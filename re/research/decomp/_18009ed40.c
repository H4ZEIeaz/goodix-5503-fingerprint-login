
undefined8
FUN_18009ed40(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,undefined4 *param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar3 = 0;
  uVar2 = param_2 & 0xf;
  uVar4 = 0;
  uVar1 = (int)param_2 >> 8 & 0xf;
  if (((2 < uVar2) || (2 < uVar1)) || (uVar1 * uVar2 != 0)) {
    *param_3 = 0;
    *param_4 = 0;
    return 0x80000003;
  }
  if (uVar2 == 1) {
    if (param_1 == 10) {
      uVar3 = 2;
      uVar4 = 2;
    }
    else {
code_r0x00018009ed97:
      uVar4 = 3;
    }
  }
  else if (uVar2 == 2) {
    if (param_1 == 10) {
      uVar3 = 4;
      goto code_r0x00018009ed97;
    }
    uVar4 = 4;
    uVar3 = 2;
  }
  if (uVar1 == 1) {
    uVar3 = 0xffffffff;
  }
  else {
    if (uVar1 != 2) goto code_r0x00018009edb6;
    uVar3 = 0xfffffffe;
  }
  uVar4 = 0;
code_r0x00018009edb6:
  *param_5 = 5;
  *param_3 = uVar3;
  *param_4 = uVar4;
  return 0;
}

