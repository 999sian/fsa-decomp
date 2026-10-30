// TU 0x802ef448-0x802ef76c — Actor 'EMSK' (500-Frame Countdown Warp Trigger, misdecoded as ELSK).
#include "Game/esd/types.h"
#include "Game/esd/Actor.h"

extern "C" void __dt__5ActorFv(void* this_, int how);
void operator delete(void* p);
extern void* lbl_804AA498[];

struct EmskActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u8 _pad04[0x90 - 0x04];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x230 - 0x94];
    /* 0x230 */ s32 mTableIndex; // Unpacked from spawnParam & 0x7F
    /* 0x234 */ s32 mCountdown;  // Initialized to 500 (0x1F4)
};

extern "C" void* fn_802EF448(EmskActor* this_, short how) {
    if (this_) {
        this_->mVtable = lbl_804AA498;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" {
void Emsk_EmptyHook(void) {}
}

struct ElskPair { u32 a; u32 b; };
extern const ElskPair lbl_8046F610[3];
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D9FF4(void* rec, u32 a, u32 b);
extern "C" void fn_80136798(void* obj, int id, int arg);
extern void* lbl_8053AAF8[2];

static inline void elskNotify(u32 a, s32 i) {
    fn_802D9FF4(fn_802D6A9C(), a, lbl_8046F610[i].b);
}

// EMSK update (vtable slot 3)
extern "C" void fn_802EF4AC(EmskActor* this_) {
    this_->mCountdown = this_->mCountdown - 1;
    if (this_->mCountdown == 0) {
        s32 i = this_->mTableIndex;
        elskNotify(lbl_8046F610[i].a, i);
        fn_80136798(lbl_8053AAF8[0], 0xf, 0);
    }
}

// EMSK init (vtable slot 1)
extern "C" {
void Emsk_SetParams(EmskActor* thisPtr) {
    u32 v = thisPtr->mSpawnParam;
    thisPtr->mTableIndex = v & 0x7F;
    thisPtr->mCountdown = 0x1f4;
}
}

#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
