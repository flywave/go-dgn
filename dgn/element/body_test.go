package element

import (
	"encoding/binary"
	"math"
	"testing"

	"github.com/flywave/go-dgn/internal/le"
)

func f64s(vals ...float64) []byte {
	b := make([]byte, 8*len(vals))
	for i, v := range vals {
		binary.LittleEndian.PutUint64(b[8*i:], math.Float64bits(v))
	}
	return b
}

func u32s(vals ...uint32) []byte {
	b := make([]byte, 4*len(vals))
	for i, v := range vals {
		binary.LittleEndian.PutUint32(b[4*i:], v)
	}
	return b
}

func cat(parts ...[]byte) []byte {
	var out []byte
	for _, p := range parts {
		out = append(out, p...)
	}
	return out
}

func TestReadLine(t *testing.T) {
	b := cat(f64s(1, 2, 3, 4))
	l, err := ReadLine(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if l.Start.X != 1 || l.Start.Y != 2 || l.End.X != 3 || l.End.Y != 4 {
		t.Fatalf("%+v", l)
	}
}

func TestReadLineString(t *testing.T) {
	b := cat(
		u32s(2, 0x1234),
		f64s(0, 0, 10, 20),
	)
	ls, err := ReadLineString(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if ls.Count != 2 || ls.Flags != 0x1234 || len(ls.Points) != 2 {
		t.Fatalf("%+v", ls)
	}
	if ls.Points[1].X != 10 || ls.Points[1].Y != 20 {
		t.Fatalf("%+v", ls.Points)
	}
}

func TestReadLineStringClamp(t *testing.T) {
	b := cat(
		u32s(999999, 0),
		f64s(1, 1, 2, 2, 3, 3),
	)
	ls, err := ReadLineString(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if ls.Count != 3 || len(ls.Points) != 3 {
		t.Fatalf("clamp failed: %+v", ls)
	}
}

func TestReadLineStringShort(t *testing.T) {
	b := cat(u32s(5, 0), f64s(1, 1))
	if _, err := ReadLineString(le.New(b)); err == nil {
		t.Fatal("expected short error")
	}
}

func TestReadShape(t *testing.T) {
	b := cat(u32s(1, 7), f64s(5, 6))
	s, err := ReadShape(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if len(s.Points) != 1 || !s.HoleFlag || !s.ExtraFlag || s.Flags != 7 {
		t.Fatalf("%+v", s)
	}
}

func TestReadEllipse(t *testing.T) {
	b := cat(f64s(1, 2, 3, 4, 5))
	e, err := ReadEllipse(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if e.Primary != 1 || e.Secondary != 2 || e.Rotation != 3 || e.Origin.X != 4 || e.Origin.Y != 5 {
		t.Fatalf("%+v", e)
	}
}

func TestReadArc(t *testing.T) {
	b := cat(f64s(0.5, 1.5, 1, 2, 3, 7, 8))
	a, err := ReadArc(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if a.Start != 0.5 || a.Sweep != 1.5 || a.Primary != 1 || a.Secondary != 2 || a.Rotation != 3 {
		t.Fatalf("%+v", a)
	}
	if a.Origin.X != 7 || a.Origin.Y != 8 {
		t.Fatalf("%+v", a)
	}
}

func TestReadTextNode(t *testing.T) {
	b := cat(
		u32s(100, 200),
		[]byte{0x0a, 0x00, 0x0b, 0x00},
		f64s(1, 2, 3, 4, 9, 9),
	)
	tn, err := ReadTextNode(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if tn.U32a != 100 || tn.U32b != 200 || tn.U16a != 10 || tn.U16b != 11 {
		t.Fatalf("%+v", tn)
	}
	if tn.D[3] != 4 || tn.Origin.X != 9 {
		t.Fatalf("%+v", tn)
	}
}

func TestReadLine3d(t *testing.T) {
	b := cat(f64s(1, 2, 3, 4, 5, 6))
	l, err := ReadLine3d(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if l.Start.Z != 3 || l.End.X != 4 || l.End.Z != 6 {
		t.Fatalf("%+v", l)
	}
}

func TestReadEllipse3dAndArc3d(t *testing.T) {
	q := f64s(1, 0, 0, 0)
	o := f64s(9, 8, 7)
	e, err := ReadEllipse3d(le.New(cat(f64s(11, 22), q, o)))
	if err != nil {
		t.Fatal(err)
	}
	if e.Primary != 11 || e.Secondary != 22 || e.Rotation.W != 1 || e.Origin.Z != 7 {
		t.Fatalf("%+v", e)
	}
	ab := cat(f64s(0.5, 1.5, 2.5, 3.5), q, o)
	a, err := ReadArc3d(le.New(ab))
	if err != nil {
		t.Fatal(err)
	}
	if a.Start != 0.5 || a.Sweep != 1.5 || a.Primary != 2.5 || a.Secondary != 3.5 {
		t.Fatalf("%+v", a)
	}
	if a.Rotation.W != 1 || a.Origin.Y != 8 {
		t.Fatalf("%+v", a)
	}
}

func TestReadTextNode3d(t *testing.T) {
	b := cat(
		u32s(1, 2),
		[]byte{3, 0, 4, 0},
		f64s(9, 8, 9),    // D[3] layout (D70)
		f64s(1, 0, 0, 0), // quaternion
		f64s(5, 6, 7),    // origin
	)
	tn, err := ReadTextNode3d(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if tn.U32a != 1 || tn.U16b != 4 || tn.D[0] != 9 || tn.D[2] != 9 || tn.Rot.W != 1 || tn.Origin.Z != 7 {
		t.Fatalf("%+v", tn)
	}
}

func TestReadLineString3d(t *testing.T) {
	b := cat(u32s(2, 0), f64s(1, 2, 3, 4, 5, 6))
	ls, err := ReadLineString3d(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if len(ls.Points) != 2 || ls.Points[1].Z != 6 {
		t.Fatalf("%+v", ls)
	}

	sh, err := ReadShape3d(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if len(sh.Points) != 2 || sh.Flags != 0 {
		t.Fatalf("%+v", sh)
	}
}

func TestReadPointString2d(t *testing.T) {
	b := cat(
		u32s(1, 0),
		f64s(10, 20),
		f64s(1, 2, 3, 4),
	)
	ps, err := ReadPointString2d(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if len(ps.Points) != 1 || ps.Points[0].Y != 20 || ps.Matrices[0][3] != 4 {
		t.Fatalf("%+v", ps)
	}
}

func TestReadPointString3d(t *testing.T) {
	b := cat(
		u32s(1, 0),
		f64s(1, 2, 3),
		f64s(1, 0, 0, 0),
	)
	ps, err := ReadPointString3d(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if ps.Points[0].Z != 3 || ps.Rotations[0].W != 1 {
		t.Fatalf("%+v", ps)
	}
}

func TestReadText(t *testing.T) {
	b := cat(
		u32s(7),
		[]byte{8, 0},
		[]byte{5, 0},
		f64s(1, 0, 0, 1, 45),
		f64s(9, 9),
		[]byte{2, 0},
		[]byte("hello"),
		[]byte{1, 2, 3, 4, 5, 6},
	)
	tx, err := ReadText(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if tx.A != 7 || tx.Length != 5 || string(tx.Value) != "hello" {
		t.Fatalf("%+v", tx)
	}
	if tx.CharCount != 2 || len(tx.CharAttrs) != 6 || tx.CharAttrs[5] != 6 {
		t.Fatalf("%+v", tx)
	}
	if tx.Layout[4] != 45 || tx.Origin.Y != 9 {
		t.Fatalf("%+v", tx)
	}
}

func TestReadTextShortAttrTable(t *testing.T) {
	b := cat(
		u32s(0),
		[]byte{0, 0},
		[]byte{3, 0},
		f64s(0, 0, 0, 0, 0),
		f64s(0, 0),
		[]byte{9, 0},
		[]byte("abc"),
		[]byte{1},
	)
	tx, err := ReadText(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if tx.CharCount != 0 || tx.CharAttrs != nil {
		t.Fatalf("%+v", tx)
	}
}

func TestReadText3d(t *testing.T) {
	b := cat(
		u32s(3),
		[]byte{2, 0},
		[]byte{4, 0},
		f64s(10, 11, 12, 13), // D[4] layout (D70)
		f64s(1, 0, 0, 0),     // quaternion
		f64s(1, 2, 3),        // origin
		[]byte{3, 0},         // N=3 → 3D HAS the N×3 attr table (D37勘误)
		[]byte("wxyz"),
		[]byte{1, 2, 3, 4, 5, 6, 7, 8, 9},
	)
	tx, err := ReadText3d(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if tx.Length != 4 || string(tx.Value) != "wxyz" || tx.Origin.Z != 3 || tx.Rot.W != 1 {
		t.Fatalf("%+v", tx)
	}
	if tx.D != [4]float64{10, 11, 12, 13} || tx.N != 3 || len(tx.CharAttrs) != 9 || tx.CharAttrs[8] != 9 {
		t.Fatalf("%+v", tx)
	}
}

func TestReadCone(t *testing.T) {
	b := cat(
		[]byte{1, 0, 2, 0, 3, 0, 4, 0},
		f64s(1, 0, 0, 0),
		f64s(0, 0, 0),
		f64s(5),
		f64s(0, 0, 10),
		f64s(2),
	)
	c, err := ReadCone(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if c.H[0] != 1 || c.H[3] != 4 || c.Rot.W != 1 {
		t.Fatalf("%+v", c)
	}
	if c.P1.Z != 0 || c.R1 != 5 || c.P2.Z != 10 || c.R2 != 2 {
		t.Fatalf("%+v", c)
	}
}

func TestReadSolidAndSurface(t *testing.T) {
	b := cat(u32s(0x40), []byte{1, 0, 2, 0, 3, 0, 4, 0})
	s, err := ReadSolid(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if s.Flags != 0x40 || s.U[2] != 3 {
		t.Fatalf("%+v", s)
	}
	b2 := cat(u32s(9), []byte{9, 0, 8, 0, 7, 0, 6, 0})
	sf, err := ReadSurface(le.New(b2))
	if err != nil || sf.Flags != 9 {
		t.Fatalf("%+v %v", sf, err)
	}
}

func TestBSplinePolesReuse(t *testing.T) {
	p2, err := ReadBSplinePoles2d(le.New(cat(u32s(1, 0), f64s(3, 4))))
	if err != nil || p2.Points[0].X != 3 {
		t.Fatalf("%+v %v", p2, err)
	}
	p3, err := ReadBSplinePoles3d(le.New(cat(u32s(1, 0), f64s(1, 2, 3))))
	if err != nil || p3.Points[0].Z != 3 {
		t.Fatalf("%+v %v", p3, err)
	}
}

func TestReadBSplineArrayRest(t *testing.T) {
	b := cat(f64s(1, 2, 3), []byte{1})
	a, err := ReadBSplineArray(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if len(a.Values) != 3 || a.Values[2] != 3 {
		t.Fatalf("%+v", a)
	}
}

func TestReadBSplineCurveAndSurface(t *testing.T) {
	c, err := ReadBSplineCurve(le.New(u32s(7, 8, 9)))
	if err != nil || c.A != 7 || c.C != 9 {
		t.Fatalf("%+v %v", c, err)
	}
	s, err := ReadBSplineSurface(le.New(u32s(1, 2, 3, 4, 5, 6, 7, 8, 9)))
	if err != nil || s.F[8] != 9 {
		t.Fatalf("%+v %v", s, err)
	}
}

func TestReadCellHeader3d(t *testing.T) {
	b := cat(
		[]byte{5, 0, 6, 0},
		f64s(1, 2, 3),
		f64s(4, 5, 6),
		f64s(1, 0, 0, 0, 1, 0, 0, 0, 1),
		f64s(7, 8, 9),
	)
	c, err := ReadCellHeader3d(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if c.H[0] != 5 || c.P1.Z != 3 || c.P2.X != 4 || c.M[4] != 1 || c.P3.Z != 9 {
		t.Fatalf("%+v", c)
	}
}

func TestReadCellHeader2d(t *testing.T) {
	b := cat(
		[]byte{1, 0, 2, 0},
		f64s(1, 2),
		f64s(3, 4),
		f64s(1, 0, 0, 1),
		f64s(5, 6),
	)
	c, err := ReadCellHeader2d(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if c.H[1] != 2 || c.P2.Y != 4 || c.M[3] != 1 || c.P3.X != 5 {
		t.Fatalf("%+v", c)
	}
}

func TestReadComplexElement(t *testing.T) {
	c, err := ReadComplexElement(le.New(u32s(0xdeadbeef)))
	if err != nil || c.A != 0xdeadbeef {
		t.Fatalf("%+v %v", c, err)
	}
}

func TestReadDimension(t *testing.T) {
	var pre []byte
	putb := func(v []byte) { pre = append(pre, v...) }
	puti64 := func(v int64) { x := make([]byte, 8); binary.LittleEndian.PutUint64(x, uint64(v)); putb(x) }
	putu32 := func(v uint32) { x := make([]byte, 4); binary.LittleEndian.PutUint32(x, v); putb(x) }
	putu16 := func(v uint16) { x := make([]byte, 2); binary.LittleEndian.PutUint16(x, v); putb(x) }
	putu8 := func(v byte) { putb([]byte{v}) }

	puti64(100)
	putu32(1)
	putu32(2)
	putb(f64s(3.5))
	putu32(4)
	for _, v := range []byte{0, 0, 0, 2, 0, 0} {
		putu8(v)
	}
	putu16(7)
	putu32(71)
	putu32(72)
	putu32(73)
	putb(f64s(8, 9))
	for i := 0; i < 4; i++ {
		putu32(uint32(10 + i))
	}
	putu16(14)
	putu32(15)
	putu16(16)
	for i := 0; i < 9; i++ {
		putb(f64s(float64(20 + i)))
	}
	putu32(30)
	putu32(31)
	putb(f64s(1, 0, 0, 0))
	pt := func() {
		putb(f64s(1, 2, 3))
		putb(f64s(4, 5))
		putu16(6)
		putu16(7)
		putu32(8)
	}
	pt()
	pt()
	putb([]byte{0xff, 0xfe, 0x41})

	d, err := ReadDimension(le.New(pre))
	if err != nil {
		t.Fatal(err)
	}
	if d.I64 != 100 || d.A != 1 || d.D1 != 3.5 || d.U8[3] != 2 {
		t.Fatalf("%+v", d)
	}
	if d.N != 2 {
		t.Fatalf("N=%d", d.N)
	}
	if d.E1 != 71 || d.E2 != 72 || d.E3 != 73 {
		t.Fatalf("E=%d,%d,%d", d.E1, d.E2, d.E3)
	}
	if len(d.Pts) == 0 || d.Pts[0].Origin.Z != 3 || d.Pts[0].D1 != 4 || d.Pts[0].Off != 6 {
		t.Fatalf("%+v", d.Pts)
	}
	if d.Rot.W != 1 || d.M[8] != 28 {
		t.Fatalf("%+v", d)
	}
}

func TestReadMultiline(t *testing.T) {
	var b []byte
	put := func(v []byte) { b = append(b, v...) }
	put(f64s(1.5, 2.5))
	{
		x := make([]byte, 4)
		binary.LittleEndian.PutUint32(x, 9)
		put(x)
	}
	{
		x := make([]byte, 2)
		binary.LittleEndian.PutUint16(x, 1) // VertexCnt
		put(x)
	}
	put([]byte{0, 1, 2, 3}) // U8: [1]=SegmentCnt=1, [2]=Selector=2, [3]=BreakCnt (set below)
	b[len(b)-1] = 1         // BreakCnt=1
	{
		x := make([]byte, 2)
		binary.LittleEndian.PutUint16(x, 0x2222)
		put(x)
	}
	put([]byte{7, 8, 9}) // i8×3
	put([]byte{10})      // i8
	put(f64s(11))
	{
		x := make([]byte, 8)
		binary.LittleEndian.PutUint64(x, 12)
		put(x)
	}
	put(f64s(13))
	for i := 0; i < 18; i++ {
		{
			x := make([]byte, 4)
			binary.LittleEndian.PutUint32(x, uint32(100+i))
			put(x)
		}
	}
	put(f64s(14, 15, 16))
	// segment ×1: f64 + u32×6
	put(f64s(1.25))
	for i := 0; i < 6; i++ {
		x := make([]byte, 4)
		binary.LittleEndian.PutUint32(x, uint32(200+i))
		put(x)
	}
	// vertex ×1: Pt3d + u32 + u16×2 + u32×2
	put(f64s(1, 2, 3))
	{
		x := make([]byte, 4)
		binary.LittleEndian.PutUint32(x, 300)
		put(x)
	}
	{
		x := make([]byte, 2)
		binary.LittleEndian.PutUint16(x, 301)
		put(x)
		binary.LittleEndian.PutUint16(x, 302)
		put(x)
	}
	{
		x := make([]byte, 4)
		binary.LittleEndian.PutUint32(x, 303)
		put(x)
		binary.LittleEndian.PutUint32(x, 304)
		put(x)
	}
	// break ×1: u32×2 + f64×3
	{
		x := make([]byte, 4)
		binary.LittleEndian.PutUint32(x, 400)
		put(x)
		binary.LittleEndian.PutUint32(x, 401)
		put(x)
	}
	put(f64s(1.5, 2.5, 3.5))

	m, err := ReadMultiline(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if m.M1 != 1.5 || m.A != 9 || m.VertexCnt != 1 || m.SegmentCnt != 1 || m.BreakCnt != 1 ||
		m.Selector != 2 {
		t.Fatalf("%+v", m)
	}
	if m.I64 != 12 || m.W[17] != 117 || m.D5 != 16 {
		t.Fatalf("prefix: %+v", m)
	}
	if len(m.Segments) != 1 || m.Segments[0].D != 1.25 || m.Segments[0].W[5] != 205 {
		t.Fatalf("seg: %+v", m.Segments)
	}
	if len(m.Vertices) != 1 || m.Vertices[0].Origin.Z != 3 || m.Vertices[0].A != 300 || m.Vertices[0].C != 302 {
		t.Fatalf("vtx: %+v", m.Vertices)
	}
	if len(m.Breaks) != 1 || m.Breaks[0].A != 400 || m.Breaks[0].R != 3.5 {
		t.Fatalf("brk: %+v", m.Breaks)
	}
}

func TestReadDStringAnsi(t *testing.T) {
	b := cat([]byte("hi\x00"), []byte{1})
	s, err := ReadDString(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if s.Unicode || string(s.Ansi) != "hi" {
		t.Fatalf("%+v", s)
	}
}

func TestReadDStringUnicodeBOM(t *testing.T) {
	b := []byte{0xff, 0xfe, 'A', 0, 'B', 0, 0, 0, 9}
	s, err := ReadDString(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if !s.Unicode || len(s.UTF16) != 2 || s.UTF16[0] != 'A' || s.UTF16[1] != 'B' {
		t.Fatalf("%+v", s)
	}
}

func TestReadBSplineBoundary(t *testing.T) {
	b := cat(u32s(5, 2), f64s(1, 2, 3, 4))
	x, err := ReadBSplineBoundary(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if x.A != 5 || x.Count != 2 || x.Pts[1].X != 3 {
		t.Fatalf("%+v", x)
	}
}

func TestReadTableEntry(t *testing.T) {
	b := cat([]byte{1, 2, 3, 4, 5})
	e, err := ReadTableEntry(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if len(e.Raw) != 5 || e.Raw[0] != 1 {
		t.Fatalf("%+v", e)
	}
}

func TestTableHeaders(t *testing.T) {
	lb := make([]byte, 0, 28)
	u16b := func(v uint16) { x := make([]byte, 2); binary.LittleEndian.PutUint16(x, v); lb = append(lb, x...) }
	u64b := func(v uint64) { x := make([]byte, 8); binary.LittleEndian.PutUint64(x, v); lb = append(lb, x...) }
	u16b(7)
	u16b(8)
	u64b(0x1122334455667788)
	lb = append(lb, f64s(1.5)...)
	lb = append(lb, f64s(2.5)...)
	lh, err := ReadTableLevelHeader(le.New(lb))
	if err != nil {
		t.Fatal(err)
	}
	if lh.A != 7 || lh.B != 8 || lh.Flags != 0x1122334455667788 || lh.D2 != 2.5 {
		t.Fatalf("%+v", lh)
	}
	mh, err := ReadTableMLStyleHeader(le.New([]byte{9, 0, 10, 0, 11, 0, 12, 0, 13, 0, 14, 0}))
	if err != nil || mh.A != 9 || mh.Reserved[0] != 10 || mh.Reserved[4] != 14 {
		t.Fatalf("%+v %v", mh, err)
	}
	tb, err := ReadTableBlob(le.New([]byte{1, 2, 3}))
	if err != nil || len(tb.Raw) != 3 {
		t.Fatalf("%+v %v", tb, err)
	}
}

// TestReadTagElement covers the 216B fixed prefix + all value shapes (D79).
func TestReadTagElement(t *testing.T) {
	prefix := func() []byte {
		var b []byte
		b = append(b, f64s(1, 2, 3)...) // P1
		b = append(b, f64s(4, 5, 6)...) // P2
		b = append(b, []byte{7, 0, 8, 0}...)
		b = append(b, u32s(9)...)
		b = append(b, f64s(10, 11, 12)...) // P3
		b = append(b, f64s(13, 14, 15)...) // V3
		b = append(b, []byte{16, 0}...)    // D1
		b = append(b, []byte{1, 0}...)     // ValueType placeholder (patched below)
		b = append(b, []byte{17, 0, 18, 0}...)
		b = append(b, f64s(1, 2, 3, 4, 5)...) // M[5]
		b = append(b, f64s(9, 8, 7, 6)...)    // Rot[4]
		b = append(b, u32s(19, 20, 21, 22)...)
		b = append(b, []byte{23, 0}...)
		b = append(b, 24, 25)
		b = append(b, u32s(26)...)
		b = append(b, []byte{27, 0}...)
		b = append(b, []byte{5, 0}...) // StrLen=5
		b = append(b, u32s(28)...)
		if len(b) != 216 {
			t.Fatalf("prefix len=%d", len(b))
		}
		return b
	}
	// value type1: string
	b := prefix()
	binary.LittleEndian.PutUint16(b[106:], 1) // ValueType (D1@104, VT@106)
	b = append(b, "tag!\x00"...)
	if (len(b))&1 != 0 {
		b = append(b, 0) // align pad
	}
	tg, err := ReadTagElement(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if tg.P1.Z != 3 || tg.A != 7 || tg.C != 9 || tg.P3.Z != 12 || tg.V3.X != 13 ||
		tg.D1 != 16 || tg.ValueType != 1 || tg.M[4] != 5 || tg.Rot[0] != 9 ||
		tg.F[3] != 22 || tg.H != 24 || tg.StrLen != 5 || tg.L != 28 ||
		tg.ValueStr != "tag!\x00" {
		t.Fatalf("%+v", tg)
	}

	// value type3: u32
	b3 := prefix()
	binary.LittleEndian.PutUint16(b3[106:], 3)
	b3 = append(b3, u32s(0xCAFEBABE)...)
	t3, err := ReadTagElement(le.New(b3))
	if err != nil {
		t.Fatal(err)
	}
	if t3.ValueInt != 0xCAFEBABE {
		t.Fatalf("%+v", t3)
	}

	// value type4: f64
	b4 := prefix()
	binary.LittleEndian.PutUint16(b4[106:], 4)
	b4 = append(b4, f64s(-2.75)...)
	t4, err := ReadTagElement(le.New(b4))
	if err != nil {
		t.Fatal(err)
	}
	if t4.ValueReal != -2.75 {
		t.Fatalf("%+v", t4)
	}

	// truncated
	if _, err := ReadTagElement(le.New(prefix()[:100])); err == nil {
		t.Fatal("short must fail")
	}
}

func TestReadMeshHeader(t *testing.T) {
	mh, err := ReadMeshHeader(le.New(u32s(0xdeadbeef)))
	if err != nil || mh.A != 0xdeadbeef {
		t.Fatalf("%+v %v", mh, err)
	}
}

func TestReadSharedCellInst(t *testing.T) {
	var b []byte
	b = append(b, u32s(7)...)
	b = append(b, []byte{1, 0, 2, 0}...)
	b = append(b, f64s(1, 2, 3)...)                   // origin1
	b = append(b, f64s(4, 5, 6)...)                   // origin2
	b = append(b, f64s(1, 0, 0, 0, 1, 0, 0, 0, 1)...) // mat 3x3
	b = append(b, f64s(7, 8, 9)...)                   // origin3
	if len(b) != 152 {
		t.Fatalf("body len=%d", len(b))
	}
	s, err := ReadSharedCellInst(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if s.A != 7 || s.B != 1 || s.C != 2 || s.Origin1.Z != 3 || s.Origin2.X != 4 ||
		s.Mat[4] != 1 || s.Origin3.Y != 8 {
		t.Fatalf("%+v", s)
	}
}

func TestReadSharedCellDef(t *testing.T) {
	var b []byte
	b = append(b, 1, 2)                               // flags
	b = append(b, []byte{3, 0}...)                    // u16
	b = append(b, f64s(10, 20, 30)...)                // origin1
	b = append(b, f64s(40, 50, 60)...)                // origin2
	b = append(b, f64s(1, 0, 0, 0, 1, 0, 0, 0, 1)...) // mat
	b = append(b, f64s(70, 80, 90)...)                // origin3
	if len(b) != 148 {
		t.Fatalf("body len=%d", len(b))
	}
	s, err := ReadSharedCellDef(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if s.Flag1 != 1 || s.Flag2 != 2 || s.W != 3 || s.Origin1.Z != 30 ||
		s.Origin2.X != 40 || s.Mat[4] != 1 || s.Origin3.Y != 80 {
		t.Fatalf("%+v", s)
	}
}

func TestReadMatrixDoubleData(t *testing.T) {
	var b []byte
	b = append(b, []byte{7, 0}...) // u16
	blob := make([]byte, 70)
	for i := range blob {
		blob[i] = byte(i)
	}
	b = append(b, blob...)
	b = append(b, u32s(2, 11, 22, 33)...) // count +3 u32
	b = append(b, f64s(1.5, -2.5)...)
	m, err := ReadMatrixDoubleData(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if m.W != 7 || m.Blob[69] != 69 || m.Count != 2 || m.D1 != 11 || m.D3 != 33 ||
		len(m.Values) != 2 || m.Values[1] != -2.5 {
		t.Fatalf("%+v", m)
	}
	// truncated values → error, not panic/hang
	if _, err := ReadMatrixDoubleData(le.New(b[:len(b)-4])); err == nil {
		t.Fatal("short values must fail")
	}
}

func TestReadRasterHeader(t *testing.T) {
	var b []byte
	b = append(b, []byte{1, 0, 2, 0, 3}...)    // u16,u16,u8
	b = append(b, 4)                           // u8
	b = append(b, []byte{5, 0, 6, 0, 7, 0}...) // u16×3
	b = append(b, f64s(8, 9)...)
	b = append(b, f64s(10, 11, 12)...)
	if len(b) != 52 {
		t.Fatalf("len=%d", len(b))
	}
	h, err := ReadRasterHeader(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if h.A != 1 || h.B != 2 || h.C != 3 || h.D != 4 || h.E != 5 || h.F != 6 || h.G != 7 ||
		h.H != 8 || h.I != 9 || h.Origin.Z != 12 {
		t.Fatalf("%+v", h)
	}
}

func TestReadRasterReference(t *testing.T) {
	mk := func(a uint16) []byte {
		var b []byte
		b = append(b, []byte{byte(a), byte(a >> 8), 0, 0}...) // u16×2
		b = append(b, u32s(1, 2, 3, 4)...)                    // u32×4
		x := make([]byte, 4)
		binary.LittleEndian.PutUint32(x, 0xFFFFFFF6) // i32 = -10
		b = append(b, x...)
		binary.LittleEndian.PutUint32(x, 20)
		b = append(b, x...)
		b = append(b, f64s(1, 2, 3)...) // origin
		b = append(b, f64s(4, 5, 6, 7)...)
		if a == 0 {
			b = append(b, u32s(9, 10)...)
		}
		return b
	}
	x0, err := ReadRasterReference(le.New(mk(0)))
	if err != nil {
		t.Fatal(err)
	}
	if x0.A != 0 || x0.G != -10 || x0.H != 20 || x0.Origin.Y != 2 || x0.M4 != 7 || x0.D1 != 9 || x0.D2 != 10 {
		t.Fatalf("%+v", x0)
	}
	if len(mk(0)) != 92 || len(mk(1)) != 84 {
		t.Fatalf("sizes %d %d", len(mk(0)), len(mk(1)))
	}
	x1, err := ReadRasterReference(le.New(mk(1)))
	if err != nil {
		t.Fatal(err)
	}
	if x1.A != 1 || x1.D1 != 0 {
		t.Fatalf("%+v", x1)
	}
}

func TestReadRasterRefGeoAndRender(t *testing.T) {
	var g []byte
	g = append(g, []byte{1, 0, 2, 0}...)
	g = append(g, u32s(3)...)
	g = append(g, f64s(1, 2, 3)...) // Pt3d
	g = append(g, f64s(4, 5)...)    // Pt2d
	g = append(g, f64s(6, 7)...)    // f64×2
	g = append(g, f64s(8, 9)...)    // Pt2d
	g = append(g, u32s(10, 11, 12, 13, 14, 15)...)
	g = append(g, f64s(16, 17, 18)...) // Vec3d
	g = append(g, f64s(19, 20, 21)...) // Vec3d
	if len(g) != 152 {
		t.Fatalf("geo len=%d", len(g))
	}
	geo, err := ReadRasterRefGeo(le.New(g))
	if err != nil {
		t.Fatal(err)
	}
	if geo.A != 1 || geo.C != 3 || geo.Origin.Z != 3 || geo.P1.Y != 5 || geo.D1 != 6 ||
		geo.P2.X != 8 || geo.F[5] != 15 || geo.N1.X != 16 || geo.N2.Z != 21 {
		t.Fatalf("%+v", geo)
	}

	var rn []byte
	rn = append(rn, []byte{1, 0, 2, 0}...)
	rn = append(rn, u32s(3, 4)...)
	rn = append(rn, 5, 6) // u8×2
	for _, c := range [][3]byte{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}} {
		rn = append(rn, c[0], c[1], c[2])
	}
	rn = append(rn, 13, 14)
	rn = append(rn, u32s(15)...)
	rn = append(rn, f64s(1, 2, 3, 4)...)
	if len(rn) != 64 {
		t.Fatalf("render len=%d", len(rn))
	}
	rr, err := ReadRasterRefRender(le.New(rn))
	if err != nil {
		t.Fatal(err)
	}
	if rr.A != 1 || rr.C != 3 || rr.E != 5 || rr.Color0 != 0x030201 ||
		rr.Color3 != 0x0c0b0a || rr.G != 13 || rr.I != 15 || rr.M != 4 {
		t.Fatalf("%+v", rr)
	}
}

func TestReadRasterRefUnknown(t *testing.T) {
	b := append([]byte{1, 0, 2, 0}, u32s(9)...)
	b = append(b, 0xEE, 0xFF)
	x, err := ReadRasterRefUnknown(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if x.A != 1 || x.B != 2 || x.C != 9 || len(x.Rest) != 2 || x.Rest[0] != 0xEE {
		t.Fatalf("%+v", x)
	}
}

func TestReadRasterComponentAndClip(t *testing.T) {
	var b []byte
	b = append(b, []byte{1, 0, 2, 0, 3, 4, 5, 0, 6, 0, 7, 0}...) // u16,u16,u8,u8,u16,u16,u16 =12B
	b = append(b, 0xAA, 0xBB, 0xCC)                              // rest
	if len(b) != 15 {
		t.Fatalf("len=%d", len(b))
	}
	c, err := ReadRasterComponent(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if c.A != 1 || c.B != 2 || c.C != 3 || c.D != 4 || c.E != 5 || c.F != 6 || c.G != 7 ||
		len(c.Rest) != 3 || c.Rest[0] != 0xAA {
		t.Fatalf("%+v", c)
	}

	var cb []byte
	cb = append(cb, []byte{1, 0, 2, 0}...)
	cb = append(cb, u32s(9)...)
	cb = append(cb, []byte{3, 0, 4, 0}...)
	cb = append(cb, u32s(2)...)
	cb = append(cb, f64s(10, 20, 30, 40)...)
	if len(cb) != 48 {
		t.Fatalf("clip len=%d", len(cb))
	}
	clip, err := ReadRasterRefClip(le.New(cb))
	if err != nil {
		t.Fatal(err)
	}
	if clip.A != 1 || clip.C != 9 || clip.D != 3 || clip.E != 4 || clip.N != 2 ||
		len(clip.Pts) != 2 || clip.Pts[1].Y != 40 {
		t.Fatalf("%+v", clip)
	}
}

func TestReadRasterFrame(t *testing.T) {
	build := func(e uint16) []byte {
		var b []byte
		b = append(b, u32s(1, 2, 3)...)   // A,B,C
		b = append(b, make([]byte, 4)...) // skip4
		for i := 0; i < 16; i++ {
			b = append(b, f64s(float64(i))...)
		} // Matrix
		b = append(b, u32s(7)...)         // D
		b = append(b, byte(e), 0)         // E
		b = append(b, 0xAA, 0)            // F
		b = append(b, u32s(11)...)        // G
		b = append(b, make([]byte, 4)...) // skip4
		b = append(b, f64s(1.5, 2.5)...)  // P1
		b = append(b, f64s(3.5, 4.5)...)  // P2
		b = append(b, u32s(12, 13)...)    // H,I
		b = append(b, f64s(9.5, 10.5)...) // J,K
		b = append(b, u32s(14, 15, 16, 17)...)
		b = append(b, 0x11, 0x22, 0x33) // M,N,O
		b = append(b, 0)                // skip1
		b = append(b, 0x44)             // P
		b = append(b, 0, 0, 0)          // skip3
		if e == 1 || e == 6 {
			b = append(b, u32s(99)...) // V
		} else {
			b = append(b, 0xDE, 0xAD, 0xBE, 0xEF) // V2
		}
		for i := range make([]byte, 512) {
			b = append(b, byte(i))
		} // Blob
		b = append(b, make([]byte, 4)...) // skip4
		b = append(b, u32s(21)...)        // Q
		b = append(b, make([]byte, 4)...) // skip4
		b = append(b, u32s(22)...)        // R
		b = append(b, make([]byte, 4)...) // skip4
		b = append(b, f64s(100, 101, 102, 103, 104, 105)...)
		return b
	}
	for _, e := range []uint16{1, 6, 2} {
		f, err := ReadRasterFrame(le.New(build(e)))
		if err != nil {
			t.Fatal(err)
		}
		if f.A != 1 || f.B != 2 || f.C != 3 || f.D != 7 || f.E != e || f.G != 11 ||
			f.Matrix[0][0] != 0 || f.Matrix[3][3] != 15 ||
			f.P1.X != 1.5 || f.P2.Y != 4.5 || f.H != 12 || f.I != 13 ||
			f.J != 9.5 || f.K != 10.5 || f.L[3] != 17 ||
			f.M != 0x11 || f.N != 0x22 || f.O != 0x33 || f.P != 0x44 ||
			f.Blob[0] != 0 || f.Blob[255] != 255 ||
			f.Q != 21 || f.R != 22 || f.Y != 105 {
			t.Fatalf("e=%d %+v", e, f)
		}
		if e == 1 || e == 6 {
			if f.V != 99 || f.V2 != [4]byte{} {
				t.Fatalf("e=%d branch V %+v", e, f)
			}
		} else if f.V != 0 || f.V2 != [4]byte{0xDE, 0xAD, 0xBE, 0xEF} {
			t.Fatalf("e=%d branch V2 %+v", e, f)
		}
	}
}

func TestReadRasterRefTransp(t *testing.T) {
	var b []byte
	b = append(b, []byte{1, 0, 2, 0}...)
	b = append(b, u32s(3, 4)...)
	for i := 0; i < 256; i++ {
		b = append(b, byte(i), byte(255-i))
	}
	b = append(b, u32s(0xCAFEBABE)...)
	x, err := ReadRasterRefTransp(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if x.A != 1 || x.B != 2 || x.C != 3 || x.D != 4 ||
		x.Idx[0] != 0 || x.Val[0] != 255 || x.Idx[128] != 128 || x.Val[128] != 127 ||
		x.Tail != 0xCAFEBABE {
		t.Fatalf("%+v", x)
	}
}

func TestReadRasterRefRGBTransp(t *testing.T) {
	var b []byte
	b = append(b, []byte{5, 0, 6, 0}...)
	b = append(b, u32s(7, 8)...)
	for i := 0; i < 32; i++ {
		b = append(b, byte(i), byte(i+1), byte(i+2))   // RGB0
		b = append(b, byte(i+3), byte(i+4), byte(i+5)) // RGB1
		b = append(b, byte(i*7))                       // alpha
	}
	b = append(b, u32s(0xDEADBEEF)...)
	x, err := ReadRasterRefRGBTransp(le.New(b))
	if err != nil {
		t.Fatal(err)
	}
	if x.A != 5 || x.B != 6 || x.C != 7 || x.D != 8 ||
		x.Pair[0].RGB0 != 0x020100 || x.Pair[0].RGB1 != 0x050403 || x.Pair[0].Alpha != 0 ||
		x.Pair[31].RGB0 != 0x21201F || x.Pair[31].Alpha != 31*7 ||
		x.Tail != 0xDEADBEEF {
		t.Fatalf("%+v", x)
	}
}
