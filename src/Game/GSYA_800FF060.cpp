// GSYA_800FF060: .text 0x800FF060-0x8010089C (actor GSYA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "Game/Actor.h"

extern void* lbl_8053AAF8;
extern "C" s32 fn_80138A30(void* game);
extern u8* lbl_8053AF00;
extern f32 lbl_8053C110;
extern f32 lbl_8053C118;
extern u8 lbl_80463B8C[];
extern u8 lbl_80463B78[];
extern "C" s32 fn_8023DE58(s32 i);
extern "C" void* fn_8023E724(s32 i);
extern f32 lbl_8053C114;
extern "C" void fn_801F06F0(Actor* a, void* p2, void* p3, const void* p4, void* p5, f32 f6, f32 f7);
extern "C" void fn_803075AC(u32 x, u32 y, void* v, void* p, int sign, int two, int minus1, u8 p7, u32 u, int zero);

static inline void fsaSetTimeSlot(Actor* this_, s32 idx) {
    s32 v = *(s32*)((u8*)this_ + 0x250 + idx * 4);
    lbl_8053AF00[0x30] |= (u8)(1 << idx);
    lbl_8053AF00[0x2c + idx] = (u8)(v / 60);
    lbl_8053AF00[0x28 + idx] = (u8)((f32)(v % 60) / lbl_8053C110);
}

static inline void fsaSetTimeValue(s32 v, s32 idx) {
    lbl_8053AF00[0x30] |= (u8)(1 << idx);
    lbl_8053AF00[0x2c + idx] = (u8)(v / 60);
    lbl_8053AF00[0x28 + idx] = (u8)((f32)(v % 60) / lbl_8053C110);
}

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

extern "C" void fn_800FF0C0(Actor* this_) {
    s32 count;
    s32 i;
    Vec saved;
    if (*(s32*)((u8*)this_ + 0x230) == 7) {
        count = fn_80138A30(lbl_8053AAF8);
        i = 0;
        if (count > 0) {
            if (count > 8) {
                s32* p = (s32*)this_;
                u32 n = (u32)(count - 8 + 7) >> 3;
                do {
                    fsaSetTimeValue(p[0x94], i + 0);
                    fsaSetTimeValue(p[0x95], i + 1);
                    fsaSetTimeValue(p[0x96], i + 2);
                    fsaSetTimeValue(p[0x97], i + 3);
                    fsaSetTimeValue(p[0x98], i + 4);
                    fsaSetTimeValue(p[0x99], i + 5);
                    fsaSetTimeValue(p[0x9a], i + 6);
                    fsaSetTimeValue(p[0x9b], i + 7);
                    p += 8;
                    i += 8;
                } while (--n != 0);
            }
            for (; i < count; i++) {
                fsaSetTimeValue(*(s32*)((u8*)this_ + 0x250 + i * 4), i);
            }
        }
        lbl_8053AF00[0x30] |= (u8)(1 << (*(s32*)((u8*)this_ + 0x240) + 4));
        if (*(s32*)((u8*)this_ + 0x230) == 4) {
            *(Vec*)&saved = *(Vec*)((u8*)this_ + 0xc);
            Vec* q = (Vec*)fn_8023E724(*(s32*)((u8*)this_ + 0x240));
            *(Vec*)((u8*)this_ + 0xc) = *q;
            ((Vec*)((u8*)this_ + 0xc))->y = ((Vec*)((u8*)this_ + 0xc))->y - lbl_8053C114;
            fn_801F06F0(this_, lbl_80463B78, (void*)0x314, 0, (void*)-1, lbl_8053C118, lbl_8053C118);
            if (fn_8023DE58(*(s32*)((u8*)this_ + 0x240)) != 0) {
                fn_803075AC(*(u32*)((u8*)this_ + 0x198), fn_8023DE58(*(s32*)((u8*)this_ + 0x240)), (u8*)this_ + 0xc, (void*)0x314, 0, 2, -1, 0, 0, 0);
            }
            *(Vec*)((u8*)this_ + 0xc) = saved;
        }
    }
    fn_801F06F0(this_, lbl_80463B8C, (void*)(((u8)*((u8*)this_ + 0x235) * 2) + *(s32*)((u8*)this_ + 0x23c) + 0x311), 0, 0, lbl_8053C118, lbl_8053C118);
}

extern "C" void fn_80239914(s32 a, s32 b);
extern "C" void fn_8022FEB8(void* p, s32 a, s32 b, s32 c, s32 d);
extern "C" s32 fn_8022FD8C(s32 a);
extern "C" s32 fn_802300EC(void);
extern "C" void fn_800FF6F8(Actor* this_) {
    u8* p = (u8*)this_;
    fn_80239914(*(s32*)(p + 0x4), *(s32*)(p + 0x198));
    p[0x234] = p[0x234] + 1;
    if (*(s32*)(p + 0x230) > 9) {
        return;
    }
    switch (*(s32*)(p + 0x230)) {
    default:
        break;
    }
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

extern const f32 lbl_8053C134;
extern const f32 lbl_8053C138;
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
