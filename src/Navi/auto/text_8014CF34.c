// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014cf34-0x8014d028 (1 functions). split_file divides it into the game's real files.
#include <types.h>
extern "C" void fn_8014D2B4(void* self);

extern "C" void fn_8014CF34(u8* self)
{
    u32 done;
    *(u64*)(self + 0x114) |= 8;
    if (*(s32*)(self + 0x34) != 0) {
        if ((*(u64*)(self + 0x114) & 0x10000000000ULL) == 0) {
            if (self[0x68] != 0 && *(u32*)(self + 0x50) != 0) {
                *(u32*)(self + 0x38) = *(u32*)(self + 0x5c);
                *(u32*)(self + 0x34) = *(u32*)(self + 0x50);
                *(u32*)(self + 0x50) = 0;
                fn_8014D2B4(self);
                done = 1;
            } else {
                done = 0;
            }
            if (!done) {
                if ((*(u64*)(self + 0x114) & 4ULL) != 0) {
                    fn_8014D2B4(self);
                }
            }
        } else {
            *(u64*)(self + 0x114) |= 0x40000000000ULL;
        }
    }
}
