#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8013edb8-0x80140b80 (37 functions). split_file divides it into the game's real files.

extern s32 lbl_802FF388;
extern u8 lbl_802C6A80[];
extern "C" void fn_801404EC(void);
extern "C" void fn_8013EDB8(void);
extern "C" void fn_80140520(s32 idx);
extern "C" s32 fn_801406B0(s32 idx, s32 a, s32 b, void (*cb)(void));
extern "C" void fn_8013EF14(s32 idx, s32 param_2) {
    u8* s = lbl_802C6A80 + (idx << 8);
    s32 r;
    if (*(u32*)(s + 0x1c) == 0) {
        s[0] = 0;
        *(s32*)(s + 0x14) = param_2;
        *(void**)(s + 0x1c) = (void*)fn_801404EC;
        r = fn_801406B0(idx, 1, 3, fn_8013EDB8);
    } else {
        r = 2;
    }
    if (r == 0) {
        fn_80140520(idx);
    }
}

extern "C" s32 fn_8013EFA4(s32 idx, s32 param_2, s32 param_3) {
    u8* s = lbl_802C6A80 + (idx << 8);
    if (*(u32*)(s + 0x1c) == 0) {
        s[0] = 0xff;
        *(s32*)(s + 0x14) = param_2;
        *(s32*)(s + 0x1c) = param_3;
        return fn_801406B0(idx, 1, 3, fn_8013EDB8);
    }
    return 2;
}

extern "C" void fn_8013F008(s32 idx, s32 param_2) {
    u8* s = lbl_802C6A80 + (idx << 8);
    s32 r;
    if (*(u32*)(s + 0x1c) == 0) {
        s[0] = 0xff;
        *(s32*)(s + 0x14) = param_2;
        *(void**)(s + 0x1c) = (void*)fn_801404EC;
        r = fn_801406B0(idx, 1, 3, fn_8013EDB8);
    } else {
        r = 2;
    }
    if (r == 0) {
        fn_80140520(idx);
    }
}

extern "C" s32 fn_8013F098(void) {
    lbl_802FF388 = 1;
    return lbl_802FF388 == 1 ? 1 : 0;
}

