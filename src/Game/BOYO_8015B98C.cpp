// BOYO_8015B98C: .text 0x8015B98C-0x8015C828 (actor BOYO)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

// ---- from Game/fn_8015B98C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A0260[];

extern "C" void* fn_8015B98C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0260;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" u16 fn_801F6874(s32 dir);
extern const f32 lbl_8053D4B8;
extern const f32 lbl_8053D518;
extern const f32 lbl_8053D51C;

extern "C" void fn_8015C42C(char* this_) {
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(f32*)(this_ + 0x260) = *(f32*)(this_ + 0x264) = *(f32*)(this_ + 0x268) = lbl_8053D4B8;
    *(s16*)(this_ + 0x94) = 0;
    *(s32*)(this_ + 0x98) = (*(u32*)(this_ + 0x90) >> 8) & 3;
    *(s32*)(this_ + 0x238) = (*(u32*)(this_ + 0x90) >> 16) & 1;
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 7;
    *(s16*)(this_ + 0x25c) = 0;
    *(f32*)(this_ + 0x24) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x28) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2c) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0xb8) = 2;
    *(s32*)(this_ + 0x258) = 0;
    *(JGeometry::TVec3<f32>*)(this_ + 0x26c) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
    *(s32*)(this_ + 0x24c) = fn_801F6874(*(s32*)(this_ + 0x98));
    *(s32*)(this_ + 0x250) = 100;
    *(f32*)(this_ + 0x234) = lbl_8053D4B8;
    if (*(u32*)(this_ + 0x90) == 2 || *(u32*)(this_ + 0x90) == 3) {
        *(f32*)(this_ + 0x234) = lbl_8053D518;
        *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x234) * JMASSin(*(s32*)(this_ + 0x24c)) + *(f32*)(this_ + 0x26c);
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x234) * JMASCos(*(s32*)(this_ + 0x24c)) + *(f32*)(this_ + 0x270);
    }
    if (*(u32*)(this_ + 0x90) == 4 || *(u32*)(this_ + 0x90) == 5) {
        *(f32*)(this_ + 0x234) = lbl_8053D51C;
        *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x234) * JMASSin(*(s32*)(this_ + 0x24c)) + *(f32*)(this_ + 0x26c);
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x234) * JMASCos(*(s32*)(this_ + 0x24c)) + *(f32*)(this_ + 0x270);
    }
    if (*(u32*)(this_ + 0x90) == 2 || *(u32*)(this_ + 0x90) == 4) {
        *(s32*)(this_ + 0x250) = -100;
    }
    if (*(s32*)(this_ + 0x238) != 0) {
        *(s32*)(this_ + 0x250) <<= 1;
    }
    *(s32*)(this_ + 0xbc) = 4;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
