// TU 0x8020b354-0x8020c0a8 (actor FOBR).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
struct JMathSinCos { f32 sin; f32 cos; };
extern "C" const JMathSinCos sincosTable___5JMath[];

// ---- Fobr_ctor_8020BE40.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A5E98[];

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" u32 fn_801F37AC(void*, u32, void*, u32, u32, u32);
extern "C" void* fn_8020B354(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5E98;
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

extern "C" void fn_8020B3E4(void* this_, u32 index, u32 value, void* pos, u32 buf) {
    if ((u8)fn_801F37AC(this_, value, pos, 0, buf, index)) {
        *(u32*)((char*)this_ + 0x230) &= ~0x80;
    }
}

extern "C" void fn_8020B500(u8* param_1) {
    *(f32*)(param_1 + 0x60) = -10.0f;
    *(f32*)(param_1 + 0x64) = -10.0f;
    *(f32*)(param_1 + 0x68) = 10.0f;
    *(f32*)(param_1 + 0x6c) = 10.0f;
}

extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void fn_802075D8(void*, u16);
extern "C" void v07__5ActorFv(void*);
extern "C" void fn_8020B74C(u8* this_) {
    void* actor = fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x2A8));
    if (actor != 0) {
        fn_802075D8(actor, *(u16*)(this_ + 0x94));
    }
    v07__5ActorFv(this_);
}

extern "C" void fn_8020B798(u8* param_1) {
    u32* ptr = (u32*)(param_1 + 0x230);
    if (*ptr != 0) {
        if ((*ptr & 0x80) != 0) {
            *ptr &= ~0x80u;
        }
    }
}

extern "C" void fn_8020B838(u8* this_) {
    *(u32*)(this_ + 0x230) |= 0x80;
}

extern "C" s32 fn_801F285C(void*, u32, void*, u32, s32);
extern "C" void* fn_8023E724(s32);
extern "C" s32 fn_8023B6CC(s32);
extern "C" void fn_80207830(void*, u16, s32, s32, void*, u32);
extern "C" s32 fn_8020B848(u8* this_) {
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

extern "C" void fn_8020BC2C() {
}

extern "C" u32 fn_801F37AC(void*, u32, void*, u32, u32, u32);
extern "C" void* fn_802D6A9C();
extern "C" const f32 lbl_8053F9D4;
extern "C" void fn_8020BC30(void* this_) {
    char* p = (char*)this_;
    switch (*(s32*)(p + 0x248)) {
    case 2: {
        s32 kind = *(s32*)(p + 0x4);
        char* record = (char*)fn_802D6A9C();
        f32* r = (f32*)((kind < 8) ? (record + 0xcc) : (record + 0xdc));
        if (*(f32*)(p + 0xc) < r[0] - lbl_8053F9D4 || *(f32*)(p + 0x10) < r[1] - lbl_8053F9D4 ||
            *(f32*)(p + 0xc) > lbl_8053F9D4 + r[2] || *(f32*)(p + 0x10) > lbl_8053F9D4 + r[3]) {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    }
    case 1:
        break;
    }
}

extern "C" void fn_8020BCE4(char* this_) {
    *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x24);
    *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x28);
    *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x2c);
}

extern "C" void* fn_8020BE40(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A5E98;
    *(s32*)((char*)this_ + 0x2a8) = -1;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "Game/ItemBase.h"
