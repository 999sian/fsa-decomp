#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8003a944-0x80041b7c (90 functions). split_file divides it into the game's real files.

extern void* lbl_802469E8[];
extern void* lbl_80246AF4[];
extern void* lbl_80246B28[];
extern void* lbl_80246ABC[];
extern void* lbl_80246A88[];
extern void* lbl_80246A20[];
extern void* lbl_80246A54[];
extern void* lbl_80299A8C[];
extern void* lbl_802BF110[];
extern s64 lbl_802FFEC8;
extern s16 lbl_802FEFB4[];
extern "C" void* fn_801E0D40(void* dst, void* src, s16 size, s16 count);
extern "C" void fn_8000CEC4(void);
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8003CC2C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8003CC68(void) {}

extern "C" void* fn_8003CCB4(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_8003CD98(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_8003CE80(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80040120(void) {
    extern void* lbl_802BF0E8[];
    register void* obj1 = lbl_802BF0E8[1];
    if (obj1 != nullptr) {
        register void** vtable = *(void***)obj1;
        void (*dtor)(void*, s16) = (void (*)(void*, s16))vtable[4];
        dtor(obj1, 1);
    }
    lbl_802BF0E8[1] = nullptr;
    
    register void* obj2 = lbl_802BF0E8[2];
    if (obj2 != nullptr) {
        register void** vtable = *(void***)obj2;
        void (*dtor)(void*, s16) = (void (*)(void*, s16))vtable[4];
        dtor(obj2, 1);
    }
    lbl_802BF0E8[2] = nullptr;
}

extern "C" void* fn_80040628(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_80041B34(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802469E8;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_800401AC(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80246AF4;
        fn_801E0D40((char*)param_1 + 0x20, &fn_8000CEC4, 0xc, 0x8);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_80040230(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80246B28;
        fn_801E0D40((char*)param_1 + 0x10, &fn_8000CEC4, 0xc, 0x2);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_800402B4(void) {
    extern void* lbl_802BF110[];
    if (lbl_802BF110[2] != nullptr) {
        void (*dtor)(void*, s16) = (void (*)(void*, s16))(*(void**)(*(void***)lbl_802BF110[2] + 4));
        dtor(lbl_802BF110[2], 1);
    }
    lbl_802BF110[2] = nullptr;
}

extern "C" void* fn_80040308(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80246ABC;
        fn_801E0D40((char*)param_1 + 0x18, &fn_8003CC2C, 0x38, 0x64);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_8004038C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80246A88;
        fn_801E0D40((char*)param_1 + 0x14, &fn_8003CCB4, 0x38, 0x64);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_80040464(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80246A20;
        fn_801E0D40((char*)param_1 + 0x18, &fn_8003CE80, 0x38, 0x96);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_800404E8(void) {
    extern void* lbl_802BF0F4[];
    if (lbl_802BF0F4[3] != nullptr) {
        register void** vtable = *(void***)lbl_802BF0F4[3];
        void (*fn)(void*, s16) = (void (*)(void*, s16))vtable[4];
        fn(lbl_802BF0F4[3], 1);
    }
    lbl_802BF0F4[3] = nullptr;
}

extern "C" void* fn_8004053C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80246A54;
        fn_801E0D40((char*)param_1 + 0x20, &fn_8003CD98, 0x2c, 0x64);
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_800405C0(void) {
    extern void* lbl_802BF128[];
    void* obj = lbl_802BF128[2];
    if (obj != nullptr) {
        fn_801E0D40(obj, &fn_80040628, 0x34, 0x1e);
        fn_8015AB1C(obj);
    }
    lbl_802BF128[2] = nullptr;
}

extern "C" void fn_8003FBA4(s16 param_1, s16 param_2, s16 param_3, f32 factor) {
    volatile union {
        s64 i;
        double d;
    } temp;
    
    double dconst = *(double*)&lbl_802FFEC8;
    
    temp.i = 0x4330000000000000LL | ((s32)param_1 ^ 0x80000000);
    double d1 = temp.d - dconst;
    d1 *= (double)factor;
    
    temp.i = 0x4330000000000000LL | ((s32)param_2 ^ 0x80000000);
    double d2 = temp.d - dconst;
    d2 *= (double)factor;
    
    temp.i = 0x4330000000000000LL | ((s32)param_3 ^ 0x80000000);
    double d3 = temp.d - dconst;
    d3 *= (double)factor;
    
    lbl_802FEFB4[0] = (s16)(s32)d1;
    lbl_802FEFB4[1] = (s16)(s32)d2;
    lbl_802FEFB4[2] = (s16)(s32)d3;
}
