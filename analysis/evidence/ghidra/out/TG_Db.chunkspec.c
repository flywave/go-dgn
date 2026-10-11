/* ==== 1809e0ab0 FUN_1809e0ab0 ==== */

undefined8 * FUN_1809e0ab0(undefined8 *param_1,undefined8 param_2)

{
  code *pcVar1;
  undefined8 *puVar2;
  _func_void *p_Var3;
  undefined1 local_28 [32];
  
  puVar2 = (undefined8 *)odrxAlloc(0x48);
  if (puVar2 == (undefined8 *)0x0) {
    p_Var3 = std::get_new_handler();
    if (p_Var3 == (_func_void *)0x0) {
      FUN_1800044e0(local_28);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_28,(ThrowInfo *)&DAT_180de5280);
    }
    (*p_Var3)();
  }
  if (puVar2 != (undefined8 *)0x0) {
    FUN_1809e8020(puVar2,param_2,0x10);
    *puVar2 = OdDgElementChunk::vftable;
    pcVar1 = g_empty_array_buffer_exref;
    puVar2[7] = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)pcVar1 = *(int *)pcVar1 + 1;
    UNLOCK();
    *(undefined2 *)((longlong)puVar2 + 0x44) = 0;
  }
  *param_1 = puVar2;
  return param_1;
}



/* ==== 1809e8690 FUN_1809e8690 ==== */

undefined8 * FUN_1809e8690(undefined8 *param_1,undefined8 param_2,undefined4 param_3)

{
  undefined8 *puVar1;
  _func_void *p_Var2;
  undefined1 local_28 [32];
  
  puVar1 = (undefined8 *)odrxAlloc(0x38);
  if (puVar1 == (undefined8 *)0x0) {
    p_Var2 = std::get_new_handler();
    if (p_Var2 == (_func_void *)0x0) {
      FUN_1800044e0(local_28);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_28,(ThrowInfo *)&DAT_180de5280);
    }
    (*p_Var2)();
  }
  if (puVar1 != (undefined8 *)0x0) {
    FUN_1809e3b00(puVar1,param_2);
    *puVar1 = OdDgZipChunk::vftable;
    *(undefined4 *)(puVar1 + 6) = param_3;
  }
  *param_1 = puVar1;
  return param_1;
}



