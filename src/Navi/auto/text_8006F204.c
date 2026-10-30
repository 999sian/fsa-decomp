#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8006f204-0x80070d28 (26 functions). split_file divides it into the game's real files.

extern void* lbl_80280CEC[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80132450(s16, s16, s16, void*);
extern "C" void* fn_800638A4(void* a, void* b, void* c, s32 d);
extern "C" void* fn_8011FD10(void);
extern "C" void fn_8011FD18(void* a, void* b, s32 c, ...);
extern "C" void fn_80007AB8(void* a, s32 b, ...);
extern "C" s32 fn_8000E124(void* a, void* b, void* c, s32 d, s32 e, s32 f, s32 g, f32 h);
extern "C" u8 lbl_802B7CA0[];
extern "C" u8 lbl_802FC9D8[4];
extern "C" u8 lbl_802FC9E0;
extern "C" u8 lbl_802FC9E4;
extern "C" u8 lbl_80280920[];
extern "C" u8 lbl_80280AC0[];
extern "C" const f32 lbl_803004D8;
#pragma use_lmw_stmw off
extern "C" bool fn_8006FA3C(u8* param_1, void* param_2) {
    u8* p = *(u8**)(*(u8**)(*(u8**)(param_1 + 0x24c) + 4) + 4);
    void* r = fn_800638A4(&lbl_802FC9D8, param_2, lbl_802B7CA0 + 0x2200, 0x40);
    if (r == 0) {
        void* uVar2 = fn_8011FD10();
        fn_8011FD18(uVar2, lbl_80280920, 0xf9, (s32)&lbl_802FC9E0, lbl_80280AC0);
        fn_80007AB8(lbl_80280920, 0xf9, (s32)&lbl_802FC9E4);
    }
    if (fn_8000E124(param_1 + 0x250, p + 0x58, r, 1, 2, 0, -1, lbl_803004D8) == 0) {
        return false;
    }
    return true;
}
#pragma use_lmw_stmw reset
extern "C" u8 lbl_80280ACC[];
extern "C" s32 fn_8000D798(void* a, void* b, void* c, s32 d, s32 e, s32 f, s32 g, f32 h);
extern "C" bool fn_8006FB14(u8* param_1) {
    u8* p = *(u8**)(*(u8**)(*(u8**)(param_1 + 0x24c) + 4) + 4);
    void* r = fn_800638A4(&lbl_802FC9D8, 0, lbl_802B7CA0 + 0x2200, 0x40);
    if (r == 0) {
        void* uVar2 = fn_8011FD10();
        fn_8011FD18(uVar2, lbl_80280920, 0x10b, (s32)lbl_802FC9E0, lbl_80280ACC);
        fn_80007AB8(lbl_80280920, 0x10b, (s32)lbl_802FC9E4);
    }
    return fn_8000D798(param_1 + 0x25c, p + 0x58, r, 1, 2, 0, -1, lbl_803004D8) != 0;
}

extern "C" u8 lbl_80280AD8[];
extern "C" s32 fn_8000DE00(void* a, void* b, void* c, s32 d, s32 e, s32 f, s32 g, f32 h);
extern "C" BOOL fn_8006FBEC(void* param_1, void* param_2) {
    u8* p = *(u8**)(*(u8**)(*(u8**)((u8*)param_1 + 0x268) + 4) + 4);
    void* iVar1 = fn_800638A4(&lbl_802FC9D8, param_2, lbl_802B7CA0 + 0x2200, 0x40);
    if (iVar1 == 0) {
        void* uVar2 = fn_8011FD10();
        fn_8011FD18(uVar2, lbl_80280920, 0x11d, (s32)&lbl_802FC9E0, lbl_80280AD8);
        fn_80007AB8(lbl_80280920, 0x11d, (s32)&lbl_802FC9E4);
    }
    if (fn_8000DE00((u8*)param_1 + 0x26c, p + 0x58, iVar1, 1, 2, 0, -1, lbl_803004D8) == 0) {
        return FALSE;
    }
    return TRUE;
}

extern "C" BOOL fn_8006FCC4(void* param_1, void* param_2) {
    u8* p = *(u8**)(*(u8**)(*(u8**)((u8*)param_1 + 0x268) + 4) + 4);
    void* iVar1 = fn_800638A4(lbl_802FC9D8, param_2, lbl_802B7CA0 + 0x2200, 0x40);
    if (iVar1 == 0) {
        void* uVar2 = fn_8011FD10();
        fn_8011FD18(uVar2, lbl_80280920, 0x12f, (s32)&lbl_802FC9E0, lbl_80280AC0);
        fn_80007AB8(lbl_80280920, 0x12f, (s32)&lbl_802FC9E4);
    }
    s32 r = fn_8000E124((u8*)param_1 + 0x278, p + 0x58, iVar1, 1, 2, 0, -1, lbl_803004D8);
    if (r == 0) {
        return 0;
    }
    return 1;
}

#pragma use_lmw_stmw off
extern "C" bool fn_8006FD9C(u8* param_1, void* param_2) {
    u8* p = *(u8**)(*(u8**)(*(u8**)(param_1 + 0x268) + 4) + 4);
    void* r = fn_800638A4(&lbl_802FC9D8, param_2, lbl_802B7CA0 + 0x2200, 0x40);
    if (r == 0) {
        void* uVar2 = fn_8011FD10();
        fn_8011FD18(uVar2, lbl_80280920, 0x141, (s32)&lbl_802FC9E0, lbl_80280ACC);
        fn_80007AB8(lbl_80280920, 0x141, (s32)&lbl_802FC9E4);
    }
    if (fn_8000D798(param_1 + 0x284, p + 0x58, r, 1, 2, 0, -1, lbl_803004D8) == 0) {
        return false;
    }
    return true;
}

extern "C" bool fn_8006FE74(u8* param_1, void* param_2) {
    u8* p = *(u8**)(*(u8**)(*(u8**)(param_1 + 0x290) + 4) + 4);
    void* r = fn_800638A4(lbl_802FC9D8, param_2, lbl_802B7CA0 + 0x2200, 0x40);
    if (r == 0) {
        void* uVar2 = fn_8011FD10();
        fn_8011FD18(uVar2, lbl_80280920, 0x153, (s32)&lbl_802FC9E0, lbl_80280AC0);
        fn_80007AB8(lbl_80280920, 0x153, (s32)&lbl_802FC9E4);
    }
    if (fn_8000E124(param_1 + 0x294, p + 0x58, r, 1, 2, 0, -1, lbl_803004D8) == 0) {
        return false;
    }
    return true;
}

extern "C" void fn_8000D6F4(void* p);
extern "C" u8 fn_80010C6C(void* p, s32 a, s32 b, s32 c);
extern "C" const f32 lbl_803004C8;
extern "C" void fn_8006FF4C(u8* param_1) {
    fn_8000D6F4(param_1 + 0x250);
    fn_8000D6F4(param_1 + 0x26c);
    fn_8000D6F4(param_1 + 0x278);
    fn_8000D6F4(param_1 + 0x294);
    *(u8*)(param_1 + 0x2f4) = fn_80010C6C(*(void**)(param_1 + 0x24c), 0, 0, 0);
    if (*(f32*)(*(u8**)(param_1 + 0x24c) + 0x18) < lbl_803004C8) {
        if (*(f32*)(param_1 + 0x2e0) < *(f32*)(*(u8**)(param_1 + 0x24c) + 0x1c)) {
            *(u8*)(param_1 + 0x2f4) = 1;
        }
    } else if (*(f32*)(param_1 + 0x2e0) > *(f32*)(*(u8**)(param_1 + 0x24c) + 0x1c)) {
        *(u8*)(param_1 + 0x2f4) = 1;
    }
    *(f32*)(param_1 + 0x2e0) = *(f32*)(*(u8**)(param_1 + 0x24c) + 0x1c);
    fn_80010C6C(*(void**)(param_1 + 0x268), 0, 0, 0);
    fn_80010C6C(*(void**)(param_1 + 0x290), 0, 0, 0);
}

#pragma use_lmw_stmw reset

extern "C" void fn_80070454(void* ptr, u8 val)
{
    ((u8*)ptr)[0x2fa] = val;
    ((u8*)ptr)[0x2fb] = 0;
}

extern "C" void* fn_80070464(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_800704A0(void)
{
}

extern "C" BOOL fn_800704C4(void);
extern "C" void fn_800704A4(void) {
    fn_800704C4();
}

extern "C" BOOL fn_800704C4(void)
{
    return TRUE;
}

extern "C" int fn_8004D308(void* a, s32 b, s32 c, void* d, void* e, void* f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern "C" void fn_80024E70(void* a, s32 b);
extern void* lbl_802FF0BC;
extern "C" void fn_8007081C(void* param_1, u32* param_2) {
    u32 r;
    if (param_2[0] == 0) {
        if (lbl_802FF0BC != 0) {
            r = fn_8004D308(lbl_802FF0BC, 8, 0x6d, param_2 + 5, param_2 + 8, 0, 0xff, 0, 0, 0, 0);
        } else {
            r = 0;
        }
        param_2[0] = r;
    }
    if (param_2[1] == 0) {
        if (lbl_802FF0BC != 0) {
            r = fn_8004D308(lbl_802FF0BC, 8, 0x6e, param_2 + 5, param_2 + 8, 0, 0xff, 0, 0, 0, 0);
        } else {
            r = 0;
        }
        param_2[1] = r;
    }
    fn_80024E70(param_2 + 5, *(s16*)(param_2 + 9));
}

extern "C" void fn_800708F8(void* param)
{
    u8* base = (u8*)param;
    void** ptrs = (void**)param;
    s16 val0 = *(s16*)(base + 0x20);
    s16 val1 = *(s16*)(base + 0x22);
    s16 val2 = *(s16*)(base + 0x24);
    f32 fval0 = *(f32*)(base + 0x14);
    f32 fval1 = *(f32*)(base + 0x18);
    f32 fval2 = *(f32*)(base + 0x1c);
    
    for (int i = 0; i < 2; i++) {
        void* obj = ptrs[i];
        if (obj != NULL) {
            *(f32*)((u8*)obj + 0xa4) = fval0;
            *(f32*)((u8*)obj + 0xa8) = fval1;
            *(f32*)((u8*)obj + 0xac) = fval2;
            fn_80132450(val0, val1, val2, (u8*)obj + 0x68);
        }
    }
}

extern "C" void fn_800709B4(void* param_1, u8** param_2) {
    for (s32 i = 0; i < 2; i++) {
        u8* p = param_2[i];
        if (p != nullptr) {
            *(u32*)(p + 0xF4) |= 1;
            *(s32*)(p + 0x24) = 1;
            param_2[i] = nullptr;
        }
    }
}

extern "C" void fn_8004AE48(void);
extern "C" void fn_800636F4(void* a, void* b, s32 c);
extern "C" void fn_800127A0(void* a);
extern "C" u8 lbl_802FC9F8;
extern "C" u8 lbl_802C4E5C[];
extern "C" u8 lbl_8029FDB4[];
extern "C" BOOL fn_80070B88(void* param_1) {
    fn_8004AE48();
    s32* p = (s32*)((u8*)param_1 + 0x24c);
    s32 i;
    for (i = 0; i < 5; i++) {
        u8* a = (u8*)p[0];
        if (a != 0) {
            *(u32*)(a + 0xF4) |= 1;
            *(s32*)(a + 0x24) = 1;
            p[0] = 0;
        }
        u8* b = (u8*)p[1];
        if (b != 0) {
            *(u32*)(b + 0xF4) |= 1;
            *(s32*)(b + 0x24) = 1;
            p[1] = 0;
        }
        p += 0xe;
    }
    fn_800636F4(&lbl_802FC9F8, lbl_802B7CA0 + 0x2200, 0x40);
    s8 f = lbl_802C4E5C[4];
    if (f >= 0) {
        s32 n = *(s32*)(lbl_802C4E5C + 8) - 1;
        *(s32*)(lbl_802C4E5C + 8) = n;
        if (n == 0) {
            fn_800127A0(lbl_8029FDB4 + 4);
            *(s8*)(lbl_802C4E5C + 4) = -1;
        }
    }
    return TRUE;
}

extern "C" void fn_8004A380(void);
extern "C" void fn_8004A550(void);
extern "C" void fn_8003E6C4(f32);
extern "C" void fn_800704CC(void*);
extern u8 lbl_802C01B4[];
extern "C" s32 fn_80070C68(void* param_1) {
    fn_8004A380();
    fn_8004A550();
    fn_8003E6C4(*(f32*)(lbl_802C01B4 + 0xA0));
    fn_800704CC(param_1);
    return 1;
}

extern "C" void fn_8004ACA4(void*, void*);
extern "C" s32 fn_80070CB4(void* tag, void* data) {
    fn_8004ACA4(tag, data);
    return 1;
}

extern "C" int fn_80070CD8(void)
{
    return 1;
}

extern "C" void* fn_80070CE0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80280CEC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
