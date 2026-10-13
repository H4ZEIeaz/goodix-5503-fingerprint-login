
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_180090690(longlong *param_1,uint param_2,ulonglong param_3)

{
  undefined8 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint *puVar4;
  longlong lVar5;
  undefined8 uVar6;
  longlong lVar7;
  longlong *plVar8;
  int iVar9;
  longlong lVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  int iStackX_18;
  
  uVar18 = (int)param_3 >> 3 & 0x3f;
  uVar11 = (int)param_3 >> 0xe & 0x1ff;
  uVar12 = (uint)(param_3 >> 0x17) & 0x1ff;
  puVar4 = (uint *)FUN_1800822b0(0x8e08);
  iVar17 = 0;
  if (uVar18 == 0x14) {
    uVar18 = 0;
  }
  *param_1 = (longlong)puVar4;
  if (puVar4 == (uint *)0x0) {
    return 0x80000004;
  }
  iVar3 = 0xa0;
  uVar13 = 0;
  uVar16 = 0x32;
  iStackX_18 = 0xa0;
  uVar14 = 0;
  uVar15 = 0;
  switch(uVar18) {
  case 0:
    uVar14 = 1;
    uVar16 = 0x28;
    uVar15 = 1;
    iVar3 = 0x96;
    iStackX_18 = 0x96;
    if (uVar12 == 0x6c) {
      uVar12 = 0x68;
    }
    break;
  case 2:
    iVar3 = 0x96;
    iStackX_18 = 0x96;
    uVar16 = 0x1e;
    goto code_r0x000180090813;
  case 3:
    uVar16 = 0xf;
    iVar3 = 0x96;
    iStackX_18 = 0x96;
    goto code_r0x000180090813;
  case 4:
    uVar16 = 0x28;
    iVar3 = 0x96;
    iStackX_18 = 0x96;
    uVar14 = uVar13;
    uVar15 = 0;
    break;
  case 6:
  case 7:
  case 0x3e:
    iVar3 = 0x96;
    iStackX_18 = 0x96;
    uVar16 = 0x28;
    goto code_r0x000180090813;
  case 9:
    iVar3 = 0x96;
    iStackX_18 = 0x96;
    uVar16 = 0x2d;
    uVar14 = uVar13;
    uVar15 = 1;
    break;
  case 10:
    iVar3 = 0x78;
    iStackX_18 = 0x78;
    uVar14 = uVar13;
    uVar15 = 1;
    break;
  case 0x3f:
    iVar3 = 0x8c;
    iStackX_18 = 0x8c;
    uVar16 = 0x32;
    if (uVar12 == 0x76) {
      uVar12 = 0x78;
    }
code_r0x000180090813:
    uVar14 = 1;
    uVar15 = 1;
  }
  *puVar4 = uVar18;
  *(uint *)(*param_1 + 4) = uVar12;
  if (param_2 < uVar16) {
    uVar16 = param_2;
  }
  *(uint *)(*param_1 + 8) = uVar11;
  *(undefined4 *)(*param_1 + 0xc) = uVar14;
  *(undefined4 *)(*param_1 + 0x10) = uVar15;
  *(int *)(*param_1 + 0x14) = iVar3;
  *(int *)(*param_1 + 0x18) = iVar3;
  *(undefined4 *)(*param_1 + 0x1c) = 0;
  *(uint *)(*param_1 + 0x20) = uVar16;
  *(undefined4 *)(*param_1 + 0x24) = 0;
  lVar5 = *param_1;
  if (*(int *)(lVar5 + 0xc) != 0) {
    uVar12 = uVar12 >> 1;
    uVar11 = uVar11 >> 1;
  }
  uVar16 = uVar12 >> 3;
  if (uVar12 != uVar16 * 8) {
    uVar16 = uVar16 + 1;
  }
  iVar9 = iVar3;
  if (0 < *(int *)(lVar5 + 0x20)) {
    plVar8 = (longlong *)(lVar5 + 0x28);
    do {
      lVar5 = FUN_1800822b0(0x180);
      *plVar8 = lVar5;
      FUN_1800abeb0(lVar5,0,0x180);
      uVar6 = FUN_1800ac0e0(uVar12,uVar11,8);
      *(undefined8 *)(*plVar8 + 8) = uVar6;
      uVar6 = FUN_1800ac0e0(uVar12,uVar11,8);
      *(undefined8 *)(*plVar8 + 0x10) = uVar6;
      if ((longlong)(int)uVar18 - 9U < 2) {
        *(undefined8 *)(*plVar8 + 0x18) = 0;
      }
      else {
        uVar6 = FUN_1800ac0e0(uVar12,uVar11,8);
        *(undefined8 *)(*plVar8 + 0x18) = uVar6;
      }
      uVar6 = FUN_1800822b0(iVar3 * 0x38);
      *(undefined8 *)(*plVar8 + 0xf8) = uVar6;
      uVar6 = FUN_1800ac0e0(uVar16,uVar11,1);
      iVar17 = iVar17 + 1;
      *(undefined8 *)(*plVar8 + 0x130) = uVar6;
      *(undefined8 *)(*plVar8 + 0x20) = 0;
      *(undefined8 *)(*plVar8 + 0x140) = 0;
      *(undefined4 *)(*plVar8 + 0x14c) = 0;
      *(undefined4 *)(*plVar8 + 0x150) = 0;
      *(undefined8 *)(*plVar8 + 0x158) = 0;
      plVar8 = plVar8 + 1;
      iVar9 = iStackX_18;
    } while (iVar17 < *(int *)(*param_1 + 0x20));
  }
  lVar5 = *param_1;
  FUN_1800abeb0(lVar5 + 0x8db0,0xffffffff,0x50);
  FUN_1800abeb0(*param_1 + 0x8e00,0,8);
  lVar7 = 0;
  lVar10 = 0x14;
  plVar8 = (longlong *)(lVar5 + 0x8d10);
  do {
    lVar5 = FUN_1800822b0(0x180);
    *plVar8 = lVar5;
    FUN_1800abeb0(lVar5,0,0x180);
    uVar6 = FUN_1800ac0e0(uVar12,uVar11,8);
    *(undefined8 *)(*plVar8 + 8) = uVar6;
    uVar6 = FUN_1800ac0e0(uVar12,uVar11,8);
    *(undefined8 *)(*plVar8 + 0x10) = uVar6;
    if ((longlong)(int)uVar18 - 9U < 2) {
      *(undefined8 *)(*plVar8 + 0x18) = 0;
    }
    else {
      uVar6 = FUN_1800ac0e0(uVar12,uVar11,8);
      *(undefined8 *)(*plVar8 + 0x18) = uVar6;
    }
    uVar6 = FUN_1800822b0(iVar9 * 0x38);
    *(undefined8 *)(*plVar8 + 0xf8) = uVar6;
    uVar6 = FUN_1800ac0e0(uVar16,uVar11,1);
    *(undefined8 *)(*plVar8 + 0x130) = uVar6;
    *(undefined8 *)(*plVar8 + 0x20) = 0;
    *(undefined8 *)(*plVar8 + 0x140) = 0;
    *(undefined4 *)(*plVar8 + 0x14c) = 0;
    *(undefined4 *)(*plVar8 + 0x150) = 0;
    *(undefined8 *)(*plVar8 + 0x158) = 0;
    lVar10 = lVar10 + -1;
    plVar8 = plVar8 + 1;
  } while (lVar10 != 0);
  do {
    uVar6 = CONCAT44(_UNK_1800f0b6c,_UNK_1800f0b68);
    lVar5 = *param_1;
    lVar7 = lVar7 + 0x38;
    puVar1 = (undefined8 *)(lVar5 + 0x180 + lVar7);
    *puVar1 = CONCAT44(_UNK_1800f0b64,_UNK_1800f0b60);
    puVar1[1] = uVar6;
    *(undefined8 *)(lVar5 + 400 + lVar7) = _UNK_1800f0b70;
    *(undefined4 *)(lVar5 + 0x198 + lVar7) = _UNK_1800f0b78;
    uVar13 = _UNK_1800f0b6c;
    uVar15 = _UNK_1800f0b68;
    uVar14 = _UNK_1800f0b64;
    lVar5 = *param_1;
    puVar2 = (undefined4 *)(lVar5 + 0x19c + lVar7);
    *puVar2 = _UNK_1800f0b60;
    puVar2[1] = uVar14;
    puVar2[2] = uVar15;
    puVar2[3] = uVar13;
    *(undefined8 *)(lVar5 + 0x1ac + lVar7) = _UNK_1800f0b70;
    *(undefined4 *)(lVar5 + 0x1b4 + lVar7) = _UNK_1800f0b78;
  } while (lVar7 < 0x8618);
  puVar4[0x21f4] = 0;
  puVar4[0x21f5] = 0;
  puVar4[0x21f6] = 0xffffffff;
  puVar4[0x21f7] = 0xffffffff;
  puVar4[0x21f8] = 0xffffffff;
  puVar4[0x21f9] = 0;
  FUN_1800abeb0(*param_1 + 0x87e8,0xffffffff,200);
  *(undefined4 *)(*param_1 + 0x88b0) = 0xffffffff;
  FUN_1800abef0(*param_1 + 0x88b4,&UNK_1800f0f80);
  FUN_1800abef0(*param_1 + 0x88f4,&UNK_1800fad21);
  *(undefined4 *)(*param_1 + 0x8cf4) = 0;
  *(undefined4 *)(*param_1 + 0x8cf8) = 0;
  *(undefined4 *)(*param_1 + 0x8cfc) = 0;
  *(undefined8 *)(*param_1 + 0x8d08) = 0;
  return 0;
}

