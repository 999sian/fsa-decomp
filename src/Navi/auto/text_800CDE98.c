#include "types.h"
struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

struct VObj_800D02D8 {
    virtual void v0();
    virtual void v1();
    virtual void SetPos(f32 x, f32 y);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void SetAlpha(s32 a);
};
extern f32 lbl_80300F48;
extern "C" f32 fn_800D0570(u8* p, s32 idx, s16 t, s32 b, f32 from, f32 to);

struct VObjLerp {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(f32, f32);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(s32);
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800cde98-0x800d0844 (21 functions). split_file divides it into the game's real files.

extern void* lbl_802891CC[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300F38;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_800D0410(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 8);
}

extern "C" void fn_8015FDA8(void*, void*);
extern "C" void fn_800D0544(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 4));
}

extern "C" void fn_800D0798(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300F38;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800D07FC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802891CC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
