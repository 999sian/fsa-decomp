// TU 0x80403414-0x80403d84.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- per-player setting accessors (two banks, picked by lbl_8053AAF8->0x7f) ----
extern char* lbl_8053AAF8;
struct T34Settings {
    u8 pad0[0x68];
    s32 m68[4];
    s32 m78[4];
    s32 m88[4];
    s32 m98[4];
    s32 mA8[4];
    s32 mB8[4];
};
extern T34Settings lbl_80529DEC;

extern "C" s32 fn_80403414(s32 i) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
        return lbl_80529DEC.m68[i];
    }
    return lbl_80529DEC.m98[i];
}

extern "C" void fn_80403454(s32 i, s32 v) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
        lbl_80529DEC.m88[i] = v;
    } else {
        lbl_80529DEC.mB8[i] = v;
    }
}

extern "C" void fn_80403494(s32 i, s32 v) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
        lbl_80529DEC.m78[i] = v;
    } else {
        lbl_80529DEC.mA8[i] = v;
    }
}

extern "C" void fn_804034D4(s32 i, s32 v) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
        lbl_80529DEC.m68[i] = v;
    } else {
        lbl_80529DEC.m98[i] = v;
    }
}

// ---- fn_80403680: reset ----
struct T34Vec { f32 x, y, z; };
struct T34Mgr {
    u8 pad0[0x64];
    s32 m64;
    s32 m68[4];
    s32 m78[4];
    s32 m88[4];
    s32 m98[4];
    s32 mA8[4];
    s32 mB8[4];
    s32 mC8[4];
    s32 mD8[4];
    s32 mE8[4];
    s32 mF8[4];
    s32 m108[4];
    s32 m118;
    s32 m11C;
    s32 m120;
    s32 m124;
    s32 m128;
    s32 m12C;
    s32 m130[4];
    s32 m140[4];
    s32 m150[4];
    s32 m160[4];
    s32 m170[4];
    s32 m180[4];
    s32 m190[4];
    s32 m1A0;
    s32 m1A4;
    s32 m1A8;
    s32 m1AC;
    s32 m1B0;
    s32 m1B4[4];
    T34Vec m1C4[4];
    u8 m1F4[8];
    u8 m1FC[24];
    u8 m214;
    u8 m215;
    u8 pad216[0x236 - 0x216];
    u8 m236;
    u8 m237;
    u8 pad238;
    u8 m239;
    u8 pad23A[4];
    u8 m23E;
    u8 pad23F;
    u8 m240;
    u8 pad241;
    u8 m242;
    u8 m243;
    u8 pad244[6];
    u8 m24A;
    u8 m24B;
    u8 pad24C;
    u8 m24D;
    u8 m24E;
    u8 m24F;
    u8 pad250[2];
    u8 m252;
    u8 m253;
    u8 m254;
};

struct T34SaveSlot { u8 pad[0x10]; s32 cur; u8 pad1[0x28 - 0x14]; u32 flags; u8 pad2[0xc8 - 0x2c]; };
extern T34SaveSlot lbl_8050EC80[];
inline T34SaveSlot* t34CurSlot() { return &lbl_8050EC80[lbl_8050EC80[0].cur]; }
inline BOOL t34IsSet(s32 a, s32 b) {
    if (a < 0 || a > 7) return FALSE;
    if (b < 0 || b > 3) return FALSE;
    T34SaveSlot* slot = t34CurSlot();
    return (1 << (b + a * 4)) & slot->flags ? TRUE : FALSE;
}

extern "C" void fn_80403514(T34Mgr* p) {
    p->m118 = 0;
    p->m11C = 0;
    for (s32 a = 0; a < 8; a++) {
        for (s32 b = 0; b < 4; b++) {
            BOOL set;
            if (a < 0 || a > 7) {
                set = FALSE;
            } else if (b < 0 || b > 3) {
                set = FALSE;
            } else {
                T34SaveSlot* slot = t34CurSlot();
                set = (1 << (b + a * 4)) & slot->flags ? TRUE : FALSE;
            }
            if (!set) {
                p->m118 = a;
                p->m11C = b;
                if ((p->m118 == 0 && p->m11C == 2) || (p->m118 == 1 && p->m11C == 2) ||
                    (p->m118 == 2 && p->m11C == 2) || (p->m118 == 3 && p->m11C == 2) ||
                    (p->m118 == 4 && p->m11C == 2) || (p->m118 == 5 && p->m11C == 2) ||
                    (p->m118 == 6 && p->m11C == 2) || (p->m118 == 7 && p->m11C == 1)) {
                    p->m11C++;
                }
                return;
            }
        }
    }
}

extern "C" void fn_80403680(T34Mgr* p) {
    for (int i = 0; i < 4; i++) {
        p->m68[i] = 0;
        p->m78[i] = 1;
        p->m88[i] = 2;
        p->m98[i] = 0;
        p->mA8[i] = 1;
        p->mB8[i] = 2;
        p->mE8[i] = 0;
        p->mD8[i] = 4;
        p->mC8[i] = 4;
        p->m108[i] = 0x80;
        p->mF8[i] = 0;
        p->m130[i] = 0;
        p->m140[i] = 0;
        p->m150[i] = 0;
        p->m160[i] = 0;
        p->m170[i] = 0;
        p->m180[i] = 0;
        p->m190[i] = 0;
        p->m1C4[i].x = 0.0f;
        p->m1C4[i].y = 0.0f;
        p->m1C4[i].z = 0.0f;
    }
    p->m1B4[0] = 0;
    p->m180[0] = 0;
    p->m1B4[1] = 0;
    p->m180[1] = 0;
    p->m1B4[2] = 0;
    p->m180[2] = 0;
    p->m1B4[3] = 0;
    p->m180[3] = 0;
    p->m1B0 = 0;
    p->m214 = 0;
    p->m215 = 0;
    p->m64 = -1;
    p->m1A8 = -1;
    p->m1A4 = -1;
    p->m236 = 0;
    p->m118 = 0;
    p->m11C = 0;
    p->m120 = 0;
    p->m124 = 0;
    p->m128 = 0;
    p->m12C = 0;
    p->m239 = 0;
    p->m1AC = 0;
    p->m253 = 0;
    p->m254 = 0;
    p->m237 = 0;
    for (int j = 0; j < 24; j++) {
        p->m1FC[j] = 0xff;
    }
    p->m242 = 0;
    p->m243 = 0;
    p->m23E = 0;
    p->m240 = 0;
    p->m24A = 0;
    p->m24B = 0;
    p->m24E = 0;
    p->m24F = 0;
    p->m24D = 0;
    p->m252 = 0;
}

// ---- from src/Game/fn_80403804_dtor.cpp ----
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B0FE0[];

extern "C" void* fn_80403804(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B0FE0;
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
