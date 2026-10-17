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

extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AB10;
extern "C" u8 lbl_8046D818[];
extern const f32 lbl_80540D70;
extern const f32 lbl_80540D74;
extern "C" void fn_802F745C(void* a, void* b, u32 c, u8* d);
extern "C" void* fn_8022EA0C(s32 i);
extern "C" void* fn_8023E724(void* p);
extern "C" void fn_8013CC50(void* obj, void* pos, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void fn_801F0E34(void* obj, s32 a, s32 b);
extern const f32 lbl_80540D80;
extern "C" void fn_802C99A4(u8* this_) {
    volatile struct {
        s32 a;
        s32 b;
        void* p;
        u8 c[11];
        s32 i60;
        u8 g[3];
        s32 i68;
        s32 i6c;
        s32 i70;
    } pal;
    u8 buf[16];
    f32 mtx[4][3];
    u8 i;
    u32 ret;
    u8* obj;

    pal.a = -1;
    pal.b = -1;
    for (i = 0; i < 16; i += 8) {
        buf[(u8)i] = i;
        buf[(u8)(i + 1)] = i + 1;
        buf[(u8)(i + 2)] = i + 2;
        buf[(u8)(i + 3)] = i + 3;
        buf[(u8)(i + 4)] = i + 4;
        buf[(u8)(i + 5)] = i + 5;
        buf[(u8)(i + 6)] = i + 6;
        buf[(u8)(i + 7)] = i + 7;
    }
    pal.a = -1;
    pal.b = 0;
    pal.p = 0;
    pal.c[0] = 0;
    pal.c[1] = 0;
    pal.c[2] = 0;
    pal.c[3] = 1;
    pal.c[4] = 1;
    pal.c[5] = 0;
    pal.c[6] = 0;
    pal.c[7] = 0;
    pal.c[8] = 0;
    pal.c[9] = 0;
    pal.c[10] = 1;
    pal.i60 = 3;
    pal.g[0] = 1;
    pal.g[1] = 0;
    pal.g[2] = 0;
    pal.i68 = -1;
    pal.i6c = 0;
    pal.i70 = 2;
    mtx[1][0] = lbl_80540D70;
    mtx[2][1] = lbl_80540D70;
    mtx[3][2] = lbl_80540D70;
    if (this_[0x242]) {
        pal.c[0] = 0xff;
        pal.c[1] = 0;
    } else {
        pal.c[0] = 1;
        pal.c[1] = 1;
    }
    mtx[0][0] = (f32)*(s32*)(this_ + 0x238);
    mtx[0][1] = lbl_80540D70;
    mtx[0][2] = lbl_80540D70;
    mtx[1][1] = lbl_80540D70;
    mtx[1][2] = lbl_80540D74;
    mtx[2][0] = lbl_80540D70;
    mtx[2][2] = lbl_80540D70;
    mtx[3][0] = lbl_80540D70;
    mtx[3][1] = (f32)*(s32*)(this_ + 0x23c);
    mtx[3][2] = lbl_80540D70;
    pal.c[0] = 0xff;
    pal.c[1] = 0xff;
    pal.c[2] = 0xff;
    pal.c[3] = this_[0x244];
    pal.p = mtx;
    obj = *(u8**)((u8*)lbl_8053AAF8 + 0xa4);
    ret = ((u32 (*)(void*, u32, void*))(*(u32**)obj)[6])(obj, 0x54494D47, lbl_8046D818);
    if (*(s32*)(this_ + 4) < 8) {
        fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), this_ + 0xc, ret, buf);
    }
}

struct PointF {
    f32 x;
    f32 y;
    f32 z;
};

extern "C" void fn_802C9BCC(u8* this_) {
    u8 hit = 0;
    u8* g = (u8*)lbl_8053AAF8;
    f32 x0 = *(f32*)(this_ + 0x60) + *(f32*)(this_ + 0xc);
    f32 y0 = *(f32*)(this_ + 0x64) + *(f32*)(this_ + 0x10);
    f32 x1 = *(f32*)(this_ + 0x68) + *(f32*)(this_ + 0xc);
    f32 y1 = *(f32*)(this_ + 0x6c) + *(f32*)(this_ + 0x10);
    s32 i;

    if (g[0x7e] == 1) {
        for (i = 0; i < 4; i++) {
            u8 on = (g[0x82] & (u8)(1 << i)) != 0;
            if (on == 1) {
                Vec pt = *(Vec*)fn_8023E724(fn_8022EA0C(i));
                if (pt.x >= x0 && pt.y >= y0 && pt.x < x1 && pt.y < y1) {
                    hit = 1;
                    break;
                }
            }
        }
    } else {
        Vec pt = *(Vec*)fn_8023E724(fn_8022EA0C(0));
        if (pt.x >= x0 && pt.y >= y0 && pt.x < x1 && pt.y < y1) {
            hit = 1;
        }
    }

    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        if (hit) {
            *(s32*)(this_ + 0x230) = 1;
        }
        break;
    case 1:
        if (*(u8*)(this_ + 0x240)) {
            fn_8013CC50(*(void**)(this_ + 0x4), this_ + 0xc, lbl_80540D80, 0x564, 0, 0, 0, 0, 1);
            fn_8013CC50(*(void**)(this_ + 0x4), this_ + 0xc, lbl_80540D74, 0x503, 1, 0, 0, 0, 1);
            fn_801F0E34(this_, 0x30003, 0);
            *(u8*)(this_ + 0x240) = 0;
        }
        *(u8*)(this_ + 0x11c) = 0;
        if (*(u8*)(this_ + 0x241)) {
            *(s32*)(this_ + 0x244) -= 12;
            if (*(s32*)(this_ + 0x244) < 0) {
                *(s32*)(this_ + 0x244) = 0;
                *(s32*)(this_ + 0x230) = 2;
            }
        }
        if (!hit) {
            *(s32*)(this_ + 0x230) = 3;
        }
        break;
    case 2:
        if (!hit) {
            *(s32*)(this_ + 0x230) = 3;
        }
        break;
    case 3:
        if (*(u8*)(this_ + 0x241) <= 0xff) {
            *(s32*)(this_ + 0x244) += 12;
            if (*(s32*)(this_ + 0x244) >= 0xff) {
                *(s32*)(this_ + 0x244) = 0xff;
                *(s32*)(this_ + 0x230) = 0;
            }
        }
        if (hit) {
            *(s32*)(this_ + 0x230) = 1;
        }
        break;
    }
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

