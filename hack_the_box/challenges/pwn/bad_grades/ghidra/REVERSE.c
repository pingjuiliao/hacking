
// void FUN_00400fd5(void)
void vuln()
{
  long in_FS_OFFSET;
  int num_grades; // rbp - 0x120
  int i;          // rbp - 0x11c
  double total;   // rbp - 0x118
  double buf [33];// rbp - 0x110
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  total = 0.0;
  customed_print("Number of grades: ", "cyan", "bold");
  
  __isoc99_scanf("%d", &num_grades);
  for (i = 0; i < num_grades; i = i + 1) {
    printf("Grade [%d]: ",(ulong)(i + 1));
    __isoc99_scanf("%lf",buf + i);
    total = buf[i] + total;
  }
  printf("Your new average is: %.2f\n",total / (double)num_grades);
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


// undefined8 FUN_00401108(void)
int main()
{
  long in_FS_OFFSET;
  int local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  FUN_00400ea6();
  printf("Your grades this semester were really ");
  customed_print(&DAT_004013d7,"green","deleted");
  customed_print(" BAD!\n",&DAT_004012ba,"blink");
  printf("\n1. View current grades.\n2. Add new.\n> ");
  __isoc99_scanf(&DAT_0040137e,&local_14);
  if (local_14 == 1) {
    FUN_00400f1a();
  }
  else {
    if (local_14 != 2) {
      puts("Invalid option!\nExiting..");
                    /* WARNING: Subroutine does not return */
      exit(9);
    }
    vuln();
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return 0;
}

