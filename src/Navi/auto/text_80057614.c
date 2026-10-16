#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80057614-0x800618fc (176 functions). split_file divides it into the game's real files.

extern u8 lbl_802C05F0[];
extern u8 lbl_8026D4BC[];
extern "C" void fn_800592CC(void* p);
extern "C" void fn_80059290(void* p);
extern "C" s32 fn_80058D70(s32 idx);
extern void* lbl_8027EC78[];
extern void* lbl_80299A8C[];
extern void* lbl_802044AC[];
extern u8 lbl_8027D7C0[];
extern u32 lbl_802FBA78;
extern "C" void fn_801DA39C(s32, s32, s32, s32, s32);
extern "C" void fn_801DA364(void);
extern "C" void fn_801D9F18(s32, s32);
extern "C" void fn_801DAC08(s32, void*, s32);
extern "C" void fn_801DF2A4(void*, s32);
extern "C" void fn_801DF344(s32);
extern "C" void fn_801DE4F4(s32, void*);
extern "C" void fn_801DF0BC(void*, s32);
extern "C" void fn_801DEE10(s32);
extern "C" void fn_801DEE3C(s32);
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_8005845C(void);
extern "C" void fn_8005C424(void);
extern "C" void fn_8005B454(s32, s32, s32);
extern "C" s32 fn_80058DB8(s32);
extern "C" s32 fn_8005B82C(s32, s32, s32);
extern "C" u32 fn_8005B97C(s32, s32, s32);
extern "C" void fn_8005B6CC(s32, s32, s32);
extern "C" void fn_8005C460(void);
extern "C" s32 fn_80059190(s32 idx);
extern "C" void fn_800595FC(void);
extern "C" void fn_80057868(void) {
}

extern "C" void fn_800579E0(void) {
}

extern "C" void fn_800579F8(void) {
}

extern "C" void fn_8005867C(void) {
    fn_8005845C();
}

extern "C" void fn_80058740(void*, int);
extern "C" void fn_8005871C(void* p) {
    fn_80058740(p, 0);
}

extern "C" s32 fn_80058930(s32 idx) {
    extern f64 lbl_80300238;
    extern f64 lbl_80300240;
    extern f64 lbl_80300248;
    union {
        f64 d;
        u32 w[2];
    } u;
    u32 v;
    s32 r;
    if (fn_80058D70(idx) == 0) {
        return 0;
    }
    v = *(u32*)(lbl_8026D4BC + idx * 0xc + 4);
    u.w[0] = 0x43300000;
    u.w[1] = v ^ 0x80000000;
    r = (s32)((lbl_80300238 * (lbl_80300248 - u.d)) / lbl_80300240);
    if (v == 1000000) {
        r = 1000000;
    }
    return r;
}

extern "C" void fn_800589CC(s32 param_1) {
    fn_8005C424();
    if (param_1 >= 1 && param_1 <= 0xffff) {
        if ((u32)fn_80059190(param_1) != 0) {
            fn_800595FC();
        }
    }
    fn_8005C460();
}

extern "C" void fn_80058A28(s32 param_1) {
    fn_8005C424();
    fn_8005B454(1, param_1, 0);
    if (fn_80058DB8(param_1) != 0) {
        fn_8005B454(1, param_1, 1);
    }
    fn_8005C460();
}

extern "C" s32 fn_80058A88(s32 param_1) {
    s32 result;
    fn_8005C424();
    result = fn_8005B82C(1, param_1, 0) != 0;
    if (result != 0) {
        if (fn_80058DB8(param_1) != 0) {
            result = fn_8005B82C(1, param_1, 1) != 0;
        }
    }
    fn_8005C460();
    return result;
}

extern "C" s32 fn_80058C08(s32 idx) {
    u8* p = lbl_8026D4BC + idx * 0xc;
    if (fn_80058D70(idx) != 0) {
        return (p[1] << 3) + 0x4000;
    }
    return 0;
}

extern "C" void fn_80058C5C(void) {
    s32 i = 0;
    do {
        fn_80059290(&lbl_802C05F0[i * 0x18]);
        lbl_802C05F0[i * 0x18 + 0x16] = i;
        i++;
    } while (i < 0x10);
}

extern "C" void fn_80058CB0(void) {
    s32 i = 0;
    do {
        fn_800592CC(&lbl_802C05F0[i * 0x18]);
        i++;
    } while (i < 0x10);
}

extern "C" void fn_800595FC(void);
extern "C" void fn_80058D50(void) {
    fn_800595FC();
}

extern "C" s32 fn_80058D70(s32 idx) {
    u8* base = lbl_8026D4BC;
    s32 off = idx * 0xc;
    u8 t;
    if (idx <= 0 || idx > 0x152a) {
        return 0;
    }
    t = base[off];
    if (t == 0 || t >= 4) {
        return 0;
    }
    return 1;
}

extern "C" void fn_8005A480(void) {}

extern "C" void fn_8005B450(void) {}

extern "C" void fn_8005C330(const char*, ...) {
}

extern "C" void* lbl_802FF118;
extern "C" void* fn_8005C498(void)
{
	return lbl_802FF118;
}

extern "C" void* lbl_802FF11C;
extern "C" void* fn_8005C4A0(void)
{
	return lbl_802FF11C;
}

extern int lbl_802FF128;
extern int lbl_802FF12C;
extern int lbl_802FF130;
extern "C" void fn_8005CAC8(void) {
    lbl_802FF128 = 0;
}

extern "C" void fn_8005CB14(void) {
    if (lbl_802FF130 >= 0x20) {
        return;
    }
    lbl_802FF130++;
}

extern "C" void fn_8005CB2C(int param_1) {
    s32 prev = lbl_802FF12C;
    if (lbl_802FF12C == 0 && param_1 == 0xd4) {
        lbl_802FF12C = 1;
    } else if (lbl_802FF12C != 0 && param_1 == 0xd3) {
        lbl_802FF12C = 0;
    }
    if (lbl_802FF12C != prev) {
        lbl_802FF130 = 1;
    }
}

extern "C" int fn_8005CB7C(int param_1) {
    if (param_1 != 0xd4 && param_1 != 0xd3) {
        return 1;
    }
    return 0;
}

extern "C" void* fn_8005E7D8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EC78;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8005E820(void* self) {
    ((void (*)(void*, u8))(*(void***)((u8*)self + 8))[0x24 / 4])((u8*)self + 8, *((u8*)self + 0x174));
    s16 x = *(s16*)((u8*)self + 0x170);
    s16 y = *(s16*)((u8*)self + 0x172);
    ((void (*)(void*, s32, s32, s32, f32, f32))(*(void***)((u8*)self + 8))[0xe4 / 4])((u8*)self + 8, 0, 0, 0, x, y);
}

extern "C" void fn_8005E8B8(void* self, s32 a, s32 b, s32 c) {
    void** vtbl = *(void***)self;
    ((void (*)(void*, s32, s32, s32, s32))vtbl[0xe8 / 4])(self, 0, a, b, c);
}

extern "C" void fn_8005E8F8(void* self, u8 idx, f32 p1, f32 p2, s32 a, s32 b, s32 c) {
    if (idx < *((u8*)self + 0x110)) {
        void* slot = *(void**)((u8*)self + (idx << 2) + 0x100);
        if (slot != nullptr) {
            u8* q = *(u8**)((u8*)slot + 0x20);
            s32 y = *(u16*)(q + 4);
            s32 x = *(u16*)(q + 2);
            ((void (*)(void*, s32, s32, s32, f32, f32, f32, f32))(*(void***)self)[0xec / 4])(self, a, b, c, p1, p2, (f32)x, (f32)y);
        }
    }
}

extern "C" void fn_8005E990(void* self, s16 a, s16 b) {
    *(s16*)((u8*)self + 0x170) = a;
    *(s16*)((u8*)self + 0x172) = b;
}

extern "C" void* fn_8005F864(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_8005F8A0(void) {
}

extern "C" void fn_8005FCEC(void* self) {
    u8* base = lbl_8027D7C0;
    u32 buf[2];
    fn_801DA39C(0, 9, 1, 4, 0);
    fn_801DA364();
    fn_801D9F18(9, 2);
    fn_801DAC08(9, base + 0x111c, 0xc);
    fn_801DF2A4((u8*)self + 0x10, 0);
    fn_801DF344(0);
    buf[0] = lbl_802FBA78;
    fn_801DE4F4(1, buf);
    fn_801DF0BC(base + 0x1240, 0x60);
    fn_801DF0BC(base + 0x11e0, 0x40);
    fn_801DEE10(1);
    fn_801DEE3C(0);
}

extern "C" void fn_8005FE84(void** p) {
    p[0] = lbl_80299A8C;
    p[1] = nullptr;
    p[2] = nullptr;
    p[3] = nullptr;
    p[0] = lbl_802044AC;
    p[4] = nullptr;
}

extern "C" void fn_8006081C(void) {
}

extern void* lbl_8027EB8C[];
extern void* lbl_80299A8C[];
extern "C" void* fn_80061490(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EB8C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027EBC4[];
extern "C" void* fn_800614EC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EBC4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027EBFC[];
extern "C" void* fn_80061548(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EBFC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299A8C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027EC40[];
extern "C" void* fn_800615A4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EC40;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ECA4[];
extern "C" void* fn_80061678(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ECA4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ECCC[];
extern "C" void* fn_800616D4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ECCC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ECF4[];
extern "C" void* fn_80061730(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ECF4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ED20[];
extern "C" void* fn_8006178C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ED20;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ED48[];
extern "C" void* fn_800617E8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ED48;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027ED74[];
extern "C" void* fn_80061844(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027ED74;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8027EDA0[];
extern "C" void* fn_800618A0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8027EDA0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027EC78;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
