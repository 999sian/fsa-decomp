#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80146ae8-0x80146bb8 (1 functions). split_file divides it into the game's real files.

extern "C" u8* lbl_802FF3E0;
extern "C" void fn_80158234(u8);
extern "C" void fn_8014F9D8(void);
extern "C" void fn_8014CE84(void);
extern "C" void fn_8014EA44(u8);
extern "C" int fn_8014F7F0(u8);
extern "C" int fn_80146AE8(int type, u32 id) {
    int ret = 0;
    switch (type) {
    case 0:
        if (lbl_802FF3E0[(u8)id * 0x404 + 0x11c] == 0) {
            fn_80158234((u8)id);
            fn_8014F9D8();
            if (id == *(u32*)(lbl_802FF3E0 + (u8)id * 0x404 + 0xf4)) {
                fn_8014CE84();
            }
        }
        break;
    case 1:
        fn_8014EA44((u8)id);
        break;
    case 2:
        ret = fn_8014F7F0((u8)id);
        break;
    case 3:
        fn_80158234((u8)id);
        fn_8014F9D8();
        break;
    }
    return ret;
}
