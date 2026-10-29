#ifndef GAME_HITRECT_H
#define GAME_HITRECT_H
#include "JSystem/JGeometry/Box.h"
#include "types.h"
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
#endif
