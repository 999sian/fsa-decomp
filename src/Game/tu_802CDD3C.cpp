#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "Game/ItemBase.h"


extern "C" char lbl_804A927C[];
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};
extern "C" const f32 lbl_80540E40;
extern "C" const f32 lbl_80540E44;
extern "C" const f32 lbl_80540E34;
extern "C" const f32 lbl_80540E38;
extern "C" const f32 lbl_80540E3C;
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" u32 fn_804032E8(u32 tag, void* id);
extern "C" void fn_802F745C(void* mgr, void* pos, u32 tex, void* rec);
extern "C" void PSMTXIdentity(f32 (*m)[4]);
extern "C" u8 lbl_80540E28[8];
extern "C" void* lbl_804A90F0[];
extern "C" char lbl_8046D920[];
extern "C" char* lbl_8053AB10;
extern "C" char sincosTable___5JMath[];
extern "C" const f32 lbl_80540E30;

static inline void fn_802CDD9C_draw(char* this_, void* pos, u32 tex, void* rec)
{
    if ((s32)(*(u32*)(this_ + 0x4) + *(u8*)(this_ + 0x259)) < 8) {
        fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), pos, tex, rec);
    }
}

extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802CDD3C(Actor* p, s16 n)
{
    if (p != NULL) {
        *(void**)p = lbl_804A927C;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

struct CddDrawTables {
    void* main[0x51];
    void* extra[0xf];
    void* tail[3];
};
static inline void cddResetDrawRec(DrawRec& rec) {
        for (u32 i = 0; (u8)i < 0x10; i += 8) {
            rec.ids[(u8)i] = i;
            rec.ids[(u8)(i + 1)] = i + 1;
            rec.ids[(u8)(i + 2)] = i + 2;
            rec.ids[(u8)(i + 3)] = i + 3;
            rec.ids[(u8)(i + 4)] = i + 4;
            rec.ids[(u8)(i + 5)] = i + 5;
            rec.ids[(u8)(i + 6)] = i + 6;
            rec.ids[(u8)(i + 7)] = i + 7;
        }
        rec.w10 = -1;
        rec.w14 = 0;
        rec.w18 = 0;
        rec.b1c = 0;
        rec.b1d = 0;
        rec.b1e = 0;
        rec.b1f = 1;
        rec.b20 = 1;
        rec.b21 = 0;
        rec.b22 = 0;
        rec.b23 = 0;
        rec.b24 = 0;
        rec.b25 = 0;
        rec.b26 = 1;
        rec.w28 = 3;
        rec.b2c = 1;
        rec.b2d = 0;
        rec.b2e = 0;
        rec.w30 = -1;
        rec.w34 = 0;
        rec.w38 = 2;
}
static inline void cddRotation(f32 m[3][4], const s16 rx, const s16 ry, const s16 rz, const f32* scale) {
    f32 cz, cy, cx, sz, sy, sx;
    sx = JMASinShort(rx);
    sy = JMASinShort(ry);
    sz = JMASinShort(rz);
    cx = JMACosShort(rx);
    cy = JMACosShort(ry);
    cz = JMACosShort(rz);
    f32 cycz = cy * cz;
    f32 cysz = cy * sz;
    f32 sxcy = sx * cy;
    f32 sxsy = sx * sy;
    f32 cxcz = cx * cz;
    f32 cxsz = cx * sz;
    f32 sxsz = sx * sz;
    f32 sxcz = sx * cz;
    f32 s0 = scale[0];
    f32 s1 = scale[1];
    f32 s2 = scale[2];
    m[0][0] = s0 * cycz;
    m[1][0] = s0 * cysz;
    m[2][0] = s0 * -sy;
    m[0][1] = s1 * (sxsy * cz - cxsz);
    m[1][1] = s1 * (sxsy * sz + cxcz);
    m[2][1] = s1 * sxcy;
    m[0][2] = s2 * (cxcz * sy + sxsz);
    m[1][2] = s2 * (cxsz * sy - sxcz);
    m[2][2] = s2 * (cx * cy);
}

extern "C" void fn_802CDD9C(char* this_)
{
    Vec v;
    f32 mtx[3][4];
    u32 tex;
    void** ids = lbl_804A90F0;
    char* base = lbl_8046D920;

    if (*(s32*)(this_ + 0x230) == 1) {
        DrawRec rec;
        rec.b1c = lbl_80540E28[*(s32*)(this_ + 0x238)];
        rec.b1d = lbl_80540E28[*(s32*)(this_ + 0x23c)];
        rec.b24 = 1;
        if (*(s32*)(this_ + 0x234) >= 0x1b && *(s32*)(this_ + 0x234) <= 0x1e) {
            PSMTXIdentity(mtx);
            s16 ang = *(s16*)(this_ + 0x248);
            cddRotation(mtx, 0, ang, 0, (const f32*)(this_ + 0x24c));
            rec.w18 = mtx;
        } else if (*(s32*)(this_ + 0x234) == 0x15) {
            rec.b2d = 1;
        } else {
            rec.b21 = 1;
            rec.b23 = 1;
        }

        if (*(s32*)(this_ + 0x234) == 0x22) {
            if ((u8)((Actor*)this_)->v11() == 1) {
                tex = fn_804032E8(0x54494d47, base + 0x608);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
                return;
            } else {
                tex = fn_804032E8(0x54494d47, ids[*(s32*)(this_ + 0x234)]);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
                return;
            }
        } else {
            s32 t;
            tex = fn_804032E8(0x54494d47, ids[*(s32*)(this_ + 0x234)]);
            fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
            cddResetDrawRec(rec);
            rec.b1c = lbl_80540E28[*(s32*)(this_ + 0x238)] + 1;
            rec.b1d = lbl_80540E28[*(s32*)(this_ + 0x23c)];
            t = *(s32*)(this_ + 0x234);
            if (t == 0 || (t >= 8 && t <= 14)) {
                rec.w34 = 1;
                ((u8*)&rec.w10)[3] = 0x96;
                rec.b2c = 0;
                rec.b24 = 0;
                tex = fn_804032E8(0x54494d47, ((void**)((char*)ids + 0x144))[*(s32*)(this_ + 0x234)]);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
            } else if (t == 0x15) {
                rec.b2d = 1;
                tex = fn_804032E8(0x54494d47, base + 0x61c);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
            } else if (t == 0x31) {
                tex = fn_804032E8(0x54494d47, base + 0x628);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
            } else if (t == 0x33) {
                rec.b24 = 1;
                tex = fn_804032E8(0x54494d47, base + 0x634);
                f32 y = *(f32*)(this_ + 0x10) - lbl_80540E30;
                v.x = *(f32*)(this_ + 0xc);
                v.y = y;
                v.z = lbl_80540E34;
                fn_802CDD9C_draw(this_, &v, tex, &rec);
            } else if (t == 0x34) {
                tex = fn_804032E8(0x54494d47, base + 0x644);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
            } else if (t >= 0x37 && t <= 0x39) {
                rec.b2c = 0;
                rec.b24 = 1;
                tex = fn_804032E8(0x54494d47, ((void**)((char*)ids + 0x180))[*(s32*)(this_ + 0x234) - 0x37]);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
            } else if (t == 0x3e) {
                tex = fn_804032E8(0x54494d47, base + 0x658);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
            } else if (t == 0x42) {
                rec.b24 = 1;
                tex = fn_804032E8(0x54494d47, base + 0x670);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
            } else if (t == 0x43) {
                rec.b24 = 1;
                tex = fn_804032E8(0x54494d47, base + 0x684);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
            }
        }
    }
}

static inline void fn_802CE508_spawn(char* this_);
extern "C" void fn_802CE508(char* this_) {
    Vec v;
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        if ((*(u32*)(this_ + 0x90) >> 27) == 0 || (u8)((Actor*)this_)->v11() == 1) {
            if (*(u8*)(this_ + 0x258)) {
                if (*(s32*)(this_ + 0x4) >= 8) {
                    v.x = lbl_80540E38 + *(f32*)(this_ + 0xc);
                    v.y = lbl_80540E38 + *(f32*)(this_ + 0x10);
                    v.z = lbl_80540E34;
                    Actor_CreateByID(fn_801F856C(), 0x4b4d5249, *(u32*)(this_ + 0x4) + *(u8*)(this_ + 0x259), &v, 0, -1, -1);
                } else {
                    fn_8013CC50(*(u32*)(this_ + 0x4) + *(u8*)(this_ + 0x259), this_ + 0xc, lbl_80540E3C, 0x564, 0, 0, 0, 0, 1);
                    fn_8013CC50(*(u32*)(this_ + 0x4) + *(u8*)(this_ + 0x259), this_ + 0xc, lbl_80540E40, 0x503, 1, 0, 0, 0, 1);
                }
                fn_801F0E34(this_, 0x30003, 0);
            }
            *(s32*)(this_ + 0x230) = 1;
        }
        break;
    case 1:
        if ((*(s32*)(this_ + 0x240) == 2 || *(s32*)(this_ + 0x240) == 3) && !(u8)((Actor*)this_)->v11()) {
            if (*(u8*)(this_ + 0x258)) {
                if (*(s32*)(this_ + 0x4) >= 8) {
                    v.x = lbl_80540E38 + *(f32*)(this_ + 0xc);
                    v.y = lbl_80540E38 + *(f32*)(this_ + 0x10);
                    v.z = lbl_80540E34;
                    Actor_CreateByID(fn_801F856C(), 0x4b4d5249, *(u32*)(this_ + 0x4) + *(u8*)(this_ + 0x259), &v, 0, -1, -1);
                } else {
                    fn_8013CC50(*(u32*)(this_ + 0x4) + *(u8*)(this_ + 0x259), this_ + 0xc, lbl_80540E3C, 0x564, 0, 0, 0, 0, 1);
                    fn_8013CC50(*(u32*)(this_ + 0x4) + *(u8*)(this_ + 0x259), this_ + 0xc, lbl_80540E40, 0x503, 1, 0, 0, 0, 1);
                }
                fn_801F0E34(this_, 0x30003, 0);
            }
            *(s32*)(this_ + 0x230) = 0;
        } else if (*(s32*)(this_ + 0x240) == 4 && (u8)((Actor*)this_)->v11() == 1) {
            *(s32*)(this_ + 0x230) = 2;
        }
        break;
    }
}

extern "C" void fn_802CE7A8(char* p) {
    f32 f;
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 0xfff;
    *(u32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 12) & 0xf;
    *(u32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 16) & 0xf;
    *(u32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 20) & 0xf;
    *(u32*)(p + 0x244) = (*(u32*)(p + 0x90) >> 25) & 1;
    if (*(s32*)(p + 0x244) != 0) {
        *(u8*)(p + 0x259) = 1;
    } else {
        *(u8*)(p + 0x259) = 0;
    }
    if (*(u32*)(p + 0x90) & 0x4000000) {
        *(u8*)(p + 0x258) = 1;
    } else {
        *(u8*)(p + 0x258) = 0;
    }
    if (*(s32*)(p + 0x240) == 0 || *(s32*)(p + 0x240) == 2 || *(s32*)(p + 0x240) == 4) {
        *(s32*)(p + 0x230) = 1;
    } else {
        *(s32*)(p + 0x230) = 0;
    }
    f = lbl_80540E40;
    *(f32*)(p + 0x24c) = f;
    *(f32*)(p + 0x250) = f;
    *(f32*)(p + 0x254) = f;
    *(s16*)(p + 0x248) = 0;
    if (*(s32*)(p + 0x234) == 0x1b) {
        f = lbl_80540E44;
        *(f32*)(p + 0x24c) = f;
        *(f32*)(p + 0x250) = f;
        *(f32*)(p + 0x254) = f;
        *(s16*)(p + 0x248) = 0x4000;
    } else if (*(s32*)(p + 0x234) == 0x1c) {
        f = lbl_80540E44;
        *(f32*)(p + 0x24c) = f;
        *(f32*)(p + 0x250) = f;
        *(f32*)(p + 0x254) = f;
        *(s16*)(p + 0x248) = -0x4000;
    } else if (*(s32*)(p + 0x234) == 0x1d) {
        f = lbl_80540E44;
        *(f32*)(p + 0x24c) = f;
        *(f32*)(p + 0x250) = f;
        *(f32*)(p + 0x254) = f;
        *(s16*)(p + 0x248) = -0x8000;
    } else if (*(s32*)(p + 0x234) == 0x1e) {
        f = lbl_80540E44;
        *(f32*)(p + 0x24c) = f;
        *(f32*)(p + 0x250) = f;
        *(f32*)(p + 0x254) = f;
        *(s16*)(p + 0x248) = 0;
    }
    ((ActorSlot5*)p)->slot5();
    *(u8*)(p + 0x11f) = 1;
}

void fn_802CE93C(void) {}

