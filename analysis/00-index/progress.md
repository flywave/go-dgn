# 进度看板

更新时间：2026-10-11（第 1–62 轮；最新=第62轮 U10b 第三批收口 · D90）

## 阶段状态

| 阶段        | 状态               | 产出                                                                |
| --------- | ---------------- | ----------------------------------------------------------------- |
| 0. 侦察与决策  | ✅                | 决策记录（README）、模块定位                                                 |
| 1. ODA 盘点 | ✅                | `01-oda-inventory/modules.md`、`evidence/exports/*`（11 模块导出表+RTTI） |
| 2. DGN 深挖 | ✅ 2D+3D 判定/4类3D体 | `03-dgn/` 9 篇（新增 `element-bodies.md`）；反编译 20+ 关键函数                |
| 3. DWG 深挖 | ⬜ 未开始            | 目标 `TD_DbIO.tx`(1.4MB)；`02-dwg/` 占位                               |
| 4. RVT 路线 | ✅ 路线图            | `04-rvt/README.md`（本包无能力，独立取证）                                    |
| 5. Go 设计  | ✅ spec v1        | `05-go-design/{README,spec}.md`（可开工）                              |

## 第 1 轮关键突破

1. DGN v8 = OLE/CFB 容器（openStructuredStorageEx + oless.dll 实证）
2. v7/v8 自动探测分支（readFile 反编译）
3. 元素头 36B 字段序列 + type=u16@4（FUN_1808c5240）
4. OdDgFileFiler vtable 槽位→原语完整映射
5. 192 组公开类↔文件层实现类映射
6. Ghidra 无头分析管线打通（TG_Db 39674 函数、可按地址/名字定向反编译）

## 第 2 轮关键突破（见 `03-dgn/load-pipeline.md`）

1. CFB 子节点→`OdDgChunk` 枚举（名称数字后缀 + `$` 前缀分流，1809e4d70/1809eab70）
2. **单元素解码路径**：MemoryStream→OdDgFileFiler→`element->dgnIn(filer)`（1809e18e0）
3. 回写/递归保存路径 + EDimension 校验和分支（1809e2b40/1809e3730）→ 字段顺序互证材料
4. 载入后按类型分拣入表（18058c130）；OdDgElement 虚表 49/50/51/52 = dgnIn/Out/InFields/OutFields
5. 新工具：`DumpXrefs.java`（交叉引用）、`FindCallsWithOffset.java`（全程序虚表槽位调用扫描）

## 第 3 轮关键突破（见 `03-dgn/directory.md`）

1. **元素目录 = u32 偏移数组 + 基址**（container 字段[7]；pos = vt+200() + offset_i）
2. **类型→类表驱动分发**：`odDgnClassMap() (type,variant)→desc`，三组 variant 规则，  
   失败→4 路 Proxy 回退（complex×graphics）→ Go `registry.go` 直接可照抄
3. 头 flags 位语义落地：bit12=72B 显示头、bit13=复杂（跨度字段 +0x24/+0x6c）、bit14=+4B
4. 工厂 FUN_1809df950（36B 头→显示头→8 类特例直构→分发）+ 目录级过滤规则（type 5/9/66/95/96/97/107）
5. 源码路径线索 `Dgn\source\DgDefsInternal.h`（遗留 Dgn 树，仅文件名）

## 第 4 轮关键突破（U7c 关闭）

1. **dispatch 入参记录布局完整钉死**（`1809df950` L146-180）：  
   type/subtype/id/complex(bit13)/graphics(bit12)/db/output-class —— 见 `directory.md` §4
2. 目录扫描输出：Db+0x1490 / Db+0x1498 两个 id 集合（`FUN_1805cfb90/1805d0330` 薄包装）
3. createFromStream 调用方定位：`FUN_1809d8c50`（纯包装）+ summary-information 读取路径

## 第 5 轮（收口）关键突破

1. **Linkage 区定位公式** + **blob TLV 三长度模式**（readData @1808b4040）→ `linkages.md`
2. **CFB 流名 7 个字面量**（Dgn~~ULC 主流 + Dgn~~H/Mf/Mh/Mix/S、Oda~SH）
3. **Chunk 双实现**：OdDgElementChunk(`$`, 72B, [7]=offset数组) / OdDgZipChunk(56B)
4. 收口判定：**文件级四主链（容器/目录分发/元素头/元素体+linkage）全部有观察级证据**，  
   可进入设计编码；残余 U7b/U9/U10 为"实现到对应层再下钻"型未知

## 第 6 轮（M2/M3 提取 + 编码）

1. **U9 解**：linkage 头位域（bit12/bit14/count/nibble/typeID）→ `03-dgn/linkages.md` §2
2. **P0 元素体提取法打通**：pseudoConstructor→EXXX::vftable→slot36=dgnInFields→7 类序列  
   → `03-dgn/element-bodies.md`（LineString reader 留 U11）
3. 新工具：`ShowVtableAt` / `FindVtablesByRtti` / DumpVtables namespace 化（getName(true)）
4. **godgn 编码**：`dgn/linkage` blob 迭代器（A/B/C 三模式+截断语义）落地，测试全绿

## 第 7 轮（U11 关闭 + P0 编码）

1. **U11 解**：LineString/Shape 委托链 asm 实证 → member 读取器 `1802e60c0`  
   （count/flags2/count>10000 钳制/2d-3d 双分支 Point2d 读取）
2. 新工具 `ShowAsm.java`；`dgn/element` P0 体解码器编码 + 字节级测试

## 第 8 轮（纵向贯通）

1. **解析管线闭环**：`dgn.ParseAll(space, Dir)` = 目录头解析 → 显示头消费(ext=bit11) →  
   注册表分发(6 类 P0) → 16bit 对齐 → linkage 迭代；合成端到端测试 3 例全绿
2. `dgn/p0.go` 注册表接线（type 3/4/6/7/15/16 @ Group2D3D/0）；`Body` 包装类型
3. 断点：真实文件仅缺 **U7b**（ElementChunk 偏移表读取）即可跑通全链

## 第 9 轮（U7b 关闭 — 分析侧主要未知清零）

1. **U7b 解（D31/D32）**：索引非文件表而是 **chunk头 count + B字段步进推导**  
   （`off[i+1]=off[i]+u32@(pos+8)*2+4`）；调用链 vtable slot17→`1809e3c80`→`1809dbf20`→`1809dc670`
2. **godgn**：`dgn.BuildChunkIndex` + `TestChunkIndexToParseAll`（chunk→索引→ParseAll→P0 体，  
   纵向全链测试绿）——**端到端能力闭环**，仅差真实 .dgn 样例联调

## 第 10 轮（3D 判定 + 首批 3D 体）

1. **3D 位 CONFIRMED（D33）**：显示头 u16@8 bit11；implicit 规则 type35&\&size>259；  
   parse.go 补 implicit 分支 + record ext 路由
2. **4 类 3D 解码器落 Go（D34）**：Line3d/TextNode3d/Ellipse3d/Arc3d（Quaternion+Point3d），  
   registry 注册 Value1；`TestParseLine3dViaDisplayFlag` 端到端 3D 路由绿
3. 剩余 3D 缺口：U12（LineString3d/Shape3d/PointString 点格式）、U11b（Text 字符串）、  
   P1 3D 专有类型（Cone/Solid/Surface/BSpline/Mesh）

## 第 11 轮（U12 关闭 — 线条族+点族 2D/3D 完整）

1. **U12 解（D36）**：2D/3D 分流=member 虚表 slot8（`1802e60c0`16B / `1802e63a0`24B）；  
   slot14 分 LineString/Shape 族；PointString2d=点列+2x2矩阵、PointString3d=点列+四元数
2. godgn 新增 5 解码器（LineString3d/Shape3d/PointString2d/3d + 注册）+ 端到端 3D 测试 ——  
   **type 3/4/6/7/15/16/22 的 2D+3D 全部落地**

## 工具链（可复用）

- Ghidra 12.1.4 headless：`analysis/evidence/ghidra/scripts/`：  
  `ExportFunctions / DecompileMatches(支持正则命中名字或地址) / DumpVtables / DumpXrefs / FindCallsWithOffset`  
  用法：`analyzeHeadless <project> goDgn -process TG_Db_25.4_lic16.tx -noanalysis -scriptPath scripts -postScript …`  
  （首分析已持久化于 `ghidra/project/`，后续调用秒级）
- 关键扫描产物：`out/TG_Db.functions.tsv`（39674 函数）、`out/calls-0x188.txt`（虚表槽调用点）、  
  `out/TG_Db.vtables.txt`（FileFiler/Filer/Element/CDGElmHeader/CDGElementGeneral 虚表）
- 导出表/RTTI 提取：见第 1 轮会话脚本（产物 `evidence/exports/`）
- REA MCP：TG_Dgn7IO 会话曾返回 `ev_bbef6520…`、`ev_e467580e…`；  
  ⚠️ `evidence/rea-session-1.json` 导出为 0 records（Ghidra 大目标超时/取消导致会话证据被丢弃）。  
  **改以本目录文档 + `evidence/exports/*` + `evidence/ghidra/out/*` 作为主证据载体**，  
  下轮对小目标重新走 REA 并导出带 ev_ ID 的 bundle。  
  （另：MCP 参数中 boolean/array/object 目前会被序列化为 string，`record_unknown` 本轮不可用，  
  残留未知改由 `03-dgn/findings.md` U1–U8 跟踪）

## 第 12 轮（U11b 关闭 — P0 全集完成）

- **U11b 解（D37）**：Text 字符串 = L(u16)→rdBytes；N(u16)→2D 的 N×3 属性表
  （越界丢弃+seek尾）、**3D 无此表**；尾部 16bit 对齐 + 10/11 转换钩子
- `ReadText`/`ReadText3d` 落码 + 3 测试 → **type 3/4/6/7/15/16/17/22 × 2D/3D = 16 格全绿**
- 后续：P1 实体族（Cone/Solid/Surface/BSpline/Mesh，type 18-28/105）+ 样例联调

## 第 13 轮（P1 实体族首批）

- 解码器提取法首次应用于 **GroupNone 类型**（18/19/23）：`pn()` 注册路径
- Surface/Solid=12B 复杂头（几何在子元素，衔接 C4 跨度）；Cone=104B（Quat+双端点双半径）
- 新增 `ReadSurface/ReadSolid/ReadCone` + 测试 → 台账 D38
- 下一批 P1：BSpline 族(21,24-28)、Dimension(33)、Multiline(36)、Mesh(105)、Cell(1/2)、
  ComplexString/Shape(12/14)、Table(95/96)

## 第 14 轮（P1 第二批 — BSpline 族）

- 7 个解码器定位（含 Curve/Surface 共用/复用点列）→ `ReadBSplinePoles2d/3d`（复用）、
  `ReadBSplineArray`（剩余全读）、`ReadBSplineCurve`、`ReadBSplineSurface` + 3 测试
- 关键语义：Knots/Weights 吃掉剩余（linkage 区=空，ODA 同行为）；Curve/Surface=复杂元素
- 台账 D39；剩余 P1：Dimension(33)、Multiline(36)、Mesh(105)、Cell(1/2)、
  ComplexString/Shape(12/14)、BSplineBoundary(25)、Table(95/96)

## 第 15 轮（P1 第三批 — Cell 单元头）

- **ASM 点数定案法**（伪码丢读的对策，入标准流程）：Cell3D=148B、Cell2D=84B
- `ReadCellHeader3d/2d` + 2 测试；type2 注册 Group2D3D 双值
- 台账 D40；剩余 P1：Dimension(33)、Multiline(36)、Mesh(105)、ComplexString/Shape(12/14)、
  Table(95/96)、Boundary(25)、LibraryCell(1)

## 第 16 轮（P1 第四批 — ComplexString/Shape）

- 共用解码器=u32×1；`restoreIdListForUndo` 实证 kFileFiler 空操作（undo-only 读 child ids）
- vtable[202] 槽位链定位法奏效；台账 D41
- 剩余 P1：Dimension(33)、Multiline(36)、Mesh(105)、Table(95/96)、Boundary(25)、LibraryCell(1)

## 第 17 轮（P1 第五批 — Dimension/Multiline 定位）

- **Dimension 族经济性发现**：23 个 EDim* 类共享 slot36=`180257e60`（一处提取=全族）
  —— 但解码器 997 行（循环+6 子读取器+undo 分支），骨架已录，**全文提取=专属子轮**
- Multiline 解码器 `1801707e0`（401 行顶点循环）同样排队
- 两者暂走 Proxy（保真不误读）；台账 D42；Go 侧记下 wildcard 注册需求（GroupSub→单解码器）

## 第 18 轮（Dimension 结构化子轮 · 上）

- **前缀 188B 序列定案**（行116-181 无分支顺序读）+ 文本项 **seek 随机访问模型** +
  串读取=rdAnsi/rdUnicode 原语（dimstr.c）
- 控制流：182-329 零读取内存后处理；333-654 项循环（base+u16 跳转）；undo 分支分离
- 台账 D43；**U13 剩余**：项数组数据源、串模式判定、后段460-997 —— 未闭合前不注册（Proxy）
- 下轮：读 243-329（项构造）+ 460-700（尾段）闭合 U13 → 注册 Dimension 全族

## 第 19 轮（U13 闭合 — Dimension 落码）

- 逐点读取器 37 行定案：**DimensionPoint=48B**（Pt3d+f64×2+u16×2+u32）；N=第4个u8（勘误）
- 顺序模型定稿 + 串 BOM(FF,FE)→rdUnicode 回绕模式（dimstr.c）
- **dispatch 新增 wildcard 注册**：`(33,GroupSub)` 单解码器覆盖 23 工具子类 → `ReadDimension`
- 测试：前缀+双点+Rest 排空 + wildcard 路由；台账 D44；残留 U13b（串前缀格式/linkage 位置）
- 下轮：Multiline(401L) 或 Table(95/96) 小件

## 第 20 轮（Multiline 落码 — P1 大件全部闭合）

- `ReadMultiline`（152B 前缀 + 段/顶点/断点三段）+ `pn(36)` 注册 + 字节级往返测试
- 勘误：行60-65 = 定长3次 i8 读取；尾钩按 K 无条件循环（u32×2+f64×3）；台账 D45
- **规划内元素体状态：P0 全集(2D/3D) ✅ + 实体族 ✅ + BSpline ✅ + Cell ✅ + Complex ✅
  + Dimension ✅(wildcard) + Multiline ✅**
- 剩余：Table(95/96)、Boundary(25)、LibraryCell(1)、U13b 串格式、样例联调

## 第 21 轮（U13b 串格式 + 收尾）

- **D46**：DGN 字符串 = NUL 终止（-1 模式）+ FF,FE BOM → UTF-16；`element.ReadDString` 落码+2测试
- 余量诚实清单：Boundary(25) 尾循环未核、Table(95/96) slot36 未取、LibraryCell(1) 疑复用/弃用
  —— 均有定位、Proxy 兜底，非阻塞

## ✅ 阶段总结（第1–21轮）

- **分析**：台账 D1–D46；未知仅剩样例核对型（U1/U2/U5/U8/U10/U13 接线）+ 3 个小件
- **编码**：`godgn` 五包全绿；**27 类型码 + wildcard(23 subtype)** 注册；
  2D/3D 元素体、容器、目录、头、linkage、字符串全链合成测试
- **下一步**：①样例联调（40+ 推断固化）②小件3项 ③表族/写回/v7 规划
## 第 22 轮（最后三步推进）

**① 样例联调（部分完成）**
- 发现真实样例：GDAL `seed_2d/3d.dgn` → **验明为 DGN v7**
- ✅ **首个真实文件级测试通过**：v7 拒绝路径（`TestRealV7SeedsRejected`，缺文件自动 skip）
- ⏳ v8 真实样例仍缺 → v8 字节级金样例待补（阻塞 40+ 推断的最终固化）

**② 小件清尾**
- ✅ Boundary(25)：u32×2 + count×Point2d（slot0x100 尾读定位）
- ✅ TableEntry(95)：按 B 字段剩余 blob（need=B*2+4-off，同 C4 偏移规则）
- ⏳ TableHeader(96)：impl 类未现身（pseudoCtor ICF 合并@0x180003500；OwI 对缺失）——线索入档
- ⏳ LibraryCell(1)：零命中（疑复用/弃用）——入档

**③ 二期规划**（见 `05-go-design/spec.md` 遗留 + 本看板）
- 表族（TableHeader、CDG* 表记录 level/font/style）、写回(U8 校验和)、v7 支持(U4，
  真实 seed 已就位)、Dimension 串按 Off 接线、dgnInLinkages 字段级(U10)

**注册终态**：29 类型码 + wildcard(23 subtype)；台账 D1–D48；五包全绿
## 二期 · 第 23 轮（表族 type96）

- **注册映射全解（D49）**：rxInit 立即数提取 `(96,1)=Level / (96,6)=MLStyle /
  (96,{2,3,5,10})=Font/Text/Dim/RegApp`；三解码器（28B/4B/剩余blob）落码
- `ps(type,variant)` 精确键注册 + Sub=0→Proxy 负向测试；新工具 DumpDgnClassMap（静态区为零→rxInit 路线）
- 注册终态：**33 精确/通配键**（29 类型 + wildcard33 + 表族6键）；台账 D1–D49
- 二期剩余：U10(dgnInLinkages 字段级) / Dimension 串接线 / v7(U4, seed 就位) / 写回(U8) /
  TableHeader 兜底考证 / 样例(v8 待补)

## 二期 · 第 24 轮（U10 主体 — ID 表与架构定性）

- **架构定性（D50）**：linkage = raw 持有 + 位运算访问器；大级联 = 7 特判 ID 属性应用层
- **双 ID 命名空间落码**：`linkage.PrimaryIDs`(42, E1全表) + `xattr.TypeIDs`(53, 逐类 kType 自动提取)
- 7 特判 ID 与 E1 枚举交叉吻合（4f5a=kExternalMaterial 纠正 proximity 误判 → **以 E1 为准**）
- 新包 `dgn/xattr`（6 包全绿）；台账 D1–D50
- 二期剩余：U10b(payload 逐ID) / Dimension 串接线 / v7(U4, seed就位) / 写回(U8) / v8样例

## 二期 · 第 25 轮（v7 移植 · 帧层）★最新

- **新样例接入**：`godgn/sample.dgn`（16MB 3D PCB，= PCB(1).dgn 同哈希）、HOUSING.DGN —— 全部验明 **v7**
- **E3 主规格**：本地 GDAL dgnlib（dgnopen/dgnread.cpp）→ v7 识别 + 元素帧（D51/D52）
- **Go 落地**：`dgn.Detect/ParseV7Header/ReadV7Elements` + `cmd/probe` v7 直方图模式
- **真实文件实测**：sample=22803 元素/18 类型（首 type9 ✓）、HOUSING=40、seed_2d ✓ 全绿
- 台账 D1–D52；v7 剩余：体格式（dgnread 各 DGNT 分支）、TCB/type9 头、复杂组、E2 抽查

## 二期 · 第 26 轮（v7 移植 · core+体层）★最新

- **D53 core**：complex/deleted 位、6×i32 包围盒、显示头字段+豁免集、属性位0x0800
- **D54 体**：LINE=2×Point@body32；multipoint=count u16@32+点@34+短钳制；坐标=RAW i32(UOR)
- 帧层补 Complex/Deleted 字段；Is3D 修正=bit6（magic 0xC8 vs 0x08，全部样例吻合）
- **真实样例验证**：5814 LINE + 36 LineString 全解 ✓（`TestSampleV7Geometry`）
- v7 剩余：ARC/TEXT/CONE 逐字段核、属性区(A951)、TCB 换算、复杂组、E2 抽查

## 二期 · 第 27 轮（GDAL v8 交叉验证）★最新

- 定位 GDAL v8 驱动 = `ogrsf_frmts/dwg/ogrdgnv8layer.cpp`（**ODA API 消费方**，非独立字节解析）
- **7 项语义确认 / 0 冲突 / 1 待决**（`03-dgn/xvalidate-gdal.md`，D55）：
  Line 起终点、**Arc2d 5双字段悬案关闭（轴×2+旋转+起/扫角）**、Ellipse、点列、
  linkage typeID=getPrimaryId、Text、hole 标志
- 新增 **U14**：Arc3d start/sweep 存储位置（GDAL 端点制暗示）

## 二期 · 第 28 轮（V8 格式描述文件）★最新

- **产出 `analysis/DGN-V8-FORMAT.md`**：整合第1–27轮全部反编译结果的
  单文件 V8 规范（容器/Chunk/元素记录/分发/类型码/filer原语/体序列全表/Linkage/
  Go映射/未知护栏，含证据地址）——后续所有实现与验收的**权威依据**
- 队列不变：U14(3D弧) → v7 体余项+TCB → U10b 按需 → v8 样例固化

## 二期 · 第 29 轮（U14 关闭）★最新

- **Arc 字段序定案（D56）**：`start,sweep,primary,secondary[,rotation],origin`
  —— ASM 槽位计数(4×200+128+110+650) + EArc3D getter 四连证(0x220/228/230/238)
- 勘误闭环：bodies3d awk 漏十进制槽位；GDAL 交叉表"悬案"改判=角度在最前两位（非端点制）
- Go `Arc/Arc3d` 字段序修正 + 测试重写全绿；hook 仅置标志（角度=文件直读）
- 遗留 [?]：Ellipse 字段文件序（getter 链需再一跳，样例时核）
- **队列余项**：v7 体余项(ARC/TEXT/CONE)+TCB → U10b 按需 → v8 样例固化(+Ellipse 序)

## 二期 · 第 30 轮（v7 体余项 + TCB 关闭 ★最新）

- **D57 字节序勘误（重大）**：v7 **u32 = 半字交换序**（DGN_INT32 宏，非纯 LE）、
  **f64 = VAX D + 同序**（CPLVaxToIEEEDouble）、**包围盒 = 偏移二进制 −2^31**；
  实证 = TCB units 字节 `00 00 64 00`=100（in/th）+ 5/5 LINE bbox 含顶点；
  旧 D53/D54 "RAW i32" 读取为错（测试只验 count）→ 已修 + 补 bbox 不变量回归
- **D58 体余项 + TCB 关闭**：ARC（sweep 符号-幅值 65/317 实证）/ELLIPSE/TEXT
  （numChars+FF,FD 串）/TEXT_NODE/CONE(仅3D) 逐字段定案；
  `ParseV7TCB`（units/scale/origin/换算/TextMult）+ views[8] 排队；
  **python 镜像↔Go 双实现 325 行逐位一致**（317 弧+6 椭圆+2 TCB）
- Go：`v7num.go`（V7Int32/V7Double/Put 逆函数）+ `v7tcb.go` + v7body 扩展；六包全绿
- 遗留：TEXT/CONE/TEXT_NODE 无真实样例（HOUSING 被 TCC 拦）→ 合成测试兜底，
  样例到位后复核；TCB views、属性区、复杂元素组=排队
- **队列**：① v7 复杂组+属性区（样例在手）② U10b 按需 ③ v8 样例固化（40+ [?] 含 Ellipse 序）

## 二期 · 第 31 轮（v7 复杂组 + 属性区 + 色表 ★最新）

- **D59 复杂组语义定案**：子元素 = 头后顺序 `numelems` 个（OGR L730，**不看 bit7**；
  同型头递归吞子树）；**span 公式 `tot+19 = Σ size/2`（含头）19/19 组实证**
  = dgnlib "excluding first 19 words"；bit7 = 组成员标志（writer 置位）
- **属性区**：`AttrIndex u16@body26` → `AttrRegion = body[idx*2+28:]`；
  sample 11648 个 + 金样 ellipse@10546(16B A951 头) ✓；A951 delta 应用排队
- **色表**：type5 level1（entry255 先存@34）；sample type5=level2 → 正确拒读
- Go：`v7group.go`（ComplexHeader/GroupV7Elements 递归）+ `v7attr.go`（色表）+
  V7Core.AttrIndex/AttrRegion；**python(OGR语义)↔Go 分组树 22803 节点逐位一致**；六包绿
- **队列**：① v7 剩余类型体（Cell+Rad50/BSpline头/Tag…）+ A951 应用 ② U10b 按需
  ③ v8 样例固化（40+ [?] 含 Ellipse 序）④ TEXT/CONE 样例复核（HOUSING 拷入仓库即可）

## 二期 · 第 32 轮（v7 Cell/BSpline/Knot 族 ★最新）

- **D60**：**Rad50**（base40 逐分支移植）+ **Cell 头(2)** 2D/3D（i32/2³¹ 矩阵 + 2D 派生
  xscale/yscale/rotation 精确复刻 GDAL）+ **CellLibrary(1)**（含 desc 9×Rad50）+
  **BSpline 头 27/24**（24 的 num_bounds 用正解 u16，GDAL ×556 笔误不复刻）+
  **Knot/Weight 26/28**（`(size−36−attr)/4` 计数 + i32/(2³¹−1)）
- **交叉验证**：python 镜像↔Go **5266 行逐位一致**（223 Cell + 2522 曲线头 + 2521 Knot，
  含 Rad50 名与派生浮点）；常驻金样测试固化（RARRAY/BSC/KW）
- Go：`v7cell.go`、`v7bspline.go` + 合成字节级测试；六包绿、gofmt/vet 干净
- **队列**：① Tag(37/66)/PointString(22)/Boundary(25)/Table 剩余 + A951 应用
  ② TEXT/CONE 样例复核（HOUSING 拷入仓库）③ U10b 按需 ④ v8 样例固化

## 二期 · 第 33 轮（v7 A951+Boundary+Tag · E3 分支清零 ★最新）

- **D61 A951 分数修正落码**：`ReadV7LineF/ReadV7MultiPointF`（V7PointF）+
  `ReadV7Boundary`；**python↔Go 8419 元素几何逐位一致**（分数顶点金样@13176）
- Tag 族：`ReadV7TagValue`(37) + `ReadV7TagSet`(66 level24, defs 四型默认值) +
  `ReadV7SharedCellDefn`(34, 115 实测)；**tagSet=plain LE u32 异常记 [?]**（GDAL
  CPL_LSBPTR32 与半字序并存）；25/37/24-66 无样例=合成字节级
- Go：`v7delta.go`、`v7tag.go` + v7cell 扩展；六包绿、fmt/vet 干净
- **E3 DGNProcessElement 分支清零**（除 PointString(22) GDAL 本身不解析、
  GROUP_DATA 通走 core）；v7 侧仅剩：TCB views、TextNode 字符串元素、
  其余属性 linkage 类型（raw+U10b）、样例复核项
- **v8 样例全机检索无存**（mdfind/Work/Documents 全是 v7 seeds）→ 外部依赖，
  样例到位前 v8 [?] 固化暂停；队列不变：U10b 按需 → v8 样例固化

## 二期 · 第 34 轮（v7 TCB views + 文档入口 ★最新）

- **D62 views[8] 落码**：flags/levels/origin(变换)/delta(×scale)/9×VAX 矩阵/conversion/activez；
  **`ParseV7Document`**（首元素 TCB + 分组森林 + `Extents()` master 单位并集）
- **交叉验证**：python↔Go **10 行逐位一致**（TCB+8 views+extents）；金样固化
  （view0 恒等矩阵+origin/delta、extents 板级 inch 跨度、view6 activez）
- 测试：sample 文档级 + **seed_2d/3d 文档级**（TCB dim↔魔数 bit6 互证）+ 截断报错
- Go：`v7tcb.go` 扩展、`v7doc.go` 新增；六包绿、fmt/vet 干净
- **队列**：① v8 侧（样例缺失=外部依赖；可做 Ghidra [?] 补证与合成测试加固）
  ② U10b 按需 ③ TEXT/CONE/样例复核等 HOUSING 拷入 ④ v7 小尾巴（TextNode 字符串元素 [?]）

## 二期 · 第 35 轮（U14 遗留 Ellipse [?] 关闭 · v8 ★最新）

- **D63 Ellipse 字段序四连证**：公开 getter（TG_Db.tx 导出）→ RTDynamicCast →
  impl 槽位（+0x600/+0x610/+0x638/+0x648）→ 字段直读偏移 → 与 fields 读取器
  `1801d8de0/1801d8e60` 存储序对齐 ⇒ **Ellipse2d = primary,secondary,rotation,origin
  （godgn 现序正确）**；**Ellipse3d = f64×2+quat+origin = 72B**
- **勘误**：旧 bodies3d 提取表 Ellipse3d=56B（**与 U14 Arc3d 同款 awk 漏读病**）——
  Go `ReadEllipse3d` 已补 primary/secondary + 测试；`DGN-V8-FORMAT.md`
  Arc/Ellipse 陈旧行一并修正（该表成稿于 U14 关闭前）
- 交叉复核：Arc getStartAngle→+0x600→0x220 ✓ 与 D56 吻合；发现 **getRotationAngle**
  为 2D 实名（无 getRotation@Ellipse2d 导出）；FUN_1801d7ae0 内十进制 600=0x258 槽位陷阱
- 新证据文件：`evidence/ghidra/out/TG_Db.{ellipse,ellpub,ellpub2,ellrot}.c`；六包绿
- **队列**：① v8 样例固化（外部依赖）② U10b 按需 ③ TEXT/CONE 样例复核（HOUSING）
  ④ v8 [?] 其余项（Ellipse hook vt+0x630 语义等，样例+按需）

## 二期 · 第 36 轮（U5 主体 · 显示头语义 + type100 勘误 ★最新）

- **D64 显示头 72B 语义全表**（CDGDispHeader getter 链反编译）：
  GG/priority/**props@8 位域（class·invisible·3dFmt·viewIndep·nonPlanar·notSnappable·hbit）**/
  lineStyle/lineWeight(默认1)/color(默认0)/range(6×i64)；Go `DisplayHeader` 全字段改名
  + 7 个位访问器
- **disp 判定勘误（行为级）**：type100(XREF) **永不读显示头**（旧文档 `&&` 系笔误，
  decompile `(bit12==0||type==100)` 为准，`dir.go` 早有排除为旁证）→ `parse.go` 修正 +
  `TestType100SkipsDisplayHeader` + 既有消费测试改用 type99
- **头字段语义**：`Sub u32@16`=**levelEntryId**（SetElementLevelID 链）、`C u32@12`=**字数**；
  element-header §1 表文件偏移列勘误（padding 错位+2）；A/B/Tail 收窄为 [?]
- Go：`header.go`（DisplayHeader 改名+访问器+头字段注释）、`parse.go`；六包绿
- **队列**：① v8 样例固化（外部依赖，连续四轮记录）② U5 残项(A/B/Tail/disp@10)
  ③ U10b 按需 ④ TEXT/CONE 样例复核（HOUSING）⑤ GetAttribSizeFromHeader（属性区定位）

## 二期 · 第 37 轮（U5 续 · B/C 字段定案 + linkage 精确切分 ★最新）

- **D65**：`GetAttribSizeFromHeader=(B−C)×2` ⇒ **B@8=总字数**（size=B*2+4，与 D32 独立吻合）、
  **C@12=属性区前字数**（attrib=(B−C)*2）；`dgnInLinkages` 的 totalWords/bodyWords ↔ B/C 定案
  （D24 "待样例核" 关）；**勘误 D64 "C=元素字数" 标签**（行为不变）
- **godgn**：`parse.go` 按 B/C 精确切分 linkage 区（ODA seek 语义，独立于体解码进度；
  B/C 无效回退 Rest）+ 区分测试（type27 体区46B 解码12B → 旧路径丢首记录，新路径 3 条全对）
- 六包绿；证据 `TG_Db.attrsz.c`；U5 剩 A@0/Tail@28/disp u16@10
- **队列**：① v8 样例固化（外部依赖，连续五轮记录）② U5 残项 ③ U6 codepage
  ④ U10b 按需 ⑤ TEXT/CONE 样例复核（HOUSING）

## 二期 · 第 38 轮（U5 收尾 · Tail/Range/flag 位域 ★最新）

- **D66**：**Tail@28 = f64 时间戳**（OdTimeStamp packed×1000 —— rdDouble 读法成因 ✓）；
  **Range = 6×i64 min+extent**（后三为**尺寸**非 max，`FUN_1808bd8b0` 直证）；
  flag bit10=nonModel、bit11=locked；deleted-by-complex=恒0 stub；
  getHeaderDataSize=36/108、getFieldDataSize=纯体字节（再证 C）
- Go：`DisplayHeader.Range`→[6]int64、`Header.IsLocked/IsNonModel`、注释；六包绿
- **U5 挂账仅剩 A@0、disp u16@10**（读取路径均不依赖）
- **队列**：① v8 样例固化（外部依赖，连续六轮记录）② U6 codepage（低价值按需）
  ③ U10b 按需 ④ TEXT/CONE 样例复核（HOUSING）⑤ 解析器健壮性/panic-free 属性测试

## 二期 · 第 39 轮（解析器健壮性属性测试 ★最新）

- **D67**：`robust_test.go` 常驻 4 组 panic-free 属性测试（固定种子、可复现）：
  v8 随机头/空间/变异夹具/双入口；v7 20 读取器 × 随机体；v7 帧+最小文档变异；
  GroupV7Elements 随机组 —— **约 5000 次迭代零 panic**
- 六包绿；"读取完全"新增一层不变量保障（错误路径=返回 error 非崩溃）
- **队列**：① v8 样例固化（外部依赖，连续七轮记录）② U6 codepage 按需
  ③ U10b 按需 ④ TEXT/CONE 样例复核（HOUSING）⑤ U5 挂账（A@0/disp u16@10）

## 二期 · 第 40 轮（U6 关闭 — 静态取证基本穷尽 ★最新）

- **D68 U6 关**：`rdAnsiString/rdUnicodeString` 反编译 = **纯 raw 无码页转换**
  （n≥0: rdBytes / n<0: NUL 与 u16-0 循环，D46 互证）；字节级读取 raw 即终态，
  godgn 无需改动
- **静态可解项盘点**：U4/U5(主体)/U6/U7/U9/U11/U12/U13/U14 + D53-D68 全关；
  挂账：U5 残（A@0/disp u16@10，无 getter 触碰）、U10b（按需无调用方）、
  ellipse hook 语义[推断]、U3 收窄残（子块内部布局——Go 管线已实现+健壮性测试覆盖）
- **外部依赖（连续八轮记录）**：v8 真实样例（40+ 推断项固化）；v7 TEXT/CONE 复核（HOUSING/TCC）
- 六包绿；健壮性属性测试常驻（D67）

## 二期 · 第 41 轮（写侧交叉验证第一批 ★最新，应用户指示）

- **D69**：无 v8 样例 → 以 **dgnOutFields 写出路径为第二独立源**交叉验证（用户指示）：
  头36B/显示头72B/Ellipse2d/3d/Arc2d/3d 写出序与读取侧/godgn **全部逐位镜像一致**
  （含 Tail=double 再证、3dFmt 位 k2dTo3d/k3dTo2d 转换钩子、rotation→quat 生成分支）
- **方法论沉淀**：impl 内部偏移 ≠ 文件序；**写出调用顺序才是文件序** —— 读/写/公开 getter
  三方互证 = 无样例条件下的最强验证链
- 新证据：`TG_Db.outfields.c`、`TG_Db.hdrwrite.c`；godgn 零改动（一致性即验证）
- 下批写侧验证：Line/LineString/Text/TextNode/Cone/Cell/ComplexHeader 族

## 二期 · 第 42 轮（写侧互证第二批 —— 抓出 2 个真 bug ★最新）

- **D70**：Line/LineString(+Shape)/Cone/Cell/Text2d/ComplexStr 写侧 **全部一致**；
  但读写双证抓出 —— ① **Text3d 漏读 f64×4**（且 **D37"3D 无 N×3 表"勘误：有！**）；
  ② **TextNode3d 漏读 f64×3**（=92B）—— 与 Arc3d/Ellipse3d 同款旧提取漏读病，
  **写侧互证方法论第二次抓虫**
- godgn：`ReadText3d`（D[4]+CharAttrs+pad）/`ReadTextNode3d`（D[3]）已修+测试重写；六包绿
- 新证据：`TG_Db.outfields2-4.c`、`textin3d.c`、`lsout.c/ls3dout.c`
- 写侧验证剩余：BSpline 头/Knot、Dimension、Multiline、Boundary、Table 族（下批）

## 二期 · 第 43 轮（写侧互证第三批 —— BSpline 归属勘误 ★最新）

- **D71**：RTTI 重钉 BSpline 全族类↔type 归属（D39 表地址张冠李戴）：
  Curve(27)=u32×3 ✓、Knots/Weights=剩余 f64 ✓、Poles/Boundary ✓ —— godgn 均正确；
  **唯一真错 = Surface(24) 多读1个 u32（u32×10→9×u32，读写双证）→ 已修**
- 附带：Multiline 写侧前缀/断点结构与 D45 一致 ✓；TableEntry=rest-blob ✓
- 新证据：`evtBs.txt`（RTTI 归属）、`bsin.c/bsin2.c/outfields5.c`；六包绿
- 写侧验证剩余：Dimension(33)（997行读+写侧对照）、Table header 族 —— 下批

## 二期 · 第 44 轮（写侧互证第四批 —— Dimension/Table 漏读 ★最新）

- **D72**：① **Dimension 前缀缺 u32×3**（helper FUN_1808c52e0/写侧 FUN_1808c5500 =
  rd/wrInt32×3；前缀 188→200B，D43/D44 勘误）→ godgn 加 E1/E2/E3 + 测试；
  ② **TableMLStyleHeader 缺 8B 保留字**（真=u16+5×u16=12B；D49 "4B" 错）→ 已修；
  ③ TableLevelHeader=u16×2,i64,f64×2 ✓ 双证一致
- 四批写侧互证累计：**抓真 bug 6 个 + 勘误 5 处**（Ellipse3d/Text3d/TextNode3d/
  Surface/Dimension/MLStyle；D37/D39/D43/D44/D49 勘误）
- 六包绿；新证据 `outfields6.c/dimhelp.c/dimhelp2.c/tbl.c`
- **写侧互证状态**：P0 全集 + BSpline 族 + Cell/Cone/Boundary/ComplexStr +
  Dimension + 表族（Level/MLStyle/Entry/blobs）均已双证；未做写侧：
  Solid/Surface 头(18/19，D38 读侧 12B)、CellLibrary(1)、Multiline 段/顶点循环细节
  （前缀+断点已证）

## 二期 · 第 45 轮（注册完整性审计第一批 ★最新，应用户"最大化读取完善"指示）

- **D73**：RTTI 补钉（DumpVtables gapvt.txt）——
  ① **type11 Curve / type13 ConicSection = LineString 族体**（ECurve2D/3D、EConic2D/3D
  共用字段读取器1802e4480）→ **godgn 补注册** p0/p3(11)、p0/p3(13) + 路由测试；
  ② **type105 Mesh**：EMeshHeader=u32+钩子，6 变体子类 → **GroupSub wildcard =
  u32+Raw 无损兜底** + 测试（变体细分=后续）
- 剩余缺口清单（Proxy raw 保真，均不丢字节）：EMatrixDoubleData(103) 部分已知、
  ESharedCellInst(35) 待续、ERaster*(87-94)、Tag(37)/View(97,98)/NamedGroup(110,111)/XREF(100)
- 六包绿；注册数：**31 类型键 + wildcard(33,105) + 表族 6 键**

## 二期 · 第 46 轮（注册完整性审计第二批 ★最新）

- **D74**：① Mesh 5/6 变体共用 u32 读取器（几何在子元素；FaceLoops 专属长读取器 Raw 兜底）；
  ② **SharedCellInst(35) 完整定案 152B**（u32,u16,u16,Pt3d×2,f64×9,Pt3d）→ 注册+双测试；
  type35 隐式 disp 测试改写（35 已实路由）；③ SharedCellDef(34) 部分已知（kFileFiler 尾段待追）
- 六包绿；**注册数：32 类型键 + wildcard(33,105) + 表族6键**
- 剩余缺口：Def(34) 尾段、Matrix(103)、Raster(90)、FaceLoops 变体、Tag(37)/View(97,98)/
  NamedGroup(110,111)/XREF(100)（Proxy raw 保真）

## 二期 · 第 47 轮（完整性审计第三批 ★最新）

- **D75**：① **SharedCellDef(34) 定案 148B**（u8×2,u16,Pt3d×2,f64×9,Pt3d；id 列表=kUndo-only）；
  ② **MatrixDoubleData(103) 定案**（u16+70B+u32×4+f64数组）—— 越读→ErrTruncated 无死循环；
  两者注册+合成/截断/路由测试全绿
- **注册数：34 类型键 + wildcard(33,105) + 表族6键**；六包绿
- 剩余缺口：Raster(90)、FaceLoops 变体、Tag(37)/View(97,98)/NamedGroup(110,111)/XREF(100)

## 二期 · 第 48 轮（完整性审计第四批 ★最新）

- **D76**：① **RasterHeader(87) 读写双证**（u16×2,u8×2,u16×3,f64×2,Pt3d=52B）→
  p0/p3 双注册；② **RasterReference(90) 定案**（u16×2,u32×4,i32×2,Pt3d,f64×4
  + 条件尾 u32×2@首u16==0）→ 注册+双尺寸测试
- **注册数：36 类型键 + wildcard(33,105) + 表族6键**；六包绿
- 剩余：RasterRefComp* 子族（88/91 数据段）、FaceLoops 细节（Raw 兜底）、
  Tag/View/NamedGroup/XREF 无独立 impl（Proxy 保真）

## 二期 · 第 49 轮（完整性审计第五批 ★最新）

- **D77**：RasterRefComp 子族 7 读取器全反编译清点 —— base(88)=头7项+rest **已注册**；
  Clip reader 就绪（48B+N×Pt2d，待 subtype 映射）；Geo/Rendering/透明族 layout 记档，
  **复杂子类不注册**（半错不如 Proxy）；subtype↔class 映射=rxInit 下批
- **注册数：37 类型键 + wildcard(33,105) + 表族6键**；六包绿

## 二期 · 第 50 轮（rxInit 黄金映射表 ★最新）

- **D78**：伪构造器→rxInit→`FUN_180137ee0(type,variant)` 立即数链批量提取 ——
  **现有 godgn 全部注册获独立验证**（87=0/1、88=0、90=0、34=0、35=0、18/19、22、36…）；
  新获：91 七变体表、94、Tag=(37,0)/impl=**EAttribute**（长结构+条件分支→下批全 trace）、
  (2,9/10)=Ole2Frame、(2,14/15)=SectionMarker、(106,1/2/3)
- 六包绿；证据 `rxinit2-4.c/gapvt5-6.c/tag.c`
- **下批**：Tag(37) 全 trace + 注册；91 变体（Clip reader 已就绪，待 (91,N)↔class 补全后注册）

## 二期 · 第 51 轮（Tag(37) 全 trace 定案 ★最新）

- **D79**：EAttribute 读取器全文 trace —— 固定段 216B + 值分支（串/u16/u32/f64/blob）
  + 16bit 对齐；旋转=quat 与 f64×4 盘上等宽（存 Rot[4] 无损）；
  godgn `ReadTagElement`+pn(37)+全值型/截断/路由测试绿
- **注册数：38 类型键 + wildcard(33,105) + 表族6键**；六包绿
- 剩余：91 变体注册（Clip reader 就绪，余下 Geo/Rendering/透明 trace）、94 RasterFrame

## 二期 · 第 52 轮（Raster 变体+SectionClip 收尾 ★最新）

- **D80**：① Binary(91,1)/RGB(91,3)/Mask(91,11)→ERasterRefCompUnknown（u16×2,u32+rest）
  **三键注册**+正/负路由测试；② **SectionClip(106,1)=rest-blob 读写双证** →
  **groupOf 106 入 GroupSub** + 注册；(91,0)/(106,2) Proxy 负向固化
- **注册数：42 类型键 + wildcard(33,105) + 表族6键**；六包绿
- 剩余：94 RasterFrame reader、Geo/Render/透明4变体 trace（Proxy 保真）

## 二期 · 第 53 轮（Geo/Render 定案注册）

- **D81**：① **Geo(91,7)=152B 定案注册**（u16×2,u32,Pt3d,Pt2d,f64×2,Pt2d,u32×6,Vec3d×2）；
  ② **Render(91,8)=64B 定案注册**（u8×2+4×3字节色 packed u24+…）；
  ③ RasterFrame(94) 部分钉（含 seek+4 跳过段，尾巴未完 → Proxy）
- **注册数：44 类型键 + wildcard(33,105) + 表族6键**；六包绿
- 未注册仅剩：94 尾巴、Transp(9)/RGBTransp(10)（Proxy 保真）

## 二期 · 第 54 轮（Raster 未注册项清零 ★最新）

- **D82**：① **RasterFrame(94) 全 trace 定案注册** —— 勘误 D81③：skip4 后实为
  **f64×16 矩阵**（漏数 4×4 嵌套循环）；分支选择器=矩阵后**第一个** u16（E）非第二个
  （F）；完整序含 bytes512 + 尾 f64×6 + skip96（EOF 容忍）→ `ReadRasterFrame`+pn(94)
  +双分支测试+路由测试；② **Transp(91,9)=528B**（256×(u8 索引,u8 值)）注册；
  ③ **RGBTransp(91,10)=240B**（32×(3B RGB,3B RGB,u8 alpha)）注册
- **注册数：47 类型键 + wildcard(33,105) + 表族6键**；六包绿
- **rxInit 黄金映射表（D78）全部处置完毕** —— 类型键级注册审计收口
  （Ellipse 字段序 D63 已关，无遗留 getter 跳）

## 二期 · 第 55 轮（写侧互证第三批 ★最新）

- **D83**：以写者（dgnOutFields）为第二独立源对照 godgn 读取器，6 族全对齐：
  ① **Multiline(36) 全序确认**（f64×2,u32,u16,u8×4,…,u32×18,f64×3 + 段/顶点/
  break 三循环；break 按顶点嵌套写出但流上平坦）—— **勘误：`Selector` 原错标
  U8[3]（与 BreakCnt 同源），写侧证实 0x238=U8[2] 为独立字段 → 已修+断言**；
  ② Solid/Surface=u32+u16×4 ✓；③ Cone=u16×4+quat+Pt3d+f64+Pt3d+f64 ✓；
  ④ BSplinePoles2d/3d=u32×2+count×Pt ✓（与 LineString 共享体互证）；
  ⑤ PointString2d/3d=父调用+每点 4×f64 / quat ✓；⑥ Knots/Weights=count×f64 ✓；
  ⑦ Shape=纯委托 LineString ✓
- 除 Selector 标签外**零改动**；六包绿
- D70 方法论三批累计双证类型：Line/Text/Cone/Cell/Ellipse/Arc/Text3d/TextNode3d/
  LineString/Multiline/Solid/Surface/Poles/PointString/Knots
- **覆盖率补口（第55轮收尾）**：`TestType3DRoutes` 补齐全部 6 个 3D 路由注册
  （Shape3d/TextNode3d/Ellipse3d/Arc3d/Text3d/PointString3d 经显示头 bit11 端到端）+
  `ReadShape3d` 直测；六包绿；余下 <80% 均为错误分支（robust_test 变异已触达）

## 二期 · 第 56 轮（路由覆盖补口 ★最新）

- **D84**：为全部剩余路由注册补 ParseAll 测试（Complex 12/14、Solid/Surface、
  Cone、BSpline 24/25/26/28、Multiline、Table 96 族、CellHeader2d/3d）——
  **抓出真 bug：`pn(95)` 死注册**（GroupNone 键 vs `groupOf(95)=GroupSub`，
  TableEntry 从未命中、type95 全落 Proxy）→ 改 `RegisterWildcard(95, GroupSub)`
- 六包绿；注册键数不变，type95 读取路径首次真正生效
- **回归护栏**：`TestRegistryBucketConsistency`（全部 registry/wildcard 键 Group
  必须 == groupOf(Type)+桶成员表冻结）+ `TestEveryRegistryKeyIsReachable`
  （每个注册键构造 Record 走 Lookup 必中）—— type95 类死注册从此无法混入

## 二期 · 第 57 轮（v7 共享单元引用新解 ★最新）

- **D85**：v7 type35（shared cell reference，39 实例）此前完全未解 —— 样例逐字段
  定案：range6 半字交换 i32 UOR@48..67 + 3 scale 槽@72/104/136 + ASCII 名字@160..176；
  **39/39 ref 名字全部命中 115 defn**（defn 名字同槽，`ReadV7SharedCellDefn` 增 Name）
  → `ReadV7SharedCellRef` + 合成/样例双测试 + robust 入口
- 六包绿；GDAL 默认分支类型由样例实证补齐

## 二期 · 第 58 轮（类型普查金样 ★最新）

- **D86**：`TestSampleV7TypeCensus` —— sample.dgn 全量帧解析金样：22803 元素、
  18 类型逐计数直方图 + 帧首尾相接 + FF/FF 终止断言；CONTROL(8)/CELL_DEFINITION(10)
  各 1 例记档（GDAL 同走默认分支）
- 六包绿；v7 帧层回归防线至此无死角

## 二期 · 第 59 轮（E3 权威源码核验 ★最新）

- **D87**：本地发现完整 GDAL dgnlib 源码（flywave-computevision）—— 作为权威 E3
  对 v7 全部读取器逐偏移对拍：TEXT/TEXT_NODE/ARC/ELLIPSE/CONE/LINE/LS 族/A951/
  CELL_HEADER/CELL_LIBRARY/TCB **零偏差**；**TCB views[8] 队列项关闭**（源码
  L1538-1574 逐字段一致）；DGNTransformPoint/VAX double 互证 ✓
- 方法论升级：v7 [?] 优先查本地 dgnlib 源码；TEXT/CONE 样例复核降级为锦上添花
- 六包绿；v7 侧实现与 GDAL 参考实现达到源码级一致性

## 二期 · 第 60 轮（U10b 第一批 ★最新）

- **D88**：linkage 分发器定位 —— `oddgSetLinkageHandler` 39 项黄金表（FUN_1800548f0）+
  查表 factory（FUN_1808bf690）+ Proxy 回退；逐 handler 反编译定案 11 类 payload
  （SeedPoints/Thickness/InfiniteLine/SharedCellFlags/SheetScale/DoubleArray/String/
  ByteArray/AssocRegion/**FillStyle 族分发器**/Note）；f64 退化指数→0 规则双证
- godgn `dgn/linkage/payload.go`：DecodePayload 分发 + 11 解码器 + HandlerIDs 表 + 11 组单测
- 六包绿；余项：Dimension/LStyleMod/LevelMask/TextAnnotation 等未 trace handler

## 二期 · 第 61 轮（U10b 第二批收口 ★最新）

- **D89**：19 个余项 handler 全反编译定性 —— 修正 D88 HandlerIDs 两处错误（0x222e→0x522e、
  剔除 0x5229/0x5710，精确 39 项）；新增 HandlerNames 39 项 id→类名表；
  新解码器：DBLinkage 族（10 ID 共享 handler + DBType 枚举）、BitMask（payload[4]==6
  → TextWhiteSpace）、Dependency（变体选择器 (word3>>10)&0xf）；DMRS 记档留 raw
- **U10b handler 层 100% 收口**（39/39 定性）；typed 解码 15/39；类委托型的
  Impl 读取器布局按需下批
- godgn `dgn/linkage/payload.go`：15 解码器 + HandlerNames + 精确表；六包绿

## 二期 · 第 62 轮（U10b 第三批收口 ★最新）

- **D90**：14 个类委托型 handler 的 Impl slot-15 读取器全反编译，12 个新解码器
  （TextAnnotation/RefAttachPath/SheetModelEx/Xml/FilterMember/BoundaryClip/
  LStyleMod/SheetModel/Ole/TextIndentation/DimTextStyle/Material）；
  4 个按设计留 raw（DMRS/Dimension/Hatch/Brep，各有专用理由记档）
- **U10b 全部 39 handler 闭环：35 typed + 4 documented-raw**；
  `TestDecodersCoverHandlerTable` 钉死覆盖契约；六包绿

## 后续：设计编码阶段

- [x] **M1 已开工**：`../godgn/`（module go-dgn）
  - `internal/le` 位流原语 / `internal/cfb` 只读 CFB（v3+v4 条目）/ `cfbtest` 合成夹具
  - `dgn`：Open(v8 探测/v7 拒绝)、流分类、36B 头、72B 显示头、u32 目录+复杂跨度、  
    (type,variant) 注册表 + Proxy 回退
  - `go build ./... && go vet ./... && go test ./...` 全绿
- [ ] M2 元素体
- [ ] 实现顺序：cfb/流名 → chunk+offset目录 → 36B头 → 分发registry → 核心元素体  
  → linkage blob 迭代 → 表元素 → 样例金测试
- [ ] 实现到对应层时再下钻：U7b(ElementChunk绑定) / U9(谓词) / U10(逐linkage字段) /  
  U5(显示头) / U8(校验和) / U4(v7 第二阶段)

## RVT 侧记（资料摄入，不占 DGN 轮次）

> **已迁移**：RVT 分析/实现整体迁至同级独立仓库 **`/Users/xuning/Work/go-rvt/`**
> （module `github.com/flywave/go-rvt`）。本项目仅保留 `04-rvt/` 指引页；
> RVT 专属测试（internal/cfb/rvt_sample_test.go）已移除。以下为迁移前记录：

- **ODA BIM SDK 消费方代码摄入**：用户提供 3D Repo bim-ex `FileProcessorRvt.cpp`
  （AGPL 2018）→ 已随 RVT 迁至 `go-rvt/evidence/external/`（台账 R3–R10）
- 关键结论：① RVT 读取 = 独立商业产品 **ODA BIM SDK**（OdBm*，Loader/Modeler 分模块）；
  ② 版本门控实证（eUnsupportedFileFormat）；③ 对象模型镜像 Revit API
  （OST_* 类别/View/Units/三坐标系 Survey Point 变换）；④ 几何=BRep 三角化黑盒，
  **纯 Go 不可重现完整几何**
- **迁库后新增（go-rvt/analysis/）**：BimRv Linux SDK 盘点（TB_Loader 管线/Format{Year}
  模块族，R11–R13）+ 真实样例 CFB 实测（R14–R18：容器/压缩体系/BasicFileInfo TLV）——
  详见 go-rvt `analysis/findings.md`

## 二期 · 第 63 轮（拓扑桥 M1–M5 · go-dgn↔go-topo ★最新）

- **仓库重组**：`godgn/` 上移至仓库根，module 更名 `github.com/flywave/go-dgn`，
  推送 `git@github.com:flywave/go-dgn.git`（main 分支）
- **D91**：go-topo 桥设计定案 `analysis/05-go-design/topo-bridge.md` —— 参照 IFC
  导入模式（Reader→拓扑 Wire + Mesh 双出口）；中立 scene IR 解耦 50+ 解码器；
  坐标契约（v7 走 TCB master 单位、v8 SetUnits 显式注入不猜）；弧细分 §6.4
  弦高公式 `n = ceil(sweep/(2·acos(1−ε/r)))` clamp [3,256]
- **M1**：P0 拆分收尾 —— `dgn/element/`（prim/geom/text/solid/cell/raster/table）+
  `dgn/linkage/`（payload_geom/style/str/db），声明级 diff 零变化，六包绿
- **M2**：`dgn/scene`（Kind/Point/Arc/Entity 零依赖 IR）+ `SceneV7` /
  `SceneV7AtMaster` / `SceneV8` 构建器；金样：sample.dgn → 9138 entities、
  7 kind 直方图（ComplexHeader19/Segment5814/Polyline2605/Arc317/Ellipse6/
  CellDef338/CellRef39）、复杂组 ParentID 完整性、AtMaster 坐标映射
- **M3**（go-topo faa6771c7）：`dgn.go` DgnReader —— v7 SceneV7AtMaster +
  v8 ElementChunks 分块；Segment/Polyline→Edge 链 Wire、Arc→三点弧/整圆、
  Ellipse→TopoMakeEllipse、quat 旋转纯 Go；金样 wires=8742；合成弧测试修
  两处夹具 bug（VAX 双精度改用 V7PutDouble、TCB 字段偏移 1108 直索引）后过
- **M4**（go-topo fab488719）：`dgn_mst.go` DgnToMst —— 每 wire 元素一个
  MeshNode（EdgeGroup 连续索引边对），§6.4 弦高细分（椭圆取 min²/max 保守
  曲率半径），默认 ε=0.1；金样 8742 nodes / 106214 verts / 97472 edges；
  arcSegments 单测覆盖 clamp 与符号
- **M5**（go-topo 4c8ff5826）：层级金样 —— ParentId>0 全解析（56 子→父必为
  ComplexHeader）、CellDef 338 全命名（其中 223 个 type-2 带 placement
  Transform）、CellRef 39 全命名；SetUnits scale 契约测试（unset=原样 UOR）
- 六个 DGN 桥测试（TestDgnReader×3 / TestDgnToMst×2 / TestDgnHierarchy /
  TestDgnSetUnits / TestArcSegments）全绿
- 遗留：v8 全文件金样待真样例（并入 v8 样例固化批次）；Cone/Solid 网格出口、
  CellRef 按名解析 CellDef → 二期

## 二期 · 第 64 轮（3D 元素补全：B 样条曲线组装 + 锥体网格 ★最新）

- **动因**：桥此前只出线框类元素（线/折线/弧/椭圆）；sample.dgn（Is3D）中
  **2522 条 B 样条曲线只以控制多边形折线出口**，BIM 导入需要真实 3D 曲线/体
- **D92**：v7 B 样条存储结构定案 —— type27 头**不建复杂组**，与 knot(26)/pole(21)/
  weight(28) 兄弟元按**文件相邻序**关联（bit7 仅为组成员标注，D59 语义再证）；
  **num_knots = num_poles − order → 存的是内节点**，全向量 = order×0 + 内节点 +
  order×1（ODA DgBSplineCurve.h L282 开曲线 knots=poles+order 互证；sample 2522 条
  全为 order4/非有理/内节点∈(0,1) 严格递增，1 条 num_knots=0 亦吻合）
- **godgn `dgn/scene`**：新增 `KindBSplineCurve` + Entity.Knots/Weights/Degree 字段；
  `SceneV7` 预扫描组装 `assembleV7BSplines`（成功则兄弟元标记 consumed，21 不再
  单独出 Polyline；组装失败回退 standalone 折线，与 GDAL 点阵处理一致）；
  poles 走 ReadV7MultiPointF（A951 分数增量）；金样：实体总数 9138 不变，
  Polyline 2605→83、+BSplineCurve 2522、nested 56 不变
- **go-topo 桥**（7c091bbc0）：`GeomMakeBSplineCurve`（全向量→uniq+mults）→
  精确 OCCT 边；DgnToMst 纯 Go de Boor 采样 n=clamp(2·poles,16,128)；
  **KindCone 三角化**（64 侧+双盖=128 面/68 顶点，零半径端收锥尖）
- **C++ 关键修复**：geometry_c_api.cc ① bspline 两函数 knots/mults 数组按独立
  KnotCount 定长（旧版按 poles 定长→越界读）② **22 处 NCollection_Array1
  `{0,n}` off-by-one**（(Lower,Upper) 语义 → 末位未初始化元素；BSpline 恒报
  "Knots interval values too close"、Bezier 多出 (0,0,0) 极点静默污染）；
  排查手法与教训记入 go-topo AGENTS.md
- 金样：sample wires=8742（含 2522 条精确 B 样条 wire）、**Z 非零 wire 8646**
  （3D 坐标直通证明）；DgnToMst 8742 nodes / 202059 verts / 193317 edges；
  合成样例：B 样条夹持端点、锥体网格、SetUnits 契约全绿
- 遗留：v8 B 样条/实体（KindSolid）映射待 v8 样例；18/19（3D surface/solid 复头）
  与 24（B 样条曲面）解码头已有、scene 映射待样例；bezier 族修复无使用方金样回归
  （仅 geometry_test/topo_test 覆盖）
