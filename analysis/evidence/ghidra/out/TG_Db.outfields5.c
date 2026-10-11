/* ==== 1800a3600 FUN_1800a3600 ==== */

void FUN_1800a3600(longlong param_1,longlong *param_2)

{
  uint uVar1;
  uint uVar2;
  OdError_InvalidIndex local_res8 [8];
  
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x220) + -4);
  (**(code **)(*param_2 + 0x160))(param_2,uVar1);
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x228));
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      if (*(uint *)(*(longlong *)(param_1 + 0x220) + -4) <= uVar2) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      (**(code **)(*param_2 + 0x1a0))
                (param_2,(ulonglong)uVar2 * 0x10 + *(longlong *)(param_1 + 0x220));
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}



/* ==== 1800a36b0 FUN_1800a36b0 ==== */

void FUN_1800a36b0(longlong param_1,longlong *param_2)

{
  uint uVar1;
  uint uVar2;
  ulonglong uVar3;
  OdError_InvalidIndex local_res8 [8];
  
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x220) + -4);
  (**(code **)(*param_2 + 0x160))(param_2,uVar1);
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x228));
  uVar3 = 0;
  if (uVar1 != 0) {
    do {
      if (*(uint *)(*(longlong *)(param_1 + 0x220) + -4) <= (uint)uVar3) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      (**(code **)(*param_2 + 0x1a8))(param_2,*(longlong *)(param_1 + 0x220) + uVar3 * 0x18);
      uVar2 = (uint)uVar3 + 1;
      uVar3 = (ulonglong)uVar2;
    } while (uVar2 < uVar1);
  }
  return;
}



/* ==== 180171160 FUN_180171160 ==== */

void FUN_180171160(longlong param_1,longlong *param_2)

{
  int *piVar1;
  longlong *plVar2;
  int iVar3;
  short sVar4;
  longlong lVar5;
  char cVar6;
  uint uVar7;
  undefined1 *puVar8;
  short sVar9;
  char cVar10;
  longlong lVar11;
  ulonglong uVar12;
  OdError_InvalidIndex local_res8 [8];
  OdError_InvalidIndex local_res18 [8];
  OdError_InvalidIndex local_res20 [8];
  OdError_InvalidIndex local_48 [8];
  OdError_InvalidIndex local_40 [8];
  
  plVar2 = (longlong *)(param_1 + 0x318);
  cVar6 = '\0';
  uVar7 = 0;
  sVar9 = *(short *)(*plVar2 + -4);
  *(short *)(param_1 + 0x234) = sVar9;
  *(undefined1 *)(param_1 + 0x236) = 3;
  *(undefined1 *)(param_1 + 0x237) = *(undefined1 *)(*(longlong *)(param_1 + 0x310) + -4);
  cVar10 = '\0';
  if (sVar9 != 0) {
    do {
      if (*(uint *)(*plVar2 + -4) <= uVar7) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      LOCK();
      piVar1 = (int *)(*plVar2 + -0x10);
      iVar3 = *piVar1;
      *piVar1 = *piVar1;
      UNLOCK();
      if (1 < iVar3) {
        FUN_18000cbd0(plVar2,*(undefined4 *)(*plVar2 + -8),0,0,1);
      }
      cVar6 = (**(code **)(**(longlong **)(*plVar2 + (ulonglong)uVar7 * 8) + 0x68))();
      cVar6 = cVar10 + cVar6;
      uVar7 = uVar7 + 1;
      cVar10 = cVar6;
    } while (uVar7 < *(ushort *)(param_1 + 0x234));
  }
  *(char *)(param_1 + 0x239) = cVar6;
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x220));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x228));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x230));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x234));
  (**(code **)(*param_2 + 0x150))(param_2,*(undefined1 *)(param_1 + 0x236));
  (**(code **)(*param_2 + 0x150))(param_2,*(undefined1 *)(param_1 + 0x237));
  (**(code **)(*param_2 + 0x150))(param_2,*(undefined1 *)(param_1 + 0x238));
  (**(code **)(*param_2 + 0x150))(param_2,*(undefined1 *)(param_1 + 0x239));
  (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(param_1 + 0x23a));
  puVar8 = (undefined1 *)(param_1 + 0x23c);
  lVar11 = 3;
  do {
    (**(code **)(*param_2 + 0x148))(param_2,*puVar8);
    puVar8 = puVar8 + 1;
    lVar11 = lVar11 + -1;
  } while (lVar11 != 0);
  (**(code **)(*param_2 + 0x148))(param_2,*(undefined1 *)(param_1 + 0x23f));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x240));
  (**(code **)(*param_2 + 0x168))(param_2,*(undefined8 *)(param_1 + 0x248));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x250));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 600));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x25c));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x260));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x264));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x268));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x288));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x28c));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x290));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x294));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x298));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2b8));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 700));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2c0));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2c4));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2c8));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2e8));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2ec));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x2f0));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x2f8));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x300));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x308));
  uVar7 = 0;
  if (*(char *)(param_1 + 0x237) != '\0') {
    do {
      if (*(uint *)(*(longlong *)(param_1 + 0x310) + -4) <= uVar7) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res18);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res18,(ThrowInfo *)&DAT_180de5370);
      }
      lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x310) + (ulonglong)uVar7 * 8);
      (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(lVar11 + 0x10));
      (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(lVar11 + 0x18));
      (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(lVar11 + 0x20));
      (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(lVar11 + 0x24));
      (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(lVar11 + 0x28));
      (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(lVar11 + 0x2c));
      (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(lVar11 + 0x30));
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(byte *)(param_1 + 0x237));
  }
  uVar12 = 0;
  sVar9 = 0;
  if (*(short *)(param_1 + 0x234) != 0) {
    do {
      if (*(uint *)(*plVar2 + -4) <= (uint)uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res20);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res20,(ThrowInfo *)&DAT_180de5370);
      }
      lVar11 = *(longlong *)(*plVar2 + uVar12 * 8);
      *(short *)(lVar11 + 0x24) = sVar9;
      sVar4 = *(short *)(*(longlong *)(lVar11 + 0x30) + -4);
      *(short *)(lVar11 + 0x26) = sVar4;
      sVar9 = sVar9 + sVar4;
      (**(code **)(*param_2 + 0x1a8))(param_2,lVar11 + 8);
      (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(lVar11 + 0x20));
      (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(lVar11 + 0x24));
      (**(code **)(*param_2 + 0x158))(param_2,*(undefined2 *)(lVar11 + 0x26));
      (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(lVar11 + 0x28));
      (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(lVar11 + 0x2c));
      uVar7 = (uint)uVar12 + 1;
      uVar12 = (ulonglong)uVar7;
    } while (uVar7 < *(ushort *)(param_1 + 0x234));
  }
  uVar12 = 0;
  if (*(short *)(param_1 + 0x234) != 0) {
    do {
      if (*(uint *)(*plVar2 + -4) <= (uint)uVar12) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_40);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_40,(ThrowInfo *)&DAT_180de5370);
      }
      uVar7 = 0;
      lVar11 = *(longlong *)(*plVar2 + uVar12 * 8);
      if (*(short *)(lVar11 + 0x26) != 0) {
        do {
          if (*(uint *)(*(longlong *)(lVar11 + 0x30) + -4) <= uVar7) {
            OdError_InvalidIndex::OdError_InvalidIndex(local_48);
                    /* WARNING: Subroutine does not return */
            _CxxThrowException(local_48,(ThrowInfo *)&DAT_180de5370);
          }
          lVar5 = *(longlong *)(*(longlong *)(lVar11 + 0x30) + (ulonglong)uVar7 * 8);
          (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(lVar5 + 8));
          (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(lVar5 + 0xc));
          (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(lVar5 + 0x10));
          (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(lVar5 + 0x18));
          (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(lVar5 + 0x20));
          uVar7 = uVar7 + 1;
        } while (uVar7 < *(ushort *)(lVar11 + 0x26));
      }
      uVar7 = (uint)uVar12 + 1;
      uVar12 = (ulonglong)uVar7;
    } while (uVar7 < *(ushort *)(param_1 + 0x234));
  }
  return;
}



/* ==== 1801db730 FUN_1801db730 ==== */

void FUN_1801db730(longlong param_1,longlong *param_2)

{
  uint uVar1;
  uint uVar2;
  OdError_InvalidIndex local_res8 [8];
  
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x220));
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x228) + -4);
  (**(code **)(*param_2 + 0x160))(param_2,uVar1);
  uVar2 = 0;
  if (uVar1 != 0) {
    do {
      if (*(uint *)(*(longlong *)(param_1 + 0x228) + -4) <= uVar2) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      (**(code **)(*param_2 + 0x1a0))
                (param_2,(ulonglong)uVar2 * 0x10 + *(longlong *)(param_1 + 0x228));
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar1);
  }
  return;
}



/* ==== 180280df0 FUN_180280df0 ==== */

void FUN_180280df0(longlong param_1,longlong *param_2)

{
  uint uVar1;
  uint uVar2;
  longlong lVar3;
  OdError_InvalidIndex local_res8 [8];
  
  uVar2 = 0;
  uVar1 = *(uint *)(*(longlong *)(param_1 + 0x220) + -4);
  if (uVar1 != 0) {
    lVar3 = 0;
    do {
      if (*(uint *)(*(longlong *)(param_1 + 0x220) + -4) <= uVar2) {
        OdError_InvalidIndex::OdError_InvalidIndex(local_res8);
                    /* WARNING: Subroutine does not return */
        _CxxThrowException(local_res8,(ThrowInfo *)&DAT_180de5370);
      }
      (**(code **)(*param_2 + 0x170))
                (param_2,*(undefined8 *)(lVar3 + *(longlong *)(param_1 + 0x220)));
      uVar2 = uVar2 + 1;
      lVar3 = lVar3 + 8;
    } while (uVar2 < uVar1);
  }
  return;
}



/* ==== 1803e9cb0 FUN_1803e9cb0 ==== */

void FUN_1803e9cb0(longlong param_1,longlong *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar1 == 2) {
    FUN_1803eef60(param_1,param_2);
    return;
  }
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x260));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x264));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x268));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x26c));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x270));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x274));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x278));
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x27c));
                    /* WARNING: Could not recover jumptable at 0x0001803e9d89. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x160))(param_2,*(undefined4 *)(param_1 + 0x280));
  return;
}



/* ==== 1804bee80 FUN_1804bee80 ==== */

void FUN_1804bee80(longlong *param_1,longlong *param_2)

{
  int iVar1;
  longlong lVar2;
  
  if (param_2 != (longlong *)0x0) {
    iVar1 = (**(code **)(*param_2 + 0x58))(param_2);
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0001804beeb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x608))(param_1,param_2);
      return;
    }
  }
  lVar2 = 0;
  if (*(int *)(param_1[0x44] + -4) != 0) {
    lVar2 = param_1[0x44];
  }
                    /* WARNING: Could not recover jumptable at 0x0001804beee0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x140))(param_2,lVar2);
  return;
}



