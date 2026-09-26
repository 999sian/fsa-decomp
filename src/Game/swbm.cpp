// SWBM actor. TU 8017A44C-8017B140.
// Functions: dtor, draw (slot 6, TODO), update (slot 3, TODO), helper (TODO), init (slot 1).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" s32 fn_80237060(s32 id);
extern "C" u32 fn_8023B630(s32 id);
extern void* lbl_804A1160[];

// SWBM destructor
extern "C" void* fn_8017A44C(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1160;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// SWBM init (vtable slot 1)
extern "C" void fn_8017AE18(char* this_) {
    *(f32*)(this_ + 0x80) = -2.0f;
    *(f32*)(this_ + 0x84) = -2.0f;
    *(f32*)(this_ + 0x88) = 2.0f;
    *(f32*)(this_ + 0x8c) = 2.0f;
    *(f32*)(this_ + 0x60) = -4.0f;
    *(f32*)(this_ + 0x64) = -4.0f;
    *(f32*)(this_ + 0x68) = 4.0f;
    *(f32*)(this_ + 0x6c) = 4.0f;
    *(u32*)(this_ + 0x98) = (*(u32*)(this_ + 0x90) >> 4) & 3;
    *(u32*)(this_ + 0x258) = *(u32*)(this_ + 0x90) & 0xf;
    *(u32*)(this_ + 0x25c) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    if (fn_80237060(*(s32*)(this_ + 0x258)) == 1) {
        *(u8*)(this_ + 0x11c) = 0;
        return;
    }
    *(u8*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(u32*)(this_ + 0x118) = fn_8023B630(*(s32*)(this_ + 0x258));
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(s32*)(this_ + 0x23c) = 2;
    *(s32*)(this_ + 0x230) = 0;
    fn_801F0E34(this_, 0x30026, 0);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
