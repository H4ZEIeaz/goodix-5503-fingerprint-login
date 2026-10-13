
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800a0520(int *param_1,longlong param_2,longlong param_3,int *param_4,int param_5)

{
  bool bVar1;
  int iVar2;
  longlong lVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined1 auStack_98 [32];
  int *piStack_78;
  longlong lStack_68;
  int iStack_60;
  int iStack_5c;
  ulonglong uStack_58;
  
  uStack_58 = _DAT_18012a308 ^ (ulonglong)auStack_98;
  iVar7 = -1;
  iStack_60 = 0;
  if (param_5 == 0) {
    bVar1 = false;
  }
  else {
    if ((param_5 == 1) || (param_5 != 2)) {
      iVar5 = 1;
      bVar1 = true;
      goto code_r0x0001800a0585;
    }
    bVar1 = true;
  }
  iVar5 = 0;
code_r0x0001800a0585:
  lStack_68 = param_2;
  if (*param_1 - 9U < 2) {
    iVar2 = -1;
    if ((*(int *)(param_3 + 0x688) != 0) && (iVar2 = -1, bVar1)) {
      piStack_78 = (int *)CONCAT44(piStack_78._4_4_,iVar5);
      iVar2 = FUN_1800c2640(param_1,param_2,param_3,&iStack_60);
    }
    if (param_1[0x2380] == 0) {
      if ((-1 < iVar2) && (iVar5 != 0)) {
        piStack_78 = &iStack_5c;
        iStack_5c = 0;
        FUN_18009af80(param_1,iVar2,*(undefined4 *)(param_3 + 0x68c),param_4);
        if (iStack_5c == 5) {
          iStack_60 = 5;
        }
      }
      if ((param_1[0x2380] == 0) && (3 < iStack_60)) {
        if (iStack_60 == 5) {
          param_1[0x2381] = param_1[0x2381] + 2;
        }
        else {
          param_1[0x2381] = param_1[0x2381] + 1;
        }
        if (0x32 < param_1[0x2381]) {
          param_1[0x2380] = 1;
          FUN_1800abeb0(param_1 + 0x236c,0xffffffff,0x50);
        }
      }
    }
  }
  else {
    if (((0 < *(int *)(param_3 + 0x640)) && (*(int *)(param_3 + 0x644) == 1)) &&
       (FUN_1800a1b40(param_1,param_3), param_1[7] == param_1[8])) {
      FUN_1800a26d0(param_1);
    }
    iVar2 = -1;
    if (((*(int *)(param_3 + 0x688) != 0) && (iVar2 = iVar7, bVar1)) &&
       ((0xf < *(int *)(param_2 + 0x10c) && (0x41 < *(int *)(param_2 + 0x110))))) {
      piStack_78 = (int *)CONCAT44(piStack_78._4_4_,iVar5);
      iVar2 = FUN_1800a2110(param_1,param_2,param_3,&iStack_60);
      if ((param_1[0x2380] == 0) && (-1 < iVar2)) {
        piStack_78 = &iStack_5c;
        iStack_5c = 0;
        FUN_18009af80(param_1,iVar2,*(undefined4 *)(param_3 + 0x68c),param_4);
        if (iStack_5c == 5) {
          iStack_60 = 5;
        }
      }
    }
    if ((param_1[8] == param_1[7]) && (param_1[0x2380] == 0)) {
      param_1[0x2380] = 1;
      piVar6 = param_1 + 0x236c;
      piVar4 = param_1 + 0x2344;
      lVar3 = 0x14;
      do {
        FUN_180090550(piVar4);
        piVar4 = piVar4 + 2;
        *piVar6 = -1;
        piVar6 = piVar6 + 1;
        lVar3 = lVar3 + -1;
        param_2 = lStack_68;
      } while (lVar3 != 0);
    }
    if (((((bVar1) && (iVar2 == -1)) && (*(int *)(param_3 + 0x688) == 1)) &&
        ((param_1[0x2380] == 0 && (0x41 < *(int *)(param_2 + 0x110))))) &&
       (0xf < *(int *)(param_2 + 0x10c))) {
      piStack_78 = (int *)CONCAT44(piStack_78._4_4_,0x14);
      FUN_1800a11e0(param_2,param_1,param_1 + 0x2344,param_1 + 0x236c);
    }
    if ((*(int *)(param_3 + 0x684) != 0) && (1 < *param_1 - 9U)) {
      FUN_18009a130(param_1);
      param_1[0x233d] = param_1[0x233d] + 1;
    }
  }
  if (param_4 != (int *)0x0) {
    param_4[1] = iVar2;
    *param_4 = iStack_60;
  }
  FUN_180086a70(uStack_58 ^ (ulonglong)auStack_98);
  return;
}

