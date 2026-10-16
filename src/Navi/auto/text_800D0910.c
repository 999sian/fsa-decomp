#include "types.h"
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

struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800d0910-0x800d3600 (24 functions). split_file divides it into the game's real files.

extern void* lbl_80289490[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300F88;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_8015FDA8(void*, void*);
extern "C" void fn_800D2F3C(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 4));
}

extern f32 lbl_80300F98;
extern "C" f32 fn_800D332C(u8* p, s32 idx, s32 t, s32 b, f32 from, f32 to);
extern "C" s32 fn_800D2FE8(u8* p, s32 idx, s16 t, u8 max, s32 b, s32 mode, f32 from, f32 to) {
    if (t < 0) {
        return 0;
    }
    if (t > max) {
        return 1;
    }
    f32 r = fn_800D332C(p, max, t, b, from, to);
    u8* q = p + idx * 4;
    f32 d = r * (to - from);
    VObj_800D02D8* o = *(VObj_800D02D8**)(q + 0x28);
    o->SetPos(*(f32*)(q + 0x3c), *(f32*)(q + 0x4c) + (from + d));
    if (mode != 2) {
        if (mode == 1) {
            r = lbl_80300F98 - r;
        }
        f32 a = p[idx + 0x38];
        o = *(VObj_800D02D8**)(q + 0x28);
        o->SetAlpha((s32)(a * r));
    }
    return 0;
}

extern "C" void fn_800D3238(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 8);
}

extern "C" void fn_800D3554(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300F88;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800D35B8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80289490;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
