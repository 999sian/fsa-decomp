#include "types.h"
#include "Game/SinitPoolChain.h"

extern "C" char lbl_8049DB90[];
extern "C" f32 lbl_8053C7D8;
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void fn_8010E074(u8*);

struct DMLKResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getRes(s32 type, char* name);
};

extern "C" s32 fn_8011BDE4(u8* this_) {
#if defined(VERSION_G4SP01)
    return *(s32*)(this_ + 0x23c);
#else
    return *(s32*)(this_ + 0x238);
#endif
}

extern "C" void fn_8010DF58(u8* this_);
extern "C" void fn_801EF830(s32 a, u8* b, u8* c, s32 d, char* e, u8* f, s32 g);
extern "C" void fn_802F86CC(void* a, u8* b, void* c, s32 d, f32 e, f32 f, void* g);
extern "C" void fn_803075AC(void* a, s32 b, u8* c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern "C" char lbl_80464B84[];
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" f32 lbl_8053C7F8;
extern "C" void fn_8011C118(u8* this_) {
    u8 buf[0x3c];
    u8 i;

    fn_8010DF58(this_);
    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = -1;
    for (i = 0; i < 0x10; i += 8) {
        buf[(u8)(i + 0)] = (u8)(i + 0);
        buf[(u8)(i + 1)] = (u8)(i + 1);
        buf[(u8)(i + 2)] = (u8)(i + 2);
        buf[(u8)(i + 3)] = (u8)(i + 3);
        buf[(u8)(i + 4)] = (u8)(i + 4);
        buf[(u8)(i + 5)] = (u8)(i + 5);
        buf[(u8)(i + 6)] = (u8)(i + 6);
        buf[(u8)(i + 7)] = (u8)(i + 7);
    }
    buf[0x2e] = 0;
    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = 0;
    *(s32*)(buf + 0x18) = 0;
    buf[0x1c] = 0;
    buf[0x1d] = 0;
    buf[0x1e] = 0;
    buf[0x1f] = 1;
    buf[0x20] = 1;
    buf[0x21] = 0;
    buf[0x22] = 0;
    buf[0x23] = 0;
    buf[0x24] = 0;
    buf[0x25] = 0;
    buf[0x26] = 1;
    *(s32*)(buf + 0x28) = 3;
    buf[0x2c] = 1;
    buf[0x2d] = 0;
    *(s32*)(buf + 0x30) = -1;
    *(s32*)(buf + 0x34) = 0;
    *(s32*)(buf + 0x38) = 2;
    buf[0x2e] = 0x40;

    if (*(s32*)(this_ + 0x138) == 0) {
        fn_801EF830(*(s32*)(this_ + 4), this_ + 0xc, buf, 7, lbl_80464B84, *(u8**)(this_ + 0x280), 0);
    }
    if (*(s32*)(this_ + 4) < 8) {
        void* res = (*(DMLKResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_80464B84);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, *(s32*)(this_ + 0x280), lbl_8053C7F8, lbl_8053C7F8, 0);
    }
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x280), 0, 1, -1, 0, 0, 0);
}

extern "C" void fn_8010DF98(u8* this_);
extern "C" void fn_8011B878(u8* this_, s32 id);
extern "C" void fn_800FEB78(u8* this_, s32 flag);
extern "C" f32 lbl_8053C858;
extern "C" void fn_8011CB5C(u8* this_) {
    fn_8010DF98(this_);
    *(s32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xf;
    *(s32*)(this_ + 0x98) = (s8)((*(u32*)(this_ + 0x90) >> 4) & 3);
    switch (*(s32*)(this_ + 0x234)) {
    case 1:
        fn_8011B878(this_, 0xd);
        *(s32*)(this_ + 0x98) = 3;
        fn_800FEB78(this_ + 0x278, 0);
        break;
    case 2:
        fn_8011B878(this_, 0x16);
        *(s32*)(this_ + 0x98) = 3;
        fn_800FEB78(this_ + 0x278, 1);
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x10) + lbl_8053C858;
        break;
    default:
        fn_800FEB78(this_ + 0x278, 0);
        break;
    }
    *(u8*)(this_ + 0x284) = *(s32*)(this_ + 0x98);
}

extern "C" u8* fn_8011CC2C(u8* p) {
    f32 zero;

    fn_8010E074(p);
    *(void**)p = lbl_8049DB90;
    zero = lbl_8053C7D8;
    *(u8*)(p + 0x230) = 1;
    *(u8*)(p + 0x231) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(f32*)(p + 0x244) = zero;
    *(f32*)(p + 0x248) = zero;
    *(f32*)(p + 0x254) = zero;
    *(f32*)(p + 0x250) = zero;
    *(f32*)(p + 0x25c) = zero;
    *(f32*)(p + 0x258) = zero;
    return p;
}

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SP01)
extern "C" char lbl_8049DB90[];
extern "C" f32 lbl_8053C7D8;
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void fn_8010E074(u8*);
extern "C" void* fn_8011B390(u8* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_8049DB90;
        __dt__13Base_8010E074Fv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" s32 fn_8011BDAC(u8* self) {
    switch (*(s32*)(self + 0x23c)) {
    case 12:
    case 13:
    case 20:
    case 21:
    case 28:
    case 34:
        return 1;
    default:
        return 0;
    }
}
#endif
