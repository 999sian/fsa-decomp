#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8000d404-0x80012630 (157 functions). split_file divides it into the game's real files.

extern "C" void fn_8000EAE0(void* ptr, u32 value) {
    *(u32*)((char*)ptr + 4) = value;
}

extern void* lbl_80204948[];
extern void* lbl_80204820[];
extern void* lbl_80204720[];
extern void* lbl_8020474C[];
extern "C" void fn_801AF42C(void*, void*);
extern "C" void fn_801AF744(void*);
extern char* lbl_802FF704;
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8000EB44(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204948;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8000EBAC(void) {
}

extern "C" void fn_8000EBB0(void) {
}

extern "C" void fn_8000EBB4(void) {
}

extern "C" void* fn_8000EE0C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_8000EE4C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern void* lbl_80299A8C[];
extern "C" void* fn_8000F388(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299A8C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80159BB4(void);
extern "C" void fn_8000FA24(void) {
    fn_80159BB4();
}

extern "C" float lbl_802FFB68;
extern "C" float lbl_802FFB6C;
extern "C" char lbl_80203B80[];
extern "C" char lbl_8029F0E0[];
extern "C" void* lbl_802FEBB0;
extern "C" void fn_800101A0(volatile float* p) {
    if (p[1] <= lbl_802FFB6C) {
        return;
    }
    p[1] = p[1] - lbl_802FFB68;
    if (p[1] <= lbl_802FFB6C) {
        p[1] = lbl_802FFB6C;
        p[2] = lbl_802FFB6C;
        p[3] = lbl_802FFB6C;
        float t = p[4];
        p[5] = t;
        p[4] = p[1] * p[2];
        float u = p[5];
        if (u > lbl_802FFB6C) {
            p[3] = lbl_802FFB68 - (u - p[4]) / u;
        } else {
            p[3] = lbl_802FFB6C;
        }
    }
}

extern void* lbl_80204984[];
extern "C" void* fn_80010224(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204984;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* lbl_80204720[];
extern "C" void* lbl_8020474C[];
extern "C" void* lbl_80204948[];
extern "C" void* fn_8001026C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204720;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8020474C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80204948;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8020474C[];
extern "C" void* fn_800102D8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8020474C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80204948;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* lbl_802046F4[];
extern "C" void* lbl_80204984[];
extern "C" void* fn_80010428(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802046F4;
        if ((char*)ptr + (unsigned)0xC != nullptr) {
            *(void**)((char*)ptr + 0xC) = lbl_80204984;
        }
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80204720;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8020474C;
                if (ptr != nullptr) {
                    *(void**)ptr = lbl_80204948;
                }
            }
        }
        if (0 < param_2) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80204470[];
extern "C" void* fn_80011DF8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204470;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802044AC[];
extern "C" void* fn_80011E54(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802044AC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80204598[];
extern "C" void* fn_80011EC0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204598;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802045D4[];
extern "C" void* fn_80011F1C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802045D4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_800120A4(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" void fn_800120AC(void* ptr, u32 value) {
    *(u32*)((char*)ptr + 4) = value;
}

extern "C" void* lbl_802048F0[];
extern "C" void* lbl_8020491C[];
extern "C" void* fn_800120B4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802048F0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8020491C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80204948;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* lbl_80204820[];
extern "C" void fn_801AF42C(void*, void*);
extern "C" void fn_801AF744(void*);
extern "C" char* lbl_802FF704;
extern "C" void fn_80012170(void) {
    fn_801AF744(lbl_802FF704 + 0x18);
}

