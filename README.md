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

## Sample request（真实样本征集）

为验证并加固以下 DGN 能力，欢迎业务侧（bim4d / minebim / digital-twins /
tunneling 等）提供真实 DGN 样本（放入 `dgn/testdata/` 并注明来源脱敏级别）：

1. **v8 共享单元**：含 SharedCellDefinition(34) / SharedCellReference(35)
   的 v8 文件——用于实证 0x2716 依赖链（定义句柄）、StringLinkage(id=1)
   定义名、flag bit14 子归属（D112 反汇编链的样例验证）。
2. **SmartSolid 实体**：含 MicroStation SmartSolid/Surface（type-2 cell
   header + 0x522E BrepLinkage）的文件——ACIS(2) 载荷可直接经 `dgn/sat`
   重建为精确 B-rep（D114–D116，归档 5 个 SAT 样本已全闭环）；Parasolid(1)
   载荷用于确认判别位。
3. **带网格(105)与 Solid(18/19) 的 BIM 文件**：扩充 D111 的真实样本矩阵。

完整需求清单/验证点/Parasolid 离线细分替代路径见
`analysis/05-go-design/sample-request.md`（D119 工单）。样本只读解析，
不外发。联系 go-dgn 维护者即可。
