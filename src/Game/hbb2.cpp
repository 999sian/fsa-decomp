// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A8194-801A908C (HBB2). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_801A8194_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A2EC0[];

extern "C" void* fn_801A8194(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2EC0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct Hbb2Vec { f32 x, y, z; };
struct Hbb2 { u8 pad0[0xc]; Hbb2Vec pos; u8 pad18[0x27c - 0x18]; Hbb2Vec prev; Hbb2Vec prev2; Hbb2Vec trail[40]; };

// HBB2 init (vtable slot 1)
extern "C" void fn_801A8CB8(char* this_) {
    *(f32*)(this_ + 0x60) = -10.0f;
    *(f32*)(this_ + 0x64) = -10.0f;
    *(f32*)(this_ + 0x68) = 10.0f;
    *(f32*)(this_ + 0x6c) = 10.0f;
    *(f32*)(this_ + 0x80) = 0.0f;
    *(f32*)(this_ + 0x84) = 0.0f;
    *(f32*)(this_ + 0x88) = 0.0f;
    *(f32*)(this_ + 0x8c) = 0.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(f32*)(this_ + 0x270) = 72.0f;
    *(u8*)(this_ + 0x11e) = 1;
    *(f32*)(this_ + 0x26c) = 1.2f;
    *(f32*)(this_ + 0x274) = 255.0f;
    Hbb2* h = (Hbb2*)this_;
    h->prev.x = h->pos.x;
    h->prev.y = h->pos.y;
    h->prev.z = h->pos.z;
    h->prev2.x = h->pos.x;
    h->prev2.y = h->pos.y;
    h->prev2.z = h->pos.z;
    for (int i = 0; i < 40; i++) {
        h->trail[i].x = h->pos.x;
        h->trail[i].y = h->pos.y;
        h->trail[i].z = h->pos.z;
    }
    *(s16*)(this_ + 0x268) = 0;
    *(s32*)(this_ + 0x190) = 0;
    *(f32*)(this_ + 0x278) = 0.0f;
    *(s32*)(this_ + 0x264) = *(s32*)(this_ + 0x108);
    *(s32*)(this_ + 0x108) = 10000;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
