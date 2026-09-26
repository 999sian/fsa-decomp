// BTBZ_8012CF5C: .text 0x8012CF5C-0x8012DAC0 (actor BTBZ)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

extern "C" void v01__5ActorFv(void* this_);
extern "C" u8* fn_802D6A9C(void);
extern "C" void* fn_8013CC50(s32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern void* lbl_8049E7F0[];

struct BTBZ_Box {
    f32 x0, y0, x1, y1;
};

struct BTBZ_Vec {
    BTBZ_Vec() {}
    void set(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; }
    f32 x, y, z;
};

// ---- fn_8012D6E8: init (spawns effect 0x58 at the room centre)
extern "C" void fn_8012D6E8(u8* this_) {
    v01__5ActorFv(this_);
    *(u8*)(this_ + 0x230) = *(u32*)(this_ + 0x90) & 1;
    *(u8*)(this_ + 0x231) = (*(u32*)(this_ + 0x90) >> 1) & 1;
    if (*(void**)(this_ + 0x23C) == 0) {
        BTBZ_Vec pos;
        BTBZ_Box b = *(BTBZ_Box*)(fn_802D6A9C() + 0xCC);
        pos.set(0.5f * (b.x0 - b.x1) + b.x1, 0.5f * (b.y0 - b.y1) + b.y1, 0.0f);
        *(void**)(this_ + 0x23C) = fn_8013CC50(*(s32*)(this_ + 4), &pos, 0x58, 1, 0, 0, 0, 1, 1.0f);
        if (*(u8**)(this_ + 0x23C) != 0) {
            *(u32*)(*(u8**)(this_ + 0x23C) + 0xF4) |= 1;
        }
    }
}

// ---- fn_8012D7D4: BTBZ dtor
extern "C" void* fn_8012D7D4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049E7F0;
        fn_801EE434(*(void**)(p + 0x23C));
        *(void**)(p + 0x23C) = 0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from Game/Btbz_ctor_8012D848.cpp

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);

extern "C" void* fn_8012D848(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049E7F0;
    *(u8*)((char*)this_ + 0x230) = 0;
    *(u8*)((char*)this_ + 0x231) = 0;
    *(s32*)((char*)this_ + 0x234) = 0;
    *(s32*)((char*)this_ + 0x238) = 0;
    *(s32*)((char*)this_ + 0x23c) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
