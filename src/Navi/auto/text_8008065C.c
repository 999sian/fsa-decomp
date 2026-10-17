#include "types.h"

extern "C" int fn_80020EA4(u8* p, int q);
extern "C" void fn_8008090C(u8* p);
extern "C" int fn_800183AC(u8* p, void* f, void* q);
extern "C" int fn_80081BA0(u8* p);
extern "C" void fn_80081308();
extern u8 lbl_802FCC10;
extern "C" char fn_8000D6F4(void*);
extern "C" void fn_801C5D74(void* p, void* q);
extern void* lbl_802FF0BC;
extern u16 lbl_801FA1CC[];
extern "C" void* fn_8004D308(void* a, int b, u16 c, void* d, void* e, void* f, int g, int h, int i, int j, int k);
extern "C" void* fn_801324FC(void* a, void* b, void* c);

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8008065c-0x800868f4 (51 functions). split_file divides it into the game's real files.

extern void* lbl_80283B18[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_800808C4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80283B18;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_80080A64(u8* p) {
    if (*(void**)(p + 0x3c0) == nullptr) {
        void* r;
        void* m = lbl_802FF0BC;
        u16 id = *(u16*)&lbl_801FA1CC;
        if (m != nullptr) {
            r = fn_8004D308(m, 1, id, p + 0x128, p + 0x13c, p + 0x144, 0xff, 0, 0, 0, 0);
        } else {
            r = nullptr;
        }
        *(void**)(p + 0x3c0) = r;
    }
    u8* e = *(u8**)(*(u8**)(*(u8**)(*(u8**)(p + 0x358) + 4) + 0x84) + 0xc) + (s8)p[0x459] * 0x30;
    u8* o = *(u8**)(p + 0x3c0);
    if (o != nullptr) {
        e = (u8*)fn_801324FC(e, o + 0x68, o + 0xa4);
    }
    return e;
}

extern u8 lbl_802EE470[];
extern void* lbl_802FDC98;
extern u8 lbl_802EE58C[];
extern "C" void fn_8000CB28(void* a, s16 b);
extern "C" void fn_8000CA54(void* a, s16 b);
extern "C" void fn_8000CBFC(void* a, s16 b);
extern "C" BOOL fn_80081098(u8* p, s32 mode)
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

extern "C" BOOL fn_800811B8(void);
extern "C" BOOL fn_800811B8(void)
{
    return TRUE;
}

extern "C" void fn_800811C0(u8* p1, u8* p2) {
    u32 i;
    s32 j;
    for (i = 0, j = 0; i < 8; i++, j += 8) {
        if (*(u16*)(p1 + (j + 0x16)) != 0) {
            u8* o = *(u8**)(p2 + 0x28);
            u8* q = *(u8**)(*(u8**)(lbl_802EE470 + 0x38) + 0x14);
            u8* r = ((u8* (*)(u8*, u32))(*(void***)o)[0x14])(o, i);
            *(f32*)(r + 0x1c) = *(f32*)(r + 0x1c) - *(f32*)(q + 0x424);
            *(f32*)(r + 0x20) = *(f32*)(r + 0x20) + *(f32*)(q + 0x428);
        }
    }
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_80081264(u8* p1, u8* p2) {
    s32 j;
    u8* base;
    u32 i;
    base = lbl_802EE470;
    for (i = 0, j = 0; i < 8; i++, j += 8) {
        if (*(u16*)(p1 + (j + 0x16)) != 0) {
            u8* o = *(u8**)(p2 + 0x28);
            u8* q = *(u8**)(*(u8**)(base + 0x38) + 0x14);
            u8* r = ((u8* (*)(u8*, u32))(*(void***)o)[0x14])(o, i);
            *(f32*)(r + 0x1c) = *(f32*)(r + 0x1c) + *(f32*)(q + 0x424);
            *(f32*)(r + 0x20) = *(f32*)(r + 0x20) + *(f32*)(q + 0x428);
        }
    }
}
#pragma pop

extern "C" void fn_800813BC(void);
extern "C" void fn_80081308(void) {
    fn_800813BC();
}

extern u8 lbl_8029F8D8[];
extern "C" void fn_801C61AC(void* p, f32 x, f32 y, f32 z);
extern "C" void fn_8000C8A4(void* m, s32 a, s32 b, s32 c);
extern "C" void fn_801C5D74(void* p, void* q);
extern "C" void fn_800827C4(u8* p)
{
	u8* q = *(u8**)(*(u8**)(p + 0x358) + 4);
	*(f32*)(q + 0x18) = *(f32*)(p + 0x144);
	*(f32*)(q + 0x1c) = *(f32*)(p + 0x148);
	*(f32*)(q + 0x20) = *(f32*)(p + 0x14c);
	fn_801C61AC(lbl_8029F8D8, *(f32*)(p + 0x128), *(f32*)(p + 0x12c), *(f32*)(p + 0x130));
	fn_8000C8A4(lbl_8029F8D8, *(s16*)(p + 0x13c), *(s16*)(p + 0x13e), *(s16*)(p + 0x140));
	fn_801C5D74(lbl_8029F8D8, *(u8**)(*(u8**)(p + 0x358) + 4) + 0x24);
}

extern "C" s32 fn_80083584(u8* p) {
    if (*(s8*)(p + 0x462) == 0) {
        (*(s8*)(p + 0x462))++;
    } else if (*(s8*)(p + 0x462) != -1) {
        fn_8000D6F4(p + 0x394);
    }
    return 1;
}

extern "C" BOOL fn_80083B80(void* param_1) {
    char* p = (char*)param_1;
    if (p[0x461] == 0) {
        p[0x461] = p[0x461] + 1;
    } else if (p[0x461] != -1) {
        float* sample;
        p[0x465] = fn_8000D6F4(p + 0x3a0);
        sample = *(float**)(p + 0x3a4);
        if (sample[3] < 0.0f) {
            if (*(float*)(p + 0x418) < sample[4]) {
                p[0x465] = 1;
            }
        } else if (sample[3] > 0.0f) {
            if (*(float*)(p + 0x418) > sample[4]) {
                p[0x465] = 1;
            }
        }
        *(float*)(p + 0x418) = (*(float**)(p + 0x3a4))[4];
    }
    return TRUE;
}

extern "C" void fn_80081328(void);
extern "C" void fn_80086710(void) {
    fn_80081328();
}

extern "C" void fn_80085F24(void);
extern "C" void fn_80086838(void) {
    fn_80085F24();
}

extern "C" void fn_80081CD4(void);
extern "C" void fn_80086858(void) {
    fn_80081CD4();
}

extern "C" BOOL fn_80086878(void);
extern "C" BOOL fn_80086878(void)
{
    return TRUE;
}

extern void* lbl_80283AF0[];
extern void* lbl_80281904[];
extern "C" void* fn_80086880(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = lbl_80283AF0;
        if ((s32)param_1 + 0x38 != 0) {
            *(void**)((char*)param_1 + 0x38) = lbl_80283B18;
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