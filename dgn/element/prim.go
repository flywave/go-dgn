package element

import (
	"github.com/flywave/go-dgn/internal/le"
)

// Primitive shared types for element body readers: the point-count
// sanity limit and the Point2d/Point3d/Quaternion value types.

const pointCountSanity = 10000

type Point2d struct {
	X, Y float64
}

type Point3d struct {
	X, Y, Z float64
}

type Quaternion struct {
	W, X, Y, Z float64
}

func readQuat(r *le.Reader) Quaternion {
	return Quaternion{W: r.F64(), X: r.F64(), Y: r.F64(), Z: r.F64()}
}
