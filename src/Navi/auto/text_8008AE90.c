#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8008ae90-0x8008bd90 (14 functions). split_file divides it into the game's real files.

extern void* lbl_80284A14[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_8008AF98(void);
extern "C" void fn_8008AE90(void) {
    fn_8008AF98();
}

extern "C" void fn_8008AEB0(void);
extern "C" void fn_8008BC64(void) {
    fn_8008AEB0();
}

extern "C" void fn_8008B95C(void);
extern "C" void fn_8008BD00(void) {
    fn_8008B95C();
}

extern "C" void fn_8008B580(void);
extern "C" void fn_8008BD20(void) {
    fn_8008B580();
}

extern "C" void* fn_8008BD48(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80284A14;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
