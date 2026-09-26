// TU 0x8029D430-0x8029D898.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804A7C40[];
extern "C" void* fn_8029D430(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A7C40;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" BOOL fn_8029D490(void) {
    return FALSE;
}

extern "C" void fn_8029D498(u8* this_) {
    this_[0x11c] = 0;
}

extern "C" void fn_8029D4A4(void) {}

struct Vec3 {
    f32 x, y, z;
};
struct Box {
    f32 x0, y0, x1, y1;
};
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
};

extern "C" Vec3* fn_8023E724(s32 player);
extern "C" u8 fn_80236BEC(s32 player);
extern "C" u8 fn_8022E438(s32 p, s32 q);
extern "C" u8 fn_8023B0F4(s32 player, Box* box, s32 room, s32 a, f32 f);
extern "C" void fn_80238548(s32 player, s32 a, Vec3* pos, s32 b);
extern "C" u8 fn_801F2B20(void* this_, s32 a);
extern u8* lbl_8053AAF8;

extern "C" void fn_8029D4A8(u8* this_) {
    Vec3* src = fn_8023E724(*(s32*)(this_ + 0x230));
    ((Vec3*)(this_ + 0xc))->x = src->x;
    ((Vec3*)(this_ + 0xc))->y = src->y;
    ((Vec3*)(this_ + 0xc))->z = src->z;
    Box box;
    box.x0 = ((Box*)(this_ + 0x60))->x0;
    box.y0 = ((Box*)(this_ + 0x60))->y0;
    box.x1 = ((Box*)(this_ + 0x60))->x1;
    box.y1 = ((Box*)(this_ + 0x60))->y1;
    box.x0 += *(f32*)(this_ + 0xc);
    box.y0 += *(f32*)(this_ + 0x10);
    box.x1 += *(f32*)(this_ + 0xc);
    box.y1 += *(f32*)(this_ + 0x10);
    s32 val;
    if (lbl_8053AAF8[0x7f] != 0) {
        val = 0;
    } else {
        val = *(s32*)(this_ + 0x114);
    }
    for (s32 i = 0; i < 4; i++) {
        if (!fn_80236BEC(i) && !fn_8022E438(*(s32*)(this_ + 0x110), i) &&
            !fn_8022E438(*(s32*)(this_ + 0x230), i) &&
            fn_8023B0F4(i, &box, *(s32*)(this_ + 4), 0, 0.0f)) {
            fn_80238548(i, val, (Vec3*)(this_ + 0xc), 4);
            ((ActorV*)this_)->s07();
            return;
        }
    }
    if (fn_801F2B20(this_, 0) || *(f32*)(this_ + 0x14) <= 0.0f) {
        ((ActorV*)this_)->s07();
    }
}

extern "C" void fn_8029D634(u8* this_) {
    *(f32*)(this_ + 0x60) = -10.0f;
    *(f32*)(this_ + 0x64) = -10.0f;
    *(f32*)(this_ + 0x68) = 10.0f;
    *(f32*)(this_ + 0x6c) = 10.0f;
    *(f32*)(this_ + 0x80) = -4.0f;
    *(f32*)(this_ + 0x84) = -4.0f;
    *(f32*)(this_ + 0x88) = 4.0f;
    *(f32*)(this_ + 0x8c) = 4.0f;
    *(u32*)(this_ + 0x230) = *(u32*)(this_ + 0x90) & 3;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D08D4[0x94];
