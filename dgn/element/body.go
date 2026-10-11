package element

import (
	"fmt"

	"github.com/flywave/go-dgn/internal/le"
)

const pointCountSanity = 10000

type Point2d struct {
	X, Y float64
}

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

type TextNode struct {
	U32a   uint32
	U32b   uint32
	U16a   uint16
	U16b   uint16
	D      [4]float64
	Origin Point2d
}

func ReadTextNode(r *le.Reader) (*TextNode, error) {
	t := &TextNode{
		U32a: r.U32(),
		U32b: r.U32(),
		U16a: r.U16(),
		U16b: r.U16(),
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range t.D {
		t.D[i] = r.F64()
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.Origin = Point2d{X: r.F64(), Y: r.F64()}
	return t, r.Err()
}

type Point3d struct {
	X, Y, Z float64
}

type Quaternion struct {
	W, X, Y, Z float64
}

func readQuat(r *le.Reader) Quaternion {
	return Quaternion{W: r.F64(), X: r.F64(), Y: r.F64(), Z: r.F64()}
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

// TextNode3d layout (D70 write/read cross-validation): u32×2, u16×2,
// f64×3, quaternion rotation, Point3d origin (92B body).
type TextNode3d struct {
	U32a   uint32
	U32b   uint32
	U16a   uint16
	U16b   uint16
	D      [3]float64
	Rot    Quaternion
	Origin Point3d
}

func ReadTextNode3d(r *le.Reader) (*TextNode3d, error) {
	t := &TextNode3d{U32a: r.U32(), U32b: r.U32(), U16a: r.U16(), U16b: r.U16()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range t.D {
		t.D[i] = r.F64()
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.Rot = readQuat(r)
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.Origin = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	return t, r.Err()
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

type Text struct {
	A         uint32
	B         uint16
	Length    uint16
	Layout    [5]float64
	Origin    Point2d
	CharCount uint16
	Value     []byte
	CharAttrs []byte
}

func ReadText(r *le.Reader) (*Text, error) {
	t := &Text{A: r.U32(), B: r.U16(), Length: r.U16()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range t.Layout {
		t.Layout[i] = r.F64()
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.Origin = Point2d{X: r.F64(), Y: r.F64()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.CharCount = r.U16()
	t.Value = r.Bytes(int(t.Length))
	if r.Err() != nil {
		return nil, r.Err()
	}
	if t.CharCount > 0 {
		need := int(t.CharCount) * 3
		if r.Remaining() < need {
			t.CharCount = 0
			_ = r.Rest()
		} else {
			t.CharAttrs = r.Bytes(need)
		}
	}
	if r.Remaining() > 0 && r.Tell()&1 != 0 {
		_ = r.Seek(r.Tell() + 1)
	}
	return t, r.Err()
}

// Text3d layout (D70 write/read cross-validation): u32 A, u16 B, u16 L,
// f64×4 layout, quaternion rotation, origin, u16 N, bytes[L], N×3 char
// attrs (3D HAS the attr table — D37勘误), 16-bit align pad.
type Text3d struct {
	A         uint32
	B         uint16
	Length    uint16
	D         [4]float64
	Rot       Quaternion
	Origin    Point3d
	N         uint16
	Value     []byte
	CharAttrs []byte
}

func ReadText3d(r *le.Reader) (*Text3d, error) {
	t := &Text3d{A: r.U32(), B: r.U16(), Length: r.U16()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range t.D {
		t.D[i] = r.F64()
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.Rot = readQuat(r)
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.Origin = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.N = r.U16()
	t.Value = r.Bytes(int(t.Length))
	if r.Err() != nil {
		return nil, r.Err()
	}
	if t.N > 0 {
		need := int(t.N) * 3
		if r.Remaining() < need {
			t.N = 0
			_ = r.Rest()
		} else {
			t.CharAttrs = r.Bytes(need)
		}
	}
	if r.Remaining() > 0 && r.Tell()&1 != 0 {
		_ = r.Seek(r.Tell() + 1)
	}
	return t, r.Err()
}

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
// MeshHeader is kTypeMesh(105)'s base fields reader (EMeshHeader
// `180185700`): a single u32 (subtype discriminator [?]) + the raw
// remainder — subtype-specific variants (FaceLoops/TriangleList/…) read
// more fields; capturing Raw keeps the wildcard lossless until each
// variant is pinned (D73).
type MeshHeader struct {
	A   uint32
	Raw []byte
}

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

// RasterHeader is kTypeRasterHeader(87), ERasterHeader fields reader
// `1803f2c50` / writer `1803f2d70` (D76): u16×2, u8×2, u16×3, f64×2,
// Pt3d — 52B.
type RasterHeader struct {
	A, B    uint16
	C, D    byte
	E, F, G uint16
	H, I    float64
	Origin  Point3d
}

// RasterComponent is kTypeRasterComponent(88), ERasterComponent fields
// reader `180281570` (D77): u16×2, u8×2, u16×3 + consume-rest blob.
type RasterComponent struct {
	A, B    uint16
	C, D    byte
	E, F, G uint16
	Rest    []byte
}

// RasterRefUnknown is ERasterRefCompUnknown's fields reader `1803af850`
// (D80): u16×2, u32 + consume-rest. RTTI binds Binary(91,1), RGB(91,3)
// and Mask(91,11) to this class.
type RasterRefUnknown struct {
	A, B uint16
	C    uint32
	Rest []byte
}

// RasterRefGeo is ERasterRefCompGeo's fields reader `1803af240` (D81):
// u16×2, u32, Pt3d, Pt2d, f64×2, Pt2d, u32×6, Vec3d×2 — 152B.
type RasterRefGeo struct {
	A, B   uint16
	C      uint32
	Origin Point3d
	P1     Point2d
	D1, D2 float64
	P2     Point2d
	F      [6]uint32
	N1, N2 Point3d // vectors
}

// RasterFrame is kTypeRasterFrame(94), OdDgRasterFrameImpl fields reader
// `1803db880` (D82): u32×3, skip4, f64×16 (4×4 matrix), u32, u16, u16, u32,
// skip4, Pt2d×2, u32×2, f64×2, u32×4, u8×3, skip1, u8, skip3,
// (u32 if u16@E∈{1,6} else u8×4), bytes[512], skip4, u32, skip4, u32, skip4,
// f64×6, skip96. E (the first u16 after the matrix) is the branch selector;
// in the {1,6} case the impl also copies Blob[4] into V2[3] (derived, not
// consumed from the stream).
type RasterFrame struct {
	A, B, C          uint32
	Matrix           [4][4]float64
	D                uint32
	E, F             uint16 // E ∈ {1,6} selects the V vs V2 branch
	G                uint32
	P1, P2           Point2d
	H, I             uint32
	J, K             float64
	L                [4]uint32
	M, N, O          byte
	P                byte
	V                uint32 // when E∈{1,6}
	V2               [4]byte
	Blob             [512]byte
	Q                uint32
	R                uint32
	S, T, U, W, X, Y float64
}

func ReadRasterFrame(r *le.Reader) (*RasterFrame, error) {
	skip := func(n int) error {
		if err := r.Seek(r.Tell() + n); err != nil {
			return err
		}
		return nil
	}
	f := &RasterFrame{A: r.U32(), B: r.U32(), C: r.U32()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	if err := skip(4); err != nil {
		return nil, err
	}
	for i := range f.Matrix {
		for j := range f.Matrix[i] {
			f.Matrix[i][j] = r.F64()
		}
	}
	f.D = r.U32()
	f.E = r.U16()
	f.F = r.U16()
	f.G = r.U32()
	if r.Err() != nil {
		return nil, r.Err()
	}
	if err := skip(4); err != nil {
		return nil, err
	}
	f.P1 = Point2d{X: r.F64(), Y: r.F64()}
	f.P2 = Point2d{X: r.F64(), Y: r.F64()}
	f.H = r.U32()
	f.I = r.U32()
	f.J = r.F64()
	f.K = r.F64()
	for i := range f.L {
		f.L[i] = r.U32()
	}
	f.M = r.U8()
	f.N = r.U8()
	f.O = r.U8()
	if r.Err() != nil {
		return nil, r.Err()
	}
	if err := skip(1); err != nil {
		return nil, err
	}
	f.P = r.U8()
	if err := skip(3); err != nil {
		return nil, err
	}
	if f.E == 1 || f.E == 6 {
		f.V = r.U32()
	} else {
		f.V2 = [4]byte{r.U8(), r.U8(), r.U8(), r.U8()}
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	copy(f.Blob[:], r.Bytes(512))
	if r.Err() != nil {
		return nil, r.Err()
	}
	if err := skip(4); err != nil {
		return nil, err
	}
	f.Q = r.U32()
	if err := skip(4); err != nil {
		return nil, err
	}
	f.R = r.U32()
	if err := skip(4); err != nil {
		return nil, err
	}
	f.S = r.F64()
	f.T = r.F64()
	f.U = r.F64()
	f.W = r.F64()
	f.X = r.F64()
	f.Y = r.F64()
	if r.Err() != nil {
		return nil, r.Err()
	}
	// trailing96B (impl zero-fills after it) — tolerate short/absent tail
	if n := 0x60; r.Remaining() > 0 {
		if n > r.Remaining() {
			n = r.Remaining()
		}
		_ = skip(n)
	}
	return f, r.Err()
}

func ReadRasterRefGeo(r *le.Reader) (*RasterRefGeo, error) {
	g := &RasterRefGeo{A: r.U16(), B: r.U16(), C: r.U32()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	g.Origin = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	g.P1 = Point2d{X: r.F64(), Y: r.F64()}
	g.D1 = r.F64()
	g.D2 = r.F64()
	g.P2 = Point2d{X: r.F64(), Y: r.F64()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range g.F {
		g.F[i] = r.U32()
	}
	g.N1 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	g.N2 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	return g, r.Err()
}

// RasterRefRender is ERasterRefCompRendering's fields reader `1803af630`
// (D81): u16×2, u32×2, u8×2, 4×3-byte colors (packed u24 LE), u8×2,
// u32, f64×4 — 64B.
type RasterRefRender struct {
	A, B       uint16
	C, D       uint32
	E, F       byte
	Color0     uint32 // 3 bytes packed LE
	Color1     uint32
	Color2     uint32
	Color3     uint32
	G, H       byte
	I          uint32
	J, K, L, M float64
}

func ReadRasterRefRender(r *le.Reader) (*RasterRefRender, error) {
	x := &RasterRefRender{A: r.U16(), B: r.U16(), C: r.U32(), D: r.U32(), E: r.U8(), F: r.U8()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	rdCol := func() uint32 {
		b0, b1, b2 := r.U8(), r.U8(), r.U8()
		return uint32(b0) | uint32(b1)<<8 | uint32(b2)<<16
	}
	x.Color0 = rdCol()
	x.Color1 = rdCol()
	x.Color2 = rdCol()
	x.Color3 = rdCol()
	x.G = r.U8()
	x.H = r.U8()
	x.I = r.U32()
	if r.Err() != nil {
		return nil, r.Err()
	}
	x.J = r.F64()
	x.K = r.F64()
	x.L = r.F64()
	x.M = r.F64()
	return x, r.Err()
}

// RasterRefTransp is ERasterRefCompIndexTransparency's fields reader
// `1803af3e0` (D82): u16×2, u32×2, then 256×(u8 index, u8 value) — the value
// byte is scaled /255.0 in the impl (Trans stores the raw byte), then a u32
// tail. 528B.
type RasterRefTransp struct {
	A, B uint16
	C, D uint32
	Idx  [256]byte
	Val  [256]byte
	Tail uint32
}

func ReadRasterRefTransp(r *le.Reader) (*RasterRefTransp, error) {
	x := &RasterRefTransp{A: r.U16(), B: r.U16(), C: r.U32(), D: r.U32()}
	for i := 0; i < 256; i++ {
		x.Idx[i] = r.U8()
		x.Val[i] = r.U8()
	}
	x.Tail = r.U32()
	return x, r.Err()
}

// RasterRefRGBTransp is ERasterRefCompRGBTransparency's fields reader
// `1803af4d0` (D82): u16×2, u32×2, then 32×(3B RGB packed LE, 3B RGB packed
// LE, u8 alpha→/255.0), then a u32 tail. 240B.
type RasterRefRGBTransp struct {
	A, B uint16
	C, D uint32
	Pair [32]RGBTranspPair
	Tail uint32
}

type RGBTranspPair struct {
	RGB0, RGB1 uint32 // 3 bytes packed LE
	Alpha      byte
}

func ReadRasterRefRGBTransp(r *le.Reader) (*RasterRefRGBTransp, error) {
	x := &RasterRefRGBTransp{A: r.U16(), B: r.U16(), C: r.U32(), D: r.U32()}
	rdCol := func() uint32 {
		b0, b1, b2 := r.U8(), r.U8(), r.U8()
		return uint32(b0) | uint32(b1)<<8 | uint32(b2)<<16
	}
	for i := range x.Pair {
		x.Pair[i].RGB0 = rdCol()
		x.Pair[i].RGB1 = rdCol()
		x.Pair[i].Alpha = r.U8()
	}
	x.Tail = r.U32()
	return x, r.Err()
}

func ReadRasterRefUnknown(r *le.Reader) (*RasterRefUnknown, error) {
	x := &RasterRefUnknown{A: r.U16(), B: r.U16(), C: r.U32()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	x.Rest = r.Rest()
	return x, r.Err()
}

func ReadRasterComponent(r *le.Reader) (*RasterComponent, error) {
	c := &RasterComponent{A: r.U16(), B: r.U16(), C: r.U8(), D: r.U8(), E: r.U16(), F: r.U16(), G: r.U16()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	c.Rest = r.Rest()
	return c, r.Err()
}

// RasterRefClip is ERasterRefCompClip's fields reader `1803af120` (D77):
// u16×2, u32, u16×2, u32 count, count×Point2d. (Reader ready; subtype
// mapping for kTypeRasterAttachmentComponent(91) variants pending.)
type RasterRefClip struct {
	A, B uint16
	C    uint32
	D, E uint16
	N    uint32
	Pts  []Point2d
}

func ReadRasterRefClip(r *le.Reader) (*RasterRefClip, error) {
	c := &RasterRefClip{A: r.U16(), B: r.U16(), C: r.U32(), D: r.U16(), E: r.U16(), N: r.U32()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := uint32(0); i < c.N; i++ {
		c.Pts = append(c.Pts, Point2d{X: r.F64(), Y: r.F64()})
		if r.Err() != nil {
			return nil, r.Err()
		}
	}
	return c, r.Err()
}

func ReadRasterHeader(r *le.Reader) (*RasterHeader, error) {
	h := &RasterHeader{A: r.U16(), B: r.U16(), C: r.U8(), D: r.U8(), E: r.U16(), F: r.U16(), G: r.U16()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	h.H = r.F64()
	h.I = r.F64()
	h.Origin = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	return h, r.Err()
}

// RasterReference is kTypeRasterAttachmentHeader(90), ERasterReference
// fields reader `1803af910` (D76): u16×2, u32×4, i32×2 (stored as double
// in the impl), Pt3d, f64×4; plus u32×2 only when the first u16 is zero.
type RasterReference struct {
	A, B           uint16 // A==0 → D1,D2 present
	C, D, E, F     uint32
	G, H           int32
	Origin         Point3d
	M1, M2, M3, M4 float64
	D1, D2         uint32
}

func ReadRasterReference(r *le.Reader) (*RasterReference, error) {
	x := &RasterReference{A: r.U16(), B: r.U16()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	x.C = r.U32()
	x.D = r.U32()
	x.E = r.U32()
	x.F = r.U32()
	x.G = r.I32()
	x.H = r.I32()
	if r.Err() != nil {
		return nil, r.Err()
	}
	x.Origin = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	x.M1 = r.F64()
	x.M2 = r.F64()
	x.M3 = r.F64()
	x.M4 = r.F64()
	if r.Err() != nil {
		return nil, r.Err()
	}
	if x.A == 0 {
		x.D1 = r.U32()
		x.D2 = r.U32()
	}
	return x, r.Err()
}

// TagElement is kTypeTagElement(37), EAttribute fields reader
// `1801fa9f0` (D79): fixed 216B prefix — Pt3d×2, u16×2, u32, Pt3d,
// vector3d, u16×4, f64×5, rotation (quaternion OR f64×4 — identical
// 32B on disk, only the in-memory grouping differs; kept as Rot[4]),
// u32×4, u16, u8×2, u32, u16×2, u32 — then a value whose shape depends
// on ValueType (1=string of StrLen bytes, 2=u16, 3=u32, 4=f64,
// 5=blob of StrLen bytes), then a 16-bit align pad. Field semantics [?].
type TagElement struct {
	P1, P2    Point3d
	A, B      uint16
	C         uint32
	P3        Point3d
	V3        Point3d
	D1        uint16
	ValueType uint16 // u16#2:1=str,2=u16,3=u32,4=f64,5=blob (step9)
	E1, E2    uint16
	M         [5]float64
	Rot       [4]float64 // quaternion or 4 scalars (same bytes)
	F         [4]uint32
	G         uint16
	H, I      byte
	J         uint32
	K         uint16
	StrLen    uint16
	L         uint32
	ValueStr  string
	ValueInt  uint32
	ValueReal float64
}

func ReadTagElement(r *le.Reader) (*TagElement, error) {
	t := &TagElement{}
	t.P1 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	t.P2 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	t.A = r.U16()
	t.B = r.U16()
	t.C = r.U32()
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.P3 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	t.V3 = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	t.D1 = r.U16()
	t.ValueType = r.U16()
	t.E1 = r.U16()
	t.E2 = r.U16()
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range t.M {
		t.M[i] = r.F64()
	}
	for i := range t.Rot {
		t.Rot[i] = r.F64()
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range t.F {
		t.F[i] = r.U32()
	}
	t.G = r.U16()
	t.H = r.U8()
	t.I = r.U8()
	t.J = r.U32()
	t.K = r.U16()
	t.StrLen = r.U16()
	t.L = r.U32()
	if r.Err() != nil {
		return nil, r.Err()
	}
	switch t.ValueType {
	case 1, 5:
		t.ValueStr = string(r.Bytes(int(t.StrLen)))
	case 2:
		t.ValueInt = uint32(r.U16())
	case 3:
		t.ValueInt = r.U32()
	case 4:
		t.ValueReal = r.F64()
	default:
		// unknown type: no value payload
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	if r.Remaining() > 0 && r.Tell()&1 != 0 {
		_ = r.Seek(r.Tell() + 1)
	}
	return t, r.Err()
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

func ReadMeshHeader(r *le.Reader) (*MeshHeader, error) {
	m := &MeshHeader{A: r.U32()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	m.Raw = r.Rest()
	return m, r.Err()
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

// MatrixDoubleData is kTypeMatrixDoubleData(103), EMatrixDoubleData fields
// reader `1801e0790` (D75): u16, 70B raw blob, u32 count, u32×3, then
// count×f64 values.
type MatrixDoubleData struct {
	W      uint16
	Blob   [70]byte
	Count  uint32
	D1     uint32 // [?]
	D2     uint32
	D3     uint32
	Values []float64
}

func ReadMatrixDoubleData(r *le.Reader) (*MatrixDoubleData, error) {
	m := &MatrixDoubleData{W: r.U16()}
	copy(m.Blob[:], r.Bytes(70))
	if r.Err() != nil {
		return nil, r.Err()
	}
	m.Count = r.U32()
	m.D1 = r.U32()
	m.D2 = r.U32()
	m.D3 = r.U32()
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := uint32(0); i < m.Count; i++ {
		m.Values = append(m.Values, r.F64())
		if r.Err() != nil {
			return nil, r.Err()
		}
	}
	return m, r.Err()
}

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

type DimensionPoint struct {
	Origin Point3d
	D1     float64
	D2     float64
	Off    uint16
	Flag   uint16
	Flags  uint32
}

func ReadDimensionPoint(r *le.Reader) (*DimensionPoint, error) {
	p := &DimensionPoint{Origin: Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}}
	if r.Err() != nil {
		return nil, r.Err()
	}
	p.D1 = r.F64()
	p.D2 = r.F64()
	p.Off = r.U16()
	p.Flag = r.U16()
	p.Flags = r.U32()
	return p, r.Err()
}

type Dimension struct {
	I64  int64
	A    uint32
	B    uint32
	D1   float64
	C    uint32
	U8   [6]uint8
	N    uint8
	U16a uint16
	E1   uint32 // [?] u32×3 between U16a and M1/M2 (D72 write/read cross-validation)
	E2   uint32
	E3   uint32
	M1   float64
	M2   float64
	W    [4]uint32
	U16b uint16
	X    uint32
	U16c uint16
	M    [9]float64
	Y    uint32
	Z    uint32
	Rot  Quaternion
	Pts  []*DimensionPoint
}

func ReadDimension(r *le.Reader) (*Dimension, error) {
	d := &Dimension{}
	d.I64 = r.I64()
	d.A = r.U32()
	d.B = r.U32()
	d.D1 = r.F64()
	d.C = r.U32()
	for i := range d.U8 {
		d.U8[i] = r.U8()
	}
	d.N = d.U8[3]
	d.U16a = r.U16()
	if r.Err() != nil {
		return nil, r.Err()
	}
	d.E1 = r.U32()
	d.E2 = r.U32()
	d.E3 = r.U32()
	d.M1 = r.F64()
	d.M2 = r.F64()
	for i := range d.W {
		d.W[i] = r.U32()
	}
	d.U16b = r.U16()
	d.X = r.U32()
	d.U16c = r.U16()
	for i := range d.M {
		d.M[i] = r.F64()
	}
	d.Y = r.U32()
	d.Z = r.U32()
	if r.Err() != nil {
		return nil, r.Err()
	}
	d.Rot = readQuat(r)
	if r.Err() != nil {
		return nil, r.Err()
	}
	if int(d.N) > r.Remaining()/48 {
		return d, fmt.Errorf("dgn/element: dimension points %d exceed remaining", d.N)
	}
	for i := 0; i < int(d.N); i++ {
		p, err := ReadDimensionPoint(r)
		if err != nil {
			return d, err
		}
		d.Pts = append(d.Pts, p)
	}
	_ = r.Rest()
	return d, r.Err()
}

type MultiLineSegment struct {
	D float64
	W [6]uint32
}

type MultiLineVertex struct {
	Origin Point3d
	A      uint32
	B, C   uint16
	D, E   uint32
}

type MultiLineBreak struct {
	A, B    uint32
	P, Q, R float64
}

type MultiLine struct {
	M1, M2     float64
	A          uint32
	M          uint16
	U8         [4]uint8
	VertexCnt  uint16
	SegmentCnt uint8
	Selector   uint8
	BreakCnt   uint8
	U16b       uint16
	I8         [3]int8
	I8b        int8
	D1         float64
	I64        int64
	D2         float64
	W          [18]uint32
	D3, D4, D5 float64
	Segments   []*MultiLineSegment
	Vertices   []*MultiLineVertex
	Breaks     []*MultiLineBreak
}

func ReadMultiline(r *le.Reader) (*MultiLine, error) {
	m := &MultiLine{}
	m.M1 = r.F64()
	m.M2 = r.F64()
	m.A = r.U32()
	m.VertexCnt = r.U16()
	for i := range m.U8 {
		m.U8[i] = r.U8()
	}
	m.SegmentCnt = m.U8[1] // 0x237: segment count (writer 180171160)
	m.Selector = m.U8[2]   // 0x238: impl-written byte [?] (D83)
	m.BreakCnt = m.U8[3]   // 0x239: total breaks across vertices (writer-summed)
	m.U16b = r.U16()
	for i := range m.I8 {
		m.I8[i] = r.I8()
	}
	m.I8b = r.I8()
	m.D1 = r.F64()
	m.I64 = r.I64()
	m.D2 = r.F64()
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range m.W {
		m.W[i] = r.U32()
	}
	m.D3 = r.F64()
	m.D4 = r.F64()
	m.D5 = r.F64()
	if r.Err() != nil {
		return nil, r.Err()
	}
	if int(m.SegmentCnt) > r.Remaining()/32 {
		return m, fmt.Errorf("dgn/element: multiline segments %d exceed remaining", m.SegmentCnt)
	}
	for i := 0; i < int(m.SegmentCnt); i++ {
		s := &MultiLineSegment{D: r.F64()}
		for j := range s.W {
			s.W[j] = r.U32()
		}
		if r.Err() != nil {
			return m, r.Err()
		}
		m.Segments = append(m.Segments, s)
	}
	if int(m.VertexCnt) > r.Remaining()/40 {
		return m, fmt.Errorf("dgn/element: multiline vertices %d exceed remaining", m.VertexCnt)
	}
	for i := 0; i < int(m.VertexCnt); i++ {
		v := &MultiLineVertex{Origin: Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}}
		v.A = r.U32()
		v.B = r.U16()
		v.C = r.U16()
		v.D = r.U32()
		v.E = r.U32()
		if r.Err() != nil {
			return m, r.Err()
		}
		m.Vertices = append(m.Vertices, v)
	}
	if int(m.BreakCnt) > r.Remaining()/32 {
		return m, fmt.Errorf("dgn/element: multiline breaks %d exceed remaining", m.BreakCnt)
	}
	for i := 0; i < int(m.BreakCnt); i++ {
		b := &MultiLineBreak{A: r.U32(), B: r.U32(), P: r.F64(), Q: r.F64(), R: r.F64()}
		if r.Err() != nil {
			return m, r.Err()
		}
		m.Breaks = append(m.Breaks, b)
	}
	return m, r.Err()
}

type DString struct {
	Unicode bool
	Ansi    []byte
	UTF16   []uint16
}

func ReadDString(r *le.Reader) (*DString, error) {
	mark := r.Tell()
	b0 := r.U8()
	b1 := r.U8()
	if r.Err() != nil {
		return nil, r.Err()
	}
	if b0 == 0xff && b1 == 0xfe {
		if err := r.Seek(mark); err != nil {
			return nil, err
		}
		s := &DString{Unicode: true}
		if u := r.U16(); u != 0xfeff && r.Err() == nil {
			s.UTF16 = append(s.UTF16, u)
		}
		for {
			u := r.U16()
			if r.Err() != nil {
				return s, r.Err()
			}
			if u == 0 {
				break
			}
			s.UTF16 = append(s.UTF16, u)
		}
		return s, nil
	}
	if err := r.Seek(mark); err != nil {
		return nil, err
	}
	s := &DString{}
	for {
		c := r.U8()
		if r.Err() != nil {
			return s, r.Err()
		}
		if c == 0 {
			break
		}
		s.Ansi = append(s.Ansi, c)
	}
	return s, nil
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

type TableEntry struct {
	Raw []byte
}

func ReadTableEntry(r *le.Reader) (*TableEntry, error) {
	return &TableEntry{Raw: r.Rest()}, r.Err()
}

type TableLevelHeader struct {
	A, B  uint16
	Flags int64
	D1    float64
	D2    float64
}

func ReadTableLevelHeader(r *le.Reader) (*TableLevelHeader, error) {
	h := &TableLevelHeader{A: r.U16(), B: r.U16(), Flags: r.I64(), D1: r.F64(), D2: r.F64()}
	return h, r.Err()
}

// TableMLStyleHeader is type-96 variant6 (MultilineStyleTable):
// u16 style id + **5 reserved u16** (12B total; D72: reader 180559830
// stores the first u16 and discards five — the old "u16×2/4B" claim was
// short by the reserved words).
type TableMLStyleHeader struct {
	A        uint16
	Reserved [5]uint16
}

func ReadTableMLStyleHeader(r *le.Reader) (*TableMLStyleHeader, error) {
	h := &TableMLStyleHeader{A: r.U16()}
	for i := range h.Reserved {
		h.Reserved[i] = r.U16()
	}
	return h, r.Err()
}

type TableBlob struct {
	Raw []byte
}

func ReadTableBlob(r *le.Reader) (*TableBlob, error) {
	return &TableBlob{Raw: r.Rest()}, r.Err()
}
