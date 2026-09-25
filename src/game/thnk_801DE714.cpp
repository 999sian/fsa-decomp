// Game TU 801DE714-801E2540 (THNK). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void fn_801CE694(void* this_);
extern "C" u8 fn_801CD2F8(s32 owner);
extern "C" void* fn_80212AC0(void);
extern "C" void fn_80212AF0(void* registry, void* posPtr);
extern "C" void fn_801CE2BC(void);
extern "C" void fn_8021835C(void* this_);
extern "C" s32 fn_801CCF7C(void);

extern "C" void fn_801DE714(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state == 0xa) {
        fn_801CE694(this_);
    }
}

extern "C" void fn_801DE740(void* this_) {
    u8 flag = 0;
    s32 state = *(s32*)((char*)this_ + 0x248);
    switch (state) {
    case 0xb:
    case 0xc:
        flag = 1;
        break;
    }
    if (flag == 0) {
        return;
    }
    if (fn_801CD2F8(*(s32*)((char*)this_ + 0x4)) != 0) {
        return;
    }
    {
        void* registry = fn_80212AC0();
        fn_80212AF0(registry, (char*)this_ + 0xc);
    }
}

extern "C" void fn_801DE9C0(void* this_) {
    fn_801CE2BC();
    fn_8021835C(this_);
}

extern "C" bool fn_801E1D7C(void* thisObj) {
	s32 v = *(s32*)((char*)thisObj + 0x248);
	return v < 0xd && v >= 0xb;
}

extern "C" bool fn_801E1D9C(void* thisObj) {
	s32 v = *(s32*)((char*)thisObj + 0x278);
	bool result = false;
	if (v == 2) { result = true; }
	return result;
}

extern "C" s32 fn_801E1DE8(void* this_) {
    return fn_801CCF7C();
}
