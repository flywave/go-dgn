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



