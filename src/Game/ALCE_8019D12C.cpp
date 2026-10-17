#include "types.h"

extern u8 lbl_804C1E30[];
extern "C" void* fn_801F856C(void);
extern "C" void fn_801EE4F0(void*);
extern "C" void fn_8013CC50(u32, void*, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801F4694(void*);
extern "C" void detach__5ActorFv(void*);
extern "C" void fn_801F8544(void*, u32, void*, void*, s32);
extern "C" void Actor_CreateByID(void*, u32, void*, void*, s32, s32, s32);

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
    u32* src;
    if (n < 8) {
        src = (u32*)(base + 0xcc);
    } else {
        src = (u32*)(base + 0xdc);
    }
    u32 tmp[4];
    tmp[0] = src[0];
    tmp[1] = src[1];
    tmp[2] = src[2];
    tmp[3] = src[3];
    char* st = *(char**)((char*)lbl_8053AB10 + 0x24);
    if (*(u8*)(st + 0x7f5) == 0) {
        *(u8*)(st + 0x7f4) = 1;
        *(s32*)(st + 0x7f8) = 5;
        *(f32*)(st + 0x808) = *(f32*)&tmp[0];
        *(f32*)(st + 0x80c) = *(f32*)&tmp[1];
        *(f32*)(st + 0x810) = *(f32*)&tmp[2];
        *(f32*)(st + 0x814) = *(f32*)&tmp[3];
        *(u8*)(st + 0x7f6) = 0;
    }
    switch (*(s32*)(this_ + 0x238)) {
    case 0:
        if (*(s32*)(this_ + 0x230) == 0 && ((VActor*)this_)->v11()) {
            fn_801F0D20(this_, 0x42);
            fn_8019DC5C(this_);
            *(u8*)(this_ + 0x11c) = 0;
        }
        break;
    case 1:
        fn_8019D958(this_);
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
    char* sub = this_ + 8;
    if (*(s32*)(this_ + 0x244) > 0) {
        *(s32*)(sub + 0x23c) = *(s32*)(this_ + 0x244) - 1;
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

extern u8 lbl_804C1E30[];
extern f32 lbl_8053E440;
extern "C" void fn_8037AE00(void* p);
extern "C" void fn_8019DF7C(char* this_) {
    s32 i;
    f32 z = lbl_8053E440;
    u8* pb = lbl_804C1E30 + 0x4000;
    s32* pw = (s32*)(lbl_804C1E30 + 0x3000);
    f32* pf = (f32*)lbl_804C1E30;

    for (i = 0; i < 0x80; i++) {
        pf[2] = z;
        pf[1] = z;
        pf[0] = z;
        pf[5] = z;
        pf[4] = z;
        pf[3] = z;
        pf[8] = z;
        pf[7] = z;
        pf[6] = z;
        pf[11] = z;
        pf[10] = z;
        pf[9] = z;
        pf[14] = z;
        pf[13] = z;
        pf[12] = z;
        pf[17] = z;
        pw[0] = -1;
        pb[0] = 0;
        pf[16] = z;
        pw[1] = -1;
        pb[1] = 0;
        pf[15] = z;
        pw[2] = -1;
        pb[2] = 0;
        pf[20] = z;
        pw[3] = -1;
        pb[3] = 0;
        pf[19] = z;
        pw[4] = -1;
        pb[4] = 0;
        pf[18] = z;
        pw[5] = -1;
        pb[5] = 0;
        pf[23] = z;
        pw[6] = -1;
        pb[6] = 0;
        pf[22] = z;
        pf[21] = z;
        pw[7] = -1;
        pb[7] = 0;
        pf += 24;
        pw += 8;
        pb += 8;
    }

    *(u32*)(this_ + 0x238) = *(u32*)(this_ + 0x90) & 0xf;
    *(u32*)(this_ + 0x234) = (*(u32*)(this_ + 0x90) >> 4) & 3;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x264) = 0;

    if (lbl_8053ABB0 == 1) {
        *(u8*)(this_ + 0x11c) = 0;
    } else {
        s32 st = *(s32*)(this_ + 0x238);
        if (st == 1) {
            fn_8037AE00(lbl_8053AD70);
            lbl_8053ABB0 = 1;
            *(s32*)(this_ + 0x248) = 1;
            *(s32*)(this_ + 0x230) = 1;
        } else if (st < 1) {
            if (st >= 0) {
                *(s32*)(this_ + 0x230) = 0;
            }
        } else if (st < 4) {
            fn_8037AE00(lbl_8053AD70);
            lbl_8053ABB0 = 1;
            *(s32*)(this_ + 0x248) = 1;
            *(s32*)(this_ + 0x230) = 3;
        }
    }
}

