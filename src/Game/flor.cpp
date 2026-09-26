// TU 0x8020db74-0x8020f798 (actor FLOR).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

// ---- fn_8020F474_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6004[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_8020F474(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6004;
        fn_801EE434(*(void**)(p + 0x2b0));
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

extern "C" void fn_8030C210(void* mgr, void* pos);
extern char* lbl_8053AB10;

extern "C" void fn_8020DDC4(char* this_) {
    if (*(s32*)(this_ + 0x248) != 0) {
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
    }
}

extern "C" void* fn_801D0F40(void* this_);
extern "C" const f32 lbl_8053FA2C;

extern "C" void* fn_8020F510(char* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A6004;
    *(f32*)(this_ + 0x2a8) = lbl_8053FA2C;
    *(f32*)(this_ + 0x2ac) = lbl_8053FA2C;
    *(s32*)(this_ + 0x2b0) = 0;
    *(f32*)(this_ + 0x2b4) = lbl_8053FA2C;
    *(s32*)(this_ + 0x2b8) = -1;
    *(s32*)(this_ + 0x2bc) = 0;
    *(s32*)(this_ + 0x2c0) = -1;
    return this_;
}

extern "C" void fn_801D00B4(void* this_, s32 id, f32 f, f32* out);
extern "C" const f32 lbl_8053FA28;

extern "C" void fn_8020E268(char* this_) {
    f32 v[2];
    *(f32*)(this_ + 0x3c) = lbl_8053FA2C;
    *(f32*)(this_ + 0x40) = lbl_8053FA2C;
    *(f32*)(this_ + 0x44) = lbl_8053FA2C;
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
        if (*(s32*)(this_ + 0x2b8) >= 0) {
            fn_801D00B4(this_, *(s32*)(this_ + 0x2b8), lbl_8053FA28, v);
            *(f32*)(this_ + 0x3c) = v[0];
            *(f32*)(this_ + 0x40) = v[1];
        }
        break;
    }
}

extern "C" u8 fn_801F2DB4(void* this_, u32 a, u32 b, u32 c);
extern "C" void fn_801F0E34(void* this_, u32 id, u32 c);
extern "C" void fn_8020ED5C(void* this_, s32 st);

extern "C" u8 fn_8020DF4C(char* this_) {
    u8 r = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053FA2C &&
        *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053FA2C) {
        r = fn_801F2DB4(this_, *(u32*)(this_ + 0x1a0), 'NULL', 0);
        if (r) {
            fn_801F0E34(this_, 0x5007d, 0);
            u8 ok = 0;
            switch (*(s32*)(this_ + 0x248)) {
            case 3:
            case 5:
            case 6:
            case 8:
                ok = 1;
                break;
            }
            if (ok) {
                fn_8020ED5C(this_, 4);
            }
        }
    }
    return r;
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_801D2608(void* obj, void* tbl, s32 n);
extern "C" void fn_801D22DC(void* obj, s32 a, s32 b, s32 c);
extern void* lbl_804A5FE8[];
extern const f32 lbl_8053FA30;
extern const f32 lbl_8053FA40;

extern "C" void fn_8020F318(char* this_) {
    fn_801D0ED0(this_);
    if (*(u32*)(this_ + 0x90) & 1) {
        *(u32*)(this_ + 0x230) |= 0x2000;
        u32 p = *(u32*)(this_ + 0x90);
        *(f32*)(this_ + 0x2a8) = lbl_8053FA40 + (f32)((p >> 13) & 0x1f8);
        *(f32*)(this_ + 0x2ac) = lbl_8053FA40 + (f32)((p >> 5) & 0x1f8);
    }
    *(f32*)(this_ + 0x60) = lbl_8053FA28;
    *(f32*)(this_ + 0x64) = lbl_8053FA28;
    *(f32*)(this_ + 0x68) = lbl_8053FA30;
    *(f32*)(this_ + 0x6c) = lbl_8053FA30;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    *(f32*)(this_ + 0x80) = lbl_8053FA28;
    *(f32*)(this_ + 0x84) = lbl_8053FA28;
    *(f32*)(this_ + 0x88) = lbl_8053FA30;
    *(f32*)(this_ + 0x8c) = lbl_8053FA30;
    *(u32*)(this_ + 0xb0) = 0x50303;
    *(s32*)(this_ + 0x98) = 2;
    *(u32*)(this_ + 0x230) |= 0x380;
    *(s32*)(this_ + 0x108) = 1000;
    *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x108);
    *(u8*)(this_ + 0x194) = 1;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = fn_801CD664(0x3d) + 0x3c;
    *(f32*)(this_ + 0x254) = lbl_8053FA2C;
    *(f32*)(this_ + 0x258) = lbl_8053FA2C;
    fn_801D2608(this_ + 0x270, lbl_804A5FE8, 7);
    fn_801D22DC(this_ + 0x270, 0, 0, 0);
}

extern "C" void fn_801CE4BC(void* this_);
extern const f32 lbl_8053FA34;
extern const f32 lbl_8053FA38;
extern const f32 lbl_8053FA3C;
extern const f32 lbl_8053FA44;
extern const f32 lbl_8053FA48;
extern const f32 lbl_8053FA4C;
extern const f32 lbl_8053FA50;
extern const f32 lbl_8053FA54;

extern "C" void fn_8020E2D8(char* this_) {
    if (*(s32*)(this_ + 0x248) == 4) {
        return;
    }
    fn_801CE4BC(this_);
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053FA2C &&
        *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053FA2C) {
        switch (*(s32*)(this_ + 0x280)) {
        case 2:
            *(f32*)(this_ + 0x60) = lbl_8053FA34;
            *(f32*)(this_ + 0x64) = lbl_8053FA38;
            *(f32*)(this_ + 0x68) = lbl_8053FA3C;
            *(f32*)(this_ + 0x6c) = lbl_8053FA40;
            break;
        case 3:
            *(f32*)(this_ + 0x60) = lbl_8053FA38;
            *(f32*)(this_ + 0x64) = lbl_8053FA44;
            *(f32*)(this_ + 0x68) = lbl_8053FA48;
            *(f32*)(this_ + 0x6c) = lbl_8053FA40;
            break;
        case 4:
            *(f32*)(this_ + 0x60) = lbl_8053FA38;
            *(f32*)(this_ + 0x64) = lbl_8053FA4C;
            *(f32*)(this_ + 0x68) = lbl_8053FA28;
            *(f32*)(this_ + 0x6c) = lbl_8053FA40;
            break;
        case 5:
            *(f32*)(this_ + 0x60) = lbl_8053FA50;
            *(f32*)(this_ + 0x64) = lbl_8053FA54;
            *(f32*)(this_ + 0x68) = lbl_8053FA3C;
            *(f32*)(this_ + 0x6c) = lbl_8053FA40;
            break;
        }
        if (*(u32*)(this_ + 0x230) & 0x8000) {
            f32 t = *(f32*)(this_ + 0x60);
            *(f32*)(this_ + 0x60) = -*(f32*)(this_ + 0x68);
            *(f32*)(this_ + 0x68) = -t;
        }
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    }
}

extern "C" s32 fn_801F285C(void* this_, f32* pos, void* out, s32 a, s32 idx);
extern "C" void fn_8023B6CC(s32 idx);
extern "C" u8 fn_801EAC20(void* list, s32 idx);
extern "C" void fn_801CB538(u32 room, f32* pos, s32 a, s32 b);

extern "C" u8 fn_8020DDFC(char* this_) {
    u8 r = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053FA2C &&
        *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053FA2C) {
        for (s32 i = 0; i < 4; i++) {
            f32 pos[2];
            u8 tmp[4];
            if (i == fn_801F285C(this_, pos, tmp, 1, i)) {
                fn_8023B6CC(i);
                if (fn_801EAC20(this_ + 0x1dc, i)) {
                    r = 1;
                    f32 p3[3];
                    p3[0] = pos[0];
                    p3[1] = pos[1];
                    p3[2] = lbl_8053FA2C;
                    fn_801CB538(*(u32*)(this_ + 0x4), p3, 0, 0);
                }
            }
        }
        if (r) {
            fn_801F0E34(this_, 0x5007d, 0);
            u8 ok = 0;
            switch (*(s32*)(this_ + 0x248)) {
            case 3:
            case 5:
            case 6:
            case 8:
                ok = 1;
                break;
            }
            if (ok) {
                fn_8020ED5C(this_, 4);
            }
        }
    }
    return r;
}

extern "C" void fn_801F317C(void* this_, void* out);
extern "C" s32 fn_8023AE34(void* a, u32 id, void* out);
extern "C" s32 fn_8023AA18(void* a, u32 id, void* out);
extern "C" s32 fn_8023AC74(void* a, u32 id, void* out);
extern "C" s32 fn_8023AD54(void* a, u32 id, void* out);
extern "C" u8 fn_801CC820(s32 id, void* pos);
extern "C" u8 fn_801CC538(s32 id, void* a, void* pos, s32* out);
extern "C" void fn_801CC640(s32 id, s32* a, void* pos);
extern "C" void* fn_801F856C(void);
extern "C" char* fn_801F666C(void* base, s32 id);
extern "C" u8 fn_801EAC54(void* list, u32 v);

extern "C" u8 fn_8020E030(char* this_) {
    if (*(f32*)(this_ + 0x78) - *(f32*)(this_ + 0x70) <= lbl_8053FA2C ||
        *(f32*)(this_ + 0x7c) - *(f32*)(this_ + 0x74) <= lbl_8053FA2C) {
        return 0;
    }
    s32 n = -1;
    f32 pos[2];
    f32 buf24[3];
    f32 v[3];
    u8 bufC[16];
    s32 id;
    u8 hit = 0;
    u8 wall = 0;
    v[0] = lbl_8053FA2C;
    v[1] = lbl_8053FA2C;
    v[2] = lbl_8053FA2C;
    fn_801F317C(this_, bufC);
    id = fn_8023AE34(bufC, *(u32*)(this_ + 0x4), pos);
    if (id >= 0) {
        hit = fn_801CC820(id, v);
    } else {
        id = fn_8023AA18(bufC, *(u32*)(this_ + 0x4), pos);
        if (id >= 0) {
            wall = 1;
        } else {
            id = fn_8023AC74(bufC, *(u32*)(this_ + 0x4), pos);
            if (id >= 0) {
                fn_801CC538(id, pos, buf24, &n);
            } else {
                id = fn_8023AD54(bufC, *(u32*)(this_ + 0x4), pos);
                if (id >= 0) {
                    fn_801CC640(id, &n, v);
                }
            }
        }
    }
    u8 r = 0;
    if (id >= 0) {
    if (hit) {
        r = 1;
    } else if (wall) {
        if (fn_801EAC20(this_ + 0x1dc, id)) {
            r = 1;
        }
    } else {
        id = n;
        if (id >= 0) {
            char* a = fn_801F666C(fn_801F856C(), id);
            if (a != 0 && fn_801EAC54(this_ + 0x1dc, *(u32*)(a + 0x198))) {
                r = 1;
            }
        }
    }
    if (r) {
        f32 p3[3];
        p3[0] = pos[0];
        p3[1] = pos[1];
        p3[2] = lbl_8053FA2C;
        fn_801CB538(*(u32*)(this_ + 0x4), p3, 0, 0);
    }
    if (r) {
    fn_801F0E34(this_, 0x5007d, 0);
    u8 ok = 0;
    switch (*(s32*)(this_ + 0x248)) {
    case 3:
    case 5:
    case 6:
    case 8:
        ok = 1;
        break;
    }
    if (ok) {
        fn_8020ED5C(this_, 4);
    }
    }
    }
    return r;
}

struct FlorResMgr {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual void v03();
    virtual void* getRes(u32 type, const char* name);
};
extern char* lbl_8053AAF8;
extern char lbl_8046A430[];
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, void* data, f32 a, f32 b);

extern "C" void fn_8020DB74(char* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 1:
    case 10:
        break;
    default: {
    JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(this_ + 0xc));
    if (*(s32*)(this_ + 0x248) == 4 && *(s32*)(this_ + 0x24c) >= 60) {
        if (*(s32*)(this_ + 0x24c) % 4 < 2) {
            pos.x += lbl_8053FA28;
        } else {
            pos.x -= lbl_8053FA28;
        }
    }
    u8 buf[0x3c];
    f32 mtx[3][4];

    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = -1;

    for (u8 i = 0; i < 16; i++) {
        buf[i] = i;
    }

    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = 0;
    *(s32*)(buf + 0x18) = 0;
    buf[0x1c] = 0;
    buf[0x1d] = 0;
    buf[0x1e] = 0;
    buf[0x1f] = 1;
    buf[0x20] = 1;
    buf[0x21] = 0;
    buf[0x22] = 0;
    buf[0x23] = 0;
    buf[0x24] = 0;
    buf[0x25] = 0;
    buf[0x26] = 1;
    *(s32*)(buf + 0x28) = 3;
    buf[0x2c] = 1;
    buf[0x2d] = 0;
    buf[0x2e] = 0;
    *(s32*)(buf + 0x30) = -1;
    *(s32*)(buf + 0x34) = 0;
    *(s32*)(buf + 0x38) = 2;
    buf[0x1c] = 0;
    buf[0x1d] = 0;

    if (*(u32*)(this_ + 0x230) & 0x8000) {
        mtx[0][3] = lbl_8053FA2C;
        mtx[1][3] = lbl_8053FA2C;
        mtx[2][3] = lbl_8053FA2C;
        mtx[0][0] = lbl_8053FA30;
        mtx[0][1] = lbl_8053FA2C;
        mtx[0][2] = lbl_8053FA2C;
        mtx[1][0] = lbl_8053FA2C;
        mtx[1][1] = lbl_8053FA28;
        mtx[1][2] = lbl_8053FA2C;
        mtx[2][0] = lbl_8053FA2C;
        mtx[2][1] = lbl_8053FA2C;
        mtx[2][2] = lbl_8053FA28;
        *(void**)(buf + 0x18) = mtx;
    }
    s32 id = *(s32*)(this_ + 0x280) + 0x321;
    if (*(s32*)(this_ + 0x4) < 8) {
        void* res = ((FlorResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_8046A430);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), &pos, res, id, buf, lbl_8053FA28, lbl_8053FA28);
    }
    break;
    }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
