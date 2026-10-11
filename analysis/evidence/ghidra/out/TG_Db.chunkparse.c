/* ==== 1809d8c50 FUN_1809d8c50 ==== */

void FUN_1809d8c50(longlong *param_1,longlong *param_2,undefined1 param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong *plVar3;
  longlong *local_28;
  longlong *local_20;
  
  local_28 = (longlong *)*param_2;
  if (local_28 != (longlong *)0x0) {
    (**(code **)(*local_28 + 0x20))();
  }
  puVar2 = (undefined8 *)OdDgChunk::createFromStream(&local_20,&local_28,param_3);
  plVar1 = (longlong *)*puVar2;
  plVar3 = (longlong *)0x0;
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x20))();
    plVar3 = plVar1;
  }
  if (local_20 != (longlong *)0x0) {
    (**(code **)(*local_20 + 0x28))();
  }
  if (plVar3 != (longlong *)0x0) {
    local_28 = plVar3;
    (**(code **)(*plVar3 + 0x20))(plVar3);
    (**(code **)(*param_1 + 0xa0))(param_1,&local_28);
    (**(code **)(*plVar3 + 0x28))(plVar3);
  }
  if ((longlong *)*param_2 != (longlong *)0x0) {
    (**(code **)(*(longlong *)*param_2 + 0x28))();
    *param_2 = 0;
  }
  return;
}



