// TU 0x80438540-0x80438c68 (actor LIMT).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_80438540_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B174C[];

extern "C" void* fn_80438540(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B174C;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- fn_804385A0: LIMT draw ----
struct LimtDrawParam {
	LimtDrawParam() : m40(-1), m44(-1) {
		for (u8 i = 0; i < 16; i++) {
			mIdx[i] = i;
		}
	}
	void reset() {
		m40 = -1;
		m44 = 0;
		mMtx = NULL;
		m4C = 0;
		m4D = 0;
		m4E = 0;
		m4F = 1;
		m50 = 1;
		m51 = 0;
		m52 = 0;
		m53 = 0;
		m54 = 0;
		m55 = 0;
		m56 = 1;
		m58 = 3;
		m5C = 1;
		m5D = 0;
		m5E = 0;
		m60 = -1;
		m64 = 0;
		m68 = 2;
	}
	u8 mIdx[16];
	s32 m40;
	s32 m44;
	f32 (*mMtx)[4];
	u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
	s32 m58;
	u8 m5C, m5D, m5E;
	s32 m60;
	s32 m64;
	s32 m68;
};

extern "C" void* fn_804030C4(u32 type, const char* name);
extern "C" void fn_802F745C(void* mgr, void* pos, void* tex, LimtDrawParam* prm);
extern "C" char* lbl_8053AB10;
extern const char* lbl_804B1738[];

// NOTE: 99.9% - retail range check is "cmpwi 4; bgt" (switch lowering), ours "cmpwi 5; bge".
extern "C" void fn_804385A0(void* thisPtr) {
	char* p = (char*)thisPtr;
	LimtDrawParam prm;
	f32 mtx[3][4];
	prm.reset();
	switch (*(s32*)(p + 0x24c)) {
	case 0:
	case 1:
	case 2:
	case 3:
	case 4: {
		mtx[0][3] = 0.0f;
		mtx[1][3] = 0.0f;
		mtx[2][3] = 0.0f;
		prm.m4C = 1;
		prm.m4D = 7;
		f32 sy = *(f32*)(p + 0x260);
		f32 sx = *(f32*)(p + 0x25c);
		mtx[0][0] = sx;
		mtx[0][1] = 0.0f;
		mtx[0][2] = 0.0f;
		mtx[1][0] = 0.0f;
		mtx[1][1] = sy;
		mtx[1][2] = 0.0f;
		mtx[2][0] = 0.0f;
		mtx[2][1] = 0.0f;
		mtx[2][2] = sy;
		prm.mMtx = mtx;
		void* tex = fn_804030C4('TIMG', lbl_804B1738[*(s32*)(p + 0x24c)]);
		if (*(s32*)(p + 0x4) < 8) {
			fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), p + 0xc, tex, &prm);
		}
		break;
	}
	}
}

// ---- LIMT update / init ----
#include "JSystem/JGeometry/Vec.h"
extern "C" void* fn_801F856C(void);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern "C" u8 fn_8023F264(s32 id);
extern "C" Vec* fn_8023E724(s32 id);
extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);

static inline void limtKill(char* p) { *(u8*)(p + 0x11c) = 0; }

extern "C" void fn_8043875C(void* thisPtr) {
	char* p = (char*)thisPtr;
	for (int i = 0; i < 3; i++) {
		if (*(s32*)(p + i * 4 + 0x234) > 0) {
			(*(s32*)(p + i * 4 + 0x234))--;
		}
	}
	((JGeometry::TVec3<f32>*)(p + 0xc))->add(*(JGeometry::TVec3<f32>*)(p + 0x3c));
	char* target;
	f32 x, y, z;
	switch (*(s32*)(p + 0x230)) {
	case 0:
		*(s32*)(p + 0x230) = 1;
	case 1:
		if ((*(u32*)(p + 0x90) & 0xF) == 0) {
			char* t = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x250));
			target = t;
			if (t == NULL || *(s32*)(p + 0x24c) < 0) {
				limtKill(p);
				break;
			}
		} else {
			s32 id = *(s32*)(p + 0x250);
			if (id < 0 || id > 3 || !fn_8023F264(id) || *(s32*)(p + 0x24c) < 0) {
				limtKill(p);
				break;
			}
		}
		if ((*(u32*)(p + 0x90) & 0xF) == 0) {
			x = *(f32*)(target + 0xc);
			y = *(f32*)(target + 0x10);
			z = *(f32*)(target + 0x14);
		} else {
			Vec* v = fn_8023E724(*(s32*)(p + 0x250));
			x = v->x;
			y = v->y;
			z = v->z;
		}
		y += *(f32*)(p + 0x254);
		s32 n = *(s32*)(p + 0x24c);
		if (n >= 0 && n < 5) {
			y -= (f32)(4 - n);
			if (*(s32*)(p + 0x234) == 0) {
				f32 sc = *(f32*)(p + 0x268);
				sc *= 0.3f * (f32)(5 - n) + 1.0f;
				if (n != 0) {
					*(s32*)(p + 0x234) = n * 10;
				}
				*(f32*)(p + 0x25c) = sc;
				*(f32*)(p + 0x260) = sc;
				*(f32*)(p + 0x264) = sc;
			}
			if (*(s32*)(p + 0x24c) == 0) {
				*(f32*)(p + 0x25c) = 0.5f;
				*(f32*)(p + 0x260) = 0.5f;
				*(f32*)(p + 0x264) = 0.5f;
				*(f32*)(p + 0x268) = 0.5f;
				*(f32*)(p + 0x26c) = 0.5f;
				*(f32*)(p + 0x270) = 0.5f;
			}
			fn_801F71A4((f32*)(p + 0x25c), *(f32*)(p + 0x268), 0.2f, 0.4f);
			*(f32*)(p + 0x260) = *(f32*)(p + 0x25c);
		}
		*(f32*)(p + 0xc) = x;
		*(f32*)(p + 0x10) = y;
		*(f32*)(p + 0x14) = z;
		break;
	}
}

extern "C" void fn_804389C8(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(s32*)(p + 0x234) = 0;
	*(s32*)(p + 0x238) = 0;
	*(s32*)(p + 0x23c) = 0;
	*(s32*)(p + 0x240) = 0;
	*(s32*)(p + 0x244) = 0;
	*(s32*)(p + 0x248) = 0;
	*(s32*)(p + 0x250) = *(s32*)(p + 0x198);
	if (*(u32*)(p + 0x90) & 0xF) {
		*(s32*)(p + 0x250) = *(u32*)(p + 0x90) - 1;
	}
	*(s32*)(p + 0x24c) = 4;
	*(f32*)(p + 0x258) = 0.0f;
	*(f32*)(p + 0x254) = 0.0f;
	*(f32*)(p + 0x25c) = 0.5f;
	*(f32*)(p + 0x260) = 0.5f;
	*(f32*)(p + 0x264) = 0.5f;
	*(f32*)(p + 0x268) = 0.5f;
	*(f32*)(p + 0x26c) = 0.5f;
	*(f32*)(p + 0x270) = 0.5f;
	*(u8*)(p + 0x11e) = 1;
	*(s32*)(p + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
