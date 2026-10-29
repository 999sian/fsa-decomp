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
extern "C" void fn_801ECB08(char* p, s32 state);
extern "C" void fn_8022FEB8(f32* rect, u32 a, u32 b, u32 c, u32 d);
extern "C" void* fn_8022FD8C(void* h);
extern "C" u8 fn_8038AD24(s32 obj, s32 snd, u32 a, u32 b, f32* vals, s32 c);
extern "C" s32 fn_8037EFB4(s32 obj);
extern "C" u8 fn_8038470C(s32 obj, s32 msg);
extern "C" u8 fn_8023077C(void);
extern "C" s32 fn_8021C024(void* p);
extern "C" void fn_80215DB8(void* q);
extern "C" u8 fn_80215D38(void* q);
extern "C" s32 fn_80215E98(void* p);
extern "C" s32 fn_80215E58(void* p, s32 a);
extern "C" void fn_80215B6C(void* q, s32 a);
extern "C" void fn_80215BCC(void* q, s32 a);
extern "C" void fn_803894BC(s32 obj, s32 a);
extern "C" void fn_8022FE80(s32 obj, u32 a, u32 b, s32 c, s32 d);
extern "C" void fn_80230534(s32 a);
extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_802D7844(u8* cfg, s32 a, s32 i);
extern "C" u8 fn_8022F514(s32 i);
extern "C" s32 fn_8022F3DC(s32 i);
extern "C" f32* fn_8023E724(s32 i);
extern "C" void fn_80230498(s32 i, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0D20(void* p, s32 id);
extern "C" void fn_801EC7B8(char* p);
extern u32 lbl_80469CB8[];
extern "C" u8 fn_803865B8(void* obj);
extern "C" u8 fn_80384C58(void* obj, void* b);
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

class HrmnActor {
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
    virtual void v30(s32 a, s32 b);
    virtual u8 v34();
};

static inline void hrmnCameraFocus(char* p) {
    u8* cam = *(u8**)(lbl_8053AB10 + 0x24);
    if (!cam[0x7f5]) {
        cam[0x7f4] = 1;
        *(s32*)(cam + 0x7f8) = 4;
        *(f32*)(cam + 0x7fc) = *(f32*)(p + 0xc);
        *(f32*)(cam + 0x800) = *(f32*)(p + 0x10);
        *(f32*)(cam + 0x804) = *(f32*)(p + 0x14);
        cam[0x7f6] = 0;
    }
}

static inline void hrmnCameraLock(char* p) {
    char* cam = *(char**)(lbl_8053AB10 + 0x24);
    if (!cam[0x840]) {
        cam[0x840] = 1;
        *(f32*)(cam + 0x844) = *(f32*)(cam + 0x84c) = *(f32*)(p + 0xc);
        *(f32*)(cam + 0x848) = *(f32*)(cam + 0x850) = *(f32*)(p + 0x10);
        *(f32*)(cam + 0x854) = lbl_8053F6B8;
        *(f32*)(cam + 0x1d4) = lbl_8053F6C4;
        *(f32*)(cam + 0x1d8) = lbl_8053F6C4;
    }
}

extern "C" void fn_801EBE7C(char* p) {
    HrmnRect rect(*(f32*)(p + 0xc) - lbl_8053F6BC, *(f32*)(p + 0x10) - lbl_8053F6BC, lbl_8053F6BC + *(f32*)(p + 0xc), lbl_8053F6BC + *(f32*)(p + 0x10));
    switch (*(u32*)(p + 0x248)) {
    case 0: {
        fn_8022FEB8((f32*)&rect, *(u32*)(p + 0x4), *(u32*)(p + 0x198), 1, 0);
        *(s32*)(p + 0x2b0) = (s32)fn_8022FD8C(*(void**)(p + 0x198));
        if (*(s32*)(p + 0x2b0) < 0) {
            break;
        }
        s32 snd = 0x364;
        u8 ready = (*(u8 (**)(void*))((char*)*(void**)p + 0x34))(p);
        if (!ready) {
            snd = 0x35d;
        }
        f32 vals[3];
        vals[0] = lbl_8053F6C0;
        vals[1] = lbl_8053F6C0;
        vals[2] = lbl_8053F6C0;
        if (fn_8038AD24(*(s32*)(p + 0x2b0), snd, *(u32*)(p + 0x198), *(u32*)(p + 0x4), vals, 0)) {
            if (ready) {
                fn_801ECB08(p, 1);
            } else {
                fn_801ECB08(p, 2);
            }
        }
        break;
    }
    case 1:
        fn_8022FEB8((f32*)&rect, *(u32*)(p + 0x4), *(u32*)(p + 0x198), 1, 0);
        if (fn_803865B8(*(void**)(p + 0x2b0)) && fn_80384C58(*(void**)(p + 0x2b0), *(void**)(p + 0x198))) {
            *(s32*)(p + 0x98) = 2;
            fn_801ECB08(p, 0);
        }
        break;
    case 2:
        hrmnCameraFocus(p);
        fn_8022FEB8((f32*)&rect, *(u32*)(p + 0x4), *(u32*)(p + 0x198), 1, 0);
        if (fn_803865B8(*(void**)(p + 0x2b0))) {
            if (fn_8037EFB4(*(s32*)(p + 0x2b0)) == 0) {
                if (fn_8038470C(*(s32*)(p + 0x2b0), 0x35e)) {
                    fn_801ECB08(p, 3);
                }
            } else {
                if (fn_8038470C(*(s32*)(p + 0x2b0), 0x35f)) {
                    fn_801ECB08(p, 4);
                }
            }
        }
        break;
    case 3:
        hrmnCameraFocus(p);
        fn_8022FEB8((f32*)&rect, *(u32*)(p + 0x4), *(u32*)(p + 0x198), 1, 0);
        if (fn_803865B8(*(void**)(p + 0x2b0)) && fn_80384C58(*(void**)(p + 0x2b0), *(void**)(p + 0x198))) {
            if (fn_8023077C()) {
                fn_801ECB08(p, 6);
            } else {
                fn_801ECB08(p, 5);
            }
        }
        break;
    case 4:
        hrmnCameraFocus(p);
        fn_8022FEB8((f32*)&rect, *(u32*)(p + 0x4), *(u32*)(p + 0x198), 1, 0);
        if (fn_803865B8(*(void**)(p + 0x2b0)) && fn_80384C58(*(void**)(p + 0x2b0), *(void**)(p + 0x198))) {
            *(s32*)(p + 0x98) = 2;
            fn_801ECB08(p, 0);
        }
        break;
    case 5:
        hrmnCameraFocus(p);
        if (fn_8023077C()) {
            fn_801ECB08(p, 6);
        }
        break;
    case 6:
        hrmnCameraFocus(p);
        if (*(s32*)(p + 0x24c) >= 0x3c) {
            fn_801ECB08(p, 7);
        }
        break;
    case 7:
        if (*(s32*)(p + 0x24c) >= 0x3c) {
            fn_801ECB08(p, 8);
        }
        break;
    case 8:
        if (*(s32*)(p + 0x24c) >= 0x2d) {
            fn_801ECB08(p, 9);
        }
        break;
    case 9:
        if (*(s32*)(p + 0x24c) >= 0xb4) {
            fn_801ECB08(p, 10);
        } else if (*(s32*)(p + 0x24c) >= 0x78) {
            s32 base = fn_8021C024(p + 0x34c);
            for (s32 i = 0; i < 4; i++) {
                fn_80230498(i, fn_8023E724(i), base + 0x33a, 0xff, -0x80, -0x80, 1);
            }
        }
        break;
    case 10:
        fn_80215DB8(p + 0x2b8);
        fn_801EC7B8(p);
        break;
    case 11:
        fn_80215DB8(p + 0x2b8);
        if (*(s32*)(p + 0x24c) >= 0x1e) {
            if (fn_80215D38(p + 0x2b8)) {
                fn_801ECB08(p, 0xc);
            }
        } else if ((u8)(fn_80215E98(p + 0x2b8) == *(s32*)(p + 0x2b8))) {
            if (*(s32*)(p + 0x24c) == 0xf) {
                fn_801F0D20(p, 0x3a);
            }
        }
        break;
    case 12:
        if (*(s32*)(p + 0x24c) >= 0x3c) {
            fn_801ECB08(p, 0xd);
        }
        break;
    case 13:
        hrmnCameraLock(p);
        if (*(s32*)(p + 0x24c) >= 0x3c) {
            fn_801ECB08(p, 0xe);
        }
        break;
    case 14:
        hrmnCameraLock(p);
        fn_8022FE80(*(s32*)(p + 0x2b0), *(u32*)(p + 0x4), *(u32*)(p + 0x198), 0, 0);
        if (*(s32*)(p + 0x2b0) == (s32)fn_8022FD8C(*(void**)(p + 0x198))) {
            if (fn_80215E98(p + 0x2b8) == 0) {
                f32 vals[3];
                vals[0] = lbl_8053F6C0;
                vals[1] = lbl_8053F6C0;
                vals[2] = lbl_8053F6C0;
                if (fn_8038AD24(*(s32*)(p + 0x2b0), 0x365, *(u32*)(p + 0x198), *(u32*)(p + 0x4), vals, 2)) {
                    fn_801ECB08(p, 0x10);
                }
            } else {
                fn_803894BC(*(s32*)(p + 0x2b0), fn_80215E58(p + 0x2b8, 0) + 1);
                f32 vals[3];
                vals[0] = lbl_8053F6C0;
                vals[1] = lbl_8053F6C0;
                vals[2] = lbl_8053F6C0;
                if (fn_8038AD24(*(s32*)(p + 0x2b0), 0x366, *(u32*)(p + 0x198), *(u32*)(p + 0x4), vals, 2)) {
                    *(u8*)(p + 0x2b4) += 1;
                    fn_801ECB08(p, 0xf);
                }
            }
        }
        break;
    case 15:
        hrmnCameraLock(p);
        fn_8022FE80(*(s32*)(p + 0x2b0), *(u32*)(p + 0x4), *(u32*)(p + 0x198), 0, 0);
        if (fn_803865B8(*(void**)(p + 0x2b0))) {
            fn_80215B6C(p + 0x2b8, fn_80215E58(p + 0x2b8, *(u8*)(p + 0x2b4) - 1));
            if (*(u8*)(p + 0x2b4) >= fn_80215E98(p + 0x2b8)) {
                if (fn_8038470C(*(s32*)(p + 0x2b0), 0x36a)) {
                    fn_801ECB08(p, 0x10);
                }
            } else {
                fn_803894BC(*(s32*)(p + 0x2b0), fn_80215E58(p + 0x2b8, *(u8*)(p + 0x2b4)) + 1);
                if (fn_8038470C(*(s32*)(p + 0x2b0), lbl_80469CB8[*(u8*)(p + 0x2b4)])) {
                    *(u8*)(p + 0x2b4) += 1;
                }
            }
        }
        break;
    case 16:
        hrmnCameraLock(p);
        fn_8022FE80(*(s32*)(p + 0x2b0), *(u32*)(p + 0x4), *(u32*)(p + 0x198), 0, 0);
        if (fn_803865B8(*(void**)(p + 0x2b0)) && fn_80384C58(*(void**)(p + 0x2b0), *(void**)(p + 0x198))) {
            fn_80230534(0);
            for (s32 i = 0; i < 4; i++) {
                fn_802D7844(fn_802D6A9C(), 0, i);
            }
            if (*(u32*)(p + 0x230) & 0x2000) {
                s32 id = *(s32*)(p + 0x2b0);
                if (fn_8022F514(id)) {
                    id = fn_8022F3DC(*(s32*)(p + 0x2b0));
                }
                fn_80215BCC(p + 0x2b8, id);
            }
            (*(void (**)(void*, s32, s32))((char*)*(void**)p + 0x30))(p, 0xff, 1);
            fn_801ECB08(p, 0);
        }
        break;
    }
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

#pragma opt_lifetimes off
extern "C" void fn_801EC7B8(char* p) {
    struct Local {
        static inline bool eq(s32 a, s32 b) {
            return a == b;
        }
        static inline bool sameRoom(s32 roomId, s32 i) {
            return eq(fn_8023DE58(i), roomId);
        }
    };
    s32 count;
    s32 k;
    s32 i;
    s32 id;
    u8 flags[4];
    f32 vals[4];
    for (i = 0; i < 4; i++) {
        flags[i] = 0;
        vals[i] = 1.0f;
    }
    count = 0;
    id = *(s32*)(p + 0x4);
    u8* cfg = fn_802D6A9C();
    f32* r;
    if (id < 8) {
        r = (f32*)(cfg + 0xcc);
    } else {
        r = (f32*)(cfg + 0xdc);
    }
    f32 px;
    f32 xLim = 88.0f + r[0];
    f32 yLim = 0.5f * (r[1] + r[3]);
    for (i = 0; i < *(s32*)(p + 0x2a8); i++) {
        if (!((HrmnQueue*)(p + 0x2b8))->isEmpty(i)) {
            if (Local::sameRoom(*(s32*)(p + 0x4), i) && fn_8023E724(i)[1] > yLim && fn_8023E724(i)[0] < xLim) {
                flags[i] = 1;
                px = fn_8023E724(i)[0];
                f32 x = px - fn_8023E578(i)[0];
                f32 step = lbl_8053F6D0;
                f32 d = step * x;
                f32 t = 1.0f;
                x = px - d;
                while (x < xLim) {
                    t -= step;
                    x -= d;
                    if (t <= 0.0f) {
                        break;
                    }
                }
                if (t > 1.0f) {
                    t = 1.0f;
                } else if (t < 0.0f) {
                    t = 0.0f;
                }
                vals[i] = t;
                count++;
            }
        }
    }
    if (count > 0) {
        fn_801F0D20(p, 0x3a);
        k = fn_80215E98((HrmnQueue*)(p + 0x2b8));
        while (count > 0) {
            f32 best = *(f32*)__float_max;
            i = -1;
            for (s32 j = 0; j < *(s32*)(p + 0x2a8); j++) {
                if (flags[j] && vals[j] <= best) {
                    i = j;
                    best = vals[j];
                }
            }
            fn_80215FB8((HrmnQueue*)(p + 0x2b8), i, k, vals[i]);
            fn_80215D8C((HrmnQueue*)(p + 0x2b8), i);
            if (k == 0 && fn_80215C6C((HrmnQueue*)(p + 0x2b8), i)) {
                *(u32*)(p + 0x230) |= 0x2000;
            }
            count--;
            flags[i] = 0;
            k++;
        }
    }
    bool full = fn_80215E98((HrmnQueue*)(p + 0x2b8)) == *(s32*)(p + 0x2b8);
    if (full) {
        fn_801ECB08(p, 0xb);
    } else if (fn_8021606C((HrmnQueue*)(p + 0x2b8))) {
        for (s32 j = 0; j < *(s32*)(p + 0x2a8); j++) {
            if (!((HrmnQueue*)(p + 0x2b8))->isEmpty(j)) {
                fn_80215D8C((HrmnQueue*)(p + 0x2b8), j);
            }
        }
        fn_801F0D20(p, 0x3b);
        fn_801ECB08(p, 0xb);
    }
}
#pragma opt_lifetimes reset
extern "C" void* fn_801D0020(void* p, void* pos, s32 a, s32 b);
extern "C" void* fn_80119DD0(void);
extern "C" void fn_80119998(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern "C" void fn_80458F9C(void* a, s32 b);
extern "C" void fn_80458FF0(void* a, s32 b, s32 c, s32 d);
extern "C" void fn_802D8050(void* cfg, s32 id, s32 a, s32 b);
extern "C" u8 fn_80236B50(s32 i);
extern "C" void fn_8023764C(s32 i, s32 a);
extern "C" void fn_8022B064(void);
extern "C" void fn_8022AF78(void);
extern "C" s32 fn_801CD664(s32 n);
extern "C" u8 fn_8022F514(s32 i);
extern "C" s32 fn_8022F3DC(s32 i);
extern "C" void fn_80230498(s32 i, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80230BF4(s32 i, s32 a);
extern "C" void fn_802160F4(void* p);
extern "C" void fn_801ED968(void* p);
extern "C" void fn_80230534(s32 a);
extern "C" void fn_8021600C(void* p);
extern "C" s32 fn_80215E58(void* p, s32 a);
extern "C" void fn_80138B7C(void* p);
extern void* lbl_8053AF80;
extern const f32 lbl_8053F6D4;
extern const f32 lbl_8053F6D8;
extern const f32 lbl_8053F6DC;
extern const f32 lbl_8053F6E0;
extern "C" void fn_801ECB08(char* p, s32 state) {
    s32 rem;
    s32 i;
    f32* r;
    s32 n;
    s32* out;
    f32 pos7[3];
    s32 order[4];
    s32 pool[4];
    f32 pos13[3];
    switch (state) {
    case 0:
        *(s32*)(p + 0x2b0) = -1;
        *(u8*)(p + 0x2b4) = 0;
        *(u32*)(p + 0x230) &= ~0x2000;
        break;
    case 1:
    case 2:
        *(void**)(p + 0x98) = fn_801D0020(p, p + 0xc, *(s32*)(p + 0x2b0), 0);
        break;
    case 6:
        fn_80119998(fn_80119DD0(), 0x78, 0, 2, 0, 0, 0, 0);
        fn_80458F9C(lbl_8053AF80, 0x3c);
        break;
    case 7: {
        rem = *(s32*)(p + 0x2ac);
        if (rem != 0) {
            fn_802D8050(fn_802D6A9C(), rem, 1, 0xff);
        }
        for (rem = 0; rem < *(s32*)(p + 0x2a8); rem++) {
            if (fn_80236B50(rem)) {
                fn_8023764C(rem, 4);
            }
        }
        fn_8022B064();
        rem = *(s32*)(p + 0x4);
        u8* cfg = fn_802D6A9C();
        if (rem < 8) {
            r = (f32*)(cfg + 0xcc);
        } else {
            r = (f32*)(cfg + 0xdc);
        }
        n = *(s32*)(p + 0x2a8);
        out = order;
        pool[0] = order[0] = i = 0;
        order[1] = 1;
        pool[1] = 1;
        order[2] = 2;
        pool[2] = 2;
        order[3] = 3;
        pool[3] = 3;
        if (n >= 2) {
            if (n > 1) {
                rem = n;
                for (; i < n; i++, rem--) {
                    s32 j = fn_801CD664(rem);
                    *out = pool[j];
                    for (; j < rem - 1; j++) {
                        pool[j] = pool[j + 1];
                    }
                    out++;
                }
            }
        }
        for (rem = 0; rem < 4; rem++) {
            s32 id;
            if (fn_8022F514(rem)) {
                id = fn_8022F3DC(rem);
            } else {
                id = rem;
            }
            f32 y = lbl_8053F6D4 * (lbl_8053F6D8 + (f32)order[id]) + r[1];
            pos7[0] = lbl_8053F6DC + r[0];
            pos7[1] = y;
            pos7[2] = lbl_8053F6C0;
            fn_80230498(rem, pos7, 0x356, 0xff, -0x80, -0x80, 1);
            fn_80230BF4(rem, 0);
        }
        *(s32*)(p + 0x98) = 2;
        fn_802160F4(p + 0x2b8);
        break;
    }
    case 9:
        fn_801ED968(p + 0x2b6);
        break;
    case 10:
        fn_80230534(0);
        fn_801F0D20(p, 0x3a);
        fn_80458FF0(lbl_8053AF80, 0x1000007, 1, 0);
        fn_8021600C(p + 0x2b8);
        break;
    case 11: {
        s32 res = fn_80215E58(p + 0x2b8, 0);
        if (res >= 0) {
            *(s32*)(p + 0x2b0) = res;
        }
        break;
    }
    case 12:
        fn_80119998(fn_80119DD0(), 0x78, 0, 2, 0, 0, 0, 0);
        fn_80458F9C(lbl_8053AF80, 0x3c);
        break;
    case 13: {
        n = *(s32*)(p + 0x2ac);
        if (n != 0) {
            fn_802D8050(fn_802D6A9C(), n, 0, 0xff);
        }
        fn_8022AF78();
        for (rem = 0; rem < 4; rem++) {
            s32 id;
            if (fn_8022F514(rem)) {
                id = fn_8022F3DC(rem);
            } else {
                id = rem;
            }
            f32 y = lbl_8053F6E0 + *(f32*)(p + 0x10);
            pos13[0] = lbl_8053F6D4 * (f32)id + *(f32*)(p + 0xc);
            pos13[1] = y;
            pos13[2] = lbl_8053F6C0;
            fn_80230498(rem, pos13, 0x3f, 0xff, -0x80, -0x80, 1);
            fn_80230BF4(rem, 3);
        }
        fn_80138B7C(lbl_8053AAF8);
        break;
    }
    case 16:
        break;
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x248) = state;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
