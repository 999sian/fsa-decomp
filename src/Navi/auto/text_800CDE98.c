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
extern f64 lbl_80300F58;
extern "C" f32 fn_800D0570(u8* p, s32 idx, s32 t, s32 b, f32 from, f32 to);

struct VObjLerp {
    virtual void v0();
    virtual void v1();
    virtual void v4(f32, f32);
    virtual void v3();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v9(s32);
    virtual void v8();
    virtual void v10();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800cde98-0x800d0844 (21 functions). split_file divides it into the game's real files.

extern void* lbl_802891CC[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300F38;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" s32 fn_800D01C0(u8* p, s16 a, u8 b, f32 x, f32 y, s32 c, s32 mode) {
    if (a < 0) {
        return 0;
    }
    if (a > b) {
        return 1;
    }
    f32 t = fn_800D0570(p, b, a, c, x, y);
    VObjLerp* o = *(VObjLerp**)(p + 0x14);
    o->v4(*(f32*)(p + 0x1c) + (x + t * (y - x)), *(f32*)(p + 0x20));
    switch (mode) {
    case 1:
        o = *(VObjLerp**)(p + 0x14);
        o->v9((s32)((f32)p[0x18] * (lbl_80300F48 - t)));
        break;
    case 2:
        break;
    }
    return 0;
}

extern "C" s32 fn_800D02D8(u8* p, s32 idx, s16 t, u8 max, s32 b, s32 mode, f32 from, f32 to) {
    if (t < 0) {
        return 0;
    }
    if (t > max) {
        return 1;
    }
    f32 r = fn_800D0570(p, max, t, b, from, to);
    u8* q = p + idx * 4;
    f32 d = r * (to - from);
    VObj_800D02D8* o = *(VObj_800D02D8**)(q + 0x28);
    o->SetPos(*(f32*)(q + 0x3c), *(f32*)(q + 0x4c) + (from + d));
    if (mode != 2) {
        if (mode == 1) {
            r = lbl_80300F48 - r;
        }
        f32 a = p[idx + 0x38];
        o = *(VObj_800D02D8**)(q + 0x28);
        o->SetAlpha((s32)(a * r));
    }
    return 0;
}

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
