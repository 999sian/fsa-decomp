// BZBR_80144134: .text 0x80144134-0x8014529C (actor BZBR)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "Game/ItemBase.h"

extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void fn_801F06F0(void* actor, const char* res, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, DrawRec* rec, f32 sx, f32 sy);
extern char lbl_80465B80[];
extern s32 lbl_8049F408[];
extern s32 lbl_8049F418[];
extern char* lbl_8053AB10;
struct BzbrGame;
extern BzbrGame* lbl_8053AAF8;

// Resource manager at game+0xa4; vtable +0x18 looks a resource up by type and name.
struct BzbrResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};

// ---- from Game/fn_80144134_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F444[];

extern "C" void* fn_80144134(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F444;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_80144194(u8* this_) {
    DrawRec rec;
    f32 mtx[3][4];
    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    if (*(s32*)(this_ + 0x230) == 4) {
        DrawRec rec2;
        f32 m2[3][4];
        f32 cx; f32 ang; f32 sx; f32 sy; f32 sz; f32 cy; f32 cz;
        m2[0][3] = 0.0f;
        m2[1][3] = 0.0f;
        m2[2][3] = 0.0f;
        f32 s = *(f32*)(this_ + 0x250);
        ang = *(f32*)(this_ + 0x254);
        f32 rx = 0.0f;
        sx = sin(rx);
        sy = sin(ang);
        sz = sin(rx);
        cx = cos(rx);
        cy = cos(ang);
        cz = cos(rx);
        f32 sxsy = sx * sy;
        f32 cxsz = cx * sz;
        f32 cxcz = cx * cz;
        f32 sxsz = sx * sz;
        f32 sxcz = sx * cz;
        m2[0][0] = s * (cy * cz);
        m2[1][0] = s * (cy * sz);
        m2[2][0] = s * -sy;
        m2[0][1] = s * (sxsy * cz - cxsz);
        m2[1][1] = s * (sxsy * sz + cxcz);
        m2[2][1] = s * (sx * cy);
        m2[0][2] = s * (cxcz * sy + sxsz);
        m2[1][2] = s * (cxsz * sy - sxcz);
        m2[2][2] = s * (cx * cy);
        rec2.w18 = m2;
        s32 id = lbl_8049F408[*(s32*)(this_ + 0x244)] + 0x10;
        if (*(s32*)(this_ + 4) < 8) {
            void* res = (*(BzbrResMgr**)((u8*)lbl_8053AAF8 + 0xa4))->get(0x534f4220, lbl_80465B80);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, id, &rec2, 1.0f, 1.0f);
        }
    } else if (*(s32*)(this_ + 0x230) != 3) {
        f32 ys = *(f32*)(this_ + 0x25c);
        f32 xs = *(f32*)(this_ + 0x258);
        mtx[0][0] = xs;
        mtx[0][1] = 0.0f;
        mtx[0][2] = 0.0f;
        mtx[1][0] = 0.0f;
        mtx[1][1] = ys;
        mtx[1][2] = 0.0f;
        mtx[2][0] = 0.0f;
        mtx[2][1] = 0.0f;
        mtx[2][2] = ys;
        rec.w18 = mtx;
        if (*(f32*)(this_ + 0x14) != 0.0f) {
            rec.w30 = 0x11;
        }
        fn_801F06F0(this_, lbl_80465B80, lbl_8049F408[*(s32*)(this_ + 0x244)] + 0x10, &rec, 0, 1.0f, 1.0f);
    } else {
        fn_801F06F0(this_, lbl_80465B80, lbl_8049F418[*(s32*)(this_ + 0x244)] + 0x10, 0, 0, 1.0f, 1.0f);
    }
}

extern const f32 lbl_8053CFD8;
extern const f32 lbl_8053CFDC;
extern const f32 lbl_8053D010;
extern const f32 lbl_8053D014;
extern const f32 lbl_8053D018;
extern const f32 lbl_8053CFE0;
extern const f32 lbl_8053CFE4;
extern const f32 lbl_8053CFE8;
extern const f32 lbl_8053CFEC;
extern const f32 lbl_8053CFF0;
extern const f32 lbl_8053CFF4;
extern const f32 lbl_8053CFF8;
extern const f32 lbl_8053CFFC;
extern const f32 lbl_8053D000;
extern const f32 lbl_8053D004;
extern const f32 lbl_8053D008;
extern "C" s32 fn_801F3D94(void* a, s32 b);
extern "C" u8 fn_801F2618(void* a, f32* out, u32 c);
extern "C" void fn_801F0E34(void* a, s32 id, s32 z);
extern "C" u16 fn_8022461C(void* a, s32 b);
extern "C" s32 fn_8023B004(f32* box, s32 room);
extern "C" u8 fn_8023E854(void);
extern "C" void fn_80238548(s32 i, s32 b, f32* p, s32 n);
extern "C" s32 fn_801F285C(void* a, f32* b, u32* c, u32 e, s32 d);
extern "C" u8 fn_801F2FAC(void* a);
extern "C" u32 fn_801F2DB4(void* a, u32 b, u32 c, void* buf);
extern "C" void fn_801EE8F4(void* a, void* outDir, f32* outLen, s32 n);
extern "C" void fn_801EEC98(void* unused, s32 idx, u16* angOut, s32* quadOut, f32* distOut, s32* idxOut, s32 sel, s32 mode);
extern "C" void* fn_8023E724(s32 i);
extern "C" u8 fn_801F23BC(void* a, u32 id, void* f0C, void* f18, void* p80, f32* out1, f32* out2, u32 c);
extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);

struct BzbrRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053CFDC;
    }
};
struct BzbrGame { u8 pad[0xb4]; BzbrRandom rnd; };
extern BzbrGame* lbl_8053AAF8;

extern "C" void fn_80144F9C(u8* this_) {
    *(f32*)(this_ + 0x60) = lbl_8053D010;
    *(f32*)(this_ + 0x64) = lbl_8053D010;
    *(f32*)(this_ + 0x68) = lbl_8053D014;
    *(f32*)(this_ + 0x6c) = lbl_8053D014;
    *(f32*)(this_ + 0x80) = lbl_8053D010;
    *(f32*)(this_ + 0x84) = lbl_8053D010;
    *(f32*)(this_ + 0x88) = lbl_8053D014;
    *(f32*)(this_ + 0x8c) = lbl_8053D014;
    *(u32*)(this_ + 0x90) &= 1;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0x244) = (s32)(lbl_8053D018 * lbl_8053AAF8->rnd.get_ufloat_1());
    *(f32*)(this_ + 0x254) = lbl_8053CFD8;
    *(f32*)(this_ + 0x250) = lbl_8053CFDC;
    *(f32*)(this_ + 0x258) = lbl_8053CFDC;
    *(f32*)(this_ + 0x25c) = lbl_8053CFDC;
    *(f32*)(this_ + 0x260) = lbl_8053CFDC;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
