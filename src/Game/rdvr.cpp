// TU 80182914-80183544 — Actor 'RDVR' (Red/Blue Leever Burrowing Enemy).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JParticle/JPAEmitter.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A1718[];

extern "C" void* fn_80212AC0(void);
extern "C" void fn_80212AF0(void* registry, void* posPtr);
extern "C" void fn_801F5790(void* this_);
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, f32 sx, f32 sy, s32 a, s32 b);
extern void** lbl_8053AB10;
extern "C" void fn_8018330C(u32* out);
extern "C" void* fn_802D6A9C(void);
extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" void fn_801F2618(void* this_, s32, s32);
extern "C" u8 fn_801F305C(void* this_);
extern "C" void fn_801F71A4(f32* v, f32 target, f32 a, f32 b);
extern "C" void fn_801EEC98(void* this_, void*, u16*, s32, f32*, s32*, s32, s32);
extern "C" void fn_801F2B7C(void* this_, s32, s32, s32);
extern "C" void fn_801F714C(u16* a, u16 target, s32 b, s32 step);
extern "C" JPABaseEmitter* fn_8013CC50(s32 id, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);

class RDVR {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30();
    virtual u8 v34();

    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u8 pad08[4];
    /* 0x00C */ JGeometry::TVec3f mPos;
    /* 0x018 */ u8 pad18[0x3c - 0x18];
    /* 0x03C */ JGeometry::TVec3f mVel;
    /* 0x048 */ u8 pad48[0x60 - 0x48];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ u8 pad70[0x80 - 0x70];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 pad94[0xb0 - 0x94];
    /* 0x0B0 */ u32 mCollisionMask;
    /* 0x0B4 */ u8 padB4[4];
    /* 0x0B8 */ s32 mFieldB8;
    /* 0x0BC */ u8 padBC[0x195 - 0xbc];
    /* 0x195 */ u8 mFlag195;
    /* 0x196 */ u8 pad196[2];
    /* 0x198 */ void* mRoomHandle;
    /* 0x19C */ u8 pad19C[0x230 - 0x19c];
    /* 0x230 */ u32 mState;          // 0..7 burrowing/emerging/chasing state machine
    /* 0x234 */ u8 mColorBytes[4];
    /* 0x238 */ u8 mColorR, mColorG, mColorB;
    /* 0x23B */ u8 pad23B;
    /* 0x23C */ s32 mAnimTimer;
    /* 0x240 */ s32 mPhaseTimer;
    /* 0x244 */ s32 mSubTimer;
    /* 0x248 */ s32 mField248;
    /* 0x24C */ s32 mField24C;
    /* 0x250 */ s32 mField250;
    /* 0x254 */ s32 mAnimFrame;      // Sprite offset from 0x158 in "enemy_gc_sob.bin"
    /* 0x258 */ s32 mIsSurfaced;     // Non-zero when emerged and vulnerable
    /* 0x25C */ s32 mIsFastVariant;  // Unpacked from spawnParam & 1
    /* 0x260 */ s32 mWaitSwitchFlag; // Unpacked from (spawnParam >> 8) & 1
    /* 0x264 */ u16 mMoveAngle;
    /* 0x268 */ f32 mTargetVelX;
    /* 0x26C */ f32 mTargetVelY;
    /* 0x270 */ f32 mTargetVelZ;
    /* 0x274 */ JPABaseEmitter* mSandEmitter;

    void syncColor() {
        mSandEmitter->setGlobalPrmColor(mColorR, mColorG, mColorB);
    }
    void syncChild() {
        JPABaseEmitter* p = mSandEmitter;
        if (p != 0) {
            p->setGlobalTranslation(mPos);
            if (*((u8*)fn_802D6A9C() + 0x131f2) == 1) {
                mSandEmitter->setGlobalPrmColor(mColorR, mColorG, mColorB);
            }
        }
    }
    JPABaseEmitter* spawn(s32 id) {
        JPABaseEmitter* e = fn_8013CC50(mRoomId, &mPos, id, 0, 1, 0, 0, 1, 1.0f);
        if (*((u8*)fn_802D6A9C() + 0x131f2) == 1) {
            e->setGlobalPrmColor(mColorR, mColorG, mColorB);
        }
        return e;
    }
    void stop() {
        mTargetVelZ = 0.0f;
        mTargetVelY = 0.0f;
        mTargetVelX = 0.0f;
        mVel.z = 0.0f;
        mVel.y = 0.0f;
        mVel.x = 0.0f;
    }
};

extern "C" void* fn_80183100(RDVR* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1718;
        fn_801EE434(this_->mSandEmitter);
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8018316C(RDVR* this_) {
    void* registry = fn_80212AC0();
    fn_80212AF0(registry, &this_->mPos);
    fn_801F5790(this_);
}

extern "C" {
void fn_801831A8(RDVR* p) {
    if (p->mIsSurfaced != 0) return;
    if ((s32)p->mState == 5) return;
    p->mCollisionMask = 0x11101;
    p->mAnimFrame = 6;
    p->mState = 4;
}
}

// RDVR draw (vtable slot 6)
extern "C" void fn_80182914(RDVR* this_) {
    s32 flag = -1;
    s32 state = this_->mState;
    s32 frame = this_->mAnimFrame;
    if ((state == 0 || state == 1) && this_->mAnimTimer == 0) {
        return;
    }
    if (this_->mIsSurfaced != 0) {
        flag = 0;
    }
    if (this_->mIsFastVariant == 1 && frame >= 3) {
        frame += 5;
    }
    fn_801F06F0(this_, "enemy_gc_sob.bin", frame + 0x158, 1.0f, 1.0f, 0, flag);
}

// RDVR update (vtable slot 3)
extern "C" void fn_8018299C(RDVR* this_) {
    u16 angle = 0;
    f32 f = 0.0f;
    s32 hit = -1;
    if (fn_801F3D94(this_, 1)) {
        this_->syncChild();
        fn_801F2618(this_, 0, 0);
        return;
    }
    if (this_->mIsSurfaced != 0 && fn_801F305C(this_)) {
        this_->syncChild();
        fn_801F2618(this_, 0, 0);
        return;
    }
    fn_801F71A4(&this_->mVel.x, this_->mTargetVelX, 0.3f, 1.0f);
    fn_801F71A4(&this_->mVel.y, this_->mTargetVelY, 0.3f, 1.0f);
    this_->mPos.add(this_->mVel);
    fn_80212AF0(fn_80212AC0(), &this_->mPos);
    fn_801EEC98(this_, this_->mRoomHandle, &angle, 0, &f, &hit, 0, 0);
    if (this_->mIsSurfaced != 0) {
        fn_801F2B7C(this_, -100, -1, 1);
    }
    fn_801F2618(this_, 0, 0);
    switch (this_->mState) {
    case 0:
        if (this_->mWaitSwitchFlag == 1) {
            if (this_->v34()) {
                this_->mState = 2;
            }
            break;
        }
        this_->mPhaseTimer = 100;
        this_->mState = 1;
    case 1:
        this_->mTargetVelX = 0.5f * JMASinShort(angle);
        this_->mTargetVelY = 0.5f * JMACosShort(angle);
        if (this_->mPhaseTimer != 0) {
            break;
        }
        this_->mState = 2;
    case 2:
        this_->mFieldB8 = 1;
        if (this_->mSandEmitter == 0) {
            this_->spawn(0x1da);
            this_->mSandEmitter = fn_8013CC50(this_->mRoomId, &this_->mPos, 0x1db, 0, 1, 0, 0, 1, 1.0f);
            if (*((u8*)fn_802D6A9C() + 0x131f2) == 1) {
                this_->syncColor();
            }
        }
        this_->stop();
        this_->mAnimTimer = 6;
        this_->mField248 = 0;
        this_->mAnimFrame = 0;
        this_->mState = 3;
    case 3:
        if (this_->mAnimTimer == 0) {
            this_->mAnimFrame++;
            this_->mAnimTimer = 6;
            if (this_->mAnimFrame > 5) {
                this_->mState = 4;
            }
        }
        this_->syncChild();
        break;
    case 4:
        this_->mCollisionMask = 0x11101;
        this_->mPhaseTimer = 200;
        this_->mAnimFrame = 6;
        this_->mAnimTimer = 8;
        this_->mField248 = 0;
        this_->mIsSurfaced = 1;
        this_->mState = 5;
    case 5: {
        this_->syncChild();
        f32 speed;
        s32 step;
        if (this_->mIsFastVariant == 1) {
            speed = 1.0f;
            step = 0x300;
        } else {
            speed = 0.5f;
            step = 0x100;
        }
        fn_801F714C(&this_->mMoveAngle, angle, 1, step);
        this_->mTargetVelX = speed * JMASinShort(this_->mMoveAngle);
        this_->mTargetVelY = speed * JMACosShort(this_->mMoveAngle);
        if (this_->mAnimTimer == 0) {
            this_->mAnimFrame++;
            if (this_->mAnimFrame > 7) {
                this_->mAnimFrame = 6;
            }
            this_->mAnimTimer = 8;
        }
        if (this_->mPhaseTimer != 0) {
            break;
        }
        this_->mState = 6;
    }
    case 6:
        this_->syncChild();
        this_->mCollisionMask = 0x1000;
        this_->stop();
        this_->mIsSurfaced = 0;
        this_->mAnimTimer = 4;
        this_->mField248 = 0;
        this_->mAnimFrame = 6;
        this_->mState = 7;
    case 7:
        this_->syncChild();
        if (this_->mAnimTimer == 0) {
            this_->mAnimFrame--;
            this_->mAnimTimer = 6;
            if (this_->mAnimFrame <= 0) {
                if (this_->mSandEmitter != 0) {
                    this_->spawn(0x1da);
                    this_->mSandEmitter->becomeInvalidEmitter();
                    this_->mSandEmitter = 0;
                }
                this_->mAnimTimer = 3;
                this_->mState = 0;
            }
        }
        break;
    }
    if (this_->mAnimTimer > 0) {
        this_->mAnimTimer--;
    }
    if (this_->mPhaseTimer > 0) {
        this_->mPhaseTimer--;
    }
    if (this_->mSubTimer > 0) {
        this_->mSubTimer--;
    }
}

// RDVR init (vtable slot 1)
extern "C" void fn_801831E0(RDVR* this_) {
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
    this_->mIsFastVariant = this_->mSpawnParam & 1;
    this_->mWaitSwitchFlag = (this_->mSpawnParam >> 8) & 1;
    this_->mAnimFrame = 0;
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
    this_->mTargetVelZ = 0.0f;
    this_->mTargetVelY = 0.0f;
    this_->mTargetVelX = 0.0f;
    this_->mVel.z = 0.0f;
    this_->mVel.y = 0.0f;
    this_->mVel.x = 0.0f;
    this_->mIsSurfaced = 0;
    this_->mMoveAngle = 0;
    this_->mFlag195 = 1;
    this_->mSandEmitter = 0;
    this_->mState = 0;
}

extern "C" void fn_8018330C(u32* out) {
    *out = ((u32*)lbl_8053AB10[0xb])[1];
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
