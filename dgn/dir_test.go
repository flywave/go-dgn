package dgn

import (
	"encoding/binary"
	"testing"
)

func srcFrom(space []byte) RecordSource {
	return func(pos int64, n int) ([]byte, error) {
		if pos < 0 || pos+int64(n) > int64(len(space)) {
			return nil, errShort
		}
		return space[pos : pos+int64(n)], nil
	}
}

var errShort = &shortErr{}

type shortErr struct{}

func (*shortErr) Error() string { return "short read" }

func putU32(b []byte, v uint32) { binary.LittleEndian.PutUint32(b, v) }

func TestReadEntriesPlain(t *testing.T) {
	space := make([]byte, 300)
	h0 := Header{Type: 3, Sub: 0, ID: 1}
	h1 := Header{Type: 4, Flag: FlagExtra4, ID: 2}
	copy(space[0:], buildHeader(h0))
	copy(space[100:], buildHeader(h1))
	d := Dir{Base: 0, Offsets: []uint32{0, 100}}
	entries, err := d.ReadEntries(srcFrom(space))
	if err != nil {
		t.Fatal(err)
	}
	if len(entries) != 2 {
		t.Fatalf("len=%d", len(entries))
	}
	if entries[0].Pos != 0 || entries[0].Header.Type != 3 || entries[0].Skip() != 1 {
		t.Fatalf("e0=%+v", entries[0])
	}
	if entries[1].Pos != 100 || entries[1].Header.ID != 2 || entries[1].Header.HasExtra4() != true {
		t.Fatalf("e1=%+v", entries[1])
	}
}

func TestReadEntriesComplexSpanAt36(t *testing.T) {
	space := make([]byte, 200)
	h := Header{Type: 4, Flag: FlagComplex, ID: 7}
	copy(space[0:], buildHeader(h))
	putU32(space[36:], 3)
	d := Dir{Base: 0, Offsets: []uint32{0}}
	entries, err := d.ReadEntries(srcFrom(space))
	if err != nil {
		t.Fatal(err)
	}
	e := entries[0]
	if !e.Complex || e.Children != 3 || e.Skip() != 4 {
		t.Fatalf("e=%+v skip=%d", e, e.Skip())
	}
}

func TestReadEntriesComplexCountAt108(t *testing.T) {
	space := make([]byte, 240)
	h := Header{Type: 35, Flag: FlagComplex | FlagDisplayHeader, ID: 8}
	copy(space[0:], buildHeader(h))
	putU32(space[108:], 5)
	d := Dir{Base: 0, Offsets: []uint32{0}}
	entries, err := d.ReadEntries(srcFrom(space))
	if err != nil {
		t.Fatal(err)
	}
	e := entries[0]
	if e.Children != 5 || e.Skip() != 6 {
		t.Fatalf("e=%+v skip=%d", e, e.Skip())
	}
}

func TestReadEntriesComplexType100Keeps36(t *testing.T) {
	space := make([]byte, 240)
	base := int64(16)
	h := Header{Type: 100, Flag: FlagComplex | FlagDisplayHeader}
	copy(space[base:], buildHeader(h))
	putU32(space[base+36:], 2)
	putU32(space[base+108:], 99)
	d := Dir{Base: base, Offsets: []uint32{0}}
	entries, err := d.ReadEntries(srcFrom(space))
	if err != nil {
		t.Fatal(err)
	}
	if entries[0].Children != 2 {
		t.Fatalf("children=%d", entries[0].Children)
	}
}

func TestReadEntriesShort(t *testing.T) {
	space := make([]byte, 10)
	d := Dir{Base: 0, Offsets: []uint32{0}}
	if _, err := d.ReadEntries(srcFrom(space)); err == nil {
		t.Fatal("expected error")
	}
}
