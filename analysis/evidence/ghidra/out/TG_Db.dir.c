/* ==== 1804740d0 FUN_1804740d0 ==== */

void FUN_1804740d0(longlong param_1)

{
  OdDgTerrainTrianglesSettings *pOVar1;
  OdDgElementResolver *pOVar2;
  longlong *plVar3;
  bool bVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  uint uVar7;
  OdDgTerrainPointDisplayType OVar8;
  ulong uVar9;
  OdDgTerrainFeatureType OVar10;
  int iVar11;
  longlong lVar12;
  OdDgDatabase *this;
  longlong *plVar13;
  OdRxClass *pOVar14;
  longlong *plVar15;
  undefined8 *puVar16;
  OdString *pOVar17;
  longlong *plVar18;
  longlong *plVar19;
  OdRxClass *pOVar20;
  uint uVar21;
  int *piVar22;
  OdDgTableElementMerge *this_00;
  double dVar23;
  longlong *local_res10;
  ushort local_res18 [4];
  ushort local_res20 [4];
  longlong *local_2f8;
  longlong *local_2f0;
  OdDgElementResolver *local_2e8;
  int *piStack_2e0;
  longlong *local_2d8;
  longlong *local_2d0;
  longlong *local_2c8;
  ushort local_2c0;
  ushort local_2be [3];
  longlong *local_2b8;
  longlong *local_2b0;
  longlong *local_2a8;
  longlong *local_2a0;
  longlong *local_298;
  longlong *local_290;
  double local_288;
  double local_280;
  double local_278;
  longlong *local_270;
  OdDgTerrainContourSmoothingType local_268;
  OdDgTerrainContourSmoothingType local_264;
  code *local_260;
  longlong *local_258;
  longlong local_250;
  longlong local_248;
  longlong local_240;
  longlong local_238;
  longlong local_230;
  longlong *local_228;
  longlong *local_220;
  longlong *local_218;
  longlong *local_210;
  longlong *local_208;
  longlong *local_200;
  longlong *local_1f8;
  longlong *local_1f0;
  longlong *local_1e8;
  OdError local_1e0 [8];
  longlong *local_1d8;
  longlong *local_1d0;
  longlong *local_1c8;
  OdString local_1c0 [8];
  OdString local_1b8 [8];
  OdString local_1b0 [8];
  OdString local_1a8 [8];
  OdString local_1a0 [8];
  OdString local_198 [8];
  OdString local_190 [8];
  OdString local_188 [8];
  OdString local_180 [8];
  OdString local_178 [8];
  OdString local_170 [8];
  OdString local_168 [8];
  OdString local_160 [8];
  longlong *local_158;
  longlong *local_150;
  longlong *local_148;
  OdError_NotThatKindOfClass local_140 [8];
  longlong *local_138;
  undefined8 *local_130;
  int *local_128;
  undefined8 *local_120;
  int *local_118;
  undefined8 *local_110;
  int *local_108;
  undefined8 *local_100;
  int *local_f8;
  undefined8 *local_f0;
  int *local_e8;
  OdError local_e0 [8];
  undefined8 *local_d8;
  int *local_d0;
  undefined8 *local_c8;
  int *local_c0;
  undefined8 *local_b8;
  int *local_b0;
  undefined8 *local_a8;
  int *local_a0;
  undefined8 *local_98;
  int *local_90;
  undefined8 *local_88;
  int *local_80;
  undefined8 *local_78;
  int *local_70;
  undefined8 *local_68;
  int *local_60;
  undefined8 *local_58;
  int *local_50;
  
  plVar19 = (longlong *)0x0;
  local_2be[1] = 0;
  local_2be[2] = 0;
  FUN_1801cf7f0(param_1,0x58ec014e);
  FUN_1801cf7f0(param_1,0x58ec0064);
  FUN_1801cf7f0(param_1,0x58ec0136);
  FUN_1801cf7f0(param_1,0x58ec0001);
  lVar12 = FUN_180010890(param_1);
  if (lVar12 != 0) {
    FUN_1801cf7f0(param_1,0x58010001);
  }
  local_260 = g_empty_array_buffer_exref + 0x10;
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  FUN_1801cc8b0(param_1,0x56ec0000,&local_260,0);
  if (*(int *)(local_260 + -4) == 0) {
    OdDgExtendedElementTypeXAttribute::createObject();
    local_2f8 = (longlong *)CONCAT44(local_2f8._4_4_,0x58ec000b);
    (**(code **)(*local_1d0 + 0x88))(local_1d0,&local_2f8);
    (**(code **)(*local_1d0 + 0x98))(local_1d0,0xffffffff);
    (**(code **)(*local_1d0 + 0x68))(local_1d0,1);
    local_2f8 = local_1d0;
    (**(code **)(*local_1d0 + 0x20))(local_1d0);
    FUN_1801c1cd0(param_1,0x56ec0000,&local_2f8);
    (**(code **)(*local_1d0 + 0x28))(local_1d0);
  }
  this = (OdDgDatabase *)FUN_180010890(param_1);
  if (this != (OdDgDatabase *)0x0) {
    OdDgDatabase::getTextStyleTable(this,(OpenMode)&local_2d0);
    (**(code **)(*local_2d0 + 0x448))(local_2d0,&local_2f0,0);
    OdDgTextStyleDataXAttribute::createObject();
    plVar13 = local_2d0;
    lVar12 = *local_2d0;
    uVar6 = (**(code **)(**(longlong **)(param_1 + 0x2d0) + 0x128))();
    (**(code **)(lVar12 + 0x3f8))(plVar13,&local_250,uVar6,0);
    local_290 = local_2f0;
    if (local_2f0 != (longlong *)0x0) {
      (**(code **)(*local_2f0 + 0x20))();
    }
    if (local_250 != 0) {
      plVar13 = (longlong *)
                OdDgElementId::openObject((OdDgElementId *)&local_250,(OpenMode)&local_220,false);
      plVar13 = (longlong *)*plVar13;
      if (local_290 != (longlong *)0x0) {
        (**(code **)(*local_290 + 0x28))();
        local_290 = (longlong *)0x0;
      }
      plVar15 = local_290;
      if (plVar13 != (longlong *)0x0) {
        lVar12 = *plVar13;
        pOVar14 = OdDgTextStyleTableRecord::desc();
        plVar15 = (longlong *)(**(code **)(lVar12 + 8))(plVar13,pOVar14);
        if (plVar15 == (longlong *)0x0) {
          pOVar14 = OdDgTextStyleTableRecord::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar13 + 0x18))(plVar13);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_res10,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_res10,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_290 = plVar15;
      if (local_220 != (longlong *)0x0) {
        (**(code **)(*local_220 + 0x28))();
      }
    }
    (**(code **)(*local_1c8 + 0x68))(local_1c8,2);
    (**(code **)(*local_1c8 + 0x380))(local_1c8,&local_290);
    local_2f8 = local_1c8;
    (**(code **)(*local_1c8 + 0x20))(local_1c8);
    FUN_1801c1cd0(param_1,0x58010001,&local_2f8);
    OdDgTextStyleDataXAttribute::createObject();
    plVar13 = local_2d0;
    lVar12 = *local_2d0;
    uVar6 = (**(code **)(**(longlong **)(param_1 + 0x2d8) + 0x128))();
    (**(code **)(lVar12 + 0x3f8))(plVar13,&local_248,uVar6,0);
    local_298 = local_2f0;
    if (local_2f0 != (longlong *)0x0) {
      (**(code **)(*local_2f0 + 0x20))();
    }
    if (local_248 != 0) {
      plVar13 = (longlong *)
                OdDgElementId::openObject((OdDgElementId *)&local_248,(OpenMode)&local_210,false);
      plVar13 = (longlong *)*plVar13;
      if (local_298 != (longlong *)0x0) {
        (**(code **)(*local_298 + 0x28))();
        local_298 = (longlong *)0x0;
      }
      plVar15 = local_298;
      if (plVar13 != (longlong *)0x0) {
        lVar12 = *plVar13;
        pOVar14 = OdDgTextStyleTableRecord::desc();
        plVar15 = (longlong *)(**(code **)(lVar12 + 8))(plVar13,pOVar14);
        if (plVar15 == (longlong *)0x0) {
          pOVar14 = OdDgTextStyleTableRecord::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar13 + 0x18))(plVar13);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_res10,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_res10,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_298 = plVar15;
      if (local_210 != (longlong *)0x0) {
        (**(code **)(*local_210 + 0x28))();
      }
    }
    (**(code **)(*local_158 + 0x68))(local_158,3);
    (**(code **)(*local_158 + 0x380))(local_158,&local_298);
    local_2f8 = local_158;
    (**(code **)(*local_158 + 0x20))(local_158);
    FUN_1801c1cd0(param_1,0x58010001,&local_2f8);
    OdDgTextStyleDataXAttribute::createObject();
    plVar13 = local_2d0;
    lVar12 = *local_2d0;
    uVar6 = (**(code **)(**(longlong **)(param_1 + 0x2b0) + 0x108))();
    (**(code **)(lVar12 + 0x3f8))(plVar13,&local_240,uVar6,0);
    local_2a0 = local_2f0;
    if (local_2f0 != (longlong *)0x0) {
      (**(code **)(*local_2f0 + 0x20))();
    }
    if (local_240 != 0) {
      plVar13 = (longlong *)
                OdDgElementId::openObject((OdDgElementId *)&local_240,(OpenMode)&local_200,false);
      plVar13 = (longlong *)*plVar13;
      if (local_2a0 != (longlong *)0x0) {
        (**(code **)(*local_2a0 + 0x28))();
        local_2a0 = (longlong *)0x0;
      }
      plVar15 = local_2a0;
      if (plVar13 != (longlong *)0x0) {
        lVar12 = *plVar13;
        pOVar14 = OdDgTextStyleTableRecord::desc();
        plVar15 = (longlong *)(**(code **)(lVar12 + 8))(plVar13,pOVar14);
        if (plVar15 == (longlong *)0x0) {
          pOVar14 = OdDgTextStyleTableRecord::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar13 + 0x18))(plVar13);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_res10,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_res10,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2a0 = plVar15;
      if (local_200 != (longlong *)0x0) {
        (**(code **)(*local_200 + 0x28))();
      }
    }
    (**(code **)(*local_150 + 0x68))(local_150,4);
    (**(code **)(*local_150 + 0x380))(local_150,&local_2a0);
    local_2f8 = local_150;
    (**(code **)(*local_150 + 0x20))(local_150);
    FUN_1801c1cd0(param_1,0x58010001,&local_2f8);
    OdDgTextStyleDataXAttribute::createObject();
    plVar13 = local_2d0;
    lVar12 = *local_2d0;
    uVar6 = (**(code **)(**(longlong **)(param_1 + 0x2e0) + 0x108))();
    (**(code **)(lVar12 + 0x3f8))(plVar13,&local_238,uVar6,0);
    local_2a8 = local_2f0;
    if (local_2f0 != (longlong *)0x0) {
      (**(code **)(*local_2f0 + 0x20))();
    }
    if (local_238 != 0) {
      plVar13 = (longlong *)
                OdDgElementId::openObject((OdDgElementId *)&local_238,(OpenMode)&local_218,false);
      plVar13 = (longlong *)*plVar13;
      if (local_2a8 != (longlong *)0x0) {
        (**(code **)(*local_2a8 + 0x28))();
        local_2a8 = (longlong *)0x0;
      }
      plVar15 = local_2a8;
      if (plVar13 != (longlong *)0x0) {
        lVar12 = *plVar13;
        pOVar14 = OdDgTextStyleTableRecord::desc();
        plVar15 = (longlong *)(**(code **)(lVar12 + 8))(plVar13,pOVar14);
        if (plVar15 == (longlong *)0x0) {
          pOVar14 = OdDgTextStyleTableRecord::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar13 + 0x18))(plVar13);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_res10,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_res10,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2a8 = plVar15;
      if (local_218 != (longlong *)0x0) {
        (**(code **)(*local_218 + 0x28))();
      }
    }
    (**(code **)(*local_1f8 + 0x68))(local_1f8,5);
    (**(code **)(*local_1f8 + 0x380))(local_1f8,&local_2a8);
    local_2f8 = local_1f8;
    (**(code **)(*local_1f8 + 0x20))(local_1f8);
    FUN_1801c1cd0(param_1,0x58010001,&local_2f8);
    OdDgTextStyleDataXAttribute::createObject();
    plVar13 = local_2d0;
    lVar12 = *local_2d0;
    uVar6 = (**(code **)(**(longlong **)(param_1 + 0x2b8) + 0x108))();
    (**(code **)(lVar12 + 0x3f8))(plVar13,&local_230,uVar6,0);
    local_2b0 = local_2f0;
    if (local_2f0 != (longlong *)0x0) {
      (**(code **)(*local_2f0 + 0x20))();
    }
    if (local_230 != 0) {
      plVar13 = (longlong *)
                OdDgElementId::openObject((OdDgElementId *)&local_230,(OpenMode)&local_270,false);
      plVar13 = (longlong *)*plVar13;
      if (local_2b0 != (longlong *)0x0) {
        (**(code **)(*local_2b0 + 0x28))();
        local_2b0 = (longlong *)0x0;
      }
      plVar15 = local_2b0;
      if (plVar13 != (longlong *)0x0) {
        lVar12 = *plVar13;
        pOVar14 = OdDgTextStyleTableRecord::desc();
        plVar15 = (longlong *)(**(code **)(lVar12 + 8))(plVar13,pOVar14);
        if (plVar15 == (longlong *)0x0) {
          pOVar14 = OdDgTextStyleTableRecord::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar13 + 0x18))(plVar13);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_res10,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_res10,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2b0 = plVar15;
      if (local_270 != (longlong *)0x0) {
        (**(code **)(*local_270 + 0x28))();
      }
    }
    (**(code **)(*local_1f0 + 0x68))(local_1f0,7);
    (**(code **)(*local_1f0 + 0x380))(local_1f0,&local_2b0);
    local_2f8 = local_1f0;
    (**(code **)(*local_1f0 + 0x20))(local_1f0);
    FUN_1801c1cd0(param_1,0x58010001,&local_2f8);
    OdDgTextStyleDataXAttribute::createObject();
    plVar13 = local_2d0;
    local_270 = (longlong *)(*local_2d0 + 0x3f8);
    uVar6 = (**(code **)(**(longlong **)(param_1 + 0x2c0) + 0x108))();
    (*(code *)*local_270)(plVar13,&local_2c8,uVar6,0);
    local_2b8 = local_2f0;
    if (local_2f0 != (longlong *)0x0) {
      (**(code **)(*local_2f0 + 0x20))();
    }
    if (local_2c8 != (longlong *)0x0) {
      puVar16 = (undefined8 *)
                OdDgElementId::openObject((OdDgElementId *)&local_2c8,(OpenMode)&local_208,false);
      plVar13 = (longlong *)*puVar16;
      local_2f8 = plVar13;
      if (local_2b8 != (longlong *)0x0) {
        (**(code **)(*local_2b8 + 0x28))();
        local_2b8 = (longlong *)0x0;
      }
      plVar15 = local_2b8;
      if (plVar13 != (longlong *)0x0) {
        lVar12 = *plVar13;
        pOVar14 = OdDgTextStyleTableRecord::desc();
        plVar15 = (longlong *)(**(code **)(lVar12 + 8))(local_2f8,pOVar14);
        if (plVar15 == (longlong *)0x0) {
          pOVar14 = OdDgTextStyleTableRecord::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*local_2f8 + 0x18))(local_2f8);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_res10,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_res10,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2b8 = plVar15;
      if (local_208 != (longlong *)0x0) {
        (**(code **)(*local_208 + 0x28))();
      }
    }
    (**(code **)(*local_1e8 + 0x68))(local_1e8,8);
    (**(code **)(*local_1e8 + 0x380))(local_1e8,&local_2b8);
    local_2f8 = local_1e8;
    (**(code **)(*local_1e8 + 0x20))(local_1e8);
    FUN_1801c1cd0(param_1,0x58010001,&local_2f8);
    if (local_2b8 != (longlong *)0x0) {
      (**(code **)(*local_2b8 + 0x28))();
      local_2b8 = (longlong *)0x0;
    }
    (**(code **)(*local_1e8 + 0x28))(local_1e8);
    if (local_2b0 != (longlong *)0x0) {
      (**(code **)(*local_2b0 + 0x28))();
      local_2b0 = (longlong *)0x0;
    }
    (**(code **)(*local_1f0 + 0x28))(local_1f0);
    if (local_2a8 != (longlong *)0x0) {
      (**(code **)(*local_2a8 + 0x28))();
      local_2a8 = (longlong *)0x0;
    }
    (**(code **)(*local_1f8 + 0x28))(local_1f8);
    if (local_2a0 != (longlong *)0x0) {
      (**(code **)(*local_2a0 + 0x28))();
      local_2a0 = (longlong *)0x0;
    }
    (**(code **)(*local_150 + 0x28))(local_150);
    if (local_298 != (longlong *)0x0) {
      (**(code **)(*local_298 + 0x28))();
      local_298 = (longlong *)0x0;
    }
    (**(code **)(*local_158 + 0x28))(local_158);
    if (local_290 != (longlong *)0x0) {
      (**(code **)(*local_290 + 0x28))();
      local_290 = (longlong *)0x0;
    }
    (**(code **)(*local_1c8 + 0x28))(local_1c8);
    if (local_2f0 != (longlong *)0x0) {
      (**(code **)(*local_2f0 + 0x28))();
      local_2f0 = (longlong *)0x0;
    }
    if (local_2d0 != (longlong *)0x0) {
      (**(code **)(*local_2d0 + 0x28))();
    }
  }
  if (*(longlong *)(param_1 + 0x2a0) != 0) {
    pOVar14 = OdDgTerrainControlReferenceXAttribute::desc();
    if (pOVar14 == (OdRxClass *)0x0) {
      OdError::OdError(local_1e0,0xff);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(local_1e0,(ThrowInfo *)&DAT_180de52b8);
    }
    pOVar14 = OdDgTerrainControlReferenceXAttribute::desc();
    plVar13 = (longlong *)(**(code **)(*(longlong *)pOVar14 + 0x58))(pOVar14,&local_258);
    local_1d8 = (longlong *)0x0;
    plVar13 = (longlong *)*plVar13;
    plVar15 = local_1d8;
    if (plVar13 != (longlong *)0x0) {
      lVar12 = *plVar13;
      pOVar14 = OdDgTerrainControlReferenceXAttribute::desc();
      plVar15 = (longlong *)(**(code **)(lVar12 + 8))(plVar13,pOVar14);
      if (plVar15 == (longlong *)0x0) {
        pOVar14 = OdDgTerrainControlReferenceXAttribute::desc();
        pOVar20 = (OdRxClass *)(**(code **)(*plVar13 + 0x18))(plVar13);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                  ((OdError_NotThatKindOfClass *)&local_2e8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(&local_2e8,(ThrowInfo *)&DAT_180de5310);
      }
    }
    local_1d8 = plVar15;
    plVar13 = local_1d8;
    local_2be[1] = 1;
    local_2be[2] = 0;
    if (local_258 != (longlong *)0x0) {
      (**(code **)(*local_258 + 0x28))();
    }
    (**(code **)(*plVar13 + 0x88))(plVar13,*(undefined8 *)(param_1 + 0x2a0));
    (**(code **)(*plVar13 + 0x68))(plVar13,1);
    local_2c8 = plVar13;
    (**(code **)(*plVar13 + 0x20))(plVar13);
    FUN_1801c1cd0(param_1,0x58ec0064,&local_2c8);
    local_2be[1] = 0;
    local_2be[2] = 0;
    (**(code **)(*plVar13 + 0x28))(plVar13);
  }
  local_2f0 = (longlong *)0x0;
  uVar21 = 1;
  plVar13 = plVar19;
  do {
    OdDgTerrainGraphicsSettingsXAttribute::createObject();
    plVar15 = local_228;
    local_2e8 = (OdDgElementResolver *)0x0;
    piStack_2e0 = (int *)0x0;
    switch(uVar21) {
    case 1:
      plVar18 = *(longlong **)(param_1 + 0x2a8);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,1);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_130);
      pOVar1 = (OdDgTerrainTrianglesSettings *)*plVar18;
      if ((pOVar1 != (OdDgTerrainTrianglesSettings *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = (OdDgElementResolver *)pOVar1,
         piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_128 != (int *)0x0) && (*local_128 = *local_128 + -1, *local_128 == 0)) {
        if (local_130 != (undefined8 *)0x0) {
          (**(code **)*local_130)(local_130,1);
        }
        odrxFree(local_128);
      }
      uVar7 = (**(code **)(**(longlong **)(param_1 + 0x2a8) + 200))();
      OdDgTerrainTrianglesSettings::setMaterialId
                ((OdDgTerrainTrianglesSettings *)this_00,(ulonglong)uVar7);
      goto LAB_180475ec1;
    case 2:
      plVar18 = *(longlong **)(param_1 + 0x2d0);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,3);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_120);
      pOVar2 = (OdDgElementResolver *)*plVar18;
      if ((pOVar2 != (OdDgElementResolver *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = pOVar2, piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_118 != (int *)0x0) && (*local_118 = *local_118 + -1, *local_118 == 0)) {
        if (local_120 != (undefined8 *)0x0) {
          (**(code **)*local_120)(local_120,1);
        }
        odrxFree(local_118);
      }
      local_2f8 = (longlong *)((ulonglong)local_2f8 & 0xffffffff00000000);
      OdDgElementResolver::setElementType((OdDgElementResolver *)this_00,(ElementTypes *)&local_2f8)
      ;
      dVar23 = (double)(**(code **)(**(longlong **)(param_1 + 0x2d0) + 200))();
      OdGiAuxDataForDgDatabase::setAnnotationScale((OdGiAuxDataForDgDatabase *)this_00,dVar23);
      local_268 = (**(code **)(**(longlong **)(param_1 + 0x2d0) + 0xd8))();
      OdDgTerrainContourFeatureSettings::setSmoothingType
                ((OdDgTerrainContourFeatureSettings *)this_00,&local_268);
      uVar9 = (**(code **)(**(longlong **)(param_1 + 0x2d0) + 0xe8))();
      OdDgTerrainContourFeatureSettings::setSmoothingFactor
                ((OdDgTerrainContourFeatureSettings *)this_00,uVar9);
      bVar4 = (bool)(**(code **)(**(longlong **)(param_1 + 0x2d0) + 0xf8))();
      OdDgTerrainContourFeatureSettings::setDisplayTextFlag
                ((OdDgTerrainContourFeatureSettings *)this_00,bVar4);
      dVar23 = (double)(**(code **)(**(longlong **)(param_1 + 0x2d0) + 0x108))();
      OdDgEnvMapImageCube::setRotation((OdDgEnvMapImageCube *)this_00,dVar23);
      dVar23 = (double)(**(code **)(**(longlong **)(param_1 + 0x2d0) + 0x118))();
      OdDgTextStyleDataXAttributeImpl::setOverlineOffset
                ((OdDgTextStyleDataXAttributeImpl *)this_00,dVar23);
      OVar8 = (**(code **)(**(longlong **)(param_1 + 0x2d0) + 0x128))();
      OdDgTerrainVertexFeatureSettings::setPointDisplayType
                ((OdDgTerrainVertexFeatureSettings *)this_00,OVar8);
      bVar4 = (bool)(**(code **)(**(longlong **)(param_1 + 0x2d0) + 0x138))();
      OdDgTerrainContourFeatureSettings::setIgnoreMaxSlopesFlag
                ((OdDgTerrainContourFeatureSettings *)this_00,bVar4);
      dVar23 = (double)(**(code **)(**(longlong **)(param_1 + 0x2d0) + 0x148))();
      OdDgTerrainContourFeatureSettings::setMaxSlopeValue
                ((OdDgTerrainContourFeatureSettings *)this_00,dVar23);
      uVar9 = (**(code **)(**(longlong **)(param_1 + 0x2d0) + 0x168))();
      OdDgTerrainContourFeatureSettings::setDepressionColorIndex
                ((OdDgTerrainContourFeatureSettings *)this_00,uVar9);
      uVar9 = (**(code **)(**(longlong **)(param_1 + 0x2d0) + 0x178))();
      OdDgTerrainContourFeatureSettings::setDepressionLineStyleEntryId
                ((OdDgTerrainContourFeatureSettings *)this_00,uVar9);
      uVar9 = (**(code **)(**(longlong **)(param_1 + 0x2d0) + 0x188))();
      OdDgTerrainContourFeatureSettings::setDepressionLineWeight
                ((OdDgTerrainContourFeatureSettings *)this_00,uVar9);
      plVar18 = *(longlong **)(param_1 + 0x2d0);
      goto LAB_180474d1d;
    case 3:
      plVar18 = *(longlong **)(param_1 + 0x2d8);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,3);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_110);
      pOVar2 = (OdDgElementResolver *)*plVar18;
      if ((pOVar2 != (OdDgElementResolver *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = pOVar2, piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_108 != (int *)0x0) && (*local_108 = *local_108 + -1, *local_108 == 0)) {
        if (local_110 != (undefined8 *)0x0) {
          (**(code **)*local_110)(local_110,1);
        }
        odrxFree(local_108);
      }
      local_2f8 = (longlong *)CONCAT44(local_2f8._4_4_,1);
      OdDgElementResolver::setElementType((OdDgElementResolver *)this_00,(ElementTypes *)&local_2f8)
      ;
      dVar23 = (double)(**(code **)(**(longlong **)(param_1 + 0x2d8) + 200))();
      OdGiAuxDataForDgDatabase::setAnnotationScale((OdGiAuxDataForDgDatabase *)this_00,dVar23);
      local_264 = (**(code **)(**(longlong **)(param_1 + 0x2d8) + 0xd8))();
      OdDgTerrainContourFeatureSettings::setSmoothingType
                ((OdDgTerrainContourFeatureSettings *)this_00,&local_264);
      uVar9 = (**(code **)(**(longlong **)(param_1 + 0x2d8) + 0xe8))();
      OdDgTerrainContourFeatureSettings::setSmoothingFactor
                ((OdDgTerrainContourFeatureSettings *)this_00,uVar9);
      bVar4 = (bool)(**(code **)(**(longlong **)(param_1 + 0x2d8) + 0xf8))();
      OdDgTerrainContourFeatureSettings::setDisplayTextFlag
                ((OdDgTerrainContourFeatureSettings *)this_00,bVar4);
      dVar23 = (double)(**(code **)(**(longlong **)(param_1 + 0x2d8) + 0x108))();
      OdDgEnvMapImageCube::setRotation((OdDgEnvMapImageCube *)this_00,dVar23);
      dVar23 = (double)(**(code **)(**(longlong **)(param_1 + 0x2d8) + 0x118))();
      OdDgTextStyleDataXAttributeImpl::setOverlineOffset
                ((OdDgTextStyleDataXAttributeImpl *)this_00,dVar23);
      OVar8 = (**(code **)(**(longlong **)(param_1 + 0x2d8) + 0x128))();
      OdDgTerrainVertexFeatureSettings::setPointDisplayType
                ((OdDgTerrainVertexFeatureSettings *)this_00,OVar8);
      bVar4 = (bool)(**(code **)(**(longlong **)(param_1 + 0x2d8) + 0x138))();
      OdDgTerrainContourFeatureSettings::setIgnoreMaxSlopesFlag
                ((OdDgTerrainContourFeatureSettings *)this_00,bVar4);
      dVar23 = (double)(**(code **)(**(longlong **)(param_1 + 0x2d8) + 0x148))();
      OdDgTerrainContourFeatureSettings::setMaxSlopeValue
                ((OdDgTerrainContourFeatureSettings *)this_00,dVar23);
      uVar9 = (**(code **)(**(longlong **)(param_1 + 0x2d8) + 0x168))();
      OdDgTerrainContourFeatureSettings::setDepressionColorIndex
                ((OdDgTerrainContourFeatureSettings *)this_00,uVar9);
      uVar9 = (**(code **)(**(longlong **)(param_1 + 0x2d8) + 0x178))();
      OdDgTerrainContourFeatureSettings::setDepressionLineStyleEntryId
                ((OdDgTerrainContourFeatureSettings *)this_00,uVar9);
      uVar9 = (**(code **)(**(longlong **)(param_1 + 0x2d8) + 0x188))();
      OdDgTerrainContourFeatureSettings::setDepressionLineWeight
                ((OdDgTerrainContourFeatureSettings *)this_00,uVar9);
      plVar18 = *(longlong **)(param_1 + 0x2d8);
LAB_180474d1d:
      uVar9 = (**(code **)(*plVar18 + 0x158))();
      OdDgTerrainContourFeatureSettings::setContourLabelPrecision
                ((OdDgTerrainContourFeatureSettings *)this_00,uVar9);
      goto LAB_180475ec1;
    case 4:
      plVar18 = *(longlong **)(param_1 + 0x2b0);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,2);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_100);
      pOVar2 = (OdDgElementResolver *)*plVar18;
      if ((pOVar2 != (OdDgElementResolver *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = pOVar2, piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_f8 != (int *)0x0) && (*local_f8 = *local_f8 + -1, *local_f8 == 0)) {
        if (local_100 != (undefined8 *)0x0) {
          (**(code **)*local_100)(local_100,1);
        }
        odrxFree(local_f8);
      }
      local_2f8 = (longlong *)CONCAT44(local_2f8._4_4_,1);
      OdDgElementResolver::setElementType((OdDgElementResolver *)this_00,(ElementTypes *)&local_2f8)
      ;
      bVar4 = (bool)(**(code **)(**(longlong **)(param_1 + 0x2b0) + 200))();
      OdDgTerrainVertexFeatureSettings::setDisplayTextFlag
                ((OdDgTerrainVertexFeatureSettings *)this_00,bVar4);
      (**(code **)(**(longlong **)(param_1 + 0x2b0) + 0xd8))
                (*(longlong **)(param_1 + 0x2b0),&local_288);
      OdGiAuxDataForDgDatabase::setAnnotationScale((OdGiAuxDataForDgDatabase *)this_00,local_288);
      OdDgTerrainVertexFeatureSettings::setCellYScale
                ((OdDgTerrainVertexFeatureSettings *)this_00,local_280);
      OdDgTerrainVertexFeatureSettings::setCellZScale
                ((OdDgTerrainVertexFeatureSettings *)this_00,local_278);
      OVar8 = (**(code **)(**(longlong **)(param_1 + 0x2b0) + 0xe8))();
      OdDgTerrainVertexFeatureSettings::setPointDisplayType
                ((OdDgTerrainVertexFeatureSettings *)this_00,OVar8);
      uVar5 = (**(code **)(**(longlong **)(param_1 + 0x2b0) + 0xf8))();
      local_res10 = (longlong *)CONCAT62(local_res10._2_6_,uVar5);
      OdDgTerrainVertexFeatureSettings::setCharSymbol
                ((OdDgTerrainVertexFeatureSettings *)this_00,(ushort *)&local_res10);
      uVar9 = (**(code **)(**(longlong **)(param_1 + 0x2b0) + 0x108))();
      OdDgTerrainVertexFeatureSettings::setTextStyleEntryId
                ((OdDgTerrainVertexFeatureSettings *)this_00,uVar9);
      pOVar17 = (OdString *)
                (**(code **)(**(longlong **)(param_1 + 0x2b0) + 0x118))
                          (*(longlong **)(param_1 + 0x2b0),local_1c0);
      OdDgTerrainVertexFeatureSettings::setCellName
                ((OdDgTerrainVertexFeatureSettings *)this_00,pOVar17);
      OdString::~OdString(local_1c0);
      pOVar17 = (OdString *)
                (**(code **)(**(longlong **)(param_1 + 0x2b0) + 0x128))
                          (*(longlong **)(param_1 + 0x2b0),local_1b8);
      OdDgTerrainVertexFeatureSettings::setPrefix
                ((OdDgTerrainVertexFeatureSettings *)this_00,pOVar17);
      OdString::~OdString(local_1b8);
      pOVar17 = (OdString *)
                (**(code **)(**(longlong **)(param_1 + 0x2b0) + 0x138))
                          (*(longlong **)(param_1 + 0x2b0),local_1b0);
      OdDgTerrainVertexFeatureSettings::setSuffix
                ((OdDgTerrainVertexFeatureSettings *)this_00,pOVar17);
      pOVar17 = local_1b0;
      goto LAB_180475178;
    case 5:
      plVar18 = *(longlong **)(param_1 + 0x2e0);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,2);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_f0);
      pOVar2 = (OdDgElementResolver *)*plVar18;
      if ((pOVar2 != (OdDgElementResolver *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = pOVar2, piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_e8 != (int *)0x0) && (*local_e8 = *local_e8 + -1, *local_e8 == 0)) {
        if (local_f0 != (undefined8 *)0x0) {
          (**(code **)*local_f0)(local_f0,1);
        }
        odrxFree(local_e8);
      }
      local_2f8 = (longlong *)((ulonglong)local_2f8 & 0xffffffff00000000);
      OdDgElementResolver::setElementType((OdDgElementResolver *)this_00,(ElementTypes *)&local_2f8)
      ;
      bVar4 = (bool)(**(code **)(**(longlong **)(param_1 + 0x2e0) + 200))();
      OdDgTerrainVertexFeatureSettings::setDisplayTextFlag
                ((OdDgTerrainVertexFeatureSettings *)this_00,bVar4);
      (**(code **)(**(longlong **)(param_1 + 0x2e0) + 0xd8))
                (*(longlong **)(param_1 + 0x2e0),&local_288);
      OdGiAuxDataForDgDatabase::setAnnotationScale((OdGiAuxDataForDgDatabase *)this_00,local_288);
      OdDgTerrainVertexFeatureSettings::setCellYScale
                ((OdDgTerrainVertexFeatureSettings *)this_00,local_280);
      OdDgTerrainVertexFeatureSettings::setCellZScale
                ((OdDgTerrainVertexFeatureSettings *)this_00,local_278);
      OVar8 = (**(code **)(**(longlong **)(param_1 + 0x2e0) + 0xe8))();
      OdDgTerrainVertexFeatureSettings::setPointDisplayType
                ((OdDgTerrainVertexFeatureSettings *)this_00,OVar8);
      local_res18[0] = (**(code **)(**(longlong **)(param_1 + 0x2e0) + 0xf8))();
      OdDgTerrainVertexFeatureSettings::setCharSymbol
                ((OdDgTerrainVertexFeatureSettings *)this_00,local_res18);
      uVar9 = (**(code **)(**(longlong **)(param_1 + 0x2e0) + 0x108))();
      OdDgTerrainVertexFeatureSettings::setTextStyleEntryId
                ((OdDgTerrainVertexFeatureSettings *)this_00,uVar9);
      pOVar17 = (OdString *)
                (**(code **)(**(longlong **)(param_1 + 0x2e0) + 0x118))
                          (*(longlong **)(param_1 + 0x2e0),local_1a8);
      OdDgTerrainVertexFeatureSettings::setCellName
                ((OdDgTerrainVertexFeatureSettings *)this_00,pOVar17);
      OdString::~OdString(local_1a8);
      pOVar17 = (OdString *)
                (**(code **)(**(longlong **)(param_1 + 0x2e0) + 0x128))
                          (*(longlong **)(param_1 + 0x2e0),local_1a0);
      OdDgTerrainVertexFeatureSettings::setPrefix
                ((OdDgTerrainVertexFeatureSettings *)this_00,pOVar17);
      OdString::~OdString(local_1a0);
      pOVar17 = (OdString *)
                (**(code **)(**(longlong **)(param_1 + 0x2e0) + 0x138))
                          (*(longlong **)(param_1 + 0x2e0),local_198);
      OdDgTerrainVertexFeatureSettings::setSuffix
                ((OdDgTerrainVertexFeatureSettings *)this_00,pOVar17);
      pOVar17 = local_198;
      goto LAB_180475178;
    case 6:
      plVar18 = *(longlong **)(param_1 + 0x2c8);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,2);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_58);
      pOVar2 = (OdDgElementResolver *)*plVar18;
      if ((pOVar2 != (OdDgElementResolver *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = pOVar2, piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_50 != (int *)0x0) && (*local_50 = *local_50 + -1, *local_50 == 0)) {
        if (local_58 != (undefined8 *)0x0) {
          (**(code **)*local_58)(local_58,1);
        }
        odrxFree(local_50);
      }
      local_2f8 = (longlong *)CONCAT44(local_2f8._4_4_,4);
      OdDgElementResolver::setElementType((OdDgElementResolver *)this_00,(ElementTypes *)&local_2f8)
      ;
      OdDgTerrainVertexFeatureSettings::setDisplayTextFlag
                ((OdDgTerrainVertexFeatureSettings *)this_00,false);
      (**(code **)(**(longlong **)(param_1 + 0x2c8) + 200))
                (*(longlong **)(param_1 + 0x2c8),&local_288);
      OdGiAuxDataForDgDatabase::setAnnotationScale((OdGiAuxDataForDgDatabase *)this_00,local_288);
      OdDgTerrainVertexFeatureSettings::setCellYScale
                ((OdDgTerrainVertexFeatureSettings *)this_00,local_280);
      OdDgTerrainVertexFeatureSettings::setCellZScale
                ((OdDgTerrainVertexFeatureSettings *)this_00,local_278);
      OVar8 = (**(code **)(**(longlong **)(param_1 + 0x2c8) + 0xd8))();
      OdDgTerrainVertexFeatureSettings::setPointDisplayType
                ((OdDgTerrainVertexFeatureSettings *)this_00,OVar8);
      local_res20[0] = (**(code **)(**(longlong **)(param_1 + 0x2c8) + 0xe8))();
      OdDgTerrainVertexFeatureSettings::setCharSymbol
                ((OdDgTerrainVertexFeatureSettings *)this_00,local_res20);
      OdDgTerrainVertexFeatureSettings::setTextStyleEntryId
                ((OdDgTerrainVertexFeatureSettings *)this_00,0);
      pOVar17 = (OdString *)
                (**(code **)(**(longlong **)(param_1 + 0x2c8) + 0xf8))
                          (*(longlong **)(param_1 + 0x2c8),local_190);
      OdDgTerrainVertexFeatureSettings::setCellName
                ((OdDgTerrainVertexFeatureSettings *)this_00,pOVar17);
      OdString::~OdString(local_190);
      OdDgTerrainVertexFeatureSettings::setPrefix
                ((OdDgTerrainVertexFeatureSettings *)this_00,(OdString *)kEmpty_exref);
      OdDgTerrainVertexFeatureSettings::setSuffix
                ((OdDgTerrainVertexFeatureSettings *)this_00,(OdString *)kEmpty_exref);
      OdDgTerrainVertexFeatureSettings::setMinValue((OdDgTerrainVertexFeatureSettings *)this_00,0.0)
      ;
      goto LAB_180475ec1;
    case 7:
      plVar18 = *(longlong **)(param_1 + 0x2b8);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,2);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_d8);
      pOVar2 = (OdDgElementResolver *)*plVar18;
      if ((pOVar2 != (OdDgElementResolver *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = pOVar2, piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_d0 != (int *)0x0) && (*local_d0 = *local_d0 + -1, *local_d0 == 0)) {
        if (local_d8 != (undefined8 *)0x0) {
          (**(code **)*local_d8)(local_d8,1);
        }
        odrxFree(local_d0);
      }
      local_2f8 = (longlong *)CONCAT44(local_2f8._4_4_,2);
      OdDgElementResolver::setElementType((OdDgElementResolver *)this_00,(ElementTypes *)&local_2f8)
      ;
      bVar4 = (bool)(**(code **)(**(longlong **)(param_1 + 0x2b8) + 200))();
      OdDgTerrainVertexFeatureSettings::setDisplayTextFlag
                ((OdDgTerrainVertexFeatureSettings *)this_00,bVar4);
      (**(code **)(**(longlong **)(param_1 + 0x2b8) + 0xd8))
                (*(longlong **)(param_1 + 0x2b8),&local_288);
      OdGiAuxDataForDgDatabase::setAnnotationScale((OdGiAuxDataForDgDatabase *)this_00,local_288);
      OdDgTerrainVertexFeatureSettings::setCellYScale
                ((OdDgTerrainVertexFeatureSettings *)this_00,local_280);
      OdDgTerrainVertexFeatureSettings::setCellZScale
                ((OdDgTerrainVertexFeatureSettings *)this_00,local_278);
      OVar8 = (**(code **)(**(longlong **)(param_1 + 0x2b8) + 0xe8))();
      OdDgTerrainVertexFeatureSettings::setPointDisplayType
                ((OdDgTerrainVertexFeatureSettings *)this_00,OVar8);
      local_2c0 = (**(code **)(**(longlong **)(param_1 + 0x2b8) + 0xf8))();
      OdDgTerrainVertexFeatureSettings::setCharSymbol
                ((OdDgTerrainVertexFeatureSettings *)this_00,&local_2c0);
      uVar9 = (**(code **)(**(longlong **)(param_1 + 0x2b8) + 0x108))();
      OdDgTerrainVertexFeatureSettings::setTextStyleEntryId
                ((OdDgTerrainVertexFeatureSettings *)this_00,uVar9);
      pOVar17 = (OdString *)
                (**(code **)(**(longlong **)(param_1 + 0x2b8) + 0x118))
                          (*(longlong **)(param_1 + 0x2b8),local_188);
      OdDgTerrainVertexFeatureSettings::setCellName
                ((OdDgTerrainVertexFeatureSettings *)this_00,pOVar17);
      OdString::~OdString(local_188);
      pOVar17 = (OdString *)
                (**(code **)(**(longlong **)(param_1 + 0x2b8) + 0x128))
                          (*(longlong **)(param_1 + 0x2b8),local_180);
      OdDgTerrainVertexFeatureSettings::setPrefix
                ((OdDgTerrainVertexFeatureSettings *)this_00,pOVar17);
      OdString::~OdString(local_180);
      pOVar17 = (OdString *)
                (**(code **)(**(longlong **)(param_1 + 0x2b8) + 0x138))
                          (*(longlong **)(param_1 + 0x2b8),local_178);
      OdDgTerrainVertexFeatureSettings::setSuffix
                ((OdDgTerrainVertexFeatureSettings *)this_00,pOVar17);
      OdString::~OdString(local_178);
      dVar23 = (double)(**(code **)(**(longlong **)(param_1 + 0x2b8) + 0x148))();
      OdDgTerrainVertexFeatureSettings::setMinValue
                ((OdDgTerrainVertexFeatureSettings *)this_00,dVar23);
      goto LAB_180475ec1;
    case 8:
      plVar18 = *(longlong **)(param_1 + 0x2c0);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,2);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_c8);
      pOVar2 = (OdDgElementResolver *)*plVar18;
      if ((pOVar2 != (OdDgElementResolver *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = pOVar2, piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_c0 != (int *)0x0) && (*local_c0 = *local_c0 + -1, *local_c0 == 0)) {
        if (local_c8 != (undefined8 *)0x0) {
          (**(code **)*local_c8)(local_c8,1);
        }
        odrxFree(local_c0);
      }
      local_2f8 = (longlong *)CONCAT44(local_2f8._4_4_,3);
      OdDgElementResolver::setElementType((OdDgElementResolver *)this_00,(ElementTypes *)&local_2f8)
      ;
      bVar4 = (bool)(**(code **)(**(longlong **)(param_1 + 0x2c0) + 200))();
      OdDgTerrainVertexFeatureSettings::setDisplayTextFlag
                ((OdDgTerrainVertexFeatureSettings *)this_00,bVar4);
      (**(code **)(**(longlong **)(param_1 + 0x2c0) + 0xd8))
                (*(longlong **)(param_1 + 0x2c0),&local_288);
      OdGiAuxDataForDgDatabase::setAnnotationScale((OdGiAuxDataForDgDatabase *)this_00,local_288);
      OdDgTerrainVertexFeatureSettings::setCellYScale
                ((OdDgTerrainVertexFeatureSettings *)this_00,local_280);
      OdDgTerrainVertexFeatureSettings::setCellZScale
                ((OdDgTerrainVertexFeatureSettings *)this_00,local_278);
      OVar8 = (**(code **)(**(longlong **)(param_1 + 0x2c0) + 0xe8))();
      OdDgTerrainVertexFeatureSettings::setPointDisplayType
                ((OdDgTerrainVertexFeatureSettings *)this_00,OVar8);
      local_2be[0] = (**(code **)(**(longlong **)(param_1 + 0x2c0) + 0xf8))();
      OdDgTerrainVertexFeatureSettings::setCharSymbol
                ((OdDgTerrainVertexFeatureSettings *)this_00,local_2be);
      uVar9 = (**(code **)(**(longlong **)(param_1 + 0x2c0) + 0x108))();
      OdDgTerrainVertexFeatureSettings::setTextStyleEntryId
                ((OdDgTerrainVertexFeatureSettings *)this_00,uVar9);
      pOVar17 = (OdString *)
                (**(code **)(**(longlong **)(param_1 + 0x2c0) + 0x118))
                          (*(longlong **)(param_1 + 0x2c0),local_170);
      OdDgTerrainVertexFeatureSettings::setCellName
                ((OdDgTerrainVertexFeatureSettings *)this_00,pOVar17);
      OdString::~OdString(local_170);
      pOVar17 = (OdString *)
                (**(code **)(**(longlong **)(param_1 + 0x2c0) + 0x128))
                          (*(longlong **)(param_1 + 0x2c0),local_168);
      OdDgTerrainVertexFeatureSettings::setPrefix
                ((OdDgTerrainVertexFeatureSettings *)this_00,pOVar17);
      OdString::~OdString(local_168);
      pOVar17 = (OdString *)
                (**(code **)(**(longlong **)(param_1 + 0x2c0) + 0x138))
                          (*(longlong **)(param_1 + 0x2c0),local_160);
      OdDgTerrainVertexFeatureSettings::setSuffix
                ((OdDgTerrainVertexFeatureSettings *)this_00,pOVar17);
      pOVar17 = local_160;
LAB_180475178:
      OdString::~OdString(pOVar17);
      OdDgTerrainVertexFeatureSettings::setMinValue((OdDgTerrainVertexFeatureSettings *)this_00,0.0)
      ;
      goto LAB_180475ec1;
    case 9:
      plVar18 = *(longlong **)(param_1 + 0x2e8);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,4);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_b8);
      pOVar2 = (OdDgElementResolver *)*plVar18;
      if ((pOVar2 != (OdDgElementResolver *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = pOVar2, piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_b0 != (int *)0x0) && (*local_b0 = *local_b0 + -1, *local_b0 == 0)) {
        if (local_b8 != (undefined8 *)0x0) {
          (**(code **)*local_b8)(local_b8,1);
        }
        odrxFree(local_b0);
      }
      local_2f8 = (longlong *)((ulonglong)local_2f8 & 0xffffffff00000000);
      break;
    case 10:
      plVar18 = *(longlong **)(param_1 + 0x2f0);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,4);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_a8);
      pOVar2 = (OdDgElementResolver *)*plVar18;
      if ((pOVar2 != (OdDgElementResolver *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = pOVar2, piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_a0 != (int *)0x0) && (*local_a0 = *local_a0 + -1, *local_a0 == 0)) {
        if (local_a8 != (undefined8 *)0x0) {
          (**(code **)*local_a8)(local_a8,1);
        }
        odrxFree(local_a0);
      }
      local_2f8 = (longlong *)CONCAT44(local_2f8._4_4_,1);
      break;
    case 0xb:
      plVar18 = *(longlong **)(param_1 + 0x2f8);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,4);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_98);
      pOVar2 = (OdDgElementResolver *)*plVar18;
      if ((pOVar2 != (OdDgElementResolver *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = pOVar2, piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_90 != (int *)0x0) && (*local_90 = *local_90 + -1, *local_90 == 0)) {
        if (local_98 != (undefined8 *)0x0) {
          (**(code **)*local_98)(local_98,1);
        }
        odrxFree(local_90);
      }
      local_2f8 = (longlong *)CONCAT44(local_2f8._4_4_,2);
      break;
    case 0xc:
      plVar18 = *(longlong **)(param_1 + 0x300);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,4);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_88);
      pOVar2 = (OdDgElementResolver *)*plVar18;
      if ((pOVar2 != (OdDgElementResolver *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = pOVar2, piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_80 != (int *)0x0) && (*local_80 = *local_80 + -1, *local_80 == 0)) {
        if (local_88 != (undefined8 *)0x0) {
          (**(code **)*local_88)(local_88,1);
        }
        odrxFree(local_80);
      }
      local_2f8 = (longlong *)CONCAT44(local_2f8._4_4_,3);
      break;
    case 0xd:
      plVar18 = *(longlong **)(param_1 + 0x308);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,4);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_78);
      pOVar2 = (OdDgElementResolver *)*plVar18;
      if ((pOVar2 != (OdDgElementResolver *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = pOVar2, piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_70 != (int *)0x0) && (*local_70 = *local_70 + -1, *local_70 == 0)) {
        if (local_78 != (undefined8 *)0x0) {
          (**(code **)*local_78)(local_78,1);
        }
        odrxFree(local_70);
      }
      local_2f8 = (longlong *)CONCAT44(local_2f8._4_4_,4);
      break;
    case 0xe:
      plVar18 = *(longlong **)(param_1 + 0x310);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
        local_2f0 = (longlong *)0x0;
        plVar13 = plVar19;
      }
      plVar3 = local_2f0;
      if (plVar18 != (longlong *)0x0) {
        lVar12 = *plVar18;
        pOVar14 = OdDgTerrainOptions::desc();
        plVar13 = (longlong *)(**(code **)(lVar12 + 8))(plVar18,pOVar14);
        plVar3 = plVar13;
        if (plVar13 == (longlong *)0x0) {
          pOVar14 = OdDgTerrainOptions::desc();
          pOVar20 = (OdRxClass *)(**(code **)(*plVar18 + 0x18))(plVar18);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_2d8,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_2d8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_2f0 = plVar3;
      (**(code **)(*plVar15 + 0x88))(plVar15,4);
      plVar18 = (longlong *)(**(code **)(*plVar15 + 0x90))(plVar15,&local_68);
      pOVar2 = (OdDgElementResolver *)*plVar18;
      if ((pOVar2 != (OdDgElementResolver *)0x0) &&
         (piStack_2e0 = (int *)plVar18[1], local_2e8 = pOVar2, piStack_2e0 != (int *)0x0)) {
        *piStack_2e0 = *piStack_2e0 + 1;
      }
      piVar22 = piStack_2e0;
      this_00 = (OdDgTableElementMerge *)local_2e8;
      if ((local_60 != (int *)0x0) && (*local_60 = *local_60 + -1, *local_60 == 0)) {
        if (local_68 != (undefined8 *)0x0) {
          (**(code **)*local_68)(local_68,1);
        }
        odrxFree(local_60);
      }
      local_2f8 = (longlong *)CONCAT44(local_2f8._4_4_,5);
      break;
    default:
      piVar22 = (int *)0x0;
      this_00 = (OdDgTableElementMerge *)0x0;
      goto LAB_180475f82;
    }
    OdDgElementResolver::setElementType((OdDgElementResolver *)this_00,(ElementTypes *)&local_2f8);
LAB_180475ec1:
    if (this_00 != (OdDgTableElementMerge *)0x0) {
      uVar9 = (**(code **)(*plVar13 + 0x60))(plVar13);
      OdDgTableElementMerge::setBaseRowIndex(this_00,uVar9);
      OVar10 = (**(code **)(*plVar13 + 0x80))(plVar13);
      OdDgTerrainFeature::setFeatureType((OdDgTerrainFeature *)this_00,OVar10);
      uVar9 = (**(code **)(*plVar13 + 0x90))(plVar13);
      OdDgTextStyleDataXAttributeImpl::setBigFontId
                ((OdDgTextStyleDataXAttributeImpl *)this_00,uVar9);
      uVar9 = (**(code **)(*plVar13 + 0x70))(plVar13);
      OdDgTableElementMerge::setBaseColumnIndex(this_00,uVar9);
      dVar23 = (double)(**(code **)(*plVar13 + 0xa0))(plVar13);
      OdDgEnvMapImage::setAntialiasingStrength((OdDgEnvMapImage *)this_00,dVar23);
      bVar4 = (bool)(**(code **)(*plVar13 + 0xb0))(plVar13);
      OdDgPsPlotStyleGeneralData::setExplodeDimensionsFlag
                ((OdDgPsPlotStyleGeneralData *)this_00,bVar4);
      (**(code **)(*plVar15 + 0x68))(plVar15,uVar21);
      local_2c8 = plVar15;
      (**(code **)(*plVar15 + 0x20))(plVar15);
      FUN_1801c1cd0(param_1,0x58ec0136,&local_2c8);
    }
LAB_180475f82:
                    /* WARNING (jumptable): Ignoring partial resolution of indirect */
    if ((piVar22 != (int *)0x0) && (*piVar22 = *piVar22 + -1, *piVar22 == 0)) {
      if (this_00 != (OdDgTableElementMerge *)0x0) {
        (*(code *)**(undefined8 **)this_00)(this_00,1);
      }
      odrxFree(piVar22);
    }
    if (plVar15 != (longlong *)0x0) {
      (**(code **)(*plVar15 + 0x28))(plVar15);
      local_228 = (longlong *)0x0;
    }
    uVar21 = uVar21 + 1;
    if (0xe < uVar21) {
      OdDgTerrainTransformationXAttribute::createObject();
      (**(code **)(*local_2d8 + 0x88))(local_2d8,param_1 + 0x220);
      (**(code **)(*local_2d8 + 0x68))(local_2d8,1);
      local_res10 = local_2d8;
      (**(code **)(*local_2d8 + 0x20))(local_2d8);
      FUN_1801c1cd0(param_1,0x58ec014e,&local_res10);
      iVar11 = (**(code **)(**(longlong **)(param_1 + 0x2a8) + 0xd8))();
      if (iVar11 != 0) {
        pOVar14 = OdDgTerrainDisplayStyleXAttribute::desc();
        if (pOVar14 == (OdRxClass *)0x0) {
          OdError::OdError(local_e0,0xff);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_e0,(ThrowInfo *)&DAT_180de52b8);
        }
        pOVar14 = OdDgTerrainDisplayStyleXAttribute::desc();
        plVar19 = (longlong *)(**(code **)(*(longlong *)pOVar14 + 0x58))(pOVar14,&local_138);
        local_148 = (longlong *)0x0;
        plVar19 = (longlong *)*plVar19;
        plVar15 = local_148;
        if (plVar19 != (longlong *)0x0) {
          lVar12 = *plVar19;
          pOVar14 = OdDgTerrainDisplayStyleXAttribute::desc();
          plVar15 = (longlong *)(**(code **)(lVar12 + 8))(plVar19,pOVar14);
          if (plVar15 == (longlong *)0x0) {
            pOVar14 = OdDgTerrainDisplayStyleXAttribute::desc();
            pOVar20 = (OdRxClass *)(**(code **)(*plVar19 + 0x18))(plVar19);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_140,pOVar20,pOVar14);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_140,(ThrowInfo *)&DAT_180de5310);
          }
        }
        local_148 = plVar15;
        plVar19 = local_148;
        local_2be[1] = 8;
        local_2be[2] = 0;
        if (local_138 != (longlong *)0x0) {
          (**(code **)(*local_138 + 0x28))();
        }
        (**(code **)(*plVar19 + 0x68))(plVar19,0);
        lVar12 = *plVar19;
        uVar6 = (**(code **)(**(longlong **)(param_1 + 0x2a8) + 0xd8))();
        (**(code **)(lVar12 + 0x88))(plVar19,uVar6);
        local_res10 = plVar19;
        (**(code **)(*plVar19 + 0x20))(plVar19);
        FUN_1801c1cd0(param_1,0x58ec0001,&local_res10);
        (**(code **)(*plVar19 + 0x28))(plVar19);
      }
      (**(code **)(*local_2d8 + 0x28))(local_2d8);
      if (plVar13 != (longlong *)0x0) {
        (**(code **)(*plVar13 + 0x28))(plVar13);
      }
      FUN_1800144b0(local_260 + -0x10);
      return;
    }
  } while( true );
}



