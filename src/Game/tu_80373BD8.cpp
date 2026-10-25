#include "Game/Actor.h"
#define Vec SDKVec
#include "JSystem/JGeometry/Box.h"
#undef Vec


extern "C" char lbl_804AE5C8[];
extern "C" char lbl_804750AC[];
extern "C" f32 lbl_80475060[];
extern "C" f32 lbl_80542E88;
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

extern "C" void fn_80373EC8(Actor* p) {
    Vec saved = p->field_0C;
    f32 angle = *(f32*)((u8*)p + 0x244);
    f32 period = lbl_80542E90;
    f32 q = (f32)(s32)(angle / period);
    f32 rem = angle - period * q;
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
    p->field_0C.y -= angle;
    p->field_0C.y += lbl_80475060[idx];
    fn_801F06F0(p, lbl_804750AC, *(s32*)((u8*)p + 0x23c) + 0x469, 0, -1, lbl_80542E94, lbl_80542E94);
    if (idx == 0) {
        p->field_0C = saved;
    } else {
        Vec off;
        off.x = lbl_80542E88;
        off.y = *(f32*)((u8*)p + 0x244);
        off.z = lbl_80542E88;
        p->field_0C.x = saved.x - off.x;
        p->field_0C.y = saved.y - off.y;
        p->field_0C.z = saved.z - off.z;
        fn_801F06F0(p, lbl_804750AC, idx + 0x469, 0, -1, lbl_80542E94, lbl_80542E94);
        p->field_0C = saved;
    }
}

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
    p->field_3C.x = p->field_3C.y = p->field_3C.z = 0.0f;
    if (*(s32*)((u8*)p + 0x248) > 0) --*(s32*)((u8*)p + 0x248);
    fn_80373C38(p);
    JGeometry::TBox2f box = *(JGeometry::TBox2f*)((u8*)p + 0x60);
    box.addPos(*(JGeometry::TVec2f*)((u8*)p + 0xc));
    s32 count = 0;
    s32 idx = fn_80239470(&box, p->field_04, *(s32*)((u8*)p + 0x198));
    if (idx >= 0) count = fn_80238A68(*(s32*)((u8*)p + 0x198));
    if (count >= 4) {
        f32 dx = p->field_0C.x - fn_8023E724(idx)->x;
        if (__fabs(dx) >= 2.0f) {
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
                            JGeometry::TVec3f pos = *fn_8023E724(i);
                            JGeometry::TVec3f off(0.0f, 7.0f, 0.0f);
                            JGeometry::TVec3f sum = pos + off;
                            fn_80230498(i, sum, 0x2e2, 0xff, -0x80, -0x80, 1);
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
    p->field_3C.x = 0.0f;
    p->field_3C.y = *(f32*)((u8*)p + 0x244) - old;
    p->field_3C.z = 0.0f;
    p->field_0C.y = p->field_24.y + *(f32*)((u8*)p + 0x244);
    f32 height = *(f32*)((u8*)p + 0x244);
    if (height < 10.0f) *(s32*)((u8*)p + 0x23c) = 0;
    else if (height < 20.0f) *(s32*)((u8*)p + 0x23c) = 4;
    else if (height < 30.0f) *(s32*)((u8*)p + 0x23c) = 5;
    else if (height < 40.0f) *(s32*)((u8*)p + 0x23c) = 6;
    else *(s32*)((u8*)p + 0x23c) = 7;
}

extern "C" f32 lbl_80542ED0;
extern "C" f32 lbl_80542ED4;
extern "C" f32 lbl_80542E88;
extern "C" void fn_803744C4(u8* p) {
    f32 a = lbl_80542ED0;
    f32 b = lbl_80542ED4;
    f32 z = lbl_80542E88;
    *(f32*)(p + 0x60) = a;
    *(f32*)(p + 0x64) = a;
    *(f32*)(p + 0x68) = b;
    *(f32*)(p + 0x6c) = b;
    *(f32*)(p + 0x80) = z;
    *(f32*)(p + 0x84) = z;
    *(f32*)(p + 0x88) = z;
    *(f32*)(p + 0x8c) = z;
    *(s32*)(p + 0x108) = 0;
    *(s32*)(p + 0x23c) = 0;
    u8 r = (*(u8 (**)(u8*))(*(u8**)p + 0x34))(p);
    p[0x254] = r;
    p[0x240] = r;
    z = lbl_80542E88;
    *(f32*)(p + 0x244) = z;
    *(f32*)(p + 0x3c) = z;
    *(f32*)(p + 0x40) = z;
    *(f32*)(p + 0x44) = z;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = -1;
    *(s32*)(p + 0x250) = 0;
}

extern "C" void fn_80374564(void) {
}

