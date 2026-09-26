// TU 0x80329468-0x8032ab80 (actor GNLD).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Gold_dtor_8032A8E0.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AB660[];

// GOLD cluster, part 5/6. Destructor - culls 3 handles (this+0x24c/0x250/
// 0x254) via the confirmed fn_801EE434, then the shared base dtor
// __dt__5ActorFv plus a conditional second-base dtor dtor_80084580.
extern "C" void* Gold_dtor(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AB660;
        fn_801EE434(*(void**)((char*)this_ + 0x24c));
        fn_801EE434(*(void**)((char*)this_ + 0x250));
        fn_801EE434(*(void**)((char*)this_ + 0x254));
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

struct GnldVBase {
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
    virtual u8 v11();
};

extern "C" void detach__5ActorFv(void* this_);
extern const f32 lbl_80541D10;
extern const f32 lbl_80541D14;
extern const f32 lbl_80541D18;
extern const f32 lbl_80541D7C;

extern "C" void fn_8032A7B8(char* this_) {
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x238) = *(u32*)(this_ + 0x90) & 0xffff;
    *(s32*)(this_ + 0x234) = 0;
    *(f32*)(this_ + 0x244) = lbl_80541D10;
    *(f32*)(this_ + 0x248) = lbl_80541D18;
    *(s32*)(this_ + 0x240) = 0xb;
    *(s32*)(this_ + 0x23c) = (*(u32*)(this_ + 0x90) >> 20) & 0xf;
    switch ((*(u32*)(this_ + 0x90) >> 16) & 0xf) {
    default:
    case 0:
    case 5:
    case 6:
        *(s32*)(this_ + 0x230) = 0;
        break;
    case 1:
        *(s32*)(this_ + 0x230) = 1;
        break;
    case 2: {
        *(s32*)(this_ + 0x238) = 0;
        f32 b = lbl_80541D14;
        f32 a = lbl_80541D7C;
        *(f32*)(this_ + 0x60) = a;
        *(f32*)(this_ + 0x64) = a;
        *(f32*)(this_ + 0x68) = b;
        *(f32*)(this_ + 0x6c) = b;
        *(s32*)(this_ + 0x230) = 3;
        break;
    }
    case 3:
        *(s32*)(this_ + 0x230) = 4;
        break;
    case 4:
    case 7:
        *(s32*)(this_ + 0x230) = 5;
        break;
    }
    s32 st = *(s32*)(this_ + 0x230);
    if ((st == 1 || st == 3 || st == 4) && ((GnldVBase*)this_)->v11()) {
        detach__5ActorFv(this_);
    }
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
