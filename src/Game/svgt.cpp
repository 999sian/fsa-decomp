// TU 0x803524c8-0x8035280c — Actor 'SVGT' (Dual Particle Emitter Prop).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern "C" void fn_801EE434(u32 handle);
extern "C" u32 fn_8013CC50(u32 id, void* pos, u32 type, s32 p4, u32 p5, u32 p6, u32 p7, u32 p8, f32 f);

struct SvgtActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPos[3];
    /* 0x018 */ u8 _pad18[0x234 - 0x18];
    /* 0x234 */ u32 mEmitterA; // Particle 0x447
    /* 0x238 */ u32 mEmitterB; // Particle 0x448
};

extern "C" void fn_803524C8(void) {}
extern "C" void fn_803524CC(void) {}

// SVGT init (vtable slot 1)
extern "C" void fn_803524D0(SvgtActor* p) {
    p->mEmitterA = 0;
    p->mEmitterB = 0;
    if (p->mEmitterA == 0) {
        p->mEmitterA = fn_8013CC50(p->mRoomId, p->mPos, 0x447, -1, 0, 0, 0, 1, 1.0f);
    }
    if (p->mEmitterB == 0) {
        p->mEmitterB = fn_8013CC50(p->mRoomId, p->mPos, 0x448, -1, 0, 0, 0, 1, 1.0f);
    }
}

extern void* lbl_804ACB98[];

extern "C" void* fn_80352574(SvgtActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804ACB98;
        fn_801EE434(this_->mEmitterA);
        fn_801EE434(this_->mEmitterB);
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
