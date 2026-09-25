// RAIL_800FD438: .text 0x800FD438-0x800FE8C0 (actor RAIL)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_800FD438_dtor.cpp

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_8049C770[];

extern "C" void* fn_800FD438(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C770;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/oscluster_800fde38.cpp

extern "C" {

/* fn_800FDE38(ringArray): a "ping-pong" direction stepper for the same
 * ring struct documented in oscluster_800fd498.c/fn_800FD894/fn_800FD998
 * (`+0x1`=direction mode, `+0x2`=ring size, `+0x3`=accumulator index).
 * Toggles the direction mode, then increments or decrements the
 * accumulator index accordingly, and reverses direction automatically
 * when the accumulator underflows (`0xFF`) or reaches the ring size -
 * i.e. this steps the accumulator back and forth between `0` and
 * `size-1` rather than wrapping around like `fn_800FD818`'s plain
 * stepper. A natural fit for animating a wave/oscillation traveling
 * back and forth along a chain of ring segments. No extab content of
 * its own, landed via the ordinary ASM/nofralloc convention. Caller
 * not traced.
 */

void fn_800FDE38(void* ringArray)
{
    char* r = (char*)ringArray;
    u8 dir;

    dir = *(u8*)(r + 0x1) ^ 1;
    *(u8*)(r + 0x1) = dir;

    if (*(u8*)(r + 0x1) == 0) {
        u8 idx = *(u8*)(r + 0x3);
        *(u8*)(r + 0x3) = idx + 1;
    } else {
        u8 idx = *(u8*)(r + 0x3);
        *(u8*)(r + 0x3) = idx - 1;
    }

    {
        u8 idx = *(u8*)(r + 0x3);
        if (idx == 0xff) {
            u8 size = *(u8*)(r + 0x2);
            *(u8*)(r + 0x3) = size - 1;
            return;
        }
        if (idx != *(u8*)(r + 0x2)) {
            return;
        }
        *(u8*)(r + 0x3) = 0;
    }
}

} // extern "C"

#include "JSystem/JAudio/JASFakeMatchFSA.h"
