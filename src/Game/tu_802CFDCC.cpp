#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JUtility/TColor.h"

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

enum {
    FOURCC_SOB = 0x534F4220, // 'SOB ' (Sprite Object Binary resource type)
};

extern FsaGameManager* lbl_8053AAF8;
extern FsaRenderManager* lbl_8053AB10;
extern "C" const char lbl_8046E040[];
extern "C" s32 lbl_8046DFD0[];

struct CFActor : Actor {
    s32 field_230;
    s32 field_234[3];
    s32 field_240, field_244, field_248, field_24c, field_250, field_254;
    Vec field_258;
    s32 field_264, field_268, field_26c;
    f32 field_270;
    s32 field_274[256];
    s32 field_674;
};
extern "C" const f64 lbl_80540E70;
extern "C" const f32 lbl_80540E78;
extern "C" const f32 lbl_80540E80;
extern "C" const f32 lbl_80540E7C;
extern "C" const f32 lbl_80540E84;
extern "C" void fn_802F86CC(u32 sobRenderer, Vec* pos, u32 sobResource, s32 spriteId,
                            f32 scaleX, f32 scaleY, SobDrawParams* drawParams);
#include "dolphin/gx/GXStruct.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"

extern "C" void fn_80158B5C(u32 mgr, s32 room, Vec* pos, GXColor color, f32 size);
static inline void drawShadowCF(s32 room, JGeometry::TVec3f* pos, f32 size, u8 alpha = 0x80) {
    fn_80158B5C(lbl_8053AB10->mFxMgr, room, pos, JUtility::TColor(0, 0, 0, alpha), size);
}
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 fn_801F7A08(void* a, u32 b);
extern "C" void fn_801F35AC(Actor* a);
extern "C" void fn_801F71A4(void* a, f32 b, f32 c, f32 d);
extern "C" s32 fn_801CD664(s32 n);
extern "C" u8 fn_802DE764(s32 a, s32 b, s32 c);
extern "C" void fn_80458FF0(void* a, s32 b, s32 c, s32 d);
extern "C" s32 fn_8013CC50(u32 id, void* p, u32 f, u32 a, u32 b, u32 c, u32 d, u32 e, f32 g);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" const f32 lbl_80540E88;
extern "C" const f32 lbl_80540E8C;
extern "C" const f32 lbl_80540E90;
extern "C" const f32 lbl_80540E94;
extern "C" const f32 lbl_80540E98;
extern void* lbl_8053AF80;


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

#pragma opt_propagation on
extern "C" void fn_802CFE2C(Actor* p) {
    if (*(u8*)((u8*)p + 0x26c) == 1) {
        SobDrawParams drawParams;
        JGeometry::TVec3f pos0;
        JGeometry::TVec3f pos1;
        JGeometry::TVec3f pos2;
        s32 spriteId;
        u32 sobRes;

        drawParams.renderFlags[1] = -1;
        drawParams.primaryColor.rgba.a = (u8)(s32)(255.0 - *(f32*)((u8*)p + 0x270));
        spriteId = *(s32*)((u8*)p + 0x264) + 0x175;
        pos0.set(lbl_80540E7C + p->field_0C.x, lbl_80540E78 + p->field_0C.y, p->field_0C.z);
        if ((s32)p->field_04 < 8) {
            sobRes = lbl_8053AAF8->mResMgr->getResource(FOURCC_SOB, lbl_8046E040);
            fn_802F86CC(lbl_8053AB10->mSobRenderer, &pos0, sobRes, spriteId, lbl_80540E80, lbl_80540E80, &drawParams);
        }

        drawParams.primaryColor.rgba.a = (u8)(s32)*(f32*)((u8*)p + 0x270);
        spriteId = lbl_8046DFD0[*(s32*)((u8*)p + 0x264)] + 0x175;
        pos1.set(lbl_80540E7C + p->field_0C.x, lbl_80540E78 + p->field_0C.y, p->field_0C.z);
        if ((s32)p->field_04 < 8) {
            sobRes = lbl_8053AAF8->mResMgr->getResource(FOURCC_SOB, lbl_8046E040);
            fn_802F86CC(lbl_8053AB10->mSobRenderer, &pos1, sobRes, spriteId, lbl_80540E80, lbl_80540E80, &drawParams);
        }

        pos2.set(lbl_80540E7C + p->field_0C.x, lbl_80540E78 + p->field_0C.y, p->field_0C.z);
        drawShadowCF(p->field_04, &pos2, lbl_80540E84, 0x80);
    }
}
#pragma opt_propagation off
#pragma opt_strength_reduction off
extern "C" void fn_802D010C(Actor* p) {
    s32* tbl = lbl_8046DFD0;
    s32* q;
    s32 r28;
    s32 i;
    s32 r;
    CFActor* indexed;
    int spawnParam;
    s32 offset;
    f32 x, y, z;
    s32 created;

    switch (*(s32*)((u8*)p + 0x230)) {
    case 0:
    case 1:
        if (*(s32*)((u8*)p + 0x250) == 0 || (u8)p->v11()) {
            if (*(s32*)((u8*)p + 0x230) == 0) {
                *(s32*)((u8*)p + 0x230) = 1;
                *(s32*)((u8*)p + 0x268) = 0xc;
                *(s32*)((u8*)p + 0x264) = 0;
                if (fn_802DE764(0, 3, 10)) {
                    fn_80458FF0(lbl_8053AF80, 0x1000021, 0, 0);
                }
            }
            *(s32*)((u8*)p + 0x248) -= 1;
            if (*(s32*)((u8*)p + 0x248) == 0) {
                if (fn_802DE764(0, 3, 6)) {
                    if (*(s32*)((u8*)p + 0x240) == 0) {
                        *(s32*)((u8*)p + 0x254) = 1;
                    } else {
                        *(s32*)((u8*)p + 0x254) = 0;
                    }
                }
                *(s32*)((u8*)p + 0x248) = *(s32*)((u8*)p + 0x24c);
                if (*(s32*)((u8*)p + 0x240) < *(s32*)((u8*)p + 0x244)) {
                    indexed = (CFActor*)((u8*)p + ((CFActor*)p)->field_254 * 4);
                    s32 type = indexed->field_234[0];
                    switch (type) {
                    case 0:
                                                created = Actor_CreateByID(fn_801F856C(), 0x48494E4F, p->field_04, (f32*)((u8*)p + 0x258), 0, -1, -1);
                        indexed = (CFActor*)((u8*)p + ((CFActor*)p)->field_240 * 4);
                        indexed->field_274[0] = created;
                        break;
                    case 1:
                    case 2:
                    case 3:
                    case 4:
                    case 5:
                    case 10:
                    case 11:
                    case 13:
                    case 14:
                    case 18:
                        offset = type * 4;
                        q = tbl + 4;
                        q = (s32*)*(s32*)((u8*)q + offset);
                        created = Actor_CreateByID(fn_801F856C(), 0x534C5231, p->field_04, (f32*)((u8*)p + 0x258), (u32)q, -1, -1);
                        indexed = (CFActor*)((u8*)p + ((CFActor*)p)->field_240 * 4);
                        indexed->field_274[0] = created;
                        break;
                    case 6:
                    case 7:
                    case 8:
                    case 9:
                        offset = type * 4;
                        q = tbl + 4;
                        q = (s32*)*(s32*)((u8*)q + offset);
                        created = Actor_CreateByID(fn_801F856C(), 0x52555059, p->field_04, (f32*)((u8*)p + 0x258), (u32)q, -1, -1);
                        indexed = (CFActor*)((u8*)p + ((CFActor*)p)->field_240 * 4);
                        indexed->field_274[0] = created;
                        break;
                    case 12:
                    case 15:
                    case 17:
                        offset = type * 4;
                        q = tbl + 4;
                        q = (s32*)*(s32*)((u8*)q + offset);
                        created = Actor_CreateByID(fn_801F856C(), 0x424D5459, p->field_04, (f32*)((u8*)p + 0x258), (u32)q, -1, -1);
                        indexed = (CFActor*)((u8*)p + ((CFActor*)p)->field_240 * 4);
                        indexed->field_274[0] = created;
                        break;
                    case 19:
                        offset = type * 4;
                        q = tbl + 4;
                        q = (s32*)*(s32*)((u8*)q + offset);
                        created = Actor_CreateByID(fn_801F856C(), 0x484E5259, p->field_04, (f32*)((u8*)p + 0x258), (u32)q, -1, -1);
                        indexed = (CFActor*)((u8*)p + ((CFActor*)p)->field_240 * 4);
                        indexed->field_274[0] = created;
                        break;
                    case 0x10:
                        if (fn_801F7A08(fn_801F856C(), 0x424D5459) < 0) {
                                                    created = Actor_CreateByID(fn_801F856C(), 0x424D5459, p->field_04, (f32*)((u8*)p + 0x258), 0x14, -1, -1);
                        indexed = (CFActor*)((u8*)p + ((CFActor*)p)->field_240 * 4);
                        indexed->field_274[0] = created;
                        }
                        break;
                    default:
                        break;
                    }
                    *(s32*)((u8*)p + 0x240) = *(s32*)((u8*)p + 0x240) + 1;
                    if (*(s32*)((u8*)p + 0x240) >= *(s32*)((u8*)p + 0x244)) {
                        *(s32*)((u8*)p + 0x230) = 2;
                    }
                } else {
                    *(s32*)((u8*)p + 0x230) = 2;
                }
            } else if (*(s32*)((u8*)p + 0x248) == 0x1d) {
                s32 type;
                r28 = -1;
                r = fn_801CD664(100);
                if (r < 10) {
                    *(s32*)((u8*)p + 0x254) = 2;
                } else if (r < 0x28) {
                    *(s32*)((u8*)p + 0x254) = 1;
                } else {
                    *(s32*)((u8*)p + 0x254) = 0;
                }
                indexed = (CFActor*)((u8*)p + ((CFActor*)p)->field_254 * 4);
                if (indexed->field_234[0] == 0x10) {
                    if (fn_801F7A08(fn_801F856C(), 0x424D5459) < 0) {
                        r28 = 1;
                    }
                }
                indexed = (CFActor*)((u8*)p + ((CFActor*)p)->field_254 * 4);
                type = indexed->field_234[0];
                if (!(type == 10 || (u32)(type - 0xb) <= 4 || type == 0x11 || type == 0x13 || type == 0x10) || r28 >= 0) {
                    JGeometry::TVec3f v0(*(f32*)((u8*)p + 0x258), *(f32*)((u8*)p + 0x25c) - lbl_80540E88, *(f32*)((u8*)p + 0x260));
                    fn_8013CC50(p->field_04, &v0, 0x1d3, 0, 0, 0, 0, 1, lbl_80540E80);
                    JGeometry::TVec3f v1(*(f32*)((u8*)p + 0x258), *(f32*)((u8*)p + 0x25c) - lbl_80540E88, *(f32*)((u8*)p + 0x260));
                    fn_8013CC50(p->field_04, &v1, 0x1d4, 0, -1, 0, 0, 1, lbl_80540E80);
                    JGeometry::TVec3f v2(*(f32*)((u8*)p + 0x258), *(f32*)((u8*)p + 0x25c) - lbl_80540E88, *(f32*)((u8*)p + 0x260));
                    fn_8013CC50(p->field_04, &v2, 0x1d5, 0, 0, 0, 0, 1, lbl_80540E80);
                }
            }
        } else if (*(s32*)((u8*)p + 0x230) == 1) {
            *(s32*)((u8*)p + 0x230) = 0;
            *(s32*)((u8*)p + 0x264) = 3;
        }
        if (*(s32*)((u8*)p + 0x230) == 1) {
            if (*(s32*)((u8*)p + 0x268) == 0) {
                q = tbl + 24;
                *(s32*)((u8*)p + 0x268) = q[*(s32*)((u8*)p + 0x264)];
                q = tbl;
                *(s32*)((u8*)p + 0x264) = q[*(s32*)((u8*)p + 0x264)];
                *(f32*)((u8*)p + 0x270) = lbl_80540E8C;
            } else {
                *(s32*)((u8*)p + 0x268) -= 1;
                fn_801F71A4((u8*)p + 0x270, lbl_80540E90, lbl_80540E94, lbl_80540E98);
            }
        }
        break;
    case 2:
        for (q = (s32*)p, i = 0; i < *(s32*)((u8*)p + 0x244) + 1; i++) {
            r28 = q[0x9d];
            if (r28 >= 0) {
                if (fn_801F666C(fn_801F856C(), r28) == 0) {
                    q[0x9d] = -1;
                    *(s32*)((u8*)p + 0x674) += 1;
                }
            }
            q++;
        }
        if (*(s32*)((u8*)p + 0x674) >= *(s32*)((u8*)p + 0x244) - 1) {
            fn_801F35AC(p);
        }
        break;
    }
}
#pragma opt_propagation reset
#pragma opt_strength_reduction reset
extern "C" const f32 lbl_80540E7C;
extern "C" const f32 lbl_80540E8C;
extern "C" const f32 lbl_80540E9C;
extern "C" const f32 lbl_80540EA0;
extern "C" const f32 lbl_80540EA4;
extern "C" void fn_802D06BC(Actor* p) {
    s32 neg = -1;
    u8* b = (u8*)p;
    s32 i;

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



