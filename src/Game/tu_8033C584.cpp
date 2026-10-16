#include "Game/Actor.h"
#include "Game/ItemBase.h"


extern "C" char lbl_804AC250[];
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" f32 lbl_80542178;
extern "C" f32 lbl_8054218C;
extern "C" f32 lbl_80542190;
extern "C" f32 lbl_80542194;
extern "C" f32 lbl_80542198;
extern "C" void* fn_8013CC50(u32, void*, s32, s32, s32, s32, s32, s32, f32);
extern "C" char lbl_80471E10[];
extern "C" void fn_801F06F0(void* this_, void* p, s32 n, void* ids, s32 flag, f32 fa, f32 fb);
extern "C" void fn_803075AC(void* a, void* b, void* c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern "C" void fn_8033C584(u8* this_) {
    DrawRec rec;
    if (*(s32*)(this_ + 0x238) < 0x3c) {
        u32 sign = *(u32*)(this_ + 0x234) >> 31;
        if (((*(u32*)(this_ + 0x234) & 1) ^ sign) - sign != 0) {
            return;
        }
    }
    rec.b2d = 1;
    fn_801F06F0(this_, lbl_80471E10, *(s32*)(this_ + 0x23c) + 0x5e, rec.ids, 1, lbl_80542178, lbl_80542178);
    fn_803075AC(*(void**)(this_ + 0x198), *(void**)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x23c) + 0x5e, 0, 2, -1, 0, 0, 0);
}

extern "C" void fn_8033C968(u8* this_) {
    f32 zero = lbl_80542190;
    f32 f3 = lbl_8054218C;
    f32 f2 = lbl_80542194;
    f32 f0 = lbl_80542198;

    *(u32*)(this_ + 0x240) = *(u32*)(this_ + 0x90) & 3;
    *(u32*)(this_ + 0x108) = 8;
    *(u32*)(this_ + 0x23c) = 0;
    *(f32*)(this_ + 0x248) = zero;
    *(f32*)(this_ + 0x24c) = zero;
    *(f32*)(this_ + 0x250) = zero;
    *(f32*)(this_ + 0x3c) = zero;
    *(f32*)(this_ + 0x40) = zero;
    *(f32*)(this_ + 0x44) = zero;
    *(f32*)(this_ + 0x3c) = f3;
    *(f32*)(this_ + 0x250) = f2;
    *(f32*)(this_ + 0x40) = f0;
    *(u32*)(this_ + 0x234) = 0;
    *(u32*)(this_ + 0x238) = 0xb4;
    *(u16*)(this_ + 0x244) = 0;
    *(u32*)(this_ + 0x230) = 0;
    *(void**)(this_ + 0x254) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x183, 0, 0, 0, 0, 1, lbl_80542178);
    *(void**)(this_ + 0x258) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x184, 0, 0, 0, 0, 1, lbl_80542178);
}

extern "C" Actor* fn_8033CA4C(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804AC250;
        fn_801EE434(*(void**)((u8*)param_1 + 0x254));
        fn_801EE434(*(void**)((u8*)param_1 + 0x258));
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}
