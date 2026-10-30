// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
#include <types.h>
extern "C" void fn_8014D2B4(void* self);
// .text 0x8014ce84-0x8014cf34 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_8014CE84(u8* self)
{
    u32 done;
    u64 flags;
    if (*(s32*)(self + 0x4c) == 1) {
        if (self[0x68] != 0 && *(u32*)(self + 0x54) != 0) {
            *(u32*)(self + 0x38) = *(u32*)(self + 0x60);
            *(u32*)(self + 0x34) = *(u32*)(self + 0x54);
            *(u32*)(self + 0x54) = 0;
            fn_8014D2B4(self);
            done = 1;
        } else {
            done = 0;
        }
        if (!done) {
            flags = *(u64*)(self + 0x114);
            if ((flags & 0x40000ULL) != 0) {
                fn_8014D2B4(self);
            }
        }
    }
}
