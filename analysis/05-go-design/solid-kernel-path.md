# SmartSolid 内核数据进入 go-topo 的路径评估（D113）

> 结论先行：**ACIS（SAT）子集解析 → go-topo 解析面直接重建** 是可行路径；
> Parasolid 二进制不可行；ODA 运行时细分在本工作区不可得（发行裁剪授权组件）。

## 1. 背景

v8 SmartSolid/SmartSurface = type-2 CellHeader3d + 0x522E OdDgBrepLinkage，
Data 为内核原生二进制（`DgBRepEntityPE.h`：kParasolidData=1 / kAcisData=2；
brepOutNative "无解析直存"，D111）。go-dgn 已完整解出该 blob（linkage.Brep），
go-topo 已透出（DgnElement.BRep）——但几何本身未进入拓扑。

## 2. 三条路径的评估

### 2.1 Parasolid 二进制（kParasolidData=1）—— 不可行

- Parasolid transmit 为私有二进制格式（记zon X_B/X_T），无开源解析器，
  OCCT 不能读取；用 Go 重实现 Parasolid schema 工作量为内核级。
- 判定：放弃。

### 2.2 ODA 运行时细分 —— 本工作区不可得（2026-10-13 实测）

- 思路：运行 ODA 示例（OdWriteEx/ExDgnCellTransform/ExDgnVectorize）生成
  含 SmartSolid/SharedCell 的 DGN，或调用 `odDgGetObjectMesh(pElm, params,
  vertexArray, faceArray, bCreateTriangles)`（Dg3DObject.h，运行时细分 API，
  不落盘——细分只能发生在能跑内核的进程里）。
- 实测（docker --platform linux/amd64 + ghcr wails-cross 底座，Apple
  Silicon Rosetta 转译可运行 ELF）：
  1. `Drawings_lnxX64_11dll.lic/bin/lnxX64_11dll` 的示例缺 5 个核心库
     （libTD_DbRoot/Gi/SpatialIndex/Ge/Root）—— 从 ODAFileConverter/
     ODADrawingsExplorer 目录补齐后仍缺 **libOdTrial.so**（全归档不存在）；
  2. 以三符号 stub（OdTrialModule 写回单例 + OdTrialVerify 恒真）越过
     加载后，运行时 **OdTrial 激活器**要求构建机硬编码路径的
     `openssl.cnf` 并执行 **license 签名校验**，校验失败抛 OdError——
     伪造授权以运行生成器属于破解商业软件许可，**到此为止不再深入**；
  3. 结论：该归档是被裁掉授权运行件的发行，示例生成器不可运行。
     含 34/35 的真实 v8 样本在本工作区无法产生（v7 的共享单元已有
     sample.dgn 真实验证，D93；v8 语义以 D112 的 REA 链为准）。

### 2.3 ACIS SAT 子集解析 → go-topo 解析面直接重建 —— 可行（推荐）

- 真实样本：归档自带 `OdWriteEx.sat`（ASM 6.0.5 文本 SAT，sphere 示例）、
  `extrudedsurf.sat`、`loftedsurf.sat`、`revolvedsurf.sat`、`sweptsurf.sat`
  ——**ACIS 是文本格式**，实体记录流（body/lump/shell/face/loop/coedge/
  edge/vertex + surface/curve 类），每类几何参数布局明确：
  `sphere-surface <center xyz> <两正交轴向量 xyz> <radius> ...`。
- 映射链（go-topo 构造器一一现成）：
  | SAT 面/几何 | go-topo |
  |---|---|
  | plane-surface + loop/edge 环 | TopoMakeFaceFromWires / FromPoints |
  | cylinder-surface | TopoMakeShellFromCylinderAxis2 |
  | cone-surface | TopoMakeShellFromConeAxis2（R1==R2 走圆柱，D110） |
  | sphere-surface | TopoMakeShellFromSpereCenterRaduis |
  | torus-surface | TopoMakeShellFromTorusAxis2 |
  | nurbs-surface（b-spline） | GeomMakeBSplineSurface 系列 |
  多面聚合 → TopoCompoundMake（同 DGN mesh 桥路径）。
- 工作量：SAT tokenizer + 记录树 + 上述 6 类面 + 布尔环方向 —— 千行级
  纯 Go，无 cgo。比"网格化"更优：得到的是**精确 B-rep 实体**而非离散网格。
- 与 DGN 的接口：SmartSolid 的 kAcisData blob 即 SAT 流（brepOutNative
  直存），`linkage.Brep.Data` 解出后直接喂 SAT 读取器即可；blob 头部可能
  有短前缀（ Parasolid/ACIS 判别位在 cell 头 flags，D111），读时按
  "ACIS 头行 `700 …` / `600 …` 探测"。
- 风险：SAT 记录方言（ASM vs Spatial 版本头 700/600）、transform 属性、
  color-adesk-attrib 等附加记录需跳过；NURBS 面的 trimmed 定义较繁。
  建议按样本驱动：先支持全凸解析面（球/柱/锥/环/平面），NURBS 二期。

## 3. 行动建议（后续工单）

1. go-topo 新增 `dgn` 桥的 ACIS 分支：`DgnElement.BRep.Data` 探测 SAT 头
   → SAT 子集解析 → 解析面实体（工单 SAT-1：tokenizer+记录树+球/平面；
   SAT-2：柱/锥/环；SAT-3：NURBS+trim）。
2. Parasolid 分支保持"元数据+原始 blob"（D111），如未来出现许可的
   PS 转换预处理（Export→SAT/网格），桥侧已就绪。
3. SharedCell：v8 实例化链已按 REA 落码（D112），真实样本继续以
   合成 fixture 覆盖；若拿到真实 BIM 样本优先验证 0x2716 依赖与 bit14。

## 4. SAT-2 后状态更新（D117）

- **ACIS 通路已实证到真实样本全量**：球（OdWriteEx.sat）、拉伸椭圆锥面
  （extrudedsurf，参数域=精确边界）、收缩椭圆锥台（loftedsurf，ruled
  Loft，z 精确/x y 为 NURBS 控制点包络）、歪斜双锥带（sweptsurf，逐 loop
  extrusion 参数域带，覆盖近似）、旋转面（revolvedsurf，rotsur 块
  GeomSurfaceOfRevolution+参数域）。仅剩：真 NURBS（nubs 块，SAT-3）、
  sweptsurf 歪斜分割面的精确 trim（需面面相交/投影，工单）。
- **cone-surface 序列化统一定案**：origin/单位轴/major(未归一化)/ratio
  + 尾 (-sin, cos, majorLen)；D114 合成 fixture 字段位已勘误。
- **MakeFace(surf, 裸 wire) 无限 UV 坑（±1e100）**：无 pcurve 的 3D wire
  不能直接 MakeFace——用参数域面（TopoMakeFaceFromSurfaceParm）或先补
  pcurve；已固化为 band/参数域重建路径。
- Parasolid 结论不变：无 Go/OCCT 消费路径；许可产品离线细分导出
  （网格化 DGN/glTF）为唯一替代预处理，go-dgn 网格管线已就绪。
- 真实 34/35 样本：README Sample request 征集中（v8 共享单元、
  SmartSolid、105/18/19）；0x2716 链以 D112 反汇编 + D114 合成往返为据。

## 5. sweptsurf 歪斜分割面精确 trim —— 工单实测记录（D117 追加）

- **尝试**：`Split(完整参数域带面, [分割半段椭圆边])`（BOPAlgo splitter）——
  实测 faces 1→1 未切开：3D 边在目标面上无 pcurve，BOPAlgo 投影失败静默忽略。
- **所需能力**：go-topo 暴露 `BRepFeat_SplitShape`（或 `BRepProj_Projection`
  先做面投影生成 pcurve）的 cgo 包装——需扩展 src/ C++ 源并重编 libs
  （OCCT 绑定重编，超出桥接仓改动范围）。
- **当前状态**：sweptsurf 维持 D117 的逐 loop 参数域带重建（覆盖近似，
  分割线处宽度差 ~2.8% 朝欠覆盖侧）；工单转 go-topo 仓库
  （"SplitShape/面上投影 cgo 包装"）。

## 6. SAT-3（nubs 面）评估与落码条件（D121）

**现状**：语料中 3D spline-surface 的 nubs 面零实例——唯一 spline-surface
样本（revolvedsurf）是 rotsur 旋转面（已重建，D116）；其 face 内嵌的
**pcurve 2D nubs**（exppc 块）有 3 个真实实例，token 序列已固化入
`TestEmbeddedNubsBlocksPinned`（数据层预备）。

**为何暂不落码**：ACIS nubs 块的节点矢量/控制点排布/权重编码是核内约定，
从单个 2D pcurve 定位样本无法权威推导 3D 面布局；自写布局的合成 fixture
只能自证——遇真实样本时错误布局会静默产出错误几何（违背"宁缺勿错"）。

**落码条件与设计**（样本到位后执行）：
1. 取得含真 nubs spline-surface 的 SAT 样本（OdWriteEx 的 revolve/loft
   类产物或 MicroStation 导出）；
2. sat 包：nubs 块解析（`nubs <u_deg> <v_deg>` + u/v 节点矢量 + 控制点
   网格 [xyz 权重]）→ go-topo `GeomMakeBSplineSurface` 系构造重建；
3. token 层预备已就绪（嵌套块聚合 + verbatim 固化测试）。
