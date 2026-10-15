#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80025170-0x800275d8 (75 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_800254CC(void);
extern "C" void fn_8002544C(void) {
    fn_800254CC();
}

extern "C" void fn_80025570(void);
extern "C" void fn_8002546C(void) {
    fn_80025570();
}

extern "C" void fn_8002566C(void);
extern "C" void fn_8002548C(void) {
    fn_8002566C();
}

extern "C" void fn_80025710(void);
extern "C" void fn_800254AC(void) {
    fn_80025710();
}

extern u8 lbl_802FED9C;
extern "C" void fn_80026520(void) {
    lbl_802FED9C = 0;
}

extern u8 lbl_802FED9E;
extern "C" void fn_80026630(void) {
    lbl_802FED9E = 0;
}

extern "C" void* fn_80026E54(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}
