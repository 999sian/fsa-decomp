#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/ItemBase.h"

extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void fn_80138B7C();
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" char __vt__4SLR3[];
extern "C" char* lbl_8053AAF8;
extern "C" char* lbl_8053AF80;
extern "C" char lbl_80529DEC[];
extern "C" s32 fn_802DE814(s32);
extern "C" char* fn_802D6A9C();
extern "C" void fn_80458FF0(void*, u32, s32, s32);
extern "C" s32 Actor_CreateByID(void*, u32, s32, void*, s32, s32, s32);

struct Slr3VT {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual u8 check();
};

extern "C" double sin(double);
extern "C" double cos(double);
extern const char lbl_804667D8[];
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_80170008(char* self) {
    f32 sasb, casc, cacc;
    f32 sa, sb, sc, ca, cb, cc;
    f32 rx, rz;
    DrawRec rec;
    f32 mtx[3][4];
    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    f32 x = *(f32*)(self + 0xc);
    f32 y = *(f32*)(self + 0x10);
    f32 z = *(f32*)(self + 0x14);
    if (*(u16*)(self + 0x94) == 5) {
        return;
    }
    if ((*(u32*)(self + 0x90) >> 27) != 0) {
        if (!((Slr3VT*)self)->check()) {
            return;
        }
    }
    rec.ids[8] = *(u8*)(self + 0x274);
    fn_801F06F0(self, lbl_804667D8, *(s32*)(self + 0x258) + 0x7f, &rec, 7, 1.0f, 1.0f);
    if (*(s32*)(self + 0x244) == 0) {
        rec.b1d = 1;
    } else {
        rec.b20 = 0;
    }
    rec.ids[6] = 6;
    char* p = self;
    for (s32 i = 0; i < 10; i++) {
        mtx[0][0] = 0.5f;
        mtx[0][1] = 0.0f;
        mtx[0][2] = 0.0f;
        mtx[1][0] = 0.0f;
        mtx[1][1] = 0.5f;
        mtx[1][2] = 0.0f;
        mtx[2][0] = 0.0f;
        mtx[2][1] = 0.0f;
        mtx[2][2] = 0.5f;
        rec.w18 = mtx;
        *(f32*)(self + 0xc) = *(f32*)(p + 0x29c);
        *(f32*)(self + 0x10) = *(f32*)(p + 0x2a0);
        *(f32*)(self + 0x14) = *(f32*)(p + 0x2a4);
        fn_801F06F0(self, lbl_804667D8, 0x83, &rec, 7, 1.0f, 1.0f);
        p += 0xc;
    }
    *(f32*)(self + 0xc) = x;
    *(f32*)(self + 0x10) = y;
    *(f32*)(self + 0x14) = z;
    if (*(s32*)(self + 0x244) == 0) {
        rec.b1d = 2;
    } else {
        rec.b20 = 0;
    }
    f32 ang = *(f32*)(self + 0x278);
    f32 s = *(f32*)(self + 0x27c);
    rx = 0.0f;
    rz = 0.0f;
    sa = sin(rx);
    sb = sin(ang);
    sc = sin(rz);
    ca = cos(rx);
    cb = cos(ang);
    cc = cos(rz);
    cacc = ca * cc;
    sasb = sa * sb;
    casc = ca * sc;
    mtx[0][0] = s * (cb * cc);
    mtx[1][0] = s * (cb * sc);
    mtx[2][0] = s * -sb;
    mtx[0][1] = s * (sasb * cc - casc);
    mtx[1][1] = s * (sasb * sc + cacc);
    mtx[2][1] = s * (sa * cb);
    mtx[0][2] = s * (cacc * sb + sa * sc);
    mtx[1][2] = s * (casc * sb - sa * cc);
    mtx[2][2] = s * (ca * cb);
    rec.w30 = 0x11;
    rec.w18 = mtx;
    if (*(u16*)(self + 0x94) == 4) {
        rec.ids[6] = *(u8*)(self + 0x274);
        rec.b1d = 0;
    }
    *(f32*)(self + 0xc) = *(f32*)(self + 0x314);
    *(f32*)(self + 0x10) = *(f32*)(self + 0x318);
    *(f32*)(self + 0x14) = *(f32*)(self + 0x31c);
    fn_801F06F0(self, lbl_804667D8, 0x82, &rec, 7, 1.0f, 1.0f);
    *(f32*)(self + 0xc) = x;
    *(f32*)(self + 0x10) = y;
    *(f32*)(self + 0x14) = z;
}

void fn_80170450(u8* self)
{
    s32 kind;
    kind = *(u16*)(self + 0x94);
    if (kind != 5) {
        *(s32*)(self + 0x108) = 10000;
    }
}

extern "C" void fn_801719C0(void* this_) {
    char* p = (char*)this_;
    if (*(s32*)(p + 0x108) > 0) {
        return;
    }
    s32 id = *(s32*)(p + 0x26c);
    if (id != 0) {
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            *(u8*)((char*)found + 0x11c) = 0;
            *(s32*)(p + 0x26c) = 0;
        }
    }
}

extern "C" void* fn_80171A28(char* self, s16 flag) {
    if (self != 0) {
        *(char**)self = __vt__4SLR3;
        if (*(u16*)(self + 0x94) != 5) {
            s32 st = *(s32*)(lbl_8053AAF8 + 0x4c);
            if (st != 9 && st != 0xb && *(s32*)(self + 0x108) != 0) {
                fn_80138B7C();
            }
            s32 id = *(s32*)(self + 0x26c);
            if (id != 0) {
                char* p = (char*)fn_801F666C(fn_801F856C(), id);
                if (p != 0) {
                    p[0x11c] = 0;
                }
            }
        }
        fn_801EE434(*(void**)(self + 0x28c));
        __dt__5ActorFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" void fn_80171AF8(char* self) {
    *(u16*)(self + 0x94) = *(u32*)(self + 0x90) & 0xff;
    *(u32*)(self + 0x270) = (*(u32*)(self + 0x90) >> 8) & 1;
    *(f32*)(self + 0x60) = -8.0f;
    *(f32*)(self + 0x64) = -8.0f;
    *(f32*)(self + 0x68) = 8.0f;
    *(f32*)(self + 0x6c) = 8.0f;
    *(f32*)(self + 0x80) = -8.0f;
    *(f32*)(self + 0x84) = -8.0f;
    *(f32*)(self + 0x88) = 8.0f;
    *(f32*)(self + 0x8c) = 8.0f;
    *(s32*)(self + 0x248) = 0;
    *(s32*)(self + 0x24c) = 0;
    *(s32*)(self + 0x250) = 0;
    *(s32*)(self + 0x254) = 0;
    *(s32*)(self + 0x234) = 0;
    *(s32*)(self + 0x238) = 0;
    *(s32*)(self + 0x23c) = 0;
    *(s32*)(self + 0x240) = 0;
    *(s32*)(self + 0x244) = 0;
    *(JGeometry::TVec3<f32>*)(self + 0x29c) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2a8) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2b4) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2c0) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2cc) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2d8) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2e4) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2f0) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x2fc) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x308) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(JGeometry::TVec3<f32>*)(self + 0x314) = *(JGeometry::TVec3<f32>*)(self + 0xc);
    *(f32*)(self + 0x298) = 0.0f;
    *(f32*)(self + 0x294) = 0.0f;
    *(f32*)(self + 0x290) = 0.0f;
    *(f32*)(self + 0x44) = 0.0f;
    *(f32*)(self + 0x40) = 0.0f;
    *(f32*)(self + 0x3c) = 0.0f;
    *(f32*)(self + 0x280) = 0.3f;
    *(f32*)(self + 0x278) = 0.0f;
    *(f32*)(self + 0x27c) = 1.5f;
    *(s32*)(self + 0xb0) = 0xa002204;
    *(s32*)(self + 0xbc) = 3;
    *(s32*)(self + 0x28c) = 0;
    *(s32*)(self + 0x264) = 0;
    if ((u8)fn_802DE814(0xa002204) == 1) {
        *(s32*)(self + 0x108) = 0x10;
    }
    if (*(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 3) {
        *(s32*)(self + 0x108) = 0x18;
    }
    *(s32*)(self + 0x268) = *(s32*)(self + 0x108);
    *(s32*)(self + 0x258) = 0;
    *(f32*)(self + 0x284) = 0.0f;
    *(f32*)(self + 0x288) = 70.0f;
    *(s32*)(self + 0x118) = 0x10;
    ((JGeometry::TVec3<f32>*)(self + 0x32c))->set(*(JGeometry::TVec3<f32>*)(self + 0xc));
    if (*(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 3) {
        char* a = fn_802D6A9C();
        if (*(s32*)(a + 0x18) == 3) {
            char* b = fn_802D6A9C();
            if (*(s32*)(b + 0x14) == 1) {
                *(s32*)(self + 0x244) = 0x64;
            }
        }
    }
    *(s32*)(self + 0x260) = 0;
    *(s32*)(self + 0x25c) = 0;
    *(s32*)(self + 0x98) = 2;
    *(s32*)(self + 0x250) = 0x47e;
    char* random = lbl_8053AAF8;
    *(u32*)(random + 0xb4) = *(u32*)(random + 0xb4) * 0x19660d + 0x3c6ef35f;
    {
        u32 bits = (*(u32*)(random + 0xb4) >> 9) | 0x3f800000;
        *(s32*)(self + 0x23c) = (s32)((*(f32*)&bits - 1.0f) * 100.0f) + 0x64;
    }
    *(u8*)(self + 0x274) = 8;
    *(s32*)(self + 0x26c) = 0;
    *(s32*)(self + 0x230) = 0;
    switch (*(u16*)(self + 0x94)) {
    case 0:
        *(s32*)(self + 0x250) = 0x190;
        break;
    case 3: {
        *(u8*)(self + 0x274) = 6;
        char* random = lbl_8053AAF8;
    *(u32*)(random + 0xb4) = *(u32*)(random + 0xb4) * 0x19660d + 0x3c6ef35f;
        {
            u32 bits = (*(u32*)(random + 0xb4) >> 9) | 0x3f800000;
            *(s32*)(self + 0x23c) = (s32)((*(f32*)&bits - 1.0f) * 50.0f) + 0x32;
        }
        *(s32*)(self + 0x250) = 0x64;
        *(f32*)(self + 0x27c) = 1.0f;
        *(f32*)(self + 0x288) = 10.0f;
        *(s32*)(self + 0x230) = 2;
        break;
    }
    case 1:
        *(u8*)(self + 0x274) = 4;
        *(f32*)(self + 0x27c) = 1.0f;
        *(f32*)(self + 0x288) = 10.0f;
        *(s32*)(self + 0x230) = 1;
        break;
    case 2:
        *(u8*)(self + 0x274) = 2;
        break;
    case 4:
        *(s32*)(self + 0x23c) = 0x32;
        *(u8*)(self + 0x274) = 3;
        *(s32*)(self + 0x230) = 3;
        break;
    case 5:
        *(s32*)(self + 0x114) = 4;
        *(s32*)(self + 0x108) = 0x2710;
        *(u8*)(self + 0x1a8) = 0;
        break;
    }
    if ((*(u32*)(self + 0x90) >> 27) != 0) {
        *(s32*)(self + 0xb0) = 0;
    } else {
        if (*(u16*)(self + 0x94) != 5) {
            *(s32*)(self + 0x26c) = Actor_CreateByID(fn_801F856C(), 0x534c5233, *(s32*)(self + 0x4), self + 0xc, 5, -1, -1);
            if ((u8)lbl_8053AAF8[0x7f] == 1) {
                fn_80458FF0(lbl_8053AF80, 0x1000021, 0, 0);
            }
        }
    }
}

