/* ==== 1802a37b0 FUN_1802a37b0 ==== */

void FUN_1802a37b0(longlong param_1,longlong *param_2)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined1 local_28 [32];
  
  puVar6 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_28);
  uVar5 = puVar6[1];
  uVar2 = puVar6[2];
  uVar3 = puVar6[3];
  *(undefined4 *)(param_1 + 8) = *puVar6;
  *(undefined4 *)(param_1 + 0xc) = uVar5;
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  *(undefined4 *)(param_1 + 0x14) = uVar3;
  *(undefined8 *)(param_1 + 0x18) = *(undefined8 *)(puVar6 + 4);
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x20) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x28) = uVar1;
  uVar4 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x30) = uVar4;
  uVar4 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x32) = uVar4;
  uVar5 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x34) = uVar5;
  return;
}



