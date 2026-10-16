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
// .text 0x800d73fc-0x800ee3f0 (167 functions). split_file divides it into the game's real files.

extern void* lbl_8028B80C[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80301058;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_8015FDA8(void*, void*);
extern "C" void fn_800E38B8(void) {}

extern "C" void fn_800EE0F0(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 4));
}

extern "C" void fn_800EE344(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80301058;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800EE3A8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028B80C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
