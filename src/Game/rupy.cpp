// TU 0x8032ab80-0x8032df94 (actor RUPY).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "JSystem/JGeometry/Vec.h"
#define Vec ActorVec
#include "Game/Actor.h"
#undef Vec
#include "Game/ItemBase.h"

extern const f32 lbl_80541D88;

// Scaled rotation matrix (X, Y, Z angles) into the upper 3x3 of m.
static inline void RupyRotScaleMtx(f32 (*m)[4], f32 s, f32 rx, f32 ry, f32 rz) {
    f32 cz;
    f32 cy;
    f32 sz;
    f32 sy;
    f32 sx;
    f32 cx;
    sx = sin(rx);
    sy = sin(ry);
    sz = sin(rz);
    cx = cos(rx);
    cy = cos(ry);
    cz = cos(rz);
    f32 sxsy = sx * sy;
    f32 cxsz = cx * sz;
    f32 cxcz = cx * cz;
    f32 sxsz = sx * sz;
    f32 sxcz = sx * cz;
    f32 cycz = cy * cz;
    f32 cysz = cy * sz;
    m[0][0] = s * cycz;
    m[1][0] = s * cysz;
    m[2][0] = s * -sy;
    m[0][1] = s * (sxsy * cz - cxsz);
    m[1][1] = s * (sxsy * sz + cxcz);
    m[2][1] = s * (sx * cy);
    m[0][2] = s * (cxcz * sy + sxsz);
    m[1][2] = s * (cxsz * sy - sxcz);
    m[2][2] = s * (cx * cy);
}

// Resource manager at lbl_8053AAF8+0xA4: vtable 0x18 looks up a resource by type and name.
struct RupyResMgr {
    virtual void r0();
    virtual void r1();
    virtual void r2();
    virtual void r3();
    virtual void* get(u32 type, const char* name);
};

// Actor vtable slot 13 (byte offset 0x34).
struct RupySlot13 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual u8 slot13();
};

// ---- fn_8032AB80_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AB6D8[];
extern const f32 lbl_80541D88;
extern const f32 lbl_80541D90;
extern const f32 lbl_80541D98;
extern const f32 lbl_80541D9C;
extern const f32 lbl_80541DA0;
extern const f32 lbl_80541DA4;
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" u8 fn_802DE9A0(void);
extern "C" u8 fn_802DEB58(void);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 flag);
extern "C" void* fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern void* lbl_8053AAF8;
extern const f32 lbl_80541DA8;
extern const f32 lbl_80541DAC;
extern const f32 lbl_80541DB0;
extern const f32 lbl_80541DB4;
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_801F0D20(void* this_, s32 a);
extern "C" u8 fn_802DEBA0(void);
extern const f32 lbl_80541D8C;
extern const f32 lbl_80541D94;
extern void* lbl_8053AED0;
extern const u32 lbl_804719D8[];
extern "C" u8 fn_8023B0F4(s32 idx, void* box, u32 room, s32 a, f32 f);
extern "C" u8 fn_80230188(s32 idx);
extern "C" u8 fn_80234ECC(s32 idx);
extern "C" u8 fn_8023EA28(s32 idx);
extern "C" u8 fn_80236B50(s32 idx);
extern "C" u8 fn_8023B9CC(s32 d, void* rect, u32 room, void* out8, u32 e);
extern "C" u8 fn_8023B848(s32 d, void* rect, u32 room, void* out8);
extern "C" u8 fn_80234C5C(s32 idx);
extern "C" u8 fn_8022B7C4(s32 idx);
extern "C" u8 fn_8022F514(s32 idx);
extern "C" s32 fn_8022F3DC(s32 idx);
extern "C" u8 fn_802D7F40(void* rec, u32 sw);
extern "C" void fn_802D7F84(void* rec, u32 sw, s32 on);
extern "C" void fn_8043D67C(void* mgr, s32 id, s32 arg, s32 flag);
extern "C" void fn_8043D874(void* mgr, s32 idx, u32 id, s32 flag);
extern "C" void fn_80230FD0(s32 idx, s32 id);
extern "C" void fn_802362C4(s32 idx, u32 id);
extern "C" u8 fn_8023ED8C(s32 idx);
extern "C" u8 fn_8023EBB8(s32 idx);
extern "C" u8 fn_80233DA4(s32 idx);
extern "C" u8 fn_802308E0(s32 idx);
extern "C" void* fn_8023E724(s32 idx);
extern "C" u8 fn_80233E40(s32 idx);
extern "C" void fn_80230498(s32 idx, void* vec, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void detach__5ActorFv(void* this_);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 room, void* pos, u32 param, s32 a, s32 b);
extern "C" void* fn_801F856C(void);
struct RupyVec3 {
    f32 x, y, z;
};

// Fast LCG at lbl_8053AAF8+0xB4; returns a value in [0,1).
static inline f32 rupyRand01() {
    u32* s = (u32*)((u8*)lbl_8053AAF8 + 0xb4);
    *s = *s * 0x19660du + 0x3c6ef35fu;
    u32 a = (*s >> 9) | 0x3f800000u;
    return *(f32*)&a - lbl_80541D90;
}

extern "C" void* fn_8032AB80(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AB6D8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_8032ABE0(void* this_) {
    s32 idx;
    u8* p = (u8*)this_;
    s32 i;
    f32 pos[2];
    f32 box[4];
    JGeometry::TVec3f v;
    JGeometry::TVec3f w;
    s32 state = *(s32*)(p + 0x230);

    if (state == 0 || state == 6 || (u32)(state - 1) <= 1 || state == 9 || state == 0xd) {
        if (*(u16*)(p + 0x94) != 2) {
            u8 flag = *((u8*)lbl_8053AAF8 + 0x7e);
            if (flag == 1 && *(s32*)(p + 0x24c) <= 0x3d4) {
            } else {
                if (flag != 0) {
                    return;
                }
                if (*(s32*)(p + 0x24c) > 0x320) {
                    return;
                }
            }
        }

        f32 y = *(f32*)(p + 0x10);
        f32 x = *(f32*)(p + 0xc);
        pos[0] = x;
        pos[1] = y;
        box[0] = *(f32*)(p + 0x60);
        box[1] = *(f32*)(p + 0x64);
        box[2] = *(f32*)(p + 0x68);
        box[3] = *(f32*)(p + 0x6c);
        box[0] += pos[0];
        box[1] += pos[1];
        box[2] += pos[0];
        box[3] += pos[1];

        idx = -1;
        for (i = 0; i < 4; i++) {
            if (fn_8023B0F4(i, box, *(u32*)(p + 4), 0, *(f32*)(p + 0x14)) == 1) {
                if (*(f32*)(p + 0x14) > lbl_80541D8C && *(u16*)(p + 0x94) != 2) {
                    continue;
                }
                if (fn_80230188(i) != 1 && fn_80234ECC(i) != 1 && fn_8023EA28(i) != 1) {
                    idx = i;
                    break;
                }
            }
        }

        if (idx < 0 && (*(f32*)(p + 0x14) < lbl_80541D8C || *(u16*)(p + 0x94) == 2)) {
            for (i = 0; i < 4; i++) {
                if (fn_80230188(i) == 0 && fn_8023EA28(i) == 0 && fn_80236B50(i) == 0 &&
                    (fn_8023B9CC(i, box, *(u32*)(p + 4), pos, 1) == 1 ||
                     fn_8023B848(i, box, *(u32*)(p + 4), pos) == 1)) {
                    idx = i;
                    break;
                }
            }
        }

        if (idx < 0) {
            return;
        }
        if (fn_80234C5C(idx) != 0) {
            return;
        }
        if ((*(u16*)(p + 0x94) != 0x23 && fn_8022B7C4(idx) == 0) ||
            (*(u16*)(p + 0x94) == 0x23 && fn_8022B7C4(idx) == 1)) {
            *(f32*)(p + 0x238) = lbl_80541D90;
            i = idx;
            if (fn_8022F514(idx) == 1) {
                i = fn_8022F3DC(idx);
            }
            if (*(s32*)((u8*)fn_802D6A9C() + 4) == 0 && *(s32*)((u8*)fn_802D6A9C() + 8) == 0 &&
                fn_802D7F40(fn_802D6A9C(), 0) == 0) {
                fn_8043D67C(lbl_8053AED0, 0x13f, i, 0);
                fn_802D7F84(fn_802D6A9C(), 0, 1);
            }
            if (*(s32*)(p + 0x268) >= 4) {
                if (fn_8023ED8C(idx) == 0 && fn_8023EBB8(idx) == 0 && fn_80233DA4(idx) == 0) {
                    if (fn_802308E0(idx) == 1) {
                        v = *(JGeometry::TVec3f*)fn_8023E724(idx);
                        w.x = v.x;
                        w.y = v.y - lbl_80541D94;
                        w.z = v.z;
                        if (fn_80233E40(idx)) {
                            fn_80230498(idx, &v, 0x336, 0xff, -0x80, -0x80, 1);
                        } else {
                            fn_80230498(idx, &v, 0xed, 0xff, -0x80, -0x80, 1);
                        }
                        Actor_CreateByID(fn_801F856C(), 0x494d5550, *(u32*)(p + 4), &w,
                                         *(s32*)(p + 0x268) + (idx << 24) + (idx << 26) + 0xa00000, -1, -1);
                        detach__5ActorFv(this_);
                    }
                } else {
                    fn_8043D874(lbl_8053AED0, idx, lbl_804719D8[*(s32*)(p + 0x268)], 0);
                    *(u16*)(p + 0x94) = 1;
                    *(s32*)(p + 0x264) = idx;
                    *(s32*)(p + 0x230) = 3;
                    *(s32*)(p + 0x274) = 0;
                    *(s32*)(p + 0xb0) = 0;
                }
            } else {
                fn_80230FD0(i, 0x20011);
                fn_802362C4(idx, lbl_804719D8[*(s32*)(p + 0x268)]);
                *(u16*)(p + 0x94) = 1;
                *(s32*)(p + 0x264) = idx;
                *(s32*)(p + 0x230) = 3;
                *(s32*)(p + 0x274) = 0;
                *(s32*)(p + 0xb0) = 0;
            }
        }
    }
}

extern "C" s32 fn_8032B0A4(void* this_) {
    u8* p = (u8*)this_;
    u16 subtype = *(u16*)(p + 0x94);
    s32 sVar;
    u32 id1;
    u32 id2;

    if (subtype == 0x23 || subtype == 0x24) {
        return 0;
    }
    if (*(f32*)(p + 0x14) > lbl_80541D98) {
        return 0;
    }
    sVar = (u16)fn_8022461C(p + 0xc, *(s32*)(p + 0x4));
    if (sVar == 3) {
        *(s32*)(p + 0x24c) = 0x3ff;
        *(f32*)(p + 0x44) = lbl_80541D88;
        *(f32*)(p + 0x40) = lbl_80541D88;
        *(f32*)(p + 0x3c) = lbl_80541D88;
        *(s32*)(p + 0x230) = 5;
        return 1;
    }
    if (sVar == 0xe) {
        *(s32*)(p + 0x24c) = 0x3ff;
        *(f32*)(p + 0x44) = lbl_80541D88;
        *(f32*)(p + 0x40) = lbl_80541D88;
        *(f32*)(p + 0x3c) = lbl_80541D88;
        *(f32*)(p + 0x238) = lbl_80541D88;
        if (*(s32*)(p + 0x230) != 5) {
            *(s32*)(p + 0x230) = 5;
            if (fn_802DE9A0() == 1) {
                id1 = 0x2a9;
                id2 = 0x2aa;
                fn_801F0E34(this_, 0x50040, 0);
            } else {
                if (fn_802DEB58() == 1) {
                    id1 = 0x45e;
                    id2 = 0x45f;
                    fn_801F0E34(this_, 0x5003f, 0);
                } else {
                    return 1;
                }
            }
            if (*(s32*)(p + 0x268) < 4) {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541D9C, id1, -1, 1, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541D9C, id2, 0, 0, 0, 0, 1);
            } else if (*(s32*)(p + 0x268) < 8) {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541D90, id1, -1, 1, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541D90, id2, 0, 0, 0, 0, 1);
            } else {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541DA0, id1, -1, 1, 0, 0, 1);
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541DA0, id2, 0, 0, 0, 0, 1);
            }
        }
        return 1;
    }
    if (sVar == 0xd) {
        *(f32*)(p + 0x44) = lbl_80541D88;
        *(f32*)(p + 0x40) = lbl_80541D88;
        *(f32*)(p + 0x3c) = lbl_80541D88;
        *(f32*)(p + 0x44) = lbl_80541DA4;
        *(f32*)(p + 0x238) = lbl_80541D90;
        if (*(s32*)(p + 0x230) != 6) {
            *(s32*)(p + 0x24c) = 0x1e;
            if (*(s32*)(p + 0x268) < 4) {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541D9C, 0x3d0, 0, 1, 0, 0, 1);
            } else if (*(s32*)(p + 0x268) < 8) {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541D90, 0x3d0, 0, 1, 0, 0, 1);
            } else {
                fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, lbl_80541DA0, 0x3d0, 0, 1, 0, 0, 1);
            }
            fn_801F0E34(this_, 0x30022, 0);
        }
        *(s32*)(p + 0x230) = 6;
        return 1;
    }
    return 0;
}

extern "C" s32 fn_8032B3F8(void* this_) {
    u8* p = (u8*)this_;
    u32 room = *(u32*)(p + 4);
    u8* mgr = (u8*)fn_802D6A9C();
    if (mgr[room + 0x131df] == 0) {
        if (*(f32*)(p + 0x14) > lbl_80541D88 || *(f32*)(p + 0x44) > lbl_80541D88) {
            *(f32*)(p + 0x44) = *(f32*)(p + 0x44) - lbl_80541DA8;
        } else if (*(f32*)(p + 0x14) <= lbl_80541D88) {
            *(f32*)(p + 0x14) = lbl_80541D88;
            if (p[0x280] == 1) {
                fn_801F0D20(this_, 0x42);
                p[0x280] = 0;
            }
            if ((u8)fn_8032B0A4(this_) != 0) {
                return 0;
            }
            if (*(s32*)(p + 0x260) == 0) {
                if (fn_802DEBA0() == 0) {
                    fn_801F0E34(this_, 0x3000a, 0);
                }
                *(s32*)(p + 0x260) = 1;
                if (p[0x27f] == 0) {
                    *(f32*)(p + 0x44) = lbl_80541DA0 + (lbl_80541D90 - lbl_80541DA0 * rupyRand01());
                    *(f32*)(p + 0x3c) = lbl_80541DAC - rupyRand01();
                    *(f32*)(p + 0x40) = lbl_80541DAC - rupyRand01();
                } else {
                    *(f32*)(p + 0x44) = lbl_80541DA0;
                    p[0x27f] = 0;
                }
            } else {
                *(f32*)(p + 0x44) = lbl_80541D88;
                *(f32*)(p + 0x40) = lbl_80541D88;
                *(f32*)(p + 0x3c) = lbl_80541D88;
                if (p[0x27d] != 0) {
                    *(s32*)(p + 0x230) = 9;
                } else {
                    *(s32*)(p + 0x230) = 1;
                }
            }
        }
    } else {
        if (lbl_80541D88 != *(f32*)(p + 0x44)) {
            *(f32*)(p + 0x40) = *(f32*)(p + 0x40) - *(f32*)(p + 0x44);
            *(f32*)(p + 0x44) = lbl_80541D88;
        }
        if (*(f32*)(p + 0x14) > lbl_80541D88) {
            *(f32*)(p + 0x10) = *(f32*)(p + 0x10) - *(f32*)(p + 0x14);
            *(f32*)(p + 0x14) = lbl_80541D88;
        }
        *(f32*)(p + 0x40) = *(f32*)(p + 0x40) + lbl_80541DA8;
        if (p[0x27e] == 1 && *(f32*)(p + 0x40) > lbl_80541D88) {
            if (lbl_80541D88 != *(f32*)(p + 0x284)) {
                *(f32*)(p + 0x3c) = *(f32*)(p + 0x3c) - *(f32*)(p + 0x3c);
            }
            if (lbl_80541D88 != *(f32*)(p + 0x288)) {
                if (p[0x280] == 1) {
                    fn_801F0D20(this_, 0x42);
                    p[0x280] = 0;
                }
                if (*(s32*)(p + 0x260) == 0) {
                    if (fn_802DEBA0() == 0) {
                        fn_801F0E34(this_, 0x3000a, 0);
                    }
                    *(s32*)(p + 0x260) = 1;
                    *(f32*)(p + 0x44) = lbl_80541D88;
                    *(f32*)(p + 0x3c) = lbl_80541DAC - rupyRand01();
                    *(f32*)(p + 0x40) = lbl_80541DB0 + (lbl_80541D90 - lbl_80541DA0 * rupyRand01());
                } else {
                    *(f32*)(p + 0x3c) = lbl_80541D88;
                    *(f32*)(p + 0x44) = lbl_80541D88;
                    *(f32*)(p + 0x40) = lbl_80541DB4;
                    if (p[0x27d] != 0) {
                        *(s32*)(p + 0x230) = 9;
                    } else {
                        *(s32*)(p + 0x230) = 1;
                    }
                }
            }
        }
    }
    return 1;
}

extern "C" u8 fn_8023A51C(s32 idx);
extern "C" s32 fn_8023DE58(s32 idx);
extern "C" void* fn_8023A478(s32 idx);
extern "C" u8 fn_8030C2A8(void* a, void* b);
extern "C" s32 fn_8023A240(void);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F8544(void* table, s32 kind, s32 room, void* pos, s32 flags);
extern "C" void* fn_801F666C(void* table, s32 idx);
extern "C" void detach__5ActorFv(void* this_);
extern const f32 lbl_80541DB8;
extern const f32 lbl_80541DBC;
extern void* lbl_8053AB10;
extern "C" void fn_8032BB90(char* this_) {
s32 room;
u32 kind;
s32 dir;
s32 i = 0;
do {
    if (fn_8023A51C(i) != 1) continue;
    room = *(s32*)(this_ + 4);
    if (room != fn_8023DE58(i)) continue;
    f32* pos = (f32*)fn_8023A478(i);
    JGeometry::TVec2f* actorPos = (JGeometry::TVec2f*)(this_ + 0xc);
    f32 dx = pos[0] - actorPos->x;
    f32 dy = pos[1] - actorPos->y;
    f32 dx2 = dx * dx;
    f32 dy2 = dy * dy;
    if (dx2 + dy2 > lbl_80541DB8) continue;
    if (fn_8030C2A8(*(void**)((char*)lbl_8053AB10 + 0x24), actorPos) != 1) continue;
    *(f32*)(this_ + 0x14) = lbl_80541DBC;
    if (*(s32*)(this_ + 0x230) == 7 || *(s32*)(this_ + 0x248) != 0) {
        kind = 'RUPY';
        if (*(s32*)(this_ + 0x248) != 0) {
            kind = 'ESRY';
            *(u32*)(this_ + 0x268) |= *(u32*)(this_ + 0x90) & 0xf8000000;
            *(u32*)(this_ + 0x268) |= 0x10000;
            u16 subtype = *(u16*)(this_ + 0x94);
            if (subtype == 0x20 || subtype == 0x21) dir = fn_8023A240();
            else if (*(s32*)(this_ + 0x248) == 1) dir = subtype - 0x11;
            else dir = subtype - 0x15;
        } else {
            *(u32*)(this_ + 0x268) |= 0x2000000;
            u16 subtype = *(u16*)(this_ + 0x94);
            if (subtype == 0x1d || subtype == 0x1e) dir = fn_8023A240();
            else if (subtype >= 4 && subtype <= 7) dir = subtype - 4;
            else dir = subtype - 8;
        }
        s32 index = fn_801F8544(fn_801F856C(), kind, *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x268));
        if (index >= 0) {
            char* spawned = (char*)fn_801F666C(fn_801F856C(), index);
            switch (dir) {
case 0: *(JGeometry::TVec3f*)(spawned + 0x3c) = JGeometry::TVec3f(lbl_80541DB0, lbl_80541D88, lbl_80541DBC); break;
case 1: *(JGeometry::TVec3f*)(spawned + 0x3c) = JGeometry::TVec3f(lbl_80541DA0, lbl_80541D88, lbl_80541DBC); break;
case 2: *(JGeometry::TVec3f*)(spawned + 0x3c) = JGeometry::TVec3f(lbl_80541D88, -lbl_80541DA0, lbl_80541DBC); break;
case 3: *(JGeometry::TVec3f*)(spawned + 0x3c) = JGeometry::TVec3f(lbl_80541D88, lbl_80541DA0, lbl_80541DBC); break;
}
        }
        detach__5ActorFv(this_);
    } else {
        if (*(u16*)(this_ + 0x94) == 0x1f) dir = fn_8023A240();
        else dir = *(u16*)(this_ + 0x94) - 0xc;
        switch (dir) {
case 0: *(JGeometry::TVec3f*)(this_ + 0x3c) = JGeometry::TVec3f(lbl_80541DB0, lbl_80541D88, lbl_80541DBC); break;
case 1: *(JGeometry::TVec3f*)(this_ + 0x3c) = JGeometry::TVec3f(lbl_80541DA0, lbl_80541D88, lbl_80541DBC); break;
case 2: *(JGeometry::TVec3f*)(this_ + 0x3c) = JGeometry::TVec3f(lbl_80541D88, -lbl_80541DA0, lbl_80541DBC); break;
case 3: *(JGeometry::TVec3f*)(this_ + 0x3c) = JGeometry::TVec3f(lbl_80541D88, lbl_80541DA0, lbl_80541DBC); break;
}
        if (*((u8*)lbl_8053AAF8 + 0x7e) == 1) *(s32*)(this_ + 0x24c) = 0x3d9;
        else *(s32*)(this_ + 0x24c) = 0x325;
        *(s32*)(this_ + 0xb0) = 0x20000;
        if (*(s32*)(this_ + 0x268) >= 4) *(s32*)(this_ + 0xb0) = 0x2000a;
        *(s32*)(this_ + 0x230) = 0;
    }
    u16 subtype = *(u16*)(this_ + 0x94);
    if ((subtype >= 4 && subtype <= 7) || (subtype >= 0xc && subtype <= 0xf) || subtype == 0x1d || subtype == 0x1f)
        ((Actor*)this_)->v10(0xff, 1);
    return;
} while (++i < 4);
}

extern "C" void fn_802F86CC(void* a, void* pos, void* obj, s32 id, DrawRec* rec, f32 sx, f32 sy);
extern "C" void fn_803075AC(void* h, s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void fn_801F06F0(void* actor, const char* res, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" s32 fn_8023CB24(s32 i);
extern "C" s8 fn_8023CA88(s32 i);
extern "C" u8 lbl_80471948[];
extern const f32 lbl_80541DC4;
extern const f32 lbl_80541DC8;
extern const f32 lbl_80541DCC;
extern const f32 lbl_80541DD0;
extern "C" void fn_8032BFB0(char* p) {
    u8* base = lbl_80471948;
    s32 big;
    const char* name;
    s32 mode;
    s32 id;
    f32 scale;
    s32 st = *(s32*)(p + 0x230);
    if (st == 7) {
        return;
    }
    if (st == 8) {
        return;
    }
    if (st == 0xc) {
        return;
    }
    if (st == 0xe) {
        return;
    }
    if (st == 0x11 || *(u16*)(p + 0x94) == 0x24) {
        return;
    }
    if (st == 0xa) {
        if (lbl_80541D88 == *(f32*)(p + 0x238)) {
            return;
        }
    } else if (st == 0xf || st == 0x10) {
        if (*(s32*)(p + 4) < 8) {
            return;
        }
    }
    name = (const char*)(base + 0xe0);
    scale = *(f32*)(p + 0x238);
    big = 0;
    if (*(s32*)(p + 0x268) >= 8) {
        name = (const char*)(base + 0xf4);
        big = 1;
    }
    DrawRec rec;
    f32 mtx[3][4];
    JGeometry::TVec3<f32> save;
    PSMTXIdentity(mtx);
    {
        f32 cx;
        f32 ang;
        f32 s;
        f32 sx;
        f32 sy;
        f32 sz;
        f32 cy;
        f32 cz;
        ang = *(f32*)(p + 0x23c);
        sx = sin(lbl_80541D88);
        sy = sin(ang);
        sz = sin(lbl_80541D88);
        cx = cos(lbl_80541D88);
        cy = cos(ang);
        cz = cos(lbl_80541D88);
        s = scale;
        f32 sxsy = sx * sy;
        f32 cxsz = cx * sz;
        f32 cxcz = cx * cz;
        f32 sxsz = sx * sz;
        f32 sxcz = sx * cz;
        f32 cycz = cy * cz;
        f32 cysz = cy * sz;
        rec.w18 = mtx;
        rec.b2d = 1;
        rec.b20 = 0;
        mtx[0][0] = s * cycz;
        mtx[1][0] = s * cysz;
        mtx[2][0] = s * -sy;
        mtx[0][1] = s * (sxsy * cz - cxsz);
        mtx[1][1] = s * (sxsy * sz + cxcz);
        mtx[2][1] = s * (sx * cy);
        mtx[0][2] = s * (cxcz * sy + sxsz);
        mtx[1][2] = s * (cxsz * sy - sxcz);
        mtx[2][2] = s * (cx * cy);
    }
    st = *(s32*)(p + 0x230);
    if (st == 5 || st == 6) {
        ((u8*)&rec.w10)[3] = (s32)((lbl_80541DC4 * (f32)*(s32*)(p + 0x24c)) / lbl_80541DC8);
        id = *(s32*)(p + 0x254) + ((s32*)base)[*(s32*)(p + 0x268)];
        if (*(s32*)(p + 4) >= 8) {
            return;
        }
        void* obj = (*(RupyResMgr**)((u8*)lbl_8053AAF8 + 0xa4))->get('SOB ', name);
        fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), p + 0xc, obj, id, &rec, lbl_80541D90, lbl_80541D90);
        return;
    }
    if (*(u16*)(p + 0x94) != 2 && *(s32*)(p + 0x24c) < 0x100 && (*(s32*)(p + 0x24c) & 2) && *(s32*)(p + 4) >= 8) {
        if (((u8*)lbl_8053AAF8)[0x96] != 1) {
            return;
        }
    }
    rec.b1d = 1;
    if (*(s32*)(p + 4) < 8 && *(s32*)(p + 0x24c) < 0xe0) {
        s32 t = *(s32*)(p + 0x24c) % 64;
        if (t > 0x20) {
            ((u8*)&rec.w10)[3] = (s32)(lbl_80541DC4 * (lbl_80541DCC - (f32)t) * lbl_80541DD0);
        } else {
            ((u8*)&rec.w10)[3] = (s32)(lbl_80541DC4 * (f32)t * lbl_80541DD0);
        }
    }
    if (*(f32*)(p + 0x14) > lbl_80541D88) {
        rec.b1c = 1;
    } else if (*(u16*)(p + 0x94) == 0x23) {
        rec.b1c = -1;
    } else {
        rec.b1c = 0;
    }
    mode = 7;
    if (*(u16*)(p + 0x94) == 0x23) {
        mode = -1;
        ((u8*)&rec.w10)[3] = 0x7f;
        ((u8*)&rec.w10)[0] = 0x7f;
        ((u8*)&rec.w10)[1] = 0x7f;
        ((u8*)&rec.w10)[2] = 0x7f;
    } else if (*(s32*)(p + 0x230) == 3 || *(s32*)(p + 0x230) == 4) {
        if (*(s32*)(p + 0x264) >= 0 && *(s32*)(p + 0x264) <= 3) {
            rec.b1d = fn_8023CB24(*(s32*)(p + 0x264)) + 1;
            rec.b1c = fn_8023CA88(*(s32*)(p + 0x264));
            mode = -1;
        }
    }
    if (*(s32*)(p + 0x230) == 0xd && *(f32*)(p + 0x14) > lbl_80541D88) {
        rec.w30 = 0x11;
    }
    save = *(JGeometry::TVec3<f32>*)(p + 0xc);
    *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x290);
    fn_801F06F0(p, name, *(s32*)(p + 0x254) + ((s32*)base)[*(s32*)(p + 0x268)], &rec, mode, lbl_80541D90, lbl_80541D90);
    id = *(s32*)(p + 0x254) + ((s32*)base)[*(s32*)(p + 0x268)];
    if (*(s32*)(p + 0x268) >= 8) {
        id = *(s32*)(p + 0x254) + ((s32*)base)[*(s32*)(p + 0x268) - 4];
    }
    if (*(s32*)(p + 0x230) == 0xb) {
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, id, big != 0, 2, -1, 1, 0, 0);
    } else {
        fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, id, big != 0, 2, -1, 0, 0, 0);
    }
    *(JGeometry::TVec3<f32>*)(p + 0xc) = save;
}

extern "C" void fn_8032C664(char* p) {
}

// RUPY: small helpers.
extern const f32 lbl_80541D88;
extern "C" void fn_8032D534(char* p) {
    *(f32*)(p + 0x44) = lbl_80541D88;
    *(f32*)(p + 0x40) = lbl_80541D88;
    *(f32*)(p + 0x3c) = lbl_80541D88;
    if (*(s32*)(p + 0x24c) < 800) {
        *(s32*)(p + 0x24c) = 800;
    }
    *(s32*)(p + 0x230) = 1;
}

extern "C" u32 fn_8032D564(void* p, s32 i) { return lbl_804719D8[i]; }

// NONMATCHING (93.1%): the constant extent copy is scheduled before the
// register saves here, after them in retail.
// fn_8032D578 - RUPY: can the rupee land at pos? Checks the collision map
// first, then the tile type.
struct RupyPt { f32 x, y; };
extern RupyPt lbl_80541D80;
extern u32 lbl_80541D84;
extern "C" u8* fn_8020D58C();
extern "C" u8 fn_8020D6AC(void* slot, s32 room, void* pos, u32 id, RupyPt* ext);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" bool fn_802265DC(void* pos, s32 room, s32 a);
extern "C" u8 fn_8032D578(char* p, s32 room, void* pos) {
    RupyPt ext;
    *(u32*)&ext = *(u32*)&lbl_80541D80;
    ((u32*)&ext)[1] = *(u32*)&lbl_80541D84;
    u32 id = *(u32*)(p + 0x198);
    u8* mgr = fn_8020D58C();
    if (fn_8020D6AC(mgr + 4 + mgr[1] * 0x784, room, pos, id, &ext) == 1) {
        return 1;
    }
    bool ok;
    s32 t = fn_8022461C(pos, room);
    if (t == 0x3b || t == 0x23) {
        ok = 0;
    } else {
        ok = fn_802265DC(pos, room, 0);
    }
    if (!ok) {
        *(u8*)(p + 0x283) = 0;
    }
    return ok;
}

// ---- FlagClear_8032D660.cpp ----
// fn_8032D660(this) - RUPY's (Rupee) vtable slot override. Gated on
// this->0x94 (a halfword) being exactly 0x19 or 0x1a - likely a
// rupee-color/value subtype range. When in that range, makes a
// virtual call through its own vtable slot 13 (byte offset 0x34,
// shared with many other actors); if that call returns true, clears
// this->0x280 (a byte flag - plausibly "is still collectible/active",
// given RUPY's role as a pickup). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot13 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual u8 slot13();
};

extern "C" void fn_8032D660(void* this_) {
    u16 subtype = *(u16*)((char*)this_ + 0x94);
    if (subtype == 0x19 || subtype == 0x1a) {
        if (((ActorSlot13*)this_)->slot13() != 0) {
            *(u8*)((char*)this_ + 0x280) = 0;
        }
    }
}

extern const f32 lbl_80541DFC;
extern const f32 lbl_80541E1C;
extern const f32 lbl_80541E20;
extern const f32 lbl_80541E24;
extern const f32 lbl_80541E28;
extern const f32 lbl_80541E2C;
extern const f32 lbl_80541E30;
extern const f32 lbl_80541E34;
extern const f32 lbl_80541E38;
extern "C" void fn_8032D6C0(void* this_) {
    u8* p = (u8*)this_;
    s32 room;

    *(u16*)(p + 0x94) = (*(u32*)(p + 0x90) >> 16) & 0xff;
    *(s32*)(p + 0x268) = *(u32*)(p + 0x90) & 0xff;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x254) = 0;
    *(u16*)(p + 0x240) = 0;
    *(s32*)(p + 0x258) = 0;
    *(u16*)(p + 0x242) = 0;
    *(s32*)(p + 0x25c) = 0;
    *(u16*)(p + 0x244) = 0;
    *(s32*)(p + 0x260) = 1;
    *(u8*)(p + 0x280) = (*(u32*)(p + 0x90) >> 25) & 1;
    *(u8*)(p + 0x281) = (*(u32*)(p + 0x90) >> 26) & 1;
    *(s32*)(p + 0x278) = (*(u32*)(p + 0x90) >> 8) & 0xff;
    *(s32*)(p + 0x234) = 0x12;
    *(s32*)(p + 0x264) = -1;
    *(f32*)(p + 0x238) = lbl_80541D90;
    *(f32*)(p + 0x23c) = lbl_80541D88;
    *(s32*)(p + 0x250) = (s32)(lbl_80541DFC * rupyRand01()) + 0x3c;
    *(f32*)(p + 0x80) = lbl_80541E1C;
    *(f32*)(p + 0x84) = lbl_80541D88;
    *(f32*)(p + 0x88) = lbl_80541D98;
    *(f32*)(p + 0x8c) = lbl_80541E20;
    *(f32*)(p + 0x60) = lbl_80541E24;
    *(f32*)(p + 0x64) = lbl_80541E24;
    *(f32*)(p + 0x68) = lbl_80541E20;
    *(f32*)(p + 0x6c) = lbl_80541E20;
    if (((u8*)lbl_8053AAF8)[0x7e] == 1) {
        *(s32*)(p + 0x24c) = 0x3f2;
    } else {
        *(s32*)(p + 0x24c) = 0x33e;
    }
    *(s32*)(p + 0x248) = 0;
    if (*(s32*)(p + 0x268) >= 8) {
        *(f32*)(p + 0x80) = lbl_80541E24;
        *(f32*)(p + 0x84) = lbl_80541E1C;
        *(f32*)(p + 0x88) = lbl_80541E20;
        *(f32*)(p + 0x8c) = lbl_80541D94;
        *(f32*)(p + 0x60) = lbl_80541E28;
        *(f32*)(p + 0x64) = lbl_80541E28;
        *(f32*)(p + 0x68) = lbl_80541E2C;
        *(f32*)(p + 0x6c) = lbl_80541E2C;
    }
    *(s32*)(p + 0x26c) = -1;
    *(u8*)(p + 0x282) = 0;
    *(u8*)(p + 0x27c) = 1;
    *(u8*)(p + 0x27d) = 0;
    *(u8*)(p + 0x27e) = 0;
    *(f32*)(p + 0x28c) = lbl_80541D88;
    *(f32*)(p + 0x288) = lbl_80541D88;
    *(f32*)(p + 0x284) = lbl_80541D88;
    *(u8*)(p + 0x27f) = (*(u32*)(p + 0x90) >> 24) & 1;
    *(s32*)(p + 0x270) = 0;
    *(f32*)(p + 0x298) = lbl_80541D88;
    *(f32*)(p + 0x294) = lbl_80541D88;
    *(f32*)(p + 0x290) = lbl_80541D88;
    *(s32*)(p + 0x274) = 0;
    *(JGeometry::TVec3f*)(p + 0x29c) = *(JGeometry::TVec3f*)(p + 0xc);
    *(u8*)(p + 0x283) = 0;

    switch (*(u16*)(p + 0x94)) {
    case 0:
        *(s32*)(p + 0xb0) = 0x20000;
        if (*(s32*)(p + 0x268) >= 4) {
            *(s32*)(p + 0xb0) = 0x2000a;
        }
        room = *(s32*)(p + 0x4);
        {
            u8* tbl = (u8*)fn_802D6A9C() + 0x10000;
            if (tbl[room + 0x31df] == 1) {
                *(f32*)(p + 0x10) = *(f32*)(p + 0x10) - *(f32*)(p + 0x14);
                *(f32*)(p + 0x14) = lbl_80541D88;
                *(f32*)(p + 0x40) = *(f32*)(p + 0x40) - *(f32*)(p + 0x44);
                *(f32*)(p + 0x44) = lbl_80541D88;
                *(s32*)(p + 0x230) = 0;
                break;
            }
        }
        /* fall through */
    case 1:
        *(s32*)(p + 0x230) = 0xb;
        break;
    case 2:
        *(s32*)(p + 0x24c) = 0x12c;
        *(f32*)(p + 0x80) = lbl_80541E1C;
        *(f32*)(p + 0x84) = lbl_80541E1C;
        *(f32*)(p + 0x88) = lbl_80541D98;
        *(f32*)(p + 0x8c) = lbl_80541D98;
        *(f32*)(p + 0x14) = *(f32*)(p + 0x14) + lbl_80541D98;
        *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + lbl_80541D98;
        *(s32*)(p + 0x230) = 2;
        break;
    case 3:
        *(s32*)(p + 0xb0) = 0x20000;
        if (*(s32*)(p + 0x268) >= 4) {
            *(s32*)(p + 0xb0) = 0x2000a;
        }
        room = *(s32*)(p + 0x4);
        {
            u8* tbl = (u8*)fn_802D6A9C() + 0x10000;
            if (tbl[room + 0x31df] == 1) {
                *(f32*)(p + 0x40) = lbl_80541DB4;
                *(s32*)(p + 0x24c) = 0x30c;
                *(u8*)(p + 0x27d) = 1;
                *(s32*)(p + 0x230) = 9;
                break;
            }
        }
        /* fall through */
    case 4:
        *(s32*)(p + 0x248) = 2;
        if (((ActorSlot13*)this_)->slot13() != 0) {
            detach__5ActorFv(this_);
            return;
        }
        *(s32*)(p + 0x24c) = 0;
        *(s32*)(p + 0x230) = 8;
        *(u8*)(p + 0x280) = 1;
        break;
    case 5:
        *(f32*)(p + 0x238) = lbl_80541D88;
        *(u8*)(p + 0x280) = 1;
        *(s32*)(p + 0x274) = 0xa;
        if (((ActorSlot13*)this_)->slot13() != 0) {
            if (*(u16*)(p + 0x94) == 0x1a) {
                *(f32*)(p + 0x238) = lbl_80541D90;
                *(s32*)(p + 0x230) = 0xa;
                break;
            }
        }
        /* fall through */
    case 6:
        if (((ActorSlot13*)this_)->slot13() != 0) {
            detach__5ActorFv(this_);
            return;
        }
        *(f32*)(p + 0x14) = lbl_80541E30;
        *(u8*)(p + 0x280) = 1;
        *(s32*)(p + 0x230) = 0xc;
        break;
    case 7:
        if (*(u32*)(p + 0x198) & 1) {
            *(s16*)(p + 0x242) = (s16)(lbl_80541E38 - lbl_80541E34 * rupyRand01());
        } else {
            *(s16*)(p + 0x242) = (s16)(rupyRand01() * lbl_80541E34 + lbl_80541E34);
        }
        if (((u8*)lbl_8053AAF8)[0x7e] == 1) {
            *(s32*)(p + 0x24c) = 0x3f2;
        } else {
            *(s32*)(p + 0x24c) = 0x33e;
        }
        *(s32*)(p + 0x230) = 0xd;
        break;
    case 8:
        *(f32*)(p + 0x14) = lbl_80541E30;
        *(s32*)(p + 0x230) = 0xe;
        if (*(s32*)(p + 0x268) >= 4) {
            room = *(s32*)(p + 0x4);
            if (room >= 8) {
                Actor_CreateByID(fn_801F856C(), 0x52534e50, room, p + 0xc, 0, -1, -1);
            }
        }
        break;
    case 9:
        *(s32*)(p + 0x24c) = 0x30c;
        *(u8*)(p + 0x27d) = 1;
        *(s32*)(p + 0x230) = 9;
        break;
    case 10:
        *(s32*)(p + 0x274) = 0xa;
        *(s32*)(p + 0x24c) = 0x30c;
        *(u8*)(p + 0x27d) = 1;
        *(s32*)(p + 0x230) = 9;
        break;
    case 11:
        if (((u8*)lbl_8053AAF8)[0x7e] == 1) {
            *(s32*)(p + 0x24c) = 0x3d9;
        } else {
            *(s32*)(p + 0x24c) = 0x325;
        }
        *(s32*)(p + 0x274) = 0xa;
        room = *(s32*)(p + 0x4);
        {
            u8* tbl = (u8*)fn_802D6A9C() + 0x10000;
            if (tbl[room + 0x31df] == 1) {
                *(f32*)(p + 0x10) = *(f32*)(p + 0x10) - *(f32*)(p + 0x14);
                *(f32*)(p + 0x14) = lbl_80541D88;
                *(f32*)(p + 0x40) = *(f32*)(p + 0x40) - *(f32*)(p + 0x44);
                *(f32*)(p + 0x44) = lbl_80541D88;
            }
        }
        *(s32*)(p + 0x230) = 0xf;
        break;
    case 0x26:
        break;
    default:
        break;
    }

    if (*(s32*)(p + 0x278) > 0) {
        *(s32*)(p + 0x234) = *(s32*)(p + 0x230);
        *(s32*)(p + 0x230) = 0x11;
    }
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        *(u8*)(p + 0x194) = 1;
    } else {
        detach__5ActorFv(this_);
    }
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
