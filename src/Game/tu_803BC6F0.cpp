#include "types.h"
#include "JSystem/J2D/J2DPane.h"
#include "dolphin/os/OSTime.h"
#include "JSystem/J2D/J2DPicture.h"
#include "Game/FsaVObj.h"

struct Tu803CE9ECObj {
    virtual void v0();
};
typedef void (Tu803CE9ECObj::*Tu803CE9ECFn)();
extern Tu803CE9ECFn lbl_804AFD70[];

struct MenuSlots38 {
    u8 pad0[0x38];
    u8* slot[3];
};

struct MenuSlots44 {
    u8 pad0[0x44];
    u8* slot[3];
};

static inline void addMenuTiming(s32& total, s32 value) { total = value + total; }

static inline f32 menuPulseSquare(s32 value) { return (f32)(value * value); }

struct MenuSlots24 {
    u8 pad0[0x24];
    u8* slot[2];
};

struct Tu803Blk {
    u32 w[0x78];
};

struct VtSlot9 {
    void* v0;
    void* v1;
    void* v2;
    void* v3;
    void* v4;
    void* v5;
    void* v6;
    void* v7;
    void* v8;
    void (*v9)(void* a, s32 b);
};

extern "C" void* lbl_8053AD30;
extern "C" void* lbl_8053AF80;
extern "C" u32 fn_80309C4C(void* a, u32 b, int c);
extern "C" void fn_80458880(void* a, int b, int c);
extern "C" void fn_803C0018(char* p);


extern "C" void OSResetSystem(int reset, unsigned long resetCode, int forceMenu);
extern "C" u32 fn_80309A9C(void* a, u32 b, int c);
extern "C" void fn_803C05D8(u8* p);
extern "C" void fn_8040245C(void* a, s32 b, s32 c, u8 d, s32 e);
extern "C" f32 lbl_80543458;

extern "C" char lbl_804AFF60[];
extern "C" char lbl_80529DEC[];
extern "C" u32 lbl_8053ADB0;
extern "C" u32 getTotalFreeSize__7JKRHeapFv(void* heap);
extern "C" void __dl__FPv(void* p);

struct DtorVt {
    void* v0;
    void* v1;
    void (*v2)(void* a, s32 b);
    void (*v3)(void* a);
};

struct DtorBase {
    virtual void del(s32 b) = 0;
    virtual void v1() = 0;
};

static inline void releaseSlot(void* obj) {
    if (obj != 0) {
        ((DtorBase*)obj)->del(1);
    }
}

struct J2DTextBoxVt {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(u32 a);
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void* v15(u32 a, u32 b, u32 c);
};
extern "C" char lbl_8051C1A0[];
extern "C" char lbl_8050EC80[];
extern "C" u8* lbl_8053AAF8;
extern "C" int fn_803B9A94(void* a, u32 b, int c, u32 d, int e, int f);
extern "C" void fn_803C24BC(char* p);
extern "C" s32 fn_803B9BDC(char* this_);
extern "C" void fn_803BF004(char* this_);
extern "C" void fn_803B93E8(void* a, void* b, void* c, s32 d);
extern "C" void fn_803BACF8(void* a, u8 b);
extern "C" const u64 lbl_80476938[];
extern "C" u32 lbl_80476980[];
extern "C" f32 lbl_80543458;
extern "C" f32 lbl_80543498;
extern "C" f32* getBounds__7J2DPaneFv(void* this_);
extern "C" u32 fn_803B9940(void* a, s32 b);
extern "C" u8 fn_803B90E4(u32 a, s32 b);
extern "C" u8 fn_803B8CAC(u32 a, s32 b);
extern "C" void fn_803B9B8C(void* a);
extern "C" void fn_80402B10(void* a, s16 b, u8 c, f32 d);
extern "C" s32 fn_803B933C(void* unused, void* slots, s32 idx);
extern "C" void fn_803B9CCC(char* this_, void* src, u32 len, s32 offset);
static inline void setFade(void* a, s16 b, s32 c, f32 d, f32 e) {
    ((void (*)(void*, s16, s32, f32, f32))fn_80402B10)(a, b, c, d, e);
}
extern "C" void fn_80402628(void* a, s16 b, u8 c, s32 d);
extern "C" void fn_804023D0(void* a, void* b, u8 c);
extern "C" void fn_803B9D54(void* a, void* b, u32 c, void* d, u32 e, s32 f);
extern "C" s32 CARDGetSerialNo(s32 chan, u64* serial);
extern "C" void fn_803CE4CC(char* p);
extern "C" void fn_80402E08(void* a, f32 b, f32 c);
extern "C" char* getStringPtr__10J2DTextBoxCFv(void* this_);
extern "C" f32 lbl_80543494;
extern "C" void fn_803832BC(char* a, s32 b, int c, int d, int e);
extern "C" const u8 lbl_804765D0[];
extern "C" u8 lbl_8050DB0C[];
extern "C" f32 lbl_8054349C;
extern "C" void fn_803BC6F0(char* this_, u32 a, f32 t);
extern "C" f32 lbl_80543478;
extern "C" f32 lbl_805434A0;
extern "C" f32 lbl_8054345C;
extern "C" u8 fn_80402940(void* p, s32 id, f32 a, f32 b, s32 c);

static inline s32 getFileIcon(u32 slot, const u8* base = lbl_804765D0) {
    u32 k = 0;
    s32 j;
    for (j = 0; j < 8; j++) {
        if (fn_803B8CAC(slot, j)) {
            k++;
        } else {
            return ((const s32*)(base + 0x730))[k];
        }
    }
    return ((const s32*)(base + 0x730))[7];
}

static inline void startObj(char* this_, s32 off) {
    f32 d = *(f32*)(*(char**)(this_ + 0x3c) + 0xc) - *(f32*)(*(char**)(this_ + 0x38) + 0xc);
    fn_80402E08(*(void**)(this_ + off), lbl_80543458, d);
    setFade(*(void**)(this_ + off), *(s16*)(lbl_8050DB0C + 0x1ba), 0, lbl_80543458, lbl_80543498);
    fn_80402628(*(void**)(this_ + off), *(s16*)(lbl_8050DB0C + 0x1ba), *(u8*)(*(char**)(this_ + off) + 0x28), 0);
}

static inline BOOL isTimeSet(s64 t) {
    BOOL r = FALSE;
    if (t != 0) {
        r = TRUE;
    }
    return r;
}

struct KeyObjVt {
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
    virtual void v13();
    virtual void v14();
    virtual void* v15(u32 a, u64 b);
};

struct PaneObjVt {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(s32 b);
};

struct Clr {
    u8 r, g, b, a;
};

struct ColorVt {
    void* v[15];
    void* (*v15)(void* self, u32 a, u64 b);
    void* v16[60];
    void (*v76)(void* self, void* a, void* b);
};

struct TextBoxVt15 {
    void* v[15];
    void* (*v15)(void* a, u64 b);
};

typedef void* (*KeyGetFn)(void* self, u64 key);
typedef void (*Fn5Fn)(void* a, s16 b, s32 c, f32 d, f32 e);

// Virtual slot 15 of this_+8 maps a u64 key from the lbl_804765D0 table to an object, which is set on this_[cell+idx*4].
static inline u8* menuSlot(char* p, const s32 index) {
    char* selected = p;
    selected += index * 4;
    return *(u8**)(selected + 0x38);
}

static inline void setCell(u8* this_, s32 cell, s32 idx, s32 keyOff, u8 flag) {
    u8* sub = *(u8**)(this_ + 8);
    void* o = ((KeyGetFn)(*(void***)sub)[15])(sub, *(u64*)(lbl_804765D0 + keyOff + idx * 8));
    fn_804023D0(*(void**)(this_ + cell + idx * 4), o, flag);
}

static inline void setCellT(u8* this_, u8* tbl, s32 cell, s32 idx, s32 keyOff, u8 flag) {
    u8* sub = *(u8**)(this_ + 8);
    void* o = ((KeyGetFn)(*(void***)sub)[15])(sub, *(u64*)(tbl + keyOff + idx * 8));
    fn_804023D0(*(void**)(this_ + cell + idx * 4), o, flag);
}

static inline void setCellU(u8* this_, u8* tbl, s32 keyOff, s32 flagOff) {
    s32 idx = *(s32*)(this_ + 0xa4);
    u8* sub = *(u8**)(this_ + 8);
    void* o = ((KeyGetFn)(*(void***)sub)[15])(sub, *(u64*)(tbl + keyOff + idx * 8));
    fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), o, *(u8*)(this_ + flagOff));
}

static inline void drawTextRow(u8* p, u8* q, u8* t) {
    s32 k;
    for (k = 0; k < 4; k++) {
        void* object = *(void**)(p + 0x8);
        void* s = ((J2DPane*)object)->search(*(u64*)t);
        fn_804023D0(*(void**)(q + 0x24), s, p[k + 0x19f]);
        t += 8;
    }
}

// Keyed loop: each entry's key from the lbl_804765D0 table feeds the virtual call on p+recvOff, then fn_804023D0 sets target.
static inline void setKeyed(u8* p, s32 recvOff, void* target, u8* keys, s32 n, s32 flagOff) {
    s32 i;
    for (i = 0; i < n; i++) {
        void* s = ((TextBoxVt15*)*(void**)(p + recvOff))->v15(*(void**)(p + recvOff), *(u64*)(keys + i * 8));
        fn_804023D0(target, s, p[i + flagOff]);
    }
}

struct Obj9 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v9(s32 b);
};

struct Vt15x3 {
    void* v[15];
    void* (*v15)(void* self, u32 a, u32 b, u32 c);
};

static inline void* callVt3(u8* p, u32 a, u32 b, u32 c) {
    void* obj = *(void**)(p + 8);
    return (*(Vt15x3**)obj)->v15(obj, a, b, c);
}

static inline void setKeyedAt(u8* p, s32 recvOff, s32 tgtOff, u8* keys, s32 n, s32 flagOff) {
    u8* k = keys;
    s32 i;
    for (i = 0; i < n; i++, k += 8) {
        void* object = *(void**)(p + recvOff);
        void* s = ((J2DPane*)object)->search(*(u64*)k);
        fn_804023D0(*(void**)(p + tgtOff), s, p[i + flagOff]);
    }
}

static inline void setKeyedB(u8* p, s32 recvOff, s32 tgtOff, u8* keys, s32 n, s32 flagOff) {
    s32 i;
    u8* k = keys;
    for (i = 0; i < n; i++, k += 8) {
        u64 key = *(u64*)k;
        void* s = ((TextBoxVt15*)*(void**)(p + recvOff))->v15(*(void**)(p + recvOff), key);
        fn_804023D0(*(void**)(p + tgtOff), s, p[i + flagOff]);
    }
}

struct PaneVt9 {
    void* v0;
    void* v1;
    void* v2;
    void* v3;
    void* v4;
    void* v5;
    void* v6;
    void* v7;
    void* v8;
    void (*v9)(void* a, s32 b);
};

struct PaneVirtVt {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(s32 b);
};

static inline void stopPane(void* obj) {
    ((PaneVirtVt*)obj)->v9(0);
}

struct KeyLookupVt {
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
    virtual void v13();
    virtual void v14();
    virtual void* v15(u64 key);
};

static inline void* keyObj(void* obj, u64 key) {
    return ((KeyLookupVt*)obj)->v15(key);
}

static inline void tu803C_setCell(u8* this_, s32 cell, s32 idx, s32 keyOff, s32 flagOff) {
    void* o = keyObj(*(void**)(this_ + 8), *(u64*)(lbl_804765D0 + keyOff + idx * 8));
    fn_804023D0(*(void**)(this_ + cell + idx * 4), o, this_[flagOff]);
}

static inline void tu803C_setCell2(u8* this_, u8* base, s32 cell, s32 idx, s32 keyOff, s32 flagOff) {
    void* o = keyObj(*(void**)(this_ + 8), *(u64*)(base + keyOff + idx * 8));
    fn_804023D0(*(void**)(this_ + idx * 4 + cell), o, this_[flagOff]);
}

static inline void tu803C_max(s32* m, s32 v) {
    if (*m < v) {
        *m = v;
    }
}

static inline void initPane(void* obj) {
    fn_80402E08(obj, lbl_80543458, lbl_80543458);
    *(s16*)((u8*)obj + 0x22) = 0;
    stopPane(*(void**)((u8*)obj + 4));
}
extern "C" void fn_80402E08(void* state, f32 x, f32 y);
#pragma dont_inline on
void fn_803BC6F0(char* this_, u32 a, f32 t) {
    f32 k = t;
    if (k > lbl_80543478) {
        k = lbl_80543478;
    }
    if (k < lbl_80543458) {
        k = lbl_80543458;
    }
    u32* vt = (u32*)this_;
    (void)vt;
    (void)a;
}
#pragma dont_inline reset

static inline void setPicBlackWhite(u8* p, const u8* keys, u32 idx, JUtility::TColor black, JUtility::TColor white) {
    ((J2DPicture*)((J2DPane*)*(void**)(p + 8))->search(((const u64*)keys)[idx]))->setBlackWhite(black, white);
}

extern "C" void fn_803BD5E0(u8* p, u32 idx) {
    u8* base = (u8*)lbl_804765D0;
    u32 off = idx * 8;
    void* r;
    Clr a;
    a.r = 0x80; a.g = 0x80; a.b = 0x80; a.a = 0xff;
    Clr b;
    b.r = 0; b.g = 0; b.b = 0; b.a = 0;
    {
        Clr a2 = a;
        Clr b2 = b;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), idx, *(u64*)(base + 0x5d8 + off));
        (*(ColorVt**)r)->v76(r, &b2, &a2);
    }
    Clr c;
    c.r = 0xb4; c.g = 0xb4; c.b = 0xb4; c.a = 0xff;
    Clr d;
    d.r = 0x82; d.g = 0x82; d.b = 0x82; d.a = 0x00;
    {
        Clr d2 = d;
        Clr c2 = c;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&d, *(u64*)(base + 0x5c0 + off));
        (*(ColorVt**)r)->v76(r, &d2, &c2);
    }
    {
        Clr d3 = d;
        Clr c3 = c;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&c, *(u64*)(base + 0x5a8 + off));
        (*(ColorVt**)r)->v76(r, &d3, &c3);
    }
    {
        Clr d4 = d;
        Clr c4 = c;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&c, *(u64*)(base + 0x590 + off));
        (*(ColorVt**)r)->v76(r, &d4, &c4);
    }
    {
        Clr d5 = d;
        Clr c5 = c;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&c, *(u64*)(base + 0x578 + off));
        (*(ColorVt**)r)->v76(r, &d5, &c5);
    }
    {
        Clr n;
        n.r = d.r; n.g = d.g; n.b = d.b; n.a = 0xff;
        Clr n2 = n;
        Clr c6 = c;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), d.b, *(u64*)(base + 0x560 + off));
        (*(ColorVt**)r)->v76(r, &n2, &c6);
    }
    Clr g;
    g.r = 0x50; g.g = 0x50; g.b = 0x50; g.a = 0x00;
    Clr f;
    f.r = 0x80; f.g = 0x80; f.b = 0x80; f.a = 0xff;
    {
        Clr g2 = g;
        Clr f2 = f;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), 0, *(u64*)(base + 0x548 + off));
        (*(ColorVt**)r)->v76(r, &g2, &f2);
    }
    {
        Clr g3 = g;
        Clr f3 = f;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&f, *(u64*)(base + 0x530 + off));
        (*(ColorVt**)r)->v76(r, &g3, &f3);
    }
    {
        Clr g4 = g;
        Clr f4 = f;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&f, *(u64*)(base + 0x518 + off));
        (*(ColorVt**)r)->v76(r, &g4, &f4);
    }
    {
        Clr g5 = g;
        Clr f5 = f;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&f, *(u64*)(base + 0x500 + off));
        (*(ColorVt**)r)->v76(r, &g5, &f5);
    }
    {
        Clr g6 = g;
        Clr f6 = f;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&f, *(u64*)(base + 0x4e8 + off));
        (*(ColorVt**)r)->v76(r, &g6, &f6);
    }
    Clr h;
    h.r = 0x82; h.g = 0x82; h.b = 0x82; h.a = 0xff;
    Clr i;
    i.r = 0x64; i.g = 0x64; i.b = 0x64; i.a = 0x00;
    {
        Clr i2 = i;
        Clr h2 = h;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&i, *(u64*)(base + 0x6c8 + off));
        (*(ColorVt**)r)->v76(r, &i2, &h2);
    }
    {
        Clr i3 = i;
        Clr h3 = h;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&h, *(u64*)(base + 0x6b0 + off));
        (*(ColorVt**)r)->v76(r, &i3, &h3);
    }
    {
        Clr i4 = i;
        Clr h4 = h;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&h, *(u64*)(base + 0x698 + off));
        (*(ColorVt**)r)->v76(r, &i4, &h4);
    }
    {
        Clr i5 = i;
        Clr h5 = h;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&h, *(u64*)(base + 0x680 + off));
        (*(ColorVt**)r)->v76(r, &i5, &h5);
    }
    {
        Clr n3;
        n3.r = i.r; n3.g = i.g; n3.b = i.b; n3.a = 0xff;
        Clr n4 = n3;
        Clr h6 = h;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), i.b, *(u64*)(base + 0x668 + off));
        (*(ColorVt**)r)->v76(r, &n4, &h6);
    }
    Clr j;
    j.r = 0xb4; j.g = 0xb4; j.b = 0xb4; j.a = 0xff;
    Clr k;
    k.r = 0xb4; k.g = 0xb4; k.b = 0xb4; k.a = 0x00;
    {
        Clr k2 = k;
        Clr j2 = j;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), 0, *(u64*)(base + 0x650 + off));
        (*(ColorVt**)r)->v76(r, &k2, &j2);
    }
    {
        Clr k3 = k;
        Clr j3 = j;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&j, *(u64*)(base + 0x638 + off));
        (*(ColorVt**)r)->v76(r, &k3, &j3);
    }
    {
        Clr k4 = k;
        Clr j4 = j;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&j, *(u64*)(base + 0x620 + off));
        (*(ColorVt**)r)->v76(r, &k4, &j4);
    }
    {
        Clr k5 = k;
        Clr j5 = j;
        r = (*(ColorVt**)*(void**)(p + 0x8))->v15(*(void**)(p + 0x8), *(u32*)&j, *(u64*)(base + 0x608 + off));
        (*(ColorVt**)r)->v76(r, &k5, &j5);
    }
}

// Finds the picture keyed by key[idx] on p+8 and sets its black/white colors.
static inline void setPictureBlackWhite(u8* p, const u64* key, s32 idx, Clr black, Clr white) {
    FsaVObj* r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
    r->v76((u32*)&black, (u32*)&white);
}

#pragma opt_propagation off
extern "C" void fn_803BDD44(u8* p, s32 idx) {
    const u8* table = lbl_804765D0;
    FsaVObj* r;
    {
        Clr w = *(Clr*)(p + 0xe8);
        Clr b = *(Clr*)(p + 0xfc);
        const u64* key = (const u64*)(table + 0x5d8);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&b, (u32*)&w);
    }
    Clr c = *(Clr*)(p + 0xec);
    Clr d = *(Clr*)(p + 0x100);
    {
        Clr c2 = c;
        Clr d2 = d;
        const u64* key = (const u64*)(table + 0x5c0);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&d2, (u32*)&c2);
    }
    {
        Clr c2 = c;
        Clr d2 = d;
        const u64* key = (const u64*)(table + 0x5a8);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&d2, (u32*)&c2);
    }
    {
        Clr c2 = c;
        Clr d2 = d;
        const u64* key = (const u64*)(table + 0x590);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&d2, (u32*)&c2);
    }
    {
        Clr c2 = c;
        Clr d2 = d;
        const u64* key = (const u64*)(table + 0x578);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&d2, (u32*)&c2);
    }
    {
        Clr n;
        n.r = d.r; n.g = d.g; n.b = d.b; n.a = 0xff;
        Clr c2 = c;
        Clr n2 = n;
        const u64* key = (const u64*)(table + 0x560);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&n2, (u32*)&c2);
    }
    Clr e = *(Clr*)(p + 0xf0);
    Clr f = *(Clr*)(p + 0x104);
    {
        Clr e2 = e;
        Clr f2 = f;
        const u64* key = (const u64*)(table + 0x548);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&f2, (u32*)&e2);
    }
    {
        Clr e2 = e;
        Clr f2 = f;
        const u64* key = (const u64*)(table + 0x530);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&f2, (u32*)&e2);
    }
    {
        Clr e2 = e;
        Clr f2 = f;
        const u64* key = (const u64*)(table + 0x518);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&f2, (u32*)&e2);
    }
    {
        Clr e2 = e;
        Clr f2 = f;
        const u64* key = (const u64*)(table + 0x500);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&f2, (u32*)&e2);
    }
    {
        Clr e2 = e;
        Clr f2 = f;
        const u64* key = (const u64*)(table + 0x4e8);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&f2, (u32*)&e2);
    }
    Clr g = *(Clr*)(p + 0xf4);
    Clr h = *(Clr*)(p + 0x108);
    {
        Clr g2 = g;
        Clr h2 = h;
        const u64* key = (const u64*)(table + 0x6c8);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&h2, (u32*)&g2);
    }
    {
        Clr g2 = g;
        Clr h2 = h;
        const u64* key = (const u64*)(table + 0x6b0);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&h2, (u32*)&g2);
    }
    {
        Clr g2 = g;
        Clr h2 = h;
        const u64* key = (const u64*)(table + 0x698);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&h2, (u32*)&g2);
    }
    {
        Clr g2 = g;
        Clr h2 = h;
        const u64* key = (const u64*)(table + 0x680);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&h2, (u32*)&g2);
    }
    {
        Clr n;
        n.r = h.r; n.g = h.g; n.b = h.b; n.a = 0xff;
        Clr g2 = g;
        Clr n2 = n;
        const u64* key = (const u64*)(table + 0x668);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&n2, (u32*)&g2);
    }
    Clr i = *(Clr*)(p + 0xf8);
    Clr j = *(Clr*)(p + 0x10c);
    {
        Clr i2 = i;
        Clr j2 = j;
        const u64* key = (const u64*)(table + 0x650);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&j2, (u32*)&i2);
    }
    {
        Clr i2 = i;
        Clr j2 = j;
        const u64* key = (const u64*)(table + 0x638);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&j2, (u32*)&i2);
    }
    {
        Clr i2 = i;
        Clr j2 = j;
        const u64* key = (const u64*)(table + 0x620);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&j2, (u32*)&i2);
    }
    {
        Clr i2 = i;
        Clr j2 = j;
        const u64* key = (const u64*)(table + 0x608);
        r = (FsaVObj*)((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        r->v76((u32*)&j2, (u32*)&i2);
    }
}
#pragma opt_propagation reset

#pragma dont_inline on
extern "C" void fn_803BE3D8(void* a) {
    char* this_ = (char*)a;
    s16 cnt;
    u8 tbl[0x10];
    s32 i;
    *(s16*)(this_ + 0xdc) += 1;
    cnt = *(s16*)(this_ + 0xdc);
    if (cnt < 0x36) {
        return;
    }
    *(s16*)(this_ + 0xdc) = 0;
    if (*(u32*)(this_ + 0xd0) == 0) {
        return;
    }
    for (i = 0; i < 0x10; i++) {
        tbl[i] = (u8)i;
    }
}
#pragma dont_inline reset
#pragma dont_inline reset

#pragma opt_propagation off
extern "C" void fn_803BF004(char* p) {
    char* selected;
    s32 idx;
    const u8* table = lbl_804765D0;
    f32 zero = 0.0f;
    *(s16*)(*(u8**)(p + 0x20) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x20) + 0x26) = 0;
    f32 delta = *(f32*)(*(u8**)(p + 0x38) + 0xc) - *(f32*)(menuSlot(p, *(s32*)(p + 0xa4)) + 0xc);
    fn_80402E08(menuSlot(p, *(s32*)(p + 0xa4)), zero, delta);
    {
        char* q = p;
        q += *(s32*)(p + 0xa4) * 4;
        *(s16*)(*(u8**)(q + 0x38) + 0x22) = 0;
        q = p;
        q += *(s32*)(p + 0xa4) * 4;
        *(s16*)(*(u8**)(q + 0x38) + 0x26) = 0;
    }
    ((J2DPane*)*(void**)(menuSlot(p, *(s32*)(p + 0xa4)) + 4))->setAlpha(*(u8*)(menuSlot(p, *(s32*)(p + 0xa4)) + 0x28));
    idx = *(s32*)(p + 0xa4);
    {
        const u64* key = (const u64*)(table + 0x780);
        void* found = ((J2DPane*)*(void**)(p + 8))->search(key[idx]);
        selected = p;
        selected += idx * 4;
        fn_804023D0(*(void**)(selected + 0x38), found, *(u8*)(p + 0x125));
    }
    {
        const u64* key = (const u64*)(table + 0x768);
        fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), *(u8*)(p + 0x126));
    }
    {
        const u64* key = (const u64*)(table + 0x750);
        fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), *(u8*)(p + 0x127));
    }
    {
        const u64* key = (const u64*)(table + 0x6c8);
        fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), *(u8*)(p + 0x128));
    }
    {
        const u64* key = (const u64*)(table + 0x6b0);
        fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), *(u8*)(p + 0x129));
    }
    {
        const u64* key = (const u64*)(table + 0x698);
        fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), *(u8*)(p + 0x12a));
    }
    {
        const u64* key = (const u64*)(table + 0x680);
        fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), *(u8*)(p + 0x12b));
    }
    {
        const u64* key = (const u64*)(table + 0x668);
        fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), *(u8*)(p + 0x12c));
    }
    {
        const u64* key = (const u64*)(table + 0x650);
        fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), *(u8*)(p + 0x12d));
    }
    {
        const u64* key = (const u64*)(table + 0x638);
        fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), *(u8*)(p + 0x12e));
    }
    {
        const u64* key = (const u64*)(table + 0x620);
        fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), *(u8*)(p + 0x12f));
    }
    {
        const u64* key = (const u64*)(table + 0x608);
        fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), *(u8*)(p + 0x130));
    }
    {
        const u64* key = (const u64*)(table + 0x5f0);
        fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), *(u8*)(p + 0x131));
    }
    *(s16*)(p + 0xd8) = 0;
    *(s16*)(p + 0xda) = 0;
    p[0x112] = p[0x110];
    p[0x110] = 0x23;
    fn_80458880(lbl_8053AF80, 0x62, -1);
}
#pragma opt_propagation reset
extern "C" void fn_803BF3BC(u8* this_) {
    const u64* __restrict tbl;
    int i;
    void* o;

    *(u8*)(*(u8**)(*(u8**)(this_ + 0x20) + 4) + 0xb0) = 1;
    fn_80402E08(*(void**)(this_ + 0x50), -400.0f, 0.0f);
    *(u16*)(*(u8**)(this_ + 0x50) + 0x20) = 0;
    o = *(void**)(*(u8**)(this_ + 0x50) + 4);
    ((PaneVirtVt*)o)->v9(0);
    fn_804023D0(*(void**)(this_ + 0x50), ((KeyLookupVt*)*(void**)(this_ + 0x8))->v15(0x0050666375723031ULL), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((KeyLookupVt*)*(void**)(this_ + 0x8))->v15(0x0050666375723032ULL), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((KeyLookupVt*)*(void**)(this_ + 0x8))->v15(0x0050666375723033ULL), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((KeyLookupVt*)*(void**)(this_ + 0x8))->v15(0x0050666375723034ULL), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));

    if ((this_[0x115] & (u8)(1 << *(s32*)(this_ + 0xa4))) != 0) {
        *(u16*)(*(u8**)(this_ + 0x20) + 0x20) = 0;
        *(u16*)(*(u8**)(this_ + 0x20) + 0x26) = 0;
    } else {
        *(u16*)(*(u8**)(this_ + 0x14) + 0x20) = 0;
        *(u16*)(*(u8**)(this_ + 0x14) + 0x26) = 0;
        *(u16*)(*(u8**)(this_ + 0x18) + 0x20) = 0;
        *(u16*)(*(u8**)(this_ + 0x18) + 0x26) = 0;
        *(u16*)(*(u8**)(this_ + 0x1c) + 0x20) = 0;
        *(u16*)(*(u8**)(this_ + 0x1c) + 0x26) = 0;
        fn_80402E08(*(void**)(this_ + 0x20), 400.0f, 0.0f);
        *(u16*)(*(u8**)(this_ + 0x20) + 0x20) = 0;
        o = *(void**)(*(u8**)(this_ + 0x20) + 4);
        ((PaneVirtVt*)o)->v9(0);
        tbl = lbl_80476938;
        for (i = 0; i < 9; i++) {
            fn_804023D0(*(void**)(this_ + 0x20), ((KeyLookupVt*)*(void**)(this_ + 0x4))->v15(tbl[i]), this_[0x196 + i]);
        }
        *(u16*)(*(u8**)(this_ + 0x20) + 0x26) = 0;
    }
    o = *(void**)(*(u8**)(this_ + 0x34) + 4);
    ((PaneVirtVt*)o)->v9(0);
    fn_804023D0(*(void**)(this_ + 0x34), ((KeyLookupVt*)*(void**)(this_ + 0x8))->v15(0x5061636375723031ULL), *(u8*)(*(u8**)(this_ + 0x34) + 0x28));
    *(u16*)(*(u8**)(this_ + 0x34) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x24) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x24) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x28) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x28) + 0x26) = 0;
    *(u16*)(this_ + 0xd8) = 0;
    *(u16*)(this_ + 0xda) = 0;
    this_[0x112] = this_[0x110];
    this_[0x110] = 0x22;
}
#pragma opt_lifetimes reset
extern "C" void fn_803BF698(u8* this_) {
    u32 state;

    fn_803CE4CC((char*)this_);
    state = 0x117;
    if (lbl_8053AAF8[0x7f] != 0) {
        state = 0x116;
    }
    *(u32*)(this_ + 0x84) = state;
    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(this_ + 8))->search(0x5466743031ULL)), *(s32*)(this_ + 0x84), 0, 0, 0);
    if (*(u32*)(this_ + 0x84) == 0x60 || *(u32*)(this_ + 0x84) == 0x64) {
        *(s32*)(this_ + 0xb0) = 0x5a;
    }
    fn_80402E08(*(void**)(this_ + 0x50), lbl_80543494, lbl_80543458);
    *(u16*)(*(u8**)(this_ + 0x50) + 0x20) = 0;
    ((J2DPane*)*(void**)(*(u8**)(this_ + 0x50) + 4))->setAlpha(0);
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DPane*)*(void**)(this_ + 8))->search(0x50666375723031ULL), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DPane*)*(void**)(this_ + 8))->search(0x50666375723032ULL), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DPane*)*(void**)(this_ + 8))->search(0x50666375723033ULL), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DPane*)*(void**)(this_ + 8))->search(0x50666375723034ULL), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    *(u16*)(*(u8**)(this_ + 0x38) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x38) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x38) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x44) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x44) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x44) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x3c) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x3c) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x3c) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x48) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x48) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x48) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x40) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x40) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x40) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x4c) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x4c) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x4c) + 0x26) = 0;
    ((J2DPane*)*(void**)(*(u8**)(this_ + 0x34) + 4))->setAlpha(0);
    fn_804023D0(*(void**)(this_ + 0x34), ((J2DPane*)*(void**)(this_ + 8))->search(0x5061636375723031ULL), *(u8*)(*(u8**)(this_ + 0x34) + 0x28));
    if (this_[0x115] & (u8)(1 << *(s32*)(this_+0xa4))) {
        *(u16*)(*(u8**)(this_+0x20)+0x20)=0;
        *(u16*)(*(u8**)(this_+0x20)+0x26)=0;
    } else {
    *(u16*)(*(u8**)(this_ + 0x14) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x14) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x18) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x18) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x1c) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x1c) + 0x26) = 0;
    }
    *(u16*)(*(u8**)(this_ + 0x24) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x24) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x28) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x28) + 0x26) = 0;
    *(u16*)(this_ + 0xd8) = 0;
    *(u16*)(this_ + 0xda) = 0;
    this_[0x112] = this_[0x110];
    this_[0x110] = 0x27;
}

static inline int menuWidthPair(const u8* p) {
    return *(const s16*)(p + 0x1e4) + *(const s16*)(p + 0x1e2);
}

#pragma opt_propagation off
static inline s16 menuWidthSum(const u8* p) {
    int a = *(const s16*)(p + 0x1e2);
    int b = *(const s16*)(p + 0x1e4);
    int c = *(const s16*)(p + 0x1e0);
    return c + (b + a);
}
#pragma opt_propagation reset

static inline void bindMenuNine(u8* p, const u8* tbl) {
    int i;
    const u64* keys;
    i = 0;
    keys = (const u64*)(tbl + 0x368);
    for (; i < 9; ++i, ++keys) {
        void* pane = ((J2DPane*)*(void**)(p + 4))->search(*keys);
        fn_804023D0(*(void**)(p + 0x20), pane, p[i + 0x196]);
    }
}

#pragma opt_strength_reduction off
extern "C" void fn_803BF9C4(u8* p) {
    u8* tbl = (u8*)lbl_804765D0;
    u8* q;
    s32 i;
    int k;
    const u64* keys;
    u8* o;
    void* r;
    void* obj;

    *(u8*)(*(u8**)(*(u8**)(p + 0x20) + 4) + 0xb0) = 1;
    *(u8*)(*(u8**)(*(u8**)(p + 0x34) + 4) + 0xb0) = 1;
    obj = *(void**)(*(u8**)(p + 0x50) + 4);
    ((Obj9*)obj)->v9(0);
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p+8))->search(0x50666375723031ULL), (*(u8**)(p + 0x50))[0x28]);
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p+8))->search(0x50666375723032ULL), (*(u8**)(p + 0x50))[0x28]);
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p+8))->search(0x50666375723033ULL), (*(u8**)(p + 0x50))[0x28]);
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p+8))->search(0x50666375723034ULL), (*(u8**)(p + 0x50))[0x28]);

    ((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x50636f70623031ULL))->setBlackWhite(*(JUtility::TColor*)(p+0xe4),*(JUtility::TColor*)(p+0xe0));
    ((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x50636f70623032ULL))->setBlackWhite(*(JUtility::TColor*)(p+0xe4),*(JUtility::TColor*)(p+0xe0));
    ((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x5064656c623031ULL))->setBlackWhite(*(JUtility::TColor*)(p+0xe4),*(JUtility::TColor*)(p+0xe0));
    ((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x5064656c623032ULL))->setBlackWhite(*(JUtility::TColor*)(p+0xe4),*(JUtility::TColor*)(p+0xe0));

    *(s16*)(*(u8**)(p + 0x38) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x38) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x38) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x26) = 0;

    fn_80402E08(*(void**)(p + 0x20), 1.0f, 0.0f);
    *(s16*)(*(u8**)(p + 0x20) + 0x20) = 0;
    obj = *(void**)(*(u8**)(p + 0x20) + 4);
    ((Obj9*)obj)->v9(*(u8*)(*(u8**)(p + 0x20) + 0x28));

    bindMenuNine(p, tbl);
    *(s16*)(*(u8**)(p + 0x20) + 0x26) = 0;
    obj = *(void**)(*(u8**)(p + 0x34) + 4);
    ((Obj9*)obj)->v9(0);
    fn_804023D0(*(void**)(p + 0x34), ((J2DPane*)*(void**)(p+8))->search(0x5061636375723031ULL), (*(u8**)(p + 0x34))[0x28]);
    *(s16*)(*(u8**)(p + 0x34) + 0x26) = 0;

    q = p;
    for (i = 0; i < 4; i++) {
        *(u8*)(*(u8**)(*(u8**)(q + 0x24) + 4) + 0xb0) = 1;
        fn_80402E08(*(void**)(q + 0x24), 0.0f, 100.0f);
        *(s16*)(*(u8**)(q + 0x24) + 0x22) = 0;
        obj = *(void**)(*(u8**)(q + 0x24) + 4);
        ((Obj9*)obj)->v9(0);
        *(s16*)(*(u8**)(q + 0x24) + 0x26) = k = 0;
        switch (i) {
        case 0:
            keys = (const u64*)(tbl + 0x7f8);
            for (; k < 4; k++, keys++) {
                obj = *(void**)(p + 8);
                r = ((J2DPane*)obj)->search(*keys);
                fn_804023D0(*(void**)(q + 0x24), r, p[k + 0x19f]);
            }
            break;
        case 1:
            keys = (const u64*)(tbl + 0x7d8);
            for (; k < 4; k++, keys++) {
                obj = *(void**)(p + 8);
                r = ((J2DPane*)obj)->search(*keys);
                fn_804023D0(*(void**)(q + 0x24), r, p[k + 0x19f]);
            }
            break;
        case 2:
            keys = (const u64*)(tbl + 0x7b8);
            for (; k < 4; k++, keys++) {
                obj = *(void**)(p + 8);
                r = ((J2DPane*)obj)->search(*keys);
                fn_804023D0(*(void**)(q + 0x24), r, p[k + 0x19f]);
            }
            break;
        case 3:
            keys = (const u64*)(tbl + 0x798);
            for (; k < 4; k++, keys++) {
                obj = *(void**)(p + 8);
                r = ((J2DPane*)obj)->search(*keys);
                fn_804023D0(*(void**)(q + 0x24), r, p[k + 0x19f]);
            }
            break;
        }
        q += 4;
    }

    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p+8))->search(0x547374723031ULL)), 0x11e, 0, 0, 0);
    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p+8))->search(0x54636f703031ULL)), 0x11f, 0, 0, 0);

    {
        const s16* widths = (const s16*)(lbl_8050DB0C + 0x1e0);
        int a = widths[1];
        int b = widths[2];
        int partial = b + a;
        s16 sum = widths[0] + partial;
        *(s16*)(p + 0xd8) = *(s16*)(lbl_8050DB0C + 0x1e6);
        if (*(s16*)(p + 0xd8) < sum) {
            *(s16*)(p + 0xd8) = sum;
        }
    }
    *(s16*)(p + 0xda) = 0;
    p[0x112] = p[0x110];
    p[0x110] = 0x20;
}
#pragma opt_strength_reduction reset
extern "C" void fn_803C0018(char* p) {
    s32 state = 0x117;
    if (lbl_8053AAF8[0x7f] != 0) {
        state = 0x116;
    }
    *(s32*)(p + 0x84) = state;
    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(0x5466743031ULL)), *(s32*)(p + 0x84), 0, 0, 0);
    if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
        *(s32*)(p + 0xb0) = 0x5a;
    }
    ((J2DPane*)*(void**)(*(u8**)(p + 0x50) + 4))->setAlpha(0);
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723031ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723032ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723033ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723034ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    *(s16*)(*(u8**)(p + 0x38) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x38) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x38) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x26) = 0;
    ((J2DPane*)*(void**)(*(u8**)(p + 0x34) + 4))->setAlpha(0);
    fn_804023D0(*(void**)(p + 0x34), ((J2DPane*)*(void**)(p + 8))->search(0x5061636375723031ULL), *(u8*)(*(u8**)(p + 0x34) + 0x28));
    *(s16*)(*(u8**)(p + 0x14) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x14) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x18) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x18) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x1c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x1c) + 0x26) = 0;
    *(s16*)(p + 0xd8) = 0;
    *(s16*)(p + 0xda) = 0;
    p[0x112] = p[0x110];
    p[0x110] = 0x1d;
}

extern "C" void fn_803C02CC(u8* p) {
    s32 state = 0x117;
    if (lbl_8053AAF8[0x7f] != 0) {
        state = 0x116;
    }
    *(s32*)(p + 0x84) = state;
    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(0x5466743031ULL)), *(s32*)(p + 0x84), 0, 0, 0);
    if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
        *(s32*)(p + 0xb0) = 0x5a;
    }
    ((J2DPane*)*(void**)(*(u8**)(p + 0x50) + 4))->setAlpha(0);
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723031ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723032ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723033ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723034ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    *(s16*)(*(u8**)(p + 0x38) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x38) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x38) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x26) = 0;
    ((J2DPane*)*(void**)(*(u8**)(p + 0x34) + 4))->setAlpha(0);
    fn_804023D0(*(void**)(p + 0x34), ((J2DPane*)*(void**)(p + 8))->search(0x5061636375723031ULL), *(u8*)(*(u8**)(p + 0x34) + 0x28));
    if (p[0x115] & (u8)(1 << *(s32*)(p + 0xa0))) {
        *(s16*)(*(u8**)(p + 0x20) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x20) + 0x26) = 0;
    } else {
        *(s16*)(*(u8**)(p + 0x14) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x14) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x18) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x18) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x1c) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x1c) + 0x26) = 0;
    }
    *(s16*)(*(u8**)(p + 0x24) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x24) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x28) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x28) + 0x26) = 0;
    *(s16*)(p + 0xd8) = 0;
    *(s16*)(p + 0xda) = 0;
    p[0x112] = p[0x110];
    p[0x110] = 0x1c;
}

extern "C" void fn_803C05D8(u8* p) {
    s32 i;
    s32 j;
    u32* q;

    for (i = 0; i < 8; i++) {
        if (fn_803B90E4(*(u32*)(p + 0xa0), i)) {
            ((J2DPane*)*(void**)(p + 4))->search(((u64*)lbl_80476980)[i + 2])->hide();
        } else {
            ((J2DPane*)*(void**)(p + 4))->search(((u64*)lbl_80476980)[i + 2])->show();
        }
    }

    *(u32*)(p + 0xa8) = *(u32*)(p + 0xa0);
    q = (u32*)p;
    for (j = 0; j < 8; j++) {
        q[0x2e] = fn_803B8CAC(*(u32*)(p + 0xa0), j);
        q++;
    }

    ((J2DPane*)*(void**)(*(u8**)(p + 0x50) + 4))->setAlpha(0);
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723031ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723032ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723033ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723034ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    *(s16*)(*(u8**)(p + 0x38) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x38) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x38) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x26) = 0;
    ((J2DPane*)*(void**)(*(u8**)(p + 0x34) + 4))->setAlpha(0);
    fn_804023D0(*(void**)(p + 0x34), ((J2DPane*)*(void**)(p + 8))->search(0x5061636375723031ULL), *(u8*)(*(u8**)(p + 0x34) + 0x28));
    *(s16*)(*(u8**)(p + 0x34) + 0x26) = 0;
    if (p[0x115] & (u8)(1 << *(s32*)(p + 0xa0))) {
        ((J2DPane*)*(void**)(*(u8**)(p + 0x20) + 4))->show();
        fn_80402E08(*(void**)(p + 0x20), 600.0f, 0.0f);
        *(s16*)(*(u8**)(p + 0x20) + 0x20) = 0;
        ((J2DPane*)*(void**)(*(u8**)(p + 0x20) + 4))->setAlpha(0);
        q = (u32*)lbl_80476938;
        for (i = 0; i < 9; i++) {
            fn_804023D0(*(void**)(p + 0x20), ((J2DPane*)*(void**)(p + 4))->search(*(u64*)q), p[0x196 + i]);
            q += 2;
        }
        *(s16*)(*(u8**)(p + 0x20) + 0x26) = 0;
    } else {
        *(s16*)(*(u8**)(p + 0x14) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x14) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x18) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x18) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x1c) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x1c) + 0x26) = 0;
    }
    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(0x547374723031ULL)), 0x11e, 0, 0, 0);
    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(0x54636f703031ULL)), 0x11f, 0, 0, 0);
    *(s16*)(*(u8**)(p + 0x24) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x24) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x28) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x28) + 0x26) = 0;
    *(s16*)(p + 0xd8) = 0;
    *(s16*)(p + 0xda) = 0;
    p[0x112] = p[0x110];
    p[0x110] = 0x1a;
}

#pragma opt_propagation off
extern "C" void fn_803C0A34(char* pc) {
    u8* p = (u8*)pc;
    u8* kp;
    int i;
    int j;
    u8* keys;
    u8* base;
    u8* selected;
    s32 idx;
    f32 d;
    u8* o;

    base = (u8*)lbl_804765D0;
    for (i = 0, kp = base + 0x3b0; i < 8; i++, kp += 8) {
        if (fn_803B90E4(*(u32*)(p + 0xa0), i)) {
            o = (u8*)keyObj(*(void**)(p + 4), *(u64*)(kp + 0x10));
            o[0xb0] = 0;
        } else {
            o = (u8*)keyObj(*(void**)(p + 4), *(u64*)(kp + 0x10));
            o[0xb0] = 1;
        }
    }

    *(u32*)(p + 0xa8) = *(u32*)(p + 0xa0);
    { u8* q;
    int k;
    q = p;
    for (k = 0; k < 8; k++, q += 4) {
        *(u32*)(q + 0xb8) = fn_803B8CAC(*(u32*)(p + 0xa0), k);
    }
    }

    *(s32*)(p + 0x84) = 100;
    fn_803832BC(getStringPtr__10J2DTextBoxCFv(keyObj(*(void**)(p + 8), 0x5466743031ULL)), *(s32*)(p + 0x84), 0, 0, 0);
    if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 100) {
        *(s32*)(p + 0xb0) = 0x5a;
    }

    fn_803CE4CC((char*)p);
    {
        f32 zero = lbl_80543458;
        *(s32*)(p + 0x80) = 0;
        fn_80402E08(*(void**)(p + 0x14), zero, zero);
    }
    *(s16*)(*(u8**)(p + 0x14) + 0x22) = 0;
    stopPane(*(void**)(*(u8**)(p + 0x14) + 4));
    fn_80402E08(*(void**)(p + 0x18), lbl_80543458, lbl_80543458);
    *(s16*)(*(u8**)(p + 0x18) + 0x22) = 0;
    stopPane(*(void**)(*(u8**)(p + 0x18) + 4));
    fn_80402E08(*(void**)(p + 0x1c), lbl_80543458, lbl_80543458);
    *(s16*)(*(u8**)(p + 0x1c) + 0x22) = 0;
    stopPane(*(void**)(*(u8**)(p + 0x1c) + 4));

    for (j = 0, keys = base + 0x48; j < 0x51; j++, keys += 8) {
        fn_804023D0(*(void**)(p + 0x14), keyObj(*(void**)(p + 4), *(u64*)keys), p[0x132 + j]);
    }
    { int k;
 u8* key;
 for (k = 0, key = base + 0x2d0; k < 0x13; k++, key += 8) {
        fn_804023D0(*(void**)(p + 0x14), keyObj(*(void**)(p + 8), *(u64*)key), p[0x183 + k]);
    }
}

    {
        u8* firstPane = *(u8**)(p + 0x14);
        *(s16*)(firstPane + 0x26) = 0;
        f32 one = 0.0f;
        *(s16*)(*(u8**)(p + 0x18) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x1c) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x20) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x20) + 0x26) = 0;

        idx = *(s32*)(p + 0xa0);
        f32 first = *(f32*)(*(u8**)(p + 0x38) + 0xc);
        f32 second = *(f32*)(menuSlot((char*)p, idx) + 0xc);
        d = first - second;
        fn_80402E08((void*)menuSlot((char*)p, idx), one, d);
    }
    {
        u8* q = p;
        q += *(s32*)(p + 0xa0) * 4;
        *(s16*)(*(u8**)(q + 0x38) + 0x22) = 0;
        q = p;
        q += *(s32*)(p + 0xa0) * 4;
        *(s16*)(*(u8**)(q + 0x38) + 0x26) = 0;
    }
    o = menuSlot((char*)p, *(s32*)(p + 0xa0));
    {
        void* sub = *(void**)(o + 4);
        ((PaneVirtVt*)sub)->v9(o[0x28]);
    }

    idx = *(s32*)(p + 0xa0);
    {
 const u64* key = (const u64*)(base + 0x780);
 fn_804023D0(*(void**)((selected = p + idx * 4) + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x125]);
 }
    { const u64* key = (const u64*)(base + 0x768);
 fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x126]);
 }
    { const u64* key = (const u64*)(base + 0x750);
 fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x127]);
 }
    { const u64* key = (const u64*)(base + 0x6c8);
 fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x128]);
 }
    { const u64* key = (const u64*)(base + 0x6b0);
 fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x129]);
 }
    { const u64* key = (const u64*)(base + 0x698);
 fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x12a]);
 }
    { const u64* key = (const u64*)(base + 0x680);
 fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x12b]);
 }
    { const u64* key = (const u64*)(base + 0x668);
 fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x12c]);
 }
    { const u64* key = (const u64*)(base + 0x650);
 fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x12d]);
 }
    { const u64* key = (const u64*)(base + 0x638);
 fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x12e]);
 }
    { const u64* key = (const u64*)(base + 0x620);
 fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x12f]);
 }
    { const u64* key = (const u64*)(base + 0x608);
 fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x130]);
 }
    { const u64* key = (const u64*)(base + 0x5f0);
 fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x131]);
 }

    *(s16*)(p + 0xd8) = 0;
    *(s16*)(p + 0xda) = 0;
    p[0x112] = p[0x110];
    p[0x110] = 0x17;
    fn_80458880(lbl_8053AF80, 0x5b, -1);
}
#pragma opt_propagation reset
extern "C" void fn_803C1054(u8* p) {
    s32 i;
    const u64* pair;

    ((u8*)*(void**)(*(u8**)(p + 0x20) + 4))[0xb0] = 1;
    fn_80402E08(*(void**)(p + 0x50), -300.0f, 0.0f);
    *(u16*)(*(u8**)(p + 0x50) + 0x20) = 0;
    ((J2DTextBoxVt*)*(void**)(*(u8**)(p + 0x50) + 4))->v9(0);
    fn_804023D0(*(void**)(p + 0x50), ((KeyLookupVt*)*(void**)(p + 8))->v15(0x0050666375723031ULL), (*(u8**)(p + 0x50))[0x28]);
    fn_804023D0(*(void**)(p + 0x50), ((KeyLookupVt*)*(void**)(p + 8))->v15(0x0050666375723032ULL), (*(u8**)(p + 0x50))[0x28]);
    fn_804023D0(*(void**)(p + 0x50), ((KeyLookupVt*)*(void**)(p + 8))->v15(0x0050666375723033ULL), (*(u8**)(p + 0x50))[0x28]);
    fn_804023D0(*(void**)(p + 0x50), ((KeyLookupVt*)*(void**)(p + 8))->v15(0x0050666375723034ULL), (*(u8**)(p + 0x50))[0x28]);

    if (p[0x115] & (u8)(1 << *(s32*)(p + 0xa0))) {
        *(u16*)(*(u8**)(p + 0x20) + 0x20) = 0;
        *(u16*)(*(u8**)(p + 0x20) + 0x26) = 0;
    } else {
        *(u16*)(*(u8**)(p + 0x14) + 0x20) = 0;
        *(u16*)(*(u8**)(p + 0x14) + 0x26) = 0;
        *(u16*)(*(u8**)(p + 0x18) + 0x20) = 0;
        *(u16*)(*(u8**)(p + 0x18) + 0x26) = 0;
        *(u16*)(*(u8**)(p + 0x1c) + 0x20) = 0;
        *(u16*)(*(u8**)(p + 0x1c) + 0x26) = 0;
        fn_80402E08(*(void**)(p + 0x20), 600.0f, *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + 0x38) + 0xc));
        *(u16*)(*(u8**)(p + 0x20) + 0x20) = 0;
        ((J2DTextBoxVt*)*(void**)(*(u8**)(p + 0x20) + 4))->v9(0);
        pair = lbl_80476938;
        for (i = 0; i < 9; i++) {
            fn_804023D0(*(void**)(p + 0x20), ((KeyLookupVt*)*(void**)(p + 4))->v15(pair[i]), p[0x196 + i]);
        }
        *(u16*)(*(u8**)(p + 0x20) + 0x26) = 0;
    }
    ((J2DTextBoxVt*)*(void**)(*(u8**)(p + 0x34) + 4))->v9(0);
    fn_804023D0(*(void**)(p + 0x34), ((KeyLookupVt*)*(void**)(p + 8))->v15(0x5061636375723031ULL), (*(u8**)(p + 0x34))[0x28]);
    *(u16*)(*(u8**)(p + 0x34) + 0x26) = 0;
    *(u16*)(*(u8**)(p + 0x24) + 0x22) = 0;
    *(u16*)(*(u8**)(p + 0x24) + 0x26) = 0;
    *(u16*)(*(u8**)(p + 0x28) + 0x22) = 0;
    *(u16*)(*(u8**)(p + 0x28) + 0x26) = 0;
    *(u16*)(p + 0xd8) = 0;
    *(u16*)(p + 0xda) = 0;
    p[0x112] = p[0x110];
    p[0x110] = 0x16;
}

extern "C" void fn_803C1340(u8* p) {
    void* o;

    fn_80402E08(*(void**)(p + 0x50), -300.0f, 0.0f);
    *(s16*)(*(u8**)(p + 0x50) + 0x20) = 0;
    ((J2DPane*)*(void**)(*(u8**)(p+0x50)+4))->setAlpha(0);
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p+8))->search(0x0050666375723031ULL), (*(u8**)(p + 0x50))[0x28]);
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p+8))->search(0x0050666375723032ULL), (*(u8**)(p + 0x50))[0x28]);
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p+8))->search(0x0050666375723033ULL), (*(u8**)(p + 0x50))[0x28]);
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p+8))->search(0x0050666375723034ULL), (*(u8**)(p + 0x50))[0x28]);

    ((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x50636f70623031ULL))->setBlackWhite(*(JUtility::TColor*)(p+0xe4),*(JUtility::TColor*)(p+0xe0));
    ((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x50636f70623032ULL))->setBlackWhite(*(JUtility::TColor*)(p+0xe4),*(JUtility::TColor*)(p+0xe0));
    ((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x5064656c623031ULL))->setBlackWhite(*(JUtility::TColor*)(p+0xe4),*(JUtility::TColor*)(p+0xe0));
    ((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x5064656c623032ULL))->setBlackWhite(*(JUtility::TColor*)(p+0xe4),*(JUtility::TColor*)(p+0xe0));
    *(s16*)(*(u8**)(p + 0x38) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x38) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x38) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x44) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x3c) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x48) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x40) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x4c) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x14) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x14) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x18) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x18) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x1c) + 0x20) = 0;
    *(s16*)(*(u8**)(p + 0x1c) + 0x26) = 0;

    ((J2DPane*)*(void**)(*(u8**)(p+0x34)+4))->setAlpha(0);
    fn_804023D0(*(void**)(p + 0x34), ((J2DPane*)*(void**)(p+8))->search(0x5061636375723031ULL), (*(u8**)(p + 0x34))[0x28]);
    *(s16*)(*(u8**)(p + 0x34) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x24) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x24) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x28) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x28) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x2c) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x2c) + 0x26) = 0;
    *(s16*)(*(u8**)(p + 0x30) + 0x22) = 0;
    *(s16*)(*(u8**)(p + 0x30) + 0x26) = 0;

    *(f32*)(p + 0x70) = 0.0f;
    *(f32*)(p + 0x64) = 0.0f;
    *(f32*)(p + 0x74) = 0.0f;
    *(f32*)(p + 0x68) = 0.0f;
    *(f32*)(p + 0x78) = 0.0f;
    *(f32*)(p + 0x6c) = 0.0f;
    *(s16*)(p + 0xd8) = 0;
    *(s16*)(p + 0xda) = 0;
    p[0x112] = p[0x110];
    p[0x110] = 0x14;
}

extern "C" void fn_803C1734(u8* this_) {
 u8* p=this_;
 u8* base=(u8*)lbl_804765D0;
 {u8* k;s32 i;k=base+0x3b0;
 for(i=0;i<8;i++,k+=8){
 if(fn_803B90E4(*(u32*)(p+0xa4),i)) ((J2DPane*)*(void**)(p+4))->search(*(u64*)(k+0x10))->hide();
 else ((J2DPane*)*(void**)(p+4))->search(*(u64*)(k+0x10))->show();
 }
 }
 *(u32*)(p+0xa8)=*(u32*)(p+0xa4);
 {u8* q;s32 i;q=p;
 for(i=0;i<8;i++,q+=4) *(u32*)(q+0xb8)=fn_803B8CAC(*(u32*)(p+0xa4),i);}
((J2DPane*)*(void**)(*(u8**)(p+0x14)+4))->show();
((J2DPane*)*(void**)(*(u8**)(p+0x18)+4))->show();
((J2DPane*)*(void**)(*(u8**)(p+0x1c)+4))->show();
((J2DPane*)*(void**)(*(u8**)(p+0x34)+4))->show();
((J2DPane*)*(void**)(*(u8**)(p+0x24)+4))->show();
((J2DPane*)*(void**)(*(u8**)(p+0x28)+4))->show();
((J2DPane*)*(void**)(*(u8**)(p+0x2c)+4))->show();
((J2DPane*)*(void**)(*(u8**)(p+0x30)+4))->show();
if(*(u64*)(lbl_8050EC80+*(u32*)(p+0xa4)*200+0x20)==0) {
((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x50636f70623031ULL))->setBlackWhite(JUtility::TColor(0x50,0x50,0x50,0),JUtility::TColor(0xb4,0xb4,0xb4,0xff));
((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x50636f70623032ULL))->setBlackWhite(JUtility::TColor(0x50,0x50,0x50,0),JUtility::TColor(0xb4,0xb4,0xb4,0xff));
((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x5064656c623031ULL))->setBlackWhite(JUtility::TColor(0x50,0x50,0x50,0),JUtility::TColor(0xb4,0xb4,0xb4,0xff));
((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x5064656c623032ULL))->setBlackWhite(JUtility::TColor(0x50,0x50,0x50,0),JUtility::TColor(0xb4,0xb4,0xb4,0xff));
} else {
((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x50636f70623031ULL))->setBlackWhite(*(JUtility::TColor*)(p+0xe4),*(JUtility::TColor*)(p+0xe0));
((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x50636f70623032ULL))->setBlackWhite(*(JUtility::TColor*)(p+0xe4),*(JUtility::TColor*)(p+0xe0));
((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x5064656c623031ULL))->setBlackWhite(*(JUtility::TColor*)(p+0xe4),*(JUtility::TColor*)(p+0xe0));
((J2DPicture*)((J2DPane*)*(void**)(p+8))->search(0x5064656c623032ULL))->setBlackWhite(*(JUtility::TColor*)(p+0xe4),*(JUtility::TColor*)(p+0xe0));
}
stopPane(*(void**)(*(u8**)(p+0x50)+4));
fn_804023D0(*(void**)(p+0x50),((J2DPane*)*(void**)(p+8))->search(0x50666375723031ULL),(*(u8**)(p+0x50))[0x28]);
fn_804023D0(*(void**)(p+0x50),((J2DPane*)*(void**)(p+8))->search(0x50666375723032ULL),(*(u8**)(p+0x50))[0x28]);
fn_804023D0(*(void**)(p+0x50),((J2DPane*)*(void**)(p+8))->search(0x50666375723033ULL),(*(u8**)(p+0x50))[0x28]);
fn_804023D0(*(void**)(p+0x50),((J2DPane*)*(void**)(p+8))->search(0x50666375723034ULL),(*(u8**)(p+0x50))[0x28]);
*(s16*)(*(u8**)(p+0x50)+0x26)=0;
*(s16*)(*(u8**)(p+0x38)+0x20)=0;
*(s16*)(*(u8**)(p+0x38)+0x22)=0;
*(s16*)(*(u8**)(p+0x38)+0x26)=0;
*(s16*)(*(u8**)(p+0x44)+0x20)=0;
*(s16*)(*(u8**)(p+0x44)+0x22)=0;
*(s16*)(*(u8**)(p+0x44)+0x26)=0;
*(s16*)(*(u8**)(p+0x3c)+0x20)=0;
*(s16*)(*(u8**)(p+0x3c)+0x22)=0;
*(s16*)(*(u8**)(p+0x3c)+0x26)=0;
*(s16*)(*(u8**)(p+0x48)+0x20)=0;
*(s16*)(*(u8**)(p+0x48)+0x22)=0;
*(s16*)(*(u8**)(p+0x48)+0x26)=0;
*(s16*)(*(u8**)(p+0x40)+0x20)=0;
*(s16*)(*(u8**)(p+0x40)+0x22)=0;
*(s16*)(*(u8**)(p+0x40)+0x26)=0;
*(s16*)(*(u8**)(p+0x4c)+0x20)=0;
*(s16*)(*(u8**)(p+0x4c)+0x22)=0;
*(s16*)(*(u8**)(p+0x4c)+0x26)=0;
fn_80402E08(*(void**)(p+0x14),0.0f,1.0f);
*(s16*)(*(u8**)(p+0x14)+0x20)=0;
stopPane(*(void**)(*(u8**)(p+0x14)+4));
fn_80402E08(*(void**)(p+0x18),0.0f,1.0f);
*(s16*)(*(u8**)(p+0x18)+0x20)=0;
stopPane(*(void**)(*(u8**)(p+0x18)+4));
fn_80402E08(*(void**)(p+0x1c),0.0f,1.0f);
*(s16*)(*(u8**)(p+0x1c)+0x20)=0;
stopPane(*(void**)(*(u8**)(p+0x1c)+4));
{u8* k;s32 i;i=0;k=base+0x48;for(;i<81;i++,k+=8){fn_804023D0(*(void**)(p+0x14),((J2DPane*)*(void**)(p+4))->search(*(u64*)k),p[i+0x132]);}}
{u8* k;s32 i;i=0;k=base+0x2d0;for(;i<19;i++,k+=8){fn_804023D0(*(void**)(p+0x14),((J2DPane*)*(void**)(p+8))->search(*(u64*)k),p[i+0x183]);}}
*(s16*)(*(u8**)(p+0x14)+0x26)=0;
*(s16*)(*(u8**)(p+0x18)+0x26)=0;
*(s16*)(*(u8**)(p+0x1c)+0x26)=0;
stopPane(*(void**)(*(u8**)(p+0x34)+4));
fn_804023D0(*(void**)(p+0x34),((J2DPane*)*(void**)(p+8))->search(0x5061636375723031ULL),(*(u8**)(p+0x34))[0x28]);
*(s16*)(*(u8**)(p+0x34)+0x26)=0;
{u8* q;s32 i;q=p;for(i=0;i<4;i++,q+=4){
fn_80402E08(*(void**)(q+0x24),1.0f,lbl_8054349C);
*(s16*)(*(u8**)(q+0x24)+0x22)=0;
stopPane(*(void**)(*(u8**)(q+0x24)+4));
switch(i){
case 0:{s32 j;u8* kp;j=0;kp=base+0x7f8;for(;j<4;j++,kp+=8){fn_804023D0(*(void**)(q+0x24),((J2DPane*)*(void**)(p+8))->search(*(u64*)kp),p[j+0x19f]);}break;}
case 1:{u8* kp;s32 j;j=0;kp=base+0x7d8;for(;j<4;j++,kp+=8){fn_804023D0(*(void**)(q+0x24),((J2DPane*)*(void**)(p+8))->search(*(u64*)kp),p[j+0x19f]);}break;}
case 2:{u8* kp;s32 j;j=0;kp=base+0x7b8;for(;j<4;j++,kp+=8){fn_804023D0(*(void**)(q+0x24),((J2DPane*)*(void**)(p+8))->search(*(u64*)kp),p[j+0x19f]);}break;}
case 3:{u8* kp;s32 j;j=0;kp=base+0x798;for(;j<4;j++,kp+=8){fn_804023D0(*(void**)(q+0x24),((J2DPane*)*(void**)(p+8))->search(*(u64*)kp),p[j+0x19f]);}break;}
}
*(s16*)(*(u8**)(q+0x24)+0x26)=0;}}
fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p+8))->search(0x547374723031ULL)),280,0,0,0);
fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p+8))->search(0x54636f703031ULL)),281,0,0,0);
fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p+8))->search(0x5464656c3031ULL)),282,0,0,0);
fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p+8))->search(0x546261633031ULL)),283,0,0,0);
*(s16*)(p+0xd8)=0;*(s16*)(p+0xda)=0;p[0x112]=p[0x110];p[0x110]=0x12;}

extern "C" void fn_803C21A8(u8* this_) {
    u32 state;

    fn_803CE4CC((char*)this_);
    state = 0x117;
    if (lbl_8053AAF8[0x7f] != 0) {
        state = 0x116;
    }
    *(u32*)(this_ + 0x84) = state;
    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(this_ + 8))->search(0x5466743031ULL)), *(s32*)(this_ + 0x84), 0, 0, 0);
    if (*(u32*)(this_ + 0x84) == 0x60 || *(u32*)(this_ + 0x84) == 0x64) {
        *(s32*)(this_ + 0xb0) = 0x5a;
    }
    fn_80402E08(*(void**)(this_ + 0x50), lbl_80543494, lbl_80543458);
    *(u16*)(*(u8**)(this_ + 0x50) + 0x20) = 0;
    ((J2DPane*)*(void**)(*(u8**)(this_ + 0x50) + 4))->setAlpha(0);
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DPane*)*(void**)(this_ + 8))->search(0x50666375723031ULL), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DPane*)*(void**)(this_ + 8))->search(0x50666375723032ULL), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DPane*)*(void**)(this_ + 8))->search(0x50666375723033ULL), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    fn_804023D0(*(void**)(this_ + 0x50), ((J2DPane*)*(void**)(this_ + 8))->search(0x50666375723034ULL), *(u8*)(*(u8**)(this_ + 0x50) + 0x28));
    *(u16*)(*(u8**)(this_ + 0x38) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x38) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x38) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x44) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x44) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x44) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x3c) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x3c) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x3c) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x48) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x48) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x48) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x40) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x40) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x40) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x4c) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x4c) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x4c) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x14) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x14) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x18) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x18) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x1c) + 0x20) = 0;
    *(u16*)(*(u8**)(this_ + 0x1c) + 0x26) = 0;
    ((J2DPane*)*(void**)(*(u8**)(this_ + 0x34) + 4))->setAlpha(0);
    fn_804023D0(*(void**)(this_ + 0x34), ((J2DPane*)*(void**)(this_ + 8))->search(0x5061636375723031ULL), *(u8*)(*(u8**)(this_ + 0x34) + 0x28));
    *(u16*)(*(u8**)(this_ + 0x24) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x24) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x28) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x28) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x2c) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x2c) + 0x26) = 0;
    *(u16*)(*(u8**)(this_ + 0x30) + 0x22) = 0;
    *(u16*)(*(u8**)(this_ + 0x30) + 0x26) = 0;
    *(u16*)(this_ + 0xd8) = 0;
    *(u16*)(this_ + 0xda) = 0;
    this_[0x112] = this_[0x110];
    this_[0x110] = 6;
}

void fn_803C24BC(char* this_) {
    s32 n;
    u8* ob;
    u8* sub;
    void* r;
    u32 state;
    char* s;
    u8* o54;
    u8* o;
    f32 fa;
    f32 fb;
    const u8* base = lbl_804765D0;
    u32* k0 = (u32*)(base + 0x780);
    u32* k1 = (u32*)(base + 0x768);
    u32* k2 = (u32*)(base + 0x750);
    u32* k3 = (u32*)(base + 0x6c8);
    u32* k4 = (u32*)(base + 0x6b0);
    u32* k5 = (u32*)(base + 0x698);
    u32* k6 = (u32*)(base + 0x680);
    u32* k7 = (u32*)(base + 0x668);
    u32* k8 = (u32*)(base + 0x650);
    u32* k9 = (u32*)(base + 0x638);
    u32* k10 = (u32*)(base + 0x620);
    u32* k11 = (u32*)(base + 0x608);
    u32* k12 = (u32*)(base + 0x5f0);
    u32* j0 = (u32*)(base + 0x5d8);
    u32* j1 = (u32*)(base + 0x5c0);
    u32* j2 = (u32*)(base + 0x5a8);
    u32* j3 = (u32*)(base + 0x590);
    u32* j4 = (u32*)(base + 0x578);
    u32* j5 = (u32*)(base + 0x560);
    u32* j6 = (u32*)(base + 0x548);
    u32* j7 = (u32*)(base + 0x530);
    u32* j8 = (u32*)(base + 0x518);
    u32* j9 = (u32*)(base + 0x500);
    u32* j10 = (u32*)(base + 0x4e8);
    u32* j11 = (u32*)(base + 0x4d0);
    u32* j12 = (u32*)(base + 0x4b8);
    u8* p = (u8*)this_;

    fn_803CE4CC(this_);
    state = 0x117;
    if (lbl_8053AAF8[0x7f] != 0) {
        state = 0x116;
    }
    *(u32*)(p + 0x84) = state;
    sub = *(u8**)(p + 8);
    r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, state, 0x54, 0x66743031);
    s = getStringPtr__10J2DTextBoxCFv(r);
    fn_803832BC(s, *(u32*)(p + 0x84), 0, 0, 0);
    if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
        *(u32*)(p + 0xb0) = 0x5a;
    }
    fa = lbl_80543494;
    fb = lbl_80543458;
    o = *(u8**)(p + 0x14);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 0;
    o = *(u8**)(p + 0x18);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 0;
    o = *(u8**)(p + 0x1c);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 0;
    o = *(u8**)(p + 0x34);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 0;
    o = *(u8**)(p + 0x24);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 0;
    o = *(u8**)(p + 0x28);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 0;
    o = *(u8**)(p + 0x2c);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 0;
    o = *(u8**)(p + 0x30);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 0;
    o = *(u8**)(p + 0x50);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 1;
    o = *(u8**)(p + 0x38);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 1;
    o = *(u8**)(p + 0x44);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 1;
    o = *(u8**)(p + 0x3c);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 1;
    o = *(u8**)(p + 0x48);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 1;
    o = *(u8**)(p + 0x40);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 1;
    o = *(u8**)(p + 0x4c);
    *(u8*)(*(u8**)(o + 4) + 0xb0) = 1;

    fn_80402E08(*(void**)(p + 0x50), fa, fb);
    *(u16*)(*(u8**)(p + 0x50) + 0x20) = 0;
    sub = *(u8**)(*(u8**)(p + 0x50) + 4);
    ((void (*)(void*, u32))(*(void***)sub)[9])(sub, 0);

    sub = *(u8**)(p + 8);
    r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, 0x500000, 0x506663, 0x75723031);
    fn_804023D0(*(void**)(p + 0x50), r, (*(u8**)(p + 0x50))[0x28]);
    sub = *(u8**)(p + 8);
    r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, 0x500000, 0x506663, 0x75723032);
    fn_804023D0(*(void**)(p + 0x50), r, (*(u8**)(p + 0x50))[0x28]);
    sub = *(u8**)(p + 8);
    r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, 0x500000, 0x506663, 0x75723033);
    fn_804023D0(*(void**)(p + 0x50), r, (*(u8**)(p + 0x50))[0x28]);
    sub = *(u8**)(p + 8);
    r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, 0x500000, 0x506663, 0x75723034);
    fn_804023D0(*(void**)(p + 0x50), r, (*(u8**)(p + 0x50))[0x28]);
    *(u16*)(*(u8**)(p + 0x50) + 0x26) = 0;

    for (n = 0; n < 3; n++) {
        ob = p + n * 4;

        fn_80402E08(*(void**)(ob + 0x38), lbl_80543458, lbl_805434A0);
        *(u16*)(*(u8**)(ob + 0x38) + 0x22) = 0;
        sub = *(u8**)(*(u8**)(ob + 0x38) + 4);
        ((void (*)(void*, u32))(*(void***)sub)[9])(sub, 0);

        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)k0, k0[0], k0[1]);
        fn_804023D0(*(void**)(ob + 0x38), r, p[0x125]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)k1, k1[0], k1[1]);
        fn_804023D0(*(void**)(ob + 0x38), r, p[0x126]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)k2, k2[0], k2[1]);
        fn_804023D0(*(void**)(ob + 0x38), r, p[0x127]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)k3, k3[0], k3[1]);
        fn_804023D0(*(void**)(ob + 0x38), r, p[0x128]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)k4, k4[0], k4[1]);
        fn_804023D0(*(void**)(ob + 0x38), r, p[0x129]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)k5, k5[0], k5[1]);
        fn_804023D0(*(void**)(ob + 0x38), r, p[0x12a]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)k6, k6[0], k6[1]);
        fn_804023D0(*(void**)(ob + 0x38), r, p[0x12b]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)k7, k7[0], k7[1]);
        fn_804023D0(*(void**)(ob + 0x38), r, p[0x12c]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)k8, k8[0], k8[1]);
        fn_804023D0(*(void**)(ob + 0x38), r, p[0x12d]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)k9, k9[0], k9[1]);
        fn_804023D0(*(void**)(ob + 0x38), r, p[0x12e]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)k10, k10[0], k10[1]);
        fn_804023D0(*(void**)(ob + 0x38), r, p[0x12f]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)k11, k11[0], k11[1]);
        fn_804023D0(*(void**)(ob + 0x38), r, p[0x130]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)k12, k12[0], k12[1]);
        fn_804023D0(*(void**)(ob + 0x38), r, p[0x131]);
        *(u16*)(*(u8**)(ob + 0x38) + 0x26) = 0;

        fn_80402E08(*(void**)(ob + 0x44), lbl_80543494, lbl_80543458);
        *(u16*)(*(u8**)(ob + 0x44) + 0x20) = 0;
        sub = *(u8**)(*(u8**)(ob + 0x44) + 4);
        ((void (*)(void*, u32))(*(void***)sub)[9])(sub, 0);

        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)j0, j0[0], j0[1]);
        fn_804023D0(*(void**)(ob + 0x44), r, p[0x118]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)j1, j1[0], j1[1]);
        fn_804023D0(*(void**)(ob + 0x44), r, p[0x119]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)j2, j2[0], j2[1]);
        fn_804023D0(*(void**)(ob + 0x44), r, p[0x11a]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)j3, j3[0], j3[1]);
        fn_804023D0(*(void**)(ob + 0x44), r, p[0x11b]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)j4, j4[0], j4[1]);
        fn_804023D0(*(void**)(ob + 0x44), r, p[0x11c]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)j5, j5[0], j5[1]);
        fn_804023D0(*(void**)(ob + 0x44), r, p[0x11d]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)j6, j6[0], j6[1]);
        fn_804023D0(*(void**)(ob + 0x44), r, p[0x11e]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)j7, j7[0], j7[1]);
        fn_804023D0(*(void**)(ob + 0x44), r, p[0x11f]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)j8, j8[0], j8[1]);
        fn_804023D0(*(void**)(ob + 0x44), r, p[0x120]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)j9, j9[0], j9[1]);
        fn_804023D0(*(void**)(ob + 0x44), r, p[0x121]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)j10, j10[0], j10[1]);
        fn_804023D0(*(void**)(ob + 0x44), r, p[0x122]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)j11, j11[0], j11[1]);
        fn_804023D0(*(void**)(ob + 0x44), r, p[0x123]);
        sub = *(u8**)(p + 8);
        r = ((void* (*)(void*, u32, u32, u32))(*(void***)sub)[15])(sub, (u32)j12, j12[0], j12[1]);
        fn_804023D0(*(void**)(ob + 0x44), r, p[0x124]);
        *(u16*)(*(u8**)(ob + 0x44) + 0x26) = 0;

        k0 += 2; k1 += 2; k2 += 2; k3 += 2; k4 += 2; k5 += 2; k6 += 2;
        k7 += 2; k8 += 2; k9 += 2; k10 += 2; k11 += 2; k12 += 2;
        j0 += 2; j1 += 2; j2 += 2; j3 += 2; j4 += 2; j5 += 2; j6 += 2;
        j7 += 2; j8 += 2; j9 += 2; j10 += 2; j11 += 2; j12 += 2;
    }

    o54 = *(u8**)(p + 0x54);
    fn_80402E08(o54, lbl_80543494, lbl_80543458);
    *(u16*)(o54 + 0x22) = 0;
    sub = *(u8**)(o54 + 4);
    ((void (*)(void*, u32))(*(void***)sub)[9])(sub, 0);
    *(u16*)(o54 + 0x26) = 0;
    *(u16*)(p + 0xd8) = 0;
    *(u16*)(p + 0xda) = 0;
    p[0x112] = p[0x110];
    p[0x110] = 4;
}

extern "C" void fn_803C2E24(u8* p) {
    s32 iVar6, iVar4, iVar7, iVar10, iVar13, iVar11, iVar9, iVar12, iVar8;
    s32 aVal, sVal;
    s32 ord[3];
    s32* pw;
    s32 i;
    u8* tb = lbl_8050DB0C;

    iVar11 = *(s16*)(tb + 0x1fc);
    iVar13 = *(s16*)(tb + 0x1fa);
    iVar4 = *(s16*)(tb + 0x1f4);
    iVar7 = *(s16*)(tb + 0x1f6);
    iVar10 = *(s16*)(tb + 0x1f8);
    iVar6 = iVar4 + iVar7;
    aVal = iVar10 + iVar13 + iVar11 * 3;
    if (iVar6 < aVal) {
        iVar6 = aVal;
    }
    iVar9 = *(s16*)(tb + 0x1fe);
    iVar12 = *(s16*)(tb + 0x200);
    iVar8 = *(s16*)(tb + 0x202);
    sVal = iVar9 + iVar12 + iVar8;
    if (iVar6 < sVal) {
        iVar6 = sVal;
    }

    pw = ord;
    if (*(s32*)(p + 0xa4) != 0) {
        ord[0] = 0;
        pw = ord + 1;
    }
    if (*(s32*)(p + 0xa4) != 1) {
        *pw = 1;
        pw++;
    }
    if (*(s32*)(p + 0xa4) != 2) {
        *pw = 2;
    }

    *(s16*)(p + 0xd8) += 1;
    if (*(s16*)(p + 0xd8) > iVar4) {
        if (((1 << *(s32*)(p + 0xa4)) & 0xff & p[0x115]) == 0) {
            setFade(*(void**)(p + 0x14), iVar7, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + 0x14), iVar7, *(u8*)(*(u8**)(p + 0x14) + 0x28), 0);
            setFade(*(void**)(p + 0x18), iVar7, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + 0x18), iVar7, *(u8*)(*(u8**)(p + 0x18) + 0x28), 0);
            setFade(*(void**)(p + 0x1c), iVar7, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + 0x1c), iVar7, *(u8*)(*(u8**)(p + 0x1c) + 0x28), 0);
            for (i = 0; i < 0x51; i++) {
                void* o = ((KeyGetFn)(*(void***)(*(u8**)(p + 4)))[15])(*(u8**)(p + 4), *(u64*)(lbl_804765D0 + 0x48 + i * 8));
                fn_804023D0(*(void**)(p + 0x14), o, p[i + 0x132]);
            }
            for (i = 0; i < 0x13; i++) {
                void* o = ((KeyGetFn)(*(void***)(*(u8**)(p + 8)))[15])(*(u8**)(p + 8), *(u64*)(lbl_804765D0 + 0x2d0 + i * 8));
                fn_804023D0(*(void**)(p + 0x14), o, p[i + 0x183]);
            }
        } else {
            setFade(*(void**)(p + 0x20), iVar7, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + 0x20), iVar7, *(u8*)(*(u8**)(p + 0x20) + 0x28), 0);
            for (i = 0; i < 9; i++) {
                void* o = ((KeyGetFn)(*(void***)(*(u8**)(p + 4)))[15])(*(u8**)(p + 4), *(u64*)(lbl_804765D0 + 0x368 + i * 8));
                fn_804023D0(*(void**)(p + 0x20), o, p[i + 0x196]);
            }
        }
    }
    (void)iVar6;
    (void)iVar8;
    (void)iVar9;
    (void)iVar12;
}

typedef void* (*KeyGetFn)(void* self, u64 key);
typedef void (*Fn5Fn)(void* a, s16 b, s32 c, f32 d, f32 e);
#pragma opt_propagation off
#pragma opt_strength_reduction off
extern "C" void fn_803C3904(u8* this_) {
    const u8* base = lbl_804765D0;
    s32 order[2];
    register s32* ord = order;
    s32* out = order;
    s32 off;
    s32 k;
    unsigned int idx;
    void* pane;
    s32 a = *(s16*)(lbl_8050DB0C + 0x200);
    s32 b = *(s16*)(lbl_8050DB0C + 0x202);
    s32 c = *(s16*)(lbl_8050DB0C + 0x1fe);
    int total = a + b;
    total = c + total;

    for (s32 n = 0; n < 3; ++n) {
        if (n != *(s32*)(this_ + 0xa4)) {
            *out++ = n;
        }
    }
    *(s16*)(this_ + 0xd8) = *(s16*)(this_ + 0xd8) + 1;

    k = 0;
    off = 0;
    do {
        if (*(s16*)(this_ + 0xd8) > c + off) {
            ((Fn5Fn)fn_80402B10)(*(void**)(this_ + 0x38 + *ord * 4), a, 0, lbl_80543498, lbl_80543458);
            fn_80402628(*(void**)(this_ + 0x38 + *ord * 4), a, 0, *(u8*)(*(u8**)(this_ + 0x38 + *ord * 4) + 0x28));
            idx = *ord;
            {
                const u64* keys = (const u64*)(base + 0x780);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), pane, this_[0x125]);
            }
            {
                const u64* keys = (const u64*)(base + 0x768);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), pane, this_[0x126]);
            }
            {
                const u64* keys = (const u64*)(base + 0x750);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), pane, this_[0x127]);
            }
            {
                const u64* keys = (const u64*)(base + 0x6c8);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), pane, this_[0x128]);
            }
            {
                const u64* keys = (const u64*)(base + 0x6b0);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), pane, this_[0x129]);
            }
            {
                const u64* keys = (const u64*)(base + 0x698);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), pane, this_[0x12a]);
            }
            {
                const u64* keys = (const u64*)(base + 0x680);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), pane, this_[0x12b]);
            }
            {
                const u64* keys = (const u64*)(base + 0x668);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), pane, this_[0x12c]);
            }
            {
                const u64* keys = (const u64*)(base + 0x650);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), pane, this_[0x12d]);
            }
            {
                const u64* keys = (const u64*)(base + 0x638);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), pane, this_[0x12e]);
            }
            {
                const u64* keys = (const u64*)(base + 0x620);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), pane, this_[0x12f]);
            }
            {
                const u64* keys = (const u64*)(base + 0x608);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), pane, this_[0x130]);
            }
            {
                const u64* keys = (const u64*)(base + 0x5f0);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x38 + idx * 4), pane, this_[0x131]);
            }
            ((Fn5Fn)fn_80402B10)(*(void**)(this_ + 0x44 + *ord * 4), a, 0, lbl_80543498, lbl_80543458);
            fn_80402628(*(void**)(this_ + 0x44 + *ord * 4), a, 0, *(u8*)(*(u8**)(this_ + 0x44 + *ord * 4) + 0x28));
            idx = *ord;
            {
                const u64* keys = (const u64*)(base + 0x5d8);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x44 + idx * 4), pane, this_[0x118]);
            }
            {
                const u64* keys = (const u64*)(base + 0x5c0);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x44 + idx * 4), pane, this_[0x119]);
            }
            {
                const u64* keys = (const u64*)(base + 0x5a8);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x44 + idx * 4), pane, this_[0x11a]);
            }
            {
                const u64* keys = (const u64*)(base + 0x590);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x44 + idx * 4), pane, this_[0x11b]);
            }
            {
                const u64* keys = (const u64*)(base + 0x578);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x44 + idx * 4), pane, this_[0x11c]);
            }
            {
                const u64* keys = (const u64*)(base + 0x560);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x44 + idx * 4), pane, this_[0x11d]);
            }
            {
                const u64* keys = (const u64*)(base + 0x548);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x44 + idx * 4), pane, this_[0x11e]);
            }
            {
                const u64* keys = (const u64*)(base + 0x530);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x44 + idx * 4), pane, this_[0x11f]);
            }
            {
                const u64* keys = (const u64*)(base + 0x518);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x44 + idx * 4), pane, this_[0x120]);
            }
            {
                const u64* keys = (const u64*)(base + 0x500);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x44 + idx * 4), pane, this_[0x121]);
            }
            {
                const u64* keys = (const u64*)(base + 0x4e8);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x44 + idx * 4), pane, this_[0x122]);
            }
            {
                const u64* keys = (const u64*)(base + 0x4d0);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x44 + idx * 4), pane, this_[0x123]);
            }
            {
                const u64* keys = (const u64*)(base + 0x4b8);
                pane = (*(J2DPane**)(this_ + 8))->search(keys[idx]);
                fn_804023D0(*(void**)(this_ + 0x44 + idx * 4), pane, this_[0x124]);
            }
        }
        k++;
        off += b;
        ord++;
    } while (k < 2);

    if (*(s32*)(this_ + 0xa4) != 0 && *(s16*)(this_ + 0xd8) > c) {
        fn_80402940(*(void**)(this_ + 0x38 + *(s32*)(this_ + 0xa4) * 4), a,
                             *(f32*)(*(u8**)(this_ + 0x38) + 0xc) - *(f32*)(*(u8**)(this_ + 0x38 + *(s32*)(this_ + 0xa4) * 4) + 0xc), lbl_80543458, 0);
        fn_80402940(*(void**)(this_ + 0x44 + *(s32*)(this_ + 0xa4) * 4), a,
                             *(f32*)(*(u8**)(this_ + 0x44) + 0xc) - *(f32*)(*(u8**)(this_ + 0x44 + *(s32*)(this_ + 0xa4) * 4) + 0xc), lbl_80543458, 0);
    }
    if (*(s16*)(this_ + 0xd8) > total) {
        this_[0x112] = this_[0x110];
        this_[0x110] = 5;
    }
}
#pragma opt_strength_reduction reset
#pragma opt_propagation reset
extern "C" f32 lbl_805434A4;
extern "C" f32 lbl_805434A8;
extern "C" void fn_803BF3BC(u8* p);
extern "C" void fn_803BF698(u8* p);
extern "C" void fn_80402E08(void* a, f32 b, f32 c);
extern "C" void fn_8040245C(void* a, s32 b, s32 c, u8 d, s32 e);
extern "C" f64 lbl_80543468;
#pragma opt_propagation on
extern "C" void fn_803C4054(u8* p) {
    f32 zero;
    f32 v;
    s32 i;

    if (fn_80309C4C(lbl_8053AD30, 1, 1) != 0) {
        if (p[0x114] != 0) {
            p[0x114] = p[0x114] - 1;
            *(s16*)(p + 0xda) = 1;
            *(s16*)(*(u8**)(p + 0x34) + 0x26) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else {
        if (fn_80309C4C(lbl_8053AD30, 2, 1) != 0) {
            if (p[0x114] < 1) {
                p[0x114] = p[0x114] + 1;
                *(s16*)(p + 0xda) = 1;
                *(s16*)(*(u8**)(p + 0x34) + 0x26) = 0x1e;
                fn_80458880(lbl_8053AF80, 0x26, -1);
            }
        } else {
            if (fn_80309C4C(lbl_8053AD30, 0x100, 1) != 0) {
                if (p[0x114] == 0) {
                    fn_803BF3BC(p);
                    fn_80458880(lbl_8053AF80, 0xb, -1);
                } else {
                    *(s32*)(p + 0x80) = 0;
                    fn_803BF698(p);
                    fn_80458880(lbl_8053AF80, 0xc, -1);
                }
            }
        }
    }

    if (p[0x110] == 0x25) {
        v = lbl_80543458;
        if (*(s16*)(p + 0xda) != 0) {
            if (*(s16*)(p + 0xda) < 5) {
                v = lbl_805434A4 * (f32)(*(s16*)(p + 0xda) * *(s16*)(p + 0xda)) / lbl_805434A8;
                *(s16*)(p + 0xda) = *(s16*)(p + 0xda) + 1;
            } else if (*(s16*)(p + 0xda) < 10) {
                v = lbl_805434A4 * (f32)((10 - *(s16*)(p + 0xda)) * (10 - *(s16*)(p + 0xda))) / lbl_805434A8;
                *(s16*)(p + 0xda) = *(s16*)(p + 0xda) + 1;
            } else {
                *(s16*)(p + 0xda) = 0;
            }
        }
        zero = lbl_80543458;
        for (i = 0; i < 2; i++) {
            if (zero != v && i == p[0x114]) {
                fn_80402E08(*(void**)(p + 0x24 + i * 4), zero, v);
            } else {
                fn_80402E08(*(void**)(p + 0x24 + i * 4), lbl_80543458, lbl_80543458);
            }
        }
        fn_80402E08(*(void**)(p + 0x34), *(f32*)(((u8**)(p + 0x24))[p[0x114]] + 8) - *(f32*)(*(u8**)(p + 0x24) + 8), v);
        fn_8040245C(*(void**)(p + 0x34), 0x3c, 0, (*(u8**)(p + 0x34))[0x28], 1);
        fn_804023D0(*(void**)(p + 0x34), ((J2DPane*)*(void**)(p + 8))->search(0x5061636375723031ULL), (*(u8**)(p + 0x34))[0x28]);
    }
}
extern "C" void fn_803C4330(char* p) {
    s32 state;

    if (*(s32*)(p + 0xb0) > 0) {
        *(s32*)(p + 0xb0) = *(s32*)(p + 0xb0) - 1;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1300, 1) != 0 || *(s32*)(p + 0xb0) == 0) {
        *(s32*)(p + 0xb0) = -1;
        fn_803CE4CC(p);
        state = 0x117;
        if (lbl_8053AAF8[0x7f] != 0) {
            state = 0x116;
        }
        *(s32*)(p + 0x84) = state;
        fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(0x5466743031ULL)), *(s32*)(p + 0x84), 0, 0, 0);
        if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
            *(s32*)(p + 0xb0) = 0x5a;
        }
        fn_80402E08(*(void**)(p + 0x50), lbl_80543494, lbl_80543458);
        *(s16*)(*(char**)(p + 0x50) + 0x20) = 0;
        ((J2DPane*)*(void**)(*(u8**)(p + 0x50) + 4))->setAlpha(0);
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723031ULL), *(u8*)(*(char**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723032ULL), *(u8*)(*(char**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723033ULL), *(u8*)(*(char**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723034ULL), *(u8*)(*(char**)(p + 0x50) + 0x28));
        *(s16*)(*(char**)(p + 0x38) + 0x20) = 0;
        *(s16*)(*(char**)(p + 0x38) + 0x22) = 0;
        *(s16*)(*(char**)(p + 0x38) + 0x26) = 0;
        *(s16*)(*(char**)(p + 0x44) + 0x20) = 0;
        *(s16*)(*(char**)(p + 0x44) + 0x22) = 0;
        *(s16*)(*(char**)(p + 0x44) + 0x26) = 0;
        *(s16*)(*(char**)(p + 0x3c) + 0x20) = 0;
        *(s16*)(*(char**)(p + 0x3c) + 0x22) = 0;
        *(s16*)(*(char**)(p + 0x3c) + 0x26) = 0;
        *(s16*)(*(char**)(p + 0x48) + 0x20) = 0;
        *(s16*)(*(char**)(p + 0x48) + 0x22) = 0;
        *(s16*)(*(char**)(p + 0x48) + 0x26) = 0;
        *(s16*)(*(char**)(p + 0x40) + 0x20) = 0;
        *(s16*)(*(char**)(p + 0x40) + 0x22) = 0;
        *(s16*)(*(char**)(p + 0x40) + 0x26) = 0;
        *(s16*)(*(char**)(p + 0x4c) + 0x20) = 0;
        *(s16*)(*(char**)(p + 0x4c) + 0x22) = 0;
        *(s16*)(*(char**)(p + 0x4c) + 0x26) = 0;
        ((J2DPane*)*(void**)(*(u8**)(p + 0x34) + 4))->setAlpha(0);
        fn_804023D0(*(void**)(p + 0x34), ((J2DPane*)*(void**)(p + 8))->search(0x5061636375723031ULL), *(u8*)(*(char**)(p + 0x34) + 0x28));
        *(s16*)(p + 0xd8) = 0;
        *(s16*)(p + 0xda) = 0;
        p[0x112] = p[0x110];
        p[0x110] = 0x26;
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

extern "C" void fn_803C4628(u8* this_) {
    u8* cfg = lbl_8050DB0C;
    u8* tbl = (u8*)lbl_804765D0;
    s16 sVar2 = *(s16*)(cfg + 0x208);
    s16 sVar3 = *(s16*)(cfg + 0x20a);
    s32 iVar10 = sVar2 + sVar3;
    s16 sVar11 = *(s16*)(cfg + 0x210);
    s32 iVar6 = *(s16*)(cfg + 0x20c);
    s32 iVar8 = *(s16*)(cfg + 0x20e);
    s32 iVar7 = *(s16*)(cfg + 0x212);
    s32 iVar5;
    s32 cur;
    void* obj;

    if (sVar11 < iVar10) {
        sVar11 = iVar10;
    }
    iVar5 = iVar6 + iVar8;
    if (iVar5 < sVar11 + iVar7) {
        iVar5 = sVar11 + iVar7;
    }
    *(s16*)(this_ + 0xd8) += 1;
    if (*(s16*)(this_ + 0xd8) > sVar2 && *(s16*)(this_ + 0xd8) <= iVar10) {
        cur = *(s32*)(this_ + 0xa4);
        obj = *(void**)(this_ + 0x38 + cur * 4);
        fn_80402940(obj, sVar3, *(f32*)((u8*)*(void**)(this_ + 0x38) + 0xc) - *(f32*)((u8*)obj + 0xc),
                    *(f32*)((u8*)*(void**)(this_ + 0x40) + 0xc) - *(f32*)((u8*)obj + 0xc), 0);
        obj = *(void**)(this_ + 0x38 + cur * 4);
        fn_80402628(obj, sVar3, *(u8*)((u8*)obj + 0x28), 0);
        setCellT(this_, tbl, 0x38, cur, 0x780, *(u8*)(this_ + 0x125));
        setCellT(this_, tbl, 0x38, cur, 0x768, *(u8*)(this_ + 0x126));
        setCellT(this_, tbl, 0x38, cur, 0x750, *(u8*)(this_ + 0x127));
        setCellT(this_, tbl, 0x38, cur, 0x6c8, *(u8*)(this_ + 0x128));
        setCellT(this_, tbl, 0x38, cur, 0x6b0, *(u8*)(this_ + 0x129));
        setCellT(this_, tbl, 0x38, cur, 0x698, *(u8*)(this_ + 0x12a));
        setCellT(this_, tbl, 0x38, cur, 0x680, *(u8*)(this_ + 0x12b));
        setCellT(this_, tbl, 0x38, cur, 0x668, *(u8*)(this_ + 0x12c));
        setCellT(this_, tbl, 0x38, cur, 0x650, *(u8*)(this_ + 0x12d));
        setCellT(this_, tbl, 0x38, cur, 0x638, *(u8*)(this_ + 0x12e));
        setCellT(this_, tbl, 0x38, cur, 0x620, *(u8*)(this_ + 0x12f));
        setCellT(this_, tbl, 0x38, cur, 0x608, *(u8*)(this_ + 0x130));
        setCellT(this_, tbl, 0x38, cur, 0x5f0, *(u8*)(this_ + 0x131));
    }
    if (*(s16*)(this_ + 0xd8) == iVar10) {
        obj = *(void**)(this_ + 0x38 + *(s32*)(this_ + 0xa4) * 4);
        fn_80402E08(obj, lbl_80543498, *(f32*)((u8*)*(void**)(this_ + 0x38) + 0xc) - *(f32*)((u8*)obj + 0xc));
        *(s16*)((u8*)obj + 0x20) = 0;
        {
            void* sub = *(void**)((u8*)obj + 4);
            (*(VtSlot9**)sub)->v9(sub, 0);
        }
        cur = *(s32*)(this_ + 0xa4);
        setCellT(this_, tbl, 0x38, cur, 0x780, *(u8*)(this_ + 0x125));
        setCellT(this_, tbl, 0x38, cur, 0x768, *(u8*)(this_ + 0x126));
        setCellT(this_, tbl, 0x38, cur, 0x750, *(u8*)(this_ + 0x127));
        setCellT(this_, tbl, 0x38, cur, 0x6c8, *(u8*)(this_ + 0x128));
        setCellT(this_, tbl, 0x38, cur, 0x6b0, *(u8*)(this_ + 0x129));
        setCellT(this_, tbl, 0x38, cur, 0x698, *(u8*)(this_ + 0x12a));
        setCellT(this_, tbl, 0x38, cur, 0x680, *(u8*)(this_ + 0x12b));
        setCellT(this_, tbl, 0x38, cur, 0x668, *(u8*)(this_ + 0x12c));
        setCellT(this_, tbl, 0x38, cur, 0x650, *(u8*)(this_ + 0x12d));
        setCellT(this_, tbl, 0x38, cur, 0x638, *(u8*)(this_ + 0x12e));
        setCellT(this_, tbl, 0x38, cur, 0x620, *(u8*)(this_ + 0x12f));
        setCellT(this_, tbl, 0x38, cur, 0x608, *(u8*)(this_ + 0x130));
        setCellT(this_, tbl, 0x38, cur, 0x5f0, *(u8*)(this_ + 0x131));
        *(s16*)(*(u8**)(this_ + 0x38 + cur * 4) + 0x26) = 0;
        *(s32*)(this_ + 0x84) = 0x60;
        ((void* (*)(void*, u32, u32, u32))(*(void***)(*(u8**)(this_ + 8)))[15])(*(void**)(this_ + 8), cur * 4, 0x54, 0x66743031);
        {
            char* s = getStringPtr__10J2DTextBoxCFv(0);
            fn_803832BC(s, *(s32*)(this_ + 0x84), 0, 0, 0);
        }
        if (*(s32*)(this_ + 0x84) == 0x60 || *(s32*)(this_ + 0x84) == 0x64) {
            *(s32*)(this_ + 0xb0) = 0x5a;
        }
        fn_803CE4CC((char*)this_);
        *(s32*)(this_ + 0x80) = 0;
    }
    if (this_[0x115] & (u8)(1 << *(s32*)(this_ + 0xa4))) {
        f32 t = (f32)(*(s16*)(this_ + 0xd8) - sVar2) / (f32)sVar3;
        fn_803BC6F0((char*)this_, cur, lbl_80543478 - t);
    }
    if (iVar6 < *(s16*)(this_ + 0xd8)) {
        setFade(*(void**)(this_ + 0x20), iVar8, 0, lbl_80543458, lbl_80543498);
    }
    if (iVar5 < *(s16*)(this_ + 0xd8)) {
        this_[0x112] = this_[0x110];
        this_[0x110] = 0x24;
    }
}

#pragma opt_strength_reduction off
extern "C" void fn_803C5190(u8* p) {
    u8* tbl = lbl_8050DB0C;
    u8* base = (u8*)lbl_804765D0;
    s16 a = *(s16*)(tbl + 0x21c);
    s32 b = *(s16*)(tbl + 0x21e);
    s16 f = *(s16*)(tbl + 0x226);
    s32 sum = a + b;
    s32 d = *(s16*)(tbl + 0x222);
    s32 e = *(s16*)(tbl + 0x224);
    s32 c = *(s16*)(tbl + 0x220);
    s32 g = *(s16*)(tbl + 0x228);
    s32 lim = c + d + e;
    u8* keys;
    s32 i;
    u8* q;

    if (f < sum) {
        f = sum;
    }
    if (lim < f + g) {
        lim = f + g;
    }

    *(s16*)(p + 0xd8) += 1;
    if (*(s16*)(p + 0xd8) > a && *(s16*)(p + 0xd8) <= sum) {
        if ((p[0x115] & ((1 << *(u32*)(p + 0xa4)) & 0xff)) != 0) {
            setFade(*(void**)(p + 0x20), b, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + 0x20), b, ((u8*)*(void**)(p + 0x20))[0x28], 0);
            keys=base+0x368;
            {
                u8* walker = keys;
                for(int j=0;j<9;j++,walker+=8) {
                    void* obj=((J2DPane*)*(void**)(p+4))->search(*(u64*)walker);
                    fn_804023D0(*(void**)(p+0x20),obj,p[0x196+j]);
                }
            }
            if (*(s16*)(p + 0xd8) == sum) {
                fn_80402E08(*(void**)(p + 0x20), lbl_80543498, lbl_80543458);
                *(s16*)(*(u8**)(p + 0x20) + 0x20) = 0;
                ((PaneObjVt*)*(void**)(*(u8**)(p + 0x20) + 4))->v9(0);
                for(int j=0;j<9;j++,keys+=8) {
                    void* obj=((J2DPane*)*(void**)(p+4))->search(*(u64*)keys);
                    fn_804023D0(*(void**)(p+0x20),obj,p[0x196+j]);
                }
                *(s16*)(*(u8**)(p + 0x20) + 0x26) = 0;
            }
        } else {
            setFade(*(void**)(p + 0x14), b, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + 0x14), b, ((u8*)*(void**)(p + 0x14))[0x28], 0);
            setFade(*(void**)(p + 0x18), b, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + 0x18), b, ((u8*)*(void**)(p + 0x18))[0x28], 0);
            setFade(*(void**)(p + 0x1c), b, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + 0x1c), b, ((u8*)*(void**)(p + 0x1c))[0x28], 0);
            setKeyedAt(p, 4, 0x14, base + 0x48, 0x51, 0x132);
            setKeyedAt(p, 8, 0x14, base + 0x2d0, 0x13, 0x183);
        }
        if (*(s16*)(p + 0xd8) == sum) {
            *(s32*)(p + 0x84) = 0x5f;
            void* s = ((J2DPane*)*(void**)(p+8))->search(0x5466743031ULL);
            char* str = getStringPtr__10J2DTextBoxCFv(s);
            fn_803832BC(str, *(s32*)(p + 0x84), 0, 0, 0);
            if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
                *(s32*)(p + 0xb0) = 0x5a;
            }
            s = ((J2DPane*)*(void**)(p+4))->search(0x5464623031ULL);
            str = getStringPtr__10J2DTextBoxCFv(s);
            fn_803832BC(str, 0x67, 0, 0, 0);
        }
    }

    q = p;
    i = 0;
    sum = 0;
    for (; i < 2; i++) {
        if (*(s16*)(p + 0xd8) > c + sum) {
            fn_80402940(*(void**)(q + 0x24), d, lbl_80543458, lbl_8054349C, 0);
            fn_80402628(*(void**)(q + 0x24), d, ((u8*)*(void**)(q + 0x24))[0x28], 0);
            switch (i) {
            case 0:
                drawTextRow(p, q, base + 0x7f8);
                break;
            case 1:
                drawTextRow(p, q, base + 0x7d8);
                break;
            case 2:
                drawTextRow(p, q, base + 0x7b8);
                break;
            case 3:
                drawTextRow(p, q, base + 0x798);
                break;
            }
        }
        sum += e;
        q += 4;
    }

    if (*(s16*)(p + 0xd8) > f) {
        setFade(*(void**)(p + 0x20), g, 0, lbl_80543498, lbl_80543458);
        fn_80402628(*(void**)(p + 0x20), g, 0, ((u8*)*(void**)(p + 0x20))[0x28]);
        setKeyedAt(p, 4, 0x20, base + 0x368, 9, 0x196);
    }

    if (*(s16*)(p + 0xd8) > lim) {
        fn_803B933C(lbl_8050EC80, *(void**)(p + 0x5c), *(u32*)(p + 0xa4));
        fn_803BACF8(*(void**)(p + 0x5c), (u8)*(u32*)(p + 0xa4));
        fn_803B9CCC(lbl_8051C1A0, *(void**)(p + 0x5c), 0x258, 0);
        p[0x112] = p[0x110];
        p[0x110] = 0x21;
    }
}
#pragma opt_strength_reduction reset
extern "C" void fn_803C579C(char* this_) {
    s32 r = fn_803B9BDC(lbl_8051C1A0);
    if (r == 2) {
        *(u32*)(this_ + 0x84) = 0;
        *(u32*)(this_ + 0x80) = 0x68;
        *(u8*)(this_ + 0x112) = *(u8*)(this_ + 0x110);
        *(u8*)(this_ + 0x110) = 0;
    } else if (r == 1) {
        fn_803BF004(this_);
    }
}

extern "C" void fn_803C5808(u8* p) {
    s32 list[2];
    s32 off;
    s32 thr;
    s32* lp;
    s32 a = *(s16*)(lbl_8050DB0C + 0x17c);
    s32 b = *(s16*)(lbl_8050DB0C + 0x17e);
    s32 c = *(s16*)(lbl_8050DB0C + 0x180);
    s32 d = *(s16*)(lbl_8050DB0C + 0x182);
    s32 e = *(s16*)(lbl_8050DB0C + 0x184);

    thr = a + (b + c);
    if (thr < d + e) {
        thr = d + e;
    }
    {
        s32 f = *(s16*)(lbl_8050DB0C + 0x186);
        s32 g = *(s16*)(lbl_8050DB0C + 0x188);
        s32 h = *(s16*)(lbl_8050DB0C + 0x18a);
        if (thr < f + (g + h * 3)) {
            thr = f + (g + h * 3);
        }
    }

    lp = list;
    if (*(s32*)(p + 0xa4) != 0) {
        *lp = 0;
        lp++;
    }
    if (*(s32*)(p + 0xa4) != 1) {
        *lp = 1;
        lp++;
    }
    if (*(s32*)(p + 0xa4) != 2) {
        *lp = 2;
    }

    *(s16*)(p + 0xd8) = *(s16*)(p + 0xd8) + 1;
    lp = list;
    off = 0;
    do {
        if (*(s16*)(p + 0xd8) > a + off) {
            s32 k = *lp;
            setFade(*(void**)(p + k * 4 + 0x38), b, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + k * 4 + 0x38), b, *(u8*)(*(u8**)(p + k * 4 + 0x38) + 0x28), 0);
            setCell(p, 0x38, k, 0x780, p[0x125]);
            setCell(p, 0x38, k, 0x768, p[0x126]);
            setCell(p, 0x38, k, 0x750, p[0x127]);
            setCell(p, 0x38, k, 0x6c8, p[0x128]);
            setCell(p, 0x38, k, 0x6b0, p[0x129]);
            setCell(p, 0x38, k, 0x698, p[0x12a]);
            setCell(p, 0x38, k, 0x680, p[0x12b]);
            setCell(p, 0x38, k, 0x668, p[0x12c]);
            setCell(p, 0x38, k, 0x650, p[0x12d]);
            setCell(p, 0x38, k, 0x638, p[0x12e]);
            setCell(p, 0x38, k, 0x620, p[0x12f]);
            setCell(p, 0x38, k, 0x608, p[0x130]);
            setCell(p, 0x38, k, 0x5f0, p[0x131]);

            setFade(*(void**)(p + k * 4 + 0x44), b, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + k * 4 + 0x44), b, *(u8*)(*(u8**)(p + k * 4 + 0x44) + 0x28), 0);
            setCell(p, 0x44, k, 0x5d8, p[0x118]);
            setCell(p, 0x44, k, 0x5c0, p[0x119]);
            setCell(p, 0x44, k, 0x5a8, p[0x11a]);
            setCell(p, 0x44, k, 0x590, p[0x11b]);
            setCell(p, 0x44, k, 0x578, p[0x11c]);
            setCell(p, 0x44, k, 0x560, p[0x11d]);
            setCell(p, 0x44, k, 0x548, p[0x11e]);
            setCell(p, 0x44, k, 0x530, p[0x11f]);
            setCell(p, 0x44, k, 0x518, p[0x120]);
            setCell(p, 0x44, k, 0x500, p[0x121]);
            setCell(p, 0x44, k, 0x4e8, p[0x122]);
            setCell(p, 0x44, k, 0x4d0, p[0x123]);
            setCell(p, 0x44, k, 0x4b8, p[0x124]);
        }
        lp++;
        off += c;
    } while (lp < list + 2);

    if (*(s32*)(p + 0xa4) != 0 && *(s16*)(p + 0xd8) > a) {
        fn_80402940(*(void**)(p + *(s32*)(p + 0xa4) * 4 + 0x38), b, lbl_80543458,
                    *(f32*)(*(u8**)(p + 0x38) + 0xc) - *(f32*)(*(u8**)(p + *(s32*)(p + 0xa4) * 4 + 0x38) + 0xc), 0);
        fn_80402940(*(void**)(p + *(s32*)(p + 0xa4) * 4 + 0x44), b, lbl_80543458,
                    *(f32*)(*(u8**)(p + 0x44) + 0xc) - *(f32*)(*(u8**)(p + *(s32*)(p + 0xa4) * 4 + 0x44) + 0xc), 0);
    }

    if (*(s16*)(p + 0xd8) > d) {
        setFade(*(void**)(p + 0x20), e, 0, lbl_80543498, lbl_80543458);
        fn_80402628(*(void**)(p + 0x20), e, 0, *(u8*)(*(u8**)(p + 0x20) + 0x28));
        setKeyedAt(p, 4, 0x20, (u8*)lbl_804765D0 + 0x368, 9, 0x196);
    }
}

#pragma opt_strength_reduction off
extern "C" void fn_803C61C4(u8* p) {
    s16 sVar;
    s32 E;
    s32 F;
    u8* tbl;
    s32 off;
    u8* q;
    s32 B;
    s32 C;
    s32 hi;
    s16 A;
    s32 i;
    s32 EF;
    s32 start;
    s32 j;
    s32 lo;
    s32 n;

    tbl = (u8*)lbl_804765D0;
    A = *(s16*)(lbl_8050DB0C + 0x1e2);
    B = *(s16*)(lbl_8050DB0C + 0x1e4);
    C = *(s16*)(lbl_8050DB0C + 0x1e0);
    sVar = *(s16*)(lbl_8050DB0C + 0x1e6);
    E = *(s16*)(lbl_8050DB0C + 0x1e8);
    F = *(s16*)(lbl_8050DB0C + 0x1ea);
    n = B + A;
    n += 1;
    n += C;
    if (sVar < n) {
        sVar = n;
    }
    start = sVar;
    EF = E + F;
    EF += start;
    *(s16*)(p + 0xd8) += 1;
    if (p[0x112] != 5) {
        q = p;
        off = 0;
        for (i = 0; i < 4; i++) {
            lo = C + off;
            if (*(s16*)(p + 0xd8) > lo && *(s16*)(p + 0xd8) <= (hi = A + lo)) {
                fn_80402940(*(void**)(q + 0x24), A, lbl_80543458, lbl_8054349C, 0);
                fn_80402628(*(void**)(q + 0x24), A, *(u8*)(*(u8**)(q + 0x24) + 0x28), 0);
                switch (i) {
                case 0:
                    {
                        s32 k = 0;
                        u8* t = tbl + 0x7f8;
                        for (; k < 4; ++k, t += 8) {
                            void* object = *(void**)(p + 8);
                            void* result = ((J2DPane*)object)->search(*(u64*)t);
                            fn_804023D0(*(void**)(q + 0x24), result, p[k + 0x19f]);
                        }
                    }
                    break;
                case 1:
                    {
                        s32 k = 0;
                        u8* t = tbl + 0x7d8;
                        for (; k < 4; ++k, t += 8) {
                            void* object = *(void**)(p + 8);
                            void* result = (*(TextBoxVt15**)object)->v15(object, *(u64*)t);
                            fn_804023D0(*(void**)(q + 0x24), result, p[k + 0x19f]);
                        }
                    }
                    break;
                case 2:
                    {
                        s32 k = 0;
                        u8* t = tbl + 0x7b8;
                        for (; k < 4; ++k, t += 8) {
                            void* object = *(void**)(p + 8);
                            void* result = (*(TextBoxVt15**)object)->v15(object, *(u64*)t);
                            fn_804023D0(*(void**)(q + 0x24), result, p[k + 0x19f]);
                        }
                    }
                    break;
                case 3:
                    {
                        s32 k = 0;
                        u8* t = tbl + 0x798;
                        for (; k < 4; ++k, t += 8) {
                            void* object = *(void**)(p + 8);
                            void* result = (*(TextBoxVt15**)object)->v15(object, *(u64*)t);
                            fn_804023D0(*(void**)(q + 0x24), result, p[k + 0x19f]);
                        }
                    }
                    break;
                }
                if (*(s16*)(p + 0xd8) == hi) {
                    if (i == 0) {
                        char* s = getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 0x8))->search( 0x547374723031ULL));
                        fn_803832BC(s, 0x11e, 0, 0, 0);
                        *(s16*)(*(u8**)(q + 0x24) + 0x22) = 0;
                        *(s16*)(*(u8**)(q + 0x24) + 0x26) = 0;
                    } else if (i == 1) {
                        char* s = getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 0x8))->search( 0x54636F703031ULL));
                        fn_803832BC(s, 0x11f, 0, 0, 0);
                        *(s16*)(*(u8**)(q + 0x24) + 0x22) = 0;
                        *(s16*)(*(u8**)(q + 0x24) + 0x26) = 0;
                    }
                }
            }
            off += B;
            q += 4;
        }
    }

    q = p;
    off = 0;
    for (j = 0; j < 2; j++) {
        if (*(s16*)(p + 0xd8) > start + off) {
            fn_80402940(*(void**)(q + 0x24), E, lbl_8054349C, lbl_80543458, 0);
            fn_80402628(*(void**)(q + 0x24), E, 0, *(u8*)(*(u8**)(q + 0x24) + 0x28));
            switch (j) {
            case 0:
                {
                        s32 k = 0;
                        u8* t = tbl + 0x7f8;
                        for (; k < 4; ++k, t += 8) {
                            void* object = *(void**)(p + 8);
                            void* result = (*(TextBoxVt15**)object)->v15(object, *(u64*)t);
                            fn_804023D0(*(void**)(q + 0x24), result, p[k + 0x19f]);
                        }
                    }
                break;
            case 1:
                {
                        s32 k = 0;
                        u8* t = tbl + 0x7d8;
                        for (; k < 4; ++k, t += 8) {
                            void* object = *(void**)(p + 8);
                            void* result = (*(TextBoxVt15**)object)->v15(object, *(u64*)t);
                            fn_804023D0(*(void**)(q + 0x24), result, p[k + 0x19f]);
                        }
                    }
                break;
            case 2:
                {
                        s32 k = 0;
                        u8* t = tbl + 0x7b8;
                        for (; k < 4; ++k, t += 8) {
                            void* object = *(void**)(p + 8);
                            void* result = (*(TextBoxVt15**)object)->v15(object, *(u64*)t);
                            fn_804023D0(*(void**)(q + 0x24), result, p[k + 0x19f]);
                        }
                    }
                break;
            case 3:
                {
                        s32 k = 0;
                        u8* t = tbl + 0x798;
                        for (; k < 4; ++k, t += 8) {
                            void* object = *(void**)(p + 8);
                            void* result = (*(TextBoxVt15**)object)->v15(object, *(u64*)t);
                            fn_804023D0(*(void**)(q + 0x24), result, p[k + 0x19f]);
                        }
                    }
                break;
            }
        }
        off += F;
        q += 4;
    }
    if (*(s16*)(p + 0xd8) > EF) {
        p[0x112] = p[0x110];
        p[0x110] = 0x25;
    }
}
#pragma opt_strength_reduction reset
extern "C" u8 lbl_8050DB0C[];
extern "C" u8 fn_80402940(void* p, s32 id, f32 a, f32 b, s32 c);
extern "C" void fn_803BC6F0(char* this_, u32 a, f32 t);
extern "C" void fn_803C6690(char* p) {
    s16 start = *(s16*)(lbl_8050DB0C + 0x1cc);
    s16 dur = *(s16*)(lbl_8050DB0C + 0x1ce);
    s32 end = start + dur;
    s32 i;
    *(s16*)(p + 0xd8) += 1;
    if (*(s16*)(p + 0xd8) > start) {
        for (i = 0; i < 3; i++) {
            fn_80402940(*(void**)(p + 0x38 + i * 4), dur, *(f32*)(p + 0x70 + i * 4), 0.0f, 0);
            fn_80402940(*(void**)(p + 0x44 + i * 4), dur, *(f32*)(p + 0x64 + i * 4), 0.0f, 0);
        }
        fn_803BC6F0(p, *(u32*)(p + 0xa4), 1.0f - (f32)(*(s16*)(p + 0xd8) - start) / (f32)dur);
    }
    if (*(s16*)(p + 0xd8) > end) {
        p[0x112] = p[0x110];
        p[0x110] = 5;
    }
}

extern "C" void fn_803C6798(u8* p) {
    u8* base = (u8*)lbl_804765D0;
    s16 t1b8 = *(s16*)(lbl_8050DB0C + 0x1b8);
    s16 t1ba = *(s16*)(lbl_8050DB0C + 0x1ba);
    s16 t1c2 = *(s16*)(lbl_8050DB0C + 0x1c2);
    s16 t1c4 = *(s16*)(lbl_8050DB0C + 0x1c4);
    s32 m = t1b8 + t1ba;
    tu803C_max(&m, *(s16*)(lbl_8050DB0C + 0x1bc) + *(s16*)(lbl_8050DB0C + 0x1be) + *(s16*)(lbl_8050DB0C + 0x1c0));
    tu803C_max(&m, t1c2 + t1c4);
    (*(s16*)(p + 0xd8))++;
    if (*(s16*)(p + 0xd8) > t1b8) {
        s32 j;
        u8* kq;
        fn_80402E08(*(void**)(p + 0x14), lbl_80543458, *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + 0x38) + 0xc));
        setFade(*(void**)(p + 0x14), t1ba, 0, lbl_80543458, lbl_80543498);
        fn_80402628(*(void**)(p + 0x14), t1ba, (*(u8**)(p + 0x14))[0x28], 0);
        fn_80402E08(*(void**)(p + 0x18), lbl_80543458, *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + 0x38) + 0xc));
        setFade(*(void**)(p + 0x18), t1ba, 0, lbl_80543458, lbl_80543498);
        fn_80402628(*(void**)(p + 0x18), t1ba, (*(u8**)(p + 0x18))[0x28], 0);
        fn_80402E08(*(void**)(p + 0x1c), lbl_80543458, *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + 0x38) + 0xc));
        setFade(*(void**)(p + 0x1c), t1ba, 0, lbl_80543458, lbl_80543498);
        fn_80402628(*(void**)(p + 0x1c), t1ba, (*(u8**)(p + 0x1c))[0x28], 0);
        for (j = 0, kq = base + 0x48; j < 0x51; j++, kq += 8) {
            fn_804023D0(*(void**)(p + 0x14), keyObj(*(void**)(p + 4), *(u64*)kq), p[0x132 + j]);
        }
        for (j = 0, kq = base + 0x2d0; j < 0x13; j++, kq += 8) {
            fn_804023D0(*(void**)(p + 0x14), keyObj(*(void**)(p + 8), *(u64*)kq), p[0x183 + j]);
        }
    }
    if (*(s16*)(p + 0xd8) > t1c2) {
        s32 i;
        for (i = 0; i < 3; i++) {
            if (i != *(s32*)(p + 0xa4) && i != *(s32*)(p + 0xa0)) {
                fn_80402E08(*(void**)(p + i * 4 + 0x38), lbl_80543458, lbl_80543458);
                fn_80402E08(*(void**)(p + i * 4 + 0x44), lbl_80543458, lbl_80543458);
                setFade(*(void**)(p + i * 4 + 0x38), t1c4, 0, lbl_80543498, lbl_80543458);
                fn_80402628(*(void**)(p + i * 4 + 0x38), t1c4, 0, (*(u8**)(p + i * 4 + 0x38))[0x28]);
                tu803C_setCell2(p, base, 0x38, i, 0x780, 0x125);
                tu803C_setCell2(p, base, 0x38, i, 0x768, 0x126);
                tu803C_setCell2(p, base, 0x38, i, 0x750, 0x127);
                tu803C_setCell2(p, base, 0x38, i, 0x6c8, 0x128);
                tu803C_setCell2(p, base, 0x38, i, 0x6b0, 0x129);
                tu803C_setCell2(p, base, 0x38, i, 0x698, 0x12a);
                tu803C_setCell2(p, base, 0x38, i, 0x680, 0x12b);
                tu803C_setCell2(p, base, 0x38, i, 0x668, 0x12c);
                tu803C_setCell2(p, base, 0x38, i, 0x650, 0x12d);
                tu803C_setCell2(p, base, 0x38, i, 0x638, 0x12e);
                tu803C_setCell2(p, base, 0x38, i, 0x620, 0x12f);
                tu803C_setCell2(p, base, 0x38, i, 0x608, 0x130);
                tu803C_setCell2(p, base, 0x38, i, 0x5f0, 0x131);
                setFade(*(void**)(p + i * 4 + 0x44), t1c4, 0, lbl_80543498, lbl_80543458);
                fn_80402628(*(void**)(p + i * 4 + 0x44), t1c4, 0, (*(u8**)(p + i * 4 + 0x44))[0x28]);
                tu803C_setCell2(p, base, 0x44, i, 0x5d8, 0x118);
                tu803C_setCell2(p, base, 0x44, i, 0x5c0, 0x119);
                tu803C_setCell2(p, base, 0x44, i, 0x5a8, 0x11a);
                tu803C_setCell2(p, base, 0x44, i, 0x590, 0x11b);
                tu803C_setCell2(p, base, 0x44, i, 0x578, 0x11c);
                tu803C_setCell2(p, base, 0x44, i, 0x560, 0x11d);
                tu803C_setCell2(p, base, 0x44, i, 0x548, 0x11e);
                tu803C_setCell2(p, base, 0x44, i, 0x530, 0x11f);
                tu803C_setCell2(p, base, 0x44, i, 0x518, 0x120);
                tu803C_setCell2(p, base, 0x44, i, 0x500, 0x121);
                tu803C_setCell2(p, base, 0x44, i, 0x4e8, 0x122);
                tu803C_setCell2(p, base, 0x44, i, 0x4d0, 0x123);
                tu803C_setCell2(p, base, 0x44, i, 0x4b8, 0x124);
            } else {
                fn_80402940(*(void**)(p + i * 4 + 0x38), t1c4, *(f32*)(p + i * 4 + 0x70), lbl_80543458, 0);
                fn_80402940(*(void**)(p + i * 4 + 0x44), t1c4, *(f32*)(p + i * 4 + 0x64), lbl_80543458, 0);
            }
        }
    }
    if (*(s16*)(p + 0xd8) > m) {
        p[0x112] = p[0x110];
        p[0x110] = 5;
    }
}

void fn_803C70B8(char* this_) {
    s16 s1b8 = *(s16*)(lbl_8050DB0C + 0x1b8);
    s16 s1ba = *(s16*)(lbl_8050DB0C + 0x1ba);
    s16 s1bc = *(s16*)(lbl_8050DB0C + 0x1bc);
    s16 s1be = *(s16*)(lbl_8050DB0C + 0x1be);
    s16 s1c0 = *(s16*)(lbl_8050DB0C + 0x1c0);
    s16 s1c2 = *(s16*)(lbl_8050DB0C + 0x1c2);
    s16 s1c4 = *(s16*)(lbl_8050DB0C + 0x1c4);
    s32 lim = s1b8 + s1ba;
    s32 t = s1bc + (s1be + s1c0);
    s16 frame;
    s32 i;

    if (lim < t) {
        lim = t;
    }
    t = s1c2 + s1c4;
    if (lim < t) {
        lim = t;
    }

    frame = *(s16*)(this_ + 0xd8) + 1;
    *(s16*)(this_ + 0xd8) = frame;
    if (frame > s1b8) {
        if ((u8)(1 << *(u32*)(this_ + 0xa0)) & *(u8*)(this_ + 0x115)) {
            startObj(this_, 0x20);
            for (i = 0; i < 9; i++) {
                void* o = ((KeyGetFn)(*(void***)(*(u8**)(this_ + 4)))[15])(*(void**)(this_ + 4), *(u64*)(lbl_804765D0 + 0x368 + i * 8));
                fn_804023D0(*(void**)(this_ + 0x20), o, *(u8*)(this_ + 0x196 + i));
            }
        } else {
            startObj(this_, 0x14);
            startObj(this_, 0x18);
            startObj(this_, 0x1c);
            for (i = 0; i < 0x51; i++) {
                void* o = ((KeyGetFn)(*(void***)(*(u8**)(this_ + 4)))[15])(*(void**)(this_ + 4), *(u64*)(lbl_804765D0 + 0x48 + i * 8));
                fn_804023D0(*(void**)(this_ + 0x14), o, *(u8*)(this_ + 0x132 + i));
            }
            for (i = 0; i < 0x13; i++) {
                void* o = ((KeyGetFn)(*(void***)(*(u8**)(this_ + 8)))[15])(*(void**)(this_ + 8), *(u64*)(lbl_804765D0 + 0x2d0 + i * 8));
                fn_804023D0(*(void**)(this_ + 0x14), o, *(u8*)(this_ + 0x183 + i));
            }
        }
    }
}

extern "C" void fn_803C1054(u8* p);
extern "C" void fn_803C02CC(u8* p);
extern "C" void fn_80402E08(void* a, f32 b, f32 c);
extern "C" void fn_8040245C(void* a, s32 b, s32 c, u8 d, s32 e);
extern "C" f32 lbl_805434A4;
extern "C" f32 lbl_805434A8;
extern "C" void fn_803C7CA0(u8* p) {
    s32 i;
    f32 f31;
    f32 f30;
    s16 t;
    if (fn_80309C4C(lbl_8053AD30, 1, 1) != 0) {
        if (p[0x114] != 0) {
            p[0x114] = p[0x114] - 1;
            *(s16*)(p + 0xda) = 1;
            *(s16*)(*(u8**)(p + 0x34) + 0x26) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else {
        if (fn_80309C4C(lbl_8053AD30, 2, 1) != 0) {
            if (p[0x114] < 1) {
                p[0x114] = p[0x114] + 1;
                *(s16*)(p + 0xda) = 1;
                *(s16*)(*(u8**)(p + 0x34) + 0x26) = 0x1e;
                fn_80458880(lbl_8053AF80, 0x26, -1);
            }
        } else {
            if (fn_80309C4C(lbl_8053AD30, 0x100, 1) != 0) {
                if (p[0x114] == 0) {
                    fn_803C1054(p);
                    fn_80458880(lbl_8053AF80, 0xb, -1);
                } else {
                    *(s32*)(p + 0x80) = 0;
                    fn_803C02CC(p);
                    fn_80458880(lbl_8053AF80, 0xc, -1);
                }
            }
        }
    }
    if (p[0x110] == 0x1b) {
        t = *(s16*)(p + 0xda);
        f30 = lbl_80543458;
        if (t != 0) {
            if (t < 5) {
                f30 = lbl_805434A4 * (f32)(t * t) / lbl_805434A8;
                *(s16*)(p + 0xda) = t + 1;
            } else if (t < 10) {
                f30 = lbl_805434A4 * (f32)((10 - t) * (10 - t)) / lbl_805434A8;
                *(s16*)(p + 0xda) = t + 1;
            } else {
                *(s16*)(p + 0xda) = 0;
            }
        }
        f31 = lbl_80543458;
        for (i = 0; i < 2; i++) {
            if (f31 != f30 && i == p[0x114]) {
                fn_80402E08(*(void**)(p + 0x24 + i * 4), f31, f30);
            } else {
                fn_80402E08(*(void**)(p + 0x24 + i * 4), lbl_80543458, lbl_80543458);
            }
        }
        {
            MenuSlots24* q = (MenuSlots24*)p;
            fn_80402E08(*(void**)(p + 0x34), *(f32*)(q->slot[p[0x114]] + 8) - *(f32*)(*(u8**)(p + 0x24) + 8), f30);
        }
        fn_8040245C(*(void**)(p + 0x34), 0x3c, 0, *(u8*)(*(u8**)(p + 0x34) + 0x28), 1);
        fn_804023D0(*(void**)(p + 0x34), ((KeyLookupVt*)*(void**)(p + 0x8))->v15(0x5061636375723031ULL), *(u8*)(*(u8**)(p + 0x34) + 0x28));
    }
}

extern "C" void fn_803C7F7C(u8* p) {
    u8* base = (u8*)lbl_804765D0;
    s32 t1a4 = *(s16*)(lbl_8050DB0C + 0x1a4);
    s32 t1a6 = *(s16*)(lbl_8050DB0C + 0x1a6);
    s16 t1aa = *(s16*)(lbl_8050DB0C + 0x1aa);
    s32 t1ac = *(s16*)(lbl_8050DB0C + 0x1ac);
    s16 t1ae = *(s16*)(lbl_8050DB0C + 0x1ae);
    s32 t1a8 = *(s16*)(lbl_8050DB0C + 0x1a8);
    s32 t1b0 = *(s16*)(lbl_8050DB0C + 0x1b0);
    s32 m = t1a4 + t1a6;
    s32 i;
    tu803C_max(&m, t1a8 + (t1aa + t1ac));
    tu803C_max(&m, t1ae + t1b0);
    (*(s16*)(p + 0xd8))++;
    if (*(s16*)(p + 0xd8) > t1a4) {
        s32 j;
        u8* kq;
        if ((u8)(1 << *(u32*)(p + 0xa0)) & p[0x115]) {
            fn_80402E08(*(void**)(p + 0x20), lbl_80543458, *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + 0x38) + 0xc));
            setFade(*(void**)(p + 0x20), t1a6, 0, lbl_80543498, lbl_80543458);
            fn_80402628(*(void**)(p + 0x20), t1a6, 0, (*(u8**)(p + 0x20))[0x28]);
            for (j = 0, kq = base + 0x368; j < 9; j++, kq += 8) {
                fn_804023D0(*(void**)(p + 0x20), keyObj(*(void**)(p + 4), *(u64*)kq), p[0x196 + j]);
            }
        } else {
            fn_80402E08(*(void**)(p + 0x14), lbl_80543458, *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + 0x38) + 0xc));
            setFade(*(void**)(p + 0x14), t1a6, 0, lbl_80543498, lbl_80543458);
            fn_80402628(*(void**)(p + 0x14), t1a6, 0, (*(u8**)(p + 0x14))[0x28]);
            fn_80402E08(*(void**)(p + 0x18), lbl_80543458, *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + 0x38) + 0xc));
            setFade(*(void**)(p + 0x18), t1a6, 0, lbl_80543498, lbl_80543458);
            fn_80402628(*(void**)(p + 0x18), t1a6, 0, (*(u8**)(p + 0x18))[0x28]);
            fn_80402E08(*(void**)(p + 0x1c), lbl_80543458, *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + 0x38) + 0xc));
            setFade(*(void**)(p + 0x1c), t1a6, 0, lbl_80543498, lbl_80543458);
            fn_80402628(*(void**)(p + 0x1c), t1a6, 0, (*(u8**)(p + 0x1c))[0x28]);
            for (j = 0, kq = base + 0x48; j < 0x51; j++, kq += 8) {
                fn_804023D0(*(void**)(p + 0x14), keyObj(*(void**)(p + 4), *(u64*)kq), p[0x132 + j]);
            }
            for (j = 0, kq = base + 0x2d0; j < 0x13; j++, kq += 8) {
                fn_804023D0(*(void**)(p + 0x14), keyObj(*(void**)(p + 8), *(u64*)kq), p[0x183 + j]);
            }
        }
    }
    {
        u8* q = p;
        s32 k = 0;
        for (i = 0; i < 2; i++, k += t1ac, q += 4) {
            if (*(s16*)(p + 0xd8) > t1a8 + k) {
                s32 j;
                u8* kq;
                fn_80402940(*(void**)(q + 0x24), t1aa, lbl_8054349C, lbl_80543458, 0);
                fn_80402628(*(void**)(q + 0x24), t1aa, 0, (*(u8**)(q + 0x24))[0x28]);
                switch (i) {
                case 0:
                    for (j = 0, kq = base + 0x7f8; j < 4; j++, kq += 8) {
                        fn_804023D0(*(void**)(q + 0x24), keyObj(*(void**)(p + 8), *(u64*)kq), p[0x19f + j]);
                    }
                    break;
                case 1:
                    for (j = 0, kq = base + 0x7d8; j < 4; j++, kq += 8) {
                        fn_804023D0(*(void**)(q + 0x24), keyObj(*(void**)(p + 8), *(u64*)kq), p[0x19f + j]);
                    }
                    break;
                case 2:
                    for (j = 0, kq = base + 0x7b8; j < 4; j++, kq += 8) {
                        fn_804023D0(*(void**)(q + 0x24), keyObj(*(void**)(p + 8), *(u64*)kq), p[0x19f + j]);
                    }
                    break;
                case 3:
                    for (j = 0, kq = base + 0x798; j < 4; j++, kq += 8) {
                        fn_804023D0(*(void**)(q + 0x24), keyObj(*(void**)(p + 8), *(u64*)kq), p[0x19f + j]);
                    }
                    break;
                }
            }
        }
    }
    for (i = 0; i < 3; i++) {
        if (i != *(s32*)(p + 0xa4)) {
            if (i != *(s32*)(p + 0xa0)) {
                if (*(s16*)(p + 0xd8) > t1ae) {
                    fn_80402E08(*(void**)(p + i * 4 + 0x38), lbl_80543458, *(f32*)(p + i * 4 + 0x70));
                    fn_80402E08(*(void**)(p + i * 4 + 0x44), lbl_80543458, *(f32*)(p + i * 4 + 0x64));
                    setFade(*(void**)(p + i * 4 + 0x38), t1b0, 0, lbl_80543458, lbl_80543498);
                    fn_80402628(*(void**)(p + i * 4 + 0x38), t1b0, (*(u8**)(p + i * 4 + 0x38))[0x28], 0);
                    tu803C_setCell2(p, base, 0x38, i, 0x780, 0x125);
                    tu803C_setCell2(p, base, 0x38, i, 0x768, 0x126);
                    tu803C_setCell2(p, base, 0x38, i, 0x750, 0x127);
                    tu803C_setCell2(p, base, 0x38, i, 0x6c8, 0x128);
                    tu803C_setCell2(p, base, 0x38, i, 0x6b0, 0x129);
                    tu803C_setCell2(p, base, 0x38, i, 0x698, 0x12a);
                    tu803C_setCell2(p, base, 0x38, i, 0x680, 0x12b);
                    tu803C_setCell2(p, base, 0x38, i, 0x668, 0x12c);
                    tu803C_setCell2(p, base, 0x38, i, 0x650, 0x12d);
                    tu803C_setCell2(p, base, 0x38, i, 0x638, 0x12e);
                    tu803C_setCell2(p, base, 0x38, i, 0x620, 0x12f);
                    tu803C_setCell2(p, base, 0x38, i, 0x608, 0x130);
                    tu803C_setCell2(p, base, 0x38, i, 0x5f0, 0x131);
                    setFade(*(void**)(p + i * 4 + 0x44), t1b0, 0, lbl_80543458, lbl_80543498);
                    fn_80402628(*(void**)(p + i * 4 + 0x44), t1b0, (*(u8**)(p + i * 4 + 0x44))[0x28], 0);
                    tu803C_setCell2(p, base, 0x44, i, 0x5d8, 0x118);
                    tu803C_setCell2(p, base, 0x44, i, 0x5c0, 0x119);
                    tu803C_setCell2(p, base, 0x44, i, 0x5a8, 0x11a);
                    tu803C_setCell2(p, base, 0x44, i, 0x590, 0x11b);
                    tu803C_setCell2(p, base, 0x44, i, 0x578, 0x11c);
                    tu803C_setCell2(p, base, 0x44, i, 0x560, 0x11d);
                    tu803C_setCell2(p, base, 0x44, i, 0x548, 0x11e);
                    tu803C_setCell2(p, base, 0x44, i, 0x530, 0x11f);
                    tu803C_setCell2(p, base, 0x44, i, 0x518, 0x120);
                    tu803C_setCell2(p, base, 0x44, i, 0x500, 0x121);
                    tu803C_setCell2(p, base, 0x44, i, 0x4e8, 0x122);
                    tu803C_setCell2(p, base, 0x44, i, 0x4d0, 0x123);
                    tu803C_setCell2(p, base, 0x44, i, 0x4b8, 0x124);
                }
            } else if (*(s16*)(p + 0xd8) > t1ae) {
                fn_80402940(*(void**)(p + i * 4 + 0x38), t1b0, *(f32*)(p + i * 4 + 0x70),
                            *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + i * 4 + 0x38) + 0xc), 0);
                fn_80402940(*(void**)(p + i * 4 + 0x44), t1b0, *(f32*)(p + i * 4 + 0x64),
                            *(f32*)(*(u8**)(p + 0x48) + 0xc) - *(f32*)(*(u8**)(p + i * 4 + 0x44) + 0xc), 0);
            }
        }
    }
    if (*(s16*)(p + 0xd8) > m) {
        *(f32*)(p + *(s32*)(p + 0xa0) * 4 + 0x70) = *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + *(s32*)(p + 0xa0) * 4 + 0x38) + 0xc);
        *(f32*)(p + *(s32*)(p + 0xa0) * 4 + 0x64) = *(f32*)(*(u8**)(p + 0x48) + 0xc) - *(f32*)(*(u8**)(p + *(s32*)(p + 0xa0) * 4 + 0x44) + 0xc);
        p[0x112] = p[0x110];
        p[0x110] = 0x1b;
    }
}

#pragma opt_lifetimes off
extern "C" void fn_803C8B80(u8* p) {
    s32 i;
    f32 f31;
    f32 f30;
    s16 t;
    s32 state;

    if (fn_80309A9C(lbl_8053AD30, 8, 1) != 0) {
        *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) - 1;
        if (*(s32*)(p + 0xa0) < 0) {
            *(s32*)(p + 0xa0) = 2;
        }
        if (*(s32*)(p + 0xa0) == *(s32*)(p + 0xa4)) {
            *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) - 1;
            if (*(s32*)(p + 0xa0) < 0) {
                *(s32*)(p + 0xa0) = 2;
            }
        }
        if (*(s32*)(p + 0xa0) == *(s32*)(p + 0xa4)) {
            *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) - 1;
            if (*(s32*)(p + 0xa0) < 0) {
                *(s32*)(p + 0xa0) = 2;
            }
        }
        *(s16*)(p + 0xda) = 1;
        *(s16*)(*(u8**)(p + 0x50) + 0x26) = 0x1e;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    } else if (fn_80309A9C(lbl_8053AD30, 4, 1) != 0) {
        *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) + 1;
        if (*(s32*)(p + 0xa0) > 2) {
            *(s32*)(p + 0xa0) = 0;
        }
        if (*(s32*)(p + 0xa0) == *(s32*)(p + 0xa4)) {
            *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) + 1;
            if (*(s32*)(p + 0xa0) > 2) {
                *(s32*)(p + 0xa0) = 0;
            }
        }
        if (*(s32*)(p + 0xa0) == *(s32*)(p + 0xa4)) {
            *(s32*)(p + 0xa0) = *(s32*)(p + 0xa0) + 1;
            if (*(s32*)(p + 0xa0) > 2) {
                *(s32*)(p + 0xa0) = 0;
            }
        }
        *(s16*)(p + 0xda) = 1;
        *(s16*)(*(u8**)(p + 0x50) + 0x26) = 0x1e;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    } else if (fn_80309C4C(lbl_8053AD30, 0x1100, 1) != 0) {
        p[0x114] = 1;
        *(s32*)(p + 0x84) = 0x62;
        fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(0x5466743031ULL)), *(s32*)(p + 0x84), 0, 0, 0);
        if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
            *(s32*)(p + 0xb0) = 0x5a;
        }
        if (p[0x115] & (u8)(1 << *(s32*)(p + 0xa0))) {
            fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 4))->search(0x5464623031ULL)), 0x66, 0, 0, 0);
        } else {
            *(s32*)(p + 0x80) = 0;
        }
        fn_80458880(lbl_8053AF80, 0xb, -1);
        fn_803C05D8(p);
    } else if (fn_80309C4C(lbl_8053AD30, 0x200, 1) != 0) {
        *(s32*)(p + 0x80) = 0;
        state = 0x117;
        if (lbl_8053AAF8[0x7f] != 0) {
            state = 0x116;
        }
        *(s32*)(p + 0x84) = state;
        fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(0x5466743031ULL)), *(s32*)(p + 0x84), 0, 0, 0);
        if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
            *(s32*)(p + 0xb0) = 0x5a;
        }
        fn_80402E08(*(void**)(p + 0x50), lbl_80543494, lbl_80543458);
        *(s16*)(*(u8**)(p + 0x50) + 0x20) = 0;
        ((J2DTextBoxVt*)*(void**)(*(u8**)(p + 0x50) + 4))->v9(0);
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723031ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723032ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723033ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723034ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        *(s16*)(*(u8**)(p + 0x38) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x38) + 0x22) = 0;
        *(s16*)(*(u8**)(p + 0x38) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x44) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x44) + 0x22) = 0;
        *(s16*)(*(u8**)(p + 0x44) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x3c) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x3c) + 0x22) = 0;
        *(s16*)(*(u8**)(p + 0x3c) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x48) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x48) + 0x22) = 0;
        *(s16*)(*(u8**)(p + 0x48) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x40) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x40) + 0x22) = 0;
        *(s16*)(*(u8**)(p + 0x40) + 0x26) = 0;
        *(s16*)(*(u8**)(p + 0x4c) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x4c) + 0x22) = 0;
        *(s16*)(*(u8**)(p + 0x4c) + 0x26) = 0;
        *(s16*)(p + 0xd8) = 0;
        *(s16*)(p + 0xda) = 0;
        p[0x112] = p[0x110];
        p[0x110] = 0x1e;
        fn_80458880(lbl_8053AF80, 0xc, -1);
    }
    if (p[0x110] == 0x19) {
            t = *(s16*)(p + 0xda);
            f30 = lbl_80543458;
            if (t != 0) {
                if (t < 5) {
                    f30 = lbl_805434A4 * (f32)(t * t) / lbl_805434A8;
                    *(s16*)(p + 0xda) = t + 1;
                } else if (t < 10) {
                    f30 = lbl_805434A4 * (f32)((10 - t) * (10 - t)) / lbl_805434A8;
                    *(s16*)(p + 0xda) = t + 1;
                } else {
                    *(s16*)(p + 0xda) = 0;
                }
            }
            f31 = lbl_80543458;
            for (i = 0; i < 3; i++) {
                if (f31 != f30 && i == *(s32*)(p + 0xa0)) {
                    fn_80402E08(*(void**)(p + 0x44 + i * 4), f31, *(f32*)(p + 0x64 + i * 4) + f30);
                } else {
                    fn_80402E08(*(void**)(p + 0x44 + i * 4), lbl_80543458, *(f32*)(p + 0x64 + i * 4));
                }
            }
            u8* selection = p;
            selection += *(s32*)(p + 0xa0) * 4;
            f32* bounds = getBounds__7J2DPaneFv(*(void**)(*(u8**)(selection + 0x44) + 4));
            f32 y = bounds[1] - *(f32*)(*(u8**)(p + 0x44) + 0xc);
            fn_80402E08(*(void**)(p + 0x50), lbl_80543458, y);
            fn_8040245C(*(void**)(p + 0x50), 0x3c, 0, *(u8*)(*(u8**)(p + 0x50) + 0x28), 1);
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723031ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723032ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723033ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723034ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    }
}
#pragma opt_lifetimes reset
extern "C" void fn_803C92B8(char* p) {
    if (*(s32*)(p + 0xb0) > 0) {
        *(s32*)(p + 0xb0) = *(s32*)(p + 0xb0) - 1;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1300, 1) != 0 || *(s32*)(p + 0xb0) == 0) {
        *(s32*)(p + 0xb0) = -1;
        fn_803C0018(p);
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

extern "C" f32 lbl_805434AC;
#pragma opt_propagation off
extern "C" void fn_803C9338(u8* p) {
    int idx;
    int d;
    const u8* base = lbl_804765D0;
    u8* tbl = lbl_8050DB0C;
    s16 a = *(s16*)(tbl + 0x1ec);
    s16 b = *(s16*)(tbl + 0x1ee);
    s16 c = *(s16*)(tbl + 0x1f0);
    d = *(s16*)(tbl + 0x1f2);
    s32 max = a + b;
    s32 i;
    u8* selected;
    if (max < c + d) {
        max = c + d;
    }
    *(s16*)(p + 0xd8) = *(s16*)(p + 0xd8) + 1;
    if (*(s16*)(p + 0xd8) > a) {
        idx = *(s32*)(p + 0xa0);
        fn_80402940(menuSlot((char*)p, idx), b, *(f32*)(*(u8**)(p + 0x38) + 0xc) - *(f32*)(menuSlot((char*)p, idx) + 0xc), *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(menuSlot((char*)p, idx) + 0xc), 0);
        fn_80402628(menuSlot((char*)p, *(s32*)(p + 0xa0)), b, 0, *(u8*)(menuSlot((char*)p, *(s32*)(p + 0xa0)) + 0x28));
        idx = *(s32*)(p + 0xa0);
        {
            void* obj = *(void**)(p + 8);
            const u64* key = (const u64*)(base + 0x780);
            void* o = ((J2DPane*)obj)->search(key[idx]);
            selected = p;
            selected += idx * 4;
            fn_804023D0(*(void**)(selected + 0x38), o, p[0x125]);
        }
        {
            const u64* key = (const u64*)(base + 0x768);
            fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x126]);
        }
        {
            const u64* key = (const u64*)(base + 0x750);
            fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x127]);
        }
        {
            const u64* key = (const u64*)(base + 0x6c8);
            fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x128]);
        }
        {
            const u64* key = (const u64*)(base + 0x6b0);
            fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x129]);
        }
        {
            const u64* key = (const u64*)(base + 0x698);
            fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x12a]);
        }
        {
            const u64* key = (const u64*)(base + 0x680);
            fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x12b]);
        }
        {
            const u64* key = (const u64*)(base + 0x668);
            fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x12c]);
        }
        {
            const u64* key = (const u64*)(base + 0x650);
            fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x12d]);
        }
        {
            const u64* key = (const u64*)(base + 0x638);
            fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x12e]);
        }
        {
            const u64* key = (const u64*)(base + 0x620);
            fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x12f]);
        }
        {
            const u64* key = (const u64*)(base + 0x608);
            fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x130]);
        }
        {
            const u64* key = (const u64*)(base + 0x5f0);
            fn_804023D0(*(void**)(selected + 0x38), ((J2DPane*)*(void**)(p + 8))->search(key[idx]), p[0x131]);
        }
        fn_80402940(*(void**)(p + 0x14), b, lbl_80543458, *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + 0x38) + 0xc), 0);
        fn_80402628(*(void**)(p + 0x14), b, 0, *(u8*)(*(u8**)(p + 0x14) + 0x28));
        fn_80402940(*(void**)(p + 0x18), b, lbl_80543458, *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + 0x38) + 0xc), 0);
        fn_80402628(*(void**)(p + 0x18), b, 0, *(u8*)(*(u8**)(p + 0x18) + 0x28));
        fn_80402940(*(void**)(p + 0x1c), b, lbl_80543458, *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + 0x38) + 0xc), 0);
        fn_80402628(*(void**)(p + 0x1c), b, 0, *(u8*)(*(u8**)(p + 0x1c) + 0x28));
        i = 0;
        for (const u64* key = (const u64*)(base + 0x48); i < 0x51; i++, key++) {
            u8* obj = *(u8**)(p + 0x4);
            void* o = keyObj(obj, *key);
            fn_804023D0(*(void**)(p + 0x14), o, p[0x132 + i]);
        }
        i = 0;
        for (const u64* key = (const u64*)(base + 0x2d0); i < 0x13; i++, key++) {
            u8* obj = *(u8**)(p + 0x8);
            void* o = keyObj(obj, *key);
            fn_804023D0(*(void**)(p + 0x14), o, p[0x183 + i]);
        }
    }
    if (*(s16*)(p + 0xd8) > c) {
        ((Fn5Fn)fn_80402B10)(*(void**)(p + 0x20), d, 0, lbl_80543458, lbl_805434AC);
        fn_80402628(*(void**)(p + 0x20), d, *(u8*)(*(u8**)(p + 0x20) + 0x28), 0);
        i = 0;
        for (const u64* key = (const u64*)(base + 0x368); i < 9; i++, key++) {
            u8* obj = *(u8**)(p + 0x4);
            void* o = keyObj(obj, *key);
            fn_804023D0(*(void**)(p + 0x20), o, p[0x196 + i]);
        }
    }
    if (*(s16*)(p + 0xd8) > max) {
        *(u8*)(p + 0x112) = *(u8*)(p + 0x110);
        *(u8*)(p + 0x110) = 0x18;
    }
}
#pragma opt_propagation reset

extern "C" f32 lbl_80543478;
#pragma opt_strength_reduction off
extern "C" void fn_803C9898(u8* p) {
    const u8* timing = lbl_8050DB0C;
    u8* base = (u8*)lbl_804765D0;
    s16 a = *(s16*)(timing + 0x1d0);
    int d = *(s16*)(timing + 0x1d6);
    s16 b = *(s16*)(timing + 0x1d2);
    s16 c = *(s16*)(timing + 0x1d4);
    s16 e = *(s16*)(timing + 0x1d8);
    s32 sum;
    s32 tot = c + d + e;
    s16 mx = *(s16*)(timing + 0x1da);
    s16 g = *(s16*)(timing + 0x1dc);
    sum = a + b;

    u8* q;
    s32 row;
    s32 off;
    u8* kb;
    s32 i;
    u8* kp;
    if (mx < sum) {
        mx = sum;
    }
    if (tot < mx + g) {
        tot = mx + g;
    }
    *(s16*)(p + 0xd8) = *(s16*)(p + 0xd8) + 1;
    if (*(s16*)(p + 0xd8) > a && *(s16*)(p + 0xd8) <= sum) {
        if ((p[0x115] & (u8)(1 << *(s32*)(p + 0xa0))) != 0) {
            ((Fn5Fn)fn_80402B10)(*(void**)(p + 0x20), b, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + 0x20), b, *(u8*)(*(u8**)(p + 0x20) + 0x28), 0);
            kb = base + 0x368;
            kp = kb;
            for (i = 0; i < 9; i++) {
                void* o = ((J2DPane*)*(void**)(p + 0x4))->search(*(u64*)kp);
                fn_804023D0(*(void**)(p + 0x20), o, p[0x196 + i]);
                kp += 8;
            }
            if (*(s16*)(p + 0xd8) == sum) {
                fn_80402E08(*(void**)(p + 0x20), lbl_80543498,
                            *(f32*)(*(u8**)(p + 0x3c) + 0xc) - *(f32*)(*(u8**)(p + 0x38) + 0xc));
                *(s16*)(*(u8**)(p + 0x20) + 0x20) = 0;
                ((PaneObjVt*)*(void**)(*(u8**)(p + 0x20) + 0x4))->v9(0);
                for (i = 0; i < 9; i++) {
                    void* o = ((J2DPane*)*(void**)(p + 0x4))->search(*(u64*)kb);
                    fn_804023D0(*(void**)(p + 0x20), o, p[0x196 + i]);
                    kb += 8;
                }
                *(s16*)(*(u8**)(p + 0x20) + 0x26) = 0;
            }
        } else {
            ((Fn5Fn)fn_80402B10)(*(void**)(p + 0x14), b, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + 0x14), b, *(u8*)(*(u8**)(p + 0x14) + 0x28), 0);
            ((Fn5Fn)fn_80402B10)(*(void**)(p + 0x18), b, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + 0x18), b, *(u8*)(*(u8**)(p + 0x18) + 0x28), 0);
            ((Fn5Fn)fn_80402B10)(*(void**)(p + 0x1c), b, 0, lbl_80543458, lbl_80543498);
            fn_80402628(*(void**)(p + 0x1c), b, *(u8*)(*(u8**)(p + 0x1c) + 0x28), 0);
            { u8* key;
            for (i = 0, key = base + 0x48; i < 0x51; i++, key += 8) {
                void* o = ((J2DPane*)*(void**)(p + 0x4))->search(*(u64*)key);
                fn_804023D0(*(void**)(p + 0x14), o, p[0x132 + i]);

            }
            }
            { u8* key;
            for (i = 0, key = base + 0x2d0; i < 0x13; i++, key += 8) {
                void* o = ((J2DPane*)*(void**)(p + 0x8))->search(*(u64*)key);
                fn_804023D0(*(void**)(p + 0x14), o, p[0x183 + i]);

            }
            }
        }
        fn_803BC6F0((char*)p, *(u32*)(p + 0xa4), lbl_80543478 - (f32)(*(s16*)(p + 0xd8) - a) / (f32)b);
        if (*(s16*)(p + 0xd8) == sum) {
            *(s32*)(p + 0x84) = 0x63;
            fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(0x5466743031ULL)), *(s32*)(p + 0x84), 0, 0, 0);
            if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
                *(s32*)(p + 0xb0) = 0x5a;
            }
            fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 4))->search(0x5464623031ULL)), 0x67, 0, 0, 0);
        }
    }
    off = 0;
    q = p;
    for (row = 0; row < 2; row++) {
        if (*(s16*)(p + 0xd8) > c + off) {
            fn_80402940(*(void**)(q + 0x24), d, lbl_80543458, lbl_8054349C, 0);
            fn_80402628(*(void**)(q + 0x24), d, *(u8*)(*(u8**)(q + 0x24) + 0x28), 0);
            switch (row) {
            case 0:
                for (i = 0, kp = base + 0x7f8; i < 4; i++, kp += 8) {
 void* found = ((J2DPane*)*(void**)(p + 8))->search(*(u64*)kp);
 fn_804023D0(*(void**)(q + 0x24), found, p[0x19f + i]);
 }
                break;
            case 1:
                for (i = 0, kp = base + 0x7d8; i < 4; i++, kp += 8) {
 void* found = ((J2DPane*)*(void**)(p + 8))->search(*(u64*)kp);
 fn_804023D0(*(void**)(q + 0x24), found, p[0x19f + i]);
 }
                break;
            case 2:
                for (i = 0, kp = base + 0x7b8; i < 4; i++, kp += 8) {
 void* found = ((J2DPane*)*(void**)(p + 8))->search(*(u64*)kp);
 fn_804023D0(*(void**)(q + 0x24), found, p[0x19f + i]);
 }
                break;
            case 3:
                for (i = 0, kp = base + 0x798; i < 4; i++, kp += 8) {
 void* found = ((J2DPane*)*(void**)(p + 8))->search(*(u64*)kp);
 fn_804023D0(*(void**)(q + 0x24), found, p[0x19f + i]);
 }
                break;
            }
        }
        off += e;
        q += 4;
    }
    if (*(s16*)(p + 0xd8) > mx) {
        ((Fn5Fn)fn_80402B10)(*(void**)(p + 0x20), g, 0, lbl_80543498, lbl_80543458);
        fn_80402628(*(void**)(p + 0x20), g, 0, *(u8*)(*(u8**)(p + 0x20) + 0x28));
        for (i = 0, kp = base + 0x368; i < 9; i++, kp += 8) {
            void* o = ((J2DPane*)*(void**)(p + 0x4))->search(*(u64*)kp);
            fn_804023D0(*(void**)(p + 0x20), o, p[0x196 + i]);
        }
    }
    if (*(s16*)(p + 0xd8) > tot) {
        memcpy(*(u8**)(p + 0x5c) + *(u32*)(p + 0xa0) * 200, *(u8**)(p + 0x5c) + *(u32*)(p + 0xa4) * 200, 200);
        fn_803BACF8(*(void**)(p + 0x5c), (u8)*(u32*)(p + 0xa0));
        fn_803B9CCC(lbl_8051C1A0, *(void**)(p + 0x5c), 0x258, 0);
        p[0x112] = p[0x110];
        p[0x110] = 0x15;
    }
}
#pragma opt_strength_reduction reset
extern "C" void fn_803C0A34(char* p);
extern "C" void fn_803CE4CC(char* p);
extern "C" void fn_803C9F14(char* this_) {
    s32 r = fn_803B9BDC(lbl_8051C1A0);
    if (r == 2) {
        *(u32*)(this_ + 0x84) = 0;
        *(u32*)(this_ + 0x80) = 0x69;
        *(u8*)(this_ + 0x112) = *(u8*)(this_ + 0x110);
        *(u8*)(this_ + 0x110) = 0;
    } else if (r == 1) {
        fn_803C0A34(this_);
    }
}

void fn_803C9F80(char* this_) {
    s32 a = *(s16*)(lbl_8050DB0C + 0x190);
    s32 b = *(s16*)(lbl_8050DB0C + 0x192);
    s32 c = *(s16*)(lbl_8050DB0C + 0x194);
    s32 d = *(s16*)(lbl_8050DB0C + 0x196);
    s32 e = *(s16*)(lbl_8050DB0C + 0x198);
    s32 sum0 = a + b;
    s32 sum1 = d + e * 3 + c;
    s32 r19 = sum0;
    s32 sel[3];
    s32 i;
    u32 n;
    if (sum0 < sum1) {
        r19 = sum1;
    }
    sum1 = *(s16*)(lbl_8050DB0C + 0x19a) + *(s16*)(lbl_8050DB0C + 0x19e) + *(s16*)(lbl_8050DB0C + 0x19c);
    if (r19 < sum1) {
        r19 = sum1;
    }
    n = *(u32*)(this_ + 0xa4);
    for (i = 0; i < 3; i++) {
        if (i != n) {
            sel[i] = i;
        }
    }
}

extern "C" void fn_803CABAC(u8* self) {
    if (fn_80309C4C(lbl_8053AD30, 0x1100, 1) != 0) {
        s32 state = *(s32*)(self + 0xa0);
        if (state == 2) {
        } else if (state >= 0) {
        }
    }
}

#pragma optimization_level 3
extern "C" void fn_803CB3DC(u8* p) {
 u8* tbl = lbl_8050DB0C;
 u8* base = (u8*)lbl_804765D0;
 s32 b = *(s16*)(tbl+0x17e);
 s32 c = *(s16*)(tbl+0x180);
 s32 a = *(s16*)(tbl+0x17c);
 s32 lim = b+c;
 lim = a+lim;
 s32 d = *(s16*)(tbl+0x182);
 s32 e = *(s16*)(tbl+0x184);
 s32 f = *(s16*)(tbl+0x186);
 s32 g = *(s16*)(tbl+0x188);
 s32 h = *(s16*)(tbl+0x18a);
 if(lim<d+e) lim=d+e;
 s32 tail=g+h*3;
 tail=f+tail;
 if(lim<tail) lim=tail;
 s32 ids[2]; s32* id=ids; s32* dst=id;
 for(s32 j=0;j<3;j++){if(j!=*(s32*)(p+0xa4)) *dst++=j;}
 *(s16*)(p+0xd8)+=1;
 s32 off; s32 i;
 i=0;off=0;
 for(;i<2;i++,off+=c,id++) {
 if(*(s16*)(p+0xd8)>a+off) {
 setFade(*(void**)(p+0x38+*id*4),b,0,lbl_80543458,lbl_80543498);
 fn_80402628(*(void**)(p+0x38+*id*4),b,(*(u8**)(p+0x38+*id*4))[0x28],0);
 s32 idx=*id;
void* first56=((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x780)+(u32)idx*8));
s32 cell56=idx*4+0x38;
fn_804023D0(*(void**)(p+cell56),first56,p[0x125]);
fn_804023D0(*(void**)(p+cell56),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x768)+(u32)idx*8)),p[0x126]);
fn_804023D0(*(void**)(p+cell56),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x750)+(u32)idx*8)),p[0x127]);
fn_804023D0(*(void**)(p+cell56),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x6c8)+(u32)idx*8)),p[0x128]);
fn_804023D0(*(void**)(p+cell56),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x6b0)+(u32)idx*8)),p[0x129]);
fn_804023D0(*(void**)(p+cell56),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x698)+(u32)idx*8)),p[0x12a]);
fn_804023D0(*(void**)(p+cell56),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x680)+(u32)idx*8)),p[0x12b]);
fn_804023D0(*(void**)(p+cell56),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x668)+(u32)idx*8)),p[0x12c]);
fn_804023D0(*(void**)(p+cell56),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x650)+(u32)idx*8)),p[0x12d]);
fn_804023D0(*(void**)(p+cell56),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x638)+(u32)idx*8)),p[0x12e]);
fn_804023D0(*(void**)(p+cell56),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x620)+(u32)idx*8)),p[0x12f]);
fn_804023D0(*(void**)(p+cell56),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x608)+(u32)idx*8)),p[0x130]);
fn_804023D0(*(void**)(p+cell56),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x5f0)+(u32)idx*8)),p[0x131]);
setFade(*(void**)(p+0x44+*id*4),b,0,lbl_80543458,lbl_80543498);
 fn_80402628(*(void**)(p+0x44+*id*4),b,(*(u8**)(p+0x44+*id*4))[0x28],0);
 idx=*id;
void* first68=((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x5d8)+(u32)idx*8));
s32 cell68=idx*4+0x44;
fn_804023D0(*(void**)(p+cell68),first68,p[0x118]);
fn_804023D0(*(void**)(p+cell68),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x5c0)+(u32)idx*8)),p[0x119]);
fn_804023D0(*(void**)(p+cell68),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x5a8)+(u32)idx*8)),p[0x11a]);
fn_804023D0(*(void**)(p+cell68),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x590)+(u32)idx*8)),p[0x11b]);
fn_804023D0(*(void**)(p+cell68),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x578)+(u32)idx*8)),p[0x11c]);
fn_804023D0(*(void**)(p+cell68),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x560)+(u32)idx*8)),p[0x11d]);
fn_804023D0(*(void**)(p+cell68),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x548)+(u32)idx*8)),p[0x11e]);
fn_804023D0(*(void**)(p+cell68),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x530)+(u32)idx*8)),p[0x11f]);
fn_804023D0(*(void**)(p+cell68),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x518)+(u32)idx*8)),p[0x120]);
fn_804023D0(*(void**)(p+cell68),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x500)+(u32)idx*8)),p[0x121]);
fn_804023D0(*(void**)(p+cell68),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x4e8)+(u32)idx*8)),p[0x122]);
fn_804023D0(*(void**)(p+cell68),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x4d0)+(u32)idx*8)),p[0x123]);
fn_804023D0(*(void**)(p+cell68),((J2DPane*)*(void**)(p+8))->search(*(u64*)((u8*)(base+0x4b8)+(u32)idx*8)),p[0x124]);
}}
 if(*(s32*)(p+0xa4)!=0 && *(s16*)(p+0xd8)>a){
 fn_80402940(*(void**)(p+0x38+*(s32*)(p+0xa4)*4),b,lbl_80543458,*(f32*)(*(u8**)(p+0x38)+0xc)-*(f32*)(*(u8**)(p+0x38+*(s32*)(p+0xa4)*4)+0xc) ,0);
 fn_80402940(*(void**)(p+0x44+*(s32*)(p+0xa4)*4),b,lbl_80543458,*(f32*)(*(u8**)(p+0x44)+0xc)-*(f32*)(*(u8**)(p+0x44+*(s32*)(p+0xa4)*4)+0xc),0);
 }
 if(*(s16*)(p+0xd8)>d){
 setFade(*(void**)(p+0x14),e,0,lbl_80543498,lbl_80543458);
 fn_80402628(*(void**)(p+0x14),e,0,(*(u8**)(p+0x14))[0x28]);
 setFade(*(void**)(p+0x18),e,0,lbl_80543498,lbl_80543458);
 fn_80402628(*(void**)(p+0x18),e,0,(*(u8**)(p+0x18))[0x28]);
 setFade(*(void**)(p+0x1c),e,0,lbl_80543498,lbl_80543458);
 fn_80402628(*(void**)(p+0x1c),e,0,(*(u8**)(p+0x1c))[0x28]);
 {s32 k;u8* kp; k=0;kp=base+0x48;for(;k<0x51;k++,kp+=8)fn_804023D0(*(void**)(p+0x14),((J2DPane*)*(void**)(p+4))->search(*(u64*)kp),p[k+0x132]);}
 {s32 k;u8* kp; k=0;kp=base+0x2d0;for(;k<0x13;k++,kp+=8)fn_804023D0(*(void**)(p+0x14),((J2DPane*)*(void**)(p+8))->search(*(u64*)kp),p[k+0x183]);}
 }
 off=0;u8* q=p;
 for(s32 row=0;row<4;row++,off+=h,q+=4){
 if(*(s16*)(p+0xd8)>f+off){
 fn_80402940(*(void**)(q+0x24),g,lbl_80543458,lbl_8054349C,0);
 fn_80402628(*(void**)(q+0x24),g,0,(*(u8**)(q+0x24))[0x28]);
 switch(row){
 case 0:{s32 k;u8* kp; k=0;kp=base+0x7f8;for(;k<4;k++,kp+=8)fn_804023D0(*(void**)(q+0x24),((J2DPane*)*(void**)(p+8))->search(*(u64*)kp),p[k+0x19f]);}break;
 case 1:{s32 k;u8* kp; k=0;kp=base+0x7d8;for(;k<4;k++,kp+=8)fn_804023D0(*(void**)(q+0x24),((J2DPane*)*(void**)(p+8))->search(*(u64*)kp),p[k+0x19f]);}break;
 case 2:{s32 k;u8* kp; k=0;kp=base+0x7b8;for(;k<4;k++,kp+=8)fn_804023D0(*(void**)(q+0x24),((J2DPane*)*(void**)(p+8))->search(*(u64*)kp),p[k+0x19f]);}break;
 case 3:{s32 k;u8* kp; k=0;kp=base+0x798;for(;k<4;k++,kp+=8)fn_804023D0(*(void**)(q+0x24),((J2DPane*)*(void**)(p+8))->search(*(u64*)kp),p[k+0x19f]);}break;
 }}}
 if(*(s16*)(p+0xd8)>lim){p[0x112]=p[0x110];p[0x110]=0x13;}
}
#pragma optimization_level reset
extern "C" void fn_803CBE38(char* p) {
    int r;
    r = fn_803B9A94(lbl_8051C1A0, *(u32*)(p + 0x5c), 0x258, *(u32*)(p + 0x60), 0x1d4c, 0);
    if (r != 0) {
        if (r == 1) {
            lbl_8053AAF8[0xff] = 1;
            fn_803C24BC(p);
            *(u64*)(lbl_8050EC80 + 8) = *(u64*)(lbl_8051C1A0 + 0x1ff8);
        } else if (r == 2) {
            p[0x112] = p[0x110];
            p[0x110] = 1;
        }
    }
}

extern "C" void fn_803CBEE0(void) {
    OSResetSystem(1, 1, 1);
}

extern "C" void fn_803CBF0C(char* p) {
    if (fn_80309C4C(lbl_8053AD30, 1, 1) != 0) {
        if (*(u8*)(p + 0x114) != 0) {
            *(u8*)(p + 0x114) = *(u8*)(p + 0x114) - 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 2, 1) != 0) {
        if (*(u8*)(p + 0x114) < 1) {
            *(u8*)(p + 0x114) = *(u8*)(p + 0x114) + 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x100, 1) != 0) {
        if (*(u8*)(p + 0x114) == 0) {
            *(s32*)(p + 0x80) = 0;
            *(u8*)(p + 0x112) = *(u8*)(p + 0x110);
            *(u8*)(p + 0x110) = 0x10;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            if (*(u8*)((u8*)lbl_8053AAF8 + 0x7f) != 0) {
                *(s32*)(p + 0x80) = 0x5c;
            } else {
                *(s32*)(p + 0x80) = 0x256;
            }
            *(u8*)(p + 0x112) = *(u8*)(p + 0x110);
            *(u8*)(p + 0x110) = 3;
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
    }
}

extern "C" void* lbl_8053AD30;
extern "C" void* lbl_8053AF80;
extern "C" u32 fn_80309C4C(void* a, u32 b, int c);
extern "C" void fn_80458880(void* a, int b, int c);
extern "C" void fn_803CC048(char* p) {
    if (*(s32*)(p + 0xb0) > 0) {
        *(s32*)(p + 0xb0) = *(s32*)(p + 0xb0) - 1;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1300, 1) != 0 || *(s32*)(p + 0xb0) == 0) {
        *(s32*)(p + 0xb0) = -1;
        *(s32*)(p + 0x80) = 0;
        p[0x112] = p[0x110];
        p[0x110] = 1;
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

extern "C" char lbl_80529DEC[];
extern "C" int fn_803B9C5C(void* a);
extern "C" void fn_803CC0D8(char* p) {
    int r = fn_803B9C5C(lbl_8051C1A0);
    if (r == 1) {
        *(s32*)(p + 0x80) = 0x55;
        p[0x112] = p[0x110];
        p[0x110] = 0xe;
        p[0x113] = 0;
        lbl_80529DEC[0x24c] = 0;
        *(s32*)(p + 0xb0) = 0x5a;
    } else if (r == 2) {
        *(s32*)(p + 0x80) = 0x56;
        p[0x112] = p[0x110];
        p[0x110] = 0;
        p[0x113] = 0;
        lbl_80529DEC[0x24c] = 0;
    }
}

extern "C" void fn_803B9DDC(void* a);
extern "C" void fn_803CC17C(u8* p) {
    if (fn_80309C4C(lbl_8053AD30, 1, 1) != 0) {
        if (p[0x114] != 0) {
            p[0x114] = p[0x114] - 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else {
        if (fn_80309C4C(lbl_8053AD30, 2, 1) != 0) {
            if (p[0x114] < 1) {
                p[0x114] = p[0x114] + 1;
                fn_80458880(lbl_8053AF80, 0x26, -1);
            }
        } else {
            if (fn_80309C4C(lbl_8053AD30, 0x100, 1) != 0) {
                if (p[0x114] == 0) {
                    fn_803B9DDC(lbl_8051C1A0);
                    *(s32*)(p + 0x80) = 0x54;
                    p[0x112] = p[0x110];
                    p[0x110] = 0xd;
                    p[0x113] = 1;
                    lbl_80529DEC[0x24c] = 1;
                    fn_80458880(lbl_8053AF80, 0xb, -1);
                } else {
                    *(s32*)(p + 0x80) = 0x52;
                    p[0x112] = p[0x110];
                    p[0x110] = 2;
                    fn_80458880(lbl_8053AF80, 0xc, -1);
                }
            }
        }
    }
}

extern "C" void fn_803CC2BC(char* p) {
    if (fn_80309C4C(lbl_8053AD30, 1, 1) != 0) {
        if (*(u8*)(p + 0x114) != 0) {
            *(u8*)(p + 0x114) = *(u8*)(p + 0x114) - 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 2, 1) != 0) {
        if (*(u8*)(p + 0x114) < 1) {
            *(u8*)(p + 0x114) = *(u8*)(p + 0x114) + 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if (fn_80309C4C(lbl_8053AD30, 0x100, 1) != 0) {
        if (*(u8*)(p + 0x114) == 0) {
            *(s32*)(p + 0x80) = 0x53;
            *(u8*)(p + 0x112) = *(u8*)(p + 0x110);
            *(u8*)(p + 0x110) = 0xc;
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            *(s32*)(p + 0x80) = 0x52;
            *(u8*)(p + 0x112) = *(u8*)(p + 0x110);
            *(u8*)(p + 0x110) = 2;
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
    }
}

extern "C" void fn_803CC3DC(char* p) {
    if (*(s32*)(p + 0xb0) > 0) {
        *(s32*)(p + 0xb0) = *(s32*)(p + 0xb0) - 1;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1300, 1) != 0 || *(s32*)(p + 0xb0) == 0) {
        *(s32*)(p + 0xb0) = -1;
        *(s32*)(p + 0x80) = 0;
        lbl_8053AAF8[0xff] = 1;
        fn_803C24BC(p);
        fn_80458880(lbl_8053AF80, 0xb, -1);
        *(u64*)(lbl_8050EC80 + 8) = *(u64*)(lbl_8051C1A0 + 0x1ff8);
    }
}

extern "C" void fn_803CC490(char* p) {
    int r = fn_803B9BDC(lbl_8051C1A0);
    if (r == 1) {
        *(s32*)(p + 0x80) = 0x5b;
        p[0x112] = p[0x110];
        p[0x110] = 0xa;
        p[0x113] = 0;
        lbl_80529DEC[0x24c] = 0;
        *(s32*)(p + 0xb0) = 0x5a;
    } else if (r == 2) {
        *(s32*)(p + 0x80) = 0x5a;
        fn_803CE4CC(p);
        p[0x112] = p[0x110];
        p[0x110] = 0;
        p[0x113] = 0;
        lbl_80529DEC[0x24c] = 0;
    }
}

extern "C" void fn_803CC53C(char* p) {
    u64 serial;
    fn_803B93E8(lbl_8050EC80, *(void**)(p + 0x5c), *(void**)(p + 0x60), 0);
    fn_803BACF8(*(void**)(p + 0x5c), 0);
    fn_803B93E8(lbl_8050EC80, *(void**)(p + 0x5c), *(void**)(p + 0x60), 1);
    fn_803BACF8(*(void**)(p + 0x5c), 1);
    fn_803B93E8(lbl_8050EC80, *(void**)(p + 0x5c), *(void**)(p + 0x60), 2);
    fn_803BACF8(*(void**)(p + 0x5c), 2);
    fn_803B9D54(lbl_8051C1A0, *(void**)(p + 0x5c), 0x258, *(void**)(p + 0x60), 0x1d4c, 0);
    p[0x112] = p[0x110];
    p[0x110] = 9;
    CARDGetSerialNo(((u8*)lbl_8051C1A0)[0x1ff4], &serial);
    *(u64*)(lbl_8051C1A0 + 0x1ff8) = serial;
}

extern "C" void fn_803CC62C(u8* p) {
    u32 r;
    r = fn_80309C4C(lbl_8053AD30, 1, 1);
    if (r != 0) {
        if (p[0x114] != 0) {
            p[0x114] = p[0x114] - 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else {
        r = fn_80309C4C(lbl_8053AD30, 2, 1);
        if (r != 0) {
            if (p[0x114] < 1) {
                p[0x114] = p[0x114] + 1;
                fn_80458880(lbl_8053AF80, 0x26, -1);
            }
        } else {
            r = fn_80309C4C(lbl_8053AD30, 0x100, 1);
            if (r != 0) {
                if (p[0x114] == 0) {
                    *(s32*)(p + 0x80) = 0x59;
                    p[0x112] = p[0x110];
                    p[0x110] = 8;
                    p[0x113] = 1;
                    lbl_80529DEC[0x24c] = 1;
                    fn_80458880(lbl_8053AF80, 0xb, -1);
                } else {
                    *(s32*)(p + 0x80) = 0x58;
                    p[0x112] = p[0x110];
                    p[0x110] = 2;
                    fn_80458880(lbl_8053AF80, 0xc, -1);
                }
            }
        }
    }
}

extern "C" void fn_803CC760(u8* p) {
    s32 mx;
    s32 order[3];
    s32* op;
    s32 i;
    s32 r29;
    s32 r24;
    s32 idx;
    u8* q;
    s16 t168, t16a, t16c, t16e, t170, t172, t174, t176;

    t170 = *(s16*)(lbl_8050DB0C + 0x170);
    t16e = *(s16*)(lbl_8050DB0C + 0x16e);
    t168 = *(s16*)(lbl_8050DB0C + 0x168);
    t16a = *(s16*)(lbl_8050DB0C + 0x16a);
    t16c = *(s16*)(lbl_8050DB0C + 0x16c);
    t172 = *(s16*)(lbl_8050DB0C + 0x172);
    t174 = *(s16*)(lbl_8050DB0C + 0x174);
    t176 = *(s16*)(lbl_8050DB0C + 0x176);

    mx = t168 + t16a;
    tu803C_max(&mx, t16c + t16e + 3 * t170);
    tu803C_max(&mx, t172 + t174 + t176);

    op = order;
    if (*(s32*)(p + 0xa4) != 0) {
        *op++ = 0;
    }
    if (*(s32*)(p + 0xa4) != 1) {
        *op++ = 1;
    }
    if (*(s32*)(p + 0xa4) != 2) {
        *op = 2;
    }

    *(s16*)(p + 0xd8) = *(s16*)(p + 0xd8) + 1;
    if (*(s16*)(p + 0xd8) > t168) {
        setFade(*(void**)(p + 0x14), t16a, 0, lbl_80543458, lbl_80543498);
        fn_80402628(*(void**)(p + 0x14), t16a, ((u8*)*(void**)(p + 0x14))[0x28], 0);
        setFade(*(void**)(p + 0x18), t16a, 0, lbl_80543458, lbl_80543498);
        fn_80402628(*(void**)(p + 0x18), t16a, ((u8*)*(void**)(p + 0x18))[0x28], 0);
        setFade(*(void**)(p + 0x1c), t16a, 0, lbl_80543458, lbl_80543498);
        fn_80402628(*(void**)(p + 0x1c), t16a, ((u8*)*(void**)(p + 0x1c))[0x28], 0);
        setKeyedAt(p, 0x4, 0x14, (u8*)lbl_804765D0 + 0x48, 0x51, 0x132);
        setKeyedAt(p, 0x8, 0x14, (u8*)lbl_804765D0 + 0x2d0, 0x13, 0x183);
    }

    r29 = 0;
    q = p;
    for (i = 0; i < 4; i++) {
        if (*(s16*)(p + 0xd8) > t16c + r29) {
            void* tgt = *(void**)(q + 0x24);
            fn_80402940(tgt, t16e, lbl_80543458, lbl_8054349C, 0);
            fn_80402628(tgt, t16e, ((u8*)tgt)[0x28], 0);
            switch (i) {
            case 0:
                setKeyedAt(p, 0x8, 0x24, (u8*)lbl_804765D0 + 0x7f8, 0x4, 0x19f);
                break;
            case 1:
                setKeyedAt(p, 0x8, 0x28, (u8*)lbl_804765D0 + 0x7d8, 0x4, 0x19f);
                break;
            case 2:
                setKeyedAt(p, 0x8, 0x2c, (u8*)lbl_804765D0 + 0x7b8, 0x4, 0x19f);
                break;
            case 3:
                setKeyedAt(p, 0x8, 0x30, (u8*)lbl_804765D0 + 0x798, 0x4, 0x19f);
                break;
            }
        }
        r29 += t170;
        q += 4;
    }

    r24 = 0;
    for (i = 0; i < 2; i++) {
        if (*(s16*)(p + 0xd8) > t172 + r24) {
            idx = order[0];
            setFade(*(void**)(p + 0x38 + idx * 4), t174, 0, lbl_80543498, lbl_80543458);
            fn_80402628(*(void**)(p + 0x38 + idx * 4), t174, 0, ((u8*)*(void**)(p + 0x38 + idx * 4))[0x28]);
            tu803C_setCell(p, 0x38, idx, 0x780, 0x125);
            tu803C_setCell(p, 0x38, idx, 0x768, 0x126);
            tu803C_setCell(p, 0x38, idx, 0x750, 0x127);
            tu803C_setCell(p, 0x38, idx, 0x6c8, 0x128);
            tu803C_setCell(p, 0x38, idx, 0x6b0, 0x129);
            tu803C_setCell(p, 0x38, idx, 0x698, 0x12a);
            tu803C_setCell(p, 0x38, idx, 0x680, 0x12b);
            tu803C_setCell(p, 0x38, idx, 0x668, 0x12c);
            tu803C_setCell(p, 0x38, idx, 0x650, 0x12d);
            tu803C_setCell(p, 0x38, idx, 0x638, 0x12e);
            tu803C_setCell(p, 0x38, idx, 0x620, 0x12f);
            tu803C_setCell(p, 0x38, idx, 0x608, 0x130);
            tu803C_setCell(p, 0x38, idx, 0x5f0, 0x131);
            setFade(*(void**)(p + 0x44 + idx * 4), t174, 0, lbl_80543498, lbl_80543458);
            fn_80402628(*(void**)(p + 0x44 + idx * 4), t174, 0, ((u8*)*(void**)(p + 0x44 + idx * 4))[0x28]);
            tu803C_setCell(p, 0x44, idx, 0x5d8, 0x118);
            tu803C_setCell(p, 0x44, idx, 0x5c0, 0x119);
            tu803C_setCell(p, 0x44, idx, 0x5a8, 0x11a);
            tu803C_setCell(p, 0x44, idx, 0x590, 0x11b);
            tu803C_setCell(p, 0x44, idx, 0x578, 0x11c);
        }
        r24 += t176;
    }
    if (*(s32*)(p + 0xa4) != 0 && t172 < *(s16*)(p + 0xd8)) {
        fn_80402940(*(void**)(p + *(s32*)(p + 0xa4) * 4 + 0x38), t174, lbl_80543458, lbl_8054349C, 0);
        fn_80402940(*(void**)(p + *(s32*)(p + 0xa4) * 4 + 0x44), t174, lbl_80543458, lbl_8054349C, 0);
    }
    if (mx < *(s16*)(p + 0xd8)) {
        s32 local_50 = *(s32*)(p + 0xe0);
        s32 local_4c = *(s32*)(p + 0xe4);
        void* obj = callVt3(p, 0x70620000, 0x50636f, 0x70623031);
        ((ColorVt*)obj)->v76(obj, &local_4c, &local_50);
        p[0x112] = p[0x110];
        p[0x110] = 5;
    }
}

extern "C" void* lbl_8053AEC0;
extern "C" void fn_803C1734(u8* p);
extern "C" void fn_803BF9C4(u8* p);
extern "C" void fn_804310BC(void* a);
extern "C" u32 fn_80309A9C(void* a, u32 b, int c);
extern "C" u32 fn_80309A9A(void* a, u32 b, int c);
extern "C" void fn_803CD2DC(u8* p) {
    u8 flags;
    if (fn_80309C4C(lbl_8053AD30, 0x1100, 1) != 0) {
        flags = p[0x115];
        if (flags & (u8)(1 << *(s32*)(p + 0xa4))) {
            p[0x114] = 1;
            *(s32*)(p + 0x84) = 0x5e;
            fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(0x5466743031ULL)), *(s32*)(p + 0x84), 0, 0, 0);
            if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
                *(s32*)(p + 0xb0) = 0x5a;
            }
            fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 4))->search(0x5464623031ULL)), 0x65, 0, 0, 0);
            fn_803BF9C4(p);
        } else {
            *(s32*)(p + 0xa0) = 0;
            fn_803C1734(p);
        }
        fn_80458880(lbl_8053AF80, 0xb, -1);
    } else if (fn_80309C4C(lbl_8053AD30, 0x200, 1) != 0) {
        if (p[0x116] != 0) {
            fn_804310BC(lbl_8053AEC0);
            p[0x1a3] = 0;
        }
        *(s32*)(p + 0x1a8) = 2;
        fn_80458880(lbl_8053AF80, 0xc, -1);
    } else if (fn_80309A9C(lbl_8053AD30, 4, 1) != 0) {
        fn_80458880(lbl_8053AF80, 0x26, -1);
        *(s32*)(p + 0xa4) = *(s32*)(p + 0xa4) + 1;
        if (*(s32*)(p + 0xa4) >= 3) {
            *(s32*)(p + 0xa4) = 0;
        }
        *(s16*)(p + 0xda) = 1;
        *(s16*)(*(u8**)(p + 0x50) + 0x26) = 0x1e;
    } else if (fn_80309A9C(lbl_8053AD30, 8, 1) != 0) {
        fn_80458880(lbl_8053AF80, 0x26, -1);
        *(s32*)(p + 0xa4) = *(s32*)(p + 0xa4) - 1;
        if (*(s32*)(p + 0xa4) < 0) {
            *(s32*)(p + 0xa4) = 2;
        }
        *(s16*)(p + 0xda) = 1;
        *(s16*)(*(u8**)(p + 0x50) + 0x26) = 0x1e;
    }
    if (p[0x110] == 5) {
        f32 f30;
        f30 = 0.0f;
        f32 f31;
        u8* q;
        s32 i;
        s16 t = *(s16*)(p + 0xda);
        if (t != 0) {
            if (t < 5) {
                f30 = (lbl_805434A4 * static_cast<f32>(t * t)) / lbl_805434A8;
                *(s16*)(p + 0xda) = t + 1;
            } else if (t < 10) {
                f30 = (lbl_805434A4 * static_cast<f32>((10 - t) * (10 - t))) / lbl_805434A8;
                *(s16*)(p + 0xda) = t + 1;
            } else {
                *(s16*)(p + 0xda) = 0;
            }
        }
        f31 = 0.0f;
        q = p;
        for (i = 0; i < 3; i++) {
            if (f31 != f30 && i == *(s32*)(p + 0xa4)) {
                fn_80402E08(*(void**)(q + 0x44), f31, f30);
            } else {
                fn_80402E08(*(void**)(q + 0x44), 0.0f, 0.0f);
            }
            q += 4;
        }
        f32* bounds = getBounds__7J2DPaneFv(*(void**)(((u8**)(p + 0x44))[*(s32*)(p + 0xa4)] + 4));
        fn_80402E08(*(void**)(p + 0x50), 0.0f, bounds[1] - *(f32*)(*(u8**)(p + 0x44) + 0xc));
        fn_8040245C(*(void**)(p + 0x50), 0x3c, 0, *(u8*)(*(u8**)(p + 0x50) + 0x28), 1);
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723031ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723032ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723033ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
        fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723034ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    }
}

extern "C" void fn_803CD75C(u8* p) {
    s32 i;
    s32 sum = 0;
    s16 b = *(s16*)(lbl_8050DB0C + 0x156);
    s16 c = *(s16*)(lbl_8050DB0C + 0x154);
    s16 d = *(s16*)(lbl_8050DB0C + 0x15a);
    s16 e = *(s16*)(lbl_8050DB0C + 0x15c);
    s16 f = *(s16*)(lbl_8050DB0C + 0x15e);
    s16 g = *(s16*)(lbl_8050DB0C + 0x160);
    s32 a = *(s16*)(lbl_8050DB0C + 0x158);
    s32 m = c + b;
    if (m < c + b + a * 2) {
        m = c + b + a * 2;
    }
    if (m < d + e) {
        m = d + e;
    }
    if (m < f + g) {
        m = f + g;
    }
    *(s16*)(p + 0xd8) += 1;
    if (*(s16*)(p + 0xd8) > c) {
        setFade(*(void**)(p + 0x50), b, 0, lbl_80543494, lbl_80543458);
    }
    for (i = 0; i < 3; i++) {
        if (*(s16*)(p + 0xd8) > c + sum) {
            fn_80402940(*(void**)(p + 0x38 + (2 - i) * 4), b, lbl_805434A0, lbl_80543458, 0);
            fn_80402628(*(void**)(p + 0x38 + (2 - i) * 4), b, 0, ((u8*)*(void**)(p + 0x38 + (2 - i) * 4))[0x28]);
            setCell(p, 0x38, 2 - i, 0x780, p[0x125]);
            setCell(p, 0x38, 2 - i, 0x768, p[0x126]);
            setCell(p, 0x38, 2 - i, 0x750, p[0x127]);
            setCell(p, 0x38, 2 - i, 0x6c8, p[0x128]);
            setCell(p, 0x38, 2 - i, 0x6b0, p[0x129]);
            setCell(p, 0x38, 2 - i, 0x698, p[0x12a]);
            setCell(p, 0x38, 2 - i, 0x680, p[0x12b]);
            setCell(p, 0x38, 2 - i, 0x668, p[0x12c]);
            setCell(p, 0x38, 2 - i, 0x650, p[0x12d]);
            setCell(p, 0x38, 2 - i, 0x638, p[0x12e]);
            setCell(p, 0x38, 2 - i, 0x620, p[0x12f]);
            setCell(p, 0x38, 2 - i, 0x608, p[0x130]);
            setCell(p, 0x38, 2 - i, 0x5f0, p[0x131]);
            setFade(*(void**)(p + 0x44 + i * 4), b, 0, lbl_80543494, lbl_80543458);
            fn_80402628(*(void**)(p + 0x44 + i * 4), b, 0, ((u8*)*(void**)(p + 0x44 + i * 4))[0x28]);
            setCell(p, 0x44, i, 0x5d8, p[0x118]);
            setCell(p, 0x44, i, 0x5c0, p[0x119]);
            setCell(p, 0x44, i, 0x5a8, p[0x11a]);
            setCell(p, 0x44, i, 0x590, p[0x11b]);
            setCell(p, 0x44, i, 0x578, p[0x11c]);
            setCell(p, 0x44, i, 0x560, p[0x11d]);
            setCell(p, 0x44, i, 0x548, p[0x11e]);
            setCell(p, 0x44, i, 0x530, p[0x11f]);
            setCell(p, 0x44, i, 0x518, p[0x120]);
            setCell(p, 0x44, i, 0x500, p[0x121]);
            setCell(p, 0x44, i, 0x4e8, p[0x122]);
            setCell(p, 0x44, i, 0x4d0, p[0x123]);
            setCell(p, 0x44, i, 0x4b8, p[0x124]);
        }
        sum += a;
    }
    if (*(s16*)(p + 0xd8) > d) {
        fn_80402940(*(void**)(p + 0x54), e, lbl_8054345C, lbl_80543458, 0);
        fn_80402628(*(void**)(p + 0x54), e, 0, ((u8*)*(void**)(p + 0x54))[0x28]);
    }
    if (*(s16*)(p + 0xd8) == f + 1) {
        p[0x1a4] = 1;
    }
    if (*(s16*)(p + 0xd8) > m) {
        p[0x112] = p[0x110];
        p[0x110] = 5;
    }
}

extern "C" void fn_803B950C(void* a, void* b);
extern "C" void fn_80403680(void* p);
extern "C" void fn_803CDEE8(u8* p) {
    u32 r;
    u8* a;
    u8* b;
    int i;
    r = fn_80309C4C(lbl_8053AD30, 1, 1);
    if (r != 0) {
        if (p[0x114] != 0) {
            p[0x114] = p[0x114] - 1;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else {
        r = fn_80309C4C(lbl_8053AD30, 2, 1);
        if (r != 0) {
            if (p[0x114] < 1) {
                p[0x114] = p[0x114] + 1;
                fn_80458880(lbl_8053AF80, 0x26, -1);
            }
        } else {
            r = fn_80309C4C(lbl_8053AD30, 0x100, 1);
            if (r != 0) {
                if (p[0x114] == 0) {
                    b = (u8*)lbl_8050EC80;
                    *(s32*)(p + 0x80) = 0;
                    a = b;
                    lbl_8053AAF8[0xff] = 0;
                    for (i = 0; i < 3; i++) {
                        fn_803B950C(a + 0x20, b + 0x280);
                        a = a + 0xc8;
                        b = b + 0x9c4;
                    }
                    fn_80403680(&lbl_80529DEC);
                    fn_803C24BC((char*)p);
                    fn_80458880(lbl_8053AF80, 0xb, -1);
                } else {
                    *(s32*)(p + 0x80) = 0;
                    p[0x112] = p[0x110];
                    p[0x110] = 1;
                    fn_80458880(lbl_8053AF80, 0xc, -1);
                }
            }
        }
    }
}

extern "C" void fn_803CE05C(char* p) {
    if (fn_80309C4C(lbl_8053AD30, 0x1300, 1) != 0) {
        if (*(u32*)(p + 0x7c) == 0x51) {
            *(s32*)(p + 0x80) = 0x83;
        } else if (*(u32*)(p + 0x7c) == 0x83) {
            *(s32*)(p + 0x80) = 0x84;
            p[0x112] = p[0x110];
            p[0x110] = 0xf;
        } else {
            if (lbl_8053AAF8[0x7f] != 0) {
                *(s32*)(p + 0x80) = 0x5c;
            } else {
                *(s32*)(p + 0x80) = 0x256;
            }
            p[0x112] = p[0x110];
            p[0x110] = 3;
        }
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

#pragma opt_propagation on
#pragma opt_strength_reduction on
extern "C" void fn_803CE11C(u8* p) {
    u32 state;
    f32* bounds;
    char* obj;
    f32 dx;
    f32 left;
    f32 x;
    f32 limit;
    s16 duration;
    s32 i;

    state = fn_803B9940(lbl_8051C1A0, 0);
    bounds = getBounds__7J2DPaneFv(*(void**)(*(char**)(p + 0x20) + 4));
    obj=*(char**)(p+0x20);
    left=*bounds;
    x=*(f32*)(obj+8);
    dx=left-x;
    limit=lbl_80543498;
    if (dx < limit) {
        duration=*(s16*)(lbl_8050DB0C+0x1d2);
        setFade(obj, duration, 0, lbl_80543458, limit);
        fn_80402628(*(void**)(p + 0x20), *(s16*)(lbl_8050DB0C + 0x1d2), *(u8*)(*(char**)(p + 0x20) + 0x28), 0);
        for (i = 0; i < 9; i++) {
            J2DPane* pane=((J2DPane*)*(void**)(p+4))->search(lbl_80476938[i]);
            fn_804023D0(*(void**)(p+0x20),pane,p[0x196+i]);
        }
        p[0x117] = 0;
    } else {
        switch (state) {
        case 0:
            *(s32*)(p + 0x80) = 0x4c;
            p[0x112] = p[0x110];
            p[0x1a4] = 1;
            fn_803C24BC((char*)p);
            p[0x110] = 2;
            *(u32*)((u8*)lbl_8050EC80 + 0xc) = 0;
            *(u32*)((u8*)lbl_8050EC80 + 0x8) = 0;
            break;
        case 1:
            *(s32*)(p + 0x80) = 0x4d;
            p[0x112] = p[0x110];
            p[0x1a4] = 1;
            p[0x110] = 2;
            break;
        case 2:
            *(s32*)(p + 0x80) = 0x4e;
            p[0x112] = p[0x110];
            p[0x1a4] = 1;
            p[0x110] = 2;
            break;
        case 3:
            *(s32*)(p + 0x80) = 0x4f;
            p[0x112] = p[0x110];
            p[0x1a4] = 1;
            p[0x110] = 2;
            break;
        case 4:
            *(s32*)(p + 0x80) = 0x50;
            p[0x112] = p[0x110];
            p[0x110] = 0xb;
            break;
        case 5:
            *(s32*)(p + 0x80) = 0x51;
            p[0x112] = p[0x110];
            p[0x1a4] = 1;
            p[0x110] = 2;
            break;
        case 6:
            fn_803B9B8C(lbl_8051C1A0);
            *(s32*)(p + 0x80) = 0;
            p[0x112] = p[0x110];
            p[0x110] = 0x11;
            break;
        case 7:
            *(s32*)(p + 0x80) = 0x57;
            p[0x112] = p[0x110];
            p[0x110] = 7;
            break;
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        default:
            *(s32*)(p + 0x80) = 0;
            break;
        }
    }
}
#pragma opt_strength_reduction reset
#pragma opt_propagation reset
extern "C" void fn_803832BC(char* a, s32 b, int c, int d, int e);
extern "C" char* getStringPtr__10J2DTextBoxCFv(void* this_);
extern "C" f32* getBounds__7J2DPaneFv(void* this_);
extern "C" f32 lbl_80543498;
extern "C" void fn_803CE370(char* p) {
    u32 r;
    if (*(s32*)(p + 0xb0) > 0) {
        *(s32*)(p + 0xb0) = *(s32*)(p + 0xb0) - 1;
    }
    if (fn_80309C4C(lbl_8053AD30, 0x1300, 1) != 0 || *(s32*)(p + 0xb0) == 0) {
        *(s32*)(p + 0xb0) = -1;
        *(s32*)(p + 0x80) = 0;
        r = 0x117;
        if (lbl_8053AAF8[0x7f] != 0) {
            r = 0x116;
        }
        *(s32*)(p + 0x84) = r;
        void* tb = ((J2DTextBoxVt*)*(void**)(p + 8))->v15(r, 0x54, 0x66743031);
        fn_803832BC(getStringPtr__10J2DTextBoxCFv(tb), *(s32*)(p + 0x84), 0, 0, 0);
        if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
            *(s32*)(p + 0xb0) = 0x5a;
        }
        f32* bounds = getBounds__7J2DPaneFv(*(void**)(*(char**)(p + 0x20) + 4));
        f32 w = *bounds;
        f32 h = *(f32*)(*(char**)(p + 0x20) + 8);
        if (h - w > lbl_80543498) {
            *(s16*)(*(char**)(p + 0x20) + 0x20) = 0;
            *(s16*)(*(char**)(p + 0x20) + 0x26) = 0;
            p[0x117] = 1;
        }
        p[0x112] = p[0x110];
        p[0x110] = 1;
        fn_80458880(lbl_8053AF80, 0xb, -1);
    }
}

extern u32 lbl_8053ADB0;
extern "C" s32 fn_803CE4B0(void) {
    if (lbl_8053ADB0 != 0) {
        return *(s32*)(lbl_8053ADB0 + 0x1a8);
    }
    return 3;
}

extern "C" int snprintf(char* s, unsigned long n, const char* fmt, ...);
extern "C" u8 fn_803BADAC(void* a);
#pragma opt_lifetimes off
extern "C" void fn_803CE4CC(char* p) {
    const u8* base;
    const u64* dates;
 const u64* levels;
 const u64* fires;
 s32 i;
    OSCalendarTime cal;

    base = lbl_804765D0;
 dates=(const u64*)(base+0x30);
 levels=(const u64*)(base+0);
 fires=(const u64*)(base+0x18);
    for (i = 0; i < 3; i++) {
        u8* rec = (u8*)lbl_8050EC80 + i * 0xc8;
        p[0x115] &= ~(u8)(1 << i);
        if ((s32)lbl_8053AAF8[0xff] != 0) {
            if (fn_803BADAC(rec + 0x20)) {
                s64 t = *(s64*)(rec + 0x20);
                if (isTimeSet(t)) {
                    OSTicksToCalendarTime(t, &cal);
                    snprintf(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(dates[i])), 0x1e, (const char*)(base + 0x868), cal.mon + 1, cal.mday, cal.year, cal.hour, cal.min, cal.sec);
                    ((J2DPane*)*(void**)(p + 8))->search(levels[i])->show();
                    ((J2DPane*)*(void**)(p + 8))->search(fires[i])->hide();
                    ((J2DPane*)*(void**)(p + 8))->search(dates[i])->show();
                    s32 icon;
                    icon = getFileIcon(0);
                    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(0x5466316c76ULL)), icon, 0, 0, 0);
                    icon = getFileIcon(1);
                    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(0x5466326c76ULL)), icon, 0, 0, 0);
                    icon = getFileIcon(2);
                    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(0x5466336c76ULL)), icon, 0, 0, 0);
                } else {
                    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(fires[i])), 0x6a, 0, 0, 0);
                    ((J2DPane*)*(void**)(p + 8))->search(levels[i])->hide();
                    ((J2DPane*)*(void**)(p + 8))->search(fires[i])->show();
                    ((J2DPane*)*(void**)(p + 8))->search(dates[i])->hide();
                }
                fn_803BDD44((u8*)p, i);
            } else {
                fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(fires[i])), 0x11d, 0, 0, 0);
                ((J2DPane*)*(void**)(p + 8))->search(levels[i])->hide();
                ((J2DPane*)*(void**)(p + 8))->search(fires[i])->show();
                ((J2DPane*)*(void**)(p + 8))->search(dates[i])->hide();
                p[0x115] |= (u8)(1 << i);
                fn_803BD5E0((u8*)p, i);
            }
        } else {
            fn_803832BC(getStringPtr__10J2DTextBoxCFv(((J2DPane*)*(void**)(p + 8))->search(fires[i])), 0x6a, 0, 0, 0);
            ((J2DPane*)*(void**)(p + 8))->search(levels[i])->hide();
            ((J2DPane*)*(void**)(p + 8))->search(fires[i])->show();
            ((J2DPane*)*(void**)(p + 8))->search(dates[i])->hide();
            fn_803BDD44((u8*)p, i);
        }
    }
}
#pragma opt_lifetimes reset
extern "C" void* lbl_8053ACA8;
extern "C" void* lbl_8053AED8;
extern "C" void fn_80431174(void* a, u8 b);
extern "C" u8 fn_802B1DCC(void* a);
extern "C" void fn_80440BF4(void* a, s32 b);
extern "C" void fn_80431A9C(void* a, u64 b);
extern "C" s32 fn_804317AC(void* a);
extern "C" s32 fn_80431740(void* a);
extern "C" f32 lbl_80543460;
extern "C" f32 lbl_8054345C;
#pragma opt_propagation off
extern "C" void fn_803CE9EC(u8* p) {
    u8* base;
    s32 st;
    u32 v;
    s16 pos;
    s16 lim;
    f32 t;

    *(s32*)(p + 0x1a8) = 3;
    if (p[0x116] == 1) {
        fn_80431174(lbl_8053AEC0, p[0x114]);
    }
    base = (u8*)lbl_8051C1A0;
    {
        if ((base[0x1ff5] == 0 || base[0x1ff5] == 1) && fn_802B1DCC(lbl_8053ACA8) == 0) {
            if (p[0x113] == 0 && p[0x117] == 0) {
                p[0x112] = p[0x110];
                p[0x110] = 1;
            }
        }
    }
    if (p[0x116] < 2) {
        (((Tu803CE9ECObj*)lbl_8053ADB0)->*(lbl_804AFD70[p[0x110]]))();
    }
    {
        if (p[0x110] != p[0x111]) {
            p[0x111] = p[0x110];
            switch (p[0x110]) {
            case 0:
            case 2:
            case 5:
            case 10:
            case 14:
            case 19:
                p[0x1a5] = 0;
                break;
            case 3: case 7: case 11: case 12: case 15:
                p[0x1a5] = 1;
                break;
            case 37: default:
                break;
            }
        }
        if (p[0x1a5] != p[0x1a6]) {
            p[0x1a4] = 2;
        } else if (p[0x1a4] == 2) {
            p[0x1a4] = 1;
        }
        switch (p[0x1a4]) {
        case 1:
            lim = *(s16*)(lbl_8050DB0C + 0x160);
            ++*(s16*)(p + 0xde);
            if (*(s16*)(p + 0xde) < lim) {
                t = (f32)(*(s16*)(p + 0xde) * *(s16*)(p + 0xde)) / (f32)(lim * lim);
                fn_80402E08(*(void**)(p + 0x58), lbl_80543458, lbl_80543460 * t + lbl_8054345C);
                u8* obj = *(u8**)(p + 0x58);
                (*(J2DTextBoxVt**)(obj + 4))->v9((s32)(t * (f32)obj[0x28]));
            } else {
                *(s16*)(p + 0xde) = lim;
                fn_80402E08(*(void**)(p + 0x58), 0.0f, 0.0f);
                u8* obj = *(u8**)(p + 0x58);
                (*(J2DTextBoxVt**)(obj + 4))->v9(obj[0x28]);
                p[0x1a4] = 0;
            }
            break;
        case 2:
            lim = *(s16*)(lbl_8050DB0C + 0x160);
            --*(s16*)(p + 0xde);
            if ((s16)*(s16*)(p + 0xde) > 0) {
                t = (f32)(*(s16*)(p + 0xde) * *(s16*)(p + 0xde)) / (f32)(lim * lim);
                fn_80402E08(*(void**)(p + 0x58), lbl_80543458, lbl_80543460 * t + lbl_8054345C);
                u8* obj = *(u8**)(p + 0x58);
                (*(J2DTextBoxVt**)(obj + 4))->v9((s32)(t * (f32)obj[0x28]));
            } else {
                *(s16*)(p + 0xde) = 0;
                fn_80402E08(*(void**)(p + 0x58), 0.0f, -200.0f);
                (*(J2DTextBoxVt**)(*(u8**)(p + 0x58) + 4))->v9(0);
                p[0x1a6] = p[0x1a5];
                if (p[0x1a5] == 0) fn_80440BF4(lbl_8053AED8, 1);
                else fn_80440BF4(lbl_8053AED8, 0);
                p[0x1a4] = 1;
            }
            break;
        }
    }
    u32 previous = *(u32*)(p + 0x7c);
    u32 next = *(u32*)(p + 0x80);
    if (previous != next) {
        if (p[0x116] == 0) {
            *(u32*)(p + 0x7c) = next;
            v = *(s32*)(p + 0x7c);
            if (v != 0) {
                if (v == 0x50 || v == 0x53 || v == 0x57 || v == 0x5c || v == 0x84 || v == 0x256) {
                    ((void (*)(void*, u32, s32, void*))fn_80431A9C)(lbl_8053AEC0, v, 0, p + 0x114);
                    p[0x1a3] = 0;
                } else {
                    ((void (*)(void*, u32, s32, void*))fn_80431A9C)(lbl_8053AEC0, v, 0, 0);
                    p[0x1a3] = 0;
                }
                p[0x116] = 2;
            }
        } else if (p[0x116] == 1) {
            p[0x116] = 3;
        }
    }
    if (p[0x116] == 2) {
        if (p[0x1a3] > 0x48) {
            p[0x1a3] = 0x50;
        } else {
            p[0x1a3] += 8;
        }
        if (fn_804317AC(lbl_8053AEC0) != 0) {
            p[0x1a3] = 0x50;
            p[0x116] = 1;
        }
    } else if (p[0x116] == 3) {
        if (p[0x1a3] < 8) {
            p[0x1a3] = 0;
        } else {
            p[0x1a3] -= 8;
        }
        if (fn_80431740(lbl_8053AEC0) != 0) {
            p[0x1a3] = 0;
            p[0x116] = 0;
        }
    }
    base[0x1ff5] = 2;
}
#pragma opt_propagation reset
extern "C" const u64 lbl_804769D0[];
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_805434B0;
extern "C" f32 lbl_805434B4;
extern "C" f32 lbl_805434B8;
extern "C" void fn_8013B490(void* a);
extern "C" void fn_804316EC(void* a);
extern "C" void fn_80440EE8(void* a);
extern "C" void fn_803BE3D8(void* a);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* a, f32 x, f32 y, void* ctx);
extern "C" void fn_803CEED4(u8* p) {
    f32 f31;
    f32 f30;

    for (int i = 0; i < 8; ++i) {
        if (((s32*)(p + 0xb8))[i] == 0) {
            *(s32*)(p + 0xb4) = i;
            break;
        }
    }

    if (*(s32*)(p + 0xb4) < 7) {
        f31 = getBounds__7J2DPaneFv(((J2DPane*)*(void**)(p + 4))->search(lbl_804769D0[4]))[0];
        f30 = getBounds__7J2DPaneFv(((J2DPane*)*(void**)(p + 4))->search(lbl_804769D0[*(s32*)(p + 0xb4)]))[0] - f31;
        f31 = getBounds__7J2DPaneFv(((J2DPane*)*(void**)(p + 4))->search(lbl_804769D0[4]))[1];
        f31 = getBounds__7J2DPaneFv(((J2DPane*)*(void**)(p + 4))->search(lbl_804769D0[*(s32*)(p + 0xb4)]))[1] - f31;

        {
            J2DPane* o = ((J2DPane*)*(void**)(p + 8))->search(0x0050616468753031ULL);
            o->move(*(f32*)(p + 0x88) + f30, *(f32*)(p + 0x94) + f31);
        }
        {
            J2DPane* o = ((J2DPane*)*(void**)(p + 4))->search(0x0050616468753032ULL);
            o->move(*(f32*)(p + 0x8c) + f30, *(f32*)(p + 0x98) + f31);
        }
        {
            J2DPane* o = ((J2DPane*)*(void**)(p + 4))->search(0x0050616468753033ULL);
            o->move(*(f32*)(p + 0x90) + f30, *(f32*)(p + 0x9c) + f31);
        }
    }

    fn_8013B490(lbl_8053AB10);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 4), lbl_80543458, lbl_80543458, *(void**)((u8*)lbl_8053AB10 + 0x10));

    {
        u8* q = *(u8**)(*(u8**)(p + 0x14) + 4);
        if (q[0xb0] != 0 && (*(u32*)(lbl_8050EC80 + *(u32*)(p + 0xa8) * 0xc8 + 0x28) & 1)) {
            if (fn_803B8CAC(*(u32*)(p + 0xa8), 0) && fn_803B8CAC(*(u32*)(p + 0xa8), 1) && fn_803B8CAC(*(u32*)(p + 0xa8), 2) && fn_803B8CAC(*(u32*)(p + 0xa8), 3) && fn_803B8CAC(*(u32*)(p + 0xa8), 4) && fn_803B8CAC(*(u32*)(p + 0xa8), 5) && fn_803B8CAC(*(u32*)(p + 0xa8), 6)) {
                if (((u8*)((J2DPane*)*(void**)(p + 8))->search(0x0050616468753031ULL))[0xb0] != 0) {
                    ((J2DPane*)*(void**)(p + 8))->search(0x0050616468753031ULL)->hide();
                    ((J2DPane*)*(void**)(p + 4))->search(0x0050616468753032ULL)->hide();
                    ((J2DPane*)*(void**)(p + 4))->search(0x0050616468753033ULL)->hide();
                }
            } else if (((u8*)((J2DPane*)*(void**)(p + 8))->search(0x0050616468753031ULL))[0xb0] == 0) {
                ((J2DPane*)*(void**)(p + 8))->search(0x0050616468753031ULL)->show();
                ((J2DPane*)*(void**)(p + 4))->search(0x0050616468753032ULL)->show();
                ((J2DPane*)*(void**)(p + 4))->search(0x0050616468753033ULL)->show();
            }
            fn_803BE3D8(p);
        } else {
            if (((u8*)((J2DPane*)*(void**)(p + 8))->search(0x0050616468753031ULL))[0xb0] == 0) {
                goto drawCursor;
            }
            ((J2DPane*)*(void**)(p + 8))->search(0x0050616468753031ULL)->hide();
            ((J2DPane*)*(void**)(p + 4))->search(0x0050616468753032ULL)->hide();
            ((J2DPane*)*(void**)(p + 4))->search(0x0050616468753033ULL)->hide();
        }
drawCursor:
        draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 8), lbl_80543458, lbl_80543458, *(void**)((u8*)lbl_8053AB10 + 0x10));
    }

    if (*(u8*)(p + 0x116) != 0) {
        (*(J2DPicture**)(p + 0x10))->setAlpha(p[0x1a3]);
        (*(J2DPicture**)(p + 0x10))->draw(lbl_805434B0, lbl_805434B0, lbl_805434B4, lbl_805434B8, false, false, false);
        fn_804316EC(lbl_8053AEC0);
    }
    fn_80440EE8(lbl_8053AED8);
}

extern "C" void fn_804310CC(void* a);
extern "C" void fn_803CF504(u8* p) {
    s32 i;
    const u8* tbl = lbl_804765D0;
    u8* q;
    u8* s50;
    *(s32*)(p + 0x1a8) = 3;
    fn_804310CC(lbl_8053AEC0);
    *(s32*)(p + 0x80) = 0;
    *(s32*)(p + 0x7c) = 0;
    *(s32*)(p + 0x84) = 0x117;
    *(u32*)(p + 0xa4) = (u8)lbl_80529DEC[0x23b];
    *(s32*)(p + 0xa0) = 0;
    *(s32*)(p + 0xa8) = 0;
    p[0x113] = 0;
    *(s32*)(p + 0xac) = 0;
    p[0x111] = 1;
    p[0x112] = 1;
    p[0x110] = 1;
    p[0x114] = 0;
    p[0x115] = 0;
    *(s32*)(p + 0xb0) = -1;
    *(s16*)(p + 0xdc) = 0;
    p[0x116] = 0;
    *(s32*)(p + 0xb4) = 0;
    p[0x117] = 0;
    if (*(u32*)(p + 0x84) == 0x117 && lbl_8053AAF8[0x7f] != 0) {
        *(u32*)(p + 0x84) = 0x116;
    }
    fn_803832BC(getStringPtr__10J2DTextBoxCFv(((KeyObjVt*)*(void**)(p + 8))->v15(*(u32*)(p + 0x84), 0x5466743031ULL)), *(s32*)(p + 0x84), 0, 0, 0);
    if (*(u32*)(p + 0x84) == 0x60 || *(u32*)(p + 0x84) == 0x64) {
        *(s32*)(p + 0xb0) = 0x5a;
    }
    for (i = 0; i < 8; i++) {
        *(u32*)(p + 0xb8 + i * 4) = fn_803B8CAC(0, i);
    }
    *(u8*)(*(u8**)(*(u8**)(p + 0x14) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(p + 0x18) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(p + 0x1c) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(p + 0x20) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(p + 0x34) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(p + 0x24) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(p + 0x28) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(p + 0x2c) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(p + 0x30) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(p + 0x50) + 4) + 0xb0) = 1;
    {
        u64* k15 = (u64*)(tbl);
        u64* k16 = (u64*)(tbl + 0x18);
        u64* k17 = (u64*)(tbl + 0x30);
        q = p;
        for (i = 0; i < 3; i++) {
            *(u8*)(*(u8**)(*(u8**)(q + 0x38) + 4) + 0xb0) = 1;
            *(u8*)(*(u8**)(*(u8**)(q + 0x44) + 4) + 0xb0) = 1;
            *(u8*)(((J2DPane*)*(void**)(p + 8))->search(*k15) + 0xb0) = 0;
            *(u8*)(((J2DPane*)*(void**)(p + 8))->search(*k16) + 0xb0) = 0;
            *(u8*)(((J2DPane*)*(void**)(p + 8))->search(*k17) + 0xb0) = 0;
            k15++;
            k16++;
            k17++;
            q += 4;
        }
    }
    fn_80402E08(*(void**)(p + 0x50), lbl_80543494, lbl_80543458);
    s50 = *(u8**)(p + 0x50);
    *(s16*)(s50 + 0x20) = 0;
    (*(VtSlot9**)(s50 + 4))->v9(s50 + 4, 0);
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723031ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723032ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723033ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    fn_804023D0(*(void**)(p + 0x50), ((J2DPane*)*(void**)(p + 8))->search(0x50666375723034ULL), *(u8*)(*(u8**)(p + 0x50) + 0x28));
    *(s16*)(s50 + 0x26) = 0;
    {
        u64* k780 = (u64*)(tbl + 0x780);
        u64* k768 = (u64*)(tbl + 0x768);
        u64* k750 = (u64*)(tbl + 0x750);
        u64* k6c8 = (u64*)(tbl + 0x6c8);
        u64* k6b0 = (u64*)(tbl + 0x6b0);
        u64* k698 = (u64*)(tbl + 0x698);
        u64* k680 = (u64*)(tbl + 0x680);
        u64* k668 = (u64*)(tbl + 0x668);
        u64* k650 = (u64*)(tbl + 0x650);
        u64* k638 = (u64*)(tbl + 0x638);
        u64* k620 = (u64*)(tbl + 0x620);
        u64* k608 = (u64*)(tbl + 0x608);
        u64* k5f0 = (u64*)(tbl + 0x5f0);
        u64* k5d8 = (u64*)(tbl + 0x5d8);
        u64* k5c0 = (u64*)(tbl + 0x5c0);
        u64* k5a8 = (u64*)(tbl + 0x5a8);
        u64* k590 = (u64*)(tbl + 0x590);
        u64* k578 = (u64*)(tbl + 0x578);
        u64* k560 = (u64*)(tbl + 0x560);
        u64* k548 = (u64*)(tbl + 0x548);
        u64* k530 = (u64*)(tbl + 0x530);
        u64* k518 = (u64*)(tbl + 0x518);
        u64* k500 = (u64*)(tbl + 0x500);
        u64* k4e8 = (u64*)(tbl + 0x4e8);
        u64* k4d0 = (u64*)(tbl + 0x4d0);
        u64* k4b8 = (u64*)(tbl + 0x4b8);
        for (i = 0; i < 3; i++) {
            fn_80402E08(*(void**)(p + 0x38), lbl_80543458, lbl_805434A0);
            *(s16*)(*(u8**)(p + 0x38) + 0x22) = 0;
            (*(VtSlot9**)(*(u8**)(p + 0x38) + 4))->v9(*(u8**)(p + 0x38) + 4, 0);
            fn_804023D0(*(void**)(p + 0x38), ((J2DPane*)*(void**)(p + 8))->search(*k780), p[0x125]);
            fn_804023D0(*(void**)(p + 0x38), ((J2DPane*)*(void**)(p + 8))->search(*k768), p[0x126]);
            fn_804023D0(*(void**)(p + 0x38), ((J2DPane*)*(void**)(p + 8))->search(*k750), p[0x127]);
            fn_804023D0(*(void**)(p + 0x38), ((J2DPane*)*(void**)(p + 8))->search(*k6c8), p[0x128]);
            fn_804023D0(*(void**)(p + 0x38), ((J2DPane*)*(void**)(p + 8))->search(*k6b0), p[0x129]);
            fn_804023D0(*(void**)(p + 0x38), ((J2DPane*)*(void**)(p + 8))->search(*k698), p[0x12a]);
            fn_804023D0(*(void**)(p + 0x38), ((J2DPane*)*(void**)(p + 8))->search(*k680), p[0x12b]);
            fn_804023D0(*(void**)(p + 0x38), ((J2DPane*)*(void**)(p + 8))->search(*k668), p[0x12c]);
            fn_804023D0(*(void**)(p + 0x38), ((J2DPane*)*(void**)(p + 8))->search(*k650), p[0x12d]);
            fn_804023D0(*(void**)(p + 0x38), ((J2DPane*)*(void**)(p + 8))->search(*k638), p[0x12e]);
            fn_804023D0(*(void**)(p + 0x38), ((J2DPane*)*(void**)(p + 8))->search(*k620), p[0x12f]);
            fn_804023D0(*(void**)(p + 0x38), ((J2DPane*)*(void**)(p + 8))->search(*k608), p[0x130]);
            fn_804023D0(*(void**)(p + 0x38), ((J2DPane*)*(void**)(p + 8))->search(*k5f0), p[0x131]);
            *(s16*)(*(u8**)(p + 0x38) + 0x26) = 0;
            fn_80402E08(*(void**)(p + 0x44), lbl_80543494, lbl_80543458);
            *(s16*)(*(u8**)(p + 0x44) + 0x20) = 0;
            (*(VtSlot9**)(*(u8**)(p + 0x44) + 4))->v9(*(u8**)(p + 0x44) + 4, 0);
            fn_804023D0(*(void**)(p + 0x44), ((J2DPane*)*(void**)(p + 8))->search(*k5d8), p[0x118]);
            fn_804023D0(*(void**)(p + 0x44), ((J2DPane*)*(void**)(p + 8))->search(*k5c0), p[0x119]);
            fn_804023D0(*(void**)(p + 0x44), ((J2DPane*)*(void**)(p + 8))->search(*k5a8), p[0x11a]);
            fn_804023D0(*(void**)(p + 0x44), ((J2DPane*)*(void**)(p + 8))->search(*k590), p[0x11b]);
            fn_804023D0(*(void**)(p + 0x44), ((J2DPane*)*(void**)(p + 8))->search(*k578), p[0x11c]);
            fn_804023D0(*(void**)(p + 0x44), ((J2DPane*)*(void**)(p + 8))->search(*k560), p[0x11d]);
            fn_804023D0(*(void**)(p + 0x44), ((J2DPane*)*(void**)(p + 8))->search(*k548), p[0x11e]);
            fn_804023D0(*(void**)(p + 0x44), ((J2DPane*)*(void**)(p + 8))->search(*k530), p[0x11f]);
            fn_804023D0(*(void**)(p + 0x44), ((J2DPane*)*(void**)(p + 8))->search(*k518), p[0x120]);
            fn_804023D0(*(void**)(p + 0x44), ((J2DPane*)*(void**)(p + 8))->search(*k500), p[0x121]);
            fn_804023D0(*(void**)(p + 0x44), ((J2DPane*)*(void**)(p + 8))->search(*k4e8), p[0x122]);
            fn_804023D0(*(void**)(p + 0x44), ((J2DPane*)*(void**)(p + 8))->search(*k4d0), p[0x123]);
            fn_804023D0(*(void**)(p + 0x44), ((J2DPane*)*(void**)(p + 8))->search(*k4b8), p[0x124]);
            *(s16*)(*(u8**)(p + 0x44) + 0x26) = 0;
            k780++; k768++; k750++; k6c8++; k6b0++; k698++; k680++; k668++; k650++; k638++;
            k620++; k608++; k5f0++; k5d8++; k5c0++; k5a8++; k590++; k578++; k560++; k548++;
            k530++; k518++; k500++; k4e8++; k4d0++; k4b8++;
        }
    }
    fn_80402E08(*(void**)(p + 0x54), lbl_80543458, lbl_805434A0);
    *(s16*)(*(u8**)(p + 0x54) + 0x22) = 0;
    (*(VtSlot9**)(*(u8**)(p + 0x54) + 4))->v9(*(u8**)(p + 0x54) + 4, 0);
    *(s16*)(*(u8**)(p + 0x54) + 0x26) = 0;
    *(s16*)(p + 0xde) = 0;
    p[0x1a4] = 0;
    p[0x1a5] = 0;
    p[0x1a6] = 0;
    fn_80402E08(*(void**)(p + 0x58), lbl_80543458, lbl_805434A0);
    (*(VtSlot9**)(*(u8**)(p + 0x58) + 4))->v9(*(u8**)(p + 0x58) + 4, 0);
    *(s16*)(p + 0xd8) = 0;
    *(s16*)(p + 0xda) = 0;
}

extern "C" u8* fn_803CFFBC(u8* p, s16 flags) {
    void** q;
    void** r;

    if (p != 0) {
        *(void**)p = lbl_804AFF60;
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 8));
        releaseSlot(*(void**)(p + 4));
        releaseSlot(*(void**)(p + 8));
        releaseSlot(*(void**)(p + 0x10));
        *(void**)(p + 0x10) = 0;
        releaseSlot(*(void**)(p + 0x14));
        *(void**)(p + 0x14) = 0;
        releaseSlot(*(void**)(p + 0x18));
        *(void**)(p + 0x18) = 0;
        releaseSlot(*(void**)(p + 0x1c));
        *(void**)(p + 0x1c) = 0;
        releaseSlot(*(void**)(p + 0x20));
        *(void**)(p + 0x20) = 0;

        q = (void**)p;
        for (int i = 0; i < 4; i++) {
            releaseSlot(q[9]);
            q[9] = 0;
            q++;
        }

        releaseSlot(*(void**)(p + 0x34));
        *(void**)(p + 0x34) = 0;

        r = (void**)p;
        for (int i = 0; i < 3; i++) {
            releaseSlot(r[0xe]);
            r[0xe] = 0;
            releaseSlot(r[0x11]);
            r[0x11] = 0;
            r++;
        }

        releaseSlot(*(void**)(p + 0x50));
        *(void**)(p + 0x50) = 0;
        releaseSlot(*(void**)(p + 0x54));
        *(void**)(p + 0x54) = 0;

        {
            void* obj = *(void**)(lbl_80529DEC + 0x30);
            ((DtorBase*)obj)->v1();
        }
        lbl_8053ADB0 = 0;
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void __construct_array(void* p, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void __ct__Q28JUtility6TColorFv(void* p);
extern "C" void fn_80403680(void* a);
extern "C" void fn_802FF798(void* a);
extern "C" u8* fn_803D0264(u8* p) {
    s32 i;
    *(void**)p = lbl_804AFF60;
    *(s32*)(p + 0xe0) = -1;
    *(s32*)(p + 0xe4) = -1;
    __construct_array(p + 0xe8, __ct__Q28JUtility6TColorFv, 0, 4, 5);
    __construct_array(p + 0xfc, __ct__Q28JUtility6TColorFv, 0, 4, 5);
    getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 8));
    lbl_8053AAF8[0xff] = 0;
    for (i = 0; i < 3; i++) {
        fn_803B950C(lbl_8050EC80 + i * 0xc8 + 0x20, lbl_8050EC80 + i * 0x9c4 + 0x280);
    }
    fn_80403680(lbl_80529DEC);
    if (lbl_80529DEC[0x242] == 0) {
        lbl_80529DEC[0x242] = 1;
        fn_802FF798(*(void**)((u8*)lbl_8053AB10 + 0x20));
    }
    return p;
}

extern "C" u8 lbl_804AFB90[];
extern "C" u8 lbl_80527E68[];
extern "C" void __register_global_object(void* object, void* destructor, void* registration);
extern "C" void __ct__17JASGenericMemPoolFv(void* p);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void* p);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void* p);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void* p);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void* p);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void* p);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void* p);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void* p);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void* p);
extern "C" void __dt__18JASMemPool_5JAISeFv(void* p);
#pragma opt_common_subs off
extern "C" void fn_803D24E4(void) {
    u8* registration=lbl_80527E68;
    u32* s = (u32*)lbl_804AFB90;
    u32* d = (u32*)(lbl_804AFB90 + 0x1e0);
    d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[3] = s[3]; d[4] = s[4]; d[5] = s[5]; d[6] = s[6]; d[7] = s[7];
    d[8] = s[8]; d[9] = s[9]; d[10] = s[10]; d[11] = s[11]; d[12] = s[12]; d[13] = s[13]; d[14] = s[14]; d[15] = s[15];
    d[16] = s[16]; d[17] = s[17]; d[18] = s[18]; d[19] = s[19]; d[20] = s[20]; d[21] = s[21]; d[22] = s[22]; d[23] = s[23];
    d[24] = s[24]; d[25] = s[25]; d[26] = s[26]; d[27] = s[27]; d[28] = s[28]; d[29] = s[29]; d[30] = s[30]; d[31] = s[31];
    d[32] = s[32]; d[33] = s[33]; d[34] = s[34]; d[35] = s[35]; d[36] = s[36]; d[37] = s[37]; d[38] = s[38]; d[39] = s[39];
    d[40] = s[40]; d[41] = s[41]; d[42] = s[42]; d[43] = s[43]; d[44] = s[44]; d[45] = s[45]; d[46] = s[46]; d[47] = s[47];
    d[48] = s[48]; d[49] = s[49]; d[50] = s[50]; d[51] = s[51]; d[52] = s[52]; d[53] = s[53]; d[54] = s[54]; d[55] = s[55];
    d[56] = s[56]; d[57] = s[57]; d[58] = s[58]; d[59] = s[59]; d[60] = s[60]; d[61] = s[61]; d[62] = s[62]; d[63] = s[63];
    d[64] = s[64]; d[65] = s[65]; d[66] = s[66]; d[67] = s[67]; d[68] = s[68]; d[69] = s[69]; d[70] = s[70]; d[71] = s[71];
    d[72] = s[72]; d[73] = s[73]; d[74] = s[74]; d[75] = s[75]; d[76] = s[76]; d[77] = s[77]; d[78] = s[78]; d[79] = s[79];
    d[80] = s[80]; d[81] = s[81]; d[82] = s[82]; d[83] = s[83]; d[84] = s[84]; d[85] = s[85]; d[86] = s[86]; d[87] = s[87];
    d[88] = s[88]; d[89] = s[89]; d[90] = s[90]; d[91] = s[91]; d[92] = s[92]; d[93] = s[93]; d[94] = s[94]; d[95] = s[95];
    d[96] = s[96]; d[97] = s[97]; d[98] = s[98]; d[99] = s[99]; d[100] = s[100]; d[101] = s[101]; d[102] = s[102]; d[103] = s[103];
    d[104] = s[104]; d[105] = s[105]; d[106] = s[106]; d[107] = s[107]; d[108] = s[108]; d[109] = s[109]; d[110] = s[110]; d[111] = s[111];
    d[112] = s[112]; d[113] = s[113]; d[114] = s[114]; d[115] = s[115]; d[116] = s[116]; d[117] = s[117]; d[118] = s[118]; d[119] = s[119];
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, (void*)__dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, registration);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, (void*)__dt__35JASMemPool_MultiThreaded_8JASTrackFv, registration + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, (void*)__dt__38JASMemPool_MultiThreaded_10JASChannelFv, registration + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, (void*)__dt__29JASMemPool_15JASPoolObj3_FSAFv, registration + 36);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, (void*)__dt__29JASMemPool_15JASPoolObj4_FSAFv, registration + 48);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, (void*)__dt__22JASMemPool_9JAIStreamFv, registration + 60);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, (void*)__dt__27JASMemPool_13JAISoundChildFv, registration + 72);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, (void*)__dt__19JASMemPool_6JAISeqFv, registration + 84);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, (void*)__dt__18JASMemPool_5JAISeFv, registration + 96);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}
#pragma opt_common_subs on
