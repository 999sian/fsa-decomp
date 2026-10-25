#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"

extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" char lbl_8046ADF0[];
extern "C" f32 lbl_8053FFD8;
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, f32 sx, f32 sy, struct SobDrawParam* prm);
extern "C" void fn_803075AC(void* p, s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

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

static inline void sobDraw(u8* p, SobDrawParam* prm, s32 flag) {
    s32 room = *(s32*)(p + 4);
    u8* pos = p + 0xc;
    s32 id = *(s32*)(p + 0x234);
    if (room < 8) {
        SobResMgr* mgr = *(SobResMgr**)(lbl_8053AAF8 + 0xa4);
        void* res = mgr->getRes(0x534F4220, lbl_8046ADF0);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, lbl_8053FFD8, lbl_8053FFD8, prm);
        fn_803075AC(*(void**)(p + 0x198), room, p + 0xc, id, 0, 1, -1, flag, 0, 0);
    }
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

extern "C" void fn_802297FC(Actor* this_) {
    u8* p = (u8*)this_;
    SobDrawParam prm;
    prm.reset();
    switch ((*(u32*)(p + 0x90) >> 2) & 0x3f) {
    case 0:
        sobDraw(p, 0, 1);
        break;
    case 1:
        sobDraw(p, 0, 0);
        break;
    case 2:
    case 3:
        sobDraw(p, 0, 1);
        break;
    case 4:
    case 14:
        sobDraw(p, 0, 1);
        break;
    case 5:
        prm.m4C = 2;
        prm.m5D = 1;
        sobDraw(p, &prm, 1);
        break;
    case 6:
    case 8:
    case 7:
    case 9:
        sobDraw(p, 0, 1);
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

extern "C" f32 lbl_8053FFD8;
extern "C" f32 lbl_8053FFE0;
extern "C" f32 lbl_8053FFE8;
extern "C" f32 lbl_8053FFEC;
extern "C" f32 lbl_8053FFF0;
extern "C" f32 lbl_8053FFF4;
extern "C" f32 lbl_8053FFF8;
extern "C" void fn_8022A83C(u8* p) {
    s32 mode = (*(u32*)(p + 0x90) >> 2) & 0x3f;
    f32* src;
    if (mode != 5) {
        if (mode == 1) {
            if (fn_8022F514(*(u32*)(p + 0x90) & 3)) {
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
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        *(f32*)(p + 0x10) += (f32)(s32)(lbl_8053FFEC * (*(f32*)&bits - lbl_8053FFD8)) - lbl_8053FFF8;
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
    if (mode <= 0xe) {
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
            src = fn_8023E724(mode & 3);
            *(f32*)(p + 0xc) = src[0];
            *(f32*)(p + 0x10) = src[1];
            *(f32*)(p + 0x14) = src[2];
            *(f32*)(p + 0xc) += lbl_8053FFF0;
            *(f32*)(p + 0x14) += lbl_8053FFF4;
            *(s32*)(p + 0x234) = 0x2a3;
            break;
        case 7:
        case 9:
            src = fn_8023E724(mode & 3);
            *(f32*)(p + 0xc) = src[0];
            *(f32*)(p + 0x10) = src[1];
            *(f32*)(p + 0x14) = src[2];
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
    }
    *(u8*)(p + 0x11f) = 1;
}

