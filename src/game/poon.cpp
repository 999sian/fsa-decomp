// Poon actor ("Poon" actor id, mixed case in the table). TU 80167938-801688AC.
// Functions: dtor, draw (slot 6, TODO), update (slot 3, TODO), init (slot 1).
#include "types.h"

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A06C0[];

// Poon destructor
extern "C" void* fn_80167938(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A06C0;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct PoonVec { f32 x, y, z; };

// Poon init (vtable slot 1)
extern "C" void fn_801685C8(char* this_) {
    *(f32*)(this_ + 0x60) = -6.0f;
    *(f32*)(this_ + 0x64) = -6.0f;
    *(f32*)(this_ + 0x68) = 6.0f;
    *(f32*)(this_ + 0x6c) = 6.0f;
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
    *(s32*)(this_ + 0x250) = 0;
    *(f32*)(this_ + 0x278) = 0.2f;
    *(f32*)(this_ + 0x27c) = 0.2f;
    *(f32*)(this_ + 0x280) = 0.2f;
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x270) = 0.0f;
    *(f32*)(this_ + 0x274) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(u8*)(this_ + 0x25c) = 0;
    *(f32*)(this_ + 0x254) = 1.0f;
    ((PoonVec*)(this_ + 0x260))->x = ((PoonVec*)(this_ + 0xc))->x;
    ((PoonVec*)(this_ + 0x260))->y = ((PoonVec*)(this_ + 0xc))->y;
    ((PoonVec*)(this_ + 0x260))->z = ((PoonVec*)(this_ + 0xc))->z;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0xb8) = 1;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
