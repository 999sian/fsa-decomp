// TU 0x80204d44-0x80206b30 (actor TZOK).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

struct TzokVec3 { f32 x, y, z; };

extern "C" u8 lbl_8046A238[];
extern "C" s32 fn_801D0280(u8* this_, s32 idx);
extern "C" void fn_80217484(void* p);
extern "C" void fn_8021BA30(void* p, u16 tag);

extern "C" bool fn_801CD2F8(s32 id);
extern "C" u8 fn_802046FC(void* base, void* a, void* b);
extern "C" u8 fn_801F2618(u8* p, u8* q, u8 c);
extern "C" u8 lbl_8053EFC0;
extern "C" u32 fn_801CD664(s32 id);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* reg, s32 id);
extern "C" s32 fn_801F8544(void* reg, u32 id, s32 room, void* pos, s32 kind);
extern "C" f32 lbl_8053F870;
extern "C" f32 lbl_8053F878;
extern "C" f32 lbl_8053F890;
extern "C" f32 lbl_8053F894;
extern "C" f32 lbl_8053F898;
struct TzokRng {
    u8 pad0[0xb4];
    u32 seed;
};
extern "C" TzokRng* lbl_8053AAF8;

static inline f32 tzokRand01() {
    TzokRng* g = lbl_8053AAF8;
    union {
        f32 f;
        u32 s;
    } out;
    g->seed = g->seed * 0x19660d + 0x3c6ef35f;
    out.s = (g->seed >> 9) | 0x3f800000;
    return out.f - lbl_8053F870;
}

// ---- fn_802064E0.cpp ----
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D7F40(void* record, s32 roomIdx);

// NEW ACTOR (vtable lbl_804A5A30). Room-membership predicate: true
// when this->0x354 (a room index) is set and matches via the confirmed
// fn_802D6A9C/fn_802D7F40 pair.
extern "C" s32 fn_802064E0(void* this_) {
    s32 result = 0;
    s32 roomIdx = *(s32*)((char*)this_ + 0x354);
    if (roomIdx != 0) {
        if (fn_802D7F40(fn_802D6A9C(), roomIdx)) {
            result = 1;
        }
    }
    return result;
}

// ---- fn_80206758_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern "C" void fn_801EE434(void* handle);
extern "C" void* fn_80204638(void);
extern "C" void fn_802049E0(void* base, void* this_);
extern void* lbl_804A5A30[];
extern void* lbl_804A46F4[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80206758(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5A30;
        fn_801EE434(*(void**)(p + 0x358));
        void* base = fn_80204638();
        fn_802049E0(base, this_);
        if (this_ != 0) {
            *(void**)p = lbl_804A46F4;
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

struct TzokActor {
    u8 pad0[4];
    s32 mRoom;
    u8 pad8[4];
    f32 mX;
    f32 mY;
    f32 mZ;
    u8 pad18[0x94 - 0x18];
    u16 m94;
    u8 pad96[0xc4 - 0x96];
    u8 mc4;
    u8 padc5[0x248 - 0xc5];
    s32 mState;
};

struct TzokGlobals {
    u8 pad0[0x24];
    void* m24;
};

extern TzokGlobals* lbl_8053AB10;
extern "C" void fn_8030C210(void* mgr, f32* pos);

extern "C" BOOL fn_80204D44(TzokActor* self) {
    BOOL r = FALSE;
    if (self->m94 == 1 || self->mc4 != 0) {
        r = TRUE;
    }
    return r;
}

extern "C" void fn_80204D6C(TzokActor* self) {
    if (self->mState != 9 && self->mState != 8) {
        fn_8030C210(lbl_8053AB10->m24, &self->mX);
    }
}

extern "C" void* fn_80230CFC(void* a);
extern "C" s16 fn_801F6874(void* a);
extern "C" f32* fn_8023E7B0(void* a);
extern "C" s32 fn_8023DE58(void* a);
extern "C" u8 fn_8022F514(void* a);
extern "C" void* fn_8022F3DC(void* a);
extern "C" f32* fn_8023E724(void* a);
extern "C" void fn_801CE32C(void);
extern f32 lbl_8053F860;
extern "C" void fn_80204DAC(void* this_) {
    char* p = (char*)this_;
    if (*(s32*)(p + 0x248) == 3) {
        if (*(u8*)(p + 0xc4) != 0) {
            *(void**)(p + 0x98) = fn_80230CFC(*(void**)(p + 0xc8));
            *(s16*)(p + 0x33c) = fn_801F6874(*(void**)(p + 0x98));
            TzokVec3* src = (TzokVec3*)fn_8023E7B0(*(void**)(p + 0xc8));
            f32 zero = lbl_8053F860;
            *(f32*)(p + 0xc) = src->x;
            *(f32*)(p + 0x10) = src->y;
            *(f32*)(p + 0x14) = src->z;
            *(f32*)(p + 0x3c) = zero;
            *(f32*)(p + 0x40) = zero;
            *(f32*)(p + 0x44) = zero;
            if (*(s32*)(p + 4) != fn_8023DE58(*(void**)(p + 0xc8))) {
                *(s32*)(p + 4) = fn_8023DE58(*(void**)(p + 0xc8));
                *(s32*)(p + 0x2a8) = 0;
                void* obj = *(void**)(p + 0xc8);
                if (fn_8022F514(obj)) {
                    obj = fn_8022F3DC(obj);
                }
                TzokVec3* pos = (TzokVec3*)fn_8023E724(obj);
                *(TzokVec3*)(p + 0x32c) = *pos;
            }
        }
    } else if ((*(u32*)(p + 0x230) & 7) == 0) {
        fn_801CE32C();
    }
}

extern "C" void fn_80204EB8(TzokActor* self) {
    bool outside = false;
    if (self->m94 == 1 && !fn_801CD2F8(self->mRoom)) {
        s32 room = self->mRoom;
        u8* cfg = (u8*)fn_802D6A9C();
        f32* rect = (f32*)(room < 8 ? cfg + 0xcc : cfg + 0xdc);
        f32 x = self->mX;
        bool inside = false;
        if (x >= rect[0] && self->mY >= rect[1] && x < rect[2] && self->mY < rect[3]) {
            inside = true;
        }
        if (!inside) {
            outside = true;
        }
    }
    if (outside) {
        return;
    }
    switch (self->mState) {
    case 1:
    case 2:
    case 6:
    case 8:
        break;
    default:
        return;
    }
    if (fn_802046FC(fn_80204638(), (u8*)self + 0x3c, &self->mX) != 0 &&
        (*(u32*)((u8*)self + 0x230) & 0x1000)) {
        fn_801F2618((u8*)self, (u8*)self + 0x264, lbl_8053EFC0);
    }
}

extern "C" u8 sincosTable___5JMath[];
extern "C" void fn_801D01A0(TzokActor* self, TzokVec3* pos, f32* out, f32 scale);
extern "C" void fn_80204FEC(TzokActor* self) {
    (*(void (**)(TzokActor*))(*(u8**)self + 0x84))(self);
    bool outside = false;
    if (self->m94 == 1 && !fn_801CD2F8(self->mRoom)) {
        s32 room = self->mRoom;
        u8* cfg = (u8*)fn_802D6A9C();
        f32* rect = (f32*)(room < 8 ? cfg + 0xcc : cfg + 0xdc);
        f32 x = self->mX;
        bool inside = false;
        if (x >= rect[0] && self->mY >= rect[1] && x < rect[2] && self->mY < rect[3]) {
            inside = true;
        }
        if (!inside) {
            outside = true;
        }
    }
    if (outside) {
        *(f32*)((u8*)self + 0x3c) = lbl_8053F860;
        *(f32*)((u8*)self + 0x40) = lbl_8053F860;
        return;
    }
    f32 out[2];
    switch (self->mState) {
    case 4:
        return;
    case 3:
    case 7:
        *(f32*)((u8*)self + 0x3c) = lbl_8053F860;
        *(f32*)((u8*)self + 0x40) = lbl_8053F860;
        return;
    case 5:
        out[0] = *(f32*)((u8*)self + 0x360);
        out[1] = *(f32*)((u8*)self + 0x364);
        *(f32*)((u8*)self + 0x3c) = out[0];
        *(f32*)((u8*)self + 0x40) = out[1];
        return;
    case 6:
    case 8:
    case 9: {
        u8* tbl = (u8*)sincosTable___5JMath + ((s32)*(s16*)((u8*)self + 0x33c) >> 2 & 0x3ff8);
        out[0] = *(f32*)tbl;
        out[1] = *(f32*)(tbl + 4);
        *(f32*)((u8*)self + 0x3c) = out[0] * *(f32*)((u8*)self + 0x254);
        *(f32*)((u8*)self + 0x40) = out[1] * *(f32*)((u8*)self + 0x254);
        return;
    }
    default:
        fn_801D01A0(self, (TzokVec3*)((u8*)self + 0x32c), out, *(f32*)((u8*)self + 0x254));
        *(f32*)((u8*)self + 0x3c) = out[0];
        *(f32*)((u8*)self + 0x40) = out[1];
        return;
    }
}

extern "C" void fn_80230C6C(s32 id);
extern "C" void fn_80205E0C(u8* self, s32 n);
extern "C" u8 fn_801CCFE4(s32 idx);
extern "C" u8 fn_80239C00(s32 idx, void* buf, s32 room);
extern "C" u8 fn_8022F9E4(s32 idx, void* a, s32 b, s32 c);
extern "C" void fn_801F31C4(void* self, void* buf);
extern "C" void fn_801CE0A4(void* self, s32 param);
extern "C" void fn_8020FADC(void* self);
extern "C" void fn_802051AC(void* this_, s32 param_2) {
    char* p = (char*)this_;
    if (p[0xc4] != 0 && *(s32*)(p + 0xc8) >= 0 && *(s32*)(p + 0xc8) < 4) {
        bool bVar1 = false;
        if (*(u8*)fn_80204638() == 0) {
            s32 room = *(s32*)(p + 0x354);
            if (room != 0 && fn_802D7F40(fn_802D6A9C(), room)) {
                bVar1 = true;
            }
        } else {
            bVar1 = true;
        }
        if (bVar1) {
            fn_80230C6C(*(s32*)(p + 0xc8));
        }
    }
    bool bVar1 = false;
    s32 room = *(s32*)(p + 0x354);
    if (room != 0 && fn_802D7F40(fn_802D6A9C(), room)) {
        bVar1 = true;
    }
    if (bVar1) {
        s32 st = *(s32*)(p + 0x248);
        if (st != 7) {
            if (st < 7) {
                if (st < 3 || st == 6) {
                    fn_80205E0C((u8*)p, 9);
                }
            } else if (st != 9) {
                fn_80205E0C((u8*)p, 9);
            }
        }
    }
    u8 c348 = *(u8*)(p + 0x348);
    if (c348 != 0) {
        *(u8*)(p + 0x348) = c348 - 1;
    }
    u8 c349 = *(u8*)(p + 0x349);
    if (c349 != 0) {
        *(u8*)(p + 0x349) = c349 - 1;
    }
    bVar1 = false;
    if (*(u16*)(p + 0x94) == 1 && !fn_801CD2F8(*(s32*)(p + 4))) {
        s32 r = *(s32*)(p + 4);
        f32* box = (f32*)((u8*)fn_802D6A9C() + (r < 8 ? 0xcc : 0xdc));
        f32 x = *(f32*)(p + 0xc);
        f32 y = *(f32*)(p + 0x10);
        bool inside = false;
        if (x >= box[0] && y >= box[1] && x < box[2] && y < box[3]) {
            inside = true;
        }
        if (!inside) {
            bVar1 = true;
        }
    }
    if (!bVar1) {
        s32 st = *(s32*)(p + 0x248);
        if (st != 9 && (st < 3 || st > 4)) {
            if (*(u8*)fn_80204638() == 0) {
                room = *(s32*)(p + 0x354);
                bool bVar2 = false;
                if (room != 0 && fn_802D7F40(fn_802D6A9C(), room)) {
                    bVar2 = true;
                }
                if (!bVar2) {
                    f32 buf[6];
                    fn_801F31C4(this_, buf);
                    s32 i = 0;
                    do {
                        if (fn_801CCFE4(i) && fn_8023DE58((void*)i) == *(s32*)(p + 4) &&
                            fn_80239C00(i, buf, *(s32*)(p + 4)) && fn_8022F9E4(i, *(void**)(p + 0x198), 1, 0)) {
                            fn_80205E0C((u8*)p, 3);
                            break;
                        }
                        i++;
                    } while (i < 4);
                }
            }
        }
        fn_801CE0A4(this_, param_2);
        fn_8020FADC(this_);
    }
}

extern "C" void fn_801D22A0(void* obj, s32 a, s32 b);
extern "C" void fn_801D2264(void* obj, s32 a, s32 b);
extern "C" void fn_801D22DC(void* obj, s32 a, s32 b, s32 c);
extern "C" void fn_801CE4BC(void* this_);
extern "C" void fn_80205478(void* this_) {
    char* p = (char*)this_;
    s32 state = *(s32*)(p + 0x248);
    switch (state) {
    case 5:
    case 7:
        return;
    }
    if (*(s32*)(p + 0x350) == 2) {
        fn_801D22A0(p + 0x270, *(s32*)(p + 0x98), 2);
    } else if (state == 0) {
        if (*(s32*)(p + 0x278) < 4 && *(s32*)(p + 0x278) >= 0) {
            fn_801D2264(p + 0x270, *(s32*)(p + 0x98), 2);
        } else {
            fn_801D22DC(p + 0x270, *(s32*)(p + 0x98), 2, 0);
        }
    } else if (*(s32*)(p + 0x278) < 4 && *(s32*)(p + 0x278) >= 0) {
        fn_801D22DC(p + 0x270, *(s32*)(p + 0x98) + 4, 2, 0);
    } else if (*(s32*)(p + 0x350) == 0) {
        fn_801D22A0(p + 0x270, *(s32*)(p + 0x98) + 4, 2);
    } else {
        fn_801D2264(p + 0x270, *(s32*)(p + 0x98) + 4, 2);
    }
    fn_801CE4BC(this_);
}

extern "C" void fn_80205E0C(u8* self, s32 n) {
    if (n == 7) {
        switch (*(s32*)(self + 0x248)) {
        case 3:
        case 4:
            return;
        }
    }
    switch (*(s32*)(self + 0x248)) {
    case 1:
    case 2:
    case 3:
        *(u32*)(self + 0x230) &= ~0x1000;
        break;
    }
    switch (n) {
    case 0: {
        s32 m1 = -1;
        f32 zero = lbl_8053F860;
        *(s32*)(self + 0x340) = m1;
        *(s32*)(self + 0x338) = m1;
        *(f32*)(self + 0x258) = zero;
        *(s32*)(self + 0x2a8) = 0;
        fn_80217484(self + 0x368);
        break;
    }
    case 1:
        *(s32*)(self + 0x340) = -1;
        *(u8*)(self + 0x348) = 0x1e;
        *(f32*)(self + 0x258) = *(f32*)(lbl_8046A238 + *(s32*)(self + 0x350) * 0x14);
        *(s32*)(self + 0x2a8) = 0;
        *(u32*)(self + 0x230) |= 0x1000;
        break;
    case 2:
        *(u8*)(self + 0x349) = 0x1e;
        *(f32*)(self + 0x258) = *(f32*)(lbl_8046A238 + *(s32*)(self + 0x350) * 0x14 + 4);
        *(u32*)(self + 0x230) |= 0x1000;
        break;
    case 3: {
        s32 m1 = -1;
        f32 zero = lbl_8053F860;
        *(s32*)(self + 0x340) = m1;
        *(s32*)(self + 0x338) = m1;
        *(f32*)(self + 0x254) = zero;
        *(f32*)(self + 0x258) = zero;
        *(f32*)(self + 0x3c) = zero;
        *(f32*)(self + 0x40) = zero;
        *(f32*)(self + 0x44) = zero;
        *(s32*)(self + 0x2a8) = 0;
        *(u32*)(self + 0x230) |= 0x1000;
        break;
    }
    case 4:
        *(s32*)(self + 0x110) = -1;
        break;
    case 5:
        *(s32*)(self + 0x340) = -1;
        *(s32*)(self + 0x338) = -1;
        *(s32*)(self + 0x2a8) = 0;
        break;
    case 6:
        *(s32*)(self + 0x340) = -1;
        *(u8*)(self + 0x348) = 0x1e;
        *(f32*)(self + 0x258) = *(f32*)(lbl_8046A238 + *(s32*)(self + 0x350) * 0x14);
        *(s32*)(self + 0x2a8) = 0;
        *(s16*)(self + 0x33c) = fn_801D0280(self, *(s32*)(self + 0x338)) - 0x8000;
        break;
    case 7: {
        s32 m1 = -1;
        f32 zero = lbl_8053F860;
        *(s32*)(self + 0x340) = m1;
        *(s32*)(self + 0x338) = m1;
        *(f32*)(self + 0x254) = zero;
        *(f32*)(self + 0x258) = zero;
        *(s32*)(self + 0x2a8) = 0;
        break;
    }
    case 8:
        *(s32*)(self + 0x340) = -1;
        *(s32*)(self + 0x338) = -1;
        *(f32*)(self + 0x258) = *(f32*)(lbl_8046A238 + *(s32*)(self + 0x350) * 0x14);
        *(s32*)(self + 0x2a8) = 0;
        fn_8021BA30(self + 0x374, *(s16*)(self + 0x33c));
        break;
    case 9:
        if (*(s32*)(self + 0x248) != 8) {
            *(s32*)(self + 0x340) = -1;
            *(s32*)(self + 0x338) = -1;
            *(f32*)(self + 0x258) = *(f32*)(lbl_8046A238 + *(s32*)(self + 0x350) * 0x14);
            *(s32*)(self + 0x2a8) = 0;
            fn_8021BA30(self + 0x374, *(s16*)(self + 0x33c));
        }
        break;
    }
    *(s32*)(self + 0x24c) = 0;
    *(s32*)(self + 0x248) = n;
}

struct TzokPt { f32 x, y; };
extern TzokPt lbl_8053AC60;

static inline f32 tzokDist2(TzokActor* p) {
    f32 dy = p->mY - lbl_8053AC60.y;
    f32 dx = p->mX - lbl_8053AC60.x;
    f32 dy2 = dy * dy;
    f32 dx2 = dx * dx;
    return dx2 + dy2;
}

extern "C" s32 fn_802068A0(TzokActor** a, TzokActor** b) {
    s32 r = 0;
    f32 da = tzokDist2(*a);
    f32 db = tzokDist2(*b);
    if (da < db) {
        r = -1;
    } else if (da > db) {
        r = 1;
    }
    return r;
}

extern "C" void fn_801D1974(void* self);
extern "C" void fn_80217484(void* p);
extern "C" void fn_8021BA30(void* p, u16 tag);

extern "C" void* fn_80206810(u8* self) {
    fn_801D1974(self);
    *(void***)self = lbl_804A5A30;
    *(s32*)(self + 0x340) = -1;
    *(s32*)(self + 0x344) = 0;
    self[0x348] = 0;
    self[0x349] = 0;
    self[0x34a] = 0;
    self[0x34b] = 0;
    self[0x34c] = 0;
    *(s32*)(self + 0x350) = 0;
    *(s32*)(self + 0x354) = 0;
    *(s32*)(self + 0x358) = 0;
    *(s32*)(self + 0x35c) = 0;
    *(f32*)(self + 0x360) = 0.0f;
    *(f32*)(self + 0x364) = 0.0f;
    fn_80217484(self + 0x368);
    fn_8021BA30(self + 0x374, 0);
    return self;
}

extern "C" bool fn_801CD2F8(s32 id);

struct TzokRect { f32 x0, y0, x1, y1; };

static inline u8 tzokInRect(TzokRect* r, f32* p) {
    return p[0] >= r->x0 && p[1] >= r->y0 && p[0] < r->x1 && p[1] < r->y1;
}

static inline TzokRect* tzokRoomRect(s32 room) {
    u8* cfg = (u8*)fn_802D6A9C();
    return room < 8 ? (TzokRect*)(cfg + 0xcc) : (TzokRect*)(cfg + 0xdc);
}

extern "C" BOOL fn_8020609C(TzokActor* self) {
    BOOL r = FALSE;
    if (self->m94 == 1 && !fn_801CD2F8(self->mRoom)) {
        TzokRect* rect = tzokRoomRect(self->mRoom);
        if (!tzokInRect(rect, &self->mX)) {
            r = TRUE;
        }
    }
    return r;
}

extern "C" void fn_80206168(char* p) {
    s32 kind;
    u32 n;
    bool b;

    if (*(u32*)(p + 0x344) != 0) {
        b = fn_801CD2F8(*(s32*)(p + 4));
        {
            u32 lim = fn_801CD664(0x1f) + 0x14;
            n = *(u32*)(p + 0x344);
            if (n >= lim) {
                n = lim;
            }
        }
        if (b && n >= 0x14) {
            n = n / 20 * 20;
        }
        *(u32*)(p + 0x344) -= n;
        while (n != 0) {
            if (n < 0x32) {
                if (n >= 0x14 && (b || tzokRand01() < lbl_8053F890)) {
                    kind = 2;
                    n -= 0x14;
                } else if (n >= 5 && (b || tzokRand01() < lbl_8053F890)) {
                    kind = 1;
                    n -= 5;
                } else {
                    kind = 0;
                    n -= 1;
                }
            } else {
                kind = 3;
                n -= 0x32;
            }
            s32 r = fn_801F8544(fn_801F856C(), 0x52555059, *(s32*)(p + 4), p + 0xc, kind);
            if (r < 0) {
                continue;
            }
            char* obj = (char*)fn_801F666C(fn_801F856C(), r);
            if (obj == 0) {
                continue;
            }
            TzokVec3 v;
            v.z = lbl_8053F898 * tzokRand01();
            v.y = lbl_8053F894 * (lbl_8053F878 * tzokRand01() - lbl_8053F870);
            v.x = lbl_8053F894 * (lbl_8053F878 * tzokRand01() - lbl_8053F870);
            *(TzokVec3*)(obj + 0x3c) = v;
            *(f32*)(obj + 0x44) = v.z;
        }
    }
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7274(void* pool, s32 param, void* out, s32 exceptId);
extern "C" u8 fn_801CF888(void* this_, void* a, void* b, s32 c);
extern "C" void qsort(void* base, size_t nmemb, size_t size, s32 (*compar)(void*, void*));
extern "C" s32 fn_802063FC(u8* this_) {
    TzokPt pt;
    TzokActor* list[1024];
    s32 count;
    s32 n;
    s32 i;
    s32 result;
    TzokActor** p;

    pt.x = *(f32*)(this_ + 0xc);
    pt.y = *(f32*)(this_ + 0x10);
    count = fn_801F7274(fn_801F856C(), *(s32*)(this_ + 4), list, -1);
    if (count >= 2) {
        lbl_8053AC60 = pt;
        qsort(list, count, 4, (s32 (*)(void*, void*))fn_802068A0);
    }
    p = list;
    result = -1;
    n = count > 20 ? 20 : count;
    for (i = 0; i < n; i++) {
        if (fn_801CF888(this_, &pt, &(*p)->mX, *(s32*)(this_ + 4)) == 0) {
            result = *(s32*)((u8*)*p + 0x198);
            break;
        }
        p++;
    }
    return result;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
