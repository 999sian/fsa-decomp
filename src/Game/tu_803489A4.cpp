#include "Game/Actor.h"
#include "Game/ItemBase.h"


extern "C" char lbl_804AC7B8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_803489A4(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AC7B8;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" char lbl_804720B8[];
extern const f32 lbl_80542480;
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_80348A04(u8* this_) {
    DrawRec rec;
    rec.b1d = 1;
    rec.b1c = 1;
    s32 pos = *(s32*)(this_ + 0x23c);
    pos += *(s32*)(this_ + 0x248);
    fn_801F06F0(this_, lbl_804720B8, pos + 0x2c5, &rec, 1, lbl_80542480, lbl_80542480);
}

extern "C" void fn_80349628(u8* this_) {
    *(s32*)(this_ + 0x108) = 8;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x2a0) = 0.0f;
    *(f32*)(this_ + 0x29c) = 0.0f;
    *(f32*)(this_ + 0x298) = 0.0f;
    *(f32*)(this_ + 0x270) = 0.0f;
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x27c) = 0.0f;
    *(f32*)(this_ + 0x278) = 0.0f;
    *(f32*)(this_ + 0x274) = 0.0f;
    *(f32*)(this_ + 0x288) = 0.0f;
    *(f32*)(this_ + 0x284) = 0.0f;
    *(f32*)(this_ + 0x280) = 0.0f;
    *(f32*)(this_ + 0x294) = 0.0f;
    *(f32*)(this_ + 0x290) = 0.0f;
    *(f32*)(this_ + 0x28c) = 0.0f;
    *(f32*)(this_ + 0x258) = 5.0f;
    *(f32*)(this_ + 0x25c) = 32.0f;
    *(s32*)(this_ + 0x248) = 0;
    *(s16*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x234) = 0x78;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = -1;
    *(s32*)(this_ + 0x250) = -1;
    *(s32*)(this_ + 0x24c) = -1;
    this_[0x262] = 0;
    this_[0x263] = 0;
    this_[0x264] = 0;
    this_[0x265] = 0;
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(s32*)(this_ + 0x230) = 0;
}

