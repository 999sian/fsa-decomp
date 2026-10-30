#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801580c4-0x8015814c (1 functions). split_file divides it into the game's real files.

extern "C" void* fn_801588FC(void* p, void* buf);
extern "C" void fn_801BC250(void* p, u32 size);
extern "C" void fn_80158314(void* p, u32 a, u32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801580C4(u8* param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6)
{
    u8 buf[32];
    u32 base = (u32)fn_801588FC((void*)param_4, buf + 0x18);
    param_3 += param_2 & 0x1f;
    param_3 = (param_3 + 0x1f) & ~0x1f;
    param_2 &= ~0x1f;
    param_1 += param_2;
    fn_801BC250(param_1, param_3);
    fn_80158314(param_1, base + param_2, param_3, 1, param_5, param_6);
}
