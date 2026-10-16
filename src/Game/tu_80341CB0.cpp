#include "Game/Actor.h"


extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" void fn_80341CB0(s32 id, f32* pos) {
    Actor_CreateByID(fn_801F856C(), 0x42424D42, id, pos, 0x30000, -1, -1);
}
