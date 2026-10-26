// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80187144-8018A8D8 (FGN2). Remaining functions are not yet decompiled.
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

// from src/Game/stub_8018a6a0.cpp
extern void* lbl_8053AF80[2];

// fn_8018A6A0(this, a, b) - trivial 2-float pair setter.
extern "C" void fn_8018A6A0(void* thisObj, f32 a, f32 b) {
	char* p = (char*)thisObj;
	*(f32*)(p + 0x0) = a;
	*(f32*)(p + 0x4) = b;
}

// fn_8018A6AC() - returns the global sound-bank pointer.
extern "C" void* fn_8018A6AC(void) {
	return lbl_8053AF80[0];
}

// Small (inline-style) accessors.
extern char* lbl_8053AAF8;
extern "C" void* fn_8013C824(void* a);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F6884(void* mgr);
extern "C" void* fn_801F68E0(void* mgr);

extern "C" void fn_8018A588(char* p, s32 v) { *(s32*)(p + 0x108) = v; }
extern "C" u16 fn_8018A590(char* p) { return *(u16*)(p + 0x94); }
extern "C" void fn_8018A598(char* p, u8 v) { *(u8*)(p + 0x11c) = v; }
extern "C" void fn_8018A5A0(char* p, s32 v) { *(s32*)(p + 0x98) = v; }
extern "C" void fn_8018A5A8(char* p, u16 v) { *(u16*)(p + 0x94) = v; }
extern "C" u8 fn_8018A5B0(char* p) { return *(u8*)(p + 0x11c); }
extern "C" void fn_8018A5B8(f32* v, f32 x, f32 y, f32 z) { v[0] = x; v[1] = y; v[2] = z; }
extern "C" void fn_8018A5C8(char* p, u8 v) { *(u8*)(p + 0xbb) = v; }
extern "C" void fn_8018A5D0(char* p) { *(u32*)(p + 0xf4) &= ~4; }
extern "C" void fn_8018A5E0(char* p) { *(u32*)(p + 0xf4) |= 4; }
extern "C" void* fn_8018A5F0(void* a) { return *(void**)((char*)fn_8013C824(a) + 0xc); }
extern "C" BOOL fn_8018A614(s32 bit) { return (*(u8*)(lbl_8053AAF8 + 0x82) & (u8)(1 << bit)) != 0; }
extern "C" void* fn_8018A63C(void) { return fn_801F6884(fn_801F856C()); }
extern "C" void* fn_8018A660(void) { return fn_801F68E0(fn_801F856C()); }
extern "C" void fn_8018A684(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

struct ActorVt_fgn2 {
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

extern "C" void fn_80187144(ActorVt_fgn2* this_) {
    fn_801F0E34(this_, 0x40047, 0);
    this_->setShadow(*(s8*)((char*)this_ + 0x2ee), 8.0f, -16.0f);
}

extern "C" void* fn_804032E8(u32, const char*);
extern "C" void fn_801EFD34(void*, void*, DrawRec*, s32, f32, f32, f32);
extern const char lbl_804A1960[];
extern const f32 lbl_8053DFE8, lbl_8053DFEC, lbl_8053DFF0, lbl_8053DFF4, lbl_8053DFF8;
#pragma opt_propagation off
extern "C" void fn_801871A0(char* this_) {
    const char* tbl = lbl_804A1960;
    DrawRec rec;
    f32 sy = lbl_8053DFE8;
    f32 sx = sy;
    JGeometry::TVec3<f32> pos(*(Vec*)(this_ + 0xc));
    f32 mtx[3][4];
    void* tex;
    u8* tag = (u8*)&rec.w10;
    mtx[0][3] = sy;
    mtx[1][3] = sy;
    mtx[2][3] = sy;
    rec.b1f = 0;
    if (*(u32*)(this_ + 0x90) != 0 && *(u32*)(this_ + 0x90) != 1) {
        return;
    }
    *(f32*)(this_ + 0x14) = lbl_8053DFE8;
    switch (*(s32*)(this_ + 0x278)) {
    case 0: {
        const char* const* p = (const char* const*)(tbl + 0xb0);
        tex = fn_804032E8('FGAN', p[*(s32*)(this_ + 0x26c)]);
        break;
    }
    case 1: {
        const char* const* p = (const char* const*)(tbl + 0xf0);
        tex = fn_804032E8('FGAN', p[*(s32*)(this_ + 0x26c)]);
        const f32 (*sc)[2] = (const f32 (*)[2])(tbl + 0xc8);
        sx = sc[*(s32*)(this_ + 0x26c)][0];
        sy = sc[*(s32*)(this_ + 0x26c)][1];
        break;
    }
    case 2: {
        const char* const* p = (const char* const*)(tbl + 0x104);
        tex = fn_804032E8('FGAN', p[*(s32*)(this_ + 0x26c)]);
        sy = lbl_8053DFEC;
        break;
    }
    case 3: {
        const char* const* p = (const char* const*)(tbl + 0x124);
        tex = fn_804032E8('FGAN', p[*(s32*)(this_ + 0x26c)]);
        break;
    }
    }
    rec.b1d = -2;
    rec.b1c = 0;
    tag[0] = 0;
    tag[1] = 0;
    tag[2] = 0;
    tag[3] = (u8)(lbl_8053DFF0 * *(f32*)(this_ + 0x290));
    mtx[0][0] = lbl_8053DFF4;
    mtx[0][1] = lbl_8053DFE8;
    mtx[0][2] = lbl_8053DFE8;
    mtx[1][0] = lbl_8053DFE8;
    mtx[1][1] = lbl_8053DFF8;
    mtx[1][2] = lbl_8053DFE8;
    mtx[2][0] = lbl_8053DFE8;
    mtx[2][1] = lbl_8053DFE8;
    mtx[2][2] = mtx[1][1];
    rec.w18 = mtx;
    fn_801EFD34(this_, tex, &rec, -1, sx, sy, lbl_8053DFE8);
    *(Vec*)(this_ + 0xc) = pos;
    rec.b1d = *(u8*)(this_ + 0x2ee);
    rec.w30 = 14;
    f32 sy2 = *(f32*)(this_ + 0x2cc);
    mtx[0][0] = *(f32*)(this_ + 0x2c8);
    mtx[0][1] = lbl_8053DFE8;
    mtx[0][2] = lbl_8053DFE8;
    mtx[1][0] = lbl_8053DFE8;
    mtx[1][1] = sy2;
    mtx[1][2] = lbl_8053DFE8;
    mtx[2][0] = lbl_8053DFE8;
    mtx[2][1] = lbl_8053DFE8;
    mtx[2][2] = sy2;
    rec.w18 = mtx;
    tag[0] = 0xff;
    tag[1] = 0xff;
    tag[2] = 0xff;
    tag[3] = (u8)*(f32*)(this_ + 0x290);
    fn_801EFD34(this_, tex, &rec, -1, sx, sy, lbl_8053DFE8);
}
#pragma opt_propagation reset
extern "C" void fn_80187530(char* this_) {
}

extern "C" s32 fn_8022EA0C(s32 idx);
extern "C" u8 fn_8023F264(s32 idx);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" u8 fn_80230188(s32 idx);
extern "C" u8 fn_80236B50(s32 idx);
extern "C" u8 fn_8022DCD8(s32 idx);
extern s32 lbl_8053AB78;
extern const f32 lbl_8053DFF4;
extern const f32 lbl_8053E050;
#pragma opt_propagation off
extern "C" u16 fn_80189DEC(char* this_) {
    s32 cur = fn_8022EA0C(*(u16*)(this_ + 0x94));
    char* p = this_;
    s32 h;
    s32 i;
    s32 cand;
    u32 bits;
    char* rng;
    f32 f;
    if (cur < 0) {
        cur = 0;
    }
    if (fn_8023F264(cur) == 0) {
        goto retry;
    }
    h = *(s32*)(p + 0x4);
    if (h != fn_8023DE58(cur)) {
        goto retry;
    }
    if (fn_80230188(cur) != 0 || fn_80236B50(cur) != 0 || lbl_8053AB78 == 1) {
    retry:
        rng = lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        cand = (s32)(lbl_8053E050 * (*(f32*)&bits - lbl_8053DFF4));
        for (i = 0; i < 4; i++) {
            if (cand != cur && fn_8023F264(cand) != 0) {
                h = *(s32*)(p + 0x4);
                if (h == fn_8023DE58(cand) && fn_8022EA0C(cand) == cand && fn_80230188(cand) == 0 && fn_80236B50(cand) == 0 && fn_8022DCD8(cand) == 0) {
                    *(s16*)(p + 0x94) = cand;
                    if (lbl_8053AB78 == 1) {
                        *(s32*)(p + 0x27c) = *(u16*)(p + 0x94);
                    }
                    return *(u16*)(p + 0x94);
                }
            }
            cand++;
            cand &= 3;
        }
    }
    *(s16*)(p + 0x94) = cur;
    return *(u16*)(p + 0x94);
}
#pragma opt_propagation reset
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* mgr, s32 a);
extern "C" void fn_8022ADCC(void);
extern "C" char* fn_801F666C(void* mgr, s32 handle);
extern void* lbl_804A1A98[];
struct Handles_fgn2 { u8 pad[0x2f4]; void* a[4]; void* b[4]; void* c; };

// FGN2 destructor
extern "C" void* fn_80189F74(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1A98;
        s32 h;
        for (int i = 0; i < 4; i++) {
            fn_801EE434(((Handles_fgn2*)this_)->a[i]);
            fn_801EE434(((Handles_fgn2*)this_)->b[i]);
        }
        fn_801EE434(((Handles_fgn2*)this_)->c);
        if (*(u32*)(this_ + 0x90) == 0) {
            fn_802D7440(fn_802D6A9C(), 1);
            fn_8022ADCC();
        }
        if (*(u32*)(this_ + 0x90) == 10) {
            h = *(s32*)(this_ + 0x274);
            if (h >= 0) {
                char* c = fn_801F666C(fn_801F856C(), h);
                if (c != 0) {
                    *(f32*)(c + 0x28c) = 3.0f;
                    *(s32*)(this_ + 0x274) = -1;
                }
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern const f32 lbl_8053DFE0;
extern const f32 lbl_8053DFE4;
extern const f32 lbl_8053DFFC;
extern const f32 lbl_8053E00C;
extern const f32 lbl_8053E010;
extern const f32 lbl_8053E01C;
extern const f32 lbl_8053E084;
extern const f32 lbl_8053E08C;
extern const f32 lbl_8053E098;
extern const f32 lbl_8053E0B0;
extern const f32 lbl_8053E0B4;
extern const f32 lbl_8053E0B8;
extern const f64 lbl_8053E0C0;
extern s32 lbl_80539FB8;
extern s32 lbl_8053AB7C;
extern s32 lbl_8053AB80;
extern u8 lbl_80539FBC;
extern u8 lbl_8053AB84;
extern char lbl_804A19F0[];
extern "C" s32 fn_8013CC50(void* room, void* pos, u16 id, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e);
static u8 lbl_804C17A8[0x10];
#pragma opt_propagation off
extern "C" void fn_8018A070(char* this_) {
    char* tbl;
    char* p;
    char* entry;
    s32 k;
    s32 off;
    char* h;
    off = 0;
    p = this_;
    *(u16*)(this_ + 0x94) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
    *(u32*)(this_ + 0x90) &= 0xf;
    *(s32*)(this_ + 0x24c) = off;
    *(s32*)(this_ + 0x250) = off;
    *(s32*)(this_ + 0x254) = off;
    *(s32*)(this_ + 0x258) = off;
    *(s32*)(this_ + 0x25c) = off;
    *(s32*)(this_ + 0x260) = off;
    *(s32*)(this_ + 0x264) = off;
    *(s32*)(this_ + 0x268) = off;
    *(s32*)(this_ + 0x234) = off;
    *(s32*)(this_ + 0x238) = off;
    *(s32*)(this_ + 0x23c) = off;
    *(s32*)(this_ + 0x240) = off;
    *(s32*)(this_ + 0x244) = off;
    *(s32*)(this_ + 0x248) = off;
    *(u8*)(this_ + 0x196) = 1;
    *(s32*)(this_ + 0x26c) = off;
    *(f32*)(this_ + 0x2ac) = lbl_8053DFE8;
    *(f32*)(this_ + 0x2b8) = lbl_8053DFE8;
    *(f32*)(this_ + 0x2b4) = lbl_8053DFE8;
    *(f32*)(this_ + 0x2b0) = lbl_8053DFE8;
    *(f32*)(this_ + 0x44) = lbl_8053DFE8;
    *(f32*)(this_ + 0x40) = lbl_8053DFE8;
    *(f32*)(this_ + 0x3c) = lbl_8053DFE8;
    *(s32*)(this_ + 0x2f4) = off;
    *(s32*)(this_ + 0x304) = off;
    *(s32*)(this_ + 0x2f8) = off;
    *(s32*)(this_ + 0x308) = off;
    *(s32*)(this_ + 0x2fc) = off;
    *(s32*)(this_ + 0x30c) = off;
    *(s32*)(this_ + 0x300) = off;
    *(s32*)(this_ + 0x310) = off;
    *(s32*)(this_ + 0x314) = off;
    *(f32*)(this_ + 0x14) = lbl_8053DFF4;
    *(f32*)(this_ + 0x280) = lbl_8053E010;
    *(f32*)(this_ + 0x28c) = lbl_8053DFE8;
    *(u8*)(this_ + 0x2ef) = off;
    *(u32*)(this_ + 0x274) = -1;
    *(s32*)(this_ + 0x278) = 2;
    *(u16*)(this_ + 0x2ec) = off;
    *(f32*)(this_ + 0x294) = lbl_8053E01C;
    *(f32*)(this_ + 0x2a0) = *(f32*)(lbl_804A1960 + *(u16*)(this_ + 0x94) * 12);
    *(f32*)(this_ + 0x298) = lbl_8053E01C;
    *(f32*)(this_ + 0x2a4) = *(f32*)(lbl_804A1960 + *(u16*)(this_ + 0x94) * 12 + 4);
    *(f32*)(this_ + 0x29c) = lbl_8053E01C;
    *(f32*)(this_ + 0x2a8) = *(f32*)(lbl_804A1960 + *(u16*)(this_ + 0x94) * 12 + 8);
    *(u32*)(this_ + 0x108) = 10000;
    *(u8*)(this_ + 0x2f0) = off;
    *(f32*)(this_ + 0x290) = lbl_8053E01C;
    *(f32*)(this_ + 0x284) = lbl_8053DFE8;
    *(f32*)(this_ + 0x288) = lbl_8053DFE8;
    *(f32*)(this_ + 0x2c8) = lbl_8053DFF4;
    *(f32*)(this_ + 0x2cc) = lbl_8053DFF4;
    *(f32*)(this_ + 0x2d0) = lbl_8053DFF4;
    fn_8018A684((f32*)(this_ + 0x2bc), (f32*)(this_ + 0xc));
    *(f32*)(this_ + 0x2c0) = *(f32*)(this_ + 0x2c0) + lbl_8053DFE0;
    *(f32*)(this_ + 0x2d4) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2d8) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2dc) = *(f32*)(this_ + 0x14);

    switch (*(s32*)(this_ + 0x90)) {
    case 0: default:
        *(f32*)(this_ + 0x60) = lbl_8053DFE4;
        *(f32*)(this_ + 0x64) = lbl_8053E08C;
        *(f32*)(this_ + 0x68) = lbl_8053E084;
        *(f32*)(this_ + 0x6c) = lbl_8053DFFC;
        *(f32*)(this_ + 0x80) = lbl_8053E08C;
        *(f32*)(this_ + 0x84) = lbl_8053E08C;
        *(f32*)(this_ + 0x88) = lbl_8053DFE0;
        *(f32*)(this_ + 0x8c) = lbl_8053DFE0;
        *(f32*)(this_ + 0x290) = lbl_8053DFE8;
        *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0xc) - lbl_8053E00C;
        fn_8018A684((f32*)(this_ + 0x2e0), (f32*)(this_ + 0xc));
        fn_8018A684((f32*)(this_ + 0x2d4), (f32*)(this_ + 0xc));
        fn_802D7440(fn_802D6A9C(), 0);
        lbl_80539FB8 = 100;
        lbl_8053AB78 = 0;
        lbl_8053AB7C = 0;
        lbl_8053AB80 = 0;
        lbl_80539FBC = 0;
        lbl_8053AB84 = 0;
        *(u32*)(lbl_804C17A8 + 0) = 0;
        *(u32*)(lbl_804C17A8 + 4) = 0;
        *(u32*)(lbl_804C17A8 + 8) = 0;
        *(u32*)(lbl_804C17A8 + 12) = 0;
        *(s32*)(this_ + 0x114) = 2;
        *(f32*)(this_ + 0x288) = lbl_8053DFFC;
        *(u8*)(this_ + 0x2ee) = 1;
        *(u32*)(this_ + 0x230) = 0;
        break;
    case 1:
        *(f32*)(this_ + 0x60) = lbl_8053DFE4;
        *(f32*)(this_ + 0x64) = lbl_8053E08C;
        *(f32*)(this_ + 0x68) = lbl_8053E084;
        *(f32*)(this_ + 0x6c) = lbl_8053DFFC;
        *(f32*)(this_ + 0x80) = lbl_8053E08C;
        *(f32*)(this_ + 0x84) = lbl_8053E08C;
        *(f32*)(this_ + 0x88) = lbl_8053DFE0;
        *(f32*)(this_ + 0x8c) = lbl_8053DFE0;
        *(f32*)(this_ + 0x290) = lbl_8053DFE8;
        *(f32*)(this_ + 0x2d4) += lbl_8053E098 * (f32)*(u16*)(this_ + 0x94);
        *(s32*)(this_ + 0x114) = 2;
        *(f32*)(this_ + 0x288) = lbl_8053DFFC;
        *(u8*)(this_ + 0x2ee) = 1;
        *(s32*)(this_ + 0x230) = 5;
        break;
    case 10:
        tbl = lbl_804A19F0;
        p = this_;
        for (k = 0; k < 4; k++) {
            entry = tbl + off;
            *(s32*)(p + 0x2f4) = fn_8013CC50(*(void**)(this_ + 4), this_ + 0xc, *(u16*)entry, lbl_8053DFF4, 1, 2, 0, 0, 1);
            *(s32*)(p + 0x304) = fn_8013CC50(*(void**)(this_ + 4), this_ + 0xc, *(u16*)(entry + 2), lbl_8053DFF4, 1, 2, 0, 0, 1);
            if (k != *(u16*)(this_ + 0x94)) {
                h = *(char**)(p + 0x2f4);
                if (h != 0) {
                    *(u32*)(h + 0xf4) |= 4;
                }
                h = *(char**)(p + 0x304);
                if (h != 0) {
                    *(u32*)(h + 0xf4) |= 4;
                }
            }
            off += 4;
            p += 4;
        }
        *(u8*)(this_ + 0x2f0) = 0xb;
        if (lbl_8053AB78 == 1) {
            *(u8*)(this_ + 0x2f0) = 6;
        }

    case 11:
        *(f32*)(this_ + 0x2d0) = lbl_8053DFE8;
        *(f32*)(this_ + 0x2cc) = lbl_8053DFE8;
        *(f32*)(this_ + 0x2c8) = lbl_8053DFE8;
        *(u8*)(this_ + 0x2ee) = 2;
        *(f32*)(this_ + 0x60) = lbl_8053E0B0;
        *(f32*)(this_ + 0x64) = lbl_8053E0B0;
        *(f32*)(this_ + 0x68) = lbl_8053E0B4;
        *(f32*)(this_ + 0x6c) = lbl_8053E0B4;
        *(f32*)(this_ + 0x80) = lbl_8053E0B8;
        *(f32*)(this_ + 0x84) = lbl_8053E0B8;
        *(f32*)(this_ + 0x88) = lbl_8053E010;
        *(f32*)(this_ + 0x8c) = lbl_8053E010;
        if (*(u32*)(this_ + 0x90) == 11) {
            *(s32*)(this_ + 0x2f4) = fn_8013CC50(*(void**)(this_ + 4), this_ + 0xc, 0x37a, lbl_8053DFF4, 1, 2, 0, 0, 1);
            *(s32*)(this_ + 0x304) = fn_8013CC50(*(void**)(this_ + 4), this_ + 0xc, 0x37b, lbl_8053DFF4, 1, 2, 0, 0, 1);
        }
        *(s32*)(this_ + 0x118) = 4;
        *(s32*)(this_ + 0x230) = 0x1d;
        break;
    case 12:
        *(s32*)(this_ + 0x234) = 0x1e;
        *(u8*)(this_ + 0x2ee) = 2;
        *(f32*)(this_ + 0x60) = lbl_8053E0B8;
        *(f32*)(this_ + 0x64) = lbl_8053E0B8;
        *(f32*)(this_ + 0x68) = lbl_8053E010;
        *(f32*)(this_ + 0x6c) = lbl_8053E010;
        *(f32*)(this_ + 0x80) = lbl_8053E0B8;
        *(f32*)(this_ + 0x84) = lbl_8053E0B8;
        *(f32*)(this_ + 0x88) = lbl_8053E010;
        *(f32*)(this_ + 0x8c) = lbl_8053E010;
        *(s32*)(this_ + 0x118) = 2;
        *(s32*)(this_ + 0x230) = 0x1e;
        break;
    }
    *(s32*)(this_ + 0x27c) = *(u16*)(this_ + 0x94);
    *(s32*)(this_ + 0x270) = lbl_80539FB8 << 2;
}
#pragma opt_propagation reset


#include "JSystem/JAudio/JASFakeMatchFSA.h"
