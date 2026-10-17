

#include "types.h"
#include "dolphin/dvd/dvd.h"
#include "dolphin/dvd/dvdfs.h"
#include "JSystem/J2D/J2DScreen.h"

extern "C" {
extern void* lbl_8053ADD0;
extern const float lbl_8054360C;
extern const float lbl_80543610;
extern const float lbl_80543604;
extern const float lbl_805435E8;
extern const float lbl_805435F8;
extern const float lbl_805435FC;
extern const float lbl_80543600;
void fn_80402E08(void*, f32, f32);
extern s32 lbl_8053AF80;
extern char lbl_80477898[];
extern void* lbl_8053ACA8;
extern u8 lbl_80529DEC[];
u8 fn_80457F80(s32, u32*, s32);
void OSSetSaveRegion(void*, void*);
void OSSetBootDol(u32);
BOOL __PADDisableRecalibration(BOOL);
void fn_802B1558(void*);
}

extern "C" int fn_803DAC3C(void)
{
    if (lbl_8053ADD0 != 0) {
        return *(int*)((u8*)lbl_8053ADD0 + 0x68);
    }
    return 2;
}

extern "C" void fn_803DD19C(void)
{
}

extern "C" void fn_803DD1A0(void)
{
}

extern "C" void fn_803DD1A4(u8* self) {
    f32 f31;
    s32 v = *(s32*)(self + 0x8c);
    if (v < 30) {
        f31 = (f32)(v * v) / lbl_805435F8;
    } else {
        s32 t = v - 30;
        f31 = lbl_805435E8 - (f32)(t * t) / lbl_805435F8;
    }
    s32 d;
    s32 w = *(s32*)(self + 0x88);
    if (w < 5) {
        d = w;
    } else {
        d = 10 - w;
    }
    f32 f30 = lbl_805435FC * (f32)(d * d) / lbl_80543600;
    if (*(s32*)(self + 0x80) == 0) {
        fn_80402E08(*(void**)(self + 0x50), lbl_80543604, f30);
        fn_80402E08(*(void**)(self + 0x54), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x58), lbl_80543604, f30);
    } else {
        fn_80402E08(*(void**)(self + 0x50), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x54), lbl_80543604, f30);
        fn_80402E08(*(void**)(self + 0x58), *(f32*)(*(u8**)(self + 0x54) + 8) - *(f32*)(*(u8**)(self + 0x50) + 8), f30);
    }
    J2DPane* pane = ((J2DScreen*)*(void**)(self + 0x4))->search('Paccur01');
    pane->setAlpha((u8)((f32)self[0xa2] * f31));
    pane = ((J2DScreen*)*(void**)(self + 0x4))->search('Paccur02');
    pane->setAlpha((u8)((f32)self[0xa2] * f31));
}

extern "C" void fn_803DD3DC(void)
{
}

extern "C" void fn_803DD760(void)
{
}

extern "C" void fn_803DD764(void* self_) {
    u8* self = (u8*)self_;
    f32 inc = lbl_8054360C;
    f32 threshold = lbl_80543610;
    *(f32*)(self + 0x7c) += inc;
    if (*(f32*)(self + 0x7c) >= threshold) {
        *(f32*)(self + 0x7c) = threshold;
        u32 arg = 0xb;
        DVDFileInfo fileInfo;
        if (fn_80457F80(lbl_8053AF80, &arg, -2) != 0) {
            s16 v = *(s16*)(self + 0x98) - 1;
            *(s16*)(self + 0x98) = v;
            if (v <= 0 && DVDOpen(lbl_80477898, &fileInfo) == 1) {
                u8* base = lbl_80529DEC;
                u32 off;
                for (off = 0; off < 16; off += 8) {
                    u8* src = base + off;
                    u8* dst = (u8*)(off - 0x7f900000);
                    dst[0] = src[0x216];
                    dst[1] = src[0x217];
                    dst[2] = src[0x218];
                    dst[3] = src[0x219];
                    dst[4] = src[0x21a];
                    dst[5] = src[0x21b];
                    dst[6] = src[0x21c];
                    dst[7] = src[0x21d];
                    src = base + off + 8;
                    dst = (u8*)(off + 8 - 0x7f900000);
                    dst[0] = src[0x216];
                    dst[1] = src[0x217];
                    dst[2] = src[0x218];
                    dst[3] = src[0x219];
                    dst[4] = src[0x21a];
                    dst[5] = src[0x21b];
                    dst[6] = src[0x21c];
                    dst[7] = src[0x21d];
                }
                OSSetSaveRegion((void*)0x80700000, (void*)0x8070001f);
                __PADDisableRecalibration(1);
                fn_802B1558(lbl_8053ACA8);
                OSSetBootDol(fileInfo.startAddr);
                OSResetSystem(0, 0, 0);
            }
        }
    }
}

extern "C" void fn_803DD8E8(void* self_)
{
    u8* self = (u8*)self_;
    f32 threshold = lbl_80543610;
    f32 inc = lbl_8054360C;
    f32 field = *(f32*)(self + 0x78);
    f32 t = field + inc;
    *(f32*)(self + 0x78) = t;
    if (!(*(f32*)(self + 0x78) >= threshold)) {
        return;
    }
    *(f32*)(self + 0x78) = threshold;
    *(f32*)(self + 0x7c) = lbl_80543604;
    s32 v = *(s16*)(self + 0x9a) + 1;
    *(s16*)(self + 0x9a) = v;
    if ((s16)v > 100) {
        *(int*)(self + 0x84) = 7;
    }
}

extern "C" void fn_803DD93C(void* self_)
{
    u8* self = (u8*)self_;
    f32 threshold = lbl_80543610;
    f32 t = *(f32*)(self + 0x7c);
    t = t + lbl_8054360C;
    *(f32*)(self + 0x7c) = t;
    if (!(*(f32*)(self + 0x7c) >= threshold)) {
        return;
    }
    *(f32*)(self + 0x7c) = threshold;
    *(int*)(self + 0x84) = 6;
}

extern void* lbl_8053AB10;
extern void* lbl_8053AED8;
extern void (J2DScreen::*lbl_804B0628[])();
void fn_8013B490(void*);
void fn_80427D2C(void*, s32, s32, s32, s32);
void fn_80440EE8(void*);
extern const float lbl_80543634;
extern const float lbl_80543638;

class SeqVoice {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual BOOL isPlaying();
    virtual void fadeOut(f32);
};

extern void (J2DScreen::*lbl_804B0568[])();
void fn_80458FF0(void*, u32, s32, s32);
void fn_80458408(void*, u32, s32);
void fn_803DCCA4(u8*);
int fn_80427DB4(SeqVoice*, u8);
void fn_80427D94(SeqVoice*);
int fn_80427D60(SeqVoice*);
u8 fn_804286A0(void);
u8 fn_802B1DCC(void*);
extern "C" void fn_803DF624(u8* self) {
    (((J2DScreen*)lbl_8053ADD0)->*(lbl_804B0628[*(s32*)(self + 0x84)]))();
    fn_8013B490(lbl_8053AB10);
    ((J2DScreen*)*(void**)(self + 0x8))->draw(lbl_80543604, lbl_80543604, *(J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
    if (self[0xa0] == 2) {
        fn_80427D2C(*(void**)(self + 0x64), 0x32, 0x9f, -0x164, -0x11b);
    }
    fn_8013B490(lbl_8053AB10);
    ((J2DScreen*)*(void**)(self + 0x4))->draw(lbl_80543604, lbl_80543604, *(J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
    fn_80440EE8(lbl_8053AED8);
    if (*(s32*)(self + 0x84) == 5) {
        void* obj = *(void**)(self + 0x10);
        ((void (*)(void*, s32))((*(void***)obj)[0x24 / 4]))(obj, (s32)*(f32*)(self + 0x7c));
        obj = *(void**)(self + 0x10);
        ((void (*)(void*, s32, s32, s32, f32, f32, f32, f32))((*(void***)obj)[0xec / 4]))(obj, 0, 0, 0, lbl_80543604, lbl_80543604, lbl_80543634, lbl_80543638);
    } else if (*(s32*)(self + 0x84) == 6) {
        void* obj = *(void**)(self + 0x10);
        ((void (*)(void*, s32, s32, s32, f32, f32, f32, f32))((*(void***)obj)[0xec / 4]))(obj, 0, 0, 0, lbl_80543604, lbl_80543604, lbl_80543634, lbl_80543638);
    } else if (*(s32*)(self + 0x84) == 7) {
        void* obj = *(void**)(self + 0x10);
        ((void (*)(void*, s32))((*(void***)obj)[0x24 / 4]))(obj, (s32)*(f32*)(self + 0x7c));
        obj = *(void**)(self + 0x10);
        ((void (*)(void*, s32, s32, s32, f32, f32, f32, f32))((*(void***)obj)[0xec / 4]))(obj, 0, 0, 0, lbl_80543604, lbl_80543604, lbl_80543634, lbl_80543638);
    }
    if (*(s32*)(self + 0x94) != 0) {
        u8* base = lbl_80529DEC;
        if (*(s32*)(base + 0x1a0) > 0) {
            *(s32*)(base + 0x1a0) -= 1;
        } else {
            *(s32*)(base + 0x1a0) = 0;
        }
        *(s32*)(self + 0x94) = *(s32*)(base + 0x1a0);
    }
}

extern "C" void fn_803DF810(u8* self) {
    if (*(s32*)(self + 0x94) == 0 && *(s32*)(self + 0x84) != 7) {
        fn_80458FF0((void*)lbl_8053AF80, 0x100001a, 0, 0);
        fn_80458408((void*)lbl_8053AF80, 0x100001a, 0);
        lbl_80529DEC[0x248] = 0;
    }
    (((J2DScreen*)lbl_8053ADD0)->*(lbl_804B0568[*(s32*)(self + 0x84)]))();
    fn_803DCCA4(self);
    if (self[0xa0] == 1) {
        if (fn_80427DB4(*(SeqVoice**)(self + 0x64), self[0x9e]) != 0) {
            self[0xa1] = 0;
            self[0xa0] = 2;
        } else {
            fn_80427D94(*(SeqVoice**)(self + 0x64));
        }
    } else if (self[0xa0] == 2) {
        int r = fn_80427D60(*(SeqVoice**)(self + 0x64));
        if (fn_804286A0() && self[0xa1] == 0) {
            SeqVoice* v = *(SeqVoice**)(self + 0x64);
            (*(void (**)(SeqVoice*, f32))((u8*)v + 0x14))(v, lbl_80543604);
            self[0xa1] = 1;
        }
        if (*(s32*)(self + 0x68) != 2 || fn_802B1DCC(lbl_8053ACA8)) {
            fn_80427D94(*(SeqVoice**)(self + 0x64));
            self[0xa0] = 0;
        } else {
            SeqVoice* v = *(SeqVoice**)(self + 0x64);
            if ((*(u32 (**)(SeqVoice*))((u8*)v + 0x10))(v) == 0 || r == 0) {
                fn_80427D94(*(SeqVoice**)(self + 0x64));
                if (fn_80427DB4(*(SeqVoice**)(self + 0x64), self[0x9e]) != 0) {
                    self[0xa1] = 0;
                } else {
                    fn_80427D94(*(SeqVoice**)(self + 0x64));
                    self[0xa0] = 1;
                }
            }
        }
    } else if (self[0xa0] == 3) {
        fn_80427D94(*(SeqVoice**)(self + 0x64));
        self[0xa0] = 0;
    }
}

