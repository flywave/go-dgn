package linkage

import (
	"encoding/binary"
	"testing"
)

func hdr(count byte, nibble byte, userData, remote bool) uint16 {
	h := uint16(count) | uint16(nibble)<<8
	if userData {
		h |= flagUserData
	}
	if remote {
		h |= flagRemote
	}
	return h
}

func rec(h uint16, typeID uint16, payload int) []byte {
	b := make([]byte, 4+payload)
	binary.LittleEndian.PutUint16(b[0:], h)
	binary.LittleEndian.PutUint16(b[2:], typeID)
	return b
}

func TestModeAFixed8(t *testing.T) {
	b := append(rec(hdr(0, 0, false, false), 0x1234, 0), make([]byte, 4)...)
	if len(b) != 8 {
		t.Fatalf("len=%d", len(b))
	}
	rs := Iter(b)
	if len(rs) != 1 || rs[0].Mode != ModeA || rs[0].TypeID != 0 || len(rs[0].Raw) != 8 {
		t.Fatalf("rs=%+v", rs)
	}
}

func TestModeBCount(t *testing.T) {
	// count=3 -> n = 3*2+2 = 8
	b := rec(hdr(3, 0, true, false), 0x56e9, 4)
	rs := Iter(b)
	if len(rs) != 1 || rs[0].Mode != ModeB || rs[0].TypeID != 0x56e9 || len(rs[0].Raw) != 8 {
		t.Fatalf("rs=%+v", rs)
	}
}

func TestModeBZeroTypeID(t *testing.T) {
	b := rec(hdr(2, 0, true, false), 0, 2)
	rs := Iter(b)
	if len(rs) != 1 || rs[0].TypeID != 0 {
		t.Fatalf("rs=%+v", rs)
	}
}

func TestModeCExponent(t *testing.T) {
	// nibble=2 -> (2<<2)=8 ; count=2 -> n=16
	b := rec(hdr(2, 2, true, true), 0x0102, 12)
	rs := Iter(b)
	if len(rs) != 1 || rs[0].Mode != ModeC || len(rs[0].Raw) != 16 || rs[0].TypeID != 0x0102 {
		t.Fatalf("rs=%+v", rs)
	}
}

func TestSequenceAndTruncation(t *testing.T) {
	var b []byte
	b = append(b, rec(hdr(1, 0, true, false), 1, 2)...)  // n=4
	b = append(b, rec(hdr(0, 0, false, false), 0, 4)...) // n=8
	b = append(b, rec(hdr(9, 0, true, false), 2, 0)...)  // wants 20, only0 -> stop
	rs := Iter(b)
	if len(rs) != 2 {
		t.Fatalf("rs=%+v", rs)
	}
	if rs[0].TypeID != 1 || len(rs[0].Raw) != 4 {
		t.Fatalf("r0=%+v", rs[0])
	}
	if rs[1].Mode != ModeA || len(rs[1].Raw) != 8 {
		t.Fatalf("r1=%+v", rs[1])
	}
}

func TestModeCCountZeroUsesRest(t *testing.T) {
	b := rec(hdr(0, 3, true, true), 7, 6) // computed n=0 -> rest
	rs := Iter(b)
	if len(rs) != 1 || len(rs[0].Raw) != 10 {
		t.Fatalf("rs=%+v", rs)
	}
}

func TestEmptyAndShort(t *testing.T) {
	if rs := Iter(nil); len(rs) != 0 {
		t.Fatalf("%+v", rs)
	}
	if rs := Iter([]byte{1, 2, 3}); len(rs) != 0 {
		t.Fatalf("%+v", rs)
	}
}
