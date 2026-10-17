#include "types.h"
struct VObj_800C8D90 {
    virtual void v0();
    virtual void v1();
    virtual void v2(f32, f32);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(u8);
};

struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8010abb0-0x8010cb9c (30 functions). split_file divides it into the game's real files.

extern void* lbl_8028EAF8[];
extern u8 lbl_802C5AFC[];
extern u8 lbl_8029FDB4[];
extern "C" void fn_800127A0(void*, s8 = 0);
struct VObj_800EF6D0A {
 virtual void v0(s32 x);
};

struct VObj_800EF6D0B {
 virtual void v0();
 virtual void v1();
 virtual void v2();
 virtual void v3();
 virtual void v4();
 virtual void v5();
 virtual void v6();
 virtual void v7();
};

extern "C" s32 fn_8010C6D8(void* p, s16 a, u8 b, s32 c);
extern "C" void fn_8010C1F0(u8* p);
extern "C" void fn_8010C18C(u8* param_1);
extern "C" s32 fn_80020384(void* p, s32 a);
extern "C" void fn_8002F544(s32 a);
struct VObj_8010C1F0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(u8);
};
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_8030127C;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
struct NaviState_8010ABB0;
typedef void (NaviState_8010ABB0::*NaviStateFn_8010ABB0)();
extern NaviStateFn_8010ABB0 lbl_8028EA24[];
extern "C" s32 fn_8002F6BC(void* p);
extern void* lbl_802FF278;
extern f32 lbl_80301280;
extern f32 lbl_80301284;
extern "C" void fn_801E10DC(void);
struct VObj_8010BD04 {
    virtual void v0();
    virtual void v1();
    virtual void v2(u8);
};
struct VObj_8010B5B4 {
    virtual void v0();
    virtual void v1();
    virtual void v2(f32, f32);
    virtual void v3();
    virtual void v4(f32, f32);
};
extern "C" void fn_8010C320(u8* p, s16 a, u8 b, s32 c, s32 d, f32 e, f32 f);
extern "C" void fn_8010C5C4(u8* p, s16 a, u8 b, s32 c, s32 d);
extern "C" void fn_8010C488(u8* p, s32 i, s16 a, u8 b, s32 c, s32 d, f32 e, f32 f);
extern "C" void fn_8010B4E8(u8* p) {
    f32 zero = lbl_8030127C;
    *(s16*)(p + 0x98) = 0;
    fn_8010C320(p, *(s16*)(p + 0x98), lbl_802C5AFC[0xd], 0, 0, *(f32*)(lbl_802C5AFC + 0x10), zero);
    fn_8010C5C4(p, *(s16*)(p + 0x98), lbl_802C5AFC[0xc], 0, 0);
    for (s32 i = 0; i < 2; i++) {
        fn_8010C488(p, i, *(s16*)(p + 0x98), lbl_802C5AFC[0x1c], 0, 0, *(f32*)(lbl_802C5AFC + 0x18), lbl_8030127C);
    }
    *(f32*)(p + 0x90) = lbl_8030127C;
    *(f32*)(p + 0x94) = lbl_8030127C;
}

extern "C" void fn_8010B5B4(u8* param_1) {
    f32 a = lbl_80301280;
    *(f32*)(param_1 + 0x90) = a;
    f32 b = lbl_80301284;
    *(f32*)(param_1 + 0x94) = b;
    (*(VObj_8010B5B4**)(param_1 + 0x14))->v2(*(f32*)(param_1 + 0x18) + *(f32*)(param_1 + 0x90), *(f32*)(param_1 + 0x1c));
    (*(VObj_8010B5B4**)(param_1 + 0x20))->v2(*(f32*)(param_1 + 0x24), *(f32*)(param_1 + 0x28) + *(f32*)(param_1 + 0x94));
}

extern "C" void fn_8010B634(u8* p) {
    *(u8*)(*(u8**)(p + 0x70) + 0xb0) = 0;
    p[0x9d] = 0;
    p[0x9c] = 0;
}

extern "C" void fn_8010B64C(u8* p) {
    f32 zero = lbl_8030127C;
    *(s16*)(p + 0x98) = 0;
    fn_8010C320(p, *(s16*)(p + 0x98), lbl_802C5AFC[0xd], 0, 0, *(f32*)(lbl_802C5AFC + 0x10), zero);
    fn_8010C5C4(p, *(s16*)(p + 0x98), lbl_802C5AFC[0xc], 0, 0);
    for (s32 i = 0; i < 2; i++) {
        fn_8010C488(p, i, *(s16*)(p + 0x98), lbl_802C5AFC[0x1c], 0, 0, *(f32*)(lbl_802C5AFC + 0x18), lbl_8030127C);
    }
    zero = lbl_8030127C;
    *(f32*)(p + 0x90) = zero;
    *(f32*)(p + 0x94) = zero;
    *(u8*)(*(u8**)(p + 0x70) + 0xb0) = 0;
    *(u8*)(p + 0x9d) = 0;
    *(u8*)(p + 0x9c) = 0;
    *(u8*)(p + 0x9a) = 8;
}

extern "C" void fn_8010BAA0(NaviState_8010ABB0* p) {
    ((u8*)p)[0x9d] = 0;
    (p->*lbl_8028EA24[((u8*)p)[0x9a]])();
}

extern "C" void fn_8010BD04(u8* param_1) {
    if (fn_8002F6BC(param_1) == 0) {
        param_1[0x9b] = 0x3c;
        u8 v = param_1[0x9b];
        VObj_8010BD04* obj = *(VObj_8010BD04**)((u8*)lbl_802FF278 + 4);
        if (obj != nullptr) {
            obj->v2(v);
        }
        param_1[0x9a] = 2;
    }
}

extern "C" void fn_8010BD6C(u8* param_1) {
    if (param_1[0x9b] != 0) {
        param_1[0x9b]--;
        return;
    }
    param_1[0x9a] = 3;
}

extern "C" void fn_8010BD90(u8* param_1) {
    s32 r = fn_80020384((char*)lbl_802B7CA0 + 0x1388, 0);
    if (r == 1) {
        param_1[0x9a] = 8;
    }
}

extern "C" void fn_8010BDDC(u8* param_1) {
    if (fn_8002F6BC(param_1) == 0) {
        param_1[0x9c] = 1;
        param_1[0x9a] = 8;
    }
}

extern "C" void fn_8010BE20(u8* param_1) {
    s32 iVar1 = fn_8010C6D8(param_1, *(s16*)(param_1 + 0x98), lbl_802C5AFC[0x14], 0);
    (*(s16*)(param_1 + 0x98))++;
    if (iVar1 == 1) {
        *(s16*)(param_1 + 0x98) = 0;
        param_1[0x50] ^= 1;
        param_1[0x7c] = 1;
        fn_8010C1F0(param_1);
        fn_8010C18C(param_1);
        fn_8002F544(0x5c);
        (*(u8**)(param_1 + 0x70))[0xb0] = 1;
        param_1[0x9d] = 2;
        param_1[0x9a] = 6;
    }
}

extern "C" void fn_8010C0EC(u8* param_1) {
    s32 iVar1 = fn_8010C6D8(param_1, *(s16*)(param_1 + 0x98), lbl_802C5AFC[0x14], 0);
    (*(s16*)(param_1 + 0x98))++;
    if (iVar1 == 1) {
        *(s16*)(param_1 + 0x98) = 0;
        param_1[0x50] ^= 1;
        param_1[0x7c] = 1;
        fn_8010C1F0(param_1);
        fn_8010C18C(param_1);
        (*(u8**)(param_1 + 0x70))[0xb0] = 1;
        param_1[0x9d] = 2;
        param_1[0x9a] = 0;
    }
}

extern "C" void fn_8010C188(void) {}

extern "C" void fn_8010C18C(u8* param_1) {
    f32 off = 0.5f * param_1[0x7c];
    (*(VObj_800C8D90**)(param_1 + 0x70))->v2(*(f32*)(param_1 + 0x74) + off, *(f32*)(param_1 + 0x78));
}

extern "C" void fn_8010C1F0(u8* p) {
    p[0x7d] = 0;
    p[0x7e] = 1;
    (*(VObj_8010C1F0**)(p + 0x70))->v7(lbl_802C5AFC[0x1f]);
}

extern f32 lbl_80301298;
extern "C" f32 fn_8010C8C8(u8* p, u8 a, u8 b, s32 c);
extern f64 lbl_803012A0;
extern "C" void fn_8010C23C(u8* p) {
    f32 f = lbl_80301298 - fn_8010C8C8(p, lbl_802C5AFC[0x1e], p[0x7d], 0);
    if (p[0x7e] != 0) {
        s32 d = lbl_802C5AFC[0x1f] - lbl_802C5AFC[0x20];
        u8 v = (u8)(lbl_802C5AFC[0x20] + (u32)(f * (f32)d));
        (*(VObj_8010C1F0**)(p + 0x70))->v7(v);
    }
    if (p[0x7d] == 0) {
        p[0x7d] = lbl_802C5AFC[0x1e];
        p[0x7e] ^= 1;
    } else {
        p[0x7d]--;
    }
}

extern "C" void fn_8010C7F4(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 8);
}

extern "C" void fn_8010C830(u8* p) {
    VObj_800EF6D0A* a = *(VObj_800EF6D0A**)(p + 0xc);
    if (a != nullptr) {
        a->v0(1);
    }
    (*(VObj_800EF6D0B**)(p + 4))->v7();
    s8 idx = *(s8*)(lbl_802C5AFC + 4);
    if (idx >= 0) {
        if (--*(s32*)(lbl_802C5AFC + 8) == 0) {
            fn_800127A0(lbl_8029FDB4 + 4, idx);
            *(s8*)(lbl_802C5AFC + 4) = -1;
        }
    }
}

extern "C" void fn_8010CAF0(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_8030127C;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_8010CB54(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028EAF8;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
