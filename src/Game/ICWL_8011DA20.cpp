#include "types.h"

extern "C" void __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void* anim);
extern void* lbl_8049DE18[];
extern const f32 lbl_8053C8BC;
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_8049CC34[];
extern "C" void* fn_8011E650(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049DE18;
        fn_801EE434(*(void**)(p + 0x27c));
        *(s32*)(p + 0x27c) = 0;
        if (p + 0x244 != 0) {
            if (p + 0x268 != 0) {
                *(void**)(p + 0x268) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_8011E6E0(char* p) {
    __ct__5ActorFv(p);
    *(void**)p = lbl_8049DE18;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(f32*)(p + 0x240) = lbl_8053C8BC;
    fn_801D267C(p + 0x244);
    *(s32*)(p + 0x27c) = 0;
    return p;
}
