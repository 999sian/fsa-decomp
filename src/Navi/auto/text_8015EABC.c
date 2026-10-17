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
extern "C" int fn_8015ED10(void*, int);
extern "C" int fn_8015ED98(void*, int);
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

