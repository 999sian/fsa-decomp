#include "types.h"

extern "C" f32 lbl_80541500;
extern "C" f32 lbl_805414FC;

extern "C" void fn_802FF798(void* mgr);
extern "C" f32 fn_802F5FF4(f32 x) {
    f32 v;
    if (x >= lbl_80541500) {
        v = x;
    } else {
        v = lbl_80541500;
    }
    return lbl_805414FC / (lbl_805414FC - v);
}

extern "C" u16 fn_802F9908(u8* base, s32 idx, s32 off) {
    if (idx >= 0 && idx < 4) {
        return *(u16*)(*(u8**)(base + idx * 4 + 0x28) + off * 2);
    }
    if (idx >= 4 && idx < 8) {
        return *(u16*)(*(u8**)(base + idx * 4 + 0x28) + off * 2);
    }
    return *(u16*)(*(u8**)(base + idx * 4 + 0x28) + off * 2);
}

extern "C" void fn_802F9974(u8* base, s32 idx, s32 off, u16 val) {
    if (idx >= 0 && idx < 4) {
        *(u16*)(*(u8**)(base + idx * 4 + 0x28) + off * 2) = val;
        return;
    }
    if (idx >= 4 && idx < 8) {
        *(u16*)(*(u8**)(base + idx * 4 + 0x28) + off * 2) = val;
        return;
    }
    *(u16*)(*(u8**)(base + idx * 4 + 0x28) + off * 2) = val;
}

extern "C" void fn_802FF548(void* mgr) {
    fn_802FF798(mgr);
}
