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
    virtual void s2(f32 x, f32 y);
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
    void state0();
    void state1();
};
typedef void (Unk80434370::*Unk80434370Fn)();
static Unk80434370Fn lbl_804B1690[2] = {
    &Unk80434370::state0,
    &Unk80434370::state1
};

extern "C" char* lbl_8053AB10;
extern "C" float lbl_80543BC8;
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
        *(f32*)(this_ + 0x40) = ((*(f32*)(p + 0x28) - *(f32*)(p + 0x20)) - *(f32*)(this_ + 0x48) * f31) * lbl_80543BC8;
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
        *(f32*)(this_ + 0x40) = ((*(f32*)(p + 0x28) - *(f32*)(p + 0x20)) - *(f32*)(this_ + 0x4c) * f31) * lbl_80543BC8;
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
    return param_1->m_state == 2;
}

extern "C" float lbl_80543BDC;
extern "C" float lbl_80543BE0;
extern "C" float lbl_80543BF8;
extern "C" void fn_8043670C(char* this_, s32 flag) {
    f32 f31 = *(f32*)((char*)((VtSlots*)*(void**)(this_ + 0x4))->s13(0x54713031ULL) + 0x11c);
    *(s16*)(this_ + 0x58) = 0;
    *(s16*)(this_ + 0x5a) = 0;
    union { f32 f; u32 s; } u;
    u32 seed;
    seed = *(u32*)((u8*)lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f;
    *(u32*)((u8*)lbl_8053AAF8 + 0xb4) = seed;
    u.s = (seed >> 9) | 0x3f800000;
    *(s16*)(this_ + 0x5c) = (s16)((s32)((u.f - lbl_80543BE0) * lbl_80543BDC) + 10);
    seed = *(u32*)((u8*)lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f;
    *(u32*)((u8*)lbl_8053AAF8 + 0xb4) = seed;
    u.s = (seed >> 9) | 0x3f800000;
    *(s16*)(this_ + 0x5e) = (s16)((s32)((u.f - lbl_80543BE0) * lbl_80543BDC) + 10);
    *(s16*)(this_ + 0x60) = 0;
    *(s16*)(this_ + 0x66) = -6;
    *(u8*)(this_ + 0x6b) = 0;
    *(u8*)(this_ + 0x6c) = (u8)flag;
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
		for (s32 i = 0; i < 6; i++) {
			DispatchSlot2(this_ + 0x1c + i * 4);
		}
		DispatchSlot2(this_ + 0x34);
		if (how > 0) {
			__dl__FPv(this_);
		}
	}
	return this_;
}

extern "C" char lbl_804AF86C[];
extern "C" char lbl_8048F598[];
extern "C" char lbl_80529DEC[];
extern "C" void* __nw__FUl(u32 size);
extern "C" void __ct__9J2DScreenFv(void* self);
extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* self, const char* name, u32 a, void* archive);
extern "C" void fn_80402F04(void* obj, void* pane);
extern "C" void* fn_804030C4(u32 tag, const char* name);
extern "C" void fn_80440D78(void* p, void* r);
extern "C" void fn_80440CE4(void* p, void* r);
extern "C" f32 getRotate__7J2DPaneCFv(void* pane);
extern "C" void* fn_804372C4(void* this_) {
    char* names = lbl_8048F598;
    *(char**)this_ = lbl_804B16A8;
    void* screen = __nw__FUl(0x118);
    if (screen != 0) {
        __ct__9J2DScreenFv(screen);
    }
    *(void**)((char*)this_ + 0x4) = screen;
    if (*(u8*)((char*)lbl_8053AAF8 + 0x7f) == 1) {
        setPriority__9J2DScreenFPCcUlP10JKRArchive(screen, names, 0x1100000, *(void**)(lbl_80529DEC + 0x28));
    } else {
        setPriority__9J2DScreenFPCcUlP10JKRArchive(screen, names + 0xc, 0x1100000, *(void**)(lbl_80529DEC + 0x28));
    }
    void* o = __nw__FUl(0x2c);
    if (o != 0) {
        *(char**)o = lbl_804AF86C;
        *(void**)((char*)this_ + 0x8) = o;
        fn_80402F04(*(void**)((char*)this_ + 0x8), ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x506f7062626b3033ULL));
    }
    o = __nw__FUl(0x2c);
    if (o != 0) {
        *(char**)o = lbl_804AF86C;
        *(void**)((char*)this_ + 0xc) = o;
        fn_80402F04(*(void**)((char*)this_ + 0xc), ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x5061723031ULL));
    }
    o = __nw__FUl(0x2c);
    if (o != 0) {
        *(char**)o = lbl_804AF86C;
        *(void**)((char*)this_ + 0x10) = o;
        fn_80402F04(*(void**)((char*)this_ + 0x10), ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x5061723032ULL));
    }
    o = __nw__FUl(0x2c);
    if (o != 0) {
        *(char**)o = lbl_804AF86C;
        *(void**)((char*)this_ + 0x14) = o;
        fn_80402F04(*(void**)((char*)this_ + 0x14), ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x004e646174613033ULL));
    }
    o = __nw__FUl(0x2c);
    if (o != 0) {
        *(char**)o = lbl_804AF86C;
        *(void**)((char*)this_ + 0x18) = o;
        fn_80402F04(*(void**)((char*)this_ + 0x18), ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x004e646174613032ULL));
    }
    o = __nw__FUl(0x2c);
    if (o != 0) {
        *(char**)o = lbl_804AF86C;
        *(void**)((char*)this_ + 0x1c) = o;
        fn_80402F04(*(void**)((char*)this_ + 0x1c), ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x0000507262613031ULL));
    }
    o = __nw__FUl(0x2c);
    if (o != 0) {
        *(char**)o = lbl_804AF86C;
        *(void**)((char*)this_ + 0x20) = o;
        fn_80402F04(*(void**)((char*)this_ + 0x20), ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x0000507262613032ULL));
    }
    o = __nw__FUl(0x2c);
    if (o != 0) {
        *(char**)o = lbl_804AF86C;
        *(void**)((char*)this_ + 0x24) = o;
        fn_80402F04(*(void**)((char*)this_ + 0x24), ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x0000507262613033ULL));
    }
    o = __nw__FUl(0x2c);
    if (o != 0) {
        *(char**)o = lbl_804AF86C;
        *(void**)((char*)this_ + 0x28) = o;
        fn_80402F04(*(void**)((char*)this_ + 0x28), ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x0000507262613034ULL));
    }
    if (*(u8*)((char*)lbl_8053AAF8 + 0x7f) == 1) {
        *(void**)((char*)this_ + 0x30) = 0;
        *(void**)((char*)this_ + 0x2c) = 0;
    } else {
        o = __nw__FUl(0x2c);
        if (o != 0) {
            *(char**)o = lbl_804AF86C;
            *(void**)((char*)this_ + 0x2c) = o;
            fn_80402F04(*(void**)((char*)this_ + 0x2c), ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x0000507262613035ULL));
        }
        o = __nw__FUl(0x2c);
        if (o != 0) {
            *(char**)o = lbl_804AF86C;
            *(void**)((char*)this_ + 0x30) = o;
            fn_80402F04(*(void**)((char*)this_ + 0x30), ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x0000507262613036ULL));
        }
    }
    o = __nw__FUl(0x2c);
    if (o != 0) {
        *(char**)o = lbl_804AF86C;
        *(void**)((char*)this_ + 0x34) = o;
        fn_80402F04(*(void**)((char*)this_ + 0x34), ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x50746f7062623037ULL));
    }
    *(void**)((char*)this_ + 0x38) = *(void**)((char*)lbl_8053AED8 + 0x8);
    fn_80440D78(lbl_8053AED8, fn_804030C4(0x54494d47, names + 0x1c));
    fn_80440CE4(lbl_8053AED8, fn_804030C4(0x54494d47, names + 0x30));
    {
        void* p = ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x54613032ULL);
        (*(void (**)(void*, void*))(*(char**)p + 0x9c))(p, *(void**)((char*)lbl_8053AD78 + 0x154));
    }
    {
        void* p = ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x54713032ULL);
        (*(void (**)(void*, void*))(*(char**)p + 0x9c))(p, *(void**)((char*)lbl_8053AD78 + 0x154));
    }
    {
        void* p = ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x54613031ULL);
        (*(void (**)(void*, void*))(*(char**)p + 0x9c))(p, *(void**)((char*)lbl_8053AD78 + 0x154));
    }
    {
        void* p = ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x54713031ULL);
        (*(void (**)(void*, void*))(*(char**)p + 0x9c))(p, *(void**)((char*)lbl_8053AD78 + 0x154));
    }
    if (*(u8*)((char*)lbl_8053AAF8 + 0x7f) == 0) {
        {
            void* p = ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x54613033ULL);
            (*(void (**)(void*, void*))(*(char**)p + 0x9c))(p, *(void**)((char*)lbl_8053AD78 + 0x154));
        }
        {
            void* p = ((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x54713033ULL);
            (*(void (**)(void*, void*))(*(char**)p + 0x9c))(p, *(void**)((char*)lbl_8053AD78 + 0x154));
        }
    }
    *(s16*)((char*)this_ + 0x62) = (s16)(int)getRotate__7J2DPaneCFv(((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x5061723031ULL));
    *(s16*)((char*)this_ + 0x64) = (s16)(int)getRotate__7J2DPaneCFv(((VtSlots*)*(void**)((char*)this_ + 0x4))->s13(0x5061723032ULL));
    f32 zero = lbl_80543BD8;
    *(f32*)((char*)this_ + 0x3c) = zero;
    *(f32*)((char*)this_ + 0x40) = zero;
    *(f32*)((char*)this_ + 0x44) = zero;
    *(s16*)((char*)this_ + 0x58) = 0;
    *(s16*)((char*)this_ + 0x5a) = 0;
    *(s16*)((char*)this_ + 0x5c) = 0;
    *(s16*)((char*)this_ + 0x5e) = 0;
    *(s16*)((char*)this_ + 0x60) = 0;
    *(s16*)((char*)this_ + 0x66) = 0;
    *(u32*)((char*)this_ + 0x54) = 0;
    *(f32*)((char*)this_ + 0x48) = zero;
    *(u8*)((char*)this_ + 0x68) = 0;
    *(f32*)((char*)this_ + 0x4c) = zero;
    *(u8*)((char*)this_ + 0x69) = 0;
    *(f32*)((char*)this_ + 0x50) = zero;
    *(u8*)((char*)this_ + 0x6a) = 0;
    *(u8*)((char*)this_ + 0x6b) = 0;
    *(u8*)((char*)this_ + 0x6c) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

