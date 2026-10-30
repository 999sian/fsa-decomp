#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80145dc8-0x80145e34 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_80141CD4(u32);
extern "C" void fn_80141B20(u32);
extern "C" void fn_8014208C(u32, u32, u32);
extern "C" void fn_80145DC8(u8* p) {
    switch (p[0x2c]) {
    case 1:
        fn_80141CD4(*(u32*)(p + 0x28));
        break;
    case 2:
        fn_80141B20(*(u32*)(p + 0x28));
        break;
    case 3:
        fn_8014208C(*(u32*)(p + 0x28), 0, 0);
        break;
    }
}
