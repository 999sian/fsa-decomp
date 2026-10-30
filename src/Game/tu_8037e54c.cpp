#pragma optimization_level 3
// TU 0x8037e54c-0x8038de74.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
extern "C" s32 fn_8022EA0C(s32);
extern "C" void* fn_802D6A9C();
extern "C" u8 fn_802D800C(void*, u8);
extern "C" s32 fn_80138A30(void*);
extern "C" s32 fn_8022CAF8(s32);
extern "C" u32 fn_8023EEB4(s32);
extern "C" s32 fn_8023EF50(s32);
extern "C" void fn_8023EE28(s32);
extern "C" s32 fn_8023ECF0(s32);
extern "C" u8 fn_8023EFEC(s32);
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void*, s32);
extern "C" s32 fn_80236100(s32);
extern "C" s32 fn_802373EC(s32);
extern "C" u8 fn_802D7E5C(void*, u8, s32);
extern "C" u8 fn_802D46D8(void* cfg, s32 index, u32 bit, u8 set);
extern "C" u8 fn_8022C8EC(s32 a);
extern "C" void fn_8030C4A0(u8* p, f32* in, u8 flag, f32* out);
extern "C" u8 fn_80303750(s32 a);
extern "C" s32 fn_8023DE58(s32 x);
extern "C" u8 fn_80390818(void* p);
extern u8 lbl_8050EC80[];
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JUtility/JUTFont.h"
#include "JSystem/JUtility/TColor.h"
#include "JSystem/JUtility/JUTVideo.h"
extern "C" u32 fn_80383EB0(s32 p, s32 q);
extern "C" u8 fn_80389F78(s32 unused, s32 p, s32 unused2, u32 id, JGeometry::TVec3<f32>* pos, u16 flags);
extern "C" u8 fn_80389964(s32 unused, s32 self, u32 id, u16 flags);
extern "C" u8 fn_8038B8A8(s32 unused, s32 p, s32 q, u32 id, u32 flags);
extern f32 lbl_805430F8;
extern f32 lbl_805430FC;
extern u8* lbl_8053AB10;

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


extern const f32 lbl_805430C8;
extern const f32 lbl_805430B8;
extern const f32 lbl_805430BC;
extern const f32 lbl_805430C0;
extern const f32 lbl_805430C4;
extern const f32 lbl_805430CC;
extern void* lbl_804AF32C[];
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
    s16 hf0[4];     // 0xf0
    s32 wf8;        // 0xf8
    s32 wfc[4];     // 0xfc
    u8 pad10c[0x114 - 0x10c];
    void* sub[4];   // 0x114
};
extern Mgr* lbl_8053AD78;

struct CharFontVt {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09(s8 ch, s32* info);
};

static inline u8 fn_8037F580_getw(char* buf, s32* idx) {
    s32 info;
    CharFontVt* font = *(CharFontVt**)((u8*)lbl_8053AD78 + 0x154);
    font->v09(buf[*idx], &info);
    return ((u8*)&info)[1];
}

static inline f32 fn_8037F580_adv(f32 acc, f32 scale, u8 w, char* buf, s32* idx, char ch) {
    *idx += 1;
    buf[*idx] = ch;
    return scale * (f32)(s32)w + acc;
}

static inline f32 fn_8037F580_skip(f32 acc, f32 scale, u8 w, s32* idx) {
    *idx += 1;
    return scale * (f32)(s32)w + acc;
}

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

// fn_80384C58 mode flag: explicit compare chain (no range merge), 0xc only while b7f is clear.
static inline u8 fn_80384C58_flag(void) {
    u8 f = 0;
    if (lbl_8053AAF8->b7f != 0) {
        if (lbl_8053AAF8->mode == 7) goto yes;
        if (lbl_8053AAF8->mode == 8) goto yes;
        if (lbl_8053AAF8->mode == 9) goto yes;
        if (lbl_8053AAF8->mode == 0x16) goto yes;
        if (lbl_8053AAF8->mode == 0xa) goto yes;
        if (lbl_8053AAF8->mode == 0xb) goto yes;
    } else {
        if (lbl_8053AAF8->mode == 7) goto yes;
        if (lbl_8053AAF8->mode == 8) goto yes;
        if (lbl_8053AAF8->mode == 9) goto yes;
        if (lbl_8053AAF8->mode == 0x16) goto yes;
        if (lbl_8053AAF8->mode == 0xa) goto yes;
        if (lbl_8053AAF8->mode == 0xb) goto yes;
        if (lbl_8053AAF8->mode == 0xc) goto yes;
    }
    return f;
yes:
    f = 1;
    return f;
}

static inline s32 fn_80384C58_slot(s32 p) {
    if (fn_80384C58_flag()) {
        s32 r = fn_8022F340(p);
        if (r >= 0 && r < 4) {
            return r;
        }
    }
    return p;
}

// Mode test shared by the slot-remap checks in fn_80385960: mode 0xc only counts while b7f is clear.
static inline bool fn_80385960_remapMode(void) {
    s32 mode = lbl_8053AAF8->mode;
    u8 f = 0;
    if (lbl_8053AAF8->b7f == 0) {
        if (mode == 7 || mode == 8 || mode == 9 || mode == 0x16 || mode == 0xa || mode == 0xb || mode == 0xc) {
            f = 1;
        }
    } else {
        if (mode == 7 || mode == 8 || mode == 9 || mode == 0x16 || mode == 0xa || mode == 0xb) {
            f = 1;
        }
    }
    return f != 0;
}

static inline s32 fn_80385960_slot(s32 p) {
    if (fn_80385960_remapMode()) {
        s32 i = fn_8022F340(p);
        if (i >= 0 && i < 4) {
            return i;
        }
    }
    return p;
}
extern "C" void fn_80390850(void* p);
extern "C" void fn_80458880(void* base, s32 a, s32 b);
extern "C" void fn_80391678(void* p);
extern "C" void fn_80230224(s32 a, s32 b);
extern "C" u8 fn_8023F264(s32 a);
extern u8 lbl_80529DEC[];
extern "C" int snprintf(char* s, unsigned long n, const char* fmt, ...);
extern "C" char* strcat(char* dst, const char* src);
extern "C" f32 fn_80381560(u8 type, s32 num, f32 scale);
extern "C" f32 fn_8037F580(u8 type, s32 num, char* out, s32* len, f32 scale);
extern f32 lbl_805430E8;
extern f32 lbl_805430EC;


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
extern "C" void __ct__9T37ConfigFv(char* p) {
    *(void**)p = lbl_804AF32C;
    *(u8*)(p + 0x4) = 0x0;
    *(u8*)(p + 0x5) = 0x0;
    *(s16*)(p + 0x6) = 0x0;
    *(f32*)(p + 0x8) = lbl_805430B8;
    *(f32*)(p + 0x30) = lbl_805430BC;
    *(f32*)(p + 0x34) = lbl_805430C0;
    *(f32*)(p + 0x38) = lbl_805430C4;
    *(f32*)(p + 0x3c) = lbl_805430C8;
    *(s16*)(p + 0x4c) = 0x6;
    *(f32*)(p + 0x40) = lbl_805430CC;
    *(s16*)(p + 0x4e) = -0x28;
    *(s16*)(p + 0x50) = 0x50;
    *(s16*)(p + 0x52) = 0x5;
    *(s16*)(p + 0x54) = 0x50;
    *(s16*)(p + 0x56) = 0x3;
    *(s16*)(p + 0x58) = 0x0;
    *(s16*)(p + 0x5a) = 0x3c;
    *(s16*)(p + 0x5c) = 0x3;
    *(s16*)(p + 0x5e) = 0xa;
    *(s16*)(p + 0x60) = 0xf;
    *(s16*)(p + 0x62) = 0x1e;
    *(s16*)(p + 0x64) = 0x4;
    *(s16*)(p + 0x66) = 0x16;
    *(s16*)(p + 0x68) = 0x10;
    *(s16*)(p + 0x6a) = 0x18;
    *(s16*)(p + 0x6c) = 0x78;
    *(s16*)(p + 0x6e) = 0x0;
    *(s16*)(p + 0x70) = 0x16;
    *(s16*)(p + 0x74) = 0x5;
    *(s16*)(p + 0x76) = 0x1e;
    *(s16*)(p + 0x78) = 0x0;
    *(s16*)(p + 0x7a) = 0x1e;
    *(s16*)(p + 0x7c) = 0x5;
    *(s16*)(p + 0x7e) = 0x5;
    *(s16*)(p + 0x80) = 0x32;
    *(u8*)(p + 0x2fa) = 0x0;
    *(u8*)(p + 0x2fb) = 0x0;
    *(s16*)(p + 0x8c) = 0x1c;
    *(s16*)(p + 0x8e) = 0x5;
    *(s16*)(p + 0x90) = 0x1a;
    *(s16*)(p + 0x92) = 0x5;
    *(s16*)(p + 0x94) = 0xe;
    *(s16*)(p + 0x96) = 0xa;
    *(s16*)(p + 0x98) = 0xa;
    *(s16*)(p + 0x9a) = 0x32;
    *(s16*)(p + 0x9c) = 0x1;
    *(s16*)(p + 0x9e) = 0x1e;
    *(s16*)(p + 0xc8) = 0x0;
    *(s16*)(p + 0xca) = 0x16;
    *(s16*)(p + 0xcc) = 0x14;
    *(s16*)(p + 0xce) = 0x14;
    *(s16*)(p + 0xd0) = 0xe;
    *(s16*)(p + 0xd2) = 0x14;
    *(s16*)(p + 0xd4) = 0x14;
    *(s16*)(p + 0xd6) = 0x10;
    *(s16*)(p + 0xd8) = 0x5;
    *(s16*)(p + 0xda) = 0x14;
    *(s16*)(p + 0xdc) = 0xa;
    *(s16*)(p + 0xde) = 0x10;
    *(s16*)(p + 0xe0) = 0xc;
    *(s16*)(p + 0xe2) = 0x5;
    *(s16*)(p + 0xe4) = 0xa;
    *(s16*)(p + 0xe6) = 0x14;
    *(s16*)(p + 0xe8) = 0x0;
    *(s16*)(p + 0xea) = 0xa;
    *(s16*)(p + 0xec) = 0x5;
    *(s16*)(p + 0xee) = 0x2;
    *(s16*)(p + 0xf0) = 0x14;
    *(s16*)(p + 0xf2) = 0x0;
    *(s16*)(p + 0xf4) = 0x14;
    *(s16*)(p + 0xf6) = 0x5;
    *(s16*)(p + 0xf8) = 0xa;
    *(s16*)(p + 0xfa) = 0x5;
    *(s16*)(p + 0x104) = 0xa;
    *(s16*)(p + 0x106) = 0x3;
    *(s16*)(p + 0x108) = 0xa;
    *(s16*)(p + 0x10a) = 0x14;
    *(s16*)(p + 0x118) = 0x0;
    *(s16*)(p + 0x11a) = 0x12;
    *(s16*)(p + 0x11c) = 0x8;
    *(s16*)(p + 0x11e) = 0x16;
    *(s16*)(p + 0x120) = 0x0;
    *(s16*)(p + 0x122) = 0xf;
    *(s16*)(p + 0x124) = 0x12;
    *(s16*)(p + 0x126) = 0xf;
    *(s16*)(p + 0x128) = 0x64;
    *(s16*)(p + 0x12a) = 0xc8;
    *(s16*)(p + 0x12c) = 0x1e;
    *(s16*)(p + 0x12e) = 0x14;
    *(s16*)(p + 0x154) = 0x0;
    *(s16*)(p + 0x156) = 0x14;
    *(s16*)(p + 0x158) = 0x6;
    *(s16*)(p + 0x15a) = 0x0;
    *(s16*)(p + 0x15c) = 0x14;
    *(s16*)(p + 0x15e) = 0x0;
    *(s16*)(p + 0x160) = 0x14;
    *(s16*)(p + 0x168) = 0x0;
    *(s16*)(p + 0x16a) = 0x12;
    *(s16*)(p + 0x16c) = 0x0;
    *(s16*)(p + 0x16e) = 0xa;
    *(s16*)(p + 0x170) = 0x8;
    *(s16*)(p + 0x172) = 0xa;
    *(s16*)(p + 0x174) = 0x14;
    *(s16*)(p + 0x176) = 0x6;
    *(s16*)(p + 0x17c) = 0x0;
    *(s16*)(p + 0x17e) = 0x10;
    *(s16*)(p + 0x180) = 0x6;
    *(s16*)(p + 0x182) = 0xa;
    *(s16*)(p + 0x184) = 0x14;
    *(s16*)(p + 0x186) = 0xa;
    *(s16*)(p + 0x188) = 0xa;
    *(s16*)(p + 0x18a) = 0x8;
    *(s16*)(p + 0x190) = 0x0;
    *(s16*)(p + 0x192) = 0x14;
    *(s16*)(p + 0x194) = 0x0;
    *(s16*)(p + 0x196) = 0xa;
    *(s16*)(p + 0x198) = 0x8;
    *(s16*)(p + 0x19a) = 0x14;
    *(s16*)(p + 0x19c) = 0x14;
    *(s16*)(p + 0x19e) = 0xa;
    *(s16*)(p + 0x1a4) = 0x0;
    *(s16*)(p + 0x1a6) = 0x14;
    *(s16*)(p + 0x1a8) = 0x0;
    *(s16*)(p + 0x1aa) = 0x6;
    *(s16*)(p + 0x1ac) = 0x8;
    *(s16*)(p + 0x1ae) = 0x0;
    *(s16*)(p + 0x1b0) = 0x14;
    *(s16*)(p + 0x1b8) = 0x0;
    *(s16*)(p + 0x1ba) = 0x14;
    *(s16*)(p + 0x1bc) = 0x0;
    *(s16*)(p + 0x1be) = 0xa;
    *(s16*)(p + 0x1c0) = 0x8;
    *(s16*)(p + 0x1c2) = 0x0;
    *(s16*)(p + 0x1c4) = 0x14;
    *(s16*)(p + 0x1cc) = 0x0;
    *(s16*)(p + 0x1ce) = 0x14;
    *(s16*)(p + 0x1d0) = 0x0;
    *(s16*)(p + 0x1d2) = 0x14;
    *(s16*)(p + 0x1d4) = 0x0;
    *(s16*)(p + 0x1d6) = 0xa;
    *(s16*)(p + 0x1d8) = 0x8;
    *(s16*)(p + 0x1da) = 0x14;
    *(s16*)(p + 0x1dc) = 0x14;
    *(s16*)(p + 0x1e0) = 0x0;
    *(s16*)(p + 0x1e2) = 0xa;
    *(s16*)(p + 0x1e4) = 0x8;
    *(s16*)(p + 0x1e6) = 0x14;
    *(s16*)(p + 0x1e8) = 0xa;
    *(s16*)(p + 0x1ea) = 0x8;
    *(s16*)(p + 0x1ec) = 0x0;
    *(s16*)(p + 0x1ee) = 0x14;
    *(s16*)(p + 0x1f0) = 0x0;
    *(s16*)(p + 0x1f2) = 0x14;
    *(s16*)(p + 0x1f4) = 0x0;
    *(s16*)(p + 0x1f6) = 0x14;
    *(s16*)(p + 0x1f8) = 0x0;
    *(s16*)(p + 0x1fa) = 0xa;
    *(s16*)(p + 0x1fc) = 0x8;
    *(s16*)(p + 0x1fe) = 0x14;
    *(s16*)(p + 0x200) = 0x14;
    *(s16*)(p + 0x202) = 0xa;
    *(s16*)(p + 0x208) = 0x0;
    *(s16*)(p + 0x20a) = 0x14;
    *(s16*)(p + 0x20c) = 0x0;
    *(s16*)(p + 0x20e) = 0x14;
    *(s16*)(p + 0x210) = 0x14;
    *(s16*)(p + 0x212) = 0x14;
    *(s16*)(p + 0x21c) = 0x0;
    *(s16*)(p + 0x21e) = 0x14;
    *(s16*)(p + 0x220) = 0x0;
    *(s16*)(p + 0x222) = 0xa;
    *(s16*)(p + 0x224) = 0x8;
    *(s16*)(p + 0x226) = 0x14;
    *(s16*)(p + 0x228) = 0x14;
    *(s16*)(p + 0x22a) = 0x1e;
    *(s16*)(p + 0x22c) = 0x50;
    *(s16*)(p + 0x22e) = 0x1e;
    *(s16*)(p + 0x230) = 0x0;
    *(s16*)(p + 0x232) = 0x0;
    *(s16*)(p + 0x234) = 0x0;
    *(s16*)(p + 0x236) = 0x0;
    *(s16*)(p + 0x238) = 0xa;
    *(s16*)(p + 0x23c) = 0xa;
    *(s16*)(p + 0x23a) = 0x4;
    *(s16*)(p + 0x23e) = 0x0;
    *(s16*)(p + 0x240) = -0x37;
    *(s16*)(p + 0x244) = 0xc;
    *(s16*)(p + 0x246) = 0x4;
    *(s16*)(p + 0x248) = 0x8;
    *(s16*)(p + 0x24a) = 0xa;
    *(s16*)(p + 0x24c) = 0x8;
    *(s16*)(p + 0x24e) = 0x4;
    *(s16*)(p + 0x250) = 0x8;
    *(s16*)(p + 0x252) = 0x7;
    *(s16*)(p + 0x254) = 0x4;
    *(s16*)(p + 0x256) = 0x8;
    *(s16*)(p + 0x258) = 0x1e;
    *(s16*)(p + 0x25a) = 0x5;
    *(s16*)(p + 0x25c) = 0x8;
    *(s16*)(p + 0x25e) = 0xa;
    *(s16*)(p + 0x260) = 0x0;
    *(s16*)(p + 0x262) = 0xc;
    *(s16*)(p + 0x264) = 0x0;
    *(s16*)(p + 0x266) = 0xc;
    *(s16*)(p + 0x268) = 0x5;
    *(s16*)(p + 0x26c) = 0x18;
    *(s16*)(p + 0x26e) = 0xf;
    *(s16*)(p + 0x290) = 0x50;
    *(s16*)(p + 0x270) = 0x2;
    *(s16*)(p + 0x272) = 0x5;
    *(s16*)(p + 0x274) = 0x0;
    *(s16*)(p + 0x276) = 0x6;
    *(s16*)(p + 0x278) = 0x0;
    *(s16*)(p + 0x27a) = 0x0;
    *(s16*)(p + 0x27c) = 0x0;
    *(s16*)(p + 0x27e) = -0xc;
    *(s16*)(p + 0x280) = 0x0;
    *(s16*)(p + 0x282) = 0x0;
    *(s16*)(p + 0x284) = 0x3c;
    *(s16*)(p + 0x286) = 0x14;
    *(s16*)(p + 0x288) = 0xa;
    *(s16*)(p + 0x28a) = 0x8;
    *(s16*)(p + 0x28c) = 0x6;
    *(s16*)(p + 0x28e) = 0x4;
    *(s16*)(p + 0x294) = -0x3c;
    *(s16*)(p + 0x296) = 0x12c;
    *(s16*)(p + 0x298) = 0x15e;
    *(s16*)(p + 0x29a) = 0x1ea;
    *(s16*)(p + 0x29c) = 0x24;
    *(s16*)(p + 0x29e) = 0x32;
    *(s16*)(p + 0x2a0) = 0x0;
    *(s16*)(p + 0x2a2) = 0x0;
    *(s16*)(p + 0x2a4) = 0x0;
    *(s16*)(p + 0x2a6) = 0x0;
    *(s16*)(p + 0x2a8) = 0x10;
    *(s16*)(p + 0x2aa) = 0x2;
    *(s16*)(p + 0x2ac) = 0x0;
    *(s16*)(p + 0x2ae) = 0x0;
    *(s16*)(p + 0x2b0) = 0x47e;
    *(s16*)(p + 0x2b2) = 0x6;
    *(s16*)(p + 0x2b4) = 0x0;
    *(s16*)(p + 0x2b6) = 0x14;
    *(s16*)(p + 0x2b8) = 0x5;
    *(s16*)(p + 0x2ba) = 0x0;
    *(s16*)(p + 0x2bc) = 0x0;
    *(s16*)(p + 0x2be) = 0xa;
    *(s16*)(p + 0x2c0) = 0x1e;
    *(s16*)(p + 0x2c2) = 0x46;
    *(s16*)(p + 0x2c4) = 0x23;
    *(s16*)(p + 0x2c6) = 0x50;
    *(s16*)(p + 0x2c8) = 0x28;
    *(s16*)(p + 0x2ca) = 0x8c;
    *(s16*)(p + 0x2cc) = 0x0;
    *(s16*)(p + 0x2ce) = 0x4a;
    *(s16*)(p + 0x2d0) = 0x1e;
    *(s16*)(p + 0x2d2) = 0x0;
    *(s16*)(p + 0x2d4) = 0x0;
    *(s16*)(p + 0x2d6) = 0x0;
    *(s16*)(p + 0x2d8) = 0x0;
    *(s16*)(p + 0x2da) = 0x0;
    *(s16*)(p + 0x2dc) = 0x0;
    *(s16*)(p + 0x2de) = 0x0;
    *(s16*)(p + 0x2e0) = 0x0;
    *(s16*)(p + 0x2e2) = 0x0;
    *(s16*)(p + 0x2e4) = 0x0;
    *(s16*)(p + 0x2e6) = 0x0;
    *(s16*)(p + 0x2e8) = 0xc8;
    *(s16*)(p + 0x2ea) = 0x82;
    *(s16*)(p + 0x2ec) = 0x0;
    *(s16*)(p + 0x2ee) = 0x2;
    *(f32*)(p + 0x44) = lbl_805430C4;
    *(f32*)(p + 0x48) = lbl_805430B8;
    *(s16*)(p + 0x2f8) = 0x50;
    *(u8*)(p + 0x30c) = 0x0;
    *(u8*)(p + 0x304) = 0x50;
    *(u8*)(p + 0x305) = 0x14;
    *(u8*)(p + 0x306) = 0x96;
    *(u8*)(p + 0x307) = 0x0;
    *(u8*)(p + 0x308) = 0x0;
    *(u8*)(p + 0x309) = 0x0;
    *(u8*)(p + 0x30a) = 0x0;
    *(u8*)(p + 0x30b) = 0x0;
    *(u8*)(p + 0x30c) = 0x0;
    *(u8*)(p + 0x30d) = 0x0;
}

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

extern "C" void* __dt__9T37ConfigFv(void* this_, s16 freeFlag) {
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

extern "C" u8 fn_8038A42C(s32, s32, s32, u32, s32, const JGeometry::TVec3<f32>*, u16);
static inline u8 canShowMessage(s32 p) {
    if (!fn_80303750(resolvePlayer(p))) return 0;
    u8 hit;
    for (s32 i=0;i<4;++i) {
        if ((lbl_8053AAF8->b82 & (u8)(1<<i)) && fn_80390818(lbl_8053AD78->sub[i])==1) {
            hit=1;
            goto found;
        }
    }
    hit=0;
found:
    if (hit) return 0;
    return 1;
}
extern "C" void fn_8022FBB8(s32, s32);
extern "C" u8 fn_802308E0(s32);
static inline u32 messageIndexById(const u32 id) {
    u32 result;
    u32 i;
    Inf1* inf = &lbl_8053AD78->p8->inf;
    for (i = 0; i < inf->count; i++) {
        if (inf->entries[i].id == id) { result = i; break; }
    }
    if (i >= inf->count) result = 0x12b;
    return result;
}
static inline u8 showMessageById(s32 manager, s32 player, s32 source, u32 id, s32 value, JGeometry::TVec3<f32> pos, u32 flags) {
    typedef u8 (*ShowFn)(s32, s32, s32, u32, s32, const JGeometry::TVec3<f32>*, u32);
    u32 index = messageIndexById(id);
    return ((ShowFn)fn_8038A42C)((s32)lbl_8053AD78, player, source, index, value, &pos, flags);
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

#pragma opt_lifetimes off
extern "C" u8 fn_8038C678(s32 a, u32 id, s32 p3, s32 room, const JGeometry::TVec3<f32>* pos, u32 flags) {
    f32 out[3];
    s32 i;
    s32 q;
    char* e;
    s32 f4;
    s32 f2;
    u16 flags16;
    s32 p;
    int roomCopy=room;
    p = resolvePlayer(a);
    if (!lbl_8053AAF8->b7f && !(flags & 0x2000)) return 0;
    u32 index=messageIndexById(id);
index=fn_80383EB0(p,index);
id=lbl_8053AD78->p8->inf.entries[index].id;
    if(fn_802D46D8(fn_802D6A9C(),p,index,0)==1) {
s32 q=resolvePlayer(p);
Inf1* inf=&lbl_8053AD78->p8->inf;
char* e=(char*)inf+inf->size+inf->entries[index].offset+8;
u32 next=index;
if(e[0]==0x1a&&e[2]==2&&e[4]==5)next=*(s32*)(e+5);
index=fn_80383EB0(q,next);
id=lbl_8053AD78->p8->inf.entries[index].id;
}
if (lbl_8053AAF8->b7e == 0 || ((flags16=flags), (flags & 0x40))) {
        if (roomCopy < 8) { JGeometry::TVec3<f32> v; v=*pos; return showMessageById((s32)lbl_8053AD78,p,a,id,p3,v,flags); }
        if (!fn_8022C8EC(0)) {
            f32 in[2];
            in[0]=lbl_805430F8; in[1]=lbl_805430FC;
            fn_8030C4A0(*(u8**)(lbl_8053AB10+0x24),in,1,out);
            JGeometry::TVec3<f32> v; v=*(JGeometry::TVec3<f32>*)out;
            return showMessageById((s32)lbl_8053AD78,p,a,id,p3,v,flags);
        }
    u8 can=canShowMessage(p);
        if (can) { JGeometry::TVec3<f32> v; v=*pos; return showMessageById((s32)lbl_8053AD78,p,a,id,p3,v,flags); }
        return ((u8(*)(s32,s32,s32,u32,s32,u32))fn_8038C60C)((s32)lbl_8053AD78,p,a,id,p3,flags);
    } else {
        u32 textIndex=messageIndexById(id);
        q=resolvePlayer(p);
        Inf1* inf=&lbl_8053AD78->p8->inf;
inf=&lbl_8053AD78->p8->inf;
e=(char*)inf+inf->size+8+inf->entries[textIndex].offset;
        u8 hit;
        if (e[0]==0x1a && e[2]==2 && e[4]==0x1f) hit=1;
        else if(e[0]==0x1a && e[2]==2 && e[4]==0x2f && ((u8*)lbl_8053AD78)[0xed]==0 && fn_80138A30(lbl_8053AAF8)>=2 && fn_8023DE58(fn_8022EA0C(q))>=8) {
            hit=1;
            ((u8*)lbl_8053AD78)[0xed]=hit;
            *(s32*)((u8*)lbl_8053AD78+0x110)=q;
            ((u8*)lbl_8053AD78)[0xee]=e[5];
        } else hit=0;
        if(hit) {
            if(((u8(*)(s32,s32,u32,u32))fn_80389964)((s32)lbl_8053AD78,p,messageIndexById(id),flags)) {
                JGeometry::TVec3<f32> v; v=*pos;
                if(showMessageById((s32)lbl_8053AD78,p,a,id,p3,v,flags)) {
                    q=resolvePlayer(a);
                    f4=flags16&4;
                    f2=flags16&2;
                    for(i=0;i<4;i++) {
                        if(i!=q && (lbl_8053AAF8->b82 & (u8)(1<<i))) {
                            if(fn_8022CAF8(i)==4) fn_8022FBB8(fn_8022EA0C(i),p3); else fn_8022FBB8(i,p3);
                            ((u8*)lbl_8053AD78->sub[resolvePlayer(i)])[0x24]=9;
                            if(!f4 && !f2) fn_802308E0(i);
                        }
                    }
                    return 1;
                }
            }
            goto fail;
        }
    u8 can=canShowMessage(p);
        if(can) { JGeometry::TVec3<f32> v; v=*pos; return showMessageById((s32)lbl_8053AD78,p,a,id,p3,v,flags); }
        return ((u8(*)(s32,s32,s32,u32,s32,u32))fn_8038C60C)((s32)lbl_8053AD78,p,a,id,p3,flags);
    }
fail:
    return 0;
}
#pragma opt_lifetimes on
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
    for (int i = 0; i < 4; i++) {
        const Mgr* mgr = lbl_8053AD78;
        int v;
        v = mgr->wfc[i];
        if (v != -1 && ((u32)(-((u32)lbl_8053AAF8->b82 & (u8)(1 << v)) | ((u32)lbl_8053AAF8->b82 & (u8)(1 << v))) >> 31) == 1) {
            fn_80390E68(mgr->sub[v]);
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

extern "C" u32 fn_8023EEB4(s32 p);
extern "C" s32 fn_8023EF50(s32 p);
extern "C" void fn_8023EE28(s32 p);
extern "C" s32 fn_8023ECF0(s32 p);
extern "C" u8 fn_8023EFEC(s32 p);
extern "C" s32 fn_80236100(s32 p);
extern "C" s32 fn_802373EC(s32 p);
extern "C" u32 fn_80383EB0(s32 p, s32 q) {
    s32 yes, no;
    s32 result;
    s8* cmd;
    u8 kind;
    s32 player;
    s32 original;
    original = fn_8022EA0C(p);
    player = resolvePlayer(p);
    p = q;
    for (;;) {
        Inf1* inf = &lbl_8053AD78->p8->inf;
        cmd = (s8*)inf + inf->size + inf->entries[p].offset + 8;
        s8 op = 0;
        if (cmd[0] == 0x1a && cmd[2] == 2) {
            switch (cmd[4]) {
            case 7: case 16: case 23: case 24: case 29: case 32:
            case 33: case 35: case 42: case 44: case 48: case 51:
                op = cmd[4]; break;
            default: goto invalid;
            }
        } else {
        invalid:
            cmd = 0;
        }
        if (cmd == 0) break;
        switch (op) {
        case 7: {
            yes = *(s32*)(cmd + 6);
            no = *(s32*)(cmd + 10);
            if (fn_802D800C(fn_802D6A9C(), cmd[5])) p = yes;
            else p = no;
            break;
        }
        case 16: {
            kind = cmd[5];
            s32 yes = *(s32*)(cmd + 6);
            s32 no = *(s32*)(cmd + 10);
            u32 consume = (u8)cmd[14];
            switch (kind) {
            case 0: case 1: case 2: case 16:
                if (fn_8023EEB4(original) == 'KEY0') {
                    s32 handle = fn_8023EF50(original);
                    s32 k = *(s32*)((u8*)fn_801F666C(fn_801F856C(), handle) + 0x280);
                    if ((k == 0 && kind == 0) || (k == 1 && kind == 1) || (k == 2 && kind == 2) || (k == 9 && kind == 16)) {
                        no = yes; if (consume) fn_8023EE28(original);
                    }
                } break;
            case 3: if (fn_8023EEB4(original) == 'BORD') { no = yes; if (consume) fn_8023EE28(original); } break;
            case 4: if (fn_8023EEB4(original) == 'STON') { no = yes; if (consume) fn_8023EE28(original); } break;
            case 5: if (fn_8023EEB4(original) == 'HBMB') { no = yes; if (consume) fn_8023EE28(original); } break;
            case 6: if (fn_8023EEB4(original) == 'NIWA') { no = yes; if (consume) fn_8023EE28(original); } break;
            case 7: if (fn_8023EEB4(original) == 'GRAS') { no = yes; if (consume) fn_8023EE28(original); } break;
            case 8: case 9: case 10:
                if (fn_8023EEB4(original) == 'TUBO') {
                    s32 handle = fn_8023EF50(original);
                    u32 k = (*(u32*)((u8*)fn_801F666C(fn_801F856C(), handle) + 0x90) >> 7) & 31;
                    if ((k == 0 && kind == 10) || (k == 1 && kind == 8) || (k == 2 && kind == 9)) {
                        no = yes; if (consume) fn_8023EE28(original);
                    }
                } break;
            case 11: case 12: case 13: case 14:
                if (fn_8023EEB4(original) == 'PLAY') {
                    if ((fn_8023ECF0(player) == 0 && kind == 11) ||
                        (fn_8023ECF0(original) == 1 && kind == 12) ||
                        (fn_8023ECF0(original) == 2 && kind == 13) ||
                        (fn_8023ECF0(original) == 3 && kind == 14)) no = yes;
                } break;
            case 15: if (!fn_8023EFEC(original)) no = yes; break;
            }
            p = no; break;
        }
        case 23: {
            u32 n = (u8)cmd[5];
            u32* seed = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
            *seed = *seed * 0x19660d + 0x3c6ef35f;
            union { u32 u; f32 f; } random;
            random.u = (*seed >> 9) | 0x3f800000;
            s32 v = (s32)(n * (random.f - lbl_805430C4)) + 1;
            if (v > (s32)n) v = n;
            Inf1* table = &lbl_8053AD78->p8->inf;
            u32 wanted = table->entries[p].id + v;
            u32 i;

            for (i = 0; i < table->count; i++) {
                if (table->entries[i].id == wanted) { result = i; break; }
            }
            if (i >= table->count) result = 0x12b;
            p = result;
            break;
        }
        case 24: {
            s32 a = *(s32*)(cmd + 5), b = *(s32*)(cmd + 9);
            s32 c = *(s32*)(cmd + 13), d = *(s32*)(cmd + 17);
            switch (fn_80138A30(lbl_8053AAF8)) {
            case 1: p = a; break; case 2: p = b; break;
            case 3: p = c; break; case 4: p = d; break;
            } break;
        }
        case 29: {
            s32 threshold = *(s32*)(cmd + 5);
            s32 yes = *(s32*)(cmd + 9);
            s32 no = *(s32*)(cmd + 13);
            p = no;
            if (fn_80236100(player) >= threshold) p = yes;
            break;
        }
        case 32: {
            s32 a = *(s32*)(cmd + 5), b = *(s32*)(cmd + 9);
            s32 c = *(s32*)(cmd + 13), d = *(s32*)(cmd + 17);
            switch (player) {
            case 0: p = a; break; case 1: p = b; break;
            case 2: p = c; break; case 3: p = d; break;
            } break;
        }
        case 33: {
            s32 yes = *(s32*)(cmd + 5); no = *(s32*)(cmd + 9);
            s32 room = *(s32*)(lbl_80529DEC + 0x118);
            s32 bit = *(s32*)(lbl_80529DEC + 0x11c);
            int set;
            if (room < 0 || room > 7) set = 0;
            else if (bit < 0 || bit > 3) set = 0;
            else set = (*(u32*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x28) & (1 << (room * 4 + bit))) != 0;
            if (set) p = yes; else p = no;
            break;
        }
        case 35: {
            u32 index = (u8)cmd[5];
            u16 bit = *(u16*)(cmd + 6);
            s32 yes = *(s32*)(cmd + 8); no = *(s32*)(cmd + 12);
            u8 which;
            if (index >= 1 && index <= 4) which = index - 1;
            else which = player;
            if (fn_802D7E5C(fn_802D6A9C(), which, bit)) p = yes; else p = no;
            break;
        }
        case 42: {
            s32 yes = *(s32*)(cmd + 5), no = *(s32*)(cmd + 9);
            if ((*(u8*)((u8*)lbl_8053AAF8 + 0x83) >> (player * 2) & 3) == 2u) p = yes;
            else p = no;
            break;
        }
        case 44: {
            s32 yes = *(s32*)(cmd + 5), no = *(s32*)(cmd + 9);
            if (fn_8022CAF8(player) != 4) p = yes; else p = no; break;
        }
        case 48: {
            s32 yes = *(s32*)(cmd + 5), no = *(s32*)(cmd + 9);
            if (fn_802373EC(player) == 1) p = yes; else p = no; break;
        }
        case 51: break;
        }
    }
    return p;
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

extern u8 lbl_8050DB0C[];
extern void* lbl_8053AED0;
extern "C" void fn_8043DF8C(void* p, f32 x, f32 y);
struct SubFlags { u16 pad : 9; u16 big : 1; u16 rest : 6; };
#define POS(i) (((Vec2f*)((u8*)lbl_8053AD78 + 0x124))[i])
extern "C" void fn_8037EB4C() {
    s32 i;
    for (i = 0; i < 4; i++) {
        u8* sub = *(u8**)((u8*)lbl_8053AD78 + 0x114 + i * 4);
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
    for (s32 j = 0; j < 4; j++) {
        list[j] = -1;
        if (fn_8023F264(j) == 1) {
            list[j] = j;
            n++;
        }
    }
    for (s32 j = 0; j < 4; j++) {
        if (list[j] >= 0 && fn_802300EC(list[j]) == 1) {
            ok++;
        }
    }
    if (n != ok) {
        return 0;
    }
    for (s32 j = 0; j < 4; j++) {
        if (list[j] >= 0) {
            fn_80230AD4(list[j]);
        }
    }
    return 1;
}


static inline s32 resolvePlayerConst(const int p) {
    if(isShared()) {
        const int r=fn_8022F340(p);
        if(r>=0 && r<4) return r;
    }
    return p;
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
extern "C" f32 fn_803832BC(char* out, u32 id, int num, char* out2, char* out3);
extern "C" u8 fn_8037F2FC(u32 id, s32 lines, u8 flag, const JUtility::TColor* __restrict color, f32 x, f32 y, f32 w, f32 h) {
    if (!lbl_8053AD78->be4) {
        if (lbl_8053AD78->w3c != id) {
            lbl_8053AD78->w3c = id;
            char* str = ((J2DTextBox*)lbl_8053AD78->p4)->getStringPtr();
            lbl_8053AD78->f6c = fn_803832BC(str, lbl_8053AD78->w3c, 0, 0, 0);
        }
        f32 scale = w / lbl_805430D0;
        f32 len = lbl_8053AD78->f6c * scale;
        f32 total = (s32)JUTVideo::getManager()->getFbWidth();
        total += len;
        ((J2DTextBox*)lbl_8053AD78->p4)->setFontSize(w, h);
        ((J2DTextBox*)lbl_8053AD78->p4)->setFontColor(*color, *color);
        lbl_8053AD78->w7c = lines;
        if (lbl_8053AD78->w7c == 0) {
            lbl_8053AD78->f70 = x - lbl_8053AD78->f6c * scale * 0.5f;
            lbl_8053AD78->f78 = 0.0f;
        } else {
            lbl_8053AD78->f70 = (s32)JUTVideo::getManager()->getFbWidth();
            lbl_8053AD78->f78 = total / lbl_8053AD78->w7c;
        }
        lbl_8053AD78->f74 = y - h * 0.5f;
        lbl_8053AD78->be5 = flag;
        lbl_8053AD78->be4 = 1;
        return 1;
    }
    return 0;
}

extern "C" f32 fn_8037F580(u8 type, s32 num, char* out, s32* len, f32 scale) {
    f32 acc = lbl_805430C8;
    u8 w;
    switch(type) {
    case 1:
        out[*len] = (char)0xa0;
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'F');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'o');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'r');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'c');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'e');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, (char)0xa0);
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'G');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'e');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'm');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_skip(acc, scale, w, len);
        if(num!=1) {
            out[*len] = 's';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
        }
        break;
    case 2:
        out[*len] = (char)0xa0;
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'C');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'u');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'c');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'c');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'o');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_skip(acc, scale, w, len);
        if(num!=1) {
            out[*len] = 's';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
        }
        break;
    case 3:
        out[*len] = (char)0xa0;
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'b');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'a');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'd');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'd');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_skip(acc, scale, w, len);
        if(num==1) {
            out[*len] = 'y';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
        } else {
            out[*len] = 'i';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
            out[*len] = 'e';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
            out[*len] = 's';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
        }
        break;
    case 4:
        out[*len] = (char)0xa0;
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 't');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'i');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'm');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'e');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_skip(acc, scale, w, len);
        if(num!=1) {
            out[*len] = 's';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
        }
        break;
    case 5:
        out[*len] = (char)0xa0;
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 's');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'y');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 's');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 't');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'e');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'm');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_skip(acc, scale, w, len);
        if(num!=1) {
            out[*len] = 's';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
        }
        break;
    case 6:
        out[*len] = (char)0xa0;
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 't');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'h');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'i');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'e');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_skip(acc, scale, w, len);
        if(num==1) {
            out[*len] = 'f';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
        } else {
            out[*len] = 'v';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
            out[*len] = 'e';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
            out[*len] = 's';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
        }
        break;
    case 7:
        out[*len] = (char)0xa0;
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'm');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'o');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'l');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'e');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_skip(acc, scale, w, len);
        if(num!=1) {
            out[*len] = 's';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
        }
        break;
    case 8:
        out[*len] = (char)0xa0;
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'r');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'e');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 't');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'u');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'r');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'n');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_skip(acc, scale, w, len);
        if(num!=1) {
            out[*len] = 's';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
        }
        break;
    case 9:
        out[*len] = (char)0xa0;
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'F');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'o');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'r');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'c');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'e');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, (char)0xa0);
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'F');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'a');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'i');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_adv(acc, scale, w, out, len, 'r');
        w = fn_8037F580_getw(out, len);
        acc = fn_8037F580_skip(acc, scale, w, len);
        if(num==1) {
            out[*len] = 'y';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
        } else {
            out[*len] = 'i';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
            out[*len] = 'e';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
            out[*len] = 's';
            w = fn_8037F580_getw(out, len);
            acc = fn_8037F580_skip(acc, scale, w, len);
        }
        break;
    default:
        break;
    }
    return acc;
}

extern "C" f32 fn_80381560(u8 type, s32 num, f32 scale)
{
    switch (type) {
    case 0:
        return scale;
    default:
        return scale;
    }
}

#pragma dont_inline on
#pragma opt_loop_invariants off
extern "C" f32 fn_80382B48(char* out, u32 id, int num, char* out2, char* out3) {
    f32 lw[10];
    char padbuf[0x10];
    s32 len;
    char chunk[3];
    f32 maxW = lbl_805430C8;
    f32 width = maxW;
    Inf1* inf = &lbl_8053AD78->p8->inf;
    s32 i = 0;
    s32 col = 1;
    s8* data = (s8*)inf + inf->size + inf->entries[id].offset + 8;
    u8 mode = 0;
    s8 c;

    len = 0;
    lw[0] = maxW;
    lw[1] = maxW;
    lw[2] = maxW;
    lw[3] = maxW;
    lw[4] = maxW;
    lw[5] = maxW;
    lw[6] = maxW;
    lw[7] = maxW;
    lw[8] = maxW;
    lw[9] = maxW;
    while ((c = data[i]) != 0) {
        if (c == '\n') {
            lw[col - 1] = width;
            if (width > maxW) {
                maxW = width;
            }
            width = lbl_805430C8;
            col++;
            i++;
        } else if (c == 0x1a) {
            if (data[i + 2] == 2) {
                s8 t = data[i + 4];
                if (t == 0 || t == 10 || t == 0x12 || t == 0x19) {
                } else if (t == 1 || t == 9 || t == 0x11 || t == 0x1a) {
                }
            } else if (data[i + 2] == 3) {
                int ch = num + '0';
                JUTFont::TWidth tw;
                (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(ch, &tw);
                width += (s32)tw.w1;
                width += fn_80381560(data[i + 5], num, lbl_805430E8);
            }
            i += data[i + 1];
        } else {
            s32 code = c & 0xff;
            i++;
            if ((*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->isLeadByte(code)) {
                code <<= 8;
                code |= (u8)data[i++];
            }
            JUTFont::TWidth tw;
            (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(code, &tw);
            width += (s32)tw.w1;
        }
    }
    lw[col - 1] = width;
    if (width > maxW) {
        maxW = width;
    }
    i = 0;
    len = 0;
    col = 1;
    width = lbl_805430C8;
    chunk[2] = 0;
    chunk[1] = 0;
    chunk[0] = 0;
    out[0] = 0;
    if (out2) {
        out2[0] = 0;
    }
    if (out3) {
        out3[0] = 0;
    }
    {
        s32 pad = (s32)((lbl_805430EC - lw[col - 1]) / 2.0f + 0.5f);
        if (pad > 0) {
            snprintf(padbuf, 0xf, "\x1b" "CR[%d]", pad);
            strcat(out, padbuf);
        }
    }
    while ((c = data[i]) != 0) {
        if (c == '\n') {
            chunk[0] = c;
            chunk[1] = 0;
            if (mode == 1 && out2) {
                strcat(out2, chunk);
            } else if (mode == 2 && out3) {
                strcat(out3, chunk);
            } else {
                strcat(out, chunk);
            }
            col++;
            i++;
            {
                s32 pad = (s32)((lbl_805430EC - lw[col - 1]) / 2.0f + 0.5f);
                if (pad > 0) {
                    snprintf(padbuf, 0xf, "\x1b" "CR[%d]", pad);
                    strcat(out, padbuf);
                }
            }
            width = lbl_805430C8;
        } else if (c == 0x1a) {
            if (data[i + 2] == 2) {
                s8 t = data[i + 4];
                if (t == 0 || t == 10 || t == 0x12 || t == 0x19) {
                    if (mode < 2) {
                        (&lbl_8053AD78->f5c)[mode] = width;
                        (&lbl_8053AD78->f64)[mode] = col - 1;
                        mode++;
                    }
                } else if (t == 1 || t == 9 || t == 0x11 || t == 0x1a) {
                    if (mode < 2) {
                        (&lbl_8053AD78->f5c)[mode] = width;
                        (&lbl_8053AD78->f64)[mode] = col - 1;
                        lbl_8053AD78->be6 = mode;
                        mode++;
                    }
                }
            } else if (data[i + 2] == 3) {
                int ch = num + '0';
                chunk[0] = ch;
                chunk[1] = 0;
                if (mode == 1 && out2) {
                    strcat(out2, chunk);
                } else if (mode == 2 && out3) {
                    strcat(out3, chunk);
                } else {
                    strcat(out, chunk);
                }
                JUTFont::TWidth tw;
                (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(ch, &tw);
                width += (s32)tw.w1;
                width += fn_8037F580(data[i + 5], num, out, &len, lbl_805430E8);
            }
            i += data[i + 1];
        } else {
            s32 code = c & 0xff;
            if ((*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->isLeadByte(code)) {
                chunk[0] = data[i];
                code <<= 8;
                chunk[1] = data[i + 1];
                chunk[2] = 0;
                if (mode == 1 && out2) {
                    if (chunk[0] != 0x20) {
                        strcat(out2, chunk);
                    }
                } else if (mode == 2 && out3) {
                    strcat(out3, chunk);
                } else {
                    strcat(out, chunk);
                }
                code |= (u8)data[i];
                i += 2;
            } else {
                chunk[0] = data[i];
                chunk[1] = 0;
                if (mode == 1 && out2) {
                    if (chunk[0] != 0x20) {
                        strcat(out2, chunk);
                    }
                } else if (mode == 2 && out3) {
                    strcat(out3, chunk);
                } else {
                    strcat(out, chunk);
                }
                i++;
            }
            JUTFont::TWidth tw;
            (*(JUTFont**)((u8*)lbl_8053AD78 + 0x154))->getWidthEntry(code, &tw);
            width += (s32)tw.w1;
        }
    }
    chunk[0] = c;
    chunk[1] = 0;
    if (mode == 1 && out2) {
        strcat(out2, chunk);
    } else if (mode == 2 && out3) {
        strcat(out3, chunk);
    } else {
        strcat(out, chunk);
    }
    return maxW;
}
#pragma opt_loop_invariants reset
#pragma dont_inline reset
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
    void* res = ((GameStateRes*)lbl_8053AAF8)->loader->getRes(0x3f3f3f3f, lbl_804755B0);
    mFont = new JUTResFont((ResFONT*)res, 0);
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
#pragma opt_lifetimes on
#pragma opt_propagation on
extern "C" void fn_8038D570() {
    s32 i;
    s32 j;
    s32 k;
    u8 id;
    s32 n;
    lbl_8053AD78->be7 = 0;
    for (i = 0; i < 4; i++) {
        if (testBit(lbl_8053AAF8->b82, i) == true) {
            *(s32*)((u8*)lbl_8053AD78->sub[i] + 0x18) = i;
            fn_80390EBC(lbl_8053AD78->sub[i]);
        }
    }
    if (lbl_8053AD78->be4) {
        if (lbl_8053AD78->w7c == 0) {
            for (j = 0; j < 4; j++) {
                if ((lbl_8053AD78->be5 & (1 << j)) && fn_80309D6C(lbl_8053AD30, fn_8030AAF4(j), 0x100)) {
                    lbl_8053AD78->be4 = 0;
                }
            }
        } else {
            lbl_8053AD78->w7c--;
            lbl_8053AD78->f70 -= lbl_8053AD78->f78;
            if (lbl_8053AD78->w7c == 0) {
                lbl_8053AD78->be4 = false;
            }
            {
                for (k = 0; k < 4; k++) {
                    if ((lbl_8053AD78->be5 & (1 << k)) && fn_80309D6C(lbl_8053AD30, fn_8030AAF4(k), 0x100)) {
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
                    t = lbl_8053AD78->bea;
                    fn_802D8050(fn_802D6A9C(), t, 1, 0xff);
                }
            } else {
                if (fn_802D800C(fn_802D6A9C(), m->bea) == 1) {
                    t = lbl_8053AD78->bea;
                    fn_802D8050(fn_802D6A9C(), t, 0, 0xff);
                }
            }
        }
    }
    if (lbl_8053AD78->bed) {
        for (n = 0; n < fn_80138A30(lbl_8053AAF8); n++) {
            (&lbl_8053ACD8)[n] = 1;
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


extern "C" u8 fn_8022FB1C(s32 p, s32 a);
extern "C" s32 fn_8022CAF8(s32 p);
extern "C" s32 fn_8022EA0C(s32 p);
extern "C" u8 fn_8023061C(s32 p, s32 a);
#pragma opt_lifetimes off
extern "C" void fn_803895EC(s32 unused, s32 p, s32 a, u8 b, u8 c) {
    s32 self;
    s32 orig = p;
    if (isShared()) {
        s32 resolved = fn_8022F340(p);
        if (resolved >= 0 && resolved < 4) {
            self = resolved;
            goto haveSelf;
        }
    }
    self = p;
haveSelf:
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
            if (b) fn_8023061C(p, 0);
            *((u8*)lbl_8053AD78->sub[resolvePlayer(p)] + 0x24) = 0;
        }
    }
}
#pragma opt_lifetimes reset

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
#pragma optimization_level 3
extern "C" u8 fn_8038B8A8(s32 unused, const s32 p, s32 q, u32 id, u32 options) {
    unsigned int flags = options;
    if (!isActive(p) && !fn_80303750(p) && fn_8022C8EC(p)) {
        u16 f = flags;
        if (f & 0x91f) {
            fn_80390E40(lbl_8053AD78->sub[p], id, 0);
            setActive(p, 1);
            if (f & 2) {
                *(u16*)((u8*)lbl_8053AD78->sub[p] + 0x28) |= 0x80;
            } else {
                *(u16*)((u8*)lbl_8053AD78->sub[p] + 0x28) |= 0x1;
            }
            if (f & 8) {
                *(u16*)((u8*)lbl_8053AD78->sub[p] + 0x28) |= 0x10;
            } else if (f & 0x10) {
                *(u16*)((u8*)lbl_8053AD78->sub[p] + 0x28) |= 0x20;
            }
            if (f & 0x100) {
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
extern "C" u8 fn_8038BD08(s32 a, s32 id, s32 room, JGeometry::TVec3<f32>* pos, s32 flags) {
    typedef u8 (*TvFn)(s32, s32, s32, u32, JGeometry::TVec3<f32>*, s32);
    typedef u8 (*TvFnV)(s32, s32, s32, u32, JGeometry::TVec3<f32>, s32);
    typedef u8 (*CheckFn)(s32, s32, u32, s32);
    f32 out[3];
    f32 in[2];
    bool ok;
    s32 p = resolvePlayer(a);
    if (!lbl_8053AAF8->b7f && !(flags & 0x2000)) {
        return 0;
    }
    id = fn_80383EB0(p, id);
    u16 flags16 = (u16)flags;
    if (!(flags & 0x20)) {
        if (fn_802D46D8(fn_802D6A9C(), p, id, 0) == 1) {
            return 0;
        }
    } else if (fn_802D46D8(fn_802D6A9C(), p, id, 0) == 1) {
        s32 q = resolvePlayer(p);
        Inf1* inf = &lbl_8053AD78->p8->inf;
        s8* e = (s8*)inf + (inf->size + inf->entries[id].offset + 8);
        s32 next = id;
        if (e[0] == 0x1a && e[2] == 2 && e[4] == 5) {
            next = *(s32*)(e + 5);
        }
        id = fn_80383EB0(q, next);
    }
    if (lbl_8053AAF8->b7e == 0 || (flags16 & 0x40)) {
        if (room < 8) {
            return ((TvFnV)fn_80389F78)((s32)lbl_8053AD78, p, a, id, *pos, flags);
        }
        if (!fn_8022C8EC(0)) {
            in[0] = lbl_805430F8;
            in[1] = lbl_805430FC;
            fn_8030C4A0(*(u8**)(lbl_8053AB10 + 0x24), in, 1, out);
            JGeometry::TVec3<f32> v(*(Vec*)out);
            return ((TvFn)fn_80389F78)((s32)lbl_8053AD78, p, a, id, &v, flags);
        }
        if (!fn_80303750(resolvePlayer(p))) {
            ok = false;
        } else if (fn_8037E4BC()) {
            ok = false;
        } else {
            ok = true;
        }
        if (ok) {
            JGeometry::TVec3<f32> v(*pos);
            return ((TvFn)fn_80389F78)((s32)lbl_8053AD78, p, a, id, &v, flags);
        }
        return fn_8038B8A8((s32)lbl_8053AD78, p, a, id, flags);
    }
    s32 q = resolvePlayer(p);
    Inf1* inf = &lbl_8053AD78->p8->inf;
    s8* e = (s8*)inf + inf->size + inf->entries[id].offset + 8;
    bool hit;
    if (e[0] == 0x1a && e[2] == 2 && e[4] == 0x1f) {
        hit = true;
    } else if (e[0] == 0x1a && e[2] == 2 && e[4] == 0x2f && ((u8*)lbl_8053AD78)[0xed] == 0 && fn_80138A30(lbl_8053AAF8) >= 2 && fn_8023DE58(fn_8022EA0C(q)) >= 8) {
        ((u8*)lbl_8053AD78)[0xed] = 1;
        *(s32*)((u8*)lbl_8053AD78 + 0x110) = q;
        ((u8*)lbl_8053AD78)[0xee] = e[5];
        hit = true;
    } else {
        hit = false;
    }
    if (hit) {
        if (((CheckFn)fn_80389964)((s32)lbl_8053AD78, p, id, flags)) {
            JGeometry::TVec3<f32> v(*pos);
            if (((TvFn)fn_80389F78)((s32)lbl_8053AD78, p, a, id, &v, flags)) {
                return 1;
            }
        }
        return 0;
    }
    if (!fn_80303750(resolvePlayer(p))) {
        ok = false;
    } else if (fn_8037E4BC()) {
        ok = false;
    } else {
        ok = true;
    }
    if (ok) {
        JGeometry::TVec3<f32> v(*pos);
        return ((TvFn)fn_80389F78)((s32)lbl_8053AD78, p, a, id, &v, flags);
    }
    return fn_8038B8A8((s32)lbl_8053AD78, p, a, id, flags);
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
    *(JGeometry::TVec3<f32>*)(sub + 0x50) = *pos;
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

extern "C" void fn_80230224(s32 i, s32 b);
#pragma opt_lifetimes on
extern "C" u8 fn_80384C58(s32 param_1, s32 param_2) {
    s32 a = resolvePlayer(param_1);
    s32 b;
    const u32* bits;
    s32 k;
    s32 found;
    u8 c;
    u16 flags;

    b = resolvePlayer(a);
    if (((u8*)lbl_8053AD78->sub[b])[0x24] == 0) {
        return 1;
    }
    b = resolvePlayer(a);
    if (((u8*)lbl_8053AD78->sub[b])[0x24] != 5) {
        b = resolvePlayer(a);
        if (((u8*)lbl_8053AD78->sub[b])[0x24] != 8) {
            goto fail;
        }
    }
    b = resolvePlayer(a);
    if (((u8*)lbl_8053AD78->sub[b])[0x40] != 0) {
        goto fail;
    }

 flags=*(u16*)((u8*)lbl_8053AD78->sub[a]+0x28);
 if(((flags>>2)&1)==0){
 if(flags&0x800)c=1;else c=fn_8022FB1C(param_1,param_2);
 if(c){
 b=resolvePlayer(param_1);
 flags=*(u16*)((u8*)lbl_8053AD78->sub[b]+0x28);
 if(((flags>>3)&1)||(flags&0x80))c=1;
 else if(lbl_8053AAF8->b7e==1)c=fn_8023061C(b,0);
 else {
 s32 players[4]; s32 j; s32* entry; s32* first;
 first=players;entry=first;
 for(j=0;j<4;j++,entry++){*entry=-1;if(fn_8023F264(j)==1)*entry=j;}
 {for(k=0;k<4;k++,first++)if(*first>=0)fn_80230224(*first,0);}
 c=1;
 }
 if(c){u32 bit=*(u32*)((u8*)lbl_8053AD78->sub[a]+0x20);
fn_802D46D8(fn_802D6A9C(),a,bit,1);
if (((u8*)lbl_8053AD78->sub[resolvePlayer(a)])[0x24] == 8) {
 b=resolvePlayer(a); s32 temp[4]; s32 j, offset; s32* out;
 for(j=offset=0,out=temp;j<lbl_8053AD78->wf8;offset+=4,out++,j++) {
 *out=*(s32*)((u8*)lbl_8053AD78+offset+0xfc);
 if(*(s32*)((u8*)lbl_8053AD78+offset+0xfc)==(int)b){*(s32*)((u8*)lbl_8053AD78+offset+0xfc)=-1;found=j;}
 }
 lbl_8053AD78->wf8--;
 for(;found<lbl_8053AD78->wf8;found++)lbl_8053AD78->wfc[found]=temp[found+1];
 lbl_8053AD78->wfc[lbl_8053AD78->wf8]=-1;
 if((*(u16*)((u8*)lbl_8053AD78->sub[a]+0x28)&0x40)==0)fn_80458880(lbl_8053AF80,0x29,-1);
}
 u8 first=1,second=0;
 void* sub=lbl_8053AD78->sub[a]; flags=*(u16*)((u8*)sub+0x28);
 if(((flags>>3)&1)||(flags&0x80))first=0;
 if((flags&0x800)==0)second=1;
 fn_80391678(sub);
 fn_803895EC((s32)lbl_8053AD78,param_1,param_2,first,second);return 1;
 }}}
 else {
 if(flags&0x800)c=1;else c=fn_8022FB1C(param_1,param_2);
 if(c){u32 bit=*(u32*)((u8*)lbl_8053AD78->sub[a]+0x20);
fn_802D46D8(fn_802D6A9C(),a,bit,1);
if (((u8*)lbl_8053AD78->sub[resolvePlayer(a)])[0x24] == 8) {
 b=resolvePlayer(a); s32 temp[4]; s32 j, offset; s32* out;
 for(j=offset=0,out=temp;j<lbl_8053AD78->wf8;offset+=4,out++,j++) {
 *out=*(s32*)((u8*)lbl_8053AD78+offset+0xfc);
 if(*(s32*)((u8*)lbl_8053AD78+offset+0xfc)==(int)b){*(s32*)((u8*)lbl_8053AD78+offset+0xfc)=-1;found=j;}
 }
 lbl_8053AD78->wf8--;
 for(;found<lbl_8053AD78->wf8;found++)lbl_8053AD78->wfc[found]=temp[found+1];
 lbl_8053AD78->wfc[lbl_8053AD78->wf8]=-1;
 if((*(u16*)((u8*)lbl_8053AD78->sub[a]+0x28)&0x40)==0)fn_80458880(lbl_8053AF80,0x29,-1);
}
 u8 second=0;void* sub=lbl_8053AD78->sub[a];
 if(((*(u16*)((u8*)sub+0x28)>>11)&1)==0)second=1;
 fn_80391678(sub);
 fn_803895EC((s32)lbl_8053AD78,param_1,param_2,0,second);return 1;
 }}
 fail: return 0;
}
#pragma opt_lifetimes reset
u8 fn_80385960(s32 param_1){
 s32 found;
 s32 slot=resolvePlayer(param_1);
 s32 idx;
 u16 flags;
 if(((u8*)lbl_8053AD78->sub[resolvePlayer(slot)])[0x24]==0)return 1;
 if(((u8*)lbl_8053AD78->sub[resolvePlayer(slot)])[0x24]!=5){
 if(((u8*)lbl_8053AD78->sub[resolvePlayer(slot)])[0x24]!=8)goto fail;
 }
 if(((u8*)lbl_8053AD78->sub[resolvePlayer(slot)])[0x40]!=0)goto fail;
 void* sub=lbl_8053AD78->sub[slot];
 flags=*(u16*)((u8*)sub+0x28);
 if(((flags>>12)&1)==1){fn_80391678(sub);return 1;}
 if((flags&1)==0){
 u8 done;
 idx=resolvePlayer(param_1);
 u16 f=*(u16*)((u8*)lbl_8053AD78->sub[idx]+0x28);
 if(((f>>3)&1)||(f&0x80))done=1;
 else if(lbl_8053AAF8->b7e==1)done=fn_8023061C(idx,0);
 else{
 s32 players[4]; s32 i; s32* entry; s32* first;
 first=players;entry=first;
 for(i=0;i<4;i++,entry++){*entry=-1;if(fn_8023F264(i)==1)*entry=i;}
 {s32 i;for(i=0;i<4;i++,first++)if(*first>=0)fn_80230224(*first,0);}
 done=1;
 }
 if(done){
 u32 bit=*(u32*)((u8*)lbl_8053AD78->sub[slot]+0x20);
 fn_802D46D8(fn_802D6A9C(),slot,bit,1);
if(((u8*)lbl_8053AD78->sub[resolvePlayer(slot)])[0x24]==8){
 idx=resolvePlayer(slot);
 s32 temp[4];
 s32 i; s32 offset; s32* out;
 i=0;out=temp;offset=i;
 for(;i<lbl_8053AD78->wf8;offset+=4,out++,i++){*out=*(s32*)((u8*)lbl_8053AD78+offset+0xfc);if(*(s32*)((u8*)lbl_8053AD78+offset+0xfc)==idx){*(s32*)((u8*)lbl_8053AD78+offset+0xfc)=-1;found=i;}}
 lbl_8053AD78->wf8--;
 for(;found<lbl_8053AD78->wf8;found++)lbl_8053AD78->wfc[found]=temp[found+1];
 lbl_8053AD78->wfc[lbl_8053AD78->wf8]=-1;
 if((*(u16*)((u8*)lbl_8053AD78->sub[slot]+0x28)&0x40)==0)fn_80458880(lbl_8053AF80,0x29,-1);
 }
 fn_80391678(lbl_8053AD78->sub[slot]);return 1;
}}else{fn_802D46D8(fn_802D6A9C(),slot,*(u32*)((u8*)sub+0x20),1);if(((u8*)lbl_8053AD78->sub[resolvePlayer(slot)])[0x24]==8){
 idx=resolvePlayer(slot);
 s32 temp[4];
 s32 i; s32 offset; s32* out;
 i=0;out=temp;offset=i;
 for(;i<lbl_8053AD78->wf8;offset+=4,out++,i++){*out=*(s32*)((u8*)lbl_8053AD78+offset+0xfc);if(*(s32*)((u8*)lbl_8053AD78+offset+0xfc)==idx){*(s32*)((u8*)lbl_8053AD78+offset+0xfc)=-1;found=i;}}
 lbl_8053AD78->wf8--;
 for(;found<lbl_8053AD78->wf8;found++)lbl_8053AD78->wfc[found]=temp[found+1];
 lbl_8053AD78->wfc[lbl_8053AD78->wf8]=-1;
 if((*(u16*)((u8*)lbl_8053AD78->sub[slot]+0x28)&0x40)==0)fn_80458880(lbl_8053AF80,0x29,-1);
 }
 fn_80391678(lbl_8053AD78->sub[slot]);return 1;
}fail:return 0;}
#pragma opt_lifetimes reset
extern "C" u8 fn_803908D0(void* sub);
extern "C" u8 fn_80390BA8(void* sub);
extern "C" s32 fn_80390BDC(void* sub);
extern "C" s32 fn_80390C38(void* sub);
extern "C" u8 fn_80390894(void* sub, u32 v);
extern "C" void fn_80390B64(void* sub);
extern "C" u8 fn_802D46D8(void* cfg, s32 index, u32 bit, u8 set);
extern "C" void OSReport(const char* fmt, ...);
#pragma opt_lifetimes on
extern "C" u8 fn_803865B8(s32 p) {
    const s32 i = resolvePlayer(p);
    bool bVar5;
    u8 bVar15;
    u16 uVar2;
    BOOL done = (lbl_8053AD78->be7 & (u8)(1 << resolvePlayer(i))) != 0;
    if (done & 1) {
        return 1;
    }
    if (lbl_8053AD78->hf0[i] > 0) {
        lbl_8053AD78->hf0[i]--;
        if (lbl_8053AD78->hf0[i] == 0) {
            lbl_8053AD78->be7 |= (u8)(1 << resolvePlayer(i));
            return 1;
        }
        return 0;
    }
    if (isActive(i) != 5) {
        if (isActive(i) != 8) {
            goto L_fail;
        }
    }
    bool bVar4 = false;
    u8 bVar6 = 0;
    if (fn_803908D0(lbl_8053AD78->sub[i]) == 0) {
        return 0;
    }
    if (fn_80390BA8(lbl_8053AD78->sub[i]) != 0xff) {
        if (fn_80390BA8(lbl_8053AD78->sub[i]) == 0) bVar4 = true;
        if ((u32)fn_80390BDC(lbl_8053AD78->sub[i]) == 0) {
            bVar6 = true;
        }
    }
    if (*((u8*)lbl_8053AD78->sub[resolvePlayer(i)] + 0x40) == 0) {
        if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(i), 0x100) == 0) {
            bVar5 = false;
            for (s32 k = 0; k < 4; k++) {
                if (lbl_8053AAF8->b82 & (u8)(1 << k)) {
                    u8 st = *((u8*)lbl_8053AD78->sub[k] + 0x24);
                    if (st == 0 || st == 9) {
                        if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(k), 0x100) != 0) {
                            bVar5 = true;
                        }
                    }
                }
            }
            if (bVar5 && (*(u16*)((u8*)lbl_8053AD78->sub[i] + 0x28) & 0x100) != 0) {
                bVar5 = true;
            } else {
                bVar5 = false;
            }
            if (bVar5) {
                goto L_191d8;
            }
        } else {
        L_191d8:
            if (!bVar4) {
                goto L_1920c;
            }
        }
        uVar2 = *(u16*)((u8*)lbl_8053AD78->sub[i] + 0x28);
        if ((((uVar2 >> 5) & 1) == 0 || (uVar2 & 0x1000) != 0) && bVar6 != 1) {
            goto L_fail;
        }
    L_1920c:
        if (((*(u16*)((u8*)lbl_8053AD78->sub[i] + 0x28)) >> 12 & 1) == 1) {
            return 1;
        }
        bVar15 = fn_80390894(lbl_8053AD78->sub[i], *(u32*)((u8*)lbl_8053AD78->sub[resolvePlayer(i)] + 0x2c));
        switch(bVar15){case 1: fn_80458880(lbl_8053AF80,0x59,-1);break;case 2:fn_80458880(lbl_8053AF80,0x5a,-1);break;}
        if (((*(u16*)((u8*)lbl_8053AD78->sub[i] + 0x28)) >> 12 & 1) == 0) {
            fn_802D46D8(fn_802D6A9C(), i, *(u32*)((u8*)lbl_8053AD78->sub[i] + 0x20), 1);
        }
        if ((u32)fn_80390C38(lbl_8053AD78->sub[i]) != 0xffffffff) {
        fn_8038470C(i, fn_80390C38(lbl_8053AD78->sub[i]));
        return 0;
        }
        lbl_8053AD78->hf0[i] = 2;
        return 0;
    }
    if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(i), 0x100) == 0) {
        bVar5 = false;
        for (s32 k = 0; k < 4; k++) {
            if (lbl_8053AAF8->b82 & (u8)(1 << k)) {
                u8 st = *((u8*)lbl_8053AD78->sub[k] + 0x24);
                if (st == 0 || st == 9) {
                    if (fn_80309D6C(lbl_8053AD30, fn_8030AAF4(k), 0x100) != 0) {
                        bVar5 = true;
                    }
                }
            }
        }
        if (bVar5 && (*(u16*)((u8*)lbl_8053AD78->sub[i] + 0x28) & 0x100) != 0) {
            bVar5 = true;
        } else {
            bVar5 = false;
        }
        if (bVar5) {
            goto L_194bc;
        }
    } else {
    L_194bc:
        if (!bVar4) {
            goto L_194d0;
        }
    }
    if (bVar6 != 1) {
        goto L_fail;
    }
L_194d0:
    OSReport("====>%d, %d\n", i, (*(u16*)((u8*)lbl_8053AD78->sub[i] + 0x28) >> 8) & 1);
    fn_80390B64(lbl_8053AD78->sub[i]);
    bVar15 = fn_80390894(lbl_8053AD78->sub[i], *(u32*)((u8*)lbl_8053AD78->sub[resolvePlayer(i)] + 0x2c));
    switch(bVar15){case 1: fn_80458880(lbl_8053AF80,0x59,-1);break;case 2:fn_80458880(lbl_8053AF80,0x5a,-1);break;}
    if (isActive(i) == 5) {
        setActive(i, 2);
    } else {
        setActive(i, 7);
    }
    return 0;
L_fail:
    return 0;
}

#pragma opt_lifetimes on
extern "C" u8 fn_80387494(s32 param_1) {
    s32 slot=resolvePlayer(param_1);
    s32 found;
    s32 k;
    u32 bit;
    s32 idx;
    u16 flags;
    if(isActive(slot)==0) return 1;
    if(isActive(slot)!=5 && isActive(slot)!=8 && isActive(slot)!=1 &&
       isActive(slot)!=6 && isActive(slot)!=3 && isActive(slot)!=7 && isActive(slot)!=4)
        goto fail;
    void* sub=lbl_8053AD78->sub[slot];
    flags=*(u16*)((u8*)sub+0x28);
    if((flags&1)==0) {
        u8 done;
        idx=resolvePlayer(param_1);
        u16 f=*(u16*)((u8*)lbl_8053AD78->sub[idx]+0x28);
        if(((f>>3)&1)||(f&0x80)) done=1;
        else if(lbl_8053AAF8->b7e==1) done=fn_8023061C(idx,0);
        else {
            s32 players[4];
            s32 i;
            s32* entry;
            s32* first;
            first=players;
            entry=first;
            for(i=0;i<4;i++,entry++) {
                *entry=-1;
                if(fn_8023F264(i)==1) *entry=i;
            }
            for(k=0;k<4;k++,first++) if(*first>=0) fn_80230224(*first,0);
            done=1;
        }
        if(done) {
            bit=*(u32*)((u8*)lbl_8053AD78->sub[slot]+0x20);
            fn_802D46D8(fn_802D6A9C(),slot,bit,1);
            sub=lbl_8053AD78->sub[slot];
            flags=*(u16*)((u8*)sub+0x28);
            if(((flags>>3)&1)||(flags&0x80)) {
                if(isActive(slot)==8) {
            idx=resolvePlayer(slot);
            s32 temp[4];
            s32 i, offset;
            s32* out;
            i=0; out=temp; offset=i;
            for(;i<lbl_8053AD78->wf8;offset+=4,out++,i++) {
                *out=*(s32*)((u8*)lbl_8053AD78+offset+0xfc);
                if(idx==*(s32*)((u8*)lbl_8053AD78+offset+0xfc)) {
                    *(s32*)((u8*)lbl_8053AD78+offset+0xfc)=-1;
                    found=i;
                }
            }
            lbl_8053AD78->wf8--;
            for(;found<lbl_8053AD78->wf8;found++) lbl_8053AD78->wfc[found]=temp[found+1];
            lbl_8053AD78->wfc[lbl_8053AD78->wf8]=-1;
            if((*(u16*)((u8*)lbl_8053AD78->sub[slot]+0x28)&0x40)==0)
                fn_80458880(lbl_8053AF80,0x29,-1);
        }
        fn_80391678(lbl_8053AD78->sub[slot]);
        return 1;
            }
            *(u8*)((u8*)sub+0x42)=1;
        if(isActive(slot)==6 || isActive(slot)==7) setActive(slot,8);
        else setActive(slot,5);
        return 0;
        }
    } else {
        if((flags&8)||(flags&0x80)) {
            if(isActive(slot)==8) {
            idx=resolvePlayer(slot);
            s32 temp[4];
            s32 i, offset;
            s32* out;
            i=0; out=temp; offset=i;
            for(;i<lbl_8053AD78->wf8;offset+=4,out++,i++) {
                *out=*(s32*)((u8*)lbl_8053AD78+offset+0xfc);
                if(idx==*(s32*)((u8*)lbl_8053AD78+offset+0xfc)) {
                    *(s32*)((u8*)lbl_8053AD78+offset+0xfc)=-1;
                    found=i;
                }
            }
            lbl_8053AD78->wf8--;
            for(;found<lbl_8053AD78->wf8;found++) lbl_8053AD78->wfc[found]=temp[found+1];
            lbl_8053AD78->wfc[lbl_8053AD78->wf8]=-1;
            if((*(u16*)((u8*)lbl_8053AD78->sub[slot]+0x28)&0x40)==0)
                fn_80458880(lbl_8053AF80,0x29,-1);
        }
        fn_80391678(lbl_8053AD78->sub[slot]);
        return 1;
        }
        *(u8*)((u8*)sub+0x42)=1;
        if(isActive(slot)==6 || isActive(slot)==7) setActive(slot,8);
        else setActive(slot,5);
        return 0;
    }
fail:
    return 0;
}
#pragma opt_lifetimes reset
extern "C" u8 fn_8022FCF0(s32 q, s32 v);
extern "C" void fn_8022FC54(s32 q, s32 v);
extern "C" u8 fn_8038A42C(s32 unused, s32 p, s32 q, u32 id, s32 val, const JGeometry::TVec3<f32>* pos, u16 flags) {
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
            JGeometry::TVec3<f32> v(*pos);
            u8* sub = (u8*)lbl_8053AD78->sub[p];
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

extern "C" void fn_8022FBB8(s32, s32);

#pragma opt_lifetimes off
extern "C" u8 fn_8038AD24(s32 a, u32 id, s32 p3, s32 room, const JGeometry::TVec3<f32>* pos, u16 flags) {
    f32 out[3];
    s32 i;
    s32 q;
    char* e;
    s32 f4;
    s32 f2;
    u16 flags16;
    s32 p;
    int roomCopy=room;
    p = resolvePlayer(a);
    if (!lbl_8053AAF8->b7f && !(flags & 0x2000)) return 0;
    id = fn_80383EB0(p, id);
    if (id == 0xea || id == 0xeb) {
        if (fn_802D46D8(fn_802D6A9C(), p, id, 0) == 1) return 0;
    } else if (fn_802D46D8(fn_802D6A9C(), p, id, 0) == 1) {
        s32 q = resolvePlayer(p);
        Inf1* inf = &lbl_8053AD78->p8->inf;
        char* e = (char*)inf + inf->size + 8 + inf->entries[id].offset;
        u32 next=id;
        if (e[0]==0x1a && e[2]==2 && e[4]==5) next=*(s32*)(e+5);
        id = fn_80383EB0(q,next);
    }
    if (lbl_8053AAF8->b7e == 0 || (flags & 0x40)) {
        if (roomCopy < 8) { JGeometry::TVec3<f32> v; v=*pos; return fn_8038A42C((s32)lbl_8053AD78,p,a,id,p3,&v,flags); }
        if (!fn_8022C8EC(0)) {
            f32 in[2];
            in[0]=lbl_805430F8; in[1]=lbl_805430FC;
            fn_8030C4A0(*(u8**)(lbl_8053AB10+0x24),in,1,out);
            JGeometry::TVec3<f32> v; v=*(JGeometry::TVec3<f32>*)out;
            return fn_8038A42C((s32)lbl_8053AD78,p,a,id,p3,&v,flags);
        }
    u8 can=canShowMessage(p);
        if (can) { JGeometry::TVec3<f32> v; v=*pos; return fn_8038A42C((s32)lbl_8053AD78,p,a,id,p3,&v,flags); }
        return fn_8038A984((s32)lbl_8053AD78,p,a,id,p3,flags);
    } else {
        flags16=flags;
        q=resolvePlayer(p);
        Inf1* inf=&lbl_8053AD78->p8->inf;
        e=(char*)inf+inf->size+8+inf->entries[id].offset;
        u8 hit;
        if (e[0]==0x1a && e[2]==2 && e[4]==0x1f) hit=1;
        else if(e[0]==0x1a && e[2]==2 && e[4]==0x2f && ((u8*)lbl_8053AD78)[0xed]==0 && fn_80138A30(lbl_8053AAF8)>=2 && fn_8023DE58(fn_8022EA0C(q))>=8) {
            hit=1;
            ((u8*)lbl_8053AD78)[0xed]=hit;
            *(s32*)((u8*)lbl_8053AD78+0x110)=q;
            ((u8*)lbl_8053AD78)[0xee]=e[5];
        } else hit=0;
        if(hit) {
            if(fn_80389964((s32)lbl_8053AD78,p,id,flags)) {
                JGeometry::TVec3<f32> v; v=*pos;
                if(fn_8038A42C((s32)lbl_8053AD78,p,a,id,p3,&v,flags)) {
                    q=resolvePlayer(a);
                    f4=flags16&4;
                    f2=flags16&2;
                    for(i=0;i<4;i++) {
                        if(i!=q && (lbl_8053AAF8->b82 & (u8)(1<<i))) {
                            if(fn_8022CAF8(i)==4) fn_8022FBB8(fn_8022EA0C(i),p3); else fn_8022FBB8(i,p3);
                            ((u8*)lbl_8053AD78->sub[resolvePlayer(i)])[0x24]=9;
                            if(!f4 && !f2) fn_802308E0(i);
                        }
                    }
                    return 1;
                }
            }
            goto fail;
        }
    u8 can=canShowMessage(p);
        if(can) { JGeometry::TVec3<f32> v; v=*pos; return fn_8038A42C((s32)lbl_8053AD78,p,a,id,p3,&v,flags); }
        return fn_8038A984((s32)lbl_8053AD78,p,a,id,p3,flags);
    }
fail:
    return 0;
}
#pragma opt_lifetimes on
extern "C" f32 fn_8037F580(u8 type, s32 num, char* out, s32* len, f32 scale);
extern "C" f32 fn_80381560(u8 type, s32 num, f32 scale);
extern f32 lbl_805430E8;
extern f32 lbl_805430EC;
#define PUT_CH(ch) \
    if (mode == 1 && out2) { out2[len] = (ch); } \
    else if (mode == 2 && out3) { out3[len] = (ch); } \
    else { out[len] = (ch); }
static inline JUTFont* msgFont() { return *(JUTFont**)((u8*)lbl_8053AD78 + 0x154); }
#pragma opt_loop_invariants off
extern "C" f32 fn_803832BC(char* out, u32 id, int num, char* out2, char* out3) {
    s8* p;
    f32 width = lbl_805430C8;
    Inf1* inf = &lbl_8053AD78->p8->inf;
    s8* data = (s8*)inf + inf->size + inf->entries[id].offset + 8;
    s32 pos = 0;
    s32 col = 1;
    u8 mode = 0;
    s32 len = 0;
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
                int ch = num + '0';
                PUT_CH(ch);
                len++;
                JUTFont::TWidth tw;
                msgFont()->getWidthEntry(ch, &tw);
                width += (s32)tw.w1;
                width += fn_8037F580(p[5], num, out, &len, lbl_805430C4);
            }
            pos += p[1];
        } else {
            PUT_CH(c);
            unsigned int code = *(u8*)p;
            len++;
            pos++;
            if (msgFont()->isLeadByte(code)) {
                code <<= 8;
                PUT_CH(data[pos]);
                c = data[pos++];
                len++;
                code |= (u8)c;
            }
            JUTFont::TWidth tw;
            msgFont()->getWidthEntry(code, &tw);
            width += (s32)tw.w1;
        }
    }
    PUT_CH(c);
    return width;
}
#pragma opt_loop_invariants reset
static inline s32 messagePadding(const f32 value) {
    return (s32)(value / 2.0f + 0.5f);
}
static inline void finishMessageLine(char* out, char* line, s32 col, f32 width, f32 fa, f32 fb, char* padbuf = NULL) {
    s32 pad = messagePadding(fa - width * fb);
    const s32 row = col - 1;
    if (lbl_8053AD78->f64 == (f32)row) lbl_8053AD78->f5c += pad;
    if (lbl_8053AD78->f68 == (f32)row) lbl_8053AD78->f60 += pad;
    if (pad > 0) {
        snprintf(padbuf, 0xf, "\x1b" "CR[%d]", pad);
        strcat(out, padbuf);
    }
    strcat(out, line);
}
extern "C" void fn_80230E1C(s32, s32);

#pragma optimization_level 3
extern "C" s32 fn_803837A4(char* out, s32 idx, s32 player, s32 val, f32 fa, f32 fb) {
    u8 flag;
    s32 shift;
    char* p;
    Inf1* inf = &lbl_8053AD78->p8->inf;
    char* str = (char*)inf + (inf->size + inf->entries[idx].offset + 8);
    s32 num = val;
    s32 pos = 0;
    s32 col = 1;
    u8 mode = 0;
    s32 len = 0;
    flag = (u8)(1 << (player - 1));
    shift = (player - 1) * 2;
    f32 width = lbl_805430C8;
    char padbuf[16];
    char line[100];
    char c;
    lbl_8053AD78->f5c = width;
    lbl_8053AD78->f64 = width;
    lbl_8053AD78->f60 = width;
    lbl_8053AD78->f68 = width;
    out[0] = 0;
    while ((c = (p = str + pos)[0]) != 0) {
        if (c == '\n') {
            char* dst = line + len;
            dst[0] = c;
            dst[1] = 0;
            finishMessageLine(out, line, col, width, fa, fb, padbuf);
            width = lbl_805430C8;
            len = 0;
            col++;
            pos++;
        } else if (c == 0x1a) {
            if (p[2] == 2) {
                char t = p[4];
                if (t == 0 || t == 10 || t == 0x12 || t == 0x19) {
                    if (mode < 2) {
                        (&lbl_8053AD78->f5c)[mode] = width;
                        (&lbl_8053AD78->f64)[mode] = col - 1;
                        mode++;
                    }
                } else if (t == 1 || t == 9 || t == 0x11 || t == 0x1a) {
                    if (mode < 2) {
                        (&lbl_8053AD78->f5c)[mode] = width;
                        (&lbl_8053AD78->f64)[mode] = col - 1;
                        lbl_8053AD78->be6 = mode;
                        mode++;
                    }
                } else if (t == 0x2e) {
                    if (player >= 1 && player <= 4 && (lbl_8053AAF8->b82 & flag) != 0 &&
                        ((u32)(((u8*)lbl_8053AAF8)[0x83] >> shift) & 3) == 1 && fn_8023DE58(player - 1) >= 8) {
                        fn_80230E1C(player - 1, 0);
                    }
                }
            } else if (p[2] == 3) {
                if (p[4] == 0) {
                    s32 ch = player + '0';
                    line[len++] = ch;
                    JUTFont::TWidth tw;
                    msgFont()->getWidthEntry(ch, &tw);
                    width += (s32)tw.w1;
                    width += fn_8037F580(p[5], player, line, &len, lbl_805430C4);
                } else if (p[4] == 2) {
                    s32 divisor = 1000;
                    bool started = false;
                    s32 digit = 0;
                    do {
                        if (val >= divisor) started = true;
                        if (started || divisor == 1) {
                            s32 ch = val / divisor + '0';
                            line[len++] = ch;
                            JUTFont::TWidth tw;
                            msgFont()->getWidthEntry(ch, &tw);
                            width += (s32)tw.w1;
                        }
                        val %= divisor;
                        divisor /= 10;
                        digit++;
                    } while (digit < 4);
                    width += fn_8037F580(p[5], num, line, &len, lbl_805430C4);
                }
            }
            pos += p[1];
        } else {
            line[len++] = c;
            u32 code = *(u8*)p;
            pos++;
            if (msgFont()->isLeadByte(code)) {
                line[len++] = str[pos];
                c = str[pos++];
                code = (code << 8) | (u8)c;
            }
            JUTFont::TWidth tw;
            msgFont()->getWidthEntry(code, &tw);
            width += (s32)tw.w1;
        }
    }
    line[len] = c;
    finishMessageLine(out, line, col, width, fa, fb, padbuf);
    return col;
}
struct T37Config {
    T37Config();
    ~T37Config();
    u8 data[0x310];
};
static T37Config sConfig;
#include "JSystem/JAudio/JASFakeMatchFSA.h"
