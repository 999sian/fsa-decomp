#include "types.h"

extern "C" void fn_8010DF58(void* this_);
extern "C" void fn_8010DF78(void* this_);
extern "C" void fn_8010F7EC(void*, s32);
extern "C" void fn_80110E9C(void*);
extern "C" void fn_8011093C(void*);
extern "C" void fn_801D1C18(void*);
extern "C" void fn_8010F4DC(void*);
extern "C" void fn_8010E7E8(void*, s32);
extern "C" void fn_8010E2D4(void*, s32);
extern "C" void* fn_8010FA84(u8* this_) {
#if defined(VERSION_G4SP01)
    return *(void**)(this_ + 0x23c);
#else
    return *(void**)(this_ + 0x238);
#endif
}

extern "C" void fn_80110198(u8* this_) {
    fn_8010DF58(this_);
    if (this_[0x230] == 0) {
        if (*(s32*)(this_ + 0x2fc) >= 0x13) {
            fn_8010F7EC(this_, 0x21b);
        } else if (*(s32*)(this_ + 0x2fc) >= 0xf) {
            fn_8010F7EC(this_, 0x274);
        } else {
            fn_8010F7EC(this_, 0x9b);
        }
    }
}

extern "C" void fn_80111CC0(u8* this_) {
    fn_8010DF78(this_);
    switch (*(s32*)(this_ + 0x234)) {
    case 0:
    case 1:
        fn_80110E9C(this_);
        break;
    case 2:
        fn_8011093C(this_);
        break;
    }
    fn_801D1C18(this_ + 0x2f4);
    fn_801D1C18(this_ + 0x32c);
    if (this_[0x230] != 0) {
        fn_8010F4DC(this_);
    }
}

extern "C" void fn_8010F478(u8* this_, s32 param_2) {
    switch (*(s32*)(this_ + 0x234)) {
    case 0:
    case 1:
        fn_8010E7E8(this_, param_2);
        break;
    case 2:
        fn_8010E2D4(this_, param_2);
        break;
    }
    *(s32*)(this_ + 0x238) = param_2;
}

extern "C" void fn_8010F9F0(u8* p) {
    switch (*(s32*)(p + 0x234)) {
    case 0:
    case 1:
        fn_8010E7E8(p, 0x31);
        break;
    case 2:
        fn_8010E2D4(p, 0x31);
        break;
    case 3:
        break;
    }
    *(s32*)(p + 0x238) = 0x31;
}

extern "C" s32 fn_8010FA54(u8* this_) {
#if defined(VERSION_G4SP01)
    switch (*(s32*)(this_ + 0x23c)) {
#else
    switch (*(s32*)(this_ + 0x238)) {
#endif
    case 47:
    case 61:
    case 62:
        return 1;
    }
    return 0;
}
