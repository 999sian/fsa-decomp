#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8006f204-0x80070d28 (26 functions). split_file divides it into the game's real files.

extern void* lbl_80280CEC[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80070464(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_800704C4(void);
extern "C" void fn_800704A4(void) {
    fn_800704C4();
}

extern "C" void fn_8004A380(void);
extern "C" void fn_8004A550(void);
extern "C" void fn_8003E6C4(f32);
extern "C" void fn_800704CC(void*);
extern u8 lbl_802C01B4[];
extern "C" s32 fn_80070C68(void* param_1) {
    fn_8004A380();
    fn_8004A550();
    fn_8003E6C4(*(f32*)(lbl_802C01B4 + 0xA0));
    fn_800704CC(param_1);
    return 1;
}

extern "C" void fn_8004ACA4(void*, void*);
extern "C" s32 fn_80070CB4(void* tag, void* data) {
    fn_8004ACA4(tag, data);
    return 1;
}

extern "C" void* fn_80070CE0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80280CEC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
