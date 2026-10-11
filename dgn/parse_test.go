package dgn

import (
	"encoding/binary"
	"math"
	"testing"

	"github.com/flywave/go-dgn/dgn/element"
)

func f64le(vals ...float64) []byte {
	b := make([]byte, 8*len(vals))
	for i, v := range vals {
		binary.LittleEndian.PutUint64(b[8*i:], math.Float64bits(v))
	}
	return b
}

func join(parts ...[]byte) []byte {
	var out []byte
	for _, p := range parts {
		out = append(out, p...)
	}
	return out
}

func modeBRec(typeID uint16) []byte {
	b := []byte{0x01, 0x10, 0, 0}
	binary.LittleEndian.PutUint16(b[2:], typeID)
	return b
}

func TestParseAllLineWithLinkage(t *testing.T) {
	body := f64le(1, 2, 3, 4)
	hdr := buildHeader(Header{Type: 3, ID: 7})
	rec := modeBRec(0x56e9)
	space := join(hdr, body, rec)

	d := Dir{Base: 0, Offsets: []uint32{0}}
	got, err := ParseAll(space, d)
	if err != nil {
		t.Fatal(err)
	}
	if len(got) != 1 {
		t.Fatalf("len=%d", len(got))
	}
	p := got[0]
	if p.Record.Type != 3 || p.Record.ID != 7 {
		t.Fatalf("record=%+v", p.Record)
	}
	bd, ok := p.Body.(*Body)
	if !ok {
		t.Fatalf("body type %T", p.Body)
	}
	ln, ok := bd.Value.(*element.Line)
	if !ok || ln.Start.X != 1 || ln.End.Y != 4 {
		t.Fatalf("line=%+v", ln)
	}
	if len(p.Linkages) != 1 || p.Linkages[0].TypeID != 0x56e9 || len(p.Linkages[0].Raw) != 4 {
		t.Fatalf("linkages=%+v", p.Linkages)
	}
}

func TestParseAllProxyAndOrdering(t *testing.T) {
	e0 := join(buildHeader(Header{Type: 120, ID: 1}), []byte{0xaa, 0xbb})
	e1 := join(buildHeader(Header{Type: 3, ID: 2}), f64le(0, 0, 5, 6))
	space := join(e0, e1)
	d := Dir{Base: 0, Offsets: []uint32{0, uint32(len(e0))}}
	got, err := ParseAll(space, d)
	if err != nil {
		t.Fatal(err)
	}
	if len(got) != 2 {
		t.Fatalf("len=%d", len(got))
	}
	if _, ok := got[0].Body.(*ProxyElement); !ok {
		t.Fatalf("e0 body %T", got[0].Body)
	}
	px := got[0].Body.(*ProxyElement)
	if len(px.Raw) != 2 || px.Raw[0] != 0xaa {
		t.Fatalf("proxy raw=%v", px.Raw)
	}
	ln := got[1].Body.(*Body).Value.(*element.Line)
	if ln.End.X != 5 || ln.End.Y != 6 {
		t.Fatalf("line=%+v", ln)
	}
}

func TestParseAllDisplayHeaderConsumed(t *testing.T) {
	// any non-100 type with bit12 consumes the display header
	hdr := buildHeader(Header{Type: 99, Flag: FlagDisplayHeader | FlagComplex, ID: 9})
	disp := make([]byte, DisplayHeaderSize)
	binary.LittleEndian.PutUint16(disp[8:], 1<<11)
	raw := []byte{1, 2, 3, 4}
	space := join(hdr, disp, raw)
	d := Dir{Base: 0, Offsets: []uint32{0}}
	got, err := ParseAll(space, d)
	if err != nil {
		t.Fatal(err)
	}
	p := got[0]
	if p.Record.Ext != 1 {
		t.Fatalf("ext=%d", p.Record.Ext)
	}
	px, ok := p.Body.(*ProxyElement)
	if !ok || len(px.Raw) != 4 {
		t.Fatalf("body=%+v", p.Body)
	}
}

func TestType100SkipsDisplayHeader(t *testing.T) {
	// type100 (XREF header) never carries the standard display header (D64),
	// even with bit12 set: body starts right after the 36B header.
	hdr := buildHeader(Header{Type: 100, Flag: FlagDisplayHeader, ID: 9})
	raw := []byte{9, 8, 7}
	space := join(hdr, raw)
	d := Dir{Base: 0, Offsets: []uint32{0}}
	got, err := ParseAll(space, d)
	if err != nil {
		t.Fatal(err)
	}
	px, ok := got[0].Body.(*ProxyElement)
	if !ok || len(px.Raw) != 3 || px.Raw[0] != 9 {
		t.Fatalf("body=%+v", got[0].Body)
	}
}

func TestParseLine3dViaDisplayFlag(t *testing.T) {
	hdr := buildHeader(Header{Type: 3, Flag: FlagDisplayHeader, ID: 11})
	disp := make([]byte, DisplayHeaderSize)
	binary.LittleEndian.PutUint16(disp[8:], 1<<11)
	body := f64le(1, 2, 3, 4, 5, 6)
	space := join(hdr, disp, body)
	d := Dir{Base: 0, Offsets: []uint32{0}}
	got, err := ParseAll(space, d)
	if err != nil {
		t.Fatal(err)
	}
	p := got[0]
	if p.Record.Ext != 1 {
		t.Fatalf("ext=%d", p.Record.Ext)
	}
	if k := p.Record.Key(); k.Group != Group2D3D || k.Value != 1 {
		t.Fatalf("key=%+v", k)
	}
	ln, ok := p.Body.(*Body).Value.(*element.Line3d)
	if !ok {
		t.Fatalf("body %T", p.Body)
	}
	if ln.End.Z != 6 {
		t.Fatalf("%+v", ln)
	}
}

func TestType11CurveSharesLineStringBody(t *testing.T) {
	// type11 Curve routes through the LineString readers (D73):
	// 2D without display header → LineString2d; 3D via display ext → LineString3d
	hdr := buildHeader(Header{Type: 11, B: 12, C: 12, ID: 3})
	body := join(u32s(2, 0x55), f64le(1, 2, 3, 4))
	got, err := ParseAll(join(hdr, body), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	ls, ok := got[0].Body.(*Body).Value.(*element.LineString)
	if !ok || len(ls.Points) != 2 || ls.Points[1].Y != 4 {
		t.Fatalf("2d body %T %+v", got[0].Body, got[0].Body)
	}

	hdr3 := buildHeader(Header{Type: 11, Flag: FlagDisplayHeader, B: 24, C: 24, ID: 4})
	disp := make([]byte, DisplayHeaderSize)
	binary.LittleEndian.PutUint16(disp[8:], 1<<11) // 3D format
	body3 := join(u32s(2, 0), f64le(1, 2, 3, 4, 5, 6))
	got3, err := ParseAll(join(hdr3, disp, body3), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	ls3, ok := got3[0].Body.(*Body).Value.(*element.LineString3d)
	if !ok || len(ls3.Points) != 2 || ls3.Points[1].Z != 6 {
		t.Fatalf("3d body %T %+v", got3[0].Body, got3[0].Body)
	}

	// type13 ConicSection routes identically (D73)
	hdr13 := buildHeader(Header{Type: 13, B: 12, C: 12, ID: 5})
	got13, err := ParseAll(join(hdr13, body), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if _, ok := got13[0].Body.(*Body).Value.(*element.LineString); !ok {
		t.Fatalf("conic body %T", got13[0].Body)
	}
}

func TestType35SharedCellInstRoutes(t *testing.T) {
	hdr := buildHeader(Header{Type: 35, B: 80, C: 80, ID: 7})
	body := join(u32s(1), []byte{0, 0, 0, 0}, make([]byte, 144))
	got, err := ParseAll(join(hdr, body), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	s, ok := got[0].Body.(*Body).Value.(*element.SharedCellInst)
	if !ok || s.A != 1 {
		t.Fatalf("body %T %+v", got[0].Body, got[0].Body)
	}
}

func TestType91And106VariantRoutes(t *testing.T) {
	// (91,3) RGB → ERasterRefCompUnknown layout (u16,u16,u32+rest)
	h91 := buildHeader(Header{Type: 91, Sub: 3, B: 8, C: 8, ID: 15})
	b91 := append([]byte{1, 0, 2, 0}, u32s(9)...)
	b91 = append(b91, 0xEE)
	got, err := ParseAll(join(h91, b91), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	x, ok := got[0].Body.(*Body).Value.(*element.RasterRefUnknown)
	if !ok || x.A != 1 || x.C != 9 || len(x.Rest) != 1 || x.Rest[0] != 0xEE {
		t.Fatalf("body %T %+v", got[0].Body, got[0].Body)
	}
	// (91,7) Geo / (91,8) Render route to their pinned readers (D81)
	hg := buildHeader(Header{Type: 91, Sub: 7, B: 80, C: 80, ID: 19})
	gg := make([]byte, 152)
	gotg, err := ParseAll(join(hg, gg), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if _, ok := gotg[0].Body.(*Body).Value.(*element.RasterRefGeo); !ok {
		t.Fatalf("geo body %T", gotg[0].Body)
	}
	hr := buildHeader(Header{Type: 91, Sub: 8, B: 34, C: 34, ID: 20})
	gr := make([]byte, 64)
	gotr, err := ParseAll(join(hr, gr), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if _, ok := gotr[0].Body.(*Body).Value.(*element.RasterRefRender); !ok {
		t.Fatalf("render body %T", gotr[0].Body)
	}
	// unmapped subtype (91,0) → Proxy
	h91z := buildHeader(Header{Type: 91, Sub: 0, B: 4, C: 4, ID: 16})
	gotz, err := ParseAll(join(h91z, []byte{7, 7}), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if _, ok := gotz[0].Body.(*ProxyElement); !ok {
		t.Fatalf("unmapped91 subtype not proxy: %T", gotz[0].Body)
	}

	// (106,1) SectionClip → rest blob; (106,2) Terrain → Proxy
	h106 := buildHeader(Header{Type: 106, Sub: 1, B: 8, C: 8, ID: 17})
	got106, err := ParseAll(join(h106, []byte{9, 8, 7}), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if tb, ok := got106[0].Body.(*Body).Value.(*element.TableBlob); !ok || len(tb.Raw) != 3 || tb.Raw[0] != 9 {
		t.Fatalf("body %T %+v", got106[0].Body, got106[0].Body)
	}
	h106b := buildHeader(Header{Type: 106, Sub: 2, B: 6, C: 6, ID: 18})
	got106b, err := ParseAll(join(h106b, []byte{1, 2}), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if _, ok := got106b[0].Body.(*ProxyElement); !ok {
		t.Fatalf("unmapped106 subtype not proxy: %T", got106b[0].Body)
	}
}

func TestType37TagElementRoutes(t *testing.T) {
	// 216B prefix zeros +5B string value
	h := buildHeader(Header{Type: 37, B: 113, C: 113, ID: 14})
	body := make([]byte, 221)
	binary.LittleEndian.PutUint16(body[106:], 1) // ValueType
	binary.LittleEndian.PutUint16(body[210:], 5) // StrLen
	copy(body[216:], "hi\x00\x00\x00")
	got, err := ParseAll(join(h, body), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	tg, ok := got[0].Body.(*Body).Value.(*element.TagElement)
	if !ok || tg.ValueType != 1 || tg.ValueStr != "hi\x00\x00\x00" {
		t.Fatalf("body %T %+v", got[0].Body, got[0].Body)
	}
}

func TestType88RasterComponentRoutes(t *testing.T) {
	h := buildHeader(Header{Type: 88, B: 10, C: 10, ID: 13})
	body := append(make([]byte, 12), 0x77)
	got, err := ParseAll(join(h, body), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	c, ok := got[0].Body.(*Body).Value.(*element.RasterComponent)
	if !ok || len(c.Rest) != 1 || c.Rest[0] != 0x77 {
		t.Fatalf("body %T %+v", got[0].Body, got[0].Body)
	}
}

func TestType87And90RasterRoutes(t *testing.T) {
	// type87 Group2D3D: both ext variants route to RasterHeader
	h87 := buildHeader(Header{Type: 87, B: 28, C: 28, ID: 10})
	b87 := make([]byte, 52)
	got, err := ParseAll(join(h87, b87), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if _, ok := got[0].Body.(*Body).Value.(*element.RasterHeader); !ok {
		t.Fatalf("2d body %T", got[0].Body)
	}
	h87d := buildHeader(Header{Type: 87, Flag: FlagDisplayHeader, B: 64, C: 64, ID: 11})
	disp := make([]byte, DisplayHeaderSize)
	got2, err := ParseAll(join(h87d, disp, b87), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if _, ok := got2[0].Body.(*Body).Value.(*element.RasterHeader); !ok {
		t.Fatalf("3d body %T", got2[0].Body)
	}

	// type90
	h90 := buildHeader(Header{Type: 90, B: 46, C: 46, ID: 12})
	b90 := make([]byte, 84)
	binary.LittleEndian.PutUint16(b90, 1) // A=1 → no tail
	got90, err := ParseAll(join(h90, b90), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if x, ok := got90[0].Body.(*Body).Value.(*element.RasterReference); !ok || x.A != 1 {
		t.Fatalf("body %T %+v", got90[0].Body, got90[0].Body)
	}
}

func TestType34And103Routes(t *testing.T) {
	// SharedCellDef(34): 148B body
	h34 := buildHeader(Header{Type: 34, B: 76, C: 76, ID: 8})
	b34 := make([]byte, 148)
	b34[0] = 9
	got, err := ParseAll(join(h34, b34), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if s, ok := got[0].Body.(*Body).Value.(*element.SharedCellDef); !ok || s.Flag1 != 9 {
		t.Fatalf("body %T %+v", got[0].Body, got[0].Body)
	}

	// MatrixDoubleData(103): u16+70B+u32×4+values
	h103 := buildHeader(Header{Type: 103, B: 50, C: 50, ID: 9})
	b103 := join([]byte{1, 0}, make([]byte, 70), u32s(1, 0, 0, 0), f64le(3.5))
	got103, err := ParseAll(join(h103, b103), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	m, ok := got103[0].Body.(*Body).Value.(*element.MatrixDoubleData)
	if !ok || m.Count != 1 || len(m.Values) != 1 || m.Values[0] != 3.5 {
		t.Fatalf("body %T %+v", got103[0].Body, got103[0].Body)
	}
}

func TestType105MeshHeaderRoutes(t *testing.T) {
	hdr := buildHeader(Header{Type: 105, Sub: 7, B: 5, C: 5, ID: 6})
	got, err := ParseAll(join(hdr, u32s(42), []byte{9, 8}), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	mh, ok := got[0].Body.(*Body).Value.(*element.MeshHeader)
	if !ok || mh.A != 42 || len(mh.Raw) != 2 || mh.Raw[0] != 9 {
		t.Fatalf("body %T %+v", got[0].Body, got[0].Body)
	}
}

func TestParseImplicitDisplayHeader(t *testing.T) {
	// type35 with C*2≥256 and no bit12: display header consumed implicitly;
	// type35 is now routed to ReadSharedCellInst (D74) — body = 152B after
	// the implicit 72B display header.
	hdr := buildHeader(Header{Type: 35, Flag: 0, Sub: 0, B: 128, C: 128})
	disp := make([]byte, DisplayHeaderSize)
	body := join(u32s(99), make([]byte, 148))
	space := join(hdr, disp, body)
	d := Dir{Base: 0, Offsets: []uint32{0}}
	got, err := ParseAll(space, d)
	if err != nil {
		t.Fatal(err)
	}
	s, ok := got[0].Body.(*Body).Value.(*element.SharedCellInst)
	if !ok || s.A != 99 {
		t.Fatalf("implicit disp not consumed or misrouted: body=%+v", got[0].Body)
	}
}

func TestParseLineString3dEndToEnd(t *testing.T) {
	hdr := buildHeader(Header{Type: 4, Flag: FlagDisplayHeader, ID: 21})
	disp := make([]byte, DisplayHeaderSize)
	binary.LittleEndian.PutUint16(disp[8:], 1<<11)
	body := join(u32s(2, 0x55), f64le(1, 2, 3, 4, 5, 6))
	space := join(hdr, disp, body)
	d := Dir{Base: 0, Offsets: []uint32{0}}
	got, err := ParseAll(space, d)
	if err != nil {
		t.Fatal(err)
	}
	ls, ok := got[0].Body.(*Body).Value.(*element.LineString3d)
	if !ok {
		t.Fatalf("body %T", got[0].Body)
	}
	if ls.Flags != 0x55 || ls.Points[1].Z != 6 {
		t.Fatalf("%+v", ls)
	}
}

func u32s(vals ...uint32) []byte {
	b := make([]byte, 4*len(vals))
	for i, v := range vals {
		binary.LittleEndian.PutUint32(b[4*i:], v)
	}
	return b
}

// TestLinkageSplitByHeaderWords verifies the B/C based attribute-region
// split (D65): linkage starts at C*2+4 regardless of body decoder progress.
// The v8 type27 reader consumes only 12B of a 46B body region — the
// Rest-based fallback would start 34B early and lose the first record.
func TestLinkageSplitByHeaderWords(t *testing.T) {
	// body region 46B (42 consumed + 4 pad), linkage 12B;
	// as = C*2+4 = 82 (C=39), ae = B*2+4 = 94 (B=45), attrib = (B−C)*2 = 12
	hdr := buildHeader(Header{Type: 27, B: 45, C: 39, ID: 5})
	body := make([]byte, 46) // header fields all zero; reader takes 42
	var link []byte
	for _, id := range []uint16{0x1111, 0x2222, 0x3333} {
		// mode-B record: hdr16 = userData(bit12)|count(1) → len = count*2+2 = 4
		link = append(link, 0x01, 0x10, byte(id), byte(id>>8))
	}
	space := join(hdr, body, link)
	if len(space) != 94 {
		t.Fatalf("space=%d", len(space))
	}
	d := Dir{Base: 0, Offsets: []uint32{0}}
	got, err := ParseAll(space, d)
	if err != nil {
		t.Fatal(err)
	}
	p := got[0]
	if len(p.Linkages) != 3 {
		t.Fatalf("linkages=%d %+v", len(p.Linkages), p.Linkages)
	}
	want := []uint16{0x1111, 0x2222, 0x3333}
	for i, r := range p.Linkages {
		if r.TypeID != want[i] {
			t.Fatalf("linkage %d type=%#x want %#x (%+v)", i, r.TypeID, want[i], p.Linkages)
		}
	}

	// no B/C (fixtures): fallback = remainder path — starts inside the body
	// pad, so the first record is garbage (TypeID 0) and 0x1111 is lost;
	// documents why the header-words split matters.
	hdr0 := buildHeader(Header{Type: 27, ID: 5})
	got0, err := ParseAll(join(hdr0, body, link), d)
	if err != nil {
		t.Fatal(err)
	}
	if len(got0[0].Linkages) == 0 || got0[0].Linkages[0].TypeID != 0 {
		t.Fatalf("fallback=%+v", got0[0].Linkages)
	}
}

func TestType94RasterFrameRoutes(t *testing.T) {
	// RasterFrame(94) body per D82 trace: u32×3, skip4, f64×16, u32,
	// u16(E),u16,u32, skip4, Pt2d×2, u32×2, f64×2, u32×4, u8×3, skip1, u8,
	// skip3, V(u32, E=1), bytes512, skip4,u32, skip4,u32, skip4, f64×6, skip96.
	var b []byte
	b = append(b, u32s(5, 6, 7)...)
	b = append(b, make([]byte, 4)...)
	for i := 0; i < 16; i++ {
		b = append(b, f64le(float64(i))...)
	}
	b = append(b, u32s(1)...)
	b = append(b, 1, 0)       // E=1 → u32 branch
	b = append(b, 2, 0)       // F
	b = append(b, u32s(3)...) // G
	b = append(b, make([]byte, 4)...)
	b = append(b, f64le(1, 2, 3, 4)...) // P1,P2
	b = append(b, u32s(8, 9)...)
	b = append(b, f64le(5, 6)...)
	b = append(b, u32s(10, 11, 12, 13)...)
	b = append(b, 0x55, 0x66, 0x77)
	b = append(b, 0)
	b = append(b, 0x88)
	b = append(b, 0, 0, 0)
	b = append(b, u32s(77)...) // V
	b = append(b, make([]byte, 512)...)
	b = append(b, make([]byte, 4)...)
	b = append(b, u32s(31)...)
	b = append(b, make([]byte, 4)...)
	b = append(b, u32s(32)...)
	b = append(b, make([]byte, 4)...)
	b = append(b, f64le(200, 201, 202, 203, 204, 205)...)
	hdr := buildHeader(Header{Type: 94, B: 100, C: 100, ID: 10})
	got, err := ParseAll(join(hdr, b), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	rf, ok := got[0].Body.(*Body).Value.(*element.RasterFrame)
	if !ok {
		t.Fatalf("body %T %+v", got[0].Body, got[0].Body)
	}
	if rf.A != 5 || rf.E != 1 || rf.V != 77 || rf.O != 0x77 || rf.Y != 205 {
		t.Fatalf("%+v", rf)
	}
}

// TestType3DRoutes exercises every Group2D3D Value=1 (3D) registration via
// the display-header 3D flag: Shape3d(6), TextNode3d(7), Ellipse3d(15),
// Arc3d(16), Text3d(17), PointString3d(22).
func TestType3DRoutes(t *testing.T) {
	parse3d := func(typ uint16, body []byte) any {
		t.Helper()
		hdr := buildHeader(Header{Type: typ, Flag: FlagDisplayHeader, B: 100, C: 100, ID: 40})
		disp := make([]byte, DisplayHeaderSize)
		binary.LittleEndian.PutUint16(disp[8:], 1<<11) // 3D format
		got, err := ParseAll(join(hdr, disp, body), Dir{Base: 0, Offsets: []uint32{0}})
		if err != nil {
			t.Fatal(err)
		}
		return got[0].Body.(*Body).Value
	}

	// Shape3d = LineString3d body: count, flags, count×Pt3d
	sh, ok := parse3d(6, join(u32s(2, 7), f64le(1, 2, 3, 4, 5, 6))).(*element.LineString3d)
	if !ok || sh.Flags != 7 || sh.Points[1].Z != 6 {
		t.Fatalf("shape3d %T %+v", sh, sh)
	}

	// TextNode3d: u32×2, u16×2, f64×3, quat(4), pt3d = 92B
	tn := parse3d(7, join(u32s(11, 12), []byte{13, 0, 14, 0},
		f64le(1, 2, 3), f64le(0.25, 0.5, 0.75, 1), f64le(9, 8, 7))).(*element.TextNode3d)
	if tn.U32a != 11 || tn.U16b != 14 || tn.D[2] != 3 || tn.Rot.W != 0.25 || tn.Origin.Z != 7 {
		t.Fatalf("%+v", tn)
	}

	// Ellipse3d: f64×2, quat, pt3d = 72B
	el := parse3d(15, join(f64le(5, 6), f64le(0.5, 0.5, 0.5, 0.5), f64le(1, 2, 3))).(*element.Ellipse3d)
	if el.Primary != 5 || el.Rotation.X != 0.5 || el.Origin.Z != 3 {
		t.Fatalf("%+v", el)
	}

	// Arc3d: f64×4, quat, pt3d = 88B
	ar := parse3d(16, join(f64le(1, 2, 3, 4), f64le(1, 0, 0, 0), f64le(7, 8, 9))).(*element.Arc3d)
	if ar.Start != 1 || ar.Secondary != 4 || ar.Origin.Y != 8 {
		t.Fatalf("%+v", ar)
	}

	// Text3d: u32, u16×2, f64×4, quat, pt3d, u16 N, bytes[Length]
	tx := parse3d(17, join(u32s(1), []byte{2, 0, 2, 0},
		f64le(1, 2, 3, 4), f64le(1, 0, 0, 0), f64le(5, 6, 7),
		[]byte{2, 0}, []byte{'h', 'i'}, []byte{1, 2, 3, 4, 5, 6})).(*element.Text3d)
	if tx.Length != 2 || tx.N != 2 || string(tx.Value) != "hi" || tx.D[3] != 4 ||
		len(tx.CharAttrs) != 6 || tx.CharAttrs[5] != 6 {
		t.Fatalf("%+v", tx)
	}

	// PointString3d: count, flags, count×Pt3d, count×quat
	ps3 := parse3d(22, join(u32s(2, 0), f64le(1, 2, 3, 4, 5, 6),
		f64le(1, 0, 0, 0, 0.5, 0.5, 0.5, 0.5))).(*element.PointString3d)
	if len(ps3.Points) != 2 || ps3.Rotations[1].W != 0.5 || ps3.Points[0].Z != 3 {
		t.Fatalf("%+v", ps3)
	}
}

// TestGroupNoneRoutes exercises every remaining GroupNone/GroupSub route
// registration through ParseAll so a mis-bound pn/ps target fails loudly.
func TestGroupNoneRoutes(t *testing.T) {
	parseNone := func(typ uint16, body []byte) any {
		t.Helper()
		hdr := buildHeader(Header{Type: typ, B: 200, C: 200, ID: 30})
		got, err := ParseAll(join(hdr, body), Dir{Base: 0, Offsets: []uint32{0}})
		if err != nil {
			t.Fatal(err)
		}
		return got[0].Body.(*Body).Value
	}

	// ComplexElement(12/14): u32
	if c, ok := parseNone(12, u32s(5)).(*element.ComplexElement); !ok || c.A != 5 {
		t.Fatalf("type12 %T %+v", c, c)
	}
	if _, ok := parseNone(14, u32s(6)).(*element.ComplexElement); !ok {
		t.Fatal("type14 route")
	}

	// Surface(18)/Solid(19): u32+u16×4
	sb := join(u32s(9), []byte{1, 0, 2, 0, 3, 0, 4, 0})
	if s, ok := parseNone(18, sb).(*element.Solid); !ok || s.Flags != 9 || s.U[3] != 4 {
		t.Fatalf("type18 %T %+v", s, s)
	}
	if _, ok := parseNone(19, sb).(*element.Solid); !ok {
		t.Fatal("type19 route")
	}

	// Cone(23): u16×4+quat+Pt3d+f64+Pt3d+f64
	cb := join([]byte{1, 0, 2, 0, 3, 0, 4, 0},
		f64le(1, 0, 0, 0), f64le(1, 2, 3), f64le(4.5),
		f64le(4, 5, 6), f64le(7.5))
	if c, ok := parseNone(23, cb).(*element.Cone); !ok || c.H[3] != 4 || c.R1 != 4.5 || c.P2.Z != 6 {
		t.Fatalf("type23 %T %+v", c, c)
	}

	// BSplineSurface(24): 9×u32
	surf := make([]byte, 36)
	binary.LittleEndian.PutUint32(surf[4:], 77)
	if s, ok := parseNone(24, surf).(*element.BSplineSurface); !ok || s.F[1] != 77 {
		t.Fatalf("type24 %T %+v", s, s)
	}

	// BSplineBoundary(25): u32×2 + count×Pt2d
	bb := join(u32s(3, 1), f64le(1, 2))
	if x, ok := parseNone(25, bb).(*element.BSplineBoundary); !ok || x.A != 3 || x.Pts[0].Y != 2 {
		t.Fatalf("type25 %T %+v", x, x)
	}

	// BSplineArray knots(26)/weights(28): rest f64
	if a, ok := parseNone(26, f64le(1.5, 2.5)).(*element.BSplineArray); !ok || a.Values[1] != 2.5 {
		t.Fatalf("type26 %T %+v", a, a)
	}
	if _, ok := parseNone(28, f64le(1)).(*element.BSplineArray); !ok {
		t.Fatal("type28 route")
	}

	// Multiline(36): prefix-only body (152B, all counts zero).
	// reader order: f64,f64,u32@16,u16@20,u8×4@22,u16@26,i8×4@28,f64@32,
	// i64@40,f64@48,u32×18@56,f64×3@128
	mb := make([]byte, 152)
	binary.LittleEndian.PutUint32(mb[16:], 42)
	if m, ok := parseNone(36, mb).(*element.MultiLine); !ok || m.A != 42 {
		t.Fatalf("type36 %T %+v", m, m)
	}

	// TableEntry(95): rest blob
	if te, ok := parseNone(95, []byte{1, 2, 3}).(*element.TableEntry); !ok || len(te.Raw) != 3 {
		t.Fatalf("type95 %T %+v", te, te)
	}
}

// TestType96TableVariantRoutes covers (96,1) LevelHeader, (96,6) MLStyle and
// an unmapped subtype falling to the blob wildcard.
func TestType96TableVariantRoutes(t *testing.T) {
	parse96 := func(sub uint32, body []byte) any {
		t.Helper()
		hdr := buildHeader(Header{Type: 96, Sub: sub, B: 50, C: 50, ID: 31})
		got, err := ParseAll(join(hdr, body), Dir{Base: 0, Offsets: []uint32{0}})
		if err != nil {
			t.Fatal(err)
		}
		return got[0].Body.(*Body).Value
	}
	flags := make([]byte, 8)
	binary.LittleEndian.PutUint64(flags, 0x1122334455667788)
	lb := join([]byte{7, 0, 8, 0}, flags, f64le(1.5, 2.5))
	if h, ok := parse96(1, lb).(*element.TableLevelHeader); !ok || h.A != 7 || h.D2 != 2.5 {
		t.Fatalf("(96,1) %T %+v", h, h)
	}
	if h, ok := parse96(6, []byte{9, 0, 1, 0, 2, 0, 3, 0, 4, 0, 5, 0}).(*element.TableMLStyleHeader); !ok ||
		h.A != 9 || h.Reserved[4] != 5 {
		t.Fatalf("(96,6) %T %+v", h, h)
	}
	if b, ok := parse96(2, []byte{1, 2}).(*element.TableBlob); !ok || len(b.Raw) != 2 {
		t.Fatalf("(96,2) %T %+v", b, b)
	}
}

// TestCellHeaderRoutes covers the Group2D3D cell-header pair (type 2).
func TestCellHeaderRoutes(t *testing.T) {
	// 2D: u16×2 + Pt2d×2 + 4×f64 + Pt2d
	b2 := join([]byte{1, 0, 2, 0},
		f64le(1, 2, 3, 4), f64le(0.25, 0.5, 0.75, 1), f64le(5, 6))
	h2 := buildHeader(Header{Type: 2, B: 40, C: 40, ID: 32})
	got2, err := ParseAll(join(h2, b2), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if c, ok := got2[0].Body.(*Body).Value.(*element.CellHeader2d); !ok || c.H[0] != 1 || c.M[3] != 1 || c.P3.Y != 6 {
		t.Fatalf("cell2d %T %+v", c, c)
	}

	// 3D via display-header flag: u16×2 + Pt3d×2 + 9×f64 + Pt3d
	b3 := join([]byte{1, 0, 2, 0},
		f64le(1, 2, 3, 4, 5, 6), f64le(make([]float64, 9)...), f64le(7, 8, 9))
	h3 := buildHeader(Header{Type: 2, Flag: FlagDisplayHeader, B: 74, C: 74, ID: 33})
	disp := make([]byte, DisplayHeaderSize)
	binary.LittleEndian.PutUint16(disp[8:], 1<<11)
	got3, err := ParseAll(join(h3, disp, b3), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if c, ok := got3[0].Body.(*Body).Value.(*element.CellHeader3d); !ok || c.P2.Z != 6 || c.P3.Z != 9 {
		t.Fatalf("cell3d %T %+v", c, c)
	}
}
