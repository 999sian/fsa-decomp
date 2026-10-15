#include "types.h"
#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80196344-0x801a537c (574 functions). split_file divides it into the game's real files.

extern "C" void fn_801A7E24(int);
struct NaviRect16 { s16 x, y, w, h; };
struct NaviColor8 { u8 r, g, b, a; };
struct NaviRectHolder {
    u8 unk_0x0[0xda];
    NaviRect16 rects[4];
    NaviColor8 colors[4];
};
extern void* lbl_80299E68[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80196388(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299E68;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029A150[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80198CCC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A150;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029A0D4[];
extern "C" void* fn_80198D70(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A0D4;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029AE58[];
extern "C" void* fn_80198DB8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029AE58;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029A078[];
extern "C" void* fn_80198E00(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A078;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80299F88[];
extern "C" void* fn_80198E48(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299F88;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_80198EBC(void) {
    return 2;
}

extern void* lbl_8029A02C[];
extern "C" void* fn_80198F44(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A02C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029A078;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_80199A28() {
    return 0x244;
}

extern "C" int fn_80199A30() {
    return 0x3e8;
}

extern "C" int fn_80199A38() {
    return 0x8c;
}

extern "C" int fn_80199A40() {
    return 0x1e;
}

extern "C" int fn_80199A48() {
    return 0x1e;
}

extern "C" int fn_80199A50() {
    return 0x1e;
}

extern "C" int fn_80199A58() {
    return 0x1e;
}

extern "C" int fn_801A3544(int p) { return p + 4; }

extern void* lbl_8029A2C0[];
extern "C" void* fn_801A3614(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A2C0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299F88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_801A36E8(int p) { return p + 4; }

extern void* lbl_8029A35C[];
extern "C" void* fn_801A3768(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A35C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299F88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801A3864(void) { return 0x54563136; }

extern "C" void fn_801A3870(u8* p, s32 i, u16 v) {
    ((u16*)(p + 8))[i] = v;
}

extern "C" void fn_801A3880(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 8))[i] = *pv;
}

extern "C" u16 fn_801A3894(u8* p, s32 i) {
    return ((u16*)(p + 8))[i];
}

extern "C" void fn_801A38A4(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x18)) = *pv;
}

extern "C" void fn_801A38B8(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x18)) = *pv;
}

extern "C" u8* fn_801A38CC(u8* p, s32 i) {
    return p + 0x18 + i * 4;
}

extern "C" void fn_801A38E0(NaviRectHolder* p, s32 i, NaviRect16* src) {
    p->rects[i].x = src->x;
    p->rects[i].y = src->y;
    p->rects[i].w = src->w;
    p->rects[i].h = src->h;
}

extern "C" u8* fn_801A3938(u8* p, s32 i) {
    return p + 0xda + i * 8;
}

extern "C" void fn_801A394C(NaviRectHolder* p, s32 i, NaviColor8* src) {
    p->colors[i].r = src->r;
    p->colors[i].g = src->g;
    p->colors[i].b = src->b;
    p->colors[i].a = src->a;
}

extern "C" void* fn_801A3B8C(void* p) {
    return *(void**)((char*)p + 4);
}

extern void* lbl_8029A400[];
extern "C" void* fn_801A3BA4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A400;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AE58;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A3C00(void* ptr, u32 value) {
    *(u32*)((char*)ptr + 4) = value;
}

extern "C" void fn_801A3CB8(u8* p, s32 i, u16 v) {
    ((u16*)(p + 8))[i] = v;
}

extern "C" void fn_801A3CC8(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 8))[i] = *pv;
}

extern "C" u16 fn_801A3CDC(u8* p, s32 i) {
    return ((u16*)(p + 8))[i];
}

extern "C" void* fn_801A3FD4(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" u32 fn_801A3FDC(u8* p) { return *(u32*)(p + 0x90); }

extern void* lbl_8029A4F8[];
extern "C" void* fn_801A3FEC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A4F8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AE58;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801A40EC(void) { return 0x54564232; }

extern "C" void fn_801A40F8(u8* p, s32 i, u16 v) {
    ((u16*)(p + 8))[i] = v;
}

extern "C" void fn_801A4108(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 8))[i] = *pv;
}

extern "C" u16 fn_801A411C(u8* p, s32 i) {
    return ((u16*)(p + 8))[i];
}

extern "C" void* fn_801A4414(void* p) {
    return *(void**)((char*)p + 4);
}

extern void* lbl_8029A5F0[];
extern "C" void* fn_801A442C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A5F0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AE58;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A4538(u8* p, s32 i, u16 v) {
    ((u16*)(p + 8))[i] = v;
}

extern "C" void fn_801A4548(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 8))[i] = *pv;
}

extern "C" u16 fn_801A455C(u8* p, s32 i) {
    return ((u16*)(p + 8))[i];
}

extern "C" u8* fn_801A4594(u8* p, s32 i) { return p + i * 4 + 10; }

extern "C" u8* fn_801A466C(u8* p, s32 i) {
    return p + 0x18 + i * 4;
}

extern "C" void* fn_801A4680(void* p) {
    return *(void**)((char*)p + 4);
}

extern void* lbl_8029A6E8[];
extern "C" void* fn_801A4688(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A6E8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AE58;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A47D0(u8* p, s32 i, u16 v) {
    ((u16*)(p + 8))[i] = v;
}

extern "C" void fn_801A47E0(u8* p, s32 i, u16* pv) {
    ((u16*)(p + 8))[i] = *pv;
}

extern "C" u16 fn_801A47F4(u8* p, s32 i) {
    return ((u16*)(p + 8))[i];
}

extern "C" void fn_801A4804(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x18)) = *pv;
}

extern "C" void fn_801A4818(u8* p, s32 i, u32* pv) {
    *((u32*)(p + (i << 2) + 0x18)) = *pv;
}

extern "C" u8* fn_801A482C(u8* p, s32 i) {
    return p + 0x18 + i * 4;
}

extern "C" void* fn_801A4A08(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" void fn_801A4A18(int param_1, int param_2) {
    *(int*)(param_1 + 0xd4) = param_2;
}

extern void* lbl_8029A7E4[];
extern "C" void* fn_801A4A20(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A7E4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AE58;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_801A4A7C(void) {
    return 0x54474243;
}

extern "C" void fn_801A4A88(int param_1) {
    fn_801A7E24(param_1 + 0x5c);
}

extern "C" void fn_801A4AAC(int param_1) {
    fn_801A7E24(param_1 + 0x5c);
}

extern "C" int fn_801A4AD0(int param_1) {
    return param_1 + 0x5c;
}

extern "C" void* lbl_8029A91C[];
extern "C" void* lbl_8029AA18[];
extern "C" void* fn_801A4AD8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A91C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AA18;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8029A0D4;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A4B44(void* ptr, u32 value) {
    *(u32*)((char*)ptr + 4) = value;
}

extern "C" void* fn_801A4B58(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" void fn_801A4BB0(u8* p, u32 v) {
    *(u32*)(p + 0x58) = v;
}

extern "C" u32 fn_801A4BB8(void) {
    return 0x54474234;
}

extern "C" void fn_801A4BC4(int param_1) {
    fn_801A7E24(param_1 + 0x5c);
}

extern "C" void fn_801A4BE8(int param_1) {
    fn_801A7E24(param_1 + 0x5c);
}

extern "C" int fn_801A4C0C(int param_1) {
    return param_1 + 0x5c;
}

extern "C" void* lbl_8029A9AC[];
extern "C" void* fn_801A4C14(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029A9AC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AA18;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8029A0D4;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A4C80(void) {
}

extern "C" u32 fn_801A4C84(void) {
    return 0x54475054;
}

extern "C" u32 fn_801A4C90(void) {
    return 0x434c4f4e;
}

extern "C" void fn_801A4C9C(u8* param_1, s32 param_2, NaviColor8* param_3) {
    ((NaviColor8*)(param_1 + 4))[param_2] = *param_3;
}

extern "C" int fn_801A4CF4(int param_1, int param_2) {
    return param_1 + param_2 * 4 + 4;
}

extern "C" void fn_801A4D08(u8* param_1, s32 param_2, u8* param_3) {
    u8* dst = param_1 + param_2 * 4;
    dst[0xc] = param_3[0];
    dst[0xd] = param_3[1];
    dst[0xe] = param_3[2];
    dst[0xf] = param_3[3];
}

extern "C" void fn_801A4D74(u8* param_1, u8* param_2) {
    param_1[0x14] = param_2[0];
}

extern "C" void fn_801A4D80(u8* param_1, u8 param_2) {
    param_1[0x14] = param_2;
}

extern "C" void* fn_801A4E10(u8* p) {
    return *(void**)(p + 0x48);
}

extern void* lbl_8029AAB8[];
extern "C" void* fn_801A4E28(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029AAB8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029A150;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* lbl_8029AB90[];
extern "C" void* lbl_8029AF34[];
extern "C" void* fn_801A4EFC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029AB90;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AF34;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8029A150;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_801A4FC0(int param_1, int param_2) {
    return param_1 + param_2 * 4 + 4;
}

extern void* lbl_8029AC34[];
extern "C" void* fn_801A5074(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029AC34;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299F88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029ACD0[];
extern "C" void* fn_801A50DC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029ACD0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299F88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029AD68[];
extern "C" void* fn_801A5144(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029AD68;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299F88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

