package dgn

import (
	"encoding/binary"
	"math"
	"math/rand"
	"testing"
)

// v8HeaderBytes builds a 36-byte element header.
func v8HeaderBytes(h Header) []byte {
	b := make([]byte, HeaderSize)
	binary.LittleEndian.PutUint32(b[0:], h.A)
	binary.LittleEndian.PutUint16(b[4:], h.Type)
	binary.LittleEndian.PutUint16(b[6:], h.Flag)
	binary.LittleEndian.PutUint32(b[8:], h.B)
	binary.LittleEndian.PutUint32(b[12:], h.C)
	binary.LittleEndian.PutUint32(b[16:], h.Sub)
	binary.LittleEndian.PutUint64(b[20:], h.ID)
	binary.LittleEndian.PutUint64(b[28:], h.Tail)
	return b
}

// v8LineRecord builds a minimal type-3 line element record (2D, no display
// header) whose total span equals B*2+4. words=32 carries the full 32-byte
// two-point body so the line decoder succeeds.
func v8LineRecord(id uint64, words uint32) []byte {
	h := Header{Type: 3, B: words, C: words, ID: id}
	rec := v8HeaderBytes(h)
	f64 := func(v float64) {
		rec = binary.LittleEndian.AppendUint64(rec, math.Float64bits(v))
	}
	f64(0)
	f64(0)
	f64(1)
	f64(1) // 2D line: two points
	for uint32(len(rec)) < words*2+4 {
		rec = append(rec, 0)
	}
	return rec[:words*2+4]
}

func TestParseV8ChunkRaw(t *testing.T) {
	var raw []byte
	raw = binary.LittleEndian.AppendUint32(raw, 2) // capacity
	raw = binary.LittleEndian.AppendUint32(raw, 0) // flags
	raw = append(raw, v8LineRecord(1, 32)...)
	raw = append(raw, v8LineRecord(2, 32)...)

	ch, err := ParseV8Chunk("$1", raw, &zipWindow{})
	if err != nil {
		t.Fatal(err)
	}
	if ch.Capacity != 2 || len(ch.Offsets) != 2 || ch.Heap != nil {
		t.Fatalf("cap=%d offs=%v heap=%d", ch.Capacity, ch.Offsets, len(ch.Heap))
	}
	if err := ch.ParseElements(); err != nil {
		t.Fatal(err)
	}
	if len(ch.Elements) != 2 || ch.Elements[1].Record.ID != 2 {
		t.Fatalf("elements = %d", len(ch.Elements))
	}
}

func TestParseV8ChunkCompressed(t *testing.T) {
	// The compressed payload is the pure record space: no count/flags prefix.
	inner := v8LineRecord(7, 32)

	framed := zipSegment(t, inner, nil)

	var raw []byte
	raw = binary.LittleEndian.AppendUint32(raw, 1) // capacity
	raw = binary.LittleEndian.AppendUint32(raw, 2) // flags
	raw = binary.LittleEndian.AppendUint32(raw, 0) // prefix u32 (U15)
	raw = binary.LittleEndian.AppendUint32(raw, 0) // prefix u32 (U15)
	raw = append(raw, framed...)

	ch, err := ParseV8Chunk("Dgn-Md/#000000/Dgn^G/$1", raw, &zipWindow{})
	if err != nil {
		t.Fatal(err)
	}
	if len(ch.Offsets) != 1 || len(ch.Space) != len(inner) {
		t.Fatalf("offs=%d space=%d", len(ch.Offsets), len(ch.Space))
	}
	if err := ch.ParseElements(); err != nil {
		t.Fatal(err)
	}
	if len(ch.Elements) != 1 || ch.Elements[0].Record.ID != 7 {
		t.Fatalf("elements = %+v", ch.Elements)
	}
}

func TestParseV8ChunkEmptySlotsAndHeap(t *testing.T) {
	var raw []byte
	raw = binary.LittleEndian.AppendUint32(raw, 2) // capacity: 1 real + 1 empty slot
	raw = binary.LittleEndian.AppendUint32(raw, 0)
	raw = append(raw, v8LineRecord(5, 32)...)
	// trailing empty slot: a bare 4-byte zero record (A=0, type=0, B=0),
	// followed by zero padding — capacity padding keeps the B-field window
	// of the walk inside zeros until the heap begins.
	raw = append(raw, 0, 0, 0, 0)
	raw = append(raw, 0, 0, 0, 0, 0, 0, 0, 0)
	// trailing heap: leading u32 ≠ 0
	raw = append(raw, []byte{0x1b, 0xa1, 0x00, 0x00, 0xde, 0xad}...)

	ch, err := ParseV8Chunk("$2", raw, &zipWindow{})
	if err != nil {
		t.Fatal(err)
	}
	if len(ch.Offsets) != 2 || ch.Offsets[1] != 68 {
		t.Fatalf("offs=%v", ch.Offsets)
	}
	// heap = zero padding (8B) + marker (6B)
	if ch.Heap == nil || len(ch.Heap) != 14 {
		t.Fatalf("heap = %v", ch.Heap)
	}
	if err := ch.ParseElements(); err != nil {
		t.Fatal(err)
	}
	if len(ch.Elements) != 1 || ch.Elements[0].Record.ID != 5 {
		t.Fatalf("elements = %d", len(ch.Elements))
	}
}

func TestParseV8ChunkGarbage(t *testing.T) {
	if _, err := ParseV8Chunk("$1", []byte{1, 2, 3}, &zipWindow{}); err == nil {
		t.Fatal("expected error for short chunk")
	}
	// zlib-looking garbage in the payload area: must not panic, may error.
	bad := make([]byte, 32)
	binary.LittleEndian.PutUint32(bad[0:], 1)
	binary.LittleEndian.PutUint32(bad[4:], 0)
	copy(bad[16:], []byte{0x78, 0x9c, 0xff, 0xff, 0xff})
	if _, err := ParseV8Chunk("$1", bad, &zipWindow{}); err == nil {
		t.Log("garbage chunk decoded without error")
	}
}

func TestV8ChunkWalkMatchesBuildChunkIndex(t *testing.T) {
	// The uncompressed-path walk (BuildChunkIndex, records start at 8) and
	// the compressed-path walk (records start at 0) must agree on shapes.
	var records []byte
	records = append(records, v8LineRecord(1, 32)...)
	records = append(records, v8LineRecord(2, 32)...)

	var raw []byte
	raw = binary.LittleEndian.AppendUint32(raw, 2)
	raw = binary.LittleEndian.AppendUint32(raw, 3)
	raw = append(raw, records...)

	idx := BuildChunkIndex(raw)
	ch, err := ParseV8Chunk("$1", raw, &zipWindow{})
	if err != nil {
		t.Fatal(err)
	}
	if len(idx.Offsets) != len(ch.Offsets) {
		t.Fatalf("legacy=%v v8=%v", idx.Offsets, ch.Offsets)
	}
	for i := range idx.Offsets {
		if idx.Offsets[i]-8 != ch.Offsets[i] {
			t.Fatalf("offset %d: legacy %d vs v8 %d", i, idx.Offsets[i], ch.Offsets[i])
		}
	}
}

func TestParseV8ChunkPanicFree(t *testing.T) {
	rng := rand.New(rand.NewSource(0x0D68))
	for i := 0; i < 400; i++ {
		buf := make([]byte, rng.Intn(200))
		rng.Read(buf)
		if rng.Intn(4) == 0 && len(buf) > 20 {
			copy(buf[16:], []byte{0x78, 0x9c})
		}
		mustNoPanic(t, "ParseV8Chunk/random", i, func() {
			if ch, err := ParseV8Chunk("$1", buf, &zipWindow{}); err == nil {
				_ = ch.ParseElements()
			}
		})
	}
}
