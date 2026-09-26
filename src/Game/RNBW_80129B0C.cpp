// RNBW_80129B0C: .text 0x80129B0C-0x8012A5EC (actor RNBW)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

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
        for (s32 i = 0; i < 5; i++) {
            fn_801EE434(((RnbwActor*)this_)->mHandles[i]);
            ((RnbwActor*)this_)->mHandles[i] = 0;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
