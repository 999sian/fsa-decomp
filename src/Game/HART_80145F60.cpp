#include "types.h"
#include "Game/Actor.h"

extern "C" const f32 lbl_8053D050;
extern "C" const f32 lbl_8053D060;
extern "C" const f32 lbl_8053D064;
extern "C" const f32 lbl_8053D068;
extern "C" const f32 lbl_8053D06C;
extern "C" const f32 lbl_8053D070;
extern "C" const f32 lbl_8053D074;
extern "C" s32 fn_802D6A9C(void);
extern "C" char lbl_8049F4F0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80145F60(Actor* this_, s16 n) {
    if (this_ != nullptr) {
        *(void**)this_ = lbl_8049F4F0;
        __dt__5ActorFv(this_, 0);
        if (n > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_80146890(void* this_) {
    f32 val = lbl_8053D050;
    *(f32*)((u8*)this_ + 0x44) = val;
    *(f32*)((u8*)this_ + 0x40) = val;
    *(f32*)((u8*)this_ + 0x3c) = val;
    *(u32*)((u8*)this_ + 0x230) = 4;
}
