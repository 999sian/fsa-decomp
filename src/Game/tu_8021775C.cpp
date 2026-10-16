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

extern "C" void fn_80217A74(void** p)
{
    fn_801EE434(p[0]);
    fn_801EE434(p[1]);
    p[0] = 0;
    p[1] = 0;
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
