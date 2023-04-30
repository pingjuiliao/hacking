
void my_read(void *param_1,uint param_2)
{
  int iVar1;
  ssize_t sVar2;
  
  sVar2 = read(0,param_1,(ulong)param_2);
  iVar1 = (int)sVar2;
  if (iVar1 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    _exit(1);
  }
  if (*(char *)((long)param_1 + (long)iVar1 + -1) == '\n') {
    *(undefined *)((long)param_1 + (long)iVar1 + -1) = 0;
  }
  return;
}


void setup(void)
{
  signal(0xe,FUN_00100d0f);
  alarm(0x708);
  DAT_00302020 = mmap((void *)0x0,0x1000,3,0x22,-1,0);
  if (DAT_00302020 == (void *)0xffffffffffffffff) {
    puts("mmap error");
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  return;
}


void enter_password(char *param_1)
{
  int iVar1;
  size_t __n;
  char local_88 [128];
  
  printf("Your passowrd :");
  my_read(local_88,0x7f);
  __n = strlen(local_88);
  iVar1 = strncmp(local_88,param_1,__n);
  if (iVar1 == 0) {
    DAT_302014_has_logined = 1;
    puts("Login Success !");
  }
  else {
    puts("Failed !");
  }
  return;
}


void magic_copy(char *param_1)
{
  char local_88 [128];
  
  printf("Copy :");
  my_read(local_88,0x3f);
  strcpy(param_1,local_88);
  puts("It is magic copy !");
  return;
}

undefined8 main(void)
{
  undefined8 *puVar1;
  int iVar2;
  undefined local_68 [64];
  undefined8 local_28;
  undefined8 local_20;
  char cmd [16]; // $rbp - 0x10
  
  setup();
  DAT_302018_fd = open("/dev/urandom",0);
  read(DAT_302018_fd,&local_28,0x10);
  puVar1 = DAT_00302020;
  *DAT_00302020 = local_28;
  puVar1[1] = local_20;
  close(DAT_302018_fd);
  while( true ) {
    write(1, ">> ",3);
    __read_chk(0,cmd,0x10,0x10);
    if (cmd[0] == '2') break;
    if (cmd[0] == '3') {
      if (DAT_302014_has_logined == 0) {
        puts("Invalid choice");
      }
      else {
        magic_copy(local_68);
      }
    }
    else if (cmd[0] == '1') {
      if (DAT_302014_has_logined == 0) {
        enter_password(&local_28);
      }
      else {
        DAT_302014_has_logined = 0;
      }
    }
    else {
      puts("Invalid choice");
    }
  }
  if (DAT_302014_has_logined == 0) {
                    /* WARNING: Subroutine does not return */
    exit(0);
  }
  iVar2 = memcmp(&local_28,DAT_00302020,0x10);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}

