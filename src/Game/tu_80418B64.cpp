#include "types.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/JUtility/JUTVideo.h"


extern u8* lbl_8053AAF8;
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
extern "C" void fn_8022EA0C(s32);
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

extern u64 lbl_8048D320[];
extern u32 lbl_804B13C4;
extern u8 lbl_8050EC80[];
extern "C" void fn_80419C38(u8* self, s32 i, s32 v);
extern "C" void fn_8041C67C(u8* this_) {
	s32 i;
	u64* p20 = &lbl_8048D320[0x15c];
	u64* p29 = p20;
	u64* p28 = &lbl_8048D320[0x164];
	u64* p27 = &lbl_8048D320[0x168];
	u64* p26 = &lbl_8048D320[0x16c];
	u64* p25 = &lbl_8048D320[0x170];
	u64* p24 = &lbl_8048D320[0x178];
	u64* p23 = &lbl_8048D320[0x17c];
	u64* p22 = &lbl_8048D320[0x180];
	u64* p21 = &lbl_8048D320[0x13b];

	for (i = 0; i < 4; i++) {
		if (lbl_8053AAF8[0x82] & (1 << i)) {
			((u8*)((SubObj*)*(u8**)(this_ + 0x18))->w13(*p29))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 0x18))->w13(*p28))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(*p27))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(*p26))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(*p25))[0xb0] = 1;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(*p24))[0xb0] = 1;
			if (lbl_8050EC80[*(u32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x88]) {
				((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(*p23))[0xb0] = 1;
			} else {
				((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(*p23))[0xb0] = 0;
			}
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(*p22))[0xb0] = 1;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(p21[0]))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(p21[1]))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(p21[2]))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(p21[3]))[0xb0] = 0;
		} else {
			((u8*)((SubObj*)*(u8**)(this_ + 0x18))->w13(*p29))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 0x18))->w13(*p28))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(*p27))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(*p26))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(*p25))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(*p24))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(*p23))[0xb0] = 0;
			((u8*)((SubObj*)*(u8**)(this_ + 4))->w13(*p22))[0xb0] = 0;
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

	u64* q22 = &lbl_8048D320[0x160];
	u32 s = fn_804030C4(0x54494d47, lbl_804B13C4);
	for (i = 0; i < 4; i++) {
		((void (*)(u8*, u32, u32))(*(u32**)((SubObj*)*(u8**)(this_ + 0x18))->w13(*p20))[68])((u8*)((SubObj*)*(u8**)(this_ + 0x18))->w13(*p20), s, 0);
		p20++;
		q22++;
	}

	for (i = 0; i < 4; i++) {
		if (lbl_8053AAF8[0x82] & (1 << i)) {
			fn_80419C38(this_, i, 1);
		}
	}
}

extern "C" void fn_8041DD24(u8* this_) {
    u64* p31;
    u64* p30;
    u64* p29;
    u64* p28;
    s32 n;
    u8* base;
    u8* self;
    s32 cnt;
    s32 i;

    self = this_;
    base = (u8*)lbl_8048D320;
    if (self[0x28a] & 1) {
        n = fn_80237810(0);
        cnt = *(s32*)(lbl_80529DEC + 0xd8);
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
    u32* table;
    s32 j;
    s32 bit;
    s32 flag;
    s32 i;

    table = (u32*)lbl_80529DEC;
    for (i = 0; i < 4; i++) {
        bit = 1 << i;
        flag = (lbl_8053AAF8[0x82] & (u8)bit) != 0;
        if (flag != 0) {
            table[0x36 + i] = fn_80237774(i);
            for (j = 0; j < 4; j++) {
                if (j != i && fn_8022F514(j) && fn_8022F3DC(j) == i) {
                    table[0x36 + j] = table[0x36 + i];
                }
            }
            this_[0x28a] |= (u8)bit;
            *(u32*)(this_ + 0x198 + i * 4) = 0;
            table[0x3a + i] = fn_80236100(i);
            this_[0x28b] |= (u8)bit;
            *(u32*)(this_ + 0x1a8 + i * 4) = 0;
            table[0x42 + i] = fn_802375B0(i);
            for (j = 0; j < 4; j++) {
                if (j != i && fn_8022F514(j) && fn_8022F3DC(j) == i) {
                    table[0x42 + j] = table[0x42 + i];
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
    u8 mask;
    u32 bit;
    s32 i;
    s32 cnt;
    BOOL flag;

    bit = 1 << idx;
    mask = bit;

    flag = (lbl_80529DEC[0x239] & mask) != 0;
    if (flag) {
        *(s32*)(lbl_80529DEC + idx * 4 + 0xd8) = fn_80237774(idx);
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
    f32 f;

    tbl = (u8*)lbl_8048D320;
    lbl = (u8*)lbl_80529DEC;
    f = lbl_80543A00;

    i = 0;
    fn_8041E3B4(self, i);
    *(u32*)(lbl + 0xd8) = fn_80237774(i);
    *(u32*)(lbl + 0xe8) = fn_80236100(i);
    *(u32*)(lbl + 0x108) = fn_802375B0(i);

    p = self;
    q = self;
    for (; i < 4; i++, p += 4, q += 2) {
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
        SetPaneVisible(*(u8**)(self + 4), 0x004E646174613133ULL, 1);
        SetPaneVisible(*(u8**)(self + 4), 0x506870316E693032ULL, 0);
        SetPaneVisible(*(u8**)(self + 4), 0x5068317069696233ULL, 1);
        SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0x398), 0);
        SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0x3a0), 0);
        SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0x3a8), 0);
        SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0x3b0), 0);
        SetPaneVisible(*(u8**)(self + 4), 0x004E646174613136ULL, (lbl_8053AAF8[0x83] & 3) == 2);

        for (i = 0; i < 4; i++) {
            SetPaneVisible(*(u8**)(self + 0x18), *(u64*)(tbl + 0xae0 + 8 * i), 0);
            SetPaneVisible(*(u8**)(self + 0x18), *(u64*)(tbl + 0xb20 + 8 * i), 0);
            SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0xb40 + 8 * i), 0);
            SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0xb60 + 8 * i), 0);
            SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0xb80 + 8 * i), 0);
            SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0xbc0 + 8 * i), 0);
            SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0xbe0 + 8 * i), 0);
            SetPaneVisible(*(u8**)(self + 4), *(u64*)(tbl + 0xc00 + 8 * i), 0);
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
    if (*(s32*)(lbl + 0x118) < 8 && *(s32*)(lbl + 0x11c) < 4) {
        fn_8043A608(lbl_8053AED0);
    }
    if (*(u8**)(self + 0x50) != 0) {
        fn_8044172C(*(u8**)(self + 0x50));
    }
}

