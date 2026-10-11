package xattr

import "testing"

func TestName(t *testing.T) {
	if n, ok := Name(0x57050000); !ok || n == "" {
		t.Fatalf("%q %v", n, ok)
	}
	if _, ok := Name(0xdeadbeef); ok {
		t.Fatal("unexpected hit")
	}
}
