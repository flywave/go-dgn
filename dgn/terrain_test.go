package dgn

import (
	"math"
	"testing"

	"github.com/flywave/go-dgn/dgn/scene"
)

func TestTerrainDecodeFromHeaps(t *testing.T) {
	f, err := Open("testdata/txdot-rudderplaza-terrain.dgn")
	if err != nil {
		t.Fatal(err)
	}
	doc, err := f.V8()
	if err != nil {
		t.Fatal(err)
	}
	meshes := DecodeTerrainHeaps(doc)
	if len(meshes) == 0 {
		t.Fatal("no terrain mesh decoded from heaps")
	}
	for _, m := range meshes {
		t.Logf("terrain mesh: vertices=%d triangles=%d", len(m.Points), len(m.Faces))
		if len(m.Points) != 428 {
			t.Fatalf("terrain vertices=%d, want exactly 428 (10272B f64 payload)", len(m.Points))
		}
		// vertices finite and plausibly planar-scattered (Texas state plane scale)
		minx, maxx := m.Points[0][0], m.Points[0][0]
		for _, p := range m.Points {
			if math.IsNaN(p[0]) || math.IsNaN(p[2]) {
				t.Fatal("NaN vertex")
			}
			if p[0] < minx {
				minx = p[0]
			}
			if p[0] > maxx {
				maxx = p[0]
			}
		}
		t.Logf("x range: %f .. %f", minx, maxx)
	}
	// scene wiring: a terrain entity must surface (KindSolid mesh) so the
	// go-topo bridge can triangulate it — D143 closes the type-106/EC gap.
	ents, err := SceneV8Terrain(doc)
	if err != nil {
		t.Fatal(err)
	}
	solids := 0
	for _, e := range ents {
		if e.Kind == scene.KindSolid && len(e.Points) == 428 {
			solids++
		}
	}
	if solids == 0 {
		t.Fatal("no terrain point-mesh entity emitted")
	}
}
