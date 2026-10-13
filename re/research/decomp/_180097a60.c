
void FUN_180097a60(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  longlong lVar1;
  undefined8 uVar2;
  int iVar3;
  
  FUN_1800abe60(*(undefined8 *)(*(longlong *)(param_2 + 2) + 0x18),
                *(undefined8 *)(*(longlong *)(param_1 + 2) + 0x18),
                *(undefined4 *)(*(longlong *)(param_1 + 2) + 0xc));
  lVar1 = *(longlong *)(param_1 + 4);
  if (lVar1 == 0) {
    *(undefined8 *)(param_2 + 4) = 0;
  }
  else {
    FUN_1800abe60(*(undefined8 *)(*(longlong *)(param_2 + 4) + 0x18),*(undefined8 *)(lVar1 + 0x18),
                  *(undefined4 *)(lVar1 + 0xc));
  }
  lVar1 = *(longlong *)(param_1 + 6);
  if (lVar1 == 0) {
    *(undefined8 *)(param_2 + 6) = 0;
  }
  else {
    FUN_1800abe60(*(undefined8 *)(*(longlong *)(param_2 + 6) + 0x18),*(undefined8 *)(lVar1 + 0x18),
                  *(undefined4 *)(lVar1 + 0xc));
  }
  FUN_1800abe60(param_2 + 10,param_1 + 10,200);
  FUN_1800ac880(*(undefined8 *)(param_1 + 0x4c),param_2 + 0x4c);
  *(undefined8 *)(param_2 + 8) = 0;
  iVar3 = param_1[0x3c];
  if (param_3 < (int)param_1[0x3c]) {
    iVar3 = param_3;
  }
  param_2[0x3c] = iVar3;
  FUN_1800abe60(*(undefined8 *)(param_2 + 0x3e),*(undefined8 *)(param_1 + 0x3e),iVar3 * 0x38);
  param_2[0x42] = param_1[0x42];
  uVar2 = *(undefined8 *)(param_1 + 0x5a);
  *(undefined8 *)(param_2 + 0x58) = *(undefined8 *)(param_1 + 0x58);
  *(undefined8 *)(param_2 + 0x5a) = uVar2;
  *(undefined8 *)(param_2 + 0x5c) = *(undefined8 *)(param_1 + 0x5c);
  param_2[0x5e] = param_1[0x5e];
  param_2[0x53] = param_1[0x53];
  param_2[0x41] = param_1[0x41];
  param_2[0x43] = param_1[0x43];
  param_2[0x44] = param_1[0x44];
  param_2[0x40] = param_1[0x40];
  param_2[0x49] = param_1[0x49];
  param_2[0x47] = param_1[0x47];
  param_2[0x48] = param_1[0x48];
  param_2[0x45] = param_1[0x45];
  param_2[0x43] = param_1[0x43];
  param_2[0x44] = param_1[0x44];
  param_2[0x4a] = param_1[0x4a];
  param_2[1] = param_1[1];
  *param_2 = *param_1;
  return;
}

