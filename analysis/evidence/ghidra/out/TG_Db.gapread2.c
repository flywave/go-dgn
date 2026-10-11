/* ==== 180185750 FUN_180185750 ==== */

undefined8 FUN_180185750(longlong *param_1,longlong *param_2)

{
  code *pcVar1;
  int *piVar2;
  ulonglong *puVar3;
  longlong *plVar4;
  int iVar5;
  longlong lVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 uVar9;
  char cVar10;
  short sVar11;
  int iVar12;
  undefined4 uVar13;
  uint uVar14;
  ulong uVar15;
  undefined4 *puVar16;
  code *pcVar17;
  undefined4 *puVar18;
  uint uVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  ulonglong uVar22;
  uint uVar23;
  ulong *puVar24;
  longlong lVar25;
  undefined4 local_res10 [2];
  undefined4 local_res18 [2];
  undefined4 local_res20 [2];
  code *local_198;
  code *local_190;
  code *local_188;
  code *local_180;
  code *local_178;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158 [2];
  code *local_150;
  code *local_148;
  code *local_140;
  code *local_138;
  code *local_130;
  OdError_InvalidIndex local_128 [8];
  OdError_InvalidIndex local_120 [8];
  OdError_InvalidIndex local_118 [8];
  OdError_InvalidIndex local_110 [8];
  OdError_InvalidIndex local_108 [8];
  OdError_InvalidIndex local_100 [8];
  OdError_InvalidIndex local_f8 [8];
  OdError_InvalidIndex local_f0 [8];
  OdError_InvalidIndex local_e8 [8];
  OdError_InvalidIndex local_e0 [8];
  undefined1 local_d8 [16];
  undefined1 local_c8 [24];
  undefined1 local_b0 [24];
  undefined1 local_98 [24];
  undefined1 local_80 [24];
  undefined1 local_68 [40];
  
  if ((param_2 == (longlong *)0x0) ||
     (iVar12 = (**(code **)(*param_2 + 0x58))(param_2), iVar12 != 2)) {
    uVar13 = (**(code **)(*param_2 + 0xb0))(param_2);
    *(undefined4 *)((longlong)param_1 + 0x244) = uVar13;
    iVar12 = (**(code **)(*param_2 + 0x58))(param_2);
    if (iVar12 != 2) {
      return 0;
    }
    goto LAB_180186d4d;
  }
  uVar13 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x244) = uVar13;
  puVar3 = (ulonglong *)(param_1 + 0x49);
  FUN_180183bd0(puVar3);
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    uVar22 = (ulonglong)uVar14;
    do {
      local_198 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
      if (uVar14 != 0) {
        uVar21 = (ulonglong)uVar14;
        pcVar17 = local_198;
        do {
          local_res10[0] = (**(code **)(*param_2 + 0xb0))(param_2);
          uVar14 = *(uint *)(pcVar17 + -4);
          LOCK();
          pcVar1 = pcVar17 + -0x10;
          iVar12 = *(int *)pcVar1;
          *(int *)pcVar1 = *(int *)pcVar1;
          UNLOCK();
          if ((iVar12 < 2) && (uVar14 != *(uint *)(local_198 + -8))) {
LAB_1801858e6:
            puVar18 = local_res10;
          }
          else {
            if (*(uint *)(pcVar17 + -4) == 0) {
LAB_1801858c5:
              FUN_18016ee30(&local_198,uVar14 + 1,iVar12 < 2,0,1);
              goto LAB_1801858e6;
            }
            FUN_18016f6d0(&local_198);
            if (((*(int *)(local_198 + -4) == 0) || (local_res10 < local_198)) ||
               (*(int *)(local_198 + -4) == 0)) goto LAB_1801858c5;
            FUN_18016f6d0();
            pcVar17 = (code *)0x0;
            if (*(uint *)(local_198 + -4) != 0) {
              pcVar17 = local_198;
            }
            if (pcVar17 + (ulonglong)*(uint *)(local_198 + -4) * 4 <= local_res10)
            goto LAB_1801858c5;
            local_168 = local_res10[0];
            FUN_18016ee30(&local_198,uVar14 + 1,iVar12 < 2,0,1);
            puVar18 = &local_168;
          }
          pcVar17 = local_198;
          memmove(local_198 + (ulonglong)uVar14 * 4,puVar18,4);
          *(int *)(pcVar17 + -4) = *(int *)(pcVar17 + -4) + 1;
          uVar21 = uVar21 - 1;
        } while (uVar21 != 0);
      }
      uVar14 = *(uint *)(*puVar3 - 4);
      LOCK();
      piVar2 = (int *)(*puVar3 - 0x10);
      iVar12 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if ((iVar12 < 2) && (uVar14 != *(uint *)(*puVar3 - 8))) {
LAB_180185a4a:
        *(code **)(*puVar3 + (ulonglong)uVar14 * 8) = local_198;
        pcVar17 = local_198 + -0x10;
        LOCK();
        *(int *)pcVar17 = *(int *)pcVar17 + 1;
        UNLOCK();
      }
      else {
        if (*(int *)(*puVar3 - 4) != 0) {
          LOCK();
          piVar2 = (int *)(*puVar3 - 0x10);
          iVar5 = *piVar2;
          *piVar2 = *piVar2;
          UNLOCK();
          if (1 < iVar5) {
            FUN_1801853e0(puVar3,*(undefined4 *)(*puVar3 - 8),0,0,1);
          }
          if ((*(int *)((longlong)*puVar3 - 4) == 0) || ((code **)*puVar3 <= &local_198))
          goto LAB_180185973;
LAB_180185a30:
          FUN_1801853e0(puVar3,uVar14 + 1,iVar12 < 2,0,1);
          goto LAB_180185a4a;
        }
LAB_180185973:
        if (*(int *)(*puVar3 - 4) == 0) goto LAB_180185a30;
        LOCK();
        piVar2 = (int *)(*puVar3 - 0x10);
        iVar5 = *piVar2;
        *piVar2 = *piVar2;
        UNLOCK();
        if (1 < iVar5) {
          FUN_1801853e0(puVar3,*(undefined4 *)(*puVar3 - 8),0,0,1);
        }
        uVar23 = *(uint *)(*puVar3 - 4);
        uVar21 = 0;
        if (uVar23 != 0) {
          uVar21 = *puVar3;
        }
        if ((code **)(uVar21 + (ulonglong)uVar23 * 8) <= &local_198) goto LAB_180185a30;
        local_150 = local_198;
        pcVar17 = local_198 + -0x10;
        LOCK();
        *(int *)pcVar17 = *(int *)pcVar17 + 1;
        UNLOCK();
        FUN_1801853e0(puVar3,uVar14 + 1,iVar12 < 2,0,1);
        *(code **)(*puVar3 + (ulonglong)uVar14 * 8) = local_198;
        pcVar1 = g_empty_array_buffer_exref;
        local_150 = g_empty_array_buffer_exref + 0x10;
        LOCK();
        *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
        UNLOCK();
        LOCK();
        iVar12 = *(int *)pcVar1;
        *(int *)pcVar1 = *(int *)pcVar1 + -1;
        UNLOCK();
        if ((iVar12 == 1) && (pcVar1 != g_empty_array_buffer_exref)) {
          odrxFree();
        }
      }
      *(int *)(*puVar3 - 4) = *(int *)(*puVar3 - 4) + 1;
      LOCK();
      iVar12 = *(int *)pcVar17;
      *(int *)pcVar17 = *(int *)pcVar17 + -1;
      UNLOCK();
      if ((iVar12 == 1) && (pcVar17 != g_empty_array_buffer_exref)) {
        odrxFree(pcVar17);
      }
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
  }
  puVar3 = (ulonglong *)(param_1 + 0x4a);
  FUN_180183bd0(puVar3);
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    uVar22 = (ulonglong)uVar14;
    do {
      local_190 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
      if (uVar14 != 0) {
        uVar21 = (ulonglong)uVar14;
        pcVar17 = local_190;
        do {
          local_res18[0] = (**(code **)(*param_2 + 0xb0))(param_2);
          uVar14 = *(uint *)(pcVar17 + -4);
          LOCK();
          pcVar1 = pcVar17 + -0x10;
          iVar12 = *(int *)pcVar1;
          *(int *)pcVar1 = *(int *)pcVar1;
          UNLOCK();
          if ((iVar12 < 2) && (uVar14 != *(uint *)(local_190 + -8))) {
LAB_180185bd6:
            puVar18 = local_res18;
          }
          else {
            if (*(uint *)(pcVar17 + -4) == 0) {
LAB_180185bb5:
              FUN_18016ee30(&local_190,uVar14 + 1,iVar12 < 2,0,1);
              goto LAB_180185bd6;
            }
            FUN_18016f6d0(&local_190);
            if (((*(int *)(local_190 + -4) == 0) || (local_res18 < local_190)) ||
               (*(int *)(local_190 + -4) == 0)) goto LAB_180185bb5;
            FUN_18016f6d0();
            pcVar17 = (code *)0x0;
            if (*(uint *)(local_190 + -4) != 0) {
              pcVar17 = local_190;
            }
            if (pcVar17 + (ulonglong)*(uint *)(local_190 + -4) * 4 <= local_res18)
            goto LAB_180185bb5;
            local_164 = local_res18[0];
            FUN_18016ee30(&local_190,uVar14 + 1,iVar12 < 2,0,1);
            puVar18 = &local_164;
          }
          pcVar17 = local_190;
          memmove(local_190 + (ulonglong)uVar14 * 4,puVar18,4);
          *(int *)(pcVar17 + -4) = *(int *)(pcVar17 + -4) + 1;
          uVar21 = uVar21 - 1;
        } while (uVar21 != 0);
      }
      uVar14 = *(uint *)(*puVar3 - 4);
      LOCK();
      piVar2 = (int *)(*puVar3 - 0x10);
      iVar12 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if ((iVar12 < 2) && (uVar14 != *(uint *)(*puVar3 - 8))) {
LAB_180185d38:
        *(code **)(*puVar3 + (ulonglong)uVar14 * 8) = local_190;
        pcVar17 = local_190 + -0x10;
        LOCK();
        *(int *)pcVar17 = *(int *)pcVar17 + 1;
        UNLOCK();
      }
      else {
        if (*(int *)(*puVar3 - 4) != 0) {
          LOCK();
          piVar2 = (int *)(*puVar3 - 0x10);
          iVar5 = *piVar2;
          *piVar2 = *piVar2;
          UNLOCK();
          if (1 < iVar5) {
            FUN_1801853e0(puVar3,*(undefined4 *)(*puVar3 - 8),0,0,1);
          }
          if ((*(int *)((longlong)*puVar3 - 4) == 0) || ((code **)*puVar3 <= &local_190))
          goto LAB_180185c63;
LAB_180185d1e:
          FUN_1801853e0(puVar3,uVar14 + 1,iVar12 < 2,0,1);
          goto LAB_180185d38;
        }
LAB_180185c63:
        if (*(int *)(*puVar3 - 4) == 0) goto LAB_180185d1e;
        LOCK();
        piVar2 = (int *)(*puVar3 - 0x10);
        iVar5 = *piVar2;
        *piVar2 = *piVar2;
        UNLOCK();
        if (1 < iVar5) {
          FUN_1801853e0(puVar3,*(undefined4 *)(*puVar3 - 8),0,0,1);
        }
        uVar23 = *(uint *)(*puVar3 - 4);
        uVar21 = 0;
        if (uVar23 != 0) {
          uVar21 = *puVar3;
        }
        if ((code **)(uVar21 + (ulonglong)uVar23 * 8) <= &local_190) goto LAB_180185d1e;
        local_148 = local_190;
        pcVar17 = local_190 + -0x10;
        LOCK();
        *(int *)pcVar17 = *(int *)pcVar17 + 1;
        UNLOCK();
        FUN_1801853e0(puVar3,uVar14 + 1,iVar12 < 2,0,1);
        *(code **)(*puVar3 + (ulonglong)uVar14 * 8) = local_190;
        pcVar1 = g_empty_array_buffer_exref;
        local_148 = g_empty_array_buffer_exref + 0x10;
        LOCK();
        *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
        UNLOCK();
        LOCK();
        iVar12 = *(int *)pcVar1;
        *(int *)pcVar1 = *(int *)pcVar1 + -1;
        UNLOCK();
        if ((iVar12 == 1) && (pcVar1 != g_empty_array_buffer_exref)) {
          odrxFree();
        }
      }
      *(int *)(*puVar3 - 4) = *(int *)(*puVar3 - 4) + 1;
      LOCK();
      iVar12 = *(int *)pcVar17;
      *(int *)pcVar17 = *(int *)pcVar17 + -1;
      UNLOCK();
      if ((iVar12 == 1) && (pcVar17 != g_empty_array_buffer_exref)) {
        odrxFree(pcVar17);
      }
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
  }
  puVar3 = (ulonglong *)(param_1 + 0x4b);
  FUN_180183bd0(puVar3);
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    uVar22 = (ulonglong)uVar14;
    do {
      local_188 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
      if (uVar14 != 0) {
        uVar21 = (ulonglong)uVar14;
        pcVar17 = local_188;
        do {
          local_res20[0] = (**(code **)(*param_2 + 0xb0))(param_2);
          uVar14 = *(uint *)(pcVar17 + -4);
          LOCK();
          pcVar1 = pcVar17 + -0x10;
          iVar12 = *(int *)pcVar1;
          *(int *)pcVar1 = *(int *)pcVar1;
          UNLOCK();
          if ((iVar12 < 2) && (uVar14 != *(uint *)(local_188 + -8))) {
LAB_180185ec6:
            puVar18 = local_res20;
          }
          else {
            if (*(uint *)(pcVar17 + -4) == 0) {
LAB_180185ea5:
              FUN_18016ee30(&local_188,uVar14 + 1,iVar12 < 2,0,1);
              goto LAB_180185ec6;
            }
            FUN_18016f6d0(&local_188);
            if (((*(int *)(local_188 + -4) == 0) || (local_res20 < local_188)) ||
               (*(int *)(local_188 + -4) == 0)) goto LAB_180185ea5;
            FUN_18016f6d0();
            pcVar17 = (code *)0x0;
            if (*(uint *)(local_188 + -4) != 0) {
              pcVar17 = local_188;
            }
            if (pcVar17 + (ulonglong)*(uint *)(local_188 + -4) * 4 <= local_res20)
            goto LAB_180185ea5;
            local_160 = local_res20[0];
            FUN_18016ee30(&local_188,uVar14 + 1,iVar12 < 2,0,1);
            puVar18 = &local_160;
          }
          pcVar17 = local_188;
          memmove(local_188 + (ulonglong)uVar14 * 4,puVar18,4);
          *(int *)(pcVar17 + -4) = *(int *)(pcVar17 + -4) + 1;
          uVar21 = uVar21 - 1;
        } while (uVar21 != 0);
      }
      uVar14 = *(uint *)(*puVar3 - 4);
      LOCK();
      piVar2 = (int *)(*puVar3 - 0x10);
      iVar12 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if ((iVar12 < 2) && (uVar14 != *(uint *)(*puVar3 - 8))) {
LAB_180186028:
        *(code **)(*puVar3 + (ulonglong)uVar14 * 8) = local_188;
        pcVar17 = local_188 + -0x10;
        LOCK();
        *(int *)pcVar17 = *(int *)pcVar17 + 1;
        UNLOCK();
      }
      else {
        if (*(int *)(*puVar3 - 4) != 0) {
          LOCK();
          piVar2 = (int *)(*puVar3 - 0x10);
          iVar5 = *piVar2;
          *piVar2 = *piVar2;
          UNLOCK();
          if (1 < iVar5) {
            FUN_1801853e0(puVar3,*(undefined4 *)(*puVar3 - 8),0,0,1);
          }
          if ((*(int *)((longlong)*puVar3 - 4) == 0) || ((code **)*puVar3 <= &local_188))
          goto LAB_180185f53;
LAB_18018600e:
          FUN_1801853e0(puVar3,uVar14 + 1,iVar12 < 2,0,1);
          goto LAB_180186028;
        }
LAB_180185f53:
        if (*(int *)(*puVar3 - 4) == 0) goto LAB_18018600e;
        LOCK();
        piVar2 = (int *)(*puVar3 - 0x10);
        iVar5 = *piVar2;
        *piVar2 = *piVar2;
        UNLOCK();
        if (1 < iVar5) {
          FUN_1801853e0(puVar3,*(undefined4 *)(*puVar3 - 8),0,0,1);
        }
        uVar23 = *(uint *)(*puVar3 - 4);
        uVar21 = 0;
        if (uVar23 != 0) {
          uVar21 = *puVar3;
        }
        if ((code **)(uVar21 + (ulonglong)uVar23 * 8) <= &local_188) goto LAB_18018600e;
        local_140 = local_188;
        pcVar17 = local_188 + -0x10;
        LOCK();
        *(int *)pcVar17 = *(int *)pcVar17 + 1;
        UNLOCK();
        FUN_1801853e0(puVar3,uVar14 + 1,iVar12 < 2,0,1);
        *(code **)(*puVar3 + (ulonglong)uVar14 * 8) = local_188;
        pcVar1 = g_empty_array_buffer_exref;
        local_140 = g_empty_array_buffer_exref + 0x10;
        LOCK();
        *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
        UNLOCK();
        LOCK();
        iVar12 = *(int *)pcVar1;
        *(int *)pcVar1 = *(int *)pcVar1 + -1;
        UNLOCK();
        if ((iVar12 == 1) && (pcVar1 != g_empty_array_buffer_exref)) {
          odrxFree();
        }
      }
      *(int *)(*puVar3 - 4) = *(int *)(*puVar3 - 4) + 1;
      LOCK();
      iVar12 = *(int *)pcVar17;
      *(int *)pcVar17 = *(int *)pcVar17 + -1;
      UNLOCK();
      if ((iVar12 == 1) && (pcVar17 != g_empty_array_buffer_exref)) {
        odrxFree(pcVar17);
      }
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
  }
  puVar3 = (ulonglong *)(param_1 + 0x4c);
  FUN_180183bd0(puVar3);
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    uVar22 = (ulonglong)uVar14;
    do {
      local_180 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
      if (uVar14 != 0) {
        uVar21 = (ulonglong)uVar14;
        pcVar17 = local_180;
        do {
          local_170 = (**(code **)(*param_2 + 0xb0))(param_2);
          uVar14 = *(uint *)(pcVar17 + -4);
          LOCK();
          pcVar1 = pcVar17 + -0x10;
          iVar12 = *(int *)pcVar1;
          *(int *)pcVar1 = *(int *)pcVar1;
          UNLOCK();
          if ((iVar12 < 2) && (uVar14 != *(uint *)(local_180 + -8))) {
LAB_1801861ae:
            puVar18 = &local_170;
          }
          else {
            if (*(uint *)(pcVar17 + -4) == 0) {
LAB_18018618d:
              FUN_18016ee30(&local_180,uVar14 + 1,iVar12 < 2,0,1);
              goto LAB_1801861ae;
            }
            FUN_18016f6d0(&local_180);
            if (((*(int *)(local_180 + -4) == 0) || (&local_170 < local_180)) ||
               (*(int *)(local_180 + -4) == 0)) goto LAB_18018618d;
            FUN_18016f6d0();
            pcVar17 = (code *)0x0;
            if (*(uint *)(local_180 + -4) != 0) {
              pcVar17 = local_180;
            }
            if (pcVar17 + (ulonglong)*(uint *)(local_180 + -4) * 4 <= &local_170)
            goto LAB_18018618d;
            local_15c = local_170;
            FUN_18016ee30(&local_180,uVar14 + 1,iVar12 < 2,0,1);
            puVar18 = &local_15c;
          }
          pcVar17 = local_180;
          memmove(local_180 + (ulonglong)uVar14 * 4,puVar18,4);
          *(int *)(pcVar17 + -4) = *(int *)(pcVar17 + -4) + 1;
          uVar21 = uVar21 - 1;
        } while (uVar21 != 0);
      }
      uVar14 = *(uint *)(*puVar3 - 4);
      LOCK();
      piVar2 = (int *)(*puVar3 - 0x10);
      iVar12 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if ((iVar12 < 2) && (uVar14 != *(uint *)(*puVar3 - 8))) {
LAB_18018630e:
        *(code **)(*puVar3 + (ulonglong)uVar14 * 8) = local_180;
        pcVar17 = local_180 + -0x10;
        LOCK();
        *(int *)pcVar17 = *(int *)pcVar17 + 1;
        UNLOCK();
      }
      else {
        if (*(int *)(*puVar3 - 4) != 0) {
          LOCK();
          piVar2 = (int *)(*puVar3 - 0x10);
          iVar5 = *piVar2;
          *piVar2 = *piVar2;
          UNLOCK();
          if (1 < iVar5) {
            FUN_1801853e0(puVar3,*(undefined4 *)(*puVar3 - 8),0,0,1);
          }
          if ((*(int *)((longlong)*puVar3 - 4) == 0) || ((code **)*puVar3 <= &local_180))
          goto LAB_180186239;
LAB_1801862f4:
          FUN_1801853e0(puVar3,uVar14 + 1,iVar12 < 2,0,1);
          goto LAB_18018630e;
        }
LAB_180186239:
        if (*(int *)(*puVar3 - 4) == 0) goto LAB_1801862f4;
        LOCK();
        piVar2 = (int *)(*puVar3 - 0x10);
        iVar5 = *piVar2;
        *piVar2 = *piVar2;
        UNLOCK();
        if (1 < iVar5) {
          FUN_1801853e0(puVar3,*(undefined4 *)(*puVar3 - 8),0,0,1);
        }
        uVar23 = *(uint *)(*puVar3 - 4);
        uVar21 = 0;
        if (uVar23 != 0) {
          uVar21 = *puVar3;
        }
        if ((code **)(uVar21 + (ulonglong)uVar23 * 8) <= &local_180) goto LAB_1801862f4;
        local_138 = local_180;
        pcVar17 = local_180 + -0x10;
        LOCK();
        *(int *)pcVar17 = *(int *)pcVar17 + 1;
        UNLOCK();
        FUN_1801853e0(puVar3,uVar14 + 1,iVar12 < 2,0,1);
        *(code **)(*puVar3 + (ulonglong)uVar14 * 8) = local_180;
        pcVar1 = g_empty_array_buffer_exref;
        local_138 = g_empty_array_buffer_exref + 0x10;
        LOCK();
        *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
        UNLOCK();
        LOCK();
        iVar12 = *(int *)pcVar1;
        *(int *)pcVar1 = *(int *)pcVar1 + -1;
        UNLOCK();
        if ((iVar12 == 1) && (pcVar1 != g_empty_array_buffer_exref)) {
          odrxFree();
        }
      }
      *(int *)(*puVar3 - 4) = *(int *)(*puVar3 - 4) + 1;
      LOCK();
      iVar12 = *(int *)pcVar17;
      *(int *)pcVar17 = *(int *)pcVar17 + -1;
      UNLOCK();
      if ((iVar12 == 1) && (pcVar17 != g_empty_array_buffer_exref)) {
        odrxFree(pcVar17);
      }
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
  }
  puVar3 = (ulonglong *)(param_1 + 0x4d);
  FUN_180183bd0(puVar3);
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    uVar22 = (ulonglong)uVar14;
    do {
      local_178 = g_empty_array_buffer_exref + 0x10;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
      if (uVar14 != 0) {
        uVar21 = (ulonglong)uVar14;
        pcVar17 = local_178;
        do {
          local_16c = (**(code **)(*param_2 + 0xb0))(param_2);
          uVar14 = *(uint *)(pcVar17 + -4);
          LOCK();
          pcVar1 = pcVar17 + -0x10;
          iVar12 = *(int *)pcVar1;
          *(int *)pcVar1 = *(int *)pcVar1;
          UNLOCK();
          if ((iVar12 < 2) && (uVar14 != *(uint *)(local_178 + -8))) {
LAB_18018648e:
            puVar18 = &local_16c;
          }
          else {
            if (*(uint *)(pcVar17 + -4) == 0) {
LAB_18018646d:
              FUN_18016ee30(&local_178,uVar14 + 1,iVar12 < 2,0,1);
              goto LAB_18018648e;
            }
            FUN_18016f6d0(&local_178);
            if (((*(int *)(local_178 + -4) == 0) || (&local_16c < local_178)) ||
               (*(int *)(local_178 + -4) == 0)) goto LAB_18018646d;
            FUN_18016f6d0();
            pcVar17 = (code *)0x0;
            if (*(uint *)(local_178 + -4) != 0) {
              pcVar17 = local_178;
            }
            if (pcVar17 + (ulonglong)*(uint *)(local_178 + -4) * 4 <= &local_16c)
            goto LAB_18018646d;
            local_158[0] = local_16c;
            FUN_18016ee30(&local_178,uVar14 + 1,iVar12 < 2,0,1);
            puVar18 = local_158;
          }
          pcVar17 = local_178;
          memmove(local_178 + (ulonglong)uVar14 * 4,puVar18,4);
          *(int *)(pcVar17 + -4) = *(int *)(pcVar17 + -4) + 1;
          uVar21 = uVar21 - 1;
        } while (uVar21 != 0);
      }
      uVar14 = *(uint *)(*puVar3 - 4);
      LOCK();
      piVar2 = (int *)(*puVar3 - 0x10);
      iVar12 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if ((iVar12 < 2) && (uVar14 != *(uint *)(*puVar3 - 8))) {
LAB_1801865ee:
        *(code **)(*puVar3 + (ulonglong)uVar14 * 8) = local_178;
        pcVar17 = local_178 + -0x10;
        LOCK();
        *(int *)pcVar17 = *(int *)pcVar17 + 1;
        UNLOCK();
      }
      else {
        if (*(int *)(*puVar3 - 4) != 0) {
          LOCK();
          piVar2 = (int *)(*puVar3 - 0x10);
          iVar5 = *piVar2;
          *piVar2 = *piVar2;
          UNLOCK();
          if (1 < iVar5) {
            FUN_1801853e0(puVar3,*(undefined4 *)(*puVar3 - 8),0,0,1);
          }
          if ((*(int *)((longlong)*puVar3 - 4) == 0) || ((code **)*puVar3 <= &local_178))
          goto LAB_180186519;
LAB_1801865d4:
          FUN_1801853e0(puVar3,uVar14 + 1,iVar12 < 2,0,1);
          goto LAB_1801865ee;
        }
LAB_180186519:
        if (*(int *)(*puVar3 - 4) == 0) goto LAB_1801865d4;
        LOCK();
        piVar2 = (int *)(*puVar3 - 0x10);
        iVar5 = *piVar2;
        *piVar2 = *piVar2;
        UNLOCK();
        if (1 < iVar5) {
          FUN_1801853e0(puVar3,*(undefined4 *)(*puVar3 - 8),0,0,1);
        }
        uVar23 = *(uint *)(*puVar3 - 4);
        uVar21 = 0;
        if (uVar23 != 0) {
          uVar21 = *puVar3;
        }
        if ((code **)(uVar21 + (ulonglong)uVar23 * 8) <= &local_178) goto LAB_1801865d4;
        local_130 = local_178;
        pcVar17 = local_178 + -0x10;
        LOCK();
        *(int *)pcVar17 = *(int *)pcVar17 + 1;
        UNLOCK();
        FUN_1801853e0(puVar3,uVar14 + 1,iVar12 < 2,0,1);
        *(code **)(*puVar3 + (ulonglong)uVar14 * 8) = local_178;
        pcVar1 = g_empty_array_buffer_exref;
        local_130 = g_empty_array_buffer_exref + 0x10;
        LOCK();
        *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
        UNLOCK();
        LOCK();
        iVar12 = *(int *)pcVar1;
        *(int *)pcVar1 = *(int *)pcVar1 + -1;
        UNLOCK();
        if ((iVar12 == 1) && (pcVar1 != g_empty_array_buffer_exref)) {
          odrxFree();
        }
      }
      *(int *)(*puVar3 - 4) = *(int *)(*puVar3 - 4) + 1;
      LOCK();
      iVar12 = *(int *)pcVar17;
      *(int *)pcVar17 = *(int *)pcVar17 + -1;
      UNLOCK();
      if ((iVar12 == 1) && (pcVar17 != g_empty_array_buffer_exref)) {
        odrxFree(pcVar17);
      }
      uVar22 = uVar22 - 1;
    } while (uVar22 != 0);
  }
  plVar4 = param_1 + 0x4e;
  FUN_180018080(plVar4);
  *(undefined4 *)(*plVar4 + -4) = 0;
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    FUN_180177de0(plVar4,uVar14);
  }
  uVar23 = 0;
  if (uVar14 != 0) {
    lVar25 = 0;
    do {
      if (*(uint *)(*plVar4 + -4) <= uVar23) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_128);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_128,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_180018080(plVar4);
      lVar6 = *plVar4;
      puVar16 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_c8);
      uVar13 = puVar16[1];
      uVar7 = puVar16[2];
      uVar8 = puVar16[3];
      puVar18 = (undefined4 *)(lVar6 + lVar25);
      *puVar18 = *puVar16;
      puVar18[1] = uVar13;
      puVar18[2] = uVar7;
      puVar18[3] = uVar8;
      *(undefined8 *)(lVar6 + 0x10 + lVar25) = *(undefined8 *)(puVar16 + 4);
      uVar23 = uVar23 + 1;
      lVar25 = lVar25 + 0x18;
    } while (uVar23 < uVar14);
  }
  plVar4 = param_1 + 0x4f;
  FUN_18016f6d0(plVar4);
  *(undefined4 *)(*plVar4 + -4) = 0;
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    FUN_1801928a0(plVar4,uVar14);
  }
  uVar23 = 0;
  if (uVar14 != 0) {
    lVar25 = 0;
    do {
      if (*(uint *)(*plVar4 + -4) <= uVar23) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_120);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_120,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_18016f6d0(plVar4);
      lVar6 = *plVar4;
      uVar13 = (**(code **)(*param_2 + 0xb0))(param_2);
      *(undefined4 *)(lVar6 + lVar25) = uVar13;
      uVar23 = uVar23 + 1;
      lVar25 = lVar25 + 4;
    } while (uVar23 < uVar14);
  }
  plVar4 = param_1 + 0x50;
  FUN_180018080(plVar4);
  *(undefined4 *)(*plVar4 + -4) = 0;
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    FUN_180177de0(plVar4,uVar14);
  }
  uVar23 = 0;
  if (uVar14 != 0) {
    lVar25 = 0;
    do {
      if (*(uint *)(*plVar4 + -4) <= uVar23) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_118);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_118,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_180018080(plVar4);
      lVar6 = *plVar4;
      puVar16 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_b0);
      uVar13 = puVar16[1];
      uVar7 = puVar16[2];
      uVar8 = puVar16[3];
      puVar18 = (undefined4 *)(lVar6 + lVar25);
      *puVar18 = *puVar16;
      puVar18[1] = uVar13;
      puVar18[2] = uVar7;
      puVar18[3] = uVar8;
      *(undefined8 *)(lVar6 + 0x10 + lVar25) = *(undefined8 *)(puVar16 + 4);
      uVar23 = uVar23 + 1;
      lVar25 = lVar25 + 0x18;
    } while (uVar23 < uVar14);
  }
  plVar4 = param_1 + 0x51;
  FUN_180185560(plVar4);
  *(undefined4 *)(*plVar4 + -4) = 0;
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    FUN_180177de0(plVar4,uVar14);
  }
  uVar23 = 0;
  if (uVar14 != 0) {
    lVar25 = 0;
    do {
      if (*(uint *)(*plVar4 + -4) <= uVar23) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_110);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_110,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_180185560(plVar4);
      lVar6 = *plVar4;
      puVar16 = (undefined4 *)(**(code **)(*param_2 + 0x120))(param_2,local_98);
      uVar13 = puVar16[1];
      uVar7 = puVar16[2];
      uVar8 = puVar16[3];
      puVar18 = (undefined4 *)(lVar6 + lVar25);
      *puVar18 = *puVar16;
      puVar18[1] = uVar13;
      puVar18[2] = uVar7;
      puVar18[3] = uVar8;
      *(undefined8 *)(lVar6 + 0x10 + lVar25) = *(undefined8 *)(puVar16 + 4);
      uVar23 = uVar23 + 1;
      lVar25 = lVar25 + 0x18;
    } while (uVar23 < uVar14);
  }
  plVar4 = param_1 + 0x52;
  FUN_180017f50(plVar4);
  *(undefined4 *)(*plVar4 + -4) = 0;
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    FUN_180192eb0(plVar4,uVar14);
  }
  uVar23 = 0;
  if (uVar14 != 0) {
    lVar25 = 0;
    do {
      if (*(uint *)(*plVar4 + -4) <= uVar23) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_108);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_108,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_180017f50(plVar4);
      lVar6 = *plVar4;
      puVar16 = (undefined4 *)(**(code **)(*param_2 + 0x100))(param_2,local_d8);
      uVar13 = puVar16[1];
      uVar7 = puVar16[2];
      uVar8 = puVar16[3];
      puVar18 = (undefined4 *)(lVar6 + lVar25);
      *puVar18 = *puVar16;
      puVar18[1] = uVar13;
      puVar18[2] = uVar7;
      puVar18[3] = uVar8;
      uVar23 = uVar23 + 1;
      lVar25 = lVar25 + 0x10;
    } while (uVar23 < uVar14);
  }
  plVar4 = param_1 + 0x53;
  FUN_180018080(plVar4);
  *(undefined4 *)(*plVar4 + -4) = 0;
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    FUN_180177de0(plVar4,uVar14);
  }
  uVar23 = 0;
  if (uVar14 != 0) {
    lVar25 = 0;
    do {
      if (*(uint *)(*plVar4 + -4) <= uVar23) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_100);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_100,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_180018080(plVar4);
      lVar6 = *plVar4;
      puVar16 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_80);
      uVar13 = puVar16[1];
      uVar7 = puVar16[2];
      uVar8 = puVar16[3];
      puVar18 = (undefined4 *)(lVar6 + lVar25);
      *puVar18 = *puVar16;
      puVar18[1] = uVar13;
      puVar18[2] = uVar7;
      puVar18[3] = uVar8;
      *(undefined8 *)(lVar6 + 0x10 + lVar25) = *(undefined8 *)(puVar16 + 4);
      uVar23 = uVar23 + 1;
      lVar25 = lVar25 + 0x18;
    } while (uVar23 < uVar14);
  }
  plVar4 = param_1 + 0x54;
  FUN_18016f6d0(plVar4);
  *(undefined4 *)(*plVar4 + -4) = 0;
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    FUN_1801928a0(plVar4,uVar14);
  }
  uVar23 = 0;
  if (uVar14 != 0) {
    lVar25 = 0;
    do {
      if (*(uint *)(*plVar4 + -4) <= uVar23) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_f8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_f8,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_18016f6d0(plVar4);
      lVar6 = *plVar4;
      uVar13 = (**(code **)(*param_2 + 0xb0))(param_2);
      *(undefined4 *)(lVar6 + lVar25) = uVar13;
      uVar23 = uVar23 + 1;
      lVar25 = lVar25 + 4;
    } while (uVar23 < uVar14);
  }
  plVar4 = param_1 + 0x55;
  FUN_180185560(plVar4);
  *(undefined4 *)(*plVar4 + -4) = 0;
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    FUN_180177de0(plVar4,uVar14);
  }
  uVar23 = 0;
  if (uVar14 != 0) {
    lVar25 = 0;
    do {
      if (*(uint *)(*plVar4 + -4) <= uVar23) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_f0);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_f0,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_180185560(plVar4);
      lVar6 = *plVar4;
      puVar16 = (undefined4 *)(**(code **)(*param_2 + 0x120))(param_2,local_68);
      uVar13 = puVar16[1];
      uVar7 = puVar16[2];
      uVar8 = puVar16[3];
      puVar18 = (undefined4 *)(lVar6 + lVar25);
      *puVar18 = *puVar16;
      puVar18[1] = uVar13;
      puVar18[2] = uVar7;
      puVar18[3] = uVar8;
      *(undefined8 *)(lVar6 + 0x10 + lVar25) = *(undefined8 *)(puVar16 + 4);
      uVar23 = uVar23 + 1;
      lVar25 = lVar25 + 0x18;
    } while (uVar23 < uVar14);
  }
  plVar4 = param_1 + 0x57;
  LOCK();
  piVar2 = (int *)(*plVar4 + -0x10);
  iVar12 = *piVar2;
  *piVar2 = *piVar2;
  UNLOCK();
  if (1 < iVar12) {
    FUN_1801151a0(plVar4,*(undefined4 *)(*plVar4 + -8),0,0,1);
  }
  *(undefined4 *)(*plVar4 + -4) = 0;
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    lVar25 = *plVar4;
    iVar12 = uVar14 - *(int *)(lVar25 + -4);
    if (iVar12 < 1) {
      if (iVar12 < 0) {
        LOCK();
        piVar2 = (int *)(lVar25 + -0x10);
        iVar12 = *piVar2;
        *piVar2 = *piVar2;
        UNLOCK();
        uVar23 = uVar14;
        if (1 < iVar12) goto LAB_180186aef;
      }
    }
    else {
      uVar23 = *(int *)(lVar25 + -4) + iVar12;
      LOCK();
      piVar2 = (int *)(lVar25 + -0x10);
      iVar12 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if (iVar12 < 2) {
        if (uVar23 <= *(uint *)(*plVar4 + -8)) goto LAB_180186b02;
        uVar20 = 1;
      }
      else {
LAB_180186aef:
        uVar20 = 0;
      }
      FUN_1801151a0(plVar4,uVar23,uVar20,0,1);
    }
LAB_180186b02:
    *(uint *)(*plVar4 + -4) = uVar14;
  }
  uVar22 = 0;
  if (uVar14 != 0) {
    do {
      if (*(uint *)(*plVar4 + -4) <= (uint)uVar22) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_e8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_e8,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar2 = (int *)(*plVar4 + -0x10);
      iVar12 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if (1 < iVar12) {
        FUN_1801151a0(plVar4,*(undefined4 *)(*plVar4 + -8),0,0,1);
      }
      lVar25 = *plVar4;
      uVar9 = (**(code **)(*param_2 + 0x98))(param_2);
      *(undefined1 *)(uVar22 + lVar25) = uVar9;
      uVar23 = (uint)uVar22 + 1;
      uVar22 = (ulonglong)uVar23;
    } while (uVar23 < uVar14);
  }
  plVar4 = param_1 + 0x58;
  LOCK();
  piVar2 = (int *)(*plVar4 + -0x10);
  iVar12 = *piVar2;
  *piVar2 = *piVar2;
  UNLOCK();
  if (1 < iVar12) {
    FUN_180017c50(plVar4,*(undefined4 *)(*plVar4 + -8),0,0,1);
  }
  *(undefined4 *)(*plVar4 + -4) = 0;
  uVar14 = (**(code **)(*param_2 + 0xb0))(param_2);
  if (uVar14 != 0) {
    lVar25 = *plVar4;
    uVar23 = *(uint *)(lVar25 + -4);
    uVar19 = uVar14 - uVar23;
    uVar22 = (ulonglong)uVar19;
    if ((int)uVar19 < 1) {
      if ((int)uVar19 < 0) {
        LOCK();
        piVar2 = (int *)(lVar25 + -0x10);
        iVar12 = *piVar2;
        *piVar2 = *piVar2;
        UNLOCK();
        if (1 < iVar12) {
          FUN_180017c50(plVar4,uVar14,0,0,1);
        }
      }
    }
    else {
      LOCK();
      piVar2 = (int *)(lVar25 + -0x10);
      iVar12 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if (iVar12 < 2) {
        if (*(uint *)(*plVar4 + -8) < uVar19 + uVar23) {
          uVar20 = 1;
          goto LAB_180186bdf;
        }
      }
      else {
        uVar20 = 0;
LAB_180186bdf:
        FUN_180017c50(plVar4,uVar19 + uVar23,uVar20,0,1);
      }
      if (uVar19 != 0) {
        puVar24 = (ulong *)(*plVar4 + (ulonglong)uVar23 * 4 + uVar22 * 4);
        do {
          puVar24 = puVar24 + -1;
          *puVar24 = 0;
          OdCmEntityColor::setColorMethod(puVar24,0xc2);
          uVar23 = (int)uVar22 - 1;
          uVar22 = (ulonglong)uVar23;
        } while (uVar23 != 0);
      }
    }
    *(uint *)(*plVar4 + -4) = uVar14;
  }
  uVar22 = 0;
  if (uVar14 != 0) {
    do {
      if (*(uint *)(*plVar4 + -4) <= (uint)uVar22) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_e0);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_e0,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar2 = (int *)(*plVar4 + -0x10);
      iVar12 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if (1 < iVar12) {
        FUN_180017c50(plVar4,*(undefined4 *)(*plVar4 + -8),0,0,1);
      }
      lVar25 = *plVar4;
      uVar15 = (**(code **)(*param_2 + 0xb0))(param_2);
      OdCmEntityColor::setColor((OdCmEntityColor *)(lVar25 + uVar22 * 4),uVar15);
      uVar23 = (uint)uVar22 + 1;
      uVar22 = (ulonglong)uVar23;
    } while (uVar23 < uVar14);
  }
  cVar10 = (**(code **)(*param_2 + 0x98))(param_2);
  *(bool *)(param_1 + 0x56) = '\0' < cVar10;
  cVar10 = (**(code **)(*param_2 + 0x98))(param_2);
  *(bool *)(param_1 + 0x59) = '\0' < cVar10;
  cVar10 = (**(code **)(*param_2 + 0x98))(param_2);
  *(bool *)((longlong)param_1 + 0x2c9) = '\0' < cVar10;
  cVar10 = (**(code **)(*param_2 + 0x98))(param_2);
  *(bool *)((longlong)param_1 + 0x2ca) = '\0' < cVar10;
  sVar11 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(bool *)((longlong)param_1 + 0x2cb) = 0 < sVar11;
  *(undefined1 *)((longlong)param_1 + 0x2cc) = 1;
LAB_180186d4d:
  (**(code **)(*param_1 + 0x690))(param_1);
  return 0;
}



/* ==== 180269260 FUN_180269260 ==== */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180269260(longlong param_1,longlong *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  longlong lVar9;
  OdDgDatabase *this;
  ulonglong uVar10;
  undefined8 uVar11;
  undefined1 auStack_108 [32];
  longlong local_e8;
  undefined8 local_e0;
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 local_a8;
  undefined8 uStack_a0;
  undefined8 local_98;
  undefined8 uStack_90;
  undefined8 local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  undefined8 local_68;
  undefined8 uStack_60;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  ulonglong local_28;
  
  local_28 = DAT_180fcd438 ^ (ulonglong)auStack_108;
  uVar4 = (**(code **)(*param_2 + 0x98))(param_2);
  *(undefined1 *)(param_1 + 0x268) = uVar4;
  uVar4 = (**(code **)(*param_2 + 0x98))(param_2);
  *(undefined1 *)(param_1 + 0x269) = uVar4;
  uVar5 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x26a) = uVar5;
  (**(code **)(*param_2 + 0x110))(param_2,&local_c0);
  (**(code **)(*param_2 + 0x110))(param_2,&local_d8);
  *(undefined8 *)(param_1 + 0x270) = local_c0;
  *(undefined8 *)(param_1 + 0x278) = uStack_b8;
  *(undefined8 *)(param_1 + 0x280) = local_b0;
  *(undefined8 *)(param_1 + 0x288) = local_d8;
  *(undefined8 *)(param_1 + 0x290) = uStack_d0;
  *(undefined8 *)(param_1 + 0x298) = local_c8;
  *(undefined1 *)(param_1 + 0x370) = 0;
  OdGeMatrix3d::OdGeMatrix3d((OdGeMatrix3d *)&local_a8);
  local_a8 = (**(code **)(*param_2 + 200))(param_2);
  uStack_a0 = (**(code **)(*param_2 + 200))(param_2);
  local_98 = (**(code **)(*param_2 + 200))(param_2);
  local_88 = (**(code **)(*param_2 + 200))(param_2);
  uStack_80 = (**(code **)(*param_2 + 200))(param_2);
  local_78 = (**(code **)(*param_2 + 200))(param_2);
  local_68 = (**(code **)(*param_2 + 200))(param_2);
  uStack_60 = (**(code **)(*param_2 + 200))(param_2);
  uVar11 = (**(code **)(*param_2 + 200))(param_2);
  *(undefined8 *)(param_1 + 0x2a0) = local_a8;
  *(undefined8 *)(param_1 + 0x2a8) = uStack_a0;
  *(undefined8 *)(param_1 + 0x2b0) = local_98;
  *(undefined8 *)(param_1 + 0x2b8) = uStack_90;
  *(undefined8 *)(param_1 + 0x2c0) = local_88;
  *(undefined8 *)(param_1 + 0x2c8) = uStack_80;
  *(undefined8 *)(param_1 + 0x2d0) = local_78;
  *(undefined8 *)(param_1 + 0x2d8) = uStack_70;
  *(undefined8 *)(param_1 + 0x2e0) = local_68;
  *(undefined8 *)(param_1 + 0x2e8) = uStack_60;
  *(undefined8 *)(param_1 + 0x2f0) = uVar11;
  *(undefined4 *)(param_1 + 0x2f8) = uStack_50;
  *(undefined4 *)(param_1 + 0x2fc) = uStack_4c;
  *(undefined4 *)(param_1 + 0x300) = local_48;
  *(undefined4 *)(param_1 + 0x304) = uStack_44;
  *(undefined4 *)(param_1 + 0x308) = uStack_40;
  *(undefined4 *)(param_1 + 0x30c) = uStack_3c;
  *(undefined4 *)(param_1 + 0x310) = local_38;
  *(undefined4 *)(param_1 + 0x314) = uStack_34;
  *(undefined4 *)(param_1 + 0x318) = uStack_30;
  *(undefined4 *)(param_1 + 0x31c) = uStack_2c;
  puVar8 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,&local_d8);
  uVar1 = puVar8[1];
  uVar2 = puVar8[2];
  uVar3 = puVar8[3];
  *(undefined4 *)(param_1 + 800) = *puVar8;
  *(undefined4 *)(param_1 + 0x324) = uVar1;
  *(undefined4 *)(param_1 + 0x328) = uVar2;
  *(undefined4 *)(param_1 + 0x32c) = uVar3;
  *(undefined8 *)(param_1 + 0x330) = *(undefined8 *)(puVar8 + 4);
  iVar6 = (**(code **)(*param_2 + 0x58))(param_2);
  if (((iVar6 == 2) && (iVar6 = (**(code **)(*param_2 + 0xb0))(param_2), iVar6 == 1)) &&
     (lVar9 = FUN_180010890(param_1), lVar9 != 0)) {
    uVar7 = (**(code **)(*param_2 + 0xb0))(param_2);
    uVar10 = (ulonglong)uVar7;
    FUN_18000d1e0(param_1 + 0x220);
    *(undefined4 *)(*(longlong *)(param_1 + 0x220) + -4) = 0;
    if (uVar7 != 0) {
      do {
        local_e0 = (**(code **)(*param_2 + 0xb8))(param_2);
        this = (OdDgDatabase *)FUN_180010890(param_1);
        OdDgDatabase::getElementId(this,(OdDbHandle *)&local_e8);
        if (local_e8 != 0) {
          FUN_180013b80(param_1 + 0x220,&local_e8);
        }
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
  }
  return 0;
}



