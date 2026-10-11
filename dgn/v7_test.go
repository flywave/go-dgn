package dgn

import (
	"os"
	"testing"
)

func loadSample(t *testing.T, path string) []byte {
	t.Helper()
	b, err := os.ReadFile(path)
	if err != nil {
		t.Skipf("sample absent: %s", path)
	}
	return b
}

func TestDetectKinds(t *testing.T) {
	if Detect([]byte{0xC8, 0x09, 0xFE, 0x02}) != KindV7 {
		t.Fatal("v7 3d")
	}
	if Detect([]byte{0x08, 0x09, 0xFE, 0x02}) != KindV7 {
		t.Fatal("v7 2d")
	}
	if Detect([]byte{0x08, 0x05, 0x17, 0x00}) != KindV7CellLib {
		t.Fatal("cell lib")
	}
	if Detect([]byte{0xD0, 0xCF, 0x11, 0xE0, 0xA1, 0xB1, 0x1A, 0xE1}) != KindV8 {
		t.Fatal("v8")
	}
	if Detect([]byte("AC1032....")) != KindUnknown {
		t.Fatal("unknown")
	}
}

func TestParseV7HeaderSample(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	h, err := ParseV7Header(b)
	if err != nil {
		t.Fatal(err)
	}
	if !h.Is3D || h.Level != 8 {
		t.Fatalf("%+v", h)
	}
}

func TestReadV7ElementsSample(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatal(err)
	}
	if len(els) < 100 {
		t.Fatalf("too few elements: %d", len(els))
	}
	if els[0].Type != 9 {
		t.Fatalf("first element type=%d want 9 (design file header)", els[0].Type)
	}
	total := 0
	for _, e := range els {
		total += e.Size()
	}
	if total > len(b) {
		t.Fatalf("total %d > file %d", total, len(b))
	}
	seen := map[byte]int{}
	for _, e := range els {
		seen[e.Type]++
	}
	t.Logf("elements=%d types=%d first10types=%v", len(els), len(seen), func() []byte {
		var s []byte
		for i := 0; i < 10 && i < len(els); i++ {
			s = append(s, els[i].Type)
		}
		return s
	}())
}

// TestSampleV7TypeCensus is a golden census of the 16MB sample: exact
// element count and per-type histogram. Any drift means the frame walker
// (word-length framing, FF/FF terminator) changed — the strongest
// regression pin available without a v8 sample (D86).
func TestSampleV7TypeCensus(t *testing.T) {
	b := loadSample(t, "../sample.dgn")
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatal(err)
	}
	want := map[byte]int{
		2: 223, 3: 5814, 4: 36, 5: 1, 6: 47, 8: 1, 9: 2, 10: 1,
		12: 16, 14: 3, 15: 6, 16: 317, 21: 2522, 26: 2521, 27: 2522,
		34: 115, 35: 39, 66: 8617,
	}
	if len(els) != 22803 {
		t.Fatalf("elements=%d want 22803", len(els))
	}
	got := map[byte]int{}
	for _, e := range els {
		got[e.Type]++
	}
	if len(got) != len(want) {
		t.Fatalf("type count %d want %d: %v", len(got), len(want), got)
	}
	for typ, n := range want {
		if got[typ] != n {
			t.Errorf("type %d: %d want %d", typ, got[typ], n)
		}
	}
	// Offsets strictly increasing and framed exactly to the FF/FF marker.
	prevEnd := 0
	for _, e := range els {
		if e.Offset != prevEnd {
			t.Fatalf("element @%d does not abut previous end %d", e.Offset, prevEnd)
		}
		prevEnd = e.Offset + e.Size()
	}
	if prevEnd > len(b) || b[prevEnd] != 0xFF || b[prevEnd+1] != 0xFF {
		t.Fatalf("elements do not end at FF/FF marker (end=%d file=%d)", prevEnd, len(b))
	}
}

func TestReadV7Seed2D(t *testing.T) {
	b := loadSample(t, "/Users/xuning/Work/flywave-platform-hydropower/gdal_data/seed_2d.dgn")
	h, err := ParseV7Header(b)
	if err != nil {
		t.Fatal(err)
	}
	if h.Is3D {
		t.Fatalf("%+v", h)
	}
	els, err := ReadV7Elements(b)
	if err != nil {
		t.Fatal(err)
	}
	if len(els) == 0 {
		t.Fatal("no elements")
	}
}
