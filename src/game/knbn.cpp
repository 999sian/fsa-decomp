// TU 0x8038f9f4-0x8039003c (actor KNBN).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_8038F9F4_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF428[];

extern "C" void* fn_8038F9F4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF428;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/Knbn_EmptyHook.cpp ----
// fn_8038FA54 - KNBN: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void fn_8038FA54(void) {}

}

// ---- KNBN update / init ----
#include "JSystem/JGeometry/Box.h"
struct KnbnMgr { u8 flag(u32 i) { return mFlags[i]; } u8 pad[0x131df]; u8 mFlags[1]; };
struct KnbnBox { f32 x0, y0, x1, y1; };
extern "C" u16 fn_80226850(void* pos, u32 id);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_8022FEB8(JGeometry::TBox2<f32>* box, u32 id, u32 p3, int p4, int p5);
extern "C" s32 fn_8022FD8C(u32 p);
extern "C" Vec* fn_8023E724(s32 obj);
extern "C" u8 fn_8038C678(s32 obj, u32 p2, u32 p3, u32 p4, JGeometry::TVec3<f32>* pos, u32 p6);
extern "C" s32 fn_80230CFC(s32 obj);
extern "C" u8 fn_80388CAC(s32 obj, u32 p);
extern "C" u8 fn_80138AB0(void);
extern u8* lbl_8053AAF8;

extern "C" void fn_8038FA58(void* thisPtr) {
	char* p = (char*)thisPtr;
	u32 flag;
	int kind = fn_80226850(p + 0xc, *(u32*)(p + 0x4));
	if (kind == 0x1c7) {
		*(f32*)(p + 0x60) = 0.0f;
		*(f32*)(p + 0x64) = 0.0f;
		*(f32*)(p + 0x68) = 32.0f;
		*(f32*)(p + 0x6c) = 32.0f;
	}
	JGeometry::TBox2<f32> box(2.0f + *(f32*)(p + 0x60), *(f32*)(p + 0x64), *(f32*)(p + 0x68) - 2.0f, *(f32*)(p + 0x6c) - 2.0f);
	box.addPos(*(JGeometry::TVec2<f32>*)(p + 0xc));

	switch (*(s32*)(p + 0x230)) {
	case 0:
		if (kind == 0x71 || kind == 0x3c || kind == 0x1c7) {
			u32 id = *(u32*)(p + 0x4);
			if (((KnbnMgr*)fn_802D6A9C())->flag(id) != 0) {
				fn_8022FEB8(&box, *(u32*)(p + 0x4), *(u32*)(p + 0x198), 1, 0);
			} else {
				fn_8022FEB8(&box, *(u32*)(p + 0x4), *(u32*)(p + 0x198), 1, 1);
			}
			*(s32*)(p + 0x234) = fn_8022FD8C(*(u32*)(p + 0x198));
			flag = (kind == 0x71) ? 0x200 : 0x400;
			id = *(u32*)(p + 0x4);
			if (((KnbnMgr*)fn_802D6A9C())->flag(id) != 0) {
				if (*(s32*)(p + 0x234) >= 0) {
					u32 a = *(u32*)(p + 0x198);
					u32 b = *(u32*)(p + 0x4);
					JGeometry::TVec3<f32> pos(*fn_8023E724(*(s32*)(p + 0x234)));
					if (fn_8038C678(*(s32*)(p + 0x234), (*(u32*)(p + 0x90) & 0xFFFF) + 0x12b, a, b, &pos, flag)) {
						*(s32*)(p + 0x230) = 1;
					}
				}
			} else {
				if (*(s32*)(p + 0x234) >= 0 && fn_80230CFC(*(s32*)(p + 0x234)) == 3
				    && *(f32*)(p + 0x10) <= fn_8023E724(*(s32*)(p + 0x234))->y) {
					u32 a = *(u32*)(p + 0x198);
					u32 b = *(u32*)(p + 0x4);
					JGeometry::TVec3<f32> pos(*fn_8023E724(*(s32*)(p + 0x234)));
					if (fn_8038C678(*(s32*)(p + 0x234), (*(u32*)(p + 0x90) & 0xFFFF) + 0x12b, a, b, &pos, flag)) {
						*(s32*)(p + 0x230) = 1;
					}
				}
			}
		} else {
			*(u8*)(p + 0x11c) = 0;
		}
		break;
	case 1:
		fn_8022FEB8(&box, *(u32*)(p + 0x4), *(u32*)(p + 0x198), 1, 0);
		if (fn_80388CAC(*(s32*)(p + 0x234), *(u32*)(p + 0x198))) {
			*(s32*)(p + 0x230) = 0;
		}
		break;
	}
}

static inline void knbnKill(char* p) { *(u8*)(p + 0x11c) = 0; }

extern "C" void fn_8038FD08(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(f32*)(p + 0x60) = 0.0f;
	*(f32*)(p + 0x64) = 0.0f;
	*(f32*)(p + 0x68) = 16.0f;
	*(f32*)(p + 0x6c) = 16.0f;
	*(f32*)(p + 0x3c) = 0.0f;
	*(f32*)(p + 0x40) = 0.0f;
	*(f32*)(p + 0x44) = 0.0f;
	*(s32*)(p + 0x230) = 0;
	*(s32*)(p + 0x234) = -1;
	if (lbl_8053AAF8[0x7e] == 1) {
		if (*(u32*)(p + 0x90) & 0x80000000) {
			knbnKill(p);
		} else if (fn_80138AB0() == 1 && (*(u32*)(p + 0x90) & 0x20000000)) {
			knbnKill(p);
		} else if (*(u32*)(p + 0x90) & 0x10000000) {
			knbnKill(p);
		}
	} else {
		if (*(u32*)(p + 0x90) & 0x40000000) {
			knbnKill(p);
		} else if (fn_80138AB0() == 1 && (*(u32*)(p + 0x90) & 0x20000000)) {
			knbnKill(p);
		} else if (*(u32*)(p + 0x90) & 0x10000000) {
			knbnKill(p);
		}
	}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
