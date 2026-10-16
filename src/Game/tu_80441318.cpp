#include "Game/Actor.h"
#include "types.h"


extern "C" char lbl_804B19E0[];
extern "C" void fn_802D6A9C(void);
extern "C" u8 fn_802D39CC(void);
extern "C" int fn_80231A50(void);
extern "C" void fn_804413F0(u8* param_1) {
    u16 n = *(u16*)(param_1 + 0xc);
    if (n < 300) {
        *(u16*)(param_1 + 0xc) = n + 1;
    } else if (fn_80231A50() >= 0) {
        param_1[0xe] = 2;
    }
}

extern "C" void fn_80441444(u8* param_1) {
    fn_802D6A9C();
    if (fn_802D39CC() == 0) {
        param_1[0xe] = 1;
        *(u16*)(param_1 + 0xc) = 0;
    }
}

extern "C" void fn_8044148C(void) {
}

extern "C" void fn_8044172C(void) {
}

extern "C" void fn_80441778(void* p) {
    *(void**)p = lbl_804B19E0;
    *(s16*)((u8*)p + 0xc) = 0;
    *(u8*)((u8*)p + 0xe) = 0;
    *(u8*)((u8*)p + 0xf) = 0;
    *(s32*)((u8*)p + 0x4) = -1;
    *(s32*)((u8*)p + 0x8) = 0;
}
