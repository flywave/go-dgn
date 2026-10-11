/* ==== 1800086b0 GetRangeHigh ==== */

/* public: virtual class OdGePoint3d const & __ptr64 __cdecl ECell<class
   OdDgFiler3d>::GetRangeHigh(void)const __ptr64 */

OdGePoint3d * __thiscall ECell<OdDgFiler3d>::GetRangeHigh(ECell<OdDgFiler3d> *this)

{
                    /* 0x86b0  4045  ?GetRangeHigh@?$ECell@VOdDgFiler3d@@@@UEBAAEBVOdGePoint3d@@XZ
                        */
  return (OdGePoint3d *)(this + 0x260);
}



/* ==== 1800086c0 GetRangeLow ==== */

/* public: virtual class OdGePoint3d const & __ptr64 __cdecl ECell<class
   OdDgFiler3d>::GetRangeLow(void)const __ptr64 */

OdGePoint3d * __thiscall ECell<OdDgFiler3d>::GetRangeLow(ECell<OdDgFiler3d> *this)

{
                    /* 0x86c0  4046  ?GetRangeLow@?$ECell@VOdDgFiler3d@@@@UEBAAEBVOdGePoint3d@@XZ */
  return (OdGePoint3d *)(this + 0x248);
}



/* ==== 180011c40 getHbitFlag ==== */

/* public: bool __cdecl CDGDispHeader::getHbitFlag(void)const __ptr64 */

bool __thiscall CDGDispHeader::getHbitFlag(CDGDispHeader *this)

{
                    /* 0x11c40  11392  ?getHbitFlag@CDGDispHeader@@QEBA_NXZ */
  if (*(longlong *)(this + 0x30) != 0) {
    return SUB21((ushort)*(undefined2 *)(*(longlong *)(this + 0x30) + 8) >> 0xf,0);
  }
  return false;
}



/* ==== 180011d10 getInvisibleFlag ==== */

/* public: bool __cdecl CDGDispHeader::getInvisibleFlag(void)const __ptr64 */

bool __thiscall CDGDispHeader::getInvisibleFlag(CDGDispHeader *this)

{
                    /* 0x11d10  11546  ?getInvisibleFlag@CDGDispHeader@@QEBA_NXZ */
  if (*(longlong *)(this + 0x30) != 0) {
    return (bool)(*(byte *)(*(longlong *)(this + 0x30) + 8) >> 7);
  }
  return false;
}



/* ==== 180011d30 getIs3dFlagUndefined ==== */

/* public: bool __cdecl CDGDispHeader::getIs3dFlagUndefined(void)const __ptr64 */

bool __thiscall CDGDispHeader::getIs3dFlagUndefined(CDGDispHeader *this)

{
                    /* 0x11d30  11551  ?getIs3dFlagUndefined@CDGDispHeader@@QEBA_NXZ */
  return (bool)this[0x38];
}



/* ==== 180011f10 getNonPlanarFlag ==== */

/* public: bool __cdecl CDGDispHeader::getNonPlanarFlag(void)const __ptr64 */

bool __thiscall CDGDispHeader::getNonPlanarFlag(CDGDispHeader *this)

{
                    /* 0x11f10  12232  ?getNonPlanarFlag@CDGDispHeader@@QEBA_NXZ */
  if (*(longlong *)(this + 0x30) != 0) {
    return (bool)((byte)((ushort)*(undefined2 *)(*(longlong *)(this + 0x30) + 8) >> 0xd) & 1);
  }
  return false;
}



/* ==== 180011f30 getNotSnappableFlag ==== */

/* public: bool __cdecl CDGDispHeader::getNotSnappableFlag(void)const __ptr64 */

bool __thiscall CDGDispHeader::getNotSnappableFlag(CDGDispHeader *this)

{
                    /* 0x11f30  12242  ?getNotSnappableFlag@CDGDispHeader@@QEBA_NXZ */
  if (*(longlong *)(this + 0x30) != 0) {
    return (bool)((byte)((ushort)*(undefined2 *)(*(longlong *)(this + 0x30) + 8) >> 0xe) & 1);
  }
  return true;
}



/* ==== 1800126d0 getPriority ==== */

/* public: long __cdecl CDGDispHeader::getPriority(void)const __ptr64 */

long __thiscall CDGDispHeader::getPriority(CDGDispHeader *this)

{
                    /* 0x126d0  12811  ?getPriority@CDGDispHeader@@QEBAJXZ */
  if (*(longlong *)(this + 0x30) != 0) {
    return *(long *)(*(longlong *)(this + 0x30) + 4);
  }
  return 0;
}



/* ==== 1800127a0 getViewIndependentFlag ==== */

/* public: bool __cdecl CDGDispHeader::getViewIndependentFlag(void)const __ptr64 */

bool __thiscall CDGDispHeader::getViewIndependentFlag(CDGDispHeader *this)

{
                    /* 0x127a0  14288  ?getViewIndependentFlag@CDGDispHeader@@QEBA_NXZ */
  if (*(longlong *)(this + 0x30) != 0) {
    return (bool)((byte)((ushort)*(undefined2 *)(*(longlong *)(this + 0x30) + 8) >> 0xc) & 1);
  }
  return false;
}



/* ==== 18011c9e0 getHbitFlag ==== */

/* public: virtual bool __cdecl CDGElementGeneral::getHbitFlag(void)const __ptr64 */

bool __thiscall CDGElementGeneral::getHbitFlag(CDGElementGeneral *this)

{
                    /* 0x11c9e0  11393  ?getHbitFlag@CDGElementGeneral@@UEBA_NXZ */
  if (*(longlong *)(this + 0xe0) != 0) {
    return SUB21((ushort)*(undefined2 *)(*(longlong *)(this + 0xe0) + 8) >> 0xf,0);
  }
  return false;
}



/* ==== 18011ca10 getInvisibleFlag ==== */

/* public: virtual bool __cdecl CDGElementGeneral::getInvisibleFlag(void)const __ptr64 */

bool __thiscall CDGElementGeneral::getInvisibleFlag(CDGElementGeneral *this)

{
                    /* 0x11ca10  11547  ?getInvisibleFlag@CDGElementGeneral@@UEBA_NXZ */
  if (*(longlong *)(this + 0xe0) != 0) {
    return (bool)(*(byte *)(*(longlong *)(this + 0xe0) + 8) >> 7);
  }
  return false;
}



/* ==== 18011ddb0 getNonPlanarFlag ==== */

/* public: virtual bool __cdecl CDGElementGeneral::getNonPlanarFlag(void)const __ptr64 */

bool __thiscall CDGElementGeneral::getNonPlanarFlag(CDGElementGeneral *this)

{
                    /* 0x11ddb0  12233  ?getNonPlanarFlag@CDGElementGeneral@@UEBA_NXZ */
  if (*(longlong *)(this + 0xe0) != 0) {
    return (bool)((byte)((ushort)*(undefined2 *)(*(longlong *)(this + 0xe0) + 8) >> 0xd) & 1);
  }
  return false;
}



/* ==== 18011ddd0 getNotSnappableFlag ==== */

/* public: virtual bool __cdecl CDGElementGeneral::getNotSnappableFlag(void)const __ptr64 */

bool __thiscall CDGElementGeneral::getNotSnappableFlag(CDGElementGeneral *this)

{
                    /* 0x11ddd0  12243  ?getNotSnappableFlag@CDGElementGeneral@@UEBA_NXZ */
  if (*(longlong *)(this + 0xe0) != 0) {
    return (bool)((byte)((ushort)*(undefined2 *)(*(longlong *)(this + 0xe0) + 8) >> 0xe) & 1);
  }
  return true;
}



/* ==== 18011eab0 getViewIndependentFlag ==== */

/* public: virtual bool __cdecl CDGElementGeneral::getViewIndependentFlag(void)const __ptr64 */

bool __thiscall CDGElementGeneral::getViewIndependentFlag(CDGElementGeneral *this)

{
                    /* 0x11eab0  14289  ?getViewIndependentFlag@CDGElementGeneral@@UEBA_NXZ */
  if (*(longlong *)(this + 0xe0) != 0) {
    return (bool)((byte)((ushort)*(undefined2 *)(*(longlong *)(this + 0xe0) + 8) >> 0xc) & 1);
  }
  return false;
}



/* ==== 1801f3000 GetRange ==== */

/* public: void __cdecl ESharedCellInst::GetRange(class OdGeExtents3d & __ptr64)const __ptr64 */

void __thiscall ESharedCellInst::GetRange(ESharedCellInst *this,OdGeExtents3d *param_1)

{
  undefined8 uVar1;
  
                    /* 0x1f3000  4044  ?GetRange@ESharedCellInst@@QEBAXAEAVOdGeExtents3d@@@Z */
  uVar1 = *(undefined8 *)(this + 0x230);
  *(undefined8 *)param_1 = *(undefined8 *)(this + 0x228);
  *(undefined8 *)(param_1 + 8) = uVar1;
  uVar1 = *(undefined8 *)(this + 0x240);
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(this + 0x238);
  *(undefined8 *)(param_1 + 0x18) = uVar1;
  uVar1 = *(undefined8 *)(this + 0x250);
  *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(this + 0x248);
  *(undefined8 *)(param_1 + 0x28) = uVar1;
  return;
}



/* ==== 180230530 getPriority ==== */

/* public: unsigned long __cdecl OdDgReferenceAttachmentHeader::getPriority(void)const __ptr64 */

ulong __thiscall OdDgReferenceAttachmentHeader::getPriority(OdDgReferenceAttachmentHeader *this)

{
  longlong lVar1;
  
                    /* 0x230530  12815  ?getPriority@OdDgReferenceAttachmentHeader@@QEBAKXZ */
  lVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &CDGReferenceElement::RTTI_Type_Descriptor,0);
  return *(ulong *)(lVar1 + 0x27c);
}



/* ==== 1802c2c30 getHbitFlag ==== */

/* public: virtual bool __cdecl OdDgGraphicsElement::getHbitFlag(void)const __ptr64 */

bool __thiscall OdDgGraphicsElement::getHbitFlag(OdDgGraphicsElement *this)

{
  bool bVar1;
  longlong *plVar2;
  
                    /* 0x2c2c30  11394  ?getHbitFlag@OdDgGraphicsElement@@UEBA_NXZ */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGElementGeneral::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001802c2c5f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar1 = (bool)(**(code **)(*plVar2 + 0x5c0))(plVar2);
  return bVar1;
}



/* ==== 1802c2c70 getInvisibleFlag ==== */

/* public: virtual bool __cdecl OdDgGraphicsElement::getInvisibleFlag(void)const __ptr64 */

bool __thiscall OdDgGraphicsElement::getInvisibleFlag(OdDgGraphicsElement *this)

{
  longlong *plVar1;
  char cVar2;
  undefined1 uVar3;
  longlong lVar4;
  
                    /* 0x2c2c70  11548  ?getInvisibleFlag@OdDgGraphicsElement@@UEBA_NXZ */
  if ((*s_bIsOverruling_exref != (code)0x0) && (this != (OdDgGraphicsElement *)0x0)) {
    lVar4 = (**(code **)(*(longlong *)this + 0x18))();
    for (plVar1 = *(longlong **)(*(longlong *)(lVar4 + 8) + 0x60); plVar1 != (longlong *)0x0;
        plVar1 = (longlong *)plVar1[1]) {
      cVar2 = (**(code **)(*(longlong *)*plVar1 + 0x58))((longlong *)*plVar1,this);
      if (cVar2 != '\0') {
        *(longlong *)(*plVar1 + 8) = plVar1[1];
        plVar1 = (longlong *)*plVar1;
        if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001802c2cf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          uVar3 = (**(code **)(*plVar1 + 0x60))(plVar1,this);
          return (bool)uVar3;
        }
        break;
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0001802c2cca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar3 = (**(code **)(*(longlong *)this + 0x5b8))(this);
  return (bool)uVar3;
}



/* ==== 1802c2d00 getInvisibleFlag ==== */

/* public: virtual bool __cdecl OdDgVisibilityOverrule::getInvisibleFlag(class OdDgGraphicsElement
   const * __ptr64) __ptr64 */

bool __thiscall
OdDgVisibilityOverrule::getInvisibleFlag(OdDgVisibilityOverrule *this,OdDgGraphicsElement *param_1)

{
  longlong *plVar1;
  char cVar2;
  undefined1 uVar3;
  
                    /* 0x2c2d00  11549
                       ?getInvisibleFlag@OdDgVisibilityOverrule@@UEAA_NPEBVOdDgGraphicsElement@@@Z
                        */
  plVar1 = *(longlong **)(this + 8);
  do {
    if (plVar1 == (longlong *)0x0) {
LAB_1802c2d39:
                    /* WARNING: Could not recover jumptable at 0x0001802c2d49. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(*(longlong *)param_1 + 0x5b8))(param_1);
      return (bool)uVar3;
    }
    cVar2 = (**(code **)(*(longlong *)*plVar1 + 0x58))((longlong *)*plVar1,param_1);
    if (cVar2 != '\0') {
      *(longlong *)(*plVar1 + 8) = plVar1[1];
      plVar1 = (longlong *)*plVar1;
      if (plVar1 != (longlong *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001802c2d73. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar3 = (**(code **)(*plVar1 + 0x60))(plVar1,param_1);
        return (bool)uVar3;
      }
      goto LAB_1802c2d39;
    }
    plVar1 = (longlong *)plVar1[1];
  } while( true );
}



/* ==== 1802c2f30 getNonPlanarFlag ==== */

/* public: virtual bool __cdecl OdDgGraphicsElement::getNonPlanarFlag(void)const __ptr64 */

bool __thiscall OdDgGraphicsElement::getNonPlanarFlag(OdDgGraphicsElement *this)

{
  bool bVar1;
  longlong *plVar2;
  
                    /* 0x2c2f30  12234  ?getNonPlanarFlag@OdDgGraphicsElement@@UEBA_NXZ */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGElementGeneral::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001802c2f5f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar1 = (bool)(**(code **)(*plVar2 + 0x5a0))(plVar2);
  return bVar1;
}



/* ==== 1802c2f70 getNotSnappableFlag ==== */

/* public: virtual bool __cdecl OdDgGraphicsElement::getNotSnappableFlag(void)const __ptr64 */

bool __thiscall OdDgGraphicsElement::getNotSnappableFlag(OdDgGraphicsElement *this)

{
  bool bVar1;
  longlong *plVar2;
  
                    /* 0x2c2f70  12244  ?getNotSnappableFlag@OdDgGraphicsElement@@UEBA_NXZ */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGElementGeneral::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001802c2f9f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar1 = (bool)(**(code **)(*plVar2 + 0x5b0))(plVar2);
  return bVar1;
}



/* ==== 1802c2fb0 getPriority ==== */

/* public: virtual long __cdecl OdDgGraphicsElement::getPriority(void)const __ptr64 */

long __thiscall OdDgGraphicsElement::getPriority(OdDgGraphicsElement *this)

{
  int iVar1;
  longlong *plVar2;
  longlong lVar3;
  
                    /* 0x2c2fb0  12812  ?getPriority@OdDgGraphicsElement@@UEBAJXZ */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGElementGeneral::RTTI_Type_Descriptor,0);
  lVar3 = (**(code **)(*plVar2 + 0x460))(plVar2);
  if (lVar3 != 0) {
    lVar3 = (**(code **)(*plVar2 + 0x460))(plVar2);
    if (*(longlong *)(lVar3 + 0x30) != 0) {
      iVar1 = *(int *)(*(longlong *)(lVar3 + 0x30) + 4);
      if (20000000 < iVar1 + 10000000U) {
        iVar1 = 0;
      }
      return iVar1;
    }
  }
  return 0;
}



/* ==== 1802c3170 getViewIndependentFlag ==== */

/* public: virtual bool __cdecl OdDgGraphicsElement::getViewIndependentFlag(void)const __ptr64 */

bool __thiscall OdDgGraphicsElement::getViewIndependentFlag(OdDgGraphicsElement *this)

{
  bool bVar1;
  longlong *plVar2;
  
                    /* 0x2c3170  14292  ?getViewIndependentFlag@OdDgGraphicsElement@@UEBA_NXZ */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGElementGeneral::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001802c319f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  bVar1 = (bool)(**(code **)(*plVar2 + 0x590))(plVar2);
  return bVar1;
}



/* ==== 1803b3540 getViewIndependentFlag ==== */

/* public: virtual bool __cdecl ERasterReference::getViewIndependentFlag(void)const __ptr64 */

bool __thiscall ERasterReference::getViewIndependentFlag(ERasterReference *this)

{
                    /* 0x3b3540  14290  ?getViewIndependentFlag@ERasterReference@@UEBA_NXZ */
  return (bool)this[0x2ac];
}



/* ==== 18059ece0 getPriority ==== */

/* public: virtual long __cdecl OdDgLevelTableRecord::getPriority(void)const __ptr64 */

long __thiscall OdDgLevelTableRecord::getPriority(OdDgLevelTableRecord *this)

{
  longlong lVar1;
  
                    /* 0x59ece0  12813  ?getPriority@OdDgLevelTableRecord@@UEBAJXZ */
  lVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &CDGLevel::RTTI_Type_Descriptor,0);
  return *(int *)(lVar1 + 600) / 1000;
}



/* ==== 18081cfe0 GetColor ==== */

/* public: virtual unsigned long const __cdecl CDGAttribFillStyle::GetColor(void)const __ptr64 */

ulong __thiscall CDGAttribFillStyle::GetColor(CDGAttribFillStyle *this)

{
                    /* 0x81cfe0  4007  ?GetColor@CDGAttribFillStyle@@UEBA?BKXZ
                       0x81cfe0  4022  ?GetGradientFromColor@CDGAttribFillStyle@@UEBA?BKXZ */
  if (((byte)this[0x60] & 1) != 0) {
    return *(ulong *)(this + 0x40);
  }
  return *(ulong *)(this + 0x10);
}



/* ==== 18081e0d0 GetColor ==== */

/* public: virtual unsigned long const __cdecl CDGDispHeader::GetColor(void)const __ptr64 */

ulong __thiscall CDGDispHeader::GetColor(CDGDispHeader *this)

{
                    /* 0x81e0d0  4008  ?GetColor@CDGDispHeader@@UEBA?BKXZ */
  if (*(longlong *)(this + 0x30) == 0) {
    return 0xffffffff;
  }
  return *(ulong *)(*(longlong *)(this + 0x30) + 0x14);
}



/* ==== 18081e0f0 GetGraphicsGroup ==== */

/* public: virtual unsigned long const __cdecl CDGDispHeader::GetGraphicsGroup(void)const __ptr64 */

ulong __thiscall CDGDispHeader::GetGraphicsGroup(CDGDispHeader *this)

{
                    /* 0x81e0f0  4024  ?GetGraphicsGroup@CDGDispHeader@@UEBA?BKXZ */
  if (*(ulong **)(this + 0x30) == (ulong *)0x0) {
    return 0xffffffff;
  }
  return **(ulong **)(this + 0x30);
}



/* ==== 18081e110 GetLineStyle ==== */

/* public: virtual long const __cdecl CDGDispHeader::GetLineStyle(void)const __ptr64 */

long __thiscall CDGDispHeader::GetLineStyle(CDGDispHeader *this)

{
                    /* 0x81e110  4029  ?GetLineStyle@CDGDispHeader@@UEBA?BJXZ */
  if (*(longlong *)(this + 0x30) == 0) {
    return 0x7fffffff;
  }
  return *(long *)(*(longlong *)(this + 0x30) + 0xc);
}



/* ==== 18081e130 GetLineWeight ==== */

/* public: virtual unsigned long const __cdecl CDGDispHeader::GetLineWeight(void)const __ptr64 */

ulong __thiscall CDGDispHeader::GetLineWeight(CDGDispHeader *this)

{
                    /* 0x81e130  4030  ?GetLineWeight@CDGDispHeader@@UEBA?BKXZ */
  if (*(longlong *)(this + 0x30) == 0) {
    return 0xffffffff;
  }
  return *(ulong *)(*(longlong *)(this + 0x30) + 0x10);
}



/* ==== 18081e150 GetRange ==== */

/* public: virtual struct Dgn8::SIntRange3D const & __ptr64 __cdecl
   CDGDispHeader::GetRange(void)const __ptr64 */

SIntRange3D * __thiscall CDGDispHeader::GetRange(CDGDispHeader *this)

{
                    /* 0x81e150  4043  ?GetRange@CDGDispHeader@@UEBAAEBUSIntRange3D@Dgn8@@XZ */
  if (*(longlong *)(this + 0x30) == 0) {
    return (SIntRange3D *)&DAT_180fcd3f8;
  }
  return (SIntRange3D *)(*(longlong *)(this + 0x30) + 0x18);
}



/* ==== 180843eb0 getViewIndependentFlag ==== */

/* public: virtual bool __cdecl OdDgAcsXAttributeImpl::getViewIndependentFlag(void)const __ptr64 */

bool __thiscall OdDgAcsXAttributeImpl::getViewIndependentFlag(OdDgAcsXAttributeImpl *this)

{
                    /* 0x843eb0  14291  ?getViewIndependentFlag@OdDgAcsXAttributeImpl@@UEBA_NXZ */
  return (bool)this[0xb0];
}



