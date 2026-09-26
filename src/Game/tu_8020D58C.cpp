// TU 0x8020d58c-0x8020db74: double-buffered list of actor hit rectangles.
// A function-local static manager holds two lists of up to 80 rects; the
// game flips them each frame, adds rects for actors and queries them.
#include "types.h"
#include "JSystem/JGeometry/Box.h"

typedef JGeometry::TBox2<f32> HitBox;

struct HitRect {
    HitRect() {}
    HitBox box;  // 0x0
    s32 kind;    // 0x10
    s32 actorId; // 0x14
};

struct HitRectList {
    HitRectList();
    void add(const HitBox& box, s32 kind, s32 actorId) {
        if (count < 80 && box.f.x - box.i.x > 0.0f && box.f.y - box.i.y > 0.0f) {
            rects[count].box = box;
            rects[count].kind = kind;
            rects[count].actorId = actorId;
            count++;
        }
    }

    void add(f32 x0, f32 y0, f32 x1, f32 y1, s32 kind, s32 actorId) {
        if (count < 80 && x1 - x0 > 0.0f && y1 - y0 > 0.0f) {
            rects[count].box.set(x0, y0, x1, y1);
            rects[count].kind = kind;
            rects[count].actorId = actorId;
            count++;
        }
    }

    s32 count;          // 0x0
    HitRect rects[80];  // 0x4
};

struct HitRectMgr {
    HitRectMgr() { reset(); }
    void reset() {
        cur = 0;
        other = 1;
        lists[0].count = 0;
        lists[1].count = 0;
    }

    u8 cur;                // 0x0
    u8 other;              // 0x1
    HitRectList lists[2];  // 0x4
};

extern "C" void* fn_801F856C(void);
extern "C" u8* fn_801F666C(void* mgr, s32 id);

extern "C" HitRectMgr* fn_8020D58C() {
    static HitRectMgr sMgr;
    return &sMgr;
}

HitRectList::HitRectList() {
    count = 0;
}

extern "C" void fn_8020D660(HitRectMgr* m) {
    m->cur ^= 1;
    m->other ^= 1;
    *(s32*)((u8*)m + m->cur * sizeof(HitRectList) + 4) = 0;
}

extern "C" void fn_8020D690(HitRectMgr* m) {
    m->reset();
}

static inline bool hitContains(const HitBox& b, const JGeometry::TVec2<f32>& p) {
    return p.x >= b.i.x && p.y >= b.i.y && p.x < b.f.x && p.y < b.f.y;
}

// NONMATCHING: register allocation (retail gives the params r28-r31).
extern "C" bool fn_8020D6AC(HitRectList* l, s32 kind, const JGeometry::TVec2<f32>& pos, s32 exclude, const u32* names) {
    bool hit = false;
    s32 n = l->count;
    for (s32 i = 0; i < n; i++) {
        HitRect* r = &l->rects[i];
        if (r->kind == kind) {
            s32 id = r->actorId;
            if (id != exclude && hitContains(r->box, pos)) {
                hit = true;
                if (names != 0) {
                    u8* a = fn_801F666C(fn_801F856C(), id);
                    if (a == 0) {
                        hit = false;
                    } else {
                        for (const u32* p = names; *p != 'NULL'; p++) {
                            if (*p == *(u32*)(a + 0x1a0)) {
                                hit = false;
                                break;
                            }
                        }
                    }
                }
                if (hit) break;
            }
        }
    }
    return hit;
}

extern "C" void fn_8020D7D0(HitRectList* l, s32 actorId) {
    u8* a = fn_801F666C(fn_801F856C(), actorId);
    if (a != 0 && a[0x11c] != 0) {
        f32* pos = (f32*)(a + 0xc);
        f32* box = (f32*)(a + 0x80);
        HitBox b = *(HitBox*)box;
        b.addPos(*(JGeometry::TVec2<f32>*)pos);
        l->add(b.i.x, b.i.y, b.f.x, b.f.y, *(s32*)(a + 0x4), actorId);
    }
}

// NONMATCHING: retail keeps box.i.x in f3 and reloads the other fields.
extern "C" void fn_8020D8C0(HitRectList* l, const HitBox& box, s32 kind, s32 actorId) {
    l->add(box, kind, actorId);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
