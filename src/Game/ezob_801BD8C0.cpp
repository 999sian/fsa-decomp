// Game TU 801BD8C0-801BDE5C — Actor 'FBOB' (Fireball Obstacle / Projectile, misdecoded as EZOB).
#include "types.h"
#include "JSystem/JUtility/TColor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JParticle/JPAEmitter.h"

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A4038[];

extern "C" void fn_8013CB44(void* h, void* pos, u32 a, u32 b, u32 c);
extern "C" int fn_801CB7CC(void* arg);
extern "C" void fn_80158B5C(void* obj, u32 id, void* pos, GXColor color, f32 f);
extern u8* lbl_8053AB10;
extern const f32 lbl_8053EC8C;
extern const f32 lbl_8053EC90;
extern const f32 lbl_8053EC94;
extern const f32 lbl_8053EC98;
extern const f32 lbl_8053EC9C;
extern const u16 lbl_8053EC88[2];
extern "C" u8 fn_801F2B7C(void* this_, u32 a, s32 b, u32 c);
extern "C" JPABaseEmitter* fn_8013CC50(u32 id, f32* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

struct EzobSub270 {
    u8 _pad00[0x24];
    void* mVtable; // +0x294 on EZOB
    u8 _pad28[0x10];
};

struct EZOB {
    /* 0x000 */ void* vtbl;
    /* 0x004 */ u32 mId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3<f32> mPos;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ f32 mBounds70[4];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u32 mField94;
    /* 0x098 */ u32 mField98;
    /* 0x09C */ u8 _pad9C[0xB0 - 0x9C];
    /* 0x0B0 */ u32 mCollisionMask;
    /* 0x0B4 */ u8 _padB4[0x114 - 0xB4];
    /* 0x114 */ u32 mHitType;
    /* 0x118 */ u8 _pad118[0x194 - 0x118];
    /* 0x194 */ u8 mFlag194;
    /* 0x195 */ u8 _pad195[0x240 - 0x195];
    /* 0x240 */ u8 mHitResult;
    /* 0x241 */ u8 _pad241[0x270 - 0x241];
    /* 0x270 */ EzobSub270 mAnimSub;
    /* 0x2A8 */ JPABaseEmitter* mEmitters[2];
};

extern "C" void fn_801BD8C0(EZOB* this_, const JGeometry::TVec3<f32>& pos, void* arg) {
    this_->mPos.x = pos.x;
    this_->mPos.y = pos.y;
    this_->mPos.z = pos.z;
    s16 rot = fn_801CB7CC(arg);
    for (s32 i = 0; i < 2; i++) {
        fn_8013CB44(this_->mEmitters[i], (void*)&pos, 0, 0, 1);
        if (i == 0) {
            JPAGetXYZRotateMtx(0, rot, 0, this_->mEmitters[i]->mGlobalRot);
        }
    }
}

extern "C" void fn_801BD978(EZOB* this_) {
    u32 id = this_->mId;
    JUtility::TColor color(0, 0, 0, 0x80);
    fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), id, &this_->mPos, color, lbl_8053EC8C);
}

extern "C" void fn_801BD9D0(EZOB* this_) {
    this_->mHitResult = fn_801F2B7C(this_, this_->mHitType, -1, 1);
    if (this_->mSpawnParam == 0) {
        fn_8013CC50(this_->mId, &this_->mPos.x, 0x54d, 1, 1, 0, 0, 1, lbl_8053EC90);
    }
}

extern "C" void fn_801BDA40(EZOB* this_) {
    fn_801D0ED0(this_);
    f32 a = lbl_8053EC94;
    f32 c = lbl_8053EC90;
    f32 b = lbl_8053EC98;
    f32 d = lbl_8053EC9C;
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
    this_->mFlag194 = 1;
    this_->mHitType = 2;
    for (s32 i = 0; i < 2; i++) {
        u16 kind = lbl_8053EC88[i];
        this_->mEmitters[i] = fn_8013CC50(this_->mId, &this_->mPos.x, kind, 0, 0, 0, 0, 1, lbl_8053EC90);
    }
}

extern "C" void* fn_801BDB2C(EZOB* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->vtbl = lbl_804A4038;
        for (s32 i = 0; i < 2; i++) {
            fn_801EE434(this_->mEmitters[i]);
        }
        if (this_ != 0) {
            this_->vtbl = lbl_804A4808;
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

extern "C" void* fn_801BDBF0(EZOB* this_) {
    fn_801D0F40(this_);
    this_->vtbl = lbl_804A4038;
    this_->mEmitters[0] = 0;
    this_->mEmitters[1] = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
