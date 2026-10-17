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
#include "Game/ItemBase.h"

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

struct UnkObj8033D4CC {
    u8 pad0[4];
    s32 room;
    u8 pad8[0xc - 0x8];
    JGeometry::TVec3f mPos;
    u8 pad18[0x24 - 0x18];
    JGeometry::TVec3f mAnchor;
    u8 pad30[0x3c - 0x30];
    JGeometry::TVec3f mVel;
    u8 pad48[0x60 - 0x48];
    f32 mRect[4];
    u8 pad70[0x90 - 0x70];
    u32 mSpawnParam;
    u8 pad94[0x16c - 0x94];
    s32 m16c;
    u8 pad170[0x198 - 0x170];
    s32 mHandle;
    u8 pad19c[0x230 - 0x19c];
    s32 m230;
    s32 m234;
    JGeometry::TVec3f mPrev;
    u8 pad244[0x248 - 0x244];
    s32 m248;
    u8 pad24c[0x254 - 0x24c];
    s32 m254;
    s32 m258;
    s32 m25c;
    s32 m260;
    u8 m264;
    u8 pad265[0x268 - 0x265];
    s32 m268;
    s32 m26c;
    u8 m270;
    u8 m271;
    u8 m272;
};

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

struct UnkObj8033CD44 {
    u8 pad0[4];
    s32 unk4;
    u8 pad8[4];
    JGeometry::TVec3f mPos;
    u8 pad18[0x198 - 0x18];
    void* unk198;
    u8 pad19c[0x250 - 0x19c];
    s32 unk250;
    s32 unk254;
    u8 pad258[0x25c - 0x258];
    s32 state;
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

typedef f32 Mtx[3][4];
extern "C" void PSMTXIdentity(Mtx m);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 mode, f32 a, f32 b);
extern "C" void fn_803075AC(void* h, s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" void* fn_804032E8(u32 tag, const char* name);
extern "C" void fn_801EFD34(void* this_, void* res, DrawRec* rec, s32 n, f32 a, f32 b, f32 c);
extern "C" s32 lbl_804ABCA0[][4];
extern "C" f32 lbl_805421A0;
extern "C" f32 lbl_805421A4;
extern "C" f32 lbl_805421A8;
extern "C" f32 lbl_805421AC;
extern "C" f32 lbl_805421B4;
extern "C" void fn_8033CD44(UnkObj8033CD44* this_) {
    u8* base = (u8*)lbl_80471E28;
    const char* name;
    s32 id;

    switch (this_->state) {
    case 0:
    case 1:
    case 5:
        if (this_->state == 0) {
            name = (const char*)(base + 0x30);
            id = lbl_804ABCA0[0][this_->unk250] + 0x475;
        } else if (this_->state == 1) {
            name = (const char*)(base + 0x44);
            id = 0x1c1;
        } else {
            name = (const char*)(base + 0x44);
            id = 0x37c;
        }
        fn_801F06F0(this_, name, id, NULL, 3, lbl_805421A0, lbl_805421A0);
        fn_803075AC(this_->unk198, this_->unk4, &this_->mPos, id, 0, 2, -1, 0, 0, 0);
        return;
    case 2:
    case 6:
        name = (const char*)(base + 0x44);
        if (this_->state == 2) {
            id = lbl_804ABCA0[this_->unk254][this_->unk250] + 0x3b4;
            for (s32 j = 0; j < 2; j++) {
                f32 x = lbl_805421A8 * (f32)j + lbl_805421A4;
                for (s32 i = 0; i < 2; i++) {
                    f32 y = lbl_805421A8 * (f32)i + lbl_805421AC;
                    JGeometry::TVec3f saved = this_->mPos;
                    this_->mPos.add(JGeometry::TVec3f(x, y, lbl_805421B0));
                    fn_801F06F0(this_, name, id, NULL, 3, lbl_805421A0, lbl_805421A0);
                    this_->mPos = saved;
                }
            }
        } else {
            JGeometry::TVec3f saved = this_->mPos;
            this_->mPos.add(JGeometry::TVec3f(lbl_805421B0, lbl_805421A4, lbl_805421B0));
            fn_801F06F0(this_, name, 0x37d, NULL, 3, lbl_805421A0, lbl_805421A0);
            this_->mPos = saved;
        }
        {
            JGeometry::TVec3f saved = this_->mPos;
            this_->mPos.add(JGeometry::TVec3f(lbl_805421B0, lbl_805421A4, lbl_805421B0));
            fn_803075AC(this_->unk198, this_->unk4, &this_->mPos,
                        this_->state == 2 ? lbl_804ABCA0[0][this_->unk250] + 0x3ca : 0x37d, 0, 2, -1, 0, 0, 0);
            this_->mPos = saved;
        }
        return;
    case 3: {
        Mtx m;
        DrawRec rec;
        PSMTXIdentity(m);
        m[0][0] = lbl_805421B4;
        m[0][1] = lbl_805421B0;
        m[0][2] = lbl_805421B0;
        m[1][0] = lbl_805421B0;
        m[1][1] = lbl_805421B4;
        m[1][2] = lbl_805421B0;
        m[2][0] = lbl_805421B0;
        m[2][1] = lbl_805421B0;
        m[2][2] = lbl_805421B4;
        rec.w18 = m;
        fn_801F06F0(this_, (const char*)(base + 0x44), 0x1c1, &rec, 3, lbl_805421A0, lbl_805421A0);
        fn_803075AC(this_->unk198, this_->unk4, &this_->mPos, 0x1c1, 1, 2, -1, 0, 0, 0);
        return;
    }
    case 4: {
        void* res = fn_804032E8(0x54494d47, (const char*)(base + 0x58));
        fn_801EFD34(this_, res, NULL, 7, lbl_805421B0, lbl_805421B0, lbl_805421B0);
        return;
    }
    default:
        return;
    }
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

