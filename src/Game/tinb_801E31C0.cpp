// Game TU 801E31C0-801E3618 — Actor 'TINB' (Tingle Mode / Multiplayer Condition Marker).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A5370[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_801D0F40(void* this_);

struct TinbSub270 {
    u8 _pad00[0x24];
    void* mVtable; // +0x294 on TinbActor
    u8 _pad28[0x10];
};

struct TinbActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u8 _pad04[0x60 - 0x04];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ f32 mBounds70[4];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0xB0 - 0x94];
    /* 0x0B0 */ u32 mCollisionMask;
    /* 0x0B4 */ u8 _padB4[0x108 - 0xB4];
    /* 0x108 */ u32 mSortPriority;
    /* 0x10C */ u8 _pad10C[0x230 - 0x10C];
    /* 0x230 */ u32 mItemFlags;
    /* 0x234 */ u8 _pad234[0x244 - 0x234];
    /* 0x244 */ u32 mCopiedPriority;
    /* 0x248 */ u8 _pad248[0x270 - 0x248];
    /* 0x270 */ TinbSub270 mAnimSub;
};

extern "C" void* fn_801E31C0(TinbActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A5370;
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

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7884(void* mgr, u32 tag, s32 id);
extern "C" TinbActor* fn_801F666C(void* mgr, s32 idx);
extern u8* lbl_8053AAF8;
extern "C" void fn_801D0ED0(void* this_);
extern const f32 lbl_8053F508;
extern const f32 lbl_8053F50C;

extern "C" BOOL fn_801E3250(u32 id, u8 useHigh) {
    s32 idx;
    BOOL result = FALSE;
    idx = fn_801F7884(fn_801F856C(), 'TINB', id);
    if (idx >= 0) {
        TinbActor* actor = fn_801F666C(fn_801F856C(), idx);
        if (actor != 0) {
            u32 state;
            if (useHigh) {
                state = (actor->mSpawnParam >> 4) & 0xf;
            } else {
                state = actor->mSpawnParam & 0xf;
            }
            if (state == 0) {
                result = TRUE;
            } else if (lbl_8053AAF8[0x7e] == 0) {
                if (state == 2) {
                    result = TRUE;
                }
            } else if (state == 1) {
                result = TRUE;
            }
        }
    }
    return result;
}

extern "C" void fn_801E331C(void) {}

// TINB init (vtable slot 1)
extern "C" void fn_801E3320(TinbActor* this_) {
    fn_801D0ED0(this_);
    f32 b = lbl_8053F50C;
    f32 a = lbl_8053F508;
    this_->mBounds60[0] = a;
    this_->mBounds60[1] = a;
    this_->mBounds60[2] = b;
    this_->mBounds60[3] = b;
    this_->mBounds70[0] = this_->mBounds60[0];
    this_->mBounds70[1] = this_->mBounds60[1];
    this_->mBounds70[2] = this_->mBounds60[2];
    this_->mBounds70[3] = this_->mBounds60[3];
    this_->mBounds80[0] = a;
    this_->mBounds80[1] = a;
    this_->mBounds80[2] = b;
    this_->mBounds80[3] = b;
    this_->mCollisionMask = 0;
    this_->mItemFlags |= 0x380;
    this_->mSortPriority = 1000;
    this_->mCopiedPriority = this_->mSortPriority;
}

extern "C" void* fn_801E33B8(TinbActor* this_) {
    fn_801D0F40(this_);
    this_->mVtable = lbl_804A5370;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
