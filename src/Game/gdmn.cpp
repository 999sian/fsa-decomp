// TU 80183544-80184040 — Actor 'GDMN' (Burrowing Ground Enemy, sibling of RDVR).
#include "types.h"
#include "JSystem/JParticle/JPAEmitter.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);



struct GdmnVirt {
    virtual void v08(); virtual void v0c(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1c(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2c(); virtual void v30();
    virtual u8 v34();
};

struct GdmnActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3<f32> mPos;
    /* 0x018 */ u8 _pad18[0x3C - 0x18];
    /* 0x03C */ JGeometry::TVec3<f32> mVel;
    /* 0x048 */ u8 _pad48[0x60 - 0x48];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0xB0 - 0x94];
    /* 0x0B0 */ u32 mCollisionMask;
    /* 0x0B4 */ u32 mFieldB4;
    /* 0x0B8 */ s32 mFieldB8;
    /* 0x0BC */ u8 _padBC[0x195 - 0xBC];
    /* 0x195 */ u8 mFlag195;
    /* 0x196 */ u8 _pad196[2];
    /* 0x198 */ void* mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mState;          // 0..7 burrowing/emerging/chasing state machine
    /* 0x234 */ u8 mColorBytes[4];
    /* 0x238 */ u8 mColorR, mColorG, mColorB;
    /* 0x23B */ u8 _pad23B;
    /* 0x23C */ s32 mAnimTimer;
    /* 0x240 */ s32 mPhaseTimer;
    /* 0x244 */ s32 mSubTimer;
    /* 0x248 */ s32 mField248;
    /* 0x24C */ s32 mField24C;
    /* 0x250 */ s32 mField250;
    /* 0x254 */ s32 mAnimFrame;      // Sprite offset from 0x155 in "enemy_gc_sob.bin"
    /* 0x258 */ s32 mIsSurfaced;
    /* 0x25C */ s32 mWaitSwitchFlag; // Unpacked from (spawnParam >> 8) & 1
    /* 0x260 */ u16 mMoveAngle;
    /* 0x262 */ u16 _pad262;
    /* 0x264 */ f32 mTargetVelX;
    /* 0x268 */ f32 mTargetVelY;
    /* 0x26C */ f32 mTargetVelZ;
    /* 0x270 */ JPABaseEmitter* mSandEmitter;
};

extern "C" {
void fn_80183544(GdmnActor* this_);
void fn_8018359C(GdmnActor* this_);
void fn_80183C18(GdmnActor* this_);
void* fn_80183C54(GdmnActor* this_, s16 freeFlag);
void fn_80183CC0(GdmnActor* thisPtr);
void fn_80183CF8(GdmnActor* this_);
void v02__5ActorFv();
void v05__5ActorFv();
void v07__5ActorFv();
void v08__5ActorFv();
void v09__5ActorFv();
void v10__5ActorFUlUl();
void v11__5ActorFv();
void v12__5ActorFv();
void v13__5ActorFv();
void v14__5ActorFv();
void v16__5ActorFv();
void v17__5ActorFiPf();
void v18__5ActorFiPf();
}

void* lbl_804A1790[] = {
    0,
    0,
    (void*)fn_80183C54,
    (void*)fn_80183CF8,
    (void*)v02__5ActorFv,
    (void*)fn_8018359C,
    (void*)fn_80183C18,
    (void*)v05__5ActorFv,
    (void*)fn_80183544,
    (void*)v07__5ActorFv,
    (void*)v08__5ActorFv,
    (void*)v09__5ActorFv,
    (void*)v10__5ActorFUlUl,
    (void*)v11__5ActorFv,
    (void*)v12__5ActorFv,
    (void*)v13__5ActorFv,
    (void*)v14__5ActorFv,
    (void*)fn_80183CC0,
    (void*)v16__5ActorFv,
    (void*)v17__5ActorFiPf,
    (void*)v18__5ActorFiPf,
};

extern "C" void* fn_80212AC0(void);
extern "C" void fn_80212AF0(void* registry, void* posPtr);
extern "C" void v04__5ActorFv(void* this_);

extern "C" void* fn_802D6A9C(void);
extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" u8 fn_801F305C(void* this_);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" void fn_801F71A4(f32* v, f32 a, f32 b, f32 c);
extern "C" void fn_801EEC98(void* this_, void* room, u16* a, s32* dir, f32* dist, s32* player, s32 b, s32 c);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" void fn_801F714C(void* shortPtr, s32 target, s32 divisor, s32 maxStep);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 c);
extern "C" JPABaseEmitter* fn_8013CC50(u32 owner, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern u8* lbl_8053AAF8;

static inline f32 gdmnSin(s16 v) {
    return JMath::sincosTable_.mTable[static_cast<u16>(v) >> (16U - 11)].first;
}
static inline f32 gdmnCos(s16 v) {
    return JMath::sincosTable_.mTable[static_cast<u16>(v) >> (16U - 11)].second;
}

#define GDMN_TINT(E)     if ((((u8*)fn_802D6A9C()) + 0x10000)[0x31f2] == 1) {         (E)->setGlobalPrmColor(this_->mColorR, this_->mColorG, this_->mColorB);     }

static inline void gdmnFollow(GdmnActor* this_) {
    JPABaseEmitter* e = this_->mSandEmitter;
    if (e != 0) {
        e->setGlobalTranslation(this_->mPos);
        GDMN_TINT(this_->mSandEmitter);
    }
}

static inline JPABaseEmitter* gdmnSpawn(GdmnActor* this_, s32 id) {
    return fn_8013CC50(this_->mRoomId, &this_->mPos, id, 0, 1, 0, 0, 1, 1.0f);
}

static inline void gdmnStop(GdmnActor* this_) {
    this_->mVel.x = this_->mVel.y = this_->mVel.z =
        this_->mTargetVelX = this_->mTargetVelY = this_->mTargetVelZ = 0.0f;
}

static inline s32 gdmnRand(s32 n) {
    u32* seed = (u32*)(lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 0x3c6ef35f;
    u32 bits = (*seed >> 9) | 0x3f800000;
    return (f32)n * (*(f32*)&bits - 1.0f);
}

extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, f32 sx, f32 sy, s32 a, s32 b);
extern "C" void fn_8018330C(u32* out);

// GDMN draw (vtable slot 6)
extern "C" void fn_80183544(GdmnActor* this_) {
    s32 s = this_->mState;
    if (s == 0 || s == 1) {
        return;
    }
    fn_801F06F0(this_, "enemy_gc_sob.bin", this_->mAnimFrame + 0x155, 1.0f, 1.0f, 0, -1);
}

// GDMN update (vtable slot 3)
extern "C" void fn_8018359C(GdmnActor* this_) {
    u16 ang = 0;
    f32 dist = 0.0f;
    s32 player = -1;
    if (fn_801F3D94(this_, 1)) {
        gdmnFollow(this_);
        fn_801F2618(this_, 0, 0);
        return;
    }
    if (this_->mIsSurfaced != 0 && fn_801F305C(this_)) {
        gdmnFollow(this_);
        fn_801F2618(this_, 0, 0);
        return;
    }
    fn_801F71A4(&this_->mVel.x, this_->mTargetVelX, 0.3f, 1.0f);
    fn_801F71A4(&this_->mVel.y, this_->mTargetVelY, 0.3f, 1.0f);
    this_->mPos.add(this_->mVel);
    fn_80212AF0(fn_80212AC0(), &this_->mPos);
    fn_801EEC98(this_, this_->mRoomHandle, &ang, 0, &dist, &player, 0, 0);
    if (this_->mIsSurfaced != 0) {
        fn_801F2B7C(this_, -100, -1, 1);
    }
    fn_801F2618(this_, 0, 0);
    switch ((u32)this_->mState) {
    case 0:
        if (this_->mWaitSwitchFlag == 1) {
            if (((GdmnVirt*)this_)->v34()) {
                this_->mState = 2;
            }
            break;
        }
        this_->mPhaseTimer = gdmnRand(30) + 30;
        this_->mState = 1;
    case 1:
        if (this_->mPhaseTimer != 0) {
            break;
        }
        if (dist > 64.0f) {
            break;
        }
        this_->mState = 2;
    case 2:
        fn_801F0E34(this_, 0x40097, 0);
        this_->mFieldB8 = 1;
        if (this_->mSandEmitter == 0) {
            JPABaseEmitter* e = gdmnSpawn(this_, 0x1da);
            GDMN_TINT(e);
            this_->mSandEmitter = gdmnSpawn(this_, 0x1db);
            GDMN_TINT(this_->mSandEmitter);
        }
        gdmnStop(this_);
        this_->mAnimTimer = 8;
        this_->mField248 = 0;
        this_->mAnimFrame = 2;
        this_->mState = 3;
    case 3:
        if (this_->mAnimTimer != 0) {
            break;
        }
        gdmnFollow(this_);
        this_->mState = 4;
    case 4:
        this_->mCollisionMask = 0x11101;
        this_->mAnimTimer = 8;
        this_->mPhaseTimer = 200;
        this_->mField248 = 0;
        this_->mAnimFrame = 0;
        this_->mIsSurfaced = 1;
        this_->mState = 5;
    case 5:
        gdmnFollow(this_);
        fn_801F714C(&this_->mMoveAngle, ang, 1, 0x200);
        this_->mTargetVelX = 0.7f * gdmnSin(this_->mMoveAngle);
        this_->mTargetVelY = 0.7f * gdmnCos(this_->mMoveAngle);
        if (this_->mAnimTimer == 0) {
            this_->mAnimFrame = this_->mAnimFrame + 1;
            this_->mAnimFrame = this_->mAnimFrame & 1;
            this_->mAnimTimer = 8;
        }
        if (this_->mPhaseTimer != 0) {
            break;
        }
        this_->mState = 6;
    case 6:
        if (this_->mSandEmitter != 0) {
            JPABaseEmitter* e = gdmnSpawn(this_, 0x1da);
            GDMN_TINT(e);
            this_->mSandEmitter->becomeInvalidEmitter();
            this_->mSandEmitter = 0;
        }
        this_->mCollisionMask = 0x1000;
        gdmnStop(this_);
        this_->mIsSurfaced = 0;
        this_->mAnimTimer = 8;
        this_->mField248 = 0;
        this_->mAnimFrame = 2;
        this_->mState = 7;
    case 7:
        if (this_->mAnimTimer != 0) {
            break;
        }
        this_->mState = 0;
        break;
    }
    if (this_->mAnimTimer > 0) {
        this_->mAnimTimer -= 1;
    }
    if (this_->mPhaseTimer > 0) {
        this_->mPhaseTimer -= 1;
    }
    if (this_->mSubTimer > 0) {
        this_->mSubTimer -= 1;
    }
}

extern "C" void fn_80183C18(GdmnActor* this_) {
    void* registry = fn_80212AC0();
    fn_80212AF0(registry, &this_->mPos);
    v04__5ActorFv(this_);
}

extern "C" void* fn_80183C54(GdmnActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A1790;
        fn_801EE434(this_->mSandEmitter);
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80183CC0(GdmnActor* p) {
    if (p->mIsSurfaced != 0) return;
    if (p->mState == 5) return;
    p->mCollisionMask = 0x11101;
    p->mAnimFrame = 0;
    p->mState = 4;
}

// GDMN init (vtable slot 1)
extern "C" void fn_80183CF8(GdmnActor* this_) {
    this_->mBounds60[0] = -8.0f;
    this_->mBounds60[1] = -8.0f;
    this_->mBounds60[2] = 8.0f;
    this_->mBounds60[3] = 8.0f;
    this_->mBounds80[0] = -8.0f;
    this_->mBounds80[1] = -8.0f;
    this_->mBounds80[2] = 8.0f;
    this_->mBounds80[3] = 8.0f;
    this_->mField248 = 0;
    this_->mField24C = 0;
    this_->mField250 = 0;
    this_->mAnimTimer = 0;
    this_->mPhaseTimer = 0;
    this_->mSubTimer = 0;
    this_->mColorR = 0;
    this_->mColorG = 0;
    this_->mColorB = 0;
    if (*((u8*)fn_802D6A9C() + 0x131f2) == 1) {
        u8 c[4];
        fn_8018330C((u32*)c);
        this_->mColorBytes[0] = c[0];
        this_->mColorBytes[1] = c[1];
        this_->mColorBytes[2] = c[2];
        this_->mColorBytes[3] = c[3];
        this_->mColorR = *(u32*)this_->mColorBytes >> 24;
        this_->mColorG = *(u32*)this_->mColorBytes >> 16;
        this_->mColorB = *(u32*)this_->mColorBytes >> 8;
    }
    this_->mWaitSwitchFlag = (this_->mSpawnParam >> 8) & 1;
    this_->mFlag195 = 1;
    this_->mAnimFrame = 2;
    this_->mTargetVelZ = 0.0f;
    this_->mTargetVelY = 0.0f;
    this_->mTargetVelX = 0.0f;
    this_->mVel.z = 0.0f;
    this_->mVel.y = 0.0f;
    this_->mVel.x = 0.0f;
    this_->mIsSurfaced = 0;
    this_->mMoveAngle = 0;
    this_->mSandEmitter = 0;
    this_->mState = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
