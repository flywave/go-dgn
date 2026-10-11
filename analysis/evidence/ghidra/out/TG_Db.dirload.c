/* ==== 1809d94d0 FUN_1809d94d0 ==== */

void FUN_1809d94d0(longlong *param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  int iVar1;
  undefined4 uVar2;
  longlong lVar3;
  longlong *plVar4;
  undefined8 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  code *pcVar8;
  longlong *plVar9;
  uint uVar10;
  longlong *plVar11;
  uint uVar12;
  uint uVar13;
  longlong *plVar14;
  ulonglong uVar15;
  code *pcVar16;
  uint uVar17;
  longlong *plVar18;
  undefined8 *puVar19;
  code *local_128;
  uint local_120;
  uint local_11c;
  longlong *local_118;
  uint local_110;
  longlong local_108;
  longlong *local_100;
  longlong local_f8;
  undefined8 local_f0;
  longlong *local_e8;
  undefined1 local_e0;
  undefined8 local_d8;
  undefined8 local_d0;
  ushort local_c8;
  undefined8 local_c4;
  undefined4 local_bc;
  undefined8 local_b8;
  undefined8 local_b0;
  Error local_a8 [8];
  OdError_InvalidIndex local_a0 [8];
  OdError_InvalidIndex local_98 [16];
  OdError_InvalidIndex local_88 [8];
  longlong *local_80;
  OdError_InvalidIndex local_78 [8];
  OdError_InvalidIndex local_70 [8];
  OdError_InvalidIndex local_68 [24];
  undefined1 local_50 [24];
  
  local_108 = *(longlong *)(*(longlong *)(param_4 + 0x10) + 0xd50);
  if ((*(char *)(local_108 + 0x20) == '\0') && (*(char *)(local_108 + 0x21) == '\0')) {
    plVar9 = (longlong *)0x0;
    local_f0 = 0;
    local_e8 = (longlong *)0x0;
    local_e0 = 0;
    local_d8 = 0;
    local_128 = g_empty_array_buffer_exref + 0x10;
    LOCK();
    *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
    UNLOCK();
    FUN_1809e1ca0(&local_128);
    local_120 = 0;
    local_110 = *(uint *)(param_1[7] + -4);
    if (*(int *)(local_128 + -4) == 0) {
      OdError_InvalidIndex::OdError_InvalidIndex(local_a0);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_a0,(ThrowInfo *)&DAT_180de5370);
    }
    LOCK();
    pcVar8 = local_128 + -0x10;
    iVar1 = *(int *)pcVar8;
    *(int *)pcVar8 = *(int *)pcVar8;
    UNLOCK();
    if (1 < iVar1) {
      FUN_1809df270(&local_128,*(undefined4 *)(local_128 + -8),0,0,1);
    }
    pcVar8 = local_128;
    *(uint *)(local_128 + 4) = local_110;
    Dgn8::Error::Error(local_a8,0,"C:\\B\\1\\_\\_\\Dgn\\source\\DgDefsInternal.h",0x134);
    plVar18 = plVar9;
    for (plVar14 = plVar9; uVar13 = (uint)plVar14, local_11c = uVar13, uVar13 < local_110;
        plVar14 = (longlong *)(ulonglong)((int)plVar14 + 1)) {
      if (*(uint *)(param_1[7] + -4) <= uVar13) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_98);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_98,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_18016f6d0(param_1 + 7);
      uVar15 = (ulonglong)*(uint *)(param_1[7] + (longlong)plVar14 * 4);
      lVar3 = (**(code **)(*param_1 + 200))(param_1);
      lVar3 = lVar3 + uVar15;
      local_d0 = 0;
      local_c8 = 0;
      local_c4 = 0;
      local_bc = 0;
      local_b8 = 0;
      local_b0 = 0;
      local_118 = (longlong *)0x0;
      puVar19 = &local_d0;
      local_f8 = lVar3;
      plVar4 = (longlong *)FUN_1809df950(param_1,&local_100,uVar15,param_4,puVar19,0);
      plVar4 = (longlong *)*plVar4;
      plVar11 = plVar9;
      if (plVar4 != (longlong *)0x0) {
        local_118 = plVar4;
        (**(code **)(*plVar4 + 0x20))();
        plVar11 = plVar4;
      }
      if (local_100 != (longlong *)0x0) {
        (**(code **)(*local_100 + 0x28))();
        local_100 = (longlong *)0x0;
      }
      uVar2 = 0;
      if (plVar11 == (longlong *)0x0) {
        if (((local_c8 >> 0xd & 1) != 0) &&
           ((**(code **)(*param_1 + 0x70))(param_1), (local_c8 >> 0xd & 1) != 0)) {
          piVar6 = (int *)(lVar3 + 0x24);
          if (((local_c8 >> 0xc & 1) != 0) && (local_d0._4_4_ != 100)) {
            piVar6 = (int *)(lVar3 + 0x6c);
          }
          plVar14 = (longlong *)(ulonglong)(uVar13 + *piVar6);
        }
      }
      else {
        plVar4 = (longlong *)
                 __RTDynamicCast(plVar11[1],0,&OdDgElementImpl::RTTI_Type_Descriptor,
                                 &CDGElementGeneral::RTTI_Type_Descriptor,
                                 (ulonglong)puVar19 & 0xffffffff00000000);
        local_80 = plVar4;
        if ((plVar4 != (longlong *)0x0) && (param_3 != 0)) {
          (**(code **)(*plVar4 + 0x480))(plVar4,param_3 + 0x58,1);
        }
        uVar17 = (uint)plVar18;
        if (uVar17 == 0) {
          uVar5 = (**(code **)(*plVar11 + 0x120))(plVar11,local_50);
          FUN_180013b80(param_2,uVar5);
          if (param_3 != 0) {
            (**(code **)(*plVar11 + 0x118))(plVar11,*(undefined8 *)(param_3 + 0x58));
          }
        }
        else {
          if (*(uint *)(pcVar8 + -4) <= uVar17) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_88);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_88,(ThrowInfo *)&DAT_180de5370);
          }
          LOCK();
          pcVar8 = pcVar8 + -0x10;
          iVar1 = *(int *)pcVar8;
          *(int *)pcVar8 = *(int *)pcVar8;
          UNLOCK();
          if (1 < iVar1) {
            FUN_1809df270(&local_128,*(undefined4 *)(local_128 + -8),0,0,1);
          }
          plVar11 = local_118;
          pcVar8 = local_128;
          FUN_180113970(*(undefined8 *)(local_128 + (longlong)plVar18 * 0x20 + 8),local_118);
        }
        if ((local_c8 >> 0xd & 1) != 0) {
          local_120 = uVar17 + 1;
          plVar18 = (longlong *)(ulonglong)local_120;
          local_f0 = CONCAT44(local_f0._4_4_,uVar13);
          (**(code **)(*param_1 + 0x70))();
          if ((local_c8 >> 0xd & 1) != 0) {
            puVar7 = (undefined4 *)(lVar3 + 0x24);
            if (((local_c8 >> 0xc & 1) != 0) && (local_d0._4_4_ != 100)) {
              puVar7 = (undefined4 *)(lVar3 + 0x6c);
            }
            uVar2 = *puVar7;
          }
          local_f0 = CONCAT44(uVar2,(undefined4)local_f0);
          if (local_e8 != plVar11) {
            if (local_e8 != (longlong *)0x0) {
              (**(code **)(*local_e8 + 0x28))();
            }
            local_e8 = plVar11;
            (**(code **)(*plVar11 + 0x20))(plVar11);
          }
          FUN_1809e1ca0(&local_128,&local_f0);
          pcVar8 = local_128;
        }
        *(ushort *)(plVar4 + 9) = *(ushort *)(plVar4 + 9) & 0xfffd;
      }
      while( true ) {
        uVar13 = (uint)plVar18;
        if (*(uint *)(pcVar8 + -4) <= uVar13) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_68);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_68,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        pcVar8 = pcVar8 + -0x10;
        iVar1 = *(int *)pcVar8;
        *(int *)pcVar8 = *(int *)pcVar8;
        UNLOCK();
        if (1 < iVar1) {
          FUN_1809df270(&local_128,*(undefined4 *)(local_128 + -8),0,0,1);
        }
        pcVar16 = local_128;
        lVar3 = (longlong)plVar18 * 0x20;
        if (*(uint *)(local_128 + -4) <= uVar13) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_70);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_70,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        pcVar8 = local_128 + -0x10;
        iVar1 = *(int *)pcVar8;
        *(int *)pcVar8 = *(int *)pcVar8;
        UNLOCK();
        if (1 < iVar1) {
          FUN_1809df270(&local_128,*(undefined4 *)(local_128 + -8),0,0,1);
        }
        pcVar8 = local_128;
        if (*(int *)(local_128 + lVar3 + 4) + *(int *)(pcVar16 + lVar3) != (int)plVar14) break;
        if (*(uint *)(local_128 + -4) <= uVar13) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_78);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_78,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        pcVar8 = local_128 + -0x10;
        iVar1 = *(int *)pcVar8;
        *(int *)pcVar8 = *(int *)pcVar8;
        UNLOCK();
        if (1 < iVar1) {
          FUN_1809df270(&local_128,*(undefined4 *)(local_128 + -8),0,0,1);
        }
        pcVar8 = local_128;
        if (*(longlong *)(local_128 + lVar3 + 8) == 0) {
LAB_1809d9afd:
          local_120 = uVar13 - 1;
          plVar18 = (longlong *)(ulonglong)local_120;
          pcVar8 = local_128;
        }
        else {
          uVar17 = *(uint *)(local_128 + -4);
          uVar12 = uVar17 - 1;
          uVar10 = uVar12 - uVar17;
          if ((int)uVar10 < 1) {
            if (-1 < (int)uVar10) goto LAB_1809d9af9;
            uVar10 = -uVar10;
            LOCK();
            pcVar16 = local_128 + -0x10;
            iVar1 = *(int *)pcVar16;
            *(int *)pcVar16 = *(int *)pcVar16;
            UNLOCK();
            if (1 < iVar1) {
              FUN_1809df270(&local_128,uVar12,0,0,1);
              goto LAB_1809d9af9;
            }
            if (uVar10 == 0) goto LAB_1809d9af9;
            pcVar16 = local_128 + (ulonglong)uVar10 * 0x20 + (ulonglong)uVar12 * 0x20 + 8;
            do {
              uVar10 = uVar10 - 1;
              pcVar16 = pcVar16 + -0x20;
              if (*(longlong **)pcVar16 != (longlong *)0x0) {
                (**(code **)(**(longlong **)pcVar16 + 0x28))();
                *(longlong *)pcVar16 = 0;
              }
            } while (uVar10 != 0);
            *(uint *)(pcVar8 + -4) = uVar12;
            local_120 = uVar13 - 1;
            plVar18 = (longlong *)(ulonglong)local_120;
          }
          else {
            LOCK();
            pcVar8 = local_128 + -0x10;
            iVar1 = *(int *)pcVar8;
            *(int *)pcVar8 = *(int *)pcVar8;
            UNLOCK();
            if (iVar1 < 2) {
              if (*(uint *)(local_128 + -8) < uVar10 + uVar17) {
                uVar5 = 1;
                goto LAB_1809d9a16;
              }
            }
            else {
              uVar5 = 0;
LAB_1809d9a16:
              FUN_1809df270(&local_128,uVar10 + uVar17,uVar5,0,1);
            }
            if (uVar10 == 0) {
LAB_1809d9af9:
              *(uint *)(local_128 + -4) = uVar12;
              goto LAB_1809d9afd;
            }
            pcVar8 = local_128 + (ulonglong)uVar10 * 0x20 + 8 + (ulonglong)uVar17 * 0x20;
            do {
              *(undefined8 *)(pcVar8 + -0x28) = 0;
              *(undefined8 *)(pcVar8 + -0x20) = 0;
              pcVar8[-0x18] = (code)0x0;
              *(undefined8 *)(pcVar8 + -0x10) = 0;
              uVar10 = uVar10 - 1;
              pcVar8 = pcVar8 + -0x20;
            } while (uVar10 != 0);
            *(uint *)(local_128 + -4) = uVar12;
            local_120 = uVar13 - 1;
            plVar18 = (longlong *)(ulonglong)local_120;
            pcVar8 = local_128;
          }
        }
      }
      if ((local_108 != 0) && (*(longlong **)(local_108 + 0x18) != (longlong *)0x0)) {
        (**(code **)(**(longlong **)(local_108 + 0x18) + 0x18))();
      }
      if (local_118 != (longlong *)0x0) {
        (**(code **)(*local_118 + 0x28))();
      }
    }
    pcVar16 = pcVar8 + -0x10;
    LOCK();
    iVar1 = *(int *)pcVar16;
    *(int *)pcVar16 = *(int *)pcVar16 + -1;
    UNLOCK();
    if ((iVar1 == 1) && (pcVar16 != g_empty_array_buffer_exref)) {
      FUN_1809e0c20(pcVar8,*(undefined4 *)(pcVar8 + -4));
      odrxFree(pcVar16);
    }
    if (local_e8 != (longlong *)0x0) {
      (**(code **)(*local_e8 + 0x28))();
    }
  }
  else {
    FUN_1809d9c80(param_1,param_2);
  }
  return;
}



