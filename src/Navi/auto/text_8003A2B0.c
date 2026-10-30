#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8003a2b0-0x8003a908 (8 functions). split_file divides it into the game's real files.

extern void* lbl_80246388[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8003A680(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80246388;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802463B0[];
extern "C" void* fn_8003A6C8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802463B0;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802463DC[];
extern "C" void* fn_8003A710(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802463DC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80246404[];
extern "C" void* fn_8003A758(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80246404;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80246430[];
extern "C" void* fn_8003A7A0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80246430;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80246458[];
extern "C" void* fn_8003A7E8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80246458;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8024635C[];
extern void* lbl_80222428[];
extern "C" void* fn_8003A830(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8024635C;
        if ((s32)ptr + (unsigned)0xac != 0) {
            ((void**)ptr)[0x2b] = lbl_80246388;
        }
        if ((s32)ptr + (unsigned)0x9c != 0) {
            ((void**)ptr)[0x27] = lbl_802463B0;
        }
        if ((s32)ptr + (unsigned)0x68 != 0) {
            ((void**)ptr)[0x1a] = lbl_802463DC;
        }
        if ((s32)ptr + (unsigned)0x38 != 0) {
            ((void**)ptr)[0xe] = lbl_80246404;
        }
        if ((s32)ptr + (unsigned)0x2c != 0) {
            ((void**)ptr)[0xb] = lbl_80246430;
        }
        if ((s32)ptr + (unsigned)0x4 != 0) {
            ((void**)ptr)[1] = lbl_80246458;
        }
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80222428;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

