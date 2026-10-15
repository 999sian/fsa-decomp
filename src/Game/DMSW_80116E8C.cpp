#include "types.h"

extern "C" char lbl_8049DA0C[];
extern "C" char lbl_8049CC34[];
extern "C" f32 lbl_8053C75C;
extern "C" void fn_801EE434(void*);
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" void fn_8010E074(void*);
extern "C" void fn_801D267C(void*);
extern "C" s32 fn_80117498(char* p) {
    switch (*(s32*)(p + 0x234)) {
    case 12:
        return 1;
    }
    return 0;
}

extern "C" s32 fn_801174B8(char* p) {
    return *(s32*)(p + 0x234);
}

extern "C" void* fn_80118018(char* p, s16 flag) {
    if (p != 0) {
        *(void**)p = lbl_8049DA0C;
        for (s32 i = 0; i < 4; i++) {
            fn_801EE434(*(void**)(p + 0x288 + i * 4));
            *(void**)(p + 0x288 + i * 4) = 0;
            fn_801EE434(*(void**)(p + 0x298 + i * 4));
            *(void**)(p + 0x298 + i * 4) = 0;
            fn_801EE434(*(void**)(p + 0x2a8));
            *(void**)(p + 0x2a8) = 0;
        }
        if (p + 0x250 != 0 && p + 0x274 != 0) {
            *(void**)(p + 0x274) = lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void* fn_801180D0(char* p) {
    fn_8010E074(p);
    *(void**)p = lbl_8049DA0C;
    f32 f = lbl_8053C75C;
    *(u8*)(p + 0x230) = 0;
    *(u8*)(p + 0x231) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = -1;
    *(f32*)(p + 0x23c) = f;
    *(f32*)(p + 0x240) = f;
    fn_801D267C(p + 0x250);
    *(s32*)(p + 0x2a8) = 0;
    for (s32 i = 0; i < 4; i++) {
        *(s32*)(p + 0x288 + i * 4) = 0;
        *(s32*)(p + 0x298 + i * 4) = 0;
    }
    return p;
}

