
char ** create(undefined4 param_1,char *param_2)

{
  char **__ptr;
  
  __ptr = (char **)malloc(0x10);
  __ptr[1] = param_2;
  asprintf(__ptr,"%s",param_1);
  __ptr[2] = (char *)0x0;
  __ptr[3] = (char *)0x0;
  return __ptr;
}

