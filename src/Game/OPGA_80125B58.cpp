#include "types.h"
#include "JSystem/JGeometry/Vec.h"
struct OPGA_Vec {
    f32 x, y, z;
};

extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
extern "C" void* fn_8013CC50(u32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801D22DC(void*, s32, s32, s32);
extern "C" void fn_801D1F14(void*, f32);
class Actor {
public:
    void v01();
    void v06();
};

extern "C" void fn_801D2608(void*, void*, s32);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D8050(void*, s32, s32, s32);

struct OpgaVT {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v12(u32 a, u32 b);
    virtual u8 v13();
    virtual void v14();
    virtual int v15();
};
void operator delete(void* p);
extern "C" void* __vt__4OPGA[];
extern void* lbl_8049CC34[];
extern const f32 lbl_8053CA70;
extern const f32 lbl_8053CA78;
extern const f32 lbl_8053CA7C;
extern const f32 lbl_8053CA90;
extern const f32 lbl_8053CA94;
extern void* lbl_8049E330[];
extern void* lbl_8049E340[];
extern u8 lbl_80464EE8[];
extern u8 lbl_80464EFC[];
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern const f32 lbl_8053CA80;
extern const f32 lbl_8053CA84;
extern const f32 lbl_8053CA88;
extern "C" void fn_801F02BC(void*, void*, s32, void*, s32, f32, f32, s32, s32);
extern "C" void fn_802F86CC(void*, void*, s32, void*, f32, f32, s32);
extern "C" void* fn_80125B58(u8* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4OPGA;
        if (this_ + 0x27c != 0) {
            if (this_ + 0x2a0 != 0) {
                *(void**)(this_ + 0x2a0) = lbl_8049CC34;
            }
        }
        if (this_ + 0x244 != 0) {
            if (this_ + 0x268 != 0) {
                *(void**)(this_ + 0x268) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_80125BF4(u8* this_) {
    JGeometry::TVec3f pos(*(JGeometry::TVec3f*)(this_ + 0xc));
    pos.y += lbl_8053CA78;
    fn_8013CC50(*(u32*)(this_ + 4), &pos, 0x33a, 0, 0, 0, 0, 1, lbl_8053CA7C);
}

extern "C" void fn_80125C58(u8* this_, u8 flag) {
    this_[0x231] = flag;
    if (this_[0x231] != 0) {
        switch (*(s32*)(this_ + 0x238)) {
        case 1:
            fn_801D22DC(this_ + 0x27c, 0, 0, 0);
            break;
        case 0:
        default:
            fn_801D22DC(this_ + 0x27c, 1, 0, 0);
            break;
        }
        fn_801D1F14(this_ + 0x27c, lbl_8053CA70);
    }
}

extern "C" void fn_80125CDC(u8* this_) {
    ((Actor*)this_)->v01();
}

extern "C" void fn_8012639C(u8* this_) {
    ((Actor*)this_)->v01();
    *(s32*)(this_ + 0x238) = *(s32*)(this_ + 0x90) & 1;
    *(s32*)(this_ + 0x240) = (*(u32*)(this_ + 0x90) >> 22) & 0x1f;
    *(f32*)(this_ + 0x60) = lbl_8053CA90;
    *(f32*)(this_ + 0x64) = lbl_8053CA90;
    *(f32*)(this_ + 0x68) = lbl_8053CA94;
    *(f32*)(this_ + 0x6c) = lbl_8053CA94;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    *(f32*)(this_ + 0x80) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x84) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x88) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x8c) = *(f32*)(this_ + 0x6c);
    *(s32*)(this_ + 0x98) = 2;
    fn_801D2608(this_ + 0x244, lbl_8049E330, 4);
    fn_801D22DC(this_ + 0x244, 2, 2, 0);
    fn_801D1F14(this_ + 0x244, lbl_8053CA70);
    fn_801D2608(this_ + 0x27c, lbl_8049E340, 4);
    fn_801D22DC(this_ + 0x27c, 0, 0, 0);
    fn_801D1F14(this_ + 0x27c, lbl_8053CA70);
    *(u8*)(this_ + 0x11d) = 0;
    if (((OpgaVT*)this_)->v15() == 0 || ((OpgaVT*)this_)->v13()) {
        *(s32*)(this_ + 0x234) = 1;
        switch (*(s32*)(this_ + 0x234)) {
        case 0:
            *(u8*)(this_ + 0x230) = 0;
            break;
        case 1:
            ((OpgaVT*)this_)->v12(0xff, 1);
            *(u8*)(this_ + 0x230) = 1;
            *(u8*)(this_ + 0x11d) = 1;
            *(s32*)(this_ + 0x23c) = -1;
            break;
        case 2: {
            s32 n = *(s32*)(this_ + 0x240);
            if (n > 0) {
                fn_802D8050(fn_802D6A9C(), n, 1, 0xff);
            }
        } break;
        }
    }
}

void __sinit_OPGA_80125B58_cpp(void) {}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
