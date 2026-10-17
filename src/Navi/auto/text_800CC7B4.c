#include "types.h"
struct VObj_800CC1C4 {
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
// .text 0x800cc7b4-0x800cddd0 (18 functions). split_file divides it into the game's real files.

extern void* lbl_80288B0C[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300EF0;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern f32 lbl_80300EE4;
extern "C" f32 fn_800CDAFC(void* self, s32 n, s32 i);
extern u8 lbl_802BB0FC[];
extern u8 lbl_80288A50[];
extern u8 lbl_802C5714[];
extern "C" void fn_801E10DC(u8* self, s32 n);
extern "C" void fn_800CD444(u8* self);
extern "C" void fn_800CD6FC(u8* self);
extern "C" void fn_800CD3C4(u8* self);
extern "C" s32 fn_800CD8E4(u8* self, s16 i, u8 n, void* unused, s32 mode, f32 from, f32 to);
extern "C" s32 fn_800CD7CC(u8* self, s16 i, u8 n, void* unused, s32 mode, f32 from, f32 to);
extern "C" s32 fn_800CD7CC(u8* self, s16 i, u8 n, void* unused, s32 mode, f32 from, f32 to) {
    if (i < 0) {
        return 0;
    }
    if (i > n) {
        return 1;
    }
    f32 t = fn_800CDAFC(self, n, i);
    f32 d = t * (to - from);
    (*(VObj_800CC1C4**)(self + 0x14))->SetPos(*(f32*)(self + 0x1c), *(f32*)(self + 0x20) + (from + d));
    if (mode != 2) {
        if (mode == 1) {
            t = lbl_80300EE4 - t;
        }
        (*(VObj_800CC1C4**)(self + 0x14))->SetAlpha((s32)((f32)*(u8*)(self + 0x18) * t));
    }
    return 0;
}

extern "C" void fn_800CD9FC(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 8);
}

extern "C" void fn_8015FDA8(void*, void*);
extern "C" void fn_800CDAD0(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 4));
}

extern "C" void fn_800CDD24(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300EF0;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800CDD88(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288B0C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
