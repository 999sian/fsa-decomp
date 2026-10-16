#include "types.h"
extern u8 lbl_802FCA30;

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80070d78-0x80077d64 (99 functions). split_file divides it into the game's real files.

extern char lbl_8029F8D8[];
extern "C" void fn_801C61AC(void*, f32, f32, f32);
extern "C" void fn_8000C8A4(void*, s16, s16, s16);
extern "C" void fn_80115D38(s16*, s16, int, int);
extern "C" void fn_801C5D74(void*, void*);
extern "C" int fn_80020EA4(void* p, int x);
extern "C" int fn_800183AC(void* p, void* f, void* a);
extern "C" int fn_800175B8(void* p);
extern u8 lbl_802FCA18;
extern "C" void fn_800636F4(void*, void*, s32);
extern char lbl_802B7CA0[];
extern u16 lbl_802FED38;
extern u8 lbl_802FF058;

struct Entry_80281230 { u16 a; u16 b; f32 f0; f32 f1; f32 f2; f32 f3; };
extern Entry_80281230 lbl_80281230[];
extern u16 lbl_802FCAD0[4];
extern u8 lbl_802FCAA8[8];
extern "C" void fn_80022438(void*, void*, s32, s32, f32, f32, f32, f32);
struct StateObj_80072080;
typedef BOOL (StateObj_80072080::*StateFunc_80072080)(int);
struct StateObj_80072080 {
    u8 pad[0x294];
    s8 m_state;
    StateFunc_80072080 m_func;
};
struct StateObj_80073ECC;
typedef BOOL (StateObj_80073ECC::*StateFunc_80073ECC)(int);
struct StateObj_80073ECC {
    u8 pad[0x2e4];
    s8 m_state;
    u8 pad2[0xb];
    StateFunc_80073ECC m_func;
};

struct VObj_800723CC {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

struct Entry_80281294 { u16 a; u16 b; f32 f; s16 c; s16 d; };
extern Entry_80281294 lbl_80281294[];
extern u16 lbl_802FCAD8[4];
extern Entry_80281294 lbl_802812AC[];
extern u16 lbl_802FCADC[4];
extern char lbl_802B7CA0[];
extern "C" void* fn_800638A4(void*, int, void*, int);
extern "C" void fn_8000DABC(void*, void*, void*, int, int, s16, s16, f32);
extern void* lbl_80281904[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80070D98(void);
extern "C" void fn_80070D78(void) {
    fn_80070D98();
}

extern "C" void fn_80070E64(void);
extern "C" void fn_800710A4(void) {
    fn_80070E64();
}

extern "C" BOOL fn_800710C4(void);
extern "C" BOOL fn_800710C4(void)
{
    return TRUE;
}

extern "C" BOOL fn_800710CC(void);
extern "C" BOOL fn_800710CC(void)
{
    return TRUE;
}

extern "C" int fn_800710D4(void)
{
    fn_800636F4(&lbl_802FCA18, lbl_802B7CA0 + 0x2200, 0x40);
    return 1;
}

extern u8 lbl_802FCA18;
extern u16 lbl_802FED38;
extern u8 lbl_802FF058;
extern s32 lbl_802FF190;
extern u32 lbl_802FF194;
extern f32 lbl_8030054C;
extern u8 lbl_802BB0FC[];
extern u8 lbl_802C4E74[];
extern u8 lbl_802EE470[];
extern u8 lbl_802EE58C[];
extern void* lbl_802FDC98;
struct Entry_801F9BAC { f32 x; f32 y; f32 z; };
extern Entry_801F9BAC lbl_801F9BAC[];
extern "C" void fn_800636F4(void*, void*, s32);
extern "C" void fn_80058B64(s32);
extern "C" void fn_80017FEC(s32, s32, void*, s32, s32, void*, s32);
extern "C" void fn_8000CB28(void*, s16);
extern "C" void fn_8002F358(s32, s32);
extern "C" void fn_80073AD8(u8*);
extern "C" void fn_800187B0(u8*);
extern "C" void fn_80018804(u8*, s32);
extern "C" void fn_80073F80(u8*, s32);
extern "C" void fn_80073DDC(u8*);
extern "C" BOOL fn_80073720(u8* p);
extern "C" int fn_8007110C(u8* p) {
    int iVar1 = fn_80020EA4(p + 0x244, (int)&lbl_802FCA18);
    if (iVar1 == 4) {
        if ((*(u32*)(p + 0xf8) & 8) == 0) {
            if (p != nullptr) {
                fn_800175B8(p);
            }
            *(u32*)(p + 0xf8) |= 8;
        }
        if ((u8)fn_800183AC(p, (void*)fn_80070D78, (void*)0xc40)) {
            u16 flags = lbl_802FED38;
            lbl_802FF058 = 0;
            lbl_802FED38 = (u16)(flags | 1);
            iVar1 = 4;
        } else {
            iVar1 = 5;
        }
    }
    return iVar1;
}

extern "C" void fn_800711CC(void);
extern "C" void fn_800711AC(void) {
    fn_800711CC();
}

extern "C" BOOL fn_80071BCC(void);
extern "C" BOOL fn_80071BCC(void)
{
    return TRUE;
}

extern "C" BOOL fn_80071BD4(void);
extern "C" BOOL fn_80071BD4(void)
{
    return TRUE;
}

extern "C" int fn_80071BDC(void)
{
    fn_800636F4(&lbl_802FCA30, lbl_802B7CA0 + 0x2200, 0x40);
    return 1;
}

extern u8 lbl_802FCA30;
extern "C" int fn_80071C14(u8* p) {
    int iVar1 = fn_80020EA4(p + 0x244, (int)&lbl_802FCA30);
    if (iVar1 == 4) {
        if ((*(u32*)(p + 0xf8) & 8) == 0) {
            if (p != nullptr) {
                fn_800175B8(p);
            }
            *(u32*)(p + 0xf8) |= 8;
        }
        if ((u8)fn_800183AC(p, (void*)fn_800711AC, (void*)0x2190)) {
            iVar1 = 4;
        } else {
            iVar1 = 5;
        }
    }
    return iVar1;
}

extern void* lbl_80247380[];
extern "C" void fn_80071CA0(void* p);
extern "C" void fn_80071CA0(void* p) {
    f32* f = (f32*)p;
    *(void**)p = lbl_80247380;
    f[1] = 0.0f;
    f[2] = 0.0f;
    f[3] = 0.0f;
    f[4] = 1.0f;
    f[5] = 1.0f;
    f[6] = 1.0f;
}

extern "C" void fn_80071D8C(void);
extern "C" void fn_80071CD0(void) {
    fn_80071D8C();
}

extern "C" void fn_80071FE4(u8* p) {
    u8* q = *(u8**)(p + 0x24c);
    s16 rot[3];
    *(f32*)(q + 0x18) = *(f32*)(p + 0x144);
    *(f32*)(q + 0x1c) = *(f32*)(p + 0x148);
    *(f32*)(q + 0x20) = *(f32*)(p + 0x14c);
    fn_801C61AC(lbl_8029F8D8, *(f32*)(p + 0x128), *(f32*)(p + 0x12c), *(f32*)(p + 0x130));
    fn_80115D38(rot, *(s16*)(p + 0x13c), 0, 0);
    fn_8000C8A4(lbl_8029F8D8, rot[0], rot[1], rot[2]);
    fn_801C5D74(lbl_8029F8D8, *(u8**)(p + 0x24c) + 0x24);
}

extern "C" BOOL fn_80072080(StateObj_80072080* self, StateFunc_80072080* func, int arg)
{
    if (self->m_func) {
        if (self->m_func) {
            self->m_state = -1;
            (self->*self->m_func)(arg);
        }
        self->m_func = *func;
        self->m_state = 0;
        (self->*self->m_func)(arg);
    }
    return TRUE;
}

extern "C" BOOL fn_80072134(s8* p)
{
    if (p[0x294] == 0) {
        p[0x294]++;
    }
    return TRUE;
}

extern "C" int fn_80071CF0(u8* p);
extern "C" void fn_80072240(u8* p) {
    fn_80071CF0(p);
}

extern "C" BOOL fn_80072260(void);
extern "C" BOOL fn_80072260(void)
{
    return TRUE;
}

extern "C" void fn_80041268(void*, void*, int);
extern "C" void fn_8000E774(void*, void*, int);
extern "C" void fn_801C5D74(void*, void*);
extern "C" void fn_8000EC78(void*);
extern "C" void fn_8000EBB8(void*);
extern "C" BOOL fn_800723CC(u8* p)
{
    fn_80041268(*(void**)(p + 0x24c), p + 0x180, 0);
    fn_8000E774(p + 0x250, *(void**)(p + 0x24c), (int)*(f32*)(*(u8**)(p + 0x254) + 0x10));
    if (*(u32*)(p + 0xb0) == 1) {
        (*(VObj_800723CC**)(p + 0x24c))->v2();
        fn_801C5D74(p + 0x264, *(void**)(*(u8**)(*(u8**)(p + 0x24c) + 0x84) + 0xc));
        fn_8000EC78(*(void**)(p + 0x24c));
    } else {
        fn_8000EBB8(*(void**)(p + 0x24c));
    }
    *(u32*)(*(u8**)(p + 0x24c) + 0xd8) = 0;
    return TRUE;
}

extern "C" BOOL fn_8007247C(void)
{
    return TRUE;
}

extern void* lbl_802473AC[];
extern "C" void fn_80072484(void* p);
extern "C" void fn_80072484(void* p) {
    f32* f = (f32*)p;
    *(void**)p = lbl_802473AC;
    f[1] = 0.0f;
    f[2] = 0.0f;
    f[3] = 0.0f;
    f[4] = 1.0f;
    f[5] = 1.0f;
    f[6] = 1.0f;
}

extern "C" void fn_80072570(void);
extern "C" void fn_800724B4(void) {
    fn_80072570();
}

extern "C" int fn_800183AC(void* p, void* f, void* a);
extern "C" int fn_800175B8(void* p);
extern "C" int fn_800726DC(u8* p);
extern void* lbl_8027F6DC[];
extern void* lbl_8027FDCC[];
#pragma dont_inline on
extern "C" int fn_800724D4(u8* p) {
    if ((*(u32*)(p + 0xf8) & 8) == 0) {
        if (p != nullptr) {
            fn_800175B8(p);
            *(void**)(p + 0x250) = lbl_8027F6DC;
            *(u32*)(p + 0x254) = 0;
            *(void**)(p + 0x250) = lbl_8027FDCC;
            *(u32*)(p + 0x25c) = 0;
        }
        *(u32*)(p + 0xf8) |= 8;
    }
    if ((u8)fn_800183AC(p, (void*)fn_800724B4, 0)) {
        return fn_800726DC(p);
    }
    return 5;
}
#pragma dont_inline reset

extern "C" void fn_800727C8(u8* p) {
    u8* q = *(u8**)(p + 0x24c);
    s16 rot[3];
    *(f32*)(q + 0x18) = *(f32*)(p + 0x144);
    *(f32*)(q + 0x1c) = *(f32*)(p + 0x148);
    *(f32*)(q + 0x20) = *(f32*)(p + 0x14c);
    fn_801C61AC(lbl_8029F8D8, *(f32*)(p + 0x128), *(f32*)(p + 0x12c), *(f32*)(p + 0x130));
    fn_80115D38(rot, *(s16*)(p + 0x13c), 0, 0);
    fn_8000C8A4(lbl_8029F8D8, rot[0], rot[1], rot[2]);
    fn_801C5D74(lbl_8029F8D8, *(u8**)(p + 0x24c) + 0x24);
}

extern "C" BOOL fn_80072864(StateObj_80072080* self, StateFunc_80072080* func, int arg)
{
    if (self->m_func) {
        if (self->m_func) {
            self->m_state = -1;
            (self->*self->m_func)(arg);
        }
        self->m_func = *func;
        self->m_state = 0;
        (self->*self->m_func)(arg);
    }
    return TRUE;
}

extern "C" BOOL fn_80072918(s8* p)
{
    if (p[0x294] == 0) {
        p[0x294]++;
    }
    return TRUE;
}

extern "C" int fn_800724D4(u8* p);
extern "C" void fn_80072A5C(u8* p) {
    fn_800724D4(p);
}

extern "C" BOOL fn_80072A7C(void);
extern "C" BOOL fn_80072A7C(void)
{
    return TRUE;
}

extern "C" BOOL fn_80072CD8(void);
extern "C" BOOL fn_80072CD8(void)
{
    return TRUE;
}

extern void* lbl_8024756C[];
extern f32 lbl_80300548;
extern f32 lbl_8030054C;
extern f32 lbl_80300550;
extern f32 lbl_80300554;
extern f32 lbl_80300558;
extern f32 lbl_8030055C;
extern f32 lbl_80300560;
extern "C" void fn_80072CE0(void* p) {
    f32* f = (f32*)p;
    s16* h = (s16*)p;
    u8* b = (u8*)p;
    f32 zero = lbl_80300548;
    *(void**)p = lbl_8024756C;
    f[1] = zero;
    f[2] = zero;
    f[3] = zero;
    f32 one = lbl_8030054C;
    f[4] = one;
    f[5] = one;
    f[6] = one;
    f[7] = lbl_80300550;
    f[8] = lbl_80300554;
    f[9] = lbl_80300558;
    f[10] = lbl_8030055C;
    f[11] = lbl_80300560;
    h[24] = 0x3c;
    h[25] = 0xf0;
    h[26] = 0x15cc;
    h[27] = 0x3c;
    h[28] = 0x6800;
    b[0x3a] = 0;
    b[0x3b] = 0;
    b[0x3c] = 0;
}

extern "C" void fn_80072E68(void);
extern "C" void fn_80072D6C(void) {
    fn_80072E68();
}

#pragma dont_inline on
extern "C" BOOL fn_80073720(u8* p) {
    u32 flags;
    if (lbl_802BB0FC[0xee]) {
        flags = lbl_802FF194 & ~4;
    } else {
        flags = lbl_802FF194 | 4;
    }
    lbl_802FF194 = flags;
    if (*(s32*)(p + 0x2c4) == 1 && lbl_8030054C == *(f32*)(*(u8**)(p + 0x254) + 0x1c)) {
        fn_8002F358(0x47, 0);
    }
    fn_80073AD8(p);
    fn_800187B0(p);
    fn_80018804(p, 0);
    fn_80073F80(p, 0);
    fn_80073DDC(p);
    return TRUE;
}
#pragma dont_inline reset

extern "C" BOOL fn_800738DC(u8* self, s32 idx)
{
    if (*(s32*)(self + 0x2c8) != idx) {
        Entry_80281230* e;
        f32 f0, f1;
        u16 k;
        *(s32*)(self + 0x2c8) = idx;
        e = &lbl_80281230[idx];
        f0 = e->f0;
        f1 = e->f1;
        *(u16*)(self + 0x2de) = e->a;
        k = lbl_802FCAD0[*(u16*)(self + 0x2de)];
        *(u8*)(self + 0x2e7) = 0;
        fn_80022438(*(void**)(self + 0x258), lbl_802FCAA8, k, e->b, f0, f1, e->f2, e->f3);
    }
    return 0;
}

extern "C" BOOL fn_8007395C(u8* self, int idx)
{
    Entry_80281294* e;
    f32 f;
    void* r;
    *(int*)(self + 0x2cc) = idx;
    e = &lbl_80281294[idx];
    f = e->f;
    r = fn_800638A4(lbl_802FCAA8, lbl_802FCAD8[e->a], lbl_802B7CA0 + 0x2200, 0x40);
    if (r == NULL) {
        return FALSE;
    }
    fn_8000DABC(self + 0x25c, *(u8**)(*(u8**)(*(u8**)(self + 0x254) + 4) + 4) + 0x58, r, 1, e->b, e->c, e->d, f);
}

extern "C" BOOL fn_80073A1C(u8* self, int idx)
{
    Entry_80281294* e;
    f32 f;
    void* r;
    *(int*)(self + 0x2d0) = idx;
    e = &lbl_802812AC[idx];
    f = e->f;
    r = fn_800638A4(lbl_802FCAA8, lbl_802FCADC[e->a], lbl_802B7CA0 + 0x2200, 0x40);
    if (r == NULL) {
        return FALSE;
    }
    fn_8000DABC(self + 0x268, *(u8**)(*(u8**)(self + 0x24c) + 4) + 0x58, r, 1, e->b, e->c, e->d, f);
}

extern "C" BOOL fn_80073ECC(StateObj_80073ECC* self, StateFunc_80073ECC* func, int arg)
{
    if (self->m_func) {
        if (self->m_func) {
            self->m_state = -1;
            (self->*self->m_func)(arg);
        }
        self->m_func = *func;
        self->m_state = 0;
        (self->*self->m_func)(arg);
    }
    return TRUE;
}

extern "C" void fn_80072D8C(void);
extern "C" void fn_80075550(void) {
    fn_80072D8C();
}

extern "C" BOOL fn_80075570(u8* p) {
    fn_800636F4((void*)&lbl_802FCAA8, lbl_802B7CA0 + 0x2200, 0x40);
    if (*(s8*)(p + 0x240) == 0) {
        fn_80058B64(0x14b0);
    }
    lbl_802FF190 = 0;
    return TRUE;
}

extern "C" void fn_800755D0(u8* p) {
    fn_80073720(p);
}

extern "C" void fn_8007356C(void);
extern "C" void fn_800755F0(void) {
    fn_8007356C();
}

extern "C" BOOL fn_80075610(void);
extern "C" BOOL fn_80075610(void)
{
    return TRUE;
}

extern "C" void fn_80075618(void* p) {
    if (lbl_802FF190 == 0) {
        Entry_801F9BAC entry;
        s32 off = *(s32*)(lbl_802BB0FC + 0x424) * 12;
        u8* base = (u8*)lbl_801F9BAC;
        entry.x = *(f32*)(base + off);
        entry.y = *(f32*)(base + off + 4);
        entry.z = *(f32*)(base + off + 8);
        fn_80017FEC(10, 0, &entry, 0, 0, p, 0);
    }
}

extern "C" void* fn_80075890(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80281904;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" BOOL fn_800759F0(u8* p, s32 param_2) {
    if (lbl_802C4E74[0xb7] != 0 && param_2 == 0) {
        u8* obj = *(u8**)(lbl_802EE470 + 0x38);
        u32 off = *(u16*)(p + 0x14) * 0x30;
        u8* r29 = *(u8**)(obj + 0x14);
        fn_801C5D74(*(u8**)(*(u8**)(obj + 0x84) + 0xc) + off, lbl_802FDC98);
        fn_8000CB28(lbl_802FDC98, (s16)*(s32*)(r29 + 0x3c8));
        fn_801C5D74(lbl_802FDC98, *(u8**)(*(u8**)(obj + 0x84) + 0xc) + off);
        fn_801C5D74(lbl_802FDC98, lbl_802EE58C);
    }
    return TRUE;
}

extern "C" BOOL fn_80075AA4(u8* p, s32 param_2) {
    if (param_2 == 0) {
        u8* obj = *(u8**)(lbl_802EE470 + 0x38);
        u32 off = *(u16*)(p + 0x14) * 0x30;
        u8* r29 = *(u8**)(obj + 0x14);
        fn_801C5D74(*(u8**)(*(u8**)(obj + 0x84) + 0xc) + off, lbl_802FDC98);
        fn_8000CB28(lbl_802FDC98, (s32)*(s16*)(r29 + 0x3f8));
        fn_801C5D74(lbl_802FDC98, *(u8**)(*(u8**)(obj + 0x84) + 0xc) + off);
        fn_801C5D74(lbl_802FDC98, lbl_802EE58C);
    }
    return TRUE;
}

extern "C" void fn_80075CB8(void);
extern "C" void fn_80075B40(void) {
    fn_80075CB8();
}

extern "C" void fn_800766B0(f32* out, u8* obj) {
    out[0] = *(f32*)(obj + 0x2c4);
    out[1] = *(f32*)(obj + 0x2c8);
    out[2] = *(f32*)(obj + 0x2cc);
}

extern "C" void fn_80075B60(void);
extern "C" void fn_80077B10(void) {
    fn_80075B60();
}

extern "C" void fn_80077314(void);
extern "C" void fn_80077CBC(void) {
    fn_80077314();
}

extern "C" void fn_8007634C(void);
extern "C" void fn_80077CDC(void) {
    fn_8007634C();
}

extern "C" BOOL fn_80077CFC(void);
extern "C" BOOL fn_80077CFC(void)
{
    return TRUE;
}