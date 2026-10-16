#include "types.h"


extern "C" char lbl_804A8578[];
extern "C" void* lbl_8053ACA8;
extern "C" u8 lbl_80529DEC[];
extern "C" void __dl__FPv(void*);
extern "C" u32 fn_802B1D60(void) {
    u8 v = lbl_80529DEC[0x222];
    if (v <= 3) {
        return v;
    }
    return -1;
}

extern "C" u32 fn_802B1D7C(void) {
    return lbl_80529DEC[0x221] != 0;
}

extern "C" void fn_802B1D98(u8* p) {
    lbl_80529DEC[0x221] = 0;
    p[6] = 0;
}

extern "C" u32 fn_802B1DB0(void) {
    return lbl_80529DEC[0x220] != 0;
}

extern "C" u32 fn_802B1DCC(void) {
    return lbl_80529DEC[0x21f] != 0;
}

extern "C" void fn_802B1EB0(void) {
}

extern "C" void* fn_802B1EB4(void* p, s16 n) {
    if (p != 0) {
        *(char**)p = lbl_804A8578;
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_802B1EFC(u8* p) {
    *(char**)p = lbl_804A8578;
    lbl_8053ACA8 = p;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0xff;
}

