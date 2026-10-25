#include "Game/Actor.h"
extern const f32 lbl_805425CC;
extern const f32 lbl_805425D0;
extern const f32 lbl_805425D4;
extern const f32 lbl_805425C0;
extern const f32 lbl_805425A0;
extern const f32 lbl_805425A4;
extern const f32 lbl_805425A8;
extern const f32 lbl_805425AC;
extern const f32 lbl_805425B0;
extern const f32 lbl_804721C8[];
extern "C" f32 PSVECDistance(const Vec* a, const Vec* b);
extern "C" Vec* fn_8023E724(s32 idx);
extern "C" u8 fn_8023F264(s32 idx);
extern "C" u8 fn_8023EA28(s32 idx);
extern "C" u8 fn_8023B0F4(s32 idx, f32* rect, s32 room, f32 f, s32 zero);
extern "C" s32 fn_80138A30(void* mgr);
extern "C" s32 fn_8022CAF8(s32 idx);
extern "C" void fn_801F0E34(Actor* self, s32 soundId, s32 flag);
extern "C" u8 fn_8023077C(void);
extern "C" void fn_80230498(s32 idx, Vec* v, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_8022FFC4(s32 idx, Vec* v);
extern "C" void fn_80230FD0(s32 idx, s32 id);
extern "C" void fn_801F0D20(Actor* self, s32 id);
extern "C" u8 fn_80230534(s32 idx);
extern "C" s32 lbl_804721D4[];
extern "C" const f32 lbl_805425C4;
extern "C" const f32 lbl_805425C8;
extern "C" const f32 lbl_805425CC;

enum YnswConstants {
    FOURCC_SOB           = 0x534F4220, // 'SOB ' (Sprite Object Binary resource type)
    MAX_TV_LAYER_ID      = 8,          // Layers 0..7 render on TV; 8..15 are GBA sub-screens
    YNSW_SPRITE_BASE_ID  = 0x0D,       // Base sprite index in "enemy_both_sob.bin" (+ mAnimFrame)
    YNSW_Z_SORT_PRIORITY = -3,         // Sub-layer Z-bias so ground switch draws beneath actors
};

struct FsaResourceManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual u32 getResource(u32 fourccType, char* fileName); // slot 6 (+0x18)
};

struct FsaGameManager {
    u8 _pad00[0xA4];
    FsaResourceManager* mResMgr; // +0xA4
};

struct FsaRenderManager {
    u8 _pad00[0x20];
    u32 mSobRenderer; // +0x20: 2D SOB sprite renderer instance
};

struct SobDrawParams {
    /* 0x00 (r1+0x08) */ u8 paletteMap[0x10];
    /* 0x10 (r1+0x18) */ s32 primaryColor;
    /* 0x14 (r1+0x1C) */ s32 envColor;
    /* 0x18 (r1+0x20) */ s32 transformMtx;
    /* 0x1C (r1+0x24) */ s8 renderFlags[0xB];
    /* 0x28 (r1+0x30) */ s32 blendMode;
    /* 0x2C (r1+0x34) */ u8 shadowFlags[3];
    /* 0x30 (r1+0x38) */ s32 lightId;
    /* 0x34 (r1+0x3C) */ s32 animPhase;
    /* 0x38 (r1+0x40) */ s32 cullMode;

    SobDrawParams() {
        s32 i;
        primaryColor = -1;
        envColor = -1;
        for (i = 0; (u8)i < 0x10; i += 8) {
            paletteMap[(u8)i] = i;
            paletteMap[(u8)(i + 1)] = i + 1;
            paletteMap[(u8)(i + 2)] = i + 2;
            paletteMap[(u8)(i + 3)] = i + 3;
            paletteMap[(u8)(i + 4)] = i + 4;
            paletteMap[(u8)(i + 5)] = i + 5;
            paletteMap[(u8)(i + 6)] = i + 6;
            paletteMap[(u8)(i + 7)] = i + 7;
        }
        primaryColor = -1;
        envColor = 0;
        transformMtx = 0;
        renderFlags[0] = 0;
        renderFlags[1] = 0;
        renderFlags[2] = 0;
        renderFlags[3] = 1;
        renderFlags[4] = 1;
        renderFlags[5] = 0;
        renderFlags[6] = 0;
        renderFlags[7] = 0;
        renderFlags[8] = 0;
        renderFlags[9] = 0;
        renderFlags[10] = 1;
        blendMode = 3;
        shadowFlags[0] = 1;
        shadowFlags[1] = 0;
        shadowFlags[2] = 0;
        lightId = -1;
        animPhase = 0;
        cullMode = 2;
    }
};

struct YnswVirt : public Actor {
    virtual void v12(u8 a, s32 b);
    virtual u8 v13();
};

// YNSW ('YNSW') - Floor/Step Switch Actor.
// Total size: 0x284 bytes (derives from Actor, base size 0x230).
struct YnswActor : public Actor {
    /* 0x230 */ s32 mState;          // 0 = unpressed, 4 = pressed/latched
    /* 0x234 */ s32 mSwitchType;     // Unpacked from spawnParam & 0xF (1 = persistent room-flag switch)
    /* 0x238 */ s32 mAnimFrame;      // 0 = up, 2 = depressed (added to YNSW_SPRITE_BASE_ID 0x0D)
    /* 0x23C */ s32 mPrevAnimFrame;
    /* 0x240 */ s32 mTimer;
    /* 0x244 */ s32 mSubTimer;
    /* 0x248 */ s32 mUnused248;
    /* 0x24C */ u8 mPlayerOn[4];     // Per-player current contact flags
    /* 0x250 */ u8 mPlayerWasOn[4];  // Per-player previous-frame contact flags
    /* 0x254 */ Vec mPlayerPos[4];   // Per-player tracked positions (4 x 0x0C bytes)
};

extern FsaGameManager* lbl_8053AAF8;
extern FsaRenderManager* lbl_8053AB10;
extern char lbl_80472210[]; // "enemy_both_sob.bin"

extern "C" void fn_802F86CC(u32 sobRenderer, void* pos, u32 sobResource, s32 spriteId,
                            f32 scaleX, f32 scaleY, void* drawParams);
extern "C" void fn_80307AC8(s32 gbaActorHandle, s32 layerId, void* pos, s32 spriteId,
                            s32 on, s32 modeFlags, s32 targetPlayer);

#define Ynsw_Draw          fn_8034E2F0
#define Ynsw_Init          fn_8034EAB4
#define SobRenderer_Draw   fn_802F86CC
#define GbaEffect_Dispatch fn_80307AC8

extern "C" char __vt__4YNSW[];
extern "C" void __dt__5ActorFv(Actor*, s32);

extern "C" Actor* fn_8034DFF0(Actor* p, s16 freeFlag) {
    if (p) {
        *(void**)p = __vt__4YNSW;
        __dt__5ActorFv(p, 0);
        if (freeFlag > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8034E050(YnswActor* this_) {
    u8 used[4];
    Vec target;
    Vec tmp;
    Vec pos[4];
    s32 i;
    s32 j;
    s32 k;
    s32 nearest;
    f32 minDist;
    f32 offX;
    f32 offZ;

    for (i = 0; i < 4; i++) {
        used[i] = 0;
        pos[i] = *fn_8023E724(i);
    }
    nearest = -1;
    minDist = lbl_805425B0;
    k = 0;
    for (j = 0; j < 2; j++) {
        offX = lbl_805425A4 * (f32)j + lbl_805425A0;
        offZ = lbl_805425AC * (f32)j + lbl_805425A8;
        tmp = this_->field_0C;
        tmp.x += offX;
        tmp.y += lbl_805425A4 * (f32)k + lbl_805425A0;
        for (i = 0; i < 4; i++) {
            if (used[i] == 0) {
                f32 d = PSVECDistance(&tmp, &pos[i]);
                if (minDist > d) {
                    minDist = d;
                    nearest = i;
                }
            }
        }
        target = this_->field_0C;
        target.x += offZ;
        target.y += (lbl_805425AC * (f32)k + lbl_805425A8) + lbl_804721C8[this_->mAnimFrame];
        this_->mPlayerPos[nearest] = target;
        used[nearest] = 1;
        k++;
    }
}

extern "C" void fn_8034E49C(YnswActor* this_) {
    f32 rect[4];
    Vec v44;
    Vec v38;
    Vec v2c;
    Vec v20;
    Vec v14;
    Vec v8;
    s32 i;
    s32 count = 0;
    u8 flag;

    rect[0] = this_->field_60 + this_->field_0C.x;
    rect[1] = this_->field_64 + this_->field_0C.y + lbl_805425C4;
    rect[2] = this_->field_68 + this_->field_0C.x;
    rect[3] = this_->field_6C + this_->field_0C.y + lbl_805425C4;

    switch (this_->mState) {
    case 0:
        for (i = 0; i < 4; i++) {
            this_->mPlayerWasOn[i] = this_->mPlayerOn[i];
            if (!fn_8023F264(i)) {
                continue;
            }
            if (fn_8023EA28(i)) {
                continue;
            }
            this_->mPlayerOn[i] = fn_8023B0F4(i, rect, this_->field_04, lbl_805425C8, 0);
            if (this_->mPlayerOn[i] == 1) {
                count++;
            }
        }

        flag = 0;
        if (fn_80138A30(lbl_8053AAF8) != 1) {
            flag = 1;
        } else if (fn_8022CAF8(0) == 2) {
            flag = 1;
        }

        switch (count) {
        case 0:
            this_->mAnimFrame = 0;
            this_->mSubTimer = 0;
            break;
        case 1:
        case 2:
        case 3:
            if (this_->mPrevAnimFrame == 0) {
                fn_801F0E34(this_, 0x5006E, 0);
            }
            this_->mAnimFrame = 1;
            this_->mSubTimer = 0;
            break;
        case 4:
            if (this_->mTimer != count) {
                if (this_->mPrevAnimFrame == 0) {
                    fn_801F0E34(this_, 0x5006E, 0);
                }
                this_->mAnimFrame = 1;
                this_->mSubTimer = 5;
            } else if (this_->mSubTimer <= 0 && !((YnswVirt*)this_)->v13()) {
                if (!fn_8023077C()) {
                    break;
                }
                v44.z = lbl_805425CC;
                v44.y = lbl_805425CC;
                v44.x = lbl_805425CC;
                v44.y = lbl_804721C8[this_->mAnimFrame];
                fn_8034E050(this_);
                for (i = 0; i < 4; i++) {
                    fn_80230498(i, &this_->mPlayerPos[i], 0xe8, 0xff, -0x80, -0x80, 1);
                    fn_8022FFC4(i, &v44);
                }
                this_->mState = 2;
                this_->mSubTimer = 0xf;
                break;
            }
            if (flag == 1 && this_->mSubTimer > 0) {
                this_->mSubTimer--;
            }
            break;
        }

        if (this_->mSwitchType == 0 && this_->mTimer == 4 && count < 4) {
            ((YnswVirt*)this_)->v12(0xff, 0);
        }
        for (i = 0; i < 4; i++) {
            if (!fn_8023F264(i)) {
                continue;
            }
            if (fn_8023EA28(i)) {
                continue;
            }
            v38.z = lbl_805425CC;
            v38.y = lbl_805425CC;
            v38.x = lbl_805425CC;
            if (this_->mPlayerOn[i] == 1) {
                v38.y = lbl_804721C8[this_->mAnimFrame];
            }
            if (lbl_804721C8[this_->mAnimFrame] != lbl_805425CC || this_->mPlayerWasOn[i] != this_->mPlayerOn[i]) {
                fn_8022FFC4(i, &v38);
            }
        }
        this_->mTimer = count;
        break;
    case 2:
        if (this_->mSubTimer <= 0) {
            for (i = 0; i < 4; i++) {
                v2c = *fn_8023E724(i);
                fn_80230498(i, &v2c, 0xe8, 0xff, -0x80, -0x80, 1);
            }
            fn_801F0E34(this_, 0x30009, 0);
            this_->mAnimFrame = 2;
            this_->mUnused248 = 0;
            this_->mSubTimer = 0x1e;
            this_->mState = 1;
        }
        for (i = 0; i < 4; i++) {
            v20.z = lbl_805425CC;
            v20.y = lbl_805425CC;
            v20.x = lbl_805425CC;
            v20.y = lbl_804721C8[this_->mAnimFrame];
            fn_8022FFC4(i, &v20);
        }
        this_->mSubTimer--;
        break;
    case 1:
        if (--this_->mSubTimer == 0) {
            if (this_->mUnused248 >= 0xd) {
                fn_801F0D20(this_, 3);
                ((YnswVirt*)this_)->v12(0xff, 1);
                this_->mSubTimer = 0xf;
                this_->mState = 3;
                break;
            }
            this_->mUnused248++;
            this_->mSubTimer = lbl_804721D4[this_->mUnused248];
            for (i = 0; i < 4; i++) {
                v14 = *fn_8023E724(i);
                fn_80230498(i, &v14, this_->mUnused248 + 0xdb, 0xff, -0x80, -0x80, 1);
                if (this_->mUnused248 == 1) {
                    fn_80230FD0(i, 0x10001);
                }
            }
        }
        break;
    case 3:
        if (--this_->mSubTimer < 0 && fn_80230534(0)) {
            this_->mSubTimer = 0;
            for (i = 0; i < 4; i++) {
                v8.z = lbl_805425CC;
                v8.y = lbl_805425CC;
                v8.x = lbl_805425CC;
                fn_8022FFC4(i, &v8);
            }
            if (this_->mSwitchType == 1) {
                this_->mState = 4;
            } else {
                this_->mState = 0;
            }
        }
        break;
    case 4:
        break;
    }

    this_->mPrevAnimFrame = this_->mAnimFrame;
}

extern "C" void Ynsw_Draw(YnswActor* this_) {
    SobDrawParams drawParams;
    drawParams.renderFlags[1] = YNSW_Z_SORT_PRIORITY;
    drawParams.renderFlags[0] = 0;

    s32 spriteId = this_->mAnimFrame + YNSW_SPRITE_BASE_ID;
    if ((s32)this_->field_04 < MAX_TV_LAYER_ID) {
        u32 sobRes = lbl_8053AAF8->mResMgr->getResource(FOURCC_SOB, lbl_80472210);
        SobRenderer_Draw(lbl_8053AB10->mSobRenderer, &this_->field_0C, sobRes, spriteId,
                         lbl_805425C0, lbl_805425C0, &drawParams);
    }
    GbaEffect_Dispatch(this_->field_198, this_->field_04, &this_->field_0C,
                       this_->mAnimFrame + YNSW_SPRITE_BASE_ID, 0, 0, -1);
}

extern "C" void Ynsw_Init(YnswActor* this_) {
    this_->field_7C.y = lbl_805425D0;
    this_->field_7C.z = lbl_805425D0;
    this_->field_88 = lbl_805425D4;
    this_->field_8C = lbl_805425D4;
    this_->field_60 = lbl_805425D0;
    this_->field_64 = lbl_805425D0;
    this_->field_68 = lbl_805425D4;
    this_->field_6C = lbl_805425D4;
    this_->mAnimFrame = 0;
    this_->mPrevAnimFrame = this_->mAnimFrame;
    this_->mSubTimer = 0;
    this_->mTimer = 0;
    this_->mSwitchType = this_->field_90 & 0xf;
    this_->mPlayerOn[0] = 0;
    this_->mPlayerWasOn[0] = 0;
    this_->mPlayerPos[0].z = lbl_805425CC;
    this_->mPlayerPos[0].y = lbl_805425CC;
    this_->mPlayerPos[0].x = lbl_805425CC;
    this_->mPlayerOn[1] = 0;
    this_->mPlayerWasOn[1] = 0;
    this_->mPlayerPos[1].z = lbl_805425CC;
    this_->mPlayerPos[1].y = lbl_805425CC;
    this_->mPlayerPos[1].x = lbl_805425CC;
    this_->mPlayerOn[2] = 0;
    this_->mPlayerWasOn[2] = 0;
    this_->mPlayerPos[2].z = lbl_805425CC;
    this_->mPlayerPos[2].y = lbl_805425CC;
    this_->mPlayerPos[2].x = lbl_805425CC;
    this_->mPlayerOn[3] = 0;
    this_->mPlayerWasOn[3] = 0;
    this_->mPlayerPos[3].z = lbl_805425CC;
    this_->mPlayerPos[3].y = lbl_805425CC;
    this_->mPlayerPos[3].x = lbl_805425CC;
    this_->mState = 0;
    if (this_->mSwitchType == 1 && (u8)((YnswVirt*)this_)->v11() == 1) {
        this_->mAnimFrame = 2;
        this_->mState = 4;
    }
}

