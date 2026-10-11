package dgn

import (
	"encoding/binary"
	"errors"
	"fmt"
)

var ErrNotV7 = errors.New("dgn: not a DGN v7 file")

type Kind uint8

const (
	KindUnknown Kind = iota
	KindV7
	KindV7CellLib
	KindV8
)

func Detect(b []byte) Kind {
	if len(b) < 4 {
		return KindUnknown
	}
	if b[0] == 0x08 && b[1] == 0x05 && b[2] == 0x17 && b[3] == 0x00 {
		return KindV7CellLib
	}
	if (b[0] == 0x08 || b[0] == 0xC8) && b[1] == 0x09 && b[2] == 0xFE && b[3] == 0x02 {
		return KindV7
	}
	if len(b) >= 8 && b[0] == 0xD0 && b[1] == 0xCF && b[2] == 0x11 && b[3] == 0xE0 {
		return KindV8
	}
	return KindUnknown
}

type V7Header struct {
	Is3D   bool
	Level  byte
	Words  uint16
	Magic0 byte
}

func ParseV7Header(b []byte) (V7Header, error) {
	var h V7Header
	if Detect(b) != KindV7 {
		return h, ErrNotV7
	}
	h.Magic0 = b[0]
	h.Is3D = b[0]&0x40 != 0
	h.Level = b[0] & 0x3f
	h.Words = binary.LittleEndian.Uint16(b[2:])
	return h, nil
}

type V7Element struct {
	Level   byte
	Type    byte
	Complex bool
	Deleted bool
	Words   uint16
	Offset  int
	Body    []byte
}

func (e V7Element) Size() int { return int(e.Words)*2 + 4 }

func ReadV7Elements(b []byte) ([]V7Element, error) {
	if Detect(b) != KindV7 {
		return nil, ErrNotV7
	}
	var out []V7Element
	off := 0
	for off+4 <= len(b) {
		if b[off] == 0xFF && b[off+1] == 0xFF {
			return out, nil
		}
		lvl := b[off] & 0x3f
		typ := b[off+1] & 0x7f
		cx := b[off]&0x80 != 0
		dl := b[off+1]&0x80 != 0
		words := binary.LittleEndian.Uint16(b[off+2:])
		size := int(words)*2 + 4
		if size < 4 || off+size > len(b) {
			return out, fmt.Errorf("dgn/v7: element at %d size %d out of range (%d total)", off, size, len(b))
		}
		out = append(out, V7Element{
			Level: lvl, Type: typ, Complex: cx, Deleted: dl,
			Words: words, Offset: off, Body: b[off+4 : off+size],
		})
		off += size
	}
	return out, nil
}
