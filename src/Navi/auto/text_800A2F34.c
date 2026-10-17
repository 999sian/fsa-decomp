#include "types.h"
struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800a2f34-0x800a4f9c (25 functions). split_file divides it into the game's real files.

extern void* lbl_80286DC8[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300B80;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_800127A0(void*);
extern "C" s32 fn_80020384(void*, s32);
extern char lbl_802C54FC[];
extern char lbl_802BB0FC[];
extern char lbl_80231850[];
extern u32 lbl_802FEDDC;
extern "C" void fn_80017FCC(void*);
extern "C" s32 fn_80029794(void*, void*, s32);
extern "C" void fn_800A4768(void*, s16, u8, s32, s32, f32, f32);
extern "C" void fn_800A4A90(void*, s16, u8, s32, s32, f32, f32);
extern char lbl_8029FDB4[];
extern void* lbl_802FF278;
struct VObj_800A468C {
    virtual void v0();
    virtual void v1();
    virtual void v2(u8);
};

extern "C" BOOL fn_800A2F68(void)
{
    return TRUE;
}

extern "C" BOOL fn_800A3030(void);
extern "C" BOOL fn_800A3030(void)
{
    return TRUE;
}

extern "C" BOOL fn_800A3038(void);
extern "C" BOOL fn_800A3038(void)
{
    return TRUE;
}

extern "C" s32 fn_8002F168(void* p);
extern "C" void fn_800A4678(void* param_1) {
    *(u8*)((u8*)param_1 + 0x19c) = 2;
    *(u8*)((u8*)param_1 + 0x19a) = 1;
}

extern "C" void fn_800A468C(void* param_1) {
    if (fn_8002F168(param_1) != 1) {
        *(u8*)((u8*)param_1 + 0x198) = 0x3c;
        u8 v = *(u8*)((u8*)param_1 + 0x198);
        VObj_800A468C* obj = *(VObj_800A468C**)((u8*)lbl_802FF278 + 4);
        if (obj != nullptr) {
            obj->v2(v);
        }
        *(u8*)((u8*)param_1 + 0x19a) = 5;
    }
}

extern "C" void fn_800A46F4(void* param_1) {
    if (*(u8*)((u8*)param_1 + 0x198) != 0) {
        *(u8*)((u8*)param_1 + 0x198) = *(u8*)((u8*)param_1 + 0x198) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x19a) = 6;
}

extern "C" void fn_800A4718(u8* param_1) {
    s32 r = fn_80020384((char*)lbl_802B7CA0 + 0x1388, 0);
    if (r == 1) {
        *(u8*)(param_1 + 0x19a) = 7;
    }
}

extern "C" void fn_800A4764(void) {
}

extern "C" void fn_800A4BD4(u8* param_1) {
    char* base = (char*)lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0xfc, base + 0x100, param_1 + 8);
}

extern "C" void fn_800A4C10(u8* param_1) {
    void* p = *(void**)(param_1 + 0xc);
    if (p != nullptr) {
        ((void (*)(void*, s32))((*(void***)p)[2]))(p, 1);
    }
    p = *(void**)(param_1 + 0x158);
    if (p != nullptr) {
        ((void (*)(void*, s32))((*(void***)p)[2]))(p, 1);
    }
    p = *(void**)(param_1 + 4);
    ((void (*)(void*))((*(void***)p)[9]))(p);
    u8* g = (u8*)lbl_802C54FC;
    if (*(s8*)(g + 4) >= 0) {
        s32 n = *(s32*)(g + 8) - 1;
        *(s32*)(g + 8) = n;
        if (n == 0) {
            fn_800127A0(lbl_8029FDB4 + 4);
            *(s8*)(g + 4) = -1;
        }
    }
}

extern "C" void fn_800A4EF0(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300B80;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800A4F54(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80286DC8;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
