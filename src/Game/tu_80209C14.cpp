#include "Game/ItemBase.h"

extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void fn_802075D8(void*, u16);
extern "C" void v07__5ActorFv(void*);
extern "C" u32 fn_801F37AC(void*, u32, void*, u32, u32, u32);
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Box.h"


extern void* lbl_804A5D60[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" f32 lbl_8053F970;
extern "C" f32 lbl_8053F964;
extern "C" f32 lbl_8053EFB8;
extern "C" void* fn_80209C14(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5D60;
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80209CA4(ItemBase* this_, u32 index, u32 value, void* pos, u32 buf) {
    if ((u8)fn_801F37AC(this_, value, pos, 0, buf, index)) {
        this_->m230 &= ~0x80;
    }
}

extern "C" void fn_80209CF4(u8* this_, const JGeometry::TVec2<f32>* pos) {
    if ((*(volatile u32*)(this_ + 0x230) & 0x2000) != 0) {
        return;
    }
    *(u32*)(this_ + 0x230) |= 0x8000;
    *(JGeometry::TVec2<f32>*)(this_ + 0x2C8) = *pos;
}

extern "C" void fn_80209D20(u8* this_, u32 value, u8 flag) {
    if ((*(volatile u32*)(this_ + 0x230) & 0x2000) != 0) {
        return;
    }
    *(u32*)(this_ + 0x230) |= 0x4000;
    *(u32*)(this_ + 0x2AC) = value;
    *(u8*)(this_ + 0x2B0) = flag;
}

extern "C" void fn_80209D44(ItemBase* this_) {
    this_->m230 |= 0x2000;
}

extern "C" void fn_80209FBC(u8* this_) {
    void* actor = fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x2A8));
    if (actor != 0) {
        fn_802075D8(actor, *(u16*)(this_ + 0x94));
    }
    v07__5ActorFv(this_);
}

extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void fn_802075D8(void*, u16);
extern "C" void v07__5ActorFv(void*);
extern "C" u32 fn_801F2DB4(void*, u32, u32, void*);
extern "C" void fn_8020A008(ItemBase* this_) {
    this_->m230 |= 0x80;
}

extern "C" s32 fn_801F285C(void*, u32, void*, u32, s32);
extern "C" void* fn_8023E724(s32);
extern "C" s32 fn_8023B6CC(s32);
extern "C" void fn_80207830(void*, u16, s32, s32, void*, u32);
extern "C" s32 fn_8020A018(u8* this_) {
    u32 out;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > 0.0f &&
        *(f32*)(this_ + 0x6C) - *(f32*)(this_ + 0x64) > 0.0f) {
        s32 player = fn_801F285C(this_, 0, &out, 1, -1);
        if (player >= 0) {
            void* actor = fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x2A8));
            if (actor != 0) {
                fn_80207830(actor, *(u16*)(this_ + 0x94), player, fn_8023B6CC(player), fn_8023E724(player), out);
            }
        }
    }
    return 0;
}

extern "C" s32 fn_8020A0E8(u8* this_) {
    fn_801F2DB4(this_, *(u32*)(this_ + 0x1A0), 'NULL', 0);
    return 0;
}


// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SJ01)
extern "C" void fn_8020AE2C(void* param_1) {
    f32 f1 = *(f32*)((u8*)param_1 + 0x24);
    f32 f0 = *(f32*)((u8*)param_1 + 0xc);
    f32 f3 = *(f32*)((u8*)param_1 + 0x28);
    f32 f2 = *(f32*)((u8*)param_1 + 0x10);
    *(f32*)((u8*)param_1 + 0x2c0) = f1 - f0;
    *(f32*)((u8*)param_1 + 0x2c4) = f3 - f2;
}

extern "C" void* fn_801D0F40(void* this_);
extern "C" float lbl_8053F964;
extern "C" void fn_801D0F40(void* this_);
extern "C" const f32 lbl_8053F964;
extern "C" void* fn_8020B0B8(char* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A5D60;
    *(s32*)(this_ + 0x2a8) = -1;
    *(s32*)(this_ + 0x2ac) = 0;
    *(u8*)(this_ + 0x2b0) = 1;
    *(u8*)(this_ + 0x2b1) = 0;
    *(f32*)(this_ + 0x2b4) = lbl_8053F964;
    *(f32*)(this_ + 0x2b8) = lbl_8053F964;
    *(f32*)(this_ + 0x2bc) = lbl_8053F964;
    *(f32*)(this_ + 0x2c0) = lbl_8053F964;
    *(f32*)(this_ + 0x2c4) = lbl_8053F964;
    *(f32*)(this_ + 0x2c8) = lbl_8053F964;
    *(f32*)(this_ + 0x2cc) = lbl_8053F964;
    return this_;
}

#endif
