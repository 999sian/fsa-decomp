#include "types.h"


extern "C" void fn_801F0E34(void* this_, u32 a, u32 b);
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void* fn_801F856C(void);
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* p);
extern const f32 lbl_805429A8;
extern const f32 lbl_805429AC;
extern const f32 lbl_805429B0;
extern char lbl_804AD858[];
extern char lbl_804A5958[];
extern "C" void fn_80234810();
extern "C" void fn_802382D0(u32 a, u32 b);
extern "C" void fn_8023077C();
extern "C" void* fn_8035E8CC(void* p, short f) {
    if (p) {
        *(void**)p = lbl_804AD858;
        if (p) {
            *(void**)p = lbl_804A5958;
            __dt__5ActorFv(p, 0);
        }
        if (f > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_8035E93C(void* this_) {
    char* p = (char*)this_;
    if (*(f32*)(p + 0x10) < lbl_805429A8) {
        if (*(s32*)(p + 0x244) == 0) {
            *(s32*)(p + 0x244) = 6;
            *(s32*)(p + 0x248) = *(s32*)(p + 0x248) + 1;
            if (*(s32*)(p + 0x248) >= 8) {
                *(s32*)(p + 0x248) = 0;
            }
        }
        *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + lbl_805429AC;
    } else {
        *(u8*)(p + 0x11c) = 0;
    }
}

extern "C" void fn_8035E9A0(void* this_) {
    char* p = (char*)this_;
    void* base = fn_801F856C();
    void* found = fn_801F666C(base, *(s32*)(p + 0x90));
    if (found != 0) {
        if (*(f32*)((char*)found + 0x10) >= lbl_805429B0) {
            *(s32*)(p + 0x248) = 0;
            *(s32*)(p + 0x250) = 0x3d;
            if (*(s32*)((char*)found + 0x230) == 4 && *(s32*)((char*)found + 0x234) < 0xf0) {
                *(s32*)(p + 0x250) = 0x3f;
            }
        }
    }
    if (*(s32*)(p + 0x238) != 0) {
        *(s32*)(p + 0x248) = 0;
        *(s32*)(p + 0x250) = 0x10;
        *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
    }
}

extern "C" void fn_8035EA48(void* this_) {
    char* p = (char*)this_;
    if (*(s32*)(p + 0x234) == 0) {
        *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, *(s32*)(p + 0x23c));
        if (found != 0) {
            *(s32*)((char*)found + 0x230) = 3;
        }
    }
}

extern "C" void fn_8035EAA4(void* this_) {
    char* p = (char*)this_;
    if (*(s32*)(p + 0x234) == 0) {
        fn_801F0E34(this_, 0x30085, 0);
        void* base = fn_801F856C();
        void* found = fn_801F666C(base, *(s32*)(p + 0x23c));
        if (found != 0) {
            *(s32*)((char*)found + 0x238) = 1;
        }
        *(s32*)(p + 0x234) = 0x78;
        *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
    }
}

extern const f32 lbl_805429B4;
extern const f32 lbl_805429B8;
extern const f32 lbl_805429BC;
extern const f32 lbl_805429CC;
extern const f32 lbl_805429D0;
extern const f32 lbl_805429D4;
extern "C" void fn_8035EB18(void* this_) {
    char* p = (char*)this_;
    if (*(s32*)(p + 0x234) == 0) {
        *(f32*)(p + 0xc) = *(f32*)(p + 0xc) + lbl_805429B4;
        *(f32*)(p + 0x10) = *(f32*)(p + 0x10) - lbl_805429B8;
        *(s32*)(p + 0x234) = 0x10e;
        *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
    } else if (*(s32*)(p + 0x234) == 10) {
        fn_801F0E34(this_, 0x30088, 0);
    }
}

extern "C" void fn_8013CC50(void* this_, f32* pos, u16 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 f);
extern const f32 lbl_805429C0;
extern const f32 lbl_805429C4;
extern const f32 lbl_805429C8;
extern u16 lbl_80472820[];
extern "C" void fn_8035EC98(void* this_) {
    char* p = (char*)this_;
    if (*(s32*)(p + 0x234) == 0) {
        f32 pos[3] = {lbl_805429C0, lbl_805429C4, lbl_805429BC};
        for (s32 i = 0; i < 0x11; i++) {
            fn_8013CC50(*(void**)(p + 4), pos, lbl_80472820[i], 1, 1, 0, 0, 1, lbl_805429C8);
        }
        fn_801F0E34(this_, 0x30087, 0);
        *(s32*)(p + 0x234) = 0x14;
        *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
    }
}

extern "C" void fn_8035ED60(char* self) {
    *(f32*)(self + 0x260) = *(f32*)(self + 0x10);
    if (*(f32*)(self + 0x10) >= lbl_805429B0) {
        *(f32*)(self + 0x10) = *(f32*)(self + 0x10) - lbl_805429CC;
        if (*(s32*)(self + 0x244) == 0) {
            *(s32*)(self + 0x244) = 7;
            *(s32*)(self + 0x248) = *(s32*)(self + 0x248) + 1;
            if (*(s32*)(self + 0x248) >= 8) {
                *(s32*)(self + 0x248) = 0;
            }
        }
        *(s32*)(self + 0x268) = *(s32*)(self + 0x248);
    } else {
        *(s32*)(self + 0x268) = 0;
        *(s32*)(self + 0x248) = 0;
        *(s32*)(self + 0x244) = 0;
        char* p = (char*)fn_801F666C(fn_801F856C(), *(s32*)(self + 0x23c));
        if (p != 0) {
            *(s32*)(p + 0x230) = 2;
        }
        *(s32*)(self + 0x234) = 0x8f;
        *(s32*)(self + 0x230) = *(s32*)(self + 0x230) + 1;
    }
}

extern "C" void fn_8035EE30(void) {
}

extern "C" void fn_8035EFB4(void* this_) {
    char* p = (char*)this_;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0x18;
    fn_80234810();
    fn_802382D0(0, 0);
    fn_8023077C();
    *(f32*)(p + 0x254) = lbl_805429D0 + (*(f32*)(p + 0xc) + lbl_805429BC);
    *(f32*)(p + 0x258) = lbl_805429D0 + (*(f32*)(p + 0xc) + lbl_805429D0);
    *(f32*)(p + 0x25c) = lbl_805429D0 + (*(f32*)(p + 0xc) + lbl_805429D4);
    *(f32*)(p + 0x260) = *(f32*)(p + 0x10);
    *(s32*)(p + 0x264) = 0x18;
    *(s32*)(p + 0x268) = 0;
    *(s32*)(p + 0x26c) = 0;
}

