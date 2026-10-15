#include "types.h"


extern u8* lbl_8053AAF8;
extern u8* lbl_8053AF40;
extern u8* lbl_8053AF48;
extern u32 lbl_8053AD70;
extern "C" void fn_8044CB08(void*);
extern "C" int fn_8044F664(void);
extern "C" int fn_80453AF8(void);
extern "C" int fn_8044F680(void*);
extern "C" int fn_80453B14(void*);
extern "C" void fn_8037AD00(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        fn_8044CB08(lbl_8053AF40);
    }
}

extern "C" void fn_8037AE30(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        *(u8*)(lbl_8053AF40 + 0x13f) = 1;
    } else {
        *(u8*)(lbl_8053AF48 + 0x54) = 1;
    }
}

