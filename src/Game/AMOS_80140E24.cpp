#include "types.h"
#include "Game/ItemBase.h"
#include "Game/SinitPoolChain.h"

extern void* lbl_8049F260[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_80140E24(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F260;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F02BC(void* a, u8* p2, void* p3, DrawRec* p4, s32 p5, s32 p6, u8 p7, f32 f6, f32 f7);
extern "C" f32 lbl_8053CEA0;
extern "C" f32 lbl_8053CEA4;
extern "C" u8 lbl_80465AC8[];
extern "C" u8 lbl_80465ADC[];
extern "C" void fn_80140E84(void* this_) {
    DrawRec r;
    f32 m[3][4];
    s32 p5 = 0;
    s32 p6 = 0;
    m[0][3] = lbl_8053CEA0;
    m[1][3] = lbl_8053CEA0;
    m[2][3] = lbl_8053CEA0;
    r.b20 = 0;
    if (*(s32*)((u8*)this_ + 0x31c) != 0) {
        p5 = 3;
        p6 = 1;
        m[0][0] = lbl_8053CEA4;
        m[0][1] = lbl_8053CEA0;
        m[0][2] = lbl_8053CEA0;
        m[1][0] = lbl_8053CEA0;
        m[1][1] = lbl_8053CEA4;
        m[1][2] = lbl_8053CEA0;
        m[2][0] = lbl_8053CEA0;
        m[2][1] = lbl_8053CEA0;
        m[2][2] = lbl_8053CEA4;
        r.w18 = m;
    }
    s16 sVar1 = *(s16*)((u8*)this_ + 0x94);
    if (sVar1 == 3 || (u16)(sVar1 - 4) < 2 || sVar1 == 7) {
        fn_801F02BC(this_, lbl_80465AC8, (u8*)*(void**)((u8*)this_ + 0x318) + 0x444, &r, 3, p6, 0, lbl_8053CEA4, lbl_8053CEA4);
    } else {
        fn_801F02BC(this_, lbl_80465ADC, (u8*)*(void**)((u8*)this_ + 0x318) + 0x152, &r, p5, p6, 0, lbl_8053CEA4, lbl_8053CEA4);
    }
}

#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Box.h"
#include "sdk/stl/math.h"
#include "std/math.h"
extern "C" int fn_801F3D94(void* this_, int = 1);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" u8 fn_801F305C(void* this_);
extern "C" s32 fn_801F285C(void* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" u8 fn_80237948(s32 a, void* b);
extern "C" void fn_8013CC50(s32 obj, void* pos, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 v);
extern "C" void fn_80239914(void* a, s32 b, s32 c);
extern "C" void fn_801EF510(void* this_);
extern "C" f32 lbl_8053CEA8;
extern "C" f32 lbl_8053CEB4;
extern "C" f32 lbl_8053CEB8;
extern "C" f32 lbl_8053CEBC;
extern "C" f32 lbl_8053CEC0;
extern "C" f32 lbl_8053CEAC;
extern "C" f32 lbl_8053CEB0;

extern "C" u8 fn_8023F264(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" void fn_801F2B7C(void*, s32, s32, s32);
extern "C" void fn_801EEC98(void*, s32, s32, s32*, s32, s32*, s32, s32);
extern "C" s32 fn_80230CFC(s32);
extern "C" void fn_801EE8F4(void*, void*, s32, s32);
extern "C" u8* fn_8020D58C();
extern "C" void fn_8020D7D0(void*, s32);
extern "C" u8 fn_802265DC(void*, s32, s32);
extern "C" u16 fn_80226850(void*, s32);
extern "C" void* fn_801F856C();
extern "C" s32 fn_801F7818(void*, u32, s32, void*, s32);
extern "C" s32 fn_80239558(void*, s32, s32);
extern "C" s32 fn_80239470(void*, s32, s32);
extern "C" u8 fn_800FE3EC(void*, s32, void*, s32);
extern "C" void fn_800FDEA0(void*, void*, void*, void*, void*, s32, f32);
extern "C" void* fn_801F8108(void*, u32, s32, f32);
extern "C" void* fn_801F666C(void*, void*);
extern "C" void fn_801BEDBC(void*);
extern f32 lbl_8053CEC4, lbl_8053CECC, lbl_8053CEE8;
extern JGeometry::TVec3f lbl_80465A98[4];
static inline void AMOSnormalize(JGeometry::TVec3f* v) { v->normalize(); }
extern "C" void fn_80141064(u8* this_) {
    s32 room;
    s32 i;
    JGeometry::TVec2f center;
    JGeometry::TBox2f box;
    JGeometry::TVec3f delta;
    JGeometry::TVec3f pos;
    box.i.x=(*(f32*)(this_+0x60)); box.i.y=(*(f32*)(this_+0x64)); box.f.x=(*(f32*)(this_+0x68)); box.f.y=(*(f32*)(this_+0x6c));
    box.addPos((*(f32*)(this_+0xc)), (*(f32*)(this_+0x10)));
    if (fn_801F3D94(this_, 1)) {
        fn_801F2618(this_, 0, 0);
        return;
    }
    if ((*(s32*)(this_+0x2f8)) == 2 || (*(s32*)(this_+0x2f8)) == 5) {
        if ((*(u16*)(this_+0x94)) != 3 && (*(u16*)(this_+0x94)) != 5) {
            if (fn_801F305C(this_)) {
                if ((*(s32*)(this_+0x2f8)) != 2) {
                    (*(s32*)(this_+0x318)) = 0;
                    (*(s32*)(this_+0x2f8)) = 2;
                }
                if ((*(s32*)(this_+0x108)) <= 0) fn_801F0E34(this_, 0x400a1, 0);
                fn_801F2618(this_, 0, 0);
                return;
            }
        } else {
            for (room = 0; room < 4; room++) {
                s32 n = fn_801F285C(this_, 0, 0, 0, room);
                if (n >= 0) {
                    f32 half = 0.5f;
                    center.set(half * (box.i.x - box.f.x) + box.f.x,
                               half * (box.i.y - box.f.y) + box.f.y);
                    if (fn_80237948(n, &center)) {
                        fn_8013CC50((*(s32*)(this_+0x4)), this_+0xc, lbl_8053CEA4, 0x117, 0, 1, 0, 0, 1);
                        fn_8013CC50((*(s32*)(this_+0x4)), this_+0xc, lbl_8053CEA4, 0x118, 0, 1, 0, 0, 1);
                        fn_801F0E34(this_, 0x400d1, 0);
                    }
                }
            }
        }
    }
    switch ((*(s32*)(this_+0x2f8))) {
    case 0:
        fn_80239914(&box, (*(s32*)(this_+0x4)), (*(s32*)(this_+0x198)));
        fn_801EF510(this_);
        if ((*(u16*)(this_+0x94)) == 2) {
            if ((u8)((Actor*)this_)->v11()) {
                fn_801F0E34(this_, 0x400a0, 0);
                if ((*(u16*)(this_+0x94)) != 3) (*(s32*)(this_+0xbc)) = 2;
                (*(s32*)(this_+0x2f8)) = 1;
                (*(s32*)(this_+0x2fc)) = 60;
            }
        } else {
            for (i=0; i<4; i++) {
                if (!fn_8023F264(i)) continue;
                room = (*(s32*)(this_+0x4));
                if (room == fn_8023DE58(i)) {
                    delta.sub(*fn_8023E724(i), (*(JGeometry::TVec3f*)(this_+0xc)));
                    f32 range = lbl_8053CEAC;
                    if ((*(u16*)(this_+0x94)) == 3) range = lbl_8053CEB0;
                    if (delta.squared() < range) {
                        fn_801F0E34(this_, 0x400a0, 0);
                        if ((*(u16*)(this_+0x94)) != 3) (*(s32*)(this_+0xbc)) = 2;
                        (*(s32*)(this_+0x2f8)) = 1;
                        (*(s32*)(this_+0x2fc)) = 60;
                        return;
                    }
                }
            }
        }
        break;
    case 1:
        --(*(s32*)(this_+0x2fc));
        box = (*(JGeometry::TBox2f*)(this_+0x60));
        box.addPos(*(JGeometry::TVec2f*)(this_+0xc));
        fn_80239914(&box, (*(s32*)(this_+0x4)), (*(s32*)(this_+0x198)));
        if (!((*(s32*)(this_+0x2fc)) & 2)) (*(s32*)(this_+0x318)) ^= 1;
        if ((*(s32*)(this_+0x2fc)) < 0) {
            (*(s32*)(this_+0xb8)) = 1;
            if ((*(u16*)(this_+0x94)) != 3) (*(s32*)(this_+0xb0)) = 0x12205;
            (*(s32*)(this_+0x318)) = 0;
            (*(s32*)(this_+0x2f8)) = 2;
        }
        break;
    case 2:
        if ((*(s32*)(this_+0x300)) > 0) --(*(s32*)(this_+0x300));
        (*(f32*)(this_+0x44)) += lbl_8053CEB4;
        (*(JGeometry::TVec3f*)(this_+0xc)).add((*(JGeometry::TVec3f*)(this_+0x3c)));
        if ((*(f32*)(this_+0x14)) <= 0.0f) {
            pos.x=(*(f32*)(this_+0xc)); pos.y=(*(f32*)(this_+0x10)); pos.z=(*(f32*)(this_+0x14));
            pos.y += lbl_8053CEB8;
            if ((*(s32*)(this_+0x304))) {
                if ((*(u16*)(this_+0x94)) == 3 || (*(u16*)(this_+0x94)) == 4)
                    fn_8013CC50((*(s32*)(this_+0x4)), &pos, lbl_8053CEBC, 0x3cf, 0, 0, 0, 0, 1);
                else
                    fn_8013CC50((*(s32*)(this_+0x4)), &pos, lbl_8053CEA4, 0x3cf, 0, 0, 0, 0, 1);
                fn_801F0E34(this_, 0x40007, 0);
            }
            (*(s32*)(this_+0x304)) = 1;
            (*(f32*)(this_+0x14)) = 0.0f;
            if ((*(u16*)(this_+0x94)) == 3 || (*(u16*)(this_+0x94)) == 4) {
                s32 a=-1, b=-1;
                fn_801EEC98(this_, (*(s32*)(this_+0x198)), 0, &a, 0, &b, 0, 0);
                bool blocked=false;
                if (b < 0) blocked=true;
                else if (a != fn_80230CFC(b)) blocked=true;
                if (blocked == true) {
                    (*(s32*)(this_+0x304)) = 0;
                    (*(JGeometry::TVec3f*)(this_+0x3c)).zero();
                    box = (*(JGeometry::TBox2f*)(this_+0x60));
                    box.addPos(*(JGeometry::TVec2f*)(this_+0xc));
                    fn_80239914(&box, (*(s32*)(this_+0x4)), (*(s32*)(this_+0x198)));
                    fn_801EF510(this_);
                    fn_801F2B7C(this_, -100, -1, 1);
                    fn_801F2618(this_, 0, 0);
                    return;
                }
            }
            fn_801EE8F4(this_, &pos, 0, 0);
            pos.scale(lbl_8053CEA8);
            (*(f32*)(this_+0x3c)) = pos.x;
            (*(f32*)(this_+0x40)) = pos.y;
            (*(f32*)(this_+0x44)) = lbl_8053CEBC;
        }
        fn_801F2B7C(this_, -100, -1, 1);
        fn_801F2618(this_, 0, 0);
        break;
    case 3: {
        s32 handle = (*(s32*)(this_+0x198));
        u8* manager = fn_8020D58C();
        fn_8020D7D0(manager + manager[0]*0x784 + 4, handle);
        fn_801EF510(this_);
        if ((int)(*(u16*)(this_+0x94)) == 6 || (int)(*(u16*)(this_+0x94)) == 7) {
            box = (*(JGeometry::TBox2f*)(this_+0x60));
            box.addPos(*(JGeometry::TVec2f*)(this_+0xc));
            fn_80239914(&box, (*(s32*)(this_+0x4)), (*(s32*)(this_+0x198)));
            return;
        }
        if (PSVECDistance(&(*(JGeometry::TVec3f*)(this_+0xc)), &(*(JGeometry::TVec3f*)(this_+0x320))) >= lbl_8053CEC0) {
            (*(f32*)(this_+0xc)) = ((s32((*(f32*)(this_+0xc))) + 4) / 8) * 8;
            (*(f32*)(this_+0x10)) = ((s32((*(f32*)(this_+0x10))) + 4) / 8) * 8;
            (*(JGeometry::TVec3f*)(this_+0x320)) = (*(JGeometry::TVec3f*)(this_+0xc));
            (*(f32*)(this_+0x3c)) = 0.0f; (*(f32*)(this_+0x40)) = 0.0f; (*(f32*)(this_+0x44)) = 0.0f;
            JGeometry::TBox2f b;
b.set(*(JGeometry::TBox2f*)(this_+0x60));
            b.addPos(*(JGeometry::TVec2f*)(this_+0xc));
            fn_80239914(&b, (*(s32*)(this_+0x4)), (*(s32*)(this_+0x198)));
            (*(JGeometry::TVec3f*)(this_+0x18)) = (*(JGeometry::TVec3f*)(this_+0xc));
            (*(s32*)(this_+0x300)) = 8;
            return;
        }
        if (((*(f32*)(this_+0x3c)) != lbl_8053CEA0 || (*(f32*)(this_+0x40)) != lbl_8053CEA0) && fn_801F2618(this_,0,0)) {
            (*(f32*)(this_+0xc)) = ((s32((*(f32*)(this_+0xc))) + 4) / 8) * 8;
            (*(f32*)(this_+0x10)) = ((s32((*(f32*)(this_+0x10))) + 4) / 8) * 8;
            (*(JGeometry::TVec3f*)(this_+0x320)) = (*(JGeometry::TVec3f*)(this_+0xc));
            (*(f32*)(this_+0x3c)) = 0.0f; (*(f32*)(this_+0x40)) = 0.0f; (*(f32*)(this_+0x44)) = 0.0f;
            JGeometry::TBox2f b;
b.set(*(JGeometry::TBox2f*)(this_+0x60));
            b.addPos(*(JGeometry::TVec2f*)(this_+0xc));
            fn_80239914(&b, (*(s32*)(this_+0x4)), (*(s32*)(this_+0x198)));
            (*(JGeometry::TVec3f*)(this_+0x18)) = (*(JGeometry::TVec3f*)(this_+0xc));
            (*(s32*)(this_+0x300)) = 8;
            (*(JGeometry::TVec3f*)(this_+0x3c)).zero();
        } else {
            JGeometry::TVec3f oldPos((*(JGeometry::TVec3f*)(this_+0xc)));
            JGeometry::TVec3f oldVel((*(JGeometry::TVec3f*)(this_+0x3c)));
            f32 sq = (*(JGeometry::TVec3f*)(this_+0x3c)).squared();
            if (!(sq <= JGeometry::TUtilf::epsilon())) {
                f32 inv = JGeometry::TUtilf::inv_sqrt(sq);
                (*(JGeometry::TVec3f*)(this_+0x3c)).scale(inv);
            }
            if ((*(s32*)(this_+0x314)) >= 0) (*(JGeometry::TVec3f*)(this_+0x3c)).scale(lbl_8053CECC);
            else if ((*(s32*)(this_+0x310)) >= 0) (*(JGeometry::TVec3f*)(this_+0x3c)).scale(lbl_8053CEB8);
            else (*(JGeometry::TVec3f*)(this_+0x3c)).zero();
            (*(f32*)(this_+0xc)) += (*(f32*)(this_+0x3c));
            (*(f32*)(this_+0x10)) += (*(f32*)(this_+0x40));
            (*(JGeometry::TVec3f*)(this_+0x3c)).set(oldVel);
            f32 half = 0.5f;
            center.set(half*(box.i.x-box.f.x)+box.f.x,
                       half*(box.i.y-box.f.y)+box.f.y);
            if (fn_802265DC(this_+0xc, (*(s32*)(this_+0x4)), 0) == 1 || fn_80226850(this_+0xc, (*(s32*)(this_+0x4))) == 0x8f) {
                (*(JGeometry::TVec3f*)(this_+0x3c)).zero();
            } else if ((*(f32*)(this_+0x3c)) != lbl_8053CEA0 || (*(f32*)(this_+0x40)) != lbl_8053CEA0) {
                u8* actors[1024];
                s32 count = fn_801F7818(fn_801F856C(), 0x414d4f53, (*(s32*)(this_+0x4)), actors, -1);
                for (s32 i=0; i<count; i++) {
                    u8* other=actors[i];
                    if (other && other) {
                        if (*(s32*)(other+0x198) != (*(s32*)(this_+0x198))) {
                            f32 dx=*(f32*)(other+0xc)-(*(f32*)(this_+0xc));
                            f32 dy=*(f32*)(other+0x10)-(*(f32*)(this_+0x10));
                            if (std::sqrtf(dx*dx+dy*dy) < lbl_8053CEB8) {
                                (*(JGeometry::TVec3f*)(this_+0x3c)).zero();
                                break;
                            }
                        }
                    }
                }
            }
            (*(JGeometry::TVec3f*)(this_+0xc)).set(oldPos);
            (*(JGeometry::TVec3f*)(this_+0xc)).add((*(JGeometry::TVec3f*)(this_+0x3c)));
        }
        if ((*(s32*)(this_+0x30c)) < 2 && ((*(f32*)(this_+0x3c)) != lbl_8053CEA0 || (*(f32*)(this_+0x40)) != lbl_8053CEA0)) {
            ++(*(s32*)(this_+0x30c));
            if ((*(s32*)(this_+0x30c)) == 2) fn_801F0E34(this_, 0x30004, 0);
        }
        JGeometry::TBox2f b;
b.set(*(JGeometry::TBox2f*)(this_+0x60));
        b.addPos(*(JGeometry::TVec2f*)(this_+0xc));
        fn_80239914(&b, (*(s32*)(this_+0x4)), (*(s32*)(this_+0x198)));
        if ((*(s32*)(this_+0x300)) > 0) --(*(s32*)(this_+0x300));
        else if ((*(s32*)(this_+0x300)) == 0 && (*(JGeometry::TVec3f*)(this_+0x3c)).isZero()) {
            s32 dir=-1;
            (*(s32*)(this_+0x310)) = fn_80239558(&b, (*(s32*)(this_+0x4)), (*(s32*)(this_+0x198)));
            if ((*(s32*)(this_+0x310)) >= 0) {
                dir = fn_80230CFC((*(s32*)(this_+0x310)));
                (*(s32*)(this_+0x314)) = -1;
            } else {
                (*(s32*)(this_+0x314)) = fn_80239470(&b,(*(s32*)(this_+0x4)),(*(s32*)(this_+0x198)));
                if ((*(s32*)(this_+0x314)) >= 0) {
                    (*(s32*)(this_+0x310)) = -1;
                    dir = fn_80230CFC((*(s32*)(this_+0x314)));
                    if (dir == 0) dir = 1;
                    else if (dir == 1) dir = 0;
                    else if (dir == 2) dir = 3;
                    else if (dir == 3) dir = 2;
                }
            }
            if (dir >= 0 && dir < 4) {
                (*(s32*)(this_+0x30c)) = 0;
                (*(JGeometry::TVec3f*)(this_+0x3c)).set(lbl_80465A98[dir]);
                (*(JGeometry::TVec3f*)(this_+0x320)).set((*(JGeometry::TVec3f*)(this_+0xc)));
            }
        }
        break;
    }
    case 4: {
        JGeometry::TVec3f p((*(JGeometry::TVec3f*)(this_+0xc)));
        if (!fn_800FE3EC(this_+0x230, (*(s32*)(this_+0x308)), &p, (*(s32*)(this_+0x4)))) break;
        (*(s32*)(this_+0x2f8)) = 5;
    }
    case 5:
        if ((*(u32*)(this_+0x90) >> 27) && (u8)((Actor*)this_)->v11()) {
            ((Actor*)this_)->v07();
            return;
        }
        fn_801EF510(this_);
        (*(f32*)(this_+0x44)) += lbl_8053CEB4;
        (*(JGeometry::TVec3f*)(this_+0xc)).add((*(JGeometry::TVec3f*)(this_+0x3c)));
        if ((*(f32*)(this_+0x14)) <= 0.0f) {
            (*(f32*)(this_+0x14)) = 0.0f;
            JGeometry::TVec3f p;
 p.x=(*(f32*)(this_+0xc)); p.y=(*(f32*)(this_+0x10)); p.z=(*(f32*)(this_+0x14));
            p.y += lbl_8053CEB8;
            if ((*(s32*)(this_+0x304))) {
                fn_8013CC50((*(s32*)(this_+0x4)), &p, lbl_8053CEBC, 0x3cf, 0,0,0,0,1);
                fn_801F0E34(this_,0x40007,0);
            }
            (*(s32*)(this_+0x304))=1;
            JGeometry::TVec3f vel;
            vel.setAll(0.0f);
            s32 room=(*(s32*)(this_+0x4));
            JGeometry::TVec3f pp((*(JGeometry::TVec3f*)(this_+0xc)));
            s32 result;
            fn_800FDEA0(this_+0x230,&pp,&vel,&room,&result,0x200,lbl_8053CEE8);
            (*(f32*)(this_+0x3c))=vel.x; (*(f32*)(this_+0x40))=vel.y; (*(f32*)(this_+0x44))=lbl_8053CEBC;
        }
        fn_801F2B7C(this_,-100,-1,1);
        fn_801F2618(this_,0,0);
        void* obj = fn_801F8108(this_,0x4c4e424d,-1,lbl_8053CEC4);
        if(obj) {
            obj = fn_801F666C(fn_801F856C(),obj);
            if(obj) fn_801BEDBC(obj);
        }
        break;
    }
}

extern f32 lbl_8053CEB8;
extern f32 lbl_8053CEF8;
extern f32 lbl_8053CEFC;
extern f32 lbl_8053CF00;
extern f32 lbl_8053CF04;
extern f32 lbl_8053CF08;
extern f32 lbl_8053CF0C;
extern f32 lbl_8053CF10;
extern f32 lbl_8053CF14;
extern f32 lbl_8053CF18;
extern f32 lbl_8053CF1C;
extern f32 lbl_8053CF20;
extern "C" void fn_80142224(u8* this_) {
    const f32 e = lbl_8053CF08;
    const f32 d = lbl_8053CF04;
    const f32 c = lbl_8053CF00;
    const f32 b = lbl_8053CEFC;
    const f32 a = lbl_8053CEF8;

    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = a;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = b;
    *(f32*)(this_ + 0x70) = c;
    *(f32*)(this_ + 0x74) = d;
    *(f32*)(this_ + 0x78) = e;
    *(f32*)(this_ + 0x7c) = e;
    *(f32*)(this_ + 0x80) = a;
    *(f32*)(this_ + 0x84) = a;
    *(f32*)(this_ + 0x88) = b;
    *(f32*)(this_ + 0x8c) = b;
    *(u32*)(this_ + 0x300) = 0;
    *(u32*)(this_ + 0x30c) = 0;
    *(u32*)(this_ + 0xb0) = 0xa040004;
    *(s32*)(this_ + 0x310) = -1;
    *(s32*)(this_ + 0x314) = -1;
    *(s32*)(this_ + 0x31c) = (*(u32*)(this_ + 0x90) >> 4) & 1;
    if (*(s32*)(this_ + 0x31c) != 0) {
        *(f32*)(this_ + 0x60) = c;
        *(f32*)(this_ + 0x64) = c;
        *(f32*)(this_ + 0x68) = e;
        *(f32*)(this_ + 0x6c) = e;
        *(s32*)(this_ + 0xc0) = 3;
    }
    *(u16*)(this_ + 0x94) = *(u32*)(this_ + 0x90) & 0xf;
    *(u32*)(this_ + 0x308) = (*(u32*)(this_ + 0x90) >> 8) & 0xff;
    *(s32*)(this_ + 0x318) = 1;
    *(s32*)(this_ + 0x304) = 0;
    *(s32*)(this_ + 0xbc) = 3;

    if (*(u16*)(this_ + 0x94) == 3 || (u16)(*(u16*)(this_ + 0x94) - 4) <= 1 || *(u16*)(this_ + 0x94) == 7) {
        *(s32*)(this_ + 0xc0) = 3;
        *(f32*)(this_ + 0x60) = lbl_8053CF0C;
        *(f32*)(this_ + 0x64) = lbl_8053CF10;
        *(f32*)(this_ + 0x68) = lbl_8053CF14;
        *(f32*)(this_ + 0x6c) = lbl_8053CF18;
        *(f32*)(this_ + 0x70) = d;
        *(f32*)(this_ + 0x74) = lbl_8053CF1C;
        *(f32*)(this_ + 0x78) = lbl_8053CF20;
        *(f32*)(this_ + 0x7c) = lbl_8053CEB8;
        *(f32*)(this_ + 0x80) = lbl_8053CF0C;
        *(f32*)(this_ + 0x84) = lbl_8053CF10;
        *(f32*)(this_ + 0x88) = lbl_8053CF14;
        *(f32*)(this_ + 0x8c) = lbl_8053CF18;
    }
    *(s32*)(this_ + 0x2f8) = 3;

    switch (*(u16*)(this_ + 0x94)) {
    case 1:
    case 4:
    case 6:
    case 7:
        *(u8*)(this_ + 0x196) = 1;
        *(u8*)(this_ + 0x1a8) = 0;
        return;
    case 5:
        *(u8*)(this_ + 0x196) = 1;
        *(u8*)(this_ + 0x1a8) = 0;
        *(s32*)(this_ + 0xb8) = 1;
        *(s32*)(this_ + 0x318) = 0;
        *(s32*)(this_ + 0x2f8) = 4;
        return;
    case 3:
        *(u8*)(this_ + 0x196) = 1;
    default:
        *(s32*)(this_ + 0xb8) = 1;
        *(s32*)(this_ + 0x2f8) = 0;
        return;
    }
}

