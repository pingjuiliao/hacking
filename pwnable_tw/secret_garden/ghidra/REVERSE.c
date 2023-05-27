//
// sizeof(Flower) == 0x28;
struct Flower {
  uint32_t existence;
  uint8_t pad[4];
  char* name;
  char color[0x18];
};

void menu(void)
{
  long lVar1;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  puts("");
  puts(&DAT_00101328);
  puts(&DAT_00101378);
  puts(&DAT_00101328);
  puts("");
  puts("  1 . Raise a flower ");
  puts("  2 . Visit the garden ");
  puts("  3 . Remove a flower from the garden");
  puts("  4 . Clean the garden");
  puts("  5 . Leave the garden");
  puts("");
  __printf_chk(1,"Your choice : ");
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


void raise_flower(void)
{
  int iVar1;
  undefined8 *puVar2;
  void *__buf;
  long *plVar3;
  uint uVar4;
  long in_FS_OFFSET;
  uint local_24;
  long local_20;
  
  local_20 = *(long *)(in_FS_OFFSET + 0x28);
  local_24 = 0;
  if (DAT_302024_flower_cnt < 100) {
    puVar2 = (undefined8 *)malloc(0x28);
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    __printf_chk(1,"Length of the name :");
    iVar1 = __isoc99_scanf("%u",&local_24);
    if (iVar1 == -1) {
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    __buf = malloc((ulong)local_24);
    if (__buf == (void *)0x0) {
      puts("Alloca error !!");
                    /* WARNING: Subroutine does not return */
      exit(-1);
    }
    __printf_chk(1,"The name of flower :");
    read(0,__buf,(ulong)local_24);
    puVar2[1] = __buf;
    __printf_chk(1,"The color of the flower :");
    __isoc99_scanf("%23s",puVar2 + 2);
    puVar2.existence = 1;

    // plant the flower: if the pointer is null then plant (cleared)
    if (DAT_302040_garden == 0) {
      uVar4 = 0;
LAB_00100d75:
      (&DAT_302040_garden)[uVar4] = (long)puVar2;
    }
    else {
      plVar3 = &DAT_00302040_garden[1];
      uVar4 = 1;
      do {
        if (*plVar3 == 0) goto LAB_00100d75;
        uVar4 = uVar4 + 1;
        plVar3 = plVar3 + 1;
      } while (uVar4 != 100);
    }
    DAT_302024_flower_cnt = DAT_302024_flower_cnt + 1;
    puts("Successful !");
  }
  else {
    puts("The garden is overflow");
  }
  if (local_20 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


int remove_flower(void)
{
  int iVar1;
  long in_FS_OFFSET;
  uint local_14;
  long local_10;
  
  local_10 = *(long *)(in_FS_OFFSET + 0x28);
  if (DAT_302024_flower_cnt == 0) {
    iVar1 = puts("No flower in the garden");
  }
  else {
    __printf_chk(1,"Which flower do you want to remove from the garden:");
    __isoc99_scanf("%d",&local_14); // 0xe31: ja: not a vuln
    if ((local_14 < 100) && ((undefined4 *)(&DAT_302040_garden)[local_14] != (undefined4 *)0x0)) {
      (&DAT_302040_garden)[local_14].existence = 0;
      free(*(void **)((&DAT_302040_garden)[local_14].name));
      iVar1 = puts("Successful");
    }
    else {
      puts("Invalid choice");
      iVar1 = 0;
    }
  }
  if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar1;
}


void clean_garden(void)
{
  long lVar1;
  int *__ptr;
  int **ppiVar2;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  ppiVar2 = (int **)&DAT_302040_garden;
  do {
    __ptr = *ppiVar2;
    if ((__ptr != NULL && (__ptr.existence == 0)) {
      free(__ptr);
      *ppiVar2 = (int *)0x0;
      DAT_302024_flower_cnt = DAT_302024_flower_cnt + -1;
    }
    ppiVar2 = ppiVar2 + 1;
  } while (ppiVar2 != (int **)&_end);
  puts("Done!");
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


void show_garden(void)
{
  long lVar1;
  int *piVar2;
  ulong uVar3;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  uVar3 = 0;
  if (DAT_302024_flower_cnt == 0) {
    puts("No flower in the garden !");
  }
  else {
    do {
      piVar2 = (int *)(&DAT_302040_garden)[uVar3];
      if ((piVar2 != (int *)0x0) && (piVar2.existence != 0)) {
        __printf_chk(1,"Name of the flower[%u] :%s\n",uVar3 & 0xffffffff,*(undefined8 *)(piVar2 + 2)
                    );
        __printf_chk(1,"Color of the flower[%u] :%s\n",uVar3 & 0xffffffff,
                     (&DAT_302040_garden)[uVar3] + 0x10);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 != 100);
  }
  if (lVar1 == *(long *)(in_FS_OFFSET + 0x28)) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}


void setup(void)
{
  long lVar1;
  long in_FS_OFFSET;
  
  lVar1 = *(long *)(in_FS_OFFSET + 0x28);
  setvbuf(stdout,(char *)0x0,2,0);
  signal(0xe,FUN_00100b40);
  alarm(0x3c);
  if (lVar1 != *(long *)(in_FS_OFFSET + 0x28)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}


void main(void)
{
  ulong uVar1;
  long in_FS_OFFSET;
  char acStack_28 [8];
  undefined8 local_20;
  
  local_20 = *(undefined8 *)(in_FS_OFFSET + 0x28);
  setup();
  do {
    menu();
    read(0,acStack_28,4);
    uVar1 = strtol(acStack_28,(char **)0x0,10);
    switch(uVar1 & 0xffffffff) {
    default:
      puts("Invalid choice");
      break;
    case 1:
      raise_flower();
      break;
    case 2:
      show_garden();
      break;
    case 3:
      remove_flower();
      break;
    case 4:
      clean_garden();
      break;
    case 5:
      puts("See you next time.");
                    /* WARNING: Subroutine does not return */
      exit(0);
    }
  } while( true );
}

