/* ==== 1808af400 FUN_1808af400 ==== */

uint FUN_1808af400(__uint64 param_1,uint param_2)

{
  longlong *plVar1;
  uint uVar2;
  undefined4 local_res10 [2];
  longlong *local_res18 [2];
  undefined **local_38;
  undefined4 local_30;
  undefined2 local_2c;
  longlong local_28 [2];
  
  local_38 = OdDgDependencyLinkageData::vftable;
  local_30 = 0;
  local_2c = 0;
  OdDgAttributeLinkageHeader::OdDgAttributeLinkageHeader((OdDgAttributeLinkageHeader *)local_28);
  local_30 = local_30 & 0xffffc9ff | 0x900;
  (**(code **)(local_28[0] + 0x18))(local_28,0x56d0);
  local_38 = `public:_static_enum_OdDgDependencyLinkage::RootDataType___cdecl_OdDgDependencyLinkageData::getRootDataType(unsigned_char_const*___ptr64,unsigned_long)'
             ::__l2::RootTypeReader::vftable;
  OdFlatMemStream::createNew(local_res18,param_1,(ulonglong)param_2);
  plVar1 = local_res18[0];
  if (local_res18[0] != (longlong *)0x0) {
    (**(code **)(*local_res18[0] + 0x98))(local_res18[0],local_res10,4);
    (**(code **)(local_28[0] + 0x68))(local_28,local_res10[0]);
    (**(code **)(*plVar1 + 0x98))(plVar1,local_res10,2);
    local_30._2_2_ = (undefined2)local_res10[0];
    (**(code **)(*plVar1 + 0x98))(plVar1,local_res10,2);
    local_2c = (undefined2)local_res10[0];
    (**(code **)(*plVar1 + 0x98))(plVar1,local_res10,2);
    local_30 = CONCAT22(local_30._2_2_,(undefined2)local_res10[0]);
    (*(code *)*local_38)(&local_38,plVar1);
  }
  uVar2 = local_30 >> 10;
  if (local_res18[0] != (longlong *)0x0) {
    (**(code **)(*local_res18[0] + 0x28))(local_res18[0]);
    local_res18[0] = (longlong *)0x0;
  }
  OdDgAttributeLinkageHeader::~OdDgAttributeLinkageHeader((OdDgAttributeLinkageHeader *)local_28);
  return uVar2 & 0xf;
}



