#include "types.h"

extern "C" void fn_801EE434(void*);
extern "C" void fn_8022ADCC(void);
extern "C" void fn_80134FC4(void*, s32);
extern "C" void fn_8037AE30(void*);
extern "C" void __dt__5ActorFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern char lbl_804A2AB0[];
extern void* lbl_8053AAF8;
extern void* lbl_8053AD70;
extern u8 lbl_8053ABB0;
struct Quad {
    f32 v[4];
};
struct Words {
    u32 v[4];
};
struct VActor {
    virtual void v00(void);
    virtual void v01(void);
    virtual void v02(void);
    virtual void v03(void);
    virtual void v04(void);
    virtual void v05(void);
    virtual void v06(void);
    virtual void v07(void);
    virtual void v08(void);
    virtual void v09(void);
    virtual void v10(void);
    virtual u8 v11(void);
};

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_8019D958(char* p);
extern "C" void fn_8019D2AC(char* p);
extern "C" void fn_8019DC5C(char* p);
extern "C" void fn_801F0D20(char* p, s32 n);
extern void* lbl_8053AB10;
extern "C" void fn_8019D12C(char* this_) {
    s32 n = *(s32*)(this_ + 0x4);
    char* base = (char*)fn_802D6A9C();
    Quad* src;
    if (n < 8) {
        src = (Quad*)(base + 0xcc);
    } else {
        src = (Quad*)(base + 0xdc);
    }
    Quad q = *src;
    char* st = *(char**)((char*)lbl_8053AB10 + 0x24);
    if (*(u8*)(st + 0x7f5) == 0) {
        *(u8*)(st + 0x7f4) = 1;
        *(s32*)(st + 0x7f8) = 5;
        *(Quad*)(st + 0x808) = q;
        *(u8*)(st + 0x7f6) = 0;
    }
    switch (*(s32*)(this_ + 0x238)) {
    case 1:
        fn_8019D958(this_);
        break;
    case 0:
        if (*(s32*)(this_ + 0x230) == 0 && ((u8 (*)(char*))(*(void**)(*(char**)this_ + 0x34)))(this_) != 0) {
            fn_801F0D20(this_, 0x42);
            fn_8019DC5C(this_);
            *(u8*)(this_ + 0x11c) = 0;
        }
        break;
    case 2:
    case 3:
        fn_8019D2AC(this_);
        break;
    }
    if (*(s32*)(this_ + 0x23c) > 0) {
        *(s32*)(this_ + 0x23c) = *(s32*)(this_ + 0x23c) - 1;
    }
    if (*(s32*)(this_ + 0x240) > 0) {
        *(s32*)(this_ + 0x240) = *(s32*)(this_ + 0x240) - 1;
    }
    if (*(s32*)(this_ + 0x244) > 0) {
        *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x244) - 1;
    }
}

extern "C" void* fn_8019DEB4(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2AB0;
        char* p = this_;
        int i = 0;
        do {
            fn_801EE434(*(void**)(p + 0x260));
            i++;
            p += 4;
        } while (i < 2);
        if (*(s32*)(this_ + 0x248) == 1) {
            fn_8022ADCC();
            *(s32*)(this_ + 0x248) = 0;
            fn_80134FC4(lbl_8053AAF8, 0);
            lbl_8053ABB0 = 0;
            fn_8037AE30(lbl_8053AD70);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
