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

extern void* lbl_8028E960[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80301204;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_8015FDA8(void*, void*);
extern "C" void fn_800F4D38(void) {}

extern "C" void fn_800F7DAC(void) {}

extern "C" BOOL fn_800FFBBC(void)
{
    return TRUE;
}

extern "C" BOOL fn_800FFBC4(void);
extern "C" BOOL fn_800FFBC4(void)
{
    return TRUE;
}

extern "C" void fn_80103664(u8* p) {
    s32 idx1 = (s8)p[0x4cd];
    s32 idx2 = (s8)p[0x4cc];
    VObj_800F4B7CListener* obj = *(VObj_800F4B7CListener**)(p + 0x46c);
    obj->v4(*(f32*)(p + idx1 * 0x18 + idx2 * 4 + 0x4d0), *(f32*)(p + idx1 * 4 + 0x518));
}

extern char lbl_802C5A84[];
extern char lbl_8028D704[];
extern "C" s32 fn_80108928(void* self, s16 a, u8 b, f32 c, s32 d, s32 e, f32 f, f32 g, f32 h);
extern "C" void fn_8002F7C0(void* p, s32 b);
extern "C" void fn_80107F20(void* self);
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
