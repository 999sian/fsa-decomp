#include "Game/Actor.h"


extern void* lbl_804A9078[];
extern const f32 lbl_80540E14;
extern const f32 lbl_80540E18;
extern const f32 lbl_80540E1C;
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_802CCEB0(void* this_, s16 freeFlag) {
    if (this_ != NULL) {
        *(void**)this_ = lbl_804A9078;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_802CCF10(void) {}

extern "C" void fn_802CDA70(Actor* this_) {
    this_->field_60 = lbl_80540E14;
    this_->field_64 = lbl_80540E14;
    this_->field_68 = lbl_80540E18;
    this_->field_6C = lbl_80540E18;
    *(u32*)((u8*)this_ + 0x23C) = 0;
    *(u32*)((u8*)this_ + 0x238) = this_->field_90 & 0x3F;
    if (*(s32*)((u8*)this_ + 0x238) != 2) {
        this_->field_0C.x += lbl_80540E1C;
        this_->field_0C.y += lbl_80540E1C;
    } else {
        this_->field_0C.x += lbl_80540E1C;
    }
    s32 state = *(s32*)((u8*)this_ + 0x238);
    if (state == 0 || state == 3) {
        *(u32*)((u8*)this_ + 0x230) = 0;
    } else if (state == 1) {
        *(u32*)((u8*)this_ + 0x230) = 5;
    } else {
        *(u32*)((u8*)this_ + 0x230) = 8;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
