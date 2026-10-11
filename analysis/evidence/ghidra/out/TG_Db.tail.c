/* ==== 1808bd8b0 FUN_1808bd8b0 ==== */

void FUN_1808bd8b0(longlong *param_1,double *param_2)

{
  *param_2 = (double)*param_1;
  param_2[1] = (double)param_1[1];
  param_2[2] = (double)param_1[2];
  param_2[3] = (double)(param_1[3] + *param_1);
  param_2[4] = (double)(param_1[4] + param_1[1]);
  param_2[5] = (double)(param_1[5] + param_1[2]);
  return;
}



/* ==== 1808c4f00 FUN_1808c4f00 ==== */

double FUN_1808c4f00(void)

{
  __int64 _Var1;
  OdTimeStamp local_res8 [32];
  
  OdTimeStamp::OdTimeStamp(local_res8,3);
  OdTimeStamp::getUniversalTime(local_res8);
  _Var1 = OdTimeStamp::packedValue(local_res8);
  return (double)_Var1 * 1000.0;
}



