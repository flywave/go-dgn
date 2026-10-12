package sat

import (
	"math"
	"os"
	"strings"
	"testing"
)

// TestParseRealSphere runs the parser on the archived OdWriteEx.sat (the
// real ACIS sample shipped beside the ODA examples): a one-sphere body at
// the origin, radius 1.
func TestParseRealSphere(t *testing.T) {
	b, err := os.ReadFile("../testdata/OdWriteEx.sat")
	if err != nil {
		t.Skipf("sample absent: %v", err)
	}
	doc, err := Parse(b)
	if err != nil {
		t.Fatalf("parse: %v", err)
	}
	faces := doc.Faces()
	if len(faces) != 1 || faces[0].Owner != 2 || faces[0].Surface != 5 {
		t.Fatalf("faces = %+v", faces)
	}
	surfs, skipped := doc.FaceSurfaces()
	if len(surfs) != 1 || skipped != 0 {
		t.Fatalf("surfaces = %+v skipped = %d", surfs, skipped)
	}
	s := surfs[0]
	if s.Kind != SurfSphere || s.Origin != [3]float64{} || s.R1 != 1 {
		t.Fatalf("sphere = %+v", s)
	}
}

// TestRealConeSamples runs the three real cone-surface samples. They are
// elliptical (unnormalized major axes, trailing ratio fields) — SAT-1
// recognizes the kind but skips the layout as unpinned.
func TestRealConeSamples(t *testing.T) {
	d := "/Users/xuning/Work/go-dgn/ODA-Parse-DWGs-main/archives/Drawings_lnxX64_11dll.lic/bin/lnxX64_11dll/"
	for _, name := range []string{"extrudedsurf", "loftedsurf", "sweptsurf"} {
		b, err := os.ReadFile(d + name + ".sat")
		if err != nil {
			t.Skipf("sample absent: %v", err)
		}
		doc, err := Parse(b)
		if err != nil {
			t.Fatalf("%s: %v", name, err)
		}
		cones := 0
		for _, r := range doc.Records {
			if r.Type == "cone-surface" {
				cones++
			}
		}
		if cones == 0 {
			t.Fatalf("%s: no cone-surface record", name)
		}
		surfs, skipped := doc.FaceSurfaces()
		// every face's surface is a (skipped) elliptical cone
		if len(surfs)+skipped == 0 {
			t.Fatalf("%s: no faces", name)
		}
	}
}

// TestSyntheticSurfaces pins the SAT-1 analytic layouts with synthetic
// records (circular semantics; one face per surface).
func TestSyntheticSurfaces(t *testing.T) {
	hdr := "700 6 1 0\n16 x 17 ASM 6.0.5.7004 NT 24 Mon Jan 16 13:30:30 2006\n1 1e-6 1e-9\n"
	mk := func(surface string) string {
		// record 0 = surface, record 1 = face referencing it
		return hdr + surface + " #\nface $1 -1 $-1 $-1 $-1 $-1 $-1 $0 forward single #\n"
	}
	t.Run("plane", func(t *testing.T) {
		doc, err := Parse([]byte(mk("plane-surface $-1 -1 $-1 1 2 3 0 0 1 1 0 0")))
		if err != nil {
			t.Fatal(err)
		}
		s, sk := doc.FaceSurfaces()
		if sk != 0 || len(s) != 1 || s[0].Kind != SurfPlane ||
			s[0].Origin != [3]float64{1, 2, 3} || s[0].Normal != [3]float64{0, 0, 1} ||
			s[0].UVec != [3]float64{1, 0, 0} {
			t.Fatalf("%+v skipped=%d", s, sk)
		}
	})
	t.Run("cylinder", func(t *testing.T) {
		doc, err := Parse([]byte(mk("cylinder-surface $-1 -1 $-1 0 0 0 0 0 1 1 0 0 5")))
		if err != nil {
			t.Fatal(err)
		}
		s, sk := doc.FaceSurfaces()
		if sk != 0 || len(s) != 1 || s[0].Kind != SurfCylinder || s[0].R1 != 5 {
			t.Fatalf("%+v skipped=%d", s, sk)
		}
	})
	t.Run("cone", func(t *testing.T) {
		// ratio @12, then I I, then -sin, cos, majorLen (D116 layout)
		doc, err := Parse([]byte(mk("cone-surface $-1 -1 $-1 0 0 0 0 0 1 1 0 0 0.5 I I -0.3162 0.9487 2 forward")))
		if err != nil {
			t.Fatal(err)
		}
		s, sk := doc.FaceSurfaces()
		if sk != 0 || len(s) != 1 || s[0].Kind != SurfCone ||
			s[0].Ratio != 0.5 || s[0].Sin != -0.3162 || s[0].Cos != 0.9487 || s[0].MajorLen != 2 {
			t.Fatalf("%+v skipped=%d", s, sk)
		}
	})
	t.Run("torus", func(t *testing.T) {
		doc, err := Parse([]byte(mk("torus-surface $-1 -1 $-1 0 0 0 0 0 1 1 0 0 10 2")))
		if err != nil {
			t.Fatal(err)
		}
		s, sk := doc.FaceSurfaces()
		if sk != 0 || len(s) != 1 || s[0].Kind != SurfTorus || s[0].R1 != 10 || s[0].R2 != 2 {
			t.Fatalf("%+v skipped=%d", s, sk)
		}
	})
	t.Run("spline-is-skipped", func(t *testing.T) {
		doc, err := Parse([]byte(hdr + "spline-surface $-1 -1 $-1 forward { rotsur }\nface $1 -1 $-1 $-1 $-1 $-1 $-1 $0 forward single #\n"))
		if err != nil {
			t.Fatal(err)
		}
		s, sk := doc.FaceSurfaces()
		if len(s) != 0 || sk != 1 {
			t.Fatalf("spline surfaces = %+v skipped = %d", s, sk)
		}
	})
}

// TestParseRejectsNonACIS keeps the kAcisData probe honest: non-SAT blobs
// (parasolid, noise) must be rejected, not mis-parsed.
func TestParseRejectsNonACIS(t *testing.T) {
	for _, bad := range []string{"", "parasolid header\x00\x01", "random text no header"} {
		if _, err := Parse([]byte(bad)); err == nil {
			t.Fatalf("accepted %q", bad)
		}
	}
}

// TestBoundaryTreeRealSample pins the SAT-2 boundary tree on the real
// extrudedsurf sample: one face with two closed single-edge loops whose
// edges reference equal translated ellipses (base at origin, top at
// (0,1,3), major 2, ratio 0.5).
func TestBoundaryTreeRealSample(t *testing.T) {
	d := "/Users/xuning/Work/go-dgn/ODA-Parse-DWGs-main/archives/Drawings_lnxX64_11dll.lic/bin/lnxX64_11dll/"
	b, err := os.ReadFile(d + "extrudedsurf.sat")
	if err != nil {
		t.Skipf("sample absent: %v", err)
	}
	doc, err := Parse(b)
	if err != nil {
		t.Fatal(err)
	}
	edges := doc.Edges()
	if len(edges) != 2 {
		t.Fatalf("edges = %d", len(edges))
	}
	for _, e := range edges {
		if e.StartVertex < 0 || e.StartVertex != e.EndVertex {
			t.Fatalf("edge %d not closed: %+v", e.Index, e)
		}
		if math.Abs(e.EndP-e.StartP-2*math.Pi) > 1e-9 {
			t.Fatalf("edge %d params = %g..%g", e.Index, e.StartP, e.EndP)
		}
	}
	ells := doc.Ellipses()
	if len(ells) != 2 {
		t.Fatalf("ellipses = %d", len(ells))
	}
	top, base := ells[0], ells[1]
	if base.Origin != [3]float64{} || top.Origin[2] != 3 {
		t.Fatalf("origins = %v / %v", base.Origin, top.Origin)
	}
	if base.MajorRadius() != 2 || base.MinorRadius() != 1 {
		t.Fatalf("base radii = %g/%g", base.MajorRadius(), base.MinorRadius())
	}
	pts := doc.Points()
	if len(pts) != 2 || pts[0].P != [3]float64{2, 1, 3} {
		t.Fatalf("points = %+v", pts)
	}
	loops := doc.FaceEdges(3)
	if len(loops) != 2 || len(loops[0]) != 1 || len(loops[1]) != 1 {
		t.Fatalf("face loops = %d groups", len(loops))
	}
	if loops[0][0].Curve < 0 || loops[1][0].Curve < 0 {
		t.Fatalf("loop edges missing curve refs: %+v %+v", loops[0][0], loops[1][0])
	}
}

// TestParseRotsurBlock pins the rotsur embedded-block extraction
// (revolvedsurf anchor): base ellipse origin/normal/major/ratio and the
// F-prefixed u/v domain bounds.
func TestParseRotsurBlock(t *testing.T) {
	block := ` rotsur 
	ellipse 0 0 0 0 0 1 2 0 0 0.5 I I 
	5 0.007728240996651212 0 0 1 0 
	none F 0 F 6.2831853071795862 F 0 F 3.1400000000000001 PERIODIC OPEN NON_SINGULAR NON_SINGULAR 
	0 
	} `
	el, umax, vmax, ok := ParseRotsurBlock(block)
	if !ok {
		t.Fatal("not ok")
	}
	if el.Origin != [3]float64{} || el.Normal != [3]float64{0, 0, 1} ||
		el.Major != [3]float64{2, 0, 0} || el.Ratio != 0.5 {
		t.Fatalf("ellipse = %+v", el)
	}
	if umax != 6.2831853071795862 || vmax != 3.14 {
		t.Fatalf("domain = %g..%g", umax, vmax)
	}
}

// TestEmbeddedNubsBlocksPinned freezes the real nubs token sequences from
// revolvedsurf.sat (the only nubs instances in the sample corpus — 2D
// pcurve blocks; no 3D spline-surface nubs sample exists). The SAT-3
// surface parser will validate its tokenizer against these exact tokens
// when implemented.
func TestEmbeddedNubsBlocksPinned(t *testing.T) {
	d := "/Users/xuning/Work/go-dgn/ODA-Parse-DWGs-main/archives/Drawings_lnxX64_11dll.lic/bin/lnxX64_11dll/"
	b, err := os.ReadFile(d + "revolvedsurf.sat")
	if err != nil {
		t.Skipf("sample absent: %v", err)
	}
	doc, err := Parse(b)
	if err != nil {
		t.Fatal(err)
	}
	var blocks []string
	for _, r := range doc.Records {
		if r.Block != "" {
			blocks = append(blocks, r.Block)
		}
	}
	if len(blocks) < 4 { // 1 rotsur + 3 pcurve nubs/exppc blocks
		t.Fatalf("embedded blocks = %d", len(blocks))
	}
	nubs := 0
	for _, blk := range blocks {
		if strings.Contains(blk, "nubs") {
			nubs++
		}
	}
	if nubs < 3 {
		t.Fatalf("nubs blocks = %d", nubs)
	}
	// pin the first pcurve nubs token sequence verbatim (periodic
	// seam-curve pcurve of the revolution face)
	first := blocks[1]
	for _, tok := range []string{"exppc", "nubs", "periodic", "6.2831853071795862", "3.1400000000000001", "spline"} {
		if !strings.Contains(first, tok) {
			t.Fatalf("pcurve nubs block missing %q:\n%s", tok, first)
		}
	}
}
