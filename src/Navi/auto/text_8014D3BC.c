// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014d3bc-0x8014d4b8 (1 functions). split_file divides it into the game's real files.
#include "types.h"

extern void* lbl_802FF44C;
extern void* lbl_802FF450;
extern u32 lbl_802FF458;
extern u32 lbl_802FF45C;

extern "C" void fn_8014D3BC(u8* p, s32 param_2)
{
    if (*(s32*)(p + 0x4c) == param_2) {
        return;
    }
    if (*(s32*)(p + 0x4c) == 0) {
        if (*(void**)(p + 0x40) == NULL) {
            lbl_802FF44C = *(void**)(p + 0x3c);
        } else {
            *(void**)(*(u8**)(p + 0x40) + 0x3c) = *(void**)(p + 0x3c);
        }
        if (*(void**)(p + 0x3c) != NULL) {
            *(void**)(*(u8**)(p + 0x3c) + 0x40) = *(void**)(p + 0x40);
        }
    }
    if (param_2 == 2) {
        if (*(u64*)(p + 0x98) != 0) {
            if (*(u64*)(p + 0x98) != 0xFFFFFFFFFFFFFFFFULL) {
                if (*(void**)(p + 0x48) == NULL) {
                    lbl_802FF450 = *(void**)(p + 0x44);
                } else {
                    *(void**)(*(u8**)(p + 0x48) + 0x44) = *(void**)(p + 0x44);
                }
                if (*(void**)(p + 0x44) != NULL) {
                    *(void**)(*(u8**)(p + 0x44) + 0x48) = *(void**)(p + 0x48);
                }
            }
            *(u64*)(p + 0x98) = 0;
            *(u64*)(p + 0xa0) = *(u64*)&lbl_802FF458;
            *(u64*)(p + 0x114) &= 0xFFFFFFFFFFFBFFFBULL;
        }
    }
    *(s32*)(p + 0x4c) = param_2;
}
