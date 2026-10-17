#include "Game/SinitPoolChain.h"
#include "Game/Actor.h"


extern "C" char lbl_804AE5C8[];
extern "C" char lbl_804750AC[];
extern "C" f32 lbl_80475060[];
extern "C" f32 lbl_80542E88;
extern "C" f32 lbl_80542E90;
extern "C" f32 lbl_80542E94;
extern "C" f32 lbl_80542E98;
extern "C" f32 lbl_80542E9C;
extern "C" void fn_801F06F0(Actor* a, const char* tbl, s32 idx, void* rec, s32 p5, f32 sx, f32 sy);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80373BD8(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AE5C8;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_80373EC8(Actor* p) {
    Vec saved = p->field_0C;
    f32 angle = *(f32*)((u8*)p + 0x244);
    f32 period = lbl_80542E90;
    f32 q = (f32)(s32)(angle / period);
    f32 rem = angle - period * q;
    s32 idx;
    if (rem < lbl_80542E94) {
        idx = 0;
    } else if (rem < lbl_80542E98) {
        idx = 1;
    } else if (rem < lbl_80542E9C) {
        idx = 2;
    } else {
        idx = 3;
    }
    p->field_0C.y -= angle;
    p->field_0C.y += lbl_80475060[idx];
    fn_801F06F0(p, lbl_804750AC, *(s32*)((u8*)p + 0x23c) + 0x469, 0, -1, lbl_80542E94, lbl_80542E94);
    if (idx == 0) {
        p->field_0C = saved;
    } else {
        p->field_0C.x = saved.x - lbl_80542E88;
        p->field_0C.y = saved.y - angle;
        p->field_0C.z = saved.z - lbl_80542E88;
        fn_801F06F0(p, lbl_804750AC, idx + 0x469, 0, -1, lbl_80542E94, lbl_80542E94);
        p->field_0C = saved;
    }
}

extern "C" f32 lbl_80542ED0;
extern "C" f32 lbl_80542ED4;
extern "C" f32 lbl_80542E88;
extern "C" void fn_803744C4(u8* p) {
    f32 a = lbl_80542ED0;
    f32 b = lbl_80542ED4;
    f32 z = lbl_80542E88;
    *(f32*)(p + 0x60) = a;
    *(f32*)(p + 0x64) = a;
    *(f32*)(p + 0x68) = b;
    *(f32*)(p + 0x6c) = b;
    *(f32*)(p + 0x80) = z;
    *(f32*)(p + 0x84) = z;
    *(f32*)(p + 0x88) = z;
    *(f32*)(p + 0x8c) = z;
    *(s32*)(p + 0x108) = 0;
    *(s32*)(p + 0x23c) = 0;
    u8 r = (*(u8 (**)(u8*))(*(u8**)p + 0x34))(p);
    p[0x254] = r;
    p[0x240] = r;
    z = lbl_80542E88;
    *(f32*)(p + 0x244) = z;
    *(f32*)(p + 0x3c) = z;
    *(f32*)(p + 0x40) = z;
    *(f32*)(p + 0x44) = z;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = -1;
    *(s32*)(p + 0x250) = 0;
}

