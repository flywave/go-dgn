package dgn

import (
	"encoding/binary"
	"math"
	"testing"

	"github.com/flywave/go-dgn/dgn/scene"
)

// v8f64 appends a little-endian float64.
func v8f64(b []byte, v float64) []byte {
	return binary.LittleEndian.AppendUint64(b, math.Float64bits(v))
}

// v8pt3 appends a Point3d triple.
func v8pt3(b []byte, x, y, z float64) []byte {
	return v8f64(v8f64(v8f64(b, x), y), z)
}

// TestSceneV8SharedCellInst pins the v8 shared-cell reference semantics
// (D111): fields u32,u16,u16,Pt3d×2,Mat(9),Pt3d — the trailing Pt3d is
// the placement translation, the 3×3 the rotation; the entity surfaces
// as KindCellRef with a placement transform.
func TestSceneV8SharedCellInst(t *testing.T) {
	body := binary.LittleEndian.AppendUint32(nil, 77)        // A
	body = binary.LittleEndian.AppendUint16(body, 1)         // B
	body = binary.LittleEndian.AppendUint16(body, 2)         // C
	body = v8pt3(body, 1, 2, 3)                              // Origin1 (range)
	body = v8pt3(body, 4, 5, 6)                              // Origin2 (range)
	for _, v := range []float64{1, 0, 0, 0, 1, 0, 0, 0, 1} { // Mat = identity
		body = v8f64(body, v)
	}
	body = v8pt3(body, 10, 20, 30) // Origin3 = translation

	rec := v8HeaderBytes(Header{Type: 35, Flag: 0, B: 76, C: 76, ID: 100})
	rec = append(rec, body...)
	rec = rec[:92*2+4]

	space := join(binary.LittleEndian.AppendUint32(nil, 1),
		binary.LittleEndian.AppendUint32(nil, 0), rec)
	idx := BuildChunkIndex(space)
	ents, err := SceneV8(space, Dir{Base: 0, Offsets: idx.Offsets})
	if err != nil {
		t.Fatal(err)
	}
	if len(ents) != 1 {
		t.Fatalf("entities = %d", len(ents))
	}
	e := ents[0]
	if e.Kind != scene.KindCellRef {
		t.Fatalf("kind = %v", e.Kind)
	}
	if e.Transform == nil {
		t.Fatal("transform is nil")
	}
	tr := e.Transform
	if tr[0] != 1 || tr[5] != 1 || tr[10] != 1 || tr[15] != 1 {
		t.Fatalf("rotation block = %v", tr)
	}
	if tr[12] != 10 || tr[13] != 20 || tr[14] != 30 {
		t.Fatalf("translation = %v", tr[12:15])
	}
}

// TestSceneV8BRepCellHeader pins the SmartSolid surfacing (D111): a type-2
// cell header carrying a 0x522E BRep linkage becomes a KindSolid entity
// with the BRep metadata instead of a cell definition.
func TestSceneV8BRepCellHeader(t *testing.T) {
	chBody := binary.LittleEndian.AppendUint16(nil, 1) // H
	chBody = binary.LittleEndian.AppendUint16(chBody, 2)
	chBody = v8pt3(chBody, 0, 0, 0)                          // P1
	chBody = v8pt3(chBody, 9, 9, 9)                          // P2
	for _, v := range []float64{1, 0, 0, 0, 1, 0, 0, 0, 1} { // M
		chBody = v8f64(chBody, v)
	}
	chBody = v8pt3(chBody, 0, 0, 0) // P3
	if len(chBody) != 148 {
		t.Fatalf("cell body = %d", len(chBody))
	}

	// 0x522E linkage envelope: [u16 count|userData][u16 typeID][payload]
	payload := binary.LittleEndian.AppendUint16(nil, 5)    // flag1
	payload = binary.LittleEndian.AppendUint16(payload, 1) // flag2 (kParasolidData)
	payload = v8f64(payload, 1.0)                          // scale
	payload = append(payload, 0xDE, 0xAD, 0xBE, 0xEF)      // native BRep bytes
	linkage := binary.LittleEndian.AppendUint16(nil, uint16((len(payload)+2)/2)|0x1000)
	linkage = binary.LittleEndian.AppendUint16(linkage, 0x522e)
	linkage = append(linkage, payload...)

	// 3D variant: a display header whose Properties bit 11 selects the
	// p3(2) CellHeader3d decoder (no display header → ext=0 → 2D).
	dh := make([]byte, 72)
	binary.LittleEndian.PutUint16(dh[8:], 1<<11) // Properties: 3D
	hdr := v8HeaderBytes(Header{Type: 2, Flag: FlagDisplayHeader, B: 138, C: 126, ID: 101})
	rec := append(hdr, dh...)
	rec = append(rec, chBody...)
	rec = append(rec, linkage...)
	rec = rec[:138*2+4]

	space := join(binary.LittleEndian.AppendUint32(nil, 1),
		binary.LittleEndian.AppendUint32(nil, 0), rec)
	idx := BuildChunkIndex(space)
	ents, err := SceneV8(space, Dir{Base: 0, Offsets: idx.Offsets})
	if err != nil {
		t.Fatal(err)
	}
	if len(ents) != 1 {
		t.Fatalf("entities = %d", len(ents))
	}
	e := ents[0]
	if e.Kind != scene.KindSolid {
		t.Fatalf("kind = %v", e.Kind)
	}
	if e.BRep == nil {
		t.Fatal("brep is nil")
	}
	if e.BRep.Flag1 != 5 || e.BRep.Flag2 != 1 || e.BRep.Scale != 1.0 || len(e.BRep.Data) != 4 {
		t.Fatalf("brep = %+v", e.BRep)
	}
}

// TestSceneV8SharedCellRoundTrip pins the D112 instancing chain: the
// instance's 0x2716 dependency carries the definition handle, the
// definition's name rides a 0x56D2 StringLinkage(id 1), and the
// definition's geometry is the adjacent flag-bit14 run.
func TestSceneV8SharedCellRoundTrip(t *testing.T) {
	u16le := func(b []byte, v uint16) []byte { return binary.LittleEndian.AppendUint16(b, v) }
	u32le := func(b []byte, v uint32) []byte { return binary.LittleEndian.AppendUint32(b, v) }
	u64le := func(b []byte, v uint64) []byte { return binary.LittleEndian.AppendUint64(b, v) }

	// instance: 152B body (translation 10,20,30) + 0x56D0 dependency
	instBody := u32le(nil, 77)
	instBody = u16le(instBody, 1)
	instBody = u16le(instBody, 2)
	instBody = v8pt3(instBody, 1, 2, 3)
	instBody = v8pt3(instBody, 4, 5, 6)
	for _, v := range []float64{1, 0, 0, 0, 1, 0, 0, 0, 1} {
		instBody = v8f64(instBody, v)
	}
	instBody = v8pt3(instBody, 10, 20, 30)
	depPayload := u16le(nil, 0x2716) // shared-cell def dependency (app id)
	depPayload = u16le(depPayload, 0)
	depPayload = u16le(depPayload, 0) // rootDataType = kElementId
	depPayload = u16le(depPayload, 1)
	depPayload = u64le(depPayload, 0x64)
	dep := u16le(nil, uint16((len(depPayload)+2)/2)|0x1000)
	dep = u16le(dep, 0x56d0)
	dep = append(dep, depPayload...)
	inst := v8HeaderBytes(Header{Type: 35, Flag: 0, B: 102, C: 92, ID: 100})
	inst = append(inst, instBody...)
	inst = append(inst, dep...)
	inst = inst[:102*2+4]

	// definition: 148B body + 0x56D2 name string (id 1)
	defBody := u16le(nil, 1)
	defBody = u16le(defBody, 2)
	defBody = v8pt3(defBody, 0, 0, 0)
	defBody = v8pt3(defBody, 9, 9, 9)
	for _, v := range []float64{1, 0, 0, 0, 1, 0, 0, 0, 1} {
		defBody = v8f64(defBody, v)
	}
	defBody = v8pt3(defBody, 0, 0, 0)
	strPayload := u32le(nil, 1) // name linkage id
	strPayload = u32le(strPayload, 6)
	strPayload = append(strPayload, "CELL01"...)
	str := u16le(nil, uint16((len(strPayload)+2)/2)|0x1000)
	str = u16le(str, 0x56d2)
	str = append(str, strPayload...)
	def := v8HeaderBytes(Header{Type: 34, Flag: 0, B: 101, C: 90, ID: 200})
	def = append(def, defBody...)
	def = append(def, str...)
	def = def[:101*2+4]

	// child line: 2D line (32B body), flag bit14 = complex-chain member
	lineBody := make([]byte, 32)
	binary.LittleEndian.PutUint64(lineBody[0:], math.Float64bits(5))
	binary.LittleEndian.PutUint64(lineBody[8:], math.Float64bits(6))
	binary.LittleEndian.PutUint64(lineBody[16:], math.Float64bits(15))
	binary.LittleEndian.PutUint64(lineBody[24:], math.Float64bits(16))
	child := v8HeaderBytes(Header{Type: 3, Flag: 1 << 14, B: 32, C: 32, ID: 201})
	child = append(child, lineBody...)
	child = child[:32*2+4]

	var buf []byte
	buf = append(buf, inst...)
	buf = append(buf, def...)
	buf = append(buf, child...)
	space := join(binary.LittleEndian.AppendUint32(nil, 3), binary.LittleEndian.AppendUint32(nil, 0), buf)
	idx := BuildChunkIndex(space)
	ents, err := SceneV8(space, Dir{Base: 0, Offsets: idx.Offsets})
	if err != nil {
		t.Fatal(err)
	}
	if len(ents) != 3 {
		t.Fatalf("entities = %d", len(ents))
	}
	inst0, def0, child0 := ents[0], ents[1], ents[2]
	if inst0.Kind != scene.KindCellRef || inst0.DefID != 0x64 {
		t.Fatalf("inst = %+v", inst0)
	}
	if def0.Kind != scene.KindCellDef || def0.Name != "CELL01" {
		t.Fatalf("def = %+v", def0)
	}
	if child0.Kind != scene.KindSegment || child0.ParentID != 200 || !child0.DefnOnly {
		t.Fatalf("child = %+v", child0)
	}
}
