// LPLK_800F6820: .text 0x800F6820-0x800F7FCC (actor LPLK)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

// ---- from Game/fn_800F7C4C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern "C" s32 fn_8022DCD8(s32 player);
extern "C" void fn_8022DD74(s32 player);
extern void* lbl_8049C578[];

extern "C" void* fn_800F7C4C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C578;
        char* p = (char*)this_;
        s32 player = *(s32*)(p + 0x238);
        if ((u8)fn_8022DCD8(player) != 0) {
            player = *(s32*)(p + 0x238);
            fn_8022DD74(player);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

struct LplkVirt {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual s32 v13();
};
extern const f32 lbl_8053BF98;
extern const f32 lbl_8053BF68;
extern const f32 lbl_8053BF48;
extern const f32 lbl_8053BF9C;

extern "C" void fn_800F7CC8(char* this_) {
    *(f32*)(this_ + 0x60) = lbl_8053BF98;
    *(f32*)(this_ + 0x64) = lbl_8053BF98;
    *(f32*)(this_ + 0x68) = lbl_8053BF68;
    *(f32*)(this_ + 0x6c) = lbl_8053BF68;
    *(f32*)(this_ + 0x80) = lbl_8053BF98;
    *(f32*)(this_ + 0x84) = lbl_8053BF98;
    *(f32*)(this_ + 0x88) = lbl_8053BF68;
    *(f32*)(this_ + 0x8c) = lbl_8053BF68;
    *(u8*)(this_ + 0x235) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(u8*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xf;
    *(u8*)(this_ + 0x23c) = 1;
    *(s32*)(this_ + 0x238) = 0;
    *(f32*)(this_ + 0x264) = lbl_8053BF48;
    *(f32*)(this_ + 0x260) = lbl_8053BF48;
    if (*(u32*)(this_ + 0x90) & 0x100) {
        *(s32*)(this_ + 0x230) = 1;
    }
    if (((LplkVirt*)this_)->v13() != 0) {
        *(s32*)(this_ + 0x230) = 4;
    }
    if (*(u32*)(this_ + 0x90) & 0x400) {
        *(u8*)(this_ + 0x23c) = 0;
        *(f32*)(this_ + 0x14) = lbl_8053BF9C;
    }
    *(s32*)(this_ + 0x24c) = 0;
}

extern const f32 lbl_8053BF30;
struct LplkRandom {
    u32 seed;
    f32 get() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053BF30;
    }
};
struct LplkGame { u8 pad[0xb4]; LplkRandom rnd; };
extern LplkGame* lbl_8053AAF8;
extern const f32 lbl_8053BF34;
extern const f32 lbl_8053BF38;
extern const u16 lbl_80539E70[4];
extern "C" void fn_801CD150(void* src, void* dst);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F8544(void* base, u32 fourCC, s32 room, void* pos, s32 kind);
extern "C" char* fn_801F666C(void* base, s32 id);
extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, u32 a, s32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void v07__5ActorFv(void* this_);

#pragma opt_propagation off
extern "C" void fn_800F6820(char* this_) {
    s32 kind;
    int room;
    JGeometry::TVec3<f32> pos;
    BOOL big;
    kind = *(s32*)(this_ + 0x4);
    if ((u8)fn_8022DCD8(*(s32*)(this_ + 0x238)) != 0) {
        fn_8022DD74(*(s32*)(this_ + 0x238));
    }
    if (*(u32*)(this_ + 0x90) & 0x1000) {
        big = TRUE;
        fn_801CD150(this_ + 0xc, &pos);
        kind = 8;
    } else {
        big = FALSE;
        pos.x = *(f32*)(this_ + 0xc);
        pos.y = *(f32*)(this_ + 0x10);
        pos.z = *(f32*)(this_ + 0x14);
    }
    room = kind;
    while (*(s32*)(this_ + 0x244) > 0) {
        if (big == 0) {
            if (*(s32*)(this_ + 0x244) >= 200) {
                kind = 3;
                *(s32*)(this_ + 0x244) -= 50;
            } else if (*(s32*)(this_ + 0x244) >= 80) {
                kind = 2;
                *(s32*)(this_ + 0x244) -= 20;
            } else if (*(s32*)(this_ + 0x244) >= 20) {
                kind = 1;
                *(s32*)(this_ + 0x244) -= 5;
            } else {
                kind = 0;
                *(s32*)(this_ + 0x244) -= 1;
            }
        } else {
            if (*(s32*)(this_ + 0x244) >= 200) {
                kind = 4;
                *(s32*)(this_ + 0x244) -= 100;
            } else if (*(s32*)(this_ + 0x244) >= 50) {
                kind = 3;
                *(s32*)(this_ + 0x244) -= 50;
            } else {
                kind = 2;
                *(s32*)(this_ + 0x244) -= 20;
            }
        }
        s32 id = fn_801F8544(fn_801F856C(), 'RUPY', room, &pos, kind);
        if (id >= 0) {
            char* a = fn_801F666C(fn_801F856C(), id);
            if (a != 0) {
                JGeometry::TVec3<f32> v;
                f32 r = lbl_8053AAF8->rnd.get();
                v.z = lbl_8053BF38 * r + lbl_8053BF38;
                v.y = lbl_8053BF34 - lbl_8053AAF8->rnd.get();
                v.x = lbl_8053BF34 - lbl_8053AAF8->rnd.get();
                *(JGeometry::TVec3<f32>*)(a + 0x3c) = v;
            }
        }
    }
    fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_80539E70[*(u8*)(this_ + 0x234)], 0, 0, 0, 0, 1, lbl_8053BF30);
    *(s32*)(this_ + 0x18c) = 0;
    v07__5ActorFv(this_);
}
#pragma opt_propagation reset
extern "C" void fn_801F02BC(char* this_, void* anim, s32 idx, u8* tbl, s32 frame, s32 a, s32 b, f32 x, f32 y, f32 z);
extern const f32 lbl_8053BF3C;
extern const f32 lbl_8053BF40;
extern const f32 lbl_8053BF44;
extern const s32 lbl_8053BF50[];
extern const s32 lbl_8053BF48_tbl[];
extern u8 lbl_8049C518[];
extern u8 lbl_80463710[];
extern u8 lbl_80463724[];
extern "C" void fn_800F6AB4(char* this_) {
    volatile struct {
        s32 a;
        s32 b;
        f32* p;
        u8 c[11];
        s32 d;
        u8 e[3];
        s32 f;
        s32 g;
        s32 h;
    } cfg;
    f32 arr[12];
    u8 tbl[16];
    s32* base = (s32*)lbl_8049C518;
    cfg.a = -1;
    cfg.b = -1;
    for (u8 i = 0; i < 0x10; i += 8) {
        tbl[i] = i;
        tbl[(u8)(i + 1)] = (u8)(i + 1);
        tbl[(u8)(i + 2)] = (u8)(i + 2);
        tbl[(u8)(i + 3)] = (u8)(i + 3);
        tbl[(u8)(i + 4)] = (u8)(i + 4);
        tbl[(u8)(i + 5)] = (u8)(i + 5);
        tbl[(u8)(i + 6)] = (u8)(i + 6);
        tbl[(u8)(i + 7)] = (u8)(i + 7);
    }
    cfg.a = -1;
    cfg.b = 0;
    cfg.p = 0;
    cfg.c[0] = 0;
    cfg.c[1] = 0;
    cfg.c[2] = 0;
    cfg.c[3] = 1;
    cfg.c[4] = 1;
    cfg.c[5] = 0;
    cfg.c[6] = 0;
    cfg.c[7] = 0;
    cfg.c[8] = 0;
    cfg.c[9] = 0;
    cfg.c[10] = 1;
    cfg.d = 3;
    cfg.e[0] = 1;
    cfg.e[1] = 0;
    cfg.e[2] = 0;
    cfg.f = -1;
    cfg.g = 0;
    cfg.h = 2;
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        fn_801F02BC(this_, lbl_80463710, *(u8*)(this_ + 0x235) + base[*(u8*)(this_ + 0x234)], tbl, 0, 0, 0, lbl_8053BF30, lbl_8053BF30, 0.0f);
        return;
    case 2:
        *(f32*)(this_ + 0xc) += *(f32*)(this_ + 0x260);
        *(f32*)(this_ + 0x10) += *(f32*)(this_ + 0x264);
        fn_801F02BC(this_, lbl_80463724, *(u8*)(this_ + 0x235) + (base + 8)[*(u8*)(this_ + 0x234)], tbl, 7, 0, 0, lbl_8053BF30, lbl_8053BF30, 0.0f);
        *(f32*)(this_ + 0xc) -= *(f32*)(this_ + 0x260);
        *(f32*)(this_ + 0x10) -= *(f32*)(this_ + 0x264);
        break;
    case 4:
        break;
    default:
        {
            f32 f = lbl_8053BF30 + lbl_8053BF3C * ((f32)*(u32*)(this_ + 0x244) / lbl_8053BF40);
            if (f > lbl_8053BF44) {
                f = lbl_8053BF44;
            }
            cfg.p = arr;
            arr[0] = f;
            arr[1] = lbl_8053BF48;
            arr[2] = lbl_8053BF48;
            arr[3] = lbl_8053BF48;
            arr[4] = lbl_8053BF48;
            arr[5] = lbl_8053BF30;
            arr[6] = lbl_8053BF48;
            arr[7] = lbl_8053BF48;
            arr[8] = lbl_8053BF48;
            arr[9] = lbl_8053BF48;
            arr[10] = f;
            arr[11] = lbl_8053BF48;
            fn_801F02BC(this_, lbl_80463724, *(u8*)(this_ + 0x235) + (base + 4)[*(u8*)(this_ + 0x234)], tbl, 7, 0, 0, lbl_8053BF30, lbl_8053BF30, f);
        }
        break;
    }
}

extern "C" void fn_800F6D80(u8* self) {
    *(s32*)(self + 0x24c) += 1;
    s32 st = *(s32*)(self + 0x230);
    (void)st;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
