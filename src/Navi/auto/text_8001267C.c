#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8001267c-0x80012804 (4 functions). split_file divides it into the game's real files.

extern void* lbl_802049BC[];

struct Entry_800126C8 {
    u8 data[0x18];
    u32 pad;
    u32 key;
};
struct Table_800126C8 {
    u32 unk0;
    Entry_800126C8 entries[0x40];
};
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8001267C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802049BC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800126C4(void) {}

