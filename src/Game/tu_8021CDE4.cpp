// TU 0x8021cde4-0x8021d26c.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry.h"

struct Vec_8021CDE4 {
    Vec_8021CDE4() {}
    Vec_8021CDE4(f32 x_, f32 y_, f32 z_) { x = x_; y = y_; z = z_; }
    Vec_8021CDE4& operator=(const Vec_8021CDE4& o) { x = o.x; y = o.y; z = o.z; return *this; }
    f32 x, y, z;
};

struct StateInfo_8021CDE4 {
    u16 mDuration;
    u16 pad[4];
};

extern "C" {
extern const StateInfo_8021CDE4 lbl_8046A748[];
u8 fn_801CD2F8(u32 id);
void fn_801CD150(const Vec_8021CDE4& src, void* dst);
void fn_801CD0D0(void* src, void* dst);
void fn_801C3B7C(void* actor, s32 anim);
void fn_8021425C(void* slots, u8 idx, u32 a, const JGeometry::TVec3<f32>& v, u32 b);
void SetCurrentSlotIndex(void* slots, u8 idx);
void* GetCurrentSlotPtr(void* slots);
Vec_8021CDE4 fn_800FE294(void* slot, s32 alpha);

// NonMatching: only the stack slots of the two Vec temporaries are swapped.
inline void SetTarget_8021CDE4(char* p) {
    fn_801CD150(Vec_8021CDE4(*(f32*)(p + 0x570), 24.0f + *(f32*)(p + 0x574), 0.0f), p + 0x580);
}

void fn_8021CDE4(void* this_, s32 state) {
    char* p = (char*)this_;
    *(s32*)(p + 0x108) = *(s32*)(p + 0x244);
    *(s32*)(p + 0x568) = lbl_8046A748[state].mDuration;
    switch (state) {
    case 1: {
        if (fn_801CD2F8(*(u32*)(p + 0x4))) {
            *(s32*)(p + 0x58c) = 2;
            SetTarget_8021CDE4(p);
        } else {
            *(s32*)(p + 0x58c) = 0;
            fn_801CD150(*(Vec_8021CDE4*)(p + 0xc), p + 0x580);
        }
        *(s32*)(p + 0x57c) = 8;
        *(u32*)(p + 0x56c) = *(u32*)(p + 0x4);
        *(f32*)(p + 0x570) = *(f32*)(p + 0xc);
        *(f32*)(p + 0x574) = *(f32*)(p + 0x10);
        *(f32*)(p + 0x578) = *(f32*)(p + 0x14);
        fn_8021425C(p + 0x358, 1, (*(u32*)(p + 0x90) >> 12) & 0xf, *(JGeometry::TVec3<f32>*)(p + 0x580), *(u32*)(p + 0x57c));
        SetCurrentSlotIndex(p + 0x358, 1);
        *(Vec_8021CDE4*)(p + 0x32c) = fn_800FE294(GetCurrentSlotPtr(p + 0x358), 0xff);
        fn_801C3B7C(this_, 0x19);
        break;
    }
    case 2: {
        s32 cur = *(s32*)(p + 0x564);
        if (cur == 0) {
            fn_801C3B7C(this_, 0x2b);
        } else if (cur == 1) {
            *(s32*)(p + 0x58c) = 1;
            *(s32*)(p + 0x57c) = 0;
            fn_801CD0D0(p + 0xc, p + 0x580);
            *(u32*)(p + 0x56c) = *(u32*)(p + 0x4);
            *(f32*)(p + 0x570) = *(f32*)(p + 0xc);
            *(f32*)(p + 0x574) = *(f32*)(p + 0x10);
            *(f32*)(p + 0x578) = *(f32*)(p + 0x14);
            SetCurrentSlotIndex(p + 0x358, 0);
            fn_801C3B7C(this_, 0x1a);
        } else if (cur == 3) {
            *(s32*)(p + 0x568) = 1;
            if (*(s32*)(p + 0x248) != 0x2a) {
                fn_801C3B7C(this_, 0x1b);
            }
        }
        break;
    }
    case 3:
        *(u16*)(p + 0x59e) = 600;
        fn_801C3B7C(this_, 0x2e);
        break;
    }
    *(s32*)(p + 0x564) = state;
}
}

// ---- stub_8021cff8.cpp ----
// fn_8021CFF8(this) - boolean gate: this->0x564==3 AND this->0x59e==0.
// fn_8021D020(this) - fused sibling: boolean gate comparing a
// countdown (this->0x244 - this->0x568) against a remaining-hop
// budget this->0x108. Both are small SLK2 rail-state predicates.
extern "C" {

s32 fn_8021CFF8(void* thisObj) {
	s32 result = 0;
	if (*(s32*)((char*)thisObj + 0x564) == 3 && *(u16*)((char*)thisObj + 0x59e) == 0) {
		result = 1;
	}
	return result;
}

s32 fn_8021D020(void* thisObj) {
	s32 result = 0;
	s32 countdown = *(s32*)((char*)thisObj + 0x244) - *(s32*)((char*)thisObj + 0x568);
	if (*(s32*)((char*)thisObj + 0x108) <= countdown) {
		result = 1;
	}
	return result;
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
