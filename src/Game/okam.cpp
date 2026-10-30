// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801AE9C4-801AFB38 (OKAM). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// from src/Game/fn_801AE9C4_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A3448[];

extern "C" void* fn_801AE9C4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A3448;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// OKAM: change animation state
extern "C" void fn_801AF7D0(char* this_, s32 state) {
    s32 cur = *(s32*)(this_ + 0x258);
    if (cur == state) {
        return;
    }
    if ((cur == 2 && state == 1) || (cur == 6 && state == 5)) {
        return;
    }
    *(s32*)(this_ + 0x258) = state;
    *(u8*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x240) = 0;
    switch (*(s32*)(this_ + 0x258)) {
    case 0:
        *(s32*)(this_ + 0x254) = 0;
        break;
    case 1:
        *(s32*)(this_ + 0x254) = 4;
        if (*(f32*)(this_ + 0x260) > 0.0f) {
            *(f32*)(this_ + 0x278) = 16.0f;
        } else {
            *(f32*)(this_ + 0x278) = -16.0f;
        }
        break;
    case 2:
        *(f32*)(this_ + 0x280) = 0.0f;
        *(f32*)(this_ + 0x27c) = 0.0f;
        *(f32*)(this_ + 0x278) = 0.0f;
        *(s32*)(this_ + 0x254) = 0x18;
        break;
    case 3:
        *(s32*)(this_ + 0x254) = 8;
        break;
    case 4:
        *(s32*)(this_ + 0x254) = 0xc;
        break;
    case 5:
        *(s32*)(this_ + 0x254) = 0x10;
        if (*(f32*)(this_ + 0x264) > 0.0f) {
            *(f32*)(this_ + 0x27c) = 16.0f;
        } else {
            *(f32*)(this_ + 0x27c) = -16.0f;
        }
        break;
    case 6:
        *(f32*)(this_ + 0x280) = 0.0f;
        *(f32*)(this_ + 0x27c) = 0.0f;
        *(f32*)(this_ + 0x278) = 0.0f;
        *(s32*)(this_ + 0x254) = 0x1b;
        break;
    case 7:
        *(s32*)(this_ + 0x254) = 0x14;
        break;
    }
    *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x254);
    *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x24c) + *(s32*)(this_ + 0x240);
}

// OKAM: advance animation frame
extern "C" void fn_801AF678(char* this_) {
    if (*(s32*)(this_ + 0x234) != 0) {
        return;
    }
    *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x254);
    *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x24c) + *(s32*)(this_ + 0x240);
    *(s32*)(this_ + 0x234) = 5;
    switch (*(s32*)(this_ + 0x258)) {
    case 0:
    case 2:
    case 4:
    case 6:
        (*(s32*)(this_ + 0x240))++;
        *(s32*)(this_ + 0x240) &= 3;
        break;
    case 1:
        (*(s32*)(this_ + 0x240))++;
        *(s32*)(this_ + 0x240) &= 3;
        if (*(s32*)(this_ + 0x240) == 0) {
            fn_801AF7D0(this_, 2);
            *(u8*)(this_ + 0x25c) = 1;
        }
        break;
    case 3:
        (*(s32*)(this_ + 0x240))++;
        if (*(s32*)(this_ + 0x240) > 2) {
            fn_801AF7D0(this_, 0);
            *(u8*)(this_ + 0x25c) = 1;
        }
        break;
    case 5:
        (*(s32*)(this_ + 0x240))++;
        *(s32*)(this_ + 0x240) &= 3;
        if (*(s32*)(this_ + 0x240) == 0) {
            fn_801AF7D0(this_, 6);
            *(u8*)(this_ + 0x25c) = 1;
        }
        break;
    case 7:
        (*(s32*)(this_ + 0x240))++;
        if (*(s32*)(this_ + 0x240) > 2) {
            fn_801AF7D0(this_, 4);
            *(u8*)(this_ + 0x25c) = 1;
        }
        break;
    }
}

extern void* lbl_8053AAF8;
extern "C" s32 fn_80138A30(void* game);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, u32 arg, void* pos, u32 arg2, s32 a, s32 b);
extern u32 lbl_804A33B8[];
extern u32 lbl_804A33C4[];

// OKAM init (vtable slot 1). In multiplayer with a variant > 2 it spawns a
// replacement actor (OKTA / PEAC / STAL table) instead.
extern "C" void fn_801AF05C(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    if (fn_80138A30(lbl_8053AAF8) <= 1) {
        s32 i = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
        if (i > 2) {
            i = 0;
        }
        u32 id;
        u32 arg;
        arg = lbl_804A33C4[i];
        id = lbl_804A33B8[i];
        if (Actor_CreateByID(fn_801F856C(), id, *(u32*)(this_ + 4), this_ + 0xc, arg, -1, -1) >= 0) {
            *(u8*)(this_ + 0x11c) = 0;
        }
        return;
    }
    *(f32*)(this_ + 0x274) = 0.0f;
    *(f32*)(this_ + 0x270) = 0.0f;
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x280) = 0.0f;
    *(f32*)(this_ + 0x27c) = 0.0f;
    *(f32*)(this_ + 0x278) = 0.0f;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = -1;
    *(u8*)(this_ + 0x25c) = 0;
    *(u32*)(this_ + 0x250) = *(u32*)(this_ + 0x90) & 1;
    if (*(s32*)(this_ + 0x250) == 0) {
        *(s32*)(this_ + 0x98) = 0;
        fn_801AF7D0(this_, 0);
    } else {
        *(s32*)(this_ + 0x98) = 2;
        fn_801AF7D0(this_, 4);
    }
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x264) = 0.0f;
    *(f32*)(this_ + 0x260) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(u32*)(this_ + 0xb0) = 0xa042004;
    *(s32*)(this_ + 0x230) = 0;
}

struct OkamBox {
    u32 w[4];
};

static inline void okamSetBox(char* this_, f32 l, f32 t, f32 r, f32 b) {
    f32 x = *(f32*)(this_ + 0x26c);
    f32 y = *(f32*)(this_ + 0x270);
    *(f32*)(this_ + 0x60) = l + x;
    *(f32*)(this_ + 0x64) = t + y;
    *(f32*)(this_ + 0x68) = r + x;
    *(f32*)(this_ + 0x6c) = b + y;

}

extern "C" s32 fn_801F285C(char* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_801F2B7C(char* this_, s32 a, s32 b, s32 c);
extern "C" void fn_801EEC98(char* this_, s32 handle, s32 a, s32* out, s32 b, s32 c, s32 d, s32 e);
extern "C" u8 fn_801F305C(char* this_);
extern "C" u8 fn_801F2618(char* this_, s32 a, s32 b);
extern "C" u8 fn_80237948(s32 idx, f32* pos);
extern "C" void fn_8013CC50(s32 handle, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(char* this_, s32 a, s32 b);
#pragma opt_common_subs off
extern "C" void fn_801AF1EC(char* this_) {
    s32 flag = -1;
    register int res = -1;
    s32 i = 0;
    f32 pos[2];
    s32 state;

    for (; i < 4; i++) {
        if (res >= 0) break;
        res = fn_801F285C(this_, 0, 0, 1, i);
    }
    state = *(s32*)(this_ + 0x258);
    switch (state) {
    case 0:
    case 4:
        if (state == 0) {
            f32 b = *(f32*)(this_ + 0x270);
            f32 a = *(f32*)(this_ + 0x26c);
            *(f32*)(this_ + 0x60) = -16.0f + a;
            *(f32*)(this_ + 0x64) = -7.0f + b;
            *(f32*)(this_ + 0x68) = 16.0f + a;
            *(f32*)(this_ + 0x6c) = 7.0f + b;
        } else {
            f32 b = *(f32*)(this_ + 0x270);
            f32 a = *(f32*)(this_ + 0x26c);
            *(f32*)(this_ + 0x60) = -7.0f + a;
            *(f32*)(this_ + 0x64) = -18.0f + b;
            *(f32*)(this_ + 0x68) = 7.0f + a;
            *(f32*)(this_ + 0x6c) = 18.0f + b;
        }
        *(OkamBox*)(this_ + 0x80) = *(OkamBox*)(this_ + 0x60);
        fn_801F2B7C(this_, -100, -1, 1);
        break;
    case 2: {
        register f32 b = *(f32*)(this_ + 0x270);
        f32 a = *(f32*)(this_ + 0x26c);
        *(f32*)(this_ + 0x60) = -6.0f + a;
        *(f32*)(this_ + 0x64) = -6.0f + b;
        *(f32*)(this_ + 0x68) = 6.0f + a;
        *(f32*)(this_ + 0x6c) = 6.0f + b;
        if (0 <= res) {
            fn_801EEC98(this_, *(s32*)(this_ + 0x198), 0, &flag, 0, 0, res, 2);
            if (0 <= flag) {
                if ((flag & 2) != 0) {
                    if (fn_801F305C(this_)) {
                        fn_801F2618(this_, 0, 0);
                        return;
                    }
                }
            }
        }
    }
    case 1: {
        f32 b = *(f32*)(this_ + 0x270);
        f32 a = *(f32*)(this_ + 0x26c);
        *(f32*)(this_ + 0x60) = -28.0f + a;
        *(f32*)(this_ + 0x64) = -7.0f + b;
        *(f32*)(this_ + 0x68) = 28.0f + a;
        *(f32*)(this_ + 0x6c) = 7.0f + b;
        *(OkamBox*)(this_ + 0x80) = *(OkamBox*)(this_ + 0x60);
        fn_801F2B7C(this_, -100, -1, 1);
        break;
    }
    case 6: {
        f32 b = *(f32*)(this_ + 0x270);
        f32 a = *(f32*)(this_ + 0x26c);
        *(f32*)(this_ + 0x60) = -6.0f + a;
        *(f32*)(this_ + 0x64) = -6.0f + b;
        *(f32*)(this_ + 0x68) = 6.0f + a;
        *(f32*)(this_ + 0x6c) = 6.0f + b;
        if (0 <= res) {
            fn_801EEC98(this_, *(s32*)(this_ + 0x198), 0, &flag, 0, 0, res, 2);
            if (flag >= 0) {
                if ((flag & 2) == 0) {
                    if (fn_801F305C(this_)) {
                        fn_801F2618(this_, 0, 0);
                        return;
                    }
                }
            }
        }
    }
    case 5: {
        f32 b = *(f32*)(this_ + 0x270);
        f32 a = *(f32*)(this_ + 0x26c);
        *(f32*)(this_ + 0x60) = -7.0f + a;
        *(f32*)(this_ + 0x64) = -28.0f + b;
        *(f32*)(this_ + 0x68) = 7.0f + a;
        *(f32*)(this_ + 0x6c) = 28.0f + b;
        *(OkamBox*)(this_ + 0x80) = *(OkamBox*)(this_ + 0x60);
        fn_801F2B7C(this_, -100, -1, 1);
        break;
    }
    }

    f32 x0 = *(f32*)(this_ + 0x60);
    f32 y0 = *(f32*)(this_ + 0x64);
    f32 x1 = *(f32*)(this_ + 0x68);
    register f32 y1 = *(f32*)(this_ + 0x6c);
    f32 px = *(f32*)(this_ + 0xc);
    f32 py = *(f32*)(this_ + 0x10);
    for (i = 0; i < 4; i++) {
        s32 hit = fn_801F285C(this_, 0, 0, 0, i);
        if (0 <= hit) {
            x0 += px;
            x1 += px;
            y0 += py;
            y1 += py;
            pos[0] = 0.5f * (x0 - x1) + x1;
            pos[1] = 0.5f * (y0 - y1) + y1;
            if (fn_80237948(hit, pos)) {
                fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, 1.0f, 0x117, 0, 1, 0, 0, 1);
                fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, 1.0f, 0x118, 0, 1, 0, 0, 1);
                fn_801F0E34(this_, 0x400d1, 0);
            }
        }
    }
}
#pragma opt_common_subs reset
static inline double okamAbs(double x) { return __fabs(x); }

struct OkamDrawParam {
    OkamDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = NULL;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};

struct OkamResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* getRes(u32 type, const char* name);
};

struct OkamGame {
    u8 pad0[0xa4];
    OkamResMgr* mRes;
};

extern const char* lbl_804A33D0[];
extern "C" void fn_801EFD34(void* self, void* tex, f32 sx, f32 sy, f32 z, OkamDrawParam* prm, s32 a);

extern "C" void fn_801AEA24(u8* self) {
    OkamDrawParam prm;
    prm.reset();
    void* tex = ((OkamGame*)lbl_8053AAF8)->mRes->getRes('TIMG', lbl_804A33D0[*(s32*)(self + 0x24c)]);
    fn_801EFD34(self, tex, *(f32*)(self + 0x26c), *(f32*)(self + 0x270), 0.0f, &prm, -1);
}

extern "C" s32 fn_801F3D94(char* this_, s32 a);
extern "C" void fn_801F71A4(f32* v, f32 target, f32 step, f32 limit);
extern "C" u8 fn_8023F264(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" u8 fn_80235580(s32 i);
extern "C" u8 fn_8022F478(s32 i);
extern "C" u8 fn_80230188(s32 i);
extern "C" u8 fn_8022DCD8(s32 i);
extern "C" f32* fn_8023E724(s32 i);
extern "C" u8 fn_801F23BC(char* this_, s32 room, f32* pos, f32* other, f32* box, f32* a, f32* b, s32 c);
extern "C" void fn_801AEB8C(char* this_) {
    f32 hitA[3];
    f32 hitB[3];
    s32 room;
    s32 i;

    if (fn_801F3D94(this_, 1)) {
        fn_801F2618(this_, 0, 0);
        return;
    }
    fn_801F71A4((f32*)(this_ + 0x3c), *(f32*)(this_ + 0x260), 0.3f, 1.0f);
    fn_801F71A4((f32*)(this_ + 0x40), *(f32*)(this_ + 0x264), 0.3f, 1.0f);
    fn_801F71A4((f32*)(this_ + 0x26c), *(f32*)(this_ + 0x278), 0.5f, 1.0f);
    fn_801F71A4((f32*)(this_ + 0x270), *(f32*)(this_ + 0x27c), 0.5f, 1.0f);
    *(JGeometry::TVec3f*)(this_ + 0xc) += *(JGeometry::TVec3f*)(this_ + 0x3c);
    fn_801AF1EC(this_);
    u8 hit = fn_801F2618(this_, 0, 0);
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        *(s32*)(this_ + 0x244) = -1;
        *(f32*)(this_ + 0x268) = 0.0f;
        *(f32*)(this_ + 0x264) = 0.0f;
        *(f32*)(this_ + 0x260) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(s32*)(this_ + 0x238) = 0;
        *(s32*)(this_ + 0x230) = 1;
    case 1:
        if (hit) {
            if (*(s32*)(this_ + 0x244) != 0 && *(s32*)(this_ + 0x258) != 0 && *(s32*)(this_ + 0x258) != 4) {
                *(s32*)(this_ + 0x230) = 2;
            }
            *(f32*)(this_ + 0x260) *= -1.0f;
            *(f32*)(this_ + 0x264) *= -1.0f;
            *(f32*)(this_ + 0x3c) *= -1.0f;
            *(f32*)(this_ + 0x40) *= -1.0f;
            break;
        }
        for (i = 0; i < 4; i++) {
            if (fn_8023F264(i)) {
                room = *(s32*)(this_ + 4);
                if (room == fn_8023DE58(i) && !fn_80235580(i) && !fn_8022F478(i) && !fn_80230188(i) && !fn_8022DCD8(i)) {
                    f32 dx = okamAbs(*(f32*)(this_ + 0xc) - fn_8023E724(i)[0]);
                    f32 dy = okamAbs(*(f32*)(this_ + 0x10) - fn_8023E724(i)[1]);
                    s32 vert = *(u32*)(this_ + 0x98) & 2;
                    if (((!vert && dy < 16.0f) || (vert && dx < 16.0f)) &&
                        !fn_801F23BC(this_, *(s32*)(this_ + 4), (f32*)(this_ + 0xc), fn_8023E724(i), (f32*)(this_ + 0x70), hitA, hitB, 0) &&
                        (*(s32*)(this_ + 0x244) < 0 || *(s32*)(this_ + 0x244) == i)) {
                        if (*(s32*)(this_ + 0x238) == 0) {
                            *(s32*)(this_ + 0x244) = i;
                            fn_801F0E34(this_, 0x400d3, 0);
                            if (*(s32*)(this_ + 0x250) == 0) {
                                if (fn_8023E724(i)[0] > *(f32*)(this_ + 0xc)) {
                                    *(f32*)(this_ + 0x260) = 0.7f;
                                } else {
                                    *(f32*)(this_ + 0x260) = -0.7f;
                                }
                            } else {
                                if (fn_8023E724(i)[1] > *(f32*)(this_ + 0x10)) {
                                    *(f32*)(this_ + 0x264) = 0.7f;
                                } else {
                                    *(f32*)(this_ + 0x264) = -0.7f;
                                }
                            }
                            if (*(s32*)(this_ + 0x250) == 0) {
                                fn_801AF7D0(this_, 1);
                            } else {
                                fn_801AF7D0(this_, 5);
                            }
                            u32* seed = (u32*)((char*)lbl_8053AAF8 + 0xb4);
                            *seed = *seed * 0x19660d + 0x3c6ef35f;
                            union { f32 f; u32 u; } r;
                            r.u = (*seed >> 9) | 0x3f800000;
                            *(s32*)(this_ + 0x238) = (s32)(50.0f * (r.f - 1.0f)) + 0x32;
                        }
                        break;
                    }
                }
            }
            if (*(s32*)(this_ + 0x244) == i) {
                if (*(s32*)(this_ + 0x258) == 0 || *(s32*)(this_ + 0x258) == 4) {
                    *(s32*)(this_ + 0x230) = 0;
                } else {
                    *(s32*)(this_ + 0x230) = 2;
                }
                break;
            }
        }
        break;
    case 2:
        if (*(s32*)(this_ + 0x250) == 0) {
            fn_801AF7D0(this_, 3);
        } else {
            fn_801AF7D0(this_, 7);
        }
        *(f32*)(this_ + 0x268) = 0.0f;
        *(f32*)(this_ + 0x264) = 0.0f;
        *(f32*)(this_ + 0x260) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(s32*)(this_ + 0x230) = 3;
    case 3:
        if (*(u8*)(this_ + 0x25c) == 1) {
            *(s32*)(this_ + 0x230) = 0;
        }
        break;
    }
    fn_801AF678(this_);
    char* t = this_;
    for (s32 k = 0; k < 3; k++) {
        if (*(s32*)(t + 0x234) > 0) {
            *(s32*)(t + 0x234) = *(s32*)(t + 0x234) - 1;
        }
        t += 4;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
