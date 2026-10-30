// TU 0x802f3b74-0x802f3f7c — Actor 'DMYK' (Spawns 'PEFF' Portal/Effect and Registers Callback).
#include "Game/esd/types.h"

extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804AA6A0[];

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
#ifndef unknown
#define unknown jsys_unknown
#endif
#include "JSystem/JGeometry/Vec.h"

struct DmykActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3<f32> mPos;
    /* 0x018 */ u8 _pad18[0x90 - 0x18];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x230 - 0x11D];
    /* 0x230 */ s32 mEventId;      // Unpacked from spawnParam & 0xFFF
    /* 0x234 */ s32 mNibbleA;      // Unpacked from (spawnParam >> 12) & 0xF
    /* 0x238 */ s32 mNibbleB;      // Unpacked from (spawnParam >> 16) & 0xF
    /* 0x23C */ s32 mPeffHandle;   // Spawned 'PEFF' actor handle (-1 = none)
};

extern "C" void* fn_802F3B74(DmykActor* this_, short how) {
    if (this_) {
        this_->mVtable = lbl_804AA6A0;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" {
void Dmyk_EmptyHook(void) {}
}

extern "C" u8 fn_80388EEC(void* handle);

struct ActorSlot9 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void slot9();
};

// DMYK update (vtable slot 3)
extern "C" void fn_802F3BD8(DmykActor* this_) {
    void* handle = (void*)this_->mNibbleB;
    if ((u8)fn_80388EEC(handle) != 0) {
        ((ActorSlot9*)this_)->slot9();
    }
}

extern "C" void* fn_801F856C();
extern "C" DmykActor* fn_801F666C(void* base, s32 id);

extern "C" void fn_802F3C24(DmykActor* p) {
    s32 id = p->mPeffHandle;
    if (id >= 0) {
        void* base = fn_801F856C();
        DmykActor* found = fn_801F666C(base, id);
        if (found != 0) {
            found->mActiveFlag = 0;
        }
        p->mPeffHandle = -1;
    }
    p->mActiveFlag = 0;
}

extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void fn_8038BD08(s32 a, s32 b, u32 owner, JGeometry::TVec3<f32>* pos, s32 kind);

// DMYK init (vtable slot 1)
extern "C" void fn_802F3C8C(DmykActor* p) {
    p->mEventId = p->mSpawnParam & 0xFFF;
    p->mNibbleA = (p->mSpawnParam >> 12) & 0xF;
    p->mNibbleB = (p->mSpawnParam >> 16) & 0xF;
    p->mPeffHandle = -1;
    s32 a = p->mNibbleA;
    if (a == p->mNibbleB) {
        p->mPeffHandle = Actor_CreateByID(fn_801F856C(), 'PEFF', p->mRoomId, &p->mPos,
                                          (a & 3) | 0x24, -1, -1);
        u32 owner = p->mRoomId;
        JGeometry::TVec3<f32> pos(p->mPos);
        fn_8038BD08(p->mNibbleB, p->mEventId, owner, &pos, 0x21);
    } else {
        p->mActiveFlag = 0;
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
#ifndef unknown
#define unknown jsys_unknown
#endif
#include "JSystem/JAudio/JASFakeMatchFSA.h"
