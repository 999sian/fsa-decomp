// WIND_80106ADC: .text 0x80106ADC-0x80107360 (actor WIND)
// NOTE: __ct__17fn_801070B4_actorFv (0x801070B4) is 90.5% (register allocation around the WaveController new); others in this file match.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_80106EB0.cpp

extern "C" s32 fn_80456334(s32 a, void* ptr, s32 zero);

// fn_80106EB0(a, ptr): a small thunk - dereferences the first word of
// ptr into a stack temp and calls fn_80456334(a, &temp, 0). Reads as
// an "unwrap and forward" helper, likely a virtual-call trampoline or
// a param-adapter for fn_80456334.
extern "C" s32 fn_80106EB0(s32 a, void* ptr) {
    s32 temp = *(s32*)ptr;
    return fn_80456334(a, &temp, 0);
}

// ---- from Game/fn_801070B4_ctor.cpp

struct Actor {
    Actor();
    ~Actor();
};

class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};

extern void* lbl_8049CC98[];

class fn_801070B4_actor : public Actor {
public:
    fn_801070B4_actor();
};

fn_801070B4_actor::fn_801070B4_actor() : Actor() {
    *(void**)this = lbl_8049CC98;
    char* p = (char*)this;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 3;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(WaveController**)(p + 0x244) = new WaveController(0, 0, 8);
}
