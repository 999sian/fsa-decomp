#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Box.h"
#include "Game/ItemBase.h"
extern s32 lbl_80463E50[];
extern f32 lbl_80463E74[];
extern const f64 lbl_8053C200;

extern void* lbl_8049CB04[];
extern "C" void* lbl_8053AAF8;
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_80138B7C(void* mgr);
extern "C" void __dt__5ActorFv(Actor* self, s32 flag);
extern "C" void fn_801EEC98(void* this_, void* room, s16* a, s32* dir, f32* dist, s32* player, s32 b, s32 c);
extern "C" void* fn_8023E724(s32 i);
extern "C" void fn_80239914(void* box, u32 room, u32 id);
extern "C" void fn_80458FF0(void* a, u32 b, s32 c, s32 d);
extern "C" void fn_802D79E8(void* mgr, u32 room, s32 b, f32 x, f32 y);
extern "C" void fn_80134DE4(void* a, s32 b, s32 c);
extern u8 lbl_80463C30[];
extern s16 lbl_8049C3B8[];
extern "C" void* lbl_8053AF80;
extern const f32 lbl_8053C1F8;
extern const f32 lbl_8053C1FC;
extern const f32 lbl_8053C210;
extern const f32 lbl_8053C214;
extern const f32 lbl_8053C218;
extern const f32 lbl_8053C21C;
extern const f32 lbl_8053C220;
extern const f32 lbl_8053C224;
extern "C" void fn_801EFD34(Actor* this_, void* res, u8* idx, s32 n, f32 a, f32 b, f32 c);
extern "C" void* fn_804032E8(u32 type, const char* name);
extern const char* lbl_8049CA98[];
extern "C" void fn_801042D0(Actor* this_) {
    u8 idx[0x10];
    f32 pos[3];
    for (u32 i = 0; (u8)i < 0x10; i += 8) {
        idx[(u8)(i + 0)] = i + 0;
        idx[(u8)(i + 1)] = i + 1;
        idx[(u8)(i + 2)] = i + 2;
        idx[(u8)(i + 3)] = i + 3;
        idx[(u8)(i + 4)] = i + 4;
        idx[(u8)(i + 5)] = i + 5;
        idx[(u8)(i + 6)] = i + 6;
        idx[(u8)(i + 7)] = i + 7;
    }
    pos[0] = *(f32*)((u8*)this_ + 0xc);
    pos[1] = *(f32*)((u8*)this_ + 0x10);
    pos[2] = *(f32*)((u8*)this_ + 0x14);
    void* tex = fn_804032E8(0x54494D47, lbl_8049CA98[*(s32*)((u8*)this_ + 0x238)]);
    fn_801EFD34(this_, tex, idx, -1, lbl_8053C1F8, lbl_8053C1F8, lbl_8053C1F8);
    *(f32*)((u8*)this_ + 0x10) = pos[1];
}

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_strength_reduction off
extern "C" void fn_801045D8(Actor* this_) {
    u8* tbl = lbl_80463C30;
    f32 f31;
    {
        s32* ids;
        f32* offs;
        s32 idx;
        idx = *(s32*)((u8*)this_ + 0x238);
        ids = (s32*)(tbl + 0x220);
        offs = (f32*)(tbl + 0x268);
        f31 = (f32)lbl_8049C3B8[2] + (*(f32*)((u8*)this_ + 0x10) + lbl_8053C1FC * (f32)(lbl_8049C3B8[0] + ids[idx]) + offs[idx]);
    }

    switch (*(s32*)((u8*)this_ + 0x234)) {
    case 0:
        *(u8*)((u8*)this_ + 0x244) = 1;
        break;
    case 1:
        *(u8*)((u8*)this_ + 0x244) = 0;
        break;
    case 2:
        if (*(u8*)((u8*)this_ + 0x245) == 0) {
            s16 a = 0;
            f32 dist = lbl_8053C1F8;
            s32 dir = 0;
            s32 player = 0;
            fn_801EEC98(this_, *(void**)((u8*)this_ + 0x198), &a, &dir, &dist, &player, 0, 0);
            if (player >= 0 && ((f32*)fn_8023E724(player))[1] - f31 < lbl_8053C210) {
                this_->v10(0xff, 1);
                *(u8*)((u8*)this_ + 0x245) = 1;
            }
        } else if (*(u8*)((u8*)this_ + 0x245) == 1) {
            *(f32*)((u8*)this_ + 0x240) -= lbl_8053C214;
            if (*(f32*)((u8*)this_ + 0x240) < lbl_8053C218) {
                *(u8*)((u8*)this_ + 0x244) = 0;
            }
            if (*(f32*)((u8*)this_ + 0x240) < lbl_8053C21C) {
                *(f32*)((u8*)this_ + 0x240) = lbl_8053C21C;
                *(u8*)((u8*)this_ + 0x245) = 2;
            }
                fn_802D79E8(fn_802D6A9C(), *(u32*)((u8*)this_ + 4), 0, lbl_8053C220, lbl_8053C1F8);
                fn_80134DE4(lbl_8053AAF8, 1, 0);
        } else {
            *(f32*)((u8*)this_ + 0x240) = lbl_8053C21C;
            *(u8*)((u8*)this_ + 0x244) = 0;
        }
        break;
    }

    if (*(u8*)((u8*)this_ + 0x244) != 0) {
        f32 box[4];
        f32 y0, x0, x1, x;
        x = *(f32*)((u8*)this_ + 0xc);
        y0 = f31 - lbl_8053C224;
        x1 = lbl_8053C224 + x;
        x0 = x - lbl_8053C224;
        box[1] = y0;
        box[0] = x0;
        box[2] = x1;
        box[3] = lbl_8053C224 + f31;
        fn_80239914(box, *(u32*)((u8*)this_ + 4), *(u32*)((u8*)this_ + 0x198));
    }
    if (*(u8*)((u8*)this_ + 0x246) != 0) {
        if (*(u8*)((u8*)this_ + 0x246) == 1) {
            u32* ids = (u32*)(tbl + 0x28c);
            fn_80458FF0(lbl_8053AF80, ids[*(s32*)((u8*)this_ + 0x238)], 0, 0);
        } else if (*(u8*)((u8*)this_ + 0x246) == 2) {
            u32* ids = (u32*)(tbl + 0x28c);
            fn_80458FF0(lbl_8053AF80, ids[*(s32*)((u8*)this_ + 0x238)], 1, 0);
        }
        *(u8*)((u8*)this_ + 0x246) = 0;
    }
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
#pragma opt_propagation reset
extern "C" Actor* fn_80104894(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_8049CB04;
        if (*(s32*)((u8*)p + 0x234) == 2) {
            s32 kind = *(s32*)((u8*)lbl_8053AAF8 + 0x4c);
            if (kind != 9 && kind != 0xb) {
                u8* mgr = (u8*)fn_802D6A9C();
                *(s32*)(mgr + 0x1328c) = 0;
                fn_80138B7C(lbl_8053AAF8);
            }
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_80104934(Actor* this_) {
 f32 zero = 0.0f;
 *(u32*)((u8*)this_+0x238)=*(u32*)((u8*)this_+0x90)&0xf;
 *(u32*)((u8*)this_+0x234)=(*(u32*)((u8*)this_+0x90)>>8)&0xf;
 *(f32*)((u8*)this_+0x240)=zero;
 *(s32*)((u8*)this_+0x23c)=0;
 *(u8*)((u8*)this_+0x244)=0;
 *(u8*)((u8*)this_+0x245)=0;
 *(u8*)((u8*)this_+0x246)=0;
 if (*(s32*)((u8*)this_+0x234)==2) *(u8*)((u8*)this_+0x244)=1;
 if (*(u8*)((u8*)fn_802D6A9C()+0x131f9)!=0) this_->v10(0xff,1);
 if (*(s32*)((u8*)this_+0x234)==2) {
  if ((u8)this_->v11()!=0) {
   *(u8*)((u8*)this_+0x245)=2;
   *(u8*)((u8*)this_+0x246)=1;
  } else *(u8*)((u8*)this_+0x246)=2;
 }
}

void __sinit_SIBT_801042D0_cpp(void) {}

#include "Game/SinitPoolChain.h"
