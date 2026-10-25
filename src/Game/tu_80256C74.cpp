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
u8 Player_IsLinked(void*);
s32 Player_GetLinkTargetIndex(void*);
u8 fn_80230188(s32);
u8 fn_8025F684(void*);
u8 fn_8025F448(void*);
u8 fn_802412A4(void*);
u8 fn_8024C448(void*);
u8 fn_80241230(void*);
u8 fn_80250D30(void*);
u8 fn_802411C4(void*);
u8 fn_80240B70(void*);
u8 fn_80240B5C(void*);
u8 fn_80240B84(void*);
u8 Player_GetField_0xce8(void*);
u8 fn_80240D64(void*);
u8 fn_80240DAC(void*);
u8 Player_CheckField_0xc9c(void*);
u8 fn_802412C4(void*);
void fn_80268B3C(void*);
s32 Actor_CreateByID(void* mgr, u32 fourCC, u32 owner, void* pos, u32 param, s32 a, s32 b);
        s32 fn_8026FC20(void*);
s32 fn_802A1844(void*, void*, s32, s32);
u16 fn_8022461C(void*, s32);
void fn_8024F0E8(void*, s32);
u8* fn_8013CC50(s32, void*, u16, s32, s32, s32, void*, s32, f32);
u8 fn_8022C274(u32);
u8 fn_8022B160(void*);
u32 fn_80246B10(void*, u32);
f32 fn_80246F28(void*);
f32 fn_80247330(void*);
f32 fn_8024712C(void*);
void fn_802808E8(void*, f32);
u8 fn_80247594(void*, s32);
void fn_8030EA00(void);
void fn_8043D67C(void*, s32, s32, s32);
void fn_802BAA0C(void*, void*);
void fn_8013CB44(void*, void*, s32, s32, s32);
}
void JPAGetXYZRotateMtx(s16, s16, s16, f32 (*)[4]);
extern const f32 lbl_805400DC;
extern const f32 lbl_80540110;
extern const f32 lbl_80540114;
extern const f32 lbl_80540118;
extern const f32 lbl_8054011C;
extern const f32 lbl_80540120;
extern u16 lbl_8046B200[][4];
extern int __float_epsilon[];
extern "C" const JGeometry::TVec3<f32> lbl_8046AF00[];
extern u8* lbl_8053AED0;
extern u8* lbl_8053AC98;

extern u8* lbl_8053AAF8;
extern const f32 lbl_805400C0;
extern const f32 lbl_805400C4;
extern const f32 lbl_805400C8;
extern const f32 lbl_805400CC;
extern const f32 lbl_805400D0;
extern const f32 lbl_805400D4;
extern const f32 lbl_805400D8;
extern const f32 lbl_8054010C;
extern const f32 lbl_805400E0;
extern const f32 lbl_80540104;
extern const f32 lbl_80540124;
extern const f32 lbl_80540140;
extern const f32 lbl_80540144;
extern const f32 lbl_805400FC;
extern const f32 lbl_80540148;
extern "C" f32 fn_8022C82C(void*);
extern "C" f32 fn_8022C76C(void*);
extern const JGeometry::TVec3<f32> lbl_8046B010[];
extern const f32 lbl_80540130;
extern const JGeometry::TVec3<f32> lbl_8046AFE0[];
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D79E8(void* mgr, s32 id, s32 a, f32 f1, f32 f2);
extern "C" void fn_80134DE4(void* game, s32 a, s32 b);

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
    if (x1 >= x0 && y1 >= y0) {
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
    if (U8(p, (u32)0xb9e) == 0) {
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
    if (x1 >= x0 && y1 >= y0) {
        ok = true;
    }
    if (ok) {
        center->x = lbl_805400C0 * (F32(p, 0x5b0) - F32(p, 0x5b8)) + F32(p, 0x5b8);
        center->y = lbl_805400C0 * (F32(p, 0x5b4) - F32(p, 0x5bc)) + F32(p, 0x5bc);
        return true;
    }
    return false;
}

extern "C" bool fn_802570BC(u8* p, const JGeometry::TBox2<f32>* bounds,
                             s32 id, JGeometry::TVec2<f32>* center) {
    if (GetBusyLocked(p)) {
        return false;
    }
    if (Player_GetField_0x454(p)) {
        return false;
    }
    u8* ids = p;
    u8* boxes = p;
    for (s32 i = 0; i < 3; ids += 4, boxes += 0x10, i++) {
        if (S32(ids, 0xb1c) >= 0 && S32(ids, 0xb5c) == id) {
            JGeometry::TBox2<f32> overlap = BOX(boxes, 0x550);
            if (overlap.intersect(*bounds)) {
                JGeometry::TBox2<f32>& box = BOX(p, i * 0x10 + 0x550);
                center->x = lbl_805400C0 * (box.i.x - box.f.x) + box.f.x;
                center->y = lbl_805400C0 * (box.i.y - box.f.y) + box.f.y;
                return true;
            }
        }
    }
    if (S32(p, 0xb28) >= 0 && id == S32(p, 0x3b4)) {
        JGeometry::TBox2<f32>& box = BOX(p, 0x580);
        JGeometry::TBox2<f32> overlap = box;
        if (overlap.intersect(*bounds)) {
            center->x = lbl_805400C0 * (box.i.x - box.f.x) + box.f.x;
            center->y = lbl_805400C0 * (box.i.y - box.f.y) + box.f.y;
            return true;
        }
    }
    if (S32(p, 0xb3c) >= 0 && S32(p, 0xb70) == id) {
        JGeometry::TBox2<f32>& box = BOX(p, 0x5a0);
        JGeometry::TBox2<f32> overlap = box;
        if (overlap.intersect(*bounds)) {
            center->x = lbl_805400C0 * (box.i.x - box.f.x) + box.f.x;
            center->y = lbl_805400C0 * (box.i.y - box.f.y) + box.f.y;
            return true;
        }
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
    for (s32 i = 0; i < 3; ids += 4, boxes += 0x10, i++) {
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
    u8* base = p;
    u8* boxes = base;
    s32* ids = (s32*)p;
    if (S32(p, 0xb00) >= 0 && S32(p, 0xb40) == id) {
        for (s32 i = 0; i < 3; i++, ids++, boxes += 0x10) {
            JGeometry::TBox2<f32> overlap = BOX(boxes, 0x4e0);
            if (overlap.intersect(*bounds)) {
                JGeometry::TBox2<f32>& box = BOX(base, 0x4e0 + i * 0x10);
                center->x = lbl_805400C0 * (box.i.x - box.f.x) + box.f.x;
                center->y = lbl_805400C0 * (box.i.y - box.f.y) + box.f.y;
                S32(base, 0xb7c) = i;
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

u8 fn_8022B334(s32);
u8 fn_8022C310(s32);
u8 fn_8022B160(void*);
void fn_80241618(void*, s32, s32);
s32 fn_802373EC(s32);
s32 fn_8023EEB4(s32);
void fn_8024B298(void*, s32, void*);
u8 fn_8025F500(void*);
u8 fn_802518AC(void*, s32);
u8 fn_80246228(void*);
s32 fn_802486A0(void*);
u8 fn_80243194(void*, s32);
u8 lbl_8053ABB8[];
JGeometry::TVec3<f32> lbl_8046B220[];
extern "C" u8 fn_8022B334(s32);
extern "C" u8 fn_8022C310(s32);
extern "C" u8 fn_8022B160(void*);
extern "C" void fn_80241618(void*, s32, s32);
extern "C" s32 fn_802373EC(s32);
extern "C" s32 fn_8023EEB4(s32);
extern "C" void fn_8024B298(void*, s32, void*);
extern "C" u8 fn_8025F500(void*);
extern "C" u8 fn_802518AC(void*, s32);
extern "C" u8 fn_80246228(void*);
extern "C" u8 lbl_8053ABB8[];
extern "C" JGeometry::TVec3<f32> lbl_8046B220[];
extern "C" void fn_8025785C(u8* p) {
    if (S32(p, 0xb74) > 0) {
        S32(p, 0xb74) = S32(p, 0xb74) - 1;
    }
    if (fn_8022B334(S32(p, 0x4))) {
        if (Player_IsLinked(p)) {
            s32 cur = fn_802416C4(p);
            if (fn_802373EC(Player_GetLinkTargetIndex(p)) != cur) {
                fn_80241618(p, fn_802373EC(Player_GetLinkTargetIndex(p)), 1);
            }
        }
        if (fn_8022C310(S32(p, 0x4))) {
            if (fn_802416C4(p) == 1) {
                fn_80251AEC(p, 0x39);
            } else if (fn_802416C4(p) == 2) {
                fn_80251AEC(p, 0x48);
            } else if (fn_802416C4(p) == 3) {
                if (S32(p, 0xb18) < 0) {
                    s32 n = 0;
                    if (S32(p, 0xb00) >= 0) {
                        n = 1;
                    }
                    if (S32(p, 0xb04) >= 0) {
                        n++;
                    }
                    if (S32(p, 0xb08) >= 0) {
                        n++;
                    }
                    if (n < 3) {
                        fn_80251AEC(p, 0x3d);
                    }
                }
            } else if (fn_802416C4(p) == 4) {
                if (S32(p, 0xb18) < 0 && S32(p, 0xb74) < 1) {
                    if (fn_8022B160(p) == 0 ||
                        ((Player_IsLinked(p) == 0 || fn_802486A0(p) == 4) && lbl_8053ABB8[S32(p, 0x4)] == 0)) {
                        fn_80251AEC(p, 0x3a);
                    }
                }
            } else if (fn_802416C4(p) == 5) {
                fn_80251AEC(p, 0x3c);
            } else if (fn_802416C4(p) == 6) {
                if (fn_802415CC(p) >= 2) {
                    fn_80251AEC(p, 0x45);
                } else if (fn_802415CC(p) < 2) {
                    s32 n = 0;
                    if (S32(p, 0xb1c) >= 0) {
                        n = 1;
                    }
                    if (S32(p, 0xb20) >= 0) {
                        n++;
                    }
                    if (S32(p, 0xb24) >= 0) {
                        n++;
                    }
                    if (n < 3) {
                        fn_80251AEC(p, 0x44);
                    }
                }
            } else if (fn_802416C4(p) == 7) {
                if (fn_8025F500(p)) {
                    u8* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
                    if (actor != NULL && S32(actor, 0x1a4) != 0) {
                        goto end;
                    }
                }
                for (s32 i = 0; i < 4; i++) {
                    if (fn_80243194(p, i) && fn_8023EEB4(i) == 0x52434b32) {
                        goto end;
                    }
                }
                s32 id = S32(p, 0x3b4);
                if (*((u8*)fn_802D6A9C() + id + 0x131df) == 0) {
                    if (F32(p, 0x10) > lbl_805400C4) {
                        goto end;
                    }
                } else if (fn_802518AC(p, 1) == 0) {
                    JGeometry::TVec2<f32> v;
                    fn_8024B298(p, 2, &v);
                    v.y = v.y + lbl_805400C8;
                    if (fn_8022461C(&v, S32(p, 0x3b4)) == 2) {
                        goto end;
                    }
                }
                if (fn_8025F684(p)) {
                    fn_80251AEC(p, 0x14);
                } else {
                    fn_80251AEC(p, 0x46);
                }
            } else if (fn_802416C4(p) == 8) {
                for (s32 i = 0; i < 2; i++) {
                    if (S32(p, 0xb30 + i * 4) < 0) {
                        JGeometry::TVec3f v = lbl_8046B220[S32(p, 0x3dc)];
                        v.add(V3(p, 0x8));
                        v.z = lbl_805400C4;
                        if (fn_8022461C(&v, S32(p, 0x3b4)) == 0xe) {
                            goto end;
                        }
                        s32 created;
                        if (fn_802415CC(p) >= 2) {
                            created = Actor_CreateByID(fn_801F856C(), 0x48424d42, S32(p, 0x3b4), &v, 8, -1, S32(p, 0x4));
                        } else {
                            created = Actor_CreateByID(fn_801F856C(), 0x48424d42, S32(p, 0x3b4), &v, 0, -1, S32(p, 0x4));
                        }
                        if (fn_801F666C(fn_801F856C(), created) != NULL) {
                            S32(p, 0xb30 + i * 4) = created;
                            fn_8024F0E8(p, 0x20006);
                            goto end;
                        }
                    }
                }
            } else if (fn_802416C4(p) == 9) {
                fn_80251AEC(p, 0x47);
            } else if (fn_802416C4(p) == 10) {
                if (S32(p, 0xb18) < 0) {
                    fn_80251AEC(p, 0x3b);
                }
            } else if (fn_80246228(p)) {
                U8(p, 0x1200) = 1;
            }
        }
    }
end:
    U8(p, 0x1174) = 0;
}

extern "C" BOOL fn_80257DB4(u8* p) {
    if (U8(p, 0x1174) != 0) {
        return FALSE;
    }
    if (Player_IsLinked(p) && fn_80230188(Player_GetLinkTargetIndex(p))) {
        return FALSE;
    }
    if (Player_GetField_0x454(p)) {
        return FALSE;
    }
    if (fn_80270A8C(p)) {
        return FALSE;
    }
    if (fn_8025F684(p) && fn_802416C4(p) != 7) {
        return FALSE;
    }
    if (fn_8025F448(p)) {
        return FALSE;
    }
    if (fn_802412A4(p)) {
        return FALSE;
    }
    if (fn_8024C448(p)) {
        return FALSE;
    }
    if (fn_80241230(p)) {
        return FALSE;
    }
    if (fn_80250D30(p)) {
        return FALSE;
    }
    if (fn_802411C4(p)) {
        return FALSE;
    }
    if (fn_80240B70(p)) {
        return FALSE;
    }
    if (fn_80240B5C(p)) {
        return FALSE;
    }
    if (fn_80240B84(p)) {
        return FALSE;
    }
    if (Player_GetField_0xce8(p)) {
        return FALSE;
    }
    if (fn_80240D64(p)) {
        return FALSE;
    }
    if (fn_80240DAC(p)) {
        return FALSE;
    }
    if (F32(p, 0x10) > lbl_805400C4) {
        return FALSE;
    }
    if (Player_CheckField_0xc9c(p)) {
        return FALSE;
    }
    if (fn_802412C4(p)) {
        return FALSE;
    }
    if (S32(p, 0xd74) != 0) {
        return FALSE;
    }
    return U32(p, 0xd3c) >> 31;
}

extern "C" void fn_80257FF4(u8* p) {
    u8* q = p;
    s32 id;
    for (s32 i = 0; i < 2; i++) {
        id = S32(q, 0xb30);
        if (id >= 0) {
            if (!fn_801F666C(fn_801F856C(), id)) {
                S32(q, 0xb30) = -1;
            }
        }
        q += 4;
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
    s32 id;
    s32 i = 0;
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
        ids += 4;
        boxes += 0x10;
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
    for (s32 i = 0; i < 3; i++, ids += 4, boxes += 0x10) {
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

extern "C" u8 fn_80247594(void*, s32);
extern "C" void fn_802586D0(u8* p) {
    u8 state = U8(p, 0x3fa);
    if (state < 2) {
        U8(p, 0x3fb) = 0;
    } else if (state < 6) {
        U8(p, 0x3fb) = 1;
    } else if (state < 8) {
        U8(p, 0x3fb) = 0;
    } else {
        U8(p, 0x3fb) = 0;
        fn_80251AEC(p, 0);
    }
    if (U8(p, 0x3fa) == 2 && fn_80247594(p, 0) && S32(p, 0xb3c) < 0) {
        JGeometry::TVec3<f32> pos = V3(p, 0x8);
        switch (S32(p, 0x3dc)) {
        case 0:
            pos.y -= lbl_805400C8;
            break;
        case 1:
            pos.y -= lbl_805400C8;
            break;
        case 2:
            pos.x += lbl_805400C8;
            break;
        case 3:
            pos.x -= lbl_805400C8;
            break;
        }
        u32 flags;
        s32 owner = S32(p, 0x4);
        flags = (fn_802415CC(p) << 12) | ((S32(p, 0x3dc) & 3) << 4) | (owner & 3) | 0x140;
        flags = Actor_CreateByID(fn_801F856C(), 0x46495245, S32(p, 0x3b4), &pos, flags, -1, owner);
        if (fn_801F666C(fn_801F856C(), flags)) {
            S32(p, 0xb3c) = flags;
            U8(p, 0x3fa) = U8(p, 0x3fa) + 1;
            fn_80268B3C(p);
        }
    }
}

extern "C" void fn_80258880(u8* p) {
    U8(p, 0x458) = 0;
}

extern "C" void fn_8025888C(void) {
}

extern "C" void fn_80258890(u8* p) {
    JGeometry::TVec3<f32> pos = V3(p, 0x8);
    pos.z = lbl_805400C4;
    switch (S32(p, 0x3dc)) {
    case 0:
        pos.x += lbl_805400DC;
        break;
    case 1:
        pos.x -= lbl_805400DC;
        break;
    case 2:
        pos.y += lbl_805400DC;
        break;
    case 3:
        pos.y -= lbl_805400DC;
        break;
    }
    if (U8(p, 0x3fd) == 1) {
        u8 s = U8(p, 0x3fa);
        if (s < 0x10) {
            U8(p, 0x3fb) = 4;
        } else if (s < 0x13) {
            U8(p, 0x3fb) = 5;
        } else if (s < 0x16) {
            U8(p, 0x3fb) = 6;
        } else {
            U8(p, 0x3fb) = 6;
            fn_80251AEC(p, 0);
        }
    } else {
        u8 s = U8(p, 0x3fa);
        if (s < 0xc) {
            U8(p, 0x3fb) = 0;
        } else if (s < 0x1c) {
            U8(p, 0x3fb) = 1;
        } else if (s < 0x20) {
            U8(p, 0x3fb) = 2;
        } else if (s < 0x28) {
            U8(p, 0x3fb) = 3;
        } else {
            U8(p, 0x3fb) = 3;
            fn_80251AEC(p, 0);
        }
        if (U8(p, 0x3fa) == 0xb) {
            U8(p, 0xb9e) = 1;
            BOX(p, 0x5cc).set(pos.x - lbl_805400E0, pos.y - lbl_805400E0, pos.x + lbl_805400E0, pos.y + lbl_805400E0);
        }
        if (U8(p, 0x3fa) == 0xc) {
            S32(p, 0xba0) = fn_802A1844(lbl_8053AC98, &pos, S32(p, 0x4), S32(p, 0x3b4));
            s32 r = S32(p, 0xba0);
            if ((r > 0 && r <= 4) || U8(p, 0xb9f) != 0) {
                fn_8024F0E8(p, 0x20044);
            } else {
                U8(p, 0x3fb) = 0;
                U8(p, 0x3fd) = 1;
                if (fn_8022461C(&pos, S32(p, 0x3b4)) == 0x39) {
                    fn_8024F0E8(p, 0x20040);
                } else if (S32(p, 0xba0) == 8) {
                    fn_8024F0E8(p, 0x2004f);
                } else {
                    fn_8024F0E8(p, 0x20066);
                }
            }
        }
        U8(p, 0xb9e) = 0;
        U8(p, 0xb9f) = 0;
        if (U8(p, 0x3fa) == 0x1c && U8(p, 0x3fd) == 0) {
            s32 r = S32(p, 0xba0);
            f32 alpha = lbl_805400D4;
            if (r > 0 && r <= 4) {
                fn_8013CC50(S32(p, 0x3b4), p + 0x8, lbl_8046B200[r - 1][S32(p, 0x3dc)], 0, 0, 0, 0, 1, alpha);
            }
        }
    }
    U8(p, 0x3fa)++;
    fn_80268B3C(p);
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

extern "C" void fn_8025AED0(u8* p) {
    U8(p, 0x3fc) = U8(p, 0x3fc) + 1;
    u32 phase = (U8(p, 0x3fc) >> 1) & 3;
    if (phase == 0) {
        S32(p, 0x3dc) = 0;
        S32(p, 0x3e8) = 0;
    } else if (phase == 1) {
        S32(p, 0x3dc) = 2;
        S32(p, 0x3e8) = 2;
    } else if (phase == 2) {
        S32(p, 0x3dc) = 1;
        S32(p, 0x3e8) = 1;
    } else {
        S32(p, 0x3dc) = 3;
        S32(p, 0x3e8) = 3;
    }
    fn_80268B3C(p);
    U8(p, 0x124d) = 0;
    fn_80251AEC(p, 0);
}

extern "C" void fn_8025B218(u8* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
}

extern "C" void fn_8025B22C(u8* p) {
    s32 owner;
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
            owner = U32(p, 0x4);
            void* mgr = fn_801F856C();
            S32(p, 0xb18) = Actor_CreateByID(mgr, 0x424F4D45, S32(p, 0x3b4), p + 0x8, ((U32(p, 0x3e8) & 7) << 4) | (owner & 3) | 0x100, -1, owner);
        } else {
            owner = U32(p, 0x4);
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

extern "C" void fn_8025C894(u8* p) {
    u8 state = U8(p, 0x3fa);
    if (state < 3) {
        U8(p, 0x3fa) = state + 1;
        U8(p, 0x3fb) = 0;
    } else if (state < 6) {
        U8(p, 0x3fa) = state + 1;
        U8(p, 0x3fb) = 1;
    } else if (state == 6) {
        if (U8(p, 0x3fc) < 0x30) {
            if (fn_802415CC(p) >= 2) {
                U8(p, 0x3fc) += 2;
                if (U8(p, 0x3fc) >= 0x30) {
                    U8(p, 0x3fc) = 0x30;
                }
            } else {
                U8(p, 0x3fc) += 1;
            }
            if (U8(p, 0x3fc) == 0x30) {
                s32 idx = S32(p, 0x3dc);
                V3(p, 0x12fc).set(lbl_8046B010[idx]);
                V3(p, 0x12fc) += V3(p, 0x8);
                if (!PTR(p, 0x12cc)) {
                    V3(p, 0x12d4).set(V3(p, 0x12fc));
                    PTR(p, 0x12cc) = fn_8013CC50(S32(p, 0x3b4), p + 0x12fc, 0xcb, 0, -1, 0, p + 0x12d0, 1, lbl_805400D4);
                    if (PTR(p, 0x12cc)) {
                        U32(PTR(p, 0x12cc), 0xf4) |= 0x40;
                    }
                }
                if (!PTR(p, 0x12e4)) {
                    V3(p, 0x12ec).set(V3(p, 0x12fc));
                    PTR(p, 0x12e4) = fn_8013CC50(S32(p, 0x3b4), p + 0x12fc, 0xcc, 0, -1, 0, p + 0x12e8, 1, lbl_805400D4);
                    if (PTR(p, 0x12e4)) {
                        U32(PTR(p, 0x12e4), 0xf4) |= 0x40;
                    }
                }
                if (S32(p, 0x12c0) < 0) {
                    S32(p, 0x12c0) = Actor_CreateByID(fn_801F856C(), 0x50454646, S32(p, 0x3b4), p + 0x12fc, (U32(p, 0x4) & 3) | 8, -1, -1);
                }
                fn_8024F0E8(p, 0x2000d);
            }
        } else {
            s32 idx = S32(p, 0x3dc);
            V3(p, 0x12fc).set(lbl_8046B010[idx]);
            V3(p, 0x12fc) += V3(p, 0x8);
            if (PTR(p, 0x12cc)) {
                V3(p, 0x12d4).set(V3(p, 0x12fc));
            }
            if (PTR(p, 0x12e4)) {
                V3(p, 0x12ec).set(V3(p, 0x12fc));
            }
            if (S32(p, 0x12c0) >= 0) {
                u8* actor = fn_801F666C(fn_801F856C(), S32(p, 0x12c0));
                if (actor) {
                    V3(actor, 0xc).set(V3(p, 0x12fc));
                }
            }
        }
        if (F32(p, 0x10) > lbl_805400C4) {
            V3(p, 0x8) += V3(p, 0x344);
            F32(p, 0x10) += F32(p, 0x34c);
            F32(p, 0x34c) -= lbl_80540104;
            if (F32(p, 0x10) > lbl_805400C4) {
                F32(p, 0x10) = lbl_805400C4;
                F32(p, 0x368) = F32(p, 0x344);
                F32(p, 0x36c) = F32(p, 0x348);
                F32(p, 0x370) = lbl_805400C4;
                F32(p, 0x344) = lbl_805400C4;
                F32(p, 0x348) = lbl_805400C4;
                F32(p, 0x34c) = lbl_805400C4;
                U8(p, 0x43d) = 3;
            }
        }
    } else if (state < 10) {
        U8(p, 0x3fa) = state + 1;
        U8(p, 0x3fb) = 2;
    } else {
        U8(p, 0x3fa) = state + 1;
        U8(p, 0x3fb) = 3;
    }
    if (U8(p, 0x3fa) >= 0xe) {
        if (S32(p, 0xb74) == 0 && fn_8022C274(U32(p, 0x4))) {
            U8(p, 0x3fa) = 0;
            U8(p, 0x3fb) = 0;
        } else {
            for (s32 i = 0; i < 3; i++) {
                if (S32(p, 0xb00 + i * 4) < 0) {
                    JGeometry::TVec3<f32> pos = V3(p, 0x8);
                    switch (S32(p, 0x3dc)) {
                    case 0:
                    case 1:
                        pos.y -= lbl_805400E0;
                        break;
                    case 3:
                        pos.x -= lbl_805400C8;
                        break;
                    }
                    if (U8(p, 0x3fc) >= 0x30) {
                        s32 owner = S32(p, 0x4);
                        S32(p, 0xb00 + i * 4) = Actor_CreateByID(fn_801F856C(), 0x41525257, S32(p, 0x3b4), &pos, ((owner & 3) | ((S32(p, 0x3dc) & 3) << 4)), -1, owner);
                    } else {
                        s32 owner = S32(p, 0x4);
                        S32(p, 0xb00 + i * 4) = Actor_CreateByID(fn_801F856C(), 0x41525257, S32(p, 0x3b4), &pos, ((owner & 3) | ((S32(p, 0x3dc) & 3) << 4) | 0x100), -1, owner);
                    }
                }
            }
        }
    }
    fn_80268B3C(p);
    S32(p, 0x40c) = S32(p, 0x40c) + 1;
    if (S32(p, 0x40c) < 0x1e) {
        S32(p, 0x40c) = S32(p, 0x40c) + 1;
    }
}

extern "C" void fn_8025D090(u8* p) {
    U8(p, 0x458) = 0;
    F32(p, 0x344) = lbl_805400C4;
    F32(p, 0x348) = lbl_805400C4;
    F32(p, 0x34c) = lbl_805400C4;
    S32(p, 0x40c) = 0;
}

extern "C" void fn_8025D0B0(u8* p) {
    f32 savedY = F32(p, 0xc);
    if (S32(p, 0xbac) >= 1) {
        switch (S32(p, 0x3dc)) {
        case 0:
            F32(p, 8) = F32(p, 8) + lbl_805400FC;
            break;
        case 1:
            F32(p, 8) = F32(p, 8) - lbl_805400FC;
            break;
        case 2:
            F32(p, 0xc) = savedY + lbl_805400FC;
            break;
        case 3:
            F32(p, 0xc) = savedY - lbl_805400FC;
            break;
        }
    } else {
        switch (S32(p, 0x3dc)) {
        case 0:
            if (fn_8022C82C(PTR(p, 4)) < lbl_805400C4) {
                S32(p, 0xba8) = 1;
                break;
            }
            if (fn_8022C76C(PTR(p, 4)) > lbl_805400C4) {
                F32(p, 8) = F32(p, 8) + lbl_80540148;
                F32(p, 0xc) = F32(p, 0xc) - lbl_80540148;
                if (fn_8022C82C(PTR(p, 4)) == lbl_805400C4) {
                    U8(p, 0x3fc)++;
                    if (U8(p, 0x3fc) > 8) {
                        if (U8(PTR(p, 0xbf0), 0xb4) != 0) {
                            S32(p, 0xba8) = 1;
                        } else {
                            S32(p, 0x3dc) = 3;
                            S32(p, 0x3e8) = 3;
                            U8(p, 0x3fc) = 0;
                        }
                    }
                }
            } else if (fn_8022C76C(PTR(p, 4)) < lbl_805400C4) {
                F32(p, 8) = F32(p, 8) + lbl_80540148;
                F32(p, 0xc) = F32(p, 0xc) + lbl_80540148;
                if (fn_8022C82C(PTR(p, 4)) == lbl_805400C4) {
                    U8(p, 0x3fc)++;
                    if (U8(p, 0x3fc) > 8) {
                        if (U8(PTR(p, 0xbf0), 0xb4) != 0) {
                            S32(p, 0xba8) = 1;
                        } else {
                            S32(p, 0x3dc) = 2;
                            S32(p, 0x3e8) = 2;
                            U8(p, 0x3fc) = 0;
                        }
                    }
                }
            } else {
                F32(p, 8) = F32(p, 8) + lbl_805400FC;
                U8(p, 0x3fc) = 0;
            }
            break;
        case 1:
            if (fn_8022C82C(PTR(p, 4)) > lbl_805400C4) {
                S32(p, 0xba8) = 1;
                break;
            }
            if (fn_8022C76C(PTR(p, 4)) > lbl_805400C4) {
                F32(p, 8) = F32(p, 8) - lbl_80540148;
                F32(p, 0xc) = F32(p, 0xc) - lbl_80540148;
                if (fn_8022C82C(PTR(p, 4)) == lbl_805400C4) {
                    U8(p, 0x3fc)++;
                    if (U8(p, 0x3fc) > 8) {
                        if (U8(PTR(p, 0xbf0), 0xb4) != 0) {
                            S32(p, 0xba8) = 1;
                        } else {
                            S32(p, 0x3dc) = 3;
                            S32(p, 0x3e8) = 3;
                            U8(p, 0x3fc) = 0;
                        }
                    }
                }
            } else if (fn_8022C76C(PTR(p, 4)) < lbl_805400C4) {
                F32(p, 8) = F32(p, 8) - lbl_80540148;
                F32(p, 0xc) = F32(p, 0xc) + lbl_80540148;
                if (fn_8022C82C(PTR(p, 4)) == lbl_805400C4) {
                    U8(p, 0x3fc)++;
                    if (U8(p, 0x3fc) > 8) {
                        if (U8(PTR(p, 0xbf0), 0xb4) != 0) {
                            S32(p, 0xba8) = 1;
                        } else {
                            S32(p, 0x3dc) = 2;
                            S32(p, 0x3e8) = 2;
                            U8(p, 0x3fc) = 0;
                        }
                    }
                }
            } else {
                F32(p, 8) = F32(p, 8) - lbl_805400FC;
                U8(p, 0x3fc) = 0;
            }
            break;
        case 2:
            if (fn_8022C76C(PTR(p, 4)) > lbl_805400C4) {
                S32(p, 0xba8) = 1;
                break;
            }
            if (fn_8022C82C(PTR(p, 4)) > lbl_805400C4) {
                F32(p, 8) = F32(p, 8) + lbl_80540148;
                F32(p, 0xc) = F32(p, 0xc) + lbl_80540148;
                if (fn_8022C76C(PTR(p, 4)) == lbl_805400C4) {
                    U8(p, 0x3fc)++;
                    if (U8(p, 0x3fc) > 8) {
                        S32(p, 0x3dc) = 0;
                        S32(p, 0x3e8) = 0;
                        U8(p, 0x3fc) = 0;
                    }
                }
            } else if (fn_8022C82C(PTR(p, 4)) < lbl_805400C4) {
                F32(p, 8) = F32(p, 8) - lbl_80540148;
                F32(p, 0xc) = F32(p, 0xc) + lbl_80540148;
                if (fn_8022C76C(PTR(p, 4)) == lbl_805400C4) {
                    U8(p, 0x3fc)++;
                    if (U8(p, 0x3fc) > 8) {
                        S32(p, 0x3dc) = 1;
                        S32(p, 0x3e8) = 1;
                        U8(p, 0x3fc) = 0;
                    }
                }
            } else {
                F32(p, 0xc) = F32(p, 0xc) + lbl_805400FC;
                U8(p, 0x3fc) = 0;
            }
            break;
        case 3:
            if (fn_8022C76C(PTR(p, 4)) < lbl_805400C4) {
                S32(p, 0xba8) = 1;
                break;
            }
            if (fn_8022C82C(PTR(p, 4)) > lbl_805400C4) {
                F32(p, 8) = F32(p, 8) + lbl_80540148;
                F32(p, 0xc) = F32(p, 0xc) - lbl_80540148;
                if (fn_8022C76C(PTR(p, 4)) == lbl_805400C4) {
                    U8(p, 0x3fc)++;
                    if (U8(p, 0x3fc) > 8) {
                        S32(p, 0x3dc) = 0;
                        S32(p, 0x3e8) = 0;
                        U8(p, 0x3fc) = 0;
                    }
                }
            } else if (fn_8022C82C(PTR(p, 4)) < lbl_805400C4) {
                F32(p, 8) = F32(p, 8) - lbl_80540148;
                F32(p, 0xc) = F32(p, 0xc) - lbl_80540148;
                if (fn_8022C76C(PTR(p, 4)) == lbl_805400C4) {
                    U8(p, 0x3fc)++;
                    if (U8(p, 0x3fc) > 8) {
                        S32(p, 0x3dc) = 1;
                        S32(p, 0x3e8) = 1;
                        U8(p, 0x3fc) = 0;
                    }
                }
            } else {
                F32(p, 0xc) = F32(p, 0xc) - lbl_805400FC;
                U8(p, 0x3fc) = 0;
            }
            break;
        }
        if (U8(PTR(p, 0xbf0), 0xb4) != 0) {
            F32(p, 0xc) = savedY;
        }
    }
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
    }
        V3(p, 8).add(V3(p, 0x344));
        F32(p, 0x34c) -= 0.25f;
        if (F32(p, 0x34c) < -4.0f) {
            F32(p, 0x34c) = -4.0f;
        }
        if (F32(p, 0x34c) <= 0.0f && F32(p, 0x10) <= 0.0f) {
            F32(p, 0x10) = 0.0f;
        U8(p, 0x124d) = 0;
        fn_80251AEC(p, 0);
        }
        fn_80268B3C(p);
        if (fn_8025197C(p, 1)) {
            F32(p, 0x344) = 0.0f;
            F32(p, 0x348) = 0.0f;
        }
}

extern "C" void fn_802F601C(void*, JGeometry::TVec3<f32>*, s32, JGeometry::TVec3<f32>*, f32, f32);
extern u8* lbl_8053AB10;
extern const f32 lbl_805400FC;
extern "C" int __float_epsilon[];
extern "C" void fn_8025D7E4(u8* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
    const JGeometry::TVec3<f32>* e = &lbl_8046AFE0[S32(p, 0x3dc)];
    f32 x = e->x;
    f32 y = e->y;
    F32(p, 0x344) = x;
    f32 z = e->z;
    F32(p, 0x348) = y;
    F32(p, 0x34c) = z;
    fn_8024F0E8(p, 0x20010);
    if (*(volatile const f32*)&lbl_805400C4 != F32(p, 0x348)) {
        fn_802D79E8(fn_802D6A9C(), S32(p, 0x3b4), 0, lbl_805400E0, *(volatile const f32*)&lbl_805400C4);
    } else {
        fn_802D79E8(fn_802D6A9C(), S32(p, 0x3b4), 0, *(volatile const f32*)&lbl_805400C4, lbl_805400E0);
    }
    fn_80134DE4(lbl_8053AAF8, 1, 0);
    JGeometry::TVec3<f32> offset;
    if (S32(p, 0x3dc) == 0 || S32(p, 0x3dc) == 1) {
        offset.set(lbl_805400C4, lbl_80540130, lbl_805400C4);
    } else {
        offset.z = lbl_805400C4;
        offset.y = lbl_805400C4;
        offset.x = lbl_805400C4;
    }
    JGeometry::TVec3<f32> direction;
    direction.set(-F32(p, 0x344), -F32(p, 0x348), lbl_805400C4);
    f32 sq = direction.squared();
    if (!(sq <= lbl_805400D8 * *(f32*)__float_epsilon)) {
        f32 inv;
        if (sq <= lbl_805400C4) {
            inv = sq;
        } else {
            f32 y = __frsqrte(sq);
            inv = lbl_805400C0 * y * (lbl_805400FC - sq * (y * y));
        }
        direction.scale(inv);
    }
    JGeometry::TVec3<f32> pos;
    JGeometry::TVec3<f32> base = V3(p, 8);
    pos.add(base, offset);
    if (S32(p, 0x3b4) < 8) {
        fn_802F601C(*(void**)(lbl_8053AB10 + 0x20), &pos, 3, &direction, lbl_805400D4, lbl_805400D4);
    }
    U8(p, 0xb9c) = 1;
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

extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" char lbl_804CF768[];
extern "C" void fn_8025E8F4(void)
{
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, lbl_804CF768 + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, lbl_804CF768 + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, lbl_804CF768 + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, lbl_804CF768 + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, lbl_804CF768 + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, lbl_804CF768 + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, lbl_804CF768 + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, lbl_804CF768 + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, lbl_804CF768 + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

