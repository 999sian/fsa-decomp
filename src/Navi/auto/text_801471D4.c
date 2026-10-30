#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801471d4-0x8014723c (1 functions). split_file divides it into the game's real files.

extern "C" void fn_80158D4C(void);
extern "C" void fn_80142140(u32, u32, u32, u32);
extern "C" void fn_80158D14(void);
extern "C" void fn_801471D4(u32 a, u32 b, u32 c, u32 d) {
    u32 buf[2];
    fn_80158D4C();
    fn_80142140(a, b, c, d);
    fn_80158D14();
}
