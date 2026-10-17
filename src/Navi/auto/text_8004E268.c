#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004e268-0x8004e8fc (12 functions). split_file divides it into the game's real files.

extern void* lbl_80247174[];
extern void* lbl_802471EC[];
extern void* lbl_802471C4[];
extern f32 lbl_80300158;
extern f32 lbl_8030015C;
extern f32 lbl_80300160;
extern f32 lbl_80300164;
extern f32 lbl_80300168;
extern f32 lbl_8030016C;
extern f32 lbl_80300170;
extern f32 lbl_80300174;
extern f32 lbl_80300178;
extern f32 lbl_8030017C;
extern f32 lbl_80300180;
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_801DE4F4(s32, void*);
extern "C" void fn_8004E268(void* param_1) {
    s32 local[1];
    local[0] = *(s32*)((u8*)param_1 + 4);
    fn_801DE4F4(2, local);
}

extern "C" void fn_8004E298(void) {}

extern char lbl_80247000[];
extern "C" void fn_801303BC(void*, int);
extern char lbl_802470CC[];
extern "C" void* fn_8004E29C(void** param_1, s16 param_2) {
    if (param_1 != nullptr) {
        param_1[0] = (void*)lbl_802470CC;
        if (param_1 != nullptr) {
            param_1[0] = (void*)lbl_80247000;
            fn_801303BC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8004E30C(void* ptr) {
    u8* p = (u8*)ptr;
    *(void**)p = lbl_802471EC;
    *(s16*)(p + 0x6) = 0;
    *(s16*)(p + 0x8) = 0;
    *(s16*)(p + 0xa) = 0;
    *(s16*)(p + 0xc) = 0xff;
    *(s16*)(p + 0xe) = 0;
    *(s16*)(p + 0x10) = 0;
    *(s16*)(p + 0x12) = 0;
    *(s16*)(p + 0x14) = 0xff;
    *(s16*)(p + 0x16) = 0;
    *(s16*)(p + 0x18) = 0;
    *(s16*)(p + 0x1a) = 0;
    *(s16*)(p + 0x1c) = 0xff;
    *(s16*)(p + 0x1e) = 0;
    *(s16*)(p + 0x20) = 0;
    *(s16*)(p + 0x22) = 0;
    *(s16*)(p + 0x24) = 0xff;
    *(s16*)(p + 0x26) = 0;
    *(s16*)(p + 0x28) = 0;
    *(s16*)(p + 0x2a) = 0;
    *(s16*)(p + 0x2c) = 0xff;
    *(s16*)(p + 0x2e) = 0;
    *(s16*)(p + 0x30) = 0;
    *(s16*)(p + 0x32) = 0;
    *(s16*)(p + 0x34) = 0xff;
    *(s16*)(p + 0x36) = 0;
    *(s16*)(p + 0x38) = 0;
    *(s16*)(p + 0x3a) = 0;
    *(s16*)(p + 0x3c) = 0xff;
    *(s16*)(p + 0x3e) = 0;
    *(s16*)(p + 0x40) = 0;
    *(s16*)(p + 0x42) = 0;
    *(s16*)(p + 0x44) = 0xff;
    *(s16*)(p + 0x46) = 0;
    *(s16*)(p + 0x48) = 0;
    *(s16*)(p + 0x4a) = 0;
    *(s16*)(p + 0x4c) = 0xff;
    *(s16*)(p + 0x4e) = 0;
    *(s16*)(p + 0x50) = 0;
    *(s16*)(p + 0x52) = 0;
    *(s16*)(p + 0x54) = 0xff;
}

extern "C" void fn_8004E3C4(void* ptr) {
    u8* p = (u8*)ptr;
    *(void**)p = lbl_802471C4;
    *(s16*)(p + 0x42) = 0;
    *(s16*)(p + 0x44) = 0;
    *(s16*)(p + 0x46) = 0;
    *(s16*)(p + 0x48) = 0;
    *(s16*)(p + 0x4a) = 0;
    *(s16*)(p + 0x4c) = 0;
    *(s16*)(p + 0x4e) = 0;
    *(s16*)(p + 0x50) = 0;
    *(s16*)(p + 0x52) = 0;
    *(s16*)(p + 0x54) = 0;
    *(s16*)(p + 0x56) = 0;
    *(s16*)(p + 0x58) = 0;
    *(s16*)(p + 0x5a) = 0;
    *(s16*)(p + 0x5c) = 0;
    *(s16*)(p + 0x5e) = 0;
    *(f32*)(p + 0x8) = 1.0f;
    *(f32*)(p + 0xc) = 0.0f;
    *(f32*)(p + 0x10) = 0.0f;
    *(f32*)(p + 0x14) = 30.0f;
    *(f32*)(p + 0x18) = 25000.0f;
    *(f32*)(p + 0x1c) = 15000.0f;
    *(f32*)(p + 0x20) = 350.0f;
    *(f32*)(p + 0x24) = 0.001f;
    *(f32*)(p + 0x28) = 1.2f;
    *(f32*)(p + 0x2c) = 8.0f;
    *(f32*)(p + 0x30) = 0.0f;
    *(s16*)(p + 0x3c) = 0x96;
    *(s16*)(p + 0x3e) = 0;
    *(s16*)(p + 0x40) = 0;
    *(f32*)(p + 0x34) = -2500.0f;
    *(f32*)(p + 0x38) = 15.0f;
}

extern "C" void* fn_8004E71C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247174;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8024719C[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8004E764(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8024719C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802471C4[];
extern "C" void* fn_8004E7AC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802471C4;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802471EC[];
extern "C" void* fn_8004E7F4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802471EC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern f32 lbl_80300158;
extern f32 lbl_8030015C;
extern f32 lbl_80300160;
extern f32 lbl_80300164;
extern f32 lbl_80300168;
extern f32 lbl_8030016C;
extern f32 lbl_80300170;
extern f32 lbl_80300174;
extern f32 lbl_80300178;
extern f32 lbl_8030017C;
extern f32 lbl_80300180;
extern void* lbl_8024714C[];
extern void* lbl_80222428[];
extern "C" void fn_801E0D40(void*, void*, s32, s32);
extern "C" void* fn_8004E83C(void** p, s16 param_2) {
    if (p != 0) {
        p[0] = lbl_8024714C;
        fn_801E0D40(&p[0x34], (void*)fn_8004E71C, 0xb4, 2);
        if (&p[0x30] != 0) {
            p[0x30] = lbl_8024719C;
        }
        if (&p[0x18] != 0) {
            p[0x18] = lbl_802471C4;
        }
        if (&p[2] != 0) {
            p[2] = lbl_802471EC;
        }
        if (p != 0) {
            p[0] = lbl_80222428;
        }
        if (param_2 > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

