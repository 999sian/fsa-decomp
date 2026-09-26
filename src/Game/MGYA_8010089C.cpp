// MGYA_8010089C: .text 0x8010089C-0x80102278 (actor MGYA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_8010089C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C8EC[];

extern "C" void* fn_8010089C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C8EC;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JGeometry/Vec.h"
extern const f32 lbl_8053C140;
extern "C" void fn_801F0E34(void* this_, s32 id, s32 c);
extern "C" void fn_8030C210(void*, void*);
extern "C" void detach__5ActorFv(void* this_);
extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" s32 fn_8013CC50(s32 id, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);
extern "C" u8 fn_8022F514(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" void fn_80238548(s32, s32, void*, s32);
extern "C" void* fn_80138A30(void*);
struct MGYA_Random {
    u32 seed;
    f32 get() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053C140;
    }
};
struct MGYA_Game { u8 pad[0xb4]; MGYA_Random rnd; };
extern MGYA_Game* lbl_8053AAF8;
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void*, s32);
extern const f32 lbl_8053C148;
extern const f32 lbl_8053C14C;
extern const f32 lbl_8053C150;
extern u8* lbl_8053AB10;
extern const f32 lbl_8053C144;
extern const f32 lbl_8053C190;
extern const f32 lbl_8053C194;
extern const f32 lbl_8053C198;
extern const f32 lbl_8053C19C;
extern const f32 lbl_8053C1A0;

class MGYA {
public:
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual u8 v34();
    s32 m04;
    u8 pad08[4];
    JGeometry::TVec3f mPos; // 0x0c
    u8 pad18[0x60 - 0x18];
    f32 m60, m64, m68, m6C;
    f32 m70, m74, m78, m7C;
    u8 pad80[0x90 - 0x80];
    u32 m90;
    u8 pad94[0xb0 - 0x94];
    s32 mB0;
    u8 padB4[0x10c - 0xb4];
    s32 m10C;
    u8 pad110[0x230 - 0x110];
    s32 m230;
    s32 m234;
    s32 m238;
    s32 m23C;
    s32 m240;
    u8 m244;
    u8 m245;
    u8 m246;
    u8 m247;
    u8 m248;
    u8 pad249[0x24c - 0x249];
    JGeometry::TVec3f m24C;
    f32 m258;
    u8 m25C[4];
    u16 m260[4];
    u16 m268[4];
    u8 pad270[0x290 - 0x270];
    MGYA* m290;
};

extern "C" void fn_80100D28(MGYA* this_);

extern "C" void fn_801008FC(MGYA* this_) {
    s32 pl = this_->m10C;
    if (pl < 0) {
        return;
    }
    fn_801F0E34(this_, 0x40099, 0);
    if (fn_8022F514(pl)) {
        pl = fn_8022F3DC(pl);
    }
    if (this_->m244 == 1) {
        JGeometry::TVec3f pos = this_->mPos;
        pos.x += lbl_8053C144;
        fn_8013CC50(this_->m04, &pos, 0x59, 1, 1, 0, 0, 1, lbl_8053C140);
        fn_8013CC50(this_->m04, &pos, 0x5a, 1, 1, 0, 0, 1, lbl_8053C140);
        fn_8013CC50(this_->m04, &pos, 0x5b, 1, 1, 0, 0, 1, lbl_8053C140);
        fn_801F0E34(this_, 0x30001, 0);
        f32 xy[2];
        xy[0] = pos.x;
        xy[1] = pos.y;
        fn_80238548(pl, 0, xy, 0xb);
    } else {
        s32 a = 1;
        s32 b = 0;
        if (pl == this_->m244 - 2) {
            a = 3;
        } else if (this_->m244 != 0) {
            b = 1;
        }
        MGYA* m = this_->m290;
        m->m260[pl] += a;
        m->m268[pl] += b;
    }
}

extern "C" void fn_80100A90(MGYA* this_) {
    this_->m290 = (MGYA*)fn_801F666C(fn_801F856C(), this_->m90 & 0xffff);
    this_->m60 = lbl_8053C148;
    this_->m64 = lbl_8053C148;
    this_->m68 = lbl_8053C14C;
    this_->m6C = lbl_8053C14C;
    this_->m70 = lbl_8053C148;
    this_->m74 = lbl_8053C148;
    this_->m78 = lbl_8053C14C;
    this_->m7C = lbl_8053C14C;
    this_->m234 = 0;
    this_->m246 = 0;
    this_->m245 = 0;
    this_->m240 = 0;
    s32 r = lbl_8053C150 * lbl_8053AAF8->rnd.get();
    int n = (u8)(u32)fn_80138A30(lbl_8053AAF8);
    if (this_->m290->m23C > 0x2d0) {
        if (r < 10) {
            this_->m244 = 1;
        } else if (n >= 1 && r < 15) {
            this_->m244 = 2;
        } else if (n >= 2 && r < 20) {
            this_->m244 = 3;
        } else if (n >= 3 && r < 25) {
            this_->m244 = 4;
        } else if (n == 4 && r < 30) {
            this_->m244 = 5;
        } else {
            this_->m244 = 0;
        }
    } else {
        s32 t3;
        s32 t1;
        s32 t2;
        s32 t4;
        s32 base;
        base = 0;
        t4 = 0;
        t2 = 0;
        t1 = 0;
        switch (n) {
        case 1:
            t1 = 0x5a;
            base = 10;
            break;
        case 2:
            t1 = 0x2d;
            t2 = 0x2d;
            base = 10;
            break;
        case 3:
            t1 = 0x1e;
            t2 = 0x1e;
            t3 = 0x1e;
            base = 10;
            break;
        case 4:
            t1 = 0x16;
            t2 = 0x16;
            t3 = 0x16;
            t4 = 0x16;
            base = 12;
            break;
        }
        if (r < base) {
            this_->m244 = 1;
        } else if (r < (t1 = base + t1)) {
            this_->m244 = 2;
        } else if (r < (t1 = t2 + t1)) {
            this_->m244 = 3;
        } else if (r < (t1 = t3 + t1)) {
            this_->m244 = 4;
        } else if (r < t4 + t1) {
            this_->m244 = 5;
        }
    }
    fn_8013CC50(this_->m04, &this_->mPos, 0x1da, 0, 1, 0, 0, 1, lbl_8053C140);
}

extern "C" void fn_80101DF0(MGYA* this_) {
    if (this_->m90 & 0x10000) {
        this_->m245++;
        if (this_->m245 == 8) {
            this_->m246++;
            if (this_->m246 == 2) {
                this_->m246 = 0;
            }
            this_->m245 = 0;
        }
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &this_->mPos);
        this_->m234++;
        if (this_->m234 < 0x28) {
            if ((this_->m234 & 3) == 0) {
                fn_8013CC50(this_->m04, &this_->mPos, 0x1da, 0, 1, 0, 0, 1, lbl_8053C140);
            }
        } else {
            this_->m240 = 1;
            this_->mB0 = 0x1100;
            if (this_->m234 == 0xa0) {
                fn_8013CC50(this_->m04, &this_->mPos, 0x1da, 0, 1, 0, 0, 1, lbl_8053C140);
                detach__5ActorFv(this_);
            }
            fn_801F3D94(this_, 1);
        }
    } else {
        fn_80100D28(this_);
    }
}

extern "C" void fn_80101F20(MGYA* this_) {
    if (this_->m90 & 0x10000) {
        fn_80100A90(this_);
        return;
    }
    this_->m60 = lbl_8053C194;
    this_->m64 = lbl_8053C194;
    this_->m68 = lbl_8053C198;
    this_->m6C = lbl_8053C198;
    this_->m247 = 1;
    this_->m246 = 0;
    this_->m245 = 0;
    this_->m238 = -1;
    this_->mPos.x += lbl_8053C19C;
    this_->mPos.y += lbl_8053C1A0;
    this_->m24C.x = this_->mPos.x;
    this_->m24C.y = this_->mPos.y;
    this_->m24C.z = this_->mPos.z;
    this_->m258 = lbl_8053C190;
    for (int i = 0; i < 4; i++) {
        this_->m25C[i] = 0;
        this_->m260[i] = 0;
        this_->m268[i] = 0;
    }
    this_->m244 = (u8)(u32)fn_80138A30(lbl_8053AAF8);
    this_->m248 = (this_->m90 >> 22) & 0x1f;
    if (this_->v34()) {
        this_->m230 = 9;
        this_->m234 = 0;
    } else {
        this_->m230 = 0;
        this_->m234 = 0;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
