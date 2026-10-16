#include "types.h"
struct Entry_802C67C4 { s32 unk0; s32 id; u8 pad[0x18]; };
struct Slot_8013D1D4 { u8 pad[0x10]; void* ptr; };

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8013dd14-0x8013e0ec (9 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80133414(void*, int);
extern char lbl_802935B0[];
extern "C" void* fn_8013DD14(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_802935B0;
        fn_80133414(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern Entry_802C67C4 lbl_802C688C[];
extern u32 lbl_802FF378;
extern "C" void fn_8013DEBC(void* param_1) {
    Entry_802C67C4* e;
    s32 id;
    for (e = lbl_802C688C; (id = e->id) != -1; e++) {
        Slot_8013D1D4* s = (Slot_8013D1D4*)((u8*)*(void**)((u8*)param_1 + 4) + id * 0x14);
        void* p = e ? (void*)e : (void*)&lbl_802FF378;
        s->ptr = p;
    }
}

