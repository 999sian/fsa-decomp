#include "Game/Actor.h"
#include "Game/ItemBase.h"
#include "Game/SinitPoolChain.h"

struct Color4 {
    Color4(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
    u8 r, g, b, a;
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
extern "C" f32 lbl_805409D8;
extern "C" f32 lbl_805409DC;
extern "C" f32 lbl_805409E0;
extern "C" f32 lbl_805409E4;
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
    VecOp* pos = (VecOp*)(p + 0xc);
    VecOp* vel = (VecOp*)(p + 0x3c);
    VecOp* acc = (VecOp*)(p + 0x270);
    VecOp posBak = *pos;
    VecOp velBak = *vel;
    VecOp accBak = *acc;
    VecOp hitE;
    VecOp hitD;
    VecOp oldPos;
    VecOp sum;
    f32 sign;
    u8 hit1;
    u8 hit2;
    u8 hit3;

    hitE.x = lbl_805409DC;
    hitE.y = lbl_805409DC;
    hitE.z = lbl_805409DC;
    hitD.x = lbl_805409DC;
    hitD.y = lbl_805409DC;
    hitD.z = lbl_805409DC;
    sign = lbl_805409D8;

    *(u8*)(p + 0x27c) = 0;
    *pos += *vel;
    hit1 = fn_801F2618(param_1, &hitE, 0);
    if (acc->x != lbl_805409DC) {
        *(u8*)(p + 0x27c) = 1;
        *pos += *acc;
        hit2 = fn_801F2618(param_1, &hitD, 0);
        if (hit1 == 1 && hitE.y != lbl_805409DC) {
            if (acc->x > lbl_805409DC) {
                if (vel->y <= lbl_805409DC) {
                    sign = lbl_805409E0;
                }
            } else {
                if (vel->y > lbl_805409DC) {
                    sign = lbl_805409E0;
                }
            }
            vel->x = -vel->y * sign;
            acc->y = acc->x * sign;
            vel->y = lbl_805409DC;
            acc->x = lbl_805409DC;
        } else if (!hit2 || hitD.x == lbl_805409DC) {
            if (acc->x > lbl_805409DC) {
                if (vel->y > lbl_805409DC) {
                    sign = lbl_805409E0;
                }
            } else {
                if (vel->y <= lbl_805409DC) {
                    sign = lbl_805409E0;
                }
            }
            vel->x = -vel->y * sign;
            acc->y = acc->x * sign;
            vel->y = lbl_805409DC;
            acc->x = lbl_805409DC;
            oldPos = *pos;
            sum.x = vel->x * lbl_805409E4 + acc->x;
            sum.y = vel->y * lbl_805409E4 + acc->y;
            sum.z = vel->z * lbl_805409E4 + acc->z;
            *pos += sum;
            hit3 = fn_801F2618(param_1, 0, 0);
            if (hit3) {
                *pos = oldPos;
            } else {
                *pos = posBak;
                *vel = velBak;
                *acc = accBak;
                *pos += *vel;
            }
        }
    } else if (acc->y != lbl_805409DC) {
        *(u8*)(p + 0x27c) = 1;
        *pos += *acc;
        hit2 = fn_801F2618(param_1, &hitD, 0);
        if (hit1 == 1 && hitE.x != lbl_805409DC) {
            if (acc->y > lbl_805409DC) {
                if (vel->x <= lbl_805409DC) {
                    sign = lbl_805409E0;
                }
            } else {
                if (vel->x > lbl_805409DC) {
                    sign = lbl_805409E0;
                }
            }
            vel->y = -vel->x * sign;
            acc->x = acc->y * sign;
            vel->x = lbl_805409DC;
            acc->y = lbl_805409DC;
        } else if (!hit2 || hitD.y == lbl_805409DC) {
            if (acc->y > lbl_805409DC) {
                if (vel->x > lbl_805409DC) {
                    sign = lbl_805409E0;
                }
            } else {
                if (vel->x <= lbl_805409DC) {
                    sign = lbl_805409E0;
                }
            }
            vel->y = -vel->x * sign;
            acc->x = acc->y * sign;
            vel->x = lbl_805409DC;
            acc->y = lbl_805409DC;
            oldPos = *pos;
            sum.x = vel->x * lbl_805409E4 + acc->x;
            sum.y = vel->y * lbl_805409E4 + acc->y;
            sum.z = vel->z * lbl_805409E4 + acc->z;
            *pos += sum;
            hit3 = fn_801F2618(param_1, 0, 0);
            if (hit3) {
                *pos = oldPos;
            } else {
                *pos = posBak;
                *vel = velBak;
                *acc = accBak;
                *pos += *vel;
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
extern "C" f32 lbl_805409D8;
extern "C" f32 lbl_805409E8;
extern "C" u8* lbl_8053AB10;
extern "C" void fn_801F06F0(Actor* a, const char* tbl, s32 id, void* rec, s32 p5, f32 f1, f32 f2);
extern "C" void fn_80158B5C(void* mgr, u32 id, void* pos, Color4 col, f32 radius);
extern "C" void fn_803075AC(u32 callerID, u32 ownerID, void* pos, s32 effectRef, s32 flag, s32 mode, s32 targetPlayerIdx, s32 kind, s32 stackArg9, s32 stackArg10);
extern "C" void fn_802B2728(Actor* param_1)
{
    if (*(s32*)((u8*)param_1 + 0x25c) != 0) {
        DrawRec rec;

        fn_801F06F0(param_1, lbl_8046CA80, *(s32*)((u8*)param_1 + 0x258) + 0x78, (DrawRec*)((u8*)&rec - (u8*)&rec), 1, lbl_805409D8, lbl_805409D8);
        fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), *(u32*)((u8*)param_1 + 4), (u8*)param_1 + 0xc, Color4(0, 0, 0, 0x80), lbl_805409E8);
        fn_803075AC(*(u32*)((u8*)param_1 + 0x198), *(u32*)((u8*)param_1 + 4), (u8*)param_1 + 0xc, *(s32*)((u8*)param_1 + 0x258) + 0x78, 0, 2, -1, 0, 0, 0);
    }
}

extern "C" f32 lbl_80540A0C;
extern "C" f32 lbl_80540A10;
extern "C" f32 lbl_80540A14;
extern "C" f32 lbl_80540A08;
extern "C" f32 lbl_805409DC;
extern "C" f32 lbl_805409E0;
extern "C" f32 lbl_805409F0;
extern "C" f32 lbl_805409F4;
extern "C" f32 lbl_805409C8;
extern "C" void fn_802B2F44(Actor* param_1)
{
    u8* p = (u8*)param_1;
    f32 zero = lbl_805409DC;
    f32 a = lbl_80540A0C;
    f32 b = lbl_80540A10;

    *(f32*)(p + 0x60) = a;
    *(f32*)(p + 0x64) = a;
    *(f32*)(p + 0x68) = b;
    *(f32*)(p + 0x6c) = b;
    *(f32*)(p + 0x80) = a;
    *(f32*)(p + 0x84) = a;
    *(f32*)(p + 0x88) = b;
    *(f32*)(p + 0x8c) = b;
    *(f32*)(p + 0x10) += lbl_80540A14;
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
    *(f32*)(p + 0x278) = zero;
    *(f32*)(p + 0x274) = zero;
    *(f32*)(p + 0x270) = zero;
    *(u8*)(p + 0x27c) = 1;
    if (*(s32*)(p + 0x240) == 1) {
        *(f32*)(p + 0x260) = *(f32*)((u8*)&lbl_805409C8 + (*(s32*)(p + 0x248) << 2));
        *(f32*)(p + 0x264) = lbl_805409D8;
        *(f32*)(p + 0x26c) = lbl_80540A08;
    } else if (*(s32*)(p + 0x240) == 2) {
        *(f32*)(p + 0x60) = a;
        *(f32*)(p + 0x64) = a;
        *(f32*)(p + 0x68) = b;
        *(f32*)(p + 0x6c) = b;
        *(f32*)(p + 0x80) = lbl_805409F0;
        *(f32*)(p + 0x84) = lbl_805409F0;
        *(f32*)(p + 0x88) = lbl_805409F4;
        *(f32*)(p + 0x8c) = lbl_805409F4;
        switch (*(s32*)(p + 0x248)) {
        case 0: {
            Vec v;
            v.y = zero;
            v.x = lbl_805409D8;
            v.z = zero;
            *(Vec*)(p + 0x3c) = v;
            break;
        }
        case 1: {
            Vec v;
            v.y = zero;
            v.x = lbl_805409E0;
            v.z = zero;
            *(Vec*)(p + 0x3c) = v;
            break;
        }
        case 2: {
            Vec v;
            v.y = zero;
            v.x = lbl_805409D8;
            v.z = zero;
            *(Vec*)(p + 0x3c) = v;
            break;
        }
        case 3: {
            Vec v;
            v.y = zero;
            v.x = lbl_805409E0;
            v.z = zero;
            *(Vec*)(p + 0x3c) = v;
            break;
        }
        }
    }
    *(s32*)(p + 0x230) = 0;
}

extern "C" void fn_802B3128(void) {
}

