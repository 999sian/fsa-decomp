#include "JSystem/JGeometry/Vec.h"
#include "Game/SinitPoolChain.h"

typedef JGeometry::TVec3<f32> YasiVec;

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
extern const char lbl_8046E058[];
extern "C" s32 fn_8023CB24(s32 holder);
extern "C" s32 fn_8023CA88(s32 holder);
extern "C" s32 fn_801F02BC(void* p, const char* name, s32 id, void* param, s32 a, s32 b, s32 c, f32 f1, f32 f2);
extern "C" const f32 lbl_80540EAC;
extern "C" const f32 lbl_80540EA8;
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void*, u32, u32, void*, u32, s32, s32);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" void fn_8013CC50(u32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801F0E34(void*, u32, s32);
extern "C" u8 fn_802DE9A0(void);
extern "C" u8 fn_802DEB58(void);

struct Vtable802D0B84 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

extern "C" s32 fn_801F132C(void* this_, u32 param2, u32 param3, void* statePtr);
extern "C" char lbl_804A93D0[];
extern "C" void __dt__5ActorFv(void* p, int flags);
extern "C" void __dl__FPv(void* p);
extern "C" const f32 lbl_80540EB8;
extern "C" const f32 lbl_80540EBC;
extern "C" const f32 lbl_80540EC0;
extern "C" const f32 lbl_80540EC4;
extern "C" const f32 lbl_80540EB0;
extern "C" const f32 lbl_80540EB4;
extern char* lbl_8053AAF8;
extern void* lbl_8053AC98;
struct YasiVT {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void breakUp();
};
extern "C" YasiVec* fn_8023E7B0(s32 holder);
extern "C" s32 fn_8023DE58(s32 holder);
extern "C" u8 fn_8023BCD4(s32 holder);
extern "C" char* fn_802D6A9C(void);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" u16 fn_80226850(YasiVec* pos, u32 room);
extern "C" void fn_802A381C(void* mgr, YasiVec* pos, u32 room, s32 id);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 holder, s32 b);
extern "C" u8 fn_801F2B20(void* this_, s32 a);
extern "C" void* fn_802D0B24(void* p, s16 flags) {
    if (p != 0) {
        *(void**)p = lbl_804A93D0;
        __dt__5ActorFv(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_802D0B84(Vtable802D0B84* p) {
    p->m7();
}

extern "C" s32 fn_802D0BB0(void* this_, u32 param2, u32 param3) {
    return fn_801F132C(this_, param2, param3, (u32*)((char*)this_ + 0x230));
}

extern "C" void fn_802D0BD4(char* p) {
    YasiVec pos(*(YasiVec*)(p + 0xc));
    pos.z = lbl_80540EA8;
    s32 id = *(s32*)(p + 0x4);
    if (id >= 8) {
        Actor_CreateByID(fn_801F856C(), 0x4b4d5249, id, &pos, 0, -1, -1);
    }
    if (fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0xd || fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0x39) {
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540EAC, 0x3d0, 0, 1, 0, 0, 1);
        fn_801F0E34(p, 0x30022, 0);
    } else if (fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4)) == 0xe) {
        if (fn_802DE9A0()) {
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540EAC, 0x2a9, -1, 1, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540EAC, 0x2aa, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x5005f, 0);
        } else if (fn_802DEB58()) {
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540EAC, 0x45e, -1, 1, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540EAC, 0x45f, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x5003f, 0);
        }
    } else {
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540EAC, 0x8c, 1, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540EAC, 0x8d, 1, 0, 0, 0, 1);
        fn_801F0E34(p, 0x30003, 0);
    }
    *(u8*)(p + 0x11c) = 0;
}

extern "C" void fn_802D0E28(char* p) {
    s32 flag = 7;
    YasiDrawParam param;
    ((u8*)&param.key.a)[3] = *(u8*)(p + 0x234);
    if (*(u8*)(p + 0xc4) != 0) {
        param.f20 = 0;
        flag = -1;
        param.color = fn_8023CB24(*(s32*)(p + 0xc8)) + 1;
        param.palette = fn_8023CA88(*(s32*)(p + 0xc8));
    }
    fn_801F02BC(p, lbl_8046E058, 0x29, &param, flag, 0, 1, lbl_80540EAC, lbl_80540EAC);
}

extern "C" void fn_802D0FAC(char* p) {
    *(u8*)(p + 0x234) = 0xff;
    if (*(u8*)(p + 0xc4) != 0) {
        YasiVec* h = fn_8023E7B0(*(s32*)(p + 0xc8));
        YasiVec* pos = (YasiVec*)(p + 0xc);
        pos->x = h->x;
        pos->y = h->y;
        pos->z = h->z;
        *(s32*)(p + 0x4) = fn_8023DE58(*(s32*)(p + 0xc8));
        *(u8*)(p + 0x234) = fn_8023BCD4(*(s32*)(p + 0xc8));
        return;
    }
    s32 room = *(s32*)(p + 0x4);
    char* base = fn_802D6A9C() + 0x10000 + room;
    if (*(u8*)(base + 0x31df) == 0) {
        *(f32*)(p + 0x44) += lbl_80540EB0;
        *(YasiVec*)(p + 0xc) += *(YasiVec*)(p + 0x3c);
        s32 hit = *(s32*)(p + 0x114);
        if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
            hit = 0;
        }
        if (((YasiVec*)(p + 0xc))->z < lbl_80540EA8 || fn_801F2618(p, 0, 0)) {
            if (((YasiVec*)(p + 0xc))->z < lbl_80540EA8) {
                if (fn_80226850((YasiVec*)(p + 0xc), *(s32*)(p + 0x4)) == 0x90) {
                    fn_802A381C(lbl_8053AC98, (YasiVec*)(p + 0xc), *(s32*)(p + 0x4), 0x91);
                } else if (fn_80226850((YasiVec*)(p + 0xc), *(s32*)(p + 0x4)) == 0x91) {
                    fn_802A381C(lbl_8053AC98, (YasiVec*)(p + 0xc), *(s32*)(p + 0x4), 0x92);
                }
            }
            ((YasiVT*)p)->breakUp();
        } else if (fn_801F2B7C(p, hit, *(s32*)(p + 0xc8), 4) || fn_801F2B20(p, 0)) {
            ((YasiVT*)p)->breakUp();
        }
    } else {
        if (*(u8*)(p + 0x235) == 0) {
            ((YasiVec*)(p + 0xc))->y = ((YasiVec*)(p + 0xc))->y - ((YasiVec*)(p + 0xc))->z;
            ((YasiVec*)(p + 0xc))->z = lbl_80540EA8;
            ((YasiVec*)(p + 0x3c))->z = lbl_80540EA8;
            *(u8*)(p + 0x235) = 1;
        }
        *(f32*)(p + 0x40) += lbl_80540EB4;
        *(YasiVec*)(p + 0xc) += *(YasiVec*)(p + 0x3c);
        s32 hit = *(s32*)(p + 0x114);
        if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
            hit = 0;
        }
        if (fn_801F2618(p, 0, 0)) {
            ((YasiVT*)p)->breakUp();
        } else if (fn_801F2B7C(p, hit, *(s32*)(p + 0xc8), 4) || fn_801F2B20(p, 0)) {
            ((YasiVT*)p)->breakUp();
        }
    }
}

extern "C" void fn_802D1270(char* p) {
    *(f32*)(p + 0x60) = lbl_80540EB8;
    *(f32*)(p + 0x64) = lbl_80540EB8;
    *(f32*)(p + 0x68) = lbl_80540EBC;
    *(f32*)(p + 0x6c) = lbl_80540EBC;
    *(f32*)(p + 0x80) = lbl_80540EC0;
    *(f32*)(p + 0x84) = lbl_80540EC0;
    *(f32*)(p + 0x88) = lbl_80540EC4;
    *(f32*)(p + 0x8c) = lbl_80540EC4;
    *(s32*)(p + 0x230) = 0;
    *(u8*)(p + 0x234) = 0xff;
    *(u8*)(p + 0x235) = 0;
}

void fn_802D12B8(void) {}

