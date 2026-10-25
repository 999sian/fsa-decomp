// TU 0x8042e964-0x80432638.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"


#include "JSystem/J2D/J2DScreen.h"
#include <string.h>

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
extern "C" f32 lbl_80543B18;
extern "C" f32 lbl_80543B28;
extern "C" f32 lbl_80543B94;
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

struct T80431_Pane {
    u8 pad0[0x20];
    f32 w;
    f32 h;
    f32 sw;
    f32 sh;
    u8 pad30[0x118 - 0x30];
    f32 f118;
};

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

extern "C" s16 lbl_80543AE8[];
extern "C" s16 lbl_80543AF0[];
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
        x = self->screen->search('Twt01')->getBounds()->i.x + lbl_80543B18 * (tb->sw - tb->w);
        tb = (T80431_Pane*)self->screen->search('Twt01');
        y = self->screen->search('Twt01')->getBounds()->i.y + lbl_80543B18 * (tb->sh - tb->h);
        if (flag == 0) {
            T80431_Pane* cur = (T80431_Pane*)self->screen->search('Pwcur01');
            x += lbl_80543B18 * ((*(f32*)((char*)self + 0xbc) - *(f32*)((char*)self + 0xc8)) - (cur->sw - cur->w));
        } else {
            T80431_Pane* cur = (T80431_Pane*)self->screen->search('Pwcur01');
            x += lbl_80543B18 * ((*(f32*)((char*)self + 0xc0) - *(f32*)((char*)self + 0xc8)) - (cur->sw - cur->w)) + (*(f32*)((char*)self + 0xd0) - *(f32*)((char*)self + 0xcc));
        }
        T80431_Pane* pcur = (T80431_Pane*)self->screen->search('Pwcur01');
        f32 hdiff = pcur->sh - pcur->h;
        f32 fa = ((T80431_Pane*)self->screen->search('Twt01'))->f118;
        tb = (T80431_Pane*)self->screen->search('Twt01');
        y += lbl_80543B18 * (fa - hdiff) + (((f32*)((char*)self + 0xd8))[flag] - lbl_80543B18 * (f32)*(s32*)((char*)self + 0xe4) - lbl_80543B28) * tb->f118;
        self->screen->search('Pwcur01')->move(x, y);
        self->screen->search('Pwcur02')->move(x, y);
        T80431_Pane* pa = (T80431_Pane*)self->screen->search('Pwcur01');
        f32 hh = pa->sh - pa->h;
        T80431_Pane* pb = (T80431_Pane*)self->screen->search('Pwcur01');
        self->screen->search('Pwcur01')->rotate(lbl_80543B18 * (pb->sw - pb->w), lbl_80543B18 * hh, J2DROTATE_Z, (f32)lbl_80543AE8[self->feb]);
        T80431_Pane* pa2 = (T80431_Pane*)self->screen->search('Pwcur02');
        f32 hh2 = pa2->sh - pa2->h;
        T80431_Pane* pb2 = (T80431_Pane*)self->screen->search('Pwcur02');
        self->screen->search('Pwcur02')->rotate(lbl_80543B18 * (pb2->sw - pb2->w), lbl_80543B18 * hh2, J2DROTATE_Z, (f32)lbl_80543AF0[self->feb]);
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

struct T80431_Res {
    void* vt;
    u8* data;
};

struct T80431_Helper {
    void* vt;
    J2DScreen* screen;
    void* objA;
    void* objB;
    s16 timer;
    u8 flag;
};

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
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
