#include "types.h"
#include <dolphin/gx.h>
extern "C" {
extern const f32 lbl_8053F65C;
extern const f32 lbl_8053F660;
extern const f32 lbl_8053F664;
extern s8 lbl_8053AC50;
extern u8 lbl_804CA358[];
extern u8 lbl_80469C78[];
extern f32 sincosTable___5JMath[];

void* fn_801F856C(void);
s32 fn_801F7F58(void* a, void* b, void* c, s32 d, f32 e);
void* fn_801F666C(void* a, s32 b);
u8 fn_801CC8E4(void);
void fn_802BAA00(void* p);
void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
void fn_801E9B54(void);
void fn_801E8C74(void* a, s32 b);
s32 fn_801EA8C0(u8* param_1, u8* param_2);
void qsort(void* base, size_t nmemb, size_t size, s32 (*compar)(void*, void*));
}

extern "C" void* fn_801E9AFC(void) {
    if (lbl_8053AC50 == 0) {
        __construct_array(lbl_804CA358, (void*)fn_801E9B54, NULL, 0x78, 2);
        lbl_8053AC50 = 1;
    }
    return lbl_804CA358;
}

extern "C" void fn_801E9B54(void) {
}

extern "C" s32 fn_801E9B58(u8* param_1) {
    s32 iVar2;

    iVar2 = fn_801F7F58(fn_801F856C(), param_1, lbl_80469C78, *(s32*)(param_1 + 0x198), lbl_8053F65C);
    if (iVar2 >= 0 && iVar2 != *(s32*)(param_1 + 0x198)) {
        param_1 = (u8*)fn_801F666C(fn_801F856C(), iVar2);
        if (param_1 != NULL) {
            if (fn_801CC8E4() != 0) {
                iVar2 = -1;
            } else if (*(u32*)(param_1 + 0x1a0) == 0x46495245) {
                fn_802BAA00(param_1);
            }
        }
    }
    return iVar2;
}

extern "C" void fn_801E9C00(s16 param_1, f32* param_2) {
    s16 sVar3;
    u32 uVar2;
    f32* pt;
    f32 fx;
    f32 fy;

    param_2[0] = lbl_8053F660;
    param_2[1] = lbl_8053F664;
    sVar3 = 0x2000;
    if (param_1 < 0) {
        sVar3 = -0x2000;
    }
    uVar2 = ((u32)(-(s32)(s16)(param_1 + sVar3)) >> 2) & 0x3ff8;
    pt = (f32*)((u8*)sincosTable___5JMath + uVar2);
    fx = param_2[0];
    fy = param_2[1];
    param_2[0] = fx * pt[1] - fy * pt[0];
    param_2[1] = fy * pt[1] + fx * pt[0];
}

extern "C" void fn_801EA304(u8* param_1) {
    GXLoadTlut((GXTlutObj*)(param_1 + 0x160), 0);
    GXLoadTexObj((GXTexObj*)(param_1 + 0x114), GX_TEXMAP0);
}

extern "C" void fn_801EA344(u8* param_1) {
    GXLoadTlut((GXTlutObj*)(param_1 + 0x154), 0);
    GXLoadTexObj((GXTexObj*)(param_1 + 0xf4), GX_TEXMAP0);
}

extern "C" s32 fn_801EA6D8(u8* param_1, u8 param_2, s32 param_3) {
    u8* entry;
    s32 result = -1;
    s32 i;
    s32 count;
    u8* p;

    if (param_2 == 0) {
        u8* slot = param_1 + *(s32*)(param_1 + 0x74) * 4;
        *(s32*)(slot + 0x64) = param_3;
        *(s32*)(param_1 + 0x74) = *(s32*)(param_1 + 0x74) + 1;
    } else {
        count = *(s32*)(param_1 + 0x60);
        entry = param_1;
        for (i = 0; i < count; i++) {
            if (param_2 == entry[4]) {
                *(s32*)(param_1 + i * 0xc + 8) = param_3;
                p = *(u8**)(param_1 + i * 0xc);
                if (p != NULL) {
                    result = *(s32*)(p + 0x198);
                }
                break;
            }
            entry += 0xc;
        }
    }
    return result;
}

extern "C" s32 fn_801EA8C0(u8* param_1, u8* param_2) {
    s32 result = 0;
    u8 a = param_1[4];
    u8 b = param_2[4];

    if (a < b) {
        return -1;
    }
    if (a > b) {
        result = 1;
    }
    return result;
}

