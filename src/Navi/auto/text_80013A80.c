#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80013a80-0x80015cc0 (55 functions). split_file divides it into the game's real files.

extern void* lbl_80204F9C[];
struct StateObj_80015A40;
typedef void (StateObj_80015A40::*StateFunc_80015A40)(s32);
struct StateObj_80015A40 {
    u8 pad[0x64];
    StateFunc_80015A40 m_func;
};
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80013F24(void* p);
extern "C" void* fn_801C027C(void);
extern "C" void fn_8015D1F4(void* p, void* q, s32 r);
extern "C" void fn_8015D29C(void* p, s32 r);
extern "C" void fn_80159BA4(s32 r);
extern "C" s32 DVDGetDriveStatus(void);
extern "C" void fn_80012DE0(void);
extern "C" void fn_801C1174(void* p);
extern "C" void OSCancelThread(void* p);
extern "C" void fn_801BB7E0(void* p);
extern "C" f32 fn_80116064(f32 x);
extern "C" void fn_80013E18(void* p);
extern u8 lbl_802A2140[];
extern "C" s64 OSGetTime(void);
extern "C" void OSCreateAlarm(void* alarm);
extern "C" s32 fn_801C1594(void);
extern "C" void fn_80013B90(void);
extern "C" void fn_80013BEC(void);
extern "C" void fn_801C0EEC(void* p);
extern "C" void fn_801C0884(void* base, void* fn, s32 a, void* p, u32 size, s32 n, s32 c);
extern "C" void fn_801BB764(void* alarm, u32 a, s64 t, u32 b, u32 c, void* handler);
extern u8 lbl_802A3460[];
extern u8 lbl_802FEBE0;
extern f32 lbl_802FFBB8;
extern "C" s32 fn_8002663C(void);
extern "C" void fn_80026630(void);
extern "C" void fn_800266A8(void);
extern s32 lbl_802FED98;
extern u8 lbl_802FEBE8[];
extern "C" void fn_80015B1C(void* p);
extern struct Unk80204EA4 lbl_80204F64;
extern "C" void fn_80015A00(void* p);
extern "C" void fn_800265F0(u8 param_1);
extern void* lbl_802FF370;
extern u32 lbl_802FB958;
struct Unk80204EBC {
    u32 a;
    u32 b;
    u32 c;
};
extern struct Unk80204EBC lbl_80204EBC;
extern "C" s32 fn_80124A50(void* mgr, u8 id, void* buf);
extern "C" void fn_80124AAC(void* mgr, u8 id, void (*cb)(void*, void*), void* p);
extern "C" void fn_80124820(void* mgr, u8 id, void (*cb)(void*, void*), void* p);
extern "C" s32 fn_80124AF4(void* mgr, u8 id, void* buf);
extern "C" void fn_80124A04(void* mgr, u8 id, void* dst, void (*cb)(void*, void*), void* p);
extern "C" s32 fn_80124900(void* mgr, u8 id, void* buf);
extern "C" void fn_801248B8(void* mgr, u8 id, void (*cb)(void*, void*), void* p);
extern "C" void fn_80015A40(void* self);
extern "C" s32 fn_80014EBC(void* p, s32 x);
struct StateObj_80014EBC;
typedef s32 (StateObj_80014EBC::*StateFunc_80014EBC)(s32);
struct StateObj_80014EBC {
    u8 pad[0x7c];
    StateFunc_80014EBC m_func;
    u8 pad88[0x22];
    s8 m_state;
};
extern "C" s32 fn_801E10A0(void* p, void* q);
extern "C" s32 fn_801E1070(void* p);
extern "C" void fn_801E10DC(void* p, void* q);
extern "C" void fn_80014790(void* p, s32 x);
extern "C" void fn_80014574(void* p, void (*cb)(void*, void*));
extern "C" void fn_800145A4(void* p);
extern "C" s32 fn_8002652C(void);
extern "C" void fn_800268AC(void);
extern "C" void fn_80026520(void);
extern "C" void fn_80026774(void);
extern "C" void fn_8002669C(void);
extern "C" void fn_8001533C(void* self, void* tbl, s32 x);
extern "C" s32 fn_80124868(void* mgr, u8 id, void* buf);
extern "C" void fn_8012495C(void* mgr, u8 id, void* q, void (*cb)(void*, void*), void* p);
extern "C" s32 fn_801249A8(void* mgr, u8 id, void* buf);
struct Unk80204EA4 {
    u32 a;
    u32 b;
    u32 c;
};
extern struct Unk80204EA4 lbl_80204EA4;
extern struct Unk80204EA4 lbl_80204EB0;
extern struct Unk80204EA4 lbl_80204EC8;
extern "C" s32 fn_801E1070(void* p);
extern "C" s32 fn_801E10A0(void* p, void* q);
extern "C" void fn_801E10DC(void* p, void* q);
struct StateObj_80014790;
typedef void (StateObj_80014790::*StateFunc_80014790)(s32);
struct StateObj_80014790 {
    u8 pad[0x70];
    StateFunc_80014790 m_func;
    u8 pad2[0xa9 - 0x7c];
    s8 m_state;
};

struct Unk80013DA0 {
    u8 pad[0x20];
    u8 unk20;
    u8 pad21[0x24 - 0x21];
    u32 b0 : 2;
    u32 b1 : 15;
    u32 b2 : 15;
    u32 unk28;
    u8 pad2c[0x50 - 0x2c];
    u8 unk50;
    u8 unk51;
    u8 unk52;
    u8 unk53;
    u8 unk54;
    u8 unk55;
    u8 pad56;
    u8 unk57;
    u8 unk58;
    u8 unk59;
    u8 unk5a;
    u8 unk5b;
    u8 unk5c;
    u8 unk5d;
    u8 unk5e;
    u8 unk5f;
    u8 pad60[0x63 - 0x60];
    u8 unk63;
    u8 pad64[0xa8 - 0x64];
    s8 unkA8;
};
extern "C" void fn_80014390(Unk80013DA0* self);
extern "C" void fn_80013A80(void)
{
    u8* base = lbl_802A2140;
    s64 time;
    s32 n;

    if (lbl_802FEBE0 == 0) {
        time = OSGetTime();
        fn_801C027C();
        n = fn_801C1594();
        fn_801C0884(base, fn_80013B90, 0, base + 0x320 + 0x1000, 0x1000, n - 3, 1);
        fn_801C0EEC(base);
        OSCreateAlarm(base + 0x1320);
        fn_801BB764(base + 0x1320, 0x80000000, time, 0, *(u32*)0x800000F8 >> 2, fn_80013BEC);
        lbl_802FEBE0 = 1;
    }
}

extern "C" void fn_80013B48(void) {
    if (lbl_802FEBE0) {
        OSCancelThread(lbl_802A2140);
        fn_801BB7E0(lbl_802A3460);
        lbl_802FEBE0 = 0;
    }
}

extern "C" void fn_80013B90(void) {
    u8 buf[0x74];
    fn_8015D1F4(buf, fn_801C027C(), 0);
    fn_8015D29C(buf, -1);
    fn_80159BA4(0);
    while (true) {
        if (DVDGetDriveStatus() == -1) {
            fn_80012DE0();
        }
        fn_801C1174(lbl_802A2140);
    }
}

extern "C" void fn_801C0EEC(void*);
extern "C" void fn_80013BEC(void) {
    fn_801C0EEC(lbl_802A2140);
}

extern "C" void fn_80013C14(void* self, void* p) {
    fn_80013F24(p);
}

extern "C" void fn_80013FC0(void* p);
extern "C" void fn_80013C38(void* self, void* p) {
    fn_80013FC0(p);
}

extern "C" void fn_8001404C(void* p);
extern "C" void fn_80013C5C(void* self, void* p) {
    fn_8001404C(p);
}

extern "C" void fn_800140D0(void* p);
extern "C" void fn_80013C80(void* self, void* p) {
    fn_800140D0(p);
}

extern "C" void fn_80014160(void* p);
extern "C" void fn_80013CA4(void* self, void* p) {
    fn_80014160(p);
}

extern "C" void fn_800141EC(void* p);
extern "C" void fn_80013CC8(void* self, void* p) {
    fn_800141EC(p);
}

extern "C" void fn_80014260(void* p);
extern "C" void fn_80013CEC(void* self, void* p) {
    fn_80014260(p);
}

extern "C" void fn_80014308(void* p);
extern "C" void fn_80013D10(void* self, void* p) {
    fn_80014308(p);
}

extern "C" void fn_800143E8(void* p);
extern "C" void fn_80013D34(void* self, void* p) {
    fn_800143E8(p);
}

extern "C" void fn_80014520(void* p);
extern "C" void fn_80013D58(void* self, void* p) {
    fn_80014520(p);
}

extern "C" void fn_800145F0(void* p);
extern "C" void fn_80013D7C(void* self, void* p) {
    fn_800145F0(p);
}

extern "C" void fn_80013DA0(Unk80013DA0* self, u8 a, u8 b) {
    self->unk50 = a;
    self->unk5f = b;
    self->b2 = (u32)fn_80116064(32767.0f);
    self->b1 = (u32)fn_80116064(32767.0f);
    self->b0 = self->unk50;
    fn_80013E18(self);
}

extern "C" void fn_80013F24(void* p) {
    s32 r;
    struct Unk80204EA4 tbl;
    if (fn_80124868(lbl_802FF370, ((Unk80013DA0*)p)->unk50, &r) == 0 && r == 0x40000) {
        fn_801248B8(lbl_802FF370, ((Unk80013DA0*)p)->unk50, fn_80013C38, p);
    } else {
        tbl = lbl_80204EA4;
        fn_8001533C(p, &tbl, 0);
    }
}

extern "C" void fn_80013FC0(void* p) {
    s32 r;
    struct Unk80204EA4 tbl;
    if (fn_80124900(lbl_802FF370, ((Unk80013DA0*)p)->unk50, &r) == 0) {
        fn_80124AAC(lbl_802FF370, ((Unk80013DA0*)p)->unk50, fn_80013C5C, p);
    } else {
        tbl = lbl_80204EB0;
        fn_8001533C(p, &tbl, 0);
    }
}

extern "C" void fn_8001404C(void* p) {
    u8 buf[4];
    if (fn_80124AF4(lbl_802FF370, ((Unk80013DA0*)p)->unk50, buf) == 0 && (u32)buf[0] == 0x28) {
        fn_8012495C(lbl_802FF370, ((Unk80013DA0*)p)->unk50, (u8*)p + 0x2c, fn_80013C80, p);
    } else {
        fn_80124820(lbl_802FF370, ((Unk80013DA0*)p)->unk50, fn_80013C14, p);
    }
}

extern "C" void fn_800140D0(void* p) {
    u8 buf[4];
    if (fn_801249A8(lbl_802FF370, ((Unk80013DA0*)p)->unk50, buf) == 0) {
        if (*(u32*)((u8*)p + 0x2c) == lbl_802FB958) {
            fn_80124AAC(lbl_802FF370, ((Unk80013DA0*)p)->unk50, fn_80013CA4, p);
        } else {
            fn_80014390((Unk80013DA0*)p);
        }
    } else {
        fn_80124820(lbl_802FF370, ((Unk80013DA0*)p)->unk50, fn_80013C14, p);
    }
}

extern "C" void fn_80014160(void* p) {
    Unk80013DA0* self = (Unk80013DA0*)p;
    u8 buf[4];
    if (fn_80124AF4(lbl_802FF370, self->unk50, buf) == 0 && buf[0] == 0x20) {
        self->unk28 = lbl_802FB958;
        fn_80124A04(lbl_802FF370, self->unk50, &self->unk28, fn_80013CC8, p);
    } else {
        fn_80124820(lbl_802FF370, self->unk50, fn_80013C14, p);
    }
}

extern "C" void fn_800141EC(void* p) {
    u8 buf[4];
    if (fn_80124A50(lbl_802FF370, ((Unk80013DA0*)p)->unk50, buf) == 0) {
        fn_80124AAC(lbl_802FF370, ((Unk80013DA0*)p)->unk50, fn_80013CEC, p);
    } else {
        fn_80124820(lbl_802FF370, ((Unk80013DA0*)p)->unk50, fn_80013C14, p);
    }
}

extern "C" void fn_80014260(void* p) {
    u8 buf[4];
    if (fn_80124AF4(lbl_802FF370, ((Unk80013DA0*)p)->unk50, buf) == 0 && buf[0] == 0x30) {
        if (((Unk80013DA0*)p)->unk20 == 1) {
            ((Unk80013DA0*)p)->unk54 = 1;
        } else {
            ((Unk80013DA0*)p)->unk20 = 1;
        }
        fn_80015A40(p);
    } else {
        struct Unk80204EBC tbl = lbl_80204EBC;
        fn_8001533C(p, &tbl, 0);
    }
}

extern "C" void fn_80014308(void* p) {
    Unk80013DA0* self = (Unk80013DA0*)p;
    u8 buf[4];
    if (fn_80124900(lbl_802FF370, self->unk50, buf) != 0) {
        fn_80014390(self);
    } else {
        self->unk58++;
        if (self->unk58 > 0x3c) {
            fn_80014390(self);
        } else {
            fn_801248B8(lbl_802FF370, self->unk50, fn_80013D10, p);
        }
    }
}

extern "C" void fn_80014390(Unk80013DA0* self) {
    fn_80015A00(self);
    self->unk51 = 0;
    self->unk54 = 0;
    self->b1 = (u32)fn_80116064(32767.0f);
    self->unk20 = 0;
}

extern "C" void fn_80014520(void* p) {
    if (fn_80014EBC(p, 0) != 0) {
        fn_800145A4(p);
    } else {
        fn_80014574(p, fn_80013D58);
    }
}

extern "C" void fn_80014574(void* p, void (*cb)(void*, void*)) {
    fn_80124AAC(lbl_802FF370, ((Unk80013DA0*)p)->unk50, cb, p);
}

extern "C" void fn_800145A4(void* p) {
    fn_80014790(p, 0);
    fn_80124A04(lbl_802FF370, ((Unk80013DA0*)p)->unk50, (u8*)p + 0x28, fn_80013D7C, p);
}

extern "C" void fn_80014720(void) {
    if (fn_8002652C() != 0) {
        fn_800268AC();
        fn_80026520();
        fn_80026774();
        fn_8002669C();
    }
}

extern "C" void fn_80014758(void) {
    if (fn_8002663C() != 0) {
        lbl_802FED98 = 0;
        fn_80026630();
        fn_800266A8();
    }
}

extern "C" void fn_80014790(void* p, s32 arg) {
    s32 a = arg;
    StateObj_80014790* self = (StateObj_80014790*)p;
    struct Unk80204EA4 tbl;
    if (fn_801E1070(&self->m_func) == 0) {
        tbl = lbl_80204EC8;
        if (fn_801E10A0(&self->m_func, &tbl) != 0) {
            if (fn_801E1070(&self->m_func) != 0) {
                self->m_state = -1;
                (self->*self->m_func)(0);
            }
            *(struct Unk80204EA4*)&self->m_func = tbl;
            self->m_state = 0;
            (self->*self->m_func)(0);
        }
    }
    (self->*self->m_func)(a);
}

extern struct Unk80204EA4 lbl_80204F04;
extern "C" s32 fn_80014EBC(void* p, s32 x) {
    StateObj_80014EBC* self = (StateObj_80014EBC*)p;
    if (!self->m_func) {
        StateFunc_80014EBC func = *(StateFunc_80014EBC*)&lbl_80204F04;
        if (self->m_func != func) {
            if (self->m_func) {
                self->m_state = -1;
                (self->*self->m_func)(0);
            }
            self->m_func = func;
            self->m_state = 0;
            (self->*self->m_func)(0);
        }
    }
    return (self->*self->m_func)(x);
}

extern "C" s32 fn_80015574(s8* p) {
    if (p[0xa8] == 0) {
        p[0x53] = 1;
        p[0xa8]++;
    } else if (p[0xa8] != -1 && (u8)p[0x5e] < 3) {
        p[0x5e]++;
    }
    return 1;
}

extern struct Unk80204EA4 lbl_80204F58;
extern "C" s32 fn_801E10A0(void* p, void* q);
extern "C" s32 fn_801E1070(void* p);
extern "C" void fn_801E10DC(void* p, void* q);
extern "C" f32 lbl_802FFBBC;
extern "C" void fn_80015A40(void* p) {
    struct Unk80204EA4 tbl;
    u8* self = (u8*)p;
    tbl = lbl_80204F58;
    if (fn_801E10A0(self + 0x64, &tbl) != 0) {
        if (fn_801E1070(self + 0x64) != 0) {
            self[0xa8] = -1;
            fn_801E10DC(p, 0);
        }
        *(struct Unk80204EA4*)(self + 0x64) = tbl;
        self[0xa8] = 0;
        *(u16*)(self + 0x88) = 0;
        *(u16*)(self + 0x8a) = 0;
        *(u16*)(self + 0x8c) = 0;
        *(u16*)(self + 0x8e) = 0;
        *(f32*)(self + 0x90) = 0.0f;
        fn_801E10DC(p, 0);
    }
    self[0xab] = 1;
}

extern "C" void fn_80015B1C(void* p) {
    struct Unk80204EA4 tbl;
    u8* self = (u8*)p;
    self[0x55] = 1;
    tbl = lbl_80204F64;
    if (fn_801E10A0(self + 0x64, &tbl) != 0) {
        if (fn_801E1070(self + 0x64) != 0) {
            self[0xa8] = -1;
            fn_801E10DC(p, 0);
        }
        *(struct Unk80204EA4*)(self + 0x64) = tbl;
        self[0xa8] = 0;
        *(u16*)(self + 0x88) = 0;
        *(u16*)(self + 0x8a) = 0;
        *(u16*)(self + 0x8c) = 0;
        *(u16*)(self + 0x8e) = 0;
        *(f32*)(self + 0x90) = 0.0f;
        fn_801E10DC(p, 0);
    }
    self[0x5e] = 0;
}

extern "C" void fn_80015C24(void) {
}

extern "C" u32 fn_80015C28(u32 param) {
    union {
        u32 w;
        u8 b[4];
    } src, dst;
    src.w = param;
    dst.b[0] = src.b[3];
    dst.b[1] = src.b[2];
    dst.b[2] = src.b[1];
    dst.b[3] = src.b[0];
    return dst.w;
}

extern "C" void* fn_80015C5C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80204F9C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" s32 fn_80015CA4(s16* p) {
    s32 v = *p;
    if (v != 0) {
        *p = v - 1;
    }
    return *p;
}

