
void welcome(void)
{
  puts("#######################################################");
  puts("   This is a simple program to open,read,write a file");
  puts("   You can open what you want to see");
  puts("   Can you read everything ?");
  puts("#######################################################");
  return;
}


int init(EVP_PKEY_CTX *ctx)
{
  uint uVar1;
  
  setvbuf(stdout,(char *)0x0,2,0);
  signal(0xe,handler);
  uVar1 = alarm(0x3c);
  return uVar1;
}

void handler(void)
{
  puts("Timeout");
                    /* WARNING: Subroutine does not return */
  exit(1);
}

void main(void)
{
  int iVar1;
  int in_GS_OFFSET;
  EVP_PKEY_CTX *in_stack_ffffffc0;
  char local_34 [32];
  undefined4 local_14;
  undefined *puStack_c;
  
  puStack_c = &stack0x00000004;
  local_14 = *(undefined4 *)(in_GS_OFFSET + 0x14);
  init(in_stack_ffffffc0);
  welcome();
  do {
    menu();
    __isoc99_scanf("%s",local_34);
    iVar1 = atoi(local_34);
    switch(iVar1) {
    default:
      puts("Invaild choice");
                    /* WARNING: Subroutine does not return */
      exit(0);
    case 1:
      openfile();
      break;
    case 2:
      readfile();
      break;
    case 3:
      writefile();
      break;
    case 4:
      closefile();
      break;
    case 5:
      printf("Leave your name :");
      __isoc99_scanf("%s",name_0x804b260);
      printf("Thank you %s ,see you next time\n",name_0x804b260);
      if (fp_0x804b280 != (FILE *)0x0) {
        fclose(fp_0x804b280);
      }
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
  } while( true );
}


void menu(void)
{
  puts("---------------MENU---------------");
  puts("  1. Open");
  puts("  2. Read");
  puts("  3. Write to screen");
  puts("  4. Close");
  puts("  5. Exit");
  puts("----------------------------------");
  printf("Your choice :");
  return;
}


int openfile(void)
{
  int iVar1;
  char *pcVar2;
  
  if (fp_0x804b280 == (FILE *)0x0) {
    memset(magicbuf_0x804b0c0,0,400);
    printf("What do you want to see :");
    __isoc99_scanf("%63s", filename_0x804b080);
    pcVar2 = strstr(filename_0x804b080,"flag");
    if (pcVar2 != (char *)0x0) {
      puts("Danger !");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
    fp_0x804b280 = fopen(filename_0x804b080,"r");
    if (fp_0x804b280 == (FILE *)0x0) {
      iVar1 = puts("Open failed");
    }
    else {
      iVar1 = puts("Open Successful");
    }
  }
  else {
    puts("You need to close the file first");
    iVar1 = 0;
  }
  return iVar1;
}


void readfile(void)
{
  size_t sVar1;
  
  memset(magicbuf_0x804b0c0,0,400);
  if (fp_0x804b280 == (FILE *)0x0) {
    puts("You need to open a file first");
  }
  else {
    sVar1 = fread(magicbuf_0x804b0c0,399,1,fp_0x804b280);
    if (sVar1 != 0) {
      puts("Read Successful");
    }
  }
  return;
}


void writefile(void)
{
  char *pcVar1;
  
  pcVar1 = strstr(filename_0x804b080,"flag");
  if (pcVar1 == (char *)0x0) {
    pcVar1 = strstr(magicbuf_0x804b0c0,"FLAG");
    if (pcVar1 == (char *)0x0) {
      pcVar1 = strchr(magicbuf_0x804b0c0,0x7d);
      if (pcVar1 == (char *)0x0) {
        puts(magicbuf_0x804b0c0);
        return;
      }
    }
  }
  puts("you can\'t see it");
                    /* WARNING: Subroutine does not return */
  exit(1);
}

void closefile(void)
{
  if (fp_0x804b280 == (FILE *)0x0) {
    puts("Nothing need to close");
  }
  else {
    fclose(fp_0x804b280);
  }
  fp_0x804b280 = (FILE *)0x0;
  return;
}
