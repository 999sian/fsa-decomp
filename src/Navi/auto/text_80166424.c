#include "types.h"


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

extern "C" int fn_801699B4(void) {
    return 0xFFFF;
}

extern "C" BOOL fn_801699CC(void)
{
    return TRUE;
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

extern "C" u8 fn_80173180(int param_1, int param_2)
{
    return ((u8*)(param_1 + param_2))[0x45];
}

extern "C" void fn_8017318C(void)
{
}

extern "C" BOOL fn_80173190(void)
{
    return TRUE;
}

extern "C" void fn_80173198(int param_1, int param_2, int param_3)
{
    u8* ptr = (u8*)(param_1 + param_2 * 8);
    ptr[0x2d] = ((u8*)param_3)[1];
    ptr[0x2e] = ((u8*)param_3)[2];
    ptr[0x2f] = ((u8*)param_3)[3];
    ptr[0x31] = ((u8*)param_3)[5];
    ptr[0x32] = ((u8*)param_3)[6];
    ptr[0x33] = ((u8*)param_3)[7];
}

extern "C" int fn_8017334C()
{
	return 0;
}

extern "C" int fn_80173354()
{
	return 0;
}

extern "C" int fn_8017335C()
{
	return 0;
}

extern "C" int fn_80173364()
{
	return 0;
}

extern "C" int fn_8017336C()
{
	return 0;
}

extern "C" int fn_80173374()
{
	return 0;
}

extern "C" int fn_8017337C()
{
	return 0;
}

extern "C" void fn_80178B74(void* param_1, void* param_2) {
    (*(void (**)(void*))(*(u8**)param_1 + 0x8c))(param_1);
    u8* it = *(u8**)((u8*)param_1 + 0xdc);
    if (it != NULL) {
        it -= 0xc;
    }
    while (it != NULL) {
        void* obj = *(void**)(it + 0xc);
        it = *(u8**)(it + 0x18);
        (*(void (**)(void*, void*))(*(u8**)obj + 0x88))(obj, param_2);
        if (it != NULL) {
            it -= 0xc;
        }
    }
}

extern "C" void fn_80178DA4(void* param_1)
{
}

extern "C" void fn_80178E60(void) {
}

