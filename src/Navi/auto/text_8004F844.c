#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004f844-0x800575d8 (67 functions). split_file divides it into the game's real files.

extern void* lbl_80222428[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_80249D24[];
extern "C" void fn_80021DDC(void* p);
extern "C" void fn_8005556C(void* self, void* p) {
    fn_80021DDC(p);
}

extern "C" void* fn_8005757C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80249D24;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80222428;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
