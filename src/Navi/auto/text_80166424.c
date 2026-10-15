#include "types.h"


extern "C" void fn_801693F4(void *, void *, unsigned int);
extern "C" void fn_801DF378(void *, int, unsigned char);
extern "C" void fn_80169578(void *, void *, void *);
extern "C" void fn_80169710(void *, void *);
extern "C" void fn_801693A8(void *param_1, unsigned int param_2, float param_3, float param_4, float param_5)
{
	float local_c = param_3 + param_5;
	float local_8 = param_4 + param_5;
	unsigned int local_18 = *(unsigned int *)param_1;
	float local_14 = param_3;
	float local_10 = param_4;
	fn_801693F4(&local_14, &local_18, param_2);
}

extern "C" BOOL fn_801694D8(void)
{
	return TRUE;
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

extern "C" BOOL fn_801699CC(void);
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

extern "C" int fn_8016B418()
{
	return 0;
}

extern "C" BOOL fn_80173190(void);
extern "C" BOOL fn_80173190(void)
{
    return TRUE;
}

extern "C" int fn_8017332C()
{
	return 0;
}

extern "C" int fn_80173334()
{
	return 0;
}

extern "C" int fn_8017334C()
{
	return 0;
}

extern "C" int fn_80173354()
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

extern "C" void fn_80178DB0(void* param_1) {
    void* vtable = *(void**)param_1;
    void (*func)(void) = *(void(**)(void))((u8*)vtable + 0x74);
    func();
}

