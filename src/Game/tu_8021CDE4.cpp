// TU 0x8021cde4-0x8021d26c — SLK2 Boss Rail-State Transition & Hop Budget Helpers.
#include "types.h"
#include "JSystem/JGeometry.h"

struct Vec_8021CDE4 {
    Vec_8021CDE4() {}
    Vec_8021CDE4(f32 x_, f32 y_, f32 z_) { x = x_; y = y_; z = z_; }
    Vec_8021CDE4& operator=(const Vec_8021CDE4& o) { x = o.x; y = o.y; z = o.z; return *this; }
    f32 x, y, z;
};

struct StateInfo_8021CDE4 {
    u16 mDuration;
    u16 pad[4];
};

struct Slk2RailActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ Vec_8021CDE4 mPos;
    /* 0x018 */ u8 _pad18[0x90 - 0x18];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x108 - 0x94];
    /* 0x108 */ s32 mRemainingBudget;
    /* 0x10C */ u8 _pad10C[0x244 - 0x10C];
    /* 0x244 */ s32 mMaxBudget;
    /* 0x248 */ s32 mAnimId;
    /* 0x24C */ u8 _pad24C[0x32C - 0x24C];
    /* 0x32C */ Vec_8021CDE4 mRailTargetPos;
    /* 0x338 */ u8 _pad338[0x358 - 0x338];
    /* 0x358 */ u8 mRailSlots[0x20C];
    /* 0x564 */ s32 mRailState;
    /* 0x568 */ s32 mStateDuration;
    /* 0x56C */ u32 mSavedRoomId;
    /* 0x570 */ Vec_8021CDE4 mSavedPos;
    /* 0x57C */ s32 mRailStepCount;
    /* 0x580 */ Vec_8021CDE4 mGoalPos;
    /* 0x58C */ s32 mGoalMode;
    /* 0x590 */ u8 _pad590[0x59E - 0x590];
    /* 0x59E */ u16 mStunTimer;
};

extern "C" {
extern const StateInfo_8021CDE4 lbl_8046A748[];
u8 fn_801CD2F8(u32 id);
void fn_801CD150(const Vec_8021CDE4& src, void* dst);
void fn_801CD0D0(void* src, void* dst);
void fn_801C3B7C(void* actor, s32 anim);
void fn_8021425C(void* slots, u8 idx, u32 a, const JGeometry::TVec3<f32>& v, u32 b);
void SetCurrentSlotIndex(void* slots, u8 idx);
void* GetCurrentSlotPtr(void* slots);
Vec_8021CDE4 fn_800FE294(void* slot, s32 alpha);

inline void SetTarget_8021CDE4(Slk2RailActor* p) {
    fn_801CD150(Vec_8021CDE4(p->mSavedPos.x, 24.0f + p->mSavedPos.y, 0.0f), &p->mGoalPos);
}

void fn_8021CDE4(void* this_, s32 state) {
    Slk2RailActor* p = (Slk2RailActor*)this_;
    p->mRemainingBudget = p->mMaxBudget;
    p->mStateDuration = lbl_8046A748[state].mDuration;
    switch (state) {
    case 1: {
        if (fn_801CD2F8(p->mRoomId)) {
            p->mGoalMode = 2;
            SetTarget_8021CDE4(p);
        } else {
            p->mGoalMode = 0;
            fn_801CD150(p->mPos, &p->mGoalPos);
        }
        p->mRailStepCount = 8;
        p->mSavedRoomId = p->mRoomId;
        p->mSavedPos.x = p->mPos.x;
        p->mSavedPos.y = p->mPos.y;
        p->mSavedPos.z = p->mPos.z;
        fn_8021425C(p->mRailSlots, 1, (p->mSpawnParam >> 12) & 0xf, *(JGeometry::TVec3<f32>*)&p->mGoalPos, p->mRailStepCount);
        SetCurrentSlotIndex(p->mRailSlots, 1);
        p->mRailTargetPos = fn_800FE294(GetCurrentSlotPtr(p->mRailSlots), 0xff);
        fn_801C3B7C(this_, 0x19);
        break;
    }
    case 2: {
        s32 cur = p->mRailState;
        if (cur == 0) {
            fn_801C3B7C(this_, 0x2b);
        } else if (cur == 1) {
            p->mGoalMode = 1;
            p->mRailStepCount = 0;
            fn_801CD0D0(&p->mPos, &p->mGoalPos);
            p->mSavedRoomId = p->mRoomId;
            p->mSavedPos.x = p->mPos.x;
            p->mSavedPos.y = p->mPos.y;
            p->mSavedPos.z = p->mPos.z;
            SetCurrentSlotIndex(p->mRailSlots, 0);
            fn_801C3B7C(this_, 0x1a);
        } else if (cur == 3) {
            p->mStateDuration = 1;
            if (p->mAnimId != 0x2a) {
                fn_801C3B7C(this_, 0x1b);
            }
        }
        break;
    }
    case 3:
        p->mStunTimer = 600;
        fn_801C3B7C(this_, 0x2e);
        break;
    }
    p->mRailState = state;
}

s32 fn_8021CFF8(Slk2RailActor* thisObj) {
    s32 result = 0;
    if (thisObj->mRailState == 3 && thisObj->mStunTimer == 0) {
        result = 1;
    }
    return result;
}

s32 fn_8021D020(Slk2RailActor* thisObj) {
    s32 result = 0;
    s32 countdown = thisObj->mMaxBudget - thisObj->mStateDuration;
    if (thisObj->mRemainingBudget <= countdown) {
        result = 1;
    }
    return result;
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
