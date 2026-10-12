// Package scene defines a neutral geometry IR for DGN documents.
//
// The IR decouples downstream consumers (e.g. the go-topo bridge) from the
// 50+ concrete decoder structs in dgn/element and the V7* readers. Builders
// live in the root dgn package (SceneV7/SceneV8); this package stays pure
// types with zero dependencies. Design: analysis/05-go-design/topo-bridge.md §4.
package scene

import "fmt"

// Kind classifies the geometry carried by an Entity.
type Kind uint8

const (
	KindInvalid       Kind = iota
	KindSegment            // two-point straight line
	KindPolyline           // multi-segment line / shape / bspline poles
	KindArc                // circular arc (start/sweep + two axes)
	KindEllipse            // full ellipse (arc with fixed 0/360 sweep)
	KindPointString        // unconnected points
	KindCone               // frustum: two centers + two radii
	KindSolid              // mesh solid (v8); no IR geometry yet
	KindText               // text node; Origin + optional string
	KindCellDef            // cell/block definition with placement transform
	KindCellRef            // shared-cell reference (name only)
	KindComplexHeader      // complex group header (children carry geometry)
	KindBSplineCurve       // B-spline curve (v7 type 27 + pole/knot siblings)
)

// String returns the kind name for debugging/golden tests.
func (k Kind) String() string {
	switch k {
	case KindSegment:
		return "Segment"
	case KindPolyline:
		return "Polyline"
	case KindArc:
		return "Arc"
	case KindEllipse:
		return "Ellipse"
	case KindPointString:
		return "PointString"
	case KindCone:
		return "Cone"
	case KindSolid:
		return "Solid"
	case KindText:
		return "Text"
	case KindCellDef:
		return "CellDef"
	case KindCellRef:
		return "CellRef"
	case KindComplexHeader:
		return "ComplexHeader"
	case KindBSplineCurve:
		return "BSplineCurve"
	}
	return fmt.Sprintf("Kind(%d)", uint8(k))
}

// Point is a 3D position in document units (raw UOR for SceneV7,
// master units for SceneV7AtMaster, UOR for SceneV8).
type Point struct {
	X, Y, Z float64
}

// Arc carries circular/elliptical parameters. Rotation is the 2D rotation
// in degrees; Quat is the 3D rotation (unit quaternion, W,X,Y,Z) — a
// non-zero Quat supersedes Rotation.
type Arc struct {
	Center        Point
	PrimaryAxis   float64 // axis length 1, document units
	SecondaryAxis float64 // axis length 2
	Start, Sweep  float64 // degrees; Ellipse is fixed 0/360
	Rotation      float64 // degrees CCW (2D)
	Quat          [4]float64
}

// BRep carries the 0x522E OdDgBrepLinkage payload of a SmartSolid/
// SmartSurface (D111, CDGAttribEmbeddedBRep read/write double-proven):
// two flag words, the BRep scale, and the native kernel binary.
type BRep struct {
	Flag1 uint16
	Flag2 uint16
	Scale float64
	Data  []byte
}

// Entity is one geometry-bearing element in a scene.
type Entity struct {
	ID        uint64 // v7: element frame offset; v8: Header.ID
	ParentID  uint64 // complex-group header ID; 0 = top-level
	Kind      Kind
	Dim       uint8        // 2 or 3 (file dimension)
	Level     int          // v7: element level; v8: level entry id
	Color     int32        // raw color index; -1 = unknown
	Name      string       // cell / shared-cell name
	Transform *[16]float64 // cell placement, column-major 4x4; nil otherwise
	Points    []Point      // KindSegment/Polyline/PointString endpoints; KindCone centers; KindText origin; KindBSplineCurve poles
	Faces     [][]int32    // KindSolid (v8 mesh 105): vertex-index face loops into Points; nil = points only (cloud / undecodable faces)
	Radii     [2]float64   // KindCone: radius1, radius2
	Arc       *Arc         // KindArc/KindEllipse
	Text      string       // KindText
	// KindBSplineCurve (v7 type 27): Knots is the full expanded knot
	// vector (order×start + interior + order×end, parametric domain);
	// Weights nil = non-rational; Degree = order−1.
	Knots   []float64
	Weights []float64
	Degree  int
	// DefnOnly marks geometry inside a shared-cell DEFINITION (v7 type 34)
	// span: definition-local coordinates that render only through CellRef
	// instances, never top-level (BIM shared-cell semantics, D93).
	DefnOnly bool
	BBox     [2]Point // raw-UOR header bbox (v7 only); zero when absent
	// BRep marks a SmartSolid/SmartSurface/FeatureSolid: a v8 type-2 cell
	// header carrying a 0x522E OdDgBrepLinkage (D111). Data is the native
	// parasolid/ACIS binary — no Go/OCCT kernel tessellates it, so the
	// entity is metadata-only geometry.
	BRep *BRep
	// DefID is the definition element a v8 KindCellRef instances (D112):
	// the 0x2716 dependency linkage's element-id root. 0 = unknown (the
	// name-based v7 path resolves definitions instead).
	DefID uint64
}
