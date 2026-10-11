package element

import (
	"github.com/flywave/go-dgn/internal/le"
)

// Cell body readers: cell headers, shared cell inst/def, complex
// element headers (D74/D75).

// SharedCellInst is kTypeSharedCellReference(35), ESharedCellInst fields
// reader `1801f4c00` (D74): u32, u16×2, Pt3d×2 (origin/insert), 3×3
// transform as f64×9 (sub-reader FUN_1801f6e10), Pt3d (z dropped in the
// impl cache but present in the file) — 152B.
type SharedCellInst struct {
	A       uint32 // [?] flags/cell defn reference
	B, C    uint16 // [?]
	Origin1 Point3d
	Origin2 Point3d
	Mat     [9]float64
	Origin3 Point3d
}

func ReadSharedCellInst(r *le.Reader) (*SharedCellInst, error) {
	s := &SharedCellInst{A: r.U32(), B: r.U16(), C: r.U16()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	s.Origin1 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	s.Origin2 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range s.Mat {
		s.Mat[i] = r.F64()
	}
	s.Origin3 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	return s, r.Err()
}

// SharedCellDef is kTypeSharedCellDefinition(34), ESharedCellDef fields
// reader `180269260` (D75): u8×2, u16, Pt3d×2 (origin/extent), 3×3
// transform f64×9, Pt3d — 148B (the trailing id-list block is
// kUndo-only and not read from files).
type SharedCellDef struct {
	Flag1, Flag2 byte // [?]
	W            uint16
	Origin1      Point3d
	Origin2      Point3d
	Mat          [9]float64
	Origin3      Point3d
}

func ReadSharedCellDef(r *le.Reader) (*SharedCellDef, error) {
	s := &SharedCellDef{Flag1: r.U8(), Flag2: r.U8(), W: r.U16()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	s.Origin1 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	s.Origin2 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range s.Mat {
		s.Mat[i] = r.F64()
	}
	s.Origin3 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	return s, r.Err()
}

type CellHeader3d struct {
	H  [2]uint16
	P1 Point3d
	P2 Point3d
	M  [9]float64
	P3 Point3d
}

func ReadCellHeader3d(r *le.Reader) (*CellHeader3d, error) {
	c := &CellHeader3d{}
	c.H[0] = r.U16()
	c.H[1] = r.U16()
	if r.Err() != nil {
		return nil, r.Err()
	}
	c.P1 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	c.P2 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range c.M {
		c.M[i] = r.F64()
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	c.P3 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	return c, r.Err()
}

type CellHeader2d struct {
	H  [2]uint16
	P1 Point2d
	P2 Point2d
	M  [4]float64
	P3 Point2d
}

func ReadCellHeader2d(r *le.Reader) (*CellHeader2d, error) {
	c := &CellHeader2d{}
	c.H[0] = r.U16()
	c.H[1] = r.U16()
	if r.Err() != nil {
		return nil, r.Err()
	}
	c.P1 = Point2d{X: r.F64(), Y: r.F64()}
	c.P2 = Point2d{X: r.F64(), Y: r.F64()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range c.M {
		c.M[i] = r.F64()
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	c.P3 = Point2d{X: r.F64(), Y: r.F64()}
	return c, r.Err()
}

type ComplexElement struct {
	A uint32
}

func ReadComplexElement(r *le.Reader) (*ComplexElement, error) {
	c := &ComplexElement{A: r.U32()}
	return c, r.Err()
}
