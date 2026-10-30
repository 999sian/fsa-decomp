// NZMI_800F3C10: .text 0x800F3C10-0x800F46C0 — Actor 'NZMI' (Nezumi / Rat Enemy).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C400[];

class NZMI_Actor {
public:
    virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20();
    virtual void vf24();

    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u32 mIsLargeVariant; // spawnParam & 1 (1 = 1.2x scale, chases players)
    /* 0x094 */ u8 _pad94[0xB0 - 0x94];
    /* 0x0B0 */ u32 mCollisionMask;
    /* 0x0B4 */ u8 _padB4[0x114 - 0xB4];
    /* 0x114 */ u32 mHitType;
    /* 0x118 */ u8 _pad118[0x198 - 0x118];
    /* 0x198 */ void* mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mState;          // 0 = wander, 1 = idle pause, 2 = chase player, 3 = retreat
    /* 0x234 */ u8 mIsIdlePose;      // 0 = running, 1 = standing
    /* 0x235 */ u8 mDirIndex;        // 0..3 cardinal direction index
    /* 0x236 */ u8 _pad236[2];
    /* 0x238 */ s32 mFrameTick;      // Counts 0..3 per animation frame toggle
    /* 0x23C */ s32 mStateTimer;
    /* 0x240 */ s32 mAnimFrame;      // 0 or 1
    /* 0x244 */ s32 mStateDuration;
};

extern "C" void* fn_800F3C10(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C400;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

struct NZMI_DrawKey {
    s32 a, b;
    NZMI_DrawKey() { a = -1; b = -1; }
};
struct NZMI_DrawParam {
    u8 map[16];       // 0x00
    NZMI_DrawKey key; // 0x10
    void* c;          // 0x18
    u8 palette;       // 0x1c
    u8 color;         // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;        // 0x28
    u8 f2c, f2d, f2e;
    s32 g;            // 0x30
    s32 h;            // 0x34
    s32 i;            // 0x38

    NZMI_DrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};
extern const char lbl_80463660[];
extern u8 lbl_80539E68[8];
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, NZMI_DrawParam* param, s32 a, f32 sx, f32 sy);

// NZMI draw (vtable slot 6)
extern "C" void fn_800F3C70(NZMI_Actor* this_) {
    NZMI_DrawParam param;
    f32 m[3][4];
    m[0][3] = 0.0f;
    m[1][3] = 0.0f;
    m[2][3] = 0.0f;
    if (this_->mIsLargeVariant != 0) {
        m[0][1] = 0.0f;
        m[0][0] = 1.2f;
        m[0][2] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = 1.2f;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = 1.2f;
        param.c = m;
    }
    fn_801F06F0(this_, lbl_80463660,
                0xA1 + this_->mAnimFrame + this_->mIsIdlePose * 2 + lbl_80539E68[this_->mDirIndex] * 4,
                &param, 0, 1.0f, 1.0f);
}

struct NZMI_Random {
    u32 seed;
    f32 get() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct NZMI_Game { u8 pad[0xb4]; NZMI_Random rnd; };
extern NZMI_Game* lbl_8053AAF8;
static inline s32 NZMI_rand(f32 r) { return r * lbl_8053AAF8->rnd.get(); }
static inline f32 NZMI_randg(NZMI_Game* g, f32 r) { return r * g->rnd.get(); }

extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" u8 fn_801F305C(void* this_);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" u8 fn_801F2B7C(void* this_, u32 a, s32 b, u32 c);
extern "C" u8 v17__5ActorFiPf(void* this_, s32 room, void* pos);
extern "C" void fn_801EEC98(void* this_, void* room, s16* a, s32* dir, f32* dist, s32* player, s32 b, s32 c);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 c);
extern f32 lbl_8049C3E0[4][2];

static inline void NZMI_move(NZMI_Actor* this_) {
    this_->mPosX += lbl_8049C3E0[lbl_80539E68[this_->mDirIndex]][0];
    this_->mPosY += lbl_8049C3E0[lbl_80539E68[this_->mDirIndex]][1];
}

static inline void NZMI_restartWander(NZMI_Actor* this_) {
    this_->mStateDuration = (s32)(50.0f * lbl_8053AAF8->rnd.get()) + 0x32;
    this_->mState = 1;
    this_->mStateTimer = 0;
}

static inline bool NZMI_seek(NZMI_Actor* this_) {
    s16 a = 0;
    f32 dist = 0.0f;
    s32 dir = 0;
    s32 player = 0;
    fn_801EEC98(this_, this_->mRoomHandle, &a, &dir, &dist, &player, 0, 0);
    if (player != -1 && dist < 120.0f) {
        this_->mState = 2;
        this_->mStateTimer = 0;
        for (u8 i = 0; i < 4; i++) {
            if (dir == lbl_80539E68[i]) {
                this_->mDirIndex = i;
                break;
            }
        }
        return true;
    }
    return false;
}

static inline void NZMI_face(NZMI_Actor* this_) {
    s16 a = 0;
    f32 dist = 0.0f;
    s32 dir = 0;
    s32 player = 0;
    fn_801EEC98(this_, this_->mRoomHandle, &a, &dir, &dist, &player, 0, 0);
    if (player != -1 && dist < 120.0f) {
        for (u8 i = 0; i < 4; i++) {
            if (dir == lbl_80539E68[i]) {
                this_->mDirIndex = i;
                break;
            }
        }
    }
}

// NZMI update (vtable slot 3)
extern "C" void fn_800F3E08(NZMI_Actor* this_) {
    if (fn_801F3D94(this_, 1) != 0 || fn_801F305C(this_)) {
        fn_801F2618(this_, 0, 0);
        return;
    }
    this_->mFrameTick += 1;
    if (this_->mFrameTick == 4) {
        this_->mAnimFrame += 1;
        if (this_->mAnimFrame == 2) {
            this_->mAnimFrame = 0;
        }
        this_->mFrameTick = 0;
    }
    bool hit;
    if (this_->mIsLargeVariant != 0) {
        hit = fn_801F2B7C(this_, this_->mHitType, -1, 4);
    } else {
        hit = fn_801F2B7C(this_, this_->mHitType, -1, 1);
    }
    u8 wall = fn_801F2618(this_, 0, 0);
    if (wall && v17__5ActorFiPf(this_, this_->mRoomId, &this_->mPosX) == 1) {
        this_->vf24();
        return;
    }
    switch (this_->mState) {
    case 0:
    case 3: {
        this_->mIsIdlePose = 0;
        if (wall) {
            this_->mDirIndex += 1;
        }
        this_->mDirIndex &= 3;
        if (this_->mIsLargeVariant != 0 && this_->mState == 0) {
            if (NZMI_seek(this_)) {
                return;
            }
        }
        NZMI_move(this_);
        this_->mStateTimer += 1;
        if (this_->mStateTimer == this_->mStateDuration) {
            NZMI_restartWander(this_);
        }
        break;
    }
    case 1:
        this_->mIsIdlePose = 1;
        this_->mStateTimer += 1;
        if (this_->mStateTimer == this_->mStateDuration) {
            this_->mStateDuration = NZMI_rand(80.0f) + 10;
            this_->mDirIndex = NZMI_randg(lbl_8053AAF8, 4.0f);
            this_->mState = 0;
            fn_801F0E34(this_, 0x400A6, 0);
            this_->mStateTimer = 0;
        }
        break;
    case 2: {
        this_->mDirIndex &= 3;
        NZMI_move(this_);
        if ((this_->mStateTimer & 0x1111) == 0) {
            NZMI_face(this_);
        }
        if (hit == true) {
            this_->mStateDuration = 100;
            this_->mState = 3;
            this_->mStateTimer = 0;
        } else {
            this_->mStateTimer += 1;
            if (this_->mStateTimer == 100 || wall) {
                NZMI_restartWander(this_);
            }
        }
        break;
    }
    }
}

// NZMI init (vtable slot 1)
extern "C" void fn_800F43D0(NZMI_Actor* this_) {
    this_->mBounds60[0] = -8.0f;
    this_->mBounds60[1] = -8.0f;
    this_->mBounds60[2] = 8.0f;
    this_->mBounds60[3] = 8.0f;
    this_->mBounds80[0] = -10.0f;
    this_->mBounds80[1] = -10.0f;
    this_->mBounds80[2] = 10.0f;
    this_->mBounds80[3] = 10.0f;
    this_->mCollisionMask = 0x11101;
    this_->mAnimFrame = 0;
    this_->mDirIndex = 0;
    this_->mState = 1;
    this_->mFrameTick = 0;
    this_->mStateTimer = 0;
    this_->mIsIdlePose = 0;
    this_->mStateDuration = NZMI_rand(50.0f) + 0x32;
    this_->mIsLargeVariant &= 1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
