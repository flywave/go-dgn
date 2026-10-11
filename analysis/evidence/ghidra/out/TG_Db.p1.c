/* ==== 180222180 FUN_180222180 ==== */

undefined8 FUN_180222180(longlong param_1,longlong *param_2)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined2 uVar5;
  undefined4 *puVar6;
  undefined1 local_28 [32];
  
  uVar5 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x220) = uVar5;
  uVar5 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x222) = uVar5;
  uVar5 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x224) = uVar5;
  uVar5 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x226) = uVar5;
  puVar6 = (undefined4 *)(**(code **)(*param_2 + 0x128))(param_2,local_28);
  uVar2 = puVar6[1];
  uVar3 = puVar6[2];
  uVar4 = puVar6[3];
  *(undefined4 *)(param_1 + 0x228) = *puVar6;
  *(undefined4 *)(param_1 + 0x22c) = uVar2;
  *(undefined4 *)(param_1 + 0x230) = uVar3;
  *(undefined4 *)(param_1 + 0x234) = uVar4;
  uVar2 = puVar6[5];
  uVar3 = puVar6[6];
  uVar4 = puVar6[7];
  *(undefined4 *)(param_1 + 0x238) = puVar6[4];
  *(undefined4 *)(param_1 + 0x23c) = uVar2;
  *(undefined4 *)(param_1 + 0x240) = uVar3;
  *(undefined4 *)(param_1 + 0x244) = uVar4;
  puVar6 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_28);
  uVar2 = puVar6[1];
  uVar3 = puVar6[2];
  uVar4 = puVar6[3];
  *(undefined4 *)(param_1 + 0x248) = *puVar6;
  *(undefined4 *)(param_1 + 0x24c) = uVar2;
  *(undefined4 *)(param_1 + 0x250) = uVar3;
  *(undefined4 *)(param_1 + 0x254) = uVar4;
  *(undefined8 *)(param_1 + 600) = *(undefined8 *)(puVar6 + 4);
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x260) = uVar1;
  puVar6 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_28);
  uVar2 = puVar6[1];
  uVar3 = puVar6[2];
  uVar4 = puVar6[3];
  *(undefined4 *)(param_1 + 0x268) = *puVar6;
  *(undefined4 *)(param_1 + 0x26c) = uVar2;
  *(undefined4 *)(param_1 + 0x270) = uVar3;
  *(undefined4 *)(param_1 + 0x274) = uVar4;
  *(undefined8 *)(param_1 + 0x278) = *(undefined8 *)(puVar6 + 4);
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x280) = uVar1;
  return 0;
}



/* ==== 1803b6380 FUN_1803b6380 ==== */

undefined8 FUN_1803b6380(longlong param_1,longlong *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x240) = uVar2;
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x244) = uVar1;
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x246) = uVar1;
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x248) = uVar1;
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x24a) = uVar1;
  return 0;
}



