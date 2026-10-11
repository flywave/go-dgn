/* ==== 18058c130 FUN_18058c130 ==== */

void FUN_18058c130(longlong param_1,longlong *param_2)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  bool bVar4;
  uint uVar5;
  undefined4 uVar6;
  longlong *plVar7;
  undefined8 uVar8;
  longlong *plVar9;
  longlong *plVar10;
  OdRxClass *pOVar11;
  OdDgDatabase *pOVar12;
  OdDbHandle *pOVar13;
  OdDgElementId *this;
  longlong *plVar14;
  undefined8 uVar15;
  longlong lVar16;
  undefined8 *puVar17;
  OdRxClass *pOVar18;
  OdDgNonModelElementCollection *pOVar19;
  code *pcVar20;
  longlong **pplVar21;
  undefined8 *puVar22;
  uint uVar23;
  undefined8 *puVar24;
  longlong *local_res10;
  undefined8 local_res18;
  longlong *local_res20;
  OdError_NotThatKindOfClass local_1b8 [8];
  longlong *local_1b0;
  longlong *local_1a8;
  longlong local_1a0;
  longlong local_198;
  longlong local_190;
  longlong local_188;
  code *local_180;
  longlong *local_178;
  longlong *local_170;
  longlong *local_168;
  longlong *local_160;
  longlong *local_158;
  longlong *local_150;
  longlong *local_148;
  longlong *local_140;
  longlong *local_138;
  longlong *local_130;
  longlong *local_128;
  longlong *local_120;
  longlong *local_118;
  longlong *local_110;
  longlong *local_108;
  longlong *local_100;
  longlong *local_f8;
  longlong *local_f0;
  longlong *local_e8;
  longlong *local_e0;
  longlong *local_d8;
  OdString local_d0 [8];
  longlong local_c8;
  undefined8 local_c0;
  longlong *local_b8;
  longlong local_b0;
  longlong local_a8;
  longlong *local_a0;
  undefined8 local_98;
  undefined1 local_90 [8];
  longlong *local_88;
  longlong *local_80;
  undefined1 local_78 [8];
  undefined1 local_70 [8];
  undefined1 local_68 [8];
  undefined1 local_60 [8];
  undefined1 local_58 [8];
  undefined1 local_50 [8];
  undefined1 local_48 [8];
  undefined1 local_40 [8];
  
  plVar7 = (longlong *)(**(code **)(*param_2 + 0x78))(param_2,&local_1b0,&szNonModelStorage);
  local_1a8 = (longlong *)0x0;
  plVar7 = (longlong *)*plVar7;
  plVar9 = local_1a8;
  if (plVar7 != (longlong *)0x0) {
    lVar16 = *plVar7;
    uVar8 = FUN_18004b530();
    plVar9 = (longlong *)(**(code **)(lVar16 + 8))(plVar7,uVar8);
    if (plVar9 == (longlong *)0x0) {
      pOVar11 = (OdRxClass *)FUN_18004b530();
      pOVar18 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_1a8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_1a8,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_1a8 = plVar9;
  plVar7 = local_1a8;
  if (local_1b0 != (longlong *)0x0) {
    (**(code **)(*local_1b0 + 0x28))();
    local_1b0 = (longlong *)0x0;
  }
  if (plVar7 == (longlong *)0x0) {
    OdError::OdError((OdError *)local_1b8,5);
                    /* WARNING: Subroutine does not return */
    _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de52b8);
  }
  (**(code **)(*param_2 + 0x78))(param_2,&local_res20,&szNonModelAStorage);
  local_f8 = local_res20;
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x20))();
  }
  FUN_18058e1b0(plVar7,&local_f8);
  FUN_18000d1e0((longlong *)(param_1 + 0x248));
  plVar7 = local_1a8;
  *(undefined4 *)(*(longlong *)(param_1 + 0x248) + -4) = 0;
  local_180 = g_empty_array_buffer_exref + 0x10;
  LOCK();
  *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
  UNLOCK();
  uVar5 = (**(code **)(*local_1a8 + 0x80))(local_1a8);
  uVar23 = 0;
  if (uVar5 != 0) {
    do {
      plVar9 = (longlong *)(**(code **)(*plVar7 + 0x88))(plVar7,&local_f0,uVar23);
      plVar9 = (longlong *)*plVar9;
      if (plVar9 == (longlong *)0x0) {
        local_e0 = (longlong *)0x0;
      }
      else {
        lVar16 = *plVar9;
        uVar8 = FUN_18004b540();
        local_e0 = (longlong *)(**(code **)(lVar16 + 8))(plVar9,uVar8);
      }
      plVar9 = local_e0;
      if (local_f0 != (longlong *)0x0) {
        (**(code **)(*local_f0 + 0x28))();
        local_f0 = (longlong *)0x0;
      }
      plVar10 = local_res20;
      if (plVar9 != (longlong *)0x0) {
        if (local_res20 != (longlong *)0x0) {
          uVar8 = (**(code **)(*plVar9 + 0x58))(plVar9,local_d0);
          plVar10 = (longlong *)(**(code **)(*plVar10 + 0x90))(plVar10,&local_e8,uVar8);
          plVar10 = (longlong *)*plVar10;
          if (plVar10 == (longlong *)0x0) {
            local_d8 = (longlong *)0x0;
          }
          else {
            lVar16 = *plVar10;
            pOVar11 = OdDgChunk::desc();
            local_d8 = (longlong *)(**(code **)(lVar16 + 8))(plVar10,pOVar11);
          }
          plVar10 = local_d8;
          if (local_e8 != (longlong *)0x0) {
            (**(code **)(*local_e8 + 0x28))();
            local_e8 = (longlong *)0x0;
          }
          OdString::~OdString(local_d0);
          local_168 = plVar10;
          if (plVar10 != (longlong *)0x0) {
            (**(code **)(*plVar10 + 0x20))(plVar10);
          }
          (**(code **)(*plVar9 + 0xa8))(plVar9,&local_168);
          if (plVar10 != (longlong *)0x0) {
            (**(code **)(*plVar10 + 0x28))(plVar10);
          }
        }
        if (*(longlong *)(param_1 + 0x58) == 0) {
LAB_18058c3a7:
          pOVar12 = *(OdDgDatabase **)(param_1 + 0x68);
        }
        else {
          local_c8 = *(longlong *)(param_1 + 0x58);
          pOVar12 = OdDgElementId::database((OdDgElementId *)&local_c8);
          if (pOVar12 == (OdDgDatabase *)0x0) {
LAB_18058c396:
            bVar4 = false;
          }
          else {
            local_c0 = *(undefined8 *)(param_1 + 0x58);
            pOVar13 = OdDgElementId::getHandle((OdDgElementId *)&local_c0);
            if (*(longlong *)pOVar13 == 0) goto LAB_18058c396;
            bVar4 = true;
          }
          if (!bVar4) goto LAB_18058c3a7;
          pOVar12 = OdDgElementId::database((OdDgElementId *)(param_1 + 0x58));
        }
        FUN_1809d94d0(plVar9,&local_180,0,pOVar12);
      }
      if (plVar9 != (longlong *)0x0) {
        (**(code **)(*plVar9 + 0x28))(plVar9);
      }
      uVar23 = uVar23 + 1;
    } while (uVar23 < uVar5);
  }
  FUN_18000d410(&local_180,&local_b8);
LAB_18058c3fb:
  do {
    while( true ) {
      cVar2 = (**(code **)(*local_b8 + 0x60))(local_b8);
      if (cVar2 != '\0') {
        FUN_18058bf90(param_1);
        (**(code **)(*local_b8 + 0x28))(local_b8);
        pcVar20 = local_180 + -0x10;
        LOCK();
        iVar1 = *(int *)pcVar20;
        *(int *)pcVar20 = *(int *)pcVar20 + -1;
        UNLOCK();
        if ((iVar1 == 1) && (pcVar20 != g_empty_array_buffer_exref)) {
          odrxFree();
        }
        if (local_res20 != (longlong *)0x0) {
          (**(code **)(*local_res20 + 0x28))();
          local_res20 = (longlong *)0x0;
        }
        (**(code **)(*local_1a8 + 0x28))();
        return;
      }
      plVar7 = (longlong *)(**(code **)(*local_b8 + 0x68))(local_b8,local_90);
      plVar7 = *(longlong **)(*plVar7 + 0x18);
      local_88 = plVar7;
      if (plVar7 == (longlong *)0x0) break;
      (**(code **)(*plVar7 + 0x20))(plVar7);
      pOVar11 = OdDgElement::desc();
      plVar9 = (longlong *)(**(code **)(*plVar7 + 0x18))(plVar7);
      cVar2 = (**(code **)(*plVar9 + 0x60))(plVar9,pOVar11);
      if (cVar2 != '\0') break;
      pOVar11 = OdRxObject::desc();
      plVar9 = (longlong *)(**(code **)(*plVar7 + 0x18))(plVar7);
      cVar2 = (**(code **)(*plVar9 + 0x60))(plVar9,pOVar11);
      if (cVar2 == '\0') break;
      lVar16 = *plVar7;
      pOVar11 = OdRxObject::desc();
      plVar9 = (longlong *)(**(code **)(lVar16 + 8))(plVar7,pOVar11);
      if (plVar9 == (longlong *)0x0) {
        pOVar11 = OdRxObject::desc();
        pOVar18 = (OdRxClass *)(**(code **)(*plVar7 + 0x18))(plVar7);
        OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
      }
      iVar1 = (int)plVar9[5];
      local_80 = plVar9;
      if (iVar1 == 0x22) {
        plVar10 = *(longlong **)(*(longlong *)(param_1 + 0x200) + 8);
        (**(code **)(*plVar10 + 0x328))(plVar10,plVar9);
        (**(code **)(*plVar9 + 0x28))(plVar9);
        (**(code **)(*plVar7 + 0x28))(plVar7);
        (**(code **)(*local_b8 + 0x70))(local_b8,1);
      }
      else if ((iVar1 == 0x6b) || (iVar1 == 0x42)) {
        local_a8 = plVar9[6];
        FUN_180013b80(*(longlong *)(*(longlong *)(param_1 + 0x228) + 8) + 0xb0,&local_a8);
        (**(code **)(*plVar9 + 0x28))(plVar9);
        (**(code **)(*plVar7 + 0x28))(plVar7);
        (**(code **)(*local_b8 + 0x70))(local_b8,1);
      }
      else {
        if (iVar1 != 0x62) {
          (**(code **)(*plVar9 + 0x28))(plVar9);
          break;
        }
        local_b0 = plVar9[6];
        FUN_180013b80(*(longlong *)(*(longlong *)(param_1 + 0x1f0) + 8) + 0xb0,&local_b0);
        (**(code **)(*plVar9 + 0x28))(plVar9);
        (**(code **)(*plVar7 + 0x28))(plVar7);
        (**(code **)(*local_b8 + 0x70))(local_b8,1);
      }
    }
    this = (OdDgElementId *)(**(code **)(*local_b8 + 0x68))(local_b8,local_78);
    OdDgElementId::openObject(this,(OpenMode)&local_res10,false);
    if (local_res10 == (longlong *)0x0) {
      if (plVar7 != (longlong *)0x0) {
        (**(code **)(*plVar7 + 0x28))(plVar7);
      }
      (**(code **)(*local_b8 + 0x70))(local_b8,1);
      goto LAB_18058c3fb;
    }
    uVar6 = (**(code **)(*local_res10 + 0x100))();
    plVar9 = local_res10;
    switch(uVar6) {
    case 5:
      cVar2 = (**(code **)(*local_res10 + 0x108))();
      if (cVar2 != '\x01') {
        local_160 = local_res10;
        if (local_res10 != (longlong *)0x0) {
          (**(code **)(*local_res10 + 0x20))();
        }
        pplVar21 = &local_160;
        goto LAB_18058d203;
      }
      puVar17 = (undefined8 *)(**(code **)(*local_res10 + 0x120))(local_res10,local_70);
      *(undefined8 *)(param_1 + 0x4b0) = *puVar17;
      break;
    default:
      local_170 = local_res10;
      if (local_res10 != (longlong *)0x0) {
        (**(code **)(*local_res10 + 0x20))();
      }
      pplVar21 = &local_170;
LAB_18058d203:
      pOVar19 = *(OdDgNonModelElementCollection **)(param_1 + 0x228);
LAB_18058d20a:
      OdDgNonModelElementCollection::add(pOVar19,pplVar21);
      break;
    case 9:
      puVar17 = (undefined8 *)(**(code **)(*local_res10 + 0x120))(local_res10,local_68);
      *(undefined8 *)(param_1 + 0x4a8) = *puVar17;
      break;
    case 0x22:
      local_198 = 0;
      lVar16 = local_198;
      if (local_res10 != (longlong *)0x0) {
        lVar16 = *local_res10;
        pOVar11 = OdDgSharedCellDefinition::desc();
        lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
        if (lVar16 == 0) {
          pOVar11 = OdDgSharedCellDefinition::desc();
          pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_198 = lVar16;
      OdDgSharedCellDefinitionTable::add
                (*(OdDgSharedCellDefinitionTable **)(param_1 + 0x200),&local_198);
      break;
    case 0x27:
      cVar2 = (**(code **)(*local_res10 + 0x108))();
      if ((((cVar2 != '\0') && (cVar2 = (**(code **)(*local_res10 + 0x108))(), cVar2 != -0x13)) &&
          (cVar2 = (**(code **)(*local_res10 + 0x108))(), cVar2 != -0x12)) &&
         ((cVar2 = (**(code **)(*local_res10 + 0x108))(), cVar2 != -0x14 &&
          (cVar2 = (**(code **)(*local_res10 + 0x108))(), cVar2 != -0x15)))) {
        local_140 = local_res10;
        if (local_res10 != (longlong *)0x0) {
          (**(code **)(*local_res10 + 0x20))();
        }
        pplVar21 = &local_140;
        goto LAB_18058d203;
      }
      local_138 = local_res10;
      if (local_res10 != (longlong *)0x0) {
        (**(code **)(*local_res10 + 0x20))();
      }
      OdDgTagDefinitionSetTable::add(*(OdDgTagDefinitionSetTable **)(param_1 + 0x208),&local_138);
      break;
    case 0x42:
      pOVar11 = OdDgElementTemplate::desc();
      plVar9 = (longlong *)(**(code **)(*local_res10 + 0x18))();
      cVar2 = (**(code **)(*plVar9 + 0x60))(plVar9,pOVar11);
      if (cVar2 == '\0') {
        pOVar11 = OdDgLinkSet::desc();
        plVar9 = (longlong *)(**(code **)(*local_res10 + 0x18))();
        cVar2 = (**(code **)(*plVar9 + 0x60))(plVar9,pOVar11);
        if (cVar2 == '\0') {
          pOVar11 = OdDgPrintStyleTableRecord::desc();
          plVar9 = (longlong *)(**(code **)(*local_res10 + 0x18))();
          cVar2 = (**(code **)(*plVar9 + 0x60))(plVar9,pOVar11);
          plVar9 = local_res10;
          if (cVar2 == '\0') {
            pOVar11 = OdDgColorBook::desc();
            plVar9 = (longlong *)(**(code **)(*local_res10 + 0x18))();
            cVar2 = (**(code **)(*plVar9 + 0x60))(plVar9,pOVar11);
            if (cVar2 == '\0') {
              local_118 = local_res10;
              if (local_res10 != (longlong *)0x0) {
                (**(code **)(*local_res10 + 0x20))();
              }
              pplVar21 = &local_118;
              goto LAB_18058d203;
            }
            local_120 = local_res10;
            if (local_res10 != (longlong *)0x0) {
              (**(code **)(*local_res10 + 0x20))();
            }
            OdDgColorBookTable::add(*(OdDgColorBookTable **)(param_1 + 0x220),&local_120);
          }
          else {
            local_190 = 0;
            lVar16 = local_190;
            if (local_res10 != (longlong *)0x0) {
              lVar16 = *local_res10;
              pOVar11 = OdDgPrintStyleTableRecord::desc();
              lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
              if (lVar16 == 0) {
                pOVar11 = OdDgPrintStyleTableRecord::desc();
                pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
                OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
              }
            }
            local_190 = lVar16;
            OdDgPrintStyleTable::add(*(OdDgPrintStyleTable **)(param_1 + 0x1f8),&local_190);
          }
        }
        else {
          local_128 = local_res10;
          if (local_res10 != (longlong *)0x0) {
            (**(code **)(*local_res10 + 0x20))();
          }
          OdDgLinkSetTable::add(*(OdDgLinkSetTable **)(param_1 + 0x218),&local_128);
        }
      }
      else {
        local_130 = local_res10;
        if (local_res10 != (longlong *)0x0) {
          (**(code **)(*local_res10 + 0x20))();
        }
        OdDgElementTemplateTable::add(*(OdDgElementTemplateTable **)(param_1 + 0x210),&local_130);
      }
      break;
    case 0x60:
      uVar3 = (**(code **)(*local_res10 + 0x108))();
      plVar9 = local_res10;
      switch(uVar3) {
      case 1:
        local_a0 = (longlong *)0x0;
        plVar10 = local_a0;
        if (local_res10 != (longlong *)0x0) {
          lVar16 = *local_res10;
          pOVar11 = OdDgLevelTable::desc();
          plVar10 = (longlong *)(**(code **)(lVar16 + 8))(plVar9,pOVar11);
          if (plVar10 == (longlong *)0x0) {
            pOVar11 = OdDgLevelTable::desc();
            pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
          }
        }
        local_a0 = plVar10;
        plVar10 = local_a0;
        lVar16 = local_a0[1];
        cVar2 = FUN_1805fe3e0(lVar16);
        plVar9 = local_res10;
        if (cVar2 == '\0') {
          if (*(longlong **)(param_1 + 0xc0) != (longlong *)0x0) {
            (**(code **)(**(longlong **)(param_1 + 0xc0) + 0x28))();
            *(undefined8 *)(param_1 + 0xc0) = 0;
          }
          if (plVar9 != (longlong *)0x0) {
            lVar16 = *plVar9;
            pOVar11 = OdDgLevelTable::desc();
            lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
            if (lVar16 == 0) {
              pOVar11 = OdDgLevelTable::desc();
              pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
              OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                        ((OdError_NotThatKindOfClass *)&local_1b0,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(&local_1b0,(ThrowInfo *)&DAT_180de5310);
            }
            *(longlong *)(param_1 + 0xc0) = lVar16;
          }
          FUN_1801f1bf0(*(undefined8 *)(param_1 + 0xc0));
        }
        else {
          local_98 = *(undefined8 *)(lVar16 + 0x288);
          uVar8 = FUN_180010890(param_1);
          FUN_180624190(&local_res18,uVar8,&local_98,0);
          bVar4 = OdDgElementId::isValid((OdDgElementId *)&local_res18);
          if (bVar4) {
            puVar17 = (undefined8 *)(*(undefined8 **)(param_1 + 0x198))[1];
            cVar2 = *(char *)((longlong)puVar17 + 0x19);
            puVar22 = *(undefined8 **)(param_1 + 0x198);
            while (cVar2 == '\0') {
              bVar4 = OdDgElementId::operator<
                                ((OdDgElementId *)(puVar17 + 4),(OdDgElementId *)&local_res18);
              if (bVar4) {
                puVar24 = (undefined8 *)puVar17[2];
                puVar17 = puVar22;
              }
              else {
                puVar24 = (undefined8 *)*puVar17;
              }
              puVar22 = puVar17;
              puVar17 = puVar24;
              cVar2 = *(char *)((longlong)puVar24 + 0x19);
            }
            if ((*(char *)((longlong)puVar22 + 0x19) != '\0') ||
               (bVar4 = OdDgElementId::operator<
                                  ((OdDgElementId *)&local_res18,(OdDgElementId *)(puVar22 + 4)),
               bVar4)) {
              bVar4 = false;
            }
            else {
              bVar4 = true;
            }
            if (!bVar4) {
              puVar22 = *(undefined8 **)(param_1 + 0x198);
            }
            if (puVar22 == *(undefined8 **)(param_1 + 0x198)) {
              plVar14 = (longlong *)FUN_18058a5e0(param_1 + 0x198,&local_res18);
              plVar9 = local_res10;
              if ((longlong *)*plVar14 != (longlong *)0x0) {
                (**(code **)(*(longlong *)*plVar14 + 0x28))();
                *plVar14 = 0;
              }
              if (plVar9 != (longlong *)0x0) {
                lVar16 = *plVar9;
                pOVar11 = OdDgLevelTable::desc();
                lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
                if (lVar16 == 0) {
                  pOVar11 = OdDgLevelTable::desc();
                  pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
                  OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                            ((OdError_NotThatKindOfClass *)&local_1b0,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
                  _CxxThrowException(&local_1b0,(ThrowInfo *)&DAT_180de5310);
                }
                goto LAB_18058c888;
              }
            }
          }
          else {
            uVar8 = FUN_180010890(param_1);
            uVar8 = FUN_1805fd800(lVar16,local_60,uVar8);
            uVar15 = FUN_180010890(param_1);
            puVar17 = (undefined8 *)FUN_180624190(local_58,uVar15,uVar8,0);
            local_res18 = *puVar17;
            bVar4 = OdDgElementId::isValid((OdDgElementId *)&local_res18);
            if (bVar4) {
              plVar14 = (longlong *)FUN_18058a5e0(param_1 + 0x198,&local_res18);
              plVar9 = local_res10;
              if ((longlong *)*plVar14 != (longlong *)0x0) {
                (**(code **)(*(longlong *)*plVar14 + 0x28))();
                *plVar14 = 0;
              }
              if (plVar9 != (longlong *)0x0) {
                lVar16 = *plVar9;
                pOVar11 = OdDgLevelTable::desc();
                lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
                if (lVar16 == 0) {
                  pOVar11 = OdDgLevelTable::desc();
                  pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
                  OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                            ((OdError_NotThatKindOfClass *)&local_1b0,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
                  _CxxThrowException(&local_1b0,(ThrowInfo *)&DAT_180de5310);
                }
LAB_18058c888:
                *plVar14 = lVar16;
              }
            }
            else {
              local_158 = local_res10;
              if (local_res10 != (longlong *)0x0) {
                (**(code **)(*local_res10 + 0x20))();
              }
              OdDgNonModelElementCollection::add
                        (*(OdDgNonModelElementCollection **)(param_1 + 0x228),&local_158);
              uVar8 = (**(code **)(*local_res10 + 0x120))(local_res10,local_50);
              FUN_1802b8480(param_1 + 0x248,uVar8);
            }
          }
        }
        (**(code **)(*plVar10 + 0x28))(plVar10);
        break;
      case 2:
        if (*(longlong **)(param_1 + 200) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(param_1 + 200) + 0x28))();
          *(undefined8 *)(param_1 + 200) = 0;
        }
        if (plVar9 != (longlong *)0x0) {
          lVar16 = *plVar9;
          pOVar11 = OdDgFontTable::desc();
          lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
          if (lVar16 == 0) {
            pOVar11 = OdDgFontTable::desc();
            pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
          }
          *(longlong *)(param_1 + 200) = lVar16;
        }
        FUN_1801f1bf0(*(undefined8 *)(param_1 + 200));
        break;
      case 3:
        if (*(longlong **)(param_1 + 0xd0) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(param_1 + 0xd0) + 0x28))();
          *(undefined8 *)(param_1 + 0xd0) = 0;
        }
        if (plVar9 != (longlong *)0x0) {
          lVar16 = *plVar9;
          pOVar11 = OdDgTextStyleTable::desc();
          lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
          if (lVar16 == 0) {
            pOVar11 = OdDgTextStyleTable::desc();
            pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
          }
          *(longlong *)(param_1 + 0xd0) = lVar16;
        }
        FUN_1801f1bf0(*(undefined8 *)(param_1 + 0xd0));
        break;
      case 4:
        if (*(longlong **)(param_1 + 0x110) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(param_1 + 0x110) + 0x28))();
          *(undefined8 *)(param_1 + 0x110) = 0;
        }
        if (plVar9 != (longlong *)0x0) {
          lVar16 = *plVar9;
          pOVar11 = OdDgLevelFilterTable::desc();
          lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
          if (lVar16 == 0) {
            pOVar11 = OdDgLevelFilterTable::desc();
            pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
          }
          *(longlong *)(param_1 + 0x110) = lVar16;
        }
        FUN_1801f1bf0(*(undefined8 *)(param_1 + 0x110));
        break;
      case 5:
        if (*(longlong **)(param_1 + 0xd8) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(param_1 + 0xd8) + 0x28))();
          *(undefined8 *)(param_1 + 0xd8) = 0;
        }
        if (plVar9 != (longlong *)0x0) {
          lVar16 = *plVar9;
          pOVar11 = OdDgDimStyleTable::desc();
          lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
          if (lVar16 == 0) {
            pOVar11 = OdDgDimStyleTable::desc();
            pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
          }
          *(longlong *)(param_1 + 0xd8) = lVar16;
        }
        FUN_1801f1bf0(*(undefined8 *)(param_1 + 0xd8));
        break;
      case 6:
        if (*(longlong **)(param_1 + 0xf0) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(param_1 + 0xf0) + 0x28))();
          *(undefined8 *)(param_1 + 0xf0) = 0;
        }
        if (plVar9 != (longlong *)0x0) {
          lVar16 = *plVar9;
          pOVar11 = OdDgMultilineStyleTable::desc();
          lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
          if (lVar16 == 0) {
            pOVar11 = OdDgMultilineStyleTable::desc();
            pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
          }
          *(longlong *)(param_1 + 0xf0) = lVar16;
        }
        FUN_1801f1bf0(*(undefined8 *)(param_1 + 0xf0));
        break;
      case 7:
        if (*(longlong **)(param_1 + 0xf8) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(param_1 + 0xf8) + 0x28))();
          *(undefined8 *)(param_1 + 0xf8) = 0;
        }
        if (plVar9 != (longlong *)0x0) {
          lVar16 = *plVar9;
          pOVar11 = OdDgLineStyleTable::desc();
          lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
          if (lVar16 == 0) {
            pOVar11 = OdDgLineStyleTable::desc();
            pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
          }
          *(longlong *)(param_1 + 0xf8) = lVar16;
        }
        FUN_1801f1bf0(*(undefined8 *)(param_1 + 0xf8));
        plVar9 = *(longlong **)(param_1 + 0xf8);
        if (plVar9 != (longlong *)0x0) {
          (**(code **)(*plVar9 + 0x20))(plVar9);
        }
        plVar10 = (longlong *)plVar9[1];
        (**(code **)(*plVar9 + 0x28))(plVar9);
        (**(code **)(*plVar10 + 0x698))(plVar10);
        break;
      case 8:
        if (*(longlong **)(param_1 + 0x100) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(param_1 + 0x100) + 0x28))();
          *(undefined8 *)(param_1 + 0x100) = 0;
        }
        if (plVar9 != (longlong *)0x0) {
          lVar16 = *plVar9;
          pOVar11 = OdDgLineStyleDefTable::desc();
          lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
          if (lVar16 == 0) {
            pOVar11 = OdDgLineStyleDefTable::desc();
            pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
          }
          *(longlong *)(param_1 + 0x100) = lVar16;
        }
        FUN_1801f1bf0(*(undefined8 *)(param_1 + 0x100));
        break;
      case 9:
        local_150 = local_res10;
        if (local_res10 != (longlong *)0x0) {
          (**(code **)(*local_res10 + 0x20))();
        }
        pplVar21 = &local_150;
        pOVar19 = *(OdDgNonModelElementCollection **)(param_1 + 0x238);
        goto LAB_18058d20a;
      case 10:
        if (*(longlong **)(param_1 + 0x108) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(param_1 + 0x108) + 0x28))();
          *(undefined8 *)(param_1 + 0x108) = 0;
        }
        if (plVar9 != (longlong *)0x0) {
          lVar16 = *plVar9;
          pOVar11 = OdDgRegAppTable::desc();
          lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
          if (lVar16 == 0) {
            pOVar11 = OdDgRegAppTable::desc();
            pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
          }
          *(longlong *)(param_1 + 0x108) = lVar16;
        }
        FUN_1801f1bf0(*(undefined8 *)(param_1 + 0x108));
        break;
      default:
        local_148 = local_res10;
        if (local_res10 != (longlong *)0x0) {
          (**(code **)(*local_res10 + 0x20))();
        }
        pplVar21 = &local_148;
        goto LAB_18058d203;
      case 0x12:
        if (*(longlong **)(param_1 + 0xe0) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(param_1 + 0xe0) + 0x28))();
          *(undefined8 *)(param_1 + 0xe0) = 0;
        }
        if (plVar9 != (longlong *)0x0) {
          lVar16 = *plVar9;
          pOVar11 = OdDgMaterialTable::desc();
          lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
          if (lVar16 == 0) {
            pOVar11 = OdDgMaterialTable::desc();
            pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
          }
          *(longlong *)(param_1 + 0xe0) = lVar16;
        }
        FUN_1801f1bf0(*(undefined8 *)(param_1 + 0xe0));
        break;
      case 0x13:
        if (*(longlong **)(param_1 + 0xb8) != (longlong *)0x0) {
          (**(code **)(**(longlong **)(param_1 + 0xb8) + 0x28))();
          *(undefined8 *)(param_1 + 0xb8) = 0;
        }
        if (plVar9 != (longlong *)0x0) {
          lVar16 = *plVar9;
          pOVar11 = OdDgLevelMaskIndexTable::desc();
          lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
          if (lVar16 == 0) {
            pOVar11 = OdDgLevelMaskIndexTable::desc();
            pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
            OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
          }
          *(longlong *)(param_1 + 0xb8) = lVar16;
        }
        FUN_1801f1bf0(*(undefined8 *)(param_1 + 0xb8));
      }
      break;
    case 0x61:
      local_188 = 0;
      lVar16 = local_188;
      if (local_res10 != (longlong *)0x0) {
        lVar16 = *local_res10;
        pOVar11 = OdDgViewGroup::desc();
        lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
        if (lVar16 == 0) {
          pOVar11 = OdDgViewGroup::desc();
          pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_188 = lVar16;
      OdDgViewGroupTable::add(*(OdDgViewGroupTable **)(param_1 + 0x1e8),&local_188);
      break;
    case 0x62:
      local_1a0 = 0;
      lVar16 = local_1a0;
      if (local_res10 != (longlong *)0x0) {
        lVar16 = *local_res10;
        pOVar11 = OdDgView::desc();
        lVar16 = (**(code **)(lVar16 + 8))(plVar9,pOVar11);
        if (lVar16 == 0) {
          pOVar11 = OdDgView::desc();
          pOVar18 = (OdRxClass *)(**(code **)(*plVar9 + 0x18))(plVar9);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass(local_1b8,pOVar18,pOVar11);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(local_1b8,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_1a0 = lVar16;
      OdDgNamedViewTable::add(*(OdDgNamedViewTable **)(param_1 + 0x1f0),&local_1a0);
      break;
    case 0x6b:
      pOVar11 = OdDgEnvironmentMapTable::desc();
      plVar9 = (longlong *)(**(code **)(*local_res10 + 0x18))();
      cVar2 = (**(code **)(*plVar9 + 0x60))(plVar9,pOVar11);
      if (cVar2 == '\0') {
        pOVar11 = OdDgDisplayStyleTable::desc();
        plVar9 = (longlong *)(**(code **)(*local_res10 + 0x18))();
        cVar2 = (**(code **)(*plVar9 + 0x60))(plVar9,pOVar11);
        if (cVar2 == '\0') {
          pOVar11 = OdDgPrototypeElement::desc();
          plVar9 = (longlong *)(**(code **)(*local_res10 + 0x18))();
          cVar2 = (**(code **)(*plVar9 + 0x60))(plVar9,pOVar11);
          if (cVar2 == '\0') {
            local_178 = local_res10;
            if (local_res10 != (longlong *)0x0) {
              (**(code **)(*local_res10 + 0x20))();
            }
            pplVar21 = &local_178;
            goto LAB_18058d203;
          }
          local_100 = local_res10;
          if (local_res10 != (longlong *)0x0) {
            (**(code **)(*local_res10 + 0x20))();
          }
          OdDgPrototypeElementTable::add
                    (*(OdDgPrototypeElementTable **)(param_1 + 0x240),&local_100);
        }
        else {
          if (*(longlong *)(param_1 + 0x4c0) != 0) {
            local_108 = local_res10;
            if (local_res10 != (longlong *)0x0) {
              (**(code **)(*local_res10 + 0x20))();
            }
            pplVar21 = &local_108;
            goto LAB_18058d203;
          }
          puVar17 = (undefined8 *)(**(code **)(*local_res10 + 0x120))(local_res10,local_40);
          *(undefined8 *)(param_1 + 0x4c0) = *puVar17;
        }
      }
      else {
        if (*(longlong *)(param_1 + 0x4b8) != 0) {
          local_110 = local_res10;
          if (local_res10 != (longlong *)0x0) {
            (**(code **)(*local_res10 + 0x20))();
          }
          pplVar21 = &local_110;
          goto LAB_18058d203;
        }
        puVar17 = (undefined8 *)(**(code **)(*local_res10 + 0x120))(local_res10,local_48);
        *(undefined8 *)(param_1 + 0x4b8) = *puVar17;
      }
    }
    if (local_res10 != (longlong *)0x0) {
      (**(code **)(*local_res10 + 0x28))();
      local_res10 = (longlong *)0x0;
    }
    if (plVar7 != (longlong *)0x0) {
      (**(code **)(*plVar7 + 0x28))(plVar7);
    }
    (**(code **)(*local_b8 + 0x70))(local_b8,1);
  } while( true );
}



/* ==== 1809e5830 FUN_1809e5830 ==== */

void FUN_1809e5830(longlong param_1,longlong *param_2)

{
  ulonglong *puVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  bool bVar5;
  code *pcVar6;
  int *piVar7;
  OdRxClass *pOVar8;
  OdAnsiString *pOVar9;
  undefined8 *puVar10;
  longlong *plVar11;
  undefined8 uVar12;
  longlong *plVar13;
  longlong *plVar14;
  OdDgDatabase *pOVar15;
  OdDbHandle *pOVar16;
  longlong *plVar17;
  OdString *this;
  char *pcVar18;
  OdRxClass *pOVar19;
  ulonglong uVar20;
  uint uVar21;
  longlong *plVar22;
  OdDgModel *this_00;
  uint uVar23;
  longlong *plVar24;
  longlong local_res8;
  int local_res10 [2];
  undefined8 local_res18;
  uint local_res20 [2];
  longlong *local_1b8;
  longlong *local_1b0;
  longlong *local_1a8;
  longlong *local_1a0;
  longlong *local_198;
  longlong *local_190;
  longlong *local_188;
  OdDgModel *local_180;
  longlong *local_178;
  longlong *local_170;
  longlong *local_168;
  longlong *local_160;
  longlong *local_158;
  longlong *local_150;
  longlong *local_148;
  longlong *local_140;
  longlong *local_138;
  longlong *local_130;
  longlong *local_128;
  longlong *local_120;
  longlong *local_118;
  OdString local_110 [8];
  OdString local_108 [8];
  longlong *local_100;
  longlong *local_f8;
  longlong *local_f0;
  longlong *local_e8;
  Error local_e0 [8];
  OdAnsiString local_d8 [8];
  undefined8 local_d0;
  code *local_c8;
  longlong *local_c0;
  undefined1 local_b8 [8];
  longlong local_b0;
  longlong local_a8;
  undefined8 local_a0;
  code *local_98;
  longlong *local_90;
  undefined1 local_88 [8];
  OdAnsiString local_80 [8];
  OdString local_78 [8];
  undefined1 local_70 [8];
  undefined1 local_68 [8];
  undefined1 local_60 [8];
  undefined1 local_58 [24];
  
  plVar22 = *(longlong **)(param_1 + 8);
  lVar3 = plVar22[2];
  local_res8 = param_1;
  local_1a0 = plVar22;
  Dgn8::Error::Error((Error *)local_res10,5,"C:\\B\\1\\_\\_\\Dgn\\source\\DgDefsInternal.h",0x134);
  (**(code **)(*param_2 + 0x78))(param_2,&local_e8,&szDesignFileIndexStorage);
  if (local_e8 != (longlong *)0x0) {
    (**(code **)(*local_e8 + 0x90))(local_e8,&local_168,&szDesignFileIndexStream);
    if (local_168 != (longlong *)0x0) {
      plVar17 = *(longlong **)(lVar3 + 0x118);
      if (plVar17 != (longlong *)0x0) {
        (**(code **)(*plVar17 + 0x20))(plVar17);
      }
      plVar24 = (longlong *)plVar17[1];
      (**(code **)(*plVar17 + 0x28))(plVar17);
      piVar7 = (int *)(**(code **)(*plVar24 + 0x328))(plVar24,local_88,local_168);
      local_res10[0] = *piVar7;
    }
    if (local_168 != (longlong *)0x0) {
      (**(code **)(*local_168 + 0x28))();
    }
  }
  piVar7 = (int *)Dgn8::Error::Error(local_e0,0,"C:\\B\\1\\_\\_\\Dgn\\source\\DgDefsInternal.h",
                                     0x134);
  bVar5 = true;
  if (local_res10[0] == *piVar7) {
    plVar17 = *(longlong **)(lVar3 + 0x118);
    if (plVar17 != (longlong *)0x0) {
      (**(code **)(*plVar17 + 0x20))(plVar17);
    }
    lVar4 = plVar17[1];
    (**(code **)(*plVar17 + 0x28))(plVar17);
    bVar5 = true;
    if (*(int *)(*(longlong *)(lVar4 + 0xd0) + -4) != 0) {
      bVar5 = false;
    }
  }
  (**(code **)(*param_2 + 0x78))(param_2,&local_1b8,&szModelRootStorage);
  if (local_1b8 != (longlong *)0x0) {
    plVar17 = *(longlong **)(lVar3 + 0x118);
    if (plVar17 != (longlong *)0x0) {
      (**(code **)(*plVar17 + 0x20))(plVar17);
    }
    plVar24 = (longlong *)plVar17[1];
    local_138 = plVar24;
    (**(code **)(*plVar17 + 0x28))(plVar17);
    if (bVar5) {
      local_res20[0] = (**(code **)(*local_1b8 + 0x68))();
      uVar21 = 0;
      local_res18 = (longlong *)((ulonglong)local_res18._4_4_ << 0x20);
      uVar23 = local_res20[0];
      if (local_res20[0] != 0) {
        do {
          (**(code **)(*local_1b8 + 0x70))(local_1b8,&local_1b0,uVar21);
          if (local_1b0 != (longlong *)0x0) {
            OdDgModel::createObject();
            this_00 = local_180;
            OdDgModel::setModelIs3dFlag(local_180,false);
            OdString::OdString(local_108,(ushort *)L"Model");
            OdDgModel::setName(this_00,local_108);
            OdString::~OdString(local_108);
            plVar17 = *(longlong **)(this_00 + 8);
            local_178 = plVar17;
            if (plVar17[0xb] != 0) {
              local_b0 = plVar17[0xb];
              pOVar15 = OdDgElementId::database((OdDgElementId *)&local_b0);
              if (pOVar15 == (OdDgDatabase *)0x0) {
LAB_1809e6023:
                bVar5 = false;
              }
              else {
                local_a8 = plVar17[0xb];
                pOVar16 = OdDgElementId::getHandle((OdDgElementId *)&local_a8);
                bVar5 = true;
                if (*(longlong *)pOVar16 == 0) goto LAB_1809e6023;
              }
              if (bVar5) {
                OdError::OdError((OdError *)&local_res8,0x1f);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(&local_res8,(ThrowInfo *)&DAT_180de52b8);
              }
            }
            plVar24 = local_1b0;
            plVar17[0xd] = (longlong)plVar22;
            lVar3 = *(longlong *)(param_1 + 8);
            lVar4 = *(longlong *)(lVar3 + 0x10);
            if (local_1b0 == (longlong *)0x0) {
              OdError::OdError((OdError *)&local_res8,0x14);
                    /* WARNING: Subroutine does not return */
              _CxxThrowException(&local_res8,(ThrowInfo *)&DAT_180de52b8);
            }
            plVar22 = *(longlong **)(this_00 + 8);
            (**(code **)(*local_1b0 + 0x90))(local_1b0,&local_140,&szModelHeaderStream);
            if (local_140 != (longlong *)0x0) {
              (**(code **)(*plVar22 + 0x3f8))(plVar22,local_b8);
            }
            FUN_1806175e0(local_60,lVar3,this_00,plVar22[0x218],0);
            if (*(char *)(lVar4 + 0xd10) != '\0') {
              puVar10 = (undefined8 *)(**(code **)(*(longlong *)this_00 + 0x120))(this_00,local_58);
              puVar1 = (ulonglong *)(lVar4 + 0xd18);
              uVar21 = *(uint *)(*puVar1 - 4);
              LOCK();
              piVar7 = (int *)(*puVar1 - 0x10);
              iVar2 = *piVar7;
              *piVar7 = *piVar7;
              UNLOCK();
              if ((1 < iVar2) || (uVar21 == *(uint *)(*puVar1 - 8))) {
                if (*(int *)(*puVar1 - 4) == 0) {
LAB_1809e610d:
                  if (*(int *)(*puVar1 - 4) != 0) {
                    FUN_18000d1e0();
                    uVar23 = *(uint *)(*puVar1 - 4);
                    uVar20 = 0;
                    if (uVar23 != 0) {
                      uVar20 = *puVar1;
                    }
                    if (puVar10 < (undefined8 *)(uVar20 + (ulonglong)uVar23 * 8)) {
                      local_a0 = *puVar10;
                      FUN_18000cf00(puVar1,uVar21 + 1,iVar2 < 2,0,1);
                      puVar10 = &local_a0;
                      goto LAB_1809e6179;
                    }
                  }
                }
                else {
                  FUN_18000d1e0(puVar1);
                  if ((*(int *)((longlong)*puVar1 - 4) == 0) || ((undefined8 *)*puVar1 <= puVar10))
                  goto LAB_1809e610d;
                }
                FUN_18000cf00(puVar1,uVar21 + 1,iVar2 < 2,0,1);
              }
LAB_1809e6179:
              memmove((void *)(*puVar1 + (ulonglong)uVar21 * 8),puVar10,8);
              *(int *)(*puVar1 - 4) = *(int *)(*puVar1 - 4) + 1;
              pcVar6 = g_empty_array_buffer_exref;
              local_98 = g_empty_array_buffer_exref + 0x10;
              LOCK();
              *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
              UNLOCK();
              FUN_18018cc70(lVar4 + 0xd20,&local_98);
              LOCK();
              iVar2 = *(int *)pcVar6;
              *(int *)pcVar6 = *(int *)pcVar6 + -1;
              UNLOCK();
              this_00 = local_180;
              if ((iVar2 == 1) && (pcVar6 != g_empty_array_buffer_exref)) {
                odrxFree(pcVar6);
                this_00 = local_180;
              }
            }
            plVar17 = (longlong *)
                      (**(code **)(*plVar24 + 0x78))(plVar24,&local_100,&szGraphicElementsStorage);
            local_90 = (longlong *)0x0;
            plVar17 = (longlong *)*plVar17;
            plVar11 = local_90;
            if (plVar17 != (longlong *)0x0) {
              lVar3 = *plVar17;
              uVar12 = FUN_18004b530();
              plVar11 = (longlong *)(**(code **)(lVar3 + 8))(plVar17,uVar12);
              if (plVar11 == (longlong *)0x0) {
                pOVar8 = (OdRxClass *)FUN_18004b530();
                pOVar19 = (OdRxClass *)(**(code **)(*plVar17 + 0x18))(plVar17);
                OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                          ((OdError_NotThatKindOfClass *)&local_res8,pOVar19,pOVar8);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(&local_res8,(ThrowInfo *)&DAT_180de5310);
              }
            }
            local_90 = plVar11;
            plVar17 = local_90;
            if (local_100 != (longlong *)0x0) {
              (**(code **)(*local_100 + 0x28))();
              local_100 = (longlong *)0x0;
            }
            (**(code **)(*plVar24 + 0x78))(plVar24,&local_188,&szGraphicElementsAStorage);
            if (plVar17 != (longlong *)0x0) {
              local_f8 = local_188;
              if (local_188 != (longlong *)0x0) {
                (**(code **)(*local_188 + 0x20))();
              }
              FUN_18058e1b0(plVar17,&local_f8);
              FUN_1809e4d70(local_res8,plVar17,local_188,plVar22,0);
            }
            plVar11 = (longlong *)
                      (**(code **)(*plVar24 + 0x78))(plVar24,&local_f0,&szControlElementsStorage);
            local_130 = (longlong *)0x0;
            plVar11 = (longlong *)*plVar11;
            plVar13 = local_130;
            if (plVar11 != (longlong *)0x0) {
              lVar3 = *plVar11;
              uVar12 = FUN_18004b530();
              plVar13 = (longlong *)(**(code **)(lVar3 + 8))(plVar11,uVar12);
              if (plVar13 == (longlong *)0x0) {
                pOVar8 = (OdRxClass *)FUN_18004b530();
                pOVar19 = (OdRxClass *)(**(code **)(*plVar11 + 0x18))(plVar11);
                OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                          ((OdError_NotThatKindOfClass *)&local_res8,pOVar19,pOVar8);
                    /* WARNING: Subroutine does not return */
                _CxxThrowException(&local_res8,(ThrowInfo *)&DAT_180de5310);
              }
            }
            local_130 = plVar13;
            plVar11 = local_130;
            if (local_f0 != (longlong *)0x0) {
              (**(code **)(*local_f0 + 0x28))();
              local_f0 = (longlong *)0x0;
            }
            (**(code **)(*plVar24 + 0x78))(plVar24,&local_190,&szControlElementsAStorage);
            param_1 = local_res8;
            if (plVar11 != (longlong *)0x0) {
              local_160 = local_190;
              if (local_190 != (longlong *)0x0) {
                (**(code **)(*local_190 + 0x20))();
              }
              FUN_18058e1b0(plVar11,&local_160);
              param_1 = local_res8;
              FUN_1809e4d70(local_res8,plVar11,local_190,plVar22,1);
            }
            *(ushort *)(plVar22 + 9) = *(ushort *)(plVar22 + 9) & 0xfffb;
            (**(code **)(*plVar22 + 0x18))(plVar22,0);
            (**(code **)(*plVar22 + 8))(plVar22,0);
            *(uint *)plVar22[0xb] = *(uint *)plVar22[0xb] | 0x40000000;
            if (local_190 != (longlong *)0x0) {
              (**(code **)(*local_190 + 0x28))();
              local_190 = (longlong *)0x0;
            }
            if (plVar11 != (longlong *)0x0) {
              (**(code **)(*plVar11 + 0x28))(plVar11);
            }
            if (local_188 != (longlong *)0x0) {
              (**(code **)(*local_188 + 0x28))();
              local_188 = (longlong *)0x0;
            }
            if (plVar17 != (longlong *)0x0) {
              (**(code **)(*plVar17 + 0x28))(plVar17);
            }
            if (local_140 != (longlong *)0x0) {
              (**(code **)(*local_140 + 0x28))();
              local_140 = (longlong *)0x0;
            }
            this = (OdString *)(**(code **)(*local_1b0 + 0x58))(local_1b0,local_78);
            pcVar18 = OdString::operator_char_const____ptr64(this);
            uVar12 = OdAnsiString::OdAnsiString(local_80,pcVar18);
            FUN_1805ee550(local_178,uVar12);
            OdAnsiString::~OdAnsiString(local_80);
            OdString::~OdString(local_78);
            plVar24 = local_138;
            (**(code **)(*local_138 + 0x2b8))(local_138,this_00);
            (**(code **)(*(longlong *)this_00 + 0x28))(this_00);
            local_180 = (OdDgModel *)0x0;
            plVar22 = local_1a0;
            uVar21 = (uint)local_res18;
            uVar23 = local_res20[0];
          }
          if (local_1b0 != (longlong *)0x0) {
            (**(code **)(*local_1b0 + 0x28))();
            local_1b0 = (longlong *)0x0;
          }
          uVar21 = uVar21 + 1;
          local_res18 = (longlong *)CONCAT44(local_res18._4_4_,uVar21);
        } while (uVar21 < uVar23);
      }
    }
    else {
      plVar22 = plVar24 + 0x1a;
      plVar17 = (longlong *)0x0;
      plVar11 = plVar17;
      if (*(int *)(*plVar22 + -4) != 0) {
        LOCK();
        piVar7 = (int *)(*plVar22 + -0x10);
        iVar2 = *piVar7;
        *piVar7 = *piVar7;
        UNLOCK();
        if (1 < iVar2) {
          FUN_18000cd30(plVar22,*(undefined4 *)(*plVar22 + -8),0,0,1);
        }
        if (*(int *)(*plVar22 + -4) != 0) {
          plVar11 = (longlong *)*plVar22;
        }
      }
      local_res18 = plVar11;
      if (*(int *)(*plVar22 + -4) != 0) {
        LOCK();
        piVar7 = (int *)(*plVar22 + -0x10);
        iVar2 = *piVar7;
        *piVar7 = *piVar7;
        UNLOCK();
        if (1 < iVar2) {
          FUN_18000cd30(plVar22,*(undefined4 *)(*plVar22 + -8),0,0,1);
        }
        uVar21 = *(uint *)(*plVar22 + -4);
        if (uVar21 != 0) {
          plVar17 = (longlong *)*plVar22;
        }
        plVar17 = plVar17 + uVar21;
      }
      local_178 = plVar17;
      if (plVar11 != plVar17) {
        do {
          plVar22 = (longlong *)*plVar11;
          if (plVar22 == (longlong *)0x0) {
            local_158 = (longlong *)0x0;
          }
          else {
            lVar3 = *plVar22;
            pOVar8 = OdDgModel::desc();
            local_158 = (longlong *)(**(code **)(lVar3 + 8))(plVar22,pOVar8);
          }
          plVar22 = local_158;
          if (local_158 != (longlong *)0x0) {
            pOVar9 = (OdAnsiString *)FUN_1805ddf10(local_158[1],local_d8);
            OdString::OdString(local_110,pOVar9);
            OdAnsiString::~OdAnsiString(local_d8);
            (**(code **)(*local_1b8 + 0x78))(local_1b8,&local_148,local_110);
            plVar24 = local_148;
            if (local_148 != (longlong *)0x0) {
              lVar3 = *(longlong *)(param_1 + 8);
              lVar4 = *(longlong *)(lVar3 + 0x10);
              plVar17 = (longlong *)plVar22[1];
              (**(code **)(*local_148 + 0x90))(local_148,&local_150,&szModelHeaderStream);
              if (local_150 != (longlong *)0x0) {
                (**(code **)(*plVar17 + 0x3f8))(plVar17,local_res20);
              }
              FUN_1806175e0(local_70,lVar3,plVar22,plVar17[0x218],0);
              if (*(char *)(lVar4 + 0xd10) != '\0') {
                puVar10 = (undefined8 *)(**(code **)(*plVar22 + 0x120))(plVar22,local_68);
                puVar1 = (ulonglong *)(lVar4 + 0xd18);
                uVar21 = *(uint *)(*puVar1 - 4);
                LOCK();
                piVar7 = (int *)(*puVar1 - 0x10);
                iVar2 = *piVar7;
                *piVar7 = *piVar7;
                UNLOCK();
                if ((1 < iVar2) || (uVar21 == *(uint *)(*puVar1 - 8))) {
                  if (*(int *)(*puVar1 - 4) == 0) {
LAB_1809e5bab:
                    if (*(int *)(*puVar1 - 4) != 0) {
                      FUN_18000d1e0();
                      uVar23 = *(uint *)(*puVar1 - 4);
                      uVar20 = 0;
                      if (uVar23 != 0) {
                        uVar20 = *puVar1;
                      }
                      if (puVar10 < (undefined8 *)(uVar20 + (ulonglong)uVar23 * 8)) {
                        local_d0 = *puVar10;
                        FUN_18000cf00(puVar1,uVar21 + 1,iVar2 < 2,0,1);
                        puVar10 = &local_d0;
                        goto LAB_1809e5c17;
                      }
                    }
                  }
                  else {
                    FUN_18000d1e0(puVar1);
                    if ((*(int *)((longlong)*puVar1 - 4) == 0) || ((undefined8 *)*puVar1 <= puVar10)
                       ) goto LAB_1809e5bab;
                  }
                  FUN_18000cf00(puVar1,uVar21 + 1,iVar2 < 2,0,1);
                }
LAB_1809e5c17:
                memmove((void *)(*puVar1 + (ulonglong)uVar21 * 8),puVar10,8);
                *(int *)(*puVar1 - 4) = *(int *)(*puVar1 - 4) + 1;
                pcVar6 = g_empty_array_buffer_exref;
                local_c8 = g_empty_array_buffer_exref + 0x10;
                LOCK();
                *(int *)g_empty_array_buffer_exref = *(int *)g_empty_array_buffer_exref + 1;
                UNLOCK();
                FUN_18018cc70(lVar4 + 0xd20,&local_c8);
                LOCK();
                iVar2 = *(int *)pcVar6;
                *(int *)pcVar6 = *(int *)pcVar6 + -1;
                UNLOCK();
                plVar22 = local_158;
                if ((iVar2 == 1) && (pcVar6 != g_empty_array_buffer_exref)) {
                  odrxFree(pcVar6);
                  plVar22 = local_158;
                }
              }
              plVar11 = (longlong *)
                        (**(code **)(*plVar24 + 0x78))(plVar24,&local_128,&szGraphicElementsStorage)
              ;
              local_c0 = (longlong *)0x0;
              plVar11 = (longlong *)*plVar11;
              plVar13 = local_c0;
              if (plVar11 != (longlong *)0x0) {
                lVar3 = *plVar11;
                uVar12 = FUN_18004b530();
                plVar13 = (longlong *)(**(code **)(lVar3 + 8))(plVar11,uVar12);
                if (plVar13 == (longlong *)0x0) {
                  pOVar8 = (OdRxClass *)FUN_18004b530();
                  pOVar19 = (OdRxClass *)(**(code **)(*plVar11 + 0x18))(plVar11);
                  OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                            ((OdError_NotThatKindOfClass *)&local_res8,pOVar19,pOVar8);
                    /* WARNING: Subroutine does not return */
                  _CxxThrowException(&local_res8,(ThrowInfo *)&DAT_180de5310);
                }
              }
              local_c0 = plVar13;
              plVar11 = local_c0;
              if (local_128 != (longlong *)0x0) {
                (**(code **)(*local_128 + 0x28))();
                local_128 = (longlong *)0x0;
              }
              (**(code **)(*plVar24 + 0x78))(plVar24,&local_198,&szGraphicElementsAStorage);
              if (plVar11 != (longlong *)0x0) {
                local_120 = local_198;
                if (local_198 != (longlong *)0x0) {
                  (**(code **)(*local_198 + 0x20))();
                }
                FUN_18058e1b0(plVar11,&local_120);
                FUN_1809e4d70(local_res8,plVar11,local_198,plVar17,0);
              }
              plVar13 = (longlong *)
                        (**(code **)(*plVar24 + 0x78))(plVar24,&local_118,&szControlElementsStorage)
              ;
              local_1a0 = (longlong *)0x0;
              plVar13 = (longlong *)*plVar13;
              plVar14 = local_1a0;
              if (plVar13 != (longlong *)0x0) {
                lVar3 = *plVar13;
                uVar12 = FUN_18004b530();
                plVar14 = (longlong *)(**(code **)(lVar3 + 8))(plVar13,uVar12);
                if (plVar14 == (longlong *)0x0) {
                  pOVar8 = (OdRxClass *)FUN_18004b530();
                  pOVar19 = (OdRxClass *)(**(code **)(*plVar13 + 0x18))(plVar13);
                  OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                            ((OdError_NotThatKindOfClass *)&local_res8,pOVar19,pOVar8);
                    /* WARNING: Subroutine does not return */
                  _CxxThrowException(&local_res8,(ThrowInfo *)&DAT_180de5310);
                }
              }
              local_1a0 = plVar14;
              plVar13 = local_1a0;
              if (local_118 != (longlong *)0x0) {
                (**(code **)(*local_118 + 0x28))();
                local_118 = (longlong *)0x0;
              }
              (**(code **)(*plVar24 + 0x78))(plVar24,&local_1a8,&szControlElementsAStorage);
              param_1 = local_res8;
              if (plVar13 != (longlong *)0x0) {
                local_170 = local_1a8;
                if (local_1a8 != (longlong *)0x0) {
                  (**(code **)(*local_1a8 + 0x20))();
                }
                FUN_18058e1b0(plVar13,&local_170);
                param_1 = local_res8;
                FUN_1809e4d70(local_res8,plVar13,local_1a8,plVar17,1);
              }
              *(ushort *)(plVar17 + 9) = *(ushort *)(plVar17 + 9) & 0xfffb;
              (**(code **)(*plVar17 + 0x18))(plVar17,0);
              (**(code **)(*plVar17 + 8))(plVar17,0);
              *(uint *)plVar17[0xb] = *(uint *)plVar17[0xb] | 0x40000000;
              if (local_1a8 != (longlong *)0x0) {
                (**(code **)(*local_1a8 + 0x28))();
                local_1a8 = (longlong *)0x0;
              }
              if (plVar13 != (longlong *)0x0) {
                (**(code **)(*plVar13 + 0x28))(plVar13);
              }
              if (local_198 != (longlong *)0x0) {
                (**(code **)(*local_198 + 0x28))();
                local_198 = (longlong *)0x0;
              }
              if (plVar11 != (longlong *)0x0) {
                (**(code **)(*plVar11 + 0x28))(plVar11);
              }
              if (local_150 != (longlong *)0x0) {
                (**(code **)(*local_150 + 0x28))();
                local_150 = (longlong *)0x0;
              }
              (**(code **)(*local_138 + 0x2b8))(local_138,plVar22);
              plVar11 = local_res18;
              plVar17 = local_178;
            }
            if (local_148 != (longlong *)0x0) {
              (**(code **)(*local_148 + 0x28))(local_148);
              local_148 = (longlong *)0x0;
            }
            OdString::~OdString(local_110);
            (**(code **)(*plVar22 + 0x28))(plVar22);
          }
          plVar11 = plVar11 + 1;
          plVar24 = local_138;
          local_res18 = plVar11;
        } while (plVar11 != plVar17);
      }
    }
    plVar24 = plVar24 + 0x1a;
    LOCK();
    piVar7 = (int *)(*plVar24 + -0x10);
    iVar2 = *piVar7;
    *piVar7 = *piVar7;
    UNLOCK();
    if (1 < iVar2) {
      FUN_18000cd30(plVar24,*(undefined4 *)(*plVar24 + -8),0,0,1);
    }
    uVar21 = *(uint *)(*plVar24 + -4);
    uVar20 = (ulonglong)uVar21;
    if (uVar21 != 0) {
      plVar22 = (longlong *)(*plVar24 + uVar20 * 8);
      do {
        uVar23 = (int)uVar20 - 1;
        uVar20 = (ulonglong)uVar23;
        plVar22 = plVar22 + -1;
        if ((longlong *)*plVar22 != (longlong *)0x0) {
          (**(code **)(*(longlong *)*plVar22 + 0x28))();
          *plVar22 = 0;
        }
      } while (uVar23 != 0);
    }
    *(int *)(*plVar24 + -4) = *(int *)(*plVar24 + -4) - uVar21;
  }
  if (local_1b8 != (longlong *)0x0) {
    (**(code **)(*local_1b8 + 0x28))();
    local_1b8 = (longlong *)0x0;
  }
  if (local_e8 != (longlong *)0x0) {
    (**(code **)(*local_e8 + 0x28))();
  }
  return;
}



/* ==== 1809e68a0 FUN_1809e68a0 ==== */

void FUN_1809e68a0(longlong *param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  longlong lVar3;
  OdRxDynamicLinker *pOVar4;
  longlong *plVar5;
  OdRxClass *pOVar6;
  longlong *plVar7;
  _func_void *p_Var8;
  OdRxClass *pOVar9;
  longlong *plVar10;
  ulonglong uVar11;
  longlong *local_res18;
  longlong *local_res20;
  longlong *local_a8;
  longlong *local_a0;
  undefined4 local_98;
  undefined4 local_94;
  longlong local_90;
  undefined4 local_88;
  longlong *local_80;
  _RTL_CRITICAL_SECTION local_78;
  undefined1 local_40 [24];
  
  OdString::OdString((OdString *)&local_a0,(ushort *)L"ThreadPool");
  pOVar4 = odrxDynamicLinker();
  plVar5 = (longlong *)(**(code **)(*(longlong *)pOVar4 + 0x88))(pOVar4,&local_res20,&local_a0,1);
  plVar10 = (longlong *)0x0;
  local_a8 = (longlong *)0x0;
  plVar5 = (longlong *)*plVar5;
  plVar7 = local_a8;
  if (plVar5 != (longlong *)0x0) {
    lVar3 = *plVar5;
    pOVar6 = OdRxThreadPoolService::desc();
    plVar7 = (longlong *)(**(code **)(lVar3 + 8))(plVar5,pOVar6);
    if (plVar7 == (longlong *)0x0) {
      pOVar6 = OdRxThreadPoolService::desc();
      pOVar9 = (OdRxClass *)(**(code **)(*plVar5 + 0x18))(plVar5);
      OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                ((OdError_NotThatKindOfClass *)&local_a8,pOVar9,pOVar6);
                    /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_a8,(ThrowInfo *)&DAT_180de5310);
    }
  }
  local_a8 = plVar7;
  plVar5 = local_a8;
  if (local_res20 != (longlong *)0x0) {
    (**(code **)(*local_res20 + 0x28))();
    local_res20 = (longlong *)0x0;
  }
  OdString::~OdString((OdString *)&local_a0);
  if (plVar5 == (longlong *)0x0) {
    FUN_1809e6fa0(param_1);
  }
  else {
    if (param_2 == 0) {
      param_2 = (**(code **)(*plVar5 + 0x80))(plVar5);
    }
    uVar11 = (ulonglong)param_2;
    (**(code **)(*plVar5 + 0xb0))(plVar5,&local_res18,1,uVar11,1);
    local_98 = 0xffffffff;
    local_94 = 0xffffffff;
    InitializeCriticalSection(&local_78);
    local_90 = 0;
    local_88 = 1000;
    LOCK();
    UNLOCK();
    LOCK();
    UNLOCK();
    LOCK();
    local_98 = 0;
    UNLOCK();
    local_94 = *(undefined4 *)(param_1[5] + -4);
    LOCK();
    UNLOCK();
    local_80 = param_1;
    plVar5 = (longlong *)odrxAlloc(0x58);
    if (plVar5 == (longlong *)0x0) {
      p_Var8 = std::get_new_handler();
      if (p_Var8 == (_func_void *)0x0) {
        FUN_1800044e0(local_40);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_40,(ThrowInfo *)&DAT_180de5280);
      }
      (*p_Var8)();
    }
    if (plVar5 != (longlong *)0x0) {
      *plVar5 = 0;
      plVar5[1] = 0;
      plVar5[2] = 0;
      plVar5[3] = 0;
      plVar5[4] = 0;
      plVar5[5] = 0;
      plVar5[6] = 0;
      plVar5[7] = 0;
      plVar5[8] = 0;
      plVar5[9] = 0;
      *plVar5 = (longlong)OdDgRestoreElementsThread::vftable;
      *(undefined4 *)(plVar5 + 1) = 0xffffffff;
      *(undefined4 *)((longlong)plVar5 + 0xc) = 0xffffffff;
      InitializeCriticalSection((LPCRITICAL_SECTION)(plVar5 + 5));
      plVar5[2] = 0;
      *(undefined4 *)(plVar5 + 3) = 1000;
      *(undefined4 *)(plVar5 + 1) = 0;
      LOCK();
      *(undefined4 *)(plVar5 + 1) = 0;
      UNLOCK();
      *(undefined4 *)((longlong)plVar5 + 0xc) = 0;
      LOCK();
      *(undefined4 *)((longlong)plVar5 + 0xc) = 0;
      UNLOCK();
      plVar5[4] = 0;
      *plVar5 = (longlong)
                OdRxObjectImpl<OdDgRestoreElementsThread,OdDgRestoreElementsThread>::vftable;
      *(undefined4 *)(plVar5 + 10) = 0xffffffff;
      *(undefined4 *)(plVar5 + 10) = 0;
      LOCK();
      *(undefined4 *)(plVar5 + 10) = 1;
      UNLOCK();
      plVar10 = plVar5;
    }
    plVar10[2] = local_90;
    *(undefined4 *)(plVar10 + 3) = local_88;
    *(undefined4 *)(plVar10 + 1) = local_98;
    *(undefined4 *)((longlong)plVar10 + 0xc) = local_94;
    plVar10[4] = (longlong)local_80;
    LOCK();
    puVar1 = (undefined4 *)((longlong)plVar10 + 0xc);
    uVar2 = *puVar1;
    *puVar1 = *puVar1;
    UNLOCK();
    *(undefined4 *)(plVar10 + 3) = uVar2;
    local_res20 = plVar10;
    if (*(longlong **)(plVar10[4] + 0x18) != (longlong *)0x0) {
      (**(code **)(**(longlong **)(plVar10[4] + 0x18) + 0x20))();
    }
    local_a0 = plVar10;
    (**(code **)(*plVar10 + 0x20))(plVar10);
    (**(code **)(*plVar10 + 0x28))(plVar10);
    if (param_2 != 0) {
      do {
        (**(code **)(*local_res18 + 0x68))(local_res18,plVar10,1);
        uVar11 = uVar11 - 1;
      } while (uVar11 != 0);
    }
    (**(code **)(*local_res18 + 0x78))();
    (**(code **)(*param_1 + 0x68))(param_1);
    (**(code **)(*plVar10 + 0x28))(plVar10);
    DeleteCriticalSection(&local_78);
    plVar5 = local_a8;
    if (local_res18 != (longlong *)0x0) {
      (**(code **)(*local_res18 + 0x28))();
      local_res18 = (longlong *)0x0;
      plVar5 = local_a8;
    }
  }
  if (plVar5 != (longlong *)0x0) {
    (**(code **)(*plVar5 + 0x28))(plVar5);
  }
  return;
}



/* ==== 1809e6bd0 FUN_1809e6bd0 ==== */

void FUN_1809e6bd0(longlong param_1)

{
  longlong lVar1;
  longlong *plVar2;
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  while (lVar1 != 0) {
    plVar2 = *(longlong **)(param_1 + 0x40);
    (**(code **)(*plVar2 + 0x58))(plVar2);
    *(longlong *)(param_1 + 0x40) = plVar2[1];
    (**(code **)(*plVar2 + 0x28))(plVar2);
    lVar1 = *(longlong *)(param_1 + 0x40);
  }
  return;
}



/* ==== 1809e6fa0 FUN_1809e6fa0 ==== */

void FUN_1809e6fa0(longlong *param_1)

{
  longlong *plVar1;
  longlong lVar2;
  char cVar3;
  undefined8 *puVar4;
  OdRxClass *pOVar5;
  longlong *plVar6;
  undefined8 uVar7;
  OdRxClass *pOVar8;
  uint *local_res8;
  longlong *local_res10;
  undefined1 local_res18 [16];
  
  plVar1 = (longlong *)param_1[3];
  if (plVar1 != (longlong *)0x0) {
    (**(code **)(*plVar1 + 0x20))(plVar1,*(undefined4 *)(param_1[5] + -4));
  }
  local_res8 = (uint *)0x0;
  do {
    puVar4 = (undefined8 *)(**(code **)(*param_1 + 0x70))(param_1,local_res18);
    local_res8 = (uint *)*puVar4;
    if ((local_res8 != (uint *)0x0) && ((*local_res8 & 0x20000000) != 0)) {
      local_res10 = (longlong *)0x0;
      plVar1 = *(longlong **)(local_res8 + 6);
      plVar6 = local_res10;
      if (plVar1 != (longlong *)0x0) {
        lVar2 = *plVar1;
        pOVar5 = OdRxObject::desc();
        plVar6 = (longlong *)(**(code **)(lVar2 + 8))(plVar1,pOVar5);
        if (plVar6 == (longlong *)0x0) {
          pOVar5 = OdRxObject::desc();
          pOVar8 = (OdRxClass *)(**(code **)(*plVar1 + 0x18))(plVar1);
          OdError_NotThatKindOfClass::OdError_NotThatKindOfClass
                    ((OdError_NotThatKindOfClass *)&local_res10,pOVar8,pOVar5);
                    /* WARNING: Subroutine does not return */
          _CxxThrowException(&local_res10,(ThrowInfo *)&DAT_180de5310);
        }
      }
      local_res10 = plVar6;
      plVar1 = local_res10;
      if ((local_res10 != (longlong *)0x0) &&
         (cVar3 = (**(code **)(*local_res10 + 0x90))(local_res10), cVar3 == '\0')) {
        uVar7 = (**(code **)(*plVar1 + 0x68))(plVar1);
        FUN_1809e22a0(uVar7,&local_res8,*(undefined1 *)((longlong)param_1 + 0x21),1);
      }
      if (plVar1 != (longlong *)0x0) {
        (**(code **)(*plVar1 + 0x28))(plVar1);
      }
    }
    if ((longlong *)param_1[3] != (longlong *)0x0) {
      (**(code **)(*(longlong *)param_1[3] + 0x18))();
    }
  } while (local_res8 != (uint *)0x0);
  return;
}



