// 18008ec20 identifytemplate

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void identifytemplate(longlong *param_1,undefined8 *param_2,undefined8 param_3,uint *param_4)

{
  longlong lVar1;
  longlong lVar2;
  uint uVar3;
  undefined8 *puVar4;
  undefined1 auStack_718 [32];
  undefined4 uStack_6f8;
  undefined1 *puStack_6f0;
  undefined8 uStack_6e8;
  undefined8 uStack_6e0;
  int aiStack_6d8 [4];
  undefined1 auStack_6c8 [1680];
  ulonglong uStack_38;
  
                    /* 0x8ec20  14  identifytemplate */
  uStack_38 = _DAT_18012a308 ^ (ulonglong)auStack_718;
  uVar3 = 0;
  aiStack_6d8[0] = 0;
  if ((((param_1 != (longlong *)0x0) && (param_2 != (undefined8 *)0x0)) && (param_4 != (uint *)0x0))
     && ((lVar1 = *param_1, lVar1 != 0 && (lVar2 = FUN_1800abe00(0x8e08), lVar2 != 0)))) {
    FUN_1800abe20(lVar2,*param_2,0x8e08);
    if (*(int *)(lVar2 + 0x1c) != 0) {
      puVar4 = (undefined8 *)(lVar2 + 0x28);
      do {
        uStack_6e0 = 0;
        puStack_6f0 = auStack_6c8;
        uStack_6e8 = 0;
        uStack_6f8 = 0;
        FUN_18009dab0(aiStack_6d8,*puVar4,lVar1,0);
        if (0 < aiStack_6d8[0]) {
          *param_4 = uVar3;
          goto code_r0x00018008ed15;
        }
        uVar3 = uVar3 + 1;
        puVar4 = puVar4 + 1;
      } while (uVar3 < *(uint *)(lVar2 + 0x1c));
    }
    *param_4 = 0xffffffff;
code_r0x00018008ed15:
    FUN_1800abdf0(lVar2);
  }
  FUN_180086a70(uStack_38 ^ (ulonglong)auStack_718);
  return;
}

