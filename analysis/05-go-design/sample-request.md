# 真实 BIM DGN 样本征集工单（D119）

> 状态：**征集中**（2026-10-13 发起）。接收方式：脱敏后放入
> `go-dgn/dgn/testdata/`（文件名建议 `v8_bim_<来源>_<内容>.dgn`），
> 或提供只读样本路径，由维护者完成脱敏与入库。

## 背景

go-dgn → go-topo 的 DGN 桥已完成（D110–D118）：v7/v8 全线框、锥台实体、
v8 网格（18 真实网格验证）、v8 Solid(18/19) 边界甄别、SharedCell DefID
实例化链（反汇编+合成往返）、ACIS SmartSolid 五类解析面+边界重建
（5 个真实 SAT 样本全部进入 go-topo）。以下类别已有完整实现，
**缺真实样本做最终实证**。

## 样本需求清单（按优先级）

| # | 样本内容 | 验证点 | 现有证据基线 |
|---|---|---|---|
| 1 | **v8 SharedCell**：含 SharedCellDefinition(34) + SharedCellReference(35) 的 v8 文件（MicroStation 放置→共享单元、或 active cells） | ① 0x2716 依赖链 roots[0]=定义句柄（D112 反汇编链）；② StringLinkage(id=1) 定义名；③ flag bit14 子归属；④ 按放置实例化进 go-topo（defID→byID） | D112 反汇编 + D114 合成往返（TestSceneV8SharedCellRoundTrip / TestDgnToMstV8SharedCellInstance） |
| 2 | **SmartSolid(SmartSurface)**：含 type-2 cell header + 0x522E BrepLinkage 的实体（MicroStation 建模→SmartSolid、参数化实体） | ① kAcisData(2)：SAT 子集解析→精确 B-rep 重建（D114–D116 已就绪，5 真实 SAT 样本全闭环）；② kParasolidData(1)：载荷判别位与 blob 完整性 | 0x522E 载荷布局 CDGAttribEmbeddedBRep 读写双证（D111）；ACIS 通路 POC 全链实证（D113） |
| 3 | **带网格(105)/Solid(18/19) 的 BIM 文件**：任意含 v8 网格/实体的工程文件 | 网格 105 面语义（已 18 网格验证，扩样本矩阵）、18/19 边界子元素归属 | D109/D110 |
| 4 | **真 NURBS spline-surface**（非 rotsur 的 `nubs` 块） | SAT-3 NURBS 面 解析→重建 | rotsur 分支已实证（D116） |

## Parasolid 离线细分替代路径（若无法提供 ACIS 类样本）

kParasolidData SmartSolid 需要**许可的 MicroStation / PowerDraft / ODA
产品**执行一次离线细分导出（任一即可）：

- MicroStation：`File → Export → 3D 网格（glTF/OBJ/DGN mesh 元素）`；
- ODA 转换链：`ODAFileConverter`/`ExDgnVectorize` 类工具的细分产物
  （本工作区归档的发行缺 libOdTrial 授权运行件，无法自跑——D113 实测）；
- 或任何能把 Parasolid 转 STEP/SAT/mesh 的许可工具链。

产物直接走 go-dgn 网格管线（v8 mesh 105 / glTF）进入 go-topo，桥侧已就绪。

## 脱敏要求

- 移除/替换业务敏感的地理参照、项目属性（TagData/DBLinkage）——
  go-dgn 只读几何与元素结构，属性 linkage 保留 raw 不解析；
- 文件可含多余元素（probe/meshdump 会输出全量清单用于甄别）。
