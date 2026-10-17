#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80025170-0x800275d8 (75 functions). split_file divides it into the game's real files.

extern u8 lbl_802FED9C;
extern u8 lbl_802FED9D;
extern u8 lbl_802FED9E;
extern u8 lbl_802FED9F;
extern u8 lbl_802FEDA4;
extern "C" u8 lbl_802BBD38[];
struct NaviEntry { u8 pad[0x1c]; int flag; };
struct NaviSlot { NaviEntry e[16]; s16 cur; s16 next; };
struct NaviEnt14 { int a[3]; int val; int b; };
struct NaviSlot2C { NaviEnt14 e[2]; s16 cur; s16 next; };
extern u8 lbl_802BC618[];
extern u8 lbl_802BBD28[];
extern u8 lbl_802BC548[];

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_800254CC(void);
extern "C" void fn_8002544C(void) {
    fn_800254CC();
}

extern "C" void fn_80025570(void);
extern "C" void fn_8002546C(void) {
    fn_80025570();
}

extern "C" void fn_8002566C(void);
extern "C" void fn_8002548C(void) {
    fn_8002566C();
}

extern "C" void fn_80025710(void);
extern "C" void fn_800254AC(void) {
    fn_80025710();
}

extern "C" void fn_80026480(u8 i) {
    NaviSlot* s = (NaviSlot*)lbl_802BBD38 + i;
    s->e[s->next].flag = 1;
}

extern "C" u8 lbl_802BBD38[];
extern "C" int fn_800264AC(u8 i) {
    u8* p = lbl_802BBD38 + i * 0x204;
    p += *(s16*)(p + 0x200) * 0x20;
    return *(int*)(p + 0x1c);
}

extern "C" void fn_800264D4(u8 i) {
    NaviSlot* s = (NaviSlot*)lbl_802BBD38 + i;
    s->e[s->cur].flag = 0;
}

extern u8 lbl_802BBD38[];
extern "C" u8 fn_800265AC(u8);
extern "C" void fn_80026500(u8 param_1) {
    lbl_802FED9C |= (u8)(1 << param_1);
}

extern u8 lbl_802FED9C;
extern "C" void fn_80026520(void) {
    lbl_802FED9C = 0;
}

extern "C" int fn_8002652C(void) {
    u8 i;
    for (i = 0; i < 4; i++) {
        if (fn_800265AC(i)) {
            u8 m = lbl_802FED9C & (u8)(1 << i);
            if (!m) {
                return 0;
            }
        }
    }
    return 1;
}

extern "C" void fn_800265D0(u8 param_1) {
    lbl_802FED9D |= (u8)(1 << param_1);
}

extern "C" void fn_800265F0(u8 param_1) {
    lbl_802FED9D &= ~((u8)(1 << param_1));
}

extern "C" void fn_80026610(u8 param_1) {
    lbl_802FED9E |= (u8)(1 << param_1);
}

extern u8 lbl_802FED9E;
extern "C" void fn_80026630(void) {
    lbl_802FED9E = 0;
}

extern "C" u32 fn_8002663C(void) {
    u8 i;
    for (i = 0; i < 4; i++) {
        u8 mask = 1 << i;
        if ((u8)(*(volatile u8*)&lbl_802FED9D & mask) != 0 && (u8)(*(volatile u8*)&lbl_802FED9E & mask) == 0) {
            return 0;
        }
    }
    return 1;
}

extern "C" u8 fn_80026694(void) {
    return lbl_802FED9F;
}

extern "C" void fn_8002669C(void) {
    lbl_802FED9F = 1;
}

extern u8 lbl_802FED9F;
extern "C" void fn_800266A8(void) {
    lbl_802FED9F = 0;
}

extern u8 lbl_802FEDA4;
extern u8 lbl_802FED9D;
extern "C" void fn_800266B4(u8 param_1) {
    ((u8*)&lbl_802FEDA4)[param_1] = 1;
}

extern "C" void fn_800266C8(u8 param_1) {
    ((u8*)&lbl_802FEDA4)[param_1] = 2;
}

extern "C" u32 fn_800266DC(void) {
    volatile u32 result = 1;
    for (u8 i = 0; i < 4; i++) {
        if ((lbl_802FED9D & (1 << i)) != 0) {
            u8 val = ((u8*)&lbl_802FEDA4)[i];
            if (val == 2) {
                result = 2;
            }
            if (val == 0) {
                return 0;
            }
        }
    }
    return result;
}

extern "C" void fn_80026758(void) {
    lbl_802FEDA4 = 0;
    ((u8*)&lbl_802FEDA4)[1] = 0;
    ((u8*)&lbl_802FEDA4)[2] = 0;
    ((u8*)&lbl_802FEDA4)[3] = 0;
}

extern "C" void fn_80026774(void) {
    u32* p = (u32*)lbl_802BBD28;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
}

extern "C" int fn_80026790(u8 i, int j) {
    u8* p = lbl_802BC548 + i * 0x34;
    return *(int*)(p + *(s16*)(p + 0x30) * 0x18 + j * 4);
}

extern "C" void fn_800267BC(u8 i) {
    u32* w = (u32*)(lbl_802BC548 + i * 0x34);
    w[0] = 0;
    w[1] = 0;
    w[2] = 0;
    w[3] = 0;
    w[4] = 0;
    w[5] = 0;
    w[6] = 0;
    w[7] = 0;
    w[8] = 0;
    w[9] = 0;
    w[10] = 0;
    w[11] = 0;
    *(u16*)(lbl_802BC548 + i * 0x34 + 0x30) = 0;
    *(u16*)(lbl_802BC548 + i * 0x34 + 0x32) = 0;
}

extern "C" void fn_80026810(u8 i) {
    u8* p = lbl_802BC548 + i * 0x34;
    (*(s16*)(p + 0x30))++;
    if (*(s16*)(p + 0x30) >= 2) {
        *(s16*)(p + 0x30) = 0;
    }
}

extern "C" int fn_80026848(u8 i) {
    u8* p = lbl_802BC548 + i * 0x34;
    p += *(s16*)(p + 0x30) * 0x18;
    return *(int*)(p + 0x14);
}

extern "C" int fn_8002689C()
{
	return 0;
}

extern "C" int fn_800268A4()
{
	return 0;
}

extern "C" void fn_80026BD8(u8 idx) {
    u32* w = (u32*)(lbl_802BC618 + idx * 0x2c);
    w[0] = 0;
    w[1] = 0;
    w[2] = 0;
    w[3] = 0;
    w[4] = 0;
    w[5] = 0;
    w[6] = 0;
    w[7] = 0;
    w[8] = 0;
    w[9] = 0;
    *(u16*)(lbl_802BC618 + idx * 0x2c + 0x28) = 0;
    *(u16*)(lbl_802BC618 + idx * 0x2c + 0x2a) = 0;
}

extern "C" NaviEnt14 fn_80026CF0(u8 i) {
    NaviSlot2C* s = (NaviSlot2C*)lbl_802BC618 + i;
    return s->e[s->cur];
}

extern "C" int fn_80026D3C(u8 i) {
    u8* p = lbl_802BC618 + i * 0x2c;
    p += *(s16*)(p + 0x28) * 0x14;
    return *(int*)(p + 0x10);
}

extern u8 lbl_802BC618[];
extern "C" void fn_80026D64(u8 i) {
    u8* p = lbl_802BC618 + i * 0x2c;
    (*(s16*)(p + 0x2a))++;
    if (*(s16*)(p + 0x2a) >= 2) {
        *(s16*)(p + 0x2a) = 0;
    }
}

extern "C" void fn_80026D9C(u8 i) {
    u8* p = lbl_802BC618 + i * 0x2c;
    (*(s16*)(p + 0x28))++;
    if (*(s16*)(p + 0x28) >= 2) {
        *(s16*)(p + 0x28) = 0;
    }
}

extern "C" int fn_80026DD4(u8 i) {
    u8* p = lbl_802BC618 + i * 0x2c;
    p += *(s16*)(p + 0x2a) * 0x14;
    return *(int*)(p + 0xc);
}

extern "C" int fn_80026DFC(u8 i) {
    u8* p = lbl_802BC618 + i * 0x2c;
    p += *(s16*)(p + 0x28) * 0x14;
    return *(int*)(p + 0xc);
}

extern "C" void fn_80026E24(u8 i) {
    NaviSlot2C* s = (NaviSlot2C*)lbl_802BC618 + i;
    s->e[s->cur].val = 0;
}

extern "C" void fn_80026E50(void) {}

extern "C" void* fn_80026E54(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80013DA0(void);
extern "C" void fn_80026EC4(u8* p);
extern u32 lbl_802026C0[3];
extern "C" void fn_80026E90(u8* p) {
    fn_80013DA0();
    fn_80026EC4(p);
}

extern "C" void fn_80026EC4(u8* p) {
    *(u32*)(p + 0xac) = lbl_802026C0[0];
    *(u32*)(p + 0xb0) = lbl_802026C0[1];
    *(u32*)(p + 0xb4) = lbl_802026C0[2];
    p[0xd0] = 0;
    *(u32*)(p + 0xb8) = lbl_802026C0[0];
    *(u32*)(p + 0xbc) = lbl_802026C0[1];
    *(u32*)(p + 0xc0) = lbl_802026C0[2];
    *(u32*)(p + 0xc4) = 0;
    p[0xd1] = 0;
    p[0xd2] = 0;
}

extern "C" BOOL fn_80026F14(s8* p) {
    if (p[0xd0] == 0) {
        p[0xd0]++;
    }
    return TRUE;
}

