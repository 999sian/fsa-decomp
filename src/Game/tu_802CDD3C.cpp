#include "Game/Actor.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"


extern "C" char lbl_804A927C[];
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};
extern "C" const f32 lbl_80540E40;
extern "C" const f32 lbl_80540E44;
extern "C" const f32 lbl_80540E34;
extern "C" const f32 lbl_80540E38;
extern "C" const f32 lbl_80540E3C;
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);

static inline void fn_802CE508_spawn(char* this_) {
    if (*(s32*)(this_ + 0x4) >= 8) {
        Vec v;
        v.x = *(f32*)(this_ + 0xc) + lbl_80540E38;
        v.y = *(f32*)(this_ + 0x10) + lbl_80540E38;
        v.z = lbl_80540E34;
        Actor_CreateByID(fn_801F856C(), 0x4b4d5249, *(u32*)(this_ + 0x4) + *(u8*)(this_ + 0x259), &v, 0, -1, -1);
    } else {
        fn_8013CC50(*(u32*)(this_ + 0x4) + *(u8*)(this_ + 0x259), this_ + 0xc, lbl_80540E3C, 0x564, 0, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(this_ + 0x4) + *(u8*)(this_ + 0x259), this_ + 0xc, lbl_80540E40, 0x503, 1, 0, 0, 0, 1);
    }
    fn_801F0E34(this_, 0x30003, 0);
}
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802CDD3C(Actor* p, s16 n)
{
    if (p != NULL) {
        *(void**)p = lbl_804A927C;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

static inline void fn_802CE508_spawn(char* this_);
extern "C" void fn_802CE508(char* this_) {
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        if ((*(u32*)(this_ + 0x90) >> 27) == 0 || (u8)((Actor*)this_)->v11() == 1) {
            if (*(u8*)(this_ + 0x258)) {
                fn_802CE508_spawn(this_);
            }
            *(s32*)(this_ + 0x230) = 1;
        }
        break;
    case 1:
        if ((*(s32*)(this_ + 0x240) == 2 || *(s32*)(this_ + 0x240) == 3) && !(u8)((Actor*)this_)->v11()) {
            if (*(u8*)(this_ + 0x258)) {
                fn_802CE508_spawn(this_);
            }
            *(s32*)(this_ + 0x230) = 0;
        } else if (*(s32*)(this_ + 0x240) == 4 && (u8)((Actor*)this_)->v11() == 1) {
            *(s32*)(this_ + 0x230) = 2;
        }
        break;
    }
}

extern "C" void fn_802CE7A8(char* p) {
    f32 f;
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 0xfff;
    *(u32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 12) & 0xf;
    *(u32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 16) & 0xf;
    *(u32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 20) & 0xf;
    *(u32*)(p + 0x244) = (*(u32*)(p + 0x90) >> 25) & 1;
    if (*(s32*)(p + 0x244) != 0) {
        *(u8*)(p + 0x259) = 1;
    } else {
        *(u8*)(p + 0x259) = 0;
    }
    if (*(u32*)(p + 0x90) & 0x4000000) {
        *(u8*)(p + 0x258) = 1;
    } else {
        *(u8*)(p + 0x258) = 0;
    }
    if (*(s32*)(p + 0x240) == 0 || *(s32*)(p + 0x240) == 2 || *(s32*)(p + 0x240) == 4) {
        *(s32*)(p + 0x230) = 1;
    } else {
        *(s32*)(p + 0x230) = 0;
    }
    f = lbl_80540E40;
    *(f32*)(p + 0x24c) = f;
    *(f32*)(p + 0x250) = f;
    *(f32*)(p + 0x254) = f;
    *(s16*)(p + 0x248) = 0;
    if (*(s32*)(p + 0x234) == 0x1b) {
        f = lbl_80540E44;
        *(f32*)(p + 0x24c) = f;
        *(f32*)(p + 0x250) = f;
        *(f32*)(p + 0x254) = f;
        *(s16*)(p + 0x248) = 0x4000;
    } else if (*(s32*)(p + 0x234) == 0x1c) {
        f = lbl_80540E44;
        *(f32*)(p + 0x24c) = f;
        *(f32*)(p + 0x250) = f;
        *(f32*)(p + 0x254) = f;
        *(s16*)(p + 0x248) = -0x4000;
    } else if (*(s32*)(p + 0x234) == 0x1d) {
        f = lbl_80540E44;
        *(f32*)(p + 0x24c) = f;
        *(f32*)(p + 0x250) = f;
        *(f32*)(p + 0x254) = f;
        *(s16*)(p + 0x248) = -0x8000;
    } else if (*(s32*)(p + 0x234) == 0x1e) {
        f = lbl_80540E44;
        *(f32*)(p + 0x24c) = f;
        *(f32*)(p + 0x250) = f;
        *(f32*)(p + 0x254) = f;
        *(s16*)(p + 0x248) = 0;
    }
    ((ActorSlot5*)p)->slot5();
    *(u8*)(p + 0x11f) = 1;
}

void fn_802CE93C(void) {}

