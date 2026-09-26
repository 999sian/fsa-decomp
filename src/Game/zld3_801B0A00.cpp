// Game TU 801B0A00-801B27DC (ZLD3). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" s32 lbl_804A35A0[3];
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* unused, u8 flag);
extern void* lbl_804A35AC[];

extern "C" void fn_801F06F0(void* this_, const char* name, s32 idx, s32 a, s32 b, f32 x, f32 y);
extern const char lbl_804690C8[];

// ZLD3 draw
extern "C" void fn_801B0A00(u8* this_) {
    s32 id = 0x9B;
    if (*(s32*)(this_ + 0x90) == 0) {
        if (*(s32*)(this_ + 0x250) == 2 || *(s32*)(this_ + 0x250) == 3) {
            id = 0x274;
        }
        fn_801F06F0(this_, lbl_804690C8, id + *(s32*)(this_ + 0x24C), 0, 7, 1.0f, 1.0f);
    }
}

struct ZLD3_Vec {
    f32 x, y, z;
};
extern "C" u8 fn_8023F264(s32 player);
extern "C" s32 fn_8023DE58(s32 player);
extern "C" ZLD3_Vec* fn_8023E724(s32 player);
extern "C" void fn_80230498(s32 i, void* p, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);
extern "C" void fn_80230BF4(s32 player, s32 a);
extern "C" void fn_802303FC(s32 player, void* pos, s32 a);
extern "C" f64 fabs(f64);

extern "C" void fn_801B2000(u8* this_, s32 mode, f32 depth) {
    f32 y = *(f32*)(this_ + 0x10);
    y -= depth;
    u8* q = this_;
    for (s32 i = 0; i < 4; i++) {
        if (fn_8023F264(i) && *(s32*)(this_ + 4) == fn_8023DE58(i) + 0) {
            ZLD3_Vec* v = fn_8023E724(i);
            *(f32*)(q + 0x288) = v->x;
            *(f32*)(q + 0x28C) = v->y;
            *(f32*)(q + 0x290) = v->z;
            if (mode == 0) {
                if (*(u8*)(this_ + 0x258) == 1) {
                    *(f32*)(q + 0x28C) = y;
                    fn_80230498(i, q + 0x288, 0x3E, 0xFF, -0x80, -0x80, 1);
                } else {
                    fn_801F71A4((f32*)(q + 0x28C), y, 0.3f, 1.0f);
                    fn_80230BF4(i, 2);
                    fn_802303FC(i, q + 0x288, 0xFF);
                    if ((f32)fabs(fn_8023E724(i)->y - y) < 1.0f) {
                        *(u8*)(this_ + 0x258) = 1;
                    }
                }
            }
        }
        q += 0xC;
    }
}

extern "C" void fn_801B2138(void* thisObj, s32 param) {
	char* p = (char*)thisObj;
	if (*(s32*)(p + 0x254) != param) {
		*(s32*)(p + 0x254) = param;
		*(u8*)(p + 0x259) = 0;
		*(s32*)(p + 0x234) = 0;
		*(s32*)(p + 0x240) = 0;
	}
	if (*(s32*)(p + 0x234) != 0) {
		return;
	}
	switch (*(s32*)(p + 0x250)) {
	case 0:
		*(s32*)(p + 0x24c) = *(s32*)(p + 0x98) << 3;
		return;
	case 1:
		*(s32*)(p + 0x24c) = (*(s32*)(p + 0x98) << 3) + *(s32*)(p + 0x240);
		*(s32*)(p + 0x234) = 5;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) & 0x7;
		return;
	case 2:
		*(s32*)(p + 0x24c) = 2;
		return;
	case 3:
		*(s32*)(p + 0x24c) = lbl_804A35A0[*(s32*)(p + 0x240)];
		*(s32*)(p + 0x234) = 8;
		if (*(s32*)(p + 0x240) == 0) {
			*(s32*)(p + 0x234) = 0x28;
		}
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
		if (*(s32*)(p + 0x240) > 2) {
			*(s32*)(p + 0x240) = 0;
			*(s32*)(p + 0x250) = 4;
			*(s32*)(p + 0x254) = *(s32*)(p + 0x250);
		}
		return;
	case 4:
		switch (*(s32*)(p + 0x98)) {
		case 0:
			*(s32*)(p + 0x98) = 2;
			break;
		case 1:
			*(s32*)(p + 0x98) = 3;
			break;
		case 2:
			*(s32*)(p + 0x98) = 1;
			break;
		case 3:
			*(s32*)(p + 0x98) = 0;
			break;
		default:
			break;
		}
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
		*(s32*)(p + 0x234) = 5;
		if (*(s32*)(p + 0x240) >= 2) {
			*(s32*)(p + 0x240) = 0;
			*(u8*)(p + 0x259) = 1;
			*(s32*)(p + 0x250) = 0;
			*(s32*)(p + 0x254) = *(s32*)(p + 0x250);
		}
		*(s32*)(p + 0x24c) = *(s32*)(p + 0x98) << 3;
		return;
	default:
		return;
	}
}

extern char* lbl_8053AF80;
extern "C" s32 fn_80458F9C(void* mgr, s32 id);
extern "C" u8 fn_802D800C(void* mgr, s32 id);
extern "C" void fn_802D8050(void* mgr, s32 a, s32 b, s32 c);
extern "C" void* fn_80119DD0(void);
extern "C" void fn_80119998(void* p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g);

static inline void ZLD3_copyPos(u8* this_, u32 off) {
    *(f32*)(this_ + off) = *(f32*)(this_ + 0xC);
    *(f32*)(this_ + off + 4) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + off + 8) = *(f32*)(this_ + 0x14);
}

// ZLD3 init (vtable slot 1)
extern "C" void fn_801B2394(u8* this_) {
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6C) = 8.0f;
    *(f32*)(this_ + 0x80) = -8.0f;
    *(f32*)(this_ + 0x84) = -8.0f;
    *(f32*)(this_ + 0x88) = 8.0f;
    *(f32*)(this_ + 0x8C) = 8.0f;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23C) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = -1;
    fn_80458F9C(lbl_8053AF80, 0x3C);
    *(s32*)(this_ + 0x98) = 2;
    fn_801B2138(this_, *(s32*)(this_ + 0x250));
    ZLD3_copyPos(this_, 0x264);
    ZLD3_copyPos(this_, 0x270);
    ZLD3_copyPos(this_, 0x27C);
    *(u8*)(this_ + 0x258) = 0;
    *(u8*)(this_ + 0x259) = 0;
    ZLD3_copyPos(this_, 0x288);
    ZLD3_copyPos(this_, 0x294);
    ZLD3_copyPos(this_, 0x2A0);
    ZLD3_copyPos(this_, 0x2AC);
    *(void**)(this_ + 0x2B8) = 0;
    *(void**)(this_ + 0x2BC) = 0;
    *(f32*)(this_ + 0x25C) = 0.0f;
    *(f32*)(this_ + 0x260) = 0.0f;
    fn_802D7440(fn_802D6A9C(), 0);
    s32 bgm = 0xC8;
    switch (*(s32*)(this_ + 0x90)) {
    case 0:
        if (!fn_802D800C(fn_802D6A9C(), 0x10)) {
            *(s32*)(this_ + 0x230) = 0;
        } else {
            *(s32*)(this_ + 0x90) = 2;
            fn_802D8050(fn_802D6A9C(), 1, 1, 0xFF);
            *(s32*)(this_ + 0x230) = 0x14;
        }
        break;
    case 1:
        *(s32*)(this_ + 0x230) = 0xF;
        bgm = 0x64;
        break;
    }
    if (*(u8*)(this_ + 0x11C) == 1 && *(u32*)(this_ + 0x90) != 2) {
        fn_80119998(fn_80119DD0(), bgm, 0, 0, 0, 0, 0, 0);
    }
}

extern "C" void* fn_801B22F4(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A35AC;
        char* p = (char*)this_;
        int i = 0;
        do {
            void* h = *(void**)(p + 0x2b8);
            fn_801EE434(h);
            i++;
            p += 4;
        } while (i < 2);
        fn_802D7440(fn_802D6A9C(), 1);
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
