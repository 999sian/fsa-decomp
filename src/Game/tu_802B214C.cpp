#include "Game/Actor.h"
#include "Game/ItemBase.h"

struct Color4 {
    Color4(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
    u8 r, g, b, a;
};


extern "C" char lbl_804A8588[];
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
        fn_801F06F0(param_1, lbl_8046CA80, *(s32*)((u8*)param_1 + 0x258) + 0x78, NULL, 1, lbl_805409D8, lbl_805409D8);
        fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), *(u32*)((u8*)param_1 + 4), (u8*)param_1 + 0xc, Color4(0, 0, 0, 0x80), lbl_805409E8);
        fn_803075AC(*(u32*)((u8*)param_1 + 0x198), *(u32*)((u8*)param_1 + 4), (u8*)param_1 + 0xc, *(s32*)((u8*)param_1 + 0x258) + 0x78, 0, 2, -1, 0, 0, 0);
    }
}

