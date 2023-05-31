
void FUN_004009aa(void)

{
  size_t __size;
  void *pvVar1;
  uint local_1c;
  
  local_1c = 0;
  while( true ) {
    if (8 < local_1c) {
      puts("You can\'t add new page anymore!");
      return;
    }
    if (*(long *)(&DAT_006020a0 + (ulong)local_1c * 8) == 0) break;
    local_1c = local_1c + 1;
  }
  printf("Size of page :");
  __size = FUN_004008cd();
  pvVar1 = malloc(__size);
  if (pvVar1 != (void *)0x0) {
    printf("Content :");
    FUN_00400856(pvVar1,__size & 0xffffffff);
    *(void **)(&DAT_006020a0 + (ulong)local_1c * 8) = pvVar1;
    *(size_t *)(&DAT_006020e0 + (ulong)local_1c * 8) = __size;
    DAT_00602040 = DAT_00602040 + 1;
    puts("Done !");
    return;
  }
  puts("Error !");
                    /* WARNING: Subroutine does not return */
  exit(0);
}

