#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80077da0-0x8007bc94 (37 functions). split_file divides it into the game's real files.

extern void* lbl_80282198[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80077F44(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80282198;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80078414(void);
extern "C" void fn_80078364(void) {
    fn_80078414();
}

extern "C" void fn_80078384(void);
extern "C" void fn_8007BB2C(void) {
    fn_80078384();
}

extern "C" void fn_8007B638(void);
extern "C" void fn_8007BBD8(void) {
    fn_8007B638();
}

extern "C" void fn_80078F94(void);
extern "C" void fn_8007BBF8(void) {
    fn_80078F94();
}

