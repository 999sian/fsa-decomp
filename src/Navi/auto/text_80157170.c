#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80157170-0x80157210 (1 functions). split_file divides it into the game's real files.

extern "C" u32 fn_80157100(u32 param_1);
extern "C" u32 fn_80155F70(u32 param_1, u8 param_2, u8 param_3);
extern "C" u32 fn_80157170(u8* param_1, u32 param_2) {
    u16 v;
    u8 type = fn_80157100(param_2);

    switch (type) {
    case 0xa0:
        return *(s16*)(param_1 + 0x1c4) * 2 + 0x2000;
    case 0xa1:
        return *(s16*)(param_1 + 0x1d0) * 2 + 0x2000;
    default:
        if (param_1[0x121] == 0xff) {
            v = 0;
        } else {
            v = fn_80155F70(param_2, param_1[0x121], param_1[0x122]);
        }
        return v;
    }
}
