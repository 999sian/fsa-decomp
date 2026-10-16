#include "types.h"


extern void* lbl_8053ADB8;
extern "C" void* fn_803D5090(void* game);
extern void* lbl_8053AD68;
extern void* lbl_8053ADA0;
extern void* lbl_8053ADA8;
extern void* lbl_8053ADC0;
extern "C" void fn_803B6768(void* p);
extern "C" void fn_803B8188(void* p);
extern "C" void fn_803D87C0(void* p);
extern "C" void fn_803A97A0(void* p);
extern "C" void fn_803B7E64(void* p);
extern "C" void fn_803D8670(void* p);
extern "C" u8 fn_8037A120(void) {
    if (*(void**)((u8*)lbl_8053AD68 + 4) != 0) {
        return *((u8*)lbl_8053ADA0 + 0x4c0);
    }
    if (*(void**)((u8*)lbl_8053AD68 + 8) != 0) {
        return *((u8*)lbl_8053ADA8 + 0x294);
    }
    if (*(void**)((u8*)lbl_8053AD68 + 0xc) != 0) {
        return *((u8*)lbl_8053ADC0 + 0x76);
    }
    return 0;
}

extern "C" void fn_8037A664(u8* p) {
    if (*(void**)(p + 4) != 0) {
        u32 v = *((u8*)lbl_8053ADA0 + 0x4c0);
        u8 c = v;
        if (c != 5 && c != 8 && c != 7) {
            fn_803A97A0(lbl_8053ADA0);
        }
    }
    if (*(void**)(p + 8) != 0) {
        u32 v = *((u8*)lbl_8053ADA8 + 0x294);
        u8 c = v;
        if (c != 5 && c != 8 && c != 7) {
            fn_803B7E64(lbl_8053ADA8);
        }
    }
    if (*(void**)(p + 0xc) != 0) {
        fn_803D8670(lbl_8053ADC0);
    }
}

extern "C" void fn_8037A708(u8* p) {
    if (*(void**)(p + 4) != 0) {
        fn_803B6768(*(void**)(p + 4));
    }
    if (*(void**)(p + 8) != 0) {
        fn_803B8188(*(void**)(p + 8));
    }
    if (*(void**)(p + 0xc) != 0) {
        fn_803D87C0(*(void**)(p + 0xc));
    }
    p[0x1c] = 0;
}

extern "C" u8 fn_8037AA28(void) {
    return *((u8*)lbl_8053ADB8 + 0x216c);
}

extern "C" void* fn_8037AA34(void) { return fn_803D5090(lbl_8053ADB8); }

extern void* lbl_8053ADB8;
extern "C" void* fn_803D5554(void* game);
extern "C" void* fn_8037AA58(void) { return fn_803D5554(lbl_8053ADB8); }

extern "C" void* fn_803D521C(void* game);
extern "C" void* fn_8037AA7C(void) { return fn_803D521C(lbl_8053ADB8); }

