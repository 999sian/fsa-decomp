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

struct YasiDrawKey {
    s32 a, b;
    YasiDrawKey() { a = -1; b = -1; }
};
struct YasiDrawParam {
    u8 map[16];
    YasiDrawKey key;
    s32 c;
    u8 palette;
    u8 color;
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;
    u8 f2c, f2d, f2e;
    s32 g;
    s32 h;
    s32 i;

    YasiDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
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

typedef JGeometry::TVec3<f32> YasiVec;
extern const f32 lbl_80540F38;
extern const f32 lbl_80540F3C;
extern "C" void* fn_801F856C();
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" u16 fn_8022461C(YasiVec* pos, u32 room);
extern "C" void fn_8013CC50(u32 room, YasiVec* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" u8 fn_802DE9A0();
extern "C" void fn_802D3234(char* p) {
    if (*(s32*)(p + 0x4) >= 8) {
        YasiVec pos(*(YasiVec*)(p + 0xc));
        pos.z = lbl_80540F38;
        Actor_CreateByID(fn_801F856C(), 0x4b4d5249, *(u32*)(p + 0x4), &pos, 0, -1, -1);
        fn_801F0E34(p, 0x30018, 0);
    } else if (fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0xd || fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0x39) {
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540F3C, 0x3d0, 0, 1, 0, 0, 1);
        fn_801F0E34(p, 0x30022, 0);
    } else if (fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0xe) {
        if (fn_802DE9A0()) {
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540F3C, 0x2a9, -1, 1, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540F3C, 0x2aa, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x5005f, 0);
        } else {
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540F3C, 0x45e, -1, 1, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540F3C, 0x45f, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x5003f, 0);
        }
    } else {
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540F3C, 0x91, 1, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540F3C, 0x92, 1, 0, 0, 0, 1);
        fn_801F0E34(p, 0x30018, 0);
    }
    *(u8*)(p + 0x11c) = 0;
}

extern "C" void fn_802D3488(u8* param_1) {
    s32 flag = 7;
    YasiDrawParam param;
    ((u8*)&param.key.a)[3] = param_1[0x234];
    if (param_1[0xc4] != 0) {
        param.f20 = 0;
        flag = -1;
        param.color = fn_8023CB24(*(s32*)(param_1 + 0xc8)) + 1;
        param.palette = fn_8023CA88(*(s32*)(param_1 + 0xc8));
    }
    fn_801F02BC(param_1, lbl_8046E130, 0x28, &param, flag, lbl_80540F3C, lbl_80540F3C, 0, 1);
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

void fn_802D3794(void) {
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
