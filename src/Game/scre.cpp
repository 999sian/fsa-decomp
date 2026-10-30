// TU 0x80391ce4-0x80394134 (actor SCRE).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JUtility/TColor.h"
#include "JSystem/JMath/JMath.h"

class RupyNum {
public:
	void add(u8 digit, int p2, f32 scale, JUtility::TColor color);
};
extern "C" RupyNum* lbl_8053AF50;
extern const u8 lbl_80543170[4];
extern const u8 lbl_80543174[4];
extern const u8 lbl_80543178[4];
extern const f32 lbl_80543194;
extern const f32 lbl_80543198;
extern const f32 lbl_8054318C;
extern const f32 lbl_805431B4;
extern "C" void add__7RupyNumFUcifQ28JUtility6TColor(RupyNum*, s32, int, f32, JUtility::TColor);
static inline void screAdd(int n, const JGeometry::TVec3f pos, const JUtility::TColor color) {
    add__7RupyNumFUcifQ28JUtility6TColor(lbl_8053AF50, n, (int)&pos, lbl_8054318C, color);
}

extern "C" void fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern "C" void fn_80458880(void* mgr, u32 p, s32 v);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F8544(void* mgr, u32 tag, u32 id, f32* pos, s32 n);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void Actor_CreateByID(void* mgr, u32 name, u32 id, void* pos, u32 a5, s32 a6, s32 a7);
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" void* lbl_8053AF80;
extern "C" s32 fn_8023BC38(s32);
extern const u8 lbl_8054317C[];
extern const u8 lbl_80543180[];
extern const u8 lbl_80543184[];
extern const s32 lbl_80475710[10];
extern const f32 lbl_805431A8;
extern const f32 lbl_805431B8;
extern const f32 lbl_805431BC;
extern const f32 lbl_805431C0;

// ---- from src/Game/fn_80391CE4_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF4C0[];

extern "C" void* fn_80391CE4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF4C0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#pragma dont_inline on
extern "C" void fn_80391D44(void* this_) {
    u8* p = (u8*)this_;
    s32 n = fn_8023BC38(*(s32*)(p + 0x238)) / 60 + 1;
    if (n < 10) {
        f32 x = *(f32*)(p + 0xc);
        f32 y = *(f32*)(p + 0x10);
        f32 z = *(f32*)(p + 0x14);
        Vec pos;
        pos.x = x;
        pos.y = y;
        pos.z = z;
        if (*(s32*)(p + 4) < 8) {
            s32 type = *(s32*)(p + 0x238);
            GXColor c;
            c.r = lbl_8054317C[type];
            c.g = lbl_80543180[type];
            c.b = lbl_80543184[type];
            c.a = 0xff;
            lbl_8053AF50->add(n, (int)&pos, lbl_8054318C, *(JUtility::TColor*)&c);
        }
    } else {
        Vec pos;
        pos.x = *(f32*)(p + 0xc) - 8.333f;
        pos.y = *(f32*)(p + 0x10);
        pos.z = *(f32*)(p + 0x14);
        if (*(s32*)(p + 4) < 8) {
            s32 type = *(s32*)(p + 0x238);
            GXColor c;
            c.r = lbl_8054317C[type];
            c.g = lbl_80543180[type];
            c.b = lbl_80543184[type];
            c.a = 0xff;
            lbl_8053AF50->add(1, (int)&pos, lbl_8054318C, *(JUtility::TColor*)&c);
        }
        Vec pos2;
        pos2.x = *(f32*)(p + 0xc) + 8.333f;
        pos2.y = *(f32*)(p + 0x10);
        pos2.z = *(f32*)(p + 0x14);
        if (*(s32*)(p + 4) < 8) {
            s32 type = *(s32*)(p + 0x238);
            GXColor c;
            c.r = lbl_8054317C[type];
            c.g = lbl_80543180[type];
            c.b = lbl_80543184[type];
            c.a = 0xff;
            lbl_8053AF50->add(0, (int)&pos2, lbl_8054318C, *(JUtility::TColor*)&c);
        }
    }
}

extern const f32 lbl_80543188;
extern const f32 lbl_8054319C;
extern const f32 lbl_80543190;
static inline void screDigit(int n, const JGeometry::TVec3f pos, const JUtility::TColor color) {
    add__7RupyNumFUcifQ28JUtility6TColor(lbl_8053AF50, n, (int)&pos, lbl_80543188, color);
}
static inline void screDigitAt(u8* p, int n, f32 alpha) {
    if (*(s32*)(p + 4) < 8) {
        JUtility::TColor color(0xff, 0xd2, 0, (u8)(s32)alpha);
        screDigit(n, *(JGeometry::TVec3f*)(p + 0xc), color);
    }
}
static inline void screDigitOff(u8* p, int n, f32 x, f32 alpha) {
    JGeometry::TVec3f pos(x, *(f32*)(p + 0x10), *(f32*)(p + 0x14));
    if (*(s32*)(p + 4) < 8) {
        JUtility::TColor color(0xff, 0xd2, 0, (u8)(s32)alpha);
        screDigit(n, pos, color);
    }
}
extern "C" void fn_80391F58(void* this_) {
    u8* p = (u8*)this_;
    f32 alpha = lbl_80543194 * (*(s32*)(p + 0x230) / lbl_80543198);
    switch (*(s32*)(p + 0x23c)) {
    case 0:
        if (*(s32*)(p + 4) < 8) {
            JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(p + 0xc);
            JUtility::TColor color(0xff, 0xd2, 0, (u8)(s32)alpha);
            lbl_8053AF50->add(1, (int)&pos, lbl_80543188, color);
        }
        break;
    case 1:
        if (*(s32*)(p + 4) < 8) {
            JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(p + 0xc);
            JUtility::TColor color(0xff, 0xd2, 0, (u8)(s32)alpha);
            lbl_8053AF50->add(5, (int)&pos, lbl_80543188, color);
        }
        break;
    case 2: {
        JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(p + 0xc);
        pos.x -= lbl_8054319C;
        if (*(s32*)(p + 4) < 8) {
            JUtility::TColor color(0xff, 0xd2, 0, (u8)(s32)alpha);
            lbl_8053AF50->add(2, (int)&pos, lbl_80543188, color);
        }
        JGeometry::TVec3f pos2 = *(JGeometry::TVec3f*)(p + 0xc);
        pos2.x += lbl_8054319C;
        if (*(s32*)(p + 4) < 8) {
            JUtility::TColor color(0xff, 0xd2, 0, (u8)(s32)alpha);
            lbl_8053AF50->add(0, (int)&pos2, lbl_80543188, color);
        }
        break;
    }
    }
}

#pragma dont_inline reset

#pragma opt_propagation on
#pragma opt_common_subs off
extern "C" void fn_80393228(void* this_) {
    u8* p = (u8*)this_;
    f32 alpha = lbl_80543194 * (*(s32*)(p + 0x230) / lbl_80543198);
    if (*(s32*)(p + 0x23c) < 10) {
        if (*(s32*)(p + 4) < 8) {
            JGeometry::TVec3f pos(*(JGeometry::TVec3f*)(p + 0xc));
            s32 type = *(s32*)(p+0x238);
            u8 b = lbl_80543178[type];
            u8 r = lbl_80543170[type];
            u8 g = lbl_80543174[type];
            screAdd(*(s32*)(p + 0x23c), pos, JUtility::TColor(r, g, b, (u8)(s32)alpha));
        }
    } else if (*(s32*)(p + 0x23c) < 100) {
        if (*(s32*)(p + 4) < 8) {
            JGeometry::TVec3f pos(*(f32*)(p+0xc)-lbl_805431B4, *(f32*)(p+0x10), *(f32*)(p+0x14));
            s32 type = *(s32*)(p+0x238);
            u8 b = lbl_80543178[type];
            u8 r = lbl_80543170[type];
            u8 g = lbl_80543174[type];
            screAdd(*(s32*)(p + 0x23c)/10, pos, JUtility::TColor(r, g, b, (u8)(s32)alpha));
        }
        alpha = lbl_80543194 * (*(s32*)(p + 0x230) / lbl_80543198);
        if (*(s32*)(p + 4) < 8) {
            JGeometry::TVec3f pos(lbl_805431B4+*(f32*)(p+0xc), *(f32*)(p+0x10), *(f32*)(p+0x14));
            s32 type = *(s32*)(p+0x238);
            u8 b = lbl_80543178[type];
            u8 r = lbl_80543170[type];
            u8 g = lbl_80543174[type];
            screAdd(*(s32*)(p + 0x23c)%10, pos, JUtility::TColor(r, g, b, (u8)(s32)alpha));
        }
    } else if (*(s32*)(p + 4) < 8) {
        JGeometry::TVec3f pos(*(JGeometry::TVec3f*)(p + 0xc));
        s32 type = *(s32*)(p+0x238);
            u8 b = lbl_80543178[type];
            u8 r = lbl_80543170[type];
            u8 g = lbl_80543174[type];
        screAdd(10, pos, JUtility::TColor(r, g, b, (u8)(s32)alpha));
    }
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
extern "C" void fn_80393514(void* this_) {
    u8* p = (u8*)this_;
    if (*(s32*)(p + 0x230) == 0x5a) {
        f32 scale[12] = {0.3f, 0.3f, 0.3f, 0.35f, 0.35f, 0.4f, 0.45f, 0.5f, 0.55f, 0.6f, 0.6f, 0.6f};
        fn_8013CC50(*(s32*)(p + 4), p + 0xc, scale[0], 0xcb, 0, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(p + 4), p + 0xc, scale[0], 0xcc, 0, 0, 0, 0, 1);
        s32 n = *(s32*)(p + 0x23c);
        s32 idx = 9;
        if (n < 10) {
            idx = n - 1;
        }
        fn_80458880(lbl_8053AF80, lbl_80475710[idx], -1);
    }
    s16 ang = (*(s32*)(p + 0x230) % 60) << 10;
    if (*(s32*)(p + 0x234) == 0) {
        *(f32*)(p + 0x3c) = lbl_805431A8 * JMASinShort(ang);
        ((JGeometry::TVec3f*)(p + 0xc))->add(*(JGeometry::TVec3f*)(p + 0x3c));
    } else {
        *(f32*)(p + 0x248) += lbl_805431A8 * JMASinShort(ang);
        *(f32*)(p + 0x24c) -= lbl_805431A8;
        JGeometry::TVec3f* pos = (JGeometry::TVec3f*)(p + 0xc);
        pos->x = *(f32*)(p + 0x248) + fn_8023E724(*(s32*)(p + 0x238))->x;
        pos->y = *(f32*)(p + 0x24c) + fn_8023E724(*(s32*)(p + 0x238))->y;
    }
    if ((*(s32*)(p + 0x230))-- == 0) {
        JGeometry::TVec3f* player;
        s32 count;
        s32 i;
        s32 j;
        s32 slot;
        s32 a = *(s32*)(p + 0x240) / 10;
        s32 b = *(s32*)(p + 0x244) / 10;
        i = b + 1;
        if (a > b) {
            count = a - b;
            for (j = 0; j < count; i++, j++) {
                slot = -1;
                switch (i) {
                case 1:
                case 2: {
                    f32 y = fn_8023E724(*(s32*)(p + 0x238))->y;
                    f32 x = fn_8023E724(*(s32*)(p + 0x238))->x;
                    JGeometry::TVec3f pos;
                    pos.set(x, y, lbl_805431B8);
                    slot = fn_801F8544(fn_801F856C(), 0x52555059, *(s32*)(p + 4), (f32*)&pos, 2);
                    break;
                }
                case 3:
                case 4:
                case 5: {
                    f32 y = fn_8023E724(*(s32*)(p + 0x238))->y;
                    f32 x = fn_8023E724(*(s32*)(p + 0x238))->x;
                    JGeometry::TVec3f pos;
                    pos.set(x, y, lbl_805431B8);
                    slot = fn_801F8544(fn_801F856C(), 0x52555059, *(s32*)(p + 4), (f32*)&pos, 3);
                    break;
                }
                default: {
                    player = fn_8023E724(*(s32*)(p + 0x238));
                    Actor_CreateByID(fn_801F856C(), 0x46415259, *(s32*)(p + 4), player, 0, -1, -1);
                    break;
                }
                }
                if (slot >= 0) {
                    u8* c = (u8*)fn_801F666C(fn_801F856C(), slot);
                    if (c != 0) {
                        JGeometry::TVec3f v;
                        v.set(lbl_805431BC, lbl_805431BC, lbl_805431C0);
                        *(JGeometry::TVec3f*)(c + 0x3c) = v;
                    }
                }
            }
        }
        if (*(s32*)(p + 0x240) >= 15 && *(s32*)(p + 0x244) < 15) {
            f32 y = fn_8023E724(*(s32*)(p + 0x238))->y;
            f32 x = fn_8023E724(*(s32*)(p + 0x238))->x;
            JGeometry::TVec3f pos;
            pos.set(x, y, lbl_805431B8);
            slot = fn_801F8544(fn_801F856C(), 0x52555059, *(s32*)(p + 4), (f32*)&pos, 2);
            if (slot >= 0) {
                u8* c = (u8*)fn_801F666C(fn_801F856C(), slot);
                if (c != 0) {
                    JGeometry::TVec3f v;
                    v.set(lbl_805431BC, lbl_805431BC, lbl_805431C0);
                    *(JGeometry::TVec3f*)(c + 0x3c) = v;
                }
            }
        }
        *(u8*)(p + 0x11c) = 0;
    }
}

// ---- from src/Game/fn_8039394C.cpp ----
// fn_8039394C - actor@lbl_804AF490: coordinator function. Dispatches
// on this->0x234 (mode): 0/4 -> fn_80393228(this); 1 -> nothing;
// 2 -> fn_80391F58(this); 3/5/6/7 -> if (!fn_80230188(this->0x238))
// fn_80391D44(this).
extern "C" void fn_80393228(void* this_);
extern "C" void fn_80391F58(void* this_);
extern "C" u8 fn_80230188(s32 a);
extern "C" void fn_80391D44(void* this_);

extern "C" void fn_8039394C(void* this_) {
    s32 mode = *(s32*)((char*)this_ + 0x234);
    if (mode == 0 || mode == 4) {
        fn_80393228(this_);
    } else if (mode == 1) {
        // nothing
    } else if (mode == 2) {
        fn_80391F58(this_);
    } else if (mode == 3 || mode == 5 || mode == 6 || mode == 7) {
        if (!fn_80230188(*(s32*)((char*)this_ + 0x238))) {
            fn_80391D44(this_);
        }
    }
}

// ---- fn_803939E0: update
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" s32 fn_8023BC38(s32);
extern "C" void fn_80393514(void* this_);
extern const f32 lbl_805431A8;
extern const f32 lbl_805431AC;
extern const f32 lbl_805431B0;
extern const f32 lbl_805431C4;

struct SCRE {
    u8 pad00[0xc];
    JGeometry::TVec3f mPos; // 0x0c
    u8 pad18[0x3c - 0x18];
    JGeometry::TVec3f mVel; // 0x3c
    u8 pad48[0x11c - 0x48];
    u8 m11C;
    u8 pad11D[0x230 - 0x11d];
    s32 m230;
    s32 mMode; // 0x234
    s32 mPlayer; // 0x238
};

extern "C" void fn_803939E0(SCRE* this_) {
    s32 mode = this_->mMode;
    if (mode == 0 || mode == 4) {
        fn_80393514(this_);
    } else if (mode == 1) {
        if (this_->m230 >= 0x50) {
            s32 d = 0x5a - this_->m230;
            this_->mVel.y = lbl_805431AC * (lbl_805431B0 - (f32)(d * d / 100));
            this_->mPos.add(this_->mVel);
        }
        if (this_->m230-- == 0) {
            this_->m11C = 0;
        }
    } else if (mode == 2) {
        this_->mVel.x = lbl_805431A8 * JMASinShort((this_->m230 % 60) << 10);
        this_->mPos.add(this_->mVel);
        if (this_->m230-- == 0) {
            this_->m11C = 0;
        }
    } else if (mode == 3 || mode == 5 || mode == 6 || mode == 7) {
        f32 y, z;
        z = fn_8023E724(this_->mPlayer)->z;
        y = fn_8023E724(this_->mPlayer)->y - lbl_805431C4;
        this_->mPos.set(fn_8023E724(this_->mPlayer)->x, y, z);
        if (!fn_80230188(this_->mPlayer) && fn_8023BC38(this_->mPlayer) <= 0) {
            this_->m11C = 0;
        }
    }
}

// ---- fn_80393BF4: init
struct SCRE_Save { u8 pad[0x1f4]; u16 arr[4]; };
extern SCRE_Save lbl_80529DEC;
extern u8* lbl_8053AAF8;
extern "C" u8 fn_802DE814(void);
extern "C" void fn_801F0D20(void* this_, s32 id);
extern const f32 lbl_805431BC;
extern const f32 lbl_805431C0;
extern const f32 lbl_805431C8;
extern const f32 lbl_805431CC;

struct SCRE2 {
    u8 pad00[0xc];
    JGeometry::TVec3f mPos; // 0x0c
    u8 pad18[0x3c - 0x18];
    JGeometry::TVec3f mVel; // 0x3c
    u8 pad48[0x90 - 0x48];
    u32 m90;
    u8 pad94[0x11c - 0x94];
    u8 m11C;
    u8 pad11D[0x230 - 0x11d];
    s32 m230;
    s32 mMode;   // 0x234
    s32 mPlayer; // 0x238
    s32 m23C;
    s32 m240;
    s32 m244;
    f32 m248;
    f32 m24C;

    void snapToPlayer() {
        f32 z, y;
        z = fn_8023E724(mPlayer)->z;
        y = fn_8023E724(mPlayer)->y - lbl_805431C4;
        mPos.set(fn_8023E724(mPlayer)->x, y, z);
    }
    void snapToPlayer2() {
        f32 z = fn_8023E724(mPlayer)->z;
        f32 y = fn_8023E724(mPlayer)->y - lbl_805431C4;
        mPos.x = fn_8023E724(mPlayer)->x;
        mPos.y = y;
        mPos.z = z;
    }
};

#pragma opt_propagation off
extern "C" void fn_80393BF4(SCRE2* arg) {
    s32 mode;
    u16* tbl;
    SCRE2* __restrict this_ = arg;
    arg->m23C = arg->m90 & 0xffff;
    arg->mPlayer = (arg->m90 >> 16) & 0xff;
    arg->mMode = arg->m90 >> 24;
    this_->m248 = this_->mPos.x - fn_8023E724(this_->mPlayer)->x;
    this_->m24C = this_->mPos.y - fn_8023E724(this_->mPlayer)->y - lbl_805431C8;
    tbl = lbl_80529DEC.arr;
    this_->m240 = this_->m23C;
    this_->m244 = tbl[this_->mPlayer];
    mode = this_->mMode;
    if (mode == 0 || mode == 4) {
        if (lbl_8053AAF8[0x7f] == 0 || fn_802DE814()) {
            this_->m11C = 0;
        }
        if (this_->m23C == 0) {
            this_->m11C = 0;
        } else if (this_->m23C >= 100) {
            this_->m23C = 100;
        }
        if (this_->mMode == 0) {
            this_->mVel.set(lbl_805431BC, lbl_805431CC, lbl_805431BC);
        } else {
            this_->mVel.set(lbl_805431BC, lbl_805431BC, lbl_805431BC);
        }
        this_->m230 = 0x5a;
        tbl[this_->mPlayer] = this_->m240;
    } else if (mode == 1) {
        this_->mVel.set(lbl_805431BC, lbl_805431C0, lbl_805431BC);
        this_->m230 = 0x5a;
        fn_801F0D20(this_, 0x41);
    } else if (mode == 2) {
        if (this_->m23C >= 12) {
            this_->m11C = 0;
        }
        this_->mVel.set(lbl_805431BC, lbl_805431CC, lbl_805431BC);
        this_->m230 = 0x5a;
    } else if (mode == 3) {
        this_->m230 = 0x257;
        this_->snapToPlayer2();
    } else if (mode == 5) {
        this_->m230 = 0x1a3;
        this_->snapToPlayer();
    } else if (mode == 6) {
        this_->m230 = 0x12b;
        this_->snapToPlayer();
    } else if (mode == 7) {
        this_->m230 = 0xb3;
        this_->snapToPlayer();
    }
}
#pragma opt_propagation reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"
