#include "types.h"


extern "C" void fn_801CEBD0(void* actor);
extern "C" s32 fn_801CD950(f32* value, f32 target, f32 step);
extern "C" void fn_801CEBD0(void*);
extern "C" int fn_80210898(void)
{
	fn_801CEBD0(NULL);
	return 0;
}

void fn_80210990(void* param_1, int param_2, float* param_3)
{
	float f5 = *(float*)((char*)param_1 + 0x54);
	float f4 = *(float*)((char*)param_1 + 0x58);
	
	param_3[0] = -16.0f * f5;
	param_3[1] = -24.0f * f4;
	param_3[2] = 16.0f * f5;
	param_3[3] = 8.0f * f4;
	
	if (param_2 == 2) {
		param_3[1] = 8.0f * f4 + param_3[1];
		return;
	}
	if (param_2 >= 2) {
		if (param_2 >= 4) {
			return;
		}
		param_3[3] = -(8.0f * f4 - param_3[3]);
		return;
	}
	if (param_2 == 0) {
		param_3[2] = -(8.0f * f5 - param_3[2]);
		return;
	}
	if (param_2 < 0) {
		return;
	}
	param_3[0] = 8.0f * f5 + param_3[0];
}

void fn_80210A30(void* param_1, float* param_2)
{
	float f5 = *(float*)((char*)param_1 + 0x54);
	float f4 = *(float*)((char*)param_1 + 0x58);
	
	param_2[0] = -16.0f * f5;
	param_2[1] = -24.0f * f4;
	param_2[2] = 16.0f * f5;
	param_2[3] = 8.0f * f4;
}

int fn_80210A6C(void* param_1)
{
	s32 result = fn_801CD950((f32*)((char*)param_1 + 0x2a8), 128.0f, 2.0f);
	return result == 0;
}

extern "C" signed char lbl_8053FAB8[2][2];
extern "C" float fn_80210B34(int i)
{
	return lbl_8053FAB8[i][0];
}

