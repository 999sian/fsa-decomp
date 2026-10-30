// TU 0x802ec1d4-0x802ec73c — Actor 'GEN3' (Table-Driven Multi-Actor Spawner).
#include "Game/esd/types.h"
#include "Game/esd/Actor.h"

extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804AA1D0[];

struct Gen3VT {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual u8 check();
};

struct Gen3Actor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPos[3];
    /* 0x018 */ u8 _pad18[0x90 - 0x18];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x230 - 0x94];
    /* 0x230 */ s32 mState;          // 0 = wait switch, 1 = pre-spawn smoke, 2 = spawn actor, 4 = wait reset
    /* 0x234 */ u32 mTypeIndex;      // Unpacked from spawnParam & 0x7F
    /* 0x238 */ s32 mSpawnInterval;  // Unpacked from (spawnParam >> 7) & 0x1FF
    /* 0x23C */ s32 mTotalCount;     // Unpacked from (spawnParam >> 16) & 0xF
    /* 0x240 */ s32 mRepeatMode;     // Unpacked from (spawnParam >> 20) & 0xF
    /* 0x244 */ s32 mSuppressBgm;    // Unpacked from (spawnParam >> 24) & 1
    /* 0x248 */ s32 mRemainingCount;
    /* 0x24C */ s32 mTimer;
    /* 0x250 */ u32 mTargetFourCC;   // Looked up from lbl_8046F398[mTypeIndex]
};

extern "C" void* fn_802EC1D4(Gen3Actor* this_, short how) {
    if (this_) {
        this_->mVtable = lbl_804AA1D0;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" {
void Gen3_EmptyHook(void) {}
}

extern const u32 lbl_8046F450[];
extern const f32 lbl_805413F0;
extern char* lbl_8053AF80;
extern char* lbl_8053AAF8;
extern "C" void* fn_801F856C();
extern "C" s32 fn_801F78F4(void* reg, u32 fourCC, s32 prev);
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void fn_8013CC50(f32 scale, u32 owner, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80458FF0(void* obj, u32 id, s32 a, s32 b);
extern "C" void fn_801F35AC(void* this_);

// GEN3 update (vtable slot 3)
extern "C" void fn_802EC238(Gen3Actor* p) {
    s32 i;
    s32 id;
    switch (p->mState) {
    case 0:
        if (((Gen3VT*)p)->check()) {
            p->mState = 1;
            p->mTimer = 1;
        }
        break;
    case 1:
        p->mTimer = p->mTimer - 1;
        if (p->mTimer == 0) {
            i = 0;
            if (p->mRepeatMode == 1) {
                id = -1;
                for (; i < 30; i++) {
                    s32 r = fn_801F78F4(fn_801F856C(), p->mTargetFourCC, id);
                    id = r;
                    if (r < 0) {
                        goto spawn;
                    }
                }
                p->mRemainingCount = p->mTotalCount;
                p->mState = 4;
                break;
            }
        spawn:
            i = p->mRoomId;
            if (i >= 8) {
                Actor_CreateByID(fn_801F856C(), 'KMRI', i, p->mPos, 3, -1, -1);
            } else {
                fn_8013CC50(lbl_805413F0, i, p->mPos, 0x35c, 1, 1, 0, 0, 1);
            }
        }
        p->mState = 2;
        p->mTimer = 2;
        break;
    case 2:
        p->mTimer = p->mTimer - 1;
        if (p->mTimer == 0) {
            i = lbl_8046F450[p->mTypeIndex];
            Actor_CreateByID(fn_801F856C(), p->mTargetFourCC, p->mRoomId, p->mPos, i, -1, -1);
            if (*(u32*)(lbl_8053AF80 + 0x58) != 0x1000021 && *(u8*)(lbl_8053AAF8 + 0x7f) == 1 &&
                p->mSuppressBgm == 0) {
                fn_80458FF0(lbl_8053AF80, 0x1000021, 1, 0);
            }
            p->mTimer = p->mSpawnInterval;
            p->mRemainingCount = p->mRemainingCount - 1;
            if (p->mRemainingCount == 0) {
                s32 mode = p->mRepeatMode;
                if (mode == 0) {
                    fn_801F35AC(p);
                } else if (mode == 1) {
                    p->mRemainingCount = p->mTotalCount;
                    p->mState = 4;
                }
            } else {
                p->mState = 1;
            }
        }
        break;
    case 4:
        if (!((Gen3VT*)p)->check()) {
            p->mState = 0;
        }
        break;
    }
}

extern "C" {
extern u32 lbl_8046F398[0x2e];

// GEN3 init (vtable slot 1)
void Gen3_SetParams(Gen3Actor* p) {
    u32 typeIdx = p->mSpawnParam & 0x7f;
    p->mTypeIndex = typeIdx;
    u32 idx = p->mTypeIndex;
    p->mTargetFourCC = lbl_8046F398[idx];
    p->mSpawnInterval = (p->mSpawnParam >> 7) & 0x1ff;
    p->mTotalCount = (p->mSpawnParam >> 16) & 0xf;
    p->mRepeatMode = (p->mSpawnParam >> 20) & 0xf;
    p->mSuppressBgm = (p->mSpawnParam >> 24) & 0x1;
    p->mRemainingCount = p->mTotalCount;
    p->mTimer = 1;
    p->mState = 0;
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
