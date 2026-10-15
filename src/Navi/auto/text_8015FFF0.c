#include "types.h"
extern "C" int fn_801C7D34(void*);
extern "C" void fn_80166FC4(void*, void*);
extern "C" void fn_8011C9EC(const char*, int, const char*, ...);
extern "C" char lbl_802EE2EC[];
extern "C" char lbl_802981A8[];
extern "C" char lbl_802981B8[];
extern "C" char lbl_802FE368[4];
extern "C" void fn_801BE3A0(void*);
extern "C" void fn_801BDEE4(void*, void*, int);
extern "C" void fn_801BE47C(void*);
extern "C" void fn_801BDE1C(void*, void*, int);
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015fff0-0x80164978 (90 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8015FC80(void*, int);
extern char lbl_80297CE8[];
extern "C" void fn_80166C08(void*, int);
extern "C" void* fn_8015FFF0(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_80160CDC(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80297CE8;
        fn_8015FC80(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80160C34(void*, void*, int);
extern "C" u8 fn_80161A2C(void*, void*, void*);
extern "C" void fn_80166D3C(void*, void*);
extern "C" char lbl_80297DD4[];
extern "C" char lbl_802EE2D4[];
extern "C" void* fn_80161710(void*, void*);
extern "C" void* fn_80161874(void* a, void** b) {
    *b = fn_80161710(a, *b);
    return a;
}

extern "C" int fn_801618B8(int p) { return p + 4; }

extern "C" u16 fn_801618C0(u16* p) { return *p; }

extern "C" u8* fn_801618C8(u8* p, void* a, void* b) {
    fn_80160C34(p, a, 1);
    *(void**)p = lbl_80297DD4;
    p[0x30] = 0;
    *(void**)(p + 0x60) = b;
    if (!fn_80161A2C(p, a, *(void**)(p + 0x60))) {
        return p;
    }
    *(u32*)(p + 0x2c) = 0x52415243;
    *(int*)(p + 0x28) = *(int*)(p + 0x54) + *(int*)(*(u8**)(p + 0x48) + 4);
    fn_80166D3C(lbl_802EE2D4, p + 0x18);
    p[0x30] = 1;
    return p;
}

extern "C" void fn_8015D0B8(void*, int);
extern char lbl_80297E68[];
extern "C" void* fn_80162A70(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80297E68;
        fn_8015D0B8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_801647A0(u8* p) {
    if (p[0x18]) {
        if (fn_801C7D34(p + 0x5c)) {
            p[0x18] = 0;
            fn_80166FC4(lbl_802EE2EC, p + 0xe4);
        } else {
            fn_8011C9EC(lbl_802981A8, 0xd5, lbl_802FE368, lbl_802981B8);
        }
    }
}

extern "C" u32 fn_801648EC(u8* p) {
    u32 v;
    fn_801BE3A0(p + 0x1c);
    fn_801BDEE4(p + 0xc0, &v, 1);
    *(u32*)(p + 0xf4) = 0;
    fn_801BE47C(p + 0x1c);
    return v;
}

extern "C" void fn_80164940(void* a, u8* b) {
    fn_801BDE1C(*(u8**)(b + 0x3c) + 0xc0, a, 0);
}

extern "C" int fn_801C7D34(void*);
extern "C" void fn_80166FC4(void*, void*);
extern "C" void fn_8011C9EC(const char*, int, const char*, ...);
extern "C" char lbl_802EE2EC[];
extern "C" char lbl_802981A8[];
extern "C" char lbl_802981B8[];
extern "C" char lbl_802FE368[];
extern "C" void fn_801BE3A0(void*);
extern "C" void fn_801BDEE4(void*, void*, int);
extern "C" void fn_801BE47C(void*);
extern "C" void fn_801BDE1C(void*, void*, int);
extern "C" u32 fn_80164970(u8* p) { return *(u32*)(p + 0x90); }
extern "C" int fn_801C7D34(void*);
extern "C" void fn_80166FC4(void*, void*);
extern "C" void fn_8011C9EC(const char*, int, const char*, ...);
extern "C" char lbl_802EE2EC[];
extern "C" char lbl_802981A8[];
extern "C" char lbl_802981B8[];
extern "C" char lbl_802FE368[];
extern "C" void fn_801BE3A0(void*);
extern "C" void fn_801BDEE4(void*, void*, int);
extern "C" void fn_801BE47C(void*);
extern "C" void fn_801BDE1C(void*, void*, int);
