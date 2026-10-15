#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80041c10-0x8004dcf8 (82 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void* fn_80041C10(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_80041C4C(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8004A37C(void) {
}

extern "C" void fn_801303BC(void*, int);
extern "C" void fn_8003E748(void);
extern char lbl_80246FDC[];
extern char lbl_80247000[];
extern u32 lbl_802FF0C8;
extern char lbl_802BF42C[];
extern u8 lbl_802BF110;
extern u8 lbl_802BF104;
extern u8 lbl_802BF0F4;
extern u8 lbl_802BF0E8;
extern u8 lbl_802BF188;
extern char lbl_802BF134[];
extern f32 lbl_8030011C;
extern "C" void* fn_8004AF1C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80247000;
        fn_801303BC(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8004B070(void) {
}

extern "C" void fn_8004B074(void* param_1, void* param_2, void* param_3, void* param_4) {
    void* vtable = *(void**)param_1;
    (*(void(**)(void))((char*)vtable + 0x20))();
    
    if (*(u8*)((char*)param_1 + 0x13) == 0) {
        *(void**)((char*)param_1 + 0x4) = param_2;
        *(u32*)((char*)param_2 + 0xf4) = *(u32*)((char*)param_2 + 0xf4) | 0x40;
    }
    if (*(u8*)((char*)param_1 + 0x12) == 0) {
        if (*(u8*)((char*)param_1 + 0x11) != 0) {
            *(u32*)((char*)param_2 + 0x24) = 0x0;
        }
        *(void**)((char*)param_1 + 0x8) = param_3;
        *(void**)((char*)param_1 + 0xc) = param_4;
        *(u8*)((char*)param_1 + 0x10) = 0x0;
    }
}

extern "C" void fn_8004B11C(void* param_1) {
    void* obj = *(void**)((char*)param_1 + 0x4);
    if (obj == nullptr) {
        return;
    }
    *(u32*)((char*)obj + 0xf4) = *(u32*)((char*)obj + 0xf4) | 0x1;
    *(u32*)((char*)obj + 0x24) = 0x1;
    
    obj = *(void**)((char*)param_1 + 0x4);
    *(u32*)((char*)obj + 0xf4) = *(u32*)((char*)obj + 0xf4) & 0xffffffbf;
    
    obj = *(void**)((char*)param_1 + 0x4);
    *(u32*)((char*)obj + 0xec) = 0x0;
    
    *(u8*)((char*)param_1 + 0x10) = *(u8*)((char*)param_1 + 0x10) | 0x1;
    *(void**)((char*)param_1 + 0x4) = nullptr;
}

extern "C" void* fn_8004B16C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80246FDC;
        *(void**)param_1 = (void*)lbl_80247000;
        fn_801303BC(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8004B1DC(void* param_1, void* param_2, void* param_3, void* param_4) {
    void* vtable = *(void**)param_1;
    (*(void(**)(void))((char*)vtable + 0x20))();
    
    if (*(u8*)((char*)param_1 + 0x13) == 0) {
        *(void**)((char*)param_1 + 0x4) = param_2;
        *(u32*)((char*)param_2 + 0xf4) = *(u32*)((char*)param_2 + 0xf4) | 0x40;
    }
    if (*(u8*)((char*)param_1 + 0x12) == 0) {
        if (*(u8*)((char*)param_1 + 0x11) != 0) {
            *(u32*)((char*)param_2 + 0x24) = 0x0;
        }
        *(void**)((char*)param_1 + 0x8) = param_3;
        *(void**)((char*)param_1 + 0xc) = param_4;
        *(u8*)((char*)param_1 + 0x10) = 0x0;
    }
    *(u8*)((char*)param_2 + 0x110) = 0x2;
    *(u32*)((char*)param_2 + 0xf0) = (u32)&lbl_802FF0C8;
    *(u32*)((char*)param_2 + 0xc0) = *(u8*)((char*)param_1 + 0x14);
}

extern "C" void fn_8004B854(void* param_1) {
    void* obj = *(void**)((char*)param_1 + 0x4);
    if (obj == nullptr) {
        return;
    }
    *(u32*)((char*)obj + 0xf4) = *(u32*)((char*)obj + 0xf4) | 0x1;
    *(u32*)((char*)obj + 0x24) = 0x1;
    
    obj = *(void**)((char*)param_1 + 0x4);
    *(u32*)((char*)obj + 0xf4) = *(u32*)((char*)obj + 0xf4) & 0xffffffbf;
    
    obj = *(void**)((char*)param_1 + 0x4);
    *(void**)((char*)obj + 0xec) = (void*)lbl_802BF42C;
    
    *(u8*)((char*)param_1 + 0x10) = *(u8*)((char*)param_1 + 0x10) | 0x1;
    *(void**)((char*)param_1 + 0x4) = nullptr;
}

extern "C" void* fn_8004CBB4(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern char lbl_80246DC4[];
extern "C" void* fn_8004D5D0(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80246DC4;
        fn_801303BC(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80130CB8(void*, int);
extern char lbl_80246E14[];
extern "C" void* fn_8004D634(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80246E14;
        fn_80130CB8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80130CB8(void*, int);
extern char lbl_80246F18[];
extern "C" void* fn_8004D9C4(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80246F18;
        fn_80130CB8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern char lbl_80246F4C[];
extern "C" void* fn_8004DA28(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80246F4C;
        fn_80130CB8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern void* lbl_80222428[];
extern void* lbl_80247088[];
extern "C" void* fn_8004DC80(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247088;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80222428;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

