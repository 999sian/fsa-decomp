#include "Game/Actor.h"

struct FsaResourceManager {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual u32 getResource(u32 fourccType, const char* fileName); // slot 6 (+0x18)
};

struct FsaGameManager {
    u8 _pad00[0xA4];
    FsaResourceManager* mResMgr; // +0xA4
};

struct FsaRenderManager {
    u8 _pad00[0x20];
    u32 mSobRenderer; // +0x20: 2D SOB sprite renderer instance
    u8 _pad24[0x8];
    u32 mFxMgr;       // +0x2C: fn_80158B5C manager
};

// 0x3C-byte 2D SOB draw configuration payload (same layout as tu_802AFA10.cpp)
struct SobDrawParams {
    u8 paletteMap[0x10];
    union {
        s32 raw;
        struct {
            u8 r, g, b, a;
        } rgba;
    } primaryColor;
    s32 envColor;
    void* transformMtx;
    s8 renderFlags[0xB];
    s32 blendMode;
    u8 shadowFlags[3];
    s32 lightId;
    s32 animPhase;
    s32 cullMode;

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

extern FsaGameManager* lbl_8053AAF8;
extern FsaRenderManager* lbl_8053AB10;
extern "C" const char lbl_8046E040[];
extern "C" const s32 lbl_8046DFD0[];
extern "C" const f64 lbl_80540E70;
extern "C" const f32 lbl_80540E78;
extern "C" const f32 lbl_80540E80;
extern "C" const f32 lbl_80540E84;
extern "C" void fn_802F86CC(u32 sobRenderer, Vec* pos, u32 sobResource, s32 spriteId,
                            f32 scaleX, f32 scaleY, SobDrawParams* drawParams);
extern "C" void fn_80158B5C(u32 mgr, s32 room, Vec* pos, void* color, f32 size);


extern "C" char lbl_804A9328[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802CFDCC(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804A9328;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" const f32 lbl_80540E7C;
extern "C" const f32 lbl_80540E8C;
extern "C" const f32 lbl_80540E9C;
extern "C" const f32 lbl_80540EA0;
extern "C" const f32 lbl_80540EA4;
extern "C" void fn_802D06BC(Actor* p) {
    u8* b;
    s32 neg;
    s32 i;

    neg = -1;
    b = (u8*)p;
    for (i = 8; i > 0; i--) {
        *(s32*)(b + 0x274) = neg;
        *(s32*)(b + 0x278) = neg;
        *(s32*)(b + 0x27c) = neg;
        *(s32*)(b + 0x280) = neg;
        *(s32*)(b + 0x284) = neg;
        *(s32*)(b + 0x288) = neg;
        *(s32*)(b + 0x28c) = neg;
        *(s32*)(b + 0x290) = neg;
        *(s32*)(b + 0x294) = neg;
        *(s32*)(b + 0x298) = neg;
        *(s32*)(b + 0x29c) = neg;
        *(s32*)(b + 0x2a0) = neg;
        *(s32*)(b + 0x2a4) = neg;
        *(s32*)(b + 0x2a8) = neg;
        *(s32*)(b + 0x2ac) = neg;
        *(s32*)(b + 0x2b0) = neg;
        *(s32*)(b + 0x2b4) = neg;
        *(s32*)(b + 0x2b8) = neg;
        *(s32*)(b + 0x2bc) = neg;
        *(s32*)(b + 0x2c0) = neg;
        *(s32*)(b + 0x2c4) = neg;
        *(s32*)(b + 0x2c8) = neg;
        *(s32*)(b + 0x2cc) = neg;
        *(s32*)(b + 0x2d0) = neg;
        *(s32*)(b + 0x2d4) = neg;
        *(s32*)(b + 0x2d8) = neg;
        *(s32*)(b + 0x2dc) = neg;
        *(s32*)(b + 0x2e0) = neg;
        *(s32*)(b + 0x2e4) = neg;
        *(s32*)(b + 0x2e8) = neg;
        *(s32*)(b + 0x2ec) = neg;
        *(s32*)(b + 0x2f0) = neg;
        b += 0x80;
    }
    p->field_60 = lbl_80540E9C;
    p->field_64 = lbl_80540E9C;
    p->field_68 = lbl_80540EA0;
    p->field_6C = lbl_80540EA0;
    *(s32*)((u8*)p + 0x234) = (p->field_90 >> 22) & 0x1f;
    *(s32*)((u8*)p + 0x238) = (p->field_90 >> 17) & 0x1f;
    *(s32*)((u8*)p + 0x23c) = (p->field_90 >> 12) & 0x1f;
    *(s32*)((u8*)p + 0x24c) = ((p->field_90 >> 7) & 0x1f) * 30;
    if (*(s32*)((u8*)p + 0x24c) == 0) {
        *(s32*)((u8*)p + 0x24c) = 10;
    }
    *(s32*)((u8*)p + 0x248) = 1;
    *(s32*)((u8*)p + 0x244) = p->field_90 & 0x7f;
    if (*(s32*)((u8*)p + 0x244) == 0) {
        *(s32*)((u8*)p + 0x244) = 0x100;
    }
    *(s32*)((u8*)p + 0x240) = 0;
    *(s32*)((u8*)p + 0x250) = p->field_90 >> 27;
    *(s32*)((u8*)p + 0x230) = 0;
    *(s32*)((u8*)p + 0x264) = 3;
    *(s32*)((u8*)p + 0x268) = 0;
    *(s32*)((u8*)p + 0x674) = 0;
    *(u8*)((u8*)p + 0x26c) = 1;
    if (*(s32*)((u8*)p + 0x234) == 10 || *(s32*)((u8*)p + 0x234) == 0x11 || *(s32*)((u8*)p + 0x234) == 0x13 ||
        (u32)(*(s32*)((u8*)p + 0x234) - 0xb) <= 2 || *(s32*)((u8*)p + 0x234) == 0xf || *(s32*)((u8*)p + 0x234) == 0xe) {
        *(u8*)((u8*)p + 0x26c) = 0;
    }
    if (*(s32*)((u8*)p + 0x238) == 10 || *(s32*)((u8*)p + 0x238) == 0x11 || *(s32*)((u8*)p + 0x238) == 0x13 ||
        (u32)(*(s32*)((u8*)p + 0x238) - 0xb) <= 2 || *(s32*)((u8*)p + 0x238) == 0xf || *(s32*)((u8*)p + 0x238) == 0xe) {
        *(u8*)((u8*)p + 0x26c) = 0;
    }
    if (*(s32*)((u8*)p + 0x23c) == 10 || *(s32*)((u8*)p + 0x23c) == 0x11 || *(s32*)((u8*)p + 0x23c) == 0x13 ||
        (u32)(*(s32*)((u8*)p + 0x23c) - 0xb) <= 2 || *(s32*)((u8*)p + 0x23c) == 0xf || *(s32*)((u8*)p + 0x23c) == 0xe) {
        *(u8*)((u8*)p + 0x26c) = 0;
    }
    *(f32*)((u8*)p + 0x270) = lbl_80540E8C;
    *(s32*)((u8*)p + 0x254) = 0;
    *(f32*)((u8*)p + 0x258) = lbl_80540E7C + p->field_0C.x;
    *(f32*)((u8*)p + 0x25c) = lbl_80540EA4 + p->field_0C.y;
    *(f32*)((u8*)p + 0x260) = p->field_0C.z;
}

extern "C" void fn_802D0900(void) {
}

