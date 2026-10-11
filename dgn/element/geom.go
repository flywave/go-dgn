package element

import (
	"fmt"

	"github.com/flywave/go-dgn/internal/le"
)

// 2D/3D geometry body readers: lines, linestrings, shapes, ellipses,
// arcs and point strings (D63 getter-chain / D70 cross-validated layouts).

type Line struct {
	Start Point2d
	End   Point2d
}

func ReadLine(r *le.Reader) (*Line, error) {
	l := &Line{
		Start: Point2d{X: r.F64(), Y: r.F64()},
		End:   Point2d{X: r.F64(), Y: r.F64()},
	}
	return l, r.Err()
}

type LineString struct {
	Count  uint32
	Flags  uint32
	Points []Point2d
}

func ReadLineString(r *le.Reader) (*LineString, error) {
	ls := &LineString{}
	ls.Count = r.U32()
	ls.Flags = r.U32()
	if r.Err() != nil {
		return nil, r.Err()
	}
	if ls.Count > pointCountSanity {
		rest := r.Remaining()
		ls.Count = uint32(rest / 16)
	}
	if uint32(r.Remaining()/16) < ls.Count {
		return ls, fmt.Errorf("dgn/element: linestring count %d exceeds remaining %d bytes", ls.Count, r.Remaining())
	}
	ls.Points = make([]Point2d, 0, ls.Count)
	for i := uint32(0); i < ls.Count; i++ {
		ls.Points = append(ls.Points, Point2d{X: r.F64(), Y: r.F64()})
		if r.Err() != nil {
			return ls, r.Err()
		}
	}
	return ls, nil
}

type Shape struct {
	Count     uint32
	Flags     uint32
	Points    []Point2d
	HoleFlag  bool
	ExtraFlag bool
}

func ReadShape(r *le.Reader) (*Shape, error) {
	ls, err := ReadLineString(r)
	s := &Shape{
		Count:  ls.Count,
		Flags:  ls.Flags,
		Points: ls.Points,
		// set-by-reader semantics: EShape2D writes these to 1 after body read
		HoleFlag:  true,
		ExtraFlag: true,
	}
	return s, err
}

// Ellipse body (2D): primary, secondary, rotation (f64×3), origin — 40B.
// File order pinned by the getter chain (D63): getPrimaryAxis→vt+0x600→
// impl+0x220, getSecondaryAxis→vt+0x610→+0x228, getRotationAngle→vt+0x638
// →+0x240, origin stored @+0x248 by dgnInFields (FUN_1801d8de0).
type Ellipse struct {
	Primary   float64
	Secondary float64
	Rotation  float64
	Origin    Point2d
}

func ReadEllipse(r *le.Reader) (*Ellipse, error) {
	e := &Ellipse{
		Primary:   r.F64(),
		Secondary: r.F64(),
		Rotation:  r.F64(),
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	e.Origin = Point2d{X: r.F64(), Y: r.F64()}
	return e, r.Err()
}

type Arc struct {
	Start     float64
	Sweep     float64
	Primary   float64
	Secondary float64
	Rotation  float64
	Origin    Point2d
}

func ReadArc(r *le.Reader) (*Arc, error) {
	a := &Arc{
		Start:     r.F64(),
		Sweep:     r.F64(),
		Primary:   r.F64(),
		Secondary: r.F64(),
		Rotation:  r.F64(),
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	a.Origin = Point2d{X: r.F64(), Y: r.F64()}
	return a, r.Err()
}

type Line3d struct {
	Start Point3d
	End   Point3d
}

func ReadLine3d(r *le.Reader) (*Line3d, error) {
	l := &Line3d{
		Start: Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()},
		End:   Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()},
	}
	return l, r.Err()
}

// Ellipse3d body: primary, secondary (f64×2), rotation (quaternion),
// origin — 72B. Field order pinned by the getter chain (D63):
// getPrimaryAxis→vt+0x600→impl+0x220, getSecondaryAxis→vt+0x610→+0x228,
// getRotation→FUN_1801d7ae0 reads +0x240..0x260, getOrigin→vt+0x638→+0x260.
type Ellipse3d struct {
	Primary   float64
	Secondary float64
	Rotation  Quaternion
	Origin    Point3d
}

func ReadEllipse3d(r *le.Reader) (*Ellipse3d, error) {
	e := &Ellipse3d{Primary: r.F64(), Secondary: r.F64()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	e.Rotation = readQuat(r)
	if r.Err() != nil {
		return nil, r.Err()
	}
	e.Origin = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	return e, r.Err()
}

type Arc3d struct {
	Start     float64
	Sweep     float64
	Primary   float64
	Secondary float64
	Rotation  Quaternion
	Origin    Point3d
}

func ReadArc3d(r *le.Reader) (*Arc3d, error) {
	a := &Arc3d{
		Start:     r.F64(),
		Sweep:     r.F64(),
		Primary:   r.F64(),
		Secondary: r.F64(),
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	a.Rotation = readQuat(r)
	if r.Err() != nil {
		return nil, r.Err()
	}
	a.Origin = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	return a, r.Err()
}

type LineString3d struct {
	Count  uint32
	Flags  uint32
	Points []Point3d
}

func ReadLineString3d(r *le.Reader) (*LineString3d, error) {
	ls := &LineString3d{}
	ls.Count = r.U32()
	ls.Flags = r.U32()
	if r.Err() != nil {
		return nil, r.Err()
	}
	if ls.Count > pointCountSanity {
		ls.Count = uint32(r.Remaining() / 24)
	}
	if uint32(r.Remaining()/24) < ls.Count {
		return ls, fmt.Errorf("dgn/element: linestring3d count %d exceeds remaining", ls.Count)
	}
	ls.Points = make([]Point3d, 0, ls.Count)
	for i := uint32(0); i < ls.Count; i++ {
		ls.Points = append(ls.Points, Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()})
		if r.Err() != nil {
			return ls, r.Err()
		}
	}
	return ls, nil
}

func ReadShape3d(r *le.Reader) (*LineString3d, error) {
	return ReadLineString3d(r)
}

type PointString2d struct {
	Count    uint32
	Flags    uint32
	Points   []Point2d
	Matrices [][4]float64
}

func ReadPointString2d(r *le.Reader) (*PointString2d, error) {
	ps := &PointString2d{}
	ps.Count = r.U32()
	ps.Flags = r.U32()
	if r.Err() != nil {
		return nil, r.Err()
	}
	if ps.Count > pointCountSanity {
		ps.Count = uint32(r.Remaining() / 16)
	}
	if uint32(r.Remaining()/16) < ps.Count {
		return ps, fmt.Errorf("dgn/element: pointstring2d count %d exceeds remaining", ps.Count)
	}
	ps.Points = make([]Point2d, 0, ps.Count)
	for i := uint32(0); i < ps.Count; i++ {
		ps.Points = append(ps.Points, Point2d{X: r.F64(), Y: r.F64()})
		if r.Err() != nil {
			return ps, r.Err()
		}
	}
	ps.Matrices = make([][4]float64, 0, ps.Count)
	for i := uint32(0); i < ps.Count; i++ {
		var m [4]float64
		for j := range m {
			m[j] = r.F64()
		}
		if r.Err() != nil {
			return ps, r.Err()
		}
		ps.Matrices = append(ps.Matrices, m)
	}
	return ps, nil
}

type PointString3d struct {
	Count     uint32
	Flags     uint32
	Points    []Point3d
	Rotations []Quaternion
}

func ReadPointString3d(r *le.Reader) (*PointString3d, error) {
	ps := &PointString3d{}
	ps.Count = r.U32()
	ps.Flags = r.U32()
	if r.Err() != nil {
		return nil, r.Err()
	}
	if ps.Count > pointCountSanity {
		ps.Count = uint32(r.Remaining() / 24)
	}
	if uint32(r.Remaining()/24) < ps.Count {
		return ps, fmt.Errorf("dgn/element: pointstring3d count %d exceeds remaining", ps.Count)
	}
	ps.Points = make([]Point3d, 0, ps.Count)
	for i := uint32(0); i < ps.Count; i++ {
		ps.Points = append(ps.Points, Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()})
		if r.Err() != nil {
			return ps, r.Err()
		}
	}
	ps.Rotations = make([]Quaternion, 0, ps.Count)
	for i := uint32(0); i < ps.Count; i++ {
		ps.Rotations = append(ps.Rotations, readQuat(r))
		if r.Err() != nil {
			return ps, r.Err()
		}
	}
	return ps, nil
}
