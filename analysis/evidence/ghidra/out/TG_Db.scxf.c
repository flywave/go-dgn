/* ==== 1801f6e10 FUN_1801f6e10 ==== */

OdGeMatrix3d * FUN_1801f6e10(OdGeMatrix3d *param_1,longlong *param_2)

{
  undefined8 uVar1;
  
  OdGeMatrix3d::OdGeMatrix3d(param_1);
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)param_1 = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 8) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x10) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x20) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x28) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x30) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x40) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x48) = uVar1;
  uVar1 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x50) = uVar1;
  return param_1;
}



