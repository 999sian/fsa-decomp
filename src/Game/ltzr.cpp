// TU 0x8033f9a0-0x80340ec8 (actor LTZR).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include "JSystem/JMath/JMath.h"

// ---- from src/Game/Ltzr_ctor_80340C60.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801BB3B0(void* this_);
extern void* lbl_804AC3E0[];

extern "C" void fn_801BB30C(void* this_, s32);
extern "C" void __dl__FPv(void*);
extern "C" void fn_801BB1AC(void* this_);
extern "C" void fn_802314D8(s32, f32*);
extern "C" void fn_801F0E34(void*, u32, s32);
extern const f32 lbl_80542268;
extern const f32 lbl_805422AC;
extern const f32 lbl_80542288;
extern const f32 lbl_8054227C;
extern const f32 lbl_8054228C;
extern const f32 lbl_805422B0;
extern const f32 lbl_805422B4;
extern "C" u8 fn_80233E40(s32);
extern "C" f32* fn_8023E724(s32);
extern "C" void fn_8023DFF4(s32, f32*);
extern "C" void* fn_8013CC50(void*, void*, f32, s32, s32, s32, s32, s32, s32);

extern "C" void* fn_8033F9A0(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AC3E0;
        fn_801BB30C(this_, 0);
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_80340650(void) { return 0; }
extern "C" s32 fn_80340658(void) { return 0; }
extern "C" s32 fn_80340660(void) { return 0; }

extern "C" void fn_80340668(void* this_) {
    f32 b = lbl_805422AC;
    f32 a = lbl_80542268;
    u8 hit = 0;
    u8* flags = (u8*)this_;
    for (s32 i = 0; i < 4; i++) {
        if (flags[0x2ac + i] != 0) {
            f32 v[3];
            v[0] = a;
            v[1] = a;
            v[2] = b;
            fn_802314D8(i, v);
            hit = 1;
        }
    }
    if (hit == 1) {
        fn_801F0E34(this_, 0x50082, 0);
        void** vt = *(void***)this_;
        ((void (*)(void*))vt[41])(this_);
    }
}

extern "C" void fn_80340BC8(char* p) {
    p[0x2ac] = 0;
    p[0x2ad] = 0;
    p[0x2ae] = 0;
    p[0x2af] = 0;
    *(s16*)(p + 0x2b2) = 0;
    p[0x2b0] = 0;
    *(f32*)(p + 0x10) = *(f32*)(p + 0x28);
}

extern "C" void fn_80340BF0(char* p) {
    fn_801BB1AC(p);
    *(f32*)(p + 0xc) -= lbl_80542288;
    *(f32*)(p + 0x24) -= lbl_80542288;
    *(f32*)(p + 0x10) -= lbl_80542288;
    *(f32*)(p + 0x28) -= lbl_80542288;
    *(f32*)(p + 0x2b4) = lbl_8054227C;
    p[0x2b1] = 1;
}

extern "C" void* fn_80340C60(void* this_) {
    fn_801BB3B0(this_);
    *(void**)this_ = lbl_804AC3E0;
    *(s32*)((char*)this_ + 0x2b8) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
