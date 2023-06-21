// %rsp = %rbp - 0x20
int _register(undefined8 param_1)
{
  int iVar1;
  long in_FS_OFFSET;
  int size; // -0xc(%rbp)
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("{i} Username length: ");
  iVar1 = __isoc99_scanf("%d",&size);
  if (iVar1 < 0) {
    puts("Something went wrong!");
    size = -1;
  }
  else if ((size < 1) || (0x80 < size)) {
    puts("Invalid length.");
    size = -1;
  }
  else {
    printf("{i} Enter username: ");
    getInput(param_1,size);
    puts("Username registered successfully!");
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return size;
}

// %rsp = %rbp - 0xb0
bool _login(char *param_1,int param_2)
{
  int iVar1;
  long in_FS_OFFSET;
  char local_a8 [152]; // -0xa0(%rbp)
  long local_10; // -0x8(%rbp)
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  printf("{i} Username: ");
  getInput(local_a8,param_2);
  iVar1 = strncmp(local_a8,param_1,(long)param_2);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1 == 0;
}


undefined8 main(void)
{
  bool bVar1; // -0xa9(%rbp)
  int iVar2;
  undefined8 uVar3;
  long in_FS_OFFSET;
  int option; // -0xa8(%rbp)
  int registered_size; // -0xa4(%rbp)
  undefined local_a8[152]; // -0xa0(%rbp)
  long local_10; // -0x8(%rbp)
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  bVar1 = false;
  setup();
  banner();
  do {
    menu();
    iVar2 = __isoc99_scanf("%d",&option);
    if (iVar2 < 0) {
      puts("Something went wrong.\n");
      uVar3 = 1;
LAB_00101657:
      if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
        return uVar3;
      }
                    /* WARNING: Subroutine does not return */
      __stack_chk_fail();
    }
    if (option == 3) {
      uVar3 = 0;
      goto LAB_00101657;
    }
    if (3 < option) {
LAB_0010163c:
      puts("Invalid option.\n");
      uVar3 = 1;
      goto LAB_00101657;
    }
    if (option == 1) {
      registered_size = _register(local_a8);
      if (registered_size < 0) {
        uVar3 = 1;
        goto LAB_00101657;
      }
      bVar1 = true;
    } else {
      if (option != 2) goto LAB_0010163c;
      if (bVar1) {
        iVar2 = _login(local_a8,registered_size);
        if (iVar2 == 0) {
          puts("Invalid username! :)");
        } else {
          puts("Good job! :^)");
        }
      } else {
        puts("You need to register first.");
      }
    }
  } while( true );
}


// rsp = rbp - 0x20
// param_1: -0x18(%rbp)
// param_2: -0x1c(%rbp)
void getInput(long param_1,int param_2)
{
  ssize_t sVar1;
  long in_FS_OFFSET;
  char local_12; // -0xa(%rbp)
  char local_11; // -0x9(%rbp)
  long local_10; // -0x8(%rbp)
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  local_11 = '\0';
  do {
    if ((param_2 <= local_11) || (sVar1 = read(0,&local_12,1), (int)sVar1 < 1))
    goto code_r0x0010137f;
    if (local_12 != ' ') {
      if (local_12 == '\n') {
code_r0x0010137f:
        if (local_10 == *(long *)(in_FS_OFFSET + 0x28)) {
          return;
        }
                    /* WARNING: Subroutine does not return */
        __stack_chk_fail();
      }
      *(char *)(local_11 + param_1) = local_12;
    }
    local_11 = local_11 + '\x01';
  } while( true );
}

void menu(void)
{
  puts("{1. Register  }");
  puts("{2. Login     }");
  puts("{3. Exit      }");
  printf("-> ");
  return;
}

void setup(void)
{
  setvbuf(stdin,(char *)0x0,2,0);
  setvbuf(stdout,(char *)0x0,2,0);
  setvbuf(stderr,(char *)0x0,2,0);
  return;
}

void banner(void)
{
  puts(
      " /$$                           /$$                  /$$$$$$  /$$                         /$$             /$$                        "
      );
  puts(
      "| $$                          |__/                 /$$__  $$|__/                        | $$            | $$                        "
      );
  puts(
      "| $$        /$$$$$$   /$$$$$$  /$$ /$$$$$$$       | $$  \\__/ /$$ /$$$$$$/$$$$  /$$   /$$| $$  /$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$ "
      );
  puts(
      "| $$       /$$__  $$ /$$__  $$| $$| $$__  $$      |  $$$$$$ | $$| $$_  $$_  $$| $$  | $$| $$ |____  $$|_  $$_/   /$$__  $$ /$$__  $$"
      );
  puts(
      "| $$      | $$  \\ $$| $$  \\ $$| $$| $$  \\ $$       \\____  $$| $$| $$ \\ $$ \\ $$| $$  | $$| $$  /$$$$$$$  | $$    | $$  \\ $$| $$  \\__/"
      );
  puts(
      "| $$      | $$  | $$| $$  | $$| $$| $$  | $$       /$$  \\ $$| $$| $$ | $$ | $$| $$  | $$| $$ /$$__  $$  | $$ /$$| $$  | $$| $$      "
      );
  puts(
      "| $$$$$$$$|  $$$$$$/|  $$$$$$$| $$| $$  | $$      |  $$$$$$/| $$| $$ | $$ | $$|  $$$$$$/| $$|  $$$$$$$  |  $$$$/|  $$$$$$/| $$      "
      );
  puts(
      "|________/ \\______/  \\____  $$|__/|__/  |__/       \\______/ |__/|__/ |__/ |__/ \\______/ |__/ \\_______/   \\___/   \\______/ |__/      "
      );
  puts(
      "                     /$$  \\ $$                                                                                                      "
      );
  puts(
      "                    |  $$$$$$/                                                                                                      "
      );
  puts(
      "                     \\______/                                                                                                       "
      );
  puts("");
  return;
}


