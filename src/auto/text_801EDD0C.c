#include "types.h"
#include "Game/ItemBase.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "Game/Actor.h"
#include "dolphin/gx.h"

extern "C" f64 __fsel(f64, f64, f64);
static inline f32 clampDrawScale(f32 value, f32 minimum) {
    return __fsel(minimum - value, minimum, value);
}
extern "C" void* fn_804032E8(u32, const void*);
extern "C" void fn_801EF830(s32, void*, DrawRec*, u32, void*, u32, void*);
extern "C" void fn_801EFD34(void*, void*, DrawRec*, s32, f32, f32, f32);
extern "C" f32 fn_802F5FF4(f32);
extern "C" const void* lbl_804A5760[];
extern "C" f32 lbl_8053F0B8;
extern "C" f32 lbl_8053F0BC;
#pragma opt_propagation on
extern "C" f32 lbl_8053F720;
#pragma opt_propagation on
extern "C" void fn_801EDD0C(u8* __restrict self) {
    void* res = fn_804032E8('TIMG', lbl_804A5760[*(s32*)(self + 0x280)]);
    DrawRec rec;
    f32 m[3][4];
    rec.b1f = 0;
    rec.b1c = 1;
    rec.b1d = 1;
    u32 mask = 7;
    if (self[0x5d1]) mask = 0x407;
    ((s8*)&rec.w10)[3] = 0;
    f32 z = 1.0f + *(f32*)(self + 0x554);
    f32 minScale = lbl_8053F720;
    m[0][3] = 0.0f; m[1][3] = 0.0f; m[2][3] = 0.0f;
    m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f;
    m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f;
    m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = __fsel(minScale - z, minScale, z);
    rec.w18 = &m;
    if (*(s32*)(self + 0x248) == 5) {
        if (*(u32*)(self + 0x138) == 0) {
            fn_801EF830(*(s32*)(self + 4), self + 0xc, &rec, mask, 0, 0, res);
        }
        f32 ratio = 1.0f / fn_802F5FF4(lbl_8053F0B8);
        f32 scale = fn_802F5FF4(*(f32*)(self + 0x14));
        scale *= ratio;
        m[0][0] *= scale;
        m[1][0] *= scale;
        m[2][0] *= scale;
        m[0][1] *= scale;
        m[1][1] *= scale;
        m[2][1] *= scale;
        m[0][2] *= scale;
        m[1][2] *= scale;
        m[2][2] *= scale;
        m[0][3] *= scale;
        m[1][3] *= scale;
        m[2][3] *= scale;
        rec.w18 = &m;
        fn_801EFD34(self, res, &rec, -1, 0.0f, -12.0f * lbl_8053F0BC, 0.0f);
    } else {
        fn_801EFD34(self, res, &rec, mask, 0.0f, -12.0f * lbl_8053F0BC, 0.0f);
    }
}
