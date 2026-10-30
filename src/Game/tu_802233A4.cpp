// TU 0x802233a4-0x802242f4.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_80223534.cpp ----
extern "C" void fn_80221184(void* this_);
extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* table, s32 id);
extern "C" void fn_801CDC8C(void* this_, s32 event);
extern "C" void* fn_801EE434(void* handle);

extern "C" void fn_80223534(void* this_) {
    fn_80221184(this_);
    char* p = (char*)this_;
    if (*(u32*)(p + 0x2b8) != 0) {
        void* base = fn_8013C824();
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)base + 0xc), *(s32*)(p + 0x2b8));
        *(s32*)(p + 0x2b8) = 0;
    }
    fn_801CDC8C(this_, 0x4000E);
    fn_801EE434(*(void**)(p + 0x2bc));
    fn_801EE434(*(void**)(p + 0x2c0));
    *(s32*)(p + 0x2bc) = 0;
    *(s32*)(p + 0x2c0) = 0;
}

// ---- fn_80223F90_dtor.cpp ----
extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* table, s32 id);
extern "C" void fn_801CDC8C(void* this_, s32 event);
extern "C" void* fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6D00[];
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80223F90(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6D00;
        if (*(u32*)(p + 0x2b8) != 0) {
            void* base = fn_8013C824();
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)base + 0xc), *(s32*)(p + 0x2b8));
            *(s32*)(p + 0x2b8) = 0;
        }
        fn_801CDC8C(this_, 0x4000E);
        fn_801EE434(*(void**)(p + 0x2bc));
        fn_801EE434(*(void**)(p + 0x2c0));
        *(s32*)(p + 0x2bc) = 0;
        *(s32*)(p + 0x2c0) = 0;
        if (this_ != 0) {
            *(void**)p = lbl_804A6A00;
            if (this_ != 0) {
                *(void**)p = lbl_804A4808;
                if (p + 0x270 != 0) {
                    if (p + 0x294 != 0) {
                        *(void**)(p + 0x294) = lbl_8049CC34;
                    }
                }
                __dt__5ActorFv(this_, 0);
            }
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- fn_80224084_ctor.cpp ----
extern "C" void* fn_802218C8(void* this_);
extern void* lbl_804A6D00[];

extern "C" void* fn_80224084(void* this_) {
    fn_802218C8(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_804A6D00;
    *(s32*)(p + 0x2b8) = 0;
    *(s32*)(p + 0x2bc) = 0;
    *(s32*)(p + 0x2c0) = 0;
    return this_;
}


// ---- fn_802233A4 / fn_802235B0 / fn_80223608 / fn_80223F14 ----
extern "C" {
extern f32 lbl_8053EFB8;
s32 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
void fn_80221250(void* this_);
void fn_801CE4E8(void* this_);
void fn_80221210(void* this_);
void fn_8013CB44(void* h, void* pos, u32 a, u32 b, u32 c);
void fn_802217C8(void* this_);
void fn_801D22DC(void* anim, s32 idx, s32 a, s32 b);

struct Rect_802233A4 {
    Rect_802233A4() {}
    Rect_802233A4(f32 a, f32 b, f32 c, f32 d) { x0 = a; y0 = b; x1 = c; y1 = d; }
    void set(f32 a, f32 b, f32 c, f32 d) { x0 = a; y0 = b; x1 = c; y1 = d; }
    void add(f32 dx, f32 dy) { x0 += dx; y0 += dy; x1 += dx; y1 += dy; }
    bool isValid() const { return x1 - x0 > 0.0f && y1 - y0 > 0.0f; }
    f32 x0, y0, x1, y1;
};

static inline void AddRect_802233A4(f32& x0, f32& y0, f32& x1, f32& y1, f32 dx, f32 dy) {
    x0 += dx;
    y0 += dy;
    x1 += dx;
    y1 += dy;
}

static inline void CalcRect_802233A4(char* p, Rect_802233A4& r) {
    r.set(1.0f, 1.0f, -1.0f, -1.0f);
    if (*(s32*)(p + 0x248) == 5) {
        r.set(-8.0f, -8.0f, 8.0f, 8.0f);
        switch (*(s32*)(p + 0x98)) {
        case 0:
            r.add(16.0f, 0.0f);
            break;
        case 1:
            r.add(-16.0f, 0.0f);
            break;
        case 2:
            r.add(0.0f, 16.0f);
            break;
        case 3:
            r.add(0.0f, -16.0f);
            break;
        }
    }
}

s32 fn_802233A4(void* this_) {
    char* p = (char*)this_;
    s32 ret = 0;
    Rect_802233A4 r;
    CalcRect_802233A4(p, r);
    if (r.x1 - r.x0 > 0.0f && r.y1 - r.y0 > 0.0f) {
        Rect_802233A4 save = *(Rect_802233A4*)(p + 0x60);
        *(Rect_802233A4*)(p + 0x60) = r;
        ret = fn_801F2B7C(this_, *(s32*)(p + 0x114), -1, 1);
        *(Rect_802233A4*)(p + 0x60) = save;
    }
    return ret;
}

void fn_802235B0(void* this_) {
    char* p = (char*)this_;
    switch (*(s32*)(p + 0x248)) {
    case 2:
        fn_80221250(this_);
        break;
    case 6:
        *(f32*)(p + 0x44) += lbl_8053EFB8;
        break;
    default:
        fn_801CE4E8(this_);
        break;
    }
}

void fn_80223608(void* this_) {
    char* p = (char*)this_;
    fn_80221210(this_);
    fn_8013CB44(*(void**)(p + 0x2bc), p + 0xc, 0, 0, 1);
    fn_8013CB44(*(void**)(p + 0x2c0), p + 0xc, 0, 0, 1);
}

void fn_80223F14(void* this_) {
    char* p = (char*)this_;
    fn_802217C8(this_);
    *(u32*)(p + 0x98) = *(u32*)(p + 0x90) & 3;
    *(u32*)(p + 0x230) &= ~0x100;
    *(s32*)(p + 0x248) = 4;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = 0.0f;
    *(f32*)(p + 0x258) = 0.0f;
    fn_801D22DC(p + 0x270, 2, 0, 0);
}
}

// ---- fn_80223664 (update) / fn_802238CC (spawn rect corners) ----
#include "JSystem/JGeometry.h"

extern "C" {
extern const f32 lbl_8053FE70;
extern void* lbl_8053AC98;
void fn_80221408(void* this_);
void fn_80221334(void* this_);
void fn_802212AC(void* this_);
void fn_802216E8(void* this_, s32 t);
void fn_8022149C(void* this_, s32 a);
void fn_801F0E34(void* this_, s32 p1, s32 p2);
u16 fn_8022461C(void* pos, u32 room);
u8 fn_80224B88(void* pos, u32 room);
u8 fn_80224E88(void* pos, u32 room);
s32 fn_801CD30C(s32 val);
void fn_802A20F0(void* mgr, JGeometry::TVec3<f32>* pos, s32 a, u32 room, s32 b, s32 c);
void fn_80223AD8(void* this_, s32 state);
void fn_802238CC(void* this_);


void fn_80223664(void* this_, u8 flag) {
    char* p = (char*)this_;
    switch (*(u32*)(p + 0x248)) {
    case 0:
        fn_80221408(this_);
        break;
    case 1:
        fn_80221334(this_);
        break;
    case 2:
        fn_802212AC(this_);
        break;
    case 3:
        if (*(s32*)(p + 0x24c) >= 0x78) {
            fn_80223AD8(this_, 5);
        }
        break;
    case 4:
        fn_802216E8(this_, 0x78);
        if (*(f32*)(p + 0x14) <= 0.0f) {
            if (*(u32*)(p + 0x230) & 0x2000) {
                fn_80223AD8(this_, 5);
            } else {
                *(f32*)(p + 0x44) = lbl_8053FE70;
            }
        }
        break;
    case 5: {
        s32 se = 0x400e7;
        if (fn_8022461C(p + 0xc, *(u32*)(p + 0x4)) == 0x39) {
            se = 0x400e8;
        } else if (fn_80224B88(p + 0xc, *(u32*)(p + 0x4))) {
            se = 0x400e9;
        } else if (fn_80224E88(p + 0xc, *(u32*)(p + 0x4))) {
            se = 0x400ea;
        }
        fn_801F0E34(this_, se, 0);
        fn_802238CC(this_);
        if (*(s32*)(p + 0x24c) > 1 && flag) {
            fn_801EE434(*(void**)(p + 0x2bc));
            fn_801EE434(*(void**)(p + 0x2c0));
            *(s32*)(p + 0x2bc) = 0;
            *(s32*)(p + 0x2c0) = 0;
            fn_80223AD8(this_, 6);
        }
        break;
    }
    case 6:
        if (*(s32*)(p + 0x24c) > 1 && *(f32*)(p + 0x14) <= 0.0f) {
            fn_80223AD8(this_, 7);
        }
        break;
    case 7:
        if (*(s32*)(p + 0x24c) >= 0x7b) {
            if (*(u32*)(p + 0x2b8) != 0) {
                void* base = fn_8013C824();
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)base + 0xc), *(s32*)(p + 0x2b8));
                *(s32*)(p + 0x2b8) = 0;
            }
            fn_801CDC8C(this_, 0x4000E);
            fn_80223AD8(this_, 8);
        } else if (*(s32*)(p + 0x24c) % 6 == 0) {
            *(s32*)(p + 0x98) = fn_801CD30C(*(s32*)(p + 0x98));
            fn_801D22DC(p + 0x270, *(s32*)(p + 0x98), 0, 0);
        }
        break;
    case 8:
        if (*(s32*)(p + 0x24c) >= 0x1e) {
            fn_8022149C(this_, 1);
        }
        break;
    }
}

extern "C" const f32 lbl_8053FF1C;
void fn_802238CC(void* this_) {
    f32 y1;
    f32 x1;
    f32 y0;
    f32 x0;
    char* p = (char*)this_;
    y0 = x0 = 1.0f;
    y1 = x1 = -1.0f;
    if (*(s32*)(p + 0x248) == 5) {
        y0 = x0 = -8.0f;
        y1 = x1 = 8.0f;
        switch (*(s32*)(p + 0x98)) {
        case 0:
            AddRect_802233A4(x0, y0, x1, y1, 16.0f, 0.0f);
            break;
        case 1:
            AddRect_802233A4(x0, y0, x1, y1, -16.0f, 0.0f);
            break;
        case 2:
            AddRect_802233A4(x0, y0, x1, y1, 0.0f, 16.0f);
            break;
        case 3:
            AddRect_802233A4(x0, y0, x1, y1, 0.0f, -16.0f);
            break;
        }
    }
    if (x1 - x0 > 0.0f && y1 - y0 > 0.0f) {
        f32 dx = *(f32*)(p + 0xc);
        f32 dy = *(f32*)(p + 0x10);
        x0 += dx;
        y0 += dy;
        x1 += dx;
        y1 += dy;
        JGeometry::TVec3<f32>* v;
        u32 room;
        JGeometry::TVec3<f32> a;
        v = &a;
        room = *(u32*)(p + 0x4);
        a.set(x0, y0, lbl_8053FF1C);
        fn_802A20F0(lbl_8053AC98, v, -1, room, 0, 0);
        JGeometry::TVec3<f32> b;
        v = &b;
        room = *(u32*)(p + 0x4);
        b.set(x1, y0, lbl_8053FF1C);
        fn_802A20F0(lbl_8053AC98, v, -1, room, 0, 0);
        JGeometry::TVec3<f32> c;
        v = &c;
        room = *(u32*)(p + 0x4);
        c.set(x1, y1, lbl_8053FF1C);
        fn_802A20F0(lbl_8053AC98, v, -1, room, 0, 0);
        JGeometry::TVec3<f32> d;
        v = &d;
        room = *(u32*)(p + 0x4);
        d.set(x0, y1, lbl_8053FF1C);
        fn_802A20F0(lbl_8053AC98, v, -1, room, 0, 0);
    }
}

extern "C" void fn_801D22A0(void* anim, s32 idx, s32 a);
extern "C" s32 fn_8013CC50(u32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" u8 fn_801CD2F8(s32 room);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7884(void* mgr, u32 kind, s32 room);
extern "C" void* fn_801F666C(void* mgr, s32 id);
extern "C" void fn_8036D858(void* actor, JGeometry::TVec3<f32>* pos);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D79E8(void* mgr, s32 room, s32 a, f32 b, f32 c);
extern "C" void fn_80134DE4(void* game, s32 a, s32 b);
extern "C" void fn_802F601C(void* h, JGeometry::TVec3<f32>* pos, f32 a, f32 b, s32 c, JGeometry::TVec3<f32>* dir);
extern void* lbl_8053AAF8;
extern void* lbl_8053AB10;
extern "C" void fn_80223AD8(void* this_, s32 state) {
    char* p = (char*)this_;
    JGeometry::TVec3<f32> d;
    JGeometry::TVec3<f32> n;
    JGeometry::TVec3<f32> q;
    JGeometry::TVec3<f32> pos6;
    JGeometry::TVec3<f32> pos7;
    JGeometry::TVec3<f32> tmp;
    switch (state) {
    case 5:
        *(f32*)(p + 0x258) = 2.5f;
        fn_801D22A0(p + 0x270, *(s32*)(p + 0x98) + 0x14, 2);
        *(s32*)(p + 0x2bc) = fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, 0x116, 0, 0, 0, 0, 1, 1.0f);
        *(s32*)(p + 0x2c0) = fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, 0x115, 0, 0, 0, 0, 1, 1.0f);
        break;
    case 6: {
        *(f32*)(p + 0x258) = 0.0f;
        JGeometry::TVec3<f32>* vel = (JGeometry::TVec3<f32>*)(p + 0x3c);
        vel->set(-vel->x, -vel->y, 0.0f);
        vel->normalize();
        vel->scale(1.2f);
        *(f32*)(p + 0x44) = 4.0f;
        fn_801D22DC(p + 0x270, *(s32*)(p + 0x98) + 0xc, 0, 0);
        if (!fn_801CD2F8(*(s32*)(p + 0x4))) {
            s32 id = fn_801F7884(fn_801F856C(), 'LFGN', *(s32*)(p + 0x4));
            if (id >= 0) {
                void* a = fn_801F666C(fn_801F856C(), id);
                if (a != 0) {
                    pos6 = *(JGeometry::TVec3<f32>*)(p + 0xc);
                    fn_8036D858(a, &pos6);
                }
            }
        }
        fn_801F0E34(this_, 0x400eb, 0);
        d.set(0.0f, 0.0f, 0.0f);
        switch (*(s32*)(p + 0x98)) {
        case 0:
        case 1:
            d.set(0.0f, -8.0f, 0.0f);
            fn_802D79E8(fn_802D6A9C(), *(s32*)(p + 0x4), 0, 0.0f, 4.0f);
            break;
        default:
            fn_802D79E8(fn_802D6A9C(), *(s32*)(p + 0x4), 0, 4.0f, 0.0f);
            break;
        }
        fn_80134DE4(lbl_8053AAF8, 1, 0);
        n.set(-vel->x, -vel->y, 0.0f);
        n.normalize();
        tmp = *(JGeometry::TVec3<f32>*)(p + 0xc);
        tmp += d;
        q = tmp;
        if (*(s32*)(p + 0x4) < 8) {
            fn_802F601C(*(void**)((u8*)lbl_8053AB10 + 0x20), &q, 1.0f, 1.0f, 3, &n);
        }
        break;
    }
    case 7:
    case 8:
        *(f32*)(p + 0x254) = 0.0f;
        *(f32*)(p + 0x258) = 0.0f;
        *(f32*)(p + 0x3c) = 0.0f;
        *(f32*)(p + 0x40) = 0.0f;
        fn_801D22A0(p + 0x270, *(s32*)(p + 0x98), 0);
        if (state == 7) {
            pos7 = *(JGeometry::TVec3<f32>*)(p + 0xc);
            *(s32*)(p + 0x2b8) = fn_8013CC50(*(s32*)(p + 0x4), &pos7, 0x565, 0, 1, 0, 0, 1, 0.5f);
            fn_801F0E34(this_, 0x4000e, 0);
        }
        break;
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x248) = state;
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
