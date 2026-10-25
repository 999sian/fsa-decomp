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

extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" void fn_803B9160(void*);
extern "C" void* fn_803B94C4(void*, s16);
extern "C" void* fn_803B95D4(void*, s16);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern char lbl_8050EC60[];
extern char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern char __init__memPool___26JASPoolAllocObject_5JAISe;
extern char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern char memPool___30JASPoolAllocObject_9JAIStream[];
extern char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern char memPool___27JASPoolAllocObject_6JAISeq[];
extern char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void fn_803B961C(void) {
	u8* base = (u8*)lbl_8050EC60;
	s32 i = 0;
	u8* q;
	u8* p = base + 0x20;
	q = p;
	*(void**)p = lbl_804AFB30;
	*(u32*)(p + 0x10) = 0;
	*(u32*)(p + 0xc) = 0;
	*(u32*)(p + 0x8) = 0;
	do {
		u8* r = p + 0x20;
		memset(r, 0, 0xc8);
		memset(q + 0x280, 0, 0x9c4);
		i++;
		r[0x7c] = 1;
		r[0x79] = 0x32;
		p += 0xc8;
		*(u32*)(r + 0x8) |= 0x4;
		*(u32*)(r + 0x8) |= 0x40;
		*(u32*)(r + 0x8) |= 0x400;
		*(u32*)(r + 0x8) |= 0x4000;
		*(u32*)(r + 0x8) |= 0x40000;
		*(u32*)(r + 0x8) |= 0x400000;
		*(u32*)(r + 0x8) |= 0x4000000;
		*(u32*)(r + 0x8) |= 0x20000000;
		r[0x88] = 1;
		r[0x89] = 1;
		q += 0x9c4;
	} while (i < 3);
	__register_global_object(base + 0x20, (void*)fn_803B94C4, base);
	fn_803B9160(base + 0x200c);
	__register_global_object(base + 0x200c, (void*)fn_803B95D4, base + 0x2000);
	if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
		__ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
		__register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, (void*)__dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0x20e8);
		__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
	}
	if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
		__ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
		__register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, (void*)__dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0x20f4);
		__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
	}
	if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
		__ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
		__register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, (void*)__dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x2100);
		__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
	}
	if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
		__ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
		__register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, (void*)__dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x210c);
		__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
	}
	if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
		__ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
		__register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, (void*)__dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x2118);
		__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
	}
	if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
		__ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
		__register_global_object(memPool___30JASPoolAllocObject_9JAIStream, (void*)__dt__22JASMemPool_9JAIStreamFv, base + 0x2124);
		__init__memPool___30JASPoolAllocObject_9JAIStream = 1;
	}
	if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
		__ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
		__register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, (void*)__dt__27JASMemPool_13JAISoundChildFv, base + 0x2130);
		__init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
	}
	if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
		__ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
		__register_global_object(memPool___27JASPoolAllocObject_6JAISeq, (void*)__dt__19JASMemPool_6JAISeqFv, base + 0x213c);
		__init__memPool___27JASPoolAllocObject_6JAISeq = 1;
	}
	if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
		__ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
		__register_global_object(memPool___26JASPoolAllocObject_5JAISe, (void*)__dt__18JASMemPool_5JAISeFv, base + 0x2148);
		__init__memPool___26JASPoolAllocObject_5JAISe = 1;
	}
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
	return ((1 << (n * 4 + bit)) & *(u32*)((u8*)lbl_8050EC80 + *(s32*)((u8*)lbl_8050EC80 + 0x10) * 0xc8 + 0x28)) != 0;
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

#pragma peephole on
extern "C" u8 fn_803B90E4(s32 idx, s32 n) {
    if (n < 3) return 1;
    switch (*(u32*)((u8*)lbl_8050EC80 + idx * 0xc8 + 0x28) & 0x80000000) {
    default: return 1;
    case 0: return 0;
    }
}
#pragma peephole reset
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
