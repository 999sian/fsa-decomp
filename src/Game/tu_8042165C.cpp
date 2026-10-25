#include "types.h"

class J2DGrafContext;
class J2DScreen {
public:
    void draw(f32, f32, const J2DGrafContext*);
};

extern "C" void fn_8013B490(void*);
extern u8* lbl_8053AB10;
extern const f32 lbl_80543A40;
extern const f32 lbl_80543A44;
extern const f32 lbl_80543A48;
extern const f32 lbl_80543A4C;

extern u8* lbl_8053AAF8;
extern u8 lbl_80529DEC[];
extern "C" u32 fn_80237774(s32 i);
extern "C" u8 fn_8022F514(s32 i);
extern "C" s32 fn_8022F3DC(s32 i);
extern "C" u32 fn_80236100(s32 i);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B146C[];

// Sub-object whose virtual slots 9 and 15 are called by fn_80421A34.
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
extern u8 lbl_8048E1B8[];
extern u8 lbl_8050EC80[];
extern u32 lbl_804B145C[];
extern "C" u32 fn_802375B0(s32 i);
extern "C" void fn_80421A34(u8* this_, s32 i, u8 flag);
extern "C" void fn_80424148(u8* this_, s32 i, u8 flag);
extern "C" void fn_8044172C(void* p);
extern u8* lbl_8053AED0;
extern u8* lbl_8053AD30;
extern "C" u8 fn_80230188(s32 i);
extern "C" s32 fn_80237810(s32 i);

typedef u8* (*SubGetFn)(u8*, u64);
typedef void (*SubSetFn)(u8*, f32, f32, f32, f32, f32, f32, f32, f32);

// Virtual slot 15 of this_->sub: returns the object for a 64-bit key.
static inline u8* GetSub(u8* this_, u64 key) {
    u8* sub = *(u8**)(this_ + 4);
    return ((SubGetFn)(*(void***)sub)[15])(sub, key);
}

// Virtual slot 65 of an object: eight float arguments.
static inline void SetSub(u8* sub, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h) {
    ((SubSetFn)(*(void***)sub)[65])(sub, a, b, c, d, e, f, g, h);
}
extern "C" s32 fn_8022EA0C(s32 i);
extern "C" u8 fn_8023BE0C(void);
extern "C" u32 fn_8030AAF4(s32 i);
extern "C" s32 fn_80309D24(u8* a, u32 b, s32 c);
extern "C" u32 fn_802373EC(s32 i);
extern "C" s32 fn_8023725C(s32 i);
extern "C" u8 fn_8022C8EC(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" void* fn_8023E724(s32 i);
extern "C" u8 fn_8043DF24(u8* obj, f32 x, f32 y, f32 px, f32 py, f32 r);
extern "C" void fn_8030C5F0(void* a, void* b, s32 c, s32 d, f32* out);

typedef u8* (*PairCallFn)(u8* self, u32 a, u32 b);

// Virtual slot 15 of the sub-object at this+4: takes a (u32, u32) pair and returns the object whose 0xb0 byte is set.
static inline u8* CallPair(u8* this_, u32 a, u32 b) {
    u8* sub = *(u8**)(this_ + 4);
    return ((PairCallFn)(*(void***)sub)[15])(sub, a, b);
}

extern u64 lbl_8048F158[];
extern u32 lbl_804B1434[];
extern "C" s32 fn_802366CC(void);
extern "C" u32 fn_804030C4(u32 tag, u32 id);

typedef void (*Slot68Fn)(u8* self, u32 a, u32 b);

// Virtual slot 68 of an object returned by SubObj::w13: calls (u32, 0).
static inline void CallSlot68(u8* obj, u32 s) {
    ((Slot68Fn)(*(void***)obj)[68])(obj, s, 0);
}

// Virtual slot 15 of obj keyed by a 64-bit value.
static inline u8* GetKeyed(u8* obj, u64 key) {
    return ((SubGetFn)(*(void***)obj)[15])(obj, key);
}

// Virtual slot 15 of obj keyed by a 64-bit value: sets the 0xb0 byte of the returned object.
static inline void SetKeyFlag(u8* obj, u64 key, u8 v) {
    u8* ret = GetKeyed(obj, key);
    ret[0xb0] = v;
}

// Virtual slot 2 of an owned sub-object: destroy(freeFlag).
struct DtorSlot2 {
    virtual void destroy(s32 freeFlag);
};

// Releases the owned object in a member slot, then clears the slot.
static inline void ReleaseSlot(void** slot) {
    DtorSlot2* obj = (DtorSlot2*)*slot;
    if (obj != 0) {
        obj->destroy(1);
    }
    *slot = 0;
}
extern "C" void fn_8042165C(u8* this_) {
    u8* base = lbl_8048E1B8;
    s32 j;
    s32 i;
    s32 k;
    f32 pos[2];

    *(u16*)(this_ + 0x1f0) = 0;
    *(u16*)(this_ + 0x1f2) = 0;
    *(u16*)(this_ + 0x1f4) = 0;
    *(u16*)(this_ + 0x1f6) = 0;
    for (i = 0; i < 4; i++) {
        s32 mask = 1 << i;
        bool on = (lbl_8053AAF8[0x82] & (u8)mask) != 0;
        if (on && !fn_8022C8EC(i)) {
            for (k = 0; k < 4; k++) {
                if (k != i) ((u16*)(this_ + 0x1f0))[k] |= (u16)mask;
            }
            if (fn_8023DE58(i) < 8) {
                f32* xs;
                f32* ys;
                fn_8030C5F0(*(void**)(lbl_8053AB10 + 0x24), fn_8023E724(i), 0, 0, pos);
                xs = (f32*)(base + 0xfd0);
                ys = (f32*)(base + 0xff8);
                for (j = 0; j < 10; j++) {
                    if (!fn_8043DF24(lbl_8053AED0, *xs, *ys, pos[0], pos[1], lbl_80543A40)) {
                        for (k = 0; k < 4; k++) {
                            ((u16*)(this_ + 0x1f0))[k] |= (u16)(1 << j);
                        }
                    }
                    xs++;
                    ys++;
                }
            }
        }
        if (this_[0x24d + i] != 0xff) {
            for (k = 0; k < 4; k++) {
                if (k != i) ((u16*)(this_ + 0x1f0))[k] |= (u16)(1 << this_[0x24d + i]);
            }
        }
    }

    {
        u8* flags = this_;
        u8* timers = this_;
        u8* row = base + 0x1020;
        for (i = 0; i < 4; i++) {
            if ((lbl_8053AAF8[0x82] & (u8)(1 << i)) != 0 && !fn_8022C8EC(i) && fn_8023DE58(i) < 8) {
                u8* p = row;
                for (j = 0; j < 10; j++) {
                    if (((u16)(1 << *p) & *(u16*)(flags + 0x1f0)) == 0) {
                        if (this_[i + 0x251] != row[j] && this_[i + 0x24d] == 0xff) {
                            this_[i + 0x24d] = row[j];
                            *(s32*)(timers + 0x198) = 0;
                            for (k = 0; k < 4; k++) {
                                ((u16*)(this_ + 0x1f0))[k] |= (u16)(1 << this_[i + 0x24d]);
                            }
                        }
                        break;
                    }
                    p++;
                }
                if (this_[i + 0x24d] != 0xff) {
                    *(s32*)(timers + 0x198) = *(s32*)(timers + 0x198) + 1;
                    if (*(s32*)(timers + 0x198) >= 60) {
                        this_[i + 0x251] = this_[i + 0x24d];
                        this_[i + 0x24d] = 0xff;
                    }
                } else if (*(s32*)(timers + 0x198) != 0) {
                    *(s32*)(timers + 0x198) = *(s32*)(timers + 0x198) + 1;
                    if (*(s32*)(timers + 0x198) >= 120) {
                        *(s32*)(timers + 0x198) = 0;
                    }
                }
            }
            flags += 2;
            timers += 4;
            row += 10;
        }
    }
}

extern "C" void fn_80421A34(u8* this_, s32 i, u8 flag) {
    u8* base = lbl_8048E1B8;
    s32 j;
    u8 bit = 1 << i;
    s32 off = i * 4;
    f32 old = *(f32*)(this_ + off + 0x118);

    if (!(this_[0x25d] & bit)) {
        if (old > lbl_80543A40) {
            *(f32*)(this_ + off + 0x118) = old - lbl_80543A44;
        } else {
            *(f32*)(this_ + off + 0x118) = lbl_80543A40;
        }
        (*(u8**)(lbl_8053AB10 + 0x20))[0x217 + i] = 1;
    } else {
        s32* table = (s32*)lbl_80529DEC;
        if (table[0x36 + i] == 0) {
            if (old > lbl_80543A48) {
                *(f32*)(this_ + off + 0x118) = old - lbl_80543A44;
                if (*(f32*)(this_ + off + 0x118) <= lbl_80543A48) {
                    *(f32*)(this_ + off + 0x118) = lbl_80543A48;
                }
            } else if (old < lbl_80543A48) {
                *(f32*)(this_ + off + 0x118) = old + lbl_80543A44;
                if (*(f32*)(this_ + off + 0x118) >= lbl_80543A48) {
                    *(f32*)(this_ + off + 0x118) = lbl_80543A48;
                }
            }
        } else {
            if (old < lbl_80543A4C) {
                *(f32*)(this_ + off + 0x118) = old + lbl_80543A44;
            } else {
                *(f32*)(this_ + off + 0x118) = lbl_80543A4C;
            }
        }
    }

    if (*(f32*)(this_ + off + 0x118) != old || flag) {
        u8* p = this_ + off;
        u64* a = (u64*)(base + 0xc68);
        u64* b = (u64*)(base + 0xce8);
        u64* c = (u64*)(base + 0xca8);
        u64* d = (u64*)(base + 0xd28);
        for (j = 0; j < 8; j++) {
            (*(SubObj**)(p + 0x8))->w13(*a)->w07((s32)((f32)this_[0x21c] * *(f32*)(p + 0x118)));
            (*(SubObj**)(p + 0x8))->w13(*b)->w07((s32)((f32)this_[0x21d] * *(f32*)(p + 0x118)));
            (*(SubObj**)(p + 0x8))->w13(*c)->w07((s32)((f32)this_[0x21e] * *(f32*)(p + 0x118)));
            (*(SubObj**)(p + 0x8))->w13(*d)->w07((s32)((f32)this_[0x21f] * *(f32*)(p + 0x118)));
            a++;
            b++;
            c++;
            d++;
        }
        u64* e = (u64*)(base + 0xfa0);
        for (j = 0; j < 6; j++) {
            (*(SubObj**)(p + 0x2c))->w13(*e)->w07((s32)((f32)this_[0x247 + j] * *(f32*)(p + 0x118)));
            e++;
        }
    }
}

extern "C" void fn_80421D78(u8* this_, s32 idx) {
    s32 n;
    u8* p;
    u8* q;
    u32 s;

    fn_8022EA0C(idx);
    if (fn_802366CC() > 0) {
        fn_8022EA0C(idx);
        if (fn_802366CC() < 300) {
            fn_8022EA0C(idx);
            n = fn_802366CC() / 60 + 1;
            q = this_ + idx;
            if (n != q[0x25e]) {
                if (n > 99) {
                    n = 99;
                }
                if (n < 0) {
                    n = 0;
                }
                if (n < 10) {
                    s = fn_804030C4(0x54494d47, lbl_804B1434[n]);
                    p = this_ + idx * 4;
                    CallSlot68((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048F158[0]), s);
                    CallSlot68((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048F158[1]), s);
                    if (((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048F158[2]))[0xb0] == 1) {
                        ((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048F158[2]))[0xb0] = 0;
                        ((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048F158[3]))[0xb0] = 0;
                    }
                } else {
                    s = fn_804030C4(0x54494d47, lbl_804B1434[n / 10]);
                    p = this_ + idx * 4;
                    CallSlot68((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048F158[0]), s);
                    CallSlot68((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048F158[1]), s);
                    s = fn_804030C4(0x54494d47, lbl_804B1434[n % 10]);
                    CallSlot68((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048F158[2]), s);
                    CallSlot68((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048F158[3]), s);
                    if (((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048F158[2]))[0xb0] == 0) {
                        ((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048F158[2]))[0xb0] = 1;
                        ((u8*)((SubObj*)*(u8**)(p + 0x2c))->w13(lbl_8048F158[3]))[0xb0] = 1;
                    }
                }
                q[0x25e] = n;
            }
        } else {
            this_[idx + 0x25e] = 0;
        }
    } else {
        this_[idx + 0x25e] = 0;
    }
    if (*(s16*)(this_ + idx * 2 + 0x208) > 0) {
        *(s16*)(this_ + idx * 2 + 0x208) = *(s16*)(this_ + idx * 2 + 0x208) - 1;
    }
}

extern "C" void fn_80423804(u8* this_, u32 idx) {
    u8* base = lbl_8048E1B8;
    if (this_[0x256] & (u8)(1 << idx)) {
        s32 n = fn_80237810(idx);
        s32 cnt = *(s32*)(lbl_80529DEC + idx * 4 + 0xd8);
        s32 k = cnt;
        if (n > 0x20) {
            n = 0x20;
        }
        if (n < 0) {
            n = 0;
        }
        if (n < cnt) {
            k = n;
        }
        if (k < 0) {
            k = 0;
        }

        u32 off = idx * 0x40;
        u64* a = (u64*)(base + 0x228 + off);
        u64* b = (u64*)(base + 0x328 + off);
        u64* c = (u64*)(base + 0x428 + off);
        u64* d = (u64*)(base + 0x528 + off);
        for (s32 j = 0; j < 8; j++) {
            if (k >= 4) {
                SetSub(GetSub(this_, *a), lbl_80543A4C, lbl_80543A40, lbl_80543A40, lbl_80543A40, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C);
                SetSub(GetSub(this_, *b), lbl_80543A4C, lbl_80543A40, lbl_80543A40, lbl_80543A40, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C);
                GetSub(this_, *c)[0xb0] = 0;
                GetSub(this_, *d)[0xb0] = 0;
                n -= 4;
                k -= 4;
            } else {
                if (k == 0) {
                    SetSub(GetSub(this_, *a), lbl_80543A40, lbl_80543A40, lbl_80543A40, lbl_80543A40, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C);
                    SetSub(GetSub(this_, *b), lbl_80543A40, lbl_80543A40, lbl_80543A40, lbl_80543A40, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C);
                    if (n > 0) {
                        GetSub(this_, *c)[0xb0] = 1;
                        GetSub(this_, *d)[0xb0] = 1;
                        n -= 4;
                    } else {
                        GetSub(this_, *c)[0xb0] = 0;
                        GetSub(this_, *d)[0xb0] = 0;
                    }
                } else if (k == 1) {
                    SetSub(GetSub(this_, *a), lbl_80543A40, lbl_80543A40, lbl_80543A40, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C);
                    SetSub(GetSub(this_, *b), lbl_80543A40, lbl_80543A40, lbl_80543A40, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C);
                    GetSub(this_, *c)[0xb0] = 0;
                    GetSub(this_, *d)[0xb0] = 0;
                    n -= 4;
                } else if (k == 2) {
                    SetSub(GetSub(this_, *a), lbl_80543A40, lbl_80543A40, lbl_80543A4C, lbl_80543A40, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C);
                    SetSub(GetSub(this_, *b), lbl_80543A40, lbl_80543A40, lbl_80543A4C, lbl_80543A40, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C);
                    GetSub(this_, *c)[0xb0] = 0;
                    GetSub(this_, *d)[0xb0] = 0;
                    n -= 4;
                } else if (k == 3) {
                    SetSub(GetSub(this_, *a), lbl_80543A40, lbl_80543A4C, lbl_80543A40, lbl_80543A40, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C);
                    SetSub(GetSub(this_, *b), lbl_80543A40, lbl_80543A4C, lbl_80543A40, lbl_80543A40, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C, lbl_80543A4C);
                    GetSub(this_, *c)[0xb0] = 0;
                    GetSub(this_, *d)[0xb0] = 0;
                    n -= 4;
                }
                k = 0;
            }
            a++;
            b++;
            c++;
            d++;
        }
    }
}

extern "C" void fn_80423DF0(u8* this_, s32 i) {
    s32 idx = -1;
    u8 mask = 1 << i;
    u8* tbl = lbl_8048E1B8;
    s32 j;
    u32* pair;
    u32* pair2;
    s32 set;

    set = (this_[0x259] & mask) != 0;
    if (!set && !fn_80230188(i)) {
        fn_8022EA0C(i);
        if (fn_8023BE0C() && !(lbl_8053AED0[0x255] & mask)) {
            this_[0x259] |= mask;
            pair = (u32*)(tbl + 0xe28) + i * 2;
            CallPair(this_, pair[0], pair[1])[0xb0] = 1;
        }
    } else if ((u32)fn_80309D24(lbl_8053AD30, fn_8030AAF4(i), 0x100) == 0 || (lbl_8053AED0[0x255] & mask) != 0 || fn_80230188(i)) {
        this_[0x259] &= ~mask;
        pair = (u32*)(tbl + 0xe28) + i * 2;
        CallPair(this_, pair[0], pair[1])[0xb0] = 0;
    }

    switch (fn_802373EC(i)) {
    case 1:
        idx = 5;
        break;
    case 2:
        idx = 0xb;
        break;
    case 3:
        idx = 2;
        break;
    case 4:
        idx = 3;
        break;
    case 5:
        idx = 6;
        break;
    case 6:
        idx = 7;
        break;
    case 7:
        idx = 4;
        break;
    case 8:
        idx = 8;
        break;
    case 9:
        idx = 0xa;
        break;
    case 10:
        idx = 1;
        break;
    case 11:
    case 12:
    case 13:
        idx = 0;
        break;
    }

    if (*(s32*)(this_ + 0x148 + i * 4) != idx || (lbl_8053AED0[0x255] & mask) != 0) {
        *(s32*)(this_ + 0x148 + i * 4) = idx;
        pair = (u32*)(tbl + 0x6e8 + i * 0x60);
        pair2 = (u32*)(tbl + 0x868 + i * 0x60);
        for (j = 0; j < 0xc; j++) {
            if (j == idx) {
                CallPair(this_, pair[0], pair[1])[0xb0] = 1;
                CallPair(this_, pair2[0], pair2[1])[0xb0] = 1;
            } else {
                CallPair(this_, pair[0], pair[1])[0xb0] = 0;
                CallPair(this_, pair2[0], pair2[1])[0xb0] = 0;
            }
            pair += 2;
            pair2 += 2;
        }
        if (fn_8023725C(i) == 2) {
            pair = (u32*)(tbl + 0x688 + i * 0x18);
            for (j = 0; j < 3; j++) {
                CallPair(this_, pair[0], pair[1])[0xb0] = 1;
                pair += 2;
            }
        } else {
            pair = (u32*)(tbl + 0x688 + i * 0x18);
            for (j = 0; j < 3; j++) {
                CallPair(this_, pair[0], pair[1])[0xb0] = 0;
                pair += 2;
            }
        }
    }
}

extern "C" void fn_80425128(u8* this_) {
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
            this_[0x256] |= (u8)bit;
            *(u32*)(this_ + 0x168 + i * 4) = 0;
            table[0x3a + i] = fn_80236100(i);
            this_[0x257] |= (u8)bit;
            *(u32*)(this_ + 0x178 + i * 4) = 0;
        }
    }
}

extern "C" s32 fn_80236228(s32 i);
extern "C" void fn_80230FD0(s32 i, s32 msg);
extern "C" void fn_8023619C(s32 i, s32 v);
extern "C" void fn_802362C4(s32 i, s32 v);
extern "C" void fn_80425234(u8* this_, s32 i, s32 val, u8 flag) {
    s32 k;
    s32 sum;
    u32* table;

    if (fn_8022F514(i)) {
        k = fn_8022F3DC(i);
    } else {
        k = i;
    }
    if (flag) {
        sum = val + (s32)fn_80236100(k);
        if (sum > 9999) {
            val = 9999 - fn_80236228(k);
        } else if (sum < -5000) {
            val = -5000 - fn_80236228(k);
        }
    } else {
        sum = val + fn_80236228(k);
        if (sum > 9999) {
            val = 9999 - fn_80236228(k);
        } else if (sum < 0) {
            if (fn_80236228(k) <= 0) {
                val = 0;
            } else {
                val = -fn_80236228(k);
            }
        }
    }
    if (val >= 1000 || val <= -1000) {
        ((s16*)(this_ + 0x1f8))[i] = __abs(val) / 100;
        ((s16*)(this_ + 0x200))[i] = 0;
    } else {
        fn_80230FD0(i, 0x20034);
    }
    if (flag) {
        fn_8023619C(k, val);
    } else {
        fn_802362C4(k, val);
    }
    table = (u32*)lbl_80529DEC;
    table[0x3a + k] = fn_80236100(k);
    ((u32*)(this_ + 0x178))[k] = 0;
    this_[0x257] |= (u8)(1 << k);
}

extern "C" void fn_80230EB8(s32 i, s32 a);
extern u8 lbl_8050DB0C[];
extern "C" void fn_804253E0(u8* this_, s32 i) {
    s32* table;
    s32 j;
    s32* p;
    s32* q;
    s32 v;
    s32 off = i * 4;

    p = (s32*)(lbl_80529DEC + off + 0xd8);
    v = *p;
    if (v < (s32)fn_80237774(i)) {
        *(s32*)(this_ + off + 0x168) = *(s32*)(this_ + off + 0x168) + 1;
        if (*(s32*)(this_ + off + 0x168) >= 10) {
            table = (s32*)lbl_80529DEC;
            *p = *p + 1;
            for (j = 0; j < 4; j++) {
                if (j != i && fn_8022F514(j) && fn_8022F3DC(j) == i) {
                    table[0x36 + j] = *(s32*)((u8*)table + off + 0xd8);
                }
            }
            this_[0x256] |= (u8)(1 << i);
            *(s32*)(this_ + off + 0x168) = 0;
            fn_80230EB8(i, 9);
            *(s16*)(this_ + i * 2 + 0x1e8) = *(s16*)(lbl_8050DB0C + 0x74) * *(s16*)(lbl_8050DB0C + 0x76) + 0x1e;
            *(s32*)(this_ + off + 0x1b8) = *(s32*)(this_ + off + 0x1a8);
            *(s32*)(this_ + off + 0x1a8) = *p;
            *(s32*)(this_ + off + 0x1c8) = fn_80237810(i);
        }
    } else {
        v = *p;
        if (v > (s32)fn_80237774(i)) {
            s32 bit = 1 << i;
            table = (s32*)lbl_80529DEC;
            ((u8*)table)[0x24a] |= (u8)bit;
            *(s32*)(this_ + off + 0x168) = *(s32*)(this_ + off + 0x168) + 1;
            if (*(s32*)(this_ + off + 0x168) >= 10) {
                *p = *p - 1;
                for (j = 0; j < 4; j++) {
                    if (j != i && fn_8022F514(j) && fn_8022F3DC(j) == i) {
                        table[0x36 + j] = *(s32*)((u8*)table + off + 0xd8);
                    }
                }
                this_[0x256] |= (u8)bit;
                *(s32*)(this_ + off + 0x168) = 0;
            }
            *(s16*)(this_ + i * 2 + 0x1e8) = *(s16*)(lbl_8050DB0C + 0x74) * *(s16*)(lbl_8050DB0C + 0x76) + 0x1e;
            *(s32*)(this_ + off + 0x1b8) = *(s32*)(this_ + off + 0x1a8);
            *(s32*)(this_ + off + 0x1a8) = *p;
            *(s32*)(this_ + off + 0x1c8) = fn_80237810(i);
        } else {
            *(s32*)(this_ + off + 0x168) = 0;
        }
    }

    q = (s32*)(lbl_80529DEC + off + 0xe8);
    v = *q;
    if (v < (s32)fn_80236100(i)) {
        *(s32*)(this_ + off + 0x178) = *(s32*)(this_ + off + 0x178) + 1;
        if (*(s32*)(this_ + off + 0x178) >= 2) {
            *q = *q + 2;
            v = *q;
            if (v < (s32)fn_80236100(i)) {
                fn_80230EB8(i, 4);
            } else {
                *q = fn_80236100(i);
                fn_80230EB8(i, 0x51);
            }
            this_[0x257] |= (u8)(1 << i);
            *(s32*)(this_ + off + 0x178) = 0;
        }
    } else {
        v = *q;
        if (v > (s32)fn_80236100(i)) {
            *(s32*)(this_ + off + 0x178) = *(s32*)(this_ + off + 0x178) + 1;
            if (*(s32*)(this_ + off + 0x178) >= 2) {
                *q = *q - 2;
                v = *q;
                if (v < (s32)fn_80236100(i)) {
                    *q = fn_80236100(i);
                    fn_80230EB8(i, 0x51);
                } else {
                    fn_80230EB8(i, 0x4e);
                }
                this_[0x257] |= (u8)(1 << i);
                *(s32*)(this_ + off + 0x178) = 0;
            }
        } else {
            *(s32*)(this_ + off + 0x178) = 0;
        }
    }

    if (*(s16*)(this_ + i * 2 + 0x1f8) > 0) {
        if (*(s16*)(this_ + i * 2 + 0x200) == 0) {
            *(s16*)(this_ + i * 2 + 0x1f8) = *(s16*)(this_ + i * 2 + 0x1f8) - 1;
            fn_80230FD0(i, 0x20034);
            if (*(s16*)(this_ + i * 2 + 0x1f8) != 0) {
                *(s16*)(this_ + i * 2 + 0x200) = 12;
            }
        } else {
            *(s16*)(this_ + i * 2 + 0x200) = *(s16*)(this_ + i * 2 + 0x200) - 1;
        }
    }
}

extern "C" void fn_80425F24(u8* this_) {
    fn_8013B490(lbl_8053AB10);
    (*(J2DScreen**)(this_ + 0x18))->draw(lbl_80543A40, lbl_80543A40, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void fn_804263A8(u8* this_) {
    u8* base = lbl_8048E1B8;
    s32 i;

    for (i = 0; i < 4; i++) {
        u8 mask = 1 << i;
        if (!(lbl_8053AAF8[0x82] & mask)) {
            this_[0x25d] &= ~mask;
        } else {
            if ((lbl_8053AED0[0xdd] & mask) && !(this_[0x25c] & mask)) {
                this_[0x25c] |= mask;
                this_[0x25d] |= mask;
            } else if (lbl_8053AED0[0xdc] & 0x10) {
                this_[0x25d] &= ~mask;
            } else if (*(s32*)(lbl_8053AAF8 + 0x4c) == 0xb) {
                this_[0x25d] &= ~mask;
                *(u32*)(lbl_80529DEC + 0xd8 + i * 4) = fn_80237774(i);
                *(u32*)(lbl_80529DEC + 0xe8 + i * 4) = fn_80236100(i);
                *(u32*)(lbl_80529DEC + 0x108 + i * 4) = fn_802375B0(i);
            }
        }

        *(s32*)(this_ + 0x158 + i * 4) = 0x180;
        *(s32*)(this_ + 0x168 + i * 4) = 0;
        *(s32*)(this_ + 0x178 + i * 4) = 0;
        *(s32*)(this_ + 0x188 + i * 4) = 0;
        *(f32*)(this_ + 0xf8 + i * 4) = lbl_80543A40;
        *(f32*)(this_ + 0x108 + i * 4) = lbl_80543A40;
        *(f32*)(this_ + 0x118 + i * 4) = lbl_80543A40;
        *(f32*)(this_ + 0x128 + i * 4) = lbl_80543A40;
        *(f32*)(this_ + 0x138 + i * 4) = lbl_80543A40;
        this_[0x251 + i] = i;
        this_[0x24d + i] = 0xff;
        *(u16*)(this_ + 0x1f0 + i * 2) = 0;
        *(s32*)(this_ + 0x198 + i * 4) = 0;
        *(s32*)(this_ + 0x1a8 + i * 4) = 0;
        *(s32*)(this_ + 0x1b8 + i * 4) = 0;
        *(s32*)(this_ + 0x1c8 + i * 4) = 0;
        *(u16*)(this_ + 0x1e8 + i * 2) = 0;
        *(u16*)(this_ + 0x1f8 + i * 2) = 0;
        *(u16*)(this_ + 0x200 + i * 2) = 0;
        *(s32*)(this_ + 0x1d8 + i * 4) = 0;
        *(u16*)(this_ + 0x208 + i * 2) = 0;
    }

    for (i = 0; i < 4; i++) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
            fn_80421A34(this_, i, 1);
        }
    }

    this_[0x255] = 0xf;
    this_[0x256] = 0xf;
    this_[0x257] = 0xf;
    this_[0x258] = 0;
    this_[0x259] = 0;
    this_[0x25a] = 0;
    this_[0x25b] = 0;
    *(s32*)(this_ + 0x148) = -2;
    *(s32*)(this_ + 0x14c) = -2;
    *(s32*)(this_ + 0x150) = -2;
    *(s32*)(this_ + 0x154) = -2;

    for (i = 0; i < 4; i++) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
            SetKeyFlag(*(u8**)(this_ + 0x18), *(u64*)(base + 0xd68 + i * 8), 0);
            SetKeyFlag(*(u8**)(this_ + 0x18), *(u64*)(base + 0xda8 + i * 8), 0);
            SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xdc8 + i * 8), 0);
            SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xde8 + i * 8), 1);
            SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xe28 + i * 8), 0);
            SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xe68 + i * 8), 1);
            if (lbl_8050EC80[*(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x89] != 0) {
                SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xe88 + i * 8), 1);
            } else {
                SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xe88 + i * 8), 0);
            }
            if (((s32)lbl_8053AAF8[0x83] >> (2 * i) & 3) == 2) {
                SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xe08 + i * 8), 1);
                SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xea8 + i * 8), 1);
                SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xec8 + i * 8), 0);
            } else {
                SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xe08 + i * 8), 0);
                SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xea8 + i * 8), 0);
                SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xec8 + i * 8), 0);
            }
        } else {
            SetKeyFlag(*(u8**)(this_ + 0x18), *(u64*)(base + 0xd68 + i * 8), 0);
            SetKeyFlag(*(u8**)(this_ + 0x18), *(u64*)(base + 0xda8 + i * 8), 0);
            SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xdc8 + i * 8), 0);
            SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xde8 + i * 8), 0);
            SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xe08 + i * 8), 0);
            SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xe28 + i * 8), 0);
            SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xe68 + i * 8), 0);
            SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xe88 + i * 8), 0);
            SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xea8 + i * 8), 0);
            SetKeyFlag(*(u8**)(this_ + 4), *(u64*)(base + 0xec8 + i * 8), 0);
        }
    }

    {
        u32 tag = fn_804030C4(0x54494D47, lbl_804B145C[0]);
        for (i = 0; i < 4; i++) {
            CallSlot68(GetKeyed(*(u8**)(this_ + 0x18), *(u64*)(base + 0xd68 + i * 8)), tag);
            CallSlot68(GetKeyed(*(u8**)(this_ + 0x18), *(u64*)(base + 0xd88 + i * 8)), tag);
        }
    }

    for (i = 0; i < 4; i++) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
            fn_80424148(this_, i, 1);
        }
    }
    fn_8044172C(*(void**)(this_ + 0xf0));
}

extern "C" void* fn_80426AD4(void* this_, s16 how) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B146C;
        ReleaseSlot((void**)((u8*)this_ + 0x4c));
        ReleaseSlot((void**)((u8*)this_ + 0xf0));
        ReleaseSlot((void**)((u8*)this_ + 0x4));

        void** slot = (void**)this_;
        for (s32 i = 0; i < 4; i++) {
            ReleaseSlot(slot + 2);
            ReleaseSlot(slot + 11);
            slot++;
        }

        ReleaseSlot((void**)((u8*)this_ + 0x18));

        void** base = (void**)this_;
        for (s32 i = 0; i < 4; i++) {
            ReleaseSlot(base + 20);
            ReleaseSlot(base + 24);
            ReleaseSlot(base + 28);
            ReleaseSlot(base + 32);
            ReleaseSlot(base + 36);
            ReleaseSlot(base + 40);
            ReleaseSlot(base + 44);
            ReleaseSlot(base + 48);
            ReleaseSlot(base + 52);
            ReleaseSlot(base + 56);
            base++;
        }

        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
