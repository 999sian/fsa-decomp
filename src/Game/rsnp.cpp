// TU 0x80354a44-0x80354d64 — Actor 'RSNP' (50-Frame Transient GBA Effect 0x3CD).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern void* lbl_804ACD18[];

struct RsnpActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x198 - 0x18];
    /* 0x198 */ u32 mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mLifeTimer;
};

extern "C" void* fn_80354A44(RsnpActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804ACD18;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_803075AC(u32 a, u32 id, void* pos, u32 type, u32 p5, u32 p6, s32 p7, u32 p8, u32 p9, u32 p10);
extern "C" void detach__5ActorFv(void* actor);

// RSNP draw (vtable slot 6)
extern "C" void fn_80354AA4(RsnpActor* p) {
    fn_803075AC(p->mRoomHandle, p->mRoomId, &p->mPosX, 0x3cd, 0, 2, -1, 0, 0, 0);
}

// RSNP update (vtable slot 3): detaches after 50 frames
extern "C" void fn_80354AF4(RsnpActor* p) {
    if (p->mLifeTimer >= 50) {
        detach__5ActorFv(p);
    } else {
        p->mLifeTimer = p->mLifeTimer + 1;
    }
}

// RSNP init (vtable slot 1)
extern "C" void fn_80354B2C(RsnpActor* p) {
    p->mLifeTimer = 0;
    p->mPosZ = 0.0f;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
