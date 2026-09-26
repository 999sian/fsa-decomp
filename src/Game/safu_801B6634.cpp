// Game TU 801B6634-801B6C50 (SAFU). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A3948[];

extern "C" void* fn_801B6634(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A3948;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F71A4(f32* v, f32 a, f32 b, f32 c);
extern const f32 lbl_8053EA98;
extern const f32 lbl_8053EA9C;
extern const f32 lbl_8053EAA0;
extern const f32 lbl_8053EAA4;
extern const f32 lbl_8053EAA8;
extern const f32 lbl_8053EAAC;
extern const f32 lbl_8053EAB0;
extern const f32 lbl_8053EAB4;
extern const f32 lbl_8053EAB8;
extern const f32 lbl_8053EABC;

extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, void* p5, f32 a, f32 b);
extern "C" void fn_803075AC(void* obj, u32 id, void* pos, u32 kind, u32 a, u32 b, s32 c, u32 d, u32 e, u32 f);
extern u8 lbl_80469120[];

extern "C" void fn_801B6694(u8* this_) {
    DrawRec rec;
    f32 mtx[3][4];
    f32 zero = lbl_8053EA98;
    mtx[0][3] = zero;
    mtx[1][3] = zero;
    mtx[2][3] = zero;
    f32 sy = *(f32*)(this_ + 0x25c);
    mtx[0][0] = *(f32*)(this_ + 0x258);
    mtx[0][1] = zero;
    mtx[0][2] = zero;
    mtx[1][0] = zero;
    mtx[1][1] = sy;
    mtx[1][2] = zero;
    mtx[2][0] = zero;
    mtx[2][1] = zero;
    mtx[2][2] = sy;
    rec.w18 = mtx;
    rec.b1c = 1;
    rec.b1d = 1;
    rec.b20 = 0;
    rec.b2d = 1;
    fn_801F06F0(this_, lbl_80469120, 0xe6, &rec, 0, lbl_8053EA9C, lbl_8053EA9C);
    fn_803075AC(*(void**)(this_ + 0x198), *(u32*)(this_ + 0x4), this_ + 0xc, 0xe6, 0, 2, -1, 0, 0, 1);
}

extern "C" void fn_801B6854(u8* this_) {
    fn_801F71A4((f32*)(this_ + 0x3c), *(f32*)(this_ + 0x24c), lbl_8053EAA0, lbl_8053EA9C);
    fn_801F71A4((f32*)(this_ + 0x40), *(f32*)(this_ + 0x250), lbl_8053EAA0, lbl_8053EA9C);
    fn_801F71A4((f32*)(this_ + 0x258), *(f32*)(this_ + 0x264), lbl_8053EAA4, lbl_8053EAA8);
    fn_801F71A4((f32*)(this_ + 0x25c), *(f32*)(this_ + 0x268), lbl_8053EAA4, lbl_8053EAA8);
    ((JGeometry::TVec3<f32>*)(this_ + 0xc))->add(*(JGeometry::TVec3<f32>*)(this_ + 0x3c));
    switch (*(s32*)(this_ + 0x230)) {
    case 2:
        break;
    case 0:
        if (*(u16*)(this_ + 0x94) == 0) {
            break;
        }
        *(u16*)(this_ + 0x94) = 0;
        *(f32*)(this_ + 0x44) = lbl_8053EAAC;
        *(s32*)(this_ + 0x230) = 1;
        break;
    case 1:
        if (*(f32*)(this_ + 0x14) < lbl_8053EA98) {
            *(f32*)(this_ + 0x258) = lbl_8053EAB0;
            *(f32*)(this_ + 0x25c) = lbl_8053EAB4;
            *(f32*)(this_ + 0x260) = lbl_8053EA9C;
            *(f32*)(this_ + 0x14) = lbl_8053EA98;
            *(f32*)(this_ + 0x44) = lbl_8053EA98;
            *(s32*)(this_ + 0x230) = 2;
        }
        break;
    }
    for (s32 i = 0; i < 3; i++) {
        s32* t = (s32*)(this_ + i * 4);
        if (t[0x234 / 4] > 0) {
            t[0x234 / 4]--;
        }
    }
}

extern "C" void fn_801B69AC(u8* this_) {
    f32 b = lbl_8053EABC;
    f32 a = lbl_8053EAB8;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = a;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = b;
    *(f32*)(this_ + 0x80) = a;
    *(f32*)(this_ + 0x84) = a;
    *(f32*)(this_ + 0x88) = b;
    *(f32*)(this_ + 0x8c) = b;
    *(u32*)(this_ + 0x240) = 0;
    *(u32*)(this_ + 0x244) = 0;
    *(u32*)(this_ + 0x248) = 0;
    *(u32*)(this_ + 0x234) = 0;
    *(u32*)(this_ + 0x238) = 0;
    *(u32*)(this_ + 0x23c) = 0;
    *(f32*)(this_ + 0x258) = lbl_8053EA9C;
    *(f32*)(this_ + 0x25c) = lbl_8053EA9C;
    *(f32*)(this_ + 0x260) = lbl_8053EA9C;
    *(f32*)(this_ + 0x264) = lbl_8053EA9C;
    *(f32*)(this_ + 0x268) = lbl_8053EA9C;
    *(f32*)(this_ + 0x26c) = lbl_8053EA9C;
    *(f32*)(this_ + 0x254) = lbl_8053EA98;
    *(f32*)(this_ + 0x250) = lbl_8053EA98;
    *(f32*)(this_ + 0x24c) = lbl_8053EA98;
    *(u32*)(this_ + 0x230) = 0;
    this_[0x11f] = 1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
