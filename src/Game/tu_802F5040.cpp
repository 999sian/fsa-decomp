#include "types.h"

extern "C" f32 lbl_80541500;
extern "C" f32 lbl_805414FC;

struct Tu802F5040Tbl {
    u8 pad0[0x28];
    u8* m_tbl[8];
};

extern "C" void fn_802FA3FC(void* mgr);
extern "C" void fn_802FF798(void* mgr);
extern void* lbl_8053AAF8;
extern "C" f32 fn_802F5FF4(f32 x) {
    f32 a = lbl_805414FC;
    f32 v = lbl_80541500;
    if (x >= lbl_80541500) {
        v = x;
    }
    return a / (a - v);
}

extern "C" u16 fn_802F9908(Tu802F5040Tbl* base, s32 idx, s32 off) {
    s32 v;
    if (idx >= 0 && idx < 4) {
        v = *(u16*)(base->m_tbl[idx] + off * 2);
    } else if (idx >= 4 && idx < 8) {
        v = *(u16*)(base->m_tbl[idx] + off * 2);
    } else {
        v = *(u16*)(base->m_tbl[idx] + off * 2);
    }
    return (u16)v;
}

extern "C" void fn_802F9974(Tu802F5040Tbl* base, s32 idx, s32 off, u16 val) {
    if (idx >= 0 && idx < 4) {
        *(u16*)(base->m_tbl[idx] + off * 2) = val;
    } else if (idx >= 4 && idx < 8) {
        *(u16*)(base->m_tbl[idx] + off * 2) = val;
    } else {
        *(u16*)(base->m_tbl[idx] + off * 2) = val;
    }
}

extern "C" void fn_802FA3FC(void* mgr);
extern void* lbl_8053AAF8;
extern "C" void fn_802FA3FC(void* mgr);
extern "C" void fn_802FF548(void* mgr) {
    fn_802FF798(mgr);
}

extern "C" void fn_803003A8(void) {}

extern "C" void fn_803004C0(void) {}

