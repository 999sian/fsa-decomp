#include "types.h"

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
