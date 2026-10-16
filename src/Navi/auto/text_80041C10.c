#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80041c10-0x8004dcf8 (82 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8004C614(void*);
extern "C" void fn_8004C694(void*);

extern unsigned char lbl_80246BD8[];
extern unsigned char lbl_80246C0C[];
extern int lbl_802FC1B0;
extern int lbl_802FC1B4;
extern void* lbl_802FF0C0;
extern u8 lbl_802EE470[];
extern "C" void fn_8012FDE0(void*);
extern "C" void fn_8012FE90(void*, void*, void*);
extern "C" void fn_80192688(void*);
extern "C" void fn_801DEE3C(s32);
extern "C" void fn_801DE24C(s32);
extern "C" void fn_801DE3E0(s32, s32, s32, s32, s32);
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
    register void* vtable = *(void**)param_1;
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
    if (param_1) {
        *(void**)param_1 = (void*)lbl_80246FDC;
        if (param_1) {
            *(void**)param_1 = (void*)lbl_80247000;
        }
        fn_801303BC(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8004B1DC(void* param_1, void* param_2, void* param_3, void* param_4) {
    register void* vtable = *(void**)param_1;
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

extern "C" void fn_8004C52C(void*, void* p) {
    bool flag = false;
    if (((*(unsigned int*)((char*)p + 0xf4) & 0x8) != 0) &&
        ((*(unsigned int*)((char*)p + 0xd0) + *(unsigned int*)((char*)p + 0xdc)) == 0)) {
        flag = true;
    }
    if (flag) {
        *(unsigned int*)((char*)p + 0xf4) &= 0xffffffbf;
        *(unsigned int*)((char*)p + 0xec) = 0;
        *(unsigned int*)((char*)p + 0xf0) = 0;
        fn_8004C614(p);
    } else {
        fn_8004C694(p);
    }
}

extern "C" void fn_8004C5A0(void*, void* p) {
    extern void* lbl_802FF0A0;
    extern unsigned char lbl_802FF0A4;
    extern unsigned char lbl_802FF0A5;
    extern int lbl_802FF09C;
    
    *(unsigned int*)((char*)p + 0xec) = 0;
    
    void* base = lbl_802FF0A0;
    if (base == 0) return;
    
    unsigned char max_count = lbl_802FF0A4;
    if (max_count <= 0) return;
    
    unsigned char current_idx = lbl_802FF0A5;
    unsigned char rem = current_idx % max_count;
    lbl_802FF0A5 = rem;
    
    unsigned char cnt = max_count;
    while (true) {
        int val = *(int*)((char*)base + rem * 0xc4);
        if (val == 0) {
            rem++;
            lbl_802FF0A5 = rem;
            *(unsigned int*)((char*)p + 0xc0) = rem - 1;
            *(unsigned int*)((char*)p + 0xf0) = (unsigned int)&lbl_802FF09C;
            return;
        }
        rem++;
        if (--cnt == 0) break;
    }
}

extern "C" void* fn_8011FD10(void);
extern "C" void fn_8011FD18(void*, void*, int, void*, void*);
extern "C" void fn_80007AB8(void*, int, void*);
extern "C" void fn_80130C64(void*, unsigned char, int);
extern "C" void fn_8003C510(void*, void*, void*);
extern "C" void fn_80115914(void*, void*);
extern "C" void fn_801E0DB8(void*, void*, void*, int, int);
extern "C" void* fn_8004C970(void*);
extern "C" void fn_8004C614(void* p) {
    if (p == 0) {
        void* tmp = fn_8011FD10();
        fn_8011FD18(tmp, lbl_80246BD8, 0x42e, &lbl_802FC1B0, lbl_80246C0C);
        fn_80007AB8(lbl_80246BD8, 0x42e, &lbl_802FC1B4);
    }
    void* result = fn_8004C970(p);
    if (result != 0) {
        *(unsigned int*)result = 0;
    }
}

extern "C" void* fn_8004C970(void* param_1) {
    extern void* lbl_802FF0A0;
    extern unsigned char lbl_802FF0A4;
    extern unsigned char lbl_80246BD8[];
    extern unsigned char lbl_80246C1C[];
    extern int lbl_802FC1B0;
    extern int lbl_802FC1B4;
    
    void* base = lbl_802FF0A0;
    if (base == 0 || param_1 == 0) {
        return 0;
    }
    
    unsigned int value = *(unsigned int*)((char*)param_1 + 0xc0);
    
    if (value == 0xffffffff) {
        return 0;
    }
    
    unsigned char max_val = lbl_802FF0A4;
    if (value >= (unsigned int)max_val) {
        void* tmp = fn_8011FD10();
        fn_8011FD18(tmp, (void*)lbl_80246BD8, 0x477, (void*)lbl_80246C1C, (void*)lbl_802FC1B0);
        fn_80007AB8((void*)lbl_80246BD8, 0x477, (void*)lbl_802FC1B4);
    }
    
    return (void*)((char*)base + value * 0xc4);
}

extern "C" void fn_8004CB14(void* param_1, void* param_2) {
    unsigned char byte = *(unsigned char*)((char*)param_1 + 4);
    fn_80130C64(param_2, byte, 0);
}

extern "C" void fn_8004CBF0(void);
extern "C" void* fn_8004CBB4(void* ptr, s16 param_2);
extern "C" void* fn_8004CB44(void* param_1) {
    extern unsigned char lbl_80247020[];
    extern unsigned char lbl_80246E48[];
    
    *(void**)param_1 = (void*)lbl_80247020;
    *(void**)param_1 = (void*)lbl_80246E48;
    fn_801E0DB8((void*)((char*)param_1 + 0x10), (void*)fn_8004CBF0, (void*)fn_8004CBB4, 0x14, 0x20);
    *(unsigned int*)((char*)param_1 + 4) = 0;
    *(unsigned short*)((char*)param_1 + 0xc) = 0;
    return param_1;
}

extern "C" void* fn_8004CBB4(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8004CBF0(void) {
}

extern "C" void fn_8004CEC8(void* param_1, void* param_2, void* param_3) {
    extern float lbl_80300124;
    
    float arr1[3];
    arr1[0] = *(float*)((char*)param_3 + 0x18);
    arr1[1] = *(float*)((char*)param_3 + 0x1c);
    arr1[2] = *(float*)((char*)param_3 + 0x20);
    
    float arr2[3];
    float arr3[3];
    
    fn_8003C510(arr1, arr2, arr3);
    
    float scale = lbl_80300124 * arr1[0];
    
    fn_80115914(param_2, arr2);
    
    *(float*)((char*)param_3 + 0x18) = arr1[0];
    *(float*)((char*)param_3 + 0x1c) = arr1[1];
    *(float*)((char*)param_3 + 0x20) = arr1[2];
}

extern "C" void fn_8004D298(void) {}

extern "C" void fn_8004D29C(void* param_1, void* param_2, void* param_3) {
    if (lbl_802FF0C0 != nullptr) {
        fn_80192688(lbl_802EE470);
        fn_8012FE90(lbl_802FF0C0, param_2, param_3);
        fn_801DEE3C(0);
        fn_801DE24C(0);
    }
}

extern "C" void fn_8004D468(void) {
    fn_801DE3E0(0, 7, 7, 7, 1);
}

extern "C" void fn_8004D5C0(void) {}

extern "C" void fn_8004D5C4(void) {}

extern "C" void fn_8004D5C8(void) {}

extern "C" void fn_8004D5CC(void) {}

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

extern "C" void fn_8004D630(void) {}

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

extern "C" void fn_8004D694(void) {}

extern "C" void fn_8004D708(void) {
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

extern "C" void fn_8004DA24(void) {}

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

