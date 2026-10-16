#include "types.h"

extern "C" const f32 lbl_80541AE0;
extern "C" void* lbl_804AB308[];
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void*, short);

extern "C" void fn_803221F4(char* p) {
    *(f32*)(p + 0x44) = lbl_80541AE0;
    *(f32*)(p + 0x40) = lbl_80541AE0;
    *(f32*)(p + 0x3c) = lbl_80541AE0;
    if (*(s32*)(p + 0x278) <= 0xb4) {
        *(s32*)(p + 0x278) = 0xb6;
    }
}

extern "C" void** fn_80323708(void** p, short del) {
    if (p != 0) {
        *p = lbl_804AB308;
        fn_801EE434(*(void**)((char*)p + 0x2c4));
        fn_801EE434(*(void**)((char*)p + 0x2c8));
        __dt__5ActorFv(p, 0);
        if (del > 0) {
            operator delete(p);
        }
    }
    return p;
}

