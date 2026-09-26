#pragma optimization_level 3
// TU 0x8037e54c-0x8038de74.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/Dtor_lbl804AF070_8038D90C.cpp ----
// fn_8038D90C - actor@lbl_804AF070: destructor. Reinstalls the base
// vtable; if registered at global lbl_8053AD78, releases 4 sub-
// objects (12-byte array elements at this->0x114+4*i) and one more
// sub-object at this->0x154, then this->0x4 - all via own virtual
// slot 0 (byte offset 0x8) - then clears lbl_8053AD78. Finally
// conditionally forwards to __dl__FPv. See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF070[];
struct InfEntry {
    u32 offset;
    u16 id;
    u16 pad;
};
struct Inf1 {
    u32 magic;
    u32 size;
    u16 count;
    u16 entSize;
    u8 pad[4];
    InfEntry entries[1];
};
struct MsgData {
    u8 pad[0x20];
    Inf1 inf;
};

struct DrawObj {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void draw(f32 x, f32 y);
};

struct Mgr {
    u8 pad0[0x4];
    DrawObj* p4;    // 0x04
    MsgData* p8;    // 0x08 message data
    u8 padc[0x4c - 0xc];
    s32 w4c[4];     // 0x4c
    f32 f5c;        // 0x5c
    f32 f60;
    f32 f64;
    f32 f68;
    u8 pad6c[0x70 - 0x6c];
    f32 f70;
    f32 f74;
    u8 pad78[0xe4 - 0x78];
    u8 be4;         // 0xe4
    u8 pade5;
    u8 be6;         // 0xe6
    u8 pade7;
    u8 be8;         // 0xe8
    u8 pade9[0xf0 - 0xe9];
    u16 hf0[4];     // 0xf0
    s32 wf8;        // 0xf8
    s32 wfc[4];     // 0xfc
    u8 pad10c[0x114 - 0x10c];
    void* sub[4];   // 0x114
};
extern Mgr* lbl_8053AD78;

struct GameState {
    u8 pad0[0x4c];
    s32 mode;       // 0x4c
    u8 pad50[0x7f - 0x50];
    u8 b7f;         // 0x7f
    u8 pad80[2];
    u8 b82;         // 0x82
};
extern GameState* lbl_8053AAF8;
extern "C" s32 fn_8022F340(s32 p);
extern "C" void fn_80390850(void* p);
extern u8 lbl_80529DEC[];


static inline bool inModeA(GameState* g) {
    bool r = false;
    if (g->mode == 7 || g->mode == 8 || g->mode == 9 || g->mode == 0x16 || g->mode == 10 || g->mode == 11) {
        r = true;
    }
    return r;
}
static inline bool inModeB(GameState* g) {
    bool r = false;
    if (g->mode == 7 || g->mode == 8 || g->mode == 9 || g->mode == 0x16 || g->mode == 10 || g->mode == 11 || g->mode == 12) {
        r = true;
    }
    return r;
}
static inline bool isShared() {
    GameState* g = lbl_8053AAF8;
    if (g->b7f) {
        return inModeA(g) != 0;
    } else {
        return inModeB(g) != 0;
    }
}
static inline s32 resolvePlayer(s32 p) {
    if (isShared()) {
        s32 r = fn_8022F340(p);
        if (r >= 0 && r < 4) {
            return r;
        }
    }
    return p;
}


extern "C" s32 fn_8037E54C(s32 p) {
    if (p >= 0 && p < 4) {
        s32 i = resolvePlayer(p);
        if (*(s32*)(lbl_80529DEC + 0x118) >= 8 && *(s32*)(lbl_80529DEC + 0x11c) == 0) {
            return lbl_8053AD78->w4c[i];
        }
    }
    return 0;
}

extern "C" u8 fn_8037E694(s32 p) {
    s32 i = resolvePlayer(p);
    return *((u8*)lbl_8053AD78->sub[i] + 0x44);
}

extern "C" bool fn_8037E7AC(s32 p) {
    s32 i = resolvePlayer(p);
    return (lbl_8053AD78->be8 & (u8)(1 << i)) != 0;
}

extern "C" void fn_8037E8D4(s32 p) {
    s32 i = resolvePlayer(p);
    lbl_8053AD78->be8 |= (u8)(1 << i);
}

extern "C" void fn_8037E9F4(s32 p) {
    s32 i = resolvePlayer(p);
    fn_80390850(lbl_8053AD78->sub[i]);
}

extern "C" void fn_8037EB0C(f32* a, f32* b, f32* c, f32* d, u8* e) {
    *a = lbl_8053AD78->f5c;
    *b = lbl_8053AD78->f64;
    *c = lbl_8053AD78->f60;
    *d = lbl_8053AD78->f68;
    *e = lbl_8053AD78->be6;
}

extern "C" s32 fn_8037EE8C(s32 p) {
    s32 i = resolvePlayer(p);
    s32 r = *(s32*)((u8*)lbl_8053AD78->sub[i] + 0x2c) + 1;
    if (r > 3) {
        r = 0;
    }
    return r;
}

extern "C" s32 fn_8037EFB4(s32 p) {
    s32 i = resolvePlayer(p);
    return *(s32*)((u8*)lbl_8053AD78->sub[i] + 0x2c);
}

extern "C" void fn_80390C6C(void* p);
extern "C" void fn_8037F0CC(s32 p) {
    s32 i = resolvePlayer(p);
    fn_80390C6C(lbl_8053AD78->sub[i]);
}

extern "C" u8 fn_8037F1E4(s32 p) {
    s32 i = resolvePlayer(p);
    return *((u8*)lbl_8053AD78->sub[i] + 0x24);
}


struct Slot0 {
    virtual void slot0(s32 arg);
};

static void ReleaseIfSet(void* p, s32 arg) {
    if (p != 0) {
        ((Slot0*)p)->slot0(arg);
    }
}

extern "C" void* fn_8038D90C(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF070;
        if (lbl_8053AD78 != 0) {
            for (s32 i = 0; i < 4; i++) {
                void* p = *(void**)((char*)this_ + 0x114 + 4 * i);
                if (p != 0) {
                    ReleaseIfSet(p, 1);
                    *(void**)((char*)this_ + 0x114 + 4 * i) = 0;
                }
            }
            void* p154 = *(void**)((char*)this_ + 0x154);
            if (p154 != 0) {
                ((Slot0*)p154)->slot0(1);
            }
            *(void**)((char*)this_ + 0x154) = 0;
            void* p4 = *(void**)((char*)this_ + 0x4);
            if (p4 != 0) {
                ((Slot0*)p4)->slot0(1);
            }
            *(void**)((char*)this_ + 0x4) = 0;
            lbl_8053AD78 = 0;
        }
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_8038DBF0_dtor.cpp ----
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF32C[];

extern "C" void* fn_8038DBF0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF32C;
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8038A984(s32 a, s32 b, s32 c, u32 id, s32 e, s32 f);
extern "C" void fn_8038C60C(s32 a, s32 b, s32 c, u32 id, s32 e, s32 f) {
    u32 i;
    Inf1* inf = &lbl_8053AD78->p8->inf;
    for (i = 0; i < inf->count; i++) {
        if (inf->entries[i].id == id) {
            id = i;
            break;
        }
    }
    if (i >= inf->count) {
        id = 0x12b;
    }
    fn_8038A984(a, b, c, id, e, f);
}

extern "C" void fn_80391678(void* p);
extern "C" void fn_80390E68(void* p);
extern "C" void fn_8038D454() {
    for (s32 i = 0; i < 4; i++) {
        fn_80391678(lbl_8053AD78->sub[i]);
    }
}

static inline bool testBit(u8 bits, s32 n) {
    return (bits & (u8)(1 << n)) != 0;
}

extern "C" void fn_8038D4A8() {
    for (s32 i = 0; i < 4; i++) {
        Mgr* m = lbl_8053AD78;
        s32 v = m->wfc[i];
        if (v != -1 && testBit(lbl_8053AAF8->b82, v) == true) {
            fn_80390E68(m->sub[v]);
        }
    }
    if (lbl_8053AD78->be4) {
        lbl_8053AD78->p4->draw(lbl_8053AD78->f70, lbl_8053AD78->f74);
    }
}

extern "C" void fn_8038D870() {
    for (s32 i = 0; i < 4; i++) {
        fn_80391678(lbl_8053AD78->sub[i]);
        *(MsgData**)((u8*)lbl_8053AD78->sub[i] + 4) = lbl_8053AD78->p8;
        lbl_8053AD78->wfc[i] = -1;
        lbl_8053AD78->hf0[i] = 0;
    }
    lbl_8053AD78->wf8 = 0;
    lbl_8053AD78->be4 = 0;
}

extern "C" u16 fn_803846A4(s32 i) {
    return lbl_8053AD78->p8->inf.entries[i].id;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
