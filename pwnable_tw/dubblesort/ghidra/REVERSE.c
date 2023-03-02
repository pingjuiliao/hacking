
/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

uint32_t main(void)

{
  uint32_t uVar1;
  uint uVar2;
  uint32_t *puVar3;
  int in_GS_OFFSET;
  uint local_78;
  uint32_t number_array[8];  // -0x7c(%ebp)
  undefined name_buffer[64]; // -0x5c(%ebp)
  int canary;
  
  canary = *(int *)(in_GS_OFFSET + 0x14);
  FUN_000108b5();
  __printf_chk(1,"What your name :");
  read(0,name_buffer,0x40);
  __printf_chk(1,"Hello %s,How many numbers do you what to sort :",name_buffer);
  __isoc99_scanf("%u",&local_78);
  if (local_78 != 0) {
    puVar3 = number_array;
    uVar2 = 0;
    do {
      __printf_chk(1,"Enter the %d number : ",uVar2);
      fflush(stdout);
      __isoc99_scanf("%u",puVar3);
      uVar2 = uVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar2 < local_78);
  }
  // sorting
  FUN_00010931(number_array,local_78);
  puts("Result :");
  if (local_78 != 0) {
    uVar2 = 0;
    do {
      __printf_chk(1,&DAT_00010c1d,number_array[uVar2]);
      uVar2 = uVar2 + 1;
    } while (uVar2 < local_78);
  }
  uVar1 = 0;
  if (canary != *(int *)(in_GS_OFFSET + 0x14)) {
    uVar1 = FUN_00010ba0();
  }
  return uVar1;
}

