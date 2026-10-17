// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80006500-0x8000b470 (36 functions). split_file divides it into the game's real files.
#include "types.h"

extern void* lbl_80298574[];
extern void* lbl_80298520[];
extern u8 lbl_802B7CA0[];
extern u8 lbl_8029F8B0[];
extern char lbl_802037D8[];
extern char lbl_8020383C[];
extern char lbl_802FB790[4];
extern char lbl_802FB794[4];
extern s16 lbl_802FEB42;
extern u8 lbl_802FEB08;
extern u8 lbl_802FEB20;
extern u8 lbl_8029F408[];
extern void* lbl_802FEB5C;
extern void* lbl_802FEB4C;
extern void* lbl_802FEB50;
extern u32 lbl_802FEB54;
extern u8 lbl_802FB7B0, lbl_802FB7B1, lbl_802FB7B2;
extern "C" {
void fn_8015AB1C(void*);
u32 fn_8000F74C(u32, u32, u32);
void fn_800082C8(void);
void fn_8005FEC0(void*);
void fn_8000F9E8(u32);
void fn_8000FAB4(void);
void fn_801BB7E0(void*);
BOOL OSDisableInterrupts(void);
BOOL OSRestoreInterrupts(BOOL);
void (*fn_801DB640(void*))(void);
void* fn_8011FD10(void);
void fn_8011FD18(void*, const char*, int, const char*, ...);
void fn_80007AB8(const char*, int, const char*, ...);
u32 fn_800095BC(void*, void*, u8, u8, u8);
void DCFlushRange(void*, u32);
void fn_801C0A6C(u32);
void fn_801C13D0(void*);
void fn_8006069C(void*);
}

extern "C" void fn_80006EE4(void) {
    lbl_802FEB08 = 1;
}

extern "C" void fn_80006EF0(void) {
    lbl_802FEB08 = 0;
}

extern "C" void fn_80006EFC(void) {
    if (lbl_802FEB20 != 0) {
        return;
    }
    lbl_802FEB20 = 1;
}

extern "C" void fn_8000829C(u8 param_1, u8 param_2) {
    lbl_8029F408[0x46] = param_1;
    lbl_8029F408[0x47] = param_2;
    lbl_8029F408[0x96] = param_1;
    lbl_8029F408[0x97] = param_2;
    lbl_8029F408[0xe6] = param_1;
    lbl_8029F408[0xe7] = param_2;
    lbl_8029F408[0x136] = param_1;
    lbl_8029F408[0x137] = param_2;
}

extern "C" void fn_800085E0(void) {}

extern "C" void fn_800085E4(void) {}

extern "C" u32 fn_8000A1AC(void) {
    u32 value = fn_800095BC(lbl_802FEB4C, lbl_802FEB50, lbl_802FB7B1, lbl_802FB7B2, lbl_802FB7B0);
    DCFlushRange(lbl_802FEB50, lbl_802FEB54);
    fn_801C0A6C(value);
    return value;
}

extern "C" void fn_8000A208(void) {
    fn_801BB7E0(lbl_8029F8B0);
    BOOL enabled = OSDisableInterrupts();
    if (lbl_802FEB42 == 2) {
        if (fn_801DB640(lbl_802FEB5C) != fn_8000A208) {
            fn_8011FD18(fn_8011FD10(), lbl_802037D8, 0x9D3, lbl_802FB790, lbl_8020383C);
            fn_80007AB8(lbl_802037D8, 0x9D3, lbl_802FB794);
        }
        lbl_802FEB5C = nullptr;
        lbl_802FEB42++;
    }
    OSRestoreInterrupts(enabled);
}

extern "C" void* fn_8000B3B8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80298574;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80298520;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_8000B414(void) {
    u32 value = fn_8000F74C(0, 0, 0);
    fn_800082C8();
    fn_8005FEC0(lbl_802B7CA0 + 0x1424);
    fn_8000F9E8(value);
    fn_8000FAB4();
    return 1;
}

