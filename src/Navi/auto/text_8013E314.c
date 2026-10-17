#include "types.h"
#include "types.h"

struct VObj_8013E314 {
    virtual void fn_0();
    virtual void fn_1();
    virtual void fn_2();
    virtual void fn_3(s32);
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
    virtual void fn_14(s32);
};
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8013e314-0x8013eb20 (13 functions). split_file divides it into the game's real files.

struct PmfObj_8013E374;
typedef void (PmfObj_8013E374::*PmfFunc_8013E374)();

extern "C" void fn_8013BC94(void*, void*, void*, void*, void*);
extern "C" void fn_8013CD54(void*);
extern "C" void fn_801E0DB8(void*, void*, void*, u32, u32);
extern void* lbl_8029260C[];
extern void* lbl_802922F4[];
extern void* lbl_8029383C[];

inline void* operator new(unsigned long, void* p) { return p; }
struct Elem_8013E3A4 {
    u8 data[0x14];
};
struct Base_8013E3A4 {
    void* vtbl;
    Elem_8013E3A4* items;
    s32 count;
    Base_8013E3A4(Elem_8013E3A4* p, s32 n) {
        vtbl = lbl_8029260C;
        items = p;
        count = n;
    }
};
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80133414(void*, int);
extern char lbl_80293738[];
extern "C" void* fn_8013E314(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80293738;
        fn_80133414(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8013E374(void* param_1, void* param_2) {
    PmfFunc_8013E374* pmf = (PmfFunc_8013E374*)((u8*)param_1 + 8);
    (((PmfObj_8013E374*)*(void**)((u8*)param_2 + 0x88))->*(*pmf))();
}

extern "C" void* fn_8013E3A4(u32* self, u32 param_2, u32 param_3) {
    *(void**)self = lbl_8029260C;
    self[1] = (u32)(self + 3);
    self[2] = 0xd;
    *(void**)self = lbl_802922F4;
    fn_801E0DB8(self + 3, (void*)fn_8013CD54, 0, 0x14, 0xd);
    *(void**)self = lbl_8029383C;
    self[0x44] = param_2;
    self[0x45] = param_3;
    self[0x46] = 0;
    return self;
}

extern "C" void* fn_80134B3C(void* ptr, s16 param_2);
extern "C" void* fn_8013E44C(void* ptr, s16 param_2) {
    if (ptr) {
        *(void**)ptr = lbl_8029383C;
        ((VObj_8013E314*)ptr)->fn_3(0);
        fn_80134B3C(ptr, 0);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8013E9E4(void* param_1, void* param_2, void* param_3, void* param_4, void* param_5, void* param_6) {
    fn_8013BC94(*(void**)((u8*)param_1 + 0x114), param_3, param_4, param_5, param_6);
}

struct PmfObj_8013E374;
typedef void (PmfObj_8013E374::*PmfFunc_8013E374)();
extern "C" void fn_8013BC94(void*, void*, void*, void*, void*);
extern "C" void fn_8013BD54(void*);
extern "C" void fn_8013EA90(void* param_1) {
    fn_8013BD54(*(void**)((u8*)param_1 + 0x114));
}

extern "C" void fn_8013EAB4(void* param_1, void* param_2) {
    *(u32*)((u8*)param_2 + 0x118) = *(u32*)((u8*)param_1 + 8);
}

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80133414(void*, int);
extern char lbl_802937C0[];
extern "C" void* fn_8013EAC0(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_802937C0;
        fn_80133414(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}