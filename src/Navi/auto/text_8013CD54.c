#include "types.h"
struct NaviTracker {
    virtual void fn_0();
    virtual void fn_1();
    virtual void fn_2();
    virtual void fn_3(s32);
    virtual u32 fn_4();
    virtual void fn_5(u32);
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
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8013cd54-0x8013d9a4 (28 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80133414(void*, int);
extern char lbl_80293318[];
extern char lbl_80201E80[];
extern "C" void fn_8013BC94(void*, void*, void*, void*, void*);
extern "C" void fn_8013D5DC(void*, void*);
extern "C" void fn_8013D7E0(void*, void*);
struct Entry_802C67C4 { s32 unk0; s32 id; u8 pad[0x18]; };
extern Entry_802C67C4 lbl_802C67C4[];
extern u32 lbl_802FF378;
struct Slot_8013D1D4 { u8 pad[0x10]; void* ptr; };
struct VObj_8013CD54 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vfA();
    virtual void vfB();
    virtual void vfC();
    virtual void vfD();
    virtual void vfE(void*);
};
struct VObj_8013D304 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual u32 vf4();
    virtual void vf5(u32);
};
struct VObj_8013D488 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9(u32, s32);
};
extern "C" void* fn_8013CD6C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80293318;
        fn_80133414(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern void* lbl_802933B4[];
extern "C" void* fn_8013414C(void* ptr, s16 param_2);
extern "C" void* fn_8013CE9C(void* ptr, s16 param_2) {
    if (ptr) {
        *(void**)ptr = lbl_802933B4;
        ((NaviTracker*)ptr)->fn_3(0);
        fn_8013414C(ptr, 0);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8013CF14(void) {
}

extern "C" void fn_801336CC(void* param_1, void* param_2, void* param_3);
extern "C" void fn_8013CF18(void* param_1) {
    void* o = *(void**)((u8*)param_1 + 0x60);
    ((NaviTracker*)o)->fn_5(((NaviTracker*)o)->fn_4() | 1);
    o = *(void**)((u8*)param_1 + 0x60);
    u32 local = ((u32 (*)(void*))(*(void***)o)[15])(o);
    fn_801336CC(param_1, lbl_80201E80, &local);
}

extern "C" void fn_8013CFA4(void* param_1) {
    VObj_8013D304* o = *(VObj_8013D304**)((u8*)param_1 + 0x60);
    o->vf5(o->vf4() & 0xfffffffe);
}

extern "C" void fn_801337AC(void* param_1, void* param_2, void* param_3);
extern "C" void fn_8013CFF8(void* param_1) {
    void* local;
    void* local2;
    fn_801337AC(param_1, &local, lbl_80201E80);
    local2 = local;
    (*(VObj_8013CD54**)((u8*)param_1 + 0x60))->vfE(&local2);
    (*(VObj_8013CD54**)((u8*)param_1 + 0x60))->vf3();
}

extern "C" void fn_8013D064(void* param_1, void* param_2, void* param_3, void* param_4, void* param_5, void* param_6) {
    fn_8013BC94(*(void**)((u8*)param_1 + 0x60), param_3, param_4, param_5, param_6);
}

extern char lbl_802934A8[];
extern "C" void fn_801343E4(void* ptr, s32 param_2);
extern "C" void* fn_8013BD28(void* a, void* b);
extern "C" void fn_801336CC(void* a, void* b, void* c);
extern "C" void* fn_8013D15C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802934A8;
        ((NaviTracker*)ptr)->fn_3(0);
        fn_801343E4(ptr, 0);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8013D1D4(void* param_1) {
    Entry_802C67C4* e;
    s32 id;
    for (e = lbl_802C67C4; (id = e->id) != -1; e++) {
        Slot_8013D1D4* s = (Slot_8013D1D4*)((u8*)*(void**)((u8*)param_1 + 4) + id * 0x14);
        void* p = e ? (void*)e : (void*)&lbl_802FF378;
        s->ptr = p;
    }
}

extern "C" void fn_8013D304(void* param_1) {
    VObj_8013D304* o = *(VObj_8013D304**)((u8*)param_1 + 0x100);
    o->vf5(o->vf4() & 0xfffffffe);
}

extern "C" void fn_8013D358(void* param_1, void* param_2) {
    void* v;
    v = *(void**)((u8*)param_2 + 0x14);
    fn_8013D5DC(param_1, v);
    fn_8013D7E0(param_1, v);
    (*(VObj_8013D304**)((u8*)param_1 + 0x100))->vf3();
}

extern "C" void fn_8013D3B4(void* param_1, void* param_2, void* param_3, void* param_4, void* param_5, void* param_6) {
    fn_8013BC94(*(void**)((u8*)param_1 + 0x100), param_3, param_4, param_5, param_6);
}

extern "C" void* fn_8013BCDC(void* param_1, void* param_2);
extern "C" void fn_8013D3E8(void* param_1, s32 param_2, void* param_3) {
    switch (param_2) {
    case 0x18:
        *(void**)((u8*)param_1 + 0x108) = fn_8013BCDC(*(void**)((u8*)param_1 + 0xfc), param_3);
        break;
    }
}

extern "C" void fn_8013D42C(void* param_1, s32 param_2, u32* param_3) {
    switch (param_2) {
    case 0x18:
        *(void**)((u8*)param_1 + 0x10c) = fn_8013BD28(*(void**)((u8*)param_1 + 0x108), param_3);
        break;
    case 0x19:
        *(u32*)((u8*)param_1 + 0x10c) = *param_3;
        break;
    }
}

extern "C" void fn_8013D488(void* param_1, s32 param_2, u32* param_3) {
    switch (param_2) {
    case 2: {
        u8 b = (u8)((0 - *param_3 | *param_3) >> 31);
        *(u8*)((u8*)param_1 + 0x110) = b;
        switch (*(s32*)((u8*)param_1 + 0x104)) {
        case 1: {
            u32 a = 0;
            s32 c = -1;
            if (*(u8*)((u8*)param_1 + 0x110) != 0) {
                a = *(u32*)((u8*)param_1 + 0x108);
                c = *(s32*)((u8*)param_1 + 0x10c);
            }
            (*(VObj_8013D488**)((u8*)param_1 + 0x100))->vf9(a, c);
            break;
        }
        case 0:
            break;
        }
        break;
    }
    }
}

extern "C" void fn_8013D508(void* param_1, s32 param_2, u32* param_3) {
    if (param_2 != 2) {
        return;
    }
    *(u32*)((u8*)param_1 + 0x104) = *param_3;
}

