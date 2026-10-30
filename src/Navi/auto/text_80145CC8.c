#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80145cc8-0x80145d0c (1 functions). split_file divides it into the game's real files.

extern "C" void fn_80145B14(void *param_1, s32 param_2, s32 param_3);
extern "C" void fn_80145CC8(void *param_1)
{
    void *p = param_1;
    fn_80145B14(p, 0, 0);
    fn_80145B14(p, 1, 0);
}
