#include "Game/Actor.h"
#include "Game/ItemBase.h"


extern "C" char __vt__4TUGF[];
extern "C" void dtor_801EB8CC(void*, s32);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80353E70(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = __vt__4TUGF;
        dtor_801EB8CC((char*)param_1 + 0x230, -1);
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern s32 lbl_80472288[];
extern const char lbl_80472298[];
extern f32 lbl_80542750;
extern "C" void fn_80353EE0(void* this_) {
    DrawRec rec;
    rec.b2d = 1;
    rec.b1c = 1;
    rec.b1d = 1;
    rec.w30 = 8;
    fn_801F06F0(this_, lbl_80472298, lbl_80472288[*(s32*)((char*)this_ + 0x2c8)] + 0x466, &rec, 7, lbl_80542750, lbl_80542750);
}

