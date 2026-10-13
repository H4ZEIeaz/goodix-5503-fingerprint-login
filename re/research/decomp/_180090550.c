
undefined8 FUN_180090550(longlong *param_1)

{
  longlong lVar1;
  
  if ((param_1 != (longlong *)0x0) && (lVar1 = *param_1, lVar1 != 0)) {
    if (*(longlong *)(lVar1 + 8) != 0) {
      FUN_1800acaf0(lVar1 + 8);
    }
    *(undefined8 *)(*param_1 + 8) = 0;
    if (*(longlong *)(*param_1 + 0x10) != 0) {
      FUN_1800acaf0();
    }
    *(undefined8 *)(*param_1 + 0x10) = 0;
    if (*(longlong *)(*param_1 + 0x18) != 0) {
      FUN_1800acaf0();
    }
    *(undefined8 *)(*param_1 + 0x18) = 0;
    if (*(longlong *)(*param_1 + 0x20) != 0) {
      FUN_1800acaf0();
    }
    *(undefined8 *)(*param_1 + 0x20) = 0;
    if (*(longlong *)(*param_1 + 0xf8) != 0) {
      FUN_180082260();
    }
    *(undefined8 *)(*param_1 + 0xf8) = 0;
    if (*(longlong *)(*param_1 + 0x130) != 0) {
      FUN_1800acaf0();
    }
    *(undefined8 *)(*param_1 + 0x130) = 0;
    if (*(longlong *)(*param_1 + 0x158) != 0) {
      FUN_1800acaf0();
    }
    *(undefined8 *)(*param_1 + 0x158) = 0;
    FUN_180082260(*param_1);
    *param_1 = 0;
    return 0;
  }
  return 0x80000002;
}

