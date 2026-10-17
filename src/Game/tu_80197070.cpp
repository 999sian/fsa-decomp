// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80197070-8019D12C (unknown). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

#if defined(VERSION_G4SP01)
extern "C" const f32 lbl_8053E3EC;
#endif

// from src/Game/Actor_SetVec2_0x0.cpp
// Unnamed actor cluster, part 7/9. fn_8019C4F4 - trivial 2-float setter
// (0x0/0x4), no extab.
extern "C" {

extern "C" void fn_801F71A4(f32* p, f32 target, f32 a, f32 b);
extern "C" const f32 lbl_8053E370;
extern "C" const f32 lbl_8053E374;
extern "C" const f32 lbl_8053E378;
extern "C" const f32 lbl_8053E37C;
extern "C" char* lbl_8053AB10;
extern "C" void fn_8030C210(void* p, JGeometry::TVec3<f32>* v);
extern "C" void fn_80198828(u8*);
extern "C" void fn_80197EB0(u8*);
extern "C" void fn_801979C4(u8*);
extern "C" void fn_801976E8(u8*);
extern "C" void fn_80197550(u8* this_) {
    JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
    *(s32*)(this_ + 0x108) = 10000;
    fn_801F71A4((f32*)(this_ + 0x3c), *(f32*)(this_ + 0x274), lbl_8053E374, lbl_8053E370);
    fn_801F71A4((f32*)(this_ + 0x40), *(f32*)(this_ + 0x278), lbl_8053E374, lbl_8053E370);
    fn_801F71A4((f32*)(this_ + 0x14), *(f32*)(this_ + 0x26c), lbl_8053E374, lbl_8053E370);
    ((JGeometry::TVec3<f32>*)(this_ + 0xc))->add(*(JGeometry::TVec3<f32>*)(this_ + 0x3c));
    switch (*(s32*)(this_ + 0x90)) {
    case 0:
        fn_80198828(this_);
        break;
    case 1:
        fn_80197EB0(this_);
        break;
    case 2:
        fn_801979C4(this_);
        pos.x += lbl_8053E378;
        pos.y -= lbl_8053E37C;
        break;
    case 3:
        fn_801976E8(this_);
        pos.x += lbl_8053E378;
        pos.y -= lbl_8053E37C;
        break;
    }
    fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &pos);
    for (s32 i = 0; i < 4; i++) {
        s32* t = (s32*)(this_ + i * 4);
        if (t[0x234 / 4] > 0) {
            t[0x234 / 4]--;
        }
    }
}

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
inline SaveSlot8050* curSlot8050() { return (SaveSlot8050*)((u8*)&lbl_8050EC80 + lbl_8050EC80.cur * 0xc8); }
extern "C" BOOL fn_8019CE40(s32 a, s32 b) {
    if (a < 0 || a > 7) return FALSE;
    if (b < 0 || b > 3) return FALSE;
    return (1 << (b + a * 4)) & curSlot8050()->flags ? TRUE : FALSE;
}
extern "C" void fn_8019CECC(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* mgr, s32 a);
extern u8 lbl_8053AB98;
extern u8 lbl_8053ABA8;

struct Handles_tu_80197070 { u8 pad[0x304]; void* h[13]; };
// TU_80197070 destructor
extern void* lbl_804A2944[];
extern "C" void* fn_8019C7EC(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2944;
        for (int i = 0; i < 13; i++) {
            fn_801EE434(((Handles_tu_80197070*)this_)->h[i]);
        }
        if (*(s32*)(this_ + 0x90) == 0) {
            fn_802D7440(fn_802D6A9C(), 1);
            lbl_8053AB98 = 0;
            lbl_8053ABA8 = 0;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct Vec_8019 { f32 x, y, z; };
extern "C" u8 fn_8023F264(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" void fn_80230498(s32 i, Vec_8019* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
struct Pos_8019 { u32 vt; s32 id; u8 pad[0x2a4 - 8]; Vec_8019 p[4]; };

#if defined(VERSION_G4SP01)
extern "C" void fn_8019C500(char* obj, int flag)
{
    char* p;
    int i;
    int id;
    float v[3];

    i = 0;
    p = obj;
    do {
        if (fn_8023F264(i) && (id = *(int*)(obj + 4), id == fn_8023DE58(i))) {
            v[0] = *(float*)(p + 0x2a4);
            v[1] = *(float*)(p + 0x2a8);
            v[2] = *(float*)(p + 0x2ac);
            if (flag == 0) {
                v[1] = lbl_8053E3EC + *(float*)(obj + 0x10);
            }
            fn_80230498(i, (Vec_8019*)v, 0x3f, 0xff, -0x80, -0x80, 1);
        }
        i++;
        p += 0xc;
    } while (i < 4);
}

#else
extern "C" void fn_8019C500(Pos_8019* this_, s32 flag) {
    for (int i = 0; i < 4; i++) {
        if (fn_8023F264(i)) {
            s32 id = this_->id;
            if (id == fn_8023DE58(i)) {
                Vec_8019 pos;
                pos.x = this_->p[i].x;
                pos.y = this_->p[i].y;
                pos.z = this_->p[i].z;
                if (flag == 0) {
                    pos.y = 32.0f + *(f32*)((char*)this_ + 0x10);
                }
                fn_80230498(i, &pos, 0x3f, 0xff, -0x80, -0x80, 1);
            }
        }
    }

}
#endif

#include "JSystem/JAudio/JASFakeMatchFSA.h"
