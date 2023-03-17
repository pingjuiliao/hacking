
void delete(void)

{
  int iVar1;
  int iVar2;
  int in_GS_OFFSET;
  int local_3c;
  undefined4 *local_38;
  char local_26 [22];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_3c = 1;
  local_38 = myCart._8_4_;
  printf("Item Number> ");
  fflush(stdout);
  my_read(local_26,0x15);
  iVar2 = atoi(local_26);
  do {
    if (local_38 == (undefined4 *)0x0) {
LAB_08048a5e:
      if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      return;
    }
    if (local_3c == iVar2) {
      iVar2 = local_38[2];
      iVar1 = local_38[3];
      if (iVar1 != 0) {
        *(int *)(iVar1 + 8) = iVar2;
      }
      if (iVar2 != 0) {
        *(int *)(iVar2 + 0xc) = iVar1;
      }
      printf("Remove %d:%s from your shopping cart.\n",local_3c,*local_38);
      goto LAB_08048a5e;
    }
    local_3c = local_3c + 1;
    local_38 = (undefined4 *)local_38[2];
  } while( true );
}

