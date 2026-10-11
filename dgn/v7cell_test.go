package dgn

import (
	"encoding/binary"
	"math"
	"testing"
)

func TestV7Rad50(t *testing.T) {
	cases := []struct {
		w    uint16
		want string
	}{
		{1683, "ABC"},                 // 1*1600+2*40+3
		{49151, "0.1"},                // 30*1600+28*40+31
		{0, "   "},                    // three spaces
		{39*1600 + 39*40 + 39, "999"}, // 9*  = digits
		{27 * 1600, "$  "},            // '$'
	}
	for _, c := range cases {
		if got := V7Rad50(c.w); got != c.want {
			t.Errorf("rad50(%d)=%q want %q", c.w, got, c.want)
		}
	}
}

func TestReadV7CellHeader2D(t *testing.T) {
	body := make([]byte, 88)
	binary.LittleEndian.PutUint16(body[32:], 53765)
	binary.LittleEndian.PutUint16(body[34:], 28858) // "RAR"
	binary.LittleEndian.PutUint16(body[36:], 28865) // "RAY"
	binary.LittleEndian.PutUint16(body[38:], 5)
	binary.LittleEndian.PutUint16(body[40:], 1)
	// range
	V7PutInt32(body[48:], -100)
	V7PutInt32(body[52:], -200)
	V7PutInt32(body[56:], 100)
	V7PutInt32(body[60:], 200)
	// matrix: a=0 b=1 c=429496 d=0 → xscale=2, rotation=270 (b>0 flips)
	V7PutInt32(body[64:], 0)
	V7PutInt32(body[68:], 1)
	V7PutInt32(body[72:], 429496)
	V7PutInt32(body[76:], 0)
	V7PutInt32(body[80:], 12345)
	V7PutInt32(body[84:], -6789)
	c, err := ReadV7CellHeader(V7Element{Type: 2, Words: 44, Body: body}, false)
	if err != nil {
		t.Fatal(err)
	}
	if c.Name != "RARRAY" || c.TotLength != 53765 || c.Class != 5 || c.Levels[0] != 1 {
		t.Fatalf("%+v", c)
	}
	if c.RangeLow != (V7Point{X: -100, Y: -200}) || c.RangeHigh != (V7Point{X: 100, Y: 200}) {
		t.Fatalf("range %+v %+v", c.RangeLow, c.RangeHigh)
	}
	if c.Origin != (V7Point{X: 12345, Y: -6789}) {
		t.Fatalf("origin %+v", c.Origin)
	}
	if c.XScale != 2.0 {
		t.Fatalf("xscale=%v", c.XScale)
	}
	if want := 1.0 / 214748; c.YScale != want {
		t.Fatalf("yscale=%v want %v", c.YScale, want)
	}
	if math.Abs(c.Rotation-270) > 1e-9 {
		t.Fatalf("rotation=%v", c.Rotation)
	}
	// b<=0 → no flip → 90°
	V7PutInt32(body[68:], -1)
	c2, err := ReadV7CellHeader(V7Element{Type: 2, Words: 44, Body: body}, false)
	if err != nil {
		t.Fatal(err)
	}
	if math.Abs(c2.Rotation-90) > 1e-9 {
		t.Fatalf("rotation=%v", c2.Rotation)
	}
	if _, err := ReadV7CellHeader(V7Element{Type: 2, Body: make([]byte, 40)}, false); err == nil {
		t.Fatal("short body must fail")
	}
}

func TestReadV7CellHeader3D(t *testing.T) {
	body := make([]byte, 120)
	binary.LittleEndian.PutUint16(body[34:], 28858)
	binary.LittleEndian.PutUint16(body[36:], 28865)
	V7PutInt32(body[48:], 1)
	V7PutInt32(body[52:], 2)
	V7PutInt32(body[56:], 3)
	V7PutInt32(body[60:], 4)
	V7PutInt32(body[64:], 5)
	V7PutInt32(body[68:], 6)
	V7PutInt32(body[72:], 1<<30) // trans[0] = 0.5
	V7PutInt32(body[108:], 7)
	V7PutInt32(body[112:], 8)
	V7PutInt32(body[116:], 9)
	c, err := ReadV7CellHeader(V7Element{Type: 2, Words: 60, Body: body}, true)
	if err != nil {
		t.Fatal(err)
	}
	if c.RangeLow != (V7Point{X: 1, Y: 2, Z: 3}) || c.RangeHigh != (V7Point{X: 4, Y: 5, Z: 6}) {
		t.Fatalf("%+v %+v", c.RangeLow, c.RangeHigh)
	}
	if c.Trans[0] != 0.5 || c.Origin != (V7Point{X: 7, Y: 8, Z: 9}) {
		t.Fatalf("trans0=%v origin=%+v", c.Trans[0], c.Origin)
	}
	if c.XScale != 0 || c.Rotation != 0 {
		t.Fatalf("3D must not derive 2D scales: %+v", c)
	}
}

func TestReadV7CellLibrary(t *testing.T) {
	body := make([]byte, 66)
	binary.LittleEndian.PutUint16(body[28:], 1680) // "AB "
	binary.LittleEndian.PutUint16(body[30:], 0)
	binary.LittleEndian.PutUint16(body[32:], 123) // numwords
	binary.LittleEndian.PutUint16(body[34:], 0x0800)
	binary.LittleEndian.PutUint16(body[36:], 7)
	binary.LittleEndian.PutUint16(body[38:], 3)
	binary.LittleEndian.PutUint16(body[40:], 9)
	binary.LittleEndian.PutUint16(body[48:], 1680) // desc word0 = "AB "
	for i := 1; i < 9; i++ {
		binary.LittleEndian.PutUint16(body[48+i*2:], 0)
	}
	lib, err := ReadV7CellLibrary(V7Element{Level: 1, Type: 1, Words: 33, Body: body})
	if err != nil {
		t.Fatal(err)
	}
	if lib.Name != "AB    " || lib.NumWords != 123 || lib.Properties != 0x0800 ||
		lib.DisplaySym != 7 || lib.Class != 3 || lib.Levels[0] != 9 {
		t.Fatalf("%+v", lib)
	}
	if len(lib.Description) != 27 {
		t.Fatalf("desc len=%d", len(lib.Description))
	}
	wantDesc := "AB "
	for i := 0; i < 8; i++ {
		wantDesc += "   "
	}
	if lib.Description != wantDesc {
		t.Fatalf("desc=%q want %q", lib.Description, wantDesc)
	}
	if _, err := ReadV7CellLibrary(V7Element{Type: 3, Body: body}); err == nil {
		t.Fatal("wrong type must fail")
	}
}

func TestReadV7BSplineHeaders(t *testing.T) {
	body := make([]byte, 42)
	V7PutInt32(body[32:], -12345)
	body[36] = 0x20 | 0x02 // props=0x20, order=4
	body[37] = 5
	binary.LittleEndian.PutUint16(body[38:], 7)
	binary.LittleEndian.PutUint16(body[40:], 9)
	h, err := ReadV7BSplineCurveHeader(V7Element{Type: 27, Words: 21, Body: body})
	if err != nil {
		t.Fatal(err)
	}
	if h.DescWords != -12345 || h.Order != 4 || h.Properties != 0x20 || h.CurveType != 5 ||
		h.NumPoles != 7 || h.NumKnots != 9 {
		t.Fatalf("%+v", h)
	}
	if _, err := ReadV7BSplineCurveHeader(V7Element{Type: 24, Body: body}); err == nil {
		t.Fatal("wrong type must fail")
	}

	sb := make([]byte, 54)
	V7PutInt32(sb[32:], 777)
	sb[36] = 0x10 | 0x03 // u props 0x10, u order 5
	sb[37] = 2
	binary.LittleEndian.PutUint16(sb[38:], 11)
	binary.LittleEndian.PutUint16(sb[40:], 13)
	binary.LittleEndian.PutUint16(sb[42:], 1)
	sb[44] = 0x20 | 0x04 // v props 0x20, v order 6
	binary.LittleEndian.PutUint16(sb[46:], 17)
	binary.LittleEndian.PutUint16(sb[48:], 19)
	binary.LittleEndian.PutUint16(sb[50:], 2)
	binary.LittleEndian.PutUint16(sb[52:], 300) // proper u16 (GDAL ×556 typo not replicated)
	sh, err := ReadV7BSplineSurfaceHeader(V7Element{Type: 24, Words: 27, Body: sb})
	if err != nil {
		t.Fatal(err)
	}
	if sh.DescWords != 777 || sh.UOrder != 5 || sh.VOrder != 6 || sh.UProperties != 0x10 ||
		sh.VProperties != 0x20 || sh.CurveType != 2 || sh.NumPolesU != 11 || sh.NumKnotsU != 13 ||
		sh.RuleLinesU != 1 || sh.NumPolesV != 17 || sh.NumKnotsV != 19 || sh.RuleLinesV != 2 ||
		sh.NumBounds != 300 {
		t.Fatalf("%+v", sh)
	}
}

func TestReadV7KnotWeights(t *testing.T) {
	// no attribute flag: whole tail is values
	body := make([]byte, 32+12)
	V7PutInt32(body[32:], 0)
	V7PutInt32(body[36:], 1<<30)
	V7PutInt32(body[40:], -(1 << 30))
	v, err := ReadV7KnotWeights(V7Element{Type: 26, Words: 22, Body: body})
	if err != nil {
		t.Fatal(err)
	}
	if len(v) != 3 || v[0] != 0 {
		t.Fatalf("%v", v)
	}
	if want := float64(1<<30) / (float64(1<<31) - 1); v[1] != want {
		t.Fatalf("v1=%v want %v", v[1], want)
	}

	// attribute flag: values stop before the attr region (idx=8 → attr@44)
	body2 := make([]byte, 52)
	binary.LittleEndian.PutUint16(body2[26:], 8)      // attrIndex
	binary.LittleEndian.PutUint16(body2[28:], 0x0800) // properties
	V7PutInt32(body2[32:], 0)
	V7PutInt32(body2[36:], 1<<30)
	V7PutInt32(body2[40:], -(1 << 30))
	body2[44] = 0xA9
	body2[45] = 0x51
	v2, err := ReadV7KnotWeights(V7Element{Type: 28, Words: 26, Body: body2})
	if err != nil {
		t.Fatal(err)
	}
	if len(v2) != 3 || v2[2] != v[2] {
		t.Fatalf("attr case: %v", v2)
	}
	if _, err := ReadV7KnotWeights(V7Element{Type: 3, Body: body}); err == nil {
		t.Fatal("wrong type must fail")
	}
	if _, err := ReadV7KnotWeights(V7Element{Type: 26, Body: make([]byte, 34)}); err == nil {
		t.Fatal("empty data must fail")
	}
}

func TestSampleCellsAndBSpline(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatal(err)
	}
	hdr, err := ParseV7Header(b)
	if err != nil {
		t.Fatal(err)
	}
	cells, curves, kws := 0, 0, 0
	for _, e := range els {
		switch e.Type {
		case 2:
			c, err := ReadV7CellHeader(e, hdr.Is3D)
			if err != nil {
				t.Fatalf("cell @%d: %v", e.Offset, err)
			}
			cells++
			if e.Offset == 1550576 { // golden cell (python mirror cross-check)
				if c.Name != "RARRAY" || c.Class != 5 || c.TotLength != 53765 ||
					c.Levels[0] != 1 || c.RangeLow != (V7Point{X: -6669067, Y: 4731940, Z: -1885566}) {
					t.Fatalf("golden cell: %+v", c)
				}
				if c.Trans[0] != 9.999983012676239e-05 || c.Origin != (V7Point{}) {
					t.Fatalf("golden cell trans/origin: %v %+v", c.Trans[0], c.Origin)
				}
			}
		case 27:
			bh, err := ReadV7BSplineCurveHeader(e)
			if err != nil {
				t.Fatalf("bsc @%d: %v", e.Offset, err)
			}
			curves++
			if e.Offset == 13260 { // golden curve header
				if bh.DescWords != 92 || bh.Order != 4 || bh.Properties != 16 ||
					bh.CurveType != 0 || bh.NumPoles != 5 || bh.NumKnots != 1 {
					t.Fatalf("golden bsc: %+v", bh)
				}
			}
		case 26, 28:
			v, err := ReadV7KnotWeights(e)
			if err != nil {
				t.Fatalf("kw @%d: %v", e.Offset, err)
			}
			kws++
			if e.Offset == 13306 { // golden knot element
				if len(v) != 1 || v[0] != 0.45379404558511172 {
					t.Fatalf("golden kw: %v", v)
				}
			}
		}
	}
	if cells != 223 || curves != 2522 || kws != 2521 {
		t.Fatalf("cells=%d curves=%d kws=%d", cells, curves, kws)
	}
}

func TestSharedCellDefn(t *testing.T) {
	// synthetic gate + decode
	body := make([]byte, 34)
	binary.LittleEndian.PutUint16(body[32:], 77)
	s, err := ReadV7SharedCellDefn(V7Element{Type: 34, Words: 17, Body: body})
	if err != nil {
		t.Fatal(err)
	}
	if s.TotLength != 77 {
		t.Fatalf("%+v", s)
	}
	if _, err := ReadV7SharedCellDefn(V7Element{Type: 3, Body: body}); err == nil {
		t.Fatal("wrong type must fail")
	}

	// sample: 115 elements parse
	b := loadSample(t, "../sample.dgn")
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatal(err)
	}
	n := 0
	defNames := map[string]bool{}
	for _, e := range els {
		if e.Type != 34 {
			continue
		}
		d, err := ReadV7SharedCellDefn(e)
		if err != nil {
			t.Fatalf("defn @%d: %v", e.Offset, err)
		}
		if d.Name == "" {
			t.Fatalf("defn @%d has empty name", e.Offset)
		}
		defNames[d.Name] = true
		n++
	}
	if n != 115 {
		t.Fatalf("shared cell defns=%d", n)
	}

	// sample: 39 shared-cell references; every name resolves to a defn
	// (sample-derived cross-validation, D85)
	rn := 0
	for _, e := range els {
		if e.Type != 35 {
			continue
		}
		r, err := ReadV7SharedCellRef(e)
		if err != nil {
			t.Fatalf("ref @%d: %v", e.Offset, err)
		}
		if r.Name == "" || !defNames[r.Name] {
			t.Fatalf("ref @%d name %q not among defns", e.Offset, r.Name)
		}
		if r.RangeLow.X == 0 && r.RangeHigh.X == 0 {
			t.Fatalf("ref @%d degenerate range", e.Offset)
		}
		rn++
	}
	if rn != 39 {
		t.Fatalf("shared cell refs=%d", rn)
	}
}

func TestReadV7SharedCellRefSynthetic(t *testing.T) {
	body := make([]byte, 176)
	binary.LittleEndian.PutUint16(body[32:], 88)
	// range low/high as halfword-swapped i32 (V7Int32 convention)
	put := func(off int, v int32) {
		binary.LittleEndian.PutUint32(body[off:], uint32(v>>16|v<<16))
	}
	put(48, 100)
	put(52, 200)
	put(56, 300)
	put(60, 400)
	put(64, 500)
	put(68, 600)
	copy(body[160:], "CELL-A\x00")
	r, err := ReadV7SharedCellRef(V7Element{Type: 35, Body: body})
	if err != nil {
		t.Fatal(err)
	}
	if r.TotLength != 88 || r.Name != "CELL-A" ||
		r.RangeLow.X != 100 || r.RangeLow.Z != 300 || r.RangeHigh.Y != 500 {
		t.Fatalf("%+v", r)
	}
	if _, err := ReadV7SharedCellRef(V7Element{Type: 34, Body: body}); err == nil {
		t.Fatal("wrong type must fail")
	}
	if _, err := ReadV7SharedCellRef(V7Element{Type: 35, Body: make([]byte, 100)}); err == nil {
		t.Fatal("short body must fail")
	}
}
