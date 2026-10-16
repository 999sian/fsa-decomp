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
