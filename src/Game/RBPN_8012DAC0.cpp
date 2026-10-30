// RBPN_8012DAC0: .text 0x8012DAC0-0x8012DF70 — Actor 'RBPN' (Periodic Colored Effect Spawner).
#include "types.h"

extern "C" void v01__5ActorFv(void* this_);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, s32 flag);
extern "C" void fn_802A381C(void* mgr, void* pos, u32 room, s32 id);
void operator delete(void* p);
extern void* lbl_8049E848[];
extern u8* lbl_8053AAF8;
extern void* lbl_8053AC98;
extern const u16 lbl_8053CC30[4];
extern const s32 lbl_804650F8[];

class RBPN_Actor {
public:
    virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24();
    virtual void vf28(); virtual void vf2C();
    virtual void vf30(s32, s32);
    virtual u8 vf34();
    virtual void vf38();
    virtual s32 vf3C();

    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPos[3];
    /* 0x018 */ u8 _pad18[0x90 - 0x18];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x230 - 0x94];
    /* 0x230 */ s32 mState;          // 0 = active, 1 = paused by room switch
    /* 0x234 */ s32 mInitialIndex;   // Unpacked from (spawnParam >> 7) & 0x1F
    /* 0x238 */ s32 mTimer;          // Frame counter toward mPeriod
    /* 0x23C */ s32 mPeriod;         // 10 * (spawnParam & 0x7F), default 120
    /* 0x240 */ s32 mCycleIndex;     // 0..3 index into lbl_8053CC30
    /* 0x244 */ s32 mTriggerSwitch;  // Unpacked from (spawnParam >> 22) & 0x1F
};

extern "C" void* fn_8012DAC0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049E848;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

static inline void spawnEffect(u16 id, RBPN_Actor* this_) {
    fn_802A381C(lbl_8053AC98, this_->mPos, this_->mRoomId, id);
}

// RBPN update (vtable slot 3)
extern "C" void fn_8012DB20(RBPN_Actor* this_) {
    switch (this_->mState) {
    case 0: {
        if (this_->vf3C() != 0 && !this_->vf34()) {
            this_->mState = 1;
            break;
        }
        s32 flag = this_->mTriggerSwitch;
        if (flag != 0 && fn_802D800C(fn_802D6A9C(), flag)) {
            this_->mTimer = this_->mPeriod;
        }
        this_->mTimer++;
        if (this_->mTimer >= this_->mPeriod) {
            s32 idx;
            if (lbl_8053AAF8[0x7F] != 0) {
                this_->mCycleIndex--;
                if (this_->mCycleIndex < 0) {
                    this_->mCycleIndex = 3;
                }
                if (lbl_8053AAF8[0x7E] != 0) {
                    idx = lbl_804650F8[this_->mCycleIndex];
                } else {
                    idx = this_->mCycleIndex;
                }
            } else {
                this_->mCycleIndex++;
                if (this_->mCycleIndex >= 4) {
                    this_->mCycleIndex = 0;
                }
                idx = this_->mCycleIndex;
            }
            spawnEffect(lbl_8053CC30[idx], this_);
            this_->mTimer = 0;
        }
        break;
    }
    case 1:
        if (this_->vf3C() == 0) {
            this_->mState = 0;
        } else if (this_->vf34()) {
            this_->mState = 0;
        }
        break;
    case 2:
    default:
        break;
    }
}

// RBPN init (vtable slot 1)
extern "C" void fn_8012DCE8(RBPN_Actor* this_) {
    this_->mPeriod = this_->mSpawnParam & 0x7F;
    this_->mPeriod = this_->mPeriod * 10;
    if (this_->mPeriod <= 0) {
        this_->mPeriod = 120;
    }
    this_->mInitialIndex = (this_->mSpawnParam >> 7) & 0x1F;
    if (this_->mInitialIndex >= 4) {
        this_->mInitialIndex = 0;
    }
    this_->mCycleIndex = this_->mInitialIndex;
    this_->mTriggerSwitch = (this_->mSpawnParam >> 22) & 0x1F;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
