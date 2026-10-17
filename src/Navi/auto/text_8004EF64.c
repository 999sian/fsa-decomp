#include "types.h"
#include "types.h"
extern "C" void* fn_8004F67C(void* ptr, s16 param_2);

extern "C" void* fn_8004F50C(void* ptr, s16 param_2);

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8004ef64-0x8004f7c4 (19 functions). split_file divides it into the game's real files.

extern void* lbl_8024745C[];
extern void* lbl_8024763C[];
extern f32 lbl_803001E8;
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8004F154(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8024745C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80247430[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8004F19C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247430;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80247404[];
extern "C" void* fn_8004F1E4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247404;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8024756C[];
extern "C" void* fn_8004F22C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8024756C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80247544[];
extern void* lbl_802474F4[];
extern void* lbl_802474D0[];
extern void* lbl_80247594[];
extern "C" void fn_801E0D40(void* dst, void* fn, s32 size, s32 count);
extern "C" void* fn_8004F154(void* ptr, s16 param_2);
extern "C" void* fn_8004F19C(void* ptr, s16 param_2);
extern "C" void* fn_8004F1E4(void* ptr, s16 param_2);
extern "C" void* fn_8004F5C4(void* ptr, s16 param_2);
extern "C" void* fn_8004F274(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247544;
        fn_801E0D40((char*)ptr + 4, (void*)fn_8004F1E4, 0x30, 0x1d);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8024751C[];
extern "C" void* fn_8004F2E4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8024751C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_8004F32C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802474F4;
        fn_801E0D40((char*)ptr + 4, (void*)fn_8004F19C, 0x1c, 0x1);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_8004F39C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802474D0;
        fn_801E0D40((char*)ptr + 4, (void*)fn_8004F154, 0x24, 0x8);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802474AC[];
extern "C" void* fn_8004F40C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802474AC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80247484[];
extern "C" void* fn_8004F454(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247484;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80247354[];
extern "C" void* fn_8004F49C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247354;
        fn_801E0D40((char*)ptr + 4, (void*)fn_8004F50C, 0x1c, 0x1);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802473D8[];
extern "C" void* fn_8004F50C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802473D8;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_8004F554(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247594;
        fn_801E0D40((char*)ptr + 4, (void*)fn_8004F5C4, 0x1c, 0x8);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802473AC[];
extern "C" void* fn_8004F5C4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802473AC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802475BC[];
extern "C" void* fn_8004F60C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802475BC;
        fn_801E0D40((char*)ptr + 4, (void*)fn_8004F67C, 0x1c, 0x1);
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80247380[];
extern "C" void* fn_8004F67C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247380;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8004F6C4(void* ptr) {
    f32 zero = lbl_803001E8;
    f32* f = (f32*)ptr;
    s16* s = (s16*)ptr;
    *(void**)ptr = lbl_8024763C;
    f[1] = zero;
    f[2] = zero;
    f[3] = zero;
    f[4] = zero;
    f[5] = zero;
    f[6] = zero;
    f[7] = zero;
    f[8] = zero;
    f[9] = zero;
    f[10] = zero;
    f[11] = zero;
    f[12] = zero;
    f[13] = zero;
    f[14] = zero;
    f[15] = zero;
    f[16] = zero;
    f[17] = zero;
    f[18] = zero;
    f[19] = zero;
    f[20] = zero;
    f[21] = zero;
    f[22] = zero;
    f[23] = zero;
    f[24] = zero;
    f[25] = zero;
    f[26] = zero;
    f[27] = zero;
    f[28] = zero;
    f[29] = zero;
    f[30] = zero;
    s[0x3e] = 0;
    s[0x3f] = 0;
    s[0x40] = 0;
    s[0x41] = 0;
    s[0x42] = 0;
    s[0x43] = 0;
    s[0x44] = 0;
    s[0x45] = 0;
    s[0x46] = 0;
    s[0x47] = 0;
}

extern void* lbl_8024763C[];
extern "C" void* fn_8004F77C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8024763C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

