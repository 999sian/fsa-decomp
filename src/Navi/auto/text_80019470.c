#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80019470-0x80021014 (291 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8001C2E4(void*, void*);
extern "C" void fn_801155E0(void*, int);
extern "C" void fn_8001D630(void*, void*);
extern "C" void* fn_800194F8(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8001978C(void) {
}

extern "C" void fn_80019790(void) {
}

extern "C" void fn_80019794(void* param_1) {
    fn_8001C2E4(*(void**)((u8*)param_1 + 0xc0), param_1);
}

extern "C" void fn_8001D57C(void*, void*);
extern "C" void fn_800197BC(void* param_1) {
    fn_8001D57C(*(void**)((u8*)param_1 + 0xc0), param_1);
}

extern "C" void fn_8001D5B8(void*, void*);
extern "C" void fn_800197E4(void* param_1) {
    fn_8001D5B8(*(void**)((u8*)param_1 + 0xc0), param_1);
}

extern "C" void fn_8001D5F4(void*, void*);
extern "C" void fn_8001980C(void* param_1) {
    fn_8001D5F4(*(void**)((u8*)param_1 + 0xc0), param_1);
}

extern "C" void fn_80019834(void* param_1) {
    void* self = param_1;
    void* iVar1;
    
    if (*(s8*)((u8*)self + 0xc) == 0) {
        iVar1 = *(void**)((u8*)self + 0x10);
        fn_801155E0((u8*)self + 0xc4, 1);
        *(void**)((u8*)self + 0xc0) = *(void**)((u8*)iVar1 + 0x24);
        *(s32*)((u8*)self + 0xc8) = -1;
    }
    fn_8001D630(*(void**)((u8*)self + 0xc0), self);
}

extern "C" void fn_8001DC20(void);
extern "C" void fn_8001A5D0(void) {
    fn_8001DC20();
}

extern "C" void fn_8001E628(void);
extern "C" void fn_8001A910(void) {
    fn_8001E628();
}

extern "C" void fn_8001DDA4(void);
extern "C" void fn_8001A930(void) {
    fn_8001DDA4();
}

extern "C" void cTg_SingleCut__FP16create_tag_class(void);
extern "C" void fn_8001A950(void) {
    cTg_SingleCut__FP16create_tag_class();
}

extern "C" void cTg_Create__FP16create_tag_classPv(void);
extern "C" void fn_8001A99C(void) {
    cTg_Create__FP16create_tag_classPv();
}

extern "C" void fn_8001A9BC(void* param_1) {
    fn_8001C2E4(*(void**)((u8*)param_1 + 0xc0), param_1);
}

extern "C" void fn_8001A9E4(void* param_1) {
    fn_8001D57C(*(void**)((u8*)param_1 + 0xc0), param_1);
}

extern "C" void fn_8001AA0C(void* param_1) {
    fn_8001D5B8(*(void**)((u8*)param_1 + 0xc0), param_1);
}

extern "C" void fn_8001AA34(void* param_1) {
    fn_8001D5F4(*(void**)((u8*)param_1 + 0xc0), param_1);
}

extern "C" void cTg_SingleCutFromTree__FP16create_tag_class(void);
extern "C" void fn_8001AAFC(void) {
    cTg_SingleCutFromTree__FP16create_tag_class();
}

extern "C" void fn_8001B590(void) {
    cTg_SingleCut__FP16create_tag_class();
}

extern "C" void fn_8001B0B0(void);
extern "C" void fn_8001B5D4(void) {
    fn_8001B0B0();
}

extern "C" void fn_8001B494(void);
extern "C" void fn_8001B63C(void) {
    fn_8001B494();
}

extern "C" void fn_8001B65C(void);
extern "C" void fn_8001B760(void) {
    fn_8001B65C();
}

extern "C" void fn_8001EA5C(void);
extern "C" void fn_8001BE84(void) {
    fn_8001EA5C();
}

extern "C" void fn_8001EB08(void);
extern "C" void fn_8001BEA4(void) {
    fn_8001EB08();
}

extern "C" void fn_8001EC90(void);
extern "C" void fn_8001C984(void) {
    fn_8001EC90();
}

extern "C" void fn_8001BC68(void);
extern "C" void fn_8001C9DC(void) {
    fn_8001BC68();
}

extern "C" void fn_8001B9CC(void);
extern "C" u32 fn_8001F26C(u32, s16, u32, void*, u32);
extern "C" void fn_8001C9FC(void) {
    fn_8001B9CC();
}

extern "C" void fn_8001CA1C(void) {
    fn_8001B5D4();
}

extern "C" u32 fn_8001DA1C(void* param_1) {
    *(u32*)((u8*)param_1 + 0x54) = fn_8001F26C(
        *(u32*)((u8*)param_1 + 0x50),
        *(s16*)((u8*)param_1 + 0x58),
        *(u32*)(*(u32*)((u8*)param_1 + 0x3c) + 0xc),
        param_1,
        *(u32*)((u8*)param_1 + 0x5c)
    );
    
    u32 lz = __cntlzw(-1 - *(u32*)((u8*)param_1 + 0x54));
    return (lz >> 5) + 2;
}

extern "C" u32 fn_8001DA78(void) {
    return 2;
}

extern "C" u32 fn_8001DB08(void) {
    return 2;
}

extern "C" u32 fn_8001DB10(void) {
    return 2;
}

extern "C" void cTg_IsUse__FP16create_tag_class(void);
extern "C" void fn_8001E69C(void) {
    cTg_IsUse__FP16create_tag_class();
}

extern "C" void cTg_Addition__FP15node_list_classP16create_tag_class(void);
extern "C" void fn_8001EAE8(void) {
    cTg_Addition__FP15node_list_classP16create_tag_class();
}

extern "C" void fn_8001EB08(void) {
    cTg_SingleCut__FP16create_tag_class();
}

extern "C" u32 fn_8001EFE4(void) {
    return 2;
}

extern "C" void fn_8001F7F0(int param_1, f32* param_2) {
    f32 t0, t1, t2;
    t0 = param_2[0], t1 = param_2[1];
    *(f32*)(param_1 + 0x30) = t0;
    t2 = param_2[2];
    *(f32*)(param_1 + 0x34) = t1;
    *(f32*)(param_1 + 0x38) = t2;
    *(u8*)(param_1 + 4) |= 0x20;
}

extern "C" void* fn_8001F818(void* param_1) {
    void* q = *(void**)((char*)param_1 + 4);
    if (q != nullptr) {
        return q;
    }
    return nullptr;
}

extern "C" u32 fn_8001F82C(void* param_1, u8 param_2) {
    if (param_2 == 0) {
        return 0;
    }
    if (param_2 > 8) {
        return 0;
    }
    return *(u32*)((char*)param_1 + param_2 * 4 + 4);
}

extern "C" void fn_80132858(void*, int);
extern char lbl_80205A6C[];
extern "C" void* fn_8001F854(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80205A6C;
        fn_80132858(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80132778(void*, int);
extern char lbl_80205B18[];
extern "C" void* fn_8001F8B4(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80205B18;
        fn_80132778(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_801329B4(void*, int);
extern char lbl_802059DC[];
extern "C" void* fn_8001FE38(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_802059DC;
        fn_801329B4(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8015AB1C(void*);
extern "C" void* fn_80020304(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void* fn_80020344(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" int fn_800636A0(void*, void*, int);
extern "C" int fn_8006347C(void*, void*, int, const char*, int, int);
extern "C" int fn_80021240(void*, const void*, int);
extern u8 lbl_802B7CA0[];
extern const char lbl_802061AC[];
extern const u8 lbl_802061C0[];
extern "C" int fn_80020E9C(void) {
    return 4;
}

extern "C" int fn_80020EA4(void* param_1, int param_2) {
    if (*(int*)((u8*)param_1 + 4) == 2) {
        return 4;
    }
    return fn_80021240(param_1, lbl_802061C0, param_2);
}

extern "C" int fn_80020EE4(void** param_1) {
    extern u8 lbl_802B7CA0[];
    return fn_8006347C(param_1[0], lbl_802B7CA0 + 0x2200, 0x40, lbl_802061AC, 0, (int)param_1[1]) == 0 ? 5 : 2;
}

