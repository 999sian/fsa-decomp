#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"


extern "C" char lbl_804AE574[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80373138(Actor* this_, s16 del) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AE574;
        __dt__5ActorFv(this_, 0);
        if (del > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" char lbl_804AE560[];
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" void fn_802F745C(u8*, u8*, u32, s32);
extern "C" void fn_80373434(u8* this_) {
    u8* obj = *(u8**)(lbl_8053AAF8 + 0xa4);
    u32 r = ((u32 (**)(u8*, u32, u32))(*(u32*)obj))[6](obj, 0x54494d47, ((u32*)lbl_804AE560)[*(s32*)(this_ + 0x23c)]);
    if (*(s32*)(this_ + 4) < 8) {
        fn_802F745C(*(u8**)(lbl_8053AB10 + 0x20), this_ + 0xc, r, 0);
    }
}

extern "C" f32 lbl_80542E50;
extern "C" f32 lbl_80542E58;
extern "C" f32 lbl_80542E5C;
extern "C" f32 lbl_80542E60;
extern "C" f32 lbl_80542E64;
extern "C" f32 lbl_80542E6C;
extern "C" f32 lbl_80542E84;
extern "C" void fn_803738DC(Actor* this_) {
    u8* p = (u8*)this_;
    this_->field_60 = lbl_80542E58;
    this_->field_64 = lbl_80542E5C;
    this_->field_68 = lbl_80542E60;
    this_->field_6C = lbl_80542E64;
    this_->field_70.x = lbl_80542E58;
    this_->field_70.y = lbl_80542E5C;
    this_->field_70.z = lbl_80542E60;
    this_->field_7C.x = lbl_80542E84;
    this_->field_7C.y = lbl_80542E50;
    this_->field_7C.z = lbl_80542E50;
    this_->field_88 = lbl_80542E50;
    this_->field_8C = lbl_80542E50;
    this_->field_108 = 0;
    *(s32*)(p + 0x23c) = 0;
    *(u8*)(p + 0x240) = *(u8*)(p + 0x254) = this_->v11();
    if (*(u8*)(p + 0x240)) {
        *(f32*)(p + 0x244) = lbl_80542E6C;
    } else {
        *(f32*)(p + 0x244) = lbl_80542E50;
    }
    this_->field_3C.x = lbl_80542E50;
    this_->field_3C.y = lbl_80542E50;
    this_->field_3C.z = lbl_80542E50;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = -1;
    *(s32*)(p + 0x250) = 0;
}

extern "C" void fn_803739B4(void) {
}
