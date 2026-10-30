// TU 0x802AC58C-0x802AC8AC — Player Spawn / Formation Placement Helper Actor.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

struct SpawnPlacementActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u8 _pad04[0x0C - 0x04];
    /* 0x00C */ f32 mPos[3];
    /* 0x018 */ u8 _pad18[0x90 - 0x18];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x234 - 0x11D];
    /* 0x234 */ u32 mFormationMode; // Unpacked from (spawnParam >> 8) & 0xF
};

extern void* lbl_804A8338[];
extern "C" void* fn_802AC58C(SpawnPlacementActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A8338;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802AC5EC(void) {}
extern "C" void fn_802AC5F0(void) {}

extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_8023F1D4(int idx, void* pos, int a, int b, u8 c);
static const s32 lbl_8046C890[4] = {2, 3, 0, 1};

extern "C" void fn_802AC5F4(SpawnPlacementActor* this_) {
    this_->mFormationMode = (this_->mSpawnParam >> 8) & 0xf;
    if (fn_802D6A9C()[0x131f6] == 0 || fn_802D6A9C()[0x131f9] == 2) {
        this_->mFormationMode = 0;
    }
    u32 params = this_->mSpawnParam;
    fn_8023F1D4(params & 0xf, this_->mPos, lbl_8046C890[(params >> 4) & 3],
                this_->mFormationMode, (params >> 12) & 1);
    this_->mActiveFlag = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D15D4[0x94];
