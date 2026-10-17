#include "types.h"

struct DtorSlot2 {
	virtual void destroy(s32 freeFlag);
};

static inline void DispatchSlot2(char* slot) {
	DtorSlot2* obj = *(DtorSlot2**)slot;
	if (obj != 0) {
		obj->destroy(1);
	}
	*(void**)slot = 0;
}
extern "C" char lbl_804B16A8[];
extern "C" void __dl__FPv(void* this_);
class J2DGrafContext;
class VtSlots {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual s32 s10();
    virtual void s11();
    virtual void s12();
    virtual void* s13(u64 tag);
};
class J2DScreen {
public:
    void draw(float, float, const J2DGrafContext*);
};

class Unk80434370 {
public:
    unsigned char pad[0x6b];
    unsigned char m_state;
};
typedef void (Unk80434370::*Unk80434370Fn)();
extern Unk80434370Fn lbl_804B1690[];

extern "C" char* lbl_8053AB10;
extern "C" const float lbl_80543BC8;
extern "C" double lbl_80543BD0;
extern "C" void* lbl_8053AD78;
extern "C" f32 fn_803832BC(char*, s32, s32, s32, s32);
class J2DTextBox {
public:
    char* getStringPtr() const;
};
extern "C" void* lbl_8053AED8;
extern "C" const float lbl_80543BD8;
extern "C" void fn_8013B490(void*);
extern "C" void fn_80440EE8(void*);
extern "C" Unk80434370Fn lbl_804B1690[];
extern "C" u8 fn_80402940(void* obj, s32 type, f32 a, f32 b, s32 c);
extern "C" u32 fn_80309A9C(void* pad, s32 mask, s32 a);
extern "C" u32 fn_80309C4C(void* pad, s32 mask, s32 a);
extern "C" void* lbl_8053AD30;
extern "C" void* lbl_8053AF80;
extern "C" void* lbl_8053AAF8;
extern "C" u8 lbl_8050EC80[];
extern "C" void fn_80458880(void* mgr, u32 p, int v);
extern "C" void fn_80434370(char* this_);
extern "C" void fn_80434724(char* this_);
extern "C" void fn_80435E20(char* this_);
extern "C" void fn_80434370(char* this_) {
    f32 f31;
    f31 = *(f32*)((char*)((VtSlots*)*(void**)(this_ + 0x4))->s13((u64)0x54613031) + 0x11c);
    f31 = f31 / (f32)((VtSlots*)*(void**)((char*)lbl_8053AD78 + 0x154))->s10();
    s16 idx = *(s16*)(this_ + 0x5a);
    if (idx == 0) {
        if (*(u8*)(this_ + 0x68) == 1) {
            *(u8*)(this_ + 0x68) = 0;
            *(f32*)(this_ + 0x48) = fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_ + 0x4))->s13((u64)0x54613031))->getStringPtr(), 0xfd, 0, 0, 0);
        } else {
            *(u8*)(this_ + 0x68) = 1;
            *(f32*)(this_ + 0x48) = fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_ + 0x4))->s13((u64)0x54613031))->getStringPtr(), 0xfc, 0, 0, 0);
        }
        char* p = (char*)((VtSlots*)*(void**)(this_ + 0x4))->s13((u64)0x54613031);
        f32 d = *(f32*)(p + 0x28) - *(f32*)(p + 0x20);
        *(f32*)(this_ + 0x40) = (d - *(f32*)(this_ + 0x48) * f31) * lbl_80543BC8;
    } else if (idx == 1) {
        if (*(u8*)(this_ + 0x6c) == 0) {
            if (*(u8*)(this_ + 0x69) == 1) {
                *(u8*)(this_ + 0x69) = 0;
                *(f32*)(this_ + 0x4c) = fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_ + 0x4))->s13((u64)0x54613032))->getStringPtr(), 0xfd, 0, 0, 0);
            } else {
                *(u8*)(this_ + 0x69) = 1;
                *(f32*)(this_ + 0x4c) = fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_ + 0x4))->s13((u64)0x54613032))->getStringPtr(), 0xfc, 0, 0, 0);
            }
        } else {
            if (*(u8*)(this_ + 0x69) == 1) {
                *(u8*)(this_ + 0x69) = 0;
                *(f32*)(this_ + 0x4c) = fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_ + 0x4))->s13((u64)0x54613032))->getStringPtr(), 0xff, 0, 0, 0);
            } else {
                *(u8*)(this_ + 0x69) = 1;
                *(f32*)(this_ + 0x4c) = fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_ + 0x4))->s13((u64)0x54613032))->getStringPtr(), 0xfe, 0, 0, 0);
            }
        }
        char* p = (char*)((VtSlots*)*(void**)(this_ + 0x4))->s13((u64)0x54613032);
        f32 d = *(f32*)(p + 0x28) - *(f32*)(p + 0x20);
        *(f32*)(this_ + 0x40) = (d - *(f32*)(this_ + 0x4c) * f31) * lbl_80543BC8;
    } else if (idx == 2) {
        if (*(u8*)(this_ + 0x6c) == 1) {
            if (*(u8*)(this_ + 0x6a) == 1) {
                *(u8*)(this_ + 0x6a) = 0;
                *(f32*)(this_ + 0x50) = fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_ + 0x4))->s13((u64)0x54613033))->getStringPtr(), 0xfd, 0, 0, 0);
            } else {
                *(u8*)(this_ + 0x6a) = 1;
                *(f32*)(this_ + 0x50) = fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_ + 0x4))->s13((u64)0x54613033))->getStringPtr(), 0xfc, 0, 0, 0);
            }
        }
    }
}

extern "C" void fn_804361A8(char* this_) {
    if (fn_80309C4C(lbl_8053AD30, 0x1100, *(s32*)(this_ + 0x54)) != 0) {
        if (*(u8*)(this_ + 0x6c) == 0) {
            if (*(u8*)(this_ + 0x68)) {
                *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x7c) = 1;
            } else {
                *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x7c) = 0;
            }
            if (*(u8*)(this_ + 0x69)) {
                *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x88) = 1;
            } else {
                *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x88) = 0;
            }
        } else {
            if (*(u8*)(this_ + 0x68)) {
                *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x7d) = 1;
            } else {
                *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x7d) = 0;
            }
            if (*(u8*)(this_ + 0x69)) {
                *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x7f) = 1;
            } else {
                *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x7f) = 0;
            }
            if (*(u8*)(this_ + 0x6a)) {
                *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x89) = 1;
            } else {
                *(u8*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x89) = 0;
            }
        }
        *(u8*)(this_ + 0x6b) = 2;
    } else if (fn_80309C4C(lbl_8053AD30, 0x200, *(s32*)(this_ + 0x54)) != 0) {
        *(u8*)(this_ + 0x6b) = 2;
    } else if (fn_80309A9C(lbl_8053AD30, 0x4, *(s32*)(this_ + 0x54)) != 0) {
        if (*(u8*)((u8*)lbl_8053AAF8 + 0x7e) != 0) {
            fn_80458880(lbl_8053AF80, 0x26, -1);
            *(s16*)(this_ + 0x5a) += 1;
            if (*(u8*)(this_ + 0x6c) == 0) {
                if (*(s16*)(this_ + 0x5a) > 1) {
                    *(s16*)(this_ + 0x5a) = 0;
                }
            } else if (*(s16*)(this_ + 0x5a) > 2) {
                *(s16*)(this_ + 0x5a) = 0;
            }
            fn_80434724(this_);
        }
    } else if (fn_80309A9C(lbl_8053AD30, 0x8, *(s32*)(this_ + 0x54)) != 0) {
        if (*(u8*)((u8*)lbl_8053AAF8 + 0x7e) != 0) {
            fn_80458880(lbl_8053AF80, 0x26, -1);
            *(s16*)(this_ + 0x5a) -= 1;
            if (*(u8*)(this_ + 0x6c) == 0) {
                if (*(s16*)(this_ + 0x5a) < 0) {
                    *(s16*)(this_ + 0x5a) = 1;
                }
            } else if (*(s16*)(this_ + 0x5a) < 0) {
                *(s16*)(this_ + 0x5a) = 2;
            }
            fn_80434724(this_);
        }
    } else if (fn_80309A9C(lbl_8053AD30, 0x1, *(s32*)(this_ + 0x54)) != 0) {
        fn_80458880(lbl_8053AF80, 0x26, -1);
        *(s16*)(this_ + 0x60) = -1;
        fn_80434370(this_);
    } else if (fn_80309A9C(lbl_8053AD30, 0x2, *(s32*)(this_ + 0x54)) != 0) {
        fn_80458880(lbl_8053AF80, 0x26, -1);
        *(s16*)(this_ + 0x60) = 1;
        fn_80434370(this_);
    }
    fn_80435E20(this_);
}

extern "C" void fn_8043651C(u8* self) {
    u8 a = 0;
    u8 b = 0;
    u8 c = 0;
    *(s16*)(self + 0x58) += 1;
    if (*(s16*)(self + 0x58) > 0) {
        a = fn_80402940(*(void**)(self + 0x8), 0x10, -150.0f, 0.0f, 0);
        for (int i = 0; i < 2; i++) {
            fn_80402940(*(void**)(self + 0xc + i * 4), 0x10, -150.0f + *(f32*)(self + 0x44), *(f32*)(self + 0x44), 0);
        }
        fn_80402940(*(void**)(self + 0x14), 0x10, -150.0f, 0.0f, 0);
        fn_80402940(*(void**)(self + 0x18), 0x10, -150.0f, 0.0f, 0);
    }
    if (*(s16*)(self + 0x58) > 0) {
        b = fn_80402940(*(void**)(self + 0x34), 0x14, 200.0f, 0.0f, 0);
    }
    if (*(s16*)(self + 0x58) > 10) {
        c = fn_80402940(*(void**)(self + 0x38), 0x16, 200.0f, 0.0f, 0);
    }
    if (a && b && c) {
        *(u8*)(self + 0x6b) = 1;
    }
}

extern "C" void fn_80436668(char* param_1)
{
    fn_8013B490(lbl_8053AB10);
    (*(J2DScreen**)(param_1 + 4))->draw(lbl_80543BD8, lbl_80543BD8, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
    fn_80440EE8(lbl_8053AED8);
}

extern "C" int fn_804366B8(Unk80434370* param_1)
{
    (param_1->*lbl_804B1690[param_1->m_state])();
    return 2 == param_1->m_state;
}

extern "C" void* fn_8043711C(char* this_, s16 how) {
	if (this_ != 0) {
		*(void**)this_ = lbl_804B16A8;

		DispatchSlot2(this_ + 0x4);
		DispatchSlot2(this_ + 0x8);
		DispatchSlot2(this_ + 0xc);
		DispatchSlot2(this_ + 0x10);
		DispatchSlot2(this_ + 0x14);
		DispatchSlot2(this_ + 0x18);
		char* p = this_;
		for (s32 i = 0; i < 6; i++) {
			DispatchSlot2(p + 0x1c);
			p += 4;
		}
		DispatchSlot2(this_ + 0x34);
		if (how > 0) {
			__dl__FPv(this_);
		}
	}
	return this_;
}

