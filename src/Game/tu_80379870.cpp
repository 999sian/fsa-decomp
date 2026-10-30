#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JGeometry/Box.h"


extern void* lbl_804AE948[];
extern "C" void* fn_801F856C(void);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_80379870(void* this_, s16 freeFlag) {
    if (this_ != NULL) {
        *(void**)this_ = lbl_804AE948;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" u8 fn_803798D0(void* this_) {
    u8* self = (u8*)this_;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    s32 count;
    s32 off;
    s32 i;
    x0 = *(f32*)(self + 0x60);
    y0 = *(f32*)(self + 0x64);
    x1 = *(f32*)(self + 0x68);
    y1 = *(f32*)(self + 0x6c);
    x0 += *(f32*)(self + 0xc);
    y0 += *(f32*)(self + 0x10);
    x1 += *(f32*)(self + 0xc);
    y1 += *(f32*)(self + 0x10);
    count = *(s32*)((u8*)fn_801F856C() + 0x1008);
    i = 0;
    off = 0;
    for (; i < count; i++) {
        u8* other;
        u32 id;
        u8 ok;
        f32 ox0, oy0, ox1, oy1;
        if (i == *(s32*)(self + 0x198)) {
            continue;
        }
        other = *(u8**)((u8*)fn_801F856C() + off + 8);
        if (other != NULL) {
            id = *(u32*)(other + 0x1a0);
            if (id == 0x484F5553 || id == 0x4D525441) {
                ox0 = *(f32*)(other + 0x60) + *(f32*)(other + 0xc);
                oy0 = *(f32*)(other + 0x64) + *(f32*)(other + 0x10);
                ox1 = *(f32*)(other + 0x68) + *(f32*)(other + 0xc);
                oy1 = *(f32*)(other + 0x6c) + *(f32*)(other + 0x10);
                if (ox0 <= x0) {
                } else {
                    ox0 = x0;
                }
                if (oy0 <= y0) {
                } else {
                    oy0 = y0;
                }
                if (x1 <= ox1) {
                } else {
                    ox1 = x1;
                }
                if (y1 <= oy1) {
                } else {
                    oy1 = y1;
                }
                ok = ox1 < ox0 && oy1 < oy0;
            } else {
                ok = 0;
            }
        } else {
            ok = 0;
        }
        if (ok) {
            return 1;
        }
        off += 4;
    }
    return 0;
}

extern "C" u8 fn_803798D0(void* this_);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" void fn_80239914(f32* rect, s32 a, void* b);
extern f32 lbl_80475340[];
struct Quad {
    f32 v[4];
};
extern "C" const Quad lbl_804752C0[4];
extern "C" const Quad lbl_80475300[4];
#pragma opt_propagation off
extern "C" void fn_80379A90(Actor* this_) {
    u8 ok;
    JGeometry::TBox2<f32> rect;
    if (*(s32*)((u8*)this_ + 0x234) == 0 || (u8)this_->v11()) {
        switch (*(s32*)((u8*)this_ + 0x230)) {
        case 0:
            if (!fn_803798D0(this_)) {
                return;
            }
            break;
        case 1: {
            Vec saved;
            JGeometry::setTVec3f((f32*)&this_->field_0C, (f32*)&saved);
            ok = 0;
            if (fn_801F2618(this_, 0, 0)) {
                ok = 1;
            }
            JGeometry::setTVec3f((f32*)&saved, (f32*)&this_->field_0C);
            if (!ok) {
                return;
            }
            break;
        }
        }
        {
            u8 idx = (this_->field_90 & 3) + *(s32*)((u8*)this_ + 0x230) * 4;
            const JGeometry::TBox2<f32>* table = (const JGeometry::TBox2<f32>*)lbl_80475340;
            rect.set(table[idx]);
            rect.i.x += this_->field_0C.x;
            f32 y = this_->field_0C.y;
            rect.f.x += this_->field_0C.x;
            rect.i.y += y;
            rect.f.y += y;
            fn_80239914((f32*)&rect, *(s32*)((u8*)this_ + 0x4), *(void**)((u8*)this_ + 0x198));
        }
    }
}
#pragma opt_propagation reset
extern "C" void fn_80379BD8(Actor* this_) {
    u8* self = (u8*)this_;
    u32 w = *(u32*)(self + 0x90);
    u32 idx = w & 3;
    u8* base;
    u32 off;
    f32 v0;
    f32 v1;
    f32 v2;
    f32 v3;
    *(s32*)(self + 0x230) = (w >> 22) & 0x1f;
    switch (*(s32*)(self + 0x230)) {
    case 0:
        base = (u8*)lbl_804752C0;
        off = (idx << 4) & 0xff0;
        v0 = *(f32*)(base + off);
        base += off;
        v1 = *(f32*)(base + 4);
        v2 = *(f32*)(base + 8);
        v3 = *(f32*)(base + 12);
        *(f32*)(self + 0x60) = v0;
        *(f32*)(self + 0x64) = v1;
        *(f32*)(self + 0x68) = v2;
        *(f32*)(self + 0x6c) = v3;
        break;
    case 1:
        base = (u8*)lbl_80475300;
        off = (idx << 4) & 0xff0;
        v0 = *(f32*)(base + off);
        base += off;
        v1 = *(f32*)(base + 4);
        v2 = *(f32*)(base + 8);
        v3 = *(f32*)(base + 12);
        *(f32*)(self + 0x60) = v0;
        *(f32*)(self + 0x64) = v1;
        *(f32*)(self + 0x68) = v2;
        *(f32*)(self + 0x6c) = v3;
        break;
    }
    *(f32*)(self + 0x3c) = 0.0f;
    *(f32*)(self + 0x40) = 0.0f;
    *(f32*)(self + 0x44) = 0.0f;
    *(f32*)(self + 0x80) = *(f32*)(self + 0x60);
    *(f32*)(self + 0x84) = *(f32*)(self + 0x64);
    *(f32*)(self + 0x88) = *(f32*)(self + 0x68);
    *(f32*)(self + 0x8c) = *(f32*)(self + 0x6c);
    *(u32*)(self + 0x234) = *(u32*)(self + 0x90) >> 27;
    if (*(s32*)(self + 0x230) == 1) {
        *(f32*)(self + 0xc) = (f32)(((s32)*(f32*)(self + 0xc) / 16) * 16 + 8);
        *(f32*)(self + 0x10) = (f32)(((s32)*(f32*)(self + 0x10) / 16) * 16 + 8);
        if (idx < 2) {
            *(f32*)(self + 0xc) += 8.0f;
        } else {
            *(f32*)(self + 0x10) += 8.0f;
        }
    }
}

extern "C" void fn_80379D60(void) {
}

