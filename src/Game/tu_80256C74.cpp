// Player collision-cache and state helpers, retail 0x80256C74-0x8025EB18.
#include "types.h"
#include "JSystem/JGeometry/Box.h"

#pragma auto_inline off

#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define U32(p, o) (*(u32*)((u8*)(p) + (o)))
#define S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define F32(p, o) (*(f32*)((u8*)(p) + (o)))
#define PTR(p, o) (*(u8**)((u8*)(p) + (o)))
#define V2(p, o) (*(JGeometry::TVec2<f32>*)((u8*)(p) + (o)))
#define V3(p, o) (*(JGeometry::TVec3<f32>*)((u8*)(p) + (o)))
#define BOX(p, o) (*(JGeometry::TBox2<f32>*)((u8*)(p) + (o)))

extern "C" {
void* fn_801F856C();
u8* fn_801F666C(void*, s32);
u8 fn_8030EA0C(void*);
u8 fn_80270A8C(void*);
u8 fn_80270C88(void*);
u8 Player_GetField_0x454(void*);
s32 fn_802416C4(void*);
s32 fn_80241794(void*);
u8 fn_80251AEC(void*, s32);
void fn_802BAA00(void*);
s32 fn_802415CC(void*);
void fn_80268B3C(void*);
s32 Actor_CreateByID(void* mgr, u32 fourCC, u32 owner, void* pos, u32 param, s32 a, s32 b);
s32 fn_8026FC20(void*);
}

extern u8* lbl_8053AAF8;
extern const f32 lbl_805400C0;
extern const f32 lbl_805400C4;
extern const f32 lbl_805400C8;
extern const f32 lbl_805400CC;
extern const f32 lbl_805400D0;
extern const f32 lbl_805400D4;
extern const f32 lbl_805400D8;
extern const f32 lbl_8054010C;

extern "C" u8 GetBusyLocked(void*);
extern "C" u8 fn_802413F0(void*);
extern "C" bool fn_80256C74(u8* p, const f32* bounds, s32 id) {
    if (GetBusyLocked(p)) {
        return false;
    }
    if (Player_GetField_0x454(p)) {
        return false;
    }
    if (!fn_80270A8C(p)) {
        return false;
    }
    if (U8(p, 0xba4) == 0) {
        return false;
    }
    if (!fn_802413F0(p)) {
        return false;
    }
    if (id != S32(p, 0x3b4)) {
        return false;
    }
    f32 x0 = F32(p, 0x5dc);
    f32 y0 = F32(p, 0x5e0);
    f32 x1 = F32(p, 0x5e4);
    f32 y1 = F32(p, 0x5e8);
    if (x0 <= bounds[0]) {
        x0 = bounds[0];
    }
    if (y0 <= bounds[1]) {
        y0 = bounds[1];
    }
    if (x1 >= bounds[2]) {
        x1 = bounds[2];
    }
    if (y1 >= bounds[3]) {
        y1 = bounds[3];
    }
    bool ok = false;
    if (x0 <= x1 && y0 <= y1) {
        ok = true;
    }
    if (ok) {
        return true;
    }
    return false;
}

extern "C" bool fn_80256DCC(u8* p, const JGeometry::TBox2<f32>* bounds, s32 id, JGeometry::TVec2<f32>* center) {
    if (GetBusyLocked(p)) {
        return false;
    }
    if (Player_GetField_0x454(p)) {
        return false;
    }
    if (U8(p, 0xb9e) == 0) {
        return false;
    }
    if (!fn_802413F0(p)) {
        return false;
    }
    if (id != S32(p, 0x3b4)) {
        return false;
    }
    JGeometry::TBox2<f32>& box = BOX(p, 0x5cc);
    JGeometry::TBox2<f32> overlap = box;
    overlap.i.setMax(bounds->i);
    overlap.f.setMin(bounds->f);
    if (!overlap.isValid()) {
        center->x = lbl_805400C0 * (box.i.x - box.f.x) + box.f.x;
        center->y = lbl_805400C0 * (box.i.y - box.f.y) + box.f.y;
        return true;
    }
    return false;
}

extern "C" bool fn_80256F44(u8* p, const f32* bounds, s32 id, JGeometry::TVec2<f32>* center) {
    if (GetBusyLocked(p)) {
        return false;
    }
    if (Player_GetField_0x454(p)) {
        return false;
    }
    if (!fn_802413F0(p)) {
        return false;
    }
    if (id != S32(p, 0x3b4)) {
        return false;
    }
    if (U8(p, 0xb99) == 0) {
        return false;
    }
    f32 x0 = F32(p, 0x5b0);
    f32 y0 = F32(p, 0x5b4);
    f32 x1 = F32(p, 0x5b8);
    f32 y1 = F32(p, 0x5bc);
    if (!(x0 <= bounds[0])) {
        x0 = bounds[0];
    }
    if (!(y0 <= bounds[1])) {
        y0 = bounds[1];
    }
    if (!(x1 >= bounds[2])) {
        x1 = bounds[2];
    }
    if (!(y1 >= bounds[3])) {
        y1 = bounds[3];
    }
    if (x0 <= x1 && y0 <= y1) {
        center->x = lbl_805400C0 * (F32(p, 0x5b0) - F32(p, 0x5b8)) + F32(p, 0x5b8);
        center->y = lbl_805400C0 * (F32(p, 0x5b4) - F32(p, 0x5bc)) + F32(p, 0x5bc);
        return true;
    }
    return false;
}

extern "C" bool fn_802573E0(u8* p, const JGeometry::TBox2<f32>* bounds,
                             s32 id, JGeometry::TVec2<f32>* center) {
    if (S32(p, 0xb38) < 0) {
        return false;
    }
    if (S32(p, 0xb6c) != id) {
        return false;
    }
    JGeometry::TBox2<f32>& box = BOX(p, 0x590);
    JGeometry::TBox2<f32> overlap = box;
    if (overlap.intersect(*bounds)) {
        center->x = lbl_805400C0 * (box.i.x - box.f.x) + box.f.x;
        center->y = lbl_805400C0 * (box.i.y - box.f.y) + box.f.y;
        return true;
    }
    return false;
}

extern "C" bool fn_802574CC(u8* p, const JGeometry::TBox2<f32>* bounds,
                             s32 id, JGeometry::TVec2<f32>* center) {
    if (S32(p, 0xb18) < 0) {
        return false;
    }
    if (S32(p, 0xb58) != id) {
        return false;
    }
    JGeometry::TBox2<f32>& box = BOX(p, 0x540);
    JGeometry::TBox2<f32> overlap = box;
    if (overlap.intersect(*bounds)) {
        center->x = lbl_805400C0 * (box.i.x - box.f.x) + box.f.x;
        center->y = lbl_805400C0 * (box.i.y - box.f.y) + box.f.y;
        return true;
    }
    return false;
}

extern "C" bool fn_802575B8(u8* p, const JGeometry::TBox2<f32>* bounds,
                             s32 id, JGeometry::TVec2<f32>* center) {
    u8* ids = p;
    u8* boxes = p;
    for (s32 i = 0; i < 3; i++, ids += 4, boxes += 0x10) {
        if (S32(ids, 0xb0c) >= 0 && S32(ids, 0xb4c) == id) {
            JGeometry::TBox2<f32> overlap = BOX(boxes, 0x510);
            if (overlap.intersect(*bounds)) {
                JGeometry::TBox2<f32>& box = BOX(p, 0x510 + i * 0x10);
                center->x = lbl_805400C0 * (box.i.x - box.f.x) + box.f.x;
                center->y = lbl_805400C0 * (box.i.y - box.f.y) + box.f.y;
                S32(p, 0xb80) = i;
                return true;
            }
        }
    }
    S32(p, 0xb80) = -1;
    return false;
}

extern "C" bool fn_802576CC(u8* p, const JGeometry::TBox2<f32>* bounds,
                             s32 id, JGeometry::TVec2<f32>* center) {
    u8* boxes = p;
    u8* ids = p;
    if (S32(ids, 0xb00) >= 0 && S32(ids, 0xb40) == id) {
        for (s32 i = 0; i < 3; i++, ids += 4, boxes += 0x10) {
            JGeometry::TBox2<f32> overlap = BOX(boxes, 0x4e0);
            if (overlap.intersect(*bounds)) {
                JGeometry::TBox2<f32>& box = BOX(p, 0x4e0 + i * 0x10);
                center->x = lbl_805400C0 * (box.i.x - box.f.x) + box.f.x;
                center->y = lbl_805400C0 * (box.i.y - box.f.y) + box.f.y;
                S32(p, 0xb7c) = i;
                return true;
            }
        }
    }
    S32(p, 0xb7c) = -1;
    return false;
}

extern "C" u8 fn_802577E0(u8* p) {
    if (fn_80270C88(p)) {
        return 0;
    }
    if (Player_GetField_0x454(p)) {
        return 0;
    }
    s32 state = S32(p, 0x1240);
    if (state == 0x3f || state == 0xc) {
        return 0;
    }
    return fn_80251AEC(p, 0x3f);
}

extern "C" void fn_80257FF4(u8* p) {
    s32 i;
    s32 id;
    for (i = 0; i < 2; i++) {
        id = S32(p, 0xb30);
        if (id >= 0) {
            if (!fn_801F666C(fn_801F856C(), id)) {
                S32(p, 0xb30) = -1;
            }
        }
        p += 4;
    }
}

extern "C" void fn_80258070(u8* p) {
    s32 id = S32(p, 0xb2c);
    if (id >= 0) {
        u8* actor = fn_801F666C(fn_801F856C(), id);
        if (!actor) {
            S32(p, 0xb2c) = -1;
        } else if (!fn_8030EA0C(actor)) {
            S32(p, 0xb2c) = -1;
        }
    }
}

extern "C" void fn_802580E0(u8* p) {
    f32 target;
    if (fn_80270A8C(p)) {
        target = lbl_805400C4;
    } else if (U8(lbl_8053AAF8, 0x7f)) {
        if (fn_802416C4(p) == 2) {
            target = lbl_805400CC;
        } else {
            target = lbl_805400C4;
        }
    } else {
        target = lbl_805400D0;
    }
    if (F32(p, 0xb90) > target) {
        F32(p, 0xb90) -= lbl_805400D4;
        if (F32(p, 0xb90) < target) {
            F32(p, 0xb90) = target;
        }
    } else if (F32(p, 0xb90) < target) {
        F32(p, 0xb90) += lbl_805400D4;
        if (F32(p, 0xb90) > target) {
            F32(p, 0xb90) = target;
        }
    }
}

extern "C" void fn_8025819C(u8* p) {
    s32 id = S32(p, 0xb3c);
    if (id >= 0) {
        u8* actor = fn_801F666C(fn_801F856C(), id);
        if (!actor) {
            S32(p, 0xb3c) = -1;
            S32(p, 0xb70) = -1;
        } else {
            JGeometry::TVec2<f32> pos = V2(actor, 0xc);
            S32(p, 0xb70) = S32(actor, 4);
            BOX(p, 0x5a0).set(BOX(actor, 0x60));
            BOX(p, 0x5a0).addPos(pos);
        }
    }
}

extern "C" void fn_8025825C(u8* p) {
    s32 id = S32(p, 0xb38);
    if (id < 0) {
        U8(p, 0xb68) = 0;
    } else {
        u8* actor = fn_801F666C(fn_801F856C(), id);
        if (!actor) {
            U8(p, 0xb68) = 0;
            S32(p, 0xb38) = -1;
            S32(p, 0xb6c) = -1;
        } else {
            if (JMathInlineVEC::PSVECSquareMag(&V3(actor, 0x3c)) <= lbl_805400D8 * FLT_EPSILON) {
                U8(p, 0xb68) = 0;
            } else {
                U8(p, 0xb68) = 1;
            }
            JGeometry::TVec2<f32> pos = V2(actor, 0xc);
            S32(p, 0xb6c) = S32(actor, 4);
            BOX(p, 0x590).set(BOX(actor, 0x60));
            BOX(p, 0x590).addPos(pos);
        }
    }
}

extern "C" void fn_80258384(u8* p) {
    u8* ids = p;
    u8* boxes = p;
    s32 i = 0;
    s32 id;
    while (i < 3) {
        id = S32(ids, 0xb1c);
        if (id >= 0) {
            u8* actor = fn_801F666C(fn_801F856C(), id);
            if (!actor) {
                S32(ids, 0xb1c) = -1;
                S32(ids, 0xb5c) = -1;
            } else {
                JGeometry::TVec2<f32> pos = V2(actor, 0xc);
                S32(ids, 0xb5c) = S32(actor, 4);
                BOX(boxes, 0x550).set(BOX(actor, 0x60));
                BOX(boxes, 0x550).addPos(pos);
            }
        }
        i++;
        boxes += 0x10;
        ids += 4;
    }
}

extern "C" void fn_80258470(u8* p) {
    void* manager = fn_801F856C();
    u8* actor = fn_801F666C(manager, S32(p, 0xb18));
    if (!actor) {
        S32(p, 0xb18) = -1;
        S32(p, 0xb58) = -1;
    } else {
        JGeometry::TVec2<f32> pos = V2(actor, 0xc);
        S32(p, 0xb58) = S32(actor, 4);
        BOX(p, 0x540).set(BOX(actor, 0x60));
        BOX(p, 0x540).addPos(pos);
    }
}

extern "C" void fn_8025851C(u8* p) {
    u8* ids = p;
    u8* boxes = p;
    for (s32 i = 0; i < 3; i++, boxes += 0x10, ids += 4) {
        void* manager = fn_801F856C();
        u8* actor = fn_801F666C(manager, S32(ids, 0xb0c));
        if (!actor) {
            S32(ids, 0xb0c) = -1;
            S32(ids, 0xb4c) = -1;
        } else {
            JGeometry::TVec2<f32> pos = V2(actor, 0xc);
            S32(ids, 0xb4c) = S32(actor, 4);
            BOX(boxes, 0x510).set(BOX(actor, 0x60));
            BOX(boxes, 0x510).addPos(pos);
        }
    }
}

extern "C" void fn_802585F4(u8* p) {
    u8* ids = p;
    u8* boxes = p;
    for (s32 i = 0; i < 3; i++, ids += 4, boxes += 0x10) {
        void* manager = fn_801F856C();
        u8* actor = fn_801F666C(manager, S32(ids, 0xb00));
        if (!actor) {
            S32(ids, 0xb00) = -1;
            S32(ids, 0xb40) = -1;
        } else {
            JGeometry::TVec2<f32> pos = V2(actor, 0xc);
            S32(ids, 0xb40) = S32(actor, 4);
            BOX(boxes, 0x4e0).set(BOX(actor, 0x60));
            BOX(boxes, 0x4e0).addPos(pos);
        }
    }
}

extern "C" void fn_802586CC(void) {
}

extern "C" void fn_80258880(u8* p) {
    U8(p, 0x458) = 0;
}

extern "C" void fn_8025888C(void) {
}

extern "C" void fn_80258BA8(u8* p) {
    U8(p, 0x458) = 0;
    U8(p, 0xb9f) = 0;
    S32(p, 0xba0) = 0;
}

extern "C" void fn_80258BBC(u8* p) {
    s32 state = S32(p, 0x1244);
    if (state != 5 && state != 7) {
        F32(p, 0x10) = lbl_805400C4;
    }
    U8(p, 0xb79) = 0;
    U8(p, 0x1204) = 0;
}

extern "C" void fn_8027EB04(void*);
extern "C" void fn_8024F0E8(void*, s32);
extern "C" u8 fn_8024B24C(void*);
extern "C" s32 fn_802486A0(void*);
extern "C" u8 Player_IsLinked(void*);
extern "C" u8 fn_80243194(void*, s32);
extern "C" void fn_8023E690(s32, void*);
extern "C" void fn_8024BAEC(void*);
extern "C" void fn_80259660(u8* p) {
    U8(p, 0x458) = 0;
    fn_8027EB04(p);
    F32(p, 0x344) = lbl_805400C4;
    F32(p, 0x348) = lbl_805400C4;
    F32(p, 0x34c) = lbl_805400C4;
    F32(p, 0x34c) = lbl_8054010C;
    fn_8024F0E8(p, 0x10002);
    F32(p, 0x368) = lbl_805400C4;
    F32(p, 0x36c) = lbl_805400C4;
    F32(p, 0x370) = lbl_805400C4;
    U8(p, 0xb79) = 0;
    U8(p, 0x1204) = 0;
    if (fn_8024B24C(p)) {
        if (fn_802486A0(p) == 5 && !Player_IsLinked(p)) {
            for (s32 i = 0; i < 4; i++) {
                if (fn_80243194(p, i) && i != S32(p, 0x4)) {
                    fn_8023E690(i, p + 8);
                }
            }
            fn_8024BAEC(p);
        }
    }
    if (fn_8024B24C(p)) {
        U8(p, 0x1204) = 1;
    } else {
        U8(p, 0x1204) = 0;
    }
}

extern "C" void fn_80259778(u8* p) {
    F32(p, 0x34c) = lbl_8054010C;
}

extern "C" void fn_80259784(u8* p) {
    u8* effect = PTR(p, 0x12c4);
    if (effect) {
        U32(effect, 0xf4) |= 1;
        S32(effect, 0x24) = 1;
        PTR(p, 0x12c4) = 0;
    }
    effect = PTR(p, 0x12c8);
    if (effect) {
        U32(effect, 0xf4) |= 1;
        S32(effect, 0x24) = 1;
        PTR(p, 0x12c8) = 0;
    }
    s32 id = S32(p, 0xb28);
    if (id >= 0) {
        u8* actor = fn_801F666C(fn_801F856C(), id);
        if (actor) {
            fn_802BAA00(actor);
        }
        S32(p, 0xb28) = -1;
    }
}

extern "C" void fn_8025A04C(u8* p) {
    U8(p, 0x458) = 0;
    if (fn_80241794(p) <= 0) {
        U8(p, 0xb84) = 0;
    } else {
        U8(p, 0xb84) = 1;
    }
    S32(p, 0xb88) = 0;
    S32(p, 0xb28) = -1;
    S32(p, 0xb8c) = 0;
}

extern "C" void fn_8025A0B0(u8* p) {
    u8* effect = PTR(p, 0x12c4);
    if (effect) {
        U32(effect, 0xf4) |= 1;
        S32(effect, 0x24) = 1;
        PTR(p, 0x12c4) = 0;
    }
    effect = PTR(p, 0x12c8);
    if (effect) {
        U32(effect, 0xf4) |= 1;
        S32(effect, 0x24) = 1;
        PTR(p, 0x12c8) = 0;
    }
    s32 id = S32(p, 0xb28);
    if (id >= 0) {
        u8* actor = fn_801F666C(fn_801F856C(), id);
        if (actor) {
            fn_802BAA00(actor);
        }
        S32(p, 0xb28) = -1;
    }
}

extern "C" void fn_8025A9C0(u8* p) {
    U8(p, 0x458) = 0;
    if (fn_80241794(p) <= 0) {
        U8(p, 0xb84) = 0;
    } else {
        U8(p, 0xb84) = 1;
    }
    S32(p, 0xb88) = 0;
    S32(p, 0xb28) = -1;
    S32(p, 0xb8c) = 0;
}

extern "C" u8 fn_8025AA24(u8* p, s32 id) {
    if (S32(p, 0x11f8) >= 0) {
        return 0;
    }
    if (fn_80251AEC(p, 0x43)) {
        S32(p, 0x11f8) = id;
        return 1;
    }
    return 0;
}

extern "C" u8 fn_8025AA8C(u8* p, s32 id) {
    if (S32(p, 0x11f8) >= 0) {
        return 0;
    }
    if (fn_80251AEC(p, 0x42)) {
        S32(p, 0x11f8) = id;
        return 1;
    }
    return 0;
}

extern "C" void fn_8025AAF4(u8* p) {
    S32(p, 0x11f8) = -1;
}

extern "C" void fn_8025AEB0(u8* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
}

extern "C" void fn_8025AEC4(u8* p) {
    S32(p, 0x11f8) = -1;
}

extern "C" void fn_8025B218(u8* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
}

extern "C" void fn_8025B22C(u8* p) {
    if (U8(p, 0x3fa) < 2) {
        U8(p, 0x3fb) = 0;
    } else if (U8(p, 0x3fa) < 4) {
        U8(p, 0x3fb) = 1;
    } else if (U8(p, 0x3fa) < 6) {
        U8(p, 0x3fb) = 2;
    } else {
        U8(p, 0x3fb) = 3;
    }
    if (U8(p, 0x3fa) == 6) {
        if (fn_802415CC(p) >= 2) {
            u32 owner = U32(p, 0x4);
            void* mgr = fn_801F856C();
            S32(p, 0xb18) = Actor_CreateByID(mgr, 0x424F4D45, S32(p, 0x3b4), p + 0x8, ((U32(p, 0x3e8) & 7) << 4) | (owner & 3) | 0x100, -1, owner);
        } else {
            u32 owner = U32(p, 0x4);
            void* mgr = fn_801F856C();
            S32(p, 0xb18) = Actor_CreateByID(mgr, 0x424F4D45, S32(p, 0x3b4), p + 0x8, ((U32(p, 0x3e8) & 7) << 4) | (owner & 3), -1, owner);
        }
    } else if (U8(p, 0x3fa) == 0x10) {
        fn_80251AEC(p, 0);
    }
    U8(p, 0x3fa)++;
    fn_80268B3C(p);
}

extern "C" void fn_8025B35C(u8* p) {
    U8(p, 0x458) = 0;
}

extern "C" void fn_8025B368(u8* p) {
    U8(p, 0xb99) = 0;
    U8(p, 0xb9a) = 0;
    U8(p, 0xb9b) = 0;
    u8* effect = PTR(p, 0x1274);
    if (effect) {
        U32(effect, 0xf4) &= ~0x40;
        effect = PTR(p, 0x1274);
        U32(effect, 0xf4) |= 1;
        S32(effect, 0x24) = 1;
        PTR(p, 0x1274) = 0;
    }
    effect = PTR(p, 0x128c);
    if (effect) {
        U32(effect, 0xf4) &= ~0x40;
        effect = PTR(p, 0x128c);
        U32(effect, 0xf4) |= 1;
        S32(effect, 0x24) = 1;
        PTR(p, 0x128c) = 0;
    }
    S32(p, 0x40c) = 0;
}

extern "C" void fn_8025BDC8(u8* p) {
    U8(p, 0x458) = 0;
    S32(p, 0x40c) = 0;
}

extern "C" void fn_8025BDD8(u8* p) {
    u8* effect = PTR(p, 0x12cc);
    if (effect) {
        U32(effect, 0xf4) &= ~0x40;
        effect = PTR(p, 0x12cc);
        U32(effect, 0xf4) |= 1;
        S32(effect, 0x24) = 1;
        PTR(p, 0x12cc) = 0;
    }
    effect = PTR(p, 0x12e4);
    if (effect) {
        U32(effect, 0xf4) &= ~0x40;
        effect = PTR(p, 0x12e4);
        U32(effect, 0xf4) |= 1;
        S32(effect, 0x24) = 1;
        PTR(p, 0x12e4) = 0;
    }
    s32 id = S32(p, 0x12c0);
    if (id >= 0) {
        u8* actor = fn_801F666C(fn_801F856C(), id);
        if (actor) {
            U8(actor, 0x11c) = 0;
        }
        S32(p, 0x12c0) = -1;
    }
    S32(p, 0x40c) = 0;
}

extern "C" void fn_8025C79C(u8* p) {
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_805400C4;
    F32(p, 0x348) = lbl_805400C4;
    F32(p, 0x34c) = lbl_805400C4;
    S32(p, 0x40c) = 0;
}

extern "C" void fn_8025C7BC(u8* p) {
    u8* effect = PTR(p, 0x12cc);
    if (effect) {
        U32(effect, 0xf4) &= ~0x40;
        effect = PTR(p, 0x12cc);
        U32(effect, 0xf4) |= 1;
        S32(effect, 0x24) = 1;
        PTR(p, 0x12cc) = 0;
    }
    effect = PTR(p, 0x12e4);
    if (effect) {
        U32(effect, 0xf4) &= ~0x40;
        effect = PTR(p, 0x12e4);
        U32(effect, 0xf4) |= 1;
        S32(effect, 0x24) = 1;
        PTR(p, 0x12e4) = 0;
    }
    s32 id = S32(p, 0x12c0);
    if (id >= 0) {
        u8* actor = fn_801F666C(fn_801F856C(), id);
        if (actor) {
            U8(actor, 0x11c) = 0;
        }
        S32(p, 0x12c0) = -1;
    }
    S32(p, 0x40c) = 0;
}

extern "C" void fn_8025D090(u8* p) {
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_805400C4;
    F32(p, 0x348) = lbl_805400C4;
    F32(p, 0x34c) = lbl_805400C4;
    S32(p, 0x40c) = 0;
}

extern "C" void fn_8025D6A0(u8* p) {
    U8(p, 0xb9c) = 0;
}

extern const f32 lbl_80540104;
extern const f32 lbl_80540108;
extern "C" void fn_80268B3C(void*);
extern "C" u8 fn_8025197C(void*, s32);
extern "C" void fn_8025D6AC(u8* p) {
    u8 phase = U8(p, 0x3fc);
    if (phase < 4) {
        U8(p, 0x3fd) = 0;
    } else if (phase < 8) {
        U8(p, 0x3fd) = 1;
    } else if (phase < 0xc) {
        U8(p, 0x3fd) = 2;
    } else {
        U8(p, 0x3fd) = 3;
    }
    U8(p, 0x3fc)++;
    if (U8(p, 0x3fc) == 2) {
        U8(p, 0xb9c) = 0;
        V3(p, 8) += V3(p, 0x344);
        f32 c104 = lbl_80540104;
        F32(p, 0x34c) -= c104;
        f32 c108 = lbl_80540108;
        if (F32(p, 0x34c) < c108) {
            F32(p, 0x34c) = c108;
        }
        if (F32(p, 0x34c) <= lbl_805400C4 && F32(p, 0x10) <= lbl_805400C4) {
            F32(p, 0x10) = lbl_805400C4;
        }
        U8(p, 0x124d) = 0;
        fn_80251AEC(p, 0);
        fn_80268B3C(p);
        if (fn_8025197C(p, 1)) {
            F32(p, 0x344) = lbl_805400C4;
            F32(p, 0x348) = lbl_805400C4;
        }
    }
}

extern "C" void fn_8025D9FC(u8* p) {
    u8* effect = PTR(p, 0x1360);
    if (effect) {
        U32(effect, 0xf4) |= 1;
        S32(effect, 0x24) = 1;
        PTR(p, 0x1360) = 0;
    }
    effect = PTR(p, 0x1368);
    if (effect) {
        U32(effect, 0xf4) |= 1;
        S32(effect, 0x24) = 1;
        PTR(p, 0x1368) = 0;
    }
    effect = PTR(p, 0x1364);
    if (effect) {
        U32(effect, 0xf4) |= 1;
        S32(effect, 0x24) = 1;
        PTR(p, 0x1364) = 0;
    }
    if (S32(p, 0xbac) > 0 || fn_8026FC20(p) > 0) {
        U8(p, 0xce8) = 0;
    }
    S32(p, 0xbac) = 0;
    S32(p, 0xba8) = 0;
}

extern "C" void fn_8027221C(void*, s32);
extern "C" u32 fn_80246B10(void*, u32);
extern "C" s32 fn_80230CFC(s32);
extern "C" s32 Player_GetLinkTargetIndex(void*);
extern "C" const JGeometry::TVec3<f32> lbl_8046AF00[];
extern "C" void fn_8025E79C(u8* p) {
    fn_8027221C(p, 6);
    U8(p, 0x458) = 1;
    if (Player_IsLinked(p) && fn_802486A0(p) != 4) {
        s32 v = fn_80230CFC(Player_GetLinkTargetIndex(p));
        S32(p, 0x3dc) = v;
        S32(p, 0x3e8) = v;
    } else {
        if (fn_80246B10(p, 2)) {
            S32(p, 0x3dc) = 0;
            S32(p, 0x3e8) = 0;
        } else if (fn_80246B10(p, 1)) {
            S32(p, 0x3dc) = 1;
            S32(p, 0x3e8) = 1;
        } else if (fn_80246B10(p, 8)) {
            S32(p, 0x3dc) = 3;
            S32(p, 0x3e8) = 3;
        } else if (fn_80246B10(p, 4)) {
            S32(p, 0x3dc) = 2;
            S32(p, 0x3e8) = 2;
        }
    }
    s32 idx = S32(p, 0x3dc);
    JGeometry::TVec3<f32> d = lbl_8046AF00[idx];
    S32(p, 0xba8) = 0;
    V3(p, 8) += d;
    U8(p, 0x3fa) = 0;
    S32(p, 0xbac) = 0;
}

