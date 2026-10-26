#include "JSystem/JGeometry/Vec.h"
#define Vec ActorVec
#include "Game/Actor.h"
#undef Vec
#include "Game/ItemBase.h"
#include "Game/SinitPoolChain.h"

extern "C" s32 lbl_805409D0[2];
extern "C" const f32 lbl_805409EC;
extern "C" const f32 lbl_805409F0;
extern "C" const f32 lbl_805409F4;
extern "C" const f32 lbl_805409F8;
extern "C" const f32 lbl_805409FC;
extern "C" const f32 lbl_80540A00;
extern "C" const f32 lbl_80540A04;
extern "C" const f32 lbl_80540A08;
extern "C" u8 sincosTable___5JMath[];
extern "C" void fn_801F71A4(void* p, f32 target, f32 a, f32 b);
extern "C" u8 fn_801F2B7C(Actor* a, s32 b, s32 c, s32 d);

static inline f32 movementInvSqrt(f32 x) { return JGeometry::TUtilf::inv_sqrt(x); }
static inline void movementNormalize(JGeometry::TVec3<f32>* v) {
    f32 squared = v->squared();
    if (squared <= JGeometry::TUtilf::epsilon()) return;
    f32 inverse = movementInvSqrt(squared);
    v->scale(inverse);
}

struct Color4 {
    Color4(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
    u8 r, g, b, a;
};


struct Tu802BVirtual {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual u8 check(); virtual s32 getState();
};

struct VecOp : Vec {
    VecOp& operator+=(const Vec& o)
    {
        x += o.x;
        y += o.y;
        z += o.z;
        return *this;
    }
};

extern "C" char lbl_804A8588[];
extern "C" const f32 lbl_805409D8;
extern "C" const f32 lbl_805409DC;
extern "C" const f32 lbl_805409E0;
extern "C" const f32 lbl_805409E4;
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802B214C(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804A8588;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" u8 fn_802B21AC(Actor* param_1, int param_2, f32* param_3)
{
    int ret = param_1->Actor::v17(param_2, param_3);
    if ((u8)ret == 0) {
        *((u8*)param_1 + 0x27c) = 0;
    }
    return (u8)ret;
}

extern "C" u8 fn_801F2618(Actor* a, Vec* out, u32 c);
extern "C" void fn_802B21EC(Actor* param_1)
{
    u8* p = (u8*)param_1;
    JGeometry::TVec3<f32>* pos = (JGeometry::TVec3<f32>*)(p + 0xc);
    JGeometry::TVec3<f32>* vel = (JGeometry::TVec3<f32>*)(p + 0x3c);
    JGeometry::TVec3<f32>* acc = (JGeometry::TVec3<f32>*)(p + 0x270);
    JGeometry::TVec3<f32> hitE;
    JGeometry::TVec3<f32> hitD;
    u8 hit1, hit2, hit3;
    hitE.zero();
    hitD.zero();
    f32 factor;
    f32 sign = lbl_805409D8;
    JGeometry::TVec3<f32> posBak(*pos);
    JGeometry::TVec3<f32> velBak(*vel);
    JGeometry::TVec3<f32> accBak(*acc);

    *(u8*)(p + 0x27c) = 0;
    *pos += *vel;
    hit1 = fn_801F2618(param_1, &hitE, 0);
    if (lbl_805409DC != acc->x) {
        *(u8*)(p + 0x27c) = 1;
        *pos += *acc;
        hit2 = fn_801F2618(param_1, &hitD, 0);
        if (hit1 == 1 && lbl_805409DC != hitE.y) {
            if (acc->x > lbl_805409DC) {
                if (!(vel->y > lbl_805409DC)) {
                    sign = lbl_805409E0;
                }
            } else {
                if (vel->y > lbl_805409DC) {
                    sign = lbl_805409E0;
                }
            }
            factor = lbl_805409E4;
            vel->x = -vel->y * sign;
            acc->y = acc->x * sign;
            vel->y = lbl_805409DC;
            acc->x = lbl_805409DC;
        } else if (!hit2 || lbl_805409DC == hitD.x) {
            if (acc->x > lbl_805409DC) {
                if (vel->y > lbl_805409DC) {
                    sign = lbl_805409E0;
                }
            } else {
                if (!(vel->y > lbl_805409DC)) {
                    sign = lbl_805409E0;
                }
            }
            factor = lbl_805409E4;
            vel->x = -vel->y * sign;
            acc->y = acc->x * sign;
            vel->y = lbl_805409DC;
            acc->x = lbl_805409DC;
            JGeometry::TVec3<f32> oldPos(*pos);
            JGeometry::TVec3<f32> sum(*vel);
            sum *= factor;
            sum += *acc;
            *pos += sum;
            hit3 = fn_801F2618(param_1, 0, 0);
            if (!hit3) {
                *pos = posBak;
                *vel = velBak;
                *acc = accBak;
                *pos += *vel;
            } else {
                *pos = oldPos;
            }
        }
    } else if (lbl_805409DC != acc->y) {
        *(u8*)(p + 0x27c) = 1;
        *pos += *acc;
        hit2 = fn_801F2618(param_1, &hitD, 0);
        if (hit1 == 1 && lbl_805409DC != hitE.x) {
            if (acc->y > lbl_805409DC) {
                if (!(vel->x > lbl_805409DC)) {
                    sign = lbl_805409E0;
                }
            } else {
                if (vel->x > lbl_805409DC) {
                    sign = lbl_805409E0;
                }
            }
            factor = lbl_805409E4;
            vel->y = -vel->x * sign;
            acc->x = acc->y * sign;
            vel->x = lbl_805409DC;
            acc->y = lbl_805409DC;
        } else if (!hit2 || lbl_805409DC == hitD.y) {
            if (acc->y > lbl_805409DC) {
                if (vel->x > lbl_805409DC) {
                    sign = lbl_805409E0;
                }
            } else {
                if (!(vel->x > lbl_805409DC)) {
                    sign = lbl_805409E0;
                }
            }
            factor = lbl_805409E4;
            vel->y = -vel->x * sign;
            acc->x = acc->y * sign;
            vel->x = lbl_805409DC;
            acc->y = lbl_805409DC;
            JGeometry::TVec3<f32> oldPos(*pos);
            JGeometry::TVec3<f32> sum(*vel);
            sum *= factor;
            sum += *acc;
            *pos += sum;
            hit3 = fn_801F2618(param_1, 0, 0);
            if (!hit3) {
                *pos = posBak;
                *vel = velBak;
                *acc = accBak;
                *pos += *vel;
            } else {
                *pos = oldPos;
            }
        }
    }
    if (*(u8*)(p + 0x27c) == 1) {
        *pos = posBak;
        *vel = velBak;
        *acc = accBak;
    }
}

extern "C" char lbl_8046CA80[];
extern "C" const f32 lbl_805409D8;
extern "C" f32 lbl_805409E8;
extern "C" u8* lbl_8053AB10;
extern "C" void fn_801F06F0(Actor* a, const char* tbl, s32 id, void* rec, s32 p5, f32 f1, f32 f2);
extern "C" void fn_80158B5C(void* mgr, u32 id, void* pos, Color4 col, f32 radius);
extern "C" void fn_803075AC(u32 callerID, u32 ownerID, void* pos, s32 effectRef, s32 flag, s32 mode, s32 targetPlayerIdx, s32 kind, s32 stackArg9, s32 stackArg10);
extern "C" void fn_802B2728(Actor* param_1)
{
    if (*(s32*)((u8*)param_1 + 0x25c) != 0) {
        DrawRec rec;
        DrawRec* recp = &rec;

        fn_801F06F0(param_1, lbl_8046CA80, *(s32*)((u8*)param_1 + 0x258) + 0x78, NULL, 1, lbl_805409D8, lbl_805409D8);
        fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), *(u32*)((u8*)param_1 + 4), (u8*)param_1 + 0xc, Color4(0, 0, 0, 0x80), lbl_805409E8);
        fn_803075AC(*(u32*)((u8*)param_1 + 0x198), *(u32*)((u8*)param_1 + 4), (u8*)param_1 + 0xc, *(s32*)((u8*)param_1 + 0x258) + 0x78, 0, 2, -1, 0, 0, 0);
    }
}

#pragma opt_propagation off
extern "C" void fn_802B28E4(Actor* param_1)
{
    u8* p = (u8*)param_1;
    JGeometry::TVec3<f32>* pos = (JGeometry::TVec3<f32>*)(p + 0xc);
    JGeometry::TVec3<f32>* vel = (JGeometry::TVec3<f32>*)(p + 0x3c);
    JGeometry::TVec3<f32> hit;
    s32 r;
    s32 cnt;

    *(s32*)(p+0x250) -= 1;
    if (*(s32*)(p+0x250) == 0) {
        if (*(s32*)(p+0x240) == 2) {
            s32 st=*(s32*)(p+0x248);
            if (((st==0 || st==3) && *(s32*)(p+0x24c)==0) ||
                ((st==1 || st==2) && *(s32*)(p+0x24c)==1)) {
                *(s32*)(p+0x258) -= 1;
                if (*(s32*)(p+0x258)<0) *(s32*)(p+0x258)=4;
                goto timerReset;
            }
        }
        *(s32*)(p+0x258) += 1;
        if (*(s32*)(p+0x258)>=5) *(s32*)(p+0x258)=0;
timerReset:
        *(s32*)(p+0x250)=4;
    }

    switch (*(s32*)(p + 0x240)) {
    case 0:
        *(s32*)(p + 0x244) += lbl_805409D0[*(s32*)(p + 0x248)];
        *(f32*)(p + 0xc) = lbl_805409EC * *(f32*)(sincosTable___5JMath + (((u16)*(s32*)(p + 0x244) >> 2) & 0x3ff8)) + *(f32*)(p + 0x234);
        *(f32*)(p + 0x10) = lbl_805409EC * *(f32*)(sincosTable___5JMath + (((u16)*(s32*)(p + 0x244) >> 2) & 0x3ff8) + 4) + *(f32*)(p + 0x238);
        *(s32*)(p + 0x25c) = 0;
        r = ((Tu802BVirtual*)param_1)->getState();
        if (r >= 6) {
            p[0x11c] = 0;
        } else {
            r = ((Tu802BVirtual*)param_1)->getState();
            if (r >= 3) {
                *(s32*)(p + 0x25c) = 1;
            }
            r = ((Tu802BVirtual*)param_1)->getState();
            if (r == 3 && (*(u32*)(p + 0x90) & 0xf) == 0) {
                *(s32*)(p + 0x25c) = 0;
            }
        }
        if (*(s32*)(p + 0x254) == 0) {
        if (*(s32*)(p + 0x25c) != 0) {
            *(f32*)(p + 0x60) = lbl_805409F0;
            *(f32*)(p + 0x64) = lbl_805409F0;
            *(f32*)(p + 0x68) = lbl_805409F4;
            *(f32*)(p + 0x6c) = lbl_805409F4;
            if (fn_801F2B7C(param_1, *(s32*)(p + 0x114), -1, 1)) {
                *(s32*)(p + 0x248) ^= 1;
                *(s32*)(p + 0x254) = 0x28;
            }
        }
        } else { *(s32*)(p+0x254)-=1; }
        break;
    case 1:
        fn_801F71A4(p + 0x3c, *(f32*)(p + 0x260), lbl_805409F8, *(f32*)(p + 0x26c));
        fn_801F71A4(p + 0x40, *(f32*)(p + 0x264), lbl_805409F8, *(f32*)(p + 0x26c));
        fn_801F71A4(p + 0x26c, lbl_805409D8, lbl_805409FC, lbl_805409FC);
        *pos += *vel;
        if (fn_801F2618(param_1, &hit, 0)) {
            if (hit.x != lbl_805409DC) {
                if (hit.x >= lbl_805409DC) { *(f32*)(p+0x260)=lbl_805409D8; } else { *(f32*)(p+0x260)=lbl_805409E0; }
            }
            if (hit.y != lbl_805409DC) {
                if (hit.y >= lbl_805409DC) { *(f32*)(p+0x264)=lbl_805409D8; } else { *(f32*)(p+0x264)=lbl_805409E0; }
            }
        }
        if (fn_801F2B7C(param_1, *(s32*)(p + 0x114), -1, 1)) {
            if (*(f32*)(p + 0x260) >= lbl_805409DC) { *(f32*)(p+0x260)=lbl_805409E0; } else { *(f32*)(p+0x260)=lbl_805409D8; }
            if (*(f32*)(p + 0x264) >= lbl_805409DC) { *(f32*)(p+0x264)=lbl_805409E0; } else { *(f32*)(p+0x264)=lbl_805409D8; }
        }
        break;
    case 2: {
        JGeometry::TVec3<f32>* desired=(JGeometry::TVec3<f32>*)(p+0x260);
        if (((Tu802BVirtual*)param_1)->check() == 1) {
            desired->zero();
            *desired += *vel;
            ((JGeometry::TVec3<f32>*)(p+0x270))->normalize();
            *(JGeometry::TVec3<f32>*)(p+0x270) *= lbl_805409E0;
            ((JGeometry::TVec3<f32>*)(p+0x270))->z=lbl_805409DC;
            *desired += *(JGeometry::TVec3<f32>*)(p+0x270);
            *(f32*)(p+0x26c)=lbl_80540A08;
            *(s32*)(p+0x240)=1;
        } else {
            switch (*(s32*)(p+0x230)) {
            case 0:
                *pos += *vel;
                if (fn_801F2618(param_1, (JGeometry::TVec3<f32>*)(p+0x270), 0)==1) {
                    *(s32*)(p+0x230)=1;
                    ((JGeometry::TVec3<f32>*)(p+0x270))->normalize();
                    *(JGeometry::TVec3<f32>*)(p+0x270) *= lbl_805409E0;
                    ((JGeometry::TVec3<f32>*)(p+0x270))->z=lbl_805409DC;
                    vel->x=vel->y=vel->z=lbl_805409DC;
                    f32 sign=lbl_805409D8;
                    if (*(s32*)(p+0x24c)==1) sign=lbl_805409E0;
                    switch (*(s32*)(p+0x248)) {
                    case 0: case 1: vel->x=sign; break;
                    case 2: case 3: vel->y=sign; break;
                    }
                }
                break;
            case 1:
                fn_802B21EC(param_1);
                fn_801F2B7C(param_1, *(s32*)(p+0x114), -1, 1);
                break;
            }
        }
        break;
    }
    }
}
#pragma opt_propagation reset
extern "C" f32 lbl_80540A0C;
extern "C" f32 lbl_80540A10;
extern "C" f32 lbl_80540A14;
extern "C" const f32 lbl_80540A08;
extern "C" const f32 lbl_805409DC;
extern "C" const f32 lbl_805409E0;
extern "C" const f32 lbl_805409F0;
extern "C" const f32 lbl_805409F4;
extern "C" f32 lbl_805409C8;
extern "C" void fn_802B2F44(Actor* param_1)
{
    u8* p = (u8*)param_1;
    static const f32 tbl[] = {1.0f, -1.0f};

    *(f32*)(p + 0x60) = -7.0f;
    *(f32*)(p + 0x64) = -7.0f;
    *(f32*)(p + 0x68) = 7.0f;
    *(f32*)(p + 0x6c) = 7.0f;
    *(f32*)(p + 0x80) = -7.0f;
    *(f32*)(p + 0x84) = -7.0f;
    *(f32*)(p + 0x88) = 7.0f;
    *(f32*)(p + 0x8c) = 7.0f;
    *(f32*)(p + 0x10) += 12.0f;
    *(f32*)(p + 0x234) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x238) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x23c) = *(f32*)(p + 0x14);
    *(s32*)(p + 0x250) = 4;
    *(s32*)(p + 0x254) = 0;
    *(s32*)(p + 0x258) = 0;
    *(u32*)(p + 0x248) = *(u32*)(p + 0x90) & 0x7f;
    *(u32*)(p + 0x24c) = (*(u32*)(p + 0x90) >> 12) & 0x1f;
    *(u32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 7) & 0x1f;
    if (*(s32*)(p + 0x240) == 0) {
        *(s32*)(p + 0x25c) = 0;
    } else {
        *(s32*)(p + 0x25c) = 1;
    }
    *(f32*)(p + 0x278) = 0.0f;
    *(f32*)(p + 0x274) = 0.0f;
    *(f32*)(p + 0x270) = 0.0f;
    *(u8*)(p + 0x27c) = 1;
    if (*(s32*)(p + 0x240) == 1) {
        *(f32*)(p + 0x260) = tbl[*(s32*)(p + 0x248)];
        *(f32*)(p + 0x264) = 1.0f;
        *(f32*)(p + 0x26c) = 0.75f;
    } else if (*(s32*)(p + 0x240) == 2) {
        *(f32*)(p + 0x60) = -7.0f;
        *(f32*)(p + 0x64) = -7.0f;
        *(f32*)(p + 0x68) = 7.0f;
        *(f32*)(p + 0x6c) = 7.0f;
        *(f32*)(p + 0x80) = -6.0f;
        *(f32*)(p + 0x84) = -6.0f;
        *(f32*)(p + 0x88) = 6.0f;
        *(f32*)(p + 0x8c) = 6.0f;
        switch (*(s32*)(p + 0x248)) {
        case 0:
            *(JGeometry::TVec3f*)(p + 0x3c) = JGeometry::TVec3f(1.0f, 0.0f, 0.0f);
            break;
        case 1:
            *(JGeometry::TVec3f*)(p + 0x3c) = JGeometry::TVec3f(-1.0f, 0.0f, 0.0f);
            break;
        case 2:
            *(JGeometry::TVec3f*)(p + 0x3c) = JGeometry::TVec3f(0.0f, 1.0f, 0.0f);
            break;
        case 3:
            *(JGeometry::TVec3f*)(p + 0x3c) = JGeometry::TVec3f(0.0f, -1.0f, 0.0f);
            break;
        }
    }
    *(s32*)(p + 0x230) = 0;
}

extern "C" void fn_802B3128(void) {
}

