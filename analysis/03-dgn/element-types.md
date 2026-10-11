# DGN 元素类型码 与 ODA 类映射

**证据**

- 类型码：E1 `ODA/include/DgElement.h:135` `OdDgElement::ElementTypes`（枚举值 = 直接观察）
- 公开类↔文件层实现类：E2 `TG_Db.tx` RTTI `OdDgObjectWithImpl<Pub,Impl>` 模板  
  （`evidence/exports/TG_Db.tx.rtti.txt`，authority=shipped-artifact）
- 字节级含义须经反编译确认（见 `element-header.md`）

## 1. ElementTypes 枚举（类型码）

|   码 | 枚举名                              | 说明（按名推断）   |
| --: | -------------------------------- | ---------- |
|   0 | `kTypeUndefined`                 | 未定义        |
|   1 | `kTypeLibraryCellHeader`         | 库单元头       |
|   2 | `kTypeCellHeader`                | 单元头        |
|   3 | `kTypeLine`                      | 直线         |
|   4 | `kTypeLineString`                | 多段线        |
|   5 | `kTypeGroupData`                 | 组数据        |
|   6 | `kTypeShape`                     | 多边形        |
|   7 | `kTypeTextNode`                  | 多行文本       |
|   8 | `kTypeDigitizerDataSet`          | 数字化仪数据     |
|   9 | `kTypeDesignFileHeader`          | 设计文件头      |
|  10 | `kTypeLevelSymbology`            | 级别符号       |
|  11 | `kTypeCurve`                     | 曲线         |
|  12 | `kTypeComplexString`             | 复合文本串      |
|  13 | `kTypeConicSection`              | 二次曲线       |
|  14 | `kTypeComplexShape`              | 复合多边形      |
|  15 | `kTypeEllipse`                   | 椭圆         |
|  16 | `kTypeArc`                       | 圆弧         |
|  17 | `kTypeText`                      | 单行文本       |
|  18 | `kTypeSurface`                   | 曲面         |
|  19 | `kTypeSolid`                     | 实体         |
|  21 | `kTypeBSplinePoles`              | B样条控制点     |
|  22 | `kTypePointString`               | 点串         |
|  23 | `kTypeCone`                      | 圆锥         |
|  24 | `kTypeBSplineSurface`            | B样条曲面      |
|  25 | `kTypeBSplineSurfaceBoundary`    | B样条曲面边界    |
|  26 | `kTypeBSplineKnots`              | B样条节点      |
|  27 | `kTypeBSplineCurve`              | B样条曲线      |
|  28 | `kTypeBSplineWeights`            | B样条权重      |
|  33 | `kTypeDimension`                 | 标注         |
|  34 | `kTypeSharedCellDefinition`      | 共享单元定义     |
|  35 | `kTypeSharedCellReference`       | 共享单元引用     |
|  36 | `kTypeMultiline`                 | 多线         |
|  37 | `kTypeTagElement`                | 标签Tag      |
|  38 | `kTypeDgnStoreComponent`         | DgnStore组件 |
|  39 | `kTypeDgnStoreHeader`            | DgnStore头  |
|  66 | `kTypeApplicationData`           | 应用数据       |
|  87 | `kTypeRasterHeader`              | 栅格头        |
|  88 | `kTypeRasterComponent`           | 栅格组件       |
|  90 | `kTypeRasterAttachmentHeader`    | 栅格附件头      |
|  91 | `kTypeRasterAttachmentComponent` | 栅格附件组件     |
|  94 | `kTypeRasterFrame`               | 栅格框        |
|  95 | `kTypeTableEntry`                | 表条目        |
|  96 | `kTypeTableHeader`               | 表头         |
|  97 | `kTypeViewGroup`                 | 视图组        |
|  98 | `kTypeView`                      | 视图         |
|  99 | `kTypeLevelMask`                 | 级别掩码       |
| 100 | `kTypeReferenceAttachmentHeader` | 参照附件头XREF  |
| 101 | `kTypeMatrixHeader`              | 矩阵头        |
| 102 | `kTypeMatrixIntegerData`         | 整型矩阵数据     |
| 103 | `kTypeMatrixDoubleData`          | 双精度矩阵数据    |
| 105 | `kTypeMesh`                      | 网格         |
| 106 | `kTypeExtraGraphicsElement`      | 扩展图形元素     |
| 107 | `kTypeExtraNonGraphicsElement`   | 扩展非图形元素    |
| 108 | `kTypeReferenceOverride`         | 参照覆盖       |
| 110 | `kTypeNamedGroupHeader`          | 命名组头       |
| 111 | `kTypeNamedGroupComponent`       | 命名组组件      |
| 127 | `kTypeEOF`                       | EOF标记      |

注意：枚举缺 20、29-32、40-65、67-86、89、92-93、104、109、112-126 —— [未知] 是否保留/废弃，需二进制交叉验证。


## 2. 公开类 ↔ 文件层实现类（RTTI 实证）

`OdDgObjectWithImpl<Pub, Impl>`：文件层（遗留 DGN 库）类持有真实字节结构，公开 OdDg 类做包装。  
**Go 重建建议：按 Impl 侧建模文件结构，按 Pub 侧建模 API。**

| 公开类(OdDg后缀)                                  | 文件层实现类                                      |
| -------------------------------------------- | ------------------------------------------- |
| `DgACS`                                      | `OdDgACSImpl`                               |
| `DgAnnotationCellHeader2d`                   | `OdDgAnnotationCell2dImpl`                  |
| `DgAnnotationCellHeader3d`                   | `OdDgAnnotationCell3dImpl`                  |
| `DgApplicationData`                          | `OdDgApplicationDataImpl`                   |
| `DgArc2d`                                    | `EArc2D`                                    |
| `DgArc3d`                                    | `EArc3D`                                    |
| `DgArrowMarker2d`                            | `OdDgArrowMarker2dImpl`                     |
| `DgArrowMarker3d`                            | `OdDgArrowMarker3dImpl`                     |
| `DgAssocRegion2d`                            | `OdDgAssocRegion2dImpl`                     |
| `DgAssocRegion3d`                            | `OdDgAssocRegion3dImpl`                     |
| `DgBSplineBoundary`                          | `EBSurfBoundary`                            |
| `DgBSplineCurve2d`                           | `EBSpline2D`                                |
| `DgBSplineCurve3d`                           | `EBSpline3D`                                |
| `DgBSplineKnots`                             | `EBSplineKnots`                             |
| `DgBSplinePoles2d`                           | `EBSplinePoles2D`                           |
| `DgBSplinePoles3d`                           | `EBSplinePoles3D`                           |
| `DgBSplineSurface`                           | `OdDgBSplineSurfaceImpl`                    |
| `DgBSplineWeights`                           | `EBSplineWeights`                           |
| `DgCellHeader2d`                             | `ECell2D`                                   |
| `DgCellHeader3d`                             | `ECell3D`                                   |
| `DgColorBook`                                | `OdDgColorBookImpl`                         |
| `DgColorBookTable`                           | `OdDgColorBookTableImpl`                    |
| `DgColorTable`                               | `OdDgColorTableImpl`                        |
| `DgComplexProxyElement`                      | `CDGElementComplexUnknown`                  |
| `DgComplexProxyGraphicsElement`              | `CDGElementComplexUnknownGraphics`          |
| `DgComplexShape`                             | `EComplexShape`                             |
| `DgComplexString`                            | `EComplexString`                            |
| `DgCone`                                     | `ECone`                                     |
| `DgConic2d`                                  | `EConic2D`                                  |
| `DgConic3d`                                  | `EConic3D`                                  |
| `DgCurve2d`                                  | `ECurve2D`                                  |
| `DgCurve3d`                                  | `ECurve3D`                                  |
| `DgDesignFileHeader`                         | `EFileHeader`                               |
| `DgDetailMarker2d`                           | `OdDgDetailMarker2dImpl`                    |
| `DgDetailMarker3d`                           | `OdDgDetailMarker3dImpl`                    |
| `DgDgnStoreComponent`                        | `EDgnStoreComponent`                        |
| `DgDgnStoreHeader`                           | `OdDgDgnStoreHeaderImpl`                    |
| `DgDictionary`                               | `OdDgDictionaryImpl`                        |
| `DgDictionaryTable`                          | `OdDgDictionaryTableImpl`                   |
| `DgDictionaryTableRecord`                    | `OdDgDictionaryTableRecordImpl`             |
| `DgDimAngleAxisX`                            | `EDimAngleAxisX`                            |
| `DgDimAngleAxisY`                            | `EDimAngleAxisY`                            |
| `DgDimAngleLines`                            | `EDimAngleLines`                            |
| `DgDimAngleLocation`                         | `EDimAngleLocation`                         |
| `DgDimAngleSize`                             | `EDimAngleSize`                             |
| `DgDimArcLocation`                           | `EDimArcLocation`                           |
| `DgDimArcSize`                               | `EDimArcSize`                               |
| `DgDimCenter`                                | `EDimCenter`                                |
| `DgDimCustomLinear`                          | `EDimCustomLinear`                          |
| `DgDimDiameter`                              | `EDimDiameter`                              |
| `DgDimDiameterExtended`                      | `EDimDiameterExtended`                      |
| `DgDimDiameterParallel`                      | `EDimDiameterParallel`                      |
| `DgDimDiameterPerpendicular`                 | `EDimDiameterPerpendicular`                 |
| `DgDimLabelLine`                             | `EDimLabelLine`                             |
| `DgDimNote`                                  | `EDimNote`                                  |
| `DgDimOrdinate`                              | `EDimOrdinate`                              |
| `DgDimRadius`                                | `EDimRadius`                                |
| `DgDimRadiusExtended`                        | `EDimRadiusExtended`                        |
| `DgDimSingleLocation`                        | `EDimSingleLocation`                        |
| `DgDimSizeArrow`                             | `EDimSizeArrow`                             |
| `DgDimSizeStroke`                            | `EDimSizeStroke`                            |
| `DgDimStackedLocation`                       | `EDimStackedLocation`                       |
| `DgDimStyleTable`                            | `CDGDimStyleTable`                          |
| `DgDimStyleTableRecord`                      | `CDGDimStyle`                               |
| `DgDisplayStyleTable`                        | `OdDgDisplayStyleTableImpl`                 |
| `DgDisplayStyleTableRecord`                  | `OdDgDisplayStyleTableRecordImpl`           |
| `DgECSchema`                                 | `OdDgECSchemaImpl`                          |
| `DgElementIdPath`                            | `OdDgElementIdPathImpl`                     |
| `DgElementTemplate`                          | `OdDgElementTemplateImpl`                   |
| `DgElementTemplateTable`                     | `OdDgElementTemplateTableImpl`              |
| `DgEllipse2d`                                | `EEllipse2D`                                |
| `DgEllipse3d`                                | `EEllipse3D`                                |
| `DgEnvironmentMapTable`                      | `OdDgEnvironmentMapTableImpl`               |
| `DgExtendedGraphicsElement`                  | `OdDgExtendedGraphicsElementImpl`           |
| `DgFontTable`                                | `CDGFontTable`                              |
| `DgFontTableRecord`                          | `CDGFont`                                   |
| `DgGeoDataInfo`                              | `OdDgGeoDataInfoImpl`                       |
| `DgImageBackground`                          | `OdDgImageBackgroundImpl`                   |
| `DgItemTypeBasedVariable`                    | `OdDgItemTypeBasedVariableImpl`             |
| `DgItemTypeLibrary`                          | `OdDgItemTypeLibraryImpl`                   |
| `DgKMLPlacemark2d`                           | `OdDgKMLPlacemark2dImpl`                    |
| `DgKMLPlacemark3d`                           | `OdDgKMLPlacemark3dImpl`                    |
| `DgLevelFilterTable`                         | `OdDgLevelFilterTableImpl`                  |
| `DgLevelFilterTableRecord`                   | `OdDgLevelFilterTableRecordImpl`            |
| `DgLevelMask`                                | `OdDgLevelMaskImpl`                         |
| `DgLevelMaskIndexTable`                      | `OdDgLevelMaskIndexTableImpl`               |
| `DgLevelMaskIndexTableRecord`                | `OdDgLevelMaskIndexTableRecordImpl`         |
| `DgLevelTable`                               | `CDGLevelTable`                             |
| `DgLevelTableRecord`                         | `CDGLevel`                                  |
| `DgLightArea`                                | `OdDgLightAreaImpl`                         |
| `DgLightDistant`                             | `OdDgLightDistantImpl`                      |
| `DgLightOpenSky`                             | `OdDgLightOpenSkyImpl`                      |
| `DgLightPoint`                               | `OdDgLightPointImpl`                        |
| `DgLightSpot`                                | `OdDgLightSpotImpl`                         |
| `DgLine2d`                                   | `ELine2D`                                   |
| `DgLine3d`                                   | `ELine3D`                                   |
| `DgLineString2d`                             | `ELineString2D`                             |
| `DgLineString3d`                             | `ELineString3D`                             |
| `DgLineStyleDefTable`                        | `OdDgLineStyleDefTableImpl`                 |
| `DgLineStyleDefTableRecord`                  | `OdDgLineStyleDefTableRecordImpl`           |
| `DgLineStyleTable`                           | `OdDgLineStyleTableImpl`                    |
| `DgLineStyleTableRecord`                     | `OdDgLineStyleTableRecordImpl`              |
| `DgLinkSet`                                  | `OdDgLinkSetImpl`                           |
| `DgLinkSetTable`                             | `OdDgLinkSetTableImpl`                      |
| `DgMaterialTable`                            | `OdDgMaterialTableImpl`                     |
| `DgMaterialTableRecord`                      | `OdDgMaterialTableRecordImpl`               |
| `DgMatrixDoubleData`                         | `EMatrixDoubleData`                         |
| `DgMatrixHeader`                             | `EMatrixHeader`                             |
| `DgMatrixIntegerData`                        | `EMatrixIntData`                            |
| `DgMeshFaceLoops`                            | `EMeshHeader_FaceLoops`                     |
| `DgMeshPointCloud`                           | `EMeshHeader_PointCloud`                    |
| `DgMeshQuadGrid`                             | `EMeshHeader_QuadGrid`                      |
| `DgMeshQuadList`                             | `EMeshHeader_QuadList`                      |
| `DgMeshTriangleGrid`                         | `EMeshHeader_TriangleGrid`                  |
| `DgMeshTriangleList`                         | `EMeshHeader_TriangleList`                  |
| `DgModel`                                    | `CDGModel`                                  |
| `DgModelSheetDraw`                           | `OdDgModelSheetDrawImpl`                    |
| `DgModelTable`                               | `CDGModelsList`                             |
| `DgMultiline`                                | `EMultiLine`                                |
| `DgMultilineStyleTable`                      | `CDGMultiLineStyleTable`                    |
| `DgMultilineStyleTableRecord`                | `CDGMultiLineStyle`                         |
| `DgNamedGroupComponent`                      | `OdDgNamedGroupComponentImpl`               |
| `DgNamedGroupHeader`                         | `OdDgNamedGroupHeaderImpl`                  |
| `DgNamedViewTable`                           | `OdDgNamedViewTableImpl`                    |
| `DgNonModelElementCollection`                | `OdDgNonModelElementCollectionImpl`         |
| `DgOle2Frame2d`                              | `OdDgOle2Frame2dImpl`                       |
| `DgOle2Frame3d`                              | `OdDgOle2Frame3dImpl`                       |
| `DgPointString2d`                            | `EPointString2D`                            |
| `DgPointString3d`                            | `EPointString3D`                            |
| `DgPrintStyleTable`                          | `OdDgPrintStyleTableImpl`                   |
| `DgPrintStyleTableRecord`                    | `OdDgPrintStyleTableRecordImpl`             |
| `DgPrototypeElement`                         | `OdDgTablePrototypeImpl`                    |
| `DgPrototypeElementTable`                    | `OdDgPrototypeElementTableImpl`             |
| `DgProxyElement`                             | `CDGElementUnknown`                         |
| `DgProxyGraphicsElement`                     | `CDGElementUnknownGraphics`                 |
| `DgRasterAttachmentComponentBinary`          | `ERasterRefCompUnknown`                     |
| `DgRasterAttachmentComponentClip`            | `ERasterRefCompClip`                        |
| `DgRasterAttachmentComponentColorTable`      | `ERasterRefCompUnknown`                     |
| `DgRasterAttachmentComponentContinuous`      | `ERasterRefCompUnknown`                     |
| `DgRasterAttachmentComponentGeo`             | `ERasterRefCompGeo`                         |
| `DgRasterAttachmentComponentMask`            | `ERasterRefCompUnknown`                     |
| `DgRasterAttachmentComponentRGB`             | `ERasterRefCompUnknown`                     |
| `DgRasterAttachmentComponentRGBTransparency` | `ERasterRefCompRGBTransparency`             |
| `DgRasterAttachmentComponentRender`          | `ERasterRefCompRendering`                   |
| `DgRasterAttachmentComponentTransparency`    | `ERasterRefCompIndexTransparency`           |
| `DgRasterAttachmentHeader`                   | `ERasterReference`                          |
| `DgRasterComponent`                          | `ERasterComponent`                          |
| `DgRasterFrame`                              | `OdDgRasterFrameImpl`                       |
| `DgRasterHeader2d`                           | `ERasterHeader2D`                           |
| `DgRasterHeader3d`                           | `ERasterHeader3D`                           |
| `DgReferenceAttachmentHeader`                | `CDGReferenceElement`                       |
| `DgReferenceAttachmentLevelMaskGroup`        | `OdDgReferenceAttachmentLevelMaskGroupImpl` |
| `DgReferenceLayout`                          | `OdDgReferenceLayoutImpl`                   |
| `DgReferenceOrder`                           | `OdDgReferenceOrderImpl`                    |
| `DgReferenceOverride`                        | `OdDgReferenceOverrideImpl`                 |
| `DgRegAppTable`                              | `CDGRegAppTable`                            |
| `DgRegAppTableRecord`                        | `CDGRegApp`                                 |
| `DgSectionClip`                              | `OdDgSectionClipImpl`                       |
| `DgSectionMarker2d`                          | `OdDgSectionMarker2dImpl`                   |
| `DgSectionMarker3d`                          | `OdDgSectionMarker3dImpl`                   |
| `DgShape2d`                                  | `EShape2D`                                  |
| `DgShape3d`                                  | `EShape3D`                                  |
| `DgSharedCellDefinition`                     | `ESharedCellDef`                            |
| `DgSharedCellDefinitionTable`                | `CDGSharedCellList`                         |
| `DgSharedCellReference`                      | `ESharedCellInst`                           |
| `DgSheetModel`                               | `CDGModel`                                  |
| `DgSolid`                                    | `ESolid`                                    |
| `DgSurface`                                  | `ESurface`                                  |
| `DgTableElement`                             | `OdDgTableElementImpl`                      |
| `DgTagDefinitionSet`                         | `CDGAttribDefSet`                           |
| `DgTagDefinitionSetTable`                    | `CDGAttribDefTable`                         |
| `DgTagElement`                               | `EAttribute`                                |
| `DgTerrain`                                  | `OdDgTerrainImpl`                           |
| `DgTerrainControlElement`                    | `OdDgTerrainControlElementImpl`             |
| `DgText2d`                                   | `EText2D`                                   |
| `DgText3d`                                   | `EText3D`                                   |
| `DgTextNode2d`                               | `ETextNode2D`                               |
| `DgTextNode3d`                               | `ETextNode3D`                               |
| `DgTextStyleTable`                           | `CDGTextStyleTable`                         |
| `DgTextStyleTableRecord`                     | `CDGTextStyle`                              |
| `DgTextStyleTableRecordEx`                   | `CDGTextStyle`                              |
| `DgTitleText2d`                              | `OdDgTitleText2dImpl`                       |
| `DgTitleText3d`                              | `OdDgTitleText3dImpl`                       |
| `DgVariable`                                 | `OdDgLocalVariableImpl`                     |
| `DgVariableValuesSet`                        | `OdDgVariationSetImpl`                      |
| `DgVariablesList`                            | `OdDgLocalVariablesListImpl`                |
| `DgView`                                     | `CDGView`                                   |
| `DgViewGroup`                                | `CDGViewGroup`                              |
| `DgViewGroupTable`                           | `OdDgViewGroupTableImpl`                    |
| `DgWhiteMaterial`                            | `OdDgElementImpl`                           |
| `DgXMLCustomSchemaContainer`                 | `OdDgXMLCustomSchemaContainerImpl`          |
| `DgXMLSchemaContainer`                       | `OdDgItemTypeLibraryImpl`                   |

共 192 组映射（从 RTTI 提取；非 ObjectWithImpl 包装的类不在表内）。

## 3. 纯遗留类（文件层直接工作，无公开包装）

E2 RTTI/导出表实证：  
`CDGElmHeader`、`CDGElementGeneral`、`CDGDispHeader`、`CDGComplexGeneral`、`CDGModel`、  
`CDGLevelTable/CDGLevel`、`CDGFontTable/CDGFont`、`CDGTextStyleTable/CDGTextStyle`、  
`CDGView`、`CDGViewGroup`、`CDGRegAppTable/CDGRegApp`、`CDGSharedCellList`、  
`CDGAttribDefSet/Table`、`CDGModelsList`、`CDGReferenceElement`、  
`CDGElementUnknown(+Graphics)`、`CDGElementComplexUnknown(+Graphics)`、  
`CDGDimStyleTable/CDGDimStyle`、`CDGMultiLineStyleTable/CDGMultiLineStyle`。

`E*` 元素结构：`EFileHeader`、`ELine2D/3D`、`ELineString2D/3D`、`EArc2D/3D`、  
`EEllipse2D/3D`、`EShape2D/3D`、`EText2D/3D`、`ETextNode2D/3D`、`ECell2D/3D`、  
`EPointString2D/3D`、`EBSpline2D/3D`、`EBSplinePoles2D/3D`、`EBSplineKnots`、  
`EBSplineWeights`、`EConic2D/3D`、`ECurve2D/3D`、`ESolid`、`ESurface`、`ECone`、  
`EComplexString`、`EComplexShape`、`EMultiLine`、`EAttribute`(Tag)、  
`ESharedCellDef/Inst`、`EMatrixHeader/IntData/DoubleData`、  
`EMeshHeader_QuadGrid/TriangleGrid/QuadList/TriangleList/PointCloud/FaceLoops`、  
`ERasterHeader2D/3D`、`ERasterComponent`、`ERasterReference`、`ERasterRefComp*`、  
`EDgnStoreComponent`、`CDGDim*`（标注族）。

来源：`evidence/exports/TG_Db.tx.rtti.txt`、`*.exports.txt`；交叉引用见 `findings.md`。
