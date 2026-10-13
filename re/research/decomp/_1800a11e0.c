
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800a11e0(undefined8 param_1,longlong param_2,longlong param_3,int *param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  ulonglong uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 auStack_d8 [32];
  undefined4 *puStack_b8;
  undefined4 *puStack_b0;
  undefined4 *puStack_a8;
  undefined4 *puStack_a0;
  undefined4 uStack_98;
  undefined4 *puStack_90;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 auStack_78 [2];
  undefined4 uStack_70;
  undefined8 uStack_6c;
  undefined8 uStack_60;
  undefined8 uStack_58;
  undefined8 uStack_50;
  ulonglong uStack_48;
  
  uStack_48 = _DAT_18012a308 ^ (ulonglong)auStack_d8;
  uVar5 = (ulonglong)param_5;
  iVar3 = -1;
  iVar2 = 0;
  iVar8 = -1;
  iVar6 = -100;
  iVar7 = -100;
  iVar9 = param_5 + 1;
  piVar4 = param_4;
  if (0 < (int)param_5) {
    do {
      iVar1 = *piVar4;
      iVar7 = iVar6;
      if (iVar6 < iVar1) {
        iVar3 = iVar2;
        iVar7 = iVar1;
      }
      if (iVar1 < iVar9) {
        iVar8 = iVar2;
        iVar9 = iVar1;
      }
      iVar2 = iVar2 + 1;
      piVar4 = piVar4 + 1;
      iVar6 = iVar7;
    } while (iVar2 < (int)param_5);
  }
  if ((*(int *)(param_2 + 0x8e00) == 0) && (iVar7 != -1)) {
    uStack_70 = *(undefined4 *)(param_2 + 0xc);
    puStack_90 = &uStack_84;
    uStack_60 = _UNK_1800f0fc0;
    uStack_58 = _UNK_1800f0fc8;
    uStack_98 = 10;
    puStack_a0 = auStack_78;
    puStack_a8 = &uStack_7c;
    uStack_6c = 0;
    puStack_b0 = &uStack_88;
    uStack_80 = 0;
    uStack_88 = 0;
    uStack_7c = 0;
    puStack_b8 = &uStack_80;
    auStack_78[0] = 0;
    uStack_84 = 0;
    uStack_50 = 0x100;
    iVar3 = FUN_1800ba280(param_1,*(undefined8 *)(param_3 + (longlong)iVar3 * 8),&uStack_60,
                          &uStack_70);
    if (0xbe < iVar3) goto code_r0x0001800a1341;
  }
  FUN_1800a1060(param_2,param_1,*(undefined8 *)(param_3 + (longlong)iVar8 * 8));
  if (iVar7 == param_5 - 1) {
    piVar4 = param_4;
    if (0 < (int)param_5) {
      do {
        if (*piVar4 != -1) {
          *piVar4 = *piVar4 + -1;
        }
        uVar5 = uVar5 - 1;
        piVar4 = piVar4 + 1;
      } while (uVar5 != 0);
    }
    iVar7 = iVar7 + -1;
  }
  param_4[iVar8] = iVar7 + 1;
code_r0x0001800a1341:
  FUN_180086a70(uStack_48 ^ (ulonglong)auStack_d8);
  return;
}

