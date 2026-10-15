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

extern "C" void fn_8044D298(void*);
extern "C" void fn_8037AD70(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        fn_8044D298(lbl_8053AF40);
    }
}

extern "C" void fn_8037AE30(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        *(u8*)(lbl_8053AF40 + 0x13f) = 1;
    } else {
        *(u8*)(lbl_8053AF48 + 0x54) = 1;
    }
}

extern "C" int fn_8037AE60(void) {
    if (lbl_8053AD70 != 0) {
        if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
            return fn_8044F664();
        } else {
            return fn_80453AF8();
        }
    }
    return 9;
}

extern "C" int fn_8037AEAC(void* self_) {
    u8* self = (u8*)self_;
    int uVar1;
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        uVar1 = fn_8044F680(lbl_8053AF40);
    } else {
        uVar1 = fn_80453B14(lbl_8053AF48);
    }
    int iVar2;
    if (lbl_8053AD70 == 0) {
        iVar2 = 9;
    } else if (*(u8*)(lbl_8053AAF8 + 0x7f) == 0) {
        iVar2 = fn_80453AF8();
    } else {
        iVar2 = fn_8044F664();
    }
    if (iVar2 != 9) {
        *(u8*)(self + 0xc) = 0;
    }
    return uVar1;
}

