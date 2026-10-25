// TKTA_801549B0: .text 0x801549B0-0x801555D8 (actor TKTA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JMath/JMath.h"

extern const f32 lbl_8053D330;
extern const f32 lbl_8053D334;
extern const f32 lbl_8053D338;
extern const f32 lbl_8053D340;
extern const f32 lbl_8053D344;
extern const f32 lbl_8053D350;
extern const f32 lbl_8053D358;
extern "C" void fn_802D6A9C();
extern "C" u8 fn_802DCD0C();
extern "C" u16 fn_80226998(f32* pos, void* room);
extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" u8 fn_801F305C(void* this_);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" void fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" void fn_801F71A4(void* vec, f32 a, f32 b, f32 c);

// ---- from Game/fn_801549B0_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049FD50[];

extern "C" void* fn_801549B0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049FD50;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_80154A10.cpp

extern "C" void* SpatialRegistry_GetBase();
extern "C" void fn_801F8544(void* base, u32 fourCC, u32 owner, void* posPtr, s32 flag);
extern "C" void Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, s32 a, s32 b, s32 c);
extern "C" void fn_801F4F28(void* this_);

extern "C" void fn_80154A10(void* this_) {
    char* p = (char*)this_;
    *(s32*)(p + 0x18c) = 0;
    if (*(u32*)(p + 0x90) != 0) {
        void* base = SpatialRegistry_GetBase();
        fn_801F8544(base, 0x52555059, *(u32*)(p + 0x4), p + 0xc, 3);
    } else {
        void* base = SpatialRegistry_GetBase();
        Actor_CreateByID(base, 0x48415254, *(u32*)(p + 0x4), p + 0xc, 0, -1, -1);
    }
    fn_801F4F28(this_);
}

extern "C" void fn_801F06F0(void* this_, void* table, u32 id, void* data, f32 f1, f32 f2, s32 mode);
extern char lbl_80465DE8[];
extern const f32 lbl_8053D330;
extern const f32 lbl_8053D334;

extern "C" void fn_80154A98(char* this_) {
    f32 mtx[3][4];
    u8 buf[0x48];

    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = -1;

    for (u8 i = 0; i < 16; i++) {
        buf[i] = i;
    }

    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = 0;
    *(s32*)(buf + 0x18) = 0;
    buf[0x1c] = 0;
    buf[0x1d] = 0;
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

    mtx[0][3] = lbl_8053D330;
    mtx[1][3] = lbl_8053D330;
    mtx[2][3] = lbl_8053D330;

    if (!(*(u32*)(this_ + 0x90) & 2)) {
        if (*(u32*)(this_ + 0x90) != 0) {
            f32 sx = *(f32*)(this_ + 0x54);
            f32 sy = *(f32*)(this_ + 0x58);
            f32 sz = *(f32*)(this_ + 0x5c);
            mtx[0][0] = sx;
            mtx[0][1] = lbl_8053D330;
            mtx[0][2] = lbl_8053D330;
            mtx[1][0] = lbl_8053D330;
            mtx[1][1] = sy;
            mtx[1][2] = lbl_8053D330;
            mtx[2][0] = lbl_8053D330;
            mtx[2][1] = lbl_8053D330;
            mtx[2][2] = sz;
            buf[0x1f] = 0;
            *(void**)(buf + 0x18) = mtx;
        }
        fn_801F06F0(this_, lbl_80465DE8, *(s32*)(this_ + 0x250) + (*(s32*)(this_ + 0x90) * 3 + 0x49), buf, lbl_8053D334, lbl_8053D334, 7);
    }
}

struct TktaRandom {
    unsigned int seed;
    unsigned int next() {
        seed = seed * 0x19660d + 0x3c6ef35f;
        return seed;
    }
    f32 get() {
        union { f32 f; u32 s; } out;
        out.s = (next() >> 9) | 0x3f800000;
        return out.f - lbl_8053D334;
    }
};
struct TktaGame { u8 pad[0xb4]; TktaRandom rnd; };
extern TktaGame* lbl_8053AAF8;
extern "C" void fn_801EEC98(void* this_, u32 a, u16* ang, s32* out, s32 b, s32 c, s32 d, s32 e);
extern const f32 lbl_8053D33C;
extern const f32 lbl_8053D348;
extern const f32 lbl_8053D34C;
extern const f32 lbl_8053D354;
extern "C" void fn_8013CC50(u32 room, Vec* pos, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);
#include "JSystem/JGeometry/Vec.h"

extern "C" void fn_80154C30(void* this_) {
    char* p = (char*)this_;
    u8 hit;

    if (*(u32*)(p + 0x90) == 2 || *(u32*)(p + 0x90) == 3) {
        if (*(u16*)(p + 0x254) == 0xffff) {
            fn_802D6A9C();
            if (fn_802DCD0C()) {
                return;
            }
            void* room = *(void**)(p + 4);
            JGeometry::TVec2<f32> xy(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
            *(u16*)(p + 0x254) = fn_80226998(&xy.x, room);
            return;
        }
        void* room = *(void**)(p + 4);
            JGeometry::TVec2<f32> xy(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
        if (*(u16*)(p + 0x254) == fn_80226998(&xy.x, room)) {
            return;
        }
        *(u32*)(p + 0x90) &= 1;
    }

    if (fn_801F3D94(this_, 1) != 0) {
        fn_801F2618(this_, 0, 0);
        return;
    }
    if (*(s32*)(p + 0x230) == 0 && fn_801F305C(this_)) {
        *(s32*)(p + 0x238) = 0;
        fn_801F2618(this_, 0, 0);
        return;
    }
    if (*(s32*)(p + 0x234) > 0) {
        *(s32*)(p + 0x234) -= 1;
    }
    if (*(s32*)(p + 0x238) > 0) {
        *(s32*)(p + 0x238) -= 1;
    }
    if (*(s32*)(p + 0x23c) > 0) {
        *(s32*)(p + 0x23c) -= 1;
    }
    fn_801F71A4(p + 0x3c, *(f32*)(p + 0x258), lbl_8053D338, lbl_8053D334);
    fn_801F71A4(p + 0x40, *(f32*)(p + 0x25c), lbl_8053D338, lbl_8053D334);
    ((JGeometry::TVec3<f32>*)(p + 0xc))->add(*(JGeometry::TVec3<f32>*)(p + 0x3c));
    fn_801F2B7C(this_, -100, -1, 1);
    hit = fn_801F2618(this_, 0, 0);

    switch (*(s32*)(p + 0x230)) {
    case 0:
        if (*(s32*)(p + 0x238) == 0) {
            u16 ang = 0;
            s32 out = 0;
            if (!(*(u32*)(p + 0x90) & 1)) {
                *(f32*)(p + 0x44) = lbl_8053D33C;
            } else {
                *(f32*)(p + 0x44) = lbl_8053D340;
            }
            f32 chance = lbl_8053AAF8->rnd.get();
            if (chance < lbl_8053D344) {
                fn_801EEC98(this_, *(u32*)(p + 0x198), &ang, &out, 0, 0, 0, 0);
            } else {
                TktaGame* game = lbl_8053AAF8;
                ang = (s32)(lbl_8053D348 * game->rnd.get());
            }
            *(f32*)(p + 0x258) = lbl_8053D34C * JMath::sincosTable_.sinShort(ang);
            *(f32*)(p + 0x25c) = lbl_8053D34C * JMath::sincosTable_.cosShort(ang);
            if (out == -1) {
                *(f32*)(p + 0x258) = lbl_8053D330;
                *(f32*)(p + 0x25c) = lbl_8053D330;
                *(f32*)(p + 0x260) = lbl_8053D330;
            }
            *(u32*)(p + 0xb0) = 0;
            *(s32*)(p + 0x250) = 2;
            *(s32*)(p + 0x230) = 1;
        } else if (*(s32*)(p + 0x234) == 0) {
            (*(s32*)(p + 0x250))++;
            *(s32*)(p + 0x250) &= 1;
            *(s32*)(p + 0x234) = 8;
        }
        break;
    case 1:
        if (hit) {
            *(f32*)(p + 0x258) = lbl_8053D330;
            *(f32*)(p + 0x25c) = lbl_8053D330;
            *(f32*)(p + 0x260) = lbl_8053D330;
            *(f32*)(p + 0x3c) = lbl_8053D330;
            *(f32*)(p + 0x40) = lbl_8053D330;
        }
        *(f32*)(p + 0x44) -= lbl_8053D350;
        if (*(f32*)(p + 0x14) <= 0.0f && *(f32*)(p + 0x44) < 0.0f) {
            JGeometry::TVec3<f32> v;
            v.set(*(JGeometry::TVec3<f32>*)(p + 0xc));
            v.y += lbl_8053D354;
            fn_8013CC50(*(u32*)(p + 4), &v, 0x3cf, 0, 0, 0, 0, 1, lbl_8053D334);
            *(s32*)(p + 0x234) = 16;
            *(s32*)(p + 0x250) = 1;
            *(f32*)(p + 0x258) = lbl_8053D330;
            *(f32*)(p + 0x25c) = lbl_8053D330;
            *(f32*)(p + 0x260) = lbl_8053D330;
            *(f32*)(p + 0x44) = lbl_8053D330;
            *(f32*)(p + 0x14) = lbl_8053D330;
            *(u32*)(p + 0xb0) = 0x11101;
            *(s32*)(p + 0x238) = (s32)(lbl_8053D358 * lbl_8053AAF8->rnd.get()) + 50;
            if ((*(u32*)(p + 0x90) & 1) && *(s32*)(p + 0x108) < 8) {
                TktaGame* game = lbl_8053AAF8;
                *(s32*)(p + 0x238) = (s32)(lbl_8053D354 * game->rnd.get()) + 4;
            }
            *(s32*)(p + 0x230) = 0;
        }
        break;
    }
}
extern const f32 lbl_8053D35C;
extern const f32 lbl_8053D360;
extern const f32 lbl_8053D364;
extern const f32 lbl_8053D368;
extern const f32 lbl_8053D36C;
extern const f32 lbl_8053D370;

extern "C" void fn_8015512C(char* this_) {
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(u32*)(this_ + 0x90) &= 7;
    if (!(*(u32*)(this_ + 0x90) & 1)) {
        *(f32*)(this_ + 0x60) = lbl_8053D35C;
        *(f32*)(this_ + 0x64) = lbl_8053D35C;
        *(f32*)(this_ + 0x68) = lbl_8053D33C;
        *(f32*)(this_ + 0x6c) = lbl_8053D33C;
        *(f32*)(this_ + 0x80) = lbl_8053D360;
        *(f32*)(this_ + 0x84) = lbl_8053D360;
        *(f32*)(this_ + 0x88) = lbl_8053D354;
        *(f32*)(this_ + 0x8c) = lbl_8053D354;
        *(s32*)(this_ + 0x108) = 4;
    } else {
        *(f32*)(this_ + 0x54) = lbl_8053D364;
        *(f32*)(this_ + 0x58) = lbl_8053D364;
        *(f32*)(this_ + 0x5c) = lbl_8053D364;
        *(f32*)(this_ + 0x60) = lbl_8053D360;
        *(f32*)(this_ + 0x64) = lbl_8053D360;
        *(f32*)(this_ + 0x68) = lbl_8053D354;
        *(f32*)(this_ + 0x6c) = lbl_8053D354;
        *(f32*)(this_ + 0x80) = lbl_8053D368;
        *(f32*)(this_ + 0x84) = lbl_8053D368;
        *(f32*)(this_ + 0x88) = lbl_8053D36C;
        *(f32*)(this_ + 0x8c) = lbl_8053D36C;
        *(s32*)(this_ + 0x108) = 8;
    }
    *(f32*)(this_ + 0x258) = lbl_8053D330;
    *(f32*)(this_ + 0x25c) = lbl_8053D330;
    *(f32*)(this_ + 0x260) = lbl_8053D330;
    *(f32*)(this_ + 0x3c) = lbl_8053D330;
    *(f32*)(this_ + 0x40) = lbl_8053D330;
    *(f32*)(this_ + 0x44) = lbl_8053D330;
    *(u16*)(this_ + 0x254) = 0xffffu;
    if (*(u32*)(this_ + 0x90) == 4 || *(u32*)(this_ + 0x90) == 5) {
        u16 ang;
        s32 hit;
        ang = (s32)(lbl_8053D348 * lbl_8053AAF8->rnd.get());
        fn_801EEC98(this_, *(u32*)(this_ + 0x198), &ang, &hit, 0, 0, 0, 0);
        if (hit >= 0) {
            ang += 0x8000;
        }
        *(f32*)(this_ + 0x258) = lbl_8053D34C * JMath::sincosTable_.sinShort(ang);
        *(f32*)(this_ + 0x25c) = lbl_8053D34C * JMath::sincosTable_.cosShort(ang);
        *(f32*)(this_ + 0x44) = lbl_8053D33C;
        *(s32*)(this_ + 0x238) = 0;
        *(u32*)(this_ + 0x90) &= 1;
        *(u32*)(this_ + 0xb0) = 0;
        *(s32*)(this_ + 0x250) = 2;
        *(s32*)(this_ + 0x230) = 1;
    } else {
        TktaGame* gm = lbl_8053AAF8;
        *(s32*)(this_ + 0x238) = (s32)(lbl_8053D370 * gm->rnd.get()) + 20;
        *(s32*)(this_ + 0x250) = 0;
        *(u32*)(this_ + 0xb0) = 0x11101;
        *(s32*)(this_ + 0x230) = 0;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
