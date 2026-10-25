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

extern "C" void fn_801F0E34(void* this_, u32 code, u32 z);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" void fn_8022E088(s32 idx, s32 n, JGeometry::TVec3f* out);
extern "C" void fn_8022DF48(s32 idx);
extern "C" void fn_8023DF68(s32 idx, const JGeometry::TVec3f& v);
static inline void fn_8023DF68(s32 idx, JGeometry::TVec3f* v) { fn_8023DF68(idx, *v); }

static inline bool tuInBox(const JGeometry::TVec3f& v, f32 x0, f32 y0, f32 x1, f32 y1) {
    if (v.x >= x0 && v.y >= y0 && v.x < x1 && v.y < y1) {
        return true;
    }
    return false;
}

static inline void tuSetBox(u8* self, f32 x0, f32 y0, f32 x1, f32 y1) {
    *(f32*)(self + 0x60) = x0;
    *(f32*)(self + 0x64) = y0;
    *(f32*)(self + 0x68) = x1;
    *(f32*)(self + 0x6c) = y1;
}

static inline bool tuCheckHit(u8* self, s32 idx) {
    s32 room = *(s32*)(self + 0x4);
    if (fn_8023DE58(idx) == room) {
        for (s32 j = 0; j < 8; j++) {
            JGeometry::TVec3f v;
            fn_8022E088(idx, j, &v);
            v -= *(JGeometry::TVec3f*)(self + 0xc);
            v.z = 0.0f;
            if (tuInBox(v, *(f32*)(self + 0x60), *(f32*)(self + 0x64), *(f32*)(self + 0x68), *(f32*)(self + 0x6c))) {
                fn_8022DF48(idx);
                return true;
            }
        }
    }
    return false;
}

static inline bool tuInBox2(const JGeometry::TVec3f& v, const f32* box) {
    f32 x0 = box[0];
    f32 y0 = box[1];
    f32 x1 = box[2];
    f32 y1 = box[3];
    if (v.x >= x0 && v.y >= y0 && v.x < x1 && v.y < y1) {
        return true;
    }
    return false;
}

static inline bool tuCheckHit2(u8* self, s32 idx, s32 room) {
    if (fn_8023DE58(idx) != room) {
        return false;
    }
    for (s32 j = 0; j < 8; j++) {
        JGeometry::TVec3f v;
        fn_8022E088(idx, j, &v);
        v -= *(JGeometry::TVec3f*)(self + 0xc);
        v.z = 0.0f;
        if (tuInBox(v, *(f32*)(self + 0x60), *(f32*)(self + 0x64), *(f32*)(self + 0x68), *(f32*)(self + 0x6c))) {
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
    oldC.z = 0.0f;
    oldC.x = 0.5f * (*(f32*)(self + 0x60) - *(f32*)(self + 0x68)) + *(f32*)(self + 0x68);
    oldC.y = 0.5f * (*(f32*)(self + 0x64) - *(f32*)(self + 0x6c)) + *(f32*)(self + 0x6c);
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

    JGeometry::TVec3f newC;
    newC.z = 0.0f;
    u8* t = *(u8**)(self + 0x240);
    f32 sw = (f32)*(u16*)(t + 2);
    f32 sh = (f32)*(u16*)(t + 4);
    f32 a = *(f32*)(self + 0x238);
    f32 b = *(f32*)(self + 0x23c);
    newC.x = 0.5f * (*(f32*)(self + 0x60) - *(f32*)(self + 0x68)) + *(f32*)(self + 0x68);
    newC.y = 0.5f * (*(f32*)(self + 0x64) - *(f32*)(self + 0x6c)) + *(f32*)(self + 0x6c);
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

