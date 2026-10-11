# go-dgn

Go implementation of the MicroStation DGN file format (v7 and v8), built
from reverse-engineering the ODA TG_Db module and cross-validated against
GDAL's dgnlib/dgnv8 reference implementations.

## Layout

- `dgn/` — format readers
  - `dgn/` (root): v7 frame/TCB/element bodies, v8 CFB/chunk/directory,
    36B element headers, 72B display headers, (type,variant) registry with
    Proxy fallback
  - `dgn/element/` — v8 element body decoders
  - `dgn/linkage/` — v8 attribute-linkage TLV iteration + typed payload
    decoders (35 of 39 handler IDs)
  - `dgn/xattr/` — extended attributes
- `internal/le/` — little-endian / DGN word-order primitives
- `internal/cfb/` — read-only CFB (compound file) container for v8
- `cmd/diag`, `cmd/probe` — inspection utilities
- `analysis/` — reverse-engineering notes, findings, and Ghidra evidence
  (not part of the Go module)

## Usage

```go
import "github.com/flywave/go-dgn/dgn"

kind := dgn.Detect(buf) // KindV7 / KindV8 / ...
```

v7: `dgn.ParseV7Document` reads header, TCB, and the element forest.
v8: `dgn.Open` / `dgn.ParseAll` read the CFB container, chunk directory,
and typed element bodies.

## Testing

```sh
go test ./...
```

`sample.dgn` (16MB v7 3D PCB design) is used by golden-sample tests and
must sit next to `go.mod`.

## Status

- v7: source-level parity with GDAL dgnlib; golden-sample validated
- v8: 47 registry keys + wildcards, write/read cross-validated against
  ODA dgnOutFields; real-file golden testing pending a v8 sample
