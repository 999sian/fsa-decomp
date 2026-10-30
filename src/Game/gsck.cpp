// TU 0x802f4aec-0x802f5040 — Actor 'GSCK' (3-Switch Synchronized Countdown Gate).
#include "Game/esd/types.h"

extern "C" void __dt__5ActorFv(void* this_, int how);
void operator delete(void* p);
extern void* lbl_804AA800[];

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
typedef JGeometry::TVec3<f32> GsckVec;

struct GsckActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u8 _pad04[0x90 - 0x04];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x230 - 0x94];
    /* 0x230 */ s32 mState;       // 0 = waiting for 3 switches, 1 = locking, 2 = counting 1..13, 3 = finishing
    /* 0x234 */ s32 mCountStep;   // 0..13 (displayed as 0xDB + mCountStep above players)
    /* 0x238 */ s32 mStepTimer;
};

extern "C" void* fn_802F4AEC(GsckActor* this_, short how) {
    if (this_) {
        this_->mVtable = lbl_804AA800;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" {
void Gsck_EmptyHook(void) {}
}

extern char* lbl_8053AB10;
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D7F40(void* rec, u32 sw);
extern "C" void fn_802D7F84(void* rec, u32 sw, s32 on);
extern "C" u8 fn_8023077C();
extern "C" GsckVec* fn_8023E724(s32 player);
extern "C" void fn_8030C210(void* obj, GsckVec pos);
extern "C" void fn_80230498(s32 player, GsckVec pos, s32 id, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_80230FD0(s32 player, s32 id);
extern "C" u8 fn_80230534(s32 a);
extern "C" void fn_801F0D20(void* this_, s32 id);
extern "C" void detach__5ActorFv(void* this_);

// GSCK update (vtable slot 3)
extern "C" void fn_802F4B50(GsckActor* p) {
    s32 i;
    u32 swDone;
    u32 params;
    u32 sw2;
    u32 sw3;
    params = p->mSpawnParam;
    swDone = (params >> 7) & 0x1f;
    switch (p->mState) {
    case 0: {
        sw2 = (params >> 17) & 0x1f;
        sw3 = (params >> 12) & 0x1f;
        if (fn_802D7F40(fn_802D6A9C(), (params >> 22) & 0x1f) &&
            fn_802D7F40(fn_802D6A9C(), sw2) &&
            fn_802D7F40(fn_802D6A9C(), sw3)) {
            if (!fn_802D7F40(fn_802D6A9C(), swDone)) {
                if (fn_8023077C()) {
                    p->mState = 2;
                    p->mCountStep = 0;
                    p->mStepTimer = 30;
                } else {
                    p->mState = 1;
                }
            } else {
                detach__5ActorFv(p);
            }
        }
        break;
    }
    case 1:
        if (fn_8023077C()) {
            p->mState = 2;
            p->mCountStep = 0;
            p->mStepTimer = 30;
        }
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), *fn_8023E724(i));
        }
        p->mStepTimer = p->mStepTimer - 1;
        if (p->mStepTimer == 0) {
            p->mCountStep = p->mCountStep + 1;
            for (i = 0; i < 4; i++) {
                fn_80230498(i, *fn_8023E724(i), p->mCountStep + 0xdb, 0xff, -0x80, -0x80, 1);
                if (p->mCountStep == 1) {
                    fn_80230FD0(i, 0x10001);
                }
            }
            p->mStepTimer = 2;
            if (p->mCountStep == 13) {
                p->mState = 3;
                p->mStepTimer = 10;
            }
        }
        break;
    case 3:
        for (i = 0; i < 4; i++) {
            fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), *fn_8023E724(i));
        }
        if (p->mStepTimer == 0) {
            if (fn_80230534(0)) {
                fn_802D7F84(fn_802D6A9C(), swDone, 1);
                fn_801F0D20(p, 3);
                detach__5ActorFv(p);
            }
        } else {
            p->mStepTimer = p->mStepTimer - 1;
        }
        break;
    }
}

struct ActorSlot5 {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void slot5();
};

// GSCK init (vtable slot 1)
extern "C" void fn_802F4DE8(GsckActor* this_) {
    this_->mState = 0;
    ((ActorSlot5*)this_)->slot5();
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
