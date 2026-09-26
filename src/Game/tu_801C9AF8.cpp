// Game TU 801C9AF8-801CB270 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" bool fn_801CAED4(void* thisObj, s32 value) {
	s32 v = *(s32*)((char*)thisObj + 0x560);
	return v != 4 && v != value;
}

extern "C" u8 v17__5ActorFiPf(void* this_, s32 room, const f32* pos);
extern const f32 lbl_8053EF38;

static inline u8 tuCheckAt(void* this_, s32 room, const f32* pos, f32 y, f32 x) {
    f32 z = pos[2];
    JGeometry::TVec3f v(x, y, z);
    return v17__5ActorFiPf(this_, room, &v.x);
}

// near-match (98%): float register assignment differs
extern "C" BOOL fn_801CAEF4(void* this_, const f32* pos, s32 room) {
    BOOL r = FALSE;
    if (v17__5ActorFiPf(this_, room, pos)
        || tuCheckAt(this_, room, pos, pos[1] - lbl_8053EF38, pos[0] - lbl_8053EF38)
        || tuCheckAt(this_, room, pos, pos[1] - lbl_8053EF38, lbl_8053EF38 + pos[0])
        || tuCheckAt(this_, room, pos, lbl_8053EF38 + pos[1], pos[0] - lbl_8053EF38)
        || tuCheckAt(this_, room, pos, lbl_8053EF38 + pos[1], lbl_8053EF38 + pos[0])) {
        r = TRUE;
    }
    return r;
}

extern const f32 lbl_8053EF20;
extern const f32 lbl_8053EF2C;
extern "C" u8 fn_801C53C4(void* p);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F82CC(void* mgr, void* self, u8 room, f32 r);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern "C" u8 fn_801F37AC(void* p, s32 a, JGeometry::TVec3f* d, s32 b, s32 c, s32 e);
extern "C" void fn_801C3B7C(void* p, s32 st);

extern "C" u8 fn_801CA0F8(char* p) {
    if (*(f32*)(p + 0x68) - *(f32*)(p + 0x60) <= lbl_8053EF20
        || *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) <= lbl_8053EF20
        || fn_801C53C4(p)) {
        return 0;
    }
    u8 r = 0;
    s32 id = fn_801F82CC(fn_801F856C(), p, *(u8*)(p + 0x195), lbl_8053EF2C);
    if (id >= 0 && id != *(s32*)(p + 0x198)) {
        char* a = fn_801F666C(fn_801F856C(), id);
        if (a != 0) {
            switch (*(s32*)(a + 0x1a0)) {
            case 'SWBM':
            case 'FLME':
                return 0;
            }
            JGeometry::TVec3f d(*(JGeometry::TVec3f*)(p + 0xc));
            d.sub(*(JGeometry::TVec3f*)(a + 0x3c));
            r = fn_801F37AC(p, 0, &d, 0, *(s32*)(a + 0x168), *(s32*)(a + 0x110));
            if (r) {
                *(u8*)(a + 0x164) = 1;
                if (*(s32*)(p + 0x248) == 0x10) {
                    *(u32*)(p + 0x230) |= 0x800000;
                } else {
                    fn_801C3B7C(p, 0x10);
                }
            }
        }
    }
    return r;
}

struct HitRectList;
struct HitRectMgr {
    u8 cur;
    u8 other;
    u8 pad[2];
    u8 lists[2][0x784];
};
extern "C" HitRectMgr* fn_8020D58C(void);
extern "C" bool fn_8020D6AC(void* l, s32 kind, const JGeometry::TVec3f& pos, s32 exclude, const u32* names);
extern "C" u16 fn_8022461C(JGeometry::TVec3f* pos, s32 room);
extern "C" u16 fn_80226850(JGeometry::TVec3f* pos, s32 room);
extern "C" u8 fn_802265DC(JGeometry::TVec3f* pos, s32 room, s32 zero);
extern const u32 lbl_8053EF18[2];
extern "C" void* fn_802D6A9C(void);

extern "C" u8 fn_801C9AF8(char* p, s32 room, const JGeometry::TVec3f* in) {
    JGeometry::TVec3f pos(*in);
    u8* cfg = (u8*)fn_802D6A9C() + 0x10000;
    if (cfg[room + 0x31df]) {
        pos.y -= pos.z;
        pos.z = lbl_8053EF20;
    }
    u8 ok = 0;
    if (pos.z <= lbl_8053EF20) {
        switch (*(s32*)(p + 0x248)) {
        case 0x11:
        case 0x17:
            ok = 1;
            break;
        }
    }
    if (ok) {
        switch (fn_8022461C(&pos, room)) {
        case 0x27:
        case 0x28:
        case 0x29:
        case 0x2a:
        case 0x2b:
            return 0;
        case 3:
            if (fn_80226850(&pos, room) == 0x7a) {
                return 0;
            }
            break;
        case 1:
            switch (fn_80226850(&pos, room)) {
            case 0x9b:
            case 0x9c:
            case 0x322:
            case 0x323:
                return 0;
            }
            break;
        }
    }
    u8 r = 1;
    if (!fn_802265DC(&pos, room, 0)) {
        s32 self = *(s32*)(p + 0x198);
        HitRectMgr* m = fn_8020D58C();
        if (!fn_8020D6AC(m->lists[m->other], room, pos, self, lbl_8053EF18)) {
            r = 0;
        }
    }
    return r;
}

extern const u8 lbl_8053EFC0;
extern const f32 lbl_8053EF24;
extern const f32 lbl_8053EF28;
extern "C" u8 fn_801F2618(void* p, void* a, u8 b);
extern "C" void fn_801CE800(void* p);

extern "C" u8 fn_801C9CB0(char* p) {
    s32 room;
    u8 flat;
    u8 r = 0;
    if (!(*(u32*)(p + 0x230) & 0x1000)
        && *(f32*)(p + 0x88) - *(f32*)(p + 0x80) > lbl_8053EF20
        && *(f32*)(p + 0x8c) - *(f32*)(p + 0x84) > lbl_8053EF20) {
        JGeometry::TVec3f prev(*(JGeometry::TVec3f*)(p + 0x18));
        JGeometry::TVec3f cur(*(JGeometry::TVec3f*)(p + 0xc));
        room = *(s32*)(p + 0x4);
        u8* cfg = (u8*)fn_802D6A9C() + 0x10000;
        flat = cfg[room + 0x31df];
        u8 adj = 0;
        if (*(s32*)(p + 0x248) == 0x1c) {
            bool above = !(*(f32*)(p + 0x14) <= lbl_8053EF20);
            if (above && flat) {
                adj = 1;
                *(f32*)(p + 0x1c) = *(f32*)(p + 0x1c) - *(f32*)(p + 0x20);
                *(f32*)(p + 0x20) = lbl_8053EF20;
                *(f32*)(p + 0x10) = *(f32*)(p + 0x10) - *(f32*)(p + 0x14);
                *(f32*)(p + 0x14) = lbl_8053EF20;
            }
        }
        u8 hit = fn_801F2618(p, p + 0x264, lbl_8053EFC0);
        r = hit;
        if (adj) {
            ((JGeometry::TVec3f*)(p + 0x18))->set(prev.x, prev.y, prev.z);
            if (!hit) {
                ((JGeometry::TVec3f*)(p + 0xc))->set(cur.x, cur.y, cur.z);
            } else {
                *(f32*)(p + 0x14) = cur.z - (*(f32*)(p + 0x10) - (cur.y - cur.z));
                *(f32*)(p + 0x10) = cur.y;
                fn_801CE800(p);
            }
        } else if (hit && flat && !(*(u32*)(p + 0x230) & 0x8) && *(f32*)(p + 0x14) <= lbl_8053EF20) {
            if (__fabs(*(f32*)(p + 0x268) - lbl_8053EF24) < lbl_8053EF28
                && __fabs(*(f32*)(p + 0x10) - *(f32*)(p + 0x1c)) < lbl_8053EF28) {
                *(f32*)(p + 0x14) = lbl_8053EF20;
                *(f32*)(p + 0x44) = lbl_8053EF20;
                *(u32*)(p + 0x230) |= 0x10;
            }
        }
    }
    return r;
}

extern "C" void fn_801F317C(void* p, void* box);
extern "C" s32 fn_8023AE34(void* box, s32 room, void* info);
extern "C" s32 fn_8023AA18(void* box, s32 room, void* info);
extern "C" s32 fn_8023AC74(void* box, s32 room, void* info);
extern "C" s32 fn_8023AD54(void* box, s32 room, void* info);
extern "C" u8 fn_801CC820(s32 idx, JGeometry::TVec3f* off);
extern "C" u8 fn_801CC538(s32 idx, void* info, JGeometry::TVec3f* out, s32* id);
extern "C" void fn_801CC640(s32 idx, s32* id, JGeometry::TVec3f* off);
extern "C" JGeometry::TVec3f* fn_8023E724(s32 idx);

struct TuBox { f32 v[4]; };

extern "C" u8 fn_801C9EB8(char* p) {
    if (*(f32*)(p + 0x78) - *(f32*)(p + 0x70) <= lbl_8053EF20
        || *(f32*)(p + 0x7c) - *(f32*)(p + 0x74) <= lbl_8053EF20
        || fn_801C53C4(p)) {
        return 0;
    }
    s32 idx;
    s32 id = -1;
    u32 info[2];
    JGeometry::TVec3f alt;
    JGeometry::TVec3f off;
    TuBox box;
    off.set(lbl_8053EF20, lbl_8053EF20, lbl_8053EF20);
    u8 useOff = 0;
    u8 isB = 0;
    u8 isC = 0;
    fn_801F317C(p, &box);
    idx = fn_8023AE34(&box, *(s32*)(p + 0x4), info);
    if (idx >= 0) {
        useOff = fn_801CC820(idx, &off);
    } else if ((idx = fn_8023AA18(&box, *(s32*)(p + 0x4), info)) >= 0) {
        isB = 1;
    } else if ((idx = fn_8023AC74(&box, *(s32*)(p + 0x4), info)) >= 0) {
        isC = fn_801CC538(idx, info, &alt, &id);
    } else if ((idx = fn_8023AD54(&box, *(s32*)(p + 0x4), info)) >= 0) {
        fn_801CC640(idx, &id, &off);
    }
    u8 r = 0;
    if (idx >= 0) {
        JGeometry::TVec3f d(*fn_8023E724(idx));
        s32 mode = 0;
        if (isB) {
            mode = 4;
        } else if (isC) {
            d.set(alt);
        } else {
            d.set(*(JGeometry::TVec3f*)(p + 0xc) - off);
            if (useOff) {
                mode = 3;
            }
        }
        r = fn_801F37AC(p, 0, &d, 0, mode, idx);
        if (r) {
            if (*(s32*)(p + 0x248) == 0x10) {
                *(u32*)(p + 0x230) |= 0x800000;
            } else {
                fn_801C3B7C(p, 0x10);
            }
        }
    }
    return r;
}

extern const f32 lbl_8053EF34;
extern "C" u8 fn_8021693C(void* box, u8 mask);
extern "C" void fn_802379E4(s32 idx, void* pos);
extern "C" u8 fn_801F2740(void* p, s32 a);
extern "C" void fn_801F3128(void* p, JGeometry::TVec2<f32>* out);
extern "C" u8 fn_801F329C(void* p, s32 idx);
extern "C" void fn_801CD0D0(JGeometry::TVec3f* in, JGeometry::TVec2<f32>* out);
extern "C" void fn_80238548(s32 idx, s32 a, JGeometry::TVec2<f32>* pos, s32 b);

static inline JGeometry::TVec2<f32> tuProject(const JGeometry::TVec2<f32>& pos) {
    JGeometry::TVec3f v(pos.x, pos.y, lbl_8053EF20);
    JGeometry::TVec2<f32> t;
    fn_801CD0D0(&v, &t);
    return t;
}

// near-match (~96%): stack slot order and loop register allocation differ
extern "C" u8 fn_801CA274(char* p) {
    u8 r = 0;
    if (*(s32*)(p + 0x564) != 3) {
        u8 mask = (*(s32*)(p + 0x560) == 4) ? (u8)0xf : (u8)(1 << *(s32*)(p + 0x560));
        if (*(f32*)(p + 0x534) - *(f32*)(p + 0x52c) > lbl_8053EF20
            && *(f32*)(p + 0x538) - *(f32*)(p + 0x530) > lbl_8053EF20) {
            u8 hit = fn_8021693C(p + 0x528, mask);
            if (hit) {
                u8 done = 0;
                for (s32 i = 0; i < 4; i++) {
                    s32 bit = 1 << i;
                    if (hit & bit) {
                        fn_802379E4(i, p + 0xc);
                        if (!done) {
                            done = 1;
                            JGeometry::TVec2<f32> d;
                            d.y = *(f32*)(p + 0x10) - fn_8023E724(i)->y;
                            d.x = *(f32*)(p + 0xc) - fn_8023E724(i)->x;
                            d.normalize();
                            d.scale(lbl_8053EF34);
                            *(f32*)(p + 0x3c) = d.x;
                            *(f32*)(p + 0x40) = d.y;
                            fn_801C3B7C(p, 0x20);
                            *(u32*)(p + 0x230) |= 0x80000;
                        }
                        mask &= ~bit;
                    }
                }
            }
            f32 s0 = *(f32*)(p + 0x60);
            f32 s1 = *(f32*)(p + 0x64);
            f32 s2 = *(f32*)(p + 0x68);
            f32 s3 = *(f32*)(p + 0x6c);
            *(f32*)(p + 0x60) = *(f32*)(p + 0x52c);
            *(f32*)(p + 0x64) = *(f32*)(p + 0x530);
            *(f32*)(p + 0x68) = *(f32*)(p + 0x534);
            *(f32*)(p + 0x6c) = *(f32*)(p + 0x538);
            u8 res;
            if (mask == 0) {
                res = 0;
            } else {
                res = fn_801F2740(p, -1);
                if (res) {
                    JGeometry::TVec2<f32> pos;
                    fn_801F3128(p, &pos);
                    for (s32 i = 0; i < 4; i++) {
                        s32 bit = 1 << i;
                        if (res & bit) {
                            if (mask & bit) {
                                JGeometry::TVec2<f32> out;
                                if (fn_801F329C(p, i)) {
                                    out = tuProject(pos);
                                } else {
                                    out.set(pos);
                                }
                                fn_80238548(i, *(s32*)(p + 0x114), &out, 2);
                            } else {
                                res &= ~bit;
                            }
                        }
                    }
                }
            }
            *(f32*)(p + 0x60) = s0;
            *(f32*)(p + 0x64) = s1;
            *(f32*)(p + 0x68) = s2;
            *(f32*)(p + 0x6c) = s3;
            r = res;
        }
    }
    return r;
}

extern const f32 lbl_8053EF24;
extern const f32 lbl_8053EF38;
extern const f32 lbl_8053EF3C;
extern const f32 lbl_8053EF40;
extern const f32 lbl_8053EF44;
extern const f32 lbl_8053EF48;
extern const f32 lbl_8053EF4C;
extern const f32 lbl_8053EF50;
extern const f32 lbl_8053EF54;
extern "C" s32 fn_801F285C(void* self, JGeometry::TVec2<f32>* hit, s32* kind, s32 c, s32 idx);
extern "C" s32 fn_8023B6CC(s32 idx);
extern "C" void fn_80237948(s32 idx, void* pos);
extern "C" u8 fn_801EAC20(void* obj, s32 idx);
extern "C" void fn_80230FD0(s32 idx, u32 flag);
extern "C" void fn_801CB4A4(s32 room, JGeometry::TVec3f* pos, s32 a, s32 b);
extern "C" s32 fn_801D0020(void* self, void* pos, s32 idx, s32 a);
extern "C" void fn_8021CDE4(void* self, s32 a);
extern "C" u8 fn_8021D020(void* self);
extern "C" void fn_801F0E34(void* self, u32 se, s32 b);

static inline u8 tuOtherPlayer(char* p, s32 i) {
    s32 w = *(s32*)(p + 0x560);
    u8 r = 0;
    if (w != 4 && w != i) {
        r = 1;
    }
    return r;
}

static inline void tuPushAway(char* p, s32 who) {
    f32 dy = *(f32*)(p + 0x10) - fn_8023E724(who)->y;
    f32 dx = *(f32*)(p + 0xc) - fn_8023E724(who)->x;
    JGeometry::TVec2<f32> d;
    d.x = dx;
    d.y = dy;
    d.normalize();
    d.scale(lbl_8053EF34);
    *(f32*)(p + 0x3c) = d.x;
    *(f32*)(p + 0x40) = d.y;
}

// near-match (98.8%): register coloring in the last two player loops differs
extern "C" u8 fn_801CA564(char* p) {
    switch (*(s32*)(p + 0x248)) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13:
    case 0x17: case 0x18: case 0x19: case 0x1a:
    case 0x29: case 0x2a: case 0x2b: case 0x2c: case 0x2d: case 0x2f:
        return 0;
    }
    s32 who;
    f32 hx, hy;
    u8 found;
    JGeometry::TVec2<f32> hit;
    JGeometry::TVec3f vel;
    JGeometry::TVec3f d;
    JGeometry::TVec3f fx1;
    JGeometry::TVec3f fx2;
    s32 kind;
    u8 held = fn_801C53C4(p);
    if (*(f32*)(p + 0x534) - *(f32*)(p + 0x52c) > lbl_8053EF20
        && *(f32*)(p + 0x538) - *(f32*)(p + 0x530) > lbl_8053EF20) {
        f32 s0 = *(f32*)(p + 0x60);
        f32 s1 = *(f32*)(p + 0x64);
        f32 s2 = *(f32*)(p + 0x68);
        f32 s3 = *(f32*)(p + 0x6c);
        found = 0;
        *(f32*)(p + 0x60) = *(f32*)(p + 0x52c);
        *(f32*)(p + 0x64) = *(f32*)(p + 0x530);
        *(f32*)(p + 0x68) = *(f32*)(p + 0x534);
        *(f32*)(p + 0x6c) = *(f32*)(p + 0x538);
        for (s32 i = 0; i < 4; i++) {
            if (i == fn_801F285C(p, &hit, 0, 1, i) && !tuOtherPlayer(p, i)) {
                hx = hit.x;
                hy = hit.y;
                found = 1;
                *(s32*)(p + 0x338) = i;
                fn_8023B6CC(i);
                fn_80237948(i, p + 0xc);
            }
        }
        *(f32*)(p + 0x60) = s0;
        *(f32*)(p + 0x64) = s1;
        *(f32*)(p + 0x68) = s2;
        *(f32*)(p + 0x6c) = s3;
        if (found) {
            who = *(s32*)(p + 0x338);
            tuPushAway(p, who);
            if (fn_801EAC20(p + 0x1dc, who)) {
                fn_80230FD0(who, 0x20002);
                fx1.set(hx, hy, lbl_8053EF20);
                fn_801CB4A4(*(s32*)(p + 0x4), &fx1, 0, 0);
            }
            fn_801C3B7C(p, 0x20);
            *(u32*)(p + 0x230) |= 0x80000;
            return 0;
        }
    }
    f32 x0, y0, x1, y1;
    switch (*(s32*)(p + 0x248)) {
    case 0xe: case 0xf: case 0x11: case 0x1b: case 0x20:
    case 0x22: case 0x23: case 0x24: case 0x25: case 0x26: case 0x27: case 0x28:
        switch (*(s32*)(p + 0x98)) {
        case 0:
            x0 = lbl_8053EF38;
            y0 = lbl_8053EF3C;
            x1 = lbl_8053EF40;
            y1 = lbl_8053EF44;
            break;
        case 1:
            x0 = lbl_8053EF48;
            y0 = lbl_8053EF3C;
            x1 = lbl_8053EF4C;
            y1 = lbl_8053EF44;
            break;
        case 2:
            x0 = lbl_8053EF3C;
            y0 = lbl_8053EF38;
            x1 = lbl_8053EF44;
            y1 = lbl_8053EF40;
            break;
        case 3:
            x0 = lbl_8053EF3C;
            y0 = lbl_8053EF48;
            x1 = lbl_8053EF44;
            y1 = lbl_8053EF4C;
            break;
        }
        break;
    default:
        y0 = x0 = lbl_8053EF50;
        y1 = x1 = lbl_8053EF24;
        break;
    }
    if (x1 - x0 > lbl_8053EF20 && y1 - y0 > lbl_8053EF20) {
        f32 s0 = *(f32*)(p + 0x60);
        f32 s1 = *(f32*)(p + 0x64);
        f32 s2 = *(f32*)(p + 0x68);
        f32 s3 = *(f32*)(p + 0x6c);
        found = 0;
        *(f32*)(p + 0x60) = x0;
        *(f32*)(p + 0x64) = y0;
        *(f32*)(p + 0x68) = x1;
        *(f32*)(p + 0x6c) = y1;
        for (s32 i = 0; i < 4; i++) {
            if (i == fn_801F285C(p, &hit, 0, 1, i) && *(s32*)(p + 0x98) == fn_801D0020(p, p + 0xc, i, 0)) {
                if (held) {
                    fn_8023B6CC(i);
                fn_80237948(i, p + 0xc);
                } else if (!tuOtherPlayer(p, i)) {
                    hx = hit.x;
                    hy = hit.y;
                    found = 1;
                    *(s32*)(p + 0x338) = i;
                    fn_8023B6CC(i);
                    fn_802379E4(i, p + 0xc);
                }
            }
        }
        *(f32*)(p + 0x60) = s0;
        *(f32*)(p + 0x64) = s1;
        *(f32*)(p + 0x68) = s2;
        *(f32*)(p + 0x6c) = s3;
        if (found) {
            switch (*(s32*)(p + 0x98)) {
            case 0:
                hx = lbl_8053EF44 + *(f32*)(p + 0xc);
                break;
            case 1:
                hx = *(f32*)(p + 0xc) - lbl_8053EF44;
                break;
            case 2:
                hy = lbl_8053EF44 + *(f32*)(p + 0x10);
                break;
            case 3:
                hy = *(f32*)(p + 0x10) - lbl_8053EF44;
                break;
            }
            who = *(s32*)(p + 0x338);
            tuPushAway(p, who);
            if (fn_801EAC20(p + 0x1dc, who)) {
                fn_801F0E34(p, 0x400d1, 0);
                fx2.set(hx, hy, lbl_8053EF20);
                fn_801CB4A4(*(s32*)(p + 0x4), &fx2, 0, 0);
            }
            fn_801C3B7C(p, 0x20);
            return 0;
        }
    }
    found = 0;
    if (*(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053EF20
        && *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > lbl_8053EF20) {
        u8 other = 0;
        for (s32 i = 0; i < 4; i++) {
            if (i == fn_801F285C(p, 0, 0, 1, i)) {
                if (held) {
                    fn_8023B6CC(i);
                fn_80237948(i, p + 0xc);
                } else if (tuOtherPlayer(p, i)) {
                    other = 1;
                    *(s32*)(p + 0x590) = i;
                }
            }
        }
        if (other) {
            fn_801F0E34(p, 0x400c0, 0);
            fn_801F0E34(p, 0x400c7, 0);
            fn_801C3B7C(p, 0x2a);
            if (*(s32*)(p + 0x564) == 3) {
                fn_8021CDE4(p, 2);
            }
            return 0;
        }
        if (!held) {
            vel = *(JGeometry::TVec3f*)(p + 0x3c);
            for (s32 i = 0; i < 4; i++) {
                if (i == fn_801F285C(p, 0, &kind, 1, i)) {
                    JGeometry::TVec3f* pp = fn_8023E724(i);
                    if (fn_801F37AC(p, fn_8023B6CC(i), pp, 0, kind, i)) {
                        found = 1;
                        *(s32*)(p + 0x338) = i;
                    }
                }
            }
            if (found) {
                f32 dy = *(f32*)(p + 0x10) - fn_8023E724(*(s32*)(p + 0x338))->y;
                f32 dx = *(f32*)(p + 0xc) - fn_8023E724(*(s32*)(p + 0x338))->x;
                d.set(dx, dy, lbl_8053EF20);
                d.normalize();
                *(JGeometry::TVec3f*)(p + 0x3c) = vel;
                d.scale(lbl_8053EF54);
                ((JGeometry::TVec3f*)(p + 0x3c))->add(d);
                *(f32*)(p + 0x44) = lbl_8053EF20;
                *(s32*)(p + 0xf8) = 0;
                if (fn_8021D020(p) && *(s32*)(p + 0x564) == 2) {
                    *(u32*)(p + 0x230) |= 0x4000000;
                    *(s32*)(p + 0xd8) = 0x30;
                    *(s32*)(p + 0xdc) = 0x30;
                } else {
                    *(u32*)(p + 0x230) &= ~0x4000000;
                    *(s32*)(p + 0xd8) = 0x18;
                    *(s32*)(p + 0xdc) = 0x18;
                }
                fn_801C3B7C(p, 0x21);
            }
        }
    }
    return found;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
