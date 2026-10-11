package linkage

import "testing"

func TestPrimaryIDs(t *testing.T) {
	cases := map[uint16]string{
		0x56E9: "kInfiniteLine",
		0x4F5A: "kExternalMaterial",
		0x0041: "kFillStyle",
		0x56DA: "kSeedPoints",
	}
	for id, want := range cases {
		got, ok := Name(id)
		if !ok || got != want {
			t.Fatalf("%#x = %q, want %q", id, got, want)
		}
	}
	if len(PrimaryIDs) < 40 {
		t.Fatalf("table too small: %d", len(PrimaryIDs))
	}
}
