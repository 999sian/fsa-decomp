#include "types.h"


extern "C" char lbl_804A8578[];
extern "C" void* lbl_8053ACA8;
extern "C" u8 lbl_80529DEC[];
extern "C" void __dl__FPv(void*);
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

