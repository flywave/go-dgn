/* ==== 180185700 FUN_180185700 ==== */

undefined8 FUN_180185700(longlong *param_1,longlong *param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x244) = uVar1;
  iVar2 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar2 == 2) {
    (**(code **)(*param_1 + 0x690))(param_1);
  }
  return 0;
}



/* ==== 1801e0790 FUN_1801e0790 ==== */

undefined8 FUN_1801e0790(longlong param_1,longlong *param_2)

{
  int *piVar1;
  code *pcVar2;
  longlong *plVar3;
  ulonglong uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  void *_Src;
  longlong lVar8;
  undefined2 uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 *puVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  uint uVar15;
  longlong lVar16;
  uint uVar17;
  undefined8 uVar18;
  OdError local_res20 [8];
  OdError_InvalidIndex local_58 [24];
  
  uVar9 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)(param_1 + 0x220) = uVar9;
  (**(code **)(*param_2 + 0x90))(param_2,param_1 + 0x222,0x46);
  plVar3 = (longlong *)(param_1 + 0x278);
  (**(code **)(*param_2 + 0xb0))(param_2);
  FUN_180015300(plVar3);
  uVar10 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x268) = uVar10;
  uVar10 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x26c) = uVar10;
  uVar10 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x270) = uVar10;
  uVar17 = 0;
  uVar6 = *(uint *)(*plVar3 + -4);
  if (uVar6 != 0) {
    lVar16 = 0;
    do {
      if (*(uint *)(*plVar3 + -4) <= uVar17) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_58);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_58,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar1 = (int *)(*plVar3 + -0x10);
      iVar5 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar5) {
        _Src = (void *)*plVar3;
        uVar7 = *(uint *)((longlong)_Src + -0xc);
        pcVar2 = (code *)((longlong)_Src + -0x10);
        uVar15 = *(uint *)((longlong)_Src + -8);
        if ((int)uVar7 < 1) {
          uVar13 = (ulonglong)-(*(int *)((longlong)_Src + -4) * uVar7) / 100;
          uVar11 = *(int *)((longlong)_Src + -4) + (int)uVar13;
          uVar14 = (ulonglong)uVar11;
          if (uVar11 < uVar15) {
            uVar14 = (ulonglong)uVar15;
          }
        }
        else {
          uVar11 = (uVar15 - 1) + uVar7;
          uVar13 = (ulonglong)uVar11 % (ulonglong)uVar7;
          uVar14 = (ulonglong)((uVar11 / uVar7) * uVar7);
        }
        uVar4 = uVar14 * 8 + 0x10;
        if (uVar4 <= uVar14) {
LAB_1801e098c:
          OdError::OdError(local_res20,9);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de52b8);
        }
        puVar12 = (undefined4 *)odrxAlloc(uVar4,uVar13);
        if (puVar12 == (undefined4 *)0x0) goto LAB_1801e098c;
        *puVar12 = 0;
        LOCK();
        *puVar12 = 1;
        UNLOCK();
        puVar12[2] = (int)uVar14;
        puVar12[1] = uVar7;
        puVar12[3] = 0;
        if (*(uint *)((longlong)_Src + -4) < uVar15) {
          uVar15 = *(uint *)((longlong)_Src + -4);
        }
        memcpy(puVar12 + 4,_Src,(ulonglong)uVar15 << 3);
        puVar12[3] = uVar15;
        *plVar3 = (longlong)(puVar12 + 4);
        LOCK();
        iVar5 = *(int *)pcVar2;
        *(int *)pcVar2 = *(int *)pcVar2 + -1;
        UNLOCK();
        if ((iVar5 == 1) && (pcVar2 != g_empty_array_buffer_exref)) {
          odrxFree(pcVar2);
        }
      }
      lVar8 = *plVar3;
      uVar18 = (**(code **)(*param_2 + 200))();
      *(undefined8 *)(lVar8 + lVar16) = uVar18;
      uVar17 = uVar17 + 1;
      lVar16 = lVar16 + 8;
    } while (uVar17 < uVar6);
  }
  return 0;
}



/* ==== 1801f4c00 dgnInFields ==== */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: virtual enum OdResult __cdecl ESharedCellInst::dgnInFields(class OdDgFiler * __ptr64)
   __ptr64 */

OdResult __thiscall ESharedCellInst::dgnInFields(ESharedCellInst *this,OdDgFiler *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  undefined8 *puVar6;
  undefined1 auStack_e8 [32];
  undefined4 local_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined8 local_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  undefined8 local_a0;
  undefined1 local_98 [128];
  ulonglong local_18;
  
                    /* 0x1f4c00  7799
                       ?dgnInFields@ESharedCellInst@@UEAA?AW4OdResult@@PEAVOdDgFiler@@@Z */
  local_18 = DAT_180fcd438 ^ (ulonglong)auStack_e8;
  uVar5 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
  *(undefined4 *)(this + 0x220) = uVar5;
  uVar4 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 0x224) = uVar4;
  uVar4 = (**(code **)(*(longlong *)param_1 + 0xa8))(param_1);
  *(undefined2 *)(this + 0x226) = uVar4;
  (**(code **)(*(longlong *)param_1 + 0x110))(param_1,&local_b0);
  (**(code **)(*(longlong *)param_1 + 0x110))(param_1,&local_c8);
  *(undefined8 *)(this + 0x228) = local_b0;
  *(undefined8 *)(this + 0x230) = uStack_a8;
  *(undefined8 *)(this + 0x238) = local_a0;
  *(undefined4 *)(this + 0x240) = local_c8;
  *(undefined4 *)(this + 0x244) = uStack_c4;
  *(undefined4 *)(this + 0x248) = uStack_c0;
  *(undefined4 *)(this + 0x24c) = uStack_bc;
  *(undefined8 *)(this + 0x250) = local_b8;
  puVar6 = (undefined8 *)FUN_1801f6e10(local_98,param_1);
  uVar3 = puVar6[1];
  *(undefined8 *)(this + 600) = *puVar6;
  *(undefined8 *)(this + 0x260) = uVar3;
  uVar3 = puVar6[3];
  *(undefined8 *)(this + 0x268) = puVar6[2];
  *(undefined8 *)(this + 0x270) = uVar3;
  uVar3 = puVar6[5];
  *(undefined8 *)(this + 0x278) = puVar6[4];
  *(undefined8 *)(this + 0x280) = uVar3;
  uVar3 = puVar6[7];
  *(undefined8 *)(this + 0x288) = puVar6[6];
  *(undefined8 *)(this + 0x290) = uVar3;
  uVar3 = puVar6[9];
  *(undefined8 *)(this + 0x298) = puVar6[8];
  *(undefined8 *)(this + 0x2a0) = uVar3;
  uVar3 = puVar6[0xb];
  *(undefined8 *)(this + 0x2a8) = puVar6[10];
  *(undefined8 *)(this + 0x2b0) = uVar3;
  uVar5 = *(undefined4 *)((longlong)puVar6 + 100);
  uVar1 = *(undefined4 *)(puVar6 + 0xd);
  uVar2 = *(undefined4 *)((longlong)puVar6 + 0x6c);
  *(undefined4 *)(this + 0x2b8) = *(undefined4 *)(puVar6 + 0xc);
  *(undefined4 *)(this + 700) = uVar5;
  *(undefined4 *)(this + 0x2c0) = uVar1;
  *(undefined4 *)(this + 0x2c4) = uVar2;
  uVar5 = *(undefined4 *)((longlong)puVar6 + 0x74);
  uVar1 = *(undefined4 *)(puVar6 + 0xf);
  uVar2 = *(undefined4 *)((longlong)puVar6 + 0x7c);
  *(undefined4 *)(this + 0x2c8) = *(undefined4 *)(puVar6 + 0xe);
  *(undefined4 *)(this + 0x2cc) = uVar5;
  *(undefined4 *)(this + 0x2d0) = uVar1;
  *(undefined4 *)(this + 0x2d4) = uVar2;
  puVar6 = (undefined8 *)(**(code **)(*(longlong *)param_1 + 0x110))(param_1,&local_c8);
  uVar3 = puVar6[1];
  *(undefined8 *)(this + 0x2d8) = *puVar6;
  *(undefined8 *)(this + 0x2e0) = uVar3;
  *(undefined8 *)(this + 0x2e8) = puVar6[2];
  *(undefined8 *)(this + 0x2f0) = 0;
  return 0;
}



