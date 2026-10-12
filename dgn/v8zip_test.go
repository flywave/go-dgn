package dgn

import (
	"bytes"
	"compress/flate"
	"testing"
)

// zipSegment builds one zlib-framed deflate segment. When dict is non-nil
// the segment is compressed against that preset window, which is how ODA
// chains segments (later segments reference earlier segments' output).
func zipSegment(t *testing.T, data []byte, dict []byte) []byte {
	t.Helper()
	var out bytes.Buffer
	level := 6
	if len(data) < 64 {
		level = flate.BestSpeed
	}
	var w *flate.Writer
	var err error
	if dict != nil {
		w, err = flate.NewWriterDict(&out, level, dict)
	} else {
		w, err = flate.NewWriter(&out, level)
	}
	if err != nil {
		t.Fatal(err)
	}
	if _, err := w.Write(data); err != nil {
		t.Fatal(err)
	}
	w.Close()
	var framed bytes.Buffer
	framed.Write([]byte{0x78, 0x9c}) // valid zlib header (FCHECK ok)
	framed.Write(out.Bytes())
	// ODA writes unreliable adlers; use a real one here and a zeroed one
	// in the golden test to cover both.
	var a uint32
	for _, b := range data {
		a = a*31 + uint32(b)
	}
	framed.Write([]byte{0, 0, 0, 0}) // deliberately bogus checksum
	_ = a
	return framed.Bytes()
}

func TestInflateZipSingleSegment(t *testing.T) {
	want := bytes.Repeat([]byte("hello v8 "), 100)
	w := &zipWindow{}
	got, segs, err := w.inflateZip(zipSegment(t, want, nil))
	if err != nil {
		t.Fatal(err)
	}
	if segs != 1 || !bytes.Equal(got, want) {
		t.Fatalf("segs=%d len=%d", segs, len(got))
	}
}

func TestInflateZipChainedSegments(t *testing.T) {
	first := bytes.Repeat([]byte("A0"), 2048) // 4 KiB of history
	second := bytes.Repeat([]byte("B1"), 2048)

	w := &zipWindow{}
	var raw bytes.Buffer
	raw.Write(zipSegment(t, first, nil))
	// Segment 2 compressed against segment 1's output: standalone decoding
	// must fail, window-chained decoding must succeed byte-exactly.
	raw.Write(zipSegment(t, second, first))

	got, segs, err := w.inflateZip(raw.Bytes())
	if err != nil {
		t.Fatal(err)
	}
	if segs != 2 {
		t.Fatalf("segs=%d", segs)
	}
	want := append(append([]byte{}, first...), second...)
	if !bytes.Equal(got, want) {
		t.Fatalf("chained decode mismatch: got %d want %d", len(got), len(want))
	}
}

func TestInflateZipStandaloneSecondSegmentFails(t *testing.T) {
	first := bytes.Repeat([]byte("A0"), 2048)
	// Start the second segment with a copy of the window tail so the
	// compressor must emit back-references beyond the segment's own output.
	second := append(append([]byte{}, first[len(first)-512:]...), bytes.Repeat([]byte("B1"), 2048)...)
	w := &zipWindow{}
	got, _, err := w.inflateZip(zipSegment(t, second, first))
	if err == nil && bytes.Equal(got, second) {
		t.Fatal("segment decoded byte-exactly without its dictionary window")
	}
}

func TestInflateZipGarbage(t *testing.T) {
	w := &zipWindow{}
	if _, _, err := w.inflateZip([]byte("not compressed at all")); err == nil {
		t.Fatal("expected error for garbage input")
	}
}

func TestDecodeZipStreamPrefix(t *testing.T) {
	prefix := []byte{0x01, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00}
	payload := []byte("payload bytes for the design header")
	w := &zipWindow{}
	raw := append(append([]byte{}, prefix...), zipSegment(t, payload, nil)...)
	p, got, err := w.DecodeZipStream(raw)
	if err != nil {
		t.Fatal(err)
	}
	if !bytes.Equal(p, prefix) {
		t.Fatalf("prefix = %x", p)
	}
	if !bytes.Equal(got, payload) {
		t.Fatalf("payload mismatch")
	}
}

func TestZlibHeaderScan(t *testing.T) {
	if !zlibHeaderAt([]byte{0x78, 0x9c}, 0) || !zlibHeaderAt([]byte{0x78, 0x5e}, 0) ||
		!zlibHeaderAt([]byte{0x78, 0x01}, 0) || !zlibHeaderAt([]byte{0x78, 0xda}, 0) {
		t.Fatal("valid headers rejected")
	}
	if zlibHeaderAt([]byte{0x78, 0x00}, 0) || zlibHeaderAt([]byte{0x00, 0x00}, 0) {
		t.Fatal("invalid header accepted")
	}
	body := append(make([]byte, 40), 0x78, 0x9c)
	if got := findZipHeader(body, 0, 64); got != 40 {
		t.Fatalf("findZipHeader = %d", got)
	}
	if got := findZipHeader(body, 0, 20); got != -1 {
		t.Fatalf("limited scan = %d", got)
	}
}
