# go-dgn 结构优化 与 go-topo 桥设计（v1）

> 目标：①评估并优化 go-dgn 当前代码结构；②设计 go-dgn → go-topo 的桥，
> 参照 go-topo 现有 IFC/DXF 解析桥的模式。本文是可直接开工的编码级设计。

## 1. go-dgn 现状盘点

### 1.1 包布局（重构前）

```
go-dgn/                          module github.com/flywave/go-dgn (go 1.24, 零依赖)
├── dgn/                    ~5.4k 行 —— v7 与 v8 混合的根包
│   ├── file.go/streams.go/dir.go/header.go/parse.go/dispatch.go/p0.go   # v8 容器+分发
│   └── v7*.go (10 文件)                                                      # v7 全套（V7 前缀命名）
├── dgn/element/            body.go 1554 行 · 51 个 Read* —— 单体解码文件
├── dgn/linkage/            blob.go(TLV) + payload.go 967 行 · 35 解码器
├── dgn/xattr/              ids.go
└── internal/{le,cfb}       字节序原语 / CFB 容器
```

### 1.2 优点（保持不动的部分）

- **零第三方依赖**：internal/le + internal/cfb 自研，无 mscfb/richardlehane 依赖。
- **注册表 + Proxy 回退**：(type,variant) 注册、分桶一致性护栏
  （`TestRegistryBucketConsistency`）、未注册类型 Proxy 兜底，扩展点清晰。
- **双格式单入口**：`dgn.Detect` 探测 v7/v7CellLib/v8，`Open`/`ParseAll`（v8）、
  `ParseV7Document`（v7）各自成体系。
- **验证充分**：v7 与 GDAL 源码级一致 + 16MB 金样；v8 反编译+写侧双证。

### 1.3 问题（本次优化对象）

| # | 问题 | 影响 |
|---|------|------|
| P1 | `element/body.go` 1554 行单体，51 个读取器 + 54 个结构体挤在一个文件 | 可维护性；每次改动全文重编译 |
| P2 | `linkage/payload.go` 967 行且持续增长（35 解码器） | 同上 |
| P3 | 根包 `dgn` 混居 v7/v8，命名靠 `V7` 前缀区分 | 可接受但需约定；大搬迁收益低（见 §5） |
| P4 | **无面向消费方的几何中间层**：解码器直接返回 50+ 种原始结构体（`Arc3d`、`LineString3d`…），下游必须 type-switch 全集 | 桥接方（go-topo）被绑死在解码器内部结构上 |
| P5 | 全局可变注册表（init 期 `Register`） | 测试隔离弱，但对只读解析库风险低，保留 |

## 2. go-topo 侧参照：IFC/DXF 桥模式

go-topo（`github.com/flywave/go-topo`，cgo + OCCT 拓扑内核）已有两种格式桥：

### 2.1 IFC 桥（ifc.go / ifc_mst.go / ifc_style.go）

```go
convert := topo.NewIfcConverter()          // 包装 C ifc_convert_t
convert.Load("model.ifc")
els := convert.GetElements()               // []*IfcElement
// IfcElement{ Shape *Shape; Id, ParentId int; Name, Guid, Type string;
//              Transform *[16]float64 }
trgs := convert.GetTriangulations()        // 顶点/面/法线/UV/材质（渲染路径）
meshes, _ := topo.IfcToMst("model.ifc")   // → []*mst.Mesh（go-mst 可视化）
```

要点：
- **双出口**：`GetElements` 给拓扑编辑（Shape=Edge/Wire/Face/Solid）；
  `GetTriangulations`/`IfcToMst` 给渲染（go-mst.Mesh）。
- **层级**：`ParentId` 表达装配/空间结构；`Transform` 随元素下发。
- **风格**：`IfcStyle`（漫反射/高光/透明度）+ 按 IFC 类型的默认样式表。

### 2.2 DXF 桥（dxf.go）

`DxfReader` 包装 C `dxf_reader_t`，薄读取 API。证明 go-topo 的模式是：
**格式读取器住在 go-topo，向内产出 Shape/Mesh，对内只依赖一个窄接口**。

### 2.3 对 DGN 桥的推论

- DGN 解析是**纯 Go**（go-dgn），不需要 C 读取器——桥的"读"侧零 cgo。
- 桥必须住在 **go-topo**：只有 go-topo 持有 topo Shape/Wire 的 cgo 构造器
  （`TopoMakeEdgeFromPoints`、`TopoMakeThreePointArc`…）。若反向（go-dgn 依赖
  go-topo）会把 OCCT/cgo 污染进纯 Go 解析库，不可接受。
- go-topo 已有 `replace ../go-mst ../gltf` 的兄弟仓模式，加
  `replace github.com/flywave/go-dgn => ../go-dgn` 顺理成章。

## 3. 总体架构

```
┌──────────────────────────── go-topo ────────────────────────────┐
│  dgn.go          DgnReader.Load → []*DgnElement (Shape/Wire/Edge)│
│  dgn_mst.go      DgnToMst → []*mst.Mesh（弧/椭圆细分）            │
│  dgn_style.go    level/color → 风格                              │
└──────────────▲──────────────────────────────▲───────────────────┘
               │ 依赖窄接口                    │ 依赖窄接口
       ┌───────┴────────┐              ┌───────┴────────┐
       │ dgn/scene      │              │ dgn (TCB/Open) │
       │ 几何中间表示 IR │              │ v7 TCB 换算入口 │
       └───────▲────────┘              └───────▲────────┘
               │ scene.FromV7 / FromV8          │
       ┌───────┴───────────────────────────────┴───────┐
       │ dgn (v7 解码器)          dgn/element (v8 解码器) │
       └───────────────────────────────────────────────┘
```

**核心决策：引入 `dgn/scene` 中间表示（IR）**，把"50+ 原始解码结构体"
收敛为几十个几何原语。桥只依赖 scene + TCB，不依赖解码器内部结构。
这是 P4 的解法，也是整个桥设计的支点。

依赖方向铁律：`go-topo → go-dgn` 单向；go-dgn 永不 import go-topo。

## 4. `dgn/scene`：几何中间表示（go-dgn 侧新增）

```go
// package scene — 纯 Go、零依赖，只表达"文件里有什么"，不做拓扑修复。
package scene

type Kind uint8

const (
	KindInvalid Kind = iota
	KindSegment        // LINE：两点直线
	KindPolyline       // LINE_STRING/SHAPE/CURVE/BSPLINE_POLE：点列
	KindArc            // ARC：start/sweep 角 + 双轴
	KindEllipse        // ELLIPSE：双轴 + 旋转（v8 3D 带 quat）
	KindPointString    // 点串（无连接）
	KindCone           // 圆台：双圆心半径
	KindSolid          // 三角网格体（Mesh TriangleList/Grid）
	KindText           // TEXT/TEXT_NODE（仅包围盒与字符串）
	KindCellDef        // CELL_HEADER：定义（含子实体）
	KindCellRef        // SHARED_CELL_REF：引用（名字）
	KindComplexHeader  // 复杂组头（链/形/面/体）
)

type Point struct{ X, Y, Z float64 }

type Arc struct {
	Center       Point
	PrimaryAxis  float64 // v7/v8 UOR 原始值
	SecondaryAxis float64
	Start, Sweep float64 // 度；Ellipse 恒 0/360
	Quat         [4]float64 // v8 3D 旋转；2D 用 Rotation
	Rotation     float64    // 2D 旋转（度）
}

type Entity struct {
	ID       uint64 // v8 Header.ID；v7 用帧序号
	ParentID uint64 // 复杂组/Cell 子实体 → 头实体；0=顶层
	Kind     Kind
	Dim      uint8  // 2 或 3（文件维度）
	Level    int
	Color    int32  // 原始色号（未查表）
	Name     string // Cell 名 / SharedCell 引用名
	Transform *[16]float64 // Cell 实例变换（列主序4×4）；无则 nil
	Points   []Point       // KindSegment/Polyline/PointString
	Arc      *Arc          // KindArc/KindEllipse
	Text     string        // KindText
	BBox     [2]Point      // 头 bbox（原始 UOR）
}
```

转换入口（go-dgn 根包新增，薄封装）：

```go
// dgn/scene_build.go
func SceneV7(doc V7Document) []scene.Entity   // 遍历 doc.Top 森林，应用 TCB 可选
func SceneV7AtMaster(doc V7Document) []scene.Entity // 应用 TCB.TransformPoint → master 单位
func SceneV8(space []byte, d Dir) ([]scene.Entity, error) // ParseAll + type-switch 收敛
```

规则：
- v7 复杂组（12/14/18/19）→ 子实体 `ParentID` 指向组头帧序号；
  v8 complex flag 同理（`Record.Complex` + 目录连续段）。
- CellHeader 的子实体展开 + `Transform`（2D 4 参数→4×4；3D 9 参数+origin→4×4）。
- 未识别/Proxy 类型 → 不产出 Entity（保持"宁缺勿错"，raw 仍可从原 API 拿）。
- 颜色保持原始色号；v7 色表可经已有 `ReadV7ColorTable` 在桥侧解析。

## 5. go-dgn 结构优化（分三档）

### P0（机械拆分，无 API 变化）——立即做

`dgn/element/body.go` 按领域拆文件（函数与类型**原名原签名**移动）：

```
element/
├── geom.go        Line/LineString/Shape/Ellipse/Arc/Line3d/Ellipse3d/Arc3d/
│                  LineString3d/Shape3d/PointString2d/3d
├── text.go        Text/Text3d/TextNode/TextNode3d
├── solid.go       Cone/Solid/Surface/BSplineCurve/Surface/Array/Poles/Boundary
├── cell.go        CellHeader2d/3d/ComplexElement/SharedCellInst/Def
├── raster.go      Raster 全族（Header/Reference/Component/RefComp*/Frame）
├── table.go       Table*/Dimension*/Multiline/DString/Tag/Mesh/Matrix
└── proxy/registry 保持在 element 包根（接口 + 注册辅助）
```

`dgn/linkage/payload.go` 同法拆：

```
linkage/
├── payload.go         DecodePayload 分发表 + f64d/le32 公共件
├── payload_geom.go    SeedPoints/AssocRegion/InfiniteLine/Thickness/Dependency
├── payload_style.go   FillStyle 族/BitMask/LStyleMod/DimTextStyle/Material
├── payload_str.go     String/ByteArray/DoubleArray/Note/XML/FilterMember
└── payload_db.go      DBLinkage 族 + Sheet*/RefAttachPath/Ole/…
```

验证：拆分前后 `go build && go vet && go test ./...` 全绿即可，导出面零变化。

### P1（新增 dgn/scene + SceneV7/SceneV8）——桥的前置

见 §4。新增约 300 行 + 测试。这是桥的第一里程碑（go-dgn 内完成，可独立验收：
对 sample.dgn 产出 N 个 Entity 的金样直方图测试）。

### P2（暂缓/不做）

- **v7/v8 分包搬迁**：收益低（V7 前缀已消歧、无循环依赖、搬迁会破坏
  所有 import 路径且不增加正确性）。除非 dwg/rvt 二期引入更大的根包压力，否则
  保持现状，以 §1.2 的约定文档化。
- 全局注册表实例化：只读库风险低，暂缓。

## 6. go-topo 侧桥（go-topo/dgn.go + dgn_mst.go）

### 6.1 API（镜像 IfcConverter 形状）

```go
// go-topo/dgn.go — 纯 Go 读取，仅在构造 Shape 时走 cgo
package topo

type DgnElement struct {
	Shape     *Shape        // Wire/Edge；无几何（Text/Proxy）为 nil
	Id        int
	ParentId  int           // 复杂组/Cell 子→头
	Name      string
	Type      string        // "Line"/"Arc"/"CellHeader3d"/…
	Level     int
	Color     int
	Transform *[16]float64  // Cell 实例 4×4，列主序（与 IfcElement 一致）
}

type DgnReader struct {
	path     string
	elements []*DgnElement
	styles   map[int]*DgnStyle
}

func NewDgnReader(path string) *DgnReader
func (r *DgnReader) Load() bool        // v7/v8 自动 Detect
func (r *DgnReader) GetElements() []*DgnElement
func (r *DgnReader) GetStyle(level int) *DgnStyle

// go-topo/dgn_mst.go — 渲染路径，镜像 IfcToMst
func DgnToMst(path string) ([]*mst.Mesh, error)
```

### 6.2 几何映射表

| scene.Kind | 拓扑出口（GetElements） | 网格出口（DgnToMst） |
|---|---|---|
| KindSegment | `TopoMakeEdgeFromTwoPoint` → Wire | 两顶点三角带退化（线段 outline） |
| KindPolyline | 逐段 Edge 链接成 Wire（首尾同点→闭合 Wire） | 折线 outline |
| KindArc | `TopoMakeThreePointArc`（起/中/末三点由 center+r+角算出） | 弧细分（弦高误差 ε，见6.4） |
| KindEllipse | 采样成 N 段三点弧 Edge 链 | 椭圆细分 |
| KindPointString | 仅顶点集（Vertex 数组），无 Edge | 点精灵/跳过 |
| KindCone | 三角化成 MeshNode（上下面+侧面）；Shape 暂为 nil | 同左 |
| KindSolid | 若源含三角网则直接转 MeshNode（顶点/面已在解码器） | 同左 |
| KindText | Shape=nil，仅元数据（Id/Level/Name=文本） | 跳过 |
| KindCellDef | 子实体展开（ParentId 链接），头仅元数据 | 子实体各自转换 |
| KindCellRef | Shape=nil，Name=引用名；DgnToMst 按名解析到 CellDef 实例化（D93） | 实例化 defn 几何（恒等放置，见 §6.5） |
| KindComplexHeader | 子实体 ParentId 链接 | 子实体各自转换 |

### 6.3 坐标管线

- **v7**：`scene.SceneV7AtMaster` 已应用 TCB（UOR×scale−origin），
  桥拿到的就是 master 单位 → 直接构造。
- **v8**：解码器返回 UOR 原值。v8 的 master 单位在表元素里（go-dgn 尚未解析），
  桥提供 `DgnReader.SetUnits(uorPerMaster float64)` 显式注入；
  未设置则原样输出 UOR（文档化，不猜）。
- 2D→3D：Z=0 平面提升；`Dim` 字段随 Entity 下发。

### 6.4 弧细分（DgnToMst）

镜像 go-topo 现有做法，给定弦高误差 ε：

```
n = ceil(sweep / (2*acos(1 - ε/r)))   // r = primary axis
至少3段，至多 256 段（防止小半径爆炸）
```

v8 Arc 的 quat 旋转先作用于 XY 平面基，再细分。

### 6.5 层级与变换

- `ParentId` 语义与 IFC 相同：复杂组头 / CellDef 头为父，几何子为子。
- `Transform` 只挂在 CellDef/CellRef 上；消费方（如 mst 转换）递归下乘。
  桥不预乘（与 IfcElement.Transform 行为一致）；**DgnToMst 已实现下乘**。
- **D93 cell 分组**：v7 type2（legacy cell header）/34（shared defn）按
  **span** 分组（Σ(size/2) = TotLength+19，与 12/14 同公式；GDAL 不分组 cell，
  sample 223/223 + 115/115 全对齐）。type34 内部为**定义空间**（`DefnOnly`），
  只经 CellRef 实例化渲染，不顶层出图；39 个 ref bbox 与其 defn 内部 bbox
  全等 → **样例内全部恒等放置**；ref 体未见 origin/rotation 字段（三个 4.0
  槽语义 [?]），非恒等放置待带样例定案后接入 Entity.Transform。

### 6.6 风格

`DgnStyle{ Color [3]float64; Transparency float64 }`：
- v7：`ReadV7ColorTable` 解析色表 → 色号→RGB；默认灰。
- v8：暂默认白（色表在表元素，二期接入）。
- 与 `IfcStyle` 同构，后续可合型。

## 7. 分期实施

| 期 | 内容 | 验收 |
|---|------|------|
| M1 | go-dgn：P0 拆分 body.go/payload.go | 六包全绿，导出面 diff 为空 |
| M2 | go-dgn：dgn/scene IR + SceneV7/SceneV8 + 金样直方图测试 | sample.dgn 产出 Entity 计数/Kind 直方图金样 |
| M3 | go-topo：go.mod 加依赖 → dgn.go（DgnReader→Wire/Edge，2D 线/弧先行） | 用 sample.dgn 产出 Wire 数金样；`go test` 绿 |
| M4 | go-topo：dgn_mst.go（DgnToMst 弧细分+折线） | sample.dgn → mst.Mesh 顶点/面数金样 |
| M5 | Cell/复杂组层级 + Transform 下发；v8 SetUnits | 层级 ParentId 金样；2D/3D 双样例 |

依赖：M3 需要兄弟仓布局（`../go-dgn`），与 `../go-mst`/`../gltf` 同模式。

## 8. 风险与开放问题

| 风险 | 缓解 |
|------|------|
| v8 master 单位未解析 → 坐标量纲歧义 | 桥侧 SetUnits 显式注入；不做隐式猜测 |
| Cell 引用（SharedCellRef）名字解析需要定义-引用链接 | ✅ D93 已实现（DgnToMst 按名实例化）；非恒等 ref 放置字段 [?] 待样例 |
| v8 色表未解析 | 桥默认白；二期接表元素 |
| Text/Spline 语义 | 一期只出元数据；KindText 预留 |
| scene IR 设计不足导致二次返工 | IR 只含已在解码器验证过的字段（Arc/点列/Cell 变换），不做投机字段 |
| go-topo cgo 环境脆弱（clang 路径等） | 按 go-topo AGENTS.md：`CC=/usr/bin/clang` 前缀 + `go clean -cache` |

## 9. 非目标（明确不做）

- 不在 go-dgn 内做拓扑修复/缝合/布尔——那是 go-topo 的职责。
- 不做 DGN 写入（goal 已明确"只读"）。
- 不做 DWG/RVT 桥（二期/三期另立）。
- 不把 v7/v8 分包搬迁（§5 P2）。
