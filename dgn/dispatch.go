package dgn

import (
	"fmt"

	"github.com/flywave/go-dgn/internal/le"
)

type VariantGroup uint8

const (
	GroupNone VariantGroup = iota
	Group2D3D
	GroupSub
)

type RegistryKey struct {
	Type  uint16
	Group VariantGroup
	Value uint32
}

func groupOf(t uint16) VariantGroup {
	switch t {
	case 2, 3, 4, 6, 7, 11, 13, 15, 16, 17, 21, 22, 27, 87:
		return Group2D3D
	case 5, 33, 39, 42, 91, 95, 96, 105, 106:
		return GroupSub
	}
	return GroupNone
}

type Record struct {
	Type     uint16
	Subtype  uint32
	ID       uint64
	Complex  bool
	Graphics bool
	Ext      uint32
}

func NewRecord(h Header, ext uint32) Record {
	return Record{
		Type:     h.Type,
		Subtype:  h.Sub,
		ID:       h.ID,
		Complex:  h.Flag&FlagComplex != 0,
		Graphics: h.Flag&FlagDisplayHeader != 0,
		Ext:      ext,
	}
}

func (r Record) Key() RegistryKey {
	g := groupOf(r.Type)
	switch g {
	case Group2D3D:
		v := uint32(0)
		if r.Ext != 0 {
			v = 1
		}
		return RegistryKey{Type: r.Type, Group: g, Value: v}
	case GroupSub:
		v := r.Subtype & 0xff
		if r.Type == 39 && v != 0x1c {
			v = 0
		}
		return RegistryKey{Type: r.Type, Group: g, Value: v}
	}
	return RegistryKey{Type: r.Type, Group: GroupNone}
}

type Element interface {
	ElementType() uint16
}

type Decoder func(r *le.Reader, h *Header) (Element, error)

type ProxyElement struct {
	H   Header
	Raw []byte
}

func (p *ProxyElement) ElementType() uint16 { return p.H.Type }

func DecodeProxy(r *le.Reader, h *Header) (Element, error) {
	return &ProxyElement{H: *h, Raw: r.Rest()}, nil
}

var registry = map[RegistryKey]Decoder{}
var wildcards = map[RegistryKey]Decoder{}

func RegisterWildcard(t uint16, g VariantGroup, d Decoder) error {
	k := RegistryKey{Type: t, Group: g}
	if d == nil {
		return fmt.Errorf("dgn: nil wildcard decoder for %+v", k)
	}
	if _, dup := wildcards[k]; dup {
		return fmt.Errorf("dgn: duplicate wildcard for %+v", k)
	}
	wildcards[k] = d
	return nil
}

func Register(k RegistryKey, d Decoder) error {
	if d == nil {
		return fmt.Errorf("dgn: nil decoder for %+v", k)
	}
	if _, dup := registry[k]; dup {
		return fmt.Errorf("dgn: duplicate decoder for %+v", k)
	}
	registry[k] = d
	return nil
}

func Lookup(rec Record) (Decoder, bool) {
	if d, ok := registry[rec.Key()]; ok {
		return d, true
	}
	if d, ok := wildcards[RegistryKey{Type: rec.Type, Group: groupOf(rec.Type)}]; ok {
		return d, true
	}
	return nil, false
}

func Decode(rec Record, h *Header, r *le.Reader) (Element, error) {
	if d, ok := Lookup(rec); ok {
		return d(r, h)
	}
	return DecodeProxy(r, h)
}
