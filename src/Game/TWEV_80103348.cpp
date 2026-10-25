// TWEV_80103348: .text 0x80103348-0x801042D0 (actor TWEV)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "Game/Actor.h"
extern "C" void fn_801F0E34(void*, u32, s32);
extern "C" s32 fn_8013CC50(void*, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80134DE4(void*, s32, s32);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void*, u32, s32, s32);
extern void* lbl_8053AAF8;
extern f32 lbl_8053C1E8;

struct TWEVParam {
    u8 buf[16];
    s32 a;
    s32 b;
    void* c;
    s8 d[11];
    s32 e;
    u8 f[3];
    s32 g;
    s32 h;
    s32 i;
};

struct TWEVVec {
    f32 x;
    f32 y;
    f32 z;
};

typedef f32 TWEVMtx[3][4];

extern "C" double sin(double);
extern "C" double cos(double);

extern char lbl_80463BD0[];
extern f32 lbl_8053C1D0;
extern f32 lbl_8053C1D4;
extern f32 lbl_8053C1D8;

static void fn_80103348_rotMtx(TWEVMtx m, f32 ax, f32 ay, f32 az) {
    f32 sa = sin(ax);
    f32 sb = sin(ay);
    f32 sc = sin(az);
    f32 ca = cos(ax);
    f32 cb = cos(ay);
    f32 cc = cos(az);
    f32 s = lbl_8053C1D8;
    m[0][0] = s * (cb * cc);
    m[0][1] = s * (sa * sb * cc - ca * sc);
    m[0][2] = s * (ca * cc * sb + sa * sc);
    m[1][0] = s * (cb * sc);
    m[1][1] = s * (sa * sb * sc + ca * cc);
    m[1][2] = s * (ca * sc * sb - sa * cc);
    m[2][0] = s * -sb;
    m[2][1] = s * (sa * cb);
    m[2][2] = s * (ca * cb);
}

// ---- from Game/fn_80103F28_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern "C" void fn_801EE434(void* handle);
extern void* lbl_8049CA40[];

extern "C" void fn_80103348(void* this_);
extern "C" u32 fn_804032E8(u32 tag, void* name);
extern "C" void fn_801EFD34(void* this_, u32 id, void* param, s32 n, f32 a, f32 b, f32 c);
extern "C" void fn_80103348(void* this_) {
    char* p = (char*)this_;
    char* names = lbl_80463BD0;
    f32 savedPos[3];
    TWEVMtx mtx;
    TWEVParam param;
    s32 i;
    f32 ang;

    param.a = -1;
    param.b = -1;
    for (i = 0; (u8)i < 16; i += 8) {
        param.buf[(u8)i] = i;
        param.buf[(u8)(i + 1)] = i + 1;
        param.buf[(u8)(i + 2)] = i + 2;
        param.buf[(u8)(i + 3)] = i + 3;
        param.buf[(u8)(i + 4)] = i + 4;
        param.buf[(u8)(i + 5)] = i + 5;
        param.buf[(u8)(i + 6)] = i + 6;
        param.buf[(u8)(i + 7)] = i + 7;
    }
    param.a = -1;
    param.b = 0;
    param.c = 0;
    param.d[0] = 0;
    param.d[1] = 0;
    param.d[2] = 0;
    param.d[3] = 1;
    param.d[4] = 1;
    param.d[5] = 0;
    param.d[6] = 0;
    param.d[7] = 0;
    param.d[8] = 0;
    param.d[9] = 0;
    param.d[10] = 1;
    param.e = 3;
    param.f[0] = 1;
    param.f[1] = 0;
    param.f[2] = 0;
    param.g = -1;
    param.h = 0;
    param.i = 2;

    *(TWEVVec*)savedPos = *(TWEVVec*)(p + 0xc);
    param.d[1] = -3;
    u32 id = fn_804032E8(0x54494d47, names + 0xc);
    fn_801EFD34(this_, id, &param, -1, lbl_8053C1D0, lbl_8053C1D0, lbl_8053C1D0);

    *(f32*)(p + 0xc) = *(f32*)(p + 0x238);
    *(f32*)(p + 0x10) = *(f32*)(p + 0x23c);
    *(f32*)(p + 0x14) = *(f32*)(p + 0x240);
    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    ang = *(s32*)(p + 0x264) / lbl_8053C1D4;
    fn_80103348_rotMtx(mtx, lbl_8053C1D0, ang, lbl_8053C1D0);
    param.c = mtx;
    param.d[1] = 1;
    id = fn_804032E8(0x54494d47, names + 0x20);
    fn_801EFD34(this_, id, &param, -1, lbl_8053C1D0, lbl_8053C1D0, lbl_8053C1D0);

    *(f32*)(p + 0xc) = *(f32*)(p + 0x244);
    *(f32*)(p + 0x10) = *(f32*)(p + 0x248);
    *(f32*)(p + 0x14) = *(f32*)(p + 0x24c);
    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    ang = *(s32*)(p + 0x268) / lbl_8053C1D4;
    fn_80103348_rotMtx(mtx, lbl_8053C1D0, ang, lbl_8053C1D0);
    param.c = mtx;
    id = fn_804032E8(0x54494d47, names + 0x34);
    fn_801EFD34(this_, id, &param, -1, lbl_8053C1D0, lbl_8053C1D0, lbl_8053C1D0);

    *(f32*)(p + 0xc) = *(f32*)(p + 0x250);
    *(f32*)(p + 0x10) = *(f32*)(p + 0x254);
    *(f32*)(p + 0x14) = *(f32*)(p + 0x258);
    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    ang = *(s32*)(p + 0x26c) / lbl_8053C1D4;
    fn_80103348_rotMtx(mtx, lbl_8053C1D0, ang, lbl_8053C1D0);
    param.c = mtx;
    id = fn_804032E8(0x54494d47, names + 0x48);
    fn_801EFD34(this_, id, &param, -1, lbl_8053C1D0, lbl_8053C1D0, lbl_8053C1D0);

    *(f32*)(p + 0xc) = savedPos[0];
    *(f32*)(p + 0x10) = savedPos[1];
    *(f32*)(p + 0x14) = savedPos[2];
}

extern "C" void fn_80103914(void* this_) {
    char* p = (char*)this_;
    s32 mode = *(s32*)(p + 0x234);
    switch (mode) {
    case 0:
        fn_80103348(this_);
        break;
    case 1:
        if (*(s32*)(p + 0x230) == 2) {
            TWEVParam param;
            s32 i;
            param.a = -1;
            param.b = -1;
            for (i = 0; (u8)i < 16; i += 8) {
                param.buf[(u8)i] = i;
                param.buf[(u8)(i + 1)] = i + 1;
                param.buf[(u8)(i + 2)] = i + 2;
                param.buf[(u8)(i + 3)] = i + 3;
                param.buf[(u8)(i + 4)] = i + 4;
                param.buf[(u8)(i + 5)] = i + 5;
                param.buf[(u8)(i + 6)] = i + 6;
                param.buf[(u8)(i + 7)] = i + 7;
            }
            param.a = -1;
            param.b = 0;
            param.c = 0;
            param.d[0] = 0;
            param.d[1] = 0;
            param.d[2] = 0;
            param.d[3] = 1;
            param.d[4] = 1;
            param.d[5] = 0;
            param.d[6] = 0;
            param.d[7] = 0;
            param.d[8] = 0;
            param.d[9] = 0;
            param.d[10] = 1;
            param.e = 3;
            param.f[0] = 1;
            param.f[1] = 0;
            param.f[2] = 0;
            param.g = -1;
            param.h = 0;
            param.i = 2;
            u32 id = fn_804032E8(0x54494d47, lbl_80463BD0);
            fn_801EFD34(this_, id, &param, -1, lbl_8053C1D0, lbl_8053C1D0, lbl_8053C1D0);
        }
        break;
    case 2:
        break;
    }
}

inline void twevUpdateSingle(void* this_) {
    char* p = (char*)this_;
        switch (*(s32*)(p + 0x230)) {
        case 1: break;
        case 0:
            if ((u8)((Actor*)this_)->v11()) {
                *(s32*)(p + 0x230) = 2;
                fn_8013CC50(*(void**)(p + 4), p + 0xc, 1.0f, 0xd3, 2, 2, 0, 0, 1);
                fn_8013CC50(*(void**)(p + 4), p + 0xc, 1.0f, 0xd4, 2, 2, 0, 0, 1);
                fn_80134DE4(lbl_8053AAF8, 1, 0);
                fn_801F0E34(this_, 0x30001, 0);
            }
            break;
        default: break;
        }

}

extern "C" void fn_80103A90(void* this_) {
    char* p = (char*)this_;
    switch (*(s32*)(p + 0x234)) {
    case 0:
        switch (*(s32*)(p + 0x230)) {
        case 0:
            if ((u8)((Actor*)this_)->v11()) {
                *(s32*)(p + 0x230) = 1;
                *(s32*)(p + 0x288) = 0;
                fn_8013CC50(*(void**)(p + 4), p + 0xc, 1.0f, 0x499, 2, 2, 0, 0, 1);
                fn_8013CC50(*(void**)(p + 4), p + 0xc, 1.0f, 0x49a, 2, 2, 0, 0, 1);
            }
            break;
        case 1:
            ++*(s32*)(p + 0x288);
            fn_801F0E34(this_, 0x3006f, 0);
            if (*(s32*)(p + 0x288) >= 180) {
                *(s32*)(p + 0x230) = 2;
                *(s32*)(p + 0x288) = 0;
            }
            break;
        case 2:
            fn_801F0E34(this_, 0x3006f, 0);
            ++*(s32*)(p + 0x288);
            if (*(s32*)(p + 0x288) > 1) {
                *(f32*)(p + 0x290) += 0.08f;
                *(s32*)(p + 0x268) += 0x20;
            }
            if (*(s32*)(p + 0x288) > 30) {
                *(f32*)(p + 0x28c) += 0.08f;
                *(s32*)(p + 0x264) -= 0x40;
                *(f32*)(p + 0x238) += 1.0f;
            }
            if (*(s32*)(p + 0x288) > 60) {
                *(f32*)(p + 0x294) += 0.08f;
                *(s32*)(p + 0x26c) -= 0x40;
            }
            if (*(s32*)(p + 0x288) == 1) {
                fn_801F0E34(this_, 0x30071, 0);
                fn_8013CC50(*(void**)(p + 4), p + 0xc, 1.0f, 0x49d, 2, 2, 0, 0, 1);
                fn_8013CC50(*(void**)(p + 4), p + 0xc, 1.0f, 0x49e, 2, 2, 0, 0, 1);
                fn_80134DE4(lbl_8053AAF8, 1, 0);
            } else if (*(s32*)(p + 0x288) == 30) {
                fn_801F0E34(this_, 0x30071, 0);
                fn_8013CC50(*(void**)(p + 4), p + 0xc, 1.0f, 0x49b, 2, 2, 0, 0, 1);
                fn_8013CC50(*(void**)(p + 4), p + 0xc, 1.0f, 0x49c, 2, 2, 0, 0, 1);
                fn_80134DE4(lbl_8053AAF8, 1, 0);
            } else if (*(s32*)(p + 0x288) == 60) {
                fn_801F0E34(this_, 0x30070, 0);
                fn_8013CC50(*(void**)(p + 4), p + 0xc, 1.0f, 0x49f, 2, 2, 0, 0, 1);
                fn_8013CC50(*(void**)(p + 4), p + 0xc, 1.0f, 0x4a0, 2, 2, 0, 0, 1);
                fn_80134DE4(lbl_8053AAF8, 3, 0);
            }
            if (*(s32*)(p + 0x288) == 70) {
                u32 id = *(u32*)(p + 0x25c);
                if (id != 0) {
                    fn_802D8050(fn_802D6A9C(), id, 1, 0xff);
                    ((Actor*)this_)->v10(0xff, 0);
                }
            }
            if (*(s32*)(p + 0x288) > 300) *(u8*)(p + 0x11c) = 0;
            *(f32*)(p + 0x23c) += *(f32*)(p + 0x28c);
            *(f32*)(p + 0x248) += *(f32*)(p + 0x290);
            *(f32*)(p + 0x254) += *(f32*)(p + 0x294);
            break;
        }
        break;
    case 1:
        switch (*(s32*)(p + 0x230)) {
        case 2: default: break;
        case 0:
            if ((u8)((Actor*)this_)->v11()) {
                *(s32*)(p + 0x230) = 2;
                fn_8013CC50(*(void**)(p + 4), p + 0xc, 1.0f, 0xd3, 2, 2, 0, 0, 1);
                fn_8013CC50(*(void**)(p + 4), p + 0xc, 1.0f, 0xd4, 2, 2, 0, 0, 1);
                fn_80134DE4(lbl_8053AAF8, 1, 0);
                fn_801F0E34(this_, 0x30001, 0);
            }
            break;
        }
        break;
    case 2: default: break;
    }
}

extern "C" void* fn_80103F28(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049CA40;
        char* p = (char*)this_;
        void* handle = *(void**)(p + 0x260);
        if (handle != 0) {
            fn_801EE434(handle);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_8013CC50(void* a, void* b, f32 scale, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern f32 lbl_8053C1D0;
extern f32 lbl_8053C1D8;
extern char lbl_80463BD0[];
extern "C" void fn_80103F9C(void* this_) {
    char* p = (char*)this_;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x260) = 0;
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 0xf;
    *(u32*)(p + 0x25c) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    switch (*(s32*)(p + 0x234)) {
    case 0: {
        f32 zero;
        *(s32*)(p + 0x288) = 0;
        zero = lbl_8053C1D0;
        *(s32*)(p + 0x264) = 0;
        *(s32*)(p + 0x268) = 0;
        *(s32*)(p + 0x26c) = 0;
        *(f32*)(p + 0x28c) = zero;
        *(f32*)(p + 0x290) = zero;
        *(f32*)(p + 0x294) = zero;
        *(f32*)(p + 0x238) = *(f32*)(p + 0xc);
        *(f32*)(p + 0x23c) = *(f32*)(p + 0x10);
        *(f32*)(p + 0x240) = *(f32*)(p + 0x14);
        *(f32*)(p + 0x244) = *(f32*)(p + 0xc);
        *(f32*)(p + 0x248) = *(f32*)(p + 0x10);
        *(f32*)(p + 0x24c) = *(f32*)(p + 0x14);
        *(f32*)(p + 0x250) = *(f32*)(p + 0xc);
        *(f32*)(p + 0x254) = *(f32*)(p + 0x10);
        *(f32*)(p + 0x258) = *(f32*)(p + 0x14);
        break;
    }
    case 2:
        *(s32*)(p + 0x260) = fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8053C1D8, 0x496, 1, 0, 0, 0, 1);
        break;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
