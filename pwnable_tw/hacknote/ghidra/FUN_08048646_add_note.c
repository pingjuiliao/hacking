
void FUN_08048646(void)

{
  int iVar1;
  void *pvVar2;
  size_t __size;
  int in_GS_OFFSET;
  int local_20;
  char local_18 [8];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  if (DAT_0804a04c < 6) {
    for (local_20 = 0; local_20 < 5; local_20 = local_20 + 1) {
      if (*(int *)(&DAT_0804a050 + local_20 * 4) == 0) {
        pvVar2 = malloc(8);
        *(void **)(&DAT_0804a050 + local_20 * 4) = pvVar2;
        if (*(int *)(&DAT_0804a050 + local_20 * 4) == 0) {
          puts("Alloca Error");
                    /* WARNING: Subroutine does not return */
          exit(-1);
        }
        **(code ***)(&DAT_0804a050 + local_20 * 4) = FUN_0804862b;
        printf("Note size :");
        read(0,local_18,8);
        __size = atoi(local_18);
        iVar1 = *(int *)(&DAT_0804a050 + local_20 * 4);
        pvVar2 = malloc(__size);
        *(void **)(iVar1 + 4) = pvVar2;
        if (*(int *)(*(int *)(&DAT_0804a050 + local_20 * 4) + 4) == 0) {
          puts("Alloca Error");
                    /* WARNING: Subroutine does not return */
          exit(-1);
        }
        printf("Content :");
        read(0,*(void **)(*(int *)(&DAT_0804a050 + local_20 * 4) + 4),__size);
        puts("Success !");
        DAT_0804a04c = DAT_0804a04c + 1;
        break;
      }
    }
  }
  else {
    puts("Full");
  }
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

