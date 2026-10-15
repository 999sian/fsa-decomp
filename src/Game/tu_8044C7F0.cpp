#include "types.h"

extern "C" void fn_804316EC(void*);
extern void* lbl_8053AEC0;
extern void* lbl_8053AF40;

extern "C" u8 fn_8044CB00(u8* p) { return p[0x140]; }

extern "C" u8 fn_8044D290(u8* p) { return p[0x140]; }

extern "C" void* fn_8044F664(void) {
    if (lbl_8053AF40 != 0) {
        return *(void**)((char*)lbl_8053AF40 + 0x184);
    }
    return (void*)9;
}

extern "C" void fn_804522C8(u8* p) {
    s16 v = *(s16*)(p + 0xfa);
    if (v == 7 || v == 8 || v == 9) {
        fn_804316EC(lbl_8053AEC0);
    }
}

extern "C" u8 fn_80453848(u8* p) {
    u8 dead = 0;
    if ((*(u32*)(p + 0xf4) & 8) && *(s32*)(p + 0xd0) + *(s32*)(p + 0xdc) == 0) {
        dead = 1;
    }
    return dead;
}

