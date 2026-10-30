// TU 0x8042e964-0x80432638.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include "JSystem/JKernel/JKRHeap.h"


#include "JSystem/J2D/J2DScreen.h"
#include <string.h>

struct MessageEntry8042 { s32 offset; s32 size; };
struct MessageTable8042 { s32 header[4]; MessageEntry8042 entries[1]; };
struct T8042_PaneAnim {
    u8 pad0[0x22];
    s16 f22;
};

struct T8042_Vis {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void set(int v);
};

struct T8042_Alpha {
    u8 pad0[0x4];
    T8042_Vis* vis;
    u8 pad8[0x26 - 0x8];
    s16 f26;
    u8 f28;
};

struct T8042_Grc {
    u8 pad0[0x10];
    const J2DGrafContext* ctx;
};

struct T8042EB14 {
    void* vt;
    J2DScreen* screen;
    T8042_PaneAnim* anim;
    T8042_Alpha* alpha;
    s16 timer;
    u8 active;
};

extern "C" {
void fn_80402E08(void* p, f32 x, f32 y);
u8 fn_80402940(void* p, int a, f32 x, f32 y, int b);
void fn_80402628(void* p, int a, int b, int c);
void fn_8013B490(void* p);
f32 fn_803832BC(char* s, s32 a, s32 b, s32 c, s32 d);
extern T8042_Grc* lbl_8053AB10;
extern char lbl_8048F390[];
extern "C" char lbl_80543B3C;
extern "C" char lbl_80543B44;
extern "C" char lbl_80543B4C;
extern "C" char lbl_80543B54;
extern "C" char lbl_80543B5C;
extern "C" char lbl_80543B64;
extern "C" char lbl_80543B6C;
extern "C" char lbl_80543B74;
extern "C" char lbl_80543B7C;
extern "C" char lbl_80543B84;
extern "C" char lbl_80543B8C;
extern "C" f32 lbl_80543AF8;
extern "C" f32 lbl_80543B18;
extern "C" f32 lbl_80543B28;
extern "C" const f32 lbl_80543B94;
extern "C" f64 lbl_80543B10;

void fn_8042EB14(T8042EB14* self) {
    self->timer = 0;
    self->active = 0;
}

void fn_8042EB24(T8042EB14* self) {
    fn_80402E08(self->anim, 0.0f, -480.0f);
    self->anim->f22 = 0;
    self->alpha->vis->set(0);
    self->alpha->f26 = 0;
    self->timer = 0;
    self->active = 0;
}

void fn_8042EB98(T8042EB14* self) {
    if (self->active) {
        fn_8013B490(lbl_8053AB10);
        self->screen->draw(0.0f, 0.0f, lbl_8053AB10->ctx);
    }
}

BOOL fn_8042EBEC(T8042EB14* self) {
    if (self->active) {
        u8 r = fn_80402940(self->anim, 0xa, 0.0f, -480.0f, 0);
        fn_80402628(self->alpha, 0xa, self->alpha->f28, 0);
        if (!r) {
            return FALSE;
        }
        self->timer = 0;
        self->active = 0;
    }
    return TRUE;
}

BOOL fn_8042EC7C(T8042EB14* self) {
    if (self->active) {
        self->timer++;
        if (self->timer < 8) {
            int t = 8 - self->timer;
            fn_80402E08(self->anim, 0.0f, -500.0f * (f32)(t * t) / 64.0f + 26.0f);
            fn_80402628(self->alpha, 8, 0, self->alpha->f28);
        } else {
            int t = 11 - self->timer;
            fn_80402E08(self->anim, 0.0f, 26.0f * (f32)(t * t) / 9.0f);
            self->alpha->vis->set(self->alpha->f28);
            if (self->timer >= 11) {
                self->anim->f22 = 0;
                self->alpha->f26 = 0;
                return TRUE;
            }
        }
    }
    return FALSE;
}

BOOL fn_8042EDAC(T8042EB14* self, s32 a, u8 b) {
    if (!self->active) {
        fn_803832BC(((J2DTextBox*)self->screen->search('Tmmt01'))->getStringPtr(), a, b, 0, 0);
        fn_803832BC(((J2DTextBox*)self->screen->search('Tmmt02'))->getStringPtr(), a, b, 0, 0);
        fn_80402E08(self->anim, 0.0f, -480.0f);
        self->anim->f22 = 0;
        self->alpha->vis->set(0);
        self->alpha->f26 = 0;
        self->timer = 0;
        self->active = 1;
        return TRUE;
    }
    return FALSE;
}
}

// ---- from src/Game/AttachmentSlotHelper_dtor_8042EEC8.cpp ----
// fn_8042EEC8: real destructor for the small (0x14-byte) "attachment-
// slot helper" class (vtable lbl_804B1600). Releases 3 virtual sub-
// objects at this->0x4/0x8/0xc via own virtual slot 0 (byte offset
// 0x8), clearing each afterward, then zeroes the global
// lbl_8053AEC4, then optionally self-frees via __dl__FPv if the
// caller flag (sign-extended) is positive. See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B1600[];
extern s32 lbl_8053AEC4;

struct Slot0 {
    virtual void slot0(s32 arg);
};

extern "C" void* fn_8042EEC8(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B1600;
        void* p1 = *(void**)((char*)this_ + 0x4);
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        *(void**)((char*)this_ + 0x4) = 0;
        void* p2 = *(void**)((char*)this_ + 0x8);
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        *(void**)((char*)this_ + 0x8) = 0;
        void* p3 = *(void**)((char*)this_ + 0xc);
        if (p3 != 0) {
            ((Slot0*)p3)->slot0(1);
        }
        *(void**)((char*)this_ + 0xc) = 0;
        lbl_8053AEC4 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct T8042_Random {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct T8042_Game { u8 pad[0xb4]; T8042_Random rnd; };
extern "C" T8042_Game* lbl_8053AAF8;
extern void* lbl_8053AD78;

struct T80431_Pane {
    u8 pad0[0x20];
    f32 w;
    f32 h;
    f32 sw;
    f32 sh;
    u8 pad30[0x118 - 0x30];
    f32 f118;
};

static inline f32 centerOffset80431(f32 width, const f32 paneWidth, const f32 offset) {
    return (width - paneWidth) / 2.0f + offset;
}

struct T80431_Owner {
    void* vt;
    u8 pad4[0x4];
    J2DScreen* screen;
    T8042_PaneAnim* anim;
    u8 pad10[0xb8 - 0x10];
    f32 width;
    f32 choiceWidth[4];
    f32 choiceX[3];
    f32 choiceLine[3];
    s32 lineCount;
    s16 timer;
    u8 padea;
    u8 feb;
    u8 active;
};

extern "C" {

f32 fn_80430368(void* self, u8 type, s32 count, char* buf) {
    char* s = lbl_8048F390;
    switch (type) {
    case 1:
        if (count != 1) {
            strcat(buf, s + 0x38);
        } else {
            strcat(buf, s + 0x44);
        }
        break;
    case 2:
        if (count != 1) {
            strcat(buf, &lbl_80543B3C);
        } else {
            strcat(buf, &lbl_80543B44);
        }
        break;
    case 3:
        if (count != 1) {
            strcat(buf, s + 0x50);
        } else {
            strcat(buf, &lbl_80543B4C);
        }
        break;
    case 4:
        if (count != 1) {
            strcat(buf, &lbl_80543B54);
        } else {
            strcat(buf, &lbl_80543B5C);
        }
        break;
    case 5:
        if (count != 1) {
            strcat(buf, s + 0x5c);
        } else {
            strcat(buf, &lbl_80543B64);
        }
        break;
    case 6:
        if (count != 1) {
            strcat(buf, &lbl_80543B6C);
        } else {
            strcat(buf, &lbl_80543B74);
        }
        break;
    case 7:
        if (count != 1) {
            strcat(buf, &lbl_80543B7C);
        } else {
            strcat(buf, &lbl_80543B84);
        }
        break;
    case 8:
        if (count != 1) {
            strcat(buf, s + 0x68);
        } else {
            strcat(buf, &lbl_80543B8C);
        }
        break;
    case 9:
        if (count != 1) {
            strcat(buf, s + 0x74);
        } else {
            strcat(buf, s + 0x84);
        }
        break;
    }
    return 0.0f;
}

#pragma push
#pragma dont_inline on
f32 fn_80430518(void* self, u8 type, s32 count, f32 scale) {
    f32 width = lbl_80543AF8;
    switch (type) {
    case 1: {
        JUTFont::TWidth w0;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(160, &w0);
        width += scale * (f32)(int)w0.w1;
        JUTFont::TWidth w1;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(70, &w1);
        width += scale * (f32)(int)w1.w1;
        JUTFont::TWidth w2;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(111, &w2);
        width += scale * (f32)(int)w2.w1;
        JUTFont::TWidth w3;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(114, &w3);
        width += scale * (f32)(int)w3.w1;
        JUTFont::TWidth w4;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(99, &w4);
        width += scale * (f32)(int)w4.w1;
        JUTFont::TWidth w5;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(101, &w5);
        width += scale * (f32)(int)w5.w1;
        JUTFont::TWidth w6;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(160, &w6);
        width += scale * (f32)(int)w6.w1;
        JUTFont::TWidth w7;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(71, &w7);
        width += scale * (f32)(int)w7.w1;
        JUTFont::TWidth w8;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(101, &w8);
        width += scale * (f32)(int)w8.w1;
        JUTFont::TWidth w9;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(109, &w9);
        width += scale * (f32)(int)w9.w1;
        if (count != 1) {
        JUTFont::TWidth w10;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(115, &w10);
        width += scale * (f32)(int)w10.w1;
        }
        break;
    }
    case 2: {
        JUTFont::TWidth w11;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(160, &w11);
        width += scale * (f32)(int)w11.w1;
        JUTFont::TWidth w12;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(67, &w12);
        width += scale * (f32)(int)w12.w1;
        JUTFont::TWidth w13;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(117, &w13);
        width += scale * (f32)(int)w13.w1;
        JUTFont::TWidth w14;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(99, &w14);
        width += scale * (f32)(int)w14.w1;
        JUTFont::TWidth w15;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(99, &w15);
        width += scale * (f32)(int)w15.w1;
        JUTFont::TWidth w16;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(111, &w16);
        width += scale * (f32)(int)w16.w1;
        if (count != 1) {
        JUTFont::TWidth w17;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(115, &w17);
        width += scale * (f32)(int)w17.w1;
        }
        break;
    }
    case 3: {
        JUTFont::TWidth w18;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(160, &w18);
        width += scale * (f32)(int)w18.w1;
        JUTFont::TWidth w19;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(98, &w19);
        width += scale * (f32)(int)w19.w1;
        JUTFont::TWidth w20;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(97, &w20);
        width += scale * (f32)(int)w20.w1;
        JUTFont::TWidth w21;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(100, &w21);
        width += scale * (f32)(int)w21.w1;
        JUTFont::TWidth w22;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(100, &w22);
        width += scale * (f32)(int)w22.w1;
        if (count == 1) {
        JUTFont::TWidth w23;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(121, &w23);
        width += scale * (f32)(int)w23.w1;
        } else {
        JUTFont::TWidth w24;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(105, &w24);
        width += scale * (f32)(int)w24.w1;
        JUTFont::TWidth w25;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(101, &w25);
        width += scale * (f32)(int)w25.w1;
        JUTFont::TWidth w26;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(115, &w26);
        width += scale * (f32)(int)w26.w1;
        }
        break;
    }
    case 4: {
        JUTFont::TWidth w27;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(160, &w27);
        width += scale * (f32)(int)w27.w1;
        JUTFont::TWidth w28;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(116, &w28);
        width += scale * (f32)(int)w28.w1;
        JUTFont::TWidth w29;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(105, &w29);
        width += scale * (f32)(int)w29.w1;
        JUTFont::TWidth w30;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(109, &w30);
        width += scale * (f32)(int)w30.w1;
        JUTFont::TWidth w31;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(101, &w31);
        width += scale * (f32)(int)w31.w1;
        if (count != 1) {
        JUTFont::TWidth w32;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(115, &w32);
        width += scale * (f32)(int)w32.w1;
        }
        break;
    }
    case 5: {
        JUTFont::TWidth w33;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(160, &w33);
        width += scale * (f32)(int)w33.w1;
        JUTFont::TWidth w34;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(115, &w34);
        width += scale * (f32)(int)w34.w1;
        JUTFont::TWidth w35;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(121, &w35);
        width += scale * (f32)(int)w35.w1;
        JUTFont::TWidth w36;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(115, &w36);
        width += scale * (f32)(int)w36.w1;
        JUTFont::TWidth w37;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(116, &w37);
        width += scale * (f32)(int)w37.w1;
        JUTFont::TWidth w38;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(101, &w38);
        width += scale * (f32)(int)w38.w1;
        JUTFont::TWidth w39;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(109, &w39);
        width += scale * (f32)(int)w39.w1;
        if (count != 1) {
        JUTFont::TWidth w40;
        (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(115, &w40);
        width += scale * (f32)(int)w40.w1;
        }
        break;
    }
    }
    return width;
}
#pragma pop

void fn_804310BC(T80431_Owner* self) {
    self->timer = 0;
    self->active = 0;
}

void fn_804310CC(T80431_Owner* self) {
    self->screen->search('Pwcur01')->hide();
    self->screen->search('Pwcur02')->hide();
    fn_80402E08(self->anim, 0.0f, -480.0f);
    self->anim->f22 = 0;
    self->timer = 0;
    self->feb = 0;
    self->active = 0;
}

extern "C" s16 lbl_80543AE8[3];
extern "C" s16 lbl_80543AF0[3];
BOOL fn_80431174(T80431_Owner* self, u8 flag) {
    if (self->screen->search('Pwcur01')->isVisible()) {
        f32 y;
        f32 x;
        self->timer -= 1;
        if (self->timer <= 0) {
            T8042_Game* g = lbl_8053AAF8;
            self->timer = (s32)(lbl_80543B94 * g->rnd.get_ufloat_1()) + 10;
            if (self->feb < 2) {
                self->feb++;
            } else {
                self->feb = 0;
            }
        }
        T80431_Pane* tb = (T80431_Pane*)self->screen->search('Twt01');
        f32 width;
        f32 bx = self->screen->search('Twt01')->getBounds()->i.x;
        width = tb->sw;
        width -= tb->w;
        x = width * lbl_80543B18 + bx;
        tb = (T80431_Pane*)self->screen->search('Twt01');
        f32 height;
        f32 by = self->screen->search('Twt01')->getBounds()->i.y;
        height = tb->sh;
        height -= tb->h;
        y = height * lbl_80543B18 + by;
        if (flag == 0) {
            T80431_Pane* cur = (T80431_Pane*)self->screen->search('Pwcur01');
            f32 cw;
            f32 space;
            space = self->choiceWidth[0];
            space -= self->choiceWidth[3];
            cw = cur->sw - cur->w;
            cw = space - cw;
            x += cw * lbl_80543B18;
        } else {
            T80431_Pane* cur = (T80431_Pane*)self->screen->search('Pwcur01');
            f32 space = self->choiceWidth[1] - self->choiceWidth[3];
            f32 cw = cur->sw - cur->w;
            f32 offset = self->choiceX[1] - self->choiceX[0];
            f32 half = 0.5f;
            x += centerOffset80431(space, cw, offset);
        }
        T80431_Pane* pcur = (T80431_Pane*)self->screen->search('Pwcur01');
        f32 hdiff = pcur->sh - pcur->h;
        f32 fa = ((T80431_Pane*)self->screen->search('Twt01'))->f118;
        tb = (T80431_Pane*)self->screen->search('Twt01');
        f32 sizeOffset = (fa - hdiff) / 2.0f;
        f32 lines = (f32)self->lineCount;
        f32 lineOffset = ((f32*)((char*)self + 0xd8))[flag] - lines / 2.0f - lbl_80543B28;
        y += lineOffset * tb->f118 + sizeOffset;
        self->screen->search('Pwcur01')->move(x, y);
        self->screen->search('Pwcur02')->move(x, y);
        T80431_Pane* pa = (T80431_Pane*)self->screen->search('Pwcur01');
        f32 hh = pa->sh - pa->h;
        T80431_Pane* pb = (T80431_Pane*)self->screen->search('Pwcur01');
        J2DPane* rotate1 = self->screen->search('Pwcur01');
        rotate1->rotate(lbl_80543B18 * (pb->sw - pb->w), lbl_80543B18 * hh, J2DROTATE_Z, (f32)lbl_80543AE8[self->feb]);
        T80431_Pane* pa2 = (T80431_Pane*)self->screen->search('Pwcur02');
        f32 hh2 = pa2->sh - pa2->h;
        T80431_Pane* pb2 = (T80431_Pane*)self->screen->search('Pwcur02');
        J2DPane* rotate2 = self->screen->search('Pwcur02');
        rotate2->rotate(lbl_80543B18 * (pb2->sw - pb2->w), lbl_80543B18 * hh2, J2DROTATE_Z, (f32)lbl_80543AF0[self->feb]);
    }
    return FALSE;
}

void fn_804316EC(T80431_Owner* self) {
    if (self->active) {
        fn_8013B490(lbl_8053AB10);
        self->screen->draw(0.0f, 0.0f, lbl_8053AB10->ctx);
    }
}

BOOL fn_80431740(T80431_Owner* self) {
    if (self->active) {
        if (!fn_80402940(self->anim, 0xa, 0.0f, 480.0f, 0)) {
            return FALSE;
        }
        self->timer = 0;
        self->active = 0;
    }
    return TRUE;
}

BOOL fn_804317AC(T80431_Owner* self) {
    if (self->active) {
        self->timer++;
        if (self->timer < 10) {
            int t = 10 - self->timer;
            fn_80402E08(self->anim, 0.0f, 20.0f + -500.0f * (f32)(t * t) / 100.0f);
        } else {
            int t = 13 - self->timer;
            fn_80402E08(self->anim, 0.0f, 20.0f * (f32)(t * t) / 9.0f);
            if (self->timer >= 13) {
                T8042_Game* g = lbl_8053AAF8;
                self->timer = (s32)(11.0f * g->rnd.get_ufloat_1()) + 10;
                self->anim->f22 = 0;
                return TRUE;
            }
        }
    }
    return FALSE;
}

void fn_8042EF9C(T80431_Owner* self, char* str, s32 a, s32 b);
void fn_8042F6DC(T80431_Owner* self);

BOOL fn_80431900(T80431_Owner* self, s32 a, s32 b, u8* out) {
    if (!self->active) {
        fn_8042EF9C(self, ((J2DTextBox*)self->screen->search('Twt01'))->getStringPtr(), a, b);
        if (out != NULL) {
            self->screen->search('Pwcur01')->show();
            self->screen->search('Pwcur02')->show();
        } else {
            self->screen->search('Pwcur01')->hide();
            self->screen->search('Pwcur02')->hide();
        }
        fn_80402E08(self->anim, 0.0f, -480.0f);
        self->anim->f22 = 0;
        self->timer = 0;
        self->feb = 0;
        self->active = 1;
        fn_8042F6DC(self);
        if (out != NULL) {
            *out = self->padea;
        }
        return TRUE;
    }
    return FALSE;
}

BOOL fn_80431A9C(T80431_Owner* self, s32 a, s32 b, u8* out) {
    if (!self->active) {
        fn_8042EF9C(self, ((J2DTextBox*)self->screen->search('Twt01'))->getStringPtr(), a, b);
        if (out != NULL) {
            self->screen->search('Pwcur01')->show();
            self->screen->search('Pwcur02')->show();
        } else {
            self->screen->search('Pwcur01')->hide();
            self->screen->search('Pwcur02')->hide();
        }
        fn_80402E08(self->anim, 0.0f, -480.0f);
        self->anim->f22 = 0;
        self->timer = 0;
        self->feb = 0;
        self->active = 1;
        fn_8042F6DC(self);
        if (out != NULL) {
            *out = self->padea;
        }
        return TRUE;
    }
    return FALSE;
}

extern void* lbl_804B1634[];
struct T80431C38 {
    u8 pad0[0x10];
    Slot0* a[5];
    Slot0* b[5];
};
extern s32 lbl_8053AEC0;

extern "C" void* lbl_804AF86C[];
struct T80431_Res {
    void* vt;
    u8* data;
    u8 pad[0x24];
    T80431_Res() { vt = lbl_804AF86C; }
};

struct T80431_Helper {
    void* vt;
    J2DScreen* screen;
    void* objA;
    void* objB;
    s16 timer;
    u8 flag;
};

struct T80431_Points { JGeometry::TVec2<s16> points[16]; };
#pragma push
#pragma new_may_return_null off
static inline void InitMessagePoints(void* p) { new (p) T80431_Points; }
#pragma pop
extern "C" char lbl_8048F424[];
struct T80431D84 {
    void* vt;
    T80431_Helper* helper;
    J2DScreen* screen;
    void* objC;
    Slot0* a[5];
    Slot0* b[5];
    JGeometry::TVec2<s16> c[16];
    JGeometry::TVec2<s16> d[16];
    u8 pad0b8[0xe8 - 0xb8];
    s16 timer;
    u8 flag;
};

typedef void* (*VtSearch)(void*, u32, u32, u32);
typedef void (*VtSet)(void*, void*);
extern "C" void* __nw__FUl(u32 size);
extern "C" void fn_80402F04(void* obj, void* pane);
extern "C" u8 lbl_80529DEC[];
extern "C" void* lbl_804AF86C[];
extern void* lbl_8053AD78;
static inline JUTFont* MessageFont() { return *(JUTFont**)((u8*)lbl_8053AD78+0x154); }

void* fn_80431C38(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B1634;
        void* p1 = *(void**)((char*)this_ + 0x4);
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        *(void**)((char*)this_ + 0x4) = 0;
        void* p2 = *(void**)((char*)this_ + 0x8);
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        *(void**)((char*)this_ + 0x8) = 0;
        void* p3 = *(void**)((char*)this_ + 0xc);
        if (p3 != 0) {
            ((Slot0*)p3)->slot0(1);
        }
        *(void**)((char*)this_ + 0xc) = 0;
        T80431C38* o = (T80431C38*)this_;
        for (int i = 0; i < 5; i++) {
            if (o->a[i] != 0) {
                o->a[i]->slot0(1);
            }
            o->a[i] = 0;
            if (o->b[i] != 0) {
                o->b[i]->slot0(1);
            }
            o->b[i] = 0;
        }
        lbl_8053AEC0 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#pragma placement_new_check off
extern "C" void __construct_array(void*, void*, void*, u32,u32);
extern "C" void __ct__Q29JGeometry8TVec2_s_Fv();
extern "C" T80431D84* fn_80431D84(T80431D84* self) {
self->vt = lbl_804B1634;
__construct_array(self->c, (void*)__ct__Q29JGeometry8TVec2_s_Fv, 0, 4,16);
__construct_array(self->d, (void*)__ct__Q29JGeometry8TVec2_s_Fv, 0, 4,16);
lbl_8053AEC0 = (s32)self;
T80431_Helper* h = (T80431_Helper*)__nw__FUl(0x14);
if(h) {
 h->vt = lbl_804B1600; lbl_8053AEC4 = (s32)h;
 h->screen = new J2DScreen;
 h->screen->setPriority(lbl_8048F390,0x1100000,*(JKRArchive**)(lbl_80529DEC+0x20));
 h->objA = new T80431_Res;
 fn_80402F04(h->objA,h->screen->search('Pmmwk02'));
 h->objB = new T80431_Res;
 fn_80402F04(h->objB,h->screen->search('Pbl01'));
 ((J2DTextBox*)h->screen->search('Tmmt01'))->setFont(MessageFont());
 ((J2DTextBox*)h->screen->search('Tmmt02'))->setFont(MessageFont());
 h->timer=0; h->flag=0;
}
self->helper=h;
self->screen=new J2DScreen;
self->screen->setPriority(lbl_8048F424,0x1100000,*(JKRArchive**)(lbl_80529DEC+0x20));
self->objC = (Slot0*)new T80431_Res;
fn_80402F04(self->objC,self->screen->search('Ndata01'));
self->a[0] = (Slot0*)new T80431_Res;
fn_80402F04(self->a[0],self->screen->search('Pwbb01'));
self->a[1] = (Slot0*)new T80431_Res;
fn_80402F04(self->a[1],self->screen->search('Pwbb02'));
self->a[2] = (Slot0*)new T80431_Res;
fn_80402F04(self->a[2],self->screen->search('Pwbb03'));
self->a[3] = (Slot0*)new T80431_Res;
fn_80402F04(self->a[3],self->screen->search('Pwbb04'));
self->a[4] = (Slot0*)new T80431_Res;
fn_80402F04(self->a[4],self->screen->search('Pwbb05'));
self->b[0] = (Slot0*)new T80431_Res;
fn_80402F04(self->b[0],self->screen->search('Pwb01'));
self->b[1] = (Slot0*)new T80431_Res;
fn_80402F04(self->b[1],self->screen->search('Pwb02'));
self->b[2] = (Slot0*)new T80431_Res;
fn_80402F04(self->b[2],self->screen->search('Pwb03'));
self->b[3] = (Slot0*)new T80431_Res;
fn_80402F04(self->b[3],self->screen->search('Pwb04'));
self->b[4] = (Slot0*)new T80431_Res;
fn_80402F04(self->b[4],self->screen->search('Pwb05'));
((J2DTextBox*)self->screen->search('Twt01'))->setFont(MessageFont());
T80431D84* dst = self;
T80431D84* src = self;
int offset;
for(int i=0;i<4;i++) {
 for(int j=0;j<4;j++) {
offset = (u8)j *4;
 dst->c[j].set(*(JGeometry::TVec2<s16>*)((u8*)*(void**)((u8*)src->a[0]+4)+0x112+offset));
 dst->d[j].set(*(JGeometry::TVec2<s16>*)((u8*)*(void**)((u8*)src->b[0]+4)+0x112+offset));
 }
dst=(T80431D84*)((u8*)dst+16); src=(T80431D84*)((u8*)src+4);
}
self->timer=0; *((u8*)self+0xec)=0; return self;
}
#pragma placement_new_check reset
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "stdio.h"
#include "JSystem/J2D/J2DPicture.h"
extern "C" char lbl_8048F3AC[];
extern "C" const char lbl_80543B20[8];
extern "C" f32 fn_80430518(void*,u8,s32,f32);
extern "C" f32 lbl_80543B1C;
#pragma opt_propagation reset
extern "C" void fn_8042EF9C(T80431_Owner* self, char* out_, s32 message, s32 count) {
int code;
char* out = out_;
char* p;
int digit;
s32 idx;
char* text;
u8 choice;
JUTFont::TWidth wa,wb,wc,wd,we;
char chunk[3];
char padding[16];
f32 widths[10];
char* resource=(char*)(*(JKRArchive**)((u8*)lbl_8053AAF8+0xa8))->getResource(0x3f3f3f3f,lbl_8048F3AC);
char* table=resource+0x20;
MessageTable8042* mt=(MessageTable8042*)table;
text=table+mt->header[1]+mt->entries[message].offset+8;
f32 size=((J2DTextBox*)self->screen->search('Twt01'))->mFontSize.x;
f32 scale=size/(f32)MessageFont()->getCellWidth();
MessageFont()->getCellHeight();
self->padea=0xff;
self->lineCount=1;
self->width=0.0f;
self->choiceWidth[0]=0.0f;
self->choiceWidth[1]=0.0f;
self->choiceWidth[2]=0.0f;
self->choiceWidth[3]=0.0f;
f32 width=0.0f;
f32 spaces=0.0f;
for(int i=0;i<10;i++) widths[i]=0.0f;
idx=0;
code=0;
choice=0;
count &= 0xff;
digit=count+'0';
while((p=text+idx,*p)!=0) {
int c=*p;
if(c=='\n') {
if(self->width<width) self->width=width;
widths[self->lineCount-1]=width;
self->lineCount++;
idx++;
width=0.0f;
} else if(c==0x1a) {
if(p[2]==2) {
char kind=p[4];
if(kind==0 || kind==10 || kind==18 || kind==25) {
if(choice==1) {self->choiceWidth[0]-=spaces; spaces=0.0f;}
if(choice<2) {self->choiceX[choice]=width;self->choiceLine[choice]=(f32)self->lineCount;choice++;}
} else if(kind==1 || kind==9 || kind==17 || kind==26) {
if(choice==1) {self->choiceWidth[0]-=spaces; spaces=0.0f;}
if(choice<2) {self->choiceX[choice]=width;self->choiceLine[choice]=(f32)self->lineCount;self->padea=choice;choice++;}
}
} else if(p[2]==3) {
code=digit;
MessageFont()->getWidthEntry(digit,&wa);
width+=scale*(f32)(int)wa.w1;
if(choice) {
MessageFont()->getWidthEntry(digit,&wb);
self->choiceWidth[choice-1]+=scale*(f32)(int)wb.w1;
}
f32 added=fn_80430518(self,(u8)p[5],count,scale);
width+=added;
if(choice) self->choiceWidth[choice-1]+=added;
}
idx+=p[1];
} else {
code=(u8)c;
idx++;
if(MessageFont()->isLeadByte(code)) {int next=(u8)text[idx];
code <<=8;
code |=next;idx++;}
MessageFont()->getWidthEntry(code,&wc);
width+=scale*(f32)(int)wc.w1;
if(choice) {
if(code==0x20 || code==0x8140) {
MessageFont()->getWidthEntry(code,&wd);
spaces+=scale*(f32)(int)wd.w1;
}
MessageFont()->getWidthEntry(code,&we);
self->choiceWidth[choice-1]+=scale*(f32)(int)we.w1;
}
}
}
widths[self->lineCount-1]=width;
if(self->width<width) self->width=width;
self->choiceWidth[3]=width;
self->lineCount=1;
idx=0;
chunk[0]=chunk[1]=chunk[2]=0;
out[0]=0;
int indent=(int)(0.5f*(428.0f-widths[self->lineCount-1])+0.5f);
if(indent>0) {snprintf(padding,15,lbl_80543B20,indent);strcat(out,padding);}
while((p=text+idx,*p)!=0) {
int c=*p;
if(c=='\n') {
chunk[0]=*p;chunk[1]=0;strcat(out,chunk);
self->lineCount++;idx++;
int indent=(int)(0.5f*(428.0f-widths[self->lineCount-1])+0.5f);
if(indent>0) {snprintf(padding,15,lbl_80543B20,indent);strcat(out,padding);}
} else if(c==0x1a) {
if((int)(u8)p[2]==3) {chunk[0]=digit;chunk[1]=0;code=digit;strcat(out,chunk);fn_80430368(self,(u8)p[5],count,out);}
idx+=p[1];
} else {
if(MessageFont()->isLeadByte(code)) {chunk[0]=p[0];chunk[1]=p[1];chunk[2]=0;strcat(out,chunk);idx+=2;}
else {chunk[0]=p[0];chunk[1]=0;strcat(out,chunk);idx++;}
}
}
chunk[0]=*p;chunk[1]=0;strcat(out,chunk);
}

extern "C" f32 lbl_80543B2C;
extern "C" void fn_80402CE0(void*,f32,f32);
extern "C" f32 lbl_80543B30;
extern "C" f32 lbl_80543B34;
extern "C" f32 lbl_80543B38;
#pragma opt_lifetimes off
void fn_8042F6DC(T80431_Owner* self) {
    u8* p=(u8*)self;
    f32 height;
    f32 width=lbl_80543B2C+self->width;
    T80431_Pane* text=(T80431_Pane*)self->screen->search('Twt01');
    height=(f32)self->lineCount*text->f118+lbl_80543B30;
    if(width<128.0f)width=128.0f;
    if(height<128.0f)height=128.0f;
    s16 repeatX=(s32)(lbl_80543B38+width)/128;
    s16 repeatY=(s32)(lbl_80543B38+height)/128;
    if(repeatX<=1)repeatX++;
    if(repeatY<=1)repeatY++;
    f32 scaleY;
    f32 scaleX;
    f32 scale;
    scale=(width+(*(f32*)(*(u8**)(p+0x24)+0x18)-*(f32*)(*(u8**)(p+0x34)+0x18)))/ *(f32*)(*(u8**)(p+0x24)+0x18);
    fn_80402CE0(*(u8**)(p+0x24),scale,lbl_80543B28);
    fn_80402CE0(*(u8**)(p+0x28),scale,lbl_80543B28);
    scaleX=width/ *(f32*)(*(u8**)(p+0x34)+0x18);
    scaleY=height/ *(f32*)(*(u8**)(p+0x34)+0x1c);
    fn_80402CE0(*(u8**)(p+0x2c),lbl_80543B28,scaleY);
    fn_80402CE0(*(u8**)(p+0x30),lbl_80543B28,scaleY);
    fn_80402CE0(*(u8**)(p+0x34),scaleX,scaleY);
    scaleX=(width+(*(f32*)(*(u8**)(p+0x10)+0x18)-*(f32*)(*(u8**)(p+0x34)+0x18)))/ *(f32*)(*(u8**)(p+0x10)+0x18);
    fn_80402CE0(*(u8**)(p+0x10),scaleX,lbl_80543B28);
    fn_80402CE0(*(u8**)(p+0x14),scaleX,lbl_80543B28);
    f32 outerWidth;
    f32 innerWidth=*(f32*)(*(u8**)(p+0x34)+0x18);
    outerWidth=*(f32*)(*(u8**)(p+0x20)+0x18);
    height=(height+(*(f32*)(*(u8**)(p+0x20)+0x1c)-*(f32*)(*(u8**)(p+0x34)+0x1c)))/ *(f32*)(*(u8**)(p+0x20)+0x1c);
    fn_80402CE0(*(u8**)(p+0x18),lbl_80543B28,height);
    fn_80402CE0(*(u8**)(p+0x1c),lbl_80543B28,height);
    fn_80402CE0(*(u8**)(p+0x20),(width+(outerWidth-innerWidth))/outerWidth,height);
    scaleX=*(f32*)(*(u8**)(p+0x34)+0x8)-(*(J2DPicture**)(*(u8**)(p+0x34)+4))->getBounds()->i.x;
    fn_80402E08(*(u8**)(p+0x24),scaleX,lbl_80543AF8);
    fn_80402E08(*(u8**)(p+0x28),scaleX,((*(J2DPicture**)(*(u8**)(p+0x34)+4))->mBounds.f.y-(*(J2DPicture**)(*(u8**)(p+0x34)+4))->mBounds.i.y)-*(f32*)(*(u8**)(p+0x34)+0x1c));
    scaleX=*(f32*)(*(u8**)(p+0x34)+0xc)-(*(J2DPicture**)(*(u8**)(p+0x34)+4))->getBounds()->i.y;
    fn_80402E08(*(u8**)(p+0x2c),lbl_80543AF8,scaleX);
    fn_80402E08(*(u8**)(p+0x30),((*(J2DPicture**)(*(u8**)(p+0x34)+4))->mBounds.f.x-(*(J2DPicture**)(*(u8**)(p+0x34)+4))->mBounds.i.x)-*(f32*)(*(u8**)(p+0x34)+0x18),scaleX);
    scaleX=*(f32*)(*(u8**)(p+0x20)+0x8)-(*(J2DPicture**)(*(u8**)(p+0x20)+4))->getBounds()->i.x;
    fn_80402E08(*(u8**)(p+0x10),scaleX,lbl_80543AF8);
    fn_80402E08(*(u8**)(p+0x14),scaleX,((*(J2DPicture**)(*(u8**)(p+0x20)+4))->mBounds.f.y-(*(J2DPicture**)(*(u8**)(p+0x20)+4))->mBounds.i.y)-*(f32*)(*(u8**)(p+0x20)+0x1c));
    scaleX=*(f32*)(*(u8**)(p+0x20)+0xc)-(*(J2DPicture**)(*(u8**)(p+0x20)+4))->getBounds()->i.y;
    fn_80402E08(*(u8**)(p+0x18),lbl_80543AF8,scaleX);
    fn_80402E08(*(u8**)(p+0x1c),((*(J2DPicture**)(*(u8**)(p+0x20)+4))->mBounds.f.x-(*(J2DPicture**)(*(u8**)(p+0x20)+4))->mBounds.i.x)-*(f32*)(*(u8**)(p+0x20)+0x18),scaleX);
    JGeometry::TVec2<s16> a[4];
    JGeometry::TVec2<s16> b[4];
    a[0].x=((T80431D84*)p)->c[0].x; a[0].y=((T80431D84*)p)->c[0].y;
    b[0].x=((T80431D84*)p)->d[0].x; b[0].y=((T80431D84*)p)->d[0].y;
    a[1].x=((T80431D84*)p)->c[1].x; a[1].y=((T80431D84*)p)->c[1].y;
    b[1].x=((T80431D84*)p)->d[1].x; b[1].y=((T80431D84*)p)->d[1].y;
    a[2].x=((T80431D84*)p)->c[2].x; a[2].y=((T80431D84*)p)->c[2].y;
    b[2].x=((T80431D84*)p)->d[2].x; b[2].y=((T80431D84*)p)->d[2].y;
    a[3].x=((T80431D84*)p)->c[3].x; a[3].y=((T80431D84*)p)->c[3].y;
    b[3].x=((T80431D84*)p)->d[3].x; b[3].y=((T80431D84*)p)->d[3].y;
    a[1].x=(repeatX<<8);
    a[3].x=(repeatX<<8);
    b[1].x=(repeatX<<8);
    b[3].x=(repeatX<<8);
    (*(J2DPicture**)(*(u8**)(p+0x10)+4))->setTexCoord(a);
    (*(J2DPicture**)(*(u8**)(p+0x24)+4))->setTexCoord(b);
    a[0].x=((T80431D84*)p)->c[4].x; a[0].y=((T80431D84*)p)->c[4].y;
    b[0].x=((T80431D84*)p)->d[4].x; b[0].y=((T80431D84*)p)->d[4].y;
    a[1].x=((T80431D84*)p)->c[5].x; a[1].y=((T80431D84*)p)->c[5].y;
    b[1].x=((T80431D84*)p)->d[5].x; b[1].y=((T80431D84*)p)->d[5].y;
    a[2].x=((T80431D84*)p)->c[6].x; a[2].y=((T80431D84*)p)->c[6].y;
    b[2].x=((T80431D84*)p)->d[6].x; b[2].y=((T80431D84*)p)->d[6].y;
    a[3].x=((T80431D84*)p)->c[7].x; a[3].y=((T80431D84*)p)->c[7].y;
    b[3].x=((T80431D84*)p)->d[7].x; b[3].y=((T80431D84*)p)->d[7].y;
    a[0].x=(repeatX<<8);
    a[2].x=(repeatX<<8);
    b[0].x=(repeatX<<8);
    b[2].x=(repeatX<<8);
    (*(J2DPicture**)(*(u8**)(p+0x14)+4))->setTexCoord(a);
    (*(J2DPicture**)(*(u8**)(p+0x28)+4))->setTexCoord(b);
    a[0].x=((T80431D84*)p)->c[8].x; a[0].y=((T80431D84*)p)->c[8].y;
    b[0].x=((T80431D84*)p)->d[8].x; b[0].y=((T80431D84*)p)->d[8].y;
    a[1].x=((T80431D84*)p)->c[9].x; a[1].y=((T80431D84*)p)->c[9].y;
    b[1].x=((T80431D84*)p)->d[9].x; b[1].y=((T80431D84*)p)->d[9].y;
    a[2].x=((T80431D84*)p)->c[10].x; a[2].y=((T80431D84*)p)->c[10].y;
    b[2].x=((T80431D84*)p)->d[10].x; b[2].y=((T80431D84*)p)->d[10].y;
    a[3].x=((T80431D84*)p)->c[11].x; a[3].y=((T80431D84*)p)->c[11].y;
    b[3].x=((T80431D84*)p)->d[11].x; b[3].y=((T80431D84*)p)->d[11].y;
    a[2].x=(repeatY<<8);
    a[3].x=(repeatY<<8);
    b[2].x=(repeatY<<8);
    b[3].x=(repeatY<<8);
    (*(J2DPicture**)(*(u8**)(p+0x18)+4))->setTexCoord(a);
    (*(J2DPicture**)(*(u8**)(p+0x2c)+4))->setTexCoord(b);
    a[0].x=((T80431D84*)p)->c[12].x; a[0].y=((T80431D84*)p)->c[12].y;
    b[0].x=((T80431D84*)p)->d[12].x; b[0].y=((T80431D84*)p)->d[12].y;
    a[1].x=((T80431D84*)p)->c[13].x; a[1].y=((T80431D84*)p)->c[13].y;
    b[1].x=((T80431D84*)p)->d[13].x; b[1].y=((T80431D84*)p)->d[13].y;
    a[2].x=((T80431D84*)p)->c[14].x; a[2].y=((T80431D84*)p)->c[14].y;
    b[2].x=((T80431D84*)p)->d[14].x; b[2].y=((T80431D84*)p)->d[14].y;
    a[3].x=((T80431D84*)p)->c[15].x; a[3].y=((T80431D84*)p)->c[15].y;
    b[3].x=((T80431D84*)p)->d[15].x; b[3].y=((T80431D84*)p)->d[15].y;
    a[0].x=(repeatY<<8);
    a[1].x=(repeatY<<8);
    b[0].x=(repeatY<<8);
    b[1].x=(repeatY<<8);
    (*(J2DPicture**)(*(u8**)(p+0x1c)+4))->setTexCoord(a);
    (*(J2DPicture**)(*(u8**)(p+0x30)+4))->setTexCoord(b);
    if(self->padea!=0xff) {
    if(self->choiceWidth[0]>=self->choiceWidth[1]) {
        { T80431_Pane* cur=(T80431_Pane*)self->screen->search('Pwcur01'); self->screen->search('Pwcur01')->resize(self->choiceWidth[0],cur->sh-cur->h); }
        { T80431_Pane* cur=(T80431_Pane*)self->screen->search('Pwcur02'); self->screen->search('Pwcur02')->resize(self->choiceWidth[0],cur->sh-cur->h); }
    } else {
        { T80431_Pane* cur=(T80431_Pane*)self->screen->search('Pwcur01'); self->screen->search('Pwcur01')->resize(self->choiceWidth[1],cur->sh-cur->h); }
        { T80431_Pane* cur=(T80431_Pane*)self->screen->search('Pwcur02'); self->screen->search('Pwcur02')->resize(self->choiceWidth[1],cur->sh-cur->h); }
    }
        u8 flag=self->padea;
        f32 x;
        f32 y;
        T80431_Pane* tb = (T80431_Pane*)self->screen->search('Twt01');
        f32 width;
        f32 bx = self->screen->search('Twt01')->getBounds()->i.x;
        width = tb->sw;
        width -= tb->w;
        x = width * lbl_80543B18 + bx;
        tb = (T80431_Pane*)self->screen->search('Twt01');
        f32 height;
        f32 by = self->screen->search('Twt01')->getBounds()->i.y;
        height = tb->sh;
        height -= tb->h;
        y = height * lbl_80543B18 + by;
        if (flag == 0) {
            T80431_Pane* cur = (T80431_Pane*)self->screen->search('Pwcur01');
            f32 cw;
            f32 space;
            space = self->choiceWidth[0];
            space -= self->choiceWidth[3];
            cw = cur->sw - cur->w;
            cw = space - cw;
            x += cw * lbl_80543B18;
        } else {
            T80431_Pane* cur = (T80431_Pane*)self->screen->search('Pwcur01');
            f32 space = self->choiceWidth[1] - self->choiceWidth[3];
            f32 cw = cur->sw - cur->w;
            f32 offset = self->choiceX[1] - self->choiceX[0];
            f32 half = 0.5f;
            x += centerOffset80431(space, cw, offset);
        }
        T80431_Pane* pcur = (T80431_Pane*)self->screen->search('Pwcur01');
        f32 fa;
        f32 hdiff = pcur->sh - pcur->h;
        fa = ((T80431_Pane*)self->screen->search('Twt01'))->f118;
        tb = (T80431_Pane*)self->screen->search('Twt01');
        f32 sizeOffset = (fa - hdiff) / 2.0f;
        f32 lines = (f32)self->lineCount;
        f32 lineOffset = ((f32*)((char*)self + 0xd8))[flag] - lines / 2.0f - lbl_80543B28;
        y += lineOffset * tb->f118 + sizeOffset;
        self->screen->search('Pwcur01')->move(x, y);
        self->screen->search('Pwcur02')->move(x, y);
        T80431_Pane* pa = (T80431_Pane*)self->screen->search('Pwcur01');
        f32 hh = pa->sh - pa->h;
        T80431_Pane* pb = (T80431_Pane*)self->screen->search('Pwcur01');
        J2DPane* rotate1 = self->screen->search('Pwcur01');
        rotate1->rotate(lbl_80543B18 * (pb->sw - pb->w), lbl_80543B18 * hh, J2DROTATE_Z, (f32)lbl_80543AE8[self->feb]);
        T80431_Pane* pa2 = (T80431_Pane*)self->screen->search('Pwcur02');
        f32 hh2 = pa2->sh - pa2->h;
        T80431_Pane* pb2 = (T80431_Pane*)self->screen->search('Pwcur02');
        J2DPane* rotate2 = self->screen->search('Pwcur02');
        rotate2->rotate(lbl_80543B18 * (pb2->sw - pb2->w), lbl_80543B18 * hh2, J2DROTATE_Z, (f32)lbl_80543AF0[self->feb]);

    }
}
#pragma opt_lifetimes reset
