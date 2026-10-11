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



