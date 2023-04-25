
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
    __isoc99_scanf(&DAT_08048dd9,local_34);
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
      __isoc99_scanf(&DAT_08048dd9,name);
      printf("Thank you %s ,see you next time\n",name);
      if (fp != (FILE *)0x0) {
        fclose(fp);
      }
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
  } while( true );
}

