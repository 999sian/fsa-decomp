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
extern char lbl_8029FDB4[];
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

extern "C" void fn_800A4BD4(u8* param_1) {
    char* base = (char*)lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0xfc, base + 0x100, param_1 + 8);
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
