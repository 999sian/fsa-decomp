#include "types.h"
#include "Game/PaneState.h"
#include "JSystem/JGeometry/Box.h"
extern "C" const f32 lbl_80543BE4;
extern "C" const f32 lbl_80543BE8;
extern "C" const f32 lbl_80543BEC;
extern "C" const f32 lbl_80543BDC;
extern "C" const f32 lbl_80543BE0;
extern "C" void rotate__7J2DPaneFff13J2DRotateAxisf(void*,f32,f32,u32,f32);
extern "C" void fn_80402E08(void*,f32,f32);
extern "C" char lbl_80529DEC[];

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
    virtual void s4(f32 width, f32 height);
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
#include "JSystem/J2D/J2DScreen.h"

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
extern "C" const float lbl_80543BC8;
extern "C" const double lbl_80543BD0;
extern "C" void* lbl_8053AD78;
extern "C" f32 fn_803832BC(char*, s32, s32, s32, s32);

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
static inline void menuMovePane(PaneState* rec, f32 offset) {
    f32 x=rec->centerX;
    x=x-offset;
    rec->pane->move(x,rec->y);
}
static inline f32 menuFontRatio(f32 fontSize, const f32 baseSize) { return fontSize/baseSize; }
static inline f32 menuTextWidth(f32 measured, f32 ratio, const f32 padding) {
    f32 width=measured*ratio;
    width+=padding;
    return width;
}
struct MenuOptionRecord {
    u8 field_00[0x7c];
    u8 flag_7C, flag_7D, field_7E, flag_7F;
    u8 field_80[8];
    u8 flag_88, flag_89;
    u8 field_8A[0x3e];
};
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

extern "C" void fn_80435E20(char* this_) {
    s16 state = *(s16*)(this_ + 0x60);
    if (state == 0) {
        if (--*(s16*)(this_ + 0x5e) <= 0) {
            char* game = (char*)lbl_8053AAF8;
            union { f32 f; u32 s; } random;
            *(volatile u32*)(game + 0xb4) = *(volatile u32*)(game + 0xb4) * 0x19660d + 0x3c6ef35f;
            random.s = (*(volatile u32*)(game + 0xb4) >> 9) | 0x3f800000;
            *(s16*)(this_ + 0x5e) = (s32)(lbl_80543BDC * (random.f - lbl_80543BE0)) + 10;
            if (*(s16*)(this_ + 0x66) == -6) *(s16*)(this_ + 0x66) = 6;
            else *(s16*)(this_ + 0x66) = -6;
            {
            char* pane = *(char**)(*(char**)(this_ + 0xc) + 4);
            rotate__7J2DPaneFff13J2DRotateAxisf(pane,
                lbl_80543BC8 * (*(f32*)(pane + 0x28) - *(f32*)(pane + 0x20)),
                lbl_80543BC8 * (*(f32*)(pane + 0x2c) - *(f32*)(pane + 0x24)),
                0x7a, *(s16*)(this_ + 0x62) + *(s16*)(this_ + 0x66));
        }
            {
            char* pane = *(char**)(*(char**)(this_ + 0x10) + 4);
            rotate__7J2DPaneFff13J2DRotateAxisf(pane,
                lbl_80543BC8 * (*(f32*)(pane + 0x28) - *(f32*)(pane + 0x20)),
                lbl_80543BC8 * (*(f32*)(pane + 0x2c) - *(f32*)(pane + 0x24)),
                0x7a, *(s16*)(this_ + 0x64) + *(s16*)(this_ + 0x66));
        }
        }
    } else {
        if (state == 1 || state == -1) {
            *(s16*)(this_ + 0x66) = 0;
            {
            char* pane = *(char**)(*(char**)(this_ + 0xc) + 4);
            rotate__7J2DPaneFff13J2DRotateAxisf(pane,
                lbl_80543BC8 * (*(f32*)(pane + 0x28) - *(f32*)(pane + 0x20)),
                lbl_80543BC8 * (*(f32*)(pane + 0x2c) - *(f32*)(pane + 0x24)),
                0x7a, *(s16*)(this_ + 0x62) + *(s16*)(this_ + 0x66));
        }
            {
            char* pane = *(char**)(*(char**)(this_ + 0x10) + 4);
            rotate__7J2DPaneFff13J2DRotateAxisf(pane,
                lbl_80543BC8 * (*(f32*)(pane + 0x28) - *(f32*)(pane + 0x20)),
                lbl_80543BC8 * (*(f32*)(pane + 0x2c) - *(f32*)(pane + 0x24)),
                0x7a, *(s16*)(this_ + 0x64) + *(s16*)(this_ + 0x66));
        }
        }
        s16 step = *(s16*)(this_ + 0x60);
        if ((s16)step < 0) {
            int n;
            if (step > -5) n = -step;
            else {
                n = step + 10;
                if (step == -10) *(s16*)(this_ + 0x60) = 0;
            }
            fn_80402E08(*(void**)(this_ + 0xc), *(f32*)(this_ + 0x40) + lbl_80543BE4 * (f32)(n*n) / lbl_80543BE8, *(f32*)(this_ + 0x44));
            fn_80402E08(*(void**)(this_ + 0x10), -*(f32*)(this_ + 0x40), *(f32*)(this_ + 0x44));
            if (*(s16*)(this_ + 0x60) != 0) --*(s16*)(this_ + 0x60);
        } else if ((s16)step > 0) {
            int n;
            if (step < 5) n = step;
            else {
                n = 10 - step;
                if (step == 10) *(s16*)(this_ + 0x60) = 0;
            }
            fn_80402E08(*(void**)(this_ + 0xc), *(f32*)(this_ + 0x40), *(f32*)(this_ + 0x44));
            fn_80402E08(*(void**)(this_ + 0x10), -*(f32*)(this_ + 0x40) + lbl_80543BEC * (f32)(n*n) / lbl_80543BE8, *(f32*)(this_ + 0x44));
            if (*(s16*)(this_ + 0x60) != 0) ++*(s16*)(this_ + 0x60);
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

extern "C" const float lbl_80543BDC;
extern "C" const float lbl_80543BE0;
extern "C" const float lbl_80543BF8;
extern "C" void rotate__7J2DPaneFff13J2DRotateAxisf(void*,f32,f32,u32,f32);
extern "C" void fn_80402E08(void*,f32,f32);
extern "C" const f32 lbl_80543BF0;
extern "C" const f32 lbl_80543BF4;
extern "C" void fn_8043670C(char* this_, s32 flag) {
    f32 width1, width2, half2;
    f32 f29;
    f32 f30;
    f32 f31 = *(f32*)((char*)((VtSlots*)*(void**)(this_ + 0x4))->s13(0x54713031ULL) + 0x11c);
    *(s16*)(this_ + 0x58) = 0;
    *(s16*)(this_ + 0x5a) = 0;
    {
        char* game=(char*)lbl_8053AAF8;
        union {f32 f;u32 s;} first;
        *(volatile u32*)(game+0xb4)=*(volatile u32*)(game+0xb4)*0x19660d+0x3c6ef35f;
        first.s=(*(volatile u32*)(game+0xb4)>>9)|0x3f800000;
        *(s16*)(this_+0x5c)=(s32)((first.f-lbl_80543BE0)*lbl_80543BDC)+10;
    }
    {
        char* game=(char*)lbl_8053AAF8;
        union {f32 f;u32 s;} second;
        *(volatile u32*)(game+0xb4)=*(volatile u32*)(game+0xb4)*0x19660d+0x3c6ef35f;
        second.s=(*(volatile u32*)(game+0xb4)>>9)|0x3f800000;
        *(s16*)(this_+0x5e)=(s32)((second.f-lbl_80543BE0)*lbl_80543BDC)+10;
    }
    *(s16*)(this_ + 0x60) = 0;
    *(s16*)(this_ + 0x66) = -6;
    *(u8*)(this_ + 0x6b) = 0;
    *(u8*)(this_ + 0x6c) = (u8)flag;

    {
        char* pane=*(char**)(*(char**)(this_+0xc)+4);
        rotate__7J2DPaneFff13J2DRotateAxisf(pane,lbl_80543BC8*(*(f32*)(pane+0x28)-*(f32*)(pane+0x20)),lbl_80543BC8*(*(f32*)(pane+0x2c)-*(f32*)(pane+0x24)),0x7a,*(s16*)(this_+0x62)+*(s16*)(this_+0x66));
    }
    {
        char* pane=*(char**)(*(char**)(this_+0x10)+4);
        rotate__7J2DPaneFff13J2DRotateAxisf(pane,lbl_80543BC8*(*(f32*)(pane+0x28)-*(f32*)(pane+0x20)),lbl_80543BC8*(*(f32*)(pane+0x2c)-*(f32*)(pane+0x24)),0x7a,*(s16*)(this_+0x64)+*(s16*)(this_+0x66));
    }
    if (*(u8*)(this_+0x6c)==0) {
        f29=fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_+4))->s13(0x54713031ULL))->getStringPtr(),0x129,0,0,0);
        f30=f31/lbl_80543BF8;
        *(u8*)(this_+0x68)=((MenuOptionRecord*)lbl_8050EC80)[*(s32*)(lbl_8050EC80+0x10)].flag_7C;
        width1=f29*f30;
        width1+=lbl_80543BF8;
        f31=width1*lbl_80543BC8;
        {
        PaneState* rec=*(PaneState**)(this_+0x1c);
        menuMovePane(rec,f31);
        rec=*(PaneState**)(this_+0x1c);
        rec->pane->resize(width1,rec->height);
    }
        {
        PaneState* rec=*(PaneState**)(this_+0x20);
        menuMovePane(rec,f31);
        rec=*(PaneState**)(this_+0x20);
        rec->pane->resize(width1,rec->height);
    }
        f29=fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_+4))->s13(0x54713032ULL))->getStringPtr(),0x24d,0,0,0);
        *(u8*)(this_+0x69)=((MenuOptionRecord*)lbl_8050EC80)[*(s32*)(lbl_8050EC80+0x10)].flag_88;
        width2=f29*f30;
        width2+=lbl_80543BF8;
        half2=width2*lbl_80543BC8;
        {
        PaneState* rec=*(PaneState**)(this_+0x24);
        menuMovePane(rec,half2);
        rec=*(PaneState**)(this_+0x24);
        rec->pane->resize(width2,rec->height);
    }
        {
        PaneState* rec=*(PaneState**)(this_+0x28);
        menuMovePane(rec,half2);
        rec=*(PaneState**)(this_+0x28);
        rec->pane->resize(width2,rec->height);
    }
    } else {
        f29=fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_+4))->s13(0x54713031ULL))->getStringPtr(),0xf8,0,0,0);
        f31/=lbl_80543BF8;
        *(u8*)(this_+0x68)=((MenuOptionRecord*)lbl_8050EC80)[*(s32*)(lbl_8050EC80+0x10)].flag_7D;
        width1=f29*f31;
        width1+=lbl_80543BF8;
        f30=width1*lbl_80543BC8;
        {
        PaneState* rec=*(PaneState**)(this_+0x1c);
        menuMovePane(rec,f30);
        rec=*(PaneState**)(this_+0x1c);
        rec->pane->resize(width1,rec->height);
    }
        {
        PaneState* rec=*(PaneState**)(this_+0x20);
        menuMovePane(rec,f30);
        rec=*(PaneState**)(this_+0x20);
        rec->pane->resize(width1,rec->height);
    }
        f29=fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_+4))->s13(0x54713032ULL))->getStringPtr(),0xf9,0,0,0);
        *(u8*)(this_+0x69)=((MenuOptionRecord*)lbl_8050EC80)[*(s32*)(lbl_8050EC80+0x10)].flag_7F;
        width2=f29*f31;
        width2+=lbl_80543BF8;
        f30=width2*lbl_80543BC8;
        {
        PaneState* rec=*(PaneState**)(this_+0x24);
        menuMovePane(rec,f30);
        rec=*(PaneState**)(this_+0x24);
        rec->pane->resize(width2,rec->height);
    }
        {
        PaneState* rec=*(PaneState**)(this_+0x28);
        menuMovePane(rec,f30);
        rec=*(PaneState**)(this_+0x28);
        rec->pane->resize(width2,rec->height);
    }
        f29=fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_+4))->s13(0x54713033ULL))->getStringPtr(),0x24d,0,0,0);
        *(u8*)(this_+0x6a)=((MenuOptionRecord*)lbl_8050EC80)[*(s32*)(lbl_8050EC80+0x10)].flag_89;
        f31=f29*f31;
        f31+=lbl_80543BF8;
        f30=f31*lbl_80543BC8;
        {
        PaneState* rec=*(PaneState**)(this_+0x2c);
        menuMovePane(rec,f30);
        rec=*(PaneState**)(this_+0x2c);
        rec->pane->resize(f31,rec->height);
    }
        {
        PaneState* rec=*(PaneState**)(this_+0x30);
        menuMovePane(rec,f30);
        rec=*(PaneState**)(this_+0x30);
        rec->pane->resize(f31,rec->height);
    }
    }
    if(*(u8*)(this_+0x68)) *(f32*)(this_+0x48)=fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_+4))->s13(0x54613031ULL))->getStringPtr(),0xfc,0,0,0);
    else *(f32*)(this_+0x48)=fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_+4))->s13(0x54613031ULL))->getStringPtr(),0xfd,0,0,0);
    if(*(u8*)(this_+0x6c)==0) {
        if(*(u8*)(this_+0x69)) *(f32*)(this_+0x4c)=fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_+4))->s13(0x54613032ULL))->getStringPtr(),0xfc,0,0,0);
        else *(f32*)(this_+0x4c)=fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_+4))->s13(0x54613032ULL))->getStringPtr(),0xfd,0,0,0);
    } else {
        if(*(u8*)(this_+0x69)) *(f32*)(this_+0x4c)=fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_+4))->s13(0x54613032ULL))->getStringPtr(),0xfe,0,0,0);
        else *(f32*)(this_+0x4c)=fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_+4))->s13(0x54613032ULL))->getStringPtr(),0xff,0,0,0);
        if(*(u8*)(this_+0x6a)) *(f32*)(this_+0x50)=fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_+4))->s13(0x54613033ULL))->getStringPtr(),0xfc,0,0,0);
        else *(f32*)(this_+0x50)=fn_803832BC(((J2DTextBox*)((VtSlots*)*(void**)(this_+4))->s13(0x54613033ULL))->getStringPtr(),0xfd,0,0,0);
    }
    fn_80434724(this_);
    fn_80402E08(*(void**)(this_+8),lbl_80543BD8,lbl_80543BF0);
    *(s16*)(*(char**)(this_+8)+0x22)=0;
    fn_80402E08(*(void**)(this_+0xc),*(f32*)(this_+0x40),lbl_80543BF0+*(f32*)(this_+0x44));
    fn_80402E08(*(void**)(this_+0x10),-*(f32*)(this_+0x40),lbl_80543BF0+*(f32*)(this_+0x44));
    *(s16*)(*(char**)(this_+0xc)+0x22)=0;
    *(s16*)(*(char**)(this_+0x10)+0x22)=0;
    fn_80402E08(*(void**)(this_+0x14),lbl_80543BD8,lbl_80543BF0);
    *(s16*)(*(char**)(this_+0x14)+0x22)=0;
    fn_80402E08(*(void**)(this_+0x18),lbl_80543BD8,lbl_80543BF0);
    *(s16*)(*(char**)(this_+0x18)+0x22)=0;
    fn_80402E08(*(void**)(this_+0x34),lbl_80543BD8,lbl_80543BF4);
    *(s16*)(*(char**)(this_+0x34)+0x22)=0;
    fn_80402E08(*(void**)(this_+0x38),lbl_80543BD8,lbl_80543BF4);
    *(s16*)(*(char**)(this_+0x38)+0x22)=0;
    if(*((u8*)lbl_8053AAF8+0x7f)) *(s32*)(this_+0x54)=((u8*)lbl_80529DEC)[0x23c]+1;
    else *(s32*)(this_+0x54)=((u8*)lbl_80529DEC)[0x23d]+2;
}

extern "C" void* fn_8043711C(char* this_, s16 how) {
	s16 h = how;
	char* p = this_;
	if (p != 0) {
		*(void**)p = lbl_804B16A8;

		DispatchSlot2(p + 0x4);
		DispatchSlot2(p + 0x8);
		DispatchSlot2(p + 0xc);
		DispatchSlot2(p + 0x10);
		DispatchSlot2(p + 0x14);
		DispatchSlot2(p + 0x18);
		char* q = p;
		for (s32 i = 0; i < 6; i++) {
			if (*(DtorSlot2**)(q + 0x1c) != 0) {
				(*(DtorSlot2**)(q + 0x1c))->destroy(1);
			}
			*(void**)(q + 0x1c) = 0;
			q += 4;
		}
		DispatchSlot2(p + 0x34);
		if (h > 0) {
			__dl__FPv(p);
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
struct Menu372C4 {
    void* vtable;
    J2DScreen* screen;
};
struct Menu372C4Names {
    char screen[0xc];
    char alternateScreen[0x10];
    char image[0x14];
    char alternateImage[1];
};
static inline void* allocateMenuPane() {
    void* pane = __nw__FUl(0x2c);
    if (pane) *(char**)pane = lbl_804AF86C;
    return pane;
}
extern "C" void* fn_804372C4(void* this_) {
    char* self = (char*)this_;
    J2DScreen* screen;
    *(char**)this_ = lbl_804B16A8;
    screen = (J2DScreen*)__nw__FUl(0x118);
    if (screen) __ct__9J2DScreenFv(screen);
    *(J2DScreen**)(self + 0x4) = screen;
    if (*(u8*)((char*)lbl_8053AAF8 + 0x7f) == 1) {
        setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(self + 4), "rule.blo", 0x1100000, *(void**)(lbl_80529DEC + 0x28));
    } else {
        setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(self + 4), "rule_bat.blo", 0x1100000, *(void**)(lbl_80529DEC + 0x28));
    }
    *(void**)(self + 0x8) = allocateMenuPane();
    fn_80402F04(*(void**)(self + 0x8), ((VtSlots*)*(void**)(self + 0x4))->s13(0x506f7062626b3033ULL));
    *(void**)(self + 0xc) = allocateMenuPane();
    fn_80402F04(*(void**)(self + 0xc), ((VtSlots*)*(void**)(self + 0x4))->s13(0x5061723031ULL));
    *(void**)(self + 0x10) = allocateMenuPane();
    fn_80402F04(*(void**)(self + 0x10), ((VtSlots*)*(void**)(self + 0x4))->s13(0x5061723032ULL));
    *(void**)(self + 0x14) = allocateMenuPane();
    fn_80402F04(*(void**)(self + 0x14), ((VtSlots*)*(void**)(self + 0x4))->s13(0x004e646174613033ULL));
    *(void**)(self + 0x18) = allocateMenuPane();
    fn_80402F04(*(void**)(self + 0x18), ((VtSlots*)*(void**)(self + 0x4))->s13(0x004e646174613032ULL));
    *(void**)(self + 0x1c) = allocateMenuPane();
    fn_80402F04(*(void**)(self + 0x1c), ((VtSlots*)*(void**)(self + 0x4))->s13(0x0000507262613031ULL));
    *(void**)(self + 0x20) = allocateMenuPane();
    fn_80402F04(*(void**)(self + 0x20), ((VtSlots*)*(void**)(self + 0x4))->s13(0x0000507262613032ULL));
    *(void**)(self + 0x24) = allocateMenuPane();
    fn_80402F04(*(void**)(self + 0x24), ((VtSlots*)*(void**)(self + 0x4))->s13(0x0000507262613033ULL));
    *(void**)(self + 0x28) = allocateMenuPane();
    fn_80402F04(*(void**)(self + 0x28), ((VtSlots*)*(void**)(self + 0x4))->s13(0x0000507262613034ULL));
    if (*(u8*)((char*)lbl_8053AAF8 + 0x7f) == 1) {
        *(void**)(self + 0x30) = 0;
        *(void**)(self + 0x2c) = 0;
    } else {
        *(void**)(self + 0x2c) = allocateMenuPane();
        fn_80402F04(*(void**)(self + 0x2c), ((VtSlots*)*(void**)(self + 0x4))->s13(0x0000507262613035ULL));
        *(void**)(self + 0x30) = allocateMenuPane();
        fn_80402F04(*(void**)(self + 0x30), ((VtSlots*)*(void**)(self + 0x4))->s13(0x0000507262613036ULL));
    }
    *(void**)(self + 0x34) = allocateMenuPane();
    fn_80402F04(*(void**)(self + 0x34), ((VtSlots*)*(void**)(self + 0x4))->s13(0x50746f7062623037ULL));
    *(void**)(self + 0x38) = *(void**)((char*)lbl_8053AED8 + 0x8);
    void* image = fn_804030C4(0x54494d47, "kk_kettei_01.bti");
    fn_80440D78(lbl_8053AED8, image);
    fn_80440CE4(lbl_8053AED8, fn_804030C4(0x54494d47, "kk_modoru_01.bti"));
    {
        void* font = *(void**)((char*)lbl_8053AD78 + 0x154);

        void* p = ((VtSlots*)*(void**)(self + 0x4))->s13(0x54613032ULL);

        ((J2DTextBox*)p)->setFont((JUTFont*)font);
    }
    {
        void* font = *(void**)((char*)lbl_8053AD78 + 0x154);

        void* p = ((VtSlots*)*(void**)(self + 0x4))->s13(0x54713032ULL);

        ((J2DTextBox*)p)->setFont((JUTFont*)font);
    }
    {
        void* font = *(void**)((char*)lbl_8053AD78 + 0x154);

        void* p = ((VtSlots*)*(void**)(self + 0x4))->s13(0x54613031ULL);

        ((J2DTextBox*)p)->setFont((JUTFont*)font);
    }
    {
        void* font = *(void**)((char*)lbl_8053AD78 + 0x154);

        void* p = ((VtSlots*)*(void**)(self + 0x4))->s13(0x54713031ULL);

        ((J2DTextBox*)p)->setFont((JUTFont*)font);
    }
    if (*(u8*)((char*)lbl_8053AAF8 + 0x7f) == 0) {
        {
            void* font = *(void**)((char*)lbl_8053AD78 + 0x154);

            void* p = ((VtSlots*)*(void**)(self + 0x4))->s13(0x54613033ULL);

            ((J2DTextBox*)p)->setFont((JUTFont*)font);
        }
        {
            void* font = *(void**)((char*)lbl_8053AD78 + 0x154);

            void* p = ((VtSlots*)*(void**)(self + 0x4))->s13(0x54713033ULL);

            ((J2DTextBox*)p)->setFont((JUTFont*)font);
        }
    }
    *(s16*)(self + 0x62) = (s16)(int)getRotate__7J2DPaneCFv(((VtSlots*)*(void**)(self + 0x4))->s13(0x5061723031ULL));
    *(s16*)(self + 0x64) = (s16)(int)getRotate__7J2DPaneCFv(((VtSlots*)*(void**)(self + 0x4))->s13(0x5061723032ULL));
    f32 zero = 0.0f;
    *(f32*)(self + 0x3c) = zero;
    *(f32*)(self + 0x40) = zero;
    *(f32*)(self + 0x44) = zero;
    *(s16*)(self + 0x58) = 0;
    *(s16*)(self + 0x5a) = 0;
    *(s16*)(self + 0x5c) = 0;
    *(s16*)(self + 0x5e) = 0;
    *(s16*)(self + 0x60) = 0;
    *(s16*)(self + 0x66) = 0;
    *(u32*)(self + 0x54) = 0;
    *(f32*)(self + 0x48) = zero;
    *(u8*)(self + 0x68) = 0;
    *(f32*)(self + 0x4c) = zero;
    *(u8*)(self + 0x69) = 0;
    *(f32*)(self + 0x50) = zero;
    *(u8*)(self + 0x6a) = 0;
    *(u8*)(self + 0x6b) = 0;
    *(u8*)(self + 0x6c) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

