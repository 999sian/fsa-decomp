// TU 0x80218cf4-0x8021a570 (actor KEPO).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

struct KepoGlobals;
extern KepoGlobals* lbl_8053AB10;
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_8030C210(void* g, f32* v);

// ---- ReturnZero_80218F80.cpp ----
// NEW ACTOR (vtable lbl_804A6550). Two trivial vtable-slot stubs, both return 0.
extern "C" {
int ReturnZero_80218F80(void) { return 0; }
int ReturnZero_80218F88(void) { return 0; }
}

// ---- stub_80219e04.cpp ----
// NEW ACTOR (vtable lbl_804A6550). "Is in an active/vulnerable window"
// predicate: true for states 6-0xa unconditionally, true for state 2
// only when variant (this->0x2b4) == 3, false otherwise.
//
// Cracked via zeldaret/tww's daNpc_Bm1_c::getBitMask() (src/d/actor/d_a_npc_bm1.cpp),
// which uses a `switch` with a default-initialized result variable and
// a single trailing return to get MWCC's switch-lowering to naturally
// produce a shared-tail merge point - if/else-if chains for this same
// logic had failed 3 times (see project_fsa_phase4_kickoff.md, 26th
// batch). The single-comparison case body also needed the established
// "default local + if-override" phrasing (not a bare `return cond;`)
// to avoid MWCC's branchless subfic/cntlzw/srwi canonicalization.
// Case declaration ORDER matters: the single-value case (2) must be
// written FIRST and the range case (6-10) SECOND for MWCC's block
// layout to match retail exactly - the reverse order (range first)
// produced byte-identical LOGIC but a 4-byte-shorter, differently
// laid out object.
extern "C" bool fn_80219E04(void* thisObj) {
	s32 v = *(s32*)((char*)thisObj + 0x248);
	bool result = false;
	switch (v) {
		case 2:
			if (*(s32*)((char*)thisObj + 0x2b4) == 3) { result = true; }
			break;
		case 6: case 7: case 8: case 9: case 10:
			result = true;
			break;
	}
	return result;
}

// ---- fn_8021A234_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6550[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_8021A234(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6550;
        fn_801EE434(*(void**)(p + 0x2c4));
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801D0F40(void* self);
extern "C" void InitDefaultRecord(void* rec);
extern void* lbl_804A6550[];

extern "C" void* fn_8021A2D0(u8* self) {
    fn_801D0F40(self);
    *(void***)self = lbl_804A6550;
    *(s32*)(self + 0x2a8) = 0;
    *(f32*)(self + 0x2ac) = 1.5f;
    *(s32*)(self + 0x2b0) = 0;
    *(s32*)(self + 0x2b4) = 0;
    *(s32*)(self + 0x2b8) = -1;
    *(f32*)(self + 0x2bc) = 0.0f;
    *(f32*)(self + 0x2c0) = 0.0f;
    *(s32*)(self + 0x2c4) = 0;
    InitDefaultRecord(self + 0x2c8);
    *(f32*)(self + 0x2d8) = 0.0f;
    return self;
}

struct J3DFrameCtrl {
    BOOL checkPass(f32 frame);
};

extern "C" void fn_801F0E34(void* self, u32 id, s32 c);
extern "C" void fn_801CE4BC(void* self);
extern "C" void fn_8021B668(void* self);

extern "C" void fn_8021917C(u8* self) {
    if (*(s32*)(self + 0x278) == 1) {
        if (((J3DFrameCtrl*)(self + 0x294))->checkPass(0.1f) || ((J3DFrameCtrl*)(self + 0x294))->checkPass(22.1f) ||
            ((J3DFrameCtrl*)(self + 0x294))->checkPass(44.1f))
        {
            fn_801F0E34(self, 0x4006b, 0);
        }
    }
    s32 prev = *(s32*)(self + 0x280);
    fn_801CE4BC(self);
    s32 state = *(s32*)(self + 0x278);
    s32 cur = *(s32*)(self + 0x280);
    if (state == 1 && prev != 5 && cur == 5) {
        fn_8021B668(self);
    }
}

struct KepoVec2 { f32 x, y; };
extern "C" void fn_801D01A0(void* self, f32 speed, void* dir, KepoVec2* out);

extern "C" void fn_80218F90(u8* self) {
    KepoVec2 v;
    *(f32*)(self + 0x3c) = 0.0f;
    *(f32*)(self + 0x40) = 0.0f;
    *(f32*)(self + 0x44) = 0.0f;
    switch (*(s32*)(self + 0x248)) {
    case 4:
        fn_801D01A0(self, *(f32*)(self + 0x254), self + 0x24, &v);
        *(f32*)(self + 0x3c) = v.x;
        *(f32*)(self + 0x40) = v.y;
        break;
    case 5:
        *(f32*)(self + 0x44) = -0.5f;
        break;
    case 0xb:
        if (*(s32*)(self + 0x280) >= 0xf || *(s32*)(self + 0x280) < 0xb) {
            *(f32*)(self + 0x44) = 0.8f;
        }
        break;
    case 0xc:
        fn_801D01A0(self, *(f32*)(self + 0x254), self + 0x2bc, &v);
        *(f32*)(self + 0x3c) = v.x;
        *(f32*)(self + 0x40) = v.y;
        break;
    }
}

struct KepoGlobals {
    u8 pad0[0x2c];
    u8* m2c;
};
extern KepoGlobals* lbl_8053AB10;
extern void* lbl_8053AAF8;
extern "C" BOOL fn_801CD950(f32* v, f32 target, f32 step);
extern "C" s32 fn_80138A30(void* game);
extern "C" void fn_80230BF4(s32 player, s32 a);
extern "C" void* fn_8023E724(s32 player);
extern "C" void fn_80230498(s32 player, void* obj, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801CE0A4(void* self, void* arg);
extern "C" void fn_8021B548(void* self);

static inline u32 kepoFlag(u8* self) {
    return *(u32*)(self + 0x230) & 0x10000;
}

extern "C" void fn_8021906C(u8* self, void* arg) {
    if (kepoFlag(self) && kepoFlag(self)) {
        switch (*(s32*)(self + 0x248)) {
        case 0:
        case 1:
            break;
        default:
            if (255.0f != *(f32*)(self + 0x2d8) && !fn_801CD950((f32*)(self + 0x2d8), 255.0f, 1.0f)) {
                s32 n = fn_80138A30(lbl_8053AAF8);
                for (s32 i = 0; i < n; i++) {
                    fn_80230BF4(i, 1);
                    fn_80230498(i, fn_8023E724(i), 0x3d, 0xff, -0x80, -0x80, 1);
                }
            }
            break;
        }
        lbl_8053AB10->m2c[0xc] = (s32)*(f32*)(self + 0x2d8);
    }
    fn_801CE0A4(self, arg);
    fn_8021B548(self);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
