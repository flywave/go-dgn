/* ==== 1802e63a0 FUN_1802e63a0 ==== */

void FUN_1802e63a0(longlong *param_1,longlong *param_2)

{
  longlong *plVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  code *pcVar12;
  code *pcVar13;
  code *pcVar14;
  uint uVar15;
  longlong *local_res8;
  char local_res10 [8];
  undefined1 local_res18 [8];
  code *local_res20;
  OdError_InvalidIndex local_b8 [8];
  OdError_InvalidIndex local_b0 [8];
  OdError_InvalidIndex local_a8 [8];
  OdError_InvalidIndex local_a0 [8];
  OdError_InvalidIndex local_98 [8];
  OdError_InvalidIndex local_90 [8];
  undefined1 local_88 [24];
  undefined1 local_70 [48];
  
  local_res8 = param_1;
  uVar7 = (**(code **)(*param_2 + 0xb0))(param_2);
  uVar8 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 1) = uVar8;
  if (10000 < uVar7) {
    iVar9 = (**(code **)(*param_2 + 0x88))(param_2);
    iVar10 = (**(code **)(*param_2 + 0x80))(param_2);
    uVar7 = (uint)(iVar9 - iVar10) / 0x18;
  }
  plVar1 = param_1 + 2;
  FUN_180177de0(plVar1,uVar7);
  cVar6 = (**(code **)(*param_1 + 0x70))(param_1);
  pcVar13 = (code *)0x0;
  if (cVar6 == '\0') {
    pcVar12 = pcVar13;
    if (uVar7 != 0) {
      do {
        if (*(uint *)(*plVar1 + -4) <= (uint)pcVar12) {
          OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)&local_res8);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_res8,(ThrowInfo *)&DAT_180de5370);
        }
        FUN_180018080(plVar1);
        lVar3 = *plVar1;
        puVar11 = (undefined4 *)(**(code **)(*param_2 + 0x110))(param_2,local_70);
        uVar8 = puVar11[1];
        uVar4 = puVar11[2];
        uVar5 = puVar11[3];
        pcVar14 = pcVar13 + lVar3;
        *(undefined4 *)pcVar14 = *puVar11;
        *(undefined4 *)(pcVar14 + 4) = uVar8;
        *(undefined4 *)(pcVar14 + 8) = uVar4;
        *(undefined4 *)(pcVar14 + 0xc) = uVar5;
        *(undefined8 *)(pcVar13 + lVar3 + 0x10) = *(undefined8 *)(puVar11 + 4);
        uVar15 = (uint)pcVar12 + 1;
        pcVar13 = pcVar13 + 0x18;
        pcVar12 = (code *)(ulonglong)uVar15;
      } while (uVar15 < uVar7);
    }
  }
  else {
    pcVar12 = pcVar13;
    pcVar14 = pcVar13;
    if (uVar7 != 0) {
      do {
        local_res10[0] = '\0';
        uVar15 = (uint)pcVar12;
        if (*(uint *)(*plVar1 + -4) <= uVar15) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_90);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_90,(ThrowInfo *)&DAT_180de5370);
        }
        FUN_180018080(plVar1);
        lVar3 = *plVar1;
        puVar11 = (undefined4 *)(**(code **)(*param_2 + 0x108))(param_2,local_88,local_res10);
        uVar8 = puVar11[1];
        uVar4 = puVar11[2];
        uVar5 = puVar11[3];
        pcVar12 = pcVar14 + lVar3;
        *(undefined4 *)pcVar12 = *puVar11;
        *(undefined4 *)(pcVar12 + 4) = uVar8;
        *(undefined4 *)(pcVar12 + 8) = uVar4;
        *(undefined4 *)(pcVar12 + 0xc) = uVar5;
        *(undefined8 *)(pcVar14 + lVar3 + 0x10) = *(undefined8 *)(puVar11 + 4);
        if (local_res10[0] != '\0') {
          local_res20 = g_empty_array_buffer_exref + 0x10;
          LOCK();
          *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
          UNLOCK();
          local_res18[0] = 0xff;
          FUN_180075e80(&local_res20,8,local_res18);
          if (*(uint *)(local_res20 + -4) < 7) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_98);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_98,(ThrowInfo *)&DAT_180de5370);
          }
          FUN_18000d0b0(&local_res20);
          local_res20[6] = (code)0xef;
          if (*(uint *)(local_res20 + -4) < 8) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_a0);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_a0,(ThrowInfo *)&DAT_180de5370);
          }
          FUN_18000d0b0(&local_res20);
          local_res20[7] = (code)0x7f;
          FUN_18000d0b0(&local_res20);
          pcVar12 = pcVar13;
          if (*(int *)(local_res20 + -4) != 0) {
            pcVar12 = local_res20;
          }
          uVar2 = *(undefined8 *)pcVar12;
          pcVar12 = local_res20 + -0x10;
          LOCK();
          iVar9 = *(int *)pcVar12;
          *(int *)pcVar12 = *(int *)pcVar12 + -1;
          UNLOCK();
          if ((iVar9 == 1) && (pcVar12 != g_empty_array_buffer_exref)) {
            odrxFree();
          }
          if (*(uint *)(*plVar1 + -4) <= uVar15) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_a8);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_a8,(ThrowInfo *)&DAT_180de5370);
          }
          FUN_180018080(plVar1);
          *(undefined8 *)(pcVar14 + *plVar1) = uVar2;
          if (*(uint *)(*plVar1 + -4) <= uVar15) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_b0);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_b0,(ThrowInfo *)&DAT_180de5370);
          }
          FUN_180018080(plVar1);
          *(undefined8 *)(pcVar14 + *plVar1 + 8) = uVar2;
          if (*(uint *)(*plVar1 + -4) <= uVar15) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_b8);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_b8,(ThrowInfo *)&DAT_180de5370);
          }
          FUN_180018080(plVar1);
          *(undefined8 *)(pcVar14 + *plVar1 + 0x10) = uVar2;
        }
        pcVar12 = (code *)(ulonglong)(uVar15 + 1);
        param_1 = local_res8;
        pcVar14 = pcVar14 + 0x18;
      } while (uVar15 + 1 < uVar7);
    }
  }
  *(undefined1 *)(param_1 + 4) = 1;
  return;
}



