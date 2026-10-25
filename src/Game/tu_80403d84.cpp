// TU 0x80403d84-0x80414f6c.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
extern "C" u8 fn_80402B10(void*, s32, f32, f32, s32);
extern "C" u8 fn_8040271C(void*, s32, f32, f32);
extern "C" void fn_80402628(void*, s32, s32, u8);
extern "C" f32 lbl_8054391C;
extern "C" f32 lbl_80543944;
extern "C" f32 lbl_805438BC;
extern "C" f32 lbl_80543898;
extern "C" f32 lbl_805438C0;
extern "C" void fn_803832BC(u8*, u32, s32, s32, s32);
extern "C" char* getStringPtr__10J2DTextBoxCFv(void*);
extern "C" char lbl_80543920[7];
extern "C" char lbl_80543928[5];
extern "C" char lbl_80543930[3];
extern "C" char lbl_80543934[8];
extern "C" char lbl_8054393C[8];
#include "JSystem/JMath/JMath.h"

// J2D pane virtuals used by fn_8040E838: search at slot 0x3c, setAnimation at slot 0x60.
struct Tu80403Pane {
	virtual void v2();
	virtual void v3();
	virtual void v4();
	virtual void v5();
	virtual void v6();
	virtual void v7();
	virtual void v8();
	virtual void v9();
	virtual void v10();
	virtual void v11();
	virtual void v12();
	virtual void v13();
	virtual void v14();
	virtual Tu80403Pane* search(u64 tag);
	virtual void v16();
	virtual void v17();
	virtual void v18();
	virtual void v19();
	virtual void v20();
	virtual void v21();
	virtual void v22();
	virtual void v23();
	virtual void setAnimation(void* a);
};
#include "std/math.h"
#include "Game/ItemBase.h"
extern "C" void fn_802F86CC(void* obj, f32* pos, void* res, s32 id, DrawRec* rec, f32 sx, f32 sy);

extern "C" s16 lbl_8048C95C[];

struct Tbl8048C1F8;
extern Tbl8048C1F8 lbl_8048C1F8;
extern u8* sManager__8JUTVideo;
extern "C" void* fn_8013CC50(void* mgr, f32 scale, f32* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);

struct Tu80406ResMgr {
	virtual void v0();
	virtual void v1();
	virtual void v2();
	virtual void v3();
	virtual void* get(u32 type, const char* name);
};

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
extern "C" char lbl_80529DEC[];
extern "C" u8 lbl_8050DB0C[];
extern u8 lbl_80543880[8];
extern u8 lbl_80543888[8];

static inline s32 EC80Bit28(s32 idx, s32 shift) {
	if (idx < 0 || idx > 7) return 0;
	return (*(u32*)((u8*)&lbl_8050EC80[lbl_8050EC80[0].selfIndex] + 0x28) & (1 << (idx * 4 + shift))) != 0;
}

// Pane pair of a 0x14-byte entry at self + 0x28 (one per row, 8 rows).
struct PaneRef {
	u8 pad0[4];
	void* pane; // 0x4
	f32 x;      // 0x8
	f32 y;      // 0xc
	u8 pad10[8];
	f32 w;      // 0x18
	f32 h;      // 0x1c
};

struct PaneEntry {
	PaneRef* x; // 0x0
	PaneRef* z; // 0x4
	PaneRef* y; // 0x8
	u8 pad[8];
};

// Owner object of this TU (layout partially known).
struct Obj240 {
	u8 pad[0x22];
	s16 f22;
	u8 pad24[2];
	s16 f26;
};
extern "C" f32 lbl_805438C8;

struct Slots208 {
	u8 pad0[0x208];
	u8* slot[16]; // 0x208, indexed by the s32 at 0x340
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

extern "C" void* lbl_8053AF80;
extern "C" u8 lbl_8048C2F8[];
extern "C" f32 lbl_805438C0;
extern "C" f32 lbl_80543898;
extern "C" void fn_80458880(void*, s32, s32);
extern "C" void fn_80402E08(void* p, f32 a, f32 b);
extern "C" void fn_804023D0(void* p, void* q, u8 b);
extern "C" void fn_80404648(u8* self) {
	if (*(u32*)(self + 0x38c) & 0x10) {
		*(s16*)(*(u8**)(self + 0xc8) + 0x20) = 0;
		*(s16*)(*(u8**)(self + 0xc8) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0xc8) + 0x24) = 0;
		*(s16*)(*(u8**)(self + 0xc8) + 0x26) = 0;
		*(s16*)(*(u8**)(self + 0xcc) + 0x20) = 0;
		*(s16*)(*(u8**)(self + 0xcc) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0xcc) + 0x24) = 0;
		*(s16*)(*(u8**)(self + 0xcc) + 0x26) = 0;
		*(s16*)(*(u8**)(self + 0xd0) + 0x20) = 0;
		*(s16*)(*(u8**)(self + 0xd0) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0xd0) + 0x24) = 0;
		*(s16*)(*(u8**)(self + 0xd0) + 0x26) = 0;
		for (s32 i = 0; i < 3; i++) {
			u8* p = self + i * 0x18;
			*(s16*)(*(u8**)(p + 0xd4) + 0x20) = 0;
			*(s16*)(*(u8**)(p + 0xd4) + 0x22) = 0;
			*(s16*)(*(u8**)(p + 0xd4) + 0x24) = 0;
			*(s16*)(*(u8**)(p + 0xd4) + 0x26) = 0;
			*(s16*)(*(u8**)(p + 0xd8) + 0x20) = 0;
			*(s16*)(*(u8**)(p + 0xd8) + 0x22) = 0;
			*(s16*)(*(u8**)(p + 0xd8) + 0x24) = 0;
			*(s16*)(*(u8**)(p + 0xd8) + 0x26) = 0;
			*(s16*)(*(u8**)(p + 0xdc) + 0x20) = 0;
			*(s16*)(*(u8**)(p + 0xdc) + 0x22) = 0;
			*(s16*)(*(u8**)(p + 0xdc) + 0x24) = 0;
			*(s16*)(*(u8**)(p + 0xdc) + 0x26) = 0;
			*(s16*)(*(u8**)(p + 0xe0) + 0x20) = 0;
			*(s16*)(*(u8**)(p + 0xe0) + 0x22) = 0;
			*(s16*)(*(u8**)(p + 0xe0) + 0x24) = 0;
			*(s16*)(*(u8**)(p + 0xe0) + 0x26) = 0;
			*(s16*)(*(u8**)(p + 0xe4) + 0x20) = 0;
			*(s16*)(*(u8**)(p + 0xe4) + 0x22) = 0;
			*(s16*)(*(u8**)(p + 0xe4) + 0x24) = 0;
			*(s16*)(*(u8**)(p + 0xe4) + 0x26) = 0;
			*(s16*)(*(u8**)(p + 0xe8) + 0x20) = 0;
			*(s16*)(*(u8**)(p + 0xe8) + 0x22) = 0;
			*(s16*)(*(u8**)(p + 0xe8) + 0x24) = 0;
			*(s16*)(*(u8**)(p + 0xe8) + 0x26) = 0;
		}
		*(s16*)(*(u8**)(self + 0x228) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x22c) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x230) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x234) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x238) + 0x22) = 0;
		*(s16*)(*(u8**)(self + 0x23c) + 0x22) = 0;
		*(s16*)(self + 0x41e) = 0;

		s32 state = *(s32*)(self + 0x340);
		if (state < 8) {
			s32 i = state * 4;
			u8* p = self + state * 16;
			u8* q = lbl_8048C2F8 + state * 64;
			while (i < *(s32*)(self + 0x340) * 4 + 4) {
				*(s16*)(*(u8**)(p + 0x128) + 0x26) = 0;
				u8* obj = *(u8**)(*(u8**)(p + 0x128) + 4);
				((void (*)(void*, s32))(*(void***)obj)[9])(obj, 0);
				void* o = *(void**)(self + 0x10);
				void* r = ((void* (*)(void*, u64))(*(void***)o)[15])(o, *(u64*)(q + 8));
				fn_804023D0(*(void**)(p + 0x128), r, *(u8*)(self + 0x641));
				p += 4;
				q += 0x10;
				i++;
			}
			u8* r29 = self + *(s32*)(self + 0x340) * 12;
			i = *(s32*)(self + 0x340) * 3;
			while (i < *(s32*)(self + 0x340) * 3 + 3) {
				*(s16*)(*(u8**)(r29 + 0x1a8) + 0x26) = 0;
				u8* obj = *(u8**)(*(u8**)(r29 + 0x1a8) + 4);
				((void (*)(void*, s32))(*(void***)obj)[9])(obj, 0);
				r29 += 4;
				i++;
			}
			*(s16*)(*(u8**)(self + *(s32*)(self + 0x340) * 4 + 0x208) + 0x26) = 0;
			u8* obj = *(u8**)(*(u8**)(self + *(s32*)(self + 0x340) * 4 + 0x208) + 4);
			((void (*)(void*, s32))(*(void***)obj)[9])(obj, 0);
		}

		for (s32 j = 0; j < 8; j++) {
			u8* base = self + j * 0x14;
			fn_80402E08(*(void**)(base + 0x28), lbl_805438C0, lbl_80543898);
			*(s16*)(*(u8**)(base + 0x28) + 0x20) = 0;
			for (s32 k = 0; k < 3; k++) {
				u8* obj = *(u8**)(base + 0x28 + k * 4);
				((void (*)(void*, s32))(*(void***)obj)[9])(obj, 0);
				*(s16*)(*(u8**)(base + 0x28 + k * 4) + 0x26) = 0;
			}
		}

		void* o = *(void**)(self + 0x10);
		u8* it = ((u8* (*)(void*, u64))(*(void***)o)[15])(o, 0x004E646174613130ULL);
		it[0xb0] = 0;
		*(s32*)(self + 0x350) = 0x13;
	} else {
		*(u32*)(self + 0x668) = 4;
		fn_80458880(lbl_8053AF80, 0xb, -1);
	}
}

typedef u8* (*SpawnFn)(void*, u32, u32, u32);
extern "C" u8 fn_803B8EBC(s32);
extern "C" void fn_80404D70(u8* self) {
	u8* p;
	*(s32*)(self + 0x370) = 0;
	if (fn_803B8EBC(7)) {
		for (s32 i = 1; i < 7; i++) {
			switch (i) {
			case 1:
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503231ULL); p[0xb0] = 0;
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503232ULL); p[0xb0] = 0;
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503233ULL); p[0xb0] = 0;
				break;
			case 2:
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503331ULL); p[0xb0] = 0;
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503332ULL); p[0xb0] = 0;
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503333ULL); p[0xb0] = 0;
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503334ULL); p[0xb0] = 0;
				break;
			case 3:
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503431ULL); p[0xb0] = 0;
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503432ULL); p[0xb0] = 0;
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503433ULL); p[0xb0] = 0;
				break;
			case 4:
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503531ULL); p[0xb0] = 0;
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503532ULL); p[0xb0] = 0;
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503533ULL); p[0xb0] = 0;
				break;
			case 5:
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503631ULL); p[0xb0] = 0;
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503632ULL); p[0xb0] = 0;
				break;
			case 6:
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503731ULL); p[0xb0] = 0;
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503732ULL); p[0xb0] = 0;
				p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503733ULL); p[0xb0] = 0;
				break;
			}
		}
		(*(u8**)(*(u8**)(self + 0xcc) + 4))[0xb0] = 1;
		*(s32*)(self + 0x370) = 7;
	} else {
		for (s32 i = 0; i < 8; i++) {
			if (fn_803B8EBC(i)) {
				s32 n = i + 1;
				if (lbl_8050EC80[lbl_8050EC80[0].selfIndex].pad1[0x82 - 0x14] & (u8)(1 << n)) {
					switch (n) {
					case 1:
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503231ULL); p[0xb0] = 0;
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503232ULL); p[0xb0] = 0;
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503233ULL); p[0xb0] = 0;
						break;
					case 2:
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503331ULL); p[0xb0] = 0;
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503332ULL); p[0xb0] = 0;
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503333ULL); p[0xb0] = 0;
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503334ULL); p[0xb0] = 0;
						break;
					case 3:
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503431ULL); p[0xb0] = 0;
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503432ULL); p[0xb0] = 0;
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503433ULL); p[0xb0] = 0;
						break;
					case 4:
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503531ULL); p[0xb0] = 0;
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503532ULL); p[0xb0] = 0;
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503533ULL); p[0xb0] = 0;
						break;
					case 5:
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503631ULL); p[0xb0] = 0;
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503632ULL); p[0xb0] = 0;
						break;
					case 6:
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503731ULL); p[0xb0] = 0;
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503732ULL); p[0xb0] = 0;
						p = (u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503733ULL); p[0xb0] = 0;
						break;
					}
					*(s32*)(self + 0x378) += 200;
					*(s32*)(self + 0x37c) += 200;
				} else {
					*(s32*)(self + 0x364) = n;
				}
				*(s32*)(self + 0x370) += 1;
			} else {
				return;
			}
			if (i == 5) {
				(*(u8**)(*(u8**)(self + 0xcc) + 4))[0xb0] = 1;
			}
		}
	}
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


extern "C" u8 fn_80404270(void*, s32);
extern "C" void fn_804446F0(void*, s32);
extern "C" void fn_80458880(void*, s32, s32);
extern void* lbl_8053AF80;
extern u8 lbl_8050DB0C[];

struct SoundIf {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void play(u32* id);
};
struct SoundHolder {
    u8 pad[8];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void play(u32* id);
};

u8 fn_80404270(void* self, s32 idx) {
	if (!((u8*)lbl_80529DEC)[0x23f] && lbl_8053AAF8[0x7e] && !((u8*)self)[0x656] && !fn_804045F8(self, idx)) {
		if (idx == 0) {
			if (EC80Bit28(idx, 1)) return 1;
		} else if (idx == 1) {
			if (EC80Bit28(idx, 1)) return 1;
		} else if (idx == 2) {
			if (EC80Bit28(idx, 1)) return 1;
		} else if (idx == 3) {
			if (EC80Bit28(idx, 1)) return 1;
		} else if (idx == 4) {
			if (EC80Bit28(idx, 1)) return 1;
		} else if (idx == 5) {
			if (EC80Bit28(idx, 1)) return 1;
		} else if (idx == 6) {
			if (EC80Bit28(idx, 1)) return 1;
		} else if (idx == 7) {
			if (EC80Bit28(idx, 2)) return 1;
		}
	}
	return 0;
}

extern "C" void fn_8040E298(u8* self) {
    (*(s16*)(self + 0x42c))++;
    if (*(s16*)(self + 0x42c) > 60) {
        if (self[0x664]) {
            self[0x664] = 2;
            *(s32*)(self + 0x350) = 6;
        } else if (fn_80404270(self, *(s32*)(self + 0x340))) {
            self[0x658] = 1;
            *(s32*)(self + 0x350) = 0x10;
            if (self[0x65d] == 1) {
                for (int i = 0; i < 15; i++) {
                    (*(Obj240**)(self + 0x278 + i * 4))->f26 = 0;
                    self[0x65d] = 0;
                }
            }
            fn_804446F0(*(void**)(self + 4), 0);
            fn_80458880(lbl_8053AF80, 0x56, -1);
        } else {
            *(s32*)(self + 0x350) = 0x15;
        }
    }
}

extern "C" void fn_8040E3A0(u8* self) {
	s32 idx = *(s32*)(self + 0x340) * 4 + *(s32*)(self + 0x348);
	f32 tx = lbl_8048C95C[idx * 2];
	f32 dx = tx - *(f32*)(self + 0x394);
	f32 tz = lbl_8048C95C[idx * 2 + 1];
	f32 dz = tz - *(f32*)(self + 0x398);
	f32 speed = (f32)*(s16*)(lbl_8050DB0C + 0x2ba) / 100.0f + 3.4f;
	f32 dist = std::sqrtf(dx * dx + dz * dz);

	if (*(u8*)(self + 0x664)) {
		if (dist < 50.0f + speed) {
			*(s16*)(self + 0x42c) = 0;
			*(s32*)(self + 0x350) = 9;
		} else {
			*(f32*)(self + 0x394) += speed * dx / dist;
			*(f32*)(self + 0x398) += speed * dz / dist;
			u32 id = 0x20064;
			(*(SoundHolder**)(self + 0x2b8))->play(&id);
		}
	} else {
		if (dist < speed) {
			*(f32*)(self + 0x394) = tx;
			*(f32*)(self + 0x398) = tz;
			*(s16*)(self + 0x42c) = 0;
			*(s32*)(self + 0x350) = 9;
		} else {
			*(f32*)(self + 0x394) += speed * dx / dist;
			*(f32*)(self + 0x398) += speed * dz / dist;
			u32 id = 0x20064;
			(*(SoundHolder**)(self + 0x2b8))->play(&id);
		}
	}

	if (*(f32*)(self + 0x394) == tx) {
		*(s32*)(self + 0x360) = 0x10;
	} else {
		s32 raw = (s32)(10430.378f * JMath::atanTable_.atan2_(-dx, -dz));
		u16 ang = raw;
		if (ang < 0x2000 || ang >= 0xe000) {
			*(s32*)(self + 0x360) = 0x18;
		} else if (ang >= 0x2000 && ang < 0x6000) {
			*(s32*)(self + 0x360) = 8;
		} else if (ang >= 0x6000 && ang <= 0xa000) {
			*(s32*)(self + 0x360) = 0x10;
		} else {
			*(s32*)(self + 0x360) = 0;
		}
	}
}

extern "C" void fn_8040F16C(u8* self) {
    *(s16*)(self + 0x434) += 0x200;
    *(s16*)(self + 0x436) += 0x400;
    *(f32*)(self + 0x3a0) = 15.0f * JMASinShort(*(s16*)(self + 0x434));
    *(f32*)(self + 0x3a4) = 5.0f * JMASinShort(*(s16*)(self + 0x436));
    if (*(s32*)(self + 0x358) < 90) {
        *(f32*)(self + 0x3a4) += -250.0f + 250.0f * (*(s32*)(self + 0x358) / 90.0f) * (*(s32*)(self + 0x358) / 90.0f);
    } else {
        u32 id = 0x400e3;
        (*(SoundHolder**)(self + 0x2c8))->play(&id);
        if (*(s32*)(self + 0x358) >= *(s16*)(lbl_8050DB0C + 0x2ca) + 90) {
            *(s32*)(self + 0x358) = 0;
            *(s32*)(self + 0x350) = 0x15;
        }
    }
}

struct J2DGrafContext;
enum J2DRotateAxis { J2DROTATE_Z = 'z' };
struct J2DPane {
	void rotate(f32, f32, J2DRotateAxis, f32);
};
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

// HUD pane reached through Screen411::search: move(x, y) at 0x10, setAlpha at 0x24.
struct Pane411 {
	virtual void v08(); virtual void v0c();
	virtual void move(f32 x, f32 y); virtual void v14(); virtual void v18(); virtual void v1c();
	virtual void v20();
	virtual void setAlpha(int a); // 0x24
	u8 pad4[0x20 - 4];
	f32 x0, y0, x1, y1; // 0x20 bounds
	u8 pad30[0xb0 - 0x30];
	u8 visible; // 0xb0

	void show() { visible = 1; }
	void hide() { visible = 0; }
};
struct Screen411 {
	virtual void v08(); virtual void v0c();
	virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
	virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
	virtual void v30(); virtual void v34(); virtual void v38();
	virtual Pane411* search(u64 tag); // 0x3c
};
// Pane position table (x, y) per slot.
struct PanePos411 {
	s16 x;
	s16 y;
};
extern "C" PanePos411 lbl_8048C9DC[];
extern "C" u8* getBounds__7J2DPaneFv(void*);
extern "C" void fn_8013B414(void* obj, f32* box, s32 flag);
extern "C" void fn_804069E8(u8* self);
extern "C" void fn_80405FC0(u8* self);
extern "C" void fn_80406634(u8* self, s32 slot, s32 flag);
extern "C" f32 lbl_80543898;
extern "C" f32 lbl_805438C4;
extern "C" f32 lbl_805438CC;
extern void* lbl_8053AEC4;
extern "C" void fn_80406F68(u8* self, f32 a, f32 b);
extern "C" void fn_80444650(void* p);
extern "C" void fn_8042EB98(void* p);

// States in which the "Pphu01" pointer pane is shown.
static inline bool Tu411ShowState(s32 st) {
	if (st == 2 || (u32)(st - 3) <= 1 || (u32)(st - 6) <= 3 || (u32)(st - 15) <= 3 ||
	    (u32)(st - 20) <= 1 || st == 22) {
		return true;
	}
	return false;
}

// Bit (idx * 4 + 3) of the current EC80 row's flag word at +0x28.
static inline BOOL Tu411SlotDone(s32 idx) {
	if (idx < 0 || idx > 7) {
		return FALSE;
	}
	return ((1 << (idx * 4 + 3)) & *(u32*)((u8*)&lbl_8050EC80[lbl_8050EC80[0].selfIndex] + 0x28)) != 0;
}

extern "C" void fn_804111C4(u8* self) {
	if (*(s32*)(self + 0x350) == 0x15) {
		fn_8037AA7C();
	}
	fn_8013B490(lbl_8053AB10);
	(*(J2DScreen**)(self + 0x18))->b100 = 1;
	draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 0x18), 0.0f, 0.0f, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
	fn_80440EE8(lbl_8053AED8);
}

extern "C" void fn_80406F68(u8* self, f32 a, f32 b);
extern "C" void fn_80411230(u8* self) {
	fn_8013B490(lbl_8053AB10);
	s32 slot = *(s32*)(self + 0x340);
	s32 st;
	if (slot < 7 && !Tu411SlotDone(slot) &&
	    (Tu411ShowState(st = *(s32*)(self + 0x350)) || st == 0x13)) {
		f32 y;
		f32 x;
		if ((*(Screen411**)(self + 0x10))->search(0x507068753031ULL)->visible == 0) {
			(*(Screen411**)(self + 0x10))->search(0x507068753031ULL)->show();
		}
		(*(Screen411**)(self + 0x10))->search(0x507068753031ULL)->setAlpha((int)((f32)self[0x65b] * *(f32*)(self + 0x3fc)));
		Pane411* p = (*(Screen411**)(self + 0x10))->search(0x507068753031ULL);
		f32 h = p->y1 - p->y0;
		p = (*(Screen411**)(self + 0x10))->search(0x507068753031ULL);
		f32 w = p->x1 - p->x0;
		y = ((f32)lbl_8048C9DC[*(s32*)(self + 0x340)].y -
		     ((f32*)getBounds__7J2DPaneFv((*(Screen411**)(self + 0x10))->search(0x4E646174613036ULL)))[1]) - h * lbl_805438C8;
		x = ((f32)lbl_8048C9DC[*(s32*)(self + 0x340)].x -
		     ((f32*)getBounds__7J2DPaneFv((*(Screen411**)(self + 0x10))->search(0x4E646174613036ULL)))[0]) - w * lbl_805438C8;
		(*(Screen411**)(self + 0x10))->search(0x507068753031ULL)->move(x, y);
	} else if (slot == 10 && *(s32*)(self + 0x348) == 2 && *(s32*)(lbl_80529DEC + 0x120) < 7 &&
	           !Tu411SlotDone(*(s32*)(lbl_80529DEC + 0x120)) && Tu411ShowState(*(s32*)(self + 0x350))) {
		f32 x;
		f32 y;
		if ((*(Screen411**)(self + 0x10))->search(0x507068753031ULL)->visible == 0) {
			(*(Screen411**)(self + 0x10))->search(0x507068753031ULL)->show();
		}
		(*(Screen411**)(self + 0x10))->search(0x507068753031ULL)->setAlpha((int)((f32)self[0x65b] * *(f32*)(self + 0x3fc)));
		s32 sy = *(s32*)(lbl_80529DEC + 0x120);
		Pane411* p = (*(Screen411**)(self + 0x10))->search(0x507068753031ULL);
		f32 h = p->y1 - p->y0;
		s32 sx = *(s32*)(lbl_80529DEC + 0x120);
		p = (*(Screen411**)(self + 0x10))->search(0x507068753031ULL);
		f32 w = p->x1 - p->x0;
		y = ((f32)lbl_8048C9DC[sy].y -
		     ((f32*)getBounds__7J2DPaneFv((*(Screen411**)(self + 0x10))->search(0x4E646174613036ULL)))[1]) - h * lbl_805438C8;
		x = ((f32)lbl_8048C9DC[sx].x -
		     ((f32*)getBounds__7J2DPaneFv((*(Screen411**)(self + 0x10))->search(0x4E646174613036ULL)))[0]) - w * lbl_805438C8;
		(*(Screen411**)(self + 0x10))->search(0x507068753031ULL)->move(x, y);
	} else if ((*(Screen411**)(self + 0x10))->search(0x507068753031ULL)->visible == 1) {
		(*(Screen411**)(self + 0x10))->search(0x507068753031ULL)->hide();
	}
	draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 0xc), lbl_80543898, lbl_80543898, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
	draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 0x14), lbl_80543898, lbl_80543898, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
	draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 0x10), lbl_80543898, lbl_80543898, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
	f32 box[4];
	box[0] = lbl_80543898;
	box[1] = lbl_80543898;
	box[2] = lbl_805438C4;
	box[3] = lbl_805438CC;
	fn_8013B414(lbl_8053AB10, box, 1);
	if (*(s32*)(self + 0x340) <= 7 || (*(s32*)(self + 0x340) == 10 && *(s32*)(self + 0x348) == 2)) {
		st = *(s32*)(self + 0x350);
		if (Tu411ShowState(st) || st == 0x13) {
			(*(s32*)(self + 0x358))++;
			fn_804069E8(self);
			if (*(s32*)(self + 0x350) != 0x13) {
				if (self[0x663]) {
					fn_80406634(self, *(s32*)(self + 0x340) - 1, 1);
				} else {
					fn_80405FC0(self);
					if (*(s32*)(self + 0x350) == 4) {
						fn_80406634(self, *(s32*)(self + 0x340), 0);
					}
				}
			}
		}
	}
	if (*(s32*)(self + 0x350) == 0x11) {
		fn_80406F68(self, *(f32*)(self + 0x3ac), *(f32*)(self + 0x3b0));
		f32 box2[4];
		box2[0] = lbl_80543898;
		box2[1] = lbl_80543898;
		box2[2] = lbl_805438C4;
		box2[3] = lbl_805438CC;
		fn_8013B414(lbl_8053AB10, box2, 1);
	}
	if (*(s32*)(self + 0x350) == 0x10) {
		fn_80444650(*(void**)(self + 4));
	} else if (*(s32*)(self + 0x350) == 0x12) {
		fn_8042EB98(lbl_8053AEC4);
	}
}

extern "C" {


u8 fn_804149C0(void) {
	u32 idx = lbl_8050EC80[0].selfIndex;
	return lbl_8050EC80[idx].field87 & 1;
}

}

// The state handlers are member functions of the menu object in the original: tables of
// member-function pointers, which MWCC initializes by copying from a .data image in __sinit.
// TODO: the handlers are still written as extern "C" free functions above; once they become
// these members (and their symbols are renamed), the table relocations will match too.
struct StateMenu {
	void fn_8040F3AC(); void fn_8040F35C(); void fn_8040F288(); void fn_8040F16C();
	void fn_8040ED20(); void fn_8040E838(); void fn_8040E720(); void fn_8040E700();
	void fn_8040E3A0(); void fn_8040E298(); void fn_8040E278(); void fn_8040D3D0();
	void fn_8040CE90(); void fn_8040C950(); void fn_8040BC1C(); void fn_80409FDC();
	void fn_8040B93C(); void fn_8040B5A0(); void fn_8040B388(); void fn_804096E8();
	void fn_80409450(); void fn_80409330();
	void fn_80403F50(); void fn_80403EAC(); void fn_80403E24(); void fn_80403D84();
};
typedef void (StateMenu::*StateMenuFn)();
static StateMenuFn sStateFns[22] = {
	&StateMenu::fn_8040F3AC, &StateMenu::fn_8040F35C, &StateMenu::fn_8040F288, &StateMenu::fn_8040F16C,
	&StateMenu::fn_8040ED20, &StateMenu::fn_8040E838, &StateMenu::fn_8040E720, &StateMenu::fn_8040E700,
	&StateMenu::fn_8040E3A0, &StateMenu::fn_8040E298, &StateMenu::fn_8040E278, &StateMenu::fn_8040D3D0,
	&StateMenu::fn_8040CE90, &StateMenu::fn_8040C950, &StateMenu::fn_8040BC1C, &StateMenu::fn_80409FDC,
	&StateMenu::fn_8040B93C, &StateMenu::fn_8040B5A0, &StateMenu::fn_8040B388, &StateMenu::fn_804096E8,
	&StateMenu::fn_80409450, &StateMenu::fn_80409330,
};
static StateMenuFn sIntroFns[4] = {
	&StateMenu::fn_80403F50, &StateMenu::fn_80403EAC, &StateMenu::fn_80403E24, &StateMenu::fn_80403D84,
};

#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "Game/ItemBase.h"
#include "dolphin/gx.h"
#include "JSystem/JUtility/JUTVideo.h"

struct Pane408 {
	virtual void v08(); virtual void v0c();
	virtual void v10(f32 x, f32 y); virtual void v14(); virtual void v18(); virtual void v1c();
	virtual void v20();
	virtual void setAlpha(int a); // 0x24
	u8 pad4[0xb0 - 4];
	u8 f0b0; // 0xb0
};
struct Screen408 {
	virtual void v08(); virtual void v0c();
	virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
	virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2c();
	virtual void v30(); virtual void v34(); virtual void v38();
	virtual Pane408* search(u64 tag); // 0x3c
};
extern u64 lbl_8048C5D0[];

extern "C" void fn_80408F38(u8* self, f32 scale) {
	for (int i = 0; i < 9; i++) {
		Pane408* p = (*(Screen408**)(self + 0x14))->search(lbl_8048C5D0[i]);
		f32 a = self[0x642 + i];
		p->setAlpha((int)(a * scale));
	}
}

extern "C" void fn_80409014(u8* self) {
	(*(s16*)(self + 0x422))++;
	if (*(s16*)(self + 0x422) >= 15) {
		*(s16*)(self + 0x422) = 0;
		if (*(u8*)(*(u8**)(*(u8**)(self + 0x228) + 4) + 0xb0)) {
			*(u8*)(*(u8**)(*(u8**)(self + 0x228) + 4) + 0xb0) = 0;
			*(u8*)(*(u8**)(*(u8**)(self + 0x22c) + 4) + 0xb0) = 1;
			*(u8*)(*(u8**)(*(u8**)(self + 0x230) + 4) + 0xb0) = 0;
			*(u8*)(*(u8**)(*(u8**)(self + 0x234) + 4) + 0xb0) = 1;
		} else {
			*(u8*)(*(u8**)(*(u8**)(self + 0x228) + 4) + 0xb0) = 1;
			*(u8*)(*(u8**)(*(u8**)(self + 0x22c) + 4) + 0xb0) = 0;
			*(u8*)(*(u8**)(*(u8**)(self + 0x230) + 4) + 0xb0) = 1;
			*(u8*)(*(u8**)(*(u8**)(self + 0x234) + 4) + 0xb0) = 0;
		}
	}
	J2DPane* pane = *(J2DPane**)(*(u8**)(self + 0x23c) + 4);
	(*(s16*)(self + 0x420))++;
	if (*(s16*)(self + 0x420) >= 180) {
		*(s16*)(self + 0x420) = 0;
	}
	s16 c = *(s16*)(self + 0x420);
	if (c < 45) {
		f32 t = (f32)(c * c) / 2025.0f;
		((void (*)(void*, f32, f32, f32, f32, f32, f32, f32, f32))(*(u32*)(*(u32*)pane + 0x104)))(pane, 1.0f - t, t, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		pane->rotate(*(f32*)(*(u8**)(self + 0x23c) + 0x18) * 0.5f, *(f32*)(*(u8**)(self + 0x23c) + 0x1c) * 0.5f, J2DROTATE_Z, 90.0f);
	} else if (c < 90) {
		s32 j = c - 45;
		f32 t = (f32)(j * j) / 2025.0f;
		((void (*)(void*, f32, f32, f32, f32, f32, f32, f32, f32))(*(u32*)(*(u32*)pane + 0x104)))(pane, t, 1.0f - t, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		pane->rotate(*(f32*)(*(u8**)(self + 0x23c) + 0x18) * 0.5f, *(f32*)(*(u8**)(self + 0x23c) + 0x1c) * 0.5f, J2DROTATE_Z, 90.0f);
	} else if (c < 135) {
		s32 j = c - 90;
		f32 t = (f32)(j * j) / 2025.0f;
		((void (*)(void*, f32, f32, f32, f32, f32, f32, f32, f32))(*(u32*)(*(u32*)pane + 0x104)))(pane, 1.0f - t, t, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		pane->rotate(*(f32*)(*(u8**)(self + 0x23c) + 0x18) * 0.5f, *(f32*)(*(u8**)(self + 0x23c) + 0x1c) * 0.5f, J2DROTATE_Z, 270.0f);
	} else {
		s32 j = c - 135;
		f32 t = (f32)(j * j) / 2025.0f;
		((void (*)(void*, f32, f32, f32, f32, f32, f32, f32, f32))(*(u32*)(*(u32*)pane + 0x104)))(pane, t, 1.0f - t, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
		pane->rotate(*(f32*)(*(u8**)(self + 0x23c) + 0x18) * 0.5f, *(f32*)(*(u8**)(self + 0x23c) + 0x1c) * 0.5f, J2DROTATE_Z, 270.0f);
	}
}

extern "C" void fn_8037AA34();
extern "C" u8 fn_8037AA28();

extern "C" void fn_80409330(u8* self) {
	fn_8037AA34();
	if (fn_8037AA28() == 0x1a) {
		if (!self[0x65d]) {
			for (int i = 0; i < 15; i++) {
				(*(Obj240**)(self + 0x278 + i * 4))->f26 = 0;
				self[0x65d] = 1;
			}
		}
		*(s32*)(self + 0x350) = 0xf;
	} else if (fn_8037AA28() == 0x19) {
		*(s32*)(self + 0x668) = 1;
	}
	if (self[0x663]) {
		*(s16*)(self + 0x434) += 0x200;
		*(s16*)(self + 0x436) += 0x400;
		*(f32*)(self + 0x3a0) = 15.0f * JMASinShort(*(s16*)(self + 0x434));
		*(f32*)(self + 0x3a4) = 5.0f * JMASinShort(*(s16*)(self + 0x436));
	}
}

extern "C" char lbl_80529DEC[];
extern "C" void fn_80409450(void* p) {
	u32 cmd1;
	u32 cmd2;
	s32 st;
	s32 bb;
	u32 bits;
	EC80Row* row;

	*(s16*)((char*)p + 0x41e) += 1;
	if (*(u8*)((char*)p + 0x663) == 0) {
		if (*(s16*)((char*)p + 0x41e) == 1) {
			char* q = (char*)p;
			for (int i = 0; i < 4; i++, q += 4) {
				*(u8*)(*(char**)(q + 0x2b8) + 0x44) = 0;
				*(u8*)(*(char**)(q + 0x2b8) + 0x45) = 0;
				cmd1 = 0x10001;
				(*(void (**)(void*, u32*))(*(char**)(*(char**)(q + 0x2b8) + 8) + 0x14))(*(void**)(q + 0x2b8), &cmd1);
			}
		} else if (*(s16*)((char*)p + 0x41e) == 0x1a) {
			s32 i = 0;
			char* q = (char*)p;
			for (; i < 4; i++, q += 4) {
				*(u8*)(*(char**)(q + 0x2b8) + 0x44) = 0;
				*(u8*)(*(char**)(q + 0x2b8) + 0x45) = 0;
				cmd2 = 0x2000e;
				(*(void (**)(void*, u32*))(*(char**)(*(char**)(q + 0x2b8) + 8) + 0x14))(*(void**)(q + 0x2b8), &cmd2);
			}
		}
	}
	if (*(s16*)((char*)p + 0x41e) >= 0x24 || *(u8*)((char*)p + 0x663) != 0) {
		st = *(s32*)((char*)p + 0x340);
		*(s32*)(lbl_80529DEC + 0x120) = st;
		*(s32*)(lbl_80529DEC + 0x124) = *(s32*)((char*)p + 0x348);
		if ((st == 0 && *(s32*)((char*)p + 0x348) == 2) || (st == 1 && *(s32*)((char*)p + 0x348) == 2) ||
			(st == 2 && *(s32*)((char*)p + 0x348) == 2) || (st == 3 && *(s32*)((char*)p + 0x348) == 2) ||
			(st == 4 && *(s32*)((char*)p + 0x348) == 2) || (st == 5 && *(s32*)((char*)p + 0x348) == 2) ||
			(st == 6 && *(s32*)((char*)p + 0x348) == 2) || (st == 7 && *(s32*)((char*)p + 0x348) == 1)) {
			*(s32*)((char*)p + 0x340) = 10;
			*(s32*)((char*)p + 0x348) = 2;
			*(u8*)(lbl_80529DEC + 0x24b) = 0;
		}
		*(s32*)(lbl_80529DEC + 0x118) = *(s32*)((char*)p + 0x340);
		st = *(s32*)((char*)p + 0x340);
		bb = *(s32*)((char*)p + 0x348);
		*(s32*)(lbl_80529DEC + 0x11c) = bb;
		if (st < 0 || st > 7) {
			bits = 0;
		} else if (bb < 0 || bb > 3) {
			bits = 0;
		} else {
			bits = 1 << (bb + st * 4);
			row = &lbl_8050EC80[lbl_8050EC80[0].selfIndex];
			bits &= *(u32*)((char*)row + 0x28);
			bits = (-bits | bits) >> 31;
		}
		if ((s32)bits != 0) {
			*(u8*)(lbl_80529DEC + 0x254) = 1;
		} else {
			*(u8*)(lbl_80529DEC + 0x254) = 0;
		}
		*(s32*)((char*)p + 0x350) = 0x16;
	}
}

extern "C" void fn_804096E8(u8* self) {
    u8* table = (u8*)&lbl_8048C1F8;
    u8 scaleDone=0;
    u8 delayDone=0;
    u8 rowsDone=0;
    u8 itemsDone=0;
    s32 i,j;
    ++*(s16*)(self+0x41e);
    if (*(s32*)(self+0x340)==7) {
        if (*(s16*)(self+0x41e)>=0) {
            self[0x640]=0;
            self[0x640]=1;
            f32 t=(f32)*(s16*)(self+0x41e)/lbl_8054391C;
            if (t>lbl_805438BC) t=lbl_805438BC;
            f32 fade=lbl_805438BC-t;
            u64* names=(u64*)(table+0x3d8);
            for(i=0;i<9;i++,names++) (*(Screen408**)(self+0x14))->search(*names)->setAlpha((s32)(self[0x642+i]*fade));
            if (*(s16*)(self+0x41e)>=20) scaleDone=1;
        }
        if (*(s16*)(self+0x41e)==1) {
            if (self[0x65e]==1) {
                (*(Obj240**)(self+0x120))->f22=0;
                (*(Obj240**)(self+0x120))->f26=0;
                (*(Obj240**)(self+0x124))->f26=0;
                self[0x65e]=0;
            }
        } else if (*(s16*)(self+0x41e)>15) delayDone=1;
    } else {
        if (*(s32*)(self+0x340)<7) {
            if (*(s16*)(self+0x41e)>=0) {
                fn_80402B10(*(void**)(self+0xc8),20,(f32)((s16*)(table+0x674))[*(s32*)(self+0x340)],lbl_80543898,0);
                fn_80402940(*(void**)(self+0xc8),20,(f32)((s16*)(table+0x684))[*(s32*)(self+0x340)],lbl_80543898,0);
                scaleDone=fn_8040271C(*(void**)(self+0xc8),20,((f32*)(table+0x658))[*(s32*)(self+0x340)]/(*(f32*)(*(u8**)(self+0xc8)+0x18)),lbl_805438BC);
                f32 factor=((f32*)(table+0x658))[*(s32*)(self+0x340)]/(*(f32*)(*(u8**)(self+0xc8)+0x18))-lbl_805438BC;
                {
                    u8* anchor=*(u8**)(self+0xc8);
                    u8* pane=*(u8**)(self+0xcc);
                    f32 dx=factor*(*(f32*)(pane+0x10)-*(f32*)(anchor+0x10));
                    f32 dy=factor*(*(f32*)(pane+0x14)-*(f32*)(anchor+0x14));
                    fn_80402B10(pane,20,dx+(f32)((s16*)(table+0x674))[*(s32*)(self+0x340)],lbl_80543898,0);
                    fn_80402940(*(void**)(self+0xcc),20,dy+(f32)((s16*)(table+0x684))[*(s32*)(self+0x340)],lbl_80543898,0);
                    fn_8040271C(*(void**)(self+0xcc),20,((f32*)(table+0x658))[*(s32*)(self+0x340)]/(*(f32*)(*(u8**)(self+0xc8)+0x18)),lbl_805438BC);
                }
                {
                    u8* anchor=*(u8**)(self+0xc8);
                    u8* pane=*(u8**)(self+0xd0);
                    f32 dx=factor*(*(f32*)(pane+0x10)-*(f32*)(anchor+0x10));
                    f32 dy=factor*(*(f32*)(pane+0x14)-*(f32*)(anchor+0x14));
                    fn_80402B10(pane,20,dx+(f32)((s16*)(table+0x674))[*(s32*)(self+0x340)],lbl_80543898,0);
                    fn_80402940(*(void**)(self+0xd0),20,dy+(f32)((s16*)(table+0x684))[*(s32*)(self+0x340)],lbl_80543898,0);
                    fn_8040271C(*(void**)(self+0xd0),20,((f32*)(table+0x658))[*(s32*)(self+0x340)]/(*(f32*)(*(u8**)(self+0xc8)+0x18)),lbl_805438BC);
                }
                u8* cursor=self;
                for(i=0;i<18;i++,cursor+=4) {
                    u8* pane=*(u8**)(cursor+0xd4);
                    f32 x=*(f32*)(pane+0x10);
                    f32 dy=factor**(f32*)(pane+0x14);
                    fn_8040271C(pane,20,((f32*)(table+0x658))[*(s32*)(self+0x340)]/(*(f32*)(*(u8**)(self+0xc8)+0x18)),lbl_805438BC);
                    fn_80402B10(*(void**)(cursor+0xd4),20,factor*x,lbl_80543898,0);
                    fn_80402940(*(void**)(cursor+0xd4),20,dy,lbl_80543898,0);
                }
            }
        } else scaleDone=1;
        if (*(s16*)(self+0x41e)==1) {
            if (self[0x65e]==1) {
                (*(Obj240**)(self+0x120))->f22=0;
                (*(Obj240**)(self+0x120))->f26=0;
                (*(Obj240**)(self+0x124))->f26=0;
                self[0x65e]=0;
            }
        } else if (*(s16*)(self+0x41e)>15) delayDone=1;
    }
    s32 last=*(s32*)(self+0x370);
    if(last>=8) last=7;
    s32 time=*(s16*)(self+0x41e);
    if(time>=0 && time<=last*2+16) {
        u8* row=self;
        s32 threshold=0;
        for(i=0;i<last+1;i++,row+=0x14,threshold+=2) {
            if(*(s16*)(self+0x41e)>=threshold) {
                fn_80402B10(*(void**)(row+0x28),16,lbl_805438C0,lbl_80543898,0);
                u8* cursor=row;
                for(j=0;j<3;j++,cursor+=4) {
                    u8* pane=*(u8**)(cursor+0x28);
                    fn_80402628(pane,16,0,pane[0x28]);
                }
            }
        }
    } else if(time>last*2+16) rowsDone=1;
    if(!self[0x657]) {
        if(*(s16*)(self+0x41e)>=10 && *(s16*)(self+0x41e)<=30) {
            u8* row=self;
            for(i=0;i<2;i++,row+=8) {
                u8* cursor=row;
                for(j=0;j<2;j++,cursor+=4) itemsDone=fn_80402940(*(void**)(cursor+0x228),15,lbl_805438C0,lbl_80543898,0);
            }
            fn_80402940(*(void**)(self+0x238),15,lbl_805438C0,lbl_80543898,0);
            fn_80402940(*(void**)(self+0x23c),15,lbl_805438C0,lbl_80543898,0);
        } else if(*(s16*)(self+0x41e)>30) itemsDone=1;
    } else itemsDone=1;
    if(scaleDone && delayDone && rowsDone && itemsDone) {
        if(self[0x657]) {
            *(s32*)(self+0x340)=*(s32*)(self+0x364);
            *(s32*)(self+0x348)=0;
            s32 state=*(s32*)(self+0x340);
            if(state<8) fn_803832BC(self+0x438,((u32*)table)[state],0,0,0);
            else if(state==8) strcpy((char*)(self+0x438),lbl_80543920);
            else if(state==9) strcpy((char*)(self+0x438),lbl_80543928);
            else if(state==10) strcpy((char*)(self+0x438),lbl_80543930);
            else if(state==11) strcpy((char*)(self+0x438),lbl_80543934);
            else if(state==12) strcpy((char*)(self+0x438),lbl_8054393C);
            else self[0x438]=0;
            strcpy(getStringPtr__10J2DTextBoxCFv((*(Screen408**)(self+0x10))->search(0x000054746c763131ULL)),(char*)(self+0x438));
            strcpy(getStringPtr__10J2DTextBoxCFv((*(Screen408**)(self+0x10))->search(0x000054746c763132ULL)),(char*)(self+0x438));
            {
            s32 state=*(s32*)(self+0x340);
            if(state<8) fn_803832BC(self+0x438,((u32*)table)[state],0,0,0);
            else if(state==8) strcpy((char*)(self+0x438),lbl_80543920);
            else if(state==9) strcpy((char*)(self+0x438),lbl_80543928);
            else if(state==10) strcpy((char*)(self+0x438),lbl_80543930);
            else if(state==11) strcpy((char*)(self+0x438),lbl_80543934);
            else if(state==12) strcpy((char*)(self+0x438),lbl_8054393C);
            else self[0x438]=0;
            }
            strcpy(getStringPtr__10J2DTextBoxCFv((*(Screen408**)(self+0x10))->search(0x000054746c763133ULL)),(char*)(self+0x438));
            strcpy(getStringPtr__10J2DTextBoxCFv((*(Screen408**)(self+0x10))->search(0x000054746c763134ULL)),(char*)(self+0x438));
        }
    }
}

extern "C" u32 fn_80309C4C(void*, s32, s32);
extern "C" s32 fn_8042EC7C(void*);
extern "C" s32 fn_8042EBEC(void*);
extern void* lbl_8053AD30;
extern void* lbl_8053AEC4;
extern "C" s16 lbl_8048C95C[];
extern "C" void fn_8040B388(u8* self) {
	switch (*(s16*)(self + 0x428)) {
	case 0:
		if (fn_8042EC7C(lbl_8053AEC4)) {
			*(s16*)(self + 0x428) = 1;
			fn_80458880(lbl_8053AF80, 0x57, -1);
		}
		break;
	case 1:
		if (fn_80309C4C(lbl_8053AD30, 0x1300, -1)) {
			s32 idx = *(s32*)(self + 0x340);
			if (idx == 0 || (u32)(idx - 1) <= 4 || idx == 6) {
				*(s32*)(self + 0x348) = 2;
			} else {
				*(s32*)(self + 0x348) = 1;
			}
			*(s32*)(self + 0x34c) = *(s32*)(self + 0x348);
			if (self[0x65e] == 1) {
				(*(Obj240**)(self + 0x120))->f22 = 0;
				(*(Obj240**)(self + 0x120))->f26 = 0;
				(*(Obj240**)(self + 0x124))->f26 = 0;
				self[0x65e] = 0;
			}
			*(f32*)(self + 0x394) = (f32)lbl_8048C95C[(*(s32*)(self + 0x340) * 4 + *(s32*)(self + 0x348)) * 2];
			*(f32*)(self + 0x398) = (f32)lbl_8048C95C[(*(s32*)(self + 0x340) * 4 + *(s32*)(self + 0x348)) * 2 + 1];
			*(s16*)(self + 0x428) = 2;
		}
		break;
	case 2:
		if (fn_8042EBEC(lbl_8053AEC4)) {
			*(s16*)(self + 0x428) = 0;
			if (self[0x658] != 0) {
				self[0x658] = 0;
				*(s32*)(self + 0x350) = 0x15;
			} else {
				if (self[0x65d] == 0) {
					for (int j = 0; j < 3; j++) {
						(*(Obj240**)(self + 0x278 + j * 0x14))->f26 = 0;
						self[0x65d] = 1;
						(*(Obj240**)(self + 0x27c + j * 0x14))->f26 = 0;
						self[0x65d] = 1;
						(*(Obj240**)(self + 0x280 + j * 0x14))->f26 = 0;
						self[0x65d] = 1;
						(*(Obj240**)(self + 0x284 + j * 0x14))->f26 = 0;
						self[0x65d] = 1;
						(*(Obj240**)(self + 0x288 + j * 0x14))->f26 = 0;
						self[0x65d] = 1;
					}
				}
				*(s32*)(self + 0x350) = 0xf;
			}
		}
		break;
	}
}

extern "C" u8 fn_804446A4(void*);
extern "C" void fn_80402E08(void*, f32, f32);
extern "C" void fn_80402CE0(void*, f32, f32);
extern "C" void appendChild__7J2DPaneFP7J2DPane(void*, void*);
extern "C" void fn_8042EDAC(void*, s32, s32);
extern "C" u8* getBounds__7J2DPaneFv(void*);
extern u64 lbl_8048C4F8[];
extern "C" void fn_8040B93C(u8* self) {
	Slots208* sl = (Slots208*)self;
	if (fn_804446A4(*(void**)(self + 4))) {
		if ((*(u8**)(self + 4))[0x4c] == 0) {
			*(s32*)(self + 0x380) = 0;
			*(s16*)(self + 0x428) = 0;
			{
				u8* x = sl->slot[*(s32*)(self + 0x340)];
				(*(u8**)(x + 4))[0xb0] = 1;
			}
			{
				u8* x = sl->slot[*(s32*)(self + 0x340)];
				u8* y = *(u8**)(x + 4);
				(*(void (**)(void*, u8))(*(u8**)y + 0x24))(y, x[0x28]);
			}
			{
				u8* x = sl->slot[*(s32*)(self + 0x340)];
				*(f32*)(self + 0x3b8) = *(f32*)(x + 0xc) - 400.0f;
			}
			f32 t;
			{
				u8* x = sl->slot[*(s32*)(self + 0x340)];
				t = *(f32*)(self + 0x3b8) - *(f32*)(x + 0xc);
				fn_80402E08(x, 0.0f, t);
			}
			{
				u8* x = sl->slot[*(s32*)(self + 0x340)];
				u8* y = *(u8**)(x + 4);
				*(f32*)(self + 0x3ac) = lbl_805438C8 * (*(f32*)(y + 0x28) - *(f32*)(y + 0x20)) + *(f32*)(y + 0x30);
			}
			{
				u8* y = *(u8**)(sl->slot[*(s32*)(self + 0x340)] + 4);
				u8* b = getBounds__7J2DPaneFv((*(Screen408**)(self + 0x10))->search(lbl_8048C4F8[*(s32*)(self + 0x340)]));
				f32 bh = *(f32*)(b + 4);
				*(f32*)(self + 0x3b0) = t + ((*(f32*)(y + 0x2c) - *(f32*)(y + 0x24)) * lbl_805438C8 + (bh + *(f32*)(self + 0x3b8)));
			}
			if (self[0x662] == 0) {
				*(s32*)(self + 0x350) = 0x11;
			} else {
				{
					u8* x = sl->slot[*(s32*)(self + 0x340)];
					fn_80402E08(x, 0.0f, 0.0f);
				}
				u8* rec = (u8*)lbl_8050EC80 + *(s32*)((u8*)lbl_8050EC80 + 0x10) * 0xc8;
				rec[0x7a] |= (u8)(1 << *(s32*)(self + 0x340));
				if (*(s32*)(self + 0x340) == 7) {
					*(u32*)(self + 0x38c) |= 1 << (*(s32*)(self + 0x340) * 4 + 1);
				} else {
					*(u32*)(self + 0x38c) |= 1 << (*(s32*)(self + 0x340) * 4 + 2);
				}
				fn_8042EDAC(lbl_8053AEC4, 0x24f, 0);
				*(s32*)(self + 0x350) = 0x12;
			}
		} else if (self[0x658]) {
			self[0x658] = 0;
			*(s32*)(self + 0x350) = 0x15;
		} else if (self[0x65d] == 0) {
			for (int i = 0; i < 15; i++) {
				(*(Obj240**)(self + 0x278 + i * 4))->f26 = 0;
				self[0x65d] = 1;
			}
			*(s32*)(self + 0x350) = 0xf;
		}
	}
}

extern "C" void fn_803832BC(u8* p, u32 id, s32 a, s32 b, s32 c);
extern "C" char* getStringPtr__10J2DTextBoxCFv(void*);
extern "C" f32 lbl_805438BC;
extern "C" f32 lbl_80543898;
extern "C" f32 lbl_805438D0;
extern "C" f32 lbl_8054397C;
extern "C" f32 lbl_80543980;
extern "C" void fn_8040C950(u8* self) {
	(*(s16*)(self + 0x426))++;
	if (*(s16*)(self + 0x426) >= 8) {
		s32 st = *(s32*)(self + 0x340);
		f32 a = 1.0f;
		if (st < 8) {
			fn_803832BC(self + 0x438, ((u32*)&lbl_8048C1F8)[st], 0, 0, 0);
		} else if (st == 8) {
			strcpy((char*)(self + 0x438), "Test-1");
		} else if (st == 9) {
			strcpy((char*)(self + 0x438), "ECTS");
		} else if (st == 10) {
			strcpy((char*)(self + 0x438), "E3");
		} else if (st == 11) {
			strcpy((char*)(self + 0x438), "Boss1-4");
		} else if (st == 12) {
			strcpy((char*)(self + 0x438), "Boss5-8");
		} else {
			self[0x438] = 0;
		}
		strcpy(getStringPtr__10J2DTextBoxCFv((*(Screen408**)(self + 0x10))->search(0x54746c763131ULL)), (char*)(self + 0x438));
		strcpy(getStringPtr__10J2DTextBoxCFv((*(Screen408**)(self + 0x10))->search(0x54746c763132ULL)), (char*)(self + 0x438));
		(*(Screen408**)(self + 0x10))->search(0x54746c763131ULL)->setAlpha((int)(self[0x64b] * a));
		(*(Screen408**)(self + 0x10))->search(0x54746c763132ULL)->setAlpha((int)(self[0x64c] * a));
		a = 0.0f;
		(*(Screen408**)(self + 0x10))->search(0x54746c763133ULL)->setAlpha((int)(self[0x64b] * a));
		(*(Screen408**)(self + 0x10))->search(0x54746c763134ULL)->setAlpha((int)(self[0x64c] * a));
		*(s32*)(self + 0x350) = 0xb;
	} else {
		s32 t = *(s16*)(self + 0x426);
		f32 w;
		f32 one = 1.0f;
		if (t < 5) {
			w = -7.0f * (f32)(t * t) / 25.0f;
			fn_80402E08(*(void**)(self + 0x228), 0.0f, w);
			fn_80402E08(*(void**)(self + 0x22c), 0.0f, w);
		} else if (t <= 10) {
			w = -7.0f * (f32)((10 - t) * (10 - t)) / 25.0f;
			fn_80402E08(*(void**)(self + 0x228), 0.0f, w);
			fn_80402E08(*(void**)(self + 0x22c), 0.0f, w);
		}
		f32 a;
		(*(Screen408**)(self + 0x10))->search(0x54746c763131ULL)->setAlpha((int)(self[0x64b] * (a = one - (f32)*(s16*)(self + 0x426) * 0.125f)));
		(*(Screen408**)(self + 0x10))->search(0x54746c763132ULL)->setAlpha((int)(self[0x64c] * a));
		(*(Screen408**)(self + 0x10))->search(0x54746c763133ULL)->setAlpha((int)(self[0x64b] * (a = one - a)));
		(*(Screen408**)(self + 0x10))->search(0x54746c763134ULL)->setAlpha((int)(self[0x64c] * a));
	}
}

extern "C" f64 lbl_805438B0;
extern "C" void fn_8040CE90(u8* self) {
	(*(s16*)(self + 0x426))++;
	if (*(s16*)(self + 0x426) >= 8) {
		s32 st = *(s32*)(self + 0x340);
		f32 a = 1.0f;
		if (st < 8) {
			fn_803832BC(self + 0x438, ((u32*)&lbl_8048C1F8)[st], 0, 0, 0);
		} else if (st == 8) {
			strcpy((char*)(self + 0x438), "Test-1");
		} else if (st == 9) {
			strcpy((char*)(self + 0x438), "ECTS");
		} else if (st == 10) {
			strcpy((char*)(self + 0x438), "E3");
		} else if (st == 11) {
			strcpy((char*)(self + 0x438), "Boss1-4");
		} else if (st == 12) {
			strcpy((char*)(self + 0x438), "Boss5-8");
		} else {
			self[0x438] = 0;
		}
		strcpy(getStringPtr__10J2DTextBoxCFv((*(Screen408**)(self + 0x10))->search(0x54746c763131ULL)), (char*)(self + 0x438));
		strcpy(getStringPtr__10J2DTextBoxCFv((*(Screen408**)(self + 0x10))->search(0x54746c763132ULL)), (char*)(self + 0x438));
		(*(Screen408**)(self + 0x10))->search(0x54746c763131ULL)->setAlpha((int)(self[0x64b] * a));
		(*(Screen408**)(self + 0x10))->search(0x54746c763132ULL)->setAlpha((int)(self[0x64c] * a));
		a = 0.0f;
		(*(Screen408**)(self + 0x10))->search(0x54746c763133ULL)->setAlpha((int)(self[0x64b] * a));
		(*(Screen408**)(self + 0x10))->search(0x54746c763134ULL)->setAlpha((int)(self[0x64c] * a));
		*(s32*)(self + 0x350) = 0xb;
	} else {
		f32 w;
		f32 a;
		if (*(s16*)(self + 0x426) < 5) {
			w = lbl_805438D0 * (f32)(*(s16*)(self + 0x426) * *(s16*)(self + 0x426)) / lbl_8054397C;
			fn_80402E08(*(void**)(self + 0x230), 0.0f, w);
			fn_80402E08(*(void**)(self + 0x234), 0.0f, w);
		} else if (*(s16*)(self + 0x426) <= 10) {
			w = lbl_805438D0 * (f32)((10 - *(s16*)(self + 0x426)) * (10 - *(s16*)(self + 0x426))) / lbl_8054397C;
			fn_80402E08(*(void**)(self + 0x230), 0.0f, w);
			fn_80402E08(*(void**)(self + 0x234), 0.0f, w);
		}
		a = 1.0f - (f32)*(s16*)(self + 0x426) * lbl_80543980;
		(*(Screen408**)(self + 0x10))->search(0x54746c763131ULL)->setAlpha((int)(self[0x64b] * a));
		(*(Screen408**)(self + 0x10))->search(0x54746c763132ULL)->setAlpha((int)(self[0x64c] * a));
		a = 1.0f - a;
		(*(Screen408**)(self + 0x10))->search(0x54746c763133ULL)->setAlpha((int)(self[0x64b] * a));
		(*(Screen408**)(self + 0x10))->search(0x54746c763134ULL)->setAlpha((int)(self[0x64c] * a));
	}
}

struct J2DTextBox {
	char* getStringPtr() const;
};
extern "C" char* strcpy(char*, const char*);
extern "C" void fn_803837A4(char* buf, s32 v, f32 a, f32 b, s32, s32);
extern "C" void fn_80402E08(void* part, f32 a, f32 b);

extern "C" void fn_80403F50(u8* self) {
	if (self[0x65a]) {
		for (int i = 0; i < 12; i++) {
			(*(Obj240**)(self + 0x240 + i * 4))->f22 = 0;
		}
		fn_803837A4((char*)(self + 0x5dc), *(s32*)(self + 0x390), *(f32*)(*(u8**)(self + 0x270) + 0x18), 1.0f, 0, 0);
		for (int i = 0; i < 2; i++) {
			strcpy((*(J2DTextBox**)(*(u8**)(self + 0x270 + i * 4) + 4))->getStringPtr(), (char*)(self + 0x5dc));
		}
		for (int i = 0; i < 12; i++) {
			fn_80402E08(*(void**)(self + 0x240 + i * 4), 0.0f, 100.0f);
		}
		self[0x659] = 1;
	}
}

struct JPAList { u8 pad[4]; s32 num; u8 pad8[4]; s32 getNum() const { return num; } };
struct JPABaseEmitter {
	u8 pad[0xcc];
	JPAList alive;  // 0xcc
	JPAList child;  // 0xd8
	u8 pade4[0xf4 - 0xe4];
	u32 flags;
	u32 checkStatus(u32 f) const { return flags & f; }
	s32 getParticleNumber() const { return alive.getNum() + child.getNum(); }
	bool isEnd() const { return checkStatus(8) && !getParticleNumber(); }
};
struct JPAEmitterManager {
	void forceDeleteEmitter(JPABaseEmitter*);
};
extern "C" void* fn_8013C824();

static inline bool emitterDone(JPABaseEmitter* e) {
	bool r = false;
	if (e->isEnd()) r = true;
	return r;
}

static inline void killEmitter(JPABaseEmitter** e) {
	(*(JPAEmitterManager**)((u8*)fn_8013C824() + 0xc))->forceDeleteEmitter(*e);
	*e = 0;
}

static inline void forceDelSlot(JPABaseEmitter** e) {
	(*(JPAEmitterManager**)((u8*)fn_8013C824() + 0xc))->forceDeleteEmitter(*e);
}

static inline void stopEmitter(void* e) {
	*(u32*)((u8*)e + 0xf4) |= 1;
	*(s32*)((u8*)e + 0x24) = 1;
}

static inline void delSlot(u8* p) {
	void* o = *(void**)p;
	if (o) ((void (*)(void*, s32))(*(void***)o)[2])(o, 1);
	*(void**)p = 0;
}

static inline void delSlot2(u8* p) {
	void* o = *(void**)p;
	if (o) ((void (*)(void*, s32))(*(void***)((u8*)o + 8))[12])(o, 1);
	*(void**)p = 0;
}

struct E720 {
	u8 pad[0x2c8];
	SoundHolder* sound;
	u8 pad2cc[0x2ec - 0x2cc];
	JPABaseEmitter* emitters[3];
	u8 pad2f8[0x350 - 0x2f8];
	s32 state;
	u8 pad354[0x35c - 0x354];
	s32 timer;
	u8 pad360[0x664 - 0x360];
	u8 f664;
};

extern "C" void fn_8040E720(E720* self) {
	self->timer++;
	if (self->timer > 10) {
		int n = 0;
		if (self->timer == 0x16) {
			u32 id = 0x30039;
			self->sound->play(&id);
		}
		for (int i = 0; i < 3; i++) {
			if (self->emitters[i]) {
				if (self->emitters[i]->isEnd()) {
					JPAEmitterManager* mgr = *(JPAEmitterManager**)((u8*)fn_8013C824() + 0xc);
					mgr->forceDeleteEmitter(self->emitters[i]);
					self->emitters[i] = 0;
					n++;
				}
			} else {
				n++;
			}
		}
		if (n == 3) {
			self->timer = 0;
			self->f664 = 0;
			self->state = 8;
		}
	}
}

extern "C" void fn_80402E70(void* p);
extern "C" void animation__9J2DScreenFv(void* p);
extern "C" void animationTransform__7J2DPaneFv(void* p);
extern "C" f64 lbl_805438A8;
extern "C" void fn_8040E838(u8* self) {
	*(s32*)(self + 0x378) += 1;
	if (*(s32*)(self + 0x378) >= *(s16*)(*(u8**)(self + 0x1c) + 6)) {
		*(s32*)(self + 0x378) = *(s16*)(*(u8**)(self + 0x1c) + 6) - 1;
	}
	*(s32*)(self + 0x37c) += 1;
	if (*(s32*)(self + 0x37c) >= *(s16*)(*(u8**)(self + 0x20) + 6)) {
		*(s32*)(self + 0x37c) = *(s16*)(*(u8**)(self + 0x20) + 6) - 1;
	}
	*(f32*)(*(u8**)(self + 0x1c) + 8) = (f32)(u32)*(s32*)(self + 0x378);
	animationTransform__7J2DPaneFv((*(Tu80403Pane**)(self + 0xc))->search(0x4e646174613038ULL));
	*(f32*)(*(u8**)(self + 0x20) + 8) = (f32)(u32)*(s32*)(self + 0x37c);
	animation__9J2DScreenFv(*(void**)(self + 0xc));
	if (*(s32*)(self + 0x378) >= *(s32*)(self + 0x364) * 200) {
		for (s32 i = 0; i < 18; i++) {
			fn_80402E70(*(void**)(self + 0xd4 + i * 4));
		}
		Tu80403Pane* pane = (*(Tu80403Pane**)(self + 0xc))->search(0x4e646174613038ULL);
		pane->setAnimation(0);
		*(s32*)(self + 0x378) = *(s32*)(self + 0x364) * 200;
		*(s32*)(self + 0x37c) = *(s32*)(self + 0x364) * 200;
		switch (*(s32*)(self + 0x364)) {
		case 1:
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503231ULL))[0xb0] = 0;
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503232ULL))[0xb0] = 0;
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503233ULL))[0xb0] = 0;
			break;
		case 2:
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503331ULL))[0xb0] = 0;
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503332ULL))[0xb0] = 0;
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503333ULL))[0xb0] = 0;
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503334ULL))[0xb0] = 0;
			break;
		case 3:
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503431ULL))[0xb0] = 0;
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503432ULL))[0xb0] = 0;
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503433ULL))[0xb0] = 0;
			break;
		case 4:
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503531ULL))[0xb0] = 0;
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503532ULL))[0xb0] = 0;
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503533ULL))[0xb0] = 0;
			break;
		case 5:
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503631ULL))[0xb0] = 0;
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503632ULL))[0xb0] = 0;
			break;
		case 6:
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503731ULL))[0xb0] = 0;
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503732ULL))[0xb0] = 0;
			((u8*)(*(Tu80403Pane**)(self + 0xc))->search(0x503733ULL))[0xb0] = 0;
			break;
		}
		u8* row = (u8*)&lbl_8050EC80[lbl_8050EC80[0].selfIndex];
		row[0x82] |= (u8)(1 << *(s32*)(self + 0x364));
		*(s32*)(self + 0x350) = 0xb;
		*(u8*)(self + 0x657) = 1;
		*(u8*)(self + 0x663) = 1;
	}
}

extern "C" void fn_8040ED20(u8* self) {
    *(s16*)(self + 0x434) += 0x200;
    *(s16*)(self + 0x436) += 0x400;
    *(f32*)(self + 0x3a0) = (f32)*(s16*)(lbl_8050DB0C + 0x2be) + 15.0f * JMASinShort(*(s16*)(self + 0x434));
    *(f32*)(self + 0x3a4) = (f32)*(s16*)(lbl_8050DB0C + 0x2c0) + 5.0f * JMASinShort(*(s16*)(self + 0x436));
    self[0x665] = 255;
    if (*(s16*)(lbl_8050DB0C + 0x2bc) == 1 && *(s16*)(self + 0x432) >= 6)
        *(s16*)(self + 0x432) -= 6;
    if (*(s16*)(self + 0x432) > *(s16*)(lbl_8050DB0C + 0x2c2)) {
        if (*(s16*)(self + 0x432) == *(s16*)(lbl_8050DB0C + 0x2c2) + 1) {
            u32 id = 0x400e2;
            (*(SoundHolder**)(self + 0x2c8))->play(&id);
        }
                f32 y;
        f32 t = (f32)(*(s16*)(self + 0x432) - *(s16*)(lbl_8050DB0C + 0x2c2)) / *(s16*)(lbl_8050DB0C + 0x2c4);
        f32 offset = -250.0f * t * t;
        y = *(f32*)(self + 0x3a4);
        y += offset;
        *(f32*)(self + 0x3a4) = y;
        if (*(f32*)(self + 0x3a4) <= -250.0f) *(f32*)(self + 0x3a4) += -250.0f;
    } else {
        u32 id = 0x400e3;
        (*(SoundHolder**)(self + 0x2c8))->play(&id);
    }
    if (*(s16*)(self + 0x432) > *(s16*)(lbl_8050DB0C + 0x2ce)) {
        s32 delta = *(s16*)(self + 0x432) - *(s16*)(lbl_8050DB0C + 0x2ce);
        if (delta < *(s16*)(lbl_8050DB0C + 0x2d0)) {
            f32 t = (f32)delta / *(s16*)(lbl_8050DB0C + 0x2d0);
            t = t * t;
            f32 alpha = 1.0f - t;
            self[0x665] = (s32)(255.0f * alpha);
        } else self[0x665] = 0;
    }
    if (*(s16*)(self + 0x432) > *(s16*)(lbl_8050DB0C + 0x2c6)) {
        f32 t = (f32)(*(s16*)(self + 0x432) - *(s16*)(lbl_8050DB0C + 0x2c6)) / *(s16*)(lbl_8050DB0C + 0x2c8);
        *(f32*)(self + 0x39c) = -250.0f * t * t;
        if (*(f32*)(self + 0x39c) <= -250.0f) {
            if (*(s16*)(lbl_8050DB0C + 0x2cc) == 1) {
                *(f32*)(self + 0x39c) = 0.0f;
                *(f32*)(self + 0x3a0) = 0.0f;
                *(f32*)(self + 0x3a4) = 0.0f;
                *(s32*)(self + 0x358) = 0;
                *(s16*)(self + 0x432) = 0;
            } else {
                *(f32*)(self + 0x39c) = -250.0f;
                self[0x657] = 1;
                u8* p;
                u8* q;
                s32 i;
                i = *(int*)(self + 0x340) * 4;
                p = self + *(int*)(self + 0x340) * 16;
                q = lbl_8048C2F8 + *(int*)(self + 0x340) * 64;
                while (i < *(int*)(self + 0x340) * 4 + 4) {
                    *(s16*)(*(u8**)(p + 0x128) + 0x26) = 0;
                    u8* obj = *(u8**)(*(u8**)(p + 0x128) + 4);
                    ((Pane408*)obj)->setAlpha(0);
                    void* o = *(void**)(self + 0x10);
                    fn_804023D0(*(void**)(p + 0x128), ((Screen408*)o)->search(*(u64*)(q + 8)), self[0x641]);
                    p += 4;
                    q += 16;
                    i++;
                }
                s32 j;
                u8* p2;
                j = *(int*)(self + 0x340) * 3;
                p2 = self + j * 4;
                while (j < *(int*)(self + 0x340) * 3 + 3) {
                    *(s16*)(*(u8**)(p2 + 0x1a8) + 0x26) = 0;
                    u8* obj = *(u8**)(*(u8**)(p2 + 0x1a8) + 4);
                    ((Pane408*)obj)->setAlpha(0);
                    p2 += 4;
                    j++;
                }
                *(s16*)(*(u8**)((self + *(int*)(self + 0x340) * 4) + 0x208) + 0x26) = 0;
                u8* obj = *(u8**)(*(u8**)((self + *(int*)(self + 0x340) * 4) + 0x208) + 4);
                ((Pane408*)obj)->setAlpha(0);
                *(s32*)(self + 0x350) = 0x13;
            }
        }
    }
}

extern "C" void fn_80411A94(u8* self, f32 scale) {
	(*(Screen408**)(self + 0x10))->search(0x54746c763131ULL)->setAlpha((int)(self[0x64b] * scale));
	(*(Screen408**)(self + 0x10))->search(0x54746c763132ULL)->setAlpha((int)(self[0x64c] * scale));
	(*(Screen408**)(self + 0x10))->search(0x54746c763133ULL)->setAlpha((int)(self[0x64b] * (scale = 1.0f - scale)));
	(*(Screen408**)(self + 0x10))->search(0x54746c763134ULL)->setAlpha((int)(self[0x64c] * scale));
}

extern u8 lbl_804B1288[];
extern "C" void fn_8042EB14(void*);
extern "C" void __dl__FPv(void*);
extern "C" u8* fn_80411C48(u8* self, s16 del) {
	if (self) {
		void* zero = 0;
		*(u8**)self = lbl_804B1288;
		fn_8042EB14(lbl_8053AEC4);
		u8* q = self;
		for (s32 i = 0; i < 4; i++, q += 4) {
			if (*(void**)(q + 0x2cc)) killEmitter((JPABaseEmitter**)(q + 0x2cc));
			if (*(void**)(q + 0x2dc)) killEmitter((JPABaseEmitter**)(q + 0x2dc));
			if (*(void**)(q + 0x2f8)) {
				stopEmitter(*(void**)(q + 0x2f8));
				*(void**)(q + 0x2f8) = 0;
			}
		}
		u8* p = self;
		for (s32 i = 0; i < 3; i++, p += 4) {
			if (*(void**)(p + 0x2ec)) killEmitter((JPABaseEmitter**)(p + 0x2ec));
			*(void**)(p + 0x2ec) = zero;
		}
		if (*(void**)(self + 0x308)) {
			stopEmitter(*(void**)(self + 0x308));
			*(void**)(self + 0x308) = 0;
		}
		if (*(void**)(self + 0x30c)) {
			stopEmitter(*(void**)(self + 0x30c));
			*(void**)(self + 0x30c) = 0;
		}
		delSlot(self + 0x4);
		delSlot(self + 0x8);
		delSlot(self + 0xc);
		delSlot(self + 0x1c);
		delSlot(self + 0x20);
		delSlot(self + 0x10);
		delSlot(self + 0x14);
		delSlot(self + 0x18);
		u8* r = self;
		for (s32 i = 0; i < 8; i++, r += 0x14) {
			u8* p2 = r;
			for (s32 j = 0; j < 3; j++, p2 += 4) {
				delSlot(p2 + 0x28);
			}
		}
		q = self;
		for (s32 i = 0; i < 0xf; i++, q += 4) {
			delSlot(q + 0x278);
		}
		delSlot(self + 0xc8);
		delSlot(self + 0xcc);
		delSlot(self + 0xd0);
		q = self;
		for (s32 i = 0; i < 0x12; i++, q += 4) {
			delSlot(q + 0xd4);
		}
		delSlot(self + 0x11c);
		q = self;
		for (s32 i = 0; i < 2; i++, q += 4) {
			delSlot(q + 0x120);
		}
		q = self;
		for (s32 i = 0; i < 0x20; i++, q += 4) {
			delSlot(q + 0x128);
		}
		q = self;
		for (s32 i = 0; i < 0x18; i++, q += 4) {
			delSlot(q + 0x1a8);
		}
		q = self;
		for (s32 i = 0; i < 8; i++, q += 4) {
			delSlot(q + 0x208);
		}
		r = self;
		for (s32 i = 0; i < 2; i++, r += 8) {
			u8* p2 = r;
			for (s32 j = 0; j < 2; j++, p2 += 4) {
				delSlot(p2 + 0x228);
			}
		}
		delSlot(self + 0x238);
		delSlot(self + 0x23c);
		q = self;
		for (s32 i = 0; i < 0xc; i++, q += 4) {
			delSlot(q + 0x240);
		}
		delSlot(self + 0x270);
		delSlot(self + 0x274);
		q = self;
		for (s32 i = 0; i < 4; i++, q += 4) {
			delSlot2(q + 0x2b8);
		}
		delSlot2(self + 0x2c8);
		lbl_8053ADF8 = 0;
		if (del > 0) __dl__FPv(self);
	}
	return self;
}

struct Tbl8048C1F8 {
	u8 pad[0x420];
	u64 names[4][2]; // 0x420
	u8 pad460[0x694 - 0x460];
	s32 vals[12][3];      // 0x694
	u8 pad724[0x744 - 0x724];
	u8 next[8][2];        // 0x744
	u8 prev[8][2];        // 0x754
};
extern Tbl8048C1F8 lbl_8048C1F8;

struct T5B10 {
	u8 pad[0x10];
	Screen408* scr; // 0x10
	u8 pad14[0x120 - 0x14];
	Obj240* p120;
	Obj240* p124;
	u8 pad128[0x340 - 0x128];
	s32 f340;
	u8 pad344[0x348 - 0x344];
	s32 f348;
	s32 f34c;
	u8 pad350[0x38c - 0x350];
	u32 f38c;
	u8 pad390[0x394 - 0x390];
	f32 f394;
	f32 f398;
	u8 pad39c[0x3bc - 0x39c];
	struct {
		f32 a;
		f32 b;
	} pos[4]; // 0x3bc
	struct {
		f32 a;
		f32 b;
	} ypos[4]; // 0x3dc
	u8 pad3fc[0x424 - 0x3fc];
	s16 f424;
	u8 pad426[0x65e - 0x426];
	u8 f65e;
};

extern "C" void fn_804054B8(T5B10* self) {
	Tbl8048C1F8* t = &lbl_8048C1F8;
	if (!self->scr->search(0x4E646174613130ULL)->f0b0) {
		self->scr->search(0x4E646174613130ULL)->f0b0 = 1;
		self->scr->search(0x4E646174613130ULL)->v10(self->f394, self->f398);
		self->f424 = 0;
		u64* e = (u64*)((u8*)t + 0x420);
		for (int i = 0; i < 4; i++, e += 2) {
			self->scr->search(e[0])->f0b0 = 0;
			self->scr->search(e[1])->f0b0 = 0;
		}
		s32 n = 0;
		for (int j = 0; j < 4; j++) {
			if (self->f38c & (1 << (self->f340 * 4 + j))) n++;
		}
		if (n > 1) {
			if (fn_804045F8(self, self->f340)) {
				if ((self->f340 <= 5 || self->f340 == 6) && !(self->f38c & (1 << (self->f340 * 4 + 1)))) {
					if (self->f34c == 0) {
						self->scr->search(t->names[lbl_80543880[self->f340]][0])->f0b0 = 1;
					}
					if (self->f34c == 2) {
						self->scr->search(t->names[lbl_80543888[self->f340]][0])->f0b0 = 1;
					}
				} else if (self->f34c < n - 1) {
					self->scr->search(t->names[((u8*)t)[0x714 + self->f340 * 3 + self->f34c]][0])->f0b0 = 1;
					if (self->f34c > 0) {
						self->scr->search(t->names[((u8*)t)[0x72c + self->f340 * 3 + self->f34c - 1]][0])->f0b0 = 1;
					}
				} else {
					if (n - 1 == 4 && self->f34c < 2) {
						self->scr->search(t->names[t->next[self->f340][self->f34c]][0])->f0b0 = 1;
					}
					if (self->f34c > 0) {
						self->scr->search(t->names[t->prev[self->f340][self->f34c - 1]][0])->f0b0 = 1;
					}
				}
			}
		}
	}
	if (++self->f424 >= 15) {
		self->f424 = 0;
		u64* e = (u64*)((u8*)t + 0x420);
		for (int i = 0; i < 4; i++, e += 2) {
			if (self->scr->search(e[0])->f0b0) {
				self->scr->search(e[0])->f0b0 = 0;
				self->scr->search(e[1])->f0b0 = 1;
			} else if (self->scr->search(e[1])->f0b0) {
				self->scr->search(e[0])->f0b0 = 1;
				self->scr->search(e[1])->f0b0 = 0;
			}
		}
	}
	u8* p = (u8*)self;
	s16* q = (s16*)(lbl_8050DB0C + 0x274);
	u64* e = (u64*)((u8*)t + 0x420);
	for (int i = 0; i < 4; i++, e += 2, q += 2, p += 8) {
		self->scr->search(e[0])->v10(*(f32*)(p + 0x3bc) + (f32)q[0], *(f32*)(p + 0x3dc) + (f32)q[1]);
		self->scr->search(e[1])->v10(*(f32*)(p + 0x3c0) + (f32)q[0], *(f32*)(p + 0x3e0) + (f32)q[1]);
	}
}

extern "C" void fn_80405B10(T5B10* self, s32 key) {
	Tbl8048C1F8* t = &lbl_8048C1F8;
	int n = 0;
	for (int j = 0; j < 4; j++) {
		if (self->f38c & (1 << (self->f340 * 4 + j))) n++;
	}
	if (n == 1) return;
	if (self->f34c < n - 1 && key == *((u8*)t->next + self->f340 * 2 + self->f34c)) {
		self->f34c++;
		self->f348 = *(s32*)((u8*)t->vals + self->f340 * 12 + self->f34c * 4);
		if (self->f65e == 1) {
			self->p120->f22 = 0;
			self->p120->f26 = 0;
			self->p124->f26 = 0;
			self->f65e = 0;
		}
		fn_80458880(lbl_8053AF80, 0x26, -1);
	}
	if (self->f34c > 0 && key == *((u8*)t->prev + self->f340 * 2 + self->f34c - 1)) {
		self->f34c--;
		self->f348 = *(s32*)((u8*)t->vals + self->f340 * 12 + self->f34c * 4);
		if (self->f65e == 1) {
			self->p120->f22 = 0;
			self->p120->f26 = 0;
			self->p124->f26 = 0;
			self->f65e = 0;
		}
		fn_80458880(lbl_8053AF80, 0x26, -1);
	}
}

extern u8 lbl_80543880[];
extern u8 lbl_80543888[];
extern u8 lbl_8048C90C[];
extern u8 lbl_8048C924[];
extern "C" void fn_80405D00(u8* self, s32 param) {
	s32 i;
	s32 count = 0;
	for (i = 0; i < 4; i++) {
		if (*(u32*)(self + 0x38c) & (1 << (*(s32*)(self + 0x340) * 4 + i))) {
			count++;
		}
	}
	if (count == 1) {
		return;
	}
	s32 state = *(s32*)(self + 0x340);
	if ((state == 0 || (u32)(state - 1) < 5 || state == 6) && !(*(u32*)(self + 0x38c) & (1 << (state * 4 + 1)))) {
		if (*(s32*)(self + 0x348) == 0) {
			if (lbl_80543880[state] == param) {
				*(s32*)(self + 0x348) = 2;
				*(s32*)(self + 0x34c) = *(s32*)(self + 0x348);
				if (self[0x65e] == 1) {
					*(s16*)(*(u8**)(self + 0x120) + 0x22) = 0;
					*(s16*)(*(u8**)(self + 0x120) + 0x26) = 0;
					*(s16*)(*(u8**)(self + 0x124) + 0x26) = 0;
					self[0x65e] = 0;
				}
				fn_80458880(lbl_8053AF80, 0x26, -1);
			}
		} else if (*(s32*)(self + 0x348) == 2) {
			if (lbl_80543888[state] == param) {
				*(s32*)(self + 0x348) = 0;
				*(s32*)(self + 0x34c) = *(s32*)(self + 0x348);
				if (self[0x65e] == 1) {
					*(s16*)(*(u8**)(self + 0x120) + 0x22) = 0;
					*(s16*)(*(u8**)(self + 0x120) + 0x26) = 0;
					*(s16*)(*(u8**)(self + 0x124) + 0x26) = 0;
					self[0x65e] = 0;
				}
				fn_80458880(lbl_8053AF80, 0x26, -1);
			}
		}
	} else {
		s32 idx = *(s32*)(self + 0x348);
		if (idx < count - 1 && (&lbl_8048C90C[state * 3])[idx] == param) {
			*(s32*)(self + 0x348) = idx + 1;
			*(s32*)(self + 0x34c) = *(s32*)(self + 0x348);
			if (self[0x65e] == 1) {
				*(s16*)(*(u8**)(self + 0x120) + 0x22) = 0;
				*(s16*)(*(u8**)(self + 0x120) + 0x26) = 0;
				*(s16*)(*(u8**)(self + 0x124) + 0x26) = 0;
				self[0x65e] = 0;
			}
			fn_80458880(lbl_8053AF80, 0x26, -1);
		}
		idx = *(s32*)(self + 0x348);
		if (idx > 0 && (&lbl_8048C924[*(s32*)(self + 0x340) * 3])[idx - 1] == param) {
			*(s32*)(self + 0x348) = idx - 1;
			*(s32*)(self + 0x34c) = *(s32*)(self + 0x348);
			if (self[0x65e] == 1) {
				*(s16*)(*(u8**)(self + 0x120) + 0x22) = 0;
				*(s16*)(*(u8**)(self + 0x120) + 0x26) = 0;
				*(s16*)(*(u8**)(self + 0x124) + 0x26) = 0;
				self[0x65e] = 0;
			}
			fn_80458880(lbl_8053AF80, 0x26, -1);
		}
	}
}

extern "C" void fn_80405FC0(u8* self) {
	f32 pos[3];
	f32 p2[3];
	f32 p3[3];
	u8* tbl = (u8*)&lbl_8048C1F8;
	f32 x1;
	f32 x2;
	f32 span;
	s32 w;
	w = *(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 4);
	x1 = *(f32*)getBounds__7J2DPaneFv((*(Screen408**)(self + 0x10))->search(0x506C693031ULL));
	x2 = *(f32*)getBounds__7J2DPaneFv((*(Screen408**)(self + 0x10))->search(0x506C693032ULL));
	span = 384.0f * (0.5f * (x2 - x1)) / (f32)w;
	getBounds__7J2DPaneFv((*(Screen408**)(self + 0x10))->search(0x506C693033ULL));
	getBounds__7J2DPaneFv((*(Screen408**)(self + 0x10))->search(0x506C693031ULL));

	u8* q = self;
	for (s32 i = 0; i < 4; i++) {
		u8* mode = *(u8**)(sManager__8JUTVideo + 4);
		pos[0] = (f32)*(s16*)(lbl_8050DB0C + 0x270) + 384.0f * *(f32*)(self + 0x394) / (f32)(s32)*(u16*)(mode + 4);
		pos[1] = *(f32*)(self + 0x39c) + ((f32)*(s16*)(lbl_8050DB0C + 0x272) + 288.0f * *(f32*)(self + 0x398) / (f32)(s32)*(u16*)(mode + 6));
		pos[2] = 0.0f;
		if (i % 2) {
			pos[0] = pos[0] + span;
		} else {
			pos[0] = pos[0] - span;
		}
		if (i < 2) {
			pos[1] = pos[1] + span;
		} else {
			pos[1] = pos[1] - span;
		}

		DrawRec rec;
		rec.ids[7] = i + 0xc;
		rec.b26 = 0;

		s32 st = *(s32*)(self + 0x350);
		if (st == 0x14 || st == 0x16) {
			s32 k = *(s16*)(self + 0x41e) / 2;
			if (k <= 0xd) {
				fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, ((Tu80406ResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, (char*)(tbl + 0xa24)), k + 0xdb, &rec, 1.0f, 1.0f);
				if (*(s16*)(self + 0x41e) == 0x1a) {
					if (*(void**)(q + 0x2cc) == 0) {
						p2[0] = 7.0f + pos[0];
						p2[1] = pos[1] - 27.0f;
						p2[2] = pos[2];
						*(void**)(q + 0x2cc) = fn_8013CC50(0, 1.0f, p2, 0xcb, 1, 0, 0, 0, 1);
						*(u32*)((u8*)*(void**)(q + 0x2cc) + 0xf4) |= 0x40;
					}
					if (*(void**)(q + 0x2dc) == 0) {
						p3[0] = 7.0f + pos[0];
						p3[1] = pos[1] - 27.0f;
						p3[2] = pos[2];
						*(void**)(q + 0x2dc) = fn_8013CC50(0, 1.0f, p3, 0xcc, 1, 0, 0, 0, 1);
						*(u32*)((u8*)*(void**)(q + 0x2dc) + 0xf4) |= 0x40;
					}
				}
			} else {
				fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, ((Tu80406ResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, (char*)(tbl + 0xa24)), 0xe8, &rec, 1.0f, 1.0f);
			}
		} else if (st == 0x2) {
			s32 idx = (*(s32*)(self + 0x358) / 5) % 4;
			s32* idTbl = (s32*)(tbl + 0xa14);
			fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, ((Tu80406ResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, (char*)(tbl + 0xa24)), idTbl[idx], &rec, 1.0f, 1.0f);
		} else if (st == 0x4) {
			((u8*)&rec)[0x13] = self[0x665];
			fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, ((Tu80406ResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, (char*)(tbl + 0xa24)), 0xe8, &rec, 1.0f, 1.0f);
		} else {
			if (*(s32*)(self + 0x358) >= 0x1e) {
				*(s32*)(self + 0x358) = 0;
				s32 id = *(s32*)(self + 0x360) + ((s32*)(tbl + 0x99c))[*(s32*)(self + 0x358)];
				fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, ((Tu80406ResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, (char*)(tbl + 0xa24)), id, &rec, 1.0f, 1.0f);
			}
		}
		q += 4;
	}
}

extern "C" BOOL fn_80404074(u8* self, s32 p, s32 a, s32* out);
extern "C" void* fn_8013CC50(void* mgr, f32 scale, f32* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u8 lbl_8048CC40[];
extern "C" void fn_804069E8(u8* self) {
	DrawRec rec;
	s32 out = -1;
	f32 mtx[3][4];
	f32 pos[3];
	f32 zero = 0.0f;
	s32 idx0 = *(s32*)(self + 0x340);
	s32 idx;
	if (idx0 == 10 && *(s32*)(self + 0x348) == 2) {
		idx = *(s32*)(lbl_80529DEC + 0x120);
	} else {
		idx = idx0;
	}
	f32 s = *(f32*)(lbl_8050DB0C + 8);
	f32 sx = sin(zero);
	f32 sy = sin(zero);
	f32 sz = sin(zero);
	f32 cx = cos(zero);
	f32 cy = cos(zero);
	f32 cz = cos(zero);
	mtx[0][3] = 0.0f;
	mtx[1][3] = 0.0f;
	mtx[2][3] = 0.0f;
	mtx[0][0] = s * (cy * cz);
	mtx[1][0] = s * (cy * sz);
	mtx[2][0] = s * -sy;
	mtx[0][1] = s * ((sx * sy) * cz - cx * sz);
	mtx[1][1] = s * ((sx * sy) * sz + cx * cz);
	mtx[2][1] = s * (sx * cy);
	mtx[0][2] = s * ((cx * cz) * sy + sx * sz);
	mtx[1][2] = s * ((cx * sz) * sy - sx * cz);
	mtx[2][2] = s * (cx * cy);
	rec.w18 = mtx;
	u8* q = self;
	for (int i = 0; i < 4; i++, q += 4) {
		if (fn_80404074(self, idx, i, &out)) {
			_GXRenderModeObj* mode = JUTVideo::getManager()->getRenderMode();
			pos[0] = lbl_8048C95C[idx * 8 + i * 2] * (384.0f / mode->fbWidth);
			pos[1] = lbl_8048C95C[idx * 8 + i * 2 + 1] * (288.0f / mode->efbHeight);
			pos[2] = 0.0f;
			GXSetTevDirect(GX_TEVSTAGE0);
			GXSetTevDirect(GX_TEVSTAGE1);
			GXSetTevDirect(GX_TEVSTAGE2);
			GXSetTevDirect(GX_TEVSTAGE3);
			rec.b26 = 0;
			rec.b1d = 1;
			rec.b1c = 1;
			((u8*)&rec.w10)[3] = (u8)(s32)(255.0f * *(f32*)(self + 0x400));
			if (i == out) {
				if (*(s32*)(self + 0x35c) == 10) {
					if (*(void**)(self + 0x2ec) == 0) {
						*(void**)(self + 0x2ec) = fn_8013CC50(0, 1.0f, pos, 0x7b, 1, 0, 0, 0, 1);
						(*(JPABaseEmitter**)(self + 0x2ec))->flags |= 0x40;
					}
					if (*(void**)(self + 0x2f0) == 0) {
						*(void**)(self + 0x2f0) = fn_8013CC50(0, 1.0f, pos, 0x7c, 1, 0, 0, 0, 1);
						(*(JPABaseEmitter**)(self + 0x2f0))->flags |= 0x40;
					}
					if (*(void**)(self + 0x2f4) == 0) {
						*(void**)(self + 0x2f4) = fn_8013CC50(0, 1.0f, pos, 0x7d, 1, 0, 0, 0, 1);
						(*(JPABaseEmitter**)(self + 0x2f4))->flags |= 0x40;
					}
					if (*(void**)(q + 0x2f8)) {
						JPABaseEmitter* e = *(JPABaseEmitter**)(q + 0x2f8);
						e->flags |= 1;
						*(s32*)((u8*)e + 0x24) = 1;
						*(void**)(q + 0x2f8) = 0;
					}
				}
				if (*(s32*)(self + 0x35c) <= 10) {
					Tu80406ResMgr* mgr = *(Tu80406ResMgr**)(lbl_8053AAF8 + 0xa4);
					fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, mgr->get('SOB ', (const char*)lbl_8048CC40), 0x25b, &rec, 1.0f, 1.0f);
				}
			} else {
				Tu80406ResMgr* mgr = *(Tu80406ResMgr**)(lbl_8053AAF8 + 0xa4);
				fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, mgr->get('SOB ', (const char*)lbl_8048CC40), 0x25a, &rec, 1.0f, 1.0f);
			}
		}
	}
}

extern "C" void fn_8013B414(void* obj, f32* box, s32 flag);
extern "C" void fn_802F86CC(void* obj, f32* pos, void* res, s32 id, DrawRec* rec, f32 sx, f32 sy);
extern "C" s32 lbl_8048CB58[];
extern "C" u8 lbl_8048CC2C[];
extern u8* lbl_8053AAF8;
extern "C" void fn_80406F68(u8* self, f32 a, f32 b) {
	s32 st = *(s32*)(self + 0x380);
	s32 seg = (st % 40) / 10;
	f32 box[4];
	DrawRec rec;
	f32 vec[3];
	f32 pos[3];

	box[0] = 0.0f;
	box[1] = 0.0f;
	box[2] = 256.0f;
	box[3] = 192.0f;
	fn_8013B414(lbl_8053AB10, box, 1);
	_GXRenderModeObj* mode = JUTVideo::getManager()->getRenderMode();
	pos[0] = a * (256.0f / mode->fbWidth);
	pos[1] = b * (192.0f / mode->efbHeight) - 5.0f;
	pos[2] = 0.0f;

	GXSetTevDirect(GX_TEVSTAGE0);
	GXSetTevDirect(GX_TEVSTAGE1);
	GXSetTevDirect(GX_TEVSTAGE2);
	GXSetTevDirect(GX_TEVSTAGE3);

	vec[0] = pos[0];
	vec[1] = pos[1] + JMath::sincosTable_.sinShort((s16)(st << 11));
	vec[2] = 0.0f;
	rec.ids[2] = 2;
	Tu80406ResMgr* mgr = *(Tu80406ResMgr**)(lbl_8053AAF8 + 0xa4);
	fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), vec, mgr->get('SOB ', (const char*)lbl_8048CC2C), 0xc6, &rec, 1.0f, 1.0f);

	pos[0] -= 16.0f;
	pos[1] += 3.0f;
	rec.ids[2] = 3;
	s32 id = lbl_8048CB58[seg] + 0xc0;
	mgr = *(Tu80406ResMgr**)(lbl_8053AAF8 + 0xa4);
	fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, mgr->get('SOB ', (const char*)lbl_8048CC2C), id, &rec, 1.0f, 1.0f);

	pos[0] += 32.0f;
	rec.ids[2] = 4;
	id = lbl_8048CB58[seg] + 0xc3;
	mgr = *(Tu80406ResMgr**)(lbl_8053AAF8 + 0xa4);
	fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, mgr->get('SOB ', (const char*)lbl_8048CC2C), id, &rec, 1.0f, 1.0f);
}

extern "C" u32 lbl_8048C2B8[];
extern "C" f32 lbl_805438F8;
extern "C" f32 lbl_805438FC;
extern "C" f32 lbl_80543898;
extern "C" f32 lbl_80543900;
extern "C" f32 lbl_805438D8;
extern "C" f32 lbl_805438DC;
extern "C" f32 lbl_80543904;
#pragma peephole off
extern "C" void fn_80408114(u8* self) {
    s32 i;
    u8* obj;
    if (*(s32*)(self + 0x350) == 0xb || *(s32*)(self + 0x350) == 0xc || *(s32*)(self + 0x350) == 0xd) {
        for (i = 0; i < 8; i++) {
            f32 f;
            if (i == *(s32*)(self + 0x340)) {
                *(s16*)(self + 0x40e + i * 2) = *(s16*)(self + 0x40e + i * 2) + 1;
                if (*(s16*)(self + 0x40e + i * 2) < 15) {
                    f = lbl_805438F8 * ((f32)*(s16*)(self + 0x40e + i * 2) / lbl_805438FC);
                    if (f > lbl_80543900) {
                        f = lbl_80543900;
                    } else if (f < lbl_80543898) {
                        f = lbl_80543898;
                    }
                } else {
                    f32 t;
                    if (*(s16*)(self + 0x40e + i * 2) >= 0x73) {
                        *(s16*)(self + 0x40e + i * 2) = 15;
                    }
                    if (*(s16*)(self + 0x40e + i * 2) < 0x41) {
                        t = (f32)(*(s16*)(self + 0x40e + i * 2) - 15) / lbl_805438D8;
                    } else {
                        t = (f32)(100 - (*(s16*)(self + 0x40e + i * 2) - 15)) / lbl_805438D8;
                    }
                    f = lbl_80543904 * t + lbl_80543900;
                    if (f > lbl_805438DC) {
                        f = lbl_805438DC;
                    } else if (f < lbl_80543900) {
                        f = lbl_80543900;
                    }
                }
            } else if (i == *(s32*)(self + 0x344)) {
                if (*(s16*)(self + 0x40e + i * 2) >= 15) {
                    *(s16*)(self + 0x40e + i * 2) = 15;
                }
                if (*(s16*)(self + 0x40e + i * 2) > 0) {
                    *(s16*)(self + 0x40e + i * 2) = *(s16*)(self + 0x40e + i * 2) - 1;
                }
                f = lbl_805438F8 * ((f32)*(s16*)(self + 0x40e + i * 2) / lbl_805438FC);
                if (f > lbl_80543900) {
                    f = lbl_80543900;
                } else if (f < lbl_80543898) {
                    f = lbl_80543898;
                }
            } else {
                *(s16*)(self + 0x40e + i * 2) = 0;
                f = lbl_80543898;
            }
            obj = *(u8**)(self + 0xc);
            ((void (*)(void*, s32, u32, u32))(*(u32**)obj)[15])(obj, 0, lbl_8048C2B8[2 * i], lbl_8048C2B8[2 * i + 1]);
            ((void (*)(void*, s32))(*(u32**)obj)[9])(obj, (s32)f);
        }
    } else {
        *(s16*)(self + 0x40e) = 0;
        for (i = 0; i < 8; i++) {
            obj = *(u8**)(self + 0xc);
            ((void (*)(void*, s32, u32, u32))(*(u32**)obj)[15])(obj, 0, lbl_8048C2B8[2 * i], lbl_8048C2B8[2 * i + 1]);
            ((void (*)(void*, s32))(*(u32**)obj)[9])(obj, 0);
        }
    }
}
#pragma peephole reset
extern "C" void fn_804083D8(u8* self) {
	u8* p = self;
	u32 bx0, ax0, bz0, az0, by0, ay0;
	u32 bx1, ax1, bz1, az1, by1, ay1;
	f32 t;
	f32 yX;
	f32 yY;
	f32 sx = (*(PaneRef**)(self + 0x28))->w / 72.0f;
	f32 sy = (*(PaneRef**)(self + 0x28))->h / 36.0f;
	*(s16*)(self + 0x42e) = 30;
	for (int i = 0; i < 8; i++, p += 0x14) {
		if (i == *(s32*)(self + 0x340)) {
			fn_80402CE0(*(PaneRef**)(p + 0x28), 1.0f / sx, 1.0f / sy);
			((void (*)(void*, f32, f32))(*(u32*)(*(u32*)(*(PaneRef**)(p + 0x2c))->pane + 0x18)))((*(PaneRef**)(p + 0x2c))->pane, 72.0f, 36.0f);
			t = *(f32*)((u8*)getBounds__7J2DPaneFv((*(PaneRef**)(p + 0x28))->pane) + 4);
			yX = (*(PaneRef**)(p + 0x28))->y;
			yY = (*(PaneRef**)(p + 0x30))->y;
			f32 dx = (*(PaneRef**)(p + 0x28))->x - *(f32*)getBounds__7J2DPaneFv((*(PaneRef**)(p + 0x28))->pane);
			((void (*)(void*, f32, f32))(*(u32*)(*(u32*)(*(PaneRef**)(p + 0x30))->pane + 0x10)))((*(PaneRef**)(p + 0x30))->pane, (*(PaneRef**)(p + 0x30))->x + dx, yY + (yX - t));
			ax0 = *(u32*)(self + 0x31c);
			bx0 = *(u32*)(self + 0x334);
			((void (*)(void*, u32*, u32*))(*(u32*)(*(u32*)(*(PaneRef**)(p + 0x28))->pane + 0x130)))((*(PaneRef**)(p + 0x28))->pane, &bx0, &ax0);
			az0 = *(u32*)(self + 0x320);
			bz0 = *(u32*)(self + 0x338);
			((void (*)(void*, u32*, u32*))(*(u32*)(*(u32*)(*(PaneRef**)(p + 0x2c))->pane + 0x130)))((*(PaneRef**)(p + 0x2c))->pane, &bz0, &az0);
			ay0 = *(u32*)(self + 0x324);
			by0 = *(u32*)(self + 0x33c);
			((void (*)(void*, u32*, u32*))(*(u32*)(*(u32*)(*(PaneRef**)(p + 0x30))->pane + 0xac)))((*(PaneRef**)(p + 0x30))->pane, &by0, &ay0);
		} else {
			fn_80402CE0(*(PaneRef**)(p + 0x28), 1.0f, 1.0f);
			((void (*)(void*, f32, f32))(*(u32*)(*(u32*)(*(PaneRef**)(p + 0x2c))->pane + 0x18)))((*(PaneRef**)(p + 0x2c))->pane, (*(PaneRef**)(p + 0x2c))->w, (*(PaneRef**)(p + 0x2c))->h);
			((void (*)(void*, f32, f32))(*(u32*)(*(u32*)(*(PaneRef**)(p + 0x30))->pane + 0x10)))((*(PaneRef**)(p + 0x30))->pane, (*(PaneRef**)(p + 0x30))->x, (*(PaneRef**)(p + 0x30))->y);
			ax1 = *(u32*)(self + 0x310);
			bx1 = *(u32*)(self + 0x328);
			((void (*)(void*, u32*, u32*))(*(u32*)(*(u32*)(*(PaneRef**)(p + 0x28))->pane + 0x130)))((*(PaneRef**)(p + 0x28))->pane, &bx1, &ax1);
			az1 = *(u32*)(self + 0x314);
			bz1 = *(u32*)(self + 0x32c);
			((void (*)(void*, u32*, u32*))(*(u32*)(*(u32*)(*(PaneRef**)(p + 0x2c))->pane + 0x130)))((*(PaneRef**)(p + 0x2c))->pane, &bz1, &az1);
			ay1 = *(u32*)(self + 0x318);
			by1 = *(u32*)(self + 0x330);
			((void (*)(void*, u32*, u32*))(*(u32*)(*(u32*)(*(PaneRef**)(p + 0x30))->pane + 0xac)))((*(PaneRef**)(p + 0x30))->pane, &by1, &ay1);
		}
	}
	if (*(s32*)(self + 0x340) < 8) {
		for (int j = 0; j < 8; j++) {
			if (j != *(s32*)(self + 0x340)) {
				appendChild__7J2DPaneFP7J2DPane((*(Screen408**)(self + 0x10))->search(0x004E646174613031ULL), (*(PaneRef**)(self + 0x28 + j * 0x14))->pane);
			}
		}
		appendChild__7J2DPaneFP7J2DPane((*(Screen408**)(self + 0x10))->search(0x004E646174613031ULL), (*(PaneRef**)(self + 0x28 + *(s32*)(self + 0x340) * 0x14))->pane);
	}
}

extern "C" void fn_8040873C(u8* self, void* p2) {
	f32 scale = lbl_805438BC;
	s32 x = (s32)p2;
	s32 i;
	u32* e;
	u8* obj;
	u8* tbl = (u8*)&lbl_8048C1F8;
	if (*(s32*)(self + 0x340) == 7) {
		e = (u32*)(tbl + 0x3d8);
		for (i = 0; i < 9; i++) {
			obj = *(u8**)(self + 0x14);
			((void (*)(void*, s32, u32, u32))(*(void***)obj)[15])(obj, x, e[0], e[1]);
			x = (s32)((f32)self[0x642 + i] * scale);
			((void (*)(void*, s32))(*(void***)obj)[9])(obj, x);
			e += 2;
		}
		fn_80402E08(*(void**)(self + 0x120), lbl_80543898, lbl_80543898);
		for (i = 0; i < 2; i++) {
			u8* q = *(u8**)(self + 0x120 + i * 4);
			((void (*)(void*, s32))(*(void***)(*(u8**)(q + 4)))[9])(*(void**)(q + 4), q[0x28]);
		}
		self[0x65e] = 1;
	}
}

static inline bool checkRowBit(u32 idx, int p, int j) {
	if (p < 0 || p > 7) return false;
	if (j < 0 || j > 3) return false;
	return (*(u32*)((u8*)&lbl_8050EC80[idx] + 0x28) & (1 << (p * 4 + j))) != 0;
}

extern "C" BOOL fn_80404074(u8* self, s32 p, s32 a, s32* out) {
	int n = 0;
	int lim;
	for (int j = 0; j < 4; j++) {
		if (checkRowBit(lbl_8050EC80[0].selfIndex, p, j)) n++;
	}
	if (p == 7) {
		if (n <= 1) n--;
		lim = 1;
		if (*(s32*)(self + 0x388) != -1 && (*(s32*)(self + 0x350) == 6 || self[0x664] == 1)) {
			if (*(s32*)(self + 0x388) == 0) *out = 2;
			else if (*(s32*)(self + 0x388) == 1) *out = 3;
		}
	} else {
		if (n <= 2) n--;
		lim = 2;
		if (*(s32*)(self + 0x388) != -1 && (*(s32*)(self + 0x350) == 6 || self[0x664] == 1)) {
			if (*(s32*)(self + 0x388) == 0) *out = 1;
			else if (*(s32*)(self + 0x388) == 1) *out = 3;
		}
	}
	if (a == lim) return FALSE;
	if (a > n || a == *out) return TRUE;
	return FALSE;
}
