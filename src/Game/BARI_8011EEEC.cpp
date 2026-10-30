// BARI_8011EEEC: .text 0x8011EEEC-0x8011FFB8 — Actor 'BARI' (Electric / Energy Barrier).
#include "types.h"
#include "JSystem/JParticle/JPAEmitter.h"

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* __ct__5ActorFv(void* this_);
extern void* lbl_8049DEE8[];

extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* p);

static inline void stopEmitter(JPABaseEmitter* e) {
    if (e != 0) {
        e->becomeInvalidEmitter();
    }
}

extern "C" JPABaseEmitter* fn_8013CC50(u32 id, void* pos, s32 type, s32 p4, s32 p5, u32 p6, u32 p7, u32 p8, f32 f);
extern "C" void fn_8013CAA4(JPABaseEmitter* e, f32 angle);

struct Bari {
    /* 0x000 */ void* vtbl;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3<f32> mPos;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ f32 mBounds70[4];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0xB0 - 0x94];
    /* 0x0B0 */ u32 mCollisionMask;
    /* 0x0B4 */ u32 mFieldB4;
    /* 0x0B8 */ u32 mFieldB8;
    /* 0x0BC */ u32 mFieldBC;
    /* 0x0C0 */ u8 _padC0[0xD8 - 0xC0];
    /* 0x0D8 */ u32 mDamageTimer;
    /* 0x0DC */ u8 _padDC[0x114 - 0xDC];
    /* 0x114 */ s32 mHitType;
    /* 0x118 */ u32 mHitSubType;
    /* 0x11C */ u8 _pad11C[0x198 - 0x11C];
    /* 0x198 */ u32 mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mState;          // 0 = active barrier, 1 = transition off, 2 = inactive, 3 = breaking, 4 = destroyed
    /* 0x234 */ s32 mOrientation;    // 0 = vertical, 1 = horizontal (from (spawnParam >> 4) & 0xF)
    /* 0x238 */ s32 mSwitchFlagId;   // Unpacked from (spawnParam >> 22) & 0x1F
    /* 0x23C */ s32 mBreakTimer;
    /* 0x240 */ u8 mToggleable;      // Unpacked from spawnParam & 1
    /* 0x241 */ u8 mStrongVariant;   // Unpacked from (spawnParam >> 1) & 1
    /* 0x242 */ u8 _pad242[2];
    /* 0x244 */ JPABaseEmitter* mEmitters[3];
    /* 0x250 */ JPABaseEmitter* mPostEmitterA;
    /* 0x254 */ JPABaseEmitter* mPostEmitterB;
};

extern "C" void* fn_802D6A9C();
extern "C" void fn_802D8050(void* cfg, s32 id, s32 a, s32 b);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 a);
extern "C" void fn_801F0D20(void* this_, s32 a);
extern "C" void detach__5ActorFv(void* this_);

struct BVec {
    f32 x, y, z;
    BVec(f32 x_, f32 y_, f32 z_) { x = x_; y = y_; z = z_; }
};

static inline JPABaseEmitter* createRow(Bari* p, s32 i) {
    return fn_8013CC50(p->mRoomId, &BVec(p->mPos.x, 16.0f * (i - 1) + p->mPos.y, 0.0f), 0x125, 0, 0, 0, 0, 1, 1.0f);
}

static inline JPABaseEmitter* createA(Bari* p, s32 id) {
    BVec* pos;
    switch (p->mOrientation) {
    case 1:
        pos = &BVec(p->mPos.x, 32.0f + p->mPos.y, p->mPos.z);
        break;
    default:
        pos = &BVec(p->mPos.x - 32.0f, p->mPos.y, p->mPos.z);
        break;
    }
    return fn_8013CC50(p->mRoomId, pos, id, 0, 0, 0, 0, 1, 1.0f);
}

static inline JPABaseEmitter* createB(Bari* p, s32 id) {
    BVec* pos;
    switch (p->mOrientation) {
    case 1:
        pos = &BVec(p->mPos.x, p->mPos.y - 32.0f, p->mPos.z);
        break;
    default:
        pos = &BVec(32.0f + p->mPos.x, p->mPos.y, p->mPos.z);
        break;
    }
    return fn_8013CC50(p->mRoomId, pos, id, 0, 0, 0, 0, 1, 1.0f);
}

struct BariVt {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual u8 v11();
};

extern "C" void v03__5ActorFv(void* this_);
extern "C" u8 fn_801F2DB4(void* this_, u32 a, u32 b, s32 c);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" void fn_80239914(void* box, u32 a, u32 b);
extern "C" void fn_80230FD0(s32 player, s32 id);

extern "C" void fn_8011EEEC(Bari* p);
extern "C" void fn_8011F314(Bari* p);
extern "C" void fn_8011F5C0(Bari* p, s32 state);

extern "C" void fn_8011EEEC(Bari* p) {
    switch (p->mOrientation) {
    case 1: {
        JPABaseEmitter* e1 = createA(p, 0xca);
        JPABaseEmitter* e2 = createB(p, 0xca);
        if (e1 != 0) {
            fn_8013CAA4(e1, 1.5707964f);
        }
        if (e2 != 0) {
            fn_8013CAA4(e2, 1.5707964f);
        }
        break;
    }
    default:
        if (p->mStrongVariant) {
            for (s32 i = 0; i < 3; i++) {
                createRow(p, i);
            }
            createA(p, 0x126);
            createB(p, 0x126);
        } else {
            createA(p, 0xca);
            createB(p, 0xca);
        }
        break;
    }
}

extern "C" void fn_8011F314(Bari* p) {
    s32 i;
    for (i = 0; i < 3; i++) {
        p->mEmitters[i] = fn_8013CC50(p->mRoomId, &p->mPos, 200, 0, 0, 0, 0, 1, 1.0f);
    }
    p->mPostEmitterA = fn_8013CC50(p->mRoomId, &p->mPos, 201, 0, 0, 0, 0, 1, 1.0f);
    p->mPostEmitterB = fn_8013CC50(p->mRoomId, &p->mPos, 201, 0, 0, 0, 0, 1, 1.0f);
    JGeometry::TVec3<f32> a(p->mPos);
    JGeometry::TVec3<f32> b(p->mPos);
    switch (p->mOrientation) {
    case 1:
        for (i = 0; i < 3; i++) {
            a.x = p->mPos.x + 16.0f * (i - 1);
            p->mEmitters[i]->setGlobalTranslation(a);
            fn_8013CAA4(p->mEmitters[i], 1.5707964f);
        }
        b.y -= 32.0f;
        p->mPostEmitterA->setGlobalTranslation(b);
        fn_8013CAA4(p->mPostEmitterA, 1.5707964f);
        b.y += 64.0f;
        p->mPostEmitterB->setGlobalTranslation(b);
        fn_8013CAA4(p->mPostEmitterB, 1.5707964f);
        break;
    case 0:
    default:
        for (i = 0; i < 3; i++) {
            a.y = p->mPos.y + 16.0f * (i - 1);
            p->mEmitters[i]->setGlobalTranslation(a);
        }
        b.x -= 32.0f;
        p->mPostEmitterA->setGlobalTranslation(b);
        b.x += 64.0f;
        p->mPostEmitterB->setGlobalTranslation(b);
        break;
    }
}

extern "C" void fn_8011F5C0(Bari* p, s32 state) {
    p->mState = state;
    switch (state) {
    case 0:
        p->mCollisionMask = 0xa040304;
        if (p->mToggleable) {
            p->mEmitters[0]->clearStatus(JPAEMIT_StopDraw);
            p->mEmitters[1]->clearStatus(JPAEMIT_StopDraw);
            p->mEmitters[2]->clearStatus(JPAEMIT_StopDraw);
            p->mPostEmitterA->clearStatus(JPAEMIT_StopDraw);
            p->mPostEmitterB->clearStatus(JPAEMIT_StopDraw);
            s32 id = p->mSwitchFlagId;
            if (id > 0) {
                fn_802D8050(fn_802D6A9C(), id, 0, 0xff);
            }
        }
        break;
    case 1:
        fn_8011EEEC(p);
        p->mEmitters[0]->setStatus(JPAEMIT_StopDraw);
        p->mEmitters[1]->setStatus(JPAEMIT_StopDraw);
        p->mEmitters[2]->setStatus(JPAEMIT_StopDraw);
        p->mPostEmitterA->setStatus(JPAEMIT_StopDraw);
        p->mPostEmitterB->setStatus(JPAEMIT_StopDraw);
        p->mBreakTimer = 0;
        break;
    case 2: {
        fn_801F0E34(p, 0x50011, 0);
        p->mCollisionMask = 0;
        s32 id = p->mSwitchFlagId;
        if (id > 0) {
            fn_802D8050(fn_802D6A9C(), id, 1, 0xff);
        }
        break;
    }
    case 3:
        if (!p->mStrongVariant) {
            fn_801F0E34(p, 0x50011, 0);
        }
        p->mBreakTimer = 0;
        fn_8011EEEC(p);
        for (s32 i = 0; i < 3; i++) {
            stopEmitter(p->mEmitters[i]);
        }
        stopEmitter(p->mPostEmitterA);
        stopEmitter(p->mPostEmitterB);
        break;
    case 4: {
        s32 id = p->mSwitchFlagId;
        if (id > 0) {
            fn_802D8050(fn_802D6A9C(), id, 1, 0xff);
        }
        if (!p->mStrongVariant) {
            fn_801F0D20(p, 3);
        }
        detach__5ActorFv(p);
        break;
    }
    }
}

// BARI update (vtable slot 3)
extern "C" void fn_8011F850(Bari* p) {
    v03__5ActorFv(p);
    f32 box[4];
    box[0] = p->mBounds80[0];
    box[1] = p->mBounds80[1];
    box[2] = p->mBounds80[2];
    box[3] = p->mBounds80[3];
    box[0] += p->mPos.x;
    box[1] += p->mPos.y;
    box[2] += p->mPos.x;
    box[3] += p->mPos.y;
    switch (p->mState) {
    case 0: {
        fn_801F0E34(p, 0x50010, 0);
        if (((BariVt*)p)->v11()) {
            if (p->mToggleable) {
                fn_8011F5C0(p, 1);
            } else {
                fn_8011F5C0(p, 3);
            }
            break;
        }
        if (fn_801F2DB4(p, 'NULL', 'NULL', 0)) {
            p->mDamageTimer = 0;
        }
        u8 hit = fn_801F2B7C(p, p->mHitType, -1, 10);
        if (!hit) {
            fn_80239914(box, p->mRoomId, p->mRoomHandle);
        } else {
            for (s32 i = 0; i < 4; i++) {
                if (hit & (1 << i)) {
                    fn_80230FD0(i, 0x20042);
                }
            }
        }
        break;
    }
    case 1:
        if (!p->mStrongVariant) {
            fn_8011F5C0(p, 2);
        } else {
            p->mBreakTimer++;
            if (p->mBreakTimer >= 55) {
                p->mBreakTimer = 0;
                fn_8011F5C0(p, 2);
            }
        }
        break;
    case 2:
        if (!((BariVt*)p)->v11()) {
            fn_8011F5C0(p, 0);
        }
        break;
    case 3:
        if (p->mStrongVariant) {
            p->mBreakTimer++;
            if (p->mBreakTimer == 55) {
                fn_801F0E34(p, 0x50011, 0);
                fn_8011F5C0(p, 4);
            }
        } else if (p->mEmitters[0]->isEnableDeleteEmitter()) {
            fn_8011F5C0(p, 4);
        }
        break;
    case 4:
        break;
    }
}

// BARI init (vtable slot 1)
extern "C" void fn_8011FAF0(Bari* p) {
    v01__5ActorFv(p);
    if ((p->mSpawnParam & 1) == 1) {
        p->mToggleable = 1;
    }
    if (((p->mSpawnParam >> 1) & 1) == 1) {
        p->mStrongVariant = 1;
    }
    p->mOrientation = (p->mSpawnParam >> 4) & 0xf;
    p->mSwitchFlagId = (p->mSpawnParam >> 22) & 0x1f;
    switch (p->mOrientation) {
    case 1:
        p->mBounds60[0] = -16.0f;
        p->mBounds60[1] = -40.0f;
        p->mBounds60[2] = 16.0f;
        p->mBounds60[3] = 40.0f;
        p->mBounds70[0] = p->mBounds60[0];
        p->mBounds70[1] = p->mBounds60[1];
        p->mBounds70[2] = p->mBounds60[2];
        p->mBounds70[3] = p->mBounds60[3];
        p->mBounds80[0] = -14.0f;
        p->mBounds80[1] = -40.0f;
        p->mBounds80[2] = 14.0f;
        p->mBounds80[3] = 40.0f;
        break;
    case 0:
    default:
        p->mBounds60[0] = -40.0f;
        p->mBounds60[1] = -16.0f;
        p->mBounds60[2] = 40.0f;
        p->mBounds60[3] = 16.0f;
        p->mBounds70[0] = p->mBounds60[0];
        p->mBounds70[1] = p->mBounds60[1];
        p->mBounds70[2] = p->mBounds60[2];
        p->mBounds70[3] = p->mBounds60[3];
        p->mBounds80[0] = -40.0f;
        p->mBounds80[1] = -14.0f;
        p->mBounds80[2] = 40.0f;
        p->mBounds80[3] = 14.0f;
        break;
    }
    p->mHitType = 2;
    p->mHitSubType = 2;
    p->mFieldB8 = 1;
    p->mFieldBC = 3;
    p->mCollisionMask = 0xa040304;
    fn_8011F314(p);
    if (((BariVt*)p)->v11()) {
        fn_8011F5C0(p, 1);
    }
}

extern "C" void* fn_8011FC84(Bari* p, s16 flag) {
    if (p != 0) {
        p->vtbl = lbl_8049DEE8;
        for (s32 i = 0; i < 3; i++) {
            fn_801EE434(p->mEmitters[i]);
            p->mEmitters[i] = 0;
        }
        fn_801EE434(p->mPostEmitterA);
        p->mPostEmitterA = 0;
        fn_801EE434(p->mPostEmitterB);
        p->mPostEmitterB = 0;
        __dt__5ActorFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void* fn_8011FD28(Bari* this_) {
    __ct__5ActorFv(this_);
    this_->vtbl = lbl_8049DEE8;
    this_->mState = 0;
    this_->mOrientation = 0;
    this_->mSwitchFlagId = 0;
    this_->mBreakTimer = 0;
    this_->mToggleable = 0;
    this_->mStrongVariant = 0;
    this_->mPostEmitterA = 0;
    this_->mPostEmitterB = 0;
    this_->mEmitters[0] = 0;
    this_->mEmitters[1] = 0;
    this_->mEmitters[2] = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
