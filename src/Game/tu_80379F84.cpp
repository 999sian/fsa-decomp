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
extern "C" void* fn_8037AA7C(void);
extern "C" void fn_803A8F5C(void* p);
extern "C" void fn_803B31AC(void* p);
extern "C" void fn_803B7DCC(void* p);
extern "C" void fn_803D8364(void);
extern "C" void fn_803D82EC(void* p);
extern void* lbl_8053AAF8;
extern "C" BOOL fn_80379F84(void* this_) {
    if (*((u8*)lbl_8053AAF8 + 0x7f) == 1 && *((u8*)lbl_8053AAF8 + 0x7e) == 1 && lbl_8053AD68 != 0 &&
        *(void**)((u8*)this_ + 4) != 0) {
        u8 v = *((u8*)lbl_8053ADA0 + 0x4c0);
        if (v != 5 && v != 8 && v != 7 && v != 9) {
            return TRUE;
        }
    }
    return FALSE;
}

extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern "C" void fn_80379FF4(void) {
    s32 x = *(s32*)(lbl_80529DEC + 0x118);
    s32 y = *(s32*)(lbl_80529DEC + 0x11c);
    if (x < 8 && y < 4 && x >= 0 && x <= 7 && y >= 0 && y <= 3) {
        u8* rec = lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8;
        *(u32*)(rec + 0x28) |= 1 << (y + x * 4);
    }
    if (x >= 8) {
        return;
    }
    s32 ny = y + 1;
    if (ny > 3) {
        s32 nx = x + 1;
        ny = 0;
        if (nx >= 8) {
            nx = 0;
        }
        *(s32*)(lbl_80529DEC + 0x118) = nx;
    } else {
        if ((x == 0 && ny == 2) || (x == 1 && ny == 2) || (x == 2 && ny == 2) || (x == 3 && ny == 2) ||
            (x == 4 && ny == 2) || (x == 5 && ny == 2) || (x == 6 && ny == 2) || (x == 7 && ny == 1)) {
            ny++;
        }
    }
    *(s32*)(lbl_80529DEC + 0x11c) = ny;
}

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

extern "C" void fn_8037A580(u8* p) {
    if (*(void**)(p + 4) != 0) {
        u32 v = *((u8*)lbl_8053ADA0 + 0x4c0);
        u8 c = v;
        if (c != 5 && c != 8 && c != 7) {
            fn_803A8F5C(lbl_8053ADA0);
        } else {
            fn_8037AA7C();
            fn_803B31AC(lbl_8053ADA0);
        }
    }
    if (*(void**)(p + 8) != 0) {
        u32 v = *((u8*)lbl_8053ADA8 + 0x294);
        u8 c = v;
        if (c == 5 || c == 8 || c == 7) {
            fn_8037AA7C();
            fn_803B7DCC(lbl_8053ADA8);
        }
    }
    if (*(void**)(p + 0xc) != 0) {
        u32 v = *((u8*)lbl_8053ADC0 + 0x76);
        u8 c = v;
        if (c == 2 || c == 8 || c == 7) {
            fn_803D8364();
            fn_803D82EC(lbl_8053ADC0);
        }
    }
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

