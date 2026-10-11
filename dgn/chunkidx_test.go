package dgn

import (
	"encoding/binary"
	"math"
	"testing"

	"github.com/flywave/go-dgn/dgn/element"
)

func entryBytes(sizeWords uint32, typ uint16, id uint64, body []byte) []byte {
	b := make([]byte, 4+2+2+4)
	binary.LittleEndian.PutUint32(b[0:], 0)
	binary.LittleEndian.PutUint16(b[4:], typ)
	binary.LittleEndian.PutUint16(b[6:], 0)
	binary.LittleEndian.PutUint32(b[8:], sizeWords)
	total := 4 + 2 + 2 + 4 + 4 + 4 + 8 + 8
	_ = total
	b = append(b, make([]byte, 4)...)
	b = append(b, make([]byte, 4)...)
	idb := make([]byte, 8)
	binary.LittleEndian.PutUint64(idb, id)
	b = append(b, idb...)
	b = append(b, make([]byte, 8)...)
	b = append(b, body...)
	need := int(sizeWords)*2 + 4
	if len(b) < need {
		b = append(b, make([]byte, need-len(b))...)
	}
	return b[:need]
}

func lineEntry(id uint64) []byte {
	body := make([]byte, 0, 32)
	for _, v := range []float64{1, 2, 3, 4} {
		fb := make([]byte, 8)
		binary.LittleEndian.PutUint64(fb, float64bitsOf(v))
		body = append(body, fb...)
	}
	return entryBytes(32, 3, id, body)
}

func float64bitsOf(v float64) uint64 {
	return math.Float64bits(v)
}

func chunkOf(count uint32, flags uint32, entries ...[]byte) []byte {
	b := make([]byte, 8)
	binary.LittleEndian.PutUint32(b[0:], count)
	binary.LittleEndian.PutUint32(b[4:], flags)
	for _, e := range entries {
		b = append(b, e...)
	}
	return b
}

func TestBuildChunkIndex(t *testing.T) {
	e0 := entryBytes(12, 3, 1, nil)
	e1 := entryBytes(20, 4, 2, nil)
	ch := chunkOf(2, 5, e0, e1)
	idx := BuildChunkIndex(ch)
	if idx.Flags != 5 {
		t.Fatalf("flags=%d", idx.Flags)
	}
	if len(idx.Offsets) != 2 || idx.Offsets[0] != 8 || idx.Offsets[1] != uint32(8+len(e0)) {
		t.Fatalf("offsets=%v", idx.Offsets)
	}
}

func TestBuildChunkIndexTruncated(t *testing.T) {
	ch := chunkOf(5, 0, entryBytes(12, 3, 1, nil))
	idx := BuildChunkIndex(ch)
	if len(idx.Offsets) != 1 {
		t.Fatalf("offsets=%v", idx.Offsets)
	}
	short := []byte{3, 0, 0, 0, 0, 0, 0, 0}
	if idx := BuildChunkIndex(short); len(idx.Offsets) != 0 {
		t.Fatalf("%v", idx.Offsets)
	}
}

func TestBuildChunkIndexStopsOnNonZeroFirstField(t *testing.T) {
	bad := entryBytes(12, 3, 1, nil)
	binary.LittleEndian.PutUint32(bad[0:], 9)
	ch := chunkOf(2, 0, bad, entryBytes(12, 3, 2, nil))
	idx := BuildChunkIndex(ch)
	if len(idx.Offsets) != 0 {
		t.Fatalf("%v", idx.Offsets)
	}
}

func TestChunkIndexToParseAll(t *testing.T) {
	body := make([]byte, 0, 32)
	for _, v := range []float64{10, 20, 30, 40} {
		fb := make([]byte, 8)
		binary.LittleEndian.PutUint64(fb, math.Float64bits(v))
		body = append(body, fb...)
	}
	e := entryBytes(32, 3, 42, body)
	ch := chunkOf(1, 0, e)
	idx := BuildChunkIndex(ch)
	if len(idx.Offsets) != 1 {
		t.Fatalf("%v", idx.Offsets)
	}
	d := Dir{Base: 0, Offsets: idx.Offsets}
	got, err := ParseAll(ch, d)
	if err != nil {
		t.Fatal(err)
	}
	if len(got) != 1 || got[0].Record.ID != 42 {
		t.Fatalf("parsed=%+v", got)
	}
	ln := got[0].Body.(*Body).Value.(*element.Line)
	if ln.Start.X != 10 || ln.End.Y != 40 {
		t.Fatalf("line=%+v", ln)
	}
}
