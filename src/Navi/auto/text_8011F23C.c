#include "types.h"
#include "dolphin/os/OSFastCast.h"
extern "C" void fn_8013A57C(void);
extern "C" void* fn_80139950(void*, void*, void*);
extern "C" void fn_801334AC();
extern "C" void fn_8013345C();
extern void* lbl_802925EC[];
extern void* lbl_80292558[];
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8011f23c-0x80135cf8 (427 functions). split_file divides it into the game's real files.

extern void* lbl_80290ACC[];
extern const f32 lbl_803016E0;
extern const f32 lbl_803016E4;
extern "C" void fn_8012C274(void*);
extern "C" void fn_8015AB1C(void* ptr);
extern u8 lbl_802FF334;
extern f32 lbl_802FEAB4;
extern "C" void fn_80166C08(void*, int);
extern "C" void* fn_8011F23C(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_801204E4(void) {
    lbl_802FF334 = 0;
}

extern "C" void* fn_80120B20(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290ACC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_8012A804(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" int fn_8012A80C(int* p) { return *p; }

extern "C" void* fn_8012C240(void* ptr, void* param_2) {
    *(void**)ptr = param_2;
    fn_8012C274(ptr);
    return ptr;
}

extern "C" void fn_8012C4A4(void* param_1, u8* param_2) {
    f32 val = lbl_803016E0 * (lbl_803016E4 - *(f32*)(param_2 + 0x84));
    OSf32tou8(&val, param_2 + 0x96);
}

extern "C" void fn_8012C4D0(void* param_1, u8* param_2) {
    *(f32*)(param_2 + 0x60) = *(f32*)(param_2 + 0x68) * (lbl_803016E4 - *(f32*)(param_2 + 0x84));
    *(f32*)(param_2 + 0x64) = *(f32*)(param_2 + 0x6c) * (lbl_803016E4 - *(f32*)(param_2 + 0x84));
}

extern "C" const float lbl_803016E4;
extern "C" const float lbl_803016E0;
extern "C" void fn_8012C274(void*);
extern "C" void fn_8012C500(void** param_1, void* param_2) {
    *param_1 = param_2;
}

extern "C" void fn_8012C604(void** param_1, void* param_2) {
    *param_1 = param_2;
}

extern "C" void fn_8012D010(void*);
extern "C" void* fn_8012CFDC(void* ptr, void* param_2) {
    *(void**)ptr = param_2;
    fn_8012D010(ptr);
    return ptr;
}

extern void* lbl_80290F9C[];
extern "C" void* fn_8012F204(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290F9C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80290FCC[];
extern "C" void* fn_8012F24C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290FCC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80290FFC[];
extern "C" void* fn_8012F2A8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290FFC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029102C[];
extern "C" void* fn_8012F304(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029102C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80291060[];
extern "C" void* fn_8012F360(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80291060;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80291090[];
extern "C" void* fn_8012F3BC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80291090;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802910C0[];
extern "C" void* fn_8012F418(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802910C0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802910F0[];
extern "C" void* fn_8012F474(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802910F0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029111C[];
extern "C" void* fn_8012F4D0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029111C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029114C[];
extern "C" void* fn_8012F52C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029114C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801300FC(u8* p, u32 v, u8 i) {
    (*(u32**)(p + 0x1c))[i] = v;
}

extern "C" void* fn_80130264(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80166B70(void*, s32);
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80166B58(void*, void*);
extern "C" void fn_801302A0(u32* p) {
    p[0] = 0;
    p[1] = 0;
}

extern "C" void fn_80166C08(void*, int);
extern "C" void* fn_801302B0(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_80130304(u8* p, s16 del) {
    if (p) {
        if (p + 0x58) {
            fn_80166B70(p + 0x58, 0);
        }
        if (del > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" u8* fn_80130364(u8* p) {
    fn_80166B58(p + 0x58, p);
    *(u32*)(p + 0xc4) = 0;
    *(u32*)(p + 0xc8) = 0;
    *(u32*)(p + 0xcc) = 0;
    *(u32*)(p + 0xd0) = 0;
    *(u32*)(p + 0xd4) = 0;
    *(u32*)(p + 0xd8) = 0;
    *(u32*)(p + 0xdc) = 0;
    return p;
}

extern void* lbl_80247020[];
extern "C" void* fn_801303BC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247020;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802470EC[];
extern "C" void* fn_80130CB8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802470EC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801327D8(void) {
    return 3;
}

extern "C" void fn_801327E8(void) {
}

extern "C" float lbl_803017A0;
extern "C" float fn_801327EC(void) {
    return lbl_803017A0;
}

extern "C" void fn_801327F4(void) {
}

extern f32 lbl_802FEAB4;
extern "C" f32 fn_801327F8(void) {
    f32 temp = lbl_802FEAB4;
    return temp;
}

extern "C" float lbl_803017A0;
extern "C" float fn_80132808(void) {
    return lbl_803017A0;
}

extern "C" float fn_80132814(void) {
    return lbl_803017A0;
}

extern "C" float fn_8013284C(void) {
    return lbl_803017A0;
}

extern "C" int fn_801328B8(void) {
    return 5;
}

extern "C" void fn_801328C8(void) {
}

extern "C" void fn_801328D4(void) {
}

extern "C" void fn_801328D8(void) {
}

extern void* lbl_80291320[];
extern "C" void* fn_801328F8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80291320;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8020597C[];
extern "C" void* fn_80132C50(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8020597C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292694[];
extern "C" void* fn_80133414(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292694;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292684[];
extern "C" void* fn_80133510(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292684;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292694;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801338F8(u8* p, void* unused, int i) {
    *(u32*)(*(u8**)(p + 4) + i * 0x14 + 8) = 0;
}

extern "C" void fn_80133910(u8* p, void* unused, int i, f32* v) {
    f32 f = *v;
    u8* e = *(u8**)(p + 4) + i * 0x14;
    *(void**)(e + 8) = (void*)fn_8013345C;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xc) = f;
}

extern "C" void fn_80133470();
extern "C" void fn_8013393C(u8* p, void* unused, int i, f32* v) {
    f32 f = *v;
    u8* e = *(u8**)(p + 4) + i * 0x14;
    *(void**)(e + 8) = (void*)fn_80133470;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xc) = f;
}

extern "C" void fn_80133968(u8* p, u8* q, int i, void* a, void* b) {
    u8* e = *(u8**)(p + 4) + i * 0x14;
    u8* r = (u8*)fn_80139950(*(u8**)(q + 0x14) + 0x60, a, b);
    u32 v;
    if (r == 0) {
        v = 0;
    } else {
        v = *(u32*)(r + 0x14);
    }
    *(void**)(e + 8) = (void*)fn_801334AC;
    *(u32*)(e + 4) = 0;
    *(u32*)(e + 0xc) = v;
}

extern "C" void fn_80133BB0(int param_1, void* param_2, void* param_3, void* param_4, void* param_5) {
    int* obj = *(int**)(param_1 + 0x34);
    if (obj != 0) {
        int** vftbl = *(int***)obj;
        void (*method)(int, int, void*, void*, void*, void*) = (void (*)(int, int, void*, void*, void*, void*))vftbl[7];
        method(param_1, (int)obj, param_2, param_3, param_4, param_5);
    }
}

extern void* lbl_8029259C[];
extern void* lbl_8029260C[];
extern "C" void* fn_80133C0C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029259C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u8* fn_80133C68(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void***)(p + 8) = lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void***)(p + 8) = lbl_80292558;
    return p;
}

extern void* lbl_80292500[];
extern void* lbl_8029260C[];
extern "C" void* fn_8013414C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292500;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802924B4[];
extern "C" u8* fn_801341A8(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void**)(p + 8) = &lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void**)(p + 8) = &lbl_802924B4;
    return p;
}

extern void* lbl_80292438[];
extern "C" void* fn_801343E4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292438;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802923F0[];
extern "C" u8* fn_80134440(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void**)(p + 8) = &lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void**)(p + 8) = &lbl_802923F0;
    return p;
}

extern void* lbl_80292398[];
extern "C" void* fn_80134898(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292398;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292354[];
extern "C" u8* fn_801348F4(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void**)(p + 8) = &lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void**)(p + 8) = &lbl_80292354;
    return p;
}

extern void* lbl_802922F4[];
extern "C" void* fn_80134B3C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802922F4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802922B0[];
extern "C" u8* fn_80134B98(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void**)(p + 8) = &lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void**)(p + 8) = &lbl_802922B0;
    return p;
}

extern void* lbl_80292070[];
struct fn_80135858_Obj {
    virtual void Release(int);
};
extern void* lbl_802026C0;
extern void* lbl_80291BB4;
extern "C" void fn_8013A5EC(int ptr, int param);
extern "C" void fn_8013A57C(void);
extern "C" void fn_801E10DC(int ptr, uint param);
extern "C" int fn_80135858(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_80292070;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern void* lbl_80292148[];
extern "C" int fn_801358EC(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_80292148;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

