#include "types.h"
extern "C" int fn_80020EA4(void* p, int x);
extern "C" void fn_8007BF68(u8* p);
extern "C" int fn_800183AC(void* p, void* f, s32 a);
extern "C" int fn_8007CEDC(u8* p);
extern "C" int fn_8004D308(void* a, s32 b, s32 c, void* d, void* e, void* f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern u8 lbl_802EE470[];
extern u8 lbl_802FCBA0[];
extern u8 lbl_803007FC[8];
extern void* lbl_802FF0BC;
extern void* lbl_802FDC98;
extern u8 lbl_802EE58C[];
extern "C" void fn_801C5D74(void* a, void* b);
extern "C" void fn_8000CB28(void* a, s16 b);
extern "C" void fn_8000CA54(void* a, s16 b);
extern "C" void fn_8000CBFC(void* a, s16 b);
extern "C" int fn_801E2F8C(int x);
extern f64 lbl_80300810;
extern f32 lbl_8030081C;
extern f32 lbl_80300818;
extern f32 lbl_803007D4;
extern f32 lbl_80300820;
extern f32 lbl_803007C8;
extern f64 lbl_80300828;
extern f64 lbl_80300830;
extern f64 lbl_80300838;
extern f32 lbl_802FEAB0;

static inline f32 navi_sqrtf(f32 x)
{
    if (x > lbl_803007C8) {
        f64 guess = __frsqrte((f64)x);
        guess = lbl_80300828 * guess * (lbl_80300830 - guess * guess * x);
        guess = lbl_80300828 * guess * (lbl_80300830 - guess * guess * x);
        guess = lbl_80300828 * guess * (lbl_80300830 - guess * guess * x);
        return (f32)(x * guess);
    } else if (x < lbl_80300838) {
        return lbl_802FEAB0;
    } else {
        int t;
        u32 bits = *(u32*)&x;
        switch (bits & 0x7f800000) {
        case 0x7f800000:
            t = (bits & 0x007fffff) ? 1 : 2;
            break;
        case 0:
            t = (bits & 0x007fffff) ? 5 : 3;
            break;
        default:
            t = 4;
            break;
        }
        if (t == 1) {
            return lbl_802FEAB0;
        }
        return x;
    }
}

static inline f32 navi_angle(s32 d)
{
    f32 f;
    if (fn_801E2F8C(d) > 0x7fff) {
        if (d < 0) {
            d += 0x10000;
        } else {
            d -= 0x10000;
        }
    }
    if (fn_801E2F8C(d) < 0x2000) {
        f = lbl_80300818 * ((f32)d / lbl_8030081C);
    } else if (d < 0) {
        f = lbl_803007D4;
    } else {
        f = lbl_80300818;
    }
    return lbl_80300820 * f;
}
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8007bcd0-0x80080620 (44 functions). split_file divides it into the game's real files.

extern void* lbl_80283014[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8007BF20(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283014;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern u8 lbl_803007FC[8];
extern "C" void fn_8007C2BC(u8* p) {
    f32 vec[3];
    if (*(u32*)(p + 0x3d0) == 0) {
        u8* x = *(u8**)(p + 0x358);
        u8* y = *(u8**)(x + 4);
        u8* z = *(u8**)(y + 0x84);
        u8* a = *(u8**)(z + 0xc) + *(s8*)(p + 0x451) * 0x30;
        f32 v0 = *(f32*)(a + 0xc);
        f32 v1 = *(f32*)(a + 0x1c);
        f32 v2 = *(f32*)(a + 0x2c);
        vec[0] = v0;
        vec[1] = v1;
        vec[2] = v2;
        u16 n = *(u16*)(lbl_803007FC + 6);
        s32 r;
        if (lbl_802FF0BC != nullptr) {
            r = fn_8004D308(lbl_802FF0BC, 1, n, vec, p + 0x13c, p + 0x144, 0xff, 0, 0, 0, 0);
        } else {
            r = 0;
        }
        *(s32*)(p + 0x3d0) = r;
    }
}

extern "C" BOOL fn_8007C374(u8* p, s32 mode)
{
    if (mode == 0) {
        s32 idx = *(u16*)(p + 0x14);
        u8* w;
        u8* obj = *(u8**)(lbl_802EE470 + 0x38);
        u32 off;
        w = *(u8**)(obj + 0x14);
        off = idx * 0x30;
        fn_801C5D74(*(u8**)(*(u8**)(obj + 0x84) + 0xc) + off, lbl_802FDC98);
        if (idx == (s8)w[0x310]) {
            fn_8000CB28(lbl_802FDC98, -*(s16*)(w + 0x33a));
            fn_8000CA54(lbl_802FDC98, -*(s16*)(w + 0x33c));
            fn_8000CBFC(lbl_802FDC98, -*(s16*)(w + 0x33e));
        }
        if (idx == (s8)w[0x311]) {
            fn_8000CA54(lbl_802FDC98, -*(s16*)(w + 0x342));
            fn_8000CB28(lbl_802FDC98, (s16)*(s16*)(w + 0x340));
            fn_8000CBFC(lbl_802FDC98, (s16)*(s16*)(w + 0x344));
        }
        fn_801C5D74(lbl_802FDC98, *(u8**)(*(u8**)(obj + 0x84) + 0xc) + off);
        fn_801C5D74(lbl_802FDC98, lbl_802EE58C);
    }
    return TRUE;
}

extern "C" BOOL fn_8007C494(void);
extern "C" BOOL fn_8007C494(void)
{
    return TRUE;
}

extern "C" void fn_8007C49C(u8* p, u8* q) {
    s32 off = 0;
    u32 i = 0;
    u8* tbl = lbl_802EE470;
    do {
        if (*(u16*)(p + off + 0x16)) {
            u8* r28 = *(u8**)(*(u8**)(tbl + 0x38) + 0x14);
            u8* obj0 = *(u8**)(q + 0x28);
            u8* obj = ((u8* (*)(u8*, s32))*(void**)(*(u8**)obj0 + 0x50))(obj0, i);
            *(f32*)(obj + 0x1c) = *(f32*)(obj + 0x1c) - *(f32*)(r28 + 0x414);
            *(f32*)(obj + 0x20) = *(f32*)(obj + 0x20) + *(f32*)(r28 + 0x418);
        }
        i++;
        off += 8;
    } while (i < 8);
}

extern "C" int fn_80020EA4(void* p, int x);
extern "C" void fn_8007BF68(u8* p);
extern "C" int fn_800183AC(void* p, void* f, s32 a);
extern "C" int fn_8007CEDC(u8* p);
extern "C" void fn_8007C5E4(void);
extern u8 lbl_802FCBA0[];
extern u8 lbl_802EE470[];
extern u8 lbl_803007FC[];
extern void* lbl_802FF0BC;
extern "C" int fn_8004D308(void* a, s32 b, s32 c, void* d, void* e, void* f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern "C" void fn_8007C540(u8* p, u8* q) {
    s32 off = 0;
    u8* tbl = lbl_802EE470;
    u32 i = 0;
    do {
        if (*(u16*)(p + off + 0x16)) {
            u8* r28 = *(u8**)(*(u8**)(tbl + 0x38) + 0x14);
            u8* obj0 = *(u8**)(q + 0x28);
            u8* obj = ((u8* (*)(u8*, s32))*(void**)(*(u8**)obj0 + 0x50))(obj0, i);
            *(f32*)(obj + 0x1c) = *(f32*)(obj + 0x1c) + *(f32*)(r28 + 0x414);
            *(f32*)(obj + 0x20) = *(f32*)(obj + 0x20) + *(f32*)(r28 + 0x418);
        }
        i++;
        off += 8;
    } while (i < 8);
}
extern "C" void fn_8007C698(void);
extern "C" void fn_8007C5E4(void) {
    fn_8007C698();
}

#pragma dont_inline on
extern "C" int fn_8007C604(u8* p) {
    int iVar1 = fn_80020EA4(p + 0x244, 0);
    if (iVar1 == 4) {
        if ((*(u32*)(p + 0xf8) & 8) == 0) {
            if (p != nullptr) {
                fn_8007BF68(p);
            }
            *(u32*)(p + 0xf8) |= 8;
        }
        if ((u8)fn_800183AC(p, (void*)fn_8007C5E4, 0x91d0)) {
            iVar1 = fn_8007CEDC(p);
        } else {
            iVar1 = 5;
        }
    }
    return iVar1;
}
#pragma dont_inline reset

extern u8 lbl_8029F8D8[];
extern u8 lbl_802FCBA0[];
extern u8 lbl_802EE470[];
extern u8 lbl_803007FC[];
extern void* lbl_802FF0BC;
extern "C" int fn_80020EA4(void* p, int x);
extern "C" void fn_8007BF68(u8* p);
extern "C" int fn_800183AC(void* p, void* f, s32 a);
extern "C" int fn_8007CEDC(u8* p);
extern "C" int fn_8004D308(void* a, s32 b, s32 c, void* d, void* e, void* f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern u8 lbl_802FCBA0[];
extern u8 lbl_802EE470[];
extern u8 lbl_803007FC[];
extern void* lbl_802FF0BC;
extern "C" int fn_80020EA4(void* p, int x);
extern "C" void fn_8007BF68(u8* p);
extern "C" int fn_800183AC(void* p, void* f, s32 a);
extern "C" int fn_8007CEDC(u8* p);
extern "C" int fn_8004D308(void* a, s32 b, s32 c, void* d, void* e, void* f, s32 g, s32 h, s32 i, s32 j, s32 k);
extern s32 lbl_802821C0[];
extern "C" void fn_801C61AC(void* p, f32 x, f32 y, f32 z);
extern "C" void fn_8000C8A4(void* m, s32 a, s32 b, s32 c);
extern "C" void fn_801C5D74(void* p, void* q);
extern "C" void fn_8007E888(u8* p, void* a);
extern "C" void fn_8007D940(u8* p)
{
	u8* q = *(u8**)(*(u8**)(p + 0x358) + 4);
	*(f32*)(q + 0x18) = *(f32*)(p + 0x144);
	*(f32*)(q + 0x1c) = *(f32*)(p + 0x148);
	*(f32*)(q + 0x20) = *(f32*)(p + 0x14c);
	fn_801C61AC(lbl_8029F8D8, *(f32*)(p + 0x128), *(f32*)(p + 0x12c), *(f32*)(p + 0x130));
	fn_8000C8A4(lbl_8029F8D8, *(s16*)(p + 0x13c), *(s16*)(p + 0x13e), *(s16*)(p + 0x140));
	fn_801C5D74(lbl_8029F8D8, *(u8**)(*(u8**)(p + 0x358) + 4) + 0x24);
}

extern "C" void fn_8007E758(u8* p, s32 idx)
{
	s32* table;

	*(s32*)(p + 0x3dc) = idx;
	*(s32*)(p + 0x3e0) = 0;
	table = (s32*)lbl_802821C0[*(s32*)(p + 0x3dc)];
	fn_8007E888(p, (void*)table[*(s32*)(p + 0x3e0) * 2]);
	*(s32*)(p + 0x3e4) = table[*(s32*)(p + 0x3e0) * 2 + 1];
}

extern "C" BOOL fn_8007E7CC(u8* p)
{
	if (*(s8*)(p + 0x445) != 0) {
		s32* table = (s32*)lbl_802821C0[*(s32*)(p + 0x3dc)];
		s32 n = *(s32*)(p + 0x3e4);
		if (n == 0) {
			*(s32*)(p + 0x3e0) += 1;
			fn_8007E888(p, (void*)table[*(s32*)(p + 0x3e0) * 2]);
			*(s32*)(p + 0x3e4) = table[*(s32*)(p + 0x3e0) * 2 + 1];
		} else if (n > 0) {
			*(s32*)(p + 0x3e4) = n - 1;
			fn_8007E888(p, (void*)table[*(s32*)(p + 0x3e0) * 2]);
		} else {
			return 1;
		}
	}
	return 0;
}

extern "C" void fn_801158C0(f32* out, void* a, void* b);
extern "C" void fn_80115A74(f32* out, f32* in);
extern "C" s16 fn_80115DF4(f32 a, f32 b);
extern "C" void fn_8007F6CC(u8* self, f32* dir, void* p, f32* outA, f32* outB)
{
    f32 v[3];
    f32 tmp[3];
    f32 n[3];
    s32 d;

    fn_801158C0(tmp, p, self + 0x2a0);
    v[0] = tmp[0];
    v[1] = tmp[1];
    v[2] = tmp[2];
    fn_80115A74(n, v);
    d = fn_80115DF4(dir[0], dir[2]);
    d = fn_80115DF4(v[0], v[2]) - d;
    *outA = navi_angle(d);

    f32 len = navi_sqrtf(dir[0] * dir[0] + dir[2] * dir[2]);
    f32 len2 = navi_sqrtf(v[0] * v[0] + v[2] * v[2]);
    d = fn_80115DF4(len, dir[1]);
    d = fn_80115DF4(len2, v[1]) - d;
    *outB = navi_angle(d);
}

extern "C" int fn_8007C604(u8* p);
extern "C" void fn_80080430(u8* p) {
    fn_8007C604(p);
}

extern "C" void fn_8007FD34(void);
extern "C" void fn_80080564(void) {
    fn_8007FD34();
}

extern "C" void fn_8007CFC4(void);
extern "C" void fn_80080584(void) {
    fn_8007CFC4();
}

extern "C" BOOL fn_800805A4(void);
extern "C" BOOL fn_800805A4(void)
{
    return TRUE;
}

extern void* lbl_80282FE8[];
extern void* lbl_80281904[];
extern "C" void* fn_800805AC(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80282FE8;
        if ((s32)param_1 + 0x38 != 0) {
            *(void**)((char*)param_1 + 0x38) = lbl_80283014;
        }
        if ((s32)param_1 + 0xc != 0) {
            *(void**)((char*)param_1 + 0xc) = lbl_80281904;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

