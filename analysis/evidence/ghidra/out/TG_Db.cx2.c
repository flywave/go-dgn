/* ==== 180123bf0 restoreIdListForUndo ==== */

/* public: virtual void __cdecl CDGComplexGeneral::restoreIdListForUndo(class OdDgFiler * __ptr64)
   __ptr64 */

void __thiscall CDGComplexGeneral::restoreIdListForUndo(CDGComplexGeneral *this,OdDgFiler *param_1)

{
  int *piVar1;
  CDGComplexGeneral *pCVar2;
  uint uVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  OdDgDatabase *pOVar7;
  OdDbHandle *pOVar8;
  undefined8 *_Src;
  ulonglong uVar9;
  ulonglong uVar10;
  longlong local_res10;
  undefined8 local_res18;
  longlong local_res20;
  undefined8 local_58;
  undefined8 local_50;
  undefined8 local_48;
  OdDbHandle local_40 [8];
  
                    /* 0x123bf0  18034
                       ?restoreIdListForUndo@CDGComplexGeneral@@UEAAXPEAVOdDgFiler@@@Z */
  iVar5 = (**(code **)(*(longlong *)param_1 + 0x58))(param_1);
  if (iVar5 != 2) {
    return;
  }
  if ((*(longlong *)(this + 0x58) != 0) &&
     (local_res10 = *(longlong *)(this + 0x58),
     pOVar7 = OdDgElementId::database((OdDgElementId *)&local_res10), pOVar7 != (OdDgDatabase *)0x0)
     ) {
    local_res18 = *(undefined8 *)(this + 0x58);
    pOVar8 = OdDgElementId::getHandle((OdDgElementId *)&local_res18);
    if (*(longlong *)pOVar8 != 0) {
      bVar4 = true;
      goto LAB_180123c60;
    }
  }
  bVar4 = false;
LAB_180123c60:
  if (bVar4) {
    pCVar2 = this + 0x220;
    FUN_18000d1e0(pCVar2);
    *(undefined4 *)(*(ulonglong *)pCVar2 - 4) = 0;
    uVar6 = (**(code **)(*(longlong *)param_1 + 0xb0))(param_1);
    if (uVar6 != 0) {
      uVar10 = (ulonglong)uVar6;
      do {
        local_50 = (**(code **)(*(longlong *)param_1 + 0xb8))(param_1);
        if (*(longlong *)(this + 0x58) == 0) {
LAB_180123d19:
          pOVar7 = *(OdDgDatabase **)(this + 0x68);
        }
        else {
          local_res20 = *(longlong *)(this + 0x58);
          pOVar7 = OdDgElementId::database((OdDgElementId *)&local_res20);
          if (pOVar7 == (OdDgDatabase *)0x0) {
LAB_180123d08:
            bVar4 = false;
          }
          else {
            local_58 = *(undefined8 *)(this + 0x58);
            pOVar8 = OdDgElementId::getHandle((OdDgElementId *)&local_58);
            if (*(longlong *)pOVar8 == 0) goto LAB_180123d08;
            bVar4 = true;
          }
          if (!bVar4) goto LAB_180123d19;
          pOVar7 = OdDgElementId::database((OdDgElementId *)(this + 0x58));
        }
        _Src = (undefined8 *)OdDgDatabase::getElementId(pOVar7,local_40);
        uVar6 = *(uint *)(*(ulonglong *)pCVar2 - 4);
        LOCK();
        piVar1 = (int *)(*(ulonglong *)pCVar2 - 0x10);
        iVar5 = *piVar1;
        *piVar1 = *piVar1;
        UNLOCK();
        if ((1 < iVar5) || (uVar6 == *(uint *)(*(ulonglong *)pCVar2 - 8))) {
          if (*(int *)(*(ulonglong *)pCVar2 - 4) == 0) {
LAB_180123d76:
            if (*(int *)(*(ulonglong *)pCVar2 - 4) != 0) {
              FUN_18000d1e0();
              uVar3 = *(uint *)(*(ulonglong *)pCVar2 - 4);
              uVar9 = 0;
              if (uVar3 != 0) {
                uVar9 = *(ulonglong *)pCVar2;
              }
              if (_Src < (undefined8 *)(uVar9 + (ulonglong)uVar3 * 8)) {
                local_48 = *_Src;
                FUN_18000cf00(pCVar2,uVar6 + 1,iVar5 < 2,0,1);
                _Src = &local_48;
                goto LAB_180123de4;
              }
            }
          }
          else {
            FUN_18000d1e0(pCVar2);
            if ((*(int *)((longlong)*(undefined8 **)pCVar2 - 4) == 0) ||
               (*(undefined8 **)pCVar2 <= _Src)) goto LAB_180123d76;
          }
          FUN_18000cf00(pCVar2,uVar6 + 1,iVar5 < 2,0,1);
        }
LAB_180123de4:
        memmove((void *)(*(ulonglong *)pCVar2 + (ulonglong)uVar6 * 8),_Src,8);
        *(int *)(*(ulonglong *)pCVar2 - 4) = *(int *)(*(ulonglong *)pCVar2 - 4) + 1;
        uVar10 = uVar10 - 1;
      } while (uVar10 != 0);
    }
  }
  return;
}



