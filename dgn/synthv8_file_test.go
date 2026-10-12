package dgn

import (
	"encoding/binary"
	"fmt"
	"math"
	"os"
	"path/filepath"
	"strings"
	"testing"

	"github.com/flywave/go-dgn/internal/cfb/cfbtest"
)

// --- file-level synthetic v8 fixture (D124) ---
//
// Assembles a complete CFB container carrying one model whose graphics
// chunk holds: a SharedCellReference(35) with its 0x2716 dependency
// linkage, the SharedCellDefinition(34) with its 0x56D2 name linkage and
// a flag-bit14 line child, and a SmartSolid (type-2 cell header with a
// 0x522E BrepLinkage carrying the real ACIS sphere from OdWriteEx.sat).
// The fixture exercises the full file-level pipeline (CFB → V8 chunk
// walk → ParseElements → SceneV8ModelAtMaster) that chunk-level
// synthetic tests bypass.

type v8rec struct {
	typ  uint16
	flag uint16
	sub  uint32
	id   uint64
	body []byte // after the 36-byte header (+ display header when set)
	link []byte // attribute/linkage region ((B-C)*2 at the tail)
	disp bool   // 72-byte display header present (properties bit11 → 3D)
}

func (r v8rec) encode() []byte {
	dh := 0
	if r.disp {
		dh = 72
	}
	bw := len(r.body)
	lw := len(r.link)
	total := 36 + dh + bw + lw
	b := uint32((total - 4) / 2)
	c := uint32((36 + dh + bw - 4) / 2)
	h := make([]byte, 36)
	flag := r.flag
	if r.disp {
		flag |= 1 << 12
	}
	binary.LittleEndian.PutUint16(h[4:], r.typ)
	binary.LittleEndian.PutUint16(h[6:], flag)
	binary.LittleEndian.PutUint32(h[8:], b)
	binary.LittleEndian.PutUint32(h[12:], c)
	binary.LittleEndian.PutUint32(h[16:], r.sub)
	binary.LittleEndian.PutUint64(h[20:], r.id)
	out := append(h, make([]byte, dh)...)
	if r.disp {
		binary.LittleEndian.PutUint16(out[36+8:], 1<<11) // Properties: 3D
	}
	out = append(out, r.body...)
	return append(out, r.link...)
}

func u16le(b []byte, v uint16) []byte { return binary.LittleEndian.AppendUint16(b, v) }
func u32le(b []byte, v uint32) []byte { return binary.LittleEndian.AppendUint32(b, v) }
func u64le(b []byte, v uint64) []byte { return binary.LittleEndian.AppendUint64(b, v) }

func attrLinkage(id uint16, payload []byte) []byte {
	out := u16le(nil, uint16((len(payload)+2)/2)|0x1000)
	out = u16le(out, id)
	return append(out, payload...)
}

// TestWriteSyntheticSharedCellSmartSolidFile generates the file-level v8
// fixture into testdata and validates the go-dgn pipeline on it
// (CFB → V8 → SceneV8ModelAtMaster).
func TestWriteSyntheticSharedCellSmartSolidFile(t *testing.T) {
	// SharedCellReference(35): placement mat = identity, translation
	// (10,20,30); 0x2716 dependency → definition handle 0x64.
	instBody := u32le(nil, 77)
	instBody = u16le(instBody, 1)
	instBody = u16le(instBody, 2)
	instBody = append(instBody, f64le(1, 2, 3)...) // range
	instBody = append(instBody, f64le(4, 5, 6)...) // range
	instBody = append(instBody, f64le(1, 0, 0, 0, 1, 0, 0, 0, 1)...)
	instBody = append(instBody, f64le(10, 20, 30)...) // translation
	dep := u16le(nil, 0x2716)
	dep = u16le(dep, 0)
	dep = u16le(dep, 0) // root data type = kElementId
	dep = u16le(dep, 1)
	dep = u64le(dep, 0x64)
	instRec := v8rec{typ: 35, id: 500, body: instBody, link: attrLinkage(0x56d0, dep)}

	// SharedCellDefinition(34): name via 0x56D2 StringLinkage(id 1).
	defBody := u16le(nil, 1)
	defBody = u16le(defBody, 2)
	defBody = append(defBody, f64le(0, 0, 0)...)
	defBody = append(defBody, f64le(9, 9, 9)...)
	defBody = append(defBody, f64le(1, 0, 0, 0, 1, 0, 0, 0, 1)...)
	defBody = append(defBody, f64le(0, 0, 0)...)
	name := u32le(nil, 1)
	name = u32le(name, 6)
	name = append(name, "CELL01"...)
	defRec := v8rec{typ: 34, id: 0x64, body: defBody, link: attrLinkage(0x56d2, name)}

	// flag-bit14 line child of the definition (2D line, ext 0).
	lineBody := make([]byte, 32)
	f64leAt := func(b []byte, off int, v float64) { binary.LittleEndian.PutUint64(b[off:], math.Float64bits(v)) }
	f64leAt(lineBody, 0, 5)
	f64leAt(lineBody, 8, 6)
	f64leAt(lineBody, 16, 15)
	f64leAt(lineBody, 24, 16)
	lineRec := v8rec{typ: 3, flag: 1 << 14, id: 200, body: lineBody}

	// SmartSolid: type-2 cell header + 0x522E BrepLinkage with the real
	// ACIS sphere from OdWriteEx.sat.
	sat, err := os.ReadFile("testdata/OdWriteEx.sat")
	if err != nil {
		t.Skipf("ACIS sample absent: %v", err)
	}
	brepPayload := u16le(nil, 5)                     // flag1
	brepPayload = u16le(brepPayload, 2)              // flag2 = kAcisData
	brepPayload = append(brepPayload, f64le(1.0)...) // scale
	brepPayload = append(brepPayload, sat...)        // native ACIS
	if len(brepPayload)%2 == 1 {
		brepPayload = append(brepPayload, 0) // even-align the record
	}
	ssBody := u16le(nil, 1) // cell header H
	ssBody = append(ssBody, f64le(0, 0, 0)...)
	ssBody = append(ssBody, f64le(0, 0, 0)...)
	ssBody = append(ssBody, f64le(1, 0, 0, 0, 1, 0, 0, 0, 1)...)
	ssBody = append(ssBody, f64le(0, 0, 0)...) // P3
	ssRec := v8rec{typ: 2, disp: true, id: 300, body: ssBody, link: attrLinkage(0x522e, brepPayload)}

	recs := []v8rec{instRec, defRec, lineRec, ssRec}
	var space []byte
	for _, r := range recs {
		space = append(space, r.encode()...)
	}
	chunk := u32le(nil, uint32(len(recs)))
	chunk = u32le(chunk, 0)
	chunk = append(chunk, space...)

	data := cfbtest.WriteTree(map[string]interface{}{
		"Dgn-Md": map[string]interface{}{
			"#000000": map[string]interface{}{
				"Dgn^G": map[string]interface{}{
					"$1": chunk,
				},
			},
		},
	})
	out := filepath.Join("testdata", "v8_synth_sc_ss.dgn")
	if err := os.WriteFile(out, data, 0o644); err != nil {
		t.Fatal(err)
	}

	// go-dgn pipeline check on the written file.
	f, err := Open(out)
	if err != nil {
		t.Fatalf("open: %v", err)
	}
	doc, err := f.V8()
	if err != nil {
		t.Fatalf("v8: %v", err)
	}
	if len(doc.Models) != 1 {
		t.Fatalf("models = %d", len(doc.Models))
	}
	ents, err := SceneV8ModelAtMaster(doc, doc.Models[0])
	if err != nil {
		t.Fatalf("scene: %v", err)
	}
	byID := map[uint64]int{}
	for i := range ents {
		byID[ents[i].ID] = i
	}
	if i, ok := byID[500]; !ok || ents[i].Kind.String() != "CellRef" || ents[i].DefID != 0x64 {
		t.Fatalf("inst missing/bad: %+v", ents[i])
	}
	if i, ok := byID[0x64]; !ok || ents[i].Kind.String() != "CellDef" || ents[i].Name != "CELL01" {
		t.Fatalf("def missing/bad (present=%v)", ok)
	}
	if i, ok := byID[300]; !ok || ents[i].Kind.String() != "Solid" {
		ch := doc.Chunks["Dgn-Md/#000000/Dgn^G/$1"]
		var parts []string
		for _, el := range ch.Elements {
			lg := ""
			for _, l := range el.Linkages {
				lg += fmt.Sprintf("{%#x n=%d}", l.TypeID, len(l.Raw))
			}
			parts = append(parts, fmt.Sprintf("idx=%d type=%d links=[%s]",
				el.Entry.Index, el.Record.Type, lg))
		}
		t.Fatalf("smartsolid kind=%s brep=%v: %s",
			ents[byID[300]].Kind, ents[byID[300]].BRep != nil, strings.Join(parts, " | "))
	}
}
