#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801470fc-0x80147144 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_80158D4C(void);
extern "C" void fn_80141EA4(u32 param_1, u16 param_2);
extern "C" void fn_80158D14(void);
extern "C" void fn_801470FC(void *param_1, u32 param_2)
{
    fn_80158D4C();
    fn_80141EA4((u32)param_1, (u16)param_2);
    fn_80158D14();
}
