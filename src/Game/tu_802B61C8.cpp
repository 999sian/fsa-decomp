#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"

class Actor;


extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, s32 a, s32 b, f32 sx, f32 sy);
extern "C" const f32 lbl_80540A3C;
extern "C" const f32 lbl_80540A38;
extern "C" char lbl_8046CAB8[];
extern "C" char lbl_804A8750[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void* fn_801F856C(Actor*);
extern "C" void* Actor_CreateByID(void*, u32, s32, Vec*, s32, s32, s32);
extern "C" u16 fn_8022461C(Vec*);
extern "C" void* fn_8013CC50(u32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_801F0E34(Actor*, u32, s32);
extern "C" void* fn_8023E724(s32 i);
extern "C" s32 fn_8023AF14(void* a, void* b, f32 c, s32 d);
extern "C" void fn_801F71A4(void* p, f32 a, f32 b, f32 c);
extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" u8 fn_801F305C(void* this_);
extern "C" u8 fn_801F2618(void* this_, void* out, s32 a);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" u8 fn_801F2B20(void* this_, u32 a);
extern "C" const f32 lbl_80540A40;
extern "C" const f32 lbl_80540A44;
extern "C" const f32 lbl_80540A48;
extern "C" const f32 lbl_80540A4C;
extern "C" const f32 lbl_80540A50;
extern "C" const f32 lbl_80540A54;
extern "C" const f32 lbl_80540A58;
extern "C" const f32 lbl_80540A5C;
extern "C" const f32 lbl_80540A60;
extern "C" const f32 lbl_80540A64;
extern int __float_epsilon[];
extern "C" Actor* fn_802B61C8(Actor* this_, s16 n) {
    if (this_ != nullptr) {
        *(void**)this_ = lbl_804A8750;
        __dt__5ActorFv(this_, 0);
        if (n > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802B6228(char* p) {
    if (*(s32*)(p + 0x4) >= 8) {
        JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(p + 0xc);
        pos.z = lbl_80540A38;
        Actor_CreateByID(fn_801F856C((Actor*)p), 0x4b4d5249, *(s32*)(p + 0x4), &pos, 0, -1, -1);
    } else if (*(f32*)(p + 0x14) < lbl_80540A38 && fn_8022461C((Vec*)(p + 0xc)) == 0xd) {
        fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_80540A3C, 0x3d0, 0, 1, 0, 0, 1);
    } else {
        fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_80540A3C, 0x8c, 1, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_80540A3C, 0x8d, 1, 0, 0, 0, 1);
    }
    fn_801F0E34((Actor*)p, 0x30003, 0);
    *(u8*)(p + 0x11c) = 0;
}

extern "C" void fn_802B6358(void* this_) {
    fn_801F06F0(this_, lbl_8046CAB8, 0x29, 0, 0, lbl_80540A3C, lbl_80540A3C);
}

extern "C" void fn_802B6394(char* p) {
    switch (*(s32*)(p + 0x230)) {
    case 0: {
        f32 box[4];
        JGeometry::TVec3f v;
        box[0] = *(f32*)(p + 0x60);
        box[1] = *(f32*)(p + 0x64);
        box[2] = *(f32*)(p + 0x68);
        box[3] = *(f32*)(p + 0x6c);
        box[0] += *(f32*)(p + 0xc);
        box[1] += *(f32*)(p + 0x10);
        box[2] += *(f32*)(p + 0xc);
        box[3] += *(f32*)(p + 0x10);
        *(s32*)(p + 0x24c) = fn_8023AF14(box, *(void**)(p + 4), lbl_80540A38, 0);
        if (*(s32*)(p + 0x24c) >= 0) {
            *(f32*)(p + 0x23c) = lbl_80540A38;
            *(f32*)(p + 0x238) = lbl_80540A38;
            *(f32*)(p + 0x234) = lbl_80540A38;
            v = *(JGeometry::TVec3f*)fn_8023E724(*(s32*)(p + 0x24c));
            f32 dx = v.x - *(f32*)(p + 0xc);
            f32 dy = v.y - *(f32*)(p + 0x10);
            if (__fabsf(dx) > __fabsf(dy)) {
                if (v.x < *(f32*)(p + 0xc)) {
                    *(f32*)(p + 0x234) = lbl_80540A40;
                } else {
                    *(f32*)(p + 0x234) = lbl_80540A44;
                }
            } else {
                if (v.y < *(f32*)(p + 0x10)) {
                    *(f32*)(p + 0x238) = lbl_80540A40;
                } else {
                    *(f32*)(p + 0x238) = lbl_80540A44;
                }
            }
            *(f32*)(p + 0x44) = lbl_80540A38;
            *(f32*)(p + 0x40) = lbl_80540A38;
            *(f32*)(p + 0x3c) = lbl_80540A38;
            *(f32*)(p + 0x44) = lbl_80540A48;
            *(s32*)(p + 0x230) = 1;
        }
        break;
    }
    case 1: {
        fn_801F71A4(p + 0x3c, *(f32*)(p + 0x234), lbl_80540A4C, lbl_80540A3C);
        fn_801F71A4(p + 0x40, *(f32*)(p + 0x238), lbl_80540A4C, lbl_80540A3C);
        *(JGeometry::TVec3f*)(p + 0xc) += *(JGeometry::TVec3f*)(p + 0x3c);
        if (*(f32*)(p + 0x14) > lbl_80540A38) {
            *(f32*)(p + 0x44) -= lbl_80540A4C;
        } else {
            *(f32*)(p + 0x14) = lbl_80540A38;
            *(s32*)(p + 0x248) = 0x14;
            *(s32*)(p + 0x230) = 2;
        }
        break;
    }
    case 2: {
        *(s32*)(p + 0x248) -= 1;
        if (*(s32*)(p + 0x248) == 0) {
            *(s32*)(p + 0x230) = 3;
            *(f32*)(p + 0x244) = lbl_80540A48;
            *(f32*)(p + 0x44) = lbl_80540A38;
            *(f32*)(p + 0x40) = lbl_80540A38;
            *(f32*)(p + 0x3c) = lbl_80540A38;
            *(f32*)(p + 0x44) = lbl_80540A40;
            *(f32*)(p + 0x60) = lbl_80540A50;
            *(f32*)(p + 0x64) = lbl_80540A50;
            *(f32*)(p + 0x68) = lbl_80540A54;
            *(f32*)(p + 0x6c) = lbl_80540A54;
        }
        break;
    }
    case 3: {
        f32* tgt = (f32*)fn_8023E724(*(s32*)(p + 0x24c));
        f32 dy = tgt[1] - *(f32*)(p + 0x10);
        f32 dx = tgt[0] - *(f32*)(p + 0xc);
        f32 lenSq = dx * dx + dy * dy;
        if (lenSq > lbl_80540A58 * *(f32*)__float_epsilon) {
            f32 scale;
            if (lenSq <= lbl_80540A38) {
                scale = lenSq;
            } else {
                f32 y = __frsqrte(lenSq);
                scale = lbl_80540A5C * y * (lbl_80540A60 - lenSq * (y * y));
            }
            dx *= scale;
            dy *= scale;
        }
        *(f32*)(p + 0x234) = dx * *(f32*)(p + 0x244);
        *(f32*)(p + 0x238) = dy * *(f32*)(p + 0x244);
        fn_801F71A4(p + 0x3c, *(f32*)(p + 0x234), lbl_80540A4C, *(f32*)(p + 0x240));
        fn_801F71A4(p + 0x40, *(f32*)(p + 0x238), lbl_80540A4C, *(f32*)(p + 0x240));
        fn_801F71A4(p + 0x240, lbl_80540A3C, lbl_80540A64, lbl_80540A64);
        *(f32*)(p + 0x44) -= lbl_80540A64;
        *(JGeometry::TVec3f*)(p + 0xc) += *(JGeometry::TVec3f*)(p + 0x3c);
        JGeometry::TVec3f saved = *(JGeometry::TVec3f*)(p + 0xc);
        if (fn_801F3D94(p, 1) != 0 || fn_801F305C(p)) {
            (*(void (**)(char*))(*(char**)p + 0x24))(p);
        } else if (fn_801F2618(p, 0, 0)) {
            *(JGeometry::TVec3f*)(p + 0xc) = saved;
            (*(void (**)(char*))(*(char**)p + 0x24))(p);
        } else if (*(f32*)(p + 0x14) < lbl_80540A38) {
            (*(void (**)(char*))(*(char**)p + 0x24))(p);
        } else if (fn_801F2B7C(p, *(s32*)(p + 0x114), -1, 4)) {
            (*(void (**)(char*))(*(char**)p + 0x24))(p);
        } else if (fn_801F2B20(p, 0)) {
            (*(void (**)(char*))(*(char**)p + 0x24))(p);
        }
        break;
    }
    }
}

extern "C" const f32 lbl_80540A38;
extern "C" const f32 lbl_80540A40;
extern "C" const f32 lbl_80540A44;
extern "C" const f32 lbl_80540A68;
extern "C" const f32 lbl_80540A6C;
extern "C" const f32 lbl_80540A70;
extern "C" void fn_802B67F8(char* p) {
    *(f32*)(p + 0x60) = lbl_80540A68;
    *(f32*)(p + 0x64) = lbl_80540A68;
    *(f32*)(p + 0x68) = lbl_80540A6C;
    *(f32*)(p + 0x6c) = lbl_80540A6C;
    *(f32*)(p + 0x80) = lbl_80540A44;
    *(f32*)(p + 0x84) = lbl_80540A44;
    *(f32*)(p + 0x88) = lbl_80540A40;
    *(f32*)(p + 0x8c) = lbl_80540A40;
    *(f32*)(p + 0x23c) = lbl_80540A38;
    *(f32*)(p + 0x238) = lbl_80540A38;
    *(f32*)(p + 0x234) = lbl_80540A38;
    *(f32*)(p + 0x240) = lbl_80540A70;
    *(s32*)(p + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
