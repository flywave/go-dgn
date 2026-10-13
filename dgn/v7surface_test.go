package dgn

import (
	"testing"

	"github.com/flywave/go-dgn/dgn/scene"
)

// Synthetic v7 type-24 fixtures (D131). Real-sample corpus for type 24 is
// zero (the 16MB golden sample carries none), but the header layout is the
// GDAL-authoritative one (dgnread L943-972; go-dgn noted their *556 typo
// already) and the follower convention mirrors the type-27 curve assembly
// proven on 2522 real curves in the golden sample.

// surfaceFixture builds [24 header, 26 u-knots, 21 poles] with no v-knots
// and no weights: a 3×2 bilinear (order 2×2) open clamped patch.
func surfaceFixture(t *testing.T) []V7Element {
	t.Helper()
	// header: descWords i32@32, uflags@36 (order bits 0x0f, rational 0x40,
	// closed 0x80), curveType@37, numPolesU@38, numKnotsU@40, ruleU@42,
	// vflags@44, numPolesV@46, numKnotsV@48, ruleV@50, numBounds@52.
	body := make([]byte, 54)
	V7PutInt32(body[32:], 0)
	body[36] = 0 // u: order 2, open, non-rational
	body[38] = 3 // NumPolesU
	body[40] = 1 // NumKnotsU
	body[44] = 0 // v: order 2
	body[46] = 2 // NumPolesV
	hdr := V7Element{Type: 24, Words: uint16(len(body) / 2), Body: body}

	// u-knots: one interior knot 0.5 (i32/2^31-1 encoding)
	ubody := make([]byte, 36)
	V7PutInt32(ubody[32:], 1<<30) // 0.25? — 1<<30 / (2^31-1) ≈ 0.5
	uknots := V7Element{Type: 26, Words: uint16(len(ubody) / 2), Body: ubody}

	// poles: 6 3D points, row-major v-major: [v][u]
	pbody := make([]byte, 34+6*12)
	pbody[32] = 6
	pbody[33] = 0
	coords := [6][3]int32{
		{0, 0, 0}, {10, 0, 0}, {20, 0, 2},
		{0, 10, 0}, {10, 10, 1}, {20, 10, 3},
	}
	for i, c := range coords {
		V7PutInt32(pbody[34+i*12:], c[0])
		V7PutInt32(pbody[34+i*12+4:], c[1])
		V7PutInt32(pbody[34+i*12+8:], c[2])
	}
	poles := V7Element{Type: 21, Words: uint16(len(pbody) / 2), Body: pbody}

	return []V7Element{hdr, uknots, poles}
}

func TestV7SurfaceAssembly(t *testing.T) {
	els := surfaceFixture(t)
	consumed, surfaces := assembleV7BSplineSurfaces(els)
	if len(surfaces) != 1 {
		t.Fatalf("assembled %d surfaces, want 1", len(surfaces))
	}
	a := surfaces[els[0].Offset]
	if a.polesU != 3 || a.polesV != 2 || a.uDegree != 1 || a.vDegree != 1 {
		t.Fatalf("dims: %+v", a)
	}
	if len(a.poles) != 6 {
		t.Fatalf("poles %d", len(a.poles))
	}
	// u full knots: order 2 zeros + [0.5] + order 2 ones
	if len(a.uKnots) != 5 || a.uKnots[2] <= 0.4 || a.uKnots[2] >= 0.6 ||
		a.uKnots[0] != 0 || a.uKnots[4] != 1 {
		t.Fatalf("uKnots %v", a.uKnots)
	}
	if len(a.vKnots) != 4 || a.vKnots[0] != 0 || a.vKnots[3] != 1 {
		t.Fatalf("vKnots %v", a.vKnots)
	}
	if a.weights != nil {
		t.Fatal("non-rational fixture got weights")
	}
	if !consumed[els[1].Offset] || !consumed[els[2].Offset] {
		t.Fatal("siblings not consumed")
	}
}

func TestV7SurfaceSceneDispatch(t *testing.T) {
	els := surfaceFixture(t)
	top, err := GroupV7Elements(els)
	if err != nil {
		t.Fatal(err)
	}
	doc := V7Document{Header: V7Header{Is3D: true}, Elements: els, Top: top}
	ents := SceneV7(doc)
	var surf *scene.Entity
	other := 0
	for i := range ents {
		if ents[i].Kind == scene.KindBSplineSurface {
			surf = &ents[i]
		} else {
			other++
		}
	}
	if surf == nil {
		t.Fatal("no BSplineSurface entity (silent drop?)")
	}
	if other != 0 {
		t.Fatalf("%d stray entities (consumed poles leaked as polylines?)", other)
	}
	if surf.BSplineSurface == nil || len(surf.BSplineSurface.Poles) != 2 ||
		len(surf.BSplineSurface.Poles[0]) != 3 {
		t.Fatalf("pole grid wrong: %+v", surf.BSplineSurface)
	}
	if surf.BSplineSurface.Poles[1][2].Z != 3 {
		t.Fatalf("pole [1][2] = %+v", surf.BSplineSurface.Poles[1][2])
	}

	// failed assembly: header alone still emits a metadata-only entity
	alone := []V7Element{els[0]}
	topA, _ := GroupV7Elements(alone)
	ents2 := SceneV7(V7Document{Header: V7Header{Is3D: true}, Elements: alone, Top: topA})
	if len(ents2) != 1 || ents2[0].Kind != scene.KindBSplineSurface ||
		ents2[0].BSplineSurface != nil {
		t.Fatalf("orphan header must emit metadata-only surface: %+v", ents2)
	}
}

func TestV7SurfaceClosedRejected(t *testing.T) {
	els := surfaceFixture(t)
	els[0].Body[36] = 0x80 // u closed
	_, surfaces := assembleV7BSplineSurfaces(els)
	if len(surfaces) != 0 {
		t.Fatal("closed surface must be rejected (better-missing-than-wrong)")
	}
}

// TestV7SurfaceMasterScale checks the TCB mapping reaches surface poles:
// a TCB with UORPerSubunit=SubunitsPerMaster=1 (scale 1) keeps the fixture
// coordinates; the assertion pins that SceneV7AtMaster walks the pole grid
// without dropping it.
func TestV7SurfaceMasterScale(t *testing.T) {
	els := surfaceFixture(t)
	top, _ := GroupV7Elements(els)
	doc := V7Document{Header: V7Header{Is3D: true}, Elements: els, Top: top}
	doc.TCB = V7TCB{Dimension: 3, UORPerSubunit: 1, SubunitsPerMaster: 1, Scale: 1}
	ents := SceneV7AtMaster(doc)
	var surf *scene.Entity
	for i := range ents {
		if ents[i].Kind == scene.KindBSplineSurface {
			surf = &ents[i]
		}
	}
	if surf == nil || surf.BSplineSurface == nil ||
		surf.BSplineSurface.Poles[1][2].Z != 3 {
		t.Fatalf("master-scale pole walk broken: %+v", surf)
	}
}

// TestV8SurfaceDispatchFallback pins the v8 type-24 path (D132): the
// 9×u32 surface header decodes but its field semantics are unknown, so
// the scene emits a metadata-only BSplineSurface entity instead of the
// old silent drop.
func TestV8SurfaceDispatchFallback(t *testing.T) {
	hdr := buildHeader(Header{Type: 24, B: 18, C: 18, ID: 7})
	body := []byte{}
	for _, v := range []uint32{1, 2, 3, 4, 5, 6, 7, 8, 9} {
		body = u32le(body, v)
	}
	got, err := SceneV8(join(hdr, body), Dir{Base: 0, Offsets: []uint32{0}})
	if err != nil {
		t.Fatal(err)
	}
	if len(got) != 1 || got[0].Kind != scene.KindBSplineSurface {
		t.Fatalf("v8 surface dropped or misclassified: %+v", got)
	}
	if got[0].BSplineSurface != nil {
		t.Fatal("undecoded header must not fabricate poles")
	}
}
