#include "Game/Actor.h"
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
extern "C" const u8 lbl_80540E28[];
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
            f32 sx = *(f32*)(this_ + 0x24c);
            f32 sy = *(f32*)(this_ + 0x250);
            f32 sz = *(f32*)(this_ + 0x254);
            f32* tbl = (f32*)sincosTable___5JMath;
            f32 s0 = tbl[0];
            f32 s = *(f32*)((char*)tbl + (((u16)ang >> 5) * 8));
            f32 c0 = tbl[1];
            f32 c = *(f32*)((char*)tbl + (((u16)ang >> 5) * 8) + 4);
            rec.w18 = mtx;
            mtx[0][0] = sx * (c * c0);
            mtx[0][1] = sy * ((s0 * s) * c0 - c0 * s0);
            mtx[0][2] = sz * ((c0 * c0) * s + s0 * s0);
            mtx[1][0] = sx * (c * s0);
            mtx[1][1] = sy * ((s0 * s) * s0 + c0 * c0);
            mtx[1][2] = sz * ((c0 * s0) * s - c0 * s0);
            mtx[2][0] = sx * -s;
            mtx[2][1] = sy * (c * s0);
            mtx[2][2] = sz * (c * c0);
        } else if (*(s32*)(this_ + 0x234) == 0x15) {
            rec.b2d = 1;
        } else {
            rec.b21 = 1;
            rec.b23 = 1;
        }

        if (*(s32*)(this_ + 0x234) == 0x22) {
            if ((u8)((Actor*)this_)->v11() == 1) {
                tex = fn_804032E8(0x54494d47, base + 0x608);
            } else {
                tex = fn_804032E8(0x54494d47, ids[*(s32*)(this_ + 0x234)]);
            }
            fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
        } else {
            tex = fn_804032E8(0x54494d47, ids[*(s32*)(this_ + 0x234)]);
            fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
            new (&rec) DrawRec();
            rec.b1c = lbl_80540E28[*(s32*)(this_ + 0x238)] + 1;
            rec.b1d = lbl_80540E28[*(s32*)(this_ + 0x23c)];
            switch (*(s32*)(this_ + 0x234)) {
            case 0:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
                rec.w34 = 1;
                rec.w10 = -0x6a;
                rec.b2c = 0;
                rec.b24 = 0;
                tex = fn_804032E8(0x54494d47, ids[*(s32*)(this_ + 0x234) + 0x51]);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
                break;
            case 0x15:
                rec.b2d = 1;
                tex = fn_804032E8(0x54494d47, base + 0x61c);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
                break;
            case 0x31:
                tex = fn_804032E8(0x54494d47, base + 0x628);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
                break;
            case 0x33:
                rec.b24 = 1;
                tex = fn_804032E8(0x54494d47, base + 0x634);
                v.x = *(f32*)(this_ + 0xc);
                v.y = *(f32*)(this_ + 0x10) - lbl_80540E30;
                v.z = lbl_80540E34;
                fn_802CDD9C_draw(this_, &v, tex, &rec);
                break;
            case 0x34:
                tex = fn_804032E8(0x54494d47, base + 0x644);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
                break;
            case 0x37:
            case 0x38:
            case 0x39:
                rec.b2c = 0;
                rec.b24 = 1;
                tex = fn_804032E8(0x54494d47, ids[*(s32*)(this_ + 0x234) + 0x29]);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
                break;
            case 0x3e:
                tex = fn_804032E8(0x54494d47, base + 0x658);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
                break;
            case 0x42:
                rec.b24 = 1;
                tex = fn_804032E8(0x54494d47, base + 0x670);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
                break;
            case 0x43:
                rec.b24 = 1;
                tex = fn_804032E8(0x54494d47, base + 0x684);
                fn_802CDD9C_draw(this_, this_ + 0xc, tex, &rec);
                break;
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

