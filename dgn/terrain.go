package dgn

// Terrain XAttribute decoding (D143): OpenRoads stores a Terrain Model's
// triangle mesh as a family of XAttributes attached to the file's
// attribute-side heap chunks (Dgn^CA/$N, the mirror of the control
// chunks) — OdDgTerrainVertexCoordinatesXAttribute (0x58EC012E, f64 xyz
// triplets) and OdDgTerrainVertexTopologyXAttribute (0x58EC012F, triangle
// index triplets). Each XAttribute record in the heap is
// [u32 handlerID][u32 size|0x80000000][data].

import (
	"encoding/binary"
	"math"

	"github.com/flywave/go-delaunay"
	"github.com/flywave/go-dgn/dgn/scene"
)

const (
	xattrTerrainVertexCoordinates = 0x58EC012E
	xattrTerrainVertexTopology    = 0x58EC012F
)

// TerrainMesh is one decoded OpenRoads terrain surface.
type TerrainMesh struct {
	Points [][3]float64 // vertices, file (master) units
	Faces  [][3]int32   // triangle vertex indices
}

// DecodeTerrainHeaps scans every attribute-side heap in the document for
// the terrain vertex/topology XAttribute pair and assembles mesh(es). The
// TxDOT terrain corpus carries exactly one Coordinates+Topology pair per
// terrain model; pairs are matched in scan order.
func DecodeTerrainHeaps(doc *V8Document) []TerrainMesh {
	var coords [][]float64
	var topos [][]byte
	for _, ch := range doc.Chunks {
		if len(ch.Heap) == 0 {
			continue
		}
		h := ch.Heap
		for i := 0; i+16 <= len(h); {
			id := binary.LittleEndian.Uint32(h[i:])
			tag := binary.LittleEndian.Uint32(h[i+8:])
			if tag&0x80000000 == 0 || id == 0 {
				i++
				continue
			}
			size := int(tag &^ uint32(0x80000000))
			if size < 0 || i+16+size > len(h) || size == 0 {
				i++
				continue
			}
			data := h[i+16 : i+16+size]
			switch id {
			case xattrTerrainVertexCoordinates:
				if size%24 == 0 {
					coords = append(coords, cloneF64(data))
				}
			case xattrTerrainVertexTopology:
				if size%12 == 0 {
					topos = append(topos, append([]byte(nil), data...))
				}
			}
			i += 16 + size
		}
	}
	var out []TerrainMesh
	n := len(coords)
	if len(topos) < n {
		n = len(topos)
	}
	// Coordinates-only terrains still surface as point meshes — the
	// 428-vertex TxDOT terrain decodes exactly (state-plane f64s), while
	// the triangle definition's xattr is not yet located (D143 work
	// order: rebuild from the 0x58EC012F vertex→triangle adjacency +
	// 0x58EC0130 edges, or crack OdDgTerrain's remaining handlers).
	for k := 0; k < len(coords); k++ {
		var m TerrainMesh
		cd := coords[k]
		nv := len(cd) / 3
		if nv == 0 {
			continue
		}
		for v := 0; v < nv; v++ {
			x, y, z := cd[v*3], cd[v*3+1], cd[v*3+2]
			if math.IsNaN(x) || math.IsNaN(y) || math.IsNaN(z) ||
				math.IsInf(x, 0) || math.IsInf(y, 0) || math.IsInf(z, 0) {
				nv = v // truncate at first bad vertex
				break
			}
			m.Points = append(m.Points, [3]float64{x, y, z})
		}
		if k < n {
			td := topos[k]
			if len(td) >= 12 {
				nv := len(m.Points)
				tri := td
				nt := len(tri) / 12
				for t := 0; t < nt; t++ {
					a := int32(binary.LittleEndian.Uint32(tri[t*12:]))
					b := int32(binary.LittleEndian.Uint32(tri[t*12+4:]))
					c := int32(binary.LittleEndian.Uint32(tri[t*12+8:]))
					if a < 0 || b < 0 || c < 0 || int(a) >= nv || int(b) >= nv || int(c) >= nv {
						continue // drop out-of-range triangles, keep the rest
					}
					m.Faces = append(m.Faces, [3]int32{a, b, c})
				}
			}
		}
		if len(m.Points) > 0 {
			out = append(out, m)
		}
	}
	return out
}

func cloneF64(b []byte) []float64 {
	out := make([]float64, len(b)/8)
	for i := range out {
		out[i] = math.Float64frombits(binary.LittleEndian.Uint64(b[i*8:]))
	}
	return out
}

// SceneV8Terrain decodes terrain meshes from the document heaps and
// surfaces them as KindSolid mesh entities (same entity shape as the v8
// mesh 105 path, so the go-topo bridge consumes them unchanged). Terrain
// XAttribute coordinates are already in master units — no UOR scaling.
//
// When the xattr family carries no explicit triangle table (the OpenRoads
// norm — triangulation is kernel-generated, D148), the TIN is rebuilt
// with an unconstrained Delaunay triangulation over the decoded vertex
// XY set (D150): the 428-vertex TxDOT terrain yields ~840 triangles that
// cover every vertex.
func SceneV8Terrain(doc *V8Document) ([]scene.Entity, error) {
	var out []scene.Entity
	for _, m := range DecodeTerrainHeaps(doc) {
		e := scene.Entity{Kind: scene.KindSolid, Dim: 3}
		for _, p := range m.Points {
			e.Points = append(e.Points, scene.Point{X: p[0], Y: p[1], Z: p[2]})
		}
		if len(m.Faces) >= len(m.Points)-2 {
			// a complete TIN carried by the file
			for _, f := range m.Faces {
				e.Faces = append(e.Faces, []int32{f[0], f[1], f[2]})
			}
		} else if len(m.Points) >= 3 {
			// incomplete or absent triangle table — triangulate the vertex
			// set (generative enhancement, D150)
			for _, tri := range delaunayTIN(m.Points) {
				e.Faces = append(e.Faces, []int32{tri[0], tri[1], tri[2]})
			}
		}
		out = append(out, e)
	}
	return out, nil
}

// delaunayTIN triangulates a vertex set with the flywave go-delaunay
// library (pure Go Delaunay; D150 — replaces the hand-written
// Bowyer-Watson whose cavity rebuild stranded interior vertices).
func delaunayTIN(pts [][3]float64) [][3]int32 {
	p := make([]delaunay.Point, len(pts))
	for i, q := range pts {
		p[i] = delaunay.Point{q[0], q[1]}
	}
	tri, err := delaunay.Triangulate(p)
	if err != nil {
		return nil
	}
	var out [][3]int32
	for _, ids := range tri.GetTrianglesPointsMap() {
		if len(ids) == 3 {
			out = append(out, [3]int32{int32(ids[0]), int32(ids[1]), int32(ids[2])})
		}
	}
	return out
}
