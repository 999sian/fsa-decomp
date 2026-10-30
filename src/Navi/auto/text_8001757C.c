// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8001757c-0x800175b8 (1 functions). split_file divides it into the game's real files.
#include "types.h"

extern char lbl_802B488C[];
extern char lbl_802B4880[];
extern "C" void* fn_800172F0(void* p);
extern "C" void fn_80017534(void* p, s16 param_2);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);

extern "C" void fn_8001757C(void) {
    __register_global_object(fn_800172F0(lbl_802B488C), (void*)fn_80017534, lbl_802B4880);
}
