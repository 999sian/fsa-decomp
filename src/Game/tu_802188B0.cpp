// TU 0x802188b0-0x80218cf4 — Bomb ('HBMB') Spawner Component (embedded at +0x540 in SLK2).
#include "types.h"

extern "C" s32 fn_801CD664(s32 range);

extern "C" {
extern f32 lbl_8053EDF0;
u16* fn_801C0D70();
u8 fn_801C5348(void* actor, f32 range);
void* fn_801F856C();
void* Actor_CreateByID(void* mgr, u32 id, u32 owner, void* pos, s32 a, s32 b, s32 c);
s32 fn_801F7818(void* mgr, u32 id, u32 owner, void** out, s32 max);
}

struct Slk2HostActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x94 - 0x18];
    /* 0x094 */ u16 mSubType;
    /* 0x096 */ u8 _pad96[0x11C - 0x96];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x238 - 0x11D];
    /* 0x238 */ s32 mBombPhase;
    /* 0x23C */ u8 _pad23C[0x248 - 0x23C];
    /* 0x248 */ s32 mActionState;
    /* 0x24C */ u8 _pad24C[0x254 - 0x24C];
    /* 0x254 */ f32 mAnimProgress;
    /* 0x258 */ u8 _pad258[0x564 - 0x258];
    /* 0x564 */ s32 mBossPhase;
};

struct HbmbSpawner {
    /* 0x00 */ Slk2HostActor* mActor;
    /* 0x04 */ u16 mTimer;
};

extern "C" void fn_802188B0(HbmbSpawner* s) {
    if (!(*fn_801C0D70() & 0x400)) {
        Slk2HostActor* a = s->mActor;
        if (a->mBossPhase != 3) {
            if (s->mTimer > 1) {
                s->mTimer--;
            } else if (a->mPosZ <= 0.0f && a->mAnimProgress >= lbl_8053EDF0 - 0.001f) {
                if (!fn_801C5348(a, 64.0f)) {
                    a = s->mActor;
                    switch (a->mActionState) {
                    case 0x11:
                    case 0x1b:
                        Actor_CreateByID(fn_801F856C(), 'HBMB', a->mRoomId, &a->mPosX, 10, -1, -1);
                        s->mTimer = fn_801CD664(0x79) + 0xf0;
                        break;
                    }
                }
            }
        }
    }
}

extern "C" bool fn_802189AC(HbmbSpawner* s) {
    bool found = false;
    void* list[0x400];
    s32 n = fn_801F7818(fn_801F856C(), 'HBMB', s->mActor->mRoomId, list, -1);
    for (s32 i = 0; i < n; i++) {
        Slk2HostActor* h = (Slk2HostActor*)list[i];
        if (h != NULL && h->mActiveFlag != 0 && h->mSubType != 1 && h->mBombPhase < 5) {
            f32 dx = h->mPosX - s->mActor->mPosX;
            f32 dz = h->mPosY - s->mActor->mPosY;
            f32 dx2 = dx * dx;
            f32 dz2 = dz * dz;
            if (dx2 + dz2 <= 1024.0f) {
                found = true;
                break;
            }
        }
    }
    return found;
}

extern "C" void* fn_80218A8C(HbmbSpawner* this_) {
    this_->mActor = 0;
    s32 r = fn_801CD664(0x79);
    this_->mTimer = (u16)(r + 0x3c);
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
