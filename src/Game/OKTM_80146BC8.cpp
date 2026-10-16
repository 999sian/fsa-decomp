#include "types.h"
#include "Game/Actor.h"

extern "C" char lbl_8049F5D8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80146BC8(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_8049F5D8;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_80147834(char* this_) {
    *(f32*)(this_ + 0x60) = -2.0f;
    *(f32*)(this_ + 0x64) = -2.0f;
    *(f32*)(this_ + 0x68) = 2.0f;
    *(f32*)(this_ + 0x6c) = 2.0f;
    *(f32*)(this_ + 0x80) = -2.0f;
    *(f32*)(this_ + 0x84) = -2.0f;
    *(f32*)(this_ + 0x88) = 2.0f;
    *(f32*)(this_ + 0x8c) = 2.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x234) = 300;
    *(s32*)(this_ + 0x98) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(u32*)(this_ + 0x248) = 0xff;
    if (*(s32*)(this_ + 0x90) == 3) {
        *(f32*)(this_ + 0x60) = -6.0f;
        *(f32*)(this_ + 0x64) = -6.0f;
        *(f32*)(this_ + 0x68) = 6.0f;
        *(f32*)(this_ + 0x6c) = 6.0f;
        *(f32*)(this_ + 0x80) = -6.0f;
        *(f32*)(this_ + 0x84) = -6.0f;
        *(f32*)(this_ + 0x88) = 6.0f;
        *(f32*)(this_ + 0x8c) = 6.0f;
    }
    switch (*(s32*)(this_ + 0x90)) {
    case 5:
        *(s32*)(this_ + 0x234) = 10000;
        *(s32*)(this_ + 0x23c) = 300;
    case 1:
        *(s32*)(this_ + 0xb0) = 6;
        break;
    case 2:
        *(s32*)(this_ + 0x238) = 3;
        *(f32*)(this_ + 0x14) = 8.0f;
        *(s32*)(this_ + 0xb0) = 7;
        break;
    }
    *(s32*)(this_ + 0x230) = 0;
}

