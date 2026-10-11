# ODA Teigha 25.4 模块地图（格式解析相关）

证据来源：

- E1 `ODA/include/OdModuleNames.h`（模块名宏定义，文件:行）
- E2 PE 导出表/RTTI 提取 → `analysis/evidence/exports/*.exports.txt`、`*.rtti.txt`  
  （由 PE 头解析脚本生成，authority=shipped-artifact，脚本见本次会话）
- E2 REA Evidence：`[ev_bbef6520…]`（TG_Dgn7IO Ghidra 分析）

## 与 DWG/DGN 解析直接相关的模块

| 模块                 | 大小      | 导出数       | RTTI 类数  | 职责（推断依据）                                                                                                                                                                                      |
| ------------------ | ------- | --------- | -------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| `TD_DbIO.tx`       | 1.4 MB  | 863       | 236      | **DWG/DXF 文件 I/O**。导出类含 `OdDwgFileController`、`OdDwgFileLoader`、`OdDwgR18FileController/Header/Section`、`OdDwgR21FileSplitStream`、`OdDwgR24FileLoader`、`OdDwgFileWriter`（E2 exports）          |
| `TD_DbCore.dll`    | 5.4 MB  | 10132     | 800      | DWG 对象模型核心 + **DWG 版本魔数 AC1014/AC1015/AC1018/AC1021/AC1024/AC1027/AC1032**（strings 命中 7 处，E2）                                                                                                 |
| `TD_DbEntities.tx` | 6.7 MB  | 8070      | 976      | 全部 DWG 实体类（后续 DWG 实体编解码主目标）                                                                                                                                                                   |
| `TD_DbRoot.dll`    | 1.0 MB  | 1685      | 0        | 字符串/句柄/基础类型（OdStringBuf、OdSSet…）                                                                                                                                                              |
| `TG_Db.tx`         | 17.8 MB | **25962** | **4075** | **DGN 数据库 + DGN 文件读取核心**（E1: Dg*.h 每个头都标 "Corresponding C++ library: TG_Db"）。含 `OdDgDatabase::readFile/writeFile`、`OdDgFiler/OdDgFileFiler` 编解码接口、`CDG*`/`E*` 遗留文件结构类、`Dgn8LoadResolver` RTTI |
| `TG_Dgn7IO.tx`     | 610 KB  | 2         | 145      | **DGN v7 读取与 v7→v8 转换**（RTTI: `OdDgConvertV7ToV8Thread`、`I_dgMicroStationTCB`、`CIsffMicroStationTCB`；E1: `OdDgn7IOModuleName="TG_Dgn7IO"`）                                                    |
| `TD_DgnDb.tx`      | 282 KB  | 2         | 68       | DGN 数据库扩展模块（薄壳）                                                                                                                                                                               |
| `ExDgnDumper.tx`   | —       | 4510      | 599      | DGN 数据库转储工具（元素类型枚举/字段名的交叉证据源）                                                                                                                                                                 |
| `DwgModule.tx`     | 210 KB  | 2         | 44       | DWG 应用模块（命令/服务挂钩）                                                                                                                                                                             |
| `TG_DwgDb.tx`      | 1.1 MB  | 3038      | 439      | 名称误导：导出以 OdDg 类为主（OdDg 4826 字符命中 vs OdDb 441）。**待深挖**：可能是 DGN/DWG 共享的 filer 支持层（含 `OdDgFilerController`、`Dgn8` 命名空间 `Error@Dgn8`、`DWGHatchLine`）                                              |

## 其他（与本项目弱相关）

- DWG→DGN/DWF/IFC/STEP 互转：`TD_DgnImport/TD_DgnExport/TD_Dwf7Export/ExDwgIfc/ExDwgStep`
- 可视化（TV\_*）、渲染、BREP（TD_Br、TD_BrepBuilder）、PDF/PRC：不进入第一阶段范围
- **RVT：全包无 Revit 读写模块**（grep revit/rvt 于 bin+include 无命中；仅有 `TD_BimDb`、IFC/STEP 相关）→ 见 `04-rvt/`

## 关键导出（解析入口点，均已确认存在于导出表）

```
OdDgDatabase::readFile(OdString, FileShareMode, bool)          # TG_Db
OdDgDatabase::readFile(OdSmartPtr<OdStreamBuf>, FileShareMode, bool)
OdDgDatabase::readFromStream / writeFile / writeToStream
OdDgHostAppServices::readFile -> OdSmartPtr<OdDgDatabase>
OdDgElement::dgnIn(OdDgFiler*) / dgnInFields(OdDgFiler*) / dgnOut / dgnOutFields
OdDgModel::dgnIn(OdDgFiler*) / dgnOut
OdDgFileFiler::rd*/wr*  （完整编解码原语，见 03-dgn/filer-api.md）
```

## 运行时模块装载机制（对 Go 重建无直接影响，仅作背景）

- 每个 `.tx`/`.dll` 只导出 `odrxCreateModuleObject` + `odrxGetAPIVersion`（除被静态标记导出的类实现模块），  
  经 `odrxDynamicLinker` 按 `OdModuleNames.h` 注册（E2：全部模块导出表核对）。
