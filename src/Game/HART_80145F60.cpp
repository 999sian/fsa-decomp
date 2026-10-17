#include "types.h"
#include "Game/Actor.h"
#include "Game/ItemBase.h"
#include "Game/SinitPoolChain.h"

extern "C" const f32 lbl_8053D050;
extern "C" const f32 lbl_8053D060;
extern "C" const f32 lbl_8053D064;
extern "C" const f32 lbl_8053D068;
extern "C" const f32 lbl_8053D06C;
extern "C" const f32 lbl_8053D070;
extern "C" const f32 lbl_8053D074;
extern "C" s32 fn_802D6A9C(void);
extern "C" char lbl_8049F4F0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80145F60(Actor* this_, s16 n) {
    if (this_ != nullptr) {
        *(void**)this_ = lbl_8049F4F0;
        __dt__5ActorFv(this_, 0);
        if (n > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* entry, s32 a, void* b, s32 d, void* e);
extern "C" u16 fn_8022461C(void* a, s32 b);
extern "C" u16 fn_80226850(void* a, s32 b);
extern "C" u32 lbl_8053D040;
extern "C" u32 lbl_8053D044;
extern "C" u32 fn_80145FC0(Actor* a, s32 b, void* c) {
    u32 tmp[2];
    tmp[0] = lbl_8053D040;
    tmp[1] = lbl_8053D044;
    s32 region = a->field_198;
    void* base = fn_8020D58C();
    u8 idx = static_cast<u8*>(base)[1];
    if (fn_8020D6AC(static_cast<u8*>(base) + idx * 0x784 + 4, b, c, region, tmp) == 1) {
        return 1;
    }
    s32 kind = fn_8022461C(c, b);
    s32 sub = fn_80226850(c, b);
    if ((u32)(kind - 0x10) <= 7 || (sub >= 0x140 && sub <= 0x15f)) {
        return 0;
    }
    if (kind != 0x0 && kind != 0x4 && kind != 0x5 && kind != 0x6 && kind != 0x7 && kind != 0x2 && kind != 0x3 &&
        kind != 0x50 && kind != 0xe && kind != 0xc && kind != 0x27 && kind != 0x28 && kind != 0x29 &&
        kind != 0x2a && kind != 0x2b && kind != 0x2c && kind != 0x2d && kind != 0x2e && kind != 0x2f &&
        kind != 0x20 && kind != 0xd && kind != 0x39 && kind != 0x3a && kind != 0x3b && kind != 0x4c &&
        kind != 0x4d && kind != 0x4e && kind != 0x4f && kind != 0x24 && kind != 0x23) {
        if (kind == 0x25) {
            return ((u8*)fn_802D6A9C())[0x171] == 0;
        }
        if (kind == 0x26) {
            return ((u8*)fn_802D6A9C())[0x171] == 1;
        }
        if (kind != 0x22 || ((u8*)fn_802D6A9C())[0x170] == 1) {
            return 1;
        }
    }
    return 0;
}

extern "C" const f32 lbl_8053D048;
extern "C" char lbl_80465BC0[];
extern "C" void fn_801F06F0(void* this_, void* p, s32 n, void* ids, s32 flag, f32 fa, f32 fb);
extern "C" void fn_803075AC(void* a, void* b, void* c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern "C" void fn_801461E4(void* this_) {
    DrawRec rec;
    rec.b2d = 1;
    if (*(s32*)((u8*)this_ + 0x234) >= 0x100 || (*(s32*)((u8*)this_ + 0x234) & 2) == 0) {
        fn_801F06F0(this_, lbl_80465BC0, 0x2c, rec.ids, 1, lbl_8053D048, lbl_8053D048);
        fn_803075AC(*(void**)((u8*)this_ + 0x198), *(void**)((u8*)this_ + 4), (u8*)this_ + 0xc, 0x2c, 0, 2, -1, 0, 0, 0);
    }
}

extern "C" void fn_80146890(void* this_) {
    f32 val = lbl_8053D050;
    *(f32*)((u8*)this_ + 0x44) = val;
    *(f32*)((u8*)this_ + 0x40) = val;
    *(f32*)((u8*)this_ + 0x3c) = val;
    *(u32*)((u8*)this_ + 0x230) = 4;
}

extern "C" void fn_801468AC(void* this_) {
    *(f32*)((u8*)this_ + 0x60) = lbl_8053D064;
    *(f32*)((u8*)this_ + 0x64) = lbl_8053D064;
    *(f32*)((u8*)this_ + 0x68) = lbl_8053D068;
    *(f32*)((u8*)this_ + 0x6c) = lbl_8053D068;
    *(f32*)((u8*)this_ + 0x80) = lbl_8053D06C;
    *(f32*)((u8*)this_ + 0x84) = lbl_8053D06C;
    *(f32*)((u8*)this_ + 0x88) = lbl_8053D060;
    *(f32*)((u8*)this_ + 0x8c) = lbl_8053D060;
    *(s32*)((u8*)this_ + 0x238) = 0;
    *(s32*)((u8*)this_ + 0x234) = 0x3ff;
    *(u32*)((u8*)this_ + 0x240) = *(u32*)((u8*)this_ + 0x90) & 3;
    *(u32*)((u8*)this_ + 0xb0) = 0x21000;
    if (*(s32*)((u8*)this_ + 0x240) != 1) {
        *(f32*)((u8*)this_ + 0x44) = lbl_8053D070;
        *(u32*)((u8*)this_ + 0x230) = 0;
        s32 iVar1 = *(s32*)((u8*)this_ + 0x4);
        s32 iVar4 = fn_802D6A9C();
        if (*(u8*)(iVar4 + 0x10000 + iVar1 + 0x31df) != 0) {
            *(f32*)((u8*)this_ + 0x10) = *(f32*)((u8*)this_ + 0x10) - *(f32*)((u8*)this_ + 0x14);
            *(f32*)((u8*)this_ + 0x14) = lbl_8053D050;
            *(f32*)((u8*)this_ + 0x44) = lbl_8053D050;
            *(f32*)((u8*)this_ + 0x40) = lbl_8053D074;
            *(s32*)((u8*)this_ + 0x230) = 2;
        }
    } else {
        *(s32*)((u8*)this_ + 0x230) = 4;
    }
}

