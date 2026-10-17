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

struct YnswVirt {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual u8 v11();
    virtual void v12(); virtual u8 v13();
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

