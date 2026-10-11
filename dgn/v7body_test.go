package dgn

import (
	"encoding/binary"
	"math"
	"testing"
)

func v7El(t *testing.T, typ byte, body []byte) V7Element {
	t.Helper()
	return V7Element{Level: 5, Type: typ, Words: uint16((len(body) + 4 - 4) / 2), Body: body}
}

func v7PutBBox(body []byte, i int, v int32) {
	V7PutInt32(body[i*4:], int32(uint32(v)+(1<<31)))
}

func TestParseV7Core(t *testing.T) {
	body := make([]byte, 64)
	for i := 0; i < 6; i++ {
		v7PutBBox(body, i, int32(100+i))
	}
	binary.LittleEndian.PutUint16(body[24:], 7)
	binary.LittleEndian.PutUint16(body[28:], 0x0800|5)
	body[30] = 0x0b
	body[31] = 9
	el := V7Element{Level: 3, Type: 17, Body: body}
	c := ParseV7Core(el)
	if !c.HasDispHdr || c.BBox[5] != 105 || c.GraphicGroup != 7 {
		t.Fatalf("%+v", c)
	}
	if !c.HasAttributes() || c.Style != 3 || c.Weight != 1 || c.Color != 9 {
		t.Fatalf("%+v", c)
	}
	if ParseV7Core(V7Element{Type: 9, Body: body}).HasDispHdr {
		t.Fatal("type9 must not have disp hdr")
	}
}

func TestReadV7LineAndMultiPoint(t *testing.T) {
	body := make([]byte, 32+24)
	V7PutInt32(body[32:], 1)
	V7PutInt32(body[36:], 2)
	V7PutInt32(body[40:], 3)
	V7PutInt32(body[44:], 4)
	V7PutInt32(body[48:], 5)
	V7PutInt32(body[52:], 6)
	el := V7Element{Type: 3, Words: uint16(len(body) / 2), Body: body}
	pts, err := ReadV7Line(el, true)
	if err != nil {
		t.Fatal(err)
	}
	if pts[0].X != 1 || pts[0].Z != 3 || pts[1].Y != 5 {
		t.Fatalf("%+v", pts)
	}

	lsBody := make([]byte, 34+2*12)
	binary.LittleEndian.PutUint16(lsBody[32:], 2)
	V7PutInt32(lsBody[34:], 10)
	lsEl := V7Element{Type: 4, Words: uint16(len(lsBody) / 2), Body: lsBody}
	mp, err := ReadV7MultiPoint(lsEl, true)
	if err != nil {
		t.Fatal(err)
	}
	if len(mp) != 2 || mp[0].X != 10 {
		t.Fatalf("%+v", mp)
	}
}

func TestReadV7Arc2D(t *testing.T) {
	body := make([]byte, 76)
	V7PutInt32(body[32:], 30*360000) // start 30°
	// sweep −45° stored sign-magnitude (bit31 = sign)
	mag := uint32(45 * 360000)
	V7PutInt32(body[36:], int32(mag|(1<<31)))
	V7PutDouble(body[40:], 12.5)
	V7PutDouble(body[48:], 3.0)
	V7PutInt32(body[56:], 90*360000) // rotation 90°
	V7PutDouble(body[60:], 1.5)
	V7PutDouble(body[68:], -2.25)
	a, err := ReadV7Arc(v7El(t, 16, body), false)
	if err != nil {
		t.Fatal(err)
	}
	if a.Start != 30 || a.Sweep != -45 || a.Rotation != 90 {
		t.Fatalf("%+v", a)
	}
	if a.Primary != 12.5 || a.Secondary != 3 || a.Origin[0] != 1.5 || a.Origin[1] != -2.25 {
		t.Fatalf("%+v", a)
	}

	// sweep raw 0 → full circle (GDAL semantics)
	V7PutInt32(body[36:], 0)
	a, err = ReadV7Arc(v7El(t, 16, body), false)
	if err != nil {
		t.Fatal(err)
	}
	if a.Sweep != 360 {
		t.Fatalf("sweep=%v", a.Sweep)
	}
}

func TestReadV7Ellipse2D(t *testing.T) {
	body := make([]byte, 68)
	V7PutDouble(body[32:], 8.0)
	V7PutDouble(body[40:], 4.0)
	V7PutInt32(body[48:], 45*360000)
	V7PutDouble(body[52:], 7.0)
	V7PutDouble(body[60:], 9.0)
	e, err := ReadV7Ellipse(v7El(t, 15, body), false)
	if err != nil {
		t.Fatal(err)
	}
	if e.Start != 0 || e.Sweep != 360 || e.Primary != 8 || e.Secondary != 4 {
		t.Fatalf("%+v", e)
	}
	if e.Rotation != 45 || e.Origin[0] != 7 || e.Origin[1] != 9 {
		t.Fatalf("%+v", e)
	}
}

func TestReadV7Text(t *testing.T) {
	// 2D
	body := make([]byte, 64)
	body[32] = 3 // font
	body[33] = 7 // justification
	V7PutInt32(body[34:], 1000)
	V7PutInt32(body[38:], 2000)
	V7PutInt32(body[42:], 90*360000)
	V7PutInt32(body[46:], 111)
	V7PutInt32(body[50:], 222)
	body[54] = 5
	copy(body[56:], "HELLO")
	txt, err := ReadV7Text(v7El(t, 17, body), false)
	if err != nil {
		t.Fatal(err)
	}
	if txt.FontID != 3 || txt.Justification != 7 || txt.LengthMult != 1000 || txt.HeightMult != 2000 {
		t.Fatalf("%+v", txt)
	}
	if txt.Rotation != 90 || txt.Origin[0] != 111 || txt.Origin[1] != 222 {
		t.Fatalf("%+v", txt)
	}
	if txt.String != "HELLO" {
		t.Fatalf("string=%q", txt.String)
	}

	// 3D + FF,FD packed UTF-16 path
	body3 := make([]byte, 80)
	body3[32] = 1
	V7PutInt32(body3[34:], 300)
	V7PutInt32(body3[38:], 400)
	for i := 0; i < 4; i++ {
		V7PutInt32(body3[42+i*4:], int32(i+1))
	}
	V7PutInt32(body3[58:], 10)
	V7PutInt32(body3[62:], 20)
	V7PutInt32(body3[66:], 30)
	body3[70] = 6 // 2 words after BOM: 0x0041 ('A'), 0xAC00 (2-byte)
	body3[72], body3[73] = 0xFF, 0xFD
	binary.LittleEndian.PutUint16(body3[74:], 0x0041)
	binary.LittleEndian.PutUint16(body3[76:], 0xAC00)
	txt3, err := ReadV7Text(v7El(t, 17, body3), true)
	if err != nil {
		t.Fatal(err)
	}
	if txt3.Origin[2] != 30 || txt3.Quat[3] != 4 || txt3.LengthMult != 300 {
		t.Fatalf("%+v", txt3)
	}
	if txt3.String != "A\xac\x00" {
		t.Fatalf("string=%q", txt3.String)
	}
}

func TestReadV7TextNode(t *testing.T) {
	body := make([]byte, 82)
	binary.LittleEndian.PutUint16(body[32:], 55)
	binary.LittleEndian.PutUint16(body[34:], 2)
	binary.LittleEndian.PutUint16(body[36:], 9)
	body[38] = 40
	body[39] = 12
	body[40] = 4
	body[41] = 1
	V7PutInt32(body[46:], 500)
	V7PutInt32(body[50:], 600)
	V7PutInt32(body[54:], 180*360000)
	V7PutInt32(body[58:], 77)
	V7PutInt32(body[62:], 88)
	n, err := ReadV7TextNode(v7El(t, 7, body), false)
	if err != nil {
		t.Fatal(err)
	}
	if n.TotLength != 55 || n.NumElems != 2 || n.NodeNumber != 9 || n.MaxLength != 40 || n.MaxUsed != 12 {
		t.Fatalf("%+v", n)
	}
	if n.FontID != 4 || n.Justification != 1 || n.LengthMult != 500 || n.HeightMult != 600 {
		t.Fatalf("%+v", n)
	}
	if n.Rotation != 180 || n.Origin[0] != 77 || n.Origin[1] != 88 {
		t.Fatalf("%+v", n)
	}
}

func TestReadV7Cone(t *testing.T) {
	body := make([]byte, 114)
	binary.LittleEndian.PutUint16(body[32:], 7)
	for i := 0; i < 4; i++ {
		V7PutInt32(body[34+i*4:], int32(100+i))
	}
	V7PutDouble(body[50:], 1.0)
	V7PutDouble(body[58:], 2.0)
	V7PutDouble(body[66:], 3.0)
	V7PutDouble(body[74:], 4.0)
	V7PutDouble(body[82:], 5.0)
	V7PutDouble(body[90:], 6.0)
	V7PutDouble(body[98:], 7.0)
	V7PutDouble(body[106:], 8.0)
	c, err := ReadV7Cone(v7El(t, 23, body), true)
	if err != nil {
		t.Fatal(err)
	}
	if c.Unknown != 7 || c.Quat[3] != 103 {
		t.Fatalf("%+v", c)
	}
	if c.Center1 != [3]float64{1, 2, 3} || c.Radius1 != 4 || c.Center2 != [3]float64{5, 6, 7} || c.Radius2 != 8 {
		t.Fatalf("%+v", c)
	}
	if _, err := ReadV7Cone(v7El(t, 23, body), false); err == nil {
		t.Fatal("2D cone must fail")
	}
}

func TestSampleV7Geometry(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatal(err)
	}
	lines := 0
	for _, e := range els {
		if e.Type != 3 {
			continue
		}
		lines++
		pts, err := ReadV7Line(e, true)
		if err != nil {
			t.Fatalf("line @%d: %v", e.Offset, err)
		}
		// header bbox (offset-binary decoded) must contain the endpoints
		c := ParseV7Core(e)
		for _, p := range pts {
			if p.X < c.BBox[0] || p.X > c.BBox[3] || p.Y < c.BBox[1] || p.Y > c.BBox[4] || p.Z < c.BBox[2] || p.Z > c.BBox[5] {
				t.Fatalf("line @%d bbox=%v pt=%+v outside", e.Offset, c.BBox, p)
			}
		}
	}
	if lines < 5000 {
		t.Fatalf("lines=%d", lines)
	}
	ls := 0
	for _, e := range els {
		if e.Type == 4 {
			ls++
			pts, err := ReadV7MultiPoint(e, true)
			if err != nil {
				t.Fatalf("linestring @%d: %v", e.Offset, err)
			}
			if len(pts) < 2 {
				t.Fatalf("linestring pts=%d", len(pts))
			}
		}
	}
	if ls == 0 {
		t.Fatal("no linestrings")
	}
	coreDisp := 0
	for _, e := range els {
		if ParseV7Core(e).HasDispHdr {
			coreDisp++
		}
	}
	if coreDisp == 0 {
		t.Fatal("no disp hdr elements")
	}
}

func TestSampleV7Arc(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatal(err)
	}
	n, neg, circles := 0, 0, 0
	for _, e := range els {
		if e.Type != 16 {
			continue
		}
		a, err := ReadV7Arc(e, true)
		if err != nil {
			t.Fatalf("arc @%d: %v", e.Offset, err)
		}
		n++
		if a.Sweep < 0 {
			neg++
		}
		if a.Sweep == 360 {
			circles++
		}
		if math.Abs(a.Start) > 720 || math.Abs(a.Sweep) > 360 {
			t.Fatalf("arc @%d angles start=%v sweep=%v", e.Offset, a.Start, a.Sweep)
		}
		if a.Primary <= 0 || a.Secondary <= 0 {
			t.Fatalf("arc @%d axes %v/%v", e.Offset, a.Primary, a.Secondary)
		}
		var norm float64
		for _, q := range a.Quat {
			norm += float64(q) * float64(q)
		}
		if norm != 0 {
			if u := math.Sqrt(norm) / (1 << 31); u < 0.99 || u > 1.01 {
				t.Fatalf("arc @%d quat not unit: %v", e.Offset, u)
			}
		}
	}
	if n != 317 {
		t.Fatalf("arcs=%d", n)
	}
	if neg < 60 || neg > 70 {
		t.Fatalf("negative sweeps=%d (sample has 65)", neg)
	}
	if circles == 0 {
		t.Fatal("no full-circle arcs")
	}
}

func TestSampleV7Ellipse(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatal(err)
	}
	n := 0
	for _, e := range els {
		if e.Type != 15 {
			continue
		}
		a, err := ReadV7Ellipse(e, true)
		if err != nil {
			t.Fatalf("ellipse @%d: %v", e.Offset, err)
		}
		n++
		if a.Start != 0 || a.Sweep != 360 || a.Primary <= 0 || a.Secondary <= 0 {
			t.Fatalf("ellipse @%d %+v", e.Offset, a)
		}
		var norm float64
		for _, q := range a.Quat {
			norm += float64(q) * float64(q)
		}
		if u := math.Sqrt(norm) / (1 << 31); u < 0.99 || u > 1.01 {
			t.Fatalf("ellipse @%d quat not unit: %v", e.Offset, u)
		}
	}
	if n != 6 {
		t.Fatalf("ellipses=%d", n)
	}
}
