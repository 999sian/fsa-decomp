// TU 0x803a8dfc-0x803b7dcc.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JParticle/JPAEmitter.h"

struct MsgRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct MsgGame { u8 pad[0xb4]; MsgRandom rnd; };
extern MsgGame* lbl_8053AAF8;

extern "C" void __dl__FPv(void* p);

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

extern u8 lbl_80529DEC[];
extern void* lbl_8053AD68;
extern "C" void fn_80128C58(u8 a);
extern "C" void fn_8013A884(void* color);
extern "C" void fn_803AA8F8(void* this_);
extern "C" void fn_803AA1F8(void* this_);
extern "C" void fn_803A9AB8(void* this_);

struct AnmFrame {
    u8 pad0[6];
    s16 maxFrame;
    f32 frame;
};

struct EffHandle {
    u8 pad0[0x24];
    s32 m24;
    u8 pad28[0xf4 - 0x28];
    u32 flags;
};

struct Menu_Main {
    u8 pad0[4];
    J2DScreen* screens[8];      // 0x04
    AnmFrame* anms[8];          // 0x24
    u8 pad44[0x1b8 - 0x44];
    EffHandle* handles[4];      // 0x1b8
    u8 pad1c8[0x440 - 0x1c8];
    s32 timer;                  // 0x440
    u8 pad444[0x44c - 0x444];
    s32 frame;                  // 0x44c
    s32 cur;                    // 0x450
    u8 pad454[0x4c0 - 0x454];
    u8 mode;                    // 0x4c0
    u8 m4c1;
    u8 alpha;                   // 0x4c2
};

extern "C" void fn_803A9830(Menu_Main* p) {
    switch (p->mode) {
    case 0:
        p->timer--;
        if (p->timer == 0) {
            p->mode = 1;
        }
        break;
    case 1:
        p->alpha += 2;
        if (p->alpha >= 0xfe) {
            p->alpha = 0xff;
            p->mode = 2;
            p->m4c1 = 1;
            *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235c) = 0;
            *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235d) = 0;
            *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235e) = 0;
            *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235f) = 0;
            fn_80128C58(0xff);
            u32 color = 0xffffff00;
            fn_8013A884(&color);
        }
        break;
    case 2:
        fn_803AA8F8(p);
        break;
    case 3:
        fn_803AA1F8(p);
        break;
    case 4:
        fn_803A9AB8(p);
        break;
    case 6:
        if (p->alpha >= 0xf5) {
            p->alpha = 0xff;
            if (lbl_80529DEC[0x24d] == 1) {
                p->mode = 5;
                for (s32 i = 0; i < 4; i++) {
                    EffHandle* h = p->handles[i];
                    if (h != 0) {
                        h->flags |= 1;
                        h->m24 = 1;
                        p->handles[i] = 0;
                    }
                }
            } else {
                p->mode = 9;
            }
        } else {
            p->alpha += 10;
        }
        break;
    case 5:
        if (p->alpha <= 10) {
            p->alpha = 0;
            *(u8*)((u8*)lbl_8053AD68 + 0x1d) = 1;
        } else {
            p->alpha -= 10;
        }
        break;
    }
    p->frame++;
    if (p->frame >= p->anms[p->cur]->maxFrame) {
        p->frame = 0;
    }
    p->anms[p->cur]->frame = p->frame;
    p->screens[p->cur]->animation();
}



// ---- from src/Game/CountdownBlink_803AF604.cpp ----
extern "C" void fn_80458880(void* p1, s32 p2, s32 p3);
extern "C" void fn_803B35F8(void* this_, u32 flag);

extern void* lbl_8053AF80;

extern void* lbl_8053AD30;
extern "C" u32 fn_80309C4C(void* p, s32 a, s32 b);

struct MsgSinkObj2 {
    u32 m0;
    u32 m4;
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void send(void* msg);
};

struct FVec3 {
    FVec3() {}
    FVec3(f32 ax, f32 ay, f32 az) { x = ax; y = ay; z = az; }
    f32 x, y, z;
};

struct Menu_Join {
    u8 pad0[0x174];
    MsgSinkObj2* sinks[4];      // 0x174
    u8 pad184[0x244 - 0x184];
    FVec3 pos;                  // 0x244
    u8 pad250[0x2f0 - 0x250];
    FVec3 icons[4];             // 0x2f0
    s32 a320[4];                // 0x320
    s32 a330[4];
    s32 a340[4];
    s32 a350[4];
    s32 a360[4];
    s32 a370[4];
    s32 a380[4];
    s32 a390[4];
    s32 a3a0[4];
    s32 a3b0[4];
    s32 state[4];               // 0x3c0
    u8 pad3d0[0x440 - 0x3d0];
    s32 timer;                  // 0x440
    u8 pad444[0x454 - 0x444];
    s32 count;                  // 0x454
    u8 pad458[0x4ac - 0x458];
    u8 ids[4];                  // 0x4ac
    u8 pad4b0[0x4c1 - 0x4b0];
    u8 m4c1;
    u8 m4c2;
    u8 m4c3;
    u8 m4c4;
    u8 m4c5;
    u8 m4c6;
    u8 m4c7;
    u8 m4c8;
};

extern s32 lbl_804AF888[];
extern s32 lbl_804AF8CC[];
extern "C" void* fn_8013CC50(u32 id, FVec3* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);

static inline BOOL updateJoin(Menu_Join* p) {
    for (s32 i = 0; i < p->m4c8 + 1; i++) {
        s32 v = lbl_804AF888[p->m4c4];
        if (v == -1) {
            p->state[i] = 0x3e;
        } else {
            p->state[p->ids[i]] = v + 0xdb;
        }
    }
    if (lbl_804AF8CC[p->m4c4] == -1) {
        for (s32 k = 0; k < p->m4c8 + 1; k++) {
            FVec3 a(7.0f + p->icons[p->ids[k]].x, p->icons[p->ids[k]].y - 27.0f, p->icons[p->ids[k]].z);
            fn_8013CC50(0, &a, 0xcb, 1, 0, 0, 0, 1, 1.0f);
            FVec3 b(7.0f + p->icons[p->ids[k]].x, p->icons[p->ids[k]].y - 27.0f, p->icons[p->ids[k]].z);
            fn_8013CC50(0, &b, 0xcc, 1, 0, 0, 0, 1, 1.0f);
            p->pos = p->icons[p->ids[k]];
            u32 msg = 0x2000e;
            p->sinks[p->ids[k]]->send(&msg);
        }
        return TRUE;
    }
    return FALSE;
}

// NONMATCHING (99.9%): r5/r6 swap in the ranking loop.
extern "C" void fn_803AC154(Menu_Join* p) {
    BOOL done = FALSE;
    if (p->m4c8 != 0xff) {
        s32 lim = lbl_804AF8CC[p->m4c4];
        if (lim != -1) {
            if (p->m4c6 >= lim) {
                p->m4c4++;
            }
            p->m4c6++;
        }
        if (updateJoin(p)) {
            done = TRUE;
        }
    }
    if (p->m4c8 == 0xff || done) {
        s32 best = 0;
        s32 tot[4];
        p->m4c8 = 0xff;
        for (s32 i = 0; i < p->count; i++) {
            tot[i] = p->a320[i] + p->a340[i] + p->a350[i] + p->a360[i] + p->a370[i] - p->a380[i] + p->a3a0[i] + p->a3b0[i];
        }
        for (s32 j = 0; j < p->count; j++) {
            s32 t = tot[j];
            if (best < t) {
                p->m4c8 = 0;
                best = t;
                p->ids[p->m4c8] = j;
            } else if (best > 0 && best == t) {
                p->m4c8++;
                p->ids[p->m4c8] = j;
            }
        }
        p->timer = 0x96;
        p->m4c1 = 0x1f;
    }
}

struct Menu_Slide {
    u8 pad0[0x70];
    J2DPane* panes[0xd];        // 0x70
    u8 padA4[0x320 - 0xa4];
    s32 disp[4];                // 0x320
    u8 pad330[0x3c0 - 0x330];
    s32 state[4];               // 0x3c0
    u8 pad3d0[0x3f4 - 0x3d0];
    f32 ys[10];                 // 0x3f4
    u8 pad41c[0x440 - 0x41c];
    s32 timer;                  // 0x440
    u8 pad444[0x450 - 0x444];
    s32 cur;                    // 0x450
    s32 count;                  // 0x454
    u8 pad458[0x4ac - 0x458];
    u8 ids[4];                  // 0x4ac
    u8 pad4b0[0x4c1 - 0x4b0];
    u8 m4c1;
    u8 m4c2;
    u8 m4c3;
    u8 m4c4;
    u8 m4c5;
    u8 m4c6;
    u8 m4c7;
    u8 m4c8;
};

#define PANE(off) (p->panes[((off) - 0x70) / 4])
#define PY(off) (p->ys[((off) - 0x3f4) / 4])
#define MOVE_TO(off, yoff, extra) { f32 x = PANE(off)->getBounds()->i.x; PANE(off)->move(x, PY(yoff) extra); }

struct GameResult {
    u8 pad0[0x118];
    s32 mode;                   // 0x118
    s32 sub;                    // 0x11c
    u8 pad120[0x130 - 0x120];
    s32 wins[4];                // 0x130
    u8 pad140[0x1fc - 0x140];
    u8 winner[8][3];            // 0x1fc
    u8 pad214[0x243 - 0x214];
    u8 winMask;                 // 0x243
};

extern const char* lbl_804AF980[];
extern "C" void* fn_80403104(u32 type, const char* name);

// NONMATCHING (99%): winner-table index add order / mode register.
extern "C" void fn_803ABCEC(Menu_Slide* p) {
    p->timer--;
    s32 t = p->timer;
    if (t == 0) {
        p->timer = 0x96;
        p->m4c3 = 0;
        p->m4c4 = 0;
        p->m4c5 = 0;
        p->m4c6 = 0;
        s32 n = 0;
        for (s32 i = 0; i < p->count; i++) {
            if (p->m4c8 != 0xff) {
                if (i == p->ids[n]) {
                    p->state[i] = 0x3e;
                    if (p->m4c8 > n) {
                        n++;
                    }
                } else {
                    p->state[i] = 0xbd;
                }
            } else {
                p->state[i] = 0xbd;
            }
        }
        s32 mode = ((GameResult*)lbl_80529DEC)->mode;
        s32 sub = ((GameResult*)lbl_80529DEC)->sub;
        s32 k = sub;
        switch (mode) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            if (sub == 3) {
                k = 2;
            }
            break;
        case 7:
            if (sub == 2) {
                k = 1;
            }
            if (k == 3) {
                k = 2;
            }
            break;
        }
        if (p->m4c8 == 0) {
            ((GameResult*)lbl_80529DEC)->wins[p->ids[0]]++;
            ((GameResult*)lbl_80529DEC)->winMask = 0;
            ((GameResult*)lbl_80529DEC)->winMask = 1 << p->ids[0];
            if (((GameResult*)lbl_80529DEC)->mode >= 0 && ((GameResult*)lbl_80529DEC)->mode < 8 && k >= 0 && k < 3) {
                ((GameResult*)lbl_80529DEC)->winner[((GameResult*)lbl_80529DEC)->mode][k] = p->ids[0];
            }
            if (p->m4c8 != 0xff) {
                fn_80458880(lbl_8053AF80, 0x11, -1);
            }
        } else {
            if (mode >= 0 && mode < 8 && sub >= 0 && sub < 3) {
                ((GameResult*)lbl_80529DEC)->winner[mode][sub] = 0xff;
            }
            fn_80458880(lbl_8053AF80, 0x2b, -1);
        }
        fn_80458880(lbl_8053AF80, 0x2c, -1);
        p->m4c1 = 0x21;
    } else if (t >= 0x8a) {
        f32 off = -150.0f * ((f32)(12 - (t - 0x8a)) / 12.0f);
        MOVE_TO(0x70, 0x3f4, + off);
        if (p->timer == 0x8a) {
            PANE(0x70)->hide();
            if (p->m4c8 == 0) {
                ResTIMG* img = (ResTIMG*)fn_80403104('TIMG', lbl_804AF980[p->ids[0]]);
                ((J2DPicture*)PANE(0x7c))->changeTexture(img, 0);
                ((J2DPicture*)PANE(0x80))->changeTexture(img, 0);
                PANE(0x78)->show();
                MOVE_TO(0x78, 0x414, + off);
                PANE(0x7c)->show();
                PANE(0x80)->show();
            } else {
                PANE(0x74)->show();
                MOVE_TO(0x74, 0x418, + off);
            }
        }
    } else if (t >= 0x80) {
        f32 off = -150.0f * ((f32)(t - 0x80) / 12.0f);
        if (p->m4c8 == 0) {
            MOVE_TO(0x78, 0x414, + off);
        } else {
            MOVE_TO(0x74, 0x418, + off);
        }
        if (p->timer == 0x80) {
            MOVE_TO(0x70, 0x3f4, );
        }
    }
}

struct Menu_Score {
    u8 pad0[0x158];
    J2DPane* rects[4];          // 0x158
    u8 pad168[0x1a8 - 0x168];
    EffHandle* effs[4];         // 0x1a8
    u8 pad1b8[0x320 - 0x1b8];
    s32 disp[4];                // 0x320
    u8 pad330[0x3c0 - 0x330];
    s32 state[4];               // 0x3c0
    u8 pad3d0[0x438 - 0x3d0];
    s32 doneCount;              // 0x438
    u8 pad43c[0x454 - 0x43c];
    s32 count;                  // 0x454
    u8 pad458[0x4ac - 0x458];
    u8 ids[4];                  // 0x4ac
    u8 pad4b0[0x4c1 - 0x4b0];
    u8 m4c1;
    u8 pad4c2[0x4c8 - 0x4c2];
    u8 m4c8;
};

struct GameInfo {
    u8 pad0[0x150];
    s32 score[4];               // 0x150
    s32 m160[4];                // 0x160
    u8 pad170[0x190 - 0x170];
    s32 m190[4];                // 0x190
};

extern "C" void fn_803AC6FC(Menu_Score* p) {
    s32 done = 0;
    s32 best = -999999;
    s32 n = 0;
    s32 i;
    for (i = 0; i < p->count; i++) {
        if (p->disp[i] < ((GameInfo*)lbl_80529DEC)->score[i]) {
            if (p->effs[i] == 0) {
                FVec3 v(p->rects[i]->mGlobalBounds.i.x + p->rects[i]->mBounds.getWidth() / 2, 0.0f, 0.0f);
                p->effs[i] = (EffHandle*)fn_8013CC50(0, &v, 0x3dd, 0, 0, 0, 0, 1, 1.0f);
            }
            p->disp[i] += 2;
            if (p->disp[i] >= ((GameInfo*)lbl_80529DEC)->score[i]) {
                EffHandle* h = p->effs[i];
                if (h != 0) {
                    h->flags |= 1;
                    h->m24 = 1;
                    p->effs[i] = 0;
                }
                p->disp[i] = ((GameInfo*)lbl_80529DEC)->score[i];
                done++;
            }
        } else if (p->disp[i] > ((GameInfo*)lbl_80529DEC)->score[i]) {
            p->disp[i] -= 2;
            if (p->disp[i] <= ((GameInfo*)lbl_80529DEC)->score[i]) {
                p->disp[i] = ((GameInfo*)lbl_80529DEC)->score[i];
                done++;
            }
        } else {
            done++;
        }
    }
    if (done >= p->count) {
        for (s32 j = 0; j < p->count; j++) {
            s32 t = ((GameInfo*)lbl_80529DEC)->score[j];
            if (best < t) {
                p->m4c8 = 0;
                best = t;
                p->ids[p->m4c8] = j;
            } else if (best == t) {
                p->m4c8++;
                p->ids[p->m4c8] = j;
            }
        }
        for (i = 0; i < p->count; i++) {
            if (p->m4c8 != 0xff && i == p->ids[n]) {
                p->state[i] = 0x3e;
                if (p->m4c8 > n) {
                    n++;
                }
            }
        }
        if (p->m4c8 != 0xff) {
            fn_80458880(lbl_8053AF80, 0xf, -1);
            fn_80458880(lbl_8053AF80, 0x2a, -1);
        } else {
            fn_80458880(lbl_8053AF80, 0x2d, -1);
        }
        p->doneCount = 0;
        p->m4c1 = 0x1e;
    } else {
        if (done != p->doneCount) {
            p->doneCount = done;
            fn_80458880(lbl_8053AF80, 0x10, -1);
        }
        fn_80458880(lbl_8053AF80, 0xe, -1);
    }
}

extern "C" void fn_803AC998(Menu_Slide* p) {
    p->timer--;
    if (fn_80309C4C(lbl_8053AD30, 0x100, -1) != 0) {
        if (p->timer >= 0x3c) {
            if (p->cur < 2) {
                PANE(0x98)->hide();
                MOVE_TO(0x98, 0x408, );
            } else {
                if (PANE(0x94)->isVisible()) {
                    PANE(0x94)->hide();
                    MOVE_TO(0x94, 0x400, );
                }
                if (PANE(0xa0)->isVisible()) {
                    PANE(0xa0)->hide();
                    MOVE_TO(0xa0, 0x410, );
                }
            }
            PANE(0xa4)->show();
            MOVE_TO(0xa4, 0x40c, );
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
        p->timer = 0;
    }
    s32 t = p->timer;
    if (t == 0) {
        p->timer = 0x96;
        p->m4c1 = 0x1d;
    } else if (t >= 0x8a) {
        f32 off = -150.0f * ((f32)(12 - (t - 0x8a)) / 12.0f);
        if (p->cur < 2) {
            MOVE_TO(0x98, 0x408, + off);
        } else {
            if (PANE(0x94)->isVisible()) {
                MOVE_TO(0x94, 0x400, + off);
            }
            if (PANE(0xa0)->isVisible()) {
                MOVE_TO(0xa0, 0x410, + off);
            }
        }
        if (p->timer == 0x8a) {
            if (p->cur < 2) {
                PANE(0x98)->hide();
            } else {
                if (PANE(0x94)->isVisible()) {
                    PANE(0x94)->hide();
                }
                if (PANE(0xa0)->isVisible()) {
                    PANE(0xa0)->hide();
                }
            }
            PANE(0xa4)->show();
            MOVE_TO(0xa4, 0x40c, + off);
        }
    } else if (t >= 0x80) {
        f32 x = PANE(0xa4)->getBounds()->i.x;
        f32 off = -150.0f * ((f32)(t - 0x80) / 12.0f);
        PANE(0xa4)->move(x, PY(0x40c) + off);
        if (p->timer == 0x80) {
            if (p->cur < 2) {
                MOVE_TO(0x98, 0x408, );
            } else {
                if (PANE(0x94)->isVisible()) {
                    MOVE_TO(0x94, 0x400, );
                }
                if (PANE(0xa0)->isVisible()) {
                    MOVE_TO(0xa0, 0x410, );
                }
            }
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
    }
}

struct Menu_Hits {
    u8 pad0[0x3a0];
    s32 disp[4];                // 0x3a0
    s32 disp2[4];               // 0x3b0
    s32 state[4];               // 0x3c0
    u8 pad3d0[0x438 - 0x3d0];
    s32 doneCount;              // 0x438
    u8 pad43c[0x440 - 0x43c];
    s32 timer;                  // 0x440
    u8 pad444[0x454 - 0x444];
    s32 count;                  // 0x454
    u8 pad458[0x4ac - 0x458];
    u8 ids[4];                  // 0x4ac
    u8 pad4b0[0x4b8 - 0x4b0];
    u8 hits[4];                 // 0x4b8
    u8 hits2[4];                // 0x4bc
};

struct Menu_HitsF {
    u8 pad0[0x4c1];
    u8 m4c1;
    u8 pad4c2[0x4c8 - 0x4c2];
    u8 m4c8;
    u8 pad4c9[0x4db - 0x4c9];
    u8 m4db;
};

extern "C" void fn_803ACDA4(Menu_Hits* p) {
    Menu_HitsF* f = (Menu_HitsF*)p;
    s32 done = 0;
    s32 n = 0;
    s32 best = 0;
    u8 cnt[4];
    s32 pen[4];
    for (s32 i = 0; i < p->count; i++) {
        cnt[i] = 0;
    }
    for (s32 i = 0; i < p->count; i++) {
        cnt[p->hits2[i]]++;
    }
    for (s32 i = 0; i < p->count; i++) {
        if (cnt[i] == 3) {
            pen[i] = 500;
        } else if (cnt[i] == 2) {
            pen[i] = 300;
        } else if (cnt[i] == 1) {
            pen[i] = 100;
        } else {
            pen[i] = 0;
        }
    }
    for (s32 i = 0; i < p->count; i++) {
        if (p->disp2[i] < pen[i]) {
            p->disp2[i] += 2;
        }
        if (p->disp2[i] >= pen[i]) {
            p->disp2[i] = pen[i];
            done++;
        }
    }
    if (done >= p->count) {
        for (s32 j = 0; j < p->count; j++) {
            if (best < pen[j]) {
                f->m4c8 = 0;
                best = pen[j];
                p->ids[f->m4c8] = j;
            } else if (best > 0 && best == pen[j]) {
                f->m4c8++;
                p->ids[f->m4c8] = j;
            }
        }
        for (s32 i = 0; i < p->count; i++) {
            if (f->m4c8 != 0xff && i == p->ids[n]) {
                p->state[i] = 0x3e;
                f->m4db |= (u8)(1 << (i + 4));
                if (f->m4c8 > n) {
                    n++;
                }
            }
        }
        if (f->m4c8 != 0xff) {
            fn_80458880(lbl_8053AF80, 0xf, -1);
            fn_80458880(lbl_8053AF80, 0x2a, -1);
        } else {
            fn_80458880(lbl_8053AF80, 0x2d, -1);
        }
        if (p->count == 3) {
            if (f->m4c8 == 0) {
                *(s32*)(lbl_80529DEC + 0x64) = p->ids[0];
            } else {
                s32 r = (s32)(3.0f * lbl_8053AAF8->rnd.get_ufloat_1());
                if (r >= 3) {
                    r = 2;
                }
                *(s32*)(lbl_80529DEC + 0x64) = r;
            }
        }
        p->doneCount = 0;
        p->timer = 0x96;
        f->m4c1 = 0x1b;
    } else {
        if (done != p->doneCount) {
            p->doneCount = done;
            fn_80458880(lbl_8053AF80, 0x10, -1);
        }
        fn_80458880(lbl_8053AF80, 0xe, -1);
    }
}

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

extern "C" void fn_803AD4B0(Menu_Hits* p) {
    Menu_HitsF* f = (Menu_HitsF*)p;
    s32 done = 0;
    s32 n = 0;
    s32 best = 0;
    u8 cnt[4];
    s32 pen[4];
    for (s32 i = 0; i < p->count; i++) {
        cnt[i] = 0;
    }
    for (s32 i = 0; i < p->count; i++) {
        cnt[p->hits[i]]++;
    }
    for (s32 i = 0; i < p->count; i++) {
        if (cnt[i] == 3) {
            pen[i] = -500;
        } else if (cnt[i] == 2) {
            pen[i] = -300;
        } else if (cnt[i] == 1) {
            pen[i] = -100;
        } else {
            pen[i] = 0;
        }
    }
    for (s32 i = 0; i < p->count; i++) {
        if (p->disp[i] > pen[i]) {
            p->disp[i] -= 2;
        }
        if (p->disp[i] <= pen[i]) {
            p->disp[i] = pen[i];
            done++;
        }
    }
    if (done >= p->count) {
        for (s32 j = 0; j < p->count; j++) {
            if (best > pen[j]) {
                f->m4c8 = 0;
                best = pen[j];
                p->ids[f->m4c8] = j;
            } else if (best < 0 && best == pen[j]) {
                f->m4c8++;
                p->ids[f->m4c8] = j;
            }
        }
        for (s32 i = 0; i < p->count; i++) {
            if (f->m4c8 != 0xff && i == p->ids[n]) {
                p->state[i] = 0x3e;
                f->m4db |= (u8)(1 << i);
                if (f->m4c8 > n) {
                    n++;
                }
            }
        }
        if (f->m4c8 != 0xff) {
            fn_80458880(lbl_8053AF80, 0xf, -1);
            fn_80458880(lbl_8053AF80, 0x2a, -1);
        } else {
            fn_80458880(lbl_8053AF80, 0x2d, -1);
        }
        p->doneCount = 0;
        p->timer = 0x96;
        f->m4c1 = 0x18;
    } else {
        if (done != p->doneCount) {
            p->doneCount = done;
            fn_80458880(lbl_8053AF80, 0x10, -1);
        }
        fn_80458880(lbl_8053AF80, 0xe, -1);
    }
}

extern "C" void fn_803AD894(Menu_Slide* p) {
    p->timer--;
    if (fn_80309C4C(lbl_8053AD30, 0x100, -1) != 0) {
        if (p->timer >= 0x3c) {
            if (PANE(0x94)->isVisible()) {
                PANE(0x94)->hide();
                MOVE_TO(0x94, 0x400, );
            }
            if (PANE(0xa0)->isVisible()) {
                PANE(0xa0)->hide();
                MOVE_TO(0xa0, 0x410, );
            }
            PANE(0x9c)->show();
            MOVE_TO(0x9c, 0x404, );
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
        p->m4c1 = 0x17;
    } else if (t >= 0x8a) {
        f32 off = -150.0f * ((f32)(12 - (t - 0x8a)) / 12.0f);
        if (PANE(0x94)->isVisible()) {
            MOVE_TO(0x94, 0x400, + off);
        }
        if (PANE(0xa0)->isVisible()) {
            MOVE_TO(0xa0, 0x410, + off);
        }
        if (p->timer == 0x8a) {
            if (PANE(0x94)->isVisible()) {
                PANE(0x94)->hide();
            }
            if (PANE(0xa0)->isVisible()) {
                PANE(0xa0)->hide();
            }
            PANE(0x9c)->show();
            MOVE_TO(0x9c, 0x404, + off);
        }
    } else if (t >= 0x80) {
        f32 x = PANE(0x9c)->getBounds()->i.x;
        f32 off = -150.0f * ((f32)(t - 0x80) / 12.0f);
        PANE(0x9c)->move(x, PY(0x404) + off);
        if (p->timer == 0x80) {
            if (PANE(0x94)->isVisible()) {
                MOVE_TO(0x94, 0x400, );
            }
            if (PANE(0xa0)->isVisible()) {
                MOVE_TO(0xa0, 0x410, );
            }
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

struct Menu_Coin {
    u8 pad0[0x174];
    MsgSinkObj2* sinks[4];      // 0x174
    u8 pad184[0x380 - 0x184];
    s32 disp[4];                // 0x380
    u8 pad390[0x3c0 - 0x390];
    s32 state[4];               // 0x3c0
    u8 pad3d0[0x438 - 0x3d0];
    s32 doneCount;              // 0x438
    u8 pad43c[0x440 - 0x43c];
    s32 timer;                  // 0x440
    u8 pad444[0x448 - 0x444];
    s32 phase;                  // 0x448
    u8 pad44c[0x450 - 0x44c];
    s32 cur;                    // 0x450
    s32 count;                  // 0x454
    u8 pad458[0x4ac - 0x458];
    u8 ids[4];                  // 0x4ac
    u8 pad4b0[0x4c1 - 0x4b0];
    u8 m4c1;
    u8 m4c2;
    u8 m4c3;
    u8 m4c4;
    u8 m4c5;
    u8 m4c6;
    u8 m4c7;
    u8 m4c8;
};

struct GameCoins {
    u8 pad0[0x170];
    s32 coins[4];               // 0x170
};

extern s32 lbl_804AF948[];
extern s32 lbl_804AF910[];
extern "C" s32 fn_80138A30(void* game);
extern "C" void* fn_80403414(s32 idx);
extern "C" s32 fn_80403070(void* p);

extern "C" void fn_803ADE9C(Menu_Coin* p) {
    s32 done = 0;
    p->timer--;
    if (p->timer == 0x78) {
        s32 goal[4];
        p->m4c8 = 0xff;
        p->phase = 0;
        p->m4c3 = 0;
        p->m4c5 = 0;
        for (s32 i = 0; i < p->count; i++) {
            goal[i] = ((GameCoins*)lbl_80529DEC)->coins[i] * 100;
        }
        for (s32 i = 0; i < p->count; i++) {
            if (p->disp[i] < goal[i]) {
                p->disp[i] += 100;
                if (p->m4c8 == 0xff) {
                    p->m4c8 = 0;
                } else {
                    p->m4c8++;
                }
                p->ids[p->m4c8] = i;
                u32 msg = 0x10004;
                p->sinks[i]->send(&msg);
            } else {
                p->disp[i] = goal[i];
                done++;
            }
        }
        if (done >= p->count) {
            p->doneCount++;
            p->timer = 1;
        } else {
            fn_80458880(lbl_8053AF80, 0x22, -1);
        }
    } else if (p->timer == 0) {
        for (s32 i = 0; i < p->count; i++) {
            p->state[i] = 0x3e;
        }
        if (p->doneCount != 0) {
            p->m4c8 = 0xff;
            p->doneCount = 0;
            p->timer = 0x96;
            u8 any = 0;
            for (s32 i = 0; i < fn_80138A30(lbl_8053AAF8); i++) {
                if (fn_80403070(fn_80403414(i)) > 0) {
                    any = 1;
                }
            }
            if (any) {
                p->m4c1 = 0x14;
            } else if (p->cur < 2) {
                p->m4c1 = 0x16;
            } else {
                p->m4c1 = 0x1c;
            }
            u8 zero = 1;
            for (s32 i = 0; i < p->count; i++) {
                if (p->disp[i] != 0) {
                    zero = 0;
                    break;
                }
            }
            if (zero) {
                fn_80458880(lbl_8053AF80, 0x2a, -1);
            }
        } else {
            p->timer = 0x96;
            fn_80458880(lbl_8053AF80, 0x2d, -1);
        }
    }
    if (p->m4c8 != 0xff) {
        if (p->phase == 0) {
            p->m4c5++;
            if (p->m4c5 <= 10) {
                for (s32 i = 0; i < p->m4c8 + 1; i++) {
                    p->state[p->ids[i]] = 0xaf;
                }
            } else {
                p->phase = 1;
                p->m4c5 = 0;
            }
        } else if (p->phase == 1) {
            s32 lim = lbl_804AF948[p->m4c3];
            if (lim != -1) {
                if (p->m4c5 >= lim) {
                    p->m4c3++;
                }
                p->m4c5++;
            }
            for (s32 i = 0; i < p->m4c8 + 1; i++) {
                p->state[p->ids[i]] = lbl_804AF910[p->m4c3] + 0xbd;
            }
            if (lbl_804AF948[p->m4c3] == -1) {
                p->phase = 2;
            }
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

extern "C" void fn_803AE598(Menu_Join* p) {
    BOOL done = FALSE;
    if (p->m4c8 != 0xff) {
        s32 lim = lbl_804AF8CC[p->m4c4];
        if (lim != -1) {
            if (p->m4c6 >= lim) {
                p->m4c4++;
            }
            p->m4c6++;
        }
        if (updateJoin(p)) {
            done = TRUE;
        }
    }
    if (p->m4c8 == 0xff || done) {
        p->m4c8 = 0xff;
        p->m4c1 = 0x12;
    }
}


struct Menu_Rank {
    u8 pad0[0x330];
    s32 target[4];              // 0x330
    s32 disp340[4];             // 0x340
    s32 disp350[4];             // 0x350
    s32 disp[4];                // 0x360
    u8 pad370[0x390 - 0x370];
    s32 src390[4];              // 0x390
    s32 disp3a0[4];             // 0x3a0
    u8 pad3b0[0x3c0 - 0x3b0];
    s32 state[4];               // 0x3c0
    u8 pad3d0[0x438 - 0x3d0];
    s32 doneCount;              // 0x438
    u8 pad43c[0x440 - 0x43c];
    s32 timer;                  // 0x440
    u8 pad444[0x450 - 0x444];
    s32 cur;                    // 0x450
    s32 count;                  // 0x454
    u8 pad458[0x4ac - 0x458];
    u8 ids[4];                  // 0x4ac
    u8 pad4b0[0x4c1 - 0x4b0];
    u8 m4c1;
    u8 pad4c2[0x4c8 - 0x4c2];
    u8 m4c8;
};

// NONMATCHING (99.8%): r6/r7 swap in the ranking loop.
extern "C" void fn_803AE810(Menu_Rank* p) {
    static const s32 tbl0[4] = {300, 150, 50, 0};
    static const s32 tbl1[3] = {300, 150, 0};
    static const s32 tbl2[2] = {150, 0};
    s32 done = 0;
    s32 n = 0;
    u8 any = 0;
    s32 best = 0;
    for (s32 i = 0; i < p->count; i++) {
        if (((GameInfo*)lbl_80529DEC)->m160[i] != 0) {
            any = 1;
            break;
        }
    }
    if (any) {
        s32 vals[4];
        s32 used[4];
        s32 placed = 0;
        for (s32 i = 0; i < p->count; i++) {
            used[i] = 0;
            vals[i] = ((GameInfo*)lbl_80529DEC)->m160[i];
        }
        while (true) {
            s32 top = -1;
            for (s32 i = 0; i < p->count; i++) {
                if (used[i] == 0 && top < vals[i]) {
                    top = vals[i];
                }
            }
            s32 cnt = 0;
            for (s32 i = 0; i < p->count; i++) {
                if (used[i] == 0 && top == vals[i]) {
                    if (vals[i] == 0) {
                        p->target[i] = 0;
                    } else {
                        switch (p->cur) {
                        case 0:
                            p->target[i] = tbl0[placed];
                            break;
                        case 1:
                            p->target[i] = tbl1[placed];
                            break;
                        case 2:
                            p->target[i] = tbl2[placed];
                            break;
                        }
                    }
                    used[i] = 1;
                    cnt++;
                }
            }
            placed += cnt;
            if (placed >= p->count) {
                break;
            }
        }
    } else {
        for (s32 i = 0; i < p->count; i++) {
            p->target[i] = 0;
        }
    }
    for (s32 i = 0; i < p->count; i++) {
        if (p->disp[i] < p->target[i]) {
            p->disp[i] += 2;
        }
        if (p->disp[i] >= p->target[i]) {
            p->disp[i] = p->target[i];
            done++;
        }
    }
    if (done >= p->count) {
        for (s32 j = 0; j < p->count; j++) {
            s32 t = p->target[j];
            if (best < t) {
                p->m4c8 = 0;
                best = t;
                p->ids[p->m4c8] = j;
            } else if (best > 0 && best == t) {
                p->m4c8++;
                p->ids[p->m4c8] = j;
            }
        }
        for (s32 i = 0; i < p->count; i++) {
            if (p->m4c8 != 0xff && i == p->ids[n]) {
                p->state[i] = 0x3e;
                if (p->m4c8 > n) {
                    n++;
                }
            }
        }
        if (p->m4c8 != 0xff) {
            fn_80458880(lbl_8053AF80, 0xf, -1);
            fn_80458880(lbl_8053AF80, 0x2a, -1);
        } else {
            fn_80458880(lbl_8053AF80, 0x2d, -1);
        }
        p->doneCount = 0;
        p->m4c1 = 0x11;
    } else {
        if (done != p->doneCount) {
            p->doneCount = done;
            fn_80458880(lbl_8053AF80, 0x10, -1);
        }
        fn_80458880(lbl_8053AF80, 0xe, -1);
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

extern "C" void fn_803AEF08(Menu_Join* p) {
    BOOL done = FALSE;
    if (p->m4c8 != 0xff) {
        s32 lim = lbl_804AF8CC[p->m4c4];
        if (lim != -1) {
            if (p->m4c6 >= lim) {
                p->m4c4++;
            }
            p->m4c6++;
        }
        if (updateJoin(p)) {
            done = TRUE;
        }
        if (done) {
            p->m4c8 = 0xff;
            p->m4c1 = 0xf;
        }
    } else {
        p->timer--;
        if (p->timer == 0) {
            fn_80458880(lbl_8053AF80, 0x2d, -1);
            p->timer = 0x96;
            p->m4c1 = 0xf;
        }
    }
}

// NONMATCHING (99.8%): r6/r7 swap in the ranking loop.
extern "C" void fn_803AF1B0(Menu_Rank* p) {
    static const s32 tbl0[4] = {300, 150, 50, 0};
    static const s32 tbl1[3] = {300, 150, 0};
    static const s32 tbl2[2] = {150, 0};
    s32 done = 0;
    s32 n = 0;
    u8 any = 0;
    s32 best = 0;
    for (s32 i = 0; i < p->count; i++) {
        if (p->src390[i] != 0) {
            any = 1;
            break;
        }
    }
    if (any) {
        s32 vals[4];
        s32 used[4];
        s32 placed = 0;
        for (s32 i = 0; i < p->count; i++) {
            used[i] = 0;
            vals[i] = p->src390[i];
        }
        while (true) {
            s32 top = -1;
            for (s32 i = 0; i < p->count; i++) {
                if (used[i] == 0 && top < vals[i]) {
                    top = vals[i];
                }
            }
            s32 cnt = 0;
            for (s32 i = 0; i < p->count; i++) {
                if (used[i] == 0 && top == vals[i]) {
                    if (vals[i] == 0) {
                        p->target[i] = 0;
                    } else {
                        switch (p->cur) {
                        case 0:
                            p->target[i] = tbl0[placed];
                            break;
                        case 1:
                            p->target[i] = tbl1[placed];
                            break;
                        case 2:
                            p->target[i] = tbl2[placed];
                            break;
                        }
                    }
                    used[i] = 1;
                    cnt++;
                }
            }
            placed += cnt;
            if (placed >= p->count) {
                break;
            }
        }
    } else {
        for (s32 i = 0; i < p->count; i++) {
            p->target[i] = 0;
        }
    }
    for (s32 i = 0; i < p->count; i++) {
        if (p->disp350[i] < p->target[i]) {
            p->disp350[i] += 2;
        }
        if (p->disp350[i] >= p->target[i]) {
            p->disp350[i] = p->target[i];
            done++;
        }
    }
    if (done >= p->count) {
        for (s32 j = 0; j < p->count; j++) {
            s32 t = p->target[j];
            if (best < t) {
                p->m4c8 = 0;
                best = t;
                p->ids[p->m4c8] = j;
            } else if (best > 0 && best == t) {
                p->m4c8++;
                p->ids[p->m4c8] = j;
            }
        }
        for (s32 i = 0; i < p->count; i++) {
            if (p->m4c8 != 0xff && i == p->ids[n]) {
                p->state[i] = 0x3e;
                if (p->m4c8 > n) {
                    n++;
                }
            }
        }
        if (p->m4c8 != 0xff) {
            fn_80458880(lbl_8053AF80, 0xf, -1);
            fn_80458880(lbl_8053AF80, 0x2a, -1);
        } else {
            p->timer = 0x3c;
        }
        p->doneCount = 0;
        p->m4c1 = 0xe;
    } else {
        if (done != p->doneCount) {
            p->doneCount = done;
            fn_80458880(lbl_8053AF80, 0x10, -1);
        }
        fn_80458880(lbl_8053AF80, 0xe, -1);
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


extern "C" void fn_803AF79C(Menu_Slide* p) {
    p->timer--;
    if (fn_80309C4C(lbl_8053AD30, 0x100, -1) != 0) {
        if (p->timer >= 0x3c) {
            PANE(0x8c)->hide();
            { f32 x = PANE(0x8c)->getBounds()->i.x; PANE(0x8c)->move(x, PY(0x3f8)); }
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
        p->timer = 0;
    }
    s32 t = p->timer;
    if (t == 0) {
        s32 sum = 0;
        for (s32 i = 0; i < p->count; i++) {
            sum += p->disp[i];
        }
        // NONMATCHING: r7/r8 swap (game pointer vs. state loop cursor)
        p->timer = 0x96 + sum % 9 + (s32)(100.0f * lbl_8053AAF8->rnd.get_ufloat_1());
        p->m4c4 = 0;
        p->m4c6 = 0;
        for (s32 i = 0; i < p->count; i++) {
            p->state[i] = 0x3e;
        }
        p->m4c1 = 0xc;
    } else if (t >= 0x8a) {
        f32 off = -150.0f * ((f32)(12 - (t - 0x8a)) / 12.0f);
        { f32 x = PANE(0x8c)->getBounds()->i.x; PANE(0x8c)->move(x, PY(0x3f8) + off); }
        if (p->timer == 0x8a) {
            PANE(0x8c)->hide();
        }
    } else if (t >= 0x80) {
        if (t == 0x80) {
            { f32 x = PANE(0x8c)->getBounds()->i.x; PANE(0x8c)->move(x, PY(0x3f8)); }
            fn_80458880(lbl_8053AF80, 0x2c, -1);
        }
    }
}

extern "C" void fn_803AFA78(Menu_Join* p) {
    BOOL done = FALSE;
    if (p->m4c8 != 0xff) {
        s32 lim = lbl_804AF8CC[p->m4c4];
        if (lim != -1) {
            if (p->m4c6 >= lim) {
                p->m4c4++;
            }
            p->m4c6++;
        }
        if (updateJoin(p)) {
            done = TRUE;
        }
    }
    if (p->m4c8 == 0xff || done) {
        p->m4c8 = 0xff;
        p->m4c1 = 0xf;
    }
}


// NONMATCHING (99.8%): r6/r7 swap in the ranking loop.
extern "C" void fn_803AFCF0(Menu_Rank* p) {
    static const s32 tbl0[4] = {300, 150, 50, 0};
    static const s32 tbl1[3] = {300, 150, 0};
    static const s32 tbl2[2] = {150, 0};
    s32 done = 0;
    s32 n = 0;
    u8 any = 0;
    s32 best = 0;
    for (s32 i = 0; i < p->count; i++) {
        if (((GameInfo*)lbl_80529DEC)->m190[i] != 0) {
            any = 1;
            break;
        }
    }
    if (any) {
        s32 vals[4];
        s32 used[4];
        s32 placed = 0;
        for (s32 i = 0; i < p->count; i++) {
            used[i] = 0;
            vals[i] = ((GameInfo*)lbl_80529DEC)->m190[i];
        }
        while (true) {
            s32 top = -1;
            for (s32 i = 0; i < p->count; i++) {
                if (used[i] == 0 && top < vals[i]) {
                    top = vals[i];
                }
            }
            s32 cnt = 0;
            for (s32 i = 0; i < p->count; i++) {
                if (used[i] == 0 && top == vals[i]) {
                    if (vals[i] == 0) {
                        p->target[i] = 0;
                    } else {
                        switch (p->cur) {
                        case 0:
                            p->target[i] = tbl0[placed];
                            break;
                        case 1:
                            p->target[i] = tbl1[placed];
                            break;
                        case 2:
                            p->target[i] = tbl2[placed];
                            break;
                        }
                    }
                    used[i] = 1;
                    cnt++;
                }
            }
            placed += cnt;
            if (placed >= p->count) {
                break;
            }
        }
    } else {
        for (s32 i = 0; i < p->count; i++) {
            p->target[i] = 0;
        }
    }
    for (s32 i = 0; i < p->count; i++) {
        if (p->disp340[i] < p->target[i]) {
            p->disp340[i] += 2;
        }
        if (p->disp340[i] >= p->target[i]) {
            p->disp340[i] = p->target[i];
            done++;
        }
    }
    if (done >= p->count) {
        for (s32 j = 0; j < p->count; j++) {
            s32 t = p->target[j];
            if (best < t) {
                p->m4c8 = 0;
                best = t;
                p->ids[p->m4c8] = j;
            } else if (best > 0 && best == t) {
                p->m4c8++;
                p->ids[p->m4c8] = j;
            }
        }
        for (s32 i = 0; i < p->count; i++) {
            if (p->m4c8 != 0xff && i == p->ids[n]) {
                p->state[i] = 0x3e;
                if (p->m4c8 > n) {
                    n++;
                }
            }
        }
        if (p->m4c8 != 0xff) {
            fn_80458880(lbl_8053AF80, 0xf, -1);
            fn_80458880(lbl_8053AF80, 0x2a, -1);
        } else {
            fn_80458880(lbl_8053AF80, 0x2d, -1);
        }
        p->doneCount = 0;
        p->m4c1 = 0xa;
    } else {
        if (done != p->doneCount) {
            p->doneCount = done;
            fn_80458880(lbl_8053AF80, 0x10, -1);
        }
        fn_80458880(lbl_8053AF80, 0xe, -1);
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

struct TagPair {
    u64 tag[2];
};

struct Menu_Intro {
    u8 pad0[0x10];
    J2DScreen* screens[4];      // 0x10
    u8 pad20[0x41c - 0x20];
    f32 y41c;                   // 0x41c
    f32 y420;                   // 0x420
    f32 y424;                   // 0x424
    u8 pad428[0x440 - 0x428];
    s32 timer;                  // 0x440
    u8 pad444[0x450 - 0x444];
    s32 cur;                    // 0x450
    s32 count;                  // 0x454
    u8 pad458[0x460 - 0x458];
    s16 m460[4];                // 0x460
    u8 pad468[0x4bc - 0x468];
    u8 ready[4];                // 0x4bc
    u8 pad4c0;
    u8 m4c1;
    u8 m4c2;
    u8 pad4c3[0x4c9 - 0x4c3];
    u8 alphaTitle[13];          // 0x4c9
    u8 alpha3[3];               // 0x4d6
    u8 alpha[2];                // 0x4d9
};

struct IntroTags {
    u64 title[13];
    u64 p3[4][3];
    u64 p2[4][2];
};

extern TagPair lbl_804762D0[];
extern u8 lbl_8050DB0C[];
extern "C" u8 fn_80389BF0(s32 idx, s32 id);

extern IntroTags lbl_80476208;

// NONMATCHING (97.5%): register allocation of the timing locals.
extern "C" void fn_803B03E8(Menu_Intro* p) {
    IntroTags* tbl = &lbl_80476208;
    s32 t0 = *(s16*)(lbl_8050DB0C + 0x260);
    s32 t1 = *(s16*)(lbl_8050DB0C + 0x262);
    s32 start = *(s16*)(lbl_8050DB0C + 0x264);
    s32 dur = *(s16*)(lbl_8050DB0C + 0x266);
    s32 gap = *(s16*)(lbl_8050DB0C + 0x268);
    s32 total = start + dur + gap * (p->count - 1);
    if (total < t0 + t1) {
        total = t0 + t1;
    }
    p->timer++;
    if (p->timer > t0 && p->timer <= t0 + t1) {
        s32 d = p->timer - t0;
        f32 x = p->screens[p->cur]->search('Pmmwk02')->getBounds()->i.x;
        f32 y = 200.0f * ((f32)(d * d) / (f32)(t1 * t1));
        p->screens[p->cur]->search('Pmmwk02')->move(x, p->y41c - y);
        if (p->cur < 2) {
            for (s32 k = 0; k < 13; k++) {
                p->screens[p->cur]->search(tbl->title[k])->setAlpha((u8)(p->alphaTitle[k] * (1.0f - (f32)d / (f32)t1)));
            }
        }
    }
    if (p->timer > start && p->timer <= start + dur + gap * (p->count - 1)) {
        s32 off = 0;
        u64 (*r3)[3] = tbl->p3;
        u64 (*r2)[2] = tbl->p2;
        for (s32 i = 0; i < p->count; i++, r3++, r2++) {
            if (p->timer >= start + off) {
                s32 d = p->timer - (start + off);
                f32 y = 200.0f * ((f32)(d * d) / (f32)(dur * dur));
                f32 x = p->screens[p->cur]->search((*r3)[2])->getBounds()->i.x;
                p->screens[p->cur]->search((*r3)[2])->move(x, p->y420 + y);
                x = p->screens[p->cur]->search((*r2)[1])->getBounds()->i.x;
                p->screens[p->cur]->search((*r2)[1])->move(x, p->y424 + y);
                if (p->cur < 2) {
                    for (s32 k = 0; k < 3; k++) {
                        p->screens[p->cur]->search((*r3)[k])->setAlpha((u8)(p->alpha3[k] * (1.0f - (f32)d / (f32)dur)));
                    }
                }
                if (p->cur < 2) {
                    for (s32 k = 0; k < 2; k++) {
                        p->screens[p->cur]->search((*r2)[k])->setAlpha((u8)(p->alpha[k] * (1.0f - (f32)d / (f32)dur)));
                    }
                }
            }
            off += gap;
        }
    }
    if (total <= p->timer) {
        p->m4c2 = 0;
        p->timer = 0x96;
        p->m4c1 = 8;
    }
}

// NONMATCHING (99.5%): register allocation in the slide loops.
extern "C" void fn_803B0FD4(Menu_Intro* p) {
    p->timer++;
    s32 end;
    s32 t1 = *(s16*)(lbl_8050DB0C + 0x25a);
    s32 t2 = *(s16*)(lbl_8050DB0C + 0x25c);
    s32 dist = *(s16*)(lbl_8050DB0C + 0x25e);
    end = t1 + t2;
    if (p->timer <= end) {
        if (p->timer <= t1) {
            f32 off = (f32)dist * ((f32)(p->timer * p->timer) / (f32)(t1 * t1));
            for (s32 i = 0; i < p->count; i++) {
                f32 x = p->screens[p->cur]->search(lbl_804762D0[i].tag[1])->getBounds()->i.x;
                p->screens[p->cur]->search(lbl_804762D0[i].tag[1])->move(x, p->y424 + off);
            }
        } else if (p->timer <= end) {
            s32 d = p->timer - t1;
            f32 off = ((f32)dist + 40.0f) * ((f32)(d * d) / (f32)(t2 * t2));
            for (s32 i = 0; i < p->count; i++) {
                f32 x = p->screens[p->cur]->search(lbl_804762D0[i].tag[1])->getBounds()->i.x;
                p->screens[p->cur]->search(lbl_804762D0[i].tag[1])->move(x, (p->y424 + (f32)dist) - off);
                f32 a = 1.0f - (f32)(p->timer - t1) / (f32)t2;
                if (p->cur < 2) {
                    for (s32 k = 0; k < 2; k++) {
                        p->screens[p->cur]->search(lbl_804762D0[i].tag[k])->setAlpha((u8)(p->alpha[k] * a));
                    }
                }
            }
        }
    }
    if (p->timer >= end) {
        if (p->cur == 1) {
            if (p->ready[0] == 0xff && fn_80389BF0(0, 0x103)) {
                p->ready[0] = 1;
            }
            if (p->ready[1] == 0xff && fn_80389BF0(1, 0x104)) {
                p->ready[1] = 1;
            }
            if (p->ready[2] == 0xff && fn_80389BF0(2, 0x105)) {
                p->ready[2] = 1;
            }
            p->ready[3] = 1;
        } else {
            if (p->ready[0] == 0xff && fn_80389BF0(0, 0xde)) {
                p->ready[0] = 1;
            }
            if (p->ready[1] == 0xff && fn_80389BF0(1, 0xdf)) {
                p->ready[1] = 1;
            }
            if (p->ready[2] == 0xff && fn_80389BF0(2, 0xe0)) {
                p->ready[2] = 1;
            }
            if (p->ready[3] == 0xff && fn_80389BF0(3, 0xe1)) {
                p->ready[3] = 1;
            }
        }
        if (p->ready[0] == 1 && p->ready[1] == 1 && p->ready[2] == 1 && p->ready[3] == 1) {
            for (s32 i = 0; i < p->count; i++) {
                p->ready[i] = 0xff;
                p->m460[i] = 0;
            }
            p->m4c1 = 6;
        }
    }
}

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
    if ((mode == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 1 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 2 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 3 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 4 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 5 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 6 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 7 && *(s32*)(lbl_80529DEC + 0x11c) == 1)
        || (mode == 8 && *(s32*)(lbl_80529DEC + 0x11c) == 3)
        || (mode == 10 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || *(u8*)(lbl_80529DEC + 0x237) == 8) {
        return;
    }
    fn_8013B490(lbl_8053AB10);
    (*(VPane_803B31AC**)(p + 0x170))->setAlpha(*(u8*)(p + 0x4c2));
    (*(VPane_803B31AC**)(p + 0x170))->drawRect(0, 0, 0, lbl_805433C8, lbl_805433C8, lbl_805433D8, lbl_805433DC);
}

extern "C" void fn_803B3358(void* this_, u32 kind) {
    switch (kind) {
    case 0:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 1:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 2:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 3:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 4:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 5:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 6:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 7:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    }
}

extern "C" void fn_803B35F8(void* this_, u32 kind) {
    switch (kind) {
    case 0:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 1:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 2:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 3:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 4:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 5:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 6:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 7:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    case 8:
        for (s32 i = 0; i < *(s32*)((u8*)this_ + 0x454); i++) {
        }
        break;
    }
}

struct DelObj {
    virtual ~DelObj();
};

struct DelObj8 {
    u32 m0;
    u32 m4;
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual ~DelObj8();
};

struct Menu_Dtor {
    void* vt;
    DelObj* scr04[3];           // 0x04
    DelObj* scr10[3];           // 0x10
    DelObj* m1c;                // 0x1c
    DelObj* m20;                // 0x20
    DelObj* m24[3];             // 0x24
    u8 pad30[0x170 - 0x30];
    DelObj* m170;               // 0x170
    DelObj8* sinks[4];          // 0x174
    DelObj8* m184;              // 0x184
    EffHandle* e188[4];         // 0x188
    EffHandle* e198[4];         // 0x198
    EffHandle* e1a8[4];         // 0x1a8
    EffHandle* e1b8[4];         // 0x1b8
    JPABaseEmitter* emitters[30]; // 0x1c8
};

extern void* lbl_804AF9A0[];
extern void* lbl_8053ADA0;
extern "C" void* fn_8013C824(void);

static inline void killEmitter(JPABaseEmitter*& e) {
    if (e != 0) {
        JPAEmitterManager* m = *(JPAEmitterManager**)((u8*)fn_8013C824() + 0xc); m->forceDeleteEmitter(e);
        e = 0;
    }
}

extern "C" Menu_Dtor* fn_803B6D04(Menu_Dtor* p, s16 freeFlag) {
    if (p != 0) {
        p->vt = lbl_804AF9A0;
        for (s32 i = 0; i < 30; i++) {
            killEmitter(p->emitters[i]);
        }
        for (s32 i = 0; i < 4; i++) {
            {
                EffHandle* h = p->e1a8[i];
                if (h != 0) {
                    h->flags |= 1;
                    h->m24 = 1;
                    p->e1a8[i] = 0;
                }
            }
            {
                EffHandle* h = p->e188[i];
                if (h != 0) {
                    h->flags |= 1;
                    h->m24 = 1;
                    p->e188[i] = 0;
                }
            }
            {
                EffHandle* h = p->e198[i];
                if (h != 0) {
                    h->flags |= 1;
                    h->m24 = 1;
                    p->e198[i] = 0;
                }
            }
            {
                EffHandle* h = p->e1b8[i];
                if (h != 0) {
                    h->flags |= 1;
                    h->m24 = 1;
                    p->e1b8[i] = 0;
                }
            }
        }
        (*(JKRHeap**)(lbl_80529DEC + 8))->getTotalFreeSize();
        for (s32 i = 0; i < 3; i++) {
            delete p->scr04[i];
            p->scr04[i] = 0;
            delete p->scr10[i];
            p->scr10[i] = 0;
        }
        delete p->m20;
        p->m20 = 0;
        delete p->m1c;
        p->m1c = 0;
        for (s32 i = 0; i < 3; i++) {
            delete p->m24[i];
            p->m24[i] = 0;
        }
        delete p->m170;
        p->m170 = 0;
        for (s32 i = 0; i < 4; i++) {
            delete p->sinks[i];
            p->sinks[i] = 0;
        }
        delete p->m184;
        p->m184 = 0;
        lbl_8053ADA0 = 0;
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
