// TU 0x802B9CAC-0x802BA048.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804A8940[];
extern "C" void* fn_802B9CAC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8940;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802B9D0C(void) {}

extern "C" u8 fn_8023A51C(s32 player);
extern "C" s32 fn_8023DE58(s32 player);

extern "C" u8 fn_8030C2A8(void* p);
extern u8* lbl_8053AB10;

struct ActorV {
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10(s32 a, s32 b);

    s32 m04;
    u8 pad08[4];
    struct Vec2 {
        f32 x, y;
    } pos;
};

extern "C" ActorV::Vec2* fn_8023A478(s32 player);

static inline f32 distSq(const ActorV::Vec2& a, const ActorV::Vec2& b) {
    f32 dx = a.x - b.x;
    f32 dy = a.y - b.y;
    f32 dx2 = dx * dx;
    f32 dy2 = dy * dy;
    return dx2 + dy2;
}

// NonMatching: one instruction short, retail materialises a dead
// "addi r4, this, 0xc" (address of pos) after the fn_8023A478 call.
extern "C" void fn_802B9D10(ActorV* this_) {
    s32 id;
    for (s32 i = 0; i < 4; i++) {
        if (fn_8023A51C(i) == 1) {
            id = this_->m04;
            if (id != fn_8023DE58(i)) continue;
            if (!(distSq(*fn_8023A478(i), this_->pos) > 6400.0f)) {
                if (this_->m04 != 0) {
                    this_->s10(0xff, 1);
                    return;
                }
                if (fn_8030C2A8(*(void**)(lbl_8053AB10 + 0x24)) == 1) {
                    this_->s10(0xff, 1);
                    return;
                }
            }
        }
    }
}

extern "C" void fn_802B9E20(void) {}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D25D4[0x94];
