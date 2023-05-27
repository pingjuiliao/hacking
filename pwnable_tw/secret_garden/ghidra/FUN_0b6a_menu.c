
void FUN_00100b6a(void)

{
  long lVar1;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  puts("");
  puts(&DAT_00101328);
  puts(&DAT_00101378);
  puts(&DAT_00101328);
  puts("");
  puts("  1 . Raise a flower ");
  puts("  2 . Visit the garden ");
  puts("  3 . Remove a flower from the garden");
  puts("  4 . Clean the garden");
  puts("  5 . Leave the garden");
  puts("");
  __printf_chk(1,"Your choice : ");
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

