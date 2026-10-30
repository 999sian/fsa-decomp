// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80192038-80197070 (GNON). Remaining functions are not yet decompiled.
#include "types.h"
#include "std/math.h"
extern u8 lbl_804C1BD0[];
#include "JSystem/JMath/JMath.h"
static inline f32 gnonRandom(JMARandFast* random) { return random->get_ufloat_1(); }
extern u32 lbl_804C1BC0[];
extern "C" u8 fn_8023F264(s32);
extern "C" void* fn_8023E724(s32);

// from src/Game/GlobalMgr_GetByte_0x24f.cpp
// fn_80196DF0 - reads a byte at lbl_80529DEC->0x24f.
// fn_80196E00 - sets bit 0x10 in a byte at
// (*lbl_8053AED0)->0xdc. Retest of the batch-2
// "small-data-array" bug using the real 0x354-byte size from
// symbols.txt (the earlier attempt used an inexact 0x300 placeholder).
extern "C" {

extern u8 lbl_80529DEC[0x354];
extern void* lbl_8053AED0;

u8 fn_80196DF0(void) {
	return lbl_80529DEC[0x24f];
}

void fn_80196E00(void) {
	u8* p = (u8*)lbl_8053AED0;
	p[0xdc] |= 0x10;
}

void fn_80196E14(void) {
}

}


// Small (inline-style) accessors.
extern void* lbl_8053AAF8;
extern "C" void fn_80134DE4(void* game, void* a, void* b);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D79E8(void* mgr, void* a, void* b, f32 x, f32 y);

struct GnonVec { f32 x, y, z; };
struct GnonShared {
    u32 rooms[4];
    GnonVec positions[4];
    GnonVec playerPositions[4];
};
extern "C" void fn_80196CF4(char* this_, const GnonVec* v) {
    *(GnonVec*)(this_ + 0x98) = *v;
    *(f32*)(this_ + 0xb0) = v->x;
    *(f32*)(this_ + 0xb4) = v->y;
}
extern "C" void fn_80196D18(char* this_, f32 x, f32 y) { *(f32*)(this_ + 0xb0) = x; *(f32*)(this_ + 0xb4) = y; }
extern "C" void fn_80196D24(f32* v, f32 x, f32 y) { v[0] = x; v[1] = y; }
extern "C" void fn_80196D30(void* a, void* b) { fn_80134DE4(lbl_8053AAF8, a, b); }
extern "C" void fn_80196D60(f32* v, f32 x, f32 y, f32 z) { v[0] = x; v[1] = y; v[2] = z; }
extern "C" void fn_80196D70(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }
extern "C" void fn_80196D8C(void* a, void* b, f32 x, f32 y) { fn_802D79E8(fn_802D6A9C(), a, b, x, y); }

struct ActorVt_gnon {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setShadow(s32 type, f32 x, f32 y);
};
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
#include "JSystem/JGeometry/Vec.h"
struct GnonVirtuals : ActorVt_gnon {
virtual u8 v9(f32,f32,f32);
virtual void v10();virtual void v11();virtual void v12();virtual void v13();virtual void v14();virtual void v15();virtual void v16();virtual void v17();virtual void v18();
virtual void v19();virtual void v20(s32);
};
extern "C" void fn_8018E890(void*);
extern "C" void fn_801546BC(void*);
extern "C" void fn_80154718(void*);
extern "C" void fn_8017ECC0();
extern "C" void fn_801F3D94(void*,s32);
extern "C" u8 fn_801F2FAC(void*);
extern "C" s32 fn_801F285C(void*,s32,s32,s32,s32);
extern "C" void fn_801F3128(void*,void*);
extern "C" void fn_80238548(s32,s32,void*,s32);
extern "C" s32 fn_801F2718(void*,u32);
extern "C" void* fn_8015445C(s32);
extern "C" u16 fn_8018A590();
extern "C" u32 fn_801544C8(void*);
extern "C" void fn_801F37AC(void*,s32,void*,s32,s32,s32);
extern "C" void fn_801544D0(void*,s32);
extern "C" void fn_8018A5A8(void*,s32);
extern "C" void fn_801F71A4(void*,f32,f32,f32);
extern "C" void fn_801545F0(void*,void*);
extern "C" void fn_801F2B20(void*,s32);
extern "C" void fn_80154590(void*,f32,f32,f32,f32);
extern "C" s32 fn_80154510(void*);
extern "C" s32 fn_801545C0(void*,s32,s32);
extern "C" f32 fn_80154744();
extern "C" f32 fn_801544FC(s32);
extern "C" f32 fn_801544E4(s32);
extern const f32 lbl_8053E2E0,lbl_8053E2E4,lbl_8053E2E8;
extern u8 lbl_8053AB90,lbl_8053AB91;
extern const f32 lbl_8053E29C,lbl_8053E2A0,lbl_8053E2A4,lbl_8053E2A8,lbl_8053E2AC,lbl_8053E2B0,lbl_8053E2B4,lbl_8053E2B8,lbl_8053E2BC,lbl_8053E2C0,lbl_8053E2C4,lbl_8053E2C8,lbl_8053E2CC,lbl_8053E2D0,lbl_8053E2D4;

extern "C" void fn_80192038(ActorVt_gnon* this_) {
    fn_801F0E34(this_, 0x40006, 0);
    this_->setShadow(2, 0.0f, 0.0f);
}

#include "JSystem/JUtility/JUTTexture.h"
#include "Game/ItemBase.h"
extern "C" void fn_801EFD34(void* this_, const ResTIMG* tex, DrawRec* rec, s32 mode, f32 x, f32 y, f32 z);
extern "C" const ResTIMG* fn_804032E8(u32 type, const char* name);
extern u8 lbl_804A1FF8[];
extern const char lbl_80467F8C[];
extern const f32 lbl_8053E278;
extern f32 lbl_8053E27C;
extern f32 lbl_8053E280;
extern f32 lbl_8053E284;
static inline void gnonSetRotScale(f32 (*m)[4], f32 angle, f32 scaleX, f32 scaleY) {
    f32 sx, sy, sz, cx, cy, cz;
    f32 ss, cc, cs;
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    sx = sin(0.0f);
    sy = sin(angle);
    sz = sin(0.0f);
    cx = cos(0.0f);
    cy = cos(angle);
    cz = cos(0.0f);
    ss = sx * sy;
    cc = cx * cz;
    cs = cx * sz;
    m[0][0] = scaleX * (cy * cz);
    m[1][0] = scaleX * (cy * sz);
    m[2][0] = scaleX * -sy;
    m[0][1] = scaleY * (ss * cz - cs);
    m[1][1] = scaleY * (ss * sz + cc);
    m[2][1] = scaleY * (sx * cy);
    m[0][2] = scaleY * (cc * sy + sx * sz);
    m[1][2] = scaleY * (cs * sy - sx * cz);
    m[2][2] = scaleY * (cx * cy);
}
struct GnonDrawTables {
    u8 pad0[0x3a0];
    const char* names1[59];
    const char* names2[59];
    f32 offsets[16][2];
};
static inline void gnonSetRotation(f32 (*m)[4], f32 rx, f32 ry, f32 rz, f32 scaleX, f32 scaleY) {
    f32 ss;
    f32 cz;
    f32 cs;
    f32 cc;
    f32 sx, sy, sz, cy, cx;
    sx = sin(rx);
    sy = sin(ry);
    sz = sin(rz);
    cx = cos(rx);
    cy = cos(ry);
    cz = cos(rz);
    ss = sx * sy;
    cs = cx * sz;
    cc = cx * cz;
    m[0][0] = scaleX * (cy * cz);
    m[1][0] = scaleX * (cy * sz);
    m[2][0] = scaleX * -sy;
    m[0][1] = scaleY * (ss * cz - cs);
    m[1][1] = scaleY * (ss * sz + cc);
    m[2][1] = scaleY * (sx * cy);
    m[0][2] = scaleY * (cc * sy + sx * sz);
    m[1][2] = scaleY * (cs * sy - sx * cz);
    m[2][2] = scaleY * (cx * cy);
}
static inline void gnonSetScale(f32 (*m)[4], f32 x, f32 y, f32 z) {
    m[0][0] = x;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = y;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = z;
}
extern "C" void fn_80192090(char* this_) {
    f32 z;
    f32 y;
    f32 x;
    GnonDrawTables* tables = (GnonDrawTables*)lbl_804A1FF8;
    DrawRec rec;
    f32 m[3][4];
    m[0][3] = lbl_8053E278;
    m[1][3] = lbl_8053E278;
    m[2][3] = lbl_8053E278;
    u32 type = *(u32*)(this_ + 0x90);
    if (type == 0x1f) {
        return;
    }
    x = *(f32*)(this_ + 0xc);
    y = *(f32*)(this_ + 0x10);
    z = *(f32*)(this_ + 0x14);
    if (type != 0) {
        if (type == 0x1e) {
            rec.b1f = 0;
            rec.b1d = 5;
            m[0][3] = lbl_8053E278;
            m[1][3] = lbl_8053E278;
            m[2][3] = lbl_8053E278;
            gnonSetRotation(m, lbl_8053E278, *(u16*)(this_ + 0x2b4) / -10430.2275390625f, lbl_8053E278, 1.4f, 1.4f);
            const ResTIMG* tex = fn_804032E8('GANO', lbl_80467F8C);
            rec.w18 = m;
            ((u8*)&rec.w10)[3] = (s32)*(f32*)(this_ + 0x2b0);
            rec.w30 = -1;
            fn_801EFD34(this_, tex, &rec, -1, 0.0f, 0.0f, 0.0f);
        }
        return;
    }
    rec.b1f = 0;
    if (*(s32*)(this_ + 0x230) == 4 || *(s32*)(this_ + 0x230) == 6) {
        *(f32*)(this_ + 0x14) = 0.0f;
        ((u8*)&rec.w10)[0] = 0;
        ((u8*)&rec.w10)[1] = 0;
        ((u8*)&rec.w10)[2] = 0;
        ((u8*)&rec.w10)[3] = 100;
        rec.b1d = -2;
        const char** names = tables->names1;
        const ResTIMG* tex = fn_804032E8('GANO', names[*(s32*)(this_ + 0x284)]);
        fn_801EFD34(this_, tex, &rec, -1, 0.0f, 0.0f, 0.0f);
        JUTTexture shadow(tex, 0);
        f32 offX = 0.5f * -(f32)shadow.getWidth();
        f32 offY = 0.5f * -(f32)shadow.getHeight();
        if (*(s32*)(this_ + 0x28c) == 5) {
            m[0][3] = 0.0f;
            m[1][3] = 0.0f;
            m[2][3] = 0.0f;
            gnonSetRotation(m, lbl_8053E278, *(u16*)(this_ + 0x2b4) / -10430.2275390625f, lbl_8053E278, 1.4f, 1.4f);
            tex = fn_804032E8('GANO', lbl_80467F8C);
        } else {
            gnonSetScale(m, *(f32*)(this_ + 0x2d0), *(f32*)(this_ + 0x2d4), *(f32*)(this_ + 0x2d4));
            const char** names2 = tables->names2;
            tex = fn_804032E8('GANO', names2[*(s32*)(this_ + 0x288)]);
        }
        rec.w18 = m;
        ((u8*)&rec.w10)[0] = 0;
        ((u8*)&rec.w10)[1] = 0;
        ((u8*)&rec.w10)[2] = 0;
        ((u8*)&rec.w10)[3] = 100;
        rec.b1d = -1;
        JUTTexture body(tex, 0);
        f32 (*offs)[2] = tables->offsets;
        offX += 0.5f * (f32)body.getWidth() + offs[*(s32*)(this_ + 0x28c)][0];
        offY += 0.5f * (f32)body.getHeight() + offs[*(s32*)(this_ + 0x28c)][1];
        *(f32*)(this_ + 0x2c4) = *(f32*)(this_ + 0xc);
        *(f32*)(this_ + 0x2c8) = *(f32*)(this_ + 0x10);
        *(f32*)(this_ + 0x2cc) = *(f32*)(this_ + 0x14);
        *(f32*)(this_ + 0x2c4) += offX;
        *(f32*)(this_ + 0x2c8) += offY;
        if ((u8)this_[0x2a5] == 0 && (*(s32*)(this_ + 0x28c) != 7 ||
                                      (*(s32*)(this_ + 0x28c) == 7 && *(s32*)(this_ + 0x25c) < 6))) {
            fn_801EFD34(this_, tex, &rec, -1, offX, 0.0f, -offY);
        }
    }
    *(f32*)(this_ + 0xc) = x;
    *(f32*)(this_ + 0x10) = y;
    *(f32*)(this_ + 0x14) = z;
    rec.b1d = 3;
    rec.b1f = 0;
    gnonSetScale(m, *(f32*)(this_ + 0x54), *(f32*)(this_ + 0x58), *(f32*)(this_ + 0x58));
    rec.w18 = m;
    ((u8*)&rec.w10)[0] = 0xff;
    ((u8*)&rec.w10)[1] = 0xff;
    ((u8*)&rec.w10)[2] = 0xff;
    ((u8*)&rec.w10)[3] = 0xff;
    ((u8*)&rec.w10)[3] = (s32)*(f32*)(this_ + 0x2ac);
    if ((*(s32*)(this_ + 0x2a0) == 3 && *(s32*)(this_ + 0x230) != 10) ||
        *(s32*)(this_ + 0x230) == 0x10 || *(s32*)(this_ + 0x230) == 0x11 || *(s32*)(this_ + 0x230) == 0x12) {
        rec.w30 = 0x10;
    } else {
        rec.w30 = 0x11;
    }
    const char** names = tables->names1;
    const ResTIMG* tex = fn_804032E8('GANO', names[*(s32*)(this_ + 0x284)]);
    fn_801EFD34(this_, tex, &rec, -1, 0.0f, 0.0f, 0.0f);
    JUTTexture head(tex, 0);
    f32 offX = 0.5f * -(f32)head.getWidth();
    f32 offY = 0.5f * -(f32)head.getHeight();
    if (*(s32*)(this_ + 0x28c) == 5) {
        m[0][3] = 0.0f;
        m[1][3] = 0.0f;
        m[2][3] = 0.0f;
        gnonSetRotation(m, lbl_8053E278, *(u16*)(this_ + 0x2b4) / -10430.2275390625f, lbl_8053E278,
                        1.4f * *(f32*)(this_ + 0x2d0), 1.4f * *(f32*)(this_ + 0x2d4));
        tex = fn_804032E8('GANO', lbl_80467F8C);
    } else {
        gnonSetScale(m, *(f32*)(this_ + 0x2d0), *(f32*)(this_ + 0x2d4), *(f32*)(this_ + 0x2d4));
        const char** names2 = tables->names2;
        tex = fn_804032E8('GANO', names2[*(s32*)(this_ + 0x288)]);
    }
    rec.w18 = m;
    rec.w30 = -1;
    rec.b1d = 5;
    ((u8*)&rec.w10)[3] = (s32)*(f32*)(this_ + 0x2b0);
    JUTTexture body(tex, 0);
    f32 (*offs)[2] = tables->offsets;
    offX += 0.5f * (f32)body.getWidth() + offs[*(s32*)(this_ + 0x28c)][0];
    offY += 0.5f * (f32)body.getHeight() + offs[*(s32*)(this_ + 0x28c)][1];
    *(f32*)(this_ + 0x2c4) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2c8) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2cc) = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x2c4) += offX;
    *(f32*)(this_ + 0x2c8) += offY;
    if ((u8)this_[0x2a5] == 0 && (*(s32*)(this_ + 0x28c) != 7 ||
                                  (*(s32*)(this_ + 0x28c) == 7 && *(s32*)(this_ + 0x25c) < 6))) {
        fn_801EFD34(this_, tex, &rec, -1, offX, 0.0f, -offY);
    }
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);

struct Handles_gnon { u8 pad[0x328]; void* h[5]; };
// GNON destructor
extern void* lbl_804A25F0[];
extern "C" void* fn_80196834(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A25F0;
        for (int i = 0; i < 5; i++) {
            fn_801EE434(((Handles_gnon*)this_)->h[i]);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern u8 lbl_8053AB91;
extern u8 lbl_8053AB90;
extern u32 lbl_80539FE8;
extern "C" void fn_801968C8(char* p) {
    GnonShared* shared = (GnonShared*)lbl_804C1BC0;
    u8* tables = (u8*)shared;
    for (int i = 0; i < 10; i++) *(s32*)(p + 0x25c + i * 4) = 0;
    for (int j = 0; j < 10; j++) *(s32*)(p + 0x234 + j * 4) = 0;
    *(s32*)(p + 0x318) = -1;
    *(s32*)(p + 0x31c) = -1;
    *(s32*)(p + 0x320) = -1;
    *(s32*)(p + 0x324) = -1;
    *(u16*)(p + 0x94) = 0;
    p[0x196] = 1;
    *(s32*)(p + 0x308) = -1;
    *(s32*)(p + 0x30c) = -1;
    *(s32*)(p + 0x310) = -1;
    *(s32*)(p + 0x314) = -1;
    *(s32*)(p + 0x284) = 0;
    *(s32*)(p + 0x288) = 0;
    *(u16*)(p + 0x2b4) = 0;
    *(s32*)(p + 0x29c) = 0;
    *(s32*)(p + 0x28c) = 0;
    *(s32*)(p + 0x290) = 0;
    *(f32*)(p + 0x2c0) = 0.0f;
    *(f32*)(p + 0x2bc) = 0.0f;
    *(f32*)(p + 0x2b8) = 0.0f;
    *(f32*)(p + 0x44) = 0.0f;
    *(f32*)(p + 0x40) = 0.0f;
    *(f32*)(p + 0x3c) = 0.0f;
    *(s32*)(p + 0x298) = 480;
    *(s32*)(p + 0x2a0) = 0;
    *(f32*)(p + 0x2a8) = 0.0f;
    *(s32*)(p + 0x294) = -1;
    *(s32*)(p + 0x2f8) = -1;
    *(f32*)(p + 0x2ac) = 255.0f;
    *(f32*)(p + 0x2b0) = 255.0f;
    p[0x2a5] = 0;
    *(s16*)(p + 0x2b6) = (s32)(65536.0f * ((JMath::TRandom_fast_*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1());
    *(GnonVec*)(p + 0x2dc) = *(GnonVec*)(p + 0xc);
    *(GnonVec*)(p + 0x2e8) = *(GnonVec*)(p + 0xc);
    *(f32*)(p + 0x54) = 1.0f;
    *(f32*)(p + 0x58) = 1.0f;
    *(f32*)(p + 0x5c) = 1.0f;
    *(f32*)(p + 0x2d0) = 1.0f;
    *(f32*)(p + 0x2d4) = 1.0f;
    *(f32*)(p + 0x2d8) = 1.0f;
    *(f32*)(p + 0x2f4) = 0.0f;
    *(s32*)(p + 0x300) = 0;
    *(s32*)(p + 0x2fc) = -1;
    *(u16*)(p + 0x304) = 0;
    *(s32*)(p + 0x328) = 0;
    *(s32*)(p + 0x32c) = 0;
    *(s32*)(p + 0x330) = 0;
    *(s32*)(p + 0x334) = 0;
    *(s32*)(p + 0x338) = 0;
    p[0x2a4] = 0;
    p[0x2a6] = 1;
    *(s32*)(p + 0x118) = 2;
    if (*(u32*)(p + 0x90) == 0) {
        *(u32*)(p + 0xb0) = 0xa040004;
        lbl_8053AB91 = 0;
        lbl_80539FE8 = *(u32*)(p + 4);
        GnonVec* dst = (GnonVec*)(tables + 0x40);
        for (s32 i = 0; i < 4; ++i, ++dst) {
            if (fn_8023F264(i)) *dst = *(GnonVec*)fn_8023E724(i);
        }
        lbl_8053AB90 = 0;
        *(f32*)(p + 0x60) = -48.0f;
        *(f32*)(p + 0x64) = -48.0f;
        *(f32*)(p + 0x68) = 48.0f;
        *(f32*)(p + 0x6c) = 48.0f;
        *(f32*)(p + 0x80) = -48.0f;
        *(f32*)(p + 0x84) = -48.0f;
        *(f32*)(p + 0x88) = 48.0f;
        *(f32*)(p + 0x8c) = 50.0f;
        *(s32*)(p + 0x230) = 0;
    }
    if (*(u32*)(p + 0x90) == 10 || (u32)(*(u32*)(p + 0x90) - 11) <= 1 || *(u32*)(p + 0x90) == 13) {
        *(f32*)(p + 0x60) = -12.0f;
        *(f32*)(p + 0x64) = -12.0f;
        *(f32*)(p + 0x68) = 12.0f;
        *(f32*)(p + 0x6c) = 12.0f;
        *(f32*)(p + 0x80) = -12.0f;
        *(f32*)(p + 0x84) = -12.0f;
        *(f32*)(p + 0x88) = 12.0f;
        *(f32*)(p + 0x8c) = 12.0f;
        *(s32*)(p + 0x230) = 31;
    }
    if (*(u32*)(p + 0x90) == 20 || (u32)(*(u32*)(p + 0x90) - 21) <= 1 || *(u32*)(p + 0x90) == 23) {
        *(f32*)(p + 0x60) = -8.0f;
        *(f32*)(p + 0x64) = -8.0f;
        *(f32*)(p + 0x68) = 8.0f;
        *(f32*)(p + 0x6c) = 8.0f;
        *(f32*)(p + 0x80) = -8.0f;
        *(f32*)(p + 0x84) = -8.0f;
        *(f32*)(p + 0x88) = 8.0f;
        *(f32*)(p + 0x8c) = 8.0f;
        *(s32*)(p + 0x114) = 2;
        *(s32*)(p + 0x230) = 35;
    }
    if (*(u32*)(p + 0x90) == 1 || (u32)(*(u32*)(p + 0x90) - 2) <= 1 || *(u32*)(p + 0x90) == 4) {
        *(s32*)(p + 0x25c) = *(u32*)(p + 0x90) - 1;
        u32* rooms = shared->rooms;
        GnonVec* positions = shared->positions;
        rooms[*(s32*)(p + 0x25c)] = *(u32*)(p + 4);
        fn_80196D70((f32*)&positions[*(s32*)(p + 0x25c)], (f32*)(p + 0xc));
        positions[*(s32*)(p + 0x25c)].y += 48.0f;
        *(s32*)(p + 0x230) = 40;
    }
    if (*(u32*)(p + 0x90) == 31) {
        *(u32*)(p + 0xb0) = 0x5000000;
        *(s32*)(p + 0x230) = 44;
    }
    if (*(u32*)(p + 0x90) == 30) {
        *(u32*)(p + 0xb0) = 0xa040004;
        *(s32*)(p + 0x114) = 4;
        *(f32*)(p + 0x60) = -64.0f;
        *(f32*)(p + 0x64) = -64.0f;
        *(f32*)(p + 0x68) = 64.0f;
        *(f32*)(p + 0x6c) = 64.0f;
        *(s32*)(p + 0x230) = 42;
    }
}

extern "C" s32 fn_8013CC50(u32 id, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);
extern "C" void fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" void* fn_8023E724(s32 i);
extern "C" s32 fn_8022F3DC(s32 i);
extern "C" void fn_8022CA6C(s32 a, s32 b, s32 c);
extern "C" u8 fn_802317F0(s32 a, u32 b, void* c, void* d, s32 e);
extern "C" u8 fn_8023F264(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" u8 fn_80230188(s32 i);
extern "C" u8 fn_8022DCD8(s32 i);
extern "C" s32 fn_80237774(s32 i);
extern "C" s32 fn_80236228(s32 i);
extern f32 lbl_8053E284;
extern f32 lbl_8053E360;
extern f32 lbl_8053E298;
extern u32 lbl_804C1BC0[];
extern u8 lbl_804C1BD0[];

static inline void gnonReleaseHandle(u8** handle) {
    u8* h = *handle;
    if (h != 0) {
        *(u32*)(h + 0xf4) |= 1;
        *(s32*)(h + 0x24) = 1;
        *handle = 0;
    }
}
struct GnonTimers { u8 pad[0x234]; s32 t[10]; };

extern "C" void fn_80192BD8(char* this_) {
    switch (*(s32*)(this_ + 0x230)) {
    case 0x2c:
        *(s32*)(this_ + 0x234) = 0x32;
        fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x359, 0, 0, 0, 0, 1, 1.0f);
        fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x35a, 0, 0, 0, 0, 1, 1.0f);
        fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x35b, 0, 0, 0, 0, 1, 1.0f);
        *(s32*)(this_ + 0x230) = 0x2d;
    case 0x2d:
        if (*(s32*)(this_ + 0x234) == 0) {
            this_[0x11c] = 0;
        }
        break;
    }
    fn_801F2B7C(this_, -100, -1, 1);
    for (int i = 0; i < 10; i++) {
        if (((GnonTimers*)this_)->t[i] > 0) {
            ((GnonTimers*)this_)->t[i]--;
        }
    }
}

#pragma dont_inline on
extern "C" void fn_80192D98(void* this_){u8* self=(u8*)this_;
JGeometry::TVec3f saved,pos;
u8 box[16];fn_8018E890(box);u8 hit=0;fn_801546BC(&pos);
*(s32*)(self+0x108)=10000;
if(*(u32*)(self+0x90)==31){fn_80192BD8((char*)self);return;}
if(*(u32*)(self+0x90)==0)fn_8017ECC0();
fn_80154718(self+0xc);
if(*(u32*)(self+0x90)==0){
((GnonVirtuals*)self)->v19();
if(((GnonVirtuals*)self)->v9(lbl_8053E278,lbl_8053E29C,lbl_8053E2A0))return;
fn_801F3D94(self,0);
if(*(s32*)(self+0x2a0)!=3){
if(self[0x2a6]==0&&*(f32*)(self+0x2ac)>lbl_8053E2A4&&fn_801F2FAC(self)){
if(*(s32*)(self+0x298)>0)*(s32*)(self+0x298)-=10000-*(s32*)(self+0x108);
if(*(s32*)(self+0x298)<=0){if(*(s32*)(self+0x230)!=9){
if(*(s32*)(self+0x2a0)==0){*(s32*)(self+0x298)=480;fn_801F0E34(self,0x50000,0);*(s32*)(self+0x2a0)=1;lbl_8053AB91=1;}
else{if(*(s32*)(self+0x2a0)==1)fn_80196D30((void*)2,0);*(s32*)(self+0x230)=9;}
}}else{fn_801F0E34(self,0x50000,0);fn_801546BC(self+0x3c);}
}}
else if(self[0x2a6]==0){
for(s32 i=0;i<4;i++){s32 player=fn_801F285C(self,0,0,1,i);if(player>=0){JGeometry::TVec2f point;fn_801F3128(self,&point);fn_80238548(player,0,&point,3);}}
fn_80196D70(&saved.x,(f32*)(self+0xc));*(f32*)(self+0x10)-=*(f32*)(self+0x14);*(f32*)(self+0x14)=lbl_8053E278;s32 id=fn_801F2718(self,'GNON');fn_80196D70((f32*)(self+0xc),&saved.x);
if(id>=0){void* other=fn_8015445C(id);if(other&&fn_8018A590()==1&&(fn_801544C8(other)==20||fn_801544C8(other)==21||fn_801544C8(other)==22||fn_801544C8(other)==23)){
*(s32*)(self+0x298)=(f32)*(s32*)(self+0x298)-lbl_8053E2A8;
fn_801F37AC(self,0,self+0xc,3,0,-1);fn_801544D0(self,0);lbl_8053AB90=1;fn_801F0E34(self,0x50005,0);fn_8013CC50(*(u32*)(self+4),self+0xc,0x1ce,0,3,0,0,1,lbl_8053E298);fn_8018A5A8(other,0);self[0x2a6]=1;
if(*(s32*)(self+0x298)<=0)*(s32*)(self+0x230)=9;else{*(s32*)(self+0x28c)=15;((GnonVirtuals*)self)->v19();}
fn_801546BC(self+0x3c);
}}}}
if(*(s32*)(self+0x234)>0)--*(s32*)(self+0x234);
if(*(s32*)(self+0x238)>0)--*(s32*)(self+0x238);
if(*(s32*)(self+0x23c)>0)--*(s32*)(self+0x23c);
if(*(s32*)(self+0x240)>0)--*(s32*)(self+0x240);
if(*(s32*)(self+0x244)>0)--*(s32*)(self+0x244);
if(*(s32*)(self+0x248)>0)--*(s32*)(self+0x248);
if(*(s32*)(self+0x24c)>0)--*(s32*)(self+0x24c);
if(*(s32*)(self+0x250)>0)--*(s32*)(self+0x250);
if(*(s32*)(self+0x254)>0)--*(s32*)(self+0x254);
if(*(s32*)(self+0x258)>0)--*(s32*)(self+0x258);
if(*(s32*)(self+0x28c)==15){if(self[0x2a4]==0)return;*(s32*)(self+0x230)=3;}
if(*(u32*)(self+0x90)!=30){fn_801F71A4(self+0x3c,*(f32*)(self+0x2b8),lbl_8053E2AC,lbl_8053E298);fn_801F71A4(self+0x40,*(f32*)(self+0x2bc),lbl_8053E2AC,lbl_8053E298);}
fn_801545F0(self+0xc,self+0x3c);
if(*(u32*)(self+0x90)==0||(u32)(*(u32*)(self+0x90)-20)<=2||*(u32*)(self+0x90)==23)fn_801F2B20(self,0);

if(*(u32*)(self+0x90)==0){
s32 state=*(s32*)(self+0x230);
if(state!=9&&state!=10&&state!=12&&state!=25&&state!=26&&state!=27&&lbl_8053E2B0==*(f32*)(self+0x2ac)){
fn_80154590(self+0x60,lbl_8053E2B4,lbl_8053E2B4,lbl_8053E2B8,lbl_8053E2B8);
if(*(s32*)(self+0x2a0)!=3)fn_801F2B7C(self,-100,-1,1);else fn_801F2B7C(self,fn_80154510(self),-1,3);
fn_80154590(self+0x60,lbl_8053E2BC,lbl_8053E2BC,lbl_8053E2C0,lbl_8053E2C0);}
((GnonVirtuals*)self)->v20(0);
state=*(s32*)(self+0x230);
if(state!=12&&state!=11&&state!=16&&state!=17&&state!=18)hit=fn_801545C0(self,0,0);
state=*(s32*)(self+0x230);
if(state!=14&&state!=15){
if(state==4){if(*(s32*)(self+0x2a0)!=3)fn_801F71A4(self+0x2ac,lbl_8053E298,lbl_8053E284,lbl_8053E2C4);fn_801F71A4(self+0x14,lbl_8053E2C8,lbl_8053E284,lbl_8053E2C4);*(s32*)(self+0x26c)=0;}
else if(*(u16*)(self+0x94)>=1){if(*(s32*)(self+0x2a0)!=3)fn_801F71A4(self+0x2ac,lbl_8053E2B0,lbl_8053E284,lbl_8053E2C4);fn_801F71A4(self+0x14,lbl_8053E278,lbl_8053E284,lbl_8053E2C4);}
if(*(s32*)(self+0x2a0)==3)fn_801F71A4(self+0x2ac,lbl_8053E2B0,lbl_8053E284,lbl_8053E2C4);
if(*(f32*)(self+0x2ac)>lbl_8053E2CC)*(f32*)(self+0x2ac)=lbl_8053E2B0;
if(*(u16*)(self+0x94)>=1&&*(s32*)(self+0x26c)==0&&*(f32*)(self+0x14)<lbl_8053E2D0){
*(f32*)(self+0x14)=lbl_8053E278;fn_8013CC50(*(u32*)(self+4),self+0xc,0x1c8,0,3,0,0,1,lbl_8053E298);fn_8013CC50(*(u32*)(self+4),self+0xc,0x1c9,0,3,0,0,1,lbl_8053E298);fn_801F0E34(self,0x50028,0);fn_80196D8C((void*)*(u32*)(self+4),0,lbl_8053E2D4,lbl_8053E278);*(s32*)(self+0x26c)=1;}}
*(f32*)(self+0x2b0)=*(f32*)(self+0x2ac);
}

switch(*(s32*)(self+0x230)){
case 3:
*(s32*)(self+0x264)=0;*(s32*)(self+0x23c)=lbl_8053E2E0*fn_80154744()+lbl_8053E2A0;lbl_8053AB90=0;
if(*(s32*)(self+0x240)==0){*(s32*)(self+0x240)=lbl_8053E2E4*fn_80154744()+lbl_8053E2E0;if(*(s32*)(self+0x2a0)==3)*(s32*)(self+0x240)=lbl_8053E2E8*fn_80154744()+lbl_8053E2E8;}
*(s32*)(self+0x28c)=5;self[0x2a6]=0;*(s16*)(self+0x2b4)=0;*(f32*)(self+0x2ac)=lbl_8053E2B0;*(f32*)(self+0x2b0)=lbl_8053E2B0;*(s32*)(self+0x274)=0;*(s32*)(self+0x230)=4;
case 4:
*(f32*)(self+0x2b8)=lbl_8053E2D4*fn_801544FC(*(s16*)(self+0x2b6));*(f32*)(self+0x2bc)=lbl_8053E2D4*fn_801544E4(*(s16*)(self+0x2b6));
if(*(s32*)(self+0x2a0)==3&&*(f32*)(self+0x10)>lbl_8053E2B8+*(f32*)(self+0x2e0)&&*(f32*)(self+0x40)>lbl_8053E298&&*(s32*)(self+0x24c)==0){*(s32*)(self+0x23c)=0;*(s32*)(self+0x274)=1;}
*(s16*)(self+0x2b4)+=0x1000;fn_801F0E34(self,0x400b2,0);
if(!self[0x2a5]){fn_80196D70(&saved.x,(f32*)(self+0xc));fn_80196D70((f32*)(self+0xc),(f32*)(self+0x2c4));fn_801F0E34(self,0x30052,0);fn_80196D70((f32*)(self+0xc),&saved.x);}
if((hit!=0||*(s32*)(self+0x23c)==0)&&*(s32*)(self+0x250)==0){fn_801546BC(self+0x2b8);fn_801546BC(self+0x3c);*(s32*)(self+0x230)=5;break;}
if(*(s32*)(self+0x2a0)!=3&&*(s32*)(self+0x2fc)==-1){*(s32*)(self+0x230)=7;break;}
if(!self[0x2a5]&&*(s32*)(self+0x240)==0){
if(*(s32*)(self+0x2a0)==0&&*(f32*)(self+0x10)<*(f32*)(self+0x2e0))*(s32*)(self+0x230)=19;
if(*(s32*)(self+0x2a0)==1)*(s32*)(self+0x230)=25;
if(*(s32*)(self+0x2a0)==3&&*(f32*)(self+0x10)<*(f32*)(self+0x2e0))*(s32*)(self+0x230)=22;}break;
case 5:
*(s32*)(self+0x264)=*(s32*)(self+0x240);*(s32*)(self+0x28c)=1;*(s32*)(self+0x23c)=50;fn_801546BC(self+0x2b8);fn_801546BC(self+0x3c);*(s32*)(self+0x268)=0;*(s32*)(self+0x26c)=0;*(s32*)(self+0x230)=6;break;
}
}

extern "C" void fn_80192BD8(char* this_);
extern "C" void fn_80196020(char* this_, s32 idx) {
    char* self = this_;
    s32 i = idx;
    if (i < 0) {
        return;
    }
    if (*(s32*)(self + 0x268) < 0) {
        u8* h;
        char* base;
        h = *(u8**)(self + 0x328);
        if (h != 0) {
            *(u32*)(h + 0xf4) |= 1;
            *(s32*)(h + 0x24) = 1;
            *(u8**)(self + 0x328) = 0;
        }
        h = *(u8**)(self + 0x32c);
        if (h != 0) {
            *(u32*)(h + 0xf4) |= 1;
            *(s32*)(h + 0x24) = 1;
            *(u8**)(self + 0x32c) = 0;
        }
        base = self + 8;
        h = *(u8**)(self + 0x330);
        if (h != 0) {
            *(u32*)(h + 0xf4) |= 1;
            *(s32*)(h + 0x24) = 1;
            *(u8**)(base + 0x328) = 0;
        }
        h = *(u8**)(self + 0x334);
        if (h != 0) {
            *(u32*)(h + 0xf4) |= 1;
            *(s32*)(h + 0x24) = 1;
            *(u8**)(base + 0x32c) = 0;
        }
        h = *(u8**)(self + 0x338);
        if (h != 0) {
            *(u32*)(h + 0xf4) |= 1;
            *(s32*)(h + 0x24) = 1;
            *(u8**)(base + 0x330) = 0;
        }
        *(s32*)(self + 0x328) = fn_8013CC50(*(u32*)(self + 4), fn_8023E724(i), 0x2a6, 0, 0, 0, 0, 1, lbl_8053E298);
        *(s32*)(self + 0x32c) = fn_8013CC50(*(u32*)(self + 4), fn_8023E724(i), 0x2a7, 0, 0, 0, 0, 1, lbl_8053E298);
    }
    if (fn_8022F3DC(i) >= 0) {
        i = fn_8022F3DC(i);
    }
    fn_8022CA6C(i, 5, 0);
    if (fn_802317F0(i, lbl_804C1BC0[i], fn_8023E724(i), lbl_804C1BD0 + i * 12, 6)) {
        *(f32*)(self + 0x2a8) = lbl_8053E298;
        *(s32*)(self + 0x234) = 100;
        *(s32*)(self + 0x230) = 0x22;
    } else {
        *(s32*)(self + 0x230) = 0x21;
    }
}

#pragma opt_propagation off
extern "C" void fn_80196208(char* this_, s32 mode) {
    s32 best = -1;
    s32 i;
    *(s32*)(this_ + 0x2fc) = -1;
    for (i = 0; i < 4; i++) {
        if (!fn_8023F264(i)) continue;
        s32 room = *(s32*)(this_ + 4);
        if (room != fn_8023DE58(i)) continue;
        if (fn_80230188(i)) continue;
        if (fn_8022DCD8(i)) continue;
        if ((mode == 0 && fn_80237774(i) >= best) || (mode == 1 && fn_80236228(i) >= best)) {
            if ((mode == 0 && best == fn_80237774(i)) || (mode == 1 && best == fn_80236228(i))) {
                if (((JMARandFast*)((u8*)lbl_8053AAF8 + 0xb4))->get_ufloat_1() < 0.5f) continue;
            }
            if (mode == 0) best = fn_80237774(i);
            if (mode == 1) best = fn_80236228(i);
            f32 dx = ((f32*)fn_8023E724(i))[0] - *(f32*)(this_ + 0xc);
            f32 dy = ((f32*)fn_8023E724(i))[1] - *(f32*)(this_ + 0x10);
            f32 d = std::sqrtf(dx * dx + dy * dy);
            *(f32*)(this_ + 0x2f4) = d;
            f32 angle = JMath::atanTable_.atan2_(dx, dy);
            angle *= 10430.3779296875f;
            *(s16*)(this_ + 0x304) = (s16)angle;
            *(s32*)(this_ + 0x2fc) = i;
        }
    }
}

struct GnonAnimTables {
s16 offsets[16];
u8 pad20[0x100];
u8* frames1[16];
u8* delays1[16];
u8 pad1a0[0x100];
u8* frames2[16];
u8* delays2[16];
};
extern u8 lbl_804A1FF8[];
#pragma opt_propagation off
static inline void gnonReadTrack(u8* p, u8** frames, s16* offsets, u8** delays, s32& frame, s32& timer, s32& index) {
frame=frames[*(s32*)(p+0x28c)][index];
frame+=offsets[*(s32*)(p+0x28c)];
timer=delays[*(s32*)(p+0x28c)][index];
index++;
}
extern "C" void fn_801964AC(u8* p) {
GnonAnimTables* tables=(GnonAnimTables*)lbl_804A1FF8;
if(*(s32*)(p+0x28c)!=*(s32*)(p+0x290)) {
*(s32*)(p+0x290)=*(s32*)(p+0x28c);
p[0x2a4]=0; *(s32*)(p+0x234)=0; *(s32*)(p+0x238)=0; *(s32*)(p+0x25c)=0; *(s32*)(p+0x260)=0;
}
if(*(s32*)(p+0x234)==0) {
{
u8** delays; s16* offsets; u8** frames;
frames=tables->frames1; offsets=tables->offsets; delays=tables->delays1;
*(s32*)(p+0x284)=frames[*(s32*)(p+0x28c)][*(s32*)(p+0x25c)];
*(s32*)(p+0x284)+=offsets[*(s32*)(p+0x28c)];
*(s32*)(p+0x234)=delays[*(s32*)(p+0x28c)][*(s32*)(p+0x25c)];
(*(s32*)(p+0x25c))++;
}
if(*(s32*)(p+0x28c)==8) {
if(*(s32*)(p+0x264)==0) { if(*(s32*)(p+0x25c)>2) *(s32*)(p+0x25c)=0; }
else p[0x2a5]=0;
}
s32 state=*(s32*)(p+0x28c);
u8** frames=tables->frames1;
if(frames[state][*(s32*)(p+0x25c)]==0xff) {
if((u32)state<=1 || state==5 || state==3 || state==10 || state==12) {
*(s32*)(p+0x25c)=0;
if(*(s32*)(p+0x28c)==10 && (*(s32*)(p+0x23c)!=0 || *(s32*)(p+0x230)!=11)) fn_801F0E34(p,0x50006,0);
} else if(state==6) *(s32*)(p+0x25c)=4;
else (*(s32*)(p+0x25c))--;
p[0x2a4]=1;
if(*(s32*)(p+0x28c)==2) { *(s32*)(p+0x28c)=3; *(s32*)(p+0x25c)=0; }
if(*(s32*)(p+0x28c)==13 || *(s32*)(p+0x28c)==14) { p[0x2a4]=0; *(s32*)(p+0x25c)=0; *(s32*)(p+0x28c)=9; }
if(*(s32*)(p+0x28c)==9) { *(s32*)(p+0x28c)=10; fn_801F0E34(p,0x50006,0); *(s32*)(p+0x25c)=0; }
}
}
if(*(s32*)(p+0x238)==0) {
{
u8** delays; s16* offsets; u8** frames;
frames=tables->frames2; offsets=tables->offsets; delays=tables->delays2;
*(s32*)(p+0x288)=frames[*(s32*)(p+0x28c)][*(s32*)(p+0x260)];
*(s32*)(p+0x288)+=offsets[*(s32*)(p+0x28c)];
*(s32*)(p+0x238)=delays[*(s32*)(p+0x28c)][*(s32*)(p+0x260)];
(*(s32*)(p+0x260))++;
}
if(*(s32*)(p+0x28c)==8 && *(s32*)(p+0x264)==0 && *(s32*)(p+0x260)>2) *(s32*)(p+0x260)=0;
s32 state=*(s32*)(p+0x28c);
u8** frames=tables->frames2;
if(frames[state][*(s32*)(p+0x260)]==0xff) {
if((u32)state<=1 || state==5 || state==3 || state==10 || state==12) *(s32*)(p+0x260)=0;
else if(state==6) *(s32*)(p+0x260)=4;
else (*(s32*)(p+0x260))--;
if(*(s32*)(p+0x28c)==2) { *(s32*)(p+0x28c)=3; *(s32*)(p+0x260)=0; }
if(*(s32*)(p+0x28c)==13 || *(s32*)(p+0x28c)==14) *(s32*)(p+0x260)=0;
if(*(s32*)(p+0x28c)==9) { *(s32*)(p+0x28c)=10; *(s32*)(p+0x260)=0; }
}
}
}
#pragma opt_propagation reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"

