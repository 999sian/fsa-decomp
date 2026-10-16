#include "Game/esd/types.h"


extern "C" u8 fn_80204D44(u8* param_1);
extern "C" void __ct__Q29JGeometry8TVec3_f_Fv();
extern "C" void __construct_array(void*, void*, void*, u32, u32);
extern "C" u8 lbl_8053AC58;
extern "C" u8 lbl_804CADE0[];
extern "C" void* fn_80204638(void)
{
    u8* base;

    if (lbl_8053AC58 == 0) {
        base = lbl_804CADE0;
        base[0] = 0;
        *(u32*)(base + 0x54) = 0;
        __construct_array(base + 0x58, (void*)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 0xa);
        base = lbl_804CADE0;
        base[0] = 0;
        *(u32*)(base + 0x4) = 0;
        *(u32*)(base + 0x8) = 0;
        *(u32*)(base + 0xc) = 0;
        *(u32*)(base + 0x10) = 0;
        *(u32*)(base + 0x14) = 0;
        *(u32*)(base + 0x18) = 0;
        *(u32*)(base + 0x1c) = 0;
        *(u32*)(base + 0x20) = 0;
        *(u32*)(base + 0x24) = 0;
        *(u32*)(base + 0x28) = 0;
        *(u32*)(base + 0x2c) = 0;
        *(u32*)(base + 0x30) = 0;
        *(u32*)(base + 0x34) = 0;
        *(u32*)(base + 0x38) = 0;
        *(u32*)(base + 0x3c) = 0;
        *(u32*)(base + 0x40) = 0;
        *(u32*)(base + 0x44) = 0;
        *(u32*)(base + 0x48) = 0;
        *(u32*)(base + 0x4c) = 0;
        *(u32*)(base + 0x50) = 0;
        lbl_8053AC58 = 1;
    }
    return lbl_804CADE0;
}

extern "C" int __float_max[];
extern "C" const f32 lbl_8053F838;
extern "C" const f32 lbl_8053F83C;
extern "C" u8 fn_801CB85C(void* a, void* b, f32* c, f32 x, f32 y);
extern "C" u32 fn_802046FC(u8* param_1, void* param_2, f32* param_3) {
    f32 local[2];
    u8* p;
    f32 best;
    f32 dx;
    f32 dy;
    f32 d;
    s32 count;
    s32 idx;
    s32 i;
    u32 ret;

    count = *(s32*)(param_1 + 0x54);
    if (count >= 10) {
        return 0;
    }
    ret = 0;
    if (count >= 1) {
        local[0] = param_3[0];
        local[1] = param_3[1];
        idx = 0;
        if (*(s32*)(param_1 + 0x54) > 1) {
            best = *(f32*)&__float_max;
            p = param_1;
            for (i = 0; i < *(s32*)(param_1 + 0x54); i++, p += 0xc) {
                dy = *(f32*)(p + 0x5c) - param_3[1];
                dx = *(f32*)(p + 0x58) - param_3[0];
                d = dx * dx + dy * dy;
                if (d < best) {
                    best = d;
                    idx = i;
                }
            }
        }
        ret = fn_801CB85C(param_1 + idx * 0xc + 0x58, param_2, local, lbl_8053F838, lbl_8053F83C);
        if ((ret & 0xff) != 0) {
            param_3[0] = local[0];
            param_3[1] = local[1];
        }
    }
    p = param_1 + *(s32*)(param_1 + 0x54) * 0xc + 0x58;
    ((f32*)p)[0] = param_3[0];
    ((f32*)p)[1] = param_3[1];
    ((f32*)p)[2] = param_3[2];
    *(s32*)(param_1 + 0x54) = *(s32*)(param_1 + 0x54) + 1;
    return ret;
}

extern "C" void fn_80204834(u8* param_1) {
    for (int i = 0; i < 2; i++) {
        for (int j = 4; j <= 0x28; j += 4) {
            u8* p = *(u8**)(param_1 + j);
            if (p) {
                p[0x11c] = 0;
            }
        }
        param_1 += 0x28;
    }
}

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802048F4(u8* param_1) {
    u8* mgr = (u8*)fn_802D6A9C();
    for (s32 i = 0; i < 10; i++) {
        for (s32 j = 0; j < 2; j++) {
            u8* p = *(u8**)(param_1 + i * 8 + j * 4 + 4);
            if (p != NULL && p[0x11c] != 0 && *(s32*)(p + 4) == 0) {
                bool inside = false;
                if (*(f32*)(p + 0xc) >= *(f32*)(mgr + 0xcc) && *(f32*)(p + 0x10) >= *(f32*)(mgr + 0xd0) &&
                    *(f32*)(p + 0xc) < *(f32*)(mgr + 0xd4) && *(f32*)(p + 0x10) < *(f32*)(mgr + 0xd8)) {
                    inside = true;
                }
                if (!inside && fn_80204D44(p) == 0) {
                    p[0x11c] = 0;
                }
            }
        }
    }
}

extern "C" void fn_802049E0(u8* param_1, u8* param_2) {
    u8** slot = (u8**)(param_1 + ((u32)param_2[0x34a] & 0xff) * 8 + 4);
    if (slot[0] == param_2) {
        slot[0] = 0;
        return;
    }
    if (slot[1] == param_2) {
        slot[1] = 0;
    }
}

extern "C" void fn_80204A20(u8* param_1, u8* param_2) {
    u8** slot = (u8**)(param_1 + ((u32)param_2[0x34a] & 0xff) * 8 + 4);
    if (slot[0] == 0) {
        slot[0] = param_2;
        if (slot[1] != 0 && fn_80204D44(slot[1])) {
            param_2[0x11c] = 0;
        }
    } else if (slot[1] == 0) {
        slot[1] = param_2;
        if (slot[0] != 0 && fn_80204D44(slot[0])) {
            param_2[0x11c] = 0;
        }
    }
}

extern "C" void fn_80204ABC(u8* param_1, u8 param_2) {
    if (param_2 == 0) {
        return;
    }
    *param_1 = 0;
    for (int i = 1; i <= 20; i++) {
        ((u32*)param_1)[i] = 0;
    }
}

