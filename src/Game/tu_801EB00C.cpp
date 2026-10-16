#include "types.h"

extern "C" void fn_801EE434(void*);
extern "C" void __dl__FPv(void*);
extern const float lbl_8053F69C;
extern const float lbl_8053F6A0;
extern const float lbl_8053F6A4;
extern const float lbl_8053F6A8;
extern const float lbl_8053F6AC;
extern const float lbl_8053F6B0;
extern const float lbl_8053F678;
extern "C" u16 fn_801CD664(s32);
extern "C" char* dtor_801EB8CC(char* p, s16 freeFlag) {
    if (p != 0) {
        for (s32 i = 0; i < 7; i++) {
            fn_801EE434(*(void**)(p + 0x34 + i * 4));
        }
        fn_801EE434(*(void**)(p + 0x50));
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_801EBA14(char* p) {
    *(s32*)(p + 0x0) = 1;
    *(s32*)(p + 0x4) = 1;
    *(f32*)(p + 0x8) = lbl_8053F69C;
    *(f32*)(p + 0xc) = lbl_8053F6A0;
    *(f32*)(p + 0x10) = lbl_8053F6A4;
    *(f32*)(p + 0x14) = lbl_8053F6A8;
    *(f32*)(p + 0x18) = lbl_8053F6AC;
    *(f32*)(p + 0x1c) = lbl_8053F6B0;
    *(f32*)(p + 0x20) = lbl_8053F6AC;
    *(s16*)(p + 0x24) = 0x600;
}
