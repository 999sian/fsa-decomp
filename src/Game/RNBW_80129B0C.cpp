// RNBW_80129B0C: .text 0x80129B0C-0x8012A5EC (actor RNBW)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "Game/Actor.h"

extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* manager, s32 kind);
extern "C" void* fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 c);
extern u16 lbl_80465098[];
extern u16 lbl_804650A4[];
extern f32 lbl_8053CB48;
extern f32 lbl_8053CB4C;
extern f32 lbl_8053CB50;
extern f32 lbl_8053CB54;
extern f32 lbl_8053CB58;

// ---- from Game/Rnbw_ctor_8012A364.cpp

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* Actor_ctor(void* this_);
extern void* lbl_8049E610[];

extern "C" void* fn_8012A364(void* this_) {
    Actor_ctor(this_);
    *(void**)this_ = lbl_8049E610;
    *(s32*)((char*)this_ + 0x230) = 0;
    *(s32*)((char*)this_ + 0x234) = -1;
    *(s32*)((char*)this_ + 0x238) = 0;
    *(s32*)((char*)this_ + 0x23c) = 0;
    *(s32*)((char*)this_ + 0x240) = 0;
    *(s32*)((char*)this_ + 0x244) = 0;
    *(s32*)((char*)this_ + 0x248) = 0;
    *(s32*)((char*)this_ + 0x24c) = 0;
    return this_;
}

extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void fn_801EE434(void* handle);
struct RnbwActor {
    u8 pad[0x23c];
    void* mHandles[5];
    void release(int i) { fn_801EE434(mHandles[i]); mHandles[i] = 0; }
};

inline void releaseHandle(void*& h) { fn_801EE434(h); h = 0; }

extern "C" void* fn_8012A2E0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049E610;
        RnbwActor* actor = (RnbwActor*)this_;
        s32 i = 0;
        for (; i < 5; i++) {
            fn_801EE434(actor->mHandles[i]);
            actor->mHandles[i] = 0;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
