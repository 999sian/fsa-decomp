// TU 0x80438540-0x80438c68 — Actor 'LIMT' (Countdown Digit / Timer Overlay Indicator).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B174C[];

struct LimtDrawParam {
    LimtDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = NULL;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};

struct LimtActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3<f32> mPos;
    /* 0x018 */ u8 _pad18[0x3C - 0x18];
    /* 0x03C */ JGeometry::TVec3<f32> mVel;
    /* 0x048 */ u8 _pad48[0x90 - 0x48];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 mField11D;
    /* 0x11E */ u8 mDrawFlag11E;
    /* 0x11F */ u8 _pad11F[0x198 - 0x11F];
    /* 0x198 */ s32 mOwnerId;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mState;
    /* 0x234 */ s32 mTimers[3];    // [0] = pulse timer (+0x234)
    /* 0x240 */ s32 mField240;
    /* 0x244 */ s32 mField244;
    /* 0x248 */ s32 mField248;
    /* 0x24C */ s32 mCountStep;    // 0..4 digit index into lbl_804B1738 ('TIMG' textures)
    /* 0x250 */ s32 mTargetId;     // Actor slot or player index (0..3)
    /* 0x254 */ f32 mOffsetY;
    /* 0x258 */ f32 mField258;
    /* 0x25C */ f32 mScaleX;
    /* 0x260 */ f32 mScaleY;
    /* 0x264 */ f32 mScaleZ;
    /* 0x268 */ f32 mBaseScaleX;
    /* 0x26C */ f32 mBaseScaleY;
    /* 0x270 */ f32 mBaseScaleZ;
};

extern "C" void* fn_80438540(LimtActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804B174C;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_804030C4(u32 type, const char* name);
extern "C" void fn_802F745C(void* mgr, void* pos, void* tex, LimtDrawParam* prm);
extern "C" char* lbl_8053AB10;
extern const char* lbl_804B1738[];

// LIMT draw (vtable slot 6)
extern "C" void fn_804385A0(LimtActor* this_) {
    LimtDrawParam prm;
    f32 mtx[3][4];
    prm.reset();
    s32 kind = this_->mCountStep;
    if (kind > 4 || kind < 0) return;
    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    prm.m4C = 1;
    prm.m4D = 7;
    f32 sy = this_->mScaleY;
    f32 sx = this_->mScaleX;
    mtx[0][0] = sx;
    mtx[0][1] = 0.0f;
    mtx[0][2] = 0.0f;
    mtx[1][0] = 0.0f;
    mtx[1][1] = sy;
    mtx[1][2] = 0.0f;
    mtx[2][0] = 0.0f;
    mtx[2][1] = 0.0f;
    mtx[2][2] = sy;
    prm.mMtx = mtx;
    void* tex = fn_804030C4('TIMG', lbl_804B1738[this_->mCountStep]);
    if (this_->mRoomId < 8) {
        fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), &this_->mPos, tex, &prm);
    }
}

extern "C" void* fn_801F856C(void);
extern "C" LimtActor* fn_801F666C(void* mgr, s32 id);
extern "C" u8 fn_8023F264(s32 id);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 id);
extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);

static inline void limtKill(LimtActor* p) { p->mActiveFlag = 0; }

// LIMT update (vtable slot 3)
extern "C" void fn_8043875C(LimtActor* this_) {
    for (int i = 0; i < 3; i++) {
        if (this_->mTimers[i] > 0) {
            this_->mTimers[i]--;
        }
    }
    this_->mPos.add(this_->mVel);
    LimtActor* target;
    f32 x, y, z;
    switch (this_->mState) {
    case 0:
        this_->mState = 1;
    case 1:
        if ((this_->mSpawnParam & 0xF) == 0) {
            LimtActor* t = fn_801F666C(fn_801F856C(), this_->mTargetId);
            target = t;
            if (t == NULL || this_->mCountStep < 0) {
                limtKill(this_);
                break;
            }
        } else {
            s32 id = this_->mTargetId;
            if (id < 0 || id > 3 || !fn_8023F264(id) || this_->mCountStep < 0) {
                limtKill(this_);
                break;
            }
        }
        if ((this_->mSpawnParam & 0xF) == 0) {
            x = target->mPos.x;
            y = target->mPos.y;
            z = target->mPos.z;
        } else {
            JGeometry::TVec3<f32>* v = fn_8023E724(this_->mTargetId);
            x = v->x;
            y = v->y;
            z = v->z;
        }
        y += this_->mOffsetY;
        s32 n = this_->mCountStep;
        if (n >= 0 && n < 5) {
            y -= (f32)(4 - n);
            if (this_->mTimers[0] == 0) {
                f32 sc = this_->mBaseScaleX;
                sc *= 0.3f * (f32)(5 - n) + 1.0f;
                if (n != 0) {
                    this_->mTimers[0] = n * 10;
                }
                this_->mScaleX = sc;
                this_->mScaleY = sc;
                this_->mScaleZ = sc;
            }
            if (this_->mCountStep == 0) {
                this_->mScaleX = 0.5f;
                this_->mScaleY = 0.5f;
                this_->mScaleZ = 0.5f;
                this_->mBaseScaleX = 0.5f;
                this_->mBaseScaleY = 0.5f;
                this_->mBaseScaleZ = 0.5f;
            }
            fn_801F71A4(&this_->mScaleX, this_->mBaseScaleX, 0.2f, 0.4f);
            this_->mScaleY = this_->mScaleX;
        }
        this_->mPos.x = x;
        this_->mPos.y = y;
        this_->mPos.z = z;
        break;
    }
}

// LIMT init (vtable slot 1)
extern "C" void fn_804389C8(LimtActor* this_) {
    this_->mTimers[0] = 0;
    this_->mTimers[1] = 0;
    this_->mTimers[2] = 0;
    this_->mField240 = 0;
    this_->mField244 = 0;
    this_->mField248 = 0;
    this_->mTargetId = this_->mOwnerId;
    if (this_->mSpawnParam & 0xF) {
        this_->mTargetId = this_->mSpawnParam - 1;
    }
    this_->mCountStep = 4;
    this_->mField258 = 0.0f;
    this_->mOffsetY = 0.0f;
    this_->mScaleX = 0.5f;
    this_->mScaleY = 0.5f;
    this_->mScaleZ = 0.5f;
    this_->mBaseScaleX = 0.5f;
    this_->mBaseScaleY = 0.5f;
    this_->mBaseScaleZ = 0.5f;
    this_->mDrawFlag11E = 1;
    this_->mState = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
