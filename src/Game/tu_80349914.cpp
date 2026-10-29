#define Vec SDKVec
#include "JSystem/JGeometry/Vec.h"
#undef Vec
#include "JSystem/JMath/JMath.h"
#include "Game/Actor.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"


extern "C" char lbl_804AC810[];
extern "C" u32 fn_801F856C(void);
extern "C" int fn_801F666C(u32 a, u32 b);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void* fn_8023E724(s32 i);
extern "C" s32 fn_8022E970(s32 i);
extern "C" s32 fn_8022CAF8(s32 i);
extern "C" f32 lbl_805424D0;
extern "C" f32 lbl_805424D4;
extern "C" void fn_80349914(u8* param_1, f32* param_2) {
	f32* pfVar2 = (f32*)fn_8023E724(*(s32*)(param_1 + 0x27c));
	param_2[0] = pfVar2[0];
	param_2[1] = pfVar2[1];
	param_2[2] = pfVar2[2];
	s32 iVar3 = fn_8022E970(*(s32*)(param_1 + 0x27c));
	s32 iVar4 = fn_8022CAF8(*(s32*)(param_1 + 0x27c));
	switch (iVar4) {
	case 0:
		if (iVar3 != 1 && iVar3 >= 1 && iVar3 < 5) {
			param_2[0] = lbl_805424D0 * (f32)(iVar3 - 1) + param_2[0];
		}
		break;
	case 1:
		if (iVar3 != 1 && iVar3 >= 1 && iVar3 < 5) {
			param_2[1] = lbl_805424D0 * (f32)(iVar3 - 1) + param_2[1];
		}
		break;
	case 2:
		switch (iVar3) {
		case 2:
			param_2[0] = param_2[0] + lbl_805424D0;
			break;
		case 3:
		case 4:
			param_2[0] = param_2[0] + lbl_805424D0;
			param_2[1] = param_2[1] + lbl_805424D0;
			break;
		}
		break;
	case 3:
		if (iVar3 != 1) {
			s32 iVar5 = *(s32*)(param_1 + 0x238);
			switch (iVar5) {
			case 0:
				param_2[1] = param_2[1] + lbl_805424D4;
				break;
			case 1:
				param_2[0] = param_2[0] + lbl_805424D4;
				break;
			case 2:
				param_2[0] = param_2[0] - lbl_805424D4;
				break;
			case 3:
				param_2[1] = param_2[1] - lbl_805424D4;
				break;
			}
		}
		break;
	case 5:
		break;
	}
}

extern "C" void fn_80349B14(void)
{
}

extern "C" s32 fn_8023DE58(s32 x);
extern "C" u8 fn_8022F514(s32 a);
extern "C" s32 fn_8022F3DC(s32 a);
extern "C" void fn_801F0E34(void* a, s32 code, s32 z);
extern "C" void fn_801EEC98(void* a, u32 b, u32 c, u32 d, u32 e, void* f, u32 g, u32 h);
extern "C" u8 fn_8023A51C(s32 i);
extern "C" s32 Actor_CreateByID(u32 mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" u8* lbl_8053AAF8;
extern "C" f32 lbl_805424E0;
extern "C" const f32 lbl_805424E8;
extern "C" const f32 lbl_805424EC;
static inline u8* fobeChild(u8* p, s32 i) {
	return (u8*)fn_801F666C(fn_801F856C(), *(u32*)(p + i * 4 + 0x240));
}
static inline f32 fobeRandom(u8* game, u32 multiplier) {
	union { u32 bits; f32 value; } r;
	u32* state = (u32*)(game + 0xb4);
	*state = *state * multiplier + 0x3c6ef35f;
	r.bits = (*state >> 9) | 0x3f800000;
	return r.value - lbl_805424EC;
}
extern "C" f32 lbl_805424E4;
extern "C" f32 lbl_805424F0;
extern "C" f32 lbl_805424F4;
extern "C" const f32 lbl_805424F8;
extern "C" f32 lbl_805424FC;
extern "C" f32 lbl_80542500;
extern "C" void fn_80349B18(u8* this_) {
	s32 i;

	if (*(s32*)(this_ + 0x230) != 0 && *(s32*)(this_ + 0x230) != 4) {
		*(s16*)(this_ + 0x280) += 0x222;
		if (*(s32*)(this_ + 0x238) >= 0 && fn_8023DE58(*(s32*)(this_ + 0x238)) >= 8) {
			this_[0x282] = 1;
		}
		if (*(s32*)(this_ + 0x238) < 0) {
			this_[0x282] = 1;
		}
		if (this_[0x282] == 0) {
			for (i = 0; i < 0xe; i++) {
				u8* h = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(this_ + i * 4 + 0x240));
				if (h != 0) {
					if (*(s32*)(this_ + 0x238) >= 0 && fn_8022F514(*(s32*)(this_ + 0x238)) == 1) {
						*(s32*)(this_ + 0x238) = fn_8022F3DC(*(s32*)(this_ + 0x238));
					}
					*(s32*)(h + 0x244) = *(s32*)(this_ + 0x238);
					if (*(s32*)(h + 0x230) != 4) {
						*(s16*)(h + 0x260) = *(s16*)(this_ + 0x280);
					}
				}
			}
			s32 zeros = 0;
			*(s32*)(this_ + 0x23c) = *(s32*)(this_ + 0x238);
			for (i = 0; i < 0xe; i++) {
				u8* h = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(this_ + i * 4 + 0x240));
				if (h == 0) {
					if (++zeros >= 5) {
						this_[0x282] = 1;
						break;
					}
				} else if (*(s32*)(h + 0x230) == 4) {
					this_[0x282] = 1;
					break;
				}
			}
		}
	}
	if (this_[0x282] == 1) {
		u8 allStopped = 1;
		for (i = 0; i < 0xe; i++) {
			u8* h = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(this_ + i * 4 + 0x240));
			if (h != 0) {
				*(s32*)(h + 0x230) = 4;
				JGeometry::TVec3f v(*(JGeometry::TVec3f*)(h + 0x3c));
				v *= lbl_805424E0;
				*(JGeometry::TVec3f*)(h + 0x3c) = v;
				if (h[0x264] == 0) {
					allStopped = 0;
				}
			}
		}
		*(s32*)(this_ + 0x230) = 4;
		if (allStopped == 1) {
			for (i = 0; i < 0xe; i++) {
				u8* h = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(this_ + i * 4 + 0x240));
				if (h != 0) {
					h[0x265] = 1;
				}
			}
		}
	}
	if (*(s32*)(this_ + 0x230) != 0) {
		fn_801F0E34(this_, 0x4007e, 0);
	}
	switch (*(s32*)(this_ + 0x230)) {
	case 0: {
		u8 found = 0;
		if (*(s32*)(this_ + 0x278) == 2) {
			if ((u8)((Actor*)this_)->v11() == 1) {
				found = 1;
				*(s32*)(this_ + 0x230) = 1;
			}
		} else {
			for (i = 0; i < 4; i++) {
				if (*(s32*)(this_ + 0x278) != 1 || fn_8023A51C(i)) {
					f32 dx = ((f32*)fn_8023E724(i))[0] - *(f32*)(this_ + 0xc);
					f32 dy = ((f32*)fn_8023E724(i))[1] - *(f32*)(this_ + 0x10);
					if (dx * dx + dy * dy < lbl_805424E4) {
						found = 1;
						break;
					}
				}
			}
		}
		if (found == 1) {
			fn_801EEC98(this_, *(u32*)(this_ + 0x198), 0, 0, 0, this_ + 0x238, 0, 0);
			if (*(s32*)(this_ + 0x238) >= 0) {
				*(s32*)(this_ + 0x230) = 1;
			}
		}
		if (*(s32*)(this_ + 0x230) == 1) {
			for (i = 0; i < 0xe; i++) {
				*(u32*)(this_ + i * 4 + 0x240) = Actor_CreateByID(fn_801F856C(), 0x464F4245, *(u32*)(this_ + 4), (f32*)(this_ + 0xc), 0, -1, -1);
				u8* h = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(this_ + i * 4 + 0x240));
				if (h != 0) {
					*(u32*)(h + 0x250) = *(u32*)(this_ + 0x198);
					*(s32*)(h + 0x254) = i;
				}
			}
		}
		break;
	}
	case 1: {
		u8 noneWaiting = 1;
		u8 allReady = 1;
		for (i = 0; i < 0xe; i++) {
			u8* h = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(this_ + i * 4 + 0x240));
			if (h != 0) {
				if (noneWaiting == 1 && *(s32*)(h + 0x230) == 1) {
					noneWaiting = 0;
				}
				if (*(s32*)(h + 0x230) != 2) {
					allReady = 0;
					break;
				}
			}
		}
		if (allReady == 1) {
			*(s32*)(this_ + 0x234) = (s32)(lbl_805424E8 * fobeRandom(lbl_8053AAF8, 0x19660d)) + 0xb4;
			*(s32*)(this_ + 0x230) = 2;
		} else if (noneWaiting == 1) {
			fn_801EEC98(this_, *(u32*)(this_ + 0x198), 0, 0, 0, this_ + 0x238, 0, 0);
			for (i = 0; i < 0xe; i++) {
				u8* h = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(this_ + i * 4 + 0x240));
				if (h != 0) {
					*(s32*)(h + 0x244) = *(s32*)(this_ + 0x238);
				}
			}
		}
		break;
	}
	case 2:
		if (*(s32*)(this_ + 0x234) <= 0) {
			f32 t = lbl_805424F0;
			for (i = 0; i < 0xe; i++) {
				u8* h = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(this_ + i * 4 + 0x240));
				if (h != 0) {
					*(f32*)(h + 0x25c) = t;
					*(s32*)(h + 0x230) = 3;
				}
			}
			*(s32*)(this_ + 0x230) = 3;
		}
		break;
	case 3: {
		u8 found = 0;
		for (i = 0; i < 0xe; i++) {
			u8* h = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(this_ + i * 4 + 0x240));
			if (h != 0 && *(s32*)(h + 0x230) == 2) {
				found = 1;
				*(s32*)(this_ + 0x234) = (s32)(lbl_805424E8 * fobeRandom(lbl_8053AAF8, 0x19660d)) + 0xb4;
				break;
			}
		}
		if (found == 1) {
			for (i = 0; i < 0xe; i++) {
				u8* h = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(this_ + i * 4 + 0x240));
				if (h != 0) {
					*(s32*)(h + 0x230) = 2;
				}
			}
			*(s32*)(this_ + 0x230) = 1;
		}
		break;
	}
	case 4: {
		u8 noneAlive = 1;
		u8 allDone = 1;
		for (i = 0; i < 0xe; i++) {
			u8* h = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(this_ + i * 4 + 0x240));
			if (h != 0) {
				noneAlive = 0;
				if (h[0x262] == 0) {
					if (*(s32*)(h + 0x230) != 4) {
						*(s32*)(h + 0x230) = 4;
					}
					allDone = 0;
				}
			}
		}
		if (noneAlive == 1 && *(s32*)(this_ + 0x27c) >= 0) {
			f32 pos[3];
			pos[0] = pos[1] = pos[2] = lbl_805424F4;
			fn_80349914(this_, pos);
			s16 ang = (s32)(lbl_805424F8 * fobeRandom(lbl_8053AAF8, 0x19660d));
			for (s32 k = 0; k < 14; k++) {
				s32 type = (k & 1) + 1;
				u32 id = Actor_CreateByID(fn_801F856C(), 0x52555059, *(u32*)(this_ + 4), pos, type | 0x1000000, -1, -1);
				u8* h = (u8*)fn_801F666C(fn_801F856C(), id);
				if (h != 0) {
					JGeometry::TVec3f vel;
					s16 a = ang + (k * 0x10000) / 14;
					vel.z = lbl_80542500;
					vel.x = lbl_805424FC * JMath::sincosTable_.mTable[(u16)a >> 5].first;
					vel.y = lbl_805424FC * JMath::sincosTable_.mTable[(u16)a >> 5].second;
					*(JGeometry::TVec3f*)(h + 0x3c) = vel;
				}
			}
		}
		if (allDone == 1) {
			for (i = 0; i < 0xe; i++) {
				u8* h = (u8*)fn_801F666C(fn_801F856C(), *(u32*)(this_ + i * 4 + 0x240));
				if (h != 0) {
					((Actor*)h)->detach();
				}
			}
			((Actor*)this_)->detach();
			return;
		}
		break;
	}
	}
	if (*(s32*)(this_ + 0x234) > 0) {
		(*(s32*)(this_ + 0x234))--;
	}
}

extern "C" void fn_8034A380(Actor* param_1)
{
    *(u32*)((u8*)param_1 + 0x230) = 0;
    *(u32*)((u8*)param_1 + 0x234) = 0;
    *(s32*)((u8*)param_1 + 0x238) = -1;
    *(s32*)((u8*)param_1 + 0x23c) = -1;
    *(u32*)((u8*)param_1 + 0x278) = param_1->field_90 & 0xF;
    *(u16*)((u8*)param_1 + 0x280) = 0;
    *(u8*)((u8*)param_1 + 0x282) = 0;
    *(s32*)((u8*)param_1 + 0x240) = -1;
    *(s32*)((u8*)param_1 + 0x244) = -1;
    *(s32*)((u8*)param_1 + 0x248) = -1;
    *(s32*)((u8*)param_1 + 0x24c) = -1;
    *(s32*)((u8*)param_1 + 0x250) = -1;
    *(s32*)((u8*)param_1 + 0x254) = -1;
    *(s32*)((u8*)param_1 + 0x258) = -1;
    *(s32*)((u8*)param_1 + 0x25c) = -1;
    *(s32*)((u8*)param_1 + 0x260) = -1;
    *(s32*)((u8*)param_1 + 0x264) = -1;
    *(s32*)((u8*)param_1 + 0x268) = -1;
    *(s32*)((u8*)param_1 + 0x26c) = -1;
    *(s32*)((u8*)param_1 + 0x270) = -1;
    *(s32*)((u8*)param_1 + 0x274) = -1;
}

extern "C" Actor* fn_8034A3E8(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        u32* slot = (u32*)param_1;
        s32 i = 0;
        *(void**)param_1 = lbl_804AC810;
        do {
            u32 r = fn_801F856C();
            u32 h = fn_801F666C(r, slot[0x90]);
            if (h != 0) {
                ((Actor*)h)->detach();
            }
            i++;
            slot++;
        } while (i < 0xe);
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8034A48C(void) {
}

