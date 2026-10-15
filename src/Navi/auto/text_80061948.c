#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80061948-0x8006cfd8 (186 functions). split_file divides it into the game's real files.

extern void* lbl_8027F1FC[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80062E28(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_80062E7C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_80062ED0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027F1FC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80062F3C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_80062F90(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern void* lbl_8027F214[];
extern "C" void* fn_80063BA4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027F214;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800641AC(void);
extern "C" void fn_80064100(void) {
    fn_800641AC();
}

extern void* lbl_8027F6DC[];
extern "C" void* fn_800643E8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027F6DC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027F6D0[];
extern "C" void* fn_80064BE4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027F6D0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F6DC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027FB48[];
extern "C" void* fn_80064CBC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027FB48;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F6DC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027FB70[];
extern "C" void* fn_80064D40(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027FB70;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F6DC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80064FB0(void);
extern "C" void fn_80064DEC(void) {
    fn_80064FB0();
}

extern "C" void fn_80064E0C(void);
extern "C" void fn_80066B88(void) {
    fn_80064E0C();
}

extern "C" void fn_80066748(void);
extern "C" void fn_80066C5C(void) {
    fn_80066748();
}

extern "C" void fn_80065DC4(void);
extern "C" void fn_80066C7C(void) {
    fn_80065DC4();
}

extern void* lbl_8027FBE0[];
extern "C" void* fn_80066CA4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027FBE0;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80066DBC(void);
extern "C" void fn_80066D04(void) {
    fn_80066DBC();
}

extern "C" void fn_80066D24(void);
extern "C" void fn_80067BE4(void) {
    fn_80066D24();
}

extern "C" void fn_80067564(void);
extern "C" void fn_80067C54(void) {
    fn_80067564();
}

extern void* lbl_8027FCA8[];
extern "C" void* fn_80067DDC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027FCA8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F6DC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027FCD0[];
extern "C" void* fn_80067E38(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027FCD0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F6DC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027FDCC[];
extern "C" void* fn_80067F8C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027FDCC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F6DC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_800680A4(void);
extern "C" void fn_80067FE8(void) {
    fn_800680A4();
}

extern "C" void fn_80068008(void);
extern "C" void fn_80068804(void) {
    fn_80068008();
}

extern "C" void fn_80068B30(void);
extern "C" void fn_80068B10(void) {
    fn_80068B30();
}

