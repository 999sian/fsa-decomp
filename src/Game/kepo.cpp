// TU 0x80218cf4-0x8021a570 (actor KEPO).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Box.h"
extern const f32 lbl_8053FC94;

struct KepoGlobals;
extern KepoGlobals* lbl_8053AB10;
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_8030C210(void* g, f32* v);


// ---- ReturnZero_80218F80.cpp ----
// NEW ACTOR (vtable lbl_804A6550). Two trivial vtable-slot stubs, both return 0.
extern "C" {
#pragma float_expressions on
#pragma opt_propagation on
extern "C" void fn_80218CF4(u8* self) {
    f32 pos[3];

    if (*(s32*)(self + 0x2b4) == 0 || *(s32*)(self + 0x2b4) == 3) {
        switch (*(s32*)(self + 0x248)) {
        case 4:
        case 5:
        case 8:
        case 9: {
            u8* g = *(u8**)((u8*)lbl_8053AB10 + 0x30);
            if (g[0x284] == 0) {
                g[0x284] = 1;
                *(f32*)(g + 0x28c) = 0.05f;
            }
        } break;
        }
    }

    if (*(u32*)(self + 0x230) & 0x10000) {
        switch (*(s32*)(self + 0x248)) {
        case 0:
        case 1: {
            u8* g = *(u8**)((u8*)lbl_8053AB10 + 0x24);
            g[0x17d] = 1;
        } break;
        }
    } else if (*(s32*)(self + 0x2b4) == 0 || *(s32*)(self + 0x2b4) == 1) {
        switch (*(s32*)(self + 0x248)) {
        case 4:
        case 5:
        case 8:
        case 9: {
            s32 room = *(s32*)(self + 4);
            u8* base = (u8*)fn_802D6A9C();
            f32* ptr;
            bool bVar4;
            f32 fVar2;
            f32 t;

            if (room < 8) {
                ptr = (f32*)(base + 0xcc);
            } else {
                ptr = (f32*)(base + 0xdc);
            }
            bVar4 = false;
            f32 y = *(f32*)(self + 0x10) - *(f32*)(self + 0x14);
            f32 x = *(f32*)(self + 0xc);
            pos[0] = x;
            pos[1] = y;
            pos[2] = 0.0f;
            f32 bottom = ptr[1];
            f32 lowerY = 0.001f + bottom;
            pos[1] = __fsel(lowerY - y, lowerY, y);
            f32 left = ptr[0];
            f32 lowerX = 0.001f + left;
            pos[0] = __fsel(lowerX - x, lowerX, x);
            f32 right = ptr[2];
            f32 upperX = right - 0.001f;
            pos[0] = __fsel(upperX - pos[0], pos[0], upperX);
            if (pos[0] >= left && pos[1] >= bottom && pos[0] < right && pos[1] < ptr[3]) {
                bVar4 = true;
            }
            if (bVar4) {
                if (*(s32*)(self + 0x2b4) == 0 && (*(s32*)(self + 0x248) == 4 || *(s32*)(self + 0x248) == 5)) {
                    u8* g = *(u8**)((u8*)lbl_8053AB10 + 0x24);
                    if (g[0x7f5] == 0) {
                        g[0x7f4] = 1;
                        *(s32*)(g + 0x7f8) = 4;
                        *(f32*)(g + 0x7fc) = pos[0];
                        *(f32*)(g + 0x800) = pos[1];
                        *(f32*)(g + 0x804) = pos[2];
                        g[0x7f6] = 0;
                    }
                } else {
                    fn_8030C210(*(void**)((u8*)lbl_8053AB10 + 0x24), pos);
                    switch (*(s32*)(self + 0x248)) {
                    case 8:
                    case 9: {
                        f32 lowerY = 0.001f + ptr[1];
                        f32 value = pos[1] - 24.0f;
                        pos[1] = __fsel(lowerY - value, lowerY, value);
                        fn_8030C210(*(void**)((u8*)lbl_8053AB10 + 0x24), pos);
                    } break;
                    }
                }
            }
        } break;
        }
    }
}
#pragma opt_propagation reset
#pragma float_expressions reset
int ReturnZero_80218F80(void) { return 0; }
int ReturnZero_80218F88(void) { return 0; }
}

// ---- stub_80219e04.cpp ----
// NEW ACTOR (vtable lbl_804A6550). "Is in an active/vulnerable window"
// predicate: true for states 6-0xa unconditionally, true for state 2
// only when variant (this->0x2b4) == 3, false otherwise.
//
// Cracked via zeldaret/tww's daNpc_Bm1_c::getBitMask() (src/d/actor/d_a_npc_bm1.cpp),
// which uses a `switch` with a default-initialized result variable and
// a single trailing return to get MWCC's switch-lowering to naturally
// produce a shared-tail merge point - if/else-if chains for this same
// logic had failed 3 times (see project_fsa_phase4_kickoff.md, 26th
// batch). The single-comparison case body also needed the established
// "default local + if-override" phrasing (not a bare `return cond;`)
// to avoid MWCC's branchless subfic/cntlzw/srwi canonicalization.
// Case declaration ORDER matters: the single-value case (2) must be
// written FIRST and the range case (6-10) SECOND for MWCC's block
// layout to match retail exactly - the reverse order (range first)
// produced byte-identical LOGIC but a 4-byte-shorter, differently
// laid out object.
extern "C" bool fn_80219E04(void* thisObj) {
    s32 v = *(s32*)((char*)thisObj + 0x248);
    bool result = false;
    switch (v) {
    case 2:
        if (*(s32*)((char*)thisObj + 0x2b4) == 3) { result = true; }
        break;
    case 6: case 7: case 8: case 9: case 10:
        result = true;
        break;
    }
    return result;
}

extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern u8 lbl_804A6540[];
extern "C" void fn_801D0ED0(void* self);
extern "C" void fn_801D0E58(void* self);
extern "C" void fn_801D2608(void* anim, void* arg, s32 n);
extern "C" void fn_801D22DC(void* anim, s32 a, s32 b, s32 c);
extern "C" u8 fn_802D800C(void* mgr, u32 kind);
extern "C" void fn_8021ABC0(void* p);
#pragma float_expressions on
#pragma opt_propagation off
static inline BOOL kepoStageFlag(s32 a, s32 b) {
    if (a < 0 || a > 7) return FALSE;
    if (b < 0 || b > 3) return FALSE;
    return ((1 << (b + a * 4)) & *(u32*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x28)) != 0;
}
#pragma opt_propagation on
extern "C" void fn_80219E4C(u8* self) {
    u8* globals;
    u32 flag;
    s32 v2;
    BOOL unlocked;
    s32 a;
    s32 b;
    u32 bVar1;
    u8* base;

    fn_801D0ED0(self);
    globals = lbl_80529DEC;
    a = *(s32*)(globals + 0x118);
    b = *(s32*)(globals + 0x11c);
    flag = kepoStageFlag(a, b) != 0;
    base = (u8*)fn_802D6A9C();
    bVar1 = base[0x131f9] != 0;

    *(s32*)(self + 0x2a8) = (*(u32*)(self + 0x90) & 0xffff) + 299;
    {
        u32 v = (*(u32*)(self + 0x90) >> 20) & 0x1f;
        f32 min = lbl_8053FC94;
        f32 x = (f32)v - min;
        f32 y = (f32)v;
        *(f32*)(self + 0x2ac) = __fsel(x, y, min);
    }
    *(s32*)(self + 0x2b0) = (*(u32*)(self + 0x90) >> 25) & 0x1f;

    if (*(s32*)(globals + 0x118) == 0 && *(s32*)(globals + 0x11c) == 0 && (*(u32*)(self + 0x90) >> 31) != 0) {
        *(u32*)(self + 0x230) |= 0x10000;
    }
    if ((*(u32*)(self + 0x90) >> 19) & 1) {
        *(s32*)(self + 0x2b4) = 2;
    } else {
        if (flag != 0 || bVar1 != 0 || ((v2 = *(s32*)(self + 0x2b0)) != 0 && fn_802D800C(fn_802D6A9C(), v2))) {
            *(s32*)(self + 0x2b4) = 1;
            *(u32*)(self + 0x230) &= ~0x10000;
        } else {
            *(s32*)(self + 0x2b4) = 0;
        }
    }

    switch (*(s32*)(self + 0x2b4)) { case 0: case 3: *(u32*)(self + 0x230) |= 0x4000; break; }
    switch (*(s32*)(self + 0x2b4)) { case 0: case 3: if ((*(u32*)(self + 0x90) >> 30) & 1) *(u32*)(self + 0x230) |= 0x8000; break; }

    *(f32*)(self + 0x60) = -8.0f;
    *(f32*)(self + 0x64) = -8.0f;
    *(f32*)(self + 0x68) = 8.0f;
    *(f32*)(self + 0x6c) = 24.0f;
    *(f32*)(self + 0x70) = 1.0f;
    *(f32*)(self + 0x74) = 1.0f;
    *(f32*)(self + 0x78) = -1.0f;
    *(f32*)(self + 0x7c) = -1.0f;
    *(f32*)(self + 0x80) = 1.0f;
    *(f32*)(self + 0x84) = 1.0f;
    *(f32*)(self + 0x88) = -1.0f;
    *(f32*)(self + 0x8c) = -1.0f;
    *(s32*)(self + 0xb0) = 0;
    *(s32*)(self + 0x98) = 2;
    *(u32*)(self + 0x230) |= 0x380;
    *(s32*)(self + 0x108) = 1000;
    *(s32*)(self + 0x244) = *(s32*)(self + 0x108);
    *(u8*)(self + 0x194) = 1;
    fn_801D0E58(self);
    *(f32*)(self + 0x14) = 16.0f;

    {
        s32 room = *(s32*)(self + 4);
        u8* m = (u8*)fn_802D6A9C();
        f32* ptr;
        if (room < 8) {
            ptr = (f32*)(m + 0xcc);
        } else {
            ptr = (f32*)(m + 0xdc);
        }
        if (*(f32*)(self + 0xc) <= 0.5f * (ptr[0] + ptr[2])) {
            *(u32*)(self + 0x230) |= 0x2000;
        }
    }

    switch (*(s32*)(self + 0x2b4)) {
    case 0:
        if (*(u32*)(self + 0x230) & 0x10000) *(s32*)(self + 0x248) = 0;
        else *(s32*)(self + 0x248) = 2;
        break;
    case 1: *(s32*)(self + 0x248) = 3; break;
    case 2: *(s32*)(self + 0x248) = 6; fn_8021ABC0(self + 0x2c8); break;
    case 3: *(s32*)(self + 0x248) = 2; fn_8021ABC0(self + 0x2c8); break;
    }

    *(s32*)(self + 0x24c) = 0;
    *(s32*)(self + 0x250) = -1;
    *(f32*)(self + 0x254) = 0.0f;
    *(f32*)(self + 0x258) = 0.0f;
    fn_801D2608(self + 0x270, lbl_804A6540, 4);
    fn_801D22DC(self + 0x270, 0, 0, 0);
    if (*(u32*)(self + 0x230) & 0x10000) {
        u8* g = *(u8**)((u8*)lbl_8053AB10 + 0x2c);
        g[0xc] = (u8)(s32)*(f32*)(self + 0x2d8);
    }
}
// ---- fn_8021A234_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6550[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_8021A234(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6550;
        fn_801EE434(*(void**)(p + 0x2c4));
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801D0F40(void* self);
extern "C" void InitDefaultRecord(void* rec);
extern void* lbl_804A6550[];

extern "C" void* fn_8021A2D0(u8* self) {
    fn_801D0F40(self);
    *(void***)self = lbl_804A6550;
    *(s32*)(self + 0x2a8) = 0;
    *(f32*)(self + 0x2ac) = 1.5f;
    *(s32*)(self + 0x2b0) = 0;
    *(s32*)(self + 0x2b4) = 0;
    *(s32*)(self + 0x2b8) = -1;
    *(f32*)(self + 0x2bc) = 0.0f;
    *(f32*)(self + 0x2c0) = 0.0f;
    *(s32*)(self + 0x2c4) = 0;
    InitDefaultRecord(self + 0x2c8);
    *(f32*)(self + 0x2d8) = 0.0f;
    return self;
}

struct J3DFrameCtrl {
    BOOL checkPass(f32 frame);
};

extern "C" void fn_801F0E34(void* self, u32 id, s32 c);
extern "C" void fn_801CE4BC(void* self);
extern "C" void fn_8021B668(void* self);

extern "C" void fn_8021917C(u8* self) {
    if (*(s32*)(self + 0x278) == 1) {
        if (((J3DFrameCtrl*)(self + 0x294))->checkPass(0.1f) || ((J3DFrameCtrl*)(self + 0x294))->checkPass(22.1f) ||
            ((J3DFrameCtrl*)(self + 0x294))->checkPass(44.1f))
        {
            fn_801F0E34(self, 0x4006b, 0);
        }
    }
    s32 prev = *(s32*)(self + 0x280);
    fn_801CE4BC(self);
    s32 state = *(s32*)(self + 0x278);
    s32 cur = *(s32*)(self + 0x280);
    if (state == 1 && prev != 5 && cur == 5) {
        fn_8021B668(self);
    }
}



#pragma float_expressions on
#pragma opt_propagation off
extern "C" void fn_8021923C(u8* self) {
    void fn_80219AFC(u8* self, s32 state);
    void fn_801D22DC(void* anim, s32 a, s32 b, s32 c);
    void fn_801F0E34(void* self, u32 id, s32 c);
    void fn_801F31C4(u8* a, f32* out);
    void fn_8022FE80(s32 a, s32 b, s32 c, s32 d, s32 e);
    s32 fn_8022FD8C(s32 h);
    void fn_8022FEB8(f32* box, s32 room, s32 h, s32 a, s32 b);
    u8 fn_8038BD08(s32 a, s32 id, s32 room, f32* v, s32 c);
    u8 fn_8038C678(s32 a, s32 id, s32 h, s32 room, f32* v, s32 c);
    u8 fn_80388CAC(s32 a, s32 h);
    u8 fn_803865B8(s32 a);
    u8 fn_80384C58(s32 a, s32 h);
    s32 fn_801D05F8(u8* self, f32* pos, f32 speed);
    u8 fn_8023077C(void);
    u8 fn_801D0B44(u8* self, s32 i);
    u8 fn_8022F514(u32 i);
    int fn_8022F3DC(u32 i);
    int fn_8030AAF4(s32 i);
    u32 fn_80309D6C(void* w, s32 h, s32 flags);
    s32 fn_80230CFC(s32 i);
    u8 fn_801D21F0(void* anim);
    void* fn_801F856C(void);
    s32 fn_801D0020(u8* self, f32* pos, s32 i, u8 c);
    void fn_80230534(s32);
    u8 fn_8021A570(void*, bool);
    s32 fn_801CD354(s32);
    void fn_80138B7C(void* p);
    void fn_80458880(void* p, u32 a, s32 b);
    void fn_80230BF4(s32 player, s32 a);
    void* fn_8023E724(s32 player);
    void fn_80230498(s32 player, void* obj, s32 a, s32 b, s32 c, s32 d, s32 e);
    s32 fn_80138A30(void* game);
    extern f32 lbl_8053FC5C;
    extern f32 lbl_8053FC78;
    extern f32 lbl_8053FC84;
    extern f32 lbl_8053FC88;
    extern f32 lbl_8053FC8C;
    extern f32 lbl_8053FC90;
    extern void* lbl_8053AAF8;
    extern void* lbl_8053AD30;
    extern void* lbl_8053AF80;
    extern f32 lbl_8046A640[];

    f32 box[4];
    f32 v0[3];
    f32 v6[3];
    f32 v8[3];
    s32 n;
    s32 i;
    bool found;

    if (*(s32*)(self + 0x248) == 3) {
        f32 k;
        f32 x;
        f32 upperX;
        f32 upperY;
        f32 y;
        f32 lowerX;
        f32 lowerY;
        k=lbl_8053FC84;
        y=*(f32*)(self+0x10);
        x=*(f32*)(self+0xc);
        upperY=k+y;
        upperX=k+x;
        lowerX=x-k;
        lowerY=y-k;
        box[3] = upperY;
        box[0] = lowerX;
        box[1] = lowerY;
        box[2] = upperX;
    } else {
        fn_801F31C4(self, box);
    }

    switch (*(s32*)(self + 0x248)) {
    case 0:
        *(s32*)(self + 0x2b8) = 0;
        fn_8022FE80(*(s32*)(self + 0x2b8), *(s32*)(self + 4), *(s32*)(self + 0x198), 0, 0);
        if (fn_8022FD8C(*(s32*)(self + 0x198)) == *(s32*)(self + 0x2b8)) {
            v0[0] = lbl_8053FC5C;
            v0[1] = lbl_8053FC88;
            v0[2] = lbl_8053FC5C;
            if (fn_8038BD08(*(s32*)(self + 0x2b8), 0x150, *(s32*)(self + 4), v0, 2)) {
                fn_80219AFC(self, 1);
            }
        }
        break;
    case 1:
        fn_8022FE80(*(s32*)(self + 0x2b8), *(s32*)(self + 4), *(s32*)(self + 0x198), 0, 0);
        if (!fn_803865B8(*(s32*)(self + 0x2b8))) break;
        if (!fn_80384C58(*(s32*)(self + 0x2b8), *(s32*)(self + 0x198))) break;
        fn_80219AFC(self, 4);
        break;
    case 2:
        *(s32*)(self + 0x2b8) = fn_801D05F8(self, (f32*)(self + 0xc), 16.0f * *(f32*)(self + 0x2ac));
        if (*(s32*)(self + 0x2b8) < 0) break;
        if (!fn_8023077C()) break;
        if (*(s32*)(self + 0x2b4) == 0) {
            fn_80219AFC(self, 4);
        } else if (*(s32*)(self + 0x2b4) == 3) {
            fn_80219AFC(self, 8);
        }
        break;
    case 3: {
        f32 k;
        f32 yOrigin;
        f32 xOrigin;
        f32 ax;
        f32 ay;
        f32 b0;
        f32 b1;
        f32 b2;
        f32 b3;
        fn_8022FEB8(box, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        found = 0;
        k = lbl_8053FC84;
        yOrigin = *(f32*)(self+0x10);
        xOrigin = *(f32*)(self+0xc);
        b3 = k+yOrigin;
        b2 = k+xOrigin;
        b1 = yOrigin-k;
        b0 = xOrigin-k;
        i = found;
        do {
            if (!fn_801D0B44(self, i)) continue;
            int room;
            if (fn_8022F514(i)) room = fn_8022F3DC(i);
            else room = fn_8030AAF4(i);
            if (fn_80309D6C(lbl_8053AD30,room,0x100)==0) continue;
            ay = ((f32*)lbl_8046A640)[fn_80230CFC(i) * 2 + 1];
            ax = ((f32*)lbl_8046A640)[fn_80230CFC(i) * 2];
            f32* playerPos = (f32*)fn_8023E724(i);
            f32 x = ax + playerPos[0];
            f32 y = ay + playerPos[1];
            bool inside = false;
            if(x >= b0 && y >= b1 && x < b2 && y < b3) inside = true;
            if(!inside) continue;
            found = true;
            break;
        } while(++i < 4);
        if (found) {
            fn_80458880(lbl_8053AF80, 0x47, -1);
            fn_80219AFC(self, 4);
        }
    } break;
    case 4:
        if (__fabsf(*(f32*)(self + 0x24) - *(f32*)(self + 0xc)) < lbl_8053FC78 &&
            __fabsf(*(f32*)(self + 0x28) - *(f32*)(self + 0x10)) < lbl_8053FC78) {
            *(f32*)(self + 0xc) = *(f32*)(self + 0x24);
            *(f32*)(self + 0x10) = *(f32*)(self + 0x28);
            fn_80219AFC(self, 5);
            break;
        } else {
            if (fn_801D21F0(self + 0x270)) {
                if (*(s32*)(self + 0x278) == 0) {
                    fn_801D22DC(self + 0x270, 1, 0, 0);
                } else {
                    fn_801D22DC(self + 0x270, 0, 0, 0);
                }
            }
        }
        if (*(s32*)(self + 0x24c) == 0x2d) {
            fn_801F0E34(self, 0x4006c, 0);
        }
        break;
    case 5:
        if (*(f32*)(self + 0x14) <= 16.0f) {
            *(f32*)(self + 0x14) = 16.0f;
            if (fn_801D21F0(self + 0x270)) {
                if (*(s32*)(self + 0x2b4) == 0) {
                    fn_80219AFC(self, 8);
                } else {
                    fn_80219AFC(self, 6);
                }
            }
        }
        break;
    case 6:
        if (((u8*)fn_801F856C())[0x3041] == 0) {
            fn_8022FEB8(box, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
            *(s32*)(self + 0x2b8) = fn_8022FD8C(*(s32*)(self + 0x198));
            if (*(s32*)(self + 0x2b8) >= 0) {
                v6[0] = lbl_8053FC5C;
                v6[1] = lbl_8053FC88;
                v6[2] = lbl_8053FC5C;
                if (fn_8038C678(*(s32*)(self + 0x2b8), *(s32*)(self + 0x2a8), *(s32*)(self + 0x198), *(s32*)(self + 4), v6, 0)) {
                    fn_80219AFC(self, 7);
                }
            }
        }
        break;
    case 7:
        fn_8022FEB8(box, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        if (!fn_80388CAC(*(s32*)(self + 0x2b8), *(s32*)(self + 0x198))) break;
        if (*(u32*)(self + 0x230) & 0x4000) {
            fn_80219AFC(self, 0xa);
        } else {
            fn_80219AFC(self, 6);
        }
        break;
    case 8: {
        s32 obj;
        s32 player;
        fn_8022FE80(*(s32*)(self + 0x2b8), *(s32*)(self + 4), *(s32*)(self + 0x198), 0, 0);
        if (fn_8022FD8C(*(s32*)(self + 0x198)) != *(s32*)(self + 0x2b8)) break;
        v8[0] = lbl_8053FC5C;
        v8[1] = lbl_8053FC88;
        v8[2] = lbl_8053FC5C;
        if (!fn_8038C678(*(s32*)(self + 0x2b8), *(s32*)(self + 0x2a8), *(s32*)(self + 0x198), *(s32*)(self + 4), v8, 0x4002)) break;
        if (*(u32*)(self + 0x230) & 0x10000) {
            fn_80138B7C(lbl_8053AAF8);
            n = fn_80138A30(lbl_8053AAF8);
            for (player = 0; player < n; player++) {
                obj = fn_801CD354(fn_801D0020(self, (f32*)(self + 0xc), player, 0));
                fn_80230BF4(player, obj);
                fn_80230498(player, fn_8023E724(player), obj + 0x3c, 0xff, -0x80, -0x80, 1);
            }
        }
        fn_80219AFC(self, 9);
        break;
    }
    case 9:
        fn_8022FE80(*(s32*)(self + 0x2b8), *(s32*)(self + 4), *(s32*)(self + 0x198), 0, 0);
        if (!fn_803865B8(*(s32*)(self + 0x2b8))) break;
        if (!fn_80384C58(*(s32*)(self + 0x2b8), *(s32*)(self + 0x198))) break;
        if (*(u32*)(self + 0x230) & 0x10000) {
            n = fn_80138A30(lbl_8053AAF8);
            for(s32 player=0;player<n;player++) {
                fn_80230BF4(player,1);
                fn_80230498(player,fn_8023E724(player),0x3d,0xff,-0x80,-0x80,1);
            }
        }
        fn_80230534(0);
        if (*(u32*)(self + 0x230) & 0x4000) {
            fn_80219AFC(self, 0xa);
        } else {
            fn_80219AFC(self, 6);
        }
        break;
    case 10:
        if (*(u16*)(self + 0x2ce) != 0) break;
        fn_80219AFC(self, 0xb);
        break;
    case 11:
        if (!(*(f32*)(self + 0x14) >= 35.0f)) break;
        *(f32*)(self + 0x14) = 35.0f;
        if (!fn_801D21F0(self + 0x270)) break;
        fn_80219AFC(self, 0xc);
        break;
    case 12:
        if (__fabsf(*(f32*)(self + 0x2bc) - *(f32*)(self + 0xc)) < lbl_8053FC78 &&
            __fabsf(*(f32*)(self + 0x2c0) - *(f32*)(self + 0x10)) < lbl_8053FC78) {
            *(u8*)(self + 0x11c) = 0;
            break;
        }
        if(fn_801D21F0(self+0x270)) {
            if(*(s32*)(self+0x278)==0) fn_801D22DC(self+0x270,1,0,0);
            else fn_801D22DC(self+0x270,0,0,0);
        }
        break;
    }
    bool play = false;
    if(*(s32*)(self+0x248)!=10) {
        bool active=false;
        switch(*(s32*)(self+0x248)) {
        case 2:
            if(*(s32*)(self+0x2b4)==3) active=true;
            break;
        case 6: case 7: case 8: case 9: case 10: active=true; break;
        }
        if(active) play=true;
    }
    if(fn_8021A570(self+0x2c8,play)) {
        switch(*(s32*)(self+0x2c8)) {
        case 0: fn_801F0E34(self,0x4006e,0);break;
        case 1: fn_801F0E34(self,0x4006d,0);break;
        }
    }
}
#pragma opt_propagation reset
#pragma float_expressions reset
extern "C" void fn_8021B5A0(void* self);
extern "C" void fn_8021B5C4(void* self);
extern "C" void fn_8021ABC0(void* p);
extern "C" void fn_802D8050(void* mgr, s32 id, s32 a, s32 b);
extern "C" void fn_8043A0E8(s32 a);
extern "C" void fn_8043A608(u32 a);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801CBB98(f32* box, void* obj, f32 f, s32 t, f32* out);
extern u32 lbl_8053AED0;
extern f32 lbl_8053FC90;
extern const f32 lbl_8053FC94;
extern const f32 lbl_8053FC98;
static inline bool kepoIsSwingState(s32 state) {
    bool result = false;
    switch (state) {
    case 5:
    case 11:
        result = true;
        break;
    }
    return result;
}

#pragma opt_propagation off
extern "C" void fn_80219AFC(u8* self, s32 state) {
    s32 old = *(s32*)(self + 0x248);
    if (!kepoIsSwingState(old) && kepoIsSwingState(state)) {
        fn_8021B5C4(self);
    } else if (kepoIsSwingState(old) && !kepoIsSwingState(state)) {
        fn_8021B5A0(self);
    }

    switch (*(s32*)(self + 0x248)) {
    case 5:
        fn_8021ABC0(self + 0x2c8);
        break;
    case 7:
    case 9: {
        s32 m = *(s32*)(self + 0x2b0);
        if (m != 0) {
            fn_802D8050(fn_802D6A9C(), m, 1, 0xff);
        }
        if (*(u32*)(self + 0x230) & 0x10000) {
            fn_8043A0E8(1);
        }
        if (*(u32*)(self + 0x230) & 0x8000) {
            fn_8043A608(lbl_8053AED0);
            *(u32*)(self + 0x230) &= 0xffff7fff;
        }
    } break;
    }

    switch ((u32)state) {
    case 0:
    case 1:
    case 2:
    case 3:
        break;
    case 4: {
        s32 room;
        u8* base;
        f32 out[2];
        *(f32*)(self + 0x258) = lbl_8053FC94;
        room = *(s32*)(self + 4);
        base = (u8*)fn_802D6A9C();
        if (room < 8) {
            base += 0xcc;
        } else {
            base += 0xdc;
        }
        void* pos = self + 0x24;
        s32 t = -0x5556;
        if (*(u32*)(self + 0x230) & 0x2000) t = 0x5556;
        fn_801CBB98((f32*)base, pos, lbl_8053FC98, t, out);
        f32 z;
        f32 x;
        f32 y;
        y = out[1];
        x = out[0];
        z = lbl_8053FC90;
        *(f32*)(self + 0xc) = x;
        *(f32*)(self + 0x10) = y;
        *(f32*)(self + 0x14) = z;
    } break;
    case 5:
        *(f32*)(self + 0x258) = 0.0f;
        fn_801D22DC(self + 0x270, 2, 0, 0);
        break;
    case 6:
    case 8:
        *(f32*)(self + 0x258) = 0.0f;
        break;
    case 7:
    case 9:
        *(f32*)(self + 0x258) = 0.0f;
        fn_801F0E34(self, 0x4006c, 0);
        break;
    case 10:
        *(f32*)(self + 0x258) = 0.0f;
        *(u8*)(self + 0x2d4) = 1;
        break;
    case 11:
        *(f32*)(self + 0x258) = 0.0f;
        fn_801D22DC(self + 0x270, 3, 0, 0);
        break;
    case 12: {
        s32 room;
        u8* base;
        s32 t;
        *(f32*)(self + 0x258) = lbl_8053FC94;
        fn_801D22DC(self + 0x270, 1, 0, 0);
        room = *(s32*)(self + 4);
        base = (u8*)fn_802D6A9C();
        if (room < 8) {
            base += 0xcc;
        } else {
            base += 0xdc;
        }
        if (*(u32*)(self + 0x230) & 0x10000) {
            u32 flags = *(volatile u32*)(self + 0x230);
            t = -0x3556;
            *(u32*)(self + 0x230) = flags | 0x2000;
        } else if (*(u32*)(self + 0x230) & 0x2000) {
            t = -0x2aaa;
        } else {
            t = 0x2aaa;
        }
        fn_801CBB98((f32*)base, self + 0x24, lbl_8053FC98, t, (f32*)(self + 0x2bc));
    } break;
    }

    *(s32*)(self + 0x24c) = 0;
    *(s32*)(self + 0x248) = state;
}
#pragma opt_propagation reset
struct KepoVec2 { f32 x, y; };
extern "C" void fn_801D01A0(void* self, f32 speed, void* dir, KepoVec2* out);

extern "C" void fn_80218F90(u8* self) {
    KepoVec2 v;
    *(f32*)(self + 0x3c) = 0.0f;
    *(f32*)(self + 0x40) = 0.0f;
    *(f32*)(self + 0x44) = 0.0f;
    switch (*(s32*)(self + 0x248)) {
    case 4:
        fn_801D01A0(self, *(f32*)(self + 0x254), self + 0x24, &v);
        *(f32*)(self + 0x3c) = v.x;
        *(f32*)(self + 0x40) = v.y;
        break;
    case 5:
        *(f32*)(self + 0x44) = -0.5f;
        break;
    case 0xb:
        if (*(s32*)(self + 0x280) >= 0xf || *(s32*)(self + 0x280) < 0xb) {
            *(f32*)(self + 0x44) = 0.8f;
        }
        break;
    case 0xc:
        fn_801D01A0(self, *(f32*)(self + 0x254), self + 0x2bc, &v);
        *(f32*)(self + 0x3c) = v.x;
        *(f32*)(self + 0x40) = v.y;
        break;
    }
}

struct KepoGlobals {
    u8 pad0[0x2c];
    u8* m2c;
};
extern KepoGlobals* lbl_8053AB10;
extern void* lbl_8053AAF8;
extern "C" BOOL fn_801CD950(f32* v, f32 target, f32 step);
extern "C" s32 fn_80138A30(void* game);
extern "C" void fn_80230BF4(s32 player, s32 a);
extern "C" void* fn_8023E724(s32 player);
extern "C" void fn_80230498(s32 player, void* obj, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801CE0A4(void* self, void* arg);
extern "C" void fn_8021B548(void* self);

static inline u32 kepoFlag(u8* self) {
    return *(u32*)(self + 0x230) & 0x10000;
}

extern "C" void fn_8021906C(u8* self, void* arg) {
    if (kepoFlag(self) && kepoFlag(self)) {
        switch (*(s32*)(self + 0x248)) {
        case 0:
        case 1:
            break;
        default:
            if (255.0f != *(f32*)(self + 0x2d8) && !fn_801CD950((f32*)(self + 0x2d8), 255.0f, 1.0f)) {
                s32 n = fn_80138A30(lbl_8053AAF8);
                for (s32 i = 0; i < n; i++) {
                    fn_80230BF4(i, 1);
                    fn_80230498(i, fn_8023E724(i), 0x3d, 0xff, -0x80, -0x80, 1);
                }
            }
            break;
        }
        lbl_8053AB10->m2c[0xc] = (s32)*(f32*)(self + 0x2d8);
    }
    fn_801CE0A4(self, arg);
    fn_8021B548(self);
}

#pragma float_expressions on
#include "JSystem/JAudio/JASFakeMatchFSA.h"
