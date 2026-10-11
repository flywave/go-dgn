/* ==== 1800a3440 FUN_1800a3440 ==== */

undefined8 FUN_1800a3440(longlong param_1,longlong *param_2)

{
  undefined8 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uVar3 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x240) = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x244) = uVar3;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x248) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x24a) = uVar2;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x250) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 600) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x260) = uVar1;
  (**(code **)(*param_2 + 0x128))(param_2,&local_28);
  *(undefined4 *)(param_1 + 0x268) = local_28;
  *(undefined4 *)(param_1 + 0x26c) = uStack_24;
  *(undefined4 *)(param_1 + 0x270) = uStack_20;
  *(undefined4 *)(param_1 + 0x274) = uStack_1c;
  *(undefined4 *)(param_1 + 0x278) = local_18;
  *(undefined4 *)(param_1 + 0x27c) = uStack_14;
  *(undefined4 *)(param_1 + 0x280) = uStack_10;
  *(undefined4 *)(param_1 + 0x284) = uStack_c;
  (**(code **)(*param_2 + 0x110))(param_2,&local_28);
  *(ulonglong *)(param_1 + 0x288) = CONCAT44(uStack_24,local_28);
  *(ulonglong *)(param_1 + 0x290) = CONCAT44(uStack_1c,uStack_20);
  *(ulonglong *)(param_1 + 0x298) = CONCAT44(uStack_14,local_18);
  return 0;
}



/* ==== 1801d8e60 FUN_1801d8e60 ==== */

undefined8 FUN_1801d8e60(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 local_28 [32];
  
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x44] = lVar1;
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x45] = lVar1;
  puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x128))(param_2,local_28);
  uVar2 = puVar5[1];
  uVar3 = puVar5[2];
  uVar4 = puVar5[3];
  *(undefined4 *)(param_1 + 0x48) = *puVar5;
  *(undefined4 *)((longlong)param_1 + 0x244) = uVar2;
  *(undefined4 *)(param_1 + 0x49) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x24c) = uVar4;
  uVar2 = puVar5[5];
  uVar3 = puVar5[6];
  uVar4 = puVar5[7];
  *(undefined4 *)(param_1 + 0x4a) = puVar5[4];
  *(undefined4 *)((longlong)param_1 + 0x254) = uVar2;
  *(undefined4 *)(param_1 + 0x4b) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x25c) = uVar4;
  puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_28);
  uVar2 = puVar5[1];
  uVar3 = puVar5[2];
  uVar4 = puVar5[3];
  *(undefined4 *)(param_1 + 0x4c) = *puVar5;
  *(undefined4 *)((longlong)param_1 + 0x264) = uVar2;
  *(undefined4 *)(param_1 + 0x4d) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x26c) = uVar4;
  param_1[0x4e] = *(longlong *)(puVar5 + 4);
  (**(code **)(*param_1 + 0x630))(param_1);
  return 0;
}



/* ==== 1801dc040 FUN_1801dc040 ==== */

undefined8 FUN_1801dc040(longlong param_1,longlong *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined4 *puVar5;
  undefined8 *puVar6;
  undefined1 local_28 [32];
  
  puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_28);
  uVar1 = puVar5[1];
  uVar2 = puVar5[2];
  uVar3 = puVar5[3];
  *(undefined4 *)(param_1 + 0x220) = *puVar5;
  *(undefined4 *)(param_1 + 0x224) = uVar1;
  *(undefined4 *)(param_1 + 0x228) = uVar2;
  *(undefined4 *)(param_1 + 0x22c) = uVar3;
  *(undefined8 *)(param_1 + 0x230) = *(undefined8 *)(puVar5 + 4);
  puVar6 = (undefined8 *)(**(code **)(*param_2 + 0x110))(param_2,local_28);
  uVar4 = puVar6[1];
  *(undefined8 *)(param_1 + 0x238) = *puVar6;
  *(undefined8 *)(param_1 + 0x240) = uVar4;
  *(undefined8 *)(param_1 + 0x248) = puVar6[2];
  return 0;
}



/* ==== 180286720 FUN_180286720 ==== */

undefined8 FUN_180286720(longlong *param_1,longlong *param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 local_28 [32];
  
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x44] = lVar1;
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x45] = lVar1;
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x46] = lVar1;
  lVar1 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x47] = lVar1;
  puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x128))(param_2,local_28);
  uVar2 = puVar5[1];
  uVar3 = puVar5[2];
  uVar4 = puVar5[3];
  *(undefined4 *)(param_1 + 0x4a) = *puVar5;
  *(undefined4 *)((longlong)param_1 + 0x254) = uVar2;
  *(undefined4 *)(param_1 + 0x4b) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x25c) = uVar4;
  uVar2 = puVar5[5];
  uVar3 = puVar5[6];
  uVar4 = puVar5[7];
  *(undefined4 *)(param_1 + 0x4c) = puVar5[4];
  *(undefined4 *)((longlong)param_1 + 0x264) = uVar2;
  *(undefined4 *)(param_1 + 0x4d) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x26c) = uVar4;
  puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_28);
  uVar2 = puVar5[1];
  uVar3 = puVar5[2];
  uVar4 = puVar5[3];
  *(undefined4 *)(param_1 + 0x4e) = *puVar5;
  *(undefined4 *)((longlong)param_1 + 0x274) = uVar2;
  *(undefined4 *)(param_1 + 0x4f) = uVar3;
  *(undefined4 *)((longlong)param_1 + 0x27c) = uVar4;
  param_1[0x50] = *(longlong *)(puVar5 + 4);
  (**(code **)(*param_1 + 0x650))(param_1);
  return 0;
}



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



