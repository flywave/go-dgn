package dgn

import "fmt"

type Dir struct {
	Base    int64
	Offsets []uint32
}

type Entry struct {
	Index    int
	Pos      int64
	Header   Header
	Children uint32
	Complex  bool
}

func (e Entry) Skip() int {
	if !e.Complex {
		return 1
	}
	return 1 + int(e.Children)
}

type RecordSource func(pos int64, n int) ([]byte, error)

func (d Dir) ReadEntries(src RecordSource) ([]Entry, error) {
	out := make([]Entry, 0, len(d.Offsets))
	for i, off := range d.Offsets {
		pos := d.Base + int64(off)
		b, err := src(pos, HeaderSize)
		if err != nil {
			return out, fmt.Errorf("dgn: entry %d at %d: %w", i, pos, err)
		}
		h, err := ParseHeader(b)
		if err != nil {
			return out, fmt.Errorf("dgn: entry %d: %w", i, err)
		}
		e := Entry{Index: i, Pos: pos, Header: h, Complex: h.IsComplex()}
		if e.Complex {
			coff := int64(HeaderSize)
			if h.HasDisplayHeader() && h.Type != 100 {
				coff = 108
			}
			cb, err := src(pos+coff, 4)
			if err != nil {
				return out, fmt.Errorf("dgn: entry %d complex count: %w", i, err)
			}
			e.Children = leU32(cb)
		}
		out = append(out, e)
	}
	return out, nil
}

func leU32(b []byte) uint32 {
	return uint32(b[0]) | uint32(b[1])<<8 | uint32(b[2])<<16 | uint32(b[3])<<24
}
