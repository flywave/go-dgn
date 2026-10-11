/* ==== 1801707e0 FUN_1801707e0 ==== */

undefined8 FUN_1801707e0(longlong *param_1,longlong *param_2)

{
  int *piVar1;
  ulonglong *puVar2;
  int iVar3;
  byte bVar4;
  ushort uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 uVar10;
  undefined2 uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined8 *puVar14;
  undefined4 *puVar15;
  code *pcVar16;
  uint uVar17;
  undefined1 *puVar18;
  code *pcVar19;
  longlong lVar21;
  uint local_res10;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  undefined1 local_98 [8];
  OdError_InvalidIndex local_90 [8];
  undefined1 local_88 [8];
  OdError_InvalidIndex local_80 [8];
  OdError_InvalidIndex local_78 [8];
  undefined8 *local_70;
  undefined1 local_58 [32];
  undefined8 *puVar20;
  
  (**(code **)(*param_1 + 0x680))(param_1,local_res18);
  (**(code **)(*param_1 + 0x6a8))(param_1,local_res20,0);
  lVar21 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x44] = lVar21;
  lVar21 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x45] = lVar21;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x46) = uVar12;
  uVar11 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)((longlong)param_1 + 0x234) = uVar11;
  uVar10 = (**(code **)(*param_2 + 0xa0))(param_2);
  *(undefined1 *)((longlong)param_1 + 0x236) = uVar10;
  uVar10 = (**(code **)(*param_2 + 0xa0))(param_2);
  *(undefined1 *)((longlong)param_1 + 0x237) = uVar10;
  uVar10 = (**(code **)(*param_2 + 0xa0))(param_2);
  *(undefined1 *)(param_1 + 0x47) = uVar10;
  uVar10 = (**(code **)(*param_2 + 0xa0))(param_2);
  *(undefined1 *)((longlong)param_1 + 0x239) = uVar10;
  uVar11 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)((longlong)param_1 + 0x23a) = uVar11;
  puVar18 = (undefined1 *)((longlong)param_1 + 0x23c);
  lVar21 = 3;
  do {
    uVar10 = (**(code **)(*param_2 + 0x98))(param_2);
    *puVar18 = uVar10;
    puVar18 = puVar18 + 1;
    lVar21 = lVar21 + -1;
  } while (lVar21 != 0);
  uVar10 = (**(code **)(*param_2 + 0x98))(param_2);
  *(undefined1 *)((longlong)param_1 + 0x23f) = uVar10;
  lVar21 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x48] = lVar21;
  lVar21 = (**(code **)(*param_2 + 0xb8))(param_2);
  param_1[0x49] = lVar21;
  lVar21 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x4a] = lVar21;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x4b) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x25c) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x4c) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x264) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x4d) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x51) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x28c) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x52) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x294) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x53) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x57) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 700) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x58) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x2c4) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x59) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x5d) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x2ec) = uVar12;
  uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x5e) = uVar12;
  lVar21 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x5f] = lVar21;
  lVar21 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x60] = lVar21;
  lVar21 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x61] = lVar21;
  bVar4 = *(byte *)((longlong)param_1 + 0x237);
  puVar2 = (ulonglong *)(param_1 + 0x62);
  uVar17 = *(uint *)(*puVar2 - 8);
  if (uVar17 < bVar4) {
    if (bVar4 == 0) {
      pcVar19 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      pcVar16 = (code *)(*puVar2 - 0x10);
      LOCK();
      iVar13 = *(int *)pcVar16;
      *(int *)pcVar16 = *(int *)pcVar16 + -1;
      UNLOCK();
      if ((iVar13 == 1) && (pcVar16 != g_empty_array_buffer_exref)) {
        odrxFree();
      }
      *puVar2 = (ulonglong)pcVar19;
      pcVar16 = g_empty_array_buffer_exref;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      LOCK();
      iVar13 = *(int *)pcVar16;
      *(int *)pcVar16 = *(int *)pcVar16 + -1;
      UNLOCK();
      if ((iVar13 == 1) && (pcVar16 != g_empty_array_buffer_exref)) {
        odrxFree();
      }
    }
    else if (bVar4 != uVar17) {
      LOCK();
      piVar1 = (int *)(*puVar2 - 0x10);
      iVar13 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      FUN_18000cbd0(puVar2,bVar4,iVar13 < 2,1,1);
    }
  }
  puVar20 = (undefined8 *)0x0;
  local_res10 = 0;
  if (*(char *)((longlong)param_1 + 0x237) != '\0') {
    do {
      local_70 = (undefined8 *)FUN_18013c7c0(0x50);
      puVar14 = puVar20;
      if (local_70 != (undefined8 *)0x0) {
        local_70[1] = local_70 + 4;
        *local_70 = EMultiLineSegment::vftable;
        local_70[4] = 0;
        local_70[5] = 0;
        *(undefined2 *)(local_70 + 9) = 0;
        local_70[2] = 0;
        local_70[3] = 0;
        local_70[4] = 0;
        local_70[5] = 0;
        local_70[6] = 0;
        local_70[7] = 0;
        local_70[8] = 0;
        local_70[9] = 0;
        puVar14 = local_70;
      }
      uVar17 = *(uint *)(*puVar2 - 4);
      LOCK();
      piVar1 = (int *)(*puVar2 - 0x10);
      iVar13 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if ((1 < iVar13) || (uVar17 == *(uint *)(*puVar2 - 8))) {
        if (*(int *)(*puVar2 - 4) == 0) {
LAB_180170c61:
          if (*(int *)(*puVar2 - 4) != 0) {
            LOCK();
            piVar1 = (int *)(*puVar2 - 0x10);
            iVar3 = *piVar1;
            *piVar1 = *piVar1;
            UNLOCK();
            if (1 < iVar3) {
              FUN_18000cbd0(puVar2,*(undefined4 *)(*puVar2 - 8),0,0,1);
            }
          }
        }
        else {
          LOCK();
          piVar1 = (int *)(*puVar2 - 0x10);
          iVar3 = *piVar1;
          *piVar1 = *piVar1;
          UNLOCK();
          if (1 < iVar3) {
            FUN_18000cbd0(puVar2,*(undefined4 *)(*puVar2 - 8),0,0,1);
          }
          if ((*(int *)((undefined1 *)*puVar2 + -4) == 0) || ((undefined1 *)*puVar2 <= local_98))
          goto LAB_180170c61;
        }
        FUN_18000cbd0(puVar2,uVar17 + 1,iVar13 < 2,0,1);
      }
      *(undefined8 **)(*puVar2 + (ulonglong)uVar17 * 8) = puVar14;
      *(int *)(*puVar2 - 4) = *(int *)(*puVar2 - 4) + 1;
      uVar6 = *(uint *)(*puVar2 - 4);
      uVar17 = uVar6 - 1;
      if (uVar6 <= uVar17) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_90);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_90,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar1 = (int *)(*puVar2 - 0x10);
      iVar13 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar13) {
        FUN_18000cbd0(puVar2,*(undefined4 *)(*puVar2 - 8),0,0,1);
      }
      puVar14 = puVar20;
      if (*(int *)((longlong)*puVar2 - 4) != 0) {
        puVar14 = (undefined8 *)*puVar2;
      }
      lVar21 = puVar14[uVar17];
      uVar7 = (**(code **)(*param_2 + 200))(param_2);
      *(undefined8 *)(lVar21 + 0x10) = uVar7;
      uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
      *(undefined4 *)(lVar21 + 0x18) = uVar12;
      uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
      *(undefined4 *)(lVar21 + 0x20) = uVar12;
      uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
      *(undefined4 *)(lVar21 + 0x24) = uVar12;
      uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
      *(undefined4 *)(lVar21 + 0x28) = uVar12;
      uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
      *(undefined4 *)(lVar21 + 0x2c) = uVar12;
      uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
      *(undefined4 *)(lVar21 + 0x30) = uVar12;
      local_res10 = local_res10 + 1;
    } while (local_res10 < *(byte *)((longlong)param_1 + 0x237));
  }
  uVar5 = *(ushort *)((longlong)param_1 + 0x234);
  puVar2 = (ulonglong *)(param_1 + 99);
  uVar17 = *(uint *)(*puVar2 - 8);
  if (uVar17 < uVar5) {
    if (uVar5 == 0) {
      pcVar19 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      pcVar16 = (code *)(*puVar2 - 0x10);
      LOCK();
      iVar13 = *(int *)pcVar16;
      *(int *)pcVar16 = *(int *)pcVar16 + -1;
      UNLOCK();
      if ((iVar13 == 1) && (pcVar16 != g_empty_array_buffer_exref)) {
        odrxFree();
      }
      *puVar2 = (ulonglong)pcVar19;
      pcVar16 = g_empty_array_buffer_exref;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      LOCK();
      iVar13 = *(int *)pcVar16;
      *(int *)pcVar16 = *(int *)pcVar16 + -1;
      UNLOCK();
      if ((iVar13 == 1) && (pcVar16 != g_empty_array_buffer_exref)) {
        odrxFree();
      }
    }
    else if (uVar5 != uVar17) {
      LOCK();
      piVar1 = (int *)(*puVar2 - 0x10);
      iVar13 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      FUN_18000cbd0(puVar2,uVar5,iVar13 < 2,1,1);
    }
  }
  local_res10 = 0;
  if (*(short *)((longlong)param_1 + 0x234) != 0) {
    do {
      local_70 = (undefined8 *)FUN_18013c7c0(0x48);
      puVar14 = puVar20;
      if (local_70 != (undefined8 *)0x0) {
        puVar14 = (undefined8 *)FUN_18016b260(local_70);
      }
      uVar17 = *(uint *)(*puVar2 - 4);
      LOCK();
      piVar1 = (int *)(*puVar2 - 0x10);
      iVar13 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if ((1 < iVar13) || (uVar17 == *(uint *)(*puVar2 - 8))) {
        if (*(int *)(*puVar2 - 4) == 0) {
LAB_180170eed:
          if (*(int *)(*puVar2 - 4) != 0) {
            LOCK();
            piVar1 = (int *)(*puVar2 - 0x10);
            iVar3 = *piVar1;
            *piVar1 = *piVar1;
            UNLOCK();
            if (1 < iVar3) {
              FUN_18000cbd0(puVar2,*(undefined4 *)(*puVar2 - 8),0,0,1);
            }
          }
        }
        else {
          LOCK();
          piVar1 = (int *)(*puVar2 - 0x10);
          iVar3 = *piVar1;
          *piVar1 = *piVar1;
          UNLOCK();
          if (1 < iVar3) {
            FUN_18000cbd0(puVar2,*(undefined4 *)(*puVar2 - 8),0,0,1);
          }
          if ((*(int *)((undefined1 *)*puVar2 + -4) == 0) || ((undefined1 *)*puVar2 <= local_88))
          goto LAB_180170eed;
        }
        FUN_18000cbd0(puVar2,uVar17 + 1,iVar13 < 2,0,1);
      }
      *(undefined8 **)(*puVar2 + (ulonglong)uVar17 * 8) = puVar14;
      *(int *)(*puVar2 - 4) = *(int *)(*puVar2 - 4) + 1;
      uVar6 = *(uint *)(*puVar2 - 4);
      uVar17 = uVar6 - 1;
      if (uVar6 <= uVar17) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_80);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_80,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar1 = (int *)(*puVar2 - 0x10);
      iVar13 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar13) {
        FUN_18000cbd0(puVar2,*(undefined4 *)(*puVar2 - 8),0,0,1);
      }
      puVar14 = puVar20;
      if (*(int *)((longlong)*puVar2 - 4) != 0) {
        puVar14 = (undefined8 *)*puVar2;
      }
      lVar21 = puVar14[uVar17];
      puVar15 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_58);
      uVar12 = puVar15[1];
      uVar8 = puVar15[2];
      uVar9 = puVar15[3];
      *(undefined4 *)(lVar21 + 8) = *puVar15;
      *(undefined4 *)(lVar21 + 0xc) = uVar12;
      *(undefined4 *)(lVar21 + 0x10) = uVar8;
      *(undefined4 *)(lVar21 + 0x14) = uVar9;
      *(undefined8 *)(lVar21 + 0x18) = *(undefined8 *)(puVar15 + 4);
      uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
      *(undefined4 *)(lVar21 + 0x20) = uVar12;
      uVar11 = (**(code **)(*param_2 + 0xa8))(param_2);
      *(undefined2 *)(lVar21 + 0x24) = uVar11;
      uVar11 = (**(code **)(*param_2 + 0xa8))(param_2);
      *(undefined2 *)(lVar21 + 0x26) = uVar11;
      uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
      *(undefined4 *)(lVar21 + 0x28) = uVar12;
      uVar12 = (**(code **)(*param_2 + 0xb0))(param_2);
      *(undefined4 *)(lVar21 + 0x2c) = uVar12;
      local_res10 = local_res10 + 1;
    } while (local_res10 < *(ushort *)((longlong)param_1 + 0x234));
  }
  iVar13 = (**(code **)(*param_1 + 0x440))(param_1);
  if ((iVar13 == 0) && (*(short *)((longlong)param_1 + 0x234) != 0)) {
    do {
      if (*(uint *)(*puVar2 - 4) <= (uint)puVar20) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_78);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_78,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar1 = (int *)(*puVar2 - 0x10);
      iVar13 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar13) {
        FUN_18000cbd0(puVar2,*(undefined4 *)(*puVar2 - 8),0,0,1);
      }
      (**(code **)(**(longlong **)(*puVar2 + (longlong)puVar20 * 8) + 0x88))();
      uVar17 = (uint)puVar20 + 1;
      puVar20 = (undefined8 *)(ulonglong)uVar17;
    } while (uVar17 < *(ushort *)((longlong)param_1 + 0x234));
  }
  FUN_180174080(param_1,param_2,*(undefined1 *)((longlong)param_1 + 0x239));
  return 0;
}



