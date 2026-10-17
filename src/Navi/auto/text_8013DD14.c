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
    virtual void fn_20(void*);
    virtual void fn_21();
    virtual void fn_22(void*);
};

struct Entry_802C67C4 { s32 unk0; s32 id; u8 pad[0x18]; };
struct Slot_8013D1D4 { u8 pad[0x10]; void* ptr; };

struct NaviTracker_8013DF04 {
    virtual void fn_0();
    virtual void fn_1();
    virtual void fn_2();
    virtual void fn_3();
    virtual u32 fn_4();
    virtual void fn_5(u32);
    virtual void fn_6();
    virtual void fn_7();
    virtual void fn_8();
    virtual void fn_9();
    virtual void fn_10();
    virtual void fn_11();
    virtual void fn_12();
    virtual void fn_13();
    virtual void fn_14();
    virtual void fn_15();
    virtual void fn_16();
    virtual void fn_17();
    virtual void fn_18();
    virtual void* fn_19();
};
struct Entry_8013DF04 { s32 unk0; s32 id; u8 pad[0xc]; f32 (NaviTracker_8013DF04::*fn)(); };
struct Slot_8013DF04 { u8 pad[4]; s32 unk4; void* func; f32 value; };

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8013dd14-0x8013e0ec (9 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80133414(void*, int);
extern char lbl_802935B0[];
extern char lbl_8029260C[];
extern char lbl_80292398[];
extern char lbl_80201EB4[];
extern "C" void fn_801E0DB8(void*, void*, s32, s32, s32);
extern "C" void fn_8013CD54();
extern "C" void fn_801337AC(void*, void*, void*);
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

extern "C" void fn_801336CC(void*, void*, void*);
extern "C" void fn_8013345C();
extern "C" void fn_8013DF04(void* param_1) {
    NaviTracker_8013DF04* o = *(NaviTracker_8013DF04**)((u8*)param_1 + 0x88);
    void* local;
    Entry_8013DF04* e;
    o->fn_5(o->fn_4() | 1);
    local = (*(NaviTracker_8013DF04**)((u8*)param_1 + 0x88))->fn_19();
    fn_801336CC(param_1, lbl_80201EB4, &local);
    for (e = (Entry_8013DF04*)lbl_802C688C; e->id != -1; e++) {
        f32 v = ((*(NaviTracker_8013DF04**)((u8*)param_1 + 0x88))->*(e->fn))();
        Slot_8013DF04* s = (Slot_8013DF04*)((u8*)*(void**)((u8*)param_1 + 4) + e->id * 0x14);
        s->func = (void*)fn_8013345C;
        s->unk4 = 0;
        s->value = v;
    }
}

extern "C" void fn_801E0DB8(void*, void*, s32, s32, s32);
extern "C" void fn_8013CD54();
extern "C" void fn_801337AC(void*, void*, void*);
extern char lbl_8029260C[];
extern char lbl_80292398[];
extern char lbl_80201EB4[];
extern "C" void fn_8013DFF8(void* param_1) {
    NaviTracker_8013DF04* o = *(NaviTracker_8013DF04**)((u8*)param_1 + 0x88);
    o->fn_5(o->fn_4() & 0xfffffffe);
}

extern "C" void fn_8013E04C(void* param_1) {
    void* local;
    void* local2;
    fn_801337AC(param_1, &local, (void*)lbl_80201EB4);
    local2 = local;
    ((NaviTracker*)*(void**)((u8*)param_1 + 0x88))->fn_20(&local2);
    ((NaviTracker_8013DF04*)*(void**)((u8*)param_1 + 0x88))->fn_3();
}

extern "C" void fn_8013BC94(void*, void*, void*, void*, void*);
extern "C" void fn_8013E0B8(void* param_1, void* param_2, void* param_3, void* param_4, void* param_5, void* param_6) {
    fn_8013BC94(*(void**)((u8*)param_1 + 0x88), param_3, param_4, param_5, param_6);
}

