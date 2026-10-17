// TU 0x802684a4-0x8026fc20.
// SetField_0x98 from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dl__FPv(void*);
extern "C" s32 fn_802486A0(void*);
extern "C" bool Player_IsLinked(void*);
extern "C" void fn_802685D4(void*);
extern "C" u8 fn_80251AEC(void*, s32);
extern f32 lbl_80540228;
extern "C" s32 fn_8024FF84();
extern "C" u16 fn_8022461C(JGeometry::TVec3<f32>*, s32);
extern "C" void* fn_801F856C();
extern "C" void* Actor_CreateByID(void*, u32, s32, JGeometry::TVec3<f32>*, s32, s32, s32);
extern "C" void* fn_801F666C(void*, void*);
extern JGeometry::TVec3<f32> lbl_8046B998[];
extern void* lbl_804A71A8[];

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
    u8 pad0[0x5fc];
    HitRect rects[80];
    u8 padAFC[0xdb0 - 0xafc];
    s32 ids[80];
    s32 hits[80];
    s32 types[80];
};


inline bool rectContains(const HitRect& r, const Vec2f* p) {
    bool in = false;
    if (p->x >= r.x0 && p->y >= r.y0 && p->x < r.x1 && p->y < r.y1) {
        in = true;
    }
    return in;
}

extern "C" s32 fn_802684A4(HitRectTable* t, const Vec2f* p, s32 type) {
    for (s32 i = 0; i < 80; i++) {
        if (t->ids[i] >= 0 && type == t->types[i] && rectContains(t->rects[i], p)) {
            t->hits[i] = t->ids[i];
            return 1;
        }
    }
    return 0;
}

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

extern "C" {

void SetField_0x98(void* thisPtr) {
	*(u8*)((char*)thisPtr + 0x98) = 1;
}

}


extern JGeometry::TVec3<f32> lbl_8046BA88[];
extern Vec2f lbl_8046BA68[];
extern "C" s32 fn_80248778(void*);

extern "C" u8* fn_802D6A9C();

struct Obj8026942C {
    void* vtbl;
    u8* player;
};

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

extern "C" void fn_8026E464(u8* p) {
    s32 i;
    s32 j;
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

extern "C" u8 fn_8026E5F8(u8* p, Vec2f* pos) {
    if (!p[0xd64]) {
        if (fn_80251AEC(p, 0x38)) {
            ((JGeometry::TVec2<f32>*)(p + 0x324))->set(pos->x, pos->y);
            return 1;
        }
    } else {
        if (fn_80251AEC(p, 0x13)) {
            ((JGeometry::TVec2<f32>*)(p + 0x324))->set(pos->x, pos->y);
            return 1;
        }
    }
    return 0;
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

extern "C" void fn_8026F388(u8* p) {
    if (*(s32*)(*(u8**)(p + 4) + 0x3dc) == 2) {
        *(s32*)(p + 0xac) = 1;
        if (fn_80250D30(*(void**)(p + 4)) && *(s32*)(*(u8**)(p + 4) + 0x3dc) == *(s32*)(p + 0x1c) && fn_8024FF84() < 0) {
            JGeometry::TVec3<f32> v = *(JGeometry::TVec3<f32>*)(p + 8);
            JGeometry::TVec3<f32> off = lbl_8046B998[*(s32*)(*(u8**)(p + 4) + 0x3dc)];
            v.add(off);
            bool ok;
            u16 t = fn_8022461C(&v, *(s32*)(*(u8**)(p + 4) + 0x3b4));
            if (t == 0) {
                ok = false;
            } else if (t == 2) {
                ok = false;
            } else if (t == 0x50) {
                ok = true;
            } else {
                ok = false;
            }
            if (ok) {
                JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(p + 8);
                pos.z = lbl_80540228;
                u8* pl = *(u8**)(p + 4);
                s32 dir = *(s32*)(pl + 0x3dc);
                void* actor = Actor_CreateByID(fn_801F856C(), 0x424c434b, *(s32*)(pl + 0x3b4), &pos, (dir & 3) << 2, -1, -1);
                if ((u16)fn_8022461C(&pos, *(s32*)(*(u8**)(p + 4) + 0x3b4)) != 0x50) {
                    if (fn_801F666C(fn_801F856C(), actor)) {
                        *(void**)(*(u8**)(p + 4) + 0xd94) = actor;
                    }
                }
                return;
            }
        }
        p[*(s32*)(p + 0x1c) + 0x38] = 1;
    } else {
        p[*(s32*)(p + 0x1c) + 0x38] = 1;
    }
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
