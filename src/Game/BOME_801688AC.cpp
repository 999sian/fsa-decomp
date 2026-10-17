#include "types.h"
#include "Game/SinitPoolChain.h"
#include "Game/Actor.h"

struct SwbmDrawParam {
    SwbmDrawParam() : m40(-1), m44(-1) {
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

struct SwbmResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* getRes(u32 type, const char* name);
};

extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern const char lbl_80466350[];
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, f32 sx, f32 sy, SwbmDrawParam* prm);
extern "C" void fn_803075AC(void* p, s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

extern "C" char __vt__4BOME[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_801688AC(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4BOME;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_80168E78(char* this_) {
    SwbmDrawParam prm;
    prm.reset();
    prm.m60 = 0x11;
    s32 id = *(s32*)(this_ + 0x250) + 0x69;
    if (*(s32*)(this_ + 4) < 8) {
        void* res = (*(SwbmResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_80466350);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, id, 1.0f, 1.0f, &prm);
    }
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x250) + 0x69, 0, 2,
                -1, 0, 0, 0);
}

