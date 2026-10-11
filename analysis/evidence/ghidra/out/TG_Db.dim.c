/* ==== 180257e60 FUN_180257e60 ==== */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined8 FUN_180257e60(longlong *param_1,longlong *param_2)

{
  ulonglong *puVar1;
  undefined1 auVar2 [16];
  byte bVar3;
  undefined1 auVar4 [16];
  undefined4 uVar5;
  undefined4 uVar6;
  longlong lVar7;
  bool bVar8;
  undefined1 uVar9;
  bool bVar10;
  char cVar11;
  undefined2 uVar12;
  short sVar13;
  ushort uVar14;
  undefined4 uVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  longlong lVar19;
  undefined4 *puVar20;
  longlong *plVar21;
  longlong *plVar22;
  undefined8 uVar23;
  longlong *plVar24;
  undefined8 *puVar25;
  OdString *pOVar26;
  ulonglong uVar27;
  code *pcVar28;
  longlong *plVar29;
  int *piVar30;
  longlong *plVar31;
  uint uVar32;
  undefined1 auStack_2e8 [32];
  undefined1 local_2c8;
  uint local_2b8;
  undefined1 local_2b4;
  undefined1 local_2b3;
  OdString local_2b0 [16];
  longlong local_2a0;
  longlong *local_298;
  int *local_290;
  longlong local_288;
  longlong *local_278;
  longlong *local_270;
  longlong *local_268;
  longlong *local_260;
  longlong *local_258;
  longlong *local_250;
  longlong *local_248;
  longlong *local_240;
  longlong *local_238;
  longlong *local_230;
  longlong *local_228;
  longlong *local_220;
  longlong *local_218;
  longlong *local_210;
  longlong *local_208;
  longlong *local_200;
  longlong *local_1f8;
  longlong *local_1f0;
  longlong *local_1e8;
  int *local_1e0;
  undefined1 local_1bc [4];
  undefined1 local_1b8 [4];
  undefined1 local_1b4 [4];
  undefined1 local_1b0 [4];
  undefined1 local_1ac [4];
  undefined1 local_1a8 [16];
  OdError_InvalidIndex local_198 [8];
  OdError_InvalidIndex local_190 [8];
  OdError_InvalidIndex local_188 [8];
  OdError_InvalidIndex local_180 [8];
  OdError_InvalidIndex local_178 [8];
  OdString local_170 [8];
  OdError_InvalidIndex local_168 [8];
  OdError_InvalidIndex local_160 [8];
  OdString local_158 [8];
  OdError_InvalidIndex local_150 [8];
  OdError_InvalidIndex local_148 [8];
  OdString local_140 [8];
  OdError_InvalidIndex local_138 [8];
  OdError_InvalidIndex local_130 [8];
  OdString local_128 [8];
  OdError_InvalidIndex local_120 [8];
  OdError_InvalidIndex local_118 [8];
  OdString local_110 [8];
  OdError_InvalidIndex local_108 [8];
  OdError_InvalidIndex local_100 [8];
  OdString local_f8 [8];
  OdError_InvalidIndex local_f0 [8];
  longlong *local_e8;
  longlong *local_d8;
  int *local_d0;
  undefined1 local_c8 [32];
  longlong local_a8;
  longlong lStack_a0;
  undefined8 local_98;
  longlong lStack_90;
  longlong local_88;
  undefined8 uStack_80;
  undefined8 local_78;
  undefined8 uStack_70;
  longlong local_68;
  ulonglong local_58;
  
  local_58 = DAT_180fcd438 ^ (ulonglong)auStack_2e8;
  local_278 = param_1;
  local_1f0 = param_2;
  lVar19 = (**(code **)(*param_2 + 0xb8))(param_2);
  param_1[0x44] = lVar19;
  uVar15 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x45) = uVar15;
  uVar15 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x22c) = uVar15;
  lVar19 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x46] = lVar19;
  uVar15 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x47) = uVar15;
  uVar9 = (**(code **)(*param_2 + 0xa0))(param_2);
  *(undefined1 *)((longlong)param_1 + 0x23c) = uVar9;
  uVar9 = (**(code **)(*param_2 + 0xa0))(param_2);
  *(undefined1 *)((longlong)param_1 + 0x23d) = uVar9;
  uVar9 = (**(code **)(*param_2 + 0xa0))(param_2);
  *(undefined1 *)((longlong)param_1 + 0x23e) = uVar9;
  uVar9 = (**(code **)(*param_2 + 0xa0))(param_2);
  *(undefined1 *)((longlong)param_1 + 0x23f) = uVar9;
  uVar9 = (**(code **)(*param_2 + 0xa0))(param_2);
  *(undefined1 *)(param_1 + 0x48) = uVar9;
  uVar9 = (**(code **)(*param_2 + 0xa0))(param_2);
  *(undefined1 *)((longlong)param_1 + 0x241) = uVar9;
  uVar12 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)((longlong)param_1 + 0x242) = uVar12;
  FUN_1808c52e0((longlong)param_1 + 0x244,param_2);
  lVar19 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x4b] = lVar19;
  lVar19 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x4a] = lVar19;
  uVar15 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x4c) = uVar15;
  uVar15 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x264) = uVar15;
  uVar15 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x4d) = uVar15;
  uVar15 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x4e) = uVar15;
  uVar12 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)((longlong)param_1 + 0x274) = uVar12;
  uVar15 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x4f) = uVar15;
  uVar12 = (**(code **)(*param_2 + 0xa8))(param_2);
  *(undefined2 *)((longlong)param_1 + 0x27c) = uVar12;
  lVar19 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x50] = lVar19;
  lVar19 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x51] = lVar19;
  lVar19 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x52] = lVar19;
  lVar19 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x53] = lVar19;
  lVar19 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x54] = lVar19;
  lVar19 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x55] = lVar19;
  lVar19 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x56] = lVar19;
  lVar19 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x57] = lVar19;
  lVar19 = (**(code **)(*param_2 + 200))(param_2);
  param_1[0x58] = lVar19;
  uVar15 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)(param_1 + 0x59) = uVar15;
  uVar15 = (**(code **)(*param_2 + 0xb0))(param_2);
  *(undefined4 *)((longlong)param_1 + 0x2cc) = uVar15;
  puVar20 = (undefined4 *)(**(code **)(*param_2 + 0x128))(param_2,local_c8);
  uVar15 = puVar20[1];
  uVar5 = puVar20[2];
  uVar6 = puVar20[3];
  *(undefined4 *)(param_1 + 0x5a) = *puVar20;
  *(undefined4 *)((longlong)param_1 + 0x2d4) = uVar15;
  *(undefined4 *)(param_1 + 0x5b) = uVar5;
  *(undefined4 *)((longlong)param_1 + 0x2dc) = uVar6;
  uVar15 = puVar20[5];
  uVar5 = puVar20[6];
  uVar6 = puVar20[7];
  *(undefined4 *)(param_1 + 0x5c) = puVar20[4];
  *(undefined4 *)((longlong)param_1 + 0x2e4) = uVar15;
  *(undefined4 *)(param_1 + 0x5d) = uVar5;
  *(undefined4 *)((longlong)param_1 + 0x2ec) = uVar6;
  iVar16 = (**(code **)(*param_1 + 0x440))(param_1);
  if (iVar16 == 0) {
    local_98 = *(undefined8 *)(kIdentity_exref + 0x10);
    uStack_80 = *(undefined8 *)(kIdentity_exref + 0x28);
    local_78 = *(undefined8 *)(kIdentity_exref + 0x30);
    uStack_70 = *(undefined8 *)(kIdentity_exref + 0x38);
    local_68 = *(longlong *)(kIdentity_exref + 0x40);
    local_a8 = param_1[0x5a];
    lStack_90 = param_1[0x5b];
    lStack_a0 = param_1[0x5c];
    local_88 = param_1[0x5d];
    bVar10 = OdGeMatrix2d::isSingular((OdGeMatrix2d *)&local_a8,(OdGeTol *)gTol_exref);
    if (!bVar10) goto LAB_1802582c9;
    param_1[0x5b] = 0;
    param_1[0x5c] = 0;
    param_1[0x5d] = 0x3ff0000000000000;
  }
  else {
    if ((1e-10 < (double)param_1[0x5b]) || ((double)param_1[0x5b] < -1e-10)) {
      bVar10 = false;
    }
    else {
      bVar10 = true;
    }
    if (!bVar10) goto LAB_1802582c9;
    bVar10 = false;
    if ((1e-10 < (double)param_1[0x5c]) || (bVar8 = true, (double)param_1[0x5c] < -1e-10)) {
      bVar8 = bVar10;
    }
    if (!bVar8) goto LAB_1802582c9;
    if ((1e-10 < (double)param_1[0x5d]) || (bVar8 = true, (double)param_1[0x5d] < -1e-10)) {
      bVar8 = bVar10;
    }
    if (!bVar8) goto LAB_1802582c9;
    if ((1e-10 < (double)param_1[0x5a]) || (bVar8 = true, (double)param_1[0x5a] < -1e-10)) {
      bVar8 = bVar10;
    }
    if (!bVar8) goto LAB_1802582c9;
  }
  param_1[0x5a] = 0x3ff0000000000000;
LAB_1802582c9:
  plVar31 = (longlong *)0x0;
  plVar22 = param_1 + 0x6f;
  FUN_180260700(plVar22,*(undefined1 *)((longlong)param_1 + 0x23f));
  local_2b8 = 0;
  plVar24 = plVar31;
  if (*(char *)((longlong)param_1 + 0x23f) != '\0') {
    do {
      plVar21 = (longlong *)FUN_18013c7c0(0x78);
      plVar29 = plVar31;
      local_e8 = plVar21;
      if (plVar21 != (longlong *)0x0) {
        *plVar21 = (longlong)CDGDimensionPoint::vftable;
        plVar21[1] = 0;
        plVar21[2] = 0;
        plVar21[3] = 0;
        plVar21[4] = 0;
        plVar21[5] = 0;
        plVar21[6] = 0;
        OdString::init((OdString *)(plVar21 + 7));
        OdString::init((OdString *)(plVar21 + 8));
        OdString::init((OdString *)(plVar21 + 9));
        OdString::init((OdString *)(plVar21 + 10));
        OdString::init((OdString *)(plVar21 + 0xb));
        OdString::init((OdString *)(plVar21 + 0xc));
        plVar21[0xd] = 0;
        *(undefined1 *)(plVar21 + 0xe) = 0;
        plVar29 = plVar21;
      }
      local_1e0 = (int *)0x0;
      local_1e8 = plVar29;
      if (plVar29 != (longlong *)0x0) {
        local_1e0 = (int *)odrxAlloc(4);
        *local_1e0 = 1;
      }
      if (*(uint *)(*plVar22 + -4) <= (uint)plVar24) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_190);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_190,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar30 = (int *)(*plVar22 + -0x10);
      iVar16 = *piVar30;
      *piVar30 = *piVar30;
      UNLOCK();
      if (1 < iVar16) {
        local_2c8 = 1;
        FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
      }
      lVar19 = *plVar22;
      local_2a0 = lVar19;
      if (*(longlong **)(lVar19 + (longlong)plVar24 * 0x10) != plVar29) {
        piVar30 = *(int **)(lVar19 + 8 + (longlong)plVar24 * 0x10);
        if ((piVar30 != (int *)0x0) && (*piVar30 = *piVar30 + -1, *piVar30 == 0)) {
          odrxFree(*(undefined8 *)(lVar19 + 8 + (longlong)plVar24 * 0x10));
          local_288 = *(longlong *)(lVar19 + (longlong)plVar24 * 0x10);
          if (local_288 != 0) {
            FUN_1802a2dc0(local_288);
            FUN_18013c820(local_288,0x78);
          }
        }
        *(longlong **)(lVar19 + (longlong)plVar24 * 0x10) = plVar29;
        *(int **)(local_2a0 + 8 + (longlong)plVar24 * 0x10) = local_1e0;
        if (local_1e0 != (int *)0x0) {
          *local_1e0 = *local_1e0 + 1;
        }
      }
      piVar30 = local_1e0;
      if ((local_1e0 != (int *)0x0) && (*local_1e0 = *local_1e0 + -1, *local_1e0 == 0)) {
        if (plVar29 != (longlong *)0x0) {
          FUN_1802a2dc0(plVar29);
          FUN_18013c820(plVar29,0x78);
        }
        odrxFree(piVar30);
      }
      uVar17 = local_2b8;
      if (*(uint *)(*plVar22 + -4) <= local_2b8) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_198);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_198,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar30 = (int *)(*plVar22 + -0x10);
      iVar16 = *piVar30;
      *piVar30 = *piVar30;
      UNLOCK();
      if (1 < iVar16) {
        local_2c8 = 1;
        FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
      }
      FUN_1802a37b0(*(undefined8 *)(*plVar22 + (longlong)plVar24 * 0x10),param_2);
      local_2b8 = uVar17 + 1;
      plVar24 = (longlong *)(ulonglong)local_2b8;
    } while (local_2b8 < *(byte *)((longlong)param_1 + 0x23f));
  }
  bVar3 = *(byte *)(param_1 + 0x48);
  if (bVar3 == 0) {
LAB_180258ebd:
    uVar17 = (**(code **)(*param_2 + 0x80))(param_2);
    local_288 = CONCAT44(local_288._4_4_,uVar17);
    local_2a0 = CONCAT44(local_2a0._4_4_,uVar17);
    OdString::init(local_2b0);
    while( true ) {
      while( true ) {
        uVar32 = (uint)plVar31;
        local_2b8 = uVar32;
        if (*(byte *)((longlong)param_1 + 0x23f) <= uVar32) {
          iVar16 = (**(code **)(*param_2 + 0x58))(param_2);
          if (iVar16 == 2) {
            cVar11 = (**(code **)(*param_2 + 0x98))(param_2);
            if ((bool)(char)param_1[0x88] != (cVar11 == '\x01')) {
              *(bool *)(param_1 + 0x88) = cVar11 == '\x01';
            }
            uVar17 = uVar17 + 1;
          }
          (**(code **)(*param_2 + 0x78))(param_2,uVar17,0);
          uVar27 = (**(code **)(*param_2 + 0x80))(param_2);
          if ((uVar27 & 1) != 0) {
            (**(code **)(*param_2 + 0x98))(param_2);
          }
          if ((param_1[0x1c] == 0) || ((*(ushort *)(param_1[0x1c] + 8) >> 0xb & 1) == 0)) {
            lVar19 = param_1[0x5a];
            lVar7 = param_1[0x5b];
            auVar2 = *(undefined1 (*) [16])(param_1 + 0x5c);
            OdGeMatrix2d::OdGeMatrix2d((OdGeMatrix2d *)&local_a8);
            param_1[0x62] = lVar19;
            param_1[99] = lVar7;
            *(undefined4 *)(param_1 + 100) = (undefined4)local_98;
            *(undefined4 *)((longlong)param_1 + 0x324) = local_98._4_4_;
            *(int *)(param_1 + 0x65) = auVar2._0_4_;
            *(int *)((longlong)param_1 + 0x32c) = auVar2._4_4_;
            auVar4._8_4_ = (undefined4)uStack_80;
            auVar4._0_8_ = auVar2._8_8_;
            auVar4._12_4_ = uStack_80._4_4_;
            *(undefined1 (*) [16])(param_1 + 0x66) = auVar4;
            *(undefined4 *)(param_1 + 0x68) = (undefined4)local_78;
            *(undefined4 *)((longlong)param_1 + 0x344) = local_78._4_4_;
            *(undefined4 *)(param_1 + 0x69) = (undefined4)uStack_70;
            *(undefined4 *)((longlong)param_1 + 0x34c) = uStack_70._4_4_;
            param_1[0x6a] = local_68;
          }
          else {
            *(int *)(param_1 + 0x5e) = (int)param_1[0x5a];
            *(undefined4 *)((longlong)param_1 + 0x2f4) = *(undefined4 *)((longlong)param_1 + 0x2d4);
            *(int *)(param_1 + 0x5f) = (int)param_1[0x5b];
            *(undefined4 *)((longlong)param_1 + 0x2fc) = *(undefined4 *)((longlong)param_1 + 0x2dc);
            *(int *)(param_1 + 0x60) = (int)param_1[0x5c];
            *(undefined4 *)((longlong)param_1 + 0x304) = *(undefined4 *)((longlong)param_1 + 0x2e4);
            *(int *)(param_1 + 0x61) = (int)param_1[0x5d];
            *(undefined4 *)((longlong)param_1 + 0x30c) = *(undefined4 *)((longlong)param_1 + 0x2ec);
          }
          (**(code **)(*param_1 + 0x880))(param_1);
          OdString::~OdString(local_2b0);
          return 0;
        }
        plVar22 = param_1 + 0x6f;
        if (*(uint *)(*plVar22 + -4) <= uVar32) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_188);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_188,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        piVar30 = (int *)(*plVar22 + -0x10);
        iVar16 = *piVar30;
        *piVar30 = *piVar30;
        UNLOCK();
        if (1 < iVar16) {
          local_2c8 = 1;
          FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
        }
        sVar13 = (**(code **)(**(longlong **)(*plVar22 + (longlong)plVar31 * 0x10) + 0x60))();
        if (sVar13 != -1) break;
        plVar31 = (longlong *)(ulonglong)(uVar32 + 1);
      }
      if (*(uint *)(*plVar22 + -4) <= uVar32) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_180);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_180,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar30 = (int *)(*plVar22 + -0x10);
      iVar16 = *piVar30;
      *piVar30 = *piVar30;
      UNLOCK();
      if (1 < iVar16) {
        local_2c8 = 1;
        FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
      }
      uVar14 = (**(code **)(**(longlong **)(*plVar22 + (longlong)plVar31 * 0x10) + 0x60))();
      (**(code **)(*param_2 + 0x78))(param_2,(uint)uVar14 + (int)local_288);
      if (*(uint *)(*plVar22 + -4) <= uVar32) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_178);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_178,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar30 = (int *)(*plVar22 + -0x10);
      iVar16 = *piVar30;
      *piVar30 = *piVar30;
      UNLOCK();
      if (1 < iVar16) {
        local_2c8 = 1;
        FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
      }
      iVar16 = (**(code **)(**(longlong **)(*plVar22 + (longlong)plVar31 * 0x10) + 0xa0))();
      if (iVar16 != 0) {
        pOVar26 = (OdString *)FUN_18025f040(param_1,local_170,param_2);
        OdString::operator=(local_2b0,pOVar26);
        OdString::~OdString(local_170);
        if (*(uint *)(*plVar22 + -4) <= uVar32) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_168);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_168,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        piVar30 = (int *)(*plVar22 + -0x10);
        iVar16 = *piVar30;
        *piVar30 = *piVar30;
        UNLOCK();
        if (1 < iVar16) {
          local_2c8 = 1;
          FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
        }
        plVar24 = *(longlong **)(*plVar22 + (longlong)plVar31 * 0x10);
        (**(code **)(*plVar24 + 0x148))(plVar24,local_1b8);
      }
      if (*(uint *)(*plVar22 + -4) <= uVar32) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_160);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_160,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar30 = (int *)(*plVar22 + -0x10);
      iVar16 = *piVar30;
      *piVar30 = *piVar30;
      UNLOCK();
      if (1 < iVar16) {
        local_2c8 = 1;
        FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
      }
      iVar16 = (**(code **)(**(longlong **)(*plVar22 + (longlong)plVar31 * 0x10) + 0xa8))();
      if (iVar16 != 0) {
        pOVar26 = (OdString *)FUN_18025f040(param_1,local_158,param_2);
        OdString::operator=(local_2b0,pOVar26);
        OdString::~OdString(local_158);
        if (*(uint *)(*plVar22 + -4) <= uVar32) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_150);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_150,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        piVar30 = (int *)(*plVar22 + -0x10);
        iVar16 = *piVar30;
        *piVar30 = *piVar30;
        UNLOCK();
        if (1 < iVar16) {
          local_2c8 = 1;
          FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
        }
        plVar24 = *(longlong **)(*plVar22 + (longlong)plVar31 * 0x10);
        (**(code **)(*plVar24 + 0x158))(plVar24,local_1b4);
      }
      if (*(uint *)(*plVar22 + -4) <= uVar32) break;
      LOCK();
      piVar30 = (int *)(*plVar22 + -0x10);
      iVar16 = *piVar30;
      *piVar30 = *piVar30;
      UNLOCK();
      if (1 < iVar16) {
        local_2c8 = 1;
        FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
      }
      iVar16 = (**(code **)(**(longlong **)(*plVar22 + (longlong)plVar31 * 0x10) + 0xb0))();
      if (iVar16 != 0) {
        pOVar26 = (OdString *)FUN_18025f040(param_1,local_140,param_2);
        OdString::operator=(local_2b0,pOVar26);
        OdString::~OdString(local_140);
        if (*(uint *)(*plVar22 + -4) <= uVar32) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_138);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_138,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        piVar30 = (int *)(*plVar22 + -0x10);
        iVar16 = *piVar30;
        *piVar30 = *piVar30;
        UNLOCK();
        if (1 < iVar16) {
          local_2c8 = 1;
          FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
        }
        plVar24 = *(longlong **)(*plVar22 + (longlong)plVar31 * 0x10);
        (**(code **)(*plVar24 + 0x168))(plVar24,local_1b0);
      }
      if (*(uint *)(*plVar22 + -4) <= uVar32) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_130);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_130,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar30 = (int *)(*plVar22 + -0x10);
      iVar16 = *piVar30;
      *piVar30 = *piVar30;
      UNLOCK();
      if (1 < iVar16) {
        local_2c8 = 1;
        FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
      }
      iVar16 = (**(code **)(**(longlong **)(*plVar22 + (longlong)plVar31 * 0x10) + 0xb8))();
      if (iVar16 != 0) {
        pOVar26 = (OdString *)FUN_18025f040(param_1,local_128,param_2);
        OdString::operator=(local_2b0,pOVar26);
        OdString::~OdString(local_128);
        if (*(uint *)(*plVar22 + -4) <= uVar32) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_120);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_120,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        piVar30 = (int *)(*plVar22 + -0x10);
        iVar16 = *piVar30;
        *piVar30 = *piVar30;
        UNLOCK();
        if (1 < iVar16) {
          local_2c8 = 1;
          FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
        }
        plVar24 = *(longlong **)(*plVar22 + (longlong)plVar31 * 0x10);
        (**(code **)(*plVar24 + 0x178))(plVar24,local_1bc);
      }
      if (*(uint *)(*plVar22 + -4) <= uVar32) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_118);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_118,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar30 = (int *)(*plVar22 + -0x10);
      iVar16 = *piVar30;
      *piVar30 = *piVar30;
      UNLOCK();
      if (1 < iVar16) {
        local_2c8 = 1;
        FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
      }
      iVar16 = (**(code **)(**(longlong **)(*plVar22 + (longlong)plVar31 * 0x10) + 0xc0))();
      if (iVar16 != 0) {
        pOVar26 = (OdString *)FUN_18025f040(param_1,local_110,param_2);
        OdString::operator=(local_2b0,pOVar26);
        OdString::~OdString(local_110);
        if (*(uint *)(*plVar22 + -4) <= uVar32) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_108);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_108,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        piVar30 = (int *)(*plVar22 + -0x10);
        iVar16 = *piVar30;
        *piVar30 = *piVar30;
        UNLOCK();
        if (1 < iVar16) {
          local_2c8 = 1;
          FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
        }
        plVar24 = *(longlong **)(*plVar22 + (longlong)plVar31 * 0x10);
        (**(code **)(*plVar24 + 0x188))(plVar24,local_1ac);
      }
      if (*(uint *)(*plVar22 + -4) <= uVar32) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_100);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_100,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar30 = (int *)(*plVar22 + -0x10);
      iVar16 = *piVar30;
      *piVar30 = *piVar30;
      UNLOCK();
      if (1 < iVar16) {
        local_2c8 = 1;
        FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
      }
      iVar16 = (**(code **)(**(longlong **)(*plVar22 + (longlong)plVar31 * 0x10) + 200))();
      if (iVar16 != 0) {
        pOVar26 = (OdString *)FUN_18025f040(param_1,local_f8,param_2);
        OdString::operator=(local_2b0,pOVar26);
        OdString::~OdString(local_f8);
        if (*(uint *)(*plVar22 + -4) <= uVar32) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_f0);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_f0,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        piVar30 = (int *)(*plVar22 + -0x10);
        iVar16 = *piVar30;
        *piVar30 = *piVar30;
        UNLOCK();
        if (1 < iVar16) {
          local_2c8 = 1;
          FUN_1800a2420(plVar22,*(undefined4 *)(*plVar22 + -8),0,0);
        }
        plVar22 = *(longlong **)(*plVar22 + (longlong)plVar31 * 0x10);
        (**(code **)(*plVar22 + 0x198))(plVar22,local_1a8);
      }
      uVar18 = (**(code **)(*param_2 + 0x80))(param_2);
      if (uVar17 < uVar18) {
        uVar17 = (**(code **)(*param_2 + 0x80))(param_2);
        local_2a0 = CONCAT44(local_2a0._4_4_,uVar17);
      }
      plVar31 = (longlong *)(ulonglong)(uVar32 + 1);
    }
    OdError_InvalidIndex::OdError_InvalidIndex(local_148);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_148,(ThrowInfo *)&DAT_180de5370);
  }
  local_2a0 = CONCAT44(local_2a0._4_4_,(uint)bVar3);
  plVar22 = plVar31;
  uVar17 = (uint)bVar3;
LAB_180258517:
  local_2b8 = (uint)plVar22;
  if (uVar17 <= local_2b8) goto LAB_180258ebd;
  cVar11 = (**(code **)(*param_2 + 0xa0))(param_2);
  uVar9 = (**(code **)(*param_2 + 0xa0))(param_2);
  plVar22 = plVar31;
  switch(uVar9) {
  case 1:
    uVar23 = OdDgDimOption::createObject((Type)&local_250);
    FUN_1802536b0(param_1 + 0x71,uVar23);
    if (local_250 != (longlong *)0x0) {
      (**(code **)(*local_250 + 0x28))();
      local_250 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x71] + 0x10))((undefined8 *)(param_1[0x71] + 0x10),param_2)
    ;
    if (param_1[0x71] != 0) {
      plVar22 = (longlong *)(param_1[0x71] + 0x10);
    }
    break;
  case 2:
    uVar23 = OdDgDimOption::createObject((Type)&local_200);
    FUN_180253620(param_1 + 0x79,uVar23);
    if (local_200 != (longlong *)0x0) {
      (**(code **)(*local_200 + 0x28))();
      local_200 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x79] + 0x10))((undefined8 *)(param_1[0x79] + 0x10),param_2)
    ;
    if (param_1[0x79] != 0) {
      plVar22 = (longlong *)(param_1[0x79] + 0x10);
    }
    break;
  case 3:
    uVar23 = OdDgDimOption::createObject((Type)&local_258);
    FUN_1802531a0(param_1 + 0x7a,uVar23);
    if (local_258 != (longlong *)0x0) {
      (**(code **)(*local_258 + 0x28))();
      local_258 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x7a] + 0x10))((undefined8 *)(param_1[0x7a] + 0x10),param_2)
    ;
    if (param_1[0x7a] != 0) {
      plVar22 = (longlong *)(param_1[0x7a] + 0x10);
    }
    break;
  case 4:
    uVar23 = OdDgDimOption::createObject((Type)&local_220);
    FUN_180253500(param_1 + 0x7b,uVar23);
    if (local_220 != (longlong *)0x0) {
      (**(code **)(*local_220 + 0x28))();
      local_220 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x7b] + 0x10))((undefined8 *)(param_1[0x7b] + 0x10),param_2)
    ;
    if (param_1[0x7b] != 0) {
      plVar22 = (longlong *)(param_1[0x7b] + 0x10);
    }
    break;
  default:
    plVar24 = (longlong *)FUN_18013c7c0(0x28);
    local_e8 = plVar24;
    if (plVar24 != (longlong *)0x0) {
      plVar24[1] = 0;
      *(undefined1 *)(plVar24 + 2) = 0;
      *plVar24 = (longlong)OdDgDimOptionProxyImpl::vftable;
      *(undefined1 *)(plVar24 + 3) = uVar9;
      pcVar28 = g_empty_array_buffer_exref;
      plVar24[4] = (longlong)(g_empty_array_buffer_exref + 0x10);
      LOCK();
      *(int *)pcVar28 = *(int *)pcVar28 + 1;
      UNLOCK();
      local_2b4 = 0;
      FUN_180075e80(plVar24 + 4,(uint)(byte)(cVar11 - 1) * 2);
      plVar22 = plVar24;
    }
    local_290 = (int *)0x0;
    local_298 = plVar22;
    if (plVar22 != (longlong *)0x0) {
      local_290 = (int *)odrxAlloc(4);
      *local_290 = 1;
    }
    (**(code **)*plVar22)(plVar22,param_2);
    (**(code **)(*plVar22 + 0x20))(plVar22,param_1);
    puVar1 = (ulonglong *)(param_1 + 0x70);
    uVar17 = *(uint *)(*puVar1 - 4);
    LOCK();
    piVar30 = (int *)(*puVar1 - 0x10);
    iVar16 = *piVar30;
    *piVar30 = *piVar30;
    UNLOCK();
    local_2b3 = 1 < iVar16;
    if (((bool)local_2b3) || (uVar17 == *(uint *)(*puVar1 - 8))) {
      if (*(int *)(*puVar1 - 4) != 0) {
        LOCK();
        piVar30 = (int *)(*puVar1 - 0x10);
        iVar16 = *piVar30;
        *piVar30 = *piVar30;
        UNLOCK();
        if (1 < iVar16) {
          local_2c8 = 1;
          FUN_1802570b0(puVar1,*(undefined4 *)(*puVar1 - 8),0);
        }
        if ((*(int *)((longlong)*puVar1 - 4) == 0) || ((longlong **)*puVar1 <= &local_298))
        goto LAB_180258d14;
LAB_180258e0b:
        local_2c8 = 1;
        FUN_1802570b0(puVar1,uVar17 + 1);
        goto LAB_180258e25;
      }
LAB_180258d14:
      if (*(int *)(*puVar1 - 4) == 0) goto LAB_180258e0b;
      LOCK();
      piVar30 = (int *)(*puVar1 - 0x10);
      iVar16 = *piVar30;
      *piVar30 = *piVar30;
      UNLOCK();
      if (1 < iVar16) {
        local_2c8 = 1;
        FUN_1802570b0(puVar1,*(undefined4 *)(*puVar1 - 8),0);
      }
      piVar30 = local_290;
      uVar32 = *(uint *)((longlong)*puVar1 + -4);
      plVar24 = plVar31;
      if (uVar32 != 0) {
        plVar24 = (longlong *)*puVar1;
      }
      if (plVar24 + (ulonglong)uVar32 * 2 <= &local_298) goto LAB_180258e0b;
      local_d0 = local_290;
      if (local_290 != (int *)0x0) {
        *local_290 = *local_290 + 1;
      }
      local_2c8 = 1;
      local_d8 = plVar22;
      FUN_1802570b0(puVar1,uVar17 + 1);
      puVar25 = (undefined8 *)((ulonglong)uVar17 * 0x10 + *puVar1);
      *puVar25 = plVar22;
      puVar25[1] = piVar30;
      if (piVar30 != (int *)0x0) {
        *piVar30 = *piVar30 + 1;
        *piVar30 = *piVar30 + -1;
        if (*piVar30 == 0) {
          pcVar28 = (code *)(plVar22[4] + -0x10);
          LOCK();
          iVar16 = *(int *)pcVar28;
          *(int *)pcVar28 = *(int *)pcVar28 + -1;
          UNLOCK();
          if ((iVar16 == 1) && (pcVar28 != g_empty_array_buffer_exref)) {
            odrxFree();
          }
          FUN_18013c820(plVar22,0x28);
          piVar30 = local_290;
          odrxFree(local_290);
        }
      }
    }
    else {
LAB_180258e25:
      puVar25 = (undefined8 *)((ulonglong)uVar17 * 0x10 + *puVar1);
      *puVar25 = plVar22;
      puVar25[1] = local_290;
      piVar30 = local_290;
      if (local_290 != (int *)0x0) {
        *local_290 = *local_290 + 1;
      }
    }
    *(int *)(*puVar1 - 4) = *(int *)(*puVar1 - 4) + 1;
    if ((piVar30 != (int *)0x0) && (*piVar30 = *piVar30 + -1, *piVar30 == 0)) {
      pcVar28 = (code *)(plVar22[4] + -0x10);
      LOCK();
      iVar16 = *(int *)pcVar28;
      *(int *)pcVar28 = *(int *)pcVar28 + -1;
      UNLOCK();
      if ((iVar16 == 1) && (pcVar28 != g_empty_array_buffer_exref)) {
        odrxFree();
      }
      FUN_18013c820(plVar22,0x28);
      odrxFree(local_290);
    }
    plVar22 = (longlong *)(ulonglong)(local_2b8 + 1);
    uVar17 = (uint)local_2a0;
    goto LAB_180258517;
  case 7:
    uVar23 = OdDgDimOption::createObject((Type)&local_218);
    FUN_180252ff0(param_1 + 0x7c,uVar23);
    if (local_218 != (longlong *)0x0) {
      (**(code **)(*local_218 + 0x28))();
      local_218 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x7c] + 0x10))((undefined8 *)(param_1[0x7c] + 0x10),param_2)
    ;
    if (param_1[0x7c] != 0) {
      plVar22 = (longlong *)(param_1[0x7c] + 0x10);
    }
    break;
  case 8:
    uVar23 = OdDgDimOption::createObject((Type)&local_270);
    FUN_180253110(param_1 + 0x76,uVar23);
    if (local_270 != (longlong *)0x0) {
      (**(code **)(*local_270 + 0x28))();
      local_270 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x76] + 0x10))((undefined8 *)(param_1[0x76] + 0x10),param_2)
    ;
    if (param_1[0x76] != 0) {
      plVar22 = (longlong *)(param_1[0x76] + 0x10);
    }
    break;
  case 9:
    uVar23 = OdDgDimOption::createObject((Type)&local_248);
    FUN_1802532c0(param_1 + 0x74,uVar23);
    if (local_248 != (longlong *)0x0) {
      (**(code **)(*local_248 + 0x28))();
      local_248 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x74] + 0x10))((undefined8 *)(param_1[0x74] + 0x10),param_2)
    ;
    if (param_1[0x74] != 0) {
      plVar22 = (longlong *)(param_1[0x74] + 0x10);
    }
    break;
  case 10:
    uVar23 = OdDgDimOption::createObject((Type)&local_240);
    FUN_180253470(param_1 + 0x75,uVar23);
    if (local_240 != (longlong *)0x0) {
      (**(code **)(*local_240 + 0x28))();
      local_240 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x75] + 0x10))((undefined8 *)(param_1[0x75] + 0x10),param_2)
    ;
    if (param_1[0x75] != 0) {
      plVar22 = (longlong *)(param_1[0x75] + 0x10);
    }
    break;
  case 0xb:
    uVar23 = OdDgDimOption::createObject((Type)&local_1f8);
    FUN_180253590(param_1 + 0x73,uVar23);
    if (local_1f8 != (longlong *)0x0) {
      (**(code **)(*local_1f8 + 0x28))();
      local_1f8 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x73] + 0x10))((undefined8 *)(param_1[0x73] + 0x10),param_2)
    ;
    if (param_1[0x73] != 0) {
      plVar22 = (longlong *)(param_1[0x73] + 0x10);
    }
    break;
  case 0xc:
    uVar23 = OdDgDimOption::createObject((Type)&local_238);
    FUN_180253740(param_1 + 0x72,uVar23);
    if (local_238 != (longlong *)0x0) {
      (**(code **)(*local_238 + 0x28))();
      local_238 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x72] + 0x10))((undefined8 *)(param_1[0x72] + 0x10),param_2)
    ;
    if (param_1[0x72] != 0) {
      plVar22 = (longlong *)(param_1[0x72] + 0x10);
    }
    break;
  case 0xd:
    uVar23 = OdDgDimOption::createObject((Type)&local_230);
    FUN_180253230(param_1 + 0x77,uVar23);
    if (local_230 != (longlong *)0x0) {
      (**(code **)(*local_230 + 0x28))();
      local_230 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x77] + 0x10))((undefined8 *)(param_1[0x77] + 0x10),param_2)
    ;
    if (param_1[0x77] != 0) {
      plVar22 = (longlong *)(param_1[0x77] + 0x10);
    }
    break;
  case 0xe:
    uVar23 = OdDgDimOption::createObject((Type)&local_260);
    FUN_180253080(param_1 + 0x7f,uVar23);
    if (local_260 != (longlong *)0x0) {
      (**(code **)(*local_260 + 0x28))();
      local_260 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x7f] + 0x10))((undefined8 *)(param_1[0x7f] + 0x10),param_2)
    ;
    if (param_1[0x7f] != 0) {
      plVar22 = (longlong *)(param_1[0x7f] + 0x10);
    }
    break;
  case 0xf:
    uVar23 = OdDgDimOption::createObject((Type)&local_228);
    FUN_1802533e0(param_1 + 0x78,uVar23);
    if (local_228 != (longlong *)0x0) {
      (**(code **)(*local_228 + 0x28))();
      local_228 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x78] + 0x10))((undefined8 *)(param_1[0x78] + 0x10),param_2)
    ;
    if (param_1[0x78] != 0) {
      plVar22 = (longlong *)(param_1[0x78] + 0x10);
    }
    break;
  case 0x10:
    uVar23 = OdDgDimOption::createObject((Type)&local_210);
    FUN_180252ed0(param_1 + 0x7d,uVar23);
    if (local_210 != (longlong *)0x0) {
      (**(code **)(*local_210 + 0x28))();
      local_210 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x7d] + 0x10))((undefined8 *)(param_1[0x7d] + 0x10),param_2)
    ;
    if (param_1[0x7d] != 0) {
      plVar22 = (longlong *)(param_1[0x7d] + 0x10);
    }
    break;
  case 0x11:
    uVar23 = OdDgDimOption::createObject((Type)&local_208);
    FUN_180252f60(param_1 + 0x7e,uVar23);
    if (local_208 != (longlong *)0x0) {
      (**(code **)(*local_208 + 0x28))();
      local_208 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x7e] + 0x10))((undefined8 *)(param_1[0x7e] + 0x10),param_2)
    ;
    if (param_1[0x7e] != 0) {
      plVar22 = (longlong *)(param_1[0x7e] + 0x10);
    }
    break;
  case 0x12:
    uVar23 = OdDgDimOption::createObject((Type)&local_268);
    FUN_180253350(param_1 + 0x80,uVar23);
    if (local_268 != (longlong *)0x0) {
      (**(code **)(*local_268 + 0x28))();
      local_268 = (longlong *)0x0;
    }
    (*(code *)**(undefined8 **)(param_1[0x80] + 0x10))((undefined8 *)(param_1[0x80] + 0x10),param_2)
    ;
    if (param_1[0x80] != 0) {
      plVar22 = (longlong *)(param_1[0x80] + 0x10);
    }
  }
  (**(code **)(*plVar22 + 0x20))(plVar22,param_1);
  plVar22 = (longlong *)(ulonglong)(local_2b8 + 1);
  uVar17 = (uint)local_2a0;
  goto LAB_180258517;
}



