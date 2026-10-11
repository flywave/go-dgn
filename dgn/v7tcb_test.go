package dgn

import (
	"math"
	"testing"
)

func TestParseV7TCBSample(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatal(err)
	}
	if len(els) == 0 || els[0].Type != 9 {
		t.Fatalf("first element must be TCB, got type=%d", els[0].Type)
	}
	tcb, err := ParseV7TCB(els[0])
	if err != nil {
		t.Fatal(err)
	}
	// Real sample: inch file, 100 thou/master, 2540 UOR/thou, origin 0, 3D.
	if tcb.Dimension != 3 || tcb.UORPerSubunit != 2540 || tcb.SubunitsPerMaster != 100 {
		t.Fatalf("%+v", tcb)
	}
	if tcb.MasterUnits != "in" || tcb.SubUnits != "th" {
		t.Fatalf("units %q/%q", tcb.MasterUnits, tcb.SubUnits)
	}
	if tcb.Scale != 1.0/254000.0 {
		t.Fatalf("scale=%v", tcb.Scale)
	}
	if tcb.Origin != [3]float64{0, 0, 0} {
		t.Fatalf("origin=%v", tcb.Origin)
	}
	got := tcb.TransformPoint(V7Point{X: 254000, Y: 508000, Z: -254000})
	for i, want := range [3]float64{1, 2, -1} {
		if math.Abs(got[i]-want) > 1e-12 {
			t.Fatalf("transform=%v", got)
		}
	}
	if m := tcb.ToMaster([3]float64{254000, 0, 0}); math.Abs(m[0]-1) > 1e-12 {
		t.Fatalf("master=%v", m)
	}
	if got := tcb.TextMult(1000); math.Abs(got-1000.0/254000.0*6.0/1000.0) > 1e-18 {
		t.Fatalf("textmult=%v", got)
	}
	// A second TCB exists in the sample; GDAL latches only the first.
	second := false
	for _, e := range els[1:] {
		if e.Type == 9 {
			if _, err := ParseV7TCB(e); err != nil {
				t.Fatalf("second TCB @%d: %v", e.Offset, err)
			}
			second = true
		}
	}
	if !second {
		t.Fatal("expected a second TCB in sample")
	}
}

func TestParseV7TCBSynthetic(t *testing.T) {
	body := make([]byte, 1260)
	// uor_per_subunit=1000 @body1112, subunits_per_master=100 @body1108
	V7PutInt32(body[1108:], 100)
	V7PutInt32(body[1112:], 1000)
	copy(body[1116:], "m ")
	copy(body[1118:], "cm")
	V7PutDouble(body[1236:], 1000000)
	V7PutDouble(body[1244:], -2000000)
	V7PutDouble(body[1252:], 0)
	// body1210 stays 0 → 2D
	tcb, err := ParseV7TCB(V7Element{Type: 9, Words: uint16(len(body) / 2), Body: body})
	if err != nil {
		t.Fatal(err)
	}
	if tcb.Dimension != 2 || tcb.UORPerSubunit != 1000 || tcb.SubunitsPerMaster != 100 {
		t.Fatalf("%+v", tcb)
	}
	if tcb.MasterUnits != "m " || tcb.SubUnits != "cm" {
		t.Fatalf("units %q/%q", tcb.MasterUnits, tcb.SubUnits)
	}
	if tcb.Scale != 1e-5 {
		t.Fatalf("scale=%v", tcb.Scale)
	}
	if tcb.Origin[0] != 10 || tcb.Origin[1] != -20 || tcb.Origin[2] != 0 {
		t.Fatalf("origin=%v", tcb.Origin)
	}
	if g := tcb.TransformPoint(V7Point{X: 2000000}); math.Abs(g[0]-10) > 1e-9 || math.Abs(g[1]-20) > 1e-9 || g[2] != 0 {
		t.Fatalf("transform=%v", g)
	}
	if _, err := ParseV7TCB(V7Element{Type: 3, Body: body}); err == nil {
		t.Fatal("non-TCB must fail")
	}
	if _, err := ParseV7TCB(V7Element{Type: 9, Body: make([]byte, 100)}); err == nil {
		t.Fatal("short TCB must fail")
	}
}
