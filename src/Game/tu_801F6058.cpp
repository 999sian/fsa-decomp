// TU 0x801f6058-0x801f68e0.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Registry_GetSlotValueOrFallback_801F6644.cpp ----
// Registry_GetSlotValueOrFallback(registry, idx) - reads the record pointer at
// registry->recordArray[idx] (offset 0x8). If that record's own +0x4
// field is 0, returns a per-index value from a parallel array at
// registry+0x100c; otherwise returns a single shared fallback value at
// registry+0x200c. A "per-slot value with shared default" accessor.
extern "C" u32 Registry_GetSlotValueOrFallback(void* registry, s32 idx) {
	void** recordArray = (void**)((char*)registry + 0x8);
	void* record = recordArray[idx];
	if (*(s32*)((char*)record + 0x4) == 0) {
		u32* perIndexArray = (u32*)((char*)registry + 0x100c);
		return perIndexArray[idx];
	} else {
		return *(u32*)((char*)registry + 0x200c);
	}
}

// ---- ClassifyBamAngleToQuadrant_801F681C.cpp ----
// ClassifyBamAngleToQuadrant(angle) - classifies a 16-bit BAM angle (this project's
// standard binary-angle-measurement format, full circle = 0x10000)
// into a coarse 4-way facing-direction bucket by comparing it against
// the four 45-degree-offset boundaries (0x2000/0x6000/0xA000/0xE000).
// Used by fn_801EEC98 to reduce the winning target player's precise
// angle down to a simple direction bucket for its output.
//
// The middle check (`check2`) re-tests `angle < 0x2000` even though
// that's already known false from the first check above - a genuinely
// redundant comparison preserved honestly here because it's what
// retail's own bytes do (matches the project's real-decompilation
// mandate: preserve, don't silently "fix", a provably redundant
// retail check).
extern "C" s32 ClassifyBamAngleToQuadrant(s32 param) {
	u16 angle = (u16)param;
	s32 result = 1;
	if (angle < 0x2000) goto quad2;
	if (angle < 0xe000) goto check2;
quad2:
	result = 2;
	goto tail;
check2:
	if (angle < 0x2000) goto check3;
	if (angle >= 0x6000) goto check3;
	result = 0;
	goto tail;
check3:
	angle = (u16)param;
	if (angle < 0x6000) goto tail;
	if (angle > 0xa000) goto tail;
	result = 3;
tail:
	return result;
}

extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 owner, void* pos, u32 param, s32 a, s32 b);
extern "C" char* fn_802D6A9C(void);
extern "C" void fn_80230224(s32 idx, s32 on);
extern "C" void fn_8037AE30(void* obj);
extern void* lbl_8053AD70;
extern void* lbl_8053AAF8;
extern const u16 lbl_8053F800[4];

extern "C" u32 fn_801F6058(char* this_, s32 idx) {
	return ((u32*)(this_ + 0x3030))[idx];
}

extern "C" void fn_801F6204(char* this_, u8 v) {
	*(u8*)(this_ + 0x305c) = v;
}

extern "C" u32 fn_801F620C(char* this_, u32 a, u32 b) {
	s32 n = *(s32*)(this_ + 0x3044);
	u32 r = 0;
	u32* p = *(u32**)(this_ + 0x3054);
	s32 i;
	for (i = 0; i < n; i++) {
		if (b == p[i]) {
			break;
		}
	}
	if (i < n) {
		s32 m = *(s32*)(this_ + 0x3048);
		u32* q = *(u32**)(this_ + 0x304c);
		s32 j;
		for (j = 0; j < m; j++) {
			if (a == q[j]) {
				r = (*(u32**)(this_ + 0x3058))[i + j * n];
				break;
			}
		}
		if (j == m) {
			r = (*(u32**)(this_ + 0x3058))[i];
		}
	}
	return r;
}

struct ActorReg {
	u8 pad0[8];
	char* actors[(0x1008 - 8) / 4];
	s32 count; // 0x1008
	u8 pad100c[0x2014 - 0x100c];
	s32 cur; // 0x2014
};

extern "C" void* fn_801F666C(ActorReg* reg, s32 id) {
	void* r = 0;
	char* a;
	s32 i;
	if (id >= 0) {
		if (reg->cur >= 0) {
			a = reg->actors[reg->cur];
			if (a != 0 && *(u8*)(a + 0x11c) != 0 && id == *(s32*)(a + 0x198)) {
				r = a;
				goto end;
			}
		}
		for (i = 0; i < reg->count; i++) {
			a = reg->actors[i];
			if (a != 0 && *(u8*)(a + 0x11c) != 0 && id == *(s32*)(a + 0x198)) {
				r = reg->actors[i];
				break;
			}
		}
	}
end:
	return r;
}

extern "C" s32 fn_801F6718(void* mgr, u8 b, s32 owner, void* pos, u16 f, u8 g) {
	return Actor_CreateByID(mgr, 0x53435245, owner, pos, f | (b << 16) | (g << 24), -1, -1);
}

extern "C" BOOL fn_801F6758(f32* pos, s32 idx, f32 margin) {
	char* base = fn_802D6A9C();
	f32* r;
	if (idx < 8) {
		r = (f32*)(base + 0xcc);
	} else {
		r = (f32*)(base + 0xdc);
	}
	if (pos[0] <= r[0] - margin || pos[0] >= r[2] + margin ||
	    pos[1] <= r[1] - margin || pos[1] >= r[3] + margin) {
		return TRUE;
	}
	return FALSE;
}

extern "C" u16 fn_801F6874(u8 dir) {
	return lbl_8053F800[dir & 3];
}

extern "C" void fn_801F6884(char* this_) {
	for (s32 i = 0; i < 4; i++) {
		fn_80230224(i, 0);
	}
	*(u8*)(this_ + 0x3041) = 0;
	fn_8037AE30(lbl_8053AD70);
}

extern "C" s32 fn_80236228(s32 idx);

struct Rank {
	u8 pad[0x3020];
	s32 score[4]; // 0x3020
	s32 order[4]; // 0x3030
};

extern "C" void fn_801F6068(Rank* this_) {
	s32 n = 0;
	s32 i; s32 best; s32 j;
	for (i = 0; i < 4; i++) {
		if (*((u8*)lbl_8053AAF8 + 0x82) & (u8)(1 << i)) {
			this_->score[i] = fn_80236228(i);
			n++;
			this_->order[i] = i;
		} else {
			this_->score[i] = -9999;
			this_->order[i] = 3;
		}
	}
	for (i = 0; i < n - 1; i++) {
		best = i;
		s32 v = this_->score[i];
		for (j = i + 1; j < n; j++) {
			if (v < this_->score[j]) {
				this_->score[best] = this_->score[j];
				this_->score[j] = v;
				v = this_->score[best];
				s32 t = this_->order[j];
				this_->order[j] = this_->order[best];
				this_->order[best] = t;
				best = j;
			}
		}
	}
	if (n < 4) {
		s32 ls = this_->score[n - 1];
		s32 lo = this_->order[n - 1];
		for (i = n; i < 4; i++) {
			this_->score[i] = ls;
			this_->order[i] = lo;
		}
	}
}
