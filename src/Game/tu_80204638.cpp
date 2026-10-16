#include "Game/esd/types.h"


extern "C" u8 fn_80204D44(u8* param_1);
void fn_80204834(u8* param_1) {
    for (int i = 0; i < 2; i++) {
        for (int j = 4; j <= 0x28; j += 4) {
            u8* p = *(u8**)(param_1 + j);
            if (p) {
                p[0x11c] = 0;
            }
        }
        param_1 += 0x28;
    }
}

extern "C" void fn_802049E0(u8* param_1, u8* param_2) {
    u8** slot = (u8**)(param_1 + param_2[0x34a] * 8 + 4);
    if (slot[0] == param_2) {
        slot[0] = 0;
        return;
    }
    if (slot[1] == param_2) {
        slot[1] = 0;
    }
}

extern "C" void fn_80204A20(u8* param_1, u8* param_2) {
    u8** slot = (u8**)(param_1 + param_2[0x34a] * 8 + 4);
    if (slot[0] == 0) {
        slot[0] = param_2;
        if (slot[1] != 0 && fn_80204D44(slot[1])) {
            param_2[0x11c] = 0;
        }
    } else if (slot[1] == 0) {
        slot[1] = param_2;
        if (slot[0] != 0 && fn_80204D44(slot[0])) {
            param_2[0x11c] = 0;
        }
    }
}

extern "C" void fn_80204ABC(u8* param_1, u8 param_2) {
    if (param_2 == 0) {
        return;
    }
    *param_1 = 0;
    for (int i = 1; i <= 20; i++) {
        ((u32*)param_1)[i] = 0;
    }
}

