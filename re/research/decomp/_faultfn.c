
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1800ad970(undefined4 *param_1,undefined4 *param_2,undefined8 *param_3,uint *param_4)

{
  longlong lVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  longlong lVar8;
  undefined8 uVar9;
  int iVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  undefined8 uStackX_10;
  int aiStackX_18 [4];
  undefined *puStack_40;
  
  puStack_40 = &UNK_1800ad98a;
  lVar8 = FUN_180087740();
  lVar8 = -lVar8;
  *(ulonglong *)(&stack0x00004ce8 + lVar8) =
       _DAT_18012a308 ^ (ulonglong)(&stack0xffffffffffffffc8 + lVar8);
  uVar11 = *(undefined8 *)(&stack0x00004d60 + lVar8);
  lVar1 = *(longlong *)(&stack0x00004d68 + lVar8);
  uVar2 = *(undefined8 *)(&stack0x00004d70 + lVar8);
  iVar7 = param_2[6];
  *(undefined8 *)(&stack0x00000048 + lVar8) = *(undefined8 *)(&stack0x00004d78 + lVar8);
  *(undefined8 *)(&stack0x00000038 + lVar8) = *(undefined8 *)(&stack0x00004d80 + lVar8);
  *(undefined8 *)(&stack0x00000040 + lVar8) = *(undefined8 *)(&stack0x00004d90 + lVar8);
  uVar6 = param_2[2];
  *(undefined4 *)((longlong)aiStackX_18 + lVar8 + 0xc) = *param_1;
  uVar12 = param_2[1];
  *(undefined8 *)(&stack0x00000028 + lVar8) = uVar11;
  *(undefined4 *)((longlong)aiStackX_18 + lVar8 + 4) = uVar12;
  uVar12 = 0;
  *(undefined4 *)((longlong)aiStackX_18 + lVar8) = *param_2;
  uVar9 = *param_3;
  *(undefined4 *)((longlong)aiStackX_18 + lVar8 + 8) = uVar6;
  *(undefined8 *)((longlong)&uStackX_10 + lVar8) = uVar9;
  *(undefined **)((longlong)&puStack_40 + lVar8) = &UNK_1800ada1e;
  uVar9 = FUN_1800822b0();
  uVar5 = param_4[0x9921];
  *(undefined4 *)(&stack0xfffffffffffffff8 + lVar8) = *(undefined4 *)(&stack0x00004d58 + lVar8);
  *(undefined8 *)(&stack0xfffffffffffffff0 + lVar8) = uVar9;
  *(undefined8 *)(&stack0x00000030 + lVar8) = uVar9;
  *(undefined4 *)(&stack0x00000008 + lVar8) = 0;
  *(undefined4 **)(&stack0xffffffffffffffe8 + lVar8) = param_2;
  *(undefined **)((longlong)&puStack_40 + lVar8) = &UNK_1800ada57;
  uVar6 = FUN_1800ae6a0(*(undefined8 *)((longlong)&uStackX_10 + lVar8),uVar11,(short)uVar5,
                        &stack0x00000008 + lVar8);
  *(undefined4 *)(&stack0x0000000c + lVar8) = uVar6;
  if (*(int *)(&stack0x00000008 + lVar8) == 1) {
    uVar11 = *(undefined8 *)(&stack0x00000030 + lVar8);
  }
  else {
    uVar11 = *(undefined8 *)(lVar1 + 0x18);
  }
  switch(iVar7) {
  case 0:
  case 2:
  case 0x3e:
    iVar10 = 0x32;
    break;
  default:
    iVar10 = 0x46;
    break;
  case 6:
  case 7:
  case 9:
  case 10:
    iVar10 = 0x38;
  }
  if ((*param_4 < 100) && (*(int *)((longlong)aiStackX_18 + lVar8 + 0xc) == 1)) {
    if ((iVar7 == 8) || ((iVar7 < 6 || (10 < iVar7)))) {
      iVar10 = iVar10 + -0xf;
    }
    else {
      iVar10 = iVar10 + -10;
    }
  }
  if (param_4[0x9921] == 1) {
    uVar9 = *(undefined8 *)(&stack0x00000028 + lVar8);
    *(undefined4 *)(&stack0xfffffffffffffff0 + lVar8) = *(undefined4 *)(&stack0x00004d58 + lVar8);
    *(undefined8 *)(&stack0xffffffffffffffe8 + lVar8) = 0;
    *(undefined **)((longlong)&puStack_40 + lVar8) = &UNK_1800adaf9;
    FUN_1800ad790(*(undefined8 *)((longlong)&uStackX_10 + lVar8),&stack0x00000058 + lVar8,param_2,
                  uVar9);
  }
  else {
    uVar9 = *(undefined8 *)(&stack0x00000028 + lVar8);
    *(undefined **)((longlong)&puStack_40 + lVar8) = &UNK_1800adb13;
    FUN_1800ae0c0(*(undefined8 *)((longlong)&uStackX_10 + lVar8),uVar9,&stack0x00000058 + lVar8,
                  iVar7);
  }
  *(undefined **)((longlong)&puStack_40 + lVar8) = &UNK_1800adb29;
  iVar7 = FUN_1800c45b0(uVar2,&stack0x00000058 + lVar8,uVar11,param_2);
  if (iVar10 < iVar7) {
    uVar5 = *param_4;
    uVar12 = 4;
    if ((uVar5 < 100) && (0x5a < *(int *)(&stack0x0000000c + lVar8))) {
      uVar3 = *(undefined8 *)(&stack0x00000048 + lVar8);
      uVar6 = *(undefined4 *)(&stack0x00004d88 + lVar8);
      uVar4 = *(undefined8 *)(&stack0x00000038 + lVar8);
      *(undefined8 *)(&stack0xfffffffffffffff8 + lVar8) = uVar9;
      *(undefined4 **)(&stack0xfffffffffffffff0 + lVar8) = param_2;
      *param_4 = 5;
      *(undefined8 *)(&stack0xffffffffffffffe8 + lVar8) = 0;
      *(undefined **)((longlong)&puStack_40 + lVar8) = &UNK_1800adb76;
      FUN_1800aff20(uVar4,param_4,uVar6,uVar3);
      *param_4 = uVar5;
    }
    if (0x28 < *(int *)(&stack0x0000000c + lVar8)) {
      uVar12 = 2;
    }
    uVar6 = *(undefined4 *)((longlong)aiStackX_18 + lVar8 + 8);
    *(undefined **)((longlong)&puStack_40 + lVar8) = &UNK_1800adb9e;
    FUN_1800abe60(param_4 + 0x72d9,uVar2,uVar6);
    uVar6 = *(undefined4 *)((longlong)aiStackX_18 + lVar8 + 8);
    *(undefined **)((longlong)&puStack_40 + lVar8) = &UNK_1800adbb2;
    FUN_1800abe60(param_4 + 0x85fd,uVar2,uVar6);
  }
  uVar6 = *(undefined4 *)((longlong)aiStackX_18 + lVar8 + 4);
  *(undefined4 *)(&stack0xfffffffffffffff0 + lVar8) = *(undefined4 *)(&stack0x00000008 + lVar8);
  *(undefined4 *)(&stack0xffffffffffffffe8 + lVar8) = uVar12;
  *(undefined **)((longlong)&puStack_40 + lVar8) = &UNK_1800adbd3;
  FUN_1800b9bc0(uVar2,uVar11,uVar6,*(undefined4 *)((longlong)aiStackX_18 + lVar8));
  uVar11 = *(undefined8 *)(&stack0x00000030 + lVar8);
  **(undefined4 **)(&stack0x00000040 + lVar8) = uVar12;
  *(undefined **)((longlong)&puStack_40 + lVar8) = &UNK_1800adbe4;
  FUN_180082260(uVar11);
  *(undefined **)((longlong)&puStack_40 + lVar8) = &UNK_1800adbf7;
  FUN_180086a70(*(ulonglong *)(&stack0x00004ce8 + lVar8) ^
                (ulonglong)(&stack0xffffffffffffffc8 + lVar8));
  return;
}

