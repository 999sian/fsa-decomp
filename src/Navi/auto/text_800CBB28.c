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
// .text 0x800cbb28-0x800cc6ac (15 functions). split_file divides it into the game's real files.

extern void* lbl_802889E0[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300EA0;
extern f32 lbl_80300EA4;
extern f32 lbl_80300E9C;
extern u8 lbl_802C56EC[];
extern "C" s32 fn_800CC1C4(u8* self, s16 i, u8 n, void* unused, s32 mode, f32 from, f32 to);
extern "C" s32 fn_800CC2DC(u8* self, s16 i, u8 n, void* unused, s32 mode);
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
extern "C" f32 fn_800CC3D8(void* self, s32 n, s32 i);
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_800CBF04(u8* param_1) {
    u8* a = lbl_802C56EC;
    f32 b = lbl_80300E9C;
    *(s16*)(param_1 + 0x2a) = 0;
    fn_800CC1C4(param_1, *(s16*)(param_1 + 0x2a), a[0x10], 0, 0, *(f32*)(a + 0xc), b);
    fn_800CC2DC(param_1, *(s16*)(param_1 + 0x2a), a[0x10], 0, 0);
}

struct NaviState_800CBF78;
typedef void (NaviState_800CBF78::*NaviStateFn_800CBF78)();
extern NaviStateFn_800CBF78 lbl_8028893C[];
extern "C" void fn_800CBF78(NaviState_800CBF78* p) {
    (p->*lbl_8028893C[((u8*)p)[0x2e]])();
}

extern "C" void fn_800CC1C0(void) {}

extern "C" s32 fn_800CC1C4(u8* self, s16 i, u8 n, void* unused, s32 mode, f32 from, f32 to) {
    if (i < 0) {
        return 0;
    }
    if (i > n) {
        return 1;
    }
    f32 t = fn_800CC3D8(self, n, i);
    f32 d = t * (to - from);
    (*(VObj_800CC1C4**)(self + 0x14))->SetPos(*(f32*)(self + 0x1c), *(f32*)(self + 0x20) + (from + d));
    if (mode != 2) {
        if (mode == 1) {
            t = lbl_80300EA4 - t;
        }
        (*(VObj_800CC1C4**)(self + 0x14))->SetAlpha((s32)((f32)*(u8*)(self + 0x18) * t));
    }
    return 0;
}

extern "C" s32 fn_800CC2DC(u8* param_1, s16 param_2, u8 param_3, void* param_4, s32 param_5) {
    f32 f;
    if (param_2 < 0) {
        return 0;
    }
    if (param_2 > param_3) {
        return 1;
    }
    f = fn_800CC3D8(param_1, param_3, param_2);
    if (param_5 != 2) {
        if (param_5 == 1) {
            f = lbl_80300EA4 - f;
        }
        (*(VObj_800CC1C4**)(param_1 + 0x24))->SetAlpha((int)((float)*(u8*)(param_1 + 0x28) * f));
    }
    return 0;
}

extern "C" void fn_800CC39C(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 8);
}

extern "C" void fn_800CC600(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300EA0;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800CC664(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802889E0;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
