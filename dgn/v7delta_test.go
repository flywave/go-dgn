package dgn

import (
	"encoding/binary"
	"math"
	"testing"
)

func encI16(v int16) uint16 { return uint16(v) }

// v7LineWithA951 builds a 3D LINE body whose attribute tail carries an
// A951 record covering both vertices.
func v7LineWithA951(t *testing.T) V7Element {
	t.Helper()
	// layout: data ends at 32+24=56; attrIndex → attr@56; region 16B
	body := make([]byte, 56+16)
	binary.LittleEndian.PutUint16(body[26:], 14) // idx*2+28 = 56
	binary.LittleEndian.PutUint16(body[28:], 0x0800)
	V7PutInt32(body[32:], 100)
	V7PutInt32(body[36:], 200)
	V7PutInt32(body[40:], 0)
	V7PutInt32(body[44:], -100)
	V7PutInt32(body[48:], -200)
	V7PutInt32(body[52:], 7)
	reg := body[56:]
	reg[0], reg[1] = 0xA9, 0x51
	binary.LittleEndian.PutUint16(reg[2:], 6) // dLen=12 (nonzero)
	// vertex 0 delta: dx=32767 (+1.0), dy=-16384
	binary.LittleEndian.PutUint16(reg[6:], encI16(32767))
	binary.LittleEndian.PutUint16(reg[8:], encI16(-16384))
	// vertex 1 delta: dx=-1, dy=16384
	binary.LittleEndian.PutUint16(reg[10:], encI16(-1))
	binary.LittleEndian.PutUint16(reg[12:], encI16(16384))
	return V7Element{Type: 3, Words: uint16(len(body) / 2), Body: body}
}

func TestReadV7LineF(t *testing.T) {
	el := v7LineWithA951(t)
	pts, err := ReadV7LineF(el, true)
	if err != nil {
		t.Fatal(err)
	}
	if pts[0].X != 101 || pts[0].Z != 0 {
		t.Fatalf("p0=%+v", pts[0])
	}
	if want := 200.0 + float64(-16384)/32767.0; pts[0].Y != want {
		t.Fatalf("p0y=%v want %v", pts[0].Y, want)
	}
	if want := -100.0 - 1.0/32767.0; pts[1].X != want {
		t.Fatalf("p1x=%v want %v", pts[1].X, want)
	}
	if pts[1].Z != 7 {
		t.Fatalf("p1=%+v", pts[1])
	}
	if want := -200.0 + float64(16384)/32767.0; pts[1].Y != want {
		t.Fatalf("p1y=%v want %v", pts[1].Y, want)
	}

	// raw reader unaffected by attributes
	raw, err := ReadV7Line(el, true)
	if err != nil {
		t.Fatal(err)
	}
	if raw[0].X != 100 || raw[1].X != -100 {
		t.Fatalf("%+v", raw)
	}

	// no attribute flag → identical to raw
	nof := V7Element{Type: 3, Words: 28, Body: make([]byte, 56)}
	V7PutInt32(nof.Body[32:], 42)
	f2, err := ReadV7LineF(nof, true)
	if err != nil {
		t.Fatal(err)
	}
	if f2[0].X != 42 || f2[0].Y != 0 {
		t.Fatalf("%+v", f2[0])
	}
}

func TestReadV7MultiPointF(t *testing.T) {
	// data ends at 34+24=58; attrIndex=15 → attr@58; region 16B
	body := make([]byte, 58+16)
	binary.LittleEndian.PutUint16(body[26:], 15)
	binary.LittleEndian.PutUint16(body[28:], 0x0800)
	binary.LittleEndian.PutUint16(body[32:], 2)
	V7PutInt32(body[34:], 1000)
	V7PutInt32(body[38:], 2000)
	V7PutInt32(body[42:], 0)
	V7PutInt32(body[46:], 0)
	V7PutInt32(body[50:], 0)
	V7PutInt32(body[54:], 0)
	region := body[58:]
	region[0], region[1] = 0xA9, 0x51
	binary.LittleEndian.PutUint16(region[2:], 6)
	binary.LittleEndian.PutUint16(region[6:], encI16(-32767))
	binary.LittleEndian.PutUint16(region[8:], encI16(32767))
	// vertex 1 delta stays zero
	el := V7Element{Type: 4, Words: uint16(len(body) / 2), Body: body}
	pts, err := ReadV7MultiPointF(el, true)
	if err != nil {
		t.Fatal(err)
	}
	if len(pts) != 2 {
		t.Fatalf("len=%d", len(pts))
	}
	if pts[0].X != 999 || pts[0].Y != 2001 {
		t.Fatalf("p0=%+v", pts[0])
	}
	if pts[1].X != 0 || pts[1].Y != 0 {
		t.Fatalf("p1=%+v", pts[1])
	}
}

func TestReadV7Boundary(t *testing.T) {
	body := make([]byte, 36+3*8)
	binary.LittleEndian.PutUint16(body[32:], 2) // number
	binary.LittleEndian.PutUint16(body[34:], 3) // numverts
	V7PutInt32(body[36:], 10)
	V7PutInt32(body[40:], 20)
	V7PutInt32(body[44:], -30)
	V7PutInt32(body[48:], 40)
	V7PutInt32(body[52:], 50)
	V7PutInt32(body[56:], 60)
	bd, err := ReadV7Boundary(V7Element{Type: 25, Words: uint16(len(body) / 2), Body: body})
	if err != nil {
		t.Fatal(err)
	}
	if bd.Number != 2 || len(bd.Verts) != 3 {
		t.Fatalf("%+v", bd)
	}
	if bd.Verts[0] != (V7PointF{X: 10, Y: 20}) || bd.Verts[2] != (V7PointF{X: 50, Y: 60}) {
		t.Fatalf("%+v", bd.Verts)
	}
	// numverts clamp at element end: only 2 verts fit
	short := V7Element{Type: 25, Words: (36 + 16) / 2, Body: make([]byte, 36+16)}
	binary.LittleEndian.PutUint16(short.Body[34:], 9)
	bd2, err := ReadV7Boundary(short)
	if err != nil {
		t.Fatal(err)
	}
	if len(bd2.Verts) != 2 {
		t.Fatalf("clamped=%d", len(bd2.Verts))
	}
	// errors
	if _, err := ReadV7Boundary(V7Element{Type: 3, Body: body}); err == nil {
		t.Fatal("wrong type must fail")
	}
	bad := V7Element{Type: 25, Words: 18, Body: make([]byte, 36)}
	binary.LittleEndian.PutUint16(bad.Body[34:], 0)
	if _, err := ReadV7Boundary(bad); err == nil {
		t.Fatal("numverts 0 must fail")
	}
}

func TestSampleLineFGolden(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatal(err)
	}
	hdr, err := ParseV7Header(b)
	if err != nil {
		t.Fatal(err)
	}
	var golden V7Element
	lines, frac := 0, 0
	for _, e := range els {
		if e.Type != 3 {
			continue
		}
		lines++
		pts, err := ReadV7LineF(e, hdr.Is3D)
		if err != nil {
			t.Fatalf("lineF @%d: %v", e.Offset, err)
		}
		for _, p := range pts {
			if p.X != math.Trunc(p.X) || p.Y != math.Trunc(p.Y) {
				frac++
			}
		}
		if e.Offset == 13176 {
			golden = e
		}
	}
	if lines != 5814 {
		t.Fatalf("lines=%d", lines)
	}
	if frac < 1000 {
		t.Fatalf("fractional vertices=%d (A951 must be active)", frac)
	}
	if golden.Body == nil {
		t.Fatal("golden line @13176 missing")
	}
	pts, err := ReadV7LineF(golden, hdr.Is3D)
	if err != nil {
		t.Fatal(err)
	}
	want := [2]V7PointF{
		{X: 111029.71999267556, Y: 11414.582049012726, Z: 0},
		{X: 19568, Y: 11414.835505233925, Z: 0},
	}
	if pts != want {
		t.Fatalf("golden lineF=%+v want %+v", pts, want)
	}
}
