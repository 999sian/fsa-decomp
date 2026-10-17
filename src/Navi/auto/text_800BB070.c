#include "types.h"
struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800bb070-0x800be068 (37 functions). split_file divides it into the game's real files.

extern void* lbl_80287BCC[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300CE8;
extern f32 lbl_80300D04;
extern "C" f32 fn_800BDD94(void*, u8, s32);
struct VObj_800BD938 {
    virtual void d0();
    virtual void d1();
    virtual void v4(f32, f32);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(s32);
};
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_800BC6F4(u8* p);
extern "C" void fn_800BB210(u8* p);
extern "C" void fn_800BB1B4(u8* param_1) {
    fn_800BC6F4(param_1);
    fn_800BB210(param_1);
    if (*(u8*)(lbl_802B7CA0 + 0x141a) != 0) {
        param_1[0xd4] = 0;
    } else {
        param_1[0xd4] = 1;
    }
}

extern "C" int fn_800BB6C0(u8* p, u32* q) {
    *(u32*)(p + 0x13c) = *q;
    return 1;
}

extern "C" int fn_800BB6E8(u8* p, u32* q) {
    *(u32*)(p + 0x138) = *q;
    return 1;
}

extern "C" void fn_801E10DC(void* p, void* q);
extern "C" void fn_800BD3BC(void* p);
extern "C" void fn_8017A4F8(void* p);
struct NaviState_800BC984;
typedef void (NaviState_800BC984::*NaviStateFn_800BC984)();
extern NaviStateFn_800BC984 lbl_80287A60[];
extern "C" void fn_800BC984(NaviState_800BC984* p) {
    ((u8*)p)[0xe4] = 0;
    (p->*lbl_80287A60[((u8*)p)[0xd4]])();
    fn_800BD3BC(p);
    fn_8017A4F8(*(void**)((u8*)p + 8));
}

extern "C" void fn_800BD00C(u8* p);
extern "C" void fn_800BCE58(u8* p) {
    if (p[0xe5] != 0) {
        p[0xe5]--;
    } else {
        p[0xe6] = 1;
        fn_800BD00C(p);
        p[0xd4] = 1;
    }
}

extern "C" s32 fn_8002F6BC(void* p);
extern "C" void fn_8002F9B4(void);
extern u8 lbl_802BB0FC[];
extern u8 lbl_802C55FC[];
extern "C" s32 fn_800BDA50(u8* p, u8 a, u8 b, s32 c);
extern "C" void fn_800BCEAC(u8* p) {
    if (fn_8002F6BC(p) == 0) {
        if (p[0xe0] == 3) {
            fn_8002F9B4();
        }
        p[0xe1] = p[0xe0];
        p[0xd4] = 2;
    }
}

extern "C" void fn_800BCF00(u8* p) {
    if (fn_8002F6BC(p) == 0) {
        fn_8002F9B4();
        *(s32*)(lbl_802BB0FC + 0x420) = 0;
        *(s32*)(lbl_802BB0FC + 0x424) = 0;
        p[0xe5] = 0x1e;
        p[0xd4] = 6;
    }
}

extern "C" void fn_800BCF5C(u8* p) {
    if (p[0xe5] != 0) {
        p[0xe5]--;
    } else {
        p[0xe1] = 3;
        p[0xd4] = 2;
    }
}

extern "C" void fn_800BCF88(void) {}

extern "C" void fn_800BCF8C(u8* p) {
    *(u8*)(*(u8**)(p + 0x34) + 0xb0) = 1;
    p[0xe4] = 2;
    p[0xd4] = 1;
}

extern "C" void fn_800BD00C(u8* p) {
    *(s32*)(p + 0x48) = 0;
    *(*(u8**)(p + 0x34) + 0xb0) = 1;
}

extern "C" void fn_800BD024(u8* p) {
    if (*(*(u8**)(p + 0x34) + 0xb0) != 0) {
        s32 n;
        u8* q;
        *(s32*)(p + 0x48) = *(s32*)(p + 0x48) + 1;
        q = *(u8**)(p + 0x44);
        n = *(s32*)(p + 0x48);
        if (n >= *(s16*)(q + 6)) {
            *(s32*)(p + 0x48) = n - *(s16*)(q + 6);
        }
        *(f32*)(*(u8**)(p + 0x44) + 8) = (f32)*(s32*)(p + 0x48);
    }
}

extern "C" void fn_800BD268(u8* p);
extern "C" void fn_800BD190(u8* p);
extern "C" void fn_800BD144(u8* p) {
    if (p[0xb9] == 1) {
        fn_800BD268(p);
    } else {
        p[0xb9] = 1;
    }
    fn_800BD190(p);
}

extern "C" void fn_800BD344(u8* p) {
    if (p[0xb9] != 0) {
        s32 r = fn_800BDA50(p, p[0xba], lbl_802C55FC[0x19], 0);
        p[0xba]++;
        if (r == 1) {
            p[0xba] = 0;
            p[0xb9] = 0;
            p[0xb8] ^= 1;
        }
    }
}

extern "C" int fn_800BD938(void* param_1, s16 param_2, f32 param_3, f32 param_4, u8 param_5, u32 unused, s32 param_7) {
    u8* p = (u8*)param_1;
    if (param_2 < 0) {
        return 0;
    }
    s32 idx = param_2;
    s32 max = param_5;
    if (idx > max) {
        return 1;
    }
    f32 t = fn_800BDD94(param_1, max, idx);
    f32 d = t * (param_4 - param_3);
    (*(VObj_800BD938**)(p + 0x24))->v4(*(f32*)(p + 0x28), *(f32*)(p + 0x2c) + (param_3 + d));
    if (param_7 != 2) {
        if (param_7 == 1) {
            t = lbl_80300D04 - t;
        }
        (*(VObj_800BD938**)(p + 0x24))->v9((s32)((f32)*(u8*)(p + 0x30) * t));
    }
    return 0;
}

extern "C" void fn_800BDFBC(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300CE8;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800BE020(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80287BCC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
