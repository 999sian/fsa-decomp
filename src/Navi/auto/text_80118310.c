#include "types.h"
#include "types.h"
#include <cstring>

extern "C" void fn_8011C280(int);
extern "C" void* fn_8015A90C(u32);
extern "C" void fn_8011AC74(void*, s32, s32, u16, u16);
extern void* lbl_802FF328;
extern void* lbl_802FF2B0;
extern void* lbl_802FF544;
extern "C" void fn_8011C3C8(u32);
extern u32* lbl_802C5FBC[];
extern "C" BOOL OSGetResetSwitchState(void);
extern f32 lbl_80301540;
extern u8 lbl_802FF2E8;
extern u8 lbl_802FF2E9;
extern s32 lbl_802FF2EC;
extern s32 lbl_802FF2D8;
extern void (*lbl_802FF2D4)(s32, s32);
extern u8 lbl_802FF2B8;
extern u8 lbl_802FF2BC[4];
extern s32 lbl_802FF2C4;
extern u32 lbl_8029016C[];
extern "C" void fn_801CE1B8(int);
extern "C" void fn_801CE970(int);
extern "C" void fn_801CDCB0(void);
extern "C" void fn_80166C70(void*);
extern "C" void fn_80166FC4(void*, void*);
extern "C" void fn_80166B70(void*, int);
extern "C" void fn_8015D0B8(void*, int);

extern "C" void fn_80166C08(void*, int);
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_801670D0(int, void*, int);
extern "C" void fn_80118B58(void*, int, int);

extern "C" void fn_8015AB40(void*);
extern "C" void fn_801196E0(void*);
extern "C" void fn_8011972C(void* p, u8* src);
extern "C" u8 fn_80119AD4(void*);
extern "C" void fn_80119A04(void*);
extern "C" void fn_80119A28(void*);
extern u8 lbl_802900DC[];
extern u8 lbl_80283F48[];

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80118310-0x8011c4b8 (86 functions). split_file divides it into the game's real files.

extern "C" void fn_80166C08(void*, int);
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_801670D0(int, void*, int);
extern "C" void fn_80118B58(void*, int, int);
extern "C" void* fn_80118310(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80118364(void* param_1) {
    *(float*)((char*)param_1 + 0x54) = 1.0f;
    *(float*)((char*)param_1 + 0x58) = 100000.0f;
}

extern "C" BOOL fn_801189F4(void);
extern "C" BOOL fn_801189F4(void)
{
    return TRUE;
}

extern "C" void fn_801189FC(char *param_1, int param_2, int param_3, int param_4) {
    fn_801670D0(param_2, param_1, 1);
    fn_801670D0(param_2, param_1 + 1, 1);
    fn_801670D0(param_2, param_1 + 2, (u32)(u8)param_1[1]);
    
    u8 b0 = (u8)param_1[0];
    if ((unsigned)b0 == 2 || (unsigned)b0 == 3 || (unsigned)b0 == 4) {
        register u8 b1 = (u8)param_1[1];
        param_1[b1 + 2] = 0;
    }
    fn_80118B58(param_1, param_3, param_4);
}

extern "C" void fn_80118AB4(char *param_1, char *param_2, int param_3, int param_4) {
    u8 byte1 = (u8)param_2[1];
    u8 byte0 = (u8)param_2[0];
    param_1[0] = (char)byte0;
    param_1[1] = (char)byte1;
    
    u8 stored_byte1 = (u8)param_1[1];
    if (stored_byte1 != 0) {
        memcpy(param_1 + 2, param_2 + 2, stored_byte1);
    }
    
    u8 stored_byte0 = (u8)param_1[0];
    if (stored_byte0 == 2 || stored_byte0 == 3 || stored_byte0 == 4) {
        u8 b1 = (u8)param_1[1];
        param_1[b1 + 2] = 0;
    }
    fn_80118B58(param_1, param_3, param_4);
}

extern "C" void fn_801196B4(void* p) {
    char* c = (char*)p;
    *(void**)p = lbl_80283F48;
    *(s32*)(c + 0xc) = -1;
    *(s32*)(c + 0x10) = -1;
    *(s32*)(c + 0x14) = -1;
    *(s32*)(c + 0x18) = -1;
    *(u8*)(c + 0x4) = 0;
}

extern "C" void fn_8011972C(void* p, u8* src) {
    u8 b3 = src[3];
    u8 b2 = src[2];
    u8 b1 = src[1];
    u8 b0 = src[0];
    u8* d = (u8*)p;
    d[0xc] = b0;
    d[0xd] = b1;
    d[0xe] = b2;
    d[0xf] = b3;
    d[0x10] = b0;
    d[0x11] = b1;
    d[0x12] = b2;
    d[0x13] = b3;
    d[0x14] = b0;
    d[0x15] = b1;
    d[0x16] = b2;
    d[0x17] = b3;
    d[0x18] = b0;
    d[0x19] = b1;
    d[0x1a] = b2;
    d[0x1b] = b3;
}

extern "C" void fn_80119780(void* p, u8* a, u8* b) {
    u8 a0 = a[0];
    u8 a1 = a[1];
    u8 a2 = a[2];
    u8 a3 = a[3];
    u8 b0 = b[0];
    u8 b1 = b[1];
    u8 b2 = b[2];
    u8 b3 = b[3];
    u8* d = (u8*)p;
    d[0xc] = a0;
    d[0xd] = a1;
    d[0xe] = a2;
    d[0xf] = a3;
    d[0x10] = a0;
    d[0x11] = a1;
    d[0x12] = a2;
    d[0x13] = a3;
    d[0x14] = b0;
    d[0x15] = b1;
    d[0x16] = b2;
    d[0x17] = b3;
    d[0x18] = b0;
    d[0x19] = b1;
    d[0x1a] = b2;
    d[0x1b] = b3;
}

extern "C" void* fn_80119978(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_802900DC;
        if (((u8*)param_1)[4] != 0) {
            fn_80119A04(param_1);
            fn_80119A28(param_1);
            fn_801196E0(param_1);
        }
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80283F48;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80119A04(void* param_1) {
    fn_8015AB40(*(void**)((u8*)param_1 + 0x50));
}

extern "C" void fn_80119A28(void* param_1) {
    u8* p = (u8*)param_1;
    *(u32*)(p + 0x48) = 0;
    *(u32*)(p + 0x50) = 0;
    *(u32*)(p + 0x54) = 0;
    *(u32*)(p + 0x58) = 0;
    *(u32*)(p + 0x5c) = 0;
    *(u32*)(p + 0x1c) = 0;
    *(u32*)(p + 0x20) = 0;
    *(s32*)(p + 0x44) = -1;
}

extern "C" BOOL fn_80119A54(void* param_1) {
    if (fn_80119AD4(param_1) == 0) {
        fn_8015AB40(*(void**)((u8*)param_1 + 0x50));
        *(u32*)((u8*)param_1 + 0x48) = 0;
        *(u32*)((u8*)param_1 + 0x50) = 0;
        *(u32*)((u8*)param_1 + 0x54) = 0;
        *(u32*)((u8*)param_1 + 0x58) = 0;
        *(u32*)((u8*)param_1 + 0x5c) = 0;
        *(u32*)((u8*)param_1 + 0x1c) = 0;
        *(u32*)((u8*)param_1 + 0x20) = 0;
        *(s32*)((u8*)param_1 + 0x44) = -1;
        fn_801196E0(param_1);
        *((u8*)param_1 + 4) = 0;
        return FALSE;
    }
    return TRUE;
}

extern "C" int fn_8011AB38()
{
	return 0;
}

extern "C" BOOL fn_8011AB40(void)
{
    return TRUE;
}

extern "C" void* fn_8011B0D8(u8* p, s16 del) {
    if (p) {
        *(u32*)p = (u32)lbl_8029016C;
        s16 idx = *(s16*)(p + 0x7c);
        if (idx >= 0) {
            lbl_802FF2BC[idx]--;
            *(s16*)(p + 0x7c) = -1;
        }
        fn_80166FC4(lbl_802C5FBC, p + 0x80);
        if (p + 0x80) {
            fn_80166B70(p + 0x80, 0);
        }
        fn_8015D0B8(p, 0);
        if (del > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void fn_8011B184(void) {
    if (lbl_802FF2B8 == 0) {
        fn_80166C70(lbl_802C5FBC);
        lbl_802FF2B8 = 1;
    }
}

extern "C" void fn_8011B1C0(void) {
    fn_801CE1B8(5);
    lbl_802FF2C4 = 3;
    fn_801CE970(3);
    fn_801CDCB0();
}

extern "C" void fn_8011B1F8(u8* p) {
    p[0x98] = 0;
    p[0xa8] = 1;
}

extern "C" void fn_8011B8F8(void) {
    if (lbl_802FF2E9 == 0) {
        if (OSGetResetSwitchState() != 0) {
            lbl_802FF2E8 = 1;
        } else {
            if (lbl_802FF2E8 == 1) {
                void (*fn)(s32, s32) = lbl_802FF2D4;
                lbl_802FF2E9 = 1;
                lbl_802FF2EC = -1;
                if (fn != NULL) {
                    fn(-1, lbl_802FF2D8);
                }
            }
            lbl_802FF2E8 = 0;
        }
    }
}

extern "C" void fn_8011B978(void) {
    fn_8011C280(0);
    fn_8011C3C8(0xf0000000);
}

extern "C" void fn_8011B9A4(void* param_1) {
    char* p = (char*)param_1;
    *(s32*)(p + 0x0) = 0;
    *(s32*)(p + 0x4) = 0;
    *(s32*)(p + 0x8) = 0;
    *(s32*)(p + 0x18) = 0;
    *(u8*)(p + 0xc) = 0;
    *(u8*)(p + 0xd) = 0;
    *(u8*)(p + 0xe) = 0;
    *(u8*)(p + 0xf) = 0;
    *(s32*)(p + 0x1c) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2c) = 0;
}

extern "C" void fn_8011BB70(void* param_1) {
    f32 v = lbl_80301540;
    *(f32*)((char*)param_1 + 0x0) = v;
    *(f32*)((char*)param_1 + 0x4) = v;
    *(f32*)((char*)param_1 + 0x8) = v;
    *(s16*)((char*)param_1 + 0xc) = 0;
}

extern "C" void* fn_8011C244(s32 id) {
    u32** list = lbl_802C5FBC;
    u32* p;

    for (p = *list; p != 0; p = (u32*)p[3]) {
        char* obj = (char*)p[0];
        if (id == *(s16*)(obj + 0x7c)) {
            return obj;
        }
    }
    return 0;
}

