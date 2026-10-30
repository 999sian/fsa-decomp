// TU 0x8021d26c-0x8021d734 — Actor 'FBGE' (Fireball Generator, misdecoded as EZGE in early CSV).
#include "types.h"

extern "C" {
void __dt__5ActorFv(void* this_, int flag);
void detach__5ActorFv(void* this_);
u8 fn_801CECF4(void* this_, u32 id, f32 a, f32 b);
void fn_801F0E34(void* this_, u32 a, s32 b);
void fn_801D0ED0(void* this_);
extern u8* lbl_8053AAF8;
}
void operator delete(void* p);
extern void* lbl_804A6660[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

struct EzgeVtbl {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual bool v11();
};
#define EZGE_V11(p) (((EzgeVtbl*)(p))->v11())

struct FbgeSub270 {
    u8 _pad00[0x24];
    void* mVtable; // +0x294 on FbgeActor
    u8 _pad28[0x10];
};

struct FbgeActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u8 _pad04[0x60 - 0x04];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ f32 mBounds70[4];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[4];
    /* 0x098 */ s32 mField98;
    /* 0x09C */ u8 _pad9C[0xB0 - 0x9C];
    /* 0x0B0 */ s32 mCollisionMask;
    /* 0x0B4 */ u8 _padB4[0x108 - 0xB4];
    /* 0x108 */ s32 mSortPriority;
    /* 0x10C */ u8 _pad10C[0x11C - 0x10C];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x230 - 0x11D];
    /* 0x230 */ u32 mItemFlags;
    /* 0x234 */ u8 _pad234[0x244 - 0x234];
    /* 0x244 */ s32 mCopiedPriority;
    /* 0x248 */ s32 mState;
    /* 0x24C */ s32 mTimer;
    /* 0x250 */ s32 mTargetId;
    /* 0x254 */ f32 mSpeedX;
    /* 0x258 */ f32 mSpeedY;
    /* 0x25C */ u8 _pad25C[0x270 - 0x25C];
    /* 0x270 */ FbgeSub270 mAnimSub;
    /* 0x2A8 */ u16 mFireCooldown;
};

extern "C" void* fn_8021D26C(FbgeActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A6660;
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
            operator delete(this_);
        }
    }
    return this_;
}

// FBGE update (vtable slot 3): fires 'FBAL' projectile every 120 frames when player in range
extern "C" void fn_8021D2FC(FbgeActor* this_) {
    if (EZGE_V11(this_)) {
        detach__5ActorFv(this_);
    } else {
        switch (this_->mState) {
        case 0:
            if (this_->mFireCooldown > 1) {
                this_->mFireCooldown--;
            } else if (fn_801CECF4(this_, 'FBAL', 1.5f, 112.0f)) {
                fn_801F0E34(this_, 0x50030, 0);
                this_->mFireCooldown = 120;
            }
            break;
        }
    }
}

// FBGE init (vtable slot 1)
extern "C" void fn_8021D3AC(FbgeActor* this_) {
    fn_801D0ED0(this_);
    if (lbl_8053AAF8[0x7e] != 0) {
        if ((this_->mSpawnParam >> 1) & 1) {
            this_->mActiveFlag = 0;
            return;
        }
    } else if (this_->mSpawnParam & 1) {
        this_->mActiveFlag = 0;
        return;
    }
    this_->mBounds60[0] = 1.0f;
    this_->mBounds60[1] = 1.0f;
    this_->mBounds60[2] = -1.0f;
    this_->mBounds60[3] = -1.0f;
    this_->mBounds70[0] = this_->mBounds60[0];
    this_->mBounds70[1] = this_->mBounds60[1];
    this_->mBounds70[2] = this_->mBounds60[2];
    this_->mBounds70[3] = this_->mBounds60[3];
    this_->mBounds80[0] = 1.0f;
    this_->mBounds80[1] = 1.0f;
    this_->mBounds80[2] = -1.0f;
    this_->mBounds80[3] = -1.0f;
    this_->mCollisionMask = 0;
    this_->mField98 = 2;
    this_->mItemFlags |= 0x380;
    this_->mSortPriority = 1000;
    this_->mCopiedPriority = this_->mSortPriority;
    this_->mState = 0;
    this_->mTargetId = -1;
    this_->mTimer = 0;
    this_->mSpeedX = 0.0f;
    this_->mSpeedY = 0.0f;
    if (EZGE_V11(this_)) {
        detach__5ActorFv(this_);
    }
}

extern "C" void* fn_801D0F40(void* this_);

extern "C" void* fn_8021D4CC(FbgeActor* this_) {
    fn_801D0F40(this_);
    this_->mVtable = lbl_804A6660;
    this_->mFireCooldown = 120;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
