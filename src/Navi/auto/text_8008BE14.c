#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8008be14-0x8008db20 (36 functions). split_file divides it into the game's real files.

extern void* lbl_80284C98[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_8008BE64(void);
extern char lbl_802BB0FC[];
extern char lbl_801FDAC8[];
extern f32 lbl_802C53E4[];
extern "C" void fn_8008D820(void* p, s32 n);
extern void* lbl_8024751C[];
extern "C" void fn_8008BE14(void* p);
extern "C" void fn_8008BE14(void* p) {
    f32* f = (f32*)p;
    *(void**)p = lbl_8024751C;
    f[1] = 0.0f;
    f[2] = 0.0f;
    f[3] = 0.0f;
    f[4] = 1.0f;
    f[5] = 1.0f;
    f[6] = 1.0f;
}

extern "C" void fn_8008BE44(void) {
    fn_8008BE64();
}

extern "C" BOOL fn_8008C0A4(char* p) {
    if (p[0x260] == 0) {
        p[0x260]++;
    }
    return TRUE;
}

extern "C" BOOL fn_8008C4D4(void);
extern "C" BOOL fn_8008C4D4(void)
{
    return TRUE;
}

extern "C" void fn_8008C5F4(void);
extern "C" void fn_8008C4DC(void) {
    fn_8008C5F4();
}

extern f32 lbl_80300A8C;
extern f32 lbl_80300A90;
extern char lbl_802C5408[];
extern "C" void fn_80017FCC(void);
extern "C" BOOL fn_8008CE70(char* p) {
    if (p[0x2e0] == 0) {
        p[0x2e0]++;
    } else if (p[0x2e0] != -1) {
        f32* f = (f32*)lbl_802C5408;
        f[3] -= lbl_80300A8C;
        if (f[3] < lbl_80300A90) {
            fn_80017FCC();
        }
    }
    return TRUE;
}

extern char lbl_8029F8D8[];
extern f32 lbl_802C53CC[];
extern s16 lbl_802FF1E0[];
extern "C" void fn_801C61AC(void* p, f32 x, f32 y, f32 z);
extern "C" void fn_8000CB28(void* p, s32 n);
extern "C" void fn_8000CA54(void* p, s32 n);
extern "C" void fn_8000CBFC(void* p, s32 n);
extern "C" void fn_801C5D74(void* p, void* q);
extern s16 lbl_802FF1E0[3];
extern "C" void fn_8008CEDC(char* p) {
    char* sub = *(char**)(p + 0x24c);
    *(f32*)(sub + 0x18) = *(f32*)(p + 0x144);
    *(f32*)(sub + 0x1c) = *(f32*)(p + 0x148);
    *(f32*)(sub + 0x20) = *(f32*)(p + 0x14c);
    fn_801C61AC(lbl_8029F8D8, lbl_802C53CC[0], lbl_802C53CC[1], lbl_802C53CC[2]);
    fn_8000CB28(lbl_8029F8D8, lbl_802FF1E0[1]);
    fn_8000CA54(lbl_8029F8D8, lbl_802FF1E0[0]);
    fn_8000CBFC(lbl_8029F8D8, lbl_802FF1E0[2]);
    fn_801C5D74(lbl_8029F8D8, *(char**)(p + 0x24c) + 0x24);
}

extern "C" void fn_8008C4FC(void);
extern "C" void fn_8008D420(void) {
    fn_8008C4FC();
}

extern "C" void fn_8008C994(void);
extern "C" void fn_8008D4BC(void) {
    fn_8008C994();
}

extern "C" BOOL fn_8008D5B4(void);
extern "C" BOOL fn_8008D5B4(void)
{
    return TRUE;
}

extern "C" void fn_8008D6F8(f32* p) {
    f32 v[3] = {lbl_802C53E4[0], lbl_802C53E4[1], lbl_802C53E4[2]};
    p[0] = v[0];
    p[1] = v[1];
    p[2] = v[2];
}

extern "C" void fn_8008D938(void* p) {
    fn_8008D820(p, *(s32*)(lbl_802BB0FC + 0x3f0) + 1);
}

extern char lbl_802BB0FC[];
extern char lbl_801FDAC8[];
extern f32 lbl_802C53E4[];
extern "C" void fn_8008D820(void* p, s32 n);
extern "C" void fn_8008DA68(void* p) {
    s32 idx = *(s32*)(lbl_802BB0FC + 0x424);
    u32* src = (u32*)(lbl_801FDAC8 + idx * 12);
    u32* dst = (u32*)p;
    u32 a = src[0];
    u32 b = src[1];
    dst[0] = a;
    u32 c = src[2];
    dst[1] = b;
    dst[2] = c;
}

extern "C" void* fn_8008DAD8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80284C98;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
