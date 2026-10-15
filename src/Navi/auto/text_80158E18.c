#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80158e18-0x8015db8c (138 functions). split_file divides it into the game's real files.

extern void* lbl_8029796C[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80159DB4(void);
extern u32 lbl_802FF540;
extern "C" u32 fn_80159B94(u32 param_1) {
    u32 old = lbl_802FF540;
    lbl_802FF540 = param_1;
    return old;
}

extern u32 lbl_802FF544;
extern "C" u32 fn_80159BA4(u32 param_1) {
    u32 old = lbl_802FF544;
    lbl_802FF544 = param_1;
    return old;
}

extern "C" void fn_80159C6C(void*, int);
extern "C" void fn_8015AB40(void* p) {
    fn_80159C6C(p, 0);
}

extern "C" void fn_8015AB80(void) {
}

extern "C" int fn_8015AB94(int* p, int v) {
    return (unsigned int)((v - *p) | (*p - v)) >> 31;
}

extern "C" void fn_8015ABB4(char** p) {
    char* q = *(char**)(*p + 0x18);
    if (q != 0) q -= 0xc;
    *p = q;
}

extern "C" void* fn_8015ABD0(void** p) {
    return ((void**)*p)[3];
}

extern "C" void fn_8015ABDC(void** param_1, void* param_2) {
    *param_1 = param_2;
}

extern "C" void* fn_8015ABE4(void* p) {
    return ((void**)p)[2];
}

extern "C" void fn_80159AE4(char** start, int* size, void* arg);
extern "C" char* fn_8015ADE8(char* base, char* data, int size, int flag, void* arg);
extern "C" char* lbl_802FF548;
extern char* lbl_802FF548;
extern "C" char* fn_8015AC00(void* arg, void* arg2) {
    char* p = 0;
    if (lbl_802FF548 == 0) {
        char* start;
        int size;
        fn_80159AE4(&start, &size, arg);
        char* base = start;
        char* data = base + 0x90;
        int len = size - 0x90;
        if (base != 0) {
            base = fn_8015ADE8(base, data, len, 0, arg2);
        }
        p = base;
        lbl_802FF548 = p;
    }
    p[0x6e] = 1;
    return p;
}

extern "C" void fn_8015D030(void) {
    fn_80159DB4();
}

extern "C" void* fn_8015DA4C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029796C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
