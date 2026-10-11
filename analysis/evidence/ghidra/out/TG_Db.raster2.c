/* ==== 1803f2c50 FUN_1803f2c50 ==== */

undefined8 FUN_1803f2c50(longlong param_1,longlong *param_2)

{
  undefined8 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined8 *puVar4;
  undefined1 local_28 [32];
  
  uVar3 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x240) = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x24a) = uVar3;
  uVar2 = (**(code **)(*param_2 + 0x98))(param_2);
  *(undefined1 *)(param_1 + 0x244) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0x98))(param_2);
  *(undefined1 *)(param_1 + 0x245) = uVar2;
  uVar3 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x246) = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x248) = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x24a) = uVar3;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x250) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 600) = uVar1;
  puVar4 = (undefined8 *)(**(code **)(*param_2 + 0x110))(param_2,local_28);
  uVar1 = puVar4[1];
  *(undefined8 *)(param_1 + 0x260) = *puVar4;
  *(undefined8 *)(param_1 + 0x268) = uVar1;
  *(undefined8 *)(param_1 + 0x270) = puVar4[2];
  return 0;
}



/* ==== 1803f2d70 FUN_1803f2d70 ==== */

void FUN_1803f2d70(longlong param_1,longlong *param_2)

{
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x240));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x242));
  (**(code **)(*param_2 + 0x148))(param_2,*(undefined1 *)(param_1 + 0x244));
  (**(code **)(*param_2 + 0x148))(param_2,*(undefined1 *)(param_1 + 0x245));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x246));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x248));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x24a));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x250));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 600));
                    /* WARNING: Could not recover jumptable at 0x0001803f2e44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x1a8))(param_2,param_1 + 0x260);
  return;
}



