#include "types.h"
extern "C" void fn_8001D66C(void*, void*);
extern "C" void fn_800126C4(void*);
extern "C" void fn_8001A950(void);
extern u8 lbl_8029FDB4[];
extern "C" int fn_800636A0(void*, void*, int);
extern "C" unsigned int fn_8001C554(void*, int*);
extern "C" void fn_8001E8B4(void);
extern u8 lbl_802B7CA0[];
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80019470-0x80021014 (291 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8001C2E4(void*, void*);
extern "C" void fn_801155E0(void*, int);
extern "C" void* fn_8001D630(void*, void*);
extern char lbl_802FEC48[];
extern u32 lbl_802FBA08;
extern "C" void* fn_8001AC84(void*);
extern "C" void fn_8001C174(void*, void*, void*, int);
extern "C" void* fn_8001C010(void);
extern "C" void fn_8001C008(void*);
extern "C" void fn_8001B9CC(void);
extern "C" void* fn_8001BF80(void*);
extern "C" void* fn_8001C094(void*);
extern "C" void fn_8001EB7C(void*, u8);
extern "C" void fn_8001EDEC(void*, void*, void*, void*, void*);
extern "C" void fn_8001C930(void);
extern void* lbl_802B7BD8;
extern void* lbl_802B7C04;
extern "C" void* fn_8001D540(void*, void*);
extern "C" void fn_8001D57C(void*, void*);
extern "C" void* fn_8001AC74(void*, void*);
extern "C" void* fn_8001BFBC(void*);
extern "C" void* fn_8001C518(void*, void*, void*);
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

extern "C" s32 fn_8001D5F4(void*, void*);
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

extern "C" void fn_8001A238(void* param_1, u16 param_2) {
    if (param_2 > 0x7fff) {
        return;
    }
    *(u16*)((u8*)param_1 + 6) = param_2;
}

extern "C" int fn_8001A24C(void* param_1) {
    if ((u32)((*(u8*)param_1 >> 7) & 1) == 1 || *(u16*)((u8*)param_1 + 6) != 0) {
        return 0;
    }
    fn_801155E0(param_1, 2);
    return 1;
}

extern "C" void fn_8001A298(void* param_1) {
    fn_8001D66C(*(void**)((u8*)param_1 + 0x1ac), param_1);
}

extern "C" void fn_8001A2C0(void* param_1) {
    fn_8001D57C(*(void**)((u8*)param_1 + 0x1ac), param_1);
}

extern "C" void fn_8001A2E8(void* param_1) {
    fn_8001D5B8(*(void**)((u8*)param_1 + 0x1ac), param_1);
}

extern "C" s32 fn_8001A310(void* param_1) {
    s32 ret = fn_8001D5F4(*(void**)((u8*)param_1 + 0x1ac), param_1);
    if (ret == 1) {
        ((void (*)(void*))fn_8001A950)((u8*)param_1 + 0x1b0);
    }
    fn_800126C4(lbl_8029FDB4);
    return ret;
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

extern "C" int fn_8001BBBC(short* param_1) {
    return (int)*param_1;
}

extern "C" void fn_8001BBC4(unsigned short* param_1, unsigned short param_2) {
    *param_1 = param_2;
}

extern "C" unsigned int fn_8001BBCC(int param_1) {
    int arr[1];
    arr[0] = param_1;
    
    unsigned int check = (unsigned int)(param_1 + 2);
    if (check <= 1) {
        return 0;
    }
    
    return fn_8001C554((void*)fn_8001E8B4, arr);
}

extern "C" int fn_8001BC10(int param_1) {
    int arr[1];
    arr[0] = param_1;
    
    unsigned int check = (unsigned int)(param_1 + 2);
    if (check > 1) {
        unsigned int result = fn_8001C554((void*)&fn_8001E8B4, arr);
        if (result != 0) {
            return 1;
        }
    }
    
    return 0;
}

extern "C" void fn_8001EA5C(void);
extern "C" void fn_8001BE84(void) {
    fn_8001EA5C();
}

extern "C" void fn_8001EB08(void);
extern "C" void fn_8001BEA4(void) {
    fn_8001EB08();
}

extern "C" void* fn_8001C308(void* param_1) {
    void* result = nullptr;
    if (*(s8*)((u8*)param_1 + 0xbc) == 0) {
        result = fn_8001D540(*(void**)((u8*)*(void**)((u8*)param_1 + 0xb8) + 0x10), param_1);
    }
    return result;
}

extern "C" void fn_8001C34C(void* param_1) {
    fn_8001D57C(*(void**)((u8*)param_1 + 0xb8), param_1);
}

extern "C" void fn_8001C374(void* param_1) {
    fn_8001D5B8(*(void**)((u8*)param_1 + 0xb8), param_1);
}

extern "C" void fn_8001C39C(void* param_1) {
    if (fn_8001D5F4(*(void**)((u8*)param_1 + 0xb8), param_1) == 1) {
        *(u32*)((u8*)param_1 + 0xb4) = 0;
    }
}

extern "C" void fn_8001EC90(void);
extern "C" void fn_8001C984(void) {
    fn_8001EC90();
}

extern "C" void fn_8001BC68(void);
extern "C" void fn_8001C9DC(void) {
    fn_8001BC68();
}

extern "C" u32 fn_8001F26C(u32, s16, u32, void*, u32);
extern "C" void fn_8001C9FC(void) {
    fn_8001B9CC();
}

extern "C" void fn_8001CA1C(void) {
    fn_8001B5D4();
}

extern "C" void fn_8001D434(void) {
    fn_8001C174(&lbl_802B7BD8, 0, &lbl_802B7C04, 10);
    fn_8001C930();
}

extern "C" void fn_8001D470(void* param_1, void* param_2, void* param_3, void* param_4) {
    void* result = fn_8001C010();
    fn_8001EDEC(result, param_1, param_2, param_3, param_4);
}

extern "C" void fn_8001D4D4(void* param_1, u8 param_2) {
    fn_8001EB7C(param_1, param_2 & 0xFF);
}

extern "C" void fn_8001EBA4(void*, u8);
extern "C" void fn_8001D4F8(void* param_1, u8 param_2) {
    fn_8001EBA4(param_1, param_2 & 0xFF);
}

extern "C" void fn_8001EC10(void*, u8);
extern "C" void fn_8001D51C(void* param_1, u8 param_2) {
    fn_8001EC10(param_1, param_2 & 0xFF);
}

extern "C" s32 fn_8001D5F4(void* param_1, void* param_2) {
    s32 (*fn)(void*) = *(s32 (**)(void*))((u8*)param_1 + 4);
    if (fn != nullptr) {
        return fn(param_2);
    }
    return 1;
}

extern "C" void* fn_8001D630(void* param_1, void* param_2) {
    void* (*fn)(void*) = *(void* (**)(void*))(param_1);
    if (fn != nullptr) {
        return fn(param_2);
    }
    return (void*)1;
}

extern "C" void* fn_8001D690(void* param_1) {
    void* result = nullptr;
    
    if (*(s8*)((u8*)param_1 + 0x1a8) == 0) {
        void* temp = fn_8001C010();
        fn_8001C008((u8*)param_1 + 0xbc);
        result = fn_8001D540(*(void**)((u8*)*(void**)((u8*)param_1 + 0xb8) + 0x10), param_1);
        fn_8001C008(temp);
    }
    
    return result;
}

extern "C" void* fn_8001D57C_ret(void*, void*);
extern "C" void* fn_8001D708(void* param_1) {
    extern void* fn_8001D57C(void*, void*);
    
    void* temp = fn_8001C010();
    fn_8001C008((u8*)param_1 + 0xbc);
    void* result = fn_8001D57C(*(void**)((u8*)param_1 + 0xb8), param_1);
    fn_8001C008(temp);
    return result;
}

extern "C" void* fn_8001D76C(void* param_1) {
    if (param_1 != nullptr) {
        s32 result = (s32)fn_8001AC74((void*)lbl_802FEC48, *(void**)((u8*)param_1 + 0xb4));
        if (result != 0) {
            void* ptr = (u8*)param_1 + 0xbc;
            s32 check = (s32)fn_8001BFBC(ptr);
            if (check == 0) {
                return fn_8001C518(ptr, (void*)fn_8001D76C, nullptr);
            }
            return param_1;
        }
    }
    return nullptr;
}

extern "C" u32 fn_8001D7EC(void* param_1) {
    if (lbl_802FBA08 != 1) {
        return 1;
    }
    
    if (param_1 == nullptr) {
        return 0;
    }
    
    void* result = fn_8001AC74((void*)lbl_802FEC48, *(void**)((u8*)param_1 + 0xb4));
    if (result == nullptr) {
        return 0;
    }
    
    void* ptr = (u8*)param_1 + 0xbc;
    void* check = fn_8001BFBC(ptr);
    void* final_result;
    if (check == nullptr) {
        final_result = fn_8001C518(ptr, (void*)fn_8001D76C, nullptr);
    } else {
        final_result = param_1;
    }
    
    if (final_result != nullptr) {
        return 0;
    }
    return 1;
}

extern "C" void fn_8001D890(void* param_1) {
    fn_8001D5B8(*(void**)((u8*)param_1 + 0xb8), param_1);
}

extern "C" void* fn_8001D91C(void* param_1) {
    if (*(s8*)((u8*)param_1 + 0xc) == 0) {
        void* r31 = *(void**)((u8*)param_1 + 0x10);
        void* temp = fn_8001AC84((void*)lbl_802FEC48);
        *(void**)((u8*)param_1 + 0xb4) = temp;
        *(void**)((u8*)param_1 + 0xb8) = *(void**)((u8*)r31 + 0x1c);
        fn_8001C174((void*)((u8*)param_1 + 0xbc), param_1, (void*)((u8*)param_1 + 0xe8), 0x10);
        *(u8*)((u8*)param_1 + 0x1a8) = 0;
    }
    
    void* temp2 = fn_8001C010();
    fn_8001C008((void*)((u8*)param_1 + 0xbc));
    void* result = fn_8001D630(*(void**)((u8*)param_1 + 0xb8), param_1);
    fn_8001C008(temp2);
    return result;
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

extern "C" int fn_80020E48(void* param_1) {
    int ret = fn_800636A0(param_1, lbl_802B7CA0 + 0x2200, 0x40);
    if (ret < 0) {
        return 5;
    }
    return ret > 0 ? 0 : 2;
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
    int ret = fn_8006347C(param_1[0], lbl_802B7CA0 + 0x2200, 0x40, lbl_802061AC, 0, (int)param_1[1]);
    int r = 2;
    if (ret == 0) {
        r = 5;
    }
    return r;
}

