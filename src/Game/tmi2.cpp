// TU 0x80376850-0x80376b4c — Actor 'TMI2' (Tile-Triggered 'BCK2' Spawner).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern void* lbl_804AE728[];

struct Tmi2Actor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPos[3];
    /* 0x018 */ u8 _pad18[0x11C - 0x18];
    /* 0x11C */ u8 mActiveFlag;
};

extern "C" void* fn_80376850(Tmi2Actor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804AE728;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" u16 fn_80226850(void* pos, u32 id);
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* mgr, u32 type, u32 id, void* pos, u32 flags, s32 a, s32 b);

// TMI2 update (vtable slot 3): spawns 'BCK2' when tile at mPos becomes 0x12
extern "C" void fn_803768B0(Tmi2Actor* this_) {
    if (fn_80226850(this_->mPos, this_->mRoomId) == 0x12) {
        Actor_CreateByID(fn_801F856C(), 'BCK2', this_->mRoomId, this_->mPos, 0x100, -1, -1);
        this_->mActiveFlag = 0;
    }
}

// TMI2 init (vtable slot 1)
extern "C" void fn_8037691C(Tmi2Actor* this_) {
    this_->mActiveFlag = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
