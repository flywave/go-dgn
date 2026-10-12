package dgn

import (
	"encoding/binary"
	"fmt"
	"math"
	"sort"
	"unicode/utf16"

	"github.com/flywave/go-dgn/dgn/element"
	"github.com/flywave/go-dgn/internal/cfb"
)

// V8 document layer: turns the CFB container into models and elements.
//
// Container layout (v8 golden samples + DGN-V8-FORMAT.md §1):
//
//	Dgn~H                 design header (zip chunk; 20B prefix + payload)
//	Dgn~S                 free-space map (raw)
//	Dgn~Mf                root auxiliary table (zip chunk)
//	Oda~SH                16-byte ODA signature GUID (raw)
//	Dgn^Ix/Dgn~Mix        model index (zip chunk, magic 0xAA00BA11)
//	Dgn^Nm/$n             file-level table elements (TCB, views, level masks…)
//	Dgn^NmA/$n            file-level auxiliary chunk
//	Dgn-Md/#NNNNNN/       one storage per model; inside:
//	  Dgn~Mh              model header table (zip chunk)
//	  Dgn^G/$n            graphics elements
//	  Dgn^C/$n            control elements
//	  Dgn^GA, Dgn^CA      attribute-side mirrors of ^G/^C
//	  ^AH                 u32 generation counter
//
// Every zip-bearing stream shares one 32 KiB deflate window in allocation
// order; the whole document must be decoded in one pass.

const (
	v8MagicMix = 0xAA00BA11

	StorageModels   = "Dgn-Md"
	StorageTables   = "Dgn^Nm"
	StorageTablesA  = "Dgn^NmA"
	StorageIndex    = "Dgn^Ix"
	StorageGraphics = "Dgn^G"
	StorageControl  = "Dgn^C"
)

// V8Header is the decoded Dgn~H design header.
type V8Header struct {
	Prefix   []byte // bytes ahead of the zlib payload (observed 20: u16 1, u16 4)
	Payload  []byte
	Revision uint32 // u32@320 of the payload; matches the OLE Revision Number
}

// V8ModelInfo is one entry of the Dgn~Mix model index (field semantics per
// D98, write side FUN_1805cbed0).
type V8ModelInfo struct {
	Short       string  // u16-length-prefixed UTF-16 name
	Long        string  // u32-length-prefixed UTF-16 name
	ModelNumber uint32  // model serial (@impl+0xb0; FUN_1805cc340 assigns max+1)
	TimestampMS float64 // OdTimeStamp packedValue (ms since epoch)
	Flags       uint16  // lead word: CDGModel-derived bit field
}

// V8Level is one named level-table row (type 95 under the (96,1) Level
// table; v8 goldens D101).
type V8Level struct {
	EntryID uint64 // element id of the row — matches element header Sub
	Name    string
	Number  uint32
	Flags   uint32
}

// V8ModelSettings carries the per-model unit scales decoded from the
// type-66 (AppData, subtype 20) element of the model's Dgn^C storage.
// SubUnitsPerUor is the f64 at raw offset 10 — golden-verified 0.1 for
// attach/attach1 (master = 1000/10000 m, matching the TCB resolution pair)
// and matching the OdDgModel UnitDescription default (1 m) when the element
// is absent (odwriteex).
type V8ModelSettings struct {
	Present        bool
	SubUnitsPerUor float64
	Raw            []byte
}

// V8Model is a fully parsed design model.
type V8Model struct {
	ID       uint64 // from the "#NNNNNN" storage name (hex)
	Name     string // long name from Dgn~Mix, short name as fallback
	Short    string
	Storage  string
	Header   []byte   // Dgn~Mh payload
	Elements []Parsed // Dgn^G/$ graphics elements
	Control  []Parsed // Dgn^C/$ control elements
	Settings V8ModelSettings
}

// V8Document is a fully decoded v8 design file.
type V8Document struct {
	Path           string
	Header         V8Header
	Index          []V8ModelInfo
	Models         []*V8Model
	Tables         []Parsed            // Dgn^Nm/$ elements
	Levels         []V8Level           // named level rows found in the tables
	Views          []V8View            // type-98 view definitions (rotation + tile)
	ViewLevelMasks []V8LevelMask       // type-99 per-view level visibility masks
	Design         *DesignFileHeader   // type-9 design header (file-level settings)
	UorPerMaster   float64             // UORs per master unit (type-9 body @48)
	Chunks         map[string]*V8Chunk // every '$' chunk by container path
	Aux            map[string][]byte   // decoded zip payloads by container path
	Raw            map[string][]byte   // raw bytes of non-zip streams by container path
	Warnings       []error
}

// V8 decodes the container into a full document. The receiver must have
// been produced by Open/OpenBytes on a CFB (v8) file.
func (f *File) V8() (*V8Document, error) {
	if f.c == nil {
		return nil, ErrUnsupportedV7
	}
	doc := &V8Document{
		Chunks: map[string]*V8Chunk{},
		Aux:    map[string][]byte{},
		Raw:    map[string][]byte{},
	}
	entries := f.c.Entries()
	var streams []cfbStreamEntry
	for _, e := range entries {
		if e.Type != 2 {
			continue
		}
		b, err := f.c.Stream(e.Path)
		if err != nil {
			doc.warn(fmt.Errorf("dgn/v8: stream %q: %w", e.Path, err))
			continue
		}
		streams = append(streams, cfbStreamEntry{info: e, data: b})
	}
	// Allocation order == write order == deflate window order.
	sort.SliceStable(streams, func(i, j int) bool { return streams[i].info.Start < streams[j].info.Start })

	w := &zipWindow{}
	for _, s := range streams {
		base := baseName(s.info.Path)
		switch {
		case len(base) > 0 && base[0] == ElementChunkPrefix:
			chunk, err := ParseV8Chunk(s.info.Path, s.data, w)
			if err != nil {
				doc.warn(err)
				doc.Raw[s.info.Path] = s.data
				continue
			}
			if err := chunk.ParseElements(); err != nil {
				doc.warn(fmt.Errorf("dgn/v8: chunk %q: %w", s.info.Path, err))
			}
			doc.Chunks[s.info.Path] = chunk
		case findZipHeader(s.data, 0, 64) >= 0:
			prefix, payload, err := w.DecodeZipStream(s.data)
			if err != nil {
				doc.warn(fmt.Errorf("dgn/v8: stream %q: %w", s.info.Path, err))
				doc.Raw[s.info.Path] = s.data
				continue
			}
			doc.Aux[s.info.Path] = payload
			if len(prefix) > 0 {
				doc.Raw[s.info.Path+".prefix"] = prefix
			}
		default:
			doc.Raw[s.info.Path] = s.data
		}
	}

	// UOR resolution: the uorPerMaster double sits at offset 48 of the
	// type-9 element body (the v7-compat TCB container; constant 10000 in
	// all goldens — D104). Master coordinates = UOR / UorPerMaster.
	doc.UorPerMaster = 10000
	for path, chunk := range doc.Chunks {
		if chunkParent(path) != StorageTables {
			continue
		}
		for i := range chunk.Elements {
			if chunk.Elements[i].Record.Type != 9 {
				continue
			}
			if px, ok := chunk.Elements[i].Body.(*ProxyElement); ok && len(px.Raw) >= 56 {
				if v := math.Float64frombits(binary.LittleEndian.Uint64(px.Raw[48:])); v > 0 {
					doc.UorPerMaster = v
				}
			}
		}
	}

	// Design header: Dgn~H = the first 20 body bytes verbatim + the zlib
	// payload with the rest of the 0x63C OdDgDesignFileHeaderData body
	// (D103). The Revision counter sits at body offset 340 (0x154 zone).
	if b, ok := doc.Aux[StreamH]; ok {
		doc.Header.Payload = b
		prefix := doc.Raw[StreamH+".prefix"]
		if len(prefix) >= 4 {
			doc.Header.Prefix = prefix
		}
		if len(b) >= 324 {
			doc.Header.Revision = leU32(b[320:324])
		}
		body := make([]byte, 0, len(prefix)+len(b))
		body = append(body, prefix...)
		body = append(body, b...)
		doc.Design = ParseDesignFileHeader(body)
	}

	// Model index.
	if b, ok := doc.Aux[StorageIndex+"/"+StreamMix]; ok {
		doc.Index = parseMixIndex(b)
	}

	// Models.
	for _, e := range entries {
		modelID, ok := modelStorageID(e.Path)
		if !ok {
			continue
		}
		m := &V8Model{
			ID:      modelID,
			Storage: e.Path,
		}
		if i := int(modelID); i < len(doc.Index) {
			m.Short = doc.Index[i].Short
			m.Name = doc.Index[i].Long
			if m.Name == "" {
				m.Name = m.Short
			}
		}
		if b, ok := doc.Aux[e.Path+"/"+StreamMh]; ok {
			m.Header = b
		}
		for path, chunk := range doc.Chunks {
			rest := chunkParent(path) // "Dgn-Md/#000000" or "Dgn^Nm"
			switch rest {
			case e.Path + "/" + StorageGraphics:
				m.Elements = append(m.Elements, chunk.Elements...)
			case e.Path + "/" + StorageControl:
				m.Control = append(m.Control, chunk.Elements...)
			}
		}
		doc.Models = append(doc.Models, m)
	}

	// Per-model settings (unit scales) from the type-66 AppData element.
	for _, m := range doc.Models {
		m.Settings.SubUnitsPerUor = 1.0 // OdDgModel UnitDescription default
		for path, chunk := range doc.Chunks {
			if chunkParent(path) != m.Storage+"/"+StorageControl {
				continue
			}
			for i := range chunk.Elements {
				p := &chunk.Elements[i]
				if p.Record.Type != 66 || p.Record.Subtype&0xff != 20 {
					continue
				}
				px, ok := p.Body.(*ProxyElement)
				if !ok || len(px.Raw) < 18 {
					continue
				}
				m.Settings.Present = true
				m.Settings.Raw = px.Raw
				if v := math.Float64frombits(binary.LittleEndian.Uint64(px.Raw[10:])); v > 0 && !math.IsInf(v, 0) && !math.IsNaN(v) {
					m.Settings.SubUnitsPerUor = v
				}
			}
		}
	}
	sort.Slice(doc.Models, func(i, j int) bool { return doc.Models[i].ID < doc.Models[j].ID })

	// File-level tables (Dgn^Nm).
	for path, chunk := range doc.Chunks {
		if chunkParent(path) == StorageTables {
			doc.Tables = append(doc.Tables, chunk.Elements...)
			for i := range chunk.Elements {
				if dh, ok := chunk.Elements[i].Body.(*DesignFileHeader); ok && doc.Design == nil {
					doc.Design = dh
				}
			}
		}
	}

	parseV8Views(doc)

	// Level rows: type-95 rows following a (96,1) LevelTable header that
	// share its subtype, whose blob carries the common trailing name
	// record. Structural pairing (LevelTable header → same-subtype rows)
	// keeps other named tables (RegApp/linestyles/filters) out.
	for _, chunk := range doc.Chunks {
		hdrSub := uint32(0xffff)
		for i := range chunk.Elements {
			p := &chunk.Elements[i]
			if p.Record.Type == 96 {
				hdrSub = p.Record.Subtype & 0xff
				continue
			}
			if hdrSub != 1 || p.Record.Type != 95 || p.Record.Subtype&0xff != hdrSub {
				continue
			}
			b, ok := p.Body.(*Body)
			if !ok {
				continue
			}
			te, ok := b.Value.(*element.TableEntry)
			if !ok || te.Name == "" {
				continue
			}
			doc.Levels = append(doc.Levels, V8Level{
				EntryID: p.Record.ID,
				Name:    te.Name,
				Number:  te.Number,
				Flags:   te.Flags,
			})
		}
	}
	return doc, nil
}

// LevelName resolves an element header Sub to the level table row's name.
// The Sub of a v8 graphic element equals the row's Number field (u32@0,
// golden-verified: Sub=64 → "Default"/"0", Sub=2..4 → "XRef Level 1..3");
// empty when no named row matches.
func (doc *V8Document) LevelName(levelID uint32) string {
	for _, l := range doc.Levels {
		if l.Number == levelID {
			return l.Name
		}
	}
	return ""
}

func (doc *V8Document) warn(err error) {
	doc.Warnings = append(doc.Warnings, err)
}

// parseMixIndex decodes the Dgn~Mix model index (D98, write side
// FUN_1805cbed0 field-by-field):
//
//	envelope: [u32 magic 0xAA00BA11][u32 ver=4][u32 count][u32 0]
//	per model record:
//	  lead 16B: [u16 flags][u16 field][u32 modelNumber][f64 timestamp(ms)]
//	  name header 16B: [u16 entrySize][u16 shortLen][u32 longLen]
//	                   [u16 extraLen][u16 field][u32 lastSlot]
//	  shortName UTF-16 + longName UTF-16 + extraLen bytes tail block
//
// entrySize = 0x20 + shortLen + longLen + extraLen (goldens 0x54/0x56/0x4a).
// The name-header last slot reads 0 on the 25.4 write side but non-zero in
// the legacy goldens (1 / 0x03e8ceb8 / 0x0022d850 — likely an older writer's
// ID/hash; not consumed on read). Truncated trailing records (attach model 1
// ends 9 bytes into its lead block) yield an unnamed entry.
func parseMixIndex(b []byte) []V8ModelInfo {
	if len(b) < 16 || leU32(b[0:4]) != v8MagicMix {
		return nil
	}
	count := int(leU32(b[8:12]))
	if count > 4096 {
		return nil
	}
	out := make([]V8ModelInfo, 0, count)
	pos := 16
	for i := 0; i < count; i++ {
		if pos+32 > len(b) {
			break // truncated record (legacy writers can under-write count)
		}
		var info V8ModelInfo
		info.Flags = leU16(b[pos:])
		info.ModelNumber = leU32(b[pos+4 : pos+8])
		info.TimestampMS = math.Float64frombits(leU64(b[pos+8 : pos+16]))
		entrySize := int(leU16(b[pos+16:]))
		l1 := int(leU16(b[pos+18:]))
		l2 := int(leU32(b[pos+20:]))
		extra := int(leU16(b[pos+24:]))
		names := pos + 32
		if l1%2 == 0 && l2%2 == 0 && l1 <= 512 && l2 <= 512 &&
			names+l1+l2 <= len(b) &&
			(l1 == 0 || plausibleUTF16(b[names:names+l1])) &&
			(l2 == 0 || plausibleUTF16(b[names+l1:names+l1+l2])) {
			if l1 > 0 {
				info.Short = decodeUTF16(b[names : names+l1])
			}
			if l2 > 0 {
				info.Long = decodeUTF16(b[names+l1 : names+l1+l2])
			}
		}
		out = append(out, info)
		// entrySize covers lead + name header + names + extra tail
		// (attach1: 0x56 = 32+14+24+16). The legacy attach writer inflates
		// it beyond the actual record — fall back to the computed size.
		step := 32 + l1 + l2 + extra
		if entrySize >= 32 && entrySize >= step && pos+entrySize <= len(b) {
			step = entrySize
		}
		pos += step
	}
	return out
}

func plausibleUTF16(b []byte) bool {
	if len(b) == 0 {
		return false
	}
	for i := 0; i+1 < len(b); i += 2 {
		r := rune(leU16(b[i:]))
		if r == 0 || r > 0x7e {
			return false
		}
	}
	return true
}

func decodeUTF16(b []byte) string {
	u := make([]uint16, 0, len(b)/2)
	for i := 0; i+1 < len(b); i += 2 {
		u = append(u, leU16(b[i:]))
	}
	return string(utf16.Decode(u))
}

// modelStorageID reports whether path is a model storage ("Dgn-Md/#NNNNNN")
// and returns its hex ID.
func modelStorageID(path string) (uint64, bool) {
	if len(path) < len(StorageModels)+2 || path[:len(StorageModels)] != StorageModels {
		return 0, false
	}
	rest := path[len(StorageModels)+1:]
	if len(rest) != 7 || rest[0] != '#' {
		return 0, false
	}
	var id uint64
	for _, c := range []byte(rest[1:]) {
		var v uint64
		switch {
		case c >= '0' && c <= '9':
			v = uint64(c - '0')
		case c >= 'a' && c <= 'f':
			v = uint64(c-'a') + 10
		case c >= 'A' && c <= 'F':
			v = uint64(c-'A') + 10
		default:
			return 0, false
		}
		id = id<<4 | v
	}
	return id, true
}

// chunkParent returns the directory part of a chunk path ("Dgn^Nm" or
// "Dgn-Md/#000000/Dgn^G").
func chunkParent(path string) string {
	for i := len(path) - 1; i >= 0; i-- {
		if path[i] == '/' {
			return path[:i]
		}
	}
	return ""
}

func baseName(path string) string {
	for i := len(path) - 1; i >= 0; i-- {
		if path[i] == '/' {
			return path[i+1:]
		}
	}
	return path
}

type cfbStreamEntry struct {
	info cfb.EntryInfo
	data []byte
}

func leU16(b []byte) uint16 {
	return uint16(b[0]) | uint16(b[1])<<8
}

func leU64(b []byte) uint64 {
	return uint64(leU32(b[0:4])) | uint64(leU32(b[4:8]))<<32
}
