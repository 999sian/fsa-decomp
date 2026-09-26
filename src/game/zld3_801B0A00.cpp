// Game TU 801B0A00-801B27DC (ZLD3). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" s32 lbl_804A35A0[3];
extern "C" void fn_801EE434(void* handle);
extern "C" void dtor_801F593C(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern "C" void* GetRoomConfigRecord(void);
extern "C" void fn_802D7440(void* unused, u8 flag);
extern void* lbl_804A35AC[];

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
        fn_802D7440(GetRoomConfigRecord(), 1);
        dtor_801F593C(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
