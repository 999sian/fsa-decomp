#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"

class WaveController {
public:
    WaveController(s32 a, s32 b, s32 c);
    ~WaveController();
private:
    unsigned char pad[0x5c];
};

struct WaveSubBase { u8 pad[8]; };
struct WaveSub : WaveSubBase {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void release(s32 how);
};

struct WaveOwner {
    void* vtbl;
    void* mpSub;
};

extern char lbl_804A7C98[];
extern void* lbl_8053AC98;
extern char* lbl_8053AB10;
extern "C" u8 lbl_8046C5A0[];
extern "C" u8 lbl_8046C528[];
extern "C" s32 fn_80226BC4(JGeometry::TVec2<f32>* pos, s32 room);
extern "C" void fn_802F9974(void* mgr, u32 room, s32 idx, u16 value);

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D782C(void* mgr, s32 v);
extern "C" s32 fn_802D4C10(void* mgr, u32 room, u16 v);
extern "C" void fn_802D7D00(void* mgr, u32 room, s32 idx, s32 v);
extern "C" void fn_802D7970(void* p, s32 v);
extern "C" void fn_80138B7C(void* p);
extern "C" void* fn_8023E724(void* p);
extern "C" u32 fn_802A0800(char* self, void* p3, u32 room);
extern void* lbl_8053AAF8;
extern u16 lbl_8046CB88[];
extern "C" u16 fn_8022461C(JGeometry::TVec2<f32>* pos, s32 flag);
extern "C" void fn_8029D898(void* a, s32 b) {
    s32 v = *(s32*)((char*)fn_802D6A9C() + 0x34);
    fn_802D7970(fn_802D6A9C(), b);
    fn_80138B7C(lbl_8053AAF8);
    fn_802D7970(fn_802D6A9C(), v);
}

extern "C" void fn_8029D8F0(void* p, JGeometry::TVec2<f32>* pos, s32 param_3, s32 param_4, s32 param_5) {
    void* mgr = fn_802D6A9C();
    JGeometry::TBox2f* src;
    JGeometry::TBox2f base;
    s32 x;
    s32 y;
    u32 cell;
    u32 rowStart;
    u32 slot;
    u32 room;
    u16* row;
    u16* pv;
    u16 v;
    s32 i;
    s32 j;

    if ((param_3 & 0xfe) < 8) {
        src = (JGeometry::TBox2f*)((u8*)mgr + 0xcc);
    } else {
        src = (JGeometry::TBox2f*)((u8*)mgr + 0xdc);
    }
    base = *src;
    x = (s32)(pos->x - base.i.x);
    y = (s32)(pos->y - base.i.y);
    if (x < 0) {
        x = 0;
    } else if (x >= 0x200) {
        x = 0x1ff;
    }
    if (y < 0) {
        y = 0;
    } else if (y >= 0x200) {
        y = 0x1ff;
    }
    cell = ((x - 0x10) & 0x100) | (((y - 0x30) & 0x100) << 1) | ((y - 0x30) & 0xf0) | (((x - 0x10) >> 4) & 0xf);
    room = param_3 + param_4;

    rowStart = cell;
    row = (u16*)((u8*)lbl_8046C5A0 + param_5 * 0x28);
    for (i = 0; i < 4; i++) {
        pv = row;
        slot = rowStart;
        for (j = 0; j < 4; j++) {
            v = *pv;
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, slot, v);
            slot++;
            if ((slot & 0xf) == 0) {
                slot += 0xf0;
            }
            pv++;
        }
        {
            u32 next = rowStart + 0x10;
            if ((rowStart & 0x100) != (next & 0x100)) {
                next = rowStart + 0x110;
            }
            rowStart = next;
        }
        row += 4;
    }

    rowStart = cell + 0x10;
    if ((cell & 0x100) != (rowStart & 0x100)) {
        rowStart = cell + 0x110;
    }
    row = (u16*)((u8*)lbl_8046C528 + param_5 * 0x28);
    for (i = 0; i < 4; i++) {
        pv = row;
        slot = rowStart;
        for (j = 0; j < 4; j++) {
            v = *pv;
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), param_3, slot, v);
            slot++;
            if ((slot & 0xf) == 0) {
                slot += 0xf0;
            }
            pv++;
        }
        {
            u32 next = rowStart + 0x10;
            if ((rowStart & 0x100) != (next & 0x100)) {
                next = rowStart + 0x110;
            }
            rowStart = next;
        }
        row += 4;
    }
}

extern "C" void fn_8029DB2C(void* p, u32 a, u32 room, s32 flag, u32 v1, u32 v2, u32 v3, u32 v4, u16 v5, u16 v6) {
    u32 r = room;
    if (flag == 0) {
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, r, (u16)v1);
        r += 1;
        if ((r & 0xf) == 0) {
            r += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, r, (u16)v2);
        r += 1;
        if ((r & 0xf) == 0) {
            r += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, r, (u16)v3);
        r += 1;
        if ((r & 0xf) == 0) {
            r += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, r, (u16)v4);
        r += 1;
        if ((r & 0xf) == 0) {
            r += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, r, v5);
        r += 1;
        if ((r & 0xf) == 0) {
            r += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, r, v6);
    } else {
        u32 n;
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, r, (u16)v1);
        n = r + 0x10;
        if ((r & 0x100) != (n & 0x100)) {
            n = r + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, n, (u16)v2);
        r = n + 0x10;
        if ((n & 0x100) != (r & 0x100)) {
            r = n + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, r, (u16)v3);
        n = r + 0x10;
        if ((r & 0x100) != (n & 0x100)) {
            n = r + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, n, (u16)v4);
        r = n + 0x10;
        if ((n & 0x100) != (r & 0x100)) {
            r = n + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, r, v5);
        n = r + 0x10;
        if ((r & 0x100) != (n & 0x100)) {
            n = r + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, n, v6);
    }
}

extern "C" void fn_8029DD50(void* p, s32 a, s32 room, s32 flag, s32 c, s32 v1, s32 v2, s32 v3) {
    if (flag == 0) {
        s32 idx = room;
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, idx, c);
        idx += 1;
        if ((idx & 0xf) == 0) {
            idx += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, idx, v1);
        idx += 1;
        if ((idx & 0xf) == 0) {
            idx += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, idx, v2);
        idx += 1;
        if ((idx & 0xf) == 0) {
            idx += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, idx, v3);
    } else {
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, room, c);
        s32 idx = room + 0x10;
        if ((room & 0x100) != (idx & 0x100)) {
            idx = room + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, idx, v1);
        room = idx + 0x10;
        if ((idx & 0x100) != (room & 0x100)) {
            room = idx + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, room, v2);
        idx = room + 0x10;
        if ((room & 0x100) != (idx & 0x100)) {
            idx = room + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, idx, v3);
    }
}

extern "C" void fn_8029DEBC(void* p, s32 a, s32 room, s32 flag, s32 c, s32 value) {
    if (flag == 0) {
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, room, c);
        room += 1;
        if ((room & 0xf) == 0) {
            room += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, room, value);
    } else {
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, room, c);
        s32 idx = room + 0x10;
        if ((room & 0x100) != (idx & 0x100)) {
            idx = room + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, idx, value);
    }
}

extern "C" void fn_8029DF80(void* p, s32 x, u32 y, s32 a, s32 b, s32 c, s32 d) {
    s32 n = x;
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), y, x, (u16)a);
    n++;
    if ((n & 0xf) == 0) {
        n += 0xf0;
    }
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), y, n, (u16)b);
    n = x + 0x10;
    if ((x & 0x100) != (n & 0x100)) {
        n = x + 0x110;
    }
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), y, n, (u16)c);
    n++;
    if ((n & 0xf) == 0) {
        n += 0xf0;
    }
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), y, n, (u16)d);
}

extern "C" void fn_8029E050(void* self, JGeometry::TVec2<f32>* pos, u32 room, s32 a, s32 b, s32 c, s32 d)
{
    JGeometry::TVec2<f32> q;
    q.y = pos->y;
    q.x = pos->x;
    void* mgr = lbl_8053AC98;
    *(s32*)((char*)mgr + 0x20) = fn_80226BC4(&q, room & 0xfe);
    s32 idx = *(s32*)((char*)mgr + 0x20);
    fn_802D782C(fn_802D6A9C(), 1);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, a);
    s32 n = fn_802D4C10(fn_802D6A9C(), room, *(s32*)((char*)mgr + 0x20));
    if (n != -1) {
        fn_802D7D00(fn_802D6A9C(), room, n, 1);
    }
    s32 i = *(s32*)((char*)self + 0x20) + 1;
    if ((i & 0xf) == 0) {
        i += 0xf0;
    }
    fn_802D782C(fn_802D6A9C(), 1);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, i, b);
    n = fn_802D4C10(fn_802D6A9C(), room, i);
    if (n != -1) {
        fn_802D7D00(fn_802D6A9C(), room, n, 1);
    }
    s32 base = *(s32*)((char*)self + 0x20);
    s32 j = base + 0x10;
    if ((base & 0x100) != (j & 0x100)) {
        j = base + 0x110;
    }
    fn_802D782C(fn_802D6A9C(), 1);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, j, c);
    n = fn_802D4C10(fn_802D6A9C(), room, j);
    if (n != -1) {
        fn_802D7D00(fn_802D6A9C(), room, n, 1);
    }
    i = j + 1;
    if ((i & 0xf) == 0) {
        i += 0xf0;
    }
    fn_802D782C(fn_802D6A9C(), 1);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, i, d);
    n = fn_802D4C10(fn_802D6A9C(), room, i);
    if (n != -1) {
        fn_802D7D00(fn_802D6A9C(), room, n, 1);
    }
}

extern "C" u16 fn_802F9908(void* mgr, u32 room, s32 idx);
extern "C" u32 fn_8029E888(char* self, JGeometry::TVec2<f32>* pos, void* p3, u32 room) {
    JGeometry::TVec2<f32> p;
    p.y = pos->y;
    p.x = pos->x;
    *(s32*)(self + 0x20) = fn_80226BC4(&p, room);
    *(u16*)(self + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, *(s32*)(self + 0x20));
    JGeometry::TVec3<f32> v = *(JGeometry::TVec3<f32>*)fn_8023E724(p3);
    return *(u16*)(self + 0x24) == 0x30;
}

extern "C" void fn_8029E928(void* self, JGeometry::TVec2<f32>* pos, u32 room, u32 value) {
    JGeometry::TVec2<f32> p;
    p.y = pos->y;
    p.x = pos->x;
    void* mgr = lbl_8053AC98;
    s32 r = fn_80226BC4(&p, room & 0xfe);
    *(s32*)((char*)mgr + 0x20) = r;
    s32 idx = *(s32*)((char*)mgr + 0x20);
    fn_802D782C(fn_802D6A9C(), 1);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, value);
    s32 n = fn_802D4C10(fn_802D6A9C(), room, *(s32*)((char*)mgr + 0x20));
    if (n != -1) {
        fn_802D7D00(fn_802D6A9C(), room, n, 1);
    }
}

extern "C" void fn_802D7BE8(void* mgr, s32 room, u32 value, s32 x);
extern "C" u8 lbl_8046C4C8[];
extern "C" void fn_8029EC84(void* p, u32 p2, u32 p3, u32 p4, u16 p5, u16 p6) {
    s32 idx = p2;
    u32 room = p3 + p4;
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, p6);
    if ((idx & 0x100) == ((idx - 0x10) & 0x100)) {
        idx -= 0x10;
    } else {
        idx -= 0x110;
    }
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, p5);
    u32 val = *(u32*)(lbl_8046C4C8 + (fn_802D4C10(fn_802D6A9C(), p3, (u16)p2) & ~3));
    s32 kind = p5;
    if (kind < 0xa0) {
        if (kind >= 0x18 && kind < 0x20) {
            fn_802D7BE8(fn_802D6A9C(), p3, val, kind - 0x16);
            return;
        }
    } else if (kind == 0xfff || kind < 0xa4) {
        fn_802D7BE8(fn_802D6A9C(), p3, val, kind - 0x96);
        return;
    }
    fn_802D7BE8(fn_802D6A9C(), p3, val, 1);
}

extern "C" u32 fn_802A01F0(char* self, JGeometry::TVec2<f32>* pos, void* p3, u32 room) {
    JGeometry::TVec2<f32> p;
    p.y = pos->y;
    p.x = pos->x;
    *(s32*)(self + 0x20) = fn_80226BC4(&p, room);
    *(u16*)(self + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, *(s32*)(self + 0x20));
    u32 ret = 0;
    switch (*(u16*)(self + 0x24)) {
    case 0x16:
    case 0x17:
        ret = fn_802A0800(self, p3, room);
        break;
    case 0x71:
        ret = 1;
        break;
    }
    return ret;
}

extern "C" BOOL fn_802A1490(void* this_, JGeometry::TVec2<f32>* param_2) {
    JGeometry::TVec2<f32> tmp;
    tmp.y = param_2->y;
    tmp.x = param_2->x;
    *(u32*)((u8*)this_ + 0x20) = fn_80226BC4(&tmp, 0);
    *(u16*)((u8*)this_ + 0x24) = fn_802F9908(*(void**)((u8*)lbl_8053AB10 + 0x20), 0, *(u32*)((u8*)this_ + 0x20));
    if (lbl_8046CB88[*(u16*)((u8*)this_ + 0x24)] == 0) {
        return TRUE;
    }
    if (fn_8022461C(param_2, 0) == 0x22 && *(u8*)((u8*)fn_802D6A9C() + 0x170) == 0) {
        return TRUE;
    }
    return FALSE;
}

extern "C" u32 fn_802A1554(char* self, JGeometry::TVec2<f32>* pos) {
    JGeometry::TVec2<f32> p;
    p.y = pos->y;
    p.x = pos->x;
    *(s32*)(self + 0x20) = fn_80226BC4(&p, 0);
    *(u16*)(self + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), 0, *(s32*)(self + 0x20));
    u16 kind = *(u16*)(self + 0x24);
    if (lbl_8046CB88[kind] == 0) {
        return 1;
    }
    if (kind == 0x75 || (u16)(kind - 0x68) <= 3 || kind == 0x82 || kind == 0x5f || (u16)(kind - 0x70) <= 2 || (u16)(kind - 0x40) <= 4 || kind == 0xe5 || kind == 0x58) {
        return 1;
    }
    int t = (u16)fn_8022461C(pos, 0);
    if (t == 0xe || t == 3 || (t == 0x22 && ((u8*)fn_802D6A9C())[0x170] == 0)) {
        return 1;
    }
    return 0;
}

extern "C" void fn_8013CC50(u32 room, JGeometry::TVec2<f32>* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 f);
extern "C" void* fn_801F856C(void);
extern "C" void* Actor_CreateByID(void* mgr, u32 id, u32 room, JGeometry::TVec2<f32>* pos, s32 a, s32 b, s32 c);
extern "C" void fn_802A3164(char* self, JGeometry::TVec2<f32>* pos, s32 a, u32 room);
extern f32 lbl_80540790;
extern "C" void fn_802A1688(char* self, JGeometry::TVec2<f32>* pos, u32 room, u32 kind) {
    JGeometry::TVec2<f32> p;
    f32 y = pos->y;
    f32 x = pos->x;
    p.y = y;
    p.x = x;
    *(s32*)(self + 0x20) = fn_80226BC4(&p, room);
    *(u16*)(self + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, *(s32*)(self + 0x20));
    if (*(u16*)(self + 0x24) == 0x81) {
        if (kind != 0x5342414c) {
            JGeometry::TVec2<f32> q;
            q.y = pos->y;
            q.x = pos->x;
            void* mgr = lbl_8053AC98;
            *(s32*)((char*)mgr + 0x20) = fn_80226BC4(&q, room & 0xfe);
            s32 idx = *(s32*)((char*)mgr + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, 0x9d);
            s32 n = fn_802D4C10(fn_802D6A9C(), room, *(s32*)((char*)mgr + 0x20));
            if (n != -1) {
                fn_802D7D00(fn_802D6A9C(), room, n, 1);
            }
            if ((s32)room >= 8) {
                Actor_CreateByID(fn_801F856C(), 0x4b4d5249, room, pos, 0, -1, -1);
            } else {
                fn_8013CC50(room, pos, 0xf9, 1, 0, 0, 0, 1, lbl_80540790);
                fn_8013CC50(room, pos, 0xfa, 1, 0, 0, 0, 1, lbl_80540790);
            }
        }
        u32 msg = 0x50045;
        WaveSub* sub = (WaveSub*)((WaveOwner*)self)->mpSub;
        ((void (*)(void*, u32*))(*(void***)((char*)sub + 8))[5])(sub, &msg);
    }
    fn_802A3164(self, pos, -1, room);
}

extern "C" void fn_802A381C(void* self, JGeometry::TVec2<f32>* pos, u32 room, u32 value) {
    JGeometry::TVec2<f32> p;
    p.y = pos->y;
    p.x = pos->x;
    s32 r = fn_80226BC4(&p, room & 0xfe);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, r, value);
}

extern "C" void fn_802A3884(char* self, JGeometry::TVec2<f32>* pos, void* p3, u32 room, u32 value) {
    JGeometry::TVec2<f32> p;
    p.y = pos->y;
    p.x = pos->x;
    s32 r = fn_80226BC4(&p, room & 0xfe);
    *(s32*)(self + 0x20) = r;
    s32 idx = *(s32*)(self + 0x20);
    fn_802D782C(fn_802D6A9C(), 1);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, value);
    s32 n = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)(self + 0x20));
    if (n != -1) {
        fn_802D7D00(fn_802D6A9C(), room, n, 0);
    }
}

extern "C" void fn_802A3948(char* self, JGeometry::TVec2<f32>* pos, void* p3, u32 room, u32 value) {
	JGeometry::TVec2<f32> p;
	p.y = pos->y;
	p.x = pos->x;
	*(s32*)(self + 0x20) = fn_80226BC4(&p, room & 0xfe);
	s32 idx = *(s32*)(self + 0x20);
	fn_802D782C(fn_802D6A9C(), 1);
	fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, value);
	s32 n = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)(self + 0x20));
	if (n != -1) {
		fn_802D7D00(fn_802D6A9C(), room, n, 1);
	}
}

extern "C" void fn_802A3D80(char* p) {
    *(s32*)(p + 0x8) = 10;
    *(s32*)(p + 0xc) = 0;
    *(s32*)(p + 0x10) = 10;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 10;
    *(s32*)(p + 0x1c) = 0;
}

extern "C" WaveOwner* fn_802A3DA4(WaveOwner* this_, s16 del) {
    if (this_ != 0) {
        this_->vtbl = lbl_804A7C98;
        lbl_8053AC98 = 0;
        if (this_->mpSub != 0) {
            ((WaveSub*)this_->mpSub)->release(1);
        }
        this_->mpSub = 0;
        if (del > 0) {
            delete this_;
        }
    }
    return this_;
}

extern "C" WaveOwner* fn_802A3E2C(WaveOwner* this_) {
    this_->vtbl = lbl_804A7C98;
    lbl_8053AC98 = this_;
    WaveController* w = new WaveController(0, 0, 8);
    this_->mpSub = w;
    return this_;
}

extern "C" char lbl_804D0968[];
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void fn_802A3E94(void) {
    char* base = lbl_804D0968 + 0x0;
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

