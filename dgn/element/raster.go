package element

import (
	"github.com/flywave/go-dgn/internal/le"
)

// Raster body readers: raster headers/components/frames and the
// raster attachment reference components (D76-D82).

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
