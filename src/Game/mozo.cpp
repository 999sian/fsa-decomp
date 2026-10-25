// MOZO actor. TU 80166BD0-80167938.
// Functions: draw (slot 6, TODO), update (slot 3, TODO), init (slot 1),
// child release, dtor.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, void* rec, f32 sx, f32 sy, s32 mode);
extern "C" void fn_802F86CC(void* map, void* pos, void* res, s32 idx, void* rec, f32 sx, f32 sy);
extern u8* lbl_8053AAF8;
extern const f32 lbl_8053D7F8;
extern char* lbl_8053AB10;
extern "C" void fn_801F71A4(void* p, f32 a, f32 b, f32 c);
extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" u8 fn_801F305C(void* this_);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" void fn_801F0E34(void* this_, u32 code, s32 z);
extern "C" void fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" u16 fn_8022461C(void* p, s32 room);
extern "C" void* fn_8013CC50(s32 map, void* pos, f32 f, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void detach__5ActorFv(void* this_);
extern const f32 lbl_8053D7FC;
extern const f32 lbl_8053D800;
extern const f32 lbl_8053D804;
extern const f32 lbl_8053D808;
extern const f32 lbl_8053D80C;
extern const f32 lbl_8053D810;
extern const f32 lbl_8053D814;
extern const f32 lbl_8053D818;
extern const f32 lbl_8053D81C;
extern const f32 lbl_8053D820;
extern const f32 lbl_8053D824;
extern const f32 lbl_8053D828;
extern const f32 lbl_8053D82C;
extern const f32 lbl_8053D830;
extern const f32 lbl_8053D834;
extern const s32 lbl_804A0650[];
extern const s32 lbl_804A0638[];
extern "C" u8 sincosTable___5JMath[];

struct MozoResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};

static inline void mozoRotScale(f32 m[3][4], f32 rx, const f32* pry, f32 rz, const f32* ps) {
    m[0][3] = lbl_8053D7F8;
    m[1][3] = lbl_8053D7F8;
    m[2][3] = lbl_8053D7F8;
    f32 s;
    f32 ry;
    s = *ps;
    ry = *pry;
    f32 sz, sy, sx;
    f32 cz, cy, cx;
    sx = sin(rx);
    sy = sin(ry);
    sz = sin(rz);
    cx = cos(rx);
    cy = cos(ry);
    cz = cos(rz);
    f32 cxcz = cx * cz;
    f32 sxsy = sx * sy;
    f32 cxsz = cx * sz;
    f32 sxsz = sx * sz;
    f32 sxcz = sx * cz;
    m[0][0] = s * (cy * cz);
    m[1][0] = s * (cy * sz);
    m[2][0] = s * -sy;
    m[0][1] = s * (sxsy * cz - cxsz);
    m[1][1] = s * (sxsy * sz + cxcz);
    m[2][1] = s * (sx * cy);
    m[0][2] = s * (cxcz * sy + sxsz);
    m[1][2] = s * (cxsz * sy - sxcz);
    m[2][2] = s * (cx * cy);
}

static inline f32 mozoRand01() {
    u8* g = lbl_8053AAF8;
    u32 x = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
    *(u32*)(g + 0xb4) = x;
    u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
    return *(f32*)&bits - lbl_8053D7FC;
}

// MOZO draw (vtable slot 6)
extern "C" void fn_80166BD0(u8* this_) {
    if (*(s32*)(this_ + 0x230) == 3) {
        DrawRec r;
        f32 m[3][4];
        mozoRotScale(m, lbl_8053D7F8, (f32*)(this_ + 0x25c), lbl_8053D7F8, (f32*)(this_ + 0x258));
        r.w18 = m;
        s32 idx = *(s32*)(this_ + 0x250) + 0x9d;
        if (*(s32*)(this_ + 4) < 8) {
            void* res = (*(MozoResMgr**)(lbl_8053AAF8 + 0xa4))->get('SOB ', "enemy_gc_sob.bin");
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, idx, &r, 1.0f, 1.0f);
        }
    } else {
        fn_801F06F0(this_, "enemy_gc_sob.bin", *(s32*)(this_ + 0x250) + 0x9d, 0, 1.0f, 1.0f, 0);
    }
}

extern "C" void fn_80166EC4(u8* this_) {
    if (*(void**)(this_ + 0x26c) != 0) {
        fn_801F71A4(this_ + 0x254, lbl_8053D7F8, lbl_8053D7FC, lbl_8053D800);
        *(u8*)(*(u8**)(this_ + 0x26c) + 0xbb) = (u8)(s32)*(f32*)(this_ + 0x254);
    }
    if (fn_801F3D94(this_, 1) != 0 || fn_801F305C(this_)) {
        u8* c = *(u8**)(this_ + 0x26c);
        if (c != 0) {
            *(u32*)(c + 0xf4) |= 1;
            *(s32*)(c + 0x24) = 1;
            *(void**)(this_ + 0x26c) = 0;
        }
        fn_801F2618(this_, 0, 0);
        return;
    }
    if (*(s32*)(this_ + 0x234) > 0) *(s32*)(this_ + 0x234) -= 1;
    if (*(s32*)(this_ + 0x238) > 0) *(s32*)(this_ + 0x238) -= 1;
    if (*(s32*)(this_ + 0x23c) > 0) *(s32*)(this_ + 0x23c) -= 1;
    if (*(s32*)(this_ + 0x240) > 0) *(s32*)(this_ + 0x240) -= 1;
    fn_801F71A4(this_ + 0x3c, *(f32*)(this_ + 0x260), lbl_8053D804, lbl_8053D7FC);
    fn_801F71A4(this_ + 0x40, *(f32*)(this_ + 0x264), lbl_8053D804, lbl_8053D7FC);
    {
        f32* pos = (f32*)(this_ + 0xc);
        f32* vel = (f32*)(this_ + 0x3c);
        pos[0] += vel[0];
        pos[1] += vel[1];
        pos[2] += vel[2];
    }
    u8 r31 = 0;
    if (*(s32*)(this_ + 0x230) != 3) {
        if ((s32)(u16)fn_8022461C(this_ + 0xc, *(s32*)(this_ + 4)) == 0xe) {
            fn_801F0E34(this_, 0x4001a, 0);
            *(f32*)(this_ + 0x44) = lbl_8053D7F8;
            *(f32*)(this_ + 0x40) = lbl_8053D7F8;
            *(f32*)(this_ + 0x3c) = lbl_8053D7F8;
            *(f32*)(this_ + 0x268) = lbl_8053D7F8;
            *(f32*)(this_ + 0x264) = lbl_8053D7F8;
            *(f32*)(this_ + 0x260) = lbl_8053D7F8;
            *(s32*)(this_ + 0x230) = 3;
        } else {
            fn_801F2B7C(this_, -100, -1, 1);
        }
    }
    r31 = fn_801F2618(this_, 0, 0);
    switch (*(s32*)(this_ + 0x230)) {
    case 0: {
        u8* c = *(u8**)(this_ + 0x26c);
        if (c != 0) {
            *(u32*)(c + 0xf4) |= 1;
            *(s32*)(c + 0x24) = 1;
            *(void**)(this_ + 0x26c) = 0;
        }
        *(s32*)(this_ + 0x244) = (s32)(mozoRand01() * lbl_8053D808);
        *(s32*)(this_ + 0x248) = 0;
        *(s32*)(this_ + 0x238) = (s32)(mozoRand01() * lbl_8053D80C) + 0x14;
        *(s32*)(this_ + 0x23c) = (s32)(mozoRand01() * lbl_8053D810) + 0x64;
        *(s32*)(this_ + 0x230) = 1;
    }
    /* fall through */
    case 1:
        if (!(*(f32*)(this_ + 0x14) <= lbl_8053D7F8)) goto L538;
        *(f32*)(this_ + 0x14) = lbl_8053D7F8;
        *(f32*)(this_ + 0x44) = lbl_8053D7F8;
        if (*(s32*)(this_ + 0x238) == 0) {
            s32 i1 = (s32)(mozoRand01() * lbl_8053D814);
            *(f32*)(this_ + 0x260) = *(f32*)((u8*)sincosTable___5JMath + (((u16)i1 >> 2) & 0x3ff8));
            s32 i2 = (s32)(mozoRand01() * lbl_8053D814);
            *(f32*)(this_ + 0x264) = *(f32*)((u8*)sincosTable___5JMath + (((u16)i2 >> 2) & 0x3ff8) + 4);
            *(f32*)(this_ + 0x44) = lbl_8053D818;
        } else if (*(f32*)(this_ + 0x260) != lbl_8053D7F8 || *(f32*)(this_ + 0x264) != lbl_8053D7F8) {
            fn_801F0E34(this_, 0x40018, 0);
            *(f32*)(this_ + 0x260) = lbl_8053D7F8;
            *(f32*)(this_ + 0x264) = lbl_8053D7F8;
            *(f32*)(this_ + 0x268) = lbl_8053D7F8;
        }
        if (*(s32*)(this_ + 0x23c) == 0) {
            f32 tmp[3];
            tmp[0] = *(f32*)(this_ + 0xc);
            tmp[1] = *(f32*)(this_ + 0x10) - lbl_8053D81C;
            tmp[2] = *(f32*)(this_ + 0x14);
            *(void**)(this_ + 0x26c) = fn_8013CC50(*(s32*)(this_ + 4), tmp, lbl_8053D820, 0x170, 0, 1, 0, 0, 1);
            *(f32*)(this_ + 0x254) = lbl_8053D824;
            fn_801F0E34(this_, 0x40019, 0);
            *(s32*)(this_ + 0x244) = 0;
            *(s32*)(this_ + 0x248) = (s32)(mozoRand01() * lbl_8053D828) + 1;
            *(f32*)(this_ + 0x260) = lbl_8053D7F8;
            *(f32*)(this_ + 0x264) = lbl_8053D7F8;
            *(f32*)(this_ + 0x268) = lbl_8053D7F8;
            *(s32*)(this_ + 0x230) = 2;
            return;
        }
        goto L550;
    L538:
        *(f32*)(this_ + 0x44) -= lbl_8053D7FC;
        *(s32*)(this_ + 0x238) = 0x14;
    L550:
        if (r31 != 0) {
            *(f32*)(this_ + 0x260) *= lbl_8053D82C;
            *(f32*)(this_ + 0x264) *= lbl_8053D82C;
        }
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x234) = lbl_804A0650[*(s32*)(this_ + 0x244)];
            *(s32*)(this_ + 0x250) = lbl_804A0638[*(s32*)(this_ + 0x244)];
            *(s32*)(this_ + 0x244) += 1;
            if (*(s32*)(this_ + 0x244) > 5) *(s32*)(this_ + 0x244) = 0;
        }
        break;
    case 2:
        *(f32*)(this_ + 0x25c) += lbl_8053D830;
        *(f32*)(this_ + 0x258) -= lbl_8053D834;
        if (*(f32*)(this_ + 0x258) < lbl_8053D830) {
            fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053D7FC, 0x2a9, -1, 1, 0, 0, 1);
            fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053D7FC, 0x2aa, -1, 0, 0, 0, 1);
            fn_801F0E34(this_, 0x5005f, 0);
            detach__5ActorFv(this_);
        }
        break;
    case 3:
        if (*(f32*)(this_ + 0x14) <= lbl_8053D7F8) {
            *(f32*)(this_ + 0x44) = lbl_8053D7F8;
        } else {
            *(f32*)(this_ + 0x44) -= lbl_8053D7FC;
        }
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x234) = 4;
            *(s32*)(this_ + 0x250) = lbl_804A0638[*(s32*)(this_ + 0x244)];
            *(s32*)(this_ + 0x244) += 1;
            if (*(s32*)(this_ + 0x244) > 5) *(s32*)(this_ + 0x244) = 0;
        }
        *(s32*)(this_ + 0x248) -= 1;
        if (*(s32*)(this_ + 0x248) <= 0) *(s32*)(this_ + 0x230) = 0;
        break;
    }
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A0668[];

// MOZO init (vtable slot 1)
extern "C" void fn_801675E0(char* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x108) = 4;
    *(s32*)(this_ + 0x250) = 0;
    *(f32*)(this_ + 0x25c) = 0.0f;
    *(f32*)(this_ + 0x258) = 1.0f;
    *(f32*)(this_ + 0x260) = 0.0f;
    *(f32*)(this_ + 0x264) = 0.0f;
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x254) = 255.0f;
    *(void**)(this_ + 0x26c) = 0;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0x230) = 0;
}

struct MozoChild { u8 pad[0x24]; s32 dead; u8 pad2[0xf4 - 0x28]; u32 flags; };

// MOZO: release linked child actor
extern "C" void fn_8016767C(char* this_) {
    MozoChild* c = *(MozoChild**)(this_ + 0x26c);
    if (c != 0) {
        c->flags |= 1;
        c->dead = 1;
        *(MozoChild**)(this_ + 0x26c) = 0;
    }
}

// MOZO destructor
extern "C" void* fn_801676A8(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0668;
        fn_801EE434(*(void**)(this_ + 0x26c));
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
