#include "types.h"

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SP01) || defined(VERSION_G4SE01)
extern "C" int fn_80113788(char* self) {
    return *(int*)(self + 0x23c);
}

#if defined(VERSION_G4SE01)
extern "C" int fn_80113E98(char* self) {
    switch (*(int*)(self + 0x23c)) {
    case 10:
    case 0x11:
        return 1;
    }
    return 0;
}
#endif

extern "C" void fn_8010DF58(char*);
extern "C" void fn_80113790(char*);
extern "C" void fn_80113B54(char*, int);
extern int lbl_80464830[];
extern "C" void fn_80114C1C(char* self) {
    fn_8010DF58(self);
    fn_80113790(self);
    switch (*(int*)(self + 0x23c)) {
    case 0x10:
        fn_80113B54(self, 0x1d6);
        break;
    default:
        if (*(unsigned char*)(self + 0x232) != 0) {
            fn_80113B54(self, lbl_80464830[*(int*)(self + 0x238)]);
        }
        break;
    }
}

extern "C" void fn_801EE434(void* handle);
extern "C" void __dl__FPv(void* p);
extern "C" void __dt__13Base_8010E074Fv(void* p, s32 how);
extern "C" void* fn_80115430(char* p, s16 freeFlag) {
    extern void* lbl_8049D83C[];
    extern void* lbl_8049CC34[];
    if (p != 0) {
        *(void**)p = lbl_8049D83C;
        if (*(void**)(p + 0x2a0) != 0) {
            fn_801EE434(*(void**)(p + 0x2a0));
            *(s32*)(p + 0x2a0) = 0;
        }
        if (*(void**)(p + 0x29c) != 0) {
            fn_801EE434(*(void**)(p + 0x29c));
            *(s32*)(p + 0x29c) = 0;
        }
        s32 i = 0;
        char* q = p;
        for (; i < 7; i++) {
            fn_801EE434(*(void**)(q + 0x2a8));
            *(s32*)(q + 0x2a8) = 0;
            if (i < 2) {
                fn_801EE434(*(void**)(q + 0x2e8));
                *(s32*)(q + 0x2e8) = 0;
            }
            if (i < 3) {
                fn_801EE434(*(void**)(q + 0x2c4));
                *(s32*)(q + 0x2c4) = 0;
            }
            if (i < 5) {
                fn_801EE434(*(void**)(q + 0x2d0));
                *(s32*)(q + 0x2d0) = 0;
            }
            q += 4;
        }
        if (*(void**)(p + 0x2a4) != 0) {
            fn_801EE434(*(void**)(p + 0x2a4));
            *(s32*)(p + 0x2a4) = 0;
        }
        if (*(void**)(p + 0x2e4) != 0) {
            fn_801EE434(*(void**)(p + 0x2e4));
            *(s32*)(p + 0x2e4) = 0;
        }
        if (p + 0x264 != 0 && p + 0x288 != 0) {
            *(void**)(p + 0x288) = lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" char lbl_8049D83C[];
extern "C" s32 lbl_8053AF80;
extern "C" f32 lbl_8053C69C;
extern "C" void fn_8010E074(void*);
extern "C" void fn_801D267C(void*);
extern "C" void fn_80458F9C(s32, s32);
extern "C" void* fn_80115590(char* self) {
    s32 i;
    s32 off;
    f32 zero;

    fn_8010E074(self);
    *(void**)self = lbl_8049D83C;
    zero = lbl_8053C69C;
    *(u8*)(self + 0x230) = 1;
    *(u8*)(self + 0x231) = 1;
    *(u8*)(self + 0x232) = 0;
    *(u8*)(self + 0x233) = 0;
    *(u8*)(self + 0x234) = 1;
    *(s32*)(self + 0x238) = 0;
    *(s32*)(self + 0x23c) = 0;
    *(s32*)(self + 0x240) = 0;
    *(s32*)(self + 0x244) = 0;
    *(s32*)(self + 0x248) = 0;
    *(s32*)(self + 0x24c) = 0;
    *(f32*)(self + 0x250) = zero;
    *(f32*)(self + 0x254) = zero;
    *(f32*)(self + 0x258) = zero;
    *(f32*)(self + 0x25c) = zero;
    *(s32*)(self + 0x260) = 0;
    fn_801D267C(self + 0x264);
    *(s32*)(self + 0x29c) = 0;
    *(s32*)(self + 0x2a0) = 0;
    *(s32*)(self + 0x2a4) = 0;
    *(s32*)(self + 0x2e4) = 0;
    for (i = 0, off = 0; i < 7; off += 4, i++) {
        *(s32*)((u8*)self + off + 0x2a8) = 0;
        if (i < 2) {
            *(s32*)((u8*)self + off + 0x2e8) = 0;
        }
        if (i < 3) {
            *(s32*)((u8*)self + off + 0x2c4) = 0;
        }
        if (i < 5) {
            *(s32*)((u8*)self + off + 0x2d0) = 0;
        }
    }
    fn_80458F9C(lbl_8053AF80, 0x3c);
    return self;
}

#endif
