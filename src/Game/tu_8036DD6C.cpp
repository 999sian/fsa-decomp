#include "types.h"
#include "dolphin/mtx.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"


extern u8 lbl_804AE2E0[];
extern "C" void __dt__5ActorFv(void* this_, s32 flags);
extern "C" void* fn_8036DD6C(void* this_, s16 param_2) {
    if (this_ != nullptr) {
        *(u8**)this_ = lbl_804AE2E0;
        __dt__5ActorFv(this_, 0);
        if (param_2 > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8036DDCC(void) {}

extern "C" u32 fn_80226BC4(f32* pos, s32 room);
extern "C" u16 fn_802F9908(void* mgr, s32 room, s32 idx);
extern "C" u8 fn_8023A51C(s32 i);
extern "C" s32 fn_802373EC(s32 i);
extern "C" void* fn_8023E724(s32 i);
extern "C" void fn_8013CC50(s32 id, void* pos, f32 scale, u16 kind, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 a);
extern u8* lbl_8053AB10;
static const u16 lbl_80542D38[4] = {0xfb, 0xfc, 0xfd, 0xfe};
#pragma opt_propagation off
extern "C" void fn_8036DDD0(u8* this_) {
    u32 tile = fn_80226BC4((f32*)(this_ + 0x244), *(s32*)(this_ + 4));
    u16 kind = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), *(s32*)(this_ + 4), tile) & 0x3ff;
    s32 i;
    if (kind != *(u16*)(this_ + 0x240)) {
        this_[0x250] = 1;
        return;
    }
    if (*(s32*)(this_ + 0x234) == 1 && this_[0x250] == 1) {
        this_[0x250] = 0;
        goto spawn;
    }
    this_[0x250] = 0;
    for (i = 0; i < 4; i++) {
        if (fn_8023A51C(i)) {
            if (fn_802373EC(i) == 1) {
                goto check;
            }
        spawn:
            fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, 1.0f, lbl_80542D38[*(s32*)(this_ + 0x234)], 0, 2, 0, 0, 1);
            if (*(u32*)(this_ + 0x23c) != 0xffffffff) {
                fn_801F0E34(this_, *(s32*)(this_ + 0x23c), 0);
            }
            goto tail;
        check:
            {
                Vec tmp;
                const f32* src = (const f32*)fn_8023E724(i);
                JGeometry::setTVec3f(src, &tmp.x);
                if (!(PSVECDistance((Vec*)(this_ + 0xc), &tmp) <= 57.0f && __fabsf(*(f32*)(this_ + 0xc) - tmp.x) <= 42.0f)) {
                    continue;
                }
            }
            fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, 1.0f, lbl_80542D38[*(s32*)(this_ + 0x234)], 0, 2, 0, 0, 1);
            if (*(u32*)(this_ + 0x23c) != 0xffffffff) {
                fn_801F0E34(this_, *(s32*)(this_ + 0x23c), 0);
            }
            break;
        }
    }
tail:
    if (this_[0x230] == 1) {
        this_[0x230] = 0;
        fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, 1.0f, lbl_80542D38[*(s32*)(this_ + 0x234)], 0, 2, 0, 0, 1);
        if (*(u32*)(this_ + 0x23c) != 0xffffffff) {
            fn_801F0E34(this_, *(s32*)(this_ + 0x23c), 0);
        }
    }
}
#pragma opt_propagation reset
extern const f32 lbl_80542D4C;
extern const f32 lbl_80542D50;
extern const f32 lbl_80542D54;
extern "C" void* fn_802D6A9C(void);
extern "C" void* fn_802D9C4C(void);
extern "C" void fn_8036DFF8(u8* this_) {
    u16 pk = *(u32*)(this_ + 0x90) & 0x3ff;
    u32 tile;
    if (pk == 0x1e1) {
        *(JGeometry::TVec3<f32>*)(this_ + 0x244) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
        *(f32*)(this_ + 0xc) += lbl_80542D4C;
        *(f32*)(this_ + 0x10) += lbl_80542D50;
        *(u16*)(this_ + 0x240) = pk;
        goto tail;
    } else if (pk == 0x1e2) {
        JGeometry::TVec2<f32> probe0;
        probe0.set(*(f32*)(this_ + 0xc) - lbl_80542D4C, *(f32*)(this_ + 0x10));
        tile = fn_80226BC4((f32*)&probe0, *(s32*)(this_ + 4));
        pk = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), *(s32*)(this_ + 4), tile) & 0x3ff;
        if (pk == 0x1e1) {
            this_[0x11c] = 0;
            return;
        }
        *(JGeometry::TVec3<f32>*)(this_ + 0x244) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
        *(f32*)(this_ + 0x10) += lbl_80542D50;
        *(u16*)(this_ + 0x240) = pk;
        goto tail;
    } else if (pk == 0x1f1) {
        JGeometry::TVec2<f32> probe1;
        probe1.set(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10) - lbl_80542D4C);
        tile = fn_80226BC4((f32*)&probe1, *(s32*)(this_ + 4));
        pk = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), *(s32*)(this_ + 4), tile) & 0x3ff;
        if (pk == 0x1e1) {
            this_[0x11c] = 0;
            return;
        }
        *(JGeometry::TVec3<f32>*)(this_ + 0x244) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
        *(f32*)(this_ + 0xc) += lbl_80542D4C;
        *(f32*)(this_ + 0x10) += lbl_80542D54;
        *(u16*)(this_ + 0x240) = pk;
        goto tail;
    } else {
        JGeometry::TVec2<f32> probe2;
        probe2.set(*(f32*)(this_ + 0xc) - lbl_80542D4C, *(f32*)(this_ + 0x10));
        tile = fn_80226BC4((f32*)&probe2, *(s32*)(this_ + 4));
        pk = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), *(s32*)(this_ + 4), tile) & 0x3ff;
        if (pk == 0x1f1) {
            this_[0x11c] = 0;
            return;
        }
        JGeometry::TVec2<f32> probe3;
        probe3.set(*(f32*)(this_ + 0xc) - 16.0f, *(f32*)(this_ + 0x10) - 16.0f);
        tile = fn_80226BC4((f32*)&probe3, *(s32*)(this_ + 4));
        pk = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), *(s32*)(this_ + 4), tile) & 0x3ff;
        if (pk == 0x1e2) {
            this_[0x11c] = 0;
            return;
        }
        *(JGeometry::TVec3<f32>*)(this_ + 0x244) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
        *(f32*)(this_ + 0x10) += lbl_80542D54;
        *(u16*)(this_ + 0x240) = pk;
        goto tail;
    }

tail:
    fn_802D6A9C();
    *(void**)(this_ + 0x238) = fn_802D9C4C();
    *(s32*)(this_ + 0x23c) = -1;
    {
        s8 c = *(s8*)(*(char**)(this_ + 0x238));
        if (c == 'r' || c == 's') {
            *(s32*)(this_ + 0x234) = 1;
            *(s32*)(this_ + 0x23c) = 0x50046;
        } else if (c == 'l' || c == 'x' || c == 'p' || c == 't') {
            *(s32*)(this_ + 0x234) = 2;
            *(s32*)(this_ + 0x23c) = 0x50047;
        } else if (c == 'u') {
            *(s32*)(this_ + 0x234) = 3;
            *(s32*)(this_ + 0x23c) = 0x50070;
        } else if (c != '1' || ((u8*)*(char**)(this_ + 0x238))[1] != 'b') {
            *(s32*)(this_ + 0x234) = 0;
            *(s32*)(this_ + 0x23c) = 0x50046;
        } else {
            this_[0x11c] = 0;
        }
    }
    this_[0x250] = 0;
    this_[0x230] = 0;
}

