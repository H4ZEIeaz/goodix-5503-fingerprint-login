// 18008f640 preprocess_save_calidata

undefined8 preprocess_save_calidata(undefined4 *param_1,uint *param_2)

{
  undefined8 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  longlong lVar6;
  undefined8 *puVar7;
  undefined8 *puVar8;
  undefined8 *puVar9;
  undefined8 *puVar10;
  longlong lVar11;
  ulonglong uVar12;
  
                    /* 0x8f640  19  preprocess_save_calidata */
  lVar6 = FUN_1800b18d0();
  lVar11 = -1;
  uVar12 = 0xffffffffffffffff;
  do {
    uVar12 = uVar12 + 1;
  } while (*(char *)(lVar6 + uVar12) != '\0');
  if (uVar12 < 0x21) {
    do {
      lVar11 = lVar11 + 1;
    } while (*(char *)(lVar6 + lVar11) != '\0');
  }
  else {
    lVar11 = 0x20;
  }
  if ((param_1 != (undefined4 *)0x0) && (0x224af < *param_2)) {
    FUN_1800abe20(param_1 + 2,0x180159784,
                  (ulonglong)(uint)(iRam0000000180159770 * iRam0000000180159774) * 2);
    FUN_1800abe20(param_1 + 0x264a,0x1801630a4,
                  (ulonglong)(uint)(iRam0000000180159770 * iRam0000000180159774) * 2);
    puVar1 = (undefined8 *)(param_1 + 0x8924);
    param_1[0x6122] = uRam0000000180159780;
    *puVar1 = 0;
    *(undefined8 *)(param_1 + 0x8926) = 0;
    *(undefined8 *)(param_1 + 0x8928) = 0;
    *(undefined8 *)(param_1 + 0x892a) = 0;
    FUN_1800c72a0(puVar1,lVar6,(longlong)(int)lVar11);
    lVar11 = 0x10;
    puVar8 = (undefined8 *)(param_1 + 0x4c92);
    puVar10 = (undefined8 *)0x180154520;
    do {
      uVar4 = puVar10[1];
      *puVar8 = *puVar10;
      puVar8[1] = uVar4;
      uVar4 = puVar10[3];
      puVar8[2] = puVar10[2];
      puVar8[3] = uVar4;
      uVar4 = puVar10[5];
      puVar8[4] = puVar10[4];
      puVar8[5] = uVar4;
      uVar4 = puVar10[7];
      puVar8[6] = puVar10[6];
      puVar8[7] = uVar4;
      uVar4 = puVar10[9];
      puVar8[8] = puVar10[8];
      puVar8[9] = uVar4;
      uVar4 = puVar10[0xb];
      puVar8[10] = puVar10[10];
      puVar8[0xb] = uVar4;
      uVar4 = puVar10[0xd];
      puVar8[0xc] = puVar10[0xc];
      puVar8[0xd] = uVar4;
      uVar4 = puVar10[0xf];
      puVar8[0xe] = puVar10[0xe];
      puVar8[0xf] = uVar4;
      lVar11 = lVar11 + -1;
      puVar8 = puVar8 + 0x10;
      puVar10 = puVar10 + 0x10;
    } while (lVar11 != 0);
    lVar11 = 0x94;
    puVar8 = (undefined8 *)0x180154d20;
    puVar10 = (undefined8 *)(param_1 + 0x4e92);
    do {
      puVar9 = puVar10;
      puVar7 = puVar8;
      uVar4 = puVar7[1];
      *puVar9 = *puVar7;
      puVar9[1] = uVar4;
      uVar4 = puVar7[3];
      puVar9[2] = puVar7[2];
      puVar9[3] = uVar4;
      uVar4 = puVar7[5];
      puVar9[4] = puVar7[4];
      puVar9[5] = uVar4;
      uVar4 = puVar7[7];
      puVar9[6] = puVar7[6];
      puVar9[7] = uVar4;
      uVar4 = puVar7[9];
      puVar9[8] = puVar7[8];
      puVar9[9] = uVar4;
      uVar4 = puVar7[0xb];
      puVar9[10] = puVar7[10];
      puVar9[0xb] = uVar4;
      uVar4 = puVar7[0xd];
      puVar9[0xc] = puVar7[0xc];
      puVar9[0xd] = uVar4;
      uVar4 = puVar7[0xf];
      puVar9[0xe] = puVar7[0xe];
      puVar9[0xf] = uVar4;
      lVar11 = lVar11 + -1;
      puVar8 = puVar7 + 0x10;
      puVar10 = puVar9 + 0x10;
    } while (lVar11 != 0);
    uVar4 = puVar7[0x11];
    lVar11 = 0x140;
    puVar9[0x10] = puVar7[0x10];
    puVar9[0x11] = uVar4;
    uVar4 = puVar7[0x13];
    puVar9[0x12] = puVar7[0x12];
    puVar9[0x13] = uVar4;
    uVar4 = puVar7[0x15];
    puVar9[0x14] = puVar7[0x14];
    puVar9[0x15] = uVar4;
    uVar4 = puVar7[0x17];
    puVar9[0x16] = puVar7[0x16];
    puVar9[0x17] = uVar4;
    puVar8 = (undefined8 *)(param_1 + 0x6123);
    puVar10 = (undefined8 *)0x18017fc08;
    do {
      uVar4 = puVar10[1];
      *puVar8 = *puVar10;
      puVar8[1] = uVar4;
      uVar4 = puVar10[3];
      puVar8[2] = puVar10[2];
      puVar8[3] = uVar4;
      uVar4 = puVar10[5];
      puVar8[4] = puVar10[4];
      puVar8[5] = uVar4;
      uVar4 = puVar10[7];
      puVar8[6] = puVar10[6];
      puVar8[7] = uVar4;
      uVar4 = puVar10[9];
      puVar8[8] = puVar10[8];
      puVar8[9] = uVar4;
      uVar4 = puVar10[0xb];
      puVar8[10] = puVar10[10];
      puVar8[0xb] = uVar4;
      uVar5 = *(undefined4 *)((longlong)puVar10 + 100);
      uVar2 = *(undefined4 *)(puVar10 + 0xd);
      uVar3 = *(undefined4 *)((longlong)puVar10 + 0x6c);
      *(undefined4 *)(puVar8 + 0xc) = *(undefined4 *)(puVar10 + 0xc);
      *(undefined4 *)((longlong)puVar8 + 100) = uVar5;
      *(undefined4 *)(puVar8 + 0xd) = uVar2;
      *(undefined4 *)((longlong)puVar8 + 0x6c) = uVar3;
      uVar5 = *(undefined4 *)((longlong)puVar10 + 0x74);
      uVar2 = *(undefined4 *)(puVar10 + 0xf);
      uVar3 = *(undefined4 *)((longlong)puVar10 + 0x7c);
      *(undefined4 *)(puVar8 + 0xe) = *(undefined4 *)(puVar10 + 0xe);
      *(undefined4 *)((longlong)puVar8 + 0x74) = uVar5;
      *(undefined4 *)(puVar8 + 0xf) = uVar2;
      *(undefined4 *)((longlong)puVar8 + 0x7c) = uVar3;
      lVar11 = lVar11 + -1;
      puVar8 = puVar8 + 0x10;
      puVar10 = puVar10 + 0x10;
    } while (lVar11 != 0);
    param_1[0x8923] = uRam0000000180189c08;
    FUN_180057ac0(&UNK_1800f0a58,lVar6);
    FUN_180057ac0(&UNK_1800f0a78,puVar1);
    uVar5 = FUN_1800b1ce0(0xffffffff,param_1 + 2,iRam0000000180159770 * iRam0000000180159774 * 2);
    *param_1 = uVar5;
    uVar5 = FUN_1800b1ce0(0xffffffff,param_1 + 0x264a,
                          iRam0000000180159770 * iRam0000000180159774 * 2);
    param_1[1] = uVar5;
    *param_2 = 0x224b0;
    return 0;
  }
  return 0x81;
}

