// TU 0x80207d84-0x80208e5c (actor SLMN).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

#include "JSystem/JGeometry/Vec.h"
typedef JGeometry::TVec3<f32> Vec3f;

// ---- Slmn_ctor_80208BE0.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_80207AC0(void* this_);
extern void* lbl_804A5BD8[];

extern "C" void* fn_80208BE0(void* this_) {
    fn_80207AC0(this_);
    *(void**)this_ = lbl_804A5BD8;
    *(s32*)((char*)this_ + 0x340) = 0;
    *(u8*)((char*)this_ + 0x344) = 0;
    *(u8*)((char*)this_ + 0x345) = 0;
    *(s16*)((char*)this_ + 0x346) = 0;
    *(s16*)((char*)this_ + 0x348) = 0;
    *(u8*)((char*)this_ + 0x34a) = 0;
    return this_;
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A5B28[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80207D84(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5BD8;
        if (this_ != 0) {
            *(void**)p = lbl_804A5B28;
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
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80208244(char* this_, s32 state);

extern "C" void fn_80207E24(char* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 4:
        fn_80208244(this_, 2);
        break;
    }
}

extern "C" BOOL fn_80207E58(char* this_) {
    BOOL r = FALSE;
    switch (*(s32*)(this_ + 0x248)) {
    case 3:
        if (*(u8*)(this_ + 0x34a) >= 10) {
            fn_80208244(this_, 6);
            r = TRUE;
        } else {
            fn_80208244(this_, 2);
        }
        break;
    case 6:
        r = TRUE;
        break;
    }
    return r;
}

extern "C" void fn_80207ECC(char* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
        fn_80208244(this_, 3);
        break;
    }
}

extern const f32 lbl_8053F8E0;

extern "C" void fn_80207F00(char* this_) {
    f32 z = lbl_8053F8E0;
    *(f32*)(this_ + 0x3c) = z;
    *(f32*)(this_ + 0x40) = z;
    *(f32*)(this_ + 0x44) = z;
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 id);
extern "C" void fn_80209CA4(void* obj, s32 a, s32 b, void* c, s32 d);
extern "C" void fn_80209D44(void* obj);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" u16 fn_80226850(void* pos, s32 room);

struct SlmnPart {
    s32 id;       // 0x2b0
    u8 inactive;  // 0x2b4
    u8 pad5[3];
    s32 a;        // 0x2b8
    s32 b;        // 0x2bc
    u8 c[0xc];    // 0x2c0
    s32 d;        // 0x2cc
    u8 dead;      // 0x2d0
    u8 pad21[3];
};

struct Slmn {
    u8 pad0[0x248];
    s32 state; // 0x248
    u8 pad24c[0x2b0 - 0x24c];
    SlmnPart parts[4]; // 0x2b0
};

extern "C" void fn_80208834(char* this_) {
    if (*(s32*)(this_ + 0x248) != 7) {
        fn_80208244(this_, 7);
    }
    for (s32 i = 0; i < 4; i++) {
        void* a = fn_801F666C(fn_801F856C(), ((Slmn*)this_)->parts[i].id);
        if (a != 0) {
            fn_80209CA4(a, ((Slmn*)this_)->parts[i].a, ((Slmn*)this_)->parts[i].b, ((Slmn*)this_)->parts[i].c, ((Slmn*)this_)->parts[i].d);
        }
    }
}

extern "C" void fn_802088B4(char* this_) {
    if (*(s32*)(this_ + 0x248) != 5) {
        fn_80208244(this_, 5);
    }
    for (s32 i = 0; i < 4; i++) {
        void* a = fn_801F666C(fn_801F856C(), ((Slmn*)this_)->parts[i].id);
        if (a != 0) {
            fn_80209D44(a);
        }
    }
}

extern "C" void fn_80208924(char* this_) {
    *(u16*)(this_ + 0x346) = fn_8022461C(this_ + 0xc, *(s32*)(this_ + 0x4));
    *(u16*)(this_ + 0x348) = fn_80226850(this_ + 0xc, *(s32*)(this_ + 0x4));
}

extern "C" s32 fn_801CD664(s32 range);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801F3604(void* this_);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 owner, void* pos, u32 param, s32 a, s32 b);
extern const f32 lbl_8053F8E4;
extern const f32 lbl_8053F8E8;
extern const f32 lbl_8053F8F8;
extern const f32 lbl_8053F910;

static inline void slmnSpawn(char* this_) {
    Vec3f pos; f32 dy; f32 dx; Vec3f* at; s32 param; s32 i;
    fn_801F3604(this_);
    pos = *(Vec3f*)(this_ + 0xc);
    dy = dx = lbl_8053F8E0;
    switch (*(s32*)(this_ + 0x2ac)) {
    case 0:
        pos.x -= lbl_8053F8E8;
        dx = lbl_8053F8E4;
        break;
    case 1:
        pos.y -= lbl_8053F8E8;
        dy = lbl_8053F8E4;
        break;
    }
    for (i = 0; i < 4; i++) {
        param = *(s32*)(this_ + 0x198);
        if (*(s32*)(this_ + 0x340) == 3) {
            at = (Vec3f*)(this_ + 0xc);
        } else {
            at = &pos;
        }
        ((Slmn*)this_)->parts[i].id = Actor_CreateByID(fn_801F856C(), 0x464f534c, *(s32*)(this_ + 0x4), at, param, -1, -1);
        char* a = (char*)fn_801F666C(fn_801F856C(), ((Slmn*)this_)->parts[i].id);
        if (a != 0) {
            *(s16*)(a + 0x94) = i;
            if (*(s32*)(this_ + 0x340) == 3) {
                *(Vec3f*)(a + 0x24) = pos;
            }
        }
        pos.x += dx;
        pos.y += dy;
    }
}

extern "C" void fn_8020896C(char* this_) {
    fn_801D0ED0(this_);
    *(s32*)(this_ + 0x2ac) = *(u32*)(this_ + 0x90) & 3;
    if (*(s32*)(this_ + 0x2ac) >= 2 || *(s32*)(this_ + 0x2ac) < 0) {
        *(s32*)(this_ + 0x2ac) = fn_801CD664(2);
    }
    s32 kind = (*(u32*)(this_ + 0x90) >> 4) & 3;
    if (kind > 3) {
        kind = 3;
    } else if (kind < 0) {
        kind = 0;
    }
    *(s32*)(this_ + 0x340) = kind;
    *(u8*)(this_ + 0x344) = *(u32*)(this_ + 0x90) >> 8;
    f32 hi = lbl_8053F910;
    f32 lo = lbl_8053F8F8;
    *(f32*)(this_ + 0x60) = lo;
    *(f32*)(this_ + 0x64) = lo;
    *(f32*)(this_ + 0x68) = hi;
    *(f32*)(this_ + 0x6c) = hi;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    *(f32*)(this_ + 0x80) = lo;
    *(f32*)(this_ + 0x84) = lo;
    *(f32*)(this_ + 0x88) = hi;
    *(f32*)(this_ + 0x8c) = hi;
    *(s32*)(this_ + 0xb0) = 0;
    *(s32*)(this_ + 0x98) = 2;
    *(u32*)(this_ + 0x230) |= 0x380;
    *(s32*)(this_ + 0x108) = 1000;
    *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x108);
    if (*(s32*)(this_ + 0x340) == 0) {
        *(s32*)(this_ + 0x248) = 2;
        *(s32*)(this_ + 0x250) = fn_801CD664(0x79) + 0x3c;
        slmnSpawn(this_);
    } else {
        *(s32*)(this_ + 0x248) = 0;
        *(s32*)(this_ + 0x250) = -1;
    }
    *(s32*)(this_ + 0x24c) = 0;
    *(f32*)(this_ + 0x254) = lbl_8053F8E0;
    *(f32*)(this_ + 0x258) = lbl_8053F8E0;
}

extern "C" void fn_80207A60(void* this_);
extern "C" u8 fn_801D08B4(void* this_, s32 player, void* pos, f32 r);
extern "C" u8 fn_801D0B44(void* this_, s32 player);
extern "C" u8 fn_801D0D50(void* this_, s32 player, void* pos, f32 r);

extern "C" void fn_80207F14(char* this_) {
    fn_80207A60(this_);
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
        break;
    case 3:
        break;
    case 0: {
        u8 go; f32 r; s32 j; s32 bit; s32 i;
        go = FALSE;
        r = lbl_8053F8E4 * *(u8*)(this_ + 0x344);
        switch (*(s32*)(this_ + 0x340)) {
        case 0:
            go = TRUE;
            break;
        case 1:
            for (j = 0; j < 4; j++) {
                if (fn_801D08B4(this_, j, this_ + 0xc, r)) {
                    go = TRUE;
                    break;
                }
            }
            break;
        case 2:
            for (i = 0; i < 4; i++) {
                bit = 1 << i;
                if (*(u8*)(this_ + 0x345) & bit) {
                    if (fn_801D0B44(this_, i) && !fn_801D0D50(this_, i, this_ + 0xc, r)) {
                        go = TRUE;
                        break;
                    }
                } else if (fn_801D08B4(this_, i, this_ + 0xc, r)) {
                    *(u8*)(this_ + 0x345) |= bit;
                }
            }
            break;
        case 3:
            if (*(u16*)(this_ + 0x346) != fn_8022461C(this_ + 0xc, *(s32*)(this_ + 0x4)) ||
                *(u16*)(this_ + 0x348) != fn_80226850(this_ + 0xc, *(s32*)(this_ + 0x4))) {
                go = TRUE;
            }
            break;
        }
        if (go) {
            slmnSpawn(this_);
            fn_80208244(this_, 1);
        }
        break;
    }
    case 2:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            if (!(*(u32*)(this_ + 0x230) & 0x2000) && *(u8*)(this_ + 0x34a) >= 5) {
                fn_80208244(this_, 4);
            } else {
                fn_80208244(this_, 3);
            }
        }
        break;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
