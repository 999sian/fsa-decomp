

#include "types.h"
#include "dolphin/dvd/dvd.h"
#include "dolphin/dvd/dvdfs.h"
#include "JSystem/J2D/J2DScreen.h"

struct FsaDisposable {
    virtual void v0(void);
    virtual void v1(void);
    virtual void del(s32);
    virtual void v3(void);
};

extern "C" {
extern void* lbl_8053ADD0;
extern const float lbl_8054360C;
extern const float lbl_80543610;
extern const float lbl_80543604;
extern const float lbl_80543608;
extern const float lbl_805435E8;
extern const float lbl_805435F8;
extern const float lbl_805435FC;
extern const float lbl_80543600;
extern const float lbl_80543614;
extern const float lbl_8054361C;
extern const float lbl_8054362C;
extern const float lbl_80543618;
extern const float lbl_80543624;
extern const float lbl_80543630;
extern u64 lbl_804774C8[];
extern void* lbl_8053AED8;
u8 fn_80402B10(void*, s32, f32, s32, f32);
u8 fn_80402940(void*, s32, f32, s32, f32);
void fn_80440E0C(void*, f32);
void fn_80402E08(void*, f32, f32);
extern s32 lbl_8053AF80;
extern char lbl_80477898[];
extern void* lbl_8053ACA8;
extern u8 lbl_80529DEC[];
extern u8 lbl_8050DB0C[];
u8 fn_80457F80(s32, u32*, s32);
void OSSetSaveRegion(void*, void*);
void OSSetBootDol(u32);
BOOL __PADDisableRecalibration(BOOL);
void fn_802B1558(void*);
void fn_803DAC58(void*, s32, f32);
}

extern "C" int fn_803DAC3C(void)
{
    if (lbl_8053ADD0 != 0) {
        return *(int*)((u8*)lbl_8053ADD0 + 0x68);
    }
    return 2;
}

extern "C" void fn_803DCCA4(u8* self)
{
    f32 f31;
    if (*(s32*)(self + 0x90) != 0) {
        *(s32*)(self + 0x90) = *(s32*)(self + 0x90) + 1;
        f31 = (f32)*(s32*)(self + 0x90) / (f32)*(s16*)(lbl_8050DB0C + 0x12e);
        if (*(s32*)(self + 0x90) >= *(s16*)(lbl_8050DB0C + 0x12e)) {
            *(s32*)(self + 0x90) = 0;
        }
        if (self[0x9e] != 0 && self[0x9f] != 0) {
            u32 im = 0x696d0000;
            void* mgr = *(void**)(self + 0x8);
            void* r = ((void* (*)(void*, u32, s32, u32))((*(void***)mgr)[0x3c / 4]))(mgr, im, 0x50, im + 0x3031);
            ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, 0);
            mgr = *(void**)(self + 0x8);
            r = ((void* (*)(void*, u32, s32, u32))((*(void***)mgr)[0x3c / 4]))(mgr, im, 0x50, im + 0x3032);
            ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, 0);
        }
        if (self[0x9e] != 1 && self[0x9f] != 1) {
            u32 im = 0x696d0000;
            void* mgr = *(void**)(self + 0x8);
            void* r = ((void* (*)(void*, u32, s32, u32))((*(void***)mgr)[0x3c / 4]))(mgr, im, 0x50, im + 0x3131);
            ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, 0);
            mgr = *(void**)(self + 0x8);
            r = ((void* (*)(void*, u32, s32, u32))((*(void***)mgr)[0x3c / 4]))(mgr, im, 0x50, im + 0x3132);
            ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, 0);
        }
        if (*(s32*)(self + 0x84) != 2) {
            switch (self[0x9e]) {
            case 0: {
                u32 im = 0x696d0000;
                void* mgr = *(void**)(self + 0x8);
                void* r = ((void* (*)(void*, u32, s32, u32))((*(void***)mgr)[0x3c / 4]))(mgr, im, 0x50, im + 0x3031);
                ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, (s32)((f32)self[0x11a] * f31));
                mgr = *(void**)(self + 0x8);
                r = ((void* (*)(void*, u32, s32, u32))((*(void***)mgr)[0x3c / 4]))(mgr, im, 0x50, im + 0x3032);
                ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, (s32)((f32)self[0x11b] * f31));
            } break;
            case 1: {
                u32 im = 0x696d0000;
                void* mgr = *(void**)(self + 0x8);
                void* r = ((void* (*)(void*, u32, s32, u32))((*(void***)mgr)[0x3c / 4]))(mgr, im, 0x50, im + 0x3131);
                ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, (s32)((f32)self[0x11c] * f31));
                mgr = *(void**)(self + 0x8);
                r = ((void* (*)(void*, u32, s32, u32))((*(void***)mgr)[0x3c / 4]))(mgr, im, 0x50, im + 0x3132);
                ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, (s32)((f32)self[0x11d] * f31));
            } break;
            }
        }
        f31 = lbl_805435E8 - f31;
        if (*(s32*)(self + 0x84) != 1 || self[0x9e] != self[0x9f]) {
            switch (self[0x9f]) {
            case 0: {
                u32 im = 0x696d0000;
                void* mgr = *(void**)(self + 0x8);
                void* r = ((void* (*)(void*, u32, s32, u32))((*(void***)mgr)[0x3c / 4]))(mgr, im, 0x50, im + 0x3031);
                ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, (s32)((f32)self[0x11a] * f31));
                mgr = *(void**)(self + 0x8);
                r = ((void* (*)(void*, u32, s32, u32))((*(void***)mgr)[0x3c / 4]))(mgr, im, 0x50, im + 0x3032);
                ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, (s32)((f32)self[0x11b] * f31));
            } break;
            case 1: {
                u32 im = 0x696d0000;
                void* mgr = *(void**)(self + 0x8);
                void* r = ((void* (*)(void*, u32, s32, u32))((*(void***)mgr)[0x3c / 4]))(mgr, im, 0x50, im + 0x3131);
                ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, (s32)((f32)self[0x11c] * f31));
                mgr = *(void**)(self + 0x8);
                r = ((void* (*)(void*, u32, s32, u32))((*(void***)mgr)[0x3c / 4]))(mgr, im, 0x50, im + 0x3132);
                ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, (s32)((f32)self[0x11d] * f31));
            } break;
            }
        }
    }
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

extern "C" void fn_803DD3E0(u8* self)
{
    f32 f31;
    if (self[0x9e] == 3 || *(s32*)(self + 0x84) != 1) {
        s32 v = *(s32*)(self + 0x8c);
        if (v < 30) {
            f31 = (f32)(v * v) / lbl_805435F8;
        } else {
            s32 t = v - 30;
            f31 = lbl_805435E8 - (f32)(t * t) / lbl_805435F8;
        }
    } else {
        s32 v = *(s32*)(self + 0x8c);
        if (v < 60) {
            f31 = (f32)(v * v) / lbl_80543608;
        } else {
            s32 t = v - 60;
            f31 = lbl_805435E8 - (f32)(t * t) / lbl_80543608;
        }
    }
    s32 d;
    s32 w = *(s32*)(self + 0x88);
    if (w < 5) {
        d = w;
    } else {
        d = 10 - w;
    }
    f32 f30 = lbl_805435FC * (f32)(d * d) / lbl_80543600;
    switch (self[0x9e]) {
    case 0:
        fn_80402E08(*(void**)(self + 0x34), lbl_80543604, f30);
        fn_80402E08(*(void**)(self + 0x38), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x30), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x44), lbl_80543604, f30);
        fn_80402E08(*(void**)(self + 0x48), lbl_80543604, lbl_80543604);
        fn_803DAC58(self, self[0x9e], f31);
        *(u8*)(*(u8**)(*(u8**)(self + 0x40) + 4) + 0xb0) = 0;
        break;
    case 1:
        fn_80402E08(*(void**)(self + 0x34), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x38), lbl_80543604, f30);
        fn_80402E08(*(void**)(self + 0x30), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x44), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x48), lbl_80543604, f30);
        fn_803DAC58(self, self[0x9e], f31);
        *(u8*)(*(u8**)(*(u8**)(self + 0x40) + 4) + 0xb0) = 0;
        break;
    case 2:
        fn_80402E08(*(void**)(self + 0x34), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x38), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x30), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x44), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x48), lbl_80543604, lbl_80543604);
        fn_803DAC58(self, self[0x9e], f31);
        *(u8*)(*(u8**)(*(u8**)(self + 0x40) + 4) + 0xb0) = 0;
        break;
    default:
        fn_80402E08(*(void**)(self + 0x34), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x38), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x44), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x48), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x30), lbl_80543604, f30);
        fn_80402E08(*(void**)(self + 0x40), lbl_80543604, f30);
        fn_803DAC58(self, self[0x9e], f31);
        *(u8*)(*(u8**)(*(u8**)(self + 0x40) + 4) + 0xb0) = 1;
        break;
    }
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

extern "C" s32 lbl_8053AD30;
extern "C" s32 lbl_8053AAF8;
extern "C" s32 lbl_8053AF80;
extern "C" u8 lbl_80529DEC[];
extern "C" const f32 lbl_80543620;
extern "C" const f32 lbl_8054361C;
extern "C" s32 fn_80309C4C(s32 a, s32 b, s32 c);
extern "C" s32 fn_80309A9C(s32 a, s32 b, s32 c);
extern "C" void fn_80458880(s32 a, s32 b, s32 c);
extern "C" void fn_80458F9C(s32 a, s32 b);
extern "C" void fn_80402E08(void* a, f32 b, f32 c);
extern "C" void fn_803DE05C(u8* self) {
    u8* p;
    s32 i;
    if (*(s32*)(self + 0x88) != 0) {
        *(s32*)(self + 0x88) += 1;
        if (*(s32*)(self + 0x88) > 10) {
            *(s32*)(self + 0x88) = 0;
        }
    }
    if (self[0x9e] == 2) {
        s32 a = ((s32 (*)(void*))(*(void**)(*(u8**)(self + 0x64) + 0x18)))(*(void**)(self + 0x64));
        s32 b = ((s32 (*)(s32))(*(void**)(*(u8**)(self + 0x64) + 0x10)))(a);
        if ((u32)(a - b) <= 1) {
            *(s32*)(self + 0x8c) = 0;
            return;
        }
    }
    if ((u32)fn_80309C4C(lbl_8053AD30, 0x1100, 1) != 0) {
        self[0xa0] = 3;
        if (*(s32*)(self + 0x80) == 0) {
            if (self[0x9e] == 0) {
                ((u8*)lbl_8053AAF8)[0x7f] = 1;
                *(s32*)(self + 0x68) = 3;
            } else if (self[0x9e] == 1) {
                ((u8*)lbl_8053AAF8)[0x7f] = 0;
                *(s32*)(self + 0x68) = 3;
            } else if (self[0x9e] == 2) {
                *(f32*)(self + 0x7c) = lbl_80543604;
                *(s32*)(self + 0x84) = 7;
                fn_80458F9C(lbl_8053AF80, 0x3c);
                lbl_80529DEC[0x23a] = self[0x9e];
            }
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            *(s16*)(self + 0x9c) = 0;
            p = self;
            for (i = 0; i < 2; i++, p += 4) {
                *(u8*)(*(u8**)(*(u8**)(p + 0x34) + 4) + 0xb0) = 1;
                *(u8*)(*(u8**)(*(u8**)(p + 0x44) + 4) + 0xb0) = 1;
                if (i == self[0x9e]) {
                    fn_80402E08(*(void**)(p + 0x34), lbl_80543604, lbl_80543620 - *(f32*)(p + 0x6c));
                    fn_80402E08(*(void**)(p + 0x44), lbl_80543604, lbl_80543620 - *(f32*)(p + 0x6c));
                } else {
                    fn_80402E08(*(void**)(p + 0x34), lbl_80543614, lbl_80543604);
                    fn_80402E08(*(void**)(p + 0x44), lbl_80543614, lbl_80543604);
                }
                *(s16*)(*(u8**)(p + 0x34) + 0x20) = 0;
                *(s16*)(*(u8**)(p + 0x34) + 0x22) = 0;
                *(s16*)(*(u8**)(p + 0x44) + 0x20) = 0;
                *(s16*)(*(u8**)(p + 0x44) + 0x22) = 0;
            }
            *(u8*)(*(u8**)(*(u8**)(self + 0x30) + 4) + 0xb0) = 1;
            fn_80402E08(*(void**)(self + 0x30), lbl_80543604, lbl_8054361C);
            *(s16*)(*(u8**)(self + 0x30) + 0x22) = 0;
            p = self;
            for (i = 0; i < 7; i++, p += 4) {
                fn_80402E08(*(void**)(p + 0x14), lbl_80543604, lbl_80543604);
                *(s16*)(*(u8**)(p + 0x14) + 0x20) = 0;
            }
            p = self;
            for (i = 0; i < 2; i++, p += 4) {
                fn_80402E08(*(void**)(p + 0x50), lbl_80543604, lbl_80543604);
                *(s16*)(*(u8**)(p + 0x50) + 0x22) = 0;
            }
            *(u8*)(*(u8**)(*(u8**)(self + 0x58) + 4) + 0xb0) = 0;
            *(s32*)(self + 0x84) = 4;
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
    } else if ((u32)fn_80309C4C(lbl_8053AD30, 0x200, 1) != 0) {
        *(s16*)(self + 0x9c) = 0;
        self[0xa0] = 3;
        p = self;
        for (i = 0; i < 2; i++, p += 4) {
            *(u8*)(*(u8**)(*(u8**)(p + 0x34) + 4) + 0xb0) = 1;
            *(u8*)(*(u8**)(*(u8**)(p + 0x44) + 4) + 0xb0) = 1;
            if (i == self[0x9e]) {
                fn_80402E08(*(void**)(p + 0x34), lbl_80543604, lbl_80543620 - *(f32*)(p + 0x6c));
                fn_80402E08(*(void**)(p + 0x44), lbl_80543604, lbl_80543620 - *(f32*)(p + 0x6c));
            } else {
                fn_80402E08(*(void**)(p + 0x34), lbl_80543614, lbl_80543604);
                fn_80402E08(*(void**)(p + 0x44), lbl_80543614, lbl_80543604);
            }
            *(s16*)(*(u8**)(p + 0x34) + 0x20) = 0;
            *(s16*)(*(u8**)(p + 0x34) + 0x22) = 0;
            *(s16*)(*(u8**)(p + 0x44) + 0x20) = 0;
            *(s16*)(*(u8**)(p + 0x44) + 0x22) = 0;
        }
        *(u8*)(*(u8**)(*(u8**)(self + 0x30) + 4) + 0xb0) = 1;
        fn_80402E08(*(void**)(self + 0x30), lbl_80543604, lbl_8054361C);
        *(s16*)(*(u8**)(self + 0x30) + 0x22) = 0;
        p = self;
        for (i = 0; i < 7; i++, p += 4) {
            fn_80402E08(*(void**)(p + 0x14), lbl_80543604, lbl_80543604);
            *(s16*)(*(u8**)(p + 0x14) + 0x20) = 0;
        }
        p = self;
        for (i = 0; i < 2; i++, p += 4) {
            fn_80402E08(*(void**)(p + 0x50), lbl_80543604, lbl_80543604);
            *(s16*)(*(u8**)(p + 0x50) + 0x22) = 0;
        }
        *(u8*)(*(u8**)(*(u8**)(self + 0x58) + 4) + 0xb0) = 0;
        *(s32*)(self + 0x84) = 4;
        fn_80458880(lbl_8053AF80, 0xc, -1);
    } else if ((u32)fn_80309A9C(lbl_8053AD30, 2, 1) != 0) {
        if (*(s32*)(self + 0x80) == 0) {
            *(s32*)(self + 0x80) = 1;
            *(s32*)(self + 0x88) = 1;
            *(s32*)(self + 0x8c) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if ((u32)fn_80309A9C(lbl_8053AD30, 1, 1) != 0) {
        if (*(s32*)(self + 0x80) == 1) {
            *(s32*)(self + 0x80) = 0;
            *(s32*)(self + 0x88) = 1;
            *(s32*)(self + 0x8c) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    }
    *(s32*)(self + 0x8c) += 1;
    if (*(s32*)(self + 0x8c) >= 0x3c) {
        *(s32*)(self + 0x8c) = 0;
    }
}

extern "C" void fn_803832BC(char* a, char* b, s32 c, s32 d, s32 e);
extern "C" char* lbl_8047788C[];
extern "C" char* lbl_80477880[];
typedef void* (*FsaFindPaneFn)(void*, u32, u32, u32);
extern "C" void fn_803DEC44(u8* self)
{
    s32 i;
    if (*(s32*)(self + 0x88) != 0) {
        *(s32*)(self + 0x88) += 1;
        if (*(s32*)(self + 0x88) > 10) {
            *(s32*)(self + 0x88) = 0;
        }
    }
    if ((u32)fn_80309C4C(lbl_8053AD30, 0x1100, 1) != 0) {
        if (self[0x9e] == 3) {
            self[0x9f] = self[0x9e];
            *(s32*)(self + 0x68) = 5;
        } else {
            *(s16*)(self + 0x9c) = 0;
            for (i = 0; i < 2; i++) {
                fn_80402E08(*(void**)(self + 0x34 + i * 4), lbl_80543604, lbl_80543604);
                *(s16*)(*(u8**)(self + 0x34 + i * 4) + 0x20) = 0;
                *(s16*)(*(u8**)(self + 0x34 + i * 4) + 0x22) = 0;
                fn_80402E08(*(void**)(self + 0x44 + i * 4), lbl_80543604, lbl_80543604);
                *(s16*)(*(u8**)(self + 0x44 + i * 4) + 0x20) = 0;
                *(s16*)(*(u8**)(self + 0x44 + i * 4) + 0x22) = 0;
            }
            fn_80402E08(*(void**)(self + 0x30), lbl_80543604, lbl_80543604);
            *(s16*)(*(u8**)(self + 0x30) + 0x22) = 0;
            *(u8*)(*(u8**)(*(u8**)(self + 0x40) + 4) + 0xb0) = 0;
            for (i = 0; i < 7; i++) {
                *(u8*)(*(u8**)(*(u8**)(self + 0x14 + i * 4) + 4) + 0xb0) = 1;
                fn_80402E08(*(void**)(self + 0x14 + i * 4), lbl_80543614, lbl_80543604);
                *(s16*)(*(u8**)(self + 0x14 + i * 4) + 0x20) = 0;
            }
            for (i = 0; i < 2; i++) {
                *(u8*)(*(u8**)(*(u8**)(self + 0x50 + i * 4) + 4) + 0xb0) = 1;
                fn_80402E08(*(void**)(self + 0x50 + i * 4), lbl_80543604, lbl_8054361C);
                *(s16*)(*(u8**)(self + 0x50 + i * 4) + 0x22) = 0;
            }
            switch (self[0x9e]) {
            case 0:
                *(u8*)((u8*)((FsaFindPaneFn)(*(void***)*(void**)(self + 4))[0x3c / 4])(*(void**)(self + 4), 0x570000, 0x576762, 0x636f3031) + 0xb0) = 0;
                *(u8*)((u8*)((FsaFindPaneFn)(*(void***)*(void**)(self + 4))[0x3c / 4])(*(void**)(self + 4), 0x6f700000, 0x576e, 0x6f703031) + 0xb0) = 0;
                *(u8*)((u8*)((FsaFindPaneFn)(*(void***)*(void**)(self + 4))[0x3c / 4])(*(void**)(self + 4), 0x6f700000, 0x576e, 0x6f703032) + 0xb0) = 1;
                *(u8*)((u8*)((FsaFindPaneFn)(*(void***)*(void**)(self + 4))[0x3c / 4])(*(void**)(self + 4), 0x570000, 0x576762, 0x636f3032) + 0xb0) = 1;
                break;
            case 1:
                *(u8*)((u8*)((FsaFindPaneFn)(*(void***)*(void**)(self + 4))[0x3c / 4])(*(void**)(self + 4), 0x570000, 0x576762, 0x636f3031) + 0xb0) = 1;
                *(u8*)((u8*)((FsaFindPaneFn)(*(void***)*(void**)(self + 4))[0x3c / 4])(*(void**)(self + 4), 0x6f700000, 0x576e, 0x6f703031) + 0xb0) = 1;
                *(u8*)((u8*)((FsaFindPaneFn)(*(void***)*(void**)(self + 4))[0x3c / 4])(*(void**)(self + 4), 0x6f700000, 0x576e, 0x6f703032) + 0xb0) = 0;
                *(u8*)((u8*)((FsaFindPaneFn)(*(void***)*(void**)(self + 4))[0x3c / 4])(*(void**)(self + 4), 0x570000, 0x576762, 0x636f3032) + 0xb0) = 0;
                break;
            }
            fn_803832BC(((J2DTextBox*)((FsaFindPaneFn)(*(void***)*(void**)(self + 4))[0x3c / 4])(*(void**)(self + 4), 0x6f700000, 0x546e, 0x6f703031))->getStringPtr(), lbl_8047788C[self[0x9e]], 0, 0, 0);
            fn_803832BC(((J2DTextBox*)((FsaFindPaneFn)(*(void***)*(void**)(self + 4))[0x3c / 4])(*(void**)(self + 4), 0x6f700000, 0x546e, 0x6f703032))->getStringPtr(), lbl_8047788C[self[0x9e]], 0, 0, 0);
            fn_803832BC(((J2DTextBox*)((FsaFindPaneFn)(*(void***)*(void**)(self + 4))[0x3c / 4])(*(void**)(self + 4), 0x78700000, 0x5465, 0x78703031))->getStringPtr(), lbl_80477880[self[0x9e]], 0, 0, 0);
            *(u8*)(*(u8**)(*(u8**)(self + self[0x9e] * 4 + 0x44) + 4) + 0xb0) = 0;
            *(s32*)(self + 0x84) = 2;
            self[0x9f] = self[0x9e];
            *(s32*)(self + 0x90) = 1;
        }
        fn_80458880(lbl_8053AF80, 0xb, -1);
    } else if ((u32)fn_80309C4C(lbl_8053AD30, 0x200, 1) != 0) {
        *(s32*)(self + 0x68) = 1;
        fn_80458880(lbl_8053AF80, 0xc, -1);
    } else if ((u32)fn_80309A9C(lbl_8053AD30, 4, 1) != 0) {
        self[0x9f] = self[0x9e];
        if (self[0x9e] < 3) {
            self[0x9e] = self[0x9e] + 1;
            if (self[0x9e] == 2) {
                self[0x9e] = 3;
            }
        } else {
            self[0x9e] = 0;
        }
        *(s32*)(self + 0x88) = 1;
        if (self[0x9e] == 3) {
            *(s32*)(self + 0x8c) = 0x1e;
        } else {
            *(s32*)(self + 0x8c) = 0x3c;
        }
        *(s32*)(self + 0x90) = 1;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    } else if ((u32)fn_80309A9C(lbl_8053AD30, 8, 1) != 0) {
        self[0x9f] = self[0x9e];
        if (self[0x9e] != 0) {
            self[0x9e] = self[0x9e] - 1;
            if (self[0x9e] == 2) {
                self[0x9e] = 1;
            }
        } else {
            self[0x9e] = 3;
        }
        *(s32*)(self + 0x88) = 1;
        if (self[0x9e] == 3) {
            *(s32*)(self + 0x8c) = 0x1e;
        } else {
            *(s32*)(self + 0x8c) = 0x3c;
        }
        *(s32*)(self + 0x90) = 1;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    }
    *(s32*)(self + 0x8c) = *(s32*)(self + 0x8c) + 1;
    if (self[0x9e] == 3) {
        if (*(s32*)(self + 0x8c) >= 0x3c) {
            *(s32*)(self + 0x8c) = 0;
        }
    } else if (*(s32*)(self + 0x8c) >= 0x78) {
        *(s32*)(self + 0x8c) = 0;
    }
}

extern "C" void fn_803DF2B4(u8* self) {
    u8* q;
    u8 a;
    u8 b;
    u8 c;
    s32 i;
    s32 k;
    s32 n;
    s32 j;
    f32 f30;

    *(s16*)(self + 0x9c) = *(s16*)(self + 0x9c) + 1;
    a = 0;
    b = 0;
    c = 0;
    q = self;
    k = 0;
    for (i = 0; i < 2; i++, q += 4, k += 3) {
        if (*(s16*)(self + 0x9c) <= k) {
            break;
        }
        a = fn_80402B10(*(void**)(q + 0x34), 0x14, lbl_80543614, 0, lbl_80543604);
        fn_80402B10(*(void**)(q + 0x44), 0x14, lbl_80543614, 0, lbl_80543604);
        n = *(s16*)(self + 0x9c) - k;
        if (n > 20) {
            n = 20;
        }
        f30 = (f32)(n * n) / lbl_80543618;
        switch (i) {
        case 0:
            for (j = 0; j < 17; j++) {
                J2DPane* pane = ((J2DScreen*)*(void**)(self + 0x4))->search(lbl_804774C8[56 + j]);
                pane->setAlpha((u8)(f30 * (f32)self[0xdb + j]));
            }
            goto done;
        case 1:
            for (j = 0; j < 20; j++) {
                J2DPane* pane = ((J2DScreen*)*(void**)(self + 0x4))->search(lbl_804774C8[73 + j]);
                pane->setAlpha((u8)(f30 * (f32)self[0xec + j]));
            }
            break;
        }
    }
done:
    if (*(s16*)(self + 0x9c) > 15) {
        b = fn_80402940(*(void**)(self + 0x30), 0xf, lbl_8054361C, 0, lbl_80543604);
        n = *(s16*)(self + 0x9c) - 15;
        if (n > 15) {
            n = 15;
        }
        f30 = (f32)(n * n) / lbl_80543624;
        for (j = 0; j < 6; j++) {
            J2DPane* pane = ((J2DScreen*)*(void**)(self + 0x4))->search(lbl_804774C8[50 + j]);
            pane->setAlpha((u8)(f30 * (f32)self[0xd5 + j]));
        }
    }
    if (*(s16*)(self + 0x9c) > 20) {
        c = fn_80402940(*(void**)(self + 0x5c), 0x19, lbl_8054362C, 0, lbl_80543604);
        n = *(s16*)(self + 0x9c) - 20;
        if (n > 25) {
            n = 25;
        }
        fn_80440E0C(lbl_8053AED8, (f32)(n * n) / lbl_80543630);
    }
    if (a && b && c) {
        *(s32*)(self + 0x8c) = 0;
        *(s32*)(self + 0x84) = 1;
        *(s32*)(self + 0x90) = 1;
    }
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

extern "C" void fn_803DF9E8(void* self_) {
    u8* self = (u8*)self_;
    *(s32*)(self + 0x88) = 0;
    *(s32*)(self + 0x8c) = 0;
    *(s32*)(self + 0x90) = 0;
    *(s16*)(self + 0x9c) = 0;
    *(f32*)(self + 0x7c) = lbl_80543604;
    *(f32*)(self + 0x78) = lbl_80543604;
    *(s16*)(self + 0x9a) = 0;
    *(s16*)(self + 0x98) = 0x3c;
    self[0xa1] = 0;
    for (s32 i = 0; i < 2; i++) {
        void* a = *(void**)(self + 0x34 + i * 4);
        *(u8*)(*(u8**)((u8*)a + 4) + 0xb0) = 1;
        fn_80402E08(a, lbl_80543614, lbl_80543604);
        *(s16*)((u8*)*(void**)(self + 0x34 + i * 4) + 0x20) = 0;
        void* b = *(void**)(self + 0x44 + i * 4);
        *(u8*)(*(u8**)((u8*)b + 4) + 0xb0) = 1;
        fn_80402E08(b, lbl_80543614, lbl_80543604);
        *(s16*)((u8*)*(void**)(self + 0x44 + i * 4) + 0x20) = 0;
    }
    *(u8*)(*(u8**)(*(u8**)(self + 0x30) + 4) + 0xb0) = 1;
    fn_80402E08(*(void**)(self + 0x30), lbl_80543614, lbl_8054361C);
    *(s16*)((u8*)*(void**)(self + 0x30) + 0x22) = 0;
    fn_80402E08(*(void**)(self + 0x5c), lbl_80543604, lbl_8054362C);
    *(s16*)((u8*)*(void**)(self + 0x5c) + 0x22) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x40) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x14) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x18) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x1c) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x20) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x24) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x28) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x2c) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x50) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x54) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x58) + 4) + 0xb0) = 0;
    void* mgr = *(void**)(self + 0x8);
    void* r = ((void* (*)(void*, void*, s32, s32))((*(void***)mgr)[0x3c / 4]))(mgr, *(void**)(self + 0x5c), 0x50, 0x696d3031);
    ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, 0);
    mgr = *(void**)(self + 0x8);
    r = ((void* (*)(void*, void*, s32, s32))((*(void***)mgr)[0x3c / 4]))(mgr, (void*)0x696d0000, 0x50, 0x696d3032);
    ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, 0);
    mgr = *(void**)(self + 0x8);
    r = ((void* (*)(void*, void*, s32, s32))((*(void***)mgr)[0x3c / 4]))(mgr, (void*)0x696d0000, 0x50, 0x696d3131);
    ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, 0);
    mgr = *(void**)(self + 0x8);
    r = ((void* (*)(void*, void*, s32, s32))((*(void***)mgr)[0x3c / 4]))(mgr, (void*)0x696d0000, 0x50, 0x696d3132);
    ((void (*)(void*, s32))((*(void***)r)[0x24 / 4]))(r, 0);
    *(s32*)(self + 0x84) = 0;
    *(s32*)(self + 0x68) = 2;
}

extern "C" u8 lbl_804B0688[];
extern "C" void getTotalFreeSize__7JKRHeapFv(void*);
void __dl__FPv(void*);
extern "C" void* fn_803DFC6C(u8* self, s16 param_2) {
    void* obj;
    s32 i;

    if (self != 0) {
        *(void**)self = lbl_804B0688;
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 8));
        if (self[0xa0] == 2) {
            fn_80427D94(*(SeqVoice**)(self + 0x64));
            self[0xa0] = 0;
        }
        obj = *(void**)(self + 0x60);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x60) = 0;
        obj = *(void**)(self + 0x64);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x64) = 0;
        obj = *(void**)(self + 0x4);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x4) = 0;
        obj = *(void**)(self + 0x8);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x8) = 0;
        for (i = 0; i < 7; i++) {
            obj = *(void**)(self + 0x14 + i * 4);
            if (obj != 0) {
                ((FsaDisposable*)obj)->del(1);
            }
            *(void**)(self + 0x14 + i * 4) = 0;
        }
        obj = *(void**)(self + 0x30);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x30) = 0;
        for (i = 0; i < 2; i++) {
            obj = *(void**)(self + 0x34 + i * 4);
            if (obj != 0) {
                ((FsaDisposable*)obj)->del(1);
            }
            *(void**)(self + 0x34 + i * 4) = 0;
        }
        obj = *(void**)(self + 0x40);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x40) = 0;
        for (i = 0; i < 2; i++) {
            obj = *(void**)(self + 0x44 + i * 4);
            if (obj != 0) {
                ((FsaDisposable*)obj)->del(1);
            }
            *(void**)(self + 0x44 + i * 4) = 0;
        }
        for (i = 0; i < 2; i++) {
            obj = *(void**)(self + 0x50 + i * 4);
            if (obj != 0) {
                ((FsaDisposable*)obj)->del(1);
            }
            *(void**)(self + 0x50 + i * 4) = 0;
        }
        obj = *(void**)(self + 0x58);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x58) = 0;
        obj = *(void**)(self + 0x10);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x10) = 0;
        obj = *(void**)(lbl_80529DEC + 0x2c);
        ((FsaDisposable*)obj)->v3();
        lbl_8053ADD0 = 0;
        if (param_2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

