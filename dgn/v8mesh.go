package dgn

import (
	"github.com/flywave/go-dgn/dgn/element"
)

// V8Mesh is an assembled v8 mesh (type 105 head + its adjacent Matrix
// children, D108): the head body carries a single i32 (semantics [?]), the
// following 101 Header + 103/102 data blocks carry the geometry — the same
// adjacency pattern as Solid/Surface and the v8 B-spline assemblies.
type V8Mesh struct {
	EntryID uint64
	Style   uint32 // element header Sub&0xff: 1=FaceLoops … 6=QuadGrid (E1)
	A       uint32 // head body i32 (semantics [?])
	// Points come from the adjacent MatrixDoubleData(103) blocks: three
	// consecutive f64 per vertex.
	Points [][3]float64
	// Ints are the raw i32 stream of the adjacent MatrixIntData(102)
	// blocks (mesh face/index data — per-face layout [?]).
	Ints []int32
}

// assembleV8Meshes walks a chunk's parsed elements and groups type-105
// heads with their adjacent 101/102/103 Matrix children.
func assembleV8Meshes(elements []Parsed) []*V8Mesh {
	var out []*V8Mesh
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
		for j := i + 1; j < len(elements) && isMatrix(elements[j].Record.Type); j++ {
			b, ok := elements[j].Body.(*Body)
			if !ok {
				continue
			}
			switch v := b.Value.(type) {
			case *element.MatrixDoubleData:
				for k := 0; k+2 < len(v.Values); k += 3 {
					mesh.Points = append(mesh.Points, [3]float64{v.Values[k], v.Values[k+1], v.Values[k+2]})
				}
			case *element.MatrixIntData:
				mesh.Ints = append(mesh.Ints, v.Values...)
			}
		}
		out = append(out, mesh)
	}
	return out
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
