
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18009e6b0(undefined4 *param_1,longlong param_2,int *param_3,int *param_4)

{
  int *piVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ulonglong uVar8;
  uint uVar9;
  longlong lVar11;
  int iVar12;
  int *piVar13;
  int *piVar14;
  undefined1 auStack_598 [32];
  undefined **ppuStack_578;
  int *piStack_570;
  int *piStack_568;
  undefined **ppuStack_560;
  undefined1 *puStack_558;
  int *piStack_550;
  undefined8 uStack_548;
  int aiStack_538 [2];
  int *piStack_530;
  int iStack_528;
  undefined1 auStack_524 [4];
  longlong lStack_520;
  int iStack_518;
  int iStack_514;
  undefined4 uStack_510;
  int iStack_50c;
  int iStack_508;
  int iStack_504;
  undefined *puStack_500;
  undefined *puStack_4f8;
  undefined *puStack_4f0;
  undefined *puStack_4e8;
  undefined *puStack_4e0;
  undefined *puStack_4d8;
  longlong *plStack_4d0;
  int *piStack_4c8;
  longlong lStack_4c0;
  undefined4 *puStack_4b8;
  undefined *puStack_4b0;
  undefined8 uStack_4a8;
  undefined8 uStack_4a0;
  longlong lStack_498;
  undefined **ppuStack_490;
  int *piStack_488;
  undefined8 uStack_480;
  undefined8 uStack_478;
  undefined8 auStack_470 [2];
  int iStack_460;
  int iStack_45c;
  uint uStack_458;
  undefined8 uStack_454;
  int aiStack_448 [4];
  undefined8 uStack_438;
  undefined8 uStack_430;
  undefined8 uStack_428;
  undefined8 uStack_420;
  undefined4 uStack_418;
  undefined4 uStack_414;
  undefined4 uStack_410;
  undefined4 uStack_40c;
  undefined4 uStack_3f0;
  undefined4 uStack_3ec;
  undefined4 uStack_3dc;
  undefined1 auStack_3d8 [16];
  int iStack_3c8;
  int iStack_3c4;
  uint uStack_3b4;
  undefined *puStack_288;
  undefined8 uStack_280;
  undefined8 uStack_278;
  int aiStack_268 [124];
  undefined1 auStack_78 [9];
  undefined8 uStack_6f;
  undefined8 uStack_67;
  undefined4 uStack_5f;
  undefined2 uStack_5b;
  ulonglong uStack_58;
  ulonglong uVar10;
  
  uStack_58 = _DAT_18012a308 ^ (ulonglong)auStack_598;
  piVar14 = param_4 + 6;
  *param_1 = 0;
  iStack_504 = param_3[1];
  iStack_50c = param_3[2];
  aiStack_448[0] = param_3[3];
  puStack_4f8 = (undefined *)0x0;
  puStack_4f0 = (undefined *)0x0;
  puStack_4e8 = (undefined *)0x0;
  puStack_4e0 = (undefined *)0x0;
  puStack_4d8 = (undefined *)0x0;
  aiStack_448[1] = 0;
  aiStack_448[2] = 1;
  puStack_500 = (undefined *)0x0;
  if (*param_3 == 9) {
    puStack_500 = &UNK_1800f0ff0;
    puStack_4f8 = &UNK_1800f1040;
    puStack_4f0 = &UNK_1800f1090;
    puStack_4e8 = &UNK_1800f10e0;
    puStack_4e0 = &UNK_1800f1130;
    puStack_4d8 = &UNK_1800f1180;
  }
  else if (*param_3 == 10) {
    puStack_500 = &UNK_1800f11d0;
    puStack_4f8 = &UNK_1800f1220;
    puStack_4f0 = &UNK_1800f1270;
    puStack_4e8 = &UNK_1800f12c0;
    puStack_4e0 = &UNK_1800f1310;
    puStack_4d8 = &UNK_1800f1360;
  }
  plStack_4d0 = (longlong *)(param_3 + 0x2344);
  iStack_518 = *param_4 + 2;
  iStack_508 = param_4[1] + 2;
  iStack_514 = *param_4 + 0xd1;
  lStack_4c0 = (longlong)iStack_518;
  aiStack_538[0] = 0;
  auStack_524 = (undefined1  [4])0x0;
  uStack_510 = 2;
  lStack_520 = 0;
  iStack_528 = 0x32;
  piVar13 = param_3 + 0x236c;
  piStack_530 = piVar14;
  piStack_4c8 = param_4;
  puStack_4b8 = param_1;
  do {
    iVar3 = iStack_528;
    lVar2 = *plStack_4d0;
    if ((*piVar13 != -1) && (*(int *)(lVar2 + 0xf0) != 0)) {
      FUN_1800abeb0(&uStack_438,0,0x60);
      uStack_438 = 0;
      uStack_430 = 0;
      uStack_428 = 0;
      uStack_420 = 0;
      uStack_418 = *(undefined4 *)(lVar2 + 0x10c);
      uStack_410 = *(undefined4 *)(lVar2 + 0x110);
      uStack_3f0 = *(undefined4 *)(lVar2 + 0x14c);
      if (param_2 != 0) {
        uStack_414 = *(undefined4 *)(param_2 + 0x10c);
        uStack_3ec = *(undefined4 *)(param_2 + 0x14c);
        uStack_3dc = *(undefined4 *)(param_2 + 0x150);
        uStack_40c = uStack_414;
      }
      puStack_288 = _UNK_1800f0fc0;
      uStack_280 = _UNK_1800f0fc8;
      uStack_278 = 0x100;
      auStack_78._1_8_ = 0;
      uStack_6f = 0;
      auStack_78[0] = 0;
      uStack_67 = 0;
      uStack_5f = 0;
      uStack_5b = 0;
      FUN_1800abeb0(aiStack_268,0xffffffff,0x1f0);
      ppuStack_560 = (undefined **)0x0;
      piStack_568 = (int *)0x0;
      ppuStack_578 = (undefined **)piVar14;
      piStack_570._0_4_ = *param_3;
      FUN_1800c0dd0(lVar2,param_2,0,aiStack_268);
      uStack_548 = 0;
      piStack_550 = (int *)0x0;
      puStack_558 = auStack_78;
      ppuStack_560 = &puStack_288;
      piStack_568 = aiStack_268;
      piStack_570 = (int *)CONCAT44(piStack_570._4_4_,4);
      ppuStack_578 = (undefined **)CONCAT44(ppuStack_578._4_4_,4);
      iVar3 = FUN_18009b330(param_3,param_2,iVar3,0x1f);
      iStack_460 = 0;
      piVar14 = piStack_530;
      if (6 < iVar3) {
        piStack_568 = &iStack_460;
        piStack_570 = (int *)auStack_78;
        ppuStack_578 = &puStack_288;
        FUN_18009e040(lVar2,param_2,0x1f,aiStack_268);
        iVar12 = iStack_460;
        if (iVar3 < iStack_460) {
          iVar3 = iStack_460;
        }
        piVar14 = piStack_530;
        if ((6 < iVar3) &&
           (iVar4 = FUN_18009ae70(&puStack_288,piStack_4c8[0x11],*param_3), piVar14 = piStack_530,
           iVar4 == 0)) {
          piStack_550 = &iStack_460;
          puStack_558 = (undefined1 *)CONCAT44(puStack_558._4_4_,iVar3);
          ppuStack_560 = (undefined **)&uStack_458;
          piStack_568 = &iStack_45c;
          piStack_570 = (int *)((longlong)&uStack_454 + 4);
          ppuStack_578 = (undefined **)&uStack_454;
          uStack_454._0_4_ = 0;
          uStack_454._4_4_ = 0;
          iStack_45c = 0;
          uStack_458 = 0;
          iStack_460 = 0;
          iVar4 = FUN_1800ba280(param_2,lVar2,&puStack_288,aiStack_448);
          piVar14 = piStack_530;
          if (((iVar4 < 0xd7) || ((iStack_45c < 0xd2 || (0 < *(int *)(param_2 + 0x14c))))) &&
             (*(int *)(param_2 + 0x10c) < 0xf)) {
            uVar8 = 0;
            uStack_4a0 = 0x100;
            puStack_4b0 = _UNK_1800f0fc0;
            uStack_4a8 = _UNK_1800f0fc8;
            piStack_488 = _UNK_1800f1410;
            uStack_480 = _UNK_1800f1418;
            lVar11 = 6;
            lStack_498 = _UNK_1800f1400;
            ppuStack_490 = _UNK_1800f1408;
            uStack_478 = _UNK_1800f1590;
            auStack_470[0] = _UNK_1800f1598;
            uVar10 = uVar8;
            do {
              iVar5 = *(int *)((longlong)&puStack_288 + uVar8) -
                      *(int *)((longlong)&puStack_4b0 + uVar8);
              if (iVar5 < 1) {
                iVar5 = *(int *)((longlong)&puStack_4b0 + uVar8) -
                        *(int *)((longlong)&puStack_288 + uVar8);
              }
              piVar1 = (int *)((longlong)&uStack_480 + uVar8);
              uVar8 = uVar8 + 4;
              uVar9 = (uint)uVar10 | (uint)(*piVar1 < iVar5);
              uVar10 = (ulonglong)uVar9;
              lVar11 = lVar11 + -1;
            } while (lVar11 != 0);
            if (uVar9 == 0) goto code_r0x00018009ecd8;
          }
          if (iStack_514 < iVar4) {
            FUN_1800abeb0(auStack_3d8,0,0x144);
            uStack_478 = 0;
            auStack_470[0] = 0;
            iStack_3c4 = iStack_45c;
            uStack_3b4 = iStack_460 * 0x10000 + uStack_458;
            piStack_488 = aiStack_448;
            ppuStack_490 = &puStack_288;
            uStack_480 = CONCAT44(2,iVar3);
            ppuStack_578 = (undefined **)CONCAT44(ppuStack_578._4_4_,*param_3);
            lStack_498 = param_2;
            iStack_3c8 = iVar4;
            FUN_1800b7af0(lVar2,&lStack_498,&puStack_288,auStack_3d8);
            iVar4 = iStack_3c8;
            iStack_45c = iStack_3c4;
            uStack_458 = uStack_3b4 & 0xffff;
            FUN_1800acaf0(&uStack_478);
            FUN_1800acaf0(auStack_470);
            iVar3 = iVar3 - iStack_508;
            iVar5 = 5;
            if (5 < iVar3) {
              iVar5 = iVar3;
            }
            iVar12 = iVar12 - iStack_508;
            iVar6 = 5;
            if (5 < iVar12) {
              iVar6 = iVar12;
            }
            iVar7 = iStack_45c - iStack_518;
            uStack_438 = CONCAT44(iVar6,iVar5);
            iVar6 = iVar4 - iStack_518;
            iVar5 = iStack_45c;
            if (0 < lStack_4c0) {
              iVar5 = iVar7;
              iVar4 = iVar6;
            }
            if (iVar3 < 5) {
              iVar6 = iVar6 + -4;
              iVar7 = iVar7 + -4;
            }
            if (iVar12 < 5) {
              iVar4 = iVar4 + -4;
              iVar5 = iVar5 + -4;
            }
            uStack_428 = CONCAT44(iVar5,iVar7);
            uStack_430 = CONCAT44(iVar4,iVar6);
            iVar3 = *param_3;
            iVar12 = uStack_458 * iStack_50c * iStack_504;
            uStack_420 = CONCAT44(iStack_460,(int)(iVar12 + (iVar12 >> 0x1f & 0xffU)) >> 8);
            uStack_3f0 = *(undefined4 *)(lVar2 + 0x14c);
            uStack_3ec = *(undefined4 *)(param_2 + 0x14c);
            piStack_568 = aiStack_538;
            piStack_570 = (int *)auStack_524;
            ppuStack_578 = &puStack_500;
            FUN_18009bf60(iVar3,1,&uStack_438,&uStack_510);
            piVar14 = piStack_530;
            if (aiStack_538[0] == 1) {
              if (iVar3 - 9U < 2) {
                piStack_570 = aiStack_538;
                ppuStack_578 = (undefined **)auStack_524;
                FUN_18009c5d0(lVar2,param_2,&uStack_438,&puStack_288);
                piVar14 = piStack_530;
                if (aiStack_538[0] != 1) goto code_r0x00018009ecd8;
              }
              *puStack_4b8 = 0x1f5;
              goto code_r0x00018009ed0c;
            }
          }
        }
      }
    }
code_r0x00018009ecd8:
    lStack_520 = lStack_520 + 1;
    iStack_528 = iStack_528 + 1;
    plStack_4d0 = plStack_4d0 + 1;
    piVar13 = piVar13 + 1;
    if (0x13 < lStack_520) {
code_r0x00018009ed0c:
      FUN_180086a70(uStack_58 ^ (ulonglong)auStack_598);
      return;
    }
  } while( true );
}

