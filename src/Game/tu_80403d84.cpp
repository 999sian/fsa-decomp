// TU 0x80403d84-0x80414f6c.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/Table_GetSelfIndexedBit87.cpp ----
// fn_804149C0(void) - same lbl_8050EC80 global table as
// fn_803B8C90 (Game/stub_803b8c74.cpp): reads row 0's own
// selfIndex to find its row, then returns bit 0 of the byte at +0x87.
struct EC80Row {
	u8 pad0[0x10];
	u32 selfIndex; // 0x10
	u8 pad1[0x7a - 0x14];
	u8 field7a; // 0x7a
	u8 pad7b[0x87 - 0x7b];
	u8 field87; // 0x87
	u8 pad2[0xc8 - 0x88];
};

extern "C" extern EC80Row lbl_8050EC80[16];
extern "C" extern u8* lbl_8053AAF8;

// Owner object of this TU (layout partially known).
struct Obj240 {
	u8 pad[0x22];
	s16 f22;
	u8 pad24[2];
	s16 f26;
};
struct T80403D84 {
	u8 pad0[0x240];
	Obj240* parts[12]; // 0x240
	u8 pad26c[0x350 - 0x270];
	s32 state; // 0x350
	u8 pad354[0x384 - 0x354];
	s32 f384; // 0x384
	u8 pad388[0x42a - 0x388];
	s16 timer42a; // 0x42a
	u8 pad42c[0x659 - 0x42c];
	u8 f659; // 0x659
	u8 f65a; // 0x65a
	u8 pad65b[0x664 - 0x65b];
	u8 f664; // 0x664
};

extern "C" {

u8 fn_80402940(void* p, s32 a, f32 x, f32 y, s32 b);

void fn_80403D84(T80403D84* self) {
	u8 r = fn_80402940(self->parts[0], 0xb, 0.0f, 100.0f, 0);
	for (int i = 1; i < 12; i++) {
		fn_80402940(self->parts[i], 0xb, 0.0f, 100.0f, 0);
	}
	if (r) {
		self->f65a = 0;
		self->f659 = 0;
	}
}

void fn_80403EAC(T80403D84* self) {
	u8 r = fn_80402940(self->parts[0], 0x13, 100.0f, 0.0f, 0);
	for (int i = 1; i < 12; i++) {
		fn_80402940(self->parts[i], 0x13, 100.0f, 0.0f, 0);
	}
	if (r) {
		self->timer42a = 100;
		self->f659 = 2;
	}
}

void fn_80403E24(T80403D84* self) {
	self->timer42a--;
	if (self->timer42a > 0) return;
	for (int i = 0; i < 12; i++) {
		self->parts[i]->f22 = 0;
	}
	self->f659 = 3;
}

u8 fn_804045F8(void*, s32 bit) {
	if (lbl_8053AAF8[0x7e]) {
		return (lbl_8050EC80[lbl_8050EC80[0].selfIndex].field7a & (u8)(1 << bit)) != 0;
	}
	return 0;
}

void fn_8040E278(T80403D84* self) {
	if (++self->f384 > 100) {
		self->state = 0x15;
	}
}

void fn_8040E700(T80403D84* self) {
	if (self->f65a == 0) {
		self->f664 = 0;
		self->state = 8;
	}
}

void fn_8040F288(u8* self) {
	*(f32*)(self + 0x39c) = -250.0f + 250.0f * (*(s32*)(self + 0x358) / 90.0f) * (*(s32*)(self + 0x358) / 90.0f);
	if (*(f32*)(self + 0x39c) >= 0.0f) {
		*(f32*)(self + 0x39c) = 0.0f;
		*(s32*)(self + 0x358) = 0;
		if (!self[0x65d]) {
			for (int i = 0; i < 15; i++) {
				(*(Obj240**)(self + 0x278 + i * 4))->f26 = 0;
				self[0x65d] = 1;
			}
		}
		*(s32*)(self + 0x350) = 0xf;
	}
}

void fn_8040F35C(u8* self) {
	if (fn_80402940(*(void**)(self + 0x11c), 0x14, 200.0f, 0.0f, 0)) {
		*(s32*)(self + 0x350) = 0xb;
	}
}

extern u8* lbl_8053ADF8;
void fn_8040F3AC(u8* self) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			fn_80402940(*(void**)(self + 0x228 + i * 8 + j * 4), 0x14, -150.0f, 0.0f, 0);
		}
	}
	fn_80402940(*(void**)(self + 0x238), 0x14, -150.0f, 0.0f, 0);
	fn_80402940(*(void**)(self + 0x23c), 0x14, -150.0f, 0.0f, 0);
	if (fn_80402940(*(void**)(self + 0x11c), 0x14, 200.0f, 0.0f, 0)) {
		*(s32*)(self + 0x350) = 0xb;
	}
}

u32 fn_8040F474(void) {
	return *(u32*)(lbl_8053ADF8 + 0x668);
}

void fn_8041499C(u8* dst, const u8* src) {
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
	dst[3] = src[3];
}

}

struct J2DGrafContext;
struct J2DScreen {
	u8 pad[0x100];
	u8 b100;
};
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
extern "C" void fn_8037AA7C();
extern "C" void fn_8013B490(void*);
extern "C" void fn_80440EE8(void*);
extern u8* lbl_8053AB10;
extern void* lbl_8053AED8;

extern "C" void fn_804111C4(u8* self) {
	if (*(s32*)(self + 0x350) == 0x15) {
		fn_8037AA7C();
	}
	fn_8013B490(lbl_8053AB10);
	(*(J2DScreen**)(self + 0x18))->b100 = 1;
	draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 0x18), 0.0f, 0.0f, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
	fn_80440EE8(lbl_8053AED8);
}

extern "C" {


u8 fn_804149C0(void) {
	u32 idx = lbl_8050EC80[0].selfIndex;
	return lbl_8050EC80[idx].field87 & 1;
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
