/* ==== 180008640 GetLevelID ==== */

/* public: virtual unsigned long const __cdecl CDGElementGeneral::GetLevelID(void)const __ptr64 */

ulong __thiscall CDGElementGeneral::GetLevelID(CDGElementGeneral *this)

{
                    /* 0x8640  4028  ?GetLevelID@CDGElementGeneral@@UEBA?BKXZ
                       0x8640  11802  ?getLevelEntryId@CDGElementGeneral@@UEBAKXZ
                       0x8640  11889
                       ?getLineSpacingType@OdDgTextStyleDataXAttributeImpl@@UEBA?AW4LineSpacingType@OdDgTextExtendedProperties@@XZ
                       0x8640  12076  ?getMaxIterations@OdDgLineCodeResource@@QEBAKXZ */
  return *(ulong *)(this + 0xcc);
}



/* ==== 180008f30 SetElementLevelID ==== */

/* public: virtual void __cdecl CDGElmHeader::SetElementLevelID(unsigned long) __ptr64 */

void __thiscall CDGElmHeader::SetElementLevelID(CDGElmHeader *this,ulong param_1)

{
                    /* 0x8f30  4124  ?SetElementLevelID@CDGElmHeader@@UEAAXK@Z
                       0x8f30  21587
                       ?setECSchemaSubVersion@OdDgECRelationshipXAttributeImpl@@UEAAXK@Z
                       0x8f30  22831
                       ?setNumberOfEdgeRecords@OdDgTerrainInfoXAttributeImpl@@UEAAXK@Z
                       0x8f30  23737  ?setSkyColor@OdDgEnvMapGradient@@QEAAXK@Z
                       0x8f30  24578  ?setWordHeadingStyle@OdDgWordHeadingInfoItem@@QEAAXK@Z */
  *(ulong *)(this + 0x1c) = param_1;
  return;
}



/* ==== 180008f50 SetLevelID ==== */

/* public: virtual void __cdecl CDGElementGeneral::SetLevelID(unsigned long) __ptr64 */

void __thiscall CDGElementGeneral::SetLevelID(CDGElementGeneral *this,ulong param_1)

{
                    /* 0x8f50  4135  ?SetLevelID@CDGElementGeneral@@UEAAXK@Z */
                    /* WARNING: Could not recover jumptable at 0x000180008f5a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(longlong *)(this + 0xb0) + 0x40))();
  return;
}



