#include "dolphin/os/OSFastCast.h"
#include "dolphin/os/OSCache.h"
typedef void (*VirtualMethod0)(void*, s16);
typedef void (*DispatchFn)(void*, void*, int, void*, void*);

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015ef38-0x8015f638 (11 functions). split_file divides it into the game's real files.

extern "C" void fn_8015F400(void);
extern "C" void fn_80166B58(void*, void*);
extern "C" void fn_801BDDBC(void*, void*, int);
extern "C" void fn_80159C6C(void*, int);
extern "C" void fn_80166B70(void*, int);
extern "C" void fn_801BDE1C(void*, void*, int);
extern "C" void fn_80166650(void*);
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80166C08(void*, int);
extern "C" void fn_80166FC4(void*, void*);
extern "C" void* fn_8015EF38(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern u8 lbl_80297AB0[];
#pragma push
#pragma use_lmw_stmw off
extern "C" void* fn_8015EF8C(u8* p, u32 a, u32 b, u32 c, u8 d, u8 e) {
    *(void**)p = lbl_80297AB0;
    fn_80166B58(p + 4, p);
    *(u32*)(p + 0x14) = a;
    *(u32*)(p + 0x18) = b;
    *(u32*)(p + 0x1c) = c;
    *(u8*)(p + 0x20) = d;
    *(u8*)(p + 0x21) = e;
    return p;
}
#pragma pop
extern "C" void fn_8015F228(void) {
    fn_8015F400();
}

extern "C" void fn_8015F478(u8* p) {
    if (*(s32*)(p + 0x40) == 1) {
        DCInvalidateRange(*(void**)(p + 0x4c), *(u32*)(p + 0x44));
    }
    if (*(s32*)(p + 0x60) != 0) {
        if (*(s32*)(p + 0x60) == 2) {
            fn_80166650(*(void**)(p + 0x64));
        }
    } else {
        void (*fn)(void*) = *(void (**)(void*))(p + 0x58);
        if (fn) {
            fn(p);
        } else if (*(void**)(p + 0x5c)) {
            fn_801BDE1C(*(void**)(p + 0x5c), p, 0);
        } else {
            fn_801BDE1C(p + 0x68, p, 0);
        }
    }
}

extern "C" void fn_80166B58(void*, void*);
extern "C" void fn_801BDDBC(void*, void*, int);
extern "C" void fn_80159C6C(void*, int);
extern "C" void fn_80166B70(void*, int);
extern "C" void fn_801BDE1C(void*, void*, int);
extern "C" void fn_80166650(void*);
extern "C" u8* fn_8015F520(u8* p) {
    u8* owner;
    owner = p;
    fn_80166B58(&owner[0x20], owner);
    fn_80166B58(p + 0x30, p);
    fn_801BDDBC(p + 0x68, p + 0x88, 1);
    *(u32*)(p + 0x58) = 0;
    *(u32*)(p + 0x5c) = 0;
    *(u32*)(p + 0x60) = 0;
    *(u32*)(p + 0x8c) = 0;
    *(u32*)(p + 0x90) = 0;
    *(u32*)(p + 0x94) = 0;
    return p;
}

extern "C" void* fn_8015F590(u8* p, s16 del) {
    if (p) {
        if (*(void**)(p + 0x8c)) {
            fn_8015AB1C(*(void**)(p + 0x8c));
        }
        if (*(void**)(p + 0x90)) {
            fn_8015AB1C(*(void**)(p + 0x90));
        }
        if (*(void**)(p + 0x94)) {
            fn_80159C6C(*(void**)(p + 0x94), 0);
        }
        if (p + 0x30) {
            fn_80166B70(p + 0x30, 0);
        }
        if (p + 0x20) {
            fn_80166B70(p + 0x20, 0);
        }
        if (del > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

