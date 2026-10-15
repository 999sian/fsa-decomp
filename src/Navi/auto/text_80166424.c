#include "types.h"


extern "C" BOOL fn_801694D8(void)
{
	return TRUE;
}

extern "C" void fn_801694E0(unsigned char *param_1, int param_2)
{
	fn_801DF378(param_1 + 0x24, param_2 * 3 + 0x1e, *param_1);
}

extern "C" int fn_8016997C()
{
	return 0;
}

extern "C" int fn_8016999C()
{
	return 0;
}

extern "C" int fn_801699A4()
{
	return 0;
}

extern "C" int fn_801699AC()
{
	return 0;
}

extern "C" int fn_801699D4()
{
	return 0;
}

extern "C" int fn_801699DC()
{
	return 0;
}

extern "C" int fn_801699E4()
{
	return 0;
}

extern "C" int fn_801699EC()
{
	return 0;
}

extern "C" int fn_8016B418()
{
	return 0;
}

extern "C" int fn_8017332C()
{
	return 0;
}

extern "C" int fn_8017334C()
{
	return 0;
}

extern "C" void fn_80178AEC(void* param_1, void* param_2) {
    (*(void (**)(void*))(*(u8**)param_1 + 0x84))(param_1);
    u8* it = *(u8**)((u8*)param_1 + 0xdc);
    if (it != NULL) {
        it -= 0xc;
    }
    while (it != NULL) {
        void* obj = *(void**)(it + 0xc);
        it = *(u8**)(it + 0x18);
        (*(void (**)(void*, void*))(*(u8**)obj + 0x80))(obj, param_2);
        if (it != NULL) {
            it -= 0xc;
        }
    }
}

