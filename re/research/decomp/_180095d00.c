
undefined8 FUN_180095d00(void)

{
  undefined8 uVar1;
  uint *in_stack_00000030;
  
  if ((*in_stack_00000030 < 9) && ((0x132U >> (*in_stack_00000030 & 0x1f) & 1) != 0)) {
    return 0x80000003;
  }
  uVar1 = FUN_180095320();
  return uVar1;
}

