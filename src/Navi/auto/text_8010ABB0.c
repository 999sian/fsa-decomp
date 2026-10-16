#include "types.h"
struct VObj_800C8D90 {
    virtual void v0();
    virtual void v1();
    virtual void v2(f32, f32);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(u8);
};

struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8010abb0-0x8010cb9c (30 functions). split_file divides it into the game's real files.

extern void* lbl_8028EAF8[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_8030127C;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_8010C18C(u8* param_1) {
    f32 off = 0.5f * param_1[0x7c];
    (*(VObj_800C8D90**)(param_1 + 0x70))->v2(*(f32*)(param_1 + 0x74) + off, *(f32*)(param_1 + 0x78));
}

extern "C" void fn_8010C7F4(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 8);
}

extern "C" void fn_8010CAF0(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_8030127C;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_8010CB54(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028EAF8;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
