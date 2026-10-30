// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014d028-0x8014d134 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_8014D2B4(void* self);
extern "C" void fn_8014D028(u8* self, u32 arg1)
{
    u32 done;
    u64 flags;
    if (arg1 != 0) {
        *(u32*)(self + 0x114) |= 0x100;
        return;
    }
    if (*(u32*)(self + 0x34) != 0) {
        flags = *(u64*)(self + 0x114);
        if ((flags & 0x40000000000ULL) != 0) {
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
                flags = *(u64*)(self + 0x114);
                if ((flags & 0x4ULL) != 0) {
                    fn_8014D2B4(self);
                }
            }
        }
    }
    *(u64*)(self + 0x114) &= ~0x50000000000ULL;
}
