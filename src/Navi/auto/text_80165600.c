#include "dolphin/os/OSFastCast.h"
#include "types.h"
typedef void (*VirtualMethod0)(void*, s16);
typedef void (*DispatchFn)(void*, void*, int, void*, void*);

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80165600-0x801663e0 (14 functions). split_file divides it into the game's real files.

extern "C" void fn_80164484(void* p);
extern "C" u8 fn_80164728(u8* p, u32 r4);
extern "C" void fn_801645A8(void* p, s32 n);
extern "C" void fn_80165C24(void* p, s32 n);
extern "C" void fn_80165D44(void* p, s32 n);
extern "C" void fn_8015F248(s32 a, u32 b, u32 c, u32 d, s32 e);
extern "C" s32 fn_801656F8(void* a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern "C" void* fn_8016579C(void* a, void* b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern u32 lbl_802FF654;
extern u32 lbl_802FF65C;
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80166C08(void*, int);
typedef void (*VirtualMethod0)(void*, s16);
extern "C" void* fn_80165600(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_8015A9A8(int, void*, int);
extern "C" void* lbl_802FF540;
extern "C" void* fn_80165D04(void* p);
extern "C" s32 fn_80165850(void* p);
extern "C" void fn_80165D44(void* p, s32 n);
extern "C" void fn_80164484(void* p);
extern "C" u8 fn_80164728(u8* p, u32 r4);
extern "C" void fn_801645A8(void* p, s32 n);
extern "C" void fn_80165C24(void* p, s32 n);
extern "C" void fn_8015F248(s32 a, u32 b, u32 c, u32 d, s32 e);
extern "C" s32 fn_801656F8(void* a, u32 b, u32 c, u32 d, u32 e, u32 f);
extern "C" void* fn_8016579C(void* a, void* b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern u32 lbl_802FF654;
extern u32 lbl_802FF65C;
#pragma push
#pragma use_lmw_stmw off
extern "C" void* fn_8016579C(void* a, void* b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    void* p = fn_8015A9A8(0x54, lbl_802FF540, -4);
    if (p != nullptr) {
        p = fn_80165D04(p);
        *(void**)((u8*)p + 0x28) = a;
        *(void**)((u8*)p + 0x2c) = b;
        *(u32*)((u8*)p + 0x30) = 0;
        *(u32*)((u8*)p + 0x34) = c;
        *(u32*)((u8*)p + 0x38) = d;
        *(u32*)((u8*)p + 0x3c) = e;
        *(u32*)((u8*)p + 0x40) = f;
        *(u32*)((u8*)p + 0x44) = g;
        if (fn_80165850(p) == 0) {
            fn_80165D44(p, 1);
            return nullptr;
        }
    }
    return p;
}
#pragma pop
extern char lbl_8029836C[];
extern "C" void fn_80167074(void*, int);
extern char lbl_802984EC[];
extern "C" void* fn_80165BB4(void** param_1, s16 param_2) {
    if (param_1 != nullptr) {
        param_1[0] = (void*)lbl_802984EC;
        if (param_1 != nullptr) {
            param_1[0] = (void*)lbl_8029836C;
            fn_80167074(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" s32 fn_80166378(u32 a) {
    s32 size;
    if (lbl_802FF65C == lbl_802FF654) {
        return 0;
    }
    size = (lbl_802FF65C - lbl_802FF654 + 0x1f) & ~0x1f;
    fn_8015F248(0, lbl_802FF654, a, size, 0);
    lbl_802FF65C = lbl_802FF654;
    return size;
}

