package dgn

import (
	"bytes"
	"encoding/binary"
	"math"
	"math/rand"
	"os"
	"testing"

	"github.com/flywave/go-dgn/dgn/element"
	"github.com/flywave/go-dgn/dgn/scene"
)

// Golden tests against the two real ODA-written v8 sample files (see
// analysis/03-dgn/findings.md D48: "v8 金样例待补" — these are they).
// Every number below was derived by byte-level inspection and is locked to
// catch regressions in the container → window → chunk → element pipeline.

func mustV8(t *testing.T, path string) *V8Document {
	t.Helper()
	f, err := Open(path)
	if err != nil {
		t.Fatalf("Open %s: %v", path, err)
	}
	doc, err := f.V8()
	if err != nil {
		t.Fatalf("V8 %s: %v", path, err)
	}
	if len(doc.Warnings) != 0 {
		t.Fatalf("%s: warnings: %v", path, doc.Warnings)
	}
	return doc
}

func TestV8GoldenAttach(t *testing.T) {
	doc := mustV8(t, "testdata/v8_attach.dgn")

	if doc.Header.Revision != 7 {
		t.Fatalf("revision = %d", doc.Header.Revision)
	}
	if len(doc.Header.Payload) != 1576 || len(doc.Header.Prefix) != 20 {
		t.Fatalf("header payload=%d prefix=%d", len(doc.Header.Payload), len(doc.Header.Prefix))
	}
	if len(doc.Index) != 2 {
		t.Fatalf("index = %+v", doc.Index)
	}
	if doc.Index[0].Short != "Model" || doc.Index[0].Long != "Default Model" {
		t.Fatalf("index[0] = %+v", doc.Index[0])
	}
	// D98 lead fields: modelNumber 0/1, timestamp 1228805552000 ms
	// (2008-12-09T06:52:32Z), flags bit0 set.
	if doc.Index[0].ModelNumber != 0 || doc.Index[0].TimestampMS != 1228805552000 || doc.Index[0].Flags != 1 {
		t.Fatalf("index[0] lead = %+v", doc.Index[0])
	}
	if doc.Index[1].Short != "Model for 2d elements" || doc.Index[1].Long != "" ||
		doc.Index[1].ModelNumber != 1 || doc.Index[1].TimestampMS != 1228805552000 {
		t.Fatalf("index[1] = %+v", doc.Index[1])
	}
	if len(doc.Models) != 2 {
		t.Fatalf("models = %d", len(doc.Models))
	}
	m0 := doc.Models[0]
	if m0.ID != 0 || m0.Name != "Default Model" || m0.Short != "Model" {
		t.Fatalf("model0 = %+v", m0)
	}
	if len(m0.Elements) != 12 || len(m0.Control) != 1 {
		t.Fatalf("model0 elements=%d control=%d", len(m0.Elements), len(m0.Control))
	}
	if doc.Models[1].ID != 1 || len(doc.Models[1].Elements) != 0 ||
		doc.Models[1].Name != "Model for 2d elements" {
		t.Fatalf("model1 = %+v", doc.Models[1])
	}

	// Graphics body census (locked): 5 lines, 5 linestrings, 2 arcs — all 3D.
	kinds := map[string]int{}
	for _, el := range m0.Elements {
		b, ok := el.Body.(*Body)
		if !ok {
			t.Fatalf("element %d: body %T", el.Record.ID, el.Body)
		}
		switch b.Value.(type) {
		case *element.Line3d:
			kinds["line3d"]++
		case *element.LineString3d:
			kinds["linestring3d"]++
		case *element.Arc3d:
			kinds["arc3d"]++
		}
	}
	want := map[string]int{"line3d": 5, "linestring3d": 5, "arc3d": 2}
	for k, v := range want {
		if kinds[k] != v {
			t.Fatalf("kind %s = %d, want %d (all: %v)", k, kinds[k], v, kinds)
		}
	}

	// Chunk capacity census (locked).
	wantChunks := map[string]int{
		"Dgn^Nm/$1":                29,
		"Dgn^Nm/$2":                32,
		"Dgn^NmA/$1":               2,
		"Dgn^NmA/$2":               5,
		"Dgn-Md/#000000/Dgn^G/$1":  12,
		"Dgn-Md/#000000/Dgn^C/$1":  1,
		"Dgn-Md/#000000/Dgn^CA/$1": 0,
	}
	for path, cap := range wantChunks {
		ch, ok := doc.Chunks[path]
		if !ok {
			t.Fatalf("chunk %q missing (have %d)", path, len(doc.Chunks))
		}
		if ch.Capacity != uint32(cap) {
			t.Fatalf("chunk %q capacity = %d, want %d", path, ch.Capacity, cap)
		}
	}
	// D96 header words: the legacy attach writer stamps [count][flags][0][0].
	for path, ch := range doc.Chunks {
		if ch.X != 0 || ch.Y != 0 {
			t.Fatalf("chunk %q x/y = %d/%d, want 0/0", path, ch.X, ch.Y)
		}
	}
	// The two table chunks fill their capacity exactly.
	if len(doc.Tables) != 29+32 {
		t.Fatalf("tables = %d", len(doc.Tables))
	}
	// Free space map and ODA signature pass through raw.
	if len(doc.Raw["Dgn~S"]) != 208 || len(doc.Raw["Oda~SH"]) != 16 {
		t.Fatalf("raw streams: Dgn~S=%d Oda~SH=%d", len(doc.Raw["Dgn~S"]), len(doc.Raw["Oda~SH"]))
	}
}

func TestV8GoldenAttach1(t *testing.T) {
	doc := mustV8(t, "testdata/v8_attach1.dgn")

	if doc.Header.Revision != 21 {
		t.Fatalf("revision = %d", doc.Header.Revision)
	}
	if len(doc.Index) != 1 || doc.Index[0].Short != "Default" || doc.Index[0].Long != "Master Model" {
		t.Fatalf("index = %+v", doc.Index)
	}
	if len(doc.Models) != 1 {
		t.Fatalf("models = %d", len(doc.Models))
	}
	m := doc.Models[0]
	if m.Name != "Master Model" || m.Short != "Default" {
		t.Fatalf("model = %+v", m)
	}
	if len(m.Elements) != 3 || len(m.Control) != 1 {
		t.Fatalf("elements=%d control=%d", len(m.Elements), len(m.Control))
	}
	if len(doc.Tables) != 50 {
		t.Fatalf("tables = %d", len(doc.Tables))
	}
	// D96 save-shape family: [count][flags][x][count] with x=1 on the
	// control/file-table chunks, [count][3][0][0] on graphics.
	if ch := doc.Chunks["Dgn^Nm/$1"]; ch == nil || ch.X != 1 || ch.Y != 50 {
		t.Fatalf("Dgn^Nm/$1 header = %+v", ch)
	}
	if ch := doc.Chunks[m.Storage+"/Dgn^C/$1"]; ch == nil || ch.X != 1 || ch.Y != 1 {
		t.Fatalf("Dgn^C/$1 header = %+v", ch)
	}
	if ch := doc.Chunks[m.Storage+"/Dgn^G/$1"]; ch == nil || ch.X != 0 || ch.Y != 0 {
		t.Fatalf("Dgn^G/$1 header = %+v", ch)
	}

	// Graphics census: one complex BSpline curve header + its pole and knot
	// records (types 27/21/26 of the v8 element type table).
	types := map[uint16]int{}
	var bsCurve, bsKnots bool
	for _, el := range m.Elements {
		types[el.Record.Type]++
		b, ok := el.Body.(*Body)
		if !ok {
			continue
		}
		switch b.Value.(type) {
		case *element.BSplineCurve:
			bsCurve = true
		case *element.BSplineArray:
			bsKnots = true
		}
	}
	if !bsCurve || !bsKnots {
		t.Fatalf("bspline census: curve=%v knots=%v types=%v", bsCurve, bsKnots, types)
	}
	if types[27] != 1 || types[21] != 1 || types[26] != 1 {
		t.Fatalf("types = %v", types)
	}
}

// TestV8GoldenEveryChunkFillsCapacity pins the window-decode invariant: with
// the shared sliding window every element chunk's walk consumes its full
// declared capacity (earlier partial decodes were window artifacts).
func TestV8GoldenEveryChunkFillsCapacity(t *testing.T) {
	for _, path := range []string{"testdata/v8_attach.dgn", "testdata/v8_attach1.dgn", "testdata/v8_odwriteex.dgn"} {
		doc := mustV8(t, path)
		for p, ch := range doc.Chunks {
			if ch.Capacity == 0 {
				continue
			}
			// Element-bearing chunks must fill exactly; non-element table
			// chunks (Dgn^NmA name heaps) legitimately stop at A≠0.
			if len(ch.Heap) == 0 && uint32(len(ch.Offsets)) != ch.Capacity {
				t.Errorf("%s %s: offsets=%d capacity=%d", path, p, len(ch.Offsets), ch.Capacity)
			}
		}
	}
}

func TestV8ModelStorageID(t *testing.T) {
	cases := map[string]struct {
		id uint64
		ok bool
	}{
		"Dgn-Md":          {0, false},
		"Dgn-Md/#000000":  {0, true},
		"Dgn-Md/#000001":  {1, true},
		"Dgn-Md/#deadbe":  {0xdeadbe, true},
		"Dgn-Md/#00000g":  {0, false},
		"Dgn-Md/#00000":   {0, false},
		"Dgn-Md/#0000000": {0, false},
		"other/#000000":   {0, false},
	}
	for path, want := range cases {
		id, ok := modelStorageID(path)
		if ok != want.ok || (ok && id != want.id) {
			t.Fatalf("%s: got %d,%v want %d,%v", path, id, ok, want.id, want.ok)
		}
	}
}

func TestParseMixIndexSynthetic(t *testing.T) {
	// attach1 golden record shape, rebuilt field-by-field per D98:
	// envelope + lead16 {flags,field,modelNumber,timestamp} + name header 16B
	// {entrySize,shortLen,longLen,extraLen,field,lastSlot} + names + extra.
	b := []byte{
		0x11, 0xba, 0x00, 0xaa, 0x04, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		// lead16: flags=0, field=1, modelNumber=0, timestamp=0
		0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		// name header: entrySize=0x56, shortLen=14, longLen=24, extraLen=16, field=0, lastSlot=0x03e8ceb8
		0x56, 0x00, 0x0e, 0x00, 0x18, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0xb8, 0xce, 0xe8, 0x03,
	}
	u16 := func(v uint16) { b = binary.LittleEndian.AppendUint16(b, v) }
	u32 := func(v uint32) { b = binary.LittleEndian.AppendUint32(b, v) }
	f64 := func(v float64) { b = binary.LittleEndian.AppendUint64(b, math.Float64bits(v)) }
	b = b[:16]
	u16(0)
	u16(1)
	u32(0)
	f64(0) // lead16
	u16(0x56)
	u16(14)
	u32(24)
	u16(16)
	u16(0)
	u32(0x03e8ceb8) // name header
	for _, r := range []rune("Default") {
		u16(uint16(r))
	}
	for _, r := range []rune("Master Model") {
		u16(uint16(r))
	}
	u32(0x40) // extra tail block, 16 bytes
	for i := 0; i < 3; i++ {
		u32(0)
	}
	idx := parseMixIndex(b)
	if len(idx) != 1 {
		t.Fatalf("idx = %+v", idx)
	}
	if idx[0].Short != "Default" || idx[0].Long != "Master Model" {
		t.Fatalf("names = %+v", idx[0])
	}
	if idx[0].ModelNumber != 0 || idx[0].TimestampMS != 0 || idx[0].Flags != 0 {
		t.Fatalf("lead = %+v", idx[0])
	}
	if parseMixIndex([]byte("garbage")) != nil {
		t.Fatal("garbage accepted")
	}
}

// TestV8DocumentPanicFree feeds mutated/truncated golden containers through
// the full pipeline: errors and partial documents are fine, panics are not.
func TestV8DocumentPanicFree(t *testing.T) {
	rng := rand.New(rand.NewSource(0x0D68))
	raw, err := os.ReadFile("testdata/v8_attach1.dgn")
	if err != nil {
		t.Fatal(err)
	}
	odw, err := os.ReadFile("testdata/v8_odwriteex.dgn")
	if err != nil {
		t.Fatal(err)
	}
	for i := 0; i < 300; i++ {
		src := raw
		if i%2 == 1 {
			src = odw
		}
		mut := append([]byte(nil), src...)
		for k := 0; k < 1+rng.Intn(8); k++ {
			pos := 512 + rng.Intn(len(mut)-512)
			mut[pos] = byte(rng.Intn(256))
		}
		if rng.Intn(6) == 0 {
			mut = mut[:512+rng.Intn(len(mut)-512)]
		}
		mustNoPanic(t, "V8/mutated", i, func() {
			if f, err := OpenBytes(mut); err == nil {
				_, _ = f.V8()
			}
		})
	}
}

// TestV8SceneGolden feeds the attach1 graphics chunk through the scene
// bridge: the BSpline curve assembly must surface as a KindBSplineCurve
// entity built from the poles/knots records that follow it in the chunk.
func TestV8SceneGolden(t *testing.T) {
	f, err := Open("testdata/v8_attach1.dgn")
	if err != nil {
		t.Fatal(err)
	}
	doc, err := f.V8()
	if err != nil {
		t.Fatal(err)
	}
	m := doc.Models[0]
	ch, ok := doc.Chunks[m.Storage+"/Dgn^G/$1"]
	if !ok {
		t.Fatal("graphics chunk missing")
	}
	ents, err := SceneV8(ch.Space, Dir{Base: 0, Offsets: ch.Offsets})
	if err != nil {
		t.Fatal(err)
	}
	kinds := map[string]int{}
	for _, e := range ents {
		kinds[e.Kind.String()]++
	}
	if len(ents) != 1 || kinds["BSplineCurve"] != 1 {
		t.Fatalf("kinds = %v", kinds)
	}
	if len(ents[0].Points) != 17 || len(ents[0].Knots) != 21 || ents[0].Degree != 3 {
		t.Fatalf("curve: poles=%d knots=%d degree=%d",
			len(ents[0].Points), len(ents[0].Knots), ents[0].Degree)
	}
}

// TestV8SceneAttachGolden locks the attach graphics scene histogram: all
// 12 elements route as 3D (display-header bit11), 5 segments + 5 polylines
// + 2 arcs.
func TestV8SceneAttachGolden(t *testing.T) {
	f, err := Open("testdata/v8_attach.dgn")
	if err != nil {
		t.Fatal(err)
	}
	doc, err := f.V8()
	if err != nil {
		t.Fatal(err)
	}
	m := doc.Models[0]
	ch, ok := doc.Chunks[m.Storage+"/Dgn^G/$1"]
	if !ok {
		t.Fatal("graphics chunk missing")
	}
	ents, err := SceneV8(ch.Space, Dir{Base: 0, Offsets: ch.Offsets})
	if err != nil {
		t.Fatal(err)
	}
	got := map[scene.Kind]int{}
	for _, e := range ents {
		if e.Dim != 3 {
			t.Errorf("entity %d dim=%d, want 3", e.ID, e.Dim)
		}
		got[e.Kind]++
	}
	want := map[scene.Kind]int{
		scene.KindSegment:  5,
		scene.KindPolyline: 5,
		scene.KindArc:      2,
	}
	for k, n := range want {
		if got[k] != n {
			t.Errorf("kind %v: %d want %d (all %v)", k, got[k], n, got)
		}
	}
}

// TestV8GoldenOdwriteEx locks the ODA-25.4-written sample (odwriteex.dgn):
// clean per-stream zlib frames with valid adlers (D97), save-shape chunk
// headers (D96), and a single "Master Model" 2D model.
func TestV8GoldenOdwriteEx(t *testing.T) {
	doc := mustV8(t, "testdata/v8_odwriteex.dgn")

	if doc.Header.Revision != 4 {
		t.Fatalf("revision = %d", doc.Header.Revision)
	}
	if len(doc.Index) != 1 || doc.Index[0].Short != "Model" || doc.Index[0].Long != "Master Model" {
		t.Fatalf("index = %+v", doc.Index)
	}
	if doc.Index[0].TimestampMS != 1285258852000 {
		t.Fatalf("timestamp = %v", doc.Index[0].TimestampMS)
	}
	if len(doc.Models) != 1 || doc.Models[0].Name != "Master Model" {
		t.Fatalf("models = %+v", doc.Models)
	}
	m := doc.Models[0]
	if len(m.Elements) != 4 || len(m.Control) != 0 || len(doc.Tables) != 36 {
		t.Fatalf("elements=%d control=%d tables=%d", len(m.Elements), len(m.Control), len(doc.Tables))
	}
	// D96 header shapes: G = save shape [count][2][1][count], C = the
	// dcad0 empty-block init [0][2][1][0].
	if ch := doc.Chunks[m.Storage+"/Dgn^G/$1"]; ch == nil || ch.Capacity != 4 ||
		ch.Flags != 2 || ch.X != 1 || ch.Y != 4 {
		t.Fatalf("G chunk = %+v", ch)
	}
	if ch := doc.Chunks[m.Storage+"/Dgn^C/$1"]; ch == nil || ch.Capacity != 0 ||
		ch.Flags != 2 || ch.X != 1 || ch.Y != 0 || len(ch.Space) != 0 {
		t.Fatalf("C chunk = %+v", ch)
	}
	// Graphics census: 3 lines + 1 ellipse, decoded as 2D (no display
	// header → ext=0 → Group2D3D variant 0).
	kinds := map[string]int{}
	for _, el := range m.Elements {
		b := el.Body.(*Body)
		switch v := b.Value.(type) {
		case *element.Line:
			kinds["line"]++
		case *element.Ellipse:
			kinds["ellipse"]++
		default:
			t.Fatalf("unexpected body %T", v)
		}
	}
	if kinds["line"] != 3 || kinds["ellipse"] != 1 {
		t.Fatalf("kinds = %v", kinds)
	}
}

// TestV8GoldenLevels locks the level-table extraction (D101): rows under
// the (96,1) LevelTable, names from the trailing ASCII name record, and
// the element-header Sub ↔ row Number mapping.
func TestV8GoldenLevels(t *testing.T) {
	attach := mustV8(t, "testdata/v8_attach.dgn")
	if len(attach.Levels) != 5 {
		t.Fatalf("attach levels = %d: %+v", len(attach.Levels), attach.Levels)
	}
	want := map[uint32]string{
		64: "Default",
		1:  "ExDgnCreate level 1",
		2:  "XRef Level 1",
		3:  "XRef Level 2",
		4:  "XRef Level 3",
	}
	for num, name := range want {
		if got := attach.LevelName(num); got != name {
			t.Errorf("attach LevelName(%d) = %q, want %q", num, got, name)
		}
	}
	// Graphics elements carry Sub=64 (Default) or 2..4 (XRef levels).
	subs := map[uint32]int{}
	for _, el := range attach.Models[0].Elements {
		subs[el.Record.Subtype]++
	}
	if subs[64] != 9 || subs[2] != 1 || subs[3] != 1 || subs[4] != 1 {
		t.Fatalf("attach Sub census = %v", subs)
	}

	a1 := mustV8(t, "testdata/v8_attach1.dgn")
	if len(a1.Levels) != 1 || a1.Levels[0].Name != "Default" || a1.Levels[0].Number != 64 {
		t.Fatalf("attach1 levels = %+v", a1.Levels)
	}
	if a1.LevelName(64) != "Default" {
		t.Fatalf("attach1 LevelName(64) = %q", a1.LevelName(64))
	}

	odw := mustV8(t, "testdata/v8_odwriteex.dgn")
	if len(odw.Levels) != 1 || odw.Levels[0].Name != "0" || odw.LevelName(64) != "0" {
		t.Fatalf("odwriteex levels = %+v", odw.Levels)
	}
}

// TestV8GoldenDesign locks the OdDgDesignFileHeaderData decode from the
// Dgn~H stream (D103 offset table): initialize defaults, per-file counters,
// the 3D flag cross-checked against the decoded geometry, and the
// prefix==body-head identity.
func TestV8GoldenDesign(t *testing.T) {
	odw := mustV8(t, "testdata/v8_odwriteex.dgn")
	d := odw.Design
	if d == nil {
		t.Fatal("design header missing")
	}
	if d.WordA != 1 || d.WordB != 4 || d.Version != 8 || d.SubVersion != 0x68 || d.Format != 2 {
		t.Fatalf("defaults: %+v", d)
	}
	if d.OriginalFormat != 0 || d.DefaultModelIs3D != 0 || d.DefaultModelID != 0 || d.HighestModelID != 0 {
		t.Fatalf("odwriteex fields: %+v", d)
	}
	if d.LastSaveTimeMS != 1378721198936 {
		t.Fatalf("lastSaveTime = %v", d.LastSaveTimeMS)
	}
	if !bytes.Equal(odw.Header.Prefix, d.Raw[:20]) {
		t.Fatal("Dgn~H prefix is not the body head")
	}
	if len(d.Raw) != 0x63C {
		t.Fatalf("body = %d bytes, want 1596", len(d.Raw))
	}

	attach := mustV8(t, "testdata/v8_attach.dgn")
	if attach.Design.DefaultModelIs3D != 1 || attach.Design.HighestModelID != 1 ||
		attach.Design.SubVersion != 0x66 || attach.Design.OriginalFormat != 2 {
		t.Fatalf("attach design: %+v", attach.Design)
	}
	if attach.Design.LastSaveTimeMS != 1340276520390 {
		t.Fatalf("attach lastSaveTime = %v", attach.Design.LastSaveTimeMS)
	}

	a1 := mustV8(t, "testdata/v8_attach1.dgn")
	if a1.Design.DefaultModelIs3D != 1 || a1.Design.HighestUniqueID != 333 ||
		a1.Design.LastSaveTimeMS != 1183381554450 {
		t.Fatalf("attach1 design: %+v", a1.Design)
	}
}

// TestV8GoldenMasterUnits locks the master-unit pipeline (D104): the UOR
// resolution from the type-9 TCB body, the per-model unit scale from the
// type-66 AppData element, and the resulting master-coordinate ranges.
func TestV8GoldenMasterUnits(t *testing.T) {
	attach := mustV8(t, "testdata/v8_attach.dgn")
	if attach.UorPerMaster != 10000 {
		t.Fatalf("uorPerMaster = %v", attach.UorPerMaster)
	}
	s := attach.Models[0].Settings
	if !s.Present || s.SubUnitsPerUor != 0.1 {
		t.Fatalf("attach settings = %+v", s)
	}
	ents, err := SceneV8ModelAtMaster(attach, attach.Models[0])
	if err != nil {
		t.Fatal(err)
	}
	if len(ents) != 12 {
		t.Fatalf("entities = %d", len(ents))
	}
	maxC := -math.MaxFloat64
	for _, e := range ents {
		for _, p := range e.Points {
			for _, c := range []float64{p.X, p.Y, p.Z} {
				if c > maxC {
					maxC = c
				}
			}
		}
	}
	if maxC < 3.1e6 || maxC > 3.2e6 {
		t.Fatalf("attach master max = %g, want ~3.15e6 (315 km at 0.1 m units)", maxC)
	}

	a1 := mustV8(t, "testdata/v8_attach1.dgn")
	if !a1.Models[0].Settings.Present || a1.Models[0].Settings.SubUnitsPerUor != 0.1 {
		t.Fatalf("attach1 settings = %+v", a1.Models[0].Settings)
	}

	odw := mustV8(t, "testdata/v8_odwriteex.dgn")
	if odw.Models[0].Settings.Present {
		t.Fatalf("odwriteex should have no AppData settings: %+v", odw.Models[0].Settings)
	}
	if odw.Models[0].Settings.SubUnitsPerUor != 1.0 {
		t.Fatalf("odwriteex default units = %v", odw.Models[0].Settings.SubUnitsPerUor)
	}
	odwEnts, err := SceneV8ModelAtMaster(odw, odw.Models[0])
	if err != nil {
		t.Fatal(err)
	}
	if len(odwEnts) != 4 {
		t.Fatalf("odwriteex entities = %d", len(odwEnts))
	}
}

// TestV8GoldenViews locks the view pipeline (D105): 16 views (8 quadrant-
// tiled + 8 full-screen), view rotations identity/45°, and level masks
// showing all 64 levels.
func TestV8GoldenViews(t *testing.T) {
	attach := mustV8(t, "testdata/v8_attach.dgn")
	if len(attach.Views) != 16 || len(attach.ViewLevelMasks) != 16 {
		t.Fatalf("views=%d masks=%d", len(attach.Views), len(attach.ViewLevelMasks))
	}
	// every view's tile rectangle stays within [0,1]
	for _, v := range attach.Views {
		for _, c := range v.Tile {
			if c < 0 || c > 1.001 {
				t.Fatalf("tile out of range: %v", v.Tile)
			}
		}
	}
	// tiled views occupy quadrants; fullscreen views are [0,0,1,1]
	tiled, fullscreen := 0, 0
	for _, v := range attach.Views {
		if v.Tile == [4]float64{0, 0, 1, 1} {
			fullscreen++
		} else {
			tiled++
		}
	}
	if tiled != 4 || fullscreen != 12 {
		t.Fatalf("tiled=%d fullscreen=%d", tiled, fullscreen)
	}
	// first tiled view is the identity rotation (Top); the second carries
	// the 45° pair
	tiledViews := attach.Views[:0:0]
	for _, v := range attach.Views {
		if v.Tile != [4]float64{0, 0, 1, 1} {
			tiledViews = append(tiledViews, v)
		}
	}
	ident := [9]float64{1, 0, 0, 0, 1, 0, 0, 0, 1}
	if tiledViews[0].Rotation != ident {
		t.Fatalf("tiled view0 rotation = %v", tiledViews[0].Rotation)
	}
	if math.Abs(tiledViews[1].Rotation[0]-math.Sqrt2/2) > 1e-6 {
		t.Fatalf("tiled view1 rot0 = %v", tiledViews[1].Rotation[0])
	}
	for _, lm := range attach.ViewLevelMasks {
		if lm.BitCount != 64 || lm.Mask != 0xFFFFFFFFFFFFFFFF {
			t.Fatalf("mask: %+v", lm)
		}
		if !lm.Visible(0) || !lm.Visible(63) {
			t.Fatal("levels 0/63 should be visible")
		}
	}
}
