// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A3C50-801A6690 (unknown). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

class SayaActor {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
};

extern "C" void fn_801F4694(void* this_, s32 id);
extern s32 lbl_8053A100;

static inline void Saya_setTarget(u8* this_, s32 id) {
    *(s32*)(this_ + 0x108) = 0;
    *(s32*)(this_ + 0x10C) = id;
    JGeometry::TVec3<f32> v(1.4f, 0.4f, 0.4f);
    *(s32*)(this_ + 0xA0) = id;
    *(JGeometry::TVec3<f32>*)(this_ + 0x48) = v;
    *(s32*)(this_ + 0xD8) = 0;
    *(s32*)(this_ + 0xDC) = 0;
    *(s32*)(this_ + 0xA4) = 0;
    fn_801F4694(this_, id);
    if (*(s32*)(this_ + 4) >= 8) {
        *(s32*)(this_ + 0xA8) = 0x1E;
    } else {
        *(s32*)(this_ + 0xA8) = 0x23;
    }
    lbl_8053A100 = id;
    ((SayaActor*)this_)->v44();
}

extern "C" void fn_801A3C50(u8* this_, s32 id) {
    Saya_setTarget(this_, id);
}

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
