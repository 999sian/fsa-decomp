#include "Game/Actor.h"
#include "Game/ItemBase.h"
#include "Game/SinitPoolChain.h"

struct Color4 {
    Color4(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
    u8 r, g, b, a;
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
        DrawRec* recp = &rec;

        fn_801F06F0(param_1, lbl_8046CA80, *(s32*)((u8*)param_1 + 0x258) + 0x78, NULL, 1, lbl_805409D8, lbl_805409D8);
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
extern "C" f32 lbl_805409C8[];
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
    if (*(s32*)(p + 0x240) != 0) {
        *(s32*)(p + 0x25c) = 1;
    } else {
        *(s32*)(p + 0x25c) = 0;
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
        case 0: {
            Vec v;
            v.y = 0.0f;
            v.x = 1.0f;
            v.z = 0.0f;
            *(Vec*)(p + 0x3c) = v;
            break;
        }
        case 1: {
            Vec v;
            v.y = 0.0f;
            v.x = -1.0f;
            v.z = 0.0f;
            *(Vec*)(p + 0x3c) = v;
            break;
        }
        case 2: {
            Vec v;
            v.y = 0.0f;
            v.x = 1.0f;
            v.z = 0.0f;
            *(Vec*)(p + 0x3c) = v;
            break;
        }
        case 3: {
            Vec v;
            v.y = 0.0f;
            v.x = -1.0f;
            v.z = 0.0f;
            *(Vec*)(p + 0x3c) = v;
            break;
        }
        }
    }
    *(s32*)(p + 0x230) = 0;
}

extern "C" void fn_802B3128(void) {
}

