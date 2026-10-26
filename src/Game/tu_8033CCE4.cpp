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
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "Game/ItemBase.h"

extern "C" {
extern const f32 lbl_805421B0;
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

static inline bool isGroundHeight(const f32 zero, const f32 height) {
    return zero == height;
}

extern "C" void fn_8033D4CC(UnkObj8033D4CC* self);
extern "C" int __float_epsilon[];
extern "C" const f32 lbl_805421C4;
extern "C" s32 lbl_804ABC80[];

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
    s32 state = this_->state;

    switch (state) {
    case 0:
    case 1:
    case 5:
        if (state == 0) {
            name = (const char*)(base + 0x30);
            id = lbl_804ABCA0[0][this_->unk250] + 0x475;
        } else if (state == 1) {
            name = (const char*)(base + 0x44);
            id = 0x1c1;
        } else {
            id = 0x37c;
            name = (const char*)(base + 0x44);
        }
        fn_801F06F0(this_, name, id, NULL, 3, 1.0f, 1.0f);
        fn_803075AC(this_->unk198, this_->unk4, &this_->mPos, id, 0, 2, -1, 0, 0, 0);
        return;
    case 2:
    case 6:
        if (state == 2) {
            f32 b0 = 0.0f;
            f32 ac = -24.0f;
            f32 x;
            f32 a8 = 32.0f;
            f32 a4 = -16.0f;
            id = lbl_804ABCA0[this_->unk254][this_->unk250] + 0x3b4;
            for (s32 j = 0; j < 2; j++) {
                x = a8 * (f32)j + a4;
                for (s32 i = 0; i < 2; i++) {
                    f32 y = a8 * (f32)i + ac;
                    JGeometry::TVec3f saved;
                    saved = this_->mPos;
                    this_->mPos.add(JGeometry::TVec3f(x, y, b0));
                    fn_801F06F0(this_, (const char*)(base + 0x44), id, NULL, 3, 1.0f, 1.0f);
                    this_->mPos = saved;
                }
            }
        } else {
            JGeometry::TVec3f saved = this_->mPos;
            this_->mPos.add(JGeometry::TVec3f(0.0f, -16.0f, 0.0f));
            fn_801F06F0(this_, (const char*)(base + 0x44), 0x37d, NULL, 3, 1.0f, 1.0f);
            this_->mPos = saved;
        }
        {
            s32 tile = this_->state == 2 ? lbl_804ABCA0[0][this_->unk250] + 0x3ca : 0x37d;
            JGeometry::TVec3f saved = this_->mPos;
            this_->mPos.add(JGeometry::TVec3f(0.0f, -16.0f, 0.0f));
            fn_803075AC(this_->unk198, this_->unk4, &this_->mPos,
                        tile, 0, 2, -1, 0, 0, 0);
            this_->mPos = saved;
        }
        return;
    case 3: {
        DrawRec rec;
        Mtx m;
        PSMTXIdentity(m);
        m[0][0] = lbl_805421B4;
        m[0][1] = 0.0f;
        m[0][2] = 0.0f;
        m[1][0] = 0.0f;
        m[1][1] = lbl_805421B4;
        m[1][2] = 0.0f;
        m[2][0] = 0.0f;
        m[2][1] = 0.0f;
        m[2][2] = lbl_805421B4;
        rec.w18 = m;
        fn_801F06F0(this_, (const char*)(base + 0x44), 0x1c1, &rec, 3, 1.0f, 1.0f);
        fn_803075AC(this_->unk198, this_->unk4, &this_->mPos, 0x1c1, 1, 2, -1, 0, 0, 0);
        return;
    }
    case 4: {
        void* res = fn_804032E8(0x54494d47, (const char*)(base + 0x58));
        fn_801EFD34(this_, res, NULL, 7, 0.0f, 0.0f, 0.0f);
        return;
    }
    default:
        return;
    }
}

extern "C" bool fn_8033D264(UnkObj8033D264* self, u8 dir) {
    s32 h;
    bool result = false;
    JGeometry::TVec3f saved = self->mPos;
    const JGeometry::TVec3f& off = lbl_80471E28[dir];
    self->mOffset.x = off.x;
    self->mOffset.y = off.y;
    self->mOffset.z = off.z;
    self->mPos.add(self->mOffset);
    JGeometry::TVec3f out(lbl_805421B0, lbl_805421B0, lbl_805421B0);
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
                    h = self->unk198;
                    if (fn_80238CB4(i) != h) result = false;
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
    JGeometry::TBox2<f32> rect;
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
            if (self->m271 == 1) {
                self->m271 = 0;
            } else {
                self->mPrev.x = self->mPos.x;
                self->mPrev.y = self->mPos.y;
                self->mPrev.z = self->mPos.z;
            }
            fn_801F0E34(self, 0x30004, 0);
            self->m272 = 1;
            }
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
                    } else if (self->mPos.y > self->mAnchor.y) {
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

        rect.set(*(JGeometry::TBox2<f32>*)self->mRect);
        rect.addPos(*(JGeometry::TVec2<f32>*)&self->mPos);
        if (self->m25c != 0) {
            if (self->m25c != 2) {
                return;
            }
        }
        fn_8022FEB8((f32*)&rect, self->room, self->mHandle, 1, 0);
        self->m258 = fn_8022FD8C(self->mHandle);
        if (self->m258 < 0) {
            return;
        }
        f32* p = fn_8023E724(self->m258);
        f32 height = p[2];
        f32 zero = lbl_805421B0;
        if (height != zero) {
            return;
        }
        if (!fn_802300EC(self->m258)) {
            return;
        }
        s32 handle = self->mHandle;
        s32 room = self->room;
        tmp = self->mPos;
        if (!fn_8038C678(self->m258, self->m268, handle, room, &tmp, 0)) {
            return;
        }
        self->m234 = 1;
        self->m254 = fn_80230CFC(self->m258);
        self->m254 ^= 1;
    }
}

extern f32 lbl_805421C0;
extern f32 lbl_805421DC;
extern f32 lbl_805421E0;
extern f32 lbl_805421E4;
extern f32 lbl_805421E8;
void* fn_8020D58C(s32);
void fn_8020D7D0(void*, s32);
void fn_80239914(f32*, s32, s32);
void fn_801EE434(s32);
void fn_801F0D20(void*, s32, s32);
void fn_8013CB44(s32, s32, s32, s32);
s32 fn_80388CAC(s32, s32);
extern "C" u8* fn_8020D58C(void);
extern "C" void fn_801F0D20(void* this_, s32 n);
extern "C" void fn_8033DA78(UnkObj8033D4CC* this_) {
    f32 f30;
    f32 d;
    f32 t;
    f32 box[4];
    f32 box2[4];
    f32 box3[4];
    box[0] = this_->mRect[0];
    box[1] = this_->mRect[1];
    box[2] = this_->mRect[2];
    box[3] = this_->mRect[3];
    box[0] = box[0] + this_->mPos.x;
    box[2] = box[2] + this_->mPos.x;
    box[1] = box[1] + this_->mPos.y;
    box[3] = box[3] + this_->mPos.y;
    fn_80239914(box, this_->room, this_->mHandle);
    if (this_->m25c != 0 && this_->m25c != 2) {
        s32 h = this_->mHandle;
        u8* p = fn_8020D58C();
        fn_8020D7D0(p + p[0] * 0x784 + 4, h);
    }
    switch (this_->m234) {
    case 0:
        d = PSVECDistance(&this_->mPos, &this_->mAnchor);
        if (d < lbl_805421DC) {
            f30 = lbl_805421E0;
        } else {
            t = (f32)(this_->m260 * 16) - lbl_805421C0;
            f30 = (d >= t) ? lbl_805421E4 : lbl_805421C0;
        }
        d = PSVECDistance(&this_->mPos, &this_->mPrev);
        if (d < f30) {
            f32 lim = lbl_805421E8;
            if (!(this_->mPos.x <= this_->mAnchor.x + lim) && !(this_->mPos.x >= this_->mAnchor.x - lim)) {
                this_->mPos.x = this_->mAnchor.x;
            } else if (this_->mPos.x >= this_->mPrev.x) {
                this_->mPos.x = this_->mPrev.x + (f30 + lbl_805421C8);
            } else {
                this_->mPos.x = this_->mPrev.x - (f30 + lbl_805421C8);
            }
            if (this_->mPos.y <= this_->mAnchor.y + lim || this_->mPos.y >= this_->mAnchor.y - lim) {
                if (this_->mPos.y >= this_->mPrev.y) {
                    this_->mPos.y = this_->mPrev.y + (f30 + lbl_805421C8);
                } else {
                    this_->mPos.y = this_->mPrev.y - (f30 + lbl_805421C8);
                }
            } else {
                this_->mPos.y = this_->mAnchor.y;
            }
            this_->mPrev = this_->mPos;
            this_->mVel.x = 0.0f;
            this_->mVel.y = 0.0f;
            this_->mVel.z = 0.0f;
            this_->m272 = 0;
            *(JGeometry::TVec3f*)this_->pad18 = this_->mPos;
            if (this_->m230 != 0) {
                fn_801EE434(this_->m230);
            }
            if (((this_->mSpawnParam >> 16) & 1) == 0) {
                d = PSVECDistance(&this_->mPos, &this_->mAnchor);
                t = (f32)(this_->m260 * 16) - lbl_805421C8;
                if (!(d >= t)) {
                    this_->m244 = -1;
                    ((void (*)(void*, s32, s32))(*(void**)(*(u32*)this_ + 0x30)))(this_, 0xff, 1);
                    if (this_->m25c != 4) {
                        fn_801F0D20(this_, 3);
                    }
                } else {
                    this_->m244 = 8;
                    this_->m248 = 0x1e;
                }
            } else {
                this_->m244 = 8;
                this_->m248 = 0x1e;
            }
        } else if (this_->m265 != 0) {
            box2[0] = this_->mRect[0] + this_->mPos.x;
            box2[1] = this_->mRect[1] + this_->mPos.y;
            box2[2] = this_->mRect[2] + this_->mPos.x;
            box2[3] = this_->mRect[3] + this_->mPos.y;
            if (this_->m25c == 0) {
                this_->mPos.add(this_->mVel);
                if (this_->m244 > 0) {
                    this_->m244--;
                } else if (this_->m244 == 0) {
                    f32 vz = this_->mVel.z;
                    f32 len2 = this_->mVel.x * this_->mVel.x + this_->mVel.y * this_->mVel.y + vz * vz;
                    if (len2 <= lbl_805421A8 * *(f32*)__float_epsilon) {
                        fn_8033D4CC(this_);
                    } else {
                        JGeometry::TVec3f saved = this_->mVel;
                        u8 flag = 1;
                        if (this_->m260 == 2 && lbl_805421C0 == f30 && PSVECDistance(&this_->mPos, &this_->mPrev) < lbl_805421C4 && this_->m26c != 0 && fn_8033D264(this_, (u8)(this_->m26c - 1)) == 0) {
                            flag = 0;
                        }
                        this_->mVel.x = saved.x;
                        this_->mVel.y = saved.y;
                        this_->mVel.z = vz;
                        if (flag == 0) {
                            this_->m244 = 8;
                            this_->m271 = 1;
                        }
                    }
                } else {
                    box3[0] = this_->mRect[0] + this_->mPos.x;
                    box3[1] = this_->mRect[1] + this_->mPos.y;
                    box3[2] = this_->mRect[2] + this_->mPos.x;
                    box3[3] = this_->mRect[3] + this_->mPos.y;
                    if (this_->m25c == 0) {
                        if (this_->m230 != 0) {
                            fn_8013CB44(this_->m230, 0, 0, 1);
                        }
                    } else if (this_->m25c == 2) {
                        JGeometry::TVec3f tmp;
                        fn_8022FEB8(box3, this_->room, this_->mHandle, 1, 0);
                        this_->m258 = fn_8022FD8C(this_->mHandle);
                        if (this_->m258 >= 0) {
                            f32* fp = fn_8023E724(this_->m258);
                            if (lbl_805421B0 == fp[2] && fn_802300EC(this_->m258)) {
                                tmp = this_->mPos;
                                if (fn_8038C678(this_->m258, this_->m268, this_->mHandle, this_->room, &tmp, 0)) {
                                    this_->m234 = 1;
                                    this_->m254 = fn_80230CFC(this_->m258);
                                    this_->m254 = this_->m254 ^ 1;
                                }
                            }
                        }
                    }
                }
            } else if (this_->m25c == 2) {
                JGeometry::TVec3f tmp;
                fn_8022FEB8(box2, this_->room, this_->mHandle, 1, 0);
                this_->m258 = fn_8022FD8C(this_->mHandle);
                if (this_->m258 >= 0) {
                    f32* fp = fn_8023E724(this_->m258);
                    if (lbl_805421B0 == fp[2] && fn_802300EC(this_->m258)) {
                        tmp = this_->mPos;
                        if (fn_8038C678(this_->m258, this_->m268, this_->mHandle, this_->room, &tmp, 0)) {
                            this_->m234 = 1;
                            this_->m254 = fn_80230CFC(this_->m258);
                            this_->m254 = this_->m254 ^ 1;
                        }
                    }
                }
            }
        }
        break;
    case 1:
        fn_8022FEB8(box, this_->room, this_->mHandle, 1, 0);
        if (fn_80388CAC(this_->m258, this_->mHandle)) {
            this_->m234 = 0;
            this_->m254 = 2;
            if (this_->m272 == 0) {
                if (this_->m25c == 0) {
                    this_->m250 = (this_->m250 + 1) & 3;
                    this_->m24c = ((s32*)&lbl_804ABC80)[this_->m250];
                } else if (this_->m25c == 2) {
                    this_->m24c--;
                    if (this_->m24c <= 0) {
                        this_->m250 = (this_->m250 + 1) & 3;
                        this_->m24c = ((s32*)&lbl_804ABC80)[this_->m250];
                    }
                }
            }
        }
        break;
    }
}

extern "C" const f32 lbl_805421EC;
extern "C" const f32 lbl_805421F0;
extern "C" const f32 lbl_805421F4;
extern "C" const f32 lbl_805421F8;
extern "C" const f32 lbl_805421FC;
extern "C" const f32 lbl_80542200;
extern "C" const f32 lbl_80542204;
extern "C" const f32 lbl_80542208;
extern "C" u8 fn_8028D4DC(void* a, s32 b, s32 c);
extern "C" void fn_8033E188(UnkObj8033D4CC* self) {
    self->m25c = (self->mSpawnParam >> 12) & 0xf;
    switch (self->m25c) {
    case 0:
    case 1:
    case 5:
        self->mPos.add(JGeometry::TVec3f(0.0f, 8.0f, 0.0f));
        self->mRect[0] = -15.0f;
        self->mRect[1] = -23.0f;
        self->mRect[2] = 15.0f;
        self->mRect[3] = 7.0f;
        self->mRect2[0] = -15.0f;
        self->mRect2[1] = -23.0f;
        self->mRect2[2] = 15.0f;
        self->mRect2[3] = 7.0f;
        self->m1a4 = 2;
        self->m260 = 2;
        break;
    case 2:
    case 3:
    case 6:
        self->mPos.add(JGeometry::TVec3f(0.0f, 16.0f, 0.0f));
        self->mRect[0] = -31.0f;
        self->mRect[1] = -47.0f;
        self->mRect[2] = 31.0f;
        self->mRect[3] = 15.0f;
        self->mRect2[0] = -31.0f;
        self->mRect2[1] = -47.0f;
        self->mRect2[2] = 31.0f;
        self->mRect2[3] = 15.0f;
        self->m1a4 = 4;
        self->m260 = 4;
        break;
    case 4:
        self->mRect[0] = -31.0f;
        self->mRect[1] = -31.0f;
        self->mRect[2] = 31.0f;
        self->mRect[3] = 31.0f;
        self->mRect2[0] = -31.0f;
        self->mRect2[1] = -31.0f;
        self->mRect2[2] = 31.0f;
        self->mRect2[3] = 31.0f;
        self->m1a4 = 4;
        self->m260 = 4;
        break;
    }

    self->mAnchor = self->mPos;
    self->mVel.set(0.0f, 0.0f, 0.0f);
    self->m244 = 0;
    self->m248 = 0;
    self->m0b8 = 2;
    self->m234 = 0;
    self->m250 = 0;
    self->m24c = lbl_804ABC80[0];
    self->m254 = 2;
    self->m258 = -1;
    self->m272 = 0;
    self->m268 = (self->mSpawnParam & 0xfff) + 0x12b;
    self->m265 = 0;
    self->m264 = (self->mSpawnParam >> 17) & 1;
    if (self->m264 == 0 && fn_8028D4DC(&self->mPos, self->m260 - 1, self->m16c)) {
        self->m265 = 1;
        ((Actor*)self)->v10(0xff, 1);
    }

    self->mPrev = self->mPos;
    self->m270 = 1;
    if (self->m25c == 0 || self->m25c == 2) {
        self->m270 = 0;
    }
    self->m26c = 0;
    self->m271 = 0;
    self->m230 = 0;
}


