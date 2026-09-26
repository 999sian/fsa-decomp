// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8018A8D8-8018EB94 (BPH2). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/Bph2_SetVec2.cpp
// BPH2 cluster, part 5 (final piece). fn_8018E964 - trivial 2-float
// setter, no extab entry (leaf).
extern "C" {

void fn_8018E964(void* thisPtr, f32 a, f32 b) { *(f32*)((char*)thisPtr + 0x0) = a; *(f32*)((char*)thisPtr + 0x4) = b; }

}

// Small (inline-style) accessors.
extern void* lbl_8053AAF8;
extern "C" void* fn_80138A30(void* game);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void* mgr, void* a, void* b, void* c);
extern "C" void fn_802D800C(void* mgr, void* a);

extern "C" void fn_8018E890(void) {}
extern "C" void fn_8018E894(char* this_, s32 v) { *(s32*)(this_ + 0x234) = v; }
extern "C" void* fn_8018E89C(void) { return fn_80138A30(lbl_8053AAF8); }
extern "C" void fn_8018E8C0(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }
extern "C" void fn_8018E8DC(void* a, void* b, void* c) { fn_802D8050(fn_802D6A9C(), a, b, c); }
extern "C" void fn_8018E930(void* a) { fn_802D800C(fn_802D6A9C(), a); }

#include "JSystem/JAudio/JASFakeMatchFSA.h"
