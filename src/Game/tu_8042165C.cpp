#include "types.h"
#include "JSystem/JGeometry/Box.h"

struct HudPlayerState {
    u8 pad[0x89];
    u8 visible;
    u8 tail[0x3e];
};

class J2DOrthoGraph {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void setPort();
    void setOrtho(const JGeometry::TBox2<f32>&, f32, f32);
};

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
extern const u8 lbl_8048E1B8[];
struct HeartPane {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual u8* search(u64);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void set(f32, f32, f32, f32, f32, f32, f32, f32);
    virtual void v64();
    virtual void v65();
};

static inline u8* GetHeart(u8* obj, u64 key) { return ((HeartPane*)obj)->search(key); }
static inline void SetHeart(u8* obj, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g, f32 h) { ((HeartPane*)obj)->set(a,b,c,d,e,f,g,h); }
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

#include "JSystem/JUtility/TColor.h"
typedef void (*SetBlackWhiteFn)(u8* self, JUtility::TColor black, JUtility::TColor white);

// Picture pane reached through GetSub: changeTexture(img, id) at vtable 0x110, setBlackWhite(black, white) at 0x130.
struct TimerPicture {
    virtual void p00(); virtual void p01(); virtual void p02(); virtual void p03();
    virtual void p04(); virtual void p05(); virtual void p06(); virtual void p07();
    virtual void p08(); virtual void p09(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27();
    virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31();
    virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35();
    virtual void p36(); virtual void p37(); virtual void p38(); virtual void p39();
    virtual void p40(); virtual void p41(); virtual void p42(); virtual void p43();
    virtual void p44(); virtual void p45(); virtual void p46(); virtual void p47();
    virtual void p48(); virtual void p49(); virtual void p50(); virtual void p51();
    virtual void p52(); virtual void p53(); virtual void p54(); virtual void p55();
    virtual void p56(); virtual void p57(); virtual void p58(); virtual void p59();
    virtual void p60(); virtual void p61(); virtual void p62(); virtual void p63();
    virtual void p64(); virtual void p65();
    virtual void* changeTexture(u32 img, u8 id);
    virtual void p67(); virtual void p68(); virtual void p69(); virtual void p70();
    virtual void p71(); virtual void p72(); virtual void p73();
    virtual bool setBlackWhite(JUtility::TColor black, JUtility::TColor white);
};

static inline TimerPicture* GetPicture(u8* this_, u64 key) {
    return (TimerPicture*)(*(SubObj**)(this_ + 4))->w13(key);
}

// Shows or hides the separator of player idx's timer (both picture layers).
static inline void SetTimerMark(u8* this_, u8* base, u32 idx, u8 v) {
    ((u8*)GetPicture(this_, ((u64*)(base + 0xa28 + idx * 0x28))[4]))[0xb0] = v;
    ((u8*)GetPicture(this_, ((u64*)(base + 0xac8 + idx * 0x28))[4]))[0xb0] = v;
}

// Sets digit `pos` of player idx's timer (both picture layers) to texture tex.
static inline void SetTimerDigitAt(u8* this_, u64* a, u64* b, u32 pos, u32 tex) {
    GetPicture(this_, a[pos])->changeTexture(tex, 0);
    GetPicture(this_, b[pos])->changeTexture(tex, 0);
}

static inline void SetTimerDigit(u8* this_, u8* base, u32 idx, u32 pos, u32 tex) {
    GetPicture(this_, ((u64*)(base + 0xa28 + idx * 0x28))[pos])->changeTexture(tex, 0);
    GetPicture(this_, ((u64*)(base + 0xac8 + idx * 0x28))[pos])->changeTexture(tex, 0);
}

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
    u8* base = (u8*)lbl_8048E1B8;
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
    u8* base = (u8*)lbl_8048E1B8;
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

extern "C" void fn_8042215C(u8* this_, s32 idx) {
const u8* base = lbl_8048E1B8;
s16* timer = (s16*)(this_ + idx * 2);
if (timer[0xf4] == 0) {
((u32*)(this_ + 0x1a8))[idx] = fn_80237774(idx);
((s32*)(this_ + 0x1c8))[idx] = fn_80237810(idx);
} else {
s32 cnt = ((s32*)(this_ + 0x1c8))[idx];
s32 n = ((s32*)(this_ + 0x1a8))[idx];
if(cnt > 32) cnt=32;
if(cnt < 0) cnt=0;
if(cnt<n) n=cnt;
if(n<0) n=0;
const u64* a=(const u64*)(base+0xc68);
const u64* b=(const u64*)(base+0xce8);
const u64* c=(const u64*)(base+0xca8);
const u64* d=(const u64*)(base+0xd28);
for(s32 k=0;k<8;k++) {
if(n>=4) {GetHeart(*(u8**)(this_ + idx * 4 + 8), a[k])[0xb0] = 1;
GetHeart(*(u8**)(this_ + idx * 4 + 8), b[k])[0xb0] = 1;
SetHeart(GetHeart(*(u8**)(this_ + idx * 4 + 8), a[k]), 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
SetHeart(GetHeart(*(u8**)(this_ + idx * 4 + 8), b[k]), 1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
GetHeart(*(u8**)(this_ + idx * 4 + 8), c[k])[0xb0] = 0;
GetHeart(*(u8**)(this_ + idx * 4 + 8), d[k])[0xb0] = 0;
n-=4; cnt -= 4;}
else {
if(n==0) {
GetHeart(*(u8**)(this_ + idx * 4 + 8), a[k])[0xb0] = 0; GetHeart(*(u8**)(this_ + idx * 4 + 8), b[k])[0xb0] = 0;
if(cnt>0) {GetHeart(*(u8**)(this_ + idx * 4 + 8), c[k])[0xb0] = 1; GetHeart(*(u8**)(this_ + idx * 4 + 8), d[k])[0xb0] = 1; cnt-=4;}
else {GetHeart(*(u8**)(this_ + idx * 4 + 8), c[k])[0xb0] = 0; GetHeart(*(u8**)(this_ + idx * 4 + 8), d[k])[0xb0] = 0;}
} else if(n==1) {GetHeart(*(u8**)(this_ + idx * 4 + 8), a[k])[0xb0] = 1;
GetHeart(*(u8**)(this_ + idx * 4 + 8), b[k])[0xb0] = 1;
SetHeart(GetHeart(*(u8**)(this_ + idx * 4 + 8), a[k]), 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
SetHeart(GetHeart(*(u8**)(this_ + idx * 4 + 8), b[k]), 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
GetHeart(*(u8**)(this_ + idx * 4 + 8), c[k])[0xb0] = 0;
GetHeart(*(u8**)(this_ + idx * 4 + 8), d[k])[0xb0] = 0;
cnt -= 4;}
else if(n==2) {GetHeart(*(u8**)(this_ + idx * 4 + 8), a[k])[0xb0] = 1;
GetHeart(*(u8**)(this_ + idx * 4 + 8), b[k])[0xb0] = 1;
SetHeart(GetHeart(*(u8**)(this_ + idx * 4 + 8), a[k]), 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
SetHeart(GetHeart(*(u8**)(this_ + idx * 4 + 8), b[k]), 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
GetHeart(*(u8**)(this_ + idx * 4 + 8), c[k])[0xb0] = 0;
GetHeart(*(u8**)(this_ + idx * 4 + 8), d[k])[0xb0] = 0;
cnt -= 4;}
else if(n==3) {GetHeart(*(u8**)(this_ + idx * 4 + 8), a[k])[0xb0] = 1;
GetHeart(*(u8**)(this_ + idx * 4 + 8), b[k])[0xb0] = 1;
SetHeart(GetHeart(*(u8**)(this_ + idx * 4 + 8), a[k]), 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
SetHeart(GetHeart(*(u8**)(this_ + idx * 4 + 8), b[k]), 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f);
GetHeart(*(u8**)(this_ + idx * 4 + 8), c[k])[0xb0] = 0;
GetHeart(*(u8**)(this_ + idx * 4 + 8), d[k])[0xb0] = 0;
cnt -= 4;}
n=0;
}
}
timer[0xf4]--;
}
}

extern "C" void fn_80423248(u8* this_, u32 idx) {
    u8* base = (u8*)lbl_8048E1B8;
    if (this_[0x257] & (u8)(1 << idx)) {
        s32 t;
        s32 sel = 0;
        s32 v = ((s32*)(lbl_80529DEC + 0xe8))[idx];
        s32 j;
        u32 name;
        t = v;
        if (v > 9999) {
            t = 9999;
        }
        if (t < 0) {
            s32 off = idx * 0x28;
            u64* key = (u64*)(base + 0xa28 + off);
            u64* p = key;
            for (j = 0; j < 5; j++) {
                GetPicture(this_, *p)->setBlackWhite(JUtility::TColor(0, 0, 0, 0), JUtility::TColor(0xff, 0x55, 0x41, 0xff));
                p++;
            }
            if (t < -5000) {
                t = -5000;
            }
            t *= -1;
            u32 s = fn_804030C4(0x54494d47, (u32)(base + 0x1058));
            GetPicture(this_, *key)->changeTexture(s, 0);
            GetPicture(this_, *(u64*)(base + 0xac8 + off))->changeTexture(s, 0);
            ((u8*)GetPicture(this_, ((u64*)(base + 0xa28 + off))[4]))[0xb0] = 1;
            ((u8*)GetPicture(this_, ((u64*)(base + 0xac8 + off))[4]))[0xb0] = 1;
            sel = 1;
        } else {
            s32 off = idx * 0x28;
            u64* p = (u64*)(base + 0xa28 + off);
            for (j = 0; j < 5; j++) {
                GetPicture(this_, *p)->setBlackWhite(*(JUtility::TColor*)(this_ + 0x214), *(JUtility::TColor*)(this_ + 0x210));
                p++;
            }
            ((u8*)GetPicture(this_, ((u64*)(base + 0xa28 + off))[4]))[0xb0] = 0;
            ((u8*)GetPicture(this_, ((u64*)(base + 0xac8 + off))[4]))[0xb0] = 0;
        }
        name = lbl_804B1434[t / 1000];
        t %= 1000;
        SetTimerDigit(this_, base, idx, sel, fn_804030C4(0x54494d47, name));
        name = lbl_804B1434[t / 100];
        t %= 100;
        SetTimerDigit(this_, base, idx, sel + 1, fn_804030C4(0x54494d47, name));
        name = lbl_804B1434[t / 10];
        t %= 10;
        SetTimerDigit(this_, base, idx, sel + 2, fn_804030C4(0x54494d47, name));
        SetTimerDigit(this_, base, idx, sel + 3, fn_804030C4(0x54494d47, lbl_804B1434[t]));
    }
}

extern "C" void fn_80423804(u8* this_, u32 idx) {
    u8* base = (u8*)lbl_8048E1B8;
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

        u32 off = idx << 6;
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
    u8* tbl = (u8*)lbl_8048E1B8;
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

// Copies player i's counter to every player linked to i.
static inline void SyncLinkedCount(s32 i) {
    u8* table = lbl_80529DEC;
    for (s32 j = 0; j < 4; j++) {
        if (j != i && fn_8022F514(j) && fn_8022F3DC(j) == i) {
            *(s32*)(table + j * 4 + 0xd8) = *(s32*)(table + i * 4 + 0xd8);
        }
    }
}

extern "C" void fn_80230EB8(s32 i, s32 a);
extern u8 lbl_8050DB0C[];

// Steps player i's displayed count toward the real one by 2 every other frame.
static inline void StepCount2(u8* this_, s32 i) {
    s32* q = &((s32*)(lbl_80529DEC + 0xe8))[i];
    s32 c = *q;
    if (c < (s32)fn_80236100(i)) {
        ((s32*)(this_ + 0x178))[i] = ((s32*)(this_ + 0x178))[i] + 1;
        if (((s32*)(this_ + 0x178))[i] >= 2) {
            *q = *q + 2;
            s32 c2 = *q;
            if (c2 >= (s32)fn_80236100(i)) {
                *q = fn_80236100(i);
                fn_80230EB8(i, 0x51);
            } else {
                fn_80230EB8(i, 4);
            }
            this_[0x257] |= (u8)(1 << i);
            ((s32*)(this_ + 0x178))[i] = 0;
        }
    } else {
        s32 c3 = *q;
        if (c3 > (s32)fn_80236100(i)) {
            ((s32*)(this_ + 0x178))[i] = ((s32*)(this_ + 0x178))[i] + 1;
            if (((s32*)(this_ + 0x178))[i] >= 2) {
                *q = *q - 2;
                s32 c4 = *q;
                if (c4 < (s32)fn_80236100(i)) {
                    *q = fn_80236100(i);
                    fn_80230EB8(i, 0x51);
                } else {
                    fn_80230EB8(i, 0x4e);
                }
                this_[0x257] |= (u8)(1 << i);
                ((s32*)(this_ + 0x178))[i] = 0;
            }
        } else {
            ((s32*)(this_ + 0x178))[i] = 0;
        }
    }
}

struct J2DPane {
    JGeometry::TBox2<f32>* getBounds();
};

// Pane reached through GetKeyed: resize(w, h) at vtable 0x18.
struct HudResizePane {
    virtual void r00();
    virtual void r01();
    virtual void r02();
    virtual void r03();
    virtual void resize(f32 w, f32 h);
};

static inline BOOL HudBitSet(u8 flags, u8 mask) { return (flags & mask) != 0; }

extern "C" void fn_80422824(u8* this_);
extern "C" u8 fn_8023BD70(s32 i);
extern "C" void fn_80441490(void* p);
extern const f32 lbl_80543A68;
extern const f32 lbl_80543A70;
extern const f32 lbl_80543A74;
extern const f32 lbl_80543A78;
extern const f32 lbl_80543A7C;
extern const f32 lbl_80543A80;
extern const f32 lbl_80543A84;

extern "C" void fn_804253E0(u8* this_, s32 i) {
    s32* p = &((s32*)(lbl_80529DEC + 0xd8))[i];
    s32 cur = *p;
    if (cur < (s32)fn_80237774(i)) {
        ((s32*)(this_ + 0x168))[i] = ((s32*)(this_ + 0x168))[i] + 1;
        if (((s32*)(this_ + 0x168))[i] >= 10) {
            *p = *p + 1;
            SyncLinkedCount(i);
            this_[0x256] |= (u8)(1 << i);
            ((s32*)(this_ + 0x168))[i] = 0;
            fn_80230EB8(i, 9);
            ((s16*)(this_ + 0x1e8))[i] = *(s16*)(lbl_8050DB0C + 0x74) * *(s16*)(lbl_8050DB0C + 0x76) + 0x1e;
            ((s32*)(this_ + 0x1b8))[i] = ((s32*)(this_ + 0x1a8))[i];
            ((s32*)(this_ + 0x1a8))[i] = *p;
            ((s32*)(this_ + 0x1c8))[i] = fn_80237810(i);
        }
    } else {
        s32 cur2 = *p;
        if (cur2 > (s32)fn_80237774(i)) {
            s32 bit = 1 << i;
            lbl_80529DEC[0x24a] |= (u8)bit;
            ((s32*)(this_ + 0x168))[i] = ((s32*)(this_ + 0x168))[i] + 1;
            if (((s32*)(this_ + 0x168))[i] >= 10) {
                *p = *p - 1;
                SyncLinkedCount(i);
                this_[0x256] |= (u8)bit;
                ((s32*)(this_ + 0x168))[i] = 0;
            }
            ((s16*)(this_ + 0x1e8))[i] = *(s16*)(lbl_8050DB0C + 0x74) * *(s16*)(lbl_8050DB0C + 0x76) + 0x1e;
            ((s32*)(this_ + 0x1b8))[i] = ((s32*)(this_ + 0x1a8))[i];
            ((s32*)(this_ + 0x1a8))[i] = *p;
            ((s32*)(this_ + 0x1c8))[i] = fn_80237810(i);
        } else {
            ((s32*)(this_ + 0x168))[i] = 0;
        }
    }

    StepCount2(this_, i);

    s16* t = (s16*)(this_ + i * 2);
    s32 n = t[0x1f8 / 2];
    if (n > 0) {
        s32 w = t[0x200 / 2];
        if (w == 0) {
            t[0x1f8 / 2] = n - 1;
            fn_80230FD0(i, 0x20034);
            if (t[0x1f8 / 2] != 0) {
                t[0x200 / 2] = 12;
            }
        } else {
            t[0x200 / 2] = w - 1;
        }
    }
}

extern "C" void fn_804257E4(u8* this_) {
    u8 mask;
    s32 sh;
    u64* tv1;
    u64* on1;
    u64* off1;
    u64* on2;
    s32* counts;
    u64* bars;
    s32 bit;
    u64* pos;
    s32 i;
    s32 j;
    s32 v;
    u8* base = (u8*)lbl_8048E1B8;

    pos = (u64*)(base + 0xdc8);
    counts = (s32*)lbl_80529DEC;
    on1 = pos;
    tv1 = (u64*)(base + 0xda8);
    off1 = (u64*)(base + 0xde8);
    on2 = (u64*)(base + 0xec8);
    bars = (u64*)(base + 0x148);
    for (i = 0, sh = 0; i < 4; i++) {
        bit = 1 << i;
        mask = bit;
        if (!HudBitSet(lbl_8053AAF8[0x82], mask)) {
            this_[0x25d] &= ~mask;
        } else if (HudBitSet(lbl_8053AED0[0xdd], mask) && !(this_[0x25c] & mask)) {
            this_[0x25c] |= mask;
            this_[0x25d] |= mask;
        } else if (lbl_8053AED0[0xdc] & 0x10) {
            this_[0x25d] &= ~mask;
        } else if (*(s32*)(lbl_8053AAF8 + 0x4c) == 0xb) {
            this_[0x25d] &= ~mask;
        }
        if (lbl_8053AAF8[0x82] & mask) {
            fn_804253E0(this_, i);
            if ((lbl_8053AAF8[0x83] >> sh & 3U) == 1) {
                if (fn_8023DE58(i) >= 8) {
                    if (!(this_[0x258] & mask)) {
                        this_[0x258] |= (u8)bit;
                        GetHeart(*(u8**)(this_ + 0x18), *tv1)[0xb0] = 1;
                        GetHeart(*(u8**)(this_ + 4), *on1)[0xb0] = 1;
                        GetHeart(*(u8**)(this_ + 4), *off1)[0xb0] = 0;
                    }
                } else if (this_[0x258] & mask) {
                    this_[0x258] &= ~mask;
                    GetHeart(*(u8**)(this_ + 0x18), *tv1)[0xb0] = 0;
                    GetHeart(*(u8**)(this_ + 4), *on1)[0xb0] = 0;
                    GetHeart(*(u8**)(this_ + 4), *off1)[0xb0] = 1;
                }
            }
            fn_80423DF0(this_, i);
            if ((lbl_8053AAF8[0x83] >> sh & 3U) == 2) {
                if (!(this_[0x25a] & mask)) {
                    if (fn_8023BD70(i)) {
                        this_[0x25a] |= (u8)bit;
                        GetHeart(*(u8**)(this_ + 4), *on2)[0xb0] = 1;
                    }
                } else if ((u32)fn_80309D24(lbl_8053AD30, fn_8030AAF4(i), 0x100) == 0 || (this_[0x255] & mask)) {
                    this_[0x25a] &= ~mask;
                    GetHeart(*(u8**)(this_ + 4), *on2)[0xb0] = 0;
                }
            }
            if (this_[0x255] & mask) {
                v = counts[0x42];
                if (v > 0x180) {
                    v = 0x180;
                }
                if (v < 0) {
                    v = 0;
                }
                u64* key = bars;
                for (j = 0; j < 4; j++) {
                    if (v >= 0x60) {
                        u8* pane = GetHeart(*(u8**)(this_ + 4), *key);
                        ((HudResizePane*)GetHeart(*(u8**)(this_ + 4), *key))
                            ->resize(*(f32*)(this_ + 0xf4), *(f32*)(pane + 0x2c) - *(f32*)(pane + 0x24));
                        v -= 0x60;
                    } else {
                        u8* pane = GetHeart(*(u8**)(this_ + 4), *key);
                        ((HudResizePane*)GetHeart(*(u8**)(this_ + 4), *key))
                            ->resize(*(f32*)(this_ + 0xf4) * ((f32)v / lbl_80543A68), *(f32*)(pane + 0x2c) - *(f32*)(pane + 0x24));
                        v = 0;
                    }
                    key++;
                }
            }
            fn_80423248(this_, i);
            fn_80423804(this_, i);
        }
        tv1++;
        on1++;
        off1++;
        on2++;
        counts++;
        bars += 4;
        sh += 2;
    }

    fn_80422824(this_);
    {
        u8* fp = this_;
        s32 off = 0;
        for (i = 0; i < 4; i++) {
            fn_80424148(this_, i, 0);
            if ((*(u8**)(lbl_8053AB10 + 0x20))[i + 0x148] != 0) {
                s32 x = (s32)((J2DPane*)GetHeart(*(u8**)(this_ + 4), *pos))->getBounds()->i.x;
                s32 y = (s32)((J2DPane*)GetHeart(*(u8**)(this_ + 4), *pos))->getBounds()->i.y;
                u8* p = GetHeart(*(u8**)(this_ + 4), *pos);
                f32 w = *(f32*)(p + 0x28) - *(f32*)(p + 0x20);
                p = GetHeart(*(u8**)(this_ + 4), *pos);
                f32 h = *(f32*)(p + 0x2c) - *(f32*)(p + 0x24);
                u8* dst = *(u8**)(lbl_8053AB10 + 0x20) + off;
                *(s32*)(dst + 0x1d0) = x;
                *(s32*)(dst + 0x1d4) = y;
                *(s32*)(dst + 0x1d8) = (s32)w;
                *(s32*)(dst + 0x1dc) = (s32)h;
                if (i == 0 || i == 2) {
                    if (*(f32*)(fp + 0xf8) < lbl_80543A70) {
                        *(f32*)(fp + 0xf8) = *(f32*)(fp + 0xf8) + lbl_80543A74;
                    } else {
                        *(f32*)(fp + 0xf8) = lbl_80543A78;
                    }
                } else {
                    if (*(f32*)(fp + 0xf8) > lbl_80543A7C) {
                        *(f32*)(fp + 0xf8) = *(f32*)(fp + 0xf8) - lbl_80543A74;
                    } else {
                        *(f32*)(fp + 0xf8) = lbl_80543A80;
                    }
                }
            } else {
                if (i == 0 || i == 2) {
                    if (*(f32*)(fp + 0xf8) < lbl_80543A74) {
                        *(f32*)(fp + 0xf8) = lbl_80543A40;
                    } else {
                        *(f32*)(fp + 0xf8) = *(f32*)(fp + 0xf8) - lbl_80543A74;
                    }
                } else {
                    if (*(f32*)(fp + 0xf8) > lbl_80543A84) {
                        *(f32*)(fp + 0xf8) = lbl_80543A40;
                    } else {
                        *(f32*)(fp + 0xf8) = *(f32*)(fp + 0xf8) + lbl_80543A74;
                    }
                }
            }
            off += 0x10;
            fp += 4;
            pos++;
        }
    }

    for (i = 0; i < 4; i++) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
            fn_8042215C(this_, i);
            fn_80421D78(this_, i);
        }
    }
    for (i = 0; i < 4; i++) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
            fn_80421A34(this_, i, 0);
        }
    }
    fn_80441490(*(void**)(this_ + 0xf0));
    this_[0x255] = 0;
    this_[0x256] = 0;
    this_[0x257] = 0;
}

extern "C" void fn_80425F24(u8* this_) {
    fn_8013B490(lbl_8053AB10);
    (*(J2DScreen**)(this_ + 0x18))->draw(lbl_80543A40, lbl_80543A40, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern u8* sManager__8JUTVideo;
extern const f32 lbl_80543A58;
extern const f32 lbl_80543A88;
extern const f32 lbl_80543A8C;
extern "C" void fn_8044148C(void*);
#pragma fp_contract off
extern "C" void fn_80425F6C(u8* self) {
    f32 right;
    f32 bottom;
    f32 width;
    f32 height;
    JGeometry::TVec3<f32> point;
    u8* settings = lbl_8050DB0C;
    u8* states = lbl_8050EC80;
    u8* halfwords = self;
    u8* screens = self;
    s32 i;
    u8* video = *(u8**)(sManager__8JUTVideo + 4);
    f32 pixelWidth = (f32)(s32)*(u16*)(video + 4);
    f32 pixelHeight = (f32)(s32)*(u16*)(video + 6);
    f32 scale = *(f32*)(*(u8**)(lbl_8053AB10 + 0x24) + 0x858);
    f32 factor = *(f32*)(settings + 0x40);
    width = factor * (pixelWidth / scale);
    height = factor * (pixelHeight / scale);
    right = lbl_80543A40 + width;
    bottom = lbl_80543A40 + height;
    for (i = 0; i < 4; ++i) {
        if ((lbl_8053AAF8[0x82] & (u8)(1 << i)) != 0 &&
            fn_8023DE58(fn_8022EA0C(i)) < 8) {
            if (*(s16*)(halfwords + 0x1e8) > 0 && ((HudPlayerState*)lbl_8050EC80)[*(s32*)(states + 0x10)].visible != 0) {
                fn_8030C5F0(*(void**)(lbl_8053AB10 + 0x24), fn_8023E724(fn_8022EA0C(i)), 0, 0, &point.x);
                video = *(u8**)(sManager__8JUTVideo + 4);
                J2DOrthoGraph* graph = *(J2DOrthoGraph**)(self + 0x4c);
                f32 y = (f32)*(s16*)(settings + 0x4e) + ((f32)(height * (point.y / (f32)(s32)*(u16*)(video + 6))) - (f32)(s32)*(u16*)(video + 6) * lbl_80543A58);
                f32 x = (f32)(width * (point.x / (f32)(s32)*(u16*)(video + 4))) - (f32)(s32)*(u16*)(video + 4) * lbl_80543A58;
                JGeometry::TBox2<f32> box(lbl_80543A40, lbl_80543A40, right, bottom);
                graph->setOrtho(box, lbl_80543A88, lbl_80543A8C);
                (*(J2DOrthoGraph**)(self + 0x4c))->setPort();
                (*(J2DScreen**)(screens + 8))->draw(x, y, (J2DGrafContext*)*(void**)(self + 0x4c));
                *(s16*)(halfwords + 0x208) = 0;
            } else {
                bool blocked;
                if (*(s32*)(lbl_8053AAF8 + 0x4c) == 0xb) blocked = true;
                else blocked = lbl_8053AAF8[0x88] == 2;
                if (!blocked &&
                    ((s32(*)(s32))fn_802366CC)(fn_8022EA0C(i)) > 0 &&
                    ((s32(*)(s32))fn_802366CC)(fn_8022EA0C(i)) < 300) {
                    fn_8030C5F0(*(void**)(lbl_8053AB10 + 0x24), fn_8023E724(fn_8022EA0C(i)), 0, 0, &point.x);
                    video = *(u8**)(sManager__8JUTVideo + 4);
                J2DOrthoGraph* graph = *(J2DOrthoGraph**)(self + 0x4c);
                    f32 y = (f32)*(s16*)(settings + 0x4e) + ((f32)(height * (point.y / (f32)(s32)*(u16*)(video + 6))) - (f32)(s32)*(u16*)(video + 6) * lbl_80543A58);
                    f32 x = (f32)(width * (point.x / (f32)(s32)*(u16*)(video + 4))) - (f32)(s32)*(u16*)(video + 4) * lbl_80543A58;
                    JGeometry::TBox2<f32> box(lbl_80543A40, lbl_80543A40, right, bottom);
                    graph->setOrtho(box, lbl_80543A88, lbl_80543A8C);
                    (*(J2DOrthoGraph**)(self + 0x4c))->setPort();
                    (*(J2DScreen**)(screens + 0x2c))->draw(x, y, (J2DGrafContext*)*(void**)(self + 0x4c));
                }
            }
        }
        halfwords += 2;
        screens += 4;
    }
    fn_8013B490(lbl_8053AB10);
    (*(J2DScreen**)(self + 4))->draw(lbl_80543A40, lbl_80543A40, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
    fn_8044148C(*(void**)(self + 0xf0));
}
#pragma opt_propagation off
extern "C" void fn_804263A8(u8* this_) {
    u8* config = lbl_80529DEC;
    const u8* base = lbl_8048E1B8;
    u8* words = this_;
    u8* halves = this_;
    const u64* key1;
    const u64* key0;
    const u64* key2;
    const u64* key3;
    const u64* key4;
    const u64* key5;
    const u64* key6;
    s32 shift;
    const u64* key7;
    const u64* key8;
    const u64* key9;
    const u64* firstKeys;
    s32 i;
    u8* saves;
    for (i = 0; i < 4; i++, words += 4, halves += 2, config += 4) {
        u8 mask;
        u8* controller;
        u8* game = lbl_8053AAF8;
        mask = 1 << i;
        BOOL active = (game[0x82] & mask) != 0;
        if (!active) {
            this_[0x25d] &= ~mask;
        } else {
            controller = lbl_8053AED0;
            BOOL changed = (controller[0xdd] & mask) != 0;
            if (changed && !(this_[0x25c] & mask)) {
                this_[0x25c] |= mask;
                this_[0x25d] |= mask;
            } else if (controller[0xdc] & 0x10) {
                this_[0x25d] &= ~mask;
            } else if (*(s32*)(game + 0x4c) == 0xb) {
                this_[0x25d] &= ~mask;
            }
        }

        *(u32*)(config + 0xd8) = fn_80237774(i);
        *(u32*)(config + 0xe8) = fn_80236100(i);
        *(u32*)(config + 0x108) = fn_802375B0(i);
        *(s32*)(words + 0x158) = 0x180;
        *(s32*)(words + 0x168) = 0;
        *(s32*)(words + 0x178) = 0;
        *(s32*)(words + 0x188) = 0;
        *(f32*)(words + 0xf8) = lbl_80543A40;
        *(f32*)(words + 0x108) = lbl_80543A40;
        *(f32*)(words + 0x118) = lbl_80543A40;
        *(f32*)(words + 0x128) = lbl_80543A40;
        *(f32*)(words + 0x138) = lbl_80543A40;
        this_[0x251 + i] = i;
        this_[0x24d + i] = 0xff;
        *(u16*)(halves + 0x1f0) = 0;
        *(s32*)(words + 0x198) = 0;
        *(s32*)(words + 0x1a8) = 0;
        *(s32*)(words + 0x1b8) = 0;
        *(s32*)(words + 0x1c8) = 0;
        *(u16*)(halves + 0x1e8) = 0;
        *(u16*)(halves + 0x1f8) = 0;
        *(u16*)(halves + 0x200) = 0;
        *(s32*)(words + 0x1d8) = 0;
        *(u16*)(halves + 0x208) = 0;
    }

    for (i = 0; i < 4; i++) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
            fn_80421A34(this_, i, 1);
        }
    }

    this_[0x255] = 0xf;
    firstKeys = (const u64*)(base + 0xd68);
    shift = 0;
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

    saves = lbl_8050EC80;
    key0 = firstKeys;
    key1 = (const u64*)(base + 0xda8);
    key2 = (const u64*)(base + 0xdc8);
    key3 = (const u64*)(base + 0xde8);
    key4 = (const u64*)(base + 0xe28);
    key5 = (const u64*)(base + 0xe68);
    key6 = (const u64*)(base + 0xe88);
    key7 = (const u64*)(base + 0xe08);
    key8 = (const u64*)(base + 0xea8);
    key9 = (const u64*)(base + 0xec8);
    for (i = 0; i < 4; i++, ++key0, ++key1, ++key2, ++key3, ++key4, ++key5, ++key6, ++key7, ++key8, ++key9, shift += 2) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
            ((u8*)GetHeart(*(u8**)(this_ + 0x18), *key0))[0xb0] = 0;
            ((u8*)GetHeart(*(u8**)(this_ + 0x18), *key1))[0xb0] = 0;
            ((u8*)GetHeart(*(u8**)(this_ + 4), *key2))[0xb0] = 0;
            ((u8*)GetHeart(*(u8**)(this_ + 4), *key3))[0xb0] = 1;
            ((u8*)GetHeart(*(u8**)(this_ + 4), *key4))[0xb0] = 0;
            ((u8*)GetHeart(*(u8**)(this_ + 4), *key5))[0xb0] = 1;
            if (lbl_8050EC80[*(s32*)(saves + 0x10) * 0xc8 + 0x89] != 0) {
                ((u8*)GetHeart(*(u8**)(this_ + 4), *key6))[0xb0] = 1;
            } else {
                ((u8*)GetHeart(*(u8**)(this_ + 4), *key6))[0xb0] = 0;
            }
            if (((u32)((s32)lbl_8053AAF8[0x83] >> shift) & 3) == 2) {
                ((u8*)GetHeart(*(u8**)(this_ + 4), *key7))[0xb0] = 1;
                ((u8*)GetHeart(*(u8**)(this_ + 4), *key8))[0xb0] = 1;
                ((u8*)GetHeart(*(u8**)(this_ + 4), *key9))[0xb0] = 0;
            } else {
                ((u8*)GetHeart(*(u8**)(this_ + 4), *key7))[0xb0] = 0;
                ((u8*)GetHeart(*(u8**)(this_ + 4), *key8))[0xb0] = 0;
                ((u8*)GetHeart(*(u8**)(this_ + 4), *key9))[0xb0] = 0;
            }
        } else {
            ((u8*)GetHeart(*(u8**)(this_ + 0x18), *key0))[0xb0] = 0;
            ((u8*)GetHeart(*(u8**)(this_ + 0x18), *key1))[0xb0] = 0;
            ((u8*)GetHeart(*(u8**)(this_ + 4), *key2))[0xb0] = 0;
            ((u8*)GetHeart(*(u8**)(this_ + 4), *key3))[0xb0] = 0;
            ((u8*)GetHeart(*(u8**)(this_ + 4), *key7))[0xb0] = 0;
            ((u8*)GetHeart(*(u8**)(this_ + 4), *key4))[0xb0] = 0;
            ((u8*)GetHeart(*(u8**)(this_ + 4), *key5))[0xb0] = 0;
            ((u8*)GetHeart(*(u8**)(this_ + 4), *key6))[0xb0] = 0;
            ((u8*)GetHeart(*(u8**)(this_ + 4), *key8))[0xb0] = 0;
            ((u8*)GetHeart(*(u8**)(this_ + 4), *key9))[0xb0] = 0;
        }
    }

    {
        const u64* otherKeys = (const u64*)(base + 0xd88);
        for (i = 0; i < 4; ++i, ++firstKeys, ++otherKeys) {
            u32 tag = fn_804030C4(0x54494D47, lbl_804B145C[0]);
            ((TimerPicture*)(*(HeartPane**)(this_ + 0x18))->search(*firstKeys))->changeTexture(tag, 0);
            ((TimerPicture*)(*(HeartPane**)(this_ + 0x18))->search(*otherKeys))->changeTexture(tag, 0);
        }
    }

    for (i = 0; i < 4; i++) {
        if (lbl_8053AAF8[0x82] & (u8)(1 << i)) {
            fn_80424148(this_, i, 1);
        }
    }
    fn_8044172C(*(void**)(this_ + 0xf0));
}
#pragma opt_propagation reset
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
