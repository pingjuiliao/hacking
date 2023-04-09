
undefined8 set_seccomp(char param_1,char param_2)
{
  int iVar1;
  long lVar2;
  undefined8 uVar3;
  
  lVar2 = seccomp_init(0x80000000);
  uVar3 = 0;
  if (lVar2 != 0) {
    iVar1 = seccomp_rule_add_exact(lVar2,0x7fff0000,0xe7,0);
    uVar3 = 0;
    if (-1 < iVar1) {
      if ((param_1 != '\0') && (iVar1 = seccomp_rule_add_exact(lVar2,0x7fff0000,0,0), iVar1 < 0)) {
        return 0;
      }
      if ((param_2 != '\0') && (iVar1 = seccomp_rule_add_exact(lVar2,0x7fff0000,1,0), iVar1 < 0)) {
        return 0;
      }
      iVar1 = seccomp_load(lVar2);
      uVar3 = 0;
      if (-1 < iVar1) {
        seccomp_release(lVar2);
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}

void banner(void)
{
  puts("############################################################");
  puts("#                                                          #");
  puts("#            WELCOME TO THE SHELLCODE MANAGER              #");
  puts("#           (where safety is our top priority)             #");
  puts("#                                                          #");
  puts("############################################################");
  return;
}


void menu(void)
{
  long in_FS_OFFSET;
  undefined8 local_1a;
  undefined2 local_12;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_1a = 0;
  local_12 = 0;
  puts("\nPlease choose an operation:");
  puts("1) Add a new shellcode");
  puts("2) Edit a shellcode");
  puts("3) Execute a shellcode");
  puts("4) Show your shellcodes");
  puts("5) Delete a shellcodes");
  puts("6) Exit");
  puts("7) Mystery");
  printf("\nChoice: ");
  fgets((char *)&local_1a,9,stdin);
  strtol((char *)&local_1a,(char **)0x0,10);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


long find_shellcode_slot(void)
{
  long lVar1;
  
  lVar1 = 0;
  do {
    if ((&DAT_00104120)[lVar1] == 0) {
      return lVar1;
    }
    lVar1 = lVar1 + 1;
  } while (lVar1 != 5);
  return 0xffffffff;
}


ulong get_shellcode_index(void)
{
  ulong uVar1;
  ulong uVar2;
  long in_FS_OFFSET;
  undefined8 local_1a;
  undefined2 local_12;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_1a = 0;
  local_12 = 0;
  printf("Shellcode index: ");
  fgets((char *)&local_1a,9,stdin);
  uVar1 = strtol((char *)&local_1a,(char **)0x0,10);
  if ((4 < (uint)uVar1) || (uVar2 = uVar1 & 0xffffffff, (&DAT_00104120)[(int)(uint)uVar1] == 0)) {
    puts("Invalid shellcode index!");
    uVar2 = 0xffffffff;
  }
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


void add_shellcode(void)
{
  int iVar1;
  long lVar2;
  
  iVar1 = find_shellcode_slot();
  if (iVar1 == -1) {
    puts("Too many shellcodes!");
  }
  else {
    lVar2 = add_shellcode_internal();
    if (lVar2 != 0) {
      (&DAT_00104120)[iVar1] = lVar2;
      puts("Shellcode saved");
    }
  }
  return;
}

uint * add_shellcode_internal(void)
{
  uint uVar1;
  uint *shellcode;
  long lVar2;
  void *__buf;
  long in_FS_OFFSET;
  undefined local_58 [16];
  undefined local_48 [16];
  undefined local_38 [16];
  undefined2 local_28;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_58 = ZEXT816(0);
  local_48 = ZEXT816(0);
  local_38 = ZEXT816(0);
  local_28 = 0;
  shellcode = (uint *)malloc(0x10);
  printf("Shellcode type (1=simple, 2=read, 3=write): ");
  fgets(local_58,0x31,stdin);
  lVar2 = strtol(local_58,(char **)0x0,10);
  shellcode->mode = (int)(char)lVar2;
  if ((int)(char)shellcode->mode - 1U < 3) {
    printf("Size of shellcode: ");
    local_58 = (undefined  [16])0x0;
    local_48 = (undefined  [16])0x0;
    local_38 = (undefined  [16])0x0;
    local_28 = 0;
    fgets(local_58,0x31,stdin);
    lVar2 = strtol(local_58,(char **)0x0,10);
    shellcode->size = (uint)lVar2;
    if ((uint)lVar2 - 1 < 99) {
      printf("Shellcode: ");
      uVar1 = shellcode->size;
      __buf = malloc((ulong)uVar1);
      shellcode->data = __buf;
      read(0,__buf,(ulong)uVar1);
    }
    else {
      puts("Bad size!");
      free(shellcode);
      shellcode = (uint *)0x0;
    }
  }
  else {
    puts("Bad type!");
    free(shellcode);
    shellcode = (uint *)0x0;
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return __ptr;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

void edit_shellcode(void)
{
  char cVar1;
  int idx;
  
  idx = get_shellcode_index();
  if (idx != -1) {
    cVar1 = edit_shellcode_internal((&DAT_00104120)[idx]);
    if (cVar1 != '\0') {
      puts("Shellcode edited");
    }
  }
  return;
}

undefined4 edit_shellcode_internal(int *shellcode)
{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  ulong uVar4;
  void *__buf;
  long in_FS_OFFSET;
  undefined local_78 [16];
  undefined local_68 [16];
  undefined local_58 [16];
  undefined2 local_48;
  long local_40;
  
  local_40 = *(long *)(in_FS_OFFSET + 0x28);
  local_78 = ZEXT816(0);
  local_68 = ZEXT816(0);
  local_58 = ZEXT816(0);
  local_48 = 0;
  uVar3 = 0;
  if (shellcode != (int *)0x0) {
    cVar2 = yes_no_prompt("Do you want to change the shellcode type?");
    if (cVar2 != '\0') {
      printf("Shellcode type (1=simple, 2=read, 3=write): ");
      local_78 = (undefined  [16])0x0;
      local_68 = (undefined  [16])0x0;
      local_58 = (undefined  [16])0x0;
      local_48 = 0;
      fgets(local_78,0x31,stdin);
      uVar4 = strtol(local_78,(char **)0x0,10);
      if (2 < (byte)((char)uVar4 - 1U)) {
        puts("Bad type!");
        uVar3 = 0;
        goto LAB_0010179a;
      }
      printf("Changing type to %d\n",uVar4 & 0xffffffff);
      shellcode->mode = (int)uVar4;
    }
    uVar3 = yes_no_prompt("Do you want to change the shellcode?");
    if ((char)uVar3 == '\0') {
      uVar3 = 1;
    }
    else {
      printf("Size of shellcode: ");
      local_78 = (undefined  [16])0x0;
      local_68 = (undefined  [16])0x0;
      local_58 = (undefined  [16])0x0;
      local_48 = 0;
      fgets(local_78,0x31,stdin);
      uVar4 = strtol(local_78,(char **)0x0,10);
      iVar1 = (int)uVar4;
      if (iVar1 - 1U < 99) {
        printf("Shellcode: ");
        __buf = malloc((long)iVar1);
        read(0,__buf,(long)iVar1);
        printf("Changing shellcode to new blob of length %d\n",uVar4 & 0xffffffff);
        free(*(void **)shellcode->data);
        *param_1 = iVar1;
        *(void **)(shellcode->data) = __buf;
      }
      else {
        puts("Bad size!");
        uVar3 = 0;
      }
    }
  }
LAB_0010179a:
  if (local_40 == *(long *)(in_FS_OFFSET + 0x28)) {
    return uVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}




void run_shellcode(void)
{
  int iVar1;
  
  iVar1 = get_shellcode_index();
  if (iVar1 != -1) {
    run_shellcode_internal((&DAT_00104120)[iVar1]);
  }
  return;
}

void run_shellcode_internal(uint *shellcode)
{
  uint uVar1;
  char cVar2;
  __pid_t _Var3;
  undefined8 *__dest;
  ulong uVar4;
  undefined8 *puVar5;
  long in_FS_OFFSET;
  byte bVar6;
  uint local_24;
  long local_20;
  
  bVar6 = 0;
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  printf("Running shellcode...");
  __dest = (undefined8 *)mmap((void *)0x0,0x1000,7,0x21,-1,0);
  *__dest = 0xc3c3c3c3c3c3c3c3;
  __dest[0x1ff] = 0xc3c3c3c3c3c3c3c3;
  puVar5 = (undefined8 *)((ulong)(__dest + 1) & 0xfffffffffffffff8);
  for (uVar4 = (ulong)(((int)__dest - (int)(undefined8 *)((ulong)(__dest + 1) & 0xfffffffffffffff8))
                       + 0x1000U >> 3); uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar5 = 0xc3c3c3c3c3c3c3c3;
    puVar5 = puVar5 + (ulong)bVar6 * -2 + 1;
  }
  memcpy(__dest,*(void **)shellcode->data,(ulong) shellcode->size);
  _Var3 = fork();
  if (_Var3 != 0) {
    wait(&local_24);
    puts("done!");
    printf("Execution finished with status code %d\n",(ulong)local_24);
    if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
      return;
    }
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  close(2);
  if ((shellcode->mode == 3) || (close(1), shellcode->mode != 2)) {
    close(0);
    uVar1 = shellcode->mode;
    if (uVar1 == 3) {
      cVar2 = set_seccomp(0,1);
      goto joined_r0x00101408;
    }
    if ((int)uVar1 < 4) {
      if (uVar1 == 1) {
        cVar2 = set_seccomp(0,0);
        goto joined_r0x00101408;
      }
      if (uVar1 == 2) goto LAB_0010141c;
    }
  }
  else {
LAB_0010141c:
    cVar2 = set_seccomp(1,0);
joined_r0x00101408:
    if (cVar2 == '\0') goto LAB_00101438;
  }
  (*(code *)__dest)();
LAB_00101438:
                    /* WARNING: Subroutine does not return */
  exit(0);
}


void delete_shellcode(void)
{
  char cVar1;
  int iVar2;
  
  iVar2 = get_shellcode_index();
  if (iVar2 != -1) {
    cVar1 = delete_shellcode_internal((&DAT_00104120)[iVar2]);
    if (cVar1 != '\0') {
      puts("Shellcode deleted");
    }
    (&DAT_00104120)[iVar2] = 0;
  }
  return;
}


undefined8 delete_shellcode_internal(void *param_1)
{
  if (param_1 != (void *)0x0) {
    if (*(void **)((long)param_1 + 8) != (void *)0x0) {
      free(*(void **)((long)param_1 + 8));
    }
    free(param_1);
    return 1;
  }
  return 0;
}



void show_shellcode(void)
{
  uint *puVar1;
  ulong uVar2;
  
  uVar2 = 0;
  do {
    puVar1 = (uint *)(&DAT_00104120)[uVar2];
    if (puVar1 == (uint *)0x0) {
      printf("Shellcode #%d: <empty>\n",uVar2 & 0xffffffff);
    }
    else {
      printf("Shellcode #%d: type=%d, length=%d\n",uVar2 & 0xffffffff,(ulong)puVar1[1],
             (ulong)*puVar1);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 5);
  return;
}


undefined8 main(void)
{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = menu();
  switch(uVar1) {
  default:
    uVar2 = 1;
    break;
  case 1:
    add_shellcode();
    uVar2 = 1;
    break;
  case 2:
    edit_shellcode();
    uVar2 = 1;
    break;
  case 3:
    run_shellcode();
    uVar2 = 1;
    break;
  case 4:
    show_shellcode();
    uVar2 = 1;
    break;
  case 5:
    delete_shellcode();
    uVar2 = 1;
    break;
  case 6:
    uVar2 = 0;
    break;
  case 7:
    FUN_00101c28();
    uVar2 = 1;
  }
  return uVar2;
}


/* WARNING: Could not reconcile some variable overlaps */

ulong yes_no_prompt(undefined8 param_1)
{
  char *pcVar1;
  long in_FS_OFFSET;
  undefined8 local_1a;
  undefined2 local_12;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_1a = 0;
  local_12 = 0;
  printf("%s (y/n): ",param_1);
  pcVar1 = fgets((char *)&local_1a,9,stdin);
  if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
    return (ulong)pcVar1 & 0xffffffffffffff00 | (ulong)((char)local_1a == 'y');
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

