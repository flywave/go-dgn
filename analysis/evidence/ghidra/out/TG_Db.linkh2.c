/* ==== 1800396f0 FUN_1800396f0 ==== */

undefined8
FUN_1800396f0(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  longlong *plVar1;
  _func_void *p_Var2;
  longlong *plVar3;
  longlong *local_res20;
  longlong *plVar4;
  undefined1 local_30 [24];
  
  plVar1 = (longlong *)odrxAlloc();
  if (plVar1 == (longlong *)0x0) {
    p_Var2 = std::get_new_handler();
    if (p_Var2 == (_func_void *)0x0) {
      FUN_1800044e0(local_30);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_30,(ThrowInfo *)&DAT_180de5280);
    }
    (*p_Var2)();
  }
  plVar3 = (longlong *)0x0;
  if (plVar1 != (longlong *)0x0) {
    *plVar1 = (longlong)OdRxObjectImpl<OdDgBrepLinkage,OdDgBrepLinkage>::vftable;
    *(undefined4 *)(plVar1 + 1) = 0xffffffff;
    *(undefined4 *)(plVar1 + 1) = 0;
    LOCK();
    *(undefined4 *)(plVar1 + 1) = 1;
    UNLOCK();
    *plVar1 = (longlong)OdDgBrepLinkageImpl::vftable;
    plVar3 = plVar1 + 2;
    *plVar3 = (longlong)CDGAttribEmbeddedBRep::vftable;
    *(undefined4 *)(plVar1 + 3) = 4;
    plVar1[4] = 0;
    local_res20 = plVar1;
    plVar4 = plVar3;
    OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader
              ((OdDgAttributeLinkageHeader *)(plVar1 + 5));
    (**(code **)(plVar1[5] + 0x18))(plVar1 + 5,0x522e);
    OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader
              ((OdDgAttributeLinkageHeader *)(plVar1 + 7));
    FUN_180014040(plVar3,param_2,param_3,param_4,plVar4);
    *(int *)(plVar1 + 8) = (int)plVar1[6];
    plVar3 = plVar1;
  }
  local_res20 = plVar3;
  FUN_1800203e0(param_1,&local_res20);
  if (plVar3 != (longlong *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return param_1;
}



/* ==== 18003be90 FUN_18003be90 ==== */

longlong * FUN_18003be90(longlong *param_1,__uint64 param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  longlong *plVar4;
  OdRxClass *pOVar5;
  longlong lVar6;
  OdRxClass *pOVar7;
  longlong *plVar8;
  ulonglong uVar9;
  longlong *local_38;
  longlong *local_30;
  longlong *local_28 [2];
  
  uVar9 = (ulonglong)param_3;
  uVar1 = FUN_1808af400(param_2,param_3);
  plVar4 = (longlong *)0x0;
  plVar8 = (longlong *)0x0;
  switch(uVar1) {
  case 0:
    uVar3 = OdFlatMemStream::createNew(&local_38,param_2,uVar9);
    FUN_180020460(local_28,uVar3);
    if (local_38 != (longlong *)0x0) {
      (**(code **)(*local_38 + 0x28))();
      local_38 = (longlong *)0x0;
    }
    FUN_18003b6c0(&local_30);
    iVar2 = FUN_1808af540(local_30 + 2,local_28[0]);
    if ((iVar2 == 0) && (plVar4 = plVar8, local_30 != (longlong *)0x0)) {
      lVar6 = *local_30;
      pOVar5 = OdDgDependencyLinkage::desc();
      plVar4 = (longlong *)(**(code **)(lVar6 + 8))(local_30,pOVar5);
      if (plVar4 == (longlong *)0x0) {
        pOVar5 = OdDgDependencyLinkage::desc();
        pOVar7 = (OdRxClass *)(**(code **)(*local_30 + 0x18))(local_30);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_38,pOVar7,pOVar5);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_38,(ThrowInfo *)&DAT_180de5310);
      }
    }
    if (local_30 != (longlong *)0x0) {
      (**(code **)(*local_30 + 0x28))(local_30);
    }
    if (local_28[0] != (longlong *)0x0) {
      (**(code **)(*local_28[0] + 0x28))(local_28[0]);
    }
    break;
  case 1:
    uVar3 = OdFlatMemStream::createNew(&local_38,param_2,uVar9);
    FUN_180020460(&local_30,uVar3);
    if (local_38 != (longlong *)0x0) {
      (**(code **)(*local_38 + 0x28))();
      local_38 = (longlong *)0x0;
    }
    FUN_18003b850(local_28);
    iVar2 = FUN_1808af540(local_28[0] + 2,local_30);
    if ((iVar2 == 0) && (plVar4 = plVar8, local_28[0] != (longlong *)0x0)) {
      lVar6 = *local_28[0];
      pOVar5 = OdDgDependencyLinkage::desc();
      plVar4 = (longlong *)(**(code **)(lVar6 + 8))(local_28[0],pOVar5);
      if (plVar4 == (longlong *)0x0) {
        pOVar5 = OdDgDependencyLinkage::desc();
        pOVar7 = (OdRxClass *)(**(code **)(*local_28[0] + 0x18))(local_28[0]);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_38,pOVar7,pOVar5);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_38,(ThrowInfo *)&DAT_180de5310);
      }
    }
    if (local_28[0] != (longlong *)0x0) {
      (**(code **)(*local_28[0] + 0x28))(local_28[0]);
    }
    if (local_30 != (longlong *)0x0) {
      (**(code **)(*local_30 + 0x28))(local_30);
    }
    break;
  case 2:
    uVar3 = OdFlatMemStream::createNew(&local_38,param_2,uVar9);
    FUN_180020460(&local_30,uVar3);
    if (local_38 != (longlong *)0x0) {
      (**(code **)(*local_38 + 0x28))();
      local_38 = (longlong *)0x0;
    }
    FUN_18003b530(local_28);
    iVar2 = FUN_1808af540(local_28[0] + 2,local_30);
    if ((iVar2 == 0) && (plVar4 = plVar8, local_28[0] != (longlong *)0x0)) {
      lVar6 = *local_28[0];
      pOVar5 = OdDgDependencyLinkage::desc();
      plVar4 = (longlong *)(**(code **)(lVar6 + 8))(local_28[0],pOVar5);
      if (plVar4 == (longlong *)0x0) {
        pOVar5 = OdDgDependencyLinkage::desc();
        pOVar7 = (OdRxClass *)(**(code **)(*local_28[0] + 0x18))(local_28[0]);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_38,pOVar7,pOVar5);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_38,(ThrowInfo *)&DAT_180de5310);
      }
    }
    if (local_28[0] != (longlong *)0x0) {
      (**(code **)(*local_28[0] + 0x28))(local_28[0]);
    }
    if (local_30 != (longlong *)0x0) {
      (**(code **)(*local_30 + 0x28))(local_30);
    }
    break;
  case 3:
    uVar3 = OdFlatMemStream::createNew(&local_38,param_2,uVar9);
    FUN_180020460(&local_30,uVar3);
    if (local_38 != (longlong *)0x0) {
      (**(code **)(*local_38 + 0x28))();
      local_38 = (longlong *)0x0;
    }
    FUN_18003b3a0(local_28);
    iVar2 = FUN_1808af540(local_28[0] + 2,local_30);
    if ((iVar2 == 0) && (plVar4 = plVar8, local_28[0] != (longlong *)0x0)) {
      lVar6 = *local_28[0];
      pOVar5 = OdDgDependencyLinkage::desc();
      plVar4 = (longlong *)(**(code **)(lVar6 + 8))(local_28[0],pOVar5);
      if (plVar4 == (longlong *)0x0) {
        pOVar5 = OdDgDependencyLinkage::desc();
        pOVar7 = (OdRxClass *)(**(code **)(*local_28[0] + 0x18))(local_28[0]);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_38,pOVar7,pOVar5);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_38,(ThrowInfo *)&DAT_180de5310);
      }
    }
    if (local_28[0] != (longlong *)0x0) {
      (**(code **)(*local_28[0] + 0x28))(local_28[0]);
    }
    if (local_30 != (longlong *)0x0) {
      (**(code **)(*local_30 + 0x28))(local_30);
    }
    break;
  case 4:
    uVar3 = OdFlatMemStream::createNew(&local_38,param_2,uVar9);
    FUN_180020460(&local_30,uVar3);
    if (local_38 != (longlong *)0x0) {
      (**(code **)(*local_38 + 0x28))();
      local_38 = (longlong *)0x0;
    }
    FUN_18003b9e0(local_28);
    iVar2 = FUN_1808af540(local_28[0] + 2,local_30);
    if ((iVar2 == 0) && (plVar4 = plVar8, local_28[0] != (longlong *)0x0)) {
      lVar6 = *local_28[0];
      pOVar5 = OdDgDependencyLinkage::desc();
      plVar4 = (longlong *)(**(code **)(lVar6 + 8))(local_28[0],pOVar5);
      if (plVar4 == (longlong *)0x0) {
        pOVar5 = OdDgDependencyLinkage::desc();
        pOVar7 = (OdRxClass *)(**(code **)(*local_28[0] + 0x18))(local_28[0]);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_38,pOVar7,pOVar5);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_38,(ThrowInfo *)&DAT_180de5310);
      }
    }
    if (local_28[0] != (longlong *)0x0) {
      (**(code **)(*local_28[0] + 0x28))(local_28[0]);
    }
    if (local_30 != (longlong *)0x0) {
      (**(code **)(*local_30 + 0x28))(local_30);
    }
    break;
  case 5:
    uVar3 = OdFlatMemStream::createNew(&local_38,param_2,uVar9);
    FUN_180020460(&local_30,uVar3);
    if (local_38 != (longlong *)0x0) {
      (**(code **)(*local_38 + 0x28))();
      local_38 = (longlong *)0x0;
    }
    FUN_18003bb70(local_28);
    iVar2 = FUN_1808af540(local_28[0] + 2,local_30);
    if ((iVar2 == 0) && (plVar4 = plVar8, local_28[0] != (longlong *)0x0)) {
      lVar6 = *local_28[0];
      pOVar5 = OdDgDependencyLinkage::desc();
      plVar4 = (longlong *)(**(code **)(lVar6 + 8))(local_28[0],pOVar5);
      if (plVar4 == (longlong *)0x0) {
        pOVar5 = OdDgDependencyLinkage::desc();
        pOVar7 = (OdRxClass *)(**(code **)(*local_28[0] + 0x18))(local_28[0]);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_38,pOVar7,pOVar5);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_38,(ThrowInfo *)&DAT_180de5310);
      }
    }
    if (local_28[0] != (longlong *)0x0) {
      (**(code **)(*local_28[0] + 0x28))(local_28[0]);
    }
    if (local_30 != (longlong *)0x0) {
      (**(code **)(*local_30 + 0x28))(local_30);
    }
    break;
  case 6:
    uVar3 = OdFlatMemStream::createNew(&local_38,param_2,uVar9);
    FUN_180020460(&local_30,uVar3);
    if (local_38 != (longlong *)0x0) {
      (**(code **)(*local_38 + 0x28))();
      local_38 = (longlong *)0x0;
    }
    FUN_18003bd00(local_28);
    iVar2 = FUN_1808af540(local_28[0] + 2,local_30);
    if ((iVar2 == 0) && (plVar4 = plVar8, local_28[0] != (longlong *)0x0)) {
      lVar6 = *local_28[0];
      pOVar5 = OdDgDependencyLinkage::desc();
      plVar4 = (longlong *)(**(code **)(lVar6 + 8))(local_28[0],pOVar5);
      if (plVar4 == (longlong *)0x0) {
        pOVar5 = OdDgDependencyLinkage::desc();
        pOVar7 = (OdRxClass *)(**(code **)(*local_28[0] + 0x18))(local_28[0]);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_38,pOVar7,pOVar5);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_38,(ThrowInfo *)&DAT_180de5310);
      }
    }
    if (local_28[0] != (longlong *)0x0) {
      (**(code **)(*local_28[0] + 0x28))(local_28[0]);
    }
    if (local_30 != (longlong *)0x0) {
      (**(code **)(*local_30 + 0x28))(local_30);
    }
  }
  *param_1 = 0;
  if (plVar4 != (longlong *)0x0) {
    lVar6 = *plVar4;
    pOVar5 = OdDgAttributeLinkage::desc();
    lVar6 = (**(code **)(lVar6 + 8))(plVar4,pOVar5);
    if (lVar6 == 0) {
      pOVar5 = OdDgAttributeLinkage::desc();
      pOVar7 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_28,pOVar7,pOVar5);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_28,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar6;
  }
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 0x28))(plVar4);
  }
  return param_1;
}



/* ==== 18003ef60 FUN_18003ef60 ==== */

longlong * FUN_18003ef60(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  char cVar1;
  OdRxClass *pOVar2;
  longlong lVar3;
  OdRxClass *pOVar4;
  longlong *local_res20;
  OdError_NotThatKindOfClass local_18 [16];
  
  OdDgFilterMemberLinkage::createObject();
  cVar1 = FUN_1808ae520(local_res20,param_2,param_3);
  *param_1 = 0;
  if (cVar1 == '\0') {
    if (local_res20 != (longlong *)0x0) {
      (**(code **)(*local_res20 + 0x28))(local_res20);
    }
    return param_1;
  }
  if (local_res20 != (longlong *)0x0) {
    lVar3 = *local_res20;
    pOVar2 = OdDgAttributeLinkage::desc();
    lVar3 = (**(code **)(lVar3 + 8))(local_res20,pOVar2);
    if (lVar3 == 0) {
      pOVar2 = OdDgAttributeLinkage::desc();
      pOVar4 = (OdRxClass *)(**(code **)(*local_res20 + 0x18))(local_res20);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_18,pOVar4,pOVar2);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_18,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar3;
  }
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))(local_res20);
  }
  return param_1;
}



/* ==== 18081d510 FUN_18081d510 ==== */

longlong * FUN_18081d510(longlong *param_1,__uint64 param_2,uint param_3)

{
  undefined1 uVar1;
  undefined1 uVar2;
  longlong *plVar3;
  OdRxClass *pOVar4;
  longlong *plVar5;
  longlong *plVar6;
  longlong lVar7;
  OdRxClass *pOVar8;
  ulong local_res18 [2];
  longlong *local_res20;
  longlong *local_38;
  OdError_NotThatKindOfClass local_30 [8];
  OdDgAttributeLinkageHeader local_28 [16];
  
  plVar3 = (longlong *)OdFlatMemStream::createNew(&local_res20,param_2,(ulonglong)param_3);
  local_38 = (longlong *)0x0;
  plVar3 = (longlong *)*plVar3;
  plVar5 = local_38;
  if (plVar3 != (longlong *)0x0) {
    lVar7 = *plVar3;
    pOVar4 = OdStreamBuf::desc();
    plVar5 = (longlong *)(**(code **)(lVar7 + 8))(plVar3,pOVar4);
    if (plVar5 == (longlong *)0x0) {
      pOVar4 = OdStreamBuf::desc();
      pOVar8 = (OdRxClass *)(**(code **)(*plVar3 + 0x18))(plVar3);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_38,pOVar8,pOVar4);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_38,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_38 = plVar5;
  plVar3 = local_38;
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))();
    local_res20 = (longlong *)0x0;
  }
  OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader(local_28);
  (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,4);
  OdDgTableElementMerge::setBaseRowIndex((OdDgTableElementMerge *)local_28,local_res18[0]);
  (**(code **)(*plVar3 + 0x88))(plVar3,0xfffffffffffffffe,1);
  OdDgDMRSLinkage::createObject();
  plVar5 = local_res20;
  plVar6 = (longlong *)
           __RTDynamicCast(local_res20,0,&OdDgDMRSLinkage::RTTI_Type_Descriptor,
                           &OdDgDMRSLinkageImpl::RTTI_Type_Descriptor,0);
  if (plVar6 != (longlong *)0x0) {
    (**(code **)(*plVar6 + 0x70))(plVar6,local_28);
  }
  (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,2);
  (**(code **)(*plVar5 + 0x80))(plVar5,(undefined2)local_res18[0]);
  (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,2);
  if (DAT_181021368 == '\0') {
    uVar1 = (**(code **)(*plVar3 + 0x90))(plVar3);
    lVar7 = *plVar5;
    uVar2 = (**(code **)(*plVar3 + 0x90))(plVar3);
    (**(code **)(lVar7 + 0xa0))(plVar5,uVar2);
  }
  else {
    lVar7 = *plVar5;
    uVar1 = (**(code **)(*plVar3 + 0x90))();
    (**(code **)(lVar7 + 0xa0))(plVar5,uVar1);
    uVar1 = (**(code **)(*plVar3 + 0x90))(plVar3);
  }
  (**(code **)(*plVar5 + 0x90))(plVar5,(ulonglong)CONCAT12(uVar1,(undefined2)local_res18[0]));
  *param_1 = 0;
  lVar7 = *plVar5;
  pOVar4 = OdDgAttributeLinkage::desc();
  lVar7 = (**(code **)(lVar7 + 8))(plVar5,pOVar4);
  if (lVar7 == 0) {
    pOVar4 = OdDgAttributeLinkage::desc();
    pOVar8 = (OdRxClass *)(**(code **)(*plVar5 + 0x18))(plVar5);
    OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_30,pOVar8,pOVar4);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_30,(ThrowInfo *)&DAT_180de5310);
  }
  *param_1 = lVar7;
  (**(code **)(*plVar5 + 0x28))(plVar5);
  OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_28);
  (**(code **)(*plVar3 + 0x28))(plVar3);
  return param_1;
}



/* ==== 18082a450 FUN_18082a450 ==== */

longlong * FUN_18082a450(longlong *param_1,__uint64 param_2,uint param_3)

{
  int iVar1;
  OdDgElement *this;
  ushort uVar2;
  ushort uVar3;
  longlong *plVar4;
  OdRxClass *pOVar5;
  longlong *plVar6;
  longlong lVar7;
  longlong *plVar8;
  OdRxClass *pOVar9;
  uint uVar10;
  code *pcVar11;
  ulonglong uVar12;
  uint uVar13;
  code *pcVar14;
  code *pcVar15;
  undefined8 uVar16;
  uint *puVar17;
  uint *puVar18;
  ushort uVar19;
  code *pcVar20;
  bool bVar21;
  undefined4 uVar22;
  undefined4 uVar23;
  ulonglong local_res20;
  longlong *local_1e8;
  code *local_1e0;
  ushort local_1d8 [2];
  ushort local_1d4;
  uint local_1d0;
  ushort local_1cc [2];
  OdDgElement *local_1c8;
  undefined6 local_1c0;
  byte bStack_1ba;
  byte bStack_1b9;
  undefined6 local_1b8;
  byte bStack_1b2;
  byte bStack_1b1;
  undefined6 local_1b0;
  byte bStack_1aa;
  byte bStack_1a9;
  longlong *local_1a8;
  longlong *local_1a0;
  undefined4 local_198;
  undefined4 local_194;
  undefined1 local_190 [8];
  undefined1 local_188 [8];
  undefined1 local_180 [8];
  undefined1 local_178 [8];
  undefined1 local_170 [8];
  undefined6 local_168;
  byte bStack_162;
  byte bStack_161;
  undefined6 local_160;
  byte bStack_15a;
  byte bStack_159;
  undefined6 local_158;
  byte bStack_152;
  byte bStack_151;
  undefined6 local_150;
  byte bStack_14a;
  byte bStack_149;
  undefined1 local_148 [8];
  ulong local_140;
  undefined4 local_13c;
  undefined4 local_138 [2];
  undefined6 local_130;
  byte bStack_12a;
  byte bStack_129;
  undefined6 local_128;
  byte bStack_122;
  byte bStack_121;
  undefined6 local_120;
  byte bStack_11a;
  byte bStack_119;
  undefined6 local_118;
  byte bStack_112;
  byte bStack_111;
  undefined6 local_110;
  byte bStack_10a;
  byte bStack_109;
  undefined6 local_108;
  byte bStack_102;
  byte bStack_101;
  OdDgElement *local_100;
  undefined4 local_f8 [2];
  longlong local_f0;
  longlong *local_e8 [2];
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  uint uStack_c0;
  uint uStack_bc;
  longlong *local_b8;
  longlong *local_b0;
  longlong *local_a8;
  longlong *local_a0;
  longlong local_98;
  longlong *local_90;
  OdDgAttributeLinkageHeader local_88 [16];
  OdError_InvalidIndex local_78 [8];
  undefined8 local_70;
  undefined8 uStack_68;
  
  plVar4 = (longlong *)OdFlatMemStream::createNew(local_e8,param_2,(ulonglong)param_3);
  puVar17 = (uint *)0x0;
  local_1a8 = (longlong *)0x0;
  plVar4 = (longlong *)*plVar4;
  plVar6 = local_1a8;
  if (plVar4 != (longlong *)0x0) {
    lVar7 = *plVar4;
    pOVar5 = OdStreamBuf::desc();
    plVar6 = (longlong *)(**(code **)(lVar7 + 8))(plVar4,pOVar5);
    if (plVar6 == (longlong *)0x0) {
      pOVar5 = OdStreamBuf::desc();
      pOVar9 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_res20,pOVar9,pOVar5);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_1a8 = plVar6;
  plVar4 = local_1a8;
  if (local_e8[0] != (longlong *)0x0) {
    (**(code **)(*local_e8[0] + 0x28))();
    local_e8[0] = (longlong *)0x0;
  }
  OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader(local_88);
  (**(code **)(*plVar4 + 0x98))(plVar4,&local_140,4);
  OdDgTableElementMerge::setBaseRowIndex((OdDgTableElementMerge *)local_88,local_140);
  (**(code **)(*plVar4 + 0x98))(plVar4,&local_1d0,4);
  OdDgPatternLinkage::createObject();
  uVar13 = local_1d0;
  local_1e8 = (longlong *)0x0;
  if ((local_1d0 >> 5 & 1) == 0) {
LAB_18082a5cd:
    if ((uVar13 >> 0xe & 1) != 0) {
      OdDgDWGHatchPattern::createObject();
      lVar7 = __RTDynamicCast(local_b8,0,&OdDgDWGHatchPattern::RTTI_Type_Descriptor,
                              &OdDgDWGHatchPatternImpl::RTTI_Type_Descriptor,0);
      puVar18 = (uint *)(lVar7 + 0x10);
      if (lVar7 == 0) {
        puVar18 = puVar17;
      }
      if (local_1e8 != (longlong *)0x0) {
        (**(code **)(*local_1e8 + 0x28))();
        local_1e8 = (longlong *)0x0;
      }
      plVar6 = local_1e8;
      if (local_b8 != (longlong *)0x0) {
        lVar7 = *local_b8;
        pOVar5 = OdDgHatchPattern::desc();
        plVar6 = (longlong *)(**(code **)(lVar7 + 8))(local_b8,pOVar5);
        if (plVar6 == (longlong *)0x0) {
          pOVar5 = OdDgHatchPattern::desc();
          pOVar9 = (OdRxClass *)(**(code **)(*local_b8 + 0x18))(local_b8);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_res20,pOVar9,pOVar5);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_1e8 = plVar6;
      if (local_b8 != (longlong *)0x0) {
        (**(code **)(*local_b8 + 0x28))(local_b8);
      }
      if (puVar18 != (uint *)0x0) goto LAB_18082a841;
    }
    if ((uVar13 & 1) != 0) {
      if ((uVar13 >> 2 & 1) == 0) {
        plVar6 = (longlong *)OdDgLinearHatchPattern::createObject();
        local_b0 = (longlong *)0x0;
        plVar6 = (longlong *)*plVar6;
        plVar8 = local_b0;
        if (plVar6 != (longlong *)0x0) {
          lVar7 = *plVar6;
          pOVar5 = OdDgLinearHatchPattern::desc();
          plVar8 = (longlong *)(**(code **)(lVar7 + 8))(plVar6,pOVar5);
          if (plVar8 == (longlong *)0x0) {
            pOVar5 = OdDgLinearHatchPattern::desc();
            pOVar9 = (OdRxClass *)(**(code **)(*plVar6 + 0x18))(plVar6);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                      ((OdError_NotThatKindOfClass *)&local_res20,pOVar9,pOVar5);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5310);
          }
        }
        local_b0 = plVar8;
        plVar6 = local_b0;
        if (local_1a0 != (longlong *)0x0) {
          (**(code **)(*local_1a0 + 0x28))();
          local_1a0 = (longlong *)0x0;
        }
        lVar7 = __RTDynamicCast(plVar6,0,&OdDgLinearHatchPattern::RTTI_Type_Descriptor,
                                &OdDgLinearHatchPatternImpl::RTTI_Type_Descriptor,0);
        puVar18 = (uint *)(lVar7 + 0x10);
        if (lVar7 == 0) {
          puVar18 = puVar17;
        }
        if (local_1e8 != (longlong *)0x0) {
          (**(code **)(*local_1e8 + 0x28))();
          local_1e8 = (longlong *)0x0;
        }
        plVar8 = local_1e8;
        if (plVar6 != (longlong *)0x0) {
          lVar7 = *plVar6;
          pOVar5 = OdDgHatchPattern::desc();
          plVar8 = (longlong *)(**(code **)(lVar7 + 8))(plVar6,pOVar5);
          if (plVar8 == (longlong *)0x0) {
            pOVar5 = OdDgHatchPattern::desc();
            pOVar9 = (OdRxClass *)(**(code **)(*plVar6 + 0x18))(plVar6);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                      ((OdError_NotThatKindOfClass *)&local_res20,pOVar9,pOVar5);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5310);
          }
        }
        local_1e8 = plVar8;
        if (plVar6 != (longlong *)0x0) {
          (**(code **)(*plVar6 + 0x28))(plVar6);
        }
      }
      else {
        OdDgCrossHatchPattern::createObject();
        plVar6 = local_1a0;
        lVar7 = __RTDynamicCast(local_1a0,0,&OdDgCrossHatchPattern::RTTI_Type_Descriptor,
                                &OdDgCrossHatchPatternImpl::RTTI_Type_Descriptor,0);
        puVar18 = (uint *)(lVar7 + 0x10);
        if (lVar7 == 0) {
          puVar18 = puVar17;
        }
        if (local_1e8 != (longlong *)0x0) {
          (**(code **)(*local_1e8 + 0x28))();
          local_1e8 = (longlong *)0x0;
        }
        plVar8 = local_1e8;
        if (plVar6 != (longlong *)0x0) {
          lVar7 = *plVar6;
          pOVar5 = OdDgHatchPattern::desc();
          plVar8 = (longlong *)(**(code **)(lVar7 + 8))(plVar6,pOVar5);
          if (plVar8 == (longlong *)0x0) {
            pOVar5 = OdDgHatchPattern::desc();
            pOVar9 = (OdRxClass *)(**(code **)(*plVar6 + 0x18))(plVar6);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                      ((OdError_NotThatKindOfClass *)&local_res20,pOVar9,pOVar5);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5310);
          }
        }
        local_1e8 = plVar8;
        if (plVar6 != (longlong *)0x0) {
          (**(code **)(*plVar6 + 0x28))(plVar6);
        }
      }
      if (puVar18 != (uint *)0x0) goto LAB_18082a841;
    }
    OdDgProxyHatchPattern::createObject();
    lVar7 = __RTDynamicCast(local_a8,0,&OdDgProxyHatchPattern::RTTI_Type_Descriptor,
                            &OdDgProxyHatchPatternImpl::RTTI_Type_Descriptor,0);
    puVar18 = (uint *)(lVar7 + 0x10);
    if (lVar7 == 0) {
      puVar18 = puVar17;
    }
    if (local_1e8 != (longlong *)0x0) {
      (**(code **)(*local_1e8 + 0x28))();
      local_1e8 = (longlong *)0x0;
    }
    plVar6 = local_1e8;
    if (local_a8 != (longlong *)0x0) {
      lVar7 = *local_a8;
      pOVar5 = OdDgHatchPattern::desc();
      plVar6 = (longlong *)(**(code **)(lVar7 + 8))(local_a8,pOVar5);
      if (plVar6 == (longlong *)0x0) {
        pOVar5 = OdDgHatchPattern::desc();
        pOVar9 = (OdRxClass *)(**(code **)(*local_a8 + 0x18))(local_a8);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_res20,pOVar9,pOVar5);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_1e8 = plVar6;
    if (local_a8 != (longlong *)0x0) {
      (**(code **)(*local_a8 + 0x28))(local_a8);
    }
  }
  else {
    OdDgSymbolHatchPattern::createObject();
    lVar7 = __RTDynamicCast(local_a0,0,&OdDgSymbolHatchPattern::RTTI_Type_Descriptor,
                            &OdDgSymbolHatchPatternImpl::RTTI_Type_Descriptor,0);
    puVar18 = (uint *)(lVar7 + 0x10);
    if (lVar7 == 0) {
      puVar18 = puVar17;
    }
    if (local_1e8 != (longlong *)0x0) {
      (**(code **)(*local_1e8 + 0x28))();
      local_1e8 = (longlong *)0x0;
    }
    plVar6 = local_1e8;
    if (local_a0 != (longlong *)0x0) {
      lVar7 = *local_a0;
      pOVar5 = OdDgHatchPattern::desc();
      plVar6 = (longlong *)(**(code **)(lVar7 + 8))(local_a0,pOVar5);
      if (plVar6 == (longlong *)0x0) {
        pOVar5 = OdDgHatchPattern::desc();
        pOVar9 = (OdRxClass *)(**(code **)(*local_a0 + 0x18))(local_a0);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_res20,pOVar9,pOVar5);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_1e8 = plVar6;
    if (local_a0 != (longlong *)0x0) {
      (**(code **)(*local_a0 + 0x28))(local_a0);
    }
    if (puVar18 == (uint *)0x0) goto LAB_18082a5cd;
  }
LAB_18082a841:
  if ((uVar13 & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,local_190,8);
    FUN_18082d370(puVar18);
  }
  if ((uVar13 >> 1 & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,local_188,8);
    FUN_18082c4c0(puVar18);
  }
  if ((uVar13 >> 2 & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,local_180,8);
    FUN_18082d410(puVar18);
  }
  if ((uVar13 >> 3 & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,local_178,8);
    FUN_18082c560(puVar18);
  }
  if ((uVar13 >> 4 & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,local_170,8);
    FUN_18082d210(puVar18);
  }
  if ((uVar13 >> 6 & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,local_148,8);
    FUN_18082d540(puVar18);
  }
  if ((uVar13 >> 7 & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_194,4);
    FUN_18082ca00(puVar18,local_194);
  }
  if ((uVar13 >> 8 & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_13c,4);
    FUN_18082cab0(puVar18,local_13c);
  }
  if ((uVar13 >> 9 & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,local_138,4);
    FUN_18082c970(puVar18,local_138[0]);
  }
  if ((uVar13 >> 0xb & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_168,8);
    uVar10 = (bStack_161 & 0x7f) << 4 | (uint)(bStack_162 >> 4);
    if ((uVar10 == 0) || (uVar10 == 0x7ff)) {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      uVar22 = (undefined4)local_168;
      uVar23 = (undefined4)(CONCAT17(bStack_161,CONCAT16(bStack_162,local_168)) >> 0x20);
    }
    local_d8 = CONCAT44(uVar23,uVar22);
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_160,8);
    uVar10 = (bStack_159 & 0x7f) << 4 | (uint)(bStack_15a >> 4);
    if ((uVar10 == 0) || (uVar10 == 0x7ff)) {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      uVar22 = (undefined4)local_160;
      uVar23 = (undefined4)(CONCAT17(bStack_159,CONCAT16(bStack_15a,local_160)) >> 0x20);
    }
    uStack_d0 = CONCAT44(uVar23,uVar22);
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_158,8);
    uVar10 = (bStack_151 & 0x7f) << 4 | (uint)(bStack_152 >> 4);
    if ((uVar10 == 0) || (uVar10 == 0x7ff)) {
      local_c8._0_4_ = 0;
      local_c8._4_4_ = 0;
    }
    else {
      local_c8._0_4_ = (uint)local_158;
      local_c8._4_4_ = (uint)(CONCAT17(bStack_151,CONCAT16(bStack_152,local_158)) >> 0x20);
    }
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_150,8);
    uVar10 = (bStack_149 & 0x7f) << 4 | (uint)(bStack_14a >> 4);
    if ((uVar10 == 0) || (uVar10 == 0x7ff)) {
      uVar16 = 0;
    }
    else {
      uVar16 = CONCAT17(bStack_149,CONCAT16(bStack_14a,local_150));
    }
    *(undefined8 *)(puVar18 + 0x14) = local_d8;
    *(undefined8 *)(puVar18 + 0x16) = uStack_d0;
    uStack_c0 = (uint)uVar16;
    uStack_bc = (uint)((ulonglong)uVar16 >> 0x20);
    puVar18[0x18] = (uint)local_c8;
    puVar18[0x19] = local_c8._4_4_;
    puVar18[0x1a] = uStack_c0;
    puVar18[0x1b] = uStack_bc;
    if (*(longlong *)(puVar18 + 0x32) != 0) {
      local_f0 = *(longlong *)(puVar18 + 0x32);
      OdDgElementId::openObject((OdDgElementId *)&local_f0,(OpenMode)&local_1c8,true);
      if (local_1c8 != (OdDgElement *)0x0) {
        OdDgElement::assertWriteEnabled(local_1c8,true,true);
        plVar6 = *(longlong **)(local_1c8 + 8);
        if (plVar6 != (longlong *)0x0) {
          (**(code **)(*plVar6 + 0x310))(plVar6,1);
        }
      }
      if (local_1c8 != (OdDgElement *)0x0) {
        (**(code **)(*(longlong *)local_1c8 + 0x28))();
      }
    }
    *puVar18 = *puVar18 | 0x800;
  }
  if ((uVar13 >> 0xc & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_1c0,8);
    uVar10 = (bStack_1b9 & 0x7f) << 4 | (uint)(bStack_1ba >> 4);
    if ((uVar10 == 0) || (uVar10 == 0x7ff)) {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      uVar22 = (undefined4)local_1c0;
      uVar23 = (undefined4)(CONCAT17(bStack_1b9,CONCAT16(bStack_1ba,local_1c0)) >> 0x20);
    }
    local_70 = CONCAT44(uVar23,uVar22);
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_1b8,8);
    uVar10 = (bStack_1b1 & 0x7f) << 4 | (uint)(bStack_1b2 >> 4);
    if ((uVar10 == 0) || (uVar10 == 0x7ff)) {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      uVar22 = (undefined4)local_1b8;
      uVar23 = (undefined4)(CONCAT17(bStack_1b1,CONCAT16(bStack_1b2,local_1b8)) >> 0x20);
    }
    uStack_68 = CONCAT44(uVar23,uVar22);
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_1b0,8);
    uVar10 = (bStack_1a9 & 0x7f) << 4 | (uint)(bStack_1aa >> 4);
    if ((uVar10 == 0) || (uVar10 == 0x7ff)) {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      uVar22 = (undefined4)local_1b0;
      uVar23 = (undefined4)(CONCAT17(bStack_1a9,CONCAT16(bStack_1aa,local_1b0)) >> 0x20);
    }
    local_d8 = local_70;
    uStack_d0 = uStack_68;
    local_c8 = CONCAT44(uVar23,uVar22);
    FUN_18082cd70(puVar18,&local_d8);
  }
  if ((uVar13 >> 0xf & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,local_f8,4);
    FUN_18082cc60(puVar18,local_f8[0]);
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_198,4);
    FUN_18082cb50(puVar18,local_198);
  }
  if ((uVar13 >> 0xd & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_res20,2);
    FUN_18082c820(puVar18,local_res20 & 0xffff);
  }
  pcVar20 = g_empty_array_buffer_exref;
  if ((uVar13 >> 0xe & 1) == 0) goto LAB_18082b2c9;
  local_1e0 = g_empty_array_buffer_exref + 0x10;
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  (**(code **)(*local_1a8 + 0x98))(local_1a8,local_1cc,2);
  pcVar15 = local_1e0;
  local_1d4 = local_1cc[0];
  uVar13 = *(uint *)(local_1e0 + -4);
  uVar10 = local_1cc[0] - uVar13;
  uVar12 = (ulonglong)uVar10;
  if ((int)uVar10 < 1) {
    if ((int)uVar10 < 0) {
      LOCK();
      iVar1 = *(int *)pcVar20;
      *(undefined4 *)pcVar20 = *(undefined4 *)pcVar20;
      UNLOCK();
      if (iVar1 < 2) {
        FUN_1806079d0(local_1e0 + (ulonglong)local_1cc[0] * 0x30,-uVar10);
      }
      else {
        FUN_1804f9c10(&local_1e0,(uint)local_1cc[0],0,0,1);
        pcVar15 = local_1e0;
      }
    }
  }
  else {
    LOCK();
    iVar1 = *(int *)pcVar20;
    *(undefined4 *)pcVar20 = *(undefined4 *)pcVar20;
    UNLOCK();
    if (iVar1 < 2) {
      if (*(uint *)(local_1e0 + -8) < uVar10 + uVar13) {
        uVar16 = 1;
        goto LAB_18082ae31;
      }
    }
    else {
      uVar16 = 0;
LAB_18082ae31:
      FUN_1804f9c10(&local_1e0,uVar10 + uVar13,uVar16,0,1);
    }
    pcVar15 = local_1e0;
    if (uVar10 != 0) {
      pcVar20 = local_1e0 + uVar12 * 0x30 + 0x20 + (ulonglong)uVar13 * 0x30;
      do {
        *(undefined8 *)(pcVar20 + -0x50) = 0;
        *(undefined8 *)(pcVar20 + -0x48) = 0;
        *(undefined8 *)(pcVar20 + -0x40) = 0;
        *(undefined8 *)(pcVar20 + -0x38) = 0;
        *(undefined8 *)(pcVar20 + -0x30) = 0;
        pcVar14 = g_empty_array_buffer_exref;
        *(code **)(pcVar20 + -0x28) = g_empty_array_buffer_exref + 0x10;
        LOCK();
        *(int *)pcVar14 = *(int *)pcVar14 + 1;
        UNLOCK();
        uVar13 = (int)uVar12 - 1;
        uVar12 = (ulonglong)uVar13;
        pcVar20 = pcVar20 + -0x30;
      } while (uVar13 != 0);
    }
  }
  *(uint *)(pcVar15 + -4) = (uint)local_1cc[0];
  uVar3 = 0;
  bVar21 = local_1cc[0] != 0;
  while (bVar21) {
    if (*(uint *)(pcVar15 + -4) <= (uint)uVar3) {
      OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)&local_res20);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5370);
    }
    LOCK();
    pcVar15 = pcVar15 + -0x10;
    iVar1 = *(int *)pcVar15;
    *(int *)pcVar15 = *(int *)pcVar15;
    UNLOCK();
    if (1 < iVar1) {
      FUN_1804f9c10(&local_1e0,*(undefined4 *)(local_1e0 + -8),0,0,1);
    }
    plVar4 = local_1a8;
    pcVar15 = local_1e0;
    pcVar20 = local_1e0 + (ulonglong)uVar3 * 0x30;
    (**(code **)(*local_1a8 + 0x98))(local_1a8,&local_130,8);
    uVar13 = (bStack_129 & 0x7f) << 4 | (uint)(bStack_12a >> 4);
    if ((uVar13 == 0) || (uVar13 == 0x7ff)) {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      uVar22 = (undefined4)local_130;
      uVar23 = (undefined4)(CONCAT17(bStack_129,CONCAT16(bStack_12a,local_130)) >> 0x20);
    }
    *(ulonglong *)pcVar20 = CONCAT44(uVar23,uVar22);
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_128,8);
    uVar13 = (bStack_121 & 0x7f) << 4 | (uint)(bStack_122 >> 4);
    if ((uVar13 == 0) || (uVar13 == 0x7ff)) {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      uVar22 = (undefined4)local_128;
      uVar23 = (undefined4)(CONCAT17(bStack_121,CONCAT16(bStack_122,local_128)) >> 0x20);
    }
    *(ulonglong *)(pcVar20 + 8) = CONCAT44(uVar23,uVar22);
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_120,8);
    uVar13 = (bStack_119 & 0x7f) << 4 | (uint)(bStack_11a >> 4);
    if ((uVar13 == 0) || (uVar13 == 0x7ff)) {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      uVar22 = (undefined4)local_120;
      uVar23 = (undefined4)(CONCAT17(bStack_119,CONCAT16(bStack_11a,local_120)) >> 0x20);
    }
    *(ulonglong *)(pcVar20 + 0x10) = CONCAT44(uVar23,uVar22);
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_118,8);
    uVar13 = (bStack_111 & 0x7f) << 4 | (uint)(bStack_112 >> 4);
    if ((uVar13 == 0) || (uVar13 == 0x7ff)) {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      uVar22 = (undefined4)local_118;
      uVar23 = (undefined4)(CONCAT17(bStack_111,CONCAT16(bStack_112,local_118)) >> 0x20);
    }
    *(ulonglong *)(pcVar20 + 0x18) = CONCAT44(uVar23,uVar22);
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_110,8);
    uVar13 = (bStack_109 & 0x7f) << 4 | (uint)(bStack_10a >> 4);
    if ((uVar13 == 0) || (uVar13 == 0x7ff)) {
      uVar22 = 0;
      uVar23 = 0;
    }
    else {
      uVar22 = (undefined4)local_110;
      uVar23 = (undefined4)(CONCAT17(bStack_109,CONCAT16(bStack_10a,local_110)) >> 0x20);
    }
    *(ulonglong *)(pcVar20 + 0x20) = CONCAT44(uVar23,uVar22);
    (**(code **)(*plVar4 + 0x98))(plVar4,local_1d8);
    uVar2 = local_1d8[0];
    FUN_180015300(pcVar20 + 0x28,local_1d8[0]);
    uVar19 = 0;
    if (uVar2 != 0) {
      do {
        (**(code **)(*plVar4 + 0x98))(plVar4,&local_108);
        uVar13 = (bStack_101 & 0x7f) << 4 | (uint)(bStack_102 >> 4);
        if ((uVar13 == 0) || (uVar13 == 0x7ff)) {
          uVar22 = 0;
          uVar23 = 0;
        }
        else {
          uVar22 = (undefined4)local_108;
          uVar23 = (undefined4)(CONCAT17(bStack_101,CONCAT16(bStack_102,local_108)) >> 0x20);
        }
        if (*(uint *)(*(longlong *)(pcVar20 + 0x28) + -4) <= (uint)uVar19) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_78);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_78,(ThrowInfo *)&DAT_180de5370);
        }
        FUN_18000d1e0();
        *(ulonglong *)(*(longlong *)(pcVar20 + 0x28) + (ulonglong)uVar19 * 8) =
             CONCAT44(uVar23,uVar22);
        uVar19 = uVar19 + 1;
      } while (uVar19 < uVar2);
    }
    uVar3 = uVar3 + 1;
    bVar21 = uVar3 < local_1d4;
  }
  if ((puVar18 != (uint *)0x0) && (*(longlong *)(puVar18 + 0x32) != 0)) {
    local_98 = *(longlong *)(puVar18 + 0x32);
    OdDgElementId::openObject((OdDgElementId *)&local_98,(OpenMode)&local_100,true);
    if (local_100 != (OdDgElement *)0x0) {
      OdDgElement::assertWriteEnabled(local_100,true,true);
      plVar4 = *(longlong **)(local_100 + 8);
      if (plVar4 != (longlong *)0x0) {
        (**(code **)(*plVar4 + 0x310))(plVar4,1);
      }
    }
    if (local_100 != (OdDgElement *)0x0) {
      (**(code **)(*(longlong *)local_100 + 0x28))();
    }
  }
  pcVar20 = pcVar15 + -0x10;
  LOCK();
  *(int *)pcVar20 = *(int *)pcVar20 + 1;
  UNLOCK();
  lVar7 = *(longlong *)(puVar18 + 0x26);
  pcVar14 = (code *)(lVar7 + -0x10);
  LOCK();
  iVar1 = *(int *)pcVar14;
  *(int *)pcVar14 = *(int *)pcVar14 + -1;
  UNLOCK();
  if ((iVar1 == 1) && (pcVar14 != g_empty_array_buffer_exref)) {
    uVar12 = (ulonglong)*(uint *)(lVar7 + -4);
    if (*(uint *)(lVar7 + -4) != 0) {
      plVar4 = (longlong *)(lVar7 + 0x28 + uVar12 * 0x30);
      do {
        uVar13 = (int)uVar12 - 1;
        uVar12 = (ulonglong)uVar13;
        plVar4 = plVar4 + -6;
        pcVar11 = (code *)(*plVar4 + -0x10);
        LOCK();
        iVar1 = *(int *)pcVar11;
        *(int *)pcVar11 = *(int *)pcVar11 + -1;
        UNLOCK();
        if ((iVar1 == 1) && (pcVar11 != g_empty_array_buffer_exref)) {
          odrxFree();
        }
      } while (uVar13 != 0);
    }
    odrxFree(pcVar14);
  }
  *(code **)(puVar18 + 0x26) = local_1e0;
  LOCK();
  iVar1 = *(int *)pcVar20;
  *(int *)pcVar20 = *(int *)pcVar20 + -1;
  UNLOCK();
  plVar4 = local_1a8;
  uVar13 = local_1d0;
  if ((iVar1 == 1) && (pcVar20 != g_empty_array_buffer_exref)) {
    uVar12 = (ulonglong)*(uint *)(pcVar15 + -4);
    if (*(uint *)(pcVar15 + -4) != 0) {
      pcVar15 = pcVar15 + uVar12 * 0x30 + 0x28;
      do {
        uVar13 = (int)uVar12 - 1;
        uVar12 = (ulonglong)uVar13;
        pcVar15 = pcVar15 + -0x30;
        pcVar14 = (code *)(*(longlong *)pcVar15 + -0x10);
        LOCK();
        iVar1 = *(int *)pcVar14;
        *(int *)pcVar14 = *(int *)pcVar14 + -1;
        UNLOCK();
        if ((iVar1 == 1) && (pcVar14 != g_empty_array_buffer_exref)) {
          odrxFree();
        }
      } while (uVar13 != 0);
    }
    odrxFree(pcVar20);
    plVar4 = local_1a8;
    uVar13 = local_1d0;
  }
LAB_18082b2c9:
  if ((uVar13 >> 0x11 & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_1b0,8);
    uVar10 = (bStack_1a9 & 0x7f) << 4 | (uint)(bStack_1aa >> 4);
    if ((uVar10 == 0) || (uVar10 == 0x7ff)) {
      local_1b0._0_4_ = 0;
    }
    FUN_18082cf70(puVar18,(undefined4)local_1b0);
  }
  if ((uVar13 >> 0x12 & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_res20,2);
    FUN_18082c8c0(puVar18,local_res20 & 0xffff);
  }
  if ((uVar13 >> 0x16 & 1) != 0) {
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_1b8,8);
    uVar10 = (bStack_1b1 & 0x7f) << 4 | (uint)(bStack_1b2 >> 4);
    uVar22 = 0;
    if ((uVar10 != 0) && (uVar10 != 0x7ff)) {
      uVar22 = (undefined4)local_1b8;
    }
    FUN_18082c5f0(puVar18,uVar22);
  }
  if ((puVar18 != (uint *)0x0) && (*(ulonglong *)(puVar18 + 0x32) != 0)) {
    local_res20 = *(ulonglong *)(puVar18 + 0x32);
    OdDgElementId::openObject((OdDgElementId *)&local_res20,(OpenMode)&local_1c0,true);
    this = (OdDgElement *)CONCAT17(bStack_1b9,CONCAT16(bStack_1ba,local_1c0));
    plVar6 = (longlong *)0x0;
    if (this != (OdDgElement *)0x0) {
      OdDgElement::assertWriteEnabled(this,true,true);
      plVar6 = (longlong *)CONCAT17(bStack_1b9,CONCAT16(bStack_1ba,local_1c0));
      plVar8 = (longlong *)plVar6[1];
      if (plVar8 != (longlong *)0x0) {
        (**(code **)(*plVar8 + 0x310))(plVar8,1);
        plVar6 = (longlong *)CONCAT17(bStack_1b9,CONCAT16(bStack_1ba,local_1c0));
      }
    }
    if (plVar6 != (longlong *)0x0) {
      (**(code **)(*plVar6 + 0x28))();
    }
  }
  if ((uVar13 >> 0x13 & 1) == 0) {
    *puVar18 = *puVar18 & 0xfff7ffff;
  }
  else {
    *puVar18 = *puVar18 | 0x80000;
  }
  if (*(ulonglong *)(puVar18 + 0x32) != 0) {
    local_res20 = *(ulonglong *)(puVar18 + 0x32);
    OdDgElementId::openObject((OdDgElementId *)&local_res20,(OpenMode)&local_1c8,true);
    if (local_1c8 != (OdDgElement *)0x0) {
      OdDgElement::assertWriteEnabled(local_1c8,true,true);
      plVar6 = *(longlong **)(local_1c8 + 8);
      if (plVar6 != (longlong *)0x0) {
        (**(code **)(*plVar6 + 0x310))(plVar6,1);
      }
    }
    if (local_1c8 != (OdDgElement *)0x0) {
      (**(code **)(*(longlong *)local_1c8 + 0x28))();
    }
  }
  if ((uVar13 >> 0x16 & 1) == 0) {
    *puVar18 = *puVar18 & 0xffbfffff;
  }
  else {
    *puVar18 = *puVar18 | 0x400000;
  }
  (**(code **)(*local_90 + 0x70))(local_90,local_88);
  (**(code **)(*local_90 + 0x80))(local_90,&local_1e8);
  *param_1 = 0;
  lVar7 = *local_90;
  pOVar5 = OdDgAttributeLinkage::desc();
  lVar7 = (**(code **)(lVar7 + 8))(local_90,pOVar5);
  if (lVar7 == 0) {
    pOVar5 = OdDgAttributeLinkage::desc();
    pOVar9 = (OdRxClass *)(**(code **)(*local_90 + 0x18))(local_90);
    OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
              ((OdError_NotThatKindOfClass *)&local_f0,pOVar9,pOVar5);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(&local_f0,(ThrowInfo *)&DAT_180de5310);
  }
  *param_1 = lVar7;
  if (local_1e8 != (longlong *)0x0) {
    (**(code **)(*local_1e8 + 0x28))();
    local_1e8 = (longlong *)0x0;
  }
  (**(code **)(*local_90 + 0x28))(local_90);
  OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_88);
  (**(code **)(*plVar4 + 0x28))(plVar4);
  return param_1;
}



/* ==== 180834370 FUN_180834370 ==== */

/* WARNING: Removing unreachable block (ram,0x0001808345d3) */

longlong * FUN_180834370(longlong *param_1,__uint64 param_2,uint param_3)

{
  ushort *puVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  longlong *plVar5;
  OdRxClass *pOVar6;
  longlong *plVar7;
  OdString *pOVar8;
  longlong lVar9;
  longlong *plVar10;
  code *pcVar11;
  longlong lVar12;
  OdRxClass *pOVar13;
  code *pcVar14;
  uint uVar15;
  ushort uVar16;
  undefined4 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  undefined4 uVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  undefined1 local_res18 [8];
  code *local_res20;
  longlong *local_1c8;
  uint local_1c0 [2];
  longlong *local_1b8;
  longlong *local_1b0;
  code *local_1a8;
  longlong *local_1a0;
  ushort local_198 [2];
  undefined2 local_194 [2];
  undefined4 local_190 [2];
  code *local_188;
  OdDgAttributeLinkageHeader local_180 [16];
  undefined1 local_170 [4];
  undefined1 local_16c [4];
  ulong local_168;
  undefined4 local_164;
  ulong local_160 [2];
  OdString local_158 [8];
  OdError_NotThatKindOfClass local_150 [8];
  OdString local_148 [8];
  OdString local_140 [8];
  OdError_NotThatKindOfClass local_138 [8];
  OdError_NotThatKindOfClass local_130 [8];
  OdError_NotThatKindOfClass local_128 [8];
  OdError_NotThatKindOfClass local_120 [8];
  OdError_NotThatKindOfClass local_118 [8];
  OdError_NotThatKindOfClass local_110 [8];
  OdError_NotThatKindOfClass local_108 [8];
  OdError_NotThatKindOfClass local_100 [8];
  OdError_NotThatKindOfClass local_f8 [8];
  OdError_NotThatKindOfClass local_f0 [8];
  OdError_NotThatKindOfClass local_e8 [8];
  OdError_NotThatKindOfClass local_e0 [8];
  OdError_NotThatKindOfClass local_d8 [8];
  OdError_NotThatKindOfClass local_d0 [8];
  OdError_NotThatKindOfClass local_c8 [8];
  OdDgAttributeLinkageHeader local_c0 [24];
  undefined8 local_a8;
  undefined8 uStack_a0;
  
  plVar5 = (longlong *)OdFlatMemStream::createNew(&local_1a0,param_2,(ulonglong)param_3);
  pcVar11 = (code *)0x0;
  local_1b0 = (longlong *)0x0;
  plVar5 = (longlong *)*plVar5;
  plVar7 = local_1b0;
  if (plVar5 != (longlong *)0x0) {
    lVar12 = *plVar5;
    pOVar6 = OdStreamBuf::desc();
    plVar7 = (longlong *)(**(code **)(lVar12 + 8))(plVar5,pOVar6);
    if (plVar7 == (longlong *)0x0) {
      pOVar6 = OdStreamBuf::desc();
      pOVar13 = (OdRxClass *)(**(code **)(*plVar5 + 0x18))(plVar5);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_c8,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_c8,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_1b0 = plVar7;
  plVar5 = local_1b0;
  if (local_1a0 != (longlong *)0x0) {
    (**(code **)(*local_1a0 + 0x28))();
    local_1a0 = (longlong *)0x0;
  }
  OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader(local_180);
  (**(code **)(*plVar5 + 0x98))(plVar5,&local_168,4);
  OdDgTableElementMerge::setBaseRowIndex((OdDgTableElementMerge *)local_180,local_168);
  (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,2);
  local_1a8 = (code *)0x0;
  switch((short)local_res20) {
  case 0:
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,2);
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,4);
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,4);
    plVar7 = (longlong *)OdDgDimensionOverallLinkage::createObject();
    local_1a0 = (longlong *)0x0;
    plVar7 = (longlong *)*plVar7;
    plVar10 = local_1a0;
    if (plVar7 != (longlong *)0x0) {
      lVar12 = *plVar7;
      pOVar6 = OdDgDimensionOverallLinkage::desc();
      plVar10 = (longlong *)(**(code **)(lVar12 + 8))(plVar7,pOVar6);
      if (plVar10 == (longlong *)0x0) {
        pOVar6 = OdDgDimensionOverallLinkage::desc();
        pOVar13 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_130,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_130,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_1a0 = plVar10;
    plVar7 = local_1a0;
    if (local_1c8 != (longlong *)0x0) {
      (**(code **)(*local_1c8 + 0x28))();
    }
    plVar10 = (longlong *)
              __RTDynamicCast(plVar7,0,&OdDgDimensionOverallLinkage::RTTI_Type_Descriptor,
                              &OdDgDimensionOverallLinkageImpl::RTTI_Type_Descriptor,0);
    if (plVar10 != (longlong *)0x0) {
      (**(code **)(*plVar10 + 0x70))(plVar10,local_180);
    }
    uVar15 = (uint)local_res20;
    if (((ulonglong)local_res20 & 1) != 0) {
      plVar10 = (longlong *)
                __RTDynamicCast(plVar7,0,&OdDgDimensionOverallLinkage::RTTI_Type_Descriptor,
                                &OdDgDimensionOverallLinkageImpl::RTTI_Type_Descriptor,0);
      lVar12 = *plVar10;
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(lVar12 + 0x120))(plVar10,uVar17);
    }
    if ((uVar15 >> 1 & 1) != 0) {
      lVar12 = *plVar7;
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(lVar12 + 0xb8))(plVar7,uVar17);
    }
    if ((uVar15 >> 2 & 1) != 0) {
      (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,2);
      (**(code **)(*plVar7 + 200))(plVar7,(ulonglong)local_res20 & 0xffff);
    }
    if ((uVar15 >> 3 & 1) != 0) {
      lVar12 = *plVar7;
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(lVar12 + 0xd8))(plVar7,uVar17);
    }
    if ((uVar15 >> 4 & 1) != 0) {
      lVar12 = *plVar7;
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(lVar12 + 0x100))(plVar7,uVar17);
    }
    pcVar14 = local_1a8;
    if (plVar7 != (longlong *)0x0) {
      lVar12 = *plVar7;
      pOVar6 = OdDgDimensionLinkage::desc();
      pcVar11 = (code *)(**(code **)(lVar12 + 8))(plVar7,pOVar6);
      pcVar14 = pcVar11;
      if (pcVar11 == (code *)0x0) {
        pOVar6 = OdDgDimensionLinkage::desc();
        pOVar13 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_128,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_128,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_1a8 = pcVar14;
    if (plVar7 != (longlong *)0x0) {
      (**(code **)(*plVar7 + 0x28))(plVar7);
    }
    break;
  case 1:
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,2);
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,4);
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,4);
    plVar7 = (longlong *)OdDgDimensionSegmentLinkage::createObject();
    local_1a0 = (longlong *)0x0;
    plVar7 = (longlong *)*plVar7;
    plVar10 = local_1a0;
    if (plVar7 != (longlong *)0x0) {
      lVar12 = *plVar7;
      pOVar6 = OdDgDimensionSegmentLinkage::desc();
      plVar10 = (longlong *)(**(code **)(lVar12 + 8))(plVar7,pOVar6);
      if (plVar10 == (longlong *)0x0) {
        pOVar6 = OdDgDimensionSegmentLinkage::desc();
        pOVar13 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_120,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_120,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_1a0 = plVar10;
    plVar7 = local_1a0;
    if (local_1c8 != (longlong *)0x0) {
      (**(code **)(*local_1c8 + 0x28))();
    }
    plVar10 = (longlong *)
              __RTDynamicCast(plVar7,0,&OdDgDimensionSegmentLinkage::RTTI_Type_Descriptor,
                              &OdDgDimensionSegmentLinkageImpl::RTTI_Type_Descriptor,0);
    if (plVar10 != (longlong *)0x0) {
      (**(code **)(*plVar10 + 0x70))(plVar10,local_180);
    }
    uVar15 = (uint)local_res20;
    if (((ulonglong)local_res20 & 1) != 0) {
      lVar12 = *plVar7;
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(lVar12 + 0xa8))(plVar7,uVar17);
    }
    if ((uVar15 >> 1 & 1) != 0) {
      (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,4);
      (**(code **)(*plVar7 + 0xb8))(plVar7,(ulonglong)local_res20 & 0xffffffff);
    }
    pcVar14 = local_1a8;
    if (plVar7 != (longlong *)0x0) {
      lVar12 = *plVar7;
      pOVar6 = OdDgDimensionLinkage::desc();
      pcVar11 = (code *)(**(code **)(lVar12 + 8))(plVar7,pOVar6);
      pcVar14 = pcVar11;
      if (pcVar11 == (code *)0x0) {
        pOVar6 = OdDgDimensionLinkage::desc();
        pOVar13 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_118,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_118,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_1a8 = pcVar14;
    if (plVar7 != (longlong *)0x0) {
      (**(code **)(*plVar7 + 0x28))(plVar7);
    }
    break;
  case 2:
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,4);
    plVar7 = (longlong *)OdDgDimensionPointLinkage::createObject();
    local_1a0 = (longlong *)0x0;
    plVar7 = (longlong *)*plVar7;
    plVar10 = local_1a0;
    if (plVar7 != (longlong *)0x0) {
      lVar12 = *plVar7;
      pOVar6 = OdDgDimensionPointLinkage::desc();
      plVar10 = (longlong *)(**(code **)(lVar12 + 8))(plVar7,pOVar6);
      if (plVar10 == (longlong *)0x0) {
        pOVar6 = OdDgDimensionPointLinkage::desc();
        pOVar13 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_110,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_110,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_1a0 = plVar10;
    plVar7 = local_1a0;
    if (local_1c8 != (longlong *)0x0) {
      (**(code **)(*local_1c8 + 0x28))();
    }
    plVar10 = (longlong *)
              __RTDynamicCast(plVar7,0,&OdDgDimensionPointLinkage::RTTI_Type_Descriptor,
                              &OdDgDimensionPointLinkageImpl::RTTI_Type_Descriptor,0);
    if (plVar10 != (longlong *)0x0) {
      (**(code **)(*plVar10 + 0x70))(plVar10,local_180);
    }
    uVar15 = (uint)local_res20;
    if (((uint)local_res20 >> 1 & 1) != 0) {
      (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,4);
      (**(code **)(*plVar7 + 200))(plVar7,(ulonglong)local_res20 & 0xffffffff);
    }
    if ((uVar15 >> 2 & 1) != 0) {
      (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,4);
      (**(code **)(*plVar7 + 0xd8))(plVar7,(ulonglong)local_res20 & 0xffffffff);
    }
    if ((uVar15 >> 3 & 1) != 0) {
      (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,4);
      (**(code **)(*plVar7 + 0xe8))(plVar7,(ulonglong)local_res20 & 0xffffffff);
    }
    if ((uVar15 >> 4 & 1) != 0) {
      lVar12 = *plVar7;
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(lVar12 + 0xf8))(plVar7,uVar17);
    }
    pcVar14 = local_1a8;
    if (plVar7 != (longlong *)0x0) {
      lVar12 = *plVar7;
      pOVar6 = OdDgDimensionLinkage::desc();
      pcVar11 = (code *)(**(code **)(lVar12 + 8))(plVar7,pOVar6);
      pcVar14 = pcVar11;
      if (pcVar11 == (code *)0x0) {
        pOVar6 = OdDgDimensionLinkage::desc();
        pOVar13 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_108,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_108,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_1a8 = pcVar14;
    if (plVar7 != (longlong *)0x0) {
      (**(code **)(*plVar7 + 0x28))(plVar7);
    }
    break;
  case 3:
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,2);
    (**(code **)(*plVar5 + 0x98))(plVar5,local_1c0,4);
    plVar7 = (longlong *)OdDgDimensionSegmentFlagsLinkage::createObject();
    local_res20 = (code *)0x0;
    plVar7 = (longlong *)*plVar7;
    pcVar11 = local_res20;
    if (plVar7 != (longlong *)0x0) {
      lVar12 = *plVar7;
      pOVar6 = OdDgDimensionSegmentFlagsLinkage::desc();
      pcVar11 = (code *)(**(code **)(lVar12 + 8))(plVar7,pOVar6);
      if (pcVar11 == (code *)0x0) {
        pOVar6 = OdDgDimensionSegmentFlagsLinkage::desc();
        pOVar13 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_100,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_100,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_res20 = pcVar11;
    pcVar14 = local_res20;
    if (local_1c8 != (longlong *)0x0) {
      (**(code **)(*local_1c8 + 0x28))();
    }
    plVar7 = (longlong *)
             __RTDynamicCast(pcVar14,0,&OdDgDimensionSegmentFlagsLinkage::RTTI_Type_Descriptor,
                             &OdDgDimensionSegmentFlagsLinkageImpl::RTTI_Type_Descriptor,0);
    if (plVar7 != (longlong *)0x0) {
      (**(code **)(*plVar7 + 0x70))(plVar7,local_180);
    }
    (**(code **)(*(longlong *)pcVar14 + 0x88))
              (pcVar14,CONCAT31((uint3)(local_1c0[0] >> 9),(char)(local_1c0[0] >> 1)) & 0xffffff01);
    (**(code **)(*(longlong *)pcVar14 + 0x98))(pcVar14,local_1c0[0] >> 2 & 0xffffff01);
    (**(code **)(*(longlong *)pcVar14 + 0xa8))(pcVar14,local_1c0[0] >> 3 & 0xffffff01);
    (**(code **)(*(longlong *)pcVar14 + 0xb8))(pcVar14,local_1c0[0] >> 4 & 0xffffff01);
    (**(code **)(*(longlong *)pcVar14 + 200))(pcVar14,(byte)(local_1c0[0] >> 5) & 1);
    lVar12 = *(longlong *)pcVar14;
    pOVar6 = OdDgDimensionLinkage::desc();
    pcVar11 = (code *)(**(code **)(lVar12 + 8))(pcVar14,pOVar6);
    if (pcVar11 == (code *)0x0) {
      pOVar6 = OdDgDimensionLinkage::desc();
      pOVar13 = (OdRxClass *)(**(code **)(*(longlong *)pcVar14 + 0x18))(pcVar14);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_f8,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_f8,(ThrowInfo *)&DAT_180de5310);
    }
    local_1a8 = pcVar11;
    (**(code **)(*(longlong *)pcVar14 + 0x28))(pcVar14);
    break;
  case 4:
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,2);
    (**(code **)(*plVar5 + 0x98))(plVar5,local_1c0,4);
    (**(code **)(*plVar5 + 0x98))(plVar5,local_190,4);
    plVar7 = (longlong *)OdDgDimensionRefValueLinkage::createObject();
    local_res20 = (code *)0x0;
    plVar7 = (longlong *)*plVar7;
    pcVar11 = local_res20;
    if (plVar7 != (longlong *)0x0) {
      lVar12 = *plVar7;
      pOVar6 = OdDgDimensionRefValueLinkage::desc();
      pcVar11 = (code *)(**(code **)(lVar12 + 8))(plVar7,pOVar6);
      if (pcVar11 == (code *)0x0) {
        pOVar6 = OdDgDimensionRefValueLinkage::desc();
        pOVar13 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_f0,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_f0,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_res20 = pcVar11;
    pcVar14 = local_res20;
    if (local_1c8 != (longlong *)0x0) {
      (**(code **)(*local_1c8 + 0x28))();
    }
    plVar7 = (longlong *)
             __RTDynamicCast(pcVar14,0,&OdDgDimensionRefValueLinkage::RTTI_Type_Descriptor,
                             &OdDgDimensionRefValueLinkageImpl::RTTI_Type_Descriptor,0);
    if (plVar7 != (longlong *)0x0) {
      (**(code **)(*plVar7 + 0x70))(plVar7,local_180);
    }
    lVar12 = *(longlong *)pcVar14;
    uVar17 = FUN_180833830(plVar5);
    (**(code **)(lVar12 + 0x88))(pcVar14,uVar17);
    lVar12 = *(longlong *)pcVar14;
    pOVar6 = OdDgDimensionLinkage::desc();
    pcVar11 = (code *)(**(code **)(lVar12 + 8))(pcVar14,pOVar6);
    if (pcVar11 == (code *)0x0) {
      pOVar6 = OdDgDimensionLinkage::desc();
      pOVar13 = (OdRxClass *)(**(code **)(*(longlong *)pcVar14 + 0x18))(pcVar14);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_e8,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_e8,(ThrowInfo *)&DAT_180de5310);
    }
    local_1a8 = pcVar11;
    (**(code **)(*(longlong *)pcVar14 + 0x28))(pcVar14);
    break;
  case 5:
    (**(code **)(*plVar5 + 0x98))(plVar5,local_170,2);
    plVar7 = (longlong *)OdDgDimensionTextItemLinkage::createObject();
    local_1b8 = (longlong *)0x0;
    plVar7 = (longlong *)*plVar7;
    plVar10 = local_1b8;
    if (plVar7 != (longlong *)0x0) {
      lVar12 = *plVar7;
      pOVar6 = OdDgDimensionTextItemLinkage::desc();
      plVar10 = (longlong *)(**(code **)(lVar12 + 8))(plVar7,pOVar6);
      if (plVar10 == (longlong *)0x0) {
        pOVar6 = OdDgDimensionTextItemLinkage::desc();
        pOVar13 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_150,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_150,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_1b8 = plVar10;
    plVar7 = local_1b8;
    if (local_1c8 != (longlong *)0x0) {
      (**(code **)(*local_1c8 + 0x28))();
    }
    plVar10 = (longlong *)
              __RTDynamicCast(plVar7,0,&OdDgDimensionTextItemLinkage::RTTI_Type_Descriptor,
                              &OdDgDimensionTextItemLinkageImpl::RTTI_Type_Descriptor,0);
    if (plVar10 != (longlong *)0x0) {
      (**(code **)(*plVar10 + 0x70))(plVar10,local_180);
    }
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_164,4);
    (**(code **)(*plVar7 + 0x88))(plVar7,local_164);
    (**(code **)(*plVar5 + 0x98))(plVar5,local_190,4);
    (**(code **)(*plVar7 + 0x98))(plVar7,local_190[0]);
    uVar16 = 0;
    uVar18 = 0;
    uVar19 = 0;
    uVar17 = 0;
    uVar21 = 0;
    uVar22 = 0;
    uVar20 = 0;
    (**(code **)(*plVar5 + 0x98))(plVar5,local_198,2);
    if ((*(byte *)((longlong)plVar10 + 0x2c) & 1) != 0) {
      uVar16 = local_198[0] >> 3;
      (**(code **)(*plVar7 + 0x148))(plVar7,local_198[0] & 7);
    }
    uVar15 = 0xffffffff;
    if ((*(uint *)((longlong)plVar10 + 0x2c) >> 1 & 1) != 0) {
      (**(code **)(*plVar5 + 0x98))(plVar5,local_1c0,4);
      uVar15 = local_1c0[0];
    }
    if ((*(uint *)((longlong)plVar10 + 0x2c) >> 2 & 1) != 0) {
      uVar18 = FUN_180833830(plVar5);
      uVar19 = FUN_180833830(plVar5);
    }
    if ((*(uint *)((longlong)plVar10 + 0x2c) >> 4 & 1) != 0) {
      uVar17 = FUN_180833830(plVar5);
    }
    if ((*(uint *)((longlong)plVar10 + 0x2c) >> 5 & 1) != 0) {
      uVar21 = FUN_180833830(plVar5);
    }
    if ((*(uint *)((longlong)plVar10 + 0x2c) >> 6 & 1) != 0) {
      uVar22 = FUN_180833830(plVar5);
    }
    if ((*(uint *)((longlong)plVar10 + 0x2c) >> 7 & 1) != 0) {
      uVar20 = FUN_180833830(plVar5);
    }
    OdString::init(local_158);
    if (uVar16 != 0) {
      local_188 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      FUN_1800150c0(&local_188,uVar16);
      FUN_18000d0b0(&local_188);
      pcVar14 = pcVar11;
      if (*(int *)(local_188 + -4) != 0) {
        pcVar14 = local_188;
      }
      (**(code **)(*local_1b0 + 0x98))(local_1b0,pcVar14,uVar16);
      local_res18[0] = 0;
      FUN_18021e980(&local_188,local_res18);
      pOVar8 = (OdString *)FUN_1808b7790(local_148,&local_188);
      OdString::operator=(local_158,pOVar8);
      OdString::~OdString(local_148);
      pcVar14 = local_188 + -0x10;
      LOCK();
      iVar3 = *(int *)pcVar14;
      *(int *)pcVar14 = *(int *)pcVar14 + -1;
      UNLOCK();
      plVar5 = local_1b0;
      plVar7 = local_1b8;
      if ((iVar3 == 1) && (pcVar14 != g_empty_array_buffer_exref)) {
        odrxFree();
        plVar5 = local_1b0;
        plVar7 = local_1b8;
      }
    }
    (**(code **)(*plVar7 + 0xa8))(plVar7,uVar15);
    local_a8 = uVar18;
    uStack_a0 = uVar19;
    (**(code **)(*plVar7 + 0xb8))(plVar7,&local_a8);
    (**(code **)(*plVar7 + 200))(plVar7,uVar17);
    (**(code **)(*plVar7 + 0xd8))(plVar7,uVar21);
    (**(code **)(*plVar7 + 0xe8))(plVar7,uVar22);
    (**(code **)(*plVar7 + 0xf8))(plVar7,uVar20);
    uVar18 = OdString::OdString(local_140,local_158);
    (**(code **)(*plVar7 + 0x108))(plVar7,uVar18);
    (**(code **)(*plVar5 + 0x98))(plVar5,local_16c,2);
    lVar12 = (**(code **)(*plVar5 + 0x68))(plVar5);
    OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader(local_c0);
    (**(code **)(*plVar5 + 0x98))(plVar5,local_160,4);
    OdDgTableElementMerge::setBaseRowIndex((OdDgTableElementMerge *)local_c0,local_160[0]);
    uVar2 = OdDgAttributeLinkageHeader::getLinkageDataSize(local_c0);
    (**(code **)(*plVar5 + 0x88))(plVar5,lVar12,0);
    (**(code **)(*plVar7 + 0x120))(plVar7,plVar5);
    (**(code **)(*plVar5 + 0x88))(plVar5,lVar12 + (ulonglong)uVar2,0);
    (**(code **)(*plVar5 + 0x98))(plVar5,local_194,2);
    (**(code **)(*plVar7 + 0x118))(plVar7,local_194[0]);
    lVar12 = (**(code **)(*plVar5 + 0x68))(plVar5);
    lVar9 = (**(code **)(*plVar5 + 0x70))(plVar5);
    plVar10 = local_1b0;
    if (lVar12 != lVar9) {
      local_res20 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      iVar3 = (**(code **)(*local_1b0 + 0x70))(local_1b0);
      iVar4 = (**(code **)(*plVar10 + 0x68))(plVar10);
      FUN_1800150c0(&local_res20,iVar3 - iVar4);
      uVar17 = *(undefined4 *)(local_res20 + -4);
      FUN_18000d0b0(&local_res20);
      if (*(int *)(local_res20 + -4) != 0) {
        pcVar11 = local_res20;
      }
      (**(code **)(*plVar10 + 0x98))(plVar10,pcVar11,uVar17);
      (**(code **)(*local_1b8 + 0x138))(local_1b8,&local_res20);
      pcVar11 = local_res20 + -0x10;
      LOCK();
      iVar3 = *(int *)pcVar11;
      *(int *)pcVar11 = *(int *)pcVar11 + -1;
      UNLOCK();
      plVar5 = local_1b0;
      plVar7 = local_1b8;
      if ((iVar3 == 1) && (pcVar11 != g_empty_array_buffer_exref)) {
        odrxFree();
        plVar5 = local_1b0;
        plVar7 = local_1b8;
      }
    }
    lVar12 = *plVar7;
    pOVar6 = OdDgDimensionLinkage::desc();
    pcVar11 = (code *)(**(code **)(lVar12 + 8))(plVar7,pOVar6);
    if (pcVar11 == (code *)0x0) {
      pOVar6 = OdDgDimensionLinkage::desc();
      pOVar13 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_138,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_138,(ThrowInfo *)&DAT_180de5310);
    }
    local_1a8 = pcVar11;
    OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_c0);
    OdString::~OdString(local_158);
    (**(code **)(*plVar7 + 0x28))(plVar7);
    break;
  case 6:
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,2);
    (**(code **)(*plVar5 + 0x98))(plVar5,local_190,4);
    (**(code **)(*plVar5 + 0x98))(plVar5,local_1c0,4);
    plVar7 = (longlong *)OdDgDimensionInfoLinkage::createObject();
    local_1b8 = (longlong *)0x0;
    plVar7 = (longlong *)*plVar7;
    plVar10 = local_1b8;
    if (plVar7 != (longlong *)0x0) {
      lVar12 = *plVar7;
      pOVar6 = OdDgDimensionInfoLinkage::desc();
      plVar10 = (longlong *)(**(code **)(lVar12 + 8))(plVar7,pOVar6);
      if (plVar10 == (longlong *)0x0) {
        pOVar6 = OdDgDimensionInfoLinkage::desc();
        pOVar13 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_e0,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_e0,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_1b8 = plVar10;
    plVar7 = local_1b8;
    if (local_1c8 != (longlong *)0x0) {
      (**(code **)(*local_1c8 + 0x28))();
    }
    plVar10 = (longlong *)
              __RTDynamicCast(plVar7,0,&OdDgDimensionInfoLinkage::RTTI_Type_Descriptor,
                              &OdDgDimensionInfoLinkageImpl::RTTI_Type_Descriptor,0);
    if (plVar10 != (longlong *)0x0) {
      (**(code **)(*plVar10 + 0x70))(plVar10,local_180);
    }
    if ((local_1c0[0] & 1) != 0) {
      (**(code **)(*plVar7 + 400))(plVar7,1);
      (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,2);
      (**(code **)(*plVar7 + 0x288))(plVar7,(int)(short)local_res20);
    }
    if ((local_1c0[0] >> 1 & 1) != 0) {
      (**(code **)(*plVar7 + 0x198))(plVar7,1);
      (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,2);
      (**(code **)(*plVar7 + 0x298))(plVar7,(int)(short)local_res20);
    }
    if ((local_1c0[0] >> 2 & 1) != 0) {
      (**(code **)(*plVar7 + 0x438))(plVar7,1);
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(*plVar7 + 0x458))(plVar7,uVar17);
    }
    if ((local_1c0[0] >> 3 & 1) != 0) {
      (**(code **)(*plVar7 + 0x440))(plVar7,1);
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(*plVar7 + 0x468))(plVar7,uVar17);
    }
    if ((local_1c0[0] >> 4 & 1) != 0) {
      (**(code **)(*plVar7 + 0x1a0))(plVar7,1);
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(*plVar7 + 0x2e8))(plVar7,uVar17);
    }
    if ((local_1c0[0] >> 5 & 1) == 0) {
      if (plVar7 != (longlong *)0x0) {
        puVar1 = (ushort *)(plVar7 + 0x13);
        *puVar1 = *puVar1 & 0xfffe;
        if (*puVar1 == 0) {
          (**(code **)(*plVar7 + 0x1b8))(plVar7,0);
        }
      }
    }
    else {
      (**(code **)(*plVar7 + 0x1b8))(plVar7,1);
      (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,2);
      (**(code **)(*plVar7 + 0x3e0))(plVar7,(ulonglong)local_res20 & 0xffff);
    }
    if ((local_1c0[0] >> 6 & 1) != 0) {
      (**(code **)(*plVar7 + 0x1c0))(plVar7,1);
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(*plVar7 + 0x2a8))(plVar7,uVar17);
    }
    if ((local_1c0[0] >> 7 & 1) != 0) {
      (**(code **)(*plVar7 + 0x220))(plVar7,1);
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(*plVar7 + 0x330))(plVar7,uVar17);
    }
    if ((local_1c0[0] >> 8 & 1) != 0) {
      (**(code **)(*plVar7 + 0x228))(plVar7,1);
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(*plVar7 + 0x340))(plVar7,uVar17);
    }
    if ((local_1c0[0] >> 9 & 1) != 0) {
      (**(code **)(*plVar7 + 0x230))(plVar7,1);
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(*plVar7 + 0x350))(plVar7,uVar17);
    }
    if ((local_1c0[0] >> 10 & 1) != 0) {
      (**(code **)(*plVar7 + 0x1c8))(plVar7,1);
      (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,4);
      (**(code **)(*plVar7 + 1000))(plVar7,(ulonglong)local_res20 & 0xffffffff);
    }
    if ((local_1c0[0] >> 0xb & 1) != 0) {
      (**(code **)(*plVar7 + 0x1d0))(plVar7,1);
      (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,4);
      (**(code **)(*plVar7 + 0x3b0))(plVar7,(ulonglong)local_res20 & 0xffffffff);
    }
    if ((local_1c0[0] >> 0xc & 1) != 0) {
      (**(code **)(*plVar7 + 0x1d8))(plVar7,1);
      (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,2);
      (**(code **)(*plVar7 + 0x3c0))(plVar7,(ulonglong)local_res20 & 0xffff);
    }
    if ((local_1c0[0] >> 0xd & 1) != 0) {
      (**(code **)(*plVar7 + 0x1e0))(plVar7,1);
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(*plVar7 + 0x2c8))(plVar7,uVar17);
    }
    if ((local_1c0[0] >> 0xe & 1) != 0) {
      (**(code **)(*plVar7 + 0x240))(plVar7,1);
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(*plVar7 + 0x370))(plVar7,uVar17);
    }
    if ((local_1c0[0] >> 0xf & 1) != 0) {
      (**(code **)(*plVar7 + 0x178))(plVar7,1);
      (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,2);
      (**(code **)(*plVar7 + 0x188))(plVar7,(ulonglong)local_res20 & 0xffff);
    }
    if ((local_1c0[0] >> 0x10 & 1) != 0) {
      (**(code **)(*plVar7 + 0x1f0))(plVar7,1);
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(*plVar7 + 0x2f8))(plVar7,uVar17);
    }
    if ((local_1c0[0] >> 0x12 & 1) != 0) {
      (**(code **)(*plVar7 + 0x238))(plVar7,1);
      uVar17 = FUN_180833830(plVar5);
      (**(code **)(*plVar7 + 0x360))(plVar7,uVar17);
    }
    if ((local_1c0[0] >> 0x13 & 1) != 0) {
      (**(code **)(*plVar7 + 0x1f8))(plVar7,1);
      (**(code **)(*plVar5 + 0x98))(plVar5,&local_res20,4);
      (**(code **)(*plVar7 + 0x3f0))(plVar7,(ulonglong)local_res20 & 0xffffffff);
    }
    pcVar14 = local_1a8;
    if (plVar7 != (longlong *)0x0) {
      lVar12 = *plVar7;
      pOVar6 = OdDgDimensionLinkage::desc();
      pcVar11 = (code *)(**(code **)(lVar12 + 8))(plVar7,pOVar6);
      pcVar14 = pcVar11;
      if (pcVar11 == (code *)0x0) {
        pOVar6 = OdDgDimensionLinkage::desc();
        pOVar13 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_d8,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_d8,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_1a8 = pcVar14;
    if (plVar7 != (longlong *)0x0) {
      (**(code **)(*plVar7 + 0x28))(plVar7);
    }
    break;
  default:
    *param_1 = 0;
    OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_180);
    (**(code **)(*plVar5 + 0x28))(plVar5);
    return param_1;
  }
  *param_1 = 0;
  if (pcVar11 != (code *)0x0) {
    lVar12 = *(longlong *)pcVar11;
    pOVar6 = OdDgAttributeLinkage::desc();
    lVar12 = (**(code **)(lVar12 + 8))(pcVar11,pOVar6);
    if (lVar12 == 0) {
      pOVar6 = OdDgAttributeLinkage::desc();
      pOVar13 = (OdRxClass *)(**(code **)(*(longlong *)pcVar11 + 0x18))(pcVar11);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_d0,pOVar13,pOVar6);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_d0,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar12;
  }
  if (pcVar11 != (code *)0x0) {
    (**(code **)(*(longlong *)pcVar11 + 0x28))(pcVar11);
  }
  OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_180);
  (**(code **)(*plVar5 + 0x28))(plVar5);
  return param_1;
}



/* ==== 180835b40 FUN_180835b40 ==== */

longlong * FUN_180835b40(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  char cVar1;
  OdRxClass *pOVar2;
  longlong lVar3;
  OdRxClass *pOVar4;
  longlong *local_res20;
  OdError_NotThatKindOfClass local_18 [16];
  
  OdDgDimensionTextStyleDataLinkage::createObject();
  if ((local_res20 != (longlong *)0x0) &&
     (cVar1 = (**(code **)(*local_res20 + 0x78))(local_res20,param_2,param_3), cVar1 != '\0')) {
    *param_1 = 0;
    lVar3 = *local_res20;
    pOVar2 = OdDgAttributeLinkage::desc();
    lVar3 = (**(code **)(lVar3 + 8))(local_res20,pOVar2);
    if (lVar3 != 0) {
      *param_1 = lVar3;
      (**(code **)(*local_res20 + 0x28))(local_res20);
      return param_1;
    }
    pOVar2 = OdDgAttributeLinkage::desc();
    pOVar4 = (OdRxClass *)(**(code **)(*local_res20 + 0x18))(local_res20);
    OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_18,pOVar4,pOVar2);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_18,(ThrowInfo *)&DAT_180de5310);
  }
  *param_1 = 0;
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))(local_res20);
  }
  return param_1;
}



/* ==== 1808ab3d0 FUN_1808ab3d0 ==== */

undefined8 *
FUN_1808ab3d0(undefined8 *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  OdRxClass *pOVar1;
  longlong *plVar2;
  OdRxClass *pOVar3;
  longlong *local_res20;
  undefined8 uVar4;
  OdError_NotThatKindOfClass local_20 [8];
  
  plVar2 = (longlong *)0x0;
  uVar4 = 0;
  OdDgTextAnnotationLinkage::createObject();
  (**(code **)(*local_res20 + 0x78))(local_res20,param_2,param_3,param_4,uVar4);
  if (local_res20 != (longlong *)0x0) {
    pOVar1 = OdDgAttributeLinkage::desc();
    plVar2 = (longlong *)(**(code **)(*local_res20 + 8))(local_res20,pOVar1);
    if (plVar2 == (longlong *)0x0) {
      pOVar1 = OdDgAttributeLinkage::desc();
      pOVar3 = (OdRxClass *)(**(code **)(*local_res20 + 0x18))(local_res20);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_20,pOVar3,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_20,(ThrowInfo *)&DAT_180de5310);
    }
  }
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))(local_res20);
  }
  *param_1 = plVar2;
  if (plVar2 != (longlong *)0x0) {
    (**(code **)(*plVar2 + 0x20))(plVar2);
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return param_1;
}



/* ==== 1808accc0 FUN_1808accc0 ==== */

longlong * FUN_1808accc0(longlong *param_1,longlong param_2,undefined4 param_3,undefined8 param_4)

{
  OdRxClass *pOVar1;
  longlong lVar2;
  OdRxClass *pOVar3;
  longlong *local_res10;
  OdError_NotThatKindOfClass local_res20 [8];
  undefined4 uVar4;
  
  *param_1 = 0;
  uVar4 = 1;
  if (*(char *)(param_2 + 4) != '\x06') {
    OdDgBitMaskLinkage::createObject();
    if (local_res10 != (longlong *)0x0) {
      (**(code **)(*local_res10 + 0x78))(local_res10,param_2,param_3,param_4,uVar4);
    }
    if ((longlong *)*param_1 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*param_1 + 0x28))();
      *param_1 = 0;
    }
    if (local_res10 != (longlong *)0x0) {
      lVar2 = *local_res10;
      pOVar1 = OdDgAttributeLinkage::desc();
      lVar2 = (**(code **)(lVar2 + 8))(local_res10,pOVar1);
      if (lVar2 == 0) {
        pOVar1 = OdDgAttributeLinkage::desc();
        pOVar3 = (OdRxClass *)(**(code **)(*local_res10 + 0x18))(local_res10);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res20,pOVar3,pOVar1);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
      }
      *param_1 = lVar2;
    }
    if (local_res10 != (longlong *)0x0) {
      (**(code **)(*local_res10 + 0x28))(local_res10);
    }
    return param_1;
  }
  OdDgTextWhiteSpaceLinkage::createObject();
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 0x78))(local_res10,param_2,param_3);
  }
  if ((longlong *)*param_1 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*param_1 + 0x28))();
    *param_1 = 0;
  }
  if (local_res10 != (longlong *)0x0) {
    lVar2 = *local_res10;
    pOVar1 = OdDgAttributeLinkage::desc();
    lVar2 = (**(code **)(lVar2 + 8))(local_res10,pOVar1);
    if (lVar2 == 0) {
      pOVar1 = OdDgAttributeLinkage::desc();
      pOVar3 = (OdRxClass *)(**(code **)(*local_res10 + 0x18))(local_res10);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res20,pOVar3,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar2;
  }
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 0x28))(local_res10);
  }
  return param_1;
}



/* ==== 1808ad8a0 FUN_1808ad8a0 ==== */

longlong * FUN_1808ad8a0(longlong *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  OdRxClass *pOVar1;
  longlong lVar2;
  OdRxClass *pOVar3;
  longlong *local_res20;
  undefined4 uVar4;
  OdError_NotThatKindOfClass local_20 [8];
  
  *param_1 = 0;
  uVar4 = 1;
  OdDgTextIndentationLinkage::createObject();
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x78))(local_res20,param_2,param_3,param_4,uVar4);
    if ((longlong *)*param_1 != (longlong *)0x0) {
      (**(code **)(*(longlong *)*param_1 + 0x28))();
      *param_1 = 0;
    }
    lVar2 = *local_res20;
    pOVar1 = OdDgAttributeLinkage::desc();
    lVar2 = (**(code **)(lVar2 + 8))(local_res20,pOVar1);
    if (lVar2 == 0) {
      pOVar1 = OdDgAttributeLinkage::desc();
      pOVar3 = (OdRxClass *)(**(code **)(*local_res20 + 0x18))(local_res20);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_20,pOVar3,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_20,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar2;
  }
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))(local_res20);
  }
  return param_1;
}



/* ==== 1808af930 FUN_1808af930 ==== */

longlong * FUN_1808af930(longlong *param_1,undefined8 param_2,undefined4 param_3,undefined8 param_4)

{
  longlong *plVar1;
  OdRxClass *pOVar2;
  longlong lVar3;
  OdRxClass *pOVar4;
  longlong *local_res20;
  undefined4 uVar5;
  OdError_NotThatKindOfClass local_10 [8];
  
  *param_1 = 0;
  uVar5 = 1;
  OdDgReferenceAttachPathLinkage::createObject();
  (**(code **)(*local_res20 + 0x78))(local_res20,param_2,param_3,param_4,uVar5);
  plVar1 = (longlong *)*param_1;
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
    *param_1 = 0;
  }
  if (local_res20 != (longlong *)0x0) {
    pOVar2 = OdDgAttributeLinkage::desc();
    lVar3 = (**(code **)(*local_res20 + 8))(local_res20,pOVar2);
    if (lVar3 == 0) {
      pOVar2 = OdDgAttributeLinkage::desc();
      pOVar4 = (OdRxClass *)(**(code **)(*local_res20 + 0x18))(local_res20);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_10,pOVar4,pOVar2);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_10,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar3;
  }
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))();
  }
  return param_1;
}



/* ==== 1808c07f0 FUN_1808c07f0 ==== */

longlong * FUN_1808c07f0(longlong *param_1,__uint64 param_2,uint param_3)

{
  PrimaryIds PVar1;
  longlong *plVar2;
  OdRxClass *pOVar3;
  longlong *plVar4;
  longlong *plVar5;
  longlong lVar6;
  OdRxClass *pOVar7;
  undefined8 uVar8;
  ulong local_res18 [2];
  longlong *local_res20;
  longlong *local_48;
  undefined8 local_40;
  OdDgAttributeLinkageHeader local_38 [16];
  
  plVar2 = (longlong *)OdFlatMemStream::createNew(&local_res20,param_2,(ulonglong)param_3);
  uVar8 = 0;
  local_48 = (longlong *)0x0;
  plVar2 = (longlong *)*plVar2;
  plVar4 = local_48;
  if (plVar2 != (longlong *)0x0) {
    lVar6 = *plVar2;
    pOVar3 = OdStreamBuf::desc();
    plVar4 = (longlong *)(**(code **)(lVar6 + 8))(plVar2,pOVar3);
    if (plVar4 == (longlong *)0x0) {
      pOVar3 = OdStreamBuf::desc();
      pOVar7 = (OdRxClass *)(**(code **)(*plVar2 + 0x18))(plVar2);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_48,pOVar7,pOVar3);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_48,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_48 = plVar4;
  plVar2 = local_48;
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))();
    local_res20 = (longlong *)0x0;
  }
  OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader(local_38);
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  OdDgTableElementMerge::setBaseRowIndex((OdDgTableElementMerge *)local_38,local_res18[0]);
  PVar1 = OdDgAttributeLinkageHeader::getPrimaryId(local_38);
  if ((int)PVar1 < 0x4f59) {
    if (PVar1 == 0x4f58) {
      uVar8 = 8;
    }
    else if (PVar1 == 0x20) {
      uVar8 = 1;
    }
    else if (PVar1 != 0xf81) {
      if (PVar1 == 0x1971) {
        uVar8 = 9;
      }
      else if (PVar1 == 0x3948) {
        uVar8 = 2;
      }
      else {
        if (PVar1 != 0x3a77) goto LAB_1808c090b;
        uVar8 = 3;
      }
    }
  }
  else if (PVar1 == 0x5800) {
    uVar8 = 5;
  }
  else if (PVar1 == 0x5e62) {
    uVar8 = 4;
  }
  else if (PVar1 == 0x6091) {
    uVar8 = 6;
  }
  else {
    if (PVar1 != 0x71fb) {
LAB_1808c090b:
      local_res20 = (longlong *)0x0;
      FUN_1800203e0(param_1,&local_res20);
      OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_38);
      (**(code **)(*plVar2 + 0x28))(plVar2);
      return param_1;
    }
    uVar8 = 7;
  }
  FUN_1808c02f0(&local_res20,uVar8);
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,2);
  if ((int)(short)local_res18[0] == (uint)DAT_180fcd428) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,2);
    plVar4 = local_res20;
    (**(code **)(*local_res20 + 0x88))(local_res20,(short)local_res18[0]);
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    (**(code **)(*plVar4 + 0x98))(plVar4,local_res18[0]);
    plVar5 = (longlong *)
             __RTDynamicCast(plVar4,0,&OdDgDBLinkage::RTTI_Type_Descriptor,
                             &OdDgDBLinkageImpl::RTTI_Type_Descriptor,0);
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(ulong *)((longlong)plVar5 + 0x1c) = local_res18[0];
    (**(code **)(*plVar5 + 0x70))(plVar5,local_38);
    *param_1 = 0;
    lVar6 = *plVar4;
    pOVar3 = OdDgAttributeLinkage::desc();
    lVar6 = (**(code **)(lVar6 + 8))(plVar4,pOVar3);
    if (lVar6 == 0) {
      pOVar3 = OdDgAttributeLinkage::desc();
      pOVar7 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_40,pOVar7,pOVar3);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_40,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar6;
    (**(code **)(*plVar4 + 0x28))(plVar4);
    OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_38);
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  else {
    local_40 = 0;
    FUN_1800203e0(param_1,&local_40);
    if (local_res20 != (longlong *)0x0) {
      (**(code **)(*local_res20 + 0x28))();
    }
    OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_38);
    (**(code **)(*plVar2 + 0x28))(plVar2);
  }
  return param_1;
}



/* ==== 1808c14e0 FUN_1808c14e0 ==== */

longlong * FUN_1808c14e0(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  OdRxClass *pOVar1;
  longlong lVar2;
  OdRxClass *pOVar3;
  OdError_NotThatKindOfClass local_res20 [8];
  
  OdDgMaterialLinkage::createObject();
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3);
  }
  *param_1 = 0;
  if (param_1 != (longlong *)0x0) {
    lVar2 = *param_1;
    pOVar1 = OdDgAttributeLinkage::desc();
    lVar2 = (**(code **)(lVar2 + 8))(param_1,pOVar1);
    if (lVar2 == 0) {
      pOVar1 = OdDgAttributeLinkage::desc();
      pOVar3 = (OdRxClass *)(**(code **)(*param_1 + 0x18))(param_1);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res20,pOVar3,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar2;
  }
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x28))(param_1);
  }
  return param_1;
}



/* ==== 1808c2490 FUN_1808c2490 ==== */

longlong * FUN_1808c2490(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  OdRxClass *pOVar1;
  longlong lVar2;
  OdRxClass *pOVar3;
  OdError_NotThatKindOfClass local_res20 [8];
  
  OdDgLineStyleModificationLinkage::createObject();
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3);
  }
  *param_1 = 0;
  if (param_1 != (longlong *)0x0) {
    lVar2 = *param_1;
    pOVar1 = OdDgAttributeLinkage::desc();
    lVar2 = (**(code **)(lVar2 + 8))(param_1,pOVar1);
    if (lVar2 == 0) {
      pOVar1 = OdDgAttributeLinkage::desc();
      pOVar3 = (OdRxClass *)(**(code **)(*param_1 + 0x18))(param_1);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res20,pOVar3,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar2;
  }
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x28))(param_1);
  }
  return param_1;
}



/* ==== 1808c4330 FUN_1808c4330 ==== */

longlong * FUN_1808c4330(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  OdRxClass *pOVar1;
  longlong lVar2;
  OdRxClass *pOVar3;
  OdError_NotThatKindOfClass local_res20 [8];
  
  OdDgSheetModelExtensionLinkage::createObject();
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3);
  }
  *param_1 = 0;
  if (param_1 != (longlong *)0x0) {
    lVar2 = *param_1;
    pOVar1 = OdDgAttributeLinkage::desc();
    lVar2 = (**(code **)(lVar2 + 8))(param_1,pOVar1);
    if (lVar2 == 0) {
      pOVar1 = OdDgAttributeLinkage::desc();
      pOVar3 = (OdRxClass *)(**(code **)(*param_1 + 0x18))(param_1);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res20,pOVar3,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar2;
  }
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x28))(param_1);
  }
  return param_1;
}



/* ==== 1808c43f0 FUN_1808c43f0 ==== */

longlong * FUN_1808c43f0(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  OdRxClass *pOVar1;
  longlong lVar2;
  OdRxClass *pOVar3;
  OdError_NotThatKindOfClass local_res20 [8];
  
  OdDgSheetModelLinkage::createObject();
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3);
  }
  *param_1 = 0;
  if (param_1 != (longlong *)0x0) {
    lVar2 = *param_1;
    pOVar1 = OdDgAttributeLinkage::desc();
    lVar2 = (**(code **)(lVar2 + 8))(param_1,pOVar1);
    if (lVar2 == 0) {
      pOVar1 = OdDgAttributeLinkage::desc();
      pOVar3 = (OdRxClass *)(**(code **)(*param_1 + 0x18))(param_1);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res20,pOVar3,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar2;
  }
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x28))(param_1);
  }
  return param_1;
}



/* ==== 1808c4d70 FUN_1808c4d70 ==== */

longlong * FUN_1808c4d70(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  OdRxClass *pOVar1;
  longlong lVar2;
  OdRxClass *pOVar3;
  OdError_NotThatKindOfClass local_res20 [8];
  
  OdDgOleLinkage::createObject();
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3);
  }
  *param_1 = 0;
  if (param_1 != (longlong *)0x0) {
    lVar2 = *param_1;
    pOVar1 = OdDgAttributeLinkage::desc();
    lVar2 = (**(code **)(lVar2 + 8))(param_1,pOVar1);
    if (lVar2 == 0) {
      pOVar1 = OdDgAttributeLinkage::desc();
      pOVar3 = (OdRxClass *)(**(code **)(*param_1 + 0x18))(param_1);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res20,pOVar3,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar2;
  }
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x28))(param_1);
  }
  return param_1;
}



/* ==== 1808caf70 FUN_1808caf70 ==== */

longlong * FUN_1808caf70(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  OdRxClass *pOVar1;
  longlong lVar2;
  OdRxClass *pOVar3;
  OdError_NotThatKindOfClass local_res20 [8];
  
  OdDgBoundaryClipLinkage::createObject();
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3);
  }
  *param_1 = 0;
  if (param_1 != (longlong *)0x0) {
    lVar2 = *param_1;
    pOVar1 = OdDgAttributeLinkage::desc();
    lVar2 = (**(code **)(lVar2 + 8))(param_1,pOVar1);
    if (lVar2 == 0) {
      pOVar1 = OdDgAttributeLinkage::desc();
      pOVar3 = (OdRxClass *)(**(code **)(*param_1 + 0x18))(param_1);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res20,pOVar3,pOVar1);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar2;
  }
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x28))(param_1);
  }
  return param_1;
}



/* ==== 1808d3d30 FUN_1808d3d30 ==== */

longlong * FUN_1808d3d30(longlong *param_1,__uint64 param_2,uint param_3)

{
  longlong *plVar1;
  OdRxClass *pOVar2;
  longlong *plVar3;
  longlong lVar4;
  OdRxClass *pOVar5;
  longlong *local_res20;
  longlong *local_28;
  longlong *local_20;
  
  plVar1 = (longlong *)OdFlatMemStream::createNew(&local_res20,param_2,(ulonglong)param_3);
  local_28 = (longlong *)0x0;
  plVar1 = (longlong *)*plVar1;
  plVar3 = local_28;
  if (plVar1 != (longlong *)0x0) {
    lVar4 = *plVar1;
    pOVar2 = OdStreamBuf::desc();
    plVar3 = (longlong *)(**(code **)(lVar4 + 8))(plVar1,pOVar2);
    if (plVar3 == (longlong *)0x0) {
      pOVar2 = OdStreamBuf::desc();
      pOVar5 = (OdRxClass *)(**(code **)(*plVar1 + 0x18))(plVar1);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_28,pOVar5,pOVar2);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_28,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_28 = plVar3;
  plVar1 = local_28;
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))();
    local_res20 = (longlong *)0x0;
  }
  OdDgXmlLinkage::createObject();
  if (local_20 != (longlong *)0x0) {
    (**(code **)(*local_20 + 0x78))(local_20,param_2,param_3);
  }
  *param_1 = 0;
  if (local_20 != (longlong *)0x0) {
    lVar4 = *local_20;
    pOVar2 = OdDgAttributeLinkage::desc();
    lVar4 = (**(code **)(lVar4 + 8))(local_20,pOVar2);
    if (lVar4 == 0) {
      pOVar2 = OdDgAttributeLinkage::desc();
      pOVar5 = (OdRxClass *)(**(code **)(*local_20 + 0x18))(local_20);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_res20,pOVar5,pOVar2);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar4;
  }
  if (local_20 != (longlong *)0x0) {
    (**(code **)(*local_20 + 0x28))(local_20);
  }
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x28))(plVar1);
  }
  return param_1;
}



