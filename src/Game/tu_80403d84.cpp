// TU 0x80403d84-0x80414f6c.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include "JSystem/JMath/JMath.h"

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

struct Pane408 {
	virtual void v08(); virtual void v0c();
	virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1c();
	virtual void v20();
	virtual void setAlpha(int a); // 0x24
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
	int n = 0;
	self->timer++;
	if (self->timer > 10) {
		if (self->timer == 0x16) {
			u32 id = 0x30039;
			self->sound->play(&id);
		}
		for (int i = 0; i < 3; i++) {
			if (self->emitters[i]) {
				if (self->emitters[i]->isEnd()) {
					killEmitter(&self->emitters[i]);
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

extern "C" void fn_80411A94(u8* self, f32 scale) {
	(*(Screen408**)(self + 0x10))->search(0x54746c763131ULL)->setAlpha((int)(self[0x64b] * scale));
	(*(Screen408**)(self + 0x10))->search(0x54746c763132ULL)->setAlpha((int)(self[0x64c] * scale));
	(*(Screen408**)(self + 0x10))->search(0x54746c763133ULL)->setAlpha((int)(self[0x64b] * (scale = 1.0f - scale)));
	(*(Screen408**)(self + 0x10))->search(0x54746c763134ULL)->setAlpha((int)(self[0x64c] * scale));
}

struct Tbl8048C1F8 {
	u8 pad[0x694];
	s32 vals[12][3];      // 0x694
	u8 pad724[0x744 - 0x724];
	u8 next[8][2];        // 0x744
	u8 prev[8][2];        // 0x754
};
extern Tbl8048C1F8 lbl_8048C1F8;

struct T5B10 {
	u8 pad[0x120];
	Obj240* p120;
	Obj240* p124;
	u8 pad128[0x340 - 0x128];
	s32 f340;
	u8 pad344[0x348 - 0x344];
	s32 f348;
	s32 f34c;
	u8 pad350[0x38c - 0x350];
	u32 f38c;
	u8 pad390[0x65e - 0x390];
	u8 f65e;
};

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

static inline int checkRowBit(u32 idx, int p, int j) {
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
