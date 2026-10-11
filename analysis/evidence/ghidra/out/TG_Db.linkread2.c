/* ==== 1801cc0a0 FUN_1801cc0a0 ==== */

undefined2 FUN_1801cc0a0(longlong param_1)

{
  return *(undefined2 *)(param_1 + 0x10);
}



/* ==== 180833880 FUN_180833880 ==== */

undefined8 FUN_180833880(longlong param_1,__uint64 param_2,uint param_3)

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
  (**(code **)(*(longlong *)(param_1 + 8) + 0x68))((longlong *)(param_1 + 8),local_res18[0]);
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  *(undefined4 *)(param_1 + 0xc4) = local_res18[0];
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  if ((*(byte *)(param_1 + 0xc4) & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0x18) = local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 1 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0x1c) = local_res18[0];
  }
  uVar8 = 0;
  uVar9 = 0;
  if ((*(uint *)(param_1 + 0xc4) >> 2 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
    uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
      uVar7 = 0;
    }
    else {
      uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
    }
    *(undefined8 *)(param_1 + 0x20) = uVar7;
  }
  if ((*(uint *)(param_1 + 0xc4) >> 3 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
    uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
      uVar7 = 0;
    }
    else {
      uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
    }
    *(undefined8 *)(param_1 + 0x28) = uVar7;
  }
  if ((*(uint *)(param_1 + 0xc4) >> 4 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
    uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
      uVar7 = 0;
    }
    else {
      uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
    }
    *(undefined8 *)(param_1 + 0x30) = uVar7;
  }
  if ((*(uint *)(param_1 + 0xc4) >> 5 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
    uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
      uVar7 = 0;
    }
    else {
      uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
    }
    *(undefined8 *)(param_1 + 0x38) = uVar7;
  }
  if ((*(uint *)(param_1 + 0xc4) >> 6 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
    uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
      uVar7 = 0;
    }
    else {
      uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
    }
    *(undefined8 *)(param_1 + 0x40) = uVar7;
  }
  if ((*(uint *)(param_1 + 0xc4) >> 7 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
    uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
      uVar7 = 0;
    }
    else {
      uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
    }
    *(undefined8 *)(param_1 + 0x48) = uVar7;
  }
  if ((*(uint *)(param_1 + 0xc4) >> 8 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
    uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
      uVar7 = 0;
    }
    else {
      uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
    }
    *(undefined8 *)(param_1 + 0x50) = uVar7;
  }
  if ((*(uint *)(param_1 + 0xc4) >> 9 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
    uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
      uVar7 = 0;
    }
    else {
      uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
    }
    *(undefined8 *)(param_1 + 0x58) = uVar7;
  }
  if ((*(uint *)(param_1 + 0xc4) >> 10 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
    uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
      uVar7 = 0;
    }
    else {
      uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
    }
    *(undefined8 *)(param_1 + 0x60) = uVar7;
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
    uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
      uVar7 = 0;
    }
    else {
      uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
    }
    *(undefined8 *)(param_1 + 0x68) = uVar7;
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0xb & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,2);
    *(undefined2 *)(param_1 + 0x70) = (undefined2)local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0xc & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,2);
    *(undefined2 *)(param_1 + 0x72) = (undefined2)local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0xd & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,2);
    *(undefined2 *)(param_1 + 0x74) = (undefined2)local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0xe & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,2);
    *(undefined2 *)(param_1 + 0x76) = (undefined2)local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0xf & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0x78) = local_res18[0];
  }
  if ((*(byte *)(param_1 + 0xc6) & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0x7c) = local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0x11 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0x80) = local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0x12 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0x84) = local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0x13 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
    uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar6 == 0) || (uVar6 == 0x7ff)) {
      uVar7 = 0;
    }
    else {
      uVar7 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
    }
    *(undefined8 *)(param_1 + 0x88) = uVar7;
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
    uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar6 != 0) && (uVar6 != 0x7ff)) {
      uVar8 = (undefined4)local_res20;
      uVar9 = (undefined4)(CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20)) >> 0x20);
    }
    *(ulonglong *)(param_1 + 0x90) = CONCAT44(uVar9,uVar8);
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0x14 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0x98) = local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0x15 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0x9c) = local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0x16 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0xa0) = local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0x17 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0xa4) = local_res18[0];
  }
  if ((*(byte *)(param_1 + 199) & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0xa8) = local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0x19 & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0xac) = local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0x1a & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0xb0) = local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0x1b & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0xb4) = local_res18[0];
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0x1c & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
    *(ulonglong *)(param_1 + 0xb8) = CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20));
  }
  if ((*(uint *)(param_1 + 0xc4) >> 0x1d & 1) != 0) {
    (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
    *(undefined4 *)(param_1 + 0xc0) = local_res18[0];
  }
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return 1;
}



/* ==== 1808ab130 FUN_1808ab130 ==== */

void FUN_1808ab130(longlong param_1,__uint64 param_2,uint param_3)

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
  longlong *local_28;
  longlong *local_20;
  
  plVar2 = (longlong *)OdFlatMemStream::createNew(&local_28,param_2,(ulonglong)param_3);
  local_20 = (longlong *)0x0;
  plVar2 = (longlong *)*plVar2;
  plVar4 = local_20;
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
  local_20 = plVar4;
  plVar2 = local_20;
  if (local_28 != (longlong *)0x0) {
    (**(code **)(*local_28 + 0x28))();
    local_28 = (longlong *)0x0;
  }
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  (**(code **)(*(longlong *)(param_1 + 0x28) + 0x68))((longlong *)(param_1 + 0x28),local_res18[0]);
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  *(undefined4 *)(param_1 + 0x10) = local_res18[0];
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
  *(undefined8 *)(param_1 + 0x18) = uVar7;
  (**(code **)(*plVar2 + 0x98))(plVar2,&local_res20,8);
  uVar6 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
  if ((uVar6 != 0) && (uVar6 != 0x7ff)) {
    uVar8 = (undefined4)local_res20;
    uVar9 = (undefined4)(CONCAT17(bStackX_27,CONCAT16(bStackX_26,local_res20)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x20) = CONCAT44(uVar9,uVar8);
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return;
}



/* ==== 1808ad230 FUN_1808ad230 ==== */

void FUN_1808ad230(longlong param_1,__uint64 param_2,uint param_3)

{
  ulonglong *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  longlong *plVar6;
  OdRxClass *pOVar7;
  longlong *plVar8;
  ulonglong uVar9;
  OdRxClass *pOVar10;
  uint uVar11;
  ulonglong uVar12;
  undefined8 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 local_res18 [2];
  undefined4 local_res20;
  undefined2 uStackX_24;
  byte bStackX_26;
  byte bStackX_27;
  undefined4 local_78;
  uint local_74;
  undefined6 local_70;
  byte bStack_6a;
  byte bStack_69;
  undefined6 local_68;
  byte bStack_62;
  byte bStack_61;
  undefined6 local_60;
  byte bStack_5a;
  byte bStack_59;
  longlong *local_58;
  longlong *local_50;
  undefined1 local_48 [48];
  
  plVar6 = (longlong *)OdFlatMemStream::createNew(&local_50,param_2,(ulonglong)param_3);
  local_58 = (longlong *)0x0;
  plVar6 = (longlong *)*plVar6;
  plVar8 = local_58;
  if (plVar6 != (longlong *)0x0) {
    lVar5 = *plVar6;
    pOVar7 = OdStreamBuf::desc();
    plVar8 = (longlong *)(**(code **)(lVar5 + 8))(plVar6,pOVar7);
    if (plVar8 == (longlong *)0x0) {
      pOVar7 = OdStreamBuf::desc();
      pOVar10 = (OdRxClass *)(**(code **)(*plVar6 + 0x18))(plVar6);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_res20,pOVar10,pOVar7);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_58 = plVar8;
  plVar6 = local_58;
  if (local_50 != (longlong *)0x0) {
    (**(code **)(*local_50 + 0x28))();
    local_50 = (longlong *)0x0;
  }
  (**(code **)(*plVar6 + 0x98))(plVar6,local_res18,4);
  (**(code **)(*(longlong *)(param_1 + 0x38) + 0x68))((longlong *)(param_1 + 0x38),local_res18[0]);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_res20,4);
  *(undefined4 *)(param_1 + 8) = local_res20;
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_70,8);
  uVar15 = 0;
  uVar11 = (bStack_69 & 0x7f) << 4 | (uint)(bStack_6a >> 4);
  if ((uVar11 == 0) || (uVar11 == 0x7ff)) {
    uVar13 = 0;
  }
  else {
    uVar13 = CONCAT17(bStack_69,CONCAT16(bStack_6a,local_70));
  }
  *(undefined8 *)(param_1 + 0x10) = uVar13;
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_68,8);
  uVar11 = (bStack_61 & 0x7f) << 4 | (uint)(bStack_62 >> 4);
  if ((uVar11 == 0) || (uVar11 == 0x7ff)) {
    uVar13 = 0;
  }
  else {
    uVar13 = CONCAT17(bStack_61,CONCAT16(bStack_62,local_68));
  }
  *(undefined8 *)(param_1 + 0x18) = uVar13;
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_74,4);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_78,4);
  *(undefined4 *)(param_1 + 0x28) = local_78;
  if (local_74 == 0) {
    uVar12 = (**(code **)(*plVar6 + 0x68))(plVar6);
    uVar9 = (**(code **)(*plVar6 + 0x70))(plVar6);
    if (uVar12 < uVar9) {
      (**(code **)(*plVar6 + 0x98))(plVar6,&local_res20,8);
      uVar11 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
      uVar14 = 0;
      if ((uVar11 != 0) && (uVar11 != 0x7ff)) {
        uVar15 = (undefined4)
                 (CONCAT17(bStackX_27,CONCAT16(bStackX_26,CONCAT24(uStackX_24,local_res20))) >> 0x20
                 );
        uVar14 = local_res20;
      }
      *(ulonglong *)(param_1 + 0x20) = CONCAT44(uVar15,uVar14);
    }
  }
  else {
    puVar1 = (ulonglong *)(param_1 + 0x30);
    uVar12 = (ulonglong)local_74;
    do {
      (**(code **)(*plVar6 + 0x98))(plVar6,&local_60,8);
      uVar11 = (bStack_59 & 0x7f) << 4 | (uint)(bStack_5a >> 4);
      if ((uVar11 == 0) || (uVar11 == 0x7ff)) {
        uVar15 = 0;
        uVar14 = 0;
      }
      else {
        uVar15 = (undefined4)local_60;
        uVar14 = (undefined4)(CONCAT17(bStack_59,CONCAT16(bStack_5a,local_60)) >> 0x20);
      }
      uVar11 = *(uint *)(*puVar1 - 4);
      LOCK();
      piVar2 = (int *)(*puVar1 - 0x10);
      iVar3 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if ((1 < iVar3) || (uVar11 == *(uint *)(*puVar1 - 8))) {
        if (*(int *)(*puVar1 - 4) == 0) {
LAB_1808ad462:
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
          if ((*(int *)((undefined1 *)*puVar1 + -4) == 0) || ((undefined1 *)*puVar1 <= local_48))
          goto LAB_1808ad462;
        }
        FUN_18000cbd0(puVar1,uVar11 + 1,iVar3 < 2,0,1);
      }
      *(ulonglong *)(*puVar1 + (ulonglong)uVar11 * 8) = CONCAT44(uVar14,uVar15);
      *(int *)(*puVar1 - 4) = *(int *)(*puVar1 - 4) + 1;
      uVar12 = uVar12 - 1;
      plVar6 = local_58;
    } while (uVar12 != 0);
  }
  (**(code **)(*plVar6 + 0x28))(plVar6);
  return;
}



/* ==== 1808ae0b0 FUN_1808ae0b0 ==== */

undefined8 FUN_1808ae0b0(longlong param_1,__uint64 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  longlong *plVar4;
  OdRxClass *pOVar5;
  longlong *plVar6;
  OdString *pOVar7;
  OdRxClass *pOVar8;
  code *pcVar9;
  code *pcVar10;
  undefined1 *puVar11;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  code *local_78;
  code *local_70;
  undefined1 local_68;
  undefined1 local_67 [7];
  longlong *local_60;
  short local_58 [2];
  uint local_54;
  uint local_50 [2];
  longlong *local_48;
  undefined1 local_40 [4];
  undefined4 local_3c;
  int local_38 [2];
  OdString local_30 [8];
  
  plVar4 = (longlong *)OdFlatMemStream::createNew(&local_48,param_2,(ulonglong)param_3);
  pcVar10 = (code *)0x0;
  local_60 = (longlong *)0x0;
  plVar4 = (longlong *)*plVar4;
  plVar6 = local_60;
  if (plVar4 != (longlong *)0x0) {
    lVar3 = *plVar4;
    pOVar5 = OdStreamBuf::desc();
    plVar6 = (longlong *)(**(code **)(lVar3 + 8))(plVar4,pOVar5);
    if (plVar6 == (longlong *)0x0) {
      pOVar5 = OdStreamBuf::desc();
      pOVar8 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_60,pOVar8,pOVar5);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_60,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_60 = plVar6;
  plVar4 = local_60;
  if (local_48 != (longlong *)0x0) {
    (**(code **)(*local_48 + 0x28))();
    local_48 = (longlong *)0x0;
  }
  (**(code **)(*plVar4 + 0x98))(plVar4,&local_3c,4);
  *(undefined4 *)(param_1 + 8) = local_3c;
  (**(code **)(*plVar4 + 0x98))(plVar4,local_58,2);
  *(int *)(param_1 + 0xc) = (int)local_58[0];
  (**(code **)(*plVar4 + 0x98))(plVar4,local_40,2);
  (**(code **)(*plVar4 + 0x98))(plVar4,&local_54,4);
  (**(code **)(*plVar4 + 0x98))(plVar4,local_50,4);
  (**(code **)(*plVar4 + 0x98))(plVar4,local_38,4);
  if (local_54 != 0) {
    local_78 = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
    UNLOCK();
    FUN_1800150c0(&local_78,local_54);
    FUN_18000d0b0(&local_78);
    pcVar9 = pcVar10;
    if (*(int *)(local_78 + -4) != 0) {
      pcVar9 = local_78;
    }
    (**(code **)(*local_60 + 0x98))(local_60,pcVar9,local_54);
    local_res18[0] = (code)0x0;
    uVar2 = *(uint *)(local_78 + -4);
    LOCK();
    pcVar9 = local_78 + -0x10;
    iVar1 = *(int *)pcVar9;
    *(int *)pcVar9 = *(int *)pcVar9;
    UNLOCK();
    if ((iVar1 < 2) && (uVar2 != *(uint *)(local_78 + -8))) {
LAB_1808ae2d2:
      puVar11 = local_res18;
    }
    else {
      if (*(int *)(local_78 + -4) == 0) {
LAB_1808ae2b3:
        FUN_18000ca40(&local_78,uVar2 + 1,iVar1 < 2,0,1);
        goto LAB_1808ae2d2;
      }
      FUN_18000d0b0(&local_78);
      if (((*(int *)(local_78 + -4) == 0) || (local_res18 < local_78)) ||
         (*(int *)(local_78 + -4) == 0)) goto LAB_1808ae2b3;
      FUN_18000d0b0(&local_78);
      pcVar9 = pcVar10;
      if (*(uint *)(local_78 + -4) != 0) {
        pcVar9 = local_78;
      }
      if (pcVar9 + *(uint *)(local_78 + -4) <= local_res18) goto LAB_1808ae2b3;
      local_68 = 0;
      FUN_18000ca40(&local_78,uVar2 + 1,iVar1 < 2,0,1);
      puVar11 = &local_68;
    }
    memmove(local_78 + uVar2,puVar11,1);
    *(int *)(local_78 + -4) = *(int *)(local_78 + -4) + 1;
    pOVar7 = (OdString *)FUN_1808b7790(local_30,&local_78);
    OdString::operator=((OdString *)(param_1 + 0x10),pOVar7);
    OdString::~OdString(local_30);
    pcVar9 = local_78 + -0x10;
    LOCK();
    iVar1 = *(int *)pcVar9;
    *(int *)pcVar9 = *(int *)pcVar9 + -1;
    UNLOCK();
    plVar4 = local_60;
    if ((iVar1 == 1) && (pcVar9 != g_empty_array_buffer_exref)) {
      odrxFree();
      plVar4 = local_60;
    }
  }
  if ((local_50[0] == 0) || (param_3 < local_38[0] + 0x14U)) goto LAB_1808ae4b8;
  local_70 = g_empty_array_buffer_exref + 0x10;
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  FUN_1800150c0(&local_70,local_50[0]);
  FUN_18000d0b0(&local_70);
  pcVar9 = pcVar10;
  if (*(int *)(local_70 + -4) != 0) {
    pcVar9 = local_70;
  }
  (**(code **)(*local_60 + 0x98))(local_60,pcVar9,local_50[0]);
  local_res20[0] = (code)0x0;
  uVar2 = *(uint *)(local_70 + -4);
  LOCK();
  pcVar9 = local_70 + -0x10;
  iVar1 = *(int *)pcVar9;
  *(int *)pcVar9 = *(int *)pcVar9;
  UNLOCK();
  if ((iVar1 < 2) && (uVar2 != *(uint *)(local_70 + -8))) {
LAB_1808ae456:
    puVar11 = local_res20;
  }
  else {
    if (*(int *)(local_70 + -4) == 0) {
LAB_1808ae437:
      FUN_18000ca40(&local_70,uVar2 + 1,iVar1 < 2,0,1);
      goto LAB_1808ae456;
    }
    FUN_18000d0b0(&local_70);
    if (((*(int *)(local_70 + -4) == 0) || (local_res20 < local_70)) ||
       (*(int *)(local_70 + -4) == 0)) goto LAB_1808ae437;
    FUN_18000d0b0(&local_70);
    if (*(uint *)(local_70 + -4) != 0) {
      pcVar10 = local_70;
    }
    if (pcVar10 + *(uint *)(local_70 + -4) <= local_res20) goto LAB_1808ae437;
    local_67[0] = 0;
    FUN_18000ca40(&local_70,uVar2 + 1,iVar1 < 2,0,1);
    puVar11 = local_67;
  }
  memmove(local_70 + uVar2,puVar11,1);
  *(int *)(local_70 + -4) = *(int *)(local_70 + -4) + 1;
  pOVar7 = (OdString *)FUN_1808b7790(&local_48,&local_70);
  OdString::operator=((OdString *)(param_1 + 0x18),pOVar7);
  OdString::~OdString((OdString *)&local_48);
  pcVar10 = local_70 + -0x10;
  LOCK();
  iVar1 = *(int *)pcVar10;
  *(int *)pcVar10 = *(int *)pcVar10 + -1;
  UNLOCK();
  plVar4 = local_60;
  if ((iVar1 == 1) && (pcVar10 != g_empty_array_buffer_exref)) {
    odrxFree();
    plVar4 = local_60;
  }
LAB_1808ae4b8:
  (**(code **)(*plVar4 + 0x28))(plVar4);
  return 1;
}



/* ==== 1808af600 FUN_1808af600 ==== */

void FUN_1808af600(longlong param_1,__uint64 param_2,uint param_3)

{
  ulonglong *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  longlong lVar6;
  longlong *plVar7;
  OdRxClass *pOVar8;
  longlong *plVar9;
  OdRxClass *pOVar10;
  ulonglong uVar11;
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  undefined4 local_48;
  uint local_44;
  longlong *local_40;
  longlong *local_38;
  undefined8 local_30;
  undefined1 local_28 [16];
  
  plVar7 = (longlong *)OdFlatMemStream::createNew(&local_38,param_2,(ulonglong)param_3);
  local_40 = (longlong *)0x0;
  plVar7 = (longlong *)*plVar7;
  plVar9 = local_40;
  if (plVar7 != (longlong *)0x0) {
    lVar6 = *plVar7;
    pOVar8 = OdStreamBuf::desc();
    plVar9 = (longlong *)(**(code **)(lVar6 + 8))(plVar7,pOVar8);
    if (plVar9 == (longlong *)0x0) {
      pOVar8 = OdStreamBuf::desc();
      pOVar10 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res20,pOVar10,pOVar8);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_40 = plVar9;
  plVar7 = local_40;
  if (local_38 != (longlong *)0x0) {
    (**(code **)(*local_38 + 0x28))();
    local_38 = (longlong *)0x0;
  }
  (**(code **)(*plVar7 + 0x98))(plVar7,local_res18,4);
  (**(code **)(*(longlong *)(param_1 + 0x20) + 0x68))((longlong *)(param_1 + 0x20),local_res18[0]);
  (**(code **)(*plVar7 + 0x98))(plVar7,local_res20,4);
  *(undefined4 *)(param_1 + 0x10) = local_res20[0];
  (**(code **)(*plVar7 + 0x98))(plVar7,&local_48,4);
  *(undefined4 *)(param_1 + 0x14) = local_48;
  (**(code **)(*plVar7 + 0x98))(plVar7,&local_44,4);
  if (local_44 != 0) {
    puVar1 = (ulonglong *)(param_1 + 0x18);
    uVar11 = (ulonglong)local_44;
    do {
      (**(code **)(*plVar7 + 0x98))(plVar7,&local_30,8);
      uVar5 = *(uint *)(*puVar1 - 4);
      LOCK();
      piVar2 = (int *)(*puVar1 - 0x10);
      iVar3 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if ((1 < iVar3) || (uVar5 == *(uint *)(*puVar1 - 8))) {
        if (*(int *)(*puVar1 - 4) == 0) {
LAB_1808af77d:
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
          if ((*(int *)((undefined1 *)*puVar1 + -4) == 0) || ((undefined1 *)*puVar1 <= local_28))
          goto LAB_1808af77d;
        }
        FUN_18000cbd0(puVar1,uVar5 + 1,iVar3 < 2,0,1);
      }
      *(undefined8 *)(*puVar1 + (ulonglong)uVar5 * 8) = local_30;
      *(int *)(*puVar1 - 4) = *(int *)(*puVar1 - 4) + 1;
      uVar11 = uVar11 - 1;
      plVar7 = local_40;
    } while (uVar11 != 0);
  }
  (**(code **)(*plVar7 + 0x28))(plVar7);
  return;
}



/* ==== 1808c12d0 FUN_1808c12d0 ==== */

void FUN_1808c12d0(longlong *param_1,__uint64 param_2,uint param_3)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong *plVar3;
  OdRxClass *pOVar4;
  longlong *plVar5;
  undefined8 uVar6;
  OdRxClass *pOVar7;
  uint uVar8;
  ushort uVar9;
  uint uVar10;
  undefined4 local_res18 [2];
  OdString local_res20 [8];
  longlong *local_38;
  longlong *local_30;
  
  plVar3 = (longlong *)OdFlatMemStream::createNew(&local_38,param_2,(ulonglong)param_3);
  uVar8 = 0;
  local_30 = (longlong *)0x0;
  plVar3 = (longlong *)*plVar3;
  plVar5 = local_30;
  if (plVar3 != (longlong *)0x0) {
    lVar1 = *plVar3;
    pOVar4 = OdStreamBuf::desc();
    plVar5 = (longlong *)(**(code **)(lVar1 + 8))(plVar3,pOVar4);
    if (plVar5 == (longlong *)0x0) {
      pOVar4 = OdStreamBuf::desc();
      pOVar7 = (OdRxClass *)(**(code **)(*plVar3 + 0x18))(plVar3);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_30,pOVar7,pOVar4);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_30,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_30 = plVar5;
  plVar3 = local_30;
  if (local_38 != (longlong *)0x0) {
    (**(code **)(*local_38 + 0x28))();
    local_38 = (longlong *)0x0;
  }
  (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,4);
  (**(code **)(param_1[5] + 0x68))(param_1 + 5,local_res18[0]);
  (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,2);
  uVar10 = (uint)(short)(ushort)local_res18[0];
  OdString::init(local_res20);
  do {
    (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,2);
    uVar2 = local_res18[0];
    if (uVar8 <= uVar10) {
      uVar9 = (ushort)local_res18[0] >> 8;
      if ((char)local_res18[0] != '\0') {
        OdString::operator+=(local_res20,(ushort)local_res18[0] & 0xff);
      }
      if ((char)((uint)uVar2 >> 8) != '\0') {
        OdString::operator+=(local_res20,uVar9);
      }
    }
    uVar8 = uVar8 + 2;
  } while (uVar8 < 0x1e);
  if (0x28 < param_3) {
    (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,2);
    *(ushort *)((longlong)param_1 + 0x1a) = (ushort)local_res18[0];
    (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,2);
    *(ushort *)(param_1 + 3) = (ushort)local_res18[0];
  }
  if (0x30 < param_3) {
    (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,4);
    *(undefined4 *)((longlong)param_1 + 0x1c) = local_res18[0];
    (**(code **)(*plVar3 + 0x98))(plVar3,local_res18,4);
    *(undefined4 *)(param_1 + 4) = local_res18[0];
  }
  uVar6 = OdString::OdString((OdString *)&local_38,local_res20);
  (**(code **)(*param_1 + 0x88))(param_1,uVar6);
  OdString::~OdString(local_res20);
  (**(code **)(*plVar3 + 0x28))(plVar3);
  return;
}



/* ==== 1808c1fb0 FUN_1808c1fb0 ==== */

void FUN_1808c1fb0(longlong param_1,__uint64 param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  longlong *plVar5;
  OdRxClass *pOVar6;
  longlong *plVar7;
  OdRxClass *pOVar8;
  uint uVar9;
  longlong lVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint local_res18 [2];
  undefined4 local_res20 [2];
  uint local_98;
  int local_94;
  undefined1 local_90 [4];
  uint local_8c;
  undefined6 local_88;
  byte bStack_82;
  byte bStack_81;
  undefined6 local_80;
  byte bStack_7a;
  byte bStack_79;
  undefined6 local_78;
  byte bStack_72;
  byte bStack_71;
  undefined6 local_70;
  byte bStack_6a;
  byte bStack_69;
  undefined6 local_68;
  byte bStack_62;
  byte bStack_61;
  undefined6 local_60;
  byte bStack_5a;
  byte bStack_59;
  undefined6 local_58;
  byte bStack_52;
  byte bStack_51;
  longlong *local_50;
  longlong *local_48;
  
  plVar5 = (longlong *)OdFlatMemStream::createNew(&local_50,param_2,(ulonglong)param_3);
  local_48 = (longlong *)0x0;
  plVar5 = (longlong *)*plVar5;
  plVar7 = local_48;
  if (plVar5 != (longlong *)0x0) {
    lVar10 = *plVar5;
    pOVar6 = OdStreamBuf::desc();
    plVar7 = (longlong *)(**(code **)(lVar10 + 8))(plVar5,pOVar6);
    if (plVar7 == (longlong *)0x0) {
      pOVar6 = OdStreamBuf::desc();
      pOVar8 = (OdRxClass *)(**(code **)(*plVar5 + 0x18))(plVar5);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res20,pOVar8,pOVar6);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_48 = plVar7;
  plVar5 = local_48;
  if (local_50 != (longlong *)0x0) {
    (**(code **)(*local_50 + 0x28))();
    local_50 = (longlong *)0x0;
  }
  (**(code **)(*plVar5 + 0x98))(plVar5,local_res20,4);
  (**(code **)(*(longlong *)(param_1 + 0x60) + 0x68))((longlong *)(param_1 + 0x60),local_res20[0]);
  (**(code **)(*plVar5 + 0x98))(plVar5,&local_98,4);
  *(uint *)(param_1 + 0x10) = local_98;
  uVar12 = 0;
  uVar13 = 0;
  if ((local_98 & 1) != 0) {
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_88,8);
    uVar9 = (bStack_81 & 0x7f) << 4 | (uint)(bStack_82 >> 4);
    if ((uVar9 == 0) || (uVar9 == 0x7ff)) {
      uVar11 = 0;
    }
    else {
      uVar11 = CONCAT17(bStack_81,CONCAT16(bStack_82,local_88));
    }
    *(undefined8 *)(param_1 + 0x18) = uVar11;
  }
  if ((*(uint *)(param_1 + 0x10) >> 1 & 1) != 0) {
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_80,8);
    uVar9 = (bStack_79 & 0x7f) << 4 | (uint)(bStack_7a >> 4);
    if ((uVar9 == 0) || (uVar9 == 0x7ff)) {
      uVar11 = 0;
    }
    else {
      uVar11 = CONCAT17(bStack_79,CONCAT16(bStack_7a,local_80));
    }
    *(undefined8 *)(param_1 + 0x20) = uVar11;
  }
  if ((*(uint *)(param_1 + 0x10) >> 2 & 1) != 0) {
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_78,8);
    uVar9 = (bStack_71 & 0x7f) << 4 | (uint)(bStack_72 >> 4);
    if ((uVar9 == 0) || (uVar9 == 0x7ff)) {
      uVar11 = 0;
    }
    else {
      uVar11 = CONCAT17(bStack_71,CONCAT16(bStack_72,local_78));
    }
    *(undefined8 *)(param_1 + 0x28) = uVar11;
  }
  if ((*(uint *)(param_1 + 0x10) >> 3 & 1) != 0) {
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_70,8);
    uVar9 = (bStack_69 & 0x7f) << 4 | (uint)(bStack_6a >> 4);
    if ((uVar9 == 0) || (uVar9 == 0x7ff)) {
      uVar11 = 0;
    }
    else {
      uVar11 = CONCAT17(bStack_69,CONCAT16(bStack_6a,local_70));
    }
    *(undefined8 *)(param_1 + 0x30) = uVar11;
  }
  if ((*(uint *)(param_1 + 0x10) >> 4 & 1) != 0) {
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_68,8);
    uVar9 = (bStack_61 & 0x7f) << 4 | (uint)(bStack_62 >> 4);
    if ((uVar9 == 0) || (uVar9 == 0x7ff)) {
      uVar11 = 0;
    }
    else {
      uVar11 = CONCAT17(bStack_61,CONCAT16(bStack_62,local_68));
    }
    *(undefined8 *)(param_1 + 0x38) = uVar11;
  }
  if ((*(uint *)(param_1 + 0x10) >> 5 & 1) != 0) {
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_60,8);
    uVar9 = (bStack_59 & 0x7f) << 4 | (uint)(bStack_5a >> 4);
    if ((uVar9 == 0) || (uVar9 == 0x7ff)) {
      uVar11 = 0;
    }
    else {
      uVar11 = CONCAT17(bStack_59,CONCAT16(bStack_5a,local_60));
    }
    *(undefined8 *)(param_1 + 0x40) = uVar11;
  }
  if ((*(uint *)(param_1 + 0x10) >> 6 & 1) != 0) {
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_58,8);
    uVar9 = (bStack_51 & 0x7f) << 4 | (uint)(bStack_52 >> 4);
    if ((uVar9 != 0) && (uVar9 != 0x7ff)) {
      uVar12 = (undefined4)local_58;
      uVar13 = (undefined4)(CONCAT17(bStack_51,CONCAT16(bStack_52,local_58)) >> 0x20);
    }
    *(ulonglong *)(param_1 + 0x48) = CONCAT44(uVar13,uVar12);
  }
  if ((*(uint *)(param_1 + 0x10) & 0x1800) == 0x1800) {
    (**(code **)(*plVar5 + 0x98))(plVar5,local_res18,4);
    (**(code **)(*plVar5 + 0x98))(plVar5,&local_94,4);
    if (local_94 == 1) {
      *(undefined4 *)(param_1 + 0x50) = 0;
      uVar9 = 0;
      do {
        if ((local_res18[0] & 1 << ((byte)uVar9 & 0x1f)) != 0) {
          uVar3 = *(uint *)(*(longlong *)(param_1 + 0x58) + -4);
          LOCK();
          piVar1 = (int *)(*(longlong *)(param_1 + 0x58) + -0x10);
          iVar2 = *piVar1;
          *piVar1 = *piVar1;
          UNLOCK();
          if ((iVar2 < 2) && (uVar3 != *(uint *)(*(longlong *)(param_1 + 0x58) + -8))) {
LAB_1808c23b4:
            *(uint *)(*(longlong *)(param_1 + 0x58) + (ulonglong)uVar3 * 4) = uVar9;
          }
          else {
            if (*(int *)(*(longlong *)(param_1 + 0x58) + -4) != 0) {
              FUN_18016f6d0(param_1 + 0x58);
              if ((*(int *)(*(undefined1 **)(param_1 + 0x58) + -4) == 0) ||
                 (*(undefined1 **)(param_1 + 0x58) <= local_90)) goto LAB_1808c2331;
LAB_1808c2398:
              FUN_18016ee30(param_1 + 0x58,uVar3 + 1,iVar2 < 2,0,1);
              goto LAB_1808c23b4;
            }
LAB_1808c2331:
            if (*(int *)(*(longlong *)(param_1 + 0x58) + -4) == 0) goto LAB_1808c2398;
            FUN_18016f6d0();
            uVar4 = *(uint *)(*(longlong *)(param_1 + 0x58) + -4);
            lVar10 = 0;
            if (uVar4 != 0) {
              lVar10 = *(longlong *)(param_1 + 0x58);
            }
            if ((undefined1 *)(lVar10 + (ulonglong)uVar4 * 4) <= local_90) goto LAB_1808c2398;
            local_8c = uVar9;
            FUN_18016ee30(param_1 + 0x58,uVar3 + 1,iVar2 < 2,0,1);
            memmove((void *)(*(longlong *)(param_1 + 0x58) + (ulonglong)uVar3 * 4),&local_8c,4);
          }
          piVar1 = (int *)(*(longlong *)(param_1 + 0x58) + -4);
          *piVar1 = *piVar1 + 1;
        }
        uVar9 = uVar9 + 1;
        plVar5 = local_48;
      } while (uVar9 < 0x20);
      goto LAB_1808c2426;
    }
    if ((local_res18[0] & 1) == 0) {
      *(uint *)(param_1 + 0x50) = ((byte)~(byte)local_res18[0] & 2 | 4) >> 1;
      goto LAB_1808c2426;
    }
  }
  else {
    if ((*(uint *)(param_1 + 0x10) >> 0xb & 1) == 0) goto LAB_1808c2426;
    (**(code **)(*plVar5 + 0x98))(plVar5,local_res18,4);
    if ((local_res18[0] & 1) == 0) {
      if (local_res18[0] != 0) {
        *(undefined4 *)(param_1 + 0x50) = 2;
      }
      goto LAB_1808c2426;
    }
  }
  *(undefined4 *)(param_1 + 0x50) = 1;
LAB_1808c2426:
  (**(code **)(*plVar5 + 0x28))(plVar5);
  return;
}



/* ==== 1808c3bc0 FUN_1808c3bc0 ==== */

void FUN_1808c3bc0(longlong param_1,__uint64 param_2,uint param_3)

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
  (**(code **)(*(longlong *)(param_1 + 0x28) + 0x68))((longlong *)(param_1 + 0x28),local_res18[0]);
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  *(undefined4 *)(param_1 + 0x10) = local_res18[0];
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  *(undefined4 *)(param_1 + 0x14) = local_res18[0];
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  *(undefined4 *)(param_1 + 0x18) = local_res18[0];
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  *(undefined4 *)(param_1 + 0x1c) = local_res18[0];
  (**(code **)(*plVar2 + 0x98))(plVar2,local_res18,4);
  *(undefined4 *)(param_1 + 0x20) = local_res18[0];
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return;
}



/* ==== 1808c3d40 FUN_1808c3d40 ==== */

void FUN_1808c3d40(longlong param_1,__uint64 param_2,uint param_3)

{
  OdString *this;
  longlong lVar1;
  bool bVar2;
  bool bVar3;
  longlong *plVar4;
  OdRxClass *pOVar5;
  longlong *plVar6;
  OdRxClass *pOVar7;
  uint uVar8;
  undefined8 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 local_res18 [2];
  ushort local_res20;
  undefined4 uStackX_22;
  byte bStackX_26;
  byte bStackX_27;
  ushort local_58 [2];
  ushort local_54 [2];
  longlong *local_50;
  longlong *local_48;
  
  plVar4 = (longlong *)OdFlatMemStream::createNew(&local_50,param_2,(ulonglong)param_3);
  local_48 = (longlong *)0x0;
  plVar4 = (longlong *)*plVar4;
  plVar6 = local_48;
  if (plVar4 != (longlong *)0x0) {
    lVar1 = *plVar4;
    pOVar5 = OdStreamBuf::desc();
    plVar6 = (longlong *)(**(code **)(lVar1 + 8))(plVar4,pOVar5);
    if (plVar6 == (longlong *)0x0) {
      pOVar5 = OdStreamBuf::desc();
      pOVar7 = (OdRxClass *)(**(code **)(*plVar4 + 0x18))(plVar4);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_res20,pOVar7,pOVar5);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_res20,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_48 = plVar6;
  plVar4 = local_48;
  if (local_50 != (longlong *)0x0) {
    (**(code **)(*local_50 + 0x28))();
    local_50 = (longlong *)0x0;
  }
  (**(code **)(*plVar4 + 0x98))(plVar4,local_res18,4);
  (**(code **)(*(longlong *)(param_1 + 0x150) + 0x68))((longlong *)(param_1 + 0x150),local_res18[0])
  ;
  if (0x3b < param_3) {
    (**(code **)(*plVar4 + 0x98))(plVar4,local_res18,4);
    *(undefined4 *)(param_1 + 0xd8) = local_res18[0];
    (**(code **)(*plVar4 + 0x98))(plVar4,local_res18,4);
    *(undefined4 *)(param_1 + 0x10) = local_res18[0];
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_res20,8);
    uVar10 = 0;
    uVar11 = 0;
    uVar8 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar8 == 0) || (uVar8 == 0x7ff)) {
      uVar9 = 0;
    }
    else {
      uVar9 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,CONCAT42(uStackX_22,local_res20)));
    }
    *(undefined8 *)(param_1 + 0xe0) = uVar9;
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_res20,8);
    uVar8 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar8 == 0) || (uVar8 == 0x7ff)) {
      uVar9 = 0;
    }
    else {
      uVar9 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,CONCAT42(uStackX_22,local_res20)));
    }
    *(undefined8 *)(param_1 + 0xe8) = uVar9;
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_res20,8);
    uVar8 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar8 == 0) || (uVar8 == 0x7ff)) {
      uVar9 = 0;
    }
    else {
      uVar9 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,CONCAT42(uStackX_22,local_res20)));
    }
    *(undefined8 *)(param_1 + 0xf0) = uVar9;
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_res20,8);
    uVar8 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar8 == 0) || (uVar8 == 0x7ff)) {
      uVar9 = 0;
    }
    else {
      uVar9 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,CONCAT42(uStackX_22,local_res20)));
    }
    *(undefined8 *)(param_1 + 0xf8) = uVar9;
    (**(code **)(*plVar4 + 0x98))(plVar4,&local_res20,8);
    uVar8 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
    if ((uVar8 == 0) || (uVar8 == 0x7ff)) {
      uVar9 = 0;
    }
    else {
      uVar9 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,CONCAT42(uStackX_22,local_res20)));
    }
    *(undefined8 *)(param_1 + 0x100) = uVar9;
    (**(code **)(*plVar4 + 0x98))(plVar4,local_res18,4);
    *(undefined4 *)(param_1 + 0x108) = local_res18[0];
    (**(code **)(*plVar4 + 0x98))(plVar4,local_res18,4);
    *(undefined4 *)(param_1 + 0x14) = local_res18[0];
    if (0x5b < param_3) {
      (**(code **)(*plVar4 + 0x98))(plVar4,local_res18,4);
      *(undefined4 *)(param_1 + 0x10c) = local_res18[0];
      (**(code **)(*plVar4 + 0x98))(plVar4,local_res18,4);
      *(undefined4 *)(param_1 + 0x18) = local_res18[0];
      (**(code **)(*plVar4 + 0x98))(plVar4,&local_res20,8);
      uVar8 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
      if ((uVar8 == 0) || (uVar8 == 0x7ff)) {
        uVar9 = 0;
      }
      else {
        uVar9 = CONCAT17(bStackX_27,CONCAT16(bStackX_26,CONCAT42(uStackX_22,local_res20)));
      }
      *(undefined8 *)(param_1 + 0x110) = uVar9;
      (**(code **)(*plVar4 + 0x98))(plVar4,&local_res20,8);
      uVar8 = (bStackX_27 & 0x7f) << 4 | (uint)(bStackX_26 >> 4);
      if ((uVar8 != 0) && (uVar8 != 0x7ff)) {
        uVar10 = (undefined4)CONCAT42(uStackX_22,local_res20);
        uVar11 = (undefined4)
                 (CONCAT17(bStackX_27,CONCAT16(bStackX_26,CONCAT42(uStackX_22,local_res20))) >> 0x20
                 );
      }
      *(ulonglong *)(param_1 + 0x118) = CONCAT44(uVar11,uVar10);
      (**(code **)(*plVar4 + 0x98))(plVar4,local_res18,2);
      (**(code **)(*plVar4 + 0x98))(plVar4,&local_res20,2);
      (**(code **)(*plVar4 + 0x98))(plVar4,local_58,2);
      (**(code **)(*plVar4 + 0x98))(plVar4,local_54,2);
      this = (OdString *)(param_1 + 0x120);
      OdString::empty(this);
      if ((ushort)local_res18[0] != 0) {
        OdString::operator+=(this,(ushort)local_res18[0]);
      }
      lVar1 = *(longlong *)this;
      bVar2 = true;
      if ((*(int *)(lVar1 + 4) == 0) &&
         ((*(longlong *)(lVar1 + 0x18) == 0 || (*(int *)(*(longlong *)(lVar1 + 0x18) + -0xc) == 0)))
         ) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      if ((!bVar3) && (local_res20 != 0)) {
        OdString::operator+=(this,local_res20);
      }
      lVar1 = *(longlong *)this;
      if ((*(int *)(lVar1 + 4) == 0) &&
         ((*(longlong *)(lVar1 + 0x18) == 0 || (*(int *)(*(longlong *)(lVar1 + 0x18) + -0xc) == 0)))
         ) {
        bVar3 = true;
      }
      else {
        bVar3 = false;
      }
      if ((!bVar3) && (local_58[0] != 0)) {
        OdString::operator+=(this,local_58[0]);
      }
      lVar1 = *(longlong *)this;
      if ((*(int *)(lVar1 + 4) != 0) ||
         ((*(longlong *)(lVar1 + 0x18) != 0 && (*(int *)(*(longlong *)(lVar1 + 0x18) + -0xc) != 0)))
         ) {
        bVar2 = false;
      }
      if ((!bVar2) && (local_54[0] != 0)) {
        OdString::operator+=(this,local_54[0]);
      }
      if (0x13b < param_3) {
        (**(code **)(*plVar4 + 0xa8))(plVar4,param_1 + 0x20,0xb8);
        uVar9 = FUN_180833830(plVar4);
        *(undefined8 *)(param_1 + 0x128) = uVar9;
        uVar9 = FUN_180833830(plVar4);
        *(undefined8 *)(param_1 + 0x130) = uVar9;
        uVar9 = FUN_180833830(plVar4);
        *(undefined8 *)(param_1 + 0x138) = uVar9;
        uVar9 = FUN_180833830(plVar4);
        *(undefined8 *)(param_1 + 0x140) = uVar9;
        uVar9 = FUN_180833830(plVar4);
        *(undefined8 *)(param_1 + 0x148) = uVar9;
      }
    }
  }
  (**(code **)(*plVar4 + 0x28))(plVar4);
  return;
}



/* ==== 1808c4b60 FUN_1808c4b60 ==== */

void FUN_1808c4b60(longlong param_1,__uint64 param_2,uint param_3)

{
  longlong *plVar1;
  OdRxClass *pOVar2;
  longlong *plVar3;
  OdRxClass *pOVar4;
  longlong lVar5;
  undefined4 *puVar6;
  undefined4 local_res18 [2];
  longlong *local_res20;
  longlong *local_28 [2];
  
  plVar1 = (longlong *)OdFlatMemStream::createNew(&local_res20,param_2,(ulonglong)param_3);
  local_28[0] = (longlong *)0x0;
  plVar1 = (longlong *)*plVar1;
  plVar3 = local_28[0];
  if (plVar1 != (longlong *)0x0) {
    lVar5 = *plVar1;
    pOVar2 = OdStreamBuf::desc();
    plVar3 = (longlong *)(**(code **)(lVar5 + 8))(plVar1,pOVar2);
    if (plVar3 == (longlong *)0x0) {
      pOVar2 = OdStreamBuf::desc();
      pOVar4 = (OdRxClass *)(**(code **)(*plVar1 + 0x18))(plVar1);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_28,pOVar4,pOVar2);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_28,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_28[0] = plVar3;
  plVar1 = local_28[0];
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))();
    local_res20 = (longlong *)0x0;
  }
  (**(code **)(*plVar1 + 0x98))(plVar1,local_res18,4);
  (**(code **)(*(longlong *)(param_1 + 0x58) + 0x68))((longlong *)(param_1 + 0x58),local_res18[0]);
  if (7 < param_3) {
    (**(code **)(*plVar1 + 0x98))(plVar1,local_res18,4);
    *(undefined4 *)(param_1 + 0x10) = local_res18[0];
  }
  if (0xb < param_3) {
    (**(code **)(*plVar1 + 0x98))(plVar1,local_res18,4);
    *(undefined4 *)(param_1 + 0x14) = local_res18[0];
  }
  if (0xf < param_3) {
    (**(code **)(*plVar1 + 0x98))(plVar1,local_res18,4);
    *(undefined4 *)(param_1 + 0x18) = local_res18[0];
  }
  if (0x13 < param_3) {
    (**(code **)(*plVar1 + 0x98))(plVar1,local_res18,4);
    *(undefined4 *)(param_1 + 0x1c) = local_res18[0];
  }
  if (0x17 < param_3) {
    (**(code **)(*plVar1 + 0x98))(plVar1,local_res18,4);
    *(undefined4 *)(param_1 + 0x20) = local_res18[0];
  }
  if (0x1b < param_3) {
    (**(code **)(*plVar1 + 0x98))(plVar1,local_res18,4);
    *(undefined4 *)(param_1 + 0x24) = local_res18[0];
  }
  if (0x1f < param_3) {
    (**(code **)(*plVar1 + 0x98))(plVar1,local_res18,4);
    *(undefined4 *)(param_1 + 0x28) = local_res18[0];
  }
  if (0x47 < param_3) {
    puVar6 = (undefined4 *)(param_1 + 0x2c);
    lVar5 = 10;
    do {
      (**(code **)(*plVar1 + 0x98))(plVar1,local_res18,4);
      *puVar6 = local_res18[0];
      puVar6 = puVar6 + 1;
      lVar5 = lVar5 + -1;
    } while (lVar5 != 0);
  }
  (**(code **)(*plVar1 + 0x28))(plVar1);
  return;
}



/* ==== 1808cb030 FUN_1808cb030 ==== */

void FUN_1808cb030(longlong param_1,__uint64 param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  longlong lVar5;
  longlong *plVar6;
  OdRxClass *pOVar7;
  longlong *plVar8;
  undefined8 *puVar9;
  undefined4 *puVar10;
  OdRxClass *pOVar11;
  uint uVar12;
  ulonglong uVar13;
  ulonglong *puVar14;
  ulonglong uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  undefined4 uVar19;
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  uint local_e8 [2];
  undefined6 local_e0;
  byte bStack_da;
  byte bStack_d9;
  undefined6 local_d8;
  byte bStack_d2;
  byte bStack_d1;
  undefined6 local_d0;
  byte bStack_ca;
  byte bStack_c9;
  undefined6 local_c8;
  byte bStack_c2;
  byte bStack_c1;
  undefined6 local_c0;
  byte bStack_ba;
  byte bStack_b9;
  undefined6 local_b8;
  byte bStack_b2;
  byte bStack_b1;
  undefined6 local_b0;
  byte bStack_aa;
  byte bStack_a9;
  undefined6 local_a8;
  byte bStack_a2;
  byte bStack_a1;
  undefined6 local_a0;
  byte bStack_9a;
  byte bStack_99;
  undefined6 local_98;
  byte bStack_92;
  byte bStack_91;
  undefined6 local_90;
  byte bStack_8a;
  byte bStack_89;
  undefined6 local_88;
  byte bStack_82;
  byte bStack_81;
  undefined6 local_80;
  byte bStack_7a;
  byte bStack_79;
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
  longlong *local_58;
  undefined8 local_50;
  undefined8 uStack_48;
  
  plVar6 = (longlong *)OdFlatMemStream::createNew(&local_58,param_2,(ulonglong)param_3);
  local_60 = (longlong *)0x0;
  plVar6 = (longlong *)*plVar6;
  plVar8 = local_60;
  if (plVar6 != (longlong *)0x0) {
    lVar5 = *plVar6;
    pOVar7 = OdStreamBuf::desc();
    plVar8 = (longlong *)(**(code **)(lVar5 + 8))(plVar6,pOVar7);
    if (plVar8 == (longlong *)0x0) {
      pOVar7 = OdStreamBuf::desc();
      pOVar11 = (OdRxClass *)(**(code **)(*plVar6 + 0x18))(plVar6);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res20,pOVar11,pOVar7);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_60 = plVar8;
  plVar6 = local_60;
  if (local_58 != (longlong *)0x0) {
    (**(code **)(*local_58 + 0x28))();
    local_58 = (longlong *)0x0;
  }
  (**(code **)(*plVar6 + 0x98))(plVar6,local_res18,4);
  (**(code **)(*(longlong *)(param_1 + 0x10) + 0x68))((longlong *)(param_1 + 0x10),local_res18[0]);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_e0,8);
  uVar12 = (bStack_d9 & 0x7f) << 4 | (uint)(bStack_da >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_e0;
    uVar19 = (undefined4)(CONCAT17(bStack_d9,CONCAT16(bStack_da,local_e0)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x20) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_d8,8);
  uVar12 = (bStack_d1 & 0x7f) << 4 | (uint)(bStack_d2 >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_d8;
    uVar19 = (undefined4)(CONCAT17(bStack_d1,CONCAT16(bStack_d2,local_d8)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x28) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_d0,8);
  uVar12 = (bStack_c9 & 0x7f) << 4 | (uint)(bStack_ca >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_d0;
    uVar19 = (undefined4)(CONCAT17(bStack_c9,CONCAT16(bStack_ca,local_d0)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x30) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_c8,8);
  uVar12 = (bStack_c1 & 0x7f) << 4 | (uint)(bStack_c2 >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_c8;
    uVar19 = (undefined4)(CONCAT17(bStack_c1,CONCAT16(bStack_c2,local_c8)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x38) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_c0,8);
  uVar12 = (bStack_b9 & 0x7f) << 4 | (uint)(bStack_ba >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_c0;
    uVar19 = (undefined4)(CONCAT17(bStack_b9,CONCAT16(bStack_ba,local_c0)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x40) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_b8,8);
  uVar12 = (bStack_b1 & 0x7f) << 4 | (uint)(bStack_b2 >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_b8;
    uVar19 = (undefined4)(CONCAT17(bStack_b1,CONCAT16(bStack_b2,local_b8)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x48) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_b0,8);
  uVar12 = (bStack_a9 & 0x7f) << 4 | (uint)(bStack_aa >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_b0;
    uVar19 = (undefined4)(CONCAT17(bStack_a9,CONCAT16(bStack_aa,local_b0)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x50) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_a8,8);
  uVar12 = (bStack_a1 & 0x7f) << 4 | (uint)(bStack_a2 >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_a8;
    uVar19 = (undefined4)(CONCAT17(bStack_a1,CONCAT16(bStack_a2,local_a8)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x58) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_a0,8);
  uVar12 = (bStack_99 & 0x7f) << 4 | (uint)(bStack_9a >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_a0;
    uVar19 = (undefined4)(CONCAT17(bStack_99,CONCAT16(bStack_9a,local_a0)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x60) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_98,8);
  uVar12 = (bStack_91 & 0x7f) << 4 | (uint)(bStack_92 >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_98;
    uVar19 = (undefined4)(CONCAT17(bStack_91,CONCAT16(bStack_92,local_98)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x68) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_90,8);
  uVar12 = (bStack_89 & 0x7f) << 4 | (uint)(bStack_8a >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_90;
    uVar19 = (undefined4)(CONCAT17(bStack_89,CONCAT16(bStack_8a,local_90)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x70) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_88,8);
  uVar12 = (bStack_81 & 0x7f) << 4 | (uint)(bStack_82 >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_88;
    uVar19 = (undefined4)(CONCAT17(bStack_81,CONCAT16(bStack_82,local_88)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x78) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_80,8);
  uVar12 = (bStack_79 & 0x7f) << 4 | (uint)(bStack_7a >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_80;
    uVar19 = (undefined4)(CONCAT17(bStack_79,CONCAT16(bStack_7a,local_80)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x80) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,&local_78,8);
  uVar12 = (bStack_71 & 0x7f) << 4 | (uint)(bStack_72 >> 4);
  if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
    uVar18 = 0;
    uVar19 = 0;
  }
  else {
    uVar18 = (undefined4)local_78;
    uVar19 = (undefined4)(CONCAT17(bStack_71,CONCAT16(bStack_72,local_78)) >> 0x20);
  }
  *(ulonglong *)(param_1 + 0x88) = CONCAT44(uVar19,uVar18);
  (**(code **)(*plVar6 + 0x98))(plVar6,local_res20,4);
  *(undefined4 *)(param_1 + 0x90) = local_res20[0];
  (**(code **)(*plVar6 + 0x98))(plVar6,local_e8,4);
  if (local_e8[0] != 0) {
    puVar14 = (ulonglong *)(param_1 + 0x98);
    uVar15 = (ulonglong)local_e8[0];
    do {
      (**(code **)(*plVar6 + 0x98))(plVar6,&local_70,8);
      uVar12 = (bStack_69 & 0x7f) << 4 | (uint)(bStack_6a >> 4);
      if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
        uVar18 = 0;
        uVar19 = 0;
      }
      else {
        uVar18 = (undefined4)local_70;
        uVar19 = (undefined4)(CONCAT17(bStack_69,CONCAT16(bStack_6a,local_70)) >> 0x20);
      }
      local_50 = CONCAT44(uVar19,uVar18);
      (**(code **)(*plVar6 + 0x98))(plVar6,&local_68,8);
      uVar12 = (bStack_61 & 0x7f) << 4 | (uint)(bStack_62 >> 4);
      if ((uVar12 == 0) || (uVar12 == 0x7ff)) {
        uVar16 = 0;
        uVar17 = 0;
      }
      else {
        uVar16 = (undefined4)local_68;
        uVar17 = (undefined4)(CONCAT17(bStack_61,CONCAT16(bStack_62,local_68)) >> 0x20);
      }
      uStack_48 = CONCAT44(uVar17,uVar16);
      uVar12 = *(uint *)(*puVar14 - 4);
      LOCK();
      piVar1 = (int *)(*puVar14 - 0x10);
      iVar2 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if ((iVar2 < 2) && (uVar12 != *(uint *)(*puVar14 - 8))) {
LAB_1808cb640:
        puVar10 = (undefined4 *)((ulonglong)uVar12 * 0x10 + *puVar14);
        *puVar10 = (undefined4)local_50;
        puVar10[1] = local_50._4_4_;
        puVar10[2] = (undefined4)uStack_48;
        puVar10[3] = uStack_48._4_4_;
      }
      else {
        if (*(int *)(*puVar14 - 4) != 0) {
          LOCK();
          piVar1 = (int *)(*puVar14 - 0x10);
          iVar3 = *piVar1;
          *piVar1 = *piVar1;
          UNLOCK();
          if (1 < iVar3) {
            FUN_180037ef0(puVar14,*(undefined4 *)(*puVar14 - 8),0,0,1);
          }
          if ((*(int *)((longlong)*puVar14 - 4) == 0) || ((undefined8 *)*puVar14 <= &local_50))
          goto LAB_1808cb5a9;
LAB_1808cb626:
          FUN_180037ef0(puVar14,uVar12 + 1,iVar2 < 2,0,1);
          goto LAB_1808cb640;
        }
LAB_1808cb5a9:
        if (*(int *)(*puVar14 - 4) == 0) goto LAB_1808cb626;
        LOCK();
        piVar1 = (int *)(*puVar14 - 0x10);
        iVar3 = *piVar1;
        *piVar1 = *piVar1;
        UNLOCK();
        if (1 < iVar3) {
          FUN_180037ef0(puVar14,*(undefined4 *)(*puVar14 - 8),0,0,1);
        }
        uVar4 = *(uint *)(*puVar14 - 4);
        uVar13 = 0;
        if (uVar4 != 0) {
          uVar13 = *puVar14;
        }
        if ((undefined8 *)(uVar13 + (ulonglong)uVar4 * 0x10) <= &local_50) goto LAB_1808cb626;
        FUN_180037ef0(puVar14,uVar12 + 1,iVar2 < 2,0,1);
        puVar9 = (undefined8 *)((ulonglong)uVar12 * 0x10 + *puVar14);
        *puVar9 = CONCAT44(uVar19,uVar18);
        puVar9[1] = CONCAT44(uVar17,uVar16);
      }
      *(int *)(*puVar14 - 4) = *(int *)(*puVar14 - 4) + 1;
      uVar15 = uVar15 - 1;
      plVar6 = local_60;
    } while (uVar15 != 0);
  }
  (**(code **)(*plVar6 + 0x28))(plVar6);
  return;
}



/* ==== 1808d3970 FUN_1808d3970 ==== */

void FUN_1808d3970(longlong param_1,__uint64 param_2,uint param_3)

{
  int iVar1;
  longlong lVar2;
  bool bVar3;
  bool bVar4;
  longlong *plVar5;
  OdRxClass *pOVar6;
  longlong *plVar7;
  undefined8 uVar8;
  ushort *puVar9;
  ushort *puVar10;
  OdRxClass *pOVar11;
  code *pcVar12;
  uint uVar13;
  uint local_res20 [2];
  longlong local_88;
  longlong local_80;
  longlong *local_78;
  uint local_70 [2];
  code *local_68;
  code *local_60;
  undefined4 local_58 [2];
  longlong *local_50;
  undefined1 local_48 [4];
  undefined1 local_44 [4];
  undefined1 local_40 [4];
  undefined1 local_3c [4];
  undefined1 local_38 [4];
  undefined1 local_34 [12];
  
  plVar5 = (longlong *)OdFlatMemStream::createNew(&local_50,param_2,(ulonglong)param_3);
  local_78 = (longlong *)0x0;
  plVar5 = (longlong *)*plVar5;
  plVar7 = local_78;
  if (plVar5 != (longlong *)0x0) {
    lVar2 = *plVar5;
    pOVar6 = OdStreamBuf::desc();
    plVar7 = (longlong *)(**(code **)(lVar2 + 8))(plVar5,pOVar6);
    if (plVar7 == (longlong *)0x0) {
      pOVar6 = OdStreamBuf::desc();
      pOVar11 = (OdRxClass *)(**(code **)(*plVar5 + 0x18))(plVar5);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)local_res20,pOVar11,pOVar6);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_78 = plVar7;
  plVar5 = local_78;
  if (local_50 != (longlong *)0x0) {
    (**(code **)(*local_50 + 0x28))();
    local_50 = (longlong *)0x0;
  }
  (**(code **)(*plVar5 + 0x98))(plVar5,local_58,4);
  (**(code **)(*(longlong *)(param_1 + 0x20) + 0x68))((longlong *)(param_1 + 0x20),local_58[0]);
  (**(code **)(*plVar5 + 0x98))(plVar5,local_48,4);
  (**(code **)(*plVar5 + 0x98))(plVar5,local_44,4);
  (**(code **)(*plVar5 + 0x98))(plVar5,local_40,4);
  (**(code **)(*plVar5 + 0x98))(plVar5,local_3c,4);
  (**(code **)(*plVar5 + 0x98))(plVar5,local_38,4);
  (**(code **)(*plVar5 + 0x98))(plVar5,local_34,4);
  (**(code **)(*plVar5 + 0x98))(plVar5,local_res20,4);
  bVar3 = true;
  if (local_res20[0] != 0) {
    local_68 = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
    UNLOCK();
    FUN_1800150c0(&local_68,local_res20[0]);
    plVar5 = local_78;
    lVar2 = *local_78;
    uVar8 = FUN_18023d1f0(&local_68);
    (**(code **)(lVar2 + 0x98))(plVar5,uVar8,local_res20[0]);
    puVar9 = (ushort *)FUN_18023d1f0(&local_68);
    uVar13 = local_res20[0] >> 1;
    OdString::init((OdString *)&local_88);
    bVar4 = true;
    if (uVar13 == 0xffffffff) {
      OdString::operator=((OdString *)&local_88,puVar9);
      if ((*(longlong *)(local_88 + 0x10) != 0) || (*(longlong *)(local_88 + 0x18) == 0)) {
        bVar4 = false;
      }
      if (bVar4) {
        OdString::syncUnicode((OdString *)&local_88);
      }
    }
    else {
      puVar10 = OdString::getBuffer((OdString *)&local_88,uVar13);
      memcpy(puVar10,puVar9,(ulonglong)uVar13 * 2);
      OdString::releaseBuffer((OdString *)&local_88,uVar13);
    }
    OdString::operator=((OdString *)(param_1 + 0x10),(OdString *)&local_88);
    OdString::~OdString((OdString *)&local_88);
    pcVar12 = local_68 + -0x10;
    LOCK();
    iVar1 = *(int *)pcVar12;
    *(int *)pcVar12 = *(int *)pcVar12 + -1;
    UNLOCK();
    plVar5 = local_78;
    if ((iVar1 == 1) && (pcVar12 != g_empty_array_buffer_exref)) {
      odrxFree();
      plVar5 = local_78;
    }
  }
  (**(code **)(*plVar5 + 0x98))(plVar5,local_70,4);
  if (local_70[0] != 0) {
    local_60 = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
    UNLOCK();
    FUN_1800150c0(&local_60,local_70[0]);
    plVar5 = local_78;
    lVar2 = *local_78;
    uVar8 = FUN_18023d1f0(&local_60);
    (**(code **)(lVar2 + 0x98))(plVar5,uVar8,local_70[0]);
    puVar9 = (ushort *)FUN_18023d1f0(&local_60);
    uVar13 = local_70[0] >> 1;
    OdString::init((OdString *)&local_80);
    if (uVar13 == 0xffffffff) {
      OdString::operator=((OdString *)&local_80,puVar9);
      if ((*(longlong *)(local_80 + 0x10) != 0) || (*(longlong *)(local_80 + 0x18) == 0)) {
        bVar3 = false;
      }
      if (bVar3) {
        OdString::syncUnicode((OdString *)&local_80);
      }
    }
    else {
      puVar10 = OdString::getBuffer((OdString *)&local_80,uVar13);
      memcpy(puVar10,puVar9,(ulonglong)uVar13 * 2);
      OdString::releaseBuffer((OdString *)&local_80,uVar13);
    }
    OdString::operator=((OdString *)(param_1 + 0x18),(OdString *)&local_80);
    OdString::~OdString((OdString *)&local_80);
    pcVar12 = local_60 + -0x10;
    LOCK();
    iVar1 = *(int *)pcVar12;
    *(int *)pcVar12 = *(int *)pcVar12 + -1;
    UNLOCK();
    plVar5 = local_78;
    if ((iVar1 == 1) && (pcVar12 != g_empty_array_buffer_exref)) {
      odrxFree();
      plVar5 = local_78;
    }
  }
  (**(code **)(*plVar5 + 0x28))(plVar5);
  return;
}



