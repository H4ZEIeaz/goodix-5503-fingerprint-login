
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_18009dab0(int *param_1,longlong param_2,uint *param_3,undefined4 param_4,undefined4 param_5
                  ,longlong param_6,longlong param_7,longlong param_8)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_d8 [32];
  longlong lStack_b8;
  longlong lStack_b0;
  undefined1 auStack_a8 [68];
  undefined4 uStack_64;
  undefined8 uStack_58;
  undefined8 uStack_50;
  undefined8 uStack_48;
  ulonglong uStack_40;
  
  uStack_40 = _DAT_18012a308 ^ (ulonglong)auStack_d8;
  iVar1 = FUN_1800a0390(param_3,auStack_a8,param_4,param_5);
  uStack_64 = *(undefined4 *)(param_2 + 0x148);
  if (iVar1 == 0) {
    uVar2 = *param_3;
    if (uVar2 - 9 < 2) {
      lStack_b0 = param_8;
      lStack_b8 = param_6;
      FUN_18009f4a0(param_1,param_2,param_3,auStack_a8);
      *(undefined4 *)(param_6 + 0x68c) = param_4;
    }
    else if ((uVar2 < 0x40) && ((0xc0000000000000cdU >> ((longlong)(int)uVar2 & 0x3fU) & 1) != 0)) {
      uVar2 = 0;
      if (param_3[7] != 0) {
        do {
          if (*(int *)(*(longlong *)(param_3 + (ulonglong)uVar2 * 2 + 10) + 0x114) == 5) {
            *(undefined4 *)(*(longlong *)(param_3 + (ulonglong)uVar2 * 2 + 10) + 0x114) = 0;
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < param_3[7]);
      }
      uStack_50 = _UNK_1800f0fc8;
      uStack_58 = _UNK_1800f0fc0;
      *(undefined4 *)(param_6 + 0x68c) = param_4;
      uStack_48 = 0x100;
      if (param_7 != 0) {
        FUN_1800abe60(param_7 + 0xc,&uStack_58,0x18);
        *(undefined4 *)(param_7 + 8) = 0;
      }
      lStack_b0 = param_7;
      lStack_b8 = param_6;
      FUN_18009ca40(param_1,param_2,param_3,auStack_a8);
      if ((0 < *param_1) && (param_7 != 0)) {
        *(undefined4 *)(param_7 + 8) = 0;
      }
    }
  }
  FUN_180086a70(uStack_40 ^ (ulonglong)auStack_d8);
  return;
}

