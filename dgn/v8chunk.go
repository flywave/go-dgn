package dgn

import (
	"errors"
	"fmt"
)

// V8Chunk is a decoded '$' element chunk. The 16-byte on-stream header is
// four u32s (D96, read FUN_1809ea120 / write FUN_1809ea640+dcad0):
//
//	[u32 count][u32 flags][u32 x][u32 y]
//	[zlib frame payload]   — decompresses to the pure record space
//
// count drives the record walk (its actual entry count), flags lands on
// obj+0x40 (bit0/bit1 byte views at +0x44/+0x45), x/y land on obj+0x44
// (u32 view) / obj+0x48 and are not consumed by the reader. Golden-write
// shapes: save = [count][2][0][count], empty-block init = [0][2]
// [nameSuffix][0]; the (0,0)+flags=3 family of the old attach writer is
// archived as-is (write path unknown, D96 residual). Streams with no zlib
// header after the prefix store raw records at offset 8 (legacy shape).
//
// The decompressed record space is a chain walked by
// off[i+1] = off[i] + B*2 + 4 while the leading u32 (A) stays 0 — the seed
// is the prefix length, i.e. 0 in the decompressed view (FUN_1809dc670).
// A non-zero A marks the trailing heap (element name strings such as
// "Master Model"); empty slots are legal 4-byte records (type 0, B=0).
type V8Chunk struct {
	Path     string // container path of the source stream
	Capacity uint32 // count field: number of records in this chunk
	Flags    uint32
	X        uint32 // header word 3 (obj+0x44 u32 view; write side: 0 or nameSuffix)
	Y        uint32 // header word 4 (obj+0x48; write side: count echo)
	Space    []byte // element record space (decompressed when stored compressed)
	Offsets  []uint32
	Heap     []byte // trailing non-record bytes (nil when Space runs to the end)
	Elements []Parsed
}

// ParseV8Chunk decodes one '$' chunk. The window carries the file-wide
// sliding decompression history; pass the document-level window.
func ParseV8Chunk(path string, raw []byte, w *zipWindow) (*V8Chunk, error) {
	if len(raw) < 8 {
		return nil, fmt.Errorf("dgn/v8: chunk %q too short (%d)", path, len(raw))
	}
	c := &V8Chunk{Path: path}
	c.Capacity = leU32(raw[0:4])
	c.Flags = leU32(raw[4:8])
	if len(raw) >= 16 {
		c.X = leU32(raw[8:12])
		c.Y = leU32(raw[12:16])
	}
	// The ODA 25.4 writer frames the payload right after the 16-byte header
	// (D96/D97); older files in the golden set agree. The 8-byte fallback
	// keeps the legacy raw shape (records start at 8) working.
	off := -1
	if len(raw) >= 16 {
		off = findZipHeader(raw, 16, 64)
	}
	if off < 0 {
		off = findZipHeader(raw, 8, 64)
	}
	if off >= 0 {
		payload, _, err := w.inflateZip(raw[off:])
		if err != nil && !(c.Capacity == 0 && errors.Is(err, errNoZipSegment)) {
			return nil, fmt.Errorf("dgn/v8: chunk %q: %w", path, err)
		}
		c.Space = payload
	} else {
		c.Space = raw[8:]
	}
	c.walkRecords()
	return c, nil
}

func (c *V8Chunk) walkRecords() {
	space := c.Space
	pos := uint32(0)
	for uint32(len(c.Offsets)) < c.Capacity {
		if int(pos)+4 > len(space) {
			break
		}
		if leU32(space[pos:]) != 0 {
			break
		}
		size := uint32(4)
		if int(pos)+12 <= len(space) {
			size = leU32(space[pos+8:])*2 + 4
			if size < 4 || int(pos)+int(size) > len(space) {
				break
			}
		}
		c.Offsets = append(c.Offsets, pos)
		pos += size
	}
	if int(pos) < len(space) {
		c.Heap = space[pos:]
	}
}

// ParseElements decodes the records into Parsed elements, skipping empty
// slots (span < 36 bytes, type 0) which cannot carry an element header.
func (c *V8Chunk) ParseElements() error {
	// Zero-pad short tail reads: trailing empty slots are shorter than a
	// full header but still legal directory entries.
	src := func(pos int64, n int) ([]byte, error) {
		if pos < 0 || pos > int64(len(c.Space)) {
			return nil, fmt.Errorf("out of range")
		}
		if pos+int64(n) <= int64(len(c.Space)) {
			return c.Space[pos : pos+int64(n)], nil
		}
		out := make([]byte, n)
		copy(out, c.Space[pos:])
		return out, nil
	}
	entries, err := (&Dir{Base: 0, Offsets: c.Offsets}).ReadEntries(src)
	if err != nil {
		return err
	}
	for i, e := range entries {
		end := int64(len(c.Space))
		if i+1 < len(entries) {
			end = entries[i+1].Pos
		}
		if end-e.Pos < HeaderSize {
			continue // empty slot
		}
		p, err := parseRange(c.Space, e, end)
		if err != nil {
			continue // keep walking: tolerate partial records
		}
		c.Elements = append(c.Elements, *p)
	}
	return nil
}
