/* ==== 180259990 FUN_180259990 ==== */

void FUN_180259990(longlong *param_1,longlong *param_2)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  longlong *plVar8;
  ulonglong uVar9;
  short sVar10;
  byte bVar11;
  uint uVar12;
  ulonglong uVar13;
  longlong *local_res8;
  longlong **local_res10;
  undefined1 local_res18 [8];
  undefined1 local_res20 [8];
  longlong local_158;
  undefined1 local_150 [4];
  undefined1 local_14c [4];
  longlong *local_148;
  OdError_InvalidIndex local_140 [8];
  OdError_InvalidIndex local_138 [8];
  OdError_InvalidIndex local_130 [8];
  OdError_InvalidIndex local_128 [8];
  OdError_InvalidIndex local_120 [8];
  OdError_InvalidIndex local_118 [8];
  OdError_InvalidIndex local_110 [8];
  OdError_InvalidIndex local_108 [8];
  OdAnsiString local_100 [8];
  OdAnsiString local_f8 [8];
  OdAnsiString local_f0 [8];
  OdAnsiString local_e8 [8];
  OdAnsiString local_e0 [8];
  OdAnsiString local_d8 [8];
  OdError_InvalidIndex local_d0 [8];
  OdError_InvalidIndex local_c8 [8];
  OdError_InvalidIndex local_c0 [8];
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 local_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  
  FUN_1802684f0();
  *(uint *)(param_1 + 0x59) = *(uint *)(param_1 + 0x59) & 0x7fffffff;
  (**(code **)(*param_2 + 0x168))(param_2,param_1[0x44]);
  (**(code **)(*param_2 + 0x160))(param_2,(int)param_1[0x45]);
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)((longlong)param_1 + 0x22c));
  (**(code **)(*param_2 + 0x170))(param_2,(int)param_1[0x46]);
  (**(code **)(*param_2 + 0x160))(param_2,(int)param_1[0x47]);
  (**(code **)(*param_2 + 0x150))(param_2,*(undefined1 *)((longlong)param_1 + 0x23c));
  (**(code **)(*param_2 + 0x150))(param_2,*(undefined1 *)((longlong)param_1 + 0x23d));
  (**(code **)(*param_2 + 0x150))(param_2,*(undefined1 *)((longlong)param_1 + 0x23e));
  (**(code **)(*param_2 + 0x150))(param_2,*(undefined1 *)((longlong)param_1 + 0x23f));
  (**(code **)(*param_2 + 0x150))(param_2,(char)param_1[0x48]);
  (**(code **)(*param_2 + 0x150))(param_2,*(undefined1 *)((longlong)param_1 + 0x241));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)((longlong)param_1 + 0x242));
  FUN_1808c5500((longlong)param_1 + 0x244,param_2);
  (**(code **)(*param_2 + 0x170))(param_2,(int)param_1[0x4b]);
  (**(code **)(*param_2 + 0x170))(param_2,(int)param_1[0x4a]);
  (**(code **)(*param_2 + 0x160))(param_2,(int)param_1[0x4c]);
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)((longlong)param_1 + 0x264));
  (**(code **)(*param_2 + 0x160))(param_2,(int)param_1[0x4d]);
  (**(code **)(*param_2 + 0x160))(param_2,(int)param_1[0x4e]);
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)((longlong)param_1 + 0x274));
  (**(code **)(*param_2 + 0x160))(param_2,(int)param_1[0x4f]);
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)((longlong)param_1 + 0x27c));
  (**(code **)(*param_2 + 0x170))(param_2,(int)param_1[0x50]);
  (**(code **)(*param_2 + 0x170))(param_2,(int)param_1[0x51]);
  (**(code **)(*param_2 + 0x170))(param_2,(int)param_1[0x52]);
  (**(code **)(*param_2 + 0x170))(param_2,(int)param_1[0x53]);
  (**(code **)(*param_2 + 0x170))(param_2,(int)param_1[0x54]);
  (**(code **)(*param_2 + 0x170))(param_2,(int)param_1[0x55]);
  (**(code **)(*param_2 + 0x170))(param_2,(int)param_1[0x56]);
  (**(code **)(*param_2 + 0x170))(param_2,(int)param_1[0x57]);
  (**(code **)(*param_2 + 0x170))(param_2,(int)param_1[0x58]);
  (**(code **)(*param_2 + 0x160))(param_2,(int)param_1[0x59]);
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)((longlong)param_1 + 0x2cc));
  local_b8 = (undefined4)param_1[0x5a];
  uStack_b4 = *(undefined4 *)((longlong)param_1 + 0x2d4);
  uStack_b0 = (undefined4)param_1[0x5b];
  uStack_ac = *(undefined4 *)((longlong)param_1 + 0x2dc);
  local_a8 = (undefined4)param_1[0x5c];
  uStack_a4 = *(undefined4 *)((longlong)param_1 + 0x2e4);
  uStack_a0 = (undefined4)param_1[0x5d];
  uStack_9c = *(undefined4 *)((longlong)param_1 + 0x2ec);
  iVar4 = (**(code **)(*param_1 + 0x440))(param_1);
  if ((iVar4 == 0) || (iVar4 = (**(code **)(*param_2 + 0x58))(param_2), iVar4 != 0xb)) {
    iVar4 = (**(code **)(*param_1 + 0x440))(param_1);
    if ((iVar4 == 0) && (iVar4 = (**(code **)(*param_2 + 0x58))(param_2), iVar4 == 10)) {
      local_b8 = (undefined4)param_1[0x5e];
      uStack_b4 = *(undefined4 *)((longlong)param_1 + 0x2f4);
      uStack_b0 = (undefined4)param_1[0x5f];
      uStack_ac = *(undefined4 *)((longlong)param_1 + 0x2fc);
      local_a8 = (undefined4)param_1[0x60];
      uStack_a4 = *(undefined4 *)((longlong)param_1 + 0x304);
      uStack_a0 = (undefined4)param_1[0x61];
      uStack_9c = *(undefined4 *)((longlong)param_1 + 0x30c);
    }
  }
  else {
    local_b8 = (undefined4)param_1[0x62];
    uStack_b4 = *(undefined4 *)((longlong)param_1 + 0x314);
    uStack_b0 = (undefined4)param_1[99];
    uStack_ac = *(undefined4 *)((longlong)param_1 + 0x31c);
    uStack_a0 = (undefined4)param_1[0x66];
    uStack_9c = *(undefined4 *)((longlong)param_1 + 0x334);
    local_a8 = (undefined4)param_1[0x65];
    uStack_a4 = (undefined4)((ulonglong)param_1[0x65] >> 0x20);
  }
  (**(code **)(*param_2 + 0x1c0))(param_2,&local_b8);
  uVar9 = 0;
  sVar10 = 0;
  OdString::init((OdString *)&local_158);
  bVar2 = false;
  uVar7 = uVar9;
  if (*(char *)((longlong)param_1 + 0x23f) != '\0') {
    do {
      bVar1 = false;
      uVar12 = (uint)uVar7;
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)local_d8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_d8,(ThrowInfo *)&DAT_180de5370);
      }
      local_148 = *(longlong **)(param_1[0x6f] + uVar7 * 0x10);
      (**(code **)(*local_148 + 0x68))(local_148,sVar10);
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)local_e0);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_e0,(ThrowInfo *)&DAT_180de5370);
      }
      iVar4 = (**(code **)(**(longlong **)(param_1[0x6f] + uVar7 * 0x10) + 0xa0))();
      if (iVar4 != 0) {
        OdString::empty((OdString *)&local_158);
        if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_140);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_140,(ThrowInfo *)&DAT_180de5370);
        }
        plVar8 = *(longlong **)(param_1[0x6f] + uVar7 * 0x10);
        (**(code **)(*plVar8 + 0x140))(plVar8,&local_res8,&local_158);
        if ((*(longlong *)(local_158 + 0x10) != 0) ||
           (bVar1 = true, *(longlong *)(local_158 + 0x18) == 0)) {
          bVar1 = false;
        }
        if (bVar1) {
          OdString::syncUnicode((OdString *)&local_158);
        }
        sVar10 = sVar10 + (short)*(undefined4 *)(local_158 + 4) + 1;
        bVar1 = true;
      }
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)local_e8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_e8,(ThrowInfo *)&DAT_180de5370);
      }
      iVar4 = (**(code **)(**(longlong **)(param_1[0x6f] + uVar7 * 0x10) + 0xa8))();
      if (iVar4 != 0) {
        OdString::empty((OdString *)&local_158);
        if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_138);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_138,(ThrowInfo *)&DAT_180de5370);
        }
        plVar8 = *(longlong **)(param_1[0x6f] + uVar7 * 0x10);
        (**(code **)(*plVar8 + 0x150))(plVar8,&local_res10,&local_158);
        if ((*(longlong *)(local_158 + 0x10) != 0) ||
           (bVar1 = true, *(longlong *)(local_158 + 0x18) == 0)) {
          bVar1 = bVar2;
        }
        if (bVar1) {
          OdString::syncUnicode((OdString *)&local_158);
        }
        sVar10 = sVar10 + (short)*(undefined4 *)(local_158 + 4) + 1;
        bVar1 = true;
      }
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)local_f0);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_f0,(ThrowInfo *)&DAT_180de5370);
      }
      iVar4 = (**(code **)(**(longlong **)(param_1[0x6f] + uVar7 * 0x10) + 0xb0))();
      if (iVar4 != 0) {
        OdString::empty((OdString *)&local_158);
        if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_130);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_130,(ThrowInfo *)&DAT_180de5370);
        }
        plVar8 = *(longlong **)(param_1[0x6f] + uVar7 * 0x10);
        (**(code **)(*plVar8 + 0x160))(plVar8,local_res18,&local_158);
        if ((*(longlong *)(local_158 + 0x10) != 0) ||
           (bVar1 = true, *(longlong *)(local_158 + 0x18) == 0)) {
          bVar1 = bVar2;
        }
        if (bVar1) {
          OdString::syncUnicode((OdString *)&local_158);
        }
        sVar10 = sVar10 + (short)*(undefined4 *)(local_158 + 4) + 1;
        bVar1 = true;
      }
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)local_f8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_f8,(ThrowInfo *)&DAT_180de5370);
      }
      iVar4 = (**(code **)(**(longlong **)(param_1[0x6f] + uVar7 * 0x10) + 0xb8))();
      if (iVar4 != 0) {
        OdString::empty((OdString *)&local_158);
        if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_128);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_128,(ThrowInfo *)&DAT_180de5370);
        }
        plVar8 = *(longlong **)(param_1[0x6f] + uVar7 * 0x10);
        (**(code **)(*plVar8 + 0x170))(plVar8,local_res20,&local_158);
        if ((*(longlong *)(local_158 + 0x10) != 0) ||
           (bVar1 = true, *(longlong *)(local_158 + 0x18) == 0)) {
          bVar1 = bVar2;
        }
        if (bVar1) {
          OdString::syncUnicode((OdString *)&local_158);
        }
        sVar10 = sVar10 + (short)*(undefined4 *)(local_158 + 4) + 1;
        bVar1 = true;
      }
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)local_100);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_100,(ThrowInfo *)&DAT_180de5370);
      }
      iVar4 = (**(code **)(**(longlong **)(param_1[0x6f] + uVar7 * 0x10) + 0xc0))();
      if (iVar4 != 0) {
        OdString::empty((OdString *)&local_158);
        if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_120);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_120,(ThrowInfo *)&DAT_180de5370);
        }
        plVar8 = *(longlong **)(param_1[0x6f] + uVar7 * 0x10);
        (**(code **)(*plVar8 + 0x180))(plVar8,local_150,&local_158);
        if ((*(longlong *)(local_158 + 0x10) != 0) ||
           (bVar1 = true, *(longlong *)(local_158 + 0x18) == 0)) {
          bVar1 = bVar2;
        }
        if (bVar1) {
          OdString::syncUnicode((OdString *)&local_158);
        }
        sVar10 = sVar10 + (short)*(undefined4 *)(local_158 + 4) + 1;
        bVar1 = true;
      }
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_108);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_108,(ThrowInfo *)&DAT_180de5370);
      }
      iVar4 = (**(code **)(**(longlong **)(param_1[0x6f] + uVar7 * 0x10) + 200))();
      if (iVar4 == 0) {
        if (!bVar1) {
          (**(code **)(*local_148 + 0x68))(local_148,0xffff);
        }
      }
      else {
        OdString::empty((OdString *)&local_158);
        if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_118);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_118,(ThrowInfo *)&DAT_180de5370);
        }
        plVar8 = *(longlong **)(param_1[0x6f] + uVar7 * 0x10);
        (**(code **)(*plVar8 + 400))(plVar8,local_14c,&local_158);
        if ((*(longlong *)(local_158 + 0x10) != 0) ||
           (bVar1 = true, *(longlong *)(local_158 + 0x18) == 0)) {
          bVar1 = bVar2;
        }
        if (bVar1) {
          OdString::syncUnicode((OdString *)&local_158);
        }
        sVar10 = sVar10 + (short)*(undefined4 *)(local_158 + 4) + 1;
      }
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_110);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_110,(ThrowInfo *)&DAT_180de5370);
      }
      FUN_1802a3840(*(undefined8 *)(param_1[0x6f] + uVar7 * 0x10),param_2);
      uVar7 = (ulonglong)(uVar12 + 1);
    } while (uVar12 + 1 < (uint)*(byte *)((longlong)param_1 + 0x23f));
  }
  bVar11 = *(byte *)(param_1 + 0x48);
  if (param_1[0x71] != 0) {
    plVar8 = (longlong *)(param_1[0x71] + 0x10);
    (**(code **)(*plVar8 + 8))(plVar8,param_2);
    bVar11 = bVar11 - 1;
  }
  if (param_1[0x72] != 0) {
    plVar8 = (longlong *)(param_1[0x72] + 0x10);
    (**(code **)(*plVar8 + 8))(plVar8,param_2);
    bVar11 = bVar11 - 1;
  }
  if (param_1[0x77] != 0) {
    plVar8 = (longlong *)(param_1[0x77] + 0x10);
    (**(code **)(*plVar8 + 8))(plVar8,param_2);
    bVar11 = bVar11 - 1;
  }
  if (param_1[0x78] != 0) {
    plVar8 = (longlong *)(param_1[0x78] + 0x10);
    (**(code **)(*plVar8 + 8))(plVar8,param_2);
    bVar11 = bVar11 - 1;
  }
  if (param_1[0x76] != 0) {
    plVar8 = (longlong *)(param_1[0x76] + 0x10);
    (**(code **)(*plVar8 + 8))(plVar8,param_2);
    bVar11 = bVar11 - 1;
  }
  if ((param_1[0x80] != 0) && (cVar3 = FUN_18025e810(param_1 + 0x80), cVar3 == '\0')) {
    (**(code **)(*(longlong *)(param_1[0x80] + 0x10) + 8))
              ((longlong *)(param_1[0x80] + 0x10),param_2);
    bVar11 = bVar11 - 1;
  }
  if (param_1[0x7f] != 0) {
    plVar8 = (longlong *)(param_1[0x7f] + 0x10);
    (**(code **)(*plVar8 + 8))(plVar8,param_2);
    bVar11 = bVar11 - 1;
  }
  plVar8 = (longlong *)param_1[0x7a];
  if (plVar8 != (longlong *)0x0) {
    local_res8 = plVar8;
    (**(code **)(*plVar8 + 0x20))();
    local_res10 = &local_res8;
    iVar4 = (**(code **)(*local_res8 + 0x80))();
    if (local_res8 != (longlong *)0x0) {
      (**(code **)(*local_res8 + 0x28))();
    }
    if (iVar4 == 1) {
      (**(code **)(*(longlong *)(param_1[0x7a] + 0x10) + 8))
                ((longlong *)(param_1[0x7a] + 0x10),param_2);
      bVar11 = bVar11 - 1;
    }
  }
  plVar8 = (longlong *)param_1[0x7b];
  if (plVar8 != (longlong *)0x0) {
    local_res8 = plVar8;
    (**(code **)(*plVar8 + 0x20))();
    local_res10 = &local_res8;
    iVar4 = (**(code **)(*local_res8 + 0x80))();
    if (local_res8 != (longlong *)0x0) {
      (**(code **)(*local_res8 + 0x28))();
    }
    if (iVar4 == 1) {
      (**(code **)(*(longlong *)(param_1[0x7b] + 0x10) + 8))
                ((longlong *)(param_1[0x7b] + 0x10),param_2);
      bVar11 = bVar11 - 1;
    }
  }
  if (param_1[0x7c] != 0) {
    plVar8 = (longlong *)(param_1[0x7c] + 0x10);
    (**(code **)(*plVar8 + 8))(plVar8,param_2);
    bVar11 = bVar11 - 1;
  }
  if (param_1[0x7d] != 0) {
    plVar8 = (longlong *)(param_1[0x7d] + 0x10);
    (**(code **)(*plVar8 + 8))(plVar8,param_2);
    bVar11 = bVar11 - 1;
  }
  if (param_1[0x7e] != 0) {
    plVar8 = (longlong *)(param_1[0x7e] + 0x10);
    (**(code **)(*plVar8 + 8))(plVar8,param_2);
    bVar11 = bVar11 - 1;
  }
  if ((param_1[0x79] != 0) && (cVar3 = FUN_18025e8d0(param_1 + 0x79), cVar3 == '\0')) {
    (**(code **)(*(longlong *)(param_1[0x79] + 0x10) + 8))
              ((longlong *)(param_1[0x79] + 0x10),param_2);
    bVar11 = bVar11 - 1;
  }
  if (param_1[0x73] != 0) {
    plVar8 = (longlong *)(param_1[0x73] + 0x10);
    (**(code **)(*plVar8 + 8))(plVar8,param_2);
    bVar11 = bVar11 - 1;
  }
  if (param_1[0x74] != 0) {
    plVar8 = (longlong *)(param_1[0x74] + 0x10);
    (**(code **)(*plVar8 + 8))(plVar8,param_2);
    bVar11 = bVar11 - 1;
  }
  if (param_1[0x75] != 0) {
    plVar8 = (longlong *)(param_1[0x75] + 0x10);
    (**(code **)(*plVar8 + 8))(plVar8,param_2);
    bVar11 = bVar11 - 1;
  }
  uVar7 = uVar9;
  uVar13 = uVar9;
  if (bVar11 != 0) {
    do {
      if (*(uint *)(param_1[0x70] + -4) <= (uint)uVar13) {
        OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)&local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      plVar8 = *(longlong **)(uVar7 + param_1[0x70]);
      (**(code **)(*plVar8 + 8))(plVar8,param_2);
      uVar12 = (uint)uVar13 + 1;
      uVar7 = uVar7 + 0x10;
      uVar13 = (ulonglong)uVar12;
    } while (uVar12 < bVar11);
  }
  if (*(char *)((longlong)param_1 + 0x23f) != '\0') {
    do {
      uVar12 = (uint)uVar9;
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_c0);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_c0,(ThrowInfo *)&DAT_180de5370);
      }
      iVar4 = (**(code **)(**(longlong **)(param_1[0x6f] + uVar9 * 0x10) + 0xa0))();
      if (iVar4 != 0) {
        OdString::empty((OdString *)&local_158);
        if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_108);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_108,(ThrowInfo *)&DAT_180de5370);
        }
        plVar8 = *(longlong **)(param_1[0x6f] + uVar9 * 0x10);
        (**(code **)(*plVar8 + 0x140))(plVar8,&local_res8,&local_158);
        pcVar5 = OdString::operator_char_const____ptr64((OdString *)&local_158);
        uVar6 = OdAnsiString::OdAnsiString(local_d8,pcVar5);
        (**(code **)(*param_2 + 0x1d0))(param_2,uVar6);
        OdAnsiString::~OdAnsiString(local_d8);
        (**(code **)(*param_2 + 0x150))(param_2,0);
      }
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_c8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_c8,(ThrowInfo *)&DAT_180de5370);
      }
      iVar4 = (**(code **)(**(longlong **)(param_1[0x6f] + uVar9 * 0x10) + 0xa8))();
      if (iVar4 != 0) {
        OdString::empty((OdString *)&local_158);
        if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_110);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_110,(ThrowInfo *)&DAT_180de5370);
        }
        plVar8 = *(longlong **)(param_1[0x6f] + uVar9 * 0x10);
        (**(code **)(*plVar8 + 0x150))(plVar8,&local_res10,&local_158);
        pcVar5 = OdString::operator_char_const____ptr64((OdString *)&local_158);
        uVar6 = OdAnsiString::OdAnsiString(local_e0,pcVar5);
        (**(code **)(*param_2 + 0x1d0))(param_2,uVar6);
        OdAnsiString::~OdAnsiString(local_e0);
        (**(code **)(*param_2 + 0x150))(param_2,0);
      }
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_d0);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_d0,(ThrowInfo *)&DAT_180de5370);
      }
      iVar4 = (**(code **)(**(longlong **)(param_1[0x6f] + uVar9 * 0x10) + 0xb0))();
      if (iVar4 != 0) {
        OdString::empty((OdString *)&local_158);
        if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_118);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_118,(ThrowInfo *)&DAT_180de5370);
        }
        plVar8 = *(longlong **)(param_1[0x6f] + uVar9 * 0x10);
        (**(code **)(*plVar8 + 0x160))(plVar8,local_res18,&local_158);
        pcVar5 = OdString::operator_char_const____ptr64((OdString *)&local_158);
        uVar6 = OdAnsiString::OdAnsiString(local_e8,pcVar5);
        (**(code **)(*param_2 + 0x1d0))(param_2,uVar6);
        OdAnsiString::~OdAnsiString(local_e8);
        (**(code **)(*param_2 + 0x150))(param_2,0);
      }
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex((OdError_InvalidIndex *)&local_148);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_148,(ThrowInfo *)&DAT_180de5370);
      }
      iVar4 = (**(code **)(**(longlong **)(param_1[0x6f] + uVar9 * 0x10) + 0xb8))();
      if (iVar4 != 0) {
        OdString::empty((OdString *)&local_158);
        if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_120);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_120,(ThrowInfo *)&DAT_180de5370);
        }
        plVar8 = *(longlong **)(param_1[0x6f] + uVar9 * 0x10);
        (**(code **)(*plVar8 + 0x170))(plVar8,local_res20,&local_158);
        pcVar5 = OdString::operator_char_const____ptr64((OdString *)&local_158);
        uVar6 = OdAnsiString::OdAnsiString(local_f0,pcVar5);
        (**(code **)(*param_2 + 0x1d0))(param_2,uVar6);
        OdAnsiString::~OdAnsiString(local_f0);
        (**(code **)(*param_2 + 0x150))(param_2,0);
      }
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_140);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_140,(ThrowInfo *)&DAT_180de5370);
      }
      iVar4 = (**(code **)(**(longlong **)(param_1[0x6f] + uVar9 * 0x10) + 0xc0))();
      if (iVar4 != 0) {
        OdString::empty((OdString *)&local_158);
        if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_128);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_128,(ThrowInfo *)&DAT_180de5370);
        }
        plVar8 = *(longlong **)(param_1[0x6f] + uVar9 * 0x10);
        (**(code **)(*plVar8 + 0x180))(plVar8,local_14c,&local_158);
        pcVar5 = OdString::operator_char_const____ptr64((OdString *)&local_158);
        uVar6 = OdAnsiString::OdAnsiString(local_f8,pcVar5);
        (**(code **)(*param_2 + 0x1d0))(param_2,uVar6);
        OdAnsiString::~OdAnsiString(local_f8);
        (**(code **)(*param_2 + 0x150))(param_2,0);
      }
      if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_138);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_138,(ThrowInfo *)&DAT_180de5370);
      }
      iVar4 = (**(code **)(**(longlong **)(param_1[0x6f] + uVar9 * 0x10) + 200))();
      if (iVar4 != 0) {
        OdString::empty((OdString *)&local_158);
        if (*(uint *)(param_1[0x6f] + -4) <= uVar12) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_130);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_130,(ThrowInfo *)&DAT_180de5370);
        }
        plVar8 = *(longlong **)(param_1[0x6f] + uVar9 * 0x10);
        (**(code **)(*plVar8 + 400))(plVar8,local_150,&local_158);
        pcVar5 = OdString::operator_char_const____ptr64((OdString *)&local_158);
        uVar6 = OdAnsiString::OdAnsiString(local_100,pcVar5);
        (**(code **)(*param_2 + 0x1d0))(param_2,uVar6);
        OdAnsiString::~OdAnsiString(local_100);
        (**(code **)(*param_2 + 0x150))(param_2,0);
      }
      uVar9 = (ulonglong)(uVar12 + 1);
    } while (uVar12 + 1 < (uint)*(byte *)((longlong)param_1 + 0x23f));
  }
  iVar4 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar4 == 2) {
    (**(code **)(*param_2 + 0x148))(param_2,(char)param_1[0x88] != '\0');
  }
  uVar7 = (**(code **)(*param_2 + 0x80))(param_2);
  if ((uVar7 & 1) != 0) {
    (**(code **)(*param_2 + 0x148))(param_2,0);
  }
  OdString::~OdString((OdString *)&local_158);
  return;
}



/* ==== 1804beb10 FUN_1804beb10 ==== */

undefined8 FUN_1804beb10(longlong param_1,longlong *param_2)

{
  longlong *plVar1;
  undefined4 uVar2;
  longlong lVar3;
  
  plVar1 = (longlong *)(param_1 + 0x228);
  (**(code **)(*param_2 + 0x88))(param_2);
  (**(code **)(*param_2 + 0x80))(param_2);
  FUN_1800150c0(plVar1);
  uVar2 = *(undefined4 *)(*plVar1 + -4);
  FUN_18000d0b0(plVar1);
  lVar3 = 0;
  if (*(int *)(*plVar1 + -4) != 0) {
    lVar3 = *plVar1;
  }
  (**(code **)(*param_2 + 0x140))(param_2,lVar3,uVar2);
  return 0;
}



/* ==== 1804beba0 FUN_1804beba0 ==== */

OdResult FUN_1804beba0(CDGElementGeneral *param_1,OdDgFiler *param_2)

{
  code *pcVar1;
  int iVar2;
  longlong lVar3;
  bool bVar4;
  char cVar5;
  short sVar6;
  undefined2 uVar7;
  OdResult OVar8;
  OdRxClass *pOVar9;
  longlong *plVar10;
  OdDgDatabase *pOVar11;
  OdDbHandle *pOVar12;
  longlong *plVar13;
  longlong *plVar14;
  OdString *pOVar15;
  OdRxClass *pOVar16;
  uint uVar17;
  code *local_res18;
  longlong *local_res20;
  longlong local_60;
  undefined8 local_58;
  longlong *local_50;
  OdError_NotThatKindOfClass local_48 [8];
  OdString local_40 [8];
  OdError_InvalidIndex local_38 [16];
  
  OVar8 = CDGElementGeneral::dgnInXAttributes(param_1,param_2);
  local_res18 = g_empty_array_buffer_exref + 0x10;
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  FUN_1801cc8b0(param_1,0xecda0000,&local_res18,0);
  plVar14 = (longlong *)0x0;
  if (*(int *)(local_res18 + -4) != 0) {
    do {
      if (*(uint *)(local_res18 + -4) <= (uint)plVar14) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_38);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_38,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      pcVar1 = local_res18 + -0x10;
      iVar2 = *(int *)pcVar1;
      *(int *)pcVar1 = *(int *)pcVar1;
      UNLOCK();
      if (1 < iVar2) {
        FUN_18000cd30(&local_res18,*(undefined4 *)(local_res18 + -8),0,0,1);
      }
      plVar13 = *(longlong **)(local_res18 + (longlong)plVar14 * 8);
      plVar10 = (longlong *)0x0;
      if (plVar13 != (longlong *)0x0) {
        lVar3 = *plVar13;
        pOVar9 = OdDgElementSchemaXAttribute::desc();
        plVar10 = (longlong *)(**(code **)(lVar3 + 8))(plVar13,pOVar9);
        if (plVar10 == (longlong *)0x0) {
          pOVar9 = OdDgElementSchemaXAttribute::desc();
          pOVar16 = (OdRxClass *)(**(code **)(*plVar13 + 0x18))(plVar13);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_50,pOVar16,pOVar9);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_50,(ThrowInfo *)&DAT_180de5310);
        }
      }
      sVar6 = (**(code **)(*plVar10 + 0x80))(plVar10);
      if (sVar6 == 0) {
        if (*(longlong *)(param_1 + 0x58) == 0) {
LAB_1804becd4:
          pOVar11 = *(OdDgDatabase **)(param_1 + 0x68);
        }
        else {
          local_60 = *(longlong *)(param_1 + 0x58);
          pOVar11 = OdDgElementId::database((OdDgElementId *)&local_60);
          if (pOVar11 == (OdDgDatabase *)0x0) {
LAB_1804becbf:
            bVar4 = false;
          }
          else {
            local_58 = *(undefined8 *)(param_1 + 0x58);
            pOVar12 = OdDgElementId::getHandle((OdDgElementId *)&local_58);
            bVar4 = true;
            if (*(longlong *)pOVar12 == 0) goto LAB_1804becbf;
          }
          if (!bVar4) goto LAB_1804becd4;
          pOVar11 = OdDgElementId::database((OdDgElementId *)(param_1 + 0x58));
        }
        (**(code **)(*plVar10 + 0xa0))(plVar10,&local_res20,pOVar11);
        pOVar9 = OdDgTablePrototypeDescriptionSchema::desc();
        plVar13 = (longlong *)(**(code **)(*local_res20 + 0x18))();
        cVar5 = (**(code **)(*plVar13 + 0x60))(plVar13,pOVar9);
        plVar13 = local_res20;
        if (cVar5 != '\0') {
          local_50 = (longlong *)0x0;
          plVar14 = local_50;
          if (local_res20 != (longlong *)0x0) {
            lVar3 = *local_res20;
            pOVar9 = OdDgTablePrototypeDescriptionSchema::desc();
            plVar14 = (longlong *)(**(code **)(lVar3 + 8))(plVar13,pOVar9);
            if (plVar14 == (longlong *)0x0) {
              pOVar9 = OdDgTablePrototypeDescriptionSchema::desc();
              pOVar16 = (OdRxClass *)(**(code **)(*plVar13 + 0x18))(plVar13);
              OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_48,pOVar16,pOVar9);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(local_48,(ThrowInfo *)&DAT_180de5310);
            }
          }
          local_50 = plVar14;
          plVar14 = local_50;
          uVar7 = (**(code **)(*local_50 + 0xb0))(local_50);
          *(undefined2 *)(param_1 + 0x230) = uVar7;
          pOVar15 = (OdString *)(**(code **)(*plVar14 + 0xc0))(plVar14,local_40);
          OdString::operator=((OdString *)(param_1 + 0x238),pOVar15);
          OdString::~OdString(local_40);
          (**(code **)(*plVar14 + 0x28))(plVar14);
          if (local_res20 != (longlong *)0x0) {
            (**(code **)(*local_res20 + 0x28))();
            local_res20 = (longlong *)0x0;
          }
          if (plVar10 != (longlong *)0x0) {
            (**(code **)(*plVar10 + 0x28))(plVar10);
          }
          break;
        }
        if (local_res20 != (longlong *)0x0) {
          (**(code **)(*local_res20 + 0x28))();
          local_res20 = (longlong *)0x0;
        }
        (**(code **)(*plVar10 + 0x28))(plVar10);
      }
      else {
        (**(code **)(*plVar10 + 0x28))(plVar10);
      }
      uVar17 = (uint)plVar14 + 1;
      plVar14 = (longlong *)(ulonglong)uVar17;
    } while (uVar17 < *(uint *)(local_res18 + -4));
  }
  FUN_1800144b0(local_res18 + -0x10);
  return OVar8;
}



/* ==== 1804beef0 FUN_1804beef0 ==== */

void FUN_1804beef0(longlong param_1,longlong *param_2)

{
  longlong lVar1;
  
  lVar1 = 0;
  if (*(int *)(*(longlong *)(param_1 + 0x228) + -4) != 0) {
    lVar1 = *(longlong *)(param_1 + 0x228);
  }
                    /* WARNING: Could not recover jumptable at 0x0001804bef0d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x140))(param_2,lVar1);
  return;
}



/* ==== 1804bef20 FUN_1804bef20 ==== */

void FUN_1804bef20(CDGElementGeneral *param_1,OdDgFiler *param_2)

{
  bool bVar1;
  char cVar2;
  undefined2 uVar3;
  int iVar4;
  undefined8 uVar5;
  
  bVar1 = false;
  if (param_2 != (OdDgFiler *)0x0) {
    iVar4 = (**(code **)(*(longlong *)param_2 + 0x58))(param_2);
    bVar1 = false;
    if (iVar4 == 2) {
      bVar1 = true;
    }
  }
  cVar2 = (**(code **)(*(longlong *)param_1 + 0x910))(param_1);
  if ((cVar2 != '\0') && (!bVar1)) {
    (**(code **)(*(longlong *)param_1 + 0x938))(param_1,0);
    FUN_1804b6bd0(param_1);
    uVar5 = FUN_180010890(param_1);
    uVar3 = FUN_1804c4d60(uVar5);
    *(undefined2 *)(param_1 + 0x392) = uVar3;
    FUN_1804dd4e0(param_1,0);
    (**(code **)(*(longlong *)param_1 + 0x938))(param_1,1);
  }
  CDGElementGeneral::dgnOutXAttributes(param_1,param_2);
  return;
}



