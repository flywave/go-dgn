package le

import (
	"errors"
	"math"
	"testing"
)

func TestReadSequence(t *testing.T) {
	buf := []byte{
		0x01,
		0xfe, 0xff,
		0x78, 0x56, 0x34, 0x12,
		0xef, 0xcd, 0xab, 0x90, 0x78, 0x56, 0x34, 0x12,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x3f,
		'x', 'y',
	}
	r := New(buf)
	if got := r.U8(); got != 1 {
		t.Fatalf("U8 = %d", got)
	}
	if got := r.I16(); got != -2 {
		t.Fatalf("I16 = %d", got)
	}
	if got := r.U32(); got != 0x12345678 {
		t.Fatalf("U32 = %#x", got)
	}
	if got := r.U64(); got != 0x1234567890abcdef {
		t.Fatalf("U64 = %#x", got)
	}
	if got := r.F64(); got != 1.0 {
		t.Fatalf("F64 = %v", got)
	}
	if got := string(r.Bytes(2)); got != "xy" {
		t.Fatalf("Bytes = %q", got)
	}
	if r.Remaining() != 0 {
		t.Fatalf("remaining = %d", r.Remaining())
	}
	if r.Err() != nil {
		t.Fatalf("err = %v", r.Err())
	}
}

func TestTruncationSticky(t *testing.T) {
	r := New([]byte{1, 2})
	r.U32()
	if !errors.Is(r.Err(), ErrTruncated) {
		t.Fatalf("err = %v", r.Err())
	}
	v := r.U8()
	if v != 0 {
		t.Fatalf("after error got %d", v)
	}
	if !errors.Is(r.Err(), ErrTruncated) {
		t.Fatalf("sticky err lost")
	}
}

func TestSeekAndRest(t *testing.T) {
	r := New([]byte{10, 20, 30, 40})
	if err := r.Seek(2); err != nil {
		t.Fatal(err)
	}
	if got := r.U16(); got != 0x281e {
		t.Fatalf("U16 = %#x", got)
	}
	if r.Seek(99); !errors.Is(r.Err(), ErrTruncated) {
		t.Fatalf("seek oob err = %v", r.Err())
	}
	r2 := New([]byte{7, 8, 9})
	if got := r2.Rest(); len(got) != 3 {
		t.Fatalf("Rest = %v", got)
	}
}

func TestF32(t *testing.T) {
	r := New([]byte{0x00, 0x00, 0x80, 0x3f})
	if got := r.F32(); math.Abs(float64(got)-1.0) > 1e-9 {
		t.Fatalf("F32 = %v", got)
	}
}
