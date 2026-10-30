// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015827c-0x80158314 (1 functions). split_file divides it into the game's real files.
#include "types.h"

extern "C" u8 lbl_802EBB14[];
extern "C" u8 lbl_802EB890[];

extern "C" void fn_8015827C(u8* param_1)
{
    u8* base;
    u8* p;
    u8* q;
    u32 i;
    u8 tmp[8];

    if (*(u32*)(param_1 + 0xc) == 1) {
        base = lbl_802EBB14;
    } else {
        base = lbl_802EB890;
    }
    p = base;
    q = base;
    for (i = 0; i < 0x10; i++) {
        if (param_1 == p && *(void**)(p + 0x20) != NULL) {
            (*(void (**)(void*))(p + 0x20))(*(void**)(q + 0x24));
        }
        p += 0x28;
        q += 0x28;
    }
    base[0x281]--;
}
