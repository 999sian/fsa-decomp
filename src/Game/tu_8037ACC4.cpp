#include "types.h"

struct Slot0 {
    virtual void slot0(s32 arg);
};

extern u8* lbl_8053AAF8;
extern u8* lbl_8053AF40;
extern u8* lbl_8053AF48;
extern u32 lbl_8053AD70;
extern "C" u8 lbl_804AE9B0[];
extern "C" void* __nw__FUl(unsigned long);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_80452A80(void*);
extern "C" void* fn_80454DEC(void*);
extern "C" u8 fn_8044CB00(u8*);
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

extern "C" void fn_8044D894(void*);
extern "C" void fn_8037ADA4(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        fn_8044D894(lbl_8053AF40);
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

#pragma scheduling off
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
extern "C" void fn_804522C8(void*);
extern "C" void fn_8037AF4C(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        fn_804522C8(lbl_8053AF40);
    }
}

extern "C" void fn_80452308(void*);
extern "C" void fn_80454A00(void*);
extern "C" void fn_8037AF80(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        fn_80452308(lbl_8053AF40);
    } else {
        fn_80454A00(lbl_8053AF48);
    }
}

extern "C" void* fn_8037B000(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = (void*)lbl_804AE9B0;
        void* p1 = *(void**)((char*)this_ + 0x4);
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        *(void**)((char*)this_ + 0x4) = 0;
        void* p2 = *(void**)((char*)this_ + 0x8);
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        *(void**)((char*)this_ + 0x8) = 0;
        lbl_8053AD70 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* __nw__FUl(unsigned long);
extern "C" void* fn_8037B0B8(void* this_) {
    *(void**)this_ = (void*)lbl_804AE9B0;
    lbl_8053AD70 = (u32)this_;
    *(void**)((char*)this_ + 0x4) = 0;
    *(void**)((char*)this_ + 0x8) = 0;
    *((unsigned char*)this_ + 0xc) = 0;
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        void* p = __nw__FUl(0x188);
        if (p != 0) {
            p = fn_80452A80(p);
        }
        *(void**)((char*)this_ + 0x4) = p;
    } else {
        void* p = __nw__FUl(0x5c);
        if (p != 0) {
            p = fn_80454DEC(p);
        }
        *(void**)((char*)this_ + 0x8) = p;
    }
    return this_;
}

