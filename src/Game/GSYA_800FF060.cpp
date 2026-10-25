// GSYA_800FF060: .text 0x800FF060-0x8010089C (actor GSYA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "Game/Actor.h"

// ---- from Game/fn_800FF060_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C858[];

extern "C" void* fn_800FF060(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C858;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_80138A30(void* game);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7844(void* mgr, s32 flag, s32 idx);
extern void* lbl_8053AAF8;
extern u32 lbl_80543F18;
extern "C" void fn_801003F4(s32* this_) {
    s32* p;
    s32 k = 0;
    u32 used = lbl_80543F18;
    s32 count = fn_80138A30(lbl_8053AAF8);
    s32 i;
    p = this_;
    for (i = 0; i < count; i++) {
        if (p[0x94] == 0) {
            fn_802D7844(fn_802D6A9C(), 1, i);
        } else {
            fn_802D7844(fn_802D6A9C(), 0, i);
        }
        p++;
    }
    s32* out = this_;
    for (; k != count; k++) {
        s32* q = this_;
        u8* f = (u8*)&used;
        s32 best = 1000000;
        s32 idx = -1;
        for (s32 j = 0; j < count; j++) {
            if (best > q[0x94] && *f == 0) {
                best = q[0x94];
                idx = j;
            }
            q++;
            f++;
        }
        out[0x99] = idx;
        out++;
        ((u8*)&used)[idx] = 1;
    }
    this_[0x9d] = 0;
    if (this_[0x94 + this_[0x99]] == this_[0x94 + this_[0x9a]]) {
        this_[0x9e] = 0;
    } else {
        this_[0x9e] = 1;
    }
    if (count != 2) {
        if (this_[0x94 + this_[0x9a]] == this_[0x94 + this_[0x9b]]) {
            this_[0x9f] = this_[0x9e];
        } else {
            this_[0x9f] = 2;
        }
        if (count != 3) {
            if (this_[0x94 + this_[0x9b]] == this_[0x94 + this_[0x9c]]) {
                this_[0xa0] = this_[0x9f];
            } else {
                this_[0xa0] = 3;
            }
        }
    }
}

extern f32 lbl_8053C134;
extern f32 lbl_8053C138;
extern "C" void fn_801005C4(Actor* this_) {
    f32 f1 = lbl_8053C134;
    f32 f0 = lbl_8053C138;
    *(f32*)((u8*)this_ + 0x60) = f1;
    *(f32*)((u8*)this_ + 0x64) = f1;
    *(f32*)((u8*)this_ + 0x68) = f0;
    *(f32*)((u8*)this_ + 0x6c) = f0;
    ((u8*)this_)[0x235] = 2;
    *(s32*)((u8*)this_ + 0x23c) = 0;
    ((u8*)this_)[0x234] = 0;
    *(s32*)((u8*)this_ + 0x240) = -1;
    ((u8*)this_)[0x236] = 0;
    ((u8*)this_)[0x239] = (*(u32*)((u8*)this_ + 0x90) >> 0x16) & 0x1f;
    *(s32*)((u8*)this_ + 0x230) = 0;
    *(s32*)((u8*)this_ + 0x248) = 0;
    *(s32*)((u8*)this_ + 0x260) = 600;
    if ((u8)this_->v11()) {
        *(s32*)((u8*)this_ + 0x230) = 8;
        *(s32*)((u8*)this_ + 0x248) = 0;
    } else {
        *(s32*)((u8*)this_ + 0x230) = 0;
        *(s32*)((u8*)this_ + 0x248) = 0;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
