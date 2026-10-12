package linkage

import (
	"encoding/binary"
	"math"
	"testing"
)

func u32le(v uint32) []byte {
	b := make([]byte, 4)
	binary.LittleEndian.PutUint32(b, v)
	return b
}

func u64le(v uint64) []byte {
	b := make([]byte, 8)
	binary.LittleEndian.PutUint64(b, v)
	return b
}

func f64le(v float64) []byte {
	b := make([]byte, 8)
	binary.LittleEndian.PutUint64(b, math.Float64bits(v))
	return b
}

func join(parts ...[]byte) []byte {
	var out []byte
	for _, p := range parts {
		out = append(out, p...)
	}
	return out
}

func TestDecodeSeedPoints(t *testing.T) {
	raw := join(u32le(0x1234), u32le(2),
		f64le(1.5), f64le(-2), f64le(3),
		f64le(4), f64le(5), f64le(6))
	p, err := DecodePayload(Rec{TypeID: 0x56da, Raw: raw})
	if err != nil || p == nil {
		t.Fatalf("%v %v", p, err)
	}
	sp := p.(*SeedPoints)
	if sp.Header != 0x1234 || sp.Count != 2 || len(sp.Points) != 2 ||
		sp.Points[0][0] != 1.5 || sp.Points[1][2] != 6 {
		t.Fatalf("%+v", sp)
	}
	// degenerate double (exp=0) → 0
	deg := join(u32le(0), u32le(1), make([]byte, 24))
	p, _ = DecodePayload(Rec{TypeID: 0x56da, Raw: deg})
	if p.(*SeedPoints).Points[0] != [3]float64{} {
		t.Fatalf("degenerate not zeroed: %+v", p)
	}
	// truncated count keeps partial points (handler semantics)
	p, _ = DecodePayload(Rec{TypeID: 0x56da, Raw: join(u32le(0), u32le(3), f64le(9))})
	if got := len(p.(*SeedPoints).Points); got != 0 {
		t.Fatalf("truncated points=%d", got)
	}
}

func TestDecodeThickness(t *testing.T) {
	// scalar form (< 0x20)
	raw := join(u32le(1), u32le(0), f64le(2.5))
	p, err := DecodePayload(Rec{TypeID: 0x56d4, Raw: raw})
	if err != nil || p == nil {
		t.Fatal(err)
	}
	th := p.(*Thickness)
	if th.IsVec || !th.HasData || th.Vector[0] != 2.5 {
		t.Fatalf("%+v", th)
	}
	// vector form (>= 0x20)
	rawv := join(u32le(2), u32le(0), f64le(3), f64le(4), f64le(0))
	p, _ = DecodePayload(Rec{TypeID: 0x56d4, Raw: rawv})
	th = p.(*Thickness)
	if !th.IsVec || th.Vector[1] != 4 {
		t.Fatalf("%+v", th)
	}
}

func TestDecodeSimplePairs(t *testing.T) {
	p, _ := DecodePayload(Rec{TypeID: 0x56e9, Raw: join(u32le(7), u32le(9))})
	if x := p.(*InfiniteLine); x.Header != 7 || x.Value != 9 {
		t.Fatalf("%+v", x)
	}
	p, _ = DecodePayload(Rec{TypeID: 0x56ea, Raw: join(u32le(1), u32le(0xABCD))})
	if x := p.(*SharedCellFlags); x.Flags != 0xABCD {
		t.Fatalf("%+v", x)
	}
}

func TestDecodeSheetScale(t *testing.T) {
	raw := join(u32le(5), f64le(1), f64le(2), f64le(3), f64le(4), f64le(5))
	p, err := DecodePayload(Rec{TypeID: 0x56ee, Raw: raw})
	if err != nil {
		t.Fatal(err)
	}
	if s := p.(*SheetAnnotationScale); s.Values[4] != 5 {
		t.Fatalf("%+v", s)
	}
}

func TestDecodeDoubleArray(t *testing.T) {
	raw := join(u32le(1), u32le(2), u32le(2), f64le(1.25), f64le(2.5))
	p, err := DecodePayload(Rec{TypeID: 0x56d5, Raw: raw})
	if err != nil {
		t.Fatal(err)
	}
	d := p.(*DoubleArray)
	if d.Value != 2 || d.Count != 2 || d.Values[1] != 2.5 {
		t.Fatalf("%+v", d)
	}
}

func TestDecodeString(t *testing.T) {
	raw := join(u32le(1), u32le(42), u32le(3), []byte("abc"))
	p, err := DecodePayload(Rec{TypeID: 0x56d2, Raw: raw})
	if err != nil {
		t.Fatal(err)
	}
	s := p.(*String)
	if s.ID != 42 || s.Len != 3 || string(s.Data) != "abc" {
		t.Fatalf("%+v", s)
	}
}

func TestDecodeByteArray(t *testing.T) {
	raw := join(u32le(3), []byte{0xDE, 0xAD, 0xBE})
	p, err := DecodePayload(Rec{TypeID: 0x5751, Raw: raw})
	if err != nil {
		t.Fatal(err)
	}
	b := p.(*ByteArray)
	if b.Count != 3 || len(b.Data) != 3 || b.Data[0] != 0xDE {
		t.Fatalf("%+v", b)
	}
}

func TestDecodeAssocRegion(t *testing.T) {
	p, _ := DecodePayload(Rec{TypeID: 0x56d8, Raw: join(u32le(1), u32le(2))})
	a := p.(*AssocRegion)
	if a.HasDouble {
		t.Fatalf("%+v", a)
	}
	p, _ = DecodePayload(Rec{TypeID: 0x56d8, Raw: join(u32le(1), u32le(2), f64le(8))})
	a = p.(*AssocRegion)
	if !a.HasDouble || a.Double != 8 {
		t.Fatalf("%+v", a)
	}
}

func TestDecodeFillStyle(t *testing.T) {
	// DisplayStyle: subType 0x10
	p, _ := DecodePayload(Rec{TypeID: 0x41, Raw: join(u32le(1), []byte{0x10, 0})})
	if f := p.(*FillStyle); f.Kind != FillDisplayStyle {
		t.Fatalf("%+v", f)
	}
	// FillColor: subType 8, inner != 1, color u32
	p, _ = DecodePayload(Rec{TypeID: 0x41, Raw: join(u32le(1), []byte{8, 0, 2, 0}, u32le(0x336699))})
	f := p.(*FillStyle)
	if f.Kind != FillColorVal || f.Color != 0x336699 {
		t.Fatalf("%+v", f)
	}
	// Gradient: subType 8, inner 1
	p, _ = DecodePayload(Rec{TypeID: 0x41, Raw: join(u32le(1), []byte{8, 0, 1, 0})})
	if f = p.(*FillStyle); f.Kind != FillGradient {
		t.Fatalf("%+v", f)
	}
	// InternalMaterial: subType 0xd
	p, _ = DecodePayload(Rec{TypeID: 0x41, Raw: join(u32le(1), []byte{0xd, 0, 0, 0}, u32le(0), u32le(7))})
	f = p.(*FillStyle)
	if f.Kind != FillInternalMaterial || f.Index != 1 || f.ID != 7<<32 {
		t.Fatalf("%+v", f)
	}
	// Transparency: subType 9
	p, _ = DecodePayload(Rec{TypeID: 0x41, Raw: join(u32le(1), []byte{9, 0, 0, 0}, u32le(128))})
	if f = p.(*FillStyle); f.Kind != FillTransparency || f.Color != 128 {
		t.Fatalf("%+v", f)
	}
	// unknown subType → nil (handler returns null)
	p, _ = DecodePayload(Rec{TypeID: 0x41, Raw: join(u32le(1), []byte{0x77, 0})})
	if p != nil {
		t.Fatalf("unknown subtype not nil: %T", p)
	}
}

func TestDecodeNote(t *testing.T) {
	raw := make([]byte, 32)
	binary.LittleEndian.PutUint32(raw[8:], 'N'|'o'<<8|'t'<<16|'e'<<24)
	p, _ := DecodePayload(Rec{TypeID: 0x562e, Raw: raw})
	n := p.(*Note)
	if !n.IsNote {
		t.Fatalf("%+v", n)
	}
	// wrong size → nil
	p, _ = DecodePayload(Rec{TypeID: 0x562e, Raw: make([]byte, 16)})
	if p != nil {
		t.Fatalf("short note not nil")
	}
}

func TestDecodePayloadUnknownStaysRaw(t *testing.T) {
	p, err := DecodePayload(Rec{TypeID: 0x1234, Raw: []byte{1, 2}})
	if p != nil || err != nil {
		t.Fatalf("%v %v", p, err)
	}
}

func TestF64dDegenerate(t *testing.T) {
	// +0, -0, +Inf, NaN → 0
	for _, u := range []uint64{0, 0x8000000000000000, 0x7ff0000000000000, 0x7ff8000000000001} {
		if v := f64d([]byte{
			byte(u), byte(u >> 8), byte(u >> 16), byte(u >> 24),
			byte(u >> 32), byte(u >> 40), byte(u >> 48), byte(u >> 56),
		}); v != 0 {
			t.Fatalf("u=%x got %g", u, v)
		}
	}
	if f64d(f64le(1.0)) != 1.0 {
		t.Fatal("1.0 mangled")
	}
}

func TestHandlerIDsCoverKnownNames(t *testing.T) {
	seen := map[uint16]bool{}
	for _, id := range HandlerIDs {
		seen[id] = true
	}
	// every ID with a traced decoder must appear in the handler table
	for id := range decoders {
		if !seen[id] {
			t.Errorf("decoder 0x%x missing from HandlerIDs", id)
		}
	}
}

func TestDecodeDBLinkageFamily(t *testing.T) {
	raw := join(u32le(1), []byte{4, 0}, []byte{2, 0}, u32le(77), u32le(88))
	for _, id := range []uint16{0x0020, 0x3948, 0x3a77, 0x4f58, 0x5e62, 0x5800, 0x6091, 0x71fb, 0x1971, 0x0f81} {
		p, err := DecodePayload(Rec{TypeID: id, Raw: raw})
		if err != nil || p == nil {
			t.Fatalf("id=0x%x %v %v", id, p, err)
		}
		d := p.(*DBLinkage)
		if d.Word != 4 || d.SubType != 2 || d.ID != 77 || d.Extra != 88 {
			t.Fatalf("id=0x%x %+v", id, d)
		}
	}
	// kind mapping spot checks
	p, _ := DecodePayload(Rec{TypeID: 0x3948, Raw: raw})
	if k := p.(*DBLinkage).Kind; k != DBInformix {
		t.Fatalf("kind=%d", k)
	}
	p, _ = DecodePayload(Rec{TypeID: 0x6091, Raw: raw})
	if k := p.(*DBLinkage).Kind; k != DBOracle {
		t.Fatalf("kind=%d", k)
	}
}

func TestDecodeBitMask(t *testing.T) {
	p, _ := DecodePayload(Rec{TypeID: 0x56d3, Raw: join(u32le(1), []byte{6}, []byte{9})})
	bm := p.(*BitMask)
	if !bm.IsWhiteSpace || len(bm.Rest) != 1 {
		t.Fatalf("%+v", bm)
	}
	p, _ = DecodePayload(Rec{TypeID: 0x56d3, Raw: join(u32le(1), []byte{0}, []byte{9})})
	if p.(*BitMask).IsWhiteSpace {
		t.Fatal("expected bitmask")
	}
}

func TestDecodeDependency(t *testing.T) {
	// rootDataType=(word3>>10)&0xf; word3=0x0400 → 1 (kElementId_V,
	// roots stay raw)
	raw := join(u32le(5), []byte{1, 0}, []byte{2, 0}, []byte{0x00, 0x04}, []byte{0xAA})
	p, err := DecodePayload(Rec{TypeID: 0x56d0, Raw: raw})
	if err != nil {
		t.Fatal(err)
	}
	d := p.(*Dependency)
	if d.Header != 5 || d.AppID != 1 || d.AppValue != 2 || d.RootDataType != 1 || len(d.Rest) != 1 {
		t.Fatalf("%+v", d)
	}

	// kElementId roots (D112): the shared-cell definition reference —
	// AppID 0x2716, one u64 element handle
	raw = join(u32le(9), []byte{0x16, 0x27}, []byte{0, 0}, []byte{0, 0},
		[]byte{1, 0}, u64le(0x64))
	p, err = DecodePayload(Rec{TypeID: 0x56d0, Raw: raw})
	if err != nil {
		t.Fatal(err)
	}
	d = p.(*Dependency)
	if d.AppID != 0x2716 || d.RootDataType != 0 || d.RootCount != 1 ||
		len(d.Roots) != 1 || d.Roots[0] != 0x64 {
		t.Fatalf("%+v", d)
	}
}

func TestHandlerTableExact39(t *testing.T) {
	if len(HandlerIDs) != 39 {
		t.Fatalf("HandlerIDs=%d want 39", len(HandlerIDs))
	}
	if len(HandlerNames) != 39 {
		t.Fatalf("HandlerNames=%d want 39", len(HandlerNames))
	}
	for _, id := range HandlerIDs {
		if _, ok := HandlerNames[id]; !ok {
			t.Errorf("id 0x%x missing name", id)
		}
	}
}

func TestDecodeTextAnnotation(t *testing.T) {
	raw := join(u32le(1), u32le(2), f64le(3), f64le(4))
	p, err := DecodePayload(Rec{TypeID: 0x56f3, Raw: raw})
	if err != nil {
		t.Fatal(err)
	}
	x := p.(*TextAnnotation)
	if x.Header != 1 || x.Value != 2 || x.D[0] != 3 || x.D[1] != 4 {
		t.Fatalf("%+v", x)
	}
}

func TestDecodeRefAttachPath(t *testing.T) {
	raw := join(u32le(1), u32le(2), u32le(3), u32le(2), f64le(1.5), f64le(2.5))
	p, err := DecodePayload(Rec{TypeID: 0x56f1, Raw: raw})
	if err != nil {
		t.Fatal(err)
	}
	r := p.(*RefAttachPath)
	if r.Count != 2 || r.Values[1] != 2.5 {
		t.Fatalf("%+v", r)
	}
}

func TestDecodeSheetModelExtension(t *testing.T) {
	raw := join(u32le(9), u32le(1), u32le(2), u32le(3), u32le(4), u32le(5))
	p, err := DecodePayload(Rec{TypeID: 0x5701, Raw: raw})
	if err != nil {
		t.Fatal(err)
	}
	x := p.(*SheetModelExtension)
	if x.Header != 9 || x.Fields[4] != 5 {
		t.Fatalf("%+v", x)
	}
}

func TestDecodeXML(t *testing.T) {
	raw := join(u32le(1), make([]byte, 24), u32le(3), []byte("abc"), u32le(2), []byte("de"))
	p, err := DecodePayload(Rec{TypeID: 0x56e3, Raw: raw})
	if err != nil {
		t.Fatal(err)
	}
	x := p.(*XML)
	if len(x.Parts) != 2 || string(x.Parts[0]) != "abc" || string(x.Parts[1]) != "de" {
		t.Fatalf("%+v", x)
	}
}

func TestDecodeFilterMember(t *testing.T) {
	raw := join(u32le(1), u32le(2), []byte{3, 0, 4, 0}, u32le(2), u32le(1), u32le(5), []byte("hi"), []byte("x"))
	p, err := DecodePayload(Rec{TypeID: 0x56dd, Raw: raw})
	if err != nil {
		t.Fatal(err)
	}
	f := p.(*FilterMember)
	if f.A != 3 || f.B != 4 || f.Y != 5 || string(f.Str1) != "hi" || string(f.Str2) != "x" {
		t.Fatalf("%+v", f)
	}
}

func TestDecodeBoundaryClip(t *testing.T) {
	parts := [][]byte{u32le(1)}
	for i := 0; i < 14; i++ {
		parts = append(parts, f64le(float64(i)))
	}
	parts = append(parts, u32le(7), u32le(1), f64le(8), f64le(9))
	p, err := DecodePayload(Rec{TypeID: 0x56dc, Raw: join(parts...)})
	if err != nil {
		t.Fatal(err)
	}
	b := p.(*BoundaryClip)
	if b.V[13] != 13 || b.W != 7 || b.Count != 1 || b.Pairs[0][1] != 9 {
		t.Fatalf("%+v", b)
	}
}

func TestDecodeLineStyleMod(t *testing.T) {
	// flags bits 0 and 2 set → 2 f64s; no dash section
	raw := join(u32le(1), u32le(0b101), f64le(1), f64le(2))
	p, err := DecodePayload(Rec{TypeID: 0x79f9, Raw: raw})
	if err != nil {
		t.Fatal(err)
	}
	l := p.(*LineStyleModification)
	if len(l.D) != 2 || l.D[1] != 2 || len(l.Dashes) != 0 {
		t.Fatalf("%+v", l)
	}
	// flags bits0 + 0x1800 → 1 f64 + count2 dashes
	raw = join(u32le(1), u32le(0x1801), f64le(3), u32le(2), u32le(10), u32le(20))
	p, _ = DecodePayload(Rec{TypeID: 0x79f9, Raw: raw})
	l = p.(*LineStyleModification)
	if len(l.D) != 1 || len(l.Dashes) != 2 || l.Dashes[1] != 20 {
		t.Fatalf("%+v", l)
	}
}

func TestDecodeSheetModel(t *testing.T) {
	parts := [][]byte{u32le(1), u32le(2), u32le(3)}
	for i := 0; i < 5; i++ {
		parts = append(parts, f64le(float64(i+1)))
	}
	parts = append(parts, u32le(4), u32le(5), []byte{0xAA})
	p, err := DecodePayload(Rec{TypeID: 0x56ed, Raw: join(parts...)})
	if err != nil {
		t.Fatal(err)
	}
	s := p.(*SheetModel)
	if s.A != 2 || s.B != 3 || s.V[4] != 5 || s.C != 4 || s.D != 5 || len(s.Rest) != 1 {
		t.Fatalf("%+v", s)
	}
}

func TestDecodeOleAndIndent(t *testing.T) {
	parts := [][]byte{u32le(1)}
	for i := 0; i < 7; i++ {
		parts = append(parts, u32le(uint32(i)))
	}
	parts = append(parts, []byte{1, 2})
	p, _ := DecodePayload(Rec{TypeID: 0xb01e, Raw: join(parts...)})
	o := p.(*Ole)
	if o.Fields[6] != 6 || len(o.Rest) != 2 {
		t.Fatalf("%+v", o)
	}

	parts = [][]byte{u32le(1), u32le(2), f64le(3), f64le(4), u32le(5), u32le(6), []byte{9}}
	p, _ = DecodePayload(Rec{TypeID: 0x5810, Raw: join(parts...)})
	ti := p.(*TextIndentation)
	if ti.A != 2 || ti.D[1] != 4 || ti.B != 5 || ti.C != 6 || len(ti.Rest) != 1 {
		t.Fatalf("%+v", ti)
	}
}

func TestDecodeDimTextStyleAndMaterial(t *testing.T) {
	raw := join(u32le(1), u32le(2), u32le(0xFF), u32le(3), []byte{0xAB})
	p, _ := DecodePayload(Rec{TypeID: 0x5801, Raw: raw})
	d := p.(*DimTextStyle)
	if d.X != 2 || d.Flags != 0xFF || d.Y != 3 || len(d.Rest) != 1 {
		t.Fatalf("%+v", d)
	}
	p, _ = DecodePayload(Rec{TypeID: 0x4f5a, Raw: join(u32le(1), []byte{2, 3})})
	m := p.(*Material)
	if len(m.Rest) != 2 {
		t.Fatalf("%+v", m)
	}
}

// TestDecodersCoverHandlerTable: every handler ID either has a decoder or
// is explicitly listed as raw-pending (D90).
func TestDecodersCoverHandlerTable(t *testing.T) {
	rawPending := map[uint16]bool{
		0x0000: true,  // DMRS: seek-rewind stream, kept raw
		0x0041: false, // has decoder (family)
		0x522e: false, // has decoder (Brep, D111)
		0x56d8: false,
		0x56de: true, // Dimension: 750-line specialized handler
		0x7d28: true, // Hatch: geometry-heavy handler
	}
	for _, id := range HandlerIDs {
		_, hasDec := decoders[id]
		if !hasDec && !rawPending[id] {
			t.Errorf("handler 0x%x has neither decoder nor raw-pending entry", id)
		}
	}
}

// TestDecodeBrep pins the 0x522E OdDgBrepLinkage payload (D111,
// CDGAttribEmbeddedBRep read/write double-proven): headerValue, two flag
// words, scale, native kernel BRep bytes.
func TestDecodeBrep(t *testing.T) {
	w16 := func(v uint16) []byte {
		b := make([]byte, 2)
		binary.LittleEndian.PutUint16(b, v)
		return b
	}
	// handler buffer: [u16 bits][u16 id][f1][f2][scale][data]
	raw := join(w16(0x1000|7), w16(0x522e), w16(7), w16(9),
		f64le(0.5), []byte{0xAA, 0xBB, 0xCC, 0xDD, 0xEE})
	p, err := DecodePayload(Rec{TypeID: 0x522e, Raw: raw})
	if err != nil {
		t.Fatal(err)
	}
	b := p.(*Brep)
	if b.Header != 0x522e_1007 || b.Flag1 != 7 || b.Flag2 != 9 || b.Scale != 0.5 {
		t.Fatalf("%+v", b)
	}
	if len(b.Data) != 5 || b.Data[0] != 0xAA {
		t.Fatalf("data = %v", b.Data)
	}

	if _, err := DecodePayload(Rec{TypeID: 0x522e, Raw: raw[:12]}); err == nil {
		t.Fatal("short payload accepted")
	}
}
