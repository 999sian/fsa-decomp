#include "types.h"

extern "C" s32 fn_801321DC(char* p) {
    return *(s32*)(p + 0x234);
}

extern "C" char lbl_8049EB8C[];
extern "C" char lbl_8049CC34[];
extern "C" void fn_801EE434(void*);
extern "C" void __dt__13Base_8010E074Fv(void*, int);
extern "C" void fn_8010E074(void*);
extern "C" void fn_801D267C(void*);
void operator delete(void*);
extern "C" s32 fn_80132AE0(char* p) {
    switch (*(s32*)(p + 0x234)) {
    case 21:
    case 25:
    case 26:
        return 1;
    }
    return 0;
}

extern "C" void* fn_80133624(char* p, s16 flag) {
    if (p != 0) {
        *(void**)p = lbl_8049EB8C;
        fn_801EE434(*(void**)(p + 0x288));
        *(void**)(p + 0x288) = 0;
        if (p + 0x250 != 0 && p + 0x274 != 0) {
            *(void**)(p + 0x274) = lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void* fn_801336B4(char* p) {
    fn_8010E074(p);
    *(void**)p = lbl_8049EB8C;
    p[0x230] = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = -1;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    fn_801D267C(p + 0x250);
    *(void**)(p + 0x288) = 0;
    return p;
}

