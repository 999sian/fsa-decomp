// WLFT_80106040: .text 0x80106040-0x80106ADC (actor WLFT)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// ---- from Game/fn_80106040_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049CC40[];

extern "C" void* fn_80106040(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049CC40;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- fn_8010666C: init (loads the lift model resources)
extern "C" void v01__5ActorFv(void* this_);
class WLFT_ResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};
extern u8* lbl_8053AAF8;
extern const char* lbl_80539EC8[2];
extern const char lbl_80463FC4[];
extern const f32 lbl_8053C284;
extern const f32 lbl_8053C288;
extern const f32 lbl_8053C28C;
extern const f32 lbl_8053C290;
extern const f32 lbl_8053C294;
extern const f32 lbl_8053C298;
extern const f32 lbl_8053C270;
extern const f32 lbl_8053C274;
extern const f32 lbl_8053C27C;
extern const f32 lbl_8053C280;

extern "C" void fn_8010666C(u8* this_) {
    v01__5ActorFv(this_);
    *(void**)(this_ + 0x230) = (*(WLFT_ResMgr**)(lbl_8053AAF8 + 0xA4))->vf18('????', lbl_80539EC8[0]);
    *(void**)(this_ + 0x234) = (*(WLFT_ResMgr**)(lbl_8053AAF8 + 0xA4))->vf18('????', lbl_80463FC4);
    *(s32*)(this_ + 0x29C) = *(u32*)(this_ + 0x90) & 0xF;
    *(s32*)(this_ + 0x2A0) = (*(u32*)(this_ + 0x90) >> 4) & 0xF;
    *(f32*)(this_ + 0x60) = lbl_8053C284;
    *(f32*)(this_ + 0x64) = lbl_8053C284;
    *(f32*)(this_ + 0x68) = lbl_8053C288;
    *(f32*)(this_ + 0x6C) = lbl_8053C288;
    *(f32*)(this_ + 0x60) = lbl_8053C28C;
    *(f32*)(this_ + 0x64) = lbl_8053C28C;
    *(f32*)(this_ + 0x68) = lbl_8053C290;
    *(f32*)(this_ + 0x6C) = lbl_8053C290;
    *(s32*)(this_ + 0xB8) = 1;
}

// ---- fn_8010673C: ctor
struct WLFT_DrawKey {
    s32 a, b;
    WLFT_DrawKey() { a = -1; b = -1; }
};
struct WLFT_DrawParam {
    u8 map[16];      // 0x00
    WLFT_DrawKey key; // 0x10
    s32 c;           // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    WLFT_DrawParam() {
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
struct Actor {
    Actor();
    ~Actor();
    u8 pad[0x230];
};
extern void* lbl_8049CC40[];

class WLFT : public Actor {
public:
    WLFT();
    void* m230;
    void* m234;
    WLFT_DrawParam m238;
    u8 pad274[0xC];
    f32 m280, m284, m288, m28C;
    s32 m290, m294, m298, m29C, m2A0, m2A4;
};

WLFT::WLFT() : Actor(), m230((*(void**)this = lbl_8049CC40, (void*)0)), m234(0) {
    m280 = lbl_8053C294;
    m284 = lbl_8053C294;
    m288 = lbl_8053C298;
    m28C = lbl_8053C298;
    m290 = 0;
    m294 = 0;
    m298 = 0;
    m29C = 0;
    m2A0 = 0;
    m2A4 = 0;
}

// ---- fn_8010645C: update (lift rises once all players stand on it)
extern "C" void v03__5ActorFv(void* this_);
extern "C" s32 fn_8023DE58(s32 player);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 player);
extern "C" void fn_8022DF48(s32 player);
extern "C" void fn_8023DF68(s32 player, JGeometry::TVec3<f32>* v);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D9FF4(void* mgr, s32 a, s32 b);
extern "C" void fn_80136798(void* game, s32 a, s32 b);

static inline bool wlftOnLift(u8* this_, s32 i) {
    s32 room = *(s32*)(this_ + 4);
    if (room != fn_8023DE58(i)) {
        return false;
    }
    JGeometry::TVec3<f32> p(*fn_8023E724(i));
    f32 cx = 8.0f + *(f32*)(this_ + 0xc);
    f32 cy = 8.0f + *(f32*)(this_ + 0x10);
    f32 x0 = *(f32*)(this_ + 0x60) + cx;
    f32 y0 = *(f32*)(this_ + 0x64) + cy;
    f32 x1 = *(f32*)(this_ + 0x68) + cx;
    f32 y1 = *(f32*)(this_ + 0x6c) + cy;
    u8 in = 0;
    if (p.x >= x0 && p.y >= y0 && p.x < x1 && p.y < y1) {
        in = 1;
    }
    if (in) {
        return true;
    }
    return false;
}

extern "C" void fn_8010645C(u8* this_) {
    v03__5ActorFv(this_);
    switch (*(s32*)(this_ + 0x290)) {
    case 0: {
        for (s32 i = 0; i < 4; i++) {
            if (!wlftOnLift(this_, i)) {
                return;
            }
        }
        *(s32*)(this_ + 0x290) = 1;
        *(JGeometry::TVec3<f32>*)(this_ + 0x274) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
        break;
    }
    case 1: {
        *(s32*)(this_ + 0x2a4) = *(s32*)(this_ + 0x2a4) + 1;
        JGeometry::TVec3<f32> v;
        v.set(0.0f, -0.1f, 0.0f);
        *(JGeometry::TVec3<f32>*)(this_ + 0xc) += v;
        *(f32*)(this_ + 0x280) *= 0.999f;
        *(f32*)(this_ + 0x284) *= 0.999f;
        for (s32 i = 0; i < 4; i++) {
            fn_8022DF48(i);
            fn_8023DF68(i, &v);
        }
        if (*(s32*)(this_ + 0x2a4) >= 120) {
            *(s32*)(this_ + 0x290) = 2;
            *(s32*)(this_ + 0x2a4) = 0;
        }
        break;
    }
    case 2:
        fn_802D9FF4(fn_802D6A9C(), *(s32*)(this_ + 0x29c), *(s32*)(this_ + 0x2a0));
        fn_80136798(lbl_8053AAF8, 13, 0);
        *(s32*)(this_ + 0x290) = 3;
        break;
    case 3:
        break;
    }
}

// ---- fn_801060A0: draw (shadow + lift sprite, scaled rotation matrices)
extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void PSMTXTrans(f32 (*m)[4], f32 x, f32 y, f32 z);
extern "C" void v06__5ActorFv(void* this_);
extern "C" void fn_802F745C(void* mgr, void* pos, void* tex, WLFT_DrawParam* prm);
extern u8* lbl_8053AB10;

static inline void wlftMakeMtx(f32 (*m)[4], const f32* s) {
    f32 rx = 0.0f;
    PSMTXTrans(m, rx, rx, rx);
    f32 sx = s[0];
    f32 sy = s[1];
    f32 sz = 1.0f;
    f32 sa = sin(rx);
    f32 sb = sin(rx);
    f32 sc = sin(rx);
    f32 ca = cos(rx);
    f32 cb = cos(rx);
    f32 cc = cos(rx);
    m[0][0] = sx * (cb * cc);
    m[1][0] = sx * (cb * sc);
    m[2][0] = sx * -sb;
    m[0][1] = sz * (sa * sb * cc - ca * sc);
    m[1][1] = sz * (sa * sb * sc + ca * cc);
    m[2][1] = sz * (sa * cb);
    m[0][2] = sy * (ca * cc * sb + sa * sc);
    m[1][2] = sy * (ca * sc * sb - sa * cc);
    m[2][2] = sy * (ca * cb);
}

extern "C" void fn_801060A0(WLFT* this_) {
    v06__5ActorFv(this_);
    this_->m238.color = 0xff;
    f32 m0[3][4];
    wlftMakeMtx(m0, &this_->m288);
    this_->m238.c = (s32)m0;
    WLFT_DrawParam prm;
    prm.color = 0;
    f32 m1[3][4];
    wlftMakeMtx(m1, &this_->m280);
    prm.c = (s32)m1;
    if (*(s32*)((u8*)this_ + 4) < 8) {
        void* tex = (*(WLFT_ResMgr**)(lbl_8053AAF8 + 0xA4))->vf18('TIMG', lbl_80539EC8[0]);
        fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), (u8*)this_ + 0xc, tex, &this_->m238);
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
