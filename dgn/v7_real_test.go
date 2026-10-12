package dgn

import (
	"os"
	"testing"

	"github.com/flywave/go-dgn/dgn/scene"
)

// Real public v7 samples from the Aspose.CAD MIT example repository
// (github.com/aspose-cad/Aspose.CAD-for-.NET, Examples/Data/Exporting-DGN;
// D129). Nikon_D90_Camera.dgn was the first real-world v7 file observed to
// carry non-element trailing bytes — ReadV7Elements must not fail the whole
// document on them.

func loadV7Real(t *testing.T, name string) V7Document {
	t.Helper()
	b, err := os.ReadFile("testdata/" + name)
	if err != nil {
		t.Skipf("sample absent: %v", err)
	}
	doc, err := ParseV7Document(b)
	if err != nil {
		t.Fatalf("%s: %v", name, err)
	}
	return doc
}

func TestV7RealNikonCameraTrailingBytes(t *testing.T) {
	b, err := os.ReadFile("testdata/Nikon_D90_Camera.dgn")
	if err != nil {
		t.Skipf("sample absent: %v", err)
	}
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatalf("trailing bytes must not fail the element walk: %v", err)
	}
	if len(els) != 199 {
		t.Fatalf("elements = %d, want 199", len(els))
	}
	doc := loadV7Real(t, "Nikon_D90_Camera.dgn")
	if !doc.Header.Is3D {
		t.Fatal("camera model should be 3D")
	}
	if _, _, ok := doc.Extents(); !ok {
		t.Fatal("extents: no extent-bearing element")
	}
}

func TestV7RealNikonCameraBSplineAssembly(t *testing.T) {
	doc := loadV7Real(t, "Nikon_D90_Camera.dgn")
	// The file carries 60 type-27 curve headers but only 59 pole (21)
	// records: the last pole element is truncated mid-body (claims 270B,
	// 123B remain — that truncated record is the "trailing garbage"). The
	// 59 complete curves must assemble; the incomplete header is skipped
	// (better-missing-than-wrong), so 59 — not 60 — is the honest count.
	ents := SceneV7AtMaster(doc)
	curves := 0
	var wirePts int
	for _, e := range ents {
		if e.Kind == scene.KindBSplineCurve {
			curves++
			if len(e.Points) < 2 || len(e.Knots) == 0 || e.Degree < 1 {
				t.Fatalf("curve entity %d malformed: poles=%d knots=%d degree=%d",
					e.ID, len(e.Points), len(e.Knots), e.Degree)
			}
			wirePts += len(e.Points)
		}
	}
	if curves != 59 {
		t.Fatalf("assembled B-spline curves = %d, want 59 (60th pole record truncated in source)", curves)
	}
	if wirePts == 0 {
		t.Fatal("no poles on any curve")
	}
}

func TestV7RealSeeds(t *testing.T) {
	for name, want3D := range map[string]bool{
		"V7-Imperial-Arch-01-Seed2D.dgn": false,
		"V7-Imperial-Arch-02-Seed3D.dgn": true,
	} {
		doc := loadV7Real(t, name)
		if doc.Header.Is3D != want3D {
			t.Fatalf("%s: Is3D=%v want %v", name, doc.Header.Is3D, want3D)
		}
	}
}
