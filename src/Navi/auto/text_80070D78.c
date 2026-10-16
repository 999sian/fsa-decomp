#include "types.h"
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

struct StateObj_80072080;
typedef BOOL (StateObj_80072080::*StateFunc_80072080)(int);
struct StateObj_80072080 {
    u8 pad[0x294];
    s8 m_state;
    StateFunc_80072080 m_func;
};

struct VObj_800723CC {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

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
    *(void**)p = lbl_8024756C;
    ((f32*)p)[1] = lbl_80300548;
    ((f32*)p)[2] = lbl_80300548;
    ((f32*)p)[3] = lbl_80300548;
    ((f32*)p)[4] = lbl_8030054C;
    ((f32*)p)[5] = lbl_8030054C;
    ((f32*)p)[6] = lbl_8030054C;
    ((f32*)p)[7] = lbl_80300550;
    ((f32*)p)[8] = lbl_80300554;
    ((f32*)p)[9] = lbl_80300558;
    ((f32*)p)[10] = lbl_8030055C;
    ((f32*)p)[11] = lbl_80300560;
    ((s16*)p)[24] = 0x3c;
    ((s16*)p)[25] = 0xf0;
    ((s16*)p)[26] = 0x15cc;
    ((s16*)p)[27] = 0x3c;
    ((s16*)p)[28] = 0x6800;
    ((u8*)p)[0x3a] = 0;
    ((u8*)p)[0x3b] = 0;
    ((u8*)p)[0x3c] = 0;
}

extern "C" void fn_80072E68(void);
extern "C" void fn_80072D6C(void) {
    fn_80072E68();
}

extern "C" void fn_80072D8C(void);
extern "C" void fn_80075550(void) {
    fn_80072D8C();
}

extern "C" void fn_80073720(void);
extern "C" void fn_800755D0(void) {
    fn_80073720();
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

extern "C" void* fn_80075890(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80281904;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80075CB8(void);
extern "C" void fn_80075B40(void) {
    fn_80075CB8();
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

