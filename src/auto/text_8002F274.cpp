// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include <JSystem/JSupport.h>

void fn_80030380(short *param_1)
{
  short sVar1;
  
  do {
    sVar1 = *param_1;
    param_1 = param_1 + 3;
  } while (sVar1 < 0xb);
}

int fn_80030394(int param_1, int param_2)
{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}

int fn_800303AC(int param_1, int param_2)
{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}

int fn_800303C4(int param_1, int param_2)
{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}

