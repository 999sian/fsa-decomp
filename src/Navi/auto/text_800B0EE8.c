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
// .text 0x800b0ee8-0x800bace4 (71 functions). split_file divides it into the game's real files.

extern void* lbl_8028794C[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_80287910[];
extern void* lbl_80286A30[];
extern unsigned char lbl_802313EC[];
extern "C" unsigned char fn_800B51E8(void* self, int i) {
    return lbl_802313EC[i];
}

extern "C" void* fn_800B9970(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80287910;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80286A30;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern char lbl_802B7CA0[];
extern f32 lbl_80300C88;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_800BAC38(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300C88;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800BAC9C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028794C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
