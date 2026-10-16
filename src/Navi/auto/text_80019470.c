#include "types.h"
extern u8* lbl_802FB9B8;
extern "C" int fn_80115564(void*);
#include "Navi/SSystem/c_tag.h"
#include "sdk/Dolphin/vec.h"
extern "C" int fn_8001A24C(void* param_1);

extern "C" s32 fn_8001D5F4(void*, void*);

extern "C" s32 fn_8001D5B8(void*, void*);
extern "C" void fn_8001AAFC(void*);
extern "C" void fn_8001D66C(void*, void*);
extern "C" void fn_800126C4(void*);
extern "C" void fn_8001A950(void);
extern "C" void fn_8001A99C(void*, void*);
extern "C" void fn_8001A970(void*);
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
extern void* lbl_802FEC48;
extern "C" void fn_80115178(void*, void*, void*);
extern "C" void fn_8011580C(void);
extern char lbl_802FB9D8;
extern "C" void cTg_AdditionToTree__FP21node_lists_tree_classiP16create_tag_class(void*, int, void*);
extern u32 lbl_802FBA08;
extern "C" void* fn_8001AC84(void*);
extern s8 lbl_802FEC10;
extern s32 lbl_802FEC0C;
extern s8 lbl_802FEC18;
extern s32 lbl_802FEC14;
extern "C" void fn_8001C174(void*, void*, void*, int);
extern "C" void* fn_8001C010(void);
extern "C" u32 fn_8001F26C(u32, s16, u32, void*, u32);
extern "C" void fn_8001C008(void*);
extern "C" void fn_8001B9CC(void);
extern "C" u32 fn_8001BF80(void*);
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
extern "C" void __unregister_fragment(int);
extern "C" void cTg_Addition__FP15node_list_classP16create_tag_class(void*, void*);
extern "C" void fn_80019470(f32* d, const Vec* s, f32 w) {
    f32 z;
    f32 x = s->x;
    f32 y = s->y;
    d[0] = x;
    z = s->z;
    d[1] = y;
    d[2] = z;
    d[3] = w;
}

extern "C" void fn_80019490(f32* d, const f32* s) {
    f32 y = s[1];
    f32 x = s[0];
    d[0] = x;
    f32 z = s[2];
    d[1] = y;
    f32 w = s[3];
    d[2] = z;
    f32 v = s[4];
    d[3] = w;
    f32 u = s[5];
    d[4] = v;
    d[5] = u;
}

extern "C" void fn_800194C4(f32* d, const f32* a, const f32* b) {
    f32 y = a[1];
    f32 x = a[0];
    d[0] = x;
    f32 z = a[2];
    d[1] = y;
    f32 by = b[1];
    d[2] = z;
    f32 bx = b[0];
    d[3] = bx;
    f32 bz = b[2];
    d[4] = by;
    d[5] = bz;
}

extern "C" void* fn_800194F8(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80019534(void* param_1) {
    fn_8001C2E4(*(void**)((u8*)param_1 + 0x224), param_1);
}

extern "C" void fn_8001955C(void* param_1) {
    fn_8001D57C(*(void**)((u8*)param_1 + 0x224), param_1);
}

extern "C" s32 fn_80019584(void* param_1) {
    s32 iVar1;
    iVar1 = fn_8001D5B8(*(void**)((u8*)param_1 + 0x224), param_1);
    if (iVar1 == 1) {
        fn_8001AAFC((u8*)param_1 + 0x210);
    }
    return iVar1;
}

extern "C" s32 fn_800195D8(void* param_1) {
    s32 iVar1;
    iVar1 = fn_8001D5F4(*(void**)((u8*)param_1 + 0x224), param_1);
    if (iVar1 == 1) {
        fn_8001AAFC((u8*)param_1 + 0x210);
    }
    return iVar1;
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

extern "C" s32 fn_8001D5B8(void*, void*);
extern "C" void fn_8001AAFC(void*);
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

extern "C" void fn_80019918(s32 param_1) {
    if (lbl_802FB9B8 != NULL) {
        *(s32*)(*(u8**)(lbl_802FB9B8 + 0x20) + 0xc8) = param_1;
    }
}

extern "C" s32 fn_80019930(void) {
    if (lbl_802FB9B8 != NULL) {
        return *(s32*)(lbl_802FB9B8 + 8);
    }
    return 0;
}

#pragma dont_inline on
extern "C" s32 fn_8001994C(void) {
    if (lbl_802FB9B8 != NULL) {
        return fn_80115564(lbl_802FB9B8);
    }
    return 0;
}

extern "C" s32 fn_80019980(void) {
    if (lbl_802FB9B8 != NULL && *(u16*)(lbl_802FB9B8 + 4) == 1) {
        return 1;
    }
    return 0;
}

extern "C" s32 fn_800199A8(void) {
    if (lbl_802FB9B8 != NULL) {
        return fn_8001A24C(lbl_802FB9B8);
    }
    return 0;
}

#pragma dont_inline reset

extern "C" void fn_80019AE0(void) {
}

extern "C" s32 fn_80019CFC(u8* p) {
    fn_8001C008(*(void**)(p + 0x24));
    *(u32*)(p + 0x14) = fn_8001F26C((u32)fn_8001C010(), *(s16*)(p + 0x10), 0, 0, 0);
    return 2;
}

extern "C" void fn_801155C0(void*, s32);
extern "C" void fn_8011526C(void*, void*);
extern u8 lbl_80205580[];
extern "C" void* fn_8001BFF8(void);
extern "C" void fn_8001A238(void* param_1, u16 param_2);
extern "C" void* fn_80019D4C(u8* p, s16 a, u16 b) {
    if (*(u16*)(p + 4) == 1) {
        return NULL;
    }
    fn_801155C0(p, 1);
    *(s16*)(p + 0x10) = a;
    fn_8011526C(p + 0x18, lbl_80205580);
    fn_8001A238(p, b);
    *(u16*)(p + 4) = 1;
    *(u16*)(p + 2) = 1;
    *(u32*)(p + 0x20) = 0;
    *(u32*)(p + 8) = 0;
    *(u32*)(p + 0xc) = 0;
    *(void**)(p + 0x24) = fn_8001BFF8();
    return p;
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

extern "C" void fn_8001A370(u8* param_1) {
    if (*(s8*)(param_1 + 0xc) == 0) {
        *(void**)(param_1 + 0x1ac) = *(void**)(*(u8**)(param_1 + 0x10) + 0x20);
        fn_8001A99C(param_1 + 0x1b0, param_1);
        fn_8001A970(param_1 + 0x1b0);
        if (*(u32*)(param_1 + 0xac) != 0) {
            *(u32*)(param_1 + 0xb0) = **(u32**)(param_1 + 0xac);
        }
    }
    fn_8001D630(*(void**)(param_1 + 0x1ac), param_1);
}

extern "C" void fn_80114C94(void*, void*, void*);
extern "C" void fn_8011583C();
extern "C" void fn_8001E89C();
extern "C" int fn_8001A828(int, int, int, int, int, int);
extern u8 lbl_80205620[];
extern int lbl_802FB9C0;
extern "C" void fn_8001A3E4(int param_1, void* param_2) {
    int local[2];
    local[0] = param_1;
    local[1] = (int)param_2;
    fn_80114C94(lbl_80205620, (void*)fn_8011583C, local);
}

#pragma dont_inline on
extern "C" void fn_8001A424(s16 param_1) {
    s16 local[1];
    local[0] = param_1;
    fn_8001A3E4((int)fn_8001E89C, local);
}
#pragma dont_inline reset

extern "C" int fn_8001A454(int param_1, int param_2, int param_3, int param_4) {
    u32 r = fn_8001A828(2, param_1, param_2, 0, param_3, param_4);
    if (r == 0xFFFFFFFF) {
        return 0;
    }
    lbl_802FB9C0 = r;
    return 1;
}

extern "C" void fn_8001A59C(void) {}

extern "C" s32 fn_800199A8(void);
extern "C" u32 fn_8001A5A0(void) {
    s32 iVar1 = fn_800199A8();
    u32 uVar2 = 0;
    if (iVar1 == 1) {
        uVar2 = 2;
    }
    return uVar2;
}

extern "C" void fn_8001DC20(void);
extern "C" void fn_8001A5D0(void) {
    fn_8001DC20();
}

extern "C" s32 fn_80019980(void);
extern "C" u32 fn_8001A5F0(void) {
    s32 iVar1 = fn_80019980();
    u32 uVar2 = 0;
    if (iVar1 == 1) {
        uVar2 = 2;
    }
    return uVar2;
}

extern "C" s32 fn_8001994C(void);
extern "C" u32 fn_8001A620(void) {
    s32 iVar1 = fn_8001994C();
    u32 uVar2 = 0;
    if (iVar1 == 1) {
        uVar2 = 2;
    }
    return uVar2;
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

extern "C" void fn_8001A970(void* tag) {
    cTg_Addition__FP15node_list_classP16create_tag_class(lbl_80205620, tag);
}

extern "C" void cTg_Create__FP16create_tag_classPv(void*, void*);
extern "C" void fn_8001A99C(void* param_1, void* param_2) {
    cTg_Create__FP16create_tag_classPv(param_1, param_2);
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

extern "C" void fn_8001AA98(int param_1, int param_2) {
    int local[2];
    local[0] = param_1;
    local[1] = param_2;
    fn_80115178((void*)&lbl_802FB9D8, (void*)fn_8011580C, local);
}

extern "C" void fn_8001AAD4(void* tag, int no) {
    cTg_AdditionToTree__FP21node_lists_tree_classiP16create_tag_class((void*)&lbl_802FB9D8, no, tag);
}

extern "C" s32 cTg_SingleCutFromTree__FP16create_tag_class(void*);
extern "C" void fn_8001AAFC(void* tag) {
    cTg_SingleCutFromTree__FP16create_tag_class(tag);
}

extern "C" void cTr_Create__FP21node_lists_tree_classP15node_list_classi(void*, void*, int);
extern "C" void cTg_AdditionToTree__FP21node_lists_tree_classiP16create_tag_class(void*, int, void*);
extern "C" void fn_8001D4F8(void* param_1, u8 param_2);
extern u8 lbl_802B4C38[];
extern "C" s32 fn_8001AB1C(void* tag, void* data) {
    cTg_Create__FP16create_tag_classPv(tag, data);
    return 1;
}

extern "C" void fn_8001AB40(void) {
    cTr_Create__FP21node_lists_tree_classP15node_list_classi((void*)&lbl_802FB9D8, lbl_802B4C38, 1000);
}

extern "C" s32 fn_8001AB70(void* p) {
    if (p != NULL) {
        fn_8001D4F8(p, 1);
        fn_8001D4F8(p, 2);
        return 1;
    }
    return 0;
}

extern "C" void* fn_8001AC84(void* param_1) {
    if (lbl_802FEC10 == 0) {
        lbl_802FEC0C = 0x09130000;
        lbl_802FEC10 = 1;
    }
    if (*(s32*)param_1 == 0) {
        lbl_802FEC0C = lbl_802FEC0C + 1;
        *(s32*)param_1 = lbl_802FEC0C;
    }
    return *(void**)param_1;
}

extern "C" s32 fn_8001ACC4(void) {
    if (lbl_802FEC18 == 0) {
        lbl_802FEC14 = 1;
        lbl_802FEC18 = 1;
    }
    return lbl_802FEC14++;
}

extern "C" void fn_8001B1F8(void);
extern "C" void* fn_8001ACEC(void* param_1) {
    extern void* fn_8001D57C(void*, void*);
    void* temp = fn_8001C010();
    fn_8001C008(*(void**)((u8*)param_1 + 0x2c));
    void* result = fn_8001D57C(*(void**)((u8*)param_1 + 0xa8), param_1);
    fn_8001C008(temp);
    return result;
}

extern "C" void* fn_8001AD50(void* param_1) {
    extern void* fn_8001D5B8(void*, void*);
    void* temp = fn_8001C010();
    fn_8001C008(*(void**)((u8*)param_1 + 0x2c));
    void* result = fn_8001D5B8(*(void**)((u8*)param_1 + 0xa8), param_1);
    fn_8001C008(temp);
    return result;
}

extern "C" void fn_801148F4(void*);
extern "C" int fn_8001AF58(void* param_1) {
    switch ((int)fn_8001D630(*(void**)((u8*)param_1 + 0xa8), param_1)) {
    case 2:
    case 4:
        if (*(void**)((u8*)param_1 + 0xac) != 0) {
            fn_801148F4(*(void**)((u8*)param_1 + 0xac));
            *(void**)((u8*)param_1 + 0xac) = 0;
        }
        *((u8*)param_1 + 0xd) = 2;
        return 2;
    case 0:
    case 1:
        *((u8*)param_1 + 0xc) = 1;
        *((u8*)param_1 + 0xd) = 0;
        return 0;
    case 3:
        *((u8*)param_1 + 0xd) = 3;
        return 3;
    case 5:
    default:
        *((u8*)param_1 + 0xd) = 5;
        return 5;
    }
}

extern "C" void fn_80114C5C(void*, void*, void*);
extern u8 lbl_80205648[];
extern "C" void fn_8001B014(int param_1, void* param_2) {
    int local[2];
    local[0] = param_1;
    local[1] = (int)param_2;
    fn_80114C5C(lbl_80205648, (void*)fn_8011580C, local);
}

extern "C" void fn_8001B054(int param_1, void* param_2) {
    int local[2];
    local[0] = param_1;
    local[1] = (int)param_2;
    fn_80114C94(lbl_80205648, (void*)fn_8011583C, local);
}

extern u8 lbl_80205658[];
extern "C" bool fn_8001B094(void* a, int* b) {
    return *(int*)(*(u8**)((u8*)a + 0xc) + 0x3c) == *b;
}

extern "C" s32 fn_8001B1DC(void* param_1) {
    if (param_1 != NULL) {
        return *(s8*)((u8*)param_1 + 0x14);
    }
    return 0;
}

#pragma dont_inline on
extern "C" void fn_8001B494(void) {
    fn_8001B014((int)fn_8001B1F8, NULL);
}

extern "C" void* fn_801148BC(s32);
extern "C" void fn_8001B0EC(void*);
extern "C" void fn_8001EB28(void*, void*, void*);
extern "C" void fn_8001BFD0(void*);
extern "C" void fn_8001BEC4(void*, void*);
extern "C" s32 fn_8001B5B0(void* tag, void* data);
extern "C" void fn_8001B564(void* tag);
extern "C" void* fn_8001B4C0(void* param_1, void* param_2, void* param_3) {
    u8* p = (u8*)fn_801148BC(-4);
    if (p != NULL) {
        fn_8001B5B0(p, p);
        fn_8001EB28(p + 0x18, (void*)fn_8001B0EC, p);
        *(void**)(p + 0x44) = param_1;
        *(void**)(p + 0x34) = param_3;
        *(s32*)(p + 0x3c) = fn_8001ACC4();
        *(s32*)(p + 0x40) = 0;
        *(u8*)(p + 0x15) = 0;
        fn_8001BFD0(*(void**)(p + 0x44));
        fn_8001BEC4(*(void**)(p + 0x44), p + 0x18);
        fn_8001B564(p);
    }
    return p;
}

#pragma dont_inline reset

extern "C" void fn_8001B564(void* tag) {
    cTg_Addition__FP15node_list_classP16create_tag_class(lbl_80205648, tag);
}

extern "C" void fn_8001B590(void) {
    cTg_SingleCut__FP16create_tag_class();
}

extern "C" s32 fn_8001B5B0(void* tag, void* data) {
    cTg_Create__FP16create_tag_classPv(tag, data);
    return 1;
}

extern "C" void fn_8001B0B0(void);
extern "C" void fn_8001B5D4(void) {
    fn_8001B0B0();
}

#pragma dont_inline on
extern "C" void fn_8001B5F4(void* p) { fn_8001B1DC(*(void**)((char*)p + 0x14)); }

extern "C" void fn_8001B618(void* p) { fn_8001B0EC(*(void**)((char*)p + 0x14)); }

#pragma dont_inline reset
extern "C" void fn_8001B494(void);
extern "C" void fn_8001B63C(void) {
    fn_8001B494();
}

extern "C" void fn_8001B674(void* tag) {
    *(s16*)((u8*)tag + 0x18) = 1;
    cTg_Addition__FP15node_list_classP16create_tag_class(lbl_80205658, tag);
}

extern "C" s32 fn_8001B6AC(void* tag, int (*func)(void*)) {
    if (*(s16*)((u8*)tag + 0x18) <= 0) {
        cTg_SingleCut__FP16create_tag_class();
        if (func(*(void**)((u8*)tag + 0xc)) == 0) {
            *(s16*)((u8*)tag + 0x18) = 1;
            cTg_Addition__FP15node_list_classP16create_tag_class(lbl_80205658, tag);
            return 0;
        }
        return 1;
    }
    (*(s16*)((u8*)tag + 0x18))--;
    return 0;
}

extern "C" int fn_8001B73C(void* tag, void* data) {
    cTg_Create__FP16create_tag_classPv(tag, data);
    return 1;
}

extern "C" u32 fn_8001B65C(void);
extern "C" void fn_8001B760(void) {
    fn_8001B65C();
}

extern "C" void fn_8001E924(void*);
extern "C" s32 fn_8001ADB4(void*);
extern "C" void fn_8001BFA4(void*);
extern "C" s32 fn_8001B780(void* param_1) {
    void* p = *(void**)((u8*)param_1 + 0x60);
    fn_8001C008(p);
    fn_8001E924((u8*)param_1 + 0x34);
    if (fn_8001ADB4(param_1) == 1) {
        fn_8001BFA4(p);
        return 1;
    }
    return 0;
}

extern "C" int fn_8001BBBC(short* param_1) {
    return (int)*param_1;
}

extern "C" void fn_8001BBC4(void* param_1, s16 param_2) {
    *(s16*)param_1 = param_2;
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

extern "C" void fn_8001EAE8(void* param_1, void* param_2);
extern "C" void fn_8001BEC4(void* param_1, void* param_2) {
    fn_8001EAE8((u8*)param_1 + 0x1c, param_2);
}

extern void* lbl_802056AC[];
extern "C" int fn_8001EABC(void);
extern "C" bool fn_8001BEE8(void) {
    return fn_8001EABC() == 1;
}

extern "C" void fn_8001BF14(void* param_1, s32 param_2, void* param_3, s32 param_4) {
    cTg_InsertToTree((node_lists_tree_class*)((u8*)param_1 + 0x10), param_2, (create_tag_class*)param_3, param_4);
}

extern "C" void fn_8001BF38(void* param_1, s32 param_2, void* param_3, s32 param_4) {
    cTg_InsertToTree((node_lists_tree_class*)((u8*)param_1 + 0x10), param_2, (create_tag_class*)param_3, param_4);
}

extern "C" s32 fn_8001BF5C(void* self, void* p) {
    return cTg_SingleCutFromTree__FP16create_tag_class(p);
}

extern "C" u32 fn_8001BF80(void* param_1) {
    s32 v = *(s16*)((u8*)param_1 + 0x2a);
    return (u32)((-v) & ~v) >> 31;
}

extern "C" void* fn_8001BFF8(void) {
    return lbl_802056AC[0];
}

extern "C" void fn_80115178(void*, void*, void*);
extern "C" void fn_8011580C(void);
#pragma push
#pragma dont_inline on
extern "C" void fn_8001C2C0(void* param_1) {
    fn_8001BBBC((short*)((u8*)param_1 + 0xbe));
}

extern "C" void fn_8001C2E4(void* param_1, void* param_2) {
    fn_8001D540(*(void**)((u8*)param_1 + 0x10), param_2);
}

#pragma pop
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

extern s8 lbl_802FEC38;
#pragma push
#pragma dont_inline on
extern "C" void fn_8001C3E0(void* param_1) {
    if (*(s8*)((u8*)param_1 + 0xc) == 0) {
        void* r31 = *(void**)((u8*)param_1 + 0x10);
        *(void**)((u8*)param_1 + 0xb8) = *(void**)((u8*)r31 + 0x1c);
        *(void**)((u8*)param_1 + 0xb4) = fn_8001AC84((void*)&lbl_802FEC38);
        fn_8001BBC4((u8*)param_1 + 0xbe, *(s16*)((u8*)r31 + 0x20));
        *(u8*)((u8*)param_1 + 0xbc) = 0;
    }
    fn_8001D630(*(void**)((u8*)param_1 + 0xb8), param_1);
}
#pragma pop
extern "C" void fn_8001C454(void* param_1, int param_2, int param_3) {
    int local[2];
    local[0] = param_2;
    local[1] = param_3;
    fn_80115178((u8*)param_1 + 0x10, (void*)fn_8011580C, local);
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

extern "C" void fn_8001D66C(void* param_1, void* param_2) {
    fn_8001D540(*(void**)((u8*)param_1 + 0x10), param_2);
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
    s32 p = (s32)param_1;
    if (p != 0) {
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

extern "C" void cTg_Addition__FP15node_list_classP16create_tag_class(void*, void*);
extern "C" void fn_8001EAE8(void* param_1, void* param_2) {
    cTg_Addition__FP15node_list_classP16create_tag_class(param_1, param_2);
}

extern "C" void fn_8001EB08(void) {
    cTg_SingleCut__FP16create_tag_class();
}

extern "C" u32 fn_8001EFE4(void) {
    return 2;
}

extern "C" void fn_8001F37C(void)
{
    extern s32 fragmentID;
    if (fragmentID != -2) {
        __unregister_fragment(fragmentID);
        fragmentID = 0;
    }
}

extern "C" f32 fn_8001F3AC(void)
{
    extern f32 lbl_802FFCC0;
    
    void* ptr = lbl_802B7CA0;
    if (*(u8*)((u8*)ptr + 0x1418) != 0) {
        s8 idx = *(s8*)((u8*)ptr + 0x13c0);
        ptr = *(void**)((u8*)ptr + idx * 0x34 + 0x13e4);
    } else {
        ptr = NULL;
    }
    
    if (ptr != NULL) {
        return *(f32*)((u8*)ptr + 0xc8);
    } else {
        return lbl_802FFCC0;
    }
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

extern "C" void fn_80020340(void) {}

extern "C" void* fn_80020344(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80020380(void) {}

extern "C" void fn_800204F0(void) {}

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

extern "C" int fn_80020F94()
{
	return 0;
}

