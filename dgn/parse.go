package dgn

import (
	"fmt"

	"github.com/flywave/go-dgn/dgn/linkage"
	"github.com/flywave/go-dgn/internal/le"
)

type Parsed struct {
	Entry    Entry
	Record   Record
	Body     Element
	Linkages []linkage.Rec
}

func ParseAll(space []byte, d Dir) ([]Parsed, error) {
	src := func(pos int64, n int) ([]byte, error) {
		if pos < 0 || pos+int64(n) > int64(len(space)) {
			return nil, fmt.Errorf("out of range")
		}
		return space[pos : pos+int64(n)], nil
	}
	entries, err := d.ReadEntries(src)
	if err != nil {
		return nil, err
	}
	out := make([]Parsed, 0, len(entries))
	for i, e := range entries {
		end := int64(len(space))
		if i+1 < len(entries) {
			end = entries[i+1].Pos
		}
		p, err := parseRange(space, e, end)
		if err != nil {
			return out, fmt.Errorf("entry %d: %w", i, err)
		}
		out = append(out, *p)
	}
	return out, nil
}

func ParseElement(space []byte, e Entry) (*Parsed, error) {
	return parseRange(space, e, int64(len(space)))
}

func parseRange(space []byte, e Entry, end int64) (*Parsed, error) {
	if e.Pos < 0 || end > int64(len(space)) || e.Pos+HeaderSize > end {
		return nil, fmt.Errorf("dgn: record bounds [%d,%d) in %d", e.Pos, end, len(space))
	}
	h := e.Header
	ext := uint32(0)
	bodyOff := int64(HeaderSize)
	// Display-header presence rule (CDGDispHeader::dgnInFields decompile):
	// read iff NOT[(bit12==0 || type==100) && (type!=35 || C*2 < 0x100)]
	// — type100 (ReferenceAttachmentHeader/XREF) never carries the standard
	// display header (D64; the old "&& type!=100" doc reading was wrong).
	if (h.HasDisplayHeader() && h.Type != 100) || IsImplicitDisplayHeader(h.Type, h.C*2+4) {
		if e.Pos+HeaderSize+DisplayHeaderSize > end {
			return nil, fmt.Errorf("dgn: display header truncated")
		}
		dh, err := ParseDisplayHeader(space[e.Pos+HeaderSize : e.Pos+HeaderSize+DisplayHeaderSize])
		if err != nil {
			return nil, err
		}
		ext = uint32((dh.Properties >> 11) & 1)
		bodyOff += DisplayHeaderSize
	}
	rec := NewRecord(h, ext)
	r := le.New(space[e.Pos+bodyOff : end])
	el, err := Decode(rec, &h, r)
	if err != nil {
		return nil, err
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	// Linkage/attribute region from header words (D65, GetAttribSizeFromHeader
	// (B−C)*2 + dgnInLinkages seek): attrib = (B−C)*2 bytes at the element
	// tail, body ends at C*2+4 — ODA seeks here independently of how far the
	// body decoder advanced. Fallback for fixtures without B/C: remainder
	// after the 16-bit align skip.
	var linkages []linkage.Rec
	split := false
	if h.B > 0 && h.B >= h.C {
		abs := func(w uint32) int64 { return int64(w)*2 + 4 }
		as, ae := abs(h.C), abs(h.B)
		if as >= bodyOff && ae <= end-e.Pos && ae >= as {
			split = true
			linkages = linkage.Iter(space[e.Pos+as : e.Pos+ae])
		}
	}
	if !split {
		if r.Remaining() > 0 && r.Tell()&1 != 0 {
			if err := r.Seek(r.Tell() + 1); err != nil {
				return nil, err
			}
		}
		linkages = linkage.Iter(r.Rest())
	}
	return &Parsed{
		Entry:    e,
		Record:   rec,
		Body:     el,
		Linkages: linkages,
	}, nil
}
