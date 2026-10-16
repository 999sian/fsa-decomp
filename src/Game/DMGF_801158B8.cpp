#include "types.h"

extern "C" char lbl_8049D940[];
extern "C" void fn_8010E074(void*);
extern "C" void fn_801D267C(void*);
extern "C" void fn_801EB950(void*);
extern "C" char lbl_8049CC34[];
extern "C" void fn_801EE434(void*);
extern "C" void dtor_801EB8CC(void*, s32);
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" s32 fn_801162B8(char* p) {
    switch (*(s32*)(p + 0x230)) {
    case 11:
        return 1;
    }
    return 0;
}

extern "C" s32 fn_801162D8(char* p) {
    return *(s32*)(p + 0x230);
}

extern "C" void* fn_80116B08(char* p, s16 freeFlag) {
    if (p != 0) {
        *(void**)p = lbl_8049D940;
        *(s32*)(p + 0x31c) = 0;
        *(s32*)(p + 0x320) = 0;
        *(s32*)(p + 0x324) = 0;
        *(s32*)(p + 0x328) = 0;
        *(s32*)(p + 0x32c) = 0;
        fn_801EE434(*(void**)(p + 0x314));
        *(s32*)(p + 0x314) = 0;
        fn_801EE434(*(void**)(p + 0x318));
        *(s32*)(p + 0x318) = 0;
        dtor_801EB8CC(p + 0x2a8, -1);
        if (p + 0x270 != 0) {
            if (p + 0x294 != 0) {
                *(void**)(p + 0x294) = lbl_8049CC34;
            }
        }
        if (p + 0x238 != 0) {
            if (p + 0x25c != 0) {
                *(void**)(p + 0x25c) = lbl_8049CC34;
            }
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void* fn_80116BE8(char* p) {
    fn_8010E074(p);
    *(void**)p = lbl_8049D940;
    *(s32*)(p + 0x230) = 0;
    *(u8*)(p + 0x234) = 0;
    fn_801D267C(p + 0x238);
    fn_801D267C(p + 0x270);
    fn_801EB950(p + 0x2a8);
    *(s32*)(p + 0x314) = 0;
    *(s32*)(p + 0x318) = 0;
    *(s32*)(p + 0x32c) = 0;
    *(s32*)(p + 0x31c) = 0;
    *(s32*)(p + 0x320) = 0;
    *(s32*)(p + 0x324) = 0;
    *(s32*)(p + 0x328) = 0;
    return p;
}

