/* ==== 1801d8f00 FUN_1801d8f00 ==== */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1801d8f00(longlong param_1,longlong *param_2)

{
  int iVar1;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  OdGeMatrix3d local_98 [128];
  ulonglong local_18;
  
  local_18 = DAT_180fcd438 ^ (ulonglong)auStack_f8;
  (**(code **)(*param_2 + 0x170))(param_2,(int)*(undefined8 *)(param_1 + 0x220));
  (**(code **)(*param_2 + 0x170))(param_2,(int)*(undefined8 *)(param_1 + 0x228));
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar1 == 10) {
    OdGeMatrix3d::OdGeMatrix3d(local_98);
    local_c8 = 0;
    local_d8 = 0;
    uStack_d0 = 0;
    OdGeMatrix3d::setToRotation
              (local_98,-*(double *)(param_1 + 0x240),(OdGeVector3d *)kZAxis_exref,
               (OdGePoint3d *)&local_d8);
    local_c0 = 0x3ff0000000000000;
    uStack_b8 = 0;
    local_b0 = 0;
    uStack_a8 = 0;
    OdGeQuaternion::set((OdGeQuaternion *)&local_c0,local_98);
    (**(code **)(*param_2 + 0x1c0))(param_2,&local_c0);
  }
  else {
    (**(code **)(*param_2 + 0x170))(param_2,(int)*(undefined8 *)(param_1 + 0x240));
  }
  (**(code **)(*param_2 + 0x1a0))(param_2,param_1 + 0x248);
  return;
}



/* ==== 1801d9020 FUN_1801d9020 ==== */

void FUN_1801d9020(longlong param_1,longlong *param_2)

{
  int iVar1;
  
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x220));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x228));
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar1 == 0xb) {
    (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x248));
  }
  else {
    (**(code **)(*param_2 + 0x1c0))(param_2,param_1 + 0x240);
  }
                    /* WARNING: Could not recover jumptable at 0x0001801d90a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x1a8))(param_2,param_1 + 0x260);
  return;
}



/* ==== 1802867f0 FUN_1802867f0 ==== */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_1802867f0(longlong param_1,longlong *param_2)

{
  int iVar1;
  undefined1 auStack_f8 [32];
  undefined8 local_d8;
  undefined8 uStack_d0;
  undefined8 local_c8;
  undefined8 local_c0;
  undefined8 uStack_b8;
  undefined8 local_b0;
  undefined8 uStack_a8;
  OdGeMatrix3d local_98 [128];
  ulonglong local_18;
  
  local_18 = DAT_180fcd438 ^ (ulonglong)auStack_f8;
  (**(code **)(*param_2 + 0x170))(param_2,(int)*(undefined8 *)(param_1 + 0x220));
  (**(code **)(*param_2 + 0x170))(param_2,(int)*(undefined8 *)(param_1 + 0x228));
  (**(code **)(*param_2 + 0x170))(param_2,(int)*(undefined8 *)(param_1 + 0x230));
  (**(code **)(*param_2 + 0x170))(param_2,(int)*(undefined8 *)(param_1 + 0x238));
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar1 == 10) {
    OdGeMatrix3d::OdGeMatrix3d(local_98);
    local_c8 = 0;
    local_d8 = 0;
    uStack_d0 = 0;
    OdGeMatrix3d::setToRotation
              (local_98,-*(double *)(param_1 + 0x250),(OdGeVector3d *)kZAxis_exref,
               (OdGePoint3d *)&local_d8);
    local_c0 = 0x3ff0000000000000;
    uStack_b8 = 0;
    local_b0 = 0;
    uStack_a8 = 0;
    OdGeQuaternion::set((OdGeQuaternion *)&local_c0,local_98);
    (**(code **)(*param_2 + 0x1c0))(param_2,&local_c0);
  }
  else {
    (**(code **)(*param_2 + 0x170))(param_2,(int)*(undefined8 *)(param_1 + 0x250));
  }
  (**(code **)(*param_2 + 0x1a0))(param_2,param_1 + 600);
  return;
}



/* ==== 180286930 FUN_180286930 ==== */

void FUN_180286930(longlong param_1,longlong *param_2)

{
  int iVar1;
  
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x220));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x228));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x230));
  (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 0x238));
  iVar1 = (**(code **)(*param_2 + 0x58))(param_2);
  if (iVar1 == 0xb) {
    (**(code **)(*param_2 + 0x170))(param_2,*(undefined8 *)(param_1 + 600));
  }
  else {
    (**(code **)(*param_2 + 0x1c0))(param_2,param_1 + 0x250);
  }
                    /* WARNING: Could not recover jumptable at 0x0001802869d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x1a8))(param_2,param_1 + 0x270);
  return;
}



/* ==== 18081e480 dgnOutFields ==== */

/* public: virtual void __cdecl CDGDispHeader::dgnOutFields(class OdDgFiler * __ptr64)const __ptr64
    */

void __thiscall CDGDispHeader::dgnOutFields(CDGDispHeader *this,OdDgFiler *param_1)

{
                    /* 0x81e480  7827  ?dgnOutFields@CDGDispHeader@@UEBAXPEAVOdDgFiler@@@Z */
  CDGElmHeader::dgnOutFields((CDGElmHeader *)this,param_1);
  if (*(longlong *)(this + 0x30) != 0) {
    FUN_1808c5330(*(longlong *)(this + 0x30),param_1);
  }
  return;
}



/* ==== 1808b3a70 dgnOutFields ==== */

/* public: virtual void __cdecl CDGElmHeader::dgnOutFields(class OdDgFiler * __ptr64)const __ptr64
    */

void __thiscall CDGElmHeader::dgnOutFields(CDGElmHeader *this,OdDgFiler *param_1)

{
                    /* 0x8b3a70  7828  ?dgnOutFields@CDGElmHeader@@UEBAXPEAVOdDgFiler@@@Z */
  FUN_1808c5460(this + 8);
  return;
}



