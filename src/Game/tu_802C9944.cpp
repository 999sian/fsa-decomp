#include "Game/Actor.h"


extern "C" char lbl_804A8EF8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802C9944(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A8EF8;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern const f32 lbl_80540D84;
extern const f64 lbl_80540D78;
extern "C" void fn_802C9F48(u8* this_) {
    *(u32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xff;
    *(u32*)(this_ + 0x238) = ((*(u32*)(this_ + 0x90) >> 8) & 0xff) + 1;
    *(u32*)(this_ + 0x23c) = ((*(u32*)(this_ + 0x90) >> 16) & 0xff) + 1;
    if (*(u32*)(this_ + 0x90) & 0x1000000) {
        this_[0x240] = 1;
    } else {
        this_[0x240] = 0;
    }
    if (*(u32*)(this_ + 0x90) & 0x2000000) {
        this_[0x241] = 1;
    } else {
        this_[0x241] = 0;
    }
    f32 fVar2 = (f32)(s32)((*(s32*)(this_ + 0x23c) << 3) >> 1);
    fVar2 -= lbl_80540D84;
    f32 fVar1 = (f32)(s32)((*(s32*)(this_ + 0x238) << 3) >> 1);
    fVar1 -= lbl_80540D84;
    *(f32*)(this_ + 0x60) = -fVar1;
    *(f32*)(this_ + 0x64) = -fVar2;
    *(f32*)(this_ + 0x68) = fVar1;
    *(f32*)(this_ + 0x6c) = fVar2;
    if (*(u32*)(this_ + 0x90) & 0x4000000) {
        this_[0x242] = 1;
        *(u32*)(this_ + 0x230) = 4;
    } else {
        this_[0x242] = 0;
        *(u32*)(this_ + 0x230) = 0;
    }
    *(u32*)(this_ + 0x244) = 0xff;
}

