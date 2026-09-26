// Game TU 801D2C60-801D3320 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A48B0[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_801D0F40(void* this_);

extern "C" void* dtor_801D2C60(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A48B0;
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

extern "C" s32 fn_801CF0F4(void* this_);
extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_801F0E34(void* this_, u32 id, u32 c);
extern "C" void fn_801CB538(u32 id, void* pos, u32 a, u32 b);
extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_801F2A10(void* this_, s32 a, s32 b, u32 c, u32 d);
extern "C" u8 fn_801F2B7C(void* this_, u32 a, s32 b, u32 c);
extern "C" void fn_801CE4BC(void* this_);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801D2608(void* obj, void* tbl, u32 n);
extern "C" void fn_801D22DC(void* obj, u32 a, u32 b, u32 c);
extern "C" void fn_801D1D60(void* obj);
extern u8 lbl_80469474[];
extern u8 lbl_8053A130[8];
extern const f32 lbl_8053F068;
extern const f32 lbl_8053F06C;
extern const f32 lbl_8053F070;
extern const f32 lbl_8053F074;
extern const f32 lbl_8053F078;

extern "C" void fn_801D2CF0(u8* this_, const JGeometry::TVec2<f32>& vel) {
    *(f32*)(this_ + 0x3c) = vel.x;
    *(f32*)(this_ + 0x40) = vel.y;
    *(f32*)(this_ + 0x44) = lbl_8053F068;
    *(s32*)(this_ + 0x98) = fn_801CF0F4(this_);
}

extern "C" void fn_801D2D38(u8* this_) {
    DrawRec rec;
    rec.w30 = 0xc;
    rec.b1d = 1;
    fn_801F06F0(this_, lbl_80469474, *(u32*)(this_ + 0x280) + 0xd5, &rec, -1, lbl_8053F06C, lbl_8053F06C);
}

extern "C" void fn_801D2E70(u8* this_) {
    if (this_[0x2a8] != 0) {
        this_[0x2a8]--;
        if (this_[0x2a8] == 0) {
            fn_801F0E34(this_, 0x400d1, 0);
            fn_801CB538(*(u32*)(this_ + 0x4), this_ + 0xc, 0, 0);
            this_[0x11c] = 0;
        }
    } else {
        s32 idx = *(s32*)(this_ + 0x4);
        u8* mgr = fn_802D6A9C();
        f32* r;
        if (idx < 8) {
            r = (f32*)(mgr + 0xcc);
        } else {
            r = (f32*)(mgr + 0xdc);
        }
        if (!ItemBase_inArea(r, (f32*)(this_ + 0xc))) {
            this_[0x11c] = 0;
        } else if (fn_801F2A10(this_, -1, *(s32*)(this_ + 0x98), 0, 0)) {
            this_[0x2a8] = 2;
        } else if (fn_801F2B7C(this_, *(u32*)(this_ + 0x114), -1, 1)) {
            this_[0x11c] = 0;
        }
    }
    if (this_[0x11c] != 0) {
        ((JGeometry::TVec3<f32>*)(this_ + 0xc))->add(*(JGeometry::TVec3<f32>*)(this_ + 0x3c));
    }
    fn_801CE4BC(this_);
}

extern "C" void fn_801D2FEC(u8* this_) {
    fn_801D0ED0(this_);
    f32 a = lbl_8053F070;
    f32 c = lbl_8053F06C;
    f32 b = lbl_8053F074;
    f32 d = lbl_8053F078;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = a;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = b;
    *(f32*)(this_ + 0x70) = c;
    *(f32*)(this_ + 0x74) = c;
    *(f32*)(this_ + 0x78) = d;
    *(f32*)(this_ + 0x7c) = d;
    *(f32*)(this_ + 0x80) = c;
    *(f32*)(this_ + 0x84) = c;
    *(f32*)(this_ + 0x88) = d;
    *(f32*)(this_ + 0x8c) = d;
    *(u32*)(this_ + 0xb0) = 0;
    *(u32*)(this_ + 0x230) |= 0x280;
    *(u32*)(this_ + 0x108) = 1000;
    *(u32*)(this_ + 0x244) = *(u32*)(this_ + 0x108);
    this_[0x194] = 1;
    *(u32*)(this_ + 0x114) = 2;
    fn_801D2608(this_ + 0x270, lbl_8053A130, 1);
    fn_801D22DC(this_ + 0x270, 0, 2, 0);
    fn_801D1D60(this_ + 0x270);
}

extern "C" void* fn_801D30B8(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A48B0;
    *(u8*)((char*)this_ + 0x2a8) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
