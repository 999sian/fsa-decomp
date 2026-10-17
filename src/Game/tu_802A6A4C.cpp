#include "Game/Actor.h"


extern "C" char lbl_804A7F38[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802A6A4C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A7F38;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void* lbl_8053AC98;
extern "C" void fn_802A3948(void* mgr, void* pos, s32 player, u32 room, s32 id);
extern "C" void fn_802A6AAC(Actor* p, s32 player) {
    switch (*(u16*)((u8*)p + 0x258)) {
    case 0x41:
    case 0x12:
    case 0x68:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x13);
        break;
    case 0x50:
    case 0x43:
    case 0x6a:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x51);
        break;
    case 0x14:
    case 0x52:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x15);
        break;
    case 0x15a:
        fn_802A3948(lbl_8053AC98, (u8*)p + 0xc, player, p->field_04, 0x360);
        break;
    }
}

extern "C" void fn_802A6BC0(void) {}

extern f32 lbl_80540804;
extern f32 lbl_80540808;
extern f32 lbl_8054080C;
extern f32 lbl_80540810;
extern "C" void fn_802A7978(Actor* p) {
    u8* base = (u8*)p;
    f32 k;
    f32 c;
    f32 d;
    s32 v;

    *(u32*)(base + 0x238) = ((*(u32*)(base + 0x90) >> 0x16) & 0x1f) + 1;
    *(u32*)(base + 0x23c) = ((*(u32*)(base + 0x90) >> 0x11) & 0x1f) + 1;
    *(u32*)(base + 0x240) = *(u32*)(base + 0x90) & 0x3e0;
    *(u32*)(base + 0x234) = *(u32*)(base + 0x90) & 0x1f;
    *(s32*)(base + 0x264) = (*(u32*)(base + 0x90) >> 0xc) & 0x1f;
    if (*(s32*)(base + 0x264) == 0) {
        *(s32*)(base + 0x264) = -1;
    }
    *(u32*)(base + 0x25c) = *(u32*)(base + 0x90) >> 0x1b;
    if (*(s32*)(base + 0x234) == 8 && *(s32*)(base + 0x240) == 0) {
        *(s32*)(base + 0x240) = 0x3c;
    }
    v = *(s32*)(base + 0x240);
    k = lbl_80540804;
    *(s32*)(base + 0x24c) = v;
    *(f32*)(base + 0xc) = *(f32*)(base + 0xc) + k;
    *(f32*)(base + 0x10) = *(f32*)(base + 0x10) + k;
    if (*(s32*)(base + 0x234) == 2 || *(s32*)(base + 0x234) == 3) {
        d = lbl_8054080C;
        c = lbl_80540808;
        *(f32*)(base + 0x60) = c;
        *(f32*)(base + 0x64) = c;
        *(f32*)(base + 0x68) = d;
        *(f32*)(base + 0x6c) = d;
    } else if (*(s32*)(base + 0x234) == 7) {
        f32 a = lbl_80540810 * (f32)*(s32*)(base + 0x238);
        f32 b = lbl_80540810 * (f32)*(s32*)(base + 0x23c);
        *(f32*)(base + 0x60) = -a;
        *(f32*)(base + 0x64) = -b;
        *(f32*)(base + 0x68) = a;
        *(f32*)(base + 0x6c) = b;
    } else {
        d = lbl_8054080C;
        c = lbl_80540808;
        *(f32*)(base + 0x60) = c;
        *(f32*)(base + 0x64) = c;
        *(f32*)(base + 0x68) = d;
        *(f32*)(base + 0x6c) = d;
    }
    *(s32*)(base + 0x248) = 0;
    if (*(s32*)(base + 0x234) == 4 || *(s32*)(base + 0x234) == 7) {
        *(s32*)(base + 0x230) = 2;
    } else {
        *(s32*)(base + 0x230) = 1;
    }
    *(s32*)(base + 0x250) = -1;
    *(s32*)(base + 0x260) = -1;
}

