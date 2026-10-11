/* ==== 1800080f0 GetAttribSizeFromHeader ==== */

/* public: unsigned long const __cdecl CDGElmHeader::GetAttribSizeFromHeader(void)const __ptr64 */

ulong __thiscall CDGElmHeader::GetAttribSizeFromHeader(CDGElmHeader *this)

{
                    /* 0x80f0  3993  ?GetAttribSizeFromHeader@CDGElmHeader@@QEBA?BKXZ
                       0x80f0  11976  ?getLinkageDataSize@CDGDispHeader@@QEBAKXZ */
  return (*(int *)(this + 0x14) - *(int *)(this + 0x18)) * 2;
}



/* ==== 1800083a0 GetElementDeletedByComplexHeader ==== */

/* public: virtual enum Dgn8::Bool const __cdecl
   CDGElmHeader::GetElementDeletedByComplexHeader(void) __ptr64 */

Bool __thiscall CDGElmHeader::GetElementDeletedByComplexHeader(CDGElmHeader *this)

{
                    /* 0x83a0  4014
                       ?GetElementDeletedByComplexHeader@CDGElmHeader@@UEAA?BW4Bool@Dgn8@@XZ
                       0x83a0  4453
                       ?appNameCallbackPtr@OdDgProxyClass@@QEBAP6AXPEBVOdRxClass@@AEAVOdString@@H@ZXZ
                       0x83a0  4510
                       ?background@OdDgAbstractViewPE@@UEBAPEAVOdDbStub@@PEBVOdRxObject@@@Z
                       0x83a0  6585  ?customFlags@OdDgProxyClass@@QEBAKXZ
                       0x83a0  6601
                       ?defaultLineWeight@OdGiContextForDgDatabase@@UEBA?AW4LineWeight@OdDb@@XZ
                       0x83a0  7879  ?dimensionType@OdDgDimension@@UEBA?AW4ToolType@1@XZ
                       0x83a0  7963  ?filerType@OdDgFileFiler@@UEBA?AW4FilerType@OdDgFiler@@XZ
                       0x83a0  9855  ?getController@OdDgFiler@@UEBAPEAVOdDgFilerController@@XZ
                       0x83a0  9962
                       ?getDbHostAppServices@OdDgHostAppServices@@UEBAPEAVOdDbBaseHostAppServices@@XZ
                       0x83a0  10711  ?getElementType@OdDgElement@@UEBA?AW4ElementTypes@1@XZ
                       0x83a0  11119
                       ?getFirstTerminator@OdDgDimToolAngleLines@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11120
                       ?getFirstTerminator@OdDgDimToolAngleSize@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11121
                       ?getFirstTerminator@OdDgDimToolArcSize@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11122
                       ?getFirstTerminator@OdDgDimToolCenter@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11123
                       ?getFirstTerminator@OdDgDimToolDiameter@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11124
                       ?getFirstTerminator@OdDgDimToolDiameterExtended@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11125
                       ?getFirstTerminator@OdDgDimToolDiameterParallel@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11126
                       ?getFirstTerminator@OdDgDimToolLabelLine@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11127
                       ?getFirstTerminator@OdDgDimToolNote@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11128
                       ?getFirstTerminator@OdDgDimToolOrdinate@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11129
                       ?getFirstTerminator@OdDgDimToolPerpendicular@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11130
                       ?getFirstTerminator@OdDgDimToolRadius@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11131
                       ?getFirstTerminator@OdDgDimToolRadiusExtended@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11623
                       ?getJointTerminator@OdDgDimToolAngleAxis@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11624
                       ?getJointTerminator@OdDgDimToolAngleLines@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11625
                       ?getJointTerminator@OdDgDimToolAngleLocation@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11626
                       ?getJointTerminator@OdDgDimToolAngleSize@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11627
                       ?getJointTerminator@OdDgDimToolArcLocation@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11628
                       ?getJointTerminator@OdDgDimToolArcSize@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11629
                       ?getJointTerminator@OdDgDimToolCenter@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11630
                       ?getJointTerminator@OdDgDimToolDiameter@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11631
                       ?getJointTerminator@OdDgDimToolDiameterExtended@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11632
                       ?getJointTerminator@OdDgDimToolDiameterParallel@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11633
                       ?getJointTerminator@OdDgDimToolLabelLine@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11634
                       ?getJointTerminator@OdDgDimToolNote@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11635
                       ?getJointTerminator@OdDgDimToolOrdinate@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11636
                       ?getJointTerminator@OdDgDimToolPerpendicular@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11637
                       ?getJointTerminator@OdDgDimToolRadius@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11638
                       ?getJointTerminator@OdDgDimToolRadiusExtended@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11708
                       ?getLeader@OdDgDimToolAngleAxis@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11709
                       ?getLeader@OdDgDimToolAngleLines@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11710
                       ?getLeader@OdDgDimToolAngleLocation@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11711
                       ?getLeader@OdDgDimToolAngleSize@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11712
                       ?getLeader@OdDgDimToolArcLocation@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11713  ?getLeader@OdDgDimToolArcSize@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11714  ?getLeader@OdDgDimToolCenter@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11715
                       ?getLeader@OdDgDimToolCustomLinear@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11716
                       ?getLeader@OdDgDimToolDiameterParallel@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11717
                       ?getLeader@OdDgDimToolLabelLine@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11718  ?getLeader@OdDgDimToolNote@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11719  ?getLeader@OdDgDimToolOrdinate@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11720
                       ?getLeader@OdDgDimToolPerpendicular@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11721
                       ?getLeader@OdDgDimToolSingleLocation@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11722
                       ?getLeader@OdDgDimToolSizeArrow@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11723
                       ?getLeader@OdDgDimToolSizeStroke@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11724
                       ?getLeader@OdDgDimToolStackedLocation@@EEBA?AW4Leader@OdDgDimTool@@XZ
                       0x83a0  11778
                       ?getLeftTerminator@OdDgDimToolCenter@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11779
                       ?getLeftTerminator@OdDgDimToolDiameter@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11780
                       ?getLeftTerminator@OdDgDimToolDiameterExtended@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11781
                       ?getLeftTerminator@OdDgDimToolLabelLine@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11782
                       ?getLeftTerminator@OdDgDimToolNote@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11783
                       ?getLeftTerminator@OdDgDimToolOrdinate@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11784
                       ?getLeftTerminator@OdDgDimToolRadius@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  11785
                       ?getLeftTerminator@OdDgDimToolRadiusExtended@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  12718
                       ?getPrefix@OdDgDimToolCenter@@EEBA?AW4CustomSymbol@OdDgDimTool@@XZ
                       0x83a0  12719
                       ?getPrefix@OdDgDimToolLabelLine@@EEBA?AW4CustomSymbol@OdDgDimTool@@XZ
                       0x83a0  12720
                       ?getPrefix@OdDgDimToolNote@@EEBA?AW4CustomSymbol@OdDgDimTool@@XZ
                       0x83a0  12721
                       ?getPrefix@OdDgDimToolOrdinate@@EEBA?AW4CustomSymbol@OdDgDimTool@@XZ
                       0x83a0  13035
                       ?getRightTerminator@OdDgDimToolCenter@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  13036
                       ?getRightTerminator@OdDgDimToolLabelLine@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  13037
                       ?getRightTerminator@OdDgDimToolNote@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  13038
                       ?getRightTerminator@OdDgDimToolOrdinate@@EEBA?AW4TerminatorType@OdDgDimTool@@XZ
                       0x83a0  13602
                       ?getSuffix@OdDgDimToolCenter@@EEBA?AW4CustomSymbol@OdDgDimTool@@XZ
                       0x83a0  13603
                       ?getSuffix@OdDgDimToolLabelLine@@EEBA?AW4CustomSymbol@OdDgDimTool@@XZ
                       0x83a0  13604
                       ?getSuffix@OdDgDimToolNote@@EEBA?AW4CustomSymbol@OdDgDimTool@@XZ
                       0x83a0  13605
                       ?getSuffix@OdDgDimToolOrdinate@@EEBA?AW4CustomSymbol@OdDgDimTool@@XZ
                       0x83a0  13782
                       ?getTextType@OdDgDimToolAngleAxis@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13783
                       ?getTextType@OdDgDimToolAngleLines@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13784
                       ?getTextType@OdDgDimToolAngleLocation@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13785
                       ?getTextType@OdDgDimToolAngleSize@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13786
                       ?getTextType@OdDgDimToolArcLocation@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13787
                       ?getTextType@OdDgDimToolArcSize@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13788
                       ?getTextType@OdDgDimToolCenter@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13789
                       ?getTextType@OdDgDimToolDiameter@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13790
                       ?getTextType@OdDgDimToolDiameterExtended@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13791
                       ?getTextType@OdDgDimToolDiameterParallel@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13792
                       ?getTextType@OdDgDimToolLabelLine@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13793  ?getTextType@OdDgDimToolNote@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13794
                       ?getTextType@OdDgDimToolOrdinate@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13795
                       ?getTextType@OdDgDimToolPerpendicular@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13796
                       ?getTextType@OdDgDimToolRadius@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13797
                       ?getTextType@OdDgDimToolRadiusExtended@@EEBA?AW4TextType@OdDgDimTool@@XZ
                       0x83a0  13947
                       ?getType@OdDgMeshAuxiliaryData_Normal@@QEBA?AW4DataTypes@OdDgMeshAuxiliaryData@@XZ
                       0x83a0  13963
                       ?getType@OdDgUnknownAssociation@@UEBA?AW4OdDgAssocPointRootType@OdDgAssocPointRoot@@XZ
                       0x83a0  14490
                       ?hatchAsPolygon@OdGiContextForDgDatabase@@UEBA?AW4SolidHatchAsPolygonMode@OdGiDefaultContext@@XZ
                       0x83a0  16008  ?module@OdDgProxyClass@@QEBAPEAVOdRxModule@@XZ
                       0x83a0  16133
                       ?plotStyleType@OdGiContextForDgDatabase@@UEBA?AW4PStyleType@OdGiContext@@XZ
                       0x83a0  24671  ?subClose@OdDgElement@@UEAA?AW4OdResult@@XZ
                       0x83a0  24907  ?subErase@OdDgElement@@UEAA?AW4OdResult@@_N@Z
                       0x83a0  25058
                       ?subGetGeomExtents@OdDgTerrainControlElement@@UEBA?AW4OdResult@@AEAVOdGeExtents3d@@@Z
                       0x83a0  25059
                       ?subGetGeomExtents@OdDgTerrainControlElement@@UEBA?AW4OdResult@@KAEAVOdGeExtents3d@@@Z
                       0x83a0  25099  ?subOpen@OdDgElement@@UEAA?AW4OdResult@@W4OpenMode@OdDg@@@Z
                       0x83a0  25116
                       ?subSetAttributes@OdDgDatabase@@UEBAKPEAVOdGiDrawableTraits@@@Z
                       0x83a0  25120  ?subSetAttributes@OdDgElement@@UEBAKPEAVOdGiDrawableTraits@@@Z
                       0x83a0  25520  ?subentCount@OdDgSelectionSet@@UEBAKAEBVOdDgElementId@@@Z */
  return 0;
}



/* ==== 180008630 GetHeaderPtr ==== */

/* public: class Dgn8::SElementHeader const * __ptr64 __cdecl CDGElmHeader::GetHeaderPtr(void)const
   __ptr64 */

SElementHeader * __thiscall CDGElmHeader::GetHeaderPtr(CDGElmHeader *this)

{
                    /* 0x8630  4025  ?GetHeaderPtr@CDGElmHeader@@QEBAPEBVSElementHeader@Dgn8@@XZ
                       0x8630  12575
                       ?getPath@OdDgNamedGroupItem@@QEBAAEBV?$OdArray@_KV?$OdObjectsAllocator@_K@@@@XZ
                       0x8630  13655
                       ?getSymbology@OdDgMultilineProfile@@QEBAAEBVOdDgMultilineSymbology@@XZ
                       0x8630  25521  ?subentId@OdDgFullSubentPath@@QEAAAEAVOdDbSubentId@@XZ
                       0x8630  25525
                       ?symbology@OdDgMultilineProfile@@QEAAAEAVOdDgMultilineSymbology@@XZ */
  return (SElementHeader *)(this + 8);
}



/* ==== 1808b39a0 GetLocked ==== */

/* public: virtual enum Dgn8::Bool const __cdecl CDGElmHeader::GetLocked(void)const __ptr64 */

Bool __thiscall CDGElmHeader::GetLocked(CDGElmHeader *this)

{
                    /* 0x8b39a0  4031  ?GetLocked@CDGElmHeader@@UEBA?BW4Bool@Dgn8@@XZ */
  return *(ushort *)(this + 0x10) >> 0xb & 1;
}



/* ==== 1808b39b0 GetNonModel ==== */

/* public: virtual enum Dgn8::Bool const __cdecl CDGElmHeader::GetNonModel(void)const __ptr64 */

Bool __thiscall CDGElmHeader::GetNonModel(CDGElmHeader *this)

{
                    /* 0x8b39b0  4037  ?GetNonModel@CDGElmHeader@@UEBA?BW4Bool@Dgn8@@XZ */
  return *(ushort *)(this + 0x10) >> 10 & 1;
}



