#include "types.h"
#include "Game/ItemBase.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).
#include "Game/Actor.h"
struct DrawActor801EDD0C : public Actor {
    u8 pad230[0x248 - 0x230];
    s32 state248;
    u8 pad24c[0x280 - 0x24c];
    s32 texture280;
    u8 pad284[0x554 - 0x284];
    f32 scale554;
    u8 pad558[0x5d1 - 0x558];
    u8 flag5d1;
};

extern "C" f64 __fsel(f64, f64, f64);
extern "C" void* fn_804032E8(u32, const void*);
extern "C" void fn_801EF830(s32, void*, DrawRec*, u32, void*, u32, void*);
extern "C" void fn_801EFD34(void*, void*, DrawRec*, s32, f32, f32, f32);
extern "C" f32 fn_802F5FF4(f32);
extern "C" const void* lbl_804A5760[];
extern "C" f32 lbl_8053F0B8;
extern "C" f32 lbl_8053F0BC;
extern "C" void fn_801EDD0C(u8* self) {
    void* res = fn_804032E8('TIMG', lbl_804A5760[*(s32*)(self + 0x280)]);
    DrawRec rec;
    f32 m[3][4];
    rec.b1f = 0;
    rec.b1c = 1;
    rec.b1d = 1;
    u32 mask = 7;
    if (self[0x5d1]) mask = 0x407;
    ((u8*)&rec.w10)[3] = 0;
    f32 z = 1.0f + *(f32*)(self + 0x554);
    z = __fsel(0.001f - z, 0.001f, z);
    m[0][3] = 0.0f; m[1][3] = 0.0f; m[2][3] = 0.0f;
    m[0][0] = 1.0f; m[0][1] = 0.0f; m[0][2] = 0.0f;
    m[1][0] = 0.0f; m[1][1] = 1.0f; m[1][2] = 0.0f;
    m[2][0] = 0.0f; m[2][1] = 0.0f; m[2][2] = z;
    rec.w18 = &m;
    if (*(s32*)(self + 0x248) == 5) {
        if (*(u32*)(self + 0x138) == 0) {
            fn_801EF830(*(s32*)(self + 4), self + 0xc, &rec, mask, 0, 0, res);
        }
        f32 ratio = 1.0f / fn_802F5FF4(lbl_8053F0B8);
        f32 scale = fn_802F5FF4(*(f32*)(self + 0x14)) * ratio;
        f32 v00 = m[0][0] * scale;
        f32 v10 = m[1][0] * scale;
        f32 v20 = m[2][0] * scale;
        f32 v01 = m[0][1] * scale;
        f32 v11 = m[1][1] * scale;
        f32 v21 = m[2][1] * scale;
        f32 v02 = m[0][2] * scale;
        f32 v12 = m[1][2] * scale;
        f32 v22 = m[2][2] * scale;
        f32 v03 = m[0][3] * scale;
        f32 v13 = m[1][3] * scale;
        f32 v23 = m[2][3] * scale;
        m[0][0] = v00;
        m[1][0] = v10;
        m[2][0] = v20;
        m[0][1] = v01;
        m[1][1] = v11;
        m[2][1] = v21;
        m[0][2] = v02;
        m[1][2] = v12;
        m[2][2] = v22;
        m[0][3] = v03;
        m[1][3] = v13;
        m[2][3] = v23;
        rec.w18 = &m;
        fn_801EFD34(self, res, &rec, -1, 0.0f, -12.0f * lbl_8053F0BC, 0.0f);
    } else {
        fn_801EFD34(self, res, &rec, mask, 0.0f, -12.0f * lbl_8053F0BC, 0.0f);
    }
}
