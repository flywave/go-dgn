/* ==== 18052f250 FUN_18052f250 ==== */

void FUN_18052f250(OdDgElement *param_1,longlong *param_2)

{
  code *pcVar1;
  int iVar2;
  longlong *plVar3;
  longlong *plVar4;
  longlong lVar5;
  undefined4 uVar6;
  longlong *plVar7;
  OdRxClass *pOVar8;
  longlong *plVar9;
  OdRxClass *pOVar10;
  uint uVar11;
  uint uVar12;
  ulonglong uVar13;
  code *local_res8;
  longlong *local_res10;
  longlong *local_res18;
  longlong *local_res20;
  longlong *local_68;
  longlong *local_60;
  longlong *local_58;
  OdError_InvalidIndex local_50 [8];
  longlong **local_48;
  
  plVar3 = (longlong *)param_2[1];
  plVar4 = *(longlong **)(param_1 + 8);
  FUN_180010890(plVar3);
  FUN_180010890(plVar4);
  plVar7 = (longlong *)OdMemoryStream::createNew((ulong)&local_res18);
  local_60 = (longlong *)0x0;
  plVar7 = (longlong *)*plVar7;
  plVar9 = local_60;
  if (plVar7 != (longlong *)0x0) {
    lVar5 = *plVar7;
    pOVar8 = OdStreamBuf::desc();
    plVar9 = (longlong *)(**(code **)(lVar5 + 8))(plVar7,pOVar8);
    if (plVar9 == (longlong *)0x0) {
      pOVar8 = OdStreamBuf::desc();
      pOVar10 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_60,pOVar10,pOVar8);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_60,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_60 = plVar9;
  plVar7 = local_60;
  if (local_res18 != (longlong *)0x0) {
    (**(code **)(*local_res18 + 0x28))();
    local_res18 = (longlong *)0x0;
  }
  local_res20 = plVar7;
  if (plVar7 != (longlong *)0x0) {
    (**(code **)(*plVar7 + 0x20))(plVar7);
  }
  FUN_1801c4f80(&local_res10,&local_res20);
  local_res8 = g_empty_array_buffer_exref + 0x10;
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  (**(code **)(*(longlong *)param_1 + 400))(param_1,local_res10);
  (**(code **)(*plVar4 + 0x1a0))(plVar4,0);
  OdDgElement::getXAttributes
            (param_1,(OdArray<OdRxObjectPtr,OdObjectsAllocator<OdRxObjectPtr>_> *)&local_res8);
  uVar13 = 0;
  uVar11 = *(uint *)(local_res8 + -4);
  if (uVar11 != 0) {
    do {
      if (uVar11 <= (uint)uVar13) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_50);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_50,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      pcVar1 = local_res8 + -0x10;
      iVar2 = *(int *)pcVar1;
      *(int *)pcVar1 = *(int *)pcVar1;
      UNLOCK();
      if (1 < iVar2) {
        FUN_18000cd30(&local_res8,*(undefined4 *)(local_res8 + -8),0,0,1);
      }
      local_58 = (longlong *)0x0;
      plVar4 = *(longlong **)(local_res8 + uVar13 * 8);
      plVar7 = local_58;
      if (plVar4 != (longlong *)0x0) {
        lVar5 = *plVar4;
        pOVar8 = OdDgXAttribute::desc();
        plVar7 = (longlong *)(**(code **)(lVar5 + 8))(plVar4,pOVar8);
        if (plVar7 == (longlong *)0x0) {
          pOVar8 = OdDgXAttribute::desc();
          pOVar10 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_res18,pOVar10,pOVar8);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_res18,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_58 = plVar7;
      plVar4 = local_58;
      local_48 = &local_68;
      local_68 = local_58;
      if (local_58 != (longlong *)0x0) {
        (**(code **)(*local_58 + 0x20))(local_58);
      }
      uVar6 = (**(code **)(*plVar4 + 0x58))(plVar4);
      FUN_1801c1f00(param_2,uVar6);
      (**(code **)(*plVar4 + 0x28))(plVar4);
      uVar12 = (uint)uVar13 + 1;
      uVar13 = (ulonglong)uVar12;
      uVar11 = *(uint *)(local_res8 + -4);
    } while (uVar12 < uVar11);
  }
  FUN_18001fb50(local_res10);
  (**(code **)(*param_2 + 0x188))(param_2,local_res10);
  (**(code **)(*plVar3 + 0x198))(plVar3,0);
  FUN_1800144b0(local_res8 + -0x10);
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 0x28))();
    local_res10 = (longlong *)0x0;
  }
  if (local_60 != (longlong *)0x0) {
    (**(code **)(*local_60 + 0x28))();
  }
  return;
}



/* ==== 1809e18e0 FUN_1809e18e0 ==== */

undefined8 FUN_1809e18e0(undefined8 param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  longlong *plVar1;
  bool bVar2;
  longlong lVar3;
  longlong lVar4;
  OdDgDatabase *pOVar5;
  OdDbHandle *pOVar6;
  longlong *plVar7;
  OdRxClass *pOVar8;
  longlong *plVar9;
  longlong *plVar10;
  undefined8 uVar11;
  OdRxClass *pOVar12;
  longlong *local_res10;
  longlong *local_res18;
  longlong *local_res20;
  longlong *local_78;
  OdError local_70 [8];
  longlong *local_68;
  OdError_NotThatKindOfClass local_60 [8];
  OdError_NotThatKindOfClass local_58 [8];
  longlong local_50;
  longlong local_48 [2];
  
  plVar1 = (longlong *)param_2[1];
  lVar4 = param_3[1];
  local_res20 = param_4;
  local_50 = lVar4;
  lVar3 = FUN_180010890(plVar1);
  lVar4 = FUN_180010890(lVar4);
  if ((lVar4 != 0) && (lVar3 == 0)) {
    if ((longlong *)plVar1[0xb] != (longlong *)0x0) {
      local_res10 = (longlong *)plVar1[0xb];
      pOVar5 = OdDgElementId::database((OdDgElementId *)&local_res10);
      if (pOVar5 == (OdDgDatabase *)0x0) {
LAB_1809e1973:
        bVar2 = false;
      }
      else {
        local_res18 = (longlong *)plVar1[0xb];
        pOVar6 = OdDgElementId::getHandle((OdDgElementId *)&local_res18);
        if (*(longlong *)pOVar6 == 0) goto LAB_1809e1973;
        bVar2 = true;
      }
      if (bVar2) {
        OdError::OdError(local_70,0x1f);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_70,(ThrowInfo *)&DAT_180de52b8);
      }
    }
    plVar1[0xd] = lVar4;
  }
  bVar2 = true;
  plVar7 = (longlong *)OdMemoryStream::createNew((ulong)&local_res10);
  local_68 = (longlong *)0x0;
  plVar7 = (longlong *)*plVar7;
  plVar9 = local_68;
  if (plVar7 != (longlong *)0x0) {
    pOVar8 = OdStreamBuf::desc();
    plVar9 = (longlong *)(**(code **)(*plVar7 + 8))(plVar7,pOVar8);
    if (plVar9 == (longlong *)0x0) {
      pOVar8 = OdStreamBuf::desc();
      pOVar12 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_60,pOVar12,pOVar8);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_60,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_68 = plVar9;
  plVar7 = local_68;
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 0x28))();
    local_res10 = (longlong *)0x0;
  }
  local_res18 = plVar7;
  if (plVar7 != (longlong *)0x0) {
    (**(code **)(*plVar7 + 0x20))(plVar7);
  }
  plVar9 = (longlong *)OdDgFileFiler::createObject(&local_78,&local_res18,0);
  local_res10 = (longlong *)0x0;
  plVar9 = (longlong *)*plVar9;
  plVar10 = local_res10;
  if (plVar9 != (longlong *)0x0) {
    pOVar8 = OdDgFiler::desc();
    plVar10 = (longlong *)(**(code **)(*plVar9 + 8))(plVar9,pOVar8);
    if (plVar10 == (longlong *)0x0) {
      pOVar8 = OdDgFiler::desc();
      pOVar12 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_58,pOVar12,pOVar8);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_58,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_res10 = plVar10;
  plVar9 = local_res10;
  if (local_78 != (longlong *)0x0) {
    (**(code **)(*local_78 + 0x28))();
    local_78 = (longlong *)0x0;
  }
  (**(code **)(*param_3 + 400))(param_3,plVar9);
  (**(code **)(*plVar9 + 0x78))(plVar9,0,0);
  (**(code **)(*param_2 + 0x188))(param_2,plVar9);
  lVar4 = *(longlong *)(local_50 + 0x58);
  plVar10 = *(longlong **)(lVar4 + 0x18);
  if (plVar10 != param_2) {
    if (plVar10 != (longlong *)0x0) {
      (**(code **)(*plVar10 + 0x28))();
      *(undefined8 *)(lVar4 + 0x18) = 0;
    }
    *(longlong **)(lVar4 + 0x18) = param_2;
    (**(code **)(*param_2 + 0x20))(param_2);
  }
  plVar1[0xb] = lVar4;
  if ((lVar4 != 0) &&
     (local_50 = lVar4, pOVar5 = OdDgElementId::database((OdDgElementId *)&local_50),
     pOVar5 != (OdDgDatabase *)0x0)) {
    local_48[0] = plVar1[0xb];
    pOVar6 = OdDgElementId::getHandle((OdDgElementId *)local_48);
    if (*(longlong *)pOVar6 != 0) goto LAB_1809e1b10;
  }
  bVar2 = false;
LAB_1809e1b10:
  plVar10 = local_res20;
  if (bVar2) {
    plVar1[0xd] = 0;
  }
  if (*local_res20 != 0) {
    pOVar6 = OdDgElementId::getHandle((OdDgElementId *)(plVar1 + 0xb));
    local_48[0] = *(longlong *)pOVar6;
    uVar11 = FUN_1809ea9f0(*plVar10,&local_50,local_48);
    FUN_180128d60(plVar1,uVar11);
    (**(code **)(*plVar1 + 0x198))(plVar1,0);
  }
  (**(code **)(*plVar9 + 0x28))(plVar9);
  if (plVar7 != (longlong *)0x0) {
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  return 1;
}



/* ==== 1809e2b40 FUN_1809e2b40 ==== */

void FUN_1809e2b40(longlong *param_1,longlong *param_2,longlong *param_3,longlong *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  OdDbHandle *pOVar6;
  longlong *plVar7;
  undefined8 uVar8;
  longlong *plVar9;
  OdRxClass *pOVar10;
  OdRxClass *pOVar11;
  code *pcVar12;
  code *pcVar13;
  int iVar14;
  undefined2 local_res8 [4];
  longlong *local_res10;
  code *local_res18;
  longlong *local_res20;
  longlong *local_58;
  longlong *local_50;
  
  iVar2 = (**(code **)(*param_4 + 0x80))(param_4);
  (**(code **)(*param_3 + 0x110))(param_3,param_4);
  (**(code **)(*param_2 + 0x1a0))(param_2,param_4);
  iVar3 = (**(code **)(*param_4 + 0x80))(param_4);
  local_res10 = (longlong *)CONCAT44(local_res10._4_4_,iVar3);
  (**(code **)(*param_3 + 0x188))(param_3,param_4);
  iVar4 = (**(code **)(*param_4 + 0x80))(param_4);
  iVar14 = iVar4 - iVar2;
  (**(code **)(*param_3 + 0x118))(param_3,iVar3 - iVar2,iVar14);
  lVar5 = __RTDynamicCast(param_3,0,&OdDgElementImpl::RTTI_Type_Descriptor,
                          &EDimension::RTTI_Type_Descriptor,0);
  if ((lVar5 != 0) && (cVar1 = FUN_18025b460(lVar5), cVar1 != '\0')) {
    local_res18 = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
    UNLOCK();
    FUN_1800150c0(&local_res18,iVar14);
    (**(code **)(*param_4 + 0x78))(param_4,iVar2,0);
    FUN_18000d0b0(&local_res18);
    pcVar13 = (code *)0x0;
    if (*(int *)(local_res18 + -4) != 0) {
      pcVar13 = local_res18;
    }
    (**(code **)(*param_4 + 0x90))(param_4,pcVar13,iVar14);
    FUN_18000d0b0();
    pcVar13 = local_res18;
    pcVar12 = (code *)0x0;
    if (*(int *)(local_res18 + -4) != 0) {
      pcVar12 = local_res18;
    }
    cVar1 = FUN_180255090(pcVar12,iVar14,iVar4 - (int)local_res10,local_res8);
    if (cVar1 != '\0') {
      (**(code **)(*param_4 + 0x78))(param_4,iVar2,0);
      FUN_18000d0b0();
      pcVar13 = local_res18;
      pcVar12 = (code *)0x0;
      if (*(int *)(local_res18 + -4) != 0) {
        pcVar12 = local_res18;
      }
      FUN_180267910(pcVar12,iVar14,local_res8[0],param_4);
    }
    pcVar13 = pcVar13 + -0x10;
    LOCK();
    iVar3 = *(int *)pcVar13;
    *(int *)pcVar13 = *(int *)pcVar13 + -1;
    UNLOCK();
    if ((iVar3 == 1) && (pcVar13 != g_empty_array_buffer_exref)) {
      odrxFree();
    }
  }
  (**(code **)(*param_4 + 0x78))(param_4,iVar2,0);
  (**(code **)(*param_3 + 0x110))(param_3,param_4);
  *(ushort *)(param_3 + 9) = *(ushort *)(param_3 + 9) & 0xfeff;
  (**(code **)(*param_4 + 0x78))(param_4,iVar4,0);
  (**(code **)(*param_3 + 0x1a0))(param_3,0);
  FUN_18011ec30(param_3,&local_res20);
  if ((local_res20 != (longlong *)0x0) &&
     (pOVar6 = OdDgElementId::getHandle((OdDgElementId *)(param_3 + 0xb)),
     local_res20[3] != *(longlong *)pOVar6)) {
    pOVar6 = OdDgElementId::getHandle((OdDgElementId *)(param_3 + 0xb));
    local_res20[3] = *(longlong *)pOVar6;
  }
  plVar7 = (longlong *)(**(code **)(*param_1 + 0xb0))(param_1,&local_res10);
  local_50 = (longlong *)0x0;
  plVar7 = (longlong *)*plVar7;
  plVar9 = local_50;
  if (plVar7 != (longlong *)0x0) {
    lVar5 = *plVar7;
    uVar8 = FUN_18004c170();
    plVar9 = (longlong *)(**(code **)(lVar5 + 8))(plVar7,uVar8);
    if (plVar9 == (longlong *)0x0) {
      pOVar10 = (OdRxClass *)FUN_18004c170();
      pOVar11 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_58,pOVar11,pOVar10);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_58,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_50 = plVar9;
  plVar7 = local_50;
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 0x28))();
    local_res10 = (longlong *)0x0;
  }
  if (((plVar7 != (longlong *)0x0) && (local_res20 != (longlong *)0x0)) &&
     (*(int *)(local_res20[4] + -4) != 0)) {
    local_58 = local_res20;
    (**(code **)(*local_res20 + 0x20))();
    FUN_1809ea890(plVar7,&local_58);
  }
  if (plVar7 != (longlong *)0x0) {
    (**(code **)(*plVar7 + 0x28))(plVar7);
  }
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))();
  }
  return;
}



/* ==== 1809e3730 FUN_1809e3730 ==== */

void FUN_1809e3730(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  longlong *plVar2;
  longlong *plVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  OdRxClass *pOVar9;
  longlong *plVar10;
  longlong *plVar11;
  OdDgDatabase *pOVar12;
  OdDgElementId *this;
  OdRxClass *pOVar13;
  code *pcVar14;
  longlong lVar15;
  longlong **local_res8;
  longlong *local_res10;
  code *local_res18;
  longlong *local_res20;
  longlong *local_78;
  longlong *local_70;
  longlong *local_68;
  longlong *local_60;
  undefined1 local_58 [24];
  
  local_res10 = param_2;
  pOVar9 = OdDgDictionary::desc();
  plVar10 = (longlong *)(**(code **)(*(longlong *)*param_1 + 0x18))();
  cVar4 = (**(code **)(*plVar10 + 0x60))(plVar10,pOVar9);
  if (cVar4 == '\0') {
    plVar10 = (longlong *)OdMemoryStream::createNew((ulong)&local_70);
    local_60 = (longlong *)0x0;
    plVar10 = (longlong *)*plVar10;
    plVar11 = local_60;
    if (plVar10 != (longlong *)0x0) {
      lVar1 = *plVar10;
      pOVar9 = OdStreamBuf::desc();
      plVar11 = (longlong *)(**(code **)(lVar1 + 8))(plVar10,pOVar9);
      if (plVar11 == (longlong *)0x0) {
        pOVar9 = OdStreamBuf::desc();
        pOVar13 = (OdRxClass *)(**(code **)(*plVar10 + 0x18))(plVar10);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_60,pOVar13,pOVar9);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_60,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_60 = plVar11;
    plVar10 = local_60;
    if (local_70 != (longlong *)0x0) {
      (**(code **)(*local_70 + 0x28))();
      local_70 = (longlong *)0x0;
    }
    local_res8 = &local_68;
    local_68 = plVar10;
    if (plVar10 != (longlong *)0x0) {
      (**(code **)(*plVar10 + 0x20))(plVar10);
    }
    pOVar12 = OdDgElement::database((OdDgElement *)*param_1);
    OdDgFileFiler::createObject(&local_78,&local_68,pOVar12);
    plVar3 = local_78;
    plVar11 = (longlong *)*param_1;
    plVar2 = (longlong *)plVar11[1];
    iVar5 = (**(code **)(*local_78 + 0x80))(local_78);
    (**(code **)(*plVar2 + 0x110))(plVar2,plVar3);
    (**(code **)(*plVar11 + 0x1a0))(plVar11,plVar3);
    iVar6 = (**(code **)(*plVar3 + 0x80))(plVar3);
    (**(code **)(*plVar2 + 0x188))(plVar2,plVar3);
    iVar7 = (**(code **)(*plVar3 + 0x80))(plVar3);
    (**(code **)(*plVar2 + 0x118))(plVar2,iVar6 - iVar5,iVar7 - iVar5);
    (**(code **)(*plVar3 + 0x78))(plVar3,iVar5,0);
    (**(code **)(*plVar2 + 0x110))(plVar2,plVar3);
    (**(code **)(*plVar3 + 0x78))(plVar3,iVar7,0);
    plVar11 = *(longlong **)(*param_1 + 8);
    if (plVar11 != (longlong *)0x0) {
      (**(code **)(*plVar11 + 0x1e8))(plVar11,&local_res8);
      if (local_res8 != (longlong **)0x0) {
        cVar4 = (*(code *)(*local_res8)[0xc])();
        while (cVar4 == '\0') {
          this = (OdDgElementId *)(*(code *)(*local_res8)[0xd])(local_res8,local_58);
          OdDgElementId::openObject(this,(OpenMode)&local_res20,false);
          if (local_res20 != (longlong *)0x0) {
            local_res18 = g_empty_array_buffer_exref + 0x10;
            LOCK();
            *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
            UNLOCK();
            FUN_1809e3730(&local_res20);
            plVar10 = local_78;
            uVar8 = *(undefined4 *)(local_res18 + -4);
            FUN_18000d0b0(&local_res18);
            pcVar14 = (code *)0x0;
            if (*(int *)(local_res18 + -4) != 0) {
              pcVar14 = local_res18;
            }
            (**(code **)(*plVar10 + 0x140))(plVar10,pcVar14,uVar8);
            pcVar14 = local_res18 + -0x10;
            LOCK();
            iVar5 = *(int *)pcVar14;
            *(int *)pcVar14 = *(int *)pcVar14 + -1;
            UNLOCK();
            if ((iVar5 == 1) && (pcVar14 != g_empty_array_buffer_exref)) {
              odrxFree();
            }
          }
          if (local_res20 != (longlong *)0x0) {
            (**(code **)(*local_res20 + 0x28))();
            local_res20 = (longlong *)0x0;
          }
          (*(code *)(*local_res8)[0xe])(local_res8,1);
          cVar4 = (*(code *)(*local_res8)[0xc])();
          plVar10 = local_60;
        }
      }
      if (local_res8 != (longlong **)0x0) {
        (*(code *)(*local_res8)[5])();
      }
    }
    uVar8 = (**(code **)(*plVar10 + 0x70))(plVar10);
    (**(code **)(*plVar10 + 0x88))(plVar10,0,0);
    plVar11 = local_res10;
    FUN_1800150c0(local_res10);
    FUN_18000d0b0(plVar11);
    lVar1 = *plVar11;
    lVar15 = 0;
    if (*(int *)(lVar1 + -4) != 0) {
      lVar15 = lVar1;
    }
    (**(code **)(*plVar10 + 0x98))(plVar10,lVar15,uVar8);
    if (local_78 != (longlong *)0x0) {
      (**(code **)(*local_78 + 0x28))();
      local_78 = (longlong *)0x0;
    }
    (**(code **)(*plVar10 + 0x28))(plVar10);
  }
  return;
}



