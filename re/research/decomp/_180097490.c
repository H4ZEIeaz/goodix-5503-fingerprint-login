
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_180097490(longlong param_1,undefined8 param_2,int *param_3)

{
  longlong lVar1;
  longlong lVar2;
  undefined8 uVar3;
  undefined1 auStack_58 [32];
  undefined8 uStack_38;
  undefined8 uStack_30;
  undefined8 uStack_28;
  ulonglong uStack_20;
  
  uStack_20 = _DAT_18012a308 ^ (ulonglong)auStack_58;
  uStack_28 = 0x100;
  uStack_38 = _UNK_1800f0fc0;
  uStack_30 = _UNK_1800f0fc8;
  lVar1 = *(longlong *)(param_1 + 0x28 + (ulonglong)*(uint *)(param_1 + 0x1c) * 8);
  FUN_180097a60(param_2,lVar1,*(undefined4 *)(param_1 + 0x14));
  *(undefined4 *)((ulonglong)*(uint *)(param_1 + 0x24) * 0x1c + 0x1b8 + param_1) = 0xffffffff;
  FUN_1800abe60((ulonglong)*(uint *)(param_1 + 0x24) * 0x1c + 0x1bc + param_1,&uStack_38,0x18);
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  *(undefined4 *)(*(longlong *)(param_1 + 0x28 + (ulonglong)*(uint *)(param_1 + 0x1c) * 8) + 0x108)
       = *(undefined4 *)(lVar1 + 0x108);
  *(undefined4 *)(*(longlong *)(param_1 + 0x28 + (ulonglong)*(uint *)(param_1 + 0x1c) * 8) + 0x10c)
       = *(undefined4 *)(lVar1 + 0x10c);
  *(undefined4 *)(*(longlong *)(param_1 + 0x28 + (ulonglong)*(uint *)(param_1 + 0x1c) * 8) + 0x114)
       = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x28 + (ulonglong)*(uint *)(param_1 + 0x1c) * 8) + 0x11c)
       = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x28 + (ulonglong)*(uint *)(param_1 + 0x1c) * 8) + 0x120)
       = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x28 + (ulonglong)*(uint *)(param_1 + 0x1c) * 8) + 0x124)
       = 0;
  *(undefined8 *)(*(longlong *)(param_1 + 0x28 + (ulonglong)*(uint *)(param_1 + 0x1c) * 8) + 0x140)
       = 0;
  *(undefined4 *)(*(longlong *)(param_1 + 0x28 + (ulonglong)*(uint *)(param_1 + 0x1c) * 8) + 0x14c)
       = *(undefined4 *)(lVar1 + 0x14c);
  lVar2 = *(longlong *)(param_1 + 0x28 + (ulonglong)*(uint *)(param_1 + 0x1c) * 8);
  uVar3 = *(undefined8 *)(lVar1 + 0x168);
  *(undefined8 *)(lVar2 + 0x160) = *(undefined8 *)(lVar1 + 0x160);
  *(undefined8 *)(lVar2 + 0x168) = uVar3;
  *(undefined8 *)(lVar2 + 0x170) = *(undefined8 *)(lVar1 + 0x170);
  *(undefined4 *)(lVar2 + 0x178) = *(undefined4 *)(lVar1 + 0x178);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  *param_3 = *param_3 + 100;
  FUN_180086a70(uStack_20 ^ (ulonglong)auStack_58);
  return;
}

