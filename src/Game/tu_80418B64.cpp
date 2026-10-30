#include "types.h"
extern void* lbl_804B13D4[];
extern "C" void __dl__FPv(void*);
struct DtorSlot2 {
    virtual void destroy(s32 freeFlag);
};
static inline void ReleaseSlot(void** slot) {
    DtorSlot2* obj = (DtorSlot2*)*slot;
    if (obj != 0) obj->destroy(1);
    *slot = 0;
}
extern "C" void fn_8041E8B4(u8*, s32);
extern "C" void fn_8041E3B4(u8*, u32);
extern "C" void fn_8041DD24(void*);
extern "C" void fn_8041D18C(u8*, s32);
extern "C" void fn_8041CC04(u8*);
extern "C" void fn_8041A868(u8*, s32);
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
#include "JSystem/JAudio/JASFakeMatchFSA.h"


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
extern const u64 lbl_8048DDD0[];
extern u32 lbl_804B139C[];
extern "C" s32 fn_802366CC(void);
extern "C" u32 fn_804030C4(u32 tag, u32 id);
extern "C" void fn_80230EB8(s32 i, s32 id);
extern "C" void fn_80230FD0(s32 i, s32 id);
extern "C" u32 fn_80237810(s32 i);
extern u8 lbl_8050DB0C[];
extern const u64 lbl_8048D320[];
extern f32 lbl_80543A0C;
extern f32 lbl_80543A00;

static inline void HudIncreaseFade8041(f32* value, const f32 step) { *value += step; }

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

static inline void HudHidePane8041(u8* self, u64 key) {
    (*(J2DPane**)(self + 4))->search(key)->hide();
}

static inline J2DPicture* GetPicture(u8* this_, u64 key) {
    return (J2DPicture*)(*(SubObj**)(this_ + 4))->w13(key);
}

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

static inline void SetScreenPaneVisible(u8* self, u64 name, u8 vis) {
    u8* pane = (u8*)(*(J2DScreen**)(self + 4))->search(name);
    pane[0xb0] = vis;
}

static inline u8* GetScreenPane(u8* screen, u64 name) {
    return (u8*)((J2DScreen*)screen)->search(name);
}

static inline void SetPaneBlend(u8* pane, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h) {
    ((J2DPicture*)pane)->setBlendRatio(a, b, c, d, e, f, g, h);
}

static inline void SetScreenPaneBlend(u8* self, u64 name, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h) {
    ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(name))->setBlendRatio(a, b, c, d, e, f, g, h);
}



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

extern const f32 lbl_80543A04;
#pragma opt_lifetimes off
extern "C" void fn_80418D08(u8* self, s32 idx, s32 flag) {
    const u64* base = lbl_8048D320;
    u8* p = self + idx * 4;
    s32 off = idx * 4;
    u8 mask = (u8)(1 << idx);
    f32 v31 = *(f32*)(p + 0x128);
    f32 v30 = *(f32*)(p + 0x168);

    s32 t = (self[0x28f] & mask) != 0;
    if (t == 0) {
        if (v31 > 0.0f) {
            *(f32*)(p + 0x128) = v31 - lbl_80543A04;
        } else {
            *(f32*)(p + 0x128) = 0.0f;
        }
        u8* q = *(u8**)(lbl_8053AB10 + 0x20);
        q[idx + 0x217] = 1;
    } else {
        if (*(s32*)(lbl_80529DEC + off + 0xd8) == 0 && lbl_8053AEC8[0x5e] == 0) {
            if (v31 > 0.6f) {
                *(f32*)(p + 0x128) = v31 - lbl_80543A04;
                if (*(f32*)(p + 0x128) <= 0.6f) {
                    *(f32*)(p + 0x128) = 0.6f;
                }
            } else if (v31 < 0.6f) {
                *(f32*)(p + 0x128) = v31 + lbl_80543A04;
                if (*(f32*)(p + 0x128) >= 0.6f) {
                    *(f32*)(p + 0x128) = 0.6f;
                }
            }
        } else {
            if (v31 < 1.0f) {
                HudIncreaseFade8041((f32*)(p + 0x128), lbl_80543A04);
            } else {
                *(f32*)(p + 0x128) = 1.0f;
            }
        }
    }

    if (v31 != *(f32*)(p + 0x128) || (u8)flag != 0) {
        if ((self[0x28f] & mask) == 0 && fn_8022B1AC() == 0) {
            if (*(f32*)(p + 0x168) > 0.0f) {
                *(f32*)(p + 0x168) = *(f32*)(p + 0x168) - lbl_80543A04;
            } else {
                *(f32*)(p + 0x168) = 0.0f;
            }
        } else {
            if (*(s32*)(lbl_80529DEC + off + 0xd8) == 0 && lbl_8053AEC8[0x5e] == 0) {
                if (*(f32*)(p + 0x168) > 0.6f) {
                    *(f32*)(p + 0x168) = *(f32*)(p + 0x168) - lbl_80543A04;
                    if (*(f32*)(p + 0x168) <= 0.6f) {
                        *(f32*)(p + 0x168) = 0.6f;
                    }
                } else if (*(f32*)(p + 0x168) < 0.6f) {
                    *(f32*)(p + 0x168) = *(f32*)(p + 0x168) + lbl_80543A04;
                    if (*(f32*)(p + 0x168) >= 0.6f) {
                        *(f32*)(p + 0x168) = 0.6f;
                    }
                }
            } else {
                if (*(f32*)(p + 0x168) < 1.0f) {
                    *(f32*)(p + 0x168) = *(f32*)(p + 0x168) + lbl_80543A04;
                } else {
                    *(f32*)(p + 0x168) = 1.0f;
                }
            }
        }

        if (v31 != *(f32*)(p + 0x128) || v30 != *(f32*)(p + 0x168) || (u8)flag != 0) {
            const u64* t0 = base + 0x184;
            const u64* t1 = base + 0x194;
            const u64* t2 = base + 0x18c;
            const u64* t3 = base + 0x19c;
            u8* paneBase = self + off;
            s32 k;
            for (k = 0; k < 8; k++) {
                (*(SubObj**)(paneBase + 8))->w13(*t0)->w07((s32)((f32)(u32)self[0x250] * *(f32*)(paneBase + 0x128)));
                (*(SubObj**)(paneBase + 8))->w13(*t1)->w07((s32)((f32)(u32)self[0x251] * *(f32*)(paneBase + 0x128)));
                (*(SubObj**)(paneBase + 8))->w13(*t2)->w07((s32)((f32)(u32)self[0x252] * *(f32*)(paneBase + 0x128)));
                (*(SubObj**)(paneBase + 8))->w13(*t3)->w07((s32)((f32)(u32)self[0x253] * *(f32*)(paneBase + 0x128)));
                t0++; t1++; t2++; t3++;
            }
            t3 = base + 0x156;
            for (k = 0; k < 6; k++) {
                SubObj* pane = (*(SubObj**)(paneBase + 0x2c))->w13(*t3);
                f32 alpha = (u32)self[0x27b + k];
                pane->w07((s32)(alpha * *(f32*)(paneBase + 0x168)));
                t3++;
            }
        }
    }
}
#pragma opt_lifetimes reset
extern "C" void fn_8041918C(u8* this_, s32 idx) {
    u8* p2;
    u8* q;
    s32 n;
    u32 s;

    if ((fn_8022EA0C(idx), fn_802366CC()) > 0 &&
        (fn_8022EA0C(idx), fn_802366CC()) < 300) {
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
                    s = fn_804030C4(0x54494d47, lbl_804B139C[n]);
                    u8* p = this_ + idx * 4;
                    ((J2DPicture*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[0]))->changeTexture((const ResTIMG*)s, 0);
                    ((J2DPicture*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[1]))->changeTexture((const ResTIMG*)s, 0);
                    if (((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[2]))[0xb0] == 1) {
                        u8* pane = (u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048DDD0[2]);
                        pane[0xb0] = 0;
                        pane = (u8*)GetPicture(p + 0x28, lbl_8048DDD0[3]);
                        pane[0xb0] = 0;
                    }
                } else {
                    void* image = (void*)fn_804030C4(0x54494d47, lbl_804B139C[n / 10]);
                    p2 = this_ + idx * 4;
                    ((J2DPicture*)((SubObj*)*(u8**)(p2 + 0x2c))->w13(lbl_8048DDD0[0]))->changeTexture((const ResTIMG*)image, 0);
                    ((J2DPicture*)((SubObj*)*(u8**)(p2 + 0x2c))->w13(lbl_8048DDD0[1]))->changeTexture((const ResTIMG*)image, 0);
                    s = fn_804030C4(0x54494d47, lbl_804B139C[n % 10]);
                    ((J2DPicture*)((SubObj*)*(u8**)(p2 + 0x2c))->w13(lbl_8048DDD0[2]))->changeTexture((const ResTIMG*)s, 0);
                    ((J2DPicture*)((SubObj*)*(u8**)(p2 + 0x2c))->w13(lbl_8048DDD0[3]))->changeTexture((const ResTIMG*)s, 0);
                    if (((u8*)((SubObj*)*(u8**)(p2 + 0x2c))->w13(lbl_8048DDD0[2]))[0xb0] == 0) {
                        u8* pane = (u8*)((SubObj*)*(u8**)(p2 + 0x2c))->w13(lbl_8048DDD0[2]);
                        const u64 key = lbl_8048DDD0[3];
                        pane[0xb0] = 1;
                        pane = (u8*)((SubObj*)*(u8**)(p2 + 0x2c))->w13(key);
                        pane[0xb0] = 1;
                    }
                }
                q[0x294] = n;
            }
    } else {
        this_[idx + 0x294] = 0;
    }
    s32 ticks;
    u8* timer;
    timer = this_ + idx * 2;
    ticks = *(s16*)(timer + 0x234);
    if (ticks > 0) {
        *(s16*)(timer + 0x234) = ticks - 1;
    }
}

extern "C" void fn_80419570(u8* self, s32 idx) {
    const u8* base = (const u8*)lbl_8048D320;
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
        const u64* a = (const u64*)(base + 0xc20);
        const u64* b = (const u64*)(base + 0xca0);
        const u64* c = (const u64*)(base + 0xc60);
        const u64* d = (const u64*)(base + 0xce0);
        for (s32 k = 0; k < 8; k++) {
            if (n >= 4) {
                GetScreenPane(*(u8**)(self + idx * 4 + 8), a[k])[0xb0] = 1;
                GetScreenPane(*(u8**)(self + idx * 4 + 8), b[k])[0xb0] = 1;
                SetPaneBlend(GetScreenPane(*(u8**)(self + idx * 4 + 8), a[k]), 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                SetPaneBlend(GetScreenPane(*(u8**)(self + idx * 4 + 8), b[k]), 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                GetScreenPane(*(u8**)(self + idx * 4 + 8), c[k])[0xb0] = 0;
                GetScreenPane(*(u8**)(self + idx * 4 + 8), d[k])[0xb0] = 0;
                n -= 4;
                cnt -= 4;
            } else {
                if (n == 0) {
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), a[k])[0xb0] = 0;
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), b[k])[0xb0] = 0;
                    if (cnt > 0) {
                        GetScreenPane(*(u8**)(self + idx * 4 + 8), c[k])[0xb0] = 1;
                        GetScreenPane(*(u8**)(self + idx * 4 + 8), d[k])[0xb0] = 1;
                        cnt -= 4;
                    } else {
                        GetScreenPane(*(u8**)(self + idx * 4 + 8), c[k])[0xb0] = 0;
                        GetScreenPane(*(u8**)(self + idx * 4 + 8), d[k])[0xb0] = 0;
                    }
                } else if (n == 1) {
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), a[k])[0xb0] = 1;
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), b[k])[0xb0] = 1;
                    SetPaneBlend(GetScreenPane(*(u8**)(self + idx * 4 + 8), a[k]), 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetPaneBlend(GetScreenPane(*(u8**)(self + idx * 4 + 8), b[k]), 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), c[k])[0xb0] = 0;
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), d[k])[0xb0] = 0;
                    cnt -= 4;
                } else if (n == 2) {
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), a[k])[0xb0] = 1;
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), b[k])[0xb0] = 1;
                    SetPaneBlend(GetScreenPane(*(u8**)(self + idx * 4 + 8), a[k]), 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetPaneBlend(GetScreenPane(*(u8**)(self + idx * 4 + 8), b[k]), 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), c[k])[0xb0] = 0;
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), d[k])[0xb0] = 0;
                    cnt -= 4;
                } else if (n == 3) {
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), a[k])[0xb0] = 1;
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), b[k])[0xb0] = 1;
                    SetPaneBlend(GetScreenPane(*(u8**)(self + idx * 4 + 8), a[k]), 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetPaneBlend(GetScreenPane(*(u8**)(self + idx * 4 + 8), b[k]), 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), c[k])[0xb0] = 0;
                    GetScreenPane(*(u8**)(self + idx * 4 + 8), d[k])[0xb0] = 0;
                    cnt -= 4;
                }
                n = 0;
            }
        }
        timer[0x10d]--;
    }
}

// Pane name tables inside lbl_8048D320, indexed by player.
struct HudPaneNames8041 {
    u64 pad000[0x29];
    u64 a148[8]; u64 a188[8]; u64 a1c8[8]; u64 a208[8];
    u64 a248[12]; u64 a2a8[12]; u64 a308[3]; u64 a320[3];
    u64 a338[5]; u64 a360[5]; u64 a388[2]; u64 a398[4];
    u64 a3b8[4][5];
    u64 a458[4][5];
    u64 a4f8[4][2];
    u64 a538[4][12];
    u64 a6b8[4][12];
    u64 a838[4][3];
    u64 a898[4][3];
    u64 a8f8[4][6];
    u64 pad9b8[4];
    u64 a9d8[4][4];
    u64 pada58[11]; u64 ab0[6];
    u64 ae0[4];
    u64 b00[4];
    u64 b20[4];
    u64 b40[4];
    u64 padb60[4];
    u64 b80[4];
    u64 ba0[4]; u64 bc0[4]; u64 be0[4]; u64 c00[4]; u64 c20[16]; u64 ca0[16];
};

static inline const HudPaneNames8041* HudNames8041() { return (const HudPaneNames8041*)lbl_8048D320; }
static inline u64 HudPaneName8041(const u64* names, s32 index) { return names[index]; }

struct HudFade8041 {
    u8 pad000[0x118];
    f32 fade[4];
};

extern "C" f32 fn_8043D57C(u8* obj);
extern "C" f32 fn_8043D514(u8* obj);
extern "C" void fn_80402E08(u8* obj, f32 a, f32 b);
extern "C" void fn_8037EB4C(void);

// Sets a pane's alpha to base alpha scaled by a fade factor.
static inline void HudSetPaneAlpha8041(u8* screen, const u64* names, s32 i, u8 alpha, f32 fade) {
    (*(SubObj**)screen)->w13(names[i])->w07((s32)((f32)alpha * fade));
}

extern f32 lbl_80543A18;
extern "C" void fn_80419C38(u8* self, s32 idx, s32 flag) {
    const u8* base = (const u8*)lbl_8048D320;
    u8* p;
    s32 off;
    f32 v29;
    f32 v31;
    f32 v30;
    off = idx * 4;
    p = self + off;
    v29 = *(f32*)(p + 0x118);
    v30 = *(f32*)(p + 0x138);
    v31 = *(f32*)(p + 0x148);
    s32 k;
    s32 j;
    const u64* a;
    const u64* b;
    const u64* one;
    if (idx >= 2) {
        u8* q = self + idx * 4;
        fn_80402E08(*(u8**)(p + 0x74), *(f32*)(q + 0xf8), fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0x84), lbl_80543A00, fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0x94), lbl_80543A00, fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xa4), lbl_80543A00, fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xb4), *(f32*)(q + 0xf8), fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xc4), *(f32*)(q + 0xf8), fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xd4), *(f32*)(q + 0xf8), fn_8043D57C(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xe4), *(f32*)(q + 0xf8), fn_8043D57C(lbl_8053AED0));
    } else {
        u8* q = self + idx * 4;
        fn_80402E08(*(u8**)(p + 0x74), *(f32*)(q + 0xf8), fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0x84), lbl_80543A00, fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0x94), lbl_80543A00, fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xa4), lbl_80543A00, fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xb4), *(f32*)(q + 0xf8), fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xc4), *(f32*)(q + 0xf8), fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xd4), *(f32*)(q + 0xf8), fn_8043D514(lbl_8053AED0));
        fn_80402E08(*(u8**)(p + 0xe4), *(f32*)(q + 0xf8), fn_8043D514(lbl_8053AED0));
    }
    fn_8037EB4C();
    u8 mask = (u8)(1 << idx);
    s32 t = (self[0x28f] & mask) != 0;
    if (t == 0 || (lbl_8053AED0[0xdc] & mask) != 0 || (*(u8**)(lbl_8053AB10 + 0x30))[0x284] != 0 ||
        lbl_8053AAF8[0x85] != 0) {
        if (*(f32*)(p + 0x118) > lbl_80543A04) {
            *(f32*)(p + 0x118) = *(f32*)(p + 0x118) - lbl_80543A04;
        } else {
            *(f32*)(p + 0x118) = lbl_80543A00;
        }
        if (*(f32*)(p + 0x138) > lbl_80543A04) {
            *(f32*)(p + 0x138) = *(f32*)(p + 0x138) - lbl_80543A04;
        } else {
            *(f32*)(p + 0x138) = lbl_80543A00;
        }
        if (*(f32*)(p + 0x148) > lbl_80543A04) {
            *(f32*)(p + 0x148) = *(f32*)(p + 0x148) - lbl_80543A04;
        } else {
            *(f32*)(p + 0x148) = lbl_80543A00;
        }
        (*(u8**)(lbl_8053AB10 + 0x20))[idx + 0x217] = 1;
    } else if (*(s32*)(lbl_80529DEC + off + 0xd8) == 0 && lbl_8053AEC8[0x5e] == 0) {
        if (*(f32*)(p + 0x118) > 0.6f) {
            *(f32*)(p + 0x118) = *(f32*)(p + 0x118) - lbl_80543A04;
            if (*(f32*)(p + 0x118) <= 0.6f) {
                *(f32*)(p + 0x118) = 0.6f;
            }
        } else if (*(f32*)(p + 0x118) < 0.6f) {
            *(f32*)(p + 0x118) = *(f32*)(p + 0x118) + lbl_80543A04;
            if (*(f32*)(p + 0x118) >= 0.6f) {
                *(f32*)(p + 0x118) = 0.6f;
            }
        }
        if ((*(u8**)(lbl_8053AB10 + 0x20))[idx + 0x14c] != 0) {
            if (*(f32*)(p + 0x138) < lbl_80543A18) {
                *(f32*)(p + 0x138) = *(f32*)(p + 0x138) + lbl_80543A04;
            } else {
                *(f32*)(p + 0x138) = lbl_80543A0C;
            }
            if (*(f32*)(p + 0x148) > 0.6f) {
                *(f32*)(p + 0x148) = *(f32*)(p + 0x148) - lbl_80543A04;
                if (*(f32*)(p + 0x148) <= 0.6f) {
                    *(f32*)(p + 0x148) = 0.6f;
                }
            } else if (*(f32*)(p + 0x148) < 0.6f) {
                *(f32*)(p + 0x148) = *(f32*)(p + 0x148) + lbl_80543A04;
                if (*(f32*)(p + 0x148) >= 0.6f) {
                    *(f32*)(p + 0x148) = 0.6f;
                }
            }
        } else {
            if (*(f32*)(p + 0x138) > lbl_80543A04) {
                *(f32*)(p + 0x138) = *(f32*)(p + 0x138) - lbl_80543A04;
            } else {
                *(f32*)(p + 0x138) = lbl_80543A00;
            }
            if (*(f32*)(p + 0x148) > lbl_80543A04) {
                *(f32*)(p + 0x148) = *(f32*)(p + 0x148) - lbl_80543A04;
            } else {
                *(f32*)(p + 0x148) = lbl_80543A00;
            }
        }
    } else {
        if (*(f32*)(p + 0x118) < lbl_80543A18) {
            *(f32*)(p + 0x118) = *(f32*)(p + 0x118) + lbl_80543A04;
        } else {
            *(f32*)(p + 0x118) = lbl_80543A0C;
        }
        if ((*(u8**)(lbl_8053AB10 + 0x20))[idx + 0x14c] != 0) {
            if (*(f32*)(p + 0x138) < lbl_80543A18) {
                *(f32*)(p + 0x138) = *(f32*)(p + 0x138) + lbl_80543A04;
            } else {
                *(f32*)(p + 0x138) = lbl_80543A0C;
            }
            if (*(f32*)(p + 0x148) < lbl_80543A18) {
                *(f32*)(p + 0x148) = *(f32*)(p + 0x148) + lbl_80543A04;
            } else {
                *(f32*)(p + 0x148) = lbl_80543A0C;
            }
        } else {
            if (*(f32*)(p + 0x138) > lbl_80543A04) {
                *(f32*)(p + 0x138) = *(f32*)(p + 0x138) - lbl_80543A04;
            } else {
                *(f32*)(p + 0x138) = lbl_80543A00;
            }
            if (*(f32*)(p + 0x148) > lbl_80543A04) {
                *(f32*)(p + 0x148) = *(f32*)(p + 0x148) - lbl_80543A04;
            } else {
                *(f32*)(p + 0x148) = lbl_80543A00;
            }
        }
    }

    if (v29 != *(f32*)(p + 0x118) || v30 != *(f32*)(p + 0x138) || v31 != *(f32*)(p + 0x148) || (u8)flag != 0) {
        HudFade8041* h = (HudFade8041*)self;
        one = (const u64*)(base + 0x4f8);
        one += idx * 2;
        (*(SubObj**)(self + 4))->w13(one[0])->w07((s32)((f32)self[0x24c] * *(f32*)(p + 0x118)));
        one = (const u64*)(base + 0x4f8);
        one += idx * 2;
        (*(SubObj**)(self + 4))->w13(one[1])->w07((s32)((f32)self[0x24d] * *(f32*)(p + 0x118)));
        a = (const u64*)(base + 0x3b8);
        b = (const u64*)(base + 0x458);
        a += idx * 5;
        b += idx * 5;
        for (j = 0; j < 5; j++) {
            (*(SubObj**)(self + 4))->w13(*a)->w07((s32)((f32)self[0x24e] * h->fade[idx]));
            (*(SubObj**)(self + 4))->w13(*b)->w07((s32)((f32)self[0x24f] * h->fade[idx]));
            a++; b++;
        }
        a = (const u64*)(base + 0x838);
        b = (const u64*)(base + 0x898);
        a += idx * 3;
        b += idx * 3;
        for (k = 0; k < 3; k++) {
            (*(SubObj**)(self + 4))->w13(*a)->w07((s32)((f32)self[0x258 + k] * h->fade[idx]));
            (*(SubObj**)(self + 4))->w13(*b)->w07((s32)((f32)self[0x25b + k] * h->fade[idx]));
            a++; b++;
        }
        a = (const u64*)(base + 0x538);
        b = (const u64*)(base + 0x6b8);
        a += idx * 12;
        b += idx * 12;
        for (k = 0; k < 12; k++) {
            (*(SubObj**)(self + 4))->w13(*a)->w07((s32)((f32)self[0x25e] * h->fade[idx]));
            (*(SubObj**)(self + 4))->w13(*b)->w07((s32)((f32)self[0x25f] * h->fade[idx]));
            a++; b++;
        }
        a = (const u64*)(base + 0x8f8);
        a += idx * 6;
        for (k = 0; k < 6; k++) {
            (*(SubObj**)(self + 4))->w13(*a)->w07((s32)((f32)self[0x260 + k] * h->fade[idx]));
            a++;
        }
        one = (const u64*)(base + 0xb40);
        one += idx;
        (*(SubObj**)(self + 4))->w13(*one)->w07((s32)((f32)self[0x266] * *(f32*)(p + 0x138)));
        one = (const u64*)(base + 0xb20);
        one += idx;
        (*(SubObj**)(self + 0x18))->w13(*one)->w07((s32)((f32)self[0x267] * *(f32*)(p + 0x148)));
        one = (const u64*)(base + 0xae0);
        one += idx;
        (*(SubObj**)(self + 0x18))->w13(*one)->w07((s32)((f32)self[0x268] * *(f32*)(p + 0x118)));
        one = (const u64*)(base + 0xb00);
        one += idx;
        (*(SubObj**)(self + 0x18))->w13(*one)->w07((s32)((f32)self[0x269] * *(f32*)(p + 0x118)));
        one = (const u64*)(base + 0xb80);
        one += idx;
        (*(SubObj**)(self + 4))->w13(*one)->w07((s32)((f32)self[0x26a] * *(f32*)(p + 0x118)));
        one = (const u64*)(base + 0xba0);
        one += idx;
        (*(SubObj**)(self + 4))->w13(*one)->w07((s32)((f32)self[0x26b] * *(f32*)(p + 0x118)));
        a = (const u64*)(base + 0x9d8);
        a += idx * 4;
        for (k = 0; k < 4; k++) {
            (*(SubObj**)(self + 4))->w13(*a)->w07((s32)((f32)self[0x26c + k] * h->fade[idx]));
            a++;
        }
    }
}
#pragma dont_inline reset

#pragma dont_inline on
extern "C" void fn_8041A868(u8* self, s32 arg) {
    const u8* base = (const u8*)lbl_8048D320;
    f32 old118 = *(f32*)(self + 0x118);
    f32 old158 = *(f32*)(self + 0x158);
    s32 flag = 0;
    if ((lbl_8053AAF8[0x83] & 3U) == 2) {
        flag = 1;
    }
    s32 r = fn_80418B64(self);
    u8 busy = 0;
    if (*(s16*)(self + 0x222) != (s16)r) {
        if (*(f32*)(self + 0x118) > lbl_80543A00) {
            busy = 1;
        } else {
            *(s16*)(self + 0x222) = r;
        }
    }
    s32 off = flag * 10;
    const u8* dac = base + 0xdac + off;
    s16 x = *(s16*)(lbl_8050DB0C + 0x232) + *(const s16*)(base + 0xdc0 + (off + *(s16*)(self + 0x222) * 2));
    s16 y = *(s16*)(lbl_8050DB0C + 0x234) + *(const s16*)(base + 0xdd4 + (off + *(s16*)(self + 0x222) * 2));
    if (*(const s16*)(dac + *(s16*)(self + 0x222) * 2) == 0) {
        y = y + fn_8043D514(lbl_8053AED0);
    } else {
        y = y + fn_8043D57C(lbl_8053AED0);
    }
    const u8* d98 = base + 0xd98 + off;
    fn_80402E08(*(u8**)(self + 0x54),
                (f32)(x + (*(const s16*)(d98 + *(s16*)(self + 0x222) * 2) + *(s16*)(lbl_8050DB0C + 0x2d2) +
                           *(const s16*)(base + 0xde8 + (off + *(s16*)(self + 0x222) * 2)))),
                (f32)*(s16*)(lbl_8050DB0C + 0x2d4) +
                    ((f32)y + (*(f32*)(self + 0x108) + (f32)*(const s16*)(dac + *(s16*)(self + 0x222) * 2))));
    const u8* e10 = base + 0xe10 + off;
    fn_80402E08(*(u8**)(self + 0x58),
                (f32)*(s16*)(lbl_8050DB0C + 0x2d6) +
                    ((f32)x + (*(f32*)(self + 0xf8) + (f32)*(const s16*)(d98 + *(s16*)(self + 0x222) * 2))) +
                    (f32)*(const s16*)(e10 + *(s16*)(self + 0x222) * 2),
                (f32)*(s16*)(lbl_8050DB0C + 0x2d8) +
                    ((f32)y + (*(f32*)(self + 0x108) + (f32)*(const s16*)(dac + *(s16*)(self + 0x222) * 2))));
    fn_80402E08(*(u8**)(self + 0x5c),
                (f32)*(s16*)(lbl_8050DB0C + 0x2d6) +
                    ((f32)x + (*(f32*)(self + 0xf8) + (f32)*(const s16*)(d98 + *(s16*)(self + 0x222) * 2))) +
                    (f32)*(const s16*)(e10 + *(s16*)(self + 0x222) * 2),
                (f32)*(s16*)(lbl_8050DB0C + 0x2d8) +
                    ((f32)y + (*(f32*)(self + 0x108) + (f32)*(const s16*)(dac + *(s16*)(self + 0x222) * 2))));
    fn_80402E08(*(u8**)(self + 0x6c),
                (f32)*(s16*)(lbl_8050DB0C + 0x2da) +
                    ((f32)x + (*(f32*)(self + 0xf8) + (f32)*(const s16*)(d98 + *(s16*)(self + 0x222) * 2))) +
                    (f32)*(const s16*)(base + 0xdfc + (off + *(s16*)(self + 0x222) * 2)),
                (f32)*(s16*)(lbl_8050DB0C + 0x2dc) +
                    ((f32)y + (*(f32*)(self + 0x108) + (f32)*(const s16*)(dac + *(s16*)(self + 0x222) * 2))));
    fn_80402E08(*(u8**)(self + 0x70),
                (f32)*(s16*)(lbl_8050DB0C + 0x2de) +
                    ((f32)x + (*(f32*)(self + 0xf8) + (f32)*(const s16*)(d98 + *(s16*)(self + 0x222) * 2))) +
                    (f32)*(const s16*)(base + 0xe24 + (off + *(s16*)(self + 0x222) * 2)),
                (f32)*(s16*)(lbl_8050DB0C + 0x2e0) +
                    ((f32)y + (*(f32*)(self + 0x108) + (f32)*(const s16*)(dac + *(s16*)(self + 0x222) * 2))));
    fn_8037EB4C();
    if ((self[0x28f] & 1) == 0 || (*(u8**)(lbl_8053AB10 + 0x30))[0x284] != 0 || lbl_8053AAF8[0x85] != 0 ||
        *(s16*)(self + 0x222) == 4 || busy) {
        if (*(f32*)(self + 0x118) > lbl_80543A04) {
            *(f32*)(self + 0x118) = *(f32*)(self + 0x118) - lbl_80543A04;
        } else {
            *(f32*)(self + 0x118) = lbl_80543A00;
        }
        if (*(f32*)(self + 0x158) > lbl_80543A04) {
            *(f32*)(self + 0x158) = *(f32*)(self + 0x158) - lbl_80543A04;
        } else {
            *(f32*)(self + 0x158) = lbl_80543A00;
        }
        (*(u8**)(lbl_8053AB10 + 0x20))[0x217] = 1;
    } else if (*(s32*)(lbl_80529DEC + 0xd8) == 0 && lbl_8053AEC8[0x5e] == 0) {
        if (*(f32*)(self + 0x118) > 0.6f) {
            *(f32*)(self + 0x118) = *(f32*)(self + 0x118) - lbl_80543A04;
            if (*(f32*)(self + 0x118) <= 0.6f) {
                *(f32*)(self + 0x118) = 0.6f;
            }
        } else if (*(f32*)(self + 0x118) < 0.6f) {
            *(f32*)(self + 0x118) = *(f32*)(self + 0x118) + lbl_80543A04;
            if (*(f32*)(self + 0x118) >= 0.6f) {
                *(f32*)(self + 0x118) = 0.6f;
            }
        }
        if (lbl_8053AED0[0x10e] & 1) {
            if (*(f32*)(self + 0x158) > 0.6f) {
                *(f32*)(self + 0x158) = *(f32*)(self + 0x158) - lbl_80543A04;
                if (*(f32*)(self + 0x158) <= 0.6f) {
                    *(f32*)(self + 0x158) = 0.6f;
                }
            } else if (*(f32*)(self + 0x158) < 0.6f) {
                *(f32*)(self + 0x158) = *(f32*)(self + 0x158) + lbl_80543A04;
                if (*(f32*)(self + 0x158) >= 0.6f) {
                    *(f32*)(self + 0x158) = 0.6f;
                }
            }
        } else {
            if (*(f32*)(self + 0x158) > lbl_80543A04) {
                *(f32*)(self + 0x158) = *(f32*)(self + 0x158) - lbl_80543A04;
            } else {
                *(f32*)(self + 0x158) = lbl_80543A00;
            }
        }
    } else {
        if (*(f32*)(self + 0x118) < lbl_80543A18) {
            *(f32*)(self + 0x118) = *(f32*)(self + 0x118) + lbl_80543A04;
        } else {
            *(f32*)(self + 0x118) = lbl_80543A0C;
        }
        if (lbl_8053AED0[0x10e] & 1) {
            if (*(f32*)(self + 0x158) < lbl_80543A18) {
                *(f32*)(self + 0x158) = *(f32*)(self + 0x158) + lbl_80543A04;
            } else {
                *(f32*)(self + 0x158) = lbl_80543A0C;
            }
        } else {
            if (*(f32*)(self + 0x158) > lbl_80543A04) {
                *(f32*)(self + 0x158) = *(f32*)(self + 0x158) - lbl_80543A04;
            } else {
                *(f32*)(self + 0x158) = lbl_80543A00;
            }
        }
    }
    f32 cur = *(f32*)(self + 0x118);
    if (old118 != cur || old158 != *(f32*)(self + 0x158) || (u8)arg != 0) {
        const u64* one;
        const u64* a;
        const u64* b;
        const u64* c;
        const u64* d;
        s32 j;
        one = (const u64*)(base + 0x388);
        (*(SubObj**)(self + 4))->w13(one[0])->w07((s32)((f32)self[0x24c] * cur));
        one = (const u64*)(base + 0x388);
        (*(SubObj**)(self + 4))->w13(one[1])->w07((s32)((f32)self[0x24d] * *(f32*)(self + 0x118)));
        a = (const u64*)(base + 0x338);
        b = (const u64*)(base + 0x360);
        for (j = 0; j < 5; j++) {
            (*(SubObj**)(self + 4))->w13(*a)->w07((s32)((f32)self[0x24e] * *(f32*)(self + 0x118)));
            (*(SubObj**)(self + 4))->w13(*b)->w07((s32)((f32)self[0x24f] * *(f32*)(self + 0x118)));
            b++;
            a++;
        }
        a = (const u64*)(base + 0x308);
        b = (const u64*)(base + 0x320);
        for (j = 0; j < 3; j++) {
            (*(SubObj**)(self + 4))->w13(*a)->w07((s32)((f32)self[0x258 + j] * *(f32*)(self + 0x118)));
            (*(SubObj**)(self + 4))->w13(*b)->w07((s32)((f32)self[0x25b + j] * *(f32*)(self + 0x118)));
            b++;
            a++;
        }
        a = (const u64*)(base + 0x248);
        b = (const u64*)(base + 0x2a8);
        for (j = 0; j < 12; j++) {
            (*(SubObj**)(self + 4))->w13(*a)->w07((s32)((f32)self[0x25e] * *(f32*)(self + 0x118)));
            (*(SubObj**)(self + 4))->w13(*b)->w07((s32)((f32)self[0x25f] * *(f32*)(self + 0x118)));
            b++;
            a++;
        }
        a = (const u64*)(base + 0x148);
        b = (const u64*)(base + 0x188);
        c = (const u64*)(base + 0x1c8);
        d = (const u64*)(base + 0x208);
        for (j = 0; j < 8; j++) {
            (*(SubObj**)(self + 4))->w13(*a)->w07((s32)((f32)self[0x250] * *(f32*)(self + 0x118)));
            (*(SubObj**)(self + 4))->w13(*b)->w07((s32)((f32)self[0x251] * *(f32*)(self + 0x118)));
            (*(SubObj**)(self + 4))->w13(*c)->w07((s32)((f32)self[0x252] * *(f32*)(self + 0x118)));
            (*(SubObj**)(self + 4))->w13(*d)->w07((s32)((f32)self[0x253] * *(f32*)(self + 0x118)));
            b++;
            c++;
            d++;
            a++;
        }
        (*(SubObj**)(self + 4))->w13(0x506870316e693032ULL)->w07((s32)((f32)self[0x26a] * *(f32*)(self + 0x118)));
        (*(SubObj**)(self + 4))->w13(0x506870316e693031ULL)->w07((s32)((f32)self[0x26b] * *(f32*)(self + 0x118)));
        a = (const u64*)(base + 0x398);
        for (j = 0; j < 4; j++) {
            (*(SubObj**)(self + 4))->w13(*a)->w07((s32)((f32)self[0x26c + j] * *(f32*)(self + 0x118)));
            a++;
        }
    }
}
#pragma dont_inline reset

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

extern "C" void fn_8041C0C0(u8* self_, s32 idx) {
    u8* base = (u8*)lbl_8048D320;
    u8* self = self_;
    s32 n;
    s32 which;
    s32 i;
    u32 tag;

    if (self[0x28b] & (u8)(1 << idx)) {
        which = 0;
        s32 value = ((s32*)lbl_80529DEC)[idx + 0x3a];
        n = value;
        if (value > 9999) n = 9999;
        if (n < 0) {
            s32 off = idx * 0x28;
            u64* first = (u64*)(base + 0x3b8);
            first = (u64*)((u8*)first + off);
            u64* p = first;
            for (i = 0; i < 5; i++) {
                ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*p))->setBlackWhite(JUtility::TColor(0, 0, 0, 0), JUtility::TColor(255, 85, 65, 255));
                p++;
            }
            if (n < -5000) {
                n = -5000;
            }
            n *= -1;
            tag = fn_804030C4(0x54494d47, (u32)(base + 0xe38));
            ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*first))->changeTexture((ResTIMG*)tag, 0);
            ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(((u8*)((u64*)(base + 0x458) + idx * 5)))))->changeTexture((ResTIMG*)tag, 0);
            (*(J2DPane**)(self + 4))->search(*(u64*)(((u8*)((u64*)(base + 0x3b8) + idx * 5)) + 0x20))->show();
            (*(J2DPane**)(self + 4))->search(*(u64*)(((u8*)((u64*)(base + 0x458) + idx * 5)) + 0x20))->show();
            which = 1;
        } else {
            s32 off = idx * 0x28;
            u64* p = (u64*)(base + 0x3b8);
            p = (u64*)((u8*)p + off);
            for (s32 j = 0; j < 5; j++, p++) {
                ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*p))->setBlackWhite(*(JUtility::TColor*)(self + 0x248), *(JUtility::TColor*)(self + 0x244));
            }
            (*(J2DPane**)(self + 4))->search(*(u64*)(((u8*)((u64*)(base + 0x3b8) + idx * 5)) + 0x20))->hide();
            (*(J2DPane**)(self + 4))->search(*(u64*)(((u8*)((u64*)(base + 0x458) + idx * 5)) + 0x20))->hide();
        }

        s32 digit1000 = n / 1000;
        n %= 1000;
        tag = fn_804030C4(0x54494d47, lbl_804B139C[digit1000]);
        u64* a = (u64*)(base + 0x3b8);
        a = (u64*)((u8*)a + idx * 0x28);
        ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(((u8*)a) + which * 8)))->changeTexture((ResTIMG*)tag, 0);
        u64* b = (u64*)(base + 0x458);
        b = (u64*)((u8*)b + idx * 0x28);
        ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(((u8*)b) + which * 8)))->changeTexture((ResTIMG*)tag, 0);
        s32 digit100 = n / 100;
        n %= 100;
        tag = fn_804030C4(0x54494d47, lbl_804B139C[digit100]);
        ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(((u8*)a) + (which + 1) * 8)))->changeTexture((ResTIMG*)tag, 0);
        ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(((u8*)b) + (which + 1) * 8)))->changeTexture((ResTIMG*)tag, 0);
        s32 digit10 = n / 10;
        n %= 10;
        tag = fn_804030C4(0x54494d47, lbl_804B139C[digit10]);
        ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(((u8*)a) + (which + 2) * 8)))->changeTexture((ResTIMG*)tag, 0);
        ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(((u8*)b) + (which + 2) * 8)))->changeTexture((ResTIMG*)tag, 0);
        tag = fn_804030C4(0x54494d47, lbl_804B139C[n]);
        ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(((u8*)a) + (which + 3) * 8)))->changeTexture((ResTIMG*)tag, 0);
        ((J2DPicture*)(*(J2DPane**)(self + 4))->search(*(u64*)(((u8*)b) + (which + 3) * 8)))->changeTexture((ResTIMG*)tag, 0);
    }
}

extern const u64 lbl_8048D320[];
extern const char* lbl_804B13C4[];
extern u8 lbl_8050EC80[];
extern "C" void fn_80419C38(u8* self, s32 i, s32 v);
#pragma opt_lifetimes off
extern "C" void fn_8041C67C(u8* this_) {
    u8* state;
    const u8* base;
    const u64* p29;
    const u64* p28;
    const u64* p27;
    const u64* p26;
    const u64* p25;
    const u64* p24;
    const u64* p23;
    const u64* p22;
    const u64* p21;
    const u64* p20;
    u8* self = this_;
    base = (const u8*)lbl_8048D320;

	HudHidePane8041(self, 0x004E646174613133ULL);
	HudHidePane8041(self, 0x506870316E693032ULL);
	HudHidePane8041(self, 0x5068317069696233ULL);
	HudHidePane8041(self, 0x004E646174613136ULL);
	HudHidePane8041(self, 0x004E646174613032ULL);
	p20 = (const u64*)(base + 0xae0);
	p29 = p20;
	p28 = (const u64*)(base + 0xb20);
	p27 = (const u64*)(base + 0xb40);
	p26 = (const u64*)(base + 0xb60);
	p25 = (const u64*)(base + 0xb80);
	p24 = (const u64*)(base + 0xbc0);
	p23 = (const u64*)(base + 0xbe0);
	p22 = (const u64*)(base + 0xc00);
	p21 = (const u64*)(base + 0x9d8);
    state = lbl_8050EC80;

	for (s32 i = 0; i < 4; i++) {
		if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
			((J2DPane*)(*(SubObj**)(self + 0x18))->w13(*p29))->hide();
			((J2DPane*)(*(SubObj**)(self + 0x18))->w13(*p28))->hide();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(*p27))->hide();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(*p26))->show();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(*p25))->hide();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(*p24))->show();
			if (lbl_8050EC80[*(u32*)(state + 0x10) * 0xc8 + 0x88]) {
				((J2DPane*)(*(SubObj**)(self + 4))->w13(*p23))->show();
			} else {
				((J2DPane*)(*(SubObj**)(self + 4))->w13(*p23))->hide();
			}
			((J2DPane*)(*(SubObj**)(self + 4))->w13(*p22))->show();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(p21[0]))->hide();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(p21[1]))->hide();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(p21[2]))->hide();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(p21[3]))->hide();
		} else {
			((J2DPane*)(*(SubObj**)(self + 0x18))->w13(*p29))->hide();
			((J2DPane*)(*(SubObj**)(self + 0x18))->w13(*p28))->hide();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(*p27))->hide();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(*p26))->hide();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(*p25))->hide();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(*p24))->hide();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(*p23))->hide();
			((J2DPane*)(*(SubObj**)(self + 4))->w13(*p22))->hide();
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

	const u64* q22 = (const u64*)(base + 0xb00);
	s32 digit = 0;
    do {
        u32 texture = fn_804030C4(0x54494d47, (u32)lbl_804B13C4[0]);
        ((J2DPicture*)(*(SubObj**)(self + 0x18))->w13(*p20))->changeTexture((const ResTIMG*)texture, 0);
        ((J2DPicture*)(*(SubObj**)(self + 0x18))->w13(*q22))->changeTexture((const ResTIMG*)texture, 0);
        p20++;
        q22++;
    } while (++digit < 4);

	for (s32 i = 0; i < 4; i++) {
		if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
			fn_80419C38(self, i, 1);
		}
	}
}
#pragma opt_common_subs on
#pragma opt_strength_reduction on
extern "C" void fn_8041CC04(u8* this_) {
    u8* self = this_;
    const u64* base = lbl_8048D320;
    s32 n;
    s32 which;
    s32 i;
    const u64* p;
    s32 off;
    u32 tag;
    if (self[0x28b] & 1) {
        which = 0;
        s32 v = *(s32*)(lbl_80529DEC + 0xe8);
        n = v;
        if (v > 9999) n = 9999;
        if (n < 0) {
            const u64* first = base + 0x67;
            p = first;
            for (i = 0; i < 5; i++, p++) {
                ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(*p))->setBlackWhite(JUtility::TColor(0,0,0,0), JUtility::TColor(255,85,65,255));
            }
            if (n < -5000) n = -5000;
            n *= -1;
            tag = fn_804030C4(0x54494d47, (u32)((u8*)base + 0xe38));
            ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(*first))->changeTexture((ResTIMG*)tag, 0);
            ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(base[0x6c]))->changeTexture((ResTIMG*)tag, 0);
            (*(J2DScreen**)(self + 4))->search(((const u64*)((u32)base+0x338))[4])->show();
            (*(J2DScreen**)(self + 4))->search(((const u64*)((u32)base+0x360))[4])->show();
            which = 1;
        } else {
            for (i = 0, p = base + 0x67; i < 5; i++, p++) {
                ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(*p))->setBlackWhite(*(JUtility::TColor*)(self+0x248), *(JUtility::TColor*)(self+0x244));
            }
            (*(J2DScreen**)(self + 4))->search(((const u64*)((u32)base+0x338))[4])->hide();
            (*(J2DScreen**)(self + 4))->search(((const u64*)((u32)base+0x360))[4])->hide();
        }
        s32 digit1000 = n / 1000;
        n %= 1000;
        tag = fn_804030C4(0x54494d47, lbl_804B139C[digit1000]);
        off = (which) * 8;
        ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(*(const u64*)((u32)(base+0x67)+off)))->changeTexture((ResTIMG*)tag, 0);
        ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(*(const u64*)((u32)(base+0x6c)+off)))->changeTexture((ResTIMG*)tag, 0);
        s32 digit100 = n / 100;
        n %= 100;
        tag = fn_804030C4(0x54494d47, lbl_804B139C[digit100]);
        off = (which+1) * 8;
        ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(*(const u64*)((u32)(base+0x67)+off)))->changeTexture((ResTIMG*)tag, 0);
        ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(*(const u64*)((u32)(base+0x6c)+off)))->changeTexture((ResTIMG*)tag, 0);
        s32 digit10 = n / 10;
        n %= 10;
        tag = fn_804030C4(0x54494d47, lbl_804B139C[digit10]);
        off = (which+2) * 8;
        ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(*(const u64*)((u32)(base+0x67)+off)))->changeTexture((ResTIMG*)tag, 0);
        ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(*(const u64*)((u32)(base+0x6c)+off)))->changeTexture((ResTIMG*)tag, 0);
        tag = fn_804030C4(0x54494d47, lbl_804B139C[n]);
        off = (which+3) * 8;
        ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(*(const u64*)((u32)(base+0x67)+off)))->changeTexture((ResTIMG*)tag, 0);
        ((J2DPicture*)(*(J2DScreen**)(self + 4))->search(*(const u64*)((u32)(base+0x6c)+off)))->changeTexture((ResTIMG*)tag, 0);
    }
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
extern u8* lbl_8053AD30;
extern "C" u8 fn_80230188(s32);
extern "C" u8 fn_8023BE0C(void);
extern "C" u32 fn_8030AAF4(s32);
extern "C" s32 fn_80309D24(u8*, u32, s32);
#pragma dont_inline on
extern "C" u8 fn_80236D14(s32);
extern "C" u8 fn_80236E3C(s32);
extern "C" u32 fn_802373EC(s32);
extern "C" s32 fn_8023725C(s32);
extern "C" void fn_8041D18C(u8* self_, s32 index_) {
    s32 sel;
    s32 index;
    u8* self;
    u8 mask;
    const u64* base;
    u8* pane;
    self = self_;
    index = index_;
    base = lbl_8048D320;
    sel = -1;
    if (lbl_8053AAF8[0x7e] == 0) {
        mask = (u8)(1 << index);
        s32 on = (self[0x28d] & mask) != 0;
        if (on == 0 && fn_80230188(index) == 0) {
            fn_8022EA0C(index);
            if (fn_8023BE0C() != 0 && (lbl_8053AED0[0x255] & mask) == 0) {
                self[0x28d] |= mask;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(0x506870316e693032ULL);
                pane[0xb0] = 1;
            }
        } else if ((u32)fn_80309D24(lbl_8053AD30, fn_8030AAF4(index), 0x100) == 0 ||
                   (lbl_8053AED0[0x255] & mask) != 0 || fn_80230188(index) != 0) {
            self[0x28d] &= ~mask;
            pane = (u8*)(*(J2DScreen**)(self + 4))->search(0x506870316e693032ULL);
            pane[0xb0] = 0;
        }
        if (fn_80236D14(index)) {
            if (((u8*)(*(J2DScreen**)(self + 4))->search(base[0x73]))[0xb0] == 0) {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(base[0x73]);
                pane[0xb0] = 1;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search((base + 0x73)[1]);
                pane[0xb0] = 1;
            }
        } else if (((u8*)(*(J2DScreen**)(self + 4))->search(base[0x73]))[0xb0] == 1) {
            pane = (u8*)(*(J2DScreen**)(self + 4))->search(base[0x73]);
            pane[0xb0] = 0;
            pane = (u8*)(*(J2DScreen**)(self + 4))->search((base + 0x73)[1]);
            pane[0xb0] = 0;
        }
        if (fn_80236E3C(index)) {
            const u64* t = base + 0x73;
            if (((u8*)(*(J2DScreen**)(self + 4))->search(t[2]))[0xb0] == 0) {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(t[2]);
                pane[0xb0] = 1;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(t[3]);
                pane[0xb0] = 1;
            }
        } else {
            const u64* t = base + 0x73;
            if (((u8*)(*(J2DScreen**)(self + 4))->search(t[2]))[0xb0] == 1) {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(t[2]);
                pane[0xb0] = 0;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(t[3]);
                pane[0xb0] = 0;
            }
        }
    } else {
        mask = (u8)(1 << index);
        s32 on = (self[0x28d] & mask) != 0;
        if (on == 0 && fn_80230188(index) == 0) {
            fn_8022EA0C(index);
            if (fn_8023BE0C() != 0 && (lbl_8053AED0[0x255] & mask) == 0) {
                self[0x28d] |= mask;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(base[0x137 + index]);
                pane[0xb0] = 1;
            }
        } else if ((u32)fn_80309D24(lbl_8053AD30, fn_8030AAF4(index), 0x100) == 0 ||
                   (lbl_8053AED0[0x255] & mask) != 0 || fn_80230188(index) != 0) {
            self[0x28d] &= ~mask;
            pane = (u8*)(*(J2DScreen**)(self + 4))->search(base[0x137 + index]);
            pane[0xb0] = 0;
        }
        if (fn_80236D14(index)) {
            const u64* t = base + 0x13b + index * 4;
            if (((u8*)(*(J2DScreen**)(self + 4))->search(t[0]))[0xb0] == 0) {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(t[0]);
                pane[0xb0] = 1;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search((base + 0x13b + index * 4)[1]);
                pane[0xb0] = 1;
            }
        } else {
            const u64* t = base + 0x13b + index * 4;
            if (((u8*)(*(J2DScreen**)(self + 4))->search(t[0]))[0xb0] == 1) {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(t[0]);
                pane[0xb0] = 0;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search((base + 0x13b + index * 4)[1]);
                pane[0xb0] = 0;
            }
        }
        if (fn_80236E3C(index)) {
            const u64* t = base + 0x13b + index * 4 + 2;
            if (((u8*)(*(J2DScreen**)(self + 4))->search(t[0]))[0xb0] == 0) {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(t[0]);
                pane[0xb0] = 1;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search((base + 0x13b + index * 4)[3]);
                pane[0xb0] = 1;
            }
        } else {
            const u64* t = base + 0x13b + index * 4 + 2;
            if (((u8*)(*(J2DScreen**)(self + 4))->search(t[0]))[0xb0] == 1) {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(t[0]);
                pane[0xb0] = 0;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search((base + 0x13b + index * 4)[3]);
                pane[0xb0] = 0;
            }
        }
    }
    switch (fn_802373EC(index)) {
    case 1: sel = 5; break;
    case 2: sel = 0xb; break;
    case 3: sel = 2; break;
    case 4: sel = 3; break;
    case 5: sel = 6; break;
    case 6: sel = 7; break;
    case 7: sel = 4; break;
    case 8: sel = 8; break;
    case 9: sel = 0xa; break;
    case 10: sel = 1; break;
    case 11:
    case 12:
    case 13: sel = 0; break;
    }
    s32* cur = (s32*)(self + 0x178) + index;
    if (sel == *cur && (lbl_8053AED0[0x255] & (u8)(1 << index)) == 0) {
        return;
    }
    *cur = sel;
    const u64* a0 = base + 0x49;
    const u64* b0 = base + 0x55;
    const u64* a1 = base + 0xa7 + index * 12;
    const u64* b1 = base + 0xd7 + index * 12;
    const u64* pa0 = a0;
    const u64* pb0 = b0;
    const u64* pa1 = a1;
    const u64* pb1 = b1;
    s32 i;
    for (i = 0; i < 12; i++) {
        if (lbl_8053AAF8[0x7e] == 0) {
            if (i == sel) {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*pa0);
                pane[0xb0] = 1;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*pb0);
                pane[0xb0] = 1;
            } else {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*pa0);
                pane[0xb0] = 0;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*pb0);
                pane[0xb0] = 0;
            }
        } else {
            if (i == sel) {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*pa1);
                pane[0xb0] = 1;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*pb1);
                pane[0xb0] = 1;
            } else {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*pa1);
                pane[0xb0] = 0;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*pb1);
                pane[0xb0] = 0;
            }
        }
        pb0++;
        pa1++;
        pb1++;
        pa0++;
    }
    if (lbl_8053AAF8[0x7e] == 0) {
        for (i = 0; i < 12; i++) {
            if (i == sel) {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*a0);
                pane[0xb0] = 1;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*b0);
                pane[0xb0] = 1;
            } else {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*a0);
                pane[0xb0] = 0;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*b0);
                pane[0xb0] = 0;
            }
            b0++;
            a0++;
        }
        if (fn_8023725C(index) == 2) {
            const u64* t = base + 0x64;
            for (s32 j = 0; j < 3; j++) {
                ((u8*)(*(J2DScreen**)(self + 4))->search(*t))[0xb0] = 1;
                t++;
            }
        } else {
            const u64* t = base + 0x64;
            for (s32 j = 0; j < 3; j++) {
                ((u8*)(*(J2DScreen**)(self + 4))->search(*t))[0xb0] = 0;
                t++;
            }
        }
    } else {
        for (i = 0; i < 12; i++) {
            if (i == sel) {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*a1);
                pane[0xb0] = 1;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*b1);
                pane[0xb0] = 1;
            } else {
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*a1);
                pane[0xb0] = 0;
                pane = (u8*)(*(J2DScreen**)(self + 4))->search(*b1);
                pane[0xb0] = 0;
            }
            b1++;
            a1++;
        }
        if (fn_8023725C(index) == 2) {
            const u64* t = base + 0x113 + index * 3;
            for (s32 j = 0; j < 3; j++) {
                ((u8*)(*(J2DScreen**)(self + 4))->search(*t))[0xb0] = 1;
                t++;
            }
        } else {
            const u64* t = base + 0x113 + index * 3;
            for (s32 j = 0; j < 3; j++) {
                ((u8*)(*(J2DScreen**)(self + 4))->search(*t))[0xb0] = 0;
                t++;
            }
        }
    }
}

#pragma dont_inline reset
extern "C" void fn_8041DD24(void* this_) {
    s32 cnt;
    u8* self = (u8*)this_;
    u8* base;
    const u64* p31;
    const u64* p30;
    const u64* p29;
    const u64* p28;
    s32 n;
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
        p31 = (const u64*)(base + 0x148);
        p30 = (const u64*)(base + 0x188);
        p29 = (const u64*)(base + 0x1c8);
        p28 = (const u64*)(base + 0x208);
        for (i = 0; i < 8; i++) {
            if (cnt >= 4) {
                SetScreenPaneVisible(self, *p31, 1);
                SetScreenPaneVisible(self, *p30, 1);
                SetScreenPaneBlend(self, *p31, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                SetScreenPaneBlend(self, *p30, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                SetScreenPaneVisible(self, *p29, 0);
                SetScreenPaneVisible(self, *p28, 0);
                cnt -= 4;
                n -= 4;
            } else {
                if (cnt == 0) {
                    SetScreenPaneVisible(self, *p31, 0);
                    SetScreenPaneVisible(self, *p30, 0);
                    if (n > 0) {
                        SetScreenPaneVisible(self, *p29, 1);
                        SetScreenPaneVisible(self, *p28, 1);
                        n -= 4;
                    } else {
                        SetScreenPaneVisible(self, *p29, 0);
                        SetScreenPaneVisible(self, *p28, 0);
                    }
                } else if (cnt == 1) {
                    SetScreenPaneVisible(self, *p31, 1);
                    SetScreenPaneVisible(self, *p30, 1);
                    SetScreenPaneBlend(self, *p31, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetScreenPaneBlend(self, *p30, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetScreenPaneVisible(self, *p29, 0);
                    SetScreenPaneVisible(self, *p28, 0);
                    n -= 4;
                } else if (cnt == 2) {
                    SetScreenPaneVisible(self, *p31, 1);
                    SetScreenPaneVisible(self, *p30, 1);
                    SetScreenPaneBlend(self, *p31, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetScreenPaneBlend(self, *p30, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetScreenPaneVisible(self, *p29, 0);
                    SetScreenPaneVisible(self, *p28, 0);
                    n -= 4;
                } else if (cnt == 3) {
                    SetScreenPaneVisible(self, *p31, 1);
                    SetScreenPaneVisible(self, *p30, 1);
                    SetScreenPaneBlend(self, *p31, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetScreenPaneBlend(self, *p30, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
                    SetScreenPaneVisible(self, *p29, 0);
                    SetScreenPaneVisible(self, *p28, 0);
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
        *(s16*)(this_ + i * 2 + 0x224) = (s16)((val < 0 ? -val : val) / 100);
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



struct HudCounters8041 {
    u8 pad000[0x198];
    s32 countDelay[4];
    s32 gaugeDelay[4];
    u8 pad1b8[0x21a - 0x1b8];
    s16 transition[4];
    u8 pad222[2];
    s16 timer[4];
    s16 cooldown[4];
};


static inline bool HudCountPending8041(u8 mask) {
    return (lbl_80529DEC[0x239] & mask) != 0;
}


static inline void HudStoreCountResult8041(u8* self, s32 idx, s32 result) {
    *(s32*)(self + idx * 4 + 0x1f8) = result;
}

static inline void HudSyncCount8041(s32 idx) {
    u8* dst = lbl_80529DEC;
    s32* src = (s32*)(lbl_80529DEC + idx * 4 + 0xd8);
    for (s32 i = 0; i < 4; i++, dst += 4) {
        if (i != idx && fn_8022F514(i) && fn_8022F3DC(i) == idx) {
            *(s32*)(dst + 0xd8) = *src;
        }
    }
}

static inline void HudSetCountTransition8041(u8* self, s32 idx, s32* source) {
    u8* p2 = self + idx * 2;
    u8* p4 = self + idx * 4;
    *(s16*)(p2 + 0x21a) = *(s16*)(lbl_8050DB0C + 0x74) * *(s16*)(lbl_8050DB0C + 0x76) + 0x1e;
    *(s32*)(p4 + 0x1e8) = *(s32*)(p4 + 0x1d8);
    *(s32*)(p4 + 0x1d8) = *source;
    HudStoreCountResult8041(self, idx, fn_80237810(idx));
}

#pragma opt_propagation off
extern "C" void fn_8041E8B4(u8* this_, s32 idx) {
    s32 cnt;
    s32 i;
    s32 flag;
    u32 bit;
    u8 mask;

    bit = 1 << idx;
    mask = bit;

    flag = HudCountPending8041(mask);
    if (flag) {
        cnt = fn_80237774(idx);
        s32* slot = (s32*)(lbl_80529DEC + idx * 4 + 0xd8);
        *(s32*)(lbl_80529DEC + idx * 4 + 0xd8) = cnt;
        HudSyncCount8041(idx);
        this_[0x28a] |= (u8)bit;
        ((HudCounters8041*)(this_ + idx * 4))->countDelay[0] = 0;
        HudSetCountTransition8041(this_, idx, slot);
        lbl_80529DEC[0x239] &= ~mask;
    } else {
        s32* slot = (s32*)(lbl_80529DEC + idx * 4 + 0xd8);
        cnt = *slot;
        if (cnt < (s32)fn_80237774(idx)) {
            ((HudCounters8041*)(this_ + idx * 4))->countDelay[0] += 1;
            if (((HudCounters8041*)(this_ + idx * 4))->countDelay[0] >= 10) {
                *slot += 1;
                HudSyncCount8041(idx);
                this_[0x28a] |= (u8)bit;
                ((HudCounters8041*)(this_ + idx * 4))->countDelay[0] = 0;
                fn_80230EB8(idx, 9);
            }
            if (this_[0x291] != 0) {
                HudSetCountTransition8041(this_, idx, slot);
            }
        } else {
            cnt = *slot;
            if (cnt > (s32)fn_80237774(idx)) {
            lbl_80529DEC[0x24a] |= mask;
            ((HudCounters8041*)(this_ + idx * 4))->countDelay[0] += 1;
            if (((HudCounters8041*)(this_ + idx * 4))->countDelay[0] >= 10) {
                *slot -= 1;
                HudSyncCount8041(idx);
                this_[0x28a] |= (u8)bit;
                ((HudCounters8041*)(this_ + idx * 4))->countDelay[0] = 0;
            }
            if (this_[0x291] != 0) {
                HudSetCountTransition8041(this_, idx, slot);
            }
        } else {
            ((HudCounters8041*)(this_ + idx * 4))->countDelay[0] = 0;
        }
    }

    }
    {
        s32* slot = (s32*)(lbl_80529DEC + idx * 4 + 0xe8);
        cnt = *slot;
        if (cnt < (s32)fn_80236100(idx)) {
            ((HudCounters8041*)(this_ + idx * 4))->gaugeDelay[0]++;
            if (((HudCounters8041*)(this_ + idx * 4))->gaugeDelay[0] >= 2) {
                *slot += 2;
                cnt = *slot;
                if (cnt >= (s32)fn_80236100(idx)) {
                    *slot = fn_80236100(idx);
                    fn_80230EB8(idx, 0x51);
                } else {
                    fn_80230EB8(idx, 4);
                }
                this_[0x28b] |= (u8)bit;
                ((HudCounters8041*)(this_ + idx * 4))->gaugeDelay[0] = 0;
            }
        } else {
            cnt = *slot;
            if (cnt > (s32)fn_80236100(idx)) {
                ((HudCounters8041*)(this_ + idx * 4))->gaugeDelay[0]++;
                if (((HudCounters8041*)(this_ + idx * 4))->gaugeDelay[0] >= 2) {
                    *slot -= 2;
                    cnt = *slot;
                    if (cnt <= (s32)fn_80236100(idx)) {
                        *slot = fn_80236100(idx);
                        fn_80230EB8(idx, 0x51);
                    } else {
                        fn_80230EB8(idx, 0x4e);
                    }
                    this_[0x28b] |= (u8)bit;
                    ((HudCounters8041*)(this_ + idx * 4))->gaugeDelay[0] = 0;
                }
            } else {
                ((HudCounters8041*)(this_ + idx * 4))->gaugeDelay[0] = 0;
            }
        }
    }

    if (((HudCounters8041*)(this_ + idx * 2))->timer[0] > 0) {
        if (((HudCounters8041*)(this_ + idx * 2))->cooldown[0] == 0) {
            ((HudCounters8041*)(this_ + idx * 2))->timer[0] -= 1;
            fn_80230FD0(idx, 0x20034);
            if (((HudCounters8041*)(this_ + idx * 2))->timer[0] != 0) {
                ((HudCounters8041*)(this_ + idx * 2))->cooldown[0] = 0xc;
            }
        } else {
            ((HudCounters8041*)(this_ + idx * 2))->cooldown[0] -= 1;
        }
    }
}
#pragma opt_propagation reset
#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void fn_8041EDB0(u8* self) {
    const u64* tags = lbl_8048D320;
    int i;
    const u64* a;
    const u64* b;
    const u64* c;
    const u64* paneTag;
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
extern const f32 lbl_80543A34;
extern const f32 lbl_80543A38;
extern const f32 lbl_80543A3C;
static inline bool HudHideTimer8041() {
    if (*(s32*)(lbl_8053AAF8 + 0x4c) == 0xb) return 1;
    return lbl_8053AAF8[0x88] == 2;
}
#pragma opt_common_subs off
extern "C" void fn_8041F720(u8* self) {
    f32 ay;
    f32 ax;
    f32 by;
    f32 bx;
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
                        fn_8030C5F0(*(void**)(lbl_8053AB10 + 0x24), ((void* (*)(s32))fn_8023E724)(fn_8022EA0C(i)), 0, 0, buf);
                        JUTVideo* vp = JUTVideo::getManager();
                        s32 fa = vp->getFbWidth();
                        s32 fb = vp->getEfbHeight();
                                                f32 zero = lbl_80543A00;
                        J2DOrthoGraph* graph = (J2DOrthoGraph*)*(u8**)(self + 0x4c);
                        f32 c = (f32)(s32)*(s16*)(lbl_8050DB0C + 0x4e);
                        f32 xx = sx * (buf[0] / (f32)fa);
                        ax = xx - (f32)fa * lbl_80543A34;
                        f32 yy = sy * (buf[1] / (f32)fb);
                        ay = c + (yy - (f32)fb * lbl_80543A34);
                        JGeometry::TBox2f box(zero, zero, ex, ey);
                        graph->setOrtho(box, lbl_80543A38, lbl_80543A3C);
                        ((J2DOrthoGraph*)*(u8**)(self + 0x4c))->setPort();
                        ((J2DScreen*)*(u8**)(p4 + 8))->draw(ax, ay, *(J2DGrafContext**)(self + 0x4c));
                        *(s16*)(p2 + 0x234) = 0;
                    } else if (!HudHideTimer8041()) {
                        if (((s32 (*)(s32))fn_802366CC)(fn_8022EA0C(i)) > 0) {
                            if (((s32 (*)(s32))fn_802366CC)(fn_8022EA0C(i)) < 0x12c) {
                                fn_8030C5F0(*(void**)(lbl_8053AB10 + 0x24), ((void* (*)(s32))fn_8023E724)(fn_8022EA0C(i)), 0, 0, buf);
                                JUTVideo* vp = JUTVideo::getManager();
                                s32 fa = vp->getFbWidth();
                                s32 fb = vp->getEfbHeight();
                                                                f32 zero = lbl_80543A00;
                        J2DOrthoGraph* graph = (J2DOrthoGraph*)*(u8**)(self + 0x4c);
                        f32 c = (f32)(s32)*(s16*)(lbl_8050DB0C + 0x4e);
                                f32 xx = sx * (buf[0] / (f32)fa);
                                bx = xx - (f32)fa * lbl_80543A34;
                                f32 yy = sy * (buf[1] / (f32)fb);
                                by = c + (yy - (f32)fb * lbl_80543A34);
                                JGeometry::TBox2f box(zero, zero, ex, ey);
                                graph->setOrtho(box, lbl_80543A38, lbl_80543A3C);
                                ((J2DOrthoGraph*)*(u8**)(self + 0x4c))->setPort();
                                ((J2DScreen*)*(u8**)(p4 + 0x2c))->draw(bx, by, *(J2DGrafContext**)(self + 0x4c));
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
#pragma opt_common_subs reset
extern "C" void fn_8041A868(u8* self, s32 x);
extern "C" void fn_8041C67C(u8* self);
extern "C" void fn_80418D08(u8* self, s32 i, s32 j);
extern "C" void fn_8043A608(u8* x);
extern "C" void fn_8044172C(u8* x);
extern const u64 lbl_8048D6B8[];
#pragma auto_inline off
extern "C" void fn_8041FC2C(u8* self_) {
    s32 k;
    u8* tbl;
    u8* self = self_;
    u32* lbl;
    u8* p;
    u8* q;
    u64* n0;
    u64* n1;
    u64* n2;
    u64* n3;
    u64* n4;
    u64* n5;
    u64* n6;
    s32 j;
    u64* n7;
    s32 i;
    f32 f;

    tbl = (u8*)lbl_8048D320;
    f = lbl_80543A00;
    p = self;
    q = self;

    for (i = 0; i < 4; i++, p += 4, q += 2) {
    lbl = (u32*)lbl_80529DEC + i;
    fn_8041E3B4(self, i);
    lbl[0x36] = fn_80237774(i);
    lbl[0x3a] = fn_80236100(i);
    lbl[0x42] = fn_802375B0(i);

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
    }
    *(s16*)(self + 0x222) = -1;

    if (lbl_8053AAF8[0x7e] == 0) {
        (*(J2DPane**)(self + 4))->search(0x004E646174613133ULL)->show();
        (*(J2DPane**)(self + 4))->search(0x506870316E693032ULL)->hide();
        (*(J2DPane**)(self + 4))->search(0x5068317069696233ULL)->show();
        (*(J2DPane**)(self + 4))->search(*(u64*)(tbl + 0x398))->hide();
        (*(J2DPane**)(self + 4))->search(lbl_8048D6B8[1])->hide();
        (*(J2DPane**)(self + 4))->search(lbl_8048D6B8[2])->hide();
        (*(J2DPane**)(self + 4))->search(lbl_8048D6B8[3])->hide();
        if ((lbl_8053AAF8[0x83] & 3U) == 2) {
            (*(J2DPane**)(self + 4))->search(0x004E646174613136ULL)->show();
        } else {
            (*(J2DPane**)(self + 4))->search(0x004E646174613136ULL)->hide();
        }

        n0 = (u64*)(tbl + 0xae0);
        n1 = (u64*)(tbl + 0xb20);
        n2 = (u64*)(tbl + 0xb40);
        n3 = (u64*)(tbl + 0xb60);
        n4 = (u64*)(tbl + 0xb80);
        n5 = (u64*)(tbl + 0xbc0);
        n6 = (u64*)(tbl + 0xbe0);
        n7 = (u64*)(tbl + 0xc00);
        for (j = 0; j < 4; j++, n0++, n1++, n2++, n3++, n4++, n5++, n6++, n7++) {
            (*(J2DPane**)(self + 0x18))->search(*n0)->hide();
            (*(J2DPane**)(self + 0x18))->search(*n1)->hide();
            (*(J2DPane**)(self + 4))->search(*n2)->hide();
            (*(J2DPane**)(self + 4))->search(*n3)->hide();
            (*(J2DPane**)(self + 4))->search(*n4)->hide();
            (*(J2DPane**)(self + 4))->search(*n5)->hide();
            (*(J2DPane**)(self + 4))->search(*n6)->hide();
            (*(J2DPane**)(self + 4))->search(*n7)->hide();
        }
        fn_8041A868(self, 1);
    } else {
        fn_8041C67C(self);
    }

    if (self[0x291] != 0) {
        for (k = 0; k < 4; k++) {
            if (lbl_8053AAF8[0x82] & (u8)(1 << k)) {
                fn_80418D08(self, k, 1);
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
        s32 a = *(s32*)((u8*)lbl_80529DEC + 0x118);
        if (a < 8) {
            s32 b = *(s32*)((u8*)lbl_80529DEC + 0x11c);
            if (b >= 4) goto done;
            if (a == 0 && b == 0) {
                u8* e = (u8*)lbl_8050EC80 + 0xc8 * *(s32*)((u8*)lbl_8050EC80 + 0x10);
                if (!(*(s32*)(e + 0x28) & 1)) goto done;
            }
            if (a == 0 && b == 1) goto done;
            if (a == 1 && b == 3) goto done;
            if (a == 2 && b == 3) goto done;
            if (a == 4 && b == 3) goto done;
            if (a == 5 && b == 1) goto done;
            if (a == 5 && b == 3) goto done;
            if (a == 6 && b == 1) goto done;
            if (a == 6 && b == 3) goto done;
            if (a == 7 && b == 3) goto done;
            fn_8043A608(lbl_8053AED0);
        }
    }
done:
    if (*(u8**)(self + 0x50) != 0) {
        fn_8044172C(*(u8**)(self + 0x50));
    }
}
#pragma auto_inline reset
extern "C" void* fn_804201E0(void* this_, s16 how) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B13D4;
        if (*(void**)((u8*)this_+0x50)) {
            ReleaseSlot((void**)((u8*)this_+0x50));
        }
        ReleaseSlot((void**)((u8*)this_+0x4c));
        ReleaseSlot((void**)((u8*)this_+0x4));
        void** slot=(void**)this_;
        for(s32 i=0;i<4;i++) {
            ReleaseSlot(slot+2);
            ReleaseSlot(slot+11);
            slot++;
        }
        ReleaseSlot((void**)((u8*)this_+0x18));
        ReleaseSlot((void**)((u8*)this_+0x54));
        ReleaseSlot((void**)((u8*)this_+0x58));
        ReleaseSlot((void**)((u8*)this_+0x5c));
        ReleaseSlot((void**)((u8*)this_+0x6c));
        ReleaseSlot((void**)((u8*)this_+0x70));
        void** base=(void**)this_;
        for(s32 i=0;i<4;i++) {
            ReleaseSlot(base+29);
            ReleaseSlot(base+33);
            ReleaseSlot(base+37);
            ReleaseSlot(base+41);
            ReleaseSlot(base+45);
            ReleaseSlot(base+49);
            ReleaseSlot(base+53);
            ReleaseSlot(base+57);
            base++;
        }
        if(how>0) __dl__FPv(this_);
    }
    return this_;
}

extern "C" void* __nw__FUl(u32);
extern "C" void fn_80441778(void*);
extern "C" void fn_80402F04(void*, J2DPane*);
extern u8 lbl_804AF86C[];
static inline u8* HudNewPaneState8041() {
    u8* p = (u8*)__nw__FUl(0x2c);
    if (p) *(u8**)p = lbl_804AF86C;
    return p;
}

extern u8 lbl_804B1390[];
#pragma opt_loop_invariants off
extern "C" u8* fn_80420574(u8* self) {
    const u8* base = (const u8*)lbl_8048D320;
    const u8* ids = lbl_804B1390;
    const HudPaneNames8041* names = HudNames8041();
    *(const u8**)self = ids + 0x44;
    *(s32*)(self+0x244) = -1;
    *(s32*)(self+0x248) = -1;
    if (*(s32*)(lbl_80529DEC+0x118) != 0 || *(s32*)(lbl_80529DEC+0x11c) != 0)
        lbl_8053AED0[0x10e] |= 1;
    if (*(s32*)(lbl_80529DEC+0x118) == 6 && *(s32*)(lbl_80529DEC+0x11c) == 2)
        self[0x291] = 1;
    else self[0x291] = 1;
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
    if (fn_80138A30(lbl_8053AAF8) >= 2) {
        void* p = __nw__FUl(0x10);
        if (p) fn_80441778(p);
        *(void**)(self+0x50) = p;
    } else *(void**)(self+0x50) = 0;
    *(J2DOrthoGraph**)(self+0x4c) = new J2DOrthoGraph(lbl_80543A00, lbl_80543A00,
        (f32)(s32)JUTVideo::getManager()->getFbWidth(),
        (f32)(s32)JUTVideo::getManager()->getEfbHeight(), lbl_80543A38, lbl_80543A3C);
    *(J2DScreen**)(self+4) = new J2DScreen;
    (*(J2DScreen**)(self+4))->setPriority((const char*)base+0xe4c, 0x1100000, *(JKRArchive**)(lbl_80529DEC+0x4c));
    for (s32 i=0; i<4; i++) {
        *(J2DScreen**)(self+8+i*4) = new J2DScreen;
        (*(J2DScreen**)(self+8+i*4))->setPriority((const char*)base+0xe5c, 0x1100000, *(JKRArchive**)(lbl_80529DEC+0x4c));
        *(J2DScreen**)(self+0x2c+i*4) = new J2DScreen;
        (*(J2DScreen**)(self+0x2c+i*4))->setPriority((const char*)base+0xe6c, 0x1100000, *(JKRArchive**)(lbl_80529DEC+0x20));
    }
    *(J2DScreen**)(self+0x18) = new J2DScreen;
    (*(J2DScreen**)(self+0x18))->setPriority((const char*)base+0xe7c, 0x1100000, *(JKRArchive**)(lbl_80529DEC+0x4c));
    HudHidePane8041(self, 0x005070316c693031ULL);
    HudHidePane8041(self, 0x005070326c693031ULL);
    HudHidePane8041(self, 0x005070336c693031ULL);
    HudHidePane8041(self, 0x005070346c693031ULL);
    self[0x24c] = (*(J2DScreen**)(self+0x4))->search(HudPaneName8041(names->a388, 0))->getAlpha();
    self[0x24d] = (*(J2DScreen**)(self+0x4))->search(HudPaneName8041(names->a388, 1))->getAlpha();
    self[0x24e] = (*(J2DScreen**)(self+0x4))->search(names->a338[0])->getAlpha();
    self[0x24f] = (*(J2DScreen**)(self+0x4))->search(names->a360[0])->getAlpha();
    self[0x25e] = (*(J2DScreen**)(self+0x4))->search(names->a248[0])->getAlpha();
    self[0x25f] = (*(J2DScreen**)(self+0x4))->search(names->a2a8[0])->getAlpha();
    const u64* a = names->a308;
    const u64* b = names->a320;
    for (s32 i=0;i<3;i++,a++,b++) {
        self[0x258+i] = (*(J2DScreen**)(self+4))->search(a[0])->getAlpha();
        self[0x25b+i] = (*(J2DScreen**)(self+4))->search(b[0])->getAlpha();
    }
    self[0x260] = (*(J2DScreen**)(self+0x4))->search(HudPaneName8041(names->a8f8[0], 0))->getAlpha();
    self[0x261] = (*(J2DScreen**)(self+0x4))->search(HudPaneName8041(names->a8f8[0], 1))->getAlpha();
    self[0x262] = (*(J2DScreen**)(self+0x4))->search(HudPaneName8041(names->a8f8[0], 2))->getAlpha();
    self[0x263] = (*(J2DScreen**)(self+0x4))->search(HudPaneName8041(names->a8f8[0], 3))->getAlpha();
    self[0x264] = (*(J2DScreen**)(self+0x4))->search(HudPaneName8041(names->a8f8[0], 4))->getAlpha();
    self[0x265] = (*(J2DScreen**)(self+0x4))->search(HudPaneName8041(names->a8f8[0], 5))->getAlpha();
    self[0x266] = (*(J2DScreen**)(self+0x4))->search(names->b40[0])->getAlpha();
    self[0x267] = (*(J2DScreen**)(self+0x18))->search(names->b20[0])->getAlpha();
    self[0x250] = (*(J2DScreen**)(self+0x4))->search(names->a148[0])->getAlpha();
    self[0x251] = (*(J2DScreen**)(self+0x4))->search(names->a188[0])->getAlpha();
    self[0x252] = (*(J2DScreen**)(self+0x4))->search(names->a1c8[0])->getAlpha();
    self[0x253] = (*(J2DScreen**)(self+0x4))->search(names->a208[0])->getAlpha();
    self[0x26a] = (*(J2DScreen**)(self+4))->search(0x506870316e693032ULL)->getAlpha();
    self[0x26b] = (*(J2DScreen**)(self+4))->search(0x506870316e693031ULL)->getAlpha();
    self[0x26c] = (*(J2DScreen**)(self+0x4))->search(HudPaneName8041(names->a398, 0))->getAlpha();
    self[0x26d] = (*(J2DScreen**)(self+0x4))->search(HudPaneName8041(names->a398, 1))->getAlpha();
    self[0x26e] = (*(J2DScreen**)(self+0x4))->search(HudPaneName8041(names->a398, 2))->getAlpha();
    self[0x26f] = (*(J2DScreen**)(self+0x4))->search(HudPaneName8041(names->a398, 3))->getAlpha();
    self[0x268] = (*(J2DScreen**)(self+0x18))->search(names->ae0[0])->getAlpha();
    self[0x269] = (*(J2DScreen**)(self+0x18))->search(names->b00[0])->getAlpha();
    a=names->ab0;
    for (s32 i=0;i<6;i++,a++)
        self[0x27b+i] = (*(J2DScreen**)(self+0x2c))->search(a[0])->getAlpha();
    ((JUtility::TColor*)(self+0x248))->setRGBA(((J2DPicture*)(*(J2DScreen**)(self+4))->search(names->a338[0]))->getBlack());
    ((JUtility::TColor*)(self+0x244))->setRGBA(((J2DPicture*)(*(J2DScreen**)(self+4))->search(names->a338[0]))->getWhite());
    *(u8**)(self+0x54) = HudNewPaneState8041();
    fn_80402F04(*(u8**)(self+0x54), (*(J2DScreen**)(self+4))->search(0x004e646174613133ULL));
    *(u8**)(self+0x58) = HudNewPaneState8041();
    fn_80402F04(*(u8**)(self+0x58), (*(J2DScreen**)(self+4))->search(0x506870316e693032ULL));
    *(u8**)(self+0x5c) = HudNewPaneState8041();
    fn_80402F04(*(u8**)(self+0x5c), (*(J2DScreen**)(self+4))->search(0x5068317069696233ULL));
    *(u8**)(self+0x6c) = HudNewPaneState8041();
    fn_80402F04(*(u8**)(self+0x6c), (*(J2DScreen**)(self+4))->search(0x004e646174613136ULL));
    *(u8**)(self+0x70) = HudNewPaneState8041();
    fn_80402F04(*(u8**)(self+0x70), (*(J2DScreen**)(self+4))->search(0x004e646174613032ULL));
    const u64* playerNames=names->ae0;
    const u64* q0=playerNames;
    const u64* q1=names->b20;
    const u64* q2=names->b40;
    const u64* q3=names->padb60;
    const u64* q4=names->b80;
    const u64* q5=names->bc0;
    const u64* q6=names->be0;
    const u64* q7=names->c00;
    for (s32 i=0;i<4;i++,q0++,q1++,q2++,q3++,q4++,q5++,q6++,q7++) {
        *(u8**)(self+0x74+i*4) = HudNewPaneState8041();
        fn_80402F04(*(u8**)(self+0x74+i*4), (*(J2DScreen**)(self+0x18))->search(q0[0]));
        *(u8**)(self+0x84+i*4) = HudNewPaneState8041();
        fn_80402F04(*(u8**)(self+0x84+i*4), (*(J2DScreen**)(self+0x18))->search(q1[0]));
        *(u8**)(self+0x94+i*4) = HudNewPaneState8041();
        fn_80402F04(*(u8**)(self+0x94+i*4), (*(J2DScreen**)(self+0x4))->search(q2[0]));
        *(u8**)(self+0xa4+i*4) = HudNewPaneState8041();
        fn_80402F04(*(u8**)(self+0xa4+i*4), (*(J2DScreen**)(self+0x4))->search(q3[0]));
        *(u8**)(self+0xb4+i*4) = HudNewPaneState8041();
        fn_80402F04(*(u8**)(self+0xb4+i*4), (*(J2DScreen**)(self+0x4))->search(q4[0]));
        *(u8**)(self+0xc4+i*4) = HudNewPaneState8041();
        fn_80402F04(*(u8**)(self+0xc4+i*4), (*(J2DScreen**)(self+0x4))->search(q5[0]));
        *(u8**)(self+0xd4+i*4) = HudNewPaneState8041();
        fn_80402F04(*(u8**)(self+0xd4+i*4), (*(J2DScreen**)(self+0x4))->search(q6[0]));
        *(u8**)(self+0xe4+i*4) = HudNewPaneState8041();
        fn_80402F04(*(u8**)(self+0xe4+i*4), (*(J2DScreen**)(self+0x4))->search(q7[0]));
    }
    if (!lbl_8053AAF8[0x7e]) {
        a=names->a148; b=names->a188;
        for(s32 i=0;i<8;i++,a++,b++) {
          const u32* resource=(const u32*)ids;
          for(s32 j=0;j<3;j++,resource++) {
            const ResTIMG* img=(const ResTIMG*)fn_804030C4(0x54494d47, *resource);
            ((J2DPicture*)(*(J2DScreen**)(self+4))->search(a[0]))->append(img,lbl_80543A0C);
            ((J2DPicture*)(*(J2DScreen**)(self+4))->search(b[0]))->append(img,lbl_80543A0C);
        }
        }
    } else {
        a=playerNames; b=names->b00;
        for(s32 i=0;i<4;i++,a++,b++) {
          const u32* resource=(const u32*)(ids+0x34);
          resource++;
          for(s32 j=1;j<4;j++,resource++) {
            const ResTIMG* img=(const ResTIMG*)fn_804030C4(0x54494d47, *resource);
            ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(a[0]))->append(img,lbl_80543A0C);
            ((J2DPicture*)(*(J2DScreen**)(self+0x18))->search(b[0]))->append(img,lbl_80543A0C);
        }
    }
        }
    if(self[0x291]) {
        for(s32 i=0;i<4;i++) {
          a=names->c20; b=names->ca0;
          for(s32 j=0;j<8;j++,a++,b++) {
            const u32* resource=(const u32*)ids;
            for(s32 k=0;k<3;k++,resource++) {
            const ResTIMG* img=(const ResTIMG*)fn_804030C4(0x54494d47, *resource);
            ((J2DPicture*)(*(J2DScreen**)(self+8+i*4))->search(a[0]))->append(img,lbl_80543A0C);
            ((J2DPicture*)(*(J2DScreen**)(self+8+i*4))->search(b[0]))->append(img,lbl_80543A0C);
        }
    }
        }
      }
    return self;
}
#pragma opt_loop_invariants reset
void __sinit_tu_80418B64_cpp() {}

