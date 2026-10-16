#include "types.h"

extern "C" char lbl_8049DB90[];
extern "C" f32 lbl_8053C7D8;
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void fn_8010E074(u8*);

extern "C" s32 fn_8011BDE4(u8* this_) {
#if defined(VERSION_G4SP01)
    return *(s32*)(this_ + 0x23c);
#else
    return *(s32*)(this_ + 0x238);
#endif
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
extern "C" void* fn_8011B390(void* p, s16 n) {
    if (p) {
        *(void**)p = lbl_8049DB90;
        __dt__13Base_8010E074Fv(p, 0);
        if (n > 0) operator delete(p);
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
