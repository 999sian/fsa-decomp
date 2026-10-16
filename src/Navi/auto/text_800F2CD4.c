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
// .text 0x800f2cd4-0x800f4a54 (24 functions). split_file divides it into the game's real files.

extern void* lbl_8028C5D0[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80301198;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_800F42C0(void) {}

extern "C" void fn_800F46AC(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 4);
}

extern "C" void fn_800F49A8(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80301198;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800F4A0C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028C5D0;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
