package dgn

import (
	"bytes"
	"errors"
	"testing"

	"github.com/flywave/go-dgn/internal/cfb/cfbtest"
)

func TestOpenBytesAndClassify(t *testing.T) {
	main := []byte("main-element-stream-data")
	elems := []byte("element-offset-directory")
	other := []byte{1, 2, 3}
	data := cfbtest.Write(map[string][]byte{
		"StreamULC":          main,
		"Dgn~ULC":            main,
		"$Elements":          elems,
		"SummaryInformation": other,
	})
	f, err := OpenBytes(data)
	if err != nil {
		t.Fatalf("OpenBytes: %v", err)
	}
	byName := map[string]StreamInfo{}
	for _, s := range f.Streams() {
		byName[s.Name] = s
	}
	if s, ok := byName["$Elements"]; !ok || s.Kind != ChunkElement {
		t.Fatalf("$Elements = %+v ok=%v", s, ok)
	}
	if s, ok := byName["Dgn~ULC"]; !ok || s.Kind != ChunkZip || s.Size != uint64(len(main)) {
		t.Fatalf("Dgn~ULC = %+v ok=%v", s, ok)
	}
	if s, ok := byName["SummaryInformation"]; !ok || s.Kind != ChunkOther {
		t.Fatalf("SummaryInformation = %+v ok=%v", s, ok)
	}
	if ecs := f.ElementChunks(); len(ecs) != 1 || ecs[0].Name != "$Elements" {
		t.Fatalf("ElementChunks = %+v", ecs)
	}
	got, err := f.Stream("Dgn~ULC")
	if err != nil || !bytes.Equal(got, main) {
		t.Fatalf("Stream = %q %v", got, err)
	}
	if _, err := f.Stream("Nope"); err == nil {
		t.Fatal("expected missing stream error")
	}
}

func TestOpenBytesNotCompound(t *testing.T) {
	_, err := OpenBytes([]byte("AC1032 not really a dwg either"))
	if !errors.Is(err, ErrUnsupportedV7) {
		t.Fatalf("err = %v", err)
	}
}

var v7Seeds = []string{
	"/Users/xuning/Work/flywave-platform-hydropower/gdal_data/seed_2d.dgn",
	"/Users/xuning/Work/flywave-platform-hydropower/gdal_data/seed_3d.dgn",
}

func TestRealV7SeedsRejected(t *testing.T) {
	tested := 0
	for _, p := range v7Seeds {
		f, err := Open(p)
		if err == nil {
			t.Fatalf("%s: expected ErrUnsupportedV7, got file with %d streams", p, len(f.Streams()))
		}
		if !errors.Is(err, ErrUnsupportedV7) {
			t.Fatalf("%s: err=%v", p, err)
		}
		tested++
	}
	if tested == 0 {
		t.Skip("no seed files present")
	}
}
