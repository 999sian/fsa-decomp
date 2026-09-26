// TU 0x80212e3c-0x80213e00 (actor ARIJ).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// ---- fn_80212E3C_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6340[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80212E3C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6340;
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
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- fn_80212ECC.cpp ----
extern "C" void fn_80213774(void* this_, s32 state);

// fn_80212ECC(this) - called from RUSA's setParams (extab_80212288.s)
// on sub-variant 0, once the spawned ARIJ child handle is confirmed
// valid. Picks a behavior state via fn_80213774(this, state): state 0
// if flag bit 17 of this->0x230 is set, otherwise state 2 (unless the
// current state this->0x248 is already 2, in which case does
// nothing).
extern "C" void fn_80212ECC(void* this_) {
    s32 flags = *(s32*)((char*)this_ + 0x230);
    if (flags & 0x4000) {
        fn_80213774(this_, 0);
    } else {
        if (*(s32*)((char*)this_ + 0x248) != 2) {
            fn_80213774(this_, 2);
        }
    }
}

// ---- fn_80212F14.cpp ----
extern "C" void fn_80213774(void* this_, s32 state);

// fn_80212F14(this) - sibling of fn_80212ECC: same flag-bit-17 gate,
// but the "not yet in this state" target is state 1 (this->0x248==1
// check) instead of state 2.
extern "C" void fn_80212F14(void* this_) {
    s32 flags = *(s32*)((char*)this_ + 0x230);
    if (flags & 0x4000) {
        fn_80213774(this_, 0);
    } else {
        if (*(s32*)((char*)this_ + 0x248) != 1) {
            fn_80213774(this_, 1);
        }
    }
}

// ---- fn_80212FF4.cpp ----
extern "C" void* SpatialRegistry_GetBase();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void fn_80210D90(void* companion);
extern "C" void fn_801F4F28(void* this_);

extern "C" void fn_80212FF4(void* this_) {
    s32 id = *(s32*)((char*)this_ + 0x90);
    if (id >= 0) {
        void* base = SpatialRegistry_GetBase();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            fn_80210D90(found);
        }
    }
    fn_801F4F28(this_);
}

// ---- fn_80213050.cpp ----
extern "C" void fn_80213774(void* this_, s32 state);

// fn_80213050(this) - a 3-condition gate on the same RUSA-repel state
// machine as fn_80212ECC/fn_80212F14: if this->0xd4==1 AND
// this->0x248!=0 AND flag bit 17 of this->0x230 is clear, transitions
// to state 4 via fn_80213774.
extern "C" void fn_80213050(void* this_) {
    u8 flag = *(u8*)((char*)this_ + 0xd4);
    if (flag != 1) {
        return;
    }
    if (*(s32*)((char*)this_ + 0x248) == 0) {
        return;
    }
    s32 flags = *(s32*)((char*)this_ + 0x230);
    if (flags & 0x4000) {
        return;
    }
    fn_80213774(this_, 4);
}

// ---- Arij_ctor_80213BA0.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A6340[];

extern "C" void* fn_80213BA0(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A6340;
    return this_;
}


extern const f32 lbl_8053FB48;
extern const f32 lbl_8053FB4C;
extern const f32 lbl_8053FB54;
extern const f32 lbl_8053FB58;
extern const f32 lbl_8053FB5C;
extern const f32 lbl_8053FB60;
extern const f32 lbl_8053FB78;
extern void* lbl_804A6330[];
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801D2608(void* obj, void* tbl, s32 n);
extern "C" void fn_801D22DC(void* obj, s32 a, s32 b, s32 c);

#define AF32(o) (*(f32*)(p + (o)))
#define AS32(o) (*(s32*)(p + (o)))

extern "C" void fn_80212F5C(char* p) {
    AF32(0x10) = AF32(0x10) - lbl_8053FB48;
    AF32(0x24) = AF32(0xc);
    AF32(0x28) = AF32(0x10);
    AF32(0x2c) = AF32(0x14);
    AS32(0x230) |= 0x2200;
    AS32(0x108) = 1000;
    AS32(0x244) = AS32(0x108);
    AF32(0x54) = lbl_8053FB4C;
    AF32(0x58) = lbl_8053FB4C;
    AF32(0x5c) = lbl_8053FB4C;
    AF32(0x70) = AF32(0x70) * AF32(0x54);
    AF32(0x78) = AF32(0x78) * AF32(0x54);
    AF32(0x74) = AF32(0x74) * AF32(0x58);
    AF32(0x7c) = AF32(0x7c) * AF32(0x58);
}

extern "C" void fn_80213AAC(char* p) {
    fn_801D0ED0(p);
    AF32(0x60) = lbl_8053FB48;
    AF32(0x64) = lbl_8053FB48;
    AF32(0x68) = lbl_8053FB58;
    AF32(0x6c) = lbl_8053FB58;
    AF32(0x70) = lbl_8053FB60;
    AF32(0x74) = lbl_8053FB60;
    AF32(0x78) = lbl_8053FB5C;
    AF32(0x7c) = lbl_8053FB5C;
    AF32(0x80) = lbl_8053FB48;
    AF32(0x84) = lbl_8053FB48;
    AF32(0x88) = lbl_8053FB58;
    AF32(0x8c) = lbl_8053FB58;
    AS32(0xb0) = 0;
    AS32(0x98) = 2;
    AS32(0x230) |= 0x80;
    AF32(0x10) = AF32(0x10) - lbl_8053FB78;
    AF32(0x24) = AF32(0xc);
    AF32(0x28) = AF32(0x10);
    AF32(0x2c) = AF32(0x14);
    AS32(0x248) = 0;
    AS32(0x24c) = 0;
    AS32(0x250) = -1;
    AF32(0x254) = lbl_8053FB54;
    AF32(0x258) = lbl_8053FB54;
    fn_801D2608(p + 0x270, lbl_804A6330, 4);
    fn_801D22DC(p + 0x270, 1, 2, 0);
}

extern "C" u8 fn_801D217C(void* obj);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 c);
extern "C" void fn_801CE4BC(void* this_);

inline void arijSetBox(char* p, f32 a, f32 b, f32 c, f32 d) {
    AF32(0x60) = a;
    AF32(0x64) = b;
    AF32(0x68) = c;
    AF32(0x6c) = d;
}

inline void arijSetBoxS(char* p, f32 sx, f32 sy) {
    arijSetBox(p, lbl_8053FB60 * sx, lbl_8053FB60 * sy, lbl_8053FB5C * sx, lbl_8053FB5C * sy);
}

extern "C" void fn_802132FC(char* p) {
    if (AS32(0x248) == 4 && AS32(0x278) == 1 && fn_801D217C(p + 0x270)) {
        fn_801F0E34(p, 0x50035, 0);
    }
    fn_801CE4BC(p);
    switch (AS32(0x248)) {
    case 3:
    case 6:
        switch (AS32(0x280)) {
        case 0:
            arijSetBox(p, lbl_8053FB48, lbl_8053FB48, lbl_8053FB58, lbl_8053FB58);
            break;
        default:
            {
f32 sx = AF32(0x54);
            f32 sy = AF32(0x58);
            f32 a = lbl_8053FB60 * sx;
            f32 b = lbl_8053FB60 * sy;
            f32 c = lbl_8053FB5C * sx;
            f32 d = lbl_8053FB5C * sy;
            AF32(0x60) = a;
            AF32(0x64) = b;
            AF32(0x68) = c;
            AF32(0x6c) = d;
            }
            break;
        }
        if (AS32(0x248) == 0) {
            AS32(0xb0) = 0;
        } else if (AF32(0x68) - AF32(0x60) > lbl_8053FB54 && AF32(0x6c) - AF32(0x64) > lbl_8053FB54) {
            if (AS32(0x230) & 0x2000) {
                AS32(0xb0) = 0x40004;
            } else {
                AS32(0xb0) = 0x11101;
            }
        } else {
            if (AS32(0x230) & 0x2000) {
                AS32(0xb0) = 0;
            } else {
                AS32(0xb0) = 0x1000;
            }
        }
        break;
    }
}

struct ArijDrawParam {
    ArijDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = NULL;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};
struct ArijResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};
extern const f32 lbl_8053FB50;
extern const char lbl_8046A564[];
extern char* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern "C" void fn_802F86CC(void* map, void* pos, void* res, f32 a, f32 b, s32 id, ArijDrawParam* prm);
extern "C" void fn_801F06F0(void* this_, const char* table, s32 id, ArijDrawParam* prm, f32 f1, f32 f2, s32 mode);

extern "C" void fn_80213098(char* p) {
    if (((JGeometry::TVec3<f32>*)(p + 0x54))->isZero() == false) {
        switch (AS32(0x248)) {
        case 0:
        case 1:
        case 2:
            break;
        default: {
            s32 id = AS32(0x280) + 0x13d;
            if (AS32(0x230) & 0x2000) {
                id += 4;
            }
            ArijDrawParam prm;
            f32 mtx[3][4];
            prm.reset();
            mtx[0][3] = lbl_8053FB54;
            mtx[1][3] = lbl_8053FB54;
            mtx[2][3] = lbl_8053FB54;
            f32 sx = AF32(0x54);
            f32 sy = AF32(0x58);
            f32 sz = AF32(0x5c);
            mtx[0][0] = sx;
            mtx[0][1] = lbl_8053FB54;
            mtx[0][2] = lbl_8053FB54;
            mtx[1][0] = lbl_8053FB54;
            mtx[1][1] = sy;
            mtx[1][2] = lbl_8053FB54;
            mtx[2][0] = lbl_8053FB54;
            mtx[2][1] = lbl_8053FB54;
            mtx[2][2] = sz;
            prm.mMtx = mtx;
            if (AS32(0x230) & 0x2000) {
                if (AS32(4) < 8) {
                    void* res = (*(ArijResMgr**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, lbl_8046A564);
                    fn_802F86CC(*(void**)((char*)lbl_8053AB10 + 0x20), p + 0xc, res, lbl_8053FB48, lbl_8053FB48, id, &prm);
                }
            } else {
                s32 mode = -1;
                if (AF32(0x14) > lbl_8053FB54) {
                    mode = 7;
                }
                fn_801F06F0(p, lbl_8046A564, id, &prm, lbl_8053FB48, lbl_8053FB48, mode);
            }
            break;
        }
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
