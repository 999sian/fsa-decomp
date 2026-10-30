// TU 0x802e694c-0x802e6ec4 — Actor 'ZOOM' (Camera Zoom Zone Trigger).
#include "Game/esd/types.h"

extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804A9DF8[];

struct ZoomPt { f32 x, y; };
struct ZoomBox { ZoomPt min, max; };

struct ZoomActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ ZoomBox mBounds;
    /* 0x070 */ u8 _pad70[0x90 - 0x70];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x230 - 0x94];
    /* 0x230 */ s32 mState;          // 0 = waiting for player, 1 = starting, 2 = holding zoom, 3 = releasing
    /* 0x234 */ s32 mSoundIndex;     // Unpacked from (spawnParam >> 23) & 3
    /* 0x238 */ s32 mSkipPlayerLock; // Unpacked from (spawnParam >> 22) & 1
    /* 0x23C */ s32 mHoldDuration;   // Unpacked from spawnParam & 0xFFF
    /* 0x240 */ s32 mHoldTimer;
    /* 0x244 */ s32 mWidthTiles;     // ((spawnParam >> 17) & 0x1F) + 1
    /* 0x248 */ s32 mHeightTiles;    // ((spawnParam >> 12) & 0x1F) + 1
};

extern "C" void* fn_802E694C(ZoomActor* this_, short how) {
    if (this_) {
        this_->mVtable = lbl_804A9DF8;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" {
void Zoom_EmptyHook(void) {}
}

struct ZoomTarget {
    u8 pad[0x7f4];
    u8 busy;
    u8 request;
    inline bool tryRequest() {
        bool ok = false;
        if (busy == 0) {
            ok = true;
            request = 1;
        }
        return ok;
    }
};
struct ZoomVT {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
    virtual void notify(s32 a, s32 b);
};
extern char* lbl_8053AB10;
#define ZOOM_TARGET (*(ZoomTarget**)(lbl_8053AB10 + 0x24))
extern const u32 lbl_8046F260[];
extern "C" s32 fn_8023AF14(ZoomBox* box, u32 room, s32 a, f32 f);
extern "C" void fn_801F0D20(void* this_, u32 id);
extern "C" u8 fn_8023077C();
extern "C" u8 fn_80230534(s32 a);
extern "C" void detach__5ActorFv(void* this_);

// ZOOM update (vtable slot 3)
extern "C" void fn_802E69B0(ZoomActor* p) {
    switch (p->mState) {
    case 0: {
        f32 y = p->mPosY;
        f32 x = p->mPosX;
        ZoomBox box;
        box.min.x = p->mBounds.min.x;
        box.min.y = p->mBounds.min.y;
        box.max.x = p->mBounds.max.x;
        box.max.y = p->mBounds.max.y;
        box.min.x += x;
        box.min.y += y;
        box.max.x += x;
        box.max.y += y;
        if (fn_8023AF14(&box, p->mRoomId, 0, 0.0f) >= 0 &&
            ZOOM_TARGET->tryRequest() == true) {
            if (p->mSpawnParam >> 27) {
                ((ZoomVT*)p)->notify(0xff, 1);
            }
            p->mState = 1;
            p->mHoldTimer = p->mHoldDuration;
            if (p->mSoundIndex != 0) {
                fn_801F0D20(p, lbl_8046F260[p->mSoundIndex]);
            }
        }
        break;
    }
    case 1:
        if (p->mSkipPlayerLock == 0) {
            if (fn_8023077C() == 1) {
                p->mState = 2;
                fn_801F0D20(p, 0x3c);
            }
        } else {
            p->mState = 2;
            fn_801F0D20(p, 0x3c);
        }
        break;
    case 2:
        ZOOM_TARGET->tryRequest();
        if (p->mHoldTimer == 0) {
            p->mState = 3;
        } else {
            p->mHoldTimer = p->mHoldTimer - 1;
        }
        break;
    case 3:
        ZOOM_TARGET->tryRequest();
        if (p->mSkipPlayerLock == 0) {
            if (fn_80230534(0) == 1) {
                detach__5ActorFv(p);
            }
        } else {
            detach__5ActorFv(p);
        }
        break;
    }
}

// ZOOM init (vtable slot 1)
extern "C" void fn_802E6BCC(ZoomActor* p) {
    p->mSoundIndex = (p->mSpawnParam >> 23) & 3;
    p->mSkipPlayerLock = (p->mSpawnParam >> 22) & 1;
    p->mHoldDuration = p->mSpawnParam & 0xFFF;
    p->mWidthTiles = ((p->mSpawnParam >> 17) & 0x1f) + 1;
    p->mHeightTiles = ((p->mSpawnParam >> 12) & 0x1f) + 1;
    p->mHoldTimer = 0;
    p->mPosX += 8.0f;
    p->mPosY += 8.0f;
    f32 h = 16.0f * p->mHeightTiles;
    f32 w = 16.0f * p->mWidthTiles;
    p->mBounds.min.x = -w;
    p->mBounds.min.y = -h;
    p->mBounds.max.x = w;
    p->mBounds.max.y = h;
    p->mState = 0;
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
