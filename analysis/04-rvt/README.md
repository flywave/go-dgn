# RVT（Autodesk Revit）格式 — 分析路线图

## 现状结论

- **本 ODA Teigha 25.4 交付物不具备任何 RVT 读写能力**：
  `ODA/bin` 287 个模块与 `ODA/include` ~1500 头文件中 `revit|rvt` 零命中；
  仅有 `TD_BimDb`、`ExDwgIfc`、`ExDwgStep`、`TD_PdfImport` 等互转组件。
  （证据：全量字符串检索，见 `../03-dgn/findings.md` R1）
- 因此 **RVT 无法通过 REA 分析本包获得**，需要独立取证路线。
- **外部线索已摄入**：3D Repo bim-ex 的 `FileProcessorRvt.cpp`（消费
  **ODA BIM SDK**，独立商业产品线）→ `oda-bim-clues.md`（台账 R3–R10）。
  结论：存在与 DGN 同深度的取证路径（获取 ODA BIM SDK → 头文件 E1 + DLL REA/E2），
  但 SDK 本体不在手；几何提取=Modeler 黑盒三角化，纯 Go 不可重现完整几何。

## 推荐路线（按可行性）

0. **C0 SDK 路线（新增，深度上限最高）**：获取 ODA BIM SDK（BimRv）的
   include + bin —— E1 头文件钉对象模型全表、E2 对 BimLoader/BimModeler
   DLL 复刻 TG_Db 的 REA/Ghidra 分析。前置：SDK 授权/试用渠道；
   3D Repo bim-ex 构建依赖可指出模块全名（见 `oda-bim-clues.md` §3）。
1. **C1 结构层（把握最高）**：RVT 是 OLE/CFB 复合文档（与 DGN v8 同族）。
   取一份 .rvt 用 CFB 工具列目录（流/存储名），沉淀 `rvt-container.md`。
   工具：`oledump`/`olefile`（Python）或复用本次 oless 分析经验。
2. **C2 元数据层**：`BasicFileInfo`（明文/UTF-16 元数据：版本、建立时间、
   中心点等）、`PartAtom`、`Formats`、`RevInfo` 等流多为可直接解析的
   XML/键值/明文 —— 纯 Go 可先支持"只读元数据"。
   （SDK 侧对应物 `BmBasicFileInfo.h` 已见 include，R6。）
3. **C3 模型数据层（最难）**：`Basic File Format` 为 Autodesk 专有、
   未公开；社区逆向资料极少且随版本变化（版本门控，R5 佐证）。
   需要：多版本样例（2016→2025）+ 差分分析（RE）+ 可能的 Revit IFC 导出对照。
   **建议在 DWG/DGN 完成后再启动。** 几何完整重建仅经 C0（Modeler 黑盒）可行。
4. **替代方案评估**：若业务只要"读模型"，评估 IFC（开放）路径是否覆盖需求，
   RVT 仅做识别/元数据。

## 产出物

- ✅ `oda-bim-clues.md` — ODA BIM SDK 消费方代码线索（台账 R3–R10）
- ✅ `../evidence/external/FileProcessorRvt.cpp` — 证据源存档
- `rvt-container.md` — CFB 流目录清单（需样例文件）
- `rvt-basicfileinfo.md` — 元数据流格式
- `rvt-unknowns.md` — 版本差异与未知项
