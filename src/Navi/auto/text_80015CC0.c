#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80015cc0-0x80015d50 (1 functions). split_file divides it into the game's real files.

extern u8 lbl_802A3488[];
extern void* lbl_80204F9C[];
extern "C" void fn_80015D50(void* p, s16 param_2);
extern "C" void fn_80015C5C(void* p, s16 param_2);
extern "C" void __register_global_object(void* obj, void* dtor, void* reg);
extern "C" void fn_80015CC0(void) {
    u8* p;
    __register_global_object(lbl_802A3488 + 0xc, (void*)fn_80015D50, lbl_802A3488);
    p = lbl_802A3488 + 0xc4;
    *(void**)p = lbl_80204F9C;
    p[5] = 0;
    p[6] = 1;
    p[7] = 0;
    p[8] = 1;
    p[9] = 0;
    p[0xa] = 1;
    p[0xb] = 0;
    p[0xc] = 1;
    p[0xd] = 0;
    p[0xe] = 0;
    __register_global_object(p, (void*)fn_80015C5C, lbl_802A3488 + 0xb8);
}
