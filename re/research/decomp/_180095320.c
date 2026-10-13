
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180095320(longlong *param_1,int *param_2,undefined4 param_3,int param_4,int param_5,
                  uint *param_6,byte *param_7,longlong param_8)

{
  byte bVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  uint uVar5;
  byte *pbVar6;
  short *psVar7;
  undefined1 *puVar8;
  uint uVar9;
  int iVar10;
  char *pcVar11;
  int iVar12;
  undefined1 auStack_128 [32];
  uint *puStack_108;
  undefined4 uStack_100;
  int iStack_f8;
  uint uStack_f4;
  undefined4 uStack_f0;
  longlong lStack_e8;
  undefined4 *puStack_e0;
  undefined4 *puStack_d8;
  longlong lStack_d0;
  int *piStack_c8;
  longlong lStack_c0;
  undefined4 *puStack_b8;
  longlong lStack_b0;
  longlong lStack_a8;
  undefined8 uStack_a0;
  int iStack_98;
  int iStack_94;
  int iStack_90;
  int iStack_8c;
  int iStack_88;
  byte *pbStack_80;
  uint auStack_78 [2];
  uint uStack_70;
  uint uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  undefined8 uStack_5c;
  undefined8 uStack_54;
  undefined4 uStack_4c;
  ulonglong uStack_48;
  
  uStack_48 = _DAT_18012a308 ^ (ulonglong)auStack_128;
  lStack_e8 = param_8;
  lStack_a8 = 0;
  auStack_78[0] = 0;
  puStack_108 = auStack_78;
  iStack_f8 = param_4;
  uStack_f0 = param_3;
  uVar2 = FUN_1800b9480(*(undefined8 *)(param_2 + 6),&lStack_a8,param_2[1],*param_2);
  lStack_c0 = CONCAT44(lStack_c0._4_4_,uVar2);
  if (param_5 == 0) {
    uVar9 = param_6[5];
  }
  else {
    uVar9 = param_6[6];
  }
  FUN_1800abeb0(&uStack_70,0,0x28);
  uStack_70 = *param_6;
  uStack_5c = _UNK_1800f0fb0;
  uStack_54 = _UNK_1800f0fb8;
  uStack_64 = 0x28;
  uStack_4c = 1;
  uStack_6c = uVar9;
  if (uStack_70 == 9 || uStack_70 == 10) {
    uStack_5c._0_4_ = (undefined4)_UNK_1800f0fb0;
    uStack_5c = CONCAT44(0x40,(undefined4)uStack_5c);
    uStack_54 = CONCAT44((int)((ulonglong)_UNK_1800f0fb8 >> 0x20),2);
    uStack_6c = (int)(param_4 * uVar9 + 0x32) / 100;
  }
  if (uStack_70 == 2) {
    uStack_68 = 0x1c2;
  }
  else {
    uStack_68 = 300;
    if (uStack_70 == 3) {
      uStack_68 = 600;
    }
  }
  uVar9 = param_6[3];
  uStack_60 = (uint)(uStack_70 - 6 < 2);
  puStack_e0 = (undefined4 *)0x0;
  uVar2 = (undefined4)uStack_5c;
  if (uStack_70 == 7) {
    uVar2 = 0x1822e;
  }
  uStack_5c = CONCAT44(uStack_5c._4_4_,uVar2);
  uStack_f4 = param_6[4];
  if ((uStack_70 == 0) || (uStack_70 == 0x3f)) {
    puStack_e0 = (undefined4 *)FUN_1800b95f0(param_2,*param_2 == 0x76);
  }
  else {
    puStack_e0 = (undefined4 *)FUN_1800ac0e0(*param_2,param_2[1],param_2[4]);
    FUN_1800abe60(*(undefined8 *)(puStack_e0 + 6),*(undefined8 *)(param_2 + 6),param_2[3]);
  }
  if (*param_1 == 0) {
    uVar5 = param_6[6];
    if (param_6[6] < param_6[5]) {
      uVar5 = param_6[5];
    }
    lVar3 = FUN_1800822b0(0x180);
    *param_1 = lVar3;
    FUN_1800abeb0(lVar3,0,0x180);
    uVar4 = FUN_1800822b0((longlong)(int)uVar5 * 0x38);
    *(undefined8 *)(*param_1 + 0xf8) = uVar4;
    *(undefined8 *)(*param_1 + 0x20) = 0;
    *(undefined8 *)(*param_1 + 8) = 0;
    *(undefined8 *)(*param_1 + 0x10) = 0;
    *(undefined8 *)(*param_1 + 0x18) = 0;
    *(undefined8 *)(*param_1 + 0x130) = 0;
  }
  iVar12 = iStack_f8;
  puStack_d8 = (undefined4 *)0x0;
  puStack_b8 = (undefined4 *)0x0;
  lStack_b0 = 0;
  *(undefined4 *)*param_1 = *puStack_e0;
  *(undefined4 *)(*param_1 + 4) = puStack_e0[1];
  *(undefined4 *)(*param_1 + 0x10c) = uStack_f0;
  *(int *)(*param_1 + 0x110) = iStack_f8;
  puStack_d8 = (undefined4 *)FUN_1800ac0e0(*puStack_e0,puStack_e0[1],puStack_e0[4]);
  puStack_b8 = (undefined4 *)FUN_1800ac0e0(*puStack_d8,puStack_d8[1],2);
  lStack_b0 = FUN_1800ac0e0(*puStack_b8,puStack_b8[1],2);
  piStack_c8 = (int *)FUN_1800ac0e0(*puStack_e0,puStack_e0[1],1);
  FUN_1800abeb0(*(undefined8 *)(piStack_c8 + 6),0,piStack_c8[3]);
  puStack_108 = (uint *)CONCAT44(puStack_108._4_4_,1);
  FUN_1800b4770(puStack_e0,piStack_c8,1,0x6e);
  lStack_d0 = 0;
  if (uStack_f4 != 0) {
    lStack_d0 = FUN_1800b5c10(puStack_e0);
  }
  iVar10 = 0;
  pbVar6 = *(byte **)(puStack_e0 + 6);
  psVar7 = *(short **)(lStack_b0 + 0x18);
  if (0 < (int)puStack_e0[3]) {
    do {
      bVar1 = *pbVar6;
      iVar10 = iVar10 + 1;
      pbVar6 = pbVar6 + 1;
      *psVar7 = (ushort)bVar1 << 8;
      psVar7 = psVar7 + 1;
    } while (iVar10 < (int)puStack_e0[3]);
  }
  if (*param_6 - 9 < 2) {
    uVar4 = FUN_1800b4760(0xffffffff);
    uStack_100 = 0xffffffff;
    puStack_108 = (uint *)CONCAT44(puStack_108._4_4_,0xffffffff);
    FUN_1800b2290(lStack_b0,puStack_b8,uVar4,7);
    iVar10 = 0;
    lVar3 = *(longlong *)(puStack_b8 + 6);
    puVar8 = *(undefined1 **)(puStack_d8 + 6);
    if (0 < (int)puStack_d8[3]) {
      do {
        iVar10 = iVar10 + 1;
        *puVar8 = *(undefined1 *)(lVar3 + 1);
        lVar3 = lVar3 + 2;
        puVar8 = puVar8 + 1;
      } while (iVar10 < (int)puStack_d8[3]);
    }
    puStack_108 = (uint *)*param_1;
    FUN_1800b8ca0(uVar9,puStack_d8,lStack_d0,piStack_c8);
  }
  else {
    uVar4 = FUN_1800b4760(0xffffffff);
    uStack_100 = 0xffffffff;
    puStack_108 = (uint *)CONCAT44(puStack_108._4_4_,0xffffffff);
    FUN_1800b2290(lStack_b0,puStack_b8,uVar4,6);
    puVar8 = *(undefined1 **)(puStack_d8 + 6);
    iVar10 = 0;
    lVar3 = *(longlong *)(puStack_b8 + 6);
    if (0 < (int)puStack_d8[3]) {
      do {
        iVar10 = iVar10 + 1;
        *puVar8 = *(undefined1 *)(lVar3 + 1);
        lVar3 = lVar3 + 2;
        puVar8 = puVar8 + 1;
      } while (iVar10 < (int)puStack_d8[3]);
    }
    puStack_108 = (uint *)*param_1;
    FUN_1800b8120(uVar9,puStack_d8,lStack_d0,piStack_c8);
  }
  FUN_1800b66f0(piStack_c8,*param_1 + 0x28);
  uStack_a0 = FUN_1800bb3b0(*param_1 + 0x28,uVar9,param_6[2],param_6[1]);
  FUN_1800b7840(uStack_a0,*param_1 + 0x130);
  FUN_1800acaf0(&uStack_a0);
  if (lStack_d0 == 0) {
    lStack_d0 = FUN_1800ac0e0(*puStack_d8,puStack_d8[1],puStack_d8[4]);
    FUN_1800ac880(puStack_d8,&lStack_d0);
  }
  if (*param_6 == 7) {
    uStack_6c = (int)((uStack_6c - 0x78) * iVar12) / 100 + 0x78;
  }
  puStack_108 = &uStack_70;
  FUN_180092e60(lStack_d0,puStack_d8,*(undefined8 *)(*param_1 + 0xf8),*param_1 + 0xf0);
  if ((*param_6 < 0x3f) && ((0x40000000000000c1U >> ((longlong)(int)*param_6 & 0x3fU) & 1) != 0)) {
    FUN_180093b70(piStack_c8);
  }
  if ((int)lStack_c0 == 1) {
    uStack_100 = 2;
    puStack_108 = (uint *)CONCAT44(puStack_108._4_4_,param_2[1]);
    FUN_1800aa6d0(*(undefined8 *)(*param_1 + 0xf8),lStack_a8,*param_1 + 0xf0,*param_2);
  }
  if (lStack_a8 != 0) {
    FUN_180082260();
  }
  FUN_1800acaf0(&lStack_d0);
  if (lStack_e8 != 0) {
    FUN_1800abe60(*param_1 + 0x160,lStack_e8,0x1c);
  }
  uVar5 = auStack_78[0] & 0x80000003;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 - 1 | 0xfffffffc) + 1;
  }
  *(uint *)(*param_1 + 0x148) = uVar5;
  *(undefined4 *)(*param_1 + 0x150) = 0;
  *(undefined4 *)(*param_1 + 0x14c) = 0;
  lVar3 = *(longlong *)(*param_1 + 0x158);
  if (lVar3 != 0) {
    FUN_1800abeb0(*(undefined8 *)(lVar3 + 0x18),0,*(undefined4 *)(lVar3 + 0xc));
  }
  if (param_7 != (byte *)0x0) {
    uVar5 = (uint)*param_7;
    if ((((*param_6 == 0) || (*param_6 == 10)) && (1 < *param_7)) && (iVar12 < 0x41)) {
      uVar5 = 1;
    }
    *(uint *)(*param_1 + 0x14c) = uVar5;
    if (param_7[1] != 0) {
      *(undefined4 *)(*param_1 + 0x150) = 1;
      iStack_90 = param_2[2];
      iStack_98 = *param_2;
      iStack_88 = param_2[4];
      iStack_8c = param_2[3];
      lStack_c0 = 0;
      iStack_94 = param_2[1];
      pbStack_80 = param_7;
      if ((*param_6 == 0) || (*param_6 == 0x3f)) {
        lStack_c0 = FUN_1800b95f0(&iStack_98,iStack_98 == 0x76);
      }
      else {
        lStack_c0 = FUN_1800ac0e0();
        FUN_1800abe60(*(undefined8 *)(lStack_c0 + 0x18),param_7,param_2[3]);
      }
      iVar12 = 0;
      pcVar11 = *(char **)(lStack_c0 + 0x18);
      if (0 < piStack_c8[1] * *piStack_c8) {
        do {
          iVar12 = iVar12 + 1;
          *pcVar11 = *pcVar11 != '\0';
          pcVar11 = pcVar11 + 1;
        } while (iVar12 < piStack_c8[1] * *piStack_c8);
      }
      FUN_1800b75e0(lStack_c0,*param_1 + 0x158,uVar9);
      if (lStack_c0 != 0) {
        FUN_1800acaf0(&lStack_c0);
      }
    }
  }
  if ((1 < *param_6 - 9) && (iVar12 = 0, 0 < *(int *)(*param_1 + 0xf0))) {
    do {
      FUN_180095b30((longlong)iVar12 * 0x38 + *(longlong *)(*param_1 + 0xf8),param_5);
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(*param_1 + 0xf0));
  }
  FUN_180090d90(*param_1);
  *(undefined4 *)(*param_1 + 0x100) = 0;
  *(undefined4 *)(*param_1 + 0x104) = 0;
  *(undefined4 *)(*param_1 + 0x114) = 0;
  *(undefined4 *)(*param_1 + 0x11c) = 0;
  *(undefined4 *)(*param_1 + 0x120) = 0;
  *(undefined4 *)(*param_1 + 0x124) = 0;
  *(undefined4 *)(*param_1 + 0x128) = 0;
  FUN_1800acaf0(&piStack_c8);
  FUN_1800acaf0(&puStack_d8);
  FUN_1800acaf0(&puStack_b8);
  FUN_1800acaf0(&lStack_b0);
  FUN_1800acaf0(&puStack_e0);
  FUN_180086a70(uStack_48 ^ (ulonglong)auStack_128);
  return;
}

