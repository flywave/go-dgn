/* ==== 1801cb730 FUN_1801cb730 ==== */

void FUN_1801cb730(longlong param_1,ushort param_2,ulonglong *param_3)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  longlong **pplVar8;
  undefined8 *puVar9;
  undefined8 uVar10;
  undefined8 *puVar11;
  undefined8 *puVar12;
  ulonglong uVar13;
  undefined8 *puVar14;
  ulonglong uVar15;
  longlong *plVar16;
  undefined8 *puVar17;
  longlong *local_res8;
  longlong *local_res20;
  
  FUN_18001ab90(param_3,0);
  puVar17 = *(undefined8 **)(param_1 + 0x20);
  puVar11 = (undefined8 *)puVar17[1];
  cVar4 = *(char *)((longlong)puVar11 + 0x19);
  puVar14 = puVar17;
  puVar12 = puVar11;
  while (cVar4 == '\0') {
    if (*(ushort *)(puVar12 + 4) < param_2) {
      puVar9 = (undefined8 *)puVar12[2];
      puVar12 = puVar14;
    }
    else {
      if ((*(char *)((longlong)puVar17 + 0x19) != '\0') && (param_2 < *(ushort *)(puVar12 + 4))) {
        puVar17 = puVar12;
      }
      puVar9 = (undefined8 *)*puVar12;
    }
    puVar14 = puVar12;
    puVar12 = puVar9;
    cVar4 = *(char *)((longlong)puVar9 + 0x19);
  }
  if (*(char *)((longlong)puVar17 + 0x19) == '\0') {
    puVar11 = (undefined8 *)*puVar17;
  }
  cVar4 = *(char *)((longlong)puVar11 + 0x19);
  while (cVar4 == '\0') {
    if (param_2 < *(ushort *)(puVar11 + 4)) {
      puVar12 = (undefined8 *)*puVar11;
      puVar17 = puVar11;
    }
    else {
      puVar12 = (undefined8 *)puVar11[2];
    }
    puVar11 = puVar12;
    cVar4 = *(char *)((longlong)puVar12 + 0x19);
  }
  if (puVar14 != puVar17) {
    do {
      uVar13 = puVar14[5];
      pcVar1 = (code *)(uVar13 - 0x10);
      LOCK();
      *(int *)pcVar1 = *(int *)pcVar1 + 1;
      UNLOCK();
      iVar5 = *(int *)(uVar13 - 4);
      uVar15 = 0;
      if (iVar5 != 0) {
        uVar15 = uVar13;
      }
      uVar10 = FUN_1808bf800();
      local_res8 = (longlong *)
                   FUN_1808bf690(uVar10,&local_res20,*(undefined2 *)(puVar14 + 4),uVar15,iVar5);
      local_res8 = (longlong *)*local_res8;
      if (local_res8 != (longlong *)0x0) {
        (**(code **)(*local_res8 + 0x20))();
      }
      uVar6 = *(uint *)(*param_3 - 4);
      LOCK();
      piVar2 = (int *)(*param_3 - 0x10);
      iVar5 = *piVar2;
      *piVar2 = *piVar2;
      UNLOCK();
      if ((iVar5 < 2) && (uVar6 != *(uint *)(*param_3 - 8))) {
LAB_1801cb979:
        plVar16 = local_res8;
        *(longlong **)(*param_3 + (ulonglong)uVar6 * 8) = local_res8;
        if (local_res8 != (longlong *)0x0) {
          (**(code **)(*local_res8 + 0x20))(local_res8);
        }
      }
      else {
        if (*(int *)(*param_3 - 4) == 0) {
LAB_1801cb95f:
          FUN_18000cd30(param_3,uVar6 + 1,iVar5 < 2,0,1);
          goto LAB_1801cb979;
        }
        LOCK();
        piVar2 = (int *)(*param_3 - 0x10);
        iVar3 = *piVar2;
        *piVar2 = *piVar2;
        UNLOCK();
        if (1 < iVar3) {
          FUN_18000cd30(param_3,*(undefined4 *)(*param_3 - 8),0,0,1);
        }
        pplVar8 = (longlong **)*param_3;
        if (((*(int *)((longlong)pplVar8 - 4) == 0) || (&local_res8 < pplVar8)) ||
           (*(int *)((longlong)pplVar8 - 4) == 0)) goto LAB_1801cb95f;
        LOCK();
        pplVar8 = pplVar8 + -2;
        iVar3 = *(int *)pplVar8;
        *(int *)pplVar8 = *(int *)pplVar8;
        UNLOCK();
        if (1 < iVar3) {
          FUN_18000cd30(param_3,*(undefined4 *)(*param_3 - 8),0,0,1);
        }
        plVar16 = local_res8;
        uVar7 = *(uint *)(*param_3 - 4);
        uVar13 = 0;
        if (uVar7 != 0) {
          uVar13 = *param_3;
        }
        if ((longlong **)(uVar13 + (ulonglong)uVar7 * 8) <= &local_res8) goto LAB_1801cb95f;
        if (local_res8 != (longlong *)0x0) {
          (**(code **)(*local_res8 + 0x20))(local_res8);
        }
        FUN_18000cd30(param_3,uVar6 + 1,iVar5 < 2,0,1);
        *(longlong **)(*param_3 + (ulonglong)uVar6 * 8) = plVar16;
        if (plVar16 != (longlong *)0x0) {
          (**(code **)(*plVar16 + 0x20))(plVar16);
          (**(code **)(*plVar16 + 0x28))(plVar16);
        }
      }
      *(int *)(*param_3 - 4) = *(int *)(*param_3 - 4) + 1;
      if (plVar16 != (longlong *)0x0) {
        (**(code **)(*plVar16 + 0x28))(plVar16);
      }
      if (local_res20 != (longlong *)0x0) {
        (**(code **)(*local_res20 + 0x28))();
        local_res20 = (longlong *)0x0;
      }
      LOCK();
      iVar5 = *(int *)pcVar1;
      *(int *)pcVar1 = *(int *)pcVar1 + -1;
      UNLOCK();
      if ((iVar5 == 1) && (pcVar1 != g_empty_array_buffer_exref)) {
        odrxFree(pcVar1);
      }
      puVar11 = (undefined8 *)puVar14[2];
      if (*(char *)((longlong)puVar11 + 0x19) == '\0') {
        cVar4 = *(char *)((longlong)*puVar11 + 0x19);
        puVar14 = puVar11;
        puVar11 = (undefined8 *)*puVar11;
        while (cVar4 == '\0') {
          cVar4 = *(char *)((longlong)*puVar11 + 0x19);
          puVar14 = puVar11;
          puVar11 = (undefined8 *)*puVar11;
        }
      }
      else {
        cVar4 = *(char *)((longlong)puVar14[1] + 0x19);
        puVar12 = (undefined8 *)puVar14[1];
        puVar11 = puVar14;
        while ((puVar14 = puVar12, cVar4 == '\0' && (puVar11 == (undefined8 *)puVar14[2]))) {
          cVar4 = *(char *)((longlong)puVar14[1] + 0x19);
          puVar12 = (undefined8 *)puVar14[1];
          puVar11 = puVar14;
        }
      }
    } while (puVar14 != puVar17);
  }
  return;
}



