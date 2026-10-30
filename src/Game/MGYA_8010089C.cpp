// MGYA_8010089C: .text 0x8010089C-0x80102278 (actor MGYA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JUtility/JUTVideo.h"

// ---- from Game/fn_8010089C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C8EC[];

extern "C" void* fn_8010089C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C8EC;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JGeometry/Vec.h"
#include "Game/ItemBase.h"
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, DrawRec* rec, s32 p5, f32 a, f32 b);
extern const char lbl_80463BA0[];
extern u8* lbl_8053AF18;
extern const f32 lbl_8053C154;
extern const f32 lbl_8053C140;
extern "C" void fn_801F0E34(void* this_, s32 id, s32 c);
extern "C" void fn_8030C210(void*, void*);
extern "C" void detach__5ActorFv(void* this_);
extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" s32 fn_8013CC50(s32 id, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);
extern "C" u8 fn_8022F514(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" void fn_80238548(s32, s32, void*, s32);
extern "C" void* fn_80138A30(void*);
struct MGYA_Random {
    u32 seed;
    f32 get() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053C140;
    }
};
struct MGYA_Game { u8 pad[0xb4]; MGYA_Random rnd; };
extern MGYA_Game* lbl_8053AAF8;
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern const f32 lbl_8053C148;
extern const f32 lbl_8053C14C;
extern const f32 lbl_8053C150;
extern u8* lbl_8053AB10;
extern const f32 lbl_8053C144;
extern const f32 lbl_8053C190;
extern const f32 lbl_8053C194;
extern const f32 lbl_8053C198;
extern const f32 lbl_8053C19C;
extern const f32 lbl_8053C1A0;

class MGYA {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30(s32, s32);
    virtual u8 v34();
    s32 m04;
    u8 pad08[4];
    JGeometry::TVec3f mPos; // 0x0c
    u8 pad18[0x60 - 0x18];
    f32 m60, m64, m68, m6C;
    f32 m70, m74, m78, m7C;
    u8 pad80[0x90 - 0x80];
    u32 m90;
    u8 pad94[0xb0 - 0x94];
    s32 mB0;
    u8 padB4[0x10c - 0xb4];
    s32 m10C;
    u8 pad110[0x198 - 0x110];
    s32 m198;
    u8 pad19C[0x230 - 0x19c];
    s32 m230;
    s32 m234;
    s32 m238;
    s32 m23C;
    u32 m240;
    u8 m244;
    u8 m245;
    u8 m246;
    u8 m247;
    u8 m248;
    u8 pad249[0x24c - 0x249];
    JGeometry::TVec3f m24C;
    f32 m258;
    u8 m25C[4];
    u16 m260[4];
    u16 m268[4];
    s32 m270[4];
    s32 m280[4];
    MGYA* m290;
};

extern "C" void fn_80100D28(MGYA* this_);

extern "C" void fn_801008FC(MGYA* this_) {
    s32 pl = this_->m10C;
    if (pl < 0) {
        return;
    }
    fn_801F0E34(this_, 0x40099, 0);
    if (fn_8022F514(pl)) {
        pl = fn_8022F3DC(pl);
    }
    if (this_->m244 == 1) {
        JGeometry::TVec3f pos = this_->mPos;
        pos.x += lbl_8053C144;
        fn_8013CC50(this_->m04, &pos, 0x59, 1, 1, 0, 0, 1, lbl_8053C140);
        fn_8013CC50(this_->m04, &pos, 0x5a, 1, 1, 0, 0, 1, lbl_8053C140);
        fn_8013CC50(this_->m04, &pos, 0x5b, 1, 1, 0, 0, 1, lbl_8053C140);
        fn_801F0E34(this_, 0x30001, 0);
        f32 xy[2];
        xy[0] = pos.x;
        xy[1] = pos.y;
        fn_80238548(pl, 0, xy, 0xb);
    } else {
        s32 a = 1;
        s32 b = 0;
        if (pl == this_->m244 - 2) {
            a = 3;
        } else if (this_->m244 != 0) {
            b = 1;
        }
        MGYA* m = this_->m290;
        u16* p260 = m->m260;
        u16* p268 = m->m268;
        p260[pl] += a;
        p268[pl] += b;
    }
}

extern "C" void fn_80100A90(MGYA* this_) {
    this_->m290 = (MGYA*)fn_801F666C(fn_801F856C(), this_->m90 & 0xffff);
    this_->m60 = lbl_8053C148;
    this_->m64 = lbl_8053C148;
    this_->m68 = lbl_8053C14C;
    this_->m6C = lbl_8053C14C;
    this_->m70 = lbl_8053C148;
    this_->m74 = lbl_8053C148;
    this_->m78 = lbl_8053C14C;
    this_->m7C = lbl_8053C14C;
    this_->m234 = 0;
    this_->m246 = 0;
    this_->m245 = 0;
    this_->m240 = 0;
    s32 r = lbl_8053C150 * lbl_8053AAF8->rnd.get();
    int n = (u8)(u32)fn_80138A30(lbl_8053AAF8);
    if (this_->m290->m23C > 0x2d0) {
        if (r < 10) {
            this_->m244 = 1;
        } else if (n >= 1 && r < 15) {
            this_->m244 = 2;
        } else if (n >= 2 && r < 20) {
            this_->m244 = 3;
        } else if (n >= 3 && r < 25) {
            this_->m244 = 4;
        } else if (n == 4 && r < 30) {
            this_->m244 = 5;
        } else {
            this_->m244 = 0;
        }
    } else {
        s32 t3;
        s32 t1;
        s32 t2;
        s32 t4;
        s32 base;
        base = 0;
        t4 = 0;
        t2 = 0;
        t1 = 0;
        switch (n) {
        case 1:
            t1 = 0x5a;
            base = 10;
            break;
        case 2:
            t1 = 0x2d;
            t2 = 0x2d;
            base = 10;
            break;
        case 3:
            t1 = 0x1e;
            t2 = 0x1e;
            t3 = 0x1e;
            base = 10;
            break;
        case 4:
            t1 = 0x16;
            t2 = 0x16;
            t3 = 0x16;
            t4 = 0x16;
            base = 12;
            break;
        }
        if (r < base) {
            this_->m244 = 1;
        } else if (r < (t1 = base + t1)) {
            this_->m244 = 2;
        } else if (r < (t1 = t2 + t1)) {
            this_->m244 = 3;
        } else if (r < (t1 = t3 + t1)) {
            this_->m244 = 4;
        } else if (r < t4 + t1) {
            this_->m244 = 5;
        }
    }
    fn_8013CC50(this_->m04, &this_->mPos, 0x1da, 0, 1, 0, 0, 1, lbl_8053C140);
}

extern "C" void fn_80239914(void*, s32, s32);
extern "C" void fn_8022FEB8(void*, s32, s32, s32, s32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" u8 fn_802300EC(s32);
extern "C" u8 fn_8038AD24(s32, s32, s32, s32, const JGeometry::TVec3<f32>&, s32);
extern "C" void fn_802308E0(s32);
extern "C" void fn_801EE558(void*, void*, f32*, s32);
extern "C" u8 fn_803865B8(s32);
extern "C" s32 fn_8037EFB4(s32);
extern "C" void fn_8038470C(s32, s32);
extern "C" s32 fn_802373EC(s32);
extern "C" s32 fn_8023725C(s32);
extern "C" void fn_802372F8(s32, s32, s32);
extern "C" u8 fn_80388CAC(s32, s32);
extern "C" void fn_80230534(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" void fn_8022FE80(s32, s32, s32, s32, s32);
extern "C" void fn_8022B22C();
extern "C" void fn_8043CB24(void*, s32, s32, s32, s32, s32, f32, f32, f32);
extern "C" void fn_801F0D20(void*, s32);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D8050(void*, s32, s32, s32);
extern "C" void fn_80458FF0(void*, s32, s32, s32);
extern "C" void fn_80458508(void*, s32);
extern "C" void fn_8043D67C(void*, s32, s32, s32);
extern "C" s32 Actor_CreateByID(void*, u32, s32, void*, s32, s32, s32);
extern "C" s32 fn_801F68E0(void*);
extern "C" s32 fn_8022EA0C(s32);
extern "C" void fn_8022B214();
extern "C" void fn_80138B7C(void*);
extern "C" void fn_8043D874(void*, s32, s32, s32);
extern "C" void fn_803894BC(s32, s32);
extern "C" void fn_8038938C(s32, s32);
extern "C" void fn_80389254(s32, s32);
extern "C" u8 fn_80384C58(s32, s32);
extern "C" void fn_801F6884(void*);
extern "C" void fn_802362C4(s32, s32);
extern "C" void fn_802D7844(void*, s32, s32);
extern const f32 lbl_8053C160;
extern const f32 lbl_8053C164;
extern const f32 lbl_8053C168;
extern const f32 lbl_8053C16C;
extern const f32 lbl_8053C170;
extern const f32 lbl_8053C174;
extern const f32 lbl_8053C178;
extern const f32 lbl_8053C17C;
extern const f32 lbl_8053C180;
extern const f32 lbl_8053C184;
extern const f32 lbl_8053C188;
extern const f32 lbl_8053C18C;
extern const u8 lbl_80539EB0[2];
extern const s32 lbl_8049C8D8[];
extern void* lbl_8053AED0;
extern u8* lbl_8053AF80;
extern "C" u8* sManager__8JUTVideo;
#pragma opt_lifetimes on
extern "C" void fn_80100D28(MGYA* this_) {
    JGeometry::TVec3f pos(this_->mPos);
    pos.y -= lbl_8053C160;
    JGeometry::TVec3f cam(this_->mPos);
    f32 box[4];
    JGeometry::TVec3f temp0, temp1, temp2;
    JGeometry::TVec3f dir;
    f32 spawn[3];
    JGeometry::TVec3f dir2;
    f32 dist;
    f32 dist2;
    box[0] = this_->m60;
    box[1] = this_->m64;
    box[2] = this_->m68;
    box[3] = this_->m6C;
    box[0] += this_->mPos.x;
    box[1] += this_->mPos.y;
    box[2] += this_->mPos.x;
    box[3] += this_->mPos.y;
    fn_80239914(box, this_->m04, this_->m198);
    ++this_->m245;
    if (this_->m245 == lbl_80539EB0[this_->m246]) {
        ++this_->m246;
        if (this_->m246 == 2) this_->m246 = 0;
        this_->m245 = 0;
    }
    switch (this_->m230) {
    case 0:
        fn_8022FEB8(box, this_->m04, this_->m198, 1, 0);
        this_->m238 = fn_8022FD8C(this_->m198);
        if (this_->m238 >= 0 && fn_802300EC(this_->m238)) {
            s32 id0 = this_->m244 == 1 ? 0x328 : 0x31f;
            s32 handle0 = this_->m198;
            s32 room0 = this_->m04;
            if (fn_8038AD24(this_->m238, id0, handle0, room0, (temp0 = pos, temp0), 0)) {
                for (int i = 0; i < 4; i++) fn_802308E0(i);
                for (int i = 0; i < 4; i++) {
                    this_->m25C[i] = 0;
                    this_->m260[i] = 0;
                }
                this_->m230 = 1;
                fn_801EE558(this_, &dir, &dist, this_->m238 + 1);
                if (dist < lbl_8053C150) {
                    f32 radians = JMath::atanTable_.atan2_(-dir.x, -dir.y);
                    u32 angle = (u16)(radians * lbl_8053C164);
                    if (angle < 0x2000 || angle >= 0xE000) this_->m247 = 3;
                    else if (angle >= 0x2000 && angle < 0x6000) this_->m247 = 1;
                    else if (angle >= 0x6000 && angle <= 0xA000) this_->m247 = 2;
                    else this_->m247 = 0;
                }
            }
        }
        break;
    case 1:
        { u8* c = *(u8**)(lbl_8053AB10 + 0x24);
        if (c[0x7F5] == 0) {
            c[0x7F4] = 1;
            *(s32*)(c + 0x7F8) = 4;
            *(f32*)(c + 0x7FC) = cam.x;
            *(f32*)(c + 0x800) = cam.y;
            *(f32*)(c + 0x804) = cam.z;
            c[0x7F6] = 0;
        } }
        fn_8022FEB8(box, this_->m04, this_->m198, 1, 0);
        if (fn_803865B8(this_->m238)) {
            switch (fn_8037EFB4(this_->m238)) {
            case 0:
                fn_8038470C(this_->m238, this_->m244 == 1 ? 0x329 : 0x320);
                for (int i = 0; i < 4; i++) {
                    this_->m270[i] = fn_802373EC(i);
                    this_->m280[i] = fn_8023725C(i);
                    fn_802372F8(i, 5, 1);
                }
                this_->m230 = 3;
                this_->m234 = 0;
                break;
            case 1:
                fn_8038470C(this_->m238, 0x321);
                this_->m230 = 2;
                this_->m234 = 0;
                break;
            }
        }
        break;
    case 2:
        { u8* c = *(u8**)(lbl_8053AB10 + 0x24);
        if (c[0x7F5] == 0) {
            c[0x7F4] = 1;
            *(s32*)(c + 0x7F8) = 4;
            *(f32*)(c + 0x7FC) = cam.x;
            *(f32*)(c + 0x800) = cam.y;
            *(f32*)(c + 0x804) = cam.z;
            c[0x7F6] = 0;
        } }
        fn_8022FEB8(box, this_->m04, this_->m198, 1, 0);
        if (fn_80388CAC(this_->m238, this_->m198)) {
            this_->m230 = 0;
            this_->m234 = 0;
            fn_80230534(0);
        }
        break;
    case 3:
        { u8* c = *(u8**)(lbl_8053AB10 + 0x24);
        if (c[0x7F5] == 0) {
            c[0x7F4] = 1;
            *(s32*)(c + 0x7F8) = 4;
            *(f32*)(c + 0x7FC) = cam.x;
            *(f32*)(c + 0x800) = cam.y;
            *(f32*)(c + 0x804) = cam.z;
            c[0x7F6] = 0;
        } }
        if (this_->m247 == 3) {
            this_->m258 += lbl_8053C140;
        } else {
            this_->m258 -= lbl_8053C140;
        }
        if (this_->m258 >= lbl_8053C168) {
            this_->m258 = lbl_8053C168;
        } else if (this_->m258 <= lbl_8053C16C) {
            this_->m258 = lbl_8053C16C;
        }
        fn_8022FE80(this_->m238, fn_8023DE58(0), this_->m198, 0, 0);
        if (fn_80388CAC(this_->m238, this_->m198)) {
            this_->m230 = 4;
            this_->m234 = 0;
            this_->m23C = 3600;
            fn_80230534(0);
            fn_8022B22C();
        }
        break;
    case 4:
        fn_8043CB24(lbl_8053AED0, 3 - this_->m234 / 60, 0xff, 0, 1, 1,
                    lbl_8053C170 * (f32)(s32)JUTVideo::getManager()->getFbWidth(),
                    lbl_8053C170 * (f32)(s32)JUTVideo::getManager()->getEfbHeight(), lbl_8053C174);
        if (this_->m234 % 60 == 0) {
            fn_801F0D20(this_, 0x3f);
        }
        this_->m234++;
        if (this_->m234 == 180) {
            this_->m230 = 5;
            this_->m234 = 0;
            fn_801F0D20(this_, 0x3a);
            fn_802D8050(fn_802D6A9C(), this_->m248, 1, 0xff);
            this_->m240 = *(u32*)(lbl_8053AF80 + 0x58);
            fn_80458FF0(lbl_8053AF80, 0x1000007, 1, 0);
        }
        break;
    case 5:
        this_->m23C--;
        if (this_->m23C / 60 <= 10 && this_->m23C % 60 == 59) {
            fn_801F0D20(this_, 0x3f);
            fn_80458508(lbl_8053AF80, 1);
        }
        if (this_->m23C / 60 == 10) {
            fn_8043D67C(lbl_8053AED0, 0x326, 0, 0);
        }
        this_->m234++;
        if (this_->m234 >= lbl_8049C8D8[this_->m244] && this_->m23C >= 120) {
            s32 n = lbl_8053C178 * lbl_8053AAF8->rnd.get();
            spawn[0] = lbl_8053C17C + this_->m24C.x + lbl_8053C180 * (n % 3) + (lbl_8053C184 * lbl_8053AAF8->rnd.get() - lbl_8053C188);
            spawn[1] = this_->m24C.y - lbl_8053C18C + lbl_8053C180 * (n / 3) + (lbl_8053C184 * lbl_8053AAF8->rnd.get() - lbl_8053C188);
            spawn[2] = lbl_8053C190;
            Actor_CreateByID(fn_801F856C(), 'MGYA', this_->m04, spawn, this_->m198 + 0x10000, -1, -1);
            this_->m234 = 0;
        }
        if (this_->m23C == 0) {
            fn_801F68E0(fn_801F856C());
            this_->m230 = 6;
            this_->m234 = 0;
            fn_801F0D20(this_, 0x3b);
            fn_80458508(lbl_8053AF80, 0);
            fn_802D8050(fn_802D6A9C(), this_->m248, 0, 0xff);
            this_->m247 = 2;
        }
        break;
    case 6:
        {
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &this_->mPos);
        this_->m234++;
        s32 st = fn_801F68E0(fn_801F856C());
        if (this_->m234 > 50 && st == 1) {
            this_->m238 = fn_8022EA0C(this_->m238);
            fn_8022FE80(this_->m238, fn_8023DE58(this_->m238), this_->m198, 0, 0);
            if (fn_8022FD8C(this_->m198) >= 0) {
                s32 handle1 = this_->m198;
                s32 room1 = this_->m04;
                fn_8038AD24(this_->m238, 0x322, handle1, room1, (temp1 = pos, temp1), 2);
                this_->m230 = 7;
                this_->m234 = 0;
                fn_8022B214();
                fn_80138B7C(lbl_8053AAF8);
                this_->m234 = 0;
            }
        }
        }
        break;
    case 7:
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &this_->mPos);
        fn_8022FE80(this_->m238, fn_8023DE58(this_->m238), this_->m198, 0, 0);
        if (fn_803865B8(this_->m238)) {
            if (this_->m234 > 0 && this_->m260[this_->m234 - 1] != 0) {
                fn_8043D874(lbl_8053AED0, this_->m234 - 1, this_->m260[this_->m234 - 1] * 20, 0);
            }
            if (this_->m234 < this_->m244) {
                fn_803894BC(this_->m238, this_->m234 + 1);
                fn_8038938C(this_->m238, this_->m260[this_->m234]);
                fn_80389254(this_->m238, this_->m260[this_->m234] * 20);
                u16 v = this_->m260[this_->m234];
                s32 id;
                if (v >= 40) {
                    id = 0x323;
                } else if (v < 40 && v >= 20) {
                    id = 0x324;
                } else if (v < 20 && v >= 1) {
                    id = 0x325;
                } else {
                    id = 0x31e;
                }
                fn_8038470C(this_->m238, id);
            } else {
                fn_8038470C(this_->m238, 0x327);
                this_->m230 = 8;
                this_->m234 = 0;
            }
            this_->m234++;
        }
        break;
    case 8:
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &this_->mPos);
        fn_8022FE80(this_->m238, fn_8023DE58(this_->m238), this_->m198, 0, 0);
        if (fn_803865B8(this_->m238) && fn_80384C58(this_->m238, this_->m198)) {
            this_->m230 = 9;
            this_->m234 = 0;
            fn_801F6884(fn_801F856C());
            for (int i = 0; i < 4; i++) {
                if (!fn_8022F514(i)) {
                    fn_802372F8(i, this_->m270[i], this_->m280[i]);
                }
            }
            if (this_->m244 == 1) {
                if (this_->m25C[0] == 1) {
                    fn_802362C4(0, 500);
                }
            } else {
                s32 best = -1;
                for (int i = 0; i < this_->m244; i++) {
                    if (best < this_->m268[i]) best = this_->m268[i];
                }
                if (best != 0) {
                    for (int i = 0; i < this_->m244; i++) {
                        if (best == this_->m268[i]) {
                            fn_802D7844(fn_802D6A9C(), 1, i);
                        } else {
                            fn_802D7844(fn_802D6A9C(), 0, i);
                        }
                    }
                }
            }
            this_->v30(0xff, 1);
        }
        break;
    case 9:
        fn_8022FEB8(box, this_->m04, this_->m198, 1, 0);
        this_->m238 = fn_8022FD8C(this_->m198);
        if (this_->m238 >= 0) {
            s32 handle2 = this_->m198;
            s32 room2 = this_->m04;
            if (fn_8038AD24(this_->m238, 0x328, handle2, room2, (temp2 = pos, temp2), 0)) {
                this_->m230 = 10;
                this_->m234 = 0;
                fn_801EE558(this_, &dir2, &dist2, this_->m238 + 1);
                if (dist2 < lbl_8053C150) {
                    f32 radians = JMath::atanTable_.atan2_(-dir2.x, -dir2.y);
                    u32 angle = (u16)(radians * lbl_8053C164);
                    if (angle < 0x2000 || angle >= 0xE000) this_->m247 = 3;
                    else if (angle >= 0x2000 && angle < 0x6000) this_->m247 = 1;
                    else if (angle >= 0x6000 && angle <= 0xA000) this_->m247 = 2;
                    else this_->m247 = 0;
                }
            }
        }
        break;
    case 10:
        fn_8022FEB8(box, this_->m04, this_->m198, 1, 0);
        if (fn_80388CAC(this_->m238, this_->m198)) {
            this_->m230 = 9;
            this_->m234 = 0;
        }
        break;
    }
}
#pragma opt_lifetimes off
extern "C" void fn_80101B48(MGYA* this_) {
    s32 i;
    MGYA* p;
    if (this_->m90 & 0x10000) {
        DrawRec rec;
        if (this_->m244 == 1) {
            rec.ids[0xb] = 6;
        } else if (this_->m244 != 0 && this_->m244 <= 5) {
            rec.ids[0xb] = this_->m244;
        }
        if (this_->m240 != 0) {
            fn_801F06F0(this_, lbl_80463BA0, this_->m246 + 0x155, &rec, -1, lbl_8053C140, lbl_8053C140);
        }
    } else {
        this_->mPos.y = this_->m24C.y + this_->m258;
        s32 doubled = this_->m247 << 1;
        s32 sprite = this_->m246;
        sprite = doubled + sprite;
        sprite += 0x311;
        fn_801F06F0(this_, lbl_80463BA0, sprite, 0, 0, lbl_8053C140, lbl_8053C140);
        s32 st = this_->m230;
        if (st == 5 || (u32)(st - 6) <= 1 || st == 8) {
            s32 t = this_->m23C;
            s32 m = t / 60;
            lbl_8053AF18[0x30] = m;
            lbl_8053AF18[0x31] = (t - m * 60) / lbl_8053C154;
            lbl_8053AF18[0x32] |= 0x10;
            p=this_;
            for (i = 0; i < this_->m244; i++, p=(MGYA*)((u8*)p+2)) {
                lbl_8053AF18[0x32] |= (u8)(1 << i);
                lbl_8053AF18[0x2c + i] = p->m260[0];
            }
        }
    }
}
#pragma opt_propagation reset
extern "C" void fn_80101DF0(MGYA* this_) {
    if (this_->m90 & 0x10000) {
        this_->m245++;
        if (this_->m245 == 8) {
            this_->m246++;
            if (this_->m246 == 2) {
                this_->m246 = 0;
            }
            this_->m245 = 0;
        }
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &this_->mPos);
        this_->m234++;
        if (this_->m234 < 0x28) {
            if ((this_->m234 & 3) == 0) {
                fn_8013CC50(this_->m04, &this_->mPos, 0x1da, 0, 1, 0, 0, 1, lbl_8053C140);
            }
        } else {
            this_->m240 = 1;
            this_->mB0 = 0x1100;
            if (this_->m234 == 0xa0) {
                fn_8013CC50(this_->m04, &this_->mPos, 0x1da, 0, 1, 0, 0, 1, lbl_8053C140);
                detach__5ActorFv(this_);
            }
            fn_801F3D94(this_, 1);
        }
    } else {
        fn_80100D28(this_);
    }
}

extern "C" void fn_80101F20(MGYA* this_) {
    if (this_->m90 & 0x10000) {
        fn_80100A90(this_);
        return;
    }
    this_->m60 = lbl_8053C194;
    this_->m64 = lbl_8053C194;
    this_->m68 = lbl_8053C198;
    this_->m6C = lbl_8053C198;
    this_->m247 = 1;
    this_->m246 = 0;
    this_->m245 = 0;
    this_->m238 = -1;
    this_->mPos.x += lbl_8053C19C;
    this_->mPos.y += lbl_8053C1A0;
    this_->m24C.x = this_->mPos.x;
    this_->m24C.y = this_->mPos.y;
    this_->m24C.z = this_->mPos.z;
    this_->m258 = lbl_8053C190;
    for (int i = 0; i < 4; i++) {
        this_->m25C[i] = 0;
        this_->m260[i] = 0;
        this_->m268[i] = 0;
    }
    this_->m244 = (u8)(u32)fn_80138A30(lbl_8053AAF8);
    this_->m248 = (this_->m90 >> 22) & 0x1f;
    if (this_->v34()) {
        this_->m230 = 9;
        this_->m234 = 0;
    } else {
        this_->m230 = 0;
        this_->m234 = 0;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JMath/JMath.h"
