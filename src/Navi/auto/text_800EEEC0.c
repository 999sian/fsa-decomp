#include "types.h"
struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct VObj_800EF2A8 {
 virtual void v0();
 virtual void v1();
 virtual void v2(f32 x, f32 y);
 virtual void v3();
 virtual void v4(f32 x, f32 y);
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800eeec0-0x800efb88 (17 functions). split_file divides it into the game's real files.

extern void* lbl_8028B900[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" f32* fn_80177B10(void* p);
extern char lbl_802B7CA0[];
extern f32 lbl_8030113C;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_800EF4E0(void* p);
extern "C" s32 fn_800EF768(void* p, u8 idx, u8 b, s32 c);
extern u8 lbl_802C587C[];
extern u8 lbl_8029FDB4[];
extern "C" void fn_800127A0(void*, s8 = 0);
struct VObj_800EF6D0A {
 virtual void v0(s32 x);
};

struct VObj_800EF6D0B {
 virtual void v0();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void v4();
 virtual void v5();
 virtual void v6();
 virtual void v7();
};

struct NaviState_800EF384;
typedef void (NaviState_800EF384::*NaviStateFn_800EF384)();
extern NaviStateFn_800EF384 lbl_8028B874[];
extern "C" void fn_800EF1AC(u8* p)
{
	f32 f31;
	f32 f30;
	f32 x;
	u8* b;
	u8* a;

	f30 = *(f32*)(*(u8**)(p + 0x18) + 0x28) - *(f32*)(*(u8**)(p + 0x18) + 0x20);
	f31 = fn_80177B10(*(void**)(p + 0x18))[1];
	x = fn_80177B10(*(void**)(p + 0x14))[0] - f30;
	((VObj_800EF2A8*)*(void**)(p + 0x18))->v2(x, f31);
	*(f32*)(p + 0x2c) = fn_80177B10(*(void**)(p + 0x14))[2];
	a = *(u8**)(p + 0x18);
	b = *(u8**)(p + 0x14);
	*(f32*)(p + 0x30) = (*(f32*)(b + 0x28) - *(f32*)(b + 0x20)) + (*(f32*)(a + 0x28) - *(f32*)(a + 0x20));
	p[0x34] = 0;
	*(s32*)(p + 0x40) = -1;
	*(s32*)(p + 0x44) = -1;
	*(s32*)(p + 0x48) = -1;
	*(s32*)(p + 0x4c) = -1;
	(*(u8**)(p + 0x1c))[0xb0] = 0;
	(*(u8**)(p + 0x20))[0xb0] = 0;
	p[0x50] = 0;
	p[0x52] = 0;
	p[0x51] = 1;
}

extern "C" void fn_800EF2A8(u8* p)
{
	f32 f31;
	f32 f30;
	f32* b;

	f30 = *(f32*)(*(u8**)(p + 0x18) + 0x28) - *(f32*)(*(u8**)(p + 0x18) + 0x20);
	f31 = fn_80177B10(*(void**)(p + 0x18))[1];
	b = fn_80177B10(*(void**)(p + 0x14));
	((VObj_800EF2A8*)*(void**)(p + 0x18))->v4(b[0] - f30, f31);
	b = fn_80177B10(*(void**)(p + 0x14));
	*(f32*)(p + 0x2c) = b[2];
	*(f32*)(p + 0x30) = (*(f32*)(*(u8**)(p + 0x18) + 0x28) - *(f32*)(*(u8**)(p + 0x18) + 0x20)) + (*(f32*)(*(u8**)(p + 0x14) + 0x28) - *(f32*)(*(u8**)(p + 0x14) + 0x20));
	p[0x34] = 0;
	p[0x51] = 0;
	p[0x52] = 0;
}

extern "C" void fn_800EF378(u8* param_1, u32 param_2, u32 param_3) {
    *(u32*)(param_1 + 0x40) = param_2;
    *(u32*)(param_1 + 0x44) = param_3;
}

extern "C" void fn_800EF384(NaviState_800EF384* p) {
    (p->*lbl_8028B874[((u8*)p)[0x52]])();
    fn_800EF4E0(p);
}

extern "C" void fn_800EF3D0(void) {}

extern "C" void fn_800EF3D4(u8* param_1) {
    if (param_1[0x51] == 0) {
        param_1[0x52] = 0;
    } else {
        s32 r = fn_800EF768(param_1, param_1[0x50], lbl_802C587C[0xc], 0);
        param_1[0x50]++;
        if (r == 1) {
            param_1[0x50] = 0;
            param_1[0x51] = 0;
            param_1[0x52] = 0;
        }
    }
}

extern "C" void fn_800EF450(u8* param_1) {
    if (param_1[0x51] == 1) {
        param_1[0x52] = 0;
    } else {
        s32 r = fn_800EF768(param_1, param_1[0x50], lbl_802C587C[0xc], 1);
        param_1[0x50]++;
        if (r == 1) {
            param_1[0x50] = 0;
            param_1[0x51] = 1;
            param_1[0x52] = 0;
        }
    }
}

extern "C" void fn_800EF4D0(u8* param_1, u8 param_2) {
    if (param_2 != 0) {
        param_1[0x52] = param_2;
    }
}

extern "C" void fn_800EF694(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 8);
}

extern "C" void fn_800EF6D0(u8* p) {
    VObj_800EF6D0A* a = *(VObj_800EF6D0A**)(p + 0xc);
    if (a != nullptr) {
        a->v0(1);
    }
    (*(VObj_800EF6D0B**)(p + 4))->v7();
    s8 idx = *(s8*)(lbl_802C587C + 4);
    if (idx >= 0) {
        if (--*(s32*)(lbl_802C587C + 8) == 0) {
            fn_800127A0(lbl_8029FDB4 + 4, idx);
            *(s8*)(lbl_802C587C + 4) = -1;
        }
    }
}

extern "C" void fn_800EFADC(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_8030113C;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800EFB40(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028B900;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
