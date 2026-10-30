// TU 0x802e7634-0x802e794c — Actor 'SEN2' (Delayed Event/Sound Trigger).
#include "Game/esd/types.h"
#include "Game/esd/Actor.h"

extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804A9F00[];

struct Sen2Actor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u8 _pad04[0x90 - 0x04];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x230 - 0x11D];
    /* 0x230 */ s32 mSilentFlag; // Unpacked from (spawnParam >> 26) & 1
    /* 0x234 */ s32 mTableIndex; // Unpacked from spawnParam & 0xFF
    /* 0x238 */ s32 mDelayTimer; // Unpacked from (spawnParam >> 8) & 0xFFF
};

extern "C" void* fn_802E7634(Sen2Actor* this_, short how) {
    if (this_) {
        this_->mVtable = lbl_804A9F00;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" {
void Pnp2_EmptyHook(void) {}
}

extern "C" void fn_801F0D20(void* this_, u32 id);
extern const u32 lbl_80541250[2];

// SEN2 update (vtable slot 3)
extern "C" void fn_802E7698(Sen2Actor* this_) {
    s32 t = this_->mDelayTimer;
    if (t == 0) {
        if (this_->mSilentFlag == 0) {
            fn_801F0D20(this_, lbl_80541250[this_->mTableIndex]);
        }
        this_->mActiveFlag = 0;
    } else {
        this_->mDelayTimer = t - 1;
    }
}

// SEN2 init (vtable slot 1)
extern "C" {
void Pnp2_SetParams(Sen2Actor* thisPtr) {
    u32 v1 = thisPtr->mSpawnParam;
    thisPtr->mSilentFlag = (v1 >> 26) & 0x1;
    u32 v2 = thisPtr->mSpawnParam;
    thisPtr->mTableIndex = v2 & 0xFF;
    u32 v3 = thisPtr->mSpawnParam;
    thisPtr->mDelayTimer = (v3 >> 8) & 0xFFF;
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
