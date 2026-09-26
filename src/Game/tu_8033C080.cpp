// TU 0x8033C080-0x8033C584.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern void* lbl_804AC1F8[];
extern "C" void* fn_8033C080(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AC1F8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8033C0E0(void) {}

typedef JGeometry::TVec3<f32> Vec3f;

extern "C" Vec3f* fn_8023E724(s32 player);
extern "C" void fn_80230BF4(s32 player, s32 a);
extern "C" void fn_8013CC50(u32 owner, Vec3f* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_80230498(s32 player, Vec3f* pos, s32 id, u8 alpha, s32 a, s32 b, s32 c);
extern "C" u8 fn_80230534(s32 a);
extern "C" void fn_80231368(void);
extern "C" void fn_8022CA6C(s32 player, s32 a, s32 b);
extern "C" u8 fn_80230188(s32 player);
extern u8* lbl_8053AB10;

struct Obj8033 {
    u8 pad00[4];
    u32 owner;
    u8 pad08[0x3c - 0x8];
    Vec3f pos;
    u8 pad48[0x90 - 0x48];
    u32 params;
    u8 pad94[0x11c - 0x94];
    u8 active;
    u8 pad11d[0x230 - 0x11d];
    s32 timer;
};

extern "C" void fn_8033C0E4(Obj8033* this_) {
    u8 done = 0;
    this_->pos.z -= 0.1;
    for (s32 i = 0; i < 4; i++) {
        Vec3f v(*fn_8023E724(i));
        v += this_->pos;
        if (v.z <= 0.0f) {
            v.z = 0.0f;
            fn_80230BF4(i, 2);
            done = 1;
        } else if (this_->pos.z > 0.0f) {
            fn_8013CC50(this_->owner, &v, 0x345, 0, 0, 0, 0, 1, 0.15f);
            fn_80230498(i, &v, 0x3cf, this_->timer * 0xff / 40, -0x80, -0x80, 1);
        } else {
            fn_80230498(i, &v, 0x3e, 0xff, -0x80, -0x80, 1);
        }
    }
    this_->timer++;
    if (this_->timer > 40) {
        this_->timer = 40;
    }
    if (done == 1 && fn_80230534(0) == 1) {
        fn_80231368();
        for (s32 i = 0; i < 4; i++) {
            fn_8022CA6C(i, 0, 1);
        }
        this_->active = 0;
    }
}

extern "C" void fn_8033C2C4(Obj8033* this_) {
    this_->timer = 0;
    for (s32 i = 0; i < 4; i++) {
        if (!fn_80230188(i)) {
            this_->active = 0;
        } else {
            this_->pos.z = 4.0f;
        }
    }
    if (!(this_->params & 1)) {
        (*(u8**)(lbl_8053AB10 + 0x2c))[0xc] = 0xff;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_80509B64[0x94];
