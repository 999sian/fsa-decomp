// Game TU 801B3F60-801B4D0C (ZDCO). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
extern const f32 lbl_8053EA08;
extern const f32 lbl_8053E9EC;
extern const f32 lbl_8053E9C0;
#include "std/math.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
extern const f64 lbl_8053E9D0;
extern const f64 lbl_8053E9D8;
extern const f64 lbl_8053E9E0;

static inline f32 zdcoSqrt(const f32 mag)
{
    if (mag > lbl_8053E9C0) {
        f64 xd = mag;
        f64 tmpd = __frsqrte(xd);
        tmpd = lbl_8053E9D0 * tmpd * (lbl_8053E9D8 - (tmpd * tmpd * xd));
        tmpd = lbl_8053E9D0 * tmpd * (lbl_8053E9D8 - (tmpd * tmpd * xd));
        tmpd = lbl_8053E9D0 * tmpd * (lbl_8053E9D8 - (tmpd * tmpd * xd));
        return (f32)(xd * tmpd);
    } else if (mag < lbl_8053E9E0) {
        return *(f32*)__float_nan;
    } else if (fpclassify(mag) == 1) {
        return *(f32*)__float_nan;
    } else {
        return mag;
    }
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A375C[];
extern "C" {
}

extern "C" void* fn_801B3F60(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A375C;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801B3FC0(void) {}

extern const f32 lbl_8053E9C4;
extern const f32 lbl_8053E9C8;
extern const f32 lbl_8053E9E8;
extern const f32 lbl_8053E9F0;
extern const f32 lbl_8053E9F4;
extern const f32 lbl_8053E9F8;
extern const f32 lbl_8053E9FC;
extern const f32 lbl_8053EA00;
extern const f32 lbl_8053EA04;
extern const s32 lbl_804A3740[];
extern char* lbl_8053AB10;
extern void* lbl_8053AAF8;
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D8050(void*, s32, s32, s32);
extern "C" void fn_802D79E8(void*, s32, s32, f32, f32);
extern "C" void fn_8022FEB8(f32*, s32, s32, s32, s32);
extern "C" void fn_8022FE80(s32, s32, s32, s32, s32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" u8 fn_802300EC(s32);
extern "C" u8 fn_8038AD24(s32, s32, s32, s32, JGeometry::TVec3<f32>, s32);
extern "C" u8 fn_803865B8(s32);
extern "C" u8 fn_80384C58(s32, s32);
extern "C" u8 fn_80388CAC(s32, s32);
extern "C" void fn_801EEC98(void*, s32, u16*, s32*, f32*, s32*, s32, s32);
extern "C" u8 fn_8023F264(s32);
extern "C" s32 fn_8022EA0C(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_80230188(s32);
extern "C" u8 fn_8022DCD8(s32);
extern "C" u8 fn_80236B50(s32);
extern "C" u8 fn_8022D534(s32);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32);
extern "C" s32 fn_80138A30(void*);
extern "C" void* fn_801F856C();
extern "C" s32 fn_801F68E0(void*);
extern "C" void fn_801F6884(void*);
extern "C" void fn_80230C6C(s32);
extern "C" void fn_801F0D20(void*, s32);
extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" void* fn_80119DD0();
extern "C" void fn_80119998(void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80230FD0(s32, s32);
extern "C" void fn_80236554(s32, s32, s32);
extern "C" void fn_802D9FF4(void*, s32, s32);
extern "C" void fn_802DBD60(void*);

static inline void zdcoPlaySound(u8* p) {
    int n = *(s32*)(p + 0x254);
    if (n != 0) fn_802D8050(fn_802D6A9C(), n, 1, 0xff);
}
extern "C" void fn_801B3FC4(u8* p) {
    s32 finalIndex;
    s32 quad = -1;
    f32 dist = 0.0f;
    JGeometry::TVec3<f32> v;
    switch (*(s32*)(p + 0x230)) {
    case 0:
        if (*(s32*)(p + 0x25c) == 0) break;
        if ((u8)((Actor*)p)->v11()) {
            int n = *(s32*)(p + 0x254);
            if (n != 0) fn_802D8050(fn_802D6A9C(), n, 1, 0xff);
            *(u16*)(p + 0x94) = 1;
            break;
        }
        *(u16*)(p + 0x94) = 0;
        {
            f32 box[4];
            box[0] = *(f32*)(p + 0x70);
            box[1] = *(f32*)(p + 0x74);
            box[2] = *(f32*)(p + 0x78);
            box[3] = *(f32*)(p + 0x7c);
            box[0] += *(f32*)(p + 0x26c);
            box[1] += *(f32*)(p + 0x270);
            box[2] += *(f32*)(p + 0x26c);
            box[3] += *(f32*)(p + 0x270);
            fn_8022FEB8(box, *(s32*)(p + 0x4), *(s32*)(p + 0x198), 0, 0);
        }
        *(s32*)(p + 0x248) = fn_8022FD8C(*(s32*)(p + 0x198));
        if (*(s32*)(p + 0x248) >= 0 && fn_802300EC(*(s32*)(p + 0x248))) {
            JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(p + 0xc);
            pos.y -= lbl_8053E9C4;
            s32 handle=*(s32*)(p+0x198);
            s32 room=*(s32*)(p+4);
            if (fn_8038AD24(*(s32*)(p + 0x248), lbl_804A3740[*(s32*)(p + 0x258)], handle, room, pos, 0)) {
                *(s32*)(p + 0x230) = 3;
            }
        }
        break;
    case 1:
        if (*(s32*)(p + 0x25c) == 0) break;
        ((Actor*)p)->v10(0xff, 1);
        *(s32*)(p + 0x230) = 10;
        break;
    case 2:
        if (*(s32*)(p + 0x25c) == 0) break;
        if (!(u8)((Actor*)p)->v11()) {
            int n = *(s32*)(p + 0x254);
            if (n != 0) fn_802D8050(fn_802D6A9C(), n, 1, 0xff);
            *(u16*)(p + 0x94) = 1;
            break;
        }
        *(u16*)(p + 0x94) = 0;
        break;
    case 3:
        fn_8022FE80(*(s32*)(p + 0x248), *(s32*)(p + 0x4), *(s32*)(p + 0x198), 1, 0);
        if (fn_803865B8(*(s32*)(p + 0x248)) && fn_80384C58(*(s32*)(p + 0x248), *(s32*)(p + 0x198))) {
            *(s32*)(p + 0x230) = 0;
        }
        break;
    case 4:
        if (*(s32*)(p + 0x25c) == 0) break;
        fn_801EEC98(p, *(s32*)(p + 0x198), 0, &quad, &dist, 0, 0, 0);
        if (*(s32*)(p + 0x250) == 3) {
            if (quad < 0) break;
            if (!(dist > lbl_8053E9C8)) goto activate;
            break;
        } else {
            s32 i;
            s32 cnt;
            i = 0;
            cnt = 0;
            for (; i < 4; i++) {
                if (fn_8023F264(i) && i == fn_8022EA0C(i)) {
                    s32 room = *(s32*)(p + 0x4);
                    if (room == fn_8023DE58(i) && !fn_80230188(i) &&
                        !fn_8022DCD8(i) && !fn_80236B50(i) && !fn_8022D534(i)) {
                        f32 dx = fn_8023E724(i)->x - *(f32*)(p + 0xc);
                        f32 dy = fn_8023E724(i)->y - *(f32*)(p + 0x10);
                        if (std::sqrtf(dx * dx + dy * dy) < lbl_8053E9E8) cnt++;
                    }
                }
            }
            if (cnt < fn_80138A30(lbl_8053AAF8)) break;
            if (quad < 0) break;
            if (dist > lbl_8053E9C8) break;
        }
activate:
        if (*(s32*)(p + 0x258) == 0) {
            int n = *(s32*)(p + 0x254);
            if (n != 0) fn_802D8050(fn_802D6A9C(), n, 1, 0xff);
            p[0x11c] = 0;
            break;
        }
        *(s32*)(p + 0x230) = 5;
    case 5: {
        s32 i;
        if (!fn_801F68E0(fn_801F856C())) break;
        for (i = 0; i < 4; i++) fn_80230C6C(i);
        *(s32*)(p + 0x230) = 6;
    }
    case 6: {
        u8* c;
        f32 box[4];
        v.set(*(JGeometry::TVec3<f32>*)(p + 0xc));
        v.y -= lbl_8053E9EC;
        c = *(u8**)(lbl_8053AB10 + 0x24);
        if (c[0x840] == 0) {
            c[0x840] = 1;
            *(f32*)(c + 0x84c) = v.x;
            *(f32*)(c + 0x844) = v.x;
            *(f32*)(c + 0x850) = v.y;
            *(f32*)(c + 0x848) = v.y;
            *(f32*)(c + 0x854) = lbl_8053E9F0;
            *(f32*)(c + 0x1d4) = lbl_8053E9F4;
            *(f32*)(c + 0x1d8) = lbl_8053E9F4;
        }
        c = *(u8**)(lbl_8053AB10 + 0x30);
        if (c[0x284] == 0) {
            c[0x284] = 1;
            *(f32*)(c + 0x28c) = lbl_8053E9F8;
        }
        f32 height=lbl_8053E9FC;
        box[0] = lbl_8053EA00;
        box[1] = lbl_8053EA00;
        box[2] = lbl_8053E9E8;
        box[3] = lbl_8053E9E8;
        v.y = lbl_8053E9C0;
        v.z = lbl_8053E9C0;
        v.x = lbl_8053E9C0;
        f32 x = *(f32*)(p+0x26c);
        f32 lowx = box[0]+x;
        f32 highx = box[2]+x;
        box[0]=lowx;
        f32 y = *(f32*)(p+0x270);
        f32 lowy=box[1]+y;
        f32 highy=box[3]+y;
        box[2]=highx;
        box[1]=lowy;
        box[3]=highy;
        v.y = height;
        fn_8022FEB8(box, *(s32*)(p + 0x4), *(s32*)(p + 0x198), 0, 0);
        *(s32*)(p + 0x248) = fn_8022FD8C(*(s32*)(p + 0x198));
        if (*(s32*)(p + 0x248) < 0) *(s32*)(p + 0x248) = 0;
        s32 handle=*(s32*)(p+0x198);
        s32 room=*(s32*)(p+4);
        if (fn_8038AD24(*(s32*)(p + 0x248), lbl_804A3740[*(s32*)(p + 0x258)], handle, room, v, 0x4102)) {
            *(s32*)(p + 0x230) = 7;
        }
        break;
    }
    case 7: {
        u8* c;
        v.set(*(JGeometry::TVec3<f32>*)(p + 0xc));
        v.y -= lbl_8053E9EC;
        c = *(u8**)(lbl_8053AB10 + 0x24);
        if (c[0x840] == 0) {
            c[0x840] = 1;
            *(f32*)(c + 0x84c) = v.x;
            *(f32*)(c + 0x844) = v.x;
            *(f32*)(c + 0x850) = v.y;
            *(f32*)(c + 0x848) = v.y;
            *(f32*)(c + 0x854) = lbl_8053E9F0;
            *(f32*)(c + 0x1d4) = lbl_8053E9F4;
            *(f32*)(c + 0x1d8) = lbl_8053E9F4;
        }
        c = *(u8**)(lbl_8053AB10 + 0x30);
        if (c[0x284] == 0) {
            c[0x284] = 1;
            *(f32*)(c + 0x28c) = lbl_8053E9F8;
        }
        fn_8022FE80(*(s32*)(p + 0x248), *(s32*)(p + 0x4), *(s32*)(p + 0x198), 0, 0);
        if (fn_80388CAC(*(s32*)(p + 0x248), *(s32*)(p + 0x198))) {
            if (*(s32*)(p + 0x250) == 3) {
                int n;
                fn_801F6884(fn_801F856C());
                n = *(s32*)(p + 0x254);
                if (n != 0) fn_802D8050(fn_802D6A9C(), n, 1, 0xff);
                p[0x11c] = 0;
                break;
            }
            *(s32*)(p + 0x234) = 0x5a;
            *(s32*)(p + 0x230) = 8;
        }
        break;
    }
    case 8:
        if (*(s32*)(p + 0x234) != 0) {
            fn_802D79E8(fn_802D6A9C(), *(s32*)(p + 0x4), 0, lbl_8053EA04, 0.0f);
            fn_801F0D20(p, 0x50);
            if (*(s32*)(p + 0x234) == 1) {
                ((Actor*)p)->v10(0xff, 1);
            }
        } else if (!(u8)((Actor*)p)->v11()) {
            s32 i;
            int n;
            fn_802D79E8(fn_802D6A9C(), *(s32*)(p + 0x4), 0, lbl_8053EA04, 0.0f);
            fn_801F0D20(p, 0x50);
            fn_801F6884(fn_801F856C());
            n = *(s32*)(p + 0x254);
            if (n != 0) fn_802D8050(fn_802D6A9C(), n, 1, 0xff);
            fn_80119998(fn_80119DD0(), 0xc8, 0, 2, 0, 0, 0x64, 0);
            fn_801F0E34(p, 0x400b7, 0);
            for (i = 0; i < 4; i++) fn_80230FD0(i, 0x10003);
            *(s32*)(p + 0x234) = 0xc8;
            *(s32*)(p + 0x230) = 9;
        }
        break;
    case 9: {
        u8* c;
        c = *(u8**)(lbl_8053AB10 + 0x24);
        v.set(*(JGeometry::TVec3<f32>*)(p + 0xc));
        if (c[0x7f5] == 0) {
            c[0x7f4] = 1;
            *(s32*)(c + 0x7f8) = 4;
            *(f32*)(c + 0x7fc) = *(f32*)(p + 0xc);
            *(f32*)(c + 0x800) = *(f32*)(p + 0x10);
            *(f32*)(c + 0x804) = *(f32*)(p + 0x14);
            c[0x7f6] = 0;
        }
        c = *(u8**)(lbl_8053AB10 + 0x30);
        if (c[0x284] == 0) {
            c[0x284] = 1;
            *(f32*)(c + 0x28c) = lbl_8053E9F8;
        }
        fn_802D79E8(fn_802D6A9C(), *(s32*)(p + 0x4), 0, lbl_8053EA04, 0.0f);
        fn_801F0D20(p, 0x50);
        if (*(s32*)(p + 0x234) != 0) break;
        {
            
            for (finalIndex = 0; finalIndex < 4; finalIndex++) {
                if (fn_8023F264(finalIndex)) {
                    s32 room = *(s32*)(p + 0x4);
                    if (room == fn_8023DE58(finalIndex)) fn_80236554(finalIndex, 0x20, 0);
                }
            }
        }
        fn_802D9FF4(fn_802D6A9C(), 0, 9);
        fn_802DBD60(fn_802D6A9C());
        break;
    }
    case 10:
        break;
    }
    if (*(s32*)(p + 0x234) > 0) (*(s32*)(p + 0x234))--;
    if (*(s32*)(p + 0x238) > 0) (*(s32*)(p + 0x238))--;
    if (*(s32*)(p + 0x23c) > 0) (*(s32*)(p + 0x23c))--;
}

extern "C" void fn_801B49DC(u8* this_) {
    *(f32*)(this_ + 0x60) = lbl_8053EA08;
    *(f32*)(this_ + 0x64) = lbl_8053EA08;
    *(f32*)(this_ + 0x68) = lbl_8053E9EC;
    *(f32*)(this_ + 0x6c) = lbl_8053E9EC;
    *(f32*)(this_ + 0x70) = lbl_8053EA08;
    *(f32*)(this_ + 0x74) = lbl_8053EA08;
    *(f32*)(this_ + 0x78) = lbl_8053E9EC;
    *(f32*)(this_ + 0x7c) = lbl_8053E9EC;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x250) = *(u32*)(this_ + 0x90) & 0xff;
    *(s32*)(this_ + 0x254) = (*(u32*)(this_ + 0x90) >> 22) & 0x1f;
    *(s32*)(this_ + 0x258) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(s32*)(this_ + 0x24c) = 0;
    *(f32*)(this_ + 0x26c) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x270) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x274) = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x44) = lbl_8053E9C0;
    *(f32*)(this_ + 0x40) = lbl_8053E9C0;
    *(f32*)(this_ + 0x3c) = lbl_8053E9C0;
    *(s32*)(this_ + 0x25c) = 0;
    *(u16*)(this_ + 0x94) = 0;
    this_[0x1a8] = 0;
    switch (*(s32*)(this_ + 0x250)) {
    case 0:
        *(s32*)(this_ + 0x230) = 0;
        break;
    case 2:
        *(s32*)(this_ + 0x230) = 1;
        break;
    case 1:
        *(s32*)(this_ + 0x230) = 2;
        break;
    case 3:
    case 7:
        *(s32*)(this_ + 0x230) = 4;
        break;
    default:
        *(s32*)(this_ + 0x230) = 10;
        break;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
