#include "types.h"
extern void* lbl_80299E10[];

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80192e40-0x80196184 (91 functions). split_file divides it into the game's real files.

extern void* lbl_80299E38[];
extern "C" void fn_8015AB1C(void* ptr);
extern void* lbl_80299A78[];
extern void* lbl_80299A8C[];
extern "C" void* fn_80192F60(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_80192FD4(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80193CE0(u32* p)
{
    extern u32 lbl_802FF6B0;
    extern u32 lbl_802FFA80;
    extern u8 lbl_802EE618[];
    extern u32 OSDisableInterrupts(void);
    extern void fn_801DFFF0(void*, u32, u32);
    u32 tmp = p[0];
    p[0] = p[1];
    p[1] = tmp;
    lbl_802FF6B0 = OSDisableInterrupts();
    fn_801DFFF0(lbl_802EE618, p[0], p[3]);
    lbl_802FFA80 = (u32)lbl_802EE618;
}

extern "C" void fn_80193D9C(u32* p)
{
    extern u32 lbl_802FF6B0;
    extern u32 lbl_802FFA80;
    extern u8 lbl_802EE618[];
    extern u32 OSDisableInterrupts(void);
    extern void fn_801DFFF0(void*, u32, u32);
    u32 tmp = p[0];
    p[0] = p[1];
    p[1] = tmp;
    lbl_802FF6B0 = OSDisableInterrupts();
    fn_801DFFF0(lbl_802EE618, p[0], p[3]);
    lbl_802FFA80 = (u32)lbl_802EE618;
}

extern "C" BOOL fn_80193E38(void);
extern "C" BOOL fn_80193E38(void)
{
    return TRUE;
}

extern "C" void* fn_80193E60(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299A78;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* lbl_80299A64[];
extern "C" void* fn_80194084(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299A64;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A78;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80299A8C;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* lbl_80299A2C[];
extern "C" void* fn_801942E4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299A2C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A78;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80299A8C;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80299CF8[];
extern "C" void* fn_80195EB8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299CF8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299E10;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80299E38;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80299D50[];
extern "C" void* fn_80195F3C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299D50;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299E10;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80299E38;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_80195FA8(void) { return 0x534D4242; }

extern void* lbl_80299DA8[];
extern "C" void* fn_80195FB4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299DA8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299E10;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80299E38;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u16 fn_8019602C(u8* p) { return *(u16*)(p + 8); }

extern "C" u16 fn_80196034(u8* p, u16 idx) { return ((u16*)*(void**)(p + 0xC))[idx]; }

extern void* lbl_80299DF0[];
extern "C" void* fn_80196048(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299DF0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299E38;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u16 fn_801960B0(u8* p) { return *(u16*)(p + 8); }

extern void* lbl_80299E10[];
extern "C" void* fn_801960C8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299E10;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299E38;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_80196124(void) { return 0x534D4356; }

extern "C" void* fn_80196130(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299E38;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
