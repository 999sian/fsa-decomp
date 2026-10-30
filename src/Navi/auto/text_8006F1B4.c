#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8006f1b4-0x8006f204 (1 functions). split_file divides it into the game's real files.

extern char lbl_80280910[];
extern char lbl_802C2E38[];
extern char lbl_802C2E44[];
extern "C" void fn_8006F16C(void*);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_8006F1B4(void) {
    *(void**)lbl_802C2E44 = lbl_80280910;
    lbl_802C2E44[4] = -1;
    *(s32*)(lbl_802C2E44 + 8) = 0;
    __register_global_object(lbl_802C2E44, (void*)fn_8006F16C, lbl_802C2E38);
}
typedef void (*fn_ptr)(void);
const fn_ptr __ctors[] __attribute__((section(".ctors"))) = {
	(fn_ptr)fn_8006F1B4
};
