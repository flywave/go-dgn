package dgn

import (
	"github.com/flywave/go-dgn/dgn/element"
)

// V8MatrixFamily is one Matrix child family of a mesh/solid container:
// a 101 header (IndexFamily + SizeOfRow) followed by its 103/102 data
// blocks. Real-file semantics (D111, 18 meshes across 4 Bentley samples):
// even families carry double data — 2=positions (row 3), 4=normals
// (row 3), 6=UV parameters (row 2) — and odd families carry the matching
// 1-based index tables (1=face table over positions, 3/5=aux indices).
type V8MatrixFamily struct {
	Family  uint32 // 101 IndexFamily
	Row     uint32 // 101 SizeOfRow: values per entry
	Ints    []int32
	Doubles []float64
}

// Entries returns the number of data entries in the family (values/row).
func (f *V8MatrixFamily) Entries() int {
	if f.Row == 0 {
		return 0
	}
	if f.Ints != nil {
		return len(f.Ints) / int(f.Row)
	}
	return len(f.Doubles) / int(f.Row)
}

// V8Mesh is an assembled v8 mesh (type 105 head + its adjacent Matrix
// children, D108/D111). The head body carries a single i32; the geometry
// lives in the Matrix child families.
type V8Mesh struct {
	EntryID uint64
	// Style is element header Sub&0xff as written by the producer. The
	// DgMesh.h style enum (1=FaceLoops…6=QuadGrid) does NOT map to it in
	// real files (Bentley samples write 0x40), so face derivation does not
	// consume it (D111).
	Style uint32
	A     uint32 // head body i32 (semantics [?])
	// Points are the mesh vertices: the family-2 (stride-3) position
	// entries; when family 2 is absent, the first even family with
	// row stride 3. Auxiliary families (normals/UV) never pollute it.
	Points [][3]float64
	// Ints are the raw i32 stream of the odd-family 102 blocks (face
	// index tables; see Faces).
	Ints []int32
	// Families are the assembled Matrix children in file order.
	Families []V8MatrixFamily
}

// assembleV8Meshes walks a chunk's parsed elements and groups type-105
// heads with their adjacent 101/102/103 Matrix children.
func assembleV8Meshes(elements []Parsed) []*V8Mesh {
	_, at := assembleV8MeshAt(elements)
	out := make([]*V8Mesh, 0, len(at))
	for i := range elements {
		if m, ok := at[i]; ok {
			out = append(out, m)
		}
	}
	return out
}

// assembleV8MeshAt groups type-105 heads with their adjacent Matrix
// children and indexes the result by the head's position in elements.
// consumed marks the children (heads included in at).
func assembleV8MeshAt(elements []Parsed) (consumed map[int]bool, at map[int]*V8Mesh) {
	consumed = map[int]bool{}
	at = map[int]*V8Mesh{}
	isMatrix := func(t uint16) bool { return t == 101 || t == 102 || t == 103 }
	for i := range elements {
		p := &elements[i]
		if p.Record.Type != 105 {
			continue
		}
		mesh := &V8Mesh{EntryID: p.Record.ID, Style: p.Record.Subtype & 0xff}
		if b, ok := p.Body.(*Body); ok {
			if mh, ok := b.Value.(*element.MeshHeader); ok {
				mesh.A = mh.A
			}
		}
		family := uint32(0)
		row := uint32(0)
		for j := i + 1; j < len(elements) && isMatrix(elements[j].Record.Type); j++ {
			b, ok := elements[j].Body.(*Body)
			if !ok {
				continue
			}
			consumed[j] = true
			switch v := b.Value.(type) {
			case *element.MatrixHeader:
				family, row = v.IndexFamily, v.SizeOfRow
				mesh.Families = append(mesh.Families, V8MatrixFamily{Family: family, Row: row})
			case *element.MatrixDoubleData:
				f := mesh.appendFamily(family, row)
				f.Doubles = append(f.Doubles, v.Values...)
			case *element.MatrixIntData:
				f := mesh.appendFamily(family, row)
				f.Ints = append(f.Ints, v.Values...)
			}
		}
		mesh.finish()
		at[i] = mesh
	}
	return consumed, at
}

// appendFamily returns the trailing family when it matches id (chunked
// data blocks), else appends a fresh one.
func (m *V8Mesh) appendFamily(id, row uint32) *V8MatrixFamily {
	if n := len(m.Families); n > 0 && m.Families[n-1].Family == id {
		return &m.Families[n-1]
	}
	m.Families = append(m.Families, V8MatrixFamily{Family: id, Row: row})
	return &m.Families[len(m.Families)-1]
}

// finish derives Points (position family) and Ints (face-table stream)
// from the assembled families: positions = family 2, falling back to the
// first even family with row stride 3.
func (m *V8Mesh) finish() {
	pos := -1
	for i := range m.Families {
		f := &m.Families[i]
		if f.Family == 2 && f.Row == 3 {
			pos = i
			break
		}
	}
	if pos < 0 {
		for i := range m.Families {
			f := &m.Families[i]
			if f.Family%2 == 0 && f.Row == 3 {
				pos = i
				break
			}
		}
	}
	if pos >= 0 {
		v := m.Families[pos].Doubles
		for k := 0; k+2 < len(v); k += 3 {
			m.Points = append(m.Points, [3]float64{v[k], v[k+1], v[k+2]})
		}
	}
	var ints []int32
	for i := range m.Families {
		f := &m.Families[i]
		if f.Ints != nil {
			ints = append(ints, f.Ints...)
		}
	}
	m.Ints = ints
}

// Faces derives the 0-based vertex-index face loops from the odd-family
// index tables (D111, pinned on 18 meshes across 4 Bentley samples):
//
//   - the 102 stream is a sequence of faces, each a list of vertex
//     indices terminated by 0 (the stream ends with its last face's 0);
//   - indices are 1-BASED into the position table;
//   - the sign bit is the per-vertex impliedVisibleEdge flag (geometry
//     drops it — topology needs only |index|).
//
// A stream is accepted only when every face has ≥3 vertices and every
// index is in [1, nPoints]; anything else yields nil (宁缺勿错).
func (m *V8Mesh) Faces() [][]int32 {
	n := len(m.Points)
	if n == 0 {
		return nil
	}
	var stream []int32
	for i := range m.Families {
		f := &m.Families[i]
		if f.Family%2 == 1 && f.Ints != nil {
			stream = f.Ints
			break // family 1 = the face table over positions
		}
	}
	if stream == nil {
		return nil
	}
	var faces [][]int32
	cur := []int32{}
	for _, v := range stream {
		if v == 0 {
			if len(cur) >= 3 {
				faces = append(faces, cur)
			}
			cur = []int32{}
			continue
		}
		idx := v
		if idx < 0 {
			idx = -idx
		}
		if idx < 1 || int(idx) > n {
			return nil // out of range — not a face table
		}
		cur = append(cur, idx-1) // 1-based file → 0-based consumer
	}
	if len(cur) >= 3 {
		faces = append(faces, cur)
	}
	return faces
}

// Meshes assembles the meshes of one model from its graphics/control
// chunks.
func (doc *V8Document) Meshes(m *V8Model) []*V8Mesh {
	var out []*V8Mesh
	for _, prefix := range []string{m.Storage + "/" + StorageGraphics, m.Storage + "/" + StorageControl} {
		for _, chunk := range doc.chunksByParent[prefix] {
			out = append(out, assembleV8Meshes(chunk.Elements)...)
		}
	}
	return out
}
