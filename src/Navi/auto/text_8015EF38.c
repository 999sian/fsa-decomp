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
extern "C" void* fn_8015EF38(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8015F228(void) {
    fn_8015F400();
}

extern "C" void fn_80166B58(void*, void*);
extern "C" void fn_801BDDBC(void*, void*, int);
extern "C" void fn_80159C6C(void*, int);
extern "C" void fn_80166B70(void*, int);
extern "C" void fn_801BDE1C(void*, void*, int);
extern "C" void fn_80166650(void*);
extern "C" void* fn_8015F520(void* param_1) {
    u32 p = (u32)param_1;
    fn_80166B58((void*)(p + 0x20), (void*)p);
    fn_80166B58((void*)(p + 0x30), (void*)p);
    fn_801BDDBC((void*)(p + 0x68), (void*)(p + 0x88), 1);
    *(u32*)(p + 0x58) = 0;
    *(u32*)(p + 0x5c) = 0;
    *(u32*)(p + 0x60) = 0;
    *(u32*)(p + 0x8c) = 0;
    *(u32*)(p + 0x90) = 0;
    *(u32*)(p + 0x94) = 0;
    return (void*)p;
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

