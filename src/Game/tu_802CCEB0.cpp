#include "JSystem/JAudio/JASFakeMatchFSA.h"

#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "std/math.h"
#include "JSystem/JGeometry/Vec.h"

extern void* lbl_8053AC98;
extern "C" s32 fn_8023AF14(f32* box, s32 room, f32 r, s32 flag);
extern "C" s32 fn_8023B8E4(f32* box, s32 room, f32* pos, s32 flag);
extern "C" u8 fn_8023A51C(s32 i);
extern "C" u8 fn_8023AAF8(s32 i, f32* box, s32 room, void* out);
extern "C" f32* fn_8023E724(s32 i);
extern "C" void fn_802A381C(void* mgr, void* pos, s32 room, s32 id);
extern "C" void fn_802A3948(void* mgr, void* pos, s32 a, s32 room, s32 id);
extern "C" void fn_801F0E34(void* actor, u32 id, s32 a);
extern "C" u8* fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u32 fn_80226850(void* pos, s32 room);
extern "C" u32 fn_80226998(void* pos, s32 room);
extern "C" u8 fn_80235448(s32 i);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 fourcc, s32 room, void* pos, u32 param, s32 a, s32 b);


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

void fn_802CDB18(void) {}

