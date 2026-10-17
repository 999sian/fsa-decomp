#include "Game/Actor.h"


extern "C" char lbl_804A8470[];
extern "C" void __dt__5ActorFv(Actor*, s32);
struct SlotVirt6 {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual u32 v06(u32 a, char* b);
};
struct Init48 {
    u8 idx[0x10];
    s32 w18;
    s32 w1c;
    s32 w20;
    s8 b24[0xb];
    s32 w30;
    u8 b34[3];
    s32 w38;
    s32 w3c;
    s32 w40;
};
extern char* lbl_8053AAF8;
extern char* lbl_8053AB10;
extern char lbl_8046CA68[];
extern f32 lbl_80540970;
extern "C" void fn_802F86CC(u32, char*, u32, s32, f32, f32, void*);
extern "C" void fn_80307AC8(s32, s32, char*, s32, s32, s32, s32);
extern "C" Actor* fn_802AFA10(Actor* p, s16 n) {
	if (p != nullptr) {
		*(void**)p = lbl_804A8470;
		__dt__5ActorFv(p, 0);
		if (n > 0) {
			operator delete(p);
		}
	}
	return p;
}

extern "C" void fn_802AFA70(char* this_) {
    Init48 s;
    s32 i;
    s.w18 = -1;
    s.w1c = -1;
    for (i = 0; (u8)i < 0x10; i += 8) {
        s.idx[(u8)i] = i;
        s.idx[(u8)(i + 1)] = i + 1;
        s.idx[(u8)(i + 2)] = i + 2;
        s.idx[(u8)(i + 3)] = i + 3;
        s.idx[(u8)(i + 4)] = i + 4;
        s.idx[(u8)(i + 5)] = i + 5;
        s.idx[(u8)(i + 6)] = i + 6;
        s.idx[(u8)(i + 7)] = i + 7;
    }
    s.w18 = -1;
    s.w1c = 0;
    s.w20 = 0;
    s.b24[0] = 0;
    s.b24[1] = 0;
    s.b24[2] = 0;
    s.b24[3] = 1;
    s.b24[4] = 1;
    s.b24[5] = 0;
    s.b24[6] = 0;
    s.b24[7] = 0;
    s.b24[8] = 0;
    s.b24[9] = 0;
    s.b24[10] = 1;
    s.w30 = 3;
    s.b34[0] = 1;
    s.b34[1] = 0;
    s.b34[2] = 0;
    s.w38 = -1;
    s.w3c = 0;
    s.w40 = 2;
    s.b24[1] = -3;
    switch (*(s32*)(this_ + 0x244)) {
    case 0:
        *((u8*)&s.w18 + 3) = 0x60;
        s32 iVar1 = *(s32*)(this_ + 0x240) + 0x10;
        if (*(s32*)(this_ + 0x4) < 8) {
            u32 uVar2 = ((SlotVirt6*)*(char**)(lbl_8053AAF8 + 0xa4))->v06(0x534f4220, lbl_8046CA68);
            fn_802F86CC(*(u32*)(lbl_8053AB10 + 0x20), this_ + 0xc, uVar2, iVar1, lbl_80540970, lbl_80540970, &s);
        }
        fn_80307AC8(*(s32*)(this_ + 0x198), *(s32*)(this_ + 0x4), this_ + 0xc, *(s32*)(this_ + 0x240) + 0x10, 0, 0, -1);
        break;
    case 1:
    case 3:
        if (*(s32*)(this_ + 0x250) != 0) {
            *((u8*)&s.w18 + 3) = *(s32*)(this_ + 0x254);
            s32 iVar1 = *(s32*)(this_ + 0x240) + 0x10;
            if (*(s32*)(this_ + 0x4) < 8) {
                u32 uVar2 = ((SlotVirt6*)*(char**)(lbl_8053AAF8 + 0xa4))->v06(0x534f4220, lbl_8046CA68);
                fn_802F86CC(*(u32*)(lbl_8053AB10 + 0x20), this_ + 0xc, uVar2, iVar1, lbl_80540970, lbl_80540970, &s);
            }
            fn_80307AC8(*(s32*)(this_ + 0x198), *(s32*)(this_ + 0x4), this_ + 0xc, *(s32*)(this_ + 0x240) + 0x10, 0, 0, -1);
        }
        break;
    }
}

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802B0194(u8* this_) {
	s32 id;
	u8* mgr;
	f32* pfVar5;

	*(s32*)(this_ + 0x240) = *(u32*)(this_ + 0x90) & 0xf;
	*(s32*)(this_ + 0x244) = (*(u32*)(this_ + 0x90) >> 7) & 0x1f;
	*(s32*)(this_ + 0x248) = (*(u32*)(this_ + 0x90) >> 4) & 1;
	*(s32*)(this_ + 0x230) = 0;
	*(s32*)(this_ + 0x250) = 0;
	*(s32*)(this_ + 0x24c) = 8;
	*(s32*)(this_ + 0x254) = 0x28;
	*(s32*)(this_ + 0x258) = 0;
	*(s32*)(this_ + 0x25c) = 0;

	id = *(s32*)(this_ + 4);
	mgr = (u8*)fn_802D6A9C();
	if (id < 8) {
		pfVar5 = (f32*)(mgr + 0xcc);
	} else {
		pfVar5 = (f32*)(mgr + 0xdc);
	}

	*(f32*)(this_ + 0x23c) = *(f32*)(this_ + 0x14);
	switch (*(s32*)(this_ + 0x240)) {
	case 0:
		*(f32*)(this_ + 0x234) = *(f32*)(this_ + 0xc);
		*(f32*)(this_ + 0x238) = 192.0f + pfVar5[1];
		*(f32*)(this_ + 0x60) = -32.0f;
		*(f32*)(this_ + 0x64) = -256.0f;
		*(f32*)(this_ + 0x68) = 32.0f;
		*(f32*)(this_ + 0x6c) = 256.0f;
		break;
	case 1:
		*(f32*)(this_ + 0x234) = *(f32*)(this_ + 0xc);
		*(f32*)(this_ + 0x238) = 192.0f + pfVar5[1];
		*(f32*)(this_ + 0x60) = -32.0f;
		*(f32*)(this_ + 0x64) = -256.0f;
		*(f32*)(this_ + 0x68) = 32.0f;
		*(f32*)(this_ + 0x6c) = 256.0f;
		break;
	case 2:
		*(f32*)(this_ + 0x234) = 256.0f + pfVar5[0];
		*(f32*)(this_ + 0x238) = *(f32*)(this_ + 0x10);
		*(f32*)(this_ + 0x60) = -256.0f;
		*(f32*)(this_ + 0x64) = -32.0f;
		*(f32*)(this_ + 0x68) = 256.0f;
		*(f32*)(this_ + 0x6c) = 32.0f;
		break;
	default:
		*(f32*)(this_ + 0x234) = 256.0f + pfVar5[0];
		*(f32*)(this_ + 0x238) = *(f32*)(this_ + 0x10);
		*(f32*)(this_ + 0x60) = -256.0f;
		*(f32*)(this_ + 0x64) = -32.0f;
		*(f32*)(this_ + 0x68) = 256.0f;
		*(f32*)(this_ + 0x6c) = 32.0f;
		break;
	}
}

