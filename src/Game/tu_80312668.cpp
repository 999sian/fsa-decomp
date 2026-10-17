#include "Game/esd/types.h"
#include "Game/Actor.h"
#include "Game/ItemBase.h"

extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" u8 fn_802ED7F0(char* p, f32 v);
extern "C" u8 lbl_804714C0[];
extern f32 lbl_805417E8;
extern f32 lbl_805417EC;
extern f32 lbl_805417F0;
extern f32 lbl_805417F4;
extern f32 lbl_805417F8;


extern "C" char lbl_804AABA8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void __dl__FPv(void*);
extern "C" Actor* fn_80312668(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AABA8;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" u8* fn_801F856C(void);
extern f32 lbl_80541800;
extern f32 lbl_80541804;
extern f32 lbl_8054185C;
extern f32 lbl_80541860;
extern f32 lbl_80541864;
extern f32 lbl_80541868;
extern f32 lbl_8054186C;
extern f32 lbl_80541810;
extern "C" void fn_803137D0(Actor* p) {
    u8* base = (u8*)fn_801F856C();
    s32 count = *(s32*)(base + 0x1008);
    s32 off;
    s32 i;
    i = 0;
    off = 0;
    while (i < count) {
        u8* other = *(u8**)((u8*)fn_801F856C() + off + 8);
        if (other != 0 && *(u32*)(other + 0x1a0) == 0x474e4546) {
            *(s32*)((u8*)p + 0x278) = i;
            *(f32*)((u8*)p + 0xc) = *(f32*)(other + 0xc);
            *(f32*)((u8*)p + 0x10) = *(f32*)(other + 0x10);
        }
        off += 4;
        i++;
    }
    {
        f32 a = lbl_8054185C;
        f32 b = lbl_80541860;
        *(f32*)((u8*)p + 0x24c) = a;
        f32 c = lbl_80541864;
        *(f32*)((u8*)p + 0x250) = b;
        f32 d = lbl_80541868;
        *(f32*)((u8*)p + 0x254) = c;
        *(f32*)((u8*)p + 0x258) = d;
    }
    *(f32*)((u8*)p + 0x24c) += *(f32*)((u8*)p + 0xc);
    *(f32*)((u8*)p + 0x250) += *(f32*)((u8*)p + 0x10);
    *(f32*)((u8*)p + 0x254) += *(f32*)((u8*)p + 0xc);
    *(f32*)((u8*)p + 0x258) += *(f32*)((u8*)p + 0x10);
    {
        s8 v = (s8)((*(u32*)((u8*)p + 0x90) >> 12) & 0xff);
        if (v == 0) {
            *(f32*)((u8*)p + 0x25c) = *(f32*)((u8*)p + 0xc) - lbl_80541800;
        } else {
            *(f32*)((u8*)p + 0x25c) = *(f32*)((u8*)p + 0xc) + (f32)v;
        }
    }
    {
        s8 v = (s8)((*(u32*)((u8*)p + 0x90) >> 4) & 0xff);
        if (v == 0) {
            *(f32*)((u8*)p + 0x260) = lbl_80541804 + (lbl_8054186C + *(f32*)((u8*)p + 0x10));
        } else {
            *(f32*)((u8*)p + 0x260) = *(f32*)((u8*)p + 0x10) + (f32)v;
        }
    }
    {
        f32 c2 = lbl_80541810;
        *(f32*)((u8*)p + 0x264) = c2;
        *(f32*)((u8*)p + 0x268) = *(f32*)((u8*)p + 0xc);
        *(f32*)((u8*)p + 0x26c) = *(f32*)((u8*)p + 0x10);
        *(f32*)((u8*)p + 0x270) = c2;
    }
}

extern "C" f32 lbl_80541878;
extern "C" f32 lbl_80541810;
extern "C" f32 lbl_8054187C;
extern "C" void fn_80313988(u8* p) {
    f32 a = lbl_80541878;
    f32 b = lbl_80541810;
    *(f32*)(p + 0x14) = a;
    f32 c = lbl_8054187C;
    *(f32*)(p + 0x44) = b;
    *(f32*)(p + 0x284) = c;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 3;
    *(u32*)(p + 0x238) = 0x78;
    *(u32*)(p + 0x23c) = *(u32*)(p + 0x90) >> 27;
    *(s32*)(p + 0x244) = -1;
    *(s32*)(p + 0x248) = -1;
    *(u32*)(p + 0x240) = 0;
    *(s32*)(p + 0x278) = -1;
    *(u8*)(p + 0x27c) = 0;
    *(u8*)(p + 0x27d) = 0;
    *(u8*)(p + 0x27e) = 0;
    *(u8*)(p + 0x28c) = 0;
    *(u16*)(p + 0x280) = 0xff;
    *(u16*)(p + 0x282) = 0xff;
}

