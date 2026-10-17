#include "types.h"
extern char lbl_802C5A84[];
extern "C" s32 fn_80108928(void* self, s16 a, u8 b, f32 c, s32 d, s32 e, f32 f, f32 g, f32 h);
extern "C" void fn_80106CBC(void* self);
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
extern char lbl_802B7CA0[];
extern f32 lbl_80301204;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_8015FDA8(void*, void*);
extern "C" void fn_800F4D38(void) {}

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
extern "C" void fn_80103814(void* param_1) {
    f32 f = lbl_80301204;
    u8* base = (u8*)lbl_802C5A84;
    s32 iVar1 = fn_80108928(param_1, *(s16*)((u8*)param_1 + 0xec), base[0x3c], *(f32*)(base + 0x34), 0, 0, f, f, f);
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
    ((VObj_800F4B7CListener*)*(void**)(param_1 + 0x1d4))->v4(*(f32*)(param_1 + 0x1d8) + lbl_80301228 * (f32)param_1[0x1e0], *(f32*)(param_1 + 0x1dc) + lbl_8030122C * (f32)param_1[0x1e1]);
}

extern "C" void fn_80104520(u8* param_1) {
    ((VObj_800F4B7CListener*)*(void**)(param_1 + 0x1bc))->v4(*(f32*)(param_1 + 0x1c0) + lbl_80301238 * (f32)param_1[0x1c8], *(f32*)(param_1 + 0x1c4));
}

extern "C" void fn_80104584(void* param_1) {
    s32 iVar1 = fn_80108928(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), lbl_80301204, 0, 1, *(f32*)(lbl_802C5A84 + 0x34), lbl_80301204, lbl_80301204);
    *(s16*)((u8*)param_1 + 0xec) = *(s16*)((u8*)param_1 + 0xec) + 1;
    if (iVar1 == 1) {
        *(s16*)((u8*)param_1 + 0xec) = 0;
        fn_80106CBC(param_1);
        fn_80108928(param_1, *(s16*)((u8*)param_1 + 0xec), *(u8*)(lbl_802C5A84 + 0x3c), -*(f32*)(lbl_802C5A84 + 0x34), 0, 0, lbl_80301204, lbl_80301204, lbl_80301204);
        *(u8*)((u8*)param_1 + 0xee) = 10;
    }
}

extern "C" void fn_801074D4(void) {}

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
