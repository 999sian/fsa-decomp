#include "types.h"
#include <stdarg.h>
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800227c8-0x8002507c (33 functions). split_file divides it into the game's real files.

extern void* lbl_80222428[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80022874(void) {}

extern "C" void* fn_80022878(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_800228B4(void* self) {
    s16* p = (s16*)self;
    p[0] = 0;
    p[1] = 0;
    *(s32*)(p + 2) = 0;
}

extern "C" void* fn_800228C8(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80022904(void* self) {
    s16* p = (s16*)self;
    p[0] = 0;
    p[1] = 0;
    p[4] = 0;
    *(u8*)((u8*)self + 0xa) = 0;
    *(u8*)((u8*)self + 0xb) = 0;
}

extern "C" void* fn_80022920(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8002295C(void* self) {
    u8* p = (u8*)self;
    *(s16*)(p + 0) = 0;
    *(s16*)(p + 2) = 0;
    *(s32*)(p + 8) = 0;
    *(s32*)(p + 4) = 0;
    *(s32*)(p + 0x30) = 0;
    p[0x47] = 0;
    p[0x34] = 0;
    p[0x35] = 0;
    p[0x36] = 0;
    p[0x37] = 0;
    p[0x38] = 0;
    p[0x39] = 0;
    p[0x3a] = 0;
    p[0x3b] = 0;
    p[0x3c] = 0;
    p[0x3d] = 0;
    p[0x3e] = 0;
    p[0x3f] = 0;
    p[0x40] = 0;
    p[0x41] = 0;
    p[0x42] = 0;
    p[0x43] = 0;
    *(s32*)(p + 0x2c) = 0;
}

extern u8 lbl_802BB778[];
extern u8 lbl_802BB638[];
extern u8 lbl_8029F408[];
extern "C" void fn_80022B48(s32 p);
extern "C" void fn_800229C0(void) {
    u8* src = lbl_802BB778;
    u8* dst = lbl_802BB638;
    u8* def = lbl_8029F408;
    s32 i;
    for (i = 0; i < 4; i++) {
        fn_80022B48(i);
        if (*(u16*)(src + 0x30) != 0) {
            *(u16*)(dst + 0x30) = *(u16*)(src + 0x30);
            *(u16*)(dst + 0x32) = *(u16*)(src + 0x32);
            *(u16*)(dst + 0x34) = *(u16*)(src + 0x34);
        } else {
            *(u16*)(dst + 0x30) = *(u16*)(def + 0x30);
            *(u16*)(dst + 0x32) = *(u16*)(def + 0x32);
            *(u16*)(dst + 0x34) = *(u16*)(def + 0x34);
        }
        dst += 0x50;
        def += 0x50;
        src += 0x50;
    }
}

extern "C" void* fn_80022CA8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80222428;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern s32 lbl_802FED7C;
extern s32 lbl_802FED80;
extern "C" void fn_800579FC(void);
extern "C" s32 fn_801BFB74(void);
extern "C" void fn_80057AE0(s32 p);
extern "C" void fn_80022CF0(s32 p1, s32 p2) {
    s32 flag;
    fn_800579FC();
    flag = 0;
    if ((u32)fn_801BFB74() != 1) {
        flag = 1;
    }
    fn_80057AE0(flag);
    lbl_802FED7C = p1;
    lbl_802FED80 = p2;
}

extern "C" void fn_80057B24(void);
extern "C" void fn_80022D54(void) {
    fn_80057B24();
}

extern "C" void fn_80057B9C(void);
extern "C" void fn_80022DBC(void) {
    fn_80057B9C();
}

extern s32 lbl_802FED48;
extern s32 lbl_802FED4C;
extern s32 lbl_802FED50;
extern s32 lbl_802FED54;
extern s32 lbl_802FED58;
extern s32 lbl_802FED5C;
extern s32 lbl_802FED60;
extern s32 lbl_802FED64;
extern s32 lbl_802FED68;
extern s32 lbl_802FED6C;
extern "C" void fn_800589CC(s32 p);
extern "C" void fn_80022FA0(s32* p) {
    if ((u32)p[0] != 0 || p[2] != 0) {
        fn_800589CC(p[5]);
    }
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    *(u8*)(p + 10) = 0;
    *((u8*)p + 0x2e) = 0;
    lbl_802FED48 = 0;
    lbl_802FED4C = 0;
    lbl_802FED50 = 0;
    lbl_802FED54 = 3;
    lbl_802FED58 = 0;
    lbl_802FED5C = 0;
    lbl_802FED60 = 0;
    lbl_802FED64 = 0;
    lbl_802FED68 = 0;
    lbl_802FED6C = 0;
}

extern u8 lbl_802BB0FC[];
extern "C" s32 fn_80024678(u8* p1, s32 p2, s32 p3) {
    s32 b = *(u8*)(lbl_802BB0FC + p2 * 0x4c + p3 + 0x1e8);
    if (p2 == 4) {
        b = (p1 + p3)[0x43];
    }
    if (b >= 0x47) {
        b = 0;
    }
    return b;
}

extern u8 lbl_80206488[];
extern "C" u32 fn_800248F0(u8* p1, u32 p2, u32 p3) {
    u32 ret = 0;
    if ((u8)(lbl_802BB0FC[0xee] & (1 << (u8)p2))) {
        p1[0x28] = 0;
    } else {
        ret = *(u32*)(lbl_80206488 + p3 * 0x40 + *(s32*)(p1 + 0x24) * 0x10 + p2 * 4);
        p1[0x28] = 1;
    }
    return ret;
}

extern "C" void fn_801E42F8(char* buf, const char* fmt, va_list args);
extern "C" void fn_80029208(const char*, ...);
extern "C" void fn_80024F84(u8* p1, const char* p2, ...) {
    char buf[268];
    va_list args;
    if (!(p1[0x2a] & 2)) {
        va_start(args, p2);
        fn_801E42F8(buf, p2, args);
        fn_80029208(buf);
    }
}

extern void* lbl_8022241C[];
extern "C" void* fn_80025020(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8022241C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80222428;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

