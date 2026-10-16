#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80057614-0x800618fc (176 functions). split_file divides it into the game's real files.

extern void* lbl_8027EC78[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_8005845C(void);
extern "C" void fn_8005867C(void) {
    fn_8005845C();
}

extern "C" void fn_80058740(void*, int);
extern "C" void fn_8005871C(void* p) {
    fn_80058740(p, 0);
}

extern "C" void fn_800595FC(void);
extern "C" void fn_80058D50(void) {
    fn_800595FC();
}

extern "C" void* lbl_802FF118;
extern "C" void* fn_8005C498(void)
{
	return lbl_802FF118;
}

extern "C" void* lbl_802FF11C;
extern "C" void* fn_8005C4A0(void)
{
	return lbl_802FF11C;
}

extern int lbl_802FF128;
extern int lbl_802FF12C;
extern int lbl_802FF130;
extern "C" void fn_8005CAC8(void) {
    lbl_802FF128 = 0;
}

extern "C" void fn_8005CB14(void) {
    if (lbl_802FF130 >= 0x20) {
        return;
    }
    lbl_802FF130++;
}

extern "C" void fn_8005CB2C(int param_1) {
    s32 prev = lbl_802FF12C;
    if (lbl_802FF12C == 0 && param_1 == 0xd4) {
        lbl_802FF12C = 1;
    } else if (lbl_802FF12C != 0 && param_1 == 0xd3) {
        lbl_802FF12C = 0;
    }
    if (lbl_802FF12C != prev) {
        lbl_802FF130 = 1;
    }
}

extern "C" void* fn_8005E7D8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EC78;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_8005F864(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern void* lbl_8027EB8C[];
extern void* lbl_80299A8C[];
extern "C" void* fn_80061490(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EB8C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027EBC4[];
extern "C" void* fn_800614EC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EBC4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027EBFC[];
extern "C" void* fn_80061548(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EBFC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027EC40[];
extern "C" void* fn_800615A4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EC40;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ECA4[];
extern "C" void* fn_80061678(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ECA4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ECCC[];
extern "C" void* fn_800616D4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ECCC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ECF4[];
extern "C" void* fn_80061730(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ECF4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ED20[];
extern "C" void* fn_8006178C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ED20;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ED48[];
extern "C" void* fn_800617E8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ED48;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ED74[];
extern "C" void* fn_80061844(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ED74;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027EDA0[];
extern "C" void* fn_800618A0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EDA0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

