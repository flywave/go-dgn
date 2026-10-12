package cfb

import (
	"bytes"
	"errors"
	"testing"

	"github.com/flywave/go-dgn/internal/cfb/cfbtest"
)

func pattern(n int, seed byte) []byte {
	b := make([]byte, n)
	for i := range b {
		b[i] = seed ^ byte(i)
	}
	return b
}

func TestOpenAndReadStreams(t *testing.T) {
	small := pattern(100, 0xA5)
	tiny := []byte("hello dgn")
	big := pattern(4096, 0x11)
	bigger := pattern(5000, 0x22)
	data := cfbtest.Write(map[string][]byte{
		"Dgn~S":   small,
		"Dgn~ULC": big,
		"Oda~SH":  tiny,
		"Extra":   bigger,
	})
	f, err := Open(data)
	if err != nil {
		t.Fatalf("Open: %v", err)
	}
	names := f.Names()
	want := map[string]bool{"Dgn~S": true, "Dgn~ULC": true, "Oda~SH": true, "Extra": true}
	if len(names) != len(want) {
		t.Fatalf("names = %v", names)
	}
	for _, n := range names {
		if !want[n] {
			t.Fatalf("unexpected name %q", n)
		}
	}
	cases := map[string][]byte{
		"Dgn~S":   small,
		"Oda~SH":  tiny,
		"Dgn~ULC": big,
		"Extra":   bigger,
	}
	for n, w := range cases {
		got, err := f.Stream(n)
		if err != nil {
			t.Fatalf("Stream(%q): %v", n, err)
		}
		if !bytes.Equal(got, w) {
			t.Fatalf("Stream(%q) mismatch: len=%d want=%d", n, len(got), len(w))
		}
		sz, ok := f.Size(n)
		if !ok || sz != uint64(len(w)) {
			t.Fatalf("Size(%q) = %d,%v", n, sz, ok)
		}
	}
}

func TestOpenErrors(t *testing.T) {
	if _, err := Open([]byte("not a compound file at all")); !errors.Is(err, ErrNotCompoundFile) {
		t.Fatalf("err = %v", err)
	}
	data := cfbtest.Write(map[string][]byte{"Only": []byte("x")})
	f, err := Open(data)
	if err != nil {
		t.Fatal(err)
	}
	if _, err := f.Stream("Missing"); !errors.Is(err, ErrStreamNotFound) {
		t.Fatalf("err = %v", err)
	}
}

func TestEmptyStream(t *testing.T) {
	data := cfbtest.Write(map[string][]byte{"Empty": {}})
	f, err := Open(data)
	if err != nil {
		t.Fatal(err)
	}
	b, err := f.Stream("Empty")
	if err != nil || len(b) != 0 {
		t.Fatalf("got %v, %v", b, err)
	}
}

func TestNestedStorages(t *testing.T) {
	model := map[string]interface{}{
		"$1":     []byte("graphics chunk"),
		"Dgn~Mh": []byte("model header table"),
	}
	data := cfbtest.WriteTree(map[string]interface{}{
		"Dgn~H": []byte("design header"),
		"Dgn-Md": map[string]interface{}{
			"#000000": model,
		},
	})
	f, err := Open(data)
	if err != nil {
		t.Fatal(err)
	}
	paths := map[string]bool{}
	for _, e := range f.Entries() {
		paths[e.Path] = true
		if e.Type == 1 && e.Size != 0 {
			t.Fatalf("storage %s has size %d", e.Path, e.Size)
		}
	}
	for _, want := range []string{
		"Dgn~H",
		"Dgn-Md",
		"Dgn-Md/#000000",
		"Dgn-Md/#000000/$1",
		"Dgn-Md/#000000/Dgn~Mh",
	} {
		if !paths[want] {
			t.Fatalf("path %q missing; have %v", want, paths)
		}
	}
	if b, err := f.Stream("Dgn-Md/#000000/$1"); err != nil || string(b) != "graphics chunk" {
		t.Fatalf("nested stream = %q, %v", b, err)
	}
	if b, err := f.Stream("Dgn-Md/#000000/Dgn~Mh"); err != nil || string(b) != "model header table" {
		t.Fatalf("nested stream = %q, %v", b, err)
	}
	if _, err := f.Stream("Dgn-Md"); err == nil {
		t.Fatal("storage resolved as stream")
	}
	// Allocation order: mini-stream contents allocate after regular sectors.
	streams := f.Streams()
	if len(streams) != 3 {
		t.Fatalf("streams = %d", len(streams))
	}
}

func TestV3DirectoryEntryOffsets(t *testing.T) {
	// Regression: v3 entries carry start@116/size@120 (MS-CFB §2.6.1); the
	// old reader used 120/124 and zeroed every size on real ODA files.
	data := cfbtest.Write(map[string][]byte{"S": bytes.Repeat([]byte{7}, 100)})
	f, err := Open(data)
	if err != nil {
		t.Fatal(err)
	}
	if sz, ok := f.Size("S"); !ok || sz != 100 {
		t.Fatalf("size = %d, %v", sz, ok)
	}
}
