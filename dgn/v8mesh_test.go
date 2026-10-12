package dgn

import (
	"encoding/binary"
	"math"
	"testing"

	"github.com/flywave/go-dgn/dgn/element"
	"github.com/flywave/go-dgn/dgn/scene"
	"github.com/flywave/go-dgn/internal/le"
)

// buildMeshChunkFixture assembles a synthetic graphics chunk with the
// real-file Matrix family layout (D111): 105 head + 101(family 2, row 3)
// + 103 (4 positions) + 101(family 1) + 102 (zero-terminated 1-based
// face table with a visibility flag).
func buildMeshChunkFixture(t testingTB) ([]byte, Dir) {
	head := v8HeaderBytes(Header{Type: 105, Flag: 0, B: 20, C: 20, Sub: 0x40, ID: 1})
	head = binary.LittleEndian.AppendUint32(head, 8) // body i32 (MeshHeader.A)
	head = binary.LittleEndian.AppendUint32(head, 0)
	head = head[:20*2+4]

	// 101 header: family 2 (positions), row 3
	mh := v8HeaderBytes(Header{Type: 101, B: 62, C: 62, ID: 2})
	mh = binary.LittleEndian.AppendUint16(mh, 1)
	mh = append(mh, make([]byte, 70)...)
	mh = binary.LittleEndian.AppendUint32(mh, 0) // sizeOfStruct
	mh = binary.LittleEndian.AppendUint32(mh, 3) // sizeOfRow
	mh = binary.LittleEndian.AppendUint32(mh, 1) // tag
	mh = binary.LittleEndian.AppendUint32(mh, 2) // indexFamily = positions
	mh = binary.LittleEndian.AppendUint32(mh, 0) // indexedBy
	mh = mh[:62*2+4]

	// 103: 4 positions (12 f64)
	dd := v8HeaderBytes(Header{Type: 103, B: 108, C: 108, ID: 3})
	dd = binary.LittleEndian.AppendUint16(dd, 1)
	dd = append(dd, make([]byte, 70)...)
	dd = binary.LittleEndian.AppendUint32(dd, 12)
	dd = binary.LittleEndian.AppendUint32(dd, 12)
	dd = binary.LittleEndian.AppendUint32(dd, 49)
	dd = binary.LittleEndian.AppendUint32(dd, 0)
	for _, v := range []float64{0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0} {
		dd = binary.LittleEndian.AppendUint64(dd, math.Float64bits(v))
	}
	dd = dd[:108*2+4]

	// 101 header: family 1 (face table)
	mh2 := v8HeaderBytes(Header{Type: 101, B: 62, C: 62, ID: 4})
	mh2 = binary.LittleEndian.AppendUint16(mh2, 1)
	mh2 = append(mh2, make([]byte, 70)...)
	mh2 = binary.LittleEndian.AppendUint32(mh2, 0)
	mh2 = binary.LittleEndian.AppendUint32(mh2, 1)
	mh2 = binary.LittleEndian.AppendUint32(mh2, 1)
	mh2 = binary.LittleEndian.AppendUint32(mh2, 1)
	mh2 = binary.LittleEndian.AppendUint32(mh2, 0xFFFFFFFF)
	mh2 = mh2[:62*2+4]

	// 102: faces [2,3,4] (1-based) + [4,1,-2] with a hidden-edge flag;
	// zero-terminated, indices cover exactly the 4 points.
	id := v8HeaderBytes(Header{Type: 102, B: 76, C: 76, ID: 5})
	id = binary.LittleEndian.AppendUint16(id, 1)
	id = append(id, make([]byte, 70)...)
	id = binary.LittleEndian.AppendUint32(id, 8)
	id = binary.LittleEndian.AppendUint32(id, 8)
	id = binary.LittleEndian.AppendUint32(id, 4386)
	id = binary.LittleEndian.AppendUint32(id, 0)
	for _, v := range []int32{2, 3, 4, 0, 4, 1, -2, 0} {
		id = binary.LittleEndian.AppendUint32(id, uint32(v))
	}
	id = id[:76*2+4]

	var buf []byte
	buf = append(buf, head...)
	buf = append(buf, mh...)
	buf = append(buf, dd...)
	buf = append(buf, mh2...)
	buf = append(buf, id...)

	space := join(binary.LittleEndian.AppendUint32(nil, 5), binary.LittleEndian.AppendUint32(nil, 0), buf)
	idx := BuildChunkIndex(space)
	return space, Dir{Base: 0, Offsets: idx.Offsets}
}

// testingTB is the minimal testing interface used by the fixture helper.
type testingTB interface {
	Helper()
	Fatalf(format string, args ...any)
}

func TestAssembleMeshes(t *testing.T) {
	space, dir := buildMeshChunkFixture(t)
	parsed, err := ParseAll(space, dir)
	if err != nil {
		t.Fatal(err)
	}
	if len(parsed) != 5 {
		t.Fatalf("parsed = %d", len(parsed))
	}
	meshes := assembleV8Meshes(parsed)
	if len(meshes) != 1 {
		t.Fatalf("meshes = %d", len(meshes))
	}
	m := meshes[0]
	if m.Style != 0x40 || m.A != 8 {
		t.Fatalf("head = %+v", m)
	}
	if len(m.Families) != 2 {
		t.Fatalf("families = %+v", m.Families)
	}
	if len(m.Points) != 4 || m.Points[3] != [3]float64{0, 1, 0} {
		t.Fatalf("points = %v", m.Points)
	}
	if len(m.Ints) != 8 || m.Ints[2] != 4 {
		t.Fatalf("ints = %v", m.Ints)
	}

	// scene bridge: mesh head yields one KindSolid entity with the
	// vertices; the matrix children are consumed. Faces are 0-based.
	ents, err := SceneV8(space, dir)
	if err != nil {
		t.Fatal(err)
	}
	if len(ents) != 1 || ents[0].Kind != scene.KindSolid || len(ents[0].Points) != 4 {
		t.Fatalf("entities = %+v", ents)
	}
	f := ents[0].Faces
	if len(f) != 2 || f[0][0] != 1 || f[0][1] != 2 || f[0][2] != 3 ||
		f[1][0] != 3 || f[1][1] != 0 || f[1][2] != 1 {
		t.Fatalf("faces = %v", f)
	}
}

func TestMeshDecoders(t *testing.T) {
	var buf []byte
	buf = binary.LittleEndian.AppendUint16(buf, 1)
	buf = append(buf, make([]byte, 70)...)
	buf = binary.LittleEndian.AppendUint32(buf, 72)
	buf = binary.LittleEndian.AppendUint32(buf, 24)
	buf = binary.LittleEndian.AppendUint32(buf, 1)
	buf = binary.LittleEndian.AppendUint32(buf, 2)
	buf = binary.LittleEndian.AppendUint32(buf, 3)
	mh, err := element.ReadMatrixHeader(le.New(buf))
	if err != nil {
		t.Fatal(err)
	}
	if mh.SizeOfStruct != 72 || mh.SizeOfRow != 24 || mh.Tag != 1 || mh.IndexFamily != 2 || mh.IndexedBy != 3 {
		t.Fatalf("header = %+v", mh)
	}

	buf = nil
	buf = binary.LittleEndian.AppendUint16(buf, 1)
	buf = append(buf, make([]byte, 70)...)
	buf = binary.LittleEndian.AppendUint32(buf, 3)
	buf = binary.LittleEndian.AppendUint32(buf, 1)
	buf = binary.LittleEndian.AppendUint32(buf, 2)
	buf = binary.LittleEndian.AppendUint32(buf, 3)
	buf = binary.LittleEndian.AppendUint32(buf, 7)
	buf = binary.LittleEndian.AppendUint32(buf, 8)
	buf = binary.LittleEndian.AppendUint32(buf, 9)
	mi, err := element.ReadMatrixIntData(le.New(buf))
	if err != nil {
		t.Fatal(err)
	}
	if mi.Count != 3 || len(mi.Values) != 3 || mi.Values[1] != 8 {
		t.Fatalf("intdata = %+v", mi)
	}
}

// TestMeshFacesRealLayout pins the D111 FaceLoops file layout, validated
// on 18 meshes across 4 Bentley samples: zero-terminated 1-based vertex
// lists, sign bit = edge visibility, family 2 = positions.
func TestMeshFacesRealLayout(t *testing.T) {
	m := &V8Mesh{
		Points: [][3]float64{{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0}},
		Families: []V8MatrixFamily{
			{Family: 2, Row: 3, Doubles: []float64{0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0}},
			{Family: 1, Row: 1, Ints: []int32{1, -2, 3, 0, 2, 3, 4, 0}},
		},
	}
	f := m.Faces()
	if len(f) != 2 || f[0][0] != 0 || f[0][1] != 1 || f[0][2] != 2 ||
		f[1][0] != 1 || f[1][2] != 3 {
		t.Fatalf("faces = %v", f)
	}

	// index out of [1, nPoints] rejects the whole table
	m.Families[1].Ints = []int32{1, 2, 9, 0}
	if f = m.Faces(); f != nil {
		t.Fatalf("oob faces = %v", f)
	}

	// short trailing face (<3 verts) is dropped
	m.Families[1].Ints = []int32{1, 2, 3, 0, 2, 3, 0}
	f = m.Faces()
	if len(f) != 1 || f[0][2] != 2 {
		t.Fatalf("short-tail faces = %v", f)
	}

	// an auxiliary UV family (row 2) must not enter Points…
	uv := &V8Mesh{
		Families: []V8MatrixFamily{
			{Family: 2, Row: 3, Doubles: []float64{0, 0, 1, 1, 0, 2, 2, 0, 3, 3, 0, 4}},
			{Family: 6, Row: 2, Doubles: []float64{0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6}},
		},
	}
	uv.finish()
	if len(uv.Points) != 4 {
		t.Fatalf("points polluted by aux family: %v", uv.Points)
	}

	// …and without an odd family there are no faces
	if f = uv.Faces(); f != nil {
		t.Fatalf("uv-only faces = %v", f)
	}
}

// TestMeshRealSample is the real-file regression: MeshData.dgn (Bentley
// sample, D111) holds 9 FaceLoops meshes — 35 positions and 24 quad faces
// each, families 2/4/6 + 1/3/5.
func TestMeshRealSample(t *testing.T) {
	f, err := Open("testdata/v8_meshdata.dgn")
	if err != nil {
		t.Skipf("sample absent: %v", err)
	}
	doc, err := f.V8()
	if err != nil {
		t.Fatal(err)
	}
	var meshes []*V8Mesh
	for _, m := range doc.Models {
		meshes = append(meshes, doc.Meshes(m)...)
	}
	if len(meshes) != 9 {
		t.Fatalf("meshes = %d", len(meshes))
	}
	for _, m := range meshes {
		if len(m.Points) != 35 {
			t.Fatalf("mesh %d points = %d", m.EntryID, len(m.Points))
		}
		faces := m.Faces()
		if len(faces) != 24 {
			t.Fatalf("mesh %d faces = %d", m.EntryID, len(faces))
		}
		for _, fc := range faces {
			if len(fc) != 4 {
				t.Fatalf("mesh %d face size %d", m.EntryID, len(fc))
			}
			for _, idx := range fc {
				if idx < 0 || int(idx) >= 35 {
					t.Fatalf("mesh %d face index %d", m.EntryID, idx)
				}
			}
		}
	}

	// scene bridge on the real file: 9 KindSolid entities with faces
	ents, err := SceneV8ModelAtMaster(doc, doc.Models[0])
	if err != nil {
		t.Fatal(err)
	}
	solids := 0
	for i := range ents {
		if ents[i].Kind == scene.KindSolid {
			solids++
			if len(ents[i].Faces) != 24 {
				t.Fatalf("scene mesh faces = %d", len(ents[i].Faces))
			}
		}
	}
	if solids != 9 {
		t.Fatalf("scene solids = %d", solids)
	}
}
