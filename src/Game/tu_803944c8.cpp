// TU 0x803944c8-0x803a3484.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include "JSystem/J2D/J2DScreen.h"

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
