#include "types.h"
#include "JSystem/JParticle/JPAEmitter.h"
#include "Game/ItemBase.h"

extern "C" void fn_802F86CC(void*, void*, void*, s32, f32, f32, DrawRec*);

struct Unk802A4780ResMgr {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void* vf18(u32 type, const char* name);
};


extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_8013C824(void);
extern "C" char __vt__4GOAL[];
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* a, void* p);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 c);
extern "C" void fn_8030C210(void*, void*);
extern "C" u8* lbl_8053AB10;
extern "C" u8* lbl_8053AAF8;
extern "C" const s32 lbl_8046C658[][4];
extern "C" const s32 lbl_8046C6C8[][4];
struct Unk802A4780 {
    u8 pad00[4];
    s32 m04;
    u8 pad08[4];
    JGeometry::TVec3f mPos; // 0x0c
    u8 pad18[0x230 - 0x18];
    s32 m230;
    s32 m234;
    u8 pad238[0x250 - 0x238];
    s32 m250;
    s32 m254[4];
    JGeometry::TVec3f m264[4];
};

struct Unk802A4654 {
    u8 pad00[0xc];
    JGeometry::TVec3f mPos; // 0x0c
    u8 pad18[0x234 - 0x18];
    s32 m234;
};

extern "C" void fn_802A4654(Unk802A4654* this_) {
    f32 x = this_->mPos.x;
    f32 y = this_->mPos.y;
    f32 z = this_->mPos.z;
    s32 i;
    for (i = 0; i < 4; i++) {
        this_->mPos.x = x + (f32)lbl_8046C658[this_->m234][i];
        this_->mPos.y = y + (f32)lbl_8046C6C8[this_->m234][i];
        fn_801F0E34(this_, 0x30084, 0);
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &this_->mPos);
    }
    this_->mPos.x = x;
    this_->mPos.y = y;
    this_->mPos.z = z;
}

extern "C" void* fn_802A64E8(void* this_, short how) {
    if (this_) {
        volatile u32* slot = (volatile u32*)this_;
        s32 i = 0;
        *(void**)this_ = __vt__4GOAL;
        do {
            if (slot[0xad] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xad]);
            }
            if (slot[0xb1] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xb1]);
            }
            if (slot[0xb5] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xb5]);
            }
            if (slot[0xb9] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xb9]);
            }
            if (slot[0xbd] != 0) {
                (*(JPAEmitterManager**)((char*)fn_8013C824() + 0xc))->forceDeleteEmitter((JPABaseEmitter*)slot[0xbd]);
            }
            i++;
            slot++;
        } while (i < 4);
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D752C(void*, s32);
extern "C" void fn_802D7440(void*, s32);
extern "C" void fn_8022ADE4(void);
extern "C" s32 fn_80236228(s32);
extern "C" u8* lbl_8053AAF8;
extern "C" f32 lbl_805407D0;
extern "C" f32 lbl_805407E0;
extern "C" f32 lbl_805407E4;
extern "C" f32 lbl_805407E8;
extern "C" void fn_802A6600(void* this_) {
    u8* self = (u8*)this_;
    s32 total = 0;
    s32 i;
    u32 flags;

    *(f32*)(self + 0x60) = -3.0f;
    *(f32*)(self + 0x64) = -3.0f;
    *(f32*)(self + 0x68) = 3.0f;
    *(f32*)(self + 0x6c) = 3.0f;
    *(s32*)(self + 0x230) = 0;
    *(f32*)(self + 0x44) = 0.0f;
    *(s32*)(self + 0x24c) = 9;
    *(s32*)(self + 0x250) = 0;
    *(s32*)(self + 0x2a4) = -1;
    *(s32*)(self + 0x254) = -1;
    *(s32*)(self + 0x2b4) = 0;
    *(s32*)(self + 0x2c4) = 0;
    *(s32*)(self + 0x2d4) = 0;
    *(s32*)(self + 0x2e4) = 0;
    *(s32*)(self + 0x2f4) = 0;
    *(f32*)(self + 0x264) = 0.0f;
    *(f32*)(self + 0x268) = 0.0f;
    *(f32*)(self + 0x26c) = 0.0f;
    *(s32*)(self + 0x2a8) = -1;
    *(s32*)(self + 0x258) = -1;
    *(s32*)(self + 0x2b8) = 0;
    *(s32*)(self + 0x2c8) = 0;
    *(s32*)(self + 0x2d8) = 0;
    *(s32*)(self + 0x2e8) = 0;
    *(s32*)(self + 0x2f8) = 0;
    *(f32*)(self + 0x270) = 0.0f;
    *(f32*)(self + 0x274) = 0.0f;
    *(f32*)(self + 0x278) = 0.0f;
    *(s32*)(self + 0x2ac) = -1;
    *(s32*)(self + 0x25c) = -1;
    *(s32*)(self + 0x2bc) = 0;
    *(s32*)(self + 0x2cc) = 0;
    *(s32*)(self + 0x2dc) = 0;
    *(s32*)(self + 0x2ec) = 0;
    *(s32*)(self + 0x2fc) = 0;
    *(f32*)(self + 0x27c) = 0.0f;
    *(f32*)(self + 0x280) = 0.0f;
    *(f32*)(self + 0x284) = 0.0f;
    *(s32*)(self + 0x2b0) = -1;
    *(s32*)(self + 0x260) = -1;
    *(s32*)(self + 0x2c0) = 0;
    *(s32*)(self + 0x2d0) = 0;
    *(s32*)(self + 0x2e0) = 0;
    *(s32*)(self + 0x2f0) = 0;
    *(s32*)(self + 0x300) = 0;
    *(f32*)(self + 0x288) = 0.0f;
    *(f32*)(self + 0x28c) = 0.0f;
    *(f32*)(self + 0x290) = 0.0f;
    *(s32*)(self + 0x304) = 0;
    *(s32*)(self + 0x30c) = 0;
    *(u8*)(self + 0x310) = 1;
    *(u32*)(self + 0x238) = *(u32*)(self + 0x90) & 0x1f;
    *(u32*)(self + 0x23c) = (*(u32*)(self + 0x90) >> 17) & 0x1f;
    *(u32*)(self + 0x240) = (*(u32*)(self + 0x90) >> 22) & 0x1f;
    *(u32*)(self + 0x234) = (*(u32*)(self + 0x90) >> 12) & 0x1f;
    flags = *(u32*)(self + 0x90);
    if ((flags >> 7) & 1) {
        *(f32*)(self + 0xc) = *(f32*)(self + 0xc) + lbl_805407E8;
    }
    flags = (flags >> 7) & 0x1f;
    if (flags & 2) {
        *(f32*)(self + 0x10) = *(f32*)(self + 0x10) + lbl_805407E8;
    }
    fn_802D752C(fn_802D6A9C(), 1);
    fn_802D7440(fn_802D6A9C(), 0);
    fn_8022ADE4();
    total = 0;
    for (i = 0; i < 4; i++) {
        if ((lbl_8053AAF8[0x82] & (u8)(1 << i)) != 0) {
            total += fn_80236228(i);
        }
    }
    *(s32*)(self + 0x314) = 0;
    *(s32*)(self + 0x318) = 0;
    *(s32*)(self + 0x31c) = 1;
    while (total >= 1000) {
        total -= 1000;
        *(s32*)(self + 0x314) += 1;
    }
}

