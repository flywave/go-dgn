package dgn

import (
	"testing"
)

func TestParseV7DocumentSample(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	d, err := ParseV7Document(b)
	if err != nil {
		t.Fatal(err)
	}
	if !d.Header.Is3D || d.Header.Level != 8 {
		t.Fatalf("header %+v", d.Header)
	}
	if len(d.Elements) != 22803 {
		t.Fatalf("elements=%d", len(d.Elements))
	}
	if len(d.Top) == 0 || d.Top[0].Element.Type != 9 {
		t.Fatalf("top-level first=%+v", d.Top)
	}
	// TCB + units (golden from python mirror, bit-exact cross-check)
	if d.TCB.Dimension != 3 || d.TCB.UORPerSubunit != 2540 || d.TCB.SubunitsPerMaster != 100 ||
		d.TCB.MasterUnits != "in" || d.TCB.Scale != 1.0/254000.0 {
		t.Fatalf("tcb %+v", d.TCB)
	}
	// views golden (view0 identity matrix; view6 activez)
	v0 := d.TCB.Views[0]
	if v0.Flags != 45276 || v0.ActiveZ != 3528568 {
		t.Fatalf("view0 %+v", v0)
	}
	if v0.Origin[0] != -27.729303149606299 || v0.Delta[0] != 6.152082677165355 {
		t.Fatalf("view0 origin/delta %+v", v0)
	}
	ident := [9]float64{1, 0, 0, 0, 1, 0, 0, 0, 1}
	if v0.TransMat != ident {
		t.Fatalf("view0 mat %v", v0.TransMat)
	}
	if v0.Conversion != 0.00037180930216391354 {
		t.Fatalf("view0 conv %v", v0.Conversion)
	}
	if d.TCB.Views[6].ActiveZ != 12192000 || d.TCB.Views[6].Flags != 45148 {
		t.Fatalf("view6 %+v", d.TCB.Views[6])
	}

	// extents golden (master units, python mirror bit-exact)
	mn, mx, ok := d.Extents()
	if !ok {
		t.Fatal("no extents")
	}
	wantMin := [3]float64{-27.451031496062992, -0.39972440944881893, -7.5794881889763781}
	wantMax := [3]float64{0.74970078740157486, 19.564047244094489, 0.04244488188976378}
	if mn != wantMin || mx != wantMax {
		t.Fatalf("extents min=%v max=%v", mn, mx)
	}
	// sanity: board-sized span in inches
	if mx[0]-mn[0] < 10 || mx[0]-mn[0] > 100 || mx[1]-mn[1] < 5 {
		t.Fatalf("span %v", [3]float64{mx[0] - mn[0], mx[1] - mn[1], mx[2] - mn[2]})
	}
}

func TestParseV7DocumentSeeds(t *testing.T) {
	for _, path := range []string{
		"/Users/xuning/Work/flywave-gdal/gdal_data/seed_2d.dgn",
		"/Users/xuning/Work/flywave-gdal/gdal_data/seed_3d.dgn",
	} {
		b := loadSample(t, path)
		d, err := ParseV7Document(b)
		if err != nil {
			t.Fatalf("%s: %v", path, err)
		}
		if int(d.TCB.Dimension) != map[bool]int{true: 3, false: 2}[d.Header.Is3D] {
			t.Fatalf("%s: tcb dim %d vs header %v", path, d.TCB.Dimension, d.Header.Is3D)
		}
		if _, _, ok := d.Extents(); ok {
			t.Fatalf("%s: seeds carry no extent elements", path)
		}
	}
}

func TestParseV7DocumentTruncated(t *testing.T) {
	if _, err := ParseV7Document([]byte{0xC8, 0x09, 0xFE, 0x02}); err == nil {
		t.Fatal("truncated file must fail")
	}
}
