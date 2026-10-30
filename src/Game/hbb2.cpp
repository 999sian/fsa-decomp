// TU 801A8194-801A908C — Actor 'HBB2' (Orbiting Fireball / Boss Trail Enemy with 39 Afterimages).
#include "types.h"
#include "Game/ItemBase.h"
#include <math.h>

static inline f64 sqrtStep(f64 tmpd, f32 mag) {
    return tmpd * 0.5 * (3.0 - mag * (tmpd * tmpd));
}
static inline f32 dolsqrtfull(f32 mag) {
    if (mag > 0.0f) {
        f64 tmpd = __frsqrte(mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        return mag * tmpd;
    } else if (mag < 0.0) {
        return NAN;
    } else if (fpclassify(mag) == 1) {
        return NAN;
    } else {
        return mag;
    }
}
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* __vt__4HBB2[];

struct Hbb2Vec { f32 x, y, z; };

struct Hbb2Actor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ Hbb2Vec pos;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x108 - 0x94];
    /* 0x108 */ s32 mSortPriority;
    /* 0x10C */ u8 _pad10C[8];
    /* 0x114 */ s32 mHitType;
    /* 0x118 */ u32 mField118;
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 mField11D;
    /* 0x11E */ u8 mDrawFlag11E;
    /* 0x11F */ u8 _pad11F[0x190 - 0x11F];
    /* 0x190 */ s32 mField190;
    /* 0x194 */ u32 mField194;
    /* 0x198 */ s32 mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mState;          // 0 = init orbit, 1 = orbiting, 2 = dying/fading
    /* 0x234 */ s32 mTimers[3];      // [0] = anim timer (+0x234), [1] = trail shift timer (+0x238), [2] = +0x23C
    /* 0x240 */ s32 mField240;
    /* 0x244 */ s32 mField244;
    /* 0x248 */ s32 mField248;
    /* 0x24C */ s32 mField24C;
    /* 0x250 */ s32 mField250;
    /* 0x254 */ s32 mField254;
    /* 0x258 */ s32 mIsActivated;
    /* 0x25C */ s32 mWasUnpaused;
    /* 0x260 */ s32 mAnimFrame;      // 0..2 (sprite 0x155 + mAnimFrame)
    /* 0x264 */ s32 mHealth;
    /* 0x268 */ u16 mOrbitAngle;
    /* 0x26A */ u16 _pad26A;
    /* 0x26C */ f32 mScale;          // 1.2f
    /* 0x270 */ f32 mOrbitRadius;    // 72.0f
    /* 0x274 */ f32 mTrailAlpha;     // 255.0f
    /* 0x278 */ f32 mMoveStep;
    /* 0x27C */ Hbb2Vec prev;
    /* 0x288 */ Hbb2Vec prev2;
    /* 0x294 */ Hbb2Vec trail[40];
};

extern "C" void* fn_801A8194(Hbb2Actor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = __vt__4HBB2;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern const char lbl_80468518[];
extern "C" void fn_801F02BC(void* actor, const char* file, s32 idx, f32 sx, f32 sy, DrawRec* rec, s32 a, s32 b, s32 c);

struct Hbb2Mtx {
    Hbb2Mtx() {
        m[0][3] = 0.0f;
        m[1][3] = 0.0f;
        m[2][3] = 0.0f;
    }
    void setScale(f32 s) {
        m[0][0] = s;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = s;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = s;
    }
    f32 m[3][4];
};

struct Hbb2VT {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual u8 check();
};

// HBB2 draw (vtable slot 6): renders head plus 39 fading trail afterimages
extern "C" void fn_801A81F4(Hbb2Actor* this_) {
    DrawRec rec;
    Hbb2Mtx mtx;
    if (this_->mIsActivated == 0 && (this_->mSpawnParam >> 27) != 0) {
        if (!((Hbb2VT*)this_)->check()) {
            return;
        }
    }
    rec.ids[4] = 3;
    rec.b1d = 2;
    mtx.setScale(this_->mScale);
    rec.w18 = &mtx;
    fn_801F02BC(this_, lbl_80468518, this_->mAnimFrame + 0x155, 1.0f, 1.0f, &rec, 7, 0, 0);
    f32 sx, sy, sz;
    f32 scale = this_->mScale;
    f32 alpha = this_->mTrailAlpha;
    s32 frame = this_->mAnimFrame;
    Hbb2Actor* h = this_;
    rec.ids[4] = 5;
    rec.b1d = 1;
    sx = h->pos.x;
    sy = h->pos.y;
    sz = h->pos.z;
    for (s32 i = 1; i < 40; i++) {
        if (h->trail[i].z) {
            scale *= 0.95f;
            if (scale < 0.5f) {
                scale = 0.5f;
            }
            alpha -= 2.0f;
            if (alpha < 0.0f) {
                alpha = 0.0f;
            }
            ((u8*)&rec.w10)[3] = (s32)alpha;
            mtx.setScale(scale);
            rec.w18 = &mtx;
            if (--frame < 0) {
                frame = 2;
            }
            h->pos.x = h->trail[i].x;
            h->pos.y = h->trail[i].y;
            h->pos.z = h->trail[i].z;
            fn_801F02BC(this_, lbl_80468518, frame + 0x155, 1.0f, 1.0f, &rec, 7, 0, 0);
        }
    }
    h->pos.x = sx;
    h->pos.y = sy;
    h->pos.z = sz;
}

extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void* mgr);
extern "C" void fn_801EEC98(void* self, s32 room, u16* ang, s32* dir, f32* dist, s32* player, s32 b, s32 c);
extern "C" Hbb2Vec* fn_8023E724(s32 idx);
extern "C" u8 fn_801F2B7C(void* self, s32 a, s32 holder, s32 b);
extern "C" void fn_801F71A4(f32* v, f32 target, f32 rate, f32 step);
extern "C" s32 fn_801F3D94(void* self, s32 a);
extern "C" s32 fn_801F285C(void* self, s32 a, s32 b, s32 c, s32 idx);
extern "C" s32 fn_80138A30(void* game);
extern "C" s32 fn_8022CAF8(s32 player);
extern "C" u8 fn_801F2FAC(void* self);
extern "C" void fn_801F0E34(void* self, u32 se, s32 b);
extern "C" void* fn_801F856C(void);
extern "C" void fn_801F8544(void* mgr, u32 tag, s32 room, Hbb2Vec* pos, s32 flags);
extern void* lbl_8053AAF8;

struct Hbb2VT2 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void kill();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual u8 check();
};

static inline f32 hbbSin(s16 v) { return JMath::sincosTable_.mTable[static_cast<u16>(v) >> (16U - 11)].first; }
static inline f32 hbbCos(s16 v) { return JMath::sincosTable_.mTable[static_cast<u16>(v) >> (16U - 11)].second; }

// HBB2 update (vtable slot 3)
extern "C" void fn_801A8554(Hbb2Actor* this_) {
    Hbb2Actor* h = this_;
    s32 i;
    s32 player = -1;
    if (this_->mIsActivated == 0 && (this_->mSpawnParam >> 27) != 0) {
        if (!((Hbb2VT2*)this_)->check()) {
            return;
        }
        this_->mIsActivated = 1;
    }
    if (fn_802DCD0C(fn_802D6A9C())) {
        if (this_->mWasUnpaused == 1) {
            this_->mActiveFlag = 0;
            return;
        }
    } else {
        this_->mWasUnpaused = 1;
    }
    fn_801EEC98(this_, this_->mRoomHandle, 0, 0, 0, &player, 0, 1);
    if (this_->mState == 1 && this_->mTimers[1] == 0) {
        *(JGeometry::TVec3f*)&h->trail[0] = *(JGeometry::TVec3f*)&h->pos;
        for (i = 39; i > 0; i--) {
            h->trail[i].x = h->trail[i - 1].x;
            h->trail[i].y = h->trail[i - 1].y;
            h->trail[i].z = h->trail[i - 1].z;
        }
        this_->mTimers[1] = 3;
    }
    if (this_->mHealth > 0) {
        f32 sx = h->pos.x;
        f32 sy = h->pos.y;
        f32 sz = h->pos.z;
        this_->mBounds60[0] = -2.0f;
        this_->mBounds60[1] = -2.0f;
        this_->mBounds60[2] = 2.0f;
        this_->mBounds60[3] = 2.0f;
        for (i = 39; i > 0; i--) {
            if (player >= 0) {
                f32 dx = fn_8023E724(player)->x - h->trail[i].x;
                f32 dy = fn_8023E724(player)->y - (h->trail[i].y - h->trail[i].z);
                Hbb2Vec* pp = fn_8023E724(player);
                h->prev2.x = pp->x;
                h->prev2.y = pp->y;
                h->prev2.z = pp->z;
                if (dolsqrtfull(dx * dx + dy * dy) < 16.0f) {
                    f32 ty = h->trail[i].y;
                    h->pos.x = h->trail[i].x;
                    h->pos.y = ty;
                    h->pos.z = 0.0f;
                    fn_801F2B7C(this_, this_->mHitType, -1, 5);
                }
            }
        }
        this_->mBounds60[0] = -10.0f;
        this_->mBounds60[1] = -10.0f;
        this_->mBounds60[2] = 10.0f;
        this_->mBounds60[3] = 10.0f;
        h->pos.x = sx;
        h->pos.y = sy;
        h->pos.z = sz;
    }
    if (this_->mState == 2) {
        fn_801F71A4(&this_->mTrailAlpha, 0.0f, 0.3f, 5.0f);
    }
    if (fn_801F3D94(this_, 0) != 0) {
        return;
    }
    if (this_->mHealth > 0) {
        for (i = 0; i < 4; i++) {
            s32 pl = fn_801F285C(this_, 0, 0, 1, i);
            if (pl >= 0
                && (fn_80138A30(lbl_8053AAF8) > 1 || fn_8022CAF8(pl) == 1 || fn_8022CAF8(pl) == 0)
                && fn_801F2FAC(this_)) {
                this_->mHealth -= 10000 - this_->mSortPriority;
                if (this_->mHealth <= 0) {
                    fn_801F0E34(this_, 0x40003, 0);
                    this_->mHealth = 0;
                    this_->mState = 2;
                } else {
                    fn_801F0E34(this_, 0x40002, 0);
                    this_->mState = 0;
                }
                return;
            }
        }
    }
    if (this_->mHealth > 0 && this_->mState != 0) {
        fn_801F71A4(&h->pos.x, h->prev.x, 1.0f, this_->mMoveStep);
        fn_801F71A4(&h->pos.y, h->prev.y, 1.0f, this_->mMoveStep);
        fn_801F71A4(&this_->mMoveStep, 10.0f, 0.3f, 1.0f);
    }
    fn_801F71A4(&h->pos.z, h->prev.z, 0.3f, 1.0f);
    h->prev.z = 16.0f;
    fn_801F2B7C(this_, -100, -1, 1);
    fn_801F0E34(this_, 0x400ec, 0);
    switch (this_->mState) {
    case 0:
        fn_801F0E34(this_, 0x4000f, 0);
        fn_801F0E34(this_, 0x400a9, 0);
        if (player >= 0) {
            fn_801EEC98(this_, this_->mRoomHandle, &this_->mOrbitAngle, 0, 0, 0, player, 2);
            this_->mOrbitAngle += 0x8000;
        }
        this_->mState = 1;
        // fallthrough
    case 1:
        if (player >= 0) {
            h->prev.x = this_->mOrbitRadius * hbbSin(this_->mOrbitAngle) + fn_8023E724(player)->x;
            f32 py = fn_8023E724(player)->y;
            h->prev.y = this_->mOrbitRadius * hbbCos(this_->mOrbitAngle) + py;
        } else {
            h->prev.x = this_->mOrbitRadius * hbbSin(this_->mOrbitAngle) + h->prev2.x;
            h->prev.y = this_->mOrbitRadius * hbbCos(this_->mOrbitAngle) + h->prev2.y;
        }
        h->prev.y += 16.0f;
        this_->mOrbitAngle += 0x200;
        if (this_->mTimers[0] <= 0) {
            this_->mAnimFrame++;
            if (this_->mAnimFrame > 2) {
                this_->mAnimFrame = 0;
            }
            this_->mTimers[0] = 6;
        }
        break;
    case 2:
        if (this_->mTrailAlpha < 1.0f) {
            for (i = 0; i < 40; i++) {
                fn_801F8544(fn_801F856C(), 'RUPY', this_->mRoomId, &h->trail[i], 0);
            }
            ((Hbb2VT2*)this_)->kill();
        }
        break;
    }
    for (i = 0; i < 3; i++) {
        s32* t = (s32*)((char*)this_ + i * 4);
        if (t[0x234 / 4] > 0) {
            t[0x234 / 4]--;
        }
    }
}

// HBB2 init (vtable slot 1)
extern "C" void fn_801A8CB8(Hbb2Actor* this_) {
    this_->mBounds60[0] = -10.0f;
    this_->mBounds60[1] = -10.0f;
    this_->mBounds60[2] = 10.0f;
    this_->mBounds60[3] = 10.0f;
    this_->mBounds80[0] = 0.0f;
    this_->mBounds80[1] = 0.0f;
    this_->mBounds80[2] = 0.0f;
    this_->mBounds80[3] = 0.0f;
    this_->mField240 = 0;
    this_->mField244 = 0;
    this_->mField248 = 0;
    this_->mField24C = 0;
    this_->mField250 = 0;
    this_->mField254 = 0;
    this_->mIsActivated = 0;
    this_->mWasUnpaused = 0;
    this_->mTimers[0] = 0;
    this_->mTimers[1] = 0;
    this_->mTimers[2] = 0;
    this_->mOrbitRadius = 72.0f;
    this_->mDrawFlag11E = 1;
    this_->mScale = 1.2f;
    this_->mTrailAlpha = 255.0f;
    Hbb2Actor* h = this_;
    h->prev.x = h->pos.x;
    h->prev.y = h->pos.y;
    h->prev.z = h->pos.z;
    h->prev2.x = h->pos.x;
    h->prev2.y = h->pos.y;
    h->prev2.z = h->pos.z;
    for (int i = 0; i < 40; i++) {
        h->trail[i].x = h->pos.x;
        h->trail[i].y = h->pos.y;
        h->trail[i].z = h->pos.z;
    }
    this_->mOrbitAngle = 0;
    this_->mField190 = 0;
    this_->mMoveStep = 0.0f;
    this_->mHealth = this_->mSortPriority;
    this_->mSortPriority = 10000;
    this_->mAnimFrame = 0;
    this_->mState = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
