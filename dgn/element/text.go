package element

import (
	"github.com/flywave/go-dgn/internal/le"
)

// Text body readers: 2D/3D text and text-node elements (D70 layouts).

type TextNode struct {
	U32a   uint32
	U32b   uint32
	U16a   uint16
	U16b   uint16
	D      [4]float64
	Origin Point2d
}

func ReadTextNode(r *le.Reader) (*TextNode, error) {
	t := &TextNode{
		U32a: r.U32(),
		U32b: r.U32(),
		U16a: r.U16(),
		U16b: r.U16(),
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range t.D {
		t.D[i] = r.F64()
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.Origin = Point2d{X: r.F64(), Y: r.F64()}
	return t, r.Err()
}

// TextNode3d layout (D70 write/read cross-validation): u32×2, u16×2,
// f64×3, quaternion rotation, Point3d origin (92B body).
type TextNode3d struct {
	U32a   uint32
	U32b   uint32
	U16a   uint16
	U16b   uint16
	D      [3]float64
	Rot    Quaternion
	Origin Point3d
}

func ReadTextNode3d(r *le.Reader) (*TextNode3d, error) {
	t := &TextNode3d{U32a: r.U32(), U32b: r.U32(), U16a: r.U16(), U16b: r.U16()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range t.D {
		t.D[i] = r.F64()
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.Rot = readQuat(r)
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.Origin = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	return t, r.Err()
}

type Text struct {
	A         uint32
	B         uint16
	Length    uint16
	Layout    [5]float64
	Origin    Point2d
	CharCount uint16
	Value     []byte
	CharAttrs []byte
}

func ReadText(r *le.Reader) (*Text, error) {
	t := &Text{A: r.U32(), B: r.U16(), Length: r.U16()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range t.Layout {
		t.Layout[i] = r.F64()
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.Origin = Point2d{X: r.F64(), Y: r.F64()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.CharCount = r.U16()
	t.Value = r.Bytes(int(t.Length))
	if r.Err() != nil {
		return nil, r.Err()
	}
	if t.CharCount > 0 {
		need := int(t.CharCount) * 3
		if r.Remaining() < need {
			t.CharCount = 0
			_ = r.Rest()
		} else {
			t.CharAttrs = r.Bytes(need)
		}
	}
	if r.Remaining() > 0 && r.Tell()&1 != 0 {
		_ = r.Seek(r.Tell() + 1)
	}
	return t, r.Err()
}

// Text3d layout (D70 write/read cross-validation): u32 A, u16 B, u16 L,
// f64×4 layout, quaternion rotation, origin, u16 N, bytes[L], N×3 char
// attrs (3D HAS the attr table — D37勘误), 16-bit align pad.
type Text3d struct {
	A         uint32
	B         uint16
	Length    uint16
	D         [4]float64
	Rot       Quaternion
	Origin    Point3d
	N         uint16
	Value     []byte
	CharAttrs []byte
}

func ReadText3d(r *le.Reader) (*Text3d, error) {
	t := &Text3d{A: r.U32(), B: r.U16(), Length: r.U16()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	for i := range t.D {
		t.D[i] = r.F64()
	}
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.Rot = readQuat(r)
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.Origin = Point3d{X: r.F64(), Y: r.F64(), Z: r.F64()}
	if r.Err() != nil {
		return nil, r.Err()
	}
	t.N = r.U16()
	t.Value = r.Bytes(int(t.Length))
	if r.Err() != nil {
		return nil, r.Err()
	}
	if t.N > 0 {
		need := int(t.N) * 3
		if r.Remaining() < need {
			t.N = 0
			_ = r.Rest()
		} else {
			t.CharAttrs = r.Bytes(need)
		}
	}
	if r.Remaining() > 0 && r.Tell()&1 != 0 {
		_ = r.Seek(r.Tell() + 1)
	}
	return t, r.Err()
}
