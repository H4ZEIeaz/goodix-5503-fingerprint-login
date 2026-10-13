
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180097d90(int *param_1,longlong param_2,uint *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  ulonglong uVar8;
  uint *puVar9;
  undefined1 auStack_188 [32];
  int *piStack_168;
  int iStack_158;
  uint uStack_154;
  uint uStack_150;
  int iStack_14c;
  undefined1 *puStack_148;
  uint *puStack_140;
  undefined4 uStack_138;
  int iStack_134;
  int iStack_130;
  uint auStack_128 [4];
  undefined1 auStack_118 [208];
  ulonglong uStack_48;
  
  uStack_48 = _DAT_18012a308 ^ (ulonglong)auStack_188;
  auStack_128[0] = param_3[3];
  uVar8 = 0;
  auStack_128[1] = 0;
  auStack_128[2] = 0;
  if ((*param_3 < 9) && ((0x132U >> (*param_3 & 0x1f) & 1) != 0)) {
    auStack_128[1] = 4;
    auStack_128[2] = 0;
  }
  uVar1 = param_3[8];
  uVar7 = param_3[7];
  uVar2 = param_3[1];
  uVar3 = param_3[2];
  if (uVar7 < uVar1) {
    if (*(int *)(param_2 + 0xf0) == 0) {
      *param_1 = 0;
    }
    else {
      iStack_158 = 0x64000000;
      if (uVar7 == 0) {
        FUN_180097490(param_3,param_2,&iStack_158);
        iVar6 = iStack_158;
      }
      else {
        uStack_154 = param_3[9];
        lVar4 = *(longlong *)(param_3 + (ulonglong)uVar7 * 2 + 10);
        iStack_158 = 0;
        FUN_180097a60(param_2,lVar4,param_3[5]);
        *(undefined4 *)(lVar4 + 0x114) = 0;
        *(uint *)(lVar4 + 0x104) = uStack_154;
        uVar7 = param_3[7];
        *(undefined8 *)(lVar4 + 0x120) = 0;
        *(uint *)(lVar4 + 0x11c) = uVar7;
        piStack_168 = &iStack_158;
        *(undefined8 *)(lVar4 + 0x140) = 0;
        param_3[7] = param_3[7] + 1;
        FUN_1800976f0(param_3,lVar4,auStack_128,auStack_118);
        if (iStack_158 < 1) {
          iVar6 = 0x64000064;
        }
        else {
          iStack_14c = iStack_158;
          uStack_150 = uStack_154;
          puStack_148 = auStack_118;
          puStack_140 = auStack_128;
          uStack_138 = 0xcd;
          iStack_134 = 0x64000000;
          iStack_130 = uVar3 * uVar2;
          FUN_180097fa0(param_3,lVar4,&uStack_150);
          iVar6 = (iStack_130 * 100) / (int)(uVar3 * uVar2 + 1) + iStack_134;
        }
      }
      if (param_3[7] != 0) {
        do {
          param_3[uVar8 + 0x21fa] = (uint)uVar8;
          uVar7 = (uint)uVar8 + 1;
          uVar8 = (ulonglong)uVar7;
        } while (uVar7 < param_3[7]);
      }
      lVar4 = (longlong)(int)param_3[7];
      if (lVar4 < (int)uVar1) {
        puVar9 = param_3 + lVar4 + 0x21fa;
        for (lVar5 = (int)uVar1 - lVar4; lVar5 != 0; lVar5 = lVar5 + -1) {
          *puVar9 = 0xffffffff;
          puVar9 = puVar9 + 1;
        }
      }
      *param_1 = iVar6;
      if (param_3[7] == param_3[8]) {
        FUN_1800c11d0(param_3,0);
        FUN_1800a26d0(param_3);
      }
    }
  }
  else {
    *param_1 = 0;
  }
  FUN_180086a70(uStack_48 ^ (ulonglong)auStack_188);
  return;
}

