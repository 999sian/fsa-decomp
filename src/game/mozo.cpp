// MOZO actor. TU 80166BD0-80167938.
// Functions: draw (slot 6, TODO), update (slot 3, TODO), init (slot 1),
// child release, dtor.
#include "types.h"

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A0668[];

// MOZO init (vtable slot 1)
extern "C" void fn_801675E0(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x108) = 4;
    *(s32*)(this_ + 0x250) = 0;
    *(f32*)(this_ + 0x25c) = 0.0f;
    *(f32*)(this_ + 0x258) = 1.0f;
    *(f32*)(this_ + 0x260) = 0.0f;
    *(f32*)(this_ + 0x264) = 0.0f;
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x254) = 255.0f;
    *(void**)(this_ + 0x26c) = 0;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0x230) = 0;
}

struct MozoChild { u8 pad[0x24]; s32 dead; u8 pad2[0xf4 - 0x28]; u32 flags; };

// MOZO: release linked child actor
extern "C" void fn_8016767C(char* this_) {
    MozoChild* c = *(MozoChild**)(this_ + 0x26c);
    if (c != 0) {
        c->flags |= 1;
        c->dead = 1;
        *(MozoChild**)(this_ + 0x26c) = 0;
    }
}

// MOZO destructor
extern "C" void* fn_801676A8(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0668;
        fn_801EE434(*(void**)(this_ + 0x26c));
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
