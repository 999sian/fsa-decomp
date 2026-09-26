// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A908C-801AAC8C (TTAT). Remaining functions are not yet decompiled.
#include "types.h"

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
