#pragma optimization_level 3
// TU 0x80390818-0x80391ce4.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- small accessors (0x80390818-0x80390EBC) ----
struct Tu80390818_Sub14 {
    u8 pad0[0x2D0];
    s32 m2D0;
};

struct Tu80390818_Sub {
    u8 pad0[0x14];
    Tu80390818_Sub14* m14;
    u8 pad18[0x148 - 0x18];
    s32 m148;
    u8 pad14C[0x150 - 0x14C];
    u32 m150;
    u8 pad154[0x174 - 0x154];
    s32 m174;
    u8 pad178[0x180 - 0x178];
    s32 m180[4];
    u8 pad190[0x19E - 0x190];
    u8 m19E;
    u8 m19F;
    u8 pad1A0[0x3AF - 0x1A0];
    u8 m3AF;
    u8 pad3B0[2];
    u8 m3B2[1];
};

struct Tu80390818 {
    u8 pad0[0x8];
    s32 m08;
    u8* m0C;
    s32 m10;
    s32 m14;
    s32 m18;
    u8 pad1C[0x20 - 0x1C];
    s32 m20;
    u8 m24;
    u8 m25;
    u16 m26;
    u16 m28;
    u8 pad2A[0x30 - 0x2A];
    s32 m30;
    s32 m34;
    s32 m38;
    u16 m3C;
    u16 m3E;
    u8 m40;
    u8 m41;
    u8 m42;
    u8 m43;
    u8 m44;
    u8 pad45[0x48 - 0x45];
    Tu80390818_Sub* m48;
    Tu80390818_Sub* m4C;
    f32 m50;
    f32 m54;
    f32 m58;
};

struct Tu80390818_Mgr {
    u8 pad0[0xED];
    u8 mED;
    u8 padEE[0x110 - 0xEE];
    s32 m110;
};
extern Tu80390818_Mgr* lbl_8053AD78;

extern "C" s32 fn_80390818(Tu80390818* t) {
    s32 r = 0;
    switch (t->m24) {
    case 1: case 2: case 3: case 4: case 5:
        r = 2;
        break;
    case 6: case 7: case 8:
        r = 1;
        break;
    }
    return r;
}

extern "C" s32 fn_80390850(Tu80390818* t) {
    s32 r = -1;
    switch (t->m24) {
    case 1: case 2: case 3: case 4: case 5:
        r = t->m4C->m174;
        break;
    case 6: case 7: case 8:
        r = t->m48->m174;
        break;
    }
    return r;
}

extern "C" u8 fn_80390894(Tu80390818* t, s32 i) {
    if (t->m24 == 5) {
        return t->m4C->m3B2[i];
    }
    if (t->m24 == 8) {
        return t->m48->m3B2[i];
    }
    return 0;
}

struct Tu80390818_Game {
    u8 pad0[0x4C];
    s32 mode;
    u8 pad50[0x7F - 0x50];
    u8 b7F;
};
extern Tu80390818_Game* lbl_8053AAF8;

static inline bool Tu80390818_inModeA(Tu80390818_Game* g) {
    bool r = false;
    if (g->mode == 7 || g->mode == 8 || g->mode == 9 || g->mode == 0x16 || g->mode == 10 || g->mode == 11) {
        r = true;
    }
    return r;
}
static inline bool Tu80390818_inModeB(Tu80390818_Game* g) {
    bool r = false;
    if (g->mode == 7 || g->mode == 8 || g->mode == 9 || g->mode == 0x16 || g->mode == 10 || g->mode == 11 || g->mode == 12) {
        r = true;
    }
    return r;
}
static inline bool Tu80390818_isShared() {
    Tu80390818_Game* g = lbl_8053AAF8;
    if (g->b7F) {
        return Tu80390818_inModeA(g) != 0;
    } else {
        return Tu80390818_inModeB(g) != 0;
    }
}

extern "C" void* fn_801F856C(void);
extern "C" u8* fn_801F666C(void* mgr, s32 id);
extern "C" u8 fn_802EB27C(u8* actor);

extern "C" s32 fn_803908D0(Tu80390818* t) {
    s32 id;
    for (s32 i = 0; i < 4; i++) {
        id = t->m48->m180[i];
        if (id >= 0) {
            if (Tu80390818_isShared() == true) {
                u8* a = fn_801F666C(fn_801F856C(), id);
                if (a != 0 && *(u32*)(a + 0x1A0) == 'TKRA' && !fn_802EB27C(a)) {
                    return 0;
                }
            }
            t->m48->m180[i] = -1;
        }
        id = t->m4C->m180[i];
        if (id >= 0) {
            if (Tu80390818_isShared() == true) {
                u8* a = fn_801F666C(fn_801F856C(), id);
                if (a != 0 && *(u32*)(a + 0x1A0) == 'TKRA' && !fn_802EB27C(a)) {
                    return 0;
                }
            }
            t->m4C->m180[i] = -1;
        }
    }
    return 1;
}

extern "C" void fn_80390B64(Tu80390818* t) {
    if (t->m24 == 5) {
        Tu80390818_Sub* p = t->m4C;
        p->m19E = 0xFF;
        p->m19F = 1;
    } else if (t->m24 == 8) {
        Tu80390818_Sub* p = t->m48;
        p->m19E = 0xFF;
        p->m19F = 1;
    }
}

extern "C" u8 fn_80390BA8(Tu80390818* t) {
    if (t->m24 == 5) {
        return t->m4C->m19E;
    }
    if (t->m24 == 8) {
        return t->m48->m19E;
    }
    return 0xFF;
}

extern "C" s32 fn_80390BDC(Tu80390818* t) {
    if (t->m24 == 5) {
        Tu80390818_Sub* p = t->m4C;
        if (p->m150 != 0) {
            p->m150--;
        }
        return p->m150;
    }
    if (t->m24 == 8) {
        Tu80390818_Sub* p = t->m48;
        if (p->m150 != 0) {
            p->m150--;
        }
        return p->m150;
    }
    return 0;
}

extern "C" s32 fn_80390C38(Tu80390818* t) {
    if (t->m24 == 5) {
        return t->m4C->m148;
    }
    if (t->m24 == 8) {
        return t->m48->m148;
    }
    return -1;
}

static inline u16 Tu80390818_read16(u8* p) {
    u8 hi = p[0];
    u8 lo = p[1];
    return (u16)((hi << 8) | lo);
}

extern "C" u16 fn_80390C6C(Tu80390818* t) {
    if (t->m24 == 3) {
        switch (t->m41) {
        case 0:
            t->m26 = Tu80390818_read16(t->m0C);
            t->m41 = 1;
            t->m10 = 2;
            t->m14 = 0;
            t->m43++;
            t->m0C++;
            t->m0C++;
            break;
        case 1:
            if (t->m28 & 1) {
                t->m26 = 0xFFFC;
                t->m41 = 2;
                t->m43++;
                break;
            }
            t->m41 = 2;
        case 2:
            t->m26 = Tu80390818_read16(t->m0C);
            if (t->m26 == 0xFFF0) {
                t->m10 += 2;
                t->m14++;
                t->m0C++;
                t->m0C++;
            } else if (t->m26 == 0xFFFE) {
                t->m41 = 3;
                t->m40 = t->m4C->m3AF;
            } else {
                t->m10 += 2;
                t->m0C++;
                t->m0C++;
            }
            if (t->m10 >= t->m4C->m14->m2D0) {
                t->m41 = 3;
                t->m40 = t->m4C->m3AF;
            }
            t->m43++;
            break;
        case 3:
            t->m24 = 4;
            t->m26 = 0xFFFE;
            t->m41 = 0;
            t->m43++;
            break;
        }
    } else {
        t->m26 = 0;
    }
    return t->m26;
}

extern "C" s32 fn_80390E40(Tu80390818* t, s32 v, u8 force) {
    if (t->m24 == 0 || force) {
        t->m20 = v;
        return 1;
    }
    return 0;
}

extern "C" void fn_80394690(Tu80390818_Sub*);
extern "C" void fn_8039499C(Tu80390818_Sub*, u8);

extern "C" void fn_80390E68(Tu80390818* t) {
    u8 b = 0;
    if ((t->m28 >> 1) & 1) {
        if (t->m28 & 0x40) {
            fn_80394690(t->m48);
        } else {
            if (t->m28 & 0x2000) {
                b = 1;
            }
            fn_8039499C(t->m48, b);
        }
    }
}

extern "C" void fn_803913E0(Tu80390818* t) {
    t->m08 = 0;
    t->m25 = 0;
    t->m26 = 0;
    t->m41 = 0;
    t->m40 = 1;
    t->m10 = 0;
    t->m14 = 0;
    t->m42 = 0;
    t->m43 = 0;
    for (s32 i = 0; i < 4; i++) {
        s32 id = t->m48->m180[i];
        if (id >= 0) {
            if (Tu80390818_isShared() == true) {
                u8* a = fn_801F666C(fn_801F856C(), id);
                if (a != 0 && *(u32*)(a + 0x1A0) == 'TKRA') {
                    fn_802EB27C(a);
                }
            }
            t->m48->m180[i] = -1;
        }
        id = t->m4C->m180[i];
        if (id >= 0) {
            if (Tu80390818_isShared() == true) {
                u8* a = fn_801F666C(fn_801F856C(), id);
                if (a != 0 && *(u32*)(a + 0x1A0) == 'TKRA') {
                    fn_802EB27C(a);
                }
            }
            t->m4C->m180[i] = -1;
        }
    }
}

extern "C" void fn_80391678(Tu80390818* t) {
    t->m08 = 0;
    t->m20 = 0;
    t->m24 = 0;
    t->m25 = t->m24;
    t->m26 = 0;
    t->m41 = 0;
    t->m40 = 1;
    t->m28 = 0;
    t->m10 = 0;
    t->m14 = 0;
    t->m42 = 0;
    t->m43 = 0;
    t->m3C = 0;
    t->m3E = 0;
    t->m34 = 0;
    t->m38 = 0;
    t->m30 = -1;
    t->m50 = 0.0f;
    t->m54 = 0.0f;
    t->m58 = 0.0f;
    t->m44 = 0;
    if (lbl_8053AD78->mED != 0 && t->m18 == lbl_8053AD78->m110) {
        lbl_8053AD78->mED = 0;
    }
    for (s32 i = 0; i < 4; i++) {
        s32 id = t->m48->m180[i];
        if (id >= 0) {
            if (Tu80390818_isShared() == true) {
                u8* a = fn_801F666C(fn_801F856C(), id);
                if (a != 0 && *(u32*)(a + 0x1A0) == 'TKRA') {
                    fn_802EB27C(a);
                }
            }
            t->m48->m180[i] = -1;
        }
        id = t->m4C->m180[i];
        if (id >= 0) {
            if (Tu80390818_isShared() == true) {
                u8* a = fn_801F666C(fn_801F856C(), id);
                if (a != 0 && *(u32*)(a + 0x1A0) == 'TKRA') {
                    fn_802EB27C(a);
                }
            }
            t->m4C->m180[i] = -1;
        }
    }
}

// ---- from src/Game/Dtor_lbl804AF490_80391974.cpp ----
// fn_80391974 - actor@lbl_804AF490: destructor. Reinstalls the base
// vtable, calls own virtual slot 0 (byte offset 0x8) on this->0x48 and
// this->0x4c if set, clearing each afterward, then conditionally
// forwards to __dl__FPv. See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF490[];

struct Slot0 {
    virtual void slot0(s32 arg);
};

extern "C" void* fn_80391974(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF490;
        void* p1 = *(void**)((char*)this_ + 0x48);
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        *(void**)((char*)this_ + 0x48) = 0;
        void* p2 = *(void**)((char*)this_ + 0x4c);
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        *(void**)((char*)this_ + 0x4c) = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_80391A1C_ctor.cpp ----
class ArchiveHolder_803973E8 {
public:
    ArchiveHolder_803973E8(void* owner, s32 val, const char* name);
private:
    unsigned char pad[0x3c4];
};

extern void* lbl_804AF490[];
extern char lbl_804756D8[];
extern char lbl_804756F4[];

extern "C" void* fn_80391A1C(void* this_, s32 param2) {
    char* p = (char*)this_;
    *(void**)p = lbl_804AF490;
    *(s32*)(p + 0x18) = param2;
    ArchiveHolder_803973E8* obj1 = new ArchiveHolder_803973E8(this_, *(s32*)(p + 0x18), lbl_804756D8);
    *(ArchiveHolder_803973E8**)(p + 0x48) = obj1;
    ArchiveHolder_803973E8* obj2 = new ArchiveHolder_803973E8(this_, *(s32*)(p + 0x18), lbl_804756F4);
    *(ArchiveHolder_803973E8**)(p + 0x4c) = obj2;
    *(char*)(p + 0x44) = 0;
    *(s32*)(p + 0x1c) = 1;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
