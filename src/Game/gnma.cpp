// GNMA actor. TU 801AAC8C-801AC8EC.
// Functions: draw (TODO), update (slot 3), state handlers (TODO), hit reaction
// (TODO), dtor, init (TODO).
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JMath/JMath.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_80138B7C(void* game);
extern "C" void fn_801AB6A8(void* this_);
extern "C" void fn_801AAF44(void* this_);
extern void* lbl_804A307C[];
extern char* lbl_8053AAF8;
extern s32 lbl_8053ABD8;

struct GnmaTimers { u8 pad[0x234]; s32 t[4]; };

// GNMA update (vtable slot 3)
extern "C" void fn_801AAE88(char* this_) {
    switch (*(s32*)(this_ + 0x254)) {
    case 0:
    case 2:
        fn_801AB6A8(this_);
        break;
    case 1:
    case 3:
        fn_801AAF44(this_);
        break;
    }
    for (int i = 0; i < 4; i++) {
        if (((GnmaTimers*)this_)->t[i] > 0) {
            ((GnmaTimers*)this_)->t[i]--;
        }
    }
}

struct Handles_gnma { u8 pad[0x27c]; void* h[2]; };

// GNMA destructor
extern "C" void* fn_801AC324(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A307C;
        for (int i = 0; i < 2; i++) {
            fn_801EE434(((Handles_gnma*)this_)->h[i]);
        }
        s32 kind = *(s32*)(this_ + 0x254);
        if (kind == 2 || kind == 3) {
            if (--lbl_8053ABD8 == 0 && *(s32*)(lbl_8053AAF8 + 0x4c) != 9) {
                fn_80138B7C(lbl_8053AAF8);
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_801F6874(u16 angle);
extern const f32 lbl_8053E744;
extern const f32 lbl_8053E7B0;

extern "C" void fn_801AC1F4(char* p) {
    if (*(s32*)(p + 0x25c) == *(s32*)(p + 0x108)) {
        return;
    }
    if (*(s32*)(p + 0x258) > 0) {
        (*(s32*)(p + 0x258))--;
    }
    if (*(s32*)(p + 0x258) <= 0) {
        *(u32*)(p + 0xb0) = 0;
    }
    *(s32*)(p + 0x25c) = *(s32*)(p + 0x108);
    s32 mode = *(s32*)(p + 0x254);
    if (mode == 1 || mode == 3) {
        *(f32*)(p + 0x26c) = lbl_8053E744;
        *(f32*)(p + 0x268) = lbl_8053E744;
        *(f32*)(p + 0x264) = lbl_8053E744;
        *(f32*)(p + 0x44) = lbl_8053E744;
        *(f32*)(p + 0x40) = lbl_8053E744;
        *(f32*)(p + 0x3c) = lbl_8053E744;
        *(u32*)(p + 0xb0) = 0x0a040004;
        *(s32*)(p + 0x248) = 1;
        *(s32*)(p + 0x230) = 12;
    } else {
        u16 ang = (u16)*(u32*)(p + 0x98) + 0x8000;
        *(f32*)(p + 0x3c) = lbl_8053E7B0 * JMASSin(fn_801F6874(ang));
        *(f32*)(p + 0x40) = lbl_8053E7B0 * JMASCos(fn_801F6874(ang));
        *(s32*)(p + 0x230) = 5;
    }
}

extern "C" void fn_801EFD34(void* actor, void* res, DrawRec* rec, s32 n, f32 a, f32 b, f32 c);
extern u32 lbl_804A3020[];
extern const f32 lbl_8053E740;
extern const f32 lbl_8053E748;
extern const f32 lbl_8053E74C;

static inline void tu_setScale(f32 (*mtx)[4], f32 sx, f32 sy) {
    f32 zero = lbl_8053E744;
    mtx[0][0] = sx;
    mtx[0][1] = zero;
    mtx[0][2] = zero;
    mtx[1][0] = zero;
    mtx[1][1] = sy;
    mtx[1][2] = zero;
    mtx[2][0] = zero;
    mtx[2][1] = zero;
    mtx[2][2] = sy;
    mtx[0][3] = zero;
    mtx[1][3] = zero;
    mtx[2][3] = zero;
}

class GnmaResMgr {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* getRes(u32 type, u32 name);
};

extern "C" void fn_801AAC8C(char* p) {
    DrawRec rec;
    f32 mtx[3][4];
    f32 sx = *(f32*)(p + 0x270);
    if (*(s32*)(p + 0x98) == 0) {
        sx *= lbl_8053E740;
    }
    tu_setScale(mtx, sx, *(f32*)(p + 0x274));
    rec.w18 = mtx;
    s32 n = 4;
    f32 scale = lbl_8053E748;
    s32 mode = *(s32*)(p + 0x254);
    if (mode == 0 || mode == 2) {
        n = 3;
        scale = lbl_8053E74C;
    }
    void* res = (*(GnmaResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('TIMG', lbl_804A3020[*(s32*)(p + 0x250)]);
    fn_801EFD34(p, res, &rec, n, lbl_8053E744, scale, lbl_8053E744);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
