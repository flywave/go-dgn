package dgn

import (
	"github.com/flywave/go-dgn/dgn/element"
	"github.com/flywave/go-dgn/internal/le"
)

type Body struct {
	Type  uint16
	Value any
}

func (b *Body) ElementType() uint16 { return b.Type }

func p0(t uint16, fn func(*le.Reader) (any, error)) {
	_ = Register(RegistryKey{Type: t, Group: Group2D3D, Value: 0},
		func(r *le.Reader, h *Header) (Element, error) {
			v, err := fn(r)
			return &Body{Type: h.Type, Value: v}, err
		})
}

func p3(t uint16, fn func(*le.Reader) (any, error)) {
	_ = Register(RegistryKey{Type: t, Group: Group2D3D, Value: 1},
		func(r *le.Reader, h *Header) (Element, error) {
			v, err := fn(r)
			return &Body{Type: h.Type, Value: v}, err
		})
}

func ps(t uint16, v uint32, fn func(*le.Reader) (any, error)) {
	_ = Register(RegistryKey{Type: t, Group: GroupSub, Value: v},
		func(r *le.Reader, h *Header) (Element, error) {
			v, err := fn(r)
			return &Body{Type: h.Type, Value: v}, err
		})
}

func pn(t uint16, fn func(*le.Reader) (any, error)) {
	_ = Register(RegistryKey{Type: t, Group: GroupNone, Value: 0},
		func(r *le.Reader, h *Header) (Element, error) {
			v, err := fn(r)
			return &Body{Type: h.Type, Value: v}, err
		})
}

func init() {
	p0(2, func(r *le.Reader) (any, error) { return element.ReadCellHeader2d(r) })
	p0(3, func(r *le.Reader) (any, error) { return element.ReadLine(r) })
	p0(4, func(r *le.Reader) (any, error) { return element.ReadLineString(r) })
	p0(6, func(r *le.Reader) (any, error) { return element.ReadShape(r) })
	p0(7, func(r *le.Reader) (any, error) { return element.ReadTextNode(r) })
	p0(15, func(r *le.Reader) (any, error) { return element.ReadEllipse(r) })
	p0(16, func(r *le.Reader) (any, error) { return element.ReadArc(r) })
	p0(17, func(r *le.Reader) (any, error) { return element.ReadText(r) })
	// type11 Curve & type13 ConicSection share the LineString-family body
	// (ECurve2D/3D + EConic2D/3D all use fields reader1802e4480 =
	// count,flags,count×Point via the member 2D/3D split; D73)
	p0(11, func(r *le.Reader) (any, error) { return element.ReadLineString(r) })
	p3(11, func(r *le.Reader) (any, error) { return element.ReadLineString3d(r) })
	p0(13, func(r *le.Reader) (any, error) { return element.ReadLineString(r) })
	p3(13, func(r *le.Reader) (any, error) { return element.ReadLineString3d(r) })

	p0(22, func(r *le.Reader) (any, error) { return element.ReadPointString2d(r) })
	p3(3, func(r *le.Reader) (any, error) { return element.ReadLine3d(r) })
	p3(4, func(r *le.Reader) (any, error) { return element.ReadLineString3d(r) })
	p3(6, func(r *le.Reader) (any, error) { return element.ReadShape3d(r) })
	p3(22, func(r *le.Reader) (any, error) { return element.ReadPointString3d(r) })
	p3(7, func(r *le.Reader) (any, error) { return element.ReadTextNode3d(r) })
	p3(15, func(r *le.Reader) (any, error) { return element.ReadEllipse3d(r) })
	p3(16, func(r *le.Reader) (any, error) { return element.ReadArc3d(r) })
	p3(17, func(r *le.Reader) (any, error) { return element.ReadText3d(r) })

	pn(18, func(r *le.Reader) (any, error) { return element.ReadSurface(r) })
	pn(19, func(r *le.Reader) (any, error) { return element.ReadSolid(r) })
	pn(23, func(r *le.Reader) (any, error) { return element.ReadCone(r) })

	p0(21, func(r *le.Reader) (any, error) { return element.ReadBSplinePoles2d(r) })
	p3(21, func(r *le.Reader) (any, error) { return element.ReadBSplinePoles3d(r) })
	p0(27, func(r *le.Reader) (any, error) { return element.ReadBSplineCurve(r) })
	p3(27, func(r *le.Reader) (any, error) { return element.ReadBSplineCurve(r) })
	pn(24, func(r *le.Reader) (any, error) { return element.ReadBSplineSurface(r) })
	p3(2, func(r *le.Reader) (any, error) { return element.ReadCellHeader3d(r) })
	pn(25, func(r *le.Reader) (any, error) { return element.ReadBSplineBoundary(r) })
	pn(26, func(r *le.Reader) (any, error) { return element.ReadBSplineArray(r) })
	// Type 95 sits in the GroupSub bucket (dispatch.go groupOf), so a
	// pn() key would never match — register a GroupSub wildcard instead:
	// every subtype's body is the header-defined rest blob (D47).
	_ = RegisterWildcard(95, GroupSub, func(r *le.Reader, h *Header) (Element, error) {
		v, err := element.ReadTableEntry(r)
		return &Body{Type: h.Type, Value: v}, err
	})
	ps(96, 1, func(r *le.Reader) (any, error) { return element.ReadTableLevelHeader(r) })
	ps(96, 6, func(r *le.Reader) (any, error) { return element.ReadTableMLStyleHeader(r) })
	for _, v := range []uint32{2, 3, 5, 10} {
		vv := v
		ps(96, vv, func(r *le.Reader) (any, error) { return element.ReadTableBlob(r) })
	}
	pn(12, func(r *le.Reader) (any, error) { return element.ReadComplexElement(r) })
	pn(14, func(r *le.Reader) (any, error) { return element.ReadComplexElement(r) })
	pn(36, func(r *le.Reader) (any, error) { return element.ReadMultiline(r) })
	_ = RegisterWildcard(33, GroupSub, func(r *le.Reader, h *Header) (Element, error) {
		v, err := element.ReadDimension(r)
		return &Body{Type: h.Type, Value: v}, err
	})
	pn(28, func(r *le.Reader) (any, error) { return element.ReadBSplineArray(r) })
	// type105 Mesh = GroupSub variant family (FaceLoops/TriangleList/…);
	// lossless wildcard: u32 + raw remainder until variants are pinned (D73)
	_ = RegisterWildcard(105, GroupSub, func(r *le.Reader, h *Header) (Element, error) {
		v, err := element.ReadMeshHeader(r)
		return &Body{Type: h.Type, Value: v}, err
	})
	pn(35, func(r *le.Reader) (any, error) { return element.ReadSharedCellInst(r) })
	pn(34, func(r *le.Reader) (any, error) { return element.ReadSharedCellDef(r) })
	pn(103, func(r *le.Reader) (any, error) { return element.ReadMatrixDoubleData(r) })
	// type87 sits in the Group2D3D bucket but has a single impl class —
	// register both ext variants to the same reader (D76)
	p0(87, func(r *le.Reader) (any, error) { return element.ReadRasterHeader(r) })
	p3(87, func(r *le.Reader) (any, error) { return element.ReadRasterHeader(r) })
	pn(90, func(r *le.Reader) (any, error) { return element.ReadRasterReference(r) })
	pn(88, func(r *le.Reader) (any, error) { return element.ReadRasterComponent(r) })
	pn(37, func(r *le.Reader) (any, error) { return element.ReadTagElement(r) })
	// RasterAttachmentComponent variants bound to ERasterRefCompUnknown
	// via RTTI (D80): Binary=1, RGB=3, Mask=11
	for _, v := range []uint32{1, 3, 11} {
		vv := v
		ps(91, vv, func(r *le.Reader) (any, error) { return element.ReadRasterRefUnknown(r) })
	}
	ps(91, 7, func(r *le.Reader) (any, error) { return element.ReadRasterRefGeo(r) })        // Geo (D81)
	ps(91, 8, func(r *le.Reader) (any, error) { return element.ReadRasterRefRender(r) })     // Render (D81)
	ps(91, 9, func(r *le.Reader) (any, error) { return element.ReadRasterRefTransp(r) })     // IndexTransparency (D82)
	ps(91, 10, func(r *le.Reader) (any, error) { return element.ReadRasterRefRGBTransp(r) }) // RGBTransparency (D82)
	// SectionClip(106,1) = OdDgSectionClipImpl consume-rest blob (D80)
	ps(106, 1, func(r *le.Reader) (any, error) { return element.ReadTableBlob(r) })
	// RasterFrame(94) = OdDgRasterFrameImpl fields (D82)
	pn(94, func(r *le.Reader) (any, error) { return element.ReadRasterFrame(r) })
}
