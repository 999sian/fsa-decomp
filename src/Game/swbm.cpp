// SWBM actor. TU 8017A44C-8017B140.
// Functions: dtor, draw (slot 6, TODO), update (slot 3, TODO), helper (TODO), init (slot 1).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" s32 fn_80237060(s32 id);
extern "C" u32 fn_8023B630(s32 id);
extern void* lbl_804A1160[];
extern const char lbl_80466880[];
extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* entry, s32 a, void* b, s32 d, const char* e);
extern "C" u16 fn_8022461C(s32 a, s32 b);
extern "C" u16 fn_80226850(s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);

// SWBM destructor
extern "C" void* fn_8017A44C(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A1160;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// SWBM init (vtable slot 1)
extern "C" void fn_8017AE18(char* this_) {
    *(f32*)(this_ + 0x80) = -2.0f;
    *(f32*)(this_ + 0x84) = -2.0f;
    *(f32*)(this_ + 0x88) = 2.0f;
    *(f32*)(this_ + 0x8c) = 2.0f;
    *(f32*)(this_ + 0x60) = -4.0f;
    *(f32*)(this_ + 0x64) = -4.0f;
    *(f32*)(this_ + 0x68) = 4.0f;
    *(f32*)(this_ + 0x6c) = 4.0f;
    *(u32*)(this_ + 0x98) = (*(u32*)(this_ + 0x90) >> 4) & 3;
    *(u32*)(this_ + 0x258) = *(u32*)(this_ + 0x90) & 0xf;
    *(u32*)(this_ + 0x25c) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    if (fn_80237060(*(s32*)(this_ + 0x258)) == 1) {
        *(u8*)(this_ + 0x11c) = 0;
        return;
    }
    *(u8*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(u32*)(this_ + 0x118) = fn_8023B630(*(s32*)(this_ + 0x258));
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(s32*)(this_ + 0x23c) = 2;
    *(s32*)(this_ + 0x230) = 0;
    fn_801F0E34(this_, 0x30026, 0);
}

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
extern const char lbl_80466894[];
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, f32 sx, f32 sy, SwbmDrawParam* prm);
extern "C" void fn_803075AC(void* p, s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);

extern "C" void fn_8017A4AC(char* this_) {
    SwbmDrawParam prm;
    prm.reset();
    if (*(s32*)(this_ + 0x230) == 1 || *(s32*)(this_ + 0x230) == 2) {
        if (*(s32*)(this_ + 0x240) == 0) {
            return;
        }
        prm.m4D = 1;
        prm.m60 = 0x11;
    }
    s32 id = *(s32*)(this_ + 0x254) + 0x12d;
    if (*(s32*)(this_ + 4) < 8) {
        void* res = (*(SwbmResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_80466894);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, id, 1.0f, 1.0f, &prm);
    }
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x254) + 0x12d, 0, 2,
                -1, 0, 0, 0);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
