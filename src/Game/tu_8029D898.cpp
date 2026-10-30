#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JKernel/JKRArchive.h"


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

// Actor virtual slot 7 (vtable +0x24): start/activate.
struct ActorVt {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void activate();
};

// Message sink at mpSub (vtable at +8), slot 3 (vtable +0x14) takes a message id.
struct WaveMsgSink : WaveSubBase {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void post(u32* msg);
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
class Actor {
public:
    void detach();
};
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, void*);
extern "C" void fn_802D782C(void* mgr, s32 v);
extern "C" s32 fn_802D4C10(void* mgr, u32 room, u16 v);
extern "C" void fn_802D7D00(void* mgr, u32 room, s32 idx, s32 v);
extern "C" u16 fn_802F9908(void* mgr, u32 room, s32 idx);
extern "C" void fn_802D7970(void* p, s32 v);
extern "C" void fn_80226CA8(s32, u32, JGeometry::TVec3<f32>*);
extern "C" u8 fn_802D6AC4(void*, s32);
extern "C" void fn_802D6B24(void*, s32, s32);
extern f32 lbl_80540784, lbl_80540788, lbl_8054078C, lbl_80540794;
extern "C" void fn_80138B7C(void* p);
extern "C" void* fn_8023E724(void* p);
extern "C" u32 fn_802A0800(char* self, void* p3, u32 room);
extern void* lbl_8053AAF8;
extern u16 lbl_8046CB88[];
extern "C" u16 fn_8022461C(JGeometry::TVec2<f32>* pos, s32 flag);
extern "C" u8 lbl_8046C508[];
extern "C" void fn_8013CC50(u32 room, JGeometry::TVec2<f32>* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 f);
extern "C" void* Actor_CreateByID(void* mgr, u32 id, u32 room, JGeometry::TVec2<f32>* pos, s32 a, s32 b, s32 c);
extern f32 lbl_80540790;
extern "C" void fn_80230FD0(s32 h, s32 id);
extern "C" void fn_80458880(void* p, s32 a, s32 b);
extern void* lbl_8053AF80;
// Shared tail of the fn_802A02A8 tile cases: re-tile pos with value, then refresh.
static inline s32 fn_802A02A8_Refresh(JGeometry::TVec2<f32>* pos, u32 room, u16 value, s32 p3) {
    JGeometry::TVec2<f32> t = *pos;
    void* mgr = lbl_8053AC98;
    *(s32*)((u8*)mgr + 0x20) = fn_80226BC4(&t, room & 0xfe);
    fn_802D782C(fn_802D6A9C(), 1);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, *(s32*)((u8*)mgr + 0x20), value);
    s32 idx = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)((u8*)mgr + 0x20));
    if (idx != -1) {
        fn_802D7D00(fn_802D6A9C(), room, idx, 1);
        fn_80230FD0(p3, 0x20007);
    }
    return idx;
}

static inline void fn_8029E9EC_sub(const JGeometry::TVec2<f32>* pos, s32 room, u16 param) {
    JGeometry::TVec2<f32> t;
    t.y=pos->y;
    t.x=pos->x;
    void* mgr = lbl_8053AC98;
    *(s32*)((u8*)mgr + 0x20) = fn_80226BC4(&t, room & 0xfe);
    s32 tile = *(s32*)((u8*)mgr + 0x20);
    fn_802D782C(fn_802D6A9C(), 1);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, tile, param);
    s32 idx = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)((u8*)mgr + 0x20));
    if (idx != -1) {
        fn_802D7D00(fn_802D6A9C(), room, idx, 1);
    }
}
static inline void WaveCopyPos(JGeometry::TVec2<f32>& dst, const f32 x, const f32 y);
static inline void fn_802A3164_sub(const JGeometry::TVec2<f32>* pos, s32 room, u16 param, s32 flag) {
    void* mgr;
    JGeometry::TVec2<f32> t;
    WaveCopyPos(t, pos->x, pos->y);
    mgr = lbl_8053AC98;
    *(s32*)((u8*)mgr + 0x20) = fn_80226BC4(&t, room & 0xfe);
    s32 tile = *(s32*)((u8*)mgr + 0x20);
    fn_802D782C(fn_802D6A9C(), 1);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, tile, param);
    s32 idx = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)((u8*)mgr + 0x20));
    if (idx != -1) {
        fn_802D7D00(fn_802D6A9C(), room, idx, flag);
    }
}
static inline void WaveCopyPos(JGeometry::TVec2<f32>& dst, const f32 x, const f32 y) {
    dst.y = y;
    dst.x = x;
}

static inline void WaveLiftRetile(const JGeometry::TVec3<f32>* pos, u32 room, u16 value, s32 flag) {
    JGeometry::TVec2<f32> t;
    t.x=pos->x; t.y=pos->y;
    void* mgr=lbl_8053AC98;
    *(s32*)((u8*)mgr+0x20)=fn_80226BC4(&t,room&0xfe);
    s32 tile=*(s32*)((u8*)mgr+0x20);
    fn_802D782C(fn_802D6A9C(),1);
    fn_802F9974(*(void**)(lbl_8053AB10+0x20),room,tile,value);
    s32 n=fn_802D4C10(fn_802D6A9C(),room,(u16)*(s32*)((u8*)mgr+0x20));
    if(n!=-1)fn_802D7D00(fn_802D6A9C(),room,n,flag);
}

// Replaces the room-0 tile at pos with tile `value` and refreshes it.
static inline void SetTile0(JGeometry::TVec2<f32>* pos, u16 value) {
    JGeometry::TVec2<f32> t;
    f32 y = pos->y;
    f32 x = pos->x;
    t.y = y;
    t.x = x;
    void* mgr = lbl_8053AC98;
    *(s32*)((char*)mgr + 0x20) = fn_80226BC4(&t, 0);
    s32 idx = *(s32*)((char*)mgr + 0x20);
    fn_802D782C(fn_802D6A9C(), 1);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), 0, idx, value);
    s32 n = fn_802D4C10(fn_802D6A9C(), 0, (u16)*(s32*)((char*)mgr + 0x20));
    if (n != -1) {
        fn_802D7D00(fn_802D6A9C(), 0, n, 1);
    }
}

extern "C" void fn_8029D898(void* a, s32 b) {
    s32 v = *(s32*)((char*)fn_802D6A9C() + 0x34);
    fn_802D7970(fn_802D6A9C(), b);
    fn_80138B7C(lbl_8053AAF8);
    fn_802D7970(fn_802D6A9C(), v);
}

#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void fn_8029D8F0(void* p, JGeometry::TVec2<f32>* pos, s32 arg3, s32 arg4, s32 param_5) {
    s32 param_4;
    s32 param_3;
    param_3 = arg3;
    param_4 = arg4;
    void* mgr = fn_802D6A9C();
    JGeometry::TBox2f* src;
    JGeometry::TBox2f base;
    s32 x;
    s32 y;
    s32 offset;
    u32 room;
    u32 cell;
    u16 v;
    u16* pv;
    u16* row;
    s32 rowStart;
    u32 slot;
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
    cell = (((y - 0x30) & 0x100) << 1) | ((x - 0x10) & 0x100) | ((y - 0x30) & 0xf0) | (((x - 0x10) >> 4) & 0xf);
    room = param_3 + param_4;
    offset = param_5 * 0x28;

    rowStart = cell;
    row = (u16*)((u8*)lbl_8046C5A0 + offset);
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
            pv += 1;
        }
        {
            s32 next = rowStart + 0x10;
            if ((s32)(s32)(rowStart & 0x100) != (s32)(next & 0x100)) {
                next = rowStart + 0x110;
            }
            rowStart = next;
        }
        row += 4;
    }

    rowStart = cell + 0x10;
    if ((s32)(cell & 0x100) != (s32)(rowStart & 0x100)) {
        rowStart = cell + 0x110;
    }
    row = (u16*)((u8*)lbl_8046C528 + offset);
    for (i = 0; i < 4; i++) {
        pv = row;
        slot = rowStart;
        for (j = 0; j < 4; j++) {
            v = *pv;
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), param_3, slot, v);
            slot += 1;
            if (((unsigned)slot & 0xf) == 0) {
                slot += (short)0xf0;
            }
            pv++;
        }
        {
            s32 next = rowStart + 0x10;
            if ((s32)(rowStart & 0x100) != (s32)(next & 0x100)) {
                next = rowStart + 0x110;
            }
            rowStart = next;
        }
        row += 4;
    }
}
#pragma opt_common_subs reset
#pragma opt_propagation off
extern "C" void fn_8029DB2C(void* p, u32 a, u32 room, s32 flag, u32 v1, u32 v2, u32 v3, u32 v4, u16 v5, u16 v6) {
    u32 a1;
    u32 n;
    u32 a0;
    if (flag == 0) {
        a0 = a;
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a0, room, (u16)v1);
        room += 1;
        if ((room & 0xf) == 0) {
            room += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a0, room, (u16)v2);
        room += 1;
        if ((room & 0xf) == 0) {
            room += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a0, room, (u16)v3);
        room += 1;
        if ((room & 0xf) == 0) {
            room += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a0, room, (u16)v4);
        room += 1;
        if ((room & 0xf) == 0) {
            room += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a0, room, v5);
        room += 1;
        if ((room & 0xf) == 0) {
            room += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a0, room, v6);
    } else {
        a1 = a;
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a1, room, (u16)v1);
        n = room + 0x10;
        if ((s32)(room & 0x100) != (s32)(n & 0x100)) {
            n = room + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a1, n, (u16)v2);
        room = n + 0x10;
        if ((s32)(n & 0x100) != (s32)(room & 0x100)) {
            room = n + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a1, room, (u16)v3);
        n = room + 0x10;
        if ((s32)(room & 0x100) != (s32)(n & 0x100)) {
            n = room + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a1, n, (u16)v4);
        room = n + 0x10;
        if ((s32)(n & 0x100) != (s32)(room & 0x100)) {
            room = n + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a1, room, v5);
        n = room + 0x10;
        if ((s32)(room & 0x100) != (s32)(n & 0x100)) {
            n = room + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a1, n, v6);
    }
}
#pragma opt_propagation reset
extern "C" void fn_8029DD50(void* p, s32 a, s32 room, s32 flag, s32 c, s32 v1, s32 v2, s32 v3) {
    s32 rm = room;
    s32 w1 = v1;
    s32 w2 = v2;
    s32 w3 = v3;
    if (flag == 0) {
        s32 base = a;
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), base, rm, c);
        rm++;
        if ((rm & 0xf) == 0) {
            rm += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), base, rm, w1);
        rm++;
        if ((rm & 0xf) == 0) {
            rm += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), base, rm, w2);
        rm++;
        if ((rm & 0xf) == 0) {
            rm += 0xf0;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), base, rm, w3);
    } else {
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, rm, c);
        s32 idx = rm + 0x10;
        if ((rm & 0x100) != (idx & 0x100)) {
            idx = rm + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, idx, w1);
        rm = idx + 0x10;
        if ((idx & 0x100) != (rm & 0x100)) {
            rm = idx + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, rm, w2);
        idx = rm + 0x10;
        if ((rm & 0x100) != (idx & 0x100)) {
            idx = rm + 0x110;
        }
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), a, idx, w3);
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

#pragma opt_propagation off
extern "C" void fn_8029DF80(void* p, s32 x, u32 y, s32 a, s32 b, s32 c, s32 d) {
    s32 bb;
    s32 cc;
    s32 dd;
    u32 yy;
    s32 xx;
    s32 n;
    xx = x; yy = y; bb = b; cc = c; dd = d; n = xx;
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), yy, n, (u16)a);
    n++;
    if ((n & 0xf) == 0) n += 0xf0;
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), yy, n, (u16)bb);
    n = xx + 0x10;
    if ((xx & 0x100) != (n & 0x100)) n = xx + 0x110;
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), yy, n, (u16)cc);
    s32 last = n + 1;
    if ((last & 0xf) == 0) last += 0xf0;
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), yy, last, (u16)dd);
}
#pragma opt_propagation reset
extern "C" void fn_8029E050(void* self, JGeometry::TVec2<f32>* pos, u32 room, s32 a, s32 b, s32 c, s32 d)
{
    JGeometry::TVec2<f32> q = *pos;
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

extern f32 lbl_80540780;
extern "C" void fn_80230FD0(s32 h, s32 id);
#pragma opt_propagation off
extern "C" u32 fn_8029E248(char* self, const JGeometry::TVec2<f32>* __restrict pos, u32 room) {
    u32 drawRoom;
    const JGeometry::TVec2<f32>* coords=pos;
    char* object=self;
    u32 ret;
    s32 inputRoom=room;
    ret=0;
    JGeometry::TVec2<f32> p;
    p.y = coords->y;
    p.x = coords->x;
    *(s32*)(object + 0x20) = fn_80226BC4(&p, inputRoom);
    drawRoom=inputRoom;
    *(u16*)(object + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), inputRoom, *(s32*)(object + 0x20));
    u16 kind = *(u16*)(object + 0x24);
    if (kind == 0x19c || kind == 0x19d) {
        if (kind == 0x19d) {
            ret=inputRoom;
            ret &= 0xfe;
            JGeometry::TVec2<f32> q;
            q.y = coords->y;
            q.x = coords->x;
            object=(char*)lbl_8053AC98;
            *(s32*)(object + 0x20) = fn_80226BC4(&q, ret);
            inputRoom = *(s32*)(object + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), drawRoom, inputRoom, 0x19f);
            inputRoom = fn_802D4C10(fn_802D6A9C(), drawRoom, (u16)*(s32*)(object + 0x20));
            if (inputRoom != -1) {
                fn_802D7D00(fn_802D6A9C(), drawRoom, inputRoom, 1);
            }
            JGeometry::TVec2<f32> r;
            r.y = coords->y;
            r.x = coords->x - lbl_80540780;
            object=(char*)lbl_8053AC98;
            *(s32*)(object + 0x20) = fn_80226BC4(&r, ret);
            inputRoom = *(s32*)(object + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), drawRoom, inputRoom, 0x19e);
            inputRoom = fn_802D4C10(fn_802D6A9C(), drawRoom, (u16)*(s32*)(object + 0x20));
            if (inputRoom != -1) {
                fn_802D7D00(fn_802D6A9C(), drawRoom, inputRoom, 1);
            }
        } else {
            ret=inputRoom;
            ret &= 0xfe;
            JGeometry::TVec2<f32> q;
            q.y = coords->y;
            q.x = coords->x;
            object=(char*)lbl_8053AC98;
            *(s32*)(object + 0x20) = fn_80226BC4(&q, ret);
            inputRoom = *(s32*)(object + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), drawRoom, inputRoom, 0x19e);
            inputRoom = fn_802D4C10(fn_802D6A9C(), drawRoom, (u16)*(s32*)(object + 0x20));
            if (inputRoom != -1) {
                fn_802D7D00(fn_802D6A9C(), drawRoom, inputRoom, 1);
            }
            JGeometry::TVec2<f32> r;
            r.y = coords->y;
            r.x = lbl_80540780 + coords->x;
            object=(char*)lbl_8053AC98;
            *(s32*)(object + 0x20) = fn_80226BC4(&r, ret);
            inputRoom = *(s32*)(object + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), drawRoom, inputRoom, 0x19f);
            inputRoom = fn_802D4C10(fn_802D6A9C(), drawRoom, (u16)*(s32*)(object + 0x20));
            if (inputRoom != -1) {
                fn_802D7D00(fn_802D6A9C(), drawRoom, inputRoom, 1);
            }
        }
        fn_80230FD0(0, 0x30007);
        ret = 1;
    }
    return ret;
}
#pragma opt_propagation reset
extern "C" u8 fn_8023F264(s32 i);
extern "C" u8 fn_80303750(s32 i);
extern "C" u8 fn_8022C8EC(s32 i);
extern "C" BOOL fn_8029E508(char* self, const JGeometry::TVec2<f32>* pos, void* p3, u32 room) {
    u32 area = room;
    BOOL found;
    s32 i;
    JGeometry::TVec2<f32> p;
    p.y = pos->y;
    p.x = pos->x;
    *(s32*)(self + 0x20) = fn_80226BC4(&p, area);
    *(u16*)(self + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), area, *(s32*)(self + 0x20));
    JGeometry::TVec3<f32> v = *(JGeometry::TVec3<f32>*)fn_8023E724(p3);
    if (*(u16*)(self + 0x24) == 0x19c || *(u16*)(self + 0x24) == 0x19d) {
        found = FALSE;
        if (*((u8*)lbl_8053AAF8 + 0x7e) == 1) {
            for (i = 0; i < 4; i++) {
                if ((bool)(*((u8*)lbl_8053AAF8 + 0x82) & (u8)(1 << i)) == TRUE) {
                    if (fn_8023F264(i) == TRUE && fn_80303750(i) == TRUE && fn_8022C8EC(i) == TRUE) {
                        found = TRUE;
                    }
                }
            }
        } else if (fn_80303750(0) == TRUE && fn_8022C8EC(0) == TRUE) {
            found = TRUE;
        }
        if (!found) {
        if (*(u16*)(self + 0x24) == 0x19d) {
            s32 idx = *(s32*)(self + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), area, idx, 0x19f);
            s32 n = fn_802D4C10(fn_802D6A9C(), area, (u16)idx);
            if (n != -1) {
                fn_802D7D00(fn_802D6A9C(), area, n, 1);
            }
            v.x = pos->x - 16.0f;
            v.y = pos->y;
            v.z = 0.0f;
            JGeometry::TVec2<f32> q;
            q.x = v.x;
            q.y = v.y;
            void* mgr = lbl_8053AC98;
            *(s32*)((char*)mgr + 0x20) = fn_80226BC4(&q, area & 0xfe);
            s32 idx2 = *(s32*)((char*)mgr + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), area, idx2, 0x19e);
            s32 n2 = fn_802D4C10(fn_802D6A9C(), area, (u16)*(s32*)((char*)mgr + 0x20));
            if (n2 != -1) {
                fn_802D7D00(fn_802D6A9C(), area, n2, 1);
            }
        } else {
            s32 idx = *(s32*)(self + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), area, idx, 0x19e);
            s32 n = fn_802D4C10(fn_802D6A9C(), area, (u16)idx);
            if (n != -1) {
                fn_802D7D00(fn_802D6A9C(), area, n, 1);
            }
            v.x = 16.0f + pos->x;
            v.y = pos->y;
            v.z = 0.0f;
            JGeometry::TVec2<f32> q;
            q.x = v.x;
            q.y = v.y;
            void* mgr = lbl_8053AC98;
            *(s32*)((char*)mgr + 0x20) = fn_80226BC4(&q, area & 0xfe);
            s32 idx2 = *(s32*)((char*)mgr + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), area, idx2, 0x19f);
            s32 n2 = fn_802D4C10(fn_802D6A9C(), area, (u16)*(s32*)((char*)mgr + 0x20));
            if (n2 != -1) {
                fn_802D7D00(fn_802D6A9C(), area, n2, 1);
            }
        }
        fn_80230FD0((s32)p3, 0x30007);
        } else {
            fn_80230FD0((s32)p3, 0x30017);
        }
        return TRUE;
    }
    return FALSE;
}

extern "C" u16 fn_802F9908(void* mgr, u32 room, s32 idx);
#pragma opt_propagation off
extern "C" u32 fn_8029E888(char* self, const volatile JGeometry::TVec2<f32>* pos, void* p3, u32 room) {
    f32 x;
    f32 y;
    y = pos->y;
    x = pos->x;
    JGeometry::TVec2<f32> p;
    p.y = y;
    p.x = x;
    *(s32*)(self + 0x20) = fn_80226BC4(&p, room);
    *(u16*)(self + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, *(s32*)(self + 0x20));
    JGeometry::TVec3<f32> v = *(JGeometry::TVec3<f32>*)fn_8023E724(p3);
    return *(u16*)(self + 0x24) == 0x30;
}
#pragma opt_propagation reset
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

#pragma opt_common_subs on
extern "C" void fn_8029E9EC(void* p, const JGeometry::TVec2<f32>* __restrict pos, s32 room, u32 param_4, s32 param_5, u8 param_6) {
    void* object=p;
    JGeometry::TVec2<f32> v0;
    v0.y=pos->y;
    v0.x=pos->x;
    *(s32*)((u8*)object + 0x20) = fn_80226BC4(&v0, room);
    *(u16*)((u8*)object + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, *(s32*)((u8*)object + 0x20));
    if (param_5 == 0) {
        if (!(((u16)param_4 < 0x21 || (u16)param_4 > 0x25) && (u16)(param_4 - 0x26) > 1 && (u16)param_4 != 0x36 && (u16)param_4 != 0x37)) {
            JGeometry::TVec2<f32> v2;
            u32 off = (param_6 & 0xff) * 8;
            const f32* __restrict table=(const f32*)lbl_8046C508;
            v2.y=pos->y+table[off/4+1];
            v2.x=pos->x+table[off/4];
            *(s32*)((u8*)object + 0x20) = fn_80226BC4(&v2, room);
            *(u16*)((u8*)object + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, *(s32*)((u8*)object + 0x20));
            param_4=*(u16*)((u8*)object + 0x24);
            s32 tile;
            void* mgr;
            JGeometry::TVec2<f32> t;
            t.y=pos->y; t.x=pos->x;
            mgr=lbl_8053AC98;
            *(s32*)((u8*)mgr+0x20)=fn_80226BC4(&t,room&0xfe);
            tile=*(s32*)((u8*)mgr+0x20);
            fn_802D782C(fn_802D6A9C(),1);
            fn_802F9974(*(void**)(lbl_8053AB10+0x20),room,tile,(u16)param_4);
            tile=fn_802D4C10(fn_802D6A9C(),room,(u16)*(s32*)((u8*)mgr+0x20));
            if(tile!=-1) fn_802D7D00(fn_802D6A9C(),room,tile,1);
        } else {
            fn_8029E9EC_sub(pos,room,param_4);
        }
    } else {
        fn_8029E9EC_sub(pos, room, param_4);
    }
}
#pragma opt_common_subs reset
extern "C" void fn_802D7BE8(void* mgr, s32 room, u32 value, s32 x);
extern "C" u8 lbl_8046C4C8[];
extern "C" void fn_8029EC84(void* p, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6) {
    u32 room = p3 + p4;
    s32 idx = p2;
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, (u16)p6);
    if ((idx & 0x100) != ((idx - 0x10) & 0x100)) {
        idx -= 0x110;
    } else {
        idx -= 0x10;
    }
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, (u16)p5);
    void* mgr = fn_802D6A9C();
    u32 col = (u32)p3;
    u32 val = *(u32*)(lbl_8046C4C8 + (fn_802D4C10(mgr, p3, (u16)p2) & ~3));
    s32 kind = (u16)p5;
    switch (kind) {
    case 0:
    default:
        fn_802D7BE8(fn_802D6A9C(), col, val, 1);
        return;
    case 0x18: case 0x19: case 0x1a: case 0x1b:
    case 0x1c: case 0x1d: case 0x1e: case 0x1f:
        fn_802D7BE8(fn_802D6A9C(), p3, val, kind - 0x16);
        return;
    case 0xa0: case 0xa1: case 0xa2: case 0xa3: case 0xfff:
        fn_802D7BE8(fn_802D6A9C(), col, val, kind - 0x96);
        return;
    }
}

#pragma opt_propagation off
extern "C" u32 fn_8029EDB8(u8* self,JGeometry::TVec3<f32>* pos,s32 h,s32 idx,JGeometry::TVec3<f32>* out) {
s32 result=0;
if(pos->z<lbl_80540788) {
void* mgr=fn_802D6A9C();
s32 room=idx;
JGeometry::TBox2f* src;
if(idx<8)src=(JGeometry::TBox2f*)((u8*)mgr+0xcc);else src=(JGeometry::TBox2f*)((u8*)mgr+0xdc);
JGeometry::TVec3<f32> p;
JGeometry::TBox2f base; base=*src;
f32 half=lbl_80540780;
f32 startX=pos->x-half;
p.y=pos->y-half;p.z=pos->z;
void* created;
for(s32 row=0;row<3;row++) {
p.x=startX;
for(s32 col=0;col<3;col++) {
s32 x=(s32)(p.x-base.i.x),y=(s32)(p.y-base.i.y);
if(x<0)x=0;else if(x>=512)x=511;
if(y<0)y=0;else if(y>=512)y=511;
s32 cell=((y&0x100)<<1)|(x&0x100)|(y&0xf0)|((x>>4)&0xf);
u32 tile=fn_802F9908(*(void**)(lbl_8053AB10+0x20),room,cell);
JGeometry::TVec3<f32> center;
fn_80226CA8(cell,room,&center);
if(tile>=0x40&&tile<=0x44) {
 if(tile==0x41) {
 WaveLiftRetile(&p, room, 0x12, 0);
 s32 count=*(s32*)((u8*)fn_801F856C()+0x1008);
 for(s32 i=0;i<count;i++) {
 u8* a=*(u8**)((u8*)fn_801F856C()+8+i*4);
 if(a&&*(u32*)(a+0x1a0)==0x54424f32&&idx==*(s32*)(a+4)){
 JGeometry::TVec3<f32> v=*(JGeometry::TVec3<f32>*)(a+0xc);
 JGeometry::TVec2<f32> q;q.x=v.x;q.y=v.y;
 if(cell==fn_80226BC4(&q,idx)){((Actor*)a)->detach();break;}
 }
 }
 } else if(tile==0x43) {WaveLiftRetile(&p, room, 0x50, 0);}else{WaveLiftRetile(&p, room, 0x11, 1);}
 { void* handle=Actor_CreateByID(fn_801F856C(),0x5455424f,room,(JGeometry::TVec2<f32>*)&p,tile-0x40,-1,-1); created=handle; ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),handle); if(actor)actor->activate(); }
 fn_80230FD0(h,0x20025);Actor_CreateByID(fn_801F856C(),0x424c5a45,room,(JGeometry::TVec2<f32>*)&p,15,-1,-1);
} else if(tile>=0x45&&tile<=0x49) {
 if(tile==0x46){WaveLiftRetile(&p, room, 0x14, 1);}else if(tile==0x48){WaveLiftRetile(&p, room, 0x52, 1);}else{WaveLiftRetile(&p, room, 0x15, 1);}
 { void* handle=Actor_CreateByID(fn_801F856C(),0x5455424f,room,(JGeometry::TVec2<f32>*)&p,*(u16*)(self+0x24)-0x45,-1,-1); created=handle; ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),handle); if(actor)actor->activate(); }
 fn_80230FD0(h,0x20025);Actor_CreateByID(fn_801F856C(),0x424c5a45,room,(JGeometry::TVec2<f32>*)&p,15,-1,-1);
} else if(tile==0x69) {
 WaveLiftRetile(&p, room, 0x7a, 1);{ void* handle=Actor_CreateByID(fn_801F856C(),0x47524153,room,(JGeometry::TVec2<f32>*)&p,0,-1,-1); created=handle; ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),handle); if(actor)actor->activate(); }
 fn_80458880(lbl_8053AF80,3,-1);Actor_CreateByID(fn_801F856C(),0x424c5a45,room,(JGeometry::TVec2<f32>*)&p,15,-1,-1);
} else if(tile==0x68) {WaveLiftRetile(&p, room, 0x12, 1);{ void* handle=Actor_CreateByID(fn_801F856C(),0x47524153,room,(JGeometry::TVec2<f32>*)&p,0,-1,-1); created=handle; ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),handle); if(actor)actor->activate(); }Actor_CreateByID(fn_801F856C(),0x424c5a45,room,(JGeometry::TVec2<f32>*)&p,15,-1,-1);
} else if(tile==0x6a) {WaveLiftRetile(&p, room, 0x50, 1);{ void* handle=Actor_CreateByID(fn_801F856C(),0x47524153,room,(JGeometry::TVec2<f32>*)&p,0,-1,-1); created=handle; ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),handle); if(actor)actor->activate(); }Actor_CreateByID(fn_801F856C(),0x424c5a45,room,(JGeometry::TVec2<f32>*)&p,15,-1,-1);
} else if(tile==0x70||tile==0x75||tile==0x6b) {
 WaveLiftRetile(&p, room, 0x79, 1);
 if(tile==0x70)created=Actor_CreateByID(fn_801F856C(),0x47524153,room,(JGeometry::TVec2<f32>*)&p,0,-1,-1);
 else if(tile==0x75)created=Actor_CreateByID(fn_801F856C(),0x47524153,room,(JGeometry::TVec2<f32>*)&p,1,-1,-1);
 else if(tile==0x6b) {
 if(fn_802D6AC4(fn_802D6A9C(),*(s32*)(self+0x20)))created=Actor_CreateByID(fn_801F856C(),0x47524153,room,(JGeometry::TVec2<f32>*)&p,2,-1,-1);
 else {created=Actor_CreateByID(fn_801F856C(),0x47524153,room,(JGeometry::TVec2<f32>*)&p,3,-1,-1);fn_802D6B24(fn_802D6A9C(),*(s32*)(self+0x20),1);}
 }
 {ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),created);if(actor)actor->activate();}
 Actor_CreateByID(fn_801F856C(),0x424c5a45,room,(JGeometry::TVec2<f32>*)&p,15,-1,-1);
} else if(tile==0x74||tile==0x146) {
 WaveLiftRetile(&p, room, 0x7d, 1);{ void* handle=Actor_CreateByID(fn_801F856C(),0x47524153,room,(JGeometry::TVec2<f32>*)&p,0x100000,-1,-1); created=handle; ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),handle); if(actor)actor->activate(); }Actor_CreateByID(fn_801F856C(),0x424c5a45,room,(JGeometry::TVec2<f32>*)&p,15,-1,-1);
} else if(tile==0x71) {
 WaveLiftRetile(&p, room, 0x7b, 1);{ void* handle=Actor_CreateByID(fn_801F856C(),0x424f5244,room,(JGeometry::TVec2<f32>*)&p,0,-1,-1); created=handle; ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),handle); if(actor)actor->activate(); }Actor_CreateByID(fn_801F856C(),0x424c5a45,room,(JGeometry::TVec2<f32>*)&p,15,-1,-1);
} else if(tile==0x81) {
 WaveLiftRetile(&p, room, 0x9d, 1);fn_80230FD0(h,0x20025);
 if(idx>=8){JGeometry::TVec3<f32> v;v.x=lbl_8054078C+center.x;v.y=lbl_8054078C+center.y;v.z=lbl_80540784;Actor_CreateByID(fn_801F856C(),0x4b4d5249,room,(JGeometry::TVec2<f32>*)&v,0,-1,-1);}
 else{fn_8013CC50(room,(JGeometry::TVec2<f32>*)pos,0xf9,1,0,0,0,1,lbl_80540790);fn_8013CC50(room,(JGeometry::TVec2<f32>*)pos,0xfa,1,0,0,0,1,lbl_80540790);}
} else if(tile==0x90) {
 WaveLiftRetile(&p, room, 0x91, 1);fn_80230FD0(h,0x20025);fn_8013CC50(room,(JGeometry::TVec2<f32>*)pos,0x24a,1,0,0,0,1,lbl_80540790);fn_8013CC50(room,(JGeometry::TVec2<f32>*)pos,0x24b,1,0,0,0,1,lbl_80540790);
} else if(tile==0x91||tile==0x22e) {
 WaveLiftRetile(&p, room, 0x92, 1);fn_80230FD0(h,0x20025);fn_8013CC50(room,(JGeometry::TVec2<f32>*)pos,0x24a,1,0,0,0,1,lbl_80540790);fn_8013CC50(room,(JGeometry::TVec2<f32>*)pos,0x24b,1,0,0,0,1,lbl_80540790);
} else if(tile==1) {
 WaveLiftRetile(&p, room, 0x3e0, 1);fn_80230FD0(h,0x20025);
 if(idx>=8){JGeometry::TVec3<f32> v;v.x=lbl_8054078C+center.x;v.y=lbl_8054078C+center.y;v.z=lbl_80540784;Actor_CreateByID(fn_801F856C(),0x4b4d5249,room,(JGeometry::TVec2<f32>*)&v,0,-1,-1);}
 else{fn_8013CC50(room,(JGeometry::TVec2<f32>*)&center,0xf9,1,0,0,0,1,lbl_80540790);fn_8013CC50(room,(JGeometry::TVec2<f32>*)&center,0xfa,1,0,0,0,1,lbl_80540790);}
} else if(tile==0x9b||tile==0x9c) {
 JGeometry::TVec3<f32> v;fn_80226CA8(cell,room,&v);*out=v;result=1;
 if(tile==0x9b)v.y-=lbl_80540780;
 else if(tile==0x9c){v.x-=lbl_80540780;v.y-=lbl_80540780;}
 fn_8029E050(self,(JGeometry::TVec2<f32>*)&v,idx,0x6e,0x6f,0x7e,0x7f);
 JGeometry::TVec3<f32> effect;effect.x=lbl_80540780+v.x;effect.y=lbl_80540794+v.y;effect.z=lbl_80540784;
 fn_8013CC50(room,(JGeometry::TVec2<f32>*)&effect,0x60,0,0,0,0,1,lbl_80540790);
 s32 next=idx+(idx<8?1:8), c=*(s32*)(self+0x20);
 fn_802D782C(fn_802D6A9C(),1);
 fn_802F9974(*(void**)(lbl_8053AB10+0x20),next,c,0x6c);
 s32 n=fn_802D4C10(fn_802D6A9C(),next,(u16)c);
 if(n!=-1)fn_802D7D00(fn_802D6A9C(),next,n,1);
 c++;if(!(c&15))c+=0xf0;
 fn_802D782C(fn_802D6A9C(),1);
 fn_802F9974(*(void**)(lbl_8053AB10+0x20),next,c,0x6d);
 n=fn_802D4C10(fn_802D6A9C(),next,(u16)c);
 if(n!=-1)fn_802D7D00(fn_802D6A9C(),next,n,1);
 Actor_CreateByID(fn_801F856C(),0x53454e32,room,(JGeometry::TVec2<f32>*)&v,0x3c00,-1,-1);
 fn_8013CC50(room,(JGeometry::TVec2<f32>*)pos,0x24a,1,0,0,0,1,lbl_80540790);fn_8013CC50(room,(JGeometry::TVec2<f32>*)pos,0x24b,1,0,0,0,1,lbl_80540790);
}
p.x+=half;
}
p.y+=half;
}
}
return result;
}

#pragma opt_propagation reset
extern "C" u32 fn_802A01F0(char* self, const volatile JGeometry::TVec2<f32>* pos, void* p3, u32 room) {
    f32 x;
    f32 y;
    y = pos->y;
    x = pos->x;
    JGeometry::TVec2<f32> p;
    p.y = y;
    p.x = x;
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

#pragma opt_propagation off
extern "C" s32 fn_802A02A8(char* self_, const JGeometry::TVec2<f32>* pos_, void* p3_, s32 room) {
    int result;
    void* p3 = p3_;
    char* self = self_;
    s32 idx;
    const JGeometry::TVec2<f32>* pos = pos_;
    int effect;
    s32 n;
    s32 count;
    s32 i;
    s32 off;
    Actor* a;
    char* mgr;
    JGeometry::TVec2<f32> p;
    JGeometry::TVec2<f32> t;
    t.y = pos->y;
    t.x = pos->x;
    *(s32*)(self + 0x20) = fn_80226BC4(&t, room);
    *(u16*)(self + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, *(s32*)(self + 0x20));
    result = -1;
    effect = 0x79;
    switch (*(u16*)(self + 0x24)) {
    case 0x69: {
        JGeometry::TVec2<f32> q;
        q.y = pos->y;
        q.x = pos->x;
        self = (char*)lbl_8053AC98;
        *(s32*)(self + 0x20) = fn_80226BC4(&q, room & 0xfe);
        idx = *(s32*)(self + 0x20);
        fn_802D782C(fn_802D6A9C(), 1);
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, 0x7a);
        n = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)(self + 0x20));
        if (n != -1) {
            fn_802D7D00(fn_802D6A9C(), room, n, 1);
            fn_80230FD0((s32)p3, 0x20007);
            fn_80458880(lbl_8053AF80, 3, -1); return 0; }
    }
    case 0x16:
    case 0x17:
        u8 reward = fn_802A0800(self, p3, room);
        switch (reward) { case 1: return 0x25; default: return -1; }
    case 0x68: {
        JGeometry::TVec2<f32> q;
        q.y = pos->y;
        q.x = pos->x;
        self = (char*)lbl_8053AC98;
        *(s32*)(self + 0x20) = fn_80226BC4(&q, room & 0xfe);
        idx = *(s32*)(self + 0x20);
        fn_802D782C(fn_802D6A9C(), 1);
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, 0x12);
        n = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)(self + 0x20));
        if (n != -1) {
            fn_802D7D00(fn_802D6A9C(), room, n, 1);
            fn_80230FD0((s32)p3, 0x20007);
            return 0;
        }
    }
    case 0x70: result = 0; break;
    case 0x75: result = 1; break;
    case 0x6a: {
        JGeometry::TVec2<f32> q;
        q.y = pos->y;
        q.x = pos->x;
        self = (char*)lbl_8053AC98;
        *(s32*)(self + 0x20) = fn_80226BC4(&q, room & 0xfe);
        idx = *(s32*)(self + 0x20);
        fn_802D782C(fn_802D6A9C(), 1);
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, 0x50);
        n = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)(self + 0x20));
        if (n != -1) {
            fn_802D7D00(fn_802D6A9C(), room, n, 1);
            fn_80230FD0((s32)p3, 0x20007);
            return 0;
        }
    }
    case 0x6b: result = 3; break;
    case 0x72:
    case 0x82: result = 5; if (*(u16*)(self + 0x24) == 0x72) effect = 0x7c; else effect = 0x83; break;
    case 0x5f: result = 0x27; effect = 0x83; break;
    case 0x71: result = 7; effect = 0x7b; break;
    case 0x40: result = 0x18; effect = 0x11; break;
    case 0x41: result = 0x19; effect = 0x12; break;
    case 0x42: result = 0x1a; effect = 0x11; break;
    case 0x43: result = 0x1b; effect = 0x50; break;
    case 0x44: result = 0x1c; effect = 0x11; break;
    case 0x45: result = 0x1d; effect = 0x15; break;
    case 0x46: result = 0x1e; effect = 0x14; break;
    case 0x47: result = 0x1f; effect = 0x15; break;
    case 0x48: result = 0x20; effect = 0x52; break;
    case 0x49: result = 0x21; effect = 0x15; break;
    case 0x4e: result = 0x22; effect = 0x11; break;
    case 0x4f: result = 0x23; effect = 0x11; break;
    }
    if (result != -1 && result != 0x25 && result != 0xc) {
        if (result == 0x19) {
        JGeometry::TVec2<f32> q;
        q.y = pos->y;
        q.x = pos->x;
        mgr = (char*)lbl_8053AC98;
        *(s32*)(mgr + 0x20) = fn_80226BC4(&q, room & 0xfe);
        idx = *(s32*)(mgr + 0x20);
        fn_802D782C(fn_802D6A9C(), 1);
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, effect);
        n = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)(mgr + 0x20));
        if (n != -1) {
            fn_802D7D00(fn_802D6A9C(), room, n, 1);
            fn_80230FD0((s32)p3, 0x20007);
        }

            count = *(s32*)((char*)fn_801F856C() + 0x1008);
            for (i = 0, off = 0; i < count; off += 4, i++) {
                a = *(Actor**)((char*)fn_801F856C() + off + 8);
                if (a != 0 && *(u32*)((char*)a + 0x1a0) == 0x54424f32 && room == *(s32*)((char*)a + 4)) {
                    JGeometry::TVec3<f32> ap = *(JGeometry::TVec3<f32>*)((char*)a + 0xc);
                    p.x = ap.x; p.y = ap.y;
                    if (*(s32*)(self + 0x20) == fn_80226BC4(&p, room)) {
                        a->detach();
                        break;
                    }
                }
            }
        } else {
        JGeometry::TVec2<f32> q;
        q.y = pos->y;
        q.x = pos->x;
        mgr = (char*)lbl_8053AC98;
        *(s32*)(mgr + 0x20) = fn_80226BC4(&q, room & 0xfe);
        idx = *(s32*)(mgr + 0x20);
        fn_802D782C(fn_802D6A9C(), 1);
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, effect);
        n = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)(mgr + 0x20));
        if (n != -1) {
            fn_802D7D00(fn_802D6A9C(), room, n, 1);
            fn_80230FD0((s32)p3, 0x20007);
        }

        }
    }
    return result;
}
#pragma opt_propagation reset
extern "C" u8 fn_8022F514(void* a);
extern "C" s32 fn_8022F3DC(void* a);
extern "C" s32 fn_802373EC(s32 a);
extern "C" s32 fn_8022EA0C(void* a);
extern "C" u8 fn_802308E0(s32);
extern "C" u8 fn_8023077C(void);
extern "C" void fn_8037AE30(void*);
extern void* lbl_8053AD70;
extern "C" void fn_802372F8(void*,s32,s32);
extern "C" s32 fn_8023DE58(void*);
extern "C" void fn_80230498(void*,void*,s32,s32,s32,s32,s32);
extern f32 lbl_80540798;

#pragma opt_propagation off
extern "C" u32 fn_802A0800(char* self, void* p3, u32 room) {
    JGeometry::TVec3f pos;
    JGeometry::TVec3f effectPos;
    s32 player=(s32)p3;
    s32 roomIndex=(s32)room;
    void* linkedPlayer=p3;
    s32 root=(s32)linkedPlayer;
    if(fn_8022F514((void*)linkedPlayer))root=fn_8022F3DC((void*)linkedPlayer);
    pos=*(JGeometry::TVec3f*)fn_8023E724((void*)linkedPlayer);
    u8 layer=8;
    if(roomIndex<8)layer=1;
    s32 kind=fn_802373EC(root);
    s32 tileRoom=roomIndex+layer;
    u32 tile=fn_802F9908(*(void**)(lbl_8053AB10+0x20),tileRoom,*(s32*)(self+0x20));
    if(tile==14)return 0;
    if(player!=fn_8022EA0C((void*)linkedPlayer))return 0;
    if(tile!=0 || kind!=0) {
        if(*((u8*)lbl_8053AAF8+0x7e)==1) {
            if(!fn_802308E0(root))return 0;
        } else {
            if(!fn_8023077C())return 0;
            fn_8037AE30(lbl_8053AD70);
        }
    }
    if(kind!=0) {
        if(kind>=0 && kind<14) {
        s32 idx=*(s32*)(self+0x20);
        fn_802F9974(*(void**)(lbl_8053AB10+0x20),tileRoom,idx,14);
        s32 next=idx-16;
        if((idx&0x100)!=(next&0x100))next=idx-0x110;
        fn_802F9974(*(void**)(lbl_8053AB10+0x20),tileRoom,next,14);
        s32 bits=*(u32*)(lbl_8046C4C8+(fn_802D4C10(fn_802D6A9C(),roomIndex,(u16)idx)&~3));
        fn_802D7BE8(fn_802D6A9C(),roomIndex,bits,1);
        if(tile==0) {
            Actor_CreateByID(fn_801F856C(),0x49544d53,roomIndex,(JGeometry::TVec2f*)&pos,((*(s32*)(self+0x20)<<16)+((((player<<12)+(layer<<8))+kind)+16)),-1,-1);
        } else {
            Actor_CreateByID(fn_801F856C(),0x49544d53,roomIndex,(JGeometry::TVec2f*)&pos,((*(s32*)(self+0x20)<<16)+((player<<12)+(layer<<8)+kind)),-1,-1);
        }

        }
    } else {
        s32 idx=*(s32*)(self+0x20);
        fn_802F9974(*(void**)(lbl_8053AB10+0x20),tileRoom,idx,0);
        s32 next=idx-16;
        if((idx&0x100)!=(next&0x100))next=idx-0x110;
        fn_802F9974(*(void**)(lbl_8053AB10+0x20),tileRoom,next,0);
        s32 bits=*(u32*)(lbl_8046C4C8+(fn_802D4C10(fn_802D6A9C(),roomIndex,(u16)idx)&~3));
        fn_802D7BE8(fn_802D6A9C(),roomIndex,bits,1);

    }
    effectPos.x=1.0f+pos.x;
    effectPos.y=pos.y-12.0f;
    effectPos.z=pos.z;
    s32 item=0;
    s32 power;
    switch((s32)tile) {
    case 0x28:item=1;power=0x30;break;
    case 0x29:item=2;power=0x31;break;
    case 0x2a:item=3;power=0x32;break;
    case 0x2b:item=4;power=0x33;break;
    case 0x2c:item=5;power=0x34;break;
    case 0x2d:item=6;power=0x35;break;
    case 0x2e:item=7;power=0x36;break;
    case 0x2f:item=8;power=0x37;break;
    case 0xb0:item=9;power=0x38;break;
    case 0xb1:item=10;power=0x39;break;
    case 0xb2:item=11;power=0x1000a;break;
    case 0xb3:item=12;power=0x1000b;break;
    case 0x100f:item=13;power=0x1000c;break;
    case 0x30:case 0xb4:default:item=0;break;
    }
    if(item==0) {
        if(kind!=0) {
            fn_80230FD0((s32)linkedPlayer,0x2002c);
            fn_802372F8((void*)linkedPlayer,0,1);
            if(*((u8*)lbl_8053AAF8+0x7e)==1) {
                s32 spawnBits=player<<16;
                for(s32 i=0;i<4;i++,spawnBits+=0x1000) {
                    if(fn_8022F514((void*)i)==1 && root==fn_8022F3DC((void*)i)) {
                        s32 r=fn_8023DE58((void*)i);
                        Actor_CreateByID(fn_801F856C(),0x444d594b,r,(JGeometry::TVec2f*)&effectPos,spawnBits+0xd5,-1,-1);
                    } else if(i==root) {
                        s32 r=fn_8023DE58((void*)i);
                        Actor_CreateByID(fn_801F856C(),0x444d594b,r,(JGeometry::TVec2f*)&effectPos,spawnBits+0xd5,-1,-1);
                    }
                }
            } else {
                s32 spawnBits=player<<16;
                for(s32 i=0;i<4;i++,spawnBits+=0x1000) {
                    s32 r=fn_8023DE58((void*)i);
                    Actor_CreateByID(fn_801F856C(),0x444d594b,r,(JGeometry::TVec2f*)&effectPos,spawnBits+0xd5,-1,-1);
                }
            }
        } else fn_80458880(lbl_8053AF80,6,-1);
        return 0;
    }
    if(*((u8*)lbl_8053AAF8+0x7e)==1) {
        s32 spawnBits=0;
        s32 playerBits=player<<26;
        for(s32 i=0;i<4;i++,spawnBits+=0x1000000) {
            pos=*(JGeometry::TVec3f*)fn_8023E724((void*)i);
            effectPos.x=1.0f+pos.x;
    effectPos.y=pos.y-12.0f;
    effectPos.z=pos.z;
            if(fn_8022F514((void*)i)==1 && root==fn_8022F3DC((void*)i)) {
                if(i==player) {
                    s32 r=fn_8023DE58((void*)i);
                    Actor_CreateByID(fn_801F856C(),0x494d5550,r,(JGeometry::TVec2f*)&effectPos,(spawnBits+playerBits)+(0x10000000+power),-1,-1);
                } else {
                    s32 r=fn_8023DE58((void*)i);
                    Actor_CreateByID(fn_801F856C(),0x494d5550,r,(JGeometry::TVec2f*)&effectPos,(spawnBits+playerBits)+(0x30000000+power),-1,-1);
                }
                fn_80230498((void*)i,&pos,0xe9,255,-128,-128,1);
            } else if(i==root) {
                if(i==player) {
                    s32 r=fn_8023DE58((void*)i);
                    Actor_CreateByID(fn_801F856C(),0x494d5550,r,(JGeometry::TVec2f*)&effectPos,power+(spawnBits+playerBits+0x10000000),-1,-1);
                } else {
                    s32 r=fn_8023DE58((void*)i);
                    Actor_CreateByID(fn_801F856C(),0x494d5550,r,(JGeometry::TVec2f*)&effectPos,power+(spawnBits+playerBits+0x30000000),-1,-1);
                }
                fn_80230498((void*)i,&pos,0xe9,255,-128,-128,1);
            }
        }
    } else {
        s32 spawnBits=0;
        s32 playerBits=player<<26;
        for(s32 i=0;i<4;i++,spawnBits+=0x1000000) {
            pos=*(JGeometry::TVec3f*)fn_8023E724((void*)i);
            effectPos.x=1.0f+pos.x;
    effectPos.y=pos.y-12.0f;
    effectPos.z=pos.z;
            if(i==player) {
                s32 r=fn_8023DE58((void*)i);
                Actor_CreateByID(fn_801F856C(),0x494d5550,r,(JGeometry::TVec2f*)&effectPos,power+(spawnBits+playerBits+0x10000000),-1,-1);
            } else {
                s32 r=fn_8023DE58((void*)i);
                Actor_CreateByID(fn_801F856C(),0x494d5550,r,(JGeometry::TVec2f*)&effectPos,power+(spawnBits+playerBits+0x30000000),-1,-1);
            }
            fn_80230498((void*)i,&pos,0xe9,255,-128,-128,1);
        }
    }
    return 1;
}
#pragma opt_propagation reset
extern "C" void fn_802A1050(char* self, const volatile JGeometry::TVec2<f32>* pos) {
    JGeometry::TVec2<f32> p;
    f32 x, y;
    y = pos->y;
    x = pos->x;
    p.y = y;
    p.x = x;
    *(s32*)(self + 0x20) = fn_80226BC4(&p, 0);
    *(u16*)(self + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), 0, *(s32*)(self + 0x20));
    if (*(u16*)(self + 0x24) == 0x69 || *(u16*)(self + 0x24) == 0x68 || *(u16*)(self + 0x24) == 0x75 ||
        (u16)(*(u16*)(self + 0x24) - 0x6a) <= 1 || *(u16*)(self + 0x24) == 0x82 || *(u16*)(self + 0x24) == 0x5f ||
        (u16)(*(u16*)(self + 0x24) - 0x70) <= 3 || (u16)(*(u16*)(self + 0x24) - 0x40) <= 4 ||
        *(u16*)(self + 0x24) == 0xe5) {
        u16 kind = *(u16*)(self + 0x24);
        
        switch (kind) {
        case 0x72:
        case 0x73:
        case 0x82: {
            if (kind == 0x72 || kind == 0x73) {
                JGeometry::TVec2<f32> t;
                f32 x, y;
                y = pos->y;
                x = pos->x;
                t.y = y; t.x = x;
                self = (char*)lbl_8053AC98;
                *(s32*)(self + 0x20) = fn_80226BC4(&t, 0);
                int idx = *(s32*)(self + 0x20);
                fn_802D782C(fn_802D6A9C(), 1);
                fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), 0, idx, 0x7c);
                int n = (int)fn_802D4C10(fn_802D6A9C(), 0, (u16)*(s32*)(self + 0x20));
                if (n != -1) {
                    fn_802D7D00(fn_802D6A9C(), 0, n, 1);
                }
            } else {
                JGeometry::TVec2<f32> t;
                f32 x, y;
                y = pos->y;
                x = pos->x;
                t.y = y; t.x = x;
                self = (char*)lbl_8053AC98;
                *(s32*)(self + 0x20) = fn_80226BC4(&t, 0);
                int idx = *(s32*)(self + 0x20);
                fn_802D782C(fn_802D6A9C(), 1);
                fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), 0, idx, 0x83);
                int n = (int)fn_802D4C10(fn_802D6A9C(), 0, (u16)*(s32*)(self + 0x20));
                if (n != -1) {
                    fn_802D7D00(fn_802D6A9C(), 0, n, 1);
                }
            }
            u32 id = (u32)Actor_CreateByID(fn_801F856C(), 0x53544f4e, 0, (JGeometry::TVec2<f32>*)pos, 0, -1, -1);
            ActorVt* actor = (ActorVt*)fn_801F666C(fn_801F856C(), (void*)id);
            if (actor != 0) {
                actor->activate();
            }
            break;
        }
        case 0x5f: {
            JGeometry::TVec2<f32> t;
                f32 x, y;
                y = pos->y;
                x = pos->x;
                t.y = y; t.x = x;
            self = (char*)lbl_8053AC98;
            *(s32*)(self + 0x20) = fn_80226BC4(&t, 0);
            int idx = *(s32*)(self + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), 0, idx, 0x83);
            int n = (int)fn_802D4C10(fn_802D6A9C(), 0, (u16)*(s32*)(self + 0x20));
            if (n != -1) {
                fn_802D7D00(fn_802D6A9C(), 0, n, 1);
            }
            u32 id = (u32)Actor_CreateByID(fn_801F856C(), 0x59415349, 0, (JGeometry::TVec2<f32>*)pos, 0, -1, -1);
            ActorVt* actor = (ActorVt*)fn_801F666C(fn_801F856C(), (void*)id);
            if (actor != 0) {
                actor->activate();
            }
            break;
        }
        case 0xe5: {
            JGeometry::TVec2<f32> t;
                f32 x, y;
                y = pos->y;
                x = pos->x;
                t.y = y; t.x = x;
            void* mgr = lbl_8053AC98;
            *(s32*)((char*)mgr + 0x20) = fn_80226BC4(&t, 0);
            int idx = *(s32*)((char*)mgr + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), 0, idx, 0x9d);
            int n = (int)fn_802D4C10(fn_802D6A9C(), 0, (u16)*(s32*)((char*)mgr + 0x20));
            if (n != -1) {
                fn_802D7D00(fn_802D6A9C(), 0, n, 1);
            }
            fn_8013CC50(0, (JGeometry::TVec2<f32>*)pos, 0xf9, 1, 0, 0, 0, 1, lbl_80540790);
            fn_8013CC50(0, (JGeometry::TVec2<f32>*)pos, 0xfa, 1, 0, 0, 0, 1, lbl_80540790);
            u32 msg = 0x50045;
            ((WaveMsgSink*)((WaveOwner*)self)->mpSub)->post(&msg);
            break;
        }
        }
    }
}

extern "C" BOOL fn_802A1490(void* this_, const volatile JGeometry::TVec2<f32>* param_2) {
    f32 x;
    f32 y;
    y = param_2->y;
    x = param_2->x;
    JGeometry::TVec2<f32> tmp;
    tmp.y = y;
    tmp.x = x;
    *(u32*)((u8*)this_ + 0x20) = fn_80226BC4(&tmp, 0);
    *(u16*)((u8*)this_ + 0x24) = fn_802F9908(*(void**)((u8*)lbl_8053AB10 + 0x20), 0, *(u32*)((u8*)this_ + 0x20));
    if (lbl_8046CB88[*(u16*)((u8*)this_ + 0x24)] == 0) {
        return TRUE;
    }
    s32 kind = (u16)fn_8022461C((JGeometry::TVec2<f32>*)param_2, 0);
    if (kind == 0x22 && *(u8*)((u8*)fn_802D6A9C() + 0x170) == 0) {
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
extern "C" u8 fn_802A3164(char* self, JGeometry::TVec2<f32>* pos, s32 a, u32 room);
extern f32 lbl_80540790;
extern f32 lbl_8054079C;
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

#pragma opt_propagation off
extern "C" s32 fn_802A1844(char* self, const JGeometry::TVec2<f32>* pos, s32 param_3, s32 room) {
    s32 idx;
    void* mgr;
    s32 n;
    JGeometry::TVec2<f32> p;
    WaveCopyPos(p, pos->x, pos->y);
    *(s32*)(self + 0x20) = fn_80226BC4(&p, room);
    u32 r = room;
    *(u16*)(self + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, *(s32*)(self + 0x20));
    if ((room == 0 && *(u16*)(self + 0x24) >= 0x1b0 && *(u16*)(self + 0x24) <= 0x1cf) || *(u16*)(self + 0x24) == 0x231 || *(u16*)(self + 0x24) == 0x8a || *(u16*)(self + 0x24) == 0x79 || *(u16*)(self + 0x24) == 0x7b || *(u16*)(self + 0x24) == 0x7d) {
        if (*(u16*)(self + 0x24) == 0x231) {
            JGeometry::TVec2<f32> q;
            WaveCopyPos(q, pos->x, pos->y);
            mgr = lbl_8053AC98;
            *(s32*)((char*)mgr + 0x20) = fn_80226BC4(&q, room & 0xfe);
            idx = *(s32*)((char*)mgr + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), r, idx, 0x7a);
            n = fn_802D4C10(fn_802D6A9C(), r, (u16)*(s32*)((char*)mgr + 0x20));
            if (n != -1) {
                fn_802D7D00(fn_802D6A9C(), r, n, 1);
            }
        } else if (!((*(u16*)(self + 0x24) < 0x1b5 || *(u16*)(self + 0x24) > 0x1ba) && (u16)(*(u16*)(self + 0x24) - 0x1bc) > 1 && *(u16*)(self + 0x24) != 0x8a && (*(u16*)(self + 0x24) < 0x1c5 || *(u16*)(self + 0x24) > 0x1cd))) {
            JGeometry::TVec2<f32> q;
            WaveCopyPos(q, pos->x, pos->y);
            mgr = lbl_8053AC98;
            *(s32*)((char*)mgr + 0x20) = fn_80226BC4(&q, room & 0xfe);
            idx = *(s32*)((char*)mgr + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), r, idx, 0x83);
            n = fn_802D4C10(fn_802D6A9C(), r, (u16)*(s32*)((char*)mgr + 0x20));
            if (n != -1) {
                fn_802D7D00(fn_802D6A9C(), r, n, 1);
            }
        } else if (*(u16*)(self + 0x24) == 0x79 || *(u16*)(self + 0x24) == 0x7b || *(u16*)(self + 0x24) == 0x7d) {
            JGeometry::TVec2<f32> q;
            WaveCopyPos(q, pos->x, pos->y);
            mgr = lbl_8053AC98;
            *(s32*)((char*)mgr + 0x20) = fn_80226BC4(&q, room & 0xfe);
            idx = *(s32*)((char*)mgr + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), r, idx, 0x7c);
            n = fn_802D4C10(fn_802D6A9C(), r, (u16)*(s32*)((char*)mgr + 0x20));
            if (n != -1) {
                fn_802D7D00(fn_802D6A9C(), r, n, 1);
            }
        } else {
            JGeometry::TVec2<f32> q;
            WaveCopyPos(q, pos->x, pos->y);
            mgr = lbl_8053AC98;
            *(s32*)((char*)mgr + 0x20) = fn_80226BC4(&q, room & 0xfe);
            idx = *(s32*)((char*)mgr + 0x20);
            fn_802D782C(fn_802D6A9C(), 1);
            fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), r, idx, 0x7c);
            n = fn_802D4C10(fn_802D6A9C(), r, (u16)*(s32*)((char*)mgr + 0x20));
            if (n != -1) {
                fn_802D7D00(fn_802D6A9C(), r, n, 1);
            }
        }
        char* rng = (char*)lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        u32 bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        f32 f = *(f32*)&bits - 1.0f;
        if (f < 0.2f) {
            Actor_CreateByID(fn_801F856C(), 0x48415254, r, (JGeometry::TVec2<f32>*)pos, 0, -1, -1);
        }
        if (*(s32*)((char*)fn_802D6A9C() + 0x40) == 0x14) {
            return 3;
        }
        if (*(s32*)((char*)fn_802D6A9C() + 0x40) == 0x11 || *(s32*)((char*)fn_802D6A9C() + 0x40) == 0x18) {
            return 4;
        }
        if (!((*(u16*)(self + 0x24) < 0x1b5 || *(u16*)(self + 0x24) > 0x1ba) && (u16)(*(u16*)(self + 0x24) - 0x1bc) > 1 && (*(u16*)(self + 0x24) < 0x1c5 || *(u16*)(self + 0x24) > 0x1cd))) {
            return 2;
        }
        return 1;
    } else {
        if (*(s32*)((char*)fn_802D6A9C() + 0x4) == 4 && *(s32*)((char*)fn_802D6A9C() + 0x8) == 3) {
            return 8;
        }
        if ((*(s32*)((char*)fn_802D6A9C() + 0x4) == 1 && *(s32*)((char*)fn_802D6A9C() + 0x8) == 1 && *(u16*)(self + 0x24) == 0x270) || *(u16*)(self + 0x24) == 0x271 || *(u16*)(self + 0x24) == 0x361) {
            return 8;
        }
        if ((u16)(*(u16*)(self + 0x24) - 0x11) <= 2 || *(u16*)(self + 0x24) == 0x38 || *(u16*)(self + 0x24) == 0x3b || (u16)(*(u16*)(self + 0x24) - 0x50) <= 1 || *(u16*)(self + 0x24) == 0x78 || *(u16*)(self + 0x24) == 0x8f || (u16)(*(u16*)(self + 0x24) - 0x9d) <= 1 || *(u16*)(self + 0x24) == 0x1ae || *(u16*)(self + 0x24) == 0x1af) {
            return 8;
        }
        if (*(u16*)(self + 0x24) == 0x7c || *(u16*)(self + 0x24) == 0x83) {
            return 9;
        }
        return 0;
    }
}
#pragma opt_propagation reset
extern "C" s32 fn_802A1D44(char* self, const volatile JGeometry::TVec2<f32>* pos, s32 p3, u32 room) {
    s32 idx;
    s32 n;
    f32 x, y;
    y = pos->y;
    x = pos->x;
    JGeometry::TVec2<f32> p;
    p.y=y;
    p.x=x;
    *(s32*)(self + 0x20) = fn_80226BC4(&p, room);
    *(u16*)(self + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, *(s32*)(self + 0x20));
    s32 ret = 1;
    u16 kind = *(u16*)(self + 0x24);
    if (kind == 0x76) {
        JGeometry::TVec2<f32> q;
        f32 x,y;
        y=pos->y;
        x=pos->x;
        q.y=y;
        q.x=x;
        self = (char*)lbl_8053AC98;
        *(s32*)(self + 0x20) = fn_80226BC4(&q, room & 0xfe);
        idx = *(s32*)(self + 0x20);
        fn_802D782C(fn_802D6A9C(), 1);
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, 0x77);
        n = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)(self + 0x20));
        if (n != -1) {
            fn_802D7D00(fn_802D6A9C(), room, n, 1);
        }
        fn_80230FD0(p3, 0x20026);
    } else if (kind == 0x3a) {
        JGeometry::TVec2<f32> q;
        f32 x,y;
        y=pos->y;
        x=pos->x;
        q.y=y;
        q.x=x;
        self = (char*)lbl_8053AC98;
        *(s32*)(self + 0x20) = fn_80226BC4(&q, room & 0xfe);
        idx = *(s32*)(self + 0x20);
        fn_802D782C(fn_802D6A9C(), 1);
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, 0x3b);
        n = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)(self + 0x20));
        if (n != -1) {
            fn_802D7D00(fn_802D6A9C(), room, n, 1);
        }
        fn_80230FD0(p3, 0x20026);
    } else if (kind == 0x3f) {
        JGeometry::TVec2<f32> q;
        f32 x,y;
        y=pos->y;
        x=pos->x;
        q.y=y;
        q.x=x;
        self = (char*)lbl_8053AC98;
        *(s32*)(self + 0x20) = fn_80226BC4(&q, room & 0xfe);
        idx = *(s32*)(self + 0x20);
        fn_802D782C(fn_802D6A9C(), 1);
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, 0x3e);
        n = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)(self + 0x20));
        if (n != -1) {
            fn_802D7D00(fn_802D6A9C(), room, n, 1);
        }
        fn_80230FD0(p3, 0x20026);
    } else if (kind == 0x90) {
        JGeometry::TVec2<f32> q;
        f32 x,y;
        y=pos->y;
        x=pos->x;
        q.y=y;
        q.x=x;
        self = (char*)lbl_8053AC98;
        *(s32*)(self + 0x20) = fn_80226BC4(&q, room & 0xfe);
        idx = *(s32*)(self + 0x20);
        fn_802D782C(fn_802D6A9C(), 1);
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, 0x91);
        n = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)(self + 0x20));
        if (n != -1) {
            fn_802D7D00(fn_802D6A9C(), room, n, 1);
        }
        fn_80230FD0(p3, 0x50013);
    } else if (kind == 0x91 || kind == 0x22e) {
        JGeometry::TVec2<f32> q;
        f32 x,y;
        y=pos->y;
        x=pos->x;
        q.y=y;
        q.x=x;
        self = (char*)lbl_8053AC98;
        *(s32*)(self + 0x20) = fn_80226BC4(&q, room & 0xfe);
        idx = *(s32*)(self + 0x20);
        fn_802D782C(fn_802D6A9C(), 1);
        fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, 0x92);
        n = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)(self + 0x20));
        if (n != -1) {
            fn_802D7D00(fn_802D6A9C(), room, n, 1);
        }
        fn_80230FD0(p3, 0x50012);
    } else {
        if (fn_802A3164(self, (JGeometry::TVec2<f32>*)pos, p3, room) == 0) {
            ret = 0;
        }
    }
    return ret;
}

#pragma opt_common_subs off
static inline void WaveCutTile(const JGeometry::TVec2<f32>* pos, s32 room, u16 param) {
    void* mgr;
    s32 n;
    s32 tile;
    JGeometry::TVec2<f32> t;
    f32 y,x;
    y=pos->y;x=pos->x;t.y=y;t.x=x;
    mgr=lbl_8053AC98;
    *(s32*)((u8*)mgr+0x20)=fn_80226BC4(&t,room&0xfe);
    tile=*(s32*)((u8*)mgr+0x20);
    fn_802D782C(fn_802D6A9C(),1);
    fn_802F9974(*(void**)(lbl_8053AB10+0x20),room,tile,param);
    n=fn_802D4C10(fn_802D6A9C(),room,(u16)*(s32*)((u8*)mgr+0x20));
    if(n!=-1)fn_802D7D00(fn_802D6A9C(),room,n,1);
}
#pragma opt_common_subs reset
extern "C" s32 fn_80226AE0(JGeometry::TVec2<f32>*, s32);
extern "C" u8 fn_802D6AC4(void*, s32);
extern "C" void fn_802D6B24(void*, s32, s32);
extern "C" u8 fn_802D72BC(void*, s32);
extern "C" void fn_802D7310(void*, s32, s32);
extern "C" void fn_80226CA8(s32, u32, JGeometry::TVec3<f32>*);
extern "C" void fn_802CEC10(void*);
extern "C" u8 fn_802353AC(s32);
extern f32 lbl_8054078C;
#pragma opt_propagation off
#pragma opt_common_subs on
extern "C" void fn_802A20F0(char* self, const volatile JGeometry::TVec2<f32>* pos_, int who, int room, s32 param, s32 extra) {
    JGeometry::TVec2<f32>* pos=(JGeometry::TVec2<f32>*)pos_;
    JGeometry::TVec3<f32> center;
    u32 r=room;
    f32 x,y;
    y=pos_->y;x=pos_->x;
    JGeometry::TVec2<f32> p;
    p.y=y;p.x=x;
    *(s32*)(self+0x20)=fn_80226BC4(&p,r);
    *(u16*)(self+0x24)=fn_802F9908(*(void**)(lbl_8053AB10+0x20),r,*(s32*)(self+0x20));
    s32 handle=fn_80226AE0(pos,r);
if(*(u16*)(self+0x24)==105){void* id;WaveCutTile(pos,r,122);
id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param,-1,-1);
ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),id);if(actor)actor->activate();
fn_80458880(lbl_8053AF80,3,-1);}
else if(*(u16*)(self+0x24)==104){void* id;WaveCutTile(pos,r,18);
id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param,-1,-1);
ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),id);if(actor)actor->activate();
}
else if(*(u16*)(self+0x24)==106){void* id;WaveCutTile(pos,r,80);
id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param,-1,-1);
ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),id);if(actor)actor->activate();
}
else if(*(u16*)(self+0x24)==0x70||*(u16*)(self+0x24)==0x75||*(u16*)(self+0x24)==0x6b){void* id;
if(param==0x10000){
WaveCutTile(pos,r,90);

if(!fn_802D6AC4(fn_802D6A9C(),handle)){
if(*(u16*)(self+0x24)==0x6b){id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param+3,-1,-1);
}else{id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param,-1,-1);
}
ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),id);if(actor)fn_802CEC10(actor);

fn_802D6B24(fn_802D6A9C(),handle,1);
}
}else{
WaveCutTile(pos,r,121);

if(*(u16*)(self+0x24)==0x70){id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param,-1,-1);
}
else if(*(u16*)(self+0x24)==0x75){id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param+1,-1,-1);
}
else if(*(u16*)(self+0x24)==0x6b){
if(fn_802D6AC4(fn_802D6A9C(),handle)){id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param+4,-1,-1);
}
else{id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param+3,-1,-1);
fn_802D6B24(fn_802D6A9C(),handle,1);}
}
ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),id);if(actor)actor->activate();

}
}
else if(*(u16*)(self+0x24)==116){void* id;
if(param==0x10000){
WaveCutTile(pos,r,90);

if(!fn_802D6AC4(fn_802D6A9C(),handle)){
id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param+1048576,-1,-1);
ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),id);if(actor)fn_802CEC10(actor);

fn_802D6B24(fn_802D6A9C(),handle,1);
}
}else{
WaveCutTile(pos,r,125);
id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param+1048576,-1,-1);
ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),id);if(actor)actor->activate();
}}
else if(*(u16*)(self+0x24)==326){void* id;
if(param==0x10000){
WaveCutTile(pos,r,327);

if(!fn_802D6AC4(fn_802D6A9C(),handle)){
id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param+1048576,-1,-1);
ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),id);if(actor)fn_802CEC10(actor);

fn_802D6B24(fn_802D6A9C(),handle,1);
}
}else{
WaveCutTile(pos,r,125);
id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param+1048576,-1,-1);
ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),id);if(actor)actor->activate();
}}
else if(*(u16*)(self+0x24)==250){void* id;
if(param==0x10000){
WaveCutTile(pos,r,90);

if(!fn_802D6AC4(fn_802D6A9C(),handle)){
id=Actor_CreateByID(fn_801F856C(),0x47524153,room,pos,param+2097152,-1,-1);
ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),id);if(actor)fn_802CEC10(actor);

fn_802D6B24(fn_802D6A9C(),handle,1);
}
}else{
if(!fn_802D72BC(fn_802D6A9C(),handle)){
fn_802D7310(fn_802D6A9C(),handle,1);
fn_80226CA8(handle,room,&center);
center.x+=lbl_8054078C;center.y+=lbl_8054078C;
Actor_CreateByID(fn_801F856C(),0x47524153,room,(JGeometry::TVec2<f32>*)&center,param+0x200000,-1,-1);
}}}
else if(*(u16*)(self+0x24)==0x71){void* id;
if(param==0){
if(fn_802353AC(who)==1){WaveCutTile(pos,r,123);
}else{WaveCutTile(pos,r,123);
}
}else{WaveCutTile(pos,r,90);
}
id=Actor_CreateByID(fn_801F856C(),0x424f5244,room,pos,0,-1,-1);
ActorVt* actor=(ActorVt*)fn_801F666C(fn_801F856C(),id);if(actor)actor->activate();

fn_8013CC50(room,pos,0x24a,1,0,0,0,1,lbl_80540790);
fn_8013CC50(room,pos,0x24b,1,0,0,0,1,lbl_80540790);
}
fn_802A3164(self,pos,who,r);
if(extra){
if(*(u16*)(self+0x24)==234){WaveCutTile(pos,r,594);
fn_80230FD0(who,0x30006);}
else if(*(u16*)(self+0x24)==235){WaveCutTile(pos,r,595);
fn_80230FD0(who,0x30006);}
else if(*(u16*)(self+0x24)==236){WaveCutTile(pos,r,596);
fn_80230FD0(who,0x30006);}
else if(*(u16*)(self+0x24)==249){WaveCutTile(pos,r,603);
fn_80230FD0(who,0x30006);}
else if(*(u16*)(self+0x24)==0x159 && param==0x10000){WaveCutTile(pos,r,90);
}}
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
extern "C" u8 fn_802A3164(char* this_, JGeometry::TVec2<f32>* pos, s32 param_3, u32 room_) {
    JGeometry::TVec3<f32> ap;
    JGeometry::TVec2<f32> r;
    void* id;
    ActorVt* actor;
    s32 room = room_;
    f32 x, y;
    y = pos->y;
    x = pos->x;
    JGeometry::TVec2<f32> p;
    p.y = y;
    p.x = x;
    *(s32*)(this_ + 0x20) = fn_80226BC4(&p, room);
    *(u16*)(this_ + 0x24) = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, *(s32*)(this_ + 0x20));
    u8 ret = 1;
    if (*(u16*)(this_ + 0x24) >= 0x40 && *(u16*)(this_ + 0x24) <= 0x44) {
        if (*(u16*)(this_ + 0x24) == 0x41) {
            fn_802A3164_sub(pos, room, 0x12, 0);
            s32 count = *(s32*)((char*)fn_801F856C() + 0x1008);
            s32 i, off;
            for (i = 0, off = 0; i < count; i++, off += 4) {
                Actor* a = *(Actor**)((char*)fn_801F856C() + off + 8);
                if (a != 0 && *(s32*)((char*)a + 0x1a0) == 0x54424f32 && room == *(s32*)((char*)a + 4)) {
                    ap = *(JGeometry::TVec3<f32>*)((char*)a + 0xc);
                    r.x = ap.x;
                    r.y = ap.y;
                    if (*(s32*)(this_ + 0x20) == fn_80226BC4(&r, room)) {
                        a->detach();
                        break;
                    }
                }
            }
        } else if (*(u16*)(this_ + 0x24) == 0x43) {
            fn_802A3164_sub(pos, room, 0x50, 1);
        } else {
            fn_802A3164_sub(pos, room, 0x11, 1);
        }
        id = Actor_CreateByID(fn_801F856C(), 0x5455424f, room, pos, *(u16*)(this_ + 0x24) - 0x40, -1, -1);
        actor = (ActorVt*)fn_801F666C(fn_801F856C(), id);
        if (actor != 0) {
            actor->activate();
        }
    } else if (*(u16*)(this_ + 0x24) >= 0x45 && *(u16*)(this_ + 0x24) <= 0x49) {
        if (*(u16*)(this_ + 0x24) == 0x46) {
            fn_802A3164_sub(pos, room, 0x14, 1);
        } else if (*(u16*)(this_ + 0x24) == 0x48) {
            fn_802A3164_sub(pos, room, 0x52, 1);
        } else {
            fn_802A3164_sub(pos, room, 0x15, 1);
        }
        id = Actor_CreateByID(fn_801F856C(), 0x5455424f, room, pos, *(u16*)(this_ + 0x24) - 0x45, -1, -1);
        actor = (ActorVt*)fn_801F666C(fn_801F856C(), id);
        if (actor != 0) {
            actor->activate();
        }
    } else if (*(u16*)(this_ + 0x24) == 0x4e) {
        fn_802A3164_sub(pos, room, 0x11, 1);
        id = Actor_CreateByID(fn_801F856C(), 0x5455424f, room, pos, 0x80, -1, -1);
        actor = (ActorVt*)fn_801F666C(fn_801F856C(), id);
        if (actor != 0) {
            actor->activate();
        }
    } else if (*(u16*)(this_ + 0x24) == 0x4f) {
        fn_802A3164_sub(pos, room, 0x11, 1);
        id = Actor_CreateByID(fn_801F856C(), 0x5455424f, room, pos, 0x100, -1, -1);
        actor = (ActorVt*)fn_801F666C(fn_801F856C(), id);
        if (actor != 0) {
            actor->activate();
        }
    } else {
        ret = 0;
    }
    return ret;
}

extern "C" void fn_802A381C(void* self, const JGeometry::TVec2<f32>* pos, u32 room, u32 value) {
    JGeometry::TVec2<f32> p;
    p.set(pos->x, pos->y);
    s32 r = fn_80226BC4(&p, room & 0xfe);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, r, value);
}

#pragma opt_propagation off
extern "C" void fn_802A3884(char* self, const JGeometry::TVec2<f32>* __restrict pos, void* p3, u32 room, u32 value) {
    JGeometry::TVec2<f32> p;
    f32 x;
    f32 y;
    y = pos->y;
    x = pos->x;
    p.y = y;
    p.x = x;
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
#pragma opt_propagation off
extern "C" void fn_802A3948(char* self, const JGeometry::TVec2<f32>* __restrict pos, void* p3, u32 room, u32 value) {
    JGeometry::TVec2<f32> p;
    f32 x;
    f32 y;
    y = pos->y;
    x = pos->x;
    p.y = y;
    p.x = x;
    s32 r = fn_80226BC4(&p, room & 0xfe);
    *(s32*)(self + 0x20) = r;
    s32 idx = *(s32*)(self + 0x20);
    fn_802D782C(fn_802D6A9C(), 1);
    fn_802F9974(*(void**)(lbl_8053AB10 + 0x20), room, idx, value);
    s32 n = fn_802D4C10(fn_802D6A9C(), room, (u16)*(s32*)(self + 0x20));
    if (n != -1) {
        fn_802D7D00(fn_802D6A9C(), room, n, 1);
    }
}

extern const u8 lbl_8046C4A8[];
extern "C" const char* fn_802D9C4C(void*);
extern "C" void fn_802FA160(void*,void*,s32,s32,s32,s32);
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_lifetimes off
extern "C" void fn_802A3A0C(char* p) {
    const u8* base=lbl_8046C4A8;
    --*(s32*)(p+8);
    if (*(s32*)(p+8)==0) {
        *(s32*)(p+8)=10;
        *(s32*)(p+0xc)+=2;
        if (*(s32*)(p+0xc)>=16) *(s32*)(p+0xc)=0;
        if (*(s32*)((u8*)fn_802D6A9C()+0x40)==16) {
            s32 offset=((const u16*)base)[*(s32*)(p+0xc)]+0x4000;
            void* res=(*(JKRArchive**)((u8*)lbl_8053AAF8+0xa4))->getResource(0x53434820,(const char*)base+0x170);
            fn_802FA160(*(void**)(lbl_8053AB10+0x20),res,offset,0,0x3800,0x800);
        } else {
            s32 offset=((const u16*)base)[*(s32*)(p+0xc)];
            void* res=(*(JKRArchive**)((u8*)lbl_8053AAF8+0xa4))->getResource(0x53434820,(const char*)base+0x170);
            fn_802FA160(*(void**)(lbl_8053AB10+0x20),res,offset,0,0x3800,0x800);
        }
    }
    --*(s32*)(p+0x18);
    if (*(s32*)(p+0x18)==0) {
        *(s32*)(p+0x18)=10;
        ++*(s32*)(p+0x1c);
        if (*(s32*)(p+0x1c)>=8) *(s32*)(p+0x1c)=0;
        const char* name=fn_802D9C4C(fn_802D6A9C());
        char c=*name;
        if (c=='l') {
            s32 offset=((const u16*)base)[*(s32*)(p+0x1c)]+0x2000;
            void* res=(*(JKRArchive**)((u8*)lbl_8053AAF8+0xa4))->getResource(0x53434820,(const char*)base+0x184);
            fn_802FA160(*(void**)(lbl_8053AB10+0x20),res,offset,0,0x5800,0x400);
            *(s32*)(p+0x18)=20;
        } else if (c=='s'||c=='w') {
            s32 offset=((const u16*)base)[*(s32*)(p+0x1c)]+0x6000;
            void* res=(*(JKRArchive**)((u8*)lbl_8053AAF8+0xa4))->getResource(0x53434820,(const char*)base+0x184);
            fn_802FA160(*(void**)(lbl_8053AB10+0x20),res,offset,0,0x1c00,0x400);
        } else if (c=='k'||c=='v') {
            if (*(s32*)(p+0x1c)>=4) *(s32*)(p+0x1c)=0;
            s32 offset=((const u16*)base)[*(s32*)(p+0x1c)]+0x1000;
            void* res=(*(JKRArchive**)((u8*)lbl_8053AAF8+0xa4))->getResource(0x53434820,(const char*)base+0x184);
            fn_802FA160(*(void**)(lbl_8053AB10+0x20),res,offset,0,0x5c00,0x400);
        } else if (*(s32*)((u8*)fn_802D6A9C()+0x40)==0x1b || *(const u8*)name=='y') {
            if (*(s32*)(p+0x1c)>=4) *(s32*)(p+0x1c)=0;
            s32 offset=((const u16*)base)[*(s32*)(p+0x1c)*2]+0x4000;
            void* res=(*(JKRArchive**)((u8*)lbl_8053AAF8+0xa4))->getResource(0x53434820,(const char*)base+0x184);
            fn_802FA160(*(void**)(lbl_8053AB10+0x20),res,offset,0,0x5800,0x800);
        }
    }
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma opt_lifetimes reset
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
    static u32 c0[3], c1[3], c2[3], c3[3], c4[3], c5[3], c6[3], c7[3], c8[3];
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, c0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, c1);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, c2);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, c3);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, c4);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, c5);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, c6);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, c7);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, c8);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}