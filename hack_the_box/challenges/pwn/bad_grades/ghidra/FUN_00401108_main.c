
undefined8 FUN_00401108(void)

{
  long in_FS_OFFSET;
  int local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00400ea6();
  printf("Your grades this semester were really ");
  FUN_00400acb(&DAT_004013d7,"green","deleted");
  FUN_00400acb(" BAD!\n",&DAT_004012ba,"blink");
  printf("\n1. View current grades.\n2. Add new.\n> ");
  __isoc99_scanf(&DAT_0040137e,&local_14);
  if (local_14 == 1) {
    FUN_00400f1a();
  }
  else {
    if (local_14 != 2) {
      puts("Invalid option!\nExiting..");
                    /* WARNING: Subroutine does not return */
      exit(9);
    }
    FUN_00400fd5();
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}

