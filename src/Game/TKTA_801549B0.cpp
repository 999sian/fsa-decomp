// TKTA_801549B0: .text 0x801549B0-0x801555D8 (actor TKTA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_801549B0_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049FD50[];

extern "C" void* fn_801549B0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049FD50;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_80154A10.cpp

extern "C" void* SpatialRegistry_GetBase();
extern "C" void fn_801F8544(void* base, u32 fourCC, u32 owner, void* posPtr, s32 flag);
extern "C" void Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, s32 a, s32 b, s32 c);
extern "C" void fn_801F4F28(void* this_);

extern "C" void fn_80154A10(void* this_) {
    char* p = (char*)this_;
    *(s32*)(p + 0x18c) = 0;
    if (*(u32*)(p + 0x90) != 0) {
        void* base = SpatialRegistry_GetBase();
        fn_801F8544(base, 0x52555059, *(u32*)(p + 0x4), p + 0xc, 3);
    } else {
        void* base = SpatialRegistry_GetBase();
        Actor_CreateByID(base, 0x48415254, *(u32*)(p + 0x4), p + 0xc, 0, -1, -1);
    }
    fn_801F4F28(this_);
}

extern "C" void fn_801F06F0(void* this_, void* table, u32 id, void* data, f32 f1, f32 f2, s32 mode);
extern char lbl_80465DE8[];
extern const f32 lbl_8053D330;
extern const f32 lbl_8053D334;

extern "C" void fn_80154A98(char* this_) {
    f32 mtx[3][4];
    u8 buf[0x48];

    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = -1;

    for (u8 i = 0; i < 16; i++) {
        buf[i] = i;
    }

    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = 0;
    *(s32*)(buf + 0x18) = 0;
    buf[0x1c] = 0;
    buf[0x1d] = 0;
    buf[0x1e] = 0;
    buf[0x1f] = 1;
    buf[0x20] = 1;
    buf[0x21] = 0;
    buf[0x22] = 0;
    buf[0x23] = 0;
    buf[0x24] = 0;
    buf[0x25] = 0;
    buf[0x26] = 1;
    *(s32*)(buf + 0x28) = 3;
    buf[0x2c] = 1;
    buf[0x2d] = 0;
    buf[0x2e] = 0;
    *(s32*)(buf + 0x30) = -1;
    *(s32*)(buf + 0x34) = 0;
    *(s32*)(buf + 0x38) = 2;

    mtx[0][3] = lbl_8053D330;
    mtx[1][3] = lbl_8053D330;
    mtx[2][3] = lbl_8053D330;

    if (!(*(u32*)(this_ + 0x90) & 2)) {
        if (*(u32*)(this_ + 0x90) != 0) {
            f32 sy = *(f32*)(this_ + 0x58);
            f32 sx = *(f32*)(this_ + 0x54);
            f32 sz = *(f32*)(this_ + 0x5c);
            mtx[0][0] = sx;
            mtx[0][1] = lbl_8053D330;
            mtx[0][2] = lbl_8053D330;
            mtx[1][0] = lbl_8053D330;
            mtx[1][1] = sy;
            mtx[1][2] = lbl_8053D330;
            mtx[2][0] = lbl_8053D330;
            mtx[2][1] = lbl_8053D330;
            mtx[2][2] = sz;
            buf[0x1f] = 0;
            *(void**)(buf + 0x18) = mtx;
        }
        fn_801F06F0(this_, lbl_80465DE8, *(s32*)(this_ + 0x250) + (*(s32*)(this_ + 0x90) * 3 + 0x49), buf, lbl_8053D334, lbl_8053D334, 7);
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
