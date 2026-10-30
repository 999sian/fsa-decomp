#include "types.h"
#include <stdarg.h>

typedef struct {
    u8 b7 : 1;
    u8 b6 : 1;
    u8 b5 : 1;
    u8 b4 : 1;
    u8 b3 : 1;
    u8 b2 : 1;
    u8 b1 : 1;
    u8 b0 : 1;
} Bits8;

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

extern "C" void fn_80022A74(s32 param_1, u16 param_2) {
    u16 tmp = param_2;
    u8* b = (u8*)&tmp;
    Bits8* s = (Bits8*)(lbl_802BB778 + param_1 * 0x50);
    u32 lo = b[1];
    u32 hi = b[0];

    s[0x30].b4 = (lo >> 6) & 1;
    s[0x30].b5 = (lo >> 7) & 1;
    s[0x30].b7 = (lo >> 5) & 1;
    s[0x30].b6 = (lo >> 4) & 1;
    s[0x30].b3 = (lo >> 2) & 1;
    s[0x30].b2 = hi & 1;
    s[0x30].b1 = (hi >> 1) & 1;
    s[0x30].b0 = lo & 1;
    s += 0x31;
    s->b7 = (lo >> 1) & 1;
    s->b6 = 0;
    s->b5 = 0;
    s->b4 = (lo >> 3) & 1;
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

extern "C" void fn_80057B6C(void);
extern "C" void fn_80024BC8(s32* p);
extern "C" void fn_80022D74(s32* p) {
    fn_80057B6C();
    if (p != nullptr && *(u32*)(p + 1) != 0) {
        fn_80024BC8(p);
    }
}

extern "C" void fn_80057B9C(void);
extern "C" void fn_80022DBC(void) {
    fn_80057B9C();
}

extern "C" void fn_80022DDC(s32* p) {
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

extern u8 lbl_80206678[];
extern u8 lbl_80207230[];
extern u8 lbl_80220CA8[];
extern u8 lbl_80220DC4[];
extern "C" s32 fn_800247FC(u8* p1) {
    s32 v = *(s32*)(p1 + 0x1c);
    s32 b = lbl_802BB0FC[v * 0x4c + 0x1e9];
    s32 u;
    s32 r8;
    s32 val;
    if (v == 4) {
        b = p1[0x44];
    }
    if (b >= 0x47) {
        b = 0;
    }
    u = b;
    if (b == 0x2c) {
        u = 4;
    }
    r8 = *(s32*)(lbl_80206678 + *(s32*)(p1 + 0x24) * 0x28 + p1[0x2b] * 8 + 4);
    if (u < 5) {
        s32 c = lbl_802BB0FC[v * 0x4c + 0x1e8];
        if (v == 4) {
            c = p1[0x43];
        }
        if (c >= 0x47) {
            c = 0;
        }
        val = *(s32*)(lbl_80220DC4 + r8 * 0x64 + *(s32*)(lbl_80220CA8 + c * 4) * 0x14 + u * 4);
    } else {
        val = *(s32*)(lbl_80207230 + r8 * 0x11c + u * 4);
    }
    *(s32*)(p1 + 0x38) = *(s32*)(p1 + 0x3c);
    return val;
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

extern "C" s16** lbl_80221F7C[];
extern "C" s32* lbl_80221F8C[];
extern "C" void fn_80030418(int, int);
extern "C" void fn_80024954(u8* p1, s16 p2) {
    s16** puVar3;
    s16* psVar4;
    s32 iVar5;
    BOOL bVar2;
    s32 idx;

    idx = *(s32*)(p1 + 0x24);
    iVar5 = 0;
    puVar3 = lbl_80221F7C[idx];
    while (*puVar3 != NULL) {
        psVar4 = *puVar3;
        bVar2 = FALSE;
        for (; *psVar4 != 0; psVar4++) {
            if (*psVar4 == p2) {
                bVar2 = TRUE;
                break;
            }
        }
        if (bVar2) {
            s32* tbl = lbl_80221F8C[idx];
            s32 val = tbl[iVar5];
            *(u32*)(lbl_802BB0FC + 0x444) &= 0xfffffff7;
            *(u32*)(lbl_802BB0FC + 0x450) &= 0xfffffff7;
            *(u32*)(lbl_802BB0FC + 0x45c) &= 0xfffffff7;
            *(u32*)(lbl_802BB0FC + 0x468) &= 0xfffffff7;
            fn_80030418(val, idx);
            return;
        }
        puVar3++;
        iVar5++;
    }
}

extern f32 lbl_802FFCF0;
extern f32 lbl_802FFCF4;
extern f32 lbl_802FFCF8;
extern "C" s32 fn_80058C08(s32 idx);
extern "C" void fn_8005867C(int, void*, int, int, int, float);
extern "C" void fn_80024D98(f32* param_1, void* param_2) {
    s32 idx;
    s32 q;
    f32 f;

    idx = fn_80058C08(0x84) + (lbl_802FED48 & 1);
    f = param_1[1] / lbl_802FFCF0;
    f = f * lbl_802FFCF4;
    if (f < lbl_802FFCF4) {
        f = lbl_802FFCF4;
    }
    if (f > lbl_802FFCF8) {
        f = lbl_802FFCF8;
    }
    q = ((s32)param_1[0] + 0x130) * 0x80 / 0x260;
    if (q < 0) {
        q = 0;
    }
    if (q > 0x7f) {
        q = 0x7f;
    }
    fn_8005867C(idx, param_2, 1, q, -1, f);
    lbl_802FED48++;
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
