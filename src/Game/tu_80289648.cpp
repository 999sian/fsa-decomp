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


extern "C" char lbl_804A78B0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
struct ObjSlots {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* v4(s32 a, void* b);
};

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

extern "C" void fn_802896A8(Actor* this_)
{
    DrawRec rec;
    f32 mtx[3][4];

    rec.b1d = -1;
    switch ((*(u32*)((u8*)this_ + 0x90) >> 12) & 0x1f) {
    case 0:
        PSMTXTrans(mtx, *(u16*)(*(u8**)((u8*)this_ + 0x240) + 2) * *(f32*)((u8*)this_ + 0x230) * 0.5f, 0.0f, -*(u16*)(*(u8**)((u8*)this_ + 0x240) + 4) * *(f32*)((u8*)this_ + 0x234) * 0.5f);
        break;
    case 1:
        PSMTXTrans(mtx, -*(u16*)(*(u8**)((u8*)this_ + 0x240) + 2) * *(f32*)((u8*)this_ + 0x230) * 0.5f, 0.0f, -*(u16*)(*(u8**)((u8*)this_ + 0x240) + 4) * *(f32*)((u8*)this_ + 0x234) * 0.5f);
        break;
    case 2:
        PSMTXTrans(mtx, *(u16*)(*(u8**)((u8*)this_ + 0x240) + 2) * *(f32*)((u8*)this_ + 0x230) * 0.5f, 0.0f, -*(u16*)(*(u8**)((u8*)this_ + 0x240) + 4) * *(f32*)((u8*)this_ + 0x234) * 0.5f);
        break;
    case 3:
        PSMTXTrans(mtx, *(u16*)(*(u8**)((u8*)this_ + 0x240) + 2) * *(f32*)((u8*)this_ + 0x230) * 0.5f, 0.0f, *(u16*)(*(u8**)((u8*)this_ + 0x240) + 4) * *(f32*)((u8*)this_ + 0x234) * 0.5f);
        break;
    default:
        mtx[0][3] = 0.0f;
        mtx[1][3] = 0.0f;
        mtx[2][3] = 0.0f;
        break;
    }

    {
        f32 s = sincosTable___5JMath[0];
        f32 c = sincosTable___5JMath[1];
        f32 a = *(f32*)((u8*)this_ + 0x230);
        f32 b = *(f32*)((u8*)this_ + 0x234);

        mtx[0][0] = a * (c * c);
        mtx[1][0] = a * (c * s);
        mtx[2][0] = a * -s;
        mtx[0][1] = 1.0f * (s * s * c - c * s);
        mtx[1][1] = 1.0f * (s * s * s + c * c);
        mtx[2][1] = 1.0f * (c * s);
        mtx[0][2] = b * (c * c * s + s * s);
        mtx[1][2] = b * (c * s * s - c * s);
        mtx[2][2] = b * (c * c);
    }

    rec.w18 = (void*)mtx;
    rec.b21 = 1;
    rec.b1d = -2;
    if (*(s32*)((u8*)this_ + 4) < 8) {
        void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
        void* tex = ((void* (*)(void*, u32))(*(void***)obj)[6])(obj, 0x54494d47);
        fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), (u8*)this_ + 0xc, tex, &rec);
    }
}

extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053A198;
extern "C" void fn_801F0E34(void* this_, u32 code, u32 z);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" void fn_8022E088(s32 idx, s32 n, JGeometry::TVec3f* out);
extern "C" void fn_8022DF48(s32 idx);
extern "C" void fn_8023DF68(s32 idx, JGeometry::TVec3f* v);

static inline bool tuInBox(u8* self, const JGeometry::TVec3f& v) {
    if (v.x >= *(f32*)(self + 0x60) && v.y >= *(f32*)(self + 0x64) && v.x < *(f32*)(self + 0x68) && v.y < *(f32*)(self + 0x6c)) {
        return true;
    }
    return false;
}

static inline bool tuCheckHit(u8* self, s32 idx) {
    if (*(s32*)(self + 0x4) != fn_8023DE58(idx)) {
        return false;
    }
    for (s32 j = 0; j < 8; j++) {
        JGeometry::TVec3f v;
        fn_8022E088(idx, j, &v);
        v -= *(JGeometry::TVec3f*)(self + 0xc);
        v.z = 0.0f;
        if (tuInBox(self, v)) {
            fn_8022DF48(idx);
            return true;
        }
    }
    return false;
}
extern "C" void fn_80289F6C(Actor* this_) {
    u8* self = (u8*)this_;
    s32 mode;
    s32 a;
    u8* t;

    if (((*(u32*)(self + 0x90) >> 7) & 0x1f) == 0) {
        *(u32*)(self + 0x90) |= 0x80;
    }
    if (((*(u32*)(self + 0x90) >> 17) & 0x1f) == 0) {
        *(u32*)(self + 0x90) |= 0x20000;
    }
    {
        ObjSlots* o = *(ObjSlots**)((u8*)lbl_8053AAF8 + 0xa4);
        *(void**)(self + 0x240) = o->v4(0x3f3f3f3f, lbl_8053A198);
    }
    *(s32*)(self + 0x108) = 0;

    mode = (*(u32*)(self + 0x90) >> 12) & 0x1f;
    switch (mode) {
    case 1:
        *(f32*)(self + 0xc) += 16.0f;
        break;
    case 3:
        *(f32*)(self + 0x10) += 16.0f;
        break;
    }

    a = (*(u32*)(self + 0x90) >> 7) & 0x1f;
    if (mode < 2) {
        *(f32*)(self + 0x238) = 0.0f;
        *(f32*)(self + 0x23c) = 16.0f * a;
    } else {
        *(f32*)(self + 0x238) = 16.0f * a;
        *(f32*)(self + 0x23c) = 0.0f;
    }

    t = *(u8**)(self + 0x240);
    *(f32*)(self + 0x230) = *(f32*)(self + 0x238) / (f32)*(u16*)(t + 2);
    *(f32*)(self + 0x234) = *(f32*)(self + 0x23c) / (f32)*(u16*)(t + 4);
    *(u8*)(self + 0x244) = 0;
}

