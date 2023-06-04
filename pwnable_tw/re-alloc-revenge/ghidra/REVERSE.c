
void allocate(void)
{
  ulong uVar1;
  ulong __size;
  void *pvVar2;
  long lVar3;
  
  printf("Index:");
  uVar1 = read_long();
  if ((uVar1 < 2) && (*(long *)(heap + uVar1 * 8) == 0)) {
    printf("Size:");
    __size = read_long();
    if (__size < 0x79) {
      // NOTE: different from re-alloc challeng
      pvVar2 = malloc(__size);
      if (pvVar2 == (void *)0x0) {
        puts("alloc error");
      }
      else {
        *(void **)(heap + uVar1 * 8) = pvVar2;
        printf("Data:");
        lVar3 = read_input(*(undefined8 *)(heap + uVar1 * 8),__size & 0xffffffff);
        *(undefined *)(lVar3 + *(long *)(heap + uVar1 * 8)) = 0;
      }
    }
    else {
      puts("Too large!");
    }
  }
  else {
    puts("Invalid !");
  }
  return;
}

void reallocate(void)
{
  ulong uVar1;
  ulong __size;
  void *pvVar2;
  
  printf("Index:");
  uVar1 = read_long();
  if ((uVar1 < 2) && (*(long *)(heap + uVar1 * 8) != 0)) {
    printf("Size:");
    __size = read_long();
    if (__size < 0x79) {
      pvVar2 = realloc(*(void **)(heap + uVar1 * 8),__size);
      if (pvVar2 == (void *)0x0) {
        puts("alloc error");
      }
      else {
        *(void **)(heap + uVar1 * 8) = pvVar2;
        printf("Data:");
        read_input(*(undefined8 *)(heap + uVar1 * 8),__size & 0xffffffff);
      }
    }
    else {
      puts("Too large!");
    }
  }
  else {
    puts("Invalid !");
  }
  return;
}


void rfree(void)
{
  ulong uVar1;
  
  printf("Index:");
  uVar1 = read_long();
  if (uVar1 < 2) {
    realloc(*(void **)(heap + uVar1 * 8),0);
    *(undefined8 *)(heap + uVar1 * 8) = 0;
  }
  else {
    puts("Invalid !");
  }
  return;
}


void main(void)
{
  long in_FS_OFFSET;
  int local_14;
  undefined8 local_10;
  
  local_10 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  local_14 = 0;
  init_proc();
  do {
    while( true ) {
      while( true ) {
        menu();
        __isoc99_scanf(&DAT_0010212f,&local_14);
        if (local_14 != 2) break;
        reallocate();
      }
      if (2 < local_14) break;
      if (local_14 == 1) {
        allocate();
      }
      else {
LAB_00101790:
        puts("Invalid Choice");
      }
    }
    if (local_14 != 3) {
      if (local_14 == 4) {
                    /* WARNING: Subroutine does not return */
        _exit(0);
      }
      goto LAB_00101790;
    }
    rfree();
  } while( true );
}


void menu(void)
{
  puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
  puts(&DAT_00102070);
  puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$$");
  puts("$   1. Alloc               $");
  puts("$   2. Realloc             $");
  puts("$   3. Free                $");
  puts("$   4. Exit                $");
  puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$");
  printf("Your choice: ");
  return;
}


long read_input(long param_1,undefined4 param_2)
{
  int iVar1;
  long lVar2;
  
  iVar1 = __read_chk(0,param_1,param_2,param_2);
  lVar2 = (long)iVar1;
  if (lVar2 == 0) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  if (*(char *)(param_1 + lVar2 + -1) == '\n') {
    *(undefined *)(param_1 + lVar2 + -1) = 0;
  }
  return lVar2;
}


longlong read_long(void)

{
  longlong lVar1;
  long in_FS_OFFSET;
  char local_28 [24];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  __read_chk(0,local_28,0x10,0x11);
  lVar1 = atoll(local_28);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return lVar1;
}


void handler(void)
{
  puts("Timeout");
                    /* WARNING: Subroutine does not return */
  _exit(1);
}


void init_proc(void)
{
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stderr,(char *)0x0,2,0);
  signal(0xe,handler);
  alarm(0x3c);
  return;
}


