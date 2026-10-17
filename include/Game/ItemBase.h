#ifndef GAME_ITEMBASE_H
#define GAME_ITEMBASE_H

// Intermediate actor base class used by 31 actors (ROPE, PAME, MIRA, ZNRA,
// FALL, EZMR, EZOB, BMST, LNBM, TNDR, SLGE, BOGF, BGBL, ICHL, BOIT, BOIB, THNK,
// TINB, FSPO, FSOB, HRMN, FOSL, FOBR, ZASL, FLOR, RUSA, ARIJ, SLEF, KEPO, EZGE,
// NAVI). Real name unknown.
//
// Retail evidence (G4SE01):
//   ctor    0x801D0F40 (TU game/tu_801CDC8C.cpp, 0x801CDC8C-0x801D11FC)
//   dtor    0x801B7E1C (weak/inline, first emitted in the ROPE TU)
//   vtable  lbl_804A4808 (.data), no RTTI header, 39 slots:
//           0 dtor, 1 fn_801D0ED0, 3 fn_801CDD58, 19 fn_801D0ECC,
//           20..38 fn_801CECEC..fn_801CE00C (new virtuals, see below);
//           slots 2 and 4..18 are inherited from Actor (0x801F5AE0 ctor).
//   size    >= 0x2A8 (smallest child allocation); member object at 0x270
//           (ctor fn_801D267C, holds a J3DFrameCtrl at +0x24).
//
// Actor itself (0x000-0x230) is owned by  (include/Game/Actor.h on the
// /* branches); it is only padded here so this header stays independent.
// Virtual slot names are placeholders: vNN = vtable slot NN.

#include "types.h"

// 0x3C-byte draw record passed to Actor draw fn_801F06F0 (same layout as
//  "Rec" in src/Game/Actor.cpp). The ctor is inlined at every use.
struct DrawRec {
    DrawRec() {
        w10 = -1;
        w14 = -1;
        for (u32 i = 0; (u8)i < 0x10; i += 8) {
            ids[(u8)i] = i;
            ids[(u8)(i + 1)] = i + 1;
            ids[(u8)(i + 2)] = i + 2;
            ids[(u8)(i + 3)] = i + 3;
            ids[(u8)(i + 4)] = i + 4;
            ids[(u8)(i + 5)] = i + 5;
            ids[(u8)(i + 6)] = i + 6;
            ids[(u8)(i + 7)] = i + 7;
        }
        w10 = -1;
        w14 = 0;
        w18 = 0;
        b1c = 0;
        b1d = 0;
        b1e = 0;
        b1f = 1;
        b20 = 1;
        b21 = 0;
        b22 = 0;
        b23 = 0;
        b24 = 0;
        b25 = 0;
        b26 = 1;
        w28 = 3;
        b2c = 1;
        b2d = 0;
        b2e = 0;
        w30 = -1;
        w34 = 0;
        w38 = 2;
    }
    /* 0x00 */ u8 ids[0x10];
    /* 0x10 */ s32 w10;
    /* 0x14 */ s32 w14;
    /* 0x18 */ void* w18;
    /* 0x1c */ u8 b1c;
    /* 0x1d */ s8 b1d;
    /* 0x1e */ u8 b1e;
    /* 0x1f */ u8 b1f;
    /* 0x20 */ u8 b20;
    /* 0x21 */ u8 b21;
    /* 0x22 */ u8 b22;
    /* 0x23 */ u8 b23;
    /* 0x24 */ u8 b24;
    /* 0x25 */ u8 b25;
    /* 0x26 */ u8 b26;
    /* 0x28 */ s32 w28;
    /* 0x2c */ u8 b2c;
    /* 0x2d */ u8 b2d;
    /* 0x2e */ u8 b2e;
    /* 0x30 */ s32 w30;
    /* 0x34 */ s32 w34;
    /* 0x38 */ s32 w38;
};

// Axis-aligned area bounds check used by many ItemBase children:
// bounds = {minX, minY, maxX, maxY}; pos = actor position (Actor+0xC).
// Retail keeps the result in a register initialised to false.
inline bool ItemBase_inArea(const f32* bounds, const f32* pos) {
    bool inside = false;
    f32 x = pos[0];
    if (x >= bounds[0]) {
        f32 y = pos[1];
        if (y >= bounds[1] && x < bounds[2] && y < bounds[3]) {
            inside = true;
        }
    }
    return inside;
}

class ItemBase {
public:
    /* 0x00 */ virtual ~ItemBase();
    /* 0x01 */ virtual void v01();
    /* 0x02 */ virtual void v02();
    /* 0x03 */ virtual void v03();
    /* 0x04 */ virtual void v04();
    /* 0x05 */ virtual void v05();
    /* 0x06 */ virtual void v06();
    /* 0x07 */ virtual void v07();
    /* 0x08 */ virtual void v08();
    /* 0x09 */ virtual void v09();
    /* 0x0A */ virtual void v10();
    /* 0x0B */ virtual void v11();
    /* 0x0C */ virtual void v12();
    /* 0x0D */ virtual int v13();
    /* 0x0E */ virtual void v14();
    /* 0x0F */ virtual void v15();
    /* 0x10 */ virtual void v16();
    /* 0x11 */ virtual int v17(int a, f32* b);
    /* 0x12 */ virtual int v18(int a, f32* b);
    /* 0x13 */ virtual void v19();
    /* 0x14 */ virtual int v20();
    /* 0x15 */ virtual void v21();
    /* 0x16 */ virtual void v22();
    /* 0x17 */ virtual void v23();
    /* 0x18 */ virtual void v24();
    /* 0x19 */ virtual void v25();
    /* 0x1A */ virtual void v26();
    /* 0x1B */ virtual void v27();
    /* 0x1C */ virtual void v28();
    /* 0x1D */ virtual void v29();
    /* 0x1E */ virtual void v30();
    /* 0x1F */ virtual void v31();
    /* 0x20 */ virtual void v32();
    /* 0x21 */ virtual void v33();
    /* 0x22 */ virtual void v34();
    /* 0x23 */ virtual void v35();
    /* 0x24 */ virtual void v36();
    /* 0x25 */ virtual void v37();
    /* 0x26 */ virtual void v38();

    /* 0x004 */ u8 mActor[0x230 - 0x4]; // Actor fields (see  Actor.h)
    /* 0x230 */ u32 m230;               // flags; low 3 bits = state gate
    /* 0x234 */ f32 m234;
    /* 0x238 */ f32 m238;
    /* 0x23C */ f32 m23C;
    /* 0x240 */ u8 m240;
    /* 0x244 */ u32 m244;               // ctor: 8; v01 copies Actor+0x108
    /* 0x248 */ u32 m248;
    /* 0x24C */ s32 m24C;               // counter, clamped >= 0 by v37
    /* 0x250 */ u32 m250;
    /* 0x254 */ f32 m254;
    /* 0x258 */ f32 m258;
    /* 0x25C */ f32 m25C;
    /* 0x260 */ f32 m260;
    /* 0x264 */ f32 m264;
    /* 0x268 */ f32 m268;
    /* 0x26C */ f32 m26C;
    /* 0x270 */ u8 m270[0x38];          // sub-object, ctor fn_801D267C
};

#endif
