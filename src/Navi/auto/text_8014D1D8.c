// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
#include "types.h"

// .text 0x8014d1d8-0x8014d2b4 (1 functions). split_file divides it into the game's real files.

extern void* lbl_802FF450;
extern u32 lbl_802FF458;
extern u32 lbl_802FF45C;
void fn_80145CC8(void* p);

void fn_8014D1D8(u8* p, s32 param_2)
{
    if (*(u32*)(p + 0x98) != 0 || *(u32*)(p + 0x9c) != 0) {
        if (*(u32*)(p + 0x98) != 0xffffffff || *(u32*)(p + 0x9c) != 0xffffffff) {
            if (*(void**)(p + 0x48) == NULL) {
                lbl_802FF450 = *(void**)(p + 0x44);
            } else {
                *(void**)(*(u8**)(p + 0x48) + 0x44) = *(void**)(p + 0x44);
            }
            if (*(void**)(p + 0x44) != NULL) {
                *(void**)(*(u8**)(p + 0x44) + 0x48) = *(void**)(p + 0x48);
            }
        }
        if (param_2 == 0) {
            fn_80145CC8(p);
        }
        *(u32*)(p + 0x9c) = 0;
        *(u32*)(p + 0x98) = 0;
        *(u32*)(p + 0xa4) = lbl_802FF45C;
        *(u32*)(p + 0xa0) = lbl_802FF458;
        *(u64*)(p + 0x114) &= 0xFFFFFFFFFFFBFFFBULL;
    }
}
