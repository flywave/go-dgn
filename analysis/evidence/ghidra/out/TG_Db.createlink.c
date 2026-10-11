/* ==== 1801cb470 FUN_1801cb470 ==== */

void FUN_1801cb470(longlong param_1,ulonglong *param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  longlong *plVar8;
  longlong **pplVar9;
  longlong *plVar10;
  undefined8 uVar11;
  ulonglong uVar12;
  longlong *plVar13;
  longlong *plVar14;
  longlong *local_res8;
  longlong *local_res18;
  ulonglong local_res20;
  
  FUN_18001ab90(param_2,0);
  plVar13 = (longlong *)**(longlong **)(param_1 + 0x20);
  plVar8 = *(longlong **)(param_1 + 0x20);
  if (plVar13 != plVar8) {
    do {
      local_res20 = plVar13[5];
      pcVar1 = (code *)(local_res20 - 0x10);
      LOCK();
      *(int *)pcVar1 = *(int *)pcVar1 + 1;
      UNLOCK();
      iVar5 = *(int *)(local_res20 - 4);
      uVar12 = 0;
      if (iVar5 != 0) {
        uVar12 = local_res20;
      }
      uVar11 = FUN_1808bf800();
      local_res8 = (longlong *)FUN_1808bf690(uVar11,&local_res18,(short)plVar13[4],uVar12,iVar5);
      local_res8 = (longlong *)*local_res8;
      if (local_res8 != (longlong *)0x0) {
        (**(code **)(*local_res8 + 0x20))();
      }
      uVar6 = *(uint *)(*param_2 - 4);
      LOCK();
      piVar2 = (int *)(*param_2 - 0x10);
      iVar5 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if ((iVar5 < 2) && (uVar6 != *(uint *)(*param_2 - 8))) {
LAB_1801cb64f:
        plVar14 = local_res8;
        *(longlong **)(*param_2 + (ulonglong)uVar6 * 8) = local_res8;
        if (local_res8 != (longlong *)0x0) {
          (**(code **)(*local_res8 + 0x20))(local_res8);
        }
      }
      else {
        if (*(int *)(*param_2 - 4) == 0) {
LAB_1801cb635:
          FUN_18000cd30(param_2,uVar6 + 1,iVar5 < 2,0,1);
          goto LAB_1801cb64f;
        }
        LOCK();
        piVar2 = (int *)(*param_2 - 0x10);
        iVar3 = *piVar2;
        *piVar2 = *piVar2;
        UNLOCK();
        if (1 < iVar3) {
          FUN_18000cd30(param_2,*(undefined4 *)(*param_2 - 8),0,0,1);
        }
        pplVar9 = (longlong **)*param_2;
        if (((*(int *)((longlong)pplVar9 - 4) == 0) || (&local_res8 < pplVar9)) ||
           (*(int *)((longlong)pplVar9 - 4) == 0)) goto LAB_1801cb635;
        LOCK();
        pplVar9 = pplVar9 + -2;
        iVar3 = *(int *)pplVar9;
        *(int *)pplVar9 = *(int *)pplVar9;
        UNLOCK();
        if (1 < iVar3) {
          FUN_18000cd30(param_2,*(undefined4 *)(*param_2 - 8),0,0,1);
        }
        plVar14 = local_res8;
        uVar7 = *(uint *)(*param_2 - 4);
        uVar12 = 0;
        if (uVar7 != 0) {
          uVar12 = *param_2;
        }
        if ((longlong **)(uVar12 + (ulonglong)uVar7 * 8) <= &local_res8) goto LAB_1801cb635;
        if (local_res8 != (longlong *)0x0) {
          (**(code **)(*local_res8 + 0x20))(local_res8);
        }
        FUN_18000cd30(param_2,uVar6 + 1,iVar5 < 2,0,1);
        *(longlong **)(*param_2 + (ulonglong)uVar6 * 8) = plVar14;
        if (plVar14 != (longlong *)0x0) {
          (**(code **)(*plVar14 + 0x20))(plVar14);
          (**(code **)(*plVar14 + 0x28))(plVar14);
        }
      }
      *(int *)(*param_2 - 4) = *(int *)(*param_2 - 4) + 1;
      if (plVar14 != (longlong *)0x0) {
        (**(code **)(*plVar14 + 0x28))(plVar14);
      }
      if (local_res18 != (longlong *)0x0) {
        (**(code **)(*local_res18 + 0x28))();
        local_res18 = (longlong *)0x0;
      }
      LOCK();
      iVar5 = *(int *)pcVar1;
      *(int *)pcVar1 = *(int *)pcVar1 + -1;
      UNLOCK();
      if ((iVar5 == 1) && (pcVar1 != g_empty_array_buffer_exref)) {
        odrxFree(pcVar1);
      }
      plVar14 = (longlong *)plVar13[2];
      if (*(char *)((longlong)plVar14 + 0x19) == '\0') {
        cVar4 = *(char *)(*plVar14 + 0x19);
        plVar13 = plVar14;
        plVar14 = (longlong *)*plVar14;
        while (cVar4 == '\0') {
          cVar4 = *(char *)(*plVar14 + 0x19);
          plVar13 = plVar14;
          plVar14 = (longlong *)*plVar14;
        }
      }
      else {
        cVar4 = *(char *)(plVar13[1] + 0x19);
        plVar10 = (longlong *)plVar13[1];
        plVar14 = plVar13;
        while ((plVar13 = plVar10, cVar4 == '\0' && (plVar14 == (longlong *)plVar13[2]))) {
          cVar4 = *(char *)(plVar13[1] + 0x19);
          plVar10 = (longlong *)plVar13[1];
          plVar14 = plVar13;
        }
      }
    } while (plVar13 != plVar8);
  }
  return;
}



