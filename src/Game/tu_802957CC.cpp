#include "types.h"
extern "C" const f32 lbl_80540668, lbl_8054066C, lbl_80540680, lbl_80540684;
extern "C" const f32 lbl_805406F4, lbl_805406E4;
extern "C" const f32 lbl_80540674, lbl_8054067C, lbl_80540688, lbl_8054068C, lbl_805406F0;
extern "C" f32 lbl_805406A8;
extern "C" const f32 lbl_80540678;
extern "C" const f32 lbl_80540670;
#include "JSystem/JParticle/JPAEmitter.h"

#include "JSystem/JGeometry/Box.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/ItemBase.h"


#include "dolphin/mtx.h"
#include "JSystem/JAudio/System/JASHeapCtrl.h"
#include "JSystem/JAudio/System/JASTrack.h"
class JASPoolObj3_FSA;
class JASPoolObj4_FSA;
class JAIStream;
class JAISoundChild;
class JAISeq;
class JAISe;


extern "C" char __vt__4HOUS[];
extern "C" void fn_801EE434(s32);
extern "C" void fn_80239914(void*, s32, void*);
extern "C" void __dt__5ActorFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" u8 fn_8023F264(s32 i);
extern "C" u8 fn_8022F514(s32 a);
extern "C" u8 fn_80235274(s32 a);
extern "C" void fn_80238548(s32, s32, void*, s32);
extern "C" void fn_8013CB44(void*, void*, s32, s32, s32);
extern "C" s32 fn_8023DE58(s32 x);
extern "C" void* fn_8023E724(s32 i);
extern "C" u8 fn_802317F0(s32 i, s32 a, void* b, void* c, s32 d);
extern "C" void* fn_802D6A9C();
extern "C" void* fn_802D9C4C();
extern "C" void fn_802D79E8(void* mgr, s32 mode, f32 a, f32 b, s32 c);
extern "C" void fn_802A20F0(void* mgr, void* v, s32 a, s32 room, s32 c, s32 d);
extern "C" void fn_802A1050(void* mgr, void* v);
extern "C" void fn_8030C210(void* obj, void* v);
extern "C" void fn_802C59B0(void* obj);
extern "C" void fn_802D8050(void* mgr, s32 kind, s32 a, s32 b);
extern "C" void* lbl_8053AC98;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_8046C238[];
extern "C" s32 fn_8013CC50(s32 id, void* p, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void fn_801F0E34(void* a, s32 code, s32 z);
extern "C" void* fn_801F856C();
extern "C" void* fn_801F666C(void* mgr, s32 idx);
static inline void clearHouseActors(char* self, s32 countOffset, s32 handleOffset) {
    char* entry;
    s32 index;
    for (index = 0, entry = self; index < *(s32*)(self + countOffset); entry += 4, index++) {
        char* actor = (char*)fn_801F666C(fn_801F856C(), *(s32*)(entry + handleOffset));
        if (actor) *(u8*)(actor + 0x11c) = 0;
    }
}
static inline void clearHouseFollowers(char* self, s32 countOffset, s32 handleOffset) {
    s32 index;
    char* entry;
    for (index = 0, entry = self; index < *(s32*)(self + countOffset); entry += 4, index++) {
        char* actor = (char*)fn_801F666C(fn_801F856C(), *(s32*)(entry + handleOffset));
        if (actor) *(u8*)(actor + 0x11c) = 0;
    }
}
extern "C" s32 fn_801F78F4(void*, u32, s32);
extern "C" u16 fn_80226850(void*, s32);
extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* a, s32 room, void* v, void* h, s32 c);
extern "C" u8 fn_802A1490(void* g, void* v);
extern "C" u8 fn_8023B0F4(s32 idx, void* box, s32 room, s32 a, f32 f);
extern "C" JGeometry::TVec3f lbl_8046C268[];
extern "C" f32 lbl_8046C298[];
extern "C" u8 fn_802957CC(void* p, u8 mode);
extern "C" s32 fn_80239108(void* h);
extern "C" s32 fn_80238BC4(void* h);
extern "C" s32 fn_80239470(void* box, s32 room, void* h);
extern "C" s32 fn_80238A68(void* h);
extern "C" s32 fn_8023885C(void* h);
extern "C" void fn_80238E08(void* h);
extern "C" u8 fn_802A1554(void* g, void* v);
extern "C" void fn_802A381C(void* g, void* v, s32 a, s32 b);

// Push direction from a player standing against the block, or -1.
static inline s32 PushDirFromPlayer(char* self) {
    if (fn_80239108(*(void**)(self + 0x198)) >= 4) {
        s32 room = *(s32*)(self + 4);
        if (fn_8023DE58(0) == room) {
            s32 d = fn_80238BC4(*(void**)(self + 0x198));
            if (d >= 0 && d < 4) {
                *(s32*)(self + 0x2cc) = 1;
                return d;
            }
        }
    }
    return -1;
}

// Push direction from a player pulling the block (reversed), or -1.
static inline s32 PushDirFromPull(char* self) {
    JGeometry::TBox2f box;
    box.i.x = *(f32*)(self + 0x80);
    box.i.y = *(f32*)(self + 0x84);
    box.f.x = *(f32*)(self + 0x88);
    box.f.y = *(f32*)(self + 0x8c);
    box.addPos(*(JGeometry::TVec2f*)(self + 0xc));
    if (fn_80239470(&box, *(s32*)(self + 4), *(void**)(self + 0x198)) >= 0 &&
        fn_80238A68(*(void**)(self + 0x198)) >= 4) {
        s32 d = fn_8023885C(*(void**)(self + 0x198));
        if (d >= 0 && d < 4) {
            if (d == 0) {
                d = 1;
            } else if (d == 1) {
                d = 0;
            } else if (d == 2) {
                d = 3;
            } else if (d == 3) {
                d = 2;
            }
            *(s32*)(self + 0x2cc) = -1;
            return d;
        }
    }
    return -1;
}

static inline void HouseCopyBounds(JGeometry::TBox2f& dst, const JGeometry::TBox2f& src) {
    const u32* in = (const u32*)&src;
    u32* out = (u32*)&dst;
    u32 d;
    u32 a;
    u32 b;
    u32 c;
    a = in[0];
    b = in[1];
    c = in[2];
    d = in[3];
    out[0] = a;
    out[1] = b;
    out[2] = c;
    out[3] = d;
}

struct PushProbe {
    PushProbe() {}
    JGeometry::TVec3f pos;
    JGeometry::TBox2f area;
};

extern "C" void* lbl_8053AC98;
extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* a, s32 room, void* v, void* h, s32 c);
extern "C" void* fn_802D6A9C();

// Whether the six cells along the block's right edge are free to push into.
static inline u8 PushPathClearRight(char* self) {
    s32 room = *(s32*)(self + 4);
    char* m = (char*)fn_802D6A9C();
    JGeometry::TBox2f* src = (JGeometry::TBox2f*)(room < 8 ? m + 0xcc : m + 0xdc);
    u8 ok = 1;
    PushProbe pt;
    pt.area = *src;
    pt.pos = *(JGeometry::TVec3f*)(self + 0xc);
    pt.pos.x += *(f32*)(self + 0x68);
    pt.pos.x += 8.0f;
    f32 x0 = pt.area.i.x - -32.0f;
    f32 y0 = pt.area.i.y - -32.0f;
    f32 x1 = pt.area.f.x + -32.0f;
    f32 y1 = pt.area.f.y + -32.0f;
    pt.area.i.x = x0;
    pt.area.i.y = y0;
    pt.area.f.x = x1;
    pt.area.f.y = y1;
    pt.pos.y += *(f32*)(self + 0x64);
    pt.pos.y += 8.0f;
    pt.pos.z = 0.0f;
    for (s32 i = 0; i < 6; i++) {
        if (!fn_802A1554(lbl_8053AC98, &pt)) {
            ok = 0;
            break;
        }
        void* h = *(void**)(self + 0x198);
        s32 r = *(s32*)(self + 4);
        char* base = (char*)fn_8020D58C();
        if (fn_8020D6AC(base + 4 + *(u8*)(base + 1) * 0x784, r, &pt, h, 0) == 1) {
            ok = 0;
            break;
        }
        bool in = false;
        if (pt.pos.x >= x0 && pt.pos.y >= y0 && pt.pos.x < x1 && pt.pos.y < y1) {
            in = true;
        }
        if (!in) {
            ok = 0;
            break;
        }
        pt.pos.y += 16.0f;
    }
    return ok;
}

// Writes the 6x6 tile grid under the block into the room map.
static inline void PushStampGrid(char* self) {
    JGeometry::TVec3f grid;
    JGeometry::TVec3f base;
    base = *(JGeometry::TVec3f*)(self + 0xc);
    base.x += *(f32*)(self + 0x60);
    base.y += *(f32*)(self + 0x64);
    base.x += 8.0f;
    base.y += 8.0f;
    base.z = 0.0f;
    grid = base;
    for (s32 i = 0; i < 6; i++) {
        grid.y = base.y;
        char* col = self;
        for (s32 j = 0; j < 6; j++) {
            fn_802A381C(lbl_8053AC98, &grid, 0, *(u16*)(col + 0x3b0));
            fn_802A381C(lbl_8053AC98, &grid, 1, 0);
            grid.y += 16.0f;
            col += 2;
        }
        grid.x += 16.0f;
        self += 0xc;
    }
}

struct HOUSLinks {
    u8 unk_000[0x25c];
    s32 outgoing[4];
    s32 incoming[4];
    s32 flames[4];
    s32 doors[4];
    s32 outgoingCount;
    s32 incomingCount;
    s32 flameCount;
    s32 doorCount;
};


static inline s32 WarpDestination(const char* actor) {
    int room = (*(const u32*)(actor + 0x90) >> 24) & 7;
    s32 result = room + 7;
    if (room == 0) result = room;
    return result;
}
static inline s32 HouseDestination(const char* actor) {
    int room = (*(const u32*)(actor + 0x90) >> 7) & 31;
    return (room + 7) & ~-(s32)(room == 0);
}
static inline bool WarpDestinationIs(const char* other, s32 room) { return room == WarpDestination(other); }


// Whether pos hits a collision rect of the current list (excluding this actor's own handle).
static inline u8 HitsRect(char* self, void* pos) {
    s32 room;
    void* h = *(void**)(self + 0x198);
    room = *(s32*)(self + 4);
    char* base = (char*)fn_8020D58C();
    return fn_8020D6AC(base + 4 + *(u8*)(base + 1) * 0x784, room, pos, h, 0);
}


static inline u8 HouseLeadingHitsRect(char* self, void* pos) {
    void* h;
    s32 room;
    h = *(void**)(self + 0x198);
    room = *(s32*)(self + 4);
    char* base = (char*)fn_8020D58C();
    return fn_8020D6AC(base + 4 + *(u8*)(base + 1) * 0x784, room, pos, h, 0);
}

// Scroll bounds of the screen (TV or GBA) this actor's room is on.
static inline JGeometry::TBox2f* RoomBounds(char* self) {
    s32 room = *(s32*)(self + 4);
    char* m = (char*)fn_802D6A9C();
    return (JGeometry::TBox2f*)(room < 8 ? m + 0xcc : m + 0xdc);
}

extern "C" u8 fn_802957CC(void* p, u8 mode) {
    struct Probe {
        Probe() {}
        JGeometry::TVec3f pos;
        JGeometry::TBox2f area;
        JGeometry::TVec3f save;
    };
    char* self = (char*)p;
    u8 ok = 1;
    f32 dx, dy, dz;
    s32 i;
    s32 probeStep;
    s32 room;
    char* m;
    JGeometry::TBox2f* src;
    JGeometry::TVec3f* v;
    Probe pt;
    JGeometry::TBox2f box;
    JGeometry::TVec3f q;
    JGeometry::TVec3f ofs;

    pt.save = *(JGeometry::TVec3f*)(self + 0xc);
    const JGeometry::TVec3f& direction = lbl_8046C268[mode];
    dx = direction.x;
    dy = direction.y;
    *(f32*)(self + 0x3c) = dx;
    dz = direction.z;
    *(f32*)(self + 0x40) = dy;
    *(f32*)(self + 0x44) = dz;
    *(JGeometry::TVec3f*)(self + 0xc) += *(JGeometry::TVec3f*)(self + 0x3c);
    *(f32*)(self + 0x60) = -44.0f;
    *(f32*)(self + 0x64) = -44.0f;
    *(f32*)(self + 0x68) = 44.0f;
    *(f32*)(self + 0x6c) = 44.0f;

    pt.area = *RoomBounds(self);
    pt.area.i.x -= -32.0f;
    pt.area.i.y -= -32.0f;
    pt.area.f.x += -32.0f;

    pt.pos = *(JGeometry::TVec3f*)(self + 0xc);
    pt.pos.z = lbl_80540674;

    if (mode == 0 || mode == 1) {
        if (mode == 0) {
            pt.pos.x += *(f32*)(self + 0x68);
            pt.pos.x += 8.0f;
        } else {
            pt.pos.x += *(f32*)(self + 0x60);
            pt.pos.x -= 8.0f;
        }
        pt.pos.y += *(f32*)(self + 0x64);
        pt.pos.y += 8.0f;
        for (s32 firstStep = 0; firstStep < 6; firstStep++) {
            if (!fn_802A1490(lbl_8053AC98, &pt.pos) || HouseLeadingHitsRect(self, &pt.pos) == 1) {
                ok = 0;
                break;
            }
            pt.pos.y += 16.0f;
        }
    } else {
        if (mode == 2) {
            pt.pos.y += *(f32*)(self + 0x6c);
            pt.pos.y += 8.0f;
        } else {
            pt.pos.y += *(f32*)(self + 0x64);
            pt.pos.y -= 8.0f;
        }
        pt.pos.x += *(f32*)(self + 0x60);
        pt.pos.x += 8.0f;
        for (probeStep = 0; probeStep < 6; probeStep++) {
            if (!fn_802A1490(lbl_8053AC98, &pt.pos) || HitsRect(self, &pt.pos) == 1) {
                ok = 0;
                break;
            }
            pt.pos.x += 16.0f;
        }
    }

    if (!ok) {
        ok = 1;
        box.i.x = *(f32*)(self + 0x60);
        box.i.y = *(f32*)(self + 0x64);
        box.f.x = *(f32*)(self + 0x68);
        box.f.y = *(f32*)(self + 0x6c);
        box.addPos(*(JGeometry::TVec2f*)(self + 0xc));
        for (i = 0; i < 4; i++) {
            if (fn_8023B0F4(i, &box, *(s32*)(self + 4), 0, lbl_80540674)) {
                v = (JGeometry::TVec3f*)fn_8023E724(i);
                ofs.set(((JGeometry::TVec3f*)lbl_8046C298)[mode]);
                q = *v;
                q += ofs;
                if (fn_802A1490(lbl_8053AC98, &q) != 1 || HitsRect(self, &q)) {
                    ok = 0;
                }
            }
        }
    }

    *(JGeometry::TVec3f*)(self + 0xc) = pt.save;
    *(f32*)(self + 0x3c) = lbl_80540674;
    *(f32*)(self + 0x40) = lbl_80540674;
    *(f32*)(self + 0x44) = lbl_80540674;
    *(f32*)(self + 0x60) = lbl_80540680;
    *(f32*)(self + 0x64) = lbl_80540680;
    *(f32*)(self + 0x68) = lbl_80540684;
    *(f32*)(self + 0x6c) = lbl_80540684;
    return ok;
}

#pragma opt_common_subs off
#pragma opt_strength_reduction off
extern "C" void fn_80295C40(void* p) {
    int i;
    s32 n;
    char* pc;
    char* q;
    void* obj;
    s32 k;
    s32 j;

    for (i = 0; i < 4; i++) {
        if (fn_8023F264(i) != 0 && fn_8022F514(i) == 0) {
            n = (*(u32*)((char*)p + 0x90) >> 7) & 0x1f;
            n = n == 0 ? 0 : n + 7;
            if (n == fn_8023DE58(i)) {
                n = *(s32*)((char*)p + 4);
                if (fn_802317F0(i, n, fn_8023E724(i), (char*)p + 0xc, 0x1f) != 0) {
                    *((char*)p + (i + 0x2bc)) = 1;
                } else {
                    n = *(s32*)((char*)p + 4);
                    *((char*)p + (i + 0x2bc)) = fn_802317F0(i, n, fn_8023E724(i), (char*)p + 0xc, 0x21);
                }
            }
        }
    }

    fn_802D6A9C();
    pc = (char*)fn_802D9C4C();
    fn_8013CC50(*(u32*)((char*)p + 4), (char*)p + 0xc, 1.0f, 0x82, 1, 0, 0, 0, 1);
    fn_8013CC50(*(u32*)((char*)p + 4), (char*)p + 0xc, 1.0f, 0x83, 1, 0, 0, 0, 1);
    fn_8013CC50(*(u32*)((char*)p + 4), (char*)p + 0xc, 1.0f, 0x84, 1, 0, 0, 0, 1);
    if (*pc == 'r' || *pc == 's') {
        fn_8013CC50(*(u32*)((char*)p + 4), (char*)p + 0xc, 1.0f, 0x80, 1, 0, 0, 0, 1);
    } else {
        fn_8013CC50(*(u32*)((char*)p + 4), (char*)p + 0xc, 1.0f, 0x81, 1, 0, 0, 0, 1);
    }
    fn_801F0E34(p, 0x30092, 0);

    q = (char*)p;
    k = 2;
    do {
        obj = *(void**)(q + 0x2fc);
        if (obj != 0) {
            *(u32*)((char*)obj + 0xf4) |= 1;
            *(s32*)((char*)obj + 0x24) = 1;
            *(void**)(q + 0x2fc) = 0;
        }
        obj = *(void**)(q + 0x300);
        if (obj != 0) {
            *(u32*)((char*)obj + 0xf4) |= 1;
            *(s32*)((char*)obj + 0x24) = 1;
            *(void**)(q + 0x300) = 0;
        }
        q += 8;
    } while (--k);

    q = (char*)p;
    for (j = 0; j < *(s32*)((char*)p + 0x2a4); j++) {
        obj = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x27c));
        if (obj != 0) {
            *(u8*)((char*)obj + 0x11c) = 0;
        }
        q += 4;
    }

    *(u8*)((char*)p + 0x2bb) = 1;
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
extern "C" void fn_80295EE8(char* this_) {
    char* self = this_;
    s32 i;
    s32 j;
    s32 n;
    s32 k;
    if (*(s32*)(self + 0x2c4) <= 0) {
        ((ItemBase*)self)->v07();
        return;
    }
    if (*(s32*)(self + 0x2c8) - *(s32*)(self + 0x2c4) < 60) {
        *(JGeometry::TVec3f*)(self + 0x3c) = *(JGeometry::TVec3f*)(self + 0x2d0);
        ((JGeometry::TVec3f*)(self + 0x3c))->scale(2.0f * ((f32)(*(s32*)(self + 0x2c4) + 60 - *(s32*)(self + 0x2c8)) / 60.0f));
        ((JGeometry::TVec3f*)(self + 0xc))->add(*(JGeometry::TVec3f*)(self + 0x3c));
        for (i = 0; i < 2; i++) {
            f32 x = 50.0f * i - 25.0f;
            for (j = 0; j < 2; j++) {
                void* emitter = *(void**)(self + 0x2fc + i * 8 + j * 4);
                if (emitter != 0) {
                    JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(self + 0xc);
                    f32 y = 50.0f * j - 25.0f;
                    pos.x += x * *(f32*)(self + 0x54);
                    pos.y += y * *(f32*)(self + 0x54);
                    fn_8013CB44(emitter, &pos, 0, -1, 1);
                }
            }
        }
    } else {
        char* q = self;
        for (s32 row = 0; row < 2; row++) {
            for (s32 col = 0; col < 2; col++) {
                JPABaseEmitter* emitter = *(JPABaseEmitter**)(q + 0x2fc + col * 4);
                if (emitter != 0) {
                    emitter->becomeInvalidEmitter();
                    *(JPABaseEmitter**)(q + 0x2fc + col * 4) = 0;
                }
            }
            q += 8;
        }
        ((JGeometry::TVec3f*)(self + 0x3c))->zero();
    }
    for (k = 0; k < 4; k++) {
        n = (*(u32*)(self + 0x90) >> 7) & 0x1f;
        n = n == 0 ? 0 : n + 7;
        s32 room = fn_8023DE58(k);
        if (room == n && !fn_80235274(k)) {
            fn_80238548(k, 0, fn_8023E724(k), 12);
        }
    }
    --*(s32*)(self + 0x2c4);
}

extern "C" s32 fn_801F2718(void* p, u32 id);
extern "C" void fn_802A381C(void* mgr, void* v, s32 a, s32 b);
static inline void restoreHouseGrid(char* self) {
    char* row;
    s32 i, j;
    char* col;
    JGeometry::TVec3f gridBase;
            *(u8*)(self + 0x24c) = 0;
            if (*(u8*)(self + 0x24c) == 0) {
                *(u8*)(self + 0x24c) = 1;
                gridBase = *(JGeometry::TVec3f*)(self + 0xc);
                gridBase.x += *(f32*)(self + 0x60);
                gridBase.x += 8.0f;
                gridBase.y += *(f32*)(self + 0x64);
                gridBase.y += 8.0f;
                gridBase.z = 0.0f;
                JGeometry::TVec3f grid(gridBase);
                for (i = 0, row = self; i < 6; i++, row += 0xc) {
                    grid.y = gridBase.y;
                    for (j = 0, col = row; j < 6; j++, col += 2) {
                        fn_802A381C(lbl_8053AC98, &grid, 0, *(u16*)(col + 0x3b0));
                        fn_802A381C(lbl_8053AC98, &grid, 1, 0);
                        grid.y += 16.0f;
                    }
                    grid.x += 16.0f;
                }
            }

}

extern "C" void fn_802961AC(void* p) {
    char* self = (char*)p;
    char* other;
    s32 i;
    char* row;
    char* col;
    JGeometry::TVec3f* dir;
    JGeometry::TVec3f v;
    f32 ox;
    s32 id;
    s32 j;
    u32 n;
    s32 mode;

    id = fn_801F2718(self, 0x534C5233);
    if (id < 0) {
        return;
    }
    other = (char*)fn_801F666C(fn_801F856C(), id);
    if (other) {
        if (*(u16*)(other + 0x94) == 5) {
            dir = (JGeometry::TVec3f*)(self + 0x2d0);
            *dir = *(JGeometry::TVec3f*)(self + 0xc) - *(JGeometry::TVec3f*)(other + 0xc);
            dir->normalize();
            *(JGeometry::TVec3f*)(self + 0x3c) = *dir;
            fn_801F0E34(self, 0x30075, 0);

            for (i = 0, row = self; i < 2; i++, row += 8) {
                ox = (f32)i * 50.0f - 25.0f;
                for (j = 0, col = row; j < 2; j++, col += 4) {
                    if (*(u32*)(col + 0x2fc) == 0) {
                        v = *(JGeometry::TVec3f*)(self + 0xc);
                        v.x += ox;
                        v.y += (f32)j * 50.0f - 25.0f;
                        *(s32*)(col + 0x2fc) = fn_8013CC50(*(s32*)(self + 4), &v, 3.0f, 0x3d3, 0, -1, 0, 0, 1);
                    }
                }
            }

            n = (*(u32*)(self + 0x90) >> 7) & 0x1f;
            if (n == 0) mode = 0; else mode = n + 7;
            fn_802D79E8(fn_802D6A9C(), mode, 16.0f, 0.0f, 1);

            clearHouseActors(self, 0x2a0, 0x26c);
            clearHouseFollowers(self, 0x29c, 0x25c);

            restoreHouseGrid(self);
            *(s32*)(self + 0x2c4) = 120;
            *(s32*)(self + 0x2c8) = 120;
            *(u8*)(self + 0x2ba) = 1;
        }
    }
}

extern "C" u8* lbl_8053AAF8;
extern "C" void fn_802F6CF4(void* obj, JGeometry::TVec3f* pos, void* res, DrawRec* rec);
extern "C" s32 fn_8023CB24(s32);
extern "C" u8 fn_8023CA88(s32);
extern "C" void fn_802965BC(void* this_)
{
    struct ResMgr {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void* getRes(u32 type, const char* name);
    };
    u8* self = (u8*)this_;
    const char* tbl = (const char*)lbl_8046C238;
    if ((self[0x24c] != 0 || *(s32*)(self + 0x2ac) != 0) && self[0x2bb] != 1) {
        DrawRec rec;
        Mtx m;
        const char* name;
        const char* name2;
        PSMTXTrans(m, *(f32*)(self + 0x60), *(f32*)(self + 0x64), 0.0f);
        rec.w18 = m;
        rec.b1d = -2;
        if (self[0xc4]) {
            rec.b20 = 0;
            rec.b1d = fn_8023CB24(*(s32*)(self + 0xc8)) + 1;
            rec.b1c = fn_8023CA88(*(s32*)(self + 0xc8));
        }
        JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(self + 0xc);
        if (*(s32*)(self + 0x244) == 0) {
            name = tbl + 0xa0;
            if (!self[0x2b6]) {
                name = tbl + 0x90;
            }
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, name), &rec);
            }
            rec.b1c++;
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, tbl + 0xb0), &rec);
            }
            rec.b1c--;
        } else if (*(s32*)(self + 0x244) == 1) {
            if (!self[0x2b7]) {
                name = tbl + 0xc0;
                name2 = tbl + 0xd0;
            } else {
                name = tbl + 0xe0;
                name2 = tbl + 0xf0;
            }
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, name), &rec);
            }
            rec.b1c++;
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, name2), &rec);
            }
            rec.b1c--;
            pos.y += 48.0f;
            if (!self[0x2b6]) {
                name = tbl + 0x100;
                name2 = tbl + 0x110;
            } else {
                name = tbl + 0x120;
                name2 = tbl + 0x130;
            }
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, name), &rec);
            }
            rec.b1c++;
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, name2), &rec);
            }
            rec.b1c--;
        } else {
            name = tbl + 0x140;
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, name), &rec);
            }
            rec.b1c++;
            if (*(s32*)(self + 4) < 8) {
                fn_802F6CF4(((void**)lbl_8053AB10)[8], &pos, (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->getRes(0x534d5020, tbl + 0x150), &rec);
            }
            rec.b1c--;
        }
    }
}

extern "C" void fn_80296A84(u8* this_) {
}

extern "C" void fn_802984B0(void* p) {
    char* self = (char*)p;
    JGeometry::TBox2f b1;
    JGeometry::TBox2f b2;
    JGeometry::TBox2f b3;
    JGeometry::TBox2f b4;
    JGeometry::TBox2f b5;
    JGeometry::TBox2f b6;

    switch (*(s32*)(self + 0x2b0)) {
    case 0:
        b1.set(*(JGeometry::TBox2f*)(self + 0x60));
        b1.addPos(*(JGeometry::TVec2f*)(self + 0xc));
        b1.f.y -= 40.0f;
        fn_80239914(&b1, *(s32*)(self + 0x4), *(void**)(self + 0x198));
        break;
    case 1:
        b1.set(*(f32*)(self + 0x60), *(f32*)(self + 0x64), 42.0f + *(f32*)(self + 0x60), 42.0f + *(f32*)(self + 0x64));
        b1.addPos(*(JGeometry::TVec2f*)(self + 0xc));
        fn_80239914(&b1, *(s32*)(self + 0x4), *(void**)(self + 0x198));
        b2.set(*(f32*)(self + 0x68) - 42.0f, *(f32*)(self + 0x64), *(f32*)(self + 0x68), 42.0f + *(f32*)(self + 0x64));
        b2.addPos(*(JGeometry::TVec2f*)(self + 0xc));
        fn_80239914(&b2, *(s32*)(self + 0x4), *(void**)(self + 0x198));
        break;
    case 2:
        b1.set(*(f32*)(self + 0x60), *(f32*)(self + 0x64), 42.0f + *(f32*)(self + 0x60), *(f32*)(self + 0x6c) - 40.0f);
        b1.addPos(*(JGeometry::TVec2f*)(self + 0xc));
        fn_80239914(&b1, *(s32*)(self + 0x4), *(void**)(self + 0x198));
        b2.set(*(f32*)(self + 0x68) - 42.0f, *(f32*)(self + 0x64), *(f32*)(self + 0x68), *(f32*)(self + 0x6c) - 40.0f);
        b2.addPos(*(JGeometry::TVec2f*)(self + 0xc));
        fn_80239914(&b2, *(s32*)(self + 0x4), *(void**)(self + 0x198));
        break;
    }
    switch (*(s32*)(self + 0x244)) {
    case 0:
    case 1:
        b3.set(*(f32*)(self + 0x60), *(f32*)(self + 0x6c) - 42.0f, 42.0f + *(f32*)(self + 0x60), *(f32*)(self + 0x6c));
        b3.addPos(*(JGeometry::TVec2f*)(self + 0xc));
        fn_80239914(&b3, *(s32*)(self + 0x4), *(void**)(self + 0x198));
        b4.set(*(f32*)(self + 0x68) - 42.0f, *(f32*)(self + 0x6c) - 42.0f, *(f32*)(self + 0x68), *(f32*)(self + 0x6c));
        b4.addPos(*(JGeometry::TVec2f*)(self + 0xc));
        fn_80239914(&b4, *(s32*)(self + 0x4), *(void**)(self + 0x198));
        break;
    case 2:
        b3.set(*(f32*)(self + 0x60), *(f32*)(self + 0x6c) - 42.0f, 58.0f + *(f32*)(self + 0x60), *(f32*)(self + 0x6c));
        b3.addPos(*(JGeometry::TVec2f*)(self + 0xc));
        fn_80239914(&b3, *(s32*)(self + 0x4), *(void**)(self + 0x198));
        b4.set(*(f32*)(self + 0x68) - 26.0f, *(f32*)(self + 0x6c) - 42.0f, *(f32*)(self + 0x68), *(f32*)(self + 0x6c));
        b4.addPos(*(JGeometry::TVec2f*)(self + 0xc));
        fn_80239914(&b4, *(s32*)(self + 0x4), *(void**)(self + 0x198));
        break;
    }
    if (*(s32*)(self + 0x2a8) > 0) {
        if (*(u8*)(self + 0x2b6) == 0) {
            b5.set(40.0f + *(f32*)(self + 0x60), *(f32*)(self + 0x6c) - 16.0f, *(f32*)(self + 0x68) - 40.0f, *(f32*)(self + 0x6c));
            b5.addPos(*(JGeometry::TVec2f*)(self + 0xc));
            fn_80239914(&b5, *(s32*)(self + 0x4), *(void**)(self + 0x198));
        }
        if (*(u8*)(self + 0x2b7) == 0) {
            b6.set(40.0f + *(f32*)(self + 0x60), *(f32*)(self + 0x64), *(f32*)(self + 0x68) - 40.0f, 16.0f + *(f32*)(self + 0x64));
            b6.addPos(*(JGeometry::TVec2f*)(self + 0xc));
            fn_80239914(&b6, *(s32*)(self + 0x4), *(void**)(self + 0x198));
        }
    }
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern "C" void fn_80239914(void*, s32, void*);
#pragma opt_lifetimes off
extern "C" void fn_80298978(void* p) {
    u8* self = (u8*)p;
    u8* ids = (u8*)p;
    u8* centers = (u8*)p;
    s32 i;
    s32 flag;
    s32 j;
    u32 mode;
    s32 key;
    u8 ret;
    void* obj;
    JGeometry::TVec3f pos;
    JGeometry::TVec2f* center;
    JGeometry::TBox2f box;
    JGeometry::TVec3f* v;
    f32 lenSq;

    for (i = 0; i < *(s32*)((char*)p + 0x29c); ids += 4, centers += 8, i++) {
        obj = fn_801F666C(fn_801F856C(), *(s32*)(ids + 0x25c));
        flag = 0;
        if (obj != 0) {
            v = (JGeometry::TVec3f*)((char*)p + 0x250);
            u8 zero = v->isZero();
            if (zero == 0) {
                flag = 1;
            } else {
                for (j = 0; j < 4; j++) {
                    JGeometry::setTVec3f((f32*)((char*)obj + 0x238), &pos.x);
                    key = *(u32*)((char*)obj + 0x90) & 0x7f;
                    f32 x = 8.0f * (f32)((j & 1) > 0) - 4.0f;
                    f32 y = 8.0f * (f32)((j & 2) > 0) - 4.0f;
                    pos.x += x;
                    pos.y += y;
                    if (key == 0 || key == 3) { pos.y += -16.0f; }
                    else if (key == 1 || key == 2) { pos.y += 16.0f; }
                    else if (key == 0x17) { pos.x += 16.0f; }
                    else if (key == 0x18) { pos.x += -16.0f; }
                    /*switch (key) {
                    case 3:
                        pos.y = pos.y + -16.0f;
                        break;
                    case 1:
                    case 2:
                        pos.y = pos.y + 16.0f;
                        break;
                    case 0x17:
                        pos.x = pos.x + 16.0f;
                        break;
                    case 0x18:
                        pos.x = pos.x + -16.0f;
                        break;
                    }
                    */
                    mode = (*(u32*)((char*)obj + 0x90) >> 24) & 7;
                    int room = mode + 7;
                    if (mode == 0) room = mode;
                    ItemBase* actor = (ItemBase*)p;
                    ret = actor->v17(room, &pos.x);
                    if (ret == 1U) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1) {
                center = (JGeometry::TVec2f*)centers;
                box.set(-10.0f, -10.0f, 10.0f, 10.0f);
                box.addPos(*(JGeometry::TVec2f*)((char*)center + 0x2dc));
                mode = (*(u32*)((char*)p + 0x90) >> 7) & 0x1f;
                mode = mode == 0 ? 0 : mode + 7;
                fn_80239914(&box, mode, *(void**)((char*)p + 0x198));
            }
        }
    }
}
#pragma opt_common_subs off
extern "C" void fn_80298C18(void* p) {
    char* self = (char*)p;
    const JGeometry::TVec3f* step;
    s32 i;
    char* q;
    s32 n;
    s32 k;
    s32 idx;
    void* m;
    void* obj;
    f32 lenSq;
    JGeometry::TVec3f v;
    JGeometry::TVec3f vec;
    JGeometry::TVec3f off;
    JGeometry::TVec3f v2;
    JGeometry::TVec3f* vel;

    if (*(f32*)(self + 0x250) > lbl_80540674) {
        *(s32*)(self + 0x248) += 1;
        n = (*(u32*)(self + 0x90) >> 7) & 0x1f;
        n = n == 0 ? 0 : n + 7;
        m = fn_802D6A9C();
        fn_802D79E8(m, n, lbl_80540688, lbl_80540674, 1);
        if (*(f32*)(self + 0x250) > lbl_805406F0) {
            *(f32*)(self + 0xc) += lbl_805406F0;
            *(f32*)(self + 0x250) -= lbl_805406F0;
        } else {
            *(f32*)(self + 0xc) += *(f32*)(self + 0x250);
            *(f32*)(self + 0x258) = lbl_80540674;
            *(f32*)(self + 0x254) = lbl_80540674;
            *(f32*)(self + 0x250) = lbl_80540674;
        }

        v = *(JGeometry::TVec3f*)(self + 0xc);
        v.x += *(f32*)(self + 0x68);
        v.x -= lbl_8054068C;
        v.y += *(f32*)(self + 0x64);
        v.y += lbl_80540678;
        v.z = lbl_80540674;
        for (int j = 0; j < 6; j++) {
            fn_802A20F0(lbl_8053AC98, &v, -1, *(s32*)(self + 4), 0, 1);
            fn_802A1050(lbl_8053AC98, &v);
            v.y += lbl_8054067C;
        }

        v2 = *(JGeometry::TVec3f*)(self + 0xc);
        idx = 0;
        if (*(s32*)(self + 0x2a4) > 0 && *(s32*)(self + 0x2cc) == -1) {
            idx ^= 1;
        }
        f32* entry = lbl_8046C238 + idx*3;
        off.x = entry[0];
        off.y = entry[1];
        off.z = entry[2];
        v2 += off;
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &v2);

        vel = (JGeometry::TVec3f*)(self + 0x250);
        lenSq = vel->squared();
        if (lenSq <= lbl_805406A8 * FLT_EPSILON) {
            vec.set(lbl_8054067C,lbl_80540674,lbl_80540674);
            step = &vec;
            q = self;
            for (i = 0; i < *(s32*)(self + 0x2a8); i++) {
                obj = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x28c));
                if (obj != 0) {
                    *(JGeometry::TVec3f*)((char*)obj + 0xc) = *(JGeometry::TVec3f*)((char*)obj + 0xc) + *step;
                    fn_802C59B0(obj);
                }
                q += 4;
            }

            *(s32*)(self + 0x248) = 0;
            *(u8*)(self + 0x2b8) = 0;
            *(f32*)(self + 0x44) = lbl_80540674;
            *(f32*)(self + 0x40) = lbl_80540674;
            *(f32*)(self + 0x3c) = lbl_80540674;
            *(f32*)(self + 0x258) = lbl_80540674;
            *(f32*)(self + 0x254) = lbl_80540674;
            *(f32*)(self + 0x250) = lbl_80540674;
            if (*(s32*)(self + 0x2cc) == 1) {
                k = (*(u32*)(self + 0x90) >> 12) & 0x1f;
                if (k > 0) {
                    m = fn_802D6A9C();
                    fn_802D8050(m, k, 0, 0xff);
                }
            } else {
                k = (*(u32*)(self + 0x90) >> 17) & 0x1f;
                if (k > 0) {
                    m = fn_802D6A9C();
                    fn_802D8050(m, k, 0, 0xff);
                }
            }
            *(s32*)(self + 0x2cc) = 0;
            *(u8*)(self + 0x2c0) = 1;
        } else {
            if (*(s32*)(self + 0x2cc) == 1) {
                k = (*(u32*)(self + 0x90) >> 12) & 0x1f;
                if (k > 0) {
                    m = fn_802D6A9C();
                    fn_802D8050(m, k, 1, 0xff);
                }
            } else {
                k = (*(u32*)(self + 0x90) >> 17) & 0x1f;
                if (k > 0) {
                    m = fn_802D6A9C();
                    fn_802D8050(m, k, 1, 0xff);
                }
            }
        }
    }
}
#pragma opt_common_subs on
extern "C" void fn_802D79E8(void* mgr, s32 mode, f32 a, f32 b, s32 c);
extern "C" void fn_802A20F0(void* mgr, void* v, s32 a, s32 room, s32 c, s32 d);
extern "C" void fn_802A1050(void* mgr, void* v);
extern "C" void fn_8030C210(void* obj, void* v);
extern "C" void fn_802C59B0(void* obj);
extern "C" void fn_802D8050(void* mgr, s32 kind, s32 a, s32 b);
extern "C" void* lbl_8053AC98;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_8046C238[];
#pragma opt_common_subs off
extern "C" void fn_80298FC4(char* self) {
    s32 i;
    char* q;
    s32 n;
    s32 k;
    s32 idx;
    void* m;
    void* obj;
    f32 lenSq;
    JGeometry::TVec3f v;
    JGeometry::TVec3f vec;
    JGeometry::TVec3f off;
    JGeometry::TVec3f v2;
    JGeometry::TVec3f* vel;

    if (*(f32*)(self + 0x250) < lbl_80540674) {
        *(s32*)(self + 0x248) += 1;
        n = (*(u32*)(self + 0x90) >> 7) & 0x1f;
        n = n == 0 ? 0 : n + 7;
        m = fn_802D6A9C();
        fn_802D79E8(m, n, lbl_80540688, lbl_80540674, 1);
        if (*(f32*)(self + 0x250) < lbl_805406F4) {
            *(f32*)(self + 0xc) -= lbl_805406F0;
            *(f32*)(self + 0x250) += lbl_805406F0;
        } else {
            *(f32*)(self + 0xc) += *(f32*)(self + 0x250);
            *(f32*)(self + 0x258) = lbl_80540674;
            *(f32*)(self + 0x254) = lbl_80540674;
            *(f32*)(self + 0x250) = lbl_80540674;
        }

        v = *(JGeometry::TVec3f*)(self + 0xc);
        v.x += *(f32*)(self + 0x60);
        v.x += lbl_8054068C;
        v.y += *(f32*)(self + 0x64);
        v.y += lbl_80540678;
        v.z = lbl_80540674;
        for (int j = 0; j < 6; j++) {
            fn_802A20F0(lbl_8053AC98, &v, -1, *(s32*)(self + 4), 0, 1);
            fn_802A1050(lbl_8053AC98, &v);
            v.y += lbl_8054067C;
        }

        v2 = *(JGeometry::TVec3f*)(self + 0xc);
        idx = 1;
        if (*(s32*)(self + 0x2a4) > 0 && *(s32*)(self + 0x2cc) == -1) {
            idx ^= 1;
        }
        f32* entry = lbl_8046C238 + idx*3;
        off.x = entry[0];
        off.y = entry[1];
        off.z = entry[2];
        v2 += off;
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &v2);

        vel = (JGeometry::TVec3f*)(self + 0x250);
        lenSq = vel->squared();
        if (lenSq <= lbl_805406A8 * FLT_EPSILON) {
            vec.set(lbl_805406E4,lbl_80540674,lbl_80540674);
            q = self;
            for (i = 0; i < *(s32*)(self + 0x2a8); i++) {
                obj = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x28c));
                if (obj != 0) {
                    *(JGeometry::TVec3f*)((char*)obj + 0xc) = *(JGeometry::TVec3f*)((char*)obj + 0xc) + vec;
                    fn_802C59B0(obj);
                }
                q += 4;
            }

            *(s32*)(self + 0x248) = 0;
            *(u8*)(self + 0x2b8) = 0;
            *(f32*)(self + 0x44) = lbl_80540674;
            *(f32*)(self + 0x40) = lbl_80540674;
            *(f32*)(self + 0x3c) = lbl_80540674;
            *(f32*)(self + 0x258) = lbl_80540674;
            *(f32*)(self + 0x254) = lbl_80540674;
            *(f32*)(self + 0x250) = lbl_80540674;
            if (*(s32*)(self + 0x2cc) == 1) {
                k = (*(u32*)(self + 0x90) >> 17) & 0x1f;
                if (k > 0) {
                    m = fn_802D6A9C();
                    fn_802D8050(m, k, 0, 0xff);
                }
            } else {
                k = (*(u32*)(self + 0x90) >> 12) & 0x1f;
                if (k > 0) {
                    m = fn_802D6A9C();
                    fn_802D8050(m, k, 0, 0xff);
                }
            }
            *(s32*)(self + 0x2cc) = 0;
            *(u8*)(self + 0x2c0) = 1;
        } else {
            if (*(s32*)(self + 0x2cc) == 1) {
                k = (*(u32*)(self + 0x90) >> 17) & 0x1f;
                if (k > 0) {
                    m = fn_802D6A9C();
                    fn_802D8050(m, k, 1, 0xff);
                }
            } else {
                k = (*(u32*)(self + 0x90) >> 12) & 0x1f;
                if (k > 0) {
                    m = fn_802D6A9C();
                    fn_802D8050(m, k, 1, 0xff);
                }
            }
        }
    }
}
#pragma opt_common_subs on
extern "C" void fn_80299374(char* self) {
    char* obj;
    s32 mode;
    s32 idx;
    s32 k;
    char* q;
    s32 bits;
    f32 lenSq;
    JGeometry::TVec3f tmp;
    JGeometry::TVec3f v[1];
    JGeometry::TVec3f d;
    JGeometry::TVec3f sum;

    if (*(f32*)(self + 0x254) > lbl_80540674) {
        *(s32*)(self + 0x248) += 1;
        mode = (*(u32*)(self + 0x90) >> 7) & 0x1f;
        mode = (mode == 0) ? 0 : mode + 7;
        fn_802D79E8(fn_802D6A9C(), mode, lbl_80540688, lbl_80540674, 1);

        if (*(f32*)(self + 0x254) > lbl_805406F0) {
            *(f32*)(self + 0x10) += lbl_805406F0;
            *(f32*)(self + 0x254) -= lbl_805406F0;
        } else {
            *(f32*)(self + 0x10) += *(f32*)(self + 0x254);
            *(f32*)(self + 0x258) = lbl_80540674;
            *(f32*)(self + 0x254) = lbl_80540674;
            *(f32*)(self + 0x250) = lbl_80540674;
        }

        tmp = *(JGeometry::TVec3f*)(self + 0xc);
        tmp.x += *(f32*)(self + 0x60);
        tmp.x += lbl_80540678;
        tmp.y += *(f32*)(self + 0x6c);
        tmp.y -= lbl_8054068C;
        tmp.z = lbl_80540674;
        for (bits = 0; bits < 6; bits++) {
            fn_802A20F0(lbl_8053AC98, &tmp, -1, *(s32*)(self + 0x4), 0, 1);
            fn_802A1050(lbl_8053AC98, &tmp);
            tmp.x += lbl_8054067C;
        }

        sum = *(JGeometry::TVec3f*)(self + 0xc);
        idx = 2;
        if (*(s32*)(self + 0x2a4) > 0 && *(s32*)(self + 0x2cc) == -1) {
            idx ^= 1;
        }
        f32* entry = lbl_8046C238 + idx * 3;
        d.x = entry[0];
        d.y = entry[1];
        d.z = entry[2];
        sum += d;
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &sum);

        lenSq = ((JGeometry::TVec3f*)(self + 0x250))->squared();
        if (lenSq <= lbl_805406A8 * FLT_EPSILON) {
            v[0].x = lbl_80540674;
            v[0].y = lbl_8054067C;
            v[0].z = lbl_80540674;
            q = self;
            for (k = 0; k < *(s32*)(self + 0x2a8); k++) {
                obj = (char*)fn_801F666C(fn_801F856C(), *(s32*)(q + 0x28c));
                if (obj != 0) {
                    *(JGeometry::TVec3f*)(obj + 0xc) = *(JGeometry::TVec3f*)(obj + 0xc) + v[0];
                    fn_802C59B0(obj);
                }
                q += 4;
            }

            *(s32*)(self + 0x248) = 0;
            *(u8*)(self + 0x2b8) = 0;
            *(f32*)(self + 0x44) = lbl_80540674;
            *(f32*)(self + 0x40) = lbl_80540674;
            *(f32*)(self + 0x3c) = lbl_80540674;
            *(f32*)(self + 0x258) = lbl_80540674;
            *(f32*)(self + 0x254) = lbl_80540674;
            *(f32*)(self + 0x250) = lbl_80540674;
            if (*(s32*)(self + 0x2cc) == 1) {
                bits = (*(u32*)(self + 0x90) >> 22) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 0, 0xff);
                }
            } else {
                bits = *(u32*)(self + 0x90) >> 27;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 0, 0xff);
                }
            }
            *(s32*)(self + 0x2cc) = 0;
            *(u8*)(self + 0x2c0) = 1;
        } else {
            if (*(s32*)(self + 0x2cc) == 1) {
                bits = (*(u32*)(self + 0x90) >> 22) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 1, 0xff);
                }
            } else {
                bits = *(u32*)(self + 0x90) >> 27;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 1, 0xff);
                }
            }
        }
    }
}
#pragma opt_common_subs on
extern "C" void fn_80299720(char* self) {
    char* obj;
    s32 mode;
    s32 idx;
    s32 k;
    char* q;
    s32 bits;
    f32 lenSq;
    JGeometry::TVec3f tmp;
    JGeometry::TVec3f v;
    JGeometry::TVec3f d;
    JGeometry::TVec3f sum;

    if (*(f32*)(self + 0x254) < lbl_80540674) {
        *(s32*)(self + 0x248) += 1;
        mode = (*(u32*)(self + 0x90) >> 7) & 0x1f;
        mode = (mode == 0) ? 0 : mode + 7;
        fn_802D79E8(fn_802D6A9C(), mode, lbl_80540688, lbl_80540674, 1);

        if (*(f32*)(self + 0x254) < lbl_805406F4) {
            *(f32*)(self + 0x10) -= lbl_805406F0;
            *(f32*)(self + 0x254) += lbl_805406F0;
        } else {
            *(f32*)(self + 0x10) += *(f32*)(self + 0x254);
            *(f32*)(self + 0x258) = lbl_80540674;
            *(f32*)(self + 0x254) = lbl_80540674;
            *(f32*)(self + 0x250) = lbl_80540674;
        }

        tmp = *(JGeometry::TVec3f*)(self + 0xc);
        tmp.x += *(f32*)(self + 0x60);
        tmp.x += lbl_80540678;
        tmp.y += *(f32*)(self + 0x64);
        tmp.y += lbl_8054068C;
        tmp.z = lbl_80540674;
        for (bits = 0; bits < 6; bits++) {
            fn_802A20F0(lbl_8053AC98, &tmp, -1, *(s32*)(self + 0x4), 0, 1);
            fn_802A1050(lbl_8053AC98, &tmp);
            tmp.x += lbl_8054067C;
        }

        sum = *(JGeometry::TVec3f*)(self + 0xc);
        idx = 3;
        if (*(s32*)(self + 0x2a4) > 0 && *(s32*)(self + 0x2cc) == -1) {
            idx ^= 1;
        }
        f32* entry = lbl_8046C238 + idx * 3;
        d.x = entry[0];
        d.y = entry[1];
        d.z = entry[2];
        sum += d;
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &sum);

        lenSq = ((JGeometry::TVec3f*)(self + 0x250))->squared();
        if (lenSq <= lbl_805406A8 * FLT_EPSILON) {
            v.x = lbl_80540674;
            v.y = lbl_805406E4;
            v.z = lbl_80540674;
            q = self;
            for (k = 0; k < *(s32*)(self + 0x2a8); k++) {
                obj = (char*)fn_801F666C(fn_801F856C(), *(s32*)(q + 0x28c));
                if (obj != 0) {
                    *(JGeometry::TVec3f*)(obj + 0xc) = *(JGeometry::TVec3f*)(obj + 0xc) + v;
                    fn_802C59B0(obj);
                }
                q += 4;
            }

            *(s32*)(self + 0x248) = 0;
            *(u8*)(self + 0x2b8) = 0;
            *(f32*)(self + 0x44) = lbl_80540674;
            *(f32*)(self + 0x40) = lbl_80540674;
            *(f32*)(self + 0x3c) = lbl_80540674;
            *(f32*)(self + 0x258) = lbl_80540674;
            *(f32*)(self + 0x254) = lbl_80540674;
            *(f32*)(self + 0x250) = lbl_80540674;
            if (*(s32*)(self + 0x2cc) == 1) {
                bits = *(u32*)(self + 0x90) >> 27;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 0, 0xff);
                }
            } else {
                bits = (*(u32*)(self + 0x90) >> 22) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 0, 0xff);
                }
            }
            *(s32*)(self + 0x2cc) = 0;
            *(u8*)(self + 0x2c0) = 1;
        } else {
            if (*(s32*)(self + 0x2cc) == 1) {
                bits = *(u32*)(self + 0x90) >> 27;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 1, 0xff);
                }
            } else {
                bits = (*(u32*)(self + 0x90) >> 22) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 1, 0xff);
                }
            }
        }
    }
}
#pragma opt_common_subs reset
extern "C" void fn_80299AD0(char* self) {
    char* col;
    s32 j;
    s32 room;
    char* m;
    JGeometry::TBox2f* src;
    s32 i;
    s32 d;
    s32 dir;
    u8 ok;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    JGeometry::TBox2f box;
    JGeometry::TVec3f grid;
    JGeometry::TVec3f gridBase;
    PushProbe pt;

    if (!(JMathInlineVEC::PSVECSquareMag((JGeometry::TVec3f*)(self + 0x250)) <= 32.0f * FLT_EPSILON)) {
        return;
    }
    if (*(u8*)(self + 0x2c0) == 1) {
        *(u8*)(self + 0x2c0) = 0;
        return;
    }
    if (*(u8*)(self + 0x2b4) == 0) {
        return;
    }
    dir = -1;
    if (*(u8*)(self + 0x2b9) == 0) {
        if (fn_80239108(*(void**)(self + 0x198)) >= 4) {
            room = *(s32*)(self + 4);
            if (fn_8023DE58(0) == room) {
                d = fn_80238BC4(*(void**)(self + 0x198));
                if (d >= 0 && d < 4) {
                    *(s32*)(self + 0x2cc) = 1;
                    goto gotPlayer;
                }
            }
        }
        d = -1;
    gotPlayer:
        dir = d;
        if (dir == -1) {
            box.i.x = *(f32*)(self + 0x80);
            box.i.y = *(f32*)(self + 0x84);
            box.f.x = *(f32*)(self + 0x88);
            box.f.y = *(f32*)(self + 0x8c);
            box.addPos(*(JGeometry::TVec2f*)(self + 0xc));
            if (fn_80239470(&box, *(s32*)(self + 4), *(void**)(self + 0x198)) >= 0 &&
                fn_80238A68(*(void**)(self + 0x198)) >= 4 &&
                (d = fn_8023885C(*(void**)(self + 0x198))) >= 0 && d < 4) {
                if (d == 0) {
                    d = 1;
                } else if (d == 1) {
                    d = 0;
                } else if (d == 2) {
                    d = 3;
                } else if (d == 3) {
                    d = 2;
                }
                *(s32*)(self + 0x2cc) = -1;
            } else {
                d = -1;
            }
            dir = d;
        }
    }
    if (dir != 0) {
        return;
    }

    room = *(s32*)(self + 4);
    m = (char*)fn_802D6A9C();
    src = (JGeometry::TBox2f*)(room < 8 ? m + 0xcc : m + 0xdc);
    ok = 1;
    pt.pos = *(JGeometry::TVec3f*)(self + 0xc);
    HouseCopyBounds(pt.area, *src);
    pt.pos.x += *(f32*)(self + 0x68);
    pt.pos.x += lbl_80540678;
    x0 = (pt.area.i.x -= lbl_80540670);
    y0 = (pt.area.i.y -= lbl_80540670);
    x1 = (pt.area.f.x += lbl_80540670);
    y1 = (pt.area.f.y += lbl_80540670);
    pt.pos.y += *(f32*)(self + 0x64);
    pt.pos.y += lbl_80540678;
    pt.pos.z = lbl_80540674;
    for (i = 0; i < 6; i++) {
        if (!fn_802A1554(lbl_8053AC98, &pt) || HitsRect(self, &pt) == 1) {
            ok = 0;
            break;
        }
        bool in = false;
        if (pt.pos.x >= x0 && pt.pos.y >= y0 && pt.pos.x < x1 && pt.pos.y < y1) {
            in = true;
        }
        if (!in) {
            ok = 0;
            break;
        }
        pt.pos.y += lbl_8054067C;
    }
    if (!fn_802957CC(self, 0)) {
        ok = 0;
    }
    if (ok == 1) {
        if (dir == 0) {
            fn_80238E08(*(void**)(self + 0x198));
        }
        *(f32*)(self + 0x3c) = lbl_805406F0;
        *(u8*)(self + 0x2b8) = 1;
        fn_801F0E34(self, 0x30004, 0);
        *(f32*)(self + 0x250) = lbl_8054067C;
        *(s32*)(self + 0x248) = 0;
        if (*(u8*)(self + 0x24c) == 0) {
            *(u8*)(self + 0x24c) = 1;
            gridBase = *(JGeometry::TVec3f*)(self + 0xc);
            gridBase.x += *(f32*)(self + 0x60);
            gridBase.y += *(f32*)(self + 0x64);
            gridBase.x += lbl_80540678;
            gridBase.y += lbl_80540678;
            gridBase.z = lbl_80540674;
            grid = gridBase;
            for (i = 0; i < 6; i++) {
                grid.y = gridBase.y;
                for (j = 0, col = self; j < 6; j++, col += 2) {
                    fn_802A381C(lbl_8053AC98, &grid, 0, *(u16*)(col + 0x3b0));
                    fn_802A381C(lbl_8053AC98, &grid, 1, 0);
                    grid.y += lbl_8054067C;
                }
                grid.x += lbl_8054067C;
                self += 0xc;
            }
        }
    }
}

extern "C" u8 fn_802957CC(void* p, u8 mode);
extern "C" s32 fn_80239108(void* h);
extern "C" s32 fn_80238BC4(void* h);
extern "C" s32 fn_80239470(void* box, s32 room, void* h);
extern "C" s32 fn_80238A68(void* h);
extern "C" s32 fn_8023885C(void* h);
extern "C" void fn_80238E08(void* h);
extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* a, s32 room, void* v, void* h, s32 c);
extern "C" u8 fn_802A1554(void* g, void* v);
extern "C" void fn_802A381C(void* g, void* v, s32 a, s32 b);
extern "C" void fn_801F0E34(void* p, s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" f32 lbl_805406A8;
static inline bool HouseInsideBounds(f32 x0, f32 y0, f32 x1, f32 y1, const JGeometry::TVec3f& pos) {
    bool inside = false;
    f32 x = pos.x;
    if (x >= x0) {
        f32 y = pos.y;
        if (y >= y0 && x < x1 && y < y1) inside = true;
    }
    return inside;
}

static inline s32 HouseBoxMode(char* self, JGeometry::TBox2f& box) {
    if (fn_80239470(&box, *(s32*)(self + 4), *(void**)(self + 0x198)) >= 0
        && fn_80238A68(*(void**)(self + 0x198)) >= 4) {
        s32 result = fn_8023885C(*(void**)(self + 0x198));
        if (result >= 0 && result < 4) {
            if (result == 0) result = 1;
            else if (result == 1) result = 0;
            else if (result == 2) result = 3;
            else if (result == 3) result = 2;
            *(s32*)(self + 0x2cc) = -1;
            return result;
        }
    }
    return -1;
}

// Push direction from the linked player's input (sets 0x2cc to 1).
static inline s32 PushDirFromLink(char* self) {
    if (fn_80239108(*(void**)(self + 0x198)) >= 4) {
        s32 room = *(s32*)(self + 4);
        if (room == fn_8023DE58(0)) {
            s32 dir = fn_80238BC4(*(void**)(self + 0x198));
            if (dir >= 0 && dir < 4) {
                *(s32*)(self + 0x2cc) = 1;
                return dir;
            }
        }
    }
    return -1;
}

// Push direction from a contact on the side box (sets 0x2cc to -1).
static inline s32 PushDirFromContact(char* self, JGeometry::TBox2f& box);
static inline s32 PushDirFromContact(char* self) {
    JGeometry::TBox2f box;
    return PushDirFromContact(self, box);
}
static inline s32 PushDirFromContact(char* self, JGeometry::TBox2f& box) {
    box.set(*(JGeometry::TBox2f*)(self + 0x80));
    box.addPos(*(JGeometry::TVec2f*)(self + 0xc));
    if (fn_80239470(&box, *(s32*)(self + 4), *(void**)(self + 0x198)) >= 0 && fn_80238A68(*(void**)(self + 0x198)) >= 4) {
        s32 dir = fn_8023885C(*(void**)(self + 0x198));
        if (dir >= 0 && dir < 4) {
            if (dir == 0) {
                dir = 1;
            } else if (dir == 1) {
                dir = 0;
            } else if (dir == 2) {
                dir = 3;
            } else if (dir == 3) {
                dir = 2;
            }
            *(s32*)(self + 0x2cc) = -1;
            return dir;
        }
    }
    return -1;
}

extern "C" const f32 lbl_80540670;
extern "C" const f32 lbl_80540674;
extern "C" const f32 lbl_8054067C;
#pragma opt_common_subs off
static inline bool HouseContains(const JGeometry::TBox2f& area, JGeometry::TVec3f& pos) {
    bool inside = false;
    if (pos.x >= area.i.x && pos.y >= area.i.y && pos.x < area.f.x && pos.y < area.f.y) inside = true;
    return inside;
}
#pragma opt_common_subs on


static inline s32 HouseContactMode(char* self, s32& room) {
    if (fn_80239108(*(void**)(self + 0x198)) >= 4) {
        room = *(s32*)(self + 4);
        s32 current = fn_8023DE58(0);
        if (current != room) goto invalid;
        s32 result = fn_80238BC4(*(void**)(self + 0x198));
        if (result < 0 || result >= 4) goto invalid;
        *(s32*)(self + 0x2cc) = 1;
        return result;
    }
invalid:
    return -1;
}
static inline u8 HouseHitsRect(char* self, void* pos, s32& room, void*& handle) {
    handle = *(void**)(self + 0x198);
    room = *(s32*)(self + 4);
    char* base = (char*)fn_8020D58C();
    return fn_8020D6AC(base + 4 + *(u8*)(base + 1) * 0x784, room, pos, handle, 0);
}

extern "C" void fn_80299FB0(char* self) {
    s32 room;
    void* handle;
    s32 mode;
    u8 found;
    s32 i;
    s32 j;
    char* row;
    char* col;
    JGeometry::TBox2f area;
    JGeometry::TVec3f v;
    JGeometry::TBox2f box;
    JGeometry::TVec3f grid;
    JGeometry::TVec3f gridBase;

    if (!(JMathInlineVEC::PSVECSquareMag((JGeometry::TVec3f*)(self + 0x250)) <= 32.0f * FLT_EPSILON)) {
        return;
    }
    if (*(u8*)(self + 0x2c0) == 1) {
        *(u8*)(self + 0x2c0) = 0;
        return;
    }
    if (*(u8*)(self + 0x2b4) == 0) {
        return;
    }
    mode = -1;
    if (*(u8*)(self + 0x2b9) == 0) {
        mode = HouseContactMode(self, room);
        if (mode == -1) {
            mode = PushDirFromContact(self, box);
        }
    }
    if (mode != 1) {
        return;
    }
    room = *(s32*)(self + 4);
    char* manager = (char*)fn_802D6A9C();
    area = *(JGeometry::TBox2f*)(room < 8 ? manager + 0xcc : manager + 0xdc);
    found = 1;
    v = *(JGeometry::TVec3f*)(self + 0xc);
    area.i.x -= lbl_80540670;
    area.i.y -= lbl_80540670;
    area.f.x += lbl_80540670;
    area.f.y += lbl_80540670;
    v.x += *(f32*)(self + 0x60);
    v.x -= 8.0f;
    v.y += *(f32*)(self + 0x64);
    v.y += 8.0f;
    v.z = lbl_80540674;
    for (i = 0; i < 6; i++) {
        if (!fn_802A1554(lbl_8053AC98, &v) || HouseHitsRect(self, &v, room, handle) == 1) {
            found = 0;
            break;
        }
        bool in = HouseContains(area, v);
        if (!in) {
            found = 0;
            break;
        }
        v.y += lbl_8054067C;
    }
    if (!fn_802957CC(self, 1)) {
        found = 0;
    }
    if (found != 1) {
        return;
    }
    if (mode == 1) {
        fn_80238E08(*(void**)(self + 0x198));
        *(f32*)(self + 0x3c) = lbl_805406F4;
        *(u8*)(self + 0x2b8) = 1;
        fn_801F0E34(self, 0x30004, 0);
    }
    *(f32*)(self + 0x250) = lbl_805406E4;
    *(s32*)(self + 0x248) = i = 0;
    if (*(u8*)(self + 0x24c) == 0) {
        *(u8*)(self + 0x24c) = 1;
        gridBase = *(JGeometry::TVec3f*)(self + 0xc);
        gridBase.x += *(f32*)(self + 0x60);
        gridBase.y += *(f32*)(self + 0x64);
        gridBase.x += lbl_80540678;
        gridBase.y += lbl_80540678;
        gridBase.z = lbl_80540674;
        grid = gridBase;
        for (; i < 6; i++, self += 0xc) {
            grid.y = gridBase.y;
            for (room = 0, handle = self; room < 6; room++, handle = (char*)handle + 2) {
                fn_802A381C(lbl_8053AC98, &grid, 0, *(u16*)((char*)handle + 0x3b0));
                fn_802A381C(lbl_8053AC98, &grid, 1, 0);
                grid.y += lbl_8054067C;
            }
            grid.x += lbl_8054067C;
        }
    }
}

#pragma opt_lifetimes off
extern "C" void fn_8029A494(char* self) {
    s32 mode;
    s32 room;
    void* h;
    char* row;
    char* col;
    char* base;
    s32 j;
    u8 ok;
    f32 lenSq;
    JGeometry::TVec3f* vel;
    JGeometry::TBox2f zone;
    JGeometry::TVec3f v;
    JGeometry::TBox2f box;
    JGeometry::TVec3f grid;
    JGeometry::TVec3f pos;

    vel = (JGeometry::TVec3f*)(self + 0x250);
    lenSq = JMathInlineVEC::PSVECSquareMag(vel);
    if (lenSq <= lbl_805406A8 * FLT_EPSILON) {
        if (*(u8*)(self + 0x2c0) == 1) {
            *(u8*)(self + 0x2c0) = 0;
            return;
        }
        if (*(u8*)(self + 0x2b4) == 0) {
            return;
        }
        mode = -1;
        if (*(u8*)(self + 0x2b9) == 0) {
            mode = HouseContactMode(self, room);
            if (mode == -1) {
                box.i.x = *(f32*)(self + 0x80);
                box.i.y = *(f32*)(self + 0x84);
                box.f.x = *(f32*)(self + 0x88);
                box.f.y = *(f32*)(self + 0x8c);
                box.addPos(*(JGeometry::TVec2f*)(self + 0xc));
                mode = HouseBoxMode(self, box);
            }
        }
        if (mode != 2) {
            return;
        }
        room = *(s32*)(self + 4);
        base = (char*)fn_802D6A9C();
        const u32* zoneSrc = (const u32*)(room < 8 ? base + 0xcc : base + 0xdc);
        ((u32*)&zone)[0] = zoneSrc[0];
        ((u32*)&zone)[1] = zoneSrc[1];
        ((u32*)&zone)[2] = zoneSrc[2];
        ((u32*)&zone)[3] = zoneSrc[3];
        u8 flag = 1;
        s32 i = 0;
        f32 y0, x1, step;
        zone.i.x -= lbl_80540670;
        y0 = zone.i.y - lbl_80540670;
        x1 = zone.f.x + lbl_80540670;
        const f32 y1 = zone.f.y + lbl_80540670;
        zone.i.y = y0;
        zone.f.x = x1;
        zone.f.y = y1;
        step = 16.0f;
        v = *(JGeometry::TVec3f*)(self + 0xc);
        v.x += *(f32*)(self + 0x60);
        v.x += 8.0f;
        v.y += *(f32*)(self + 0x6c);
        v.y += 8.0f;
        v.z = 0.0f;
        for (; i < 6; i++) {
            if (!fn_802A1554(lbl_8053AC98, &v) || HouseHitsRect(self, &v, room, h) == 1) {
                flag = 0;
                break;
            }
            ok = HouseInsideBounds(zone.i.x, y0, x1, y1, v);
            if (!ok) {
                flag = 0;
                break;
            }
            v.x += step;
        }
        if (!fn_802957CC(self, 2)) {
            flag = 0;
        }
        if (flag != 1) {
            return;
        }
        if (mode == 2) {
            fn_80238E08(*(void**)(self + 0x198));
            *(f32*)(self + 0x40) = 0.32f;
            *(u8*)(self + 0x2b8) = 1;
        }
            fn_801F0E34(self, 0x30004, 0);
            *(f32*)(self + 0x254) = 16.0f;
            *(s32*)(self + 0x248) = i = 0;
            if (*(u8*)(self + 0x24c) != 0) {
                return;
            }
            *(u8*)(self + 0x24c) = 1;
        pos = *(JGeometry::TVec3f*)(self + 0xc);
        pos.x += *(f32*)(self + 0x60);
        pos.x += 8.0f;
        pos.y += *(f32*)(self + 0x64);
        pos.y += 8.0f;
        pos.z = 0.0f;
        grid = pos;
        for (; i < 6; i++, self += 0xc) {
            grid.y = pos.y;
            for (j = 0, col = self; j < 6; j++, col += 2) {
                fn_802A381C(lbl_8053AC98, &grid, 0, *(u16*)(col + 0x3b0));
                fn_802A381C(lbl_8053AC98, &grid, 1, 0);
                grid.y += 16.0f;
            }
            grid.x += 16.0f;
        }
    }
}
#pragma opt_lifetimes reset
static inline int HouseFallMode(char* self) {
    if (fn_80239108(*(void**)(self + 0x198)) >= 4) {
        int room = *(s32*)(self + 4);
        if (room == fn_8023DE58(0)) {
            s32 r = fn_80238BC4(*(void**)(self + 0x198));
            if (r >= 0 && r < 4) {
                *(s32*)(self + 0x2cc) = 1;
                return r;
            }
        }
    }
    return -1;
}
static inline s32 HouseBoxMode(char* self, JGeometry::TBox2f* box) {
    box->set(*(JGeometry::TBox2f*)(self + 0x80));
    box->addPos(*(JGeometry::TVec2f*)(self + 0xc));
    if (fn_80239470(box, *(s32*)(self + 4), *(void**)(self + 0x198)) >= 0 &&
        fn_80238A68(*(void**)(self + 0x198)) >= 4) {
        s32 r = fn_8023885C(*(void**)(self + 0x198));
        if (r >= 0 && r < 4) {
            if (r == 0) r = 1;
            else if (r == 1) r = 0;
            else if (r == 2) r = 3;
            else if (r == 3) r = 2;
            *(s32*)(self + 0x2cc) = -1;
            return r;
        }
    }
    return -1;
}
#pragma opt_lifetimes off
extern "C" void fn_8029A974(char* self) {
    s32 room;
    void* handle;
    s32 mode;
    u8 found;
    s32 i;
    s32 j;
    char* row;
    char* col;
    JGeometry::TBox2f area;
    JGeometry::TVec3f v;
    JGeometry::TBox2f box;
    JGeometry::TVec3f grid;
    JGeometry::TVec3f gridBase;

    if (!(JMathInlineVEC::PSVECSquareMag((JGeometry::TVec3f*)(self + 0x250)) <= 32.0f * FLT_EPSILON)) {
        return;
    }
    if (*(u8*)(self + 0x2c0) == 1) {
        *(u8*)(self + 0x2c0) = 0;
        return;
    }
    if (*(u8*)(self + 0x2b4) == 0) {
        return;
    }
    mode = -1;
    if (*(u8*)(self + 0x2b9) == 0) {
        mode = HouseContactMode(self, room);
        if (mode == -1) {
            mode = PushDirFromContact(self, box);
        }
    }
    if (mode != 3) {
        return;
    }
    room = *(s32*)(self + 4);
    char* manager = (char*)fn_802D6A9C();
    area = *(JGeometry::TBox2f*)(room < 8 ? manager + 0xcc : manager + 0xdc);
    found = 1;
    v = *(JGeometry::TVec3f*)(self + 0xc);
    area.i.x -= lbl_80540670;
    area.i.y -= lbl_80540670;
    area.f.x += lbl_80540670;
    area.f.y += lbl_80540670;
    v.x += *(f32*)(self + 0x60);
    v.x += 8.0f;
    v.y += *(f32*)(self + 0x64);
    v.y -= 8.0f;
    v.z = lbl_80540674;
    for (i = 0; i < 6; i++) {
        if (!fn_802A1554(lbl_8053AC98, &v) || HouseHitsRect(self, &v, room, handle) == 1) {
            found = 0;
            break;
        }
        bool in = false;
        if (v.x >= area.i.x && v.y >= area.i.y && v.x < area.f.x && v.y < area.f.y) {
            in = true;
        }
        if (!in) {
            found = 0;
            break;
        }
        v.x += lbl_8054067C;
    }
    if (!fn_802957CC(self, 3)) {
        found = 0;
    }
    if (found != 1) {
        return;
    }
    if (mode == 3) {
        fn_80238E08(*(void**)(self + 0x198));
        *(f32*)(self + 0x40) = lbl_805406F4;
        *(u8*)(self + 0x2b8) = 1;
    }
    fn_801F0E34(self, 0x30004, 0);
    *(f32*)(self + 0x254) = lbl_805406E4;
    *(s32*)(self + 0x248) = i = 0;
    if (*(u8*)(self + 0x24c) == 0) {
        *(u8*)(self + 0x24c) = 1;
        gridBase = *(JGeometry::TVec3f*)(self + 0xc);
        f32 y;
        f32 x;
        x = gridBase.x + *(f32*)(self + 0x60);
        y = gridBase.y + *(f32*)(self + 0x64);
        gridBase.x = x;
        gridBase.y = y;
        gridBase.x = x + lbl_80540678;
        gridBase.y = y + lbl_80540678;
        gridBase.z = lbl_80540674;
        grid = gridBase;
        for (; i < 6; i++, self += 0xc) {
            grid.y = gridBase.y;
            for (room = 0, handle = self; room < 6; room++, handle = (char*)handle + 2) {
                fn_802A381C(lbl_8053AC98, &grid, 0, *(u16*)((char*)handle + 0x3b0));
                fn_802A381C(lbl_8053AC98, &grid, 1, 0);
                grid.y += lbl_8054067C;
            }
            grid.x += lbl_8054067C;
        }
    }
}
#pragma opt_lifetimes reset
extern "C" void fn_8029AE58(char* p) {
    const f32 center = lbl_80540678;
    JGeometry::TVec3f v;
    JGeometry::TVec3f pos;
    JGeometry::TVec3f origin;
    origin = *(JGeometry::TVec3f*)(p + 0xc);
    origin.x += *(f32*)(p + 0x60);
    origin.y += *(f32*)(p + 0x64);
    origin.x += center;
    origin.y += center;
    origin.z = 0.0f;
    pos = origin;
    s32 j;
    s32 i;
    char* col;
    char* row = p;
    for (i = 0; i < 6; i++) {
        pos.y = origin.y;
        col = row;
        for (j = 0; j < 6; j++, col += 2) {
            *(u16*)(col + 0x320) = fn_80226850(&pos, 1);
            *(u16*)(col + 0x368) = fn_80226850(&pos, 0);
            if (*(u8*)(p + 0x2b5) == 0) {
                if (*(s32*)(p + 0x244) == 0 || *(s32*)(p + 0x244) == 2)
                    *(u16*)(col + 0x3b0) = 0x78;
                else
                    *(u16*)(col + 0x3b0) = 0x360;
            }
            pos.y += 16.0f;
        }
        row += 12;
        pos.x += 16.0f;
    }
    *(u8*)(p + 0x2b5) = 1;
    s32 warp = -1;
    s32 flame = -1;
    s32 door = -1;
    f32 left, top, right, bottom;
    left = *(f32*)(p + 0x60);
    right = *(f32*)(p + 0x68);
    top = *(f32*)(p + 0x64);
    bottom = *(f32*)(p + 0x6c);
    left += *(f32*)(p + 0xc);
    right += *(f32*)(p + 0xc);
    top += *(f32*)(p + 0x10);
    bottom += *(f32*)(p + 0x10);
    for (;;) {
        warp = fn_801F78F4(fn_801F856C(), 0x57415250, warp);
        if (warp < 0) break;
        char* other = (char*)fn_801F666C(fn_801F856C(), warp);
        if (!other) continue;
        s32 room = *(s32*)((char*)fn_802D6A9C() + 0x14);
        if (room != *(s32*)(other + 0x244)) continue;
        s32 stage = *(s32*)((char*)fn_802D6A9C() + 0x18);
        if (stage != *(s32*)(other + 0x248)) continue;
        {
            s32 otherRoom = *(s32*)(other + 4);
            if (otherRoom == HouseDestination(p) && WarpDestinationIs(other, *(s32*)(p + 4))) {
                if (*(s32*)(p + 0x29c) < 4) {
                    ((HOUSLinks*)p)->outgoing[((HOUSLinks*)p)->outgoingCount] = warp;
                    *(s32*)(p + 0x29c) += 1;
                }
            } else if (HouseDestination(p) == WarpDestination(other) && *(s32*)(p + 4) == otherRoom) {
                if (*(s32*)(p + 0x2a0) < 4) {
                    ((HOUSLinks*)p)->incoming[((HOUSLinks*)p)->incomingCount] = warp;
                    *(s32*)(p + 0x2a0) += 1;
                    v = *(JGeometry::TVec3f*)(other + 0xc);
                    switch (*(u32*)(other + 0x90) & 0x7f) {
                    case 0: case 3: v.y -= 2.0f; break;
                    case 1: case 2: v.y += 2.0f; break;
                    case 0x17: v.x += 2.0f; break;
                    }
                    *(JGeometry::TVec3f*)(other + 0xc) = v;
                }
            }
        }
    }
    for (s32 i = 0; i < *(s32*)(p + 0x29c); i++) {
        char* other = (char*)fn_801F666C(fn_801F856C(), *(s32*)(p + i * 4 + 0x25c));
        if (other) {
            *(f32*)(p + 0x2dc + i * 8) = *(f32*)(other + 0xc);
            *(f32*)(p + 0x2e0 + i * 8) = *(f32*)(other + 0x10);
        }
    }
    for (;;) {
        flame = fn_801F78F4(fn_801F856C(), 0x464c4d45, flame);
        if (flame < 0) break;
        if (fn_801F666C(fn_801F856C(), flame)) {
            if (*(s32*)(p + 0x2a4) >= 4) break;
            ((HOUSLinks*)p)->flames[((HOUSLinks*)p)->flameCount] = flame;
            *(s32*)(p + 0x2a4) += 1;
        }
    }
    for (;;) {
        door = fn_801F78F4(fn_801F856C(), 0x444f4f52, door);
        if (door < 0) break;
        char* other = (char*)fn_801F666C(fn_801F856C(), door);
        if (other) {
            bool inside = false;
            f32 y;
            f32 x = *(f32*)(other + 0xc);
            if (x >= left) {
                y = *(f32*)(other + 0x10);
                if (y >= top && x < right && y < bottom) inside = true;
            }
            if (inside) {
                if (*(s32*)(p + 0x2a8) >= 4) break;
                ((HOUSLinks*)p)->doors[((HOUSLinks*)p)->doorCount] = door;
                *(s32*)(p + 0x2a8) += 1;
            }
        }
    }
}

extern "C" void fn_8029B2EC(void* p) {
    *(f32*)((char*)p + 0x60) = -48.0f;
    *(f32*)((char*)p + 0x64) = -48.0f;
    *(f32*)((char*)p + 0x68) = 48.0f;
    *(f32*)((char*)p + 0x6c) = 48.0f;
    *(f32*)((char*)p + 0x80) = -48.0f;
    *(f32*)((char*)p + 0x84) = -48.0f;
    *(f32*)((char*)p + 0x88) = 48.0f;
    *(f32*)((char*)p + 0x8c) = 48.0f;
    *(s32*)((char*)p + 0xb8) = 1;
    *(s32*)((char*)p + 0xbc) = 3;
    *(s32*)((char*)p + 0x1a4) = 4;
    *(s32*)((char*)p + 0x108) = 10000;
    *(f32*)((char*)p + 0x250) = 0.0f;
    *(f32*)((char*)p + 0x254) = 0.0f;
    *(f32*)((char*)p + 0x258) = 0.0f;
    *(s32*)((char*)p + 0x2ac) = 0;
    *(u8*)((char*)p + 0x24c) = 0;
    *(s32*)((char*)p + 0x248) = 0;
    *(f32*)((char*)p + 0x54) = 1.0f;
    *(f32*)((char*)p + 0x58) = 1.0f;
    *(f32*)((char*)p + 0x5c) = 1.0f;
    *(s32*)((char*)p + 0x230) = 0;
    *(s32*)((char*)p + 0x244) = *(u32*)((char*)p + 0x90) & 3;
    *(u8*)((char*)p + 0x2b9) = (*(u32*)((char*)p + 0x90) >> 2) & 1;
    *(u8*)((char*)p + 0x2b5) = 0;
    *(u8*)((char*)p + 0x2b8) = 0;
    *(s32*)((char*)p + 0x2b0) = (*(u32*)((char*)p + 0x90) >> 3) & 3;
    *(u8*)((char*)p + 0x2b4) = 1;
    *(u8*)((char*)p + 0x2b6) = 1;
    *(u8*)((char*)p + 0x2b7) = 1;
    if (*(s32*)((char*)p + 0x244) == 0) {
        *(u8*)((char*)p + 0x2b6) = 0;
    } else if (*(s32*)((char*)p + 0x244) == 1) {
        *(u8*)((char*)p + 0x2b6) = 0;
        *(u8*)((char*)p + 0x2b7) = 0;
    }
    *(s32*)((char*)p + 0x25c) = -1;
    *(s32*)((char*)p + 0x26c) = -1;
    *(s32*)((char*)p + 0x260) = -1;
    *(s32*)((char*)p + 0x270) = -1;
    *(s32*)((char*)p + 0x264) = -1;
    *(s32*)((char*)p + 0x274) = -1;
    *(s32*)((char*)p + 0x268) = -1;
    *(s32*)((char*)p + 0x278) = -1;
    *(s32*)((char*)p + 0x27c) = -1;
    *(s32*)((char*)p + 0x280) = -1;
    *(s32*)((char*)p + 0x284) = -1;
    *(s32*)((char*)p + 0x288) = -1;
    *(s32*)((char*)p + 0x28c) = -1;
    *(s32*)((char*)p + 0x290) = -1;
    *(s32*)((char*)p + 0x294) = -1;
    *(s32*)((char*)p + 0x298) = -1;
    *(s32*)((char*)p + 0x29c) = 0;
    *(s32*)((char*)p + 0x2a0) = 0;
    *(s32*)((char*)p + 0x2a4) = 0;
    *(s32*)((char*)p + 0x2a8) = 0;
    *(s32*)((char*)p + 0x2cc) = 0;
    *(u8*)((char*)p + 0x2c0) = 0;
    *(u8*)((char*)p + 0x2ba) = 0;
    *(u8*)((char*)p + 0x2bb) = 0;
    *(u8*)((char*)p + 0x2bc) = 0;
    *(u8*)((char*)p + 0x2bd) = 0;
    *(u8*)((char*)p + 0x2be) = 0;
    *(u8*)((char*)p + 0x2bf) = 0;
    *(s32*)((char*)p + 0x2c4) = 0;
    *(s32*)((char*)p + 0x234) = 0;
    *(s32*)((char*)p + 0x2fc) = 0;
    *(s32*)((char*)p + 0x300) = 0;
    *(s32*)((char*)p + 0x304) = 0;
    *(s32*)((char*)p + 0x308) = 0;
    *(s32*)((char*)p + 0x310) = 0;
    *(s32*)((char*)p + 0x314) = 0;
    *(s32*)((char*)p + 0x318) = 0;
    *(s32*)((char*)p + 0x31c) = 0;
    *(s32*)((char*)p + 0x30c) = 0;
    *(f32*)((char*)p + 0x238) = *(f32*)((char*)p + 0xc);
    *(f32*)((char*)p + 0x23c) = *(f32*)((char*)p + 0x10);
    *(f32*)((char*)p + 0x240) = *(f32*)((char*)p + 0x14);
}

extern "C" void* fn_8029B484(void* p, s16 flag) {
    char* col;
    char* row;
    s32* q;
    s32 i;
    s32 j;
    int k;

    if (p != 0) {
        row = (char*)p;
        *(char**)p = __vt__4HOUS;
        for (i = 0; i < 2; i++) {
            for (j = 0, col = row; j < 2; j++) {
                fn_801EE434(*(s32*)(col + 0x2fc));
                col += 4;
            }
            row += 8;
        }
        for (k = 0, q = (s32*)p; k < 4; k++) {
            fn_801EE434(q[0x310 / 4]);
            q++;
        }
        __dt__5ActorFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

#pragma merge_bss off
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "string.h"
#pragma merge_bss reset
