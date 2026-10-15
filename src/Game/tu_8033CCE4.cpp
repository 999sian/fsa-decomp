#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"

struct Obj8033D264 {
    u8 pad0[4];
    u32 room;
    u8 pad8[0xc - 0x8];
    JGeometry::TVec3<f32> pos;
    u8 pad18[0x3c - 0x18];
    JGeometry::TVec3<f32> vel;
    u8 pad48[0x60 - 0x48];
    JGeometry::TBox2<f32> bounds;
    u8 pad70[0x198 - 0x70];
    s32 x198;
};
#include "JSystem/JGeometry/Vec.h"

extern "C" {
extern f32 lbl_805421B0;
extern JGeometry::TVec3f lbl_80471E28[];
bool fn_801F2618(void*, JGeometry::TVec3f*, int);
bool fn_8023B0F4(int, f32*, int, f32, int);
int fn_8022CAF8(int);
bool fn_8022F478(int);
int fn_80238CB4(int);
}

struct UnkObj8033D264 {
    u8 pad0[4];
    int unk4;
    u8 pad8[4];
    JGeometry::TVec3f mPos;
    u8 pad18[0x3c - 0x18];
    JGeometry::TVec3f mOffset;
    u8 pad48[0x60 - 0x48];
    f32 mRect[4];
    u8 pad70[0x198 - 0x70];
    int unk198;
};
