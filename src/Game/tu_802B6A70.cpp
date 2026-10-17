#include "Game/Actor.h"

extern "C" void* lbl_8053AAF8;

/* 0x19660d/0x3c6ef35f LCG kept at lbl_8053AAF8+0xB4; returns a [0,1) float. */
static inline f32 rand01() {
    u32* s = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *s = *s * 0x19660du + 0x3c6ef35fu;
    u32 a = (*s >> 9) | 0x3f800000u;
    return *(f32*)&a - 1.0f;
}
extern "C" u8 lbl_8046CAD0[];
extern "C" void fn_801EFD34(Actor* p, void* obj, f32 x, f32 y, f32 z, void* buf, s32 n);


extern "C" char lbl_804A87A8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" void fn_802B6DAC(Actor* p) {
    u8 buf[0x3c];
    u8* q;
    u8* tbl;
    s32 i;
    void* mgr;
    void* obj;
    s32 c;

    tbl = lbl_8046CAD0;
    if (*(s32*)((char*)p + 0x234) == 1 || *(s32*)((char*)p + 0x234) >= 3) {
        q = buf;
        *(s32*)(q + 0x10) = -1;
        *(s32*)(q + 0x14) = -1;
        for (i = 0; (u8)i < 16; i += 8) {
            q[(u8)i] = i;
            q[(u8)(i + 1)] = i + 1;
            q[(u8)(i + 2)] = i + 2;
            q[(u8)(i + 3)] = i + 3;
            q[(u8)(i + 4)] = i + 4;
            q[(u8)(i + 5)] = i + 5;
            q[(u8)(i + 6)] = i + 6;
            q[(u8)(i + 7)] = i + 7;
        }
        buf[0x1c] = 0;
        buf[0x1d] = 0;
        *(s32*)(buf + 0x10) = -1;
        *(s32*)(buf + 0x14) = 0;
        *(s32*)(buf + 0x18) = 0;
        buf[0x1e] = 0;
        buf[0x1f] = 1;
        buf[0x20] = 1;
        buf[0x21] = 0;
        buf[0x22] = 0;
        buf[0x23] = 0;
        buf[0x24] = 0;
        buf[0x25] = 0;
        buf[0x26] = 1;
        *(s32*)(buf + 0x28) = 3;
        buf[0x2c] = 1;
        buf[0x2d] = 0;
        buf[0x2e] = 0;
        *(s32*)(buf + 0x30) = -1;
        *(s32*)(buf + 0x34) = 0;
        *(s32*)(buf + 0x38) = 2;
        buf[0x1c] = 0;
        buf[0x1d] = 1;

        c = **(char**)((char*)p + 0x248);
        if (c == 'r' || c == 's' || c == 'y') {
            mgr = *(void**)((char*)lbl_8053AAF8 + 0xa4);
            obj = ((void* (*)(void*, s32, void*))(*(void***)mgr)[6])(mgr, 0x54494d47, tbl + 0x30);
            fn_801EFD34(p, obj, 0.0f, -18.0f, 0.0f, buf, 7);
        } else if (c == 'l' || c == 'x' || c == 'p') {
            mgr = *(void**)((char*)lbl_8053AAF8 + 0xa4);
            obj = ((void* (*)(void*, s32, void*))(*(void***)mgr)[6])(mgr, 0x54494d47, tbl + 0x40);
            fn_801EFD34(p, obj, 0.0f, -18.0f, 0.0f, buf, 7);
        } else if (c == 'u') {
            mgr = *(void**)((char*)lbl_8053AAF8 + 0xa4);
            obj = ((void* (*)(void*, s32, void*))(*(void***)mgr)[6])(mgr, 0x54494d47, tbl + 0x50);
            fn_801EFD34(p, obj, 0.0f, -18.0f, 0.0f, buf, 7);
        } else {
            mgr = *(void**)((char*)lbl_8053AAF8 + 0xa4);
            obj = ((void* (*)(void*, s32, void*))(*(void***)mgr)[6])(mgr, 0x54494d47, tbl + 0x60);
            fn_801EFD34(p, obj, 0.0f, -18.0f, 0.0f, buf, 7);
        }
    }
}

extern "C" Actor* fn_802B74F4(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A87A8;
        if (*(void**)((char*)p + 0x230)) {
            fn_801EE434(*(void**)((char*)p + 0x230));
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void* fn_802D6A9C(void);
extern "C" void* fn_802D9C4C(void* mgr);
extern "C" u8 fn_802D7544(void* mgr, void* arg);
extern "C" void fn_8029D8F0(void* mgr, f32* pos, s32 room, s32 n, s32 flag);
extern "C" void* lbl_8053AC98;

extern "C" void fn_802B7568(u8* p) {
    f32 vec[3];
    void* mgr;
    s32 room;
    s32 n;

    *(s32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    *(f32*)(p + 0xc) += 8.0f;
    *(f32*)(p + 0x60) = -48.0f;
    *(f32*)(p + 0x64) = -16.0f;
    *(f32*)(p + 0x68) = 48.0f;
    *(f32*)(p + 0x6c) = 40.0f;
    *(s32*)(p + 0x1a4) = 1;
    if (*(s32*)(p + 4) < 8) {
        *(s32*)(p + 0x244) = 1;
    } else {
        *(s32*)(p + 0x244) = 8;
    }
    *(s32*)(p + 0x23c) = 2;
    *(s32*)(p + 0x234) = 0;
    mgr = fn_802D6A9C();
    *(void**)(p + 0x248) = fn_802D9C4C(mgr);
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x240) = 0;
    if (fn_802D7544(fn_802D6A9C(), *(void**)(p + 0x16c))) {
        room = *(s32*)(p + 4);
        n = *(s32*)(p + 0x244);
        vec[0] = *(f32*)(p + 0xc) - 8.0f;
        vec[1] = *(f32*)(p + 0x10);
        vec[2] = *(f32*)(p + 0x14);
        fn_8029D8F0(lbl_8053AC98, vec, room, n, 0);
        *(u8*)(p + 0x11c) = 0;
    }
}

