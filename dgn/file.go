package dgn

import (
	"errors"
	"fmt"
	"os"
	"sort"
	"strings"

	"github.com/flywave/go-dgn/internal/cfb"
)

var ErrUnsupportedV7 = errors.New("dgn: not an OLE compound document (DGN v7 unsupported in v1)")

type ChunkKind uint8

const (
	ChunkOther ChunkKind = iota
	ChunkElement
	ChunkZip
)

func (k ChunkKind) String() string {
	switch k {
	case ChunkElement:
		return "element"
	case ChunkZip:
		return "zip"
	}
	return "other"
}

type StreamInfo struct {
	Name string
	Size uint64
	Kind ChunkKind
}

type File struct {
	c       *cfb.File
	streams []StreamInfo
}

func Open(path string) (*File, error) {
	b, err := os.ReadFile(path)
	if err != nil {
		return nil, err
	}
	return OpenBytes(b)
}

func OpenBytes(b []byte) (*File, error) {
	c, err := cfb.Open(b)
	if errors.Is(err, cfb.ErrNotCompoundFile) {
		return nil, ErrUnsupportedV7
	}
	if err != nil {
		return nil, err
	}
	f := &File{c: c}
	for _, e := range c.Streams() {
		f.streams = append(f.streams, StreamInfo{Name: e.Path, Size: e.Size, Kind: kindOf(e.Path)})
	}
	sort.Slice(f.streams, func(i, j int) bool { return f.streams[i].Name < f.streams[j].Name })
	return f, nil
}

func kindOf(name string) ChunkKind {
	base := name
	if i := strings.LastIndexByte(base, '/'); i >= 0 {
		base = base[i+1:]
	}
	if strings.HasPrefix(base, string(ElementChunkPrefix)) {
		return ChunkElement
	}
	if strings.HasPrefix(base, "Dgn~") || strings.HasPrefix(base, "Oda~") {
		return ChunkZip
	}
	return ChunkOther
}

func (f *File) Streams() []StreamInfo {
	out := make([]StreamInfo, len(f.streams))
	copy(out, f.streams)
	return out
}

func (f *File) ElementChunks() []StreamInfo {
	var out []StreamInfo
	for _, s := range f.streams {
		if s.Kind == ChunkElement {
			out = append(out, s)
		}
	}
	return out
}

func (f *File) Stream(name string) ([]byte, error) {
	b, err := f.c.Stream(name)
	if err != nil {
		return nil, fmt.Errorf("dgn: stream %q: %w", name, err)
	}
	return b, nil
}
