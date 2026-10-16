#include "JSystem/JGeometry/Vec.h"

struct Vtable802D31E4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

extern "C" char lbl_804A94D8[];
extern "C" void __dt__5ActorFv(void* p, int flags);
extern "C" void __dl__FPv(void* p);
extern "C" const f32 lbl_80540F44;
extern "C" const f32 lbl_80540F48;
extern "C" const f32 lbl_80540F4C;
extern "C" const f32 lbl_80540F50;
extern "C" const f32 lbl_80540F3C;
extern "C" char lbl_8046E130[];
extern "C" s32 fn_8023CB24(s32 holder);
extern "C" u8 fn_8023CA88(s32 holder);
extern "C" void fn_801F02BC(void* this_, void* table, u32 size, void* buf, s32 flag, f32 f1, f32 f2, u32 a, u32 b);

struct Unk802D3488Buf {
    u8 buf[0x10];
    s32 a;
    s32 b;
    s32 c;
    u8 d[11];
    s32 e;
    u8 f;
    u8 g;
    u8 h;
    s32 i;
    s32 j;
    s32 k;
};

extern "C" s32 fn_801F132C(void* this_, u32 param2, u32 param3, void* statePtr);
extern "C" void* fn_802D3184(void* p, s16 flags) {
    if (p != 0) {
        *(void**)p = lbl_804A94D8;
        __dt__5ActorFv(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_802D31E4(Vtable802D31E4* p) {
    p->m7();
}

extern "C" s32 fn_802D3210(void* this_, u32 param2, u32 param3) {
    return fn_801F132C(this_, param2, param3, (u32*)((char*)this_ + 0x230));
}

extern "C" const f32 lbl_80540F38;
extern "C" const f32 lbl_80540F40;
extern "C" char* lbl_8053AAF8;
extern "C" JGeometry::TVec3<f32>* fn_8023E7B0(s32 holder);
extern "C" s32 fn_8023DE58(s32 holder);
extern "C" u8 fn_8023BCD4(s32 holder);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" u8 fn_801F2B20(void* this_, s32 a);
extern "C" void fn_802D360C(Vtable802D31E4* p) {
    *(u8*)((char*)p + 0x234) = 0xff;
    if (*(u8*)((char*)p + 0xc4) != 0) {
        JGeometry::TVec3<f32>* h = fn_8023E7B0(*(s32*)((char*)p + 0xc8));
        *(f32*)((char*)p + 0xc) = h->x;
        *(f32*)((char*)p + 0x10) = h->y;
        *(f32*)((char*)p + 0x14) = h->z;
        *(s32*)((char*)p + 0x4) = fn_8023DE58(*(s32*)((char*)p + 0xc8));
        *(u8*)((char*)p + 0x234) = fn_8023BCD4(*(s32*)((char*)p + 0xc8));
        return;
    }
    *(f32*)((char*)p + 0x44) += lbl_80540F40;
    *(JGeometry::TVec3<f32>*)((char*)p + 0xc) += *(JGeometry::TVec3<f32>*)((char*)p + 0x3c);
    s32 hit = *(s32*)((char*)p + 0x114);
    if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
        hit = 0;
    }
    if (*(f32*)((char*)p + 0x14) < lbl_80540F38 || fn_801F2618(p, 0, 0)) {
        p->m7();
    } else if (fn_801F2B7C(p, hit, *(s32*)((char*)p + 0xc8), 1) || fn_801F2B20(p, 0)) {
        p->m7();
    }
}

extern "C" void fn_802D3758(char* p) {
    *(f32*)(p + 0x60) = lbl_80540F44;
    *(f32*)(p + 0x64) = lbl_80540F44;
    *(f32*)(p + 0x68) = lbl_80540F48;
    *(f32*)(p + 0x6c) = lbl_80540F48;
    *(f32*)(p + 0x80) = lbl_80540F4C;
    *(f32*)(p + 0x84) = lbl_80540F4C;
    *(f32*)(p + 0x88) = lbl_80540F50;
    *(f32*)(p + 0x8c) = lbl_80540F50;
    *(s32*)(p + 0x230) = 0;
}

