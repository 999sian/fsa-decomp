#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80157210-0x801572a8 (1 functions). split_file divides it into the game's real files.

extern "C" u32 fn_80157100(u32 param_1);
extern "C" void fn_80155D54(void* param_1, u8 param_2, u8 param_3, s32 param_4);
extern "C" void fn_80157210(u8* param_1, void* param_2, s16 param_3) {
    s16 clamped;

    if (param_3 < 0) {
        clamped = 0;
    } else {
        clamped = param_3;
        if (clamped > 0x3fff) {
            clamped = 0x3fff;
        }
    }
    s32 type = (u8)fn_80157100((u32)param_2);
    if (type >= 0xa2 || type < 0xa0) {
        if (param_1[0x121] != 0xff) {
            fn_80155D54(param_2, param_1[0x121], param_1[0x122], clamped);
        }
    }
}
