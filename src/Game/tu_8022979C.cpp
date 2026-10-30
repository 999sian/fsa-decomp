#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/ItemBase.h"
#include "Game/SinitPoolChain.h"

extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" char lbl_8046ADF0[];
extern "C" const f32 lbl_8053FFD8;
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, f32 sx, f32 sy, struct SobDrawParam* prm);
extern "C" void fn_803075AC(void* p, s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

extern "C" f32* fn_8023E724(u32 idx);

struct SobResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* getRes(u32 type, const char* name);
};

struct SobDrawParam {
    SobDrawParam() : m40(-1), m44(-1) {
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

static inline void sobDraw(u8* p, void* prm, s32 flag) {
    s32 id = *(s32*)(p + 0x234);
    void* pos = p + 0xc;
    if (*(s32*)(p + 4) < 8) {
        SobResMgr* mgr = *(SobResMgr**)(lbl_8053AAF8 + 0xa4);
        void* res = mgr->getRes(0x534F4220, lbl_8046ADF0);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053FFD8, lbl_8053FFD8, (SobDrawParam*)prm);
    }
    fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234), 0, 1, -1, flag, 0, 0);
}


extern "C" char lbl_804A6E20[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8022979C(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804A6E20;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

#pragma opt_propagation off
extern "C" void fn_802297FC(Actor* this_) {
    u8* p = (u8*)this_;
    void* pos;
    s32 id;
    DrawRec prm;
    switch ((*(u32*)(p + 0x90) >> 2) & 0x3f) {
    case 0:
        id = *(s32*)(p + 0x234);
        pos = p + 0xc;
        if (*(s32*)(p + 4) < 8) {
            void* res = (*(SobResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_8046ADF0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053FFD8, lbl_8053FFD8, 0);
        }
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234), 0, 1, -1, 1, 0, 0);
        break;
    case 1:
        id = *(s32*)(p + 0x234);
        pos = p + 0xc;
        if (*(s32*)(p + 4) < 8) {
            void* res = (*(SobResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_8046ADF0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053FFD8, lbl_8053FFD8, 0);
        }
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234), 0, 1, -1, 0, 0, 0);
        break;
    case 2:
        id = *(s32*)(p + 0x234);
        pos = p + 0xc;
        if (*(s32*)(p + 4) < 8) {
            void* res = (*(SobResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_8046ADF0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053FFD8, lbl_8053FFD8, 0);
        }
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234), 0, 1, -1, 1, 0, 0);
        break;
    case 3:
        id = *(s32*)(p + 0x234);
        pos = p + 0xc;
        if (*(s32*)(p + 4) < 8) {
            void* res = (*(SobResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_8046ADF0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053FFD8, lbl_8053FFD8, 0);
        }
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234), 0, 1, -1, 1, 0, 0);
        break;
    case 4:
    case 14:
        id = *(s32*)(p + 0x234);
        pos = p + 0xc;
        if (*(s32*)(p + 4) < 8) {
            void* res = (*(SobResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_8046ADF0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053FFD8, lbl_8053FFD8, 0);
        }
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234), 0, 1, -1, 1, 0, 0);
        break;
    case 5:
        prm.b1c = 2;
        prm.b2d = 1;
        id = *(s32*)(p + 0x234);
        pos = p + 0xc;
        if (*(s32*)(p + 4) < 8) {
            void* res = (*(SobResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_8046ADF0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053FFD8, lbl_8053FFD8, (SobDrawParam*)&prm);
        }
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234), 0, 1, -1, 1, 0, 0);
        break;
    case 6:
        id = *(s32*)(p + 0x234);
        pos = p + 0xc;
        if (*(s32*)(p + 4) < 8) {
            void* res = (*(SobResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_8046ADF0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053FFD8, lbl_8053FFD8, 0);
        }
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234), 0, 1, -1, 1, 0, 0);
        break;
    case 7:
        id = *(s32*)(p + 0x234);
        pos = p + 0xc;
        if (*(s32*)(p + 4) < 8) {
            void* res = (*(SobResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_8046ADF0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053FFD8, lbl_8053FFD8, 0);
        }
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234), 0, 1, -1, 1, 0, 0);
        break;
    case 8:
        id = *(s32*)(p + 0x234);
        pos = p + 0xc;
        if (*(s32*)(p + 4) < 8) {
            void* res = (*(SobResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_8046ADF0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053FFD8, lbl_8053FFD8, 0);
        }
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234), 0, 1, -1, 1, 0, 0);
        break;
    case 9:
        id = *(s32*)(p + 0x234);
        pos = p + 0xc;
        if (*(s32*)(p + 4) < 8) {
            void* res = (*(SobResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_8046ADF0);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053FFD8, lbl_8053FFD8, 0);
        }
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234), 0, 1, -1, 1, 0, 0);
        break;
    }
}
#pragma opt_propagation reset
extern "C" s32 fn_80237774(u32 idx);
extern "C" s32 lbl_80529DEC[];
extern "C" u16 fn_8022461C(void* pos, u32 room);
extern "C" u8 fn_80239D38(void);
extern "C" u8 fn_80236B50(u32 idx);
extern "C" u8 fn_80236AB4(u32 idx);
extern "C" u8 fn_80235274(u32 idx);
extern "C" void fn_802A20F0(void* mgr, void* pos, u32 idx, u32 room, s32 a, s32 b);
extern "C" void* lbl_8053AC98;
extern "C" const f32 lbl_8046ACC8[][2];
static inline void spawnSplash(u8* p, const f32* t, s32 n) {
    for (s32 i = 0; i < n; i++, t += 2) {
        JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(p + 0xc));
        pos.x = pos.x + t[0];
        pos.y = pos.y + t[1];
        fn_802A20F0(lbl_8053AC98, &pos, *(u32*)(p + 0x90) & 3, *(u32*)(p + 0x4), 0, 1);
    }
}

struct SplashOffsets {
    f32 small[9][2];
    f32 medium[12][2];
    f32 large[16][2];
};
extern "C" u8 fn_8022FA80(u32 idx);
extern "C" s32 fn_8022F340(u32 idx);
extern "C" u8 fn_8037E694(u32 idx);
extern "C" const f32 lbl_8053FFDC;
extern "C" const f32 lbl_8053FFE0;
extern "C" const f32 lbl_8053FFE4;
extern "C" const f32 lbl_8053FFE8;
extern "C" const f32 lbl_8053FFEC;
extern "C" const f32 lbl_8053FFF0;
extern "C" const f32 lbl_8053FFF4;

static inline void spawnSplashAt(u8* p, const f32 (*tbl)[2], s32 start, s32 n) {
    const f32* t = tbl[start];
    for (s32 i = 0; i < n; i++, t += 2) {
        JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(p + 0xc));
        pos.x = pos.x + t[0];
        pos.y = pos.y + t[1];
        fn_802A20F0(lbl_8053AC98, &pos, *(u32*)(p + 0x90) & 3, *(u32*)(p + 0x4), 0, 1);
    }
}

static inline bool playerAtGoal(u32 idx) {
    return fn_80237774(idx) == lbl_80529DEC[idx + 0x36];
}

static inline u8 playerLinkState(u32 idx) {
    s32 slot = fn_8022F340(idx);
    return (lbl_8053AAF8[0x83] >> (slot << 1)) & 3;
}

extern "C" void fn_80229F1C(Actor* this_) {
    u8* p = (u8*)this_;
    const f32 (*tbl)[2] = lbl_8046ACC8;
    s32 i;
    const f32* t;
    *(u32*)(p + 0x230) = *(u32*)(p + 0x230) + 1;
    u32 flags = *(u32*)(p + 0x90);
    switch ((flags >> 2) & 0x3f) {
    case 0:
        if (*(u32*)(p + 0x230) <= 2) {
            *(s32*)(p + 0x234) = 0x85;
        } else if (*(u32*)(p + 0x230) <= 4) {
            *(s32*)(p + 0x234) = 0x86;
        } else if (*(u32*)(p + 0x230) <= 6) {
            *(s32*)(p + 0x234) = 0x87;
        } else if (*(u32*)(p + 0x230) <= 8) {
            *(s32*)(p + 0x234) = 0x88;
        } else {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 1: {
        JGeometry::setTVec3f(fn_8023E724(flags & 3), (f32*)(p + 0xc));
        *(s32*)(p + 0x234) = ((*(u32*)(p + 0x230) >> 1) & 7) + 0x7d;
        u32 idx = *(u32*)(p + 0x90) & 3;
        s32 r = fn_80237774(idx);
        if (r == lbl_80529DEC[idx + 0x36]) {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    }
    case 2:
        if (*(u32*)(p + 0x230) <= 2) {
            *(s32*)(p + 0x234) = 0x2ab;
        } else if (*(u32*)(p + 0x230) <= 4) {
            *(s32*)(p + 0x234) = 0x2ac;
        } else if (*(u32*)(p + 0x230) <= 6) {
            *(s32*)(p + 0x234) = 0x2ad;
        } else if (*(u32*)(p + 0x230) <= 8) {
            *(s32*)(p + 0x234) = 0x2ae;
        } else if (*(u32*)(p + 0x230) <= 10) {
            *(s32*)(p + 0x234) = 0x2ab;
        } else {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 3: {
        *(f32*)(p + 0x10) -= lbl_8053FFDC;
        *(s32*)(p + 0x234) = 0x1aa;
        u8* rng = lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        u32 bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        if ((s32)(lbl_8053FFE0 * (*(f32*)&bits - lbl_8053FFD8)) == 0) {
            *(f32*)(p + 0xc) -= lbl_8053FFDC;
        } else {
            *(f32*)(p + 0xc) += lbl_8053FFDC;
        }
        if (*(f32*)(p + 0x10) < *(f32*)(p + 0x28) - lbl_8053FFE4 || fn_8022461C(p + 0xc, *(u32*)(p + 0x4)) != 0x3b) {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    }
    case 4:
    case 14:
        JGeometry::setTVec3f(fn_8023E724(flags & 3), (f32*)(p + 0xc));
        *(f32*)(p + 0x14) += lbl_8053FFE8;
        if (*(u32*)(p + 0x230) >= 0xc) {
            *(u32*)(p + 0x230) = 0;
        }
        *(s32*)(p + 0x234) = (u16)(*(u32*)(p + 0x230) / 3) + 0x1c3;
        if ((s32)((*(u32*)(p + 0x90) >> 2) & 0x3f) == 0xe) {
            *(f32*)(p + 0xc) -= lbl_8053FFEC;
            if (fn_80239D38() || !fn_80236B50(*(u32*)(p + 0x90) & 3) || fn_80236AB4(*(u32*)(p + 0x90) & 3)) {
                *(u8*)(p + 0x11c) = 0;
            }
        } else if (!fn_80235274(*(u32*)(p + 0x90) & 3)) {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 5:
        if (*(u32*)(p + 0x230) == 1) {
            t = tbl[0];
            for (i = 0; i < 9; i++, t += 2) {
                JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(p + 0xc));
                pos.x = pos.x + t[0];
                pos.y = pos.y + t[1];
                fn_802A20F0(lbl_8053AC98, &pos, *(u32*)(p + 0x90) & 3, *(u32*)(p + 0x4), 0, 1);
            }
        } else if (*(u32*)(p + 0x230) == 0xb) {
            t = tbl[9];
            for (i = 0; i < 12; i++, t += 2) {
                JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(p + 0xc));
                pos.x = pos.x + t[0];
                pos.y = pos.y + t[1];
                fn_802A20F0(lbl_8053AC98, &pos, *(u32*)(p + 0x90) & 3, *(u32*)(p + 0x4), 0, 1);
            }
        } else if (*(u32*)(p + 0x230) == 0x15) {
            t = tbl[21];
            for (i = 0; i < 16; i++, t += 2) {
                JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(p + 0xc));
                pos.x = pos.x + t[0];
                pos.y = pos.y + t[1];
                fn_802A20F0(lbl_8053AC98, &pos, *(u32*)(p + 0x90) & 3, *(u32*)(p + 0x4), 0, 1);
            }
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 6:
    case 8:
        JGeometry::setTVec3f(fn_8023E724(flags & 3), (f32*)(p + 0xc));
        *(f32*)(p + 0xc) += lbl_8053FFF0;
        *(f32*)(p + 0x14) += lbl_8053FFF4;
        if (fn_8022FA80(*(u32*)(p + 0x90) & 3) == 1 || (s32)((*(u32*)(p + 0x90) >> 2) & 0x3f) == 8) {
            if (*(u32*)(p + 0x230) >= 2 && *(s32*)(p + 0x234) == 0x2a3) {
                *(u32*)(p + 0x230) = 2;
                if (playerLinkState(*(u32*)(p + 0x90) & 3) == 2) {
                    *(s32*)(p + 0x234) = 0x2a5;
                } else if (fn_8037E694(*(u32*)(p + 0x90) & 3) == 1) {
                    if (*(s32*)(p + 0x4) < 8) {
                        *(s32*)(p + 0x234) = 0x2a5;
                    } else {
                        *(s32*)(p + 0x234) = 0x2a8;
                    }
                } else if (fn_8037E694(*(u32*)(p + 0x90) & 3) == 2) {
                    if (*(s32*)(p + 0x4) < 8) {
                        *(s32*)(p + 0x234) = 0x2a4;
                    } else {
                        *(s32*)(p + 0x234) = 0x2a5;
                    }
                } else if (*(s32*)(p + 0x4) < 8) {
                    *(s32*)(p + 0x234) = 0x2a5;
                } else {
                    *(s32*)(p + 0x234) = 0x2a8;
                }
            }
        } else {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 7:
    case 9:
        JGeometry::setTVec3f(fn_8023E724(flags & 3), (f32*)(p + 0xc));
        *(f32*)(p + 0xc) -= lbl_8053FFF0;
        *(f32*)(p + 0x14) += lbl_8053FFF4;
        if (fn_8022FA80(*(u32*)(p + 0x90) & 3) == 1 || (s32)((*(u32*)(p + 0x90) >> 2) & 0x3f) == 9) {
            if (*(u32*)(p + 0x230) > 2 && *(s32*)(p + 0x234) == 0x2a3) {
                *(u32*)(p + 0x230) = 2;
                if (playerLinkState(*(u32*)(p + 0x90) & 3) == 2) {
                    *(s32*)(p + 0x234) = 0x2a6;
                } else if (fn_8037E694(*(u32*)(p + 0x90) & 3) == 1) {
                    if (*(s32*)(p + 0x4) < 8) {
                        *(s32*)(p + 0x234) = 0x2a6;
                    } else {
                        *(s32*)(p + 0x234) = 0x2a9;
                    }
                } else if (fn_8037E694(*(u32*)(p + 0x90) & 3) == 2) {
                    if (*(s32*)(p + 0x4) < 8) {
                        *(s32*)(p + 0x234) = 0x2a7;
                    } else {
                        *(s32*)(p + 0x234) = 0x2a6;
                    }
                } else if (*(s32*)(p + 0x4) < 8) {
                    *(s32*)(p + 0x234) = 0x2a6;
                } else {
                    *(s32*)(p + 0x234) = 0x2a9;
                }
            }
        } else {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 10:
        JGeometry::setTVec3f(fn_8023E724(flags & 3), (f32*)(p + 0xc));
        if (*(u32*)(p + 0x230) <= 2) {
            *(s32*)(p + 0x234) = 0x2f5;
        } else {
            *(s32*)(p + 0x234) = 0x2f6;
        }
        if (*(u32*)(p + 0x230) > 4) {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 11:
        if (*(u32*)(p + 0x230) <= 2) {
            *(s32*)(p + 0x234) = 0x306;
        } else if (*(u32*)(p + 0x230) <= 4) {
            *(s32*)(p + 0x234) = 0x307;
        } else if (*(u32*)(p + 0x230) <= 6) {
            *(s32*)(p + 0x234) = 0x308;
        } else if (*(u32*)(p + 0x230) <= 8) {
            *(s32*)(p + 0x234) = 0x309;
        } else if (*(u32*)(p + 0x230) <= 10) {
            *(s32*)(p + 0x234) = 0x30a;
        } else if (*(u32*)(p + 0x230) <= 12) {
            *(s32*)(p + 0x234) = 0x30b;
        } else {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 12:
        if (*(u32*)(p + 0x230) <= 2) {
            *(s32*)(p + 0x234) = 0x30c;
        } else if (*(u32*)(p + 0x230) <= 4) {
            *(s32*)(p + 0x234) = 0x30d;
        } else if (*(u32*)(p + 0x230) <= 6) {
            *(s32*)(p + 0x234) = 0x30e;
        } else {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 13:
        if (*(u32*)(p + 0x230) <= 2) {
            *(s32*)(p + 0x234) = 0x300;
        } else if (*(u32*)(p + 0x230) <= 4) {
            *(s32*)(p + 0x234) = 0x301;
        } else if (*(u32*)(p + 0x230) <= 6) {
            *(s32*)(p + 0x234) = 0x302;
        } else if (*(u32*)(p + 0x230) <= 8) {
            *(s32*)(p + 0x234) = 0x303;
        } else if (*(u32*)(p + 0x230) <= 10) {
            *(s32*)(p + 0x234) = 0x304;
        } else if (*(u32*)(p + 0x230) <= 12) {
            *(s32*)(p + 0x234) = 0x305;
        } else {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    }
}

extern "C" u8 fn_8022F514(u32 idx);
extern "C" f32* fn_8023E724(u32 idx);
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" char lbl_8046ADF0[];
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, f32 sx, f32 sy, struct SobDrawParam* prm);
extern "C" void fn_803075AC(void* p, s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

extern "C" const f32 lbl_8053FFD8;
extern "C" const f32 lbl_8053FFE0;
extern "C" const f32 lbl_8053FFE8;
extern "C" const f32 lbl_8053FFEC;
extern "C" const f32 lbl_8053FFF0;
extern "C" const f32 lbl_8053FFF4;
extern "C" const f32 lbl_8053FFF8;
extern "C" void fn_8022A83C(u8* p) {
    s32 mode;
    u32 flags = *(u32*)(p + 0x90);
    mode = (flags >> 2) & 0x3f;
    f32* src;
    if (mode != 5) {
        if (mode == 1) {
            if (fn_8022F514(flags & 3)) {
                *(u8*)(p + 0x11c) = 0;
                return;
            }
        } else if (mode != 6 && mode != 7 && mode != 8 && mode != 9 && *(s32*)(p + 0x4) < 8) {
            *(u8*)(p + 0x11c) = 0;
            return;
        }
    }
    mode = (*(u32*)(p + 0x90) >> 2) & 0x3f;
    if (mode == 3) {
        u8* rng = lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        u32 bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        *(f32*)(p + 0xc) += (f32)(s32)(lbl_8053FFEC * (*(f32*)&bits - lbl_8053FFD8)) - lbl_8053FFE0;
        rng = lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        u32 bits2 = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        *(f32*)(p + 0x10) += (f32)(s32)(lbl_8053FFEC * (*(f32*)&bits2 - lbl_8053FFD8)) - lbl_8053FFF8;
    } else if (mode == 4) {
        *(f32*)(p + 0x14) += lbl_8053FFE8;
    } else if (mode == 0xe) {
        *(f32*)(p + 0xc) -= lbl_8053FFEC;
        *(f32*)(p + 0x14) += lbl_8053FFE8;
    }
    *(u32*)(p + 0x108) = 0;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x234) = 0;
    mode = (*(u32*)(p + 0x90) >> 2) & 0x3f;
    switch (mode) {
        case 0:
            *(s32*)(p + 0x234) = 0x85;
            break;
        case 1:
            *(s32*)(p + 0x234) = 0x7d;
            break;
        case 2:
            *(s32*)(p + 0x234) = 0x2ab;
            break;
        case 3:
            *(s32*)(p + 0x234) = 0x1aa;
            break;
        case 4:
        case 14:
            *(s32*)(p + 0x234) = 0x1c3;
            break;
        case 6:
        case 8:
            src = fn_8023E724(*(u32*)(p + 0x90) & 3);
            JGeometry::setTVec3f(src, (f32*)(p + 0xc));
            *(f32*)(p + 0xc) += lbl_8053FFF0;
            *(f32*)(p + 0x14) += lbl_8053FFF4;
            *(s32*)(p + 0x234) = 0x2a3;
            break;
        case 7:
        case 9:
            src = fn_8023E724(*(u32*)(p + 0x90) & 3);
            JGeometry::setTVec3f(src, (f32*)(p + 0xc));
            *(f32*)(p + 0xc) -= lbl_8053FFF0;
            *(f32*)(p + 0x14) += lbl_8053FFF4;
            *(s32*)(p + 0x234) = 0x2a3;
            break;
        case 10:
            *(s32*)(p + 0x234) = 0x2f5;
            break;
        case 11:
            *(s32*)(p + 0x234) = 0x306;
            break;
        case 12:
            *(s32*)(p + 0x234) = 0x30c;
            break;
        case 13:
            *(s32*)(p + 0x234) = 0x300;
            break;
    }
    *(u8*)(p + 0x11f) = 1;
}

extern "C" void fn_8022AB40(void) {
}

