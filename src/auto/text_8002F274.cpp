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

extern "C" int fn_80030394(int param_1, int param_2)
{
  if (param_2 != 0) {
    return param_1 + param_2;
  }
  return 0;
}

extern "C" void* fn_800303AC(const void* ptr, const void* offset)
{
  if (offset == 0) {
    return 0;
  }
  return (unsigned char*)ptr + (unsigned int)offset;
}

extern "C" void* fn_800303C4(const void* base, const void* offset)
{
  if (offset == 0) {
    return 0;
  }
  return (void*)((int)base + (int)offset);
}

extern "C" void* fn_800303DC(const void* base, const void* offset)
{
  if (offset == 0) {
    return 0;
  }
  return (void*)((int)base + (int)offset);
}

extern "C" void* fn_800303F4(const void* ptr, const void* offset)
{
  if (offset == 0) {
    return 0;
  }
  return (unsigned char*)ptr + (unsigned int)offset;
}

s32 fn_8003040C(s32 param_1, s32 param_2)
{
	if (param_2 == 0) {
		return 0;
	}
	return param_1 + param_2;
}

extern "C" void* fn_80030424(const void* ptr, const void* offset)
{
	if (offset == 0) {
		return 0;
	}
	return (void*)((int)ptr + (int)offset);
}

int fn_8003043C(int param_1, int param_2)
{
  if (param_2 == 0) {
    return 0;
  }
  return param_1 + param_2;
}

extern "C" void* fn_80030454(const void* ptr, const void* offset)
{
	if (offset == 0) {
		return 0;
	}
	return (void*)((int)ptr + (int)offset);
}
class JKRHeap;
class JASBank;
extern "C" JASBank* fn_8002F294(const void*, JKRHeap*);
class JASBNKParser {
public:
    static JASBank* createBank(const void*, JKRHeap*);
};
