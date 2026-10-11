/* ==== 1802ebb60 FUN_1802ebb60 ==== */

undefined8 FUN_1802ebb60(longlong param_1,longlong *param_2)

{
  int *piVar1;
  code *pcVar2;
  ulonglong uVar3;
  int iVar4;
  uint uVar5;
  void *_Src;
  longlong lVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  uint uVar13;
  longlong lVar14;
  uint uVar15;
  undefined8 uVar16;
  OdError local_res20 [8];
  OdError_InvalidIndex local_58 [24];
  
  iVar7 = (**(code **)(*param_2 + 0x88))(param_2);
  iVar8 = (**(code **)(*param_2 + 0x80))(param_2);
  FUN_180015300(param_1 + 0x220);
  uVar15 = 0;
  if ((uint)(iVar7 - iVar8) >> 3 != 0) {
    lVar14 = 0;
    do {
      if (*(uint *)(*(longlong *)(param_1 + 0x220) + -4) <= uVar15) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_58);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_58,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar1 = (int *)(*(longlong *)(param_1 + 0x220) + -0x10);
      iVar4 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar4) {
        _Src = *(void **)(param_1 + 0x220);
        uVar5 = *(uint *)((longlong)_Src + -0xc);
        pcVar2 = (code *)((longlong)_Src + -0x10);
        uVar13 = *(uint *)((longlong)_Src + -8);
        if ((int)uVar5 < 1) {
          uVar11 = (ulonglong)-(*(int *)((longlong)_Src + -4) * uVar5) / 100;
          uVar9 = *(int *)((longlong)_Src + -4) + (int)uVar11;
          uVar12 = (ulonglong)uVar9;
          if (uVar9 < uVar13) {
            uVar12 = (ulonglong)uVar13;
          }
        }
        else {
          uVar9 = (uVar13 - 1) + uVar5;
          uVar11 = (ulonglong)uVar9 % (ulonglong)uVar5;
          uVar12 = (ulonglong)((uVar9 / uVar5) * uVar5);
        }
        uVar3 = uVar12 * 8 + 0x10;
        if (uVar3 <= uVar12) {
LAB_1802ebd10:
          OdError::OdError(local_res20,9);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de52b8);
        }
        puVar10 = (undefined4 *)odrxAlloc(uVar3,uVar11);
        if (puVar10 == (undefined4 *)0x0) goto LAB_1802ebd10;
        *puVar10 = 0;
        LOCK();
        *puVar10 = 1;
        UNLOCK();
        puVar10[2] = (int)uVar12;
        puVar10[1] = uVar5;
        puVar10[3] = 0;
        if (*(uint *)((longlong)_Src + -4) < uVar13) {
          uVar13 = *(uint *)((longlong)_Src + -4);
        }
        memcpy(puVar10 + 4,_Src,(ulonglong)uVar13 << 3);
        puVar10[3] = uVar13;
        *(undefined4 **)(param_1 + 0x220) = puVar10 + 4;
        LOCK();
        iVar4 = *(int *)pcVar2;
        *(int *)pcVar2 = *(int *)pcVar2 + -1;
        UNLOCK();
        if ((iVar4 == 1) && (pcVar2 != g_empty_array_buffer_exref)) {
          odrxFree(pcVar2);
        }
      }
      lVar6 = *(longlong *)(param_1 + 0x220);
      uVar16 = (**(code **)(*param_2 + 200))();
      *(undefined8 *)(lVar6 + lVar14) = uVar16;
      uVar15 = uVar15 + 1;
      lVar14 = lVar14 + 8;
    } while (uVar15 < (uint)(iVar7 - iVar8) >> 3);
  }
  return 0;
}



/* ==== 1803b8690 FUN_1803b8690 ==== */

undefined8 FUN_1803b8690(longlong param_1,longlong *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar1 == 2) {
    FUN_1803bd750(param_1,param_2);
  }
  else {
    uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
    *(undefined4 *)(param_1 + 0x240) = uVar2;
    uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
    *(undefined4 *)(param_1 + 0x244) = uVar2;
    uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
    *(undefined4 *)(param_1 + 0x248) = uVar2;
  }
  *(undefined2 *)(param_1 + 0x2cb) = 1;
  *(undefined8 *)(param_1 + 0x2e0) = 0xbff0000000000000;
  return 0;
}



