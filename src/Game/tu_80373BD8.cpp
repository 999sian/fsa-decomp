#include "Game/Actor.h"
#define Vec SDKVec
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#undef Vec


extern "C" u8 fn_8023077C();
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" void fn_80230498(s32, const JGeometry::TVec3f&, s32, s32, s32, s32, s32);
extern "C" void fn_80230FD0(s32, u32);
extern "C" u8 fn_80230534(s32);
extern "C" const f32 lbl_80542E8C;
extern "C" const s32 lbl_80475070[];
extern "C" char lbl_804AE5C8[];
extern "C" char lbl_804750AC[];
extern "C" f32 lbl_80475060[];
extern "C" const f32 lbl_80542E88;
extern "C" f32 lbl_80542E90;
extern "C" f32 lbl_80542E94;
extern "C" f32 lbl_80542E98;
extern "C" f32 lbl_80542E9C;
extern "C" void fn_801F06F0(Actor* a, const char* tbl, s32 idx, void* rec, s32 p5, f32 sx, f32 sy);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80373BD8(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AE5C8;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_80373C38(Actor* this_) {
    u8* p = (u8*)this_;
    s32 i;
    s32 state = *(s32*)(p + 0x24c);
    if (state < 0) return;
    if (state < 4) {
        if (!fn_8023077C()) return;
        *(s32*)(p + 0x24c) = 4;
        *(s32*)(p + 0x248) = 0x32;
        *(s32*)(p + 0x250) = 0;
        for (i = 0; i < 4; i++) {
            JGeometry::TVec3f pos = *fn_8023E724(i);
            fn_80230498(i, pos + JGeometry::TVec3f(lbl_80542E88, lbl_80542E8C, lbl_80542E88), 0x2e2, 0xff, -0x80, -0x80, 1);
        }
        return;
    }
    if (*(s32*)(p + 0x250) == 0 && *(s32*)(p + 0x248) > 0x1e) {
        for (i = 0; i < 4; i++) {
            JGeometry::TVec3f v = *fn_8023E724(i);
            fn_80230498(i, v, 0x2e2, 0xff, -0x80, -0x80, 1);
        }
        return;
    }
    if (*(s32*)(p + 0x250) < 0xd) {
        if (*(s32*)(p + 0x248) == 0) {
            *(s32*)(p + 0x250) += 1;
            *(s32*)(p + 0x248) = lbl_80475070[*(s32*)(p + 0x250)];
            for (i = 0; i < 4; i++) {
                JGeometry::TVec3f v = *fn_8023E724(i);
                fn_80230498(i, v, *(s32*)(p + 0x250) + 0xdb, 0xff, -0x80, -0x80, 1);
                if (*(s32*)(p + 0x250) == 1) fn_80230FD0(i, 0x10001);
            }
            if (*(s32*)(p + 0x250) == 0xd) *(s32*)(p + 0x248) = 0x19;
        }
    } else {
        if (*(s32*)(p + 0x248) == 0 && fn_80230534(0)) {
            *(s32*)(p + 0x24c) = -1;
            this_->v10(0xff, 1);
        }
    }
}

extern "C" void fn_80373EC8(Actor* p) {
    f32 period = lbl_80542E90;
    JGeometry::TVec3f saved = *(JGeometry::TVec3f*)((u8*)p + 0xc);
    f32 angle = *(f32*)((u8*)p + 0x244);
    f32 rem = angle - period * (f32)(s32)(angle / period);
    s32 idx;
    if (rem < lbl_80542E94) {
        idx = 0;
    } else if (rem < lbl_80542E98) {
        idx = 1;
    } else if (rem < lbl_80542E9C) {
        idx = 2;
    } else {
        idx = 3;
    }
    f32 step = lbl_80475060[idx];
    p->field_0C.y -= angle;
    p->field_0C.y += step;
    fn_801F06F0(p, lbl_804750AC, *(s32*)((u8*)p + 0x23c) + 0x469, 0, -1, lbl_80542E94, lbl_80542E94);
    if (idx == 0) {
        *(JGeometry::TVec3f*)((u8*)p + 0xc) = saved;
    } else {
        JGeometry::TVec3f off;
        off.x = lbl_80542E88;
        off.y = *(f32*)((u8*)p + 0x244);
        off.z = lbl_80542E88;
        *(JGeometry::TVec3f*)((u8*)p + 0xc) = saved - off;
        fn_801F06F0(p, lbl_804750AC, idx + 0x469, 0, -1, lbl_80542E94, lbl_80542E94);
        *(JGeometry::TVec3f*)((u8*)p + 0xc) = saved;
    }
}

extern "C" const f32 lbl_80542E8C;
extern "C" const s32 lbl_80475070[];
extern "C" void fn_80230FD0(s32, u32);
extern "C" u8 fn_80230534(s32);
extern "C" void fn_80373C38(Actor*);
extern "C" s32 fn_80239470(void*, s32, s32);
extern "C" s32 fn_80238A68(s32);
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" void fn_8023DFF4(s32, void*);
extern "C" void fn_80239914(void*, s32, s32);
extern "C" void fn_801F0E34(void*, s32, s32);
extern "C" u8 fn_8023077C();
extern "C" void fn_80230498(s32, const JGeometry::TVec3f&, s32, s32, s32, s32, s32);
extern "C" void fn_80374074(Actor* p) {
    f32 old = *(f32*)((u8*)p + 0x244);
    f32 period = 10.0f;
    f32 rem = old - period * (f32)(s32)(old / period);
    p->field_3C.x = 0.0f;
    p->field_3C.y = 0.0f;
    p->field_3C.z = 0.0f;
    if (*(s32*)((u8*)p + 0x248) > 0) --*(s32*)((u8*)p + 0x248);
    fn_80373C38(p);
    JGeometry::TBox2f box = *(JGeometry::TBox2f*)((u8*)p + 0x60);
    JGeometry::TVec3f pos;
    box.addPos(*(JGeometry::TVec2f*)((u8*)p + 0xc));
    s32 idx;
    s32 count = 0;
    idx = fn_80239470(&box, p->field_04, *(s32*)((u8*)p + 0x198));
    if (idx >= 0) count = fn_80238A68(*(s32*)((u8*)p + 0x198));
    if (count >= 4) {
        f32 dx = p->field_0C.x - fn_8023E724(idx)->x;
        if (__fabsf(dx) >= 2.0f) {
            JGeometry::TVec3f off(dx, 0.0f, 0.0f);
            fn_8023DFF4(idx, &off);
        }
        fn_80239914(&box, p->field_04, *(s32*)((u8*)p + 0x198));
        if (*(f32*)((u8*)p + 0x244) >= 36.0f) {
            *(f32*)((u8*)p + 0x244) += 0.5f;
            if (*(f32*)((u8*)p + 0x244) >= 40.0f) {
                *(f32*)((u8*)p + 0x244) = 40.0f;
                if (*(u8*)((u8*)p + 0x254) == 0) {
                    *(u8*)((u8*)p + 0x240) = 1;
                    fn_801F0E34(p, 0x3004b, 0);
                    p->field_0C.y = p->field_24.y + *(f32*)((u8*)p + 0x244);
                    *(u8*)((u8*)p + 0x254) = 1;
                    if (fn_8023077C()) {
                        *(s32*)((u8*)p + 0x248) = 50;
                        *(s32*)((u8*)p + 0x24c) = 4;
                        *(s32*)((u8*)p + 0x250) = 0;
                        for (s32 i = 0; i < 4; ++i) {
                            pos = *fn_8023E724(i);
                            fn_80230498(i, pos + JGeometry::TVec3f(0.0f, 7.0f, 0.0f), 0x2e2, 0xff, -0x80, -0x80, 1);
                        }
                    } else *(s32*)((u8*)p + 0x24c) = 0;
                }
            }
        } else {
            if (*(f32*)((u8*)p + 0x244) <= 0.0f) {
                *(JGeometry::TVec3f*)((u8*)p + 0x230) = *(JGeometry::TVec3f*)((u8*)p + 0xc);
                *(f32*)((u8*)p + 0x234) += 16.0f;
            }
            if (rem < 2.0f) {
                *(f32*)((u8*)p + 0x244) += 0.03f;
                if (rem >= 1.97f) fn_801F0E34(p, 0x5007a, 0);
            } else *(f32*)((u8*)p + 0x244) += 0.5f;
        }
    } else {
        if (*(u8*)((u8*)p + 0x240) && *(s32*)((u8*)p + 0x248) > 0) {
            *(f32*)((u8*)p + 0x244) = 40.0f;
        } else {
            *(f32*)((u8*)p + 0x244) -= 1.25f;
            if (*(f32*)((u8*)p + 0x244) < 0.0f) *(f32*)((u8*)p + 0x244) = 0.0f;
            else fn_801F0E34(p, 0x5007b, 0);
        }
    }
    f32 delta = *(f32*)((u8*)p + 0x244) - old;
    p->field_3C.x = 0.0f;
    p->field_3C.y = delta;
    p->field_3C.z = 0.0f;
    p->field_0C.y = p->field_24.y + *(f32*)((u8*)p + 0x244);
    f32 height = *(f32*)((u8*)p + 0x244);
    if (height < 10.0f) *(s32*)((u8*)p + 0x23c) = 0;
    else if (height < 20.0f) *(s32*)((u8*)p + 0x23c) = 4;
    else if (height < 30.0f) *(s32*)((u8*)p + 0x23c) = 5;
    else if (height < 40.0f) *(s32*)((u8*)p + 0x23c) = 6;
    else *(s32*)((u8*)p + 0x23c) = 7;
}

extern "C" const f32 lbl_80542ED0;
extern "C" const f32 lbl_80542ED4;
extern "C" const f32 lbl_80542E88;
#pragma optimization_level 3
extern "C" void fn_803744C4(u8* p) {
    *(f32*)(p + 0x60) = lbl_80542ED0;
    *(f32*)(p + 0x64) = lbl_80542ED0;
    *(f32*)(p + 0x68) = lbl_80542ED4;
    *(f32*)(p + 0x6c) = lbl_80542ED4;
    *(f32*)(p + 0x80) = lbl_80542E88;
    *(f32*)(p + 0x84) = lbl_80542E88;
    *(f32*)(p + 0x88) = lbl_80542E88;
    *(f32*)(p + 0x8c) = lbl_80542E88;
    *(s32*)(p + 0x108) = 0;
    *(s32*)(p + 0x23c) = 0;
    u32 r = ((Actor*)p)->v11();
    p[0x254] = r;
    p[0x240] = r;
    *(f32*)(p + 0x244) = lbl_80542E88;
    *(f32*)(p + 0x3c) = lbl_80542E88;
    *(f32*)(p + 0x40) = lbl_80542E88;
    *(f32*)(p + 0x44) = lbl_80542E88;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = -1;
    *(s32*)(p + 0x250) = 0;
}
#pragma optimization_level 4
extern "C" void fn_80374564(void) {
}

