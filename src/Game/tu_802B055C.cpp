#include "Game/Actor.h"


extern "C" char lbl_804A84C8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" const f32 lbl_805409A0;
extern "C" const f32 lbl_805409A4;
extern "C" const f32 lbl_80540990;
extern "C" void fn_802B0A4C(char* p) {
    *(u32*)(p + 0x248) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    *(u32*)(p + 0x24c) = (*(u32*)(p + 0x90) >> 17) & 0x1f;
    *(u32*)(p + 0x250) = (*(u32*)(p + 0x90) >> 12) & 0x1f;
    *(f32*)(p + 0x60) = lbl_805409A0;
    *(f32*)(p + 0x64) = lbl_805409A0;
    *(f32*)(p + 0x68) = lbl_805409A4;
    *(f32*)(p + 0x6c) = lbl_805409A4;
    *(u32*)(p + 0x234) = 0;
    *(u32*)(p + 0x238) = 0;
    *(u32*)(p + 0x23c) = 0;
    *(u32*)(p + 0x240) = 0;
    *(u32*)(p + 0x244) = 0;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x254) = 0;
    *(f32*)(p + 0x258) = lbl_80540990;
}
