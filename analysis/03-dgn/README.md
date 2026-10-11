# DGN 格式分析（主线）

## 目标

为纯 Go DGN 解析库提供可实现级（implementation-ready）的格式说明：  
文件结构 → 元素头 → 类型分发 → 各元素体 → linkage/XAttribute → 表（level/style/font…）。

## 证据源优先级

1. E1 ODA 头文件（`Dg*.h`，`ODA/include/`）— 对象模型与枚举
2. E2 `TG_Db.tx` 静态反汇编/反编译（Ghidra 12.1.4；导出表 25962 个已命名函数 + RTTI 4075 类）
3. E3 公开知识交叉印证：Bentley DGN v8 结构（Element Header/Linkage 概念、MicroStation TCB）、  
   社区实现；**凡仅有 E3 支撑的结论必须标 [推断]**

## 文档索引

| 文件                  | 内容                                       | 状态                           |
| ------------------- | ---------------------------------------- | ---------------------------- |
| `element-types.md`  | 元素类型码表 + ODA 类 ↔ 文件层实现类映射                | ✅ E1+E2                      |
| `filer-api.md`      | 序列化原语（rd\*/wr\*）与 dgnIn/dgnOut 约定        | ✅ E2                         |
| `load-pipeline.md`  | **第2轮**：chunk 容器、单元素解码/回写、虚表槽位           | ✅ E2                         |
| `directory.md`      | **第3轮**：u32 偏移目录、odDgnClassMap 类型分发、过滤规则 | ✅ E2                         |
| `file-structure.md` | 文件级结构（头/区段/元素流）                          | 🚧 已按 load-pipeline 校正       |
| `element-header.md` | 元素头字节布局                                  | ✅ 静态推断（待样例验证）                |
| `linkages.md`       | Linkage/XAttribute 表                     | 📋 类清单已获取，dgnInLinkages 待反编译 |
| `v7-format.md`      | DGN v7（TG_Dgn7IO + TCB）                  | ⬜ 第二批                        |
| `findings.md`       | 结论台账（结论→证据→置信度→未知）                       | 🚧 持续更新                      |

## 当前关键观察（摘要）

- **`TG_Db.tx` 是 DGN 格式的核心**：`OdDgDatabase::readFile` 入口、`OdDgFiler` 编解码原语、  
  全部元素类均在其中（E2 exports）。
- ODA 的 DGN 读写采用 **虚函数 `dgnIn/dgnInFields(OdDgFiler*)`** 按元素类型分发（E2：OdDgElement 导出）。
- 公开类（`OdDgLine2d`…）由**遗留文件层类**实现：`ELine2D/EArc2D/EFileHeader/CDGModel…`  
  （E2 RTTI `OdDgObjectWithImpl<Public, Impl>` 模板全量映射，见 element-types.md）。
- DGN v7 独立在 `TG_Dgn7IO.tx`（v7→v8 转换线程 + MicroStation TCB 类）（E2 RTTI；[ev_bbef6520…]）。
- RVT 与本 ODA 包无关 → `../04-rvt/`。
