#include "Game/esd/types.h"
#include "JSystem/JGeometry/Vec.h"
typedef JGeometry::TVec3<f32> YasiVec;
struct YasiVT {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void breakUp();
};
extern const f32 lbl_80540F18;


extern "C" void fn_801F132C(void* a, s32 b, s32 c, s32* d);
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, s32 a, s32 b, f32 sx, f32 sy);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void __dt__5ActorFv(void* this_, int how);
void operator delete(void* p);
extern "C" char lbl_804A9480[];
extern "C" char lbl_8046E118[];
extern const f32 lbl_80540F1C;
extern const f32 lbl_80540F24;
extern const f32 lbl_80540F28;
extern const f32 lbl_80540F2C;
extern const f32 lbl_80540F30;
extern const f32 lbl_80540F18;
extern const f32 lbl_80540F20;
extern "C" void* lbl_8053AC98;
extern "C" u8 fn_801F2618(void* a, s32 b, s32 c);
extern "C" u8 fn_801F2B7C(void* a, s32 b, s32 c, s32 d);
extern "C" u8 fn_801F2B20(void* a, s32 b);
extern "C" f32* fn_8023E7B0(s32 a);
extern "C" s32 fn_8023DE58(s32 a);
extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" void fn_802A381C(void* mgr, void* pos, s32 room, s32 id);
extern "C" void* fn_802D2AA4(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9480;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802D2B04(void* this_, s32 b, s32 c) {
    fn_801F132C(this_, b, c, (s32*)((char*)this_ + 0x234));
}

extern "C" u16 fn_8022461C(YasiVec* pos, u32 room);
extern "C" void fn_8013CC50(u32 room, YasiVec* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" void* fn_801F856C();
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void fn_802D2B28(char* p) {
    s32 c = fn_8022461C((YasiVec*)(p + 0xc), *(u32*)(p + 0x4));
    if (c == 0xd || c == 0x3b || c == 0x39) {
        *(f32*)(p + 0x14) = lbl_80540F18;
        *(f32*)(p + 0x3c) = lbl_80540F18;
        *(f32*)(p + 0x40) = lbl_80540F18;
        *(f32*)(p + 0x44) = lbl_80540F18;
        fn_801F0E34(p, 0x30047, 0);
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540F1C, 0x4f3, -1, 1, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540F1C, 0x4f4, 0, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540F1C, 0x4f5, 0, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540F1C, 0x4f6, 0, 0, 0, 0, 1);
        *(u8*)(p + 0x11c) = 0;
    } else {
        if (*(s32*)(p + 0x230) < 0x50) {
            if (*(s32*)(p + 0x4) >= 8) {
                YasiVec pos(*(YasiVec*)(p + 0xc));
                pos.z = lbl_80540F18;
                Actor_CreateByID(fn_801F856C(), 0x4b4d5249, *(u32*)(p + 0x4), &pos, 0, -1, -1);
            } else {
                fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540F1C, 0x8a, 1, 0, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), (YasiVec*)(p + 0xc), lbl_80540F1C, 0x8b, 1, 0, 0, 0, 1);
            }
        }
        fn_801F0E34(p, 0x30003, 0);
        *(u8*)(p + 0x11c) = 0;
    }
}

extern "C" void fn_802D2D0C(void* this_) {
    f32 c = lbl_80540F1C;
    fn_801F06F0(this_, lbl_8046E118, 0x2b, 0, 7, c, c);
    fn_803075AC(*(void**)((char*)this_ + 0x198), *(s32*)((char*)this_ + 4), (char*)this_ + 0xc, 0x2b, 0, 2, -1, 1, 0, 0);
}

extern "C" void fn_802D2D84(char* p) {
    if (*(u8*)(p + 0xc4) != 0) {
        YasiVec* h = (YasiVec*)fn_8023E7B0(*(s32*)(p + 0xc8));
        *(f32*)(p + 0xc) = h->x;
        *(f32*)(p + 0x10) = h->y;
        *(f32*)(p + 0x14) = h->z;
        *(s32*)(p + 0x4) = fn_8023DE58(*(s32*)(p + 0xc8));
        if (*(s32*)(p + 0x230) < 1000) {
            *(s32*)(p + 0x230) += 1;
        }
        return;
    }
    *(f32*)(p + 0x44) += lbl_80540F20;
    *(YasiVec*)(p + 0xc) += *(YasiVec*)(p + 0x3c);
    if (*(f32*)(p + 0x14) < lbl_80540F18 || fn_801F2618(p, 0, 0)) {
        if (*(f32*)(p + 0x14) < lbl_80540F18) {
            if (fn_80226850((YasiVec*)(p + 0xc), *(s32*)(p + 0x4)) == 0x90) {
                fn_802A381C(lbl_8053AC98, (YasiVec*)(p + 0xc), *(s32*)(p + 0x4), 0x91);
            } else if (fn_80226850((YasiVec*)(p + 0xc), *(s32*)(p + 0x4)) == 0x91) {
                fn_802A381C(lbl_8053AC98, (YasiVec*)(p + 0xc), *(s32*)(p + 0x4), 0x92);
            }
        }
        ((YasiVT*)p)->breakUp();
    } else if (fn_801F2B7C(p, 0, *(s32*)(p + 0xc8), 5) || fn_801F2B20(p, 0)) {
        ((YasiVT*)p)->breakUp();
    }
}

extern "C" void fn_802D2F18(char* p) {
    *(f32*)(p + 0x60) = lbl_80540F24;
    *(f32*)(p + 0x64) = lbl_80540F24;
    *(f32*)(p + 0x68) = lbl_80540F28;
    *(f32*)(p + 0x6c) = lbl_80540F28;
    *(s32*)(p + 0x1a4) = 1;
    *(s32*)(p + 0x230) = 0;
    *(f32*)(p + 0x80) = lbl_80540F2C;
    *(f32*)(p + 0x84) = lbl_80540F2C;
    *(f32*)(p + 0x88) = lbl_80540F30;
    *(f32*)(p + 0x8c) = lbl_80540F30;
    *(s32*)(p + 0x234) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

