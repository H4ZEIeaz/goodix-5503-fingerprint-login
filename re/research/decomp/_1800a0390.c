
undefined8 FUN_1800a0390(int *param_1,longlong param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar1 = param_1[1];
  iVar2 = param_1[2];
  uVar3 = FUN_18009ed40(*param_1,param_3,param_2,param_2 + 4,param_2 + 8);
  if ((int)uVar3 != 0) {
    return uVar3;
  }
  *(undefined4 *)(param_2 + 0xc) = 0xda;
  FUN_1800a26a0(param_4,param_2 + 0x10,param_2 + 0x14);
  *(undefined4 *)(param_2 + 0x18) = 0x17;
  *(undefined4 *)(param_2 + 0x1c) = 0x2f;
  *(undefined4 *)(param_2 + 0x20) = 0x28;
  *(undefined4 *)(param_2 + 0x24) = 0x26;
  *(undefined4 *)(param_2 + 0x28) = 0xffffffff;
  *(undefined4 *)(param_2 + 0x2c) = 0x10;
  if (*param_1 == 9) {
    *(undefined4 *)(param_2 + 0x28) = 0x78;
  }
  else {
    if (*param_1 != 10) goto code_r0x0001800a0449;
    *(undefined4 *)(param_2 + 0x28) = 100;
  }
  *(undefined4 *)(param_2 + 0x1c) = 0x2d;
  *(undefined4 *)(param_2 + 0x18) = 0x16;
code_r0x0001800a0449:
  *(undefined4 *)(param_2 + 0x34) = 1;
  *(int *)(param_2 + 0x48) = param_1[3];
  *(int *)(param_2 + 0x30) = (iVar2 * iVar1 * 0x100) / 0x2520;
  *(int *)(param_2 + 0x3c) = *param_1;
  switch(*param_1) {
  default:
    *(undefined4 *)(param_2 + 0x40) = 0;
    break;
  case 6:
  case 7:
  case 0x3f:
    *(undefined4 *)(param_2 + 0x40) = 1;
  }
  return 0;
}

