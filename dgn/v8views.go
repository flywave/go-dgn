package dgn

import (
	"encoding/binary"
	"math"
)

// V8View is the typed reading of a v8 View element (type 98, body 272B).
// Layout from the attach golden differential (8 views, D105):
//
//	@0    u32 flags (1 on every golden view)
//	@8    9×f64 rotation matrix, row-major 3×3 — identity for the Top view,
//	      √2/2 pairs for the 45°-rotated views
//	@80   4×f64 normalized view-tile rectangle (x0, y0, x1, y1 in [0,1];
//	      the 8 golden views tile the screen in quadrants)
//
// The remaining bytes (camera/clipping parameters, per-view counters) are
// undecoded — semantics not pinned.
type V8View struct {
	EntryID  uint64
	Rotation [9]float64
	Tile     [4]float64
	Raw      []byte
}

// V8LevelMask is the typed reading of a v8 LevelMask element (type 99,
// body 52B, one per view): u32@16 is the mask width in bits (64 on the
// goldens) and u64@20 the visibility bitset — all 0xFF in the golden
// files (every level displayed).
type V8LevelMask struct {
	EntryID  uint64
	ViewID   uint32 // u32@0 (links to the owning view on the goldens)
	BitCount uint32 // @16
	Mask     uint64 // @20
	Raw      []byte
}

// Visible reports whether level number n (0-based) passes the mask.
func (m V8LevelMask) Visible(n int) bool {
	if n < 0 || n >= 64 {
		return false
	}
	return m.Mask&(1<<uint(n)) != 0
}

// parseV8Views extracts typed views and level masks from the parsed table
// elements (the elements stay Proxy-decoded; this reads their raw bodies).
func parseV8Views(doc *V8Document) {
	for i := range doc.Tables {
		p := &doc.Tables[i]
		px, ok := p.Body.(*ProxyElement)
		if !ok {
			continue
		}
		raw := px.Raw
		switch p.Record.Type {
		case 98:
			if len(raw) < 112 {
				continue
			}
			v := V8View{EntryID: p.Record.ID, Raw: raw}
			for j := 0; j < 9; j++ {
				v.Rotation[j] = math.Float64frombits(binary.LittleEndian.Uint64(raw[8+8*j:]))
			}
			for j := 0; j < 4; j++ {
				v.Tile[j] = math.Float64frombits(binary.LittleEndian.Uint64(raw[80+8*j:]))
			}
			doc.Views = append(doc.Views, v)
		case 99:
			if len(raw) < 28 {
				continue
			}
			lm := V8LevelMask{
				EntryID:  p.Record.ID,
				ViewID:   binary.LittleEndian.Uint32(raw[0:]),
				BitCount: binary.LittleEndian.Uint32(raw[16:]),
				Mask:     binary.LittleEndian.Uint64(raw[20:]),
				Raw:      raw,
			}
			doc.ViewLevelMasks = append(doc.ViewLevelMasks, lm)
		}
	}
}
