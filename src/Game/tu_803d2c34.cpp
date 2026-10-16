// TU 0x803d2c34-0x803d6434.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

#include <string.h>
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"
#include <dolphin/os.h>

struct SaveEntry {
    OSTime time;       // 0x00
    u32 f8;            // 0x08
    u8 padc[0x65 - 0xc];
    u8 flags;          // 0x65
    u8 pad66[0xc8 - 0x66];
};

struct SaveData {
    u8 pad0[0x8];
    u64 id;            // 0x08
    s32 idx;           // 0x10
    u8 pad14[0xc];
    SaveEntry entries[3]; // 0x20
    u8 pad278[8];
    u8 extra[0x1d4c];  // 0x280
};

struct SaveMgr {
    u8 pad0[0x1ff4];
    u8 chan;
    u8 state;
    u8 pad1ff6[2];
    u64 id;
};

struct MCAnim {
    u8 pad0[0x8];
    f32 f8;
    u8 padc[0x22 - 0xc];
    s16 f22;
};

struct MCVis {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void set(int v);
};

struct MCBounds {
    u8 pad0[0x20];
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
};

struct MCAlpha {
    u8 pad0[0x4];
    MCVis* vis;
    u8 pad8[0x18 - 0x8];
    f32 f18;
    f32 f1c;
    u8 pad20[0x24 - 0x20];
    s16 f24;
    s16 f26;
    u8 f28;
};

struct MCPane {
    u8 pad0[0xb0];
    u8 visible;
};

struct MCPaneHolder {
    u8 pad0[0x4];
    MCPane* pane;
    u8 pad8[0x28 - 0x8];
    u8 f28;
};

struct MemCardMenu;
typedef void (MemCardMenu::*MCStateFn)();
extern MemCardMenu* lbl_8053ADB8;

static inline f32 mcW(MCAlpha* a) {
    MCBounds* b = (MCBounds*)a->vis;
    return b->x1 - b->x0;
}
static inline f32 mcH(MCAlpha* a) {
    MCBounds* b = (MCBounds*)a->vis;
    return b->y1 - b->y0;
}

struct MemCardMenu {
    u8 pad0[0x4];
    J2DScreen* screen;
    J2DPicture* f08;
    J2DTextBox* f0c;
    J2DTextBox* f10;
    MCAlpha* f14;
    MCAnim* f18;
    MCAnim* f1c[2];
    MCAnim* f24;
    MCPaneHolder* f28;
    MCAlpha* f2c[4];
    MCAlpha* f3c[4];
    MCAnim* f4c;
    u32 f50;
    u32 f54;
    u8 pad58[0x78 - 0x58];
    s32 f78;
    s32 f7c;
    s16 f80;
    s16 f82;
    s16 f84;
    s16 f86;
    char f88[0x1b4 - 0x88];
    u8 f1b4;
    u8 pad1b5[0x1c0 - 0x1b5];
    SaveEntry entries[3]; // 0x1c0
    u8 pad418[8];
    u8 work[0x1d4c];      // 0x420
    u8 f216c;
    u8 f216d;
    u8 f216e;
    u8 f216f;
    u8 f2170;
    u8 f2171;
    u8 pad2172;
    u8 f2173;
    u8 f2174;
    u8 f2175;
    u8 f2176;
    u8 f2177;

    void fn_803D4770();
    void fn_803D4484();
    void fn_803D4298();
    void fn_803D4068();
    void fn_803D3EC8();
    void fn_803D3D50();
    void fn_803D3C90();
    void fn_803D3B38();
    void fn_803D39C8();
    void fn_803D3928();
    void fn_803D3898();
    void fn_803D373C();
    void fn_803D35F0();
    void fn_803D35C4();
    void fn_803D3460();
    void fn_803D335C();
    void fn_803D3214();
    void fn_803D3180();
    void fn_803D3108();
    void fn_803D3060();
    void fn_803D2FFC();
    void fn_803D2E10();
    void fn_803D2C9C();
    void fn_803D2C34();
};

static MCStateFn lbl_804B0168[24] = {
    &MemCardMenu::fn_803D4770,
    &MemCardMenu::fn_803D4484,
    &MemCardMenu::fn_803D4298,
    &MemCardMenu::fn_803D4068,
    &MemCardMenu::fn_803D3EC8,
    &MemCardMenu::fn_803D3D50,
    &MemCardMenu::fn_803D3C90,
    &MemCardMenu::fn_803D3B38,
    &MemCardMenu::fn_803D39C8,
    &MemCardMenu::fn_803D3928,
    &MemCardMenu::fn_803D3898,
    &MemCardMenu::fn_803D373C,
    &MemCardMenu::fn_803D35F0,
    &MemCardMenu::fn_803D35C4,
    &MemCardMenu::fn_803D3460,
    &MemCardMenu::fn_803D335C,
    &MemCardMenu::fn_803D3214,
    &MemCardMenu::fn_803D3180,
    &MemCardMenu::fn_803D3108,
    &MemCardMenu::fn_803D3060,
    &MemCardMenu::fn_803D2FFC,
    &MemCardMenu::fn_803D2E10,
    &MemCardMenu::fn_803D2C9C,
    &MemCardMenu::fn_803D2C34,
};


extern SaveData lbl_8050EC80;
extern SaveMgr lbl_8051C1A0;
extern u8 lbl_80529DEC[];
extern void* lbl_8053AD30;
extern void* lbl_8053AF80;

extern "C" {
void* fn_80309C4C(void*, s32, s32);
void fn_80458880(void*, s32, s32);
s32 fn_803B9A94(SaveMgr*, void*, u32, void*, u32, s32);
s32 fn_803B9BDC(SaveMgr*);
void fn_8013B490(void*);
void fn_804316EC(void*);
void fn_80440EE8(void*);
extern void* lbl_8053AED8;
extern struct MCGrc { u8 pad[0x10]; const J2DGrafContext* ctx; }* lbl_8053AB10;
BOOL fn_80431A9C(void*, s32, s32, u8*);
void fn_80382B48(char* dst, u32 id, s32 a, char* yes, char* no);
void fn_8037EB0C(f32* a, f32* b, f32* c, f32* d, u8* e);
void fn_804310CC(void*);
void fn_80402E08(void* p, f32 x, f32 y);
void fn_80402CE0(void* p, f32 x, f32 y);
void fn_80431174(void*, u8);
BOOL fn_804317AC(void*);
BOOL fn_80431740(void*);
u8 fn_802B1DCC(void*);
extern void* lbl_8053ACA8;
u8 fn_80402940(void* p, int a, f32 x, f32 y, int b);
u8 fn_80402628(void* p, int a, int b, int c);
u8 fn_8040271C(void* p, int a, f32 x, f32 y);
extern u8 lbl_8050DB0C[];
void fn_804310BC(void*);
extern void* lbl_8053AEC0;
u32 fn_803B9940(SaveMgr*, s32);
void fn_803B9B8C(SaveMgr*);
s32 fn_803B9C5C(SaveMgr*);
void fn_803B9DDC(SaveMgr*);
void fn_803B9CCC(SaveMgr*, void*, u32, s32);
void fn_803BADAC(SaveEntry*);
void fn_803BACF8(SaveEntry*, u8);
void fn_803B93E8(SaveData*, SaveEntry*, void*, s32);
void fn_803B9D54(SaveMgr*, void*, u32, void*, u32, s32);
s32 CARDGetSerialNo(s32 chan, u64* serial);
extern u8* lbl_8053AAF8;

static inline void stampSave() {
lbl_8050EC80.entries[lbl_8050EC80.idx].time = OSGetTime();
if (!(lbl_8050EC80.entries[lbl_8050EC80.idx].flags & 1)) {
lbl_8050EC80.entries[lbl_8050EC80.idx].flags |= 1;
}
if (lbl_8050EC80.entries[lbl_8050EC80.idx].f8 & 1) {
lbl_8050EC80.entries[lbl_8050EC80.idx].flags |= 2;
}
}

void MemCardMenu::fn_803D2C34() {
    MemCardMenu* self = this;
    if (fn_80309C4C(lbl_8053AD30, 0x1300, -1)) {
        self->f54 = 0;
        self->f216c = 5;
        self->f2175 = 1;
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

void MemCardMenu::fn_803D2C9C() {
    MemCardMenu* self = this;
    s32 r = fn_803B9A94(&lbl_8051C1A0, self->entries, 0x258, self->work, 0x1d4c, 0);
    if (r == 0) {
    } else if (r == 1) {
        if (lbl_8050EC80.id == lbl_8051C1A0.id) {
            fn_803BADAC(&self->entries[lbl_8050EC80.idx]);
            lbl_8050EC80.entries[lbl_8050EC80.idx].time = OSGetTime();
            u8* e = (u8*)&lbl_8050EC80 + lbl_8050EC80.idx * 0xc8;
            if (!(e[0x85] & 1)) {
                e[0x85] |= 1;
            }
            if (((SaveEntry*)((u8*)&lbl_8050EC80 + lbl_8050EC80.idx * 0xc8 + 0x20))->f8 & 1) {
                e = (u8*)&lbl_8050EC80 + lbl_8050EC80.idx * 0xc8;
                e[0x85] |= 2;
            }
            self->f54 = 0x7e;
            self->f2177 = 0;
            self->f216d = 0x12;
            self->f216e = 1;
            lbl_80529DEC[0x24c] = 1;
        } else {
            self->f54 = 0x7c;
            self->f2177 = 0;
            self->f216d = 6;
        }
    } else if (r == 2) {
        self->f216c = 5;
        self->f2175 = 1;
    }
}

void MemCardMenu::fn_803D2E10() {
    MemCardMenu* self = this;
    if (fn_80309C4C(lbl_8053AD30, 1, -1)) {
        if (self->f2170 != 0) {
            self->f2170--;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 2, -1)) {
        if (self->f2170 < 1) {
            self->f2170++;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x100, -1)) {
        self->f2171 = self->f2170;
        if (self->f2170 == 0) {
            memcpy(self->work, lbl_8050EC80.extra, 0x1d4c);
            stampSave();
            self->f54 = 0x7e;
            self->f2177 = 0;
            self->f216d = 0x12;
            self->f216e = 1;
            lbl_80529DEC[0x24c] = 1;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            self->f2170 = 0;
            self->f54 = 0x7b;
            self->f2177 = 0;
            self->f216d = 2;
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
        self->f82 = 1;
    }
}

void MemCardMenu::fn_803D2FFC() {
    MemCardMenu* self = this;
    if (self->f7c > 0) {
        self->f7c--;
    }
    if (self->f7c == 0) {
        if (lbl_80529DEC[0x24d]) {
            self->f216d = 0x19;
            self->f216c = 4;
        } else {
            self->f54 = 0x82;
            self->f2177 = 0;
            self->f216d = 3;
        }
    }
}

void MemCardMenu::fn_803D3060() {
    MemCardMenu* self = this;
    s32 r = fn_803B9BDC(&lbl_8051C1A0);
    if (r == 1) {
        self->f54 = 0x80;
        self->f2177 = 0;
        self->f216d = 0x14;
        self->f216e = 0;
        lbl_80529DEC[0x24c] = 0;
        self->f1b4 = 1;
        self->f7c = 0x5a;
    } else if (r == 2) {
        self->f54 = 0x7f;
        self->f2177 = 0;
        self->f216d = 0x17;
        self->f216e = 0;
        lbl_80529DEC[0x24c] = 0;
    }
}

void MemCardMenu::fn_803D3108() {
    MemCardMenu* self = this;
    memcpy(self->entries, lbl_8050EC80.entries, 0x258);
    fn_803BACF8(self->entries, lbl_8050EC80.idx);
    fn_803B9CCC(&lbl_8051C1A0, self->entries, 0x258, 0);
    self->f216c = 0x13;
}

void MemCardMenu::fn_803D3180() {
    MemCardMenu* self = this;
    if (self->f7c > 0) {
        self->f7c--;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1300, -1) || self->f7c == 0) {
        self->f7c = -1;
        self->f2170 = 0;
        self->f54 = 0x7b;
        self->f2177 = 0;
        self->f216d = 2;
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

void MemCardMenu::fn_803D3214() {
    MemCardMenu* self = this;
    s32 r = fn_803B9BDC(&lbl_8051C1A0);
    if (r == 1) {
        self->f54 = 0x7a;
        self->f2177 = 0;
        lbl_8053AAF8[0xff] = 1;
        stampSave();
        u64 serial;
        CARDGetSerialNo(lbl_8051C1A0.chan, &serial);
        lbl_8050EC80.id = serial;
        self->f216d = 0x11;
        self->f216e = 0;
        lbl_80529DEC[0x24c] = 0;
        self->f7c = 0x5a;
    } else if (r == 2) {
        self->f54 = 0x79;
        self->f2177 = 0;
        self->f216d = 0x17;
        self->f216e = 0;
        lbl_80529DEC[0x24c] = 0;
    }
}

void MemCardMenu::fn_803D335C() {
    MemCardMenu* self = this;
    fn_803B93E8(&lbl_8050EC80, self->entries, self->work, 0);
    fn_803BACF8(self->entries, 0);
    fn_803B93E8(&lbl_8050EC80, self->entries, self->work, 1);
    fn_803BACF8(self->entries, 1);
    fn_803B93E8(&lbl_8050EC80, self->entries, self->work, 2);
    fn_803BACF8(self->entries, 2);
    fn_803B9D54(&lbl_8051C1A0, self->entries, 0x258, self->work, 0x1d4c, 0);
    for (s32 i = 0; i < 3; i++) {
        if (i != lbl_8050EC80.idx) {
            memcpy(&lbl_8050EC80.entries[i], (u8*)self + 0x1c0 + i * sizeof(SaveEntry), sizeof(SaveEntry));
        }
    }
    self->f216c = 0x10;
}

void MemCardMenu::fn_803D3460() {
    MemCardMenu* self = this;
    if (fn_80309C4C(lbl_8053AD30, 1, -1)) {
        if (self->f2170 != 0) {
            self->f2170--;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 2, -1)) {
        if (self->f2170 < 1) {
            self->f2170++;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x100, -1)) {
        self->f2171 = self->f2170;
        if (self->f2170 == 0) {
            self->f54 = 0x78;
            self->f2177 = 0;
            self->f216d = 0xf;
            self->f216e = 1;
            lbl_80529DEC[0x24c] = 1;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            self->f54 = 0x77;
            self->f2177 = 0;
            self->f216d = 6;
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
        self->f82 = 1;
    }
}


void MemCardMenu::fn_803D4298() {
    MemCardMenu* self = this;
    if (fn_80309C4C(lbl_8053AD30, 1, -1)) {
        if (self->f2170 != 0) {
            self->f2170--;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 2, -1)) {
        if (self->f2170 < 1) {
            self->f2170++;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x100, -1)) {
        self->f2175 = 0;
        self->f2171 = self->f2170;
        if (self->f2170 == 0) {
            self->f216c = 5;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            self->f1b4 = 1;
            if (lbl_80529DEC[0x24d]) {
                self->f18->f22 = 0;
                self->f1c[0]->f22 = 0;
                self->f1c[1]->f22 = 0;
                self->f24->f22 = 0;
                if (self->f2176) {
                    self->f4c->f22 = 0;
                }
                self->f28->pane->visible = 0;
                self->f84 = 0;
                self->f216f = 2;
                self->f2171 = self->f2170;
                if (self->f2174) {
                    fn_804310BC(lbl_8053AEC0);
                    self->f2173 = 0;
                }
                self->f216d = 0x19;
                self->f216c = 4;
            } else {
                self->f2170 = 0;
                self->f54 = 0x82;
                self->f2177 = 0;
                self->f216d = 3;
            }
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
        self->f82 = 1;
    }
}

void fn_803D49A4(MemCardMenu* self) {
    f32 w0 = mcW(self->f2c[0]);
    f32 b0 = self->f2c[0]->f18;
    fn_80402E08(self->f2c[0], -(0.5f * (w0 - b0)), -(0.5f * (mcH(self->f2c[0]) - self->f2c[0]->f1c)));
    fn_80402E08(self->f2c[1], 0.5f * (mcW(self->f2c[1]) - self->f2c[1]->f18), -(0.5f * (mcH(self->f2c[1]) - self->f2c[1]->f1c)));
    fn_80402E08(self->f2c[2], -(0.5f * (mcW(self->f2c[2]) - self->f2c[2]->f18)), 0.5f * (mcH(self->f2c[2]) - self->f2c[2]->f1c));
    fn_80402E08(self->f2c[3], 0.5f * (mcW(self->f2c[3]) - self->f2c[3]->f18), 0.5f * (mcH(self->f2c[3]) - self->f2c[3]->f1c));
    if (w0 / b0 < 1.0f) {
        fn_80402CE0(self->f3c[0], (2.0f * (self->f2c[0]->f18 - mcW(self->f2c[0])) + self->f3c[0]->f18) / self->f3c[0]->f18, self->f3c[0]->f1c);
        fn_80402E08(self->f3c[0], 0.0f, 0.0f);
        fn_80402CE0(self->f3c[1], (2.0f * (self->f2c[1]->f18 - mcW(self->f2c[1])) + self->f3c[1]->f18) / self->f3c[1]->f18, self->f3c[1]->f1c);
        fn_80402E08(self->f3c[1], 0.0f, 0.0f);
        fn_80402CE0(self->f3c[2], (mcW(self->f2c[0]) + mcW(self->f2c[1])) / self->f3c[2]->f18, (2.0f * (self->f2c[2]->f1c - mcH(self->f2c[2])) + self->f3c[2]->f1c) / self->f3c[2]->f1c);
        fn_80402E08(self->f3c[2], 0.0f, 0.0f);
        fn_80402CE0(self->f3c[3], (mcW(self->f2c[2]) + mcW(self->f2c[3])) / self->f3c[3]->f18, (2.0f * (self->f2c[3]->f1c - mcH(self->f2c[3])) + self->f3c[3]->f1c) / self->f3c[3]->f1c);
        fn_80402E08(self->f3c[3], 0.0f, 0.0f);
    } else {
        fn_80402E08(self->f3c[0], -(f32)(0.5f * (mcW(self->f3c[0]) - self->f3c[0]->f18) + (mcW(self->f2c[0]) - self->f2c[0]->f18)), 0.0f);
        fn_80402E08(self->f3c[1], 0.5f * (mcW(self->f3c[1]) - self->f3c[1]->f18) + (mcW(self->f2c[1]) - self->f2c[1]->f18), 0.0f);
        fn_80402E08(self->f3c[2], 0.0f, -(f32)(0.5f * (mcH(self->f3c[2]) - self->f3c[2]->f1c) + (mcH(self->f2c[2]) - self->f2c[2]->f1c)));
        fn_80402E08(self->f3c[3], 0.0f, 0.5f * (mcH(self->f3c[3]) - self->f3c[3]->f1c) + (mcH(self->f2c[3]) - self->f2c[3]->f1c));
    }
}

void fn_803D4DB0(MemCardMenu* self) {
    if (self->f54 != self->f50 && self->f54 != 0) {
        if (self->f2174 == 0) {
            self->f50 = self->f54;
            u32 m = self->f50;
            if (m == 0x6b || m - 0x6c <= 2 || m - 0x70 <= 1 || m == 0x77 || m == 0x7c) {
                fn_80431A9C(lbl_8053AEC0, m, 0, NULL);
                self->f2173 = 0;
                self->f2174 = 2;
                if (self->f216f != 0) {
                    self->f1c[0]->f22 = 0;
                    self->f1c[1]->f22 = 0;
                    self->f216f = 2;
                }
                strcpy(self->f10->getStringPtr(), "");
            } else {
                char* title = ((J2DTextBox*)self->screen->search('Tyes01'))->getStringPtr();
                fn_80382B48(self->f88, self->f50, 0, title, ((J2DTextBox*)self->screen->search('Tno01'))->getStringPtr());
                m = self->f50;
                if (m == 0x6f || m == 0x72 || m == 0x76 || m == 0x7b || m == 0x7d || m == 0x82 || m == 0x86 || m == 0x87) {
                    f32 a, c, b, d;
                    fn_8037EB0C(&a, &b, &c, &d, &self->f2170);
                    if (self->f216f != 3) {
                        self->f1c[0]->f22 = 0;
                        self->f1c[1]->f22 = 0;
                        self->f216f = 1;
                    }
                    for (s32 i = 0; title[i] != 0; i++) {
                        if ((u8)title[i] == 0x81 && (u8)title[i + 1] == 0x40) {
                            title[i] = 0;
                            break;
                        }
                    }
                    strcpy(self->f10->getStringPtr(), self->f88);
                } else {
                    if (self->f216f != 0) {
                        self->f1c[0]->f22 = 0;
                        self->f1c[1]->f22 = 0;
                        self->f216f = 2;
                    }
                    strcpy(self->f10->getStringPtr(), self->f88);
                }
            }
            if (self->f2177) {
                self->f84 = 0;
                strcpy(self->f0c->getStringPtr(), self->f88);
                self->f216c = 0;
            } else {
                self->f54 = self->f50;
                self->f86 = 0;
                self->f216c = 1;
            }
            self->f0c->setAlpha(0xff);
            self->f10->setAlpha(0);
        } else if (self->f2174 == 1) {
            self->f2174 = 3;
        }
    }
}

void fn_803D5090(MemCardMenu* self) {
    if (self->f2174 == 1) {
        fn_80431174(lbl_8053AEC0, self->f2170);
    }
    if (self->f216c != 0 && self->f216c != 2 && self->f216c != 1 && self->f216c != 3) {
        if (lbl_8051C1A0.state == 0 || lbl_8051C1A0.state == 1) {
            if (!fn_802B1DCC(lbl_8053ACA8) && !self->f216e && !self->f1b4) {
                self->f216c = 5;
                self->f2175 = 1;
            }
        }
    }
    if (self->f216c < 0x18) {
        (lbl_8053ADB8->*lbl_804B0168[self->f216c])();
    }
    fn_803D4DB0(self);
    lbl_8051C1A0.state = 2;
    if (self->f2174 == 2) {
        if (self->f2173 > 0x48) {
            self->f2173 = 0x50;
        } else {
            self->f2173 += 8;
        }
        if (fn_804317AC(lbl_8053AEC0)) {
            self->f2173 = 0x50;
            self->f2174 = 1;
        }
    } else if (self->f2174 == 3) {
        if (self->f2173 < 8) {
            self->f2173 = 0;
        } else {
            self->f2173 -= 8;
        }
        if (fn_80431740(lbl_8053AEC0)) {
            self->f2173 = 0;
            self->f2174 = 0;
        }
    }
}

void fn_803D521C(MemCardMenu* self) {
    fn_8013B490(lbl_8053AB10);
    if (self->f216f == 3) {
        f32 off = 0.0f;
        f32 alpha;
        if (self->f82 > 0) {
            if (self->f82 == 1) {
                self->f80 = 0x1e;
            }
            s32 t = self->f82 < 5 ? self->f82 : 10 - self->f82;
            off = 5.0f * (f32)(t * t) / 25.0f;
            if (self->f82 < 10) {
                self->f82++;
            } else {
                self->f82 = 0;
            }
        }
        self->f80++;
        if (self->f80 >= 0x3c) {
            self->f80 = 0;
        }
        if (self->f80 < 0x1e) {
            alpha = self->f28->f28 * ((f32)(self->f80 * self->f80) / 900.0f);
        } else {
            s32 t = self->f80 - 0x1e;
            alpha = (1.0f - (f32)(t * t) / 900.0f) * (f32)self->f28->f28;
        }
        ((J2DPane*)self->f28->pane)->setAlpha((u8)alpha);
        self->screen->search('Paccur01')->setAlpha((u8)alpha);
        if (self->f2171 == 0) {
            fn_80402E08(self->f28, 0.0f, off);
            fn_80402E08(self->f1c[0], 0.0f, off);
            fn_80402E08(self->f1c[1], 0.0f, 0.0f);
        } else {
            fn_80402E08(self->f28, self->f1c[1]->f8 - self->f1c[0]->f8, off);
            fn_80402E08(self->f1c[0], 0.0f, 0.0f);
            fn_80402E08(self->f1c[1], 0.0f, off);
        }
        if (0.0f == off && self->f2171 != self->f2170) {
            self->f2171 = self->f2170;
        }
    }
    self->screen->draw(0.0f, 0.0f, lbl_8053AB10->ctx);
    if (self->f2174) {
        self->f08->setAlpha(self->f2173);
        self->f08->draw(-1.0f, -1.0f, 611.0f, 451.0f, false, false, false);
        fn_804316EC(lbl_8053AEC0);
    }
    if (self->f2176) {
        fn_80440EE8(lbl_8053AED8);
    }
}

void fn_803D5554(MemCardMenu* self) {
    fn_804310CC(lbl_8053AEC0);
    self->f54 = 0;
    self->f50 = 0;
    self->f216e = 0;
    self->f78 = 0;
    self->f88[0] = 0;
    self->f2170 = 0;
    self->f2171 = 0;
    self->f7c = -1;
    self->f84 = 0;
    self->f216f = 0;
    self->f80 = 0;
    self->f82 = 0;
    self->f86 = 0;
    self->f2174 = 0;
    self->f2173 = 0;
    self->f2177 = 0;
    self->f2175 = 0;
    self->f1b4 = 0;
    self->f2170 = 0;
    self->f54 = 0x7b;
    self->f2177 = 1;
    self->f216c = 2;
    self->f14->vis->set(0);
    self->f14->f26 = 0;
    fn_80402E08(self->f18, 0.0f, -480.0f);
    self->f18->f22 = 0;
    for (s32 i = 0; i < 2; i++) {
        fn_80402E08(self->f1c[i], 0.0f, 200.0f);
        self->f1c[i]->f22 = 0;
    }
    fn_80402E08(self->f24, 0.0f, -250.0f);
    self->f24->f22 = 0;
    self->f28->pane->visible = 0;
    for (s32 i = 0; i < 8; i++) {
        fn_80402CE0(self->f2c[i], 1.0f, 1.0f);
        self->f2c[i]->f24 = 0;
        self->f2c[i]->vis->set(0);
        self->f2c[i]->f26 = 0;
    }
    fn_803D49A4(self);
    lbl_80529DEC[0x243] = 0;
}

void MemCardMenu::fn_803D4770() {
    MemCardMenu* self = this;
    u8 a = 0;
    u8 b = 0;
    u8 c = 0;
    u8 d = 0;
    u8 e = 0;
    s32 t0 = *(s16*)(lbl_8050DB0C + 0xc8);
    s32 t1 = *(s16*)(lbl_8050DB0C + 0xca);
    s32 t2 = *(s16*)(lbl_8050DB0C + 0xcc);
    s32 t3 = *(s16*)(lbl_8050DB0C + 0xce);
    s32 t4 = *(s16*)(lbl_8050DB0C + 0xd0);
    s32 t5 = *(s16*)(lbl_8050DB0C + 0xd2);
    s32 t11 = *(s16*)(lbl_8050DB0C + 0xe2);
    s32 t6 = *(s16*)(lbl_8050DB0C + 0xd4);
    s32 t7 = *(s16*)(lbl_8050DB0C + 0xd6);
    s32 t8 = *(s16*)(lbl_8050DB0C + 0xd8);
    s32 t9 = *(s16*)(lbl_8050DB0C + 0xde);
    s32 t10 = *(s16*)(lbl_8050DB0C + 0xe0);
    self->f84++;
    if (self->f84 > t0) {
        a = fn_80402628(self->f14, t1, 0, self->f14->f28);
    }
    if (self->f84 > t2) {
        b = fn_80402940(self->f24, t3, -250.0f, 0.0f, 0);
        if (self->f2176) {
            fn_80402940(self->f4c, t3, -200.0f, 0.0f, 0);
        }
    }
    if (self->f84 > t4 + t5) {
        c = fn_80402940(self->f18, t11, 26.0f, 0.0f, 0);
    } else if (self->f84 > t4) {
        fn_80402940(self->f18, t5, -480.0f, 26.0f, 0);
    }
    for (s32 i = 0; i < 2; i++) {
        if (self->f84 > t6 + i * t8) {
            d = fn_80402940(self->f1c[i], t7, 200.0f, 0.0f, 0);
        }
    }
    if (self->f84 > t9) {
        for (s32 i = 0; i < 8; i++) {
            e = fn_8040271C(self->f2c[i], t10, 2.0f, 1.0f);
            fn_80402628(self->f2c[i], t10, 0, self->f2c[i]->f28);
        }
        fn_803D49A4(self);
    }
    if (a && b && c && d && e) {
        self->f216f = 3;
        self->f80 = 0x1e;
        self->f28->pane->visible = 1;
        self->f216c = self->f216d;
    }
}

void MemCardMenu::fn_803D4484() {
    MemCardMenu* self = this;
    s32 t0 = *(s16*)(lbl_8050DB0C + 0xe4);
    s32 t1 = *(s16*)(lbl_8050DB0C + 0xe6);
    s32 t2 = *(s16*)(lbl_8050DB0C + 0xe8);
    s32 t3 = *(s16*)(lbl_8050DB0C + 0xea);
    s32 t4 = *(s16*)(lbl_8050DB0C + 0xec);
    u8 done[3];
    done[2] = 0;
    self->f86++;
    done[1] = 0;
    done[0] = 0;
    if (self->f216f == 1) {
        for (s32 i = 0; i < 2; i++) {
            if (self->f86 > t2 + i * t4) {
                done[i] = fn_80402940(self->f1c[i], t3, 200.0f, 0.0f, 0);
            }
        }
        if (done[0] && done[1]) {
            self->f216f = 3;
            self->f80 = 0x1e;
            self->f28->pane->visible = 1;
        }
    } else if (self->f216f == 2) {
        for (s32 i = 0; i < 2; i++) {
            if (self->f86 > t2 + i * t4) {
                done[i] = fn_80402940(self->f1c[i], t3, 0.0f, 200.0f, 0);
            }
        }
        if (self->f86 > t2 + 1) {
            self->f28->pane->visible = 0;
        }
        if (done[0] && done[1]) {
            self->f216f = 0;
        }
    } else {
        done[1] = 1;
        done[0] = 1;
    }
    if (self->f86 > t0) {
        f32 r = (f32)(self->f86 - t0) / (f32)t1;
        self->f0c->setAlpha((u8)(255.0f * (1.0f - r)));
        self->f10->setAlpha((u8)(255.0f * r));
        if (self->f86 >= t1 + t0) {
            done[2] = 1;
        }
    }
    if (done[0] && done[1] && done[2]) {
        if ((u32)self->f54 == 0x80) {
            fn_80458880(lbl_8053AF80, 0x5b, -1);
        }
        strcpy(self->f0c->getStringPtr(), self->f88);
        self->f0c->setAlpha(0xff);
        self->f10->setAlpha(0);
        self->f216c = self->f216d;
    }
}

void MemCardMenu::fn_803D35C4() {
    OSResetSystem(1, 1, 1);
}

void MemCardMenu::fn_803D35F0() {
    MemCardMenu* self = this;
    if (fn_80309C4C(lbl_8053AD30, 1, -1)) {
        if (self->f2170 != 0) {
            self->f2170--;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 2, -1)) {
        if (self->f2170 < 1) {
            self->f2170++;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x100, -1)) {
        self->f2171 = self->f2170;
        if (self->f2170 == 0) {
            self->f54 = 0;
            self->f216c = 0xd;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            self->f2170 = 0;
            self->f54 = 0x7b;
            self->f2177 = 0;
            self->f216d = 2;
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
        self->f82 = 1;
    }
}

void MemCardMenu::fn_803D373C() {
    MemCardMenu* self = this;
    if (fn_80309C4C(lbl_8053AD30, 1, -1)) {
        if (self->f2170 != 0) {
            self->f2170--;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 2, -1)) {
        if (self->f2170 < 1) {
            self->f2170++;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x100, -1)) {
        self->f2171 = self->f2170;
        if (self->f2170 == 0) {
            self->f2170 = 1;
            self->f54 = 0x87;
            self->f2177 = 0;
            self->f216d = 0xc;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            self->f2170 = 0;
            self->f54 = 0x7b;
            self->f2177 = 0;
            self->f216d = 2;
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
        self->f82 = 1;
    }
}

void MemCardMenu::fn_803D3898() {
    MemCardMenu* self = this;
    if (self->f7c > 0) {
        self->f7c--;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1300, -1) || self->f7c == 0) {
        self->f7c = -1;
        self->f54 = 0;
        self->f216c = 5;
        self->f2175 = 1;
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

void MemCardMenu::fn_803D3928() {
    MemCardMenu* self = this;
    s32 r = fn_803B9C5C(&lbl_8051C1A0);
    if (r == 1) {
        self->f54 = 0x74;
        self->f2177 = 0;
        self->f216d = 0xa;
        self->f216e = 0;
        lbl_80529DEC[0x24c] = 0;
        self->f7c = 0x5a;
    } else if (r == 2) {
        self->f54 = 0x75;
        self->f2177 = 0;
        self->f216d = 0x17;
        self->f216e = 0;
        lbl_80529DEC[0x24c] = 0;
    }
}

void MemCardMenu::fn_803D39C8() {
    MemCardMenu* self = this;
    if (fn_80309C4C(lbl_8053AD30, 1, -1)) {
        if (self->f2170 != 0) {
            self->f2170--;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 2, -1)) {
        if (self->f2170 < 1) {
            self->f2170++;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x100, -1)) {
        self->f2171 = self->f2170;
        if (self->f2170 == 0) {
            self->f54 = 0x73;
            self->f2177 = 0;
            self->f216d = 9;
            fn_803B9DDC(&lbl_8051C1A0);
            self->f216e = 1;
            lbl_80529DEC[0x24c] = 1;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            self->f54 = 0x71;
            self->f2177 = 0;
            self->f216d = 6;
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
        self->f82 = 1;
    }
}

void MemCardMenu::fn_803D3B38() {
    MemCardMenu* self = this;
    if (fn_80309C4C(lbl_8053AD30, 1, -1)) {
        if (self->f2170 != 0) {
            self->f2170--;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 2, -1)) {
        if (self->f2170 < 1) {
            self->f2170++;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x100, -1)) {
        self->f2171 = self->f2170;
        if (self->f2170 == 0) {
            self->f2170 = 1;
            self->f54 = 0x72;
            self->f2177 = 0;
            self->f216d = 8;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            self->f54 = 0x71;
            self->f2177 = 0;
            self->f216d = 6;
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
        self->f82 = 1;
    }
}

void MemCardMenu::fn_803D3C90() {
    MemCardMenu* self = this;
    if (fn_80309C4C(lbl_8053AD30, 0x1300, -1)) {
        if (self->f50 == 0x70) {
            self->f54 = 0x85;
            self->f2177 = 0;
            self->f216d = self->f216c;
        } else if (self->f50 == 0x85) {
            self->f2170 = 1;
            self->f54 = 0x86;
            self->f2177 = 0;
            self->f216d = 0xb;
        } else {
            self->f2170 = 0;
            self->f54 = 0x7b;
            self->f2177 = 0;
            self->f216d = 2;
        }
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

void MemCardMenu::fn_803D3D50() {
    MemCardMenu* self = this;
    switch (fn_803B9940(&lbl_8051C1A0, 0)) {
    case 0:
        self->f54 = 0x6b;
        self->f2177 = 0;
        self->f216d = 6;
        break;
    case 8:
        self->f54 = 0x6c;
        self->f2177 = 0;
        self->f216d = 6;
        break;
    case 9:
        self->f54 = 0x6d;
        self->f2177 = 0;
        self->f216d = 6;
        break;
    case 10:
        self->f54 = 0x6e;
        self->f2177 = 0;
        self->f216d = 6;
        break;
    case 6:
    case 7:
        self->f2170 = 1;
        self->f54 = 0x6f;
        self->f2177 = 0;
        self->f216d = 7;
        break;
    case 11:
    case 12:
        self->f54 = 0x70;
        self->f2177 = 0;
        self->f216d = 6;
        break;
    case 2:
        if (self->f2175) {
            self->f2170 = 0;
            self->f54 = 0x7b;
            self->f2177 = 0;
            self->f216d = 2;
        } else {
            fn_803B9B8C(&lbl_8051C1A0);
            self->f216c = 0x16;
        }
        break;
    case 1:
        self->f2170 = 1;
        self->f54 = 0x76;
        self->f2177 = 0;
        self->f216d = 14;
        break;
    default:
        self->f54 = 0;
        break;
    }
}

void MemCardMenu::fn_803D3EC8() {
    MemCardMenu* self = this;
    u8 a = 0;
    u8 b = 0;
    u8 c = 0;
    s32 t0 = *(s16*)(lbl_8050DB0C + 0xee);
    s32 t1 = *(s16*)(lbl_8050DB0C + 0xf0);
    s32 t2 = *(s16*)(lbl_8050DB0C + 0xf2);
    s32 t3 = *(s16*)(lbl_8050DB0C + 0xf4);
    s32 t4 = *(s16*)(lbl_8050DB0C + 0xf6);
    s32 t5 = *(s16*)(lbl_8050DB0C + 0xf8);
    s32 t6 = *(s16*)(lbl_8050DB0C + 0xfa);
    self->f84++;
    if (self->f84 > t0) {
        a = fn_80402940(self->f24, t1, 0.0f, 480.0f, 0);
        if (self->f2176) {
            fn_80402940(self->f4c, t1, 0.0f, -200.0f, 0);
        }
        fn_80402628(self->f14, t1, self->f14->f28, 0);
        for (s32 i = 0; i < 8; i++) {
            fn_8040271C(self->f2c[i], t1, 1.0f, 2.0f);
            fn_80402628(self->f2c[i], t1, self->f2c[i]->f28, 0);
        }
        fn_803D49A4(self);
    }
    if (self->f84 > t2) {
        b = fn_80402940(self->f18, t3, 0.0f, 480.0f, 0);
    }
    for (s32 i = 0; i < 2; i++) {
        if (self->f84 > t4 + i * t6) {
            c = fn_80402940(self->f1c[i], t5, 0.0f, 200.0f, 0);
        }
    }
    if (a && b && c) {
        self->f216c = self->f216d;
    }
}

void MemCardMenu::fn_803D4068() {
    MemCardMenu* self = this;
    if (fn_80309C4C(lbl_8053AD30, 1, -1)) {
        if (self->f2170 != 0) {
            self->f2170--;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 2, -1)) {
        if (self->f2170 < 1) {
            self->f2170++;
            self->f2171 = self->f2170;
            self->f82 = 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x100, -1)) {
        self->f18->f22 = 0;
        self->f1c[0]->f22 = 0;
        self->f1c[1]->f22 = 0;
        self->f14->f26 = 0;
        for (s32 i = 0; i < 8; i++) {
            self->f2c[i]->f24 = 0;
            self->f2c[i]->f26 = 0;
        }
        self->f24->f22 = 0;
        if (self->f2176) {
            self->f4c->f22 = 0;
        }
        self->f28->pane->visible = 0;
        self->f84 = 0;
        self->f216f = 2;
        self->f2171 = self->f2170;
        if (self->f2174) {
            fn_804310BC(lbl_8053AEC0);
            self->f2173 = 0;
        }
        if (self->f2170 == 0) {
            self->f216d = 0x1a;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            self->f216d = 0x19;
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
        self->f216c = 4;
        self->f82 = 1;
    }
}


}

// ---- from src/Game/fn_803D5710.cpp ----
// vtable slot 2 (byte offset 8) - see [[reference_fsa_virtual_dispatch_codegen_trick]].
struct DtorSlot2 {
	virtual void destroy(s32 freeFlag);
};

extern "C" void getTotalFreeSize__7JKRHeapFv(void* p);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B0288[];
extern u8 lbl_80529DEC[];

static inline void DispatchSlot2(char* slot) {
	DtorSlot2* obj = *(DtorSlot2**)slot;
	if (obj != 0) {
		obj->destroy(1);
	}
	*(void**)slot = 0;
}

// fn_803D5710 - actor@lbl_804B0288: destructor (0x1D0). Standard
// DESTROYBASE template: manager-notify (getTotalFreeSize__7JKRHeapFv on
// lbl_80529DEC->0x8) first, then owned-sub-object teardown: singles at
// 0x4/0x8/0x14, a single+2-element-array pair (0x18 then 0x1c-0x20), a
// single (0x24), then another single+8-element-array pair (0x28 then
// 0x2c-0x48), finished by the standard "> 0 means also deallocate"
// conditional chain to __dl__FPv.
extern "C" void* fn_803D5710(void* this_, s16 how) {
	if (this_ != 0) {
		*(void**)this_ = lbl_804B0288;
		void* mgr = *(void**)(lbl_80529DEC + 0x8);
		getTotalFreeSize__7JKRHeapFv(mgr);

		char* t = (char*)this_;

		DispatchSlot2(t + 0x4);
		DispatchSlot2(t + 0x8);
		DispatchSlot2(t + 0x14);

		DispatchSlot2(t + 0x18);
		for (s32 i = 0; i < 2; i++) {
			DispatchSlot2(t + 0x1c + i * 4);
		}

		DispatchSlot2(t + 0x24);

		DispatchSlot2(t + 0x28);
		for (s32 j = 0; j < 8; j++) {
			DispatchSlot2(t + 0x2c + j * 4);
		}

		lbl_8053ADB8 = 0;
		if (how > 0) {
			__dl__FPv(this_);
		}
	}
	return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
