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
s32 fn_8026FC20(void*);
}

extern u8* lbl_8053AAF8;
extern const f32 lbl_805400C0;
extern const f32 lbl_805400C4;
extern const f32 lbl_805400CC;
extern const f32 lbl_805400D0;
extern const f32 lbl_805400D4;
extern const f32 lbl_8054010C;

extern "C" bool fn_802573E0(u8* p, const JGeometry::TBox2<f32>* bounds,
                             s32 id, JGeometry::TVec2<f32>* center) {
    if (S32(p, 0xb38) < 0) {
        return false;
    }
    if (S32(p, 0xb6c) != id) {
        return false;
    }
    JGeometry::TBox2<f32> overlap = BOX(p, 0x590);
    if (overlap.intersect(*bounds)) {
        center->x = lbl_805400C0 * (BOX(p, 0x590).i.x - BOX(p, 0x590).f.x) + BOX(p, 0x590).f.x;
        center->y = lbl_805400C0 * (BOX(p, 0x590).i.y - BOX(p, 0x590).f.y) + BOX(p, 0x590).f.y;
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
    JGeometry::TBox2<f32> overlap = BOX(p, 0x540);
    if (overlap.intersect(*bounds)) {
        center->x = lbl_805400C0 * (BOX(p, 0x540).i.x - BOX(p, 0x540).f.x) + BOX(p, 0x540).f.x;
        center->y = lbl_805400C0 * (BOX(p, 0x540).i.y - BOX(p, 0x540).f.y) + BOX(p, 0x540).f.y;
        return true;
    }
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

extern "C" void fn_80258384(u8* p) {
    u8* ids = p;
    u8* boxes = p;
    for (s32 i = 0; i < 3; i++, boxes += 0x10, ids += 4) {
        s32 id = S32(ids, 0xb1c);
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
