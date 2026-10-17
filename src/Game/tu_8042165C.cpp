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
extern u8* lbl_8053AED0;
extern u8* lbl_8053AD30;
extern "C" u8 fn_80230188(s32 i);
extern "C" void fn_8022EA0C(s32 i);
extern "C" u8 fn_8023BE0C(void);
extern "C" u32 fn_8030AAF4(s32 i);
extern "C" s32 fn_80309D24(u8* a, u32 b, s32 c);
extern "C" u32 fn_802373EC(s32 i);
extern "C" s32 fn_8023725C(s32 i);

typedef u8* (*PairCallFn)(u8* self, u32 a, u32 b);

// Virtual slot 15 of the sub-object at this+4: takes a (u32, u32) pair and returns the object whose 0xb0 byte is set.
static inline u8* CallPair(u8* this_, u32 a, u32 b) {
    u8* sub = *(u8**)(this_ + 4);
    return ((PairCallFn)(*(void***)sub)[15])(sub, a, b);
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
extern "C" void fn_80421A34(u8* this_, s32 i, u8 flag) {
    s32 j;
    u8 bit = 1 << i;
    f32* fv = (f32*)(this_ + 0x118);
    f32 old = fv[i];

    if (!(this_[0x25d] & bit)) {
        if (old > 0.0f) {
            fv[i] = old - 0.1f;
        } else {
            fv[i] = 0.0f;
        }
        (*(u8**)(lbl_8053AB10 + 0x20))[0x217 + i] = 1;
    } else {
        u32* table = (u32*)lbl_80529DEC;
        if (table[0x36 + i] == 0) {
            if (old > 0.6f) {
                fv[i] = old - 0.1f;
                if (fv[i] > 0.6f) {
                    fv[i] = 0.6f;
                }
            } else if (old < 0.6f) {
                fv[i] = old + 0.1f;
                if (fv[i] < 0.6f) {
                    fv[i] = 0.6f;
                }
            }
        } else {
            if (old < 1.0f) {
                fv[i] = old + 0.1f;
            } else {
                fv[i] = 1.0f;
            }
        }
    }

    if (fv[i] != old || flag) {
        u8* p = this_ + i * 4;
        u64* a = (u64*)(lbl_8048E1B8 + 0xc68);
        u64* b = (u64*)(lbl_8048E1B8 + 0xce8);
        u64* c = (u64*)(lbl_8048E1B8 + 0xca8);
        u64* d = (u64*)(lbl_8048E1B8 + 0xd28);
        for (j = 0; j < 8; j++) {
            (*(SubObj**)(p + 0x8))->w13(*a)->w07((s32)((f32)this_[0x21c] * fv[i]));
            (*(SubObj**)(p + 0x8))->w13(*b)->w07((s32)((f32)this_[0x21d] * fv[i]));
            (*(SubObj**)(p + 0x8))->w13(*c)->w07((s32)((f32)this_[0x21e] * fv[i]));
            (*(SubObj**)(p + 0x8))->w13(*d)->w07((s32)((f32)this_[0x21f] * fv[i]));
            a++;
            b++;
            c++;
            d++;
        }
        u64* e = (u64*)(lbl_8048E1B8 + 0xfa0);
        for (j = 0; j < 6; j++) {
            (*(SubObj**)(p + 0x2c))->w13(*e)->w07((s32)((f32)this_[0x247 + j] * fv[i]));
            e++;
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

    if (!((s32)(this_[0x259] & mask) != 0) && !fn_80230188(i)) {
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
    s32 i;
    s32 j;
    s32 bit;
    s32 flag;
    u32* table;

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
        ((s16*)(this_ + 0x1f8))[i] = (((val >> 31) ^ val) - (val >> 31)) / 100;
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

extern "C" void fn_80425F24(u8* this_) {
    fn_8013B490(lbl_8053AB10);
    (*(J2DScreen**)(this_ + 0x18))->draw(lbl_80543A40, lbl_80543A40, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
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
