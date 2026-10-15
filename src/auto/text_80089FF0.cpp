#include "JSystem/JKernel/JKRHeap.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern JKRHeap* sSystemHeap;

JKRHeap* fn_8008C484(JKRHeap* this_ptr)
{
    JKRHeap* old = sSystemHeap;
    sSystemHeap = this_ptr;
    return old;
}

extern "C" void __dt__9JKRThreadFv(void *, s32);
extern "C" void __dl__FPv(void *);
void fn_8008CA24(void *p1, void *p2, u16 p3, u32 p4, void *p5)
{
    *(void **)p1 = p2;
    *(void **)((u8 *)p1 + 4) = p5;
    *(u16 *)((u8 *)p1 + 12) = 1;
    *(u16 *)((u8 *)p1 + 14) = p3;
    *(u8 *)((u8 *)p1 + 16) = 0;
}

void fn_8008CA44(void *p1, s16 p2)
{
    if (p1 != nullptr) {
        *(void **)p1 = (void *)0x80499414;
        __dt__9JKRThreadFv(p1, p2);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
}

