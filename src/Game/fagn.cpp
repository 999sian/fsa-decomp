// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80184040-80184D64 (FAGN). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// from src/Game/fn_80184040_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A1888[];

extern "C" void* fn_80184040(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1888;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// from src/Game/fn_80184A14.cpp
extern "C" void* fn_80212AC0(void);
extern "C" void fn_80212AF0(void* registry, void* posPtr);
extern "C" void fn_801F5790(void* this_);

// fn_80184A14(this) - sibling of fn_8018316C (see that file's banner
// and project_fsa_80212af0_callers_closed.md) - a third class's
// vtable-slot-0x18 override doing the identical "repel from RUSA
// zones, then chain to the generic slot-0x18 default" pattern.
extern "C" void fn_80184A14(void* this_) {
    void* registry = fn_80212AC0();
    fn_80212AF0(registry, (char*)this_ + 0xc);
    fn_801F5790(this_);
}
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, f32 sx, f32 sy, s32 a, s32 b);

// FAGN draw (vtable slot 6)
extern "C" void fn_801840A0(char* this_) {
    fn_801F06F0(this_, "enemy_gc_sob.bin", *(s32*)(this_ + 0x24c) + 0x145, 1.0f, 1.0f, 0, 7);
}

struct FagnRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct FagnGame { u8 pad[0xb4]; FagnRandom rnd; };
extern FagnGame* lbl_8053AAF8;

// FAGN init (vtable slot 1)
extern "C" void fn_80184A50(char* this_) {
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
    FagnGame* g = lbl_8053AAF8;
    *(s32*)(this_ + 0x98) = (s32)(3.99f * g->rnd.get_ufloat_1());
    *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x98) * 4;
    *(f32*)(this_ + 0x260) = 0.0f;
    *(f32*)(this_ + 0x25c) = 0.0f;
    *(f32*)(this_ + 0x258) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0xb8) = 1;
    *(u8*)(this_ + 0x195) = 1;
    *(f32*)(this_ + 0x254) = 0.0f;
    *(f32*)(this_ + 0x250) = 1.0f;
    *(s32*)(this_ + 0x230) = 0;
}

extern "C" s32 fn_801F3D94(void* self, s32 a);
extern "C" u8 fn_801F305C(void* self);
extern "C" u8 fn_801F2618(void* self, void* a, u8 b);
extern "C" void fn_801F71A4(f32* v, f32 target, f32 rate, f32 step);
extern "C" u8 fn_801F2B7C(void* self, s32 a, s32 holder, s32 b);
extern "C" void fn_801EEC98(void* self, s32 room, s16* ang, s32* dir, f32* dist, s32* player, s32 b, s32 c);
extern "C" u16 fn_802265FC(JGeometry::TVec2<f32>* pos, s32 room);
extern "C" JGeometry::TVec3f* fn_8023E724(s32 idx);
extern "C" u8 fn_801F23BC(void* self, s32 room, void* pos, void* target, void* box, s32 a, s32 b, s32 c);
extern "C" void fn_801F0E34(void* self, u32 se, s32 b);
extern const s32 lbl_804A1808[];
extern const s32 lbl_804A1848[];

static inline void fagnFall(char* this_) {
    *(s32*)(this_ + 0xbc) = 2;
    if (*(f32*)(this_ + 0x14) > 0.0f) {
        *(f32*)(this_ + 0x44) -= 1.0f;
    } else {
        *(f32*)(this_ + 0x14) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
    }
    fn_801F2618(this_, 0, 0);
}

static inline void fagnSetDir(char* this_, f32 a, f32 b) {
    switch (*(s32*)(this_ + 0x98)) {
    case 0:
        *(f32*)(this_ + 0x258) = a;
        *(f32*)(this_ + 0x25c) = 0.0f;
        *(f32*)(this_ + 0x260) = 0.0f;
        break;
    case 1:
        *(f32*)(this_ + 0x258) = b;
        *(f32*)(this_ + 0x25c) = 0.0f;
        *(f32*)(this_ + 0x260) = 0.0f;
        break;
    case 2:
        *(f32*)(this_ + 0x258) = 0.0f;
        *(f32*)(this_ + 0x25c) = a;
        *(f32*)(this_ + 0x260) = 0.0f;
        break;
    case 3:
        *(f32*)(this_ + 0x258) = 0.0f;
        *(f32*)(this_ + 0x25c) = b;
        *(f32*)(this_ + 0x260) = 0.0f;
        break;
    }
}

static inline f32 fagnAbs(f32 x) { return __fabs(x); }

// FAGN update (vtable slot 5). Near-match (99%): LCG temp regs and jump-case float regs differ.
extern "C" void fn_801840E0(char* this_) {
    f32 px, py, bx0, by0, bx1, by1;
    bx0 = *(f32*)(this_ + 0x80);
    by0 = *(f32*)(this_ + 0x84);
    bx1 = *(f32*)(this_ + 0x88);
    by1 = *(f32*)(this_ + 0x8c);
    py = *(f32*)(this_ + 0x10);
    px = *(f32*)(this_ + 0xc);
    s16 ang = 0;
    f32 dist = 0.0f;
    s32 player = -1;
    s32 dir = -1;
    if (fn_801F3D94(this_, 1) != 0) {
        fagnFall(this_);
        return;
    }
    if (fn_801F305C(this_)) {
        fagnFall(this_);
        return;
    }
    fn_801F71A4((f32*)(this_ + 0x3c), *(f32*)(this_ + 0x258), 0.1f, *(f32*)(this_ + 0x250));
    fn_801F71A4((f32*)(this_ + 0x40), *(f32*)(this_ + 0x25c), 0.1f, *(f32*)(this_ + 0x250));
    ((JGeometry::TVec3f*)(this_ + 0xc))->add(*(JGeometry::TVec3f*)(this_ + 0x3c));
    fn_80212AF0(fn_80212AC0(), this_ + 0xc);
    fn_801F2B7C(this_, -100, -1, 1);
    fn_801EEC98(this_, *(s32*)(this_ + 0x198), &ang, &dir, &dist, &player, 0, 0);
    u8 hitWall = fn_801F2618(this_, 0, 0);
    bx0 += px;
    bx1 += px;
    by0 += py;
    by1 += py;
    JGeometry::TVec2<f32> c;
    c.x = 0.5f * (bx0 - bx1) + bx1;
    c.y = 0.5f * (by0 - by1) + by1;
    u16 ground = fn_802265FC(&c, *(s32*)(this_ + 0x4));
    *(f32*)(this_ + 0x250) = 1.0f;
    if (ground == 0x50) {
        *(f32*)(this_ + 0x250) = 0.01f;
    }
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        *(s32*)(this_ + 0x234) = 0;
        *(s32*)(this_ + 0x240) = 0;
        *(s32*)(this_ + 0xbc) = 2;
        *(s32*)(this_ + 0x230) = 1;
        // fallthrough
    case 1: {
        if (*(s32*)(this_ + 0x23c) == 0 && *(s32*)(this_ + 0x98) == dir
            && ((!(*(s32*)(this_ + 0x98) & 2) && fagnAbs(fn_8023E724(player)->y - *(f32*)(this_ + 0x10)) < 24.0f)
                || ((*(s32*)(this_ + 0x98) & 2) && fagnAbs(fn_8023E724(player)->x - *(f32*)(this_ + 0xc)) < 24.0f))) {
            if (!fn_801F23BC(this_, *(s32*)(this_ + 0x4), this_ + 0xc, fn_8023E724(player), this_ + 0x80, 0, 0, 0)) {
                *(s32*)(this_ + 0x230) = 2;
                break;
            }
        }
        if (hitWall || *(s32*)(this_ + 0x238) == 0) {
            u8 turn = hitWall;
            if (hitWall || ground != 0x50) {
                *(f32*)(this_ + 0x44) = 0.0f;
                *(f32*)(this_ + 0x40) = 0.0f;
                *(f32*)(this_ + 0x3c) = 0.0f;
            }
            *(s32*)(this_ + 0x238) = (s32)(100.0f * lbl_8053AAF8->rnd.get_ufloat_1()) + 50;
            if (!hitWall) {
                if (lbl_8053AAF8->rnd.get_ufloat_1() < 0.7f) {
                    if (dir != -1) {
                        if (*(s32*)(this_ + 0x98) == dir) {
                            break;
                        }
                        *(s32*)(this_ + 0x98) = dir;
                    }
                } else {
                    turn = 1;
                    *(s32*)(this_ + 0x234) = 8;
                }
            }
            if (turn) {
                if (!(*(s32*)(this_ + 0x98) & 2)) {
                    if (lbl_8053AAF8->rnd.get_ufloat_1() < 0.5f) {
                        *(s32*)(this_ + 0x98) = 2;
                    } else {
                        *(s32*)(this_ + 0x98) = 3;
                    }
                } else {
                    if (lbl_8053AAF8->rnd.get_ufloat_1() < 0.5f) {
                        *(s32*)(this_ + 0x98) = 0;
                    } else {
                        *(s32*)(this_ + 0x98) = 1;
                    }
                }
            }
        }
        fagnSetDir(this_, 0.7f, -0.7f);
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x24c) = lbl_804A1808[*(u32*)(this_ + 0x98) * 4 + *(u32*)(this_ + 0x240)];
            *(s32*)(this_ + 0x234) = lbl_804A1848[*(u32*)(this_ + 0x98) * 4 + *(u32*)(this_ + 0x240)];
            *(s32*)(this_ + 0x240) += 1;
            *(s32*)(this_ + 0x240) &= 3;
        }
        break;
    }
    case 2: {
        *(f32*)(this_ + 0x44) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x260) = 0.0f;
        *(f32*)(this_ + 0x25c) = 0.0f;
        *(f32*)(this_ + 0x258) = 0.0f;
        *(s32*)(this_ + 0x234) = 0;
        *(s32*)(this_ + 0x240) = 0;
        *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x98) + 12;
        fn_801F0E34(this_, 0x400ab, 0);
        *(f32*)(this_ + 0x254) = 5.0f;
        if (ground != 0x50) {
            *(f32*)(this_ + 0x254) = 3.0f;
        }
        switch (*(s32*)(this_ + 0x98)) {
        case 0:
            *(f32*)(this_ + 0x258) = *(f32*)(this_ + 0x254);
            *(f32*)(this_ + 0x25c) = 0.0f;
            *(f32*)(this_ + 0x260) = 0.0f;
            *(f32*)(this_ + 0x3c) = 0.3f * *(f32*)(this_ + 0x254);
            *(f32*)(this_ + 0x40) = 0.0f;
            *(f32*)(this_ + 0x44) = 5.0f;
            break;
        case 1:
            *(f32*)(this_ + 0x258) = -*(f32*)(this_ + 0x254);
            *(f32*)(this_ + 0x25c) = 0.0f;
            *(f32*)(this_ + 0x260) = 0.0f;
            *(f32*)(this_ + 0x3c) = -(0.3f * *(f32*)(this_ + 0x254));
            *(f32*)(this_ + 0x40) = 0.0f;
            *(f32*)(this_ + 0x44) = 5.0f;
            break;
        case 2: {
            f32 sp = *(f32*)(this_ + 0x254);
            *(f32*)(this_ + 0x258) = 0.0f;
            *(f32*)(this_ + 0x25c) = sp;
            *(f32*)(this_ + 0x260) = 0.0f;
            *(f32*)(this_ + 0x3c) = 0.0f;
            *(f32*)(this_ + 0x40) = 0.3f * *(f32*)(this_ + 0x254);
            *(f32*)(this_ + 0x44) = 5.0f;
            break;
        }
        case 3: {
            f32 sp = -*(f32*)(this_ + 0x254);
            *(f32*)(this_ + 0x258) = 0.0f;
            *(f32*)(this_ + 0x25c) = sp;
            *(f32*)(this_ + 0x260) = 0.0f;
            *(f32*)(this_ + 0x3c) = 0.0f;
            *(f32*)(this_ + 0x40) = -(0.3f * *(f32*)(this_ + 0x254));
            *(f32*)(this_ + 0x44) = 5.0f;
            break;
        }
        }
        *(s32*)(this_ + 0xbc) = 3;
        *(s32*)(this_ + 0x230) = 3;
        break;
    }
    case 3: {
        f32 rate = 0.05f;
        if (ground != 0x50) {
            rate = 0.1f;
        }
        if (*(f32*)(this_ + 0x14) > 0.0f) {
            *(f32*)(this_ + 0x44) -= 1.0f;
        }
        fn_801F71A4((f32*)(this_ + 0x258), 0.0f, 0.1f, rate);
        fn_801F71A4((f32*)(this_ + 0x25c), 0.0f, 0.1f, rate);
        if (*(f32*)(this_ + 0x14) <= 0.0f) {
            *(f32*)(this_ + 0x44) = 0.0f;
            if (hitWall
                || (fagnAbs(*(f32*)(this_ + 0x3c)) < 0.1f && *(f32*)(this_ + 0x258) < 0.1f
                    && fagnAbs(*(f32*)(this_ + 0x40)) < 0.1f && *(f32*)(this_ + 0x25c) < 0.1f)) {
                *(f32*)(this_ + 0x44) = 0.0f;
                *(f32*)(this_ + 0x40) = 0.0f;
                *(f32*)(this_ + 0x3c) = 0.0f;
                *(s32*)(this_ + 0x23c) = (s32)(100.0f * lbl_8053AAF8->rnd.get_ufloat_1()) + 50;
                *(s32*)(this_ + 0x230) = 0;
            }
        }
        break;
    }
    }
    for (s32 i = 0; i < 3; i++) {
        s32* t = (s32*)(this_ + i * 4);
        if (t[0x234 / 4] > 0) {
            t[0x234 / 4]--;
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
