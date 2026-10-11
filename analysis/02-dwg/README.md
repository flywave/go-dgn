# 02-dwg — DWG 格式分析（第二阶段，占位）

状态：⬜ 未开始（优先级排在 DGN 深挖之后）

## 已完成的入口定位（证据见 `../03-dgn/findings.md` W1-W4）

- 文件 I/O：`TD_DbIO.tx`（1.4MB，863 导出）——
  `OdDwgFileController/FileLoader/FileSectionsInfo/FileSecurity/FileSplitStream`、
  **`OdDwgR18FileController/Header/Section`、`OdDwgR21FileSplitStream`、
  `OdDwgR24FileLoader`**（R18/R21/R24 = DWG 2004/2010/2018 代际的 ODA 内部代号）
  → 导出全表：`../evidence/exports/TD_DbIO.tx.exports.txt`
- 版本魔数 AC1014/15/18/21/24/27/32：`TD_DbCore.dll`（strings 7 命中）
- 实体编解码：`TD_DbEntities.tx`（8070 导出，含实体 `dwgInFields` 家族，待验证）
- 示例调用链：`DWGReadWriteOperator` 源码 + `DWGReadWriteOperator.pdb`（可完全符号化）

## 计划文档

- `file-layout.md` — 头部/section locator/页映射（R18 vs R21+ 差异）
- `bitstream.md` — BS/BL/BD/RL/RD/MC/MS/H 位流原语（ODA 对应 `OdDbDwgFiler` vtable）
- `object-map.md` — 对象映射与类段
- `entities.md` — 实体类型与字段

> 建议：DWG 公开规范（Open Design Specification）+ libreDWG 可与 RE 交叉验证，
> 比 DGN 更容易做 E3 印证。
