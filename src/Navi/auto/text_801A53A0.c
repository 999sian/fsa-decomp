#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801a53a0-0x801a7b40 (33 functions). split_file divides it into the game's real files.

struct VObj_801A7A38 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
};

extern "C" void fn_801E10DC(void* p);
extern u8 lbl_8029B188[];

extern "C" void fn_801A59E8(void);
extern "C" void fn_801E012C(void);
extern "C" void fn_801A66A8(u8* param_1, s32 param_2);
extern "C" void fn_801A670C(u8* param_1, s32 param_2);
extern "C" void fn_801A676C(u8* param_1, s32 param_2, u8 param_3);
extern "C" void fn_801A6CEC(u8* param_1, s32 param_2);
extern u8 lbl_802F0408[];
extern u8 lbl_802EE470[];
extern u32* lbl_802FFA80;
extern "C" void fn_8018F6A4(u32 a, f32 b, f32 c, f32 d);
extern "C" void fn_8018F27C(u32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g);
extern "C" void fn_8018F594(u32 a, u32* b);
extern "C" void fn_8018F890(u32 a, f32 b, f32 c, f32 d);
extern "C" void fn_801A53A0(u8* param_1, u32 param_2) {
    extern u32* lbl_802FFA80;
    u32 local;
    u32 mask;
    if ((lbl_802FFA80[2] + 0x48) > lbl_802FFA80[3]) {
        fn_801E012C();
    }
    mask = 1 << param_2;
    fn_8018F6A4(mask, *(f32*)(param_1 + 0x0), *(f32*)(param_1 + 0x4), *(f32*)(param_1 + 0x8));
    fn_8018F27C(mask, *(f32*)(param_1 + 0x1c), *(f32*)(param_1 + 0x20), *(f32*)(param_1 + 0x24), *(f32*)(param_1 + 0x28), *(f32*)(param_1 + 0x2c), *(f32*)(param_1 + 0x30));
    local = *(u32*)(param_1 + 0x18);
    fn_8018F594(mask, &local);
    fn_8018F890(mask, *(f32*)(param_1 + 0xc), *(f32*)(param_1 + 0x10), *(f32*)(param_1 + 0x14));
}

extern "C" void fn_801A598C(u8* param_1, s32 param_2) {
    if (*(u32*)(lbl_802EE470 + 0x34) & 0x40000000) {
        fn_801A670C(param_1, param_2);
    } else {
        fn_801A66A8(param_1, param_2);
    }
}

extern "C" void fn_801A59C8(void) {
    fn_801A59E8();
}

extern "C" BOOL fn_801A602C(u8* param_1) {
    if (param_1[1] >= 0x80 && param_1[1] <= 0xBB) {
        return TRUE;
    }
    return FALSE;
}

extern "C" void fn_80190684(void* param_1, u16 param_2);
extern u8 lbl_802EE470[];
extern "C" u16 fn_801A6050(void* param_1) {
    return *(u32*)((u8*)param_1 + 1);
}

extern "C" void fn_801A6214(void* param_1, const u16* param_2) {
    fn_80190684(param_1, param_2[0]);
}

extern "C" void fn_801A6238(u8* param_1) {
    if (*param_1 == 1) {
        *(u8**)(lbl_802EE470 + 0x118) = param_1 + 4;
    } else {
        *(u8**)(lbl_802EE470 + 0x118) = NULL;
    }
}

extern "C" void fn_801A6664(void) {
    u8* p = lbl_802F0408;
    s32 i = 0;
    do {
        p[0] = i >> 6;
        p[1] = (i >> 4) & 3;
        p[2] = (i >> 2) & 3;
        p[3] = i & 3;
        i++;
        p += 4;
    } while (i < 0x100);
}

extern "C" void fn_801A66A8(u8* param_1, s32 param_2) {
    if ((u32)(lbl_802FFA80[2] + 0x35) > (u32)lbl_802FFA80[3]) {
        fn_801E012C();
    }
    fn_801A676C(param_1 + 0x64, param_2 * 3 + 0x1e, *param_1);
}

extern "C" void fn_801A670C(u8* param_1, s32 param_2) {
    if ((u32)(lbl_802FFA80[2] + 0x35) > (u32)lbl_802FFA80[3]) {
        fn_801E012C();
    }
    fn_801A6CEC(param_1 + 0x64, param_2 * 3 + 0x40);
}

extern f32 lbl_80301D38;
extern f32 lbl_80301D3C;
extern f64 lbl_80301D40;
extern "C" int fn_8015AA60(int a, int b);
extern "C" void fn_801A73A4(u8* p);
extern "C" void fn_801A7258(u8* param_1) {
    *(u32*)(param_1 + 0x8) = 0;
    *(u32*)(param_1 + 0xc) = 0;
    *(f32*)(param_1 + 0x10) = lbl_80301D38;
    *(f32*)(param_1 + 0x14) = lbl_80301D3C;
    *(u32*)(param_1 + 0x1c) = 0;
    *(u32*)(param_1 + 0x20) = 0;
    *(u32*)(param_1 + 0x4) = 0x20;
    *(f32*)(param_1 + 0x18) = (*(f32*)(param_1 + 0x14) - *(f32*)(param_1 + 0x10)) / (f32)*(u32*)(param_1 + 0x4);
}

extern "C" void fn_8015AB40(void* p);
extern "C" void fn_8015AB1C(void* p);
extern "C" void fn_801A73A4(u8* p);
extern "C" void fn_80193E40(u32 a, u8* b);
extern "C" u32* fn_801A7344(u32* param_1, s16 param_2) {
    if (param_1 != NULL) {
        fn_801A73A4((u8*)param_1);
        fn_8015AB40(*(void**)param_1);
        param_1[0] = 0;
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" BOOL fn_801A78EC(u8* param_1, u8* param_2) {
    *(u32*)(param_2 + 4) = 0;
    *(u32*)(param_2 + 8) = 0;
    u8* p = *(u8**)(param_2 + 0x2c);
    *(u32*)(p + 4) = 0;
    *(u32*)(p + 8) = 0;
    if (*(u32*)(param_1 + 0x20) != 0) {
        fn_80193E40(*(u32*)(param_1 + 0x20), param_2);
        return TRUE;
    }
    return FALSE;
}

extern "C" BOOL fn_801A793C(u8* param_1, u8* param_2) {
    *(u32*)(param_2 + 4) = 0;
    *(u32*)(param_2 + 8) = 0;
    u8* p = *(u8**)(param_2 + 0x2c);
    *(u32*)(p + 4) = 0;
    *(u32*)(p + 8) = 0;
    u32 v = *(u32*)(param_1 + 0x20);
    if (v != 0) {
        fn_80193E40(v, *(u8**)(param_2 + 0x2c));
        return TRUE;
    }
    return FALSE;
}

extern "C" BOOL fn_801A7990(u32** param_1, u32* param_2) {
    param_2[1] = 0;
    param_2[2] = 0;
    u32* p = (u32*)param_2[11];
    p[1] = 0;
    p[2] = 0;
    param_2[1] = (*param_1)[0];
    (*param_1)[0] = (u32)param_2;
    return TRUE;
}

extern "C" BOOL fn_801A79C4(u32** param_1, u32* param_2, u16 param_3) {
    param_2[1] = (*param_1)[param_3];
    (*param_1)[param_3] = (u32)param_2;
    return TRUE;
}

extern "C" void fn_801A79E4(u8* param_1) {
    fn_801E10DC(param_1);
}

extern "C" void fn_801A7A38(u32* param_1) {
    u32** arr;
    u32 count;
    u32 i;
    u32* node;
    arr = (u32**)param_1[0];
    count = param_1[1];
    for (i = 0; i < count; arr++, i++) {
        node = *arr;
        while (node != NULL) {
            ((VObj_801A7A38*)node)->v1();
            node = (u32*)node[1];
        }
    }
}

extern "C" void fn_801A7ABC(u32* param_1) {
    u32 count;
    u32** arr;
    u32** p;
    s32 i;
    count = param_1[1];
    arr = (u32**)param_1[0];
    i = count - 1;
    p = arr + i;
    for (; i >= 0; p--, i--) {
        u32* node = *p;
        while (node != NULL) {
            ((VObj_801A7A38*)node)->v1();
            node = (u32*)node[1];
        }
    }
}

