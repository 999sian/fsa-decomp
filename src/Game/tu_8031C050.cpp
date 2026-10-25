#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" double sin(double x);
extern "C" double cos(double x);
extern const f32 lbl_805419BC;
extern "C" s32 lbl_804AB130[];
extern "C" char lbl_804716F0[];
extern "C" u8* lbl_8053AB10;
extern "C" u8* lbl_8053AAF8;
extern "C" void fn_802F86CC(void* a, void* b, void* c, s32 d, DrawRec* e, f32 f, f32 g);
extern "C" void fn_801F06F0(Actor* p, void* b, s32 c, DrawRec* d, s32 e, f32 f, f32 g);
extern "C" void fn_803075AC(void* a, s32 b, void* c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern "C" s32 fn_8023CB24(void);
extern "C" s32 fn_8023CA88(s32 a);

typedef f32 Mtx[3][4];
extern "C" void PSMTXIdentity(Mtx m);

struct FsaResourceManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* getResource(u32 fourccType, const char* fileName);
};


extern "C" char lbl_804AB170[];
extern const f32 lbl_805419B8;
extern "C" u16 fn_8022461C(void* pos);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8031C050(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AB170;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8031C0B0(Actor* p) {
    DrawRec rec;
    f32 m[3][4];
    u8* self = (u8*)p;
    s32 id;
    f32 ss;
    f32 cz;
    f32 cs, a0, a1, a2, a3, a4, a5, a6, a7, a8;
    f32 cc;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 cx;
    f32 cy;
    f32 angle;
    f32 scale;
    rec.b2d = 1;
    rec.b1d = 0;
    rec.b20 = 0;
    s32 state = *(s32*)(self + 0x230);
    if (state == 8 || state == 9) {
        return;
    }
    if (state == 5 || state == 6 || state == 7) {
        PSMTXIdentity(m);
        angle = *(f32*)(self + 0x23c);
        scale = *(f32*)(self + 0x238);
        sx = sin(lbl_805419B8);
        sy = sin(angle);
        sz = sin(lbl_805419B8);
        cx = cos(lbl_805419B8);
        cy = cos(angle);
        cz = cos(lbl_805419B8);
        rec.w18 = m;
        cc = cx * cz;
        ss = sx * sy;
        cs = cx * sz;
        a0 = cy * cz;
        a1 = cy * sz;
        a2 = -sy;
        a3 = ss * cz - cs;
        a4 = ss * sz + cc;
        a5 = sx * cy;
        a6 = cc * sy + sx * sz;
        a7 = cs * sy - sx * cz;
        a8 = cx * cy;
        m[0][0] = scale * a0;
        m[1][0] = scale * a1;
        m[2][0] = scale * a2;
        m[0][1] = scale * a3;
        m[1][1] = scale * a4;
        m[2][1] = scale * a5;
        m[0][2] = scale * a6;
        m[1][2] = scale * a7;
        m[2][2] = scale * a8;
        id = *(s32*)(self + 0x254) + lbl_804AB130[*(s32*)(self + 0x268)];
        if (*(s32*)(self + 4) < 8) {
            void* res = ((FsaResourceManager*)*(void**)(lbl_8053AAF8 + 0xa4))->getResource(0x534F4220, lbl_804716F0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), self + 0xc, res, id, &rec, lbl_805419BC, lbl_805419BC);
        }
        return;
    }
    if (state != 2) {
        rec.b1d = 0;
        rec.w30 = 0x11;
        if (*(f32*)(self + 0x14) > lbl_805419B8) {
            rec.b1c = 1;
        }
        JGeometry::TVec3<f32> old(*(JGeometry::TVec3<f32>*)(self + 0xc));
        *(JGeometry::TVec3<f32>*)(self + 0xc) += *(JGeometry::TVec3<f32>*)(self + 0x294);
        fn_801F06F0(p, lbl_804716F0, *(s32*)(self + 0x254) + lbl_804AB130[*(s32*)(self + 0x268)], &rec, 7, lbl_805419BC, lbl_805419BC);
        fn_803075AC(*(void**)(self + 0x198), *(s32*)(self + 4), self + 0xc,
            *(s32*)(self + 0x254) + lbl_804AB130[*(s32*)(self + 0x268)], 0, 2, -1, 0, 0, 0);
        *(JGeometry::TVec3<f32>*)(self + 0xc) = old;
    } else {
        if (*(s32*)(self + 0x264) >= 0 && *(s32*)(self + 0x264) <= 3) {
            rec.b1d = fn_8023CB24() + 1;
            rec.b1c = fn_8023CA88(*(s32*)(self + 0x264));
        }
        rec.b2d = 1;
        id = *(s32*)(self + 0x254) + lbl_804AB130[*(s32*)(self + 0x268)];
        if (*(s32*)(self + 4) < 8) {
            void* res = ((FsaResourceManager*)*(void**)(lbl_8053AAF8 + 0xa4))->getResource(0x534F4220, lbl_804716F0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), self + 0xc, res, id, &rec, lbl_805419BC, lbl_805419BC);
        }
        fn_803075AC(*(void**)(self + 0x198), *(s32*)(self + 4), self + 0xc,
            *(s32*)(self + 0x254) + lbl_804AB130[*(s32*)(self + 0x268)], 0, 2, -1, 0, 0, 0);
    }
}

extern "C" s32 fn_8031DAB0(Actor* p, s32 unused, void* pos) {
    u8* self = (u8*)p;
    s32 kind = (u16)fn_8022461C(pos);

    if (kind == 3) {
        *(f32*)(self + 0x44) = lbl_805419B8;
        *(f32*)(self + 0x40) = lbl_805419B8;
        *(f32*)(self + 0x3c) = lbl_805419B8;
        *(s32*)(self + 0x230) = 5;
        return 0;
    }
    if (kind == 0xe) {
        if (*(s32*)(self + 0x230) != 7) {
            *(s32*)(self + 0x248) = 10;
            *(s32*)(self + 0x230) = 7;
        }
        return 0;
    }
    if (kind == 0xd) {
        if (*(s32*)(self + 0x230) != 6) {
            *(s32*)(self + 0x248) = 10;
            *(s32*)(self + 0x230) = 6;
        }
        return 0;
    }
    if (kind == 0 || kind == 0x27 || kind == 2 ||
        (kind == 0x28 && (s32)*(f32*)(self + 0x10) % 16 > 8) ||
        (kind == 0x29 && (s32)*(f32*)(self + 0x10) % 16 < 8) ||
        (kind == 0x2c && (s32)*(f32*)(self + 0x10) % 16 > 8) ||
        (kind == 0x2d && (s32)*(f32*)(self + 0x10) % 16 < 8) ||
        (kind == 0x2a && (s32)*(f32*)(self + 0xc) % 16 > 8) ||
        (kind == 0x2b && (s32)*(f32*)(self + 0xc) % 16 < 8) ||
        (kind == 0x2e && (s32)*(f32*)(self + 0xc) % 16 > 8) ||
        (kind == 0x2f && (s32)*(f32*)(self + 0xc) % 16 < 8)) {
        return 0;
    }
    return 1;
}

extern "C" u8* lbl_8053AAF8;
extern const f32 lbl_805419B8;
extern const f32 lbl_805419BC;
extern const f32 lbl_80541A10;
extern const f32 lbl_80541A14;
extern const f32 lbl_80541A18;
extern const f32 lbl_80541A1C;
extern "C" void detach__5ActorFv(Actor* p);
extern "C" void fn_8031DD28(Actor* p) {
    u8* self = (u8*)p;
    u32 bits;
    u16 mode;

    *(u32*)(self + 0x268) = *(u32*)(self + 0x90) & 3;
    *(s16*)(self + 0x94) = (*(u32*)(self + 0x90) >> 16) & 0xff;
    *(u32*)(self + 0x254) = 0;
    *(u32*)(self + 0x258) = 0;
    *(u32*)(self + 0x25c) = 0;
    *(u32*)(self + 0x260) = 0;
    *(u32*)(self + 0x240) = 0;
    *(u32*)(self + 0x244) = 0;
    *(u32*)(self + 0x248) = 0;
    *(u32*)(self + 0x24c) = 0;
    *(u32*)(self + 0x250) = 0;
    *(u16*)(self + 0x274) = 0;
    *(u16*)(self + 0x276) = *(u16*)(self + 0x274);
    *(u32*)(self + 0x108) = 10000;
    *(s32*)(self + 0x264) = -1;
    *(u32*)(self + 0x98) = 0;
    *(f32*)(self + 0x288) = *(f32*)(self + 0xc);
    *(f32*)(self + 0x28c) = *(f32*)(self + 0x10);
    *(f32*)(self + 0x290) = *(f32*)(self + 0x14);
    *(s32*)(self + 0x260) = 100;
    *(f32*)(self + 0x238) = lbl_805419BC;
    *(f32*)(self + 0x23c) = lbl_805419B8;
    *(u8*)(self + 0x278) = 0;
    *(u32*)(self + 0x270) = *(u32*)(self + 0x4);
    *(f32*)(self + 0x234) = lbl_80541A10;

    {
        u8* rng = lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
    }
    *(s32*)(self + 0x25c) = (s32)(lbl_80541A14 * (*(f32*)&bits - lbl_805419BC));

    *(u32*)(self + 0xb0) = 0x2000a;
    *(f32*)(self + 0x29c) = lbl_805419B8;
    *(f32*)(self + 0x298) = lbl_805419B8;
    *(f32*)(self + 0x294) = lbl_805419B8;
    *(u32*)(self + 0x26c) = 0;

    mode = *(u16*)(self + 0x94);
    switch (mode) {
    case 0:
        *(u32*)(self + 0x268) = *(u32*)(self + 0x90) & 3;
        *(u32*)(self + 0x230) = 0;
        *(u8*)(self + 0x278) = 1;
        break;
    case 1:
        *(u32*)(self + 0x268) = *(u32*)(self + 0x90) & 3;
        *(u32*)(self + 0x230) = 4;
        break;
    case 2:
        *(u32*)(self + 0x230) = 8;
        break;
    }

    *(f32*)(self + 0x27c) = lbl_805419B8;
    *(f32*)(self + 0x280) = lbl_805419B8;
    *(f32*)(self + 0x284) = lbl_805419B8;
    *(f32*)(self + 0x3c) = lbl_805419B8;
    *(f32*)(self + 0x40) = lbl_805419B8;
    *(f32*)(self + 0x44) = lbl_805419B8;
    *(u32*)(self + 0xb8) = 1;
    *(f32*)(self + 0x80) = lbl_80541A18;
    *(f32*)(self + 0x84) = lbl_80541A18;
    *(f32*)(self + 0x88) = lbl_80541A1C;
    *(f32*)(self + 0x8c) = lbl_80541A1C;
    *(f32*)(self + 0x60) = lbl_80541A18;
    *(f32*)(self + 0x64) = lbl_80541A18;
    *(f32*)(self + 0x68) = lbl_80541A1C;
    *(f32*)(self + 0x6c) = lbl_80541A1C;

    if (*(lbl_8053AAF8 + 0x7f) == 0) {
        detach__5ActorFv(p);
    } else {
        *(u8*)(self + 0x194) = 1;
    }
}

