// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A908C-801AAC8C (TTAT). Remaining functions are not yet decompiled.
#include "types.h"

extern char* lbl_8053AB10;
extern char* lbl_8053AF80;
extern char* lbl_8053AAF8;
extern s32 lbl_8053ABD0;
extern const f32 lbl_8053E6E0;
extern const f32 lbl_8053E6E8;
extern const f32 lbl_8053E6EC;
extern const f32 lbl_8053E6F0;
extern const f32 lbl_8053E6F4;
extern const f32 lbl_8053E6F8;
extern const f32 lbl_8053E6FC;
extern const f32 lbl_8053E700;

// from src/Game/fn_801A908C.cpp
extern "C" void fn_801A90D4(void* this_);
extern "C" void fn_801A9374(void* this_);

// TTAT (vtable lbl_804A2FB0, ctor fn_80200D10, GOMA's direct neighbor -
// see project_fsa_goma_actor_progress.md) cluster, part 1/9. draw()
// dispatcher - calls 2 sub-pieces (fn_801A90D4/fn_801A9374).
extern "C" void fn_801A908C(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x258);
    if (state == 5) {
        goto piece0;
    }
    if (state >= 5) {
        goto skip;
    }
    if (state == 0) {
        goto piece0;
    }
    if (state >= 0) {
        goto piece1;
    }
    goto skip;
piece0:
    fn_801A90D4(this_);
    goto skip;
piece1:
    fn_801A9374(this_);
skip:
    return;
}

// from src/Game/TtatStateHelper_801AA8F4.cpp
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);

// TTAT cluster, part 9/9. Private helper called from state handler #2
// (fn_801A9CF4) - uses fn_801F0E34 (settings-gated event).
extern "C" void fn_801AA8F4(void* this_) {
    char* t = (char*)this_;
    if (*(s32*)(t + 0x234) != 0) {
        return;
    }

    *(s32*)(t + 0x24c) = *(s32*)(t + 0x25c) + *(s32*)(t + 0x240);

    switch (*(s32*)(t + 0x260)) {
    case 0:
        *(s32*)(t + 0x234) = 6;
        *(s32*)(t + 0x240) = *(s32*)(t + 0x240) + 1;
        *(s32*)(t + 0x240) = *(s32*)(t + 0x240) & 1;
        if (*(s32*)(t + 0x240) != 0) {
            fn_801F0E34(this_, 0x5002c, 0);
        }
        break;
    case 1:
        *(s32*)(t + 0x234) = 5;
        *(s32*)(t + 0x240) = *(s32*)(t + 0x240) + 1;
        if (*(s32*)(t + 0x240) > 3) {
            *(s32*)(t + 0x240) = 3;
            *(u8*)(t + 0x2b0) = 1;
        }
        break;
    case 2:
        *(s32*)(t + 0x234) = 5;
        *(s32*)(t + 0x240) = *(s32*)(t + 0x240) - 1;
        if (*(s32*)(t + 0x240) < 0) {
            *(s32*)(t + 0x240) = 0;
            *(u8*)(t + 0x2b0) = 1;
        }
        break;
    case 3:
        *(s32*)(t + 0x234) = 6;
        *(s32*)(t + 0x240) = *(s32*)(t + 0x240) + 1;
        if (*(s32*)(t + 0x240) > 3) {
            *(s32*)(t + 0x240) = 3;
            *(u8*)(t + 0x2b0) = 1;
        }
        break;
    case 4:
        *(s32*)(t + 0x234) = 6;
        *(s32*)(t + 0x240) = *(s32*)(t + 0x240) - 1;
        if (*(s32*)(t + 0x240) < 0) {
            *(s32*)(t + 0x240) = 0;
            *(u8*)(t + 0x2b0) = 1;
        }
        break;
    default:
        break;
    }
}

extern "C" void fn_801A96B4(void* this_);
extern "C" void fn_801A9CF4(void* this_);
struct TtatTimers { u8 pad[0x234]; s32 t[3]; };

// TTAT update (vtable slot 3)
extern "C" void fn_801A961C(char* this_) {
    switch (*(s32*)(this_ + 0x258)) {
    case 0:
    case 5:
        fn_801A96B4(this_);
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        fn_801A9CF4(this_);
        break;
    }
    for (int i = 0; i < 3; i++) {
        if (((TtatTimers*)this_)->t[i] > 0) {
            ((TtatTimers*)this_)->t[i]--;
        }
    }
}

extern "C" void fn_8030C210(void* a, void* b);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void* fn_8013CC50(u32 id, void* pos, s32 type, s32 p4, s32 p5, u32 p6, u32 p7, u32 p8, f32 f);
extern "C" void fn_8013CB44(void* obj, void* p, s32 a, s32 b, s32 c);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 id);
extern "C" void fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" void fn_80458FF0(void* obj, s32 a, s32 b, s32 c);
extern u8 sincosTable___5JMath[];
extern const u16 lbl_8053A108[4];
extern "C" void fn_801A96B4(void* this_) {
    f32 s = lbl_8053E6E0;
    s32 id;
    f32* v;
    s32 ang;
    s32 i;
    char* t = (char*)this_;

    fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), t + 0xc);
    *(f32*)(t + 0x80) = lbl_8053E6EC;
    *(f32*)(t + 0x84) = lbl_8053E6EC;
    *(f32*)(t + 0x88) = lbl_8053E6F0;
    *(f32*)(t + 0x8c) = lbl_8053E6F0;

    if (*(s32*)(t + 0x240) != *(s32*)(t + 0x250) && *(s32*)(t + 0x250) > 0) {
        *(s32*)(t + 0x238) = 50;
        *(s32*)(t + 0x240) = *(s32*)(t + 0x250);
        if (*(s32*)(t + 0x2b8) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(t + 0x2b8));
            *(s32*)(t + 0x2b8) = 0;
        }
        *(void**)(t + 0x2b8) = fn_8013CC50(*(s32*)(t + 0x4), t + 0xc, lbl_8053A108[4 - *(s32*)(t + 0x250)], 0, 0, 0, 0, 1, lbl_8053E6E8);
    }
    fn_8013CB44(*(void**)(t + 0x2b8), t + 0xc, 0, 0, 1);

    switch (*(s32*)(t + 0x250)) {
    case 0:
        if (*(s32*)(t + 0x230) != 4) {
            if (*(s32*)(t + 0x2b8) != 0) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(t + 0x2b8));
                *(s32*)(t + 0x2b8) = 0;
            }
            *(s32*)(t + 0x230) = 3;
        }
        break;
    case 1:
        *(s32*)(t + 0x248) = 0x400;
        break;
    case 2:
        *(s32*)(t + 0x248) = 0x300;
        break;
    case 3:
        *(s32*)(t + 0x248) = 0x200;
        break;
    case 4:
        *(s32*)(t + 0x248) = 0x100;
        break;
    }

    if (*(s32*)(t + 0x230) != 4 && *(s32*)(t + 0x230) != 3 && *(s32*)(t + 0x238) == 0) {
        if (*(s32*)(t + 0x244) == 0) {
            *(f32*)(t + 0x2b4) = *(f32*)(t + 0x2b4) - *(s32*)(t + 0x248);
        } else {
            *(f32*)(t + 0x2b4) = *(f32*)(t + 0x2b4) + *(s32*)(t + 0x248);
        }
    }

    for (i = 0; i < 4; i++) {
        void* c;
        id = *(s32*)(t + 0x270 + i * 4);
        if (id != 0) {
            c = fn_801F666C(fn_801F856C(), id);
            if (c != 0) {
                v = (f32*)(t + 0x280 + i * 0xc);
                ang = (s32)*(f32*)(t + 0x2b4) + (u16)(i * 0x4000);
                if (*(u8*)(t + 0x26c) == 1) {
                    *(u8*)((char*)c + 0x26c) = 1;
                    *(s32*)(t + 0x238) = 50;
                }
                *(f32*)((char*)c + 0x2b4) = (f32)((u16)ang + 0x8000);
                v[0] = *(f32*)(t + 0xc);
                v[1] = *(f32*)(t + 0x10);
                v[2] = *(f32*)(t + 0x14);
                v[0] = v[0] + lbl_8053E6F4 * *(f32*)(sincosTable___5JMath + (((u16)ang >> 2) & 0x3ff8));
                v[1] = v[1] + lbl_8053E6F4 * *(f32*)(sincosTable___5JMath + (((u16)ang >> 2) & 0x3ff8) + 4);
                *(f32*)((char*)c + 0xc) = v[0];
                *(f32*)((char*)c + 0x10) = v[1];
                *(f32*)((char*)c + 0x14) = v[2];
            }
        }

        switch (*(s32*)(t + 0x250)) {
        case 1:
            s = lbl_8053E700;
            break;
        case 2:
            s = lbl_8053E6FC;
            break;
        case 3:
            s = lbl_8053E6E8;
            break;
        case 4:
            s = lbl_8053E6F8;
            break;
        }
        if (*(s32*)(t + 0x238) == 0) {
            *(f32*)(t + 0x3c) = s * *(f32*)(sincosTable___5JMath + ((*(u16*)(t + 0x2b2) >> 2) & 0x3ff8));
            *(f32*)(t + 0x40) = s * *(f32*)(sincosTable___5JMath + ((*(u16*)(t + 0x2b2) >> 2) & 0x3ff8) + 4);
        }
    }

    *(u8*)(t + 0x26c) = 0;
    *(f32*)(t + 0xc) = *(f32*)(t + 0xc) + *(f32*)(t + 0x3c);
    *(f32*)(t + 0x10) = *(f32*)(t + 0x10) + *(f32*)(t + 0x40);
    *(f32*)(t + 0x14) = *(f32*)(t + 0x14) + *(f32*)(t + 0x44);
    fn_801F2B7C(t, -100, -1, 1);

    if (*(s32*)(t + 0x254) == 1 && *(u8*)(lbl_8053AAF8 + 0x7f) == 1) {
        if (*(s32*)(t + 0x258) != 5 && lbl_8053ABD0 == 0) {
            fn_80458FF0(lbl_8053AF80, 0x1000021, 0, 0);
        } else {
            fn_80458FF0(lbl_8053AF80, 0x1000004, 0, 0);
        }
    } else {
        *(s32*)(t + 0x254) = *(s32*)(t + 0x254) + 1;
        if (*(s32*)(t + 0x254) == 3) {
            *(s32*)(t + 0x254) = 2;
        }
    }

    switch (*(s32*)(t + 0x230)) {
    case 0:
        *(s32*)(t + 0x230) = 1;
        /* fall through */
    case 1:
        {
            u32 seed = *(u32*)(lbl_8053AAF8 + 0xb4) * 0x19660d + 0x3c6ef35f;
            u32 bits;
            f32 f;
            *(u32*)(lbl_8053AAF8 + 0xb4) = seed;
            bits = (seed >> 9) | 0x3f800000;
            f = *(f32*)&bits;
            *(s32*)(t + 0x244) = (s32)((f - lbl_8053E6E8) * lbl_8053E700) & 1;
        }
        *(s32*)(t + 0x230) = 2;
        /* fall through */
    case 2:
        if (fn_801F2618(t, 0, 0)) {
            *(f32*)(t + 0x44) = lbl_8053E6E0;
            *(f32*)(t + 0x40) = lbl_8053E6E0;
            *(f32*)(t + 0x3c) = lbl_8053E6E0;
            if (*(s32*)(t + 0x244) == 0) {
                *(u16*)(t + 0x2b2) -= 0x4000;
            } else {
                *(u16*)(t + 0x2b2) += 0x4000;
            }
            *(s32*)(t + 0x230) = 1;
        }
        if (*(s32*)(t + 0x238) != 0) {
            *(f32*)(t + 0x44) = lbl_8053E6E0;
            *(f32*)(t + 0x40) = lbl_8053E6E0;
            *(f32*)(t + 0x3c) = lbl_8053E6E0;
            if (*(s32*)(t + 0x238) == 1) {
                *(s32*)(t + 0x230) = 1;
            }
        }
        break;
    case 3:
        *(s32*)(t + 0x234) = 0;
        *(s32*)(t + 0x244) = 0;
        *(f32*)(t + 0x44) = lbl_8053E6E0;
        *(f32*)(t + 0x40) = lbl_8053E6E0;
        *(f32*)(t + 0x3c) = lbl_8053E6E0;
        *(s32*)(t + 0x230) = 4;
        /* fall through */
    case 4:
        if (*(s32*)(t + 0x234) == 0) {
            if (*(s32*)(t + 0x244) > 3) {
                ((void (*)(void*))((void**)*(void**)t)[9])(t);
            } else {
                s32 id2 = *(s32*)(t + 0x270 + *(s32*)(t + 0x244) * 4);
                if (id2 >= 0) {
                    void* c2 = fn_801F666C(fn_801F856C(), id2);
                    if (c2 != 0) {
                        ((void (*)(void*))((void**)*(void**)c2)[9])(c2);
                        *(s32*)(t + 0x234) = 10;
                        *(s32*)(t + 0x244) = *(s32*)(t + 0x244) + 1;
                    }
                }
            }
        }
        break;
    }
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_80138B7C(void* game);
extern void* lbl_804A2FB0[];
extern char* lbl_8053AAF8;
extern s32 lbl_8053ABD0;

// TTAT destructor
extern "C" void* fn_801AA464(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2FB0;
        fn_801EE434(*(void**)(this_ + 0x2b8));
        if (*(s32*)(this_ + 0x258) == 0 && *(s32*)(lbl_8053AAF8 + 0x4c) != 9) {
            fn_80138B7C(lbl_8053AAF8);
        }
        if (*(s32*)(this_ + 0x258) == 5) {
            lbl_8053ABD0--;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "Game/ItemBase.h"

extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void fn_801EFD34(void* this_, void* res, void* rec, f32 a, f32 b, f32 c, s32 d);
extern const f32 lbl_8053E6E0;
extern const f32 lbl_8053E6E4;
extern const f32 lbl_8053E6E8;
extern char* lbl_804A2F2C[];

struct TtatResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};

static inline void ttatRotScale(f32 m[3][4], f32 rx, const f32* pang, f32 rz, const f32* ps) {
    f32 ry = *pang / lbl_8053E6E4;
    f32 sz, sy, sx, cz, cy, cx;
    sx = sin(rx);
    sy = sin(ry);
    sz = sin(rz);
    cx = cos(rx);
    cy = cos(ry);
    cz = cos(rz);
    f32 cxcz = cx * cz;
    f32 sxsy = sx * sy;
    f32 cxsz = cx * sz;
    f32 sxsz = sx * sz;
    f32 sxcz = sx * cz;
    f32 s = *ps;
    m[0][0] = s * (cy * cz);
    m[1][0] = s * (cy * sz);
    m[2][0] = s * -sy;
    m[0][1] = s * (sxsy * cz - cxsz);
    m[1][1] = s * (sxsy * sz + cxcz);
    m[2][1] = s * (sx * cy);
    m[0][2] = s * (cxcz * sy + sxsz);
    m[1][2] = s * (cxsz * sy - sxcz);
    m[2][2] = s * (cx * cy);
}

extern "C" void fn_801A90D4(void* this_) {
    u8* t = (u8*)this_;
    DrawRec r;
    f32 m[3][4];
    m[0][3] = lbl_8053E6E0;
    m[1][3] = lbl_8053E6E0;
    m[2][3] = lbl_8053E6E0;
    r.b1d = 1;
    ttatRotScale(m, lbl_8053E6E0, (f32*)(t + 0x2b4), lbl_8053E6E0, &lbl_8053E6E8);
    r.w18 = m;
    void* res = (*(TtatResMgr**)(lbl_8053AAF8 + 0xa4))->get('TIMG', lbl_804A2F2C[0x20]);
    fn_801EFD34(this_, res, &r, lbl_8053E6E0, lbl_8053E6E0, lbl_8053E6E0, -1);
}

extern "C" void fn_801A9374(void* this_) {
    u8* t = (u8*)this_;
    DrawRec r;
    f32 m[3][4];
    m[0][3] = lbl_8053E6E0;
    m[1][3] = lbl_8053E6E0;
    m[2][3] = lbl_8053E6E0;
    r.b1d = 2;
    ttatRotScale(m, lbl_8053E6E0, (f32*)(t + 0x2b4), lbl_8053E6E0, &lbl_8053E6E8);
    r.w18 = m;
    void* res = (*(TtatResMgr**)(lbl_8053AAF8 + 0xa4))->get('TIMG', lbl_804A2F2C[*(s32*)(t + 0x24c)]);
    fn_801EFD34(this_, res, &r, lbl_8053E6E0, lbl_8053E6E0, lbl_8053E6E0, -1);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
