package element

import (
	"fmt"

	"github.com/flywave/go-dgn/internal/le"
)

// Table/misc body readers: mesh headers, tags, matrix data, dimensions,
// multiline styles, DStrings and table headers (D72/D73/D79).

// MeshHeader is kTypeMesh(105)'s base fields reader (EMeshHeader
// `180185700`): a single u32 (subtype discriminator [?]) + the raw
// remainder — subtype-specific variants (FaceLoops/TriangleList/…) read
// more fields; capturing Raw keeps the wildcard lossless until each
// variant is pinned (D73).
type MeshHeader struct {
	A   uint32
	Raw []byte
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

func ReadMeshHeader(r *le.Reader) (*MeshHeader, error) {
	m := &MeshHeader{A: r.U32()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	m.Raw = r.Rest()
	return m, r.Err()
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
