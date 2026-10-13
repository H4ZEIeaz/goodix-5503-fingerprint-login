// 1800aee90 FUN_1800aee90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800aee90(longlong *param_1,undefined8 param_2,int param_3,longlong param_4,uint param_5,
                  int *param_6,undefined4 param_7,int *param_8,int *param_9,undefined8 param_10,
                  undefined1 *param_11,ulonglong param_12,uint *param_13)

{
  undefined1 *puVar1;
  longlong *plVar2;
  int *piVar3;
  int *piVar4;
  short sVar5;
  int iVar6;
  undefined4 uVar7;
  short *psVar8;
  uint *puVar9;
  longlong lVar10;
  ulonglong uVar11;
  short *psVar12;
  longlong lVar13;
  int iVar14;
  uint uVar15;
  bool bVar16;
  undefined1 auStack_1b8 [32];
  uint *puStack_198;
  uint *puStack_190;
  uint *puStack_188;
  undefined8 uStack_180;
  undefined1 *puStack_178;
  short *psStack_170;
  undefined4 uStack_168;
  uint *puStack_160;
  undefined4 uStack_158;
  uint uStack_154;
  uint uStack_150;
  uint uStack_14c;
  longlong lStack_148;
  uint uStack_140;
  undefined1 *puStack_138;
  longlong *plStack_130;
  ulonglong uStack_128;
  int *piStack_120;
  int *piStack_118;
  uint *puStack_110;
  longlong lStack_108;
  ulonglong uStack_100;
  longlong lStack_f8;
  uint *puStack_f0;
  uint uStack_e8;
  uint uStack_e4;
  uint uStack_e0;
  int iStack_dc;
  undefined4 uStack_d8;
  longlong lStack_d0;
  uint auStack_c8 [2];
  uint uStack_c0;
  uint uStack_bc;
  int iStack_b8;
  uint uStack_b4;
  uint uStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  undefined4 uStack_a4;
  undefined1 auStack_98 [64];
  ulonglong uStack_58;
  
  uStack_58 = _DAT_18012a308 ^ (ulonglong)auStack_1b8;
  piStack_120 = param_8;
  piStack_118 = param_9;
  puStack_138 = param_11;
  uStack_154 = (int)param_5 >> 0xe & 0x1ff;
  uStack_100 = param_12;
  puStack_110 = param_13;
  uStack_150 = param_5 >> 0x17;
  uStack_158 = 0;
  iVar14 = uStack_154 * uStack_150;
  lVar13 = (longlong)iVar14;
  plStack_130 = param_1;
  FUN_1800b2280(lVar13 * 2 == (longlong)param_3);
  auStack_c8[0] = param_5 & 1;
  uStack_14c = (int)param_5 >> 3 & 0x3f;
  uStack_c0 = uStack_150;
  uStack_a4 = *(undefined4 *)(param_4 + 0x26484);
  uStack_140 = (int)param_5 >> 2 & 1;
  uVar15 = (int)param_5 >> 1 & 1;
  uStack_bc = uStack_154;
  iStack_b8 = iVar14;
  uStack_b4 = auStack_c8[0];
  uStack_b0 = uVar15;
  uStack_ac = uStack_140;
  uStack_a8 = uStack_14c;
  psVar8 = (short *)FUN_1800822b0(lVar13 * 2);
  if (psVar8 != (short *)0x0) {
    FUN_1800abe60(psVar8,param_2,iVar14 * 2);
    FUN_1800abeb0(param_4 + 0x1cb64,0,iVar14);
    FUN_1800abeb0(param_4 + 0x217f4,0,iVar14);
    if (puStack_110 != (uint *)0x0) {
      FUN_1800a2f00(puStack_110);
    }
    iVar6 = FUN_1800add90(&uStack_c0,psVar8);
    if (iVar6 == 0) {
      if (*param_6 == 0) {
        uStack_180 = CONCAT44(uStack_180._4_4_,uStack_14c);
        puStack_188 = (uint *)CONCAT44(puStack_188._4_4_,uStack_150);
        puStack_190 = (uint *)CONCAT44(puStack_190._4_4_,uStack_154);
        puStack_198 = (uint *)0x18019c11c;
        iVar14 = FUN_1800b1910(psVar8,param_4,auStack_c8[0],uVar15);
        if (iVar14 != 0) {
          *param_6 = 1;
        }
        *piStack_120 = 0;
        *piStack_118 = 0;
        FUN_180082260(psVar8);
      }
      else {
        uStack_128 = uStack_128 & 0xffffffff00000000;
        auStack_c8[0] = 0;
        puVar9 = (uint *)FUN_1800822b0(0x4c9c);
        if (puVar9 == (uint *)0x0) {
          FUN_180082260(psVar8);
        }
        else {
          lStack_148 = FUN_1800822b0(0x4fc4);
          plVar2 = plStack_130;
          if (lStack_148 == 0) {
            FUN_180082260(psVar8);
            FUN_180082260(puVar9);
          }
          else {
            if (*plStack_130 == 0) {
              lVar10 = FUN_1800ac0e0(uStack_150,uStack_154,1);
              *plVar2 = lVar10;
            }
            FUN_1800abeb0(*(undefined8 *)(*plVar2 + 0x18),0,iVar14);
            FUN_1800acd10(psVar8,param_4 + 0x9924,&uStack_c0,puVar9);
            FUN_1800abeb0(&lStack_f8,0,8);
            bVar16 = uStack_14c == 0x14;
            if (!bVar16) {
              lStack_f8 = FUN_1800822b0(lVar13 * 2);
            }
            puStack_190 = &uStack_c0;
            puStack_198 = (uint *)&lStack_f8;
            puStack_188 = puVar9;
            FUN_1800aff20(psVar8,param_4,uRam000000018019c11c,auStack_98);
            puStack_198 = (uint *)lStack_148;
            FUN_1800aeaa0(param_4 + 0x13244,param_4 + 0x1cb64,&uStack_c0,puVar9);
            uStack_e4 = uStack_154;
            uStack_e8 = uStack_150;
            uStack_e0 = uStack_150;
            uStack_d8 = 1;
            iStack_dc = iVar14;
            lStack_d0 = param_4 + 0x1cb64;
            puStack_f0 = (uint *)FUN_1800ac0e0(uStack_150,uStack_154,1);
            puStack_198 = (uint *)CONCAT44(puStack_198._4_4_,0xff);
            FUN_1800b4770(&uStack_e8,puStack_f0,1);
            if ((uStack_14c < 0x15) && ((0x10000dU >> (uStack_14c & 0x1f) & 1) != 0)) {
              uVar7 = 0;
            }
            else {
              uVar7 = 1;
            }
            puStack_178 = (undefined1 *)0x0;
            uStack_180 = *(undefined8 *)(puStack_f0 + 6);
            puStack_190 = &uStack_c0;
            puStack_198 = (uint *)(param_4 + 0x26484);
            puStack_188 = puVar9;
            FUN_1800ad370(param_4,param_7,uVar7,*(undefined8 *)(*plStack_130 + 0x18));
            if (bVar16) {
              uVar15 = (uint)uStack_128;
            }
            else {
              puStack_160 = auStack_c8;
              uStack_168 = uRam000000018019c11c;
              puStack_178 = auStack_98;
              uStack_180 = *(undefined8 *)(*plStack_130 + 0x18);
              puStack_188 = puStack_f0;
              puStack_198 = (uint *)CONCAT44(puStack_198._4_4_,uVar7);
              puStack_190 = puVar9;
              psStack_170 = psVar8;
              uStack_158 = FUN_1800ad970(param_10,&uStack_c0,&lStack_f8,param_4);
              uVar15 = auStack_c8[0];
            }
            if (lStack_f8 != 0) {
              FUN_180082260();
            }
            puVar1 = puStack_138;
            if ((uStack_140 != 0) && (puStack_138 != (undefined1 *)0x0)) {
              if ((cRam0000000180189c21 == '\0') &&
                 ((*(int *)(param_4 + 0x30488) != 0 &&
                  (iVar6 = FUN_1800a6fe0(param_4 + 0x26488,param_5,0x180189c20), iVar6 != 0)))) {
                FUN_1800abeb0(0x180189c20,0,0x124fb);
              }
              FUN_1800abeb0(puVar1,0,0x4c98);
              uVar11 = FUN_1800822b0(lVar13);
              uStack_128 = uVar11;
              FUN_1800abeb0(uVar11,0,iVar14);
              lStack_108 = FUN_1800822b0(iVar14 * 2);
              if (iVar14 != 0) {
                psVar12 = psVar8;
                do {
                  sVar5 = *(short *)((param_4 - (longlong)psVar8) + 0x9924 + (longlong)psVar12) -
                          *psVar12;
                  if (sVar5 < 1) {
                    sVar5 = 0;
                  }
                  *(short *)((lStack_108 - (longlong)psVar8) + (longlong)psVar12) = sVar5;
                  psVar12 = psVar12 + 1;
                  lVar13 = lVar13 + -1;
                  uVar11 = uStack_128;
                } while (lVar13 != 0);
              }
              puStack_198._0_4_ = uStack_14c;
              uVar7 = FUN_1800a9010(lStack_108,puVar9,uRam0000000180189c20,uVar11);
              uVar11 = uStack_128;
              uStack_180 = CONCAT44(uStack_180._4_4_,uStack_a4);
              puStack_188 = (uint *)CONCAT44(puStack_188._4_4_,uVar7);
              puStack_190 = (uint *)CONCAT44(puStack_190._4_4_,
                                             (int)*(short *)((longlong)puVar9 + 10));
              puStack_198 = (uint *)CONCAT44(puStack_198._4_4_,uStack_154);
              iVar14 = FUN_1800a7ff0(uStack_128,puStack_138,0x180189c20,uStack_150);
              if (cRam0000000180189c21 != '\0') {
                auStack_c8[0] = 0;
                puStack_198 = auStack_c8;
                FUN_1800a6b40(0x180189c20,param_5,param_4 + 0x26488,0xa000);
                *(uint *)(param_4 + 0x30488) = auStack_c8[0] + 9;
              }
              if (iVar14 != 0) {
                puStack_138[1] = 1;
              }
              *puStack_138 = (char)uVar7;
              if (iVar14 < 0) {
                uRam0000000180189c20 = 0;
              }
              FUN_180082260(lStack_108);
              FUN_180082260(uVar11);
            }
            puStack_190 = (uint *)uStack_100;
            puStack_198 = (uint *)CONCAT44(puStack_198._4_4_,*(undefined4 *)(param_4 + 0x26484));
            FUN_1800c49b0(param_4,psVar8,param_5,puStack_f0);
            FUN_1800acaf0(&puStack_f0);
            piVar4 = piStack_118;
            piVar3 = piStack_120;
            plVar2 = plStack_130;
            FUN_180092430(*plStack_130,param_5,piStack_120,piStack_118);
            lVar13 = lStack_148;
            if (*piVar4 < 6) {
              *piVar3 = 0;
            }
            if ((((uStack_140 != 0) && (*piVar3 < 0x23)) && (uStack_14c != 0x14)) &&
               ((uVar15 == 0 && (iVar14 = FUN_1800aea20(lStack_148,&uStack_c0), iVar14 == 1)))) {
              puStack_190 = (uint *)((ulonglong)puStack_190 & 0xffffffff00000000);
              puStack_198 = (uint *)CONCAT44(puStack_198._4_4_,1);
              FUN_1800b9bc0(*(undefined8 *)(*plVar2 + 0x18),0,uStack_154,uStack_150);
              uVar15 = 1;
            }
            if (puStack_110 != (uint *)0x0) {
              *puStack_110 = uVar15;
            }
            FUN_180082260(lVar13);
            FUN_180082260(puVar9);
            FUN_180082260(psVar8);
          }
        }
      }
    }
    else {
      *piStack_120 = 0;
      *piStack_118 = 0;
      FUN_180082260(psVar8);
    }
  }
  FUN_180086a70(uStack_58 ^ (ulonglong)auStack_1b8);
  return;
}

