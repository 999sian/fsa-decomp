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

