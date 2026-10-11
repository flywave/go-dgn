/* ==== 1801a55f0 getOrigin ==== */

/* public: class OdGePoint2d __cdecl OdDgTextNode2d::getOrigin(void)const __ptr64 */

void __thiscall OdDgTextNode2d::getOrigin(OdDgTextNode2d *this)

{
  undefined8 uVar1;
  longlong lVar2;
  undefined8 *in_RDX;
  
                    /* 0x1a55f0  12387  ?getOrigin@OdDgTextNode2d@@QEBA?AVOdGePoint2d@@XZ */
  lVar2 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &ETextNode2D::RTTI_Type_Descriptor,0);
  uVar1 = *(undefined8 *)(lVar2 + 0x278);
  *in_RDX = *(undefined8 *)(lVar2 + 0x270);
  in_RDX[1] = uVar1;
  return;
}



/* ==== 1801a5630 getOrigin ==== */

/* public: class OdGePoint3d __cdecl OdDgTextNode3d::getOrigin(void)const __ptr64 */

void __thiscall OdDgTextNode3d::getOrigin(OdDgTextNode3d *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *in_RDX;
  
                    /* 0x1a5630  12388  ?getOrigin@OdDgTextNode3d@@QEBA?AVOdGePoint3d@@XZ */
  lVar3 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &ETextNode3D::RTTI_Type_Descriptor,0);
  uVar2 = *(undefined8 *)(lVar3 + 0x290);
  uVar1 = *(undefined8 *)(lVar3 + 0x298);
  *in_RDX = *(undefined8 *)(lVar3 + 0x288);
  in_RDX[1] = uVar2;
  in_RDX[2] = uVar1;
  return;
}



/* ==== 1801a5da0 getRotation ==== */

/* public: double __cdecl OdDgTextNode2d::getRotation(void)const __ptr64 */

double __thiscall OdDgTextNode2d::getRotation(OdDgTextNode2d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x1a5da0  13074  ?getRotation@OdDgTextNode2d@@QEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &ETextNode2D::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001801a5dcf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x7c8))(plVar1);
  return dVar2;
}



/* ==== 1801a5de0 getRotation ==== */

/* public: class OdGeQuaternion __cdecl OdDgTextNode3d::getRotation(void)const __ptr64 */

void __thiscall OdDgTextNode3d::getRotation(OdDgTextNode3d *this)

{
  longlong *plVar1;
  
                    /* 0x1a5de0  13075  ?getRotation@OdDgTextNode3d@@QEBA?AVOdGeQuaternion@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &ETextNode3D::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 2000))(plVar1);
  return;
}



/* ==== 1801b3020 getRotation ==== */

/* public: virtual double __cdecl OdDgRasterAttachmentHeader::getRotation(void)const __ptr64 */

double __thiscall OdDgRasterAttachmentHeader::getRotation(OdDgRasterAttachmentHeader *this)

{
  double dVar1;
  bool bVar2;
  ERasterReference *this_00;
  OdGeVector3d *this_01;
  OdGeVector3d *pOVar3;
  double local_68;
  double dStack_60;
  double local_58;
  double local_50;
  double dStack_48;
  double local_40;
  double local_38;
  double local_30;
  double local_28;
  OdGeVector3d local_20 [24];
  
                    /* 0x1b3020  13068  ?getRotation@OdDgRasterAttachmentHeader@@UEBANXZ */
  this_00 = (ERasterReference *)
            __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                            &ERasterReference::RTTI_Type_Descriptor,0);
  ERasterReference::GetUVector(this_00);
  bVar2 = OdGeVector3d::isZeroLength((OdGeVector3d *)&local_68,(OdGeTol *)gTol_exref);
  if (bVar2) {
    local_68 = *(double *)kXAxis_exref;
    dStack_60 = *(double *)(kXAxis_exref + 8);
    local_58 = *(double *)(kXAxis_exref + 0x10);
  }
  else {
    OdGeVector3d::normalize((OdGeVector3d *)&local_68,(OdGeTol *)gTol_exref);
  }
  ERasterReference::GetVVector(this_00);
  bVar2 = OdGeVector3d::isZeroLength((OdGeVector3d *)&local_50,(OdGeTol *)gTol_exref);
  if (bVar2) {
    local_50 = *(double *)kYAxis_exref;
    dStack_48 = *(double *)(kYAxis_exref + 8);
    local_40 = *(double *)(kYAxis_exref + 0x10);
  }
  else {
    OdGeVector3d::normalize((OdGeVector3d *)&local_50,(OdGeTol *)gTol_exref);
  }
  local_38 = local_40 * dStack_60 - local_58 * dStack_48;
  local_30 = local_58 * local_50 - local_40 * local_68;
  local_28 = local_68 * dStack_48 - dStack_60 * local_50;
  bVar2 = OdGeVector3d::isParallelTo
                    ((OdGeVector3d *)&local_38,(OdGeVector3d *)kZAxis_exref,(OdGeTol *)gTol_exref);
  this_01 = (OdGeVector3d *)kXAxis_exref;
  pOVar3 = (OdGeVector3d *)kZAxis_exref;
  if (!bVar2) {
    OdGeVector3d::perpVector((OdGeVector3d *)&local_38);
    this_01 = local_20;
    pOVar3 = (OdGeVector3d *)&local_38;
  }
  dVar1 = OdGeVector3d::angleTo(this_01,(OdGeVector3d *)&local_68,pOVar3);
  return dVar1;
}



/* ==== 1801dfeb0 getRotationAt ==== */

/* public: virtual class OdGeMatrix2d __cdecl OdDgPointString2d::getRotationAt(unsigned long)const
   __ptr64 */

undefined8 __thiscall OdDgPointString2d::getRotationAt(OdDgPointString2d *this,ulong param_1)

{
  longlong *plVar1;
  undefined4 in_register_00000014;
  undefined4 in_R8D;
  
                    /* 0x1dfeb0  13081  ?getRotationAt@OdDgPointString2d@@UEBA?AVOdGeMatrix2d@@K@Z
                        */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EPointString2D::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x618))(plVar1,CONCAT44(in_register_00000014,param_1),in_R8D);
  return CONCAT44(in_register_00000014,param_1);
}



/* ==== 1801dff10 getRotationAt ==== */

/* public: virtual class OdGeQuaternion __cdecl OdDgPointString3d::getRotationAt(unsigned long)const
   __ptr64 */

undefined8 __thiscall OdDgPointString3d::getRotationAt(OdDgPointString3d *this,ulong param_1)

{
  longlong *plVar1;
  undefined4 in_register_00000014;
  undefined4 in_R8D;
  
                    /* 0x1dff10  13082  ?getRotationAt@OdDgPointString3d@@UEBA?AVOdGeQuaternion@@K@Z
                        */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EPointString3D::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x618))(plVar1,CONCAT44(in_register_00000014,param_1),in_R8D);
  return CONCAT44(in_register_00000014,param_1);
}



/* ==== 1801e8ea0 getOriginCap ==== */

/* public: void __cdecl OdDgMultiline::getOriginCap(class OdDgMultilineSymbology & __ptr64)const
   __ptr64 */

void __thiscall OdDgMultiline::getOriginCap(OdDgMultiline *this,OdDgMultilineSymbology *param_1)

{
  undefined8 uVar1;
  
                    /* 0x1e8ea0  12390
                       ?getOriginCap@OdDgMultiline@@QEBAXAEAVOdDgMultilineSymbology@@@Z */
  uVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &EMultiLine::RTTI_Type_Descriptor,0);
  uVar1 = FUN_18016bfb0(uVar1);
  FUN_1801e1e60(uVar1,param_1);
  return;
}



/* ==== 1801e8ef0 getOriginCapAngle ==== */

/* public: double __cdecl OdDgMultiline::getOriginCapAngle(void)const __ptr64 */

double __thiscall OdDgMultiline::getOriginCapAngle(OdDgMultiline *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x1e8ef0  12392  ?getOriginCapAngle@OdDgMultiline@@QEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EMultiLine::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001801e8f1f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x600))(plVar1);
  return dVar2;
}



/* ==== 1801eec50 getRotation ==== */

/* public: virtual class OdGeMatrix3d __cdecl
   OdDgSectionClipDataXAttributeImpl::getRotation(void)const __ptr64 */

void __thiscall
OdDgSectionClipDataXAttributeImpl::getRotation(OdDgSectionClipDataXAttributeImpl *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *in_RDX;
  
                    /* 0x1eec50  13070
                       ?getRotation@OdDgSectionClipDataXAttributeImpl@@UEBA?AVOdGeMatrix3d@@XZ */
  uVar1 = *(undefined8 *)(this + 0x40);
  uVar2 = *(undefined8 *)(this + 0x48);
  uVar3 = *(undefined8 *)(this + 0x50);
  *in_RDX = *(undefined8 *)(this + 0x38);
  in_RDX[1] = uVar1;
  uVar1 = *(undefined8 *)(this + 0x58);
  uVar4 = *(undefined8 *)(this + 0x60);
  in_RDX[2] = uVar2;
  in_RDX[3] = uVar3;
  uVar2 = *(undefined8 *)(this + 0x68);
  uVar3 = *(undefined8 *)(this + 0x70);
  in_RDX[4] = uVar1;
  in_RDX[5] = uVar4;
  uVar1 = *(undefined8 *)(this + 0x78);
  uVar4 = *(undefined8 *)(this + 0x80);
  in_RDX[6] = uVar2;
  in_RDX[7] = uVar3;
  uVar2 = *(undefined8 *)(this + 0x88);
  uVar3 = *(undefined8 *)(this + 0x90);
  in_RDX[8] = uVar1;
  in_RDX[9] = uVar4;
  uVar1 = *(undefined8 *)(this + 0x98);
  uVar4 = *(undefined8 *)(this + 0xa0);
  in_RDX[10] = uVar2;
  in_RDX[0xb] = uVar3;
  uVar2 = *(undefined8 *)(this + 0xa8);
  uVar3 = *(undefined8 *)(this + 0xb0);
  in_RDX[0xc] = uVar1;
  in_RDX[0xd] = uVar4;
  in_RDX[0xe] = uVar2;
  in_RDX[0xf] = uVar3;
  return;
}



/* ==== 18026bcb0 getOrigin ==== */

/* public: class OdGePoint3d __cdecl OdDgSharedCellDefinition::getOrigin(void)const __ptr64 */

void __thiscall OdDgSharedCellDefinition::getOrigin(OdDgSharedCellDefinition *this)

{
  undefined8 uVar1;
  
                    /* 0x26bcb0  12381  ?getOrigin@OdDgSharedCellDefinition@@QEBA?AVOdGePoint3d@@XZ
                        */
  uVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &ESharedCellDef::RTTI_Type_Descriptor,0);
  FUN_18026a0a0(uVar1);
  return;
}



/* ==== 18026bcf0 getOrigin ==== */

/* public: class OdGePoint3d __cdecl OdDgSharedCellReference::getOrigin(void)const __ptr64 */

void __thiscall OdDgSharedCellReference::getOrigin(OdDgSharedCellReference *this)

{
  ESharedCellInst *this_00;
  
                    /* 0x26bcf0  12382  ?getOrigin@OdDgSharedCellReference@@QEBA?AVOdGePoint3d@@XZ
                        */
  this_00 = (ESharedCellInst *)
            __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                            &ESharedCellInst::RTTI_Type_Descriptor,0);
  ESharedCellInst::GetOrigin(this_00);
  return;
}



/* ==== 18028a090 getOrigin ==== */

/* public: class OdGePoint3d __cdecl OdDgTagElement::getOrigin(void)const __ptr64 */

void __thiscall OdDgTagElement::getOrigin(OdDgTagElement *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *in_RDX;
  
                    /* 0x28a090  12384  ?getOrigin@OdDgTagElement@@QEBA?AVOdGePoint3d@@XZ */
  lVar3 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &EAttribute::RTTI_Type_Descriptor,0);
  uVar2 = *(undefined8 *)(lVar3 + 0x260);
  uVar1 = *(undefined8 *)(lVar3 + 0x268);
  *in_RDX = *(undefined8 *)(lVar3 + 600);
  in_RDX[1] = uVar2;
  in_RDX[2] = uVar1;
  return;
}



/* ==== 18028a1a0 getRotation2d ==== */

/* public: double __cdecl OdDgTagElement::getRotation2d(void)const __ptr64 */

double __thiscall OdDgTagElement::getRotation2d(OdDgTagElement *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x28a1a0  13053  ?getRotation2d@OdDgTagElement@@QEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EAttribute::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x00018028a1cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x660))(plVar1);
  return dVar2;
}



/* ==== 18028a1e0 getRotation3d ==== */

/* public: class OdGeQuaternion __cdecl OdDgTagElement::getRotation3d(void)const __ptr64 */

void __thiscall OdDgTagElement::getRotation3d(OdDgTagElement *this)

{
  longlong *plVar1;
  
                    /* 0x28a1e0  13054  ?getRotation3d@OdDgTagElement@@QEBA?AVOdGeQuaternion@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EAttribute::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x670))(plVar1);
  return;
}



/* ==== 1802a0830 getOrigin ==== */

/* public: virtual class OdGePoint2d __cdecl OdDgEllipse2d::getOrigin(void)const __ptr64 */

void __thiscall OdDgEllipse2d::getOrigin(OdDgEllipse2d *this)

{
  longlong *plVar1;
  
                    /* 0x2a0830  12371  ?getOrigin@OdDgEllipse2d@@UEBA?AVOdGePoint2d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EEllipse2D::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x648))(plVar1);
  return;
}



/* ==== 1802a0880 getOrigin ==== */

/* public: virtual void __cdecl OdDgEllipse3d::getOrigin(class OdGePoint3d & __ptr64)const __ptr64
    */

void __thiscall OdDgEllipse3d::getOrigin(OdDgEllipse3d *this,OdGePoint3d *param_1)

{
  undefined8 uVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined1 local_28 [32];
  
                    /* 0x2a0880  12372  ?getOrigin@OdDgEllipse3d@@UEBAXAEAVOdGePoint3d@@@Z */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EEllipse3D::RTTI_Type_Descriptor,0);
  puVar3 = (undefined8 *)(**(code **)(*plVar2 + 0x638))(plVar2,local_28);
  uVar1 = puVar3[1];
  *(undefined8 *)param_1 = *puVar3;
  *(undefined8 *)(param_1 + 8) = uVar1;
  *(undefined8 *)(param_1 + 0x10) = puVar3[2];
  return;
}



/* ==== 1802a0fb0 getRotation ==== */

/* public: virtual class OdGeQuaternion __cdecl OdDgEllipse3d::getRotation(void)const __ptr64 */

void __thiscall OdDgEllipse3d::getRotation(OdDgEllipse3d *this)

{
  undefined8 uVar1;
  
                    /* 0x2a0fb0  13061  ?getRotation@OdDgEllipse3d@@UEBA?AVOdGeQuaternion@@XZ */
  uVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &EEllipse3D::RTTI_Type_Descriptor,0);
  FUN_1801d7ae0(uVar1);
  return;
}



/* ==== 1802a0ff0 getRotationAngle ==== */

/* public: virtual double __cdecl OdDgEllipse2d::getRotationAngle(void)const __ptr64 */

double __thiscall OdDgEllipse2d::getRotationAngle(OdDgEllipse2d *this)

{
  longlong *plVar1;
  double *pdVar2;
  
                    /* 0x2a0ff0  13077  ?getRotationAngle@OdDgEllipse2d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EEllipse2D::RTTI_Type_Descriptor,0);
  pdVar2 = (double *)(**(code **)(*plVar1 + 0x638))(plVar1);
  return *pdVar2;
}



/* ==== 1802b2080 getOrigin ==== */

/* public: virtual class OdGePoint2d __cdecl OdDgCellHeader2d::getOrigin(void)const __ptr64 */

void __thiscall OdDgCellHeader2d::getOrigin(OdDgCellHeader2d *this)

{
  longlong *plVar1;
  
                    /* 0x2b2080  12369  ?getOrigin@OdDgCellHeader2d@@UEBA?AVOdGePoint2d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &ECell2D::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x698))(plVar1);
  return;
}



/* ==== 1802b20d0 getOrigin ==== */

/* public: virtual class OdGePoint3d __cdecl OdDgCellHeader3d::getOrigin(void)const __ptr64 */

void __thiscall OdDgCellHeader3d::getOrigin(OdDgCellHeader3d *this)

{
  longlong *plVar1;
  
                    /* 0x2b20d0  12370  ?getOrigin@OdDgCellHeader3d@@UEBA?AVOdGePoint3d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &ECell3D::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x698))(plVar1);
  return;
}



/* ==== 1802d5dc0 getOrigin ==== */

/* public: virtual class OdGePoint2d __cdecl OdDgText2d::getOrigin(void)const __ptr64 */

void __thiscall OdDgText2d::getOrigin(OdDgText2d *this)

{
  undefined8 uVar1;
  
                    /* 0x2d5dc0  12385  ?getOrigin@OdDgText2d@@UEBA?AVOdGePoint2d@@XZ */
  uVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &EText2D::RTTI_Type_Descriptor,0);
  FUN_180290150(uVar1);
  return;
}



/* ==== 1802d5e00 getOrigin ==== */

/* public: virtual class OdGePoint3d __cdecl OdDgText3d::getOrigin(void)const __ptr64 */

void __thiscall OdDgText3d::getOrigin(OdDgText3d *this)

{
  undefined8 uVar1;
  
                    /* 0x2d5e00  12386  ?getOrigin@OdDgText3d@@UEBA?AVOdGePoint3d@@XZ */
  uVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &EText3D::RTTI_Type_Descriptor,0);
  FUN_180290160(uVar1);
  return;
}



/* ==== 1802d65e0 getRotation ==== */

/* public: virtual double __cdecl OdDgText2d::getRotation(void)const __ptr64 */

double __thiscall OdDgText2d::getRotation(OdDgText2d *this)

{
  undefined8 uVar1;
  double dVar2;
  
                    /* 0x2d65e0  13072  ?getRotation@OdDgText2d@@UEBANXZ */
  uVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &EText2D::RTTI_Type_Descriptor,0);
  dVar2 = (double)FUN_1802901a0(uVar1);
  return dVar2;
}



/* ==== 1802d6620 getRotation ==== */

/* public: virtual class OdGeQuaternion __cdecl OdDgText3d::getRotation(void)const __ptr64 */

void __thiscall OdDgText3d::getRotation(OdDgText3d *this)

{
  undefined8 uVar1;
  
                    /* 0x2d6620  13073  ?getRotation@OdDgText3d@@UEBA?AVOdGeQuaternion@@XZ */
  uVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &EText3D::RTTI_Type_Descriptor,0);
  FUN_180290180(uVar1);
  return;
}



/* ==== 18034e590 getRotation ==== */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual void __cdecl OdDgDimension::getRotation(class OdGeMatrix2d & __ptr64)const
   __ptr64 */

void __thiscall OdDgDimension::getRotation(OdDgDimension *this,OdGeMatrix2d *param_1)

{
  undefined8 uVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined1 auStack_98 [32];
  undefined4 local_78;
  undefined1 local_68 [80];
  ulonglong local_18;
  
                    /* 0x34e590  13059  ?getRotation@OdDgDimension@@UEBAXAEAVOdGeMatrix2d@@@Z */
  local_18 = DAT_180fcd438 ^ (ulonglong)auStack_98;
  local_78 = 0;
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EDimension::RTTI_Type_Descriptor);
  puVar3 = (undefined8 *)(**(code **)(*plVar2 + 0x700))(plVar2,local_68);
  uVar1 = puVar3[1];
  *(undefined8 *)param_1 = *puVar3;
  *(undefined8 *)(param_1 + 8) = uVar1;
  uVar1 = puVar3[3];
  *(undefined8 *)(param_1 + 0x10) = puVar3[2];
  *(undefined8 *)(param_1 + 0x18) = uVar1;
  uVar1 = puVar3[5];
  *(undefined8 *)(param_1 + 0x20) = puVar3[4];
  *(undefined8 *)(param_1 + 0x28) = uVar1;
  uVar1 = puVar3[7];
  *(undefined8 *)(param_1 + 0x30) = puVar3[6];
  *(undefined8 *)(param_1 + 0x38) = uVar1;
  *(undefined8 *)(param_1 + 0x40) = puVar3[8];
  return;
}



/* ==== 18034e630 getRotation ==== */

/* public: virtual void __cdecl OdDgDimension::getRotation(class OdGeQuaternion & __ptr64)const
   __ptr64 */

void __thiscall OdDgDimension::getRotation(OdDgDimension *this,OdGeQuaternion *param_1)

{
  undefined8 uVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined1 local_28 [32];
  
                    /* 0x34e630  13060  ?getRotation@OdDgDimension@@UEBAXAEAVOdGeQuaternion@@@Z */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EDimension::RTTI_Type_Descriptor,0);
  puVar3 = (undefined8 *)(**(code **)(*plVar2 + 0x708))(plVar2,local_28);
  uVar1 = puVar3[1];
  *(undefined8 *)param_1 = *puVar3;
  *(undefined8 *)(param_1 + 8) = uVar1;
  uVar1 = puVar3[3];
  *(undefined8 *)(param_1 + 0x10) = puVar3[2];
  *(undefined8 *)(param_1 + 0x18) = uVar1;
  return;
}



/* ==== 1803d1710 getRotation ==== */

/* public: virtual class OdGeQuaternion __cdecl OdDgCone::getRotation(void)const __ptr64 */

void __thiscall OdDgCone::getRotation(OdDgCone *this)

{
  longlong *plVar1;
  
                    /* 0x3d1710  13058  ?getRotation@OdDgCone@@UEBA?AVOdGeQuaternion@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &ECone::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x620))(plVar1);
  return;
}



/* ==== 1803d7e70 getOrigin ==== */

/* public: virtual class OdGePoint2d __cdecl OdDgArc2d::getOrigin(void)const __ptr64 */

void __thiscall OdDgArc2d::getOrigin(OdDgArc2d *this)

{
  undefined8 uVar1;
  
                    /* 0x3d7e70  12365  ?getOrigin@OdDgArc2d@@UEBA?AVOdGePoint2d@@XZ */
  uVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &EArc2D::RTTI_Type_Descriptor,0);
  FUN_1802850a0(uVar1);
  return;
}



/* ==== 1803d7eb0 getOrigin ==== */

/* public: virtual void __cdecl OdDgArc2d::getOrigin(class OdGePoint2d & __ptr64)const __ptr64 */

void __thiscall OdDgArc2d::getOrigin(OdDgArc2d *this,OdGePoint2d *param_1)

{
  undefined8 uVar1;
  undefined8 *puVar2;
  undefined1 local_18 [16];
  
                    /* 0x3d7eb0  12366  ?getOrigin@OdDgArc2d@@UEBAXAEAVOdGePoint2d@@@Z */
  uVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &EArc2D::RTTI_Type_Descriptor,0);
  puVar2 = (undefined8 *)FUN_1802850a0(uVar1,local_18);
  uVar1 = puVar2[1];
  *(undefined8 *)param_1 = *puVar2;
  *(undefined8 *)(param_1 + 8) = uVar1;
  return;
}



/* ==== 1803d7f00 getOrigin ==== */

/* public: virtual class OdGePoint3d __cdecl OdDgArc3d::getOrigin(void)const __ptr64 */

void __thiscall OdDgArc3d::getOrigin(OdDgArc3d *this)

{
  longlong *plVar1;
  
                    /* 0x3d7f00  12367  ?getOrigin@OdDgArc3d@@UEBA?AVOdGePoint3d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc3D::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x670))(plVar1);
  return;
}



/* ==== 1803d7f50 getOrigin ==== */

/* public: virtual void __cdecl OdDgArc3d::getOrigin(class OdGePoint3d & __ptr64)const __ptr64 */

void __thiscall OdDgArc3d::getOrigin(OdDgArc3d *this,OdGePoint3d *param_1)

{
  undefined8 uVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined1 local_28 [32];
  
                    /* 0x3d7f50  12368  ?getOrigin@OdDgArc3d@@UEBAXAEAVOdGePoint3d@@@Z */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc3D::RTTI_Type_Descriptor,0);
  puVar3 = (undefined8 *)(**(code **)(*plVar2 + 0x670))(plVar2,local_28);
  uVar1 = puVar3[1];
  *(undefined8 *)param_1 = *puVar3;
  *(undefined8 *)(param_1 + 8) = uVar1;
  *(undefined8 *)(param_1 + 0x10) = puVar3[2];
  return;
}



/* ==== 1803d8a10 getRotation ==== */

/* public: virtual class OdGeQuaternion __cdecl OdDgArc3d::getRotation(void)const __ptr64 */

void __thiscall OdDgArc3d::getRotation(OdDgArc3d *this)

{
  longlong *plVar1;
  
                    /* 0x3d8a10  13057  ?getRotation@OdDgArc3d@@UEBA?AVOdGeQuaternion@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc3D::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x660))(plVar1);
  return;
}



/* ==== 1803d8a60 getRotationAngle ==== */

/* public: virtual double __cdecl OdDgArc2d::getRotationAngle(void)const __ptr64 */

double __thiscall OdDgArc2d::getRotationAngle(OdDgArc2d *this)

{
  longlong *plVar1;
  double *pdVar2;
  
                    /* 0x3d8a60  13076  ?getRotationAngle@OdDgArc2d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc2D::RTTI_Type_Descriptor,0);
  pdVar2 = (double *)(**(code **)(*plVar1 + 0x660))(plVar1);
  return *pdVar2;
}



/* ==== 1803d8d50 getStartAngle ==== */

/* public: virtual double __cdecl OdDgArc2d::getStartAngle(void)const __ptr64 */

double __thiscall OdDgArc2d::getStartAngle(OdDgArc2d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x3d8d50  13481  ?getStartAngle@OdDgArc2d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc2D::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001803d8d7f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x600))(plVar1);
  return dVar2;
}



/* ==== 1803d8d90 getStartAngle ==== */

/* public: virtual double __cdecl OdDgArc3d::getStartAngle(void)const __ptr64 */

double __thiscall OdDgArc3d::getStartAngle(OdDgArc3d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x3d8d90  13482  ?getStartAngle@OdDgArc3d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &EArc3D::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001803d8dbf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x600))(plVar1);
  return dVar2;
}



/* ==== 1803e3f70 getOrigin ==== */

/* public: class OdGePoint3d __cdecl OdDgRasterHeader2d::getOrigin(void)const __ptr64 */

void __thiscall OdDgRasterHeader2d::getOrigin(OdDgRasterHeader2d *this)

{
  longlong *plVar1;
  
                    /* 0x3e3f70  12377  ?getOrigin@OdDgRasterHeader2d@@QEBA?AVOdGePoint3d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &ERasterHeader2D::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x750))(plVar1);
  return;
}



/* ==== 1803e3fc0 getOrigin ==== */

/* public: class OdGePoint3d __cdecl OdDgRasterHeader3d::getOrigin(void)const __ptr64 */

void __thiscall OdDgRasterHeader3d::getOrigin(OdDgRasterHeader3d *this)

{
  longlong *plVar1;
  
                    /* 0x3e3fc0  12378  ?getOrigin@OdDgRasterHeader3d@@QEBA?AVOdGePoint3d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &ERasterHeader3D::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x750))(plVar1);
  return;
}



/* ==== 180403150 getRotation ==== */

/* public: virtual class OdGeQuaternion __cdecl OdDgOle2Frame3d::getRotation(void)const __ptr64 */

void __thiscall OdDgOle2Frame3d::getRotation(OdDgOle2Frame3d *this)

{
  longlong *plVar1;
  
                    /* 0x403150  13066  ?getRotation@OdDgOle2Frame3d@@UEBA?AVOdGeQuaternion@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgOle2Frame3dImpl::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x7a0))(plVar1);
  return;
}



/* ==== 1804031a0 getRotationAngle ==== */

/* public: virtual double __cdecl OdDgOle2Frame2d::getRotationAngle(void)const __ptr64 */

double __thiscall OdDgOle2Frame2d::getRotationAngle(OdDgOle2Frame2d *this)

{
  longlong *plVar1;
  double dVar2;
  
                    /* 0x4031a0  13079  ?getRotationAngle@OdDgOle2Frame2d@@UEBANXZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgOle2Frame2dImpl::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001804031cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  dVar2 = (double)(**(code **)(*plVar1 + 0x778))(plVar1);
  return dVar2;
}



/* ==== 180414a30 getOrigin ==== */

/* public: virtual class OdGePoint3d __cdecl OdDgACS::getOrigin(void)const __ptr64 */

void __thiscall OdDgACS::getOrigin(OdDgACS *this)

{
  longlong *plVar1;
  
                    /* 0x414a30  12363  ?getOrigin@OdDgACS@@UEBA?AVOdGePoint3d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgACSImpl::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x620))(plVar1);
  return;
}



/* ==== 180414a80 getRotation ==== */

/* public: virtual class OdGeMatrix3d __cdecl OdDgACS::getRotation(void)const __ptr64 */

void __thiscall OdDgACS::getRotation(OdDgACS *this)

{
  longlong *plVar1;
  
                    /* 0x414a80  13055  ?getRotation@OdDgACS@@UEBA?AVOdGeMatrix3d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgACSImpl::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x630))(plVar1);
  return;
}



/* ==== 180438e30 getOrigin ==== */

/* public: virtual class OdGePoint3d __cdecl OdDgSectionClip::getOrigin(void)const __ptr64 */

void __thiscall OdDgSectionClip::getOrigin(OdDgSectionClip *this)

{
  longlong *plVar1;
  
                    /* 0x438e30  12379  ?getOrigin@OdDgSectionClip@@UEBA?AVOdGePoint3d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgSectionClipImpl::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x6c0))(plVar1);
  return;
}



/* ==== 180438f00 getRotation ==== */

/* public: virtual class OdGeMatrix3d __cdecl OdDgSectionClip::getRotation(void)const __ptr64 */

void __thiscall OdDgSectionClip::getRotation(OdDgSectionClip *this)

{
  longlong *plVar1;
  
                    /* 0x438f00  13069  ?getRotation@OdDgSectionClip@@UEBA?AVOdGeMatrix3d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgSectionClipImpl::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x6b0))(plVar1);
  return;
}



/* ==== 18049a0a0 getOrigin ==== */

/* public: virtual class OdGePoint3d __cdecl OdDgTableElement::getOrigin(void)const __ptr64 */

void __thiscall OdDgTableElement::getOrigin(OdDgTableElement *this)

{
  longlong *plVar1;
  
                    /* 0x49a0a0  12383  ?getOrigin@OdDgTableElement@@UEBA?AVOdGePoint3d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgTableElementImpl::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x680))(plVar1);
  return;
}



/* ==== 18049a2e0 getRotation ==== */

/* public: virtual class OdGeMatrix3d __cdecl OdDgTableElement::getRotation(void)const __ptr64 */

void __thiscall OdDgTableElement::getRotation(OdDgTableElement *this)

{
  longlong *plVar1;
  
                    /* 0x49a2e0  13071  ?getRotation@OdDgTableElement@@UEBA?AVOdGeMatrix3d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgTableElementImpl::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x690))(plVar1);
  return;
}



/* ==== 1804c4570 getOriginalFormat ==== */

/* public: unsigned long __cdecl OdDgDesignFileHeaderData::getOriginalFormat(void)const __ptr64 */

ulong __thiscall OdDgDesignFileHeaderData::getOriginalFormat(OdDgDesignFileHeaderData *this)

{
                    /* 0x4c4570  12400  ?getOriginalFormat@OdDgDesignFileHeaderData@@QEBAKXZ */
  return *(ulong *)(this + 0x32c);
}



/* ==== 18051ac10 getOrigin ==== */

/* public: virtual class OdGePoint2d __cdecl OdDgKMLPlacemark2d::getOrigin(void)const __ptr64 */

void __thiscall OdDgKMLPlacemark2d::getOrigin(OdDgKMLPlacemark2d *this)

{
  longlong *plVar1;
  
                    /* 0x51ac10  12374  ?getOrigin@OdDgKMLPlacemark2d@@UEBA?AVOdGePoint2d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgKMLPlacemark2dImpl::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x698))(plVar1);
  return;
}



/* ==== 18051ac60 getOrigin ==== */

/* public: virtual class OdGePoint3d __cdecl OdDgKMLPlacemark3d::getOrigin(void)const __ptr64 */

void __thiscall OdDgKMLPlacemark3d::getOrigin(OdDgKMLPlacemark3d *this)

{
  longlong *plVar1;
  
                    /* 0x51ac60  12375  ?getOrigin@OdDgKMLPlacemark3d@@UEBA?AVOdGePoint3d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgKMLPlacemark3dImpl::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x698))(plVar1);
  return;
}



/* ==== 18051acb0 getRotation ==== */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual double __cdecl OdDgKMLPlacemark2d::getRotation(void)const __ptr64 */

double __thiscall OdDgKMLPlacemark2d::getRotation(OdDgKMLPlacemark2d *this)

{
  double dVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  undefined1 auStack_b8 [32];
  undefined4 local_98;
  undefined8 local_88;
  undefined8 uStack_80;
  OdGeMatrix2d local_78 [16];
  OdGeVector2d local_68 [80];
  ulonglong local_18;
  
                    /* 0x51acb0  13064  ?getRotation@OdDgKMLPlacemark2d@@UEBANXZ */
  local_18 = DAT_180fcd438 ^ (ulonglong)auStack_b8;
  local_98 = 0;
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgKMLPlacemark2dImpl::RTTI_Type_Descriptor);
  (**(code **)(*plVar2 + 0x728))(plVar2,local_68);
  local_88 = *(undefined8 *)kXAxis_exref;
  uStack_80 = *(undefined8 *)(kXAxis_exref + 8);
  puVar3 = (undefined8 *)operator*(local_78,local_68);
  local_88 = *puVar3;
  uStack_80 = puVar3[1];
  dVar1 = OdGeVector2d::angle((OdGeVector2d *)&local_88);
  return dVar1;
}



/* ==== 18051ad50 getRotation ==== */

/* public: virtual class OdGeMatrix3d __cdecl OdDgKMLPlacemark3d::getRotation(void)const __ptr64 */

void __thiscall OdDgKMLPlacemark3d::getRotation(OdDgKMLPlacemark3d *this)

{
  longlong *plVar1;
  
                    /* 0x51ad50  13065  ?getRotation@OdDgKMLPlacemark3d@@UEBA?AVOdGeMatrix3d@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &OdDgKMLPlacemark3dImpl::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x6e0))(plVar1);
  return;
}



/* ==== 180533b40 getOriginalFileVersion ==== */

/* public: unsigned long __cdecl OdDgDatabase::getOriginalFileVersion(unsigned long * __ptr64)const
   __ptr64 */

ulong __thiscall OdDgDatabase::getOriginalFileVersion(OdDgDatabase *this,ulong *param_1)

{
  longlong lVar1;
  
                    /* 0x533b40  12398  ?getOriginalFileVersion@OdDgDatabase@@QEBAKPEAK@Z */
  lVar1 = *(longlong *)(this + 0x10);
  if (param_1 != (ulong *)0x0) {
    *param_1 = *(ulong *)(lVar1 + 3000);
    lVar1 = *(longlong *)(this + 0x10);
  }
  return *(ulong *)(lVar1 + 0xbb4);
}



/* ==== 180533b60 getOriginalFormat ==== */

/* public: virtual enum OdDg::OdDgOriginalFileFormat __cdecl
   OdDgDatabase::getOriginalFormat(void)const __ptr64 */

OdDgOriginalFileFormat __thiscall OdDgDatabase::getOriginalFormat(OdDgDatabase *this)

{
  OdDgOriginalFileFormat OVar1;
  
                    /* 0x533b60  12399
                       ?getOriginalFormat@OdDgDatabase@@UEBA?AW4OdDgOriginalFileFormat@OdDg@@XZ */
  OVar1 = OdDgDesignFileHeaderData::getOriginalFormat
                    ((OdDgDesignFileHeaderData *)(*(longlong *)(this + 0x10) + 0x548));
  return OVar1;
}



/* ==== 18055cd10 getOrigin ==== */

/* public: class OdGePoint3d __cdecl OdDgRasterAttachmentComponentGeo::getOrigin(void)const __ptr64
    */

void __thiscall OdDgRasterAttachmentComponentGeo::getOrigin(OdDgRasterAttachmentComponentGeo *this)

{
  undefined8 uVar1;
  
                    /* 0x55cd10  12376
                       ?getOrigin@OdDgRasterAttachmentComponentGeo@@QEBA?AVOdGePoint3d@@XZ */
  uVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &ERasterRefCompGeo::RTTI_Type_Descriptor,0);
  FUN_1803a8d30(uVar1);
  return;
}



/* ==== 18055ce50 getRotation ==== */

/* public: double __cdecl OdDgRasterAttachmentComponentGeo::getRotation(void)const __ptr64 */

double __thiscall
OdDgRasterAttachmentComponentGeo::getRotation(OdDgRasterAttachmentComponentGeo *this)

{
  undefined8 uVar1;
  double dVar2;
  
                    /* 0x55ce50  13067  ?getRotation@OdDgRasterAttachmentComponentGeo@@QEBANXZ */
  uVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &ERasterRefCompGeo::RTTI_Type_Descriptor,0);
  dVar2 = (double)FUN_1800a14a0(uVar1);
  return dVar2;
}



/* ==== 18057f080 getOrigin ==== */

/* public: class OdGePoint3d __cdecl OdDgView::getOrigin(void)const __ptr64 */

void __thiscall OdDgView::getOrigin(OdDgView *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 *in_RDX;
  
                    /* 0x57f080  12389  ?getOrigin@OdDgView@@QEBA?AVOdGePoint3d@@XZ */
  lVar3 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &CDGView::RTTI_Type_Descriptor,0);
  uVar2 = *(undefined8 *)(lVar3 + 0x4b0);
  uVar1 = *(undefined8 *)(lVar3 + 0x4b8);
  *in_RDX = *(undefined8 *)(lVar3 + 0x4a8);
  in_RDX[1] = uVar2;
  in_RDX[2] = uVar1;
  return;
}



/* ==== 180592760 getOriginCellName ==== */

/* public: virtual class OdString __cdecl OdDgDimStyleTableRecord::getOriginCellName(void)const
   __ptr64 */

void __thiscall OdDgDimStyleTableRecord::getOriginCellName(OdDgDimStyleTableRecord *this)

{
  longlong *plVar1;
  
                    /* 0x592760  12394
                       ?getOriginCellName@OdDgDimStyleTableRecord@@UEBA?AVOdString@@XZ */
  plVar1 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGDimStyle::RTTI_Type_Descriptor,0);
  (**(code **)(*plVar1 + 0x1548))(plVar1);
  return;
}



/* ==== 1805927b0 getOriginChar ==== */

/* public: virtual unsigned short __cdecl OdDgDimStyleTableRecord::getOriginChar(void)const __ptr64
    */

ushort __thiscall OdDgDimStyleTableRecord::getOriginChar(OdDgDimStyleTableRecord *this)

{
  ushort uVar1;
  longlong *plVar2;
  
                    /* 0x5927b0  12395  ?getOriginChar@OdDgDimStyleTableRecord@@UEBAGXZ */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGDimStyle::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x0001805927df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*plVar2 + 0xa98))(plVar2);
  return uVar1;
}



/* ==== 1805927f0 getOriginFont ==== */

/* public: virtual unsigned long __cdecl OdDgDimStyleTableRecord::getOriginFont(void)const __ptr64
    */

ulong __thiscall OdDgDimStyleTableRecord::getOriginFont(OdDgDimStyleTableRecord *this)

{
  ulong uVar1;
  longlong *plVar2;
  
                    /* 0x5927f0  12396  ?getOriginFont@OdDgDimStyleTableRecord@@UEBAKXZ */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGDimStyle::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x00018059281f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*plVar2 + 0xa58))(plVar2);
  return uVar1;
}



/* ==== 180592830 getOriginSymbolType ==== */

/* public: virtual enum OdDgDimOptionTerminators::TerminatorStyle __cdecl
   OdDgDimStyleTableRecord::getOriginSymbolType(void)const __ptr64 */

TerminatorStyle __thiscall
OdDgDimStyleTableRecord::getOriginSymbolType(OdDgDimStyleTableRecord *this)

{
  TerminatorStyle TVar1;
  longlong *plVar2;
  
                    /* 0x592830  12397
                       ?getOriginSymbolType@OdDgDimStyleTableRecord@@UEBA?AW4TerminatorStyle@OdDgDimOptionTerminators@@XZ
                        */
  plVar2 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGDimStyle::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x00018059285f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  TVar1 = (**(code **)(*plVar2 + 0x1018))(plVar2);
  return TVar1;
}



/* ==== 1805a5c00 getOriginCap ==== */

/* public: void __cdecl OdDgMultilineStyleTableRecord::getOriginCap(class OdDgMultilineSymbology &
   __ptr64)const __ptr64 */

void __thiscall
OdDgMultilineStyleTableRecord::getOriginCap
          (OdDgMultilineStyleTableRecord *this,OdDgMultilineSymbology *param_1)

{
  undefined8 uVar1;
  longlong lVar2;
  
                    /* 0x5a5c00  12391
                       ?getOriginCap@OdDgMultilineStyleTableRecord@@QEBAXAEAVOdDgMultilineSymbology@@@Z
                        */
  lVar2 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &CDGMultiLineStyle::RTTI_Type_Descriptor,0);
  uVar1 = *(undefined8 *)(lVar2 + 600);
  *(undefined8 *)param_1 = *(undefined8 *)(lVar2 + 0x250);
  *(undefined8 *)(param_1 + 8) = uVar1;
  uVar1 = *(undefined8 *)(lVar2 + 0x268);
  *(undefined8 *)(param_1 + 0x10) = *(undefined8 *)(lVar2 + 0x260);
  *(undefined8 *)(param_1 + 0x18) = uVar1;
  uVar1 = *(undefined8 *)(lVar2 + 0x278);
  *(undefined8 *)(param_1 + 0x20) = *(undefined8 *)(lVar2 + 0x270);
  *(undefined8 *)(param_1 + 0x28) = uVar1;
  return;
}



/* ==== 1805a5c50 getOriginCapAngle ==== */

/* public: double __cdecl OdDgMultilineStyleTableRecord::getOriginCapAngle(void)const __ptr64 */

double __thiscall
OdDgMultilineStyleTableRecord::getOriginCapAngle(OdDgMultilineStyleTableRecord *this)

{
  undefined8 uVar1;
  double dVar2;
  
                    /* 0x5a5c50  12393  ?getOriginCapAngle@OdDgMultilineStyleTableRecord@@QEBANXZ */
  uVar1 = __RTDynamicCast(*(undefined8 *)(this + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &CDGMultiLineStyle::RTTI_Type_Descriptor,0);
  dVar2 = (double)FUN_180290140(uVar1);
  return dVar2;
}



/* ==== 1805c8540 getRotationAngle ==== */

/* public: double __cdecl OdDgLinePointResourceSymInfo::getRotationAngle(void)const __ptr64 */

double __thiscall OdDgLinePointResourceSymInfo::getRotationAngle(OdDgLinePointResourceSymInfo *this)

{
                    /* 0x5c8540  13078  ?getRotationAngle@OdDgLinePointResourceSymInfo@@QEBANXZ */
  return (*(double *)(this + 0x38) * 3.141592653589793) / 180.0;
}



/* ==== 180685170 getOrigin ==== */

/* public: virtual class OdGePoint3d __cdecl OdDgAcsXAttributeImpl::getOrigin(void)const __ptr64 */

void __thiscall OdDgAcsXAttributeImpl::getOrigin(OdDgAcsXAttributeImpl *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 *in_RDX;
  
                    /* 0x685170  12364  ?getOrigin@OdDgAcsXAttributeImpl@@UEBA?AVOdGePoint3d@@XZ
                       0x685170  12380
                       ?getOrigin@OdDgSectionClipDataExtXAttributeImpl@@UEBA?AVOdGePoint3d@@XZ
                       0x685170  12639
                       ?getPoint3dValue@OdDgTemplateValueVariant@@QEBA?AVOdGePoint3d@@XZ
                       0x685170  12825
                       ?getProjectionOffset@OdDgMatProjectionXAttributeImpl@@UEBA?AVOdGePoint3d@@XZ
                        */
  uVar2 = *(undefined8 *)(this + 0x18);
  uVar1 = *(undefined8 *)(this + 0x20);
  *in_RDX = *(undefined8 *)(this + 0x10);
  in_RDX[1] = uVar2;
  in_RDX[2] = uVar1;
  return;
}



/* ==== 1808296e0 getRotation2d ==== */

/* public: void __cdecl OdDgHatchPattern::getRotation2d(class OdGeMatrix2d & __ptr64)const __ptr64
    */

void __thiscall OdDgHatchPattern::getRotation2d(OdDgHatchPattern *this,OdGeMatrix2d *param_1)

{
  undefined8 local_28;
  undefined8 uStack_20;
  undefined8 local_18;
  undefined8 uStack_10;
  
                    /* 0x8296e0  13052  ?getRotation2d@OdDgHatchPattern@@QEBAXAEAVOdGeMatrix2d@@@Z
                        */
  (**(code **)(*(longlong *)this + 0x80))(this,&local_28);
  *(undefined8 *)param_1 = local_28;
  *(undefined8 *)(param_1 + 8) = uStack_20;
  *(undefined8 *)(param_1 + 0x18) = local_18;
  *(undefined8 *)(param_1 + 0x20) = uStack_10;
  return;
}



/* ==== 180843720 getRotation ==== */

/* public: virtual class OdGeMatrix3d __cdecl OdDgAcsXAttributeImpl::getRotation(void)const __ptr64
    */

void __thiscall OdDgAcsXAttributeImpl::getRotation(OdDgAcsXAttributeImpl *this)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 *in_RDX;
  
                    /* 0x843720  13056  ?getRotation@OdDgAcsXAttributeImpl@@UEBA?AVOdGeMatrix3d@@XZ
                        */
  uVar1 = *(undefined8 *)(this + 0x30);
  uVar2 = *(undefined8 *)(this + 0x38);
  uVar3 = *(undefined8 *)(this + 0x40);
  *in_RDX = *(undefined8 *)(this + 0x28);
  in_RDX[1] = uVar1;
  uVar1 = *(undefined8 *)(this + 0x48);
  uVar4 = *(undefined8 *)(this + 0x50);
  in_RDX[2] = uVar2;
  in_RDX[3] = uVar3;
  uVar2 = *(undefined8 *)(this + 0x58);
  uVar3 = *(undefined8 *)(this + 0x60);
  in_RDX[4] = uVar1;
  in_RDX[5] = uVar4;
  uVar1 = *(undefined8 *)(this + 0x68);
  uVar4 = *(undefined8 *)(this + 0x70);
  in_RDX[6] = uVar2;
  in_RDX[7] = uVar3;
  uVar2 = *(undefined8 *)(this + 0x78);
  uVar3 = *(undefined8 *)(this + 0x80);
  in_RDX[8] = uVar1;
  in_RDX[9] = uVar4;
  uVar1 = *(undefined8 *)(this + 0x88);
  uVar4 = *(undefined8 *)(this + 0x90);
  in_RDX[10] = uVar2;
  in_RDX[0xb] = uVar3;
  uVar2 = *(undefined8 *)(this + 0x98);
  uVar3 = *(undefined8 *)(this + 0xa0);
  in_RDX[0xc] = uVar1;
  in_RDX[0xd] = uVar4;
  in_RDX[0xe] = uVar2;
  in_RDX[0xf] = uVar3;
  return;
}



