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
s32 fn_80239108(s32);
s32 fn_80238BC4(s32);
void fn_80238E08(s32);
void* fn_802D6A9C(void);
void fn_802D7584(void*, s32, u8);
void fn_801F0E34(void*, s32, s32);
s32 fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
void fn_8022FEB8(f32*, s32, s32, s32, s32);
s32 fn_8022FD8C(s32);
f32* fn_8023E724(s32);
bool fn_802300EC(s32);
bool fn_8038C678(s32, s32, s32, s32, void*, s32);
s32 fn_80230CFC(s32);
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
    u8 pad70[0x80 - 0x70];
    f32 mRect2[4];
    u32 mSpawnParam;
    u8 pad94[0xb8 - 0x94];
    s32 m0b8;
    u8 padbc[0x16c - 0xbc];
    s32 m16c;
    u8 pad170[0x198 - 0x170];
    s32 mHandle;
    u8 pad19c[0x1a4 - 0x19c];
    s32 m1a4;
    u8 pad1a8[0x230 - 0x1a8];
    s32 m230;
    s32 m234;
    JGeometry::TVec3f mPrev;
    s32 m244;
    s32 m248;
    s32 m24c;
    s32 m250;
    s32 m254;
    s32 m258;
    s32 m25c;
    s32 m260;
    u8 m264;
    u8 m265;
    u8 pad266[0x268 - 0x266];
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

extern f32 lbl_805421CC;
extern f32 lbl_805421D0;
extern f32 lbl_805421D4;
extern f32 lbl_805421D8;
extern JGeometry::TVec3f lbl_804A79E0[];
extern JGeometry::TVec3f lbl_804AC2A8[];
s32 fn_80239108(s32);
s32 fn_80238BC4(s32);
void fn_80238E08(s32);
void* fn_802D6A9C(void);
void fn_802D7584(void*, s32, u8);
void fn_801F0E34(void*, s32, s32);
s32 fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
void fn_8022FEB8(f32*, s32, s32, s32, s32);
s32 fn_8022FD8C(s32);
f32* fn_8023E724(s32);
bool fn_802300EC(s32);
bool fn_8038C678(s32, s32, s32, s32, void*, s32);
s32 fn_80230CFC(s32);
extern f32 lbl_805421A0;
bool fn_8033D264(void*, u8);
extern "C" void fn_8033D4CC(UnkObj8033D4CC* self) {
    JGeometry::TVec3f off;
    JGeometry::TVec3f saved;
    JGeometry::TVec3f tmp;
    f32 rect[4];
    f32 f31;
    if (fn_80239108(self->mHandle) >= self->m260) {
        if (PSVECDistance(&self->mPos, &self->mAnchor) < (f32)(self->m260 << 4) - lbl_805421C8) {
            s32 idx = fn_80238BC4(self->mHandle);
            saved = self->mPos;
            off.x = lbl_804A79E0[idx].x;
            off.y = lbl_804A79E0[idx].y;
            off.z = lbl_804A79E0[idx].z;
            self->mPos.add(off);
            bool hit = fn_801F2618(self, NULL, 0);
            if (hit) {
                self->mPos = saved;
                return;
            }
            self->mPos = saved;
            if (self->m270 == 1) {
                if (self->m26c == 0) {
                    self->m26c = idx + 1;
                } else if (idx + 1 != self->m26c) {
                    return;
                }
            }
            if (self->m260 == 2) {
                if (!fn_8033D264((UnkObj8033D264*)self, (u8)idx)) {
                    return;
                }
            }
            if (self->m264 == 0) {
                fn_802D7584(fn_802D6A9C(), self->m16c, (u8)(idx + 1));
            }
            if (idx >= 0 && idx < 4) {
                fn_80238E08(self->mHandle);
                switch (self->m25c) {
                case 0:
                case 1:
                case 5:
                    f31 = lbl_805421CC;
                    self->mVel.x = lbl_804AC2A8[idx].x;
                    self->mVel.y = lbl_804AC2A8[idx].y;
                    self->mVel.z = lbl_804AC2A8[idx].z;
                    self->mVel.scale(f31);
                    break;
                case 2:
                case 3:
                case 4:
                case 6:
                    f31 = lbl_805421D0;
                    self->mVel.x = lbl_804AC2A8[idx].x;
                    self->mVel.y = lbl_804AC2A8[idx].y;
                    self->mVel.z = lbl_804AC2A8[idx].z;
                    self->mVel.scale(f31);
                    break;
                }
            }
            if (self->m271 == 1) {
                self->m271 = 0;
            } else {
                self->mPrev.x = self->mPos.x;
                self->mPrev.y = self->mPos.y;
                self->mPrev.z = self->mPos.z;
            }
            fn_801F0E34(self, 0x30004, 0);
            self->m272 = 1;
            if (self->m25c == 4) {
                if (idx == 0) {
                    self->m230 = fn_8013CC50(self->room, &self->mPos, lbl_805421A0, 0x31a, 1, 1, 0, 0, 1);
                } else if (idx == 1) {
                    self->m230 = fn_8013CC50(self->room, &self->mPos, lbl_805421A0, 0x31b, 1, 1, 0, 0, 1);
                } else if (idx == 2) {
                    self->m230 = fn_8013CC50(self->room, &self->mPos, lbl_805421A0, 0x31c, 1, 1, 0, 0, 1);
                } else {
                    self->m230 = fn_8013CC50(self->room, &self->mPos, lbl_805421A0, 0x319, 1, 1, 0, 0, 1);
                }
            }
        }
    } else {
        if ((self->mSpawnParam >> 16) & 1) {
            if (PSVECDistance(&self->mPos, &self->mAnchor) > lbl_805421A0) {
                if (self->m248 == 0) {
                    f32 zero = lbl_805421B0;
                    self->mVel.x = zero;
                    self->mVel.y = zero;
                    self->mVel.z = zero;
                    switch (self->m25c) {
                    case 0:
                    case 1:
                    case 5:
                        f31 = lbl_805421D4;
                        break;
                    case 2:
                    case 3:
                    case 4:
                    case 6:
                        f31 = lbl_805421D8;
                        break;
                    }
                    if (self->mPos.x > self->mAnchor.x) {
                        self->mVel.x = -f31;
                    } else if (self->mPos.x < self->mAnchor.x) {
                        self->mVel.x = f31;
                    }
                    if (self->mPos.y > self->mAnchor.y) {
                        self->mVel.y = -f31;
                    } else if (self->mPos.y < self->mAnchor.y) {
                        self->mVel.y = f31;
                    }
                    self->mPrev.x = self->mPos.x;
                    self->mPrev.y = self->mPos.y;
                    self->mPrev.z = self->mPos.z;
                    fn_801F0E34(self, 0x30004, 0);
                } else {
                    self->m248--;
                }
                return;
            }
        }

        rect[0] = self->mRect[0] + self->mPos.x;
        rect[1] = self->mRect[1] + self->mPos.y;
        rect[2] = self->mRect[2] + self->mPos.x;
        rect[3] = self->mRect[3] + self->mPos.y;
        if (self->m25c != 0) {
            if (self->m25c != 2) {
                return;
            }
            fn_8022FEB8(rect, self->room, self->mHandle, 1, 0);
        }
        self->m258 = fn_8022FD8C(self->mHandle);
        if (self->m258 < 0) {
            return;
        }
        f32* p = fn_8023E724(self->m258);
        if (p[2] != lbl_805421B0) {
            return;
        }
        if (!fn_802300EC(self->m258)) {
            return;
        }
        tmp = self->mPos;
        if (!fn_8038C678(self->m258, self->m268, self->mHandle, self->room, &tmp, 0)) {
            return;
        }
        self->m234 = 1;
        self->m254 = fn_80230CFC(self->m258);
        self->m254 ^= 1;
    }
}

