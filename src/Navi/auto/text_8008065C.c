#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8008065c-0x800868f4 (51 functions). split_file divides it into the game's real files.

extern void* lbl_80283B18[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_800808C4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283B18;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800813BC(void);
extern "C" void fn_80081308(void) {
    fn_800813BC();
}

extern "C" void fn_80081328(void);
extern "C" void fn_80086710(void) {
    fn_80081328();
}

extern "C" void fn_80085F24(void);
extern "C" void fn_80086838(void) {
    fn_80085F24();
}

