#include "dolphin/types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80021184-0x800226e8 (25 functions). split_file divides it into the game's real files.

extern "C" void fn_8011526C(void);
extern "C" void fn_800632A8(void*, s32);
extern "C" void fn_8006058C(void*, s32);
extern "C" void fn_80020304(void);
extern "C" void fn_80020344(void);
extern "C" void fn_801E0D40(void*, void*, s32, s32);
extern "C" void fn_8015AB1C(void*);
extern "C" void* fn_800638A4(void*, void*, void*, s32);
extern "C" void fn_80010A58(void*, void*, void*, f32, f32, f32, f32);
extern u8 lbl_802B7CA0[];
extern u8 lbl_802BB0FC[];
extern "C" void fn_80021220(void) {
    fn_8011526C();
}

extern "C" s32 fn_8002185C(void) {
    s32 count = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (*(u32*)(lbl_802B7CA0 + 0x3440) & (1 << i)) {
            count++;
        }
    }
    return count;
}

extern "C" s32 fn_800218C4(void) {
    s32 count = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (*(u32*)(lbl_802B7CA0 + 0x3444) & (1 << i)) {
            count++;
        }
    }
    return count;
}

extern "C" s32 fn_8002192C(void) {
    s32 count = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (*(u32*)(lbl_802B7CA0 + 0x3448) & (1 << i)) {
            count++;
        }
    }
    return count;
}

extern "C" s32 fn_80021994(void) {
    u8 mask = lbl_802BB0FC[0xee];
    u8 i;
    for (i = 0; i < 4; i++) {
        if ((u8)(mask & (1 << i))) {
            return i;
        }
    }
    return -1;
}

extern u8 lbl_802B7CA0[];
extern char* lbl_8020631C[];
extern char* lbl_80206200[];
extern char lbl_802FBCB4[4];
extern "C" void fn_801E6768(void*, char*);
extern "C" void fn_801E66C0(void*, char*);
extern "C" void fn_800219D8(u8* param_1, s32 param_2, void* param_3, s32 param_4) {
    char** table;
    if (param_4 == 0) {
        table = lbl_80206200;
    } else {
        table = lbl_8020631C;
    }
    if (param_1[param_2 * 0x4c + 0x1e8] >= 0x47) {
        fn_801E6768(param_3, lbl_802FBCB4);
    } else {
        fn_801E6768(param_3, table[param_1[param_2 * 0x4c + 0x1e8]]);
    }
    if (param_1[param_2 * 0x4c + 0x1e9] >= 0x47) {
        fn_801E66C0(param_3, lbl_802FBCB4);
    } else {
        fn_801E66C0(param_3, table[param_1[param_2 * 0x4c + 0x1e9]]);
    }
}

extern "C" void fn_80021A98(void* param_1, u8* param_2, char* param_3, s32 param_4) {
    char** table = param_4 == 0 ? lbl_80206200 : lbl_8020631C;
    param_3[0] = 0;
    if (param_2[0] >= 0x47) {
        fn_801E6768(param_3, lbl_802FBCB4);
    } else {
        fn_801E6768(param_3, table[param_2[0]]);
    }
    if (param_2[1] >= 0x47) {
        fn_801E66C0(param_3, lbl_802FBCB4);
    } else {
        fn_801E66C0(param_3, table[param_2[1]]);
    }
}

extern "C" void fn_80021B4C(void* param_1, char* param_2, u16* param_3, s32 param_4) {
    char** table = param_4 == 0 ? lbl_80206200 : lbl_8020631C;
    s32 i;
    for (i = 0; i < 2; i++) {
        char** p = table;
        char cVar3 = 0;
        s32 n = 0x47;
        do {
            if (*(u16*)*p == *param_3) {
                break;
            }
            p++;
            cVar3++;
        } while (--n != 0);
        *param_2 = cVar3;
        param_3++;
        param_2++;
    }
}

extern u8 lbl_802BB0FC[];
extern char* lbl_8020631C[];
extern char* lbl_80206200[];
extern char lbl_802FBCB4[];
extern "C" void fn_801E6768(void*, char*);
extern "C" void fn_801E66C0(void*, char*);
extern "C" s32 fn_80021C6C(u8* param_1, u8 param_2) {
    s32 count = 0;
    s32 n = *(s32*)(param_1 + 0x3f0);
    u8 mask = lbl_802BB0FC[0xee];
    s32 i;
    for (i = 0; i < n; i++) {
        u8 uVar3 = param_1[0x470 + i] & 0xf;
        if (uVar3 == 4) {
            u8 uVar2;
            s32 r;
            for (uVar2 = 0; uVar2 < 4; uVar2++) {
                if ((u8)(mask & (1 << uVar2)) != 0) {
                    r = uVar2;
                    goto found;
                }
            }
            r = -1;
found:
            uVar3 = r;
        }
        if (uVar3 == param_2) {
            count++;
        }
    }
    return count;
}

extern "C" void fn_80022434(void) {}

