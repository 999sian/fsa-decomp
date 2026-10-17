#include "Game/Actor.h"


extern "C" char lbl_804AB170[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8031C050(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AB170;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" u8* lbl_8053AAF8;
extern const f32 lbl_805419B8;
extern const f32 lbl_805419BC;
extern const f32 lbl_80541A10;
extern const f32 lbl_80541A14;
extern const f32 lbl_80541A18;
extern const f32 lbl_80541A1C;
extern "C" void detach__5ActorFv(Actor* p);
extern "C" void fn_8031DD28(Actor* p) {
    u8* self = (u8*)p;
    u32 bits;
    u16 mode;

    *(u32*)(self + 0x268) = *(u32*)(self + 0x90) & 3;
    *(s16*)(self + 0x94) = (*(u32*)(self + 0x90) >> 16) & 0xff;
    *(u32*)(self + 0x254) = 0;
    *(u32*)(self + 0x258) = 0;
    *(u32*)(self + 0x25c) = 0;
    *(u32*)(self + 0x260) = 0;
    *(u32*)(self + 0x240) = 0;
    *(u32*)(self + 0x244) = 0;
    *(u32*)(self + 0x248) = 0;
    *(u32*)(self + 0x24c) = 0;
    *(u32*)(self + 0x250) = 0;
    *(u16*)(self + 0x274) = 0;
    *(u16*)(self + 0x276) = *(u16*)(self + 0x274);
    *(u32*)(self + 0x108) = 10000;
    *(s32*)(self + 0x264) = -1;
    *(u32*)(self + 0x98) = 0;
    *(f32*)(self + 0x288) = *(f32*)(self + 0xc);
    *(f32*)(self + 0x28c) = *(f32*)(self + 0x10);
    *(f32*)(self + 0x290) = *(f32*)(self + 0x14);
    *(s32*)(self + 0x260) = 100;
    *(f32*)(self + 0x238) = lbl_805419BC;
    *(f32*)(self + 0x23c) = lbl_805419B8;
    *(u8*)(self + 0x278) = 0;
    *(u32*)(self + 0x270) = *(u32*)(self + 0x4);
    *(f32*)(self + 0x234) = lbl_80541A10;

    {
        u8* rng = lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
    }
    *(s32*)(self + 0x25c) = (s32)(lbl_80541A14 * (*(f32*)&bits - lbl_805419BC));

    *(u32*)(self + 0xb0) = 0x2000a;
    *(f32*)(self + 0x29c) = lbl_805419B8;
    *(f32*)(self + 0x298) = lbl_805419B8;
    *(f32*)(self + 0x294) = lbl_805419B8;
    *(u32*)(self + 0x26c) = 0;

    mode = *(u16*)(self + 0x94);
    switch (mode) {
    case 0:
        *(u32*)(self + 0x268) = *(u32*)(self + 0x90) & 3;
        *(u32*)(self + 0x230) = 0;
        *(u8*)(self + 0x278) = 1;
        break;
    case 1:
        *(u32*)(self + 0x268) = *(u32*)(self + 0x90) & 3;
        *(u32*)(self + 0x230) = 4;
        break;
    case 2:
        *(u32*)(self + 0x230) = 8;
        break;
    }

    *(f32*)(self + 0x27c) = lbl_805419B8;
    *(f32*)(self + 0x280) = lbl_805419B8;
    *(f32*)(self + 0x284) = lbl_805419B8;
    *(f32*)(self + 0x3c) = lbl_805419B8;
    *(f32*)(self + 0x40) = lbl_805419B8;
    *(f32*)(self + 0x44) = lbl_805419B8;
    *(u32*)(self + 0xb8) = 1;
    *(f32*)(self + 0x80) = lbl_80541A18;
    *(f32*)(self + 0x84) = lbl_80541A18;
    *(f32*)(self + 0x88) = lbl_80541A1C;
    *(f32*)(self + 0x8c) = lbl_80541A1C;
    *(f32*)(self + 0x60) = lbl_80541A18;
    *(f32*)(self + 0x64) = lbl_80541A18;
    *(f32*)(self + 0x68) = lbl_80541A1C;
    *(f32*)(self + 0x6c) = lbl_80541A1C;

    if (*(lbl_8053AAF8 + 0x7f) == 0) {
        detach__5ActorFv(p);
    } else {
        *(u8*)(self + 0x194) = 1;
    }
}

