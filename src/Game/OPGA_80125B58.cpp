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
    virtual void v10();
    virtual void v11();
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

