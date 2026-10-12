# go-dgn 纯 Go 解析库 — 逆向分析资料库

本目录组织 ODA (Open Design Alliance) Teigha 25.4 分析结果，作为纯 Go 解析库
（DWG / DGN / RVT）重建的依据。**结论 = 观察 + 推断 + 未知** 三态分离，每条结论
标注证据 ID（REA Evidence bundle，见 `evidence/`）与置信度。

## 决策记录

| 项 | 决定 |
|---|---|
| 优先级 | **DGN 深挖优先** → DWG（RVT 已迁出至同级 `go-rvt` 独立仓库） |
| 验证方式 | 先纯静态分析（暂无样例文件），样例后续补充 |
| 输出位置 | `/Users/xuning/Work/go-dgn/analysis/` |
| 分析对象 | `../ODA-Parse-DWGs-main/`（ODA Teigha 25.4 Windows x64 运行时 + 示例源码 + 全套头文件） |

## 目录

- `00-index/` — 证据索引、进度看板、术语表
- `01-oda-inventory/` — ODA 模块/头文件/示例程序盘点（分析的入口地图）
- `02-dwg/` — DWG 格式分析（第二阶段）
- `03-dgn/` — DGN 格式分析（**当前主线**）
- `04-rvt/` — 指引页（**RVT 已迁至同级 `go-rvt/` 独立仓库**，本项目不再混入）
- `05-go-design/` — Go 库架构设计（由格式分析结论驱动）
- `evidence/` — REA 导出的 Evidence bundle（`*.json`，含 ev_ 哈希 ID）

## 被分析物（原始事实）

- 路径：`/Users/xuning/Work/go-dgn/ODA-Parse-DWGs-main/`
- ODA 版本：25.4（`*​_25.4_lic16` 后缀；版权头 2002-2024）
- 平台：Windows x64 PE（PE32+ / mach=0x8664），非本机运行，**纯静态分析**
- 组成：
  - `ODA/bin/` — 287 个运行时模块（`.dll` / `.tx` / `.exe`）
  - `ODA/include/` — ~1500 个头文件（AcDb/Dg 完整对象模型）
  - `ODA/lib/` — MSVC 导入库
  - `DWGReadWriteOperator/` — 示例源码（DWG → JSON 导出器）
  - `ExServices/` — ODA 示例服务层源码
  - `JSON/` — jsoncpp 第三方库
- 关键：**无样例 .dwg/.dgn/.rvt 文件**

## 方法与证据约定

1. 三层证据源，置信度由高到低：
   - **E1 头文件源码**（ODA SDK `.h`）：对象模型、枚举值、类层次 — 观察级
   - **E2 二进制静态分析**（REA/Ghidra）：导出表、字符串、反编译 — 观察/推断级
   - **E3 领域知识**：公开格式规范（Open Design Specification、Bentley DGN 文档）、
     社区实现（libreDWG 等）交叉印证 — 推断级，必须显式标注
2. 每篇文档头部列出「结论 → 证据 → 置信度 → 未知」表。
3. ODA 代码为专有授权：分析产出用于**理解文件格式**（布局、字段、编解码算法），
   Go 重建不复刻其源码/命名结构。

## 证据 ID 引用方式

- REA 会话内 Evidence ID 形如 `ev_<64 hex>`；导出到 `evidence/*.json`。
- 本目录文档引用格式：`[ev_…]` 或 `E1/DgElement.h:135`（文件:行）。
