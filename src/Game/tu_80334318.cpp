#include "types.h"
#include "Game/Actor.h"
#include "Game/ItemBase.h"


extern "C" char lbl_804AB9C0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80334318(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AB9C0;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* m, u32 code, s32 i);
extern "C" void* fn_801F666C(void* m, s32 i);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_801F349C(Actor* a, u32 x, f32* p);
extern "C" void fn_802F86CC(void*, void*, void*, s32, void*, f32, f32);
extern "C" void fn_80307AC8(u32, u32, void*, s32, s32, u32, s32);
extern "C" void PSMTXIdentity(f32 (*m)[4]);
extern "C" double sin(double x);
extern "C" double cos(double x);
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" char lbl_80471AB8[];
extern "C" char lbl_80471AC8[];
extern const f32 lbl_80541F80;
extern const f32 lbl_80541F84;
extern const f32 lbl_80541F88;
extern const f32 lbl_80541F8C;

class ResMgr {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void* v18(u32 type, const char* name);
};
extern const f32 lbl_80541F70;
extern const f32 lbl_80541F74;
extern const f32 lbl_80541F84;
extern const f32 lbl_80541F88;
extern const f32 lbl_80541FA8;
extern const f32 lbl_80541FB0;
extern const f32 lbl_80541FB4;
extern const f32 lbl_80541FD0;
extern const f32 lbl_80541FD4;
extern const f32 lbl_80541FD8;
extern const f32 lbl_80541FDC;
extern const f32 lbl_80541FE0;
extern const f32 lbl_80541FE4;
extern const f32 lbl_80541FE8;
extern const f32 lbl_80541FEC;
extern const f32 lbl_80541FF0;
extern "C" s32 fn_80334378(Actor* a) {
    s32 i = -1;
    u8* e;
    u32 st;
    do {
        do {
            i = fn_801F78F4(fn_801F856C(), 0x57415250, i);
            if (i < 0) {
                goto done;
            }
            e = (u8*)fn_801F666C(fn_801F856C(), i);
        } while (e == 0);
        st = *(u32*)(e + 0x90);
    } while ((u8)st != 7);
    u32 idx = (st >> 24) & 7;
    f32 fx;
    f32 fy;
    if (idx == 0) {
        register u8* m = (u8*)fn_802D6A9C();
        fx = *(f32*)(m + 0xcc);
        fy = *(f32*)(m + 0xd0);
    } else {
        fy = lbl_80541F70;
        idx += 7;
        fx = fy;
    }
    f32 pos[3];
    pos[0] = lbl_80541F74 + ((f32)((st >> 13) & 0x1f8) + fx);
    pos[1] = lbl_80541F74 + ((f32)((st >> 5) & 0x1f8) + fy);
    pos[2] = lbl_80541F70;
    fn_801F349C(a, idx, pos);
done:
    return i;
}

extern "C" void fn_80334488(Actor* a) {
    u8* p = (u8*)a;
    if (*(s32*)(p + 0x230) == 5) {
        return;
    }
    DrawRec rB;
    DrawRec rA;
    f32 vA[3];
    f32 vB[3];
    f32 mtx[3][4];
    f32 s;
    f32 cb;
    f32 ca;
    f32 sa;
    f32 sb;
    f32 sc;
    f32 cc;
    PSMTXIdentity(mtx);
    rB.b1d = -1;
    if (*(s32*)(p + 0x230) == 7) {
        s = *(f32*)(p + 0x240);
        sa = sin(lbl_80541F70);
        sb = sin(lbl_80541F70);
        sc = sin(lbl_80541F70);
        ca = cos(lbl_80541F70);
        cb = cos(lbl_80541F70);
        cc = cos(lbl_80541F70);
        mtx[0][0] = s * (cb * cc);
        mtx[1][0] = s * (cb * sc);
        mtx[2][0] = s * -sb;
        mtx[0][1] = s * ((sa * sb) * cc - ca * sc);
        mtx[1][1] = s * ((sa * sb) * sc + ca * cc);
        mtx[2][1] = s * (sa * cb);
        mtx[0][2] = s * ((ca * cc) * sb + sa * sc);
        mtx[1][2] = s * ((ca * sc) * sb - sa * cc);
        mtx[2][2] = s * (ca * cb);
        rA.w18 = mtx;
    }
    if (*(s32*)(p + 0x250) == 0) {
        if (*(s32*)(p + 0x230) != 7) {
            vA[1] = lbl_80541F80 + *(f32*)(p + 0x10);
            vA[0] = *(f32*)(p + 0xc);
            vA[2] = lbl_80541F70;
            if (*(s32*)(p + 4) < 8) {
                void* obj = (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->v18('SOB ', lbl_80471AB8);
                fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), vA, obj, 0, &rB, lbl_80541F84, lbl_80541F84);
            }
        }
        s32 id = *(s32*)(p + 0x24c) + 0x25;
        if (*(s32*)(p + 4) < 8) {
            void* obj = (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->v18('SOB ', lbl_80471AC8);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0xc, obj, id, &rA, lbl_80541F84, lbl_80541F84);
        }
        fn_80307AC8(*(u32*)(p + 0x198), *(u32*)(p + 4), p + 0xc, *(s32*)(p + 0x24c) + 0x25, 0, 0, -1);
    } else {
        if (*(s32*)(p + 0x230) != 7) {
            vB[1] = lbl_80541F88 + *(f32*)(p + 0x10);
            vB[0] = *(f32*)(p + 0xc);
            vB[2] = lbl_80541F70;
            if (*(s32*)(p + 4) < 8) {
                void* obj = (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->v18('SOB ', lbl_80471AB8);
                fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), vB, obj, 3, &rB, lbl_80541F8C, lbl_80541F84);
            }
        }
        s32 id = *(s32*)(p + 0x24c) + 0x27;
        if (*(s32*)(p + 4) < 8) {
            void* obj = (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->v18('SOB ', lbl_80471AC8);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0xc, obj, id, &rA, lbl_80541F84, lbl_80541F84);
        }
        fn_80307AC8(*(u32*)(p + 0x198), *(u32*)(p + 4), p + 0xc, *(s32*)(p + 0x24c) + 0x27, 0, 0, -1);
    }
}

extern "C" u16 fn_8022461C(s32 a);
extern "C" s32 fn_80335688(Actor* p, s32 a, s32 b) {
    s32 st;
    s32 r = fn_8022461C(b);
    st = *(s32*)((u8*)p + 0x230);
    r = (u16)r;
    if (st != 3 && (r == 0xc || r == 3 || r == 0xe)) {
        if (st != 7) {
            *(s32*)((u8*)p + 0x25c) = 0x1e;
        }
        *(s32*)((u8*)p + 0x230) = 7;
        return 0;
    }
    if (r != 0 && r != 0x22) return 1;
    return 0;
}

extern "C" void fn_8033571C(char* p) {
    *(u32*)(p + 0x108) = 0x80;
    *(u32*)(p + 0xb0) = 0x42304;
    if (*(u32*)(p + 0x90) & 1) {
        *(s32*)(p + 0x250) = 1;
        *(f32*)(p + 0x60) = lbl_80541FD0;
        *(f32*)(p + 0x64) = lbl_80541FD4;
        *(f32*)(p + 0x68) = lbl_80541F74;
        *(f32*)(p + 0x6c) = lbl_80541F88;
        *(f32*)(p + 0x80) = lbl_80541FD8;
        *(f32*)(p + 0x84) = lbl_80541FD0;
        *(f32*)(p + 0x88) = lbl_80541FDC;
        *(f32*)(p + 0x8c) = lbl_80541FE0;
    } else {
        *(s32*)(p + 0x250) = 0;
        *(f32*)(p + 0x60) = lbl_80541FD4;
        *(f32*)(p + 0x64) = lbl_80541FE4;
        *(f32*)(p + 0x68) = lbl_80541FB4;
        *(f32*)(p + 0x6c) = lbl_80541FE8;
        *(f32*)(p + 0x80) = lbl_80541FEC;
        *(f32*)(p + 0x84) = lbl_80541FB0;
        *(f32*)(p + 0x88) = lbl_80541FF0;
        *(f32*)(p + 0x8c) = lbl_80541F74;
    }
    *(u16*)(p + 0x94) = (*(u32*)(p + 0x90) >> 4) & 1;
    *(f32*)(p + 0x234) = lbl_80541F70;
    *(f32*)(p + 0x238) = lbl_80541F70;
    *(f32*)(p + 0x23c) = lbl_80541F70;
    *(f32*)(p + 0x240) = lbl_80541F84;
    *(f32*)(p + 0x268) = lbl_80541F70;
    *(f32*)(p + 0x264) = lbl_80541F70;
    *(f32*)(p + 0x260) = lbl_80541F70;
    if (*(u16*)(p + 0x94) == 0) {
        *(s32*)(p + 0x230) = 0;
    } else {
        *(s32*)(p + 0x230) = 5;
        *(f32*)(p + 0x14) = lbl_80541FA8;
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x248) = 10;
    *(s32*)(p + 0x244) = 100;
    *(s32*)(p + 0x254) = 0;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x25c) = 0;
    *(u16*)(p + 0x26c) = 0;
    *(s32*)(p + 0xb8) = 1;
}

