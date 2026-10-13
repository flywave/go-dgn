package dgn

import (
	"testing"

	"github.com/flywave/go-dgn/dgn/scene"
)

// Real public v8 samples: TxDOT standard plan sheets straight off the
// department FTP (ftp.dot.state.tx.us /pub/txdot-info/cmd/cserve/standard/,
// D135) — MicroStation-authored CFB v8 files. Matt23 is the first real
// file observed to carry SharedCellInstance(35) elements whose 0x2716
// dependency roots resolve into the Dgn^Nm definition library chunks.

func loadV8Real(t *testing.T, name string) *V8Document {
	t.Helper()
	f, err := Open("testdata/" + name)
	if err != nil {
		t.Skipf("sample absent: %v", err)
	}
	doc, err := f.V8()
	if err != nil {
		t.Fatalf("%s: %v", name, err)
	}
	return doc
}

func TestV8RealTxDOTSharedCellChain(t *testing.T) {
	doc := loadV8Real(t, "txdot-matt23.dgn")
	ents, err := SceneV8ModelAtMaster(doc, doc.Models[0])
	if err != nil {
		t.Fatal(err)
	}
	defs, err := SceneV8SharedCellDefs(doc)
	if err != nil {
		t.Fatal(err)
	}
	if len(defs) == 0 {
		t.Fatal("Dgn^Nm library produced no entities")
	}
	defByID := map[uint64]int{}
	for i := range defs {
		defByID[defs[i].ID] = i
		if !defs[i].DefnOnly {
			t.Fatalf("library entity %#x must be DefnOnly", defs[i].ID)
		}
	}
	refs, resolved := 0, 0
	for _, e := range ents {
		if e.Kind != scene.KindCellRef || e.DefID == 0 {
			continue
		}
		refs++
		if di, ok := defByID[e.DefID]; ok {
			resolved++
			if defs[di].Kind != scene.KindCellDef {
				t.Fatalf("DefID %#x resolves to %v, want CellDef", e.DefID, defs[di].Kind)
			}
		}
	}
	if refs != 12 || resolved != 12 {
		t.Fatalf("shared-cell chain: refs=%d resolved=%d, want 12/12", refs, resolved)
	}
	// the 0x56d2 StringLinkage names decode on the real definitions
	var sawName bool
	for i := range defs {
		if defs[i].Name != "" {
			sawName = true
			break
		}
	}
	if !sawName {
		t.Fatal("no definition carries a decoded 0x56d2 name")
	}
}

func TestV8RealTxDOTGeometry(t *testing.T) {
	// 1638/1638 headers assemble (D138): the knotless-Bézier fix (D137)
	// plus the dual knot-vector semantics — header property bit
	// 0x08000000 marks fully expanded knots (k=p+order), its absence
	// means interior knots (k=p−order); both orders came out 4 on the
	// whole real corpus.
	for name, wantCurve := range map[string]int{
		"txdot-matt23.dgn":    1638,
		"txdot-bb-afl-24.dgn": 71,
		"txdot-bb-b20-12.dgn": 213,
	} {
		doc := loadV8Real(t, name)
		ents, err := SceneV8ModelAtMaster(doc, doc.Models[0])
		if err != nil {
			t.Fatalf("%s: %v", name, err)
		}
		curves := 0
		for _, e := range ents {
			if e.Kind == scene.KindBSplineCurve {
				curves++
				if len(e.Points) < 2 || len(e.Knots) == 0 {
					t.Fatalf("%s curve %#x malformed", name, e.ID)
				}
			}
		}
		if curves != wantCurve {
			t.Fatalf("%s BSplineCurve=%d want %d", name, curves, wantCurve)
		}
	}
}

// TestV8RealTxDOTTerrain3DWireframe bridges the OpenRoads terrain working
// file (D142): its graphics are true-3D — Line3d/LineString3d feature
// lines plus a named 3D cell header; the terrain surface itself lives in
// uncracked type-106 EC extension elements (proxy-sized, 16-48B — a
// work order, not silently droppable geometry).
func TestV8RealTxDOTTerrain3DWireframe(t *testing.T) {
	doc := loadV8Real(t, "txdot-rudderplaza-terrain.dgn")
	ents, err := SceneV8ModelAtMaster(doc, doc.Models[0])
	if err != nil {
		t.Fatal(err)
	}
	line3d, cellHeaders := 0, 0
	for _, e := range ents {
		switch e.Kind {
		case scene.KindPolyline:
			line3d++
		case scene.KindCellDef:
			cellHeaders++
		}
	}
	if line3d < 100 {
		t.Fatalf("3D feature polylines=%d, want >=100", line3d)
	}
	if cellHeaders != 1 {
		t.Fatalf("CellHeader3d entities=%d, want 1 (0x56d2 named)", cellHeaders)
	}
}
