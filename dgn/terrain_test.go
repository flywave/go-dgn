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

// TestTerrainDelaunayTIN pins the generative TIN rebuild (D150): with no
// explicit triangle table in the file, the 428-vertex terrain set is
// Delaunay-triangulated — the result must cover every vertex and satisfy
// the planar Euler characteristic (V - E + F = 1 for an open TIN).
func TestTerrainDelaunayTIN(t *testing.T) {
	f, err := Open("testdata/txdot-rudderplaza-terrain.dgn")
	if err != nil {
		t.Fatal(err)
	}
	doc, err := f.V8()
	if err != nil {
		t.Fatal(err)
	}
	ents, err := SceneV8Terrain(doc)
	if err != nil {
		t.Fatal(err)
	}
	if len(ents) != 1 {
		t.Fatalf("terrain entities=%d", len(ents))
	}
	e := ents[0]
	V := len(e.Points)
	F := len(e.Faces)
	if V != 428 || F < 800 {
		t.Fatalf("V=%d F=%d, want 428 vertices and ~840 triangles", V, F)
	}
	// edge census for Euler
	edgeCount := map[[2]int]int{}
	for _, f := range e.Faces {
		for k := 0; k < 3; k++ {
			a, b := f[k], f[(k+1)%3]
			if a > b {
				a, b = b, a
			}
			edgeCount[[2]int{int(a), int(b)}]++
			if f[k] < 0 || int(f[k]) >= V {
				t.Fatalf("face index %d out of range", f[k])
			}
		}
	}
	E := len(edgeCount)
	boundary := 0
	for _, c := range edgeCount {
		if c == 1 {
			boundary++
		}
	}
	t.Logf("V=%d E=%d F=%d boundary-edges=%d euler=%d", V, E, F, boundary, V-E+F)
	if V-E+F != 1 {
		t.Fatalf("Euler characteristic %d != 1 (open TIN)", V-E+F)
	}
	// every vertex must be referenced by at least one face
	used := map[int32]bool{}
	for _, f := range e.Faces {
		for _, idx := range f {
			used[idx] = true
		}
	}
	if len(used) != V {
		t.Fatalf("only %d of %d vertices used by the TIN", len(used), V)
	}
}
