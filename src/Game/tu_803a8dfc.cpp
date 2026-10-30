// TU 0x803a8dfc-0x803b7dcc.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JParticle/JPAEmitter.h"
#include "Game/ItemBase.h"

extern "C" int snprintf(char* s, unsigned long n, const char* fmt, ...);
extern "C" void fn_8013B414(void* a, f32* b, s32 c);
extern const char lbl_805433C0;
extern const char lbl_805433C4;
extern char lbl_8047641C[];
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, DrawRec* rec, f32 sx, f32 sy);

struct SprMgr_803A8F5C {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void* v18(s32 kind, char* name);
};

struct VPane_803A8F5C {
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
extern const f32 lbl_805433D8;
extern const f32 lbl_805433DC;

struct MsgRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct MsgGame {
    u8 pad[0xb4];
    MsgRandom rnd;
    s32 countPlayers() const {
        const MsgGame* game = this;
        s32 count = 0;
        for (u32 i = 0; i < 4; i++) {
            if (game->pad[0x82] & (u8)(1 << i)) count++;
        }
        return count;
    }
};
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
extern s32 lbl_804AF888[];

extern "C" f32* getBounds__7J2DPaneFv(void* this_);
extern "C" s32 fn_80388EEC(s32 idx);
extern "C" void fn_80458880(void* obj, s32 id, s32 v);
extern void* lbl_8053AF80;
extern u8 lbl_8050DB0C[];
extern u8 lbl_8050EC80[];
extern void* lbl_8053AD30;
extern void* sManager__8JUTVideo;
extern const f32 lbl_805433E8;
extern const f32 lbl_805433CC;
extern const f32 lbl_805433D4;
extern const f32 lbl_805433D0;
extern const f32 lbl_805433FC;
extern const f32 lbl_80543400;
extern const f32 lbl_805433EC;
extern const f32 lbl_805433F0;
extern const f32 lbl_805433F4;
extern const f32 lbl_805433F8;

struct VPane_803B14F8 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void move(f32 x, f32 y);
};

struct VScreen_803B14F8 {
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
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual VPane_803B14F8* v3C(s32 a, s32 b);
};

extern const f32 lbl_80543424;
extern "C" u8 fn_80389BF0(s32 i, s32 id);

struct Pane_803B1B60 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void move(f32 x, f32 y);
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24(s32 a);
};

struct PaneVt_803B38E8 {
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24();
    virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34();
    virtual void v38(); virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50(); virtual void v54();
    virtual void v58(); virtual void v5C(); virtual void v60(); virtual void v64();
    virtual void v68(); virtual void v6C(); virtual void v70(); virtual void v74();
    virtual void v78(); virtual void v7C(); virtual void v80(); virtual void v84();
    virtual void v88(); virtual void v8C(); virtual void v90(); virtual void v94();
    virtual void v98(); virtual void v9C(s32 a);
};
extern void* lbl_8053AD78;

struct Scr_803B1B60 {
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
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual Pane_803B1B60* v3C(u64 name);
};

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

struct Menu_803B2FB0;
extern "C" void fn_803B2FB0(Menu_803B2FB0*);
extern "C" u32 fn_80309D6C(void*, s32, s32);
extern "C" u32 fn_80309C4C(void*, s32, s32);
extern "C" s32 fn_8030AAF4(s32);
extern "C" void fn_803B236C(void*);
extern "C" void* fn_8013C824(void);
extern "C" void* fn_8013CC50(u32, FVec3*, u32, u32, u32, u32, u32, u32, f32);

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

extern "C" void fn_803A8F5C(char* p) {
    char* q;
    char* pos;
    s32 i;
    s32 a;
    s32 id;
    u8 shown;
    u8 neg;
    s32 d;
    void* res;
    s32 j;
    fn_8013B490(lbl_8053AB10);
    if (*(u8*)(p + 0x4c0) >= 2) {
        q = p;
        for (i = 0; i < *(s32*)(p + 0x454); i++) {
            a = *(s32*)(q + 0x3e0);
            shown = 0;
            neg = 0;
            if (a < 0) {
                a *= -1;
                neg = 1;
            }
            *(u8*)(*(char**)(q + 0xa8) + 0xb0) = 0;
            *(u8*)(*(char**)(q + 0xf8) + 0xb0) = 0;
            d = (a % 10000) / 1000;
            if (d != 0) {
                *(u8*)(*(char**)(q + 0xb8) + 0xb0) = 1;
                *(u8*)(*(char**)(q + 0x108) + 0xb0) = 1;
                snprintf(((J2DTextBox*)*(char**)(q + 0xb8))->getStringPtr(), 2, &lbl_805433C0, d);
                snprintf(((J2DTextBox*)*(char**)(q + 0x108))->getStringPtr(), 2, &lbl_805433C0, d);
                if (neg) {
                    *(u8*)(*(char**)(q + 0xa8) + 0xb0) = 1;
                    *(u8*)(*(char**)(q + 0xf8) + 0xb0) = 1;
                    snprintf(((J2DTextBox*)*(char**)(q + 0xa8))->getStringPtr(), 2, &lbl_805433C4);
                    snprintf(((J2DTextBox*)*(char**)(q + 0xf8))->getStringPtr(), 2, &lbl_805433C4);
                }
                shown = 1;
            } else {
                *(u8*)(*(char**)(q + 0xb8) + 0xb0) = 0;
                *(u8*)(*(char**)(q + 0x108) + 0xb0) = 0;
            }
            d = (a % 1000) / 100;
            if (d != 0 || shown) {
                *(u8*)(*(char**)(q + 0xc8) + 0xb0) = 1;
                *(u8*)(*(char**)(q + 0x118) + 0xb0) = 1;
                snprintf(((J2DTextBox*)*(char**)(q + 0xc8))->getStringPtr(), 2, &lbl_805433C0, d);
                snprintf(((J2DTextBox*)*(char**)(q + 0x118))->getStringPtr(), 2, &lbl_805433C0, d);
                if (!shown) {
                    if (neg) {
                        *(u8*)(*(char**)(q + 0xb8) + 0xb0) = 1;
                        *(u8*)(*(char**)(q + 0x108) + 0xb0) = 1;
                        snprintf(((J2DTextBox*)*(char**)(q + 0xb8))->getStringPtr(), 2, &lbl_805433C4);
                        snprintf(((J2DTextBox*)*(char**)(q + 0x108))->getStringPtr(), 2, &lbl_805433C4);
                    }
                    shown = 1;
                }
            } else {
                *(u8*)(*(char**)(q + 0xc8) + 0xb0) = 0;
                *(u8*)(*(char**)(q + 0x118) + 0xb0) = 0;
            }
            d = (a % 100) / 10;
            if (d != 0 || shown) {
                *(u8*)(*(char**)(q + 0xd8) + 0xb0) = 1;
                *(u8*)(*(char**)(q + 0x128) + 0xb0) = 1;
                snprintf(((J2DTextBox*)*(char**)(q + 0xd8))->getStringPtr(), 2, &lbl_805433C0, d);
                snprintf(((J2DTextBox*)*(char**)(q + 0x128))->getStringPtr(), 2, &lbl_805433C0, d);
                if (!shown) {
                    if (neg) {
                        *(u8*)(*(char**)(q + 0xc8) + 0xb0) = 1;
                        *(u8*)(*(char**)(q + 0x118) + 0xb0) = 1;
                        snprintf(((J2DTextBox*)*(char**)(q + 0xc8))->getStringPtr(), 2, &lbl_805433C4);
                        snprintf(((J2DTextBox*)*(char**)(q + 0x118))->getStringPtr(), 2, &lbl_805433C4);
                    }
                    shown = 1;
                }
            } else {
                *(u8*)(*(char**)(q + 0xd8) + 0xb0) = 0;
                *(u8*)(*(char**)(q + 0x128) + 0xb0) = 0;
            }
            d = a % 10;
            snprintf(((J2DTextBox*)*(char**)(q + 0xe8))->getStringPtr(), 2, &lbl_805433C0, d);
            snprintf(((J2DTextBox*)*(char**)(q + 0x138))->getStringPtr(), 2, &lbl_805433C0, d);
            if (!shown && neg) {
                *(u8*)(*(char**)(q + 0xd8) + 0xb0) = 1;
                *(u8*)(*(char**)(q + 0x128) + 0xb0) = 1;
                snprintf(((J2DTextBox*)*(char**)(q + 0xd8))->getStringPtr(), 2, &lbl_805433C4);
                snprintf(((J2DTextBox*)*(char**)(q + 0x128))->getStringPtr(), 2, &lbl_805433C4);
            }
            q += 4;
        }
    }
    ((J2DScreen**)(p + 4))[*(s32*)(p + 0x450)]->draw(lbl_805433C8, lbl_805433C8, *(const J2DGrafContext**)((char*)lbl_8053AB10 + 0x10));
    {
        f32 box[4];
        box[0] = lbl_805433C8;
        box[1] = lbl_805433C8;
        box[2] = lbl_805433CC;
        box[3] = lbl_805433D0;
        fn_8013B414(lbl_8053AB10, box, 1);
    }
    pos = p;
    q = p;
    for (j = 0; j < *(s32*)(p + 0x454); j++) {
        DrawRec rec;
        rec.ids[7] = (u8)(j + 12);
        rec.b26 = 1;
        if (*(u8*)(p + 0x4c0) >= 3) {
            rec.b1d = 0xff;
            rec.b1c = 0xff;
        }
        id = *(s32*)(q + 0x3c0);
        res = ((SprMgr_803A8F5C*)*(void**)((char*)lbl_8053AAF8 + 0xa4))->v18(0x534f4220, lbl_8047641C);
        fn_802F86CC(*(void**)((char*)lbl_8053AB10 + 0x20), pos + 0x2f0, res, id, &rec, 1.0f, 1.0f);
        if (*(u8*)(p + 0x4db) & ((1 << j) & 0xff)) {
            DrawRec rec2;
            if (*(u8*)(p + 0x4db) & ((1 << (j + 4)) & 0xff)) {
                ((u8*)&rec2.w10)[3] = *(u8*)(p + 0x4dd);
            } else {
                ((u8*)&rec2.w10)[3] = *(u8*)(p + 0x4dc);
            }
            rec2.ids[7] = 7;
            rec2.b26 = 1;
            if (*(u8*)(p + 0x4c0) >= 3) {
                rec2.b1d = 0xff;
                rec2.b1c = 0xff;
            }
            id = *(s32*)(q + 0x3c0);
            res = ((SprMgr_803A8F5C*)*(void**)((char*)lbl_8053AAF8 + 0xa4))->v18(0x534f4220, lbl_8047641C);
            fn_802F86CC(*(void**)((char*)lbl_8053AB10 + 0x20), pos + 0x2f0, res, id, &rec2, 1.0f, 1.0f);
        }
        q += 4;
        pos += 12;
    }
    fn_8013B490(lbl_8053AB10);
    ((J2DScreen**)(p + 0x10))[*(s32*)(p + 0x450)]->draw(lbl_805433C8, lbl_805433C8, *(const J2DGrafContext**)((char*)lbl_8053AB10 + 0x10));
    ((J2DScreen*)*(void**)(p + 0x20))->draw(lbl_805433C8, lbl_805433C8, *(const J2DGrafContext**)((char*)lbl_8053AB10 + 0x10));
    if (*(u8*)(p + 0x4c0) == 3 || *(u8*)(p + 0x4c0) == 4) {
        *((u8*)lbl_8053AB10 + 0x20) = 1;
        *((u8*)lbl_8053AB10 + 0x21) = 4;
    }
    (*(VPane_803A8F5C**)(p + 0x170))->setAlpha(*(u8*)(p + 0x4c2));
    (*(VPane_803A8F5C**)(p + 0x170))->drawRect(0, 0, 0, lbl_805433C8, lbl_805433C8, lbl_805433D8, lbl_805433DC);
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
extern const f32 lbl_80543404;
extern const f32 lbl_80543408;
extern const f32 lbl_8054342C;
extern const f32 lbl_80543428;
extern const f32 lbl_80543430;
extern const f64 lbl_805433E0;
extern const f64 lbl_805433B8;
extern "C" s32 fn_80388EEC(s32 i);
extern "C" void fn_80458880(void* a, s32 b, s32 c);
extern u8 lbl_80476270[];
extern void* lbl_8053AF80;
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
    EffHandle* emitters[30];
    u8 pad240[4];
    FVec3 position;
    FVec3 positions[10];
    s32 countdown[10];           // 0x2c8
    u8 pad2f0[0x440 - 0x2f0];
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

extern "C" void fn_803A9AB8(void* this_) {
    u8* q2;
    u8* q3;
    u8* v;
    u8* q4;
    int i;
    f32 dy;
    f32 x0;
    u8* p = (u8*)this_;
    if (p[0x4c8] != 0xff) {
        int n = 0;
        --*(int*)(p + 0x444);
        if (*(int*)(p + 0x444) == 0) {
            u8* q1 = p;
            for (int j = 0; j < *(int*)(p + 0x454); q1 += 4, ++j) {
                if (j == p[0x4ac + n]) {
                    if (*(void**)(q1 + 0x1b8) == 0) {
                        u8* pane = *(u8**)(q1 + 0x158);
                        f32 width = *(f32*)(pane + 0x28) - *(f32*)(pane + 0x20);
                        FVec3 pos(width * lbl_805433E8 + *(f32*)(pane + 0x30), lbl_805433C8, lbl_805433C8);
                        *(void**)(q1 + 0x1b8) = fn_8013CC50(0, &pos, 0x241, 0, 0, 0, 0, 1, lbl_805433D4);
                    }
                    if (p[0x4c8] > n) ++n;
                }
            }
            *(int*)(p + 0x444) = 0xf0;
        }
    }
    q2 = p;
    for (i = 0; i < *(int*)(p + 0x454); q2 += 4, ++i) {
        if (*(int*)(q2 + 0x3d0) != 0) {
            ++*(int*)(q2 + 0x3d0);
            if (*(int*)(q2 + 0x3d0) < 8) *(int*)(q2 + 0x3c0) = 0xc4;
            else if (*(int*)(q2 + 0x3d0) < 16) *(int*)(q2 + 0x3c0) = 0xc3;
            else if (*(int*)(q2 + 0x3d0) < 24) *(int*)(q2 + 0x3c0) = 0xc4;
            else { *(int*)(q2 + 0x3c0) = 0xc3; *(int*)(q2 + 0x3d0) = 0; }
        } else if (*(int*)(q2 + 0x3c0) == 0xc3) {
            if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(i), 0x100)) {
                ++*(int*)(q2 + 0x3d0);
                *(int*)(q2 + 0x3c0) = 0xc4;
                u32 msg = 0x20032;
                (*(MsgSinkObj2**)(p + 0x174 + p[0x4ac + i] * 4))->send(&msg);
            }
        }
    }
    q3 = p;
    v = p;
    for (i = 0; i < *(int*)(p + 0x454); q3 += 4, ++i, v += 12) {
        *(int*)(q3 + 0x3e0) = *(int*)(q3 + 0x3a0) + (*(int*)(q3 + 0x320) + (*(int*)(q3 + 0x340) + *(int*)(q3 + 0x350) + *(int*)(q3 + 0x360) + *(int*)(q3 + 0x370)) - *(int*)(q3 + 0x380) + *(int*)(q3 + 0x3b0));
        if (*(int*)(q3 + 0x3e0) < -5000) *(int*)(q3 + 0x3e0) = -5000;

        if (*(int*)(q3 + 0x3e0) < -500) {
            f32 ratio = lbl_805433EC / (f32)*(int*)(p + 0x434);
            f32 height = (f32)*(s16*)(lbl_8050DB0C + 0x2b0);
            dy = ratio * height / lbl_805433F0;
        } else if (*(int*)(q3 + 0x3e0) > 3000) {
            f32 ratio = lbl_805433F4 / (f32)*(int*)(p + 0x434);
            f32 height = (f32)*(s16*)(lbl_8050DB0C + 0x2b0);
            dy = ratio * height / lbl_805433F0;
        }
        else
            dy = (f32)*(s16*)(lbl_8050DB0C + 0x2b0) * (lbl_805433F8 * (f32)*(int*)(q3 + 0x3e0) / (f32)*(int*)(p + 0x434)) / lbl_805433F0;
        f32 x = getBounds__7J2DPaneFv(*(void**)(q3 + 0x158))[0];
        (*(J2DPane**)(q3 + 0x158))->move(x, *(f32*)(p + 0x3f0) - dy);
        if (*(int*)(q3 + 0x3e0) > 9999) *(int*)(q3 + 0x3e0) = 9999;
        u8* pane = *(u8**)(q3 + 0x158);
        f32 width = *(f32*)(pane + 0x28) - *(f32*)(pane + 0x20);
        int texW = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 4);
        x0 = getBounds__7J2DPaneFv(pane)[0];
        f32 cx = getBounds__7J2DPaneFv(*(void**)(p + 0x168))[0];
        cx += x0;
        f32 scale = lbl_805433CC;
        f32 center = width * lbl_805433E8 + cx;
        *(f32*)(v + 0x2f0) = scale * center / (f32)texW;
        int texH = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 6);
        x0 = getBounds__7J2DPaneFv(*(void**)(q3 + 0x158))[3];
        f32 cy = getBounds__7J2DPaneFv(*(void**)(p + 0x168))[1];
        cy += x0;
        const f32 scaleY = lbl_805433D0;
        const f32 b = lbl_80543400;
        const f32 a = lbl_805433FC;
        *(f32*)(v + 0x2f4) = scaleY * (cy - a - b) / (f32)texH;
        *(f32*)(v + 0x2f8) = lbl_805433C8;
    }
    fn_803B2FB0((Menu_803B2FB0*)p);
    if (p[0x4c8] != 0xff) {
        fn_803B236C(p);
        for (i = 0; i < 10; ++i) {
            if (*(int*)(p + 0x2c8 + i * 4) >= 0) {
                --*(int*)(p + 0x2c8 + i * 4);
                if (*(int*)(p + 0x2c8 + i * 4) <= -1) {
                    u8* countdown = p + i*4;
                    u8* slot = p + i * 12;
                    *(f32*)(p + 0x244) = *(f32*)(slot + 0x250);
                    *(f32*)(p + 0x248) = *(f32*)(slot + 0x254);
                    *(f32*)(p + 0x24c) = *(f32*)(slot + 0x258);
                    *(int*)(countdown + 0x2c8) = -1;
                    u32 msg = 0x3002a;
                    (*(MsgSinkObj2**)(p + 0x184))->send(&msg);
                    break;
                }
            }
        }
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1100, -1)) {
        u8* game = lbl_8050EC80;
        u8* entry = game + *(int*)(game + 0x10) * 0xc8;
        int add = *(int*)(p + 0x324) + *(int*)(p + 0x328);
        add += *(int*)(p + 0x32c);
        add += *(int*)(entry + 0x30);
        *(int*)(entry + 0x30) = *(int*)(p + 0x320) + add;
        entry = game + *(int*)(game + 0x10) * 0xc8;
        if (*(int*)(entry + 0x30) > 99999)
            *(int*)(entry + 0x30) = 99999;
        entry = lbl_8050EC80 + *(int*)(lbl_8050EC80 + 0x10) * 0xc8;
        if (*(int*)(entry + 0x30) < -99999)
            *(int*)(entry + 0x30) = -99999;
        p[0x4c0] = 6;
        fn_80458880(lbl_8053AF80, 0xb, -1);
        q4=p;
        for(i=0;i<30;q4+=4,++i) {
            if(*(JPABaseEmitter**)(q4+0x1c8)) {
                JPAEmitterManager* mgr=*(JPAEmitterManager**)((u8*)fn_8013C824()+0xc);
                mgr->forceDeleteEmitter(*(JPABaseEmitter**)(q4+0x1c8));
                *(JPABaseEmitter**)(q4+0x1c8)=0;
            }
        }
    } else {
    q4 = p;
    for (i = 0; i < 30; q4 += 4, ++i) {
        JPABaseEmitter* e = *(JPABaseEmitter**)(q4 + 0x1c8);
        if (e != 0 && e->isEnableDeleteEmitter()) {
            JPAEmitterManager* mgr = *(JPAEmitterManager**)((u8*)fn_8013C824() + 0xc);
            mgr->forceDeleteEmitter(*(JPABaseEmitter**)(q4 + 0x1c8));
            *(JPABaseEmitter**)(q4 + 0x1c8) = 0;
        }
    }
    }
}

extern const u64 lbl_80476310[][2];
extern "C" void* fn_80403104(u32,const char*);
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


extern "C" void fn_803AB494(void* this_) {
    char* p = (char*)this_;
    s32 rank[4];
    s32 tot[4];
    s32 done[4];
    s32 i;
    s32 k;
    s32 mx;
    s32 n;
    s32 r;

    if (lbl_804AF888[0x30 + *(u8*)(p + 0x4c3)] != -1) {
        if (*(u8*)(p + 0x4c5) >= lbl_804AF888[0x30 + *(u8*)(p + 0x4c3)]) {
            *(u8*)(p + 0x4c3) = *(u8*)(p + 0x4c3) + 1;
        }
        *(u8*)(p + 0x4c5) = *(u8*)(p + 0x4c5) + 1;
    }
    if (lbl_804AF888[0x11 + *(u8*)(p + 0x4c4)] != -1) {
        if (*(u8*)(p + 0x4c6) >= lbl_804AF888[0x11 + *(u8*)(p + 0x4c4)]) {
            *(u8*)(p + 0x4c4) = *(u8*)(p + 0x4c4) + 1;
        }
        *(u8*)(p + 0x4c6) = *(u8*)(p + 0x4c6) + 1;
    }
    k = 0;
    for (i = 0; i < *(s32*)(p + 0x454); i++) {
        if (*(u8*)(p + 0x4c8) != 0xff) {
            if (i == *(u8*)(p + 0x4ac + k)) {
                s32 v = lbl_804AF888[*(u8*)(p + 0x4c4)];
                if (v == -1) {
                    *(s32*)(p + 0x3c0 + i * 4) = 0x3e;
                } else {
                    *(s32*)(p + 0x3c0 + i * 4) = v + 0xdb;
                }
                if (*(u8*)(p + 0x4c8) > k) {
                    k++;
                }
            } else {
                *(s32*)(p + 0x3c0 + i * 4) = lbl_804AF888[0x22 + *(u8*)(p + 0x4c3)] + 0xbd;
            }
        } else {
            *(s32*)(p + 0x3c0 + i * 4) = lbl_804AF888[0x22 + *(u8*)(p + 0x4c3)] + 0xbd;
        }
    }
    if (lbl_804AF888[0x30 + *(u8*)(p + 0x4c3)] == -1 && lbl_804AF888[0x11 + *(u8*)(p + 0x4c4)] == -1) {
        if (*(u8*)(p + 0x4c8) != 0xff) {
            for (i = 0; i < *(s32*)(p + 0x454); i++) {
                s32 total=*(s32*)(p+0x340+i*4)+*(s32*)(p+0x350+i*4);
                total+=*(s32*)(p+0x360+i*4);
                total+=*(s32*)(p+0x370+i*4);
                total=*(s32*)(p+0x320+i*4)+total;
                total-=*(s32*)(p+0x380+i*4);
                total+=*(s32*)(p+0x3b0+i*4);
                tot[i]=*(s32*)(p+0x3a0+i*4)+total;
                rank[i] = 0;
                done[i] = 0;
                if (tot[i] < -5000) {
                    tot[i] = -5000;
                }
            }
            r = 0;
            do {
                mx = -5001;
                for (i = 0; i < *(s32*)(p + 0x454); i++) {
                    if (done[i] == 0 && mx < tot[i]) {
                        mx = tot[i];
                    }
                }
                n = 0;
                for (i = 0; i < *(s32*)(p + 0x454); i++) {
                    if (done[i] == 0 && tot[i] == mx) {
                        rank[i] = r;
                        n++;
                        done[i] = 1;
                    }
                }
                r += n;
            } while (r < *(s32*)(p + 0x454));

            for(i=0;i<*(s32*)(p+0x454);i++) {
                if(rank[i]==0)(*(J2DPane**)(p+0x50+i*4))->show();
                else (*(J2DPane**)(p+0x60+i*4))->show();
                (*(J2DPane**)(p+0x30+i*4))->show();
                f32 y = (f32)*(s16*)(lbl_8050DB0C+0x2ae)+(365.0f+getBounds__7J2DPaneFv(*(void**)(p+0x158+i*4))[1]);
                if(rank[i]!=0)y+=15.0f;
                f32 x=getBounds__7J2DPaneFv(*(void**)(p+0x30+i*4))[0];
                (*(J2DPane**)(p+0x30+i*4))->move(x,y);
                J2DScreen* screen=*(J2DScreen**)(p+0x10+*(s32*)(p+0x450)*4);
                x=getBounds__7J2DPaneFv(screen->search(lbl_80476310[i][0]))[0];
                screen=*(J2DScreen**)(p+0x10+*(s32*)(p+0x450)*4);
                screen->search(lbl_80476310[i][0])->move(x,y+*(f32*)(p+0x42c));
                screen=*(J2DScreen**)(p+0x10+*(s32*)(p+0x450)*4);
                x=getBounds__7J2DPaneFv(screen->search(lbl_80476310[i][1]))[0];
                screen=*(J2DScreen**)(p+0x10+*(s32*)(p+0x450)*4);
                screen->search(lbl_80476310[i][1])->move(x,y+*(f32*)(p+0x430));
                ResTIMG* image=(ResTIMG*)fn_80403104('TIMG',((const char**)((u8*)lbl_804AF888+0x108))[rank[i]]);
                (*(J2DPicture**)(p+0x30+i*4))->changeTexture(image,0);
                (*(J2DPicture**)(p+0x40+i*4))->changeTexture(image,0);
                (*(J2DPicture**)(p+0x40+i*4))->setCornerColor(*(J2DPicture::TCornerColor*)(p+0x46c+rank[i]*16));
            }
            k=0;
            for(i=0;i<*(s32*)(p+0x454);i++) {
                if(i==*(u8*)(p+0x4ac+k)) {
                    FVec3 a(7.0f+*(f32*)(p+0x2f0+i*12),*(f32*)(p+0x2f4+i*12)-27.0f,*(f32*)(p+0x2f8+i*12));
                    fn_8013CC50(0,&a,0xcb,1,0,0,0,1,1.0f);
                    FVec3 b(7.0f+*(f32*)(p+0x2f0+i*12),*(f32*)(p+0x2f4+i*12)-27.0f,*(f32*)(p+0x2f8+i*12));
                    fn_8013CC50(0,&b,0xcc,1,0,0,0,1,1.0f);
                    if(!*(void**)(p+0x1b8+i*4)) {
                        J2DPane* pane=*(J2DPane**)(p+0x158+i*4);
                        FVec3 a((pane->mBounds.f.x-pane->mBounds.i.x)*lbl_805433E8+pane->mGlobalBounds.i.x,0.0f,0.0f);
                        *(void**)(p+0x1b8+i*4)=fn_8013CC50(0,&a,0x241,0,0,0,0,1,1.0f);
                    }
                    if(*(u8*)(p+0x4c8)>k)k++;
                }
            }
            *(s32*)(p+0x444)=240;
        }
        {
            s32 mode=*(s32*)(lbl_80529DEC+0x118);
            s32 stage=*(s32*)(lbl_80529DEC+0x11c);
            mode=mode<8?mode:0;
            stage=stage<4?stage:0;
            if(mode>=0 && mode<=7 && stage>=0 && stage<=3) {
                u8* entry=lbl_8050EC80+*(s32*)(lbl_8050EC80+0x10)*200;
                *(u32*)(entry+0x28)|=1<<(mode*4+stage);
            }
        }
        *(u8*)(p+0x4c0)=4;
        *(u8*)(p+0x4c1)=0x22;
        *(s32*)(p+0x440)=60;
        if(*(u8*)(p+0x4c8)!=255) {
            for(i=0;i<*(u8*)(p+0x4c8)+1;i++) {
                u32 message=0x10008;
                (*(MsgSinkObj2**)(p+0x174+*(u8*)(p+0x4ac+i)*4))->send(&message);
            }
        }
    }
}

// ---- from src/Game/CountdownBlink_803AF604.cpp ----
extern "C" void fn_80458880(void* p1, s32 p2, s32 p3);
extern "C" void fn_803B35F8(void* this_, u32 flag);

extern void* lbl_8053AF80;

extern void* lbl_8053AD30;
extern "C" u32 fn_80309C4C(void* p, s32 a, s32 b);


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
        s32 t;
        p->m4c8 = 0xff;
        for (s32 i = 0; i < p->count; i++) {
            tot[i] = p->a320[i] + p->a340[i] + p->a350[i] + p->a360[i] + p->a370[i] - p->a380[i] + p->a3a0[i] + p->a3b0[i];
        }
        for (s32 j = 0; j < p->count; j++) {
            t = tot[j];
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

    void setWinner(s32 m, s32 k, u8 v) {
        if (m >= 0 && m < 8 && k >= 0 && k < 3) {
            winner[m][k] = v;
        }
    }
};

static inline void GameResult_setWinner(s32 m, s32 k, u8 v) {
    if (m >= 0 && m < 8 && k >= 0 && k < 3) {
        GameResult* g = (GameResult*)lbl_80529DEC;
        g->winner[m][k] = v;
    }
}

extern const char* lbl_804AF980[];
extern "C" void* fn_80403104(u32 type, const char* name);

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
        GameResult* res = (GameResult*)lbl_80529DEC;
        s32 mode = res->mode;
        s32 sub = res->sub;
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
            GameResult* g = (GameResult*)lbl_80529DEC;
            g->wins[p->ids[0]]++;
            g->winMask = 0;
            g->winMask = 1 << p->ids[0];
            g->setWinner(res->mode, k, p->ids[0]);
            if (p->m4c8 != 0xff) {
                fn_80458880(lbl_8053AF80, 0x11, -1);
            }
        } else {
            GameResult_setWinner(mode, sub, 0xff);
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
static const s32 lbl_804763C0[4] = {300, 150, 50, 0};
static const s32 lbl_804763D0[3] = {300, 150, 0};
static const s32 lbl_80543388[2] = {150, 0};

extern "C" void fn_803AE810(Menu_Rank* p) {
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
                            p->target[i] = lbl_804763C0[placed];
                            break;
                        case 1:
                            p->target[i] = lbl_804763D0[placed];
                            break;
                        case 2:
                            p->target[i] = lbl_80543388[placed];
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
        s32 t;
        for (s32 j = 0; j < p->count; j++) {
            t = p->target[j];
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
static const s32 lbl_804763A4[4] = {300, 150, 50, 0};
static const s32 lbl_804763B4[3] = {300, 150, 0};
static const s32 lbl_80543380[2] = {150, 0};

extern "C" void fn_803AF1B0(Menu_Rank* p) {
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
                            p->target[i] = lbl_804763A4[placed];
                            break;
                        case 1:
                            p->target[i] = lbl_804763B4[placed];
                            break;
                        case 2:
                            p->target[i] = lbl_80543380[placed];
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
        s32 t;
        for (s32 j = 0; j < p->count; j++) {
            t = p->target[j];
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


#pragma opt_lifetimes off
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
        union { f32 f; u32 s; } out;
        MsgGame* game=lbl_8053AAF8;
        game->rnd.seed=game->rnd.seed*0x19660d+0x3c6ef35f;
        out.s=(game->rnd.seed>>9)|0x3f800000;
        p->timer=0x96+sum%9+(s32)(100.0f*(out.f-1.0f));
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
#pragma opt_lifetimes reset
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
static const s32 lbl_80476388[4] = {300, 150, 50, 0};
static const s32 lbl_80476398[3] = {300, 150, 0};
static const s32 lbl_80543378[2] = {150, 0};

extern "C" void fn_803AFCF0(Menu_Rank* p) {
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
                            p->target[i] = lbl_80476388[placed];
                            break;
                        case 1:
                            p->target[i] = lbl_80476398[placed];
                            break;
                        case 2:
                            p->target[i] = lbl_80543378[placed];
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
        s32 t;
        for (s32 j = 0; j < p->count; j++) {
            t = p->target[j];
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
    u8 pad468[0x4b8 - 0x468];
    u8 selected[4];              // 0x4b8
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

static inline void IntroAppear(Menu_Intro* p, const u64* tags, f32 factor) {
    if (p->cur < 2) {
        for (s32 k=0;k<2;k++) {
            p->screens[p->cur]->search(tags[k])->setAlpha((u8)(p->alpha[k]*factor));
        }
    }
}

static inline void IntroFade(Menu_Intro* p, const u64* tags, const s32 count, const s32 elapsed, const s32 duration, const u32 alphaOffset) {
    if (p->cur < 2) {
        for (s32 k = 0; k < count; k++) {
            p->screens[p->cur]->search(tags[k])->setAlpha((u8)(((u8*)p)[alphaOffset + k] * (1.0f - (f32)elapsed / (f32)duration)));
        }
    }
}

extern TagPair lbl_804762D0[];
extern u8 lbl_8050DB0C[];
extern "C" u8 fn_80389BF0(s32 idx, s32 id);

extern const u8 lbl_80476208[];

// NONMATCHING (97.5%): register allocation of the timing locals.
extern "C" void fn_803B03E8(Menu_Intro* p) {
    IntroTags* tbl = (IntroTags*)lbl_80476208;
    s32 d;
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
        d = p->timer - t0;
        f32 x = p->screens[p->cur]->search('Pmmwk02')->getBounds()->i.x;
        f32 y = 200.0f * ((f32)(d * d) / (f32)(t1 * t1));
        p->screens[p->cur]->search('Pmmwk02')->move(x, p->y41c - y);
        IntroFade(p, tbl->title, 13, d, t1, 0x4c9);
    }
    if (p->timer > start && p->timer <= start + dur + gap * (p->count - 1)) {
        s32 off = 0;
        u64 (*r3)[3] = (u64 (*)[3])tbl->p3;
        u64 (*r2)[2] = (u64 (*)[2])tbl->p2;
        for (s32 i = 0; i < p->count; i++, r3++, r2++) {
            if (p->timer >= start + off) {
                s32 d = p->timer - (start + off);
                f32 y = 200.0f * ((f32)(d * d) / (f32)(dur * dur));
                f32 x = p->screens[p->cur]->search((*r3)[2])->getBounds()->i.x;
                p->screens[p->cur]->search((*r3)[2])->move(x, p->y420 + y);
                x = p->screens[p->cur]->search((*r2)[1])->getBounds()->i.x;
                p->screens[p->cur]->search((*r2)[1])->move(x, p->y424 + y);
                IntroFade(p, *r3, 3, d, dur, 0x4d6);
                IntroFade(p, *r2, 2, d, dur, 0x4d9);
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

#pragma opt_lifetimes off
#pragma fp_contract off
extern "C" void fn_803B0978(void* arg) {
    Menu_Intro* p;

    s32 k;
    const u64* fadeTags;
    Menu_Intro* q;
    u64 (*tags3)[3];
    TagPair* tags2;
    s32 end;
    s32 firstSq;
    s32 secondSq;
    s32 done;
    s32 first;
    s32 dist;
    s32 period;
    s32 i;
    u8* bytes = (u8*)arg;
    p = (Menu_Intro*)arg;
    dist = *(s16*)(lbl_8050DB0C + 0x256);
    first = *(s16*)(lbl_8050DB0C + 0x252);
    s32 second = *(s16*)(lbl_8050DB0C + 0x254);
    period = *(s16*)(lbl_8050DB0C + 0x258);
    tags3 = (u64 (*)[3])lbl_80476270;
    tags2 = lbl_804762D0;
    firstSq = first * first;
    secondSq = second * second;
    end = first + second;
    f32 span = lbl_80543428 + (f32)dist;
    done = 0;
    for (q=p, i = 0; i < p->count; q=(Menu_Intro*)((u8*)q+2), tags3++, tags2++, i++) {
        if (bytes[0x4bc+i] == 0xff && (u8)fn_80388EEC(i) != 0) {
            q->m460[0] = 0;
            f32 x = p->screens[p->cur]->search((*tags3)[2])->getBounds()->i.x;
            p->screens[p->cur]->search((*tags3)[2])->move(x, p->y420);
            bytes[0x4bc+i] = fn_803A8DFC(p, i);
            fn_80458880(lbl_8053AF80, 0xb, -1);
        }
        if (bytes[0x4bc+i] != 0xff) {
            if (q->m460[0] < end) {
                q->m460[0]++;
                if (q->m460[0] <= first) {
                    s32 t = q->m460[0];
                    f32 a = (f32)(t*t) / (f32)firstSq;
                    f32 x = p->screens[p->cur]->search(tags2->tag[1])->getBounds()->i.x;
                    p->screens[p->cur]->search(tags2->tag[1])->move(x, (p->y424 - lbl_80543428) + span*a);
                    x = p->screens[p->cur]->search((*tags3)[2])->getBounds()->i.x;
                    p->screens[p->cur]->search((*tags3)[2])->move(x, p->y420 + (f32)dist*a);
                    a = (f32)q->m460[0] / (f32)first;
                    if (p->cur < 2) {
                        for(k=0,fadeTags=tags2->tag;k<2;k++,fadeTags++) {
                            p->screens[p->cur]->search(*fadeTags)->setAlpha((u8)(p->alpha[k]*a));
                        }
                    }
                } else if (q->m460[0] <= end) {
                    s32 t = end - q->m460[0];
                    f32 off = (f32)dist * ((f32)(t*t) / (f32)secondSq);
                    f32 x = p->screens[p->cur]->search(tags2->tag[1])->getBounds()->i.x;
                    p->screens[p->cur]->search(tags2->tag[1])->move(x, p->y424 + off);
                    x = p->screens[p->cur]->search((*tags3)[2])->getBounds()->i.x;
                    p->screens[p->cur]->search((*tags3)[2])->move(x, p->y420 + off);
                }
            }
            if (q->m460[0] == end) done++;
        } else {
            if (q->m460[0] < period) q->m460[0]++;
            else q->m460[0] = 0;
            f32 step = lbl_80543430/(f32)period;
            f32 elapsed = q->m460[0];
            f32 off = lbl_8054342C * JMASinShort((s16)(step*elapsed));
            f32 x = p->screens[p->cur]->search((*tags3)[2])->getBounds()->i.x;
            p->screens[p->cur]->search((*tags3)[2])->move(x, p->y420 + off);
        }
    }
    if (done == p->count) {
        p->timer = 0;
        for (s32 i=0;i<p->count;i++) p->m460[i]=0;
        p->m4c1=7;
    }
}
#pragma fp_contract reset
#pragma opt_lifetimes reset
// NONMATCHING (99.5%): register allocation in the slide loops.
#pragma opt_lifetimes off
extern "C" void fn_803B0FD4(Menu_Intro* p) {
    s32 end;
    s32 t1;
    s32 t2;
    s32 dist;
    s32 d;
    f32 x;
    f32 a;
    p->timer++;
    t1 = *(s16*)(lbl_8050DB0C + 0x25a);
    t2 = *(s16*)(lbl_8050DB0C + 0x25c);
    dist = *(s16*)(lbl_8050DB0C + 0x25e);
    end = t1 + t2;
    if (p->timer <= end) {
        if (p->timer <= t1) {
            a = (f32)dist * ((f32)(p->timer * p->timer) / (f32)(t1 * t1));
            for (s32 i = 0; i < p->count; i++) {
                x = p->screens[p->cur]->search(lbl_804762D0[i].tag[1])->getBounds()->i.x;
                p->screens[p->cur]->search(lbl_804762D0[i].tag[1])->move(x, p->y424 + a);
            }
        } else if (p->timer <= end) {
            d = p->timer - t1;
            f32 off = ((f32)dist + 40.0f) * ((f32)(d * d) / (f32)(t2 * t2));
            for (s32 i = 0; i < p->count; i++) {
                x = p->screens[p->cur]->search(lbl_804762D0[i].tag[1])->getBounds()->i.x;
                p->screens[p->cur]->search(lbl_804762D0[i].tag[1])->move(x, (p->y424 + (f32)dist) - off);
                a = 1.0f - (f32)(p->timer - t1) / (f32)t2;
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
#pragma opt_lifetimes reset
extern "C" void fn_803B14F8(void* this_) {
    Menu_Intro* p = (Menu_Intro*)this_;
    s32 k;
    const u64* fadeTag;
    char* row;
    u64 (*tags3)[3];
    TagPair* tags2;
    s32 total;
    s32 b2;
    s32 c2;
    s32 done;
    s32 b;
    s32 a;
    s32 d;
    s32 i;
    s32 c;
    f32 x;
    f32 ratio;
    f32 span;
    a = *(s16*)(lbl_8050DB0C + 0x256);
    b = *(s16*)(lbl_8050DB0C + 0x252);
    c = *(s16*)(lbl_8050DB0C + 0x254);
    b2 = b * b;
    tags3 = (u64 (*)[3])lbl_80476270;
    tags2 = lbl_804762D0;
    span = lbl_80543428 + (f32)a;
    c2 = c * c;
    d = *(s16*)(lbl_8050DB0C + 0x258);
    row = (char*)p;
    total = b + c;
    done = 0;
    i = 0;
    while (i < p->count) {
        if (p->selected[i] == 0xff && (u8)fn_80388EEC(i)) {
            (*(s16*)(row + 0x460)) = 0;
            x = p->screens[p->cur]->search((*tags3)[2])->getBounds()->i.x;
            p->screens[p->cur]->search((*tags3)[2])->move(x, p->y420);
            p->selected[i] = fn_803A8DFC(p, i);
            fn_80458880(lbl_8053AF80, 0xb, -1);
        }
        if (p->selected[i] != 0xff) {
            if ((*(s16*)(row + 0x460)) < total) {
                (*(s16*)(row + 0x460))++;
                if ((*(s16*)(row + 0x460)) <= b) {
                    s32 t = (*(s16*)(row + 0x460));
                    ratio = (f32)(t * t) / (f32)b2;
                    x = p->screens[p->cur]->search(tags2->tag[1])->getBounds()->i.x;
                    f32 offset = span * ratio;
                    p->screens[p->cur]->search(tags2->tag[1])->move(x, (p->y424 - lbl_80543428) + offset);
                    x = p->screens[p->cur]->search((*tags3)[2])->getBounds()->i.x;
                    offset = (f32)a * ratio;
                    p->screens[p->cur]->search((*tags3)[2])->move(x, p->y420 + offset);
                    ratio = (f32)(*(s16*)(row + 0x460)) / (f32)b;
                    if (p->cur < 2) {
                        fadeTag = tags2->tag;
                        for (k = 0; k < 2; k++, fadeTag++) {
                            p->screens[p->cur]->search(*fadeTag)->setAlpha((u8)(p->alpha[k] * ratio));
                        }
                    }
                } else if ((*(s16*)(row + 0x460)) <= total) {
                    s32 t = total - (*(s16*)(row + 0x460));
                    ratio = (f32)a * ((f32)(t * t) / (f32)c2);
                    x = p->screens[p->cur]->search(tags2->tag[1])->getBounds()->i.x;
                    p->screens[p->cur]->search(tags2->tag[1])->move(x, p->y424 + ratio);
                    x = p->screens[p->cur]->search((*tags3)[2])->getBounds()->i.x;
                    p->screens[p->cur]->search((*tags3)[2])->move(x, p->y420 + ratio);
                }
            }
            if ((*(s16*)(row + 0x460)) == total) done++;
        } else {
            if ((*(s16*)(row + 0x460)) < d) (*(s16*)(row + 0x460))++;
            else (*(s16*)(row + 0x460)) = 0;
            f32 rate = lbl_80543430 / (f32)d;
            s16 angle = (s16)(rate * (f32)(*(s16*)(row + 0x460)));
            ratio = lbl_8054342C * JMath::sincosTable_.sinShort(angle);
            x = p->screens[p->cur]->search((*tags3)[2])->getBounds()->i.x;
            p->screens[p->cur]->search((*tags3)[2])->move(x, p->y420 + ratio);
        }
        row += 2;
        tags3++;
        tags2++;
        i++;
    }
    if (done == p->count) {
        p->timer = 0;
        for (s32 j = 0; j < p->count; j++) {
            p->ready[j] = 0xff;
            p->m460[j] = 0;
        }
        p->m4c1 = 4;
    }
}

#pragma fp_contract off
extern "C" void fn_803B1B60(Menu_Intro* p) {
    s32 start1;
    s32 start2;
    s32 a;
    s32 t;
    s32 b;
    s32 c;
    s32 start1b;
    s32 end2;
    s32 e;
    s32 f;
    s32 g;
    s32 start2b;
    if (p->timer > 0) {
        p->timer--;
    }
    t = p->timer;
    a = *(s16*)(lbl_8050DB0C + 0x244);
    s32 d = *(s16*)(lbl_8050DB0C + 0x24a);
    b = *(s16*)(lbl_8050DB0C + 0x246);
    c = *(s16*)(lbl_8050DB0C + 0x248);
    e = *(s16*)(lbl_8050DB0C + 0x24c);
    f = *(s16*)(lbl_8050DB0C + 0x24e);
    g = *(s16*)(lbl_8050DB0C + 0x250);
    start1 = 0x96 - a;
    end2 = 0x96 - d;
    start2 = end2 - a;
    start1b = start1 - b;
    start2b = start2 - b;

    if (t == 0) {
        if (p->cur == 1) {
            if (p->selected[0] == 0xff && fn_80389BF0(0, 0x106)) {
                p->selected[0] = 1;
            }
            if (p->selected[1] == 0xff && fn_80389BF0(1, 0x107)) {
                p->selected[1] = 1;
            }
            if (p->selected[2] == 0xff && fn_80389BF0(2, 0x108)) {
                p->selected[2] = 1;
            }
            p->selected[3] = 1;
        } else {
            if (p->selected[0] == 0xff && fn_80389BF0(0, 0xe2)) {
                p->selected[0] = 1;
            }
            if (p->selected[1] == 0xff && fn_80389BF0(1, 0xe3)) {
                p->selected[1] = 1;
            }
            if (p->selected[2] == 0xff && fn_80389BF0(2, 0xe4)) {
                p->selected[2] = 1;
            }
            if (p->selected[3] == 0xff && fn_80389BF0(3, 0xe5)) {
                p->selected[3] = 1;
            }
        }
        if (p->selected[0] == 1 && p->selected[1] == 1 && p->selected[2] == 1 && p->selected[0] == 1) {
            for (s32 i = 0; i < p->count; i++) {
                p->selected[i] = 0xff;
                p->m460[i] = 0;
            }
            p->timer = 0x96;
            p->m4c1 = 3;
        }
    } else {
        if (t >= start1) {
            f32 x = p->screens[p->cur]->search('Pmmwk02')->getBounds()->i.x;
            p->screens[p->cur]->search('Pmmwk02')->move(x, (p->y41c - lbl_80543424) + (lbl_80543424 + (f32)c) * (lbl_805433D4 - (f32)((t - start1) * (t - start1)) / (f32)(a * a)));
            f32 fade = lbl_805433D4 - (f32)(p->timer - start1) / (f32)a;
            if (p->cur < 2) {
                for (int i = 0; i < 13; i++) {
                    p->screens[p->cur]->search(((const u64*)lbl_80476208)[i])->setAlpha((u8)(p->alphaTitle[i] * fade));
                }
            }
        } else if (t >= start1b) {
            f32 x = p->screens[p->cur]->search('Pmmwk02')->getBounds()->i.x;
            p->screens[p->cur]->search('Pmmwk02')->move(x, p->y41c + (f32)c * ((f32)((t - start1b) * (t - start1b)) / (f32)(b * b)));
        }
        if (p->timer <= end2) {
            if (p->timer >= start2) {
                f32 fade;
                s32 dt = p->timer - start2;
                f32 off = (lbl_80543428 + (f32)g) * (lbl_805433D4 - (f32)(dt * dt) / (f32)(e * e));
                for (s32 i = 0; i < p->count; i++) {
                    f32 x = p->screens[p->cur]->search(((u64 (*)[3])lbl_80476270)[i][2])->getBounds()->i.x;
                    p->screens[p->cur]->search(((u64 (*)[3])lbl_80476270)[i][2])->move(x, (p->y420 - lbl_80543428) + off);
                    fade = lbl_805433D4 - (f32)(p->timer - start2) / (f32)e;
                    if (p->cur < 2) {
                        for (int k = 0; k < 3; k++) {
                            p->screens[p->cur]->search(((u64 (*)[3])lbl_80476270)[i][k])->setAlpha((u8)(p->alpha3[k] * fade));
                        }
                    }
                }
            } else if (p->timer >= start2b) {
                s32 dt = p->timer - start2b;
                f32 off = (f32)g * ((f32)(dt * dt) / (f32)(f * f));
                for (s32 i = 0; i < p->count; i++) {
                    f32 x = p->screens[p->cur]->search(((u64 (*)[3])lbl_80476270)[i][2])->getBounds()->i.x;
                    p->screens[p->cur]->search(((u64 (*)[3])lbl_80476270)[i][2])->move(x, p->y420 + off);
                }
            }
        }
    }
}
#pragma fp_contract reset
extern const f32 lbl_80476368[];
extern const f32 lbl_80476378[];
extern const f32 lbl_80543434;
extern const f32 lbl_80543438;
extern const f32 lbl_8054343C;
static inline s32 findMenuEmitter(const void* self) {
    for(s32 i=0;i<30;++i) if(((Menu_Main*)self)->emitters[i]==0) return i;
    return -1;
}
static inline void spawnMenuEmitter(void* self,u32 kind,f32 scale) {
    s32 slot=findMenuEmitter((const Menu_Main*)self);
    if(slot!=-1) {
        FVec3 pos(lbl_8054343C+((Menu_Main*)self)->position.x,lbl_8054343C+((Menu_Main*)self)->position.y,lbl_805433C8);
        ((Menu_Main*)self)->emitters[slot]=(EffHandle*)fn_8013CC50(0,&pos,kind,0,0,0,0,1,scale);
        ((Menu_Main*)self)->emitters[slot]->flags |= 0x40;
    }
}
#pragma opt_common_subs off
extern "C" void fn_803B236C(void* this_) {
    Menu_Main* menu=(Menu_Main*)this_;
    u8* self=(u8*)menu;
    s32 arr[4];
    if(*(s16*)(self+0x458)<=0) {
        s32 cnt=0;
        if(self[0x4c8]!=0) {
            s32* out=arr;
            s32 n=self[0x4c8]+1;
            for(s32 k=0;k<n;k++) {
                if(k!=*(s16*)(self+0x45c)) { *out++=k;cnt++; }
            }
            s32 idx=(s32)((f32)cnt*lbl_8053AAF8->rnd.get_ufloat_1());
            *(s16*)(self+0x45c)=self[0x4ac+arr[idx]];
        } else *(s16*)(self+0x45c)=self[0x4ac];
        cnt=0;
        s32* out=arr;
        for(s32 k=0;k<4;k++) {
            if(k!=*(s16*)(self+0x45e)) { *out++=k;cnt++; }
        }
        s32 idx=(s32)((f32)cnt*lbl_8053AAF8->rnd.get_ufloat_1());
        *(s16*)(self+0x45e)=arr[idx];
        *(f32*)(self+0x244)=lbl_80543434*lbl_8053AAF8->rnd.get_ufloat_1()+lbl_80476368[*(s16*)(self+0x45e)];
        *(f32*)(self+0x248)=lbl_80543434*lbl_8053AAF8->rnd.get_ufloat_1()+lbl_80476378[*(s16*)(self+0x45e)];
        f32 scale=lbl_805433E8*lbl_8053AAF8->rnd.get_ufloat_1()+lbl_80543438;
        { s32 slot=findMenuEmitter(menu);
    if(slot!=-1) {
        FVec3 pos(lbl_8054343C+menu->position.x,lbl_8054343C+menu->position.y,lbl_805433C8);
        menu->emitters[slot]=(EffHandle*)fn_8013CC50(0,&pos,0x56c,0,0,0,0,1,scale);
        menu->emitters[slot]->flags|=0x40;
    }
}
        switch(*(s16*)(self+0x45c)) {
        case 0: { s32 slot=findMenuEmitter(menu);
    if(slot!=-1) {
        FVec3 pos(lbl_8054343C+menu->position.x,lbl_8054343C+menu->position.y,lbl_805433C8);
        menu->emitters[slot]=(EffHandle*)fn_8013CC50(0,&pos,0x56e,0,0,0,0,1,scale);
        menu->emitters[slot]->flags|=0x40;
    }
}break;
        case 1: { s32 slot=findMenuEmitter(menu);
    if(slot!=-1) {
        FVec3 pos(lbl_8054343C+menu->position.x,lbl_8054343C+menu->position.y,lbl_805433C8);
        menu->emitters[slot]=(EffHandle*)fn_8013CC50(0,&pos,0x570,0,0,0,0,1,scale);
        menu->emitters[slot]->flags|=0x40;
    }
}break;
        case 2: { s32 slot=findMenuEmitter(menu);
    if(slot!=-1) {
        FVec3 pos(lbl_8054343C+menu->position.x,lbl_8054343C+menu->position.y,lbl_805433C8);
        menu->emitters[slot]=(EffHandle*)fn_8013CC50(0,&pos,0x56d,0,0,0,0,1,scale);
        menu->emitters[slot]->flags|=0x40;
    }
}break;
        case 3: { s32 slot=findMenuEmitter(menu);
    if(slot!=-1) {
        FVec3 pos(lbl_8054343C+menu->position.x,lbl_8054343C+menu->position.y,lbl_805433C8);
        menu->emitters[slot]=(EffHandle*)fn_8013CC50(0,&pos,0x56f,0,0,0,0,1,scale);
        menu->emitters[slot]->flags|=0x40;
    }
}break;
        default:{ s32 slot=findMenuEmitter(menu);
    if(slot!=-1) {
        FVec3 pos(lbl_8054343C+menu->position.x,lbl_8054343C+menu->position.y,lbl_805433C8);
        menu->emitters[slot]=(EffHandle*)fn_8013CC50(0,&pos,0x571,0,0,0,0,1,scale);
        menu->emitters[slot]->flags|=0x40;
    }
}break;
        }
        u32 msg=0x30029;
        (*(MsgSinkObj2**)(self+0x184))->send(&msg);
        for(s32 i=0;i<10;i++) {
            if(menu->countdown[i]==-1) {
                menu->positions[i].x=menu->position.x;
                menu->positions[i].y=menu->position.y;
                menu->positions[i].z=menu->position.z;
                menu->countdown[i]=0x3a;
                break;
            }
        }
        if(*(s16*)(self+0x45a)<=0) {
            *(s16*)(self+0x458)=*(s16*)(lbl_8050DB0C+0x50);
            *(s16*)(self+0x45a)=(lbl_8053AAF8->rnd.get_ufloat_1()*(f32)*(s16*)(lbl_8050DB0C+0x52));
        } else {
            *(s16*)(self+0x458)=20;
            (*(s16*)(self+0x45a))--;
        }
    } else (*(s16*)(self+0x458))--;
}
#pragma opt_common_subs reset
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

extern "C" void fn_803B38E8(void* this_) {
    u8* p = (u8*)this_;
    f32 f31;
    u8* src;
    u8* dst;
    int i;
    Scr_803B1B60* screen;

    screen = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)];
    *(void**)(p + 0x30) = screen->v3C(0x00005072616e3132ULL);
    *(void**)(p + 0x34) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x00005072616e3232ULL);
    f31 = getBounds__7J2DPaneFv(*(void**)(p + 0x30))[1];
    *(f32*)(p + 0x42c) = getBounds__7J2DPaneFv(((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723031ULL))[1] - f31;
    f31 = getBounds__7J2DPaneFv(*(void**)(p + 0x30))[1];
    *(f32*)(p + 0x430) = getBounds__7J2DPaneFv(((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723231ULL))[1] - f31;
    *(void**)(p + 0x40) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x00005072616e3131ULL);
    *(void**)(p + 0x44) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x00005072616e3231ULL);
    for (i = 0; i < 2; i++) {
        src = *(u8**)(p + 0x40 + i * 4);
        dst = p + 0x46c + i * 16;
        dst[0] = src[0x150];
        dst[1] = src[0x151];
        dst[2] = src[0x152];
        dst[3] = src[0x153];
        dst[4] = src[0x154];
        dst[5] = src[0x155];
        dst[6] = src[0x156];
        dst[7] = src[0x157];
        dst[8] = src[0x158];
        dst[9] = src[0x159];
        dst[10] = src[0x15a];
        dst[11] = src[0x15b];
        dst[12] = src[0x15c];
        dst[13] = src[0x15d];
        dst[14] = src[0x15e];
        dst[15] = src[0x15f];
    }
    *(void**)(p + 0x50) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723031ULL);
    *(void**)(p + 0x54) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723132ULL);
    *(void**)(p + 0x60) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723231ULL);
    *(void**)(p + 0x64) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723232ULL);
    *(void**)(p + 0xa8) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653131ULL);
    *(void**)(p + 0xb8) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653132ULL);
    *(void**)(p + 0xc8) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653133ULL);
    *(void**)(p + 0xd8) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653134ULL);
    *(void**)(p + 0xe8) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653135ULL);
    *(void**)(p + 0xf8) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3131ULL);
    *(void**)(p + 0x108) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3132ULL);
    *(void**)(p + 0x118) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3133ULL);
    *(void**)(p + 0x128) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3134ULL);
    *(void**)(p + 0x138) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3135ULL);
    *(void**)(p + 0xac) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653231ULL);
    *(void**)(p + 0xbc) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653232ULL);
    *(void**)(p + 0xcc) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653233ULL);
    *(void**)(p + 0xdc) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653234ULL);
    *(void**)(p + 0xec) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653235ULL);
    *(void**)(p + 0xfc) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3231ULL);
    *(void**)(p + 0x10c) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3232ULL);
    *(void**)(p + 0x11c) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3233ULL);
    *(void**)(p + 0x12c) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3234ULL);
    *(void**)(p + 0x13c) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3235ULL);
    *(void**)(p + 0x148) = ((Scr_803B1B60**)(p + 4))[*(s32*)(p + 0x450)]->v3C(0x00506c7465737431ULL);
    *(void**)(p + 0x14c) = ((Scr_803B1B60**)(p + 4))[*(s32*)(p + 0x450)]->v3C(0x00506c7477737432ULL);
    *(void**)(p + 0x158) = ((Scr_803B1B60**)(p + 4))[*(s32*)(p + 0x450)]->v3C(0x0050727073743031ULL);
    *(void**)(p + 0x15c) = ((Scr_803B1B60**)(p + 4))[*(s32*)(p + 0x450)]->v3C(0x0050727073743032ULL);
    *(void**)(p + 0x168) = ((Scr_803B1B60**)(p + 4))[*(s32*)(p + 0x450)]->v3C(0x004e646174613035ULL);
    *(void**)(p + 0x16c) = ((Scr_803B1B60*)*(void**)(p + 0x1c))->v3C(0x005072736c746267ULL);
    for (i = 0; i < 2; i++) {
        u8* q = p + i * 4;
        ((PaneVt_803B38E8*)*(void**)(q + 0xa8))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0xb8))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0xc8))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0xd8))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0xe8))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0xf8))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0x108))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0x118))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0x128))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0x138))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((u8*)*(void**)(q + 0xa8))[0xb0] = 0;
        ((u8*)*(void**)(q + 0xb8))[0xb0] = 0;
        ((u8*)*(void**)(q + 0xc8))[0xb0] = 0;
        ((u8*)*(void**)(q + 0xd8))[0xb0] = 0;
        ((u8*)*(void**)(q + 0xf8))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x108))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x118))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x128))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x30))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x50))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x60))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x148))[0xb0] = 0;
    }
}

extern "C" void fn_803832BC(char* a, s32 b, int c, int d, int e);

static inline void IntroReadAlpha(Menu_Intro* m, u8* dst, const u64* tags, s32 count) {
    for (s32 i = 0; i < count; i++, tags++) {
        dst[i] = m->screens[m->cur]->search(*tags)->getAlpha();
    }
}

static inline void IntroSetupScores(u8* p, s32 count) {
    for (s32 i = 0; i < count; i++) {
        u8* q = p + i * 4;
        ((PaneVt_803B38E8*)*(void**)(q + 0xa8))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0xb8))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0xc8))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0xd8))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0xe8))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0xf8))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0x108))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0x118))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0x128))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((PaneVt_803B38E8*)*(void**)(q + 0x138))->v9C(*(s32*)((u8*)lbl_8053AD78 + 0x154));
        ((u8*)*(void**)(q + 0xa8))[0xb0] = 0;
        ((u8*)*(void**)(q + 0xb8))[0xb0] = 0;
        ((u8*)*(void**)(q + 0xc8))[0xb0] = 0;
        ((u8*)*(void**)(q + 0xd8))[0xb0] = 0;
        ((u8*)*(void**)(q + 0xf8))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x108))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x118))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x128))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x30))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x50))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x60))[0xb0] = 0;
        ((u8*)*(void**)(q + 0x148))[0xb0] = 0;
    }
}

extern "C" void fn_803B42C0(void* this_) {
    register IntroTags* tbl = (IntroTags*)lbl_80476208;
    u8* p = (u8*)this_;
    Menu_Intro* m;
    f32 f31;
    u8* src;
    u8* dst;
    int i;

    *(void**)(p + 0x30) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x00005072616e3132ULL);
    *(void**)(p + 0x34) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x00005072616e3232ULL);
    *(void**)(p + 0x38) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x00005072616e3332ULL);
    f31 = getBounds__7J2DPaneFv(*(void**)(p + 0x30))[1];
    *(f32*)(p + 0x42c) = getBounds__7J2DPaneFv(((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723031ULL))[1] - f31;
    f31 = getBounds__7J2DPaneFv(*(void**)(p + 0x30))[1];
    *(f32*)(p + 0x430) = getBounds__7J2DPaneFv(((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723231ULL))[1] - f31;
    *(void**)(p + 0x40) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x00005072616e3131ULL);
    *(void**)(p + 0x44) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x00005072616e3231ULL);
    *(void**)(p + 0x48) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x00005072616e3331ULL);
    for (i = 0; i < 3; i++) {
        src = *(u8**)(p + 0x40 + i * 4);
        dst = p + 0x46c + i * 16;
        dst[0] = src[0x150];
        dst[1] = src[0x151];
        dst[2] = src[0x152];
        dst[3] = src[0x153];
        dst[4] = src[0x154];
        dst[5] = src[0x155];
        dst[6] = src[0x156];
        dst[7] = src[0x157];
        dst[8] = src[0x158];
        dst[9] = src[0x159];
        dst[10] = src[0x15a];
        dst[11] = src[0x15b];
        dst[12] = src[0x15c];
        dst[13] = src[0x15d];
        dst[14] = src[0x15e];
        dst[15] = src[0x15f];
    }
    *(void**)(p + 0x50) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723031ULL);
    *(void**)(p + 0x54) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723132ULL);
    *(void**)(p + 0x58) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723133ULL);
    *(void**)(p + 0x60) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723231ULL);
    *(void**)(p + 0x64) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723232ULL);
    *(void**)(p + 0x68) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x4e64617461723233ULL);
    *(void**)(p + 0xa8) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653131ULL);
    *(void**)(p + 0xb8) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653132ULL);
    *(void**)(p + 0xc8) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653133ULL);
    *(void**)(p + 0xd8) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653134ULL);
    *(void**)(p + 0xe8) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653135ULL);
    *(void**)(p + 0xf8) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3131ULL);
    *(void**)(p + 0x108) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3132ULL);
    *(void**)(p + 0x118) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3133ULL);
    *(void**)(p + 0x128) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3134ULL);
    *(void**)(p + 0x138) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3135ULL);
    *(void**)(p + 0xac) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653231ULL);
    *(void**)(p + 0xbc) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653232ULL);
    *(void**)(p + 0xcc) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653233ULL);
    *(void**)(p + 0xdc) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653234ULL);
    *(void**)(p + 0xec) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653235ULL);
    *(void**)(p + 0xfc) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3231ULL);
    *(void**)(p + 0x10c) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3232ULL);
    *(void**)(p + 0x11c) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3233ULL);
    *(void**)(p + 0x12c) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3234ULL);
    *(void**)(p + 0x13c) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3235ULL);
    *(void**)(p + 0xb0) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653331ULL);
    *(void**)(p + 0xc0) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653332ULL);
    *(void**)(p + 0xd0) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653333ULL);
    *(void**)(p + 0xe0) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653334ULL);
    *(void**)(p + 0xf0) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f72653335ULL);
    *(void**)(p + 0x100) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3331ULL);
    *(void**)(p + 0x110) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3332ULL);
    *(void**)(p + 0x120) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3333ULL);
    *(void**)(p + 0x130) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3334ULL);
    *(void**)(p + 0x140) = ((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x5473636f726b3335ULL);
    *(void**)(p + 0x148) = ((Scr_803B1B60**)(p + 4))[*(s32*)(p + 0x450)]->v3C(0x00506c7465737431ULL);
    *(void**)(p + 0x14c) = ((Scr_803B1B60**)(p + 4))[*(s32*)(p + 0x450)]->v3C(0x00506c7477737432ULL);
    *(void**)(p + 0x150) = ((Scr_803B1B60**)(p + 4))[*(s32*)(p + 0x450)]->v3C(0x00506c7465737433ULL);
    *(void**)(p + 0x158) = ((Scr_803B1B60**)(p + 4))[*(s32*)(p + 0x450)]->v3C(0x0050727073743031ULL);
    *(void**)(p + 0x15c) = ((Scr_803B1B60**)(p + 4))[*(s32*)(p + 0x450)]->v3C(0x0050727073743032ULL);
    *(void**)(p + 0x160) = ((Scr_803B1B60**)(p + 4))[*(s32*)(p + 0x450)]->v3C(0x0050727073743033ULL);
    *(void**)(p + 0x168) = ((Scr_803B1B60**)(p + 4))[*(s32*)(p + 0x450)]->v3C(0x004e646174613035ULL);
    *(void**)(p + 0x16c) = ((Scr_803B1B60*)*(void**)(p + 0x1c))->v3C(0x005072736c746267ULL);
    IntroSetupScores(p, 3);
    {
        s32 font = *(s32*)((u8*)lbl_8053AD78 + 0x154);
        ((PaneVt_803B38E8*)((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x0000546d6d743032ULL))->v9C(font);
    }
    {
        s32 font = *(s32*)((u8*)lbl_8053AD78 + 0x154);
        ((PaneVt_803B38E8*)((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x0000546d6d743031ULL))->v9C(font);
    }
    fn_803832BC(((J2DTextBox*)((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x0000546d6d743032ULL))->getStringPtr(), 0xdd, 0, 0, 0);
    fn_803832BC(((J2DTextBox*)((Scr_803B1B60**)(p + 0x10))[*(s32*)(p + 0x450)]->v3C(0x0000546d6d743031ULL))->getStringPtr(), 0xdd, 0, 0, 0);
    m = (Menu_Intro*)p;
    IntroReadAlpha(m, m->alphaTitle, tbl->title, 13);
    m->y41c = m->screens[m->cur]->search(0x00506d6d776b3032ULL)->getBounds()->i.y;
    IntroReadAlpha(m, m->alpha3, tbl->p3[0], 3);
    m->y420 = m->screens[m->cur]->search(0x5031616762623032ULL)->getBounds()->i.y;
    IntroReadAlpha(m, m->alpha, tbl->p2[0], 2);
    m->y424 = m->screens[m->cur]->search(0x000050316f6b3032ULL)->getBounds()->i.y;
    *(f32*)(p + 0x428) = m->screens[m->cur]->search(0x0050316167623031ULL)->getBounds()->i.y;
    m->screens[m->cur]->search(0x004e646174613032ULL)->hide();
    m->screens[m->cur]->search(0x004e646174613031ULL)->hide();
    m->screens[m->cur]->search(0x00506d6d776b3032ULL)->hide();
}

extern "C" void fn_803B5378(void* this_);
extern "C" void fn_80458F9C(void* mgr, s32 handle);
extern "C" void fn_80458FF0(void* mgr, u32 id, s32 a, s32 b);
extern void* sManager__8JUTVideo;
#pragma opt_propagation off
extern "C" void fn_803B6768(void* this_) {
    s32 count;
    s32* c320;
    s16* c460;
    u8* c2f0;
    s32 i;
    u8* p = (u8*)this_;
    count = lbl_8053AAF8->countPlayers();
    switch (count) {
    case 2:
        *(s32*)(p + 0x450) = 2;
        *(s32*)(p + 0x454) = 2;
        fn_803B38E8(p);
        break;
    case 3:
        *(s32*)(p + 0x450) = 1;
        *(s32*)(p + 0x454) = 3;
        fn_803B42C0(p);
        break;
    default:
        *(s32*)(p + 0x450) = 0;
        *(s32*)(p + 0x454) = 4;
        fn_803B5378(p);
        break;
    }
    {
        f32 x = *(f32*)(*(J2DPane**)(p + 0x70))->getBounds();
        (*(J2DPane**)(p + 0x70))->move(x, *(f32*)(p + 0x3f4));
    }
    {
        f32 x = *(f32*)(*(J2DPane**)(p + 0x8c))->getBounds();
        (*(J2DPane**)(p + 0x8c))->move(x, *(f32*)(p + 0x3f8));
    }
    {
        f32 x = *(f32*)(*(J2DPane**)(p + 0x94))->getBounds();
        (*(J2DPane**)(p + 0x94))->move(x, *(f32*)(p + 0x400));
    }
    {
        f32 x = *(f32*)(*(J2DPane**)(p + 0x90))->getBounds();
        (*(J2DPane**)(p + 0x90))->move(x, *(f32*)(p + 0x3fc));
    }
    *(u8*)(p + 0x4c2) = 0;
    *(s32*)(p + 0x440) = 1;
    *(s32*)(p + 0x444) = 0;
    *(s32*)(p + 0x448) = 0;
    *(s32*)(p + 0x44c) = 0;
    *(s32*)(p + 0x43c) = 0;
    *(s32*)(p + 0x438) = 0;
    *(s16*)(p + 0x458) = 0;
    *(s16*)(p + 0x45a) = 0;
    *(s16*)(p + 0x45c) = -1;
    *(s16*)(p + 0x45e) = -1;
    *(u8*)(p + 0x4db) = 0;
    *(u8*)(p + 0x4dc) = 0;
    *(u8*)(p + 0x4dd) = 0xff;
    c320 = (s32*)p;
    c460 = (s16*)p;
    c2f0 = p;
    i = 0;
    for (; i < 4; i++, c320++, c460++, c2f0 += 12) {
        *(s32*)((u8*)c320 + 0x320) = 0;
        *(s32*)((u8*)c320 + 0x350) = 0;
        *(s32*)((u8*)c320 + 0x340) = 0;
        *(s32*)((u8*)c320 + 0x350) = 0;
        *(s32*)((u8*)c320 + 0x360) = 0;
        *(s32*)((u8*)c320 + 0x370) = 0;
        *(s32*)((u8*)c320 + 0x380) = 0;
        *(s32*)((u8*)c320 + 0x390) = 0;
        *(s32*)((u8*)c320 + 0x3a0) = 0;
        *(s32*)((u8*)c320 + 0x3b0) = 0;
        *(u8*)(p + 0x4ac + i) = 0;
        *(s32*)((u8*)c320 + 0x3c0) = 0x3e;
        *(s32*)((u8*)c320 + 0x3d0) = 0;
        *(s32*)((u8*)c320 + 0x3e0) = 0;
        *(u8*)(p + 0x4b0 + i) = 0;
        *(u8*)(p + 0x4b4 + i) = 0xff;
        *(u8*)(p + 0x4b8 + i) = 0xff;
        *(u8*)(p + 0x4bc + i) = 0xff;
        *(s16*)((u8*)c460 + 0x460) = 0;
        if (((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << i)) {
            J2DPane* pane = *(J2DPane**)((u8*)c320 + 0x158);
            f32 x0;
            f32 width = *(f32*)((u8*)pane + 0x28) - *(f32*)((u8*)pane + 0x20);
            s32 texW = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 4);
            x0 = *(f32*)pane->getBounds();
            f32 cx = *(f32*)(*(J2DPane**)(p + 0x168))->getBounds();
            cx += x0;
            f32 scale = lbl_805433CC;
            f32 center = width * lbl_805433E8 + cx;
            *(f32*)(c2f0 + 0x2f0) = scale * center / (f32)texW;

            s32 texH = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 6);
            pane = *(J2DPane**)((u8*)c320 + 0x158);
            f32 by = ((f32*)(*(J2DPane**)(p + 0x168))->getBounds())[1];
            f32 h = *(f32*)((u8*)pane + 0x2c) - *(f32*)((u8*)pane + 0x24);
            const f32 scaleY = lbl_805433D0;
            const f32 b = lbl_80543400;
            const f32 a = lbl_805433FC;
            f32 total;
            f32 y = by + h;
            total = *(f32*)(p + 0x3f0) + y;
            f32 yy = total - a;
            total = yy - b;
            *(f32*)(c2f0 + 0x2f4) = scaleY * total / (f32)texH;
            *(f32*)(c2f0 + 0x2f8) = lbl_805433C8;
        }
    }
    *(u8*)(p + 0x4c3) = 0;
    *(u8*)(p + 0x4c4) = 0;
    *(u8*)(p + 0x4c5) = 0;
    *(u8*)(p + 0x4c6) = 0;
    *(u8*)(p + 0x4c8) = 0xff;
    *(u8*)(p + 0x4c7) = 0;
    *(s32*)(p + 0x434) = 0x4b0;
    s32 mode = *(s32*)(lbl_80529DEC + 0x118);
    if ((mode == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 1 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 2 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 3 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 4 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 5 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 6 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || (mode == 7 && *(s32*)(lbl_80529DEC + 0x11c) == 1)
        || (mode == 10 && *(s32*)(lbl_80529DEC + 0x11c) == 2)
        || *(u8*)(lbl_80529DEC + 0x237) == 8) {
        *(u8*)(p + 0x4c0) = 5;
    } else {
        *(u8*)(p + 0x4c0) = 2;
    }
    *(u8*)(p + 0x4c1) = 1;
    *(s32*)(p + 0x440) = 0x80;
    if (*(s32*)(lbl_80529DEC + 0x118) == 7 && *(s32*)(lbl_80529DEC + 0x11c) == 3) {
        fn_80458F9C(lbl_8053AF80, 0x3c);
    } else if (*(u8*)(p + 0x4c0) == 5) {
        fn_80458FF0(lbl_8053AF80, 0x100002f, 0, 0);
    } else {
        fn_80458FF0(lbl_8053AF80, 0x1000005, 1, 0);
    }
    *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235c) = 0;
    *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235d) = 0;
    *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235e) = 0;
    *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235f) = 0;
    fn_80128C58(0xff);
    u32 color = -0x100;
    fn_8013A884(&color);
}
#pragma opt_propagation reset
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

extern "C" void __construct_array(void* p, void* ctor, void* dtor, s32 size, s32 count);
extern "C" void __ct__Q29JGeometry8TVec3_f_Fv(void);
extern "C" void OSReport(const char*, ...);
class WaveController {
public:
    WaveController(s32, s32, s32);
private:
    u8 field_00[0x5c];
};
static inline void MsgReportFontSize(const char* format, const J2DPane* pane) {
    OSReport(format, *(const u16*)((const u8*)pane + 0x132));
}
extern void fn_803B7B90(void* thisPtr);
extern "C" void __mtspr(u32,u32);
extern "C" void OSReport(const char*,...);
extern "C" void* load__20J2DAnmLoaderDataBaseFPCv(const void*);
extern "C" void* fn_804030C4(u32,const char*);
extern "C" void fn_8045B46C(void*,s8,s32,s32,s32);
extern "C" void __ct__14WaveControllerFlll(void*,s32,s32,s32);
#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void* fn_803B6FD8(u8* p) {
 const char* base=(const char*)lbl_80476208;
 s32 i;
 f32 b,a,height; f32 y;
 void* obj; J2DScreen* screen; J2DPicture* picture;
    *(void**)p = lbl_804AF9A0;
    __construct_array(p + 0x250, (void*)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 0xa);
    __construct_array(p + 0x2f0, (void*)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 4);
    __construct_array(p + 0x46c, (void*)fn_803B7B90, 0, 0x10, 4);
    ((JKRHeap*)*(void**)(lbl_80529DEC + 8))->getTotalFreeSize();
    lbl_8053ADA0 = p;
    *(s32*)(p + 0x1c8) = 0;
    *(s32*)(p + 0x1cc) = 0;
    *(s32*)(p + 0x1d0) = 0;
    *(s32*)(p + 0x1d4) = 0;
    *(s32*)(p + 0x1d8) = 0;
    *(s32*)(p + 0x1dc) = 0;
    *(s32*)(p + 0x1e0) = 0;
    *(s32*)(p + 0x1e4) = 0;
    *(s32*)(p + 0x1e8) = 0;
    *(s32*)(p + 0x1ec) = 0;
    *(s32*)(p + 0x1f0) = 0;
    *(s32*)(p + 0x1f4) = 0;
    *(s32*)(p + 0x1f8) = 0;
    *(s32*)(p + 0x1fc) = 0;
    *(s32*)(p + 0x200) = 0;
    *(s32*)(p + 0x204) = 0;
    *(s32*)(p + 0x208) = 0;
    *(s32*)(p + 0x20c) = 0;
    *(s32*)(p + 0x210) = 0;
    *(s32*)(p + 0x214) = 0;
    *(s32*)(p + 0x218) = 0;
    *(s32*)(p + 0x21c) = 0;
    *(s32*)(p + 0x220) = 0;
    *(s32*)(p + 0x224) = 0;
    *(s32*)(p + 0x228) = 0;
    *(s32*)(p + 0x22c) = 0;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x188) = 0;
    *(s32*)(p + 0x198) = 0;
    *(s32*)(p + 0x1a8) = 0;
    *(s32*)(p + 0x1b8) = 0;
    *(s32*)(p + 0x18c) = 0;
    *(s32*)(p + 0x19c) = 0;
    *(s32*)(p + 0x1ac) = 0;
    *(s32*)(p + 0x1bc) = 0;
    *(s32*)(p + 0x190) = 0;
    *(s32*)(p + 0x1a0) = 0;
    *(s32*)(p + 0x1b0) = 0;
    *(s32*)(p + 0x1c0) = 0;
    *(s32*)(p + 0x194) = 0;
    *(s32*)(p + 0x1a4) = 0;
    *(s32*)(p + 0x1b4) = 0;
    *(s32*)(p + 0x1c4) = 0;
    screen=new J2DScreen(); *(J2DScreen**)(p+0x4)=screen;
    ((J2DScreen*)*(void**)(p + 0x4))->setPriority(base + 0x224, 0x1100000, (JKRArchive*)((void**)lbl_8053AD68)[6]);
    screen=new J2DScreen(); *(J2DScreen**)(p+0x10)=screen;
    ((J2DScreen*)*(void**)(p + 0x10))->setPriority(base + 0x234, 0x1100000, (JKRArchive*)((void**)lbl_8053AD68)[6]);
MsgReportFontSize(base+0x248,(*(J2DScreen**)(p+0x10))->search(0x0000546d6d743031ULL));
MsgReportFontSize(base+0x258,(*(J2DScreen**)(p+0x10))->search(0x0000546d6d743032ULL));
screen=new J2DScreen(); *(J2DScreen**)(p+0x1c)=screen; (*(J2DScreen**)(p+0x1c))->setPriority(base+0x268,0x1100000,(JKRArchive*)((void**)lbl_8053AD68)[6]);
screen=new J2DScreen(); *(J2DScreen**)(p+8)=screen; (*(J2DScreen**)(p+8))->setPriority(base+0x278,0x1100000,(JKRArchive*)((void**)lbl_8053AD68)[6]);
screen=new J2DScreen(); *(J2DScreen**)(p+0x14)=screen; (*(J2DScreen**)(p+0x14))->setPriority(base+0x288,0x1100000,(JKRArchive*)((void**)lbl_8053AD68)[6]);
MsgReportFontSize(base+0x248,(*(J2DScreen**)(p+0x14))->search(0x0000546d6d743031ULL));
MsgReportFontSize(base+0x258,(*(J2DScreen**)(p+0x14))->search(0x0000546d6d743032ULL));
screen=new J2DScreen(); *(J2DScreen**)(p+0xc)=screen; (*(J2DScreen**)(p+0xc))->setPriority(base+0x29c,0x1100000,(JKRArchive*)((void**)lbl_8053AD68)[6]);
screen=new J2DScreen(); *(J2DScreen**)(p+0x18)=screen; (*(J2DScreen**)(p+0x18))->setPriority(base+0x2ac,0x1100000,(JKRArchive*)((void**)lbl_8053AD68)[6]);
screen=new J2DScreen(); *(J2DScreen**)(p+0x20)=screen; (*(J2DScreen**)(p+0x20))->setPriority(base+0x2c0,0x1100000,(JKRArchive*)((void**)lbl_8053AD68)[6]);
OSInitFastCast();
*(void**)(p+0x24)=load__20J2DAnmLoaderDataBaseFPCv(fn_80403104('SCRN',base+0x2d4)); (*(J2DScreen**)(p+4))->setAnimation(*(J2DAnmTextureSRTKey**)(p+0x24));
*(void**)(p+0x28)=load__20J2DAnmLoaderDataBaseFPCv(fn_80403104('SCRN',base+0x2e4)); (*(J2DScreen**)(p+8))->setAnimation(*(J2DAnmTextureSRTKey**)(p+0x28));
*(void**)(p+0x2c)=load__20J2DAnmLoaderDataBaseFPCv(fn_80403104('SCRN',base+0x2f4)); (*(J2DScreen**)(p+12))->setAnimation(*(J2DAnmTextureSRTKey**)(p+0x2c));
ResTIMG* image=(ResTIMG*)fn_804030C4('TIMG',base+0x304);
picture=new J2DPicture(image); *(J2DPicture**)(p+0x170)=picture;
(*(J2DPicture**)(p+0x170))->setBlackWhite(JUtility::TColor(0xffU),JUtility::TColor(0U));
obj=(*(J2DScreen**)(p+4))->search(0x00506c7465737434ULL);height=*(f32*)((u8*)obj+0x2c)-*(f32*)((u8*)obj+0x24);
a=getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(0x0050727073743034ULL))[1];
a=getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(0x004e646174613035ULL))[1]+a;
b=getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(0x00506c7465737434ULL))[1];
b=getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(0x004e646174613034ULL))[1]+b;
*(f32*)(p+0x3f0)=height*lbl_805433E8+(getBounds__7J2DPaneFv((*(J2DScreen**)(p+4))->search(0x0050727073743034ULL))[1]+b-a);
*(f32*)(p+1012)=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x20))->search(0x5074746c626b3035ULL))[1];
*(f32*)(p+1016)=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x20))->search(0x50656d6273623036ULL))[1];
*(f32*)(p+1020)=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x20))->search(0x0050726d68623036ULL))[1];
*(f32*)(p+1024)=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x20))->search(0x506c6c6f73623036ULL))[1];
*(f32*)(p+1044)=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x20))->search(0x5077696e626b3035ULL))[1];
*(f32*)(p+1048)=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x20))->search(0x50647277626b3035ULL))[1];
*(f32*)(p+1032)=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x20))->search(0x00506c68626b3032ULL))[1];
*(f32*)(p+1028)=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x20))->search(0x00506468626b3032ULL))[1];
*(f32*)(p+1036)=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x20))->search(0x0050666f626b3032ULL))[1];
*(f32*)(p+1040)=getBounds__7J2DPaneFv((*(J2DScreen**)(p+0x20))->search(0x00506861626b3032ULL))[1];
*(J2DPane**)(p+112)=(*(J2DScreen**)(p+0x20))->search(0x5074746c626b3035ULL);
*(J2DPane**)(p+116)=(*(J2DScreen**)(p+0x20))->search(0x50647277626b3035ULL);
*(J2DPane**)(p+120)=(*(J2DScreen**)(p+0x20))->search(0x5077696e626b3035ULL);
*(J2DPane**)(p+124)=(*(J2DScreen**)(p+0x20))->search(0x000050776e723031ULL);
*(J2DPane**)(p+128)=(*(J2DScreen**)(p+0x20))->search(0x000050776e723032ULL);
*(J2DPane**)(p+140)=(*(J2DScreen**)(p+0x20))->search(0x50656d6273623036ULL);
*(J2DPane**)(p+144)=(*(J2DScreen**)(p+0x20))->search(0x0050726d68623036ULL);
*(J2DPane**)(p+148)=(*(J2DScreen**)(p+0x20))->search(0x506c6c6f73623036ULL);
*(J2DPane**)(p+152)=(*(J2DScreen**)(p+0x20))->search(0x00506c68626b3032ULL);
*(J2DPane**)(p+156)=(*(J2DScreen**)(p+0x20))->search(0x00506468626b3032ULL);
*(J2DPane**)(p+160)=(*(J2DScreen**)(p+0x20))->search(0x00506861626b3032ULL);
*(J2DPane**)(p+164)=(*(J2DScreen**)(p+0x20))->search(0x0050666f626b3032ULL);
(*(u8**)(p+112))[0xb0]=1;
(*(u8**)(p+116))[0xb0]=0;
(*(u8**)(p+120))[0xb0]=0;
(*(u8**)(p+124))[0xb0]=0;
(*(u8**)(p+128))[0xb0]=0;
(*(u8**)(p+140))[0xb0]=0;
(*(u8**)(p+144))[0xb0]=0;
(*(u8**)(p+148))[0xb0]=0;
(*(u8**)(p+152))[0xb0]=0;
(*(u8**)(p+156))[0xb0]=0;
(*(u8**)(p+164))[0xb0]=0;
(*(u8**)(p+160))[0xb0]=0;
*(f32*)(p+0x244)=lbl_805433C8;*(f32*)(p+0x248)=lbl_805433C8;*(f32*)(p+0x24c)=lbl_805433C8;
{u8* row=p; s32 i; for(i=0;i<4;i++,row+=4){obj=operator new(0x60);if(obj)fn_8045B46C(obj,(s8)i,0,0,8);*(void**)(row+0x174)=obj;}}
*(WaveController**)(p+0x184)=new WaveController((s32)(p+0x244),0,8);
((JGeometry::TVec3f*)(p+0x250))[0].set(lbl_805433C8,lbl_805433C8,lbl_805433C8);*(s32*)(p+712)=-1;
((JGeometry::TVec3f*)(p+0x250))[1].set(lbl_805433C8,lbl_805433C8,lbl_805433C8);*(s32*)(p+716)=-1;
((JGeometry::TVec3f*)(p+0x250))[2].set(lbl_805433C8,lbl_805433C8,lbl_805433C8);*(s32*)(p+720)=-1;
((JGeometry::TVec3f*)(p+0x250))[3].set(lbl_805433C8,lbl_805433C8,lbl_805433C8);*(s32*)(p+724)=-1;
((JGeometry::TVec3f*)(p+0x250))[4].set(lbl_805433C8,lbl_805433C8,lbl_805433C8);*(s32*)(p+728)=-1;
((JGeometry::TVec3f*)(p+0x250))[5].set(lbl_805433C8,lbl_805433C8,lbl_805433C8);*(s32*)(p+732)=-1;
((JGeometry::TVec3f*)(p+0x250))[6].set(lbl_805433C8,lbl_805433C8,lbl_805433C8);*(s32*)(p+736)=-1;
((JGeometry::TVec3f*)(p+0x250))[7].set(lbl_805433C8,lbl_805433C8,lbl_805433C8);*(s32*)(p+740)=-1;
((JGeometry::TVec3f*)(p+0x250))[8].set(lbl_805433C8,lbl_805433C8,lbl_805433C8);*(s32*)(p+744)=-1;
((JGeometry::TVec3f*)(p+0x250))[9].set(lbl_805433C8,lbl_805433C8,lbl_805433C8);*(s32*)(p+748)=-1;
if(*(s32*)(lbl_80529DEC+0x118)==9 && *(s32*)(lbl_80529DEC+0x11c)==3){*(s32*)(lbl_80529DEC+0x118)=7;*(s32*)(lbl_80529DEC+0x11c)=3;}
return p;
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JMath/JMath.h"
#include "dolphin/os/OSFastCast.h"
extern const f32 lbl_805433CC, lbl_805433D0, lbl_805433D4, lbl_805433E8, lbl_805433EC, lbl_805433F0, lbl_805433F4, lbl_805433F8, lbl_805433FC, lbl_80543400;
extern u8 lbl_8050EC80[];
extern "C" u32 fn_80309D6C(void*, s32, s32);
extern "C" void fn_803B236C(void*);
extern "C" void fn_803AA1F8(void* this_) {
    u8* q2;
    u8* q3;
    u8* v;
    u8* q4;
    s32 i;
    f32 dy;
    f32 x0;
    u8* p = (u8*)this_;
    if (p[0x4c8] != 0xff) {
        s32 n = 0;
        --*(s32*)(p + 0x444);
        if (*(s32*)(p + 0x444) == 0) {
            u8* q1 = p;
            for (s32 j = 0; j < *(s32*)(p + 0x454); q1 += 4, ++j) {
                if (j == p[0x4ac + n]) {
                    if (*(void**)(q1 + 0x1b8) == 0) {
                        u8* pane = *(u8**)(q1 + 0x158);
                        f32 width = *(f32*)(pane + 0x28) - *(f32*)(pane + 0x20);
                        FVec3 pos(lbl_805433E8 * width + *(f32*)(pane + 0x30), lbl_805433C8, lbl_805433C8);
                        *(void**)(q1 + 0x1b8) = fn_8013CC50(0, &pos, 0x241, 0, 0, 0, 0, 1, lbl_805433D4);
                    }
                    if (p[0x4c8] > n) ++n;
                }
            }
            *(s32*)(p + 0x444) = 0xf0;
        }
    }
    q2 = p;
    for (i = 0; i < *(s32*)(p + 0x454); q2 += 4, ++i) {
        if (*(s32*)(q2 + 0x3d0) != 0) {
            ++*(s32*)(q2 + 0x3d0);
            if (*(s32*)(q2 + 0x3d0) < 8) *(s32*)(q2 + 0x3c0) = 0xc4;
            else if (*(s32*)(q2 + 0x3d0) < 16) *(s32*)(q2 + 0x3c0) = 0xc3;
            else if (*(s32*)(q2 + 0x3d0) < 24) *(s32*)(q2 + 0x3c0) = 0xc4;
            else { *(s32*)(q2 + 0x3c0) = 0xc3; *(s32*)(q2 + 0x3d0) = 0; }
        } else if (*(s32*)(q2 + 0x3c0) == 0xc3) {
            if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(i), 0x100)) {
                ++*(s32*)(q2 + 0x3d0);
                *(s32*)(q2 + 0x3c0) = 0xc4;
                u32 msg = 0x20032;
                (*(MsgSinkObj2**)(p + 0x174 + p[0x4ac + i] * 4))->send(&msg);
            }
        }
    }
    q3 = p;
    v = p;
    for (i = 0; i < *(s32*)(p + 0x454); q3 += 4, ++i, v += 12) {
        *(s32*)(q3 + 0x3e0) = *(s32*)(q3 + 0x3a0) + (*(s32*)(q3 + 0x320) + (*(s32*)(q3 + 0x340) + *(s32*)(q3 + 0x350) + *(s32*)(q3 + 0x360) + *(s32*)(q3 + 0x370)) - *(s32*)(q3 + 0x380) + *(s32*)(q3 + 0x3b0));
        if (*(s32*)(q3 + 0x3e0) < -5000) *(s32*)(q3 + 0x3e0) = -5000;

        if (*(s32*)(q3 + 0x3e0) < -500) {
            f32 ratio = lbl_805433EC / (f32)*(s32*)(p + 0x434);
            f32 height = (f32)*(s16*)(lbl_8050DB0C + 0x2b0);
            dy = ratio * height / lbl_805433F0;
        } else if (*(s32*)(q3 + 0x3e0) > 3000) {
            f32 ratio = lbl_805433F4 / (f32)*(s32*)(p + 0x434);
            f32 height = (f32)*(s16*)(lbl_8050DB0C + 0x2b0);
            dy = ratio * height / lbl_805433F0;
        }
        else
            dy = (f32)*(s16*)(lbl_8050DB0C + 0x2b0) * (lbl_805433F8 * (f32)*(s32*)(q3 + 0x3e0) / (f32)*(s32*)(p + 0x434)) / lbl_805433F0;
        f32 x = getBounds__7J2DPaneFv(*(void**)(q3 + 0x158))[0];
        (*(J2DPane**)(q3 + 0x158))->move(x, *(f32*)(p + 0x3f0) - dy);
        if (*(s32*)(q3 + 0x3e0) > 9999) *(s32*)(q3 + 0x3e0) = 9999;
        u8* pane = *(u8**)(q3 + 0x158);
        f32 width = *(f32*)(pane + 0x28) - *(f32*)(pane + 0x20);
        s32 texW = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 4);
        x0 = getBounds__7J2DPaneFv(pane)[0];
        f32 cx = getBounds__7J2DPaneFv(*(void**)(p + 0x168))[0];
        cx += x0;
        f32 scale = lbl_805433CC;
        f32 center = width * lbl_805433E8 + cx;
        *(f32*)(v + 0x2f0) = scale * center / (f32)texW;
        s32 texH = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 6);
        x0 = getBounds__7J2DPaneFv(*(void**)(q3 + 0x158))[3];
        f32 cy = getBounds__7J2DPaneFv(*(void**)(p + 0x168))[1];
        cy += x0;
        const f32 scaleY = lbl_805433D0;
        const f32 b = lbl_80543400;
        const f32 a = lbl_805433FC;
        *(f32*)(v + 0x2f4) = scaleY * (cy - a - b) / (f32)texH;
        *(f32*)(v + 0x2f8) = lbl_805433C8;
    }
    fn_803B2FB0((Menu_803B2FB0*)p);
    if (p[0x4c8] != 0xff) {
        fn_803B236C(p);
        for (i = 0; i < 10; ++i) {
            if (*(s32*)(p + 0x2c8 + i * 4) >= 0) {
                --*(s32*)(p + 0x2c8 + i * 4);
                if (*(s32*)(p + 0x2c8 + i * 4) <= -1) {
                    u8* slot = p + i * 12;
                    *(f32*)(p + 0x244) = *(f32*)(slot + 0x250);
                    *(f32*)(p + 0x248) = *(f32*)(slot + 0x254);
                    *(f32*)(p + 0x24c) = *(f32*)(slot + 0x258);
                    *(s32*)((p + i * 4) + 0x2c8) = -1;
                    u32 msg = 0x3002a;
                    (*(MsgSinkObj2**)(p + 0x184))->send(&msg);
                    break;
                }
            }
        }
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1100, -1)) {
        u8* game = lbl_8050EC80;
        u8* entry = game + *(s32*)(game + 0x10) * 0xc8;
        s32 add = *(s32*)(p + 0x324) + *(s32*)(p + 0x328);
        add += *(s32*)(p + 0x32c);
        add += *(s32*)(entry + 0x30);
        *(s32*)(entry + 0x30) = *(s32*)(p + 0x320) + add;
        entry = game + *(s32*)(game + 0x10) * 0xc8;
        if (*(s32*)(entry + 0x30) > 99999)
            *(s32*)(entry + 0x30) = 99999;
        entry = lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8;
        if (*(s32*)(entry + 0x30) < -99999)
            *(s32*)(entry + 0x30) = -99999;
        p[0x4c0] = 4;
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
    q4 = p;
    for (i = 0; i < 30; q4 += 4, ++i) {
        JPABaseEmitter* e = *(JPABaseEmitter**)(q4 + 0x1c8);
        if (e != 0 && e->isEnableDeleteEmitter()) {
            JPAEmitterManager* mgr = *(JPAEmitterManager**)((u8*)fn_8013C824() + 0xc);
            mgr->forceDeleteEmitter(*(JPABaseEmitter**)(q4 + 0x1c8));
            *(JPABaseEmitter**)(q4 + 0x1c8) = 0;
        }
    }
}

extern const u16 lbl_80543390[4];

#pragma push
#pragma dont_inline on
extern "C" void fn_803AA8F8(void* this_) {
    Menu_Intro* ip = (Menu_Intro*)this_;
    IntroTags* tbl = (IntroTags*)lbl_80476208;
    s32 n;
    s32 j;
    s32 i;
    s32 t;
    f32 off;
    u8* q3;
    u8* v;
    const u16* ids;
    f32 dy;
    f32 x0;
    J2DPane* pane_;
#define self ((u8*)ip)
    switch (self[0x4c1]) {
    case 0x00:
    case 0x05:
        break;
    case 0x01:
        ip->timer--;
        if (ip->timer == 0) {
            ip->timer = 150;
            if (ip->cur < 2) {
                pane_ = ip->screens[ip->cur]->search(0x004e646174613031ULL);
                pane_->mIsVisible = 1;
                pane_ = ip->screens[ip->cur]->search(0x004e646174613032ULL);
                pane_->mIsVisible = 1;
                pane_ = ip->screens[ip->cur]->search(0x00506d6d776b3032ULL);
                pane_->mIsVisible = 1;
                if (ip->cur < 2) {
                    const u64* k = tbl->title;
                    for (i = 0; i < 13; i++, k++) {
                        ip->screens[ip->cur]->search(*k)->setAlpha((u8)(ip->alphaTitle[i] * lbl_805433C8));
                    }
                }
                const u64* k3 = tbl->p3[0];
                const u64* k2 = tbl->p2[0];
                for (j = 0; j < ip->count; j++, k3 += 3, k2 += 2) {
                    if (ip->cur < 2) {
                        const u64* k = k3;
                        for (i = 0; i < 3; i++, k++) {
                            ip->screens[ip->cur]->search(*k)->setAlpha((u8)(ip->alpha3[i] * lbl_805433C8));
                        }
                    }
                    if (ip->cur < 2) {
                        const u64* k = k2;
                        for (i = 0; i < 2; i++, k++) {
                            ip->screens[ip->cur]->search(*k)->setAlpha((u8)(ip->alpha[i] * lbl_805433C8));
                        }
                    }
                    ip->selected[j] = 0xff;
                    ip->m460[j] = 0;
                }
                ip->m4c1 = 2;
            } else {
                ip->m4c1 = 8;
            }
        }
        break;
    case 0x02:
        fn_803B1B60((Menu_Intro*)this_);
        break;
    case 0x03:
        fn_803B14F8(this_);
        break;
    case 0x04:
        fn_803B0FD4((Menu_Intro*)this_);
        break;
    case 0x06:
        fn_803B0978((Menu_Intro*)this_);
        break;
    case 0x07:
        fn_803B03E8((Menu_Intro*)this_);
        break;
    case 0x08:
        fn_803B0158((Menu_Slide*)this_);
        break;
    case 0x09:
        fn_803AFCF0((Menu_Rank*)this_);
        break;
    case 0x0A:
        fn_803AFA78((Menu_Join*)this_);
        break;
    case 0x0B:
        fn_803AF79C((Menu_Slide*)this_);
        break;
    case 0x0C:
        fn_803AF604(this_);
        break;
    case 0x0D:
        fn_803AF1B0((Menu_Rank*)this_);
        break;
    case 0x0E:
        fn_803AEF08((Menu_Join*)this_);
        break;
    case 0x0F:
        fn_803AEC78((Menu_Slide*)this_);
        break;
    case 0x10:
        fn_803AE810((Menu_Rank*)this_);
        break;
    case 0x11:
        fn_803AE598((Menu_Join*)this_);
        break;
    case 0x12:
        fn_803AE308((Menu_Slide*)this_);
        break;
    case 0x13:
        fn_803ADE9C((Menu_Coin*)this_);
        break;
    case 0x14:
        fn_803ADC0C((Menu_Slide*)this_);
        break;
    case 0x15:
        q3 = self;
        for (i = n = 0; i < *(s32*)(self + 0x454); q3 += 4, i++) {
            if (*(s32*)(q3 + 0x370) < fn_80403070(fn_80403414(i))) {
                *(s32*)(q3 + 0x370) += 2;
            }
            if (*(s32*)(q3 + 0x370) >= fn_80403070(fn_80403414(i))) {
                *(s32*)(q3 + 0x370) = fn_80403070(fn_80403414(i));
                n++;
            }
        }
        if (n >= *(s32*)(self + 0x454)) {
            self[0x4c8] = 0xff;
            *(s32*)(self + 0x438) = 0;
            *(s32*)(self + 0x440) = 150;
            fn_80458880(lbl_8053AF80, 0xf, -1);
            *(s32*)(self + 0x438) = 0;
            if (*(s32*)(self + 0x450) < 2) {
                self[0x4c1] = 0x16;
            } else {
                self[0x4c1] = 0x1c;
            }
        } else if (n != *(s32*)(self + 0x438)) {
            *(s32*)(self + 0x438) = n;
            fn_80458880(lbl_8053AF80, 0x10, -1);
            fn_80458880(lbl_8053AF80, 0xe, -1);
        }
        break;
    case 0x16:
        fn_803AD894((Menu_Slide*)this_);
        break;
    case 0x17:
        fn_803AD4B0((Menu_Hits*)this_);
        break;
    case 0x18:
        --*(s32*)(self + 0x440);
        if (self[0x4dc] < 0xfe) {
            self[0x4dc] += 2;
        } else {
            self[0x4dc] = 0xff;
        }
        if (*(s32*)(self + 0x440) == 0) {
            *(s32*)(self + 0x440) = 150;
            self[0x4c1] = 0x19;
        }
        break;
    case 0x19:
        fn_803AD220((Menu_Slide*)this_);
        break;
    case 0x1A:
        fn_803ACDA4((Menu_Hits*)this_);
        break;
    case 0x1B:
        --*(s32*)(self + 0x440);
        if (self[0x4dd] > 1) {
            self[0x4dd] -= 2;
        } else {
            self[0x4dd] = 0;
        }
        if (*(s32*)(self + 0x440) == 0x95) {
            q3 = self;
            v = self;
            for (i = 0, ids = lbl_80543390; i < *(s32*)(self + 0x454); q3 += 4, ids++, v += 12, i++) {
                if (self[0x4db] & (u8)(1 << (i + 4))) {
                    if (*(void**)(q3 + 0x188) == 0) {
                        *(void**)(q3 + 0x188) = fn_8013CC50(0, (FVec3*)(v + 0x2f0), *ids, 0, -1, 0, 0, 1, lbl_805433D4);
                    }
                    if (*(void**)(q3 + 0x198) == 0) {
                        *(void**)(q3 + 0x198) = fn_8013CC50(0, (FVec3*)(v + 0x2f0), 0x475, 0, -1, 0, 0, 1, lbl_805433D4);
                    }
                }
            }
        }
        if (*(s32*)(self + 0x440) == 0) {
            q3 = self;
            for (i = 0; i < *(s32*)(self + 0x454); q3 += 4, i++) {
                EffHandle* e = *(EffHandle**)(q3 + 0x188);
                if (e != 0) {
                    e->flags |= 1;
                    e->m24 = 1;
                    *(EffHandle**)(q3 + 0x188) = 0;
                }
                e = *(EffHandle**)(q3 + 0x198);
                if (e != 0) {
                    e->flags |= 1;
                    e->m24 = 1;
                    *(EffHandle**)(q3 + 0x198) = 0;
                }
                *(s32*)(self + 0x440) = 150;
                self[0x4c1] = 0x1c;
            }
        }
        break;
    case 0x1C:
        fn_803AC998((Menu_Slide*)this_);
        break;
    case 0x1D:
        fn_803AC6FC((Menu_Score*)this_);
        break;
    case 0x1E:
        fn_803AC154((Menu_Join*)this_);
        break;
    case 0x1F:
        --*(s32*)(self + 0x440);
        t = *(s32*)(self + 0x440);
        if (t == 0) {
            *(s32*)(self + 0x440) = 150;
            fn_80458880(lbl_8053AF80, 0x2c, -1);
            *(s32*)(self + 0x440) = 150;
            self[0x4c1] = 0x20;
        } else if (t >= 0x8a) {
            off = lbl_80543404 * ((f32)(12 - (t - 0x8a)) / lbl_80543408);
            x0 = getBounds__7J2DPaneFv(*(void**)(self + 0xa4))[0];
            (*(J2DPane**)(self + 0xa4))->move(x0, *(f32*)(self + 0x40c) + off);
            if (*(s32*)(self + 0x440) == 0x8a) {
                (*(J2DPane**)(self + 0xa4))->mIsVisible = 0;
                (*(J2DPane**)(self + 0x70))->mIsVisible = 1;
                x0 = getBounds__7J2DPaneFv(*(void**)(self + 0x70))[0];
                (*(J2DPane**)(self + 0x70))->move(x0, *(f32*)(self + 0x3f4) + off);
            }
        } else if (t >= 0x80) {
            x0 = getBounds__7J2DPaneFv(*(void**)(self + 0x70))[0];
            off = lbl_80543404 * ((f32)(t - 0x80) / lbl_80543408);
            (*(J2DPane**)(self + 0x70))->move(x0, *(f32*)(self + 0x3f4) + off);
            if (*(s32*)(self + 0x440) == 0x80) {
                x0 = getBounds__7J2DPaneFv(*(void**)(self + 0x70))[0];
                (*(J2DPane**)(self + 0xa4))->move(x0, *(f32*)(self + 0x3f4));
            }
        }
        break;
    case 0x20:
        fn_803ABCEC((Menu_Slide*)this_);
        break;
    case 0x21:
        fn_803AB494(this_);
        break;
    }
    q3 = self;
    v = self;
    for (i = 0; i < *(s32*)(self + 0x454); q3 += 4, ++i, v += 12) {
        *(s32*)(q3 + 0x3e0) = *(s32*)(q3 + 0x3a0) + (*(s32*)(q3 + 0x320) + (*(s32*)(q3 + 0x340) + *(s32*)(q3 + 0x350) + *(s32*)(q3 + 0x360) + *(s32*)(q3 + 0x370)) - *(s32*)(q3 + 0x380) + *(s32*)(q3 + 0x3b0));
        if (*(s32*)(q3 + 0x3e0) < -5000) *(s32*)(q3 + 0x3e0) = -5000;

        if (*(s32*)(q3 + 0x3e0) < -500) {
            f32 ratio = lbl_805433EC / (f32)*(s32*)(self + 0x434);
            f32 height = (f32)*(s16*)(lbl_8050DB0C + 0x2b0);
            dy = ratio * height / lbl_805433F0;
        } else if (*(s32*)(q3 + 0x3e0) > 3000) {
            f32 ratio = lbl_805433F4 / (f32)*(s32*)(self + 0x434);
            f32 height = (f32)*(s16*)(lbl_8050DB0C + 0x2b0);
            dy = ratio * height / lbl_805433F0;
        }
        else
            dy = (f32)*(s16*)(lbl_8050DB0C + 0x2b0) * (lbl_805433F8 * (f32)*(s32*)(q3 + 0x3e0) / (f32)*(s32*)(self + 0x434)) / lbl_805433F0;
        f32 x = getBounds__7J2DPaneFv(*(void**)(q3 + 0x158))[0];
        (*(J2DPane**)(q3 + 0x158))->move(x, *(f32*)(self + 0x3f0) - dy);
        if (*(s32*)(q3 + 0x3e0) > 9999) *(s32*)(q3 + 0x3e0) = 9999;
        u8* pane = *(u8**)(q3 + 0x158);
        f32 width = *(f32*)(pane + 0x28) - *(f32*)(pane + 0x20);
        s32 texW = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 4);
        x0 = getBounds__7J2DPaneFv(pane)[0];
        f32 cx = getBounds__7J2DPaneFv(*(void**)(self + 0x168))[0];
        cx += x0;
        f32 scale = lbl_805433CC;
        f32 center = width * lbl_805433E8 + cx;
        *(f32*)(v + 0x2f0) = scale * center / (f32)texW;
        s32 texH = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 6);
        x0 = getBounds__7J2DPaneFv(*(void**)(q3 + 0x158))[3];
        f32 cy = getBounds__7J2DPaneFv(*(void**)(self + 0x168))[1];
        cy += x0;
        const f32 scaleY = lbl_805433D0;
        const f32 b = lbl_80543400;
        const f32 a = lbl_805433FC;
        *(f32*)(v + 0x2f4) = scaleY * (cy - a - b) / (f32)texH;
        *(f32*)(v + 0x2f8) = lbl_805433C8;
    }
    fn_803B2FB0((Menu_803B2FB0*)self);
#undef self
}
#pragma pop
