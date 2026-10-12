// Package sat parses ACIS SAT B-rep streams — the kernel data carried by
// SmartSolid entities (v8 0x522E BrepLinkage, kAcisData — D113).
//
// SAT text is a stream of records, each ending with '#': a leading type
// identifier followed by fields ($-1 = null ref, $n/n = index refs,
// numbers, enum words, I placeholders). The first three lines are headers
// (version, product, tolerances) and carry no '#'.
//
// SAT-1 scope (D114): full record indexing, face→surface association and
// analytic-surface extraction (sphere/plane/cylinder/cone/torus, circular
// semantics). Record layout: every surface leads with exactly 3 id/ref
// fields, then origin ×3, normal ×3, u-vector ×3, and the type-specific
// scalars (cone: cos/sin of major angle then radius; torus: major then
// minor). Elliptical cone variants (real samples carry unnormalized major
// axes and trailing ratio fields) and spline-surface need SAT-2/3.
package sat

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

// Rec is one SAT record: its stream position, type word and fields.
// Block carries the brace-enclosed sub-text of embedded-definition
// records (e.g. spline-surface { rotsur ... }) verbatim.
type Rec struct {
	Index  int
	Type   string
	Fields []string
	Block  string
}

// Ref resolves field i as a record reference: ($n or bare n) → (n, true),
// $-1/-1 → (0, false). Non-reference fields report false.
func (r Rec) Ref(i int) (int, bool) {
	if i < 0 || i >= len(r.Fields) {
		return 0, false
	}
	n, err := strconv.Atoi(strings.TrimPrefix(r.Fields[i], "$"))
	if err != nil || n < 0 {
		return 0, false
	}
	return n, true
}

// Float parses field i as a float64.
func (r Rec) Float(i int) (float64, error) {
	if i < 0 || i >= len(r.Fields) {
		return 0, fmt.Errorf("sat: %s field %d out of range (%d fields)", r.Type, i, len(r.Fields))
	}
	return strconv.ParseFloat(r.Fields[i], 64)
}

// Doc is a parsed SAT stream with records indexed by stream position.
type Doc struct {
	Header  []string // the '#'-less leading header lines (version, product, tolerances)
	Records []Rec    // Index == slice position
}

// Rec returns the record at stream index i (ACIS refs are 0-based).
func (d *Doc) Rec(i int) (Rec, bool) {
	if i < 0 || i >= len(d.Records) {
		return Rec{}, false
	}
	return d.Records[i], true
}

// Parse tokenizes a SAT stream (text form; binary ACIS is rejected).
func Parse(data []byte) (*Doc, error) {
	s := string(data)
	// ACIS text headers start with a numeric version record ("700 …" or
	// "600 …"); anything else (e.g. parasolid magic) is rejected.
	first := s
	if i := strings.IndexAny(s, "\r\n"); i >= 0 {
		first = s[:i]
	}
	hf := firstLineFields(first)
	if len(hf) == 0 {
		return nil, fmt.Errorf("sat: empty stream")
	}
	ver, err := strconv.Atoi(hf[0])
	if err != nil || (ver != 700 && ver != 600 && ver < 1000) {
		return nil, fmt.Errorf("sat: not an ACIS text stream (header %q)", truncate(first, 40))
	}

	doc := &Doc{}
	lines := strings.Split(s, "\n")
	doc.Header = lines[:3]
	for i := 3; i < len(lines); i++ {
		ln := strings.TrimSpace(strings.TrimSuffix(strings.TrimSpace(lines[i]), "#"))
		if ln == "" {
			continue
		}
		// brace-enclosed embedded definitions (rotsur/nubs/exppc) span
		// multiple lines — aggregate into Rec.Block, keep the fields
		// outside the braces.
		block := ""
		if o := strings.Index(ln, "{"); o >= 0 {
			depth := strings.Count(ln, "{") - strings.Count(ln, "}")
			end := i
			for depth > 0 && end+1 < len(lines) {
				end++
				depth += strings.Count(lines[end], "{") - strings.Count(lines[end], "}")
			}
			joined := strings.Join(lines[i:end+1], " ")
			block = joined[strings.Index(joined, "{")+1:]
			if c := strings.LastIndex(block, "}"); c >= 0 {
				block = block[:c]
			}
			ln = strings.TrimSpace(joined[:strings.Index(joined, "{")])
			i = end
		}
		ln = strings.TrimSpace(ln)
		f := strings.Fields(ln)
		if len(f) == 0 {
			continue
		}
		doc.Records = append(doc.Records, Rec{Index: len(doc.Records), Type: f[0], Fields: f[1:], Block: block})
	}
	if len(doc.Records) == 0 {
		return nil, fmt.Errorf("sat: no records")
	}
	return doc, nil
}

func firstLineFields(l string) []string { return strings.Fields(l) }

func truncate(s string, n int) string {
	if len(s) <= n {
		return s
	}
	return s[:n] + "…"
}

// Vec3 is a parsed 3-vector field triple.
type Vec3 [3]float64

// SurfaceKind classifies an analytic surface record.
type SurfaceKind uint8

const (
	SurfSphere SurfaceKind = iota
	SurfPlane
	SurfCylinder
	SurfCone
	SurfTorus
	SurfRevolution
)

// String names the kind for diagnostics.
func (k SurfaceKind) String() string {
	switch k {
	case SurfSphere:
		return "sphere"
	case SurfPlane:
		return "plane"
	case SurfCylinder:
		return "cylinder"
	case SurfCone:
		return "cone"
	case SurfTorus:
		return "torus"
	case SurfRevolution:
		return "revolution"
	}
	return fmt.Sprintf("surface(%d)", uint8(k))
}

// Surface is one analytic surface with its owning face's stream index.
// Origin/Normal/UVec come from the shared leading block; the trailing
// scalars are type-specific (D115/D116, lofted/extruded/swept samples
// cross-verified):
//
//	sphere:   R1 = radius
//	plane:    (none)
//	cylinder: R1 = radius
//	cone:     Ratio = minor/major ellipse ratio; Sin, Cos = taper-angle
//	          sine/cosine (Sin == 0 → cylinder); MajorLen = major-axis
//	          length as serialized (may be unnormalized)
//	torus:    R1 = major radius, R2 = minor radius
//	revolution (spline-surface { rotsur }): UMax/VMax = the rotation
//	          surface's parameter bounds
type Surface struct {
	FaceIndex  int // stream index of the owning face record (-1 = orphan)
	Kind       SurfaceKind
	Origin     Vec3
	Normal     Vec3
	UVec       Vec3
	R1, R2     float64
	Ratio      float64
	Sin, Cos   float64
	MajorLen   float64
	UMax, VMax float64
}

// Face is a face record's association view: its stream index, owning
// shell and referenced surface (both -1 when absent).
type Face struct {
	Index       int
	Owner       int // shell record index
	Surface     int // surface record index
	Orientation string
}

// Faces walks the face records and resolves their owner/surface refs
// (layout: [0]=self [1]=attr [2]=next [3]=prev [4]=loop [5]=owner
// [6]=? [7]=surface [8]=orientation).
func (d *Doc) Faces() []Face {
	var out []Face
	for _, r := range d.Records {
		if r.Type != "face" {
			continue
		}
		f := Face{Index: r.Index, Owner: -1, Surface: -1}
		if o, ok := r.Ref(5); ok {
			f.Owner = o
		}
		if sfc, ok := r.Ref(7); ok {
			f.Surface = sfc
		}
		for _, o := range r.Fields[8:] {
			switch o {
			case "forward", "reversed", "unknown":
				f.Orientation = o
			}
		}
		out = append(out, f)
	}
	return out
}

func parseVec(r Rec, base int) (Vec3, bool) {
	var v Vec3
	for k := 0; k < 3; k++ {
		x, err := r.Float(base + k)
		if err != nil {
			return v, false
		}
		v[k] = x
	}
	return v, true
}

// surfaceBlock decodes the shared leading block of a surface record:
// 3 id/ref fields, then origin/normal/uvec (fields 3..11). Scalars start
// at field 12.
const surfaceScalarBase = 12

// FaceSurfaces associates every face with its analytic surface. Faces
// whose surface is missing, non-analytic (spline-surface — SAT-3) or
// elliptical (cone with a ratio field — layout unpinned) are skipped and
// counted in skipped.
func (d *Doc) FaceSurfaces() (out []Surface, skipped int) {
	for _, f := range d.Faces() {
		if f.Surface < 0 {
			skipped++
			continue
		}
		sr, ok := d.Rec(f.Surface)
		if !ok {
			skipped++
			continue
		}
		s := Surface{FaceIndex: f.Index}
		var o, n, u Vec3
		var ok1, ok2, ok3 bool
		o, ok1 = parseVec(sr, 3)
		n, ok2 = parseVec(sr, 6)
		u, ok3 = parseVec(sr, 9)
		if !ok1 || !ok2 || !ok3 {
			skipped++
			continue
		}
		s.Origin, s.Normal, s.UVec = o, n, u
		switch sr.Type {
		case "sphere-surface":
			r1, err := sr.Float(surfaceScalarBase)
			if err != nil {
				skipped++
				continue
			}
			s.Kind, s.R1 = SurfSphere, r1
		case "plane-surface":
			s.Kind = SurfPlane
		case "cylinder-surface":
			r1, err := sr.Float(surfaceScalarBase)
			if err != nil {
				skipped++
				continue
			}
			s.Kind, s.R1 = SurfCylinder, r1
		case "cone-surface":
			// [12] = minor/major ellipse ratio; after two placeholders:
			// [15] = -sin, [16] = cos (taper angle; sin==0 → cylinder),
			// [17] = major-axis length (extruded/lofted/swept anchored).
			if len(sr.Fields) < surfaceScalarBase+6 {
				skipped++
				continue
			}
			ratio, _ := sr.Float(surfaceScalarBase)
			_, _ = sr.Float(surfaceScalarBase + 1)
			_, _ = sr.Float(surfaceScalarBase + 2)
			sa, _ := sr.Float(surfaceScalarBase + 3)
			ca, _ := sr.Float(surfaceScalarBase + 4)
			ml, _ := sr.Float(surfaceScalarBase + 5)
			if ratio <= 0 {
				skipped++
				continue
			}
			s.Kind, s.Ratio, s.Sin, s.Cos, s.MajorLen = SurfCone, ratio, sa, ca, ml
		case "torus-surface":
			if len(sr.Fields) < surfaceScalarBase+2 {
				skipped++
				continue
			}
			r1, _ := sr.Float(surfaceScalarBase)
			r2, _ := sr.Float(surfaceScalarBase + 1)
			s.Kind, s.R1, s.R2 = SurfTorus, r1, r2
		case "spline-surface":
			// embedded { rotsur <ellipse> ... F <umin> F <umax> F <vmin>
			// F <vmax> ... } — an analytic base curve revolved around the
			// record axis (revolvedsurf sample: ellipse base, v ∈ [0, π]).
			if !strings.Contains(sr.Block, "rotsur") {
				skipped++
				continue
			}
			el, umax, vmax, ok := ParseRotsurBlock(sr.Block)
			if !ok {
				skipped++
				continue
			}
			s.Kind = SurfRevolution
			s.Origin, s.Normal, s.UVec = el.Origin, el.Normal, el.Major
			s.R1, s.R2 = el.MajorRadius(), el.MinorRadius()
			s.UMax, s.VMax = umax, vmax
		default:
			skipped++ // other spline surfaces — SAT-3
		}
		out = append(out, s)
	}
	return out, skipped
}

// ParseRotsurBlock extracts the base ellipse and the (umax, vmax)
// parameter bounds from a rotsur embedded block (revolvedsurf anchor:
// `ellipse 0 0 0 0 0 1 2 0 0 0.5 I I` for the base curve and
// `none F 0 F 6.2832 F 0 F 3.14 ...` for the u/v domain).
func ParseRotsurBlock(block string) (el Ellipse, umax, vmax float64, ok bool) {
	f := strings.Fields(block)
	gotEllipse := false
	var dom []float64
	for i := 0; i < len(f); i++ {
		switch f[i] {
		case "ellipse":
			var nums []float64
			j := i + 1
			for j < len(f) && len(nums) < 10 {
				if v, err := strconv.ParseFloat(f[j], 64); err == nil && !strings.HasPrefix(f[j], "$") {
					nums = append(nums, v)
					j++
					continue
				}
				break
			}
			if len(nums) >= 10 {
				el.Origin = Vec3{nums[0], nums[1], nums[2]}
				el.Normal = Vec3{nums[3], nums[4], nums[5]}
				el.Major = Vec3{nums[6], nums[7], nums[8]}
				el.Ratio = nums[9]
				gotEllipse = true
			}
		case "F":
			if i+1 < len(f) {
				if v, err := strconv.ParseFloat(f[i+1], 64); err == nil {
					dom = append(dom, v)
				}
			}
		}
	}
	if !gotEllipse || len(dom) < 4 || dom[1] == 0 {
		return el, 0, 0, false
	}
	return el, dom[1], dom[3], true
}

// --- SAT-2: boundary tree (face→loop→coedge→edge→vertex/point) ---
//
// Field layouts anchored on the real extrudedsurf.sat (D115):
//
//	loop   [0]=self [1]=attr [2]=? [3]/[4]=coedge slots [5]=owner face
//	coedge [6]=edge [8]=owner loop (sense at [7]: forward/reversed)
//	edge   [3]=start vertex [4]=start param [5]=end vertex [6]=end param
//	       [7]=coedge [8]=partner edge
//	vertex [3]=edge [4]=point
//	point  [3:6] = xyz
//	ellipse-curve [3:6]=origin [6:9]=normal [9:12]=major-axis [12]=ratio
//	       (circle when ratio == 1)

// EdgeNode is an edge record's boundary view. Curve is the referenced
// geometry record (extrudedsurf anchor: edge@10 → ellipse-curve@14 via
// the trailing ref field).
type EdgeNode struct {
	Index                  int
	StartVertex, EndVertex int // -1 = none
	StartP, EndP           float64
	Curve                  int // -1 = none
}

// Ellipse is an ellipse-curve record (circle when Ratio == 1).
type Ellipse struct {
	Index  int
	Origin Vec3
	Normal Vec3
	Major  Vec3
	Ratio  float64
}

// MajorRadius returns the semi-major axis length |Major|.
func (e Ellipse) MajorRadius() float64 {
	return vecLen(e.Major)
}

// MinorRadius returns the semi-minor axis length (major × ratio).
func (e Ellipse) MinorRadius() float64 {
	return e.MajorRadius() * e.Ratio
}

// Point returns a point record's xyz.
type Point struct {
	Index int
	P     Vec3
}

func vecLen(v Vec3) float64 {
	return math.Sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2])
}

// Edges collects every edge record's boundary view.
func (d *Doc) Edges() []EdgeNode {
	var out []EdgeNode
	for _, r := range d.Records {
		if r.Type != "edge" {
			continue
		}
		e := EdgeNode{Index: r.Index, StartVertex: -1, EndVertex: -1, Curve: -1}
		if v, ok := r.Ref(3); ok {
			e.StartVertex = v
		}
		if v, ok := r.Ref(5); ok {
			e.EndVertex = v
		}
		e.StartP, _ = r.Float(4)
		e.EndP, _ = r.Float(6)
		if c, ok := r.Ref(8); ok {
			e.Curve = c
		}
		out = append(out, e)
	}
	return out
}

// Ellipses collects every ellipse-curve record.
func (d *Doc) Ellipses() []Ellipse {
	var out []Ellipse
	for _, r := range d.Records {
		if r.Type != "ellipse-curve" {
			continue
		}
		o, ok1 := parseVec(r, 3)
		n, ok2 := parseVec(r, 6)
		m, ok3 := parseVec(r, 9)
		if !ok1 || !ok2 || !ok3 {
			continue
		}
		ratio, err := r.Float(12)
		if err != nil {
			continue
		}
		out = append(out, Ellipse{Index: r.Index, Origin: o, Normal: n, Major: m, Ratio: ratio})
	}
	return out
}

// Points collects every point record.
func (d *Doc) Points() []Point {
	var out []Point
	for _, r := range d.Records {
		if r.Type != "point" {
			continue
		}
		if p, ok := parseVec(r, 3); ok {
			out = append(out, Point{Index: r.Index, P: p})
		}
	}
	return out
}

// FaceEdges returns the face's boundary edges grouped by loop, in loop
// order. Edges inside a loop are ordered along the coedge sense when the
// loop chains them; a closed single-edge loop (start == end vertex)
// passes through as-is. Curve association is edge-index → curve-index
// via the coedge partner chain is not needed: ACIS edges reference their
// geometry through the first coedge found sharing the edge index.
func (d *Doc) FaceEdges(faceIdx int) (loops [][]EdgeNode) {
	// coedge → (edge, loop)
	edgeOf := map[int]int{}
	loopOf := map[int]int{}
	for _, r := range d.Records {
		if r.Type != "coedge" {
			continue
		}
		e, okE := r.Ref(6)
		l, okL := r.Ref(8)
		if !okE || !okL {
			continue
		}
		edgeOf[r.Index] = e
		loopOf[r.Index] = l
	}
	// loop → ordered coedge indices
	var loopIdxs []int
	coedgesByLoop := map[int][]int{}
	for _, r := range d.Records {
		if r.Type != "loop" {
			continue
		}
		owner, ok := r.Ref(5)
		if !ok || owner != faceIdx {
			continue
		}
		loopIdxs = append(loopIdxs, r.Index)
	}
	for ci, l := range loopOf {
		coedgesByLoop[l] = append(coedgesByLoop[l], ci)
	}
	for _, li := range loopIdxs {
		sortInts(coedgesByLoop[li])
	}
	for _, li := range loopIdxs {
		var loop []EdgeNode
		for _, ci := range coedgesByLoop[li] {
			ei, ok := edgeOf[ci]
			if !ok {
				continue
			}
			if e, ok := d.findEdge(ei); ok {
				loop = append(loop, e)
			}
		}
		if len(loop) > 0 {
			loops = append(loops, loop)
		}
	}
	return loops
}

func (d *Doc) findEdge(idx int) (EdgeNode, bool) {
	for _, e := range d.Edges() {
		if e.Index == idx {
			return e, true
		}
	}
	return EdgeNode{}, false
}

func sortInts(s []int) {
	for i := 1; i < len(s); i++ {
		for j := i; j > 0 && s[j] < s[j-1]; j-- {
			s[j], s[j-1] = s[j-1], s[j]
		}
	}
}
