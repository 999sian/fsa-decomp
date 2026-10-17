#include "types.h"

struct NaviPair {
    u32 a;
    u32 b;
};
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80145c64-0x80145cc8 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_80145B14(void *param_1, s32 param_2, s32 param_3);
extern u32 lbl_802FF3F0;
extern u32 lbl_802FF3F4;
extern "C" void fn_80145C64(void *param_1)
{
    u32 tmp[2];
    u8 *p = (u8 *)param_1;
    tmp[0] = lbl_802FF3F0;
    tmp[1] = lbl_802FF3F4;
    *(u32 *)(p + 0x24) = tmp[0];
    *(u32 *)(p + 0x28) = tmp[1];
    *(u32 *)(p + 0x2c) = tmp[0];
    *(u32 *)(p + 0x30) = tmp[1];
    fn_80145B14(p, 0, 0);
    fn_80145B14(p, 1, 0);
}
