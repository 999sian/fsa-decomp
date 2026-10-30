#include "types.h"
extern "C" void fn_800E927C(u8* p);
extern "C" s32 fn_800EE044(void);
extern "C" void fn_8002F358(s32, s32);
extern "C" void fn_8017A4F8(void* p);
extern "C" s32 fn_800ED0E8(void*, s32, u8, s32, s32, f32, f32);
extern "C" void fn_800E53A0(u8* p);
extern "C" char lbl_802B7CA0[];
struct VObj_800E7E60 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void* v13(s32, s32, s32);
};
extern "C" void* fn_80181BA0(void* p);
extern "C" void fn_801E41AC(void* dst, void* src, ...);
extern "C" void fn_801E6768(void* dst, char* src);
extern "C" int fn_80030390(unsigned char c);
extern "C" s32 fn_8002192C(void);
extern "C" char lbl_8028B50C[];
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" s32 fn_8002F168(u8* p);
struct VObj_800D73FC {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(int);
};
extern "C" f32 fn_800EE11C(u8* p, u8 a, s16 b);
struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800d73fc-0x800ee3f0 (167 functions). split_file divides it into the game's real files.

extern void* lbl_8028B80C[];
extern "C" char lbl_802BB0FC[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80301058;
extern f32 lbl_803010D0;
extern "C" f32* fn_80177B10(void* p);
extern "C" void fn_800E6770(u8* p);
extern "C" int fn_8004D308(void* a, s32 b, s32 c, void* d, void* e, void* f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern void* lbl_802FF0BC;
extern f32 lbl_803010EC;
extern f32 lbl_803010F0;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_8015FDA8(void*, void*);
extern "C" int fn_8002F0A8(int);
struct NaviSlot_802C04D0 {
    s32 bit;
    s32 unk4;
    s32 id;
};
extern NaviSlot_802C04D0 lbl_802C04D0[];
extern "C" u32 lbl_8028A8D8[];
extern "C" int fn_80057530(int id);
extern "C" s32 fn_800EE044(void);
extern "C" void fn_8002F458(s32 a, s32 b);
extern "C" void fn_800E7F50(void*, s32, s32, s32);
extern char lbl_802C57D4[];
extern "C" s32 fn_800ECFD0(void*, s32, u8, s32, s32, f32, f32);
extern "C" s32 fn_800ED5AC(void*, s32, u8, s32, s32, f32, f32);
extern "C" s32 fn_800ED6C4(void*, s16, u8, s32, s32, f32, f32);
extern "C" void fn_8002F358(s32 a, s32 b);
extern "C" void fn_800EBD88(char* p);
extern "C" void fn_800589CC(s32 a);
extern "C" s32 fn_800E6DA4(void* p);
extern "C" s32 fn_800ECDA0(void*, s32, u8, s32, s32, f32, f32);
extern "C" s32 fn_800ECEB8(void*, s32, u8, s32, s32, f32, f32);
extern "C" void fn_800D7940(u8* p) {
    fn_800ECDA0(p, *(s16*)(p + 0xb12), (u8)lbl_802C57D4[0x10], 0, 0, *(f32*)(lbl_802C57D4 + 0xc), 0.0f);
    (*(u8**)(p + 0x4f8))[0xb0] = 0;
    u8* d = (u8*)lbl_802C57D4;
    fn_800ECFD0(p, *(s16*)(p + 0xb12), d[0x18], 0, 0, *(f32*)(d + 0x20), 0.0f);
    (*(u8**)(p + 0x594))[0xb0] = 0;
    fn_800ECEB8(p, *(s16*)(p + 0xb12), d[0x18], 0, 0, *(f32*)(lbl_802C57D4 + 0x14), 0.0f);
    (*(u8**)(p + 0x578))[0xb0] = 0;
}

extern "C" void fn_800D7A08(u8* p) {
    fn_800ED5AC(p, *(s16*)(p + 0xb12), (u8)lbl_802C57D4[0x10], 0, 0, *(f32*)(lbl_802C57D4 + 0xc), 0.0f);
    (*(u8**)(p + 0x858))[0xb0] = 0;
    u8* d = (u8*)lbl_802C57D4;
    fn_800ED6C4(p, *(s16*)(p + 0xb12), d[0x18], 0, 0, *(f32*)(d + 0x20), 0.0f);
    (*(u8**)(p + 0x9c8))[0xb0] = 0;
    (*(u8**)(p + 0x9d8))[0xb0] = 0;
}

extern "C" BOOL fn_800DDA6C(void* p, u8* src) {
    u8* c = (u8*)p;
    u8 a;
    u8 b;
    b = src[1];
    c[0x128] = src[0];
    a = src[2];
    c[0x129] = b;
    b = src[3];
    c[0x12a] = a;
    c[0x12b] = b;
    return 1;
}

extern "C" void fn_800E29F4(u8* p);
extern "C" void fn_800E29CC(u8* p) {
    p[0xb11] = 0;
    fn_800E29F4(p);
}

#pragma use_lmw_stmw off
extern "C" void fn_800E347C(u8* p) {
    s32 i;
    for (i = 0; i < 4; i++) {
        p[0xa78 + i] = 0xff;
        if (*(u32*)(lbl_802B7CA0 + 0x3448) & (1 << i)) {
            p[0xa78 + i] = fn_80057530(i);
        }
    }
}
#pragma use_lmw_stmw reset
extern "C" s32 fn_800E3638(void* param_1, s32 param_2) {
    NaviSlot_802C04D0* s = lbl_802C04D0;
    u32 flags = *(u32*)(lbl_802B7CA0 + 0x3448);
    s32 i;
    for (i = 0; i < 4; s++, i++) {
        if (flags & (1 << s->bit)) {
            if (param_2 == s->id) {
                return lbl_802C04D0[i].bit;
            }
        }
    }
    return -1;
}

extern "C" void fn_800E38B8(void) {}

extern "C" s32 fn_800F0E58(void* p);
extern "C" void fn_800E030C(u8* p, u8 b);
extern "C" void fn_800EC3A4(u8* p, u8 b);
extern "C" s32 fn_800E3BE0(u8* p) {
    s32 ret = 0;
    if (fn_800EE044() != 0) {
        if (fn_800F0E58(lbl_802B7CA0) != 0) {
            u8* g = (u8*)lbl_802BB0FC;
            s32 i;
            if (*(s32*)(g + 0x3f0) != 0) {
                fn_8002F358(0xf4, 0);
            }
            for (i = 0; i < *(s32*)(g + 0x3f0); i++) {
                *(u8*)(*(u8**)(p + 0x5e8 + i * 4) + 0xb0) = 1;
            }
            fn_800E030C(p, *(u8*)(p + 0x5e0));
            fn_800EC3A4(p, (u8)*(s32*)(g + 0x3f0));
            ret = 1;
            *(s16*)(p + 0xa9c) = *(s16*)(lbl_802C57D4 + 0x48);
            *(u8*)(p + 0xa76) = 0x12;
        }
    }
    return ret;
}

extern "C" void fn_800E3EF0(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xa76) = 0;
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x4;
}

extern "C" void fn_800E3F28(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xa76) = 0x14;
}

extern "C" void fn_800E3F4C(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xb11) = 2;
    *(u16*)((u8*)param_1 + 0xa9c) = 10;
    *(u8*)((u8*)param_1 + 0xa76) = 0x15;
}

extern "C" void fn_800E3F80(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    if (fn_800EE044() != 0) {
        fn_8002F358(0xa5, 0);
        *(u8*)((u8*)param_1 + 0xb11) = 1;
        *(u16*)((u8*)param_1 + 0xa9c) = 10;
        *(u8*)((u8*)param_1 + 0xa76) = 0x16;
    }
}

extern "C" void fn_800E3FF0(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xa76) = 0;
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x800;
}

extern "C" void fn_800E41F8(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    } else {
        fn_8002F0A8(lbl_8028A8D8[*(u32*)(lbl_802BB0FC + 0x420)]);
        *(u32*)(lbl_802BB0FC + 0xf8) |= 0x20000000;
        *(u16*)(p + 0xa9c) = 0x78;
        p[0xa76] = 0x1a;
    }
}

extern "C" void fn_800E46F4(void* param_1) {
    u8* p = (u8*)param_1;
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    }
    s32 r = fn_800ECFD0(param_1, *(s16*)(p + 0xb12), (u8)lbl_802C57D4[0x18], 0, 0, *(f32*)(lbl_802C57D4 + 0x20), lbl_80301058);
    *(s16*)(p + 0xb12) = *(s16*)(p + 0xb12) + 1;
    if (r == 1 && *(u16*)(p + 0xa9c) == 0) {
        if (*(s32*)(lbl_802BB0FC + 0x3f0) == 0x64) {
            p[0x5dc] = 1;
        }
        *(u16*)(p + 0xb12) = 0;
        *(u16*)(p + 0xa9c) = (u8)lbl_802C57D4[0x93];
        p[0xa76] = 0x1d;
    }
}

extern "C" s32 fn_80030668(s32);
extern "C" void fn_800E47B4(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    }
    *(s32*)(p + 0xb50) = fn_80030668(*(s32*)(p + 0xb54));
    *(u32*)(lbl_802BB0FC + 0xf8) &= 0xdfffffff;
    *(u16*)(p + 0xa9c) = (u8)lbl_802C57D4[0x93];
    p[0xa76] = 0x1e;
}

extern "C" u8* fn_800306DC(int);
extern "C" void fn_800E4828(u8* p) {
    if (fn_800306DC(*(s32*)(p + 0xb50)) == 0) {
        if (*(u16*)(p + 0xa9c) != 0) {
            *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
        } else {
            p[0xb11] = 2;
            *(u16*)(p + 0xa9c) = 10;
            p[0xa76] = 0x1f;
        }
    }
}

extern "C" s32 fn_800EC85C(void*, s32, u8, f32, f32, s32, s32);
extern "C" s32 fn_800EC744(void*, s32, u8, f32, f32, s32, s32);
extern "C" void fn_80058654(int, void*, int, float);
extern "C" void fn_800E4A98(u8* p) {
    if (*(s16*)(p + 0xb12) == 0) {
        fn_8002F358(0x9a, 0);
        fn_80058654(3, (void*)0xf1, 1, lbl_80301058);
    }
    s32 a = fn_800EC85C(p, *(s16*)(p + 0xb12), ((u8*)lbl_802C57D4)[0x38], *(f32*)((u8*)lbl_802C57D4 + 0x34), lbl_80301058, 0, 0);
    s32 b = fn_800EC744(p, *(s16*)(p + 0xb12), ((u8*)lbl_802C57D4)[0x10], *(f32*)((u8*)lbl_802C57D4 + 0xc), lbl_80301058, 0, 0);
    *(s16*)(p + 0xb12) = *(s16*)(p + 0xb12) + 1;
    if (a == 1 && b == 1) {
        *(s16*)(p + 0xb12) = 0;
        p[0xa76] = 0;
    }
}

extern "C" void fn_800E5084(u8* p) {
    if (*(s16*)(p + 0xb12) == 0) {
        fn_8002F358(0x9a, 0);
    }
    s32 r = fn_800ED0E8(p, *(s16*)(p + 0xb12), (u8)lbl_802C57D4[0x28], 0, 0, *(f32*)(lbl_802C57D4 + 0x24), lbl_80301058);
    *(s16*)(p + 0xb12) = *(s16*)(p + 0xb12) + 1;
    if (r == 1) {
        *(s16*)(p + 0xb12) = 0;
        fn_8002F358(0xb7, 0);
        fn_800E53A0(p);
        p[0x3bc] = 1;
        *(s16*)(p + 0xa9c) = *(s16*)(lbl_802C57D4 + 0x8e);
        p[0xa76] = 0xe;
    }
}

extern "C" void fn_800E53A0(u8* p);
extern "C" void fn_800E5458(u8* p);
extern "C" void fn_800E560C(u8* p);
extern "C" void fn_800E513C(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    } else {
        p[0x3bc] = 0;
        fn_800E5458(p);
        fn_800E560C(p);
        *(s32*)(p + 0x3b0) = 0;
        *(f32*)(*(u8**)(p + 0x3ac) + 8) = *(s32*)(p + 0x3b0);
        fn_8017A4F8(*(void**)(p + 0x14));
        p[0xa76] = 0xf;
    }
}

extern "C" s32 fn_800ED0E8(void*, s32, u8, s32, s32, f32, f32);
extern "C" void fn_800E51D0(u8* p) {
    if (*(s16*)(p + 0xb12) == 0) {
        fn_8002F358(0x9c, 0);
    }
    s32 r = fn_800ED0E8(p, *(s16*)(p + 0xb12), (u8)lbl_802C57D4[0x28], 0, 1, lbl_80301058, *(f32*)(lbl_802C57D4 + 0x24));
    *(s16*)(p + 0xb12) = *(s16*)(p + 0xb12) + 1;
    if (r == 1) {
        *(s16*)(p + 0xb12) = 0;
        *(u8*)(*(u8**)(p + 0x384) + 0xb0) = 0;
        *(u16*)(p + 0xa9c) = *(s16*)(lbl_802C57D4 + 0x48);
        p[0xa76] = 9;
    }
}

extern "C" void fn_800E53A0(u8* p) {
    f32 v[3];
    int r;
    v[0] = (*(f32*)(p + 0x38c) + fn_80177B10(*(void**)(p + 0x3a4))[0]) - lbl_803010EC;
    v[1] = (*(f32*)(p + 0x390) + fn_80177B10(*(void**)(p + 0x3a4))[1]) - lbl_803010F0;
    v[2] = lbl_80301058;
    if (lbl_802FF0BC != 0) {
        r = fn_8004D308(lbl_802FF0BC, 8, 0x10, v, 0, 0, 0xff, 0, 0, 0, 0);
    } else {
        r = 0;
    }
    *(int*)(p + 0xb38) = r;
}

extern "C" void fn_80130974(void*);
extern "C" void fn_800E5458(u8* p) {
    if (*(u8**)(p + 0xb38) != 0) {
        fn_80130974(*(u8**)(p + 0xb38));
        u8* q = *(u8**)(p + 0xb38);
        *(u32*)(q + 0xf4) |= 1;
        *(u32*)(q + 0x24) = 1;
        *(u32*)(p + 0xb38) = 0;
    }
}

#pragma use_lmw_stmw off
extern "C" void fn_800E560C(u8* p) {
    u8* q = p;
    s32 i;
    for (i = 0; i < 3; i++, q += 4) {
        if (*(u8**)(q + 0xb3c) != 0) {
            fn_80130974(*(u8**)(q + 0xb3c));
            u8* obj = *(u8**)(q + 0xb3c);
            *(u32*)(obj + 0xf4) |= 1;
            *(u32*)(obj + 0x24) = 1;
            *(u8**)(q + 0xb3c) = 0;
        }
    }
    p[0x3bd] = 0;
}
#pragma use_lmw_stmw reset
extern "C" void fn_800E61E8(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    } else {
        fn_800E6770(p);
        *(s32*)(p + 0x310) = 0;
        *(f32*)(*(u8**)(p + 0x30c) + 8) = *(s32*)(p + 0x310);
        fn_8017A4F8(*(void**)(p + 0x2c));
        *(u16*)(p + 0xa9c) = *(s16*)(lbl_802C57D4 + 0x48);
        p[0xa76] = 4;
    }
}

extern "C" void fn_800E6478(u8* p) {
    if (p[0x340] != 0) {
        *(s32*)(p + 0x33c) = *(s32*)(p + 0x33c) + 1;
        u8* q = *(u8**)(p + 0x338);
        if (*(s32*)(p + 0x33c) >= *(s16*)(q + 6)) {
            *(s32*)(p + 0x33c) = *(s32*)(p + 0x33c) - *(s16*)(q + 6);
        }
    }
    *(f32*)(*(u8**)(p + 0x338) + 8) = (f32)*(s32*)(p + 0x33c);
    if (p[0x341] != 0) {
        *(s32*)(p + 0x334) = *(s32*)(p + 0x334) + 1;
        u8* r = *(u8**)(p + 0x330);
        if (*(s32*)(p + 0x334) >= *(s16*)(r + 6)) {
            *(s32*)(p + 0x334) = *(s32*)(p + 0x334) - *(s16*)(r + 6);
        }
    }
    *(f32*)(*(u8**)(p + 0x330) + 8) = (f32)*(s32*)(p + 0x334);
    fn_8017A4F8(*(void**)(p + 0x2c));
}

extern "C" s32 fn_800EC62C(void*, s32, u8, s32, s32, f32, f32);
extern "C" void fn_800E6554(u8* p) {
    u16 t = *(u16*)(p + 0xa9c);
    if (t != 0) {
        *(s16*)(p + 0xa9c) = t - 1;
        return;
    }
    if (*(s16*)(p + 0xb12) == 0) {
        p[0x340] = 1;
        fn_8002F358(0x9a, 0);
    }
    s32 r = fn_800EC62C(p, *(s16*)(p + 0xb12), (u8)lbl_802C57D4[0x28], 0, 0, *(f32*)(lbl_802C57D4 + 0x24), lbl_80301058);
    *(s16*)(p + 0xb12) = *(s16*)(p + 0xb12) + 1;
    if (r == 1) {
        *(s16*)(p + 0xb12) = 0;
        fn_8002F358(0x7f, 0);
        *(s16*)(p + 0xa9c) = *(s16*)(lbl_802C57D4 + 0x4c) * 6;
        p[0xa76] = 6;
    }
}

extern "C" void fn_800E6620(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xa76) = 7;
}

extern "C" void fn_800E6A4C(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u16*)((u8*)param_1 + 0xa9c) = 10;
    *(u8*)((u8*)param_1 + 0xb11) = 2;
    *(u8*)((u8*)param_1 + 0xa76) = 0x2a;
}

extern "C" void fn_800E6A80(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    } else if (fn_800EE044() != 0) {
        fn_8002F358(0xa5, 0);
        p[0xb11] = 1;
        p[0xa76] = 0x2c;
    }
}

extern "C" void fn_800E6AE8(u8* p) {
    if (*(s16*)(p + 0xb12) == 0) {
        fn_8002F358(0x9c, 0);
    }
    s32 a = fn_800EC744(p, *(s16*)(p + 0xb12), ((u8*)lbl_802C57D4)[0x10], lbl_80301058, *(f32*)((u8*)lbl_802C57D4 + 0xc), 0, 1);
    s32 b = fn_800EC85C(p, *(s16*)(p + 0xb12), ((u8*)lbl_802C57D4)[0x38], lbl_80301058, *(f32*)((u8*)lbl_802C57D4 + 0x34), 0, 1);
    *(s16*)(p + 0xb12) = *(s16*)(p + 0xb12) + 1;
    if (a == 1 && b == 1) {
        *(s16*)(p + 0xb12) = 0;
        p[0x341] = 0;
        *(u32*)((u8*)lbl_802BB0FC + 0x100) |= 0x20;
        p[0xa76] = 0;
    }
}

extern "C" void fn_800E6D44(void* param_1) {
    u8* p = (u8*)param_1;
    if (fn_800E6DA4(p) == 0) {
        fn_800589CC(2);
        fn_8002F358(0xca, 0);
        *(s16*)(p + 0xa9c) = *(s16*)(lbl_802C57D4 + 0x4a);
        p[0xa76] = 0x2f;
    }
}

extern "C" void fn_800E71CC(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
        return;
    }
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x100000;
    *(u32*)(lbl_802BB0FC + 0x100) &= 0xFFFFF87F;
    *(u8*)(p + 0xa4c) = 1;
    *(u8*)(p + 0xa76) = 0;
}

extern "C" void fn_800E7214(u8* p) {
    if (p[0xec] != 0) {
        *(s32*)(p + 0xe8) += 1;
        if (*(s16*)(*(u8**)(p + 0xe4) + 6) <= *(s32*)(p + 0xe8)) {
            *(s32*)(p + 0xe8) -= *(s16*)(*(u8**)(p + 0xe4) + 6);
        }
        *(f32*)(*(u8**)(p + 0xe4) + 8) = (f32)*(s32*)(p + 0xe8);
        *(s32*)(p + 0xf4) += 1;
        if (*(s16*)(*(u8**)(p + 0xf0) + 6) <= *(s32*)(p + 0xf4)) {
            *(s32*)(p + 0xf4) -= *(s16*)(*(u8**)(p + 0xf0) + 6);
        }
        *(f32*)(*(u8**)(p + 0xf0) + 8) = (f32)*(s32*)(p + 0xf4);
        fn_8017A4F8(*(void**)(p + 0xc));
    }
}

extern "C" void fn_800E72E4(u8* p) {
    if (p[0x4c4] != 0) {
        *(s32*)(p + 0x4c0) = *(s32*)(p + 0x4c0) + 1;
        s16 t = *(s16*)(*(u8**)(p + 0x4bc) + 6);
        if (*(s32*)(p + 0x4c0) >= t) {
            *(s32*)(p + 0x4c0) = *(s32*)(p + 0x4c0) - t;
        }
        f32 f = (f32)*(s32*)(p + 0x4c0);
        *(f32*)(*(u8**)(p + 0x4bc) + 8) = f;
        fn_8017A4F8(*(void**)(p + 0x14));
    }
}

extern "C" void fn_800E7364(u8* p) {
    if (p[0x4d0] != 0) {
        *(s32*)(p + 0x4cc) = *(s32*)(p + 0x4cc) + 1;
        s16 t = *(s16*)(*(u8**)(p + 0x4c8) + 6);
        if (*(s32*)(p + 0x4cc) >= t) {
            *(s32*)(p + 0x4cc) = *(s32*)(p + 0x4cc) - t;
        }
        *(f32*)(*(u8**)(p + 0x4c8) + 8) = (f32)*(s32*)(p + 0x4cc);
        fn_8017A4F8(*(void**)(p + 0x14));
    }
}

extern "C" void fn_800E79EC(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    } else {
        fn_8002F358(0xf2, 0);
        *(u8*)(*(u8**)(p + 0x564) + 0xb0) = 1;
        *(u16*)(p + 0xa9c) = (u8)lbl_802C57D4[0x64];
        p[0xa76] = 0x21;
    }
}

extern "C" void fn_800E7A5C(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    } else {
        fn_8002F358(0xf3, 0);
        p[0x4f4] = 0;
        *(u16*)(p + 0xa9c) = *(s16*)(lbl_802C57D4 + 0x60);
        p[0xa76] = 0x22;
    }
}

extern "C" void fn_800E7AC8(u8* p)
{
    s16 n;
    (*(u16*)(p + 0xa9c))--;
    p[0x574]++;
    n = *(s16*)(*(u8**)(p + 0x570) + 6);
    if ((s16)p[0x574] >= n) {
        p[0x574] -= n;
    }
    *(f32*)(*(u8**)(p + 0x570) + 8) = p[0x574];
    fn_8017A4F8(*(void**)(p + 0x1c));
    if (*(u16*)(p + 0xa9c) == 0) {
        *(u8*)(*(u8**)(p + 0x564) + 0xb0) = 0;
        *(u16*)(p + 0xa9c) = 0x1e;
        p[0xa76] = 0x23;
    }
}

extern "C" void fn_800E7B7C(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0xa9c) != 0) {
        *(u16*)((u8*)param_1 + 0xa9c) = *(u16*)((u8*)param_1 + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xa76) = 0;
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x10;
}

extern "C" void fn_800E7BB4(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    } else {
        fn_8002F358(0xf2, 0);
        *(u8*)(*(u8**)(p + 0x4ec) + 0xb0) = 1;
        *(u16*)(p + 0xa9c) = (u8)lbl_802C57D4[0x64];
        p[0xa76] = 0x25;
    }
}

extern "C" void fn_800E7C24(u8* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    } else {
        fn_8002F358(0xf3, 0);
        p[0x4f4] = 0;
        *(u16*)(p + 0xa9c) = *(s16*)(lbl_802C57D4 + 0x62);
        p[0xa76] = 0x26;
    }
}

extern "C" void fn_800E7C90(u8* p) {
    *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    p[0x4f4]++;
    u16 n = *(u16*)(*(u8**)(p + 0x4f0) + 6);
    if (p[0x4f4] >= (s16)n) {
        p[0x4f4] -= n;
    }
    *(f32*)(*(u8**)(p + 0x4f0) + 8) = p[0x4f4];
    fn_8017A4F8(*(void**)(p + 0x14));
    if (*(u16*)(p + 0xa9c) == 0) {
        (*(u8**)(p + 0x4ec))[0xb0] = 0;
        *(u16*)(p + 0xa9c) = 0x1e;
        p[0xa76] = 0x27;
    }
}

extern "C" void fn_800E7D44(void* p) {
    if (*(u16*)((u8*)p + 0xa9c) != 0) {
        *(u16*)((u8*)p + 0xa9c) = *(u16*)((u8*)p + 0xa9c) - 1;
        return;
    }
    *(u8*)((u8*)p + 0xa76) = 0;
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x8000;
}

extern "C" void fn_800E7D7C(u8* p) {
    s32 m = fn_80030390(*(u8*)((u8*)lbl_802B7CA0 + 0x1419));
    s32 bit = (*(u32*)((u8*)lbl_802BB0FC + 0x40) >> 1) & 1;
    s32 r = fn_8002192C();
    u8* t = (u8*)lbl_802B7CA0 + (bit + ((__cntlzw(1 - r) >> 4) & 0xfffffffe)) * 0xc + *(u8*)((u8*)lbl_802B7CA0 + 0x1419);
    p[0x4e9] = t[0x3bc];
    if (p[0xb15] != 0) {
        (*(u8**)(p + 0x5c8))[0xb0] = 1;
        (*(u8**)(p + 0x5cc))[0xb0] = 1;
    }
    if (bit == 1 || m == 0xb) {
        (*(u8**)(p + 0x5c8))[0xb0] = 0;
        (*(u8**)(p + 0x5cc))[0xb0] = 0;
        (*(u8**)(p + 0x5d0))[0xb0] = 0;
    }
}

extern "C" void fn_800E7E60(u8* p) {
    void* a;
    void* b;
    if (p[0xb49] == 1) {
        *(u8*)(*(u8**)(p + 0x9d8) + 0xb0) = 0;
    } else {
        *(u8*)(*(u8**)(p + 0x9d8) + 0xb0) = 1;
    }
    a = ((VObj_800E7E60*)*(u8**)(p + 0x24))->v13(0x72730000, 0x636f, 0x72736531);
    b = ((VObj_800E7E60*)*(u8**)(p + 0x24))->v13(0x72730000, 0x636f, 0x72736532);
    a = fn_80181BA0(a);
    b = fn_80181BA0(b);
    s32 n = fn_80030390(lbl_802B7CA0[0x1419]);
    fn_801E41AC(a, lbl_8028B50C, n + 1);
    fn_801E6768(b, (char*)a);
}

extern "C" void fn_800E8640(u8* p) {
    if (p[0x854] != 0) {
        *(s32*)(p + 0x848) = *(s32*)(p + 0x848) + 1;
        u8* a = *(u8**)(p + 0x844);
        s32 n = *(s32*)(p + 0x848);
        if (n >= *(s16*)(a + 6)) {
            *(s32*)(p + 0x848) = n - *(s16*)(a + 6);
        }
        *(f32*)(*(u8**)(p + 0x844) + 8) = (f32)*(s32*)(p + 0x848);
        *(s32*)(p + 0x850) = *(s32*)(p + 0x850) + 1;
        u8* b = *(u8**)(p + 0x84c);
        s32 m = *(s32*)(p + 0x850);
        if (m >= *(s16*)(b + 6)) {
            *(s32*)(p + 0x850) = m - *(s16*)(b + 6);
        }
        *(f32*)(*(u8**)(p + 0x84c) + 8) = (f32)*(s32*)(p + 0x850);
        fn_8017A4F8(*(void**)(p + 0x1c));
    }
}

extern u32 lbl_802FC710;
extern "C" void fn_800E87EC(u8* p);
extern "C" void fn_800E88D0(u8* p);
extern "C" void fn_800E8710(u8* p) {
    if (p[0x5dc] != 0) {
        if (*(u16*)(p + 0x5de) != 0) {
            *(u16*)(p + 0x5de) = *(u16*)(p + 0x5de) - 1;
            return;
        }
        fn_800E87EC(p);
        *(s32*)(p + 0x5d8) = *(s32*)(p + 0x5d8) + 1;
        if (*(s32*)(p + 0x5d8) >= *(s16*)(*(u8**)(p + 0x5d4) + 6)) {
            fn_800E88D0(p);
            *(s32*)(p + 0x5d8) = 0;
            lbl_802FC710 = lbl_802FC710 * 0x19660d + 0x3c6ef35f;
            *(u16*)(p + 0x5de) = ((lbl_802FC710 & 3) + 1) * 0x1e;
        }
        *(f32*)(*(u8**)(p + 0x5d4) + 8) = (f32)*(s32*)(p + 0x5d8);
        fn_8017A4F8(*(void**)(p + 0x1c));
    }
}

extern "C" void fn_800E87EC(u8* p) {
    f32 v[3];
    int r;
    if (p[0x5dd] == 0) {
        v[2] = lbl_80301058;
        if (*(u8*)(*(u8**)(p + 0x5a0) + 0xb0) != 0) {
            v[0] = (*(f32*)(p + 0x5ac) + fn_80177B10(*(void**)(p + 0x5a0))[0]) - lbl_803010EC;
            v[1] = (*(f32*)(p + 0x5b0) + fn_80177B10(*(void**)(p + 0x5a0))[1]) - lbl_803010F0;
            if (lbl_802FF0BC != 0) {
                r = fn_8004D308(lbl_802FF0BC, 8, 0x14, v, 0, 0, 0xff, 0, 0, 0, 0);
            } else {
                r = 0;
            }
            *(int*)(p + 0xb34) = r;
        } else {
            *(int*)(p + 0xb34) = 0;
        }
        p[0x5dd] = 1;
    }
}

extern "C" void fn_800E88D0(u8* p) {
    u8* obj = *(u8**)(p + 0xb34);
    if (obj != nullptr) {
        *(u32*)(obj + 0xf4) |= 1;
        *(s32*)(obj + 0x24) = 1;
    }
    *(u8*)(p + 0x5dd) = 0;
}

extern "C" void fn_800E8A08(u8* p) {
    if (p[0xb14] != 0) {
        p[0xb14]--;
    } else if (*(u32*)(lbl_802BB0FC + 0x100) & 1) {
        fn_800E927C(p);
        p[0xb14] = 0x3c;
        p[0xa76] = 0x32;
    }
}

extern "C" void fn_800E8A70(void* param_1) {
    u8* p = (u8*)param_1;
    u8 v = p[0xb14];
    if (v != 0) {
        p[0xb14] = v - 1;
        return;
    }
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x1000;
    *(u32*)(lbl_802BB0FC + 0xf8) |= 0x80000000;
    p[0xa76] = 0;
}

extern "C" void fn_800E8AB4(u8* p) {
    u8 v = p[0xb14];
    if (v != 0) {
        p[0xb14] = v - 1;
    } else if (fn_800EE044() != 0) {
        fn_8002F358(0xa5, 0);
        p[0xb11] = 1;
        p[0xb14] = 0xe;
        p[0xa76] = 0x34;
    }
}

extern "C" void fn_800E8B24(u8* p) {
    if (p[0xb14] != 0) {
        p[0xb14]--;
    } else {
        p[0x4c4] = 0;
        p[0xa76] = 0x35;
    }
}

extern "C" void fn_800E927C(u8* p);
extern "C" s32 fn_800EE044(void);
extern "C" void fn_800E9098(u8* p) {
    if (p[0xb14] != 0) {
        p[0xb14]--;
        return;
    }
    if (p[0x4e9] != 0) {
        u8 idx = p[0x4e9];
        *(u8*)(*(u8**)(p + 0x4a8 + idx * 4) + 0xb0) = 0;
    }
    *(u8*)(*(u8**)(p + 0x4a4) + 0xb0) = 1;
    *(u8*)(*(u8**)(p + 0x4b8) + 0xb0) = 1;
    p[0x4c4] = 1;
    *(u32*)(p + 0x4c0) = 0;
    *(u8*)(*(u8**)(p + 0x4ac + p[0x4e8] * 4) + 0xb0) = 1;
    p[0x4d0] = 1;
    *(u32*)(p + 0x4cc) = 0;
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x2000;
    p[0xa76] = 0;
}

extern "C" void fn_800E927C(u8* p) {
    u32** slot = (u32**)(p + 0xb18);
    u32* obj;
    s32 i;
    for (i = 0; i < 2; i++) {
        obj = slot[i];
        if (obj != 0) {
            obj[0xf4 / 4] |= 1;
            obj[0x24 / 4] = 1;
            slot[i] = 0;
        }
    }
    slot += 2;
    for (i = 0; i < 3; i++) {
        obj = slot[i];
        if (obj != 0) {
            obj[0xf4 / 4] |= 1;
            obj[0x24 / 4] = 1;
            slot[i] = 0;
        }
    }
}

extern "C" void fn_800EB018(void);
extern "C" void fn_800EA20C(u8* p) {
    if (p[0xb14] != 0) {
        p[0xb14]--;
    } else {
        fn_800EB018();
        p[0xa76] = 0x3c;
    }
}

extern "C" void fn_8002F358(s32 a, s32 b);
extern "C" void fn_800EA4BC(void* param_1) {
    s8 v = *(s8*)((u8*)param_1 + 0xa6a);
    if (v == 0) {
        fn_8002F358(0xe5, 0);
    } else if (v < 3) {
        fn_8002F358(0xe6, 0);
    } else if (v < 5) {
        fn_8002F358(0xe7, 0);
    } else if (v < 7) {
        fn_8002F358(0xe3, 0);
    } else if (v < 10) {
        fn_8002F358(0xe4, 0);
    } else {
        fn_8002F358(0xed, 0);
    }
}

extern "C" void fn_800EA564(void* param_1) {
    u8* p = (u8*)param_1;
    u8 v = p[0xb14];
    if (v != 0) {
        p[0xb14] = v - 1;
        return;
    }
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x4000000;
    p[0xa76] = 0;
}

extern "C" s32 fn_800EA6D0(void* param_1, s32 param_2);
extern "C" void fn_800EA59C(void* param_1) {
    u8* p = (u8*)param_1;
    *(s32*)(p + 0xa88) = fn_800EA6D0(param_1, (s8)p[0xa6a] + 1);
    p[0xa76] = 0x3f;
}

extern "C" s32 fn_800ED994(u8*, s32, s32, f32, f32, s32, s32);
extern "C" s32 fn_800ED83C(u8*, s32, s32, s32, f32, f32, f32, f32, s32, s32);
extern "C" void fn_800EA5E0(u8* p) {
    s32 iVar1;
    s32 iVar2;
    if (fn_8002F168(p) != 1) {
        if (*(s16*)(p + 0xb12) == 0) {
            fn_8002F358(0xec, 0);
        }
        iVar1 = fn_800ED994(p, *(s16*)(p + 0xb12), (u8)lbl_802C57D4[0x75], lbl_80301058, *(f32*)(lbl_802C57D4 + 0x7c), 0, 0);
        iVar2 = fn_800ED83C(p, 8, *(s16*)(p + 0xb12), (u8)lbl_802C57D4[0x75], lbl_80301058, *(f32*)(lbl_802C57D4 + 0x7c), lbl_80301058, lbl_80301058, 0, 2);
        *(s16*)(p + 0xb12) = *(s16*)(p + 0xb12) + 1;
        if (iVar1 == 1 && iVar2 == 1) {
            *(s16*)(p + 0xb12) = 0;
            p[0xb14] = lbl_802C57D4[0x81];
            p[0xa76] = 0x40;
        }
    }
}

extern "C" void fn_800EA848(u8* p) {
    if (p[0xb14] != 0) {
        p[0xb14]--;
    } else {
        p[0xb14] = lbl_802C57D4[0x81];
        fn_8002F0A8(*(int*)(p + 0xa88));
        p[0xa76] = 0x41;
    }
}

extern "C" void fn_800EAA4C(u8* p) {
    ((s8*)p)[0xa4d]--;
    fn_800E7F50(p, p[0xa4e], ((s8*)p)[0xa4d], 0);
    fn_8002F458(0xa7, 0);
    p[0xa76] = 0x4b;
    p[0xa77] = 0x43;
}

extern "C" void fn_800EAAB0(u8* p) {
    *(u16*)(p + 0xa9c) = (u8)lbl_802C57D4[0x95];
    p[0xa76] = 0x49;
}

extern "C" void fn_800EAFA8(void* p) {
    *(u32*)(lbl_802BB0FC + 0x100) |= 0x4000000;
    *(u8*)((u8*)p + 0xa8c) = 0;
    *(u8*)((u8*)p + 0xa76) = 0;
}

extern "C" s32 fn_8002F168(u8* p);
extern "C" void fn_800EAFCC(u8* p) {
    if (fn_8002F168(p) != 1) {
        *(u16*)(p + 0xa9c) = (u8)lbl_802C57D4[0x95];
        p[0xa76] = 0x49;
    }
}

extern "C" void fn_800EB138(u8* p) {
    if ((s8)p[0xa6a] <= 2) {
        f32 y = (*(f32*)(p + 0x864) + fn_80177B10(*(void**)(p + 0x888))[1]) - lbl_803010F0;
        f32 x = fn_80177B10(*(void**)(p + 0x888))[0];
        x = (*(f32*)(p + 0x860) + x) - lbl_803010EC;
        u8* obj = *(u8**)(p + 0xb2c);
        f32 z = lbl_80301058;
        *(f32*)(obj + 0xa4) = x;
        *(f32*)(obj + 0xa8) = y;
        *(f32*)(obj + 0xac) = z;
        obj = *(u8**)(p + 0xb30);
        *(f32*)(obj + 0xa4) = x;
        *(f32*)(obj + 0xa8) = y;
        *(f32*)(obj + 0xac) = z;
    }
}

extern "C" void fn_800EB6E0(char* p) {
    if (*(u16*)(p + 0xa9c) != 0) {
        *(u16*)(p + 0xa9c) = *(u16*)(p + 0xa9c) - 1;
    } else {
        fn_800EBD88(p);
        p[0xa76] = 0x4a;
    }
}

extern "C" void fn_800EBD88(char* p) {
    p[0xb11] = 2;
    p[0xb14] = 10;
    *(unsigned char*)(*(char**)(p + 0x9e8) + 0xb0) = 1;
    p[0xa00] = lbl_802C57D4[0x80];
    p[0xa01] = 0;
}

extern "C" void fn_800EC0E4(void* param_1) {
    if (*(u8*)((u8*)param_1 + 0xb14) != 0) {
        *(u8*)((u8*)param_1 + 0xb14) = *(u8*)((u8*)param_1 + 0xb14) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xa76) = *(u8*)((u8*)param_1 + 0xa77);
}

extern "C" int fn_800ED4DC(u8* param_1, s16 param_2, u8 param_3, s32 param_4, s32 param_5) {
    float f;
    s32 mode = param_5;
    if (*(u8*)(*(u8**)(param_1 + 0x64) + 0xb0) == 0) {
        return 1;
    }
    if (param_2 < 0) {
        return 0;
    }
    if (param_2 > param_3) {
        return 1;
    }
    f = fn_800EE11C(param_1, param_3, param_2);
    if (mode == 1) {
        f = lbl_803010D0 - f;
    }
    (*(VObj_800D73FC**)(param_1 + 0x64))->v7((int)((float)*(u8*)(param_1 + 0x70) * f));
    return 0;
}

extern "C" void fn_800EDBB4(u8* p) {
    s32 v = p[0xb48];
    if (v != 1 && v >= 1 && v < 5) {
        char* base = lbl_802B7CA0 + 0x1424;
        fn_80060794(base, base + 0x204, base + 0x208, p + 8);
    }
}

extern "C" void fn_800EE0F0(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 4));
}

extern "C" void fn_800EE344(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80301058;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800EE3A8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028B80C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
