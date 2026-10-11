/* ==== 1808275d0 FUN_1808275d0 ==== */

void FUN_1808275d0(longlong param_1,longlong *param_2)

{
  int iVar1;
  longlong *plVar2;
  undefined4 uVar3;
  longlong lVar4;
  uint uVar5;
  undefined8 local_res8;
  longlong *local_res10;
  
  OdMemoryStream::createNew((ulong)&local_res10);
  uVar5 = 0x1880;
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0) {
    uVar5 = 0x5880;
  }
  else if (iVar1 == 2) {
    uVar5 = 0x1881;
  }
  else if (iVar1 == 3) {
    uVar5 = 0x1882;
  }
  else if (iVar1 == 4) {
    uVar5 = 0x1883;
  }
  if (*(int *)(param_1 + 0x14) == 1) {
    uVar5 = uVar5 | 0x200;
  }
  else if (*(int *)(param_1 + 0x14) == 2) {
    uVar5 = uVar5 | 0x300;
  }
  if (*(char *)(param_1 + 0x18) != '\0') {
    uVar5 = uVar5 | 0x400;
  }
  local_res8 = CONCAT44(local_res8._4_4_,uVar5);
  (**(code **)(*local_res10 + 0xa8))(local_res10,&local_res8,4);
  local_res8 = *(undefined8 *)(param_1 + 0x20);
  (**(code **)(*local_res10 + 0xa8))(local_res10,&local_res8,8);
  uVar3 = (**(code **)(*local_res10 + 0x70))();
  (**(code **)(*local_res10 + 0x88))(local_res10,0,0);
  FUN_1800150c0(param_2);
  plVar2 = local_res10;
  FUN_18000d0b0(param_2);
  lVar4 = 0;
  if (*(int *)(*param_2 + -4) != 0) {
    lVar4 = *param_2;
  }
  (**(code **)(*plVar2 + 0x98))(plVar2,lVar4,uVar3);
  if (local_res10 != (longlong *)0x0) {
    (**(code **)(*local_res10 + 0x28))();
  }
  return;
}



/* ==== 180828150 FUN_180828150 ==== */

undefined8 * FUN_180828150(longlong param_1,undefined8 *param_2)

{
  *param_2 = OdDgAttributeLinkageHeader::vftable;
  *(undefined4 *)(param_2 + 1) = *(undefined4 *)(param_1 + 0x30);
  return param_2;
}



/* ==== 1808296b0 FUN_1808296b0 ==== */

undefined8 FUN_1808296b0(void)

{
  return 0x56d8;
}



/* ==== 180829f90 FUN_180829f90 ==== */

void FUN_180829f90(longlong param_1,__uint64 param_2,uint param_3)

{
  longlong lVar1;
  longlong *plVar2;
  OdRxClass *pOVar3;
  longlong *plVar4;
  OdRxClass *pOVar5;
  uint uVar6;
  undefined8 uVar7;
  uint local_res18 [2];
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
  if (8 < param_3) {
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
  if ((local_res18[0] >> 0xe & 1) == 0) {
    if (((byte)local_res18[0] & 3) == 3) {
      *(undefined4 *)(param_1 + 0x10) = 4;
    }
    else if ((local_res18[0] & 1) == 0) {
      *(uint *)(param_1 + 0x10) = local_res18[0] & 2 | 1;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = 2;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  if ((local_res18[0] & 0x300) == 0x300) {
    *(undefined4 *)(param_1 + 0x14) = 2;
  }
  else {
    *(uint *)(param_1 + 0x14) = local_res18[0] >> 9 & 1;
  }
  *(byte *)(param_1 + 0x18) = (byte)(local_res18[0] >> 10) & 1;
  (**(code **)(*plVar2 + 0x28))(plVar2);
  return;
}



/* ==== 18082cb40 FUN_18082cb40 ==== */

void FUN_18082cb40(longlong param_1,longlong param_2)

{
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_2 + 8);
  return;
}



