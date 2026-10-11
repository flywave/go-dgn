/* ==== 1800399c0 FUN_1800399c0 ==== */

longlong * FUN_1800399c0(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  char cVar1;
  OdRxClass *pOVar2;
  longlong lVar3;
  OdRxClass *pOVar4;
  longlong *local_res20;
  OdError_NotThatKindOfClass local_18 [16];
  
  OdDgByteArrayLinkage::createObject();
  cVar1 = FUN_1808adc60(local_res20,param_2,param_3);
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



/* ==== 18003d650 FUN_18003d650 ==== */

longlong * FUN_18003d650(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  OdRxClass *pOVar1;
  longlong lVar2;
  OdRxClass *pOVar3;
  OdError_NotThatKindOfClass local_res20 [8];
  
  OdDgDoubleArrayLinkage::createObject();
  (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3);
  *param_1 = 0;
  lVar2 = *param_1;
  pOVar1 = OdDgAttributeLinkage::desc();
  lVar2 = (**(code **)(lVar2 + 8))(param_1,pOVar1);
  if (lVar2 != 0) {
    *param_1 = lVar2;
    (**(code **)(*param_1 + 0x28))(param_1);
    return param_1;
  }
  pOVar1 = OdDgAttributeLinkage::desc();
  pOVar3 = (OdRxClass *)(**(code **)(*param_1 + 0x18))(param_1);
  OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_res20,pOVar3,pOVar1);
                    /* WARNING: Subroutine does not return */
  _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
}



/* ==== 1800481a0 FUN_1800481a0 ==== */

undefined8 FUN_1800481a0(undefined8 param_1,longlong param_2,undefined8 param_3,undefined8 param_4)

{
  longlong lVar1;
  ToolType TVar2;
  longlong *plVar3;
  _func_void *p_Var4;
  OdString *pOVar5;
  OdDgDimStackedLocation *this;
  longlong *local_res20;
  longlong *plVar6;
  longlong local_30;
  undefined4 local_28;
  longlong local_20;
  
  plVar3 = (longlong *)odrxAlloc(0x30);
  if (plVar3 == (longlong *)0x0) {
    p_Var4 = std::get_new_handler();
    if (p_Var4 == (_func_void *)0x0) {
      FUN_1800044e0(&local_30);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_30,(ThrowInfo *)&DAT_180de5280);
    }
    (*p_Var4)();
  }
  plVar6 = plVar3;
  if (plVar3 != (longlong *)0x0) {
    *plVar3 = (longlong)OdRxObjectImpl<OdDgStringLinkage,OdDgStringLinkage>::vftable;
    *(undefined4 *)(plVar3 + 1) = 0xffffffff;
    *(undefined4 *)(plVar3 + 1) = 0;
    LOCK();
    *(undefined4 *)(plVar3 + 1) = 1;
    UNLOCK();
    *plVar3 = (longlong)OdDgStringLinkageImpl::vftable;
    OdString::init((OdString *)(plVar3 + 3));
    OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader
              ((OdDgAttributeLinkageHeader *)(plVar3 + 4));
    OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader((OdDgAttributeLinkageHeader *)&local_30);
    this = (OdDgDimStackedLocation *)&local_30;
    local_20 = param_2;
    (**(code **)(local_30 + 0x18))(this,0x56d2);
    lVar1 = local_20;
    TVar2 = OdDgDimStackedLocation::dimensionType(this);
    *(undefined4 *)(plVar3 + 2) = *(undefined4 *)(lVar1 + (ulonglong)TVar2);
    pOVar5 = (OdString *)FUN_1800545f0(&local_30,&local_res20);
    OdString::operator=((OdString *)(plVar3 + 3),pOVar5);
    OdString::~OdString((OdString *)&local_res20);
    *(undefined4 *)(plVar3 + 5) = local_28;
    OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader((OdDgAttributeLinkageHeader *)&local_30)
    ;
  }
  local_res20 = plVar3;
  FUN_1800203e0(param_1,&local_res20,param_3,param_4,plVar6);
  if (plVar3 != (longlong *)0x0) {
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  return param_1;
}



/* ==== 180829ed0 FUN_180829ed0 ==== */

longlong * FUN_180829ed0(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  OdRxClass *pOVar1;
  longlong lVar2;
  OdRxClass *pOVar3;
  OdError_NotThatKindOfClass local_res20 [8];
  
  OdDgAssocRegionLinkage::createObject();
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



/* ==== 18082b760 FUN_18082b760 ==== */

longlong * FUN_18082b760(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  OdRxClass *pOVar1;
  longlong lVar2;
  OdRxClass *pOVar3;
  OdError_NotThatKindOfClass local_res20 [8];
  
  OdDgSeedPointsLinkage::createObject();
  if (param_1 != (longlong *)0x0) {
    (**(code **)(*param_1 + 0x80))(param_1,param_2,param_3);
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



/* ==== 180835c20 FUN_180835c20 ==== */

longlong * FUN_180835c20(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  char cVar1;
  OdRxClass *pOVar2;
  longlong lVar3;
  OdRxClass *pOVar4;
  longlong *local_res20;
  OdError_NotThatKindOfClass local_18 [16];
  
  OdDgNoteLinkage::createObject();
  if ((local_res20 != (longlong *)0x0) &&
     (cVar1 = (**(code **)(*local_res20 + 0x80))(local_res20,param_2,param_3), cVar1 != '\0')) {
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



/* ==== 1808bef50 FUN_1808bef50 ==== */

undefined8 * FUN_1808bef50(undefined8 *param_1,__uint64 param_2,uint param_3)

{
  longlong lVar1;
  char cVar2;
  longlong *plVar3;
  OdRxClass *pOVar4;
  longlong *plVar5;
  longlong *plVar6;
  OdRxClass *pOVar7;
  undefined4 uVar8;
  ulong local_res18 [2];
  longlong *local_res20;
  longlong *local_98;
  OdDgAttributeLinkageHeader local_90 [16];
  longlong *local_80;
  OdError_NotThatKindOfClass local_78 [8];
  OdError_NotThatKindOfClass local_70 [8];
  OdError_NotThatKindOfClass local_68 [8];
  OdError_NotThatKindOfClass local_60 [8];
  OdError_NotThatKindOfClass local_58 [8];
  undefined8 local_50;
  OdError_NotThatKindOfClass local_48 [16];
  
  plVar3 = (longlong *)OdFlatMemStream::createNew(&local_res20,param_2,(ulonglong)param_3);
  plVar6 = (longlong *)0x0;
  local_80 = (longlong *)0x0;
  plVar3 = (longlong *)*plVar3;
  plVar5 = local_80;
  if (plVar3 != (longlong *)0x0) {
    lVar1 = *plVar3;
    pOVar4 = OdStreamBuf::desc();
    plVar5 = (longlong *)(**(code **)(lVar1 + 8))(plVar3,pOVar4);
    if (plVar5 == (longlong *)0x0) {
      pOVar4 = OdStreamBuf::desc();
      pOVar7 = (OdRxClass *)(**(code **)(*plVar3 + 0x18))(plVar3);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_78,pOVar7,pOVar4);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_78,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_80 = plVar5;
  plVar3 = local_80;
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))();
    local_res20 = (longlong *)0x0;
  }
  OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader(local_90);
  (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,4);
  OdDgTableElementMerge::setBaseRowIndex((OdDgTableElementMerge *)local_90,local_res18[0]);
  (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,2);
  local_res20 = (longlong *)0x0;
  if ((local_res18[0] & 0xffff) == 0x10) {
    OdDgDisplayStyleLinkage::createObject();
    (**(code **)(*local_98 + 0x78))(local_98,param_2,param_3);
    lVar1 = *local_98;
    pOVar4 = OdDgAttributeLinkage::desc();
    plVar6 = (longlong *)(**(code **)(lVar1 + 8))(local_98,pOVar4);
    if (plVar6 == (longlong *)0x0) {
      pOVar4 = OdDgAttributeLinkage::desc();
      pOVar7 = (OdRxClass *)(**(code **)(*local_98 + 0x18))(local_98);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_70,pOVar7,pOVar4);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_70,(ThrowInfo *)&DAT_180de5310);
    }
    local_res20 = plVar6;
    (**(code **)(*local_98 + 0x28))(local_98);
  }
  else if ((local_res18[0] & 0xffff) == 8) {
    (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,(local_res18[0] & 0xffff) - 6);
    if ((short)local_res18[0] == 1) {
      OdDgGradientFillLinkage::createObject();
      cVar2 = (**(code **)(*local_98 + 0x78))(local_98,param_2,param_3);
      plVar5 = local_res20;
      if (cVar2 != '\0') {
        plVar5 = (longlong *)
                 __RTDynamicCast(local_98,0,&OdDgGradientFillLinkage::RTTI_Type_Descriptor,
                                 &OdDgGradientFillLinkageImpl::RTTI_Type_Descriptor,0);
        (**(code **)(*plVar5 + 0x70))(plVar5,local_90);
        plVar5 = local_res20;
        if (local_98 != (longlong *)0x0) {
          pOVar4 = OdDgAttributeLinkage::desc();
          plVar6 = (longlong *)(**(code **)(*local_98 + 8))(local_98,pOVar4);
          plVar5 = plVar6;
          if (plVar6 == (longlong *)0x0) {
            pOVar4 = OdDgAttributeLinkage::desc();
            pOVar7 = (OdRxClass *)(**(code **)(*local_98 + 0x18))(local_98);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_68,pOVar7,pOVar4);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_68,(ThrowInfo *)&DAT_180de5310);
          }
        }
      }
      local_res20 = plVar5;
      if (local_98 != (longlong *)0x0) {
        (**(code **)(*local_98 + 0x28))(local_98);
      }
    }
    else {
      OdDgFillColorLinkage::createObject();
      if (param_3 < 0x10) {
        *param_1 = 0;
        if (local_98 != (longlong *)0x0) {
          (**(code **)(*local_98 + 0x28))();
        }
        OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_90);
        (**(code **)(*plVar3 + 0x28))(plVar3);
        return param_1;
      }
      (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,4);
      (**(code **)(*local_98 + 0x80))(local_98,local_res18[0]);
      plVar5 = (longlong *)
               __RTDynamicCast(local_98,0,&OdDgFillColorLinkage::RTTI_Type_Descriptor,
                               &OdDgFillColorLinkageImpl::RTTI_Type_Descriptor,0);
      (**(code **)(*plVar5 + 0x70))(plVar5,local_90);
      lVar1 = *local_98;
      pOVar4 = OdDgAttributeLinkage::desc();
      plVar6 = (longlong *)(**(code **)(lVar1 + 8))(local_98,pOVar4);
      if (plVar6 == (longlong *)0x0) {
        pOVar4 = OdDgAttributeLinkage::desc();
        pOVar7 = (OdRxClass *)(**(code **)(*local_98 + 0x18))(local_98);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_60,pOVar7,pOVar4);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_60,(ThrowInfo *)&DAT_180de5310);
      }
      local_res20 = plVar6;
      (**(code **)(*local_98 + 0x28))(local_98);
    }
  }
  else if ((ushort)((short)local_res18[0] - 0xcU) < 3) {
    if (param_3 < 0x10) {
      *param_1 = 0;
      OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_90);
      (**(code **)(*plVar3 + 0x28))(plVar3);
      return param_1;
    }
    OdDgInternalMaterialLinkage::createObject();
    (**(code **)(*plVar3 + 0x88))(plVar3,2,1);
    (**(code **)(*plVar3 + 0x98))(plVar3,&local_50,8);
    (**(code **)(*local_98 + 0x80))(local_98,local_50);
    (**(code **)(*local_98 + 0x90))(local_98,(local_res18[0] & 0xffff) - 0xc);
    plVar5 = (longlong *)
             __RTDynamicCast(local_98,0,&OdDgInternalMaterialLinkage::RTTI_Type_Descriptor,
                             &OdDgInternalMaterialLinkageImpl::RTTI_Type_Descriptor,0);
    (**(code **)(*plVar5 + 0x70))(plVar5,local_90);
    lVar1 = *local_98;
    pOVar4 = OdDgAttributeLinkage::desc();
    plVar6 = (longlong *)(**(code **)(lVar1 + 8))(local_98,pOVar4);
    if (plVar6 == (longlong *)0x0) {
      pOVar4 = OdDgAttributeLinkage::desc();
      pOVar7 = (OdRxClass *)(**(code **)(*local_98 + 0x18))(local_98);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_48,pOVar7,pOVar4);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_48,(ThrowInfo *)&DAT_180de5310);
    }
    local_res20 = plVar6;
    (**(code **)(*local_98 + 0x28))(local_98);
  }
  else {
    if ((short)local_res18[0] != 9) {
      *param_1 = 0;
      OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_90);
      (**(code **)(*plVar3 + 0x28))(plVar3);
      return param_1;
    }
    if (param_3 < 0x10) {
      *param_1 = 0;
      OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_90);
      (**(code **)(*plVar3 + 0x28))(plVar3);
      return param_1;
    }
    OdDgTransparencyLinkage::createObject();
    (**(code **)(*plVar3 + 0x88))(plVar3,2,1);
    lVar1 = *local_98;
    uVar8 = FUN_180833830(plVar3);
    (**(code **)(lVar1 + 0x80))(local_98,uVar8);
    plVar5 = (longlong *)
             __RTDynamicCast(local_98,0,&OdDgTransparencyLinkage::RTTI_Type_Descriptor,
                             &OdDgTransparencyLinkageImpl::RTTI_Type_Descriptor,0);
    (**(code **)(*plVar5 + 0x70))(plVar5,local_90);
    lVar1 = *local_98;
    pOVar4 = OdDgAttributeLinkage::desc();
    plVar6 = (longlong *)(**(code **)(lVar1 + 8))(local_98,pOVar4);
    if (plVar6 == (longlong *)0x0) {
      pOVar4 = OdDgAttributeLinkage::desc();
      pOVar7 = (OdRxClass *)(**(code **)(*local_98 + 0x18))(local_98);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_58,pOVar7,pOVar4);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_58,(ThrowInfo *)&DAT_180de5310);
    }
    local_res20 = plVar6;
    (**(code **)(*local_98 + 0x28))(local_98);
  }
  *param_1 = plVar6;
  if (plVar6 != (longlong *)0x0) {
    (**(code **)(*plVar6 + 0x20))(plVar6);
    (**(code **)(*plVar6 + 0x28))(plVar6);
  }
  OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_90);
  (**(code **)(*plVar3 + 0x28))(plVar3);
  return param_1;
}



/* ==== 1808bfd80 FUN_1808bfd80 ==== */

longlong * FUN_1808bfd80(longlong *param_1,__uint64 param_2,uint param_3)

{
  double dVar1;
  bool bVar2;
  longlong *plVar3;
  OdRxClass *pOVar4;
  longlong *plVar5;
  OdGeVector3d *pOVar6;
  longlong lVar7;
  OdRxClass *pOVar8;
  uint uVar9;
  ulong local_res18 [2];
  undefined8 local_res20;
  longlong *local_68;
  longlong *local_60;
  OdDgAttributeLinkageHeader local_58 [16];
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  
  plVar3 = (longlong *)OdFlatMemStream::createNew(&local_res20,param_2,(ulonglong)param_3);
  local_68 = (longlong *)0x0;
  plVar3 = (longlong *)*plVar3;
  plVar5 = local_68;
  if (plVar3 != (longlong *)0x0) {
    lVar7 = *plVar3;
    pOVar4 = OdStreamBuf::desc();
    plVar5 = (longlong *)(**(code **)(lVar7 + 8))(plVar3,pOVar4);
    if (plVar5 == (longlong *)0x0) {
      pOVar4 = OdStreamBuf::desc();
      pOVar8 = (OdRxClass *)(**(code **)(*plVar3 + 0x18))(plVar3);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_68,pOVar8,pOVar4);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_68,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_68 = plVar5;
  plVar3 = local_68;
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))();
    local_res20 = (longlong *)0x0;
  }
  OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader(local_58);
  (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,4);
  OdDgTableElementMerge::setBaseRowIndex((OdDgTableElementMerge *)local_58,local_res18[0]);
  OdDgThicknessLinkage::createObject();
  plVar5 = (longlong *)
           __RTDynamicCast(local_60,0,&OdDgThicknessLinkage::RTTI_Type_Descriptor,
                           &OdDgThicknessLinkageImpl::RTTI_Type_Descriptor,0);
  if (plVar5 != (longlong *)0x0) {
    (**(code **)(*plVar5 + 0x70))(plVar5,local_58);
  }
  (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,4);
  if (param_3 < 0x20) {
    (**(code **)(*plVar3 + 0x98))(plVar3,&local_res20,8);
    uVar9 = (local_res20._7_1_ & 0x7f) << 4 | (uint)(local_res20._6_1_ >> 4);
    if ((uVar9 == 0) || (uVar9 == 0x7ff)) {
      (**(code **)(*local_60 + 0x80))(local_60,0);
    }
    else {
      (**(code **)(*local_60 + 0x80))(local_60,local_res20);
    }
  }
  else {
    local_48 = 0;
    uStack_40 = 0;
    local_38 = 0;
    (**(code **)(*plVar3 + 0x98))(plVar3,&local_48,0x18);
    uVar9 = (local_48._7_1_ & 0x7f) << 4 | (uint)(local_48._6_1_ >> 4);
    if ((uVar9 == 0) || (uVar9 == 0x7ff)) {
      local_48 = 0;
    }
    uVar9 = (uStack_40._7_1_ & 0x7f) << 4 | (uint)(uStack_40._6_1_ >> 4);
    if ((uVar9 == 0) || (uVar9 == 0x7ff)) {
      uStack_40 = 0;
    }
    uVar9 = (local_38._7_1_ & 0x7f) << 4 | (uint)(local_38._6_1_ >> 4);
    if ((uVar9 == 0) || (uVar9 == 0x7ff)) {
      local_38 = 0;
    }
    lVar7 = *plVar5;
    dVar1 = OdGeVector3d::length((OdGeVector3d *)&local_48);
    (**(code **)(lVar7 + 0x80))(plVar5,dVar1);
    bVar2 = OdGeVector3d::isZeroLength((OdGeVector3d *)&local_48,(OdGeTol *)gTol_exref);
    if (!bVar2) {
      lVar7 = *plVar5;
      pOVar6 = OdGeVector3d::normalize((OdGeVector3d *)&local_48,(OdGeTol *)gTol_exref);
      (**(code **)(lVar7 + 0x90))(plVar5,pOVar6);
    }
    *(ulong *)(plVar5 + 8) = local_res18[0];
  }
  *param_1 = 0;
  if (local_60 != (longlong *)0x0) {
    lVar7 = *local_60;
    pOVar4 = OdDgAttributeLinkage::desc();
    lVar7 = (**(code **)(lVar7 + 8))(local_60,pOVar4);
    if (lVar7 == 0) {
      pOVar4 = OdDgAttributeLinkage::desc();
      pOVar8 = (OdRxClass *)(**(code **)(*local_60 + 0x18))(local_60);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_res20,pOVar8,pOVar4);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5310);
    }
    *param_1 = lVar7;
  }
  if (local_60 != (longlong *)0x0) {
    (**(code **)(*local_60 + 0x28))(local_60);
  }
  OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_58);
  (**(code **)(*plVar3 + 0x28))(plVar3);
  return param_1;
}



/* ==== 1808c4270 FUN_1808c4270 ==== */

longlong * FUN_1808c4270(longlong *param_1,undefined8 param_2,undefined4 param_3)

{
  OdRxClass *pOVar1;
  longlong lVar2;
  OdRxClass *pOVar3;
  OdError_NotThatKindOfClass local_res20 [8];
  
  OdDgSheetAnnotationScaleLinkage::createObject();
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



/* ==== 1808ce340 FUN_1808ce340 ==== */

longlong * FUN_1808ce340(longlong *param_1,__uint64 param_2,uint param_3)

{
  longlong *plVar1;
  OdRxClass *pOVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  OdRxClass *pOVar6;
  ulong local_res18 [2];
  longlong *local_res20;
  longlong *local_38;
  OdError_NotThatKindOfClass local_30 [8];
  OdDgAttributeLinkageHeader local_28 [16];
  
  plVar1 = (longlong *)OdFlatMemStream::createNew(&local_res20,param_2,(ulonglong)param_3);
  local_38 = (longlong *)0x0;
  plVar1 = (longlong *)*plVar1;
  plVar3 = local_38;
  if (plVar1 != (longlong *)0x0) {
    lVar5 = *plVar1;
    pOVar2 = OdStreamBuf::desc();
    plVar3 = (longlong *)(**(code **)(lVar5 + 8))(plVar1,pOVar2);
    if (plVar3 == (longlong *)0x0) {
      pOVar2 = OdStreamBuf::desc();
      pOVar6 = (OdRxClass *)(**(code **)(*plVar1 + 0x18))(plVar1);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_38,pOVar6,pOVar2);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_38,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_38 = plVar3;
  plVar1 = local_38;
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))();
    local_res20 = (longlong *)0x0;
  }
  OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader(local_28);
  (**(code **)(*plVar1 + 0x98))(plVar1,local_res18,4);
  OdDgTableElementMerge::setBaseRowIndex((OdDgTableElementMerge *)local_28,local_res18[0]);
  OdDgInfiniteLineLinkage::createObject();
  plVar3 = local_res20;
  plVar4 = (longlong *)
           __RTDynamicCast(local_res20,0,&OdDgInfiniteLineLinkage::RTTI_Type_Descriptor,
                           &OdDgInfiniteLineLinkageImpl::RTTI_Type_Descriptor,0);
  if (plVar4 != (longlong *)0x0) {
    (**(code **)(*plVar4 + 0x70))(plVar4,local_28);
  }
  (**(code **)(*plVar1 + 0x98))(plVar1,local_res18,4);
  (**(code **)(*plVar3 + 0x80))(plVar3,local_res18[0]);
  *param_1 = 0;
  lVar5 = *plVar3;
  pOVar2 = OdDgAttributeLinkage::desc();
  lVar5 = (**(code **)(lVar5 + 8))(plVar3,pOVar2);
  if (lVar5 == 0) {
    pOVar2 = OdDgAttributeLinkage::desc();
    pOVar6 = (OdRxClass *)(**(code **)(*plVar3 + 0x18))(plVar3);
    OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_30,pOVar6,pOVar2);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_30,(ThrowInfo *)&DAT_180de5310);
  }
  *param_1 = lVar5;
  (**(code **)(*plVar3 + 0x28))(plVar3);
  OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader(local_28);
  (**(code **)(*plVar1 + 0x28))(plVar1);
  return param_1;
}



/* ==== 1809d8250 FUN_1809d8250 ==== */

longlong * FUN_1809d8250(longlong *param_1,__uint64 param_2,uint param_3)

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
  OdDgSharedCellFlagsLinkage::createObject();
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



