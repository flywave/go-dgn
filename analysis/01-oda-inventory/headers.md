# 01-oda-inventory — 头文件索引（格式相关子集）

完整头文件树：`ODA-Parse-DWGs-main/ODA/include/`（~1500 个 .h）。与解析库相关的：

## DGN（第一阶段核心，对应库 TG_Db）

| 头文件 | 内容 | 用途 |
|---|---|---|
| `DgElement.h` | `OdDgElement::ElementTypes` 枚举（:135）、元素基类 API | 类型码表（已提取→`03-dgn/element-types.md`） |
| `DgFiler.h` | `OdDgFiler` 接口 + `FilerType` 枚举（:51）+ rd*/wr* 声明 | filer-api.md |
| `DgCommonStructs.h` | `OdAngleCoordinate`、`OdDgLightColor`、`OdRange3d`(i64 UOR) | 基础类型 |
| `DgLineString.h / DgLine.h / DgArc.h / DgShape.h / DgText*.h …` | 各元素公开类 | 元素体字段命名参照 |
| `DgCellHeader.h` | 单元头（block/cell）公开类 | |
| `DgDatabase.h` | `OdDgDatabase::readFile/writeFile` 等 | 入口 API |
| `DgLevelTableRecord.h / DgFontTableRecord.h / DgTextStyleTableRecord.h …` | 表记录字段 | table 层 |
| `DgAttributeLinkage.h / DgXAttribute.h` | linkage/XAttribute 公开模型 | linkage 层 |
| `DgMacros.h / DgExport.h` | ODDG_DECLARE_MEMBERS 等宏（影响虚表结构理解） | |

## DWG（第二阶段）

`DbFiler.h`（DWG 侧 FilerType + dwgIn/dwgOut）、`DbObject.h`、`DbEntity.h`、
`DbLine.h`…、`DbDatabase.h`、`DwgClassDef.h`（类定义/代理对象）、`DbHandle.h`。

## 通用

`OdStreamBuf.h`（流抽象）、`OdPlatformStreamer.h`（端序/位流辅助）、
`OdModuleNames.h`（模块名→文件映射，:27-95）、`TDVersion.h/TGVersion.h`（版本）。

## 用法提示

- 每个 Dg/Db 头的注释都标注 `Corresponding C++ library: TG_Db / TD_DbCore …`
  → 反查"某类在哪个二进制"的权威来源。
- 类层次中的 `ODDG_DECLARE_MEMBERS` / `TG_EXPORT` 宏决定导出与虚表布局。
