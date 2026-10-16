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
// .text 0x800c5da4-0x800c98b8 (48 functions). split_file divides it into the game's real files.

extern void* lbl_80288750[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern char lbl_802C567C[];
extern f32 lbl_80300DD4;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" int fn_800C91A4(void*, int, s16, u8, int, f32, f32, int);
extern "C" int fn_800C93F4(void*, s16, u8, int);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" s32 fn_80020384(void*, s32);
extern "C" s32 fn_8002F6BC(void);
extern "C" s32 fn_80058A88(s32);
extern "C" void fn_801CA690(void);
extern s32 lbl_802FEBC0;
struct VObj_800C954C {
    virtual void v0(int);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
};
extern char lbl_8029FDB4[];
extern "C" void fn_800127A0(void*);
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
extern "C" void fn_800C8B30(void* param_1)
{
    char* base = lbl_802C567C;
    int local_18[2];
    int i = 0;
    
    do {
        s16 val = *(s16*)((char*)param_1 + 0x86);
        u8 byte_val = (u8)base[0x24];
        f32 fval = *(f32*)(base + 0x20);
        f32 fval2 = lbl_80300DD4;
        local_18[i] = 0;
        i++;
    } while (i < 2);
    
    s16 val = *(s16*)((char*)param_1 + 0x86);
    u8 byte_val = (u8)base[0x1e];
    int result = fn_800C93F4(param_1, val, byte_val, 0);
    
    *(s16*)((char*)param_1 + 0x86) = val + 1;
    
    if (result == 1 && local_18[0] == 1 && local_18[1] == 1) {
        *(u8*)((char*)param_1 + 0x8d) = 2;
        *(s16*)((char*)param_1 + 0x86) = 0;
        *(u8*)((char*)param_1 + 0x40) ^= 1;
        *(u8*)((char*)param_1 + 0x8b) = 8;
        *(u8*)((char*)param_1 + 0x88) = 0x13;
    }
}

extern "C" void fn_800C8CD8(u8* param_1) {
    if (param_1[0x8b] != 0) {
        param_1[0x8b]--;
    } else if (fn_8002F6BC() == 0 && fn_80058A88(0x70) != 0) {
        fn_801CA690();
        lbl_802FEBC0 = 1;
        param_1[0x88] = 0x15;
    }
}

extern "C" void fn_800C8D48(u8* param_1, s32 param_2) {
    s32 r = fn_80020384(lbl_802B7CA0 + 0x1388, param_2);
    if (r == 1) {
        param_1[0x88] = 0x15;
    }
}

extern "C" void fn_800C8D90(u8* param_1) {
    f32 off = 0.5f * param_1[0x7c];
    (*(VObj_800C8D90**)(param_1 + 0x70))->v2(*(f32*)(param_1 + 0x74) + off, *(f32*)(param_1 + 0x78));
}

extern "C" void fn_800C8DF4(u8* param_1) {
    param_1[0x7d] = 0;
    param_1[0x7e] = 1;
    (*(VObj_800C8D90**)(param_1 + 0x70))->v7(lbl_802C567C[0x27]);
}

extern "C" void fn_800C9510(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 4);
}

extern "C" void fn_800C954C(u8* p) {
    VObj_800C954C* o = *(VObj_800C954C**)(p + 8);
    if (o != 0) {
        o->v0(1);
    }
    (*(VObj_800C954C**)(p + 0x10))->v7();
    char* base = lbl_802C567C;
    if (base[4] >= 0) {
        s32 n = *(s32*)(base + 8) - 1;
        *(s32*)(base + 8) = n;
        if (n == 0) {
            fn_800127A0(lbl_8029FDB4 + 4);
            base[4] = -1;
        }
    }
}

extern "C" void fn_800C980C(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300DD4;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800C9870(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288750;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
