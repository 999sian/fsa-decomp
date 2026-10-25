#include "types.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" char __vt__4HOUS[];
extern "C" void fn_801EE434(s32);
extern "C" void __dt__5ActorFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" u8 fn_8023F264(s32 i);
extern "C" u8 fn_8022F514(s32 a);
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
extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* a, s32 room, void* v, void* h, s32 c);
extern "C" u8 fn_802A1490(void* g, void* v);
extern "C" u8 fn_8023B0F4(s32 idx, void* box, s32 room, s32 a, f32 f);
extern "C" JGeometry::TVec3f lbl_8046C268[];
extern "C" f32 lbl_8046C298[];

// Whether pos hits a collision rect of the current list (excluding this actor's own handle).
static inline u8 HitsRect(char* self, void* pos) {
    s32 room;
    void* h = *(void**)(self + 0x198);
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
    };
    char* self = (char*)p;
    u8 ok = 1;
    s32 i;
    s32 room;
    char* m;
    JGeometry::TBox2f* src;
    JGeometry::TVec3f* v;
    JGeometry::TVec3f save(*(JGeometry::TVec3f*)(self + 0xc));
    Probe pt;
    JGeometry::TBox2f box;
    JGeometry::TVec3f q;
    JGeometry::TVec3f ofs;

    ((JGeometry::TVec3f*)(self + 0x3c))->x = lbl_8046C268[mode].x;
    ((JGeometry::TVec3f*)(self + 0x3c))->y = lbl_8046C268[mode].y;
    ((JGeometry::TVec3f*)(self + 0x3c))->z = lbl_8046C268[mode].z;
    *(JGeometry::TVec3f*)(self + 0xc) += *(JGeometry::TVec3f*)(self + 0x3c);
    *(f32*)(self + 0x60) = -44.0f;
    *(f32*)(self + 0x64) = -44.0f;
    *(f32*)(self + 0x68) = 44.0f;
    *(f32*)(self + 0x6c) = 44.0f;

    room = *(s32*)(self + 4);
    m = (char*)fn_802D6A9C();
    src = (JGeometry::TBox2f*)(room < 8 ? m + 0xcc : m + 0xdc);
    pt.area = *src;
    pt.area.i.x -= -32.0f;
    pt.area.i.y -= -32.0f;
    pt.area.f.x += -32.0f;

    pt.pos = *(JGeometry::TVec3f*)(self + 0xc);
    pt.pos.z = 0.0f;

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
        for (i = 0; i < 6; i++) {
            if (!fn_802A1490(lbl_8053AC98, &pt) || HitsRect(self, &pt) == 1) {
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
        for (i = 0; i < 6; i++) {
            if (!fn_802A1490(lbl_8053AC98, &pt) || HitsRect(self, &pt) == 1) {
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
            if (fn_8023B0F4(i, &box, *(s32*)(self + 4), 0, 0.0f)) {
                v = (JGeometry::TVec3f*)fn_8023E724(i);
                ofs.set(((JGeometry::TVec3f*)lbl_8046C298)[mode].x, ((JGeometry::TVec3f*)lbl_8046C298)[mode].y,
                        ((JGeometry::TVec3f*)lbl_8046C298)[mode].z);
                q = *v;
                q += ofs;
                if (fn_802A1490(lbl_8053AC98, &q) != 1 || HitsRect(self, &q)) {
                    ok = 0;
                }
            }
        }
    }

    *(JGeometry::TVec3f*)(self + 0xc) = save;
    *(f32*)(self + 0x3c) = 0.0f;
    *(f32*)(self + 0x40) = 0.0f;
    *(f32*)(self + 0x44) = 0.0f;
    *(f32*)(self + 0x60) = -48.0f;
    *(f32*)(self + 0x64) = -48.0f;
    *(f32*)(self + 0x68) = 48.0f;
    *(f32*)(self + 0x6c) = 48.0f;
    return ok;
}

extern "C" void fn_80295C40(void* p) {
    s32 i;
    s32 n;
    char* pc;
    char* q;
    void* obj;
    s32 k;

    for (i = 0; i < 4; i++) {
        if (fn_8023F264(i) != 0 && fn_8022F514(i) == 0) {
            n = (*(u32*)((char*)p + 0x90) >> 7) & 0x1f;
            n = (n + 7) & ~-(n == 0);
            if (n == fn_8023DE58(i)) {
                n = *(s32*)((char*)p + 4);
                if (fn_802317F0(i, n, fn_8023E724(i), (char*)p + 0xc, 0x1f) != 0) {
                    *((char*)p + (i + 0x2bc)) = 1;
                } else {
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
    for (k = 0; k < 2; k++) {
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
    }

    q = (char*)p;
    for (i = 0; i < *(s32*)((char*)p + 0x2a4); i++) {
        obj = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x27c));
        if (obj != 0) {
            *(u8*)((char*)obj + 0x11c) = 0;
        }
        q += 4;
    }

    *(u8*)((char*)p + 0x2bb) = 1;
}

extern "C" void fn_80295EE8(void* this_) {
    extern void fn_8013CB44(void* a, s32 b, s32 c, s32 d, f32 e, f32 f, f32 g);
    extern void fn_8023DE58(s32 a);
    extern s32 fn_80235274(s32 a);
    extern void fn_8023E724(s32 a);
    extern void fn_80238548(s32 a, s32 b, s32 c, s32 d);

    char* self = (char*)this_;
    s32 i;
    s32 j;
    s32 n;

    if (*(s32*)(self + 0x2c4) > 0) {
        if (*(s32*)(self + 0x2c8) - *(s32*)(self + 0x2c4) < 0x3c) {
        }
    }
}

extern "C" s32 fn_801F2718(void* p, u32 id);
extern "C" void fn_802A381C(void* mgr, void* v, s32 a, s32 b);
extern "C" void fn_802961AC(void* p) {
    char* self = (char*)p;
    char* other;
    s32 i;
    char* row;
    char* col;
    JGeometry::TVec3f* dir;
    JGeometry::TVec3f v;
    JGeometry::TVec3f gridBase;
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
    if (other != 0) {
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

            for (j = 0, col = self; j < *(s32*)(self + 0x2a0); j++, col += 4) {
                other = (char*)fn_801F666C(fn_801F856C(), *(s32*)(col + 0x26c));
                if (other != 0) {
                    *(u8*)(other + 0x11c) = 0;
                }
            }
            for (j = 0, col = self; j < *(s32*)(self + 0x29c); j++, col += 4) {
                other = (char*)fn_801F666C(fn_801F856C(), *(s32*)(col + 0x25c));
                if (other != 0) {
                    *(u8*)(other + 0x11c) = 0;
                }
            }

            *(u8*)(self + 0x24c) = 0;
            if (*(u8*)(self + 0x24c) == 0) {
                *(u8*)(self + 0x24c) = 1;
                gridBase = *(JGeometry::TVec3f*)(self + 0xc);
                gridBase.x += *(f32*)(self + 0x60);
                gridBase.y += *(f32*)(self + 0x64);
                gridBase.x += 8.0f;
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
            *(s32*)(self + 0x2c4) = 120;
            *(s32*)(self + 0x2c8) = 120;
            *(u8*)(self + 0x2ba) = 1;
        }
    }
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern "C" void fn_80239914(void*, s32, void*);
extern "C" void fn_80298978(void* p) {
    s32 i;
    s32 j;
    s32 flag;
    s32 mode;
    u32 key;
    u8 ret;
    void* obj;
    JGeometry::TVec3f pos;
    JGeometry::TVec2f* center;
    JGeometry::TBox2f box;
    JGeometry::TVec3f* v;
    f32 lenSq;

    for (i = 0; i < *(s32*)((char*)p + 0x29c); i++) {
        obj = fn_801F666C(fn_801F856C(), *(s32*)((char*)p + 0x25c + i * 4));
        flag = 0;
        if (obj != 0) {
            v = (JGeometry::TVec3f*)((char*)p + 0x250);
            lenSq = v->squared();
            if (lenSq > 32.0f * FLT_EPSILON) {
                flag = 1;
            } else {
                for (j = 0; j < 4; j++) {
                    pos = *(JGeometry::TVec3f*)((char*)obj + 0x238);
                    pos.x = pos.x + (8.0f * (f32)((j & 1) != 0) - 4.0f);
                    pos.y = pos.y + (8.0f * (f32)((j & 2) != 0) - 4.0f);
                    key = *(u32*)((char*)obj + 0x90) & 0x7f;
                    switch (key) {
                    case 3:
                        pos.y = pos.y - 16.0f;
                        break;
                    case 1:
                    case 2:
                        pos.y = pos.y + 16.0f;
                        break;
                    case 0x17:
                        pos.x = pos.x + 16.0f;
                        break;
                    case 0x18:
                        pos.x = pos.x - 16.0f;
                        break;
                    }
                    mode = (*(u32*)((char*)obj + 0x90) >> 5) & 7;
                    mode = mode ? mode + 7 : 0;
                    ret = (*(u8 (**)(void*, s32, void*))(*(char**)p + 0x4c))(p, mode, &pos);
                    if ((ret & 0xff) == 1) {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1) {
                center = (JGeometry::TVec2f*)((char*)p + 0x2dc) + i;
                box.set(-10.0f, -10.0f, 10.0f, 10.0f);
                box.addPos(*center);
                mode = (*(u32*)((char*)p + 0x90) >> 7) & 0x1f;
                mode = mode ? mode + 7 : 0;
                fn_80239914(&box, mode, *(void**)((char*)p + 0x198));
            }
        }
    }
}

extern "C" void fn_80298C18(void* p) {
    char* self = (char*)p;
    char* q;
    s32 i;
    s32 n;
    s32 k;
    s32 idx;
    void* m;
    void* obj;
    f32 lenSq;
    JGeometry::TVec3f v;
    JGeometry::TVec3f v2;
    JGeometry::TVec3f vec;
    JGeometry::TVec3f* vel;

    if (*(f32*)(self + 0x250) > 0.0f) {
        *(s32*)(self + 0x248) += 1;
        n = (*(u32*)(self + 0x90) >> 7) & 0x1f;
        n = (n + 7) & ~-(n == 0);
        m = fn_802D6A9C();
        fn_802D79E8(m, n, 1.0f, 0.0f, 1);
        if (*(f32*)(self + 0x250) > 0.32f) {
            *(f32*)(self + 0xc) += 0.32f;
            *(f32*)(self + 0x250) -= 0.32f;
        } else {
            *(f32*)(self + 0xc) += *(f32*)(self + 0x250);
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
        }

        v = *(JGeometry::TVec3f*)(self + 0xc);
        v.x += *(f32*)(self + 0x68);
        v.x -= 2.0f;
        v.y += *(f32*)(self + 0x64);
        v.y += 8.0f;
        v.z = 0.0f;
        for (i = 0; i < 6; i++) {
            fn_802A20F0(lbl_8053AC98, &v, -1, *(s32*)(self + 4), 0, 1);
            fn_802A1050(lbl_8053AC98, &v);
            v.y += 16.0f;
        }

        v2 = *(JGeometry::TVec3f*)(self + 0xc);
        idx = 0;
        if (*(s32*)(self + 0x2a4) > 0 && *(s32*)(self + 0x2cc) == -1) {
            idx = 1;
        }
        v2 += *(JGeometry::TVec3f*)(lbl_8046C238 + idx * 3);
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &v2);

        vel = (JGeometry::TVec3f*)(self + 0x250);
        lenSq = vel->z * vel->z + vel->x * vel->x + vel->y * vel->y;
        if (lenSq > 32.0f * FLT_EPSILON) {
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
        } else {
            vec.x = 16.0f;
            vec.y = 0.0f;
            vec.z = 0.0f;
            q = self;
            for (i = 0; i < *(s32*)(self + 0x2a8); i++) {
                obj = fn_801F666C(fn_801F856C(), *(s32*)(q + 0x28c));
                if (obj != 0) {
                    *(JGeometry::TVec3f*)((char*)obj + 0xc) += vec;
                    fn_802C59B0(obj);
                }
                q += 4;
            }

            *(s32*)(self + 0x248) = 0;
            *(u8*)(self + 0x2b8) = 0;
            *(f32*)(self + 0x44) = 0.0f;
            *(f32*)(self + 0x40) = 0.0f;
            *(f32*)(self + 0x3c) = 0.0f;
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
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
        }
    }
}

extern "C" void fn_802D79E8(void* mgr, s32 mode, f32 a, f32 b, s32 c);
extern "C" void fn_802A20F0(void* mgr, void* v, s32 a, s32 room, s32 c, s32 d);
extern "C" void fn_802A1050(void* mgr, void* v);
extern "C" void fn_8030C210(void* obj, void* v);
extern "C" void fn_802C59B0(void* obj);
extern "C" void fn_802D8050(void* mgr, s32 kind, s32 a, s32 b);
extern "C" void* lbl_8053AC98;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_8046C238[];
extern "C" void fn_80298FC4(void* p) {
    char* self = (char*)p;
    char* q;
    char* obj;
    s32 mode;
    s32 bits;
    s32 idx;
    s32 k;
    f32 lenSq;
    JGeometry::TVec3f tmp;
    JGeometry::TVec3f v;
    JGeometry::TVec3f d;
    JGeometry::TVec3f sum;

    if (*(f32*)(self + 0x250) < 0.0f) {
        *(s32*)(self + 0x248) += 1;
        mode = (*(u32*)(self + 0x90) >> 7) & 0x1f;
        mode = (mode == 0) ? 0 : mode + 7;
        fn_802D79E8(fn_802D6A9C(), mode, 1.0f, 0.0f, 1);

        if (*(f32*)(self + 0x250) < -0.32f) {
            *(f32*)(self + 0xc) -= 0.32f;
            *(f32*)(self + 0x250) += 0.32f;
        } else {
            *(f32*)(self + 0xc) += *(f32*)(self + 0x250);
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
        }

        tmp = *(JGeometry::TVec3f*)(self + 0xc);
        tmp.x += *(f32*)(self + 0x60);
        tmp.x += 2.0f;
        tmp.y += *(f32*)(self + 0x64);
        tmp.y += 8.0f;
        tmp.z = 0.0f;
        for (k = 0; k < 6; k++) {
            fn_802A20F0(lbl_8053AC98, &tmp, -1, *(s32*)(self + 0x4), 0, 1);
            fn_802A1050(lbl_8053AC98, &tmp);
            tmp.y += 16.0f;
        }

        sum = *(JGeometry::TVec3f*)(self + 0xc);
        idx = 1;
        if (*(s32*)(self + 0x2a4) > 0 && *(s32*)(self + 0x2cc) == -1) {
            idx = 0;
        }
        d = ((JGeometry::TVec3f*)lbl_8046C238)[idx];
        sum += d;
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &sum);

        lenSq = *(f32*)(self + 0x250) * *(f32*)(self + 0x250)
              + *(f32*)(self + 0x254) * *(f32*)(self + 0x254)
              + *(f32*)(self + 0x258) * *(f32*)(self + 0x258);
        if (lenSq > 32.0f * FLT_EPSILON) {
            v.x = -16.0f;
            v.y = 0.0f;
            v.z = 0.0f;
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
            *(f32*)(self + 0x44) = 0.0f;
            *(f32*)(self + 0x40) = 0.0f;
            *(f32*)(self + 0x3c) = 0.0f;
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
            if (*(s32*)(self + 0x2cc) == 1) {
                bits = (*(u32*)(self + 0x90) >> 17) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 0, 0xff);
                }
            } else {
                bits = (*(u32*)(self + 0x90) >> 12) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 0, 0xff);
                }
            }
            *(s32*)(self + 0x2cc) = 0;
            *(u8*)(self + 0x2c0) = 1;
        } else {
            if (*(s32*)(self + 0x2cc) == 1) {
                bits = (*(u32*)(self + 0x90) >> 17) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 1, 0xff);
                }
            } else {
                bits = (*(u32*)(self + 0x90) >> 12) & 0x1f;
                if (bits > 0) {
                    fn_802D8050(fn_802D6A9C(), bits, 1, 0xff);
                }
            }
        }
    }
}

extern "C" void fn_80299374(void* p) {
    char* self = (char*)p;
    char* q;
    char* obj;
    s32 mode;
    s32 bits;
    s32 idx;
    s32 k;
    f32 lenSq;
    JGeometry::TVec3f tmp;
    JGeometry::TVec3f v;
    JGeometry::TVec3f d;
    JGeometry::TVec3f sum;

    if (*(f32*)(self + 0x254) > 0.0f) {
        *(s32*)(self + 0x248) += 1;
        mode = (*(u32*)(self + 0x90) >> 7) & 0x1f;
        mode = (mode == 0) ? 0 : mode + 7;
        fn_802D79E8(fn_802D6A9C(), mode, 1.0f, 0.0f, 1);

        if (*(f32*)(self + 0x254) > 0.32f) {
            *(f32*)(self + 0x10) += 0.32f;
            *(f32*)(self + 0x254) -= 0.32f;
        } else {
            *(f32*)(self + 0x10) += *(f32*)(self + 0x254);
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
        }

        tmp = *(JGeometry::TVec3f*)(self + 0xc);
        tmp.x += *(f32*)(self + 0x60);
        tmp.x += 8.0f;
        tmp.y += *(f32*)(self + 0x6c);
        tmp.y -= 2.0f;
        tmp.z = 0.0f;
        for (k = 0; k < 6; k++) {
            fn_802A20F0(lbl_8053AC98, &tmp, -1, *(s32*)(self + 0x4), 0, 1);
            fn_802A1050(lbl_8053AC98, &tmp);
            tmp.x += 16.0f;
        }

        sum = *(JGeometry::TVec3f*)(self + 0xc);
        idx = 2;
        if (*(s32*)(self + 0x2a4) > 0 && *(s32*)(self + 0x2cc) == -1) {
            idx ^= 1;
        }
        d.x = lbl_8046C238[idx * 3];
        d.y = lbl_8046C238[idx * 3 + 1];
        d.z = lbl_8046C238[idx * 3 + 2];
        sum = sum + d;
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &sum);

        lenSq = *(f32*)(self + 0x250) * *(f32*)(self + 0x250)
              + *(f32*)(self + 0x254) * *(f32*)(self + 0x254)
              + *(f32*)(self + 0x258) * *(f32*)(self + 0x258);
        if (lenSq <= 32.0f * FLT_EPSILON) {
            v.x = 0.0f;
            v.y = 16.0f;
            v.z = 0.0f;
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
            *(f32*)(self + 0x44) = 0.0f;
            *(f32*)(self + 0x40) = 0.0f;
            *(f32*)(self + 0x3c) = 0.0f;
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
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

extern "C" void fn_80299720(void* p) {
    char* self = (char*)p;
    char* q;
    char* obj;
    s32 mode;
    s32 bits;
    s32 idx;
    s32 k;
    f32 lenSq;
    JGeometry::TVec3f sum;
    JGeometry::TVec3f d;
    JGeometry::TVec3f v;
    JGeometry::TVec3f tmp;

    if (*(f32*)(self + 0x254) < 0.0f) {
        *(s32*)(self + 0x248) += 1;
        mode = (*(u32*)(self + 0x90) >> 7) & 0x1f;
        mode = (mode == 0) ? 0 : mode + 7;
        fn_802D79E8(fn_802D6A9C(), mode, 1.0f, 0.0f, 1);

        if (*(f32*)(self + 0x254) < -0.32f) {
            *(f32*)(self + 0x10) -= 0.32f;
            *(f32*)(self + 0x254) += 0.32f;
        } else {
            *(f32*)(self + 0x10) += *(f32*)(self + 0x254);
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
        }

        tmp = *(JGeometry::TVec3f*)(self + 0xc);
        tmp.x += *(f32*)(self + 0x60);
        tmp.x += 8.0f;
        tmp.y += *(f32*)(self + 0x64);
        tmp.y += 2.0f;
        tmp.z = 0.0f;
        for (k = 0; k < 6; k++) {
            fn_802A20F0(lbl_8053AC98, &tmp, -1, *(s32*)(self + 0x4), 0, 1);
            fn_802A1050(lbl_8053AC98, &tmp);
            tmp.x += 16.0f;
        }

        sum = *(JGeometry::TVec3f*)(self + 0xc);
        idx = 3;
        if (*(s32*)(self + 0x2a4) > 0 && *(s32*)(self + 0x2cc) == -1) {
            idx ^= 1;
        }
        d = ((JGeometry::TVec3f*)lbl_8046C238)[idx];
        sum += d;
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &sum);

        lenSq = *(f32*)(self + 0x250) * *(f32*)(self + 0x250)
              + *(f32*)(self + 0x254) * *(f32*)(self + 0x254)
              + *(f32*)(self + 0x258) * *(f32*)(self + 0x258);
        if (lenSq > 32.0f * FLT_EPSILON) {
            v.x = 0.0f;
            v.y = -16.0f;
            v.z = 0.0f;
            q = self;
            for (k = 0; k < *(s32*)(self + 0x2a8); k++) {
                obj = (char*)fn_801F666C(fn_801F856C(), *(s32*)(q + 0x28c));
                if (obj != 0) {
                    JGeometry::TVec3f cur = *(JGeometry::TVec3f*)(obj + 0xc);
                    cur += v;
                    *(JGeometry::TVec3f*)(obj + 0xc) = cur;
                    fn_802C59B0(obj);
                }
                q += 4;
            }

            *(s32*)(self + 0x248) = 0;
            *(u8*)(self + 0x2b8) = 0;
            *(f32*)(self + 0x44) = 0.0f;
            *(f32*)(self + 0x40) = 0.0f;
            *(f32*)(self + 0x3c) = 0.0f;
            *(f32*)(self + 0x258) = 0.0f;
            *(f32*)(self + 0x254) = 0.0f;
            *(f32*)(self + 0x250) = 0.0f;
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
extern "C" void fn_80299FB0(void* p) {
    s32 mode;
    s32 found;
    s32 i;
    char* self = (char*)p;
    s32 room;
    void* h;
    char* row;
    char* col;
    s32 j;
    s32 r;
    JGeometry::TVec3f v;
    JGeometry::TVec3f g;
    JGeometry::TBox2f pbox;
    JGeometry::TBox2f box;
    JGeometry::TBox2f* tbl;
    void* base;
    f32 lenSq;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;

    lenSq = JMathInlineVEC::PSVECSquareMag((JGeometry::TVec3f*)(self + 0x250));
    if (lenSq <= lbl_805406A8 * FLT_EPSILON) {
        return;
    }
    if (*(u8*)(self + 0x2c0) == 1) {
        *(u8*)(self + 0x2c0) = 0;
        return;
    }
    if (*(u8*)(self + 0x2b4) == 0) {
        return;
    }

    h = *(void**)(self + 0x198);
    mode = -1;
    if (*(u8*)(self + 0x2b9) == 0) {
        if (fn_80239108(h) >= 4) {
            room = *(s32*)(self + 4);
            if (fn_8023DE58(0) == room) {
                r = fn_80238BC4(h);
                if (r >= 0 && r < 4) {
                    *(s32*)(self + 0x2cc) = 1;
                } else {
                    r = -1;
                }
                mode = r;
            }
        }
        if (mode == -1) {
            pbox = *(JGeometry::TBox2f*)(self + 0x80);
            pbox.addPos(*(JGeometry::TVec2f*)(self + 0xc));
            if (fn_80239470(&pbox, *(s32*)(self + 4), h) >= 0 && fn_80238A68(h) >= 4) {
                r = fn_8023885C(h);
                if (r >= 0 && r < 4) {
                    *(s32*)(self + 0x2cc) = -1;
                    mode = r ^ 1;
                } else {
                    mode = -1;
                }
            }
        }
    }
    if (mode != 1) {
        return;
    }

    room = *(s32*)(self + 4);
    tbl = (JGeometry::TBox2f*)((char*)fn_802D6A9C() + (room < 8 ? 0xcc : 0xdc));
    box = *tbl;
    v = *(JGeometry::TVec3f*)(self + 0xc);
    v.x = v.x + *(f32*)(self + 0x60) - 8.0f;
    v.y = v.y + *(f32*)(self + 0x64) + 8.0f;
    v.z = 0.0f;
    x0 = box.i.x - -32.0f;
    y0 = box.i.y - -32.0f;
    x1 = box.f.x + -32.0f;
    y1 = box.f.y + -32.0f;
    box.i.x = x0;
    box.i.y = y0;
    box.f.x = x1;
    box.f.y = y1;

    found = 1;
    for (i = 0; i < 6; i++) {
        if (fn_802A1554(lbl_8053AC98, &v)) {
            base = fn_8020D58C();
            if (fn_8020D6AC((char*)base + *((u8*)base + 1) * 0x784 + 4, room, &v, h, 0) == 1) {
                found = 0;
                break;
            }
        }
        if (v.x >= x0 || v.y >= y0 || v.x >= x1 || v.y >= y1) {
            found = 0;
            break;
        }
        v.y += 16.0f;
    }
    if (!fn_802957CC(p, 1)) {
        found = 0;
    }
    if (found != 1) {
        return;
    }
    if (mode == 1) {
        fn_80238E08(h);
        *(f32*)(self + 0x3c) = -0.32f;
        *(u8*)(self + 0x2b8) = 1;
        fn_801F0E34(self, 0x30004, 0);
    }

    *(f32*)(self + 0x250) = -16.0f;
    *(s32*)(self + 0x248) = 0;
    if (*(u8*)(self + 0x24c) == 0) {
        *(u8*)(self + 0x24c) = 1;
        g.x = *(f32*)(self + 0xc) + *(f32*)(self + 0x60) + 8.0f;
        g.y = *(f32*)(self + 0x10) + *(f32*)(self + 0x64) + 8.0f;
        g.z = 0.0f;
        for (i = 0, row = self; i < 6; i++, row += 0xc) {
            for (j = 0, col = row; j < 6; j++, col += 2) {
                fn_802A381C(lbl_8053AC98, &g, 0, *(u16*)(col + 0x3b0));
                fn_802A381C(lbl_8053AC98, &g, 1, 0);
                g.y += 16.0f;
            }
            g.x += 16.0f;
        }
    }
}

extern "C" void fn_8029A974(void* p) {
    s32 mode;
    u8 flag;
    s32 i;
    char* self;
    s32 room;
    void* h;
    char* row;
    char* col;
    char* base;
    s32 j;
    u8 ok;
    f32 lenSq;
    JGeometry::TVec3f* vel;
    JGeometry::TVec3f pos;
    JGeometry::TVec3f v;
    JGeometry::TBox2f box;
    JGeometry::TBox2f zone;

    self = (char*)p;
    vel = (JGeometry::TVec3f*)(self + 0x250);
    lenSq = vel->squared();
    if (lenSq <= 32.0f * FLT_EPSILON) {
        if (*(u8*)(self + 0x2c0) == 1) {
            *(u8*)(self + 0x2c0) = 0;
            return;
        }
        if (*(u8*)(self + 0x2b4) == 0) {
            return;
        }
        mode = -1;
        if (*(u8*)(self + 0x2b9) == 0) {
            if (fn_80239108(*(void**)(self + 0x198)) >= 4) {
                room = *(s32*)(self + 4);
                if (fn_8023DE58(0) == room) {
                    mode = fn_80238BC4(*(void**)(self + 0x198));
                    if (mode >= 0 && mode < 4) {
                        *(s32*)(self + 0x2cc) = 1;
                    } else {
                        mode = -1;
                    }
                }
            }
            if (mode == -1) {
                box.i.x = *(f32*)(self + 0x80) + *(f32*)(self + 0xc);
                box.i.y = *(f32*)(self + 0x84) + *(f32*)(self + 0x10);
                box.f.x = *(f32*)(self + 0x88) + *(f32*)(self + 0xc);
                box.f.y = *(f32*)(self + 0x8c) + *(f32*)(self + 0x10);
                if (fn_80239470(&box, *(s32*)(self + 4), *(void**)(self + 0x198)) >= 0) {
                    if (fn_80238A68(*(void**)(self + 0x198)) >= 4) {
                        mode = fn_8023885C(*(void**)(self + 0x198));
                        if (mode >= 0 && mode < 4) {
                            if (mode == 0) {
                                mode = 1;
                            } else if (mode == 1) {
                                mode = 0;
                            } else if (mode == 2) {
                                mode = 3;
                            } else if (mode == 3) {
                                mode = 2;
                            }
                            *(s32*)(self + 0x2cc) = -1;
                        } else {
                            mode = -1;
                        }
                    } else {
                        mode = -1;
                    }
                } else {
                    mode = -1;
                }
            }
        }
        if (mode != 3) {
            return;
        }
        room = *(s32*)(self + 4);
        base = (char*)fn_802D6A9C();
        zone = *(JGeometry::TBox2f*)(room < 8 ? base + 0xcc : base + 0xdc);
        flag = 1;
        zone.i.x -= -32.0f;
        zone.i.y -= -32.0f;
        zone.f.x += -32.0f;
        zone.f.y += -32.0f;
        v = *(JGeometry::TVec3f*)(self + 0xc);
        v.x += *(f32*)(self + 0x60);
        v.x += 8.0f;
        v.y += *(f32*)(self + 0x64);
        v.y -= 8.0f;
        v.z = 0.0f;
        for (i = 0; i < 6; i++) {
            if (!fn_802A1554(lbl_8053AC98, &v)) {
                flag = 0;
                break;
            }
            room = *(s32*)(self + 4);
            h = *(void**)(self + 0x198);
            base = (char*)fn_8020D58C();
            if (fn_8020D6AC(base + 4 + *(u8*)(base + 1) * 0x784, room, &v, h, 0) == 1) {
                flag = 0;
                break;
            }
            ok = 0;
            if (v.x >= zone.i.x && v.y >= zone.i.y && v.x < zone.f.x && v.y < zone.f.y) {
                ok = 1;
            }
            if (!ok) {
                flag = 0;
                break;
            }
            v.x += 16.0f;
        }
        if (!fn_802957CC(p, 3)) {
            flag = 0;
        }
        if (flag != 1) {
            return;
        }
        if (mode == 3) {
            fn_80238E08(*(void**)(self + 0x198));
            *(f32*)(self + 0x40) = -0.32f;
            *(u8*)(self + 0x2b8) = 1;
            fn_801F0E34(p, 0x30004, 0);
            *(f32*)(self + 0x254) = -16.0f;
            *(s32*)(self + 0x248) = 0;
            if (*(u8*)(self + 0x24c) != 0) {
                return;
            }
            *(u8*)(self + 0x24c) = 1;
        }
        pos = *(JGeometry::TVec3f*)(self + 0xc);
        pos.x += *(f32*)(self + 0x60);
        pos.x += 8.0f;
        pos.y += *(f32*)(self + 0x64);
        pos.y += 8.0f;
        pos.z = 0.0f;
        v = pos;
        row = self;
        for (i = 0; i < 6; i++, row += 0xc) {
            for (j = 0, col = row; j < 6; j++, col += 2) {
                fn_802A381C(lbl_8053AC98, &v, 0, *(u16*)(col + 0x3b0));
                fn_802A381C(lbl_8053AC98, &v, 1, 0);
                v.y += 16.0f;
            }
            v.x += 16.0f;
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
    char* row;
    char* col;
    s32 i;
    s32 j;

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
        for (j = 0, col = (char*)p; j < 4; j++, col += 4) {
            fn_801EE434(*(s32*)(col + 0x310));
        }
        __dt__5ActorFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
