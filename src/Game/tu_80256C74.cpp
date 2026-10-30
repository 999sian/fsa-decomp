// Player collision-cache and state helpers, retail 0x80256C74-0x8025EB18.
#include "types.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JParticle/JPAEmitter.h"
extern "C" void fn_8024B298(void*, s32, void*);
extern "C" u8 fn_8022C3AC(u32);
extern "C" u8 fn_80243234(void*);
extern "C" void fn_802685D4(void*);

extern "C" f32 fn_8022C6AC(u32);
extern "C" u8 fn_8022C310(u32);
extern "C" u8 fn_8024B24C(void*);
extern "C" s32 fn_802486A0(void*);
extern "C" u8 fn_80243194(void*, s32);
extern "C" void fn_8023E690(s32, void*);
extern "C" void fn_8024BAEC(void*);
extern const f32 lbl_805400E4;
extern const f32 lbl_805400E8;
extern const f32 lbl_805400EC;
extern const f32 lbl_805400F0;
extern const f32 lbl_805400F4;
extern const f32 lbl_805400F8;
extern const f32 lbl_80540100;
extern const f32 lbl_80540108;


#pragma auto_inline off

static inline bool playerListBusy(u8* list) {
    for (s32 i = 0; i < 8; i++) {
        if (list[0xb4] == 1) { if (i == 2 || (u32)(i - 4) <= 1) continue; }
        if (list[i + 0x48] == 1) return true;
    }
    return false;
}

struct PlayerArrowPosition {
    u8 pad[0xb00];
    s32 ids[3];
    u8 padB0C[0xb40 - 0xb0c];
    s32 rooms[3];
    u8 padB4C[0x12c0 - 0xb4c];
    s32 effectHandle;
    u8 pad12C4[0x12fc - 0x12c4];
    JGeometry::TVec3<f32> pos;
};

static inline f32 playerVelocitySquared(const JGeometry::TVec3<f32>& velocity) {
    return velocity.squared();
}

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
extern const JGeometry::TVec3<f32> lbl_8046B040[];
extern const f32 lbl_80540130;
extern const JGeometry::TVec3<f32> lbl_8046AFE0[];
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D79E8(void* mgr, s32 id, s32 a, f32 f1, f32 f2);
extern "C" void fn_80134DE4(void* game, s32 a, s32 b);
extern "C" void fn_802F601C(void*, JGeometry::TVec3<f32>*, s32, JGeometry::TVec3<f32>*, f32, f32);
extern u8* lbl_8053AB10;
extern "C" u8 fn_8022B244(void);
extern "C" u8 fn_80240AF0(void*);
extern "C" s32 fn_802487FC(void*);
extern "C" s32 fn_802A1D44(void*, void*, u32, s32);
extern const f32 lbl_8054012C;
extern const f32 lbl_80540134;
extern const f32 lbl_80540128;
struct Tu80256RoomState {
    u8 pad[0x131df];
    u8 flags[16];
};

struct Tu80256Tables {
    JGeometry::TVec3<f32> initial[4];
    u8 frames[4][8];
    JGeometry::TVec3<f32> ring[8];
    JGeometry::TVec3<f32> attached[4];
    u8 padE0[0x190 - 0xe0];
    JGeometry::TVec3<f32> a[4];
    JGeometry::TVec3<f32> b[8];
    JGeometry::TVec3<f32> c[4];
    u8 pad250[0x40];
    u8 frames290[4][8];
    s32 rotations2B0[4];
    s32 rotations2C0[4];
};
static inline bool playerNearXY(const JGeometry::TVec2<f32>& a, const JGeometry::TVec2<f32>& b, const f32 epsilon) {
    bool equal = false;
    f32 dx = a.x - b.x;
    bool xEqual = false;
    if (-epsilon <= dx && dx <= epsilon) xEqual = true;
    if (xEqual) {
        f32 dy = a.y - b.y;
        bool yEqual = false;
        if (-epsilon <= dy && dy <= epsilon) yEqual = true;
        if (yEqual) equal = true;
    }
    return equal;
}

static inline void tu8025_copyVec(JGeometry::TVec3<f32>* dst, const JGeometry::TVec3<f32>* table, s32 idx) {
    dst->set(table[idx]);
}

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
    f32 b0 = bounds[0];
    if (x0 <= b0) {
        x0 = b0;
    }
    f32 b1 = bounds[1];
    if (y0 <= b1) {
        y0 = b1;
    }
    f32 b2 = bounds[2];
    if (x1 >= b2) {
        x1 = b2;
    }
    f32 b3 = bounds[3];
    if (y1 >= b3) {
        y1 = b3;
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
    f32 y1 = F32(p, 0x5bc);
    f32 y0 = F32(p, 0x5b4);
    f32 x1 = F32(p, 0x5b8);
    f32 x0 = F32(p, 0x5b0);
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
                u32 offset = i * 0x10;
                u8* selected = p;
                selected += offset;
                JGeometry::TBox2<f32>& box = BOX(selected, 0x550);
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

#pragma opt_propagation off
extern "C" bool fn_802576CC(u8* p, const JGeometry::TBox2<f32>* bounds,
                             s32 id, JGeometry::TVec2<f32>* center) {
    u8* base = p;
    u8* boxes = base;
    if (S32(p, 0xb00) >= 0 && S32(p, 0xb40) == id) {
        for (s32 i = 0; i < 3; i++, boxes += 0x10) {
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
    S32(base, 0xb7c) = -1;
    return false;
}
#pragma opt_propagation reset
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

extern "C" u8 fn_8022B334(s32);
extern "C" u8 fn_8022B160(void*);
extern "C" void fn_80241618(void*, s32, s32);
extern "C" s32 fn_802373EC(s32);
extern "C" s32 fn_8023EEB4(s32);
extern "C" void fn_8024B298(void*, s32, void*);
extern "C" u8 fn_8025F500(void*);
extern "C" u8 fn_802518AC(void*, s32);
extern "C" u8 fn_80246228(void*);
extern "C" u8 lbl_8053ABB8[4];
extern "C" JGeometry::TVec3<f32> lbl_8046B220[];
#pragma opt_propagation off
static inline void playerSyncLinkedItem(u8* p) {
    s32 cur = fn_802416C4(p);
    s32 linkedKind = fn_802373EC(Player_GetLinkTargetIndex(p));
    if (linkedKind != cur) {
        fn_80241618(p, fn_802373EC(Player_GetLinkTargetIndex(p)), 1);
    }
}
extern "C" void fn_8025785C(void* self) {
    JGeometry::TVec3f pos;
    JGeometry::TVec3f v;
    u8* p = (u8*)self;
    u8* q;
    s32 created;
    s32 i;
    int cur;
    if (S32(p, 0xb74) > 0) {
        S32(p, 0xb74) = S32(p, 0xb74) - 1;
    }
    if (!fn_8022B334(S32(p, 0x4))) goto end;
    {
        if (Player_IsLinked(p)) {
            cur = fn_802416C4(p);
            s32 linkedKind = fn_802373EC(Player_GetLinkTargetIndex(p));
            if (linkedKind != cur) {
                fn_80241618(p, fn_802373EC(Player_GetLinkTargetIndex(p)), 1);
            }
        }
        if (!fn_8022C310(S32(p, 0x4))) goto end;
        {
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
                if (S32(p, 0xb18) < 0 && S32(p, 0xb74) <= 0) {
                    if (((u8 (*)(void))fn_8022B160)() == 0 ||
                        ((Player_IsLinked(p) == 0 || fn_802486A0(p) == 4) && lbl_8053ABB8[S32(p, 0x4)] == 0)) {
                        fn_80251AEC(p, 0x3a);
                    }
                }
            } else if (fn_802416C4(p) == 5) {
                fn_80251AEC(p, 0x3c);
            } else if (fn_802416C4(p) == 6) {
                if (fn_802415CC(p) >= 2) {
                    fn_80251AEC(p, 0x45);
                } else {
                    if (fn_802415CC(p) < 2) {
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
                    if (n >= 3) goto end;
                    }
                    fn_80251AEC(p, 0x44);
                }
            } else if (fn_802416C4(p) == 7) {
                if (fn_8025F500(p)) {
                    u8* actor = fn_801F666C(fn_801F856C(), S32(p, 0xd68));
                    if (actor != NULL && S32(actor, 0x1a4) != 0) {
                        goto end;
                    }
                }
                for (s32 j = 0; j < 4; j++) {
                    if (fn_80243194(p, j) && fn_8023EEB4(j) == 0x52434b32) {
                        goto end;
                    }
                }
                s32 id = S32(p, 0x3b4);
                if (*((u8*)fn_802D6A9C() + id + 0x131df) != 0) {
                if (fn_802518AC(p, 1) == 0) {
                    fn_8024B298(p, 2, &pos);
                    pos.y = pos.y + lbl_805400C8;
                    if (fn_8022461C(&pos, S32(p, 0x3b4)) != 2) {
                        goto chooseAction;
                    }
                    goto end;
                }
                } else if (F32(p, 0x10) > lbl_805400C4) {
                    goto end;
                }
chooseAction:
                if (fn_8025F684(p)) {
                    fn_80251AEC(p, 0x14);
                } else {
                    fn_80251AEC(p, 0x46);
                }
            } else if (fn_802416C4(p) == 8) {
                q = p;
                for (i = 0; i < 2; i++, q += 4) {
                    if (S32(q, 0xb30) < 0) {
                        const JGeometry::TVec3f& initial = lbl_8046B220[S32(p, 0x3dc)];
                        f32 z;
                        f32 y;
                        f32 x;
                        x = initial.x; y = initial.y; z = initial.z;
                        v.x = x; v.y = y; v.z = z;
                        v.add(V3(p, 0x8));
                        v.z = lbl_805400C4;
                        if (fn_8022461C(&v, S32(p, 0x3b4)) == 0xe) {
                            goto end;
                        }
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
#pragma opt_propagation reset
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
#pragma opt_propagation off
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
        if (fn_801F666C(fn_801F856C(), flags) != 0) {
            S32(p, 0xb3c) = flags;
            U8(p, 0x3fa) += 1;
            fn_80268B3C(p);
        }
    }
}
#pragma opt_propagation reset
extern "C" void fn_80258880(u8* p) {
    U8(p, 0x458) = 0;
}

extern "C" void fn_8025888C(void) {
}

#pragma opt_lifetimes off
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
            f32 right = lbl_805400E0 + pos.x;
            const f32 extent = lbl_805400E0;
            BOX(p, 0x5cc).set(pos.x - extent, pos.y - extent, right, extent + pos.y);
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
            U8(p, 0xb9e) = 0;
            U8(p, 0xb9f) = 0;
        }
        if (U8(p, 0x3fa) == 0x1c && U8(p, 0x3fd) == 0) {
            s32 r = S32(p, 0xba0);
            if (r > 0 && r <= 4) {
                const u16 (*table)[4] = lbl_8046B200;
                f32 alpha = lbl_805400D4;
                fn_8013CC50(S32(p, 0x3b4), p + 0x8, table[r - 1][S32(p, 0x3dc)], 0, 0, 0, 0, 1, alpha);
            }
        }
    }
    U8(p, 0x3fa)++;
    fn_80268B3C(p);
}
#pragma opt_lifetimes reset
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

#pragma opt_common_subs off
#pragma opt_propagation on
extern "C" void fn_80258BE8(u8* p) {
 if (fn_8022C6AC(U32(p,4)) > lbl_805400C4) {
if (lbl_805400C4 == F32(p,0x344)) {
 F32(p,0x344) = lbl_805400E4 * fn_8022C82C(PTR(p,4));
} else if (F32(p,0x344) > lbl_805400C4) {
 if (F32(p,0x34c) >= lbl_805400C4) F32(p,0x344) += lbl_805400E8 * fn_8022C82C(PTR(p,4));
 else F32(p,0x344) += lbl_805400EC * fn_8022C82C(PTR(p,4));
 if (F32(p,0x344) <= lbl_805400F0 || U8(PTR(p,0xbf0),0x48)) F32(p,0x344) = lbl_805400F0;
} else if (F32(p,0x344) < lbl_805400C4) {
 if (F32(p,0x34c) >= lbl_805400C4) F32(p,0x344) += lbl_805400E8 * fn_8022C82C(PTR(p,4));
 else F32(p,0x344) += lbl_805400EC * fn_8022C82C(PTR(p,4));
 if (F32(p,0x344) >= lbl_805400F4 || U8(PTR(p,0xbf0),0x49)) F32(p,0x344) = lbl_805400F4;
}
if (lbl_805400C4 == F32(p,0x348)) {
 F32(p,0x348) = lbl_805400E4 * -fn_8022C76C(PTR(p,4));
} else if (F32(p,0x348) > lbl_805400C4) {
 if (F32(p,0x34c) >= lbl_805400C4) F32(p,0x348) -= lbl_805400E8 * fn_8022C76C(PTR(p,4));
 else F32(p,0x348) -= lbl_805400EC * fn_8022C76C(PTR(p,4));
 if (F32(p,0x348) <= lbl_805400F0 || U8(PTR(p,0xbf0),0x4a)) F32(p,0x348) = lbl_805400F0;
} else if (F32(p,0x348) < lbl_805400C4) {
 if (F32(p,0x34c) >= lbl_805400C4) F32(p,0x348) -= lbl_805400E8 * fn_8022C76C(PTR(p,4));
 else F32(p,0x348) -= lbl_805400EC * fn_8022C76C(PTR(p,4));
 if (F32(p,0x348) >= lbl_805400F4 || U8(PTR(p,0xbf0),0x4b)) F32(p,0x348) = lbl_805400F4;
}
f32 savedZ = F32(p,0x34c);
 F32(p,0x34c)=lbl_805400C4;
 f32 mag=V3(p,0x344).length();
 if(mag>=lbl_805400F8)mag=lbl_805400F8;
 V3(p,0x344).normalize(); V3(p,0x344).scale(mag);
 F32(p,0x34c)=savedZ;
 } else {
 JGeometry::TVec3<f32>& velocity = V3(p,0x344);
 f32 xSquared=velocity.x*velocity.x;
 f32 ySquared=velocity.y*velocity.y;
 f32 sq=xSquared+ySquared;
 if (!(sq<=lbl_805400D8 * *(f32*)__float_epsilon)) {
 f32 savedZ=F32(p,0x34c);
 F32(p,0x34c)=lbl_805400C4;
 f32 mag=velocity.length();
 if(fn_8022C274(U32(p,4))) {
 if(savedZ>=lbl_805400C4) {
 mag+=lbl_805400E8; if(mag>=lbl_805400F8)mag=lbl_805400F8;
 }else {mag+=lbl_805400EC;if(mag>=lbl_805400F8)mag=lbl_805400F8;}
 }else {mag-=lbl_80540100;if(mag<=lbl_805400F0)mag=lbl_805400F0;}
 V3(p,0x344).normalize(); V3(p,0x344).scale(mag);
 F32(p,0x34c)=savedZ;
 }
 }
 if(playerVelocitySquared(V3(p,0x344))<=lbl_805400D8 * *(f32*)__float_epsilon) {
 if(!(F32(p,0x10)>lbl_805400C4)) goto afterPhysics;
 }
 if(U8(p,0x3fa)<1) goto afterPhysics;
 F32(p,0x34c)-=lbl_80540104;
 if(F32(p,0x34c)<lbl_80540108)F32(p,0x34c)=lbl_80540108;
 {
 f32 oldHeight=F32(p,0x10);
 s32 room=S32(p,0x3b4);
 u8* rooms=(u8*)fn_802D6A9C();
 if(rooms[0x131df+room]) {
 F32(p,8)+=F32(p,0x344);F32(p,0xc)-=F32(p,0x34c);
 F32(p,0x10)=lbl_805400C0;
 if(F32(p,0x34c)<lbl_805400C4 && U8(PTR(p,0xbf0),0x4a)) {
 V3(p,0x368).set(F32(p,0x344),F32(p,0x348),lbl_805400C4);
 F32(p,0x344)=lbl_805400C4;F32(p,0x348)=lbl_805400C4;F32(p,0x34c)=lbl_805400C4;F32(p,0x10)=lbl_805400C4;
 if (oldHeight > lbl_805400C4) {
 if ((fn_8024B24C(p) || U8(p, 0x1204)) && fn_802486A0(p) == 5 && !Player_IsLinked(p)) {
 for (s32 i = 0; i < 4; ++i) {
 if (fn_80243194(p, i) && i != S32(p, 4)) fn_8023E690(i, p + 8);
 } fn_8024BAEC(p);
 } }
 }
 }else {
 V3(p,8)+=V3(p,0x344);
 if(F32(p,0x34c)<lbl_805400C4 && F32(p,0x10)<=lbl_805400C4) {
 F32(p,0x10)=lbl_805400C4;
 V3(p,0x368).set(F32(p,0x344),F32(p,0x348),lbl_805400C4);
 F32(p,0x344)=lbl_805400C4;F32(p,0x348)=lbl_805400C4;F32(p,0x34c)=lbl_805400C4;
 if (oldHeight > lbl_805400C4) {
 if ((fn_8024B24C(p) || U8(p, 0x1204)) && fn_802486A0(p) == 5 && !Player_IsLinked(p)) {
 for (s32 i = 0; i < 4; ++i) {
 if (fn_80243194(p, i) && i != S32(p, 4)) fn_8023E690(i, p + 8);
 } fn_8024BAEC(p);
 } }
 }
 }
 }
 afterPhysics:
 if(U8(p,0xb79)==0 && F32(p,0x10)>lbl_805400C4 && fn_802415CC(p)>=2 && fn_8022C310(U32(p,4))) {
 U8(p,0x3fb)=0;U8(p,0x3fa)=0;U8(p,0x3fc)=0;F32(p,0x34c)=lbl_8054010C;U8(p,0xb79)=1;
 }
 if(U8(p,0x3fa)<4) U8(p,0x3fb)=0;
 else if(U8(p,0x3fa)<9) U8(p,0x3fb)=1;
 else if(U8(p,0x3fa)<13) U8(p,0x3fb)=2;
 else if(U8(p,0x3fa)<17) U8(p,0x3fb)=3;
 else if(U8(p,0x3fa)<21) U8(p,0x3fb)=4;
 else if(U8(p,0x3fa)<25) U8(p,0x3fb)=5;
 else if(U8(p,0x3fa)<29) U8(p,0x3fb)=6;
 else if(U8(p,0x3fa)<33) U8(p,0x3fb)=7;
 else if(F32(p,0x10)<=lbl_805400C4) {
 F32(p,0x10)=lbl_805400C4;
 if(fn_8022C310(U32(p,4))) {
 U8(p,0x3fb)=0;U8(p,0x3fa)=0;U8(p,0x3fc)=0;
 F32(p,0x34c)=lbl_8054010C;U8(p,0xb79)=0;
 if(fn_8024B24C(p) && fn_802486A0(p)==5 && !Player_IsLinked(p)) {
 for(s32 i=0;i<4;++i) if(fn_80243194(p,i) && i!=S32(p,4))fn_8023E690(i,p+8);
 fn_8024BAEC(p);
 }
 if(fn_8024B24C(p))U8(p,0x1204)=1;else U8(p,0x1204)=0;
 } else {
 U8(p,0x3fb)=0;U8(p,0x3fc)++;
 if(U8(p,0x3fc)>=3)fn_80251AEC(p,0);
 }
 }else U8(p,0x3fb)=7;
 if(U8(p,0x3fa)>=8) {
 s32 room=S32(p,0x3b4);
 u8* rooms=(u8*)fn_802D6A9C();
 if(rooms[0x131df+room] && F32(p,0x34c)<lbl_805400C4 && F32(p,0x10)<=lbl_805400D4) {
 JGeometry::TVec3<f32> pos;
 fn_8024B298(p,2,&pos);pos.y+=lbl_805400C8;
 if(fn_8022461C(&pos,S32(p,0x3b4))!=2)fn_80251AEC(p,0);
 }
 }
 if(U8(p,0x458)==0 && U8(p,0x3fa)>=8 && fn_8022C3AC(U32(p,4))) {
 if(fn_80243234(p))fn_80251AEC(p,7);else fn_80251AEC(p,5);
 }
 U8(p,0x3fa)++;
 fn_802685D4(p);
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
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

static inline bool tu8025_eq1(f32 a, f32 b, f32 eps) {
    bool equal = false;
    f32 d = a - b;
    if (-eps <= d && d <= eps) {
        equal = true;
    }
    return equal;
}

static inline bool tu8025_eq2(u8* a, u8* b, f32 eps) {
    bool equal = false;
    if (tu8025_eq1(F32(a, 0x0), F32(b, 0x0), eps) &&
        tu8025_eq1(F32(a, 0x4), F32(b, 0x4), eps)) {
        equal = true;
    }
    return equal;
}

static inline bool tu8025_eq3(u8* a, u8* b, f32 eps) {
    bool equal = false;
    if (tu8025_eq2(a, b, eps) && tu8025_eq1(F32(a, 0x8), F32(b, 0x8), eps)) {
        equal = true;
    }
    return equal;
}

#pragma opt_strength_reduction off
extern "C" void fn_80259830(u8* p0) {
    u8* tbl = (u8*)lbl_8046AF00;
    const Tu80256Tables* tables=(const Tu80256Tables*)lbl_8046AF00;
    u8* p = p0;
    if (S32(p, 0xb8c) > 0) {
        S32(p, 0xb8c) = S32(p, 0xb8c) - 1;
    }
    if (U8(p, 0xb84) == 1 && fn_8022C274(U32(p, 4)) == 0) {
        U8(p, 0xb84) = 0;
    }
    u8 s = U8(p, 0x3fa);
    if (s < 2) {
        U8(p, 0x3fb) = 0;
    } else if (s < 3) {
        U8(p, 0x3fb) = 1;
    } else if (s < 4) {
        U8(p, 0x3fb) = 2;
    } else if (s < 10) {
        U8(p, 0x3fb) = 3;
    } else if (s < 11) {
        U8(p, 0x3fb) = 4;
    } else if (s < 13) {
        U8(p, 0x3fb) = 5;
    } else {
        U8(p, 0x3fb) = 5;
        fn_80251AEC(p, 0);
    }
    if (U8(p, 0xb84) == 0 && U8(p, 0x3fa) == 0xb) {
        if (U8(p, 0xbb8) == 0) {
            fn_8043D67C(lbl_8053AED0, 0xe8, U32(p, 4), 0);
            U8(p, 0xbb8) = 1;
        }
        if (fn_801F666C(fn_801F856C(), S32(p, 0xb2c)) == 0) {
            if (fn_80247594(p, 0)) {
                JGeometry::TVec3<f32> pos = V3(p, 8);
                switch (S32(p, 0x3dc)) {
                case 0:
                    pos.x = pos.x + lbl_805400DC;
                    break;
                case 1:
                    pos.x = pos.x - lbl_805400DC;
                    break;
                case 2:
                    pos.y = pos.y + lbl_805400DC;
                    break;
                case 3:
                    pos.y = pos.y - lbl_805400DC;
                    break;
                }
                S32(p, 0xb2c) = Actor_CreateByID(fn_801F856C(), 0x534d5249, U32(p, 0x3b4), &pos, 0, -1, U32(p, 4));
            }
        } else {
            fn_8030EA00();
        }
    }
    if (U8(p, 0x3fa) == 0xc) {
        JGeometry::TVec3<f32> pos = V3(p, 8);
        JGeometry::TBox2<f32> box;
        switch (S32(p, 0x3dc)) {
        case 0:
            pos.x += 18.0f;
            box.set(pos.x,pos.y-6.0f,pos.x+lbl_80540118,6.0f+pos.y);
            BOX(p,0x580).set(box);break;
        case 1:
            pos.x -= 18.0f;
            box.set(pos.x-lbl_80540118,pos.y-6.0f,pos.x,6.0f+pos.y);
            BOX(p,0x580).set(box);break;
        case 2:
            pos.x += 4.0f;pos.y += 12.0f;
            box.set(pos.x-6.0f,pos.y,6.0f+pos.x,pos.y+lbl_80540118);
            BOX(p,0x580).set(box);break;
        case 3:
            pos.x -= 4.0f;pos.y -= 20.0f;
            box.set(pos.x-6.0f,pos.y-lbl_80540118,6.0f+pos.x,pos.y);
            BOX(p,0x580).set(box);break;
        }
        if (U8(p, 0xb84) != 0) {
            fn_802808E8(p, lbl_80540124);
            if (tu8025_eq3(p+8,p+0x14,lbl_805400D8 * *(f32*)__float_epsilon)) {
                U8(p, 0x3f8) = 0;
            } else {
                U8(p, 0x3f8) = U8(p, 0x3f8) + 1;
                if (U8(p, 0x3f8) >= 0x1c) {
                    U8(p, 0x3f8) = 0;
                }
            }
                        if (U8(p, 0x3f8) < 4) {
                U8(p, 0x3f9) = (tables->frames290[S32(p,0x3dc)]+0)[0];
            } else if (U8(p, 0x3f8) < 6) {
                U8(p, 0x3f9) = (tables->frames290[S32(p,0x3dc)]+1)[0];
            } else if (U8(p, 0x3f8) < 10) {
                U8(p, 0x3f9) = (tables->frames290[S32(p,0x3dc)]+2)[0];
            } else if (U8(p, 0x3f8) < 14) {
                U8(p, 0x3f9) = (tables->frames290[S32(p,0x3dc)]+3)[0];
            } else if (U8(p, 0x3f8) < 18) {
                U8(p, 0x3f9) = (tables->frames290[S32(p,0x3dc)]+4)[0];
            } else if (U8(p, 0x3f8) < 20) {
                U8(p, 0x3f9) = (tables->frames290[S32(p,0x3dc)]+5)[0];
            } else if (U8(p, 0x3f8) < 24) {
                U8(p, 0x3f9) = (tables->frames290[S32(p,0x3dc)]+6)[0];
            } else {
                U8(p, 0x3f9) = (tables->frames290[S32(p,0x3dc)]+7)[0];
            }
            if (!fn_80247594(p, 1)) {
                U8(p, 0xb84) = 0;
            }
            if (S32(p, 0xb8c) <= 0 && S32(p, 0xb28) < 0) {
                s32 owner=S32(p,4);
                S32(p, 0xb28) = Actor_CreateByID(fn_801F856C(), 0x46495245, U32(p, 0x3b4), &pos,
                                                 ((S32(p, 0x3dc) & 3) << 4) | 0x1040 | (owner & 3), -1, owner);
            }
            s32 id=S32(p,0xb28);
            if (id >= 0) {
                u8* ret = fn_801F666C(fn_801F856C(), id);
                if (ret != 0) {
                    fn_802BAA0C(ret, &box);
                } else {
                    S32(p, 0xb28) = -1;
                    S32(p, 0xb8c) = 0x3c;
                }
            }
        if (PTR(p, 0x12c4) == 0) {
            PTR(p, 0x12c4) = fn_8013CC50(S32(p, 0x3b4), &pos, 0x1ab, 0, 2, 0, 0, 1, lbl_805400D4);
        }
        if (PTR(p, 0x12c4) != 0) {
            JPAGetXYZRotateMtx(0, (s16)tables->rotations2B0[S32(p,0x3dc)], -0x8000,
                               (f32(*)[4])(PTR(p, 0x12c4) + 0x68));
            fn_8013CB44(PTR(p, 0x12c4), &pos, 0, 2, 1);
        }
        if (PTR(p, 0x12c8) == 0) {
            PTR(p, 0x12c8) = fn_8013CC50(S32(p, 0x3b4), &pos, 0x54a, -1, 0, 0, 0, 1, lbl_805400D4);
        }
        if (PTR(p, 0x12c8) != 0) {
            JPAGetXYZRotateMtx(0, 0, (s16)tables->rotations2C0[S32(p,0x3dc)],
                               (f32(*)[4])(PTR(p, 0x12c8) + 0x68));
            fn_8013CB44(PTR(p, 0x12c8), &pos, -1, 0, 1);
        }
        fn_8024F0E8(p, 0x30011);
        } else {
            U8(p,0x3fa)++;
    if (PTR(p, 0x12c8) != 0) {
        u32 fl = U32(PTR(p, 0x12c8), 0xf4);
        U32(PTR(p, 0x12c8), 0xf4) = fl | 1;
    }
    if (PTR(p, 0x12c4) != 0) {
        u32 fl = U32(PTR(p, 0x12c4), 0xf4);
        U32(PTR(p, 0x12c4), 0xf4) = fl | 1;
    }
        }
    } else {
        U8(p,0x3fa)++;
    }
    fn_80268B3C(p);
}
#pragma opt_strength_reduction reset
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

extern "C" u8 fn_8023B400(s32);
extern const f32 lbl_80540128;
struct PlayerFirePosition {
    u8 pad[0xb1c];
    s32 ids[3];
    s32 activeId;
    u8 padB2C[0xb5c - 0xb2c];
    s32 rooms[3];
};
struct Tu8025Data {
    u8 pad[0x250];
    u8 frames[4][8];
    s32 rotA[4];
    s32 rotB[4];
};



#pragma pool_data on
static const u8 fireTablePrefix[0x190] = {
    0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x20, 0x00, 0x00, 0x41, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc1, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x00, 0x00, 0x00,
    0xc1, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc1, 0x20, 0x00, 0x00,
    0x00, 0x01, 0x02, 0x03, 0x00, 0x01, 0x02, 0x03, 0x00, 0x01, 0x02, 0x03, 0x00, 0x01, 0x02, 0x03,
    0x00, 0x01, 0x02, 0x03, 0x00, 0x04, 0x05, 0x06, 0x00, 0x01, 0x02, 0x03, 0x00, 0x04, 0x05, 0x06,
    0x40, 0xff, 0xf7, 0xcf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xf7, 0xcf,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xff, 0xf7, 0xcf,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xf7, 0xcf, 0x00, 0x00, 0x00, 0x00,
    0x40, 0xc0, 0x00, 0x00, 0x40, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00,
    0x40, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x42, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc2, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc2, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00,
    0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x40, 0x80, 0x00, 0x00,
    0x41, 0x40, 0x00, 0x00, 0x41, 0x90, 0x00, 0x00, 0x41, 0xa0, 0x00, 0x00, 0xc1, 0x40, 0x00, 0x00,
    0x41, 0x90, 0x00, 0x00, 0x41, 0xa0, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x41, 0xe0, 0x00, 0x00,
    0x41, 0xa0, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x41, 0xa0, 0x00, 0x00,
    0x41, 0x40, 0x00, 0x00, 0x41, 0x90, 0x00, 0x00, 0x41, 0xa0, 0x00, 0x00, 0xc1, 0x40, 0x00, 0x00,
    0x41, 0x90, 0x00, 0x00, 0x41, 0xa0, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x41, 0xe0, 0x00, 0x00,
    0x41, 0xa0, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x41, 0xa0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x07,
    0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07,
};
static const Vec blastStartPositions[4] = {
    { -16.0f, -2.0f, 16.0f },
    { 16.0f, -2.0f, 16.0f },
    { 0.0f, -6.0f, 16.0f },
    { 0.0f, -4.0f, 16.0f },
};
static const Vec blastHitPositions[8] = {
    { 20.0f, 7.0f, 0.0f },
    { -20.0f, 7.0f, 0.0f },
    { 0.0f, 12.0f, 0.0f },
    { 0.0f, -8.0f, 0.0f },
    { 24.0f, 7.0f, 0.0f },
    { -24.0f, 7.0f, 0.0f },
    { 0.0f, 11.0f, 0.0f },
    { 0.0f, -6.0f, 0.0f },
};
static const Vec blastTerrainPositions[4] = {
    { 16.0f, 0.0f, 0.0f },
    { -16.0f, 0.0f, 0.0f },
    { 0.0f, 16.0f, 0.0f },
    { 0.0f, -16.0f, 0.0f },
};
static const u8 fireAnimationFrames[4][8] = {
    {0,1,2,3,0,1,2,3}, {0,1,2,3,0,1,2,3},
    {0,1,2,3,0,4,5,6}, {0,1,2,3,0,4,5,6}
};
static const s32 fireRotationA[4] = {0xc000, 0x4000, 0x8000, 0};
static const s32 fireRotationB[4] = {0xc000, 0x4000, 0, 0x8000};
#pragma pool_data reset
#pragma opt_lifetimes off
#pragma pool_data on
extern "C" void fn_8025A15C(u8* p) {
    s32 actorID;
    PlayerFirePosition* fire = (PlayerFirePosition*)p;
    u8* base = (u8*)fireTablePrefix;
    JGeometry::TVec3<f32> pos;
    JGeometry::TBox2<f32> box;
    JGeometry::TVec3<f32> pos2;
    if (S32(p, 0xb8c) > 0) {
        S32(p, 0xb8c) = S32(p, 0xb8c) - 1;
    }
    if (U8(p, 0xb84) == 1 && !fn_8022C274(U32(p, 0x4))) {
        U8(p, 0xb84) = 0;
    }
    u8 state = U8(p, 0x3fa);
    if (state < 2) {
        U8(p, 0x3fb) = 0;
    } else if (state < 3) {
        U8(p, 0x3fb) = 1;
    } else if (state < 4) {
        U8(p, 0x3fb) = 2;
    } else if (state < 10) {
        U8(p, 0x3fb) = 3;
    } else if (state < 11) {
        U8(p, 0x3fb) = 4;
    } else if (state < 12) {
        U8(p, 0x3fb) = 5;
    } else {
        U8(p, 0x3fb) = 5;
        fn_80251AEC(p, 0);
    }
    if (U8(p, 0x3fa) == 0xb) {
        pos = V3(p, 0x8);
        switch (S32(p, 0x3dc)) {
        case 0:
            pos.x += lbl_80540110;
            box.set(pos.x, pos.y - 6.0f, pos.x + lbl_80540118, 6.0f + pos.y);
            BOX(p, 0x580).set(box);
            break;
        case 1:
            pos.x -= lbl_80540110;
            box.set(pos.x - lbl_80540118, pos.y - 6.0f, pos.x, 6.0f + pos.y);
            BOX(p, 0x580).set(box);
            break;
        case 2:
            pos.x += lbl_805400E0;
            pos.y += lbl_8054011C;
            box.set(pos.x - 6.0f, pos.y, 6.0f + pos.x, pos.y + lbl_80540118);
            BOX(p, 0x580).set(box);
            break;
        case 3:
            pos.x -= lbl_805400E0;
            pos.y -= lbl_80540120;
            box.set(pos.x - 6.0f, pos.y - lbl_80540118, 6.0f + pos.x, pos.y);
            BOX(p, 0x580).set(box);
            break;
        }
        if (U8(p, 0xb84) != 0) {
            fn_802808E8(p, lbl_80540124);
            if (tu8025_eq3(p + 0x8, p + 0x14, lbl_805400D8 * *(f32*)__float_epsilon)) {
                U8(p, 0x3f8) = 0;
            } else {
                U8(p, 0x3f8)++;
                if (U8(p, 0x3f8) >= 0x1c) {
                    U8(p, 0x3f8) = 0;
                }
            }
            u8 c = U8(p, 0x3f8);
            if (c < 4) {
                U8(p, 0x3f9) = fireAnimationFrames[S32(p, 0x3dc)][0];
            } else if (c < 6) {
                U8(p, 0x3f9) = fireAnimationFrames[S32(p, 0x3dc)][1];
            } else if (c < 10) {
                U8(p, 0x3f9) = fireAnimationFrames[S32(p, 0x3dc)][2];
            } else if (c < 14) {
                U8(p, 0x3f9) = fireAnimationFrames[S32(p, 0x3dc)][3];
            } else if (c < 18) {
                U8(p, 0x3f9) = fireAnimationFrames[S32(p, 0x3dc)][4];
            } else if (c < 20) {
                U8(p, 0x3f9) = fireAnimationFrames[S32(p, 0x3dc)][5];
            } else if (c < 24) {
                U8(p, 0x3f9) = fireAnimationFrames[S32(p, 0x3dc)][6];
            } else {
                U8(p, 0x3f9) = fireAnimationFrames[S32(p, 0x3dc)][7];
            }
            if (!fn_80247594(p, 1)) {
                U8(p, 0xb84) = 0;
            }
            if (S32(p, 0xb8c) <= 0 && S32(p, 0xb28) < 0) {
                actorID = S32(p, 0x4);
                S32(p, 0xb28) = Actor_CreateByID(fn_801F856C(), 0x46495245, S32(p, 0x3b4), &pos, ((S32(p, 0x3dc) & 3) << 4) | 0x1040 | (actorID & 3), -1, actorID);
            }
                actorID = S32(p, 0xb28);
                if (actorID >= 0) {
                    u8* a = fn_801F666C(fn_801F856C(), actorID);
                    if (a) {
                        fn_802BAA0C(a, &box);
                    } else {
                        S32(p, 0xb28) = -1;
                        S32(p, 0xb8c) = 0x3c;
                    }
                }
            if (PTR(p, 0x12c4) == 0) {
                PTR(p, 0x12c4) = fn_8013CC50(S32(p, 0x3b4), &pos, 0x1ab, 0, 2, 0, 0, 1, lbl_805400D4);
            }
            if (PTR(p, 0x12c4)) {
                ((JPABaseEmitter*)PTR(p, 0x12c4))->setGlobalRotation(JGeometry::TVec3<s16>((s16)0, (s16)fireRotationA[S32(p, 0x3dc)], (s16)-0x8000));
                fn_8013CB44(PTR(p, 0x12c4), &pos, 0, 2, 1);
            }
            if (PTR(p, 0x12c8) == 0) {
                PTR(p, 0x12c8) = fn_8013CC50(S32(p, 0x3b4), &pos, 0x54a, -1, 0, 0, 0, 1, lbl_805400D4);
            }
            if (PTR(p, 0x12c8)) {
                ((JPABaseEmitter*)PTR(p, 0x12c8))->setGlobalRotation(JGeometry::TVec3<s16>((s16)0, (s16)0, (s16)fireRotationB[S32(p, 0x3dc)]));
                fn_8013CB44(PTR(p, 0x12c8), &pos, -1, 0, 1);
            }
            fn_8024F0E8(p, 0x30011);
        } else {
            if (PTR(p, 0x12c8)) {
                U32(PTR(p, 0x12c8), 0xf4) |= 1;
            }
            if (PTR(p, 0x12c4)) {
                U32(PTR(p, 0x12c4), 0xf4) |= 1;
            }
            if (S32(p, 0xb28) < 0) {
                s32 n = 0;
                if (S32(p, 0xb1c) >= 0) {
                    n = 1;
                }
                if (n < 1 && (!Player_IsLinked(p) || fn_802486A0(p) == 4 || fn_8023B400(Player_GetLinkTargetIndex(p))) && fn_80247594(p, 0)) {
                    pos2 = V3(p, 0x8);
                    switch (S32(p, 0x3dc)) {
                    case 0:
                        pos2.x += lbl_80540128;
                        break;
                    case 1:
                        pos2.x -= lbl_80540128;
                        break;
                    case 2:
                        pos2.y += lbl_80540128;
                        break;
                    case 3:
                        break;
                    }
                    int i;
                    for (i = 0, base = p; i < 3; i++, base += 4) {
                        if (S32(base, 0xb1c) < 0) {
                            actorID = S32(p, 0x4);
                            S32(base, 0xb1c) = Actor_CreateByID(fn_801F856C(), 0x46495245, S32(p, 0x3b4), &pos2, ((S32(p, 0x3dc) & 3) << 4) | 0x1000 | (actorID & 3), -1, actorID);
                            if (S32(base, 0xb1c) >= 0) {
                                fire->rooms[i] = S32(p, 0x3b4);
                                U8(p, 0xb78) = 1;
                                break;
                            }
                        }
                    }
                }
            }
            U8(p, 0x3fa)++;
        }
    } else {
        U8(p, 0x3fa)++;
    }
    fn_80268B3C(p);
}

#pragma opt_propagation reset
#pragma opt_strength_reduction reset
#pragma pool_data reset
#pragma opt_lifetimes reset
#pragma opt_common_subs reset
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

extern "C" void fn_8025AB00(u8* p) {
    f32 speed;
    U8(p,0x3fc)++;
    if (U8(p,0x3fc)<10) U8(p,0x3fd)=0;
    else if (U8(p,0x3fc)<14) U8(p,0x3fd)=1;
    else U8(p,0x3fd)=2;
    fn_80268B3C(p);
    if (U8(p,0xafc)!=1 && !playerListBusy(PTR(p,0xbf0))) {
        u8* obj=fn_801F666C(fn_801F856C(),S32(p,0x11f8));
        if (obj && S32(obj,0x230)==0) {
            JGeometry::TVec3<f32> v(V3(obj,0xc)-V3(p,8));
            speed=v.length();
            if (speed>lbl_80540114) speed=lbl_80540114;
            v.z=0.0f;
            v.normalize();
            if (!v.isZero()) {
                v.scale(speed);
                V3(p,8).add(v);
                if (v.x+v.y<0.0f) {
                    if (v.x-v.y<0.0f) { S32(p,0x3dc)=0; S32(p,0x3e8)=0; }
                    else { S32(p,0x3dc)=2; S32(p,0x3e8)=2; }
                } else {
                    if (v.x-v.y<0.0f) { S32(p,0x3dc)=3; S32(p,0x3e8)=3; }
                    else { S32(p,0x3dc)=1; S32(p,0x3e8)=1; }
                }
            }
            F32(p,0x10)=0.0f;
            return;
        }
    }
    U8(p,0x124d)=0;
    fn_80251AEC(p,0);
}

extern "C" void fn_8025AEB0(u8* p) {
    U8(p, 0x124d) = 1;
    U8(p, 0x458) = 0;
}

extern "C" void fn_8025AEC4(u8* p) {
    S32(p, 0x11f8) = -1;
}

extern "C" void fn_8025AED0(u8* p) {
    f32 speed;
    U8(p, 0x3fc) = U8(p, 0x3fc) + 1;
    s32 phase = (U8(p, 0x3fc) >> 1) & 3;
    if (phase == 0) {
        S32(p, 0x3dc) = 0; S32(p, 0x3e8) = 0;
    } else if (phase == 1) {
        S32(p, 0x3dc) = 2; S32(p, 0x3e8) = 2;
    } else if (phase == 2) {
        S32(p, 0x3dc) = 1; S32(p, 0x3e8) = 1;
    } else {
        S32(p, 0x3dc) = 3; S32(p, 0x3e8) = 3;
    }
    fn_80268B3C(p);
    if (U8(p, 0xafc) != 1) {
        if (!playerListBusy(PTR(p,0xbf0))) {
            u8* obj=fn_801F666C(fn_801F856C(),S32(p,0x11f8));
            if (obj && S32(obj,4)==S32(p,0x3b4)) {
                JGeometry::TVec3<f32> v(V3(obj,0xc)-V3(p,8));
                v.z=0.0f;
                v.normalize();
                if (!v.isZero()) {
                    speed = lbl_80540114;
                    v.scale(speed);
                    V3(p,8).add(v);
                }
                F32(p,0x10)=0.0f;
                return;
            }
        }
    }
    U8(p, 0x124d) = 0;
    fn_80251AEC(p, 0);
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

#pragma pool_data on
extern "C" void fn_8025B3F0(u8* p) {
    s32 limit = 0x30;
    if (fn_8022B244()) {
        limit = 0x19;
    }
    if (U8(p, 0x3fa) == 0 && fn_8022C274(U32(p, 0x4))) {
        fn_8027EB04(p);
        U8(p, 0x3fc) = U8(p, 0x3fc) + 1;
        if (U8(p, 0x3fc) == limit) {
            U8(p, 0xb9b) = 1;
            tu8025_copyVec(&V3(p, 0x12a4), (const JGeometry::TVec3<f32>*)blastStartPositions, S32(p, 0x3dc));
            V3(p, 0x12a4) += V3(p, 0x8);
            s32 room = S32(p, 0x3b4);
            if (room < 8) {
                if (PTR(p, 0x1274) == 0) {
                    PTR(p, 0x1274) = fn_8013CC50(room, p + 0x12a4, 0xcb, 0, 0, 0, 0, 1, lbl_805400D4);
                    if (PTR(p, 0x1274) != 0) {
                        U32(PTR(p, 0x1274), 0xf4) |= 0x40;
                    }
                }
                if (PTR(p, 0x128c) == 0) {
                    PTR(p, 0x128c) = fn_8013CC50(S32(p, 0x3b4), p + 0x12a4, 0xcc, 0, 0, 0, 0, 1, lbl_805400D4);
                    if (PTR(p, 0x128c) != 0) {
                        U32(PTR(p, 0x128c), 0xf4) |= 0x40;
                    }
                }
            } else {
                Actor_CreateByID(fn_801F856C(), 0x50454646, room, p + 0x12a4, (U32(p, 0x4) & 3) | 8, -1, -1);
            }
            fn_8024F0E8(p, 0x2000D);
        } else if (U8(p, 0x3fc) >= (u8)(limit + 1)) {
            U8(p, 0x3fc) = limit + 1;
        }
    } else {
        U8(p, 0x3fa)++;
    }
    u8 st = U8(p, 0x3fa);
    if (st == 0) {
        if (U8(p, 0x3fc) < 2) {
            U8(p, 0x3fb) = 2;
        } else if (U8(p, 0x3fc) < 4) {
            U8(p, 0x3fb) = 1;
        } else {
            U8(p, 0x3fb) = 0;
        }
    } else if (U8(p, 0xb9b) == 0) {
        if (st < 3) {
            U8(p, 0x3fb) = 1;
        } else if (st < 5) {
            U8(p, 0x3fb) = 2;
        } else if (st < 13) {
            if (S32(p, 0x3b4) < 8) {
                U8(p, 0x3fb) = 5;
            } else if (st < 7) {
                U8(p, 0x3fb) = 3;
            } else if (st < 9) {
                U8(p, 0x3fb) = 4;
            } else {
                U8(p, 0x3fb) = 5;
            }
        } else {
            U8(p, 0x3fb) = 6;
        }
        if (U8(p, 0x3fa) >= 0x11) {
            fn_80251AEC(p, 0);
        }
    } else {
        if (st < 2) {
            U8(p, 0x3fb) = 1;
        } else if (st < 3) {
            U8(p, 0x3fb) = 2;
        } else if (st < 4) {
            U8(p, 0x3fb) = 3;
        } else if (st < 5) {
            U8(p, 0x3fb) = 4;
        } else if (st < 6) {
            U8(p, 0x3fb) = 3;
        } else if (st < 7) {
            U8(p, 0x3fb) = 4;
        } else if (st < 8) {
            U8(p, 0x3fb) = 3;
        } else if (st < 9) {
            U8(p, 0x3fb) = 4;
        } else if (st < 11) {
            U8(p, 0x3fb) = 5;
        } else if (st < 13) {
            U8(p, 0x3fb) = 6;
        } else if (st < 15) {
            U8(p, 0x3fb) = 5;
        } else if (st < 20) {
            U8(p, 0x3fb) = 6;
        } else {
            U8(p, 0x3fb) = 7;
        }
        if (U8(p, 0x3fa) >= 0x1e) {
            fn_80251AEC(p, 0);
        }
        if (S32(p, 0x3b4) < 8) {
            if (U8(p, 0x3fb) == 3) {
                U8(p, 0x3fb) = 5;
            } else if (U8(p, 0x3fb) == 4) {
                U8(p, 0x3fb) = 6;
            }
        }
    }
    if (U8(p, 0xb9b) == 1) {
        tu8025_copyVec(&V3(p, 0x5c0), (const JGeometry::TVec3<f32>*)blastHitPositions, S32(p, 0x3dc) + 4);
    } else {
        tu8025_copyVec(&V3(p, 0x5c0), (const JGeometry::TVec3<f32>*)blastHitPositions, S32(p, 0x3dc));
    }
    V3(p, 0x5c0) += V3(p, 0x8);
    F32(p, 0x5c8) = lbl_805400C4;
    u8 prev = U8(p, 0xb99);
    if (fn_8022B244()) {
        if (U8(p, 0x3fa) == 1) {
            U8(p, 0xb99) = 1;
        } else if (U8(p, 0x3fa) == 3) {
            U8(p, 0xb99) = 0;
        }
    } else {
        if (U8(p, 0x3fa) == 5) {
            U8(p, 0xb99) = 1;
        } else if (U8(p, 0x3fa) == 7) {
            U8(p, 0xb99) = 0;
        }
    }
    if (U8(p, 0xb99) == 1 && prev == 0) {
        if (fn_8022B244()) {
            F32(p, 0x5b0) = lbl_8054012C;
            F32(p, 0x5b4) = lbl_8054012C;
            F32(p, 0x5b8) = lbl_805400DC;
            F32(p, 0x5bc) = lbl_805400DC;
        } else {
            F32(p, 0x5b0) = lbl_80540130;
            F32(p, 0x5b4) = lbl_80540130;
            F32(p, 0x5b8) = lbl_80540128;
            F32(p, 0x5bc) = lbl_80540128;
        }
        F32(p, 0x5b0) += F32(p, 0x5c0);
        F32(p, 0x5b4) += F32(p, 0x5c4);
        F32(p, 0x5b8) += F32(p, 0x5c0);
        F32(p, 0x5bc) += F32(p, 0x5c4);
        JGeometry::TVec3<f32> v;
        tu8025_copyVec(&v, (const JGeometry::TVec3<f32>*)blastTerrainPositions, S32(p, 0x3dc));
        v += V3(p, 0x8);
        fn_802A1D44(lbl_8053AC98, &v, U32(p, 0x4), S32(p, 0x3b4));
        f32 scale = lbl_805400D4;
        if (fn_802486A0(p) != 5 && !fn_80240AF0(p)) {
            scale /= (f32)fn_802487FC(p);
        }
        if (fn_802415CC(p) <= 1) {
            scale *= lbl_805400C0;
        }
        if (U8(p, 0xb9b) == 1) {
            if (S32(p, 0x3b4) < 8) {
                fn_802F601C(*(void**)(lbl_8053AB10 + 0x20), (JGeometry::TVec3<f32>*)(p + 0x5c0), 2, 0, lbl_805400D4, lbl_805400C8 * scale);
            }
            fn_8024F0E8(p, 0x2002B);
            fn_8013CC50(S32(p, 0x3b4), p + 0x5c0, 0x23b, 0, 0, 0, 0, 1, lbl_805400D4);
            fn_8013CC50(S32(p, 0x3b4), p + 0x5c0, 0x23c, 0, 0, 0, 0, 1, lbl_805400D4);
            fn_8013CC50(S32(p, 0x3b4), p + 0x5c0, 0x23d, 0, 0, 0, 0, 1, lbl_80540134);
            fn_8013CC50(S32(p, 0x3b4), p + 0x5c0, 0x23e, 0, 0, 0, 0, 1, lbl_805400C8);
            fn_8013CC50(S32(p, 0x3b4), p + 0x5c0, 0x23f, 0, 0, 0, 0, 1, lbl_805400C8);
            u16 kind = fn_8022461C(p + 0x5c0, S32(p, 0x3b4));
            if (kind == 0x39 || kind == 0xd) {
                fn_8013CC50(S32(p, 0x3b4), p + 0x5c0, 0x3d0, 0, 0, 0, 0, 1, lbl_805400C8);
            } else {
                fn_8013CC50(S32(p, 0x3b4), p + 0x5c0, 0x3cf, 0, 0, 0, 0, 1, lbl_805400C8);
            }
            fn_802D79E8(fn_802D6A9C(), S32(p, 0x3b4), 0, lbl_805400E0, lbl_805400C4);
            fn_80134DE4(lbl_8053AAF8, 2, 0);
        } else {
            if (S32(p, 0x3b4) < 8) {
                fn_802F601C(*(void**)(lbl_8053AB10 + 0x20), (JGeometry::TVec3<f32>*)(p + 0x5c0), 1, 0, lbl_805400C8, scale);
            }
            fn_8024F0E8(p, 0x20024);
            fn_8013CC50(S32(p, 0x3b4), p + 0x5c0, 0x23d, 0, 0, 0, 0, 1, lbl_805400D4);
            fn_8013CC50(S32(p, 0x3b4), p + 0x5c0, 0x23e, 0, 0, 0, 0, 1, lbl_805400D4);
            fn_8013CC50(S32(p, 0x3b4), p + 0x5c0, 0x23f, 0, 0, 0, 0, 1, lbl_805400D4);
            u16 kind = fn_8022461C(p + 0x5c0, S32(p, 0x3b4));
            if (kind == 0x39 || kind == 0xd) {
                fn_8013CC50(S32(p, 0x3b4), p + 0x5c0, 0x3d0, 0, 0, 0, 0, 1, lbl_805400D4);
            } else {
                fn_8013CC50(S32(p, 0x3b4), p + 0x5c0, 0x3cf, 0, 0, 0, 0, 1, lbl_805400D4);
            }
            fn_80134DE4(lbl_8053AAF8, 1, 0);
        }
    }
    if (U8(p, 0xb9b) == 1) {
        if (U8(p, 0x3fa) == 0x12) {
            U8(p, 0xb9a) = 1;
        } else if (U8(p, 0x3fa) == 0x14) {
            U8(p, 0xb9a) = 0;
        }
    }
    fn_80268B3C(p);
    if (S32(p, 0x40c) < 0x1e) {
        S32(p, 0x40c) = S32(p, 0x40c) + 1;
    } else {
        u8* q = *(u8**)(lbl_8053AB10 + 0x24);
        if (U8(q, 0x7f4) == 0) {
            U8(q, 0x7f5) = 1;
        }
    }
}
#pragma pool_data reset
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

struct PlayerPcdmPosition {
    u8 pad[0xb0c];
    s32 ids[3];
    u8 padB18[0xb4c - 0xb18];
    s32 rooms[3];
    u8 padB58[0x12fc - 0xb58];
    JGeometry::TVec3<f32> pos;
};

struct PlayerPcdmParam {
    u32 left;
    u32 right;
};
extern const PlayerPcdmParam lbl_8046B070[];

extern "C" void fn_8025BEB0(u8* p) {
    s32 spread;
    s32 i;
    PlayerPcdmPosition* arrow = (PlayerPcdmPosition*)p;
    s32 actorID;
    u8 state = U8(p, 0x3fa);
    if (state < 3) {
        U8(p, 0x3fa) = state + 1;
        U8(p, 0x3fb) = 0;
    } else if (state < 6) {
        U8(p, 0x3fa) = state + 1;
        U8(p, 0x3fb) = 1;
    } else if (state == 6) {
        if (U8(p, 0x3fc) < 0x30) {
            U8(p, 0x3fc) += 1;
            if (U8(p, 0x3fc) == 0x30) {
                s32 idx = S32(p, 0x3dc);
                const f32* src = &lbl_8046B040[idx].x;
                f32 x = *src++;
                f32 y = *src++;
                arrow->pos.x = x;
                f32 z = *src;
                arrow->pos.y = y;
                arrow->pos.z = z;
                arrow->pos += V3(p, 0x8);
                if (!PTR(p, 0x12cc) && S32(p, 0x3b4) < 8) {
                    F32(p,0x12d4) = arrow->pos.x;
                    F32(p,0x12d8) = arrow->pos.y;
                    F32(p,0x12dc) = arrow->pos.z;
                    PTR(p, 0x12cc) = fn_8013CC50(S32(p, 0x3b4), &arrow->pos, 0xcb, 0, -1, 0, p + 0x12d0, 1, lbl_805400D4);
                    if (PTR(p, 0x12cc)) {
                        U32(PTR(p, 0x12cc), 0xf4) |= 0x40;
                    }
                }
                if (!PTR(p, 0x12e4) && S32(p, 0x3b4) < 8) {
                    F32(p,0x12ec) = arrow->pos.x;
                    F32(p,0x12f0) = arrow->pos.y;
                    F32(p,0x12f4) = arrow->pos.z;
                    PTR(p, 0x12e4) = fn_8013CC50(S32(p, 0x3b4), &arrow->pos, 0xcc, 0, -1, 0, p + 0x12e8, 1, lbl_805400D4);
                    if (PTR(p, 0x12e4)) {
                        U32(PTR(p, 0x12e4), 0xf4) |= 0x40;
                    }
                }
                if (S32(p, 0x12c0) < 0) {
                    S32(p, 0x12c0) = Actor_CreateByID(fn_801F856C(), 0x50454646, S32(p, 0x3b4), &arrow->pos, (U32(p, 0x4) & 3) | 8, -1, -1);
                }
                fn_8024F0E8(p, 0x2000d);
            }
        } else {
            s32 idx = S32(p, 0x3dc);
            const f32* src = &lbl_8046B040[idx].x;
            f32 x = *src++;
            f32 y = *src++;
            arrow->pos.x = x;
            f32 z = *src;
            arrow->pos.y = y;
            arrow->pos.z = z;
            arrow->pos += V3(p, 0x8);
            if (PTR(p, 0x12cc)) {
                F32(p,0x12d4) = arrow->pos.x;
                F32(p,0x12d8) = arrow->pos.y;
                F32(p,0x12dc) = arrow->pos.z;
            }
            if (PTR(p, 0x12e4)) {
                F32(p,0x12ec) = arrow->pos.x;
                F32(p,0x12f0) = arrow->pos.y;
                F32(p,0x12f4) = arrow->pos.z;
            }
            i = S32(p, 0x12c0);
            if (i >= 0) {
                u8* actor = fn_801F666C(fn_801F856C(), i);
                if (actor) {
                    V3(actor, 0xc) = arrow->pos;
                } else {
                    S32(p, 0x12c0) = -1;
                }
            }
        }
        if (!(playerVelocitySquared(V3(p, 0x344)) <= lbl_805400D8 * *(f32*)__float_epsilon) || F32(p, 0x10) > 0.0f) {
            V3(p, 8) += V3(p, 0x344);
            F32(p, 0x34c) -= lbl_80540104;
            if (F32(p, 0x10) <= 0.0f) {
                F32(p, 0x10) = 0.0f;
                V3(p, 0x368).set(F32(p, 0x344), F32(p, 0x348), 0.0f);
                V3(p, 0x344).set(0.0f, 0.0f, 0.0f);
                U8(p, 0x43d) = 3;
            }
        } else if (U8(p, 0x43d)) {
            --U8(p, 0x43d);
        } else if (fn_8022C274(U32(p, 4))) {
            if (fn_80246B10(p, 0x20)) {
                if (fn_80246F28(p) == 0.0f && U8(PTR(p, 0xbf0), 0xb7)) {
                    F32(p, 0x344) = F32(p, 0x368);
                    F32(p, 0x348) = F32(p, 0x36c);
                } else {
                    F32(p, 0x344) += lbl_80540140 * fn_80247330(p);
                    F32(p, 0x348) += lbl_80540140 * -fn_8024712C(p);
                }
                F32(p, 0x34c) = lbl_80540144;
                fn_8024F0E8(p, 0x10002);
            } else {
                fn_802808E8(p, lbl_80540124);
            }
            bool same = playerNearXY(V2(p,8), V2(p,0x14), lbl_805400D8 * *(f32*)__float_epsilon);
            if (same) {
                U8(p, 0x3f8) = 0;
            } else {
                ++U8(p, 0x3f8);
                if (U8(p, 0x3f8) >= 14) U8(p, 0x3f8) = 0;
            }
            if (U8(p, 0x3f8) < 4) U8(p, 0x3f9) = 0;
            else if (U8(p, 0x3f8) < 8) U8(p, 0x3f9) = 1;
            else if (U8(p, 0x3f8) < 10) U8(p, 0x3f9) = 0;
            else U8(p, 0x3f9) = 2;
        } else {
            spread = 1;
            ++U8(p, 0x3fa);
            if (fn_802415CC(p) >= 2 && U8(p, 0x3fc) >= 0x30) {
                for (i = 0; i < 3; i++) {
                    if (arrow->ids[i] >= 0) {
                        spread = 0;
                        break;
                    }
                }
            } else {
                spread = 0;
            }
            for (i = 0; i < 3; ++i) {
                if (arrow->ids[i] >= 0) {
                    continue;
                }
                JGeometry::TVec3<f32> pos = V3(p, 8);
                switch (S32(p, 0x3dc)) {
                case 0: pos.y -= lbl_805400E0; break;
                case 1: pos.y -= lbl_805400E0; break;
                case 2: break;
                case 3: pos.x -= lbl_805400C8; break;
                }
                if (U8(p, 0x3fc) >= 0x30) {
                    actorID = S32(p,4);
                    arrow->ids[i] = Actor_CreateByID(fn_801F856C(), 'PCDM', S32(p,0x3b4), &pos, ((U32(p,0x3dc) << 4) & 0x30) | ((u32)actorID & 3), -1, actorID);
                } else {
                    actorID = S32(p,4);
                    arrow->ids[i] = Actor_CreateByID(fn_801F856C(), 'PCDM', S32(p,0x3b4), &pos, ((S32(p,0x3dc)&3)<<4) | 0x100 | (actorID&3), -1, actorID);
                }
                if (arrow->ids[i] >= 0) {
                    arrow->rooms[i] = S32(p,0x3b4);
                    fn_8024F0E8(p, 0x20004);
                }
                if ((u8)spread == 1) {
                    if (arrow->ids[1] < 0) {
                        actorID = S32(p,4);
                        i = ((lbl_8046B070[S32(p,0x3dc)].left & 7) << 4) | (actorID & 3);
                        arrow->ids[1] = Actor_CreateByID(fn_801F856C(), 'PCDM', S32(p,0x3b4), &pos, i, -1, actorID);
                        if (arrow->ids[1] >= 0) {
                            arrow->rooms[1] = S32(p,0x3b4);
                        }
                    }
                    if (arrow->ids[2] < 0) {
                        actorID = S32(p,4);
                        arrow->ids[2] = Actor_CreateByID(fn_801F856C(), 'PCDM', S32(p,0x3b4), &pos, ((lbl_8046B070[S32(p,0x3dc)].right & 7) << 4) | (actorID & 3), -1, actorID);
                        if (arrow->ids[2] >= 0) {
                            arrow->rooms[2] = S32(p,0x3b4);
                        }
                    }
                }
                U8(p,0x3fc) = 0;
                break;
            }
        }
        U8(p, 0x3fb) = 1;
    } else if (state < 10) {
        U8(p, 0x3fa) = state + 1;
        U8(p, 0x3fb) = 2;
    } else {
        U8(p, 0x3fa) = state + 1;
        U8(p, 0x3fb) = 3;
    }
    if (U8(p, 0x3fa) >= 14) {
        if (fn_8022C274(U32(p, 4))) {
            U8(p, 0x3fa) = 0;
            U8(p, 0x3fb) = 0;
        } else {
            fn_80251AEC(p, 0);
        }
    }
    fn_80268B3C(p);
    if (S32(p, 0x40c) < 0x1e) {
        S32(p, 0x40c) = S32(p, 0x40c) + 1;
    } else if (U8(PTR(lbl_8053AB10,0x24),0x7f4) == 0) {
        U8(PTR(lbl_8053AB10,0x24),0x7f5) = 1;
    }
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
    s32 actorID;
    PlayerArrowPosition* arrow = (PlayerArrowPosition*)p;
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
                const f32* src = &lbl_8046B010[idx].x;
                f32 x = *src++;
                f32 y = *src++;
                arrow->pos.x = x;
                f32 z = *src;
                arrow->pos.y = y;
                arrow->pos.z = z;
                arrow->pos += V3(p, 0x8);
                if (!PTR(p, 0x12cc)) {
                    F32(p,0x12d4) = arrow->pos.x;
                    F32(p,0x12d8) = arrow->pos.y;
                    F32(p,0x12dc) = arrow->pos.z;
                    PTR(p, 0x12cc) = fn_8013CC50(S32(p, 0x3b4), &arrow->pos, 0xcb, 0, -1, 0, p + 0x12d0, 1, lbl_805400D4);
                    if (PTR(p, 0x12cc)) {
                        U32(PTR(p, 0x12cc), 0xf4) |= 0x40;
                    }
                }
                if (!PTR(p, 0x12e4)) {
                    F32(p,0x12ec) = arrow->pos.x;
                    F32(p,0x12f0) = arrow->pos.y;
                    F32(p,0x12f4) = arrow->pos.z;
                    PTR(p, 0x12e4) = fn_8013CC50(S32(p, 0x3b4), &arrow->pos, 0xcc, 0, -1, 0, p + 0x12e8, 1, lbl_805400D4);
                    if (PTR(p, 0x12e4)) {
                        U32(PTR(p, 0x12e4), 0xf4) |= 0x40;
                    }
                }
                if (S32(p, 0x12c0) < 0) {
                    S32(p, 0x12c0) = Actor_CreateByID(fn_801F856C(), 0x50454646, S32(p, 0x3b4), &arrow->pos, (U32(p, 0x4) & 3) | 8, -1, -1);
                }
                fn_8024F0E8(p, 0x2000d);
            }
        } else {
            s32 idx = S32(p, 0x3dc);
            const f32* src = &lbl_8046B010[idx].x;
                f32 x = *src++;
                f32 y = *src++;
                arrow->pos.x = x;
                f32 z = *src;
                arrow->pos.y = y;
                arrow->pos.z = z;
            arrow->pos += V3(p, 0x8);
            if (PTR(p, 0x12cc)) {
                F32(p,0x12d4) = arrow->pos.x;
                    F32(p,0x12d8) = arrow->pos.y;
                    F32(p,0x12dc) = arrow->pos.z;
            }
            if (PTR(p, 0x12e4)) {
                F32(p,0x12ec) = arrow->pos.x;
                    F32(p,0x12f0) = arrow->pos.y;
                    F32(p,0x12f4) = arrow->pos.z;
            }
            actorID = S32(p, 0x12c0);
            if (actorID >= 0) {
                u8* actor = fn_801F666C(fn_801F856C(), actorID);
                if (actor) {
                    V3(actor, 0xc) = arrow->pos;
                }
            }
        }
        if (!(playerVelocitySquared(V3(p, 0x344)) <= lbl_805400D8 * *(f32*)__float_epsilon) || F32(p, 0x10) > 0.0f) {
            V3(p, 8) += V3(p, 0x344);
            F32(p, 0x34c) -= lbl_80540104;
            if (F32(p, 0x10) <= 0.0f) {
                F32(p, 0x10) = 0.0f;
                V3(p, 0x368).set(F32(p, 0x344), F32(p, 0x348), 0.0f);
                V3(p, 0x344).set(0.0f, 0.0f, 0.0f);
                U8(p, 0x43d) = 3;
            }
        } else if (U8(p, 0x43d)) {
            --U8(p, 0x43d);
        } else if (fn_8022C274(U32(p, 4))) {
            if (fn_80246B10(p, 0x20)) {
                if (fn_80246F28(p) == 0.0f && U8(PTR(p, 0xbf0), 0xb7)) {
                    F32(p, 0x344) = F32(p, 0x368);
                    F32(p, 0x348) = F32(p, 0x36c);
                } else {
                    F32(p, 0x344) += lbl_80540140 * fn_80247330(p);
                    F32(p, 0x348) += lbl_80540140 * -fn_8024712C(p);
                }
                F32(p, 0x34c) = lbl_80540144;
                fn_8024F0E8(p, 0x10002);
            } else {
                fn_802808E8(p, lbl_80540124);
            }
            bool same = playerNearXY(V2(p,8), V2(p,0x14), lbl_805400D8 * *(f32*)__float_epsilon);
            if (same) {
                U8(p, 0x3f8) = 0;
            } else {
                ++U8(p, 0x3f8);
                if (U8(p, 0x3f8) >= 14) U8(p, 0x3f8) = 0;
            }
            if (U8(p, 0x3f8) < 4) U8(p, 0x3f9) = 0;
            else if (U8(p, 0x3f8) < 8) U8(p, 0x3f9) = 1;
            else if (U8(p, 0x3f8) < 10) U8(p, 0x3f9) = 0;
            else U8(p, 0x3f9) = 2;
        } else {
            ++U8(p, 0x3fa);
            u8* slot = p;
            for (s32 i = 0; i < 3; ++i, slot += 4) {
                if (S32(slot, 0xb00) >= 0) {
                    if (fn_802415CC(p) >= 2) continue;
                    break;
                }
                JGeometry::TVec3<f32> pos = V3(p, 8);
                switch (S32(p, 0x3dc)) {
                case 0: pos.y -= lbl_805400E0; break;
                case 1: pos.y -= lbl_805400E0; break;
                case 2: break;
                case 3: pos.x -= lbl_805400C8; break;
                }
                if (U8(p, 0x3fc) >= 0x30) {
                    actorID = S32(p,4);
                    arrow->ids[i] = Actor_CreateByID(fn_801F856C(), 'ARRW', S32(p,0x3b4), &pos, ((U32(p,0x3dc) << 4) & 0x30) | ((u32)actorID & 3), -1, actorID);
                } else {
                    actorID = S32(p,4);
                    arrow->ids[i] = Actor_CreateByID(fn_801F856C(), 'ARRW', S32(p,0x3b4), &pos, ((S32(p,0x3dc)&3)<<4) | 0x100 | (actorID&3), -1, actorID);
                }
                if (arrow->ids[i] >= 0) {
                    arrow->rooms[i] = S32(p,0x3b4);
                    fn_8024F0E8(p, 0x20004);
                    if (((u8(*)(void))fn_8022B160)()) S32(p,0xb74) = 60;
                    else Player_IsLinked(p);
                }
                U8(p,0x3fc) = 0;
                break;
            }
        }
        U8(p, 0x3fb) = 1;
    } else if (state < 10) {
        U8(p, 0x3fa) = state + 1;
        U8(p, 0x3fb) = 2;
    } else {
        U8(p, 0x3fa) = state + 1;
        U8(p, 0x3fb) = 3;
    }
    if (U8(p, 0x3fa) >= 14) {
        if (S32(p, 0xb74) == 0 && fn_8022C274(U32(p, 4))) {
            U8(p, 0x3fa) = 0;
            U8(p, 0x3fb) = 0;
        } else {
            fn_80251AEC(p, 0);
        }
    }
    fn_80268B3C(p);
    S32(p, 0x40c) = S32(p, 0x40c) + 1;
    if (S32(p, 0x40c) < 0x1e) {
        S32(p, 0x40c) = S32(p, 0x40c) + 1;
    } else if (U8(PTR(lbl_8053AB10,0x24),0x7f4) == 0) {
        U8(PTR(lbl_8053AB10,0x24),0x7f5) = 1;
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
#pragma opt_propagation off
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
    f32 dz;
    f32 dx;
    f32 dy;
    dy = -F32(p, 0x348);
    dx = -F32(p, 0x344);
    dz = lbl_805400C4;
    direction.set(dx, dy, dz);
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
    const JGeometry::TVec3<f32>& pos = V3(p, 8) + offset;
    if (S32(p, 0x3b4) < 8) {
        fn_802F601C(*(void**)(lbl_8053AB10 + 0x20), const_cast<JGeometry::TVec3<f32>*>(&pos), 3, &direction, lbl_805400D4, lbl_805400D4);
    }
    U8(p, 0xb9c) = 1;
}
#pragma opt_propagation reset
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

extern "C" void fn_80276E5C(void*);
extern "C" void fn_802709C8(void*);
extern "C" s32 fn_8023A1A4(s32);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32);
extern "C" void fn_80248004(void*,s32,s32);
extern "C" u8 fn_80224B88(void*,s32);
extern "C" u8 fn_80224E88(void*,s32);
extern "C" void fn_802A20F0(void*,void*,s32,s32,s32,s32);
extern "C" u8 fn_8022E438(s32,s32);
extern "C" u8 fn_802350A0(s32);
#pragma opt_common_subs off
extern "C" void fn_8025DACC(u8* p) {
f32 maxX;
f32 maxY;
f32 minX;
f32 minY;
JGeometry::TVec3<f32> check;
JGeometry::TVec3<f32> scan;
JGeometry::TBox2<f32> bounds;
JGeometry::TVec3<f32> ahead;
JGeometry::TVec3<f32> direction;
JGeometry::TVec3<f32> offset;
JGeometry::TVec3<f32> attached;
const Tu80256Tables* table=(const Tu80256Tables*)lbl_8046AF00;
u16 tile;
fn_80276E5C(p);fn_802709C8(p);
s32 room0=S32(p,0x3b4);
if(((Tu80256RoomState*)fn_802D6A9C())->flags[room0]){
fn_8024B298(p,2,&check);check.y+=lbl_805400C8;tile=fn_8022461C(&check,S32(p,0x3b4));
}else{tile=fn_8022461C(p+8,S32(p,0x3b4));}
if(tile==0x39){if(PTR(p,0x1368)==0){PTR(p,0x1368)=fn_8013CC50(S32(p,0x3b4),p+8,0x3d4,0,-1,(s32)(p+0x13a8),0,1,lbl_805400D4);}else{fn_8013CB44(PTR(p,0x1368),p+8,0,-1,1);}{u8* effect=PTR(p,0x1360);if(effect){U32(effect,0xf4)|=1;S32(effect,0x24)=1;PTR(p,0x1360)=0;}}{u8* effect=PTR(p,0x1364);if(effect){U32(effect,0xf4)|=1;S32(effect,0x24)=1;PTR(p,0x1364)=0;}}
}else if(tile==2||tile==3){if(PTR(p,0x1360)==0){PTR(p,0x1360)=fn_8013CC50(S32(p,0x3b4),p+8,0x116,0,-1,(s32)(p+0x1398),0,1,lbl_805400D4);}else{fn_8013CB44(PTR(p,0x1360),p+8,0,-1,1);}{u8* effect=PTR(p,0x1364);if(effect){U32(effect,0xf4)|=1;S32(effect,0x24)=1;PTR(p,0x1364)=0;}}{u8* effect=PTR(p,0x1368);if(effect){U32(effect,0xf4)|=1;S32(effect,0x24)=1;PTR(p,0x1368)=0;}}
}else{if(PTR(p,0x1360)==0){PTR(p,0x1360)=fn_8013CC50(S32(p,0x3b4),p+8,0x116,0,-1,(s32)(p+0x1398),0,1,lbl_805400D4);}else{fn_8013CB44(PTR(p,0x1360),p+8,0,-1,1);}
if(fn_8026FC20(p)==2){{u8* effect=PTR(p,0x1364);if(effect){U32(effect,0xf4)|=1;S32(effect,0x24)=1;PTR(p,0x1364)=0;}}}else{if(PTR(p,0x1364)==0){PTR(p,0x1364)=fn_8013CC50(S32(p,0x3b4),p+8,0x115,0,-1,0,0,1,lbl_805400D4);}else{fn_8013CB44(PTR(p,0x1364),p+8,0,-1,1);}}
{u8* effect=PTR(p,0x1368);if(effect){U32(effect,0xf4)|=1;S32(effect,0x24)=1;PTR(p,0x1368)=0;}}}
if(fn_802415CC(p)>=2){
s32 room1=S32(p,0x3b4);
if(((Tu80256RoomState*)fn_802D6A9C())->flags[room1]==0){
if(Player_IsLinked(p)){
s32 value=fn_8023A1A4(Player_GetLinkTargetIndex(p));
if(value>0){
s32 counter=S32(p,0xbac);
if(counter==0&&U8(p,0xce8)==0){U8(p,0xce8)=1;S32(p,0xbac)=value;}
else if(counter>0){S32(p,0xbac)=value;}}
if(fn_8026FC20(p)==4&&S32(p,0xba8)==0){
S32(p,0xba8)=1;
JGeometry::TVec3<f32>* v=fn_8023E724(Player_GetLinkTargetIndex(p));
F32(p,8)=v->x;F32(p,0xc)=v->y;F32(p,0x10)=v->z;
}
}else{
if((U8(lbl_8053AAF8,0x82)&(u8)(1<<S32(p,4)))&&U8(PTR(p,0xbf0),0xb8)){
if(U8(p,0xce8)==0&&S32(p,0xbac)==0){
scan=V3(p,8);
bool found=0;
s32 id=S32(p,0x3b4);u8* mgr=(u8*)fn_802D6A9C();
JGeometry::TBox2<f32>* box;if(id<8)box=(JGeometry::TBox2<f32>*)(mgr+0xcc);else box=(JGeometry::TBox2<f32>*)(mgr+0xdc);bounds=*box;
bounds.i.x-=lbl_8054012C;bounds.i.y-=lbl_8054012C;bounds.f.x+=lbl_8054012C;bounds.f.y+=lbl_8054012C;minX=bounds.i.x;minY=bounds.i.y;maxX=bounds.f.x;maxY=bounds.f.y;
while(1){
switch(S32(p,0x3dc)){
case 0:scan.x+=lbl_805400DC;if((u16)fn_8022461C(&scan,S32(p,0x3b4))==0x12)found=1;break;
case 1:scan.x-=lbl_805400DC;if((u16)fn_8022461C(&scan,S32(p,0x3b4))==0x13)found=1;break;
case 2:scan.y+=lbl_805400DC;if((u16)fn_8022461C(&scan,S32(p,0x3b4))==0x10)found=1;break;
case 3:scan.y-=lbl_805400DC;if((u16)fn_8022461C(&scan,S32(p,0x3b4))==0x11)found=1;break;
}
if(found)break;
bool inside=0;
if(scan.x>=minX&&scan.y>=minY&&scan.x<maxX&&scan.y<maxY)inside=1;
if(!inside)break;
}
if(found){U8(p,0xce8)=1;fn_80248004(p,5,1);S32(p,0xbac)++;}
}else if(S32(p,0xbac)==2){
ahead=V3(p,8);bool found=0;
switch(S32(p,0x3dc)){
case 0:ahead.x+=lbl_805400DC;if((u16)fn_8022461C(&ahead,S32(p,0x3b4))==0x12)found=1;break;
case 1:ahead.x-=lbl_805400DC;if((u16)fn_8022461C(&ahead,S32(p,0x3b4))==0x13)found=1;break;
case 2:ahead.y+=lbl_805400DC;if((u16)fn_8022461C(&ahead,S32(p,0x3b4))==0x10)found=1;break;
case 3:ahead.y-=lbl_805400DC;if((u16)fn_8022461C(&ahead,S32(p,0x3b4))==0x11)found=1;break;
}
if(found)S32(p,0xbac)++;
}
}else{
s32 count=S32(p,0xbac);
if(count==1){S32(p,0xbac)=count+1;}
else if(count==3){S32(p,0xbac)=count+1;S32(p,0xba8)=1;U8(p,0xce8)=0;}
}
}
}
}
fn_8024BAEC(p);
if(U8(p,0x3fa)<10){
if(tile==0x39||tile==0xd){fn_8024F0E8(p,0x2005a);}else if(fn_80224B88(p+8,S32(p,0x3b4))){fn_8024F0E8(p,0x2005b);}else if(fn_80224E88(p+8,S32(p,0x3b4))){fn_8024F0E8(p,0x2005e);}else{fn_8024F0E8(p,0x20030);}
U8(p,0x3fa)++;U8(p,0x3fb)=0;U8(p,0x3f8)++;
if(U8(p,0x3f8)>=16)U8(p,0x3f8)=0;
U8(p,0x3f9)=(u32)U8(p,0x3f8)>>1;
if(!fn_8022C274(U32(p,4)))fn_80251AEC(p,0);
}else{
s32 timer=S32(p,0xba8);
if(timer<=0){if(S32(p,0xbac)==0&&!fn_8022C274(U32(p,4)))S32(p,0xba8)=1;}
else{S32(p,0xba8)=timer-1;if(S32(p,0xba8)==0)fn_80251AEC(p,0);}
u16 terrain=fn_8022461C(p+8,S32(p,0x3b4));
if(terrain==0x39||terrain==0xd){fn_8024F0E8(p,0x20052);}else if(fn_80224B88(p+8,S32(p,0x3b4))){fn_8024F0E8(p,0x20058);}else if(fn_80224E88(p+8,S32(p,0x3b4))){fn_8024F0E8(p,0x2005d);}else{fn_8024F0E8(p,0x20051);}
U8(p,0x3fb)=1;U8(p,0x3f8)++;if(U8(p,0x3f8)>=16)U8(p,0x3f8)=0;
U8(p,0x3f9)=table->frames[S32(p,0x3dc)][(u32)U8(p,0x3f8)>>1];
fn_8025D0B0(p);
direction=V3(p,8)-V3(p,0x14);
direction.normalize();
const JGeometry::TVec3<f32>* it=table->ring;
for(s32 i=0;i<8;i++,it++){
offset.set(*it);
const JGeometry::TVec3<f32>& pos=V3(p,8)+offset;
fn_802A20F0(lbl_8053AC98,(void*)&pos,S32(p,4),S32(p,0x3b4),0,1);
}
}
fn_80268B3C(p);
if(U8(p,0x3fa)>=10){
s32 room2=S32(p,0x3b4);
if(((Tu80256RoomState*)fn_802D6A9C())->flags[room2]||U8(PTR(p,0xbf0),0xb8)==0){
if(S32(p,0x3dc)==0){if(U8(PTR(p,0xbf0),0x48))fn_80251AEC(p,0x41);}
else if(S32(p,0x3dc)==1){if(U8(PTR(p,0xbf0),0x49))fn_80251AEC(p,0x41);}
else if(S32(p,0x3dc)==2){if(U8(PTR(p,0xbf0),0x4a))fn_80251AEC(p,0x41);}
else if(S32(p,0x3dc)==3){if(U8(PTR(p,0xbf0),0x4b))fn_80251AEC(p,0x41);}
}
}
for(s32 i=0;i<4;i++){if(fn_8022E438(S32(p,4),i)&&fn_802350A0(i))fn_80251AEC(p,0x41);}
if(Player_IsLinked(p)&&fn_802350A0(Player_GetLinkTargetIndex(p)))fn_80251AEC(p,0x41);
u8* actor=fn_801F666C(fn_801F856C(),S32(p,0xbb4));
if(actor){attached.set(table->attached[S32(p,0x3dc)]);attached.add(V3(p,8));V3(actor,0xc)=attached;}
}
#pragma opt_common_subs reset
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


