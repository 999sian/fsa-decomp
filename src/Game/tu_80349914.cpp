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
extern "C" f32 lbl_805424E8;
extern "C" f32 lbl_805424EC;
extern "C" void fn_80349B18(Actor* param_1) {
	u8* this_ = (u8*)param_1;
	s32 i;
	s32 h;
	u32 slot;
	s32 zeros;
	if (*(s32*)(this_ + 0x230) == 0 || *(s32*)(this_ + 0x230) == 4) {
		return;
	}
	*(s16*)(this_ + 0x280) += 0x222;
	s32 idx = *(s32*)(this_ + 0x238);
	if (idx < 0 || fn_8023DE58(idx) >= 8) {
		this_[0x282] = 1;
	}
	if (this_[0x282] != 0) {
		return;
	}
	i = 0;
	slot = (u32)(this_ + 0x240);
	do {
		h = fn_801F666C(fn_801F856C(), *(s32*)slot);
		if (h != 0) {
			if (*(s32*)(this_ + 0x238) >= 0 && fn_8022F514(*(s32*)(this_ + 0x238)) == 1) {
				*(s32*)(this_ + 0x238) = fn_8022F3DC(*(s32*)(this_ + 0x238));
			}
			*(s32*)(h + 0x244) = *(s32*)(this_ + 0x238);
			if (*(s32*)(h + 0x230) != 4) {
				*(s16*)(h + 0x260) = *(s16*)(this_ + 0x280);
			}
		}
		i++;
		slot += 4;
	} while (i < 0xe);
	*(s32*)(this_ + 0x23c) = *(s32*)(this_ + 0x238);

	zeros = 0;
	slot = (u32)(this_ + 0x240);
	for (i = 0; i < 0xe; i++, slot += 4) {
		h = fn_801F666C(fn_801F856C(), *(s32*)slot);
		if (h == 0) {
			zeros++;
			if (zeros >= 5) {
				this_[0x282] = 1;
				return;
			}
		} else if (*(s32*)(h + 0x230) == 4) {
			this_[0x282] = 1;
			return;
		}
	}

	if (*(s32*)(this_ + 0x230) != 0) {
		fn_801F0E34(this_, 0x4007e, 0);
	}
	switch (*(s32*)(this_ + 0x230)) {
	case 0:
		if (*(s32*)(this_ + 0x278) == 2 && ((Actor*)param_1)->v11()) {
			*(s32*)(this_ + 0x230) = 1;
		}
		break;
	case 1:
		fn_801EEC98(this_, *(u32*)(this_ + 0x198), 0, 0, 0, this_ + 0x238, 0, 0);
		if (*(s32*)(this_ + 0x238) >= 0) {
			*(s32*)(this_ + 0x230) = 1;
		}
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
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

