
undefined8 FUN_001018a4(void *param_1)

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

