/* ==== 1808c5150 FUN_1808c5150 ==== */

void FUN_1808c5150(undefined4 *param_1,longlong *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *param_1 = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  param_1[1] = uVar2;
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 2) = uVar1;
  uVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)((longlong)param_1 + 10) = uVar1;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  param_1[3] = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  param_1[4] = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  param_1[5] = uVar2;
  uVar3 = (**(code **)(*param_2 + 0xb8))(param_2);
  *(undefined8 *)(param_1 + 6) = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xb8))(param_2);
  *(undefined8 *)(param_1 + 8) = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xb8))(param_2);
  *(undefined8 *)(param_1 + 10) = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xb8))(param_2);
  *(undefined8 *)(param_1 + 0xc) = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xb8))(param_2);
  *(undefined8 *)(param_1 + 0xe) = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xb8))(param_2);
  *(undefined8 *)(param_1 + 0x10) = uVar3;
  *(undefined1 *)(param_1 + 0x12) = 0;
  return;
}



/* ==== 1808c5240 FUN_1808c5240 ==== */

void FUN_1808c5240(undefined4 *param_1,longlong *param_2)

{
  short sVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  
  uVar3 = (**(code **)(*param_2 + 0xb0))(param_2);
  *param_1 = uVar3;
  sVar1 = (**(code **)(*param_2 + 0xa8))(param_2);
  param_1[1] = (int)sVar1;
  uVar2 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 2) = uVar2;
  uVar3 = (**(code **)(*param_2 + 0xb0))(param_2);
  param_1[3] = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xb0))(param_2);
  param_1[4] = uVar3;
  uVar3 = (**(code **)(*param_2 + 0xb0))(param_2);
  param_1[5] = uVar3;
  uVar4 = (**(code **)(*param_2 + 0xb8))(param_2);
  *(undefined8 *)(param_1 + 6) = uVar4;
  uVar4 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 8) = uVar4;
  return;
}



/* ==== 1809d83c0 FUN_1809d83c0 ==== */

undefined8 * FUN_1809d83c0(undefined8 *param_1,OdString *param_2)

{
  code *pcVar1;
  
  *param_1 = OdRxObjectImpl<OdDgBlock,OdDgBlock>::vftable;
  *(undefined4 *)(param_1 + 1) = 0xffffffff;
  *(undefined4 *)(param_1 + 1) = 0;
  LOCK();
  *(undefined4 *)(param_1 + 1) = 1;
  UNLOCK();
  *param_1 = OdDgBaseBlock::vftable;
  pcVar1 = g_empty_array_buffer_exref;
  param_1[2] = g_empty_array_buffer_exref + 0x10;
  LOCK();
  *(int *)pcVar1 = *(int *)pcVar1 + 1;
  pcVar1 = g_empty_array_buffer_exref;
  UNLOCK();
  param_1[3] = g_empty_array_buffer_exref + 0x10;
  LOCK();
  *(int *)pcVar1 = *(int *)pcVar1 + 1;
  UNLOCK();
  OdString::OdString((OdString *)(param_1 + 4),param_2);
  return param_1;
}



/* ==== 1809ebdc0 FUN_1809ebdc0 ==== */

undefined8 FUN_1809ebdc0(undefined8 param_1,OdString *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  undefined8 local_res8;
  
  bVar1 = false;
  local_res8 = 0;
  if ((*(longlong *)(*(longlong *)param_2 + 0x10) == 0) &&
     (*(longlong *)(*(longlong *)param_2 + 0x18) != 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    OdString::syncUnicode(param_2);
  }
  uVar2 = openStructuredStorageEx(*(undefined8 *)(*(longlong *)param_2 + 0x10),0,&local_res8);
  FUN_1809eb400(uVar2,param_2);
  FUN_1809eb730(param_1,local_res8);
  return param_1;
}



