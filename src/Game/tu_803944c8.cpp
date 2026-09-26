// TU 0x803944c8-0x803a3484.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/JMessage/resource.h"
#include "JSystem/JMessage/processor.h"
#include "JSystem/JUtility/JUTFont.h"
#include <string.h>
#include <stdio.h>

// String scratch buffers (snprintf/strcat targets).
static char lbl_8050E518[0x10];
static char lbl_8050E528[0x10];
static char lbl_8050E538[0x10];
static char lbl_8050E548[0x10];

extern void* lbl_8053AD78;

extern "C" void fn_803944C8(void* this_, s32 a, u8 b, u8 c) {
    *(u8*)((char*)this_ + 0x3b1) = 1;
    *(s32*)((char*)lbl_8053AD78 + 0x48) = a;
    *(u8*)((char*)lbl_8053AD78 + 0xea) = b;
    *(u8*)((char*)lbl_8053AD78 + 0xeb) = c;
}

static inline void setTBFontSize(J2DTextBox* tb, J2DTextBox::TFontSize size) {
    f32 x = size.x;
    f32 y = size.y;
    tb->mFontSize.x = x > 0.0f ? x : 0.0f;
    tb->mFontSize.y = y > 0.0f ? y : 0.0f;
}

struct MsgPrint {
    u8 pad0[0x7c];
    f32 m7c;
    f32 m80;
    u8 pad84[0x2c8 - 0x84];
    f32 m2c8;
    void setScale(f32 s, f32 w) {
        m2c8 = s;
        m7c = s;
        m80 = w;
    }
};

struct MsgWindow {
    u8 pad0[0x14];
    MsgPrint* m14;
    u8 pad18[0x20 - 0x18];
    J2DScreen* screen;          // 0x20
    u8 pad24[0x60 - 0x24];
    f32 fontW;                  // 0x60
    f32 fontH;                  // 0x64
    u8 pad68[0xb0 - 0x68];
    f32 lineSpace;              // 0xb0
    f32 scale;                  // 0xb4
};

extern "C" void fn_803944EC(MsgWindow* w, f32 s) {
    w->scale = s;
    J2DTextBox::TFontSize fs;
    fs.x = w->fontW * s;
    fs.y = w->fontH * s;
    setTBFontSize((J2DTextBox*)w->screen->search('Tm01'), fs);
    ((J2DTextBox*)w->screen->search('Tm01'))->setLineSpace(w->lineSpace * s);
    setTBFontSize((J2DTextBox*)w->screen->search('Tm02'), fs);
    ((J2DTextBox*)w->screen->search('Tm02'))->setLineSpace(w->lineSpace * s);
    w->m14->setScale(s, w->fontW);
}

struct MsgColor {
    u8 r, g, b, a;
};

struct MsgDraw {
    u8 pad0[8];
    void* control;              // 0x08
    u8 padC[0x10 - 0xc];
    u8* m10;                    // 0x10
    u8 pad14[0x2c - 0x14];
    J2DScreen* screen;          // 0x2c
    u8 pad30[0x9c - 0x30];
    f32 y9c;                    // 0x9c
    u8 padA0[0xd8 - 0xa0];
    f32 xd8;                    // 0xd8
    u8 paddc[0xe0 - 0xdc];
    f32 xe0;                    // 0xe0
    f32 ye4;                    // 0xe4
    u8 pade8[0x154 - 0xe8];
    u32 col1;                   // 0x154
    u32 col2;                   // 0x158
    u8 pad15c[0x164 - 0x15c];
    s32 m164;                   // 0x164
    u8 pad168[0x170 - 0x168];
    s32 len;                    // 0x170
    u8 pad174[0x1aa - 0x174];
    u8 hidden;                  // 0x1aa
    char text1[0x100];          // 0x1ab
    char text2[0x100];          // 0x2ab
    char suffix[5];             // 0x3ab
    u8 dirty;                   // 0x3b0
};

extern "C" void render__Q28JMessage8TControlFv(void* p);
extern "C" void fn_8013B490(void* p);
extern void* lbl_8053AB10;
extern u8 lbl_8050DB0C[];

// NONMATCHING (98.4%): float operand order and the clamp temp register.
extern "C" void fn_80394690(MsgDraw* w) {
    if (w->dirty) {
        render__Q28JMessage8TControlFv(w->control);
        w->dirty = 0;
    }
    f32 off = 60.0f + 0.5f * ((3.0f - (f32)w->m164) * ((J2DTextBox*)w->screen->search('Tm01'))->mLineSpacing);
    if (w->hidden == 0) {
        char buf1[0x100];
        char buf2[0x100];
        char tmp[0x20];
        strcpy(buf1, w->text1);
        strcpy(buf2, w->text2);
        if (strlen(w->suffix) != 0) {
            s32 cur = *(s32*)(w->m10 + 0x4c);
            s32 max = *(s16*)(lbl_8050DB0C + 0x4c);
            buf1[w->len] = 0;
            buf2[w->len] = 0;
            s32 c2 = cur;
            if (cur > max) {
                c2 = 0;
            }
            cur = c2;
            u8 alpha = (u8)(255.0f * (f32)(max - cur) / (f32)max);
            snprintf(tmp, 0x1e, "\x1b" "CC[%08x]\x1b" "GM[0]", (w->col1 & 0xffffff00) | alpha);
            strcat(buf1, tmp);
            strcat(buf1, w->suffix);
            snprintf(tmp, 0x1e, "\x1b" "CC[%08x]\x1b" "GM[0]", (w->col2 & 0xffffff00) | alpha);
            strcat(buf2, tmp);
            strcat(buf2, w->suffix);
        }
        strcpy(((J2DTextBox*)w->screen->search('Tm01'))->getStringPtr(), buf1);
        strcpy(((J2DTextBox*)w->screen->search('Tm02'))->getStringPtr(), buf2);
        ((J2DTextBox*)w->screen->search('Tm01'))->move(w->xd8, *(f32*)(lbl_8050DB0C + 0x3c) + (w->y9c + off));
        ((J2DTextBox*)w->screen->search('Tm02'))->move(w->xd8 + w->xe0, w->ye4 + (*(f32*)(lbl_8050DB0C + 0x3c) + (w->y9c + off)));
        fn_8013B490(lbl_8053AB10);
        w->screen->draw(0.0f, 0.0f, *(const J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
    }
}

// ---- fn_80395480: cursor/icon "pop" animation ----
extern "C" const f32 lbl_80475DA0[5];
extern "C" const f32 lbl_80475DB4[5];
struct MsgPop {
    u8 pad0[0x108];
    f32 x;                    // 0x108
    f32 y;                    // 0x10c
    f32 w;                    // 0x110
    f32 h;                    // 0x114
    u8 pad118[0x194 - 0x118];
    s16 timer;                // 0x194
    u8 pad196[0x1a4 - 0x196];
    u8 alpha;                 // 0x1a4
};

// NONMATCHING (99.9%): add operand order for the cumulative durations.
extern "C" void fn_80395480(MsgPop* self, J2DPane* pane) {
    s16* dur = (s16*)(lbl_8050DB0C + 0x286);
    s32 t0 = dur[0];
    s32 t1 = dur[0] + dur[1];
    s32 t2 = dur[0] + dur[1] + dur[2];
    s32 t3 = dur[0] + dur[1] + dur[2] + dur[3];
    s32 t4 = dur[0] + dur[1] + dur[2] + dur[3] + dur[4];
    self->timer++;
    if (pane->getAlpha() < self->alpha) {
        if (self->timer == 10) {
            self->timer = 0;
            pane->setAlpha(self->alpha);
        } else {
            pane->setAlpha(self->alpha * (self->timer / 10.0f));
        }
    } else {
        f32 sy;
        f32 sx;
        if (self->timer <= t0) {
            sy = sx = 1.0f;
        } else if (self->timer <= t1) {
            f32 d = self->timer - t0;
            f32 e = t1 - t0;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475DA0[1] - lbl_80475DA0[0]) + lbl_80475DA0[0];
            sy = r * (lbl_80475DB4[1] - lbl_80475DB4[0]) + lbl_80475DB4[0];
        } else if (self->timer <= t2) {
            f32 d = self->timer - t1;
            f32 e = t2 - t1;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475DA0[2] - lbl_80475DA0[1]) + lbl_80475DA0[1];
            sy = r * (lbl_80475DB4[2] - lbl_80475DB4[1]) + lbl_80475DB4[1];
        } else if (self->timer <= t3) {
            f32 d = self->timer - t2;
            f32 e = t3 - t2;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475DA0[3] - lbl_80475DA0[2]) + lbl_80475DA0[2];
            sy = r * (lbl_80475DB4[3] - lbl_80475DB4[2]) + lbl_80475DB4[2];
        } else if (self->timer <= t4) {
            f32 d = self->timer - t3;
            f32 e = t4 - t3;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475DA0[4] - lbl_80475DA0[3]) + lbl_80475DA0[3];
            sy = r * (lbl_80475DB4[4] - lbl_80475DB4[3]) + lbl_80475DB4[3];
        } else {
            sy = sx = 1.0f;
            self->timer = 0;
        }
        f32 w = sx * self->w;
        f32 h = sy * self->h;
        pane->resize(w, h);
        pane->move((self->x + self->w / 2) - w / 2, (self->y + self->h) - h);
    }
}

extern "C" const f32 lbl_80475D78[5];
extern "C" const f32 lbl_80475D8C[5];
struct MsgPop2 {
    u8 pad0[0xf8];
    f32 x;                    // 0xf8
    f32 y;                    // 0xfc
    f32 w;                    // 0x100
    f32 h;                    // 0x104
    u8 pad108[0x194 - 0x108];
    s16 timer;                // 0x194
    u8 pad196[0x1a3 - 0x196];
    u8 alpha;                 // 0x1a3
};

// NONMATCHING (99.9%): add operand order for the cumulative durations.
extern "C" void fn_80395834(MsgPop2* self, J2DPane* pane) {
    s16* dur = (s16*)(lbl_8050DB0C + 0x286);
    s32 t0 = dur[0];
    s32 t1 = dur[0] + dur[1];
    s32 t2 = dur[0] + dur[1] + dur[2];
    s32 t3 = dur[0] + dur[1] + dur[2] + dur[3];
    s32 t4 = dur[0] + dur[1] + dur[2] + dur[3] + dur[4];
    self->timer++;
    if (pane->getAlpha() < self->alpha) {
        if (self->timer == 10) {
            self->timer = 0;
            pane->setAlpha(self->alpha);
        } else {
            pane->setAlpha(self->alpha * (self->timer / 10.0f));
        }
    } else {
        f32 sy;
        f32 sx;
        if (self->timer <= t0) {
            sy = sx = 1.0f;
        } else if (self->timer <= t1) {
            f32 d = self->timer - t0;
            f32 e = t1 - t0;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475D78[1] - lbl_80475D78[0]) + lbl_80475D78[0];
            sy = r * (lbl_80475D8C[1] - lbl_80475D8C[0]) + lbl_80475D8C[0];
        } else if (self->timer <= t2) {
            f32 d = self->timer - t1;
            f32 e = t2 - t1;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475D78[2] - lbl_80475D78[1]) + lbl_80475D78[1];
            sy = r * (lbl_80475D8C[2] - lbl_80475D8C[1]) + lbl_80475D8C[1];
        } else if (self->timer <= t3) {
            f32 d = self->timer - t2;
            f32 e = t3 - t2;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475D78[3] - lbl_80475D78[2]) + lbl_80475D78[2];
            sy = r * (lbl_80475D8C[3] - lbl_80475D8C[2]) + lbl_80475D8C[2];
        } else if (self->timer <= t4) {
            f32 d = self->timer - t3;
            f32 e = t4 - t3;
            f32 r = (d * d) / (e * e);
            sx = r * (lbl_80475D78[4] - lbl_80475D78[3]) + lbl_80475D78[3];
            sy = r * (lbl_80475D8C[4] - lbl_80475D8C[3]) + lbl_80475D8C[3];
        } else {
            sy = sx = 1.0f;
            self->timer = 0;
        }
        f32 w = sx * self->w;
        f32 h = sy * self->h;
        pane->resize(w, h);
        pane->move((self->x + self->w / 2) - w / 2, (self->y + self->h) - h);
    }
}

// ---- from src/Game/fn_80396F94.cpp ----
extern "C" void update__Q28JMessage8TControlFv(void* subObj);
extern "C" void fn_80396884(void* this_);
extern "C" void fn_80395BE8(void* this_);

// fn_80396F94 - leading helper: calls update__Q28JMessage8TControlFv(this->0x8), then
// fn_80396884(this), then fn_80395BE8(this), then sets this->0x3b0=1
// (a "done" latch).
extern "C" void fn_80396F94(void* this_) {
    update__Q28JMessage8TControlFv(*(void**)((char*)this_ + 0x8));
    fn_80396884(this_);
    fn_80395BE8(this_);
    *(u8*)((char*)this_ + 0x3b0) = 1;
}

extern "C" void __dt__Q28JMessage19TRenderingProcessorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF72C[];
extern void* lbl_804AF6E4[];

struct MsgRP38 {
    void* vt;
    u8 pad[0x34];
    inline ~MsgRP38() {
        vt = lbl_804AF6E4;
        __dt__Q28JMessage19TRenderingProcessorFv(this, 0);
    }
};
struct MsgRP {
    void* vt;
    u8 pad[0x34];
    MsgRP38 m38;
};

extern "C" void* fn_803972A4(MsgRP* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->vt = lbl_804AF72C;
        this_->m38.~MsgRP38();
        __dt__Q28JMessage19TRenderingProcessorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_80397328_dtor.cpp ----
extern "C" void __dt__Q28JMessage18TSequenceProcessorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF774[];

extern "C" void* fn_80397328(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF774;
        __dt__Q28JMessage18TSequenceProcessorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_80397388_dtor.cpp ----
extern "C" void __dt__Q28JMessage10TReferenceFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF6D4[];

extern "C" void* fn_80397388(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF6D4;
        __dt__Q28JMessage10TReferenceFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_803986A0_dtor.cpp ----
extern "C" void __dt__Q28JMessage19TRenderingProcessorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF6E4[];

extern "C" void* fn_803986A0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF6E4;
        __dt__Q28JMessage19TRenderingProcessorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- fn_8039D0DC: glyph-slot position setup ----
struct MsgFontInfo { u8 pad0[0x28]; u16 flags; };
struct MsgRubySlot { f32 x; f32 y; u8 tag; };
struct MsgLayout {
    u8 pad0[0x68];
    MsgRubySlot* ruby[12];    // 0x68
    u8 pad98[0xe8 - 0x98];
    f32 baseE8;               // 0xe8
    u8 padEC[0xf0 - 0xec];
    f32 baseF0;               // 0xf0
    u8 padF4[0x124 - 0xf4];
    f32 slotX[3];             // 0x124
    f32 slotY[3];             // 0x130
    u8 pad13c[0x154 - 0x13c];
    s32 m154;                 // 0x154
    u8 pad158[0x15c - 0x158];
    s32 m15c;                 // 0x15c
    u8 pad160[0x164 - 0x160];
    s32 lineCount;            // 0x164
    u8 pad168[0x16c - 0x168];
    s32 m16c;                 // 0x16c
    s32 m170;                 // 0x170
    u8 pad174[0x178 - 0x174];
    s32 m178;                 // 0x178
    s32 m17c;                 // 0x17c
    u8 pad180[0x190 - 0x180];
    s16 m190;                 // 0x190
    s16 m192;                 // 0x192
    u8 pad194[0x19e - 0x194];
    u8 m19e;                  // 0x19e
    u8 pad19f[0x1a1 - 0x19f];
    u8 m1a1;                  // 0x1a1
    u8 pad1a2[0x1aa - 0x1a2];
    u8 m1aa;                  // 0x1aa
    u8 pad1ab[0x3ab - 0x1ab];
    u8 m3ab;                  // 0x3ab
    u8 m3ac;                  // 0x3ac
    u8 m3ad;                  // 0x3ad
    u8 pad3ae[0x3b2 - 0x3ae];
    u8 slotTag[6];            // 0x3b2
    MsgFontInfo* font;        // 0x3b8
};
struct MsgProc {
    u8 pad0[0x8];
    const JMessage::TResource* res; // 0x08
    u8 padC[0x38 - 0xc];
    JMessage::TRenderingProcessor proc; // 0x38
    s32 m70;                  // 0x70
    u32 bits[2];              // 0x74
    u8 pad7c[0x84 - 0x7c];
    f32 posA[(0x12c - 0x84) / 4];  // 0x84
    f32 posB[(0x1d4 - 0x12c) / 4]; // 0x12c
    f32 slotOfs[(0x210 - 0x1d4) / 4]; // 0x1d4
    s32 hours;                // 0x210
    s32 secs;                 // 0x214
    s32 m218;                 // 0x218
    s32 m21c;                 // 0x21c
    u8 pad220[0x222 - 0x220];
    s16 m222;                 // 0x222
    s16 m224;                 // 0x224
    u8 slotLine[(0x23a - 0x226)];  // 0x226
    s8 lineTab[(0x2bc - 0x23a)];   // 0x23a
    s32 m2bc;                 // 0x2bc
    char* str2c0;             // 0x2c0
    char* str2c4;             // 0x2c4
    u8 pad2c8[0x2cc - 0x2c8];
    s32 cur;                  // 0x2cc
    s32 m2d0;                 // 0x2d0
    u8 slot;                  // 0x2d4
    u8 rubySlot;              // 0x2d5
    u8 m2d6;                  // 0x2d6
    u8 pad2d7[0x2d8 - 0x2d7];
    MsgLayout* layout;        // 0x2d8

    void setTime(s32 t) {
        s32 sec = (t / 60) % 60;
        if (sec == 0) {
            sec = 1;
        }
        hours = t / 3600;
        secs = sec;
    }
    void setInfo(s16 c, s16 d, s32 a, s32 b) {
        m222 = c;
        m224 = d;
        m218 = a;
        m21c = b;
    }
    void setSlotPos(u8 i, s32 x) {
        MsgLayout* l = layout;
        s32 y = slotLine[i] - lineTab[l->m15c] - 1;
        l->slotX[i] = (f32)x + slotOfs[i];
        l->slotY[i] = (f32)y;
    }
    BOOL testBit(s32 n) {
        if (n < 32) {
            return (bits[0] & (s64)(1 << n)) ? TRUE : FALSE;
        } else if (n < 64) {
            return (bits[1] & (s64)(1 << (n - 32))) ? TRUE : FALSE;
        }
        return FALSE;
    }
};

// ---- counter-noun strings ----
// The TU's .rodata (0x80475768..) is not split yet; this describes the part
// of it holding the long counter nouns so the base+offset addressing matches.
struct MsgRodata {
    u8 pad0[0x788];
    char forceGem[0xc];       // 0x788 " Force Gem"
    char forceGems[0xc];      // 0x794 " Force Gems"
    char baddies[0xc];        // 0x7a0
    char systems[0xc];        // 0x7ac
    char thieves[0xc];        // 0x7b8
    char returns[0xc];        // 0x7c4
    char forceFairy[0x10];    // 0x7d0
    char forceFairies[0x10];  // 0x7e0
};
extern "C" const MsgRodata lbl_80475768;
extern "C" const char lbl_80543244[7];  // " cocco"
extern "C" const char lbl_8054324C[8];  // " coccos"
extern "C" const char lbl_805432A8[7];  // " Cucco"
extern "C" const char lbl_805432B0[8];  // " Cuccos"
extern "C" const char lbl_80543254[7];  // " baddy"
extern "C" const char lbl_8054325C[6];  // " time"
extern "C" const char lbl_80543264[7];  // " times"
extern "C" const char lbl_8054326C[8];  // " system"
extern "C" const char lbl_80543274[7];  // " thief"
extern "C" const char lbl_8054327C[6];  // " mole"
extern "C" const char lbl_80543284[7];  // " moles"
extern "C" const char lbl_8054328C[8];  // " return"

static inline void msgAppendWord(MsgProc* p, const char* w, s32 n) {
    strcat(p->str2c0, w);
    strcat(p->str2c4, w);
    p->m2d0 += n;
}

extern "C" void fn_8039C630(MsgProc* p, u8 kind, s32 count) {
    const MsgRodata* r = &lbl_80475768;
    switch (kind) {
    case 1:
        if (count == 1) {
            msgAppendWord(p, r->forceGem, 10);
        } else {
            msgAppendWord(p, r->forceGems, 11);
        }
        break;
    case 2:
        if (count == 1) {
            msgAppendWord(p, lbl_805432A8, 6);
        } else {
            msgAppendWord(p, lbl_805432B0, 6);
        }
        break;
    case 3:
        if (count == 1) {
            msgAppendWord(p, lbl_80543254, 6);
        } else {
            msgAppendWord(p, r->baddies, 8);
        }
        break;
    case 4:
        if (count == 1) {
            msgAppendWord(p, lbl_8054325C, 5);
        } else {
            msgAppendWord(p, lbl_80543264, 6);
        }
        break;
    case 5:
        if (count == 1) {
            msgAppendWord(p, lbl_8054326C, 7);
        } else {
            msgAppendWord(p, r->systems, 8);
        }
        break;
    case 6:
        if (count == 1) {
            msgAppendWord(p, lbl_80543274, 6);
        } else {
            msgAppendWord(p, r->thieves, 8);
        }
        break;
    case 7:
        if (count == 1) {
            msgAppendWord(p, lbl_8054327C, 5);
        } else {
            msgAppendWord(p, lbl_80543284, 6);
        }
        break;
    case 8:
        if (count == 1) {
            msgAppendWord(p, lbl_8054328C, 7);
        } else {
            msgAppendWord(p, r->returns, 8);
        }
        break;
    case 9:
        if (count == 1) {
            msgAppendWord(p, r->forceFairy, 7);
        } else {
            msgAppendWord(p, r->forceFairies, 8);
        }
        break;
    }
}


struct MsgMeasure {
    u8 pad0[0x38];
    JUTFont* font;            // 0x38
    u8 pad3c[0x44 - 0x3c];
    f32 scale;                // 0x44
    f32 fontW;                // 0x48
    f32 lineW[(0xf4 - 0x4c) / 4];  // 0x4c
    f32 lineX[(0x1a0 - 0xf4) / 4]; // 0xf4
    u8 pad1a0[0x201 - 0x1a0];
    u8 line;                  // 0x201
    u8 pad202[0x22d - 0x202];
    u8 lineChars[0x10];       // 0x22d
};

extern "C" void fn_80398700(MsgMeasure* m, u8 kind, s32 count) {
    const MsgRodata* r = &lbl_80475768;
    f32 ratio = m->fontW / (f32)m->font->getCellWidth();
    char buf[15];
    char* s = buf;
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0;
    buf[4] = 0;
    buf[5] = 0;
    buf[6] = 0;
    buf[7] = 0;
    buf[8] = 0;
    buf[9] = 0;
    buf[10] = 0;
    buf[11] = 0;
    buf[12] = 0;
    buf[13] = 0;
    buf[14] = 0;
    switch (kind) {
    case 1:
        if (count == 1) {
            strcat(s, r->forceGem);
        } else {
            strcat(s, r->forceGems);
        }
        break;
    case 2:
        if (count == 1) {
            strcat(s, lbl_80543244);
        } else {
            strcat(s, lbl_8054324C);
        }
        break;
    case 3:
        if (count == 1) {
            strcat(s, lbl_80543254);
        } else {
            strcat(s, r->baddies);
        }
        break;
    case 4:
        if (count == 1) {
            strcat(s, lbl_8054325C);
        } else {
            strcat(s, lbl_80543264);
        }
        break;
    case 5:
        if (count == 1) {
            strcat(s, lbl_8054326C);
        } else {
            strcat(s, r->systems);
        }
        break;
    case 6:
        if (count == 1) {
            strcat(s, lbl_80543274);
        } else {
            strcat(s, r->thieves);
        }
        break;
    case 7:
        if (count == 1) {
            strcat(s, lbl_8054327C);
        } else {
            strcat(s, lbl_80543284);
        }
        break;
    case 8:
        if (count == 1) {
            strcat(s, lbl_8054328C);
        } else {
            strcat(s, r->returns);
        }
        break;
    case 9:
        if (count == 1) {
            strcat(s, r->forceFairy);
        } else {
            strcat(s, r->forceFairies);
        }
        break;
    }
    int i = 0;
    while (*s != 0) {
        JUTFont::TWidth w;
        m->font->getWidthEntry(*s, &w);
        s++;
        m->lineW[m->line] += ratio * (m->scale * (f32)(s32)w.w1);
        m->lineX[m->line] += 3.0f;
        m->lineChars[m->line]++;
        if (++i >= 15) break;
    }
}

// ---- ASCII -> font code table helpers ----
struct MsgCharMap {
    u16 ascii;
    u16 code;
};
extern "C" const MsgCharMap lbl_80475830[];

static inline u16 msgToWide(u16 c) {
    for (int i = 0; lbl_80475830[i].ascii != 0xffff; i++) {
        if (lbl_80475830[i].ascii == c) {
            return lbl_80475830[i].code;
        }
    }
    return 0x1420;
}

static inline void msgPutWide(MsgProc* p, int c) {
    u16 w = msgToWide((u16)c);
    p->str2c0[p->m2d0++] = w >> 8;
    p->str2c0[p->m2d0++] = w;
}

extern "C" void fn_8039C258(MsgProc* p, s32 n) {
    bool lead = false;
    if (n < 0) {
        n *= -1;
        msgPutWide(p, '-');
    }
    s32 d = n / 10000;
    n %= 10000;
    if (d != 0) {
        lead = true;
        msgPutWide(p, d + '0');
    }
    d = n / 1000;
    n %= 1000;
    if (d != 0 || lead) {
        lead = true;
        msgPutWide(p, d + '0');
    }
    d = n / 100;
    n %= 100;
    if (d != 0 || lead) {
        lead = true;
        msgPutWide(p, d + '0');
    }
    d = n / 10;
    n %= 10;
    if (d != 0 || lead) {
        msgPutWide(p, d + '0');
    }
    msgPutWide(p, n + '0');
}

static inline void msgAppendChar(MsgProc* p, char* buf) {
    strcat(p->str2c0, buf);
    strcat(p->str2c4, buf);
    p->m2d0++;
}

// NONMATCHING (99%): cur/layout register swap in the bit test (same as fn_8039D0DC).
extern "C" void fn_8039C9A0(MsgProc* p, s32 n) {
    bool lead = false;
    bool neg = false;
    if (n < 0) {
        n *= -1;
        neg = true;
    }
    if (p->m2d6) {
        if (!p->testBit(p->cur)) {
            MsgLayout* l = p->layout;
            if (l->m16c == 0 || !p->testBit(p->cur)) {
                f32 base;
                f32 pos;
                if (!(l->font->flags & 0x40)) {
                    base = l->baseE8;
                    pos = p->posA[p->cur];
                } else {
                    base = l->baseF0;
                    pos = p->posA[p->cur] + (p->posB[p->cur] - 3.0f);
                }
                s32 x = (base - pos) * 0.5f + 0.5f;
                if (x > 0) {
                    snprintf(lbl_8050E528, 0xf, "\x1b" "CR[%d]", x);
                    strcat(p->str2c0, lbl_8050E528);
                    strcat(p->str2c4, lbl_8050E528);
                    p->m2d0 += strlen(lbl_8050E528);
                }
            }
            p->m2d6 = 0;
        }
    }
    char buf[3];
    buf[2] = 0;
    buf[1] = 0;
    buf[0] = 0;
    if (neg) {
        buf[0] = '-';
        msgAppendChar(p, buf);
    }
    s32 d = n / 10000;
    n %= 10000;
    if (d != 0) {
        buf[0] = d + '0';
        lead = true;
        msgAppendChar(p, buf);
    }
    d = n / 1000;
    n %= 1000;
    if (d != 0 || lead) {
        buf[0] = d + '0';
        lead = true;
        msgAppendChar(p, buf);
    }
    d = n / 100;
    n %= 100;
    if (d != 0 || lead) {
        buf[0] = d + '0';
        lead = true;
        msgAppendChar(p, buf);
    }
    d = n / 10;
    n %= 10;
    if (d != 0 || lead) {
        buf[0] = d + '0';
        msgAppendChar(p, buf);
    }
    buf[0] = n + '0';
    msgAppendChar(p, buf);
}

static inline void msgMeasureChar(MsgMeasure* m, int c, f32 ratio, f32 add) {
    JUTFont::TWidth w;
    m->font->getWidthEntry(c, &w);
    m->lineW[m->line] += ratio * (m->scale * (f32)(s32)w.w1);
    m->lineX[m->line] += add;
    m->lineChars[m->line]++;
}

static inline void msgMeasureChar2(MsgMeasure* m, int c, f32 ratio, f32 add) {
    JUTFont::TWidth w;
    m->font->getWidthEntry(c, &w);
    m->lineW[m->line] += 2.0f * (ratio * (m->scale * (f32)(s32)w.w1));
    m->lineX[m->line] += add;
    m->lineChars[m->line]++;
}

extern "C" void fn_80398EF4(MsgMeasure* m, s32 a, s32 b) {
    f32 ratio = m->fontW / (f32)m->font->getCellWidth();
    if (a > 99) {
        a = 99;
    }
    s32 d = a / 10;
    a -= d * 10;
    if (d > 0) {
        msgMeasureChar(m, d + '0', ratio, 3.0f);
    }
    msgMeasureChar(m, a + '0', ratio, 3.0f);
    msgMeasureChar(m, '\'', ratio, 3.0f);
    if (b > 99) {
        b = 99;
    }
    msgMeasureChar(m, b / 10 + '0', ratio, 3.0f);
    msgMeasureChar(m, b % 10 + '0', ratio, 3.0f);
    msgMeasureChar2(m, '\'', ratio, 6.0f);
}

// NONMATCHING (96%): furigana row compare codegen (subic. vs cmplwi) and regalloc.
extern "C" void fn_8039D30C(MsgProc* p, u8 tag) {
    s32 x = 0;
    if (!p->testBit(p->cur)) {
        if (p->layout->m16c == 0 || !p->testBit(p->cur)) {
            x = (0x1c - p->lineTab[p->cur + 0x2b]) / 2;
        }
    }
    switch (p->slot) {
    case 0:
        p->str2c0[p->m2d0++] = -2;
        p->str2c0[p->m2d0++] = x + (s8)p->slotLine[p->slot + 0x10];
        p->str2c0[p->m2d0++] = -2;
        if (p->layout->m1a1 != 0) {
            s32 top = p->lineTab[p->layout->m15c];
            u32 line = p->slotLine[p->slot];
            if (line - top - 1 == 0) {
                p->str2c0[p->m2d0++] = line + 0x20 - top;
                break;
            }
        }
        {
            p->str2c0[p->m2d0++] = p->slotLine[p->slot] + 0x1f - p->lineTab[p->layout->m15c];
        }
        break;
    case 1:
        p->str2c0[p->m2d0++] = -2;
        p->str2c0[p->m2d0++] = x + (s8)p->slotLine[p->slot + 0x10] + 0x40;
        p->str2c0[p->m2d0++] = -2;
        if (p->layout->m1a1 != 0) {
            s32 top = p->lineTab[p->layout->m15c];
            u32 line = p->slotLine[p->slot];
            if (line - top - 1 == 0) {
                p->str2c0[p->m2d0++] = line + 0x60 - top;
                break;
            }
        }
        {
            p->str2c0[p->m2d0++] = p->slotLine[p->slot] + 0x5f - p->lineTab[p->layout->m15c];
        }
        break;
    case 2:
        p->str2c0[p->m2d0++] = -2;
        p->str2c0[p->m2d0++] = x + (s8)p->slotLine[p->slot + 0x10] + 0x80;
        p->str2c0[p->m2d0++] = -2;
        if (p->layout->m1a1 != 0) {
            s32 top = p->lineTab[p->layout->m15c];
            u32 line = p->slotLine[p->slot];
            if (line - top - 1 == 0) {
                p->str2c0[p->m2d0++] = line + 0xa0 - top;
                break;
            }
        }
        {
            p->str2c0[p->m2d0++] = p->slotLine[p->slot] + 0x9f - p->lineTab[p->layout->m15c];
        }
        break;
    }
    p->layout->slotTag[p->slot] = tag;
    p->slot++;
}

extern "C" void fn_8039934C(MsgMeasure* m, s32 a, s32 b) {
    f32 ratio = m->fontW / (f32)m->font->getCellWidth();
    if (a > 0) {
        if (a > 99) {
            a = 99;
            b = 59;
        }
        s32 d = a / 10;
        s32 e = a % 10;
        if (d > 0) {
            msgMeasureChar(m, d + '0', ratio, 3.0f);
        }
        msgMeasureChar(m, e + '0', ratio, 3.0f);
        msgMeasureChar(m, '\'', ratio, 3.0f);
    }
    if (b > 59) {
        b = 59;
    }
    s32 d = b / 10;
    s32 e = b % 10;
    if (d > 0 || a > 0) {
        msgMeasureChar(m, d + '0', ratio, 3.0f);
    }
    msgMeasureChar(m, e + '0', ratio, 3.0f);
    msgMeasureChar2(m, '\'', ratio, 6.0f);
}

extern "C" const char lbl_805432B8[3];

// NONMATCHING (98%): FP register allocation in indent calc, r6/r7 swap.
extern "C" void fn_8039CDF8(MsgProc* p, u8 tag) {
    if (p->cur > p->lineTab[p->layout->m15c]) {
        strcat(p->str2c0, lbl_805432B8);
        strcat(p->str2c4, lbl_805432B8);
        p->m2d0 += 4;
    } else {
        p->rubySlot++;
        return;
    }
    s32 x = 0;
    if (!p->testBit(p->cur)) {
        MsgLayout* l = p->layout;
        if (l->m16c == 0 || !p->testBit(p->cur)) {
            f32 base;
            f32 pos;
            if (!(l->font->flags & 0x40)) {
                base = l->baseE8;
                pos = p->posA[p->cur];
            } else {
                base = l->baseF0;
                pos = p->posA[p->cur] + (p->posB[p->cur] - 3.0f);
            }
            x = (base - pos) * 0.5f + 0.5f;
        }
    }
    MsgLayout* l = p->layout;
    f32 fy = (f32)(p->slotLine[p->rubySlot + 3] - p->lineTab[l->m15c] - 1);
    f32 fx = (f32)x + p->slotOfs[p->rubySlot + 3];
    for (int i = 0; i < 12; i++) {
        if (l->ruby[i]->tag == 0xff) {
            l->ruby[i]->x = fx;
            l->ruby[i]->y = fy;
            l->ruby[i]->tag = tag;
            break;
        }
    }
    p->rubySlot++;
}

// NONMATCHING (97%): register coloring of cur/layout and slot index.
extern "C" void fn_8039D0DC(MsgProc* p, u8 tag) {
    s32 x = 0;
    if (!p->testBit(p->cur)) {
        MsgLayout* l = p->layout;
        if (l->m16c == 0 || !p->testBit(p->cur)) {
            f32 base;
            f32 pos;
            if (!(l->font->flags & 0x40)) {
                base = l->baseE8;
                pos = p->posA[p->cur];
            } else {
                base = l->baseF0;
                pos = p->posA[p->cur] + (p->posB[p->cur] - 3.0f);
            }
            x = 0.5f * (base - pos) + 0.5f;
        }
    }
    p->setSlotPos(p->slot, x);
    p->layout->slotTag[p->slot] = tag;
    p->slot++;
}

// ---- fn_80396FDC: message-system owner destructor ----
struct MsgVObj {
    virtual ~MsgVObj();
};
struct MsgPad8 { u8 pad[8]; };
struct MsgVObj8 : MsgPad8 {
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual ~MsgVObj8();
};
extern void* lbl_804AF5A0[];
struct MsgSystem {
    void* vt;                          // 0x00
    JMessage::TResourceContainer* res; // 0x04
    MsgVObj* m08[4];                   // 0x08
    u8 pad18[0x20 - 0x18];
    MsgVObj* m20[4];                   // 0x20
    MsgVObj* m30[11];                  // 0x30
    MsgVObj* m5c;                      // 0x5c
    u8 pad60[0x68 - 0x60];
    void* buf[12];                     // 0x68
    u8 pad98[0x3bc - 0x98];
    MsgVObj8* m3bc;                    // 0x3bc
};

static inline void fn_clearRes(JMessage::TResourceContainer* r) {
    while (!r->mContainer.empty()) {
        JGadget::TLinkList<JMessage::TResource, 0>::iterator it = r->mContainer.begin();
        r->mContainer.erase(JGadget::TNodeLinkList::iterator(it.mIt));
        r->mContainer.Do_destroy(&*it);
    }
    r->mColor.reset();
}
extern "C" MsgSystem* fn_80396FDC(MsgSystem* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->vt = lbl_804AF5A0;
        for (int i = 0; i < 12; i++) {
            delete this_->buf[i];
            this_->buf[i] = 0;
        }
        delete this_->m3bc;
        this_->m3bc = 0;
        delete this_->m20[0];
        this_->m20[0] = 0;
        delete this_->m20[1];
        this_->m20[1] = 0;
        delete this_->m20[2];
        this_->m20[2] = 0;
        delete this_->m20[3];
        this_->m20[3] = 0;
        for (int i = 0; i < 11; i++) {
            delete this_->m30[i];
            this_->m30[i] = 0;
        }
        delete this_->m5c;
        this_->m5c = 0;
        fn_clearRes(this_->res);
        delete this_->res;
        this_->res = 0;
        delete this_->m08[0];
        this_->m08[0] = 0;
        delete this_->m08[1];
        this_->m08[1] = 0;
        delete this_->m08[2];
        this_->m08[2] = 0;
        delete this_->m08[3];
        this_->m08[3] = 0;
        if (freeFlag > 0) {
            delete this_;
        }
    }
    return this_;
}

// NONMATCHING (99.9%): r3/r5 swap in the setInfo copy.
extern "C" void fn_8039FB6C(MsgProc* p, const void* entry, const char* text) {
    MsgLayout* l = p->layout;
    l->m3ad = 0;
    l->m3ac = 0;
    l->m3ab = 0;
    *p->str2c0 = 0;
    *p->str2c4 = 0;
    p->cur = 0;
    p->m2d0 = 0;
    p->slot = 0;
    p->rubySlot = 0;
    p->layout->slotTag[0] = 0;
    p->layout->slotTag[1] = 0;
    p->layout->slotTag[2] = 0;
    p->layout->m154 = -1;
    p->m2d6 = 1;
    p->m70 = p->m2bc;
    p->setInfo(p->layout->m190, p->layout->m192, p->layout->m178, p->layout->m17c);
    s32 t = *(s32*)((char*)lbl_8053AD78 + 0x44);
    p->setTime(t);
    p->proc.setBegin_messageEntryText(p->res, entry, text);
    p->proc.process(0);
    p->layout->lineCount = p->lineTab[p->layout->m15c + 1] - p->lineTab[p->layout->m15c];
    p->layout->m170 = 0;
    if (p->lineTab[p->layout->m15c + 0x55] != 0) {
        p->layout->m19e = 0;
    }
    l = p->layout;
    if (l->m1aa == 0) {
        l->ruby[0]->tag = 0xff;
        l->ruby[1]->tag = 0xff;
        l->ruby[2]->tag = 0xff;
        l->ruby[3]->tag = 0xff;
        l->ruby[4]->tag = 0xff;
        l->ruby[5]->tag = 0xff;
        l->ruby[6]->tag = 0xff;
        l->ruby[7]->tag = 0xff;
        l->ruby[8]->tag = 0xff;
        l->ruby[9]->tag = 0xff;
        l->ruby[10]->tag = 0xff;
        l->ruby[11]->tag = 0xff;
    } else {
        p->str2c0[p->m2d0++] = -1;
        p->str2c0[p->m2d0++] = -1;
        if (p->layout->lineCount < 3) {
            p->str2c0[p->m2d0++] = -1;
            p->str2c0[p->m2d0++] = p->layout->lineCount + 0xc0;
        }
    }
}

extern "C" void fn_8039FB28(void* thisPtr) {
    u8* p = (u8*)thisPtr;
    if ((*(u8**)(p + 0x2d8))[0x1aa] != 0) {
        (*(s8**)(p + 0x2c0))[(*(s32*)(p + 0x2d0))++] = -1;
        (*(s8**)(p + 0x2c0))[(*(s32*)(p + 0x2d0))++] = -2;
    }
}

// ---- from src/Game/ClearIndirectFlags_0x2c0_0x2c4.cpp ----
// component C: 3 tiny vtable-slot/helper functions bundled.
extern "C" {
void fn_8039FE54(void* thisPtr) {
	void* p1 = *(void**)((char*)thisPtr + 0x2c0);
	*(u8*)p1 = 0;
	void* p2 = *(void**)((char*)thisPtr + 0x2c4);
	*(u8*)p2 = 0;
}

void fn_8039FE6C(void) {}

int fn_8039FE70(void) { return 1; }
}

struct MsgFont {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void getWidthEntry(int c, void* out);
    virtual int getHeight();
};

struct MsgWidth {
    s8 a;
    u8 w;
    u8 pad[6];
};

extern "C" void fn_8039A350(void* thisObj, int c) {
    u8* p = (u8*)thisObj;
    if (c == 10) {
        p[0x201]++;
        p[0x22c]++;
        ((f32*)(p + 0x4c))[p[0x201]] = 0.0f;
        p[p[0x201] + 0x22d] = 0;
        ((f32*)(p + 0xf4))[p[0x201]] = 0.0f;
        p[0x1e8] = 0;
        s8 cur = ((s8*)(p + 0x202))[p[0x281]];
        if (cur != (s8)p[0x22c] && p[0x201] - cur >= 3) {
            p[0x281]++;
            p[p[0x281] + 0x202] = p[0x22c];
            p[p[0x281] + 0x257] = 0;
            p[0x1e8] = 1;
        }
    } else {
        MsgFont* font = *(MsgFont**)(p + 0x38);
        f32 scale = *(f32*)(p + 0x48) / font->getHeight();
        MsgWidth w;
        (*(MsgFont**)(p + 0x38))->getWidthEntry(c, &w);
        ((f32*)(p + 0x4c))[p[0x201]] += scale * (*(f32*)(p + 0x44) * (int)w.w);
        ((f32*)(p + 0xf4))[p[0x201]] += 3.0f;
        p[p[0x201] + 0x22d]++;
    }
}

// ---- from src/Game/stub_8039a510.cpp ----
// fn_8039A510 - component B vtable slot: advances a byte counter
// (this->0x281), then uses the counter as a byte offset from `this` to
// write 2 fields (a copy of this->0x22c, then a zero) at that
// dynamically-offset location. Each use re-reads the counter from
// memory rather than caching it, matching retail's own reload pattern.
extern "C" void fn_8039A510(void* thisObj) {
	u8* base = (u8*)thisObj;
	base[0x281] = base[0x281] + 1;
	base[base[0x281] + 0x202] = base[0x22c];
	base[base[0x281] + 0x257] = 0;
}


extern f32 lbl_805431DC;

extern "C" void fn_8039A540(void* thisObj) {
    u8* p = (u8*)thisObj;
    *(s32*)(p + 0x3c) = -1;
    *(s32*)(p + 0x40) = -1;
    p[0x201] = 0;
    ((f32*)(p + 0x4c))[p[0x201]] = 0.0f;
    ((f32*)(p + 0xf4))[p[0x201]] = 0.0f;
    p[p[0x201] + 0x22d] = 0;
    p[0x22c] = 0;
    p[0x281] = 0;
    p[0x282] = 0;
    for (int i = 0; i < 3; i++) {
        ((f32*)(p + 0x19c))[i] = 0.0f;
        p[0x1ee + i] = 0;
        p[0x1fe + i] = 0;
    }
    p[0x1fd] = 0;
    for (int i = 3; i < 15; i++) {
        ((f32*)(p + 0x19c))[i] = 0.0f;
        p[0x1ee + i] = 0;
    }
    ((s8*)(p + 0x202))[p[0x281]] = -1;
    p[p[0x281] + 0x257] = 0;
    p[0x1e8] = 0;
}

// ---- small helpers near the end of the TU (0x803A2BC4-0x803A3258) ----
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7E5C(void* mgr, s32 a, s32 b);
extern "C" void fn_802D7EB0(void* mgr, s32 a, s32 b, s32 c);
extern "C" void fn_80138B7C(void* p);
extern "C" void fn_8043D874(void* p, s32 a, s32 b, s32 c);
extern void* lbl_8053AD78;
extern void* lbl_8053AAF8;
extern void* lbl_8053AED0;
extern u8 lbl_8050EC80[];
extern u8 lbl_80529DEC[];

struct MsgCounter {
    u8 pad0[0x4c];
    s32 m4c;
    s32 m50;
    s32 m54;
    s32 m58;
    u8 m5c;
    u8 m5d;
    u8 pad5e[2];
    u8* m60;
};

extern void* lbl_8053AF80;
extern void* lbl_8053AD30;
extern u8 lbl_8050DB0C[];
extern "C" void fn_80458880(void* p, s32 a, s32 b);
extern "C" u32 fn_80309C4C(void* p, s32 a, s32 b);
extern "C" u32 fn_80309D6C(void* p, s32 a, s32 b);
extern "C" s32 fn_8030AAF4(s32 a);
extern "C" s32 fn_8037E7AC(s32 a);

extern "C" void fn_803A28A8(MsgCounter* self, int c) {
    if (self->m60[0x1aa] == 0) {
        s8 hi = (u16)c >> 8;
        if (c == 10) {
            self->m54++;
            if (self->m58 == 1) {
                self->m58 = 2;
            }
        }
        if (hi) {
            self->m50++;
        }
        self->m50++;
        if (self->m5d == 0) {
            if (!(*(u16*)(*(u8**)(self->m60 + 0x3b8) + 0x28) & 0x40)) {
                self->m4c = 1;
            } else {
                self->m4c = *(s16*)(lbl_8050DB0C + 0x4c);
            }
        }
        fn_80458880(lbl_8053AF80, 8, -1);
        if (self->m58 == 2 || self->m54 >= 3 || self->m50 >= 0xff) {
            self->m4c = 99999;
            self->m60[0x3ae] = 8;
        }
    } else {
        if (c == 10) {
            self->m54++;
            if (self->m58 == 1) {
                self->m58 = 2;
            }
        }
        self->m50 += 2;
        if (self->m58 == 2 || self->m54 >= 3 || self->m50 >= 0xff) {
            self->m4c = 99999;
            self->m60[0x3ae] = 3;
        }
    }
}

extern "C" int fn_803A2A2C(MsgCounter* self) {
    u8* q = self->m60;
    if (q[0x1aa] == 0) {
        if (self->m4c == 0) {
            return 1;
        }
        if (self->m4c == 99999) {
            if (q[0x19f] != 0) {
                self->m4c = 0;
                self->m54 = 0;
                self->m50 = 0;
                self->m58 = 0;
                self->m5d = 0;
                (*(s32*)(self->m60 + 0x15c))++;
                self->m60[0x19f] = 0;
            }
        } else {
            self->m4c--;
            if (self->m5c == 0) {
                q = self->m60;
                if (q[0x19e] != 0) {
                    if (*(u16*)(*(u8**)(q + 0x3b8) + 0x28) & 0x100) {
                        if (fn_80309C4C(lbl_8053AD30, 0x100, -1) != 0 || self->m60[0x1a0] != 0 ||
                            fn_8037E7AC(*(s32*)(self->m60 + 0x160)) != 0) {
                            self->m5d = 1;
                            self->m4c = 0;
                        }
                    } else {
                        if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(*(s32*)(q + 0x160)), 0x100) != 0 ||
                            self->m60[0x1a0] != 0 || fn_8037E7AC(*(s32*)(self->m60 + 0x160)) != 0) {
                            self->m5d = 1;
                            self->m4c = 0;
                        }
                    }
                }
            } else {
                self->m5c = 0;
            }
        }
    } else {
        if (self->m4c == 0) {
            return 1;
        }
        self->m4c--;
    }
    return 0;
}

extern "C" {
void fn_803A2BC4(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(u8*)(*(char**)(p + 0x60) + 0x3af) = 0;
    char* q = *(char**)(p + 0x60);
    if (*(u8*)(q + 0x1aa) == 0) {
        *(u8*)(q + 0x3ae) = 8;
    } else {
        *(u8*)(q + 0x3ae) = 3;
    }
}

void fn_803A2BF8(void* thisPtr) { *(u8*)((char*)thisPtr + 0x5c) = 1; }

void fn_803A2C04(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(s32*)(p + 0x4c) = 0;
    *(s32*)(p + 0x54) = 0;
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x58) = 0;
    *(u8*)(p + 0x5d) = 0;
    char* q = *(char**)(p + 0x60);
    *(s32*)(q + 0x150) = 0;
    *(u8*)(q + 0x19e) = 0xff;
    *(s32*)(*(char**)(p + 0x60) + 0x15c) = 0;
    *(u8*)(*(char**)(p + 0x60) + 0x3af) = 1;
    q = *(char**)(p + 0x60);
    *(s32*)(q + 0x16c) = 0;
    *(u8*)(q + 0x1a0) = 0;
    *(u8*)(q + 0x1a1) = 0;
    *(s32*)(q + 0x168) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x148) = -1;
    *(u8*)(*(char**)(p + 0x60) + 0x1a9) = 0;
    *(s32*)(*(char**)(p + 0x60) + 0x174) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x13c) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x140) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x144) = -1;
    q = *(char**)(p + 0x60);
    if (*(u8*)(q + 0x1aa) == 0) {
        *(u8*)(q + 0x3ae) = 7;
    } else {
        *(u8*)(q + 0x3ae) = 2;
    }
}

void fn_803A2CB0(void* thisPtr, u8 kind, s32 mode) {
    s32* w = (s32*)((char*)thisPtr + 0x50);
    switch (kind) {
    case 1: if (mode == 1) *w += 10; else *w += 11; break;
    case 2: if (mode == 1) *w += 6; else *w += 7; break;
    case 3: if (mode == 1) *w += 6; else *w += 8; break;
    case 4: if (mode == 1) *w += 5; else *w += 6; break;
    case 5: if (mode == 1) *w += 7; else *w += 8; break;
    case 6: if (mode == 1) *w += 6; else *w += 8; break;
    case 7: if (mode == 1) *w += 5; else *w += 6; break;
    case 8: if (mode == 1) *w += 7; else *w += 8; break;
    case 9: if (mode == 1) *w += 12; else *w += 14; break;
    }
    *w += 1;
}

void fn_803A2E48(void* thisPtr, s32 n) {
    s32* w = (s32*)((char*)thisPtr + 0x50);
    u8 started = 0;
    if (n < 0) {
        *w += 1;
        n *= -1;
    }
    s32 r = n % 10000;
    if (n / 10000 != 0) {
        *w += 1;
        started = 1;
    }
    s32 d = r / 1000;
    r = r % 1000;
    if (d != 0 || started) {
        *w += 1;
        started = 1;
    }
    d = r / 100;
    r = r % 100;
    if (d != 0 || started) {
        *w += 1;
        started = 1;
    }
    d = r / 10;
    if (d != 0 || started) {
        *w += 1;
    }
    *w += 1;
}

void fn_803A2F74(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(s32*)(p + 0x4c) = 0;
    *(s32*)(p + 0x54) = 0;
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x58) = 0;
    *(u8*)(p + 0x5d) = 0;
    (*(s32*)(*(char**)(p + 0x60) + 0x15c))++;
    char* q = *(char**)(p + 0x60);
    *(s32*)(q + 0x150) = 0;
    *(u8*)(q + 0x19e) = 0xff;
    *(s32*)(*(char**)(p + 0x60) + 0x148) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x13c) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x140) = -1;
    *(s32*)(*(char**)(p + 0x60) + 0x144) = -1;
    *(u8*)(*(char**)(p + 0x60) + 0x3ae) = 2;
}

s32 fn_803A2FE0(void) { return *(s32*)((char*)lbl_8053AD78 + 0x10c); }
void fn_803A2FEC(void) { *(s32*)((char*)lbl_8053AD78 + 0x44) = 0; }
void fn_803A2FFC(void) { *(u8*)((char*)lbl_8053AD78 + 0xe9) = 0; }
u8 fn_803A300C(void) { return *(u8*)((char*)lbl_8053AD78 + 0xe9); }
u16 fn_803A3018(void) { return *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x36); }
u16 fn_803A3034(void) { return *(u16*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x34); }
s32 fn_803A3050(void* p) { return *(s32*)((char*)p + 0x17c); }
s32 fn_803A3058(void* p) { return *(s32*)((char*)p + 0x178); }
s16 fn_803A3060(void* p) { return *(s16*)((char*)p + 0x192); }
s16 fn_803A3068(void* p) { return *(s16*)((char*)p + 0x190); }
void fn_803A3070(void* p, s32 v) { *(s32*)((char*)p + 0x174) = v; }
void fn_803A3078(void* p) { *(u8*)((char*)p + 0x3b1) = 0; }
void fn_803A3084(void* p, s32 i, s32 v) { ((s32*)((char*)p + 0x180))[i] = v; }
s32 fn_803A3094(void* p) { return *(s32*)((char*)p + 0x14c); }
s32 fn_803A309C(void* p) { return *(s32*)((char*)p + 0x3bc); }
void fn_803A30A4(void* p, u8 a, s32 b) {
    *(s32*)((char*)p + 0x150) = b;
    *(u8*)((char*)p + 0x19e) = a;
}
void fn_803A30B0(void* p) { *(u8*)((char*)p + 0x1a9) = 1; }
s32 fn_803A30BC(void* p) { return *(s32*)((char*)p + 0x160); }
void fn_803A30C4(void* p) { *(u8*)((char*)p + 0x1a0) = 3; }
void fn_803A30D0(void* p) { *(u8*)((char*)p + 0x1a1) = 1; }
void fn_803A30DC(void* p, s32 v) { *(s32*)((char*)p + 0x148) = v; }
void fn_803A30E4(void* p) { *(u8*)((char*)p + 0x1a1) = 0; }
void fn_803A30F0(void* p) { *(u8*)((char*)p + 0x1a0) = 2; }
void fn_803A30FC(void* p, s32 i, s32 v) { ((s32*)((char*)p + 0x13c))[i] = v; }
s32 fn_803A310C(void* p) { return *(s32*)((char*)p + 0x16c); }
void fn_803A3114(void* p) {
    if (*(u8*)((char*)p + 0x1a0) == 0) {
        (*(s32*)((char*)p + 0x168))++;
    }
    (*(s32*)((char*)p + 0x16c))++;
}
u8 fn_803A313C(void* p) { return *(u8*)((char*)p + 0x1aa); }
void fn_803A3144(void) { fn_80138B7C(lbl_8053AAF8); }
void fn_803A3168(s32 a, s32 b) { fn_802D7E5C(fn_802D6A9C(), a, b); }
void fn_803A31AC(s32 a, s32 b, s32 c) { fn_802D7EB0(fn_802D6A9C(), a, b, c); }
s32 fn_803A3200(void) { return *(s32*)(lbl_80529DEC + 0x11c); }
s32 fn_803A3210(void) { return *(s32*)(lbl_80529DEC + 0x118); }
s32 fn_803A3220(void* p) { return *(s32*)((char*)p + 0x280); }
void fn_803A3228(s32 a, s32 b, s32 c) { fn_8043D874(lbl_8053AED0, a, b, c); }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
