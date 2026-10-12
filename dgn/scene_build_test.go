package dgn

import (
	"testing"

	"github.com/flywave/go-dgn/dgn/scene"
)

// TestSceneV7SampleGolden locks the scene histogram of the 16MB sample:
// every geometry-bearing element must be classified exactly once, and
// complex-group children must reference a live ComplexHeader parent.
func TestSceneV7SampleGolden(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	doc, err := ParseV7Document(b)
	if err != nil {
		t.Fatal(err)
	}
	ents := SceneV7(doc)

	want := map[scene.Kind]int{
		scene.KindComplexHeader: 19, // type12:16 + type14:3
		scene.KindSegment:       5814,
		scene.KindPolyline:      36 + 47, // type4 + type6 (type21 poles fold into curves)
		scene.KindBSplineCurve:  2522,    // type27 assemblies (27+26+21 adjacency)
		scene.KindArc:           317,
		scene.KindEllipse:       6,
		scene.KindCellDef:       223 + 115, // type2 + type34
		scene.KindCellRef:       39,
	}
	got := map[scene.Kind]int{}
	for _, e := range ents {
		got[e.Kind]++
	}
	if len(got) != len(want) {
		t.Fatalf("kind count %d want %d: %v", len(got), len(want), got)
	}
	for k, n := range want {
		if got[k] != n {
			t.Errorf("kind %s: %d want %d", k, got[k], n)
		}
	}

	// Parent integrity: every ParentID must reference a ComplexHeader
	// (chain/shape group) or CellDef (cell header / shared-defn span group,
	// D93). DefnOnly marks shared-definition interiors (render only via
	// CellRef instances).
	byID := map[uint64]scene.Entity{}
	for _, e := range ents {
		byID[e.ID] = e
	}
	nested, defnOnly := 0, 0
	for _, e := range ents {
		if e.DefnOnly {
			defnOnly++
		}
		if e.ParentID == 0 {
			continue
		}
		p, ok := byID[e.ParentID]
		if !ok {
			t.Fatalf("entity %d parent %d missing", e.ID, e.ParentID)
		}
		if p.Kind != scene.KindComplexHeader && p.Kind != scene.KindCellDef {
			t.Fatalf("entity %d parent kind %s", e.ID, p.Kind)
		}
		nested++
	}
	if nested != 9002 {
		t.Errorf("nested=%d want 9002 (56 complex-group + cell spans, D93)", nested)
	}
	if defnOnly != 6178 {
		t.Errorf("defnOnly=%d want 6178 (shared-defn interiors, D93)", defnOnly)
	}
	t.Logf("entities=%d nested=%d defnOnly=%d", len(ents), nested, defnOnly)
}

// TestSceneV7BSplineAssemblies pins the v7 B-spline curve assembly: each
// type-27 header consumes its adjacent knot(26)/pole(21) siblings into one
// KindBSplineCurve entity carrying the full clamped knot vector
// (num_knots = num_poles − order interior values; D92 adjacency contract).
func TestSceneV7BSplineAssemblies(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	doc, err := ParseV7Document(b)
	if err != nil {
		t.Fatal(err)
	}
	ents := SceneV7(doc)
	curves := 0
	for _, e := range ents {
		if e.Kind != scene.KindBSplineCurve {
			continue
		}
		curves++
		order := e.Degree + 1
		if e.Degree != 3 {
			t.Fatalf("curve %d: degree %d want 3 (sample golden)", e.ID, e.Degree)
		}
		if len(e.Knots) != len(e.Points)+e.Degree+1 {
			t.Fatalf("curve %d: knots=%d poles=%d degree=%d",
				e.ID, len(e.Knots), len(e.Points), e.Degree)
		}
		if e.Knots[0] != 0 || e.Knots[len(e.Knots)-1] != 1 {
			t.Fatalf("curve %d: clamped ends %v…%v want 0…1",
				e.ID, e.Knots[0], e.Knots[len(e.Knots)-1])
		}
		for i := order; i < len(e.Knots)-order; i++ {
			if e.Knots[i] < e.Knots[i-1] || e.Knots[i] <= 0 || e.Knots[i] >= 1 {
				t.Fatalf("curve %d: interior knots out of (0,1) or decreasing: %v",
					e.ID, e.Knots)
			}
		}
		if e.Weights != nil && len(e.Weights) != len(e.Points) {
			t.Fatalf("curve %d: weights=%d poles=%d", e.ID, len(e.Weights), len(e.Points))
		}
	}
	if curves != 2522 {
		t.Fatalf("curves=%d want 2522", curves)
	}
}

// TestSceneV7AtMasterMapsCoords checks master-unit mapping: raw and master
// scenes must have identical kind histograms and non-zero coordinate shift
// for at least one entity (TCB origin/scale applied).
func TestSceneV7AtMasterMapsCoords(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	doc, err := ParseV7Document(b)
	if err != nil {
		t.Fatal(err)
	}
	raw := SceneV7(doc)
	mst := SceneV7AtMaster(doc)
	if len(raw) != len(mst) {
		t.Fatalf("count mismatch %d != %d", len(raw), len(mst))
	}
	shifted := false
	for i := range raw {
		if raw[i].Kind != mst[i].Kind {
			t.Fatalf("entity %d kind drift", i)
		}
		if len(raw[i].Points) != len(mst[i].Points) {
			t.Fatalf("entity %d point count drift", i)
		}
		for j := range raw[i].Points {
			if raw[i].Points[j] != mst[i].Points[j] {
				shifted = true
			}
		}
	}
	if !shifted {
		t.Fatal("no coordinate was transformed")
	}
}

// TestSceneV8Synthetic checks the v8 path on a minimal line element.
func TestSceneV8Synthetic(t *testing.T) {
	hdr := buildHeader(Header{Type: 3, B: 24, C: 24, ID: 42})
	body := f64le(1, 2, 3, 4, 5, 6)
	got, err := SceneV8(join(hdr, body), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if len(got) != 1 {
		t.Fatalf("entities=%d", len(got))
	}
	e := got[0]
	if e.Kind != scene.KindSegment || e.ID != 42 || e.Dim != 2 {
		t.Fatalf("%+v", e)
	}
	if e.Points[0] != (scene.Point{X: 1, Y: 2}) || e.Points[1] != (scene.Point{X: 3, Y: 4}) {
		t.Fatalf("%+v", e.Points)
	}
}
