
undefined8 FUN_1800a27d0(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  longlong lVar4;
  
  if (param_1 == (int *)0x0) {
    return 0x80000002;
  }
  iVar3 = 0;
  iVar1 = 0;
  if (*param_1 - 9U < 2) {
    piVar2 = param_1 + 0x236d;
    lVar4 = 4;
    if (param_1[0x2380] == 0) {
      do {
        if (-1 < piVar2[-1]) {
          iVar1 = iVar1 + 1;
        }
        if (-1 < *piVar2) {
          iVar1 = iVar1 + 1;
        }
        if (-1 < piVar2[1]) {
          iVar1 = iVar1 + 1;
        }
        if (-1 < piVar2[2]) {
          iVar1 = iVar1 + 1;
        }
        if (-1 < piVar2[3]) {
          iVar1 = iVar1 + 1;
        }
        piVar2 = piVar2 + 5;
        lVar4 = lVar4 + -1;
      } while (lVar4 != 0);
      *param_2 = iVar1;
      *param_3 = 0;
      return 0;
    }
    do {
      if (-1 < piVar2[-1]) {
        iVar3 = iVar3 + 1;
      }
      if (-1 < *piVar2) {
        iVar3 = iVar3 + 1;
      }
      if (-1 < piVar2[1]) {
        iVar3 = iVar3 + 1;
      }
      if (-1 < piVar2[2]) {
        iVar3 = iVar3 + 1;
      }
      if (-1 < piVar2[3]) {
        iVar3 = iVar3 + 1;
      }
      piVar2 = piVar2 + 5;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
  }
  else if (param_1[0x2380] == 0) {
    param_1 = param_1 + 0x236d;
    lVar4 = 4;
    do {
      if (-1 < param_1[-1]) {
        iVar1 = iVar1 + 1;
      }
      if (-1 < *param_1) {
        iVar1 = iVar1 + 1;
      }
      if (-1 < param_1[1]) {
        iVar1 = iVar1 + 1;
      }
      if (-1 < param_1[2]) {
        iVar1 = iVar1 + 1;
      }
      if (-1 < param_1[3]) {
        iVar1 = iVar1 + 1;
      }
      param_1 = param_1 + 5;
      lVar4 = lVar4 + -1;
    } while (lVar4 != 0);
    *param_2 = iVar1;
    *param_3 = 0;
    return 0;
  }
  *param_2 = 0;
  *param_3 = iVar3;
  return 0;
}

