// TU 0x803a8dfc-0x803b7dcc.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

#include "JSystem/J2D/J2DScreen.h"

struct VObj_803A8DFC {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void setAlpha(u8 a);
};

extern "C" s32 fn_8037EFB4(s32 idx);
extern "C" void fn_8013B490(void* p);
extern void* lbl_8053AB10;
// .sdata2 constants of this TU (0.0f, 800.0f, 640.0f); referenced by label until
// the whole TU's literal pool can be emitted in order.
extern const f32 lbl_805433C8;
extern const f32 lbl_805433D8;
extern const f32 lbl_805433DC;

// Maps another player's index to a compact slot excluding `self`.
extern "C" s32 fn_803A8DFC(void* this_, s32 self) {
    s32 r = 0;
    switch (self) {
    case 0:
        switch (fn_8037EFB4(self)) {
        case 0: r = 1; break;
        case 1: r = 2; break;
        case 2: r = 3; break;
        }
        break;
    case 1:
        switch (fn_8037EFB4(self)) {
        case 0: r = 0; break;
        case 1: r = 2; break;
        case 2: r = 3; break;
        }
        break;
    case 2:
        switch (fn_8037EFB4(self)) {
        case 0: r = 0; break;
        case 1: r = 1; break;
        case 2: r = 3; break;
        }
        break;
    case 3:
        switch (fn_8037EFB4(self)) {
        case 0: r = 0; break;
        case 1: r = 1; break;
        case 2: r = 2; break;
        }
        break;
    }
    return r;
}

extern "C" void fn_803A97A0(void* this_) {
    char* p = (char*)this_;
    fn_8013B490(lbl_8053AB10);
    if (*(u8*)(p + 0x4c0) >= 2) {
        (*(VObj_803A8DFC**)(p + 0x16c))->setAlpha(0xff - *(u8*)(p + 0x4c2));
    } else {
        (*(VObj_803A8DFC**)(p + 0x16c))->setAlpha(0);
    }
    (*(J2DScreen**)(p + 0x1c))->draw(lbl_805433C8, lbl_805433C8, *(const J2DGrafContext**)((char*)lbl_8053AB10 + 0x10));
}


// ---- from src/Game/CountdownBlink_803AF604.cpp ----
extern "C" void fn_80458880(void* p1, s32 p2, s32 p3);
extern "C" void fn_803B35F8(void* this_, u8 flag);

extern void* lbl_8053AF80;

extern void* lbl_8053AD30;
extern "C" u32 fn_80309C4C(void* p, s32 a, s32 b);

struct Menu_Slide {
    u8 pad0[0x70];
    J2DPane* panes[0xd];        // 0x70
    u8 padA4[0x3c0 - 0xa4];
    s32 state[4];               // 0x3c0
    u8 pad3d0[0x3f4 - 0x3d0];
    f32 ys[8];                  // 0x3f4
    u8 pad414[0x440 - 0x414];
    s32 timer;                  // 0x440
    u8 pad444[0x454 - 0x444];
    s32 count;                  // 0x454
    u8 pad458[0x4c1 - 0x458];
    u8 m4c1;
    u8 m4c2;
    u8 m4c3;
    u8 m4c4;
    u8 m4c5;
    u8 m4c6;
};

#define PANE(off) (p->panes[((off) - 0x70) / 4])
#define PY(off) (p->ys[((off) - 0x3f4) / 4])

extern "C" void fn_803AD220(Menu_Slide* p) {
    p->timer--;
    if (fn_80309C4C(lbl_8053AD30, 0x100, -1) != 0) {
        if (p->timer >= 0x3c) {
            PANE(0x9c)->hide();
            { f32 x = PANE(0x9c)->getBounds()->i.x; PANE(0x9c)->move(x, PY(0x404)); }
            PANE(0x98)->show();
            { f32 x = PANE(0x98)->getBounds()->i.x; PANE(0x98)->move(x, PY(0x408)); }
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
        p->timer = 0;
    }
    s32 t = p->timer;
    if (t == 0) {
        p->timer = 0x96;
        p->m4c4 = 0;
        p->m4c6 = 0;
        for (s32 i = 0; i < p->count; i++) {
            p->state[i] = 0x3e;
        }
        p->m4c1 = 0x1a;
    } else if (t >= 0x8a) {
        f32 off = -150.0f * ((f32)(12 - (t - 0x8a)) / 12.0f);
        { f32 x = PANE(0x9c)->getBounds()->i.x; PANE(0x9c)->move(x, PY(0x404) + off); }
        if (p->timer == 0x8a) {
            PANE(0x9c)->hide();
            PANE(0x98)->show();
            { f32 x = PANE(0x98)->getBounds()->i.x; PANE(0x98)->move(x, PY(0x408) + off); }
        }
    } else if (t >= 0x80) {
        f32 x = PANE(0x98)->getBounds()->i.x;
        f32 off = -150.0f * ((f32)(t - 0x80) / 12.0f);
        PANE(0x98)->move(x, PY(0x408) + off);
        if (p->timer == 0x80) {
            { f32 x = PANE(0x9c)->getBounds()->i.x; PANE(0x9c)->move(x, PY(0x404)); }
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
    }
}

extern "C" void fn_803ADC0C(Menu_Slide* p) {
    p->timer--;
    if (fn_80309C4C(lbl_8053AD30, 0x100, -1) != 0) {
        if (p->timer >= 0x3c) {
            PANE(0x94)->hide();
            PANE(0xa0)->show();
            { f32 x = PANE(0x94)->getBounds()->i.x; PANE(0x94)->move(x, PY(0x400)); }
            { f32 x = PANE(0xa0)->getBounds()->i.x; PANE(0xa0)->move(x, PY(0x410)); }
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
        p->timer = 0;
    }
    s32 t = p->timer;
    if (t == 0) {
        p->timer = 0x96;
        p->m4c4 = 0;
        p->m4c6 = 0;
        for (s32 i = 0; i < p->count; i++) {
            p->state[i] = 0x3e;
        }
        p->m4c1 = 0x15;
    } else if (t >= 0x8a) {
        f32 off = -150.0f * ((f32)(12 - (t - 0x8a)) / 12.0f);
        { f32 x = PANE(0x94)->getBounds()->i.x; PANE(0x94)->move(x, PY(0x400) + off); }
        if (p->timer == 0x8a) {
            PANE(0x94)->hide();
            PANE(0xa0)->show();
            { f32 x = PANE(0xa0)->getBounds()->i.x; PANE(0xa0)->move(x, PY(0x410) + off); }
        }
    } else if (t >= 0x80) {
        f32 x = PANE(0xa0)->getBounds()->i.x;
        f32 off = -150.0f * ((f32)(t - 0x80) / 12.0f);
        PANE(0xa0)->move(x, PY(0x410) + off);
        if (p->timer == 0x80) {
            { f32 x = PANE(0xa0)->getBounds()->i.x; PANE(0xa0)->move(x, PY(0x410)); }
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
    }
}

extern "C" void fn_803AE308(Menu_Slide* p) {
    p->timer--;
    if (fn_80309C4C(lbl_8053AD30, 0x100, -1) != 0) {
        if (p->timer >= 0x3c) {
            PANE(0x90)->hide();
            { f32 x = PANE(0x90)->getBounds()->i.x; PANE(0x90)->move(x, PY(0x3fc)); }
            PANE(0x94)->show();
            { f32 x = PANE(0x94)->getBounds()->i.x; PANE(0x94)->move(x, PY(0x400)); }
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
        p->timer = 0;
    }
    s32 t = p->timer;
    if (t == 0) {
        p->timer = 0x96;
        p->m4c4 = 0;
        p->m4c6 = 0;
        for (s32 i = 0; i < p->count; i++) {
            p->state[i] = 0x3e;
        }
        p->m4c1 = 0x13;
    } else if (t >= 0x8a) {
        f32 off = -150.0f * ((f32)(12 - (t - 0x8a)) / 12.0f);
        { f32 x = PANE(0x90)->getBounds()->i.x; PANE(0x90)->move(x, PY(0x3fc) + off); }
        if (p->timer == 0x8a) {
            PANE(0x90)->hide();
            PANE(0x94)->show();
            { f32 x = PANE(0x94)->getBounds()->i.x; PANE(0x94)->move(x, PY(0x400) + off); }
        }
    } else if (t >= 0x80) {
        f32 x = PANE(0x94)->getBounds()->i.x;
        f32 off = -150.0f * ((f32)(t - 0x80) / 12.0f);
        PANE(0x94)->move(x, PY(0x400) + off);
        if (p->timer == 0x80) {
            { f32 x = PANE(0x90)->getBounds()->i.x; PANE(0x90)->move(x, PY(0x3fc)); }
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
    }
}

extern "C" void fn_803AEC78(Menu_Slide* p) {
    p->timer--;
    if (fn_80309C4C(lbl_8053AD30, 0x100, -1) != 0) {
        if (p->timer >= 0x3c) {
            PANE(0x8c)->hide();
            PANE(0x90)->show();
            { f32 x = PANE(0x8c)->getBounds()->i.x; PANE(0x8c)->move(x, PY(0x3f8)); }
            { f32 x = PANE(0x90)->getBounds()->i.x; PANE(0x90)->move(x, PY(0x3fc)); }
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
        p->timer = 0;
    }
    s32 t = p->timer;
    if (t == 0) {
        p->timer = 0x96;
        p->m4c4 = 0;
        p->m4c6 = 0;
        for (s32 i = 0; i < p->count; i++) {
            p->state[i] = 0x3e;
        }
        p->m4c1 = 0x10;
    } else if (t >= 0x8a) {
        f32 off = -150.0f * ((f32)(12 - (t - 0x8a)) / 12.0f);
        { f32 x = PANE(0x8c)->getBounds()->i.x; PANE(0x8c)->move(x, PY(0x3f8) + off); }
        if (p->timer == 0x8a) {
            PANE(0x8c)->hide();
            PANE(0x90)->show();
            { f32 x = PANE(0x90)->getBounds()->i.x; PANE(0x90)->move(x, PY(0x3fc) + off); }
        }
    } else if (t >= 0x80) {
        f32 x = PANE(0x90)->getBounds()->i.x;
        f32 off = -150.0f * ((f32)(t - 0x80) / 12.0f);
        PANE(0x90)->move(x, PY(0x3fc) + off);
        if (p->timer == 0x80) {
            { f32 x = PANE(0x90)->getBounds()->i.x; PANE(0x90)->move(x, PY(0x3fc)); }
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
    }
}

extern "C" void fn_803AF604(void* this_) {
    char* t = (char*)this_;
    s32 v = *(s32*)(t + 0x440) - 1;
    *(s32*)(t + 0x440) = v;
    v = *(s32*)(t + 0x440);

    if (v > 10) {
        if (v > 0xb4) {
            if (v % 2 == 0) {
                u8 c = *(u8*)(t + 0x4c7);
                *(u8*)(t + 0x4c7) = c + 1;
                fn_80458880(lbl_8053AF80, 0x20, -1);
            }
        } else if (v > 0x78) {
            if (v % 3 == 0) {
                u8 c = *(u8*)(t + 0x4c7);
                *(u8*)(t + 0x4c7) = c + 1;
                fn_80458880(lbl_8053AF80, 0x20, -1);
            }
        } else if (v > 0x3c) {
            if (v % 4 == 0) {
                u8 c = *(u8*)(t + 0x4c7);
                *(u8*)(t + 0x4c7) = c + 1;
                fn_80458880(lbl_8053AF80, 0x20, -1);
            }
        } else {
            if (v % 5 == 0) {
                u8 c = *(u8*)(t + 0x4c7);
                *(u8*)(t + 0x4c7) = c + 1;
                fn_80458880(lbl_8053AF80, 0x20, -1);
            }
        }
    } else {
        if (v == 10) {
            fn_80458880(lbl_8053AF80, 0x21, -1);
        }
    }

    if (*(u8*)(t + 0x4c7) >= 9) {
        *(u8*)(t + 0x4c7) = 0;
    }

    if (*(s32*)(t + 0x440) == 0) {
        u8 flagArg = *(u8*)(t + 0x4c7);
        fn_803B35F8(this_, flagArg);
        *(s32*)(t + 0x440) = 0x96;
        *(u8*)(t + 0x4c1) = 0xd;
    }
}

extern "C" void fn_803B0158(Menu_Slide* p) {
    p->timer--;
    if (fn_80309C4C(lbl_8053AD30, 0x100, -1) != 0) {
        if (p->timer >= 0x3c) {
            PANE(0x70)->hide();
            PANE(0x8c)->show();
            { f32 x = PANE(0x70)->getBounds()->i.x; PANE(0x70)->move(x, PY(0x3f4)); }
            { f32 x = PANE(0x8c)->getBounds()->i.x; PANE(0x8c)->move(x, PY(0x3f8)); }
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
        p->timer = 0;
    }
    s32 t = p->timer;
    if (t == 0) {
        p->timer = 0x96;
        p->m4c4 = 0;
        p->m4c6 = 0;
        for (s32 i = 0; i < p->count; i++) {
            p->state[i] = 0x3e;
        }
        p->m4c1 = 9;
    } else if (t >= 0x8a) {
        f32 off = -150.0f * ((f32)(12 - (t - 0x8a)) / 12.0f);
        { f32 x = PANE(0x70)->getBounds()->i.x; PANE(0x70)->move(x, PY(0x3f4) + off); }
        if (p->timer == 0x8a) {
            PANE(0x70)->hide();
            PANE(0x8c)->show();
            { f32 x = PANE(0x8c)->getBounds()->i.x; PANE(0x8c)->move(x, PY(0x3f8) + off); }
        }
    } else if (t >= 0x80) {
        f32 x = PANE(0x8c)->getBounds()->i.x;
        f32 off = -150.0f * ((f32)(t - 0x80) / 12.0f);
        PANE(0x8c)->move(x, PY(0x3f8) + off);
        if (p->timer == 0x80) {
            { f32 x = PANE(0x70)->getBounds()->i.x; PANE(0x70)->move(x, PY(0x3f4)); }
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
    }
}


// ---- from src/Game/InvalidateFourFields.cpp ----
// fn_803B7B90 - trailing tiny helper (0x18), closes out the whole actor cluster
extern "C" {

void fn_803B7B90(void* thisPtr) {
	s32* p = (s32*)thisPtr;
	p[0] = -1;
	p[1] = -1;
	p[2] = -1;
	p[3] = -1;
}

}

struct MsgSink {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void send(void* msg);
};
struct MsgSinkHolder {
    u32 m0;
    u32 m4;
    MsgSink* sink() { return (MsgSink*)this; }
};
struct MsgSinkObj : MsgSinkHolder {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void send(void* msg);
};

extern "C" s32 fn_8030AAF4(s32 a);
extern "C" u32 fn_80309D24(void* p, s32 a, s32 b);
extern "C" void fn_8015F8FC(void* p, s32 a, void* b, s32 c);

struct PFlag {
    u8 v;
};

struct Menu_803B2FB0 {
    u8 pad0[0x174];
    MsgSinkObj* sinks[4];       // 0x174
    u8 pad184[0x2f0 - 0x184];
    u8 icons[4][0xc];           // 0x2f0
    u8 pad320[0x3c0 - 0x320];
    s32 state[4];               // 0x3c0
    u8 pad3d0[0x454 - 0x3d0];
    s32 count;                  // 0x454
    u8 pad458[0x4b0 - 0x458];
    PFlag flags[4];             // 0x4b0
    u8 order[4];                // 0x4b4
};

extern "C" void fn_803B2FB0(Menu_803B2FB0* p) {
    s32 i;
    for (i = 0; i < p->count; i++) {
        if (fn_80309D24(lbl_8053AD30, fn_8030AAF4(i), 0x40) != 0) {
            if (!((p->flags[i].v >> 1) & 1)) {
                u8 cnt = 0;
                for (s32 k = 0; k < p->count; k++) {
                    if (p->order[k] != 0xff) {
                        cnt++;
                    }
                }
                p->order[cnt] = i;
                fn_80458880(lbl_8053AF80, 0x1e, -1);
                p->flags[i].v |= 2;
                if (p->state[i] == 0xe7) {
                    u32 msg = 0x10008;
                    p->sinks[i]->send(&msg);
                }
            }
        } else if ((p->flags[i].v >> 1) & 1) {
            for (s32 j = 0; j < p->count; j++) {
                if (p->order[j] == (u8)i) {
                    if (j < p->count - 1) {
                        for (s32 k = j; k < p->count - 1; k++) {
                            p->order[k] = p->order[k + 1];
                        }
                    }
                    p->order[p->count - 1] = 0xff;
                }
            }
            p->flags[i].v &= ~2;
        }
    }
    for (s32 k = 0; k < p->count; k++) {
        if (p->order[k] != 0xff) {
            fn_8015F8FC(*(void**)((u8*)lbl_8053AB10 + 0x30), 0, p->icons[p->order[k]], 5);
        }
    }
}

struct VPane_803B31AC {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void setAlpha(u8 a);
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual void vD8();
    virtual void vDC();
    virtual void vE0();
    virtual void vE4();
    virtual void vE8();
    virtual void drawRect(s32 a, s32 b, s32 c, f32 x, f32 y, f32 w, f32 h);
};

extern u8 lbl_80529DEC[];

extern "C" void fn_803B31AC(void* this_) {
    char* p = (char*)this_;
    s32 mode = *(s32*)(lbl_80529DEC + 0x118);
    if (mode == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 1 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 2 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 3 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 4 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 5 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 6 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 7 && *(s32*)(lbl_80529DEC + 0x11c) == 1) return;
    if (mode == 8 && *(s32*)(lbl_80529DEC + 0x11c) == 3) return;
    if (mode == 10 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    // NONMATCHING: retail compares with cmplwi + bne/b (5 diff lines).
    switch (*(u8*)(lbl_80529DEC + 0x237)) {
    case 8:
        return;
    }
    fn_8013B490(lbl_8053AB10);
    (*(VPane_803B31AC**)(p + 0x170))->setAlpha(*(u8*)(p + 0x4c2));
    (*(VPane_803B31AC**)(p + 0x170))->drawRect(0, 0, 0, lbl_805433C8, lbl_805433C8, lbl_805433D8, lbl_805433DC);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
