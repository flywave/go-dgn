package dgn

import (
	"testing"

	"github.com/flywave/go-dgn/internal/le"
)

func TestVariantGroups(t *testing.T) {
	cases := []struct {
		typ   uint16
		group VariantGroup
	}{
		{3, Group2D3D}, {87, Group2D3D}, {27, Group2D3D},
		{33, GroupSub}, {95, GroupSub}, {105, GroupSub}, {106, GroupSub},
		{100, GroupNone}, {127, GroupNone},
	}
	for _, c := range cases {
		if got := groupOf(c.typ); got != c.group {
			t.Fatalf("type %d group=%v want %v", c.typ, got, c.group)
		}
	}
}

func TestRecordKeyRules(t *testing.T) {
	h := Header{Type: 3}
	r := NewRecord(h, 1)
	if k := r.Key(); k.Group != Group2D3D || k.Value != 1 {
		t.Fatalf("groupA ext: %+v", k)
	}
	r = NewRecord(Header{Type: 3}, 0)
	if k := r.Key(); k.Value != 0 {
		t.Fatalf("groupA no-ext: %+v", k)
	}
	r = NewRecord(Header{Type: 95, Sub: 0x42}, 0)
	if k := r.Key(); k.Group != GroupSub || k.Value != 0x42 {
		t.Fatalf("groupB: %+v", k)
	}
	r = NewRecord(Header{Type: 39, Sub: 0x1c}, 0)
	if k := r.Key(); k.Value != 0x1c {
		t.Fatalf("type39 keep 0x1c: %+v", k)
	}
	r = NewRecord(Header{Type: 39, Sub: 0x07}, 0)
	if k := r.Key(); k.Value != 0 {
		t.Fatalf("type39 force zero: %+v", k)
	}
	r = NewRecord(Header{Type: 100, Sub: 0x55}, 0)
	if k := r.Key(); k.Group != GroupNone || k.Value != 0 {
		t.Fatalf("default group: %+v", k)
	}
}

func TestRecordFlags(t *testing.T) {
	h := Header{Type: 4, Flag: FlagComplex | FlagDisplayHeader, ID: 42}
	r := NewRecord(h, 0)
	if !r.Complex || !r.Graphics || r.ID != 42 || r.Type != 4 {
		t.Fatalf("r=%+v", r)
	}
}

func TestRegistryAndProxyFallback(t *testing.T) {
	k := RegistryKey{Type: 900, Group: GroupNone}
	called := false
	if err := Register(k, func(r *le.Reader, h *Header) (Element, error) {
		called = true
		return &ProxyElement{H: *h}, nil
	}); err != nil {
		t.Fatal(err)
	}
	if err := Register(k, nil); err == nil {
		t.Fatal("expected duplicate/nil error")
	}
	rec := NewRecord(Header{Type: 900}, 0)
	el, err := Decode(rec, &Header{Type: 900}, le.New(nil))
	if err != nil || !called {
		t.Fatalf("decode: %v %v", err, called)
	}
	if el.ElementType() != 900 {
		t.Fatalf("type=%d", el.ElementType())
	}

	miss := NewRecord(Header{Type: 120}, 0)
	body := []byte{9, 8, 7}
	el2, err := Decode(miss, &Header{Type: 120}, le.New(body))
	if err != nil {
		t.Fatal(err)
	}
	px, ok := el2.(*ProxyElement)
	if !ok {
		t.Fatalf("want proxy, got %T", el2)
	}
	if len(px.Raw) != 3 || px.Raw[0] != 9 {
		t.Fatalf("proxy raw=%v", px.Raw)
	}
}

func TestDimensionWildcard(t *testing.T) {
	rec := NewRecord(Header{Type: 33, Sub: 0x1a}, 0)
	d, ok := Lookup(rec)
	if !ok {
		t.Fatal("wildcard miss")
	}
	el, err := d(le.New(nil), &Header{Type: 33})
	if err == nil {
		t.Fatalf("expected short error, got %+v", el)
	}
}

func TestTableSubtypeRouting(t *testing.T) {
	for _, v := range []uint32{2, 3, 5, 10} {
		rec := NewRecord(Header{Type: 96, Sub: v}, 0)
		if _, ok := Lookup(rec); !ok {
			t.Fatalf("table subtype %d miss", v)
		}
	}
	rec := NewRecord(Header{Type: 96, Sub: 0}, 0)
	if _, ok := Lookup(rec); ok {
		t.Fatal("subtype0 should fall to proxy")
	}
}

// TestRegistryBucketConsistency guards against dead registrations of the
// pn(95) class (D84): every registry/wildcard key's Group must match
// groupOf(Type), otherwise the decoder can never be reached by Lookup.
func TestRegistryBucketConsistency(t *testing.T) {
	check := func(kind string, keys map[RegistryKey]Decoder) {
		for k := range keys {
			if got := groupOf(k.Type); got != k.Group {
				t.Errorf("%s key (type=%d group=%v value=%d): groupOf says %v — unreachable",
					kind, k.Type, k.Group, k.Value, got)
			}
			switch k.Group {
			case Group2D3D:
				if k.Value > 1 {
					t.Errorf("%s key (type=%d): Group2D3D value %d not in {0,1}", kind, k.Type, k.Value)
				}
			case GroupSub:
				if k.Value > 0xff {
					t.Errorf("%s key (type=%d): GroupSub value %d exceeds byte", kind, k.Type, k.Value)
				}
			}
		}
	}
	check("registry", registry)
	check("wildcard", wildcards)

	// Sanity: the bucket sets themselves must stay in sync with the docs.
	for _, typ := range []uint16{5, 33, 39, 42, 91, 95, 96, 105, 106} {
		if groupOf(typ) != GroupSub {
			t.Fatalf("type %d left the GroupSub bucket", typ)
		}
	}
	for _, typ := range []uint16{2, 3, 4, 6, 7, 11, 13, 15, 16, 17, 21, 22, 27, 87} {
		if groupOf(typ) != Group2D3D {
			t.Fatalf("type %d left the Group2D3D bucket", typ)
		}
	}
}

// TestEveryRegistryKeyIsReachable constructs a Record that maps to each
// exact registry key and asserts Lookup finds a decoder. Subtype-only
// types (91/96) are reachable through their registered subtypes even
// though subtype 0 intentionally falls to Proxy (D80 negative tests).
func TestEveryRegistryKeyIsReachable(t *testing.T) {
	for k := range registry {
		rec := Record{Type: k.Type}
		switch k.Group {
		case Group2D3D:
			if k.Value == 1 {
				rec.Ext = 1
			}
		case GroupSub:
			rec.Subtype = k.Value
		}
		if got := rec.Key(); got != k {
			t.Fatalf("cannot construct record for key %+v (got %+v)", k, got)
		}
		if _, ok := Lookup(rec); !ok {
			t.Errorf("registry key %+v is unreachable via Lookup", k)
		}
	}
	for k := range wildcards {
		rec := Record{Type: k.Type}
		switch k.Group {
		case Group2D3D:
			if k.Value == 1 {
				rec.Ext = 1
			}
		case GroupSub:
			// any subtype not shadowed by an exact key hits the wildcard
			rec.Subtype = k.Value
		}
		if _, ok := Lookup(rec); !ok {
			t.Errorf("wildcard key %+v is unreachable via Lookup", k)
		}
	}
}
