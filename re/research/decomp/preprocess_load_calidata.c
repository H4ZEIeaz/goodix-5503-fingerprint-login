// 18008f320 preprocess_load_calidata

undefined8 preprocess_load_calidata(int *param_1,uint param_2)

{
  undefined8 uVar1;
  uint uVar2;
  int iVar3;
  longlong lVar4;
  int *piVar5;
  int *piVar6;
  longlong lVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  ulonglong uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  
                    /* 0x8f320  18  preprocess_load_calidata */
  lVar4 = FUN_1800b18d0();
  lVar7 = -1;
  uVar10 = 0xffffffffffffffff;
  do {
    uVar10 = uVar10 + 1;
  } while (*(char *)(lVar4 + uVar10) != '\0');
  if (uVar10 < 0x21) {
    do {
      lVar7 = lVar7 + 1;
    } while (*(char *)(lVar4 + lVar7) != '\0');
  }
  else {
    lVar7 = 0x20;
  }
  if ((param_1 == (int *)0x0) || (param_2 < 0x224b0)) {
    FUN_180057ac0(&UNK_1800f0a90);
    return 0x81;
  }
  iVar3 = FUN_1800c8750(lVar4,param_1 + 0x8924,(longlong)(int)lVar7);
  if (iVar3 != 0) {
    FUN_180057ac0(&UNK_1800f0ab0,lVar4,param_1 + 0x8924);
    return 0x80;
  }
  iVar3 = FUN_1800b1ce0(0xffffffff,param_1 + 2,uRam0000000180159770 * uRam0000000180159774 * 2);
  if ((*param_1 == iVar3) &&
     (iVar3 = FUN_1800b1ce0(0xffffffff,param_1 + 0x264a,
                            uRam0000000180159770 * uRam0000000180159774 * 2), param_1[1] == iVar3))
  {
    FUN_180057ac0(&UNK_1800f0b08);
    uVar2 = uRam0000000180159774;
    if (uRam0000000180159770 != 0) {
      uVar12 = (ulonglong)uRam0000000180159774;
      uVar10 = 0;
      uVar13 = (ulonglong)uRam0000000180159770;
      do {
        iVar3 = (int)uVar10;
        uVar11 = uVar12;
        if (uVar2 != 0) {
          do {
            *(undefined2 *)(uVar10 * 2 + 0x180159784) =
                 *(undefined2 *)((longlong)param_1 + uVar10 * 2 + 8);
            *(undefined2 *)(uVar10 * 2 + 0x1801630a4) =
                 *(undefined2 *)((longlong)param_1 + uVar10 * 2 + 0x9928);
            uVar11 = uVar11 - 1;
            uVar10 = (ulonglong)((int)uVar10 + 1);
          } while (uVar11 != 0);
        }
        uVar10 = (ulonglong)(iVar3 + uVar2);
        uVar13 = uVar13 - 1;
      } while (uVar13 != 0);
    }
    lVar4 = 0x10;
    piVar6 = param_1 + 0x4c92;
    puVar9 = (undefined8 *)0x180154520;
    do {
      uVar1 = *(undefined8 *)(piVar6 + 2);
      *puVar9 = *(undefined8 *)piVar6;
      puVar9[1] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 6);
      puVar9[2] = *(undefined8 *)(piVar6 + 4);
      puVar9[3] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 10);
      puVar9[4] = *(undefined8 *)(piVar6 + 8);
      puVar9[5] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 0xe);
      puVar9[6] = *(undefined8 *)(piVar6 + 0xc);
      puVar9[7] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 0x12);
      puVar9[8] = *(undefined8 *)(piVar6 + 0x10);
      puVar9[9] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 0x16);
      puVar9[10] = *(undefined8 *)(piVar6 + 0x14);
      puVar9[0xb] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 0x1a);
      puVar9[0xc] = *(undefined8 *)(piVar6 + 0x18);
      puVar9[0xd] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 0x1e);
      puVar9[0xe] = *(undefined8 *)(piVar6 + 0x1c);
      puVar9[0xf] = uVar1;
      lVar4 = lVar4 + -1;
      piVar6 = piVar6 + 0x20;
      puVar9 = puVar9 + 0x10;
    } while (lVar4 != 0);
    lVar4 = 0x94;
    piVar6 = param_1 + 0x4e92;
    puVar9 = (undefined8 *)0x180154d20;
    do {
      puVar8 = puVar9;
      piVar5 = piVar6;
      uVar1 = *(undefined8 *)(piVar5 + 2);
      *puVar8 = *(undefined8 *)piVar5;
      puVar8[1] = uVar1;
      uVar1 = *(undefined8 *)(piVar5 + 6);
      puVar8[2] = *(undefined8 *)(piVar5 + 4);
      puVar8[3] = uVar1;
      uVar1 = *(undefined8 *)(piVar5 + 10);
      puVar8[4] = *(undefined8 *)(piVar5 + 8);
      puVar8[5] = uVar1;
      uVar1 = *(undefined8 *)(piVar5 + 0xe);
      puVar8[6] = *(undefined8 *)(piVar5 + 0xc);
      puVar8[7] = uVar1;
      uVar1 = *(undefined8 *)(piVar5 + 0x12);
      puVar8[8] = *(undefined8 *)(piVar5 + 0x10);
      puVar8[9] = uVar1;
      uVar1 = *(undefined8 *)(piVar5 + 0x16);
      puVar8[10] = *(undefined8 *)(piVar5 + 0x14);
      puVar8[0xb] = uVar1;
      uVar1 = *(undefined8 *)(piVar5 + 0x1a);
      puVar8[0xc] = *(undefined8 *)(piVar5 + 0x18);
      puVar8[0xd] = uVar1;
      uVar1 = *(undefined8 *)(piVar5 + 0x1e);
      puVar8[0xe] = *(undefined8 *)(piVar5 + 0x1c);
      puVar8[0xf] = uVar1;
      lVar4 = lVar4 + -1;
      piVar6 = piVar5 + 0x20;
      puVar9 = puVar8 + 0x10;
    } while (lVar4 != 0);
    uVar1 = *(undefined8 *)(piVar5 + 0x22);
    lVar4 = 0x140;
    puVar8[0x10] = *(undefined8 *)(piVar5 + 0x20);
    puVar8[0x11] = uVar1;
    uVar1 = *(undefined8 *)(piVar5 + 0x26);
    puVar8[0x12] = *(undefined8 *)(piVar5 + 0x24);
    puVar8[0x13] = uVar1;
    uVar1 = *(undefined8 *)(piVar5 + 0x2a);
    puVar8[0x14] = *(undefined8 *)(piVar5 + 0x28);
    puVar8[0x15] = uVar1;
    uVar1 = *(undefined8 *)(piVar5 + 0x2e);
    puVar8[0x16] = *(undefined8 *)(piVar5 + 0x2c);
    puVar8[0x17] = uVar1;
    iRam0000000180159780 = param_1[0x6122];
    piVar6 = param_1 + 0x6123;
    puVar9 = (undefined8 *)0x18017fc08;
    do {
      uVar1 = *(undefined8 *)(piVar6 + 2);
      *puVar9 = *(undefined8 *)piVar6;
      puVar9[1] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 6);
      puVar9[2] = *(undefined8 *)(piVar6 + 4);
      puVar9[3] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 10);
      puVar9[4] = *(undefined8 *)(piVar6 + 8);
      puVar9[5] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 0xe);
      puVar9[6] = *(undefined8 *)(piVar6 + 0xc);
      puVar9[7] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 0x12);
      puVar9[8] = *(undefined8 *)(piVar6 + 0x10);
      puVar9[9] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 0x16);
      puVar9[10] = *(undefined8 *)(piVar6 + 0x14);
      puVar9[0xb] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 0x1a);
      puVar9[0xc] = *(undefined8 *)(piVar6 + 0x18);
      puVar9[0xd] = uVar1;
      uVar1 = *(undefined8 *)(piVar6 + 0x1e);
      puVar9[0xe] = *(undefined8 *)(piVar6 + 0x1c);
      puVar9[0xf] = uVar1;
      lVar4 = lVar4 + -1;
      piVar6 = piVar6 + 0x20;
      puVar9 = puVar9 + 0x10;
    } while (lVar4 != 0);
    iRam0000000180189c08 = param_1[0x8923];
    return 0;
  }
  FUN_180057ac0(&UNK_1800f0ae0);
  return 0x80;
}

