// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80184D64-80187144 (WNWN). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern const f32 lbl_8053DF40;
extern const f32 lbl_8053DF44;
extern const f32 lbl_8053DF54;
extern const f32 lbl_8053DF60;
extern const f32 lbl_8053DFD0;
extern const f32 lbl_8053DFD4;
extern const f32 lbl_8053DFD8;

// from src/Game/fn_80184D64_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A18E0[];

extern "C" void* fn_80184D64(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A18E0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct WnwnVec {
    f32 x, y, z;
};

struct Wnwn {
    u8 pad0[0xc];
    WnwnVec pos;          // 0x0c
    u8 pad18[0x274 - 0x18];
    s16 ang[10];          // 0x274
    u8 pad288[0x294 - 0x288];
    WnwnVec trail[10];    // 0x294
    WnwnVec trail2[10];   // 0x30c
    WnwnVec home;         // 0x384
};

struct WnwnRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053DF40;
    }
};
struct WnwnGame { u8 pad[0xb4]; WnwnRandom rnd; };
extern WnwnGame* lbl_8053AAF8;
extern "C" u16 fn_801F6874(s32 dir);

extern "C" void fn_80186D24(char* this_) {
    f32 b = lbl_8053DF60;
    f32 a = lbl_8053DFD0;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = a;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = b;
    *(f32*)(this_ + 0x80) = a;
    *(f32*)(this_ + 0x84) = a;
    *(f32*)(this_ + 0x88) = b;
    *(f32*)(this_ + 0x8c) = b;
    *(f32*)(this_ + 0x70) = lbl_8053DFD4;
    *(f32*)(this_ + 0x74) = lbl_8053DFD4;
    *(f32*)(this_ + 0x78) = lbl_8053DF54;
    *(f32*)(this_ + 0x7c) = lbl_8053DF54;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x98) = (s32)(lbl_8053DFD8 * lbl_8053AAF8->rnd.get_ufloat_1());
    *(s16*)(this_ + 0x272) = fn_801F6874(*(s32*)(this_ + 0x98));
    *(s32*)(this_ + 0x264) = (*(s32*)(this_ + 0x98) << 1) + *(s32*)(this_ + 0x24c);
    *(f32*)(this_ + 0x288) = *(f32*)(this_ + 0x28c) = *(f32*)(this_ + 0x290) = lbl_8053DF44;
    Wnwn* w = (Wnwn*)this_;
    w->home.x = w->pos.x;
    w->home.y = w->pos.y;
    w->home.z = w->pos.z;
    *(u16*)(this_ + 0x270) = 0xffff;
    for (s32 i = 0; i < 10; i++) {
        w->trail[i].x = w->pos.x;
        w->trail[i].y = w->pos.y;
        w->trail[i].z = w->pos.z;
        w->trail2[i].x = w->pos.x;
        w->trail2[i].y = w->pos.y;
        w->trail2[i].z = w->pos.z;
        w->ang[i] = 0;
    }
    *(f32*)(this_ + 0x26c) = lbl_8053DF44;
    *(s32*)(this_ + 0x268) = 3;
    *(s32*)(this_ + 0x260) = -1;
    *(s32*)(this_ + 0x118) = 4;
    *(u32*)(this_ + 0xb0) = 0x0a040004;
    *(s32*)(this_ + 0x230) = 0;
}

struct WnwnDrawKey {
    s32 a, b;
    WnwnDrawKey() { a = -1; b = -1; }
};

struct WnwnDrawParam {
    u8 map[16];      // 0x00
    WnwnDrawKey key; // 0x10
    s32 c;           // 0x18
    u8 palette;      // 0x1c
    s8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    WnwnDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};

extern "C" void fn_801F06F0(void* actor, const char* tbl, s32 idx, WnwnDrawParam* param, s32 p5, f32 a, f32 b);
extern const char lbl_80466ED8[];

extern "C" void fn_80184DC4(char* this_) {
    Wnwn* w = (Wnwn*)this_;
    WnwnDrawParam param;
    s32 i = 0;
    JGeometry::TVec3<f32> save = *(JGeometry::TVec3<f32>*)&w->pos;
    if (*(s32*)(this_ + 0x260) >= 0) {
        i = 1;
    }
    for (; i < 9; i++) {
        w->pos.x = w->trail[i].x;
        w->pos.y = w->trail[i].y;
        w->pos.z = w->trail[i].z;
        param.f20 = 0;
        param.color = -1;
        fn_801F06F0(this_, lbl_80466ED8, 0x13b, &param, 7, 1.0f, 1.0f);
    }
    w->pos.x = save.x;
    w->pos.y = save.y;
    w->pos.z = save.z;
    param.f20 = 0;
    param.color = 0;
    fn_801F06F0(this_, lbl_80466ED8, *(s32*)(this_ + 0x264) + 0x134, &param, 0, lbl_8053DF40, lbl_8053DF40);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
