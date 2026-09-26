// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A3C50-801A6690 (unknown). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/Saya_ForceState1_801A46FC.cpp
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, u32 id);
extern "C" s32 fn_801A41D8(void* this_, void* a4, void* a5);

// SAYA cluster, part 4/18 (88B). Vtable-slot wrapper that directly
// invokes state-handler fn_801A41D8 (an external "force-run this
// specific behavior" entry point, separate from the update() dispatch
// chain through fn_801A6160). Return value is passed through to callers
// that check it (e.g. extab_80145f60.s).
extern "C" s32 fn_801A46FC(void* this_, void* a4, void* a5) {
    void* base = fn_801F856C();
    void* target = fn_801F666C(base, (u32)this_);
    return fn_801A41D8(target, a4, a5);
}

// from src/Game/Saya_ForceState2_801A4D1C.cpp
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, u32 id);
extern "C" s32 fn_801A4754(void* this_, void* a4, void* a5);

// SAYA cluster, part 6/18 (88B). Vtable-slot wrapper directly invoking
// state-handler fn_801A4754 (same external-entry-point pattern as
// fn_801A46FC). Return value is passed through to callers that check it.
extern "C" s32 fn_801A4D1C(void* this_, void* a4, void* a5) {
    void* base = fn_801F856C();
    void* target = fn_801F666C(base, (u32)this_);
    return fn_801A4754(target, a4, a5);
}

// from src/Game/Saya_ForceState3_801A4F5C.cpp
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, u32 id);
extern "C" s32 fn_801A4D74(void* this_, void* a4, void* a5);

// SAYA cluster, part 8/18 (88B). Vtable-slot wrapper directly invoking
// state-handler fn_801A4D74 (same external-entry-point pattern). Return
// value is passed through to callers that check it.
extern "C" s32 fn_801A4F5C(void* this_, void* a4, void* a5) {
    void* base = fn_801F856C();
    void* target = fn_801F666C(base, (u32)this_);
    return fn_801A4D74(target, a4, a5);
}

// from src/Game/Saya_ForceState4_801A6108.cpp
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, u32 id);
extern "C" s32 fn_801A5400(void* this_, void* a4, void* a5);

// SAYA cluster, part 11/18 (88B). Vtable-slot wrapper directly invoking
// state-handler fn_801A5400 (same external-entry-point pattern). Return
// value is passed through to callers that check it.
extern "C" s32 fn_801A6108(void* this_, void* a4, void* a5) {
    void* base = fn_801F856C();
    void* target = fn_801F666C(base, (u32)this_);
    return fn_801A5400(target, a4, a5);
}

static u8 lbl_804C6640[0x30];

#include "JSystem/JAudio/JASFakeMatchFSA.h"
