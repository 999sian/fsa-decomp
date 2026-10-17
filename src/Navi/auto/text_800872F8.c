#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800872f8-0x80089858 (57 functions). split_file divides it into the game's real files.

extern void* lbl_80283F48[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_802883C4[];
extern void* lbl_8027EC78[];
extern "C" int fn_800636A0(void*, void*, int);
extern "C" int fn_80058A88(int x);
extern "C" int fn_80058A28(int x);
extern "C" void fn_80057C38(int x);
extern "C" void fn_8001A454(int a, int b, int c);
extern u8 lbl_802B7CA0[];
extern "C" void fn_80021240(void* a, void* b, void* c);
extern "C" void fn_8011AC24(void* a, void* b);
extern "C" void fn_80159C6C(void* a, s32 b);
extern void* lbl_802FF2B0;
extern void* lbl_802FF268;
extern u8 lbl_802FCCF0[];
struct VObj_80088954 {
    virtual void v0(s32);
};
struct VObj_80088CF8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};
extern "C" void fn_8011A194(void* obj, float x, float y, float z);
extern "C" float lbl_803009F8;
extern "C" int fn_8006347C(void*, void*, int, const char*, int, int);
extern const char lbl_80283C88[];
extern "C" int fn_800872F8(void* param_1) {
    int ret = fn_8006347C(param_1, lbl_802B7CA0 + 0x2200, 0x40, lbl_80283C88, 0, 0);
    if (ret == 0) {
        return 5;
    }
    return 2;
}

extern "C" int fn_80087348(void* param_1) {
    int ret = fn_800636A0(param_1, lbl_802B7CA0 + 0x2200, 0x40);
    if (ret < 0) {
        return 5;
    }
    return ret > 0 ? 0 : 2;
}

extern "C" int fn_8008739C(void) {
    fn_80058A28(0xb);
    return 2;
}

extern "C" int fn_800873C4(void) {
    int x = fn_80058A88(0xb);
    int neg_x = -x;
    int tmp = (neg_x | x) >> 31;
    return 4 & tmp;
}

extern "C" int fn_80058A88(int x);
extern "C" int fn_80058A28(int x);
extern "C" void fn_80057C38(int x);
extern "C" void fn_8001A454(int a, int b, int c);
extern void* lbl_80283D2C[];
extern "C" void* fn_800873FC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283D2C;
        if ((s32)ptr + (unsigned)0x4 != 0) {
            ((void**)(ptr))[1] = lbl_802883C4;
            if ((s32)ptr + 0x4 != 0) {
                ((void**)(ptr))[1] = lbl_8027EC78;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80087788(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802883C4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_800877E4(void* param_1) {
    register s8 byte = *(s8*)((u8*)param_1 + 0x420);
    if (!byte) {
        fn_80057C38(0x1e);
        (*(u8*)((u8*)param_1 + 0x420))++;
    } else if (byte != -1) {
        fn_8001A454(4, 0, 5);
    }
    return 1;
}

extern "C" BOOL fn_80087A60(void);
extern "C" BOOL fn_80087A60(void)
{
    return TRUE;
}

extern "C" BOOL fn_8008856C(void);
extern "C" BOOL fn_8008856C(void)
{
    return TRUE;
}

extern "C" void fn_800885B4(void);
extern "C" void fn_80088574(void) {
    fn_800885B4();
}

extern "C" void fn_80088690(void);
extern "C" void fn_80088594(void) {
    fn_80088690();
}

extern "C" void* fn_800888E0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283F48;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80088928(u8* param_1) {
    fn_80021240(param_1 + 0x1c4, lbl_802FCCF0, param_1);
}

extern "C" s32 fn_80088954(u8* param_1) {
    fn_8011AC24(lbl_802FF2B0, lbl_802FF268);
    VObj_80088954* p = *(VObj_80088954**)(param_1 + 0x1dc);
    if (p != 0) {
        p->v0(1);
    }
    fn_80159C6C(*(void**)(param_1 + 0x1d4), 0);
    fn_80159C6C(*(void**)(param_1 + 0x1d8), 0);
    return 1;
}

extern "C" BOOL fn_80088CF0(void);
extern "C" BOOL fn_80088CF0(void)
{
    return TRUE;
}

extern "C" void fn_80088CF8(VObj_80088CF8* obj) {
    obj->m1();
}

extern "C" void fn_80088D24(VObj_80088CF8* obj) {
    obj->m7();
}

extern "C" void fn_80119978(void*, int);
extern char lbl_80283FC4[];
extern "C" void* fn_80088D50(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80283FC4;
        fn_80119978(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80088DB0(void* obj, float x, float y) {
    fn_8011A194(obj, x, y, 12.0f);
}

extern "C" void* fn_80088DD4(u8* p) {
    return *(void**)(p + 0x48);
}

extern "C" u16 fn_80088DDC(u8* p) {
    return *(u16*)(*(u8**)(p + 0x4c) + 0x8);
}

extern "C" u16 fn_80088DE8(u8* p) {
    return *(u16*)(*(u8**)(p + 0x4c) + 0x10);
}

extern "C" u16 fn_80088DF4(u8* p) {
    return *(u16*)(*(u8**)(p + 0x4c) + 0xe);
}

extern "C" u16 fn_80088E00(void* obj) {
    return *(u16*)(*(char**)((char*)obj + 0x4c) + 0xa);
}

extern "C" u16 fn_80088E0C(void* param_1) {
    return *(u16*)(*(u8**)((u8*)param_1 + 0x4c) + 0xc);
}

extern "C" void fn_80088ED4(void);
extern "C" void fn_80088E74(void) {
    fn_80088ED4();
}

extern "C" void fn_80088F58(void);
extern "C" void fn_80088E94(void) {
    fn_80088F58();
}

extern "C" void fn_80088F9C(void);
extern "C" void fn_80088EB4(void) {
    fn_80088F9C();
}

extern "C" void fn_80069BEC(void);
extern "C" void fn_80089420(void) {
    fn_80069BEC();
}

extern "C" void fn_8008962C(void) {}

extern "C" void fn_80089630(void) {}

extern "C" BOOL fn_80089850(void);
extern "C" BOOL fn_80089850(void)
{
    return TRUE;
}

