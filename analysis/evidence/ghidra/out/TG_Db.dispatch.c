/* ==== 1809dc0c0 FUN_1809dc0c0 ==== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

Error * FUN_1809dc0c0(Error *param_1,uint *param_2,char param_3,longlong *param_4)

{
  uint uVar1;
  longlong lVar2;
  longlong *plVar3;
  bool bVar4;
  OdDgnClassMap *pOVar5;
  longlong *plVar6;
  OdRxClass *pOVar7;
  Error *pEVar8;
  ulonglong uVar9;
  uint *puVar10;
  Error *pEVar11;
  uint uVar12;
  bool bVar13;
  ulonglong local_res10;
  uint local_res18;
  ulonglong in_stack_ffffffffffffff98;
  longlong *local_58;
  longlong *local_50;
  OdDgDatabase *local_48;
  
  pEVar8 = (Error *)0x0;
  uVar1 = *param_2;
  uVar12 = param_2[1];
  local_res10 = *(ulonglong *)(param_2 + 2);
  local_res18 = param_2[4];
  local_48 = *(OdDgDatabase **)(param_2 + 8);
  if ((uVar1 == 0x27) && (uVar12 != 0x1c)) {
    uVar12 = 0;
  }
  switch(uVar1) {
  case 2:
  case 3:
  case 4:
  case 6:
  case 7:
  case 0xb:
  case 0xd:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x15:
  case 0x16:
  case 0x1b:
  case 0x57:
    bVar13 = local_res18 != 0;
    pOVar5 = odDgnClassMap();
    plVar6 = (longlong *)FUN_1809e0b60(pOVar5,&local_58,uVar1 & 0xffff,bVar13);
    plVar6 = (longlong *)*plVar6;
    if (plVar6 == (longlong *)0x0) {
      local_50 = (longlong *)0x0;
    }
    else {
      lVar2 = *plVar6;
      OdDgElement::desc();
      local_50 = (longlong *)(**(code **)(lVar2 + 8))(plVar6);
    }
    plVar3 = local_50;
    puVar10 = param_2 + 10;
    plVar6 = *(longlong **)puVar10;
    if (plVar6 != local_50) {
      if (plVar6 != (longlong *)0x0) {
        (**(code **)(*plVar6 + 0x28))();
        puVar10[0] = 0;
        puVar10[1] = 0;
      }
      *(longlong **)puVar10 = plVar3;
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 0x20))(plVar3);
      }
    }
    if (plVar3 != (longlong *)0x0) {
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    if (local_58 != (longlong *)0x0) {
      (**(code **)(*local_58 + 0x28))();
    }
    break;
  case 5:
  case 0x21:
  case 0x27:
  case 0x42:
  case 0x5b:
  case 0x5f:
  case 0x60:
  case 0x69:
    pOVar5 = odDgnClassMap();
    plVar6 = (longlong *)FUN_1809e0b60(pOVar5,&local_50,uVar1 & 0xffff,uVar12 & 0xff);
    plVar6 = (longlong *)*plVar6;
    if (plVar6 == (longlong *)0x0) {
      local_58 = (longlong *)0x0;
    }
    else {
      lVar2 = *plVar6;
      OdDgElement::desc();
      local_58 = (longlong *)(**(code **)(lVar2 + 8))(plVar6);
    }
    plVar3 = local_58;
    puVar10 = param_2 + 10;
    plVar6 = *(longlong **)puVar10;
    if (plVar6 != local_58) {
      if (plVar6 != (longlong *)0x0) {
        (**(code **)(*plVar6 + 0x28))();
        puVar10[0] = 0;
        puVar10[1] = 0;
      }
      *(longlong **)puVar10 = plVar3;
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 0x20))(plVar3);
      }
    }
    if (plVar3 != (longlong *)0x0) {
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    if (local_50 != (longlong *)0x0) {
      (**(code **)(*local_50 + 0x28))();
    }
    break;
  default:
    pOVar5 = odDgnClassMap();
    plVar6 = (longlong *)FUN_1809e0b60(pOVar5,&local_58,uVar1 & 0xffff,0);
    plVar6 = (longlong *)*plVar6;
    if (plVar6 == (longlong *)0x0) {
      local_50 = (longlong *)0x0;
    }
    else {
      lVar2 = *plVar6;
      OdDgElement::desc();
      local_50 = (longlong *)(**(code **)(lVar2 + 8))(plVar6);
    }
    plVar3 = local_50;
    puVar10 = param_2 + 10;
    plVar6 = *(longlong **)puVar10;
    if (plVar6 != local_50) {
      if (plVar6 != (longlong *)0x0) {
        (**(code **)(*plVar6 + 0x28))();
        puVar10[0] = 0;
        puVar10[1] = 0;
      }
      *(longlong **)puVar10 = plVar3;
      if (plVar3 != (longlong *)0x0) {
        (**(code **)(*plVar3 + 0x20))(plVar3);
      }
    }
    if (plVar3 != (longlong *)0x0) {
      (**(code **)(*plVar3 + 0x28))(plVar3);
    }
    if (local_58 != (longlong *)0x0) {
      (**(code **)(*local_58 + 0x28))();
    }
  }
  bVar13 = false;
  puVar10 = param_2 + 10;
  if (*(longlong *)puVar10 == 0) {
    if (param_2[5] == 0) {
      if (param_2[6] == 0) {
        OdDgProxyElement::createObject();
        FUN_1801c0070(puVar10);
        if (local_50 != (longlong *)0x0) {
          (**(code **)(*local_50 + 0x28))();
        }
      }
      else {
        OdDgProxyGraphicsElement::createObject();
        FUN_1801c0070(puVar10);
        if (local_50 != (longlong *)0x0) {
          (**(code **)(*local_50 + 0x28))();
        }
      }
    }
    else if (param_2[6] == 0) {
      OdDgComplexProxyElement::createObject();
      FUN_1801c0070(puVar10);
      if (local_50 != (longlong *)0x0) {
        (**(code **)(*local_50 + 0x28))();
      }
    }
    else {
      OdDgComplexProxyGraphicsElement::createObject();
      FUN_1801c0070(puVar10);
      if (local_50 != (longlong *)0x0) {
        (**(code **)(*local_50 + 0x28))();
      }
    }
  }
  uVar9 = local_res10;
  if (param_3 == '\0') {
    if (param_4 == (longlong *)0x0) {
      in_stack_ffffffffffffff98 = local_res10;
      OdDgDatabase::addOdDgElement(local_48,&local_res10,*(undefined8 *)puVar10,_kNull,local_res10);
    }
    else {
LAB_1809dc40c:
      plVar6 = *(longlong **)puVar10;
      if (plVar6 != (longlong *)0x0) {
        lVar2 = *param_4;
        plVar3 = *(longlong **)(lVar2 + 0x18);
        if (plVar3 != plVar6) {
          if (plVar3 != (longlong *)0x0) {
            (**(code **)(*plVar3 + 0x28))();
            *(undefined8 *)(lVar2 + 0x18) = 0;
          }
          *(longlong **)(lVar2 + 0x18) = plVar6;
          if (plVar6 != (longlong *)0x0) {
            (**(code **)(*plVar6 + 0x20))(plVar6);
          }
        }
        FUN_1809e3aa0(*(undefined8 *)(*(longlong *)puVar10 + 8));
        uVar9 = local_res10;
      }
    }
  }
  else if (param_4 != (longlong *)0x0) goto LAB_1809dc40c;
  plVar6 = (longlong *)
           __RTDynamicCast(*(undefined8 *)(*(longlong *)puVar10 + 8),0,
                           &OdDgElementImpl::RTTI_Type_Descriptor,
                           &CDGElementGeneral::RTTI_Type_Descriptor,
                           in_stack_ffffffffffffff98 & 0xffffffff00000000);
  if (plVar6 == (longlong *)0x0) goto LAB_1809dc508;
  plVar6[0x1a] = uVar9;
  pEVar11 = param_1;
  if (uVar12 == 0) {
    plVar3 = *(longlong **)puVar10;
    if (plVar3 != (longlong *)0x0) {
      lVar2 = *plVar3;
      pOVar7 = OdDgGraphicsElement::desc();
      pEVar8 = (Error *)(**(code **)(lVar2 + 8))(plVar3,pOVar7);
    }
    bVar13 = true;
    pEVar11 = pEVar8;
    if (pEVar8 == (Error *)0x0) goto LAB_1809dc4c4;
    bVar4 = true;
  }
  else {
LAB_1809dc4c4:
    bVar4 = false;
  }
  if ((bVar13) && (pEVar11 != (Error *)0x0)) {
    (**(code **)(*(longlong *)pEVar11 + 0x28))(pEVar11);
  }
  if (bVar4) {
    uVar12 = 0x40;
  }
  (**(code **)(*plVar6 + 0x450))(plVar6,uVar12);
  (**(code **)(*plVar6 + 0x470))(plVar6);
LAB_1809dc508:
  Dgn8::Error::Error(param_1,0,"C:\\B\\1\\_\\_\\Dgn\\source\\DgDefsInternal.h",0x134);
  return param_1;
}



