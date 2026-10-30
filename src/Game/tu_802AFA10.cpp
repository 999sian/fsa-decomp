#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"


extern "C" char lbl_804A8470[];
extern "C" void __dt__5ActorFv(Actor*, s32);

enum YajiMode {
    YAJI_MODE_CONSTANT        = 0, // Always visible at fixed semi-transparent alpha (0x60)
    YAJI_MODE_TRIGGER_PULSE_A = 1, // Visible only when switch/trigger is active; pulses alpha
    YAJI_MODE_TRIGGER_HIDDEN  = 2, // Trigger-only (never drawn)
    YAJI_MODE_TRIGGER_PULSE_B = 3, // Secondary switch-triggered pulsing arrow mode
};

enum YajiConstants {
    FOURCC_SOB           = 0x534F4220, // 'SOB ' (Sprite Object Binary resource type)
    MAX_TV_LAYER_ID      = 8,          // Layers 0..7 render on TV; 8..15 are GBA sub-screens
    YAJI_SPRITE_BASE_ID  = 0x10,       // Base sprite index in "enemy_both_sob.bin" (+ direction 0..3)
    YAJI_CONSTANT_ALPHA  = 0x60,       // Fixed alpha (96/255) used in YAJI_MODE_CONSTANT
    YAJI_Z_SORT_PRIORITY = -3,         // Sub-layer Z-bias so ground arrow draws beneath actors
};

// Resource manager interface located at *(lbl_8053AAF8 + 0xA4)
struct FsaResourceManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual u32 getResource(u32 fourccType, const char* fileName); // slot 6 (+0x18)
};

struct FsaGameManager {
    u8 _pad00[0xA4];
    FsaResourceManager* mResMgr; // +0xA4
};

struct FsaRenderManager {
    u8 _pad00[0x20];
    u32 mSobRenderer; // +0x20: 2D SOB sprite renderer instance
};

// 0x3C-byte (60-byte) 2D SOB draw configuration payload (formerly `Init48`,
// named after its stack frame end offset 0x48(r1) in a 0x50-byte frame).
struct SobDrawParams {
    /* 0x00 (r1+0x08) */ u8 paletteMap[0x10]; // 16-entry palette/CLUT slot map (identity 0..15)
    /* 0x10 (r1+0x18) */ union {
        s32 raw;                              // Default: -1 (0xFFFFFFFF, opaque white)
        struct {
            u8 r, g, b, a;                    // Big-endian RGBA; `a` at +0x13 (r1+0x1B)
        } rgba;
    } primaryColor;
    /* 0x14 (r1+0x1C) */ s32 envColor;        // Secondary/environment color addend (0x00000000)
    /* 0x18 (r1+0x20) */ void* transformMtx;  // Optional f32[3][4] Mtx pointer (NULL = identity)
    /* 0x1C (r1+0x24) */ s8 renderFlags[0xB]; // Render/blend/layer flags:
                                              //   [0] (+0x1C): major layer priority (0)
                                              //   [1] (+0x1D): sub-layer Z-sort bias (-3)
                                              //   [2] (+0x1E): flip/mirror flag (0)
                                              //   [3] (+0x1F): alpha test enable (1)
                                              //   [4] (+0x20): depth/Z-offset enable (1)
                                              //   [5] (+0x21): pre-pass A enable (0)
                                              //   [6] (+0x22): pre-pass B enable (0)
                                              //   [7..9]:      reserved flags (0)
                                              //   [10] (+0x26): visibility/clip enable (1)
    /* 0x28 (r1+0x30) */ s32 blendMode;       // TEV/blend preset (3)
    /* 0x2C (r1+0x34) */ u8 shadowFlags[3];   // Shadow/stencil flags ({1, 0, 0})
    /* 0x30 (r1+0x38) */ s32 lightId;         // Light/effect override ID (-1 = none)
    /* 0x34 (r1+0x3C) */ s32 animPhase;       // Animation phase offset (0)
    /* 0x38 (r1+0x40) */ s32 cullMode;        // Culling/projection mode (2)

    SobDrawParams() {
        s32 i;
        primaryColor.raw = -1;
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
        primaryColor.raw = -1;
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

// YAJI ('YAJI', 0x59414A49) - Directional Guide Arrow Actor (Japanese: Yajirushi).
// Total size: 0x260 bytes (derives from Actor, base size 0x230).
struct YajiActor : public Actor {
    /* 0x230 */ s32 mSubState;       // 0 = idle/waiting for trigger, 1 = active/pulsing
    /* 0x234 */ f32 mZoneCenterX;    // Trigger zone center X
    /* 0x238 */ f32 mZoneCenterY;    // Trigger zone center Y
    /* 0x23C */ f32 mZoneCenterZ;    // Trigger zone center Z (copied from field_0C.z)
    /* 0x240 */ s32 mDirection;      // Arrow direction (0..3, from spawnParam & 0xF)
    /* 0x244 */ s32 mMode;           // YajiMode (from (spawnParam >> 7) & 0x1F)
    /* 0x248 */ s32 mSuppressSfx;    // Suppress trigger SFX flag (from (spawnParam >> 4) & 1)
    /* 0x24C */ s32 mBlinkTimer;     // Countdown timer (init 8)
    /* 0x250 */ s32 mIsVisible;      // Visibility flag (modes 1/3) or cycle step (mode 0)
    /* 0x254 */ s32 mAlpha;          // Current pulse alpha (40..200 in modes 1/3)
    /* 0x258 */ s32 mFadeDirection;  // Alpha pulse direction (0 = fade in, 1 = fade out)
    /* 0x25C */ s32 mPlayerInZone;   // Non-zero while player overlaps trigger zone
};

extern FsaGameManager* lbl_8053AAF8;
extern FsaRenderManager* lbl_8053AB10;
extern const char lbl_8046CA68[]; // "enemy_both_sob.bin"
extern f32 lbl_80540970;          // 1.0f

extern "C" void fn_802F86CC(u32 sobRenderer, Vec* pos, u32 sobResource, s32 spriteId,
                            f32 scaleX, f32 scaleY, SobDrawParams* drawParams);
extern "C" void fn_80307AC8(s32 gbaActorHandle, s32 layerId, Vec* pos, s32 spriteId,
                            s32 on, s32 modeFlags, s32 targetPlayer);

#define Yaji_Draw          fn_802AFA70
#define SobRenderer_Draw   fn_802F86CC
#define GbaEffect_Dispatch fn_80307AC8

extern "C" Actor* fn_802AFA10(Actor* p, s16 n) {
    if (p != nullptr) {
        *(void**)p = lbl_804A8470;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void Yaji_Draw(YajiActor* this_) {
    SobDrawParams drawParams;
    drawParams.renderFlags[1] = YAJI_Z_SORT_PRIORITY;

    switch (this_->mMode) {
    case YAJI_MODE_CONSTANT: {
        drawParams.primaryColor.rgba.a = YAJI_CONSTANT_ALPHA;
        s32 spriteId = this_->mDirection + YAJI_SPRITE_BASE_ID;
        if ((s32)this_->field_04 < MAX_TV_LAYER_ID) {
            u32 sobRes = lbl_8053AAF8->mResMgr->getResource(FOURCC_SOB, lbl_8046CA68);
            SobRenderer_Draw(lbl_8053AB10->mSobRenderer, &this_->field_0C, sobRes, spriteId,
                             lbl_80540970, lbl_80540970, &drawParams);
        }
        GbaEffect_Dispatch(this_->field_198, this_->field_04, &this_->field_0C,
                           this_->mDirection + YAJI_SPRITE_BASE_ID, 0, 0, -1);
        break;
    }
    case YAJI_MODE_TRIGGER_PULSE_A:
    case YAJI_MODE_TRIGGER_PULSE_B:
        if (this_->mIsVisible != 0) {
            drawParams.primaryColor.rgba.a = this_->mAlpha;
            s32 spriteId = this_->mDirection + YAJI_SPRITE_BASE_ID;
            if ((s32)this_->field_04 < MAX_TV_LAYER_ID) {
                u32 sobRes = lbl_8053AAF8->mResMgr->getResource(FOURCC_SOB, lbl_8046CA68);
                SobRenderer_Draw(lbl_8053AB10->mSobRenderer, &this_->field_0C, sobRes, spriteId,
                                 lbl_80540970, lbl_80540970, &drawParams);
            }
            GbaEffect_Dispatch(this_->field_198, this_->field_04, &this_->field_0C,
                               this_->mDirection + YAJI_SPRITE_BASE_ID, 0, 0, -1);
        }
        break;
    }
}

extern const s32 lbl_80540968[2];
extern "C" s32 fn_8023AF14(f32*, u32, s32, f32);
extern "C" void fn_801F0E34(void*, u32, s32);
extern "C" void fn_801F0D20(void*, s32);
extern "C" void fn_8043D67C(void*, s32, s32, s32);
extern "C" void fn_8043E7CC(void*, JGeometry::TVec3f);
extern "C" void fn_8030C210(void*, Vec*);
extern void* lbl_8053AED0;

inline void yajiStartPulse(YajiActor* p) {
    p->mIsVisible = 1;
    p->mAlpha = 20;
    p->mFadeDirection = 0;
    fn_801F0E34(p, 0x30025, 0);
    p->mSubState = 1;
    if (p->mSuppressSfx == 0) fn_8043D67C(lbl_8053AED0, 0x199, 0, 0);
}
inline void yajiAdvancePulse(YajiActor* p) {
    if (p->mFadeDirection == 0) {
        if (p->mAlpha >= 200) {
            p->mAlpha = 200;
            p->mFadeDirection = 1;
        }
    } else {
        if (p->mAlpha <= 40) {
            p->mAlpha = 40;
            p->mFadeDirection = 0;
            fn_801F0E34(p, 0x30025, 0);
        }
    }
}
inline void yajiStopPulse(YajiActor* p) {
    p->mIsVisible = 0;
    p->mPlayerInZone = 0;
    p->mSubState = 0;
}

extern "C" void fn_802AFCE8(YajiActor* p) {
    f32 box[4];
    f32 y = p->mZoneCenterY;
    f32 x = p->mZoneCenterX;
    box[0]=p->field_60; box[1]=p->field_64; box[2]=p->field_68; box[3]=p->field_6C;
    box[0]+=x; box[1]+=y; box[2]+=x; box[3]+=y;
    s32 player = fn_8023AF14(box,p->field_04,0,0.0f);
    switch (p->mMode) {
    case YAJI_MODE_CONSTANT:
        p->mBlinkTimer--;
        if (p->mBlinkTimer == 0) {
            p->mBlinkTimer = 8;
            p->mIsVisible = (p->mIsVisible+1)&3;
        }
        break;
    case YAJI_MODE_TRIGGER_PULSE_A:
        switch(p->mSubState) {
        case 0:
            if ((u8)p->v11()) yajiStartPulse(p);
            else if (player >= 0) {
                p->mPlayerInZone=1;
                p->v10(0xff,1);
            }
            break;
        case 1: {
            p->mAlpha += lbl_80540968[p->mFadeDirection];
            fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &p->field_0C);
            JGeometry::TVec3f pos(p->field_0C);
            fn_8043E7CC(lbl_8053AED0, pos);
            if ((u8)p->v11()) {
                yajiAdvancePulse(p);
                if (player < 0) {
                    if (p->mPlayerInZone != 0) p->v10(0xff,0);
                    p->mPlayerInZone=0;
                } else {
                    p->mPlayerInZone=1;
                    p->v10(0xff,1);
                }
            } else yajiStopPulse(p);
            break;
        }
        }
        break;
    case YAJI_MODE_TRIGGER_HIDDEN:
        switch(p->mSubState) {
        case 0:
            if (player >= 0) {
                p->mSubState=1;
                fn_801F0D20(p,6);
            }
            break;
        case 1:
            if (player < 0) p->mSubState=0;
            break;
        }
        break;
    case YAJI_MODE_TRIGGER_PULSE_B:
        switch(p->mSubState) {
        case 0:
            if ((u8)p->v11()) yajiStartPulse(p);
            break;
        case 1: {
            p->mAlpha += lbl_80540968[p->mFadeDirection];
            fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &p->field_0C);
            JGeometry::TVec3f pos(p->field_0C);
            fn_8043E7CC(lbl_8053AED0, pos);
            if ((u8)p->v11()) {
                yajiAdvancePulse(p);
                
            } else yajiStopPulse(p);
            break;
        }
        }
        break;
    }
}

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802B0194(u8* this_) {
	s32 id;
	u8* mgr;
	f32* pfVar5;

	*(s32*)(this_ + 0x240) = *(u32*)(this_ + 0x90) & 0xf;
	*(s32*)(this_ + 0x244) = (*(u32*)(this_ + 0x90) >> 7) & 0x1f;
	*(s32*)(this_ + 0x248) = (*(u32*)(this_ + 0x90) >> 4) & 1;
	*(s32*)(this_ + 0x230) = 0;
	*(s32*)(this_ + 0x250) = 0;
	*(s32*)(this_ + 0x24c) = 8;
	*(s32*)(this_ + 0x254) = 0x28;
	*(s32*)(this_ + 0x258) = 0;
	*(s32*)(this_ + 0x25c) = 0;

	id = *(s32*)(this_ + 4);
	mgr = (u8*)fn_802D6A9C();
	if (id < 8) {
		pfVar5 = (f32*)(mgr + 0xcc);
	} else {
		pfVar5 = (f32*)(mgr + 0xdc);
	}

	*(f32*)(this_ + 0x23c) = *(f32*)(this_ + 0x14);
	switch (*(s32*)(this_ + 0x240)) {
	case 0:
		*(f32*)(this_ + 0x234) = *(f32*)(this_ + 0xc);
		*(f32*)(this_ + 0x238) = 192.0f + pfVar5[1];
		*(f32*)(this_ + 0x60) = -32.0f;
		*(f32*)(this_ + 0x64) = -256.0f;
		*(f32*)(this_ + 0x68) = 32.0f;
		*(f32*)(this_ + 0x6c) = 256.0f;
		break;
	case 1:
		*(f32*)(this_ + 0x234) = *(f32*)(this_ + 0xc);
		*(f32*)(this_ + 0x238) = 192.0f + pfVar5[1];
		*(f32*)(this_ + 0x60) = -32.0f;
		*(f32*)(this_ + 0x64) = -256.0f;
		*(f32*)(this_ + 0x68) = 32.0f;
		*(f32*)(this_ + 0x6c) = 256.0f;
		break;
	case 2:
		*(f32*)(this_ + 0x234) = 256.0f + pfVar5[0];
		*(f32*)(this_ + 0x238) = *(f32*)(this_ + 0x10);
		*(f32*)(this_ + 0x60) = -256.0f;
		*(f32*)(this_ + 0x64) = -32.0f;
		*(f32*)(this_ + 0x68) = 256.0f;
		*(f32*)(this_ + 0x6c) = 32.0f;
		break;
	case 3:
	default:
		*(f32*)(this_ + 0x234) = 256.0f + pfVar5[0];
		*(f32*)(this_ + 0x238) = *(f32*)(this_ + 0x10);
		*(f32*)(this_ + 0x60) = -256.0f;
		*(f32*)(this_ + 0x64) = -32.0f;
		*(f32*)(this_ + 0x68) = 256.0f;
		*(f32*)(this_ + 0x6c) = 32.0f;
		break;
	}
}

void fn_802B0338(void) {}

