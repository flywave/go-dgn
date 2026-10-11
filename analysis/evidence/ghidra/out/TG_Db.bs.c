/* ==== 1800a2e60 FUN_1800a2e60 ==== */

undefined8 FUN_1800a2e60(longlong param_1,longlong *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined8 uVar8;
  undefined8 uVar9;
  uint uVar10;
  undefined4 uVar11;
  undefined8 *puVar12;
  code *pcVar13;
  ulonglong uVar14;
  code *pcVar15;
  ulonglong uVar16;
  ulonglong *puVar17;
  undefined1 local_58 [16];
  undefined1 local_48 [48];
  
  uVar10 = (**(code **)(*param_2 + 0xb0))(param_2);
  uVar16 = (ulonglong)uVar10;
  uVar11 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x228) = uVar11;
  puVar17 = (ulonglong *)(param_1 + 0x220);
  FUN_1800b2ce0(puVar17,0);
  uVar5 = *(uint *)(*puVar17 - 8);
  if (uVar5 < uVar10) {
    if (uVar10 == 0) {
      pcVar15 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      pcVar13 = (code *)(*puVar17 - 0x10);
      LOCK();
      iVar3 = *(int *)pcVar13;
      *(int *)pcVar13 = *(int *)pcVar13 + -1;
      UNLOCK();
      if ((iVar3 == 1) && (pcVar13 != g_empty_array_buffer_exref)) {
        odrxFree();
      }
      *puVar17 = (ulonglong)pcVar15;
      pcVar13 = g_empty_array_buffer_exref;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      LOCK();
      iVar3 = *(int *)pcVar13;
      *(int *)pcVar13 = *(int *)pcVar13 + -1;
      UNLOCK();
      if (iVar3 != 1) {
        return 0;
      }
      if (pcVar13 == g_empty_array_buffer_exref) {
        return 0;
      }
      odrxFree();
      return 0;
    }
    if (uVar10 != uVar5) {
      LOCK();
      piVar1 = (int *)(*puVar17 - 0x10);
      iVar3 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      FUN_180037ef0(puVar17,uVar10,iVar3 < 2,1,1);
    }
  }
  if (uVar10 != 0) {
    do {
      (**(code **)(*param_2 + 0x100))(param_2,local_58);
      puVar12 = (undefined8 *)FUN_1808b5aa0(local_48,local_58);
      uVar5 = *(uint *)(*puVar17 - 4);
      LOCK();
      piVar1 = (int *)(*puVar17 - 0x10);
      iVar3 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if ((iVar3 < 2) && (uVar5 != *(uint *)(*puVar17 - 8))) {
LAB_1800a3077:
        uVar11 = *(undefined4 *)((longlong)puVar12 + 4);
        uVar6 = *(undefined4 *)(puVar12 + 1);
        uVar7 = *(undefined4 *)((longlong)puVar12 + 0xc);
        puVar2 = (undefined4 *)(*puVar17 + (ulonglong)uVar5 * 0x10);
        *puVar2 = *(undefined4 *)puVar12;
        puVar2[1] = uVar11;
        puVar2[2] = uVar6;
        puVar2[3] = uVar7;
      }
      else {
        if (*(int *)(*puVar17 - 4) != 0) {
          LOCK();
          piVar1 = (int *)(*puVar17 - 0x10);
          iVar4 = *piVar1;
          *piVar1 = *piVar1;
          UNLOCK();
          if (1 < iVar4) {
            FUN_180037ef0(puVar17,*(undefined4 *)(*puVar17 - 8),0,0,1);
          }
          if ((*(int *)((longlong)*puVar17 - 4) == 0) || ((undefined8 *)*puVar17 <= puVar12))
          goto LAB_1800a2fe9;
LAB_1800a305d:
          FUN_180037ef0(puVar17,uVar5 + 1,iVar3 < 2,0,1);
          goto LAB_1800a3077;
        }
LAB_1800a2fe9:
        if (*(int *)(*puVar17 - 4) == 0) goto LAB_1800a305d;
        LOCK();
        piVar1 = (int *)(*puVar17 - 0x10);
        iVar4 = *piVar1;
        *piVar1 = *piVar1;
        UNLOCK();
        if (1 < iVar4) {
          FUN_180037ef0(puVar17,*(undefined4 *)(*puVar17 - 8),0,0,1);
        }
        uVar10 = *(uint *)(*puVar17 - 4);
        uVar14 = 0;
        if (uVar10 != 0) {
          uVar14 = *puVar17;
        }
        if ((undefined8 *)((ulonglong)uVar10 * 0x10 + uVar14) <= puVar12) goto LAB_1800a305d;
        uVar8 = *puVar12;
        uVar9 = puVar12[1];
        FUN_180037ef0(puVar17,uVar5 + 1,iVar3 < 2,0,1);
        puVar12 = (undefined8 *)(*puVar17 + (ulonglong)uVar5 * 0x10);
        *puVar12 = uVar8;
        puVar12[1] = uVar9;
      }
      *(int *)(*puVar17 - 4) = *(int *)(*puVar17 - 4) + 1;
      uVar16 = uVar16 - 1;
    } while (uVar16 != 0);
  }
  return 0;
}



/* ==== 1800a30d0 FUN_1800a30d0 ==== */

undefined8 FUN_1800a30d0(longlong param_1,longlong *param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined8 uVar9;
  undefined8 uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined8 *puVar13;
  code *pcVar14;
  ulonglong uVar15;
  code *pcVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  ulonglong *puVar19;
  undefined1 local_58 [24];
  undefined1 local_40 [24];
  
  uVar11 = (**(code **)(*param_2 + 0xb0))(param_2);
  uVar17 = (ulonglong)uVar11;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x228) = uVar12;
  puVar19 = (ulonglong *)(param_1 + 0x220);
  FUN_1800b2dc0(puVar19,0);
  uVar6 = *(uint *)(*puVar19 - 8);
  if (uVar6 < uVar11) {
    if (uVar11 == 0) {
      pcVar16 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      pcVar14 = (code *)(*puVar19 - 0x10);
      LOCK();
      iVar3 = *(int *)pcVar14;
      *(int *)pcVar14 = *(int *)pcVar14 + -1;
      UNLOCK();
      if ((iVar3 == 1) && (pcVar14 != g_empty_array_buffer_exref)) {
        odrxFree();
      }
      *puVar19 = (ulonglong)pcVar16;
      pcVar14 = g_empty_array_buffer_exref;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      LOCK();
      iVar3 = *(int *)pcVar14;
      *(int *)pcVar14 = *(int *)pcVar14 + -1;
      UNLOCK();
      if (iVar3 != 1) {
        return 0;
      }
      if (pcVar14 == g_empty_array_buffer_exref) {
        return 0;
      }
      odrxFree();
      return 0;
    }
    if (uVar11 != uVar6) {
      LOCK();
      piVar1 = (int *)(*puVar19 - 0x10);
      iVar3 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      FUN_180038060(puVar19,uVar11,iVar3 < 2,1,1);
    }
  }
  if (uVar11 != 0) {
    do {
      (**(code **)(*param_2 + 0x110))(param_2,local_58);
      puVar13 = (undefined8 *)FUN_1808b5ae0(local_40,local_58);
      uVar6 = *(uint *)(*puVar19 - 4);
      uVar18 = (ulonglong)uVar6;
      LOCK();
      piVar1 = (int *)(*puVar19 - 0x10);
      iVar3 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if ((iVar3 < 2) && (uVar6 != *(uint *)(*puVar19 - 8))) {
LAB_1800a3310:
        uVar15 = *puVar19;
        uVar12 = *(undefined4 *)((longlong)puVar13 + 4);
        uVar7 = *(undefined4 *)(puVar13 + 1);
        uVar8 = *(undefined4 *)((longlong)puVar13 + 0xc);
        puVar2 = (undefined4 *)(uVar15 + uVar18 * 0x18);
        *puVar2 = *(undefined4 *)puVar13;
        puVar2[1] = uVar12;
        puVar2[2] = uVar7;
        puVar2[3] = uVar8;
        *(undefined8 *)(uVar15 + 0x10 + uVar18 * 0x18) = puVar13[2];
      }
      else {
        if (*(int *)(*puVar19 - 4) != 0) {
          LOCK();
          piVar1 = (int *)(*puVar19 - 0x10);
          iVar4 = *piVar1;
          *piVar1 = *piVar1;
          UNLOCK();
          if (1 < iVar4) {
            FUN_180038060(puVar19,*(undefined4 *)(*puVar19 - 8),0,0,1);
          }
          if ((*(int *)((longlong)*puVar19 - 4) == 0) || ((undefined8 *)*puVar19 <= puVar13))
          goto LAB_1800a3258;
LAB_1800a32f6:
          FUN_180038060(puVar19,uVar6 + 1,iVar3 < 2,0,1);
          goto LAB_1800a3310;
        }
LAB_1800a3258:
        if (*(int *)(*puVar19 - 4) == 0) goto LAB_1800a32f6;
        LOCK();
        piVar1 = (int *)(*puVar19 - 0x10);
        iVar4 = *piVar1;
        *piVar1 = *piVar1;
        UNLOCK();
        if (1 < iVar4) {
          FUN_180038060(puVar19,*(undefined4 *)(*puVar19 - 8),0,0,1);
        }
        uVar11 = *(uint *)(*puVar19 - 4);
        uVar15 = 0;
        if (uVar11 != 0) {
          uVar15 = *puVar19;
        }
        if ((undefined8 *)(uVar15 + (ulonglong)uVar11 * 0x18) <= puVar13) goto LAB_1800a32f6;
        uVar9 = *puVar13;
        uVar10 = puVar13[1];
        uVar5 = puVar13[2];
        FUN_180038060(puVar19,uVar6 + 1,iVar3 < 2,0,1);
        uVar15 = *puVar19;
        puVar13 = (undefined8 *)(uVar15 + uVar18 * 0x18);
        *puVar13 = uVar9;
        puVar13[1] = uVar10;
        *(undefined8 *)(uVar15 + 0x10 + uVar18 * 0x18) = uVar5;
      }
      *(int *)(*puVar19 - 4) = *(int *)(*puVar19 - 4) + 1;
      uVar17 = uVar17 - 1;
    } while (uVar17 != 0);
  }
  return 0;
}



/* ==== 1801db560 FUN_1801db560 ==== */

undefined8 FUN_1801db560(longlong param_1,longlong *param_2)

{
  int *piVar1;
  code *pcVar2;
  longlong *plVar3;
  int iVar4;
  uint uVar5;
  void *_Src;
  longlong lVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  ulonglong uVar16;
  uint uVar17;
  uint uVar18;
  longlong lVar19;
  OdError local_res20 [8];
  OdError_InvalidIndex local_68 [40];
  
  uVar9 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x220) = uVar9;
  uVar10 = (**(code **)(*param_2 + 0xb0))(param_2);
  plVar3 = (longlong *)(param_1 + 0x228);
  FUN_180192eb0(plVar3);
  uVar18 = 0;
  if (uVar10 != 0) {
    lVar19 = 0;
    do {
      if (*(uint *)(*plVar3 + -4) <= uVar18) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_68);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_68,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar1 = (int *)(*plVar3 + -0x10);
      iVar4 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar4) {
        _Src = (void *)*plVar3;
        uVar5 = *(uint *)((longlong)_Src + -0xc);
        pcVar2 = (code *)((longlong)_Src + -0x10);
        uVar17 = *(uint *)((longlong)_Src + -8);
        if ((int)uVar5 < 1) {
          uVar15 = (ulonglong)-(*(int *)((longlong)_Src + -4) * uVar5) / 100;
          uVar11 = *(int *)((longlong)_Src + -4) + (int)uVar15;
          uVar16 = (ulonglong)uVar11;
          if (uVar11 < uVar17) {
            uVar16 = (ulonglong)uVar17;
          }
        }
        else {
          uVar11 = (uVar17 - 1) + uVar5;
          uVar15 = (ulonglong)uVar11 % (ulonglong)uVar5;
          uVar16 = (ulonglong)((uVar11 / uVar5) * uVar5);
        }
        uVar14 = (uVar16 + 1) * 0x10;
        if (uVar14 <= uVar16) {
LAB_1801db702:
          OdError::OdError(local_res20,9);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de52b8);
        }
        puVar12 = (undefined4 *)odrxAlloc(uVar14,uVar15);
        if (puVar12 == (undefined4 *)0x0) goto LAB_1801db702;
        *puVar12 = 0;
        LOCK();
        *puVar12 = 1;
        UNLOCK();
        puVar12[2] = (int)uVar16;
        puVar12[1] = uVar5;
        puVar12[3] = 0;
        if (*(uint *)((longlong)_Src + -4) < uVar17) {
          uVar17 = *(uint *)((longlong)_Src + -4);
        }
        memcpy(puVar12 + 4,_Src,(ulonglong)uVar17 << 4);
        puVar12[3] = uVar17;
        *plVar3 = (longlong)(puVar12 + 4);
        LOCK();
        iVar4 = *(int *)pcVar2;
        *(int *)pcVar2 = *(int *)pcVar2 + -1;
        UNLOCK();
        if ((iVar4 == 1) && (pcVar2 != g_empty_array_buffer_exref)) {
          odrxFree(pcVar2);
        }
      }
      lVar6 = *plVar3;
      puVar13 = (undefined4 *)(**(code **)(*param_2 + 0x100))();
      uVar18 = uVar18 + 1;
      uVar9 = puVar13[1];
      uVar7 = puVar13[2];
      uVar8 = puVar13[3];
      puVar12 = (undefined4 *)(lVar6 + lVar19);
      *puVar12 = *puVar13;
      puVar12[1] = uVar9;
      puVar12[2] = uVar7;
      puVar12[3] = uVar8;
      lVar19 = lVar19 + 0x10;
    } while (uVar18 < uVar10);
  }
  return 0;
}



/* ==== 180280d10 FUN_180280d10 ==== */

undefined8 FUN_180280d10(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  ulonglong uVar4;
  uint uVar5;
  ulonglong uVar6;
  uint uVar7;
  undefined8 uVar8;
  OdError_InvalidIndex local_res8 [8];
  
  iVar2 = (**(code **)(*param_2 + 0x88))(param_2);
  iVar3 = (**(code **)(*param_2 + 0x80))(param_2);
  uVar7 = (uint)(iVar2 - iVar3) >> 3;
  FUN_180015300(param_1 + 0x220,uVar7);
  uVar4 = 0;
  uVar6 = uVar4;
  if ((uint)(iVar2 - iVar3) >> 3 != 0) {
    do {
      if (*(uint *)(*(longlong *)(param_1 + 0x220) + -4) <= (uint)uVar6) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_18000d1e0(param_1 + 0x220);
      lVar1 = *(longlong *)(param_1 + 0x220);
      uVar8 = (**(code **)(*param_2 + 200))(param_2);
      *(undefined8 *)(lVar1 + uVar4) = uVar8;
      uVar5 = (uint)uVar6 + 1;
      uVar4 = uVar4 + 8;
      uVar6 = (ulonglong)uVar5;
    } while (uVar5 < uVar7);
  }
  return 0;
}



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



/* ==== 1803e9bc0 FUN_1803e9bc0 ==== */

undefined8 FUN_1803e9bc0(longlong param_1,longlong *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar1 == 2) {
    FUN_1803ed520(param_1,param_2);
    return 0;
  }
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x260) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x264) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x268) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x26c) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x270) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x274) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x278) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x27c) = uVar2;
  uVar2 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x280) = uVar2;
  return 0;
}



