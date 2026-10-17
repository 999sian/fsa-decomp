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
extern char lbl_804AC2D8[];
void __dt__5ActorFv(void*, s32);
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

extern "C" void* fn_8033CCE4(void* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804AC2D8;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" bool fn_8033D264(UnkObj8033D264* self, u8 dir) {
    f32 zero = lbl_805421B0;
    bool result = false;
    const JGeometry::TVec3f& off = lbl_80471E28[dir];
    self->mOffset.x = off.x;
    self->mOffset.y = off.y;
    self->mOffset.z = off.z;
    JGeometry::TVec3f saved = self->mPos;
    self->mPos.add(self->mOffset);
    JGeometry::TVec3f out(zero, zero, zero);
    if (fn_801F2618(self, &out, 0)) {
        switch (dir) {
        case 0:
            if (out.x >= lbl_805421B0) result = true;
            break;
        case 1:
            if (out.x <= lbl_805421B0) result = true;
            break;
        case 2:
            if (out.y >= lbl_805421B0) result = true;
            break;
        case 3:
            if (out.y <= lbl_805421B0) result = true;
            break;
        }
    } else {
        result = true;
    }
    if (!result) {
        f32 rect[4];
        rect[0] = self->mRect[0];
        rect[1] = self->mRect[1];
        rect[2] = self->mRect[2];
        rect[3] = self->mRect[3];
        rect[0] += self->mPos.x;
        rect[2] += self->mPos.x;
        rect[1] += self->mPos.y;
        rect[3] += self->mPos.y;
        result = true;
        for (int i = 0; i < 4; i++) {
            if (fn_8023B0F4(i, rect, self->unk4, lbl_805421B0, 0)) {
                if (fn_8022CAF8(i) != 5 || !fn_8022F478(i)) {
                    if (fn_80238CB4(i) != self->unk198) result = false;
                }
            }
        }
    }
    self->mPos = saved;
    self->mOffset.set(lbl_805421B0, lbl_805421B0, lbl_805421B0);
    return result;
}

extern f32 lbl_805421C8;
extern char lbl_804AC2D8[];
void __dt__5ActorFv(void*, s32);
extern "C" f32 fn_8033D4AC(f32 a, f32 b, f32 c) {
    f32 t = c + lbl_805421C8;
    if (a < b) {
        return b - t;
    }
    return b + t;
}

