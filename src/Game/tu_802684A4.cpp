// TU 0x802684a4-0x8026fc20.
// SetField_0x98 from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
static inline JGeometry::TVec2<f32> playerDifferenceXY(const f32 x, const f32 y, const JGeometry::TVec2<f32>& b) {
    JGeometry::TVec2<f32> v(x, y);
    v.x -= b.x;
    v.y -= b.y;
    return v;
}

extern "C" void __dl__FPv(void*);
extern "C" s32 fn_802486A0(void*);
extern "C" bool Player_IsLinked(void*);
extern "C" void fn_802685D4(void*);
extern "C" u8 fn_80251AEC(void*, s32);
extern f32 lbl_80540228;
extern f32 lbl_80540254;
extern "C" u8* lbl_8053AAF8;
extern "C" s32 fn_8024FF84();
extern "C" u16 fn_8022461C(JGeometry::TVec3<f32>*, s32);
extern "C" void* fn_801F856C();
extern "C" void* Actor_CreateByID(void*, u32, s32, JGeometry::TVec3<f32>*, s32, s32, s32);
extern "C" void* fn_801F666C(void*, void*);
extern JGeometry::TVec3<f32> lbl_8046B998[];
extern void* lbl_804A71A8[];
extern const JGeometry::TVec3<f32> lbl_8046BAE8[];
extern "C" u8 fn_80240B84(void*);
extern "C" u8 fn_8025F448(void*);
extern "C" u8 fn_8025F590(void*);
extern "C" s32 fn_8023DE58(s32);
extern "C" s32 fn_8026FC20(void*);
extern "C" u8 fn_802DCD0C(void*);
extern "C" void fn_80269574(u8*);
extern "C" void fn_8026B81C(u8*, u16);
extern "C" void fn_8026C350(u8*, u16);
extern "C" void fn_8026E1E0(u8*);
extern "C" u8* fn_802D6A9C();
extern "C" u16 fn_802265FC(struct Vec2f*, s32);
extern "C" u16 fn_80226850(struct Vec2f*, s32);
extern "C" u8 Player_GetField_0xce8(void*);
extern "C" u8 fn_8025F418(void*);
extern "C" u8 fn_8022D75C(s32);
extern "C" u8 Player_GetField_0x454(void*);
extern "C" u8 fn_80241E28(void*, s32, void*);
extern "C" u8 fn_80240D64(void*);
extern "C" void fn_80268BC4(u8*);
extern f32 lbl_80540234;
extern f32 lbl_80540238;
extern f32 lbl_8054023C;
extern f32 lbl_80540240;
extern f32 lbl_80540244;
extern f32 lbl_80540248;
extern f32 lbl_8054022C;
extern f32 lbl_8054024C;
extern f32 lbl_80540250;

struct Vec2f {
    void set(const Vec2f& o) {
        f32 ox = o.x;
        f32 oy = o.y;
        x = ox;
        y = oy;
    }
    f32 x, y;
};

struct HitRect {
    f32 x0, y0, x1, y1;
};

struct HitRectTable {
    u8 pad0[0x3b4];
    s32 room;
    u8 pad3b8[0x5fc - 0x3b8];
    HitRect rects[80];
    u8 padAFC[0xdb0 - 0xafc];
    s32 ids[80];
    s32 hits[80];
    s32 types[80];
};


inline bool rectContains(const HitRect& r, const Vec2f* p) {
    f32 x;
    f32 y;
    bool in = false;
    if ((x = p->x) >= r.x0 && (y = p->y) >= r.y0 && x < r.x1 && y < r.y1) {
        in = true;
    }
    return in;
}

extern "C" u8 fn_802684A4(HitRectTable* t, const Vec2f* p, s32 type) {
    for (u32 i = 0; i < 80; i++) {
        if (t->ids[i] >= 0 && type == t->types[i] && rectContains(t->rects[i], p)) {
            t->hits[i] = t->ids[i];
            return 1;
        }
    }
    return 0;
}

inline s32 tableRoom(const HitRectTable* t) { return t->room; }

#pragma opt_dead_code off
extern "C" void fn_802685D4(void* thisPtr) {
    u8* p = (u8*)thisPtr;
    u16 k;
    p[0x3c1] = 0;
    p[0x3c2] = 0;
    if (Player_GetField_0xce8(p)) {
        goto move;
    }
    if (fn_8025F418(p) && p[0x1216] == 0 && *(s32*)(p + 0x1228) == 0) {
        if (fn_8022D75C(*(s32*)(p + 0xd70))) {
            goto move;
        }
        if (Player_GetField_0x454(p)) {
            goto move;
        }
        if (!fn_80241E28(p, *(s32*)(p + 0x3bc), p + 0x2c)) {
            goto move;
        }
        JGeometry::TVec2<f32> a(*(f32*)(p + 8), *(f32*)(p + 0x30));
        if (fn_802265FC((Vec2f*)&a, *(s32*)(p + 0x3b4)) == 1) {
            JGeometry::TVec2<f32> b(*(f32*)(p + 0x2c), *(f32*)(p + 0xc));
            if (fn_802265FC((Vec2f*)&b, *(s32*)(p + 0x3b4)) == 1) {
                JGeometry::TVec2<f32> d = playerDifferenceXY(*(f32*)(p + 8), *(f32*)(p + 0xc), *(JGeometry::TVec2<f32>*)(p + 0x2c));
                if (d.squared() >= 25.0f) {
                    d.normalize();
                    d.scale(lbl_80540234);
                }
                *(f32*)(p + 8) = *(f32*)(p + 0x2c) + d.x;
                *(f32*)(p + 0xc) = *(f32*)(p + 0x30) + d.y;
                goto move;
            }
        }
    }
    JGeometry::TVec2<f32> c(*(f32*)(p + 8), *(f32*)(p + 0xc));
    if (fn_802265FC((Vec2f*)&c, *(s32*)(p + 0x3b4)) == 1) {
        JGeometry::TVec2<f32> d = playerDifferenceXY(*(f32*)(p + 8), *(f32*)(p + 0xc), *(JGeometry::TVec2<f32>*)(p + 0x2c));
        if (d.squared() >= 25.0f) {
            d.normalize();
            d.scale(lbl_80540234);
        }
        *(f32*)(p + 8) = *(f32*)(p + 0x2c) + d.x;
        *(f32*)(p + 0xc) = *(f32*)(p + 0x30) + d.y;
        goto move;
    }
    JGeometry::TVec2<f32> e = playerDifferenceXY(*(f32*)(p + 8), *(f32*)(p + 0xc), *(JGeometry::TVec2<f32>*)(p + 0x2c));
    f32 sq = e.squared();
    if (!(sq >= lbl_80540238)) {
        goto move;
    }
    if (!(sq <= lbl_8054023C)) {
        goto move;
    }
    if (p[0xce8]) {
        goto move;
    }
    if (fn_80240D64(p)) {
        goto move;
    }
    e.normalize();
    e.scale(lbl_80540240);
    *(f32*)(p + 8) = *(f32*)(p + 0x2c) + e.x;
    *(f32*)(p + 0xc) = *(f32*)(p + 0x30) + e.y;
    fn_80268BC4((u8*)*(void**)(p + 0xbf0));
move:
    *(f32*)(p + 0x2c) = *(f32*)(p + 8);
    *(f32*)(p + 0x30) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x34) = *(f32*)(p + 0x10);
    *(s32*)(p + 0x3bc) = *(s32*)(p + 0x3b4);
    p[0x3c0] = 1;
    k = fn_80226850((Vec2f*)(p + 8), *(s32*)(p + 0x3b4));
    if (*(f32*)(p + 0x10) > 0.0f) {
        *(f32*)(p + 0x420) = 0.0f;
        *(f32*)(p + 0x424) = 0.0f;
        *(f32*)(p + 0x428) = 0.0f;
    } else {
        if (k == 0xa4) {
            *(f32*)(p + 0x424) = *(f32*)(p + 0x424) - lbl_80540244;
            if (*(f32*)(p + 0x424) < -0.5f) {
                *(f32*)(p + 0x424) = -0.5f;
            }
        } else if (k == 0xa5) {
            *(f32*)(p + 0x424) = *(f32*)(p + 0x424) + lbl_80540244;
            if (*(f32*)(p + 0x424) > 0.5f) {
                *(f32*)(p + 0x424) = 0.5f;
            }
        } else {
            f32 v = *(f32*)(p + 0x424);
            if (v > 0.025f) {
                *(f32*)(p + 0x424) = v - 0.025f;
            } else if (v < -0.025f) {
                *(f32*)(p + 0x424) = 0.025f + v;
            } else {
                *(f32*)(p + 0x424) = 0.0f;
            }
        }
        if (k == 0xa7) {
            *(f32*)(p + 0x420) = *(f32*)(p + 0x420) + lbl_80540244;
            if (*(f32*)(p + 0x420) > 0.5f) {
                *(f32*)(p + 0x420) = 0.5f;
            }
        } else if (k == 0xa6) {
            *(f32*)(p + 0x420) = *(f32*)(p + 0x420) - lbl_80540244;
            if (*(f32*)(p + 0x420) < -0.5f) {
                *(f32*)(p + 0x420) = -0.5f;
            }
        } else {
            f32 v = *(f32*)(p + 0x420);
            if (v > 0.025f) {
                *(f32*)(p + 0x420) = v - 0.025f;
            } else if (v < -0.025f) {
                *(f32*)(p + 0x420) = v + 0.025f;
            } else {
                *(f32*)(p + 0x420) = 0.0f;
            }
        }
    }
    ((JGeometry::TVec3<f32>*)(p + 8))->add(*(JGeometry::TVec3<f32>*)(p + 0x420));
}
#pragma opt_dead_code reset
extern "C" void fn_80268B3C(u8* p) {
    if (fn_802486A0(p) == 5 && Player_IsLinked(p)) {
        fn_802685D4(p);
    } else {
        f32 saved = *(f32*)(p + 0x10);
        *(f32*)(p + 0x10) = lbl_80540228;
        fn_802685D4(p);
        if (lbl_80540228 == *(f32*)(p + 0x10)) {
            *(f32*)(p + 0x10) = saved;
        }
    }
}

static inline void clearProbeFlags(u8* p) {
    p[0x9a] = 0;
    *(s32*)(p + 0x1c) = 0;
    for (s32 i = 0; i < 8; i++) {
        p[0x20+i] = 0; p[0x28+i] = 0; p[0x38+i] = 0;
        p[0x50+i] = 0; p[0x58+i] = 0; p[0x60+i] = 0;
        p[0x68+i] = 0; p[0x70+i] = 0; p[0x78+i] = 0;
        p[0x80+i] = 0; p[0x88+i] = 0;
    }
}
static inline HitRect* roomRect(s32 room) {
    u8* base = fn_802D6A9C();
    if (room < 8) return (HitRect*)(base + 0xcc);
    return (HitRect*)(base + 0xdc);
}
extern "C" void fn_80268BC4(u8* p) {
    JGeometry::TVec2<f32> v;
    s32 i;
    u32 j;
    for (i = 0; i < 8; i++) {
        p[0x40 + i] = p[0x48 + i];
        p[0x48 + i] = 0;
        p[0x30 + i] = 0;
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 16; j++) {
            *(s32*)(*(u8**)(p + 4) + i * 0x40 + j * 4 + 0xef0) = -1;
        }
    }
    p[0xb5] = p[0xb4]; p[0xb4] = 0; p[0xb6] = 0; p[0xb7] = 0; p[0xb8] = 0; p[0xb9] = 0; p[0xba] = 0;
    *(s32*)(p + 0xac) = 0;
    f32 oldX = *(f32*)(*(u8**)(p + 4) + 8);
    f32 oldY = *(f32*)(*(u8**)(p + 4) + 0xc);
    if (fn_80240B84(*(void**)(p + 4))) {
        return;
    }
    if (fn_8025F448(*(void**)(p + 4))) {
        return;
    }
    *(s32*)(p + 0xb0) = 0;
    do {
    clearProbeFlags(p);
    *(s32*)(p + 0xb0) = *(s32*)(p + 0xb0) + 1;
    for (int k = 0; k < 8; k++) {
        const f32* src = &lbl_8046BAE8[k].x;
        f32 x = *src++;
        f32 y = *src++;
        *(f32*)(p + 8) = x;
        f32 z = *src;
        *(f32*)(p + 0xc) = y;
        *(f32*)(p + 0x10) = z;
        *(s32*)(p + 0x1c) = k;
        ((JGeometry::TVec3<f32>*)(p + 8))->add(*(JGeometry::TVec3<f32>*)(*(u8**)(p + 4) + 8));
        u16 r27 = fn_8022461C((JGeometry::TVec3<f32>*)(p + 8), *(s32*)(*(u8**)(p + 4) + 0x3b4));
        if (fn_8025F590(*(void**)(p + 4)) && *(s32*)(*(u8**)(p + 4) + 0x3b4) == 8 && fn_8023DE58(*(s32*)(*(u8**)(p + 4) + 0xd70)) < 8) {
            JGeometry::TVec3<f32> saved = *(JGeometry::TVec3<f32>*)(p + 8);
            s32 room = *(s32*)(*(u8**)(p + 4) + 0x3b4);
            HitRect* o = roomRect(room);
            (*(f32*)(p + 8)) -= o->x0;
            room = *(s32*)(*(u8**)(p + 4) + 0x3b4);
            o = roomRect(room);
            (*(f32*)(p + 0xc)) -= o->y0;
            room = fn_8023DE58(*(s32*)(*(u8**)(p + 4) + 0xd70));
            o = roomRect(room);
            (*(f32*)(p + 8)) += o->x0;
            room = fn_8023DE58(*(s32*)(*(u8**)(p + 4) + 0xd70));
            o = roomRect(room);
            (*(f32*)(p + 0xc)) += o->y0;
            room = fn_8023DE58(*(s32*)(*(u8**)(p + 4) + 0xd70));
            if ((u8)fn_802684A4((HitRectTable*)*(u8**)(p + 4), (Vec2f*)(p + 8), room)) {
                p[*(s32*)(p + 0x1c) + 0x28] = 1;
            } else {
                fn_8026B81C(p, fn_8022461C((JGeometry::TVec3<f32>*)(p + 8), fn_8023DE58(*(s32*)(*(u8**)(p + 4) + 0xd70))));
            }
            *(JGeometry::TVec3<f32>*)(p + 8) = saved;
        }
        HitRectTable* table = (HitRectTable*)*(u8**)(p + 4);
        if ((u8)fn_802684A4(table, (Vec2f*)(p + 8), tableRoom(table))) {
            p[*(s32*)(p + 0x1c) + 0x28] = 1;
        } else if (fn_8026FC20(*(void**)(p + 4)) <= 0 && !fn_802DCD0C(fn_802D6A9C())) {
            s32 room = *(s32*)(*(u8**)(p + 4) + 0x3b4);
            u8* base = fn_802D6A9C();
            HitRect* rect = room < 8 ? (HitRect*)(base + 0xcc) : (HitRect*)(base + 0xdc);
            if (!rectContains(*rect, (Vec2f*)(p + 8))) p[*(s32*)(p + 0x1c) + 0x38] = 1;
            else goto process;
        } else {
        process:
            fn_8026C350(p, r27);
        }
    }
    fn_80269574(p);
    if (*(s32*)(p + 0xb0) <= 1) {
        fn_8026E1E0(p);
    }
    } while (p[0x9a] == 1 && *(s32*)(p + 0xb0) < 100);
    u8 hit = 0;
    if (p[0x98] || p[0x99]) hit = 1;
    if (!hit) {
        u8* pl = *(u8**)(p + 4);
        f32 reset = lbl_80540254;
        *(f32*)(pl + 0xc90) = reset;
        *(f32*)(pl + 0xc94) = reset;
        *(f32*)(pl + 0xc98) = reset;
    } else if (!lbl_8053AAF8[0x96]) {
        p[0x99] = p[0x98];
        p[0x98] = 0;
    }
    v.set(*(f32*)(*(u8**)(p + 4) + 8), *(f32*)(*(u8**)(p + 4) + 0xc));
    v.x -= oldX;
    v.y -= oldY;
    ((Vec2f*)(p + 0x14))->set(*(Vec2f*)&v);
}

extern "C" {

void SetField_0x98(void* thisPtr) {
	*(u8*)((char*)thisPtr + 0x98) = 1;
}

}


extern const JGeometry::TVec3<f32> lbl_8046BA88[];
extern Vec2f lbl_8046BA68[];
extern "C" s32 fn_80248778(void*);

extern "C" u8* fn_802D6A9C();

struct Obj8026942C {
    void* vtbl;
    u8* player;
};

static inline void copyIndexedVector694(const JGeometry::TVec3<f32>* table,s32 index,JGeometry::TVec3<f32>* out) {
    f32 x=table[index].x;
    f32 y=table[index].y;
    out->x=x;
    f32 z=table[index].z;
    out->y=y;
    out->z=z;
}
extern "C" void fn_8026942C(Obj8026942C* o, s32 idx, JGeometry::TVec3<f32>* out) {
    out->x = lbl_8046BA88[idx].x;
    f32 y = lbl_8046BA88[idx].y;
    out->y = y;
    out->z = lbl_8046BA88[idx].z;
    out->add(*(JGeometry::TVec3<f32>*)(o->player + 8));
}

extern "C" void fn_8026947C(Obj8026942C* o, JGeometry::TVec3<f32>* out) {
    *out = *(JGeometry::TVec3<f32>*)(o->player + 8);
    if (fn_802486A0(o->player) == 2) {
        out->x += lbl_8046BA68[fn_80248778(o->player)].x;
        s32 room = *(s32*)(o->player + 0x3b4);
        if (*(u8*)((u32)fn_802D6A9C() + 0x131df + room)) {
            out->y -= lbl_8046BA68[fn_80248778(o->player)].y;
        } else {
            out->y += lbl_8046BA68[fn_80248778(o->player)].y;
        }
    }
}

extern "C" void fn_80269574(u8* self)
{
    if (self[0x38] == 1) {
        return;
    }
    self[0x38] = 1;
}

static inline s32 tileX_8026B81C(u8* p) { return (s32)*(f32*)(p + 0xc) % 16; }
static inline s32 tileY_8026B81C(u8* p) { return (s32)*(f32*)(p + 0x8) % 16; }
static inline void setHit_8026B81C(u8* p) { p[*(s32*)(p + 0x1c) + 0x38] = 1; }

extern "C" void fn_8026B81C(u8* p, u16 k) {
    switch (k) {
    case 0x01:
        setHit_8026B81C(p);
        break;
    case 0x04:
        if (tileX_8026B81C(p) < 8) setHit_8026B81C(p);
        break;
    case 0x05:
        if (tileX_8026B81C(p) > 8) setHit_8026B81C(p);
        break;
    case 0x06:
        if (tileY_8026B81C(p) < 8) setHit_8026B81C(p);
        break;
    case 0x07:
        if (tileY_8026B81C(p) > 8) setHit_8026B81C(p);
        break;
    case 0x08:
        if (tileY_8026B81C(p) + tileX_8026B81C(p) >= 16) setHit_8026B81C(p);
        break;
    case 0x09:
        if (tileY_8026B81C(p) - tileX_8026B81C(p) < 0) setHit_8026B81C(p);
        break;
    case 0x0A:
        if (tileY_8026B81C(p) - tileX_8026B81C(p) >= 0) setHit_8026B81C(p);
        break;
    case 0x0B:
        if (tileY_8026B81C(p) + tileX_8026B81C(p) < 16) setHit_8026B81C(p);
        break;
    case 0x18:
        if (tileX_8026B81C(p) < 8 && tileY_8026B81C(p) < 8) setHit_8026B81C(p);
        break;
    case 0x19:
        if (tileX_8026B81C(p) < 8 && tileY_8026B81C(p) > 8) setHit_8026B81C(p);
        break;
    case 0x1A:
        if (tileX_8026B81C(p) > 8 && tileY_8026B81C(p) < 8) setHit_8026B81C(p);
        break;
    case 0x1B:
        if (tileX_8026B81C(p) > 8 && tileY_8026B81C(p) > 8) setHit_8026B81C(p);
        break;
    case 0x1C:
        if (tileX_8026B81C(p) > 8 || tileY_8026B81C(p) > 8) setHit_8026B81C(p);
        break;
    case 0x1D:
        if (tileX_8026B81C(p) > 8 || tileY_8026B81C(p) < 8) setHit_8026B81C(p);
        break;
    case 0x1E:
        if (tileX_8026B81C(p) < 8 || tileY_8026B81C(p) > 8) setHit_8026B81C(p);
        break;
    case 0x1F:
        if (tileX_8026B81C(p) < 8 || tileY_8026B81C(p) < 8) setHit_8026B81C(p);
        break;
    case 0x20:
        setHit_8026B81C(p);
        break;
    case 0x21:
        setHit_8026B81C(p);
        break;
    case 0x22:
        setHit_8026B81C(p);
        break;
    case 0x24:
        setHit_8026B81C(p);
        break;
    case 0x25:
        if (fn_802D6A9C()[0x171] == 0) setHit_8026B81C(p);
        break;
    case 0x26:
        if (fn_802D6A9C()[0x171] == 1) setHit_8026B81C(p);
        break;
    case 0x27: case 0x28: case 0x29: case 0x2A: case 0x2B: case 0x2C: case 0x2D: case 0x2E: case 0x2F:
        setHit_8026B81C(p);
        break;
    case 0x30:
        setHit_8026B81C(p);
        break;
    case 0x31: case 0x32: case 0x33: case 0x34:
        setHit_8026B81C(p);
        break;
    case 0x35:
        setHit_8026B81C(p);
        break;
    case 0x36:
        setHit_8026B81C(p);
        break;
    case 0x37:
        setHit_8026B81C(p);
        break;
    case 0x38:
        setHit_8026B81C(p);
        break;
    case 0x3C:
        setHit_8026B81C(p);
        break;
    case 0x3D:
        setHit_8026B81C(p);
        break;
    case 0x3E:
        setHit_8026B81C(p);
        break;
    case 0x40: case 0x41: case 0x42: case 0x43:
        setHit_8026B81C(p);
        break;
    case 0x51:
        setHit_8026B81C(p);
        break;
    case 0x52:
        setHit_8026B81C(p);
        break;
    case 0x53:
        setHit_8026B81C(p);
        break;
    case 0x58:
        if (tileY_8026B81C(p) + tileX_8026B81C(p) >= 16) setHit_8026B81C(p);
        break;
    case 0x59:
        if (tileY_8026B81C(p) - tileX_8026B81C(p) < 0) setHit_8026B81C(p);
        break;
    case 0x5A:
        if (tileY_8026B81C(p) - tileX_8026B81C(p) >= 0) setHit_8026B81C(p);
        break;
    case 0x5B:
        if (tileY_8026B81C(p) + tileX_8026B81C(p) < 16) setHit_8026B81C(p);
        break;
    case 0x5C:
        if (tileY_8026B81C(p) + tileX_8026B81C(p) >= 16) setHit_8026B81C(p);
        break;
    case 0x5D:
        if (tileY_8026B81C(p) - tileX_8026B81C(p) < 0) setHit_8026B81C(p);
        break;
    case 0x5E:
        if (tileY_8026B81C(p) - tileX_8026B81C(p) >= 0) setHit_8026B81C(p);
        break;
    case 0x5F:
        if (tileY_8026B81C(p) + tileX_8026B81C(p) < 16) setHit_8026B81C(p);
        break;
    case 0x00: case 0x02: case 0x03: case 0x60:
        break;
    }
}

extern "C" u8 fn_802413F0(void*);
extern "C" u8 fn_802DEB58(void*);
extern "C" void fn_8026E68C(u8*, u16);
extern "C" u8 fn_80241230(void*);
extern "C" u8 fn_80240670(void*);
extern "C" u8 fn_80240F14(void*);
extern "C" u8 fn_80237A80(void*);
extern "C" void fn_8026EE60(u8* p);
extern "C" void fn_8026EC88(u8* p, s32 param);
extern "C" void fn_8026F54C(u8* p);
extern "C" void fn_8026F388(u8* p);
extern "C" void fn_8026F1C4(u8* p);
extern "C" void fn_8026F000(u8* p);
extern f32 lbl_8054025C;
static inline void setHitAt_8026C350(u8* p, s32 off) { p[*(s32*)(p + 0x1c) + off] = 1; }
static inline BOOL canGrab_8026C350(u8* p) {
    void* o = *(void**)(p + 4);
    return (!fn_8025F448(o) && *(f32*)((u8*)o + 0x10) >= lbl_8054025C) || fn_80240F14(*(void**)(p + 4)) ||
           (fn_802486A0(*(void**)(p + 4)) == 4 && fn_80240670(*(void**)(p + 4)));
}
static inline void tileCheck0_8026C350(u8* p) {
    u16 t = fn_80226850((Vec2f*)(p + 8), *(s32*)(*(u8**)(p + 4) + 0x3b4));
    if (t == 6 || t == 0xb8) return;
    if (fn_80226850((Vec2f*)(p + 8), *(s32*)(*(u8**)(p + 4) + 0x3b4)) == 0x59) return;
    setHitAt_8026C350(p, 0x20);
}
static inline void ladder_8026C350(u8* p) {
    if (fn_80241230(*(void**)(p + 4))) {
        setHitAt_8026C350(p, 0x38);
    } else if (fn_802413F0(*(void**)(p + 4)) && !(*(f32*)(*(u8**)(p + 4) + 0x10) > lbl_80540254) && *(s32*)(p + 0xb0) <= 1) {
        setHitAt_8026C350(p, 0x78);
    }
}
extern "C" void fn_8026C350(u8* p, u16 param) {
    if (fn_8026FC20(*(void**)(p + 4)) >= 1) {
        if (param < 0x14 && param >= 0x10) {
            p[0xb8] = 1;
        }
        return;
    }
    u16 k = param;
    switch (k) {
    case 0x00:
        tileCheck0_8026C350(p);
        break;
    case 0x01:
        setHitAt_8026C350(p, 0x38);
        break;
    case 0x02:
        if (*(f32*)(*(u8**)(p + 4) + 0x10) > lbl_80540228) break;
        if (*(s32*)(p + 0xb0) > 1) break;
        setHitAt_8026C350(p, 0x58);
        break;
    case 0x03:
        if (!fn_802413F0(*(void**)(p + 4))) break;
        if (*(f32*)(*(u8**)(p + 4) + 0x10) > lbl_80540254) break;
        if (Player_GetField_0xce8(*(void**)(p + 4))) break;
        if (*(s32*)(p + 0xb0) > 1) break;
        setHitAt_8026C350(p, 0x68);
        break;
    case 0x04:
        if (tileX_8026B81C(p) < 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x05:
        if (tileX_8026B81C(p) > 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x06:
        if (tileY_8026B81C(p) < 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x07:
        if (tileY_8026B81C(p) > 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x08:
        if (tileY_8026B81C(p) + tileX_8026B81C(p) >= 16) setHitAt_8026C350(p, 0x38);
        break;
    case 0x09:
        if (tileY_8026B81C(p) - tileX_8026B81C(p) < 0) setHitAt_8026C350(p, 0x38);
        break;
    case 0x0A:
        if (tileY_8026B81C(p) - tileX_8026B81C(p) >= 0) setHitAt_8026C350(p, 0x38);
        break;
    case 0x0B:
        if (tileY_8026B81C(p) + tileX_8026B81C(p) < 16) setHitAt_8026C350(p, 0x38);
        break;
    case 0x0C:
        break;
    case 0x0D:
        ladder_8026C350(p);
        break;
    case 0x0E:
        if (((u8(*)())fn_802DEB58)()) {
            if (fn_802413F0(*(void**)(p + 4)) && !(*(f32*)(*(u8**)(p + 4) + 0x10) > lbl_80540254) && *(s32*)(p + 0xb0) <= 1)
                setHitAt_8026C350(p, 0x88);
        } else {
            if (fn_802413F0(*(void**)(p + 4)) && !(*(f32*)(*(u8**)(p + 4) + 0x10) > lbl_80540254) && *(s32*)(p + 0xb0) <= 1)
                setHitAt_8026C350(p, 0x88);
        }
        break;
    case 0x10: case 0x11: case 0x12: case 0x13:
        p[0xb8] = 1;
    case 0x14: case 0x15: case 0x16: case 0x17:
        fn_8026E68C(p, param);
        break;
    case 0x18:
        if (tileX_8026B81C(p) < 8 && tileY_8026B81C(p) < 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x19:
        if (tileX_8026B81C(p) < 8 && tileY_8026B81C(p) > 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x1A:
        if (tileX_8026B81C(p) > 8 && tileY_8026B81C(p) < 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x1B:
        if (tileX_8026B81C(p) > 8 && tileY_8026B81C(p) > 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x1C:
        if (tileX_8026B81C(p) > 8 || tileY_8026B81C(p) > 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x1D:
        if (tileX_8026B81C(p) > 8 || tileY_8026B81C(p) < 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x1E:
        if (tileX_8026B81C(p) < 8 || tileY_8026B81C(p) > 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x1F:
        if (tileX_8026B81C(p) < 8 || tileY_8026B81C(p) < 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x20:
        if (fn_802413F0(*(void**)(p + 4)) && *(f32*)(*(u8**)(p + 4) + 0x10) < lbl_80540254) setHitAt_8026C350(p, 0x50);
        break;
    case 0x21:
        setHitAt_8026C350(p, 0x38);
        break;
    case 0x22:
        if (fn_802D6A9C()[0x170] != 0) setHitAt_8026C350(p, 0x38);
        break;
    case 0x23:
        if (tileX_8026B81C(p) < 12) {
            if (*(f32*)(*(u8**)(p + 4) + 0x10) > lbl_80540228) break;
            if (*(s32*)(p + 0xb0) > 1) break;
            setHitAt_8026C350(p, 0x58);
        } else if (*(s32*)(p + 0x1c) == 2) {
            setHitAt_8026C350(p, 0x38);
        }
        break;
    case 0x24:
        setHitAt_8026C350(p, 0x38);
        break;
    case 0x25:
        if (fn_802D6A9C()[0x171] == 0) setHitAt_8026C350(p, 0x38);
        break;
    case 0x26:
        if (fn_802D6A9C()[0x171] == 1) setHitAt_8026C350(p, 0x38);
        break;
    case 0x27:
        if (canGrab_8026C350(p)) setHitAt_8026C350(p, 0x38);
        break;
    case 0x28:
        if (canGrab_8026C350(p) || tileX_8026B81C(p) < 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x29:
        if (canGrab_8026C350(p) || tileX_8026B81C(p) > 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x2A:
        if (canGrab_8026C350(p) || (tileY_8026B81C(p) < 8 && (*(s32*)(*(u8**)(p + 4) + 0x3dc) != 3 || *(f32*)(*(u8**)(p + 4) + 0x10) <= lbl_80540228)))
            setHitAt_8026C350(p, 0x38);
        break;
    case 0x2B:
        if (canGrab_8026C350(p) || (tileY_8026B81C(p) > 8 && (*(s32*)(*(u8**)(p + 4) + 0x3dc) != 3 || *(f32*)(*(u8**)(p + 4) + 0x10) <= lbl_80540228)))
            setHitAt_8026C350(p, 0x38);
        break;
    case 0x2C:
        if (canGrab_8026C350(p) || tileX_8026B81C(p) < 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x2D:
        if (canGrab_8026C350(p) || tileX_8026B81C(p) > 8) setHitAt_8026C350(p, 0x38);
        break;
    case 0x2E:
        if (canGrab_8026C350(p) || (tileY_8026B81C(p) < 8 && (*(s32*)(*(u8**)(p + 4) + 0x3dc) != 2 || *(f32*)(*(u8**)(p + 4) + 0x10) <= lbl_80540228)))
            setHitAt_8026C350(p, 0x38);
        break;
    case 0x2F:
        if (canGrab_8026C350(p) || (tileY_8026B81C(p) > 8 && (*(s32*)(*(u8**)(p + 4) + 0x3dc) != 2 || *(f32*)(*(u8**)(p + 4) + 0x10) <= lbl_80540228)))
            setHitAt_8026C350(p, 0x38);
        break;
    case 0x30:
        fn_8026EE60(p);
    case 0x31: case 0x32: case 0x33: case 0x34:
        fn_8026EC88(p, k - 0x31);
        break;
    case 0x35:
        fn_8026F54C(p);
        break;
    case 0x36:
        fn_8026F388(p);
        break;
    case 0x37:
        fn_8026F1C4(p);
        break;
    case 0x38:
        fn_8026F000(p);
        break;
    case 0x39:
        break;
    case 0x3A:
        if (fn_802413F0(*(void**)(p + 4)) && !(*(f32*)(*(u8**)(p + 4) + 0x10) > lbl_80540254) && *(s32*)(p + 0xb0) <= 1)
            setHitAt_8026C350(p, 0x88);
        break;
    case 0x3B:
        ladder_8026C350(p);
        break;
    case 0x3C:
        if (tileX_8026B81C(p) > 8) {
            ladder_8026C350(p);
        } else if (tileY_8026B81C(p) < 8) {
            setHitAt_8026C350(p, 0x38);
        } else if (*(s32*)(p + 0x1c) == 3) {
            fn_8026E68C(p, 0x10);
        } else if (*(s32*)(p + 0x1c) == 2) {
            fn_8026E68C(p, 0x11);
        } else {
            tileCheck0_8026C350(p);
        }
        break;
    case 0x3D:
        if (tileX_8026B81C(p) > 8) {
            ladder_8026C350(p);
        } else if (tileY_8026B81C(p) < 8) {
            if (*(s32*)(p + 0x1c) == 3) {
                fn_8026E68C(p, 0x10);
            } else if (*(s32*)(p + 0x1c) == 2) {
                fn_8026E68C(p, 0x11);
            } else {
                tileCheck0_8026C350(p);
            }
        } else {
            setHitAt_8026C350(p, 0x38);
        }
        break;
    case 0x3E:
        if (!fn_80237A80(*(void**)(*(u8**)(p + 4) + 4))) setHitAt_8026C350(p, 0x38);
        break;
    case 0x40: case 0x41: case 0x42: case 0x43:
        setHitAt_8026C350(p, 0x38);
        break;
    case 0x50:
        setHitAt_8026C350(p, 0x70);
        break;
    }
}

extern "C" u8 fn_80240670(void*);
extern "C" u8 fn_802412A4(void*);
extern "C" u8 fn_8023EAC4(void*);
extern "C" f32 fn_80247330();
extern "C" f32 fn_8024712C();
extern "C" u8 fn_80250090(void*);
extern "C" u8 fn_80241478(void*);
extern "C" void fn_8026E1E0(u8* p) {
    if (fn_80240670(*(void**)(p + 4)) && (fn_802412A4(*(void**)(p + 4)) || *(s32*)(*(u8**)(p + 4) + 0x1218) > 0)) {
        *(s32*)(p + 0xa0) = 0;
        *(s32*)(p + 0xa4) = 0;
    } else {
        if (fn_8023EAC4(*(void**)(*(u8**)(p + 4) + 4))) {
            *(s32*)(p + 0xa0) = 0;
            *(s32*)(p + 0xa4) = 0;
        } else if (*(f32*)(*(u8**)(p + 4) + 0x10) > lbl_80540228) {
            *(s32*)(p + 0xa0) = 0;
            *(s32*)(p + 0xa4) = 0;
        } else if (p[0x38] == 1 && *(s32*)(*(u8**)(p + 4) + 0x3dc) == 0 && fn_80247330() > lbl_80540228) {
            *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) + 1;
            if (*(s32*)(p + 0xa0) > 0x14) {
                *(s32*)(p + 0xa0) = 0x14;
            }
            *(s32*)(p + 0xa4) = 0;
        } else if (p[0x39] == 1 && *(s32*)(*(u8**)(p + 4) + 0x3dc) == 1 && fn_80247330() < lbl_80540228) {
            *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) + 1;
            if (*(s32*)(p + 0xa0) > 0x14) {
                *(s32*)(p + 0xa0) = 0x14;
            }
            *(s32*)(p + 0xa4) = 0;
        } else if (p[0x3a] == 1 && *(s32*)(*(u8**)(p + 4) + 0x3dc) == 2 && fn_8024712C() < lbl_80540228) {
            *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) + 1;
            if (*(s32*)(p + 0xa0) > 0x14) {
                *(s32*)(p + 0xa0) = 0x14;
            }
            *(s32*)(p + 0xa4) = 0;
        } else if (p[0x3b] == 1 && *(s32*)(*(u8**)(p + 4) + 0x3dc) == 3 && fn_8024712C() > lbl_80540228) {
            *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) + 1;
            if (*(s32*)(p + 0xa0) > 0x14) {
                *(s32*)(p + 0xa0) = 0x14;
            }
            *(s32*)(p + 0xa4) = 0;
        } else if (fn_80250090(*(void**)(p + 4))) {
            *(s32*)(p + 0xa0) = 0x14;
            *(s32*)(p + 0xa4) = 0;
        } else if (!fn_80241478(*(void**)(p + 4))) {
            *(s32*)(p + 0xa4) = *(s32*)(p + 0xa4) + 1;
            if (*(s32*)(p + 0xa4) >= 5) {
                *(s32*)(p + 0xa4) = 5;
                *(s32*)(p + 0xa0) = 0;
                *(s32*)(*(u8**)(p + 4) + 0xd94) = -1;
                *(s32*)(*(u8**)(p + 4) + 0xd9c) = -1;
                *(s32*)(*(u8**)(p + 4) + 0xd98) = 0;
            }
        }
    }
}

extern "C" void fn_8026E464(u8* p) {
    s32 i;
    u32 j;
    for (i = 0; i < 8; i++) {
        p[0x40 + i] = p[0x48 + i];
        p[0x48 + i] = 0;
        p[0x30 + i] = 0;
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 16; j++) {
            *(s32*)(*(u8**)(p + 4) + i * 0x40 + j * 4 + 0xef0) = -1;
        }
    }
    p[0xb5] = p[0xb4]; p[0xb4] = 0; p[0xb6] = 0; p[0xb7] = 0; p[0xb8] = 0; p[0xb9] = 0; p[0xba] = 0;
    *(s32*)(p + 0xac) = 0;
}

#pragma opt_propagation off
extern "C" u8 fn_8026E5F8(u8* p, Vec2f* pos) {
    if (!p[0xd64]) {
        if (fn_80251AEC(p, 0x38)) {
            f32 y;
            f32 x;
            x = pos->x;
            y = pos->y;
            *(f32*)(p + 0x324) = x;
            *(f32*)(p + 0x328) = y;
            return 1;
        }
    } else {
        if (fn_80251AEC(p, 0x13)) {
            f32 y;
            f32 x;
            x = pos->x;
            y = pos->y;
            *(f32*)(p + 0x324) = x;
            *(f32*)(p + 0x328) = y;
            return 1;
        }
    }
    return 0;
}
#pragma opt_propagation reset
extern "C" void fn_802381B8(void*);
extern "C" u8 fn_80241230(void*);
extern "C" u8 fn_80240F28(void*);
extern "C" s32 fn_802415CC(void*);
extern "C" u8 fn_8024F5E4(void*);
extern "C" u8 fn_8026EB1C(u8* p, u16 param);
extern "C" u16 fn_802265FC(Vec2f*, s32);
extern "C" u16 fn_80226998(Vec2f*, s32);
extern "C" u8* lbl_8053AAF8;
extern "C" u8 lbl_80529DEC[];
extern Vec2f lbl_8046B9C8[];
extern "C" void fn_8026E68C(u8* p, u16 key) {
    u8* pl;
    fn_802381B8(*(void**)(*(u8**)(p + 4) + 4));
    if (fn_80241230(*(void**)(p + 4))) {
        p[*(s32*)(p + 0x1c) + 0x38] = 1;
        return;
    }
    if (fn_80240F28(*(void**)(p + 4)) && fn_802415CC(*(void**)(p + 4)) >= 2) {
        p[*(s32*)(p + 0x1c) + 0x38] = 1;
        return;
    }
    if (!fn_80240670(*(void**)(p + 4)) &&
        (fn_8026EB1C(p, key) || fn_8024F5E4(*(void**)(p + 4)) || fn_80240F28(*(void**)(p + 4)) ||
         (lbl_8053AAF8[0x7f] && *(s32*)(lbl_80529DEC + 0x118) == 2 && *(s32*)(lbl_80529DEC + 0x11c) == 1))) {
        Vec2f pos;
        pos.x = *(f32*)(p + 8);
        pos.y = *(f32*)(p + 0xc);
        if (key == 0x12 || key == 0x13) {
            pos.y += 16.0f;
        }
        bool found = false;
        do {
            pos.x += lbl_8046B9C8[key - 0x10].x;
            pos.y += lbl_8046B9C8[key - 0x10].y;
            s32 room = *(s32*)(*(u8**)(p + 4) + 0x3b4);
            u8* base = fn_802D6A9C();
            HitRect* r = (room < 8) ? (HitRect*)(base + 0xcc) : (HitRect*)(base + 0xdc);
            if (!rectContains(*r, &pos)) {
                break;
            }
            u16 t = fn_802265FC(&pos, *(s32*)(*(u8**)(p + 4) + 0x3b4));
            if (t == 0 || t == 3 || t == 0xd || t == 0x39 || t == 0x3a) {
                found = true;
            }
        } while (!found);
        if (!found) {
            if (key == 0x12 || key == 0x13) {
                pos.x = *(f32*)(p + 8);
                pos.y = *(f32*)(p + 0xc);
                do {
                    pos.x += lbl_8046B9C8[key - 0x10].x;
                    pos.y += lbl_8046B9C8[key - 0x10].y;
                    s32 room = *(s32*)(*(u8**)(p + 4) + 0x3b4);
                    u8* base = fn_802D6A9C();
                    HitRect* r = (room < 8) ? (HitRect*)(base + 0xcc) : (HitRect*)(base + 0xdc);
                    if (!rectContains(*r, &pos)) {
                        return;
                    }
                    u16 t = fn_802265FC(&pos, *(s32*)(*(u8**)(p + 4) + 0x3b4));
                    if (t == 0 || t == 3 || t == 0xd || t == 0x39 || t == 0x3a) {
                        found = true;
                    }
                } while (!found);
            } else {
                return;
            }
        }
        pos.x = 8.0f + (f32)((u32)(s32)pos.x & ~0xf);
        pos.y = 8.0f + (f32)((u32)(s32)pos.y & ~0xf);
        if (fn_80226998(&pos, *(s32*)(*(u8**)(p + 4) + 0x3b4)) == 0x17e) {
            pos.x += 8.0f;
        } else if (fn_80226998(&pos, *(s32*)(*(u8**)(p + 4) + 0x3b4)) == 0x17f) {
            pos.x -= 8.0f;
        }
        pl = *(u8**)(p + 4);
        bool ok;
        if (!pl[0xd64]) {
            if (fn_80251AEC(pl, 0x38)) {
                *(f32*)(pl + 0x324) = pos.x;
                *(f32*)(pl + 0x328) = pos.y;
                ok = true;
                goto done;
            }
        } else {
            if (fn_80251AEC(pl, 0x13)) {
                *(f32*)(pl + 0x324) = pos.x;
                *(f32*)(pl + 0x328) = pos.y;
                ok = true;
                goto done;
            }
        }
        ok = false;
    done:
        if (ok && key == 0x11) {
            (*(u8**)(p + 4))[0x441] = 1;
        }
    } else {
        p[*(s32*)(p + 0x1c) + 0x38] = 1;
    }
}

extern "C" u8 fn_80250D30(void*);
extern "C" u8 fn_8026EB1C(u8* p, u16 param) {
    if (!fn_80250D30(*(void**)(p + 4))) {
        return 0;
    }
    switch (param) {
    case 0x10:
        return *(s32*)(*(u8**)(p + 4) + 0x3dc) == 3;
    case 0x11:
        return *(s32*)(*(u8**)(p + 4) + 0x3dc) == 2;
    case 0x12:
        return *(s32*)(*(u8**)(p + 4) + 0x3dc) == 1;
    case 0x13:
        return *(s32*)(*(u8**)(p + 4) + 0x3dc) == 0;
    case 0x14:
        if (*(s32*)(*(u8**)(p + 4) + 0x3dc) == 3) {
            return 1;
        }
        return *(s32*)(*(u8**)(p + 4) + 0x3dc) == 1;
    case 0x15:
        if (*(s32*)(*(u8**)(p + 4) + 0x3dc) == 3) {
            return 1;
        }
        return *(s32*)(*(u8**)(p + 4) + 0x3dc) == 0;
    case 0x16:
        if (*(s32*)(*(u8**)(p + 4) + 0x3dc) == 2) {
            return 1;
        }
        return *(s32*)(*(u8**)(p + 4) + 0x3dc) == 1;
    case 0x17:
        if (*(s32*)(*(u8**)(p + 4) + 0x3dc) == 2) {
            return 1;
        }
        return *(s32*)(*(u8**)(p + 4) + 0x3dc) == 0;
    }
    return 0;
}

extern "C" s32 GetPtrField_0x4(void*);
extern "C" void fn_8026EC88(u8* p, s32 param) {
    *(s32*)(p + 0xac) = 1;
    if (param != GetPtrField_0x4(*(void**)(p + 4))) {
        p[*(s32*)(p + 0x1c) + 0x38] = 1;
        return;
    }
    if (fn_80250D30(*(void**)(p + 4)) && *(s32*)(p + 0x1c) == *(s32*)(*(u8**)(p + 4) + 0x3dc) && fn_8024FF84() < 0) {
        JGeometry::TVec3<f32> pos;
        JGeometry::TVec3<f32> v = *(JGeometry::TVec3<f32>*)(p + 8);
        JGeometry::TVec3<f32> off(lbl_8046B998[*(s32*)(*(u8**)(p + 4) + 0x3dc)].x, lbl_8046B998[*(s32*)(*(u8**)(p + 4) + 0x3dc)].y, lbl_8046B998[*(s32*)(*(u8**)(p + 4) + 0x3dc)].z);
        v.add(off);
        bool ok;
        u16 t = fn_8022461C(&v, *(s32*)(*(u8**)(p + 4) + 0x3b4));
        if (t != 0 && t != 2) {
            if (t == 0x50) {
                ok = true;
            } else {
                ok = false;
            }
        } else {
            ok = false;
        }
        if (ok) {
            pos = *(JGeometry::TVec3<f32>*)(p + 8);
            pos.z = lbl_80540228;
            u8* a = *(u8**)(p + 4);
            s32 idx = *(s32*)(a + 0x3dc);
            void* mgr = fn_801F856C();
            void* id = Actor_CreateByID(mgr, 0x424c434b, *(s32*)(a + 0x3b4), &pos, (((param + 1) & 7) << 4) | ((idx & 3) << 2), -1, -1);
            if (fn_8022461C(&pos, *(s32*)(*(u8**)(p + 4) + 0x3b4)) != 0x50) {
                if (fn_801F666C(fn_801F856C(), id) != 0) {
                    *(void**)(*(u8**)(p + 4) + 0xd94) = id;
                }
            }
            return;
        }
    }
    p[*(s32*)(p + 0x1c) + 0x38] = 1;
}

extern "C" void fn_8026EE60(u8* p) {
    *(s32*)(p + 0xac) = 1;
    if (fn_80250D30(*(void**)(p + 4)) && *(s32*)(*(u8**)(p + 4) + 0x3dc) == *(s32*)(p + 0x1c) && fn_8024FF84() < 0) {
        JGeometry::TVec3<f32> pos;
        JGeometry::TVec3<f32> v = *(JGeometry::TVec3<f32>*)(p + 8);
        JGeometry::TVec3<f32> off(lbl_8046B998[*(s32*)(*(u8**)(p + 4) + 0x3dc)].x, lbl_8046B998[*(s32*)(*(u8**)(p + 4) + 0x3dc)].y, lbl_8046B998[*(s32*)(*(u8**)(p + 4) + 0x3dc)].z);
        v.add(off);
        u16 t = fn_8022461C(&v, *(s32*)(*(u8**)(p + 4) + 0x3b4));
        bool ok;
        if (t != 0 && t != 2) {
            if (t == 0x50) {
                ok = true;
            } else {
                ok = false;
            }
        } else {
            ok = false;
        }
        if (ok) {
            pos = *(JGeometry::TVec3<f32>*)(p + 8);
            pos.z = lbl_80540228;
            s32 idx;
            u8* a = *(u8**)(p + 4);
            idx = *(s32*)(a + 0x3dc);
            void* mgr = fn_801F856C();
            void* id = Actor_CreateByID(mgr, 0x424c434b, *(s32*)(a + 0x3b4), &pos, (idx & 3) << 2, -1, -1);
            if (fn_8022461C(&pos, *(s32*)(*(u8**)(p + 4) + 0x3b4)) != 0x50) {
                if (fn_801F666C(fn_801F856C(), id) != 0) {
                    *(void**)(*(u8**)(p + 4) + 0xd94) = id;
                }
            }
            return;
        }
    }
    p[*(s32*)(p + 0x1c) + 0x38] = 1;
}

#pragma opt_propagation off
extern "C" void fn_8026F000(u8* p) {
    JGeometry::TVec3<f32> pos;
    if (*(s32*)(*(u8**)(p + 4) + 0x3dc) == 1) {
        *(s32*)(p + 0xac) = 1;
        bool ok;
        s32 dir;
        if (fn_80250D30(*(void**)(p + 4)) && (dir = *(s32*)(*(u8**)(p + 4) + 0x3dc), *(s32*)(p + 0x1c) == dir) && ((s32 (*)(void*))fn_8024FF84)(*(void**)(p + 4)) < 0) {
            JGeometry::TVec3<f32> off;
            JGeometry::TVec3<f32> v = *(JGeometry::TVec3<f32>*)(p + 8);
            JGeometry::TVec3<f32>* o = &lbl_8046B998[*(s32*)(*(u8**)(p + 4) + 0x3dc)];
            off.x = o->x;
            off.y = o->y;
            off.z = o->z;
            v.add(off);
            u16 t = fn_8022461C(&v, *(s32*)(*(u8**)(p + 4) + 0x3b4));
            if (t == 0 || t == 2 || t == 0x50) {
                ok = true;
            } else {
                ok = false;
            }
        } else {
            ok = false;
        }
        if (ok) {
            pos = *(JGeometry::TVec3<f32>*)(p + 8);
            pos.z = lbl_80540228;
            void* id;
            u8* a = *(u8**)(p + 4);
            id = (void*)*(s32*)(a + 0x3dc);
            id = Actor_CreateByID(fn_801F856C(), 0x424c434b, *(s32*)(a + 0x3b4), &pos, ((s32)id & 3) << 2, -1, -1);
            if (fn_8022461C(&pos, *(s32*)(*(u8**)(p + 4) + 0x3b4)) != 0x50) {
                if (fn_801F666C(fn_801F856C(), id) != 0) {
                    *(void**)(*(u8**)(p + 4) + 0xd94) = id;
                }
            }
            return;
        }
        p[*(s32*)(p + 0x1c) + 0x38] = 1;
    } else {
        p[*(s32*)(p + 0x1c) + 0x38] = 1;
    }
}
#pragma opt_propagation reset
extern "C" void fn_8026F1C4(u8* this_) {
    if (*(s32*)(*(u8**)(this_ + 4) + 0x3dc) == 0) {
        *(s32*)(this_ + 0xac) = 1;
        if (fn_80250D30(*(void**)(this_ + 4)) && *(s32*)(*(u8**)(this_ + 4) + 0x3dc) == *(s32*)(this_ + 0x1c) && fn_8024FF84() < 0) {
            JGeometry::TVec3<f32> tmp2;
            JGeometry::TVec3<f32> d;
            JGeometry::TVec3<f32> tmp = *(JGeometry::TVec3<f32>*)(this_ + 8);
            JGeometry::TVec3<f32>* src = &lbl_8046B998[*(s32*)(*(u8**)(this_ + 4) + 0x3dc)];
            d.x = src->x;
            d.y = src->y;
            d.z = src->z;
            tmp += d;
            u16 r = fn_8022461C(&tmp, *(s32*)(*(u8**)(this_ + 4) + 0x3b4));
            u8 ok;
            if (r != 0 && r != 2) {
                if (r == 0x50) {
                    ok = 1;
                } else {
                    ok = 0;
                }
            } else {
                ok = 0;
            }
            if (ok) {
                tmp2 = *(JGeometry::TVec3<f32>*)(this_ + 8);
                tmp2.z = lbl_80540228;
                s32 idx = *(s32*)(*(u8**)(this_ + 4) + 0x3dc);
                u8* sub = *(u8**)(this_ + 4);
                void* a = Actor_CreateByID(fn_801F856C(), 0x424C434B, *(s32*)(sub + 0x3b4), &tmp2, idx << 2, -1, -1);
                if (fn_8022461C(&tmp2, *(s32*)(*(u8**)(this_ + 4) + 0x3b4)) != 0x50) {
                    if (fn_801F666C(fn_801F856C(), a)) {
                        *(void**)(*(u8**)(this_ + 4) + 0xd94) = a;
                    }
                }
            }
        }
        this_[*(s32*)(this_ + 0x1c) + 0x38] = 1;
    } else {
        this_[*(s32*)(this_ + 0x1c) + 0x38] = 1;
    }
}
#pragma opt_propagation off
extern "C" void fn_8026F388(u8* p) {
    JGeometry::TVec3<f32> pos;
    if (*(s32*)(*(u8**)(p + 4) + 0x3dc) == 2) {
        *(s32*)(p + 0xac) = 1;
        bool ok;
        s32 dir;
        if (fn_80250D30(*(void**)(p + 4)) && (dir = *(s32*)(*(u8**)(p + 4) + 0x3dc), *(s32*)(p + 0x1c) == dir) && ((s32 (*)(void*))fn_8024FF84)(*(void**)(p + 4)) < 0) {
            JGeometry::TVec3<f32> off;
            JGeometry::TVec3<f32> v = *(JGeometry::TVec3<f32>*)(p + 8);
            JGeometry::TVec3<f32>* o = &lbl_8046B998[*(s32*)(*(u8**)(p + 4) + 0x3dc)];
            off.x = o->x;
            off.y = o->y;
            off.z = o->z;
            v.add(off);
            u16 t = fn_8022461C(&v, *(s32*)(*(u8**)(p + 4) + 0x3b4));
            if (t == 0 || t == 2 || t == 0x50) {
                ok = true;
            } else {
                ok = false;
            }
        } else {
            ok = false;
        }
        if (ok) {
            pos = *(JGeometry::TVec3<f32>*)(p + 8);
            pos.z = lbl_80540228;
            void* id;
            u8* a = *(u8**)(p + 4);
            id = (void*)*(s32*)(a + 0x3dc);
            id = Actor_CreateByID(fn_801F856C(), 0x424c434b, *(s32*)(a + 0x3b4), &pos, ((s32)id & 3) << 2, -1, -1);
            if (fn_8022461C(&pos, *(s32*)(*(u8**)(p + 4) + 0x3b4)) != 0x50) {
                if (fn_801F666C(fn_801F856C(), id) != 0) {
                    *(void**)(*(u8**)(p + 4) + 0xd94) = id;
                }
            }
            return;
        }
        p[*(s32*)(p + 0x1c) + 0x38] = 1;
    } else {
        p[*(s32*)(p + 0x1c) + 0x38] = 1;
    }
}
#pragma opt_propagation reset
extern "C" void fn_8026F54C(u8* p) {
    JGeometry::TVec3<f32> cp;
    u8* pl = *(u8**)(p + 4);
    if (*(s32*)(pl + 0x3dc) == 3) {
        *(s32*)(p + 0xac) = 1;
        if (fn_80250D30(*(void**)(p + 4))) {
            if (*(s32*)(*(u8**)(p + 4) + 0x3dc) == *(s32*)(p + 0x1c) && fn_8024FF84() < 0) {
            JGeometry::TVec3<f32> off;
            JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(p + 8);
            u8* pl2 = *(u8**)(p + 4);
            JGeometry::TVec3<f32>& src = lbl_8046B998[*(s32*)(pl2 + 0x3dc)];
            off.x = src.x;
            off.y = src.y;
            off.z = src.z;
            pos += off;
            u16 r = fn_8022461C(&pos, *(s32*)(pl2 + 0x3b4));
            bool ok;
            if (r != 0 && r != 2) {
                if (r == 0x50) {
                    ok = true;
                } else {
                    ok = false;
                }
            } else {
                ok = false;
            }
            if (ok) {
                void* act;
                s32 idx;
                u8* a;
                cp = *(JGeometry::TVec3<f32>*)(p + 8);
                cp.z = lbl_80540228;
                a = *(u8**)(p + 4);
                idx = *(s32*)(a + 0x3dc);
                void* mgr = fn_801F856C();
                act = Actor_CreateByID(mgr, 0x424c434b, *(s32*)(a + 0x3b4), &cp, (idx & 3) << 2, -1, -1);
                if (fn_8022461C(&cp, *(s32*)(*(u8**)(p + 4) + 0x3b4)) != 0x50) {
                    if (fn_801F666C(fn_801F856C(), act)) {
                        *(void**)(*(u8**)(p + 4) + 0xd94) = act;
                    }
                }
                return;
            }
            }
        }
        p[*(s32*)(p + 0x1c) + 0x38] = 1;
    } else {
        p[*(s32*)(p + 0x1c) + 0x38] = 1;
    }
}

extern "C" void fn_8026F710(u8* p) {
    s32 i;
    u32 j;
    for (i = 0; i < 8; i++) {
        p[0x48 + i] = 0;
        p[0x30 + i] = 0;
    }
    p[0xb4] = 0;
    p[0xb6] = 0;
    for (i = 0; i < 8; i++) {
        p[0x40 + i] = p[0x48 + i];
        p[0x48 + i] = 0;
        p[0x30 + i] = 0;
    }
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 16; j++) {
            *(s32*)(*(u8**)(p + 4) + i * 0x40 + j * 4 + 0xef0) = -1;
        }
    }
    p[0xb5] = p[0xb4];
    p[0xb4] = 0;
    p[0xb6] = 0;
    p[0xb7] = 0;
    p[0xb8] = 0;
    p[0xb9] = 0;
    p[0xba] = 0;
    *(s32*)(p + 0xac) = 0;
    p[0x9a] = 0;
    *(s32*)(p + 0x1c) = 0;
    for (i = 0; i < 8; i++) {
        p[i + 0x20] = 0;
        p[i + 0x28] = 0;
        p[i + 0x38] = 0;
        p[i + 0x50] = 0;
        p[i + 0x58] = 0;
        p[i + 0x60] = 0;
        p[i + 0x68] = 0;
        p[i + 0x70] = 0;
        p[i + 0x78] = 0;
        p[i + 0x80] = 0;
        p[i + 0x88] = 0;
    }
    p[0x98] = 0;
    p[0x99] = 0;
    *(s32*)(p + 0xa0) = 0;
    *(s32*)(p + 0xa4) = 0;
    *(s32*)(p + 0xa8) = 0;
    *(s32*)(p + 0xbc) = 0;
    *(s32*)(p + 0xb0) = 0;
    *(s32*)(p + 0xac) = 0;
    *(f32*)(p + 0x14) = 0.0f;
    *(f32*)(p + 0x18) = 0.0f;
}

struct Obj8026F998 {
    void* vtbl;
    void* m4;
};

extern "C" Obj8026F998* fn_8026F998(Obj8026F998* o, s16 flag) {
    if (o) {
        o->vtbl = lbl_804A71A8;
        o->m4 = 0;
        if (flag > 0) {
            __dl__FPv(o);
        }
    }
    return o;
}

extern "C" void fn_8026F9E8(Obj8026F998* o, void* p) {
    o->vtbl = lbl_804A71A8;
    o->m4 = p;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
