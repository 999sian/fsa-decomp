// Game TU 801D7AFC-801D8400 (BGBL). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" bool fn_801CD2F8(s32 id);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);

extern "C" void fn_801D7AFC(u8* this_) {
    if (((JGeometry::TVec3<f32>*)(this_ + 0x54))->isZero() == false && fn_801CD2F8(*(s32*)(this_ + 4))) {
        fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xC,
                    *(s32*)(this_ + 0x280) + 0x1C7, 0, 2, -1, 1, 0, 0);
    }
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A4BB0[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_801D0F40(void* this_);

struct BGBL_Part {
    u8 pad0[0x98];
    f32 m98, m9C, mA0;
    u8 padA4[0xB0 - 0xA4];
    f32 mB0, mB4;
};

static inline void BGBL_syncPart(u8* this_, BGBL_Part* part) {
    if (part != 0) {
        part->m98 = *(f32*)(this_ + 0x54);
        part->m9C = *(f32*)(this_ + 0x58);
        part->mA0 = *(f32*)(this_ + 0x5C);
        f32 y = *(f32*)(this_ + 0x58);
        f32 x = *(f32*)(this_ + 0x54);
        part->mB0 = x;
        part->mB4 = y;
    }
}

static inline void BGBL_setScale(u8* this_, f32 s) {
    *(f32*)(this_ + 0x54) = s;
    *(f32*)(this_ + 0x58) = s;
    *(f32*)(this_ + 0x5C) = s;
    *(f32*)(this_ + 0x60) = -3.0f * s;
    *(f32*)(this_ + 0x64) = -3.0f * s;
    *(f32*)(this_ + 0x68) = 3.0f * s;
    *(f32*)(this_ + 0x6C) = 3.0f * s;
    *(f32*)(this_ + 0x70) = -6.0f * s;
    *(f32*)(this_ + 0x74) = -6.0f * s;
    *(f32*)(this_ + 0x78) = 6.0f * s;
    *(f32*)(this_ + 0x7C) = 6.0f * s;
    BGBL_syncPart(this_, *(BGBL_Part**)(this_ + 0x2A8));
    BGBL_syncPart(this_, *(BGBL_Part**)(this_ + 0x2AC));
}

extern "C" void fn_801D7DB4(u8* this_, f32 s) {
    BGBL_setScale(this_, s);
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void* fn_8013CC50(s32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern char lbl_8053A140[8];

extern "C" void fn_801D7E6C(u8* this_) {
    fn_801D0ED0(this_);
    *(f32*)(this_ + 0x60) = 1.0f;
    *(f32*)(this_ + 0x64) = 1.0f;
    *(f32*)(this_ + 0x68) = -1.0f;
    *(f32*)(this_ + 0x6C) = -1.0f;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7C) = *(f32*)(this_ + 0x6C);
    *(f32*)(this_ + 0x80) = 1.0f;
    *(f32*)(this_ + 0x84) = 1.0f;
    *(f32*)(this_ + 0x88) = -1.0f;
    *(f32*)(this_ + 0x8C) = -1.0f;
    *(s32*)(this_ + 0xB0) = 4;
    *(s32*)(this_ + 0x98) = 2;
    *(u32*)(this_ + 0x230) |= 0x300;
    *(s32*)(this_ + 0x114) = 2;
    *(u8*)(this_ + 0x194) = 1;
    if (fn_801CD2F8(*(s32*)(this_ + 4))) {
        fn_801D2608(this_ + 0x270, lbl_8053A140, 1);
        fn_801D22DC(this_ + 0x270, 0, 2, 0);
    } else {
        *(void**)(this_ + 0x2A8) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xC, 0x226, 1, 2, 0, 0, 1, 1.0f);
        *(void**)(this_ + 0x2AC) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xC, 0x227, 1, 2, 0, 0, 1, 1.0f);
    }
    if (fn_801CD2F8(*(s32*)(this_ + 4))) {
        BGBL_setScale(this_, 1.0f);
    } else {
        BGBL_setScale(this_, 0.0f);
    }
}

extern "C" void* fn_801D80F0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A4BB0;
        fn_801EE434(*(void**)(p + 0x2a8));
        fn_801EE434(*(void**)(p + 0x2ac));
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801D8194(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A4BB0;
    *(int*)((char*)this_ + 0x2a8) = 0;
    *(int*)((char*)this_ + 0x2ac) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
