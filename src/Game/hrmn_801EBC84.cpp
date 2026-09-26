// Game TU 801EBC84-801ED3DC (HRMN). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern s32 lbl_8053A160;
extern void* lbl_804A5630[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_801ED0AC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5630;
        lbl_8053A160 = -1;
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

extern "C" void fn_801D2264(void* anim, u32 a, u32 b);
extern "C" void fn_801CE4BC(void* this_);
extern "C" void* fn_801D0F40(void* this_);
extern "C" void* fn_80138A30(void* mgr);
extern "C" void fn_801ED974(void* p);
extern "C" void fn_80216178(void* p);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801D2608(void* obj, void* tbl, u32 n);
extern "C" void fn_801D22DC(void* obj, u32 a, u32 b, u32 c);
extern "C" void fn_801ED8F0(void* p);
extern "C" void fn_80215F30(void* p);
extern "C" void fn_801CE0A4(void* this_, void* arg);
extern "C" void fn_80239914(f32* rect, u32 a, u32 b);
extern "C" u8* fn_8020D58C(void);
extern "C" void fn_8020D8C0(void* p, f32* rect, u32 a, u32 b);
extern "C" s32 fn_80215A94(void* p);
extern "C" void fn_801EF830(u32 id, void* pos, u32 a, u32 b, void* tbl, u32 c, u32 d);
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, u32 a, f32 x, f32 y);
extern "C" void fn_801ED828(void* p);
extern "C" void fn_80215ECC(void* p);
extern char* lbl_8053AAF8;
extern char* lbl_8053AB10;
extern u8 lbl_804A5620[];
extern u8 lbl_80469CC8[];
extern u8 lbl_80469CD8[];
extern const f32 lbl_8053F6B8;
extern const f32 lbl_8053F6BC;
extern const f32 lbl_8053F6C0;
extern const f32 lbl_8053F6C4;

class HrmnResMgr {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* getRes(u32 type, void* name);
};

extern "C" void fn_801EBC84(char* p) {
    if (*(u32*)(p + 0x138) == 0) {
        fn_801EF830(*(u32*)(p + 0x4), p + 0xc, 0, 0, lbl_80469CC8, 0, 0);
    }
    s32 id = *(s32*)(p + 0x280) + 0x319;
    if (*(s32*)(p + 0x4) < 8) {
        void* res = (*(HrmnResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_80469CD8);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0xc, res, id, 0, lbl_8053F6B8, lbl_8053F6B8);
    }
    fn_801ED828(p + 0x2b6);
    switch (*(s32*)(p + 0x248)) {
    case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16:
        fn_80215ECC(p + 0x2b8);
        break;
    }
}

struct HrmnRect {
    HrmnRect(f32 a, f32 b, f32 c, f32 d) { x0 = a; y0 = b; x1 = c; y1 = d; }
    f32 x0, y0, x1, y1;
};

extern "C" void fn_801EBD6C(char* p, void* arg) {
    fn_801ED8F0(p + 0x2b6);
    fn_80215F30(p + 0x2b8);
    fn_801CE0A4(p, arg);
    HrmnRect rect(*(f32*)(p + 0xc) - lbl_8053F6BC, *(f32*)(p + 0x10) - lbl_8053F6BC, lbl_8053F6BC + *(f32*)(p + 0xc), lbl_8053F6BC + *(f32*)(p + 0x10));
    fn_80239914((f32*)&rect, *(u32*)(p + 0x4), *(u32*)(p + 0x198));
    u32 b = *(u32*)(p + 0x198);
    u32 a = *(u32*)(p + 0x4);
    u8* m = fn_8020D58C();
    fn_8020D8C0(m + *m * 0x784 + 4, (f32*)&rect, a, b);
    lbl_8053A160 = fn_80215A94(p + 0x2b8);
}

extern "C" void fn_801EBE3C(char* p) {
    fn_801D2264(p + 0x270, *(u32*)(p + 0x98), 2);
    fn_801CE4BC(p);
}

extern "C" void fn_801ECFBC(char* p) {
    fn_801D0ED0(p);
    *(u32*)(p + 0x2ac) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    *(f32*)(p + 0x60) = lbl_8053F6B8;
    *(f32*)(p + 0x64) = lbl_8053F6B8;
    *(f32*)(p + 0x68) = lbl_8053F6C4;
    *(f32*)(p + 0x6c) = lbl_8053F6C4;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(f32*)(p + 0x80) = lbl_8053F6B8;
    *(f32*)(p + 0x84) = lbl_8053F6B8;
    *(f32*)(p + 0x88) = lbl_8053F6C4;
    *(f32*)(p + 0x8c) = lbl_8053F6C4;
    *(u32*)(p + 0xb0) = 0;
    *(u32*)(p + 0x98) = 2;
    *(u32*)(p + 0x230) |= 0x380;
    *(s32*)(p + 0x108) = 1000;
    *(s32*)(p + 0x244) = *(s32*)(p + 0x108);
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = lbl_8053F6C0;
    *(f32*)(p + 0x258) = lbl_8053F6C0;
    fn_801D2608(p + 0x270, lbl_804A5620, 4);
    fn_801D22DC(p + 0x270, *(u32*)(p + 0x98), 2, 0);
}

extern "C" void* fn_801ED144(char* p) {
    fn_801D0F40(p);
    *(void**)p = lbl_804A5630;
    *(void**)(p + 0x2a8) = fn_80138A30(lbl_8053AAF8);
    *(u32*)(p + 0x2ac) = 0;
    *(s32*)(p + 0x2b0) = -1;
    *(u8*)(p + 0x2b4) = 0;
    fn_801ED974(p + 0x2b6);
    fn_80216178(p + 0x2b8);
    lbl_8053A160 = -1;
    return p;
}

extern "C" u8* fn_802D6A9C(void);
extern "C" s32 fn_80215E48(void* p, s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" f32* fn_8023E724(s32 i);
extern "C" f32* fn_8023E578(s32 i);
extern "C" void fn_801F0D20(void* p, s32 id);
extern "C" s32 fn_80215E98(void* p);
extern "C" void fn_80215FB8(void* p, s32 i, s32 k, f32 v);
extern "C" void fn_80215D8C(void* p, s32 i);
extern "C" u8 fn_80215C6C(void* p, s32 i);
extern "C" u8 fn_8021606C(void* p);
extern "C" void fn_801ECB08(char* p, s32 state);
extern int __float_max[];
extern const f32 lbl_8053F6C8;
extern const f32 lbl_8053F6CC;
extern const f32 lbl_8053F6D0;

struct HrmnQueue {
    s32 m0;
    bool isEmpty(s32 i) { bool r = fn_80215E48(this, i) >= 0; return r; }
    bool isFull() { return fn_80215E98(this) == m0; }
};

static inline f32 hrmn_clamp(f32 t) {
    if (t > lbl_8053F6B8) {
        t = lbl_8053F6B8;
    } else if (t < lbl_8053F6C0) {
        t = lbl_8053F6C0;
    }
    return t;
}

extern "C" void fn_801EC7B8(char* p) {
    u8 flags[4];
    f32 vals[4];
    flags[0] = 0;
    vals[0] = lbl_8053F6B8;
    flags[1] = 0;
    vals[1] = lbl_8053F6B8;
    flags[2] = 0;
    vals[2] = lbl_8053F6B8;
    flags[3] = 0;
    vals[3] = lbl_8053F6B8;
    s32 id = *(s32*)(p + 0x4);
    u8* fbase = flags;
    f32* vbase = vals;
    s32 count = 0;
    u8* cfg = fn_802D6A9C();
    f32* r;
    if (id < 8) {
        r = (f32*)(cfg + 0xcc);
    } else {
        r = (f32*)(cfg + 0xdc);
    }
    u8* fp = fbase;
    f32* vp = vbase;
    f32 xLim = lbl_8053F6C8 + r[0];
    f32 yLim = lbl_8053F6CC * (r[1] + r[3]);
    for (s32 i = 0; i < *(s32*)(p + 0x2a8); i++, fp++, vp++) {
        if (!((HrmnQueue*)(p + 0x2b8))->isEmpty(i)) {
            s32 myId = *(s32*)(p + 0x4);
            if (fn_8023DE58(i) == myId && fn_8023E724(i)[1] > yLim && fn_8023E724(i)[0] < xLim) {
                *fp = 1;
                f32 px = fn_8023E724(i)[0];
                f32 d = lbl_8053F6D0 * (px - fn_8023E578(i)[0]);
                f32 t = lbl_8053F6B8;
                f32 x = px - d;
                while (x < xLim) {
                    t -= lbl_8053F6D0;
                    x -= d;
                    if (t <= lbl_8053F6C0) {
                        break;
                    }
                }
                *vp = hrmn_clamp(t);
                count++;
            }
        }
    }
    if (count > 0) {
        fn_801F0D20(p, 0x3a);
        s32 k = fn_80215E98((HrmnQueue*)(p + 0x2b8));
        while (count > 0) {
            f32 best = *(f32*)__float_max;
            s32 bi = -1;
            u8* f = fbase;
            f32* v = vbase;
            for (s32 j = 0; j < *(s32*)(p + 0x2a8); j++, f++, v++) {
                if (*f && *v <= best) {
                    bi = j;
                    best = *v;
                }
            }
            fn_80215FB8((HrmnQueue*)(p + 0x2b8), bi, k, vals[bi]);
            fn_80215D8C((HrmnQueue*)(p + 0x2b8), bi);
            if (k == 0 && fn_80215C6C((HrmnQueue*)(p + 0x2b8), bi)) {
                *(u32*)(p + 0x230) |= 0x2000;
            }
            count--;
            flags[bi] = 0;
            k++;
        }
    }
    if (((HrmnQueue*)(p + 0x2b8))->isFull()) {
        fn_801ECB08(p, 0xb);
    } else if (fn_8021606C((HrmnQueue*)(p + 0x2b8))) {
        for (s32 i = 0; i < *(s32*)(p + 0x2a8); i++) {
            if (!((HrmnQueue*)(p + 0x2b8))->isEmpty(i)) {
                fn_80215D8C((HrmnQueue*)(p + 0x2b8), i);
            }
        }
        fn_801F0D20(p, 0x3b);
        fn_801ECB08(p, 0xb);
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
