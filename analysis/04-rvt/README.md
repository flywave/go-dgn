# RVT（Autodesk Revit）格式 — 分析路线图

## 现状结论

- **本 ODA Teigha 25.4 交付物不具备任何 RVT 读写能力**：
  `ODA/bin` 287 个模块与 `ODA/include` ~1500 头文件中 `revit|rvt` 零命中；
  仅有 `TD_BimDb`、`ExDwgIfc`、`ExDwgStep`、`TD_PdfImport` 等互转组件。
  （证据：全量字符串检索，见 `../03-dgn/findings.md` R1）
- 因此 **RVT 无法通过 REA 分析本包获得**，需要独立取证路线。

## 推荐路线（按可行性）

1. **C1 结构层（把握最高）**：RVT 是 OLE/CFB 复合文档（与 DGN v8 同族）。
   取一份 .rvt 用 CFB 工具列目录（流/存储名），沉淀 `rvt-container.md`。
   工具：`oledump`/`olefile`（Python）或复用本次 oless 分析经验。
2. **C2 元数据层**：`BasicFileInfo`（明文/UTF-16 元数据：版本、建立时间、
   中心点等）、`PartAtom`、`Formats`、`RevInfo` 等流多为可直接解析的
   XML/键值/明文 —— 纯 Go 可先支持"只读元数据"。
3. **C3 模型数据层（最难）**：`Basic File Format` 为 Autodesk 专有、
   未公开；社区逆向资料极少且随版本变化（版本门控）。
   需要：多版本样例（2016→2025）+ 差分分析（RE）+ 可能的 Revit IFC 导出对照。
   **建议在 DWG/DGN 完成后再启动。**
4. **替代方案评估**：若业务只要"读模型"，评估 IFC（开放）路径是否覆盖需求，
   RVT 仅做识别/元数据。

## 产出物（待建）

- `rvt-container.md` — CFB 流目录清单（需样例文件）
- `rvt-basicfileinfo.md` — 元数据流格式
- `rvt-unknowns.md` — 版本差异与未知项
