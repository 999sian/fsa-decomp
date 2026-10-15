#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8001287c-0x80013a30 (29 functions). split_file divides it into the game's real files.

typedef struct ThreadBlock {
    u8 thread[0x320];
    u8 stack[0x1800];
    u8 param[1];
} ThreadBlock;

struct node_class;
void cLs_SingleCut(node_class*);

struct UnkVtbl {
    void* unk0;
    void* unk4;
    void* unk8;
    int (*fnC)();
};

struct UnkObj {
    u8 pad[0x10];
    UnkVtbl* vt;
};

extern "C" void fn_8015AB1C(void*);
extern "C" void* fn_80012970(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" int fn_801C0884(void*, void*, void*, void*, u32, s32, u16);
extern "C" int fn_801C0EEC(void*);
extern "C" void* fn_80012D28(void*);
extern "C" u8 lbl_802A05C0[];
extern "C" void fn_80012D84(s32 prio) {
    fn_801C0884(lbl_802A05C0, (void*)fn_80012D28, lbl_802A05C0 + 0x1b20, lbl_802A05C0 + 0x320 + 0x1800, 0x1800, prio, 1);
    fn_801C0EEC(lbl_802A05C0);
}

extern "C" char lbl_80204E88[];
extern "C" void* fn_80012E08(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)((char*)ptr + 0x10) = lbl_80204E88;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

