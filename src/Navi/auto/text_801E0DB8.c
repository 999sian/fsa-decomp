// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801e0db8-0x801e0eb4 (1 functions). split_file divides it into the game's real files.
#include <types.h>

extern "C" void fn_801E0DB8(u8* self, void (*f1)(u8*, s32), void (*f2)(u8*, s32), u32 stride, u32 count)
{
    volatile struct {
        u8* base;
        u32 stride;
        u32 count;
        void (*f2)(u8*, s32);
        u32 i;
    } it;
    u8* p;

    it.base = self;
    it.stride = stride;
    it.count = count;
    it.f2 = f2;
    it.i = 0;
    p = self;
    while (it.i < count) {
        f1(p, 1);
        p += stride;
        it.i++;
    }
    if (it.i < it.count && it.f2 != 0) {
        p = it.base + it.stride * it.i;
        while (it.i != 0) {
            p -= it.stride;
            it.f2(p, -1);
            it.i--;
        }
    }
}
