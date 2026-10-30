// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014ea44-0x8014eae4 (1 functions). split_file divides it into the game's real files.

#include <types.h>
extern "C" void fn_8014D95C(void* self);
extern "C" void fn_8014E4C8(void* self);
extern "C" void fn_80148088(s32 idx);
extern "C" void fn_80157854(s32 idx);
extern void* lbl_802FF3E0;

extern "C" void fn_8014EA44(s32 idx)
{
    u8* e;
    u64 v;
    e = (u8*)lbl_802FF3E0 + idx * 0x404;
    if (*(u32*)(e + 0x34) != 0) {
        fn_8014D95C(e);
        v = *(u64*)(e + 0x114);
        v &= 0xFFFFFFFFFFFFFFFCULL;
        *(u64*)(e + 0x114) = v;
        *(u32*)(e + 0x110) = 0;
        fn_8014E4C8(e);
    }
    if (e[0x11c] != 0) {
        fn_80148088(idx);
    }
    fn_80157854(idx);
}
