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
// .text 0x800a50ec-0x800b08f8 (97 functions). split_file divides it into the game's real files.

extern void* lbl_8028739C[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300BFC;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_8015FDA8(void*, void*);
extern u8 lbl_802C5524[];
extern u8 lbl_8029FDB4[];
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_800127A0(void*);
extern "C" s32 fn_800AEE04(void* p, s32 a, u8 b, s32 c);
extern "C" s32 fn_800AE784(void* p, s32 a, u8 b, f32 x, f32 y, s32 c, s32 d);
extern "C" void fn_80017248(u8* base, u8 idx);
extern "C" void fn_800161C0(void* a, void* b, u32 c, s32 d);
extern "C" s32 fn_800ACDAC(void* p, s32 x);
extern "C" void fn_8003ABDC(void*, u32, u32, s32, s32);
extern "C" void fn_8003ABF0(void*, u32, s32, u32, s32, s32, s32, s32);
extern u8 lbl_802AE880[];
extern "C" void fn_800AA390(u8* p)
{
    s32 r1 = fn_800AEE04(p, *(s16*)(p + 0x3d8), lbl_802C5524[0x58], 1);
    s32 r2 = fn_800AE784(p, *(s16*)(p + 0x3d8), lbl_802C5524[0x4c], *(f32*)(lbl_802C5524 + 0x50), lbl_80300BFC, 0, 0);
    *(s16*)(p + 0x3d8) = *(s16*)(p + 0x3d8) + 1;
    if (r1 == 1 && r2 == 1) {
        *(s16*)(p + 0x3d8) = 0;
        p[0x4c] ^= 1;
        p[0x3ac] = 0x10;
    }
}

extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
extern "C" void fn_800AA43C(u8* p)
{
    u8* base = *(u8**)(p + 0x3ec) + 0x258;
    memcpy(base + p[0x3b6] * 0x9c4, base + p[0x3b5] * 0x9c4, 0x9c4);
    fn_80017248(*(u8**)(p + 0x3ec), p[0x3b6]);
    fn_800161C0(lbl_802AE880, *(void**)(p + 0x3ec), 0x1fa4, 0);
    p[0x3ac] = 0x11;
}

extern "C" void fn_800AA92C(u8* p)
{
    s32 r1 = fn_800AEE04(p, *(s16*)(p + 0x3d8), lbl_802C5524[0x58], 1);
    s32 r2 = fn_800AE784(p, *(s16*)(p + 0x3d8), lbl_802C5524[0x4c], *(f32*)(lbl_802C5524 + 0x50), lbl_80300BFC, 0, 0);
    *(s16*)(p + 0x3d8) = *(s16*)(p + 0x3d8) + 1;
    if (r1 == 1 && r2 == 1) {
        *(s16*)(p + 0x3d8) = 0;
        p[0x4c] ^= 1;
        p[0x3dc] = lbl_802C5524[0x68];
        p[0x3ac] = 0x28;
    }
}

extern "C" void fn_800AA9E8(u8* p)
{
    if (fn_800ACDAC(p, 1) == 1) {
        fn_8003ABDC(*(void**)(p + 0x10), 0, 0, 0, 0);
        u8* q = p + ((p[0x4c] ^ 1) * 4);
        fn_8003ABF0(*(void**)(p + 0x10), *(u32*)(q + 0x44), 0, *(u32*)(q + 0x38), 0, 0x226, 0, 0);
        p[0x3da] = 2;
        p[0x3ac] = 0x18;
    }
}

extern "C" void fn_800AC654(void) {}

extern "C" u32 fn_800AD744(void* param_1, u8* param_2, u8* param_3) {
    u8 r6 = param_2[0];
    u8 r0 = param_2[1];
    *(u8*)((u8*)param_1 + 0x13c) = r6;
    r6 = param_2[2];
    r0 = param_2[3];
    *(u8*)((u8*)param_1 + 0x13d) = r0;
    u8 r4 = param_3[0];
    *(u8*)((u8*)param_1 + 0x13e) = r6;
    *(u8*)((u8*)param_1 + 0x13f) = r0;
    r0 = param_3[1];
    *(u8*)((u8*)param_1 + 0x138) = r4;
    r4 = param_3[2];
    *(u8*)((u8*)param_1 + 0x139) = r0;
    r0 = param_3[3];
    *(u8*)((u8*)param_1 + 0x13a) = r4;
    *(u8*)((u8*)param_1 + 0x13b) = r0;
    return 1;
}

extern "C" void fn_800AD78C(void* param_1, s32 param_2) {
    void* base = (void*)((u8*)param_1 + param_2 * 0x4c);
    void* p1 = *(void**)((u8*)base + 0xc8);
    *(u8*)((u8*)p1 + 0xb0) = 1;
    void* p2 = *(void**)((u8*)base + 0xcc);
    *(u8*)((u8*)p2 + 0xb0) = 0;
    void* p3 = *(void**)((u8*)base + 0xd0);
    *(u8*)((u8*)p3 + 0xb0) = 0;
    void* p4 = *(void**)((u8*)base + 0xbc);
    *(u8*)((u8*)p4 + 0xb0) = 0;
    register void* p5 = *(void**)((u8*)base + 0xc0);
    *(u8*)((u8*)p5 + 0xb0) = 0;
    void* p6 = *(void**)((u8*)base + 0xc4);
    *(u8*)((u8*)p6 + 0xb0) = 0;
    void* p7 = *(void**)((u8*)base + 0xf0);
    *(u8*)((u8*)p7 + 0xb0) = 0;
    register void* p8 = *(void**)((u8*)base + 0xf4);
    *(u8*)((u8*)p8 + 0xb0) = 0;
    void* p9 = *(void**)((u8*)base + 0xf8);
    *(u8*)((u8*)p9 + 0xb0) = 0;
    void* p10 = *(void**)((u8*)base + 0xe4);
    *(u8*)((u8*)p10 + 0xb0) = 0;
    void* p11 = *(void**)((u8*)base + 0xe8);
    *(u8*)((u8*)p11 + (unsigned short)0xb0) = 0;
    void* p12 = *(void**)((u8*)base + 0xec);
    *(u8*)((u8*)p12 + 0xb0) = 0;
}

extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_800B051C(u8* param_1) {
    char* base = (char*)lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0xfc, base + 0x100, param_1 + 8);
}

extern "C" void fn_800B0558(void* param_1) {
    void* obj = *(void**)((u8*)param_1 + 0xc);
    if (obj != nullptr) {
        register void** vtbl = *(void***)obj;
        void (*method)(void*, int) = (void(*)(void*, int))*(void**)((u8*)vtbl + 8);
        method(obj, 1);
    }
    fn_8015AB1C(*(void**)((u8*)param_1 + 0x14));
    void* obj2 = *(void**)((u8*)param_1 + 4);
    void** vtbl2 = *(void***)obj2;
    void (*method2)(void*) = (void(*)(void*))*(void**)((u8*)vtbl2 + 0x24);
    method2(obj2);
    
    s8 byte = *(s8*)(lbl_802C5524 + 4);
    if (byte >= 0) {
        s32 val = *(s32*)(lbl_802C5524 + 8) - 1;
        *(s32*)(lbl_802C5524 + 8) = val;
        if (val == 0) {
            fn_800127A0((void*)(lbl_8029FDB4 + 4));
            *(s8*)(lbl_802C5524 + 4) = -1;
        }
    }
}

extern "C" void fn_800B05F8(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 4));
}

extern "C" void fn_800B084C(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300BFC;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800B08B0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028739C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
