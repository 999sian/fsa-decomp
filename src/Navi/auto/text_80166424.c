#include "types.h"

extern "C" void fn_80178C9C(void*, void*);


extern "C" void fn_80168280(void);
extern "C" void fn_80167CB8(void) {
    fn_80168280();
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

extern "C" int fn_801699B4(void) {
    return 0xFFFF;
}

extern "C" int fn_801699C0(void) {
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

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8016B170(void*, int);
extern u8 lbl_80298644[];
extern u8 lbl_80298660[];
typedef void (*VFn_80169B1C)(void*, int);
extern "C" u32* fn_80169B1C(u32* self, short param_2)
{
    if (self != NULL) {
        self[0] = (u32)lbl_80298644;
        u32* p = (u32*)self[0x1c];
        if (p != NULL) {
            (*(VFn_80169B1C*)(p[0] + 0xb8))(p, 1);
        }
        p = (u32*)self[0x1d];
        if (p != NULL) {
            (*(VFn_80169B1C*)(p[0] + 0x34))(p, 1);
        }
        fn_8015AB1C((void*)self[0x21]);
        fn_8016B170(self + 10, -1);
        if ((u8*)self + 0x10 != NULL) {
            self[9] = (u32)lbl_80298660;
        }
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    return self;
}

extern void* lbl_802985C8[];
extern void* lbl_80298600[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8016ACA0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802985C8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80298600;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8016AD04(void) {
}

extern "C" int fn_80172EA4(int p, int index) {
    return p + index * 4 + 0x44;
}

extern "C" u8 fn_80173180(int param_1, int param_2)
{
    int addr = param_1 + param_2;
    return ((u8*)addr)[0x45];
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
    u8* base = (u8*)(param_1 + param_2 * 8);
    u8* src = (u8*)param_3;
    base[0x2d] = src[1];
    base[0x2e] = src[2];
    base[0x2f] = src[3];
    base[0x31] = src[5];
    base[0x32] = src[6];
    base[0x33] = src[7];
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

extern "C" void fn_801789D0(int* param_1)
{
	int iVar1;

	(*(void (**)(int*, int))(*param_1 + 0x60))(param_1, 0);
	iVar1 = param_1[0x37];
	if (iVar1 != 0) {
		iVar1 = iVar1 - 0xc;
	}
	while (iVar1 != 0) {
		int* obj = *(int**)(iVar1 + 0xc);
		(*(void (**)(int*))(*obj + 0x54))(obj);
		iVar1 = *(int*)(iVar1 + 0x18);
		if (iVar1 != 0) {
			iVar1 = iVar1 - 0xc;
		}
	}
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

extern "C" u32 fn_80178E08(void) { return 0x10; }

extern "C" void fn_80178E5C(void* param_1)
{
}

extern "C" void fn_80178E60(void) {
}

