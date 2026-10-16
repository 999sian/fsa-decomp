#include "Game/Actor.h"


extern "C" char lbl_804AAA70[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8030FD60(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AAA70;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8030FDC0(char* p, s32 v) {
    *(s32*)(p + 0x25c) = v;
    *(s32*)(p + 0x234) = 0x3c;
    *(s32*)(p + 0x230) = 6;
}

extern "C" void* fn_801F856C(void);
extern char* lbl_8053AAF8;
extern f32 lbl_8054178C;
extern "C" char lbl_80471420[];
extern "C" f32 lbl_8054177C;
extern "C" void fn_801F06F0(void* a, void* p2, s32 idx, void* p4, s32 p5, f32 f1, f32 f2);
extern "C" void fn_80307AC8(void* obj, u32 id, void* pos, u32 kind, u32 a, u32 b, s32 c);
extern "C" void fn_8030FDD8(char* p) {
    if (*(u8*)(p + 0x288)) {
        f32 f = lbl_8054177C;
        fn_801F06F0(p, lbl_80471420, *(s32*)(p + 0x240) + 0x12c, 0, 0, f, f);
        fn_80307AC8(*(void**)(p + 0x198), *(u32*)(p + 0x4), p + 0xc, *(s32*)(p + 0x240) + 0x12c, 0, 0, -1);
    } else {
        s32 n = *(s32*)(p + 0x238);
        fn_801F06F0(p, lbl_80471420, *(s32*)(p + 0x240) + (n * 2) + 0xec, 0, 0, lbl_8054177C, lbl_8054177C);
        n = *(s32*)(p + 0x238);
        fn_80307AC8(*(void**)(p + 0x198), *(u32*)(p + 0x4), p + 0xc, *(s32*)(p + 0x240) + (n * 2) + 0xec, 0, 0, -1);
    }
}

extern f32 lbl_80541790;
extern f32 lbl_80541794;
extern char* lbl_8053AAF8;
extern u8 lbl_80529DEC[];
extern "C" void fn_80310A9C(char* p)
{
    f32 b = lbl_80541794;
    f32 a = lbl_80541790;

    *(f32*)(p + 0x60) = a;
    *(f32*)(p + 0x64) = a;
    *(f32*)(p + 0x68) = b;
    *(f32*)(p + 0x6c) = b;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x248) = -1;
    *(s32*)(p + 0x264) = *(u32*)(p + 0x90) >> 31;
    if (*(u32*)(p + 0x264) != 0) {
        *(s32*)(p + 0x260) = 300;
    } else {
        *(s32*)(p + 0x260) = 100;
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(s32*)(p + 0x254) = -1;
    *(s32*)(p + 0x258) = -1;
    *(u32*)(p + 0x26c) = *(u32*)(p + 0x90) & 0xf;
    *(u32*)(p + 0x270) = *(u32*)(p + 0x26c) + ((*(u32*)(p + 0x90) >> 4) & 0xf);
    *(u32*)(p + 0x274) = *(u32*)(p + 0x270) + ((*(u32*)(p + 0x90) >> 8) & 0xf);
    *(s32*)(p + 0x25c) = -1;
    *(u32*)(p + 0x268) = (*(u32*)(p + 0x90) >> 24) & 0xf;
    *(s32*)(p + 0x278) = 0;
    *(s32*)(p + 0x27c) = 0;
    *(s32*)(p + 0x280) = 0;
    *(s32*)(p + 0x284) = 0;
    if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0 && *(s32*)(lbl_80529DEC + 0x118) == 1 && *(s32*)(lbl_80529DEC + 0x11c) == 1) {
        *(u8*)(p + 0x288) = 1;
    } else {
        *(u8*)(p + 0x288) = 0;
    }
    *(s32*)(p + 0x238) = 2;
    *(s32*)(p + 0x23c) = 0x14;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
}

