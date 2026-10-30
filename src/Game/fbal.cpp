// TU 0x802201d8-0x802205e0 — Actor 'FBAL' (Fireball Projectile).
#include "types.h"

struct GXColor_FBAL {
    GXColor_FBAL(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
    u8 r, g, b, a;
};

struct FbalSub270 {
    u8 _pad00[0x24];
    void* mVtable; // +0x294 on FbalActor
    u8 _pad28[0x14];
};

struct FbalActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPos[3];
    /* 0x018 */ u8 _pad18[0x270 - 0x18];
    /* 0x270 */ FbalSub270 mAnimSub;
    /* 0x2AC */ s32 mEmitterHandle; // Particle emitter 0x290
};

extern "C" {
extern void* lbl_8053AB10;
void fn_80158B5C(void* mgr, u32 id, void* pos, GXColor_FBAL color, f32 size);
void fn_801D2E70(void* this_);
void fn_801D2FEC(void* this_);
void fn_8013CB44(s32 handle, void* pos, s32 a, s32 b, s32 c);
s32 fn_8013CC50(u32 id, void* pos, s32 kind, f32 scale, s32 a, s32 b, s32 c, s32 d, s32 e);
void fn_801EE434(s32 handle);
void __dt__5ActorFv(void* this_, int flag);
}
void operator delete(void* p);
extern void* lbl_804A6828[];
extern void* lbl_804A48B0[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

struct FBAL_Mgr { u8 pad[0x2c]; void* mShadow; };

// FBAL draw (vtable slot 6): renders ground shadow
extern "C" void fn_802201D8(FbalActor* this_) {
    u32 id = this_->mRoomId;
    GXColor_FBAL c(0, 0, 0, 0x80);
    fn_80158B5C(((FBAL_Mgr*)lbl_8053AB10)->mShadow, id, this_->mPos, c, 24.0f);
}

// FBAL update (vtable slot 3)
extern "C" void fn_80220230(FbalActor* this_) {
    fn_801D2E70(this_);
    fn_8013CB44(this_->mEmitterHandle, this_->mPos, 0, 0, 1);
}

// FBAL init (vtable slot 1)
extern "C" void fn_80220274(FbalActor* this_) {
    fn_801D2FEC(this_);
    this_->mEmitterHandle = fn_8013CC50(this_->mRoomId, this_->mPos, 0x290, 1.0f, 0, 0, 0, 0, 1);
}

extern "C" void* fn_802202CC(FbalActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A6828;
        fn_801EE434(this_->mEmitterHandle);
        if (this_ != 0) {
            this_->mVtable = lbl_804A48B0;
            if (this_ != 0) {
                this_->mVtable = lbl_804A4808;
                if (&this_->mAnimSub != 0) {
                    if (&this_->mAnimSub.mVtable != 0) {
                        this_->mAnimSub.mVtable = lbl_8049CC34;
                    }
                }
                __dt__5ActorFv(this_, 0);
            }
        }
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801D30B8(void* this_);

extern "C" void* fn_80220378(FbalActor* this_) {
    fn_801D30B8(this_);
    this_->mVtable = lbl_804A6828;
    this_->mEmitterHandle = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
