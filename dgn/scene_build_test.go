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
		scene.KindPolyline:      36 + 47 + 2522, // type4 + type6 + type21
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

	// Parent integrity: every ParentID must reference a ComplexHeader entity.
	byID := map[uint64]scene.Entity{}
	for _, e := range ents {
		byID[e.ID] = e
	}
	nested := 0
	for _, e := range ents {
		if e.ParentID == 0 {
			continue
		}
		p, ok := byID[e.ParentID]
		if !ok {
			t.Fatalf("entity %d parent %d missing", e.ID, e.ParentID)
		}
		if p.Kind != scene.KindComplexHeader {
			t.Fatalf("entity %d parent kind %s", e.ID, p.Kind)
		}
		nested++
	}
	if nested == 0 {
		t.Fatal("expected nested children under complex headers")
	}
	t.Logf("entities=%d nested=%d", len(ents), nested)
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
