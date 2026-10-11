# go-dgn 实现规格（spec v1 — 由第 1–5 轮分析收口驱动）

> 本规格是 `../03-dgn/*.md` 全部观察级结论的**编码视图**。每节标注依据文档；
> 未知项（U4/U5/U7b/U8/U9/U10）明确"实现到该层再下钻"，不阻塞骨架。

## 0. 仓库与包布局

```
go-dgn/
├── go.mod                          module github.com/<you>/go-dgn
├── internal/
│   ├── le/                         小端 Reader/Writer（游标 + 越界即停语义）
│   └── cfb/                        OLE/CFB 容器（sector/dir/FAT/miniFAT）
│                                   # 或引入 github.com/richardlehane/mscfb（D2 F1）
├── dgn/
│   ├── file.go                     打开/版本探测（v8 优先 → v7 报 ErrUnsupportedV7）
│   ├── streams.go                  流名常量（D26）
│   ├── chunk.go                    OdDgElementChunk/ZipChunk（D27）
│   ├── dir.go                      u32 偏移目录 + 头解析（D16/C2-C4）
│   ├── header.go                   SElementHeader 36B + DisplayHeader 72B（D7/D8）
│   ├── dispatch.go                 (type,variant)→decoder 注册表（D17/C6/C7）
│   ├── record.go                   dispatch 记录布局（D22）
│   ├── filer.go                    kFileFiler 读取原语（D6 槽位表）
│   ├── element/                    每类型一个文件：body 解码
│   │   ├── element.go              接口 + 基础字段（level/flags/id）
│   │   ├── line.go linestring.go shape.go arc.go ellipse.go text.go textnode.go
│   │   ├── cell.go sharedcell.go pointstring.go cone.go bspline.go …
│   │   └── proxy.go                4 路 Proxy 透传（C7）
│   ├── linkage/
│   │   ├── blob.go                 TLV 迭代（三长度模式）（D25）
│   │   └── types.go                type id → 已知 linkage 解析器（U10 渐进）
│   ├── xattr/                      36 个 readData 对应解析器（渐进）
│   └── table/                      level/font/style/regapp/view/model（CDG* 族，二期）
├── dwg/                            二期（占位）
└── rvt/                            三期（占位，见 ../04-rvt）
```

## 1. 容器层（依据 file-structure.md F1/F6、D26/D27）

```go
// v8 = OLE/CFB；v7 不支持（一期返回 ErrUnsupportedV7，二期走 v7 路线）
func Open(path string) (*File, error)
```
- 流名常量：`StreamDgnULC = "Dgn~ULC"`（主数据，readFile 实际打开者）、
  `Dgn~H, Dgn~Mf, Dgn~Mh, Dgn~Mix, Dgn~S, Oda~SH`（用途待样例确认，先枚举保留）。
- 标准 OLE 元流（SummaryInformation 等）交给容器库。

## 2. Chunk 层（D27、load-pipeline L1-L4）

```go
type Chunk interface {
    Name() string
    Bytes() []byte          // vt+0x68/0x70 语义
}
// 子节点名以 '$' 开头 → ElementChunk（72B 语义）；否则 ZipChunk（解压后取 Bytes）
```
- **ElementChunk 内含 `[]uint32` 偏移目录 + base**；解出方式=U7b（绑定函数未定位）——
  **一期策略**：以"遍历子节点 → 尝试解析头"的兜底路径先跑通，同时按 U7b 线索
  （RTTI TD → vftable → slot 0x88）补全精确解析。

## 3. 目录与元素定位（directory.md C1-C4、D16）

```go
type Dir struct { Base int64; Offsets []uint32 }
func (d Dir) Pos(i int) int64 { return d.Base + int64(d.Offsets[i]) }
// 复杂元素跨度：count 字段位于 elem+0x24；(flags.bit12 && type!=100) 时位于 elem+0x6c
//   next = i + count   →  迭代器跳过子条目
```

## 4. 元素头（element-header.md D7/D8、D22）

```go
type Header struct {                      // 文件 36B，内存对齐 40B
    Field0  uint32 // @0   语义待核(U5)
    Type    uint16 // @4   ← ElementTypes（element-types.md 表）
    Flags   uint16 // @6   bit12=显示头 bit13=复杂 bit14=附加4B
    Field3  uint32 // @8
    SubWord uint32 // @12  ← subtype 来源之一（mem@0x14）
    Field5  uint32 // @16
    ID      uint64 // @24
    Tail    uint64 // @28
}
// DisplayHeader: 72B，读取序列 3×u32+2×u16+3×u32+6×u64（FUN_1808c5150）
//   仅 flags.bit12 且 (type==100||type==35) 等条件触发（D8/C10），字段语义 U5
```

## 5. 分发（directory.md C5-C9、D17/D22）

```go
type Variant struct{ Type uint16; Kind VariantKind }
// Kind: Variant2D3D（组A: type∈{2,3,4,6,7,11,13,15,16,17,21,22,27,87}）
//       VariantSub   （组B: type∈{5,33,39,42,91,95,96,105}，subtype=u8）
//       VariantNone  （其余=0）；type39 且 subtype!=0x1c → 强制 0
var registry = map[Variant]Decoder{ … }   // 注册即 odDgnClassMap 的 Go 版
// 未命中 → ProxyDecoder{complex: flags.bit13, graphics: flags.bit12}（四态）
// 特例直构（D19）：KMLPlacemark / AnnotationCellHeader / AssocRegion / Ole2Frame ×2d3d
```

**元素记录组装（D22，读头后立刻可用）**：
`type=hdr.Type；subtype=hdr.SubWord（type33/91/95/105 特例取别处）；id=hdr.ID；
complex=flags.bit13；graphics=flags.bit12；variant4=显示头 bit11[推断 3D]`。

## 6. 单元素解码管线（load-pipeline L5、linkages.md §1）

```
bytes := chunk.Bytes()[pos:]
r := filer.New(bytes)                 // kFileFiler 语义
hdr := header.Read(r)                 // 36B
if hdr.Flags.bit12 { dispHdr = displayHeader.Read(r) }
body := decoder.DecodeBody(r, hdr)    // 按 registry 分发，读到 bodyWords 消费完
linkOff := 4 + bodyWords*2            // 相对记录起点
linkBlob := bytes[linkOff : totalWords*2]
recs := linkage.Iter(linkBlob)        // D25 三长度模式
```
- filer 原语与 vtable 槽位一一对应（filer-api.md §1）：`RdInt8/16/32/64, RdDouble,
  RdFloat, RdPoint2d/3d, RdUnicodeString, RdAnsiString, RdBytes, RdDbHandle,
  RdAddress, Seek/Tell/Length`。
- **语义要点**：读取过程**越界即停/截断返回**（readData、目录扫描均如此）——Go 侧
  统一返回 `io.ErrUnexpectedEOF`+partial，不 panic。

## 7. Linkage/XAttribute（linkages.md D25/U9/U10）

```go
type Rec struct{ TypeID uint16; Raw []byte }  // Raw 含 4B 头
func Iter(b []byte) []Rec {
    // 模式A len=8；模式B len=count*2+2；模式C len=(2<<nibble)*count
    // count=u8(hdr[0])；nibble=hdr[1]&0xf；TypeID=le16(hdr[2:4])
    // 谓词开关=U9：一期以"计算三候选长度并选 ≤剩余且>0 者"? 不行——必须按谓词：
    //   → 实现 OdDgAttributeLinkageHeader 两个谓词的反编译（U9）作为本包第一个下钻任务
}
// 已知 TypeID → 解析器注册表（渐进）；未识别 → Raw 透传
// XAttribute：id 落在 XAttr 命名空间 → 36 个 readData 的对应实现（渐进）
```

## 8. 元素体实现优先级（第一版范围）

P0：Line(3) LineString(4) Shape(6) Arc(16) Ellipse(15) Text(17) TextNode(7)
    CellHeader(1/2) SharedCellDef/Ref(34/35) PointString(22)
P1：Cone(23) Solid(19)/Surface(18) BSpline(26/27/21/28) Multiline(36) Dimension(33)
P2：Raster(87-94) Mesh(105) Tag(37) DgnStore(38/39) Table(95/96) 其余
- 每个 body 的字段序列获取方法（已验证可行）：工厂 `1809df950` 该类路径 →
  `impl.dgnInFields` 反编译 → 逐原语序列抄成 `r.RdXxx()` 链（样例 `ECell`、
  `OdDgMultilineProfile`、`ESharedCellInst` 见 filer-api §4）。

## 9. 错误与兼容策略

- 未知 type / 未知 linkage id：**不失败**，Proxy/透传 + 记录到 `File.Warnings`。
- 所有长度计算用 `uint32` 溢出检查；所有切片访问先验 `len`。
- v7 文件：`ErrUnsupportedV7`（二期 TG_Dgn7IO 路线，v7-format.md）。
- 样例缺失风险：先以"结构可解析、字段部分未知"交付，金测试清单见下。

## 10. 里程碑与验收

| 里程碑 | 内容 | 验收 |
|---|---|---|
| M1 | cfb + 流枚举 + chunk 名分流 + offset 目录取头 | 对样例列出全部元素 type/id/flags |
| M2 | 36B 头 + dispatch registry + P0 元素体 + proxy | P0 几何与 ODA 导出 JSON 对照 |
| M3 | linkage blob 迭代 + XAttr 透传 + 已知 id 若干 | blob 全量 walk 无越界、id 统计 |
| M4 | 表族（level/font/style）+ 复杂元素子迭代 | 打开真实工程文件不丢表 |
| M5 | v7 支持 + 写回(可选) + U8 校验和 | 待定 |

**测试**：`testdata/` 需补样例（用户决策"先纯静态"→ 样例到位前用
"字节级构造"单测：按 spec 手造 header/blob 做金样例）。

## 11. 分析侧遗留（不阻塞 M1-M3）

U7b(ElementChunk 绑定) / U9(linkage 谓词，**M3 前必须**) / U10(逐 linkage 字段) /
U5(显示头字段) / U8(写校验和) / U4(v7) / U1(流用途) / 惰性 vs 全量预读。
