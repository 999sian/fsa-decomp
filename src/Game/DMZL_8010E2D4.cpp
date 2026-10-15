#include "types.h"

extern "C" void fn_8010DF58(void* this_);
extern "C" void fn_8010DF78(void* this_);
extern "C" void fn_8010F7EC(void*, s32);
extern "C" void fn_80110E9C(void*);
extern "C" void fn_8011093C(void*);
extern "C" void fn_801D1C18(void*);
extern "C" void fn_8010F4DC(void*);
extern "C" void* fn_8010FA84(u8* this_) { return *(void**)(this_ + 0x238); }

extern "C" s32 fn_8010FA54(u8* this_) {
    switch (*(s32*)(this_ + 0x238)) {
    case 47:
    case 61:
    case 62:
        return 1;
    }
    return 0;
}
