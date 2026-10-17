#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80025170-0x800275d8 (75 functions). split_file divides it into the game's real files.

extern u8 lbl_802FED9C;
extern u8 lbl_802FED9D;
extern u8 lbl_802FED9E;
extern u8 lbl_802FED9F;
extern u8 lbl_802FEDA4;
extern u8 lbl_8029F408[];
extern "C" void fn_801E0D40(void*, void*, s32, s32);
extern "C" void fn_800251D8(u8* p);
extern "C" void* fn_80026E54(void*, s16);
extern "C" u8 lbl_802BBD38[];
struct NaviEntry { u8 pad[0x1c]; int flag; };
struct NaviSlot { NaviEntry e[16]; s16 cur; s16 next; };
struct NaviEnt14 { int a[3]; int val; int b; };
struct NaviSlot2C { NaviEnt14 e[2]; s16 cur; s16 next; };
struct NaviEnt18 { int a[5]; int val; };
struct NaviEnt1C { int a[7]; };
struct NaviSlot34 { NaviEnt18 e[2]; s16 cur; s16 next; };
extern u8 lbl_802BC618[];
extern u8 lbl_802BBD28[];
extern u8 lbl_802BC548[];
extern u8 lbl_802BE378[];
extern u8 lbl_802FBDB8[];
extern u8 lbl_802FBDC0;
extern u8 lbl_802FBDC8;
extern "C" void fn_80021240(void*, void*, void*);
extern "C" void fn_800274C8(void*);
extern u8 lbl_802B7CA0[];
extern u32 lbl_80226340[];
extern u8 lbl_80226364[];
extern u8 lbl_80226374[];
extern u8 lbl_80226394[];
extern u32 lbl_802262BC[];
extern u8 lbl_8029FDB4[];
extern u8 lbl_802A354C[];
extern u32 lbl_802FED94;
extern "C" void fn_801E41AC(void* dst, void* src, ...);
extern "C" u32 fn_800137B8(void*, s32, s32);
extern "C" void fn_80159C6C(void*, s32);
extern "C" void fn_800252B4(void);
extern "C" u8 fn_800126C8(void*, void*, void*);
extern "C" void fn_80021220(void*, s32);

extern "C" void fn_8015AB1C(void*);
extern "C" int fn_800254CC(u8* param_1);
extern "C" void* fn_80025170(u8* p, s16 n) {
    if (p != 0) {
        fn_800251D8(p);
        fn_801E0D40(p + 0x40, (void*)fn_80026E54, 0xd4, 4);
        if (n > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void fn_800251D8(u8* param_1) {
    u8* p = param_1;
    s32 i = 0;
    do {
        fn_80159C6C(*(void**)(p + 0x394), 0);
        *(u32*)(p + 0x394) = 0;
        i++;
        *(u32*)(p + 0x3c4) = 0;
        p += 4;
    } while (i < 0xc);
    fn_80021220(param_1, 0);
    fn_80021220(param_1 + 8, 0);
    lbl_802FED94 = 0;
}

extern "C" void fn_80025268(void) {
    fn_800252B4();
    lbl_802A354C[4] = fn_800126C8(lbl_8029FDB4 + 4, lbl_80226364, lbl_802A354C);
}

extern "C" void fn_8002544C(u8* param_1) {
    fn_800254CC(param_1);
}

extern "C" void fn_80025570(void);
extern "C" void fn_8002546C(void) {
    fn_80025570();
}

extern "C" int fn_8002566C(u8* param_1);
extern "C" void fn_8002548C(u8* param_1) {
    fn_8002566C(param_1);
}

extern "C" void fn_80025710(void);
extern "C" void fn_800254AC(void) {
    fn_80025710();
}

extern "C" int fn_800254CC(u8* param_1) {
    u8 buf[0x118];
    u32* slot = (u32*)(param_1 + 0xc);
    u32* table = lbl_802262BC;
    s32 i = 0;
    s32 v = *(s32*)(lbl_802B7CA0 + 0x343c) + 1;
    do {
        if (slot[4] == 0) {
            fn_801E41AC(buf, lbl_80226374, v, *table);
            slot[4] = fn_800137B8(buf, 0, 0);
        }
        i++;
        table++;
        slot++;
    } while (i < 3);
    return 2;
}

#pragma use_lmw_stmw off
extern "C" int fn_8002566C(u8* param_1) {
    u8 buf[0x100];
    u32* slot = (u32*)(param_1 + 0xc);
    u32* table = lbl_80226340;
    s32 i = 3;
    u8 r = lbl_802B7CA0[0x1419];
    do {
        if (slot[4] == 0) {
            fn_801E41AC(buf, lbl_80226394, (s32)&lbl_802FBDB8, r, *table);
            slot[4] = fn_800137B8(buf, 0, 0);
        }
        i++;
        table++;
        slot++;
    } while (i < 0xc);
    return 2;
}
#pragma use_lmw_stmw reset
extern "C" void fn_80025824(void* p) {
    fn_80021240(p, &lbl_802FBDC0, p);
}

extern "C" void fn_8002584C(u8* p) {
    fn_80021240(p + 8, &lbl_802FBDC8, p);
}

extern "C" void fn_80025878(u8* p) {
    for (u8 i = 0; i < 4; i++) {
        fn_800274C8(p + i * 0xd4 + 0x40);
    }
}

extern "C" s32 fn_80025DE4(void) {
    s32 r = 0;
    s32 i;
    s8* p = (s8*)lbl_8029F408;
    for (i = 0; i < 4; i++) {
        if (p[0x48] == 0) {
            r |= 1 << i;
        }
        p += 0x50;
    }
    return r;
}

extern "C" void fn_8002611C(u8 i) {
    u8* p = lbl_802BE378 + i * 0x204;
    u16* w;
    s32 n = 8;
    p[0x202] = 0;
    p[0x203] = 0;
    *(s16*)(p + 0x200) = 0;
    w = (u16*)p;
    do {
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
        w[12] = 0;
        w[13] = 0;
        w[14] = 0;
        w[15] = 0;
        w[16] = 0;
        w[17] = 0;
        w[18] = 0;
        w[19] = 0;
        w[20] = 0;
        w[21] = 0;
        w[22] = 0;
        w[23] = 0;
        w[24] = 0;
        w[25] = 0;
        w[26] = 0;
        w[27] = 0;
        w[28] = 0;
        w[29] = 0;
        w[30] = 0;
        w[31] = 0;
        w += 0x20;
    } while (--n != 0);
}

extern "C" void fn_800261D4(u8 i, u16 param_2) {
    u8* p;
    u8* c;
    if (param_2 != 0) {
        p = lbl_802BE378 + i * 0x204;
        if (param_2 != *(u16*)(p + 0x200)) {
            u8 n = p[0x203];
            c = p + 0x203;
            if (*(u16*)(p + n * 2) == 0) {
                *(u16*)(p + n * 2) = param_2;
                (*c)++;
            }
        } else {
            param_2 = 0;
        }
    }
    p = lbl_802BE378;
    p += i * 0x204;
    *(u16*)(p + 0x200) = param_2;
}

extern "C" void fn_80026248(u8 i) {
    u8* c;
    u8* p = lbl_802BE378 + i * 0x204;
    u8 n = p[0x202];
    if (*(u16*)(p + n * 2) == 0) {
        return;
    }
    *(u16*)(p + n * 2) = 0;
    c = p + 0x202;
    (*c)++;
}

extern "C" void fn_8002628C(u8 i, s32 j, u32 v) {
    u8* p = lbl_802BBD38 + i * 0x204;
    *(u32*)(p + *(s16*)(p + 0x202) * 0x20 + j * 4) = v;
}

extern "C" void fn_800263B4(NaviEnt1C* dst, u8 i) {
    u8* p = lbl_802BBD38 + i * 0x204;
    *dst = *(NaviEnt1C*)(p + *(s16*)(p + 0x200) * 0x20);
}

extern "C" void fn_80026410(u8 i) {
    u8* p = lbl_802BBD38 + i * 0x204;
    (*(s16*)(p + 0x202))++;
    if (*(s16*)(p + 0x202) >= 0x10) {
        *(s16*)(p + 0x202) = 0;
    }
}

extern "C" void fn_80026448(u8 i) {
    u8* p = lbl_802BBD38 + i * 0x204;
    (*(s16*)(p + 0x200))++;
    if (*(s16*)(p + 0x200) >= 0x10) {
        *(s16*)(p + 0x200) = 0;
    }
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

extern "C" u8 fn_800265AC(u8 i) {
    u8 v = *(volatile u8*)&lbl_802FED9D;
    return (u8)(v & (u8)(1 << i));
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
    u32* w = (u32*)(i * 0x34 + lbl_802BC548);
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
    *(u16*)(w + 12) = 0;
    *(u16*)((u8*)w + 0x32) = 0;
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

extern "C" void fn_80026870(u8 i) {
    NaviSlot34* s = (NaviSlot34*)lbl_802BC548 + i;
    s->e[s->cur].val = 0;
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

extern "C" u8 fn_800275B8(u8* param_1) {
    if (*(volatile u8*)param_1 != 0) {
        *param_1 = *param_1 - 1;
    }
    return *param_1;
}

