#pragma optimization_level 3
// TU 0x8037e54c-0x8038de74.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JUtility/JUTFont.h"
#include "JSystem/JUtility/TColor.h"
#include "JSystem/JUtility/JUTVideo.h"

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


extern f32 lbl_805430C8;
class J2DTextBox {
public:
    char* getStringPtr() const;
    struct TFontSize {
        TFontSize(f32 x_, f32 y_) { x = x_; y = y_; }
        f32 x, y;
    };
    void setFontSize(TFontSize size) {
        f32 sx = size.x;
        f32 sy = size.y;
        f32 fx = (sx > lbl_805430C8) ? sx : lbl_805430C8;
        mFontSizeX = fx;
        f32 fy = (sy > lbl_805430C8) ? sy : lbl_805430C8;
        mFontSizeY = fy;
    }
    void setFontSize(f32 x, f32 y) {
        setFontSize(TFontSize(x, y));
    }
    void setFontColor(JUtility::TColor a, JUtility::TColor b) {
        mCharColor = a;
        mGradColor = b;
    }
    J2DTextBox(const char*, const char*, s16);
    u8 pad[0x104];
    JUtility::TColor mCharColor;  // 0x104
    JUtility::TColor mGradColor;  // 0x108
    u8 pad10c[0x11c - 0x10c];
    f32 mFontSizeX;               // 0x11c
    f32 mFontSizeY;               // 0x120
    u8 pad124[0x138 - 0x124];
};

struct Mgr {
    u8 pad0[0x4];
    DrawObj* p4;    // 0x04
    MsgData* p8;    // 0x08 message data
    u8 padc[0x3c - 0xc];
    u32 w3c;        // 0x3c
    s32 w40;
    u32 w44;        // 0x44
    u32 w48;        // 0x48
    s32 w4c[4];     // 0x4c
    f32 f5c;        // 0x5c
    f32 f60;
    f32 f64;
    f32 f68;
    f32 f6c;
    f32 f70;
    f32 f74;
    f32 f78;
    s32 w7c;
    u8 pad80[0xe4 - 0x80];
    u8 be4;         // 0xe4
    u8 be5;
    u8 be6;         // 0xe6
    u8 be7;
    u8 be8;         // 0xe8
    u8 be9;
    u8 bea;
    u8 beb;
    u8 bec;
    u8 bed;
    u8 padee[0xf0 - 0xee];
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
    u8 pad50[0x7e - 0x50];
    u8 b7e;         // 0x7e
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


extern "C" u8 fn_80390818(void* p);
extern "C" bool fn_8037E4BC() {
    for (s32 i = 0; i < 4; i++) {
        if ((lbl_8053AAF8->b82 & (u8)(1 << i)) && fn_80390818(lbl_8053AD78->sub[i]) == 1) {
            return true;
        }
    }
    return false;
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

extern "C" u8 fn_8038A984(s32 a, s32 b, s32 c, u32 id, s32 e, u16 f);
extern "C" u32 fn_803846BC(u32 id) {
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
    return id;
}

extern "C" u8 fn_8038C60C(s32 a, s32 b, s32 c, u32 id, s32 e, u16 f) {
    u32 i;
    u32 count;
    Inf1* inf = &lbl_8053AD78->p8->inf;
    i = 0;
    count = inf->count;
    for (; i < count; i++) {
        if (inf->entries[i].id == id) {
            id = i;
            break;
        }
    }
    if (i >= count) {
        id = 0x12b;
    }
    return fn_8038A984(a, b, c, id, e, f);
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
        s32 v = lbl_8053AD78->wfc[i];
        if (v != -1 && testBit(lbl_8053AAF8->b82, v) == true) {
            fn_80390E68(lbl_8053AD78->sub[v]);
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



extern "C" void fn_8038938C(s32 p, s32 v) {
    s32 i = resolvePlayer(p);
    if (v > 9999) {
        v = 9999;
    }
    *(s16*)((u8*)lbl_8053AD78->sub[i] + 0x3e) = v;
}


extern "C" s8* fn_80383E2C(s32 idx, s8* out) {
    Inf1* inf = &lbl_8053AD78->p8->inf;
    s8* p = (s8*)inf + inf->size + inf->entries[idx].offset + 8;
    *out = 0;
    if (p[0] == 0x1a && p[2] == 2) {
        switch (p[4]) {
        case 7: case 16: case 23: case 24: case 29: case 32:
        case 33: case 35: case 42: case 44: case 48: case 51:
            *out = p[4];
            return p;
        }
    }
    return 0;
}


extern "C" void fn_8038911C(s32 p, s32 v) {
    s32 i = resolvePlayer(p);
    if (v > 99999) {
        v = 99999;
    }
    *(s32*)((u8*)lbl_8053AD78->sub[i] + 0x38) = v;
}

extern "C" void fn_80389254(s32 p, s32 v) {
    s32 i = resolvePlayer(p);
    if (v > 99999) {
        v = 99999;
    }
    *(s32*)((u8*)lbl_8053AD78->sub[i] + 0x34) = v;
}

extern "C" void fn_803894BC(s32 p, s32 v) {
    s32 i = resolvePlayer(p);
    if (v > 9) {
        v = 9;
    }
    *(s16*)((u8*)lbl_8053AD78->sub[i] + 0x3c) = v;
}


struct Vec2f { f32 x, y, z; };
extern f32 lbl_805430C4;
extern f32 lbl_805430BC;
extern u8 lbl_8050DB0C[];
extern void* lbl_8053AED0;
extern "C" void fn_8043DF8C(void* p, f32 x, f32 y);
struct SubFlags { u16 pad : 9; u16 big : 1; u16 rest : 6; };
#define POS(i) (((Vec2f*)((u8*)lbl_8053AD78 + 0x124))[i])
extern "C" void fn_8037EB4C() {
    for (s32 i = 0; i < 4; i++) {
        u8* sub = (u8*)lbl_8053AD78->sub[i];
        f32 s = lbl_805430C4;
        if ((*(u16*)(sub + 0x28) >> 6) & 1) {
            s = *(f32*)(lbl_8050DB0C + 0x38);
        }
        u8* q = *(u8**)(sub + 0x48);
        f32 w = s * *(f32*)(q + 0xb8);
        f32 h = s * *(f32*)(q + 0xbc);
        if (sub[0x24]) {
            f32 hh = lbl_805430BC * h;
            f32 hw = lbl_805430BC * w;
            fn_8043DF8C(lbl_8053AED0, POS(i).x - hw, POS(i).y - hh);
            fn_8043DF8C(lbl_8053AED0, POS(i).x - -hw, POS(i).y - hh);
            fn_8043DF8C(lbl_8053AED0, POS(i).x - hw, POS(i).y - -hh);
            fn_8043DF8C(lbl_8053AED0, POS(i).x - -hw, POS(i).y - -hh);
        }
    }
}


extern "C" u8 fn_802308E0(s32 p);
extern "C" u8 fn_8023F264(s32 p);
extern "C" u8 fn_802300EC(s32 p);
extern "C" void fn_80230AD4(s32 p);
extern "C" u8 fn_8037EC98(s32 p, u16 flags) {
    s32 i = resolvePlayer(p);
    if ((flags & 4) || (flags & 2)) {
        return 1;
    }
    if (lbl_8053AAF8->b7e == 1) {
        return fn_802308E0(i);
    }
    s32 list[4];
    s32 n = 0;
    s32 ok = 0;
    s32 j;
    for (j = 0; j < 4; j++) {
        list[j] = -1;
        if (fn_8023F264(j) == 1) {
            list[j] = j;
            n++;
        }
    }
    for (j = 0; j < 4; j++) {
        if (list[j] >= 0 && fn_802300EC(list[j]) == 1) {
            ok++;
        }
    }
    if (n != ok) {
        return 0;
    }
    for (j = 0; j < 4; j++) {
        if (list[j] >= 0) {
            fn_80230AD4(list[j]);
        }
    }
    return 1;
}


extern "C" u8 fn_803865B8(s32 p);
extern "C" u8 fn_80385960(s32 p);
extern "C" u8 fn_80384C58(s32 p, s32 q);
static inline u8 isActive(s32 p) {
    s32 i = resolvePlayer(p);
    return *((u8*)lbl_8053AD78->sub[i] + 0x24);
}

extern "C" u8 fn_80388CAC(s32 p, s32 q) {
    s32 i = resolvePlayer(p);
    if (!isActive(i)) {
        return 1;
    }
    if (fn_803865B8(p)) {
        return fn_80384C58(p, q);
    }
    return 0;
}

extern "C" u8 fn_80388EEC(s32 p) {
    s32 i = resolvePlayer(p);
    if (!isActive(i)) {
        return 1;
    }
    if (fn_803865B8(p)) {
        return fn_80385960(p);
    }
    return 0;
}


extern f32 lbl_805430D0;
extern "C" f32 fn_803832BC(char* out, u32 id, s32 num, char* out2, char* out3);
extern "C" u8 fn_8037F2FC(u32 id, s32 lines, u8 flag, JUtility::TColor* color, f32 x, f32 y, f32 w, f32 h) {
    if (!lbl_8053AD78->be4) {
        if (lbl_8053AD78->w3c != id) {
            lbl_8053AD78->w3c = id;
            char* str = ((J2DTextBox*)lbl_8053AD78->p4)->getStringPtr();
            lbl_8053AD78->f6c = fn_803832BC(str, lbl_8053AD78->w3c, 0, 0, 0);
        }
        f32 scale = w / lbl_805430D0;
        f32 len = lbl_8053AD78->f6c * scale;
        f32 total = len + (s32)JUTVideo::getManager()->getFbWidth();
        ((J2DTextBox*)lbl_8053AD78->p4)->setFontSize(w, h);
        ((J2DTextBox*)lbl_8053AD78->p4)->setFontColor(*color, *color);
        lbl_8053AD78->w7c = lines;
        if (lbl_8053AD78->w7c == 0) {
            lbl_8053AD78->f70 = x - lbl_8053AD78->f6c * scale * lbl_805430BC;
            lbl_8053AD78->f78 = lbl_805430C8;
        } else {
            lbl_8053AD78->f70 = (s32)JUTVideo::getManager()->getFbWidth();
            lbl_8053AD78->f78 = total / lbl_8053AD78->w7c;
        }
        lbl_8053AD78->f74 = y - h * lbl_805430BC;
        lbl_8053AD78->be5 = flag;
        lbl_8053AD78->be4 = 1;
        return 1;
    }
    return 0;
}


class ResLoader {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* getRes(u32 type, const char* name);
};
struct GameStateRes {
    u8 pad[0xa8];
    ResLoader* loader;
};
class MsgSub {
public:
    MsgSub(s32 idx);
    u8 pad[0x5c];
};
class MsgMgr {
public:
    MsgMgr();
    virtual ~MsgMgr();
    J2DTextBox* mTextBox;               // 0x04
    void* mMsgData;                     // 0x08
    JGeometry::TVec3<f32> m0c[4];       // 0x0c
    s32 m3c;                            // 0x3c
    s32 m40;                            // 0x40
    s32 m44;                            // 0x44
    s32 m48;                            // 0x48
    s32 m4c[4];                         // 0x4c
    f32 m5c, m60, m64, m68, m6c, m70, m74, m78; // 0x5c
    s32 m7c;                            // 0x7c
    char mBuf[100];                     // 0x80
    u8 me4, me5, me6, me7, me8, me9, mea, meb, mec, med, mee; // 0xe4
    u8 padef[0x10c - 0xef];
    s32 m10c;                           // 0x10c
    s32 m110;                           // 0x110
    MsgSub* mSub[4];                    // 0x114
    JGeometry::TVec3<f32> m124[4];      // 0x124
    JUTResFont* mFont;                  // 0x154
};

extern "C" char lbl_804755B0[];
extern "C" char lbl_804755C4[];
MsgMgr::MsgMgr() {
    lbl_8053AD78 = (Mgr*)this;
    ResFONT* res = (ResFONT*)((GameStateRes*)lbl_8053AAF8)->loader->getRes(0x3f3f3f3f, lbl_804755B0);
    mFont = new JUTResFont(res, 0);
    mMsgData = ((GameStateRes*)lbl_8053AAF8)->loader->getRes(0x3f3f3f3f, lbl_804755C4);
    for (s32 i = 0; i < 4; i++) {
        mSub[i] = new MsgSub(i);
        m0c[i].set(0.0f, 0.0f, 0.0f);
        m4c[i] = 0;
    }
    mec = 0;
    mBuf[0] = 0;
    m40 = -1;
    m3c = -1;
    m7c = 0;
    me5 = 0;
    m6c = m70 = m74 = m78 = 0.0f;
    me4 = 0;
    m5c = m60 = m64 = m68 = 0.0f;
    me6 = 0;
    me7 = 0;
    me8 = 0;
    m44 = 0;
    me9 = 0;
    m48 = 0;
    mea = 0;
    meb = 0;
    m10c = 0;
    med = 0;
    m110 = 0;
    mee = 0;
    mTextBox = new J2DTextBox(lbl_804755B0, mBuf, 100);
}


extern "C" void fn_80390EBC(void* p);
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" void* fn_80309D6C(void* p, s32 id, s32 mask);
extern void* lbl_8053AD30;
extern "C" void* fn_802D6A9C();
extern "C" u8 fn_802D800C(void* p, u8 id);
extern "C" void fn_802D8050(void* p, u8 id, s32 on, s32 v);
extern "C" s32 fn_80138A30(void* p);
extern u8 lbl_8053ACD8;
extern "C" void fn_8038D570() {
    s32 i;
    lbl_8053AD78->be7 = 0;
    for (i = 0; i < 4; i++) {
        if (testBit(lbl_8053AAF8->b82, i) == true) {
            *(s32*)((u8*)lbl_8053AD78->sub[i] + 0x18) = i;
            fn_80390EBC(lbl_8053AD78->sub[i]);
        }
    }
    if (lbl_8053AD78->be4) {
        if (lbl_8053AD78->w7c == 0) {
            for (i = 0; i < 4; i++) {
                if ((lbl_8053AD78->be5 & (1 << i)) && fn_80309D6C(lbl_8053AD30, fn_8030AAF4(i), 0x100)) {
                    lbl_8053AD78->be4 = 0;
                }
            }
        } else {
            lbl_8053AD78->w7c--;
            lbl_8053AD78->f70 -= lbl_8053AD78->f78;
            if (lbl_8053AD78->w7c == 0) {
                lbl_8053AD78->be4 = 0;
                for (i = 0; i < 4; i++) {
                    if ((lbl_8053AD78->be5 & (1 << i)) && fn_80309D6C(lbl_8053AD30, fn_8030AAF4(i), 0x100)) {
                        lbl_8053AD78->be4 = 0;
                    }
                }
            }
        }
    }
    if (lbl_8053AD78->be9) {
        if (lbl_8053AD78->be9 == 1 && lbl_8053AD78->w44 < 360000) {
            lbl_8053AD78->w44++;
        }
        Mgr* m = lbl_8053AD78;
        s32 t = m->w44;
        s32 h = t / 3600;
        s32 mn = (t / 60) % 60;
        if (mn == 0) {
            mn = 1;
        }
        if (mn + h * 60 > m->w48) {
            if (m->beb) {
                if (!fn_802D800C(fn_802D6A9C(), m->bea)) {
                    u8 id = lbl_8053AD78->bea;
                    fn_802D8050(fn_802D6A9C(), id, 1, 0xff);
                }
            } else {
                if (fn_802D800C(fn_802D6A9C(), m->bea) == 1) {
                    u8 id = lbl_8053AD78->bea;
                    fn_802D8050(fn_802D6A9C(), id, 0, 0xff);
                }
            }
        }
    }
    if (lbl_8053AD78->bed) {
        for (i = 0; i < fn_80138A30(lbl_8053AAF8); i++) {
            (&lbl_8053ACD8)[i] = 1;
        }
    }
    lbl_8053AD78->be8 = 0;
}


extern "C" u8 fn_8022FA80(s32 p);
extern "C" u8 fn_80230188(s32 p);
extern "C" u8 fn_8022E438(s32 p, s32 q);
extern "C" u8 fn_80389964(s32 unused, s32 self, u32 id, u16 flags) {
    u8 st[4];
    for (s32 i = 0; i < 4; i++) {
        st[i] = 0;
        if (i != self && (lbl_8053AAF8->b82 & (u8)(1 << i))) {
            if (!fn_8022FA80(i) && !isActive(i)) {
                if ((flags & 4) || (flags & 2) || id == 0x265) {
                    if (fn_80230188(i)) {
                        st[i] = 1;
                        for (s32 j = 0; j < 4; j++) {
                            if (fn_8022E438(i, j) && !fn_80230188(j)) {
                                st[i] = 0;
                            }
                        }
                    }
                } else {
                    if (fn_802300EC(i)) {
                        st[i] = 1;
                        for (s32 j = 0; j < 4; j++) {
                            if (fn_8022E438(i, j) && !fn_802300EC(j)) {
                                st[i] = 0;
                            }
                        }
                    }
                }
            }
        } else {
            st[i] = 2;
        }
    }
    if (st[0] && st[1] && st[2] && st[3]) {
        return 1;
    }
    return 0;
}


extern "C" void fn_8022FB1C(s32 p, s32 a);
extern "C" s32 fn_8022CAF8(s32 p);
extern "C" s32 fn_8022EA0C(s32 p);
extern "C" void fn_8023061C(s32 p, s32 a);
extern "C" void fn_803895EC(s32 unused, s32 p, s32 a, u8 b, u8 c) {
    s32 orig = p;
    s32 self = resolvePlayer(orig);
    for (p = 0; p < 4; p++) {
        if (isActive(p) == 9) {
            if (c) {
                if (p == self) {
                    fn_8022FB1C(orig, a);
                } else if (fn_8022CAF8(p) == 4) {
                    fn_8022FB1C(fn_8022EA0C(p), a);
                } else {
                    fn_8022FB1C(p, a);
                }
            }
            if (b) {
                fn_8023061C(p, 0);
            }
            *((u8*)lbl_8053AD78->sub[resolvePlayer(p)] + 0x24) = 0;
        }
    }
}


extern "C" u8 fn_80303750(s32 p);
extern "C" void fn_80390E40(void* sub, u32 id, s32 z);
static inline void setActive(s32 p, u8 v) {
    s32 i = resolvePlayer(p);
    *((u8*)lbl_8053AD78->sub[i] + 0x24) = v;
}
extern "C" u8 fn_80389BF0(s32 p, u32 id) {
    s32 i = resolvePlayer(p);
    if (!isActive(i) && !fn_80303750(i)) {
        fn_80390E40(lbl_8053AD78->sub[i], id, 0);
        setActive(i, 1);
        *(u16*)((u8*)lbl_8053AD78->sub[i] + 0x28) |= 0x1000;
        *(u16*)((u8*)lbl_8053AD78->sub[i] + 0x28) |= 0x80;
        *(u16*)((u8*)lbl_8053AD78->sub[i] + 0x28) |= 0x20;
        return 1;
    }
    return 0;
}


extern "C" u8 fn_8022C8EC(s32 p);
extern "C" u8 fn_8038B8A8(s32 unused, s32 p, s32 q, u32 id, u16 flags) {
    if (!isActive(p) && !fn_80303750(p) && fn_8022C8EC(p)) {
        if (flags & 0x91f) {
            fn_80390E40(lbl_8053AD78->sub[p], id, 0);
            setActive(p, 1);
            if (flags & 2) {
                *(u16*)((u8*)lbl_8053AD78->sub[p] + 0x28) |= 0x80;
            } else {
                *(u16*)((u8*)lbl_8053AD78->sub[p] + 0x28) |= 0x1;
            }
            if (flags & 8) {
                *(u16*)((u8*)lbl_8053AD78->sub[p] + 0x28) |= 0x10;
            } else if (flags & 0x10) {
                *(u16*)((u8*)lbl_8053AD78->sub[p] + 0x28) |= 0x20;
            }
            if (flags & 0x100) {
                *(u16*)((u8*)lbl_8053AD78->sub[p] + 0x28) |= 0x100;
            }
            return 1;
        }
        if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(p), 0x100) && fn_8037EC98(q, flags)) {
            fn_80390E40(lbl_8053AD78->sub[p], id, 0);
            setActive(p, 1);
            return 1;
        }
    }
    return 0;
}


struct Vec3Raw { f32 x, y, z; };
extern void* lbl_8053AF80;
extern "C" void fn_80458880(void* p, s32 a, s32 b);
static inline s32 resolved(s32 p) { return resolvePlayer(p); }
#define SUBFLAGS(p) (*(u16*)((u8*)lbl_8053AD78->sub[p] + 0x28))
extern "C" u8 fn_80389F78(s32 unused, s32 p, s32 unused2, u32 id, JGeometry::TVec3<f32>* pos, u16 flags) {
    if (!isActive(p) && (flags & 0x11f)) {
    s32 snd = flags & 0x40;
    if (snd) {
        SUBFLAGS(p) |= 0x40;
    } else if (flags & 0x200) {
        SUBFLAGS(p) |= 0x200;
    } else if (flags & 0x400) {
        SUBFLAGS(p) |= 0x400;
    }
    fn_80390E40(lbl_8053AD78->sub[p], id, 0);
    u8* sub = (u8*)lbl_8053AD78->sub[p];
    JGeometry::TVec3<f32> v(*pos);
    *(JGeometry::TVec3<f32>*)(sub + 0x50) = v;
    *(s32*)(sub + 0x30) = -1;
    setActive(p, 6);
    lbl_8053AD78->wfc[lbl_8053AD78->wf8] = resolvePlayer(p);
    lbl_8053AD78->wf8++;
    if (flags & 2) {
        SUBFLAGS(p) |= 0x80;
    } else {
        SUBFLAGS(p) |= 0x1;
    }
    if (flags & 8) {
        SUBFLAGS(p) |= 0x10;
    } else if (flags & 0x10) {
        SUBFLAGS(p) |= 0x20;
    }
    if (flags & 0x100) {
        SUBFLAGS(p) |= 0x100;
    }
    if (flags & 0x4000) {
        SUBFLAGS(p) |= 0x2000;
    }
    if (!snd) {
        fn_80458880(lbl_8053AF80, 0x28, -1);
    }
    return 1;
    }
    return 0;
}


extern "C" void fn_803913E0(void* sub);
extern "C" u32 fn_80383EB0(s32 i, s32 q);
extern "C" u8 fn_8038470C(s32 p, s32 q) {
    s32 i = resolvePlayer(p);
    fn_803913E0(lbl_8053AD78->sub[i]);
    u32 id = fn_80383EB0(i, q);
    if (isActive(i) == 5) {
        fn_80390E40(lbl_8053AD78->sub[i], id, 1);
        setActive(i, 1);
        return 1;
    }
    if (isActive(i) == 8) {
        fn_80390E40(lbl_8053AD78->sub[i], id, 1);
        setActive(i, 6);
        return 1;
    }
    return 0;
}


extern "C" u8 fn_8022FCF0(s32 q, s32 v);
extern "C" void fn_8022FC54(s32 q, s32 v);
extern "C" u8 fn_8038A42C(s32 unused, s32 p, s32 q, u32 id, s32 val, JGeometry::TVec3<f32>* pos, u16 flags) {
    if (!isActive(p) && (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(p), 0x100) || (flags & 0x19f))) {
        u8 ok = 0;
        if (flags & 0x1000) {
            if (fn_8037EC98(q, flags)) {
                ok = 1;
                SUBFLAGS(p) |= 0x800;
            }
        } else if (fn_8022FCF0(q, val) && fn_8037EC98(q, flags)) {
            fn_8022FC54(q, val);
            ok = 1;
        }
        if (ok) {
            s32 snd = flags & 0x40;
            if (snd) {
                SUBFLAGS(p) |= 0x40;
            } else if (flags & 0x200) {
                SUBFLAGS(p) |= 0x200;
            } else if (flags & 0x400) {
                SUBFLAGS(p) |= 0x400;
            }
            fn_80390E40(lbl_8053AD78->sub[p], id, 0);
            u8* sub = (u8*)lbl_8053AD78->sub[p];
            JGeometry::TVec3<f32> v(*pos);
            *(JGeometry::TVec3<f32>*)(sub + 0x50) = v;
            *(s32*)(sub + 0x30) = val;
            setActive(p, 6);
            lbl_8053AD78->wfc[lbl_8053AD78->wf8] = resolvePlayer(p);
            lbl_8053AD78->wf8++;
            if (flags & 2) {
                SUBFLAGS(p) |= 0x80;
            }
            if (flags & 0x80) {
                SUBFLAGS(p) |= 0x4;
            }
            if (flags & 4) {
                SUBFLAGS(p) |= 0x8;
            }
            if (flags & 0x100) {
                SUBFLAGS(p) |= 0x100;
            }
            if (flags & 0x4000) {
                SUBFLAGS(p) |= 0x2000;
            }
            if (!snd) {
                fn_80458880(lbl_8053AF80, 0x28, -1);
            }
            return 1;
        }
    }
    return 0;
}


extern "C" u8 fn_8038A984(s32 unused, s32 p, s32 q, u32 id, s32 val, u16 flags) {
    if (!isActive(p) && !fn_80303750(p) && fn_8022C8EC(p) &&
        (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(p), 0x100) || (flags & 0x19f))) {
        u8 ok = 0;
        if (flags & 0x1000) {
            if (fn_8037EC98(q, flags)) {
                ok = 1;
                SUBFLAGS(p) |= 0x800;
            }
        } else if (fn_8022FCF0(q, val) && fn_8037EC98(q, flags)) {
            fn_8022FC54(q, val);
            ok = 1;
        }
        if (ok) {
            fn_80390E40(lbl_8053AD78->sub[p], id, 0);
            setActive(p, 1);
            if (flags & 2) {
                SUBFLAGS(p) |= 0x80;
            }
            if (flags & 0x80) {
                SUBFLAGS(p) |= 0x4;
            }
            if (flags & 4) {
                SUBFLAGS(p) |= 0x8;
            }
            if (flags & 0x100) {
                SUBFLAGS(p) |= 0x100;
            }
            return 1;
        }
    }
    return 0;
}


extern "C" f32 fn_8037F580(u8 type, s32 num, char* out, s32* len, f32 scale);
#define PUT_CH(ch) \
    if (mode == 1 && out2) { out2[len] = (ch); } \
    else if (mode == 2 && out3) { out3[len] = (ch); } \
    else { out[len] = (ch); }
static inline JUTFont* msgFont() { return *(JUTFont**)((u8*)lbl_8053AD78 + 0x154); }
extern "C" f32 fn_803832BC(char* out, u32 id, s32 num, char* out2, char* out3) {
    f32 width = lbl_805430C8;
    Inf1* inf = &lbl_8053AD78->p8->inf;
    s8* data = (s8*)inf + inf->size + inf->entries[id].offset + 8;
    s32 pos = 0;
    s32 col = 1;
    u8 mode = 0;
    s32 len = 0;
    s8* p;
    s8 c;
    while ((c = (p = data + pos)[0]) != 0) {
        if (c == '\n') {
            PUT_CH(c);
            col++;
            pos++;
            len++;
        } else if (c == 0x1a) {
            if (p[2] == 2) {
                s8 t = p[4];
                if (t == 0 || t == 10 || t == 0x12 || t == 0x19) {
                    if (mode < 2) {
                        (&lbl_8053AD78->f5c)[mode] = width;
                        (&lbl_8053AD78->f64)[mode] = col - 1;
                        if (mode == 0) {
                            if (out2) {
                                out[len] = 0;
                                len = 0;
                            }
                        } else if (mode == 1 && out3) {
                            out2[len] = 0;
                            len = 0;
                        }
                        mode++;
                    }
                } else if (t == 1 || t == 9 || t == 0x11 || t == 0x1a) {
                    if (mode < 2) {
                        (&lbl_8053AD78->f5c)[mode] = width;
                        (&lbl_8053AD78->f64)[mode] = col - 1;
                        lbl_8053AD78->be6 = mode;
                        if (mode == 0) {
                            if (out2) {
                                out[len] = 0;
                                len = 0;
                            }
                        } else if (mode == 1 && out3) {
                            out2[len] = 0;
                            len = 0;
                        }
                        mode++;
                    }
                }
            } else if (p[2] == 3) {
                s32 ch = num + '0';
                PUT_CH(ch);
                len++;
                JUTFont::TWidth tw;
                msgFont()->getWidthEntry(num, &tw);
                width += (s32)tw.w1;
                width += fn_8037F580(p[5], num, out, &len, lbl_805430C4);
            }
            pos += p[1];
        } else {
            PUT_CH(c);
            len++;
            s32 code = (u8)*p;
            pos++;
            if (msgFont()->isLeadByte(code)) {
                code <<= 8;
                PUT_CH(data[pos]);
                len++;
                s32 lo = data[pos++];
                code |= (u8)lo;
            }
            JUTFont::TWidth tw;
            msgFont()->getWidthEntry(code, &tw);
            width += (s32)tw.w1;
        }
    }
    PUT_CH(c);
    return width;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
