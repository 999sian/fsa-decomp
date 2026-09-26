// TU 0x8033F448-0x8033F9A0.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804AC388[];
extern "C" void* fn_8033F448(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AC388;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8033F4A8(void) {}

struct Vec3 {
    f32 x, y, z;
};
struct Vec2 {
    f32 x, y;
};
struct Box {
    f32 x0, y0, x1, y1;
};

extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_802D9FF4(void* mgr, s32 a, s32 b);
extern "C" void fn_80136798(void* game, s32 id, s32 arg);
extern "C" s32 fn_80237810(s32 player);
extern "C" void fn_8023764C(s32 player, s32 v);
extern "C" void fn_8022CA6C(s32 player, s32 a, s32 b);
extern "C" u8 fn_8023F264(s32 player);
extern "C" s32 fn_8023DE58(s32 player);
extern "C" u8 fn_80230188(s32 player);
extern "C" u8 fn_8022F478(s32 player);
extern "C" u8 fn_80236D14(s32 player);
extern "C" Vec3* fn_8023E724(s32 player);
extern "C" void fn_80238548(s32 player, s32 a, Vec2* pos, s32 b);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 flag);
extern "C" void fn_8013CC50(u32 owner, Vec3* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" u8 fn_8022F514(s32 player);
extern "C" u8 fn_80236A18(s32 player);
extern void* lbl_8053AAF8;
extern u8 lbl_80529DEC[];

// NonMatching: retail computes the room-centre x/y into f31/f30 before the
// fn_801F0E34 call; here mwcc sinks that math past the call.
extern "C" void fn_8033F4AC(u8* this_) {
    u8 hit = 0;
    s32 i;
    if (this_[0x23c] == 1) {
        fn_802D9FF4(fn_802D6A9C(), *(s32*)(this_ + 0x234), *(s32*)(this_ + 0x238));
        fn_80136798(lbl_8053AAF8, 0x10, 1);
        for (i = 0; i < 4; i++) {
            fn_8023764C(i, fn_80237810(i) - 4);
            fn_8022CA6C(i, 0, 1);
        }
        this_[0x11c] = 0;
        return;
    }
    if (*(s32*)(this_ + 0x230) <= 0) {
        for (i = 0; i < 4; i++) {
            if (fn_8023F264(i) && fn_8023DE58(i) < 8 && !fn_80230188(i) && !fn_8022F478(i) &&
                !fn_80236D14(i)) {
                Vec3* p = fn_8023E724(i);
                Vec2 v;
                v.x = p->x;
                v.y = p->y;
                v.x += 0.1f;
                v.y = v.y - 0.1f;
                fn_80238548(i, 1, &v, 1);
                lbl_80529DEC[0x239] |= (u8)(1 << i);
                hit = 1;
            }
        }
        *(s32*)(this_ + 0x230) = 300;
    }
    if (hit) {
        Box r = *(Box*)(fn_802D6A9C() + 0xcc);
        f32 x = 0.5f * (r.x0 - r.x1) + r.x1;
        f32 y = 0.5f * (r.y0 - r.y1) + r.y1;
        fn_801F0E34(this_, 0x30036, 0);
        Vec3 pos;
        pos.x = x;
        pos.y = y;
        pos.z = 0.0f;
        fn_8013CC50(*(u32*)(this_ + 4), &pos, 0x1bc, 2, 2, 0, 0, 1, 1.0f);
    }
    for (i = 0; i < 4; i++) {
        if (!fn_8022F514(i) && fn_80236A18(i) && fn_8023F264(i)) {
            this_[0x23c] = 1;
        }
    }
    (*(s32*)(this_ + 0x230))--;
}

extern "C" void fn_8033F748(u8* this_) {
    *(s32*)(this_ + 0x230) = 300;
    *(u32*)(this_ + 0x234) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
    *(u32*)(this_ + 0x238) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(s32*)(this_ + 0x114) = 1;
    this_[0x23c] = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_80509F64[0x94];
