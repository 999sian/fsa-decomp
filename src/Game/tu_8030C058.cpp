#include "types.h"
#include "dolphin/gx.h"
#include "dolphin/mtx.h"


extern "C" void fn_8030DD20(u8* param_1, Mtx param_2) {
    Mtx sp8;
    PSMTXConcat((MtxPtr)(param_1 + 0x74), param_2, sp8);
    GXSetCurrentMtx(0x1b);
    GXLoadPosMtxImm(sp8, 0x1b);
    GXLoadNrmMtxImm(sp8, 0x1b);
}

extern "C" void fn_8030DD68(void) {
    GXSetCurrentMtx(0x18);
}

extern "C" void fn_8030E150(void) {
}

extern u8 lbl_804AA9E4[];
void __dl__FPv(void* p);
extern "C" void __dl__FPv(void* p);
extern "C" u32* fn_8030E6D0(u32* param_1, s16 param_2) {
    if (param_1 != NULL) {
        *param_1 = (u32)lbl_804AA9E4;
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

