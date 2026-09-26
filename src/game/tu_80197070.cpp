// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80197070-8019D12C (unknown). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/Actor_SetVec2_0x0.cpp
// Unnamed actor cluster, part 7/9. fn_8019C4F4 - trivial 2-float setter
// (0x0/0x4), no extab.
extern "C" {

void fn_8019C4F4(void* thisPtr, f32 a, f32 b) { *(f32*)((char*)thisPtr + 0x0) = a; *(f32*)((char*)thisPtr + 0x4) = b; }

}

// from src/Game/SetField_0xb0.cpp
extern "C" {

// fn_8019CEAC(this, val) - trivial setter for this->0xb0.
void fn_8019CEAC(void* thisPtr, u32 val) {
	*(u32*)((char*)thisPtr + 0xb0) = val;
}

// fn_8019CEB4(this) - trivial getter for this->0xb0.
u32 fn_8019CEB4(void* thisPtr) {
	return *(u32*)((char*)thisPtr + 0xb0);
}

// fn_8019CEBC(this, val) - trivial setter for this->0x28c.
void fn_8019CEBC(void* thisPtr, u32 val) {
	*(u32*)((char*)thisPtr + 0x28c) = val;
}

// fn_8019CEC4(this, val) - trivial setter for this->0x2f8.
void fn_8019CEC4(void* thisPtr, u32 val) {
	*(u32*)((char*)thisPtr + 0x2f8) = val;
}

}

// from src/Game/GlobalMgr_SetByte_0x24d.cpp
// fn_8019CEE8(val) - writes a byte into the global manager struct
// (lbl_80529DEC) at +0x24d. Address-only reference (lis/addi, not
// @sda21) - declared as a zero-arg function to dodge MWCC's small-data-
// eligible heuristic, matching the established fix from fn_802150B8.
extern "C" void lbl_80529DEC();

extern "C" {

void fn_8019CEE8(u8 val) {
	*(u8*)((char*)lbl_80529DEC + 0x24d) = val;
}

// fn_8019CEF8(this, a, b, c) - trivial 3-field setter.
void fn_8019CEF8(void* thisPtr, u32 a, f32 b, u32 c) {
	char* p = (char*)thisPtr;
	*(u32*)(p + 0x250) = a;
	*(f32*)(p + 0x254) = b;
	*(u32*)(p + 0x24c) = c;
}

}

// Small (inline-style) accessors.
extern char* lbl_8053AAF8;
extern "C" void fn_8013670C(void* game, void* a);
struct SaveSlot8050 { u8 pad[0x28]; u32 flags; u8 pad2[0xc8 - 0x2c]; };
struct Save8050 { u8 pad[0x10]; s32 cur; };
extern Save8050 lbl_8050EC80;

extern "C" void fn_8019CD9C(void* a) { fn_8013670C(lbl_8053AAF8, a); }
extern "C" void fn_8019CDC4(s32 a) {
    char* g = lbl_8053AAF8;
    *(u8*)(g + 0x85) = 1;
    *(s32*)(g + 0x74) = 0;
    *(s32*)(g + 0x78) = 0;
    *(s32*)(g + 0x54) = a;
}
extern "C" void fn_8019CDE4(s32 a, s32 b) {
    if (a < 0 || a > 7) return;
    if (b < 0 || b > 3) return;
    ((SaveSlot8050*)((u8*)&lbl_8050EC80 + lbl_8050EC80.cur * 0xc8))->flags |= 1 << (b + a * 4);
}
extern "C" BOOL fn_8019CE40(s32 a, s32 b) {
    if (a < 0 || a > 7) return FALSE;
    if (b < 0 || b > 3) return FALSE;
    Save8050* t = &lbl_8050EC80;
    return (((SaveSlot8050*)((u8*)t + t->cur * 0xc8))->flags & (1 << (b + a * 4))) != 0;
}
extern "C" void fn_8019CECC(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

#include "JSystem/JAudio/JASFakeMatchFSA.h"
