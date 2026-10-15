#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015ea78-0x8015eabc (1 functions). split_file divides it into the game's real files.

extern char lbl_802EE25C[];
extern char lbl_802EE250[];
extern "C" void fn_80166C70(void*);
extern "C" void fn_8015EABC(void*);
extern "C" void __register_global_object(void* object, void* destructor, void* regmem);
extern "C" void fn_8015EA78(void) {
    fn_80166C70(&lbl_802EE25C);
    __register_global_object(&lbl_802EE25C, (void*)fn_8015EABC, &lbl_802EE250);
}

extern "C" {
    typedef void (*CtorFunc)(void);
    const CtorFunc __ctors[] __attribute__((section(".ctors"))) = {
        fn_8015EA78
    };
}
