

#include "types.h"

typedef void VFn_80169B1C(u32*, int);
extern "C" void* lbl_80298644[];
extern "C" u32 lbl_80298660;
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8016B170(u32*, int);

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

extern "C" int fn_801699CC(void)
{
    return 1;
}

extern "C" int fn_801699D4()
{
	return 0;
}

extern "C" int fn_801699DC()
{
	return 0;
}

extern "C" int fn_801699EC()
{
	return 0;
}

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
            self[9] = lbl_80298660;
        }
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    return self;
}

extern void* lbl_802985C8[];
extern void* lbl_80298600[];
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

extern "C" void fn_8016AD04() {}

extern "C" int fn_801719B4(void* param_1, void* param_2) {
    if (param_2 == 0) {
        return 0;
    }
    if (*(u8*)((u8*)param_1 + 0x1b1) != 0 && *(void**)((u8*)param_1 + 0x1ac) != 0) {
        void* obj = *(void**)((u8*)param_1 + 0x1ac);
        (*(void (**)(void*, int))(*(u32*)obj + 8))(obj, 1);
    }
    *(u8*)((u8*)param_1 + 0x1b1) = 0;
    *(void**)((u8*)param_1 + 0x1ac) = param_2;
    return 1;
}

extern "C" u8 lbl_80301ADC;
extern "C" void fn_801721F0(u8* p) {
    *p = lbl_80301ADC;
}

extern "C" s32 fn_80172640(s32 p, s32 i) {
    return p + i * 4 + 0x16;
}

extern "C" s32 fn_801728E0(s32 p, s32 i) {
    return p + i * 4 + 0x16;
}

extern "C" void fn_80172974(u8* p, s32 i, u8 v) {
    p[i + 0xa8] = v;
}

extern "C" u8 fn_80172980(u8* p, s32 i) {
    return p[i + 0xa8];
}

extern "C" void fn_8017298C(u8* p, s32 i, u8 v) {
    p[i + 0xb0] = v;
}

extern "C" s32 fn_80172CEC(s32 p, s32 i) {
    return p + i + 0x78;
}

extern "C" void fn_80172CFC(u8* p1, int p2, u32* p3) { ((u32*)(p1 + 0x7c))[p2] = *p3; }

extern "C" s32 fn_80172D10(s32 p, s32 i) {
    return p + i * 4 + 0x7c;
}

extern "C" u32 fn_80172DBC(void) { return 0x54564232; }

extern "C" u8* fn_80172E24(u8* p, s32 i) { return p + i * 4 + 10; }

extern "C" u8 fn_80172EC4(u8* p, s32 i) { return *(p + i + 0x54); }

extern "C" void fn_80172ED0(u8* p, s32 i, u8 v) { *(p + i + 0x56) = v; }

extern "C" u8 fn_80172EDC(u8* p, s32 i) { return *(p + i + 0x56); }

extern "C" u32 fn_80172FF8(int param_1, u32 param_2) {
    if (param_2 >= 2) {
        return 0;
    }
    return *(u32*)(param_1 + param_2 * 4 + 100);
}

extern "C" u32 fn_80173018(int param_1, u32 param_2) {
    if (param_2 >= 2) {
        return 0;
    }
    return *(u32*)(param_1 + param_2 * 4 + 0x6c);
}

extern "C" unsigned int fn_80173060(void) {
    return 0x54564231;
}

extern "C" void fn_801730A4(int param_1, int param_2, u8* param_3) {
    u8 uVar0 = param_3[0];
    u8* p = (u8*)(param_1 + param_2 * 4);
    p[8] = uVar0;
    p[9] = param_3[1];
    p[10] = param_3[2];
}

extern "C" BOOL fn_80173190(void)
{
    return TRUE;
}

extern "C" int fn_8017334C()
{
	return 0;
}

extern "C" int fn_80173354()
{
	return 0;
}

extern "C" void* fn_80174B70(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174B88(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_80174BB8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void fn_80178DB0(void* param_1) {
    register void* vtable = *(void**)param_1;
    void (*func)(void) = *(void(**)(void))((u8*)vtable + 0x74);
    func();
}
