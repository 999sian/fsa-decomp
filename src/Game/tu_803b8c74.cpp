// TU 0x803b8c74-0x803b9940.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include <string.h>

// ---- from src/Game/fn_803B94C4_dtor.cpp ----
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AFB30[];

extern "C" void* fn_803B94C4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AFB30;
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_803B95D4_dtor.cpp ----
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AFB3C[];

extern "C" void* fn_803B95D4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AFB3C;
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/Table_SetSelfIndexedByte86.cpp ----
// fn_803B8C74(val) / fn_803B8C90() - setter/getter for a byte field at
// +0x86 in a global table (lbl_8050EC80, stride 0xc8), indexed by a
// value read from the table's own +0x10 word (row 0's self-index, not
// an incoming argument).
//
// Retry using real typed-array `[]` syntax (per zeldaret/tww's idiom
// for indexed table access) instead of the manual char*+idx*stride
// arithmetic that failed here previously - see project_fsa_phase4_kickoff.md,
// eighteenth batch, for the confirmed root cause (MWCC's indexed-vs-
// base+immediate addressing choice depends on how the address is
// expressed in source, not the underlying computation).
struct EC80Row {
	u8 pad0[0x10];
	u32 selfIndex; // 0x10
	u8 pad1[0x28 - 0x14];
	u32 flags28; // 0x28
	u8 pad1b[0x86 - 0x2c];
	u8 field86; // 0x86
	u8 pad2[0xc8 - 0x87];
};

extern EC80Row lbl_8050EC80[16];

static inline BOOL EC80NibbleBit(s32 idx, s32 n, u32 bit) {
	if (n < 0 || n > 7) {
		return FALSE;
	}
	return (lbl_8050EC80[idx].flags28 & (1 << (n * 4 + bit))) != 0;
}

static inline BOOL EC80NibbleBitCur(s32 n, u32 bit) {
	if (n < 0 || n > 7) {
		return FALSE;
	}
	return (*(u32*)((u8*)lbl_8050EC80 + *(s32*)((u8*)lbl_8050EC80 + 0x10) * 0xc8 + 0x28) & (1 << (n * 4 + bit))) != 0;
}

extern "C" {

void fn_803B8C74(u8 val) {
	u32 idx = lbl_8050EC80[0].selfIndex;
	lbl_8050EC80[idx].field86 = val;
}

u8 fn_803B8C90(void) {
	u32 idx = lbl_8050EC80[0].selfIndex;
	return lbl_8050EC80[idx].field86;
}

BOOL fn_803B8CAC(s32 idx, s32 n) {
	if (n == 7) {
		if (EC80NibbleBit(idx, n, 0) && EC80NibbleBit(idx, n, 2) && EC80NibbleBit(idx, n, 3)) {
			return TRUE;
		}
	} else {
		if (EC80NibbleBit(idx, n, 0) && EC80NibbleBit(idx, n, 1) && EC80NibbleBit(idx, n, 3)) {
			return TRUE;
		}
	}
	return FALSE;
}

extern "C" BOOL fn_803B8EBC(s32 n) {
	if (n == 7) {
		if (EC80NibbleBitCur(n, 0) && EC80NibbleBitCur(n, 2) && EC80NibbleBitCur(n, 3)) {
			return TRUE;
		}
	} else {
		if (EC80NibbleBitCur(n, 0) && EC80NibbleBitCur(n, 1) && EC80NibbleBitCur(n, 3)) {
			return TRUE;
		}
	}
	return FALSE;
}

BOOL fn_803B90E4(s32 idx, s32 n) {
	if (n < 3) {
		return TRUE;
	}
	EC80Row* r = &lbl_8050EC80[idx];
	u32 f = r->flags28;
	if ((s32)f < 0) {
		return TRUE;
	}
	return FALSE;
}

BOOL fn_803B9120(s32 n) {
	if (n < 3) {
		return TRUE;
	}
	u32 idx = lbl_8050EC80[0].selfIndex;
	u32 f = lbl_8050EC80[idx].flags28;
	if (!(f & 0x80000000)) {
		return FALSE;
	}
	return TRUE;
}

extern u32 lbl_80476548[];
extern "C" void fn_803B9160(void* this_) {
	u8* self = (u8*)this_;
	u32* t = lbl_80476548;
	u32* d1 = (u32*)(self + 0x4c);
	u32* d2 = (u32*)(self + 0x6c);
	u32 off = 0;
	s32 k = 0;
	s32 i;

	*(void**)this_ = lbl_804AFB3C;
	for (i = 0; i < 2; i++) {
		u8* p = self + off;
		p[4] = 0; p[0x94] = 0; p[5] = 0; p[0x95] = 0; p[6] = 0; p[0x96] = 0; p[7] = 0; p[0x97] = 0;
		p[8] = 0; p[0x98] = 0; p[9] = 0; p[0x99] = 0; p[0xa] = 0; p[0x9a] = 0; p[0xb] = 0; p[0x9b] = 0;
		off += 8;
		p = self + off;
		p[4] = 0; p[0x94] = 0; p[5] = 0; p[0x95] = 0; p[6] = 0; p[0x96] = 0; p[7] = 0; p[0x97] = 0;
		p[8] = 0; p[0x98] = 0; p[9] = 0; p[0x99] = 0; p[0xa] = 0; p[0x9a] = 0; p[0xb] = 0; p[0x9b] = 0;
		off += 8;
	}
	for (i = 0; i < 2; i++) {
		u8* q = self + k;
		q[0x24] = 0; q[0xb4] = 0; q[0x2d] = 0; q[0xbd] = 0; q[0x35] = 0; q[0xc5] = 0; q[0x3d] = 0; q[0xcd] = 0;
		d1[0] = t[0];
		d2[0] = t[0];
		k++;
		q = self + k;
		q[0x24] = 0; q[0xb4] = 0; q[0x2d] = 0; q[0xbd] = 0; q[0x35] = 0; q[0xc5] = 0; q[0x3d] = 0; q[0xcd] = 0;
		d1[1] = t[1];
		d2[1] = t[1];
		k++;
		q = self + k;
		q[0x24] = 0; q[0xb4] = 0; q[0x2d] = 0; q[0xbd] = 0; q[0x35] = 0; q[0xc5] = 0; q[0x3d] = 0; q[0xcd] = 0;
		d1[2] = t[2];
		d2[2] = t[2];
		k++;
		q = self + k;
		q[0x24] = 0; q[0xb4] = 0; q[0x2d] = 0; q[0xbd] = 0; q[0x35] = 0; q[0xc5] = 0; q[0x3d] = 0; q[0xcd] = 0;
		d1[3] = t[3];
		d2[3] = t[3];
		k++;
		d1 += 4;
		d2 += 4;
		t += 4;
	}
	self[0x45] = 0;
	self[0xd5] = 0;
	self[0x46] = 0;
	self[0xd6] = 0;
	*(u32*)(self + 0x8c) = 0;
	*(u32*)(self + 0x90) = 0;
	self[0x2c] = 0;
	self[0xbc] = 0;
	self[0x47] = 0;
	self[0xd7] = 0;
	self[0x48] = 0;
	self[0xd8] = 0;
}

}

struct SaveSlot {
	u8 pad0[0x8];
	u32 flags; // 0x8
	u8 pad1[0x59 - 0xc];
	u8 m59;
	u8 pad2[0x5c - 0x5a];
	u8 m5c;
	u8 pad3[0x68 - 0x5d];
	u8 m68;
	u8 m69;
	u8 pad4[0xc8 - 0x6a];
};

struct SaveBig {
	u8 data[0x9c4];
};

static inline void setDefaults(SaveSlot* slot) {
	slot->m5c = 1;
	slot->m59 = 50;
	slot->flags |= 0x4;
	slot->flags |= 0x40;
	slot->flags |= 0x400;
	slot->flags |= 0x4000;
	slot->flags |= 0x40000;
	slot->flags |= 0x400000;
	slot->flags |= 0x4000000;
	slot->flags |= 0x20000000;
	slot->m68 = 1;
	slot->m69 = 1;
}

static inline void initSlot(SaveSlot* slot) {
	memset(slot, 0, sizeof(SaveSlot));
	setDefaults(slot);
}

static inline void initSlot(SaveSlot* slot, SaveBig* big) {
	memset(slot, 0, sizeof(SaveSlot));
	memset(big, 0, sizeof(SaveBig));
	setDefaults(slot);
}

static inline void resetSlot(SaveSlot* dst) {
	SaveSlot tmp;
	initSlot(&tmp);
	memcpy(dst, &tmp, sizeof(SaveSlot));
}

static inline void resetSlot(SaveSlot* dst, SaveBig* bdst) {
	SaveSlot tmp;
	SaveBig big;
	initSlot(&tmp, &big);
	memcpy(dst, &tmp, sizeof(SaveSlot));
	memcpy(bdst, &big, sizeof(SaveBig));
}

extern "C" {

s32 fn_803B933C(void* unused, SaveSlot* slots, s32 idx) {
	SaveSlot* dst = &slots[idx];
	SaveSlot tmp;
	initSlot(&tmp);
	memcpy(dst, &tmp, sizeof(SaveSlot));
	return 0;
}

s32 fn_803B93E8(void* unused, SaveSlot* slots, SaveBig* bigs, s32 idx) {
	SaveSlot* dst = &slots[idx];
	SaveBig* bdst = &bigs[idx];
	resetSlot(dst, bdst);
	return 0;
}

void fn_803B950C(SaveSlot* slot, SaveBig* big) {
	initSlot(slot, big);
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
