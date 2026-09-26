// Game TU 801BDE5C-801BEDBC (BMST). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Box.h"

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A40E0[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_801BDE5C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A40E0;
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801BEB44(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A40E0;
    *(s16*)((char*)this_ + 0x2a8) = 0;
    *(s16*)((char*)this_ + 0x2aa) = 0;
    *(u8*)((char*)this_ + 0x2ac) = 0;
    *(s32*)((char*)this_ + 0x2b0) = 0;
    *(s32*)((char*)this_ + 0x2b4) = 0;
    return this_;
}

extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void v07__5ActorFv(void* this_);

extern "C" void fn_801BE0F4(char* this_) {
    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x70, 0, 0, 0, 0, 1, 1.0f);
    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x71, 0, 0, 0, 0, 1, 1.0f);
    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x72, 0, 0, 0, 0, 1, 1.0f);
    v07__5ActorFv(this_);
}

struct BmstVec2 { f32 x, y; };
extern "C" s32 fn_801F285C(void* actor, s32 a, s32 b, s32 c, s32 idx);
extern "C" void fn_8023B6CC(s32 idx);
extern "C" u8 fn_8023E854(s32 idx);
extern "C" void fn_801F3128(void* actor, BmstVec2* out);
extern "C" u8 fn_80238548(s32 idx, s32 a, BmstVec2* v, s32 d);
extern "C" void fn_801F0E34(void* actor, u32 msg, s32 arg);
extern "C" u8 fn_801CEBD0(void* actor);

extern "C" u8 fn_801BE19C(char* this_) {
    u8 hit = 0;
    if (*(s32*)(this_ + 0x248) == 2) {
        for (s32 i = 0; i < 4; i++) {
            if (i == fn_801F285C(this_, 0, 0, 1, i)) {
                fn_8023B6CC(i);
                if (!fn_8023E854(i)) {
                    BmstVec2 v;
                    fn_801F3128(this_, &v);
                    if (fn_80238548(i, *(s32*)(this_ + 0x114), &v, 10)) {
                        hit = 1;
                    }
                }
            }
        }
        if (hit) {
            fn_801F0E34(this_, 0x4000c, 0);
        }
    } else {
        hit = fn_801CEBD0(this_);
    }
    return hit;
}

extern "C" void fn_801F2DB4(void* actor, u32 a, u32 b, u32 c);

extern "C" void fn_801BE284(char* this_) {
    fn_801F2DB4(this_, *(u16*)(this_ + 0x2aa) != 0 ? 'NULL' : *(u32*)(this_ + 0x1a0), 'SWBM', 0);
}

extern "C" void fn_801BE2CC(void) {}

typedef JGeometry::TBox2<f32> BmstRect;
extern "C" void fn_801CE2BC(void* this_);
inline void bmstBox(BmstRect* b, char* this_) {
    JGeometry::TVec2<f32>& p = *(JGeometry::TVec2<f32>*)(this_ + 0xc);
    f32 r = 8.0f;
    b->set(p.x - r, p.y - r, p.x + r, p.y + r);
}
extern "C" void fn_80239914(BmstRect* box, u32 room, u32 id);
extern "C" u8* fn_8020D58C(void);
extern "C" void fn_8020D8C0(void* mgr, BmstRect* box, u32 room, u32 id);

extern "C" void fn_801BE2D0(char* this_) {
    fn_801CE2BC(this_);
    if (*(u16*)(this_ + 0x2aa) != 0) {
        *(u16*)(this_ + 0x2aa) = *(u16*)(this_ + 0x2aa) - 1;
    }
    BmstRect box2;
    BmstRect box;
    bmstBox(&box, this_);
    fn_80239914(&box, *(u32*)(this_ + 4), *(u32*)(this_ + 0x198));
    if (*(u16*)(this_ + 0x2aa) == 0) {
        bmstBox(&box2, this_);
        u32 id = *(u32*)(this_ + 0x198);
        u32 room = *(u32*)(this_ + 4);
        u8* m = fn_8020D58C();
        fn_8020D8C0(m + m[0] * 0x784 + 4, &box2, room, id);
    }
}

extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_801BE86C(char* this_);

extern "C" void fn_801BE6C4(char* this_, s32 state) {
    switch (state) {
    case 0:
        *(s32*)(this_ + 0x250) = fn_801CD664(1) + 90;
        break;
    case 2: {
        s16 a = *(s16*)(this_ + 0x2a8);
        f32 c = JMASCos(a);
        JGeometry::TVec3<f32> pos(10.0f * JMASSin(a) + *(f32*)(this_ + 0xc),
                                  -15.0f + (6.0f * c + *(f32*)(this_ + 0x10)),
                                  *(f32*)(this_ + 0x14));
        BOOL flag = FALSE;
        if (pos.y >= -15.0f + *(f32*)(this_ + 0x10)) {
            flag = 1;
        }
        fn_8013CC50(*(u32*)(this_ + 4), &pos, 0x1c, 0, flag, 0, 0, 1, 1.0f);
        fn_8013CC50(*(u32*)(this_ + 4), &pos, 0x1d, 0, flag, 0, 0, 1, 1.0f);
        fn_801F0E34(this_, 0x30062, 0);
        *(u16*)(this_ + 0x2aa) = 60;
        break;
    }
    case 3:
        *(s32*)(this_ + 0x250) = fn_801CD664(1) + 90;
        fn_801BE86C(this_);
        fn_801F0E34(this_, 0x30063, 0);
        break;
    }
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x248) = state;
    if (*(u16*)(this_ + 0x2aa) != 0) {
        *(u32*)(this_ + 0xb0) = 0x40002;
    } else {
        *(u32*)(this_ + 0xb0) = 0x40004;
    }
}

extern "C" void fn_801D0ED0(void* this_);

extern "C" void fn_801BEA08(char* this_) {
    fn_801D0ED0(this_);
    u8 n = *(u32*)(this_ + 0x90);
    if (n > 15) {
        n = 15;
    } else if (n < 1) {
        n = 1;
    }
    *(u8*)(this_ + 0x2ac) = n;
    *(u32*)(this_ + 0x2b0) = (*(u32*)(this_ + 0x90) >> 22) & 0x1f;
    *(u32*)(this_ + 0x2b4) = *(u32*)(this_ + 0x90) >> 27;
    if (*(s32*)(this_ + 0x2b0) != 0) {
        *(u32*)(this_ + 0x230) |= 0x2000;
    }
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -16.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(f32*)(this_ + 0x70) = -8.0f;
    *(f32*)(this_ + 0x74) = -20.0f;
    *(f32*)(this_ + 0x78) = 8.0f;
    *(f32*)(this_ + 0x7c) = 8.0f;
    *(f32*)(this_ + 0x80) = 1.0f;
    *(f32*)(this_ + 0x84) = 1.0f;
    *(f32*)(this_ + 0x88) = -1.0f;
    *(f32*)(this_ + 0x8c) = -1.0f;
    *(s32*)(this_ + 0x98) = 2;
    *(u32*)(this_ + 0x230) |= 0x180;
    *(s16*)(this_ + 0x2a8) = fn_801CD664(0x10000);
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = fn_801CD664(1) + 90;
    *(f32*)(this_ + 0x254) = 0.0f;
    *(f32*)(this_ + 0x258) = 0.0f;
    if (*(u16*)(this_ + 0x2aa) != 0) {
        *(u32*)(this_ + 0xb0) = 0x40002;
    } else {
        *(u32*)(this_ + 0xb0) = 0x40004;
    }
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 id);
extern "C" s32 Actor_CreateByID(void* mgr, u32 fourCC, u32 owner, void* pos, u32 param, s32 p6, s32 p7);

#pragma dont_inline on
extern "C" void fn_801BE86C(char* this_) {
    s16 a = *(s16*)(this_ + 0x2a8);
    f32 c = JMASCos(a);
    JGeometry::TVec3<f32> pos(10.0f * JMASSin(a) + *(f32*)(this_ + 0xc),
                              -15.0f + (6.0f * c + *(f32*)(this_ + 0x10)),
                              *(f32*)(this_ + 0x14));
    s32 id = Actor_CreateByID(fn_801F856C(), 'LNBM', *(u32*)(this_ + 4), &pos, *(u32*)(this_ + 0x198), -1, -1);
    if (id >= 0) {
        char* actor = (char*)fn_801F666C(fn_801F856C(), id);
        if (actor != 0) {
            BOOL flag = FALSE;
            if (pos.y >= -15.0f + *(f32*)(this_ + 0x10)) {
                flag = TRUE;
            }
            *(s16*)(actor + 0x94) = flag;
            s16 b = *(s16*)(this_ + 0x2a8);
            f32 dc = 6.0f * JMASCos(b);
            JGeometry::TVec2<f32> dir(10.0f * JMASSin(b), dc);
            dir.normalize();
            dir.scale(10.5f);
            JGeometry::TVec3<f32> vel(dir.x, dir.y, 0.0f);
            *(JGeometry::TVec3<f32>*)(actor + 0x3c) = vel;
        }
    }
}
#pragma dont_inline reset

#include "JSystem/JAudio/JASFakeMatchFSA.h"
