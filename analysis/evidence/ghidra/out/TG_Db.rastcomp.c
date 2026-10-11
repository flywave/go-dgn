/* ==== 180281570 FUN_180281570 ==== */

undefined8 FUN_180281570(longlong param_1,longlong *param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x220) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x222) = uVar2;
  uVar1 = (**(code **)(*param_2 + 0x98))(param_2);
  *(undefined1 *)(param_1 + 0x224) = uVar1;
  uVar1 = (**(code **)(*param_2 + 0x98))(param_2);
  *(undefined1 *)(param_1 + 0x225) = uVar1;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x226) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x228) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x22a) = uVar2;
  iVar3 = (**(code **)(*param_2 + 0x88))(param_2);
  iVar4 = (**(code **)(*param_2 + 0x80))(param_2);
  FUN_1800150c0(param_1 + 0x230);
  FUN_18000d0b0(param_1 + 0x230);
  lVar5 = 0;
  if (*(int *)(*(longlong *)(param_1 + 0x230) + -4) != 0) {
    lVar5 = *(longlong *)(param_1 + 0x230);
  }
  (**(code **)(*param_2 + 0x90))(param_2,lVar5,iVar3 - iVar4);
  return 0;
}



/* ==== 1803af120 FUN_1803af120 ==== */

undefined8 FUN_1803af120(longlong param_1,longlong *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  OdError_InvalidIndex local_res8 [8];
  undefined1 local_28 [16];
  
  uVar3 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x220) = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x222) = uVar3;
  uVar4 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x224) = uVar4;
  uVar3 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x228) = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x22a) = uVar3;
  FUN_180192eb0(param_1 + 0x230);
  uVar4 = (**(code **)(*param_2 + 0xb0))(param_2);
  uVar6 = 0;
  *(undefined4 *)(param_1 + 0x22c) = uVar4;
  if (*(short *)(param_1 + 0x22a) != 0) {
    do {
      if (*(uint *)(*(longlong *)(param_1 + 0x230) + -4) <= uVar6) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_180017f50(param_1 + 0x230);
      puVar7 = (undefined4 *)((ulonglong)uVar6 * 0x10 + *(longlong *)(param_1 + 0x230));
      puVar5 = (undefined4 *)(**(code **)(*param_2 + 0x100))(param_2,local_28);
      uVar6 = uVar6 + 1;
      uVar4 = puVar5[1];
      uVar1 = puVar5[2];
      uVar2 = puVar5[3];
      *puVar7 = *puVar5;
      puVar7[1] = uVar4;
      puVar7[2] = uVar1;
      puVar7[3] = uVar2;
    } while (uVar6 < *(ushort *)(param_1 + 0x22a));
  }
  return 0;
}



/* ==== 1803af240 FUN_1803af240 ==== */

undefined8 FUN_1803af240(longlong param_1,longlong *param_2)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined8 *puVar7;
  undefined1 local_28 [32];
  
  uVar4 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x220) = uVar4;
  uVar4 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x222) = uVar4;
  uVar5 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x224) = uVar5;
  puVar6 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_28);
  uVar5 = puVar6[1];
  uVar2 = puVar6[2];
  uVar3 = puVar6[3];
  *(undefined4 *)(param_1 + 0x228) = *puVar6;
  *(undefined4 *)(param_1 + 0x22c) = uVar5;
  *(undefined4 *)(param_1 + 0x230) = uVar2;
  *(undefined4 *)(param_1 + 0x234) = uVar3;
  *(undefined8 *)(param_1 + 0x238) = *(undefined8 *)(puVar6 + 4);
  puVar6 = (undefined4 *)(**(code **)(*param_2 + 0x100))(param_2,local_28);
  uVar5 = puVar6[1];
  uVar2 = puVar6[2];
  uVar3 = puVar6[3];
  *(undefined4 *)(param_1 + 0x240) = *puVar6;
  *(undefined4 *)(param_1 + 0x244) = uVar5;
  *(undefined4 *)(param_1 + 0x248) = uVar2;
  *(undefined4 *)(param_1 + 0x24c) = uVar3;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x250) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 600) = uVar1;
  puVar6 = (undefined4 *)(**(code **)(*param_2 + 0x100))(param_2,local_28);
  uVar5 = puVar6[1];
  uVar2 = puVar6[2];
  uVar3 = puVar6[3];
  *(undefined4 *)(param_1 + 0x260) = *puVar6;
  *(undefined4 *)(param_1 + 0x264) = uVar5;
  *(undefined4 *)(param_1 + 0x268) = uVar2;
  *(undefined4 *)(param_1 + 0x26c) = uVar3;
  uVar5 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x270) = uVar5;
  uVar5 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x274) = uVar5;
  uVar5 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x278) = uVar5;
  uVar5 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x27c) = uVar5;
  uVar5 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x280) = uVar5;
  uVar5 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x284) = uVar5;
  puVar6 = (undefined4 *)(**(code **)(*param_2 + 0x120))(param_2,local_28);
  uVar5 = puVar6[1];
  uVar2 = puVar6[2];
  uVar3 = puVar6[3];
  *(undefined4 *)(param_1 + 0x288) = *puVar6;
  *(undefined4 *)(param_1 + 0x28c) = uVar5;
  *(undefined4 *)(param_1 + 0x290) = uVar2;
  *(undefined4 *)(param_1 + 0x294) = uVar3;
  *(undefined8 *)(param_1 + 0x298) = *(undefined8 *)(puVar6 + 4);
  puVar7 = (undefined8 *)(**(code **)(*param_2 + 0x120))(param_2,local_28);
  uVar1 = puVar7[1];
  *(undefined8 *)(param_1 + 0x2a0) = *puVar7;
  *(undefined8 *)(param_1 + 0x2a8) = uVar1;
  *(undefined8 *)(param_1 + 0x2b0) = puVar7[2];
  return 0;
}



/* ==== 1803af3e0 FUN_1803af3e0 ==== */

undefined8 FUN_1803af3e0(longlong param_1,longlong *param_2)

{
  undefined1 uVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  longlong lVar5;
  double *pdVar6;
  
  uVar3 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x220) = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x222) = uVar3;
  uVar4 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x224) = uVar4;
  uVar4 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x228) = uVar4;
  lVar5 = 0x100;
  pdVar6 = (double *)(param_1 + 0x238);
  do {
    uVar1 = (**(code **)(*param_2 + 0x98))(param_2);
    *(undefined1 *)(pdVar6 + -1) = uVar1;
    bVar2 = (**(code **)(*param_2 + 0x98))(param_2);
    *pdVar6 = (double)bVar2 / 255.0;
    lVar5 = lVar5 + -1;
    pdVar6 = pdVar6 + 2;
  } while (lVar5 != 0);
  uVar4 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x1230) = uVar4;
  return 0;
}



/* ==== 1803af4d0 FUN_1803af4d0 ==== */

undefined8 FUN_1803af4d0(longlong param_1,longlong *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  uint *puVar6;
  longlong lVar7;
  
  uVar4 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x220) = uVar4;
  uVar4 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x222) = uVar4;
  uVar5 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x224) = uVar5;
  uVar5 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x228) = uVar5;
  lVar7 = 0x20;
  puVar6 = (uint *)(param_1 + 0x234);
  do {
    bVar1 = (**(code **)(*param_2 + 0x98))(param_2);
    bVar2 = (**(code **)(*param_2 + 0x98))(param_2);
    bVar3 = (**(code **)(*param_2 + 0x98))(param_2);
    puVar6[-1] = (uint)bVar3 << 0x10 | (uint)bVar2 << 8 | (uint)bVar1;
    bVar1 = (**(code **)(*param_2 + 0x98))(param_2);
    bVar2 = (**(code **)(*param_2 + 0x98))(param_2);
    bVar3 = (**(code **)(*param_2 + 0x98))(param_2);
    *puVar6 = (uint)bVar3 << 0x10 | (uint)bVar2 << 8 | (uint)bVar1;
    bVar1 = (**(code **)(*param_2 + 0x98))(param_2);
    *(double *)(puVar6 + 1) = (double)bVar1 / 255.0;
    lVar7 = lVar7 + -1;
    puVar6 = puVar6 + 4;
  } while (lVar7 != 0);
  uVar5 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x430) = uVar5;
  return 0;
}



/* ==== 1803af630 FUN_1803af630 ==== */

undefined8 FUN_1803af630(longlong param_1,longlong *param_2)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  
  uVar5 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x220) = uVar5;
  uVar5 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x222) = uVar5;
  uVar6 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x224) = uVar6;
  uVar6 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x228) = uVar6;
  uVar1 = (**(code **)(*param_2 + 0x98))(param_2);
  *(undefined1 *)(param_1 + 0x22c) = uVar1;
  uVar1 = (**(code **)(*param_2 + 0x98))(param_2);
  *(undefined1 *)(param_1 + 0x22d) = uVar1;
  bVar2 = (**(code **)(*param_2 + 0x98))(param_2);
  bVar3 = (**(code **)(*param_2 + 0x98))(param_2);
  bVar4 = (**(code **)(*param_2 + 0x98))(param_2);
  *(uint *)(param_1 + 0x230) = (uint)bVar4 << 0x10 | (uint)bVar3 << 8 | (uint)bVar2;
  bVar2 = (**(code **)(*param_2 + 0x98))(param_2);
  bVar3 = (**(code **)(*param_2 + 0x98))(param_2);
  bVar4 = (**(code **)(*param_2 + 0x98))(param_2);
  *(uint *)(param_1 + 0x234) = (uint)bVar4 << 0x10 | (uint)bVar3 << 8 | (uint)bVar2;
  bVar2 = (**(code **)(*param_2 + 0x98))(param_2);
  bVar3 = (**(code **)(*param_2 + 0x98))(param_2);
  bVar4 = (**(code **)(*param_2 + 0x98))(param_2);
  *(uint *)(param_1 + 0x238) = (uint)bVar4 << 0x10 | (uint)bVar3 << 8 | (uint)bVar2;
  bVar2 = (**(code **)(*param_2 + 0x98))(param_2);
  bVar3 = (**(code **)(*param_2 + 0x98))(param_2);
  bVar4 = (**(code **)(*param_2 + 0x98))(param_2);
  *(uint *)(param_1 + 0x23c) = (uint)bVar4 << 0x10 | (uint)bVar3 << 8 | (uint)bVar2;
  uVar1 = (**(code **)(*param_2 + 0x98))(param_2);
  *(undefined1 *)(param_1 + 0x240) = uVar1;
  uVar1 = (**(code **)(*param_2 + 0x98))(param_2);
  *(undefined1 *)(param_1 + 0x241) = uVar1;
  uVar6 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x244) = uVar6;
  uVar7 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x248) = uVar7;
  uVar7 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x250) = uVar7;
  uVar7 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 600) = uVar7;
  uVar7 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x260) = uVar7;
  return 0;
}



/* ==== 1803af850 FUN_1803af850 ==== */

undefined8 FUN_1803af850(longlong param_1,longlong *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x220) = uVar1;
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x222) = uVar1;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x224) = uVar2;
  (**(code **)(*param_2 + 0x88))(param_2);
  (**(code **)(*param_2 + 0x80))(param_2);
  FUN_1800150c0(param_1 + 0x228);
  uVar2 = *(undefined4 *)(*(longlong *)(param_1 + 0x228) + -4);
  FUN_18000d0b0(param_1 + 0x228);
  lVar3 = 0;
  if (*(int *)(*(longlong *)(param_1 + 0x228) + -4) != 0) {
    lVar3 = *(longlong *)(param_1 + 0x228);
  }
  (**(code **)(*param_2 + 0x90))(param_2,lVar3,uVar2);
  return 0;
}



