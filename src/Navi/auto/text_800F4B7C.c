#include "types.h"
extern char lbl_802C5A84[];
extern "C" s32 fn_801086F8(void* self, s16 a, u8 b, s32 c, s32 d, f32 e, f32 f);
extern char lbl_8029FDB4[];
extern char lbl_8028D72C[];
extern "C" void fn_800127A0(void* p);
extern "C" u8 fn_801081D0(char*);
extern "C" void fn_800F4D3C(void*);
extern "C" void fn_801080E8(void*);
extern "C" void fn_8002F7C0(void*, s32);
extern "C" void fn_801071C4(void* self);
extern f64 lbl_80301210;
extern "C" void fn_8017A4F8(void* p);
extern "C" s32 fn_80108B20(void* self, s16 a, u8 b, s32 c, s32 d, f32 e, f32 f);
extern "C" s32 fn_80108C38(void* self, s16 a, u8 b, s32 c, s32 d, f32 e, f32 f);
extern "C" s32 fn_80108D50(void* self, s16 a, u8 b, s32 c, s32 d, f32 e, f32 f);
extern f32 lbl_80301204;
extern "C" s32 fn_80108928(void* self, s16 a, u8 b, f32 c, s32 d, s32 e, f32 f, f32 g, f32 h);
extern "C" void fn_80106CBC(void* self);
extern "C" s32 fn_801095A4(void* self, s16 a, u8 b, f32 c, f32 d, s32 e, s32 f);
extern "C" s32 fn_801096BC(void* self, s16 a, u8 b, void* c, s32 d);
extern "C" s32 fn_8002F87C(void);
extern "C" void fn_8002F458(void* p, s32 off);
extern "C" void fn_8002F7C0(void* p, s32 b);
extern "C" s32 fn_80108810(void* self, s16 a, u8 b, s32 c, s32 d, f32 e, f32 f);

struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800f4b7c-0x80109cbc (185 functions). split_file divides it into the game's real files.

struct VObj_800F4B7CListener {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(f32 a, f32 b);
};

struct VObj_80103560 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(u8 a);
};

struct Unk80104320 {
    u8 pad[0x238];
    VObj_80103560* objs[2];
    u8 pad2[8];
    u8 vals[2];
    u8 pad3[2];
    VObj_80103560* objs2[2];
    u8 vals2[2];
    u8 sel;
    u8 pad4[3];
    u8 flag;
};

struct Unk80103560 {
    u8 pad[0x498];
    VObj_80103560* objs[2];
    u8 vals[2];
    u8 pad2[0x524 - 0x4a2];
    u8 sel;
    u8 pad3;
    u8 count;
};

struct VObj_80103664 {
    virtual void v0();
    virtual void v1();
    virtual void v2(f32 a, f32 b);
};

struct Unk80103664 {
    u8 pad[0x46c];
    VObj_80103664* obj;
    u8 pad2[0x4cc - 0x470];
    s8 i2;
    s8 i1;
    u8 pad3[2];
    f32 a[3][6];
    f32 b[3];
};

extern "C" s32 fn_801092B8(void* self, u8 a, u8 b, s32 c);
extern "C" void fn_8017A4F8(void* p);
extern char lbl_802C5A84[];

extern void* lbl_8028E960[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" s32 fn_8002F6BC(void* p);
extern "C" s32 fn_80108030(void* p);
extern "C" void fn_8002F358(s32 a, s32 b);
extern "C" void fn_8002F198(void);
extern "C" void fn_80030418(s32 a, s32 b);
extern "C" f32 fn_801099E8(void* self, u8 b, s16 a, ...);
extern f32 lbl_80301208;
struct VObj_80108104 {
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
};
struct VObj_801096BC {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(s32 a);
};
extern char lbl_802B7CA0[];
extern char lbl_802BB0FC[];
extern f32 lbl_80301204;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_8015FDA8(void*, void*);
extern u8 lbl_8028D80C[];
extern u32 lbl_802FECA4;
extern "C" u8 fn_800126C8(void* a, void* b, void* c);
extern "C" void fn_800F4D38(void* p);
extern "C" void fn_800FFB98(void* p);
extern "C" void fn_800FFBA4(void* p);
extern f32 lbl_803011E0;
extern f32 lbl_803011E4;
extern f32 lbl_803011E8;
extern f32 lbl_803011EC;
extern f32 lbl_803011F0;
extern f32 lbl_803011F4;
extern f32 lbl_803011F8;
extern f32 lbl_803011FC;
extern f32 lbl_80301200;
extern "C" void fn_800F4B7C(u8* p) {
    f32 f0 = lbl_80301200;
    f32 f1 = lbl_803011FC;
    f32 f2 = lbl_803011F8;
    f32 f3 = lbl_803011F4;
    f32 f4 = lbl_803011F0;
    f32 f5 = lbl_803011EC;
    f32 f6 = lbl_803011E8;
    f32 f7 = lbl_803011E4;
    f32 f8 = lbl_803011E0;

    *(void**)(p + 0x0) = lbl_8028E960;
    *(s8*)(p + 0x4) = -1;
    *(u32*)(p + 0x8) = 0;
    *(f32*)(p + 0xc) = f8;
    *(u8*)(p + 0x10) = 10;
    *(f32*)(p + 0x14) = f7;
    *(u8*)(p + 0x18) = 10;
    *(f32*)(p + 0x1c) = f8;
    *(u8*)(p + 0x20) = 10;
    *(u8*)(p + 0x21) = 4;
    *(u8*)(p + 0x22) = 30;
    *(u8*)(p + 0x23) = 200;
    *(u8*)(p + 0x24) = 0;
    *(u8*)(p + 0x25) = 15;
    *(u8*)(p + 0x26) = 15;
    *(f32*)(p + 0x28) = f6;
    *(f32*)(p + 0x2c) = f5;
    *(u8*)(p + 0x3d) = 5;
    *(f32*)(p + 0x44) = f7;
    *(f32*)(p + 0x40) = f4;
    *(u8*)(p + 0x48) = 30;
    *(u8*)(p + 0x49) = 30;
    *(u8*)(p + 0x30) = 15;
    *(f32*)(p + 0x34) = f3;
    *(f32*)(p + 0x38) = f2;
    *(u8*)(p + 0x3c) = 10;
    *(f32*)(p + 0x4c) = f8;
    *(u8*)(p + 0x50) = 10;
    *(f32*)(p + 0x54) = f1;
    *(u8*)(p + 0x58) = 10;
    *(u8*)(p + 0x59) = 5;
    *(u8*)(p + 0x5a) = 15;
    *(f32*)(p + 0x5c) = f8;
    *(u8*)(p + 0x60) = 10;
    *(u8*)(p + 0x61) = 10;
    *(u8*)(p + 0x62) = 30;
    *(u8*)(p + 0x63) = 180;
    *(u8*)(p + 0x64) = 90;
    *(f32*)(p + 0x68) = f0;
}

extern "C" void fn_800F4C70(u8* p) {
    if ((s8)lbl_802C5A84[4] < 0) {
        lbl_802C5A84[4] = fn_800126C8(lbl_8029FDB4 + 4, lbl_8028D80C, lbl_802C5A84);
    }
    *(s32*)(lbl_802C5A84 + 8) += 1;
    *(u32*)(p + 4) = lbl_802FECA4;
    fn_800F4D38(p);
    fn_800FFB98(p);
    fn_800FFBA4(p);
    *(u32*)(p + 0x24) = 0;
    *(u32*)(p + 0x34) = 0;
    *(u32*)(p + 0x44) = 0;
    p[0x1e0] = 0;
    p[0x1e1] = 0;
    p[0x256] = 0;
    *(u32*)(p + 0x238) = 0;
    *(u32*)(p + 0x23c) = 0;
    p[0xf2] = 0;
    p[0x194] = 0;
    p[0xee] = 0;
}

extern "C" void fn_800F4D38(void* p) {}

extern "C" void fn_800F7DAC(void) {}

extern char lbl_802995B0[];
extern char lbl_80286A4C[];
extern char lbl_80286A30[];
extern "C" void* fn_800F7E40(void* param_1, s16 param_2);
extern "C" void fn_801E0CC4(void*, void*);
extern "C" void* fn_800F7DB0(void** p, s16 param_2) {
    if (p != 0) {
        p[0] = lbl_802995B0;
        fn_801E0CC4(p[0xc], (void*)fn_800F7E40);
        if (&p[8] != 0) {
            p[8] = lbl_80286A4C;
        }
        if (p != 0) {
            p[0] = lbl_80286A30;
        }
        if (param_2 > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void fn_8015AB1C(void*);
extern "C" void* fn_800F7E40(void* param_1, s16 param_2) {
    if (param_1) {
        fn_8015AB1C(*(void**)((u8*)param_1 + 4));
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_800FFB98(void* p) { *(s16*)((u8*)p + 0xec) = 0; }

extern "C" void fn_800FFBA4(void* p) {
    *(unsigned char*)((char*)p + 0x4cc) = 0;
    *(unsigned char*)((char*)p + 0x4cd) = 0;
    *(unsigned char*)((char*)p + 0x193) = 0;
    *(unsigned char*)((char*)p + 0xf1) = 0;
}

extern "C" BOOL fn_800FFBBC(void)
{
    return TRUE;
}

extern "C" BOOL fn_800FFBC4(void);
extern "C" BOOL fn_800FFBC4(void)
{
    return TRUE;
}

struct NaviState_800FFBCC;
typedef void (NaviState_800FFBCC::*NaviStateFn_800FFBCC)();
extern NaviStateFn_800FFBCC lbl_8028DD1C[];
extern "C" void fn_800FFBCC(NaviState_800FFBCC* p) {
    ((u8*)p)[0xf2] = 0;
    (p->*lbl_8028DD1C[((u8*)p)[0xee]])();
}

extern u8 lbl_802FF189;
extern "C" void fn_800FFEF0(void* param_1) {
    fn_8002F458((void*)0xab, 0);
    fn_8002F7C0((void*)0x33, 0);
    *(u8*)((u8*)param_1 + 0xf2) = 9;
    if (*(u8*)((u8*)param_1 + 0x190) != 0) {
        lbl_802FF189 = 1;
        *(u8*)((u8*)param_1 + 0x190) = 0;
    }
    u8 bVar1 = *(u8*)((u8*)param_1 + 0x18a);
    if (bVar1 < 0xd) {
        if (bVar1 == 1) {
            *(s16*)((u8*)param_1 + 0xec) = *(u8*)(lbl_802C5A84 + 0x10);
        } else {
            *(s16*)((u8*)param_1 + 0xec) = 0;
        }
        *(u8*)((u8*)param_1 + 0x189) = 0xc;
    } else {
        if (bVar1 >= 0x43) {
            *(s16*)((u8*)param_1 + 0xec) = *(u8*)(lbl_802C5A84 + 0x10);
        } else {
            *(s16*)((u8*)param_1 + 0xec) = 0;
        }
        *(u8*)((u8*)param_1 + 0x189) = 0x44;
    }
}

extern "C" void fn_800FFFBC(u8* p) {
    if (fn_8002F87C() == 0 && fn_801081D0((char*)p) == 1) {
        fn_800F4D3C(p);
        fn_801080E8(p);
        p[0x193] = 1;
        ((u8*)(*(void**)(p + 0xd4)))[0xb0] = 1;
        fn_8002F7C0((void*)6, 0);
        *(s16*)(p + 0x528) = 0x10e;
        p[0xf2] = 2;
        p[0x188] = 0;
        p[0x194] = 1;
        p[0x189] = 1;
    }
}

extern "C" void fn_80100054(void* param_1) {
    u16 t = *(u16*)((u8*)param_1 + 0x528);
    *(u16*)((u8*)param_1 + 0x528) = t - 1;
    if (*(u16*)((u8*)param_1 + 0x18c) != 0) {
        *(u8*)((u8*)param_1 + 0xf2) = 1;
        *(u8*)((u8*)param_1 + 0x188) = 1;
        fn_8002F458((void*)0xad, 0);
        *(u16*)((u8*)param_1 + 0xec) = (u8)lbl_802C5A84[0x10];
        *(u8*)((u8*)param_1 + 0x189) = 6;
    }
    if (*(u16*)((u8*)param_1 + 0x528) == 0) {
        *(u8*)((u8*)param_1 + 0x189) = 2;
    }
}

extern "C" void fn_801000D8(void* param_1) {
    if (*(s16*)((u8*)param_1 + 0xec) == 0) {
        fn_8002F458((void*)0x9a, 0);
    }
    s32 iVar1 = fn_801086F8(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x10), 0, 0, *(f32*)(lbl_802C5A84 + 0xc), lbl_80301204);
    *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
    if (iVar1 == 1) {
        *(s16*)((u8*)param_1 + 0xec) = 0;
        *(u8*)((u8*)param_1 + 0x189) = 3;
    }
}

extern "C" void fn_80100164(void* param_1) {
    if (fn_8002F87C() != 0) {
        if (*(u16*)((u8*)param_1 + 0x18c) != 0) {
            *(u8*)((u8*)param_1 + 0xf2) = 1;
            *(u8*)((u8*)param_1 + 0x188) = 1;
            fn_8002F458((void*)0xad, 0);
            *(u8*)((u8*)param_1 + 0x189) = 6;
        }
    } else {
        *(u8*)((u8*)param_1 + 0xf2) = 0xb;
        *(u8*)((u8*)param_1 + 0x188) = 1;
        *(u8*)((u8*)param_1 + 0xef) = 8;
        *(u8*)((u8*)param_1 + 0x189) = 4;
    }
}

extern "C" void fn_801001E8(u8* p) {
    if (p[0xef] != 0) {
        p[0xef]--;
    } else {
        p[0xf2] = 2;
        p[0xef] = 8;
        p[0x189] = 5;
    }
}

extern "C" void fn_8010021C(u8* p) {
    if (p[0xef] != 0) {
        p[0xef]--;
    } else {
        p[0x188] = 0;
        if (*(u16*)(p + 0x18c) != 0) {
            p[0xf2] = 0xe;
            p[0x188] = 1;
            fn_8002F458((void*)0xad, 0);
            p[0x189] = 6;
        }
    }
}

extern "C" void fn_80100294(void* param_1) {
    if (*(s16*)((u8*)param_1 + 0xec) == 0) {
        fn_8002F458((void*)0x9c, 0);
    }
    s32 iVar1 = fn_801086F8(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x10), 0, 1, lbl_80301204, *(f32*)(lbl_802C5A84 + 0xc));
    *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
    if (iVar1 == 1) {
        *(s16*)((u8*)param_1 + 0xec) = 0;
        *(u8*)(*(u32*)((u8*)param_1 + 0xe4) + 0xb0) = 0;
        *(u8*)(*(u32*)((u8*)param_1 + 0xe8) + 0xb0) = 1;
        *(u8*)((u8*)param_1 + 0x189) = 7;
    }
}

extern "C" void fn_80100334(void* param_1) {
    if (*(s16*)((u8*)param_1 + 0xec) == 0) {
        fn_8002F458((void*)0x9a, 0);
    }
    s32 iVar1 = fn_801086F8(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x10), 0, 0, *(f32*)(lbl_802C5A84 + 0xc), lbl_80301204);
    *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
    if (iVar1 == 1) {
        *(s16*)((u8*)param_1 + 0xec) = 0;
        *(u8*)((u8*)param_1 + 0x188) = 0;
        *(u8*)((u8*)param_1 + 0xf2) = 2;
        fn_8002F7C0((void*)0x35, 0);
        *(u8*)((u8*)param_1 + 0x189) = 8;
    }
}

extern "C" void fn_8010046C(void* param_1) {
    u8* p = (u8*)param_1;
    if (p[0xef] != 0) {
        p[0xef]--;
    } else {
        p[0xf2] = 2;
        p[0xef] = 8;
        p[0x189] = 10;
    }
}

extern "C" void fn_80100524(void* param_1) {
    if (fn_8002F87C() == 0) {
        if (*(s16*)((u8*)param_1 + 0xec) == 0) {
            fn_8002F458((void*)0x9c, 0);
        }
        s32 iVar1 = fn_801086F8(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x10), 0, 1, lbl_80301204, *(f32*)(lbl_802C5A84 + 0xc));
        *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
        if (iVar1 == 1) {
            *(s16*)((u8*)param_1 + 0xec) = 0;
            *(u8*)(*(u32*)((u8*)param_1 + 0xd4) + 0xb0) = 0;
            *(u8*)(*(u32*)((u8*)param_1 + 0x128) + 0xb0) = 0;
            *(u8*)(*(u32*)((u8*)param_1 + 0xf4) + 0xb0) = 1;
            *(u8*)(*(u32*)((u8*)param_1 + 0x114) + 0xb0) = 1;
            *(u8*)(*(u32*)((u8*)param_1 + 0x11c) + 0xb0) = 0;
            *(u8*)((u8*)param_1 + 0x189) = 0xd;
        }
    }
}

extern "C" void fn_8010095C(void* param_1) {
    if (fn_8002F87C() != 0) {
        if (*(u16*)((u8*)param_1 + 0x18c) != 0) {
            fn_8002F458((void*)0xad, 0);
            fn_8002F7C0((void*)0x8, 0);
            *(u32*)((u8*)param_1 + 0x124) = 0;
            *(u8*)((u8*)*(void**)((u8*)param_1 + 0x110) + 0xb0) = 1;
            *(u16*)((u8*)param_1 + 0x528) = 8;
            *(u8*)((u8*)param_1 + 0xf2) = 0xe;
            *(u8*)((u8*)param_1 + 0x188) = 1;
            *(u8*)((u8*)param_1 + 0x189) = 0x11;
        }
    } else {
        *(u8*)((u8*)param_1 + 0xf2) = 0xb;
        *(u8*)((u8*)param_1 + 0x188) = 1;
        *(u16*)((u8*)param_1 + 0x528) = 8;
        *(u8*)((u8*)param_1 + 0x189) = 0xf;
    }
}

extern "C" void fn_80100A08(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0x189) = 0x10;
}

extern "C" void fn_80100A3C(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x188) = 0;
    if (*(u16*)((u8*)param_1 + 0x18c) != 0) {
        fn_8002F458((void*)0xad, 0);
        fn_8002F7C0((void*)0x8, 0);
        *(u32*)((u8*)param_1 + 0x124) = 0;
        *(u8*)((u8*)*(void**)((u8*)param_1 + 0x110) + 0xb0) = 1;
        *(u16*)((u8*)param_1 + 0x528) = 8;
        *(u8*)((u8*)param_1 + 0xf2) = 0xe;
        *(u8*)((u8*)param_1 + 0x188) = 1;
        *(u8*)((u8*)param_1 + 0x189) = 0x11;
    }
}

extern "C" void fn_80100AD8(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u8*)((u8*)param_1 + 0x189) = 0x12;
}

extern "C" void fn_80100B0C(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x188) = 0;
    *(u8*)((u8*)param_1 + 0x189) = 0x13;
}

extern "C" void fn_80101004(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0x189) = 0x17;
}

extern "C" void fn_80101038(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x188) = 0;
    *(u8*)((u8*)param_1 + 0x189) = 0x18;
}

extern "C" void fn_80101064(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x18c) != 0) {
        fn_8002F458((void*)0xad, 0);
        *(u8*)(*(u8**)((u8*)param_1 + 0x110) + 0xb0) = 0;
        *(u8*)(*(u8**)((u8*)param_1 + 0x114) + 0xb0) = 0;
        *(u8*)(*(u8**)((u8*)param_1 + 0x11c) + 0xb0) = 1;
        *(u16*)((u8*)param_1 + 0x528) = 8;
        *(u8*)((u8*)param_1 + 0xf2) = 0xe;
        *(u8*)((u8*)param_1 + 0x188) = 1;
        *(u32*)((u8*)param_1 + 0x124) = 0;
        fn_8002F7C0((void*)9, 0);
        *(u8*)((u8*)param_1 + 0x189) = 0x19;
    }
}

extern "C" void fn_801010F0(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0x189) = 0x1a;
}

extern "C" void fn_80101124(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x188) = 0;
    *(u8*)((u8*)param_1 + 0x189) = 0x1b;
}

extern "C" void fn_80101150(void* self) {
    u8* p = (u8*)self;
    if (fn_8002F87C() != 0) {
        if (*(u16*)(p + 0x18c) != 0) {
            fn_8002F458((void*)0xad, 0);
            fn_8002F7C0((void*)0xa, 0);
            *(u8*)(*(u8**)(p + 0x110) + 0xb0) = 1;
            *(s32*)(p + 0x124) = 0;
            *(f32*)(*(u8**)(p + 0x120) + 8) = (f32)*(s32*)(p + 0x124);
            fn_8017A4F8(*(void**)(p + 0x1c));
            *(u16*)(p + 0x528) = 8;
            *(u8*)(p + 0xf2) = 0xe;
            *(u8*)(p + 0x188) = 1;
            *(u8*)(p + 0x189) = 0x1f;
        }
    } else {
        *(u16*)(p + 0x528) = 8;
        *(u8*)(p + 0xf2) = 0xb;
        *(u8*)(p + 0x188) = 1;
        *(u8*)(p + 0x189) = 0x1c;
    }
}

extern "C" void fn_80101230(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0x189) = 0x1d;
}

extern "C" void fn_80101264(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x188) = 0;
    *(u8*)((u8*)param_1 + 0x189) = 0x1e;
}

extern "C" void fn_80101290(u8* p) {
    if (*(u16*)(p + 0x18c) != 0) {
        fn_8002F458((void*)0xad, 0);
        fn_8002F7C0((void*)0xa, 0);
        *(u8*)(*(u8**)(p + 0x110) + 0xb0) = 1;
        *(s32*)(p + 0x124) = 0;
        *(f32*)(*(u8**)(p + 0x120) + 8) = (f32)((f64)*(s32*)(p + 0x124) - lbl_80301210);
        fn_8017A4F8(*(void**)(p + 0x1c));
        *(u16*)(p + 0x528) = 8;
        *(u8*)(p + 0xf2) = 0xe;
        *(u8*)(p + 0x188) = 1;
        *(u8*)(p + 0x189) = 0x1f;
    }
}

extern "C" void fn_80101340(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0x189) = 0x20;
}

extern "C" void fn_80101374(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x188) = 0;
    *(u8*)((u8*)param_1 + 0x189) = 0x21;
}

extern "C" void fn_80101694(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0x189) = 0x24;
}

extern "C" void fn_801016C8(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x188) = 0;
    *(u8*)((u8*)param_1 + 0x189) = 0x25;
}

extern "C" void fn_801016F4(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x18c) != 0) {
        fn_8002F458((void*)0xad, 0);
        *(u16*)((u8*)param_1 + 0x528) = 8;
        *(u8*)((u8*)param_1 + 0xf2) = 0xe;
        *(u8*)((u8*)param_1 + 0x188) = 1;
        *(u8*)((u8*)param_1 + 0x189) = 0x26;
    }
}

extern "C" void fn_80101754(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0x189) = 0x27;
}

extern "C" void fn_80101788(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x188) = 0;
    *(u8*)((u8*)param_1 + 0x189) = 0x28;
}

extern "C" void fn_80101900(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0x189) = 0x2a;
}

extern "C" void fn_80101934(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x188) = 0;
    *(u8*)((u8*)param_1 + 0x189) = 0x2b;
}

extern "C" void fn_80101960(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x18c) != 0) {
        fn_8002F458((void*)0xad, 0);
        *(u8*)((u8*)param_1 + 0xf2) = 0xe;
        *(u8*)((u8*)param_1 + 0x188) = 1;
        *(u16*)((u8*)param_1 + 0x528) = 8;
        *(u8*)((u8*)param_1 + 0x189) = 0x2c;
    }
}

extern "C" void fn_801019C0(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
    } else {
        if (*(s16*)((u8*)param_1 + 0xec) == 0) {
            fn_8002F458((void*)0x9c, 0);
        }
        s32 iVar1 = fn_80108810(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x10), 0, 1, lbl_80301204, *(f32*)(lbl_802C5A84 + 0xc));
        *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
        if (iVar1 == 1) {
            *(s16*)((u8*)param_1 + 0xec) = 0;
            *(u8*)(*(u32*)((u8*)param_1 + 0x12c) + 0xb0) = 0;
            *(u8*)(*(u32*)((u8*)param_1 + 0x150) + 0xb0) = 1;
            *(u32*)(lbl_802BB0FC + 0xf8) |= 0x20000000;
            fn_8002F7C0((void*)0x36, 0);
            *(u8*)((u8*)param_1 + 0x189) = 0x2d;
        }
    }
}

extern "C" void fn_80101A98(void* param_1) {
    s32 iVar1 = fn_8002F87C();
    if (iVar1 == 0) {
        if (*(s16*)((u8*)param_1 + 0xec) == 0) {
            fn_8002F458((void*)0x9c, 0);
        }
        iVar1 = fn_80108810(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x10), 0, 0, *(f32*)(lbl_802C5A84 + 0xc), lbl_80301204);
        *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
        if (iVar1 == 1) {
            *(s16*)((u8*)param_1 + 0xec) = 0;
            *(u16*)((u8*)param_1 + 0x528) = 0x1e;
            *(u8*)((u8*)param_1 + 0x189) = 0x2e;
        }
    }
}

extern "C" void fn_80101B38(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u8*)((u8*)param_1 + 0x189) = 0x2f;
}

extern "C" void fn_80101FD0(void* self) {
    u8* p = (u8*)self;
    if (*(u16*)(p + 0x18c) != 0) {
        fn_8002F458((void*)0xad, 0);
        *(u8*)(*(u8**)(p + 0x104) + 0xb0) = 0;
        *(u8*)(*(u8**)(p + 0x128) + 0xb0) = 1;
        *(u8*)(*(u8**)(p + 0x164) + 0xb0) = 1;
        *(u16*)(p + 0x528) = 8;
        p[0xf2] = 0xe;
        p[0x188] = 1;
        if (p[0x190] != 0) {
            lbl_802FF189 = 1;
            p[0x190] = 0;
        }
        p[0x189] = 0x36;
    } else {
        if (p[0xef] != 0) {
            p[0xef]--;
            if (p[0xef] == 0x78) {
                fn_8002F358(0x115, 0);
            }
        } else if (fn_8002F87C() == 0) {
            p[0xf2] = 0xb;
            p[0x188] = 1;
            *(u16*)(p + 0x528) = 8;
            p[0x189] = 0x33;
        }
    }
}

extern "C" void fn_801020C0(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u8*)((u8*)param_1 + 0x189) = 0x34;
}

extern "C" void fn_801020F4(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x188) = 0;
    *(u8*)((u8*)param_1 + 0x189) = 0x35;
}

extern "C" void fn_80102120(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x18c) != 0) {
        fn_8002F458((void*)0xad, 0);
        *(u8*)(*(u8**)((u8*)param_1 + 0x104) + 0xb0) = 0;
        *(u8*)(*(u8**)((u8*)param_1 + 0x128) + 0xb0) = 1;
        *(u8*)(*(u8**)((u8*)param_1 + 0x164) + 0xb0) = 1;
        *(u16*)((u8*)param_1 + 0x528) = 8;
        *(u8*)((u8*)param_1 + 0xf2) = 0xe;
        *(u8*)((u8*)param_1 + 0x188) = 1;
        *(u8*)((u8*)param_1 + 0x189) = 0x36;
    }
}

extern "C" void fn_8010219C(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u8*)((u8*)param_1 + 0x189) = 0x37;
}

extern "C" void fn_801021D0(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
    } else {
        fn_8002F7C0((void*)0x39, 0);
        *(u32*)((u8*)param_1 + 0x16c) = 0;
        *(u8*)((u8*)param_1 + 0x188) = 0;
        *(u8*)((u8*)param_1 + 0x189) = 0x38;
    }
}

extern "C" void fn_80102344(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u8*)((u8*)param_1 + 0x189) = 0x3a;
}

extern "C" void fn_80102378(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x188) = 0;
    *(u8*)((u8*)param_1 + 0x189) = 0x3b;
}

extern "C" void fn_801023A4(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x18c) != 0) {
        fn_8002F458((void*)0xad, 0);
        *(u16*)((u8*)param_1 + 0x528) = 8;
        *(u8*)((u8*)param_1 + 0xf2) = 0xe;
        *(u8*)((u8*)param_1 + 0x188) = 1;
        *(u8*)((u8*)param_1 + 0x189) = 0x3c;
    }
}

extern "C" void fn_80102404(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)*(void**)((u8*)param_1 + 0x164) + 0xb0) = 0;
    *(u8*)((u8*)*(void**)((u8*)param_1 + 0x170) + 0xb0) = 1;
    *(u8*)((u8*)*(void**)((u8*)param_1 + 0x174) + 0xb0) = 1;
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u8*)((u8*)param_1 + 0x189) = 0x3d;
}

extern "C" void fn_80102458(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
    } else {
        fn_8002F7C0((void*)0x3a, 0);
        *(u32*)((u8*)param_1 + 0x184) = 0;
        *(u8*)((u8*)param_1 + 0x188) = 0;
        *(u8*)((u8*)param_1 + 0x189) = 0x3e;
    }
}

extern "C" void fn_80102648(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u8*)((u8*)param_1 + 0x189) = 0x40;
}

extern "C" void fn_8010267C(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x188) = 0;
    *(u8*)((u8*)param_1 + 0x189) = 0x41;
}

extern "C" void fn_801026A8(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x18c) != 0) {
        fn_8002F458((void*)0xad, 0);
        fn_8002F7C0((void*)0xc, 0);
        *(u8*)((u8*)param_1 + 0xf2) = 0xe;
        *(u8*)((u8*)param_1 + 0x188) = 1;
        *(u16*)((u8*)param_1 + 0x528) = 8;
        *(u8*)((u8*)param_1 + 0x189) = 0x42;
    }
}

extern "C" void fn_80102714(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u8*)((u8*)param_1 + 0x188) = 0;
    *(u8*)((u8*)param_1 + 0x189) = 0x43;
}

extern "C" void fn_80102748(void* param_1) {
    if (*(s16*)((u8*)param_1 + 0xec) == 0) {
        fn_8002F458((void*)0x9c, 0);
    }
    s32 iVar1 = fn_80108810(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x10), 0, 1, lbl_80301204, *(f32*)(lbl_802C5A84 + 0xc));
    *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
    if (iVar1 == 1) {
        *(s16*)((u8*)param_1 + 0xec) = 0;
        *(u8*)((u8*)param_1 + 0x189) = 0x45;
        *(u8*)(*(u32*)((u8*)param_1 + 0xf4) + 0xb0) = 0;
    }
}

extern "C" void fn_801027DC(void* param_1) {
    if (fn_8002F87C() != 0) {
        if (*(u16*)((u8*)param_1 + 0x18c) != 0) {
            fn_8002F458((void*)0xad, 0);
            *(u8*)((u8*)param_1 + 0xf2) = 9;
            *(u8*)((u8*)param_1 + 0x188) = 1;
            fn_8002F7C0((void*)0xd, 0);
            *(u8*)((u8*)param_1 + 0x189) = 0x49;
        }
    } else {
        *(u16*)((u8*)param_1 + 0x528) = 8;
        *(u8*)((u8*)param_1 + 0xf2) = 0xb;
        *(u8*)((u8*)param_1 + 0x188) = 1;
        *(u8*)((u8*)param_1 + 0x189) = 0x46;
    }
}

extern "C" void fn_80102870(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0xf2) = 2;
    *(u16*)((u8*)param_1 + 0x528) = 8;
    *(u8*)((u8*)param_1 + 0x189) = 0x47;
}

extern "C" void fn_801028A4(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x528) != 0) {
        *(u16*)((u8*)param_1 + 0x528) = *(u16*)((u8*)param_1 + 0x528) - 1;
        return;
    }
    *(u8*)((u8*)param_1 + 0x188) = 0;
    *(u8*)((u8*)param_1 + 0x189) = 0x48;
}

extern "C" void fn_801028D0(void* param_1) {
    if (*(u16*)((u8*)param_1 + 0x18c) != 0) {
        fn_8002F458((void*)0xad, 0);
        *(u8*)((u8*)param_1 + 0xf2) = 9;
        *(u8*)((u8*)param_1 + 0x188) = 1;
        fn_8002F7C0((void*)0xd, 0);
        *(u8*)((u8*)param_1 + 0x189) = 0x49;
    }
}

extern "C" void fn_80102BA4(u8* p) {
    p[0xf0] = 1;
    p[0xee] = 0x22;
}

extern "C" s32 fn_8002F87C(void);
extern "C" u8 fn_801081D0(char*);
extern "C" void fn_800FE858(char*);
extern "C" void fn_80102E88(char* param_1) {
    if (fn_8002F87C() == 0 && fn_801081D0(param_1) == 1) {
        fn_800FE858(param_1);
        (*(char**)(param_1 + 0x45c))[0xb0] = 1;
        (*(char**)(param_1 + 0x488))[0xb0] = 1;
        param_1[0x194] = 2;
        param_1[0xee] = 3;
    }
}

extern "C" void fn_8010348C(u8*);
extern "C" void fn_80103560(Unk80103560* p);
extern "C" void fn_80103440(u8* p) {
    if (p[0x525] == 1) {
        fn_80103560((Unk80103560*)p);
    } else {
        p[0x525] = 1;
    }
    fn_8010348C(p);
}

extern "C" void fn_80103560(Unk80103560* p) {
    p->count = 0;
    p->objs[p->sel]->v7(0);
    u32 i = p->sel ^ 1;
    p->objs[i]->v7(p->vals[i]);
    p->sel ^= 1;
}

extern "C" void fn_801035EC(Unk80103560* p) {
    if (p->pad3 != 0) {
        s32 r = fn_801092B8(p, p->count, ((u8*)lbl_802C5A84)[0x5a], 0);
        p->count++;
        if (r == 1) {
            p->count = 0;
            p->pad3 = 0;
            p->sel ^= 1;
        }
    }
}

extern "C" void fn_80103664(Unk80103664* p) {
    p->obj->v2(p->a[p->i1][p->i2], p->b[p->i1]);
}

extern "C" s32 fn_801092B8(void* self, u8 a, u8 b, s32 c);
extern f64 lbl_80301210;
extern "C" void fn_8017A4F8(void* p);
extern "C" void fn_801036C8(u8* p) {
    *(s32*)(p + 0x47c) += 1;
    if (*(s32*)(p + 0x47c) >= *(s16*)(*(u8**)(p + 0x478) + 6)) {
        *(s32*)(p + 0x47c) -= *(s16*)(*(u8**)(p + 0x478) + 6);
    }
    *(s32*)(p + 0x484) += 1;
    if (*(s32*)(p + 0x484) >= *(s16*)(*(u8**)(p + 0x480) + 6)) {
        *(s32*)(p + 0x484) -= *(s16*)(*(u8**)(p + 0x480) + 6);
    }
    *(f32*)(*(u8**)(p + 0x478) + 8) = *(s32*)(p + 0x47c);
    *(f32*)(*(u8**)(p + 0x480) + 8) = *(s32*)(p + 0x484);
    fn_8017A4F8(*(void**)(p + 0x54));
}

extern char lbl_802C5A84[];
extern char lbl_8028D704[];
extern "C" s32 fn_80108928(void* self, s16 a, u8 b, f32 c, s32 d, s32 e, f32 f, f32 g, f32 h);
extern "C" void fn_8002F7C0(void* p, s32 b);
extern "C" void fn_80107F20(void* self);
extern "C" void fn_8003ABDC(void*, u32, u32, s32, s32);
extern "C" void fn_8003ABF0(void*, u32, s32, u32, s32, s32, s32, s32);
extern "C" void fn_80104320(void* self);
extern "C" void fn_8010428C(void* self);
extern "C" s32 fn_801093D4(void* self, u8 a, u8 b, s32 c);
extern u16 lbl_8028D6E4[];
extern f32 lbl_80301228;
extern f32 lbl_8030122C;
extern f32 lbl_80301238;
extern "C" void fn_8002F458(void* p, s32 off);
extern "C" s32 fn_80108810(void* self, s16 a, u8 b, s32 c, s32 d, f32 e, f32 f);
extern "C" void fn_80103814(void* param_1) {
    s32 iVar1 = fn_80108928(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), *(f32*)(lbl_802C5A84 + 0x34), 0, 0, 0.0f, 0.0f, 0.0f);
    *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
    if (iVar1 == 1) {
        *(s16*)((u8*)param_1 + 0xec) = 0;
        fn_8002F7C0(*(void**)(lbl_8028D704 + *(s8*)((u8*)param_1 + 0x45a) * 8 + *(u8*)((u8*)param_1 + 0x45b) * 4), 0);
        fn_80107F20(param_1);
        *(u8*)((u8*)param_1 + 0xf2) = 2;
        *(u8*)((u8*)param_1 + 0xee) = 8;
    }
}

extern "C" s32 fn_800F0D64(void*);
extern "C" void fn_80104198(char* p) {
    if (p[0x45a] == 4) {
        if (fn_800F0D64(lbl_802B7CA0) < 2) {
            p[0xf2] = 8;
        } else {
            p[0xf2] = 9;
        }
    } else if (p[0x45a] >= 0 && p[0x45a] <= 1) {
        p[0xf2] = 8;
    } else if (p[0x45a] >= 2 && p[0x45a] <= 3) {
        p[0xf2] = 9;
    } else {
        p[0xf2] = 8;
    }
}

extern "C" void fn_80104240(u8* p) {
    if (p[0x259] == 1) {
        fn_80104320(p);
    } else {
        p[0x259] = 1;
    }
    fn_8010428C(p);
}

extern "C" void fn_8010428C(void* self) {
    u8* p = (u8*)self;
    u8* q = p + ((p[0x256] ^ 1) * 4);
    fn_8003ABDC(*(void**)(p + 0x60), *(u32*)(q + 0x24c), 0, 0, 0);
    q = p + ((p[0x256] ^ 1) * 4);
    fn_8003ABF0(*(void**)(p + 0x60), *(u32*)(q + 0x240), 0, *(u32*)(q + 0x238), 0, lbl_8028D6E4[p[0x257]], 1, 1);
}

extern "C" void fn_80104320(void* self) {
    Unk80104320* p = (Unk80104320*)self;
    p->flag = 0;
    p->objs[p->sel]->v7(0);
    p->objs[p->sel ^ 1]->v7(p->vals[p->sel ^ 1]);
    p->objs2[p->sel]->v7(0);
    p->objs2[p->sel ^ 1]->v7(p->vals2[p->sel ^ 1]);
    p->sel ^= 1;
}

extern "C" void fn_801043FC(u8* p) {
    if (*(u32*)(p + 0x238) != 0) {
        if (*(u32*)(p + 0x23c) != 0) {
            goto body;
        }
        return;
    }
    return;
body:
    if ((s8)p[0x45a] == 4 && p[0x259] != 0) {
        s32 r = fn_801093D4(p, p[0x25a], ((u8*)lbl_802C5A84)[0x61], 0);
        p[0x25a]++;
        if (r == 1) {
            p[0x25a] = 0;
            p[0x259] = 0;
            p[0x256] ^= 1;
        }
    }
}

extern f32 lbl_80301228;
extern f32 lbl_8030122C;
extern f32 lbl_80301238;
extern "C" void fn_8010449C(u8* param_1) {
    struct VObj_800F4B7CSlot2 {
        virtual void v0();
        virtual void v1();
        virtual void v2(f32 a, f32 b);
    };
    f32 x = lbl_80301228 * (f32)param_1[0x1e0];
    f32 y = lbl_8030122C * (f32)param_1[0x1e1];
    ((VObj_800F4B7CSlot2*)*(void**)(param_1 + 0x1d4))->v2(*(f32*)(param_1 + 0x1d8) + x, *(f32*)(param_1 + 0x1dc) + y);
}

extern "C" void fn_80104520(u8* param_1) {
    f32 x = lbl_80301238 * (f32)param_1[0x1c8];
    VObj_800F4B7CListener* obj = (VObj_800F4B7CListener*)*(void**)(param_1 + 0x1bc);
    ((void (*)(void*, f32, f32))(*(void***)obj)[4])(obj, *(f32*)(param_1 + 0x1c0) + x, *(f32*)(param_1 + 0x1c4));
}

extern "C" void fn_80104584(void* param_1) {
    u8* base = (u8*)lbl_802C5A84;
    s32 iVar1;
    {
        f32 f = lbl_80301204;
        iVar1 = fn_80108928(param_1, *(s16*)((u8*)param_1 + 0xec), base[0x3c], f, 0, 1, *(f32*)(base + 0x34), f, f);
    }
    *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
    if (iVar1 == 1) {
        *(s16*)((u8*)param_1 + 0xec) = 0;
        fn_80106CBC(param_1);
        {
            f32 f = lbl_80301204;
            fn_80108928(param_1, *(s16*)((u8*)param_1 + 0xec), base[0x3c], -*(f32*)(base + 0x34), 0, 0, f, f, f);
        }
        *(u8*)((u8*)param_1 + 0xee) = 10;
    }
}

extern "C" void fn_80104638(void* param_1) {
    s32 iVar1 = fn_80108928(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), -*(f32*)(lbl_802C5A84 + 0x34), 0, 0, lbl_80301204, lbl_80301204, lbl_80301204);
    *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
    if (iVar1 == 1) {
        *(s16*)((u8*)param_1 + 0xec) = 0;
        fn_8002F7C0(*(void**)(lbl_8028D704 + *(s8*)((u8*)param_1 + 0x45a) * 8 + *(u8*)((u8*)param_1 + 0x45b) * 4), 0);
        fn_80107F20(param_1);
        *(u8*)((u8*)param_1 + 0xf2) = 2;
        *(u8*)((u8*)param_1 + 0xee) = 8;
    }
}

extern "C" void fn_801046F0(void* param_1) {
    s32 iVar1 = fn_80108928(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), lbl_80301204, 0, 1, -*(f32*)(lbl_802C5A84 + 0x34), lbl_80301204, lbl_80301204);
    *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
    if (iVar1 == 1) {
        *(s16*)((u8*)param_1 + 0xec) = 0;
        fn_80106CBC(param_1);
        fn_80108928(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), *(f32*)(lbl_802C5A84 + 0x34), 0, 0, lbl_80301204, lbl_80301204, lbl_80301204);
        *(u8*)((u8*)param_1 + 0xee) = 0xc;
    }
}

extern "C" void fn_801047A4(void* param_1) {
    s32 iVar1 = fn_80108928(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), *(f32*)(lbl_802C5A84 + 0x34), 0, 0, 0.0f, 0.0f, 0.0f);
    *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
    if (iVar1 == 1) {
        *(s16*)((u8*)param_1 + 0xec) = 0;
        fn_8002F7C0(*(void**)(lbl_8028D704 + *(s8*)((u8*)param_1 + 0x45a) * 8 + *(u8*)((u8*)param_1 + 0x45b) * 4), 0);
        fn_80107F20(param_1);
        *(u8*)((u8*)param_1 + 0xf2) = 2;
        *(u8*)((u8*)param_1 + 0xee) = 8;
    }
}

extern "C" void fn_80104858(void* param_1) {
    u8* base = (u8*)lbl_802C5A84;
    s32 iVar1 = fn_80108928(param_1, *(s16*)((u8*)param_1 + 0xec), base[0x3c], lbl_80301204, 0, 1, lbl_80301204, lbl_80301204, *(f32*)(base + 0x38));
    *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
    if (iVar1 == 1) {
        *(s16*)((u8*)param_1 + 0xec) = 0;
        *(u8*)((u8*)param_1 + 0x45b) ^= 1;
        fn_80106CBC(param_1);
        fn_80108928(param_1, *(s16*)((u8*)param_1 + 0xec), base[0x3c], lbl_80301204, 0, 0, lbl_80301204, *(f32*)(base + 0x38), lbl_80301204);
        *(u8*)((u8*)param_1 + 0xee) = 14;
    }
}

extern "C" void fn_80104914(void* param_1) {
    s32 iVar1 = fn_80108928(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), lbl_80301204, 0, 0, lbl_80301204, *(f32*)(lbl_802C5A84 + 0x38), lbl_80301204);
    *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
    if (iVar1 == 1) {
        *(s16*)((u8*)param_1 + 0xec) = 0;
        fn_8002F7C0(*(void**)(lbl_8028D704 + *(s8*)((u8*)param_1 + 0x45a) * 8 + *(u8*)((u8*)param_1 + 0x45b) * 4), 0);
        fn_80107F20(param_1);
        *(u8*)((u8*)param_1 + 0xf2) = 2;
        *(u8*)((u8*)param_1 + 0xee) = 8;
    }
}

extern "C" s32 fn_80107EB0(u8* p);
extern "C" u8 fn_801049C8(u8* p) {
    s32 i = fn_80107EB0(p);
    return ((u8*)lbl_802B7CA0 + i)[0x3ec];
}

extern "C" void fn_801049F8(u8* p);
extern "C" void fn_80104FB8(u8* p) {
    s32 r = fn_80108928(p, *(s16*)(p + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), 0.0f, 0, 1, 0.0f, 0.0f, *(f32*)(lbl_802C5A84 + 0x38));
    (*(s16*)(p + 0xec))++;
    if (r == 1) {
        *(s16*)(p + 0xec) = 0;
        fn_801049F8(p);
        (*(u8**)(p + 0x284))[0xb0] = 1;
        (*(u8**)(p + 0x28c))[0xb0] = 1;
        p[0x40f] = 1;
        p[0xee] = 0x10;
    }
}

extern "C" void fn_80105050(u8* p) {
    s32 a = fn_801095A4(p, *(s16*)(p + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), *(f32*)(lbl_802C5A84 + 0x38), lbl_80301204, 0, 0);
    s32 b = fn_801096BC(p, *(s16*)(p + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), 0, 0);
    *(s16*)(p + 0xec) = *(s16*)(p + 0xec) + 1;
    if (a == 1 && b == 1) {
        *(s16*)(p + 0xec) = 0;
        p[0xf2] = 2;
        p[0xee] = 0x11;
    }
}

extern "C" void fn_801050FC(u8* p) {
    if (fn_80108030(p) != 0) {
        fn_8002F358(0xab, 0);
        p[0xf2] = 9;
        p[0xee] = 0x12;
    }
}

extern "C" void fn_8010514C(u8* p) {
    f32 f = lbl_80301204;
    f32 g = *(f32*)(lbl_802C5A84 + 0x38);
    s32 a = fn_801095A4(p, *(s16*)(p + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), f, g, 0, 1);
    s32 b = fn_801096BC(p, *(s16*)(p + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), 0, 1);
    *(s16*)(p + 0xec) = *(s16*)(p + 0xec) + 1;
    if (a == 1 && b == 1) {
        *(s16*)(p + 0xec) = 0;
        *(u8*)(*(u32*)(p + 0x284) + 0xb0) = 0;
        *(u8*)(*(u32*)(p + 0x28c) + 0xb0) = 0;
        p[0x40f] = 0;
        p[0xee] = 0x13;
    }
}

extern "C" void fn_80105204(u8* p) {
    f32 f = lbl_80301204;
    f32 g = *(f32*)(lbl_802C5A84 + 0x38);
    s32 a = fn_80108928(p, *(s16*)(p + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), f, 0, 0, f, g, f);
    *(s16*)(p + 0xec) = *(s16*)(p + 0xec) + 1;
    if (a == 1) {
        *(s16*)(p + 0xec) = 0;
        *(u8*)(*(u32*)(p + 0x25c) + 0xb0) = 1;
        *(u8*)(*(u32*)(p + 0x268) + 0xb0) = 1;
        *(u8*)(*(u32*)(p + 0x1bc) + 0xb0) = 1;
        p[0xf2] = 2;
        p[0xee] = 8;
    }
}

extern u8 lbl_802313EC[];
extern "C" u32 fn_80107EA0(u8* p);
extern "C" void fn_801053E4(u8* self) {
    u32 r = fn_80107EA0(self);
    u8 k = lbl_802313EC[self[0x1e1] * 2 + self[0x1e0]];
    u16* p;
    int prev;
    int cur;
    int i;
    self[0x419] = 0;
    p = (u16*)((u8*)lbl_802B7CA0 + r * 0xf0 + k * 0x14);
    prev = p[0x20a];
    p++;
    for (i = 1; i < 15; i++) {
        cur = p[0x20a];
        if (cur == prev) {
            self[0x419 + i] = self[0x418 + i];
        } else {
            self[0x419 + i] = i;
            prev = cur;
        }
        p++;
    }
}

extern "C" void* fn_80181BA0(void* p);
extern "C" void fn_801E41AC(void* a, void* b, s32 c);
extern "C" void fn_801E6768(void* a, void* b);
extern char lbl_8028E5EC[];
extern "C" void fn_801054C4(u8* p) {
    u8* self = p;
    void* b;
    void* a;
    if (self[0x45b] == 0) {
        (*(u8**)(self + 0x3dc))[0xb0] = 0;
    }
    a = ((void* (*)(void*, s32, s32, s32))(*(void***)(*(void**)(self + 0x3c)))[15])(*(void**)(self + 0x3c), 0x72730000, 0x636f, 0x72736531);
    b = ((void* (*)(void*, s32, s32, s32))(*(void***)(*(void**)(self + 0x3c)))[15])(*(void**)(self + 0x3c), 0x72730000, 0x636f, 0x72736532);
    a = fn_80181BA0(a);
    b = fn_80181BA0(b);
    fn_801E41AC(a, lbl_8028E5EC, self[0x1e0] + self[0x1e1] * 2 + 1);
    fn_801E6768(b, a);
}

extern "C" void fn_80106540(char* p);
extern "C" void fn_80105ABC(u8* p) {
    f32 f = lbl_80301204;
    s32 r1 = fn_80108C38(p, *(s16*)(p + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), 0, 0, *(f32*)(lbl_802C5A84 + 0x40), f);
    s32 r2 = fn_80108D50(p, *(s16*)(p + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), 0, 0, *(f32*)(lbl_802C5A84 + 0x44), lbl_80301204);
    (*(s16*)(p + 0xec))++;
    if (r1 == 1 && r2 == 1) {
        *(s16*)(p + 0xec) = 0;
        p[0x428] = *(u8*)(lbl_802C5A84 + 0x49);
        p[0x429] = 0;
        fn_80106540((char*)p);
        p[0xf2] = 2;
        p[0xee] = 0x16;
    }
}

extern "C" void fn_80106000(u8* p) {
    s32 r1;
    u8* base = (u8*)lbl_802C5A84;
    u8* self = p;
    r1 = fn_80108C38(self, *(s16*)(self + 0xec), base[0x3c], 0, 1, lbl_80301204, *(f32*)(base + 0x40));
    s32 r2 = fn_80108D50(self, *(s16*)(self + 0xec), base[0x3c], 0, 1, lbl_80301204, *(f32*)(lbl_802C5A84 + 0x44));
    *(s16*)(self + 0xec) += 1;
    if (r1 == 1 && r2 == 1) {
        *(s16*)(self + 0xec) = 0;
        self[0x40f] = 0;
        self[0xee] = 0x1a;
    }
}

extern "C" void fn_801060B8(u8* p) {
    s32 r = fn_80108928(p, *(s16*)(p + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), 0.0f, 0, 0, 0.0f, *(f32*)(lbl_802C5A84 + 0x38), 0.0f);
    (*(s16*)(p + 0xec))++;
    if (r == 1) {
        *(s16*)(p + 0xec) = 0;
        (*(u8**)(p + 0x1d4))[0xb0] = 1;
        (*(u8**)(p + 0x25c))[0xb0] = 1;
        (*(u8**)(p + 0x268))[0xb0] = 1;
        p[0xf2] = 2;
        p[0xee] = 8;
    }
}

extern "C" void fn_80106540(char* p) {
    *(unsigned char*)(*(char**)(p + 0x3f0) + 0xb0) = 1;
    *(unsigned char*)(p + 0x408) = lbl_802C5A84[0x48];
    *(unsigned char*)(p + 0x409) = 0;
}

extern "C" void fn_80106780(u8* p) {
    s32 r = fn_80108928(p, *(s16*)(p + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), 0.0f, 0, 1, 0.0f, 0.0f, *(f32*)(lbl_802C5A84 + 0x38));
    (*(s16*)(p + 0xec))++;
    if (r == 1) {
        *(s16*)(p + 0xec) = 0;
        fn_801071C4(p);
        p[0x458] = 1;
        p[0xee] = 0x1c;
    }
}

extern "C" void fn_80106808(u8* p) {
    s32 r = fn_80108B20(p, *(s16*)(p + 0xec), *(u8*)(lbl_802C5A84 + 0x60), 0, 0, *(f32*)(lbl_802C5A84 + 0x5c), 0.0f);
    (*(s16*)(p + 0xec))++;
    if (r == 1) {
        *(s16*)(p + 0xec) = 0;
        fn_8002F7C0(*(void**)(lbl_8028D72C + p[0x257] * 4), 0);
        p[0xf2] = 2;
        p[0xee] = 0x1d;
    }
}

extern "C" void fn_8010689C(void* p) {
    if (fn_80108030(p) != 0) {
        fn_8002F358(0xab, 0);
        fn_8002F198();
        fn_80030418(-1, *(s32*)(lbl_802BB0FC + 0x420));
        *(u8*)((u8*)p + 0xf2) = 9;
        *(u8*)((u8*)p + 0xee) = 0x1e;
    }
}

extern "C" void fn_80106904(u8* p) {
    s32 r = fn_80108B20(p, *(s16*)(p + 0xec), lbl_802C5A84[0x60], 0, 1, 0.0f, *(f32*)(lbl_802C5A84 + 0x5c));
    (*(s16*)(p + 0xec))++;
    if (r == 1) {
        *(s16*)(p + 0xec) = 0;
        p[0x458] = 0;
        p[0xee] = 0x1f;
    }
}

extern "C" void fn_80106978(void* param_1) {
    s32 iVar1;
    f32 f = lbl_80301204;
    u8* base = (u8*)lbl_802C5A84;
    s16 a = *(s16*)((u8*)param_1 + 0xec);
    iVar1 = fn_80108928(param_1, a, base[0x3c], f, 0, 0, f, *(f32*)(base + 0x38), f);
    *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
    if (iVar1 == 1) {
        *(s16*)((u8*)param_1 + 0xec) = 0;
        *(u8*)(*(u32*)((u8*)param_1 + 0x25c) + 0xb0) = 1;
        *(u8*)(*(u32*)((u8*)param_1 + 0x268) + 0xb0) = 1;
        *(u8*)((u8*)param_1 + 0xf2) = 2;
        *(u8*)((u8*)param_1 + 0xee) = 8;
    }
}

extern "C" void fn_80107490(void* p) {
    if (fn_8002F6BC(p) == 0) {
        *(u8*)((u8*)p + 0xf1) = *(u8*)((u8*)p + 0xf0);
        *(u8*)((u8*)p + 0xee) = 0x23;
    }
}

extern "C" void fn_801074D4(void) {}

extern "C" u32 fn_80107EA0(u8* p) {
    return (u32)__cntlzw(p[0x45b]) >> 5;
}

extern "C" s32 fn_80107EB0(u8* p) {
    s8 v = p[0x45a];
    switch (v) {
    case 0:
    case 2:
        if (p[0x45b] == 0) {
            return 0;
        }
        return 2;
    case 1:
    case 3:
        if (p[0x45b] == 0) {
            return 1;
        }
        return 3;
    default:
        return -1;
    }
}

extern "C" void fn_80107F20(void* param_1) {
    *(u8*)(*(u32*)((u8*)param_1 + 0x25c) + 0xb0) = 1;
    *(u8*)(*(u32*)((u8*)param_1 + 0x268) + 0xb0) = 1;
    if (*(s8*)((u8*)param_1 + 0x45a) == 4 && *(u8*)(*(u32*)((u8*)param_1 + 0x228) + 0xb0) != 0) {
        *(u8*)(*(u32*)((u8*)param_1 + 0x220) + 0xb0) = 0;
        if (*(u8*)((u8*)param_1 + 0x258) == 1) {
            *(u8*)(*(u32*)((u8*)param_1 + 0x224) + 0xb0) = 0;
        } else {
            *(u8*)(*(u32*)((u8*)param_1 + 0x224) + 0xb0) = 1;
        }
    }
    *(u32*)((u8*)param_1 + 0x27c) = 0;
}

extern "C" void fn_801080E8(void* p) {
    *(u8*)((u8*)p + 0x191) = ((u8*)lbl_802C5A84)[0x26];
    *(u8*)((u8*)p + 0x192) = 0;
}

extern "C" void fn_80108104(char* param_1) {
    if (*(u8*)(param_1 + 0x193) != 0) {
        f32 t = fn_801099E8(param_1, *(u8*)(lbl_802C5A84 + 0x26), *(u8*)(param_1 + 0x191), 2);
        if (*(u8*)(param_1 + 0x192) == 0) {
            t = lbl_80301208 - t;
        }
        VObj_80108104* obj = *(VObj_80108104**)(param_1 + 0x114);
        f32 a = *(f32*)(lbl_802C5A84 + 0x2c);
        f32 d = *(f32*)(lbl_802C5A84 + 0x28) - a;
        d *= t;
        f32 v = a + d;
        *(f32*)((char*)obj + 0xcc) = v;
        *(f32*)((char*)obj + 0xd0) = v;
        obj->v9();
        if (*(u8*)(param_1 + 0x191) == 0) {
            *(u8*)(param_1 + 0x191) = *(u8*)(lbl_802C5A84 + 0x26);
            *(u8*)(param_1 + 0x192) ^= 1;
        } else {
            *(u8*)(param_1 + 0x191) -= 1;
        }
    }
}

extern "C" s32 fn_801096BC(void* self, s16 a, u8 b, void* c, s32 d) {
    f32 f;
    if (a < 0) {
        return 0;
    }
    if (a > b) {
        return 1;
    }
    f = fn_801099E8(self, b, a);
    if (d != 2) {
        if (d == 1) {
            f = lbl_80301208 - f;
        }
        (*(VObj_801096BC**)((u8*)self + 0x284))->v7((s32)((f32)*(u8*)((u8*)self + 0x288) * f));
    }
    return 0;
}

extern "C" void fn_80109960(void) {
    u8* p = (u8*)lbl_802C5A84;
    s32 flag = (s8)p[0x4];
    if (flag >= 0) {
        s32 n = *(s32*)(p + 0x8) - 1;
        *(s32*)(p + 0x8) = n;
        if (n == 0) {
            fn_800127A0(lbl_8029FDB4 + 0x4);
            *(s8*)(p + 0x4) = -1;
        }
    }
}

extern "C" void fn_801099C0(void* self, void* a, void* b) {
    fn_8015FDA8(a, b);
}

extern "C" void fn_80109C10(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80301204;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_80109C74(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028E960;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
