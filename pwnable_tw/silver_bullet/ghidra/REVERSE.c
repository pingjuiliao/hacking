
undefined4 beat(void* bullets, void* werewolf)
{
  undefined4 uVar1;
  
  if (bullets->buf[0] == '\0') {
    puts("You need create the bullet first !");
    uVar1 = 0;
  }
  else {
    puts(">----------- Werewolf -----------<");
    printf(" + NAME : %s\n", werewolf->name);
    printf(" + HP : %d\n", werewolf->hp);
    puts(">--------------------------------<");
    puts("Try to beat it .....");
    usleep(1000000);
    werewolf->hp = werewolf->hp - bullet->size;
    if (werewolf->hp < 1) {
      puts("Oh ! You win !!");
      uVar1 = 1;
    }
    else {
      puts("Sorry ... It still alive !!");
      uVar1 = 0;
    }
  }
  return uVar1;
}


void create_bullet(char *bullet)
{
  size_t sVar1;
  
  if (bullets->buf[0] == '\0') {
    printf("Give me your description of bullet :",0);
    read_input(bullets->buf, 0x30);
    sVar1 = strlen(bullets->buf);
    printf("Your power is : %u\n",sVar1);
    bullets->size = sVar1;
    puts("Good luck !!");
  }
  else {
    puts("You have been created the Bullet !");
  }
  return;
}


void init_proc(void)
{
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stdin,(char *)0x0,2,0);
  return;
}

typedef _Werewolf {
  uint32_t hp;
  char* name;
} Werewolf;

typedef _Bullets {
  char* buf[48]; // 0x30
  size_t size;
} Bullets;

undefined4 main(void)
{
  int iVar1;
  Werewolf werewolf; // -0x3c + $ebp
  Bullets bullets;   // -0x34 + $ebp
  
  init_proc();
  bullets.size = 0;
  memset(bullets.buf, 0, 0x30);
  werewolf.hp = 0x7fffffff;
  werewolf.name = &DAT_08048d06; // "Gin!"
  
  do {
    while( true ) {
      while( true ) {
        menu();
        iVar1 = read_int();
        if (iVar1 != 2) break;
        power_up(&bullets);
      }
      if (2 < iVar1) break;
      if (iVar1 == 1) {
        create_bullet(&bullets);
      }
      else {
LAB_08048a05:
        puts("Invalid choice");
      }
    }
    if (iVar1 != 3) {
      if (iVar1 == 4) {
        puts("Don\'t give up !");
                    /* WARNING: Subroutine does not return */
        exit(0);
      }
      goto LAB_08048a05;
    }
    iVar1 = beat(&bullets, &werewolf);
    if (iVar1 != 0) {
      return 0;
    }
    puts("Give me more power !!");
  } while( true );
}


void menu(void)
{
  puts("+++++++++++++++++++++++++++");
  puts("       Silver Bullet       ");
  puts("+++++++++++++++++++++++++++");
  puts(" 1. Create a Silver Bullet ");
  puts(" 2. Power up Silver Bullet ");
  puts(" 3. Beat the Werewolf      ");
  puts(" 4. Return                 ");
  puts("+++++++++++++++++++++++++++");
  printf("Your choice :");
  return;
}


void power_up(char *bullets)
{
  size_t sVar1;
  char concat_buf[48];
  int total_size;
  
  total_size = 0;
  memset(concat_buf, 0, 0x30);
  if (bullets->buf[0] == '\0') {
    puts("You need create the bullet first !");
  }
  else if ((uint)bullets->size < 0x30) {
    printf("Give me your another description of bullet :");
    read_input(concat_buf ,0x30 - *(int *)(param_1 + 0x30));
    strncat(&bullets->buf, concat_buf, 0x30 - *(int *)(param_1 + 0x30));
    sVar1 = strlen(concat_buf);
    total_size = ((int)bullets->size) + sVar1;
    printf("Your new power is : %u\n", total_size);
    (int)bullets->size = total_size;
    puts("Enjoy it !");
  }
  else {
    puts("You can\'t power up any more !");
  }
  return;
}


ssize_t read_input(void *param_1, size_t param_2)
{
  ssize_t sVar1;
  
  sVar1 = read(0, param_1, param_2);
  if (sVar1 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  if (*(char *)((int)param_1 + sVar1 + -1) == '\n') {
    *(undefined *)((int)param_1 + sVar1 + -1) = 0;
  }
  return sVar1;
}


int read_int(void)
{
  int iVar1;
  char local_1c [20];
  ssize_t local_8;
  
  local_8 = read(0,local_1c,0xf);
  if (local_8 < 1) {
    puts("read error");
                    /* WARNING: Subroutine does not return */
    exit(1);
  }
  iVar1 = atoi(local_1c);
  return iVar1;
}

