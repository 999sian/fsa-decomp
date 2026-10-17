#include "dolphin/os/OSFastCast.h"
typedef void (*VirtualMethod0)(void*, s16);
typedef void (*DispatchFn)(void*, void*, int, void*, void*);

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015eabc-0x8015eef4 (8 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80166C08(void*, int);
typedef void (*VirtualMethod0)(void*, s16);
extern "C" void* fn_8015EABC(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" char lbl_80297A94[];
extern "C" void* lbl_802EE28C[];
extern "C" void fn_8015D0B8(void*, int);
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_801BE3A0(void*);
extern "C" void fn_801BE47C(void*);
extern "C" int fn_8015ED10(char* p, u32 size);
extern "C" int fn_8015ED98(char* p, u32 size);
extern "C" int fn_8015F0BC(void* param_1, u32 size, u8 flag, char* p);
extern "C" int fn_8015F16C(void* param_1, u32 size, u8 flag, char* p);
extern "C" void* fn_8015EBE8(void* param_1, s16 param_2) {
    struct Obj {
        virtual void Release(int);
    };
    struct Node {
        Obj* obj;
        u32 unk4;
        u32 unk8;
        Node* next;
    };
    if (param_1) {
        *(void**)param_1 = lbl_80297A94;
        Node* node = (Node*)lbl_802EE28C[0];
        while (node) {
            Node* cur = node;
            node = node->next;
            if (cur->obj) {
                cur->obj->Release(1);
            }
        }
        fn_8015D0B8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" int fn_8015EC90(char* param_1, int param_2, int param_3) {
    int r;
    fn_801BE3A0(param_1 + 0x18);
    if (param_3 == 0) {
        r = fn_8015ED10(param_1, param_2);
    } else {
        r = fn_8015ED98(param_1, param_2);
    }
    fn_801BE47C(param_1 + 0x18);
    return r;
}

extern "C" int fn_8015ED10(char* p, u32 size) {
    char* o;
    char* n;
    u32 aligned = (size + 0x1f) & ~0x1f;
    u32 best = -1;
    char* obj = 0;
    for (n = *(char**)lbl_802EE28C; n != 0; n = *(char**)(n + 0xc)) {
        o = *(char**)n;
        if (*(u32*)(o + 0x1c) >= aligned && best > *(u32*)(o + 0x1c)) {
            best = *(u32*)(o + 0x1c);
            obj = o;
            if (best == aligned) {
                break;
            }
        }
    }
    if (obj != 0) {
        return fn_8015F0BC(obj, aligned, *(u8*)(p + 0x40), p);
    }
    return 0;
}

extern "C" int fn_8015ED98(char* p, u32 size) {
    char* o;
    char* n;
    char* obj = 0;
    u32 aligned = (size + 0x1f) & ~0x1f;
    for (n = *(char**)((char*)lbl_802EE28C + 4); n != 0; n = *(char**)(n + 0x8)) {
        o = *(char**)n;
        if (*(u32*)(o + 0x1c) >= aligned) {
            obj = o;
            break;
        }
    }
    if (obj != 0) {
        return fn_8015F16C(obj, aligned, *(u8*)(p + 0x40), p);
    }
    return 0;
}

extern "C" u32 fn_8015EE10(char* p) {
    char* n;
    u32 max = 0;
    fn_801BE3A0(p + 0x18);
    for (n = (char*)lbl_802EE28C[0]; n != 0; n = *(char**)(n + 0xc)) {
        u32 v = *(u32*)(*(char**)n + 0x1c);
        if (v > max) {
            max = v;
        }
    }
    fn_801BE47C(p + 0x18);
    return max;
}

extern "C" long fn_8015EE88(char* p) {
    char* n;
    long sum = 0;
    fn_801BE3A0(p + 0x18);
    for (n = *(char**)lbl_802EE28C; n != 0; n = *(char**)(n + 0xc)) {
        sum += *(long*)(*(char**)n + 0x1c);
    }
    fn_801BE47C(p + 0x18);
    return sum;
}

