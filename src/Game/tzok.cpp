// TU 0x80204d44-0x80206b30 (actor TZOK).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

extern "C" bool fn_801CD2F8(s32 id);
extern "C" u8 fn_802046FC(void* base, void* a, void* b);
extern "C" u8 fn_801F2618(u8* p, u8* q, u8 c);
extern "C" u8 lbl_8053EFC0;

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
            f32 zero = lbl_8053F860;
            *(void**)(p + 0x98) = fn_80230CFC(*(void**)(p + 0xc8));
            *(s16*)(p + 0x33c) = fn_801F6874(*(void**)(p + 0x98));
            f32* src = fn_8023E7B0(*(void**)(p + 0xc8));
            *(f32*)(p + 0xc) = src[0];
            *(f32*)(p + 0x10) = src[1];
            *(f32*)(p + 0x14) = src[2];
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
                f32* pos = fn_8023E724(obj);
                *(f32*)(p + 0x32c) = pos[0];
                *(f32*)(p + 0x330) = pos[1];
                *(f32*)(p + 0x334) = pos[2];
            }
        }
    } else if ((*(u32*)(p + 0x230) & 7) == 0) {
        fn_801CE32C();
    }
}

extern "C" void fn_80204EB8(TzokActor* self) {
    bool outside = false;
    if (self->m94 == 1 && !fn_801CD2F8(self->mRoom)) {
        u8* cfg = (u8*)fn_802D6A9C();
        f32* rect = (f32*)(self->mRoom < 8 ? cfg + 0xcc : cfg + 0xdc);
        bool inside = false;
        if (self->mX >= rect[0] && self->mY >= rect[1] && self->mX < rect[2] && self->mY < rect[3]) {
            inside = true;
        }
        if (!inside) {
            outside = true;
        }
    }
    if (outside) {
        return;
    }
    s32 state = self->mState;
    if (state != 6) {
        if (state < 6) {
            if (state >= 3) {
                return;
            }
            if (state < 1) {
                return;
            }
        } else if (state != 8) {
            return;
        }
    }
    if (fn_802046FC(fn_80204638(), (u8*)self + 0x3c, &self->mX) != 0 &&
        (*(u32*)((u8*)self + 0x230) & 0x1000)) {
        fn_801F2618((u8*)self, (u8*)self + 0x264, lbl_8053EFC0);
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
        if (*(s32*)(p + 0x278) >= 4) {
            fn_801D22DC(p + 0x270, *(s32*)(p + 0x98), 2, 0);
        } else if (*(s32*)(p + 0x278) >= 0) {
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

struct TzokPt { f32 x, y; };
struct TzokVec3 { f32 x, y, z; };
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
