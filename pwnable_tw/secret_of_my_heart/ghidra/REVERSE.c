struct Secret {
  size_t secret_size;
  char name[0x20];
  char* secret;
};

void add_secret(void)
{
  int iVar1;
  int index;
  
  index = 0;
  while( true ) {
    if (99 < index) {
      puts("Fulled !!");
      return;
    }
    if (*(long *)((long)index * 0x30 + DAT_00302018 + 0x28) == 0) break;
    index = index + 1;
  }
  printf("Size of heart : ");
  iVar1 = read_int();
  if (0x100 < (ulong)(long)iVar1) {
    puts("Too big !");
    return;
  }
  // allocate(DAT_00302018 + (long)index * 0x30,(long)iVar1);
  { 
    int iVar1;
    void *pvVar2;
  
    *param_1 = param_2;
    printf("Name of heart :");
    read_input(param_1 + 1,0x20);
    pvVar2 = malloc(param_2);
    param_1[5] = (size_t)pvVar2;
    if (param_1[5] == 0) {
      puts("Allocate Error !");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    printf("secret of my heart :");
    iVar1 = read_input(param_1[5],param_2 & 0xffffffff);
    *(undefined *)((long)iVar1 + param_1[5]) = 0;
  }
  puts("Done !");
  return;
}



void delete_secret(void)
{
  uint uVar1;
  
  printf("Index :");
  uVar1 = read_int();
  if (99 < uVar1) {
    puts("Out of bound !");
                    /* WARNING: Subroutine does not return */
    exit(-2);
  }
  if (*(long *)((ulong)uVar1 * 0x30 + DAT_00302018 + 0x28) == 0) {
    puts("No such heap !");
  }
  else {
    // free_and_clear((ulong)uVar1 * 0x30 + DAT_00302018);
    {
      param_1.secret_size = 0;
      memset(param_1.name,0,0x20);
      free(param_1.secret);
      param_1.secret = 0;
      return;
    }
    puts("Done !");
  }
  return;
}


void show_secret(void)
{
  uint uVar1;
  
  printf("Index :");
  uVar1 = read_int();
  if (99 < uVar1) {
    puts("Out of bound !");
                    /* WARNING: Subroutine does not return */
    exit(-2);
  }
  if (*(long *)((ulong)uVar1 * 0x30 + DAT_00302018 + 0x28) == 0) {
    puts("No such heap !");
  }
  else {
    printf("Index : %d\n",(ulong)uVar1);
    printf("Size : %lu\n",*(undefined8 *)((ulong)uVar1 * 0x30 + DAT_00302018));
    printf("Name : %s\n",(ulong)uVar1 * 0x30 + DAT_00302018 + 8);
    printf("Secret : %s\n",*(undefined8 *)((ulong)uVar1 * 0x30 + DAT_00302018 + 0x28));
  }
  return;
}


void main(void)
{
  int iVar1;
  
  setup();
  do {
    while( true ) {
      while( true ) {
        menu();
        iVar1 = read_int();
        if (iVar1 != 3) break;
        delete_secret();
      }
      if (3 < iVar1) break;
      if (iVar1 == 1) {
        add_secret();
      }
      else if (iVar1 == 2) {
        show_secret();
      }
      else {
LAB_0010120f:
        puts("Invalid choice");
      }
    }
    if (iVar1 == 4) {
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    if (iVar1 != 0x1305) goto LAB_0010120f;
    show_mmap_region();
  } while( true );
}


int read_int(void)
{
  int iVar1;
  long in_FS_OFFSET;
  char local_28 [24];
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  iVar1 = __read_chk(0,local_28,0xf,0xf);
  if (iVar1 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  iVar1 = atoi(local_28);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}



void show_mmap_region(void)
{
  printf("Your secret : %p\n",DAT_00302018);
  puts("Good bye ~");
                    /* WARNING: Subroutine does not return */
  exit(0);
}

void menu(void)
{
  puts("==================================");
  puts("        Secret of my heart        ");
  puts("==================================");
  puts(" 1. Add a secret                  ");
  puts(" 2. show a secret                 ");
  puts(" 3. delete a secret               ");
  puts(" 4. Exit                          ");
  puts("==================================");
  printf("Your choice :");
  return;
}

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void setup(void)
{
  time_t tVar1;
  uint local_c;
  
  local_c = 0;
  setvbuf(_stdout,(char *)0x0,2,0);
  setvbuf(_stdin,(char *)0x0,2,0);
  tVar1 = time((time_t *)0x0);
  srand((uint)tVar1);
  for (; (int)local_c < 0x10001; local_c = local_c & 0xfffff000) {
    local_c = rand();
  }
  DAT_00302018 = mmap((void *)(long)(int)local_c,0x1000,3,0x22,-1,0);
  if (DAT_00302018 == (void *)0xffffffffffffffff) {
    puts("mmap error");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  return;
}

ulong read_input(void *param_1,uint param_2)
{
  int iVar1;
  ulong uVar2;
  
  uVar2 = read(0,param_1,(ulong)param_2);
  iVar1 = (int)uVar2;
  if (iVar1 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (*(char *)((long)param_1 + (long)iVar1 + -1) == '\n') {
    *(undefined *)((long)param_1 + (long)iVar1 + -1) = 0;
  }
  return uVar2 & 0xffffffff;
}

/*
void allocate(size_t *param_1,size_t param_2)
{
  int iVar1;
  void *pvVar2;
  
  *param_1 = param_2;
  printf("Name of heart :");
  read_input(param_1 + 1,0x20);
  pvVar2 = malloc(param_2);
  param_1[5] = (size_t)pvVar2;
  if (param_1[5] == 0) {
    puts("Allocate Error !");
    exit(0);
  }
  printf("secret of my heart :");
  iVar1 = read_input(param_1[5],param_2 & 0xffffffff);
  *(undefined *)((long)iVar1 + param_1[5]) = 0;
  return;
}

void free_and_clear(undefined8 *param_1)
{
  *param_1 = 0;
  memset(param_1 + 1,0,0x20);
  free((void *)param_1[5]);
  param_1[5] = 0;
  return;
}

*/

