/* ==== 180024850 OdDgTable ==== */

/* protected: __cdecl OdDgTable::OdDgTable(class OdDgElementImpl * __ptr64) __ptr64 */

OdDgTable * __thiscall OdDgTable::OdDgTable(OdDgTable *this,OdDgElementImpl *param_1)

{
                    /* 0x24850  1486  ??0OdDgTable@@IEAA@PEAVOdDgElementImpl@@@Z */
  OdDgElement::OdDgElement((OdDgElement *)this,param_1);
  *(undefined ***)this = vftable;
  return this;
}



/* ==== 1804bea00 FUN_1804bea00 ==== */

undefined8 FUN_1804bea00(longlong *param_1,longlong *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  
  if (param_2 != (longlong *)0x0) {
    iVar2 = (**(code **)(*param_2 + 0x58))(param_2);
    if (iVar2 != 0) {
      (**(code **)(*param_1 + 0x600))(param_1,param_2);
      return 0;
    }
  }
  iVar2 = 0x24;
  if (((*(ushort *)(param_1 + 0x18) >> 0xc & 1) != 0) &&
     (iVar2 = 0x24, *(int *)((longlong)param_1 + 0xbc) != 100)) {
    iVar2 = 0x6c;
  }
  lVar5 = param_1[0x19];
  iVar3 = (**(code **)(*param_2 + 0x88))(param_2);
  iVar4 = (**(code **)(*param_2 + 0x80))(param_2);
  if ((uint)(iVar3 - iVar4) < (uint)(((int)lVar5 * 2 + 4) - iVar2)) {
    (**(code **)(*param_2 + 0x88))(param_2);
    (**(code **)(*param_2 + 0x80))(param_2);
  }
  param_1 = param_1 + 0x44;
  FUN_1800150c0(param_1);
  uVar1 = *(undefined4 *)(*param_1 + -4);
  FUN_18000d0b0(param_1);
  lVar5 = 0;
  if (*(int *)(*param_1 + -4) != 0) {
    lVar5 = *param_1;
  }
  (**(code **)(*param_2 + 0x90))(param_2,lVar5,uVar1);
  return 0;
}



