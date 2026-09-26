// TU 0x802A7D3C-0x802A8220.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

extern "C" void fn_802A7D3C(void) {}

struct Vec3 {
    f32 x, y, z;
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
    virtual void s10(s32 a, s32 b);
    virtual u8 s11();
};

extern "C" u8* fn_802D6A9C(void);
extern "C" u8* fn_8013CC50(u32 owner, Vec3* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 flag);
extern "C" void fn_802D79E8(void* mgr, s32 room, s32 a, f32 x, f32 y);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" void fn_801EE434(void* handle);
extern "C" void detach__5ActorFv(void* this_);

// NonMatching: retail keeps a dead float->int conversion (fctiwz + stfd) of
// "y - mgr->0xd0" in case 0 and a 0x30 frame; this version drops it.
extern "C" void fn_802A7D40(u8* this_) {
    u8* mgr = fn_802D6A9C();
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        (*(s32*)(this_ + 0x234))--;
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x230) = 1;
            switch ((s32)(*(u32*)(this_ + 0x90) & 0xff)) {
            case 1:
                s32 dy = *(f32*)(this_ + 0x10) - *(f32*)(mgr + 0xd0);
                break;
            }
        }
        break;
    case 1:
        if (((ActorV*)this_)->s11()) {
            *(s32*)(this_ + 0x230) = 2;
            *(s32*)(this_ + 0x234) = 1;
        }
        break;
    case 2:
        if (*(s32*)(this_ + 0x234) == 0) {
            if (*(u8**)(this_ + 0x238) == NULL) {
                Vec3 v;
                v.y = 24.0f + *(f32*)(this_ + 0x10);
                v.x = 16.0f + *(f32*)(this_ + 0xc);
                v.z = *(f32*)(this_ + 0x14);
                *(u8**)(this_ + 0x238) = fn_8013CC50(*(u32*)(this_ + 4), &v, 0x173, 1, 0, 0, 0, 1, 1.0f);
                *(s32*)(this_ + 0x230) = 3;
                *(f32*)(this_ + 0xc) += 16.0f;
                *(f32*)(this_ + 0x10) += 24.0f;
                fn_801F0E34(this_, 0x30001, 0);
                *(s32*)(this_ + 0x234) = 20;
            }
        } else {
            (*(s32*)(this_ + 0x234))--;
        }
        break;
    case 3:
        fn_802D79E8(fn_802D6A9C(), *(s32*)(this_ + 4), 0, 4.0f, 0.0f);
        fn_801F2B7C(this_, *(s32*)(this_ + 0x114), -1, 6);
        (*(s32*)(this_ + 0x234))--;
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x230) = 4;
        }
        break;
    case 4:
    default:
        u8* h = *(u8**)(this_ + 0x238);
        if (h != NULL) {
            *(u32*)(h + 0xf4) |= 1;
            *(s32*)(h + 0x24) = 1;
            *(u8**)(this_ + 0x238) = NULL;
        }
        detach__5ActorFv(this_);
        break;
    }
}

extern void* lbl_804A7FB8[];

extern "C" void* fn_802A7F58(u8* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A7FB8;
        if (*(void**)(this_ + 0x238) != NULL) {
            fn_801EE434(*(void**)(this_ + 0x238));
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802A7FCC(u8* this_) {
    *(f32*)(this_ + 0x60) = -48.0f;
    *(f32*)(this_ + 0x64) = -48.0f;
    *(f32*)(this_ + 0x68) = 48.0f;
    *(f32*)(this_ + 0x6c) = 48.0f;
    *(void**)(this_ + 0x238) = NULL;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x234) = 20;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D0DD4[0x94];
