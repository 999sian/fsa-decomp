#include "types.h"
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

