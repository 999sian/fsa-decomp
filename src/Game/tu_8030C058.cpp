#include "types.h"
#include "dolphin/gx.h"
#include "dolphin/mtx.h"
#include "JSystem/JUtility/JUTVideo.h"

extern u8* lbl_8053AB10;

struct Vec3f { f32 x, y, z; };

static inline bool fn_8030C210_contains(u8* p, f32 x, f32 y) {
    bool in = false;
    if (x >= *(f32*)(p + 0x154) && y >= *(f32*)(p + 0x158) && x < *(f32*)(p + 0x15c) && y < *(f32*)(p + 0x160)) {
        in = true;
    }
    return in;
}

extern "C" bool fn_8030C210(u8* p, f32* v) {
    bool ret = false;
    s32 n = *(s32*)(p + 0x7f0);
    if (n < 0x80) {
        f32 x = v[0];
        if (fn_8030C210_contains(p, x, v[1])) {
            f32 y = v[1];
            f32 z = v[2];
            ret = true;
            f32* d = (f32*)(p + n * 0xc + 0x1f0);
            d[0] = x;
            d[1] = y;
            d[2] = z;
            (*(s32*)(p + 0x7f0))++;
        }
    }
    return ret;
}

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
void operator delete(void* p);
extern "C" u32* fn_8030E6D0(u32* param_1, s16 param_2) {
    if (param_1 != NULL) {
        *param_1 = (u32)lbl_804AA9E4;
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

