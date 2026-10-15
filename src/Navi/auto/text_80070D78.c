#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80070d78-0x80077d64 (99 functions). split_file divides it into the game's real files.

extern void* lbl_80281904[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80070D98(void);
extern "C" void fn_80070D78(void) {
    fn_80070D98();
}

extern "C" void fn_80070E64(void);
extern "C" void fn_800710A4(void) {
    fn_80070E64();
}

extern "C" void fn_800711CC(void);
extern "C" void fn_800711AC(void) {
    fn_800711CC();
}

extern "C" void fn_80071D8C(void);
extern "C" void fn_80071CD0(void) {
    fn_80071D8C();
}

extern "C" void fn_80071CF0(void);
extern "C" void fn_80072240(void) {
    fn_80071CF0();
}

extern "C" void fn_80072570(void);
extern "C" void fn_800724B4(void) {
    fn_80072570();
}

extern "C" void fn_800724D4(void);
extern "C" void fn_80072A5C(void) {
    fn_800724D4();
}

extern "C" void fn_80072E68(void);
extern "C" void fn_80072D6C(void) {
    fn_80072E68();
}

extern "C" void fn_80072D8C(void);
extern "C" void fn_80075550(void) {
    fn_80072D8C();
}

extern "C" void fn_80073720(void);
extern "C" void fn_800755D0(void) {
    fn_80073720();
}

extern "C" void fn_8007356C(void);
extern "C" void fn_800755F0(void) {
    fn_8007356C();
}

extern "C" void* fn_80075890(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80281904;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80075CB8(void);
extern "C" void fn_80075B40(void) {
    fn_80075CB8();
}

extern "C" void fn_80075B60(void);
extern "C" void fn_80077B10(void) {
    fn_80075B60();
}

extern "C" void fn_80077314(void);
extern "C" void fn_80077CBC(void) {
    fn_80077314();
}

extern "C" void fn_8007634C(void);
extern "C" void fn_80077CDC(void) {
    fn_8007634C();
}

