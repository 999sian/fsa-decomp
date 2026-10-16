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

extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_801C1224(char* this_, s32 param_2) {
    struct VObj {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
        virtual void v09();
    };
    s32 count = *(s32*)(this_ + 0xc);
    char* p = this_;
    for (s32 i = 0; i < count; i++) {
        char* obj = (char*)fn_801F666C(fn_801F856C(), *(s32*)(p + 0x10));
        if (obj != 0 && (*(u32*)(obj + 0x230) & 0x10000) == 0) {
            *(s32*)(obj + 0x10c) = param_2;
            ((VObj*)obj)->v09();
        }
        p += 4;
    }
}

extern "C" void fn_801C12B8(char* this_) {
    s32 idx = fn_801CD664(*(s32*)(this_ + 0xc));
    s32 id = *(s32*)(this_ + idx * 4 + 0x10);
    char* obj = (char*)fn_801F666C(fn_801F856C(), id);
    if (obj != 0) {
        *(u32*)(obj + 0x230) |= 0x10000;
    }
}

extern "C" s32 fn_801C1314(u16* this_) {
    s32 ret = 0;
    if (*(s32*)((char*)this_ + 0x50) >= 0) {
        if (((this_[0] & 0x40) == 0) && ((this_[0] & 0x80) == 0)) {
            u16 id = this_[2];
            if (id != 0 && *(s32*)((char*)this_ + 0xc) > 0 && this_[3] == id && this_[4] != id) {
                ret = 1;
            }
        }
    }
    return ret;
}

extern "C" void fn_801C1440(char* this_, s32 param_2) {
    s32* p = (s32*)(this_ + 0x10);
    s32 i;
    u8 found = 0;
    if (*(s32*)(this_ + 0xc) <= 0) return;
    for (i = 0; i < *(s32*)(this_ + 0xc); i++, p++) {
        if (!found) {
            if (param_2 == *p) {
                found = 1;
            }
        } else {
            p[-1] = *p;
        }
    }
    if (found) {
        *(s32*)(this_ + 0xc) = *(s32*)(this_ + 0xc) - 1;
    }
}

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* p, s32 v);
extern "C" u16 fn_801C14A8(char* this_, void* param_2) {
    void** arr = (void**)(this_ + 0x10);
    arr[*(s32*)(this_ + 0xc)] = param_2;
    *(s32*)(this_ + 0xc) += 1;
    *(u16*)(this_ + 0x4) += 1;
    if (*(u16*)(this_ + 0x4) == 1) {
        fn_802D7440(fn_802D6A9C(), 0);
    }
    return *(u16*)(this_ + 0x4) - 1;
}

extern "C" void fn_801C151C(char* this_) {
    *(u16*)(this_ + 0x0) = 0;
    *(u16*)(this_ + 0x2) = 0;
    *(u16*)(this_ + 0x4) = 0;
    *(u16*)(this_ + 0x6) = 0;
    *(u16*)(this_ + 0x8) = 0;
    *(s32*)(this_ + 0xc) = 0;
    *(s32*)(this_ + 0x50) = -1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
