/* ==== 180174080 FUN_180174080 ==== */

void FUN_180174080(longlong param_1,longlong *param_2,uint param_3)

{
  int *piVar1;
  code *pcVar2;
  longlong *plVar3;
  int iVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  code *pcVar9;
  undefined8 *puVar10;
  ulong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  undefined8 uVar17;
  Error local_res18 [8];
  code *local_res20;
  OdError_InvalidIndex local_70 [8];
  OdError_InvalidIndex local_68 [8];
  OdError_InvalidIndex local_60 [8];
  OdError_InvalidIndex local_58 [8];
  OdError_InvalidIndex local_50 [8];
  OdError_InvalidIndex local_48 [8];
  OdError_InvalidIndex local_40 [8];
  
  pcVar9 = g_empty_array_buffer_exref;
  if (param_3 == 0) {
    return;
  }
  local_res20 = g_empty_array_buffer_exref + 0x10;
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  uVar15 = *(uint *)(pcVar9 + 0xc);
  uVar14 = param_3 - uVar15;
  uVar13 = (ulonglong)uVar14;
  if ((int)uVar14 < 1) {
    if ((int)uVar14 < 0) {
      LOCK();
      iVar4 = *(int *)pcVar9;
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar9;
      UNLOCK();
      if (1 < iVar4) {
        FUN_18016f380(&local_res20,param_3,0,0,1);
      }
    }
    goto LAB_180174189;
  }
  LOCK();
  iVar4 = *(int *)pcVar9;
  *(undefined4 *)pcVar9 = *(undefined4 *)pcVar9;
  UNLOCK();
  if (iVar4 < 2) {
    if (*(uint *)(pcVar9 + 8) < uVar14 + uVar15) {
      uVar17 = 0x180b4ff01;
      goto LAB_180174101;
    }
  }
  else {
    uVar17 = 0;
LAB_180174101:
    FUN_18016f380(&local_res20,uVar14 + uVar15,uVar17,0,1);
  }
  if (uVar14 != 0) {
    pcVar9 = local_res20 + uVar13 * 0x28 + 0x10 + (ulonglong)uVar15 * 0x28;
    do {
      *(undefined ***)(pcVar9 + -0x38) = EMultiLineBreak::vftable;
      *(undefined8 *)(pcVar9 + -0x30) = 0;
      *(undefined8 *)(pcVar9 + -0x28) = 0;
      *(undefined8 *)(pcVar9 + -0x20) = 0;
      *(undefined8 *)(pcVar9 + -0x18) = 0;
      uVar15 = (int)uVar13 - 1;
      uVar13 = (ulonglong)uVar15;
      pcVar9 = pcVar9 + -0x28;
    } while (uVar15 != 0);
  }
LAB_180174189:
  uVar12 = 0;
  *(uint *)(local_res20 + -4) = param_3;
  pcVar9 = local_res20;
  uVar13 = uVar12;
  if (param_3 != 0) {
    do {
      if (*(uint *)(pcVar9 + -4) <= (uint)uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_70);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_70,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      pcVar9 = pcVar9 + -0x10;
      iVar4 = *(int *)pcVar9;
      *(int *)pcVar9 = *(int *)pcVar9;
      UNLOCK();
      if (1 < iVar4) {
        FUN_18016f380(&local_res20,*(undefined4 *)(local_res20 + -8),0,0,1);
      }
      pcVar9 = local_res20;
      uVar8 = (**(code **)(*param_2 + 0xb0))(param_2);
      *(undefined4 *)(pcVar9 + uVar13 + 8) = uVar8;
      uVar8 = (**(code **)(*param_2 + 0xb0))(param_2);
      *(undefined4 *)(pcVar9 + uVar13 + 0xc) = uVar8;
      uVar17 = (**(code **)(*param_2 + 200))(param_2);
      *(undefined8 *)(pcVar9 + uVar13 + 0x10) = uVar17;
      uVar17 = (**(code **)(*param_2 + 200))(param_2);
      *(undefined8 *)(pcVar9 + uVar13 + 0x18) = uVar17;
      uVar17 = (**(code **)(*param_2 + 200))(param_2);
      *(undefined8 *)(pcVar9 + uVar13 + 0x20) = uVar17;
      uVar15 = (uint)uVar12 + 1;
      uVar12 = (ulonglong)uVar15;
      uVar13 = uVar13 + 0x28;
    } while (uVar15 < param_3);
  }
  uVar13 = 0;
  if (*(short *)(param_1 + 0x234) != 0) {
    plVar3 = (longlong *)(param_1 + 0x318);
    do {
      uVar15 = (uint)uVar13;
      if (*(uint *)(*plVar3 + -4) <= uVar15) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_40);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_40,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar1 = (int *)(*plVar3 + -0x10);
      iVar4 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar4) {
        FUN_18000cbd0(plVar3,*(undefined4 *)(*plVar3 + -8),0,0,1);
      }
      uVar14 = 0;
      if (*(short *)(*(longlong *)(*plVar3 + uVar13 * 8) + 0x26) != 0) {
        while( true ) {
          if (*(uint *)(*plVar3 + -4) <= uVar15) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_48);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_48,(ThrowInfo *)&DAT_180de5370);
          }
          LOCK();
          piVar1 = (int *)(*plVar3 + -0x10);
          iVar4 = *piVar1;
          *piVar1 = *piVar1;
          UNLOCK();
          if (1 < iVar4) {
            FUN_18000cbd0(plVar3,*(undefined4 *)(*plVar3 + -8),0,0,1);
          }
          if (*(ushort *)(*(longlong *)(*plVar3 + uVar13 * 8) + 0x26) <= uVar14) break;
          if (*(uint *)(*plVar3 + -4) <= uVar15) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_50);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_50,(ThrowInfo *)&DAT_180de5370);
          }
          LOCK();
          piVar1 = (int *)(*plVar3 + -0x10);
          iVar4 = *piVar1;
          *piVar1 = *piVar1;
          UNLOCK();
          if (1 < iVar4) {
            FUN_18000cbd0(plVar3,*(undefined4 *)(*plVar3 + -8),0,0,1);
          }
          pcVar9 = local_res20;
          if (*(ushort *)(*(longlong *)(*plVar3 + uVar13 * 8) + 0x24) + uVar14 <
              *(uint *)(local_res20 + -4)) {
            if (*(uint *)(*plVar3 + -4) <= uVar15) {
              OdError_InvalidIndex::OdError_InvalidIndex(local_58);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(local_58,(ThrowInfo *)&DAT_180de5370);
            }
            LOCK();
            piVar1 = (int *)(*plVar3 + -0x10);
            iVar4 = *piVar1;
            *piVar1 = *piVar1;
            UNLOCK();
            if (1 < iVar4) {
              FUN_18000cbd0(plVar3,*(undefined4 *)(*plVar3 + -8),0,0,1);
            }
            uVar16 = *(ushort *)(*(longlong *)(*plVar3 + uVar13 * 8) + 0x24) + uVar14;
            if (*(uint *)(pcVar9 + -4) <= uVar16) {
              OdError_InvalidIndex::OdError_InvalidIndex(local_60);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(local_60,(ThrowInfo *)&DAT_180de5370);
            }
            LOCK();
            pcVar9 = local_res20 + -0x10;
            iVar4 = *(int *)pcVar9;
            *(int *)pcVar9 = *(int *)pcVar9;
            UNLOCK();
            if (1 < iVar4) {
              FUN_18016f380(&local_res20,*(undefined4 *)(local_res20 + -8),0,0,1);
            }
            pcVar9 = local_res20;
            if (*(uint *)(*plVar3 + -4) <= uVar15) {
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
              FUN_18000cbd0(plVar3,*(undefined4 *)(*plVar3 + -8),0,0,1);
            }
            lVar5 = *(longlong *)(*plVar3 + uVar13 * 8);
            if (*(uint *)(*(longlong *)(lVar5 + 0x30) + -4) < 0xffff) {
              puVar10 = (undefined8 *)FUN_18013c7c0();
              if (puVar10 != (undefined8 *)0x0) {
                *puVar10 = EMultiLineBreak::vftable;
                pcVar2 = pcVar9 + (ulonglong)uVar16 * 0x28 + 8;
                uVar8 = *(undefined4 *)(pcVar2 + 4);
                uVar6 = *(undefined4 *)(pcVar2 + 8);
                uVar7 = *(undefined4 *)(pcVar2 + 0xc);
                *(undefined4 *)(puVar10 + 1) = *(undefined4 *)pcVar2;
                *(undefined4 *)((longlong)puVar10 + 0xc) = uVar8;
                *(undefined4 *)(puVar10 + 2) = uVar6;
                *(undefined4 *)((longlong)puVar10 + 0x14) = uVar7;
                pcVar9 = pcVar9 + (ulonglong)uVar16 * 0x28 + 0x18;
                uVar17 = *(undefined8 *)(pcVar9 + 8);
                puVar10[3] = *(undefined8 *)pcVar9;
                puVar10[4] = uVar17;
              }
              FUN_180173b60(lVar5 + 0x30);
              uVar11 = 0;
            }
            else {
              uVar11 = 0x1c;
            }
            Dgn8::Error::Error(local_res18,uVar11,"C:\\B\\1\\_\\_\\Dgn\\source\\DgDefsInternal.h",
                               0x134);
          }
          uVar14 = uVar14 + 1;
        }
      }
      uVar13 = (ulonglong)(uVar15 + 1);
      pcVar9 = local_res20;
    } while (uVar15 + 1 < (uint)*(ushort *)(param_1 + 0x234));
  }
  pcVar9 = pcVar9 + -0x10;
  LOCK();
  iVar4 = *(int *)pcVar9;
  *(int *)pcVar9 = *(int *)pcVar9 + -1;
  UNLOCK();
  if ((iVar4 == 1) && (pcVar9 != g_empty_array_buffer_exref)) {
    odrxFree();
  }
  return;
}



