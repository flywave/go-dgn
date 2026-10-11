/* ==== 1802e44a0 FUN_1802e44a0 ==== */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_1802e44a0(longlong param_1,longlong *param_2)

{
  int *piVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  int iVar4;
  longlong lVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined1 auStack_a8 [32];
  undefined1 local_88;
  OdError_InvalidIndex local_78 [16];
  undefined8 local_68;
  undefined8 uStack_60;
  undefined8 local_58;
  undefined8 uStack_50;
  undefined8 local_48;
  undefined8 uStack_40;
  undefined8 local_38;
  undefined8 uStack_30;
  undefined8 local_28;
  ulonglong local_18;
  
  local_18 = DAT_180fcd438 ^ (ulonglong)auStack_a8;
  (**(code **)(*(longlong *)(param_1 + 0x220) + 0x40))();
  plVar2 = (longlong *)(param_1 + 0x248);
  FUN_1802e7e60(plVar2,*(undefined4 *)(*(longlong *)(param_1 + 0x230) + -4));
  uVar7 = 0;
  if (*(int *)(*plVar2 + -4) != 0) {
    do {
      OdGeMatrix2d::OdGeMatrix2d((OdGeMatrix2d *)&local_68);
      local_68 = (**(code **)(*param_2 + 200))(param_2);
      uStack_60 = (**(code **)(*param_2 + 200))(param_2);
      uStack_50 = (**(code **)(*param_2 + 200))(param_2);
      local_48 = (**(code **)(*param_2 + 200))(param_2);
      if (*(uint *)(*plVar2 + -4) <= (uint)uVar7) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_78);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_78,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar1 = (int *)(*plVar2 + -0x10);
      iVar4 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar4) {
        local_88 = 1;
        FUN_180185220(plVar2,*(undefined4 *)(*plVar2 + -8),0,0);
      }
      lVar5 = *plVar2;
      uVar6 = (uint)uVar7 + 1;
      puVar3 = (undefined8 *)(lVar5 + uVar7 * 0x48);
      *puVar3 = local_68;
      puVar3[1] = uStack_60;
      puVar3 = (undefined8 *)(lVar5 + 0x10 + uVar7 * 0x48);
      *puVar3 = local_58;
      puVar3[1] = uStack_50;
      puVar3 = (undefined8 *)(lVar5 + 0x20 + uVar7 * 0x48);
      *puVar3 = local_48;
      puVar3[1] = uStack_40;
      puVar3 = (undefined8 *)(lVar5 + 0x30 + uVar7 * 0x48);
      *puVar3 = local_38;
      puVar3[1] = uStack_30;
      *(undefined8 *)(lVar5 + 0x40 + uVar7 * 0x48) = local_28;
      uVar7 = (ulonglong)uVar6;
    } while (uVar6 < *(uint *)(*plVar2 + -4));
  }
  return 0;
}



/* ==== 1802e4620 FUN_1802e4620 ==== */

undefined8 FUN_1802e4620(longlong param_1,longlong *param_2)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  OdError_InvalidIndex local_res8 [8];
  undefined1 local_28 [32];
  
  (**(code **)(*(longlong *)(param_1 + 0x220) + 0x40))();
  plVar2 = (longlong *)(param_1 + 0x248);
  FUN_1802e7f20(plVar2,*(undefined4 *)(*(longlong *)(param_1 + 0x230) + -4));
  uVar10 = 0;
  if (*(int *)(*plVar2 + -4) != 0) {
    do {
      if (*(uint *)(*plVar2 + -4) <= uVar10) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar1 = (int *)(*plVar2 + -0x10);
      iVar3 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar3) {
        FUN_1802e3f90(plVar2,*(undefined4 *)(*plVar2 + -8),0,0,1);
      }
      puVar9 = (undefined4 *)((ulonglong)uVar10 * 0x20 + *plVar2);
      puVar8 = (undefined4 *)(**(code **)(*param_2 + 0x128))(param_2,local_28);
      uVar10 = uVar10 + 1;
      uVar4 = puVar8[1];
      uVar5 = puVar8[2];
      uVar6 = puVar8[3];
      *puVar9 = *puVar8;
      puVar9[1] = uVar4;
      puVar9[2] = uVar5;
      puVar9[3] = uVar6;
      uVar7 = *(undefined8 *)(puVar8 + 6);
      *(undefined8 *)(puVar9 + 4) = *(undefined8 *)(puVar8 + 4);
      *(undefined8 *)(puVar9 + 6) = uVar7;
    } while (uVar10 < *(uint *)(*plVar2 + -4));
  }
  return 0;
}



/* ==== 1802e4710 FUN_1802e4710 ==== */

void FUN_1802e4710(longlong param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0001802e471a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(longlong *)(param_1 + 0x220) + 0x48))();
  return;
}



/* ==== 1802e4720 FUN_1802e4720 ==== */

void FUN_1802e4720(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  uint uVar2;
  ulonglong uVar3;
  OdError_InvalidIndex local_res8 [8];
  
  (**(code **)(*(longlong *)(param_1 + 0x220) + 0x48))();
  uVar3 = 0;
  if (*(int *)(*(longlong *)(param_1 + 0x248) + -4) != 0) {
    do {
      lVar1 = *(longlong *)(param_1 + 0x248);
      if (*(uint *)(lVar1 + -4) <= (uint)uVar3) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(lVar1 + uVar3 * 0x48));
      (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(lVar1 + 8 + uVar3 * 0x48));
      (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(lVar1 + 0x18 + uVar3 * 0x48));
      (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(lVar1 + 0x20 + uVar3 * 0x48));
      uVar2 = (uint)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < *(uint *)(*(longlong *)(param_1 + 0x248) + -4));
  }
  return;
}



/* ==== 1802e47f0 FUN_1802e47f0 ==== */

void FUN_1802e47f0(longlong param_1,longlong *param_2)

{
  uint uVar1;
  OdError_InvalidIndex local_res8 [8];
  
  (**(code **)(*(longlong *)(param_1 + 0x220) + 0x48))();
  uVar1 = 0;
  if (*(int *)(*(longlong *)(param_1 + 0x248) + -4) != 0) {
    do {
      if (*(uint *)(*(longlong *)(param_1 + 0x248) + -4) <= uVar1) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      (**(code **)(*param_2 + 0x1c0))
                (param_2,(ulonglong)uVar1 * 0x20 + *(longlong *)(param_1 + 0x248));
      uVar1 = uVar1 + 1;
    } while (uVar1 < *(uint *)(*(longlong *)(param_1 + 0x248) + -4));
  }
  return;
}



