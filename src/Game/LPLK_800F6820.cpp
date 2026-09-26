// LPLK_800F6820: .text 0x800F6820-0x800F7FCC (actor LPLK)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_800F7C4C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern "C" s32 fn_8022DCD8(s32 player);
extern "C" void fn_8022DD74(s32 player);
extern void* lbl_8049C578[];

extern "C" void* fn_800F7C4C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C578;
        char* p = (char*)this_;
        s32 player = *(s32*)(p + 0x238);
        if ((u8)fn_8022DCD8(player) != 0) {
            player = *(s32*)(p + 0x238);
            fn_8022DD74(player);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

struct LplkVirt {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual s32 v13();
};
extern const f32 lbl_8053BF98;
extern const f32 lbl_8053BF68;
extern const f32 lbl_8053BF48;
extern const f32 lbl_8053BF9C;

extern "C" void fn_800F7CC8(char* this_) {
    *(f32*)(this_ + 0x60) = lbl_8053BF98;
    *(f32*)(this_ + 0x64) = lbl_8053BF98;
    *(f32*)(this_ + 0x68) = lbl_8053BF68;
    *(f32*)(this_ + 0x6c) = lbl_8053BF68;
    *(f32*)(this_ + 0x80) = lbl_8053BF98;
    *(f32*)(this_ + 0x84) = lbl_8053BF98;
    *(f32*)(this_ + 0x88) = lbl_8053BF68;
    *(f32*)(this_ + 0x8c) = lbl_8053BF68;
    *(u8*)(this_ + 0x235) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(u8*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xf;
    *(u8*)(this_ + 0x23c) = 1;
    *(s32*)(this_ + 0x238) = 0;
    *(f32*)(this_ + 0x264) = lbl_8053BF48;
    *(f32*)(this_ + 0x260) = lbl_8053BF48;
    if (*(u32*)(this_ + 0x90) & 0x100) {
        *(s32*)(this_ + 0x230) = 1;
    }
    if (((LplkVirt*)this_)->v13() != 0) {
        *(s32*)(this_ + 0x230) = 4;
    }
    if (*(u32*)(this_ + 0x90) & 0x400) {
        *(u8*)(this_ + 0x23c) = 0;
        *(f32*)(this_ + 0x14) = lbl_8053BF9C;
    }
    *(s32*)(this_ + 0x24c) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
