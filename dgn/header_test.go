package dgn

import (
	"encoding/binary"
	"errors"
	"testing"
)

func buildHeader(h Header) []byte {
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

func TestParseHeaderRoundTrip(t *testing.T) {
	want := Header{
		A:    0x11223344,
		Type: 4,
		Flag: FlagComplex | FlagDisplayHeader,
		B:    7,
		C:    8,
		Sub:  9,
		ID:   0x0102030405060708,
		Tail: 0x1112131415161718,
	}
	got, err := ParseHeader(buildHeader(want))
	if err != nil {
		t.Fatal(err)
	}
	if got != want {
		t.Fatalf("got %+v want %+v", got, want)
	}
	if !got.IsComplex() || !got.HasDisplayHeader() || got.HasExtra4() {
		t.Fatalf("flags wrong: %v %v %v", got.IsComplex(), got.HasDisplayHeader(), got.HasExtra4())
	}
}

func TestParseHeaderShort(t *testing.T) {
	if _, err := ParseHeader(make([]byte, 35)); err == nil {
		t.Fatal("expected error")
	}
}

func TestHeaderFlagBits(t *testing.T) {
	h := Header{Flag: (1 << 10) | (1 << 11)}
	if !h.IsNonModel() || !h.IsLocked() {
		t.Fatalf("%+v", h)
	}
	if h.HasDisplayHeader() || h.IsComplex() || h.HasExtra4() {
		t.Fatalf("%+v", h)
	}
}

func TestParseDisplayHeader(t *testing.T) {
	b := make([]byte, DisplayHeaderSize)
	for i := range b {
		b[i] = byte(i)
	}
	// properties word @8: class=8, invisible+3dFmt+viewIndep bits
	binary.LittleEndian.PutUint16(b[8:], 0x0008|(1<<7)|(1<<11)|(1<<12))
	d, err := ParseDisplayHeader(b)
	if err != nil {
		t.Fatal(err)
	}
	if d.GraphicsGroup != 0x03020100 || d.Properties != 0x0008|(1<<7)|(1<<11)|(1<<12) {
		t.Fatalf("head fields wrong: %+v", d)
	}
	if d.Class() != 8 || !d.IsInvisible() || !d.Is3DFormat() || !d.IsViewIndependent() ||
		d.IsNonPlanar() || d.IsNotSnappable() || d.IsHbit() {
		t.Fatalf("flag accessors wrong: %+v", d)
	}
	if d.Priority != 0x07060504 || d.LineStyle != 0x0f0e0d0c ||
		d.LineWeight != 0x13121110 || d.Color != 0x17161514 {
		t.Fatalf("value fields wrong: %+v", d)
	}
	if d.Range[0] != int64(binary.LittleEndian.Uint64(b[24:])) || d.Range[5] != int64(binary.LittleEndian.Uint64(b[64:])) {
		t.Fatalf("tail fields wrong: %+v", d)
	}
	if _, err := ParseDisplayHeader(make([]byte, 71)); err == nil {
		t.Fatal("expected error")
	}
}

func TestHeaderSizeMatchesFileLayout(t *testing.T) {
	if HeaderSize != 36 || DisplayHeaderSize != 72 {
		t.Fatalf("sizes: %d %d", HeaderSize, DisplayHeaderSize)
	}
	if !errors.Is(ErrUnsupportedV7, ErrUnsupportedV7) {
		t.Fatal("unreachable")
	}
}
