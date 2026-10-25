#include "types.h"
extern "C" void fn_8041E8B4(u8*, s32);
extern "C" void fn_8041E3B4(u8*, u32);
extern "C" void fn_8041DD24(void*);
extern "C" void fn_8041D18C(u8*, s32);
extern "C" void fn_8041CC04(u8*);
extern "C" void fn_8041A868(u8*, s32);
extern "C" void fn_8041C0C0(u8*, s32);
extern "C" void fn_8041B69C(u8*);
extern "C" void fn_80419C38(u8*, s32, s32);
extern "C" void fn_80419570(u8*, s32);
extern "C" void fn_8041918C(u8*, s32);
extern "C" void fn_80418D08(u8*, s32, s32);
extern "C" u8 fn_80236B50(s32);
extern "C" u8 fn_80236890();
extern "C" void fn_801367E0(u8*, s32);
extern "C" void fn_80441490(void*);
extern f32 lbl_80543A1C;
extern f32 lbl_80543A20;
extern f32 lbl_80543A24;
extern f32 lbl_80543A28;
extern f32 lbl_80543A2C;
extern f32 lbl_80543A30;
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/JUtility/JUTVideo.h"
#include "JSystem/J2D/J2DGrafContext.h"
#include "JSystem/J2D/J2DPicture.h"


extern u8* lbl_8053AAF8;
extern u8 lbl_8050EC80[];
extern u8 lbl_80529DEC[];
extern "C" u32 fn_80237774(s32 i);
extern "C" u8 fn_8022F514(s32 i);
extern "C" s32 fn_8022F3DC(s32 i);
extern "C" u32 fn_80236100(s32 i);
extern "C" u32 fn_802375B0(s32 i);
extern u8* lbl_8053AED0;
extern u8* lbl_8053AEC8;
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_8022AF5C(void);
extern "C" u8 fn_8022B1AC(void);
extern "C" u8 fn_8022B160(void);
extern "C" s32 fn_80138A30(u8* game);
extern "C" s32 fn_8022EA0C(s32);
extern "C" void* fn_8023E724();
extern "C" void fn_8030C5F0(void*, void*, s32, s32, f32*);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8* lbl_8053AB10;
extern "C" u8* sManager__8JUTVideo;
extern u64 lbl_8048DDD0[];
extern u32 lbl_804B139C[];
extern "C" s32 fn_802366CC(void);
extern "C" u32 fn_804030C4(u32 tag, u32 id);
extern "C" void fn_80230EB8(s32 i, s32 id);
extern "C" void fn_80230FD0(s32 i, s32 id);
extern "C" u32 fn_80237810(s32 i);
extern u8 lbl_8050DB0C[];
extern u64 lbl_8048D320[];
extern f32 lbl_80543A0C;
extern f32 lbl_80543A00;

static inline u8 HudPlayerActive8041(s32 index) {
    u8 mask = 1 << index;
    return (lbl_8053AAF8[0x82] & mask) != 0;
}
// Sub-object virtual slots 13 called by fn_8041918C.
struct SubObj {
    virtual void w00();
    virtual void w01();
    virtual void w02();
    virtual void w03();
    virtual void w04();
    virtual void w05();
    virtual void w06();
    virtual void w07(s32 v);
    virtual void w08();
    virtual void w09();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual SubObj* w13(u64 x);
};

typedef void (*Slot68Fn)(u8* self, u32 a, u32 b);

// Virtual slot 68 of object returned by SubObj::w13: calls (u32, 0).
static inline void CallSlot68(u8* obj, u32 s) {
    void** vtbl = *(void***)obj;
    ((Slot68Fn)vtbl[68])(obj, s, 0);
}

typedef u8* (*SearchByName)(u8* screen, u64 name);

// Looks up a pane by 8-char name on a J2DScreen and sets its visibility byte.
static inline void SetPaneVisible(u8* screen, u64 name, u8 vis) {
    u8* pane = ((SearchByName)(*(void***)screen)[15])(screen, name);
    pane[0xb0] = vis;
}

static inline void SetPaneVisibleOfSub(u8* self, u64 name, u8 vis) {
    SetPaneVisible(*(u8**)(self + 4), name, vis);
}

static inline u8* FindPaneOfSub(u8* self, u64 name) {
    u8* sub = *(u8**)(self + 4);
    return ((SearchByName)(*(void***)sub)[15])(sub, name);
}

typedef void (*PaneFloatsFn)(u8* self, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h);

static inline void PaneSetFloats(u8* pane, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h) {
    ((PaneFloatsFn)(*(void***)pane)[65])(pane, a, b, c, d, e, f, g, h);
}

typedef void (*PaneColorsFn)(u8* self, void* a, void* b);

// Sets the digit pane pair idx (names at 0x338 and 0x360 tables) to the glyph tag.
static inline void SetDigitPanes(u8* self, s32 idx, u32 tag) {
    CallSlot68(FindPaneOfSub(self, lbl_8048D320[0x67 + idx]), tag);
    CallSlot68(FindPaneOfSub(self, lbl_8048D320[0x6c + idx]), tag);
}

extern "C" s32 fn_80418B64(u8* self) {
    f32 buf[3];
    fn_8022EA0C(0);
    void* p = fn_8023E724();
    fn_8030C5F0(*(void**)(lbl_8053AB10 + 0x24), p, 0, 0, buf);
    if (fn_8023DE58(0) >= 8) {
        self[0x218] = 1;
    } else {
        if (buf[1] < 0.33333334f * (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6)) {
            self[0x218] = 0;
        } else if (buf[1] > 0.6666667f * (f32)(s32)*(u16*)(*(u8**)(sManager__8JUTVideo + 4) + 6)) {
            self[0x218] = 1;
        }
    }
    s32 r;
    if (self[0x218] != 0) {
        u8 b = lbl_8053AED0[0xdc];
        if (((b >> 0) & 1) == 1) {
            if (((b >> 1) & 1) == 1) {
                if (((b >> 2) & 1) == 1) {
                    if (((b >> 3) & 1) == 1) r = 4;
                    else r = 3;
                } else r = 1;
            } else r = 2;
        } else r = 0;
    } else {
        u8 b = lbl_8053AED0[0xdc];
        if (((b >> 2) & 1) == 1) {
            if (((b >> 3) & 1) == 1) {
                if (((b >> 0) & 1) == 1) {
                    if (((b >> 1) & 1) == 1) r = 4;
                    else r = 2;
                } else r = 0;
            } else r = 3;
        } else r = 1;
    }
    return r;
}

extern "C" void fn_80418D08(u8* self, s32 idx, s32 flag) {
    u64* base = lbl_8048D320;
    s32 off = idx * 4;
    u8* p = self + off;
    u8 mask = (u8)(1 << idx);
    f32 v31 = *(f32*)(p + 0x128);
    f32 v30 = *(f32*)(p + 0x168);

    s32 t = (self[0x28f] & mask) != 0;
    if (t == 0) {
        if (v31 > 0.0f) {
            *(f32*)(p + 0x128) = v31 - 0.1f;
        } else {
            *(f32*)(p + 0x128) = 0.0f;
        }
        u8* q = *(u8**)(lbl_8053AB10 + 0x20);
        q[idx + 0x217] = 1;
    } else {
        if (*(s32*)(lbl_80529DEC + off + 0xd8) == 0 && lbl_8053AEC8[0x5e] == 0) {
            if (v31 > 0.6f) {
                *(f32*)(p + 0x128) = v31 - 0.1f;
                if (!(*(f32*)(p + 0x128) <= 0.6f)) {
                    *(f32*)(p + 0x128) = 0.6f;
                }
            } else if (v31 < 0.6f) {
                *(f32*)(p + 0x128) = v31 + 0.1f;
                if (!(*(f32*)(p + 0x128) >= 0.6f)) {
                    *(f32*)(p + 0x128) = 0.6f;
                }
            }
        } else {
            if (v31 < 1.0f) {
                *(f32*)(p + 0x128) = v31 + 0.1f;
            } else {
                *(f32*)(p + 0x128) = 1.0f;
            }
        }
    }

    if (v31 != *(f32*)(p + 0x128) || (u8)flag != 0) {
        if ((self[0x28f] & mask) == 0 && fn_8022B1AC() == 0) {
            if (v30 > 0.0f) {
                *(f32*)(p + 0x168) = v30 - 0.1f;
            } else {
                *(f32*)(p + 0x168) = 0.0f;
            }
        } else {
            if (*(s32*)(lbl_80529DEC + off + 0xd8) == 0 && lbl_8053AEC8[0x5e] == 0) {
                if (v30 > 0.6f) {
                    *(f32*)(p + 0x168) = v30 - 0.1f;
                    if (!(*(f32*)(p + 0x168) <= 0.6f)) {
                        *(f32*)(p + 0x168) = 0.6f;
                    }
                } else if (v30 < 0.6f) {
                    *(f32*)(p + 0x168) = v30 + 0.1f;
                    if (!(*(f32*)(p + 0x168) >= 0.6f)) {
                        *(f32*)(p + 0x168) = 0.6f;
                    }
                }
            } else {
                if (v30 < 1.0f) {
                    *(f32*)(p + 0x168) = v30 + 0.1f;
                } else {
                    *(f32*)(p + 0x168) = 1.0f;
                }
            }
        }

        if (v31 != *(f32*)(p + 0x128) || v30 != *(f32*)(p + 0x168) || (u8)flag != 0) {
            u64* t0 = base + 0x184;
            u64* t1 = base + 0x194;
            u64* t2 = base + 0x18c;
            u64* t3 = base + 0x19c;
            s32 k;
            for (k = 0; k < 8; k++) {
                u8* pane = ((SearchByName)(*(void***)(*(u8**)(p + 8)))[15])(*(u8**)(p + 8), t0[k]);
                ((void (*)(u8*, s32))(*(void***)pane)[9])(pane, (s32)((f32)(u32)self[0x250] * *(f32*)(p + 0x128)));
                pane = ((SearchByName)(*(void***)(*(u8**)(p + 8)))[15])(*(u8**)(p + 8), t1[k]);
                ((void (*)(u8*, s32))(*(void***)pane)[9])(pane, (s32)((f32)(u32)self[0x251] * *(f32*)(p + 0x128)));
                pane = ((SearchByName)(*(void***)(*(u8**)(p + 8)))[15])(*(u8**)(p + 8), t2[k]);
                ((void (*)(u8*, s32))(*(void***)pane)[9])(pane, (s32)((f32)(u32)self[0x252] * *(f32*)(p + 0x128)));
                pane = ((SearchByName)(*(void***)(*(u8**)(p + 8)))[15])(*(u8**)(p + 8), t3[k]);
                ((void (*)(u8*, s32))(*(void***)pane)[9])(pane, (s32)((f32)(u32)self[0x253] * *(f32*)(p + 0x128)));
            }
            u64* t4 = base + 0x156;
            for (k = 0; k < 6; k++) {
                u8* pane = ((SearchByName)(*(void***)(*(u8**)(p + 0x2c)))[15])(*(u8**)(p + 0x2c), t4[k]);
                ((void (*)(u8*, s32))(*(void***)pane)[9])(pane, (s32)((f32)(u32)self[0x27b + k] * *(f32*)(p + 0x168)));
            }
        }
    }
}

extern "C" void fn_8041918C(u8* this_, s32 idx) {
    u8* q;
    s32 n;

    fn_8022EA0C(idx);
    if (fn_802366CC() > 0) {
        fn_8022EA0C(idx);
        if (fn_802366CC() < 300) {
            fn_8022EA0C(idx);
            n = fn_802366CC() / 60 + 1;
            q = this_ + idx;
            if (n != q[0x294]) {
                if (n > 99) {
                    n = 99;
                }
                if (n < 0) {
                    n = 0;
                }
                if (n < 10) {
                    u32 s = fn_804030C4(0x54494d47, lbl_804B139C[n]);
                    u8* p = this_ + idx * 4;
                    CallSlot68((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[0]), s);
                    CallSlot68((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[1]), s);
                    if (((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[2]))[0xb0] == 1) {
                        ((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[2]))[0xb0] = 0;
                        ((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[3]))[0xb0] = 0;
                    }
                } else {
                    u32 s = fn_804030C4(0x54494d47, lbl_804B139C[n / 10]);
                    u8* p = this_ + idx * 4;
                    CallSlot68((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[0]), s);
                    CallSlot68((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[1]), s);
                    s = fn_804030C4(0x54494d47, lbl_804B139C[n % 10]);
                    CallSlot68((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[2]), s);
                    CallSlot68((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[3]), s);
                    if (((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[2]))[0xb0] == 0) {
                        ((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[2]))[0xb0] = 1;
                        ((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[3]))[0xb0] = 1;
                    }
                }
                q[0x294] = n;
            }
        } else {
            this_[idx + 0x294] = 0;
        }
    } else {
        this_[idx + 0x294] = 0;
    }
    if (*(s16*)(this_ + idx * 2 + 0x234) > 0) {
        *(s16*)(this_ + idx * 2 + 0x234) = *(s16*)(this_ + idx * 2 + 0x234) - 1;
    }
}

extern "C" void fn_80419570(u8* self, s32 idx) {
    s16* timer = (s16*)(self + idx * 2);
    if (timer[0x10d] == 0) {
        ((u32*)(self + 0x1d8))[idx] = fn_80237774(idx);
        ((u32*)(self + 0x1f8))[idx] = fn_80237810(idx);
    } else {
        s32 cnt = ((s32*)(self + 0x1f8))[idx];
        s32 n = ((s32*)(self + 0x1d8))[idx];
        if (cnt > 0x20) cnt = 0x20;
        if (cnt < 0) cnt = 0;
        if (cnt < n) n = cnt;
        if (n < 0) n = 0;
        u8* base = (u8*)lbl_8048D320;
        u64* a = (u64*)(base + 0xc20);
        u64* b = (u64*)(base + 0xca0);
        u64* c = (u64*)(base + 0xc60);
        u64* d = (u64*)(base + 0xce0);
        for (s32 k = 0; k < 8; k++) {
            if (n >= 4) {
                SetPaneVisible(*(u8**)(self + idx * 4 + 8), *a, 1);
                SetPaneVisible(*(u8**)(self + idx * 4 + 8), *b, 1);
                PaneSetFloats(((SearchByName)(*(void***)*(u8**)(self + idx * 4 + 8))[15])(*(u8**)(self + idx * 4 + 8), *a), 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                PaneSetFloats(((SearchByName)(*(void***)*(u8**)(self + idx * 4 + 8))[15])(*(u8**)(self + idx * 4 + 8), *b), 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                SetPaneVisible(*(u8**)(self + idx * 4 + 8), *c, 0);
                SetPaneVisible(*(u8**)(self + idx * 4 + 8), *d, 0);
                cnt -= 4;
                n -= 4;
            } else {
                if (n == 0) {
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *a, 0);
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *b, 0);
                    if (cnt > 0) {
                        SetPaneVisible(*(u8**)(self + idx * 4 + 8), *c, 1);
                        SetPaneVisible(*(u8**)(self + idx * 4 + 8), *d, 1);
                        cnt -= 4;
                    } else {
                        SetPaneVisible(*(u8**)(self + idx * 4 + 8), *c, 0);
                        SetPaneVisible(*(u8**)(self + idx * 4 + 8), *d, 0);
                    }
                } else if (n == 1) {
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *a, 1);
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *b, 1);
                    PaneSetFloats(((SearchByName)(*(void***)*(u8**)(self + idx * 4 + 8))[15])(*(u8**)(self + idx * 4 + 8), *a), 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    PaneSetFloats(((SearchByName)(*(void***)*(u8**)(self + idx * 4 + 8))[15])(*(u8**)(self + idx * 4 + 8), *b), 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *c, 0);
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *d, 0);
                    cnt -= 4;
                } else if (n == 2) {
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *a, 1);
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *b, 1);
                    PaneSetFloats(((SearchByName)(*(void***)*(u8**)(self + idx * 4 + 8))[15])(*(u8**)(self + idx * 4 + 8), *a), 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    PaneSetFloats(((SearchByName)(*(void***)*(u8**)(self + idx * 4 + 8))[15])(*(u8**)(self + idx * 4 + 8), *b), 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *c, 0);
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *d, 0);
                    cnt -= 4;
                } else if (n == 3) {
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *a, 1);
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *b, 1);
                    PaneSetFloats(((SearchByName)(*(void***)*(u8**)(self + idx * 4 + 8))[15])(*(u8**)(self + idx * 4 + 8), *a), 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    PaneSetFloats(((SearchByName)(*(void***)*(u8**)(self + idx * 4 + 8))[15])(*(u8**)(self + idx * 4 + 8), *b), 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *c, 0);
                    SetPaneVisible(*(u8**)(self + idx * 4 + 8), *d, 0);
                    cnt -= 4;
                }
                n = 0;
            }
            a++;
            b++;
            c++;
            d++;
        }
        timer[0x10d]--;
    }
}

extern "C" f32 fn_8043D57C(u8* obj);
extern "C" f32 fn_8043D514(u8* obj);
extern "C" void fn_80402E08(u8* obj, f32 a, f32 b);
extern "C" void fn_8037EB4C(void);
extern "C" void fn_80419C38(u8* self, s32 idx, s32 flag) {
    u8* p = self + (idx << 2);
    f32 v29 = *(f32*)(p + 0x118);
    f32 v30 = *(f32*)(p + 0x138);
    f32 v31 = *(f32*)(p + 0x148);
    if (idx >= 2) {
        fn_80402E08(*(u8**)(p + 0x74), *(f32*)(p + 0xf8), fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0x84), lbl_80543A00, fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0x94), lbl_80543A00, fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xa4), lbl_80543A00, fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xb4), *(f32*)(p + 0xf8), fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xc4), *(f32*)(p + 0xf8), fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xd4), *(f32*)(p + 0xf8), fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xe4), *(f32*)(p + 0xf8), fn_8043D57C(lbl_8053AED0));
    } else {
        fn_80402E08(*(u8**)(p + 0x74), *(f32*)(p + 0xf8), fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0x84), lbl_80543A00, fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0x94), lbl_80543A00, fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xa4), lbl_80543A00, fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xb4), *(f32*)(p + 0xf8), fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xc4), *(f32*)(p + 0xf8), fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xd4), *(f32*)(p + 0xf8), fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xe4), *(f32*)(p + 0xf8), fn_8043D514(lbl_8053AED0));
    }
    fn_8037EB4C();
}

extern "C" void fn_8041A868(u8* self, s32 arg) {
    s32 flag = (lbl_8053AAF8[0x83] & 3) == 2;
    s32 r25 = 0;
    s32 r = fn_80418B64(self);
    if (*(s16*)(self + 0x222) != (s16)r) {
        if (*(f32*)(self + 0x118) > 0.0f) {
            r25 = 1;
        } else {
            *(s16*)(self + 0x222) = (s16)r;
        }
    }
    s32 off = flag * 10;
    (void)off;
    (void)r25;
}

extern const u64 lbl_8048DE00[];
extern const u64 lbl_8048DE20[];
extern "C" void fn_8041B69C(u8* self) {
    const u64* names;
    s32 count=0;
    s32 assigned=0;
    s32 rank[4];
    s32 used[4];
    if ((self[0x28B]&1) || (self[0x28B]&2) || (self[0x28B]&4) || (self[0x28B]&8)) {
        if (self[0x28E]==0) {
            self[0x28E]=1;
            return;
        }
        names=lbl_8048DE00;
        for (s32 i=0;i<4;i++) {
            rank[i]=0;
            used[i]=0;
            if (lbl_8053AAF8[0x82] & (u8)(1<<i)) {
                if (lbl_8050EC80[*(s32*)(lbl_8050EC80+0x10)*0xC8+0x88]!=0) {
                    (*(J2DScreen**)(self+0x18))->search(names[i])->show();
                } else {
                    (*(J2DScreen**)(self+0x18))->search(names[i])->hide();
                }
                count++;
            }
        }
        do {
            s32 number;
            s32 highest;
            highest=-5001;
            number=0;
            for (s32 i=0;i<count;i++) {
                if (used[i]==0 && highest < (s32)fn_80236100(i))
                    highest=(s32)fn_80236100(i);
            }
            for (s32 i=0;i<count;i++) {
                if (used[i]==0 && highest==(s32)fn_80236100(i)) {
                    rank[i]=assigned;
                    number++;
                    used[i]=1;
                }
            }
            assigned+=number;
        } while (assigned<count);
        const u64* colorNames=lbl_8048DE20;
        for (s32 i=0;i<count;i++) {
            switch (rank[i]) {
            case 0:
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(colorNames[i]))->setWhite(JUtility::TColor(0xff,0xff,0xff,0xff));
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(colorNames[i]))->setCornerColor(JUtility::TColor(0xb9,0x12,0x12,0xff),JUtility::TColor(0xd8,0x3a,0x16,0xff),JUtility::TColor(0xb9,0x54,0x12,0xff),JUtility::TColor(0xff,0x9d,0x10,0xff));
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(names[i]))->setBlendRatio(1.0f,0.0f,0.0f,0.0f,1.0f,1.0f,1.0f,1.0f);
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(colorNames[i]))->setBlendRatio(1.0f,0.0f,0.0f,0.0f,1.0f,1.0f,1.0f,1.0f);
                break;
            case 1:
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(colorNames[i]))->setWhite(JUtility::TColor(0xff,0xff,0xff,0xff));
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(colorNames[i]))->setCornerColor(JUtility::TColor(0xf2,0x48,0x9,0xff),JUtility::TColor(0xf2,0x48,0x9,0xff),JUtility::TColor(0xf2,0xab,0x24,0xff),JUtility::TColor(0xfc,0xff,0x21,0xff));
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(names[i]))->setBlendRatio(0.0f,1.0f,0.0f,0.0f,1.0f,1.0f,1.0f,1.0f);
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(colorNames[i]))->setBlendRatio(0.0f,1.0f,0.0f,0.0f,1.0f,1.0f,1.0f,1.0f);
                break;
            case 2:
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(colorNames[i]))->setWhite(JUtility::TColor(0xff,0xff,0x77,0xff));
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(colorNames[i]))->setCornerColor(JUtility::TColor(0xff,0xff,0xff,0xff),JUtility::TColor(0xff,0xff,0xff,0xff),JUtility::TColor(0xff,0xff,0xff,0xff),JUtility::TColor(0xff,0xff,0xff,0xff));
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(names[i]))->setBlendRatio(0.0f,0.0f,1.0f,0.0f,1.0f,1.0f,1.0f,1.0f);
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(colorNames[i]))->setBlendRatio(0.0f,0.0f,1.0f,0.0f,1.0f,1.0f,1.0f,1.0f);
                break;
            case 3:
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(colorNames[i]))->setWhite(JUtility::TColor(0xd8,0xff,0xa1,0xff));
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(colorNames[i]))->setCornerColor(JUtility::TColor(0xff,0xff,0xff,0xff),JUtility::TColor(0xff,0xff,0xff,0xff),JUtility::TColor(0xff,0xff,0xff,0xff),JUtility::TColor(0xff,0xff,0xff,0xff));
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(names[i]))->setBlendRatio(0.0f,0.0f,0.0f,1.0f,1.0f,1.0f,1.0f,1.0f);
                ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(colorNames[i]))->setBlendRatio(0.0f,0.0f,0.0f,1.0f,1.0f,1.0f,1.0f,1.0f);
                break;
            }
        }
    }
}

extern "C" void fn_8041C0C0(u8* self, s32 idx) {
    u8* base = (u8*)lbl_8048D320;
    s32 n;
    s32 which;
    s32 i;
    u32 tag;

    if (self[0x28b] & (u8)(1 << idx)) {
        which = 0;
        n = *(s32*)(lbl_80529DEC + idx * 4 + 0xe8);
        if (n > 9999) {
            n = 9999;
        }
        if (n < 0) {
            u8* p = base + 0x3b8 + idx * 0x28;
            for (i = 0; i < 5; i++) {
                GXColor col;
                GXColor zero;
                col.r = 0xff;
                col.g = 0x55;
                col.b = 0x41;
                col.a = 0xff;
                zero.r = 0;
                zero.g = 0;
                zero.b = 0;
                zero.a = 0;
                u8* obj = FindPaneOfSub(self, *(u64*)p);
                ((PaneColorsFn)(*(void***)obj)[76])(obj, &zero, &col);
                p += 8;
            }
            if (n < -5000) {
                n = -5000;
            }
            n = -n;
            tag = fn_804030C4(0x54494d47, (u32)(base + 0xe38));
            CallSlot68(FindPaneOfSub(self, *(u64*)(base + 0x3b8 + idx * 0x28)), tag);
            CallSlot68(FindPaneOfSub(self, *(u64*)(base + 0x458 + idx * 0x28)), tag);
            SetPaneVisibleOfSub(self, *(u64*)(base + 0x3b8 + idx * 0x28 + 0x20), 1);
            SetPaneVisibleOfSub(self, *(u64*)(base + 0x458 + idx * 0x28 + 0x20), 1);
            which = 1;
        } else {
            for (i = 0; i < 5; i++) {
                u32 a = *(u32*)(self + 0x244);
                u32 b = *(u32*)(self + 0x248);
                u8* obj = FindPaneOfSub(self, *(u64*)(base + 0x3b8 + idx * 0x28 + i * 8));
                ((PaneColorsFn)(*(void***)obj)[76])(obj, &b, &a);
            }
            SetPaneVisibleOfSub(self, *(u64*)(base + 0x3b8 + idx * 0x28 + 0x20), 0);
            SetPaneVisibleOfSub(self, *(u64*)(base + 0x458 + idx * 0x28 + 0x20), 0);
        }

        tag = fn_804030C4(0x54494d47, lbl_804B139C[n / 1000]);
        CallSlot68(FindPaneOfSub(self, *(u64*)(base + 0x3b8 + idx * 0x28 + which * 8)), tag);
        CallSlot68(FindPaneOfSub(self, *(u64*)(base + 0x458 + idx * 0x28 + which * 8)), tag);
        n %= 1000;
        tag = fn_804030C4(0x54494d47, lbl_804B139C[n / 100]);
        CallSlot68(FindPaneOfSub(self, *(u64*)(base + 0x3b8 + idx * 0x28 + (which + 1) * 8)), tag);
        CallSlot68(FindPaneOfSub(self, *(u64*)(base + 0x458 + idx * 0x28 + (which + 1) * 8)), tag);
        n %= 100;
        tag = fn_804030C4(0x54494d47, lbl_804B139C[n / 10]);
        CallSlot68(FindPaneOfSub(self, *(u64*)(base + 0x3b8 + idx * 0x28 + (which + 2) * 8)), tag);
        CallSlot68(FindPaneOfSub(self, *(u64*)(base + 0x458 + idx * 0x28 + (which + 2) * 8)), tag);
        n %= 10;
        tag = fn_804030C4(0x54494d47, lbl_804B139C[n]);
        CallSlot68(FindPaneOfSub(self, *(u64*)(base + 0x3b8 + idx * 0x28 + (which + 3) * 8)), tag);
        CallSlot68(FindPaneOfSub(self, *(u64*)(base + 0x458 + idx * 0x28 + (which + 3) * 8)), tag);
    }
}

extern u64 lbl_8048D320[];
extern u32 lbl_804B13C4;
extern u8 lbl_8050EC80[];
extern "C" void fn_80419C38(u8* self, s32 i, s32 v);
extern "C" void fn_8041C67C(u8* this_) {
	u64* base = lbl_8048D320;
	u8* self = this_;
	s32 i;
	SetPaneVisibleOfSub(self, 0x004E646174613133ULL, 0);
	SetPaneVisibleOfSub(self, 0x506870316E693032ULL, 0);
	SetPaneVisibleOfSub(self, 0x5068317069696233ULL, 0);
	SetPaneVisibleOfSub(self, 0x004E646174613136ULL, 0);
	SetPaneVisibleOfSub(self, 0x004E646174613032ULL, 0);
	u64* p20 = &base[0x15c];
	u64* p29 = p20;
	u64* p28 = &base[0x164];
	u64* p27 = &base[0x168];
	u64* p26 = &base[0x16c];
	u64* p25 = &base[0x170];
	u64* p24 = &base[0x178];
	u64* p23 = &base[0x17c];
	u64* p22 = &base[0x180];
	u64* p21 = &base[0x13b];

	for (i = 0; i < 4; i++) {
		if (lbl_8053AAF8[0x82] & (1 << i)) {
			((u8*)((SubObj*)*(u8**)(self + 0x18))->w13(*p29))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 0x18))->w13(*p28))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(*p27))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(*p26))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(*p25))[0xb0] = 1;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(*p24))[0xb0] = 1;
			if (lbl_8050EC80[*(u32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x88]) {
				((u8*)((SubObj*)*(u8**)(self + 4))->w13(*p23))[0xb0] = 1;
			} else {
				((u8*)((SubObj*)*(u8**)(self + 4))->w13(*p23))[0xb0] = 0;
			}
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(*p22))[0xb0] = 1;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(p21[0]))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(p21[1]))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(p21[2]))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(p21[3]))[0xb0] = 0;
		} else {
			((u8*)((SubObj*)*(u8**)(self + 0x18))->w13(*p29))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 0x18))->w13(*p28))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(*p27))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(*p26))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(*p25))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(*p24))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(*p23))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(self + 4))->w13(*p22))[0xb0] = 0;
		}
		p29++;
		p28++;
		p27++;
		p26++;
		p25++;
		p24++;
		p23++;
		p22++;
		p21 += 4;
	}

	u64* q22 = &base[0x160];
	u32 s = fn_804030C4(0x54494d47, lbl_804B13C4);
	for (i = 0; i < 4; i++) {
		((void (*)(u8*, u32, u32))(*(u32**)((SubObj*)*(u8**)(self + 0x18))->w13(*p20))[68])((u8*)((SubObj*)*(u8**)(self + 0x18))->w13(*p20), s, 0);
		p20++;
		q22++;
	}

	for (i = 0; i < 4; i++) {
		if (lbl_8053AAF8[0x82] & (1 << i)) {
			fn_80419C38(self, i, 1);
		}
	}
}

extern "C" void fn_8041CC04(u8* self) {
    u8* base = (u8*)lbl_8048D320;
    s32 n;
    s32 which;
    s32 i;
    u8* p;
    u32 tag;

    if (self[0x28b] & 1) {
        which = 0;
        s32 v = *(s32*)(lbl_80529DEC + 0xe8);
        n = v;
        if (v > 9999) {
            n = 9999;
        }
        if (n < 0) {
            p = base + 0x338;
            for (i = 0; i < 5; i++) {
                GXColor col;
                GXColor zero;
                col.r = 0xff;
                col.g = 0x55;
                col.b = 0x41;
                col.a = 0xff;
                zero.r = 0;
                zero.g = 0;
                zero.b = 0;
                zero.a = 0;
                u8* obj = FindPaneOfSub(self, *(u64*)p);
                ((PaneColorsFn)(*(void***)obj)[76])(obj, &zero, &col);
                p += 8;
            }
            if (n < -5000) {
                n = -5000;
            }
            n = -n;
            tag = fn_804030C4(0x54494d47, (u32)(base + 0xe38));
            SetDigitPanes(self, 0, tag);
            SetPaneVisibleOfSub(self, *(u64*)(base + 0x338 + 0x20), 1);
            SetPaneVisibleOfSub(self, *(u64*)(base + 0x360 + 0x20), 1);
            which = 1;
        } else {
            for (i = 0; i < 5; i++) {
                u32 a = *(u32*)(self + 0x244);
                u32 b = *(u32*)(self + 0x248);
                u8* obj = FindPaneOfSub(self, *(u64*)(base + 0x338 + i * 8));
                ((PaneColorsFn)(*(void***)obj)[76])(obj, &b, &a);
            }
            SetPaneVisibleOfSub(self, *(u64*)(base + 0x338 + 0x20), 0);
            SetPaneVisibleOfSub(self, *(u64*)(base + 0x360 + 0x20), 0);
        }

        tag = fn_804030C4(0x54494d47, lbl_804B139C[n / 1000]);
        n = n % 1000;
        SetDigitPanes(self, which, tag);

        tag = fn_804030C4(0x54494d47, lbl_804B139C[n / 100]);
        n = n % 100;
        SetDigitPanes(self, which + 1, tag);

        tag = fn_804030C4(0x54494d47, lbl_804B139C[n / 10]);
        n = n % 10;
        SetDigitPanes(self, which + 2, tag);

        tag = fn_804030C4(0x54494d47, lbl_804B139C[n]);
        SetDigitPanes(self, which + 3, tag);
    }
}

extern u8* lbl_8053AD30;
extern "C" u8 fn_80230188(s32);
extern "C" u8 fn_8023BE0C(void);
extern "C" u32 fn_8030AAF4(s32);
extern "C" s32 fn_80309D24(u8*, u32, s32);
extern "C" void fn_8041D18C(u8* self, s32 index) {
    typedef u8* (*Call3Fn)(u8*, u32, u32, u32);
    u8 mask = (u8)(1 << index);
    u8* sub = *(u8**)(self + 4);

    if (lbl_8053AAF8[0x7e] == 0) {
        if ((self[0x28d] & mask) == 0 && fn_80230188(index) == 0) {
            fn_8022EA0C(index);
            if (fn_8023BE0C() != 0 && (lbl_8053AED0[0x255] & mask) == 0) {
                self[0x28d] |= mask;
                u8* o = ((Call3Fn)(*(void***)sub)[15])(sub, 0x6e690000, 0x50687031, 0x6e693032);
                o[0xb0] = 1;
            }
        } else {
            u32 pid = fn_8030AAF4(index);
            if (fn_80309D24(lbl_8053AD30, pid, 0x100) == 0 || (lbl_8053AED0[0x255] & mask) != 0 || fn_80230188(index) != 0) {
                self[0x28d] &= ~mask;
                u8* o = ((Call3Fn)(*(void***)sub)[15])(sub, 0x6e690000, 0x50687031, 0x6e693032);
                o[0xb0] = 0;
            }
        }
    }
}

extern "C" void fn_8041DD24(void* this_) {
    s32 cnt;
    u8* self = (u8*)this_;
    u8* base;
    s32 n;
    u64* p28;
    u64* p29;
    u64* p30;
    u64* p31;
    s32 i;

    base = (u8*)lbl_8048D320;
    if (self[0x28a] & 1) {
        s32 tmp;
        n = fn_80237810(0);
        tmp = *(s32*)(lbl_80529DEC + 0xd8);
        cnt = tmp;
        if (n > 0x20) {
            n = 0x20;
        }
        if (n < 0) {
            n = 0;
        }
        if (n < cnt) {
            cnt = n;
        }
        if (cnt < 0) {
            cnt = 0;
        }
        p31 = (u64*)(base + 0x148);
        p30 = (u64*)(base + 0x188);
        p29 = (u64*)(base + 0x1c8);
        p28 = (u64*)(base + 0x208);
        for (i = 0; i < 8; i++) {
            if (cnt >= 4) {
                SetPaneVisibleOfSub(self, *p31, 1);
                SetPaneVisibleOfSub(self, *p30, 1);
                PaneSetFloats(FindPaneOfSub(self, *p31), 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                PaneSetFloats(FindPaneOfSub(self, *p30), 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                SetPaneVisibleOfSub(self, *p29, 0);
                SetPaneVisibleOfSub(self, *p28, 0);
                n -= 4;
                cnt -= 4;
            } else {
                if (cnt == 0) {
                    SetPaneVisibleOfSub(self, *p31, 0);
                    SetPaneVisibleOfSub(self, *p30, 0);
                    if (n > 0) {
                        SetPaneVisibleOfSub(self, *p29, 1);
                        SetPaneVisibleOfSub(self, *p28, 1);
                        n -= 4;
                    } else {
                        SetPaneVisibleOfSub(self, *p29, 0);
                        SetPaneVisibleOfSub(self, *p28, 0);
                    }
                } else if (cnt == 1) {
                    SetPaneVisibleOfSub(self, *p31, 1);
                    SetPaneVisibleOfSub(self, *p30, 1);
                    PaneSetFloats(FindPaneOfSub(self, *p31), 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    PaneSetFloats(FindPaneOfSub(self, *p30), 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetPaneVisibleOfSub(self, *p29, 0);
                    SetPaneVisibleOfSub(self, *p28, 0);
                    n -= 4;
                } else if (cnt == 2) {
                    SetPaneVisibleOfSub(self, *p31, 1);
                    SetPaneVisibleOfSub(self, *p30, 1);
                    PaneSetFloats(FindPaneOfSub(self, *p31), 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    PaneSetFloats(FindPaneOfSub(self, *p30), 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetPaneVisibleOfSub(self, *p29, 0);
                    SetPaneVisibleOfSub(self, *p28, 0);
                    n -= 4;
                } else if (cnt == 3) {
                    SetPaneVisibleOfSub(self, *p31, 1);
                    SetPaneVisibleOfSub(self, *p30, 1);
                    PaneSetFloats(FindPaneOfSub(self, *p31), 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    PaneSetFloats(FindPaneOfSub(self, *p30), 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetPaneVisibleOfSub(self, *p29, 0);
                    SetPaneVisibleOfSub(self, *p28, 0);
                    n -= 4;
                }
                cnt = 0;
            }
            p31++;
            p30++;
            p29++;
            p28++;
        }
    }
}

extern "C" void fn_8041E3B4(u8* this_, u32 idx) {
    u8 mask;
    u32 bit;
    s32 i;
    BOOL flag;

    bit = 1 << idx;
    mask = bit;

    flag = (lbl_8053AAF8[0x82] & mask) != 0;
    if (!flag) {
        this_[0x28f] &= ~mask;
        return;
    }
    flag = (lbl_8053AED0[0xdd] & mask) != 0;
    if (flag && (this_[0x290] & mask) == 0) {
        this_[0x290] |= mask;
        this_[0x28f] |= mask;
        return;
    }
    if ((lbl_8053AED0[0xdc] & 0x10) != 0) {
        this_[0x28f] &= ~mask;
        return;
    }
    if (((u8*)fn_802D6A9C())[0x131ef] != 0 || fn_8022AF5C() != 0 || fn_8022B1AC() != 0 || fn_8022B160() != 0) {
        this_[0x28f] &= ~mask;
        this_[0x293] |= (u8)bit;
        return;
    }
    if (lbl_8053AEC8[0x5e] == 1) {
        for (i = 0; i < fn_80138A30(lbl_8053AAF8); i++) {
            this_[0x28f] |= (u8)(1 << i);
        }
        lbl_8053AEC8[0x5e] = 0;
        return;
    }
    if (*(s32*)(lbl_8053AAF8 + 0x4c) == 0xb) {
        this_[0x28f] &= ~mask;
        return;
    }
    if (fn_8022B1AC() == 0 && fn_8022B160() == 0 && (this_[0x293] & mask) != 0) {
        this_[0x28f] |= (u8)bit;
        this_[0x293] &= ~mask;
    }
}

extern "C" void fn_8041E58C(u8* this_) {
    s32 j;
    s32 bit;
    s32 flag;
    s32 i;

    for (i = 0; i < 4; i++) {
        bit = 1 << i;
        flag = (lbl_8053AAF8[0x82] & (u8)bit) != 0;
        if (flag != 0) {
            ((u32*)lbl_80529DEC)[0x36 + i] = fn_80237774(i);
            for (j = 0; j < 4; j++) {
                if (j != i && fn_8022F514(j) && fn_8022F3DC(j) == i) {
                    ((u32*)lbl_80529DEC)[0x36 + j] = ((u32*)lbl_80529DEC)[0x36 + i];
                }
            }
            this_[0x28a] |= (u8)bit;
            *(u32*)(this_ + 0x198 + i * 4) = 0;
            ((u32*)lbl_80529DEC)[0x3a + i] = fn_80236100(i);
            this_[0x28b] |= (u8)bit;
            *(u32*)(this_ + 0x1a8 + i * 4) = 0;
            ((u32*)lbl_80529DEC)[0x42 + i] = fn_802375B0(i);
            for (j = 0; j < 4; j++) {
                if (j != i && fn_8022F514(j) && fn_8022F3DC(j) == i) {
                    ((u32*)lbl_80529DEC)[0x42 + j] = ((u32*)lbl_80529DEC)[0x42 + i];
                }
            }
            this_[0x289] |= (u8)bit;
            *(u32*)(this_ + 0x1b8 + i * 4) = 0;
        }
    }
}

extern "C" void fn_80230FD0(s32 i, s32 arg);
extern "C" s32 fn_80236228(s32 i);
extern "C" void fn_802362C4(s32 i, s32 val);
extern "C" void fn_8023619C(s32 i, s32 val);
extern "C" void fn_8041E708(u8* this_, s32 i, s32 val, u8 flag) {
    s32 idx;
    if (fn_8022F514(i)) {
        idx = fn_8022F3DC(i);
    } else {
        idx = i;
    }
    if (flag) {
        s32 sum = val + (s32)fn_80236100(idx);
        if (sum > 9999) {
            val = 9999 - fn_80236228(idx);
        } else if (sum < -5000) {
            val = -5000 - fn_80236228(idx);
        }
    } else {
        s32 sum = val + fn_80236228(idx);
        if (sum > 9999) {
            val = 9999 - fn_80236228(idx);
        } else if (sum < 0) {
            if (fn_80236228(idx) <= 0) {
                val = 0;
            } else {
                val = -fn_80236228(idx);
            }
        }
    }
    if (val >= 1000 || val <= -1000) {
        s32 mag = val < 0 ? -val : val;
        *(s16*)(this_ + i * 2 + 0x224) = (s16)(mag / 100);
        *(s16*)(this_ + i * 2 + 0x22C) = 0;
    } else {
        fn_80230FD0(i, 0x20034);
    }
    if (flag) {
        fn_8023619C(idx, val);
    } else {
        fn_802362C4(idx, val);
    }
    u32* table = (u32*)lbl_80529DEC;
    table[0x3A + idx] = fn_80236100(idx);
    *(u32*)(this_ + idx * 4 + 0x1A8) = 0;
    this_[0x28B] |= (u8)(1 << idx);
}

extern "C" void fn_8041E8B4(u8* this_, s32 idx) {
    s32 cnt;
    s32 i;
    bool flag;
    u32 bit;
    u8 mask;

    bit = 1 << idx;
    mask = bit;

    flag = lbl_80529DEC[0x239] & mask;
    if (flag) {
        s32* slot = (s32*)(lbl_80529DEC + idx * 4 + 0xd8);
        cnt = fn_80237774(idx);
        *(s32*)(lbl_80529DEC + idx * 4 + 0xd8) = cnt;
        for (i = 0; i < 4; i++) {
            if (i != idx && fn_8022F514(i) && fn_8022F3DC(i) == idx) {
                *(s32*)(lbl_80529DEC + i * 4 + 0xd8) = *(s32*)(lbl_80529DEC + idx * 4 + 0xd8);
            }
        }
        this_[0x28a] |= bit;
        *(s32*)(this_ + idx * 4 + 0x198) = 0;
        *(s16*)(this_ + idx * 2 + 0x21a) = *(s16*)(lbl_8050DB0C + 0x74) * *(s16*)(lbl_8050DB0C + 0x76) + 0x1e;
        *(s32*)(this_ + idx * 4 + 0x1e8) = *(s32*)(this_ + idx * 4 + 0x1d8);
        *(s32*)(this_ + idx * 4 + 0x1d8) = *(s32*)(lbl_80529DEC + idx * 4 + 0xd8);
        *(s32*)(this_ + idx * 4 + 0x1f8) = fn_80237810(idx);
        lbl_80529DEC[0x239] &= ~mask;
    } else {
        s32* slot = (s32*)(lbl_80529DEC + idx * 4 + 0xd8);
        cnt = *slot;
        if (cnt < (s32)fn_80237774(idx)) {
            *(s32*)(this_ + idx * 4 + 0x198) += 1;
            if (*(s32*)(this_ + idx * 4 + 0x198) >= 10) {
                *slot += 1;
                for (i = 0; i < 4; i++) {
                    if (i != idx && fn_8022F514(i) && fn_8022F3DC(i) == idx) {
                        *(s32*)(lbl_80529DEC + i * 4 + 0xd8) = *slot;
                    }
                }
                this_[0x28a] |= bit;
                *(s32*)(this_ + idx * 4 + 0x198) = 0;
                fn_80230EB8(idx, 9);
            }
            if (this_[0x291] != 0) {
                *(s16*)(this_ + idx * 2 + 0x21a) = *(s16*)(lbl_8050DB0C + 0x74) * *(s16*)(lbl_8050DB0C + 0x76) + 0x1e;
                *(s32*)(this_ + idx * 4 + 0x1e8) = *(s32*)(this_ + idx * 4 + 0x1d8);
                *(s32*)(this_ + idx * 4 + 0x1d8) = *slot;
                *(s32*)(this_ + idx * 4 + 0x1f8) = fn_80237810(idx);
            }
        } else if (cnt > (s32)fn_80237774(idx)) {
            lbl_80529DEC[0x24a] |= mask;
            *(s32*)(this_ + idx * 4 + 0x198) += 1;
            if (*(s32*)(this_ + idx * 4 + 0x198) >= 10) {
                *slot -= 1;
                for (i = 0; i < 4; i++) {
                    if (i != idx && fn_8022F514(i) && fn_8022F3DC(i) == idx) {
                        *(s32*)(lbl_80529DEC + i * 4 + 0xd8) = *slot;
                    }
                }
                this_[0x28a] |= bit;
                *(s32*)(this_ + idx * 4 + 0x198) = 0;
            }
            if (this_[0x291] != 0) {
                *(s16*)(this_ + idx * 2 + 0x21a) = *(s16*)(lbl_8050DB0C + 0x74) * *(s16*)(lbl_8050DB0C + 0x76) + 0x1e;
                *(s32*)(this_ + idx * 4 + 0x1e8) = *(s32*)(this_ + idx * 4 + 0x1d8);
                *(s32*)(this_ + idx * 4 + 0x1d8) = *slot;
                *(s32*)(this_ + idx * 4 + 0x1f8) = fn_80237810(idx);
            }
        } else {
            *(s32*)(this_ + idx * 4 + 0x198) = 0;
        }
    }

    cnt = *(s32*)(lbl_80529DEC + idx * 4 + 0xe8);
    if (cnt < (s32)fn_80236100(idx)) {
        *(s32*)(this_ + idx * 4 + 0x1a8) += 1;
        if (*(s32*)(this_ + idx * 4 + 0x1a8) >= 2) {
            *(s32*)(lbl_80529DEC + idx * 4 + 0xe8) += 2;
            if (*(s32*)(lbl_80529DEC + idx * 4 + 0xe8) < (s32)fn_80236100(idx)) {
                fn_80230EB8(idx, 4);
            } else {
                *(s32*)(lbl_80529DEC + idx * 4 + 0xe8) = fn_80236100(idx);
                fn_80230EB8(idx, 0x51);
            }
            this_[0x28b] |= bit;
            *(s32*)(this_ + idx * 4 + 0x1a8) = 0;
        }
    } else if (cnt > (s32)fn_80236100(idx)) {
        *(s32*)(this_ + idx * 4 + 0x1a8) += 1;
        if (*(s32*)(this_ + idx * 4 + 0x1a8) >= 2) {
            *(s32*)(lbl_80529DEC + idx * 4 + 0xe8) -= 2;
            if (*(s32*)(lbl_80529DEC + idx * 4 + 0xe8) > (s32)fn_80236100(idx)) {
                fn_80230EB8(idx, 0x4e);
            } else {
                *(s32*)(lbl_80529DEC + idx * 4 + 0xe8) = fn_80236100(idx);
                fn_80230EB8(idx, 0x51);
            }
            this_[0x28b] |= bit;
            *(s32*)(this_ + idx * 4 + 0x1a8) = 0;
        }
    } else {
        *(s32*)(this_ + idx * 4 + 0x1a8) = 0;
    }

    if (*(s16*)(this_ + idx * 2 + 0x224) > 0) {
        if (*(s16*)(this_ + idx * 2 + 0x22c) == 0) {
            *(s16*)(this_ + idx * 2 + 0x224) -= 1;
            fn_80230FD0(idx, 0x20034);
            if (*(s16*)(this_ + idx * 2 + 0x224) != 0) {
                *(s16*)(this_ + idx * 2 + 0x22c) = 0xc;
            }
        } else {
            *(s16*)(this_ + idx * 2 + 0x22c) -= 1;
        }
    }
}

#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void fn_8041EDB0(u8* self) {
    u64* tags = lbl_8048D320;
    int i;
    u64* a;
    u64* b;
    u64* c;
    u64* paneTag;
    if (lbl_8053AAF8[0x7e] == 0) {
        fn_8041E3B4(self,0);
        fn_8041E8B4(self,0);
        if ((u32)(lbl_8053AAF8[0x83]&3)==2) {
            fn_8041DD24(self);
            fn_8041D18C(self,0);
            fn_8041CC04(self);
        }
        fn_8041A868(self,0);
        if ((*(u8**)(lbl_8053AB10+0x20))[0x14c]) (*(u8**)(lbl_8053AB10+0x20))[0x217]=1;
        if (*(s32*)(lbl_8053AAF8+0x4c)!=11 && fn_80236B50(0) && (s32)fn_80237774(0)==0) {
            if ((s8)self[0x292]>=2) {
                if (!lbl_8053AEC8[0x5d]) lbl_8053AEC8[0x5d]=1;
            } else self[0x292]++;
        } else self[0x292]=0;
    } else {
        paneTag = tags + 0x168;
        a = tags+0x164;
        b = paneTag;
        c = tags+0x16c;
        for (i=0;i<4;i++,a++,b++,c++) {
            fn_8041E3B4(self,i);
            u8 mask = 1<<i;
            if (HudPlayerActive8041(i)==1) {
                fn_8041E8B4(self,i);
                if ((*(u8**)(lbl_8053AB10+0x20))[0x14c+i]) {
                    if (!(self[0x28c]&mask)) {
                        self[0x28c] |= mask;
                        (*(J2DPane**)(self+0x18))->search(*a)->show();
                        (*(J2DPane**)(self+4))->search(*b)->show();
                        (*(J2DPane**)(self+4))->search(*c)->hide();
                    }
                } else if (self[0x28c]&mask) {
                    self[0x28c] &= ~mask;
                    (*(J2DPane**)(self+0x18))->search(*a)->hide();
                    (*(J2DPane**)(self+4))->search(*b)->hide();
                    (*(J2DPane**)(self+4))->search(*c)->show();
                }
                fn_8041D18C(self,i);
                fn_8041C0C0(self,i);
            }
        }
        fn_8041B69C(self);
        u8* cursor = self;
        s32 offset = 0;
        for (i=0;i<4;i++,offset+=0x10,cursor+=4,paneTag++) {
            if (HudPlayerActive8041(i)) {
                fn_80419C38(self,i,0);
                u8* state=*(u8**)(lbl_8053AB10+0x20);
                if (state[0x214] && i==*(s32*)(state+0x230)) state[0x217+i]=1;
                if ((*(u8**)(lbl_8053AB10+0x20))[0x14c+i]) {
                    s32 x = (*(J2DPane**)(self+4))->search(*paneTag)->getBounds()->i.x;
                    s32 y = (*(J2DPane**)(self+4))->search(*paneTag)->getBounds()->i.y;
                    f32 width = (*(J2DPane**)(self+4))->search(*paneTag)->getWidth();
                    f32 height = (*(J2DPane**)(self+4))->search(*paneTag)->getHeight();
                    u8* box = *(u8**)(lbl_8053AB10+0x20) + offset;
                    *(s32*)(box+0x1d0)=x;
                    *(s32*)(box+0x1d4)=y;
                    *(s32*)(box+0x1d8)=(s32)width;
                    *(s32*)(box+0x1dc)=(s32)height;
                    if (i==0 || i==2) {
                        if (*(f32*)(cursor+0xf8)<lbl_80543A1C) *(f32*)(cursor+0xf8)+=lbl_80543A20;
                        else *(f32*)(cursor+0xf8)=lbl_80543A24;
                    } else {
                        if (*(f32*)(cursor+0xf8)>lbl_80543A28) *(f32*)(cursor+0xf8)-=lbl_80543A20;
                        else *(f32*)(cursor+0xf8)=lbl_80543A2C;
                    }
                } else {
                    if (i==0 || i==2) {
                        if (*(f32*)(cursor+0xf8)<lbl_80543A20) *(f32*)(cursor+0xf8)=lbl_80543A00;
                        else *(f32*)(cursor+0xf8)-=lbl_80543A20;
                    } else {
                        if (*(f32*)(cursor+0xf8)>lbl_80543A30) *(f32*)(cursor+0xf8)=lbl_80543A00;
                        else *(f32*)(cursor+0xf8)+=lbl_80543A20;
                    }
                }
            }
        }
    }
    if (self[0x291]) {
        for(i=0;i<4;i++) if (HudPlayerActive8041(i)) {
            fn_80419570(self,i);
            fn_8041918C(self,i);
        }
        for(i=0;i<4;i++) if (HudPlayerActive8041(i)) fn_80418D08(self,i,0);
    }
    self[0x28a]=0; self[0x28b]=0; self[0x289]=0;
    if (*(void**)(self+0x50)) fn_80441490(*(void**)(self+0x50));
    if (*(s32*)(lbl_8053AAF8+0x4c)!=11 && !self[0x298] && fn_80236890()) fn_801367E0(lbl_8053AAF8,11);
    if (*(s32*)(lbl_8053AAF8+0x4c)==11) {
        if (!self[0x298]) self[0x298]=1;
    } else if (self[0x298]==1) self[0x298]=0;
    s32 stage=*(s32*)(lbl_80529DEC+0x118);
    if (stage==9 && *(s32*)(lbl_80529DEC+0x11c)==3) {
        for (s32 player=0;player<4;player++) {
            if (lbl_8053AAF8[0x82] & (u8)(1<<player)) (*(u8**)(lbl_8053AB10+0x20))[0x217+player]=1;
        }
    } else if ((stage==0 && *(s32*)(lbl_80529DEC+0x11c)==2) ||
        (stage==1 && *(s32*)(lbl_80529DEC+0x11c)==2) ||
        (stage==2 && *(s32*)(lbl_80529DEC+0x11c)==2) ||
        (stage==4 && *(s32*)(lbl_80529DEC+0x11c)==2) ||
        (stage==5 && *(s32*)(lbl_80529DEC+0x11c)==2) ||
        (stage==10 && *(s32*)(lbl_80529DEC+0x11c)==2)) {
        for (s32 player=0;player<4;player++) {
            if (lbl_8053AAF8[0x82] & (u8)(1<<player)) (*(u8**)(lbl_8053AB10+0x20))[0x217+player]=1;
        }
    }
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
extern "C" void fn_8013B490(void*);
extern "C" void fn_8044148C(void);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
extern u8* lbl_8053AB10;
extern f32 lbl_80543A00;
extern "C" void fn_8041F5FC(void* this_) {
    u8* p = (u8*)this_;
    s32 mode = *(s32*)(lbl_80529DEC + 0x118);
    if (mode == 9 && *(s32*)(lbl_80529DEC + 0x11c) == 3) return;
    if (mode == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 1 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 2 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 4 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 5 && *(s32*)(lbl_80529DEC + 0x11c) == 2) return;
    if (mode == 10) {
        if (*(s32*)(lbl_80529DEC + 0x11c) == 2) {
            fn_8044148C();
            return;
        }
    }
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543A00;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(p + 0x18), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
    if (*(void**)(p + 0x50) != 0) {
        fn_8044148C();
    }
}

extern "C" void fn_8013B490(void* p);
extern f32 lbl_80543A34;
extern f32 lbl_80543A38;
extern f32 lbl_80543A3C;
extern "C" void fn_8041F720(u8* self) {
    f32 buf[3];
    s32 st = *(s32*)(lbl_80529DEC + 0x118);
    if ((st == 9 && *(s32*)(lbl_80529DEC + 0x11c) == 3) || (st == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 2) ||
        (st == 1 && *(s32*)(lbl_80529DEC + 0x11c) == 2) || (st == 2 && *(s32*)(lbl_80529DEC + 0x11c) == 2) ||
        (st == 4 && *(s32*)(lbl_80529DEC + 0x11c) == 2) || (st == 5 && *(s32*)(lbl_80529DEC + 0x11c) == 2) ||
        (st == 0xa && *(s32*)(lbl_80529DEC + 0x11c) == 2)) {
        return;
    }

    if (self[0x291] != 0) {
        f32 ex;
        f32 ey;
        f32 sx;
        f32 sy;
        f32 d = *(f32*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x858);
        f32 k = *(f32*)(lbl_8050DB0C + 0x40);
        u8* vid = *(u8**)(sManager__8JUTVideo + 4);
        sx = k * ((f32)(s32)*(u16*)(vid + 4) / d);
        sy = k * ((f32)(s32)*(u16*)(vid + 6) / d);
        ex = lbl_80543A00 + sx;
        ey = lbl_80543A00 + sy;

        for (s32 i = 0; i < 4; i++) {
            if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
                u8* p2 = self + 2 * i;
                u8* p4 = self + 4 * i;
                if (fn_8023DE58(fn_8022EA0C(i)) < 8) {
                    if (*(s16*)(p2 + 0x21a) > 0 && (lbl_8050EC80 + 0xc8 * *(s32*)(lbl_8050EC80 + 0x10))[0x88] != 0) {
                        fn_8022EA0C(i);
                        fn_8030C5F0(*(void**)(lbl_8053AB10 + 0x24), fn_8023E724(), 0, 0, buf);
                        u8* vp = *(u8**)(sManager__8JUTVideo + 4);
                        f32 fa = (f32)(s32)*(u16*)(vp + 4);
                        f32 fb = (f32)(s32)*(u16*)(vp + 6);
                        f32 c = (f32)(s32)*(s16*)(lbl_8050DB0C + 0x4e);
                        f32 xx = sx * (buf[0] / fa);
                        f32 x = xx - fa * lbl_80543A34;
                        f32 yy = sy * (buf[1] / fb);
                        f32 y = c + (yy - fb * lbl_80543A34);
                        JGeometry::TBox2f box(lbl_80543A00, lbl_80543A00, ex, ey);
                        ((J2DOrthoGraph*)*(u8**)(self + 0x4c))->setOrtho(box, lbl_80543A38, lbl_80543A3C);
                        ((J2DOrthoGraph*)*(u8**)(self + 0x4c))->setPort();
                        ((J2DScreen*)*(u8**)(p4 + 8))->draw(x, y, *(J2DGrafContext**)(self + 0x4c));
                        *(s16*)(p2 + 0x234) = 0;
                    } else if (!(*(s32*)(lbl_8053AAF8 + 0x4c) == 0xb || lbl_8053AAF8[0x88] == 2)) {
                        fn_8022EA0C(i);
                        if (fn_802366CC() > 0) {
                            fn_8022EA0C(i);
                            if (fn_802366CC() < 0x12c) {
                                fn_8022EA0C(i);
                                fn_8030C5F0(*(void**)(lbl_8053AB10 + 0x24), fn_8023E724(), 0, 0, buf);
                                u8* vp = *(u8**)(sManager__8JUTVideo + 4);
                                f32 fa = (f32)(s32)*(u16*)(vp + 4);
                                f32 fb = (f32)(s32)*(u16*)(vp + 6);
                                f32 c = (f32)(s32)*(s16*)(lbl_8050DB0C + 0x4e);
                                f32 xx = sx * (buf[0] / fa);
                                f32 x = xx - fa * lbl_80543A34;
                                f32 yy = sy * (buf[1] / fb);
                                f32 y = c + (yy - fb * lbl_80543A34);
                                JGeometry::TBox2f box(lbl_80543A00, lbl_80543A00, ex, ey);
                                ((J2DOrthoGraph*)*(u8**)(self + 0x4c))->setOrtho(box, lbl_80543A38, lbl_80543A3C);
                                ((J2DOrthoGraph*)*(u8**)(self + 0x4c))->setPort();
                                ((J2DScreen*)*(u8**)(p4 + 0x2c))->draw(x, y, *(J2DGrafContext**)(self + 0x4c));
                            }
                        }
                    }
                }
            }
        }
    }

    fn_8013B490(lbl_8053AB10);
    ((J2DScreen*)*(u8**)(self + 4))->draw(lbl_80543A00, lbl_80543A00, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void fn_8041A868(u8* self, s32 x);
extern "C" void fn_8041C67C(u8* self);
extern "C" void fn_80418D08(u8* self, s32 i, s32 j);
extern "C" void fn_8043A608(u8* x);
extern "C" void fn_8044172C(u8* x);
extern "C" void fn_8041FC2C(u8* self) {
    u8* tbl;
    u8* lbl;
    u8* p;
    u8* q;
    s32 i;
    s32 j;
    f32 f;
    u32* w;

    tbl = (u8*)lbl_8048D320;
    lbl = (u8*)lbl_80529DEC;
    f = lbl_80543A00;
    p = self;
    q = self;
    w = (u32*)(lbl + 0xd8);

    i = 0;
    fn_8041E3B4(self, i);
    *(u32*)(lbl + 0xd8) = fn_80237774(i);
    *(u32*)(lbl + 0xe8) = fn_80236100(i);
    *(u32*)(lbl + 0x108) = fn_802375B0(i);

    while (i < 4) {
        *(u32*)(p + 0x188) = 0x180;
        *(u32*)(p + 0x198) = 0;
        *(u32*)(p + 0x1a8) = 0;
        *(u32*)(p + 0x1b8) = 0;
        *(f32*)(p + 0xf8) = f;
        *(f32*)(p + 0x108) = f;
        *(f32*)(p + 0x118) = f;
        *(f32*)(p + 0x128) = f;
        *(f32*)(p + 0x138) = f;
        *(f32*)(p + 0x148) = f;
        *(f32*)(p + 0x158) = f;
        *(f32*)(p + 0x168) = f;
        self[0x285 + i] = i;
        self[0x281 + i] = 0xff;
        *(u16*)(q + 0x23c) = 0;
        *(u32*)(p + 0x1c8) = 0;
        *(u32*)(p + 0x1d8) = 0;
        *(u32*)(p + 0x1e8) = 0;
        *(u32*)(p + 0x1f8) = 0;
        *(u16*)(q + 0x21a) = 0;
        *(u16*)(q + 0x224) = 0;
        *(u16*)(q + 0x22c) = 0;
        *(u32*)(p + 0x208) = 0;
        *(u16*)(q + 0x234) = 0;
        p += 4;
        q += 2;
        w++;
        i++;
    }
    *(s16*)(self + 0x222) = -1;

    if (lbl_8053AAF8[0x7e] == 0) {
        SetPaneVisible(*(u8**)(self + 4), 0x004E646174613133ULL, 1);
        SetPaneVisible(*(u8**)(self + 4), 0x506870316E693032ULL, 0);
        SetPaneVisible(*(u8**)(self + 4), 0x5068317069696233ULL, 1);
        SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0x398), 0);
        SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0x3a0), 0);
        SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0x3a8), 0);
        SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0x3b0), 0);
        SetPaneVisible(*(u8**)(self + 4), 0x004E646174613136ULL, (lbl_8053AAF8[0x83] & 3) == 2);

        u64* n0 = (u64*)(tbl + 0xae0);
        u64* n1 = (u64*)(tbl + 0xb20);
        u64* n2 = (u64*)(tbl + 0xb40);
        u64* n3 = (u64*)(tbl + 0xb60);
        u64* n4 = (u64*)(tbl + 0xb80);
        u64* n5 = (u64*)(tbl + 0xbc0);
        u64* n6 = (u64*)(tbl + 0xbe0);
        u64* n7 = (u64*)(tbl + 0xc00);
        for (j = 0; j < 4; j++, n0++, n1++, n2++, n3++, n4++, n5++, n6++, n7++) {
            SetPaneVisible(*(u8**)(self + 0x18), *n0, 0);
            SetPaneVisible(*(u8**)(self + 0x18), *n1, 0);
            SetPaneVisible(*(u8**)(self + 4), *n2, 0);
            SetPaneVisible(*(u8**)(self + 4), *n3, 0);
            SetPaneVisible(*(u8**)(self + 4), *n4, 0);
            SetPaneVisible(*(u8**)(self + 4), *n5, 0);
            SetPaneVisible(*(u8**)(self + 4), *n6, 0);
            SetPaneVisible(*(u8**)(self + 4), *n7, 0);
        }
        fn_8041A868(self, 1);
    } else {
        fn_8041C67C(self);
    }

    if (self[0x291] != 0) {
        for (i = 0; i < 4; i++) {
            if (lbl_8053AAF8[0x82] & (1 << i)) {
                fn_80418D08(self, i, 1);
            }
        }
    }
    self[0x28a] = 0xf;
    self[0x28b] = 0xf;
    self[0x289] = 0xf;
    self[0x28c] = 0;
    self[0x28d] = 0;
    self[0x28e] = 0;
    *(s32*)(self + 0x178) = -2;
    *(s32*)(self + 0x17c) = -2;
    *(s32*)(self + 0x180) = -2;
    *(s32*)(self + 0x184) = -2;
    {
        s32 a = *(s32*)(lbl + 0x118);
        s32 b = *(s32*)(lbl + 0x11c);
        if (a < 8 && b < 4) {
            if (a == 0 && b == 0) {
                u8* e = (u8*)lbl_8050EC80 + 0xc8 * *(s32*)((u8*)lbl_8050EC80 + 0x10);
                if (*(s32*)(e + 0x28) & 1) {
                    fn_8043A608(lbl_8053AED0);
                }
            } else if (!((a == 0 && b == 1) || (a == 1 && b == 3) || (a == 2 && b == 3) ||
                         (a == 4 && b == 3) || (a == 5 && (b == 1 || b == 3)) ||
                         (a == 6 && (b == 1 || b == 3)) || (a == 7 && b == 3))) {
                fn_8043A608(lbl_8053AED0);
            }
        }
    }
    if (*(u8**)(self + 0x50) != 0) {
        fn_8044172C(*(u8**)(self + 0x50));
    }
}

extern u8 lbl_804B1390[];
extern "C" u8* fn_80420574(u8* self) {
    *(u8**)self = lbl_804B1390 + 0x44;
    *(s32*)(self + 0x244) = -1;
    *(s32*)(self + 0x248) = -1;
    if (*(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) != 0) {
        lbl_8053AED0[0x10e] |= 1;
    }
    self[0x291] = 1;
    self[0x292] = 0;
    self[0x28f] = 0;
    self[0x290] = 0;
    self[0x293] = 0;
    self[0x294] = 0;
    self[0x295] = 0;
    self[0x296] = 0;
    self[0x297] = 0;
    self[0x218] = 1;
    self[0x298] = 0;
    return self;
}

