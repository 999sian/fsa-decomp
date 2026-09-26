// Game TU 801C0D70-801C1768 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern s8 lbl_8053AC10[8];
static u16 lbl_804C7E70[0x30];
extern f32 lbl_8053ED90;
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, s32 idx);
extern "C" void fn_801C1768(void* obj);
extern "C" void fn_8021C468(void* obj);

extern "C" void* fn_801C0D70(void) {
	if (!lbl_8053AC10[0]) {
		char* p = (char*)lbl_804C7E70;
		f32 rst = lbl_8053ED90;
		u16 zero = 0;
		s32 negone = -1;
		s8 one = 1;
		*(f32*)(p + 0x54) = rst;
		*(f32*)(p + 0x58) = rst;
		*(f32*)(p + 0x5c) = rst;
		*(u16*)(p + 0x0) = zero;
		*(u16*)(p + 0x2) = zero;
		*(u16*)(p + 0x4) = zero;
		*(u16*)(p + 0x6) = zero;
		*(u16*)(p + 0x8) = zero;
		*(s32*)(p + 0xc) = zero;
		*(s32*)(p + 0x50) = negone;
		lbl_8053AC10[0] = one;
	}
	return lbl_804C7E70;
}

extern "C" void fn_801C115C(char* this_) {
    s32 idx = *(s32*)(this_ + 0x50);
    if (idx < 0) return;
    void* result = fn_801F666C(fn_801F856C(), idx);
    if (result != 0) {
        fn_801C1768(result);
    }
}

extern "C" void fn_801C11A4(char* this_) {
    s32 idx = *(s32*)(this_ + 0x50);
    if (idx < 0) return;
    void* result = fn_801F666C(fn_801F856C(), idx);
    if (result != 0) {
        fn_8021C468((char*)result + 0x2d8);
    }
}

extern "C" s32 fn_801C11F0(char* this_) {
    s32 count = *(s32*)(this_ + 0xc);
    s32 result = 0;
    if (count > 1) {
        s32 field2 = *(u16*)(this_ + 0x2);
        if (count != field2) {
            u16 field0 = *(u16*)(this_ + 0x0);
            if (field0 & 0x6) {
                result = 1;
            }
        }
    }
    return result;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
