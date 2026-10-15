#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8003a944-0x80041b7c (90 functions). split_file divides it into the game's real files.

extern void* lbl_802469E8[];
extern void* lbl_80246AF4;
extern void* lbl_80246B28;
extern void* lbl_80299A8C;
extern "C" void* fn_801E0D40(void* dst, void* src, s16 size, s16 count);
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8003CC2C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

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
    void* obj1 = lbl_802BF0E8[1];
    if (obj1 != nullptr) {
        void** vtable = *(void***)obj1;
        void (*dtor)(void*, s16) = (void (*)(void*, s16))vtable[4];
        dtor(obj1, 1);
    }
    lbl_802BF0E8[1] = nullptr;
    
    void* obj2 = lbl_802BF0E8[2];
    if (obj2 != nullptr) {
        void** vtable = *(void***)obj2;
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
