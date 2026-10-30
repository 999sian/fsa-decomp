// Game TU 801DCC98-801DD1AC — Actor 'BOIB' (Boss Ice/Energy Ball Projectile).
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A5038[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_801D0F40(void* this_);

extern "C" void fn_8013CB44(void* h, JGeometry::TVec3<f32>* pos, u32 a, u32 b, u32 c);
extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_801F2B7C(void* this_, u32 a, s32 b, u32 c);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void* fn_8013CC50(u32 id, JGeometry::TVec3<f32>* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern const f32 lbl_8053F378;
extern const f32 lbl_8053F37C;
extern const f32 lbl_8053F380;
extern const f32 lbl_8053F384;

struct BoibSub270 {
    u8 _pad00[0x24];
    void* mVtable; // +0x294 on BoibActor
    u8 _pad28[0x10];
};

struct BoibActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3<f32> mPos;
    /* 0x018 */ u8 _pad18[0x3C - 0x18];
    /* 0x03C */ JGeometry::TVec3<f32> mVel;
    /* 0x048 */ u8 _pad48[0x60 - 0x48];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ f32 mBounds70[4];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u8 _pad90[8];
    /* 0x098 */ u32 mField98;
    /* 0x09C */ u8 _pad9C[0xB0 - 0x9C];
    /* 0x0B0 */ u32 mCollisionMask;
    /* 0x0B4 */ u8 _padB4[0x114 - 0xB4];
    /* 0x114 */ u32 mHitType;
    /* 0x118 */ u32 mField118;
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x194 - 0x11D];
    /* 0x194 */ u8 mFlag194;
    /* 0x195 */ u8 _pad195[0x230 - 0x195];
    /* 0x230 */ u32 mItemFlags;
    /* 0x234 */ u8 _pad234[0x270 - 0x234];
    /* 0x270 */ BoibSub270 mAnimSub;
    /* 0x2A8 */ void* mEmitterA; // Particle 0x256
    /* 0x2AC */ void* mEmitterB; // Particle 0x257
};

// BOIB update
extern "C" void fn_801DCC98(BoibActor* this_) {
    JGeometry::TVec3<f32>* pos = &this_->mPos;
    pos->add(this_->mVel);
    fn_8013CB44(this_->mEmitterA, pos, 0, 0, 1);
    fn_8013CB44(this_->mEmitterB, &this_->mPos, 0, 0, 1);
    s32 idx = this_->mRoomId;
    u8* mgr = fn_802D6A9C();
    f32* r;
    if (idx < 8) {
        r = (f32*)(mgr + 0xcc);
    } else {
        r = (f32*)(mgr + 0xdc);
    }
    bool inside = ItemBase_inArea(r, &this_->mPos.x);
    if (!inside) {
        this_->mActiveFlag = 0;
    } else if (fn_801F2B7C(this_, this_->mHitType, -1, 0x18)) {
        this_->mActiveFlag = 0;
    }
}

// BOIB init (vtable slot 1)
extern "C" void fn_801DCDB4(BoibActor* this_) {
    fn_801D0ED0(this_);
    f32 a = lbl_8053F378;
    f32 b = lbl_8053F37C;
    f32 c = lbl_8053F380;
    f32 d = lbl_8053F384;
    this_->mBounds60[0] = a;
    this_->mBounds60[1] = a;
    this_->mBounds60[2] = b;
    this_->mBounds60[3] = b;
    this_->mBounds70[0] = c;
    this_->mBounds70[1] = c;
    this_->mBounds70[2] = d;
    this_->mBounds70[3] = d;
    this_->mBounds80[0] = c;
    this_->mBounds80[1] = c;
    this_->mBounds80[2] = d;
    this_->mBounds80[3] = d;
    this_->mCollisionMask = 0;
    this_->mField98 = 2;
    this_->mItemFlags |= 0x300;
    this_->mHitType = 2;
    this_->mFlag194 = 1;
    this_->mEmitterA = fn_8013CC50(this_->mRoomId, &this_->mPos, 0x256, 0, 0, 0, 0, 1, lbl_8053F380);
    this_->mEmitterB = fn_8013CC50(this_->mRoomId, &this_->mPos, 0x257, 0, 0, 0, 0, 1, lbl_8053F380);
}

extern "C" void* fn_801DCE9C(BoibActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A5038;
        fn_801EE434(this_->mEmitterA);
        fn_801EE434(this_->mEmitterB);
        if (this_ != 0) {
            this_->mVtable = lbl_804A4808;
            if (&this_->mAnimSub != 0) {
                if (&this_->mAnimSub.mVtable != 0) {
                    this_->mAnimSub.mVtable = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801DCF40(BoibActor* this_) {
    fn_801D0F40(this_);
    this_->mVtable = lbl_804A5038;
    this_->mEmitterA = 0;
    this_->mEmitterB = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
