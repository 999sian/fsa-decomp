// Game TU 801C9AF8-801CB270 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" bool fn_801CAED4(void* thisObj, s32 value) {
	s32 v = *(s32*)((char*)thisObj + 0x560);
	return v != 4 && v != value;
}

extern "C" u8 v17__5ActorFv(void* this_, s32 room, const f32* pos);
extern const f32 lbl_8053EF38;

static inline u8 tuCheckAt(void* this_, s32 room, const f32* pos, f32 y, f32 x) {
    f32 z = pos[2];
    JGeometry::TVec3f v(x, y, z);
    return v17__5ActorFv(this_, room, &v.x);
}

// near-match (98%): float register assignment differs
extern "C" BOOL fn_801CAEF4(void* this_, const f32* pos, s32 room) {
    BOOL r = FALSE;
    if (v17__5ActorFv(this_, room, pos)
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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
