package dgn

import (
	"github.com/flywave/go-dgn/dgn/element"
	"github.com/flywave/go-dgn/dgn/scene"
)

// SceneV7 flattens a parsed v7 document into neutral scene entities with
// raw-UOR coordinates and a nested complex-group forest. Elements marked
// deleted are skipped. Cell placement transforms use the column-major
// convention documented in scene.Entity.Transform.
func SceneV7(doc V7Document) []scene.Entity {
	var out []scene.Entity
	bsConsumed, bsCurves := assembleV7BSplines(doc.Elements, doc.Header.Is3D)
	var walk func(nodes []V7Node, parent uint64, defn bool)
	walk = func(nodes []V7Node, parent uint64, defn bool) {
		for _, n := range nodes {
			el := n.Element
			if el.Deleted {
				continue
			}
			id := uint64(el.Offset)
			c := ParseV7Core(el)
			e := scene.Entity{
				ID:       id,
				ParentID: parent,
				Dim:      dimOf(doc.Header.Is3D),
				Level:    int(el.Level),
				Color:    int32(c.Color),
				DefnOnly: defn,
				BBox:     bboxFromCore(c),
			}
			switch el.Type {
			case 3:
				pts, err := ReadV7Line(el, doc.Header.Is3D)
				if err != nil {
					continue
				}
				e.Kind = scene.KindSegment
				e.Points = []scene.Point{v7pt(pts[0]), v7pt(pts[1])}
			case 4, 6, 11, 21:
				if el.Type == 21 && bsConsumed[el.Offset] {
					continue // pole element consumed by a type-27 curve
				}
				pts, err := ReadV7MultiPoint(el, doc.Header.Is3D)
				if err != nil {
					continue
				}
				e.Kind = scene.KindPolyline
				for _, p := range pts {
					e.Points = append(e.Points, v7pt(p))
				}
			case 27:
				a, ok := bsCurves[el.Offset]
				if !ok {
					continue
				}
				e.Kind = scene.KindBSplineCurve
				e.Degree = a.degree
				e.Knots = a.knots
				e.Weights = a.weights
				for _, p := range a.poles {
					e.Points = append(e.Points, scene.Point{X: p.X, Y: p.Y, Z: p.Z})
				}
			case 16:
				a, err := ReadV7Arc(el, doc.Header.Is3D)
				if err != nil {
					continue
				}
				e.Kind = scene.KindArc
				e.Arc = v7arc(a, doc.Header.Is3D)
			case 15:
				a, err := ReadV7Ellipse(el, doc.Header.Is3D)
				if err != nil {
					continue
				}
				e.Kind = scene.KindEllipse
				e.Arc = v7arc(a, doc.Header.Is3D)
			case 23:
				if !doc.Header.Is3D {
					continue
				}
				cn, err := ReadV7Cone(el, true)
				if err != nil {
					continue
				}
				e.Kind = scene.KindCone
				e.Points = []scene.Point{
					{X: cn.Center1[0], Y: cn.Center1[1], Z: cn.Center1[2]},
					{X: cn.Center2[0], Y: cn.Center2[1], Z: cn.Center2[2]},
				}
				e.Radii = [2]float64{cn.Radius1, cn.Radius2}
			case 2:
				ch, err := ReadV7CellHeader(el, doc.Header.Is3D)
				if err != nil {
					continue
				}
				e.Kind = scene.KindCellDef
				e.Name = ch.Name
				e.Transform = v7CellTransform(ch, doc.Header.Is3D)
			case 34:
				cd, err := ReadV7SharedCellDefn(el)
				if err != nil {
					continue
				}
				e.Kind = scene.KindCellDef
				e.Name = cd.Name
			case 35:
				cr, err := ReadV7SharedCellRef(el)
				if err != nil {
					continue
				}
				e.Kind = scene.KindCellRef
				e.Name = cr.Name
			case 7, 17:
				e.Kind = scene.KindText
				if el.Type == 17 {
					t, err := ReadV7Text(el, doc.Header.Is3D)
					if err == nil {
						e.Text = t.String
					}
				}
			case 12, 14, 18, 19:
				e.Kind = scene.KindComplexHeader
			default:
				continue
			}
			out = append(out, e)
			walk(n.Children, id, defn || el.Type == 34)
		}
	}
	walk(doc.Top, 0, false)
	return out
}

// SceneV7AtMaster is SceneV7 with all coordinates mapped to master units
// through the document TCB (origin subtraction + scale).
func SceneV7AtMaster(doc V7Document) []scene.Entity {
	ents := SceneV7(doc)
	tcb := &doc.TCB
	for i := range ents {
		e := &ents[i]
		for j := range e.Points {
			e.Points[j] = toMaster(tcb, e.Points[j])
		}
		if e.Arc != nil {
			e.Arc.Center = toMaster(tcb, e.Arc.Center)
			e.Arc.PrimaryAxis *= tcb.Scale
			e.Arc.SecondaryAxis *= tcb.Scale
		}
		e.Radii[0] *= tcb.Scale
		e.Radii[1] *= tcb.Scale
		e.BBox[0] = toMaster(tcb, e.BBox[0])
		e.BBox[1] = toMaster(tcb, e.BBox[1])
		if e.Transform != nil {
			o := toMaster(tcb, scene.Point{
				X: e.Transform[12], Y: e.Transform[13], Z: e.Transform[14],
			})
			e.Transform[12], e.Transform[13], e.Transform[14] = o.X, o.Y, o.Z
		}
	}
	return ents
}

// SceneV8 converts a parsed v8 element stream into scene entities. The
// result is flat (no complex-group nesting yet — see topo-bridge M5);
// Level carries the raw level entry id from the element header. Type-27
// B-spline curve headers assemble with their adjacent knot/pole records
// into a single KindBSplineCurve entity (same adjacency rule as v7).
func SceneV8(space []byte, d Dir) ([]scene.Entity, error) {
	parsed, err := ParseAll(space, d)
	if err != nil {
		return nil, err
	}
	bsConsumed, bsCurves := assembleV8BSplines(parsed)
	var out []scene.Entity
	for i, p := range parsed {
		if bsConsumed[i] {
			continue
		}
		b, ok := p.Body.(*Body)
		if !ok {
			continue
		}
		e := scene.Entity{
			ID:    p.Record.ID,
			Dim:   dimOf(p.Record.Ext != 0),
			Level: int(p.Record.Subtype),
			Color: -1,
		}
		if a, ok := bsCurves[i]; ok {
			e.Kind = scene.KindBSplineCurve
			e.Degree = a.degree
			e.Knots = a.knots
			e.Weights = a.weights
			for _, pt := range a.poles {
				e.Points = append(e.Points, pt)
			}
			out = append(out, e)
			continue
		}
		switch v := b.Value.(type) {
		case *element.Line:
			e.Kind = scene.KindSegment
			e.Points = []scene.Point{pt2(v.Start), pt2(v.End)}
		case *element.Line3d:
			e.Kind = scene.KindSegment
			e.Points = []scene.Point{pt3(v.Start), pt3(v.End)}
		case *element.LineString:
			e.Kind = scene.KindPolyline
			e.Points = map2d(v.Points)
		case *element.LineString3d:
			e.Kind = scene.KindPolyline
			e.Points = map3d(v.Points)
		case *element.Shape:
			e.Kind = scene.KindPolyline
			e.Points = map2d(v.Points)
		case *element.PointString2d:
			e.Kind = scene.KindPointString
			e.Points = map2d(v.Points)
		case *element.PointString3d:
			e.Kind = scene.KindPointString
			e.Points = map3d(v.Points)
		case *element.Arc:
			e.Kind = scene.KindArc
			e.Arc = &scene.Arc{
				Center:        pt2(v.Origin),
				PrimaryAxis:   v.Primary,
				SecondaryAxis: v.Secondary,
				Start:         v.Start,
				Sweep:         v.Sweep,
				Rotation:      v.Rotation,
			}
		case *element.Arc3d:
			e.Kind = scene.KindArc
			e.Arc = &scene.Arc{
				Center:        pt3(v.Origin),
				PrimaryAxis:   v.Primary,
				SecondaryAxis: v.Secondary,
				Start:         v.Start,
				Sweep:         v.Sweep,
				Quat:          [4]float64{v.Rotation.W, v.Rotation.X, v.Rotation.Y, v.Rotation.Z},
			}
		case *element.Ellipse:
			e.Kind = scene.KindEllipse
			e.Arc = &scene.Arc{
				Center:        pt2(v.Origin),
				PrimaryAxis:   v.Primary,
				SecondaryAxis: v.Secondary,
				Start:         0,
				Sweep:         360,
				Rotation:      v.Rotation,
			}
		case *element.Ellipse3d:
			e.Kind = scene.KindEllipse
			e.Arc = &scene.Arc{
				Center:        pt3(v.Origin),
				PrimaryAxis:   v.Primary,
				SecondaryAxis: v.Secondary,
				Start:         0,
				Sweep:         360,
				Quat:          [4]float64{v.Rotation.W, v.Rotation.X, v.Rotation.Y, v.Rotation.Z},
			}
		case *element.Cone:
			e.Kind = scene.KindCone
			e.Points = []scene.Point{pt3(v.P1), pt3(v.P2)}
			e.Radii = [2]float64{v.R1, v.R2}
		case *element.Solid:
			e.Kind = scene.KindSolid
		case *element.Text:
			e.Kind = scene.KindText
			e.Text = string(v.Value)
			e.Points = []scene.Point{pt2(v.Origin)}
		case *element.Text3d:
			e.Kind = scene.KindText
			e.Text = string(v.Value)
			e.Points = []scene.Point{pt3(v.Origin)}
		case *element.TextNode:
			e.Kind = scene.KindText
			e.Points = []scene.Point{pt2(v.Origin)}
		case *element.TextNode3d:
			e.Kind = scene.KindText
			e.Points = []scene.Point{pt3(v.Origin)}
		case *element.CellHeader2d:
			e.Kind = scene.KindCellDef
			e.Transform = cell2dTransform(v.M, v.P3)
		case *element.CellHeader3d:
			e.Kind = scene.KindCellDef
			e.Transform = cell3dTransform(v.M, v.P3)
		case *element.ComplexElement:
			e.Kind = scene.KindComplexHeader
		default:
			continue
		}
		out = append(out, e)
	}
	return out, nil
}

// v8BSplineAssembly is the v8 counterpart of v7BSplineAssembly: a type-27
// header with adjacent knot (26), pole (21) and optional weight (28)
// records in the same chunk. Unlike v7, the knot record already carries
// the FULL knot vector (golden attach1: 21 knots = 17 poles + order 4,
// unclamped), so no clamped-end expansion is applied. Header C is the
// pole count (D99 write-side corroboration); header B is a slot-return
// artifact, not a count — never validated against.
type v8BSplineAssembly struct {
	poles   []scene.Point
	knots   []float64
	weights []float64
	degree  int
}

// assembleV8BSplines pairs type-27 headers with adjacent knot/pole/weight
// records. The curve header's C u32 is the pole count (golden + write-side
// verified, D99); the order is derived from knots = poles + order. Failed
// assemblies leave their records untouched (poles stay a polyline, knots a
// standalone array).
func assembleV8BSplines(parsed []Parsed) (consumed map[int]bool, curves map[int]v8BSplineAssembly) {
	consumed = map[int]bool{}
	curves = map[int]v8BSplineAssembly{}
	body := func(p Parsed) any {
		if b, ok := p.Body.(*Body); ok {
			return b.Value
		}
		return nil
	}
	for i, p := range parsed {
		hc, ok := body(p).(*element.BSplineCurve)
		if !ok || hc.C < 2 {
			continue
		}
		var a v8BSplineAssembly
		var cand []int
		good := true
		for j := i + 1; j < len(parsed) && j <= i+3; j++ {
			t := parsed[j].Record.Type
			if t != 26 && t != 21 && t != 28 {
				break
			}
			switch v := body(parsed[j]).(type) {
			case *element.BSplineArray:
				if t == 26 && a.knots == nil {
					a.knots = v.Values
					cand = append(cand, j)
				} else if t == 28 && a.weights == nil {
					a.weights = v.Values
					cand = append(cand, j)
				} else {
					good = false
				}
			case *element.LineString:
				if t == 21 && a.poles == nil {
					for _, pt := range v.Points {
						a.poles = append(a.poles, pt2(pt))
					}
					cand = append(cand, j)
				} else {
					good = false
				}
			case *element.LineString3d:
				if t == 21 && a.poles == nil {
					for _, pt := range v.Points {
						a.poles = append(a.poles, pt3(pt))
					}
					cand = append(cand, j)
				} else {
					good = false
				}
			default:
				good = false
			}
			if !good {
				break
			}
		}
		if !good || len(a.poles) != int(hc.C) || a.knots == nil {
			continue
		}
		order := len(a.knots) - len(a.poles)
		if order < 2 {
			continue
		}
		a.degree = order - 1
		for _, j := range cand {
			consumed[j] = true
		}
		curves[i] = a
	}
	return consumed, curves
}

func toMaster(tcb *V7TCB, p scene.Point) scene.Point {
	m := tcb.ToMaster([3]float64{p.X, p.Y, p.Z})
	return scene.Point{X: m[0], Y: m[1], Z: m[2]}
}

func dimOf(is3d bool) uint8 {
	if is3d {
		return 3
	}
	return 2
}

func bboxFromCore(c V7Core) [2]scene.Point {
	return [2]scene.Point{
		{X: float64(c.BBox[0]), Y: float64(c.BBox[1]), Z: float64(c.BBox[2])},
		{X: float64(c.BBox[3]), Y: float64(c.BBox[4]), Z: float64(c.BBox[5])},
	}
}

func v7pt(p V7Point) scene.Point {
	return scene.Point{X: float64(p.X), Y: float64(p.Y), Z: float64(p.Z)}
}

// v7arc maps a decoded V7Arc to the scene Arc. Quat components are
// i32/2^31-scaled unit-quaternion parts (D56/D63 convention).
func v7arc(a V7Arc, is3d bool) *scene.Arc {
	s := &scene.Arc{
		Center:        scene.Point{X: a.Origin[0], Y: a.Origin[1], Z: a.Origin[2]},
		PrimaryAxis:   a.Primary,
		SecondaryAxis: a.Secondary,
		Start:         a.Start,
		Sweep:         a.Sweep,
		Rotation:      a.Rotation,
	}
	if is3d {
		const s231 = 1.0 / (1 << 31)
		s.Quat = [4]float64{
			float64(a.Quat[0]) * s231,
			float64(a.Quat[1]) * s231,
			float64(a.Quat[2]) * s231,
			float64(a.Quat[3]) * s231,
		}
	}
	return s
}

// v7CellTransform packs a v7 cell header's affine placement into a
// column-major 4×4. 2D stores (a,b,c,d) as i32/2^31 with column vectors
// (a,b) and (c,d); 3D stores a row-major 3×3 that we transpose into
// column-major. Origin is a raw-UOR translation.
func v7CellTransform(ch V7CellHeader, is3d bool) *[16]float64 {
	m := new([16]float64)
	m[15] = 1
	if is3d {
		m[0], m[1], m[2] = ch.Trans[0], ch.Trans[3], ch.Trans[6]
		m[4], m[5], m[6] = ch.Trans[1], ch.Trans[4], ch.Trans[7]
		m[8], m[9], m[10] = ch.Trans[2], ch.Trans[5], ch.Trans[8]
		m[12], m[13], m[14] = float64(ch.Origin.X), float64(ch.Origin.Y), float64(ch.Origin.Z)
	} else {
		m[0], m[1] = ch.Trans[0], ch.Trans[1]
		m[4], m[5] = ch.Trans[2], ch.Trans[3]
		m[10] = 1
		m[12], m[13] = float64(ch.Origin.X), float64(ch.Origin.Y)
	}
	return m
}

func cell2dTransform(mat [4]float64, origin element.Point2d) *[16]float64 {
	m := new([16]float64)
	m[15] = 1
	m[0], m[1] = mat[0], mat[1]
	m[4], m[5] = mat[2], mat[3]
	m[10] = 1
	m[12], m[13] = origin.X, origin.Y
	return m
}

func cell3dTransform(mat [9]float64, origin element.Point3d) *[16]float64 {
	m := new([16]float64)
	m[15] = 1
	m[0], m[1], m[2] = mat[0], mat[3], mat[6]
	m[4], m[5], m[6] = mat[1], mat[4], mat[7]
	m[8], m[9], m[10] = mat[2], mat[5], mat[8]
	m[12], m[13], m[14] = origin.X, origin.Y, origin.Z
	return m
}

func pt2(p element.Point2d) scene.Point { return scene.Point{X: p.X, Y: p.Y} }
func pt3(p element.Point3d) scene.Point { return scene.Point{X: p.X, Y: p.Y, Z: p.Z} }

func map2d(pts []element.Point2d) []scene.Point {
	out := make([]scene.Point, len(pts))
	for i, p := range pts {
		out[i] = pt2(p)
	}
	return out
}

func map3d(pts []element.Point3d) []scene.Point {
	out := make([]scene.Point, len(pts))
	for i, p := range pts {
		out[i] = pt3(p)
	}
	return out
}

// v7BSplineAssembly holds one assembled type-27 curve from its sibling
// elements. v7 stores a B-spline curve as a run of adjacent elements —
// header(27), interior knots(26), poles(21), optional weights(28) —
// associated by file adjacency, not complex grouping (bit7 on the
// siblings is only a "group member" annotation; D59). NumKnots ==
// NumPoles − Order in every sample curve, i.e. the knot element holds
// the INTERIOR knots of an open clamped spline (ODA DgBSplineCurve.h
// L282: open curve knot count = poles + order).
type v7BSplineAssembly struct {
	poles   []V7PointF
	knots   []float64 // full expanded vector: clamped ends + interior
	weights []float64 // nil when non-rational (no type-28 sibling)
	degree  int
}

// assembleV7BSplines pre-scans the flat element list, pairing each type-27
// header with its adjacent knot/pole/weight siblings. On success the
// siblings are marked consumed so the scene walk emits a single
// KindBSplineCurve entity instead of a bare pole polyline. Failed
// assemblies leave their siblings untouched (standalone type 21 stays a
// polyline, matching GDAL's point-array treatment).
func assembleV7BSplines(els []V7Element, is3d bool) (consumed map[int]bool, curves map[int]v7BSplineAssembly) {
	consumed = map[int]bool{}
	curves = map[int]v7BSplineAssembly{}
	for i := 0; i < len(els); i++ {
		if els[i].Type != 27 || els[i].Deleted {
			continue
		}
		h, err := ReadV7BSplineCurveHeader(els[i])
		if err != nil || h.Order < 2 || int(h.NumPoles) < int(h.Order) {
			continue
		}
		var a v7BSplineAssembly
		var interior []float64
		var cand []int // follower indices pending consumption
		ok := true
		for j := i + 1; j < len(els) && j <= i+3; j++ {
			if t := els[j].Type; t != 26 && t != 21 && t != 28 {
				break // next logical element (e.g. the next curve header)
			}
			if els[j].Deleted {
				ok = false
				break
			}
			switch els[j].Type {
			case 26:
				if len(interior) != 0 || h.NumKnots == 0 {
					ok = false
					break
				}
				k, err := ReadV7KnotWeights(els[j])
				if err != nil || len(k) != int(h.NumKnots) {
					ok = false
					break
				}
				interior = k
				cand = append(cand, j)
			case 21:
				if len(a.poles) != 0 {
					ok = false
					break
				}
				p, err := ReadV7MultiPointF(els[j], is3d)
				if err != nil || len(p) != int(h.NumPoles) {
					ok = false
					break
				}
				a.poles = p
				cand = append(cand, j)
			case 28:
				if len(a.weights) != 0 {
					ok = false
					break
				}
				w, err := ReadV7KnotWeights(els[j])
				if err != nil || len(w) != int(h.NumPoles) {
					ok = false
					break
				}
				a.weights = w
				cand = append(cand, j)
			}
			if !ok {
				break
			}
		}
		if !ok || len(a.poles) != int(h.NumPoles) || len(interior) != int(h.NumKnots) {
			continue
		}
		order := int(h.Order)
		a.knots = make([]float64, 0, order+len(interior)+order)
		for k := 0; k < order; k++ {
			a.knots = append(a.knots, 0)
		}
		a.knots = append(a.knots, interior...)
		for k := 0; k < order; k++ {
			a.knots = append(a.knots, 1)
		}
		a.degree = order - 1
		for _, j := range cand {
			consumed[els[j].Offset] = true
		}
		curves[els[i].Offset] = a
	}
	return consumed, curves
}

// SceneV8ModelAtMaster builds the scene entities of one v8 model and maps
// raw UOR coordinates to master units through the document resolution
// (master = UOR / UorPerMaster; D104). Entities keep their model-relative
// placement; the real size of one master unit comes from the model's
// working set (V8Model.Settings.SubUnitsPerUor × sub-unit scale).
func SceneV8ModelAtMaster(doc *V8Document, m *V8Model) ([]scene.Entity, error) {
	scale := 1.0
	if doc.UorPerMaster > 0 {
		scale = 1.0 / doc.UorPerMaster
	}
	var out []scene.Entity
	for path, ch := range doc.Chunks {
		if chunkParent(path) != m.Storage+"/"+StorageGraphics {
			continue
		}
		ents, err := SceneV8(ch.Space, Dir{Base: 0, Offsets: ch.Offsets})
		if err != nil {
			return out, err
		}
		for i := range ents {
			scaleEntity(&ents[i], scale)
		}
		out = append(out, ents...)
	}
	return out, nil
}

func scaleEntity(e *scene.Entity, k float64) {
	if k == 1 {
		return
	}
	for j := range e.Points {
		e.Points[j].X *= k
		e.Points[j].Y *= k
		e.Points[j].Z *= k
	}
	if e.Arc != nil {
		e.Arc.Center.X *= k
		e.Arc.Center.Y *= k
		e.Arc.Center.Z *= k
		e.Arc.PrimaryAxis *= k
		e.Arc.SecondaryAxis *= k
	}
	e.Radii[0] *= k
	e.Radii[1] *= k
	for j := range e.BBox {
		e.BBox[j].X *= k
		e.BBox[j].Y *= k
		e.BBox[j].Z *= k
	}
	if e.Transform != nil {
		e.Transform[12] *= k
		e.Transform[13] *= k
		e.Transform[14] *= k
	}
}
