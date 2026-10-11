/* ==== 18082a140 FUN_18082a140 ==== */

void FUN_18082a140(longlong param_1,__uint64 param_2,uint param_3)

{
  ulonglong *puVar1;
  int *piVar2;
  undefined8 *puVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  char cVar7;
  longlong *plVar8;
  OdRxClass *pOVar9;
  longlong *plVar10;
  OdRxClass *pOVar11;
  uint uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 local_res18 [2];
  uint local_res20 [2];
  undefined6 local_78;
  byte bStack_72;
  byte bStack_71;
  undefined6 local_70;
  byte bStack_6a;
  byte bStack_69;
  undefined6 local_68;
  byte bStack_62;
  byte bStack_61;
  longlong *local_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  longlong *local_40;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined8 local_28;
  
  plVar8 = (longlong *)OdFlatMemStream::createNew(&local_40,param_2,(ulonglong)param_3);
  local_60 = (longlong *)0x0;
  plVar8 = (longlong *)*plVar8;
  plVar10 = local_60;
  if (plVar8 != (longlong *)0x0) {
    lVar6 = *plVar8;
    pOVar9 = OdStreamBuf::desc();
    plVar10 = (longlong *)(**(code **)(lVar6 + 8))(plVar8,pOVar9);
    if (plVar10 == (longlong *)0x0) {
      pOVar9 = OdStreamBuf::desc();
      pOVar11 = (OdRxClass *)(**(code **)(*plVar8 + 0x18))(plVar8);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res20,pOVar11,pOVar9);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_60 = plVar10;
  plVar8 = local_60;
  if (local_40 != (longlong *)0x0) {
    (**(code **)(*local_40 + 0x28))();
    local_40 = (longlong *)0x0;
  }
  (**(code **)(*plVar8 + 0x98))(plVar8,local_res18,4);
  (**(code **)(*(longlong *)(param_1 + 0x18) + 0x68))((longlong *)(param_1 + 0x18),local_res18[0]);
  (**(code **)(*plVar8 + 0x98))(plVar8,local_res20,4);
  if (local_res20[0] != 0) {
    puVar1 = (ulonglong *)(param_1 + 0x10);
    uVar15 = (ulonglong)local_res20[0];
    do {
      local_58 = *(undefined8 *)kOrigin_exref;
      uStack_50 = *(undefined8 *)(kOrigin_exref + 8);
      local_48 = *(undefined8 *)(kOrigin_exref + 0x10);
      cVar7 = (**(code **)(*plVar8 + 0x60))(plVar8);
      if (cVar7 == '\0') {
        (**(code **)(*plVar8 + 0x98))(plVar8,&local_78,8);
        uVar12 = (bStack_71 & 0x7f) << 4 | (uint)(bStack_72 >> 4);
        if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
          uVar16 = 0;
          uVar17 = 0;
        }
        else {
          uVar16 = (undefined4)local_78;
          uVar17 = (undefined4)(CONCAT17(bStack_71,CONCAT16(bStack_72,local_78)) >> 0x20);
        }
        local_58 = CONCAT44(uVar17,uVar16);
        (**(code **)(*plVar8 + 0x98))(plVar8,&local_70,8);
        uVar12 = (bStack_69 & 0x7f) << 4 | (uint)(bStack_6a >> 4);
        if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
          uVar16 = 0;
          uVar17 = 0;
        }
        else {
          uVar16 = (undefined4)local_70;
          uVar17 = (undefined4)(CONCAT17(bStack_69,CONCAT16(bStack_6a,local_70)) >> 0x20);
        }
        uStack_50 = CONCAT44(uVar17,uVar16);
        (**(code **)(*plVar8 + 0x98))(plVar8,&local_68,8);
        uVar12 = (bStack_61 & 0x7f) << 4 | (uint)(bStack_62 >> 4);
        if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
          uVar16 = 0;
          uVar17 = 0;
        }
        else {
          uVar16 = (undefined4)local_68;
          uVar17 = (undefined4)(CONCAT17(bStack_61,CONCAT16(bStack_62,local_68)) >> 0x20);
        }
        local_48 = CONCAT44(uVar17,uVar16);
      }
      uVar12 = *(uint *)(*puVar1 - 4);
      uVar14 = (ulonglong)uVar12;
      LOCK();
      piVar2 = (int *)(*puVar1 - 0x10);
      iVar4 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if ((iVar4 < 2) && (uVar12 != *(uint *)(*puVar1 - 8))) {
LAB_18082a3c9:
        uVar13 = *puVar1;
        puVar3 = (undefined8 *)(uVar13 + uVar14 * 0x18);
        *puVar3 = local_58;
        puVar3[1] = uStack_50;
        *(undefined8 *)(uVar13 + 0x10 + uVar14 * 0x18) = local_48;
      }
      else {
        if (*(int *)(*puVar1 - 4) != 0) {
          FUN_180018080(puVar1);
          if ((*(int *)((longlong)*puVar1 - 4) == 0) || ((undefined8 *)*puVar1 <= &local_58))
          goto LAB_18082a337;
LAB_18082a3af:
          FUN_18016f520(puVar1,uVar12 + 1,iVar4 < 2,0,1);
          goto LAB_18082a3c9;
        }
LAB_18082a337:
        if (*(int *)(*puVar1 - 4) == 0) goto LAB_18082a3af;
        FUN_180018080(puVar1);
        uVar5 = *(uint *)(*puVar1 - 4);
        uVar13 = 0;
        if (uVar5 != 0) {
          uVar13 = *puVar1;
        }
        if ((undefined8 *)(uVar13 + (ulonglong)uVar5 * 0x18) <= &local_58) goto LAB_18082a3af;
        local_38 = (undefined4)local_58;
        uStack_34 = local_58._4_4_;
        uStack_30 = (undefined4)uStack_50;
        uStack_2c = uStack_50._4_4_;
        local_28 = local_48;
        FUN_18016f520(puVar1,uVar12 + 1,iVar4 < 2,0,1);
        memmove((void *)(*puVar1 + uVar14 * 0x18),&local_38,0x18);
      }
      *(int *)(*puVar1 - 4) = *(int *)(*puVar1 - 4) + 1;
      uVar15 = uVar15 - 1;
      plVar8 = local_60;
    } while (uVar15 != 0);
  }
  (**(code **)(*plVar8 + 0x28))(plVar8);
  return;
}



/* ==== 1808340b0 FUN_1808340b0 ==== */

char FUN_1808340b0(OdDgDimStackedLocation *param_1,__uint64 param_2,uint param_3)

{
  OdDgDimStackedLocation OVar1;
  OdDgDimStackedLocation OVar2;
  OdDgDimStackedLocation OVar3;
  undefined4 uVar4;
  longlong lVar5;
  ToolType TVar6;
  longlong *plVar7;
  OdRxClass *pOVar8;
  longlong *plVar9;
  OdRxClass *pOVar10;
  char cVar11;
  OdDgDimStackedLocation local_res8 [8];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  longlong *local_50;
  longlong *local_48;
  
  TVar6 = OdDgDimStackedLocation::dimensionType(param_1);
  uVar4 = *(undefined4 *)(param_1 + 0x10);
  OVar1 = param_1[0x14];
  OVar2 = param_1[0x15];
  local_res8[0] = param_1[0x16];
  OVar3 = param_1[0x17];
  local_64 = *(undefined4 *)(param_1 + 0x18);
  local_60 = *(undefined4 *)(param_1 + 0x1c);
  local_5c = *(undefined4 *)(param_1 + 0x20);
  local_58 = *(undefined4 *)(param_1 + 0x24);
  local_54 = *(undefined4 *)(param_1 + 0x28);
  if (param_3 == TVar6 + 0x1c) {
    plVar7 = (longlong *)OdFlatMemStream::createNew(&local_50,param_2,(ulonglong)param_3);
    local_48 = (longlong *)0x0;
    plVar7 = (longlong *)*plVar7;
    plVar9 = local_48;
    if (plVar7 != (longlong *)0x0) {
      lVar5 = *plVar7;
      pOVar8 = OdStreamBuf::desc();
      plVar9 = (longlong *)(**(code **)(lVar5 + 8))(plVar7,pOVar8);
      if (plVar9 == (longlong *)0x0) {
        pOVar8 = OdStreamBuf::desc();
        pOVar10 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)local_res8,pOVar10,pOVar8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_48 = plVar9;
    plVar7 = local_48;
    if (local_50 != (longlong *)0x0) {
      (**(code **)(*local_50 + 0x28))();
      local_50 = (longlong *)0x0;
    }
    (**(code **)(*plVar7 + 0x98))(plVar7,&local_68,4);
    (**(code **)(*(longlong *)(param_1 + 0x30) + 0x68))(param_1 + 0x30,local_68);
    (**(code **)(*plVar7 + 0x98))(plVar7,&local_68,4);
    *(undefined4 *)(param_1 + 0x10) = local_68;
    (**(code **)(*plVar7 + 0x98))(plVar7,param_1 + 0x14,4);
    (**(code **)(*plVar7 + 0x98))(plVar7,&local_68,4);
    *(undefined4 *)(param_1 + 0x18) = local_68;
    (**(code **)(*plVar7 + 0x98))(plVar7,&local_68,4);
    *(undefined4 *)(param_1 + 0x1c) = local_68;
    (**(code **)(*plVar7 + 0x98))(plVar7,&local_68,4);
    *(undefined4 *)(param_1 + 0x20) = local_68;
    (**(code **)(*plVar7 + 0x98))(plVar7,&local_68,4);
    *(undefined4 *)(param_1 + 0x24) = local_68;
    (**(code **)(*plVar7 + 0x98))(plVar7,&local_68,4);
    *(undefined4 *)(param_1 + 0x28) = local_68;
    if ((((*(int *)(param_1 + 0x10) != 4) || (param_1[0x14] != (OdDgDimStackedLocation)0x4e)) ||
        (param_1[0x15] != (OdDgDimStackedLocation)0x6f)) ||
       ((param_1[0x16] != (OdDgDimStackedLocation)0x74 ||
        (cVar11 = '\x01', param_1[0x17] != (OdDgDimStackedLocation)0x65)))) {
      cVar11 = '\0';
    }
    (**(code **)(*plVar7 + 0x28))(plVar7);
    if (cVar11 != '\0') {
      return cVar11;
    }
  }
  *(undefined4 *)(param_1 + 0x10) = uVar4;
  param_1[0x14] = OVar1;
  param_1[0x15] = OVar2;
  param_1[0x16] = local_res8[0];
  param_1[0x17] = OVar3;
  *(undefined4 *)(param_1 + 0x18) = local_64;
  *(undefined4 *)(param_1 + 0x1c) = local_60;
  *(undefined4 *)(param_1 + 0x20) = local_5c;
  *(undefined4 *)(param_1 + 0x24) = local_58;
  *(undefined4 *)(param_1 + 0x28) = local_54;
  return '\0';
}



/* ==== 1808acfc0 FUN_1808acfc0 ==== */

void FUN_1808acfc0(longlong param_1,__uint64 param_2,uint param_3)

{
  ulonglong *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  OdRxClass *pOVar7;
  longlong *plVar8;
  OdRxClass *pOVar9;
  uint uVar10;
  ulonglong uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  uint local_58 [2];
  undefined6 local_50;
  byte bStack_4a;
  byte bStack_49;
  longlong *local_48;
  longlong *local_40;
  undefined1 local_38 [32];
  
  plVar6 = (longlong *)OdFlatMemStream::createNew(&local_40,param_2,(ulonglong)param_3);
  local_48 = (longlong *)0x0;
  plVar6 = (longlong *)*plVar6;
  plVar8 = local_48;
  if (plVar6 != (longlong *)0x0) {
    lVar5 = *plVar6;
    pOVar7 = OdStreamBuf::desc();
    plVar8 = (longlong *)(**(code **)(lVar5 + 8))(plVar6,pOVar7);
    if (plVar8 == (longlong *)0x0) {
      pOVar7 = OdStreamBuf::desc();
      pOVar9 = (OdRxClass *)(**(code **)(*plVar6 + 0x18))(plVar6);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res20,pOVar9,pOVar7);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_48 = plVar8;
  plVar6 = local_48;
  if (local_40 != (longlong *)0x0) {
    (**(code **)(*local_40 + 0x28))();
    local_40 = (longlong *)0x0;
  }
  (**(code **)(*plVar6 + 0x98))(plVar6,local_res18,4);
  (**(code **)(*(longlong *)(param_1 + 0x18) + 0x68))((longlong *)(param_1 + 0x18),local_res18[0]);
  (**(code **)(*plVar6 + 0x98))(plVar6,local_res20,4);
  *(undefined4 *)(param_1 + 0x10) = local_res20[0];
  (**(code **)(*plVar6 + 0x98))(plVar6,local_58,4);
  if (local_58[0] != 0) {
    puVar1 = (ulonglong *)(param_1 + 8);
    uVar11 = (ulonglong)local_58[0];
    do {
      (**(code **)(*plVar6 + 0x98))(plVar6,&local_50,8);
      uVar10 = (bStack_49 & 0x7f) << 4 | (uint)(bStack_4a >> 4);
      if ((uVar10 == 0) || (uVar10 == 0x7ff)) {
        uVar12 = 0;
        uVar13 = 0;
      }
      else {
        uVar12 = (undefined4)local_50;
        uVar13 = (undefined4)(CONCAT17(bStack_49,CONCAT16(bStack_4a,local_50)) >> 0x20);
      }
      uVar10 = *(uint *)(*puVar1 - 4);
      LOCK();
      piVar2 = (int *)(*puVar1 - 0x10);
      iVar3 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if ((1 < iVar3) || (uVar10 == *(uint *)(*puVar1 - 8))) {
        if (*(int *)(*puVar1 - 4) == 0) {
LAB_1808ad157:
          if (*(int *)(*puVar1 - 4) != 0) {
            LOCK();
            piVar2 = (int *)(*puVar1 - 0x10);
            iVar4 = *piVar2;
            *piVar2 = *piVar2;
            UNLOCK();
            if (1 < iVar4) {
              FUN_18000cbd0(puVar1,*(undefined4 *)(*puVar1 - 8),0,0,1);
            }
          }
        }
        else {
          LOCK();
          piVar2 = (int *)(*puVar1 - 0x10);
          iVar4 = *piVar2;
          *piVar2 = *piVar2;
          UNLOCK();
          if (1 < iVar4) {
            FUN_18000cbd0(puVar1,*(undefined4 *)(*puVar1 - 8),0,0,1);
          }
          if ((*(int *)((undefined1 *)*puVar1 + -4) == 0) || ((undefined1 *)*puVar1 <= local_38))
          goto LAB_1808ad157;
        }
        FUN_18000cbd0(puVar1,uVar10 + 1,iVar3 < 2,0,1);
      }
      *(ulonglong *)(*puVar1 + (ulonglong)uVar10 * 8) = CONCAT44(uVar13,uVar12);
      *(int *)(*puVar1 - 4) = *(int *)(*puVar1 - 4) + 1;
      uVar11 = uVar11 - 1;
      plVar6 = local_48;
    } while (uVar11 != 0);
  }
  (**(code **)(*plVar6 + 0x28))(plVar6);
  return;
}



/* ==== 1808c3990 FUN_1808c3990 ==== */

void FUN_1808c3990(longlong param_1,__uint64 param_2,uint param_3)

{
  longlong lVar1;
  longlong *plVar2;
  OdRxClass *pOVar3;
  longlong *plVar4;
  OdRxClass *pOVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 local_res18 [2];
  undefined6 local_res20;
  byte bStackX_26;
  byte bStackX_27;
  longlong *local_38;
  longlong *local_30;
  
  plVar2 = (longlong *)OdFlatMemStream::createNew(&local_38,param_2,(ulonglong)param_3);
  local_30 = (longlong *)0x0;
  plVar2 = (longlong *)*plVar2;
  plVar4 = local_30;
  if (plVar2 != (longlong *)0x0) {
    lVar1 = *plVar2;
    pOVar3 = OdStreamBuf::desc();
    plVar4 = (longlong *)(**(code **)(lVar1 + 8))(plVar2,pOVar3);
    if (plVar4 == (longlong *)0x0) {
      pOVar3 = OdStreamBuf::desc();
      pOVar5 = (OdRxClass *)(**(code **)(*plVar2 + 0x18))(plVar2);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_res20,pOVar5,pOVar3);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_30 = plVar4;
  plVar2 = local_30;
  if (local_38 != (longlong *)0x0) {
    (**(code **)(*local_38 + 0x28))();
    local_38 = (longlong *)0x0;
  }
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  (**(code **)(*(longlong *)(param_1 + 0x38) + 0x68))((longlong *)(param_1 + 0x38),local_res18[0]);
  (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
  uVar8 = 0;
  uVar9 = 0;
  uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
  if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
    uVar7 = 0;
  }
  else {
    uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
  }
  *(undefined8 *)(param_1 + 0x10) = uVar7;
  (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
  uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
  if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
    uVar7 = 0;
  }
  else {
    uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
  }
  *(undefined8 *)(param_1 + 0x18) = uVar7;
  (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
  uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
  if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
    uVar7 = 0;
  }
  else {
    uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
  }
  *(undefined8 *)(param_1 + 0x20) = uVar7;
  (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
  uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
  if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
    uVar7 = 0;
  }
  else {
    uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
  }
  *(undefined8 *)(param_1 + 0x28) = uVar7;
  (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
  uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
  if ((uVar6 != 0) && (uVar6 != 0x7ff)) {
    uVar8 = (undefined4)local_res20;
    uVar9 = (undefined4)(CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x30) = CONCAT44(uVar9,uVar8);
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return;
}



/* ==== 1809d8150 FUN_1809d8150 ==== */

void FUN_1809d8150(longlong param_1,__uint64 param_2,uint param_3)

{
  longlong lVar1;
  longlong *plVar2;
  OdRxClass *pOVar3;
  longlong *plVar4;
  OdRxClass *pOVar5;
  undefined4 local_res18 [2];
  longlong *local_res20;
  longlong *local_18 [2];
  
  plVar2 = (longlong *)OdFlatMemStream::createNew(&local_res20,param_2,(ulonglong)param_3);
  local_18[0] = (longlong *)0x0;
  plVar2 = (longlong *)*plVar2;
  plVar4 = local_18[0];
  if (plVar2 != (longlong *)0x0) {
    lVar1 = *plVar2;
    pOVar3 = OdStreamBuf::desc();
    plVar4 = (longlong *)(**(code **)(lVar1 + 8))(plVar2,pOVar3);
    if (plVar4 == (longlong *)0x0) {
      pOVar3 = OdStreamBuf::desc();
      pOVar5 = (OdRxClass *)(**(code **)(*plVar2 + 0x18))(plVar2);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_18,pOVar5,pOVar3);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_18,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_18[0] = plVar4;
  plVar2 = local_18[0];
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))();
    local_res20 = (longlong *)0x0;
  }
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  (**(code **)(*(longlong *)(param_1 + 0x18) + 0x68))((longlong *)(param_1 + 0x18),local_res18[0]);
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  *(undefined4 *)(param_1 + 0x10) = local_res18[0];
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return;
}



