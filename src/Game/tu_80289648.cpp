#include "types.h"
#define Vec SDKVec
#define PSVECMag SDK_PSVECMag
#define PSMTXScale SDK_PSMTXScale
#define PSMTXConcat SDK_PSMTXConcat
#define PSMTXIdentity SDK_PSMTXIdentity
#include "JSystem/JGeometry/Vec.h"
#undef PSMTXIdentity
#undef PSMTXConcat
#undef PSMTXScale
#undef PSVECMag
#undef Vec
#include "Game/Actor.h"
#include "Game/ItemBase.h"

extern "C" void fn_802F745C(void* a, void* b, void* c, DrawRec* d);
extern "C" void PSMTXTrans(f32 m[3][4], f32 x, f32 y, f32 z);
extern "C" const f32 sincosTable___5JMath[];
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053A198;


extern "C" char lbl_804A78B0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
struct ObjSlots {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(s32 a, void* b);
};

extern "C" void fn_801F0E34(void* this_, u32 code, u32 z);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" void fn_8022E088(s32 idx, s32 n, JGeometry::TVec3f* out);
extern "C" void fn_8022DF48(s32 idx);
extern "C" void fn_8023DF68(s32 idx, const JGeometry::TVec3f& v);

static inline void tuGetCenter(u8* self, JGeometry::TVec3f& c) {
    c.z = 0.0f;
    c.x = 0.5f * (*(f32*)(self + 0x60) - *(f32*)(self + 0x68)) + *(f32*)(self + 0x68);
    c.y = 0.5f * (*(f32*)(self + 0x64) - *(f32*)(self + 0x6c)) + *(f32*)(self + 0x6c);
}

static inline void tuSetBox(u8* self, f32 x0, f32 y0, f32 x1, f32 y1) {
    *(f32*)(self + 0x60) = x0;
    *(f32*)(self + 0x64) = y0;
    *(f32*)(self + 0x68) = x1;
    *(f32*)(self + 0x6c) = y1;
}

static inline bool tuInBox2(const JGeometry::TVec3f& v, const f32* box) {
    f32 x0 = box[0];
    f32 y0 = box[1];
    f32 x1 = box[2];
    f32 y1 = box[3];
    bool ret = false;
    if (v.x >= x0 && v.y >= y0 && v.x < x1 && v.y < y1) {
        ret = true;
    }
    return ret;
}

static inline bool tuCheckHit2(u8* self, s32 idx, s32 room) {
    s32 r = fn_8023DE58(idx);
    if (r != room) {
        return false;
    }
    for (s32 j = 0; j < 8; j++) {
        JGeometry::TVec3f v;
        fn_8022E088(idx, j, &v);
        v -= *(JGeometry::TVec3f*)(self + 0xc);
        v.z = 0.0f;
        if (tuInBox2(v, (f32*)(self + 0x60))) {
            fn_8022DF48(idx);
            return true;
        }
    }
    return false;
}

extern "C" Actor* fn_80289648(Actor* p, s16 n)
{
    if (p != NULL) {
        *(void**)p = lbl_804A78B0;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" const f32 lbl_80540460, lbl_80540464, lbl_80540468;
extern "C" void fn_802896A8(Actor* this_)
{
    DrawRec rec;
    f32 mtx[3][4];

    rec.b1d = -1;
    switch ((*(u32*)((u8*)this_ + 0x90) >> 12) & 0x1f) {
    case 0: {
 const f32 x0=*(u16*)(*(u8**)((u8*)this_ + 0x240) + 2);
 const f32 z0=-*(u16*)(*(u8**)((u8*)this_ + 0x240) + 4);
 f32 x=x0 * *(f32*)((u8*)this_ + 0x230);
 f32 z=z0 * *(f32*)((u8*)this_ + 0x234);
 f32 half=lbl_80540460;
 PSMTXTrans(mtx,half*x,lbl_80540464,z*half);
 break;
}
    case 1: {
 const f32 x0=-*(u16*)(*(u8**)((u8*)this_ + 0x240) + 2);
 const f32 z0=-*(u16*)(*(u8**)((u8*)this_ + 0x240) + 4);
 f32 x=x0 * *(f32*)((u8*)this_ + 0x230);
 f32 z=z0 * *(f32*)((u8*)this_ + 0x234);
 f32 half=lbl_80540460;
 PSMTXTrans(mtx,half*x,lbl_80540464,z*half);
 break;
}
    case 2: {
 const f32 x0=*(u16*)(*(u8**)((u8*)this_ + 0x240) + 2);
 const f32 z0=-*(u16*)(*(u8**)((u8*)this_ + 0x240) + 4);
 f32 x=x0 * *(f32*)((u8*)this_ + 0x230);
 f32 z=z0 * *(f32*)((u8*)this_ + 0x234);
 f32 half=lbl_80540460;
 PSMTXTrans(mtx,half*x,lbl_80540464,z*half);
 break;
}
    case 3: {
 const f32 x0=*(u16*)(*(u8**)((u8*)this_ + 0x240) + 2);
 const f32 z0=*(u16*)(*(u8**)((u8*)this_ + 0x240) + 4);
 f32 x=x0 * *(f32*)((u8*)this_ + 0x230);
 f32 z=z0 * *(f32*)((u8*)this_ + 0x234);
 f32 half=lbl_80540460;
 PSMTXTrans(mtx,half*x,lbl_80540464,z*half);
 break;
}
    default:
        mtx[0][3] = lbl_80540464;
        mtx[1][3] = lbl_80540464;
        mtx[2][3] = lbl_80540464;
        break;
    }

    {
 f32 sasb,cc,casc,a0,a1,a2,a3,a4,a5,a6,a7,a8,cacc;
 f32 sa,sc,sx,sy,sb,ca,cb,sz;
 sa = sincosTable___5JMath[0]; sb=sa; sc=sa;
 ca = sincosTable___5JMath[1]; cb=ca; cc=ca;
 sx=*(f32*)((u8*)this_+0x230); sy=*(f32*)((u8*)this_+0x234); sz=lbl_80540468;
 cacc=ca*cc; sasb=sa*sb; casc=ca*sc;
 a0=cb*cc; a1=cb*sc; a2=-sb; a3=sasb*cc-casc; a4=sasb*sc+cacc; a5=sa*cb;
 a6=cacc*sb+sa*sc; a7=casc*sb-sa*cc; a8=ca*cb;
 mtx[0][0]=sx*a0; mtx[1][0]=sx*a1; mtx[2][0]=sx*a2;
 mtx[0][1]=sz*a3; mtx[1][1]=sz*a4; mtx[2][1]=sz*a5;
 mtx[0][2]=sy*a6; mtx[1][2]=sy*a7; mtx[2][2]=sy*a8;
 }

    rec.w18 = (void*)mtx;
    rec.b21 = 1;
    rec.b1d = -2;
    void* name=lbl_8053A198;
    if (*(s32*)((u8*)this_ + 4) < 8) {
        void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
        void* tex = ((void* (*)(void*, u32, void*))(*(void***)obj)[6])(obj, 0x54494d47, name);
        fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), (u8*)this_ + 0xc, tex, &rec);
    }
}

extern "C" void fn_80289A88(Actor* this_) {
    u8* self = (u8*)this_;

    if ((u8)this_->v11()) {
        if (self[0x244] == 0) {
            fn_801F0E34(this_, 0x30041, 0);
        }
        self[0x244] = 1;
    } else if ((*(u32*)(self + 0x90) & 0x7f) == 0) {
        if (self[0x244] == 1) {
            fn_801F0E34(this_, 0x30041, 0);
        }
        self[0x244] = 0;
    }

    if (self[0x244] != 0) {
        if ((s32)((*(u32*)(self + 0x90) >> 12) & 0x1f) < 2) {
            *(f32*)(self + 0x238) += 1.0f;
            if (*(f32*)(self + 0x238) >= (f32)(s32)(((*(u32*)(self + 0x90) >> 17) & 0x1f) << 4)) {
                *(f32*)(self + 0x238) = (f32)(s32)(((*(u32*)(self + 0x90) >> 17) & 0x1f) << 4);
            }
        } else {
            *(f32*)(self + 0x23c) += 1.0f;
            if (*(f32*)(self + 0x23c) >= (f32)(s32)(((*(u32*)(self + 0x90) >> 17) & 0x1f) << 4)) {
                *(f32*)(self + 0x23c) = (f32)(s32)(((*(u32*)(self + 0x90) >> 17) & 0x1f) << 4);
            }
        }
    } else {
        if ((s32)((*(u32*)(self + 0x90) >> 12) & 0x1f) < 2) {
            *(f32*)(self + 0x238) -= 1.0f;
            if (*(f32*)(self + 0x238) <= 0.0f) {
                *(f32*)(self + 0x238) = 0.0f;
            }
        } else {
            *(f32*)(self + 0x23c) -= 1.0f;
            if (*(f32*)(self + 0x23c) <= 0.0f) {
                *(f32*)(self + 0x23c) = 0.0f;
            }
        }
    }

    JGeometry::TVec3f oldC;
    tuGetCenter(self, oldC);
    switch ((s32)((*(u32*)(self + 0x90) >> 12) & 0x1f)) {
    case 0:
        tuSetBox(self, 0.0f, 3.0f, *(f32*)(self + 0x238), *(f32*)(self + 0x23c) - 3.0f);
        break;
    case 1:
        tuSetBox(self, -*(f32*)(self + 0x238), 3.0f, 0.0f, *(f32*)(self + 0x23c) - 3.0f);
        break;
    case 2:
        tuSetBox(self, 3.0f, 0.0f, *(f32*)(self + 0x238) - 3.0f, *(f32*)(self + 0x23c));
        break;
    case 3:
        tuSetBox(self, 3.0f, -*(f32*)(self + 0x23c), *(f32*)(self + 0x238) - 3.0f, 0.0f);
        break;
    }

    u8* t = *(u8**)(self + 0x240);
    f32 sh = (f32)*(u16*)(t + 4);
    f32 sw = (f32)*(u16*)(t + 2);
    f32 a = *(f32*)(self + 0x238);
    f32 b = *(f32*)(self + 0x23c);
    JGeometry::TVec3f newC;
    { f32 cx = *(f32*)(self+0x68); f32 cy = *(f32*)(self+0x6c); f32 x, y; newC.z=0.0f; x = 0.5f * (*(f32*)(self+0x60)-cx)+cx; y = 0.5f * (*(f32*)(self+0x64)-cy)+cy; newC.x=x; newC.y=y; }
    *(f32*)(self + 0x230) = a / sw;
    *(f32*)(self + 0x234) = b / sh;

    for (s32 i = 0; i < 4; i++) {
        if (tuCheckHit2(self, i, *(s32*)(self + 0x4))) {
            if (!(newC - oldC).isZero()) {
                fn_8023DF68(i, newC - oldC);
            }
        }
    }
}

extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053A198;
extern "C" void fn_80289F6C(Actor* this_) {
    u8* self = (u8*)this_;
    u8* t;
    u32 v;

    if (((*(volatile u32*)(self + 0x90) >> 7) & 0x1f) == 0) {
        *(volatile u32*)(self + 0x90) |= 0x80;
    }
    if (((*(volatile u32*)(self + 0x90) >> 17) & 0x1f) == 0) {
        *(volatile u32*)(self + 0x90) |= 0x20000;
    }
    {
        ObjSlots* o = *(ObjSlots**)((u8*)lbl_8053AAF8 + 0xa4);
        *(void**)(self + 0x240) = o->v4(0x3f3f3f3f, lbl_8053A198);
    }
    *(s32*)(self + 0x108) = 0;

    switch ((s32)((*(u32*)(self + 0x90) >> 12) & 0x1f)) {
    case 0:
        break;
    case 1:
        *(f32*)(self + 0xc) += 16.0f;
        break;
    case 2:
        break;
    case 3:
        *(f32*)(self + 0x10) += 16.0f;
        break;
    }

    v = *(u32*)(self + 0x90);
    if ((s32)((v >> 12) & 0x1f) < 2) {
        *(f32*)(self + 0x238) = 0.0f;
        *(f32*)(self + 0x23c) = 16.0f * (s32)((v >> 7) & 0x1f);
    } else {
        *(f32*)(self + 0x238) = 16.0f * (s32)((v >> 7) & 0x1f);
        *(f32*)(self + 0x23c) = 0.0f;
    }

    t = *(u8**)(self + 0x240);
    {
        f32 w = *(u16*)(t + 2);
        f32 h = *(u16*)(t + 4);
        f32 x = *(f32*)(self + 0x238);
        f32 y = *(f32*)(self + 0x23c);
        *(f32*)(self + 0x230) = x / w;
        *(f32*)(self + 0x234) = y / h;
    }
    *(u8*)(self + 0x244) = 0;
}

