/* ==== 180008350 GetClass ==== */

/* public: virtual enum OdDgGraphicsElement::Class const __cdecl
   CDGElementGeneral::GetClass(void)const __ptr64 */

Class __thiscall CDGElementGeneral::GetClass(CDGElementGeneral *this)

{
  Class CVar1;
  
                    /* 0x8350  4004
                       ?GetClass@CDGElementGeneral@@UEBA?BW4Class@OdDgGraphicsElement@@XZ
                       0x8350  9674
                       ?getClass@CDGElementGeneral@@UEBA?AW4Class@OdDgGraphicsElement@@XZ */
                    /* WARNING: Could not recover jumptable at 0x00018000835a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CVar1 = (**(code **)(*(longlong *)(this + 0xb0) + 0xa8))();
  return CVar1;
}



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



/* ==== 1800112f0 get3dFormatFlag ==== */

/* public: bool __cdecl CDGDispHeader::get3dFormatFlag(void)const __ptr64 */

bool __thiscall CDGDispHeader::get3dFormatFlag(CDGDispHeader *this)

{
                    /* 0x112f0  8917  ?get3dFormatFlag@CDGDispHeader@@QEBA_NXZ */
  if (*(longlong *)(this + 0x30) != 0) {
    return (bool)((byte)((ushort)*(undefined2 *)(*(longlong *)(this + 0x30) + 8) >> 0xb) & 1);
  }
  return true;
}



/* ==== 18011b590 get3dFormatFlag ==== */

/* public: virtual bool __cdecl CDGElementGeneral::get3dFormatFlag(void)const __ptr64 */

bool __thiscall CDGElementGeneral::get3dFormatFlag(CDGElementGeneral *this)

{
                    /* 0x11b590  8918  ?get3dFormatFlag@CDGElementGeneral@@UEBA_NXZ */
  if (*(longlong *)(this + 0xe0) != 0) {
    return (bool)((byte)((ushort)*(undefined2 *)(*(longlong *)(this + 0xe0) + 8) >> 0xb) & 1);
  }
  return true;
}



/* ==== 18011b6f0 getDisplayStyleEntryId ==== */

/* public: virtual long __cdecl CDGElementGeneral::getDisplayStyleEntryId(void)const __ptr64 */

long __thiscall CDGElementGeneral::getDisplayStyleEntryId(CDGElementGeneral *this)

{
                    /* 0x11b6f0  10300  ?getDisplayStyleEntryId@CDGElementGeneral@@UEBAJXZ */
  return *(long *)(this + 0x178);
}



/* ==== 18011c7d0 getElmFillColor ==== */

/* public: virtual unsigned long __cdecl CDGElementGeneral::getElmFillColor(void)const __ptr64 */

ulong __thiscall CDGElementGeneral::getElmFillColor(CDGElementGeneral *this)

{
                    /* 0x11c7d0  10856  ?getElmFillColor@CDGElementGeneral@@UEBAKXZ */
  return *(ulong *)(this + 400);
}



/* ==== 18011c7f0 getErasingFlag ==== */

/* public: virtual bool __cdecl CDGElementGeneral::getErasingFlag(void)const __ptr64 */

bool __thiscall CDGElementGeneral::getErasingFlag(CDGElementGeneral *this)

{
                    /* 0x11c7f0  10927  ?getErasingFlag@CDGElementGeneral@@UEBA_NXZ */
  return (bool)this[0x201];
}



/* ==== 18011c810 getFillType ==== */

/* public: virtual enum OdDg::OdDgElementFillType __cdecl CDGElementGeneral::getFillType(void)const
   __ptr64 */

OdDgElementFillType __thiscall CDGElementGeneral::getFillType(CDGElementGeneral *this)

{
                    /* 0x11c810  11070
                       ?getFillType@CDGElementGeneral@@UEBA?AW4OdDgElementFillType@OdDg@@XZ */
  return *(OdDgElementFillType *)(this + 0x18c);
}



/* ==== 1802c2550 get3dFormatFlag ==== */

/* public: virtual bool __cdecl OdDgGraphicsElement::get3dFormatFlag(void)const __ptr64 */

bool __thiscall OdDgGraphicsElement::get3dFormatFlag(OdDgGraphicsElement *this)

{
  bool bVar1;
  longlong *plVar2;
  
                    /* 0x2c2550  8919  ?get3dFormatFlag@OdDgGraphicsElement@@UEBA_NXZ */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGElementGeneral::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001802c257f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar1 = (bool)(**(code **)(*plVar2 + 0x580))(plVar2);
  return bVar1;
}



/* ==== 1802c25f0 getClass ==== */

/* public: virtual enum OdDgGraphicsElement::Class __cdecl OdDgGraphicsElement::getClass(void)const
   __ptr64 */

Class __thiscall OdDgGraphicsElement::getClass(OdDgGraphicsElement *this)

{
  Class CVar1;
  longlong *plVar2;
  
                    /* 0x2c25f0  9678  ?getClass@OdDgGraphicsElement@@UEBA?AW4Class@1@XZ */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGElementGeneral::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001802c261f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  CVar1 = (**(code **)(*plVar2 + 0x4d0))(plVar2);
  return CVar1;
}



/* ==== 1802c2a70 getFillType ==== */

/* public: virtual enum OdDg::OdDgElementFillType __cdecl
   OdDgGraphicsElement::getFillType(void)const __ptr64 */

OdDgElementFillType __thiscall OdDgGraphicsElement::getFillType(OdDgGraphicsElement *this)

{
  OdDgElementFillType OVar1;
  longlong *plVar2;
  
                    /* 0x2c2a70  11071
                       ?getFillType@OdDgGraphicsElement@@UEBA?AW4OdDgElementFillType@OdDg@@XZ */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGElementGeneral::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001802c2a9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  OVar1 = (**(code **)(*plVar2 + 1000))(plVar2);
  return OVar1;
}



/* ==== 1805dd070 getClass ==== */

/* public: enum OdDgGraphicsElement::Class __cdecl OdDgModel::getClass(void)const __ptr64 */

Class __thiscall OdDgModel::getClass(OdDgModel *this)

{
  longlong lVar1;
  
                    /* 0x5dd070  9679  ?getClass@OdDgModel@@QEBA?AW4Class@OdDgGraphicsElement@@XZ */
  lVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &CDGModel::RTTI_Type_Descriptor,0);
  return *(ushort *)(lVar1 + 0x12b2) & 0xf;
}



/* ==== 18076c3c0 getClass ==== */

/* public: virtual class OdSmartPtr<class OdDgECClass> __cdecl OdDgECSchema::getClass(class OdString
   const & __ptr64)const __ptr64 */

OdString * __thiscall OdDgECSchema::getClass(OdDgECSchema *this,OdString *param_1)

{
  longlong *plVar1;
  
                    /* 0x76c3c0  9675
                       ?getClass@OdDgECSchema@@UEBA?AV?$OdSmartPtr@VOdDgECClass@@@@AEBVOdString@@@Z
                        */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgECSchemaImpl::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x7b0))(plVar1,param_1);
  return param_1;
}



/* ==== 18076c420 getClass ==== */

/* public: virtual class OdSmartPtr<class OdDgECClass> __cdecl OdDgECSchema::getClass(unsigned
   long)const __ptr64 */

undefined8 __thiscall OdDgECSchema::getClass(OdDgECSchema *this,ulong param_1)

{
  longlong *plVar1;
  undefined4 in_register_00000014;
  undefined4 in_R8D;
  
                    /* 0x76c420  9676
                       ?getClass@OdDgECSchema@@UEBA?AV?$OdSmartPtr@VOdDgECClass@@@@K@Z */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgECSchemaImpl::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x7a8))(plVar1,CONCAT44(in_register_00000014,param_1),in_R8D);
  return CONCAT44(in_register_00000014,param_1);
}



/* ==== 18081c8e0 getClass ==== */

/* public: static class OdRxClass * __ptr64 __cdecl
   OdDgExtraElementCustomizationServices::getClass(unsigned __int64) */

OdRxClass * __cdecl OdDgExtraElementCustomizationServices::getClass(__uint64 param_1)

{
  OdRxClass *pOVar1;
  undefined8 local_res10;
  
                    /* 0x81c8e0  9677
                       ?getClass@OdDgExtraElementCustomizationServices@@SAPEAVOdRxClass@@_K@Z */
  getExtraElementCustomizationServices();
  if (local_res10 == (longlong *)0x0) {
    pOVar1 = (OdRxClass *)0x0;
  }
  else {
    pOVar1 = (OdRxClass *)(**(code **)(*local_res10 + 0x68))(local_res10,param_1);
    (**(code **)(*local_res10 + 0x28))(local_res10);
  }
  return pOVar1;
}



/* ==== 18081e0b0 GetClass ==== */

/* public: virtual enum OdDgGraphicsElement::Class const __cdecl CDGDispHeader::GetClass(void)const
   __ptr64 */

Class __thiscall CDGDispHeader::GetClass(CDGDispHeader *this)

{
                    /* 0x81e0b0  4003
                       ?GetClass@CDGDispHeader@@UEBA?BW4Class@OdDgGraphicsElement@@XZ */
  if (*(longlong *)(this + 0x30) == 0) {
    return 0;
  }
  return *(ushort *)(*(longlong *)(this + 0x30) + 8) & 0xf;
}



