/* ==== 1809d9c80 FUN_1809d9c80 ==== */

void FUN_1809d9c80(longlong *param_1,undefined8 param_2,longlong param_3,longlong param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  OdDgElementResolver OVar4;
  char cVar5;
  char cVar6;
  short sVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  __uint64 _Var11;
  OdRxClass *pOVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong *plVar15;
  longlong *plVar16;
  _func_void *p_Var17;
  OdDgElementResolver *pOVar18;
  longlong lVar19;
  OdDbHandle *pOVar20;
  undefined8 *puVar21;
  undefined8 uVar22;
  longlong *plVar23;
  undefined8 uVar24;
  OdRxClass *pOVar25;
  OdDgElementResolver *pOVar26;
  code *pcVar27;
  OdDgElementResolver *pOVar28;
  OdDgElementResolver *pOVar29;
  uint uVar30;
  uint uVar31;
  OdDgElementResolver *pOVar32;
  ulonglong uVar33;
  ulonglong uVar34;
  uint uVar35;
  OdDgElementResolver *pOVar36;
  bool bVar37;
  undefined8 *puVar38;
  uint7 uVar39;
  char local_3c8;
  OdDgElementResolver *local_3c0;
  char local_3b8;
  char local_3b7;
  uint local_3b4;
  longlong local_3b0;
  uint local_3a8;
  uint local_3a4;
  OdDgElementResolver *local_3a0;
  OdDgElementResolver *local_398;
  char local_390;
  int local_38c;
  code *local_388;
  longlong local_380;
  int local_378;
  uint local_374;
  longlong *local_370;
  undefined4 local_368;
  int local_364;
  undefined8 local_360;
  ushort local_358;
  undefined8 local_354;
  int local_34c;
  undefined8 local_348;
  undefined8 local_340;
  uint local_338;
  longlong *local_330;
  OdString local_328 [8];
  uint local_320 [2];
  OdDgElementResolver *local_318;
  OdDgElementResolver local_310;
  longlong local_308;
  longlong local_300;
  longlong local_2f8;
  undefined4 local_2f0 [2];
  longlong *local_2e8;
  longlong *local_2e0;
  OdString local_2d8 [8];
  OdString local_2d0 [8];
  longlong *local_2c8;
  longlong *local_2c0;
  longlong *local_2b8;
  longlong *local_2b0;
  longlong *local_2a8;
  longlong *local_2a0;
  longlong *local_298;
  longlong *local_290;
  longlong *local_288;
  longlong *local_280;
  OdError_NotThatKindOfClass local_278 [8];
  OdError_InvalidIndex local_270 [8];
  OdError_NotThatKindOfClass local_268 [24];
  OdError_InvalidIndex local_250 [8];
  OdError_InvalidIndex local_248 [8];
  OdError_InvalidIndex local_240 [8];
  OdError_InvalidIndex local_238 [8];
  OdError_NotThatKindOfClass local_230 [8];
  OdDgElementResolver *local_228;
  OdError_NotThatKindOfClass local_220 [8];
  longlong *local_218;
  OdError_NotThatKindOfClass local_210 [8];
  OdError_NotThatKindOfClass local_208 [8];
  OdDgElementResolver *local_200;
  OdError_NotThatKindOfClass local_1f8 [8];
  longlong *local_1f0;
  OdError_InvalidIndex local_1e8 [8];
  OdError_InvalidIndex local_1e0 [8];
  OdError_NotThatKindOfClass local_1d8 [8];
  OdError_InvalidIndex local_1d0 [8];
  OdError_InvalidIndex local_1c8 [8];
  longlong *local_1c0;
  OdError_InvalidIndex local_1b8 [8];
  OdError_InvalidIndex local_1b0 [8];
  OdError_InvalidIndex local_1a8 [16];
  OdError_InvalidIndex local_198 [8];
  OdError_InvalidIndex local_190 [16];
  OdError_InvalidIndex local_180 [8];
  OdError_InvalidIndex local_178 [8];
  OdError_NotThatKindOfClass local_170 [8];
  undefined1 local_168 [8];
  OdError_InvalidIndex local_160 [8];
  OdError_InvalidIndex local_158 [8];
  Error local_150 [8];
  OdError_InvalidIndex local_148 [8];
  OdError_InvalidIndex local_140 [8];
  OdError_InvalidIndex local_138 [24];
  OdDgElementResolver *local_120;
  OdError_InvalidIndex local_118 [8];
  OdError_InvalidIndex local_110 [8];
  uint local_108;
  int local_104;
  OdDgElementResolver *local_100;
  OdDgElementResolver local_f8;
  longlong local_f0;
  undefined1 local_e8 [16];
  undefined1 local_d8 [8];
  undefined1 local_d0 [8];
  code *local_c8;
  undefined1 local_c0 [16];
  undefined1 local_b0 [24];
  undefined1 local_98 [8];
  undefined1 local_90 [32];
  undefined1 local_70 [24];
  undefined1 local_58 [32];
  
  pOVar28 = (OdDgElementResolver *)0x0;
  local_3a4 = 0;
  local_380 = *(longlong *)(param_4 + 0x10);
  local_1c0 = *(longlong **)(local_380 + 0xd50);
  local_390 = *(char *)((longlong)local_1c0 + 0x21);
  local_320[0] = 0;
  local_320[1] = 0;
  local_318 = (OdDgElementResolver *)0x0;
  local_310 = (OdDgElementResolver)0x0;
  local_308 = 0;
  local_3c0 = (OdDgElementResolver *)(g_empty_array_buffer_exref + 0x10);
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  FUN_1809e1ca0(&local_3c0);
  local_3a8 = 0;
  local_338 = *(uint *)(param_1[7] + -4);
  if (*(int *)(local_3c0 + -4) == 0) {
    OdError_InvalidIndex::OdError_InvalidIndex(local_110);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_110,(ThrowInfo *)&DAT_180de5370);
  }
  LOCK();
  pOVar26 = local_3c0 + -0x10;
  iVar9 = *(int *)pOVar26;
  *(int *)pOVar26 = *(int *)pOVar26;
  UNLOCK();
  if (1 < iVar9) {
    FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
  }
  pOVar26 = local_3c0;
  *(uint *)(local_3c0 + 4) = local_338;
  Dgn8::Error::Error(local_150,0,"C:\\B\\1\\_\\_\\Dgn\\source\\DgDefsInternal.h",0x134);
  uVar8 = (**(code **)(*param_1 + 0x70))(param_1);
  _Var11 = (**(code **)(*param_1 + 200))(param_1);
  OdFlatMemStream::createNew(&local_2c8,_Var11,(ulonglong)uVar8);
  plVar14 = local_2c8;
  local_2f8 = 0;
  lVar13 = local_2f8;
  if (local_2c8 != (longlong *)0x0) {
    lVar13 = *local_2c8;
    pOVar12 = OdStreamBuf::desc();
    lVar13 = (**(code **)(lVar13 + 8))(plVar14,pOVar12);
    if (lVar13 == 0) {
      pOVar12 = OdStreamBuf::desc();
      pOVar25 = (OdRxClass *)(**(code **)(*plVar14 + 0x18))(plVar14);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_278,pOVar25,pOVar12);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_278,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_2f8 = lVar13;
  OdDgFileFiler::createObject(&local_370,&local_2f8,param_4);
  local_3b7 = '\0';
  local_378 = 0;
  pOVar29 = pOVar28;
  pOVar36 = pOVar28;
LAB_1809d9e24:
  local_3b4 = (uint)pOVar29;
  local_374 = local_3b4;
  if (local_338 <= local_3b4) {
    FUN_18016f6d0(param_1 + 7);
    *(undefined4 *)(param_1[7] + -4) = 0;
    if (local_370 != (longlong *)0x0) {
      (**(code **)(*local_370 + 0x28))();
      local_370 = (longlong *)0x0;
    }
    if (local_2c8 != (longlong *)0x0) {
      (**(code **)(*local_2c8 + 0x28))();
      local_2c8 = (longlong *)0x0;
    }
    pOVar28 = pOVar26 + -0x10;
    LOCK();
    iVar9 = *(int *)pOVar28;
    *(int *)pOVar28 = *(int *)pOVar28 + -1;
    UNLOCK();
    if ((iVar9 == 1) && (pOVar28 != (OdDgElementResolver *)g_empty_array_buffer_exref)) {
      FUN_1809e0c20(pOVar26,*(undefined4 *)(pOVar26 + -4));
      odrxFree(pOVar28);
    }
    if (local_318 != (OdDgElementResolver *)0x0) {
      (**(code **)(*(longlong *)local_318 + 0x28))();
    }
    return;
  }
  local_38c = 0;
  local_364 = 0;
  if (*(uint *)(param_1[7] + -4) <= local_3b4) {
    OdError_InvalidIndex::OdError_InvalidIndex(local_270);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_270,(ThrowInfo *)&DAT_180de5370);
  }
  FUN_18016f6d0(param_1 + 7);
  uVar10 = *(undefined4 *)(param_1[7] + (longlong)pOVar29 * 4);
  local_368 = uVar10;
  (**(code **)(*local_370 + 0x78))(local_370,uVar10,0);
  local_360 = 0;
  local_358 = 0;
  local_354 = 0;
  local_34c = 0;
  local_348 = 0;
  local_340 = 0;
  FUN_1808c5240(&local_360,local_370);
  iVar9 = 0;
  if ((local_358 >> 0xd & 1) != 0) {
    if (((local_358 >> 0xc & 1) != 0) && (local_360._4_4_ != 100)) {
      (**(code **)(*local_370 + 0x78))(local_370,0x48,1);
    }
    iVar9 = (**(code **)(*local_370 + 0xb0))();
    local_38c = iVar9;
    local_364 = iVar9;
  }
  local_398 = (OdDgElementResolver *)0x0;
  local_3b0 = 0;
  local_3a0 = (OdDgElementResolver *)0x0;
  if (local_360._4_4_ == 0x22) {
    local_3b7 = '\x01';
    local_378 = iVar9 + 1;
  }
  plVar14 = (longlong *)0x0;
  local_3b8 = local_390;
  pOVar18 = pOVar28;
  pOVar29 = pOVar28;
  uVar8 = (uint)pOVar36;
  iVar9 = local_360._4_4_;
  if (local_390 != '\0') {
    plVar14 = (longlong *)(**(code **)(*param_1 + 0xb0))(param_1,&local_2a8);
    plVar23 = local_370;
    pcVar27 = g_empty_array_buffer_exref;
    local_3c8 = '\x01';
    if (((local_360._4_4_ - 0x60U < 2) || (local_360._4_4_ == 9)) || (local_360._4_4_ == 5)) {
LAB_1809da122:
      local_3c8 = '\0';
      pOVar18 = (OdDgElementResolver *)0x0;
      pOVar29 = (OdDgElementResolver *)0x0;
    }
    else if (local_360._4_4_ == 0x42) {
      (**(code **)(*local_370 + 0x80))(local_370);
      if ((local_358 >> 0xc & 1) != 0) {
        (**(code **)(*plVar23 + 0x78))(plVar23,0x48,1);
      }
      if ((local_358 >> 0xe & 1) != 0) {
        (**(code **)(*plVar23 + 0x78))(plVar23,4,1);
      }
      plVar14 = (longlong *)(**(code **)(*plVar23 + 0xa8))(plVar23);
      sVar7 = (short)plVar14;
      if (((sVar7 == 0x583b) || (sVar7 == 0x5842)) || ((sVar7 == 0x56e6 || (sVar7 == 0x571a)))) {
        local_3c8 = '\0';
      }
    }
    else if (local_360._4_4_ == 0x5f) {
      plVar14 = (longlong *)(ulonglong)(local_34c - 1U);
      if ((local_34c - 1U & 0xfffffff7) == 0) goto LAB_1809da122;
    }
    else if (local_360._4_4_ == 0x6b) {
      local_c8 = g_empty_array_buffer_exref + 0x10;
      local_388 = g_empty_array_buffer_exref;
      LOCK();
      *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
      UNLOCK();
      if (*plVar14 == 0) {
        local_3c8 = '\x01';
      }
      else {
        FUN_1809d9350(&local_2b0,plVar14);
        plVar23 = local_2b0;
        FUN_1809ea9f0(local_2b0,&local_330,&local_348);
        plVar14 = local_330;
        if (local_330 != (longlong *)0x0) {
          lVar13 = local_330[4];
          uVar8 = *(uint *)(lVar13 + -4);
          pOVar26 = pOVar28;
          if (uVar8 != 0) {
            do {
              uVar31 = (uint)pOVar26;
              if (uVar8 <= uVar31) {
                OdError_InvalidIndex::OdError_InvalidIndex(local_238);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(local_238,(ThrowInfo *)&DAT_180de5370);
              }
              if (*(int *)(lVar13 + (longlong)pOVar26 * 0x18) == 0x58750001) {
LAB_1809da35b:
                local_3c8 = '\0';
                pcVar27 = local_388;
                break;
              }
              if (uVar8 <= uVar31) {
                OdError_InvalidIndex::OdError_InvalidIndex(local_240);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(local_240,(ThrowInfo *)&DAT_180de5370);
              }
              if (*(int *)(lVar13 + (longlong)pOVar26 * 0x18) == 0x58660000) goto LAB_1809da35b;
              if (uVar8 <= uVar31) {
                OdError_InvalidIndex::OdError_InvalidIndex(local_248);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(local_248,(ThrowInfo *)&DAT_180de5370);
              }
              if (*(int *)(lVar13 + (longlong)pOVar26 * 0x18) == 0x56ec0000) {
                if (uVar8 <= uVar31) {
                  OdError_InvalidIndex::OdError_InvalidIndex(local_250);
                    /* WARNING: Subroutine does not return */
                  _CxxThrowException(local_250,(ThrowInfo *)&DAT_180de5370);
                }
                uVar22 = FUN_18081da20();
                plVar15 = (longlong *)
                          FUN_18081d860(uVar22,&local_2b8,
                                        *(undefined4 *)(lVar13 + (longlong)pOVar26 * 0x18),
                                        *(undefined4 *)(lVar13 + 4 + (longlong)pOVar26 * 0x18),
                                        lVar13 + ((longlong)pOVar26 * 3 + 2) * 8,0);
                local_2e8 = (longlong *)0x0;
                plVar15 = (longlong *)*plVar15;
                plVar16 = local_2e8;
                if (plVar15 != (longlong *)0x0) {
                  lVar13 = *plVar15;
                  pOVar12 = OdDgExtendedElementTypeXAttribute::desc();
                  plVar16 = (longlong *)(**(code **)(lVar13 + 8))(plVar15,pOVar12);
                  if (plVar16 == (longlong *)0x0) {
                    pOVar12 = OdDgExtendedElementTypeXAttribute::desc();
                    pOVar25 = (OdRxClass *)(**(code **)(*plVar15 + 0x18))(plVar15);
                    OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                              (local_268,pOVar25,pOVar12);
                    /* WARNING: Subroutine does not return */
                    _CxxThrowException(local_268,(ThrowInfo *)&DAT_180de5310);
                  }
                }
                local_2e8 = plVar16;
                plVar15 = local_2e8;
                if (local_2b8 != (longlong *)0x0) {
                  (**(code **)(*local_2b8 + 0x28))();
                  local_2b8 = (longlong *)0x0;
                }
                if (plVar15 != (longlong *)0x0) {
                  iVar9 = (**(code **)(*plVar15 + 0x80))(plVar15);
                  if (iVar9 == -0x13c60000) {
                    local_3c8 = '\0';
                  }
                  else {
                    if (((iVar9 != 0x6b0002) && (iVar9 != 0x58e40005)) && (iVar9 != 0x58ec0015))
                    goto LAB_1809da2c1;
                    local_3c8 = '\x01';
                  }
                  (**(code **)(*plVar15 + 0x28))(plVar15);
                  local_2e8 = (longlong *)0x0;
                  pcVar27 = local_388;
                  break;
                }
LAB_1809da2c1:
                if (plVar15 != (longlong *)0x0) {
                  (**(code **)(*plVar15 + 0x28))(plVar15);
                  local_2e8 = (longlong *)0x0;
                }
              }
              pOVar26 = (OdDgElementResolver *)(ulonglong)(uVar31 + 1);
              lVar13 = plVar14[4];
              uVar8 = *(uint *)(lVar13 + -4);
              pcVar27 = local_388;
            } while (uVar31 + 1 < uVar8);
          }
        }
        if (local_330 != (longlong *)0x0) {
          (**(code **)(*local_330 + 0x28))(local_330);
          local_330 = (longlong *)0x0;
        }
        if (plVar23 != (longlong *)0x0) {
          (**(code **)(*plVar23 + 0x28))(plVar23);
          local_2b0 = (longlong *)0x0;
        }
      }
      plVar14 = (longlong *)FUN_1800144b0(pcVar27);
      pOVar26 = local_3c0;
      pOVar18 = local_398;
      pOVar29 = local_3a0;
    }
    uVar10 = local_368;
    uVar8 = local_3a8;
    iVar9 = local_360._4_4_;
    local_3b8 = local_3c8;
    if (local_2a8 != (longlong *)0x0) {
      plVar14 = (longlong *)(**(code **)(*local_2a8 + 0x28))();
      local_2a8 = (longlong *)0x0;
      uVar10 = local_368;
      uVar8 = local_3a8;
      iVar9 = local_360._4_4_;
    }
  }
  local_388 = (code *)CONCAT44(local_388._4_4_,(int)(((ulonglong)plVar14 >> 8) << 8));
  if (local_3b8 == '\0') {
    if (((param_3 != 0) || (uVar8 != 0)) || (iVar9 == 0x27)) {
      local_388 = (code *)CONCAT44(local_388._4_4_,(int)(((ulonglong)plVar14 >> 8) << 8));
      goto LAB_1809da3a7;
    }
    cVar5 = '\x01';
    uVar10 = local_368;
LAB_1809dae86:
    puVar38 = &local_360;
    puVar21 = (undefined8 *)FUN_1809df950(param_1,&local_280,uVar10,param_4,puVar38,0);
    pOVar36 = (OdDgElementResolver *)*puVar21;
    if (pOVar36 != (OdDgElementResolver *)0x0) {
      local_3a0 = pOVar36;
      (**(code **)(*(longlong *)pOVar36 + 0x20))();
      pOVar29 = pOVar36;
    }
    if (local_280 != (longlong *)0x0) {
      (**(code **)(*local_280 + 0x28))();
      local_280 = (longlong *)0x0;
    }
    if (pOVar29 == (OdDgElementResolver *)0x0) {
      if ((local_358 >> 0xd & 1) != 0) {
        local_3b4 = local_3b4 + local_38c;
      }
    }
    else {
      uVar33 = (ulonglong)puVar38 & 0xffffffff00000000;
      plVar14 = (longlong *)
                __RTDynamicCast(*(longlong *)(pOVar29 + 8),0,&OdDgElementImpl::RTTI_Type_Descriptor,
                                &CDGElementGeneral::RTTI_Type_Descriptor,uVar33);
      if ((plVar14 != (longlong *)0x0) && (param_3 != 0)) {
        (**(code **)(*plVar14 + 0x480))(plVar14,param_3 + 0x58);
      }
      uVar8 = local_3a8;
      uVar34 = (ulonglong)local_3a8;
      if (local_3a8 == 0) {
        uVar22 = (**(code **)(*(longlong *)pOVar29 + 0x120))(pOVar29,local_b0);
        FUN_180013b80(param_2,uVar22);
        if (param_3 != 0) {
          (**(code **)(*(longlong *)pOVar29 + 0x118))(pOVar29,*(undefined8 *)(param_3 + 0x58));
        }
      }
      else {
        if (*(uint *)(pOVar26 + -4) <= local_3a8) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_198);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_198,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        pOVar26 = pOVar26 + -0x10;
        iVar9 = *(int *)pOVar26;
        *(int *)pOVar26 = *(int *)pOVar26;
        UNLOCK();
        if (1 < iVar9) {
          uVar33 = CONCAT71((int7)(uVar33 >> 8),1);
          FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,uVar33);
        }
        pOVar26 = local_3c0;
        lVar13 = uVar34 * 0x20;
        uVar39 = (uint7)(uVar33 >> 8);
        if (local_3c0[lVar13 + 0x10] == (OdDgElementResolver)0x0) {
          if (*(uint *)(local_3c0 + -4) <= uVar8) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_190);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_190,(ThrowInfo *)&DAT_180de5370);
          }
          LOCK();
          pOVar26 = local_3c0 + -0x10;
          iVar9 = *(int *)pOVar26;
          *(int *)pOVar26 = *(int *)pOVar26;
          UNLOCK();
          if (1 < iVar9) {
            FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,CONCAT71(uVar39,1));
          }
          pOVar29 = local_3a0;
          pOVar26 = local_3c0;
          FUN_180113970(*(undefined8 *)(local_3c0 + lVar13 + 8),local_3a0);
          pOVar18 = local_398;
        }
        else {
          FUN_1806175e0(local_168,param_4,local_3a0,local_348,(ulonglong)uVar39 << 8);
          lVar19 = *(longlong *)(pOVar29 + 8);
          if (*(uint *)(pOVar26 + -4) <= uVar8) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_180);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_180,(ThrowInfo *)&DAT_180de5370);
          }
          LOCK();
          pOVar26 = pOVar26 + -0x10;
          iVar9 = *(int *)pOVar26;
          *(int *)pOVar26 = *(int *)pOVar26;
          UNLOCK();
          if (1 < iVar9) {
            FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
          }
          pOVar26 = local_3c0;
          FUN_1801d0e00(lVar19,local_3c0 + lVar13 + 0x18);
          if (*(uint *)(pOVar26 + -4) <= uVar8) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_178);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_178,(ThrowInfo *)&DAT_180de5370);
          }
          LOCK();
          pOVar26 = pOVar26 + -0x10;
          iVar9 = *(int *)pOVar26;
          *(int *)pOVar26 = *(int *)pOVar26;
          UNLOCK();
          if (1 < iVar9) {
            FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
          }
          pOVar26 = local_3c0;
          local_2c0 = (longlong *)0x0;
          plVar14 = *(longlong **)(*(longlong *)(local_3c0 + lVar13 + 0x18) + 0x18);
          plVar23 = local_2c0;
          if (plVar14 != (longlong *)0x0) {
            lVar13 = *plVar14;
            pOVar12 = OdRxObject::desc();
            plVar23 = (longlong *)(**(code **)(lVar13 + 8))(plVar14,pOVar12);
            if (plVar23 == (longlong *)0x0) {
              pOVar12 = OdRxObject::desc();
              pOVar25 = (OdRxClass *)(**(code **)(*plVar14 + 0x18))(plVar14);
              OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_170,pOVar25,pOVar12);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(local_170,(ThrowInfo *)&DAT_180de5310);
            }
          }
          local_2c0 = plVar23;
          plVar14 = local_2c0;
          uVar22 = (**(code **)(*local_2c0 + 0x78))(local_2c0);
          FUN_180013b80(uVar22,local_168);
          (**(code **)(*plVar14 + 0x28))(plVar14);
          local_2c0 = (longlong *)0x0;
          pOVar18 = local_398;
          pOVar29 = local_3a0;
        }
      }
      lVar13 = local_380;
      cVar6 = local_3b7;
      local_3b7 = cVar6;
      if (*(char *)(local_380 + 0xd10) != '\0') {
        if (param_3 == 0) {
          if (local_3b7 != '\0') {
            uVar22 = (**(code **)(*(longlong *)pOVar29 + 0x120))(pOVar29,local_90);
            FUN_1802b8480(lVar13 + 0xd28,uVar22);
            local_378 = local_378 + -1;
            local_3b7 = cVar6;
            if (local_378 == 0) {
              local_3b7 = '\0';
            }
          }
        }
        else {
          uVar22 = (**(code **)(*(longlong *)pOVar29 + 0x120))(pOVar29,local_98);
          uVar24 = FUN_1809e1c20(lVar13 + 0xd20);
          FUN_1802b8480(uVar24,uVar22);
        }
      }
    }
    if ((cVar5 != '\0') && (uVar8 = local_3b4, pOVar29 == (OdDgElementResolver *)0x0))
    goto LAB_1809db4e0;
  }
  else {
LAB_1809da3a7:
    OdString::init(local_2d0);
    if (local_3b8 == '\0') {
LAB_1809da63f:
      pOVar36 = (OdDgElementResolver *)odrxAlloc(0x30);
      if (pOVar36 == (OdDgElementResolver *)0x0) {
        p_Var17 = std::get_new_handler();
        if (p_Var17 == (_func_void *)0x0) {
          FUN_1800044e0(local_58);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_58,(ThrowInfo *)&DAT_180de5280);
        }
        (*p_Var17)();
      }
      uVar8 = local_3a4;
      pOVar32 = pOVar28;
      if (pOVar36 != (OdDgElementResolver *)0x0) {
        *(undefined ***)pOVar36 = OdDgElementMTResolver::vftable;
        *(longlong *)(pOVar36 + 8) = 0;
        pcVar27 = g_empty_array_buffer_exref;
        *(code **)(pOVar36 + 0x20) = g_empty_array_buffer_exref + 0x10;
        LOCK();
        *(int *)pcVar27 = *(int *)pcVar27 + 1;
        UNLOCK();
        *(longlong *)(pOVar36 + 0x18) = 0;
        *(undefined ***)pOVar36 =
             OdRxObjectImpl<OdDgElementMTResolver,OdDgElementMTResolver>::vftable;
        *(undefined4 *)(pOVar36 + 0x28) = 0xffffffff;
        *(undefined4 *)(pOVar36 + 0x28) = 0;
        LOCK();
        *(undefined4 *)(pOVar36 + 0x28) = 1;
        UNLOCK();
        pOVar26 = local_3c0;
        pOVar18 = local_398;
        pOVar32 = pOVar36;
        pOVar29 = local_3a0;
      }
      local_3a4 = local_3a4 | 8;
      local_288 = (longlong *)0x0;
      plVar14 = local_288;
      local_200 = pOVar32;
      if (pOVar32 != (OdDgElementResolver *)0x0) {
        lVar13 = *(longlong *)pOVar32;
        pOVar12 = OdRxObject::desc();
        plVar14 = (longlong *)(**(code **)(lVar13 + 8))(pOVar32,pOVar12);
        if (plVar14 == (longlong *)0x0) {
          pOVar12 = OdRxObject::desc();
          pOVar25 = (OdRxClass *)(**(code **)(*(longlong *)pOVar32 + 0x18))(pOVar32);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_208,pOVar25,pOVar12);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_208,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_288 = plVar14;
      plVar14 = local_288;
      if (pOVar32 != (OdDgElementResolver *)0x0) {
        (**(code **)(*(longlong *)pOVar32 + 0x28))(pOVar32);
        local_200 = (OdDgElementResolver *)0x0;
      }
      local_1f0 = plVar14;
      if (plVar14 != (longlong *)0x0) {
        (**(code **)(*plVar14 + 0x20))(plVar14);
      }
      pOVar36 = local_398;
      if (plVar14 != (longlong *)0x0) {
        local_3a4 = uVar8 | 0xc;
        (**(code **)(*plVar14 + 0x28))(plVar14);
        local_288 = (longlong *)0x0;
        lVar13 = *plVar14;
        pOVar12 = OdRxObject::desc();
        pOVar18 = (OdDgElementResolver *)(**(code **)(lVar13 + 8))(plVar14,pOVar12);
        pOVar36 = pOVar18;
        if (pOVar18 == (OdDgElementResolver *)0x0) {
          pOVar12 = OdRxObject::desc();
          pOVar25 = (OdRxClass *)(**(code **)(*plVar14 + 0x18))(plVar14);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1f8,pOVar25,pOVar12);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_1f8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_398 = pOVar36;
      local_3a4 = (uVar8 | 0xc) & 0xfffffffb;
      if (plVar14 != (longlong *)0x0) {
        (**(code **)(*plVar14 + 0x28))(plVar14);
        local_1f0 = (longlong *)0x0;
      }
      if (param_3 != 0) {
        (**(code **)(*(longlong *)pOVar18 + 0x60))(pOVar18,param_3 + 0x58);
      }
      (**(code **)(*(longlong *)pOVar18 + 0x70))(pOVar18,param_1);
    }
    else {
      uVar22 = (**(code **)(*param_1 + 0xb0))(param_1,&local_2a0);
      FUN_1809e1180(&local_360,&local_370,uVar22,uVar10,local_2d0,local_2f0,&local_3b8);
      if (local_2a0 != (longlong *)0x0) {
        (**(code **)(*local_2a0 + 0x28))();
        local_2a0 = (longlong *)0x0;
      }
      if (local_3b8 == '\0') goto LAB_1809da63f;
      pOVar36 = (OdDgElementResolver *)odrxAlloc(0x68);
      if (pOVar36 == (OdDgElementResolver *)0x0) {
        p_Var17 = std::get_new_handler();
        if (p_Var17 == (_func_void *)0x0) {
          FUN_1800044e0(local_70);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_70,(ThrowInfo *)&DAT_180de5280);
        }
        (*p_Var17)();
      }
      pOVar32 = pOVar28;
      local_120 = pOVar36;
      if (pOVar36 != (OdDgElementResolver *)0x0) {
        OdDgElementResolver::OdDgElementResolver(pOVar36);
        *(undefined ***)pOVar36 = OdRxObjectImpl<OdDgElementResolver,OdDgElementResolver>::vftable;
        *(undefined4 *)(pOVar36 + 0x60) = 0xffffffff;
        *(undefined4 *)(pOVar36 + 0x60) = 0;
        LOCK();
        *(undefined4 *)(pOVar36 + 0x60) = 1;
        UNLOCK();
        pOVar26 = local_3c0;
        pOVar18 = local_398;
        pOVar32 = pOVar36;
        pOVar29 = local_3a0;
      }
      uVar8 = local_3a4;
      local_3a4 = local_3a4 | 2;
      local_298 = (longlong *)0x0;
      plVar14 = local_298;
      local_228 = pOVar32;
      if (pOVar32 != (OdDgElementResolver *)0x0) {
        lVar13 = *(longlong *)pOVar32;
        pOVar12 = OdRxObject::desc();
        plVar14 = (longlong *)(**(code **)(lVar13 + 8))(pOVar32,pOVar12);
        if (plVar14 == (longlong *)0x0) {
          pOVar12 = OdRxObject::desc();
          pOVar25 = (OdRxClass *)(**(code **)(*(longlong *)pOVar32 + 0x18))(pOVar32);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_230,pOVar25,pOVar12);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_230,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_298 = plVar14;
      plVar14 = local_298;
      if (pOVar32 != (OdDgElementResolver *)0x0) {
        (**(code **)(*(longlong *)pOVar32 + 0x28))(pOVar32);
        local_228 = (OdDgElementResolver *)0x0;
      }
      local_218 = plVar14;
      if (plVar14 != (longlong *)0x0) {
        (**(code **)(*plVar14 + 0x20))(plVar14);
      }
      pOVar36 = local_398;
      if (plVar14 != (longlong *)0x0) {
        local_3a4 = uVar8 | 3;
        (**(code **)(*plVar14 + 0x28))(plVar14);
        local_298 = (longlong *)0x0;
        lVar13 = *plVar14;
        pOVar12 = OdRxObject::desc();
        pOVar18 = (OdDgElementResolver *)(**(code **)(lVar13 + 8))(plVar14,pOVar12);
        pOVar36 = pOVar18;
        if (pOVar18 == (OdDgElementResolver *)0x0) {
          pOVar12 = OdRxObject::desc();
          pOVar25 = (OdRxClass *)(**(code **)(*plVar14 + 0x18))(plVar14);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_220,pOVar25,pOVar12);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_220,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_398 = pOVar36;
      local_3a4 = (uVar8 | 3) & 0xfffffffe;
      if (plVar14 != (longlong *)0x0) {
        (**(code **)(*plVar14 + 0x28))(plVar14);
        local_218 = (longlong *)0x0;
      }
      local_290 = (longlong *)0x0;
      plVar14 = local_290;
      if (pOVar18 != (OdDgElementResolver *)0x0) {
        lVar13 = *(longlong *)pOVar18;
        pOVar12 = OdRxObject::desc();
        plVar14 = (longlong *)(**(code **)(lVar13 + 8))(pOVar18,pOVar12);
        if (plVar14 == (longlong *)0x0) {
          pOVar12 = OdRxObject::desc();
          pOVar25 = (OdRxClass *)(**(code **)(*(longlong *)pOVar18 + 0x18))(pOVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_210,pOVar25,pOVar12);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_210,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_290 = plVar14;
      plVar14 = local_290;
      uVar10 = (**(code **)(*param_1 + 0xb8))();
      *(undefined4 *)(plVar14 + 7) = uVar10;
      OdString::operator=((OdString *)(plVar14 + 9),local_2d0);
      *(undefined4 *)(plVar14 + 10) = local_2f0[0];
      *(int *)(plVar14 + 5) = local_360._4_4_;
      if (param_3 != 0) {
        (**(code **)(*plVar14 + 0x60))(plVar14,param_3 + 0x58);
      }
      (**(code **)(*plVar14 + 0x70))(plVar14,0);
      (**(code **)(*plVar14 + 0x28))(plVar14);
      local_290 = (longlong *)0x0;
    }
    uVar10 = local_368;
    (**(code **)(*(longlong *)pOVar18 + 0x88))(pOVar18,local_368);
    uVar8 = local_3a8;
    uVar33 = (ulonglong)local_3a8;
    if (local_3a8 == 0) {
      plVar14 = (longlong *)FUN_180617b00(local_e8,param_4);
      local_3b0 = *plVar14;
      cVar5 = (**(code **)(*(longlong *)pOVar18 + 0x90))(pOVar18);
      if (cVar5 != '\0') {
        *(longlong *)(pOVar18 + 0x30) = local_3b0;
      }
      if (local_3b0 != 0) {
        if ((local_360._4_4_ == 0x27) && (param_3 == 0)) {
          FUN_180013b80(*(longlong *)(*(longlong *)(local_380 + 0x208) + 8) + 0xb0,&local_3b0);
          cVar5 = (char)local_388;
        }
        else {
          FUN_180013b80(param_2,&local_3b0);
          cVar5 = (char)local_388;
          if (param_3 != 0) {
            *(undefined8 *)(local_3b0 + 0x20) = *(undefined8 *)(param_3 + 0x58);
          }
        }
        goto LAB_1809dab49;
      }
      cVar5 = '\x01';
    }
    else {
      if (*(uint *)(pOVar26 + -4) <= local_3a8) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_1e8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_1e8,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      pOVar26 = pOVar26 + -0x10;
      iVar9 = *(int *)pOVar26;
      *(int *)pOVar26 = *(int *)pOVar26;
      UNLOCK();
      if (1 < iVar9) {
        FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
      }
      pOVar18 = local_398;
      pOVar26 = local_3c0;
      lVar13 = uVar33 * 0x20;
      if (local_3c0[lVar13 + 0x10] == (OdDgElementResolver)0x0) {
        if (*(uint *)(local_3c0 + -4) <= uVar8) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_1c8);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_1c8,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        pOVar26 = local_3c0 + -0x10;
        iVar9 = *(int *)pOVar26;
        *(int *)pOVar26 = *(int *)pOVar26;
        UNLOCK();
        if (1 < iVar9) {
          FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
        }
        pOVar18 = local_398;
        pOVar26 = local_3c0;
        plVar14 = (longlong *)FUN_180113aa0(local_d0,*(undefined8 *)(local_3c0 + lVar13 + 8));
        local_3b0 = *plVar14;
        cVar5 = (**(code **)(*(longlong *)pOVar18 + 0x90))(pOVar18);
        if (cVar5 != '\0') {
          *(longlong *)(pOVar18 + 0x30) = local_3b0;
        }
        uVar8 = (uint)local_388 & 0xff;
        if (local_3b0 == 0) {
          uVar8 = 1;
        }
LAB_1809daaee:
        local_388 = (code *)CONCAT44(local_388._4_4_,uVar8);
      }
      else {
        plVar14 = (longlong *)FUN_180617b00(local_d8,param_4);
        local_3b0 = *plVar14;
        lVar19 = (**(code **)(*(longlong *)pOVar18 + 0x90))(pOVar18);
        if ((char)lVar19 != '\0') {
          *(longlong *)(pOVar18 + 0x30) = local_3b0;
          lVar19 = local_3b0;
        }
        if (local_3b0 == 0) {
          uVar8 = (uint)CONCAT71((int7)((ulonglong)lVar19 >> 8),1);
          goto LAB_1809daaee;
        }
        if (*(uint *)(pOVar26 + -4) <= uVar8) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_1e0);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_1e0,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        pOVar26 = pOVar26 + -0x10;
        iVar9 = *(int *)pOVar26;
        *(int *)pOVar26 = *(int *)pOVar26;
        UNLOCK();
        if (1 < iVar9) {
          FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
        }
        pOVar26 = local_3c0;
        local_2e0 = (longlong *)0x0;
        plVar14 = *(longlong **)(*(longlong *)(local_3c0 + lVar13 + 0x18) + 0x18);
        plVar23 = local_2e0;
        if (plVar14 != (longlong *)0x0) {
          pOVar12 = OdRxObject::desc();
          plVar23 = (longlong *)(**(code **)(*plVar14 + 8))(plVar14,pOVar12);
          if (plVar23 == (longlong *)0x0) {
            pOVar12 = OdRxObject::desc();
            pOVar25 = (OdRxClass *)(**(code **)(*plVar14 + 0x18))(plVar14);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1d8,pOVar25,pOVar12);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1d8,(ThrowInfo *)&DAT_180de5310);
          }
        }
        local_2e0 = plVar23;
        uVar22 = (**(code **)(*local_2e0 + 0x78))(local_2e0);
        FUN_180013b80(uVar22,&local_3b0);
        if (*(uint *)(pOVar26 + -4) <= uVar8) {
          OdError_InvalidIndex::OdError_InvalidIndex(local_1d0);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_1d0,(ThrowInfo *)&DAT_180de5370);
        }
        LOCK();
        pOVar26 = pOVar26 + -0x10;
        iVar9 = *(int *)pOVar26;
        *(int *)pOVar26 = *(int *)pOVar26;
        UNLOCK();
        if (1 < iVar9) {
          FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
        }
        pOVar26 = local_3c0;
        *(undefined8 *)(local_3b0 + 0x20) = *(undefined8 *)(local_3c0 + lVar13 + 0x18);
        (**(code **)(*local_2e0 + 0x28))();
        local_2e0 = (longlong *)0x0;
        pOVar18 = local_398;
      }
      pOVar29 = local_3a0;
      cVar5 = (char)local_388;
LAB_1809dab49:
      uVar8 = local_3a8;
      if (local_3b0 != 0) {
        if (local_3b8 == '\0') {
          if (*(char *)(local_380 + 0xd10) == '\0') {
            cVar6 = (**(code **)(*(longlong *)pOVar18 + 0x90))(pOVar18);
            if (cVar6 == '\0') {
              lVar13 = local_380 + 0xd30;
              goto LAB_1809dabe5;
            }
          }
          else if (param_3 == 0) {
            if (local_3b7 != '\0') {
              FUN_180013b80(local_380 + 0xd28,&local_3b0);
              local_378 = local_378 + -1;
              if (local_378 == 0) {
                local_3b7 = '\0';
                (**(code **)(*local_1c0 + 0x58))(local_1c0,&local_3b0);
                goto LAB_1809dae70;
              }
            }
          }
          else {
            lVar13 = FUN_1809e1c20(local_380 + 0xd20);
LAB_1809dabe5:
            FUN_180013b80(lVar13,&local_3b0);
          }
          (**(code **)(*local_1c0 + 0x58))(local_1c0,&local_3b0);
        }
        else if ((local_360._4_4_ - 100U & 0xfffffff7) == 0) {
          local_300 = 0;
          uVar33 = (ulonglong)local_3a8;
          if (local_3a8 != 0) {
            if (*(uint *)(pOVar26 + -4) <= local_3a8) {
              OdError_InvalidIndex::OdError_InvalidIndex(local_1b8);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5370);
            }
            LOCK();
            pOVar26 = pOVar26 + -0x10;
            iVar9 = *(int *)pOVar26;
            *(int *)pOVar26 = *(int *)pOVar26;
            UNLOCK();
            if (1 < iVar9) {
              FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
            }
            lVar13 = uVar33 * 0x20;
            if (local_3c0[lVar13 + 0x10] == (OdDgElementResolver)0x0) {
              if (*(uint *)(local_3c0 + -4) <= uVar8) {
                OdError_InvalidIndex::OdError_InvalidIndex(local_1a8);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(local_1a8,(ThrowInfo *)&DAT_180de5370);
              }
              LOCK();
              pOVar26 = local_3c0 + -0x10;
              iVar9 = *(int *)pOVar26;
              *(int *)pOVar26 = *(int *)pOVar26;
              UNLOCK();
              if (1 < iVar9) {
                FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
              }
              pOVar26 = local_3c0;
              plVar14 = (longlong *)
                        (**(code **)(**(longlong **)(local_3c0 + lVar13 + 8) + 0x120))
                                  (*(longlong **)(local_3c0 + lVar13 + 8),local_c0);
              local_300 = *plVar14;
              pOVar18 = local_398;
              pOVar29 = local_3a0;
            }
            else {
              if (*(uint *)(local_3c0 + -4) <= uVar8) {
                OdError_InvalidIndex::OdError_InvalidIndex(local_1b0);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(local_1b0,(ThrowInfo *)&DAT_180de5370);
              }
              LOCK();
              pOVar26 = local_3c0 + -0x10;
              iVar9 = *(int *)pOVar26;
              *(int *)pOVar26 = *(int *)pOVar26;
              UNLOCK();
              if (1 < iVar9) {
                FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
              }
              local_300 = *(longlong *)(local_3c0 + lVar13 + 0x18);
              pOVar26 = local_3c0;
              pOVar18 = local_398;
              pOVar29 = local_3a0;
            }
          }
          bVar37 = false;
          if (local_360._4_4_ == 0x6c) {
            (**(code **)(*local_370 + 0x78))(local_370,uVar10,0);
            bVar37 = local_360._4_4_ == 0x6c;
          }
          OdString::init(local_328);
          if ((bVar37) && (local_300 != 0)) {
            pOVar20 = OdDgElementId::getHandle((OdDgElementId *)&local_300);
            OdString::format(local_328,(ushort *)L"%lld",*(undefined8 *)pOVar20);
            (**(code **)(*local_370 + 0x78))(local_370,0x2c,1);
            pOVar36 = pOVar28;
            do {
              lVar13 = (**(code **)(*local_370 + 0xb8))();
              if (lVar13 == 0) break;
              OdString::init(local_2d8);
              OdString::format(local_2d8,(ushort *)L"_%lld",lVar13);
              OdString::operator+=(local_328,local_2d8);
              OdString::~OdString(local_2d8);
              uVar8 = (int)pOVar36 + 1;
              pOVar36 = (OdDgElementResolver *)(ulonglong)uVar8;
            } while (uVar8 < 0x14);
          }
          else {
            pOVar20 = OdDgElementId::getHandle((OdDgElementId *)&local_3b0);
            OdString::format(local_328,(ushort *)L"%lld",*(undefined8 *)pOVar20);
          }
          FUN_18058aba0(local_380,local_328);
          OdString::~OdString(local_328);
          cVar5 = (char)local_388;
        }
      }
    }
LAB_1809dae70:
    OdString::~OdString(local_2d0);
    if (cVar5 != '\0') goto LAB_1809dae86;
  }
  iVar9 = local_38c;
  uVar8 = local_3b4;
  if ((local_358 >> 0xd & 1) == 0) goto LAB_1809db4e0;
  local_3a8 = local_3a8 + 1;
  local_320[1] = local_38c;
  local_320[0] = local_3b4;
  if (pOVar18 == (OdDgElementResolver *)0x0) {
    if (pOVar29 != (OdDgElementResolver *)0x0) {
      if (local_318 != pOVar29) {
        if (local_318 != (OdDgElementResolver *)0x0) {
          (**(code **)(*(longlong *)local_318 + 0x28))();
        }
        local_318 = pOVar29;
        (**(code **)(*(longlong *)pOVar29 + 0x20))(pOVar29);
      }
      local_310 = (OdDgElementResolver)0x0;
    }
  }
  else {
    local_308 = local_3b0;
    local_310 = (OdDgElementResolver)0x1;
  }
  uVar31 = *(uint *)(pOVar26 + -4);
  pOVar29 = pOVar26 + -0x10;
  LOCK();
  iVar1 = *(int *)pOVar29;
  *(int *)pOVar29 = *(int *)pOVar29;
  UNLOCK();
  if ((1 < iVar1) || (uVar31 == *(uint *)(local_3c0 + -8))) {
    pOVar36 = pOVar28;
    if (*(uint *)(pOVar26 + -4) == 0) {
LAB_1809db3a3:
      pOVar29 = local_318;
      if ((OdDgElementResolver *)local_320 < pOVar36) {
        local_108 = uVar8;
        local_104 = iVar9;
        local_100 = local_318;
        if (local_318 != (OdDgElementResolver *)0x0) {
          (**(code **)(*(longlong *)local_318 + 0x20))(local_318);
        }
        lVar13 = local_308;
        OVar4 = local_310;
        local_f8 = local_310;
        local_f0 = local_308;
        FUN_1809df270(&local_3c0,uVar31 + 1,iVar1 < 2,0,1);
        uVar8 = local_3b4;
        pOVar26 = local_3c0;
        pOVar36 = local_3c0 + (ulonglong)uVar31 * 0x20;
        *(uint *)pOVar36 = local_3b4;
        *(int *)(pOVar36 + 4) = local_38c;
        *(OdDgElementResolver **)(pOVar36 + 8) = pOVar29;
        if (pOVar29 != (OdDgElementResolver *)0x0) {
          (**(code **)(*(longlong *)pOVar29 + 0x20))(pOVar29);
        }
        pOVar36[0x10] = OVar4;
        *(longlong *)(pOVar36 + 0x18) = lVar13;
        if (pOVar29 != (OdDgElementResolver *)0x0) {
          (**(code **)(*(longlong *)pOVar29 + 0x28))(pOVar29);
          local_100 = (OdDgElementResolver *)0x0;
        }
        *(int *)(pOVar26 + -4) = *(int *)(pOVar26 + -4) + 1;
        goto LAB_1809db4e0;
      }
    }
    else {
      LOCK();
      iVar2 = *(int *)pOVar29;
      *(int *)pOVar29 = *(int *)pOVar29;
      UNLOCK();
      if (1 < iVar2) {
        FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
      }
      if (*(int *)(local_3c0 + -4) == 0) goto LAB_1809db3a3;
      if (local_3c0 <= (OdDgElementResolver *)local_320) {
        if (*(int *)(local_3c0 + -4) != 0) {
          LOCK();
          pOVar26 = local_3c0 + -0x10;
          iVar2 = *(int *)pOVar26;
          *(int *)pOVar26 = *(int *)pOVar26;
          UNLOCK();
          if (1 < iVar2) {
            FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
          }
          pOVar26 = pOVar28;
          if (*(uint *)(local_3c0 + -4) != 0) {
            pOVar26 = local_3c0;
          }
          pOVar36 = pOVar26 + (ulonglong)*(uint *)(local_3c0 + -4) * 0x20;
        }
        goto LAB_1809db3a3;
      }
    }
    FUN_1809df270(&local_3c0,uVar31 + 1,iVar1 < 2,0,1);
  }
  uVar8 = local_3b4;
  pOVar26 = local_3c0;
  pOVar29 = local_3c0 + (ulonglong)uVar31 * 0x20;
  *(uint *)pOVar29 = local_3b4;
  *(int *)(pOVar29 + 4) = iVar9;
  *(OdDgElementResolver **)(pOVar29 + 8) = local_318;
  if (local_318 != (OdDgElementResolver *)0x0) {
    (**(code **)(*(longlong *)local_318 + 0x20))();
  }
  pOVar29[0x10] = local_310;
  *(longlong *)(pOVar29 + 0x18) = local_308;
  *(int *)(pOVar26 + -4) = *(int *)(pOVar26 + -4) + 1;
LAB_1809db4e0:
  pOVar36 = (OdDgElementResolver *)(ulonglong)local_3a8;
LAB_1809db4e5:
  uVar31 = (uint)pOVar36;
  if (*(uint *)(pOVar26 + -4) <= uVar31) {
    OdError_InvalidIndex::OdError_InvalidIndex(local_138);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_138,(ThrowInfo *)&DAT_180de5370);
  }
  LOCK();
  pOVar26 = pOVar26 + -0x10;
  iVar9 = *(int *)pOVar26;
  *(int *)pOVar26 = *(int *)pOVar26;
  UNLOCK();
  if (1 < iVar9) {
    FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
  }
  pOVar29 = local_3c0;
  lVar13 = (longlong)pOVar36 * 0x20;
  if (*(uint *)(local_3c0 + -4) <= uVar31) {
    OdError_InvalidIndex::OdError_InvalidIndex(local_140);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_140,(ThrowInfo *)&DAT_180de5370);
  }
  LOCK();
  pOVar26 = local_3c0 + -0x10;
  iVar9 = *(int *)pOVar26;
  *(int *)pOVar26 = *(int *)pOVar26;
  UNLOCK();
  if (1 < iVar9) {
    FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
  }
  pOVar26 = local_3c0;
  if (*(int *)(local_3c0 + lVar13 + 4) + *(int *)(pOVar29 + lVar13) != uVar8) goto LAB_1809db8ca;
  if (*(uint *)(local_3c0 + -4) <= uVar31) {
    OdError_InvalidIndex::OdError_InvalidIndex(local_148);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_148,(ThrowInfo *)&DAT_180de5370);
  }
  LOCK();
  pOVar26 = local_3c0 + -0x10;
  iVar9 = *(int *)pOVar26;
  *(int *)pOVar26 = *(int *)pOVar26;
  UNLOCK();
  if (1 < iVar9) {
    FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
  }
  if (local_3c0[lVar13 + 0x10] == (OdDgElementResolver)0x0) {
    if (*(uint *)(local_3c0 + -4) <= uVar31) {
      OdError_InvalidIndex::OdError_InvalidIndex(local_160);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_160,(ThrowInfo *)&DAT_180de5370);
    }
    LOCK();
    pOVar26 = local_3c0 + -0x10;
    iVar9 = *(int *)pOVar26;
    *(int *)pOVar26 = *(int *)pOVar26;
    UNLOCK();
    if (1 < iVar9) {
      FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
    }
    pOVar26 = local_3c0;
    if (*(longlong *)(local_3c0 + lVar13 + 8) == 0) goto LAB_1809db70c;
    uVar3 = *(uint *)(local_3c0 + -4);
    uVar35 = uVar3 - 1;
    uVar30 = uVar35 - uVar3;
    if (0 < (int)uVar30) {
      LOCK();
      pOVar26 = local_3c0 + -0x10;
      iVar9 = *(int *)pOVar26;
      *(int *)pOVar26 = *(int *)pOVar26;
      UNLOCK();
      if (iVar9 < 2) {
        if (*(uint *)(local_3c0 + -8) < uVar30 + uVar3) {
          uVar22 = 1;
          goto LAB_1809db62d;
        }
      }
      else {
        uVar22 = 0;
LAB_1809db62d:
        FUN_1809df270(&local_3c0,uVar30 + uVar3,uVar22,0,1);
      }
      if (uVar30 == 0) goto LAB_1809db8b9;
      pOVar26 = local_3c0 + (ulonglong)uVar30 * 0x20 + 8 + (ulonglong)uVar3 * 0x20;
      do {
        *(undefined8 *)(pOVar26 + -0x28) = 0;
        *(undefined8 *)(pOVar26 + -0x20) = 0;
        pOVar26[-0x18] = (OdDgElementResolver)0x0;
        *(undefined8 *)(pOVar26 + -0x10) = 0;
        uVar30 = uVar30 - 1;
        pOVar26 = pOVar26 + -0x20;
      } while (uVar30 != 0);
      *(uint *)(local_3c0 + -4) = uVar35;
      local_3a8 = uVar31 - 1;
      pOVar36 = (OdDgElementResolver *)(ulonglong)local_3a8;
      pOVar26 = local_3c0;
      goto LAB_1809db4e5;
    }
    if (-1 < (int)uVar30) goto LAB_1809db8b9;
    uVar30 = -uVar30;
    LOCK();
    pOVar29 = local_3c0 + -0x10;
    iVar9 = *(int *)pOVar29;
    *(int *)pOVar29 = *(int *)pOVar29;
    UNLOCK();
    if (iVar9 < 2) {
      if (uVar30 == 0) goto LAB_1809db8b9;
      pOVar29 = local_3c0 + (ulonglong)uVar30 * 0x20 + (ulonglong)uVar35 * 0x20 + 8;
      do {
        uVar30 = uVar30 - 1;
        pOVar29 = pOVar29 + -0x20;
        if (*(longlong **)pOVar29 != (longlong *)0x0) {
          (**(code **)(**(longlong **)pOVar29 + 0x28))();
          *(longlong *)pOVar29 = 0;
        }
      } while (uVar30 != 0);
      *(uint *)(pOVar26 + -4) = uVar35;
      local_3a8 = uVar31 - 1;
      pOVar36 = (OdDgElementResolver *)(ulonglong)local_3a8;
      goto LAB_1809db4e5;
    }
LAB_1809db89c:
    FUN_1809df270(&local_3c0,uVar35,0,0,1);
  }
  else {
LAB_1809db70c:
    if (*(uint *)(local_3c0 + -4) <= uVar31) {
      OdError_InvalidIndex::OdError_InvalidIndex(local_118);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_118,(ThrowInfo *)&DAT_180de5370);
    }
    LOCK();
    pOVar26 = local_3c0 + -0x10;
    iVar9 = *(int *)pOVar26;
    *(int *)pOVar26 = *(int *)pOVar26;
    UNLOCK();
    if (1 < iVar9) {
      FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
    }
    if (local_3c0[lVar13 + 0x10] == (OdDgElementResolver)0x0) {
LAB_1809db8bd:
      local_3a8 = uVar31 - 1;
      pOVar36 = (OdDgElementResolver *)(ulonglong)local_3a8;
      pOVar26 = local_3c0;
      goto LAB_1809db4e5;
    }
    if (*(uint *)(local_3c0 + -4) <= uVar31) {
      OdError_InvalidIndex::OdError_InvalidIndex(local_158);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_158,(ThrowInfo *)&DAT_180de5370);
    }
    LOCK();
    pOVar26 = local_3c0 + -0x10;
    iVar9 = *(int *)pOVar26;
    *(int *)pOVar26 = *(int *)pOVar26;
    UNLOCK();
    if (1 < iVar9) {
      FUN_1809df270(&local_3c0,*(undefined4 *)(local_3c0 + -8),0,0,1);
    }
    pOVar26 = local_3c0;
    if (*(longlong *)(local_3c0 + lVar13 + 0x18) == 0) goto LAB_1809db8bd;
    uVar3 = *(uint *)(local_3c0 + -4);
    uVar35 = uVar3 - 1;
    uVar30 = uVar35 - uVar3;
    if ((int)uVar30 < 1) {
      if (-1 < (int)uVar30) goto LAB_1809db8b9;
      uVar30 = -uVar30;
      LOCK();
      pOVar29 = local_3c0 + -0x10;
      iVar9 = *(int *)pOVar29;
      *(int *)pOVar29 = *(int *)pOVar29;
      UNLOCK();
      if (1 < iVar9) goto LAB_1809db89c;
      if (uVar30 == 0) goto LAB_1809db8b9;
      pOVar29 = local_3c0 + (ulonglong)uVar30 * 0x20 + (ulonglong)uVar35 * 0x20 + 8;
      do {
        uVar30 = uVar30 - 1;
        pOVar29 = pOVar29 + -0x20;
        if (*(longlong **)pOVar29 != (longlong *)0x0) {
          (**(code **)(**(longlong **)pOVar29 + 0x28))();
          *(longlong *)pOVar29 = 0;
        }
      } while (uVar30 != 0);
      *(uint *)(pOVar26 + -4) = uVar35;
      local_3a8 = uVar31 - 1;
      pOVar36 = (OdDgElementResolver *)(ulonglong)local_3a8;
      goto LAB_1809db4e5;
    }
    LOCK();
    pOVar26 = local_3c0 + -0x10;
    iVar9 = *(int *)pOVar26;
    *(int *)pOVar26 = *(int *)pOVar26;
    UNLOCK();
    if (iVar9 < 2) {
      if (*(uint *)(local_3c0 + -8) < uVar30 + uVar3) {
        uVar22 = 1;
        goto LAB_1809db7cb;
      }
    }
    else {
      uVar22 = 0;
LAB_1809db7cb:
      FUN_1809df270(&local_3c0,uVar30 + uVar3,uVar22,0,1);
    }
    if (uVar30 != 0) {
      pOVar26 = local_3c0 + (ulonglong)uVar30 * 0x20 + 8 + (ulonglong)uVar3 * 0x20;
      do {
        *(undefined8 *)(pOVar26 + -0x28) = 0;
        *(undefined8 *)(pOVar26 + -0x20) = 0;
        pOVar26[-0x18] = (OdDgElementResolver)0x0;
        *(undefined8 *)(pOVar26 + -0x10) = 0;
        uVar30 = uVar30 - 1;
        pOVar26 = pOVar26 + -0x20;
      } while (uVar30 != 0);
      *(uint *)(local_3c0 + -4) = uVar35;
      local_3a8 = uVar31 - 1;
      pOVar36 = (OdDgElementResolver *)(ulonglong)local_3a8;
      pOVar26 = local_3c0;
      goto LAB_1809db4e5;
    }
  }
LAB_1809db8b9:
  *(uint *)(local_3c0 + -4) = uVar35;
  goto LAB_1809db8bd;
LAB_1809db8ca:
  if (local_3a0 != (OdDgElementResolver *)0x0) {
    (**(code **)(*(longlong *)local_3a0 + 0x28))();
  }
  if (local_398 != (OdDgElementResolver *)0x0) {
    (**(code **)(*(longlong *)local_398 + 0x28))();
  }
  pOVar29 = (OdDgElementResolver *)(ulonglong)(local_3b4 + 1);
  goto LAB_1809d9e24;
}



