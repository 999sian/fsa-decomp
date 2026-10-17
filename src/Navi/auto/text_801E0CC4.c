#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801e0cc4-0x801e0d40 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB40(void* p);
extern "C" void fn_801E0CC4(u8* p, void (*fn)(u8*, s32)) {
    if (p != NULL) {
        if (fn != NULL) {
            u32 i;
            u32 count;
            s32 size;
            size = *(s32*)(p - 0x10);
            count = *(u32*)(p - 0xc);
            u8* q = p + size * count;
            for (i = 0; i < count; i++) {
                q -= size;
                fn(q, -1);
            }
        }
        fn_8015AB40(p - 0x10);
    }
}
