#include "Game/Actor.h"
extern "C" char lbl_804AB258[];
extern "C" void __dt__5ActorFv(Actor*, s32);

enum BrryConstants {
    FOURCC_SOB           = 0x534F4220, // 'SOB ' (Sprite Object Binary resource type)
    MAX_TV_LAYER_ID      = 8,          // Layers 0..7 render on TV; 8..15 are GBA sub-screens
    BRRY_Z_SORT_PRIORITY = -2,         // Sub-layer Z-bias
};

struct FsaResourceManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual u32 getResource(u32 fourccType, char* fileName); // slot 6 (+0x18)
};

struct FsaGameManager {
    u8 mFlags[0xA4];                   // mFlags[0x7F] = barrier active gate
    FsaResourceManager* mResMgr;       // +0xA4
};

struct FsaRenderManager {
    u8 _pad00[0x20];
    u32 mSobRenderer;                  // +0x20: 2D SOB sprite renderer instance
};

struct SobDrawParams {
    /* 0x00 (r1+0x08) */ u8 paletteMap[0x10];
    /* 0x10 (r1+0x18) */ s32 primaryColor;
    /* 0x14 (r1+0x1C) */ s32 envColor;
    /* 0x18 (r1+0x20) */ s32 transformMtx;
    /* 0x1C (r1+0x24) */ s8 renderFlags[0xC];
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

// BRRY ('BRRY', misdecoded in early CSV as BPRY) - Barrier Actor.
// Total size: 0x270 bytes (derives from Actor, base size 0x230).
struct BrryActor : public Actor {
    /* 0x230 */ s32 mState;          // 0 = active/visible, 1 = tile-linked, 2 = dormant
    /* 0x234 */ u32 mTimer;
    /* 0x238 */ s32 mAnimFrame;      // Frame offset added to sSpriteTable[mVariant]
    /* 0x23C */ u32 mField23C;
    /* 0x240 */ s32 mTargetHandle;   // Init -1
    /* 0x244 */ s32 mVariant;        // Unpacked from spawnParam & 3
    /* 0x248 */ u32 mSwitchId;       // Unpacked from (spawnParam >> 8) & 0xFF
    /* 0x24C */ u32 mField24C;
    /* 0x250 */ u32 mField250;
    /* 0x254 */ u32 mField254;
    /* 0x258 */ u32 mField258;
    /* 0x25C */ u32 mField25C;
    /* 0x260 */ u32 mField260;
    /* 0x264 */ u32 mField264;
    /* 0x268 */ u32 mField268;
    /* 0x26C */ u16 mTileId;         // Tile collision ID at actor position
};

extern void* lbl_8053AAF8;
extern FsaRenderManager* lbl_8053AB10;
extern s32 lbl_804AB248[];   // Sprite base index table indexed by mVariant
extern char lbl_8047174C[];  // "enemy_both_sob.bin"
extern f32 lbl_80541A58;     // 1.0f

extern "C" void fn_802F86CC(u32 sobRenderer, void* pos, u32 sobResource, s32 spriteId,
                            f32 scaleX, f32 scaleY, void* drawParams);
extern "C" void fn_80307AC8(u32 gbaActorHandle, s32 layerId, void* pos, s32 spriteId,
                            s32 on, s32 modeFlags, s32 targetPlayer);
extern "C" u16 fn_80226850(void* pos, s32 room);

#define Brry_Draw          fn_8031EFAC
#define Brry_Init          fn_8031F97C
#define SobRenderer_Draw   fn_802F86CC
#define GbaEffect_Dispatch fn_80307AC8

extern "C" Actor* fn_8031EF4C(Actor* p, s16 freeFlag) {
    if (p != 0) {
        *(void**)p = lbl_804AB258;
        __dt__5ActorFv(p, 0);
        if (freeFlag > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void Brry_Draw(BrryActor* this_) {
    SobDrawParams drawParams;
    drawParams.renderFlags[1] = BRRY_Z_SORT_PRIORITY;
    drawParams.renderFlags[0] = 0;
    drawParams.shadowFlags[1] = 1;

    if (this_->mState == 0) {
        s32 spriteId = this_->mAnimFrame + lbl_804AB248[this_->mVariant];
        if ((s32)this_->field_04 < MAX_TV_LAYER_ID) {
            u32 sobRes = ((FsaGameManager*)lbl_8053AAF8)->mResMgr->getResource(FOURCC_SOB, lbl_8047174C);
            SobRenderer_Draw(lbl_8053AB10->mSobRenderer, &this_->field_0C, sobRes, spriteId,
                             lbl_80541A58, lbl_80541A58, &drawParams);
        }
        GbaEffect_Dispatch(this_->field_198, this_->field_04, &this_->field_0C,
                           this_->mAnimFrame + lbl_804AB248[this_->mVariant], 0, 0, -1);
    }
}

extern "C" void Brry_Init(BrryActor* this_) {
    if (((u8*)lbl_8053AAF8)[0x7f] == 0) {
        this_->detach();
    } else {
        this_->mVariant = this_->field_90 & 3;
        this_->mSwitchId = (this_->field_90 >> 8) & 0xff;
        this_->field_94 = (this_->field_90 >> 16) & 0xff;
        this_->mTileId = 0;
        this_->mAnimFrame = 0;
        this_->mTimer = 0;
        this_->mField24C = 0;
        this_->mField25C = 0;
        this_->mField250 = 0;
        this_->mField260 = 0;
        this_->mField254 = 0;
        this_->mField264 = 0;
        this_->mField258 = 0;
        this_->mField268 = 0;
        this_->field_108 = 10000;
        this_->mField23C = 0;
        this_->mTargetHandle = -1;
        this_->mState = 0;
        this_->field_0C.x = (f32)((s32)this_->field_0C.x / 16) * 16.0f + 8.0f;
        this_->field_0C.y = (f32)((s32)this_->field_0C.y / 16) * 16.0f + 8.0f;
        if (this_->field_94 == 1 || this_->field_94 == 4) {
            this_->mState = 1;
            this_->mTileId = fn_80226850(&this_->field_0C, this_->field_04);
        }
        if (this_->field_94 == 2) {
            this_->mState = 2;
        }
        if (this_->field_94 == 3 || this_->field_94 == 5) {
            this_->mState = 2;
        }
        this_->field_3C.x = 0.0f;
        this_->field_3C.y = 0.0f;
        this_->field_3C.z = 0.0f;
        this_->field_7C.y = -8.0f;
        this_->field_7C.z = -8.0f;
        this_->field_88 = 8.0f;
        this_->field_8C = 8.0f;
        this_->field_60 = -4.0f;
        this_->field_64 = -4.0f;
        this_->field_68 = 4.0f;
        this_->field_6C = 4.0f;
    }
}
