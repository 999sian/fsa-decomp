#include "types.h"


extern "C" void fn_801EE434(void*);
extern "C" void __dl__FPv(void*);
extern "C" void fn_8013CB44(void*, void*, s32, s32, s32);
extern const f32 lbl_8053FC38;

extern "C" void fn_8021798C(void** p) {
    fn_8013CB44(p[0], (u8*)p[6] + 0xc, 1, 1, 1);
    fn_8013CB44(p[1], (u8*)p[6] + 0xc, 1, 1, 1);
}

extern "C" void fn_802179EC(void** p) {
    fn_801EE434(p[4]);
    fn_801EE434(p[5]);
    p[4] = 0;
    p[5] = 0;
}

extern "C" void fn_80217A30(void** p) {
    fn_801EE434(p[2]);
    fn_801EE434(p[3]);
    p[2] = 0;
    p[3] = 0;
}

extern "C" void* fn_8013CC50(u32, void*, u16, s32, f32, s32, s32, s32, s32);
extern f32 lbl_804CD838[];

extern "C" void fn_80217A74(void** p)
{
    fn_801EE434(p[0]);
    fn_801EE434(p[1]);
    p[0] = 0;
    p[1] = 0;
}

extern "C" f32 lbl_804CD838[];
struct Vec2F {
    f32 x;
    f32 y;
};

extern "C" void fn_80217AB8(u8* p) {
    u8* sub;
    void* obj;
    f32 y;
    f32 x;

    if (*(void**)(p + 0x10) == NULL) {
        sub = *(u8**)(p + 0x18);
        *(void**)(p + 0x10) = fn_8013CC50(*(u32*)(sub + 0x5fc), sub + 0x60c, 0x224, 1, 1.0f, 1, 0, 0, 1);
        obj = *(void**)(p + 0x10);
        if (obj != NULL) {
            *(f32*)((u8*)obj + 0x98) = lbl_804CD838[0];
            *(f32*)((u8*)obj + 0x9c) = lbl_804CD838[1];
            *(f32*)((u8*)obj + 0xa0) = lbl_804CD838[2];
            y = lbl_804CD838[1];
            x = lbl_804CD838[0];
            *(f32*)((u8*)obj + 0xb0) = x;
            *(f32*)((u8*)obj + 0xb4) = y;
        }
    }
    if (*(void**)(p + 0x14) == NULL) {
        sub = *(u8**)(p + 0x18);
        *(void**)(p + 0x14) = fn_8013CC50(*(u32*)(sub + 0x5fc), sub + 0x60c, 0x225, 1, 1.0f, 1, 0, 0, 1);
        obj = *(void**)(p + 0x14);
        if (obj != NULL) {
            *(f32*)((u8*)obj + 0x98) = lbl_804CD838[0];
            *(f32*)((u8*)obj + 0x9c) = lbl_804CD838[1];
            *(f32*)((u8*)obj + 0xa0) = lbl_804CD838[2];
            y = lbl_804CD838[1];
            x = lbl_804CD838[0];
            *(f32*)((u8*)obj + 0xb0) = x;
            *(f32*)((u8*)obj + 0xb4) = y;
        }
    }
}

extern "C" void fn_80217BC8(void** p) {
    u8* base;
    if (p[2] == 0) {
        base = (u8*)p[6];
        p[2] = fn_8013CC50(*(u32*)(base + 4), base + 0xc, 0x22f, 1, lbl_8053FC38, 1, 0, 0, 1);
        u8* r = (u8*)p[2];
        if (r != 0) {
            f32* tbl = lbl_804CD838;
            *(f32*)(r + 0x98) = tbl[0];
            *(f32*)(r + 0x9c) = tbl[1];
            *(f32*)(r + 0xa0) = tbl[2];
            *(f32*)(r + 0xb0) = tbl[0];
            *(f32*)(r + 0xb4) = tbl[1];
        }
    }
    if (p[3] == 0) {
        base = (u8*)p[6];
        p[3] = fn_8013CC50(*(u32*)(base + 4), base + 0xc, 0x230, 1, lbl_8053FC38, 1, 0, 0, 1);
        u8* r = (u8*)p[3];
        if (r != 0) {
            f32* tbl = lbl_804CD838;
            *(f32*)(r + 0x98) = tbl[0];
            *(f32*)(r + 0x9c) = tbl[1];
            *(f32*)(r + 0xa0) = tbl[2];
            *(f32*)(r + 0xb0) = tbl[0];
            *(f32*)(r + 0xb4) = tbl[1];
        }
    }
}

extern "C" void fn_80217CD8(void** p) {
    u8* base;
    if (p[0] == 0) {
        base = (u8*)p[6];
        u8* sub = base + 0xc;
        p[0] = fn_8013CC50(*(u32*)(base + 4), sub, 0x228, 1, lbl_8053FC38, 1, 0, 0, 1);
        u8* r = (u8*)p[0];
        if (r != 0) {
            f32* tbl = lbl_804CD838;
            *(f32*)(r + 0x98) = tbl[0];
            *(f32*)(r + 0x9c) = tbl[1];
            *(f32*)(r + 0xa0) = tbl[2];
            f32 y = tbl[1];
            *(f32*)(r + 0xb0) = tbl[0];
            *(f32*)(r + 0xb4) = y;
        }
    }
    if (p[1] == 0) {
        base = (u8*)p[6];
        u8* sub = base + 0xc;
        p[1] = fn_8013CC50(*(u32*)(base + 4), sub, 0x229, 1, lbl_8053FC38, 1, 0, 0, 1);
        u8* r = (u8*)p[1];
        if (r != 0) {
            f32* tbl = lbl_804CD838;
            *(f32*)(r + 0x98) = tbl[0];
            *(f32*)(r + 0x9c) = tbl[1];
            *(f32*)(r + 0xa0) = tbl[2];
            f32 y = tbl[1];
            *(f32*)(r + 0xb0) = tbl[0];
            *(f32*)(r + 0xb4) = y;
        }
    }
}

extern "C" void fn_80217DE8(void** p) {
    u8* r = (u8*)fn_8013CC50(*(u32*)((u8*)p[6] + 4), (u8*)p[6] + 0xc, 0x231, 1, lbl_8053FC38, 1, 0, 0, 1);
    u8* r2 = (u8*)fn_8013CC50(*(u32*)((u8*)p[6] + 4), (u8*)p[6] + 0xc, 0x232, 1, lbl_8053FC38, 1, 0, 0, 1);
    if (r != 0) {
        *(f32*)(r + 0x98) = lbl_804CD838[0];
        *(f32*)(r + 0x9c) = lbl_804CD838[1];
        *(f32*)(r + 0xa0) = lbl_804CD838[2];
        f32 y = lbl_804CD838[1];
        *(f32*)(r + 0xb0) = lbl_804CD838[0];
        *(f32*)(r + 0xb4) = y;
    }
    if (r2 != 0) {
        *(f32*)(r2 + 0x98) = lbl_804CD838[0];
        *(f32*)(r2 + 0x9c) = lbl_804CD838[1];
        *(f32*)(r2 + 0xa0) = lbl_804CD838[2];
        f32 y = lbl_804CD838[1];
        *(f32*)(r2 + 0xb0) = lbl_804CD838[0];
        *(f32*)(r2 + 0xb4) = y;
    }
}

extern "C" void* fn_8013CC50(u32, void*, u16, s32, f32, s32, s32, s32, s32);
extern u16 lbl_8046A5A0[];
extern f32 lbl_804CD838[];
extern const f32 lbl_8053FC38;
extern "C" void fn_80217ED4(u8* self) {
    s32 i = 0;
    u8* obj = *(u8**)(self + 0x18);
    u16* ids = lbl_8046A5A0;
    u8* pos = obj + 0xc;
    f32* tbl = lbl_804CD838;
    do {
        u8* r = (u8*)fn_8013CC50(*(u32*)(obj + 4), pos, *ids, 1, lbl_8053FC38, 1, 0, 0, 1);
        if (r != 0) {
            *(f32*)(r + 0x98) = lbl_804CD838[0];
            *(f32*)(r + 0x9c) = tbl[1];
            *(f32*)(r + 0xa0) = tbl[2];
            f32 y = tbl[1];
            *(f32*)(r + 0xb0) = lbl_804CD838[0];
            *(f32*)(r + 0xb4) = y;
        }
        i++;
        ids++;
    } while (i < 6);
}

extern "C" void** dtor_80217F80(void** p, s16 flag) {
    if (p != 0) {
        fn_801EE434(p[0]);
        fn_801EE434(p[1]);
        p[0] = 0;
        p[1] = 0;
        fn_801EE434(p[2]);
        fn_801EE434(p[3]);
        p[2] = 0;
        p[3] = 0;
        fn_801EE434(p[4]);
        fn_801EE434(p[5]);
        p[4] = 0;
        p[5] = 0;
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_80218020(void** p) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
}
