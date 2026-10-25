// GNMA actor. TU 801AAC8C-801AC8EC.
// Functions: draw (TODO), update (slot 3), state handlers (TODO), hit reaction
// (TODO), dtor, init (TODO).
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_80138B7C(void* game);
extern "C" void fn_801AB6A8(void* this_);
extern "C" void fn_801AAF44(char* this_);
extern void* lbl_804A307C[];
extern char* lbl_8053AAF8;
extern s32 lbl_8053ABD8;
extern void* lbl_8053AB10;
extern void* lbl_8053AF80;
extern const f32 lbl_8053E794;
extern const f32 lbl_8053E744;
extern u8 sincosTable___5JMath[];
extern const f32 lbl_8053E750;
extern const f32 lbl_8053E754;
extern const f32 lbl_8053E758;
extern const f32 lbl_8053E75C;
extern const f32 lbl_8053E770;
extern const f32 lbl_8053E774;
extern const f32 lbl_8053E778;
extern const f32 lbl_8053E77C;
extern const f32 lbl_8053E760;
extern const f32 lbl_8053E764;
extern const f32 lbl_8053E768;
extern const f32 lbl_8053E76C;
extern const f32 lbl_8053E780;
extern const f32 lbl_8053E784;
extern const f32 lbl_8053E788;
extern const f32 lbl_8053E78C;
extern const f32 lbl_8053E790;
extern const f32 lbl_8053E798;
extern const f32 lbl_8053E7A0;
extern "C" void fn_8030C210(void* a, void* b);
extern "C" s32 fn_801F3D94(void* p, s32 n);
extern "C" u32 fn_801F2618(void* p, s32 a, s32 b);
extern "C" u8 fn_801F2DB4(void* p, u32 a, u32 b, s32 c);
extern "C" void fn_801F71A4(void* v, f32 a, f32 b, f32 c);
extern "C" void fn_801F2B7C(void* p, ...);
extern "C" void fn_801EEC98(void* p, void* h, u16* out, s32 a, s32 b, s32 c, s32 d, s32 e, f32 f);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 room, void* pos, s32 a, s32 b, s32 c);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 ClassifyBamAngleToQuadrant(u16 a);
extern "C" void fn_80458FF0(void* a, s32 b, s32 c, s32 d);

struct GnmaTimers { u8 pad[0x234]; s32 t[4]; };

// GNMA update (vtable slot 3)
extern "C" void fn_801AAE88(char* this_) {
    switch (*(s32*)(this_ + 0x254)) {
    case 0:
    case 2:
        fn_801AB6A8(this_);
        break;
    case 1:
    case 3:
        fn_801AAF44(this_);
        break;
    }
    for (int i = 0; i < 4; i++) {
        if (((GnmaTimers*)this_)->t[i] > 0) {
            ((GnmaTimers*)this_)->t[i]--;
        }
    }
}

extern "C" void fn_801AAF44(char* p) {
    fn_8030C210(*(void**)((u8*)lbl_8053AB10 + 0x24), p + 0xc);
    if (fn_801F3D94(p, 1) != 0) {
        fn_801F2618(p, 0, 0);
        return;
    }
    if (*(s32*)(p + 0x108) < 1000) {
        ((void (**)(char*))*(void**)p)[9](p);
        *(s32*)(p + 0xb0) = 0;
        return;
    }
    f32 sz = *(f32*)(p + 0x44);
    f32 sy = *(f32*)(p + 0x40);
    f32 sx = *(f32*)(p + 0x3c);
    if (fn_801F2DB4(p, 'NULL', 'HBMB', 0)) {
        *(f32*)(p + 0x3c) = sx;
        *(f32*)(p + 0x40) = sy;
        *(f32*)(p + 0x44) = sz;
        *(s32*)(p + 0xd8) = 0;
        *(s32*)(p + 0xdc) = 0;
        fn_801F71A4(p + 0x3c, *(f32*)(p + 0x264), lbl_8053E750, lbl_8053E754);
        fn_801F71A4(p + 0x40, *(f32*)(p + 0x268), lbl_8053E750, lbl_8053E754);
    }
    *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);
    fn_801F2B7C(p);
    u32 r31 = fn_801F2618(p, 0, 0);
    *(f32*)(p + 0x270) = lbl_8053E758;
    *(f32*)(p + 0x274) = lbl_8053E75C;
    *(f32*)(p + 0x278) = lbl_8053E75C;
    *(f32*)(p + 0x60) = lbl_8053E760;
    *(f32*)(p + 0x64) = lbl_8053E764;
    *(f32*)(p + 0x68) = lbl_8053E768;
    *(f32*)(p + 0x6c) = lbl_8053E76C;
    *(f32*)(p + 0x80) = lbl_8053E760;
    *(f32*)(p + 0x84) = lbl_8053E770;
    *(f32*)(p + 0x88) = lbl_8053E768;
    *(f32*)(p + 0x8c) = lbl_8053E774;
    *(f32*)(p + 0x70) = lbl_8053E778;
    *(f32*)(p + 0x74) = lbl_8053E764;
    *(f32*)(p + 0x78) = lbl_8053E77C;
    *(f32*)(p + 0x7c) = lbl_8053E76C;
    switch (*(s32*)(p + 0x230)) {
    case 7: {
        fn_80458FF0(lbl_8053AF80, 0x100004, 0, 0);
        *(s32*)(p + 0x230) = 8;
        *(s32*)(p + 0x234) = 0;
        *(u32*)(lbl_8053AAF8 + 0xb4) = 0x19660d * *(u32*)(lbl_8053AAF8 + 0xb4) + 0x3c6ef35f;
        union { f32 f; u32 s; } out;
        out.s = (*(u32*)(lbl_8053AAF8 + 0xb4) >> 9) | 0x3f800000;
        *(s32*)(p + 0x23c) = (s32)(lbl_8053E780 * (out.f - lbl_8053E754)) + 0xc8;
        *(s32*)(p + 0x244) = 0;
        *(s32*)(p + 0x98) = *(s32*)(p + 0x260);
        *(f32*)(p + 0x44) = lbl_8053E744;
        *(f32*)(p + 0x40) = lbl_8053E744;
        *(f32*)(p + 0x3c) = lbl_8053E744;
        f32 a = lbl_8053E784 + lbl_8053E788 * (f32)(3 - *(s32*)(p + 0x258));
        switch (*(s32*)(p + 0x98)) {
        case 0:
            *(f32*)(p + 0x264) = a;
            *(f32*)(p + 0x268) = lbl_8053E744;
            *(f32*)(p + 0x26c) = lbl_8053E744;
            break;
        case 1:
            *(f32*)(p + 0x264) = -a;
            *(f32*)(p + 0x268) = lbl_8053E744;
            *(f32*)(p + 0x26c) = lbl_8053E744;
            break;
        case 2:
            *(f32*)(p + 0x264) = lbl_8053E744;
            *(f32*)(p + 0x268) = a;
            *(f32*)(p + 0x26c) = lbl_8053E744;
            break;
        case 3:
            *(f32*)(p + 0x264) = lbl_8053E744;
            *(f32*)(p + 0x268) = -a;
            *(f32*)(p + 0x26c) = lbl_8053E744;
            break;
        }
        *(s32*)(p + 0x98) = 2;
        *(s32*)(p + 0x238) = (s32)(lbl_8053E78C - lbl_8053E790 * (f32)(3 - *(s32*)(p + 0x258)));
        *(s32*)(p + 0x230) = 9;
        if (r31 & 0xff) {
            *(s32*)(p + 0x260) ^= 1;
            *(s32*)(p + 0x98) = *(s32*)(p + 0x260);
            *(f32*)(p + 0x44) = lbl_8053E744;
            *(f32*)(p + 0x40) = lbl_8053E744;
            *(f32*)(p + 0x3c) = lbl_8053E744;
            f32 b = lbl_8053E784 + lbl_8053E788 * (f32)(3 - *(s32*)(p + 0x258));
            switch (*(s32*)(p + 0x98)) {
            case 0:
                *(f32*)(p + 0x264) = b;
                *(f32*)(p + 0x268) = lbl_8053E744;
                *(f32*)(p + 0x26c) = lbl_8053E744;
                break;
            case 1:
                *(f32*)(p + 0x264) = -b;
                *(f32*)(p + 0x268) = lbl_8053E744;
                *(f32*)(p + 0x26c) = lbl_8053E744;
                break;
            case 2:
                *(f32*)(p + 0x264) = lbl_8053E744;
                *(f32*)(p + 0x268) = b;
                *(f32*)(p + 0x26c) = lbl_8053E744;
                break;
            case 3:
                *(f32*)(p + 0x264) = lbl_8053E744;
                *(f32*)(p + 0x268) = -b;
                *(f32*)(p + 0x26c) = lbl_8053E744;
                break;
            }
            *(s32*)(p + 0x98) = 2;
        }
        if (*(s32*)(p + 0x238) == 0) {
            f32 oldy = *(f32*)(p + 0x10);
            f32 keepx = *(f32*)(p + 0xc);
            f32 keepz = *(f32*)(p + 0x14);
            *(f32*)(p + 0x10) = oldy + lbl_8053E794;
            u16 angle = 0;
            s32 n = 1;
            s32 key = 0;
            fn_801EEC98(p, *(void**)(p + 0x198), &angle, 0, 0, 0, 0, 4, oldy);
            if (*(s32*)(p + 0x258) == 1) {
                angle -= 0x2000;
                n = 3;
                key = 0x4f4b544d;
            }
            for (s32 i = 0; i < n; i++) {
                s32 id = Actor_CreateByID(fn_801F856C(), 0x4f4b544d, *(s32*)(p + 0x4), p + 0xc, 4, -1, -1);
                if (id >= 0) {
                    char* na = (char*)fn_801F666C(fn_801F856C(), id);
                    if (na != 0) {
                        f32* tab = (f32*)((char*)sincosTable___5JMath + ((angle >> 5) << 3));
                        *(f32*)(na + 0x3c) = lbl_8053E798 * tab[0];
                        *(f32*)(na + 0x40) = lbl_8053E798 * tab[1];
                        *(f32*)(na + 0x44) = lbl_8053E744;
                        *(s32*)(na + 0x98) = ClassifyBamAngleToQuadrant(angle);
                        *(s32*)(p + 0x238) = (s32)(lbl_8053E78C - lbl_8053E790 * (f32)(3 - *(s32*)(p + 0x258)));
                    }
                }
                angle += 0x2000;
            }
            *(f32*)(p + 0xc) = keepx;
            *(f32*)(p + 0x10) = oldy;
            *(f32*)(p + 0x14) = keepz;
        }
        if (*(s32*)(p + 0x234) == 0) {
            if (*(s32*)(p + 0x248) == 0) {
                *(s32*)(p + 0x250) = *(s32*)(p + 0x244) + 0x13;
            } else {
                *(s32*)(p + 0x250) = *(s32*)(p + 0x244) + 8;
            }
            *(s32*)(p + 0x234) = 5;
            *(s32*)(p + 0x244) = (*(s32*)(p + 0x244) + 1) & 3;
        }
        if (*(s32*)(p + 0x23c) == 0) {
            *(f32*)(p + 0x26c) = lbl_8053E744;
            *(f32*)(p + 0x268) = lbl_8053E744;
            *(f32*)(p + 0x264) = lbl_8053E744;
            *(f32*)(p + 0x44) = lbl_8053E744;
            *(f32*)(p + 0x40) = lbl_8053E744;
            *(f32*)(p + 0x3c) = lbl_8053E744;
            if (*(s32*)(p + 0x248) == 0) {
                *(s32*)(p + 0x230) = 10;
            } else {
                *(s32*)(p + 0x230) = 12;
            }
            *(s32*)(p + 0x248) ^= 1;
        }
    } break;
    }
}

struct Handles_gnma { u8 pad[0x27c]; void* h[2]; };

// GNMA destructor
extern "C" void* fn_801AC324(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A307C;
        for (int i = 0; i < 2; i++) {
            fn_801EE434(((Handles_gnma*)this_)->h[i]);
        }
        s32 kind = *(s32*)(this_ + 0x254);
        if (kind == 2 || kind == 3) {
            if (--lbl_8053ABD8 == 0 && *(s32*)(lbl_8053AAF8 + 0x4c) != 9) {
                fn_80138B7C(lbl_8053AAF8);
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_801F6874(u16 angle);
extern const f32 lbl_8053E744;
extern const f32 lbl_8053E7B0;

extern "C" void fn_801AC1F4(char* p) {
    if (*(s32*)(p + 0x25c) == *(s32*)(p + 0x108)) {
        return;
    }
    if (*(s32*)(p + 0x258) > 0) {
        (*(s32*)(p + 0x258))--;
    }
    if (*(s32*)(p + 0x258) <= 0) {
        *(u32*)(p + 0xb0) = 0;
    }
    *(s32*)(p + 0x25c) = *(s32*)(p + 0x108);
    s32 mode = *(s32*)(p + 0x254);
    if (mode == 1 || mode == 3) {
        *(f32*)(p + 0x26c) = lbl_8053E744;
        *(f32*)(p + 0x268) = lbl_8053E744;
        *(f32*)(p + 0x264) = lbl_8053E744;
        *(f32*)(p + 0x44) = lbl_8053E744;
        *(f32*)(p + 0x40) = lbl_8053E744;
        *(f32*)(p + 0x3c) = lbl_8053E744;
        *(u32*)(p + 0xb0) = 0x0a040004;
        *(s32*)(p + 0x248) = 1;
        *(s32*)(p + 0x230) = 12;
    } else {
        u16 ang = (u16)*(u32*)(p + 0x98) + 0x8000;
        *(f32*)(p + 0x3c) = lbl_8053E7B0 * JMASSin(fn_801F6874(ang));
        *(f32*)(p + 0x40) = lbl_8053E7B0 * JMASCos(fn_801F6874(ang));
        *(s32*)(p + 0x230) = 5;
    }
}

extern "C" void fn_801EFD34(void* actor, void* res, DrawRec* rec, s32 n, f32 a, f32 b, f32 c);
extern u32 lbl_804A3020[];
extern const f32 lbl_8053E740;
extern const f32 lbl_8053E748;
extern const f32 lbl_8053E74C;

static inline void tu_setScale(f32 (*mtx)[4], f32 sx, f32 sy) {
    f32 zero = lbl_8053E744;
    mtx[0][0] = sx;
    mtx[0][1] = zero;
    mtx[0][2] = zero;
    mtx[1][0] = zero;
    mtx[1][1] = sy;
    mtx[1][2] = zero;
    mtx[2][0] = zero;
    mtx[2][1] = zero;
    mtx[2][2] = sy;
    mtx[0][3] = zero;
    mtx[1][3] = zero;
    mtx[2][3] = zero;
}

class GnmaResMgr {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* getRes(u32 type, u32 name);
};

extern "C" void fn_801AAC8C(char* p) {
    DrawRec rec;
    f32 mtx[3][4];
    f32 sx = *(f32*)(p + 0x270);
    if (*(s32*)(p + 0x98) == 0) {
        sx *= lbl_8053E740;
    }
    tu_setScale(mtx, sx, *(f32*)(p + 0x274));
    rec.w18 = mtx;
    s32 n = 4;
    f32 scale = lbl_8053E748;
    s32 mode = *(s32*)(p + 0x254);
    if (mode == 0 || mode == 2) {
        n = 3;
        scale = lbl_8053E74C;
    }
    void* res = (*(GnmaResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('TIMG', lbl_804A3020[*(s32*)(p + 0x250)]);
    fn_801EFD34(p, res, &rec, n, lbl_8053E744, scale, lbl_8053E744);
}

extern const f32 lbl_8053E754;

struct GnmaRandom {
    u32 seed;
    u32 get() {
        seed = 0x19660d * seed + 0x3c6ef35f;
        return seed;
    }
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        out.s = (get() >> 9) | 0x3f800000;
        return out.f - lbl_8053E754;
    }
};

extern "C" u8* fn_802D6A9C(void);
extern "C" s32 fn_80458F9C(void* mgr, s32 handle);
extern void* lbl_8053AF80;
extern const f32 lbl_8053E758;
extern const f32 lbl_8053E75C;
extern const f32 lbl_8053E770;
extern const f32 lbl_8053E774;
extern const f32 lbl_8053E778;
extern const f32 lbl_8053E77C;
extern const f32 lbl_8053E794;
extern const f32 lbl_8053E7B8;
extern const f32 lbl_8053E7C0;
extern const f32 lbl_8053E7C4;
extern const f32 lbl_8053E7C8;

struct GnmaCfg { u8 pad[0x131df]; u8 flags[8]; };
static inline u8 gnma_cfgFlagId(s32 id) {
    u8* cfg = fn_802D6A9C();
    return cfg[id + 0x131df];
}
#define gnma_cfgFlag(p) gnma_cfgFlagId(*(s32*)((p) + 0x4))

extern "C" void fn_801AC3F0(char* p) {
    *(f32*)(p + 0x60) = lbl_8053E7B0;
    *(f32*)(p + 0x64) = lbl_8053E7C0;
    *(f32*)(p + 0x68) = lbl_8053E7C4;
    *(f32*)(p + 0x6c) = lbl_8053E794;
    *(f32*)(p + 0x80) = lbl_8053E770;
    *(f32*)(p + 0x84) = lbl_8053E7C0;
    *(f32*)(p + 0x88) = lbl_8053E774;
    *(f32*)(p + 0x8c) = lbl_8053E794;
    *(f32*)(p + 0x70) = lbl_8053E778;
    *(f32*)(p + 0x74) = lbl_8053E778;
    *(f32*)(p + 0x78) = lbl_8053E77C;
    *(f32*)(p + 0x7c) = lbl_8053E77C;
    *(s32*)(p + 0x254) = *(u32*)(p + 0x90) & 0xf;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    for (int i = 0; i < 4; i++) {
        ((GnmaTimers*)p)->t[i] = 0;
    }
    *(s32*)(p + 0x27c) = 0;
    *(s32*)(p + 0x280) = 0;
    *(s32*)(p + 0xb8) = 1;
    *(s32*)(p + 0x98) = (s32)(lbl_8053E7B8 * ((GnmaRandom*)(lbl_8053AAF8 + 0xb4))->get_ufloat_1());
    *(s32*)(p + 0x98) &= 3;
    if (gnma_cfgFlag(p)) {
        *(s32*)(p + 0x98) &= 1;
    }
    *(s32*)(p + 0x250) = (*(s32*)(p + 0x98) << 2) + *(s32*)(p + 0x244);
    *(f32*)(p + 0x26c) = lbl_8053E744;
    *(f32*)(p + 0x268) = lbl_8053E744;
    *(f32*)(p + 0x264) = lbl_8053E744;
    *(s32*)(p + 0x108) = 0x3ef;
    *(s32*)(p + 0x258) = 3;
    *(s32*)(p + 0x260) = *(s32*)(p + 0x98);
    *(u32*)(p + 0xb0) = 0x0a040010;
    s32 mode = *(s32*)(p + 0x254);
    if (mode == 0 || mode == 2) {
        *(s32*)(p + 0x258) = 2;
        *(s32*)(p + 0xbc) = 2;
        *(f32*)(p + 0x270) = lbl_8053E754;
        *(f32*)(p + 0x274) = lbl_8053E754;
        *(f32*)(p + 0x278) = lbl_8053E754;
        if (gnma_cfgFlag(p)) {
            *(f32*)(p + 0x80) = lbl_8053E7C8;
            *(f32*)(p + 0x84) = lbl_8053E7C0;
            *(f32*)(p + 0x88) = lbl_8053E7B8;
            *(f32*)(p + 0x8c) = lbl_8053E794;
        }
        *(s32*)(p + 0x230) = 1;
        if (*(s32*)(p + 0x254) == 2 && lbl_8053ABD8 == 0) {
            fn_80458F9C(lbl_8053AF80, 0x3c);
            lbl_8053ABD8++;
            *(s32*)(p + 0x230) = 0;
        }
    } else {
        *(s32*)(p + 0xbc) = 3;
        *(s32*)(p + 0x108) = 0x3f2;
        *(s32*)(p + 0x260) = *(s32*)(p + 0x98) & 1;
        *(s32*)(p + 0x98) = 2;
        *(u32*)(p + 0xb0) = 0x0a040004;
        *(f32*)(p + 0x270) = lbl_8053E758;
        *(f32*)(p + 0x274) = lbl_8053E75C;
        *(f32*)(p + 0x278) = lbl_8053E75C;
        *(s32*)(p + 0xc0) = 3;
        *(s32*)(p + 0x98) &= 1;
        *(s32*)(p + 0x250) = 0x13;
        *(s32*)(p + 0x230) = 8;
        if (*(s32*)(p + 0x254) == 3 && lbl_8053ABD8 == 0) {
            fn_80458F9C(lbl_8053AF80, 0x3c);
            lbl_8053ABD8++;
            *(s32*)(p + 0x230) = 7;
        }
    }
    *(s32*)(p + 0x25c) = *(s32*)(p + 0x108);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
