#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014717c-0x801471d4 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_80158D4C(void);
extern "C" void fn_8014208C(u32, u32, u32);
extern "C" void fn_80158D14(void);
extern "C" void fn_8014717C(u32 a, u32 b, u32 c) {
    fn_80158D4C();
    fn_8014208C(a, b, c);
    fn_80158D14();
}
