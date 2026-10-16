#include "types.h"


extern "C" void fn_801EE434(void*);
extern "C" void __dl__FPv(void*);
extern "C" void** dtor_80217F80(void** p, s16 flag) {
    if (p != 0) {
        fn_801EE434(p[0]);
        fn_801EE434(p[1]);
        p[0] = 0;
        p[1] = 0;
        fn_801EE434(p[2]);
        fn_801EE434(p[3]);
        p[2] = 0;
        p[3] = 0;
        fn_801EE434(p[4]);
        fn_801EE434(p[5]);
        p[4] = 0;
        p[5] = 0;
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_80218020(void** p) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
}
