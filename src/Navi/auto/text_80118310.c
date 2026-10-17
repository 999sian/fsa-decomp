#include "types.h"
#include "types.h"
#include <cstring>

extern "C" void fn_801DCCA0(s32);
extern "C" void fn_801DAF24(s32);
extern "C" void fn_801DEA4C(s32);
extern "C" void fn_801DE8B0(s32, s32, s32, s32);
extern "C" void fn_801DCCDC(s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801DE310(s32, s32);
extern "C" void fn_801DEDBC(s32, s32, s32, s32);
extern "C" void fn_801DA39C(s32, s32, s32, s32, s32);
extern "C" void fn_801DA364(void);
extern "C" void fn_801D9F18(s32, s32);

extern "C" void fn_8011C280(int);
extern void* lbl_80290080[];
extern u8 lbl_802FF2A0;
extern u8* lbl_802FF2A4;
extern void* lbl_802FF540;
extern "C" void* fn_80159C40(void*, s32, s32);
extern "C" void GXInitFifoBase(void*, void*, void*);
extern "C" void* GXInit(void*, s32);
extern "C" void fn_801D97E0(void*, void*, void*);

struct VObj_8011A74C {
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual u32 v7(void);
    virtual u32 v8(void);
    virtual void v9(s32 a, void* c);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual void v15(s32 a, void* b);
};
extern "C" void fn_8011C3AC(void* param_1, s32 a, s32 b, s32 c);
extern "C" void fn_8011BF04(void* a, void* b);
extern u8 lbl_802C5FC8[];
extern u8 lbl_802C5FF8[];
extern s32 lbl_802FF2E0;
extern u32 lbl_802FF2E4;
extern "C" s32 fn_8011A7C8(void* a, s32 b);
extern "C" void* fn_8015A90C(u32);
extern "C" void fn_8011AC74(void*, s32, s32, u16, u16);
extern void* lbl_802FF328;
extern void* lbl_802FF2B0;
extern void* lbl_802FF544;
extern "C" BOOL fn_8011C3C8(u32);
extern "C" u16 fn_801194E4(void* param_1, char* param_2);
extern "C" int fn_801E6578(void* a, void* b);
extern u32* lbl_802C5FBC[];
extern "C" BOOL OSGetResetSwitchState(void);
extern f32 lbl_80301540;
extern u8 lbl_802FF2E8;
extern u8 lbl_802FF2E9;
extern s32 lbl_802FF2EC;
extern s32 lbl_802FF2D8;
extern void (*lbl_802FF2D4)(s32, s32);
extern u8 lbl_802FF2B8;
extern u8 lbl_802FF2BC[4];
extern u8 lbl_802FF2CC[4];
extern "C" void fn_8011BF78(s32 chan, u8 stop);
extern u32 lbl_802FF2D0;
extern u32 lbl_80290128[];
extern "C" void fn_801CE100(long chan, unsigned long command);
extern s32 lbl_802FF2C4;
extern u32 lbl_8029016C[];
extern "C" void fn_801CE1B8(int);
extern "C" void fn_801CE970(int);
extern "C" void fn_801CDCB0(void);
extern "C" void fn_80166C70(void*);
extern "C" void fn_80166FC4(void*, void*);
extern "C" void fn_80166B70(void*, int);
extern "C" void fn_8015D0B8(void*, int);

extern "C" void fn_80166C08(void*, int);
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_801670D0(int, void*, int);
extern "C" void fn_80118B58(void*, int, int);

extern "C" void fn_8015AB40(void*);
extern "C" void fn_801DD5E0(void* p, u32 a, u32 b, u16 c);
extern "C" void fn_801196E0(void*);
extern "C" void fn_80118E24(void* a, void* b, void* c, s32 d);
extern "C" void fn_80119004(void* p);
extern "C" void fn_801190F4(void* p, u8 v);
extern "C" void fn_8011972C(void* p, u8* src);
extern "C" u8 fn_80119AD4(void*);
extern "C" void fn_80119A04(void*);
extern "C" void fn_80119A28(void*);
extern u8 lbl_802900DC[];
extern u8 lbl_80283F48[];
extern "C" void fn_801193D8(u8* self, u16* table);
extern "C" int fn_80119318(u8* self);
extern "C" void fn_801DD58C(void*, s32);
extern "C" void fn_801DD618(void* p, u32 id);
extern "C" void fn_80007AB8(const char*, int, const char*, ...);
extern char lbl_80290040[];
extern char lbl_80290050[];
extern void* lbl_80286A4C[];

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80118310-0x8011c4b8 (86 functions). split_file divides it into the game's real files.

extern "C" void fn_80166C08(void*, int);
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_801670D0(int, void*, int);
extern "C" void fn_80118B58(void*, int, int);
extern "C" void* fn_80118310(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80118364(void* param_1) {
    *(float*)((char*)param_1 + 0x54) = 1.0f;
    *(float*)((char*)param_1 + 0x58) = 100000.0f;
}

extern "C" BOOL fn_801189F4(void);
extern "C" BOOL fn_801189F4(void)
{
    return TRUE;
}

extern "C" void fn_801189FC(char *param_1, int param_2, int param_3, int param_4) {
    fn_801670D0(param_2, param_1, 1);
    fn_801670D0(param_2, param_1 + 1, 1);
    fn_801670D0(param_2, param_1 + 2, (u32)(u8)param_1[1]);
    
    u8 b0 = (u8)param_1[0];
    if ((unsigned)b0 == 2 || (unsigned)b0 == 3 || (unsigned)b0 == 4) {
        register u8 b1 = (u8)param_1[1];
        param_1[b1 + 2] = 0;
    }
    fn_80118B58(param_1, param_3, param_4);
}

extern "C" void fn_80118AB4(char *param_1, char *param_2, int param_3, int param_4) {
    u8 byte1 = (u8)param_2[1];
    u8 byte0 = (u8)param_2[0];
    param_1[0] = (char)byte0;
    param_1[1] = (char)byte1;
    
    u8 stored_byte1 = (u8)param_1[1];
    if (stored_byte1 != 0) {
        memcpy(param_1 + 2, param_2 + 2, stored_byte1);
    }
    
    u8 stored_byte0 = (u8)param_1[0];
    if (stored_byte0 == 2 || stored_byte0 == 3 || stored_byte0 == 4) {
        u8 b1 = (u8)param_1[1];
        param_1[b1 + 2] = 0;
    }
    fn_80118B58(param_1, param_3, param_4);
}

extern "C" void* fn_80118BD0(u8* p, s16 n) {
    if (p) {
        if (p[0x3b] & 1) {
            fn_8015AB40(*(void**)(p + 0x3c));
        }
        if (p[0x3b] & 2) {
            fn_8015AB1C(*(void**)(p + 0x28));
        }
        if (n > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void fn_80118DF0(void* a, void* b, u8* c) {
    fn_80118E24(a, b, c, c != 0 ? c[0xc] : 0);
}

extern "C" void fn_80118F5C(u8* p, void* b) {
    if (*(u8*)(*(u8**)(p + 0x20) + 8) != 0) {
        if (b == 0 && *(void**)(p + 0x28) != 0) {
            *(void**)(p + 0x2c) = *(void**)(p + 0x28);
        } else {
            *(void**)(p + 0x2c) = b;
        }
        fn_801190F4(p, (*(u8**)(p + 0x2c))[0xc]);
    }
}

extern "C" void fn_80118FB4(u8* p) {
    if (*(u16*)(*(u8**)(p + 0x20) + 0xa) == 0) {
        fn_80119004(p);
    } else if (*(void**)(p + 0x28) != 0) {
        *(void**)(p + 0x2c) = *(void**)(p + 0x28);
        fn_801190F4(p, (*(u8**)(p + 0x2c))[0xc]);
    }
}

extern "C" void fn_801DCFB8(void* p, void* data, u16 w, u16 h, u8 fmt, u8 a, u8 b, u32 c);
extern "C" void fn_801DD24C(void* p, u8 a, u8 b, u8 c, u8 d, u8 e, f32 x, f32 y, f32 z);
extern "C" void fn_80119004(void* p) {
    u8* self = (u8*)p;
    u8* img = *(u8**)(self + 0x20);
    u32 c = img[0x10] != 0;
    u32 off = *(u32*)(img + 0x1c) ? *(u32*)(img + 0x1c) : 0x20;
    fn_801DCFB8(self, img + off, *(u16*)(img + 2), *(u16*)(img + 4), img[0], self[0x30], self[0x31], c);
    img = *(u8**)(self + 0x20);
    fn_801DD24C(self, self[0x32], self[0x33], img[0x12], img[0x11], img[0x13],
                0.125f * *(u16*)(self + 0x34), 0.125f * *(u16*)(self + 0x36), *(s16*)(self + 0x38) / 100.0f);
}

extern "C" void fn_801DD204(void* p, u8* data, u16 w, u16 h, u8 fmt, u8 a, u8 b, u32 c, u8 d);
extern "C" void fn_801190F4(void* p, u8 v) {
    u8* self = (u8*)p;
    u8* img = *(u8**)(self + 0x20);
    u32 c = img[0x10] != 0;
    f32 z, x, y;
    self[0x3a] = v;
    img = *(u8**)(self + 0x20);
    u32 off = *(u32*)(img + 0x1c) ? *(u32*)(img + 0x1c) : 0x20;
    fn_801DD204(self, img + off, *(u16*)(img + 2), *(u16*)(img + 4), img[0], self[0x30], self[0x31], c, v);
    z = *(s16*)(self + 0x38) / 100.0f;
    x = *(u16*)(self + 0x34) * 0.125f;
    y = *(u16*)(self + 0x36) * 0.125f;
    img = *(u8**)(self + 0x20);
    fn_801DD24C(self, self[0x32], self[0x33], img[0x12], img[0x11], img[0x13], x, y, z);
}

extern "C" void fn_801191F0(u8* param_1, s32 param_2) {
    u8* p = *(u8**)(param_1 + 0x2c);
    if (p != 0) {
        fn_80119318(p);
    }
    fn_801DD58C(param_1, param_2);
}

extern "C" void fn_80119240(u8* self, u8 param_2, u8* param_3) {
    if (param_3 == 0) {
        fn_80007AB8(lbl_80290040, 0x23, lbl_80290050);
    }
    self[0xc] = param_2;
    self[0xd] = param_3[0];
    self[0x16] = param_3[1];
    *(u16*)(self + 0x14) = *(u16*)(param_3 + 2);
    *(u8**)(self + 0x10) = param_3 + 0x20;
    fn_801DD5E0(self, *(u32*)(self + 0x10), self[0xd], *(u16*)(self + 0x14));
}

extern "C" void fn_801192D8(char* param_1, u8 param_2, u8 param_3, u8 param_4, u16 param_5, u32 param_6) {
    param_1[0xc] = param_2;
    param_1[0xd] = param_3;
    param_1[0x16] = param_4;
    *(u16*)(param_1 + 0x14) = param_5;
    *(u32*)(param_1 + 0x10) = param_6;
    fn_801DD5E0(param_1, *(u32*)(param_1 + 0x10), *(u8*)(param_1 + 0xd), *(u16*)(param_1 + 0x14));
}

extern "C" void fn_801DD618(void* p, u32 id);
extern void* lbl_80286A4C[];
extern char lbl_80290040[];
extern char lbl_80290050[];
extern "C" void fn_80007AB8(const char*, int, const char*, ...);
extern "C" int fn_80119318(u8* self) {
    u32 x = *(u16*)(self + 0x14);
    u32 r = (-x | x) >> 31;
    if (r != 0) {
        fn_801DD618(self, self[0xc]);
    }
    return r;
}

extern "C" void* fn_8011935C(u8* self) {
    *(void**)self = lbl_80286A4C;
    fn_801193D8(self, 0);
    return self;
}

extern "C" void* fn_8011939C(u8* self, u16* table) {
    *(void**)self = lbl_80286A4C;
    fn_801193D8(self, table);
    return self;
}

extern "C" void fn_801193D8(u8* self, u16* table) {
    *(u16**)(self + 4) = table;
    if (table != NULL) {
        *(u16*)(self + 0xc) = table[0];
        *(u8**)(self + 8) = (u8*)table + *(u16*)(self + 0xc) * 4 + 4;
    } else {
        *(u16*)(self + 0xc) = 0;
        *(u32*)(self + 8) = 0;
    }
}

#pragma use_lmw_stmw off
extern "C" s32 fn_80119414(u8* self, char* name) {
    u16 count;
    u16 hash;
    u8* table;
    u16* entry = (u16*)(*(u8**)(self + 4) + 4);
    u16 i;
    hash = fn_801194E4(self, name);
    table = *(u8**)(self + 4);
    count = *(u16*)(self + 0xc);
    for (i = 0; i < count; entry += 2, i++) {
        if (*entry == hash && fn_801E6578(table + *(u16*)(table + i * 4 + 6), name) == 0) {
            return i;
        }
    }
    return -1;
}
#pragma use_lmw_stmw reset
extern "C" int fn_801E6578(void* a, void* b);
extern "C" u16 fn_801194E4(void* param_1, char* param_2);
extern "C" void* fn_801194B4(u8* self, u16 idx) {
    if (idx < *(u16*)(self + 0xc)) {
        u8* table = *(u8**)(self + 4);
        u16* e = (u16*)(table + idx * 4);
        return table + e[3];
    }
    return NULL;
}

extern "C" u16 fn_801194E4(void* param_1, char* param_2) {
    s32 hash = 0;
    while (*param_2 != 0) {
        hash = hash * 3 + *param_2++;
    }
    return hash;
}

extern "C" void* fn_80119514(u8* p, s32 size) {
	*(void**)p = lbl_80290080;
	*(s32*)(p + 0xc) = (size + 0x1f) & ~0x1f;
	if (lbl_802FF2A0 != 0) {
		*(void**)(p + 4) = fn_80159C40(lbl_802FF540, *(s32*)(p + 0xc) + 0x80, 0x20);
		*(u8**)(p + 8) = *(u8**)(p + 4) + 0x80;
		GXInitFifoBase(*(void**)(p + 4), *(void**)(p + 8), *(void**)(p + 0xc));
		fn_801D97E0(*(void**)(p + 4), *(void**)(p + 8), *(void**)(p + 8));
	} else {
		*(void**)(p + 8) = fn_80159C40(lbl_802FF540, *(s32*)(p + 0xc) + 0xa0, 0x20);
		*(s32*)(p + 8) = (*(s32*)(p + 8) + 0x1f) & ~0x1f;
		*(void**)(p + 4) = GXInit(*(void**)(p + 8), *(s32*)(p + 0xc));
		lbl_802FF2A0 = 1;
		lbl_802FF2A4 = p;
	}
	return p;
}

extern void* lbl_80290080[];
extern u8* lbl_802FF2A4;
extern u8 lbl_802FF2A8[5];
extern void* lbl_802FF540;
extern "C" void fn_801D9AFC(void*);
extern "C" void fn_801D9BF8(u8*, u8*, u8*, u8*, u8*);
extern "C" void fn_80159CB4(void*, void*);
#pragma use_lmw_stmw off
extern "C" void* fn_801195F0(u8* p, s16 del)
{
	if (p != nullptr) {
		*(void**)p = lbl_80290080;
		fn_801D9AFC(*(void**)(lbl_802FF2A4 + 4));
		do {
			fn_801D9BF8(&lbl_802FF2A8[0], &lbl_802FF2A8[1], &lbl_802FF2A8[2], &lbl_802FF2A8[3], &lbl_802FF2A8[4]);
		} while (lbl_802FF2A8[2] == 0);
		if (lbl_802FF2A4 == p) {
			lbl_802FF2A4 = nullptr;
		}
		fn_80159CB4(lbl_802FF540, *(void**)(p + 8));
		if (del > 0) {
			fn_8015AB1C(p);
		}
	}
	return p;
}
#pragma use_lmw_stmw reset

extern "C" void fn_801196B4(void* p) {
    char* c = (char*)p;
    *(void**)p = lbl_80283F48;
    *(s32*)(c + 0xc) = -1;
    *(s32*)(c + 0x10) = -1;
    *(s32*)(c + 0x14) = -1;
    *(s32*)(c + 0x18) = -1;
    *(u8*)(c + 0x4) = 0;
}

extern "C" void fn_8011972C(void* p, u8* src) {
    u8* d = (u8*)p;
    u8 b0 = src[0];
    u8 b1 = src[1];
    d[0xc] = b0;
    u8 b2 = src[2];
    d[0xd] = b1;
    u8 b3 = src[3];
    d[0xe] = b2;
    d[0xf] = b3;
    d[0x10] = b0;
    d[0x11] = b1;
    d[0x12] = b2;
    d[0x13] = b3;
    d[0x14] = b0;
    d[0x15] = b1;
    d[0x16] = b2;
    d[0x17] = b3;
    d[0x18] = b0;
    d[0x19] = b1;
    d[0x1a] = b2;
    d[0x1b] = b3;
}

extern "C" void fn_80119780(void* p, u8* a, u8* b) {
    u8* d = (u8*)p;
    u8 a0 = a[0];
    u8 a1 = a[1];
    d[0xc] = a0;
    d[0xd] = a1;
    u8 a2 = a[2];
    d[0xe] = a2;
    u8 a3 = a[3];
    d[0xf] = a3;
    d[0x10] = a0;
    d[0x11] = a1;
    d[0x12] = a2;
    d[0x13] = a3;
    u8 b0 = b[0];
    u8 b1 = b[1];
    d[0x14] = b0;
    d[0x15] = b1;
    u8 b2 = b[2];
    d[0x16] = b2;
    u8 b3 = b[3];
    d[0x17] = b3;
    d[0x18] = b0;
    d[0x19] = b1;
    d[0x1a] = b2;
    d[0x1b] = b3;
}

extern "C" BOOL fn_80119A54(void* param_1, void* param_2, void* param_3);
#pragma dont_inline on
extern "C" void* fn_80119904(void* p, void* a, void* b) {
    fn_801196B4(p);
    *(void**)p = lbl_802900DC;
    fn_80119A28(p);
    fn_801196E0(p);
    fn_80119A54(p, a, b);
    return p;
}
#pragma dont_inline reset

extern "C" void* fn_80119978(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_802900DC;
        if (((u8*)param_1)[4] != 0) {
            fn_80119A04(param_1);
            fn_80119A28(param_1);
            fn_801196E0(param_1);
        }
        if (param_1 != nullptr) {
            *(void**)param_1 = lbl_80283F48;
        }
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_80119A04(void* param_1) {
    fn_8015AB40(*(void**)((u8*)param_1 + 0x50));
}

extern "C" void fn_80119A28(void* param_1) {
    u8* p = (u8*)param_1;
    *(u32*)(p + 0x48) = 0;
    *(u32*)(p + 0x50) = 0;
    *(u32*)(p + 0x54) = 0;
    *(u32*)(p + 0x58) = 0;
    *(u32*)(p + 0x5c) = 0;
    *(u32*)(p + 0x1c) = 0;
    *(u32*)(p + 0x20) = 0;
    *(s32*)(p + 0x44) = -1;
}

extern "C" BOOL fn_80119A54(void* param_1, void* param_2, void* param_3) {
    if (fn_80119AD4(param_1) == 0) {
        fn_8015AB40(*(void**)((u8*)param_1 + 0x50));
        *(u32*)((u8*)param_1 + 0x48) = 0;
        *(u32*)((u8*)param_1 + 0x50) = 0;
        *(u32*)((u8*)param_1 + 0x54) = 0;
        *(u32*)((u8*)param_1 + 0x58) = 0;
        *(u32*)((u8*)param_1 + 0x5c) = 0;
        *(u32*)((u8*)param_1 + 0x1c) = 0;
        *(u32*)((u8*)param_1 + 0x20) = 0;
        *(s32*)((u8*)param_1 + 0x44) = -1;
        fn_801196E0(param_1);
        *((u8*)param_1 + 4) = 0;
        return FALSE;
    }
    return TRUE;
}

extern "C" void fn_80119E5C(void) {
    fn_801DCCA0(1);
    fn_801DEA4C(1);
    fn_801DAF24(1);
    fn_801DE8B0(0, 0, 0, 4);
    fn_801DCCDC(4, 0, 0, 1, 0, 0, 2);
    fn_801DE310(0, 0);
    fn_801DEDBC(1, 4, 5, 0xf);
    fn_801DA39C(0, 9, 1, 3, 0);
    fn_801DA39C(0, 0xb, 1, 5, 0);
    fn_801DA39C(0, 0xd, 1, 2, 0xf);
    fn_801DA364();
    fn_801D9F18(9, 1);
    fn_801D9F18(0xb, 1);
    fn_801D9F18(0xd, 1);
}

extern "C" void fn_8011A5B8(VObj_8011A74C* param_1, s32 param_2, void* param_3, void* param_4) {
    if (param_4 != 0) {
        param_1->v9(param_2, param_4);
    }
    s32 t = fn_8011A7C8(param_1, param_2);
    param_1->v15(t, param_3);
}

extern "C" s32 fn_8011A7C8(void* a, s32 b);
extern "C" void fn_8011A640(u8* param_1, s32 param_2, u8* param_3) {
    s32 t = fn_8011A7C8(param_1, param_2);
    u32** list = *(u32***)(param_1 + 0x54);
    u32 i;
    u16 n;
    param_3[0] = 0;
    n = *(u16*)(param_1 + 0x60);
    param_3[1] = (u8)*(u16*)(*(u8**)(param_1 + 0x4c) + 0xe);
    for (i = 0; i < n; i++) {
        u8* e = (u8*)list[i];
        if (t >= *(u16*)(e + 8) && t <= *(u16*)(e + 10)) {
            u8* d = (u8*)list[i] + 0xc + (t - *(u16*)(e + 8)) * 2;
            param_3[0] = d[0];
            param_3[1] = d[1];
            return;
        }
    }
}

extern "C" u32 fn_8011A700(void* param_1) {
    VObj_8011A74C* p = (VObj_8011A74C*)param_1;
    u8* q = ((u8**)p)[0x58 / 4];
    if (q != 0) {
        q = *(u8**)q;
        if (q != 0) {
            return *(u16*)(q + 0xc);
        }
    }
    return p->v8();
}

extern "C" u32 fn_8011A74C(void* param_1) {
    VObj_8011A74C* p = (VObj_8011A74C*)param_1;
    u8* q = *(u8**)((u8*)p + 0x58);
    if (q != 0) {
        q = *(u8**)q;
        if (q != 0) {
            return *(u16*)(q + 0xe);
        }
    }
    return p->v7();
}

extern "C" void fn_8011A798(u8* param_1, s32 param_2) {
    void (*fn)(s32) = *(void (**)(s32))(*(u8**)(param_1 + 0x6c));
    fn(param_2);
}

extern "C" s32 fn_8011AAF4(s32 param_1, u32 param_2, u16* param_3) {
    s32 iVar2 = (param_2 & 0xff) - 0x40;
    s32 iVar3 = (param_2 >> 8) & 0xff;
    if (iVar2 >= 0x40) {
        iVar2 -= 1;
    }
    u16 uVar1 = 0x31c;
    if (param_3 != 0) {
        uVar1 = *param_3;
    }
    return iVar2 + (iVar3 - 0x88) * 0xbc - 0x5e + uVar1;
}

extern "C" int fn_8011AB38()
{
	return 0;
}

extern "C" BOOL fn_8011AB40(void)
{
    return TRUE;
}

extern "C" int fn_8011AB48(int param_1) {
    int r = 0;
    if ((param_1 >= 0x81 && param_1 <= 0x9f) || (param_1 >= 0xe0 && param_1 <= 0xfc)) {
        r = 1;
    }
    return r;
}

extern "C" void* fn_8011AB78(void* param_1, void* param_2) {
    if (lbl_802FF2B0 == 0) {
        void* obj;
        if (param_2 == 0) {
            param_2 = lbl_802FF544;
        }
        obj = fn_8015A90C(0x14);
        if (obj != 0) {
            u8* o = (u8*)obj;
            *(s32*)(o + 8) = -1;
            *(void**)(o + 4) = param_1;
            *(s32*)(o + 0) = 0;
            *(void**)(o + 0x10) = param_2 != 0 ? param_2 : lbl_802FF544;
            o[8] = 0xff;
            o[9] = 0xff;
            o[0xa] = 0xff;
            o[0xb] = 0xff;
            o[0xc] = 1;
        }
        lbl_802FF2B0 = obj;
    }
    return lbl_802FF2B0;
}

extern "C" void* fn_8011AC24(void* p, void* v) {
    void* old = *(void**)((u8*)p + 4);
    if (v != 0) {
        *(void**)((u8*)p + 4) = v;
    }
    return old;
}

extern "C" void fn_8011AC3C(void* param_1) {
    u16* p = *(u16**)((u8*)lbl_802FF328 + 4);
    fn_8011AC74(param_1, 0, 0, p[2], p[3]);
}

extern "C" void fn_801197E4(void* p, s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g);
#pragma use_lmw_stmw off
extern "C" void fn_8011ADE8(u8* param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) {
    VObj_8011A74C* obj = *(VObj_8011A74C**)(param_1 + 4);
    f32 f7 = (f32)(s32)obj->v7();
    f32 f8 = (f32)(s32)obj->v8();
    fn_801197E4(obj, param_5, param_4, 1, (f32)param_2, (f32)param_3, f8, f7);
}
#pragma use_lmw_stmw reset
extern "C" void fn_8015D050(void*);
extern "C" void fn_8011B9A4(void*);
extern "C" void fn_8011BB70(void*);
extern "C" void fn_80166B58(void*, void*);
extern "C" void fn_80166C84(void*, void*);
extern "C" void fn_8011B5D4(void*);
extern "C" void fn_8011B184(void);
extern "C" void fn_8011B1F8(u8* p);
extern "C" void* fn_8011B004(u8* p, s32 del) {
    fn_8015D050(p);
    *(void**)p = lbl_8029016C;
    fn_8011B9A4(p + 0x18);
    fn_8011BB70(p + 0x48);
    fn_8011BB70(p + 0x58);
    fn_8011BF04(p + 0x68, p);
    fn_80166B58(p + 0x80, p);
    *(u8*)(p + 0x98) = 0;
    *(u16*)(p + 0x7c) = del;
    if (*(s16*)(p + 0x7c) >= 0) {
        lbl_802FF2BC[del]++;
    }
    fn_8011B184();
    fn_80166C84(lbl_802C5FBC, p + 0x80);
    fn_8011B5D4(p);
    *(u32*)(p + 0x90) = 0;
    *(u32*)(p + 0x94) = 0;
    fn_8011B1F8(p);
    return p;
}

extern "C" void* fn_8011B0D8(u8* p, s16 del) {
    if (p) {
        *(u32*)p = (u32)lbl_8029016C;
        s16 idx = *(s16*)(p + 0x7c);
        if (idx >= 0) {
            lbl_802FF2BC[idx]--;
            *(s16*)(p + 0x7c) = -1;
        }
        fn_80166FC4(lbl_802C5FBC, p + 0x80);
        if (p + 0x80) {
            fn_80166B70(p + 0x80, 0);
        }
        fn_8015D0B8(p, 0);
        if (del > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void fn_8011B184(void) {
    if (lbl_802FF2B8 == 0) {
        fn_80166C70(lbl_802C5FBC);
        lbl_802FF2B8 = 1;
    }
}

extern "C" void fn_8011B1C0(void) {
    fn_801CE1B8(5);
    lbl_802FF2C4 = 3;
    fn_801CE970(3);
    fn_801CDCB0();
}

extern "C" void fn_8011B1F8(u8* p) {
    p[0x98] = 0;
    p[0xa8] = 1;
}

extern "C" void fn_8011B4C0(u8* param_1) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if ((s8)lbl_802C5FC8[i * 0xc + 0xa] == 0 && lbl_802FF2BC[i] == 0) {
            *(s16*)(param_1 + 0x7c) = i;
            lbl_802FF2BC[i] = 1;
            fn_8011C3AC(lbl_802C5FF8 + i * 0x30, *(s32*)(param_1 + 0x3c), *(s32*)(param_1 + 0x40), *(s32*)(param_1 + 0x44));
            fn_8011BF04(param_1 + 0x68, param_1);
            return;
        }
    }
}

extern "C" void fn_8011B568(u8* param_1, s32 param_2, s64 param_3) {
    s64 t = *(s64*)&lbl_802FF2E0;
    if (param_3 >= t) {
        void (*fn)(s32, s32) = lbl_802FF2D4;
        lbl_802FF2E9 = 1;
        lbl_802FF2EC = *(s16*)(param_1 + 0x7c);
        if (fn != 0) {
            fn(*(s16*)(param_1 + 0x7c), lbl_802FF2D8);
        }
    }
}

extern "C" void fn_8011B8F8(void) {
    if (lbl_802FF2E9 == 0) {
        if (OSGetResetSwitchState() != 0) {
            lbl_802FF2E8 = 1;
        } else {
            if (lbl_802FF2E8 == 1) {
                void (*fn)(s32, s32) = lbl_802FF2D4;
                lbl_802FF2E9 = 1;
                lbl_802FF2EC = -1;
                if (fn != NULL) {
                    fn(-1, lbl_802FF2D8);
                }
            }
            lbl_802FF2E8 = 0;
        }
    }
}

extern "C" void fn_8011B978(void) {
    fn_8011C280(0);
    fn_8011C3C8(0xf0000000);
}

extern "C" void fn_8011B9A4(void* param_1) {
    char* p = (char*)param_1;
    *(s32*)(p + 0x0) = 0;
    *(s32*)(p + 0x4) = 0;
    *(s32*)(p + 0x8) = 0;
    *(s32*)(p + 0x18) = 0;
    *(u8*)(p + 0xc) = 0;
    *(u8*)(p + 0xd) = 0;
    *(u8*)(p + 0xe) = 0;
    *(u8*)(p + 0xf) = 0;
    *(s32*)(p + 0x1c) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2c) = 0;
}

extern "C" void fn_8011BB70(void* param_1) {
    f32 v = lbl_80301540;
    *(f32*)((char*)param_1 + 0x0) = v;
    *(f32*)((char*)param_1 + 0x4) = v;
    *(f32*)((char*)param_1 + 0x8) = v;
    *(s16*)((char*)param_1 + 0xc) = 0;
}

extern f32 lbl_802FDD00;
extern f32 lbl_802FDD04;
extern "C" u32 fn_8011BE50(f32* p, u32 flags) {
    flags &= 0xF;
    if (-lbl_802FDD04 < p[0] && p[0] < lbl_802FDD04) {
        flags &= ~3;
    } else if (p[0] <= -lbl_802FDD00) {
        flags = (flags & ~2) | 1;
    } else if (p[0] >= lbl_802FDD00) {
        flags = (flags & ~1) | 2;
    }
    if (-lbl_802FDD04 < p[1] && p[1] < lbl_802FDD04) {
        flags &= ~0xC;
    } else if (p[1] <= -lbl_802FDD00) {
        flags = (flags & ~8) | 4;
    } else if (p[1] >= lbl_802FDD00) {
        flags = (flags & ~4) | 8;
    }
    return flags;
}

extern "C" void fn_8011BF04(void* a, void* b) {
    struct S { u8 pad[0x7c]; s16 chan; };
    u32* p = (u32*)a;
    S* q = (S*)b;
    s16 chan = q->chan;
    if (chan >= 0 && chan < 4) {
        lbl_802FF2CC[chan] = 0;
        fn_8011BF78(q->chan, 1);
    }
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    lbl_802FF2D0 = 0xf0000000;
}

extern "C" void fn_801CE100(long chan, unsigned long command);
extern u32 lbl_80290128[];
extern u32 lbl_802FF2D0;
extern u8 lbl_802FF2CC[];
extern u8 lbl_802FF2CC[4];
extern "C" void fn_8011BF78(s32 chan, u8 stop) {
    if (lbl_802FF2D0 & lbl_80290128[chan]) {
        fn_801CE100(chan, (u8)(stop ? 2 : 0));
        lbl_802FF2CC[chan] = 0;
    }
}

extern "C" void* fn_8011C244(s32 id) {
    u32** list = lbl_802C5FBC;
    u32* p;

    for (p = *list; p != 0; p = (u32*)p[3]) {
        char* obj = (char*)p[0];
        if (id == *(s16*)(obj + 0x7c)) {
            return obj;
        }
    }
    return 0;
}

extern "C" void fn_8011C3AC(void* param_1, s32 a, s32 b, s32 c) {
    s32* p = (s32*)param_1;
    p[8] = 0;
    p[7] = 0;
    p[9] = a;
    p[10] = b;
    p[11] = c;
}

extern u32 lbl_80290138[4];
extern u32 lbl_802FF2C0;
extern "C" u32 fn_801CDB9C(u32);
extern "C" BOOL fn_8011C3C8(u32 mask) {
    u32* p = lbl_80290138;
    u32 flags = lbl_802FF2C0;
    int i;
    for (i = 0; i < 4; i++, p++) {
        if (flags & *p) {
            mask &= *p ^ -1;
        }
    }
    return fn_801CDB9C(mask) != 0;
}

extern "C" void fn_8011BF78(s32 chan, u8 stop);
extern "C" void fn_8011C454(u8* p, s32 idx, u32 n) {
    if (idx >= 0 && n >= *(u32*)(p + 0x1c)) {
        p[0x11] = 1;
        (p + idx)[0x48] = 1;
        void (*cb)(s32, u8*, u32) = *(void (**)(s32, u8*, u32))(p + 0x4c);
        if (cb != 0) {
            cb(idx, p, *(u32*)(p + 0x50));
        }
    }
}

