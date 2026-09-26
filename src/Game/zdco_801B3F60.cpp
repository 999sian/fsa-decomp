// Game TU 801B3F60-801B4D0C (ZDCO). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
extern const f32 lbl_8053EA08;
extern const f32 lbl_8053E9EC;
extern const f32 lbl_8053E9C0;

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A375C[];
extern "C" {
}

extern "C" void* fn_801B3F60(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A375C;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801B3FC0(void) {}

extern "C" void fn_801B49DC(u8* this_) {
    *(f32*)(this_ + 0x60) = lbl_8053EA08;
    *(f32*)(this_ + 0x64) = lbl_8053EA08;
    *(f32*)(this_ + 0x68) = lbl_8053E9EC;
    *(f32*)(this_ + 0x6c) = lbl_8053E9EC;
    *(f32*)(this_ + 0x70) = lbl_8053EA08;
    *(f32*)(this_ + 0x74) = lbl_8053EA08;
    *(f32*)(this_ + 0x78) = lbl_8053E9EC;
    *(f32*)(this_ + 0x7c) = lbl_8053E9EC;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x250) = *(u32*)(this_ + 0x90) & 0xff;
    *(s32*)(this_ + 0x254) = (*(u32*)(this_ + 0x90) >> 22) & 0x1f;
    *(s32*)(this_ + 0x258) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(s32*)(this_ + 0x24c) = 0;
    *(f32*)(this_ + 0x26c) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x270) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x274) = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x44) = lbl_8053E9C0;
    *(f32*)(this_ + 0x40) = lbl_8053E9C0;
    *(f32*)(this_ + 0x3c) = lbl_8053E9C0;
    *(s32*)(this_ + 0x25c) = 0;
    *(u16*)(this_ + 0x94) = 0;
    this_[0x1a8] = 0;
    switch (*(s32*)(this_ + 0x250)) {
    case 0:
        *(s32*)(this_ + 0x230) = 0;
        break;
    case 2:
        *(s32*)(this_ + 0x230) = 1;
        break;
    case 1:
        *(s32*)(this_ + 0x230) = 2;
        break;
    case 3:
    case 7:
        *(s32*)(this_ + 0x230) = 4;
        break;
    default:
        *(s32*)(this_ + 0x230) = 10;
        break;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
