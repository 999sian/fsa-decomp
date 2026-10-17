#include "types.h"
struct NaviTracker {
    virtual void fn_0();
    virtual void fn_1();
    virtual void fn_2();
    virtual void fn_3(s32);
    virtual u32 fn_4();
    virtual void fn_5();
    virtual u32 fn_6();
    virtual void fn_7(u32);
    virtual void fn_8();
    virtual void fn_9();
    virtual void fn_10();
    virtual void fn_11();
    virtual void fn_12();
    virtual s32 fn_13(u32*, u32, s32);
    virtual void fn_14();
    virtual s32 fn_15(u32*, u32, s32);
    virtual void fn_16();
    virtual void fn_17();
    virtual void fn_18();
    virtual void fn_19();
    virtual void fn_20();
    virtual void fn_21();
    virtual void fn_22(void*);
};

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

extern "C" void fn_801E10DC(void*);
extern "C" void fn_8013DD74(void* param_1, void* param_2) {
    void* p = (u8*)param_1 + 8;
    fn_801E10DC(*(void**)((u8*)param_2 + 0x100));
}

extern void* lbl_8029366C[];
extern "C" void* fn_80134898(void* ptr, s16 param_2);
extern "C" void* fn_8013DE44(void* ptr, s16 param_2) {
    if (ptr) {
        *(void**)ptr = lbl_8029366C;
        ((NaviTracker*)ptr)->fn_3(0);
        fn_80134898(ptr, 0);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
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

extern "C" void fn_8013BC94(void*, void*, void*, void*, void*);
extern "C" void fn_8013E0B8(void* param_1, void* param_2, void* param_3, void* param_4, void* param_5, void* param_6) {
    fn_8013BC94(*(void**)((u8*)param_1 + 0x88), param_3, param_4, param_5, param_6);
}

