package dgn

import (
	"math"
	"testing"
)

func TestV7Int32WordOrder(t *testing.T) {
	// DGN stores two LE u16 halves with the high half first (GDAL DGN_INT32).
	if got := V7Int32([]byte{0x34, 0x12, 0x78, 0x56}); got != 0x12345678 {
		t.Fatalf("got %#x", got)
	}
	// Real sample TCB bytes: subunits_per_master=100, uor_per_subunit=2540.
	if got := V7Int32([]byte{0x00, 0x00, 0x64, 0x00}); got != 100 {
		t.Fatalf("got %d", got)
	}
	if got := V7Int32([]byte{0x00, 0x00, 0xEC, 0x09}); got != 2540 {
		t.Fatalf("got %d", got)
	}
	if got := V7Int32([]byte{0xFF, 0xFF, 0xFF, 0xFF}); got != -1 {
		t.Fatalf("got %d", got)
	}
	var b [4]byte
	V7PutInt32(b[:], -12345678)
	if got := V7Int32(b[:]); got != -12345678 {
		t.Fatalf("roundtrip got %d", got)
	}
}

func TestV7DoubleVax(t *testing.T) {
	cases := []struct {
		v    float64
		want []byte
	}{
		{1.0, []byte{0x80, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
		{0.5, []byte{0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
		{-1.0, []byte{0x80, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
		{0.0, []byte{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
	}
	for _, c := range cases {
		if got := V7Double(c.want); got != c.v {
			t.Errorf("decode %v: got %v (bytes %x)", c.v, got, c.want)
		}
	}
	for _, v := range []float64{635.0, -12345.678, 254000.0, 1e-30, math.Pi, -2.5e-7} {
		var b [8]byte
		V7PutDouble(b[:], v)
		if got := V7Double(b[:]); got != v {
			t.Errorf("roundtrip %v: got %v (bytes %x)", v, got, b)
		}
	}
}

func TestV7BBoxCoordOffsetBinary(t *testing.T) {
	// raw unsigned = true + 2^31 (GDAL DGNGetElementExtents convention)
	put := func(v int32) []byte {
		var b [4]byte
		V7PutInt32(b[:], int32(uint32(v)+(1<<31)))
		return b[:]
	}
	if got := v7BBoxCoord(put(19568)); got != 19568 {
		t.Fatalf("got %d", got)
	}
	if got := v7BBoxCoord(put(-34577)); got != -34577 {
		t.Fatalf("got %d", got)
	}
	if got := v7BBoxCoord(put(math.MinInt32)); got != math.MinInt32 {
		t.Fatalf("got %d", got)
	}
}
