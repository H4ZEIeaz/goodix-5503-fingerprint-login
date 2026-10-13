
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18009f4a0(int *param_1,int *param_2,int *param_3,undefined4 *param_4,longlong param_5,
                  undefined8 param_6)

{
  int *piVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  bool bVar4;
  longlong lVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  longlong lVar13;
  int iVar14;
  int iVar15;
  undefined8 unaff_RBX;
  longlong lVar16;
  int iVar17;
  longlong lVar18;
  int iVar19;
  undefined8 unaff_R13;
  longlong lStackX_8;
  int aiStackX_10 [2];
  longlong lStackX_18;
  int iStackX_20;
  int iStackX_24;
  undefined4 auStack_1df8 [2];
  undefined *puStack_1df0;
  undefined *puStack_1de8;
  undefined *puStack_1de0;
  undefined *puStack_1dd8;
  undefined *puStack_1dd0;
  undefined *puStack_1dc8;
  int *piStack_1dc0;
  int *piStack_1db8;
  undefined8 uStack_1db0;
  undefined8 uStack_1da8;
  undefined8 uStack_1da0;
  int *piStack_1d98;
  undefined8 *puStack_1d90;
  int *piStack_1d88;
  undefined8 uStack_1d80;
  undefined8 uStack_1d78;
  undefined8 auStack_1d70 [2];
  int iStack_1d60;
  uint uStack_1d5c;
  uint uStack_1d58;
  int aiStack_1d54 [4];
  undefined4 uStack_1d44;
  undefined4 uStack_1d40;
  undefined8 uStack_1d38;
  undefined8 uStack_1d30;
  undefined8 uStack_1d28;
  undefined8 uStack_1d20;
  undefined4 uStack_1d18;
  int iStack_1d14;
  undefined4 uStack_1d10;
  int iStack_1d0c;
  int iStack_1d08;
  undefined4 uStack_1d04;
  uint uStack_1d00;
  uint uStack_1cfc;
  uint uStack_1cf8;
  uint uStack_1cf4;
  undefined4 uStack_1cf0;
  int iStack_1cec;
  int iStack_1cdc;
  int iStack_1cd8;
  int iStack_1cd4;
  int iStack_1cd0;
  int iStack_1cc8;
  int iStack_1cc4;
  int iStack_1cbc;
  int iStack_1cb8;
  int iStack_1cb4;
  uint uStack_1ca4;
  undefined4 uStack_1ca0;
  undefined1 auStack_1b78 [2064];
  undefined8 uStack_1368;
  undefined8 uStack_1360;
  undefined8 uStack_1358;
  undefined1 auStack_1348 [4800];
  undefined1 auStack_88 [56];
  ulonglong uStack_50;
  undefined *puStack_38;
  
  puStack_38 = &UNK_18009f4bc;
  lVar9 = FUN_180087740();
  lVar5 = param_5;
  lVar9 = -lVar9;
  uStack_50 = _DAT_18012a308 ^ (ulonglong)(&stack0xffffffffffffffd0 + lVar9);
  *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009f4f3;
  piStack_1dc0 = param_1;
  FUN_18009ade0();
  *param_1 = 0;
  if (param_2[0x3c] == 0) goto DAT_18009febe;
  iVar15 = param_3[1];
  *(undefined8 *)(&stack0x00001e20 + lVar9) = unaff_RBX;
  iVar19 = param_3[2];
  *(undefined8 *)(&stack0x00001e18 + lVar9) = unaff_R13;
  uStack_1d44 = 0;
  *(undefined4 *)(&stack0x00000040 + lVar9) = param_4[4];
  aiStack_1d54[3] = param_3[3];
  uStack_1d40 = 1;
  puStack_1df0 = (undefined *)0x0;
  puStack_1de8 = (undefined *)0x0;
  puStack_1de0 = (undefined *)0x0;
  puStack_1dd8 = (undefined *)0x0;
  puStack_1dd0 = (undefined *)0x0;
  puStack_1dc8 = (undefined *)0x0;
  if (*param_3 == 9) {
    puStack_1df0 = &UNK_1800f0ff0;
    puStack_1de8 = &UNK_1800f1040;
    puStack_1de0 = &UNK_1800f1090;
    puStack_1dd8 = &UNK_1800f10e0;
    puStack_1dd0 = &UNK_1800f1130;
    puStack_1dc8 = &UNK_1800f1180;
  }
  else if (*param_3 == 10) {
    puStack_1df0 = &UNK_1800f11d0;
    puStack_1de8 = &UNK_1800f1220;
    puStack_1de0 = &UNK_1800f1270;
    puStack_1dd8 = &UNK_1800f12c0;
    puStack_1dd0 = &UNK_1800f1310;
    puStack_1dc8 = &UNK_1800f1360;
  }
  uVar2 = *param_4;
  *(undefined4 *)(&stack0x0000004c + lVar9) = param_4[1];
  *(undefined4 *)(&stack0x00000044 + lVar9) = uVar2;
  *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009f60f;
  FUN_1800abeb0(auStack_88);
  iVar14 = 0;
  iVar10 = 0;
  *(undefined4 *)(&stack0x00000048 + lVar9) = 0;
  auStack_1df8[0] = 2;
  iVar11 = 0;
  iVar6 = 0;
  *(undefined4 *)((longlong)&param_6 + lVar9) = 0;
  *(undefined4 *)((longlong)&param_5 + lVar9 + 4) = 0;
  *(undefined4 *)((longlong)&iStackX_24 + lVar9) = 0;
  *(undefined4 *)(&stack0x0000003c + lVar9) = 0;
  *(undefined4 *)((longlong)&param_5 + lVar9) = 0;
  *(undefined4 *)(&stack0x00000038 + lVar9) = 0;
  *(undefined4 *)((longlong)&iStackX_20 + lVar9) = 0;
  if (0 < param_3[7]) {
    piStack_1db8 = param_3 + 0x21fa;
    do {
      iVar14 = *piStack_1db8;
      lVar16 = (longlong)iVar14;
      lVar13 = *(longlong *)(param_3 + lVar16 * 2 + 10);
      if (*(int *)(lVar13 + 0xf0) != 0) {
        if ((param_4[0xd] == 0) && (iVar14 != param_4[0xe])) {
          *(undefined4 *)(lVar16 * 0x20 + 0x1c + lVar5) = 0xfffffffe;
        }
        else if ((*(int *)(lVar5 + 0x688) != 1) ||
                ((*(int *)(lVar5 + 0x644) != 1 || (*(int *)(lVar13 + 0x100) != 1)))) {
          auStack_88[lVar16] = 1;
          *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009f6cf;
          FUN_1800abeb0(&uStack_1d38,0,0x60);
          uStack_1d38 = 0;
          uStack_1d30 = 0;
          uStack_1d28 = 0;
          uStack_1d20 = 0;
          uStack_1d18 = *(undefined4 *)(lVar13 + 0x10c);
          uStack_1d10 = *(undefined4 *)(lVar13 + 0x110);
          uStack_1cf0 = *(undefined4 *)(lVar13 + 0x14c);
          uStack_1358 = 0x100;
          uStack_1368 = _UNK_1800f0fc0;
          uStack_1360 = _UNK_1800f0fc8;
          iStack_1d14 = param_2[0x43];
          iStack_1cec = param_2[0x53];
          iStack_1cdc = param_2[0x54];
          *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009f753;
          iStack_1d0c = iStack_1d14;
          FUN_1800abeb0(&iStack_1cc8,0,0x144);
          *(undefined8 *)((longlong)&lStackX_8 + lVar9) = param_6;
          *(int **)(&stack0x00000000 + lVar9) = &iStack_1cc8;
          *(undefined8 **)(&stack0xfffffffffffffff8 + lVar9) = &uStack_1368;
          *(int *)(&stack0xfffffffffffffff0 + lVar9) = iVar14;
          *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009f790;
          FUN_18009d6a0(param_3,param_2,0,param_4);
          iVar10 = iStack_1cc8;
          iStack_1d60 = iStack_1cbc;
          if (iStack_1cc8 < 5) {
code_r0x00018009fc59:
            if (iVar11 == 0) {
              *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009fc72;
              iStack_1d60 = iVar11;
              FUN_1800a2700(&uStack_1368,&iStack_1d60);
              if ((iStack_1d60 < 0xf) || (0x168 < iStack_1d60 + 0xf)) {
                iVar14 = param_2[1];
                iVar10 = *param_2;
                *(undefined1 **)(&stack0xfffffffffffffff8 + lVar9) = auStack_1b78;
                *(undefined8 **)(&stack0xfffffffffffffff0 + lVar9) = &uStack_1368;
                *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009fcb2;
                iVar6 = FUN_1800bb010(iVar14,iVar10,iVar14,iVar10);
                if (((iVar10 * iVar14 * 0x4b < iVar6 * 100) && (10 < (int)uStack_1d38)) &&
                   (((int)uStack_1d28 < 200 || (500 < uStack_1d20._4_4_)))) {
                  *(int *)((longlong)&param_5 + lVar9) = *(int *)((longlong)&param_5 + lVar9) + 1;
                }
              }
            }
          }
          else {
            iVar6 = *param_3;
            uVar2 = param_4[0x11];
            *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009f7ba;
            iVar6 = FUN_18009ae70(&uStack_1368,uVar2,iVar6);
            if (iVar6 != 0) goto code_r0x00018009fcfc;
            uVar3 = *(undefined8 *)(param_3 + lVar16 * 2 + 10);
            aiStack_1d54[2] = 0;
            aiStack_1d54[1] = 0;
            aiStack_1d54[0] = 0;
            uStack_1d5c = 0;
            uStack_1d58 = 0;
            *(uint **)((longlong)&lStackX_18 + lVar9) = &uStack_1d58;
            *(int *)((longlong)aiStackX_10 + lVar9) = iVar10;
            *(uint **)((longlong)&lStackX_8 + lVar9) = &uStack_1d5c;
            *(int **)(&stack0x00000000 + lVar9) = aiStack_1d54;
            *(int **)(&stack0xfffffffffffffff8 + lVar9) = aiStack_1d54 + 1;
            *(undefined4 *)(&stack0x00000048 + lVar9) = 1;
            *(int **)(&stack0xfffffffffffffff0 + lVar9) = aiStack_1d54 + 2;
            *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009f824;
            iVar6 = FUN_1800ba280(param_2,uVar3,&uStack_1368);
            if ((((iVar6 < 0xd7) || (aiStack_1d54[0] < 0xd2)) || (0 < param_2[0x53])) &&
               (param_2[0x43] < 0xf)) {
              bVar4 = false;
              uStack_1da0 = 0x100;
              lVar13 = 0;
              uStack_1db0 = _UNK_1800f0fc0;
              uStack_1da8 = _UNK_1800f0fc8;
              piStack_1d88 = _UNK_1800f1410;
              uStack_1d80 = _UNK_1800f1418;
              lVar18 = 6;
              piStack_1d98 = _UNK_1800f1400;
              puStack_1d90 = _UNK_1800f1408;
              uStack_1d78 = _UNK_1800f1590;
              auStack_1d70[0] = _UNK_1800f1598;
              do {
                iVar7 = *(int *)((longlong)&uStack_1368 + lVar13) -
                        *(int *)((longlong)&uStack_1db0 + lVar13);
                if (iVar7 < 1) {
                  iVar7 = *(int *)((longlong)&uStack_1db0 + lVar13) -
                          *(int *)((longlong)&uStack_1368 + lVar13);
                }
                piVar1 = (int *)((longlong)&uStack_1d80 + lVar13);
                lVar13 = lVar13 + 4;
                bVar4 = (bool)(bVar4 | *piVar1 < iVar7);
                lVar18 = lVar18 + -1;
              } while (lVar18 != 0);
              if (!bVar4) goto code_r0x00018009fcfc;
            }
            if (iVar6 <= *(int *)(&stack0x00000044 + lVar9) + 0xcf) goto code_r0x00018009fc59;
            uVar3 = *(undefined8 *)(param_3 + lVar16 * 2 + 10);
            uStack_1d78 = 0;
            auStack_1d70[0] = 0;
            uStack_1ca4 = uStack_1d58 * 0x10000 + uStack_1d5c;
            piStack_1d88 = aiStack_1d54 + 3;
            iStack_1cb4 = aiStack_1d54[0];
            puStack_1d90 = &uStack_1368;
            *(int *)(&stack0xfffffffffffffff0 + lVar9) = *param_3;
            uStack_1d80 = CONCAT44(2,iVar10);
            *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009f952;
            piStack_1d98 = param_2;
            iStack_1cb8 = iVar6;
            FUN_1800b7af0(uVar3,&piStack_1d98,&uStack_1368,&iStack_1cc8);
            iVar6 = iStack_1cb8;
            aiStack_1d54[0] = iStack_1cb4;
            uStack_1d5c = uStack_1ca4 & 0xffff;
            uStack_1d58 = uStack_1ca4 >> 0x10;
            *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009f97c;
            FUN_1800acaf0(&uStack_1d78);
            *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009f985;
            FUN_1800acaf0(auStack_1d70);
            *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009f998;
            FUN_1800b7ff0(&uStack_1368,&iStack_1cd8);
            uStack_1d00 = (uint)(0x2f < iStack_1cd8 - 0xeaU);
            iVar11 = *(int *)(&stack0x0000004c + lVar9);
            uStack_1cfc = (uint)(0x4f < iStack_1cd4);
            uStack_1cf8 = (uint)(0x147a < iStack_1cd0);
            iVar7 = iVar10 - iVar11;
            uStack_1cf4 = (uint)(0x28f5 < iStack_1cd0);
            iStack_1d08 = 5;
            if (5 < iVar7) {
              iStack_1d08 = iVar7;
            }
            iVar17 = iStack_1d60 - iVar11;
            uStack_1d04 = uStack_1ca0;
            iVar8 = 5;
            if (5 < iVar17) {
              iVar8 = iVar17;
            }
            uStack_1d38 = CONCAT44(iVar8,iStack_1d08);
            iVar11 = iStack_1cc4 + iVar11 * -2;
            if (iStack_1d08 < iVar11) {
              iStack_1d08 = iVar11;
            }
            iVar8 = iVar6 - *(int *)(&stack0x00000044 + lVar9);
            uStack_1d30 = CONCAT44(uStack_1d30._4_4_,iVar8);
            iVar12 = aiStack_1d54[0] - *(int *)(&stack0x00000044 + lVar9);
            iVar11 = aiStack_1d54[0];
            if (0 < *(int *)(&stack0x00000044 + lVar9)) {
              iVar11 = iVar12;
              iVar6 = iVar8;
            }
            if (iVar7 < 5) {
              iVar8 = iVar8 + -4;
              iVar12 = iVar12 + -4;
            }
            if (iVar17 < 5) {
              iVar6 = iVar6 + -4;
              iVar11 = iVar11 + -4;
            }
            uStack_1d28 = CONCAT44(iVar11,iVar12);
            uStack_1d30 = CONCAT44(iVar6,iVar8);
            iVar6 = *param_3;
            uStack_1d20 = CONCAT44(uStack_1d58,(undefined4)uStack_1d20);
            iVar11 = uStack_1d5c * iVar19 * iVar15;
            uVar2 = *(undefined4 *)(&stack0x00000040 + lVar9);
            uStack_1d20 = CONCAT44(uStack_1d58,(int)(iVar11 + (iVar11 >> 0x1f & 0xffU)) >> 8);
            iVar11 = iStack_1d60;
            if (iStack_1d60 < *(int *)((longlong)&param_5 + lVar9 + 4)) {
              iVar11 = *(int *)((longlong)&param_5 + lVar9 + 4);
            }
            *(int *)((longlong)&param_5 + lVar9 + 4) = iVar11;
            *(longlong *)(&stack0x00000000 + lVar9) = (longlong)&iStackX_24 + lVar9;
            *(undefined1 **)(&stack0xfffffffffffffff8 + lVar9) = &stack0x0000003c + lVar9;
            *(undefined ***)(&stack0xfffffffffffffff0 + lVar9) = &puStack_1df0;
            *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009faef;
            FUN_18009bf60(iVar6,uVar2,&uStack_1d38,auStack_1df8);
            iVar11 = *(int *)((longlong)&iStackX_24 + lVar9);
            if (iVar11 == 1) {
              if (iVar6 - 9U < 2) {
                uVar3 = *(undefined8 *)(param_3 + lVar16 * 2 + 10);
                *(longlong *)(&stack0xfffffffffffffff8 + lVar9) = (longlong)&iStackX_24 + lVar9;
                *(undefined1 **)(&stack0xfffffffffffffff0 + lVar9) = &stack0x0000003c + lVar9;
                *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009fb2e;
                FUN_18009c5d0(uVar3,param_2,&uStack_1d38,&uStack_1368);
                iVar11 = *(int *)((longlong)&iStackX_24 + lVar9);
                *(uint *)(&stack0x00000038 + lVar9) = (uint)(iVar11 == 0);
                if (iVar11 != 1) goto code_r0x00018009fb6e;
              }
              *(int *)(lVar16 * 0x20 + 0x1c + lVar5) = iStack_1d60;
              *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009fb6c;
              FUN_1800abe60(lVar5 + 4 + lVar16 * 0x20,&uStack_1368,0x18);
            }
            else {
code_r0x00018009fb6e:
              *(undefined4 *)(lVar16 * 0x20 + 0x1c + lVar5) = 0xfffffffe;
              if (iVar11 != 1) goto code_r0x00018009fc59;
            }
            *(int *)((longlong)&param_6 + lVar9) = *(int *)((longlong)&param_6 + lVar9) + 1;
            *piStack_1dc0 = 0x65;
            param_3[0x233d] = param_3[0x233d] + 1;
            *(int *)(*(longlong *)(param_3 + lVar16 * 2 + 10) + 0x124) =
                 *(int *)(*(longlong *)(param_3 + lVar16 * 2 + 10) + 0x124) + 1;
            auStack_88[lVar16] = 2;
            *(undefined4 *)(lVar5 + 0x684) = 1;
            if (*(int *)(&stack0x0000003c + lVar9) == 1) {
              *(undefined4 *)(lVar5 + 0x688) = 1;
            }
            if ((*(int *)(*(longlong *)(param_3 + lVar16 * 2 + 10) + 0x100) == 1) &&
               (*(undefined4 *)(lVar5 + 0x644) = 1, *(int *)(lVar5 + 0x668) < iVar10)) {
              *(int *)(lVar5 + 0x668) = iVar10;
              *(longlong *)(&stack0xfffffffffffffff8 + lVar9) = lVar5 + 0x66c;
              *(int *)(&stack0xfffffffffffffff0 + lVar9) = param_3[0x21f6];
              *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009fc1c;
              FUN_18009b8c0(param_3 + 10,param_3 + 0x6e,&uStack_1368,iVar14);
            }
            if (*(int *)(lVar5 + 0x64c) < iVar10) {
              *(int *)(lVar5 + 0x64c) = iVar10;
              *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009fc43;
              FUN_1800abe60(lVar5 + 0x650,&uStack_1368,0x18);
              *(int *)(lVar5 + 0x648) = iVar14;
            }
            if (*(int *)(&stack0x00000040 + lVar9) == 0) break;
          }
          *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009fcfc;
          FUN_1800abe60(auStack_1348 + lVar16 * 0x60,&uStack_1d38,0x60);
        }
      }
code_r0x00018009fcfc:
      iVar14 = *(int *)((longlong)&iStackX_20 + lVar9) + 1;
      piStack_1db8 = piStack_1db8 + 1;
      *(int *)((longlong)&iStackX_20 + lVar9) = iVar14;
    } while (iVar14 < param_3[7]);
    iVar14 = *(int *)((longlong)&param_5 + lVar9);
    iVar10 = *(int *)((longlong)&param_5 + lVar9 + 4);
    iVar6 = *(int *)((longlong)&param_6 + lVar9);
    param_1 = piStack_1dc0;
  }
  iVar15 = 1;
  if ((*param_1 < 1) || (iVar14 < 4)) {
    iVar19 = *(int *)(&stack0x00000038 + lVar9);
  }
  else {
    *param_1 = -0x2bd;
    iVar19 = 1;
    *(undefined8 *)(lVar5 + 0x684) = 0;
  }
  iVar11 = *param_1;
  *(undefined4 *)((longlong)&iStackX_20 + lVar9) = 1;
  if (0 < iVar11) {
    if (*(int *)(&stack0x00000040 + lVar9) == 1) {
      if (*(int *)(lVar5 + 0x688) == 1) goto code_r0x00018009fd81;
      if (1 < iVar6) goto code_r0x00018009fd78;
code_r0x00018009fd86:
      *(longlong *)(&stack0xfffffffffffffff8 + lVar9) = (longlong)&iStackX_20 + lVar9;
      *(undefined ***)(&stack0xfffffffffffffff0 + lVar9) = &puStack_1df0;
      *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009fdb2;
      FUN_180098c90(param_3,lVar5,auStack_1348,auStack_88);
      iVar15 = *(int *)((longlong)&iStackX_20 + lVar9);
      if (iVar15 == 0) {
        *(undefined8 *)(lVar5 + 0x684) = 0;
        *param_1 = -0x68;
        goto code_r0x00018009fdd9;
      }
      *param_1 = 0x68;
    }
    else {
code_r0x00018009fd78:
      if (*(int *)(lVar5 + 0x688) == 1) {
code_r0x00018009fd81:
        if (iVar10 < 7) goto code_r0x00018009fd86;
      }
    }
    *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009fdd9;
    FUN_18009a130(param_3);
  }
code_r0x00018009fdd9:
  if (*(int *)(lVar5 + 0x688) == 1) {
    *param_1 = 0x6f;
  }
  else if (*param_1 < 1) {
    if (*param_1 == -0x68) {
      *param_1 = -0x68;
    }
    else if (param_2[0x44] < 0x32) {
      *param_1 = -0x65;
    }
    else if ((*(int *)(&stack0x00000048 + lVar9) == 1) && (param_2[0x43] < 0x19)) {
      *param_1 = -0x66;
    }
    else {
      *param_1 = -100;
    }
    if ((((0x28 < param_2[0x43]) && (iVar15 == 1)) && (param_4[0xd] == 1)) && (param_3[0x2380] == 0)
       ) {
      *(undefined4 *)(&stack0xfffffffffffffff0 + lVar9) = 0x14;
      *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009fe72;
      FUN_1800a11e0(param_2,param_3,param_3 + 0x2344,param_3 + 0x236c);
    }
    if ((((*param_1 < 1) && (iVar15 == 1)) &&
        ((param_4[0xd] == 1 && ((param_3[0x2380] == 1 && (param_2[0x53] == 0)))))) && (iVar19 == 0))
    {
      *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009feac;
      FUN_18009e6b0(param_1,param_2,param_3,param_4);
    }
  }
DAT_18009febe:
  *(undefined **)((longlong)&puStack_38 + lVar9) = &UNK_18009fecd;
  FUN_180086a70(uStack_50 ^ (ulonglong)(&stack0xffffffffffffffd0 + lVar9));
  return;
}

