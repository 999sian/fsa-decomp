#include "Game/Actor.h"


extern "C" char lbl_804A7A10[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8028C068(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804A7A10;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern void* lbl_8053AC98;
extern "C" void fn_8029E928(void* sys, void* pos, u32 tag, s32 id);
extern "C" void fn_8028C0C8(u8* this_) {
    s32 x;

    x = (s32)*(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0xc) = (f32)((x + 4) / 8 * 8);
    x = (s32)*(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x10) = (f32)((x + 4) / 8 * 8);
    if ((*(u32*)(this_ + 0x90) & 3) == 0) {
        fn_8029E928(lbl_8053AC98, this_ + 0xc, *(u32*)(this_ + 0x4), 0x20);
    }
    *(u8*)(this_ + 0x11c) = 0;
}

extern "C" s16 fn_8022461C(float*);
extern "C" int fn_8028D470(Actor* this_, int a, float* b) {
    if ((s32)(u16)fn_8022461C(b) == 0xd) {
        return 0;
    }
    return this_->Actor::v17(a, b);
}

