#include "JSystem/JAudio/JASFakeMatchFSA.h"

#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "std/math.h"
#include "JSystem/JGeometry/Vec.h"

extern void* lbl_8053AC98;
extern "C" s32 fn_8023AF14(f32* box, s32 room, f32 r, s32 flag);
extern "C" s32 fn_8023B8E4(f32* box, s32 room, f32* pos, s32 flag);
extern "C" u8 fn_8023A51C(s32 i);
extern "C" u8 fn_8023AAF8(s32 i, f32* box, s32 room, void* out);
extern "C" f32* fn_8023E724(s32 i);
extern "C" void fn_802A381C(void* mgr, void* pos, s32 room, s32 id);
extern "C" void fn_802A3948(void* mgr, void* pos, s32 a, s32 room, s32 id);
extern "C" void fn_801F0E34(void* actor, u32 id, s32 a);
extern "C" u8* fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u32 fn_80226850(void* pos, s32 room);
extern "C" u32 fn_80226998(void* pos, s32 room);
extern "C" u8 fn_80235448(s32 i);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 fourcc, s32 room, void* pos, u32 param, s32 a, s32 b);


extern void* lbl_804A9078[];
extern const f32 lbl_80540E14;
extern const f32 lbl_80540E18;
extern const f32 lbl_80540E1C;
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void* fn_802CCEB0(void* this_, s16 freeFlag) {
    if (this_ != NULL) {
        *(void**)this_ = lbl_804A9078;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_802CCF10(void) {}

extern "C" void fn_802CCF14(u8* p) {
    s32 hit;
    s32 near;
    JGeometry::TVec2<f32> pos(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
    f32 box[4];
    box[0] = *(f32*)(p + 0x60);
    box[1] = *(f32*)(p + 0x64);
    box[2] = *(f32*)(p + 0x68);
    box[3] = *(f32*)(p + 0x6c);
    box[0] += pos.x;
    box[1] += pos.y;
    box[2] += pos.x;
    box[3] += pos.y;
    if (*(s32*)(p + 0x238) == 3) {
        hit = fn_8023AF14(box, *(s32*)(p + 4), 100.0f, 0);
    } else {
        hit = fn_8023AF14(box, *(s32*)(p + 4), 0.0f, 0);
    }
    near = fn_8023B8E4(box, *(s32*)(p + 4), &pos.x, 1);
    *(s32*)(p + 0x108) = 0xc8;
    *(s32*)(p + 0xd8) = 0;
    s32 slotA[4];
    s32 slotB[4];
    s32 i;
    for (i = 0; i < 4; i++) {
        slotA[i] = -1;
        if (fn_8023A51C(i)) {
            slotA[i] = i;
        }
    }
    u8 tmp[8];
    for (i = 0; i < 4; i++) {
        slotB[i] = -1;
        if (fn_8023AAF8(i, box, *(s32*)(p + 4), tmp)) {
            slotB[i] = i;
        }
    }
    switch (*(u32*)(p + 0x230)) {
    case 0:
        if (hit >= 0) {
            if (*(s32*)(p + 0x238) == 3) {
                fn_802A381C(lbl_8053AC98, p + 0xc, *(s32*)(p + 4), 0x3f);
                fn_801F0E34(p, 0x30015, 0);
                *(s32*)(p + 0x23c) = 0x3c;
                *(s32*)(p + 0x230) = 4;
            } else {
                fn_802A381C(lbl_8053AC98, p + 0xc, *(s32*)(p + 4), 0x91);
                *(s32*)(p + 0x230) = 1;
                fn_8013CC50(*(s32*)(p + 4), &JGeometry::TVec3<f32>(*(f32*)(p + 0xc), *(f32*)(p + 0x10), *(f32*)(p + 0x14)), 0.3f, 0x28b, 0, 0, 0, 0, 1);
                fn_8013CC50(*(s32*)(p + 4), &JGeometry::TVec3<f32>(*(f32*)(p + 0xc), *(f32*)(p + 0x10), *(f32*)(p + 0x14)), 0.3f, 0x28c, 0, 0, 0, 0, 1);
                fn_801F0E34(p, 0x50013, 0);
            }
            break;
        }
        for (i = 0; i < 4; i++) {
            if (slotA[i] >= 0) {
                f32 dx = *(f32*)(p + 0xc) - fn_8023E724(i)[0];
                f32 dy = *(f32*)(p + 0x10) - fn_8023E724(i)[1];
                f32 d = std::sqrtf(dx * dx + dy * dy);
                if (d < 100.0f) {
                    *(s32*)(p + 0x23c) = (s32)d >> 3;
                    if (*(s32*)(p + 0x238) == 3) {
                        *(s32*)(p + 0x230) = 3;
                    } else {
                        *(s32*)(p + 0x230) = 2;
                    }
                    break;
                }
            } else if (slotB[i] >= 0) {
                f32 dx = *(f32*)(p + 0xc) - fn_8023E724(i)[0];
                f32 dy = *(f32*)(p + 0x10) - fn_8023E724(i)[1];
                f32 d = std::sqrtf(dx * dx + dy * dy);
                if (d < 40.0f) {
                    *(s32*)(p + 0x23c) = (s32)d >> 3;
                    if (*(s32*)(p + 0x238) == 3) {
                        *(s32*)(p + 0x230) = 3;
                    } else {
                        *(s32*)(p + 0x230) = 2;
                    }
                    break;
                }
            }
        }
        if ((u16)fn_80226850(p + 0xc, *(s32*)(p + 4)) != 0x90 && *(s32*)(p + 0x238) != 3) {
            *(s32*)(p + 0x230) = 5;
        }
        break;
    case 1:
        if (hit != 0) {
            *(s32*)(p + 0x230) = 5;
        }
        break;
    case 2:
        if (*(s32*)(p + 0x23c) == 0) {
            fn_802A381C(lbl_8053AC98, p + 0xc, *(s32*)(p + 4), 0x91);
            fn_8013CC50(*(s32*)(p + 4), &JGeometry::TVec3<f32>(*(f32*)(p + 0xc), *(f32*)(p + 0x10), *(f32*)(p + 0x14)), 0.3f, 0x28b, 0, 0, 0, 0, 1);
            fn_8013CC50(*(s32*)(p + 4), &JGeometry::TVec3<f32>(*(f32*)(p + 0xc), *(f32*)(p + 0x10), *(f32*)(p + 0x14)), 0.3f, 0x28c, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x50013, 0);
            *(s32*)(p + 0x230) = 5;
        } else {
            *(s32*)(p + 0x23c) = *(s32*)(p + 0x23c) - 1;
        }
        break;
    case 3:
        if (*(s32*)(p + 0x23c) == 0) {
            fn_802A381C(lbl_8053AC98, p + 0xc, *(s32*)(p + 4), 0x3f);
            fn_801F0E34(p, 0x30015, 0);
            *(s32*)(p + 0x230) = 4;
            *(s32*)(p + 0x23c) = 0x3c;
        } else {
            *(s32*)(p + 0x23c) = *(s32*)(p + 0x23c) - 1;
        }
        break;
    case 4:
        if (*(s32*)(p + 0x23c) == 0) {
            fn_802A381C(lbl_8053AC98, p + 0xc, *(s32*)(p + 4), 0x3e);
            fn_801F0E34(p, 0x30016, 0);
            *(s32*)(p + 0x230) = 0;
        } else {
            *(s32*)(p + 0x23c) = *(s32*)(p + 0x23c) - 1;
        }
        break;
    case 5:
        if (hit >= 0) {
            *(s32*)(p + 0x230) = 7;
            break;
        }
        for (i = 0; i < 4; i++) {
            if (slotA[i] >= 0) {
                *(s32*)(p + 0x230) = 2;
                f32 dx = *(f32*)(p + 0xc) - fn_8023E724(i)[0];
                f32 dy = *(f32*)(p + 0x10) - fn_8023E724(i)[1];
                f32 d = std::sqrtf(dx * dx + dy * dy);
                *(s32*)(p + 0x23c) = (s32)d >> 3;
                *(s32*)(p + 0x230) = 6;
                break;
            }
        }
        if ((u16)fn_80226850(p + 0xc, *(s32*)(p + 4)) != 0x91 &&
            (u16)fn_80226850(p + 0xc, *(s32*)(p + 4)) != 0x22e &&
            (u16)fn_80226850(p + 0xc, *(s32*)(p + 4)) != 1) {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 6:
        if (*(s32*)(p + 0x23c) == 0) {
            fn_802A381C(lbl_8053AC98, p + 0xc, *(s32*)(p + 4), 0x92);
            fn_8013CC50(*(s32*)(p + 4), &JGeometry::TVec3<f32>(*(f32*)(p + 0xc), *(f32*)(p + 0x10), *(f32*)(p + 0x14)), 0.5f, 0x28b, 0, 0, 0, 0, 1);
            fn_8013CC50(*(s32*)(p + 4), &JGeometry::TVec3<f32>(*(f32*)(p + 0xc), *(f32*)(p + 0x10), *(f32*)(p + 0x14)), 0.5f, 0x28c, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x50012, 0);
            *(u8*)(p + 0x11c) = 0;
        } else {
            *(s32*)(p + 0x23c) = *(s32*)(p + 0x23c) - 1;
        }
        break;
    case 7:
        if (hit < 0) {
            fn_802A381C(lbl_8053AC98, p + 0xc, *(s32*)(p + 4), 0x92);
            fn_8013CC50(*(s32*)(p + 4), &JGeometry::TVec3<f32>(*(f32*)(p + 0xc), *(f32*)(p + 0x10), *(f32*)(p + 0x14)), 0.5f, 0x28b, 0, 0, 0, 0, 1);
            fn_8013CC50(*(s32*)(p + 4), &JGeometry::TVec3<f32>(*(f32*)(p + 0xc), *(f32*)(p + 0x10), *(f32*)(p + 0x14)), 0.5f, 0x28c, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x50012, 0);
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 8:
        if (near >= 0 && fn_80235448(near)) {
            JGeometry::TVec2<f32> pt(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
            if ((u16)fn_80226998(&pt, *(s32*)(p + 4)) == 1) {
                fn_802A3948(lbl_8053AC98, p + 0xc, 0, *(s32*)(p + 4), 0x3e0);
                fn_801F0E34(p, 0x50045, 0);
                i = *(s32*)(p + 4);
                if (i >= 8) {
                    Actor_CreateByID(fn_801F856C(), 'KMRI', i, p + 0xc, 0, -1, -1);
                } else {
                    fn_801F0E34(p, 0x30075, 0);
                    fn_8013CC50(*(s32*)(p + 4), p + 0xc, 1.0f, 0x24a, 1, 0, 0, 0, 1);
                    fn_8013CC50(*(s32*)(p + 4), p + 0xc, 1.0f, 0x24b, 1, 0, 0, 0, 1);
                }
                *(u8*)(p + 0x11c) = 0;
            }
        }
        break;
    }
}

extern "C" void fn_802CDA70(Actor* this_) {
    this_->field_60 = lbl_80540E14;
    this_->field_64 = lbl_80540E14;
    this_->field_68 = lbl_80540E18;
    this_->field_6C = lbl_80540E18;
    *(u32*)((u8*)this_ + 0x23C) = 0;
    *(u32*)((u8*)this_ + 0x238) = this_->field_90 & 0x3F;
    if (*(s32*)((u8*)this_ + 0x238) != 2) {
        this_->field_0C.x += lbl_80540E1C;
        this_->field_0C.y += lbl_80540E1C;
    } else {
        this_->field_0C.x += lbl_80540E1C;
    }
    s32 state = *(s32*)((u8*)this_ + 0x238);
    if (state == 0 || state == 3) {
        *(u32*)((u8*)this_ + 0x230) = 0;
    } else if (state == 1) {
        *(u32*)((u8*)this_ + 0x230) = 5;
    } else {
        *(u32*)((u8*)this_ + 0x230) = 8;
    }
}

void fn_802CDB18(void) {}

