/* ==== 1801d7ae0 FUN_1801d7ae0 ==== */

undefined8 * FUN_1801d7ae0(longlong param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar1 = *(undefined8 *)(param_1 + 0x248);
  uVar2 = *(undefined8 *)(param_1 + 0x250);
  uVar3 = *(undefined8 *)(param_1 + 600);
  *param_2 = *(undefined8 *)(param_1 + 0x240);
  param_2[1] = uVar1;
  param_2[2] = uVar2;
  param_2[3] = uVar3;
  return param_2;
}



