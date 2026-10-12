package dgn

import (
	"encoding/binary"
	"math"
	"testing"

	"github.com/flywave/go-dgn/dgn/element"
	"github.com/flywave/go-dgn/dgn/scene"
	"github.com/flywave/go-dgn/internal/le"
)

// buildMeshChunkFixture assembles a synthetic graphics chunk: one type-105
// head (style 1, FaceLoops) followed by a 101 header, a 103 point block
// (4 vertices) and a 102 index block.
func buildMeshChunkFixture(t testingTB) ([]byte, Dir) {
	head := v8HeaderBytes(Header{Type: 105, Flag: 0, B: 20, C: 20, Sub: 1, ID: 1})
	head = binary.LittleEndian.AppendUint32(head, 8) // body i32 (MeshHeader.A)
	head = binary.LittleEndian.AppendUint32(head, 0)
	head = head[:20*2+4]

	mh := v8HeaderBytes(Header{Type: 101, B: 62, C: 62, ID: 2})
	mh = binary.LittleEndian.AppendUint16(mh, 1)
	mh = append(mh, make([]byte, 70)...)
	mh = binary.LittleEndian.AppendUint32(mh, 72)
	mh = binary.LittleEndian.AppendUint32(mh, 24)
	mh = binary.LittleEndian.AppendUint32(mh, 1)
	mh = binary.LittleEndian.AppendUint32(mh, 2)
	mh = binary.LittleEndian.AppendUint32(mh, 3)
	mh = mh[:62*2+4]

	dd := v8HeaderBytes(Header{Type: 103, B: 108, C: 108, ID: 3})
	dd = binary.LittleEndian.AppendUint16(dd, 1)
	dd = append(dd, make([]byte, 70)...)
	dd = binary.LittleEndian.AppendUint32(dd, 12) // 12 f64 = 4 points
	dd = binary.LittleEndian.AppendUint32(dd, 1)
	dd = binary.LittleEndian.AppendUint32(dd, 2)
	dd = binary.LittleEndian.AppendUint32(dd, 3)
	for _, v := range []float64{0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0} {
		dd = binary.LittleEndian.AppendUint64(dd, math.Float64bits(v))
	}
	dd = dd[:108*2+4]

	id := v8HeaderBytes(Header{Type: 102, B: 66, C: 66, ID: 4})
	id = binary.LittleEndian.AppendUint16(id, 1)
	id = append(id, make([]byte, 70)...)
	id = binary.LittleEndian.AppendUint32(id, 3) // 3 i32 (face indices [?])
	id = binary.LittleEndian.AppendUint32(id, 1)
	id = binary.LittleEndian.AppendUint32(id, 2)
	id = binary.LittleEndian.AppendUint32(id, 3)
	id = binary.LittleEndian.AppendUint32(id, 7)
	id = binary.LittleEndian.AppendUint32(id, 8)
	id = binary.LittleEndian.AppendUint32(id, 9)
	id = id[:66*2+4]

	var buf []byte
	buf = append(buf, head...)
	buf = append(buf, mh...)
	buf = append(buf, dd...)
	buf = append(buf, id...)

	space := join(binary.LittleEndian.AppendUint32(nil, 4), binary.LittleEndian.AppendUint32(nil, 0), buf)
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
	if len(parsed) != 4 {
		t.Fatalf("parsed = %d", len(parsed))
	}
	meshes := assembleV8Meshes(parsed)
	if len(meshes) != 1 {
		t.Fatalf("meshes = %d", len(meshes))
	}
	m := meshes[0]
	if m.Style != 1 || m.A != 8 {
		t.Fatalf("head = %+v", m)
	}
	if len(m.Points) != 4 || m.Points[3] != [3]float64{0, 1, 0} {
		t.Fatalf("points = %v", m.Points)
	}
	if len(m.Ints) != 3 || m.Ints[2] != 9 {
		t.Fatalf("ints = %v", m.Ints)
	}

	// scene bridge: mesh head yields one KindSolid entity with the
	// vertices; the matrix children are consumed.
	ents, err := SceneV8(space, dir)
	if err != nil {
		t.Fatal(err)
	}
	if len(ents) != 1 || ents[0].Kind != scene.KindSolid || len(ents[0].Points) != 4 {
		t.Fatalf("entities = %+v", ents)
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
