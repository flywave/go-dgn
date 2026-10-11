package element

import (
	"fmt"

	"github.com/flywave/go-dgn/internal/le"
)

// Cone/solid/surface and B-spline body readers: poles, knots/weights,
// curve/surface headers and boundaries (D71).

type Cone struct {
	H   [4]uint16
	Rot Quaternion
	P1  Point3d
	R1  float64
	P2  Point3d
	R2  float64
}

func ReadCone(r *le.Reader) (*Cone, error) {
	c := &Cone{}
	for i := range c.H {
		c.H[i] = r.U16()
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	c.Rot = readQuat(r)
	if r.Err() != nil {
		return nil, r.Err()
	}
	c.P1 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	c.R1 = r.F64()
	c.P2 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	c.R2 = r.F64()
	return c, r.Err()
}

type Solid struct {
	Flags uint32
	U     [4]uint16
}

func ReadSolid(r *le.Reader) (*Solid, error) {
	s := &Solid{Flags: r.U32()}
	for i := range s.U {
		s.U[i] = r.U16()
	}
	return s, r.Err()
}

type Surface = Solid

func ReadSurface(r *le.Reader) (*Solid, error) {
	return ReadSolid(r)
}

func ReadBSplinePoles2d(r *le.Reader) (*LineString, error) {
	return ReadLineString(r)
}

func ReadBSplinePoles3d(r *le.Reader) (*LineString3d, error) {
	return ReadLineString3d(r)
}

type BSplineArray struct {
	Values []float64
}

// ReadBSplineArray decodes type-26 knots / type-28 weights: both are
// consume-rest f64 arrays (EBSplineKnots `180280d10` / EBSplineWeights
// `1802ebb60`, symmetric writers count×rdDouble; D71).

func ReadBSplineArray(r *le.Reader) (*BSplineArray, error) {
	n := r.Remaining() / 8
	a := &BSplineArray{Values: make([]float64, 0, n)}
	for i := 0; i < n; i++ {
		a.Values = append(a.Values, r.F64())
		if r.Err() != nil {
			return a, r.Err()
		}
	}
	return a, nil
}

type BSplineCurve struct {
	A uint32
	B uint32
	C uint32
}

// ReadBSplineCurve decodes the type-27 curve header: EBSpline2D/3D fields
// reader `1803b8690` = rdInt32×3 (D71 write/read cross-validation; the
// 9×u32 function1803e9bc0 belongs to the surface impl, not the curve).
func ReadBSplineCurve(r *le.Reader) (*BSplineCurve, error) {
	c := &BSplineCurve{A: r.U32(), B: r.U32(), C: r.U32()}
	return c, r.Err()
}

// BSplineSurface is OdDgBSplineSurfaceImpl's file header: **9×u32** (36B)
// (D71 write/read cross-validation: 1803e9bc0/1803e9cb0; the old u32×10
// claim was a miscount).
type BSplineSurface struct {
	F [9]uint32
}

func ReadBSplineSurface(r *le.Reader) (*BSplineSurface, error) {
	s := &BSplineSurface{}
	for i := range s.F {
		s.F[i] = r.U32()
	}
	return s, r.Err()
}

type BSplineBoundary struct {
	A     uint32
	Count uint32
	Pts   []Point2d
}

func ReadBSplineBoundary(r *le.Reader) (*BSplineBoundary, error) {
	b := &BSplineBoundary{A: r.U32(), Count: r.U32()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	if b.Count > pointCountSanity {
		b.Count = uint32(r.Remaining() / 16)
	}
	if uint32(r.Remaining()/16) < b.Count {
		return b, fmt.Errorf("dgn/element: boundary count %d exceeds remaining", b.Count)
	}
	for i := uint32(0); i < b.Count; i++ {
		b.Pts = append(b.Pts, Point2d{X: r.F64(), Y: r.F64()})
		if r.Err() != nil {
			return b, r.Err()
		}
	}
	return b, nil
}
