#include "types.h"

struct NaviActor {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
};
extern void* lbl_802FEBA0;
extern void* lbl_802FEBA4;

extern void* lbl_80299A8C[];

extern "C" void* lbl_8020491C[];
extern void* lbl_80204948[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_801A9E44(void*);
extern "C" void fn_801A9A60(void*);
extern "C" void fn_801A9930(void*);
extern "C" void fn_80159528(int, int, int, int, int, int, int);
extern "C" int* lbl_802FF6E0;
extern "C" void* fn_8011FD10(void);
extern "C" void fn_8011FD18(void*, const char*, int, const char*, const char*, ...);
extern "C" void fn_80007AB8(const char*, int, const char*, ...);
extern "C" char lbl_80203B9C[];
extern "C" char lbl_802FB810[3];
extern "C" char lbl_802FB814[5];
extern "C" float lbl_802FFB6C;
extern "C" float lbl_802FFB68;
extern "C" void fn_80116840(void* p, f32 a, f32 b);
extern "C" char lbl_80203E4C[];
extern "C" char lbl_80203E28[];
extern "C" char lbl_80203F2C[];
extern "C" void* lbl_802FEBA4;
extern "C" void* lbl_802FEBA8;
extern "C" void* lbl_802FEBAC;
extern "C" void* lbl_802FF544;
extern "C" void* fn_8015C788(u32 size, void* heap, u32 flags);
extern "C" void fn_8015A644(void* ptr, s32 flag);
extern "C" void fn_80159BA4(void* p);
extern "C" void fn_8000F080(void* self, char* param_2);
extern "C" char lbl_80202614[];
extern "C" u8 lbl_80301D1C[2];

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8000d404-0x80012630 (157 functions). split_file divides it into the game's real files.

extern "C" void* fn_8000D404(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_8000D440(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_801B016C(void*, void*);
extern "C" void fn_801B0240(void*, void*);
extern "C" void fn_801AA6F0(void*);
extern "C" char lbl_80203BC4[];
extern "C" u8 fn_8000D6F4(void* self) {
    if (*(void**)((u8*)self + 4) == nullptr) {
        fn_8011FD18(fn_8011FD10(), lbl_80203B9C, 0x16e, lbl_802FB810, lbl_80203BC4);
        fn_80007AB8(lbl_80203B9C, 0x16e, lbl_802FB814);
    }
    fn_801AA6F0(*(void**)((u8*)self + 4));
    u32 result = 1;
    void* p = *(void**)((u8*)self + 4);
    if ((*(u8*)((u8*)p + 5) & 1) == 0 && lbl_802FFB6C != *(f32*)((u8*)p + 0xc)) {
        result = 0;
    }
    return (u8)result;
}

extern "C" void fn_8000DA88(void* self, void* arg, f32 value) {
    *(f32*)(*(u8**)((u8*)self + 8) + 8) = value;
    fn_801B016C(arg, *(void**)((u8*)self + 8));
}

extern "C" void fn_801B033C(void*, void*);
extern "C" void fn_8000E0F0(void* self, void* arg, f32 value) {
    *(f32*)(*(u8**)((u8*)self + 8) + 8) = value;
    fn_801B033C(arg, *(void**)((u8*)self + 8));
}

extern "C" void fn_801B05E0(void*, void*);
extern "C" void fn_8000E414(void* self, void* arg, f32 value) {
    *(f32*)(*(u8**)((u8*)self + 8) + 8) = value;
    fn_801B05E0(arg, *(void**)((u8*)self + 8));
}

extern "C" void fn_8000EAE0(void* ptr, u32 value) {
    *(u32*)((char*)ptr + 4) = value;
}

extern "C" void* fn_8000EAE8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8020491C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80204948;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80204948[];
extern void* lbl_80204820[];
extern void* lbl_80204720[];
extern void* lbl_8020474C[];
extern "C" void fn_801AF42C(void*, void*);
extern "C" void fn_801AF744(void*);
extern char* lbl_802FF704;
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8000EB44(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204948;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8000EBA8(void) {}

extern "C" void fn_8000EBAC(void) {
}

extern "C" void fn_8000EBB0(void) {
}

extern "C" void fn_8000EBB4(void) {
}

extern "C" void fn_801A9E44(void* p);
extern "C" void fn_801A9A60(void* p);
extern "C" void fn_801A9930(void* p);
extern "C" u32 fn_8015C960(u32 p);
extern "C" char lbl_80203E08[];
extern "C" void fn_8000EBB8(NaviActor* param_1) {
    u32* self = (u32*)param_1;
    if (*(u32*)(self[1] + 0x1c) == 1 && *(u16*)(self[1] + 0x74) != 1) {
        param_1->vf2();
        param_1->vf3();
        fn_801A9E44(param_1);
        param_1->vf1();
    } else {
        fn_801A9A60(param_1);
        param_1->vf0();
        fn_801A9930(param_1);
    }
    param_1->vf5();
}

extern "C" void fn_8000EC78(u32* param_1) {
    if (*(u32*)(param_1[1] + 0x1c) == 1 && *(u16*)(param_1[1] + 0x74) != 1) {
        (*(void (**)(u32*))(*(u32**)param_1 + 5))(param_1);
        fn_801A9E44(param_1);
        (*(void (**)(u32*))(*(u32**)param_1 + 3))(param_1);
    } else {
        fn_801A9A60(param_1);
        (*(void (**)(u32*))(*(u32**)param_1 + 3))(param_1);
        fn_801A9930(param_1);
    }
    (*(void (**)(u32*))(*(u32**)param_1 + 7))(param_1);
}

extern "C" int fn_8000ED24()
{
	return 0;
}

extern "C" int fn_8000ED2C()
{
	return 0;
}

extern "C" int fn_8000ED34()
{
	return 0;
}

extern "C" int fn_8000ED3C()
{
	return 0;
}

extern "C" int fn_8000ED44()
{
	return 0;
}

extern "C" int fn_8000ED4C()
{
	return 0;
}

extern "C" int fn_8000ED54()
{
	return 0;
}

extern "C" int fn_8000ED5C()
{
	return 0;
}

extern "C" int fn_8000ED64()
{
	return 0;
}

extern "C" int fn_8000ED6C()
{
	return 0;
}

extern "C" int fn_8000ED74()
{
	return 0;
}

extern "C" int fn_8000ED7C(void) {
    return 0xFFFF;
}

extern "C" int fn_8000ED88()
{
	return 0;
}

extern "C" int fn_8000ED90()
{
	return 0;
}

extern "C" int fn_8000ED98()
{
	return 0;
}

extern "C" int fn_8000EDA0()
{
	return 0;
}

extern "C" int fn_8000EDA8()
{
	return 0;
}

extern "C" int fn_8000EDB0()
{
	return 0;
}

extern "C" BOOL fn_8000EDB8(void);
extern "C" BOOL fn_8000EDB8(void)
{
    return TRUE;
}

extern "C" int fn_8000EDC0()
{
	return 0;
}

extern "C" int fn_8000EDC8()
{
	return 0;
}

extern "C" int fn_8000EDD0()
{
	return 0;
}

extern "C" int fn_8000EDD8()
{
	return 0;
}

extern "C" int fn_8000EDE0()
{
	return 0;
}

extern "C" int fn_8000EDE8()
{
	return 0;
}

extern "C" int fn_8000EDF0()
{
	return 0;
}

extern "C" void fn_8000EDF8(void) {
}

extern "C" void fn_8000EDFC(void) {
}

extern "C" void fn_8000EE00(void) {
}

extern "C" void fn_8000EE04(void) {
}

extern "C" void fn_8000EE08(void) {
}

extern "C" void* fn_8000EE0C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8000EE48(void) {
}

extern "C" void* fn_8000EE4C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8000EE88(void) {
}

extern "C" void fn_8000EE8C(void) {
}

extern "C" void fn_8000EE90(void) {}

extern "C" void fn_8000EE94(void) {}

extern "C" void fn_8000EE98(void) {}

extern "C" void fn_8000EE9C(void) {}

extern "C" void fn_8000EEA0(void) {}

extern "C" void fn_8000EEA4(void) {}

extern "C" void fn_8000EEA8(void) {}

extern "C" void fn_8000EEAC(void) {}

extern "C" void fn_8000EEB0(void) {}

extern "C" void fn_8000EEB4(void) {}

extern "C" void fn_8000EEB8(void) {}

extern "C" void fn_8000EEBC(void) {}

extern "C" void fn_8000EEC0(void) {
}

extern "C" void fn_8000EEC4(void) {
}

extern "C" void fn_8000EEC8(void) {
}

extern "C" u32 lbl_80301D14;
extern "C" void fn_8000EECC(u32* p) {
    *p = lbl_80301D14;
}

extern "C" u32 lbl_80301D08;
extern "C" void fn_8000EF10(u32* p) {
    *p = lbl_80301D08;
}

extern "C" u8 lbl_80301D30;
extern "C" void fn_8000EF1C(u8* p) {
    *p = lbl_80301D30;
}

extern "C" u32 lbl_80301D04;
extern "C" void fn_8000EF28(u32* p) {
    *p = lbl_80301D04;
}

extern "C" u8 lbl_80301D1C[2];
extern "C" void* fn_8000F018(void* self) {
    fn_8000F080(self, lbl_80202614);
    u8* p = (u8*)self;
    p[7] = (p[7] & ~0x0c) | (((u8)lbl_80301D1C[1]) << 2);
    p[7] = (p[7] & ~3) | lbl_80301D1C[0];
    return self;
}

extern "C" void fn_8000F258(void) {}

extern "C" void fn_8000F328(void) {}

extern void* lbl_8020455C[];
extern "C" void* fn_8000F32C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8020455C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80299A8C[];
extern "C" void* fn_8000F388(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299A8C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_8011FD10(void);
extern "C" void fn_8011FD18(void*, const char*, int, const char*, const char*, ...);
extern "C" void fn_80007AB8(const char*, int, const char*, ...);
extern "C" void* fn_8015AC80(void*, void*, int);
extern "C" char lbl_80203B9C[];
extern "C" char lbl_80203DE8[];
extern "C" char lbl_802FB810[3];
extern "C" char lbl_802FB814[5];
extern "C" void* fn_8000F3D0(void* a, void* b) {
    bool ok = false;
    if (lbl_802FEBA0 == nullptr || a == nullptr) {
        ok = true;
    }
    if (!ok) {
        fn_8011FD18(fn_8011FD10(), lbl_80203B9C, 0x63f, lbl_802FB810, lbl_80203DE8);
        fn_80007AB8(lbl_80203B9C, 0x63f, lbl_802FB814);
    }
    lbl_802FEBA0 = fn_8015AC80(a, b, 1);
    *((u8*)lbl_802FEBA0 + 0x6c) = 1;
    return lbl_802FEBA0;
}

extern "C" void* fn_8000F484(void)
{
	return lbl_802FEBA0;
}

extern "C" void fn_8000F48C(void* a, void* b) {
    bool ok = false;
    if (lbl_802FEBA4 == nullptr || a == nullptr) {
        ok = true;
    }
    if (!ok) {
        fn_8011FD18(fn_8011FD10(), lbl_80203B9C, 0x67d, lbl_802FB810, lbl_80203E08);
        fn_80007AB8(lbl_80203B9C, 0x67d, lbl_802FB814);
    }
    lbl_802FEBA4 = fn_8015AC80(a, b, 1);
}

extern "C" void* lbl_802FEBA4;
extern "C" void* fn_8000F534(void)
{
	return lbl_802FEBA4;
}

extern "C" void fn_8000F53C(void* a, void* b) {
    bool ok = false;
    if (lbl_802FEBA8 == nullptr || a == nullptr) {
        ok = true;
    }
    if (!ok) {
        fn_8011FD18(fn_8011FD10(), lbl_80203B9C, 0x6ba, lbl_802FB810, lbl_80203E28);
        fn_80007AB8(lbl_80203B9C, 0x6ba, lbl_802FB814);
    }
    lbl_802FEBA8 = fn_8015AC80(a, b, 1);
}

extern "C" void* lbl_802FEBA8;
extern "C" void* fn_8000F5E4(void)
{
	return lbl_802FEBA8;
}

extern "C" void* fn_8000F5EC(void* a, void* b) {
    bool ok = false;
    if (lbl_802FEBAC == nullptr || a == nullptr) {
        ok = true;
    }
    if (!ok) {
        fn_8011FD18(fn_8011FD10(), lbl_80203B9C, 0x6fa, lbl_802FB810, lbl_80203E4C);
        fn_80007AB8(lbl_80203B9C, 0x6fa, lbl_802FB814);
    }
    lbl_802FEBAC = fn_8015AC80(a, b, 1);
    *((u8*)lbl_802FEBAC + 0x6c) = 1;
    return lbl_802FEBAC;
}

extern "C" void* lbl_802FEBAC;
extern "C" void* fn_8000F6A0(void)
{
	return lbl_802FEBAC;
}

extern "C" void* fn_8000F6A8(u32 param_1, u32 param_2) {
    void* heap = lbl_802FEBA4 == nullptr ? lbl_802FF544 : lbl_802FEBA4;
    void* result;
    if (param_1 == 0 || param_1 == 0xffffffff) {
        result = fn_8015C788(0xffffffff, heap, 0);
    } else {
        u32 size = ((param_1 + 0xf) & ~0xf) + 0x80;
        if (param_2 > 0x10) {
            size = param_2 + size;
            size -= 0x10;
        }
        result = fn_8015C788(size, heap, 0);
    }
    if (result != nullptr) {
        fn_8015A644(result, 1);
    }
    return result;
}

extern "C" u32 fn_8000F9E8(u32 param_1) {
    if (param_1 == 0) {
        return 0;
    }
    u32 uVar1 = fn_8015C960(param_1);
    if (uVar1 >= 0x80) {
        uVar1 -= 0x80;
    }
    return uVar1;
}

extern "C" void fn_80159BB4(void);
extern "C" void fn_8000FA24(void) {
    fn_80159BB4();
}

extern "C" char lbl_80203E28[];
extern "C" char lbl_80203E4C[];
extern "C" void* lbl_802FF544;
extern "C" void* fn_8015C788(u32 size, void* heap, u32 flags);
extern "C" void fn_8015A644(void* ptr, s32 flag);
extern "C" char lbl_80203F2C[];
extern "C" void fn_80159BA4(void* p);
extern "C" void fn_8000FA44(void* p) {
    if (p == nullptr) {
        fn_8011FD18(fn_8011FD10(), lbl_80203B9C, 0x8b9, lbl_802FB810, lbl_80203F2C);
        fn_80007AB8(lbl_80203B9C, 0x8b9, lbl_802FB814);
    }
    fn_80159BA4(p);
}

extern "C" float lbl_802FFB68;
extern "C" float lbl_802FFB6C;
extern "C" char lbl_80203B80[];
extern "C" char lbl_8029F0E0[];
extern "C" void* lbl_802FEBB0;
extern "C" void fn_800101A0(volatile float* p) {
    if (p[1] <= lbl_802FFB6C) {
        return;
    }
    p[1] = p[1] - lbl_802FFB68;
    if (p[1] <= lbl_802FFB6C) {
        p[1] = lbl_802FFB6C;
        p[2] = lbl_802FFB6C;
        p[3] = lbl_802FFB6C;
        float t = p[4];
        p[5] = t;
        p[4] = p[1] * p[2];
        float u = p[5];
        if (u > lbl_802FFB6C) {
            p[3] = lbl_802FFB68 - (u - p[4]) / u;
        } else {
            p[3] = lbl_802FFB6C;
        }
    }
}

extern void* lbl_80204984[];
extern "C" void* fn_80010224(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204984;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* lbl_80204720[];
extern "C" void* lbl_8020474C[];
extern "C" void* lbl_80204948[];
extern "C" void* fn_8001026C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204720;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8020474C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80204948;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8020474C[];
extern "C" void* fn_800102D8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8020474C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80204948;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* lbl_802046F4[];
extern void* lbl_802047F4[];
extern void* lbl_80204820[];
extern "C" void* lbl_80204984[];
extern "C" void* fn_80010428(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802046F4;
        if ((char*)ptr + (unsigned)0xC != nullptr) {
            *(void**)((char*)ptr + 0xC) = lbl_80204984;
        }
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80204720;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8020474C;
                if (ptr != nullptr) {
                    *(void**)ptr = lbl_80204948;
                }
            }
        }
        if (0 < param_2) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80010C28(void* self, f32 value) {
    u8* p = (u8*)self;
    if (*(f32*)(p + 0x2c) < lbl_802FFB6C || value <= lbl_802FFB6C) {
        *(f32*)(p + 0x28) = lbl_802FFB68;
    } else {
        *(f32*)(p + 0x28) = lbl_802FFB6C;
        *(f32*)(p + 0x30) = lbl_802FFB68 / value;
    }
    *(f32*)(p + 0x2c) = *(f32*)(p + 0x28);
}

extern "C" u8 lbl_80301D1C[];
extern "C" char lbl_80202614[];
extern "C" void fn_8000F080(void* self, char* param_2);
extern "C" f32 lbl_802FFB68;
extern "C" f32 lbl_802FFB6C;
extern "C" void fn_80116840(void* p, f32 a, f32 b);
extern "C" u8 fn_80010C6C(void* self) {
    u8* p = (u8*)self;
    f32 one = lbl_802FFB68;
    if (*(f32*)(p + 0x28) < one) {
        *(f32*)(p + 0x2c) = *(f32*)(p + 0x28);
        fn_80116840(p + 0x28, one, *(f32*)(p + 0x30));
    }
    fn_801AA6F0(p + 0xc);
    u32 result = 1;
    if ((p[0x11] & 1) == 0 && lbl_802FFB6C != *(f32*)(p + 0x18)) {
        result = 0;
    }
    return (u8)result;
}

extern "C" void fn_80010DF0(void* self) {
    if (*(void**)((u8*)self + 4) != nullptr) {
        if (*(void**)((u8*)self + 8) != nullptr) {
            *(f32*)((u8*)*(void**)((u8*)self + 8) + 8) = *(f32*)((u8*)self + 0x1c);
        }
        void* b = *(void**)((u8*)*(void**)((u8*)self + 4) + 4);
        void* d = **(void***)((u8*)b + 0x28);
        *(void**)((u8*)d + 0x54) = self;
        ((NaviActor*)*(void**)((u8*)self + 4))->vf2();
    }
}

extern void* lbl_8020469C[];
extern "C" void* fn_80010E54(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8020469C;
        if ((char*)ptr + (unsigned)0x18 != nullptr) {
            *(void**)((char*)ptr + 0x18) = lbl_80204984;
        }
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80204720;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8020474C;
                if (ptr != nullptr) {
                    *(void**)ptr = lbl_80204948;
                }
            }
        }
        if (0 < param_2) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8001154C(void)
{
	fn_80159528(0, 0, 0, 0, 0, 1, 1);
}

extern "C" void fn_80011588(void)
{
	fn_80159528(0, 0, 0, 0, 1, 0, 1);
}

extern "C" void fn_80011688(void) {}

extern "C" void fn_80011B24(void* param_1)
{
	void* ptr1 = *(void**)((char*)param_1 + 0x10);
	(*(void(*)(void))(*(void**)((char*)(*(void**)ptr1) + 0xc)))();
	
	ptr1 = *(void**)((char*)param_1 + 0x10);
	do {
		(*(void(*)(void*))*(void**)((char*)(*(void**)ptr1) + 0x10))(ptr1);
		ptr1 = *(void**)((char*)ptr1 + 0x4);
	} while (ptr1 != NULL);
	
	*(int*)lbl_802FF6E0 = 0;
}

extern void* lbl_80204470[];
extern "C" void* fn_80011DF8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204470;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802044AC[];
extern "C" void* fn_80011E54(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802044AC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" BOOL fn_80011EB0(void);
extern "C" BOOL fn_80011EB0(void)
{
    return TRUE;
}

extern "C" int fn_80011EB8()
{
	return 0;
}

extern void* lbl_80204598[];
extern "C" void* fn_80011EC0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204598;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802045D4[];
extern "C" void* fn_80011F1C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802045D4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80011F78(void)
{
}

extern "C" void fn_80011F7C(void) {
}

extern "C" int fn_80011F80()
{
	return 0;
}

extern "C" int fn_80011F88()
{
	return 0;
}

extern "C" void fn_80011F90(void) {
}

extern "C" float fn_80011F94(void) {
    return lbl_802FFB6C;
}

extern float lbl_802FFB6C;
extern void* lbl_802047F4[];
extern "C" void* fn_80011F9C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802047F4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80204820;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80204720;
                if (ptr != nullptr) {
                    *(void**)ptr = lbl_8020474C;
                    if (ptr != nullptr) {
                        *(void**)ptr = lbl_80204948;
                    }
                }
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80012028(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204820;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80204720;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8020474C;
                if (ptr != nullptr) {
                    *(void**)ptr = lbl_80204948;
                }
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_800120A4(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" void fn_800120AC(void* ptr, u32 value) {
    *(u32*)((char*)ptr + 4) = value;
}

extern "C" void* lbl_802048F0[];
extern "C" void* lbl_8020491C[];
extern "C" void* fn_800120B4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802048F0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8020491C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80204948;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80012120(void* self, void* a, void* b) {
    fn_801AF42C(a, b);
}

extern "C" void fn_80012148(void* self, void* a, void* b) {
    fn_801AF42C(a, b);
}

extern "C" void* lbl_80204820[];
extern "C" void fn_801AF42C(void*, void*);
extern "C" void fn_801AF744(void*);
extern "C" char* lbl_802FF704;
extern "C" void fn_80012170(void) {
    fn_801AF744(lbl_802FF704 + 0x18);
}

extern "C" void fn_80012198(void* param_1)
{
	char buffer[0x20];
	
	unsigned int result = (*(unsigned int (*)(void))*(void**)((char*)(*(void**)param_1) + 0x10))();
	
	if (result) {
		unsigned short val = *(unsigned short*)((char*)lbl_802FF704 + 0x14);
		void* ptr2 = (*(void* (*)(void*, void*))*(void**)((char*)(*(void**)param_1) + 0x10))(param_1, (void*)lbl_802FF704);
		(*(void (*)(void*, unsigned short, void*))*(void**)((char*)(*(void**)ptr2) + 0x10))(ptr2, val, buffer);
		fn_801AF744(buffer);
	} else {
		fn_801AF744((void*)((char*)lbl_802FF704 + 0x18));
	}
}

